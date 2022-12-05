#include "global.h"
#include "ui_options_menu.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "printf.h"
#include "mgba.h"

/*
 * 
 */

//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
};

enum WindowIds
{
    WINDOW_1,
};

//Defines
#define  NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN 5
#define  NUM_OF_SCREENS                             5
#define  NUM_OPTIONS_PER_SCREEN                     5
#define  MAX_OPTIONS_PER_SETTING                    NUMBER_OF_MON_TYPES + 1

//These are defined in include/global.h
//#define NUM_OF_PRESET_OPTIONS         5       //Number of different options in the hub options
//#define NUM_OPTIONS_GAME_SETTINGS     6
//#define NUM_OPTIONS_BATTLE_SETTINGS   24
//#define NUM_OPTIONS_MUSIC_SETTINGS    4
//#define NUM_OPTIONS_VISUAL_SETTINGS   10
//#define NUM_OPTIONS_RANDOM_SETTINGS   16

enum OptionsIds
{
    GAME_SETTINGS,
    BATTLE_SETTINGS,
    VISUAL_SETTINGS,
    MUSIC_SETTINGS,
    RANDOM_SETTINGS,
};

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8  currentOptionId = 0;
static EWRAM_DATA u8  currentScreenId = 0;
static EWRAM_DATA u8  currentFirstOption = 0;
static EWRAM_DATA bool8 areYouNotOnSettingsHub = FALSE;

static EWRAM_DATA u8 Temporal_Options_Preset_Settings[NUM_OF_PRESET_OPTIONS];       //This is a temporal data used for the Discard Feature on Leave Dialog
static EWRAM_DATA u8 Temporal_Options_Game_Settings[NUM_OPTIONS_GAME_SETTINGS];     //This is a temporal data used for the Discard Feature on Leave Dialog
static EWRAM_DATA u8 Temporal_Options_Battle_Settings[NUM_OPTIONS_BATTLE_SETTINGS]; //This is a temporal data used for the Discard Feature on Leave Dialog
static EWRAM_DATA u8 Temporal_Options_Music_Settings[NUM_OPTIONS_MUSIC_SETTINGS];   //This is a temporal data used for the Discard Feature on Leave Dialog
static EWRAM_DATA u8 Temporal_Options_Visual_Settings[NUM_OPTIONS_VISUAL_SETTINGS]; //This is a temporal data used for the Discard Feature on Leave Dialog
static EWRAM_DATA u8 Temporal_Options_Random_Settings[NUM_OPTIONS_RANDOM_SETTINGS]; //This is a temporal data used for the Discard Feature on Leave Dialog

//==========STATIC=DEFINES==========//
static void Menu_RunSetup(void);
static bool8 Menu_DoGfxSetup(void);
static bool8 Menu_InitBgs(void);
static void Menu_FadeAndBail(void);
static bool8 Menu_LoadGraphics(void);
static void Menu_InitWindows(void);
static void PrintToWindow(u8 windowId, u8 colorIdx);
static void Task_MenuWaitFadeIn(u8 taskId);
static void Task_MenuMain(u8 taskId);


static void CopySaveBlockDataToTemporalData();
static void CopyTemporalDataToSaveBlockData();

void CopyTemporalDataToSaveBlockData()
{
    u8 i, j;

    for(i = 0 ;i < NUM_OF_PRESET_OPTIONS; i++){
        gSaveBlock2Ptr->optionsPreset[i] = Temporal_Options_Preset_Settings[i];

        switch(i){
            case GAME_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_GAME_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsGame[j] = Temporal_Options_Game_Settings[j];
                }
            break;
            case BATTLE_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_BATTLE_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsBattle[j] = Temporal_Options_Battle_Settings[j];
                }
            break;
            case VISUAL_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_VISUAL_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsVisual[j] = Temporal_Options_Visual_Settings[j];
                }
            break;
            case MUSIC_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_MUSIC_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsMusic[j] = Temporal_Options_Music_Settings[j];
                }
            break;
            case RANDOM_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_RANDOM_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsRandom[j] = Temporal_Options_Random_Settings[j];
                }
            break;
        }
    }
}

void CopySaveBlockDataToTemporalData()
{
    u8 i, j;

    for(i = 0 ;i < NUM_OF_PRESET_OPTIONS; i++){
        Temporal_Options_Preset_Settings[i] = gSaveBlock2Ptr->optionsPreset[i];

        switch(i){
            case GAME_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_GAME_SETTINGS; j++){
                    Temporal_Options_Game_Settings[j] = gSaveBlock2Ptr->optionsGame[j];
                }
            break;
            case BATTLE_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_BATTLE_SETTINGS; j++){
                    Temporal_Options_Battle_Settings[j] = gSaveBlock2Ptr->optionsBattle[j];
                }
            break;
            case VISUAL_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_VISUAL_SETTINGS; j++){
                    Temporal_Options_Visual_Settings[j] = gSaveBlock2Ptr->optionsVisual[j];
                }
            break;
            case MUSIC_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_MUSIC_SETTINGS; j++){
                    Temporal_Options_Music_Settings[j] = gSaveBlock2Ptr->optionsMusic[j];
                }
            break;
            case RANDOM_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_RANDOM_SETTINGS; j++){
                    Temporal_Options_Random_Settings[j] = gSaveBlock2Ptr->optionsRandom[j];
                }
            break;
        }
    }
}

//==========CONST=DATA==========//
static const struct BgTemplate sMenuBgTemplates[] =
{
    {
        .bg = 0,    // windows, etc
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .priority = 1
    }, 
    {
        .bg = 1,    // this bg loads the UI tilemap
        .charBaseIndex = 3,
        .mapBaseIndex = 30,
        .priority = 2
    },
    {
        .bg = 2,    // this bg loads the UI tilemap
        .charBaseIndex = 0,
        .mapBaseIndex = 28,
        .priority = 0
    }
};

static const struct WindowTemplate sMenuWindowTemplates[] = 
{
    [WINDOW_1] = 
    {
        .bg = 0,            // which bg to print text on
        .tilemapLeft = 0,   // position from left (per 8 pixels)
        .tilemapTop = 0,    // position from top (per 8 pixels)
        .width = 30,        // width (per 8 pixels)
        .height = 20,       // height (per 8 pixels)
        .paletteNum = 0,    // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[]   = INCBIN_U32("graphics/ui_menus/options_menu/tiles.4bpp.lz");
static const u32 sMenuTilemap[] = INCBIN_U32("graphics/ui_menus/options_menu/tilemap.bin.lz");
static const u16 sMenuPalette[] = INCBIN_U16("graphics/ui_menus/options_menu/palette.gbapal");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]    = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_DARK_GRAY,   TEXT_COLOR_TRANSPARENT},
    [FONT_WHITE]    = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_WHITE,       TEXT_COLOR_TRANSPARENT},
    [FONT_RED]      = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_RED,         TEXT_COLOR_TRANSPARENT},
    [FONT_BLUE]     = {TEXT_COLOR_TRANSPARENT,  TEXT_COLOR_BLUE,        TEXT_COLOR_TRANSPARENT},
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenOptionsMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Options_Menu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Options_Menu_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;

    SetMainCallback2(Menu_RunSetup);
}

static void Menu_RunSetup(void)
{
    while (1)
    {
        CopySaveBlockDataToTemporalData();

        if (Menu_DoGfxSetup() == TRUE)
            break;
    }
}

static void Menu_MainCB(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void Menu_VBlankCB(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

static bool8 Menu_DoGfxSetup(void)
{
    u8 taskId;
    switch (gMain.state)
    {
    case 0:
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000)
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
        if (Menu_InitBgs())
        {
            sMenuDataPtr->gfxLoadState = 0;
            gMain.state++;
        }
        else
        {
            Menu_FadeAndBail();
            return TRUE;
        }
        break;
    case 3:
        if (Menu_LoadGraphics() == TRUE)
            gMain.state++;
        break;
    case 4:
        LoadMessageBoxAndBorderGfx();
        Menu_InitWindows();
        gMain.state++;
        break;
    case 5:
        PrintToWindow(WINDOW_1, FONT_WHITE);
        taskId = CreateTask(Task_MenuWaitFadeIn, 0);
        BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
        gMain.state++;
        break;
    case 6:
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
        gMain.state++;
        break;
    default:
        SetVBlankCallback(Menu_VBlankCB);
        SetMainCallback2(Menu_MainCB);
        return TRUE;
    }
    return FALSE;
}

#define try_free(ptr) ({        \
    void ** ptr__ = (void **)&(ptr);   \
    if (*ptr__ != NULL)                \
        Free(*ptr__);                  \
})

static void Menu_FreeResources(void)
{
    try_free(sMenuDataPtr);
    try_free(sBg1TilemapBuffer);
    FreeAllWindowBuffers();
}


static void Task_MenuWaitFadeAndBail(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

static void Menu_FadeAndBail(void)
{
    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_MenuWaitFadeAndBail, 0);
    SetVBlankCallback(Menu_VBlankCB);
    SetMainCallback2(Menu_MainCB);
}

static bool8 Menu_InitBgs(void)
{
    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);
    if (sBg1TilemapBuffer == NULL)
        return FALSE;

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);
    return TRUE;
}

static bool8 Menu_LoadGraphics(void)
{
    switch (sMenuDataPtr->gfxLoadState)
    {
    case 0:
        ResetTempTileDataBuffers();
        DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
        sMenuDataPtr->gfxLoadState++;
        break;
    case 1:
        if (FreeTempTileDataBuffersIfPossible() != TRUE)
        {
            LZDecompressWram(sMenuTilemap, sBg1TilemapBuffer);
            sMenuDataPtr->gfxLoadState++;
        }
        break;
    case 2:
        LoadPalette(sMenuPalette, 0, 32);
        sMenuDataPtr->gfxLoadState++;
        break;
    default:
        sMenuDataPtr->gfxLoadState = 0;
        return TRUE;
    }
    return FALSE;
}

static void Menu_InitWindows(void)
{
    u32 i;

    InitWindows(sMenuWindowTemplates);
    DeactivateAllTextPrinters();
    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WINDOW_1, 0);
    LoadUserWindowBorderGfx(WINDOW_1, 720, 14 * 16);
    PutWindowTilemap(WINDOW_1);
    CopyWindowToVram(WINDOW_1, 3);

    ScheduleBgCopyTilemapToVram(2);
}

static u8 GetCurrentScreenOptionNumber(){
    switch(currentScreenId){
        case GAME_SETTINGS:
            return NUM_OPTIONS_GAME_SETTINGS;
        break;
        case BATTLE_SETTINGS:
            return NUM_OPTIONS_BATTLE_SETTINGS;
        break;
        case VISUAL_SETTINGS:
            return NUM_OPTIONS_VISUAL_SETTINGS;
        break;
        case MUSIC_SETTINGS:
            return NUM_OPTIONS_MUSIC_SETTINGS;
        case RANDOM_SETTINGS:
            return NUM_OPTIONS_RANDOM_SETTINGS;
        break;
    }
}

// --------------------------------------------------------------------------------------------------------------------

static u8 GetCurrentSlotOption(u8 option)
{
    return currentFirstOption + option;
}

static u8 GetCursorPosition()
{
    return currentOptionId - currentFirstOption;
}

static void PressedDownButton(){
    u8 halfScreen = ((NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = GetCurrentScreenOptionNumber() - halfScreen;
    u8 cursorPosition = (currentOptionId - currentFirstOption);

    if(currentOptionId < halfScreen){
        mgba_printf(MGBA_LOG_WARN, "First If");
        currentOptionId++;
    }
	else if(currentOptionId >= (GetCurrentScreenOptionNumber() - 1)){ //If you are in the last option go to the first one
        mgba_printf(MGBA_LOG_WARN, "Second If");
		currentOptionId = 0;
		currentFirstOption = 0;
    }
    else if(currentOptionId >= (finalhalfScreen - 1)){
        mgba_printf(MGBA_LOG_WARN, "Third If");
        currentOptionId++;
    }
	else{
        mgba_printf(MGBA_LOG_WARN, "Fourth If");
        currentOptionId++;
        currentFirstOption++;
    }

    mgba_printf(MGBA_LOG_WARN, "Number of Options %d", GetCurrentScreenOptionNumber());
    mgba_printf(MGBA_LOG_WARN, "Cursor Position %d", (currentOptionId - currentFirstOption));
    mgba_printf(MGBA_LOG_WARN, "First Option %d", currentFirstOption);
    mgba_printf(MGBA_LOG_WARN, "Current Position %d", currentOptionId);
    mgba_printf(MGBA_LOG_WARN, "Half Screen %d", halfScreen);
    mgba_printf(MGBA_LOG_WARN, "Final Half Screen %d", finalhalfScreen);
    mgba_printf(MGBA_LOG_WARN, "------------------------------------------------------------------");
}

static void PressedUpButton(){
    if(currentOptionId < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN / 2)
		currentOptionId++;
	else if(currentFirstOption != (GetCurrentScreenOptionNumber() - NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN))
		currentFirstOption++;
	else if((currentFirstOption + currentOptionId) == (GetCurrentScreenOptionNumber() - 1)){
		currentOptionId = 0;
		currentFirstOption = 0;
    }
	else
		currentOptionId++;

    mgba_printf(MGBA_LOG_WARN, "Cursor Position %d", (currentOptionId - currentFirstOption));
    mgba_printf(MGBA_LOG_WARN, "First Option %d", currentFirstOption);
    mgba_printf(MGBA_LOG_WARN, "Current Position %d", currentOptionId);
}

#define OPTION_NAME_LENGTH 20
#define MAX_OPTION_DESCRIPTION_LENGTH 100

struct OptionData
{
    const u8 title[OPTION_NAME_LENGTH];
    const u8 options[OPTION_NAME_LENGTH][MAX_OPTIONS_PER_SETTING];
    const u8 optionDescription[MAX_OPTION_DESCRIPTION_LENGTH];
    u8 numOptions;
};

//Graphics
static const u8 sOptionMenuIcon_Game_Settings[]     = INCBIN_U8("graphics/ui_menus/options_menu/icon_game_settings.4bpp");
static const u8 sOptionMenuIcon_Battle_Settings[]   = INCBIN_U8("graphics/ui_menus/options_menu/icon_battle_settings.4bpp");
static const u8 sOptionMenuIcon_Visual_Settings[]   = INCBIN_U8("graphics/ui_menus/options_menu/icon_visual_settings.4bpp");
static const u8 sOptionMenuIcon_Music_Settings[]    = INCBIN_U8("graphics/ui_menus/options_menu/icon_music_settings.4bpp");
static const u8 sOptionMenuIcon_Random_Settings[]   = INCBIN_U8("graphics/ui_menus/options_menu/icon_random_settings.4bpp");

//Arrows
static const u8 sOptionMenuArrow_Up[]       = INCBIN_U8("graphics/ui_menus/options_menu/arrow_up.4bpp");
static const u8 sOptionMenuArrow_Down[]     = INCBIN_U8("graphics/ui_menus/options_menu/arrow_down.4bpp");
static const u8 sOptionMenuArrow_Left[]     = INCBIN_U8("graphics/ui_menus/options_menu/arrow_left.4bpp");
static const u8 sOptionMenuArrow_Right[]     = INCBIN_U8("graphics/ui_menus/options_menu/arrow_right.4bpp");

static const u8 sOptionMenuSelector[]       = INCBIN_U8("graphics/ui_menus/options_menu/selector.4bpp");

//Text
static const u8 sText_Title_Settings_Hub[]  = _("Settings Hub");
static const u8 sText_Options_Text[]        = _("Option Description");

// For Game Settings
//#define NUM_OF_PRESET_OPTIONS 5 This is defined in Global

struct OptionData Hub_Options[NUM_OF_PRESET_OPTIONS] = {
    [GAME_SETTINGS] =
    {
        .title = _("Game Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Custom"),
            },
        .optionDescription = _("Save, Boot, Button Mode, Save Behavior,\nRun, Puzzle Difficulty, Item Sort"),
        .numOptions = 3,
    },
    [BATTLE_SETTINGS] =
    {
        .title = _("Battle Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Nuzlocke"),
            _("Kaizo"),
            _("Custom"),
            },
        .optionDescription = _("Battle Settings Description"),
        .numOptions = 5,
    },
    [VISUAL_SETTINGS] =
    {
        .title = _("Visual Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Custom"),
            },
        .optionDescription = _("Visual Settings Description"),
        .numOptions = 3,
    },
    [MUSIC_SETTINGS] =
    {
        .title = _("Music Settings"),
        .options = { 
            _("PSF"),
            _("Custom"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SV"),
            },
        .optionDescription = _("Music Settings Description"),
        .numOptions = 10,
    },
    [RANDOM_SETTINGS] =
    {
        .title = _("Random Settings"),
        .options = { 
            _("Default"),
            _("Sane"),
            _("Crazy"),
            _("Total Chaos"),
            _("Custom"),
            },
        .optionDescription = _("Random Settings Description"),
        .numOptions = 5,
    },
};

// For Game Settings

enum GameOptionsID
{
    GAME_OPTIONS_SAVE_BOOT,
    GAME_OPTIONS_BUTTON_MODE,
    GAME_OPTIONS_SAVE_BEHAVIOR,
    GAME_OPTIONS_RUN,
    GAME_OPTIONS_PUZZLE_DIFFICULTY,
    GAME_OPTIONS_ITEM_SORT,
};

struct OptionData GameSettings_Settings_Options[NUM_OPTIONS_GAME_SETTINGS] = {
    [GAME_OPTIONS_SAVE_BOOT] =
    {
        .title = _("Save Boot"),
        .options = { 
            _("Traditional"),
            _("Continue"),
            },
        .optionDescription = _("Save Boot Description"),
        .numOptions = 2,
    },
    [GAME_OPTIONS_BUTTON_MODE] =
    {
        .title = _("Button Mode"),
        .options = { 
            _("Normal"),
            _("LR"),
            _("L = A"),
            },
        .optionDescription = _("Button Mode Description"),
        .numOptions = 3,
    },
    [GAME_OPTIONS_SAVE_BEHAVIOR] =
    {
        .title = _("Save Behavior"),
        .options = { 
            _("Automatic"),
            _("Manual"),
            },
        .optionDescription = _("Save Behavior Description"),
        .numOptions = 2,
    },
    [GAME_OPTIONS_RUN] =
    {
        .title = _("Run"),
        .options = { 
            _("Always"),
            _("Toogle"),
            _("Manual"),
            },
        .optionDescription = _("Run Description"),
        .numOptions = 3,
    },
    [GAME_OPTIONS_PUZZLE_DIFFICULTY] =
    {
        .title = _("Puzzle Difficulty"),
        .options = { 
            _("Normal"),
            _("Easy"),
            },
        .optionDescription = _("Puzzle Difficulty Description"),
        .numOptions = 2,
    },
    [GAME_OPTIONS_ITEM_SORT] =
    {
        .title = _("Item Sort"),
        .options = { 
            _("Off"),
            _("Name"),
            _("Type"),
            _("Amount"),
            _("Recency"),
            },
        .optionDescription = _("Item Sort Description"),
        .numOptions = 5,
    },
};

// For Battle Settings

enum BattleOptionsID
{
    BATTLE_OPTIONS_EXPERIENCE,
    BATTLE_OPTIONS_EXP_MULTIPLIER,
    BATTLE_OPTIONS_LEVEL,
    BATTLE_OPTIONS_SWITCH_STYLE,
    BATTLE_OPTIONS_TAKE_WILD_ITEMS,
    BATTLE_OPTIONS_LAST_USED_BALL,
    BATTLE_OPTIONS_QUICK_RUN,
    BATTLE_OPTIONS_BATTLE_DIFFICULTY,
    BATTLE_OPTIONS_FAINTED_MON,
    BATTLE_OPTIONS_FIRST_POKEMON_CATCH,
    BATTLE_OPTIONS_NICKNAME,
    BATTLE_OPTIONS_WITHEOUT,
    BATTLE_OPTIONS_ITEM_HEALING,
    BATTLE_OPTIONS_CENTER_HEALING,
    BATTLE_OPTIONS_MOVE_HEALING,
    BATTLE_OPTIONS_BAG_ITEMS,
    BATTLE_OPTIONS_OPPONENTS_ITEMS,
    BATTLE_OPTIONS_BASE_STAT_EQUALIZER,
    BATTLE_OPTIONS_ONE_TYPE_CHALLENGE,
    BATTLE_OPTIONS_TYPE_ICONS,
    BATTLE_OPTIONS_ANIMATIONS,
    BATTLE_OPTIONS_INTRO,
    BATTLE_OPTIONS_HP_SPEED,
    BATTLE_OPTIONS_EXP_SPEED,
};

struct OptionData BattleSettings_Settings_Options[NUM_OPTIONS_BATTLE_SETTINGS] = {
    [BATTLE_OPTIONS_EXPERIENCE] =
    {
        .title = _("Experience"),
        .options = { 
                _("All"),
                _("Party"),
                _("Active"),
            },
        .optionDescription = _("Experience Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_EXP_MULTIPLIER] =
    {
        .title = _("Exp Multiplier"),
        .options = { 
                _("Normal"),
                _("1.5"),
                _("2"),
                _("0"),
            },
        .optionDescription = _("Exp Multiplier Description"),
        .numOptions = 4,
    },
    [BATTLE_OPTIONS_LEVEL] =
    {
        .title = _("Level"),
        .options = { 
                _("Level Cap"),
                _("No Cap"),
            },
        .optionDescription = _("Level Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_SWITCH_STYLE] =
    {
        .title = _("Switch Style"),
        .options = { 
            _("Shift"),
            _("Set"),
            },
        .optionDescription = _("Run Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_TAKE_WILD_ITEMS] =
    {
        .title = _("Take Wild Items"),
        .options = { 
                _("Never"),
                _("Ask"),
                _("Always"),
            },
        .optionDescription = _("Take Wild Items Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_LAST_USED_BALL] =
    {
        .title = _("Last Used Ball"),
        .options = { 
                _("Always"),
                _("Best Ball"),
                _("After 1 Ball"),
            },
        .optionDescription = _("Last Used Ball Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_QUICK_RUN] =
    {
        .title = _("Quick Run"),
        .options = { 
                _("B -> A"),
                _("R"),
                _("Off"),
            },
        .optionDescription = _("Quick Run Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_BATTLE_DIFFICULTY] =
    {
        .title = _("Battle Difficulty"),
        .options = { 
                _("Cinematic"),
                _("Standard"),
                _("Challenge"),
                _("Kaizo"),
            },
        .optionDescription = _("Level Description"),
        .numOptions = 4,
    },
    [BATTLE_OPTIONS_FAINTED_MON] =
    {
        .title = _("Fainted Mon"),
        .options = { 
                _("Allowed"),
                _("Box"),
                _("Release"),
            },
        .optionDescription = _("Fainted Mon Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_FIRST_POKEMON_CATCH] =
    {
        .title = _("First Pokemon Catch"),
        .options = { 
                _("Default"),
                _("First Only"),
                _("Duplicate"),
            },
        .optionDescription = _("First Pokemon Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_NICKNAME] =
    {
        .title = _("Nickname"),
        .options = { 
                _("Ask"),
                _("Forced"),
                _("None"),
            },
        .optionDescription = _("Nickname Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_WITHEOUT] =
    {
        .title = _("Witheout"),
        .options = { 
                _("Default"),
                _("Respawn"),
                _("Death"),
            },
        .optionDescription = _("Witheout Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_ITEM_HEALING] =
    {
        .title = _("Item Healing"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = _("Item Healing Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_CENTER_HEALING] =
    {
        .title = _("Center Healing"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = _("Center Healing Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_MOVE_HEALING] =
    {
        .title = _("Move Healing"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = _("Move Healing Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_BAG_ITEMS] =
    {
        .title = _("Bag Items"),
        .options = { 
                _("Allowed"),
                _("No Boss"),
                _("No Trainer"),
                _("4 Only"),
                _("No Items"),
            },
        .optionDescription = _("Bag Items Description"),
        .numOptions = 5,
    },
    [BATTLE_OPTIONS_OPPONENTS_ITEMS] =
    {
        .title = _("Opponent Items"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = _("Opponent Items Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_BASE_STAT_EQUALIZER] =
    {
        .title = _("Base Stat Equalizer"),
        .options = { 
                _("Disabled"),
                _("100"),
                _("255"),
                _("500"),
            },
        .optionDescription = _("Base Stat Equalizer Description"),
        .numOptions = 4,
    },
    [BATTLE_OPTIONS_ONE_TYPE_CHALLENGE] =
    {
        .title = _("One Type Challenge"),
        .options = { 
                _("Normal"),
                _("Fighting"),
                _("Flying"),
                _("Poison"),
                _("Ground"),
                _("Rock"),
                _("Bug"),
                _("Ghost"),
                _("Steel"),
                _("Fire"),
                _("Water"),
                _("Grass"),
                _("Electric"),
                _("Psychic"),
                _("Ice"),
                _("Dragon"),
                _("Dark"),
                _("Fairy"),
            },
        .optionDescription = _("Base Stat Equalizer Description"),
        .numOptions = NUMBER_OF_MON_TYPES + 1,
    },
    [BATTLE_OPTIONS_TYPE_ICONS] =
    {
        .title = _("Type Icons"),
        .options = { 
                _("Show"),
                _("Hide"),
            },
        .optionDescription = _("Type Icons Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_ANIMATIONS] =
    {
        .title = _("Animations"),
        .options = { 
                _("Animated"),
                _("Skip"),
            },
        .optionDescription = _("Animations Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_INTRO] =
    {
        .title = _("Intro"),
        .options = { 
                _("Normal"),
                _("Skip"),
            },
        .optionDescription = _("Intro Description"),
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_HP_SPEED] =
    {
        .title = _("Hp Speed"),
        .options = { 
                _("Fast"),
                _("Normal"),
                _("Instant"),
            },
        .optionDescription = _("Hp Speed Description"),
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_EXP_SPEED] =
    {
        .title = _("Exp Speed"),
        .options = { 
                _("Fast"),
                _("Normal"),
                _("Instant"),
            },
        .optionDescription = _("Exp Speed Description"),
        .numOptions = 3,
    },
};

// For Visual Settings

static const u8 sText_Visual_Settings_0[]     = _("Visual Setting 0");
static const u8 sText_Visual_Settings_1[]     = _("Visual Setting 1");
static const u8 sText_Visual_Settings_2[]     = _("Visual Setting 2");
static const u8 sText_Visual_Settings_3[]     = _("Visual Setting 3");
static const u8 sText_Visual_Settings_4[]     = _("Visual Setting 4");
static const u8 sText_Visual_Settings_5[]     = _("Visual Setting 5");

static const u8 *VisualSettings_Settings[NUM_OPTIONS_VISUAL_SETTINGS] = {
    sText_Visual_Settings_0,
    sText_Visual_Settings_1,
    sText_Visual_Settings_2,
    sText_Visual_Settings_3,
    sText_Visual_Settings_4,
    sText_Visual_Settings_5,
};

// For Music Settings
static const u8 sText_Music_Settings_0[]     = _("Music Setting 0");
static const u8 sText_Music_Settings_1[]     = _("Music Setting 1");
static const u8 sText_Music_Settings_2[]     = _("Music Setting 2");
static const u8 sText_Music_Settings_3[]     = _("Music Setting 3");
static const u8 sText_Music_Settings_4[]     = _("Music Setting 4");
static const u8 sText_Music_Settings_5[]     = _("Music Setting 5");

static const u8 *MusicSettings_Settings[NUM_OPTIONS_MUSIC_SETTINGS] = {
    sText_Music_Settings_0,
    sText_Music_Settings_1,
    sText_Music_Settings_2,
    sText_Music_Settings_3,
};

// For Random Settings

static const u8 sText_Random_Settings_0[]     = _("Random Setting 0");
static const u8 sText_Random_Settings_1[]     = _("Random Setting 1");
static const u8 sText_Random_Settings_2[]     = _("Random Setting 2");
static const u8 sText_Random_Settings_3[]     = _("Random Setting 3");
static const u8 sText_Random_Settings_4[]     = _("Random Setting 4");
static const u8 sText_Random_Settings_5[]     = _("Random Setting 5");

static const u8 *RandomSettings_Settings[NUM_OPTIONS_RANDOM_SETTINGS] = {
    sText_Random_Settings_0,
    sText_Random_Settings_1,
    sText_Random_Settings_2,
    sText_Random_Settings_3,
    sText_Random_Settings_4,
    sText_Random_Settings_5,
};

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str = sText_Options_Text;
    u8 i;
    u8 x = 1;
    u8 y = 1;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    // Selector Sprite --------------------------------------------------------------------------------------------------------------------
    x = 0;
    if(!areYouNotOnSettingsHub)
        y = 2 + (currentScreenId * 2);
    else
        y = 2 + (GetCursorPosition() * 2);

    BlitBitmapToWindow(windowId, sOptionMenuSelector, (x*8) + 5, (y*8), 104, 24);

    // Settings Icons --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you are on the Settings Hub
    if(!areYouNotOnSettingsHub){
        x = 1;
	    y = 2;

        for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
            switch(i){
                case GAME_SETTINGS:
                    BlitBitmapToWindow(windowId, sOptionMenuIcon_Game_Settings, (x*8) + 2, (y*8) + 5, 16, 16);
                break;
                case BATTLE_SETTINGS:
                    BlitBitmapToWindow(windowId, sOptionMenuIcon_Battle_Settings, (x*8) + 2, (y*8) + 5, 16, 16);
                break;
                case VISUAL_SETTINGS:
                    BlitBitmapToWindow(windowId, sOptionMenuIcon_Visual_Settings, (x*8) + 2, (y*8) + 5, 16, 16);
                break;
                case MUSIC_SETTINGS:
                    BlitBitmapToWindow(windowId, sOptionMenuIcon_Music_Settings, (x*8) + 2, (y*8) + 5, 16, 16);
                break;
                default:
                    BlitBitmapToWindow(windowId, sOptionMenuIcon_Random_Settings, (x*8) + 2, (y*8) + 5, 16, 16);
                break;
            }

            y = y + 2;
        }
    }
    // Current Setting Icon --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you have a selected settings
    if(areYouNotOnSettingsHub){
        x = 0;
	    y = 0;
            
        switch(currentScreenId){
            case GAME_SETTINGS:
                BlitBitmapToWindow(windowId, sOptionMenuIcon_Game_Settings, (x*8), (y*8), 16, 16);
            break;
            case BATTLE_SETTINGS:
                BlitBitmapToWindow(windowId, sOptionMenuIcon_Battle_Settings, (x*8), (y*8), 16, 16);
            break;
            case VISUAL_SETTINGS:
                BlitBitmapToWindow(windowId, sOptionMenuIcon_Visual_Settings, (x*8), (y*8) + 1, 16, 16);
            break;
            case MUSIC_SETTINGS:
                BlitBitmapToWindow(windowId, sOptionMenuIcon_Music_Settings, (x*8), (y*8), 16, 16);
            break;
            default:
                BlitBitmapToWindow(windowId, sOptionMenuIcon_Random_Settings, (x*8), (y*8) + 1, 16, 16);
            break;
        }
    }
    // Up Arrow --------------------------------------------------------------------------------------------------------------------
    x = 7;
	y = 1;

    if((!areYouNotOnSettingsHub && currentScreenId != 0) || (areYouNotOnSettingsHub && currentFirstOption != 0))
        BlitBitmapToWindow(windowId, sOptionMenuArrow_Up, (x*8), (y*8) + 7, 16, 16);

    // Down Arrow --------------------------------------------------------------------------------------------------------------------
    x = 7;
	y = 11;

    if((!areYouNotOnSettingsHub && currentScreenId != (NUM_OF_SCREENS - 1)) || 
        (areYouNotOnSettingsHub && (currentFirstOption + NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN) <= (GetCurrentScreenOptionNumber() - 1)))
        BlitBitmapToWindow(windowId, sOptionMenuArrow_Down, (x*8), (y*8) + 7, 16, 16);

    // Left Arrow --------------------------------------------------------------------------------------------------------------------
	x = 19;
    if(!areYouNotOnSettingsHub)
        y = 2 + (currentScreenId * 2);
    else
        y = 2 + (GetCursorPosition() * 2);

    BlitBitmapToWindow(windowId, sOptionMenuArrow_Left, (x*8) + 6, (y*8) + 7, 16, 16);

    // Right Arrow --------------------------------------------------------------------------------------------------------------------
	x = 27;
    if(!areYouNotOnSettingsHub)
        y = 2 + (currentScreenId * 2);
    else
        y = 2 + (GetCursorPosition() * 2);

    BlitBitmapToWindow(windowId, sOptionMenuArrow_Right, (x*8) + 6, (y*8) + 7, 16, 16);

    // Settings Hub Text --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you are on the Settings Hub
    if(!areYouNotOnSettingsHub){
        x = 0;
        y = 0;

        AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Title_Settings_Hub);
    }

    // Current Settings Title --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you have a selected settings
    if(areYouNotOnSettingsHub){
        x = 2;
        y = 0;

        AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF,  Hub_Options[currentScreenId].title);
    }

    // Settings Names --------------------------------------------------------------------------------------------------------------------
    if(!areYouNotOnSettingsHub){
        x = 3;
        y = 2;
        for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
            AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, Hub_Options[i].title);
            y = y + 2;
        }
    }
    else{
        x = 1;
        y = 2;
        switch(currentScreenId){
            case GAME_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[GetCurrentSlotOption(i)].title);
                    y = y + 2;
                }
            break;
            case BATTLE_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, BattleSettings_Settings_Options[GetCurrentSlotOption(i)].title);
                    y = y + 2;
                }
            break;
            case VISUAL_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, VisualSettings_Settings[GetCurrentSlotOption(i)]);
                    y = y + 2;
                }
            break;
            case MUSIC_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, MusicSettings_Settings[GetCurrentSlotOption(i)]);
                    y = y + 2;
                }
            break;
            default:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, RandomSettings_Settings[GetCurrentSlotOption(i)]);
                    y = y + 2;
                }
            break;
        }
    }

    // Current Settings --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you are on the Settings Hub
    if(!areYouNotOnSettingsHub){
        x = 21;
        y = 2;

        for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
            AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, Hub_Options[GetCurrentSlotOption(i)].options[Temporal_Options_Preset_Settings[GetCurrentSlotOption(i)]]);
            y = y + 2;
        }
    }
    else{
        x = 21;
        y = 2;

        switch(currentScreenId){
            case GAME_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[GetCurrentSlotOption(i)].options[Temporal_Options_Game_Settings[GetCurrentSlotOption(i)]]);
                    y = y + 2;
                }
            break;
            case BATTLE_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, BattleSettings_Settings_Options[GetCurrentSlotOption(i)].options[Temporal_Options_Battle_Settings[GetCurrentSlotOption(i)]]);
                    y = y + 2;
                }
            break;
        }
        
    }

    // Option Description --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you are on the Settings Hub
    x = 0;
    y = 14;
    if(!areYouNotOnSettingsHub){
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, Hub_Options[currentScreenId].optionDescription);
    }
    else{
        switch(currentScreenId){
            case GAME_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[currentOptionId].optionDescription);
            break;
            case BATTLE_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, BattleSettings_Settings_Options[currentOptionId].optionDescription);
            break;
            case VISUAL_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[currentOptionId].optionDescription);
            break;
            case MUSIC_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[currentOptionId].optionDescription);
            break;
            default:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[currentOptionId].optionDescription);
            break;
        }
    }

    // --------------------------------------------------------------------------------------------------------------------
    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static void Task_MenuWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
        gTasks[taskId].func = Task_MenuMain;
}

static void Task_MenuTurnOff(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sMenuDataPtr->savedCallback);
        Menu_FreeResources();
        DestroyTask(taskId);
    }
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if(JOY_NEW(DPAD_UP))
	{
        if(!areYouNotOnSettingsHub){
            if(currentScreenId > 0){
			    currentScreenId--;
            }
            else{
                currentScreenId = NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN - 1;
            }
        }
        else{
            if(currentOptionId > 0){
			    currentOptionId--;
            }
            else{
                currentOptionId = GetCurrentScreenOptionNumber() - 1;
            }

            if(currentOptionId == currentOptionId){
                if(currentFirstOption > 0){
			        currentFirstOption--;
                }
                else{
                    currentFirstOption = GetCurrentScreenOptionNumber();
                }
            }
            
        }
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_DOWN))
	{
        if(!areYouNotOnSettingsHub){
            if(currentScreenId < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN-1){
                currentScreenId++;
            }
            else{
                currentScreenId = 0;
            }
        }
        else{
            PressedDownButton();
        }
        PlaySE(SE_SELECT);
        

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_LEFT))
	{
        if(!areYouNotOnSettingsHub){
            if(Temporal_Options_Preset_Settings[currentScreenId] > 0){
			    Temporal_Options_Preset_Settings[currentScreenId]--;
            }
            else{
                Temporal_Options_Preset_Settings[currentScreenId] = Hub_Options[currentScreenId].numOptions - 1;
            }
        }
        else{
            switch(currentScreenId){
                case GAME_SETTINGS:
                    if(Temporal_Options_Game_Settings[currentOptionId] > 0){
                        Temporal_Options_Game_Settings[currentOptionId]--;
                    }
                    else{
                        Temporal_Options_Game_Settings[currentOptionId] = GameSettings_Settings_Options[currentOptionId].numOptions - 1;
                    }
                break;
                case BATTLE_SETTINGS:
                    if(Temporal_Options_Battle_Settings[currentOptionId] > 0)
                        Temporal_Options_Battle_Settings[currentOptionId]--;
                    else
                        Temporal_Options_Battle_Settings[currentOptionId] = BattleSettings_Settings_Options[currentOptionId].numOptions - 1;
                break;
            }
        }
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_RIGHT))
	{
        if(!areYouNotOnSettingsHub){
            if(Temporal_Options_Preset_Settings[currentScreenId] < Hub_Options[currentScreenId].numOptions - 1){
                Temporal_Options_Preset_Settings[currentScreenId]++;
            }
            else{
                Temporal_Options_Preset_Settings[currentScreenId] = 0;
            }
        }
        else{
            switch(currentScreenId){
                case GAME_SETTINGS:
                    if(Temporal_Options_Game_Settings[currentOptionId] < GameSettings_Settings_Options[currentOptionId].numOptions - 1){
                        Temporal_Options_Game_Settings[currentOptionId]++;
                    }
                    else{
                        Temporal_Options_Game_Settings[currentOptionId] = 0;
                    }
                break;
                case BATTLE_SETTINGS:
                    if(Temporal_Options_Battle_Settings[currentOptionId] < BattleSettings_Settings_Options[currentOptionId].numOptions - 1){
                        Temporal_Options_Battle_Settings[currentOptionId]++;
                    }
                    else{
                        Temporal_Options_Battle_Settings[currentOptionId] = 0;
                    }
                break;
            }

            /*
            BATTLE_SETTINGS,
            VISUAL_SETTINGS,
            MUSIC_SETTINGS,
            RANDOM_SETTINGS,
            */
        }
        PlaySE(SE_SELECT);
        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if (JOY_NEW(A_BUTTON))
    {
        areYouNotOnSettingsHub = !areYouNotOnSettingsHub;
        currentOptionId = 0;
        currentFirstOption = 0;
        PrintToWindow(WINDOW_1, FONT_BLACK);
    }

    if (JOY_NEW(B_BUTTON))
    {
        if(!areYouNotOnSettingsHub){
            CopyTemporalDataToSaveBlockData();
            PlaySE(SE_PC_OFF);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_MenuTurnOff;
        }
        else{
            areYouNotOnSettingsHub = !areYouNotOnSettingsHub;
            currentOptionId = 0;
            currentFirstOption = 0;
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
    }
}