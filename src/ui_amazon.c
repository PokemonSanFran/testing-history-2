#include "global.h"
#include "ui_amazon.h"
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

enum RowIds
{
    ROW_BUY_AGAIN,
    ROW_RECOMMENDED,
    ROW_MEDICINE,
    ROW_POKEBALLS,
    ROW_OTHER_ITEMS,
    ROW_POWER_UPS,
    ROW_BATTLE_ITEMS,
    ROW_BERRIES,
    ROW_TMS,
    ROW_TREASURES,
    ROW_MEGA_STONES,
    ROW_Z_CRYSTALS,
    NUM_ROWS
};

#define NUM_ITEMS_PER_ROW 5
#define NUM_MAX_ICONS_ROWNS_ON_SCREEN 5
#define NUM_MAX_ROWNS_ON_SCREEN 3

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

static EWRAM_DATA u8  currentRow = 0;
static EWRAM_DATA u8  currentItem = 0;
static EWRAM_DATA u8  currentScreenId = 0;
static EWRAM_DATA u8  currentFirstShownRow = 0;

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

static const u32 sMenuTiles[]   = INCBIN_U32("graphics/ui_menus/amazon/tiles.4bpp.lz");
static const u32 sMenuTilemap[] = INCBIN_U32("graphics/ui_menus/amazon/tilemap.bin.lz");
static const u16 sMenuPalette[] = INCBIN_U16("graphics/ui_menus/amazon/palette.gbapal");

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
void Task_OpenAmazonFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Amazon_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Amazon_Init(MainCallback callback)
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

// --------------------------------------------------------------------------------------------------------------------

static u8 GetCurrentRow(u8 row)
{
    if(currentFirstShownRow + row < NUM_ROWS)
        return currentFirstShownRow + row;
    else
        return (currentFirstShownRow + row) % NUM_ROWS;
}

static u8 GetCursorPosition()
{
    return currentRow - currentFirstShownRow;
}

static void PressedDownButton(){
    u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = NUM_ROWS - halfScreen;
    u8 cursorPosition = (currentRow - currentFirstShownRow);

    if(currentRow < halfScreen){
        currentRow++;
    }
	else if(currentRow >= (NUM_ROWS - 1)){ //If you are in the last option go to the first one
		currentRow = 0;
		currentFirstShownRow = 0;
    }
    else if(currentRow >= (finalhalfScreen - 1)){
        currentRow++;
    }
	else{
        currentRow++;
        currentFirstShownRow++;
    }
}

static void PressedUpButton(){
    u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = NUM_ROWS - halfScreen;
    u8 cursorPosition = (currentRow - currentFirstShownRow);

    if(currentRow > halfScreen && currentRow <= (finalhalfScreen - 1)){
        currentRow--;
        currentFirstShownRow--;
    }
	else if(currentRow == 0){ //If you are in the first option go to the last one
		currentRow = NUM_ROWS - 1;
		currentFirstShownRow = NUM_ROWS - NUM_MAX_ICONS_ROWNS_ON_SCREEN;
    }
    else{
        currentRow--;
    }
}


#define ROW_NAME_LENGTH 20

struct AmazonRowData
{
    const u8 title[ROW_NAME_LENGTH];
};

struct AmazonRowData Amazon_Rows[NUM_ROWS] = {
    [ROW_BUY_AGAIN] =
    {
        .title = _("Buy Again"),
    },
    [ROW_RECOMMENDED] =
    {
        .title = _("Recommended"),
    },
    [ROW_MEDICINE] =
    {
        .title = _("Medicine"),
    },
    [ROW_POKEBALLS] =
    {
        .title = _("Pokeballs"),
    },
    [ROW_OTHER_ITEMS] =
    {
        .title = _("Other Items"),
    },
    [ROW_POWER_UPS] =
    {
        .title = _("Power-Ups"),
    },
    [ROW_BATTLE_ITEMS] =
    {
        .title = _("Battle Items"),
    },
    [ROW_BERRIES] =
    {
        .title = _("Berris"),
    },
    [ROW_TMS] =
    {
        .title = _("TMs"),
    },
    [ROW_TREASURES] =
    {
        .title = _("Treasures"),
    },
    [ROW_MEGA_STONES] =
    {
        .title = _("Mega Stones"),
    },
    [ROW_Z_CRYSTALS] =
    {
        .title = _("Z-Crystals"),
    },
};

//Graphics
static const u8 sRowIcon_0[]        = INCBIN_U8("graphics/ui_menus/amazon/icon_0.4bpp");
static const u8 sRowSelector[]      = INCBIN_U8("graphics/ui_menus/amazon/row_selector.4bpp");


static const u8 sText_Help_Bar[]  = _("{DPAD_UPDOWN} Rows {DPAD_LEFTRIGHT} Items {A_BUTTON} Buy {B_BUTTON} Exit {START_BUTTON} Sort Rows");
static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str = sText_Help_Bar;
    u8 i;
    u8 x = 1;
    u8 y = 1;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    // Row Icons
    x = 1;
    y = 3;

    for(i = 0; i < NUM_MAX_ICONS_ROWNS_ON_SCREEN; i++ ){
        //if(GetCurrentRow(i) == currentFirstShownRow + i)
        //    BlitBitmapToWindow(windowId, sRowSelector, ((x-1)*8), ((y-1)*8), 32, 24);

        switch(GetCurrentRow(i)){
            case ROW_BUY_AGAIN:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_RECOMMENDED:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_MEDICINE:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_POKEBALLS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_OTHER_ITEMS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_POWER_UPS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_BATTLE_ITEMS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_BERRIES:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_TMS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_TREASURES:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_MEGA_STONES:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            case ROW_Z_CRYSTALS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
            default:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8), (y*8), 16, 16);
            break;
        }

        y = y + 3;
    }

    // Row Names
    x = 4;

    for(i = 0; i < NUM_MAX_ROWNS_ON_SCREEN; i++ ){
        str = Amazon_Rows[GetCursorPosition() + i].title;

        switch(i){
            case 0:
                y = 2;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str);
            break;
            case 1:
                y = 7;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str);
            break;
            case 2:
                y = 13;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str);
            break;
        }
    }

    // Help Bar --------------------------------------------------------------------------------------------------------------------
	x = 0;
	y = 18;

    AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar);
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
    if (JOY_NEW(B_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }

    if(JOY_NEW(DPAD_UP))
	{
        PressedUpButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_DOWN))
	{
        PressedDownButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}
}