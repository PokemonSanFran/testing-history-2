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
#include "item_icon.h"
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
#include "money.h"
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
#include "constants/items.h"
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
#define NUM_MAX_ITEMS_PER_ROW 20

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuyBuffer = NULL;

static EWRAM_DATA u8  currentRow = 0;
static EWRAM_DATA u8  currentItem = 0;
static EWRAM_DATA u8  currentScreenId = 0;
static EWRAM_DATA u8  currentFirstShownRow = 0;
static EWRAM_DATA u8  currentFirstShownItem = 0;

static EWRAM_DATA u16 currentRowItemList[NUM_ROWS][NUM_MAX_ITEMS_PER_ROW];
static EWRAM_DATA u8  itemNum[NUM_ROWS];
static EWRAM_DATA bool8 rowsSorted = FALSE;
static EWRAM_DATA bool8 buyScreen = FALSE;

static EWRAM_DATA u8 sItemMenuIconSpriteIds_0[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_1[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_2[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_3[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_4[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_5[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_6[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_7[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_8[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_9[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_10[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_11[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_12[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_13[12] = {0};
static EWRAM_DATA u8 sItemMenuIconSpriteIds_14[12] = {0};

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
static void AmazonItemInitializeArrayList(void);

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
static const u32 sMenuTilemapBuy[] = INCBIN_U32("graphics/ui_menus/amazon/tilemap_buy.bin.lz");
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

    AmazonItemInitializeArrayList();

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
    try_free(sBg1TilemapBuyBuffer);
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
    if(!buyScreen){
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
    else{
        ResetAllBgsCoordinates();
        sBg1TilemapBuyBuffer = Alloc(0x800);
        if (sBg1TilemapBuyBuffer == NULL)
            return FALSE;

        memset(sBg1TilemapBuyBuffer, 0, 0x800);
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
        SetBgTilemapBuffer(1, sBg1TilemapBuyBuffer);
        ScheduleBgCopyTilemapToVram(1);
        ShowBg(0);
        ShowBg(1);
        ShowBg(2);
        return TRUE;
    }
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
            LZDecompressWram(sMenuTilemapBuy, sBg1TilemapBuyBuffer);
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

static void CreateItemIcon(u16 itemId, u8 idx, u8 x, u8 y)
{
    u8 * ptr;
    u8 spriteId;

    switch(idx){
        case 0:
            ptr = &sItemMenuIconSpriteIds_0[10];
        break;
        case 1:
            ptr = &sItemMenuIconSpriteIds_1[10];
        break;
        case 2:
            ptr = &sItemMenuIconSpriteIds_2[10];
        break;
        case 3:
            ptr = &sItemMenuIconSpriteIds_3[10];
        break;
        case 4:
            ptr = &sItemMenuIconSpriteIds_4[10];
        break;
        case 5:
            ptr = &sItemMenuIconSpriteIds_5[10];
        break;
        case 6:
            ptr = &sItemMenuIconSpriteIds_6[10];
        break;
        case 7:
            ptr = &sItemMenuIconSpriteIds_7[10];
        break;
        case 8:
            ptr = &sItemMenuIconSpriteIds_8[10];
        break;
        case 9:
            ptr = &sItemMenuIconSpriteIds_9[10];
        break;
        case 10:
            ptr = &sItemMenuIconSpriteIds_10[10];
        break;
        case 11:
            ptr = &sItemMenuIconSpriteIds_11[10];
        break;
        case 12:
            ptr = &sItemMenuIconSpriteIds_12[10];
        break;
        case 13:
            ptr = &sItemMenuIconSpriteIds_13[10];
        break;
        case 14:
            ptr = &sItemMenuIconSpriteIds_14[10];
        break;
    }

    FreeSpriteTilesByTag(102 + idx);
    FreeSpritePaletteByTag(102 + idx);
    spriteId = AddItemIconSprite(102 + idx, 102 + idx, itemId);
        
    ptr[idx] = spriteId;
    gSprites[spriteId].x2 = x; //24;
    gSprites[spriteId].y2 = y; //140;
}

// --------------------------------------------------------------------------------------------------------------------

u8 GetCurrentRow(){
    /*/if(rowsSorted){
        return (currentRow + 2) % NUM_ROWS;
    }
    else{
       return currentRow % NUM_ROWS;
    }*/
    return currentRow % NUM_ROWS;
}

static u8 GetCursorPosition()
{
    return currentRow - currentFirstShownRow;
}

static void PressedDownButton(){
    u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = NUM_ROWS - halfScreen;
    u8 cursorPosition = (currentRow - currentFirstShownRow);
    currentItem = 0;
	currentFirstShownItem = 0;

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
    
    mgba_printf(MGBA_LOG_WARN, "Current Row %d", currentRow);
    mgba_printf(MGBA_LOG_WARN, "Cursor Position %d", cursorPosition);
    mgba_printf(MGBA_LOG_WARN, "First Row %d", currentFirstShownRow);
    mgba_printf(MGBA_LOG_WARN, "------------------------------------");
}

static void PressedUpButton(){
    u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = NUM_ROWS - halfScreen;
    u8 cursorPosition = (currentRow - currentFirstShownRow);
    currentItem = 0;
	currentFirstShownItem = 0;

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

    mgba_printf(MGBA_LOG_WARN, "Current Row %d", currentRow);
    mgba_printf(MGBA_LOG_WARN, "Cursor Position %d", cursorPosition);
    mgba_printf(MGBA_LOG_WARN, "First Row %d", currentFirstShownRow);
    mgba_printf(MGBA_LOG_WARN, "------------------------------------");
}

static void PressedRightButton(){
    u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = itemNum[currentRow] - halfScreen;
    u8 cursorPosition = (currentItem - currentFirstShownItem);

    if(currentItem < halfScreen){
        currentItem++;
    }
	else if(currentItem >= (itemNum[currentRow] - 1)){ //If you are in the last option go to the first one
		currentItem = 0;
		currentFirstShownItem = 0;
    }
    else if(currentItem >= (finalhalfScreen - 1)){
        currentItem++;
    }
	else{
        currentItem++;
        currentFirstShownItem++;
    }
    
    mgba_printf(MGBA_LOG_WARN, "Current Item %d", currentItem);
    mgba_printf(MGBA_LOG_WARN, "------------------------------------");
}

static void PressedLeftButton(){
    u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = itemNum[currentRow] - halfScreen;
    u8 cursorPosition = (currentItem - currentFirstShownItem);

    if(currentItem > halfScreen && currentItem <= (finalhalfScreen - 1)){
        currentItem--;
        currentFirstShownItem--;
    }
	else if(currentItem == 0){ //If you are in the first option go to the last one
		currentItem = itemNum[currentRow] - 1;
		currentFirstShownItem = itemNum[currentRow] - NUM_MAX_ICONS_ROWNS_ON_SCREEN;
    }
    else{
        currentItem--;
    }

    mgba_printf(MGBA_LOG_WARN, "Current Row %d", currentItem);
    mgba_printf(MGBA_LOG_WARN, "Cursor Position %d", cursorPosition);
    mgba_printf(MGBA_LOG_WARN, "First Row %d", currentFirstShownItem);
    mgba_printf(MGBA_LOG_WARN, "------------------------------------");
}

#define ROW_NAME_LENGTH 20
#define FLAG_NONE 0
#define VAR_NONE 0

struct AmazonRowData
{
    const u8 title[ROW_NAME_LENGTH];
};

struct AmazonItemData
{
    u16 item;
    u8  numBadges;
    u16 reqFlag;
    u16 reqVar;
    u16 reqVarState;
};

struct AmazonItemData Amazon_Items[NUM_ROWS][NUM_MAX_ITEMS_PER_ROW] = {
    [ROW_RECOMMENDED] =
    {
        {
            .item = ITEM_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_SUPER_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_MAX_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_LURE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_SUPER_LURE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_MEDICINE] =
    {
        {
            .item = ITEM_POTION,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_SUPER_POTION,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_HYPER_POTION,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_MAX_POTION,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_FULL_RESTORE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_REVIVE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_POKEBALLS] =
    {
        {
            .item = ITEM_POKE_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_GREAT_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_ULTRA_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_PREMIER_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_HEAL_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_OTHER_ITEMS] =
    {
        {
            .item = ITEM_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_SUPER_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_MAX_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_LURE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_SUPER_LURE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_POWER_UPS] =
    {
        {
            .item = ITEM_HP_UP,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_PROTEIN,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_IRON,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_CALCIUM,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_ZINC,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_BATTLE_ITEMS] =
    {
        {
            .item = ITEM_X_ATTACK,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_X_DEFENSE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_X_SP_ATK,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_X_SP_DEF,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_X_SPEED,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_DIRE_HIT,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_GUARD_SPEC,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_POKE_DOLL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_FLUFFY_TAIL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_POKE_TOY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_BERRIES] =
    {
        {
            .item = ITEM_CHERI_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_CHESTO_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_PECHA_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_RAWST_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_ASPEAR_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_LEPPA_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_TMS] =
    {
        {
            .item = ITEM_TM01,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_TM02,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_TM03,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_TM04,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_TM05,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_TREASURES] =
    {
        {
            .item = ITEM_MAX_MUSHROOMS,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_NUGGET,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_BIG_NUGGET,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_TINY_MUSHROOM,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_BIG_MUSHROOM,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_MEGA_STONES] =
    {
        {
            .item = ITEM_VENUSAURITE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_CHARIZARDITE_X,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_CHARIZARDITE_Y,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_BLASTOISINITE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_BEEDRILLITE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
    [ROW_Z_CRYSTALS] =
    {
        {
            .item = ITEM_NORMALIUM_Z,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_FIRIUM_Z,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_WATERIUM_Z,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_ELECTRIUM_Z,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
        {
            .item = ITEM_GRASSIUM_Z,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
        },
    },
};

void AmazonItemInitializeArrayList()
{
    u8 i, j;
    bool8 canBuy = TRUE;
    u16 badgeFlag;
    u8 numbadges = 0;
    
    for (badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++){
        if (FlagGet(badgeFlag))
        numbadges++;
    }

    for(i = 0; i < NUM_ROWS; i++){
        itemNum[i] = 0;
        for(j = 0; j < NUM_MAX_ITEMS_PER_ROW; j++){
            if(Amazon_Items[i][j].item != ITEM_NONE && i != ROW_BUY_AGAIN){
                canBuy = TRUE;

                if(VarGet(Amazon_Items[i][j].reqVar) < Amazon_Items[i][j].reqVarState && Amazon_Items[i][j].reqVar != VAR_NONE)
                    canBuy = FALSE;

                if(!FlagGet(Amazon_Items[i][j].reqFlag) && Amazon_Items[i][j].reqFlag != FLAG_NONE)
                    canBuy = FALSE;

                if(numbadges < Amazon_Items[i][j].numBadges && Amazon_Items[i][j].numBadges != 0)
                    canBuy = FALSE;

                if(canBuy){
                    currentRowItemList[i][itemNum[i]] = Amazon_Items[i][j].item;
                    itemNum[i]++;
                }
            }
            else if(i == ROW_BUY_AGAIN && j < MAX_AMAZON_BUY_AGAIN_ITEMS){
                if(gSaveBlock2Ptr->amazonBuyAgainItem[j] == ITEM_NONE)
                    gSaveBlock2Ptr->amazonBuyAgainItem[j] = ITEM_POKE_BALL;

                currentRowItemList[i][itemNum[i]] = gSaveBlock2Ptr->amazonBuyAgainItem[j];
                itemNum[i]++;
            }
        }
    }
}

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
        .title = _("Berries"),
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
static const u8 sRowIcon_0[]                = INCBIN_U8("graphics/ui_menus/amazon/icon_0.4bpp");
static const u8 sRowIcon_1[]                = INCBIN_U8("graphics/ui_menus/amazon/icon_1.4bpp");
static const u8 sRowIcon_2[]                = INCBIN_U8("graphics/ui_menus/amazon/icon_2.4bpp");
static const u8 sRowIcon_Pokeball[]         = INCBIN_U8("graphics/ui_menus/amazon/icon_pokeball.4bpp");
static const u8 sRowIcon_Potion[]           = INCBIN_U8("graphics/ui_menus/amazon/icon_potion.4bpp");
static const u8 sRowIcon_TM[]               = INCBIN_U8("graphics/ui_menus/amazon/icon_tm.4bpp");
static const u8 sRowIcon_Berries[]          = INCBIN_U8("graphics/ui_menus/amazon/icon_berries.4bpp");
static const u8 sRowIcon_Candy[]            = INCBIN_U8("graphics/ui_menus/amazon/icon_candy.4bpp");
static const u8 sRowIcon_Key[]              = INCBIN_U8("graphics/ui_menus/amazon/icon_key.4bpp");

static const u8 sRowSelector[]      = INCBIN_U8("graphics/ui_menus/amazon/row_selector.4bpp");
static const u8 sBuySelector[]      = INCBIN_U8("graphics/ui_menus/amazon/selector1.4bpp");

static const u8 sText_Help_Bar[]  = _("{DPAD_UPDOWN} Rows {DPAD_LEFTRIGHT} Items {A_BUTTON} Buy {B_BUTTON} Exit {START_BUTTON} Sort Rows");
static const u8 sText_Money_Bar[]  = _("Money: ¥{STR_VAR_1}");
static const u8 sText_FirstRowName[]  = _("{STR_VAR_1}: {STR_VAR_2}");

#define MAX_MONEY 999999

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str = sText_Help_Bar;
    u8 i, j, x2, y2, itemID;
    u8 x = 1;
    u8 y = 1;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    // Row Icons
    x = 1;
    y = 2;
    x2 = 0;
    y2 = 4;

    for(i = 0; i < NUM_MAX_ICONS_ROWNS_ON_SCREEN; i++ ){
        if(GetCurrentRow() == currentFirstShownRow + i)
            BlitBitmapToWindow(windowId, sRowSelector, ((x-1)*8) + x2, ((y-1)*8) + y2 + 4, 32, 24);

        switch(currentFirstShownRow + i){
            case ROW_BUY_AGAIN:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_RECOMMENDED:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_MEDICINE:
                BlitBitmapToWindow(windowId, sRowIcon_Potion, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_POKEBALLS:
                BlitBitmapToWindow(windowId, sRowIcon_Pokeball, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_OTHER_ITEMS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_POWER_UPS:
                BlitBitmapToWindow(windowId, sRowIcon_Candy, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_BATTLE_ITEMS:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_BERRIES:
                BlitBitmapToWindow(windowId, sRowIcon_Berries, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_TMS:
                BlitBitmapToWindow(windowId, sRowIcon_TM, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_TREASURES:
                BlitBitmapToWindow(windowId, sRowIcon_2, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_MEGA_STONES:
                BlitBitmapToWindow(windowId, sRowIcon_1, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            case ROW_Z_CRYSTALS:
                BlitBitmapToWindow(windowId, sRowIcon_Key, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
            default:
                BlitBitmapToWindow(windowId, sRowIcon_0, (x*8) + x2, (y*8) + y2, 16, 16);
            break;
        }

        y = y + 3;
        y2 = y2 + 2;
    }

    //Buy Icon
    x = (5 * (currentItem - currentFirstShownItem)) + 4;
    y = 5;
    x2 = (2 * (currentItem - currentFirstShownItem)) + 2;
    BlitBitmapToWindow(windowId, sBuySelector, (x*8) + x2, (y*8), 32, 16);

    // Item Icon
    x = 6;
    y = 5;
    x2 = 6;
    y2 = 6;
    itemID = 0;

    for(i = 0; i < NUM_MAX_ROWNS_ON_SCREEN; i++ ){
        for(j = 0; j < NUM_MAX_ICONS_ROWNS_ON_SCREEN; j++ ){
            if(i == 0){
                CreateItemIcon(currentRowItemList[(GetCurrentRow() + i) % NUM_ROWS][(currentFirstShownItem + j) % itemNum[GetCurrentRow() + i]], itemID, (x * 8) + x2, (y * 8) + y2);
            }
            else{
                CreateItemIcon(currentRowItemList[(GetCurrentRow() + i) % NUM_ROWS][j % itemNum[GetCurrentRow() + i]], itemID, (x * 8) + x2, (y * 8) + y2);
            }
            
            x = x + 5;
            x2 = x2 + 2;
            itemID++;
        }
        x = 6;
        x2 = 6;
        y = y + 5;
        y2 = y2 + 4;
    }

    // Row Names
    x = 4;

    for(i = 0; i < NUM_MAX_ROWNS_ON_SCREEN; i++ ){
        if(i == 0){
            str = Amazon_Rows[(currentRow + i) % NUM_ROWS].title;
            StringCopy(gStringVar1, str);
            str = gItems[currentRowItemList[(GetCurrentRow()) % NUM_ROWS][currentItem]].name;
            StringCopy(gStringVar2, str);
            StringExpandPlaceholders(gStringVar4, sText_FirstRowName);
        }
        else{
            StringCopy(gStringVar4, Amazon_Rows[(GetCurrentRow() + i) % NUM_ROWS].title);
        }

        switch(i){
            case 0:
                y = 2;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
            break;
            case 1:
                y = 7;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
            break;
            case 2:
                y = 13;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
            break;
        }
    }

    // Help Bar --------------------------------------------------------------------------------------------------------------------
	x = 0;
	y = 18;

    AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar);
    // Money --------------------------------------------------------------------------------------------------------------------
	x = 20;
	y = 0;
    AddMoney(&gSaveBlock1Ptr->money, MAX_MONEY);
    ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_RIGHT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, sText_Money_Bar);

    AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

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
        Menu_FreeResources();
        SetMainCallback2(sMenuDataPtr->savedCallback);
        DestroyTask(taskId);
    }
}

static void Task_MenuBuy(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        if(buyScreen)
            mgba_printf(MGBA_LOG_WARN, "Buy Screen");
        else
            mgba_printf(MGBA_LOG_WARN, "Not Buy Screen");

        Menu_FreeResources();
        Amazon_Init(CB2_ReturnToUIMenu);
        gMain.savedCallback = CB2_ReturnToUIMenu;
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

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        buyScreen = !buyScreen;
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuBuy;
    }

    //
    if(JOY_NEW(START_BUTTON))
	{
        rowsSorted = !rowsSorted;
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
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

    if(JOY_NEW(DPAD_RIGHT))
	{
        PressedRightButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_LEFT))
	{
        PressedLeftButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

}