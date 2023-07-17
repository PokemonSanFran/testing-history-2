#include "save_screen.h"
#include "save.h"
#include "start_menu.h"
#include "ui_start_menu.h"
#include "strings.h"
#include "fieldmap.h"
#include "new_game.h"

#include "gba/types.h"
#include "gba/defines.h"
#include "global.h"
#include "main.h"
#include "bg.h"
#include "text_window.h"
#include "window.h"
#include "characters.h"
#include "palette.h"
#include "task.h"
#include "overworld.h"
#include "malloc.h"
#include "gba/macro.h"
#include "menu_helpers.h"
#include "menu.h"
#include "malloc.h"
#include "scanline_effect.h"
#include "sprite.h"
#include "constants/rgb.h"
#include "decompress.h"
#include "constants/songs.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "pokemon_icon.h"
#include "graphics.h"
#include "data.h"
#include "pokedex.h"
#include "gpu_regs.h"

// This code is based on Ghoulslash's excellent UI tutorial:
// https://www.pokecommunity.com/showpost.php?p=10441093

/*
 * Glossary of acronyms and abbreviations -- because sometimes I go crazy with these
 *
 * BG = background
 * GF = Game Freak
 * DMA = Direct Memory Access
 * GBA = Game Boy Advance
 */

/*
 * Some general resources you should bookmark:
 * TONC GBA tutorial: https://www.coranac.com/tonc/text/toc.htm
 * Computer systems course with focus on GBA: https://ianfinlayson.net/class/cpsc305/
 * GBATEK reference docs: https://problemkaputt.de/gbatek.htm
 * Copetti GBA Architecture: https://www.copetti.org/writings/consoles/game-boy-advance/
 */

/*
 * The meat of the menu code lives in this file. The tutorial comments assume the following:
 *
 * 1) You understand the basics of GBA graphics i.e. the multiple BG layers and how they are controlled, the various
 *    GBA graphics modes, the basics of hardware sprites, etc
 *
 * 2) You are familiar with the concept of tiles (tilesets) vs tilemaps. These are two distinct concepts and you need to
 *    understand them to understand any UI code.
 *
 * 3) You are familiar with the concept of a charblock and a screenblock, which are crucial to proper VRAM layout.
 *
 * 4) You understand the basics of the pokeemerald Callback and Task systems, which structure the menu's control flow.
 *
 * 5) You have a basic grasp of the GBA memory layout -- you know the difference between VRAM, EWRAM, IWRAM, etc.
 *
 * 6) Some of the UI code makes use of DMA (Direct Memory Access). This assumes you are familiar with what DMA is and
 *    how it works on the GBA. Also note that a lot of the GF library code does not perform DMA directly, rather it
 *    schedules a DMA copy to occur during the next VBlank using a circle buffer of DMA transfer request objects. See
 *    the code in `gflib/dma3_manager.{h,c} for more details.
 *
 * If you are unsure about any of these concepts, please check the following resources:
 *
 * GBA graphics basics:
 *     + https://www.coranac.com/tonc/text/video.htm
 *     + https://ianfinlayson.net/class/cpsc305/notes/06-gba1
 *
 * Tiles, tilemaps, charblocks, screenblocks:
 *     + https://www.coranac.com/tonc/text/objbg.htm
 *     + https://www.coranac.com/tonc/text/regbg.htm
 *     + https://ianfinlayson.net/class/cpsc305/notes/13-tiles <--- this is a highly recommended resource
 *
 * Callbacks and Tasks:
 *     + https://github.com/pret/pokeemerald/wiki/Overview%E2%88%B6-The-Game-Loop
 *     + https://github.com/pret/pokeemerald/wiki/Overview%E2%88%B6-The-Task-System
 *
 * GBA Memory Layout:
 *     + https://www.coranac.com/tonc/text/hardware.htm#sec-memory
 *     + https://problemkaputt.de/gbatek.htm#gbamemorymap
 *
 * DMA:
 *     + https://www.coranac.com/tonc/text/dma.htm
 *     + https://ianfinlayson.net/class/cpsc305/notes/14-memory
 */

/*
 * Basic Code Flow
 * A summary of the basic control flow path for this code. This may help aid in understanding which functions get
 * called, and when.
 *
 * 1) Any code that would like to launch this menu must include `sample_ui.h' so it has the right hook-in, specifically
 *    `Task_OpenSampleUi_Simple'. It must then setup the transition (however is relevant based on its context) and set
 *    the active task to `Task_OpenSampleUi_Simple'. In our case, `start_menu.c' is the caller of this task.
 *
 * 2) `Task_OpenSampleUi_Simple' waits for any active fades to finish, then it calls our init code in `SampleUi_Init'
 *    which changes the gMainCallback2 to our `SampleUi_SetupCB'.
 *
 * 3) `SampleUi_SetupCB' runs each frame, bit-by-bit getting our menu initialized. Once initialization has finished,
 *    this callback:
 *       1) Sets up a new task `Task_SampleUiWaitFadeIn' which waits until we fade back in before hotswapping itself for
 *          `Task_SampleUiMainInput' which reads input and updates the menu state.
 *       2) Starts a palette fade to bring the screen from black back to regular colors
 *       3) Sets our VBlank callback to `SampleUi_VBlankCB' (which is called every VBlank as part of the VBlank
 *          interrupt service routine). This callback transfers our OAM and palette buffers into VRAM, among other
 *          things
 *       4) Sets gMainCallback2 to our menu's main callback `SampleUi_MainCB', which does the standard processing of
 *          tasks, animating of sprites, etc.
 *
 * 4) We have reached our standard menu state. Every frame `SampleUi_MainCB' runs, which calls `Task_SampleUiMainInput`
 *    to get input from the user and update menu state and backing graphics buffers. `SampleUi_MainCB' also updates
 *    other important gamestate. Then, when VBlank occurs, our `SampleUi_VBlankCB' copies palettes and OAM into VRAM
 *    before pending DMA transfers fire and copy any screen graphics updates into VRAM.
 */

/*
 * Various state for the UI -- we'll allocate this on the heap since none of it needs to be preserved after we exit the
 * menu.
 */
struct SampleUiState
{
    MainCallback savedCallback;
    // We will use this later to track some loading state
    u8 loadState;
    // Store the current dex mode, we'll have a mode that shows dex number/description as well as a few others
    u8 mode;
    // The sprite ID of the current mon icon, we need this so we can destroy the sprite when the user scrolls
    u8 monIconSpriteId;
    // The dex num of the currently displayed mon
    u16 monIconDexNum;
};

enum WindowIds
{
    WIN_MON_INFO,
    WIN_SAVE_MESSAGE,
    WIN_YESNO_BOX
};

enum
{
    SAVE_ASK,
    SAVE_CHECK,
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR,
    SAVE_OVERWRITE
};

/*
 * Both of these can be pointers that live in EWRAM -- allocating the actual data on the heap will save precious WRAM
 * space since none of this data matters outside the context of our menu. We can easily cleanup when we're done. It's
 * worth noting that every time the game re-loads into the overworld, the heap gets nuked from orbit. However, it is
 * still good practice to clean up after oneself, so we will be sure to free everything before exiting.
 */
static EWRAM_DATA struct SampleUiState *sSampleUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

EWRAM_DATA static u8 sSaveDialogTimer = 0;


/*
 * Defines and read-only data for on-screen dex.
 */
#define MON_ICON_X     39
#define MON_ICON_Y     36
/*
 * Dex mode defines. Info mode shows dex number and description. Stats and Other modes will show placeholder text, but
 * you can change this to show whatever info you want.
 */
#define MODE_INFO   0
#define MODE_STATS  1
#define MODE_OTHER  2
static const u8 sModeNameInfo[] =  _("Info");
static const u8 sModeNameStats[] =  _("Stats");
static const u8 sModeNameOther[] =  _("Other");
static const u8 *const sModeNames[3] = {
    [MODE_INFO]   = sModeNameInfo,
    [MODE_STATS]  = sModeNameStats,
    [MODE_OTHER]  = sModeNameOther
};

/*
 * BgTemplates are just a nice way to setup various BG attributes without having to deal with manually writing to the
 * various display and BG control registers that the Game Boy actually cares about. GF handles that for you with lots of
 * clever BG management code. All you have to do is tell it what you want. If you want to see the gory details of BG
 * control registers, check out this resource and the code in `gflib/bg.{h,c}':
 * https://problemkaputt.de/gbatek.htm#lcdiobgcontrol
 */
static const struct BgTemplate sSampleUiBgTemplates[] =
{
    {
        // We will use BG0 for the text windows
        .bg = 0,
        // Use charblock 0 for BG0 tiles
        .charBaseIndex = 0,
        // Use screenblock 31 for BG0 tilemap
        // (It has become customary to put tilemaps in the final few screenblocks)
        .mapBaseIndex = 31,
        // Draw the text windows on top of the main BG
        .priority = 1
    },
    {
        // The Main BG: we will use BG1 for the menu graphics
        .bg = 1,
        // Use charblock 3 for BG1 tiles
        .charBaseIndex = 3,
        // Use screenblock 30 for BG1 tilemap
        .mapBaseIndex = 30,
        // Draw this BG below BG0, since we want text drawn on top of the menu graphics
        .priority = 2
    }
    /*
     * I encourage you to open the mGBA Tools/Game State Views/View Tiles menu to see how this above code gets
     * translated into an actual VRAM layout. Quiz yourself by changing the charBaseIndex and mapBaseIndex and guessing
     * what will happen before looking at the Tile Viewer.
     */
};

/*
 * Like the above BgTemplates, WindowTemplates are just an easy way to setup some software windows (which are provided
 * by the GameFreak library). GF's window system is used primarily for drawing dynamic text on the background layers.
 * Their inner workings are quite confusing, so hopefully this tutorial clears some things up.
 *
 * One big thing to note is that GF windows use a technique called tile rendering to draw text. With normal BG
 * rendering, you have a pre-drawn tileset, and then you dynamically update the tilemap, based on gamestate, to change
 * what's shown on screen. With tile rendering, this process is basically flipped on its head. GF tile-rendered windows
 * instead write a preset increasing sequence of tile indexes into the parts of the BG tilemap that represent a given
 * window. Then, to draw text, it dynamically draws to a backing pixel buffer (the `u8 *tileData' in the Window struct)
 * that is copied into VRAM just like regular tile data. This effectively allows the text rendering code to treat the
 * window BG as a pseudo-framebuffer, as if we were in a simple bitmap mode like Mode 3. This technique is advantageous
 * because it allows for maximum flexibility with font sizing and spacing. You aren't locked into 8x8 tiles for each
 * character.
 *
 * For more information about tile rendering and text rendering sytems in general, check out the TTE TONC tutorial and
 * the tile rendering section specifically. You can also consult Game Freak's code in `gflib/window.c' and
 * `gflib/text.c'.
 * https://www.coranac.com/tonc/text/tte.htm#sec-chr
 */
static const struct WindowTemplate sSampleUiWindowTemplates[] =
{
    [WIN_MON_INFO] =
    {
        // This window will also print on BG0
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 9,
        .width = 26,
        .height = 10,
        // We will use the same palette for this window, since it's also just regular text
        .paletteNum = 15,
        /*
         * Here we will set the baseBlock to the previous window's baseblock + the width*height in tiles of the previous
         * window. Try changing this value around and use the mGBA tile viewer to see what happens.
         */
        .baseBlock = 1
    },
    [WIN_YESNO_BOX] =
    {
        .bg = 0,
        .tilemapLeft = 23,
        .tilemapTop = 6,
        .width = 54,
        .height = 46,
        .paletteNum = 15,
        .baseBlock = 1 + (26 * 10)
    },
    DUMMY_WIN_TEMPLATE
};


static const u32 sSampleUiTiles[] = INCBIN_U32("graphics/sample_ui/tiles.4bpp.lz");
static const u32 sSampleUiTilemap[] = INCBIN_U32("graphics/sample_ui/tilemap.bin.lz");
static const u16 sSampleUiPalette[] = INCBIN_U16("graphics/sample_ui/00.gbapal");

// Define some font color values that will index into our font color table below.
enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sSampleUiWindowFontColors[][3] =
{
    /*
     * The TEXT_COLOR_X macros here are just palette indexes. Specifically, these indexes match the colors in
     * `gMessageBox_Pal', so we will need to make sure that palette is loaded. Since our window is set to use
     * palette 15, we'll load it into BG palette slot 15 in the menu loading code.
     */
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

// Callbacks for the sample UI
static void SampleUi_SetupCB(void);
static void SampleUi_MainCB(void);
static void SampleUi_VBlankCB(void);

// Sample UI tasks
static void Task_SampleUiWaitFadeIn(u8 taskId);
static void Task_SampleUiMainInput(u8 taskId);
static void Task_SampleUiWaitFadeAndBail(u8 taskId);
static void Task_SampleUiWaitFadeAndExitGracefully(u8 taskId);

// Sample UI helper functions
void SampleUi_Init(MainCallback callback);
static bool8 SampleUi_InitBgs(void);
static void SampleUi_FadeAndBail(void);
static bool8 SampleUi_LoadGraphics(void);
static void SampleUi_InitWindows(void);
static void SaveScreen_ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static void SaveScreen_DoSave(void);
static u8 SaveScreen_SaveYesNoCallback(void);
static u8 SaveScreen_SaveConfirmSaveCallback(void);
static void SampleUi_PrintUiMonInfo(void);
static void SampleUi_DrawMonIcon(u16 dexNum);
static void SampleUi_FreeResources(void);

void Task_OpenSampleUi_StartHere(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Menu_FreeResources();
        SampleUi_Init(CB2_ReturnToUIMenu);
        DestroyTask(taskId);
    }
}

void SampleUi_Init(MainCallback callback)
{
    sSampleUiState = AllocZeroed(sizeof(struct SampleUiState));
    if (sSampleUiState == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    sSampleUiState->loadState = 0;
    sSampleUiState->savedCallback = callback;

    SetMainCallback2(SampleUi_SetupCB);
}

static void SampleUi_SetupCB(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        SetVBlankHBlankCallbacksToNull();
        ClearScheduledBgCopiesToVram();
        gMain.state++;
        break;
    case 1:
        ScanlineEffect_Stop();
        FreeAllSpritePalettes();
        ResetPaletteFade();
        ResetSpriteData();
        ResetTasks();
        gMain.state++;
        break;
    case 2:
        if (SampleUi_InitBgs())
        {
            sSampleUiState->loadState = 0;
            gMain.state++;
        }
        else
        {
            SampleUi_FadeAndBail();
            return;
        }
        break;
    case 3:
        // `SampleUi_LoadGraphics' has its own giant switch statement, so keep calling until it returns TRUE at the end
        if (SampleUi_LoadGraphics() == TRUE)
        {
            // Only advance the state of this load switch statment once all the LoadGraphics logic has finished.
            gMain.state++;
        }
        break;
    case 4:
        // Set up our text windows
        SampleUi_InitWindows();
        gMain.state++;
        break;
    case 5:
        // Setup initial draw of Pokemon icon sprite
        sSampleUiState->monIconDexNum = NATIONAL_DEX_BULBASAUR;

        /*
         * Free all mon icon palettes just to make sure nothing is left over from previous screen. The sprite system
         * uses a technique called palette tagging to help the game keep track of which palettes are in use, and by
         * which sprites. As mentioned above, we will cover palette tags in more detail in the next tutorial.
         */
        FreeMonIconPalettes();

        /*
         * Since this is a small demo without many sprites, we can just load all 6 default mon icon palettes at once.
         * If you have a more complex UI with lots of unique-palette sprites in addition to mon icons, you may instead
         * want to manage mon icon palettes dynamically based on which mon icons are currently on screen. You can do
         * this with the more granular `LoadMonIconPalette(u16 species)' and `FreeMonIconPalette(u16 species)'
         * functions.
         */
        LoadMonIconPalettes();

        // Draw the mon icon
        SampleUi_DrawMonIcon(sSampleUiState->monIconDexNum);

        // Print the UI button hints in the top-right

        // Print the mon info in the main text box
        SaveMapView();
        sSampleUiState->mode = SAVE_ASK;
        SampleUi_PrintUiMonInfo();

        // Create a task that does nothing until the palette fade is done. We will start the palette fade next frame.
        taskId = CreateTask(Task_SampleUiWaitFadeIn, 0);
        gMain.state++;
        break;
    case 6:
        /*
         * Fade screen in from black, this will take multiple frames to finish so we'll want the above active task poll
         * the fade to completion before continuing processing.
         */
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    case 7:
        // Finally we can set our main callbacks since loading is finished
        SetVBlankCallback(SampleUi_VBlankCB);
        SetMainCallback2(SampleUi_MainCB);
        break;
    }
}

static void SampleUi_MainCB(void)
{
    RunTasks();
    // For all active sprites, call their callbacks and update their animation state
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void SampleUi_VBlankCB(void)
{
    /*
     * Handle direct CPU copies here during the VBlank period. All of these transfers affect what is displayed on
     * screen, so we wait until VBlank to make the copies from the backbuffers.
     */

    // Transfer OAM buffer into VRAM OAM area
    LoadOam();
    /*
     * Sprite animation code may have updated frame image for sprites, so copy all these updated frames into the correct
     * VRAM location.
     */
    ProcessSpriteCopyRequests();
    // Transfer the processed palette buffer into VRAM palette area
    TransferPlttBuffer();
}

static void Task_SampleUiWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_SampleUiMainInput;
    }
}

static void Task_SampleUiMainInput(u8 taskId)
{
    // Exit the menu when the player presses B
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_SampleUiWaitFadeAndExitGracefully;
    }
    // User pressed or held DPAD_DOWN, scroll down through dex list
    if (JOY_REPEAT(DPAD_DOWN))
    {
        PlaySE(SE_SELECT);
        // Destroy the old mon sprite, update the selected dex num, and draw the new sprite
        FreeAndDestroyMonIconSprite(&gSprites[sSampleUiState->monIconSpriteId]);
        if (sSampleUiState->monIconDexNum < NATIONAL_DEX_MEW)
        {
            sSampleUiState->monIconDexNum++;
        }
        else
        {
            // Wrap dex number around to Bulbasaur when user presses down on Mew
            sSampleUiState->monIconDexNum = NATIONAL_DEX_BULBASAUR;
        }
        SampleUi_DrawMonIcon(sSampleUiState->monIconDexNum);
        SampleUi_PrintUiMonInfo();
    }
    // User pressed or held DPAD_UP, scroll up through dex list
    if (JOY_REPEAT(DPAD_UP))
    {
        PlaySE(SE_SELECT);
        // Destroy the old mon sprite, update the selected dex num, and draw the new sprite
        FreeAndDestroyMonIconSprite(&gSprites[sSampleUiState->monIconSpriteId]);
        if (sSampleUiState->monIconDexNum > NATIONAL_DEX_BULBASAUR)
        {
            sSampleUiState->monIconDexNum--;
        }
        else
        {
            // Wrap dex number around to Mew when user presses Up on Bulbasaur
            sSampleUiState->monIconDexNum = NATIONAL_DEX_MEW;
        }
        SampleUi_DrawMonIcon(sSampleUiState->monIconDexNum);
        SampleUi_PrintUiMonInfo();
    }
    // User pressed A, cycle to next dex mode
    if (JOY_NEW(A_BUTTON))
    {
        switch(sSampleUiState)
        {
            case SAVE_ASK:
                SaveScreen_SaveAsk_Confirm();
            case SAVE_SUCCESS:
                SaveScreen_SaveSuccess_Confirm();
            case SAVE_OVERWRITE:
        }
        if (sSampleUiState->mode == SAVE_ASK)
            {
            }
    }
}

static void SaveScreen_SaveAskConfirm(void)
{
    PlaySE(SE_SELECT);
    sSampleUiState->mode = SAVE_IN_PROGRESS;
    SampleUi_PrintUiMonInfo();
    SaveScreen_DoSave();
}

static void SaveScreen_DoSave(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        sSampleUiState->mode = SAVE_SUCCESS;
    else
        sSampleUiState->mode = SAVE_ERROR;

    SaveStartTimer();
    SampleUi_PrintUiMonInfo();
}

static void Task_SampleUiWaitFadeAndBail(u8 taskId)
{
    // Wait until the screen fades to black before we start doing cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSampleUiState->savedCallback);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_SampleUiWaitFadeAndExitGracefully(u8 taskId)
{
    /*
     * This function is basically the same as Task_SampleUiWaitFadeAndBail. However, for this sample we broke it out
     * because typically you might want to do something different if the user gracefully exits a menu vs if you got
     * booted from a menu due to heap allocation failure.
     */

    // E.g. you could do some other processing here

    // Wait until the screen fades to black before we start doing final cleanup
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSampleUiState->savedCallback);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 SampleUi_InitBgs(void)
{
    /*
     * 1 screenblock is 2 KiB, so that should be a good size for our tilemap buffer. We don't need more than one
     * screenblock since BG1's size setting is 0, which tells the GBA we are using a 32x32 tile background:
     *      (32 tile * 32 tile * 2 bytes/tile = 2048)
     * For more info on tilemap entries and how they work:
     * https://www.coranac.com/tonc/text/regbg.htm#sec-map
     */
    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);

    // BG registers may have scroll values left over from the previous screen. Reset all scroll values to 0.
    ResetAllBgsCoordinates();

    // Allocate our tilemap buffer on the heap
    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {
        // Bail if the allocation fails
        return FALSE;
    }

    /*
     * Clear all BG-related data buffers and mark DMAs as ready. Also resets the BG and mode bits of reg DISPCNT to 0.
     * This will effectively turn off all BGs and activate Mode 0.
     * LTODO explain the underlying sDmaBusyBitfield here
     */
    ResetBgsAndClearDma3BusyFlags(0);

    /*
     * Use the BG templates defined at the top of the file to init various cached BG attributes. These attributes will
     * be used by the various load methods to correctly setup VRAM per the user template. Some of the attributes can
     * also be pushed into relevant video regs using the provided functions in `bg.h'
     */
    InitBgsFromTemplates(0, sSampleUiBgTemplates, NELEMS(sSampleUiBgTemplates));

    // Set the BG manager to use our newly allocated tilemap buffer for BG1's tilemap
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);

    /*
     * Schedule to copy the tilemap buffer contents (remember we zeroed it out earlier) into VRAM on the next VBlank.
     * Right now, BG1 will just use Tile 0 for every tile. We will change this once we load in our true tilemap
     * values from sSampleUiTilemap.
     */
    ScheduleBgCopyTilemapToVram(1);

    // Set reg DISPCNT to show BG0, BG1. Try commenting these out to see what happens.
    ShowBg(0);
    ShowBg(1);

    return TRUE;
}

static void SampleUi_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_SampleUiWaitFadeAndBail, 0);

    /*
     * Set callbacks to ours while we wait for the fade to finish, then our above task will cleanup and swap the
     * callbacks back to the one we saved earlier (which should re-load the overworld)
     */
    SetVBlankCallback(SampleUi_VBlankCB);
    SetMainCallback2(SampleUi_MainCB);
}

static bool8 SampleUi_LoadGraphics(void)
{
    switch (sSampleUiState->loadState)
    {
    case 0:
        /*
         * Reset leftover temp buffers from any previous code that used them to load graphics. The loading code in
         * `menu.c' basically saves pointers to the decompression buffers after it copies to VRAM. Here, we just reset
         * all the pointers to NULL and set the tracking index to 0. This obviously assumes the previous screen freed
         * the buffers for us.
         */
        ResetTempTileDataBuffers();

        /*
         * Decompress our tileset and copy it into VRAM using the parameters we set in the BgTemplates at the top -- we
         * pass 1 for the bgId so it uses the charblock setting from the BG1 template.
         * The size, offset, mode parameters are set to 0:
         *
         *      Size is 0 because that tells the function to set the size dynamically based on the decompressed data.
         *
         *      Offset is 0 because we want to tiles loaded right at whatever charblock we set in the BgTemplate.
         *
         *      Mode is 0 because we are copying tiles and not a tilemap, and 0 tells the bg library to use the tile
         *      loading code as opposed to the tilemap loading code (unfortunately GameFreak didn't provide a mode
         *      enum -- it was probably a preprocessor define in the original game code. So you have to look at the
         *      library functions to figure out what the mode values mean).
         *
         * `menu.c' also has a alternative function `DecompressAndLoadBgGfxUsingHeap', which does the same thing but
         * automatically frees the decompression buffer for you. If you want, you can use that here instead and remove
         * the `ResetTempTileDataBuffers' call above, since it doesn't use the temp tile data buffers.
         */
        DecompressAndCopyTileDataToVram(1, sSampleUiTiles, 0, 0, 0);
        sSampleUiState->loadState++;
        break;
    case 1:
        /*
         * Each frame, keep trying to free the temp data buffer we used last frame to copy the tile data into VRAM. We
         * have to do a poll here because this free may not occur depending on the state of the DMA manager. If instead
         * you chose to load graphics using the alternative `DecompressAndLoadBgGfxUsingHeap', you can remove this call
         * and wrapping if statement since the polling/freeing is handled for you under the hood.
         * LTODO explain this better, like above sDmaBusyBitfield is being used here, this might be confusing
         */
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            /*
             * This basically just wraps the LZ77UnCompWram system call. It reads and decompresses whatever data is
             * provided in the `src' (argument 1), and writes the decompressed data to a WRAM location given in `dest'
             * (argument 2). In our case `dest' is just the tilemap buffer we heap-allocated earlier.
             */
            LZDecompressWram(sSampleUiTilemap, sBg1TilemapBuffer);
            sSampleUiState->loadState++;
        }
        break;
    case 2:
        /*
         * Copy our palette into the game's BG palette buffer, slot 0 -- this step does not directly get the palette
         * into VRAM. That only happens during VBlank if the current callback specifies a buffer transfer.
         */
        LoadPalette(sSampleUiPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        /*
         * Copy the message box palette into BG palette buffer, slot 15. Our window is set to use palette 15 and our
         * text color constants are defined assuming we are indexing into this palette.
         */
        LoadPalette(gMessageBox_Pal, BG_PLTT_ID(15), PLTT_SIZE_4BPP);
        sSampleUiState->loadState++;
    default:
        sSampleUiState->loadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void SampleUi_InitWindows(void)
{
    /*
     * Initialize windows from the window templates we specified above. This makes two important allocations:
     *
     * 1) It allocates a tilemap buffer for the window tilemap, the size of which is based on the screen size setting
     *    specified in the BgTemplate (we didn't set one, so it defaults to 0, see BGXCNT register documentation for
     *    more details on screen sizes). For this UI, the size setting is 0 which just means use a single screen. We
     *    only allocate a single tilemap for the entire BG layer. So if you have multiple windows on the same BG, they
     *    will all share the same tilemap buffer.
     *
     * 2) It allocates one `tileData' buffer (often also called the pixel buffer in the code) for each window. *Each
     *    window has its own pixel buffer.* This is the buffer into which we actually draw text, and it gets copied upon
     *    request to the tile area of VRAM based on the BG charblock and window baseblock.
     *
     * It's also worth noting that the window API allows you to allocate and set your own tilemap buffer for the window
     * BG layer, just like we did earlier for BG1. However, it's better to just let the window API do the allocation and
     * setup for you through `InitWindows()' -- just make sure to call `FreeAllWindowBuffers()' before closing up shop
     * to return your memory.
     */
    InitWindows(sSampleUiWindowTemplates);

    // Marks all text printers as inactive. Basically just setting flags. That's it.
    DeactivateAllTextPrinters();

    /*
     * Schedule a copy of BG0 tilemap buffer to VRAM. This buffer was allocated for us by `InitWindows()' since we
     * specified a window on BG0 and had not yet set that layer's tilemap buffer. Note that the buffer was also zeroed
     * for us by `InitWindows()'
     */
    ScheduleBgCopyTilemapToVram(0);

    /*
     * Fill each entire window pixel buffer (i.e. window.tileData) with the given value. In this case, fill it with 0s
     * to make the window completely transparent. We will draw text into the window pixel buffer later.
     */
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    /*
     * Write an increasing sequence of tile indexes into each window's tilemap buffer, based on the offset provided by
     * the window.baseBlock. Why? Because the window text will be drawn onto the tiles themselves. So we just want each
     * subsequent tilemap entry to point to the next tile in VRAM. That way, we can treat the tiles as a
     * pseudo-framebuffer and render our text however we want. If you dive deeper into the implementation of
     * `PutWindowTilemap', you will see that it takes some fancy calculation to determine which entries in the
     * tilemap buffer we actually need to modify (because we are mapping from GameFreak windows, which are logically 2D,
     * to VRAM locations, which in reality is basically a 1D array). I will leave exploration of the inner-workings of
     * this function as an exercise to the reader.
     */
    PutWindowTilemap(WIN_MON_INFO);

    /*
     * Copy (well, schedule to copy) each window into VRAM using DMA3 under the hood. The COPYWIN_FULL argument means we
     * copy BOTH the tilemap buffer (which recall is just an incrementing sequence of references into our tile canvas)
     * and the tiles themselves. Typically when updating text on a window, you only need to copy the tile canvas (i.e.
     * using COPYWIN_GFX) since the tilemap should never change. But to init the window we need to get both into VRAM.
     */
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_FULL);
}

static const u8 sText_SampleUiButtonHint1[] = _("{DPAD_UPDOWN}Change POKéMON");
static const u8 sText_SampleUiButtonHint2[] = _("{A_BUTTON}Mode: {STR_VAR_1}");
static const u8 sText_SampleUiButtonHint3[] = _("{B_BUTTON}Exit");

static u8 SaveScreen_SaveYesNoCallback(void)
{
    return 0;
}

static const u8 sText_SampleUiMonStats[] = _("Put stats info here");
static const u8 sText_SampleUiMonOther[] = _("Put other info here");

static void SampleUi_PrintUiMonInfo(void)
{
    // Clear the window before drawing new text
    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    switch (sSampleUiState->mode)
    {
        case SAVE_ASK:
            StringCopy(gStringVar4, gText_SaveYourAdventure);
            break;
        case SAVE_IN_PROGRESS:
            StringCopy(gStringVar4, gText_NowSavingAdventure);
            break;
        case SAVE_SUCCESS:
            StringCopy(gStringVar4, gText_YouSaved);
            break;
        case SAVE_ERROR:
            StringCopy(gStringVar4, gText_ThereWasAnError);
            break;
        case SAVE_OVERWRITE:
            StringCopy(gStringVar4, gText_EraseOldAdventure);
            break;
        default:
            break;
    }

    AddTextPrinterParameterized4(WIN_MON_INFO, FONT_SMALL, 5, 3, 0, 0, sSampleUiWindowFontColors[FONT_BLACK],
            TEXT_SKIP_DRAW, gStringVar4);

    // Copy pixel buffer to VRAM now that we are done drawing text
    CopyWindowToVram(WIN_MON_INFO, COPYWIN_GFX);
}

static void SampleUi_DrawMonIcon(u16 dexNum)
{
    // Convert the dex number to a species ID.
    u16 speciesId = NationalPokedexNumToSpecies(dexNum);

    /*
     * Create a new mon icon sprite and save off its sprite ID so we can easily free it when we need to update which
     * icon is displayed. We set the sprite callback to a preset supplied by the GF's mon icon code. This callback
     * updates the little bounce animation of the icon. `CreateMonIcon' handles all the details of sprite initialization
     * for us. Feel free to dive into the implementation to see the gory details.
     */
    sSampleUiState->monIconSpriteId = CreateMonIcon(speciesId, SpriteCB_MonIcon, MON_ICON_X, MON_ICON_Y, 4, 0);
    // Set prio to 0 so the icon sprite draws on top of everything
    gSprites[sSampleUiState->monIconSpriteId].oam.priority = 0;
}

static void SampleUi_FreeResources(void)
{
    // Free our data struct and our BG1 tilemap buffer
    if (sSampleUiState != NULL)
    {
        Free(sSampleUiState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }
    // Free all allocated tilemap and pixel buffers associated with the windows.
    FreeAllWindowBuffers();
    // Reset all sprite data
    ResetSpriteData();
}
