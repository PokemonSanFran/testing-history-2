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
#include "trig.h"
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
#include "region_map.h"
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

struct AmazonMenuResources {
	MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
	u16 currentRow:4;                //Max 12
	u16 currentFirstShownRow:4;      //Max 9
	u16 currentItem:5;               //Max 20
	u16 rowsSorted:1;                //bool8
	u16 buyScreen:1;                 //bool8
	u16 buyWindow:1;                 //bool8
	u16 itemQuantity:7;              //Max 99
	u16 currentFirstShownItem:4;     //Max 14
	u16 notEnoughMoneyWindow:1;      //bool8
	u16 filler1:3;                   //Max 8
	u16 currentRowItemList[NUM_ROWS][NUM_MAX_ITEMS_PER_ROW];
	u8 spriteIDs[20];
    u8 sItemMenuBuyIcon[12];
    u8 AmazonUpDownArrowsTask;
    u8 AmazonLeftRightArrowsTask;
};

//==========EWRAM==========//
static EWRAM_DATA struct AmazonMenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

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
static void DestroyAllItemIcons(void);
static void EnableAllItemIcons(void);
static void DisableAllItemIcons(void);
static void MoveCurrenItemIcon(u8 idx, u8 x, u8 y);

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

static const u32 sMenuTiles[]       = INCBIN_U32("graphics/ui_menus/amazon/tiles.4bpp.lz");
static const u32 sMenuTilemap[]     = INCBIN_U32("graphics/ui_menus/amazon/tilemap.bin.lz");
static const u32 sMenuTilemapBuy[]  = INCBIN_U32("graphics/ui_menus/amazon/tilemap_buy.bin.lz");
static const u16 sMenuPalette[]     = INCBIN_U16("graphics/ui_menus/amazon/palette.gbapal");

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
    u16 size = sizeof(struct AmazonMenuResources);

    if ((sMenuDataPtr = AllocZeroed(sizeof(struct AmazonMenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;

    
    sMenuDataPtr->currentRow = 0;
    sMenuDataPtr->currentItem = 0;
    sMenuDataPtr->currentFirstShownRow  = 0;
    sMenuDataPtr->currentFirstShownItem = 0;
    sMenuDataPtr->itemQuantity  = 0;

    sMenuDataPtr->rowsSorted = FALSE;
    sMenuDataPtr->buyScreen = FALSE;
    sMenuDataPtr->buyWindow = FALSE;
    sMenuDataPtr->notEnoughMoneyWindow = FALSE;

    sMenuDataPtr->AmazonUpDownArrowsTask = TASK_NONE;

    AmazonItemInitializeArrayList();
    
    mgba_printf(MGBA_LOG_WARN, "The Amazon EWRAM is using %d bytes out of 32770", size);

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

u8 GetCurrentRow(){

    if(sMenuDataPtr->rowsSorted){
        return (sMenuDataPtr->currentRow + 2) % NUM_ROWS;
    }
    else{
       return sMenuDataPtr->currentRow % NUM_ROWS;
    }
    return sMenuDataPtr->currentRow % NUM_ROWS;
}

u8 getCurrentRowItemNum(){
    u8 i, itemNum;

    itemNum = 0;

    for(i = 0; i < 20; i++){
        if(sMenuDataPtr->currentRowItemList[GetCurrentRow()][i] != ITEM_NONE)
            itemNum++;
    }

    return itemNum;
}

// Sprite Callback -------------------------------------------------------------------------------------------------------

static void SpriteCB_BuyIcon(struct Sprite *sprite)
{
    if(sMenuDataPtr->buyScreen)
        sprite->invisible = TRUE;
    else{
        u8 num = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);
        u8 x = (5 * num);
        sprite->x2 = (x * 8) + (2 * num);
        sprite->invisible = FALSE;
    }
}

static void SpriteCB_AmazonInvisibleOnBuyMenu(struct Sprite *sprite)
{
    if(sMenuDataPtr->buyScreen)
        sprite->invisible = TRUE;
    else{
        sprite->invisible = FALSE;
    }
}

static void SpriteCallback_UpArrow(struct Sprite *sprite)
{
    u8 val = sprite->data[0];
    sprite->y2 = gSineTable[val] / 128;
    sprite->data[0] += 8;

    if(sMenuDataPtr->buyScreen || sMenuDataPtr->currentRow == ROW_BUY_AGAIN)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;
}

static void SpriteCallback_DownArrow(struct Sprite *sprite)
{
    u8 val = sprite->data[0] + 128;
    sprite->y2 = gSineTable[val] / 128;
    sprite->data[0] += 8;

    if(sMenuDataPtr->buyScreen || sMenuDataPtr->currentRow == NUM_ROWS - 1)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;
}

#define LEFT_ARROW_X 30
#define LEFT_ARROW_Y 43
#define RIGHT_ARROW_X 70
#define RIGHT_ARROW_Y 43

static void SpriteCallback_LeftArrow(struct Sprite *sprite)
{
    u8 num = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);
    u8 x = (5 * num);
    u8 val = sprite->data[0] + 128;
    sprite->x = LEFT_ARROW_X + (x * 8) + (2 * num);

    sprite->x2 = gSineTable[val] / 128;
    sprite->data[0] += 8;

    if(sMenuDataPtr->buyScreen || sMenuDataPtr->currentItem == 0)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;
}

static void SpriteCallback_RightArrow(struct Sprite *sprite)
{
    u8 itemNum = getCurrentRowItemNum();
    u8 val = sprite->data[0];
    u8 num = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);
    u8 x = (5 * num);

    sprite->x = RIGHT_ARROW_X + (x * 8) + (2 * num);
    sprite->x2 = gSineTable[val] / 128;
    sprite->data[0] += 8;

    if(sMenuDataPtr->buyScreen || sMenuDataPtr->currentItem == itemNum - 1)
        sprite->invisible = TRUE;
    else
        sprite->invisible = FALSE;
}

// Buy Icon Sprite -------------------------------------------------------------------------------------------------------
#define TAG_AMAZON_INTERFACE 0 // Tile and pal tag used for all interface sprites.
#define PAL_UI_SPRITES 0

enum AmazonSpriteIDs
{
    SPRITE_BUY_ICON_ID,
    SPRITE_UP_ARROW,
    SPRITE_DOWN_ARROW,
    SPRITE_LEFT_ARROW,
    SPRITE_RIGHT_ARROW,
    NUM_AMAZON_SPRITES,
};

enum {
    GFXTAG_BUY_ICON = TAG_AMAZON_INTERFACE,
    GFXTAG_UP_ARROW,
    GFXTAG_DOWN_ARROW,
    GFXTAG_LEFT_ARROW,
    GFXTAG_RIGHT_ARROW,
};

static const u32 gBattleAmazonBuyIcon_Gfx[]    = INCBIN_U32("graphics/ui_menus/amazon/buyicon.4bpp.lz");
static const u32 gBattleAmazonUpArrow_Gfx[]    = INCBIN_U32("graphics/ui_menus/amazon/arrow_up.4bpp.lz");
static const u32 gBattleAmazonDownArrow_Gfx[]  = INCBIN_U32("graphics/ui_menus/amazon/arrow_down.4bpp.lz");
static const u32 gBattleAmazonLeftArrow_Gfx[]  = INCBIN_U32("graphics/ui_menus/amazon/arrow_left.4bpp.lz");
static const u32 gBattleAmazonRightArrow_Gfx[] = INCBIN_U32("graphics/ui_menus/amazon/arrow_right.4bpp.lz");

static const struct SpritePalette sAmazonInterfaceSpritePalette[] = {sMenuPalette, PAL_UI_SPRITES};

static void CreateBuyIconSprite(void)
{
    u8 spriteId;
    u8 SpriteTag = GFXTAG_BUY_ICON;
    struct CompressedSpriteSheet sSpriteSheet_AmazonBuyIcon = {gBattleAmazonBuyIcon_Gfx, 0x0800, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = SpriteTag;
    TempSpriteTemplate.callback = SpriteCB_BuyIcon;

    LoadCompressedSpriteSheet(&sSpriteSheet_AmazonBuyIcon);
    LoadSpritePalette(sAmazonInterfaceSpritePalette);
    spriteId = CreateSprite(&TempSpriteTemplate, 38, 43, 0);
    sMenuDataPtr->spriteIDs[SPRITE_BUY_ICON_ID] = spriteId;

    gSprites[sMenuDataPtr->spriteIDs[SPRITE_BUY_ICON_ID]].oam.shape = SPRITE_SHAPE(32x16);
    gSprites[sMenuDataPtr->spriteIDs[SPRITE_BUY_ICON_ID]].oam.size = SPRITE_SIZE(32x16);
    gSprites[sMenuDataPtr->spriteIDs[SPRITE_BUY_ICON_ID]].oam.priority = 1;
}

#define UP_ARROW_X 120
#define UP_ARROW_Y 0

static void CreateUpArrowSprite(void)
{
    u8 x, y, spriteId;
    u8 SpriteTag = GFXTAG_UP_ARROW;
    struct CompressedSpriteSheet sSpriteSheet_AmazonUpArrow = {gBattleAmazonUpArrow_Gfx, 0x0800, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = SpriteTag;
    TempSpriteTemplate.callback = SpriteCallback_UpArrow;

    LoadCompressedSpriteSheet(&sSpriteSheet_AmazonUpArrow);
    spriteId = CreateSprite(&TempSpriteTemplate, UP_ARROW_X, UP_ARROW_Y, 0);
    sMenuDataPtr->spriteIDs[SPRITE_UP_ARROW] = spriteId;

    gSprites[sMenuDataPtr->spriteIDs[SPRITE_UP_ARROW]].oam.shape = SPRITE_SHAPE(32x16);
    gSprites[sMenuDataPtr->spriteIDs[SPRITE_UP_ARROW]].oam.size = SPRITE_SIZE(32x16);
    gSprites[sMenuDataPtr->spriteIDs[SPRITE_UP_ARROW]].oam.priority = 1;
}

#define DOWN_ARROW_X UP_ARROW_X
#define DOWN_ARROW_Y 146

static void CreateDownArrowSprite(void)
{
    u8 x, y, spriteId;
    u8 SpriteTag = GFXTAG_DOWN_ARROW;
    struct CompressedSpriteSheet sSpriteSheet_AmazonDownArrow = {gBattleAmazonDownArrow_Gfx, 0x0800, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag = SpriteTag;
    TempSpriteTemplate.callback = SpriteCallback_DownArrow;

    LoadCompressedSpriteSheet(&sSpriteSheet_AmazonDownArrow);
    spriteId = CreateSprite(&TempSpriteTemplate, DOWN_ARROW_X, DOWN_ARROW_Y, 0);
    sMenuDataPtr->spriteIDs[SPRITE_DOWN_ARROW] = spriteId;

    gSprites[sMenuDataPtr->spriteIDs[SPRITE_DOWN_ARROW]].oam.shape = SPRITE_SHAPE(32x16);
    gSprites[sMenuDataPtr->spriteIDs[SPRITE_DOWN_ARROW]].oam.size = SPRITE_SIZE(32x16);
    gSprites[sMenuDataPtr->spriteIDs[SPRITE_DOWN_ARROW]].oam.priority = 1;
}


static void CreateLeftArrowSprite(void)
{
    u8 x, y, spriteId;
    u8 SpriteTag = GFXTAG_LEFT_ARROW;
    struct CompressedSpriteSheet sSpriteSheet_AmazonLeftArrow = {gBattleAmazonLeftArrow_Gfx, 0x0800, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag  = SpriteTag;
    TempSpriteTemplate.callback = SpriteCallback_LeftArrow;

    LoadCompressedSpriteSheet(&sSpriteSheet_AmazonLeftArrow);
    spriteId = CreateSprite(&TempSpriteTemplate, LEFT_ARROW_X, LEFT_ARROW_Y, 0);
    sMenuDataPtr->spriteIDs[SpriteTag] = spriteId;

    gSprites[sMenuDataPtr->spriteIDs[SpriteTag]].oam.shape = SPRITE_SHAPE(8x16);
    gSprites[sMenuDataPtr->spriteIDs[SpriteTag]].oam.size = SPRITE_SIZE(8x16);
    gSprites[sMenuDataPtr->spriteIDs[SpriteTag]].oam.priority = 1;
}

static void CreateRightArrowSprite(void)
{
    u8 x, y, spriteId;
    u8 SpriteTag = GFXTAG_RIGHT_ARROW;
    struct CompressedSpriteSheet sSpriteSheet_AmazonLeftArrow = {gBattleAmazonRightArrow_Gfx, 0x0800, SpriteTag};
    struct SpriteTemplate TempSpriteTemplate = gDummySpriteTemplate;

    TempSpriteTemplate.tileTag  = SpriteTag;
    TempSpriteTemplate.callback = SpriteCallback_RightArrow;

    LoadCompressedSpriteSheet(&sSpriteSheet_AmazonLeftArrow);
    spriteId = CreateSprite(&TempSpriteTemplate, RIGHT_ARROW_X, RIGHT_ARROW_Y, 0);
    sMenuDataPtr->spriteIDs[SpriteTag] = spriteId;

    gSprites[sMenuDataPtr->spriteIDs[SpriteTag]].oam.shape = SPRITE_SHAPE(8x16);
    gSprites[sMenuDataPtr->spriteIDs[SpriteTag]].oam.size = SPRITE_SIZE(8x16);
    gSprites[sMenuDataPtr->spriteIDs[SpriteTag]].oam.priority = 1;
}

// -------------------------------------------------------------------------------------------------------
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
        CreateBuyIconSprite();
        CreateUpArrowSprite();
        CreateDownArrowSprite();
        CreateLeftArrowSprite();
        CreateRightArrowSprite();
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

static void Menu_ChangeTilemap(void)
{
    try_free(sBg1TilemapBuffer);
    sBg1TilemapBuffer == NULL;

    ResetAllBgsCoordinates();
    sBg1TilemapBuffer = Alloc(0x800);

    memset(sBg1TilemapBuffer, 0, 0x800);
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, sMenuBgTemplates, NELEMS(sMenuBgTemplates));
    SetBgTilemapBuffer(1, sBg1TilemapBuffer);
    ScheduleBgCopyTilemapToVram(1);
    ShowBg(0);
    ShowBg(1);
    ShowBg(2);

    sMenuDataPtr->buyScreen = !sMenuDataPtr->buyScreen;
    ResetTempTileDataBuffers();
    DecompressAndCopyTileDataToVram(1, sMenuTiles, 0, 0, 0);
    FreeTempTileDataBuffersIfPossible();

    if(sMenuDataPtr->buyScreen){
        DisableAllItemIcons();
        LZDecompressWram(sMenuTilemapBuy, sBg1TilemapBuffer);
    }
    else{
        EnableAllItemIcons();
        LZDecompressWram(sMenuTilemap, sBg1TilemapBuffer);
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

#define MAX_ITEM_SPRITES 16
#define FIRST_ITEM_SPRITE_ID NUM_AMAZON_SPRITES

static void CreateItemIcon(u16 itemId, u8 idx, u8 x, u8 y)
{
    u8 spriteId;
    u8 newspriteID = FIRST_ITEM_SPRITE_ID + idx;

    spriteId = AddItemIconSprite(newspriteID, newspriteID, itemId);

    sMenuDataPtr->spriteIDs[newspriteID] = spriteId;
    gSprites[spriteId].x2 = x; //24;
    gSprites[spriteId].y2 = y; //140;
}

static void DestroyAllItemIcons()
{
    u8 i;
    u8 newspriteID = 0;
    u8 oldspriteID = 0;

    for(i = 0; i < MAX_ITEM_SPRITES; i++){
        newspriteID = FIRST_ITEM_SPRITE_ID + i;
        oldspriteID = sMenuDataPtr->spriteIDs[newspriteID];

        if(sMenuDataPtr->spriteIDs[newspriteID] != 0){
            FreeSpriteTilesByTag(newspriteID);
            FreeSpritePaletteByTag(newspriteID);
            DestroySpriteAndFreeResources(&gSprites[oldspriteID]);
        }
    }
}

static void EnableAllItemIcons()
{
    u8 i;

    for(i = 0; i < MAX_ITEM_SPRITES; i++){
        gSprites[sMenuDataPtr->spriteIDs[FIRST_ITEM_SPRITE_ID + i]].invisible = FALSE;
    }
}

static void DisableAllItemIcons()
{
    u8 i;

    for(i = 0; i < MAX_ITEM_SPRITES; i++){
        gSprites[sMenuDataPtr->spriteIDs[FIRST_ITEM_SPRITE_ID + i]].invisible = TRUE;
    }
}

static void MoveCurrenItemIcon(u8 idx, u8 x, u8 y)
{
    u8 newspriteID = FIRST_ITEM_SPRITE_ID + idx;
    u8 spriteId = sMenuDataPtr->spriteIDs[newspriteID];

    gSprites[spriteId].invisible = FALSE;
    gSprites[spriteId].x2 = x; //24;
    gSprites[spriteId].y2 = y; //140;
}

// --------------------------------------------------------------------------------------------------------------------

static u8 GetCursorPosition()
{
    return sMenuDataPtr->currentRow - sMenuDataPtr->currentFirstShownRow;
}

enum PriceTypes
{
    PRICE_ITEM,
    PRICE_DRONE,
    PRICE_FINAL,
};

u8 getDroneFee(){
    u8 droneFeePercentage = 20;

    if(!FlagGet(FLAG_TIMELINE_TRUE) && GetCurrentRow() != ROW_RECOMMENDED)
        droneFeePercentage = 20;

    if(!FlagGet(FLAG_TIMELINE_TRUE) && GetCurrentRow() == ROW_RECOMMENDED)
        droneFeePercentage = 22;

    if(FlagGet(FLAG_TIMELINE_TRUE) && GetCurrentRow() != ROW_RECOMMENDED)
        droneFeePercentage = 50;

    if(FlagGet(FLAG_TIMELINE_TRUE) && GetCurrentRow() == ROW_RECOMMENDED)
        droneFeePercentage = 52;
    
    return droneFeePercentage;
}

u8 getRowItemNum(u8 row){
    u8 i, itemNum;

    itemNum = 0;

    if(sMenuDataPtr->rowsSorted){
        row = (row + 2) % NUM_ROWS;
    }
    else{
       row = row % NUM_ROWS;
    }

    for(i = 0; i < 20; i++){
        if(sMenuDataPtr->currentRowItemList[row][i] != ITEM_NONE)
            itemNum++;
    }

    return itemNum;
}

static u16 GetCurrentItemPrice(u8 quantity, u16 itemID, u8 type)
{
    u16 itemPrice = (quantity + 1)* gItems[itemID].price;
    u16 dronePrice = (itemPrice * getDroneFee()) / 100;
    u16 totalPrice = itemPrice + dronePrice;

    switch(type){
        case PRICE_ITEM:
            return itemPrice;
        break;
        case PRICE_DRONE:
            return dronePrice;
        break;
        case PRICE_FINAL:
            return totalPrice;
        break;
    }

    return 0;
}

static void PressedDownButton(){
    if(!sMenuDataPtr->buyScreen){
        do{
            u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
            u8 finalhalfScreen = NUM_ROWS - halfScreen;
            u8 cursorPosition = (sMenuDataPtr->currentRow - sMenuDataPtr->currentFirstShownRow);
            sMenuDataPtr->currentItem = 0;
            sMenuDataPtr->currentFirstShownItem = 0;

            if(sMenuDataPtr->currentRow < halfScreen){
                sMenuDataPtr->currentRow++;
            }
            else if(sMenuDataPtr->currentRow >= (NUM_ROWS - 1)){ //If you are in the last option go to the first one
                sMenuDataPtr->currentRow = 0;
                sMenuDataPtr->currentFirstShownRow = 0;
            }
            else if(sMenuDataPtr->currentRow >= (finalhalfScreen - 1)){
                sMenuDataPtr->currentRow++;
            }
            else{
                sMenuDataPtr->currentRow++;
                sMenuDataPtr->currentFirstShownRow++;
            }
        }
        while(sMenuDataPtr->currentRowItemList[GetCurrentRow()][0] == ITEM_NONE);
    }
    else{
        u16 itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
        u8 buyableItems = GetMoney(&gSaveBlock1Ptr->money) / GetCurrentItemPrice(0, itemID, PRICE_FINAL);

        if(buyableItems != 0){
            if (buyableItems > MAX_BAG_ITEM_CAPACITY)
                buyableItems = MAX_BAG_ITEM_CAPACITY - 1;

            if(sMenuDataPtr->itemQuantity != 0)
                sMenuDataPtr->itemQuantity--;
            else
                sMenuDataPtr->itemQuantity = buyableItems - 1;
        }
    }
}

static void PressedUpButton(){
    if(!sMenuDataPtr->buyScreen){
        do{
            u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
            u8 finalhalfScreen = NUM_ROWS - halfScreen;
            u8 cursorPosition = (sMenuDataPtr->currentRow - sMenuDataPtr->currentFirstShownRow);
            sMenuDataPtr->currentItem = 0;
            sMenuDataPtr->currentFirstShownItem = 0;

            if(sMenuDataPtr->currentRow > halfScreen && sMenuDataPtr->currentRow <= (finalhalfScreen - 1)){
                sMenuDataPtr->currentRow--;
                sMenuDataPtr->currentFirstShownRow--;
            }
            else if(sMenuDataPtr->currentRow == 0){ //If you are in the first option go to the last one
                sMenuDataPtr->currentRow = NUM_ROWS - 1;
                sMenuDataPtr->currentFirstShownRow = NUM_ROWS - NUM_MAX_ICONS_ROWNS_ON_SCREEN;
            }
            else{
                sMenuDataPtr->currentRow--;
            }
        }
        while(sMenuDataPtr->currentRowItemList[GetCurrentRow()][0] == ITEM_NONE);
    }
    else{
        u16 itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
        u8 buyableItems = GetMoney(&gSaveBlock1Ptr->money) / GetCurrentItemPrice(0, itemID, PRICE_FINAL);
        //mgba_printf(MGBA_LOG_WARN, "buyableItems %d", buyableItems);

        if(sMenuDataPtr->itemQuantity != MAX_BAG_ITEM_CAPACITY - 1 && buyableItems > sMenuDataPtr->itemQuantity + 1)
            sMenuDataPtr->itemQuantity++;
        else
            sMenuDataPtr->itemQuantity = 0;
    }
}

#define LEFTRIGHT_ITEM_NUMBER_CHANGE 5

static void PressedRightButton(){
    if(!sMenuDataPtr->buyScreen){
        u8 itemNum, finalhalfScreen;
        u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
        u8 cursorPosition = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);

        itemNum = getCurrentRowItemNum();
        finalhalfScreen = itemNum - halfScreen;

        if(sMenuDataPtr->currentItem < halfScreen){
            sMenuDataPtr->currentItem++;
        }
        else if(sMenuDataPtr->currentItem >= (itemNum - 1)){ //If you are in the last option go to the first one
            sMenuDataPtr->currentItem = 0;
            sMenuDataPtr->currentFirstShownItem = 0;
        }
        else if(sMenuDataPtr->currentItem >= (finalhalfScreen - 1)){
            sMenuDataPtr->currentItem++;
        }
        else{
            sMenuDataPtr->currentItem++;
            sMenuDataPtr->currentFirstShownItem++;
        }

        if(sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem] == ITEM_NONE){ //If you are in the last option go to the first one
            sMenuDataPtr->currentItem = 0;
            sMenuDataPtr->currentFirstShownItem = 0;
        }
    }
    else{
        u16 itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
        u8 buyableItems = GetMoney(&gSaveBlock1Ptr->money) / GetCurrentItemPrice(0, itemID, PRICE_FINAL);
        //mgba_printf(MGBA_LOG_WARN, "buyableItems %d", buyableItems);

        if(sMenuDataPtr->itemQuantity != MAX_BAG_ITEM_CAPACITY - 1 && buyableItems > (sMenuDataPtr->itemQuantity + LEFTRIGHT_ITEM_NUMBER_CHANGE))
            sMenuDataPtr->itemQuantity = sMenuDataPtr->itemQuantity + LEFTRIGHT_ITEM_NUMBER_CHANGE;
        else if(sMenuDataPtr->itemQuantity != buyableItems)
            sMenuDataPtr->itemQuantity = buyableItems;
        else
            sMenuDataPtr->itemQuantity = 0;
    }
}

static void PressedLeftButton(){
    if(!sMenuDataPtr->buyScreen){
        u8 itemNum, finalhalfScreen;
        u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
        u8 cursorPosition = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);

        itemNum = getCurrentRowItemNum();
        finalhalfScreen = itemNum - halfScreen;

        if(sMenuDataPtr->currentItem > halfScreen && sMenuDataPtr->currentItem <= (finalhalfScreen - 1)){
            sMenuDataPtr->currentItem--;
            sMenuDataPtr->currentFirstShownItem--;
        }
        else if(sMenuDataPtr->currentItem == 0){ //If you are in the first option go to the last one
            sMenuDataPtr->currentItem = itemNum - 1;
            if(itemNum > NUM_MAX_ICONS_ROWNS_ON_SCREEN)
                sMenuDataPtr->currentFirstShownItem = itemNum - NUM_MAX_ICONS_ROWNS_ON_SCREEN;
        }
        else{
            sMenuDataPtr->currentItem--;
        }
    }
    else{
        u16 itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
        u8 buyableItems = GetMoney(&gSaveBlock1Ptr->money) / GetCurrentItemPrice(0, itemID, PRICE_FINAL);

        if(buyableItems != 0){
            if (buyableItems > MAX_BAG_ITEM_CAPACITY)
                buyableItems = MAX_BAG_ITEM_CAPACITY - 1;

            if(sMenuDataPtr->itemQuantity >= LEFTRIGHT_ITEM_NUMBER_CHANGE)
                sMenuDataPtr->itemQuantity = sMenuDataPtr->itemQuantity - LEFTRIGHT_ITEM_NUMBER_CHANGE;
            else if(sMenuDataPtr->itemQuantity != 0)
                sMenuDataPtr->itemQuantity = 0;
            else
                sMenuDataPtr->itemQuantity = buyableItems - 1;
        }
    }
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
    u8 itemNum[NUM_ROWS];
    
    for (badgeFlag = FLAG_BADGE01_GET; badgeFlag < FLAG_BADGE01_GET + NUM_BADGES; badgeFlag++){
        if(FlagGet(badgeFlag))
            numbadges++;
    }

    for(i = 0; i < NUM_ROWS; i++){
        for(j = 0; j < NUM_MAX_ITEMS_PER_ROW; j++)
            sMenuDataPtr->currentRowItemList[i][j] = ITEM_NONE;

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

                if(gItems[Amazon_Items[i][j].item].price == 0)
                    canBuy = FALSE;

                if(i == ROW_TMS && CheckBagHasItem(Amazon_Items[i][j].item, 1))//Removes TMs that you already have
                    canBuy = FALSE;

                if(canBuy){
                    sMenuDataPtr->currentRowItemList[i][itemNum[i]] = Amazon_Items[i][j].item;
                    //currentRowItemList[i][itemNum[i]] = Amazon_Items[i][j].item;
                    itemNum[i]++;
                }
            }
            else if(i == ROW_BUY_AGAIN && j < MAX_AMAZON_BUY_AGAIN_ITEMS){
                if(gSaveBlock2Ptr->amazonBuyAgainItem[j] == ITEM_NONE)
                    gSaveBlock2Ptr->amazonBuyAgainItem[j] = ITEM_ORAN_BERRY+ j;

                sMenuDataPtr->currentRowItemList[i][itemNum[i]] = gSaveBlock2Ptr->amazonBuyAgainItem[j];
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

static const u8 sRowSelector[]         = INCBIN_U8("graphics/ui_menus/amazon/row_selector.4bpp");
static const u8 sOrderWindow[]         = INCBIN_U8("graphics/ui_menus/amazon/orderwindow.4bpp");
static const u8 sItemSelector[]        = INCBIN_U8("graphics/ui_menus/amazon/item_selector.4bpp");

static const u8 sText_Help_Bar[]        = _("{DPAD_UPDOWN} Rows {DPAD_LEFTRIGHT} Items {A_BUTTON} Buy {B_BUTTON} Exit {START_BUTTON} Sort Rows");
static const u8 sText_Help_Bar_Buy[]    = _("{DPAD_UPDOWN} +1/-1 {DPAD_LEFTRIGHT} +5/-5 {A_BUTTON} Buy Now {B_BUTTON} Cancel");
static const u8 sText_Money_Bar[]       = _("Money: ¥{STR_VAR_1}");
static const u8 sText_Price[]           = _("Price: ¥{STR_VAR_1}");
static const u8 sText_FirstRowName[]    = _("{STR_VAR_1}: {STR_VAR_2}");
static const u8 sText_ItemNameOwned[]   = _("{STR_VAR_1} - {STR_VAR_2} Owned");
static const u8 sText_ItemCost[]        = _("Item Cost:    ¥ {STR_VAR_1}");
static const u8 sText_DroneFee[]        = _("Drone Fee:    ¥ {STR_VAR_1}");
//static const u8 sText_DroneFee[]      = _("Drone Fee:    ¥ {STR_VAR_1} ({STR_VAR_2}%)");
static const u8 sText_OrderTotal[]      = _("Order Total: ¥ {STR_VAR_1}");
static const u8 sText_ItemPrice[]       = _("¥ {STR_VAR_1}");
static const u8 sText_DeliveryTo[]      = _("Delivery to {STR_VAR_1} ({STR_VAR_2})");


static const u8 sText_OrderDelivered[]       = _("Order Delivered!");
static const u8 sText_ThanksForBuying[]      = _("Thanks you for using Amazon");
static const u8 sText_ItemNumber[]           = _("You got {STR_VAR_1} x{STR_VAR_2}");


static const u8 sText_noEnoughMoney[]        = _("You don't have enough money for this!");

#define MAX_MONEY 999999

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str = sText_Help_Bar;
    u8 i, j, x2, y2;
    u8 x = 1;
    u8 y = 1;
    u16 quantity;
    u16 itemID;
    u8 droneFeePercentage;
    u8 strArray[16];
    u8 itemNum = getCurrentRowItemNum();
    u8 temp;

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    if(!sMenuDataPtr->buyScreen){
        // Row Icons
        x = 1;
        y = 2;
        x2 = 0;
        y2 = 4;

        for(i = 0; i < NUM_MAX_ICONS_ROWNS_ON_SCREEN; i++ ){
            if(sMenuDataPtr->currentRow % NUM_ROWS == sMenuDataPtr->currentFirstShownRow + i)
                BlitBitmapToWindow(windowId, sRowSelector, ((x-1)*8) + x2, ((y-1)*8) + y2 + 4, 32, 24);

            if(sMenuDataPtr->rowsSorted)
                droneFeePercentage = 2;
            else
                droneFeePercentage = 0;

            switch((sMenuDataPtr->currentFirstShownRow + i + droneFeePercentage) % NUM_ROWS){
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

        //Item Selector
        x = (5 * (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem)) + 4;
        y = 4;
        x2 = (2 * (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem)) + 2;
        BlitBitmapToWindow(windowId, sItemSelector, (x*8) + x2, (y*8), 32, 24);

        // Item Icon
        x = 6;
        y = 5;
        x2 = 6;
        y2 = 6;
        temp = 0;
        DestroyAllItemIcons();

        for(i = 0; i < NUM_MAX_ROWNS_ON_SCREEN; i++ ){
            for(j = 0; j < NUM_MAX_ICONS_ROWNS_ON_SCREEN; j++ ){
                if(i == 0)
                    itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow() + i) % NUM_ROWS][(sMenuDataPtr->currentFirstShownItem + j)];
                else
                    itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow() + i) % NUM_ROWS][j];
                
                CreateItemIcon(itemID, temp, (x * 8) + x2, (y * 8) + y2);
                
                x = x + 5;
                x2 = x2 + 2;
                temp++;
            }
            x = 6;
            x2 = 6;
            y = y + 5;
            y2 = y2 + 4;
        }

        // Row Names
        x = 4;

        for(i = 0; i < NUM_MAX_ROWNS_ON_SCREEN; i++ ){
            if(i == 0 && sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem] != ITEM_NONE){
                str = Amazon_Rows[GetCurrentRow()].title;
                StringCopy(gStringVar1, str);
                str = gItems[sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem]].name;
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

        // Item Price --------------------------------------------------------------------------------------------------------------------
        x = 20;
        y = 2;
        quantity = GetCurrentItemPrice(sMenuDataPtr->itemQuantity, sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem], PRICE_ITEM);
	    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 5);
        StringExpandPlaceholders(gStringVar4, sText_Price);

        if(sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem] != ITEM_NONE)
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

        // Help Bar --------------------------------------------------------------------------------------------------------------------
        x = 0;
        y = 18;

        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar);
    }
    else{
        //Item Icon --------------------------------------------------------------------------------------------------------------------
        x = 3;
        y = 6;
        x2 = 0;
        y2 = 0;
        itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
        MoveCurrenItemIcon(sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem, (x * 8) + x2, (y * 8) + y2);

        //Item Name --------------------------------------------------------------------------------------------------------------------
        x = 1;
        y = 2;
        x2 = 0;
        y2 = 0;

        str = gItems[itemID].name;
        quantity = CountTotalItemQuantityInBag(itemID);
        StringCopy(gStringVar1, str);
	    ConvertIntToDecimalStringN(gStringVar2, quantity, STR_CONV_MODE_LEFT_ALIGN, 4);
        StringExpandPlaceholders(gStringVar4, sText_ItemNameOwned);

        AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
            
        //Item Price --------------------------------------------------------------------------------------------------------------------
        x = 25;
        y = 2;
        x2 = 0;
        y2 = 0;

	    ConvertIntToDecimalStringN(gStringVar1, gItems[itemID].price, STR_CONV_MODE_LEFT_ALIGN, 5);
	    //ConvertIntToDecimalStringN(gStringVar1, MAX_MONEY, STR_CONV_MODE_LEFT_ALIGN, 5);
        StringExpandPlaceholders(gStringVar4, sText_ItemPrice);

        AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);
              
        //Item Description --------------------------------------------------------------------------------------------------------------------
        x = 5;
        y = 4;
        x2 = 0;
        y2 = 0;
        str = gItems[itemID].description;
        AddTextPrinterParameterized4(windowId, 5, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, str); 

        //Item Cost --------------------------------------------------------------------------------------------------------------------
        x = 16;
        y = 10;
        x2 = 0;
        y2 = 0;

        quantity = GetCurrentItemPrice(sMenuDataPtr->itemQuantity, itemID, PRICE_ITEM);
	    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 5);
        StringExpandPlaceholders(gStringVar4, sText_ItemCost);

        AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);

        //Drone Fee --------------------------------------------------------------------------------------------------------------------
        x = 16;
        y = 12;
        x2 = 0;
        y2 = 0;

        quantity = GetCurrentItemPrice(sMenuDataPtr->itemQuantity, itemID, PRICE_DRONE);
	    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 5);
	    ConvertIntToDecimalStringN(gStringVar2, getDroneFee(), STR_CONV_MODE_LEFT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, sText_DroneFee);

        AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);

        //Order Total --------------------------------------------------------------------------------------------------------------------
        x = 16;
        y = 14;
        x2 = 0;
        y2 = 0;

        quantity = GetCurrentItemPrice(sMenuDataPtr->itemQuantity, itemID, PRICE_FINAL);
	    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 5);
        StringExpandPlaceholders(gStringVar4, sText_OrderTotal);

        AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);

        //Item Quantity --------------------------------------------------------------------------------------------------------------------
        x = 12;
        y = 12;
        x2 = 4;
        y2 = 0;

        quantity = sMenuDataPtr->itemQuantity + 1;
	    ConvertIntToDecimalStringN(gStringVar1, quantity, STR_CONV_MODE_LEFT_ALIGN, 5);

        AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

        //Delivery to
        x = 1;
        y = 16;

        GetMapNameGeneric(gStringVar1, gMapHeader.regionMapSectionId);

        StringCopy(&strArray[0], gSaveBlock2Ptr->playerName);
        str = strArray;
        StringCopy(gStringVar2, str);
        StringExpandPlaceholders(gStringVar4, sText_DeliveryTo);

        //AddTextPrinterParameterized4(windowId, 8, (x*8) + x2, (y*8) + y2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);  

        // Help Bar --------------------------------------------------------------------------------------------------------------------
        x = 0;
        y = 18;

        if(!sMenuDataPtr->notEnoughMoneyWindow)
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar_Buy);  
        else
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_noEnoughMoney);  
    
        // Order Delivered --------------------------------------------------------------------------------------------------------------------
        if(sMenuDataPtr->buyWindow){
            if(!sMenuDataPtr->notEnoughMoneyWindow){
                x = 5;
                y = 5;

                BlitBitmapToWindow(windowId, sOrderWindow, (x*8), (y*8), 152, 72);

                x = 5;
                y = 5;
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 0, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_OrderDelivered);  
                
                x = 6;
                y = 8;
                AddTextPrinterParameterized4(windowId, 8, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, sText_ThanksForBuying); 

                
                x = 6;
                y = 10;
                str = gItems[itemID].name;
                StringCopy(gStringVar1, str); 
                ConvertIntToDecimalStringN(gStringVar2, quantity, STR_CONV_MODE_LEFT_ALIGN, 2);  
                StringExpandPlaceholders(gStringVar4, sText_ItemNumber);
                AddTextPrinterParameterized4(windowId, 8, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);
            }
        }
    }

    // Money --------------------------------------------------------------------------------------------------------------------
    x = 20;
    y = 0;
    //AddMoney(&gSaveBlock1Ptr->money, MAX_MONEY);
    ConvertIntToDecimalStringN(gStringVar1, GetMoney(&gSaveBlock1Ptr->money), STR_CONV_MODE_RIGHT_ALIGN, 6);
    StringExpandPlaceholders(gStringVar4, sText_Money_Bar);

    AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);

    sMenuDataPtr->notEnoughMoneyWindow = FALSE;
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
        Menu_FreeResources();
        Amazon_Init(CB2_ReturnToUIMenu);
        gMain.savedCallback = CB2_ReturnToUIMenu;
        DestroyTask(taskId);
    }
}

static void buynewItem(u16 itemId, u8 quantity){
    u16 price = GetCurrentItemPrice(quantity, itemId, PRICE_FINAL);
    u8 i;
    bool8 newItem = TRUE;
    u8 oldItem;

    RemoveMoney(&gSaveBlock1Ptr->money, price);
    AddBagItem(itemId, quantity + 1);

    sMenuDataPtr->buyWindow = TRUE;

    if(GetCurrentRow() != ROW_TMS){
        for(i = 0; i < MAX_AMAZON_BUY_AGAIN_ITEMS; i++){
            if(itemId == gSaveBlock2Ptr->amazonBuyAgainItem[i]){
                newItem = FALSE;
                oldItem = i;
            }
        }

        if(newItem){
            for(i = 0; i < MAX_AMAZON_BUY_AGAIN_ITEMS - 1; i++){
                gSaveBlock2Ptr->amazonBuyAgainItem[(MAX_AMAZON_BUY_AGAIN_ITEMS - i) - 1] = gSaveBlock2Ptr->amazonBuyAgainItem[(MAX_AMAZON_BUY_AGAIN_ITEMS - i) - 2];
            }
        }
        else{
            gSaveBlock2Ptr->amazonBuyAgainItem[oldItem] = ITEM_NONE;

            for(i = 0; i < oldItem; i++){
                gSaveBlock2Ptr->amazonBuyAgainItem[oldItem - i] = gSaveBlock2Ptr->amazonBuyAgainItem[oldItem - i -1];
            }
        }
        gSaveBlock2Ptr->amazonBuyAgainItem[0] = itemId;

        for(i = 0; i < MAX_AMAZON_BUY_AGAIN_ITEMS; i++)
            sMenuDataPtr->currentRowItemList[ROW_BUY_AGAIN][i] = gSaveBlock2Ptr->amazonBuyAgainItem[i];
            
        if(GetCurrentRow() == ROW_BUY_AGAIN)
            sMenuDataPtr->currentItem = 0;
    }
       
    PrintToWindow(WINDOW_1, FONT_BLACK);
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if (JOY_NEW(B_BUTTON))
    {
        if(!sMenuDataPtr->buyWindow){
            if(sMenuDataPtr->buyScreen){
                sMenuDataPtr->itemQuantity = 0;
                PlaySE(SE_SELECT);
                Menu_ChangeTilemap();
                PrintToWindow(WINDOW_1, FONT_BLACK);
            }
            else{
                PlaySE(SE_PC_OFF);
                BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                gTasks[taskId].func = Task_MenuTurnOff;
            }
        }
        else{
            sMenuDataPtr->itemQuantity = 0;
            sMenuDataPtr->buyWindow = FALSE;
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
    }

    if (JOY_NEW(A_BUTTON))
    {
        if(!sMenuDataPtr->buyScreen){
            PlaySE(SE_SELECT);
            Menu_ChangeTilemap();
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
        else{
            if(sMenuDataPtr->buyWindow){
                sMenuDataPtr->itemQuantity = 0;
                sMenuDataPtr->buyWindow = FALSE;
                PrintToWindow(WINDOW_1, FONT_BLACK);
            }
            else{
                if(GetMoney(&gSaveBlock1Ptr->money) >= GetCurrentItemPrice(sMenuDataPtr->itemQuantity, sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem], PRICE_FINAL)){
                    buynewItem(sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem], sMenuDataPtr->itemQuantity);
                    PlaySE(SE_SHOP);
                }
                else{
                    sMenuDataPtr->notEnoughMoneyWindow = TRUE;
                    PlaySE(SE_FAILURE);
                }
                //Menu_ChangeTilemap();
                PrintToWindow(WINDOW_1, FONT_BLACK);
            }
        }
    }

    //
    if(JOY_NEW(START_BUTTON) && !sMenuDataPtr->buyWindow)
	{
        if(!sMenuDataPtr->buyScreen){
            sMenuDataPtr->rowsSorted = !sMenuDataPtr->rowsSorted;
            PlaySE(SE_SELECT);

            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
	}

    if(JOY_NEW(DPAD_UP) && !sMenuDataPtr->buyWindow)
	{
        PressedUpButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_DOWN) && !sMenuDataPtr->buyWindow)
	{
        PressedDownButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_RIGHT) && !sMenuDataPtr->buyWindow)
	{
        PressedRightButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_LEFT) && !sMenuDataPtr->buyWindow)
	{
        PressedLeftButton();
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

}