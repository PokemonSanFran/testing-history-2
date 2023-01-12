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
#include "region_map.h"
#include "random.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "trig.h"
#include "overworld.h"
#include "quests.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/items.h"
#include "constants/party_menu.h"
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
#define NUM_MAX_ITEMS_PER_ROW 150

struct AmazonMenuResources {
	MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
	u16 currentRow:4;                //Max 12
	u16 currentFirstShownRow:4;      //Max 9
	u16 currentItem:8;               //Max 255
	u16 currentFirstShownItem:8;     //Max 255
	u16 itemQuantity:7;              //Max 99
	u16 notEnoughMoneyWindow:1;      //bool8
	u16 rowsSorted:1;                //bool8
	u16 buyScreen:1;                 //bool8
	u16 buyWindow:1;                 //bool8
	u16 filler:5;                    //Filler
	u16 currentRowItemList[NUM_ROWS][NUM_MAX_ITEMS_PER_ROW];
	u16 itemNum[NUM_ROWS];
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
static void RecommendedInitializeArrayList(void);
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
    RecommendedInitializeArrayList();

    if(gSaveBlock2Ptr->amazonBuyAgainItem[0] == ITEM_NONE && 
      !sMenuDataPtr->rowsSorted){
        if(gSaveBlock2Ptr->amazonBuyAgainItem[ROW_RECOMMENDED] != ITEM_NONE)
            sMenuDataPtr->currentRow = ROW_RECOMMENDED;
        else
            sMenuDataPtr->currentRow = ROW_MEDICINE;
    }
    
    //mgba_printf(MGBA_LOG_WARN, "The Amazon EWRAM is using %d bytes out of 32770", size);

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
    return sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS];
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
    u8 val = sprite->data[0];
    u8 num = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);
    u8 x = (5 * num);

    sprite->x = RIGHT_ARROW_X + (x * 8) + (2 * num);
    sprite->x2 = gSineTable[val] / 128;
    sprite->data[0] += 8;

    if(sMenuDataPtr->buyScreen || sMenuDataPtr->currentItem == sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] - 1)
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
    u8 i;

    if(sMenuDataPtr->rowsSorted){
        row = (row + 2) % NUM_ROWS;
    }
    else{
       row = row % NUM_ROWS;
    }

    return sMenuDataPtr->itemNum[row];
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
        if(GetCurrentRow() != ROW_TMS && GetCurrentRow() != ROW_Z_CRYSTALS && GetCurrentRow() != ROW_MEGA_STONES){
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
        if(GetCurrentRow() != ROW_TMS && GetCurrentRow() != ROW_Z_CRYSTALS && GetCurrentRow() != ROW_MEGA_STONES){
            u16 itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
            u8 buyableItems = GetMoney(&gSaveBlock1Ptr->money) / GetCurrentItemPrice(0, itemID, PRICE_FINAL);

            if(sMenuDataPtr->itemQuantity != MAX_BAG_ITEM_CAPACITY - 1 && buyableItems > sMenuDataPtr->itemQuantity + 1)
                sMenuDataPtr->itemQuantity++;
            else
                sMenuDataPtr->itemQuantity = 0;
        }
    }
}

#define LEFTRIGHT_ITEM_NUMBER_CHANGE 5

static void PressedRightButton(){
    if(!sMenuDataPtr->buyScreen){
        u8 finalhalfScreen;
        u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
        u8 cursorPosition = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);

        finalhalfScreen = sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] - halfScreen;

        if(sMenuDataPtr->currentItem < halfScreen){
            sMenuDataPtr->currentItem++;
        }
        else if(sMenuDataPtr->currentItem >= (sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] - 1)){ //If you are in the last option go to the first one
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
        if(GetCurrentRow() != ROW_TMS && GetCurrentRow() != ROW_Z_CRYSTALS && GetCurrentRow() != ROW_MEGA_STONES){
            u16 itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][sMenuDataPtr->currentItem];
            u8 buyableItems = GetMoney(&gSaveBlock1Ptr->money) / GetCurrentItemPrice(0, itemID, PRICE_FINAL);

            if(sMenuDataPtr->itemQuantity != MAX_BAG_ITEM_CAPACITY - 1 && buyableItems > (sMenuDataPtr->itemQuantity + LEFTRIGHT_ITEM_NUMBER_CHANGE))
                sMenuDataPtr->itemQuantity = sMenuDataPtr->itemQuantity + LEFTRIGHT_ITEM_NUMBER_CHANGE;
            else if(sMenuDataPtr->itemQuantity != buyableItems)
                sMenuDataPtr->itemQuantity = buyableItems;
            else
                sMenuDataPtr->itemQuantity = 0;
        }
    }
}

static void PressedLeftButton(){
    if(!sMenuDataPtr->buyScreen){
        u8 finalhalfScreen;
        u8 halfScreen = ((NUM_MAX_ICONS_ROWNS_ON_SCREEN) - 1) / 2;
        u8 cursorPosition = (sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem);

        finalhalfScreen = sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] - halfScreen;

        if(sMenuDataPtr->currentItem > halfScreen && sMenuDataPtr->currentItem <= (finalhalfScreen - 1)){
            sMenuDataPtr->currentItem--;
            sMenuDataPtr->currentFirstShownItem--;
        }
        else if(sMenuDataPtr->currentItem == 0){ //If you are in the first option go to the last one
            sMenuDataPtr->currentItem = sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] - 1;
            if(sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] > NUM_MAX_ICONS_ROWNS_ON_SCREEN)
                sMenuDataPtr->currentFirstShownItem = sMenuDataPtr->itemNum[(GetCurrentRow()) % NUM_ROWS] - NUM_MAX_ICONS_ROWNS_ON_SCREEN;
        }
        else{
            sMenuDataPtr->currentItem--;
        }
    }
    else{
        if(GetCurrentRow() != ROW_TMS && GetCurrentRow() != ROW_Z_CRYSTALS && GetCurrentRow() != ROW_MEGA_STONES){
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
}

#define ROW_NAME_LENGTH 20
#define FLAG_NONE 0
#define VAR_NONE 0
#define QUEST_NONE 0

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
    u16 reqQuest;
};

struct AmazonItemData Amazon_Items[NUM_ROWS][NUM_MAX_ITEMS_PER_ROW] = {
    [ROW_RECOMMENDED] =
    {
        {
            .item = ITEM_NONE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
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
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SUPER_POTION,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HYPER_POTION,
            .numBadges = 5,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAX_POTION,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FULL_RESTORE,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_REVIVE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAX_REVIVE,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ENERGY_POWDER,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ENERGY_ROOT,
            .numBadges = 5,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_REVIVAL_HERB,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ANTIDOTE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PARALYZE_HEAL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BURN_HEAL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ICE_HEAL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_AWAKENING,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FULL_HEAL,
            .numBadges = 5,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ETHER,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAX_ETHER,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ELIXIR,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAX_ELIXIR,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
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
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GREAT_BALL,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ULTRA_BALL,
            .numBadges = 5,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HEAL_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_REPEAT_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LUXURY_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LEVEL_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
        },
        {
            .item = ITEM_LURE_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
        },
        {
            .item = ITEM_MOON_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
        },
        {
            .item = ITEM_FRIEND_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
        },
        {
            .item = ITEM_LOVE_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
        },
        {
            .item = ITEM_FAST_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
        },
        {
            .item = ITEM_HEAVY_BALL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_ARTISANBALLS3,
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
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SUPER_REPEL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
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
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SUPER_LURE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAX_LURE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
    },
    [ROW_POWER_UPS] =
    {
        {
            .item = ITEM_HP_UP,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PROTEIN,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_IRON,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CALCIUM,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ZINC,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CARBOS,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PP_UP,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PP_MAX,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HEALTH_FEATHER,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MUSCLE_FEATHER,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RESIST_FEATHER,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GENIUS_FEATHER,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CLEVER_FEATHER,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SWIFT_FEATHER,
            .numBadges = 2,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ABILITY_CAPSULE,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ABILITY_PATCH,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LONELY_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ADAMANT_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_NAUGHTY_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BRAVE_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BOLD_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_IMPISH_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LAX_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RELAXED_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MODEST_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MILD_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RASH_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_QUIET_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CALM_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GENTLE_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CAREFUL_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SASSY_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_TIMID_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HASTY_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_JOLLY_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_NAIVE_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SERIOUS_MINT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FIRE_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WATER_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_THUNDER_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LEAF_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ICE_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SUN_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MOON_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SHINY_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DUSK_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DAWN_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SWEET_APPLE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_TART_APPLE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CRACKED_POT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHIPPED_POT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GALARICA_CUFF,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GALARICA_WREATH,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DRAGON_SCALE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_UPGRADE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PROTECTOR,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ELECTIRIZER,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAGMARIZER,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DUBIOUS_DISC,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_REAPER_CLOTH,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PRISM_SCALE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WHIPPED_DREAM,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SACHET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_OVAL_STONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_STRAWBERRY_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LOVE_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BERRY_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CLOVER_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FLOWER_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_STAR_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RIBBON_SWEET,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EVERSTONE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RED_NECTAR,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_YELLOW_NECTAR,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PINK_NECTAR,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PURPLE_NECTAR,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FLAME_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SPLASH_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ZAP_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MEADOW_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ICICLE_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FIST_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_TOXIC_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EARTH_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SKY_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MIND_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_INSECT_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_STONE_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SPOOKY_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DRACO_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DREAD_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_IRON_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PIXIE_PLATE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DOUSE_DRIVE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SHOCK_DRIVE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BURN_DRIVE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHILL_DRIVE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FIRE_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WATER_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ELECTRIC_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GRASS_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ICE_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FIGHTING_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POISON_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GROUND_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FLYING_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PSYCHIC_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BUG_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ROCK_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ROCK_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GHOST_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DRAGON_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DARK_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_STEEL_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FAIRY_MEMORY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RUSTED_SWORD,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RUSTED_SHIELD,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RED_ORB,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BLUE_ORB,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
    },
    [ROW_BATTLE_ITEMS] =
    {
        {
            .item = ITEM_X_ATTACK,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_X_DEFENSE,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_X_SP_ATK,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_X_SP_DEF,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_X_SPEED,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DIRE_HIT,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GUARD_SPEC,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POKE_DOLL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FLUFFY_TAIL,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POKE_TOY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MACHO_BRACE,
            .numBadges = 5,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_WEIGHT,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_BRACER,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_BELT,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_LENS,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_BAND,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_ANKLET,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHOICE_BAND,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHOICE_SPECS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHOICE_SCARF,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FLAME_ORB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_TOXIC_ORB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DAMP_ROCK,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HEAT_ROCK,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SMOOTH_ROCK,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ICY_ROCK,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ELECTRIC_SEED,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PSYCHIC_SEED,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MISTY_SEED,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GRASSY_SEED,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ABSORB_BULB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CELL_BATTERY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LUMINOUS_MOSS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SNOWBALL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BRIGHT_POWDER,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WHITE_HERB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EXP_SHARE,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_QUICK_CLAW,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SOOTHE_BELL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MENTAL_HERB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_KINGS_ROCK,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_AMULET_COIN,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CLEANSE_TAG,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SMOKE_BALL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FOCUS_BAND,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LUCKY_EGG,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SCOPE_LENS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LEFTOVERS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SHELL_BELL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WIDE_LENS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MUSCLE_BAND,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WISE_GLASSES,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EXPERT_BELT,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LIGHT_CLAY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LIFE_ORB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_POWER_HERB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FOCUS_SASH,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ZOOM_LENS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_METRONOME,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_IRON_BALL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LAGGING_TAIL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_DESTINY_KNOT,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BLACK_SLUDGE,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GRIP_CLAW,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_STICKY_BARB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SHED_SHELL,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BIG_ROOT,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RAZOR_CLAW,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RAZOR_FANG,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EVIOLITE,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FLOAT_STONE,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ROCKY_HELMET,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_AIR_BALLOON,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RED_CARD,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RING_TARGET,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BINDING_BAND,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EJECT_BUTTON,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WEAKNESS_POLICY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ASSAULT_VEST,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SAFETY_GOGGLES,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ADRENALINE_ORB,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_TERRAIN_EXTENDER,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PROTECTIVE_PADS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_THROAT_SPRAY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_EJECT_PACK,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HEAVY_DUTY_BOOTS,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BLUNDER_POLICY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ROOM_SERVICE,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_UTILITY_UMBRELLA,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
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
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHESTO_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PECHA_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RAWST_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ASPEAR_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LEPPA_BERRY,
            .numBadges = 3,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ORAN_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PERSIM_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LUM_BERRY,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SITRUS_BERRY,
            .numBadges = 4,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_FIGY_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WIKI_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MAGO_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_AGUAV_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_IAPAPA_BERRY,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHILAN_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_OCCA_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PASSHO_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_WACAN_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_RINDO_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_YACHE_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHOPLE_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_KEBIA_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SHUCA_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_COBA_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PAYAPA_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_TANGA_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CHARTI_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_KASIB_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_HABAN_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_COLBUR_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_BABIRI_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ROSELI_BERRY,
            .numBadges = 6,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LIECHI_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_GANLON_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_SALAC_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_PETAYA_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_APICOT_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_LANSAT_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_STARF_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ENIGMA_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MICLE_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_CUSTAP_BERRY,
            .numBadges = 8,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_JABOCA_BERRY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_ROWAP_BERRY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_KEE_BERRY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
        {
            .item = ITEM_MARANGA_BERRY,
            .numBadges = 7,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
    },
    [ROW_TMS] =
    {
        {
            .item = ITEM_NONE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
    },
    [ROW_TREASURES] =
    {
        {
            .item = ITEM_NONE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
    },
    [ROW_MEGA_STONES] =
    {
        {
            .item = ITEM_NONE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
        },
    },
    [ROW_Z_CRYSTALS] =
    {
        {
            .item = ITEM_NONE,
            .numBadges = 0,
            .reqFlag = FLAG_NONE,
            .reqVar = VAR_NONE,
            .reqVarState = 0,
            .reqQuest = QUEST_NONE,
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
        if(FlagGet(badgeFlag))
            numbadges++;
    }

    for(i = 0; i < NUM_ROWS; i++){
        for(j = 0; j < NUM_MAX_ITEMS_PER_ROW; j++)
            sMenuDataPtr->currentRowItemList[i][j] = ITEM_NONE;

        sMenuDataPtr->itemNum[i] = 0;
        for(j = 0; j < NUM_MAX_ITEMS_PER_ROW; j++){
            if(Amazon_Items[i][j].item != ITEM_NONE && i != ROW_BUY_AGAIN){
                canBuy = TRUE;

                if(VarGet(Amazon_Items[i][j].reqVar) < Amazon_Items[i][j].reqVarState && Amazon_Items[i][j].reqVar != VAR_NONE)
                    canBuy = FALSE;

                if(!FlagGet(Amazon_Items[i][j].reqFlag) && Amazon_Items[i][j].reqFlag != FLAG_NONE)
                    canBuy = FALSE;

                if(numbadges < Amazon_Items[i][j].numBadges && Amazon_Items[i][j].numBadges != 0)
                    canBuy = FALSE;

                if(!QuestMenu_GetSetQuestState(Amazon_Items[i][j].reqQuest, FLAG_GET_COMPLETED) && Amazon_Items[i][j].reqQuest != QUEST_NONE)
                    canBuy = FALSE;

                if(gItems[Amazon_Items[i][j].item].price == 0)
                    canBuy = FALSE;

                if((i == ROW_TMS || i == ROW_Z_CRYSTALS || i == ROW_MEGA_STONES) && 
                    CheckBagHasItem(Amazon_Items[i][j].item, 1))//Removes TMs/Mega Stones/Z Crystals that you already have
                    canBuy = FALSE;

                if(canBuy){
                    sMenuDataPtr->currentRowItemList[i][sMenuDataPtr->itemNum[i]] = Amazon_Items[i][j].item;
                    //currentRowItemList[i][itemNum[i]] = Amazon_Items[i][j].item;
                    sMenuDataPtr->itemNum[i]++;
                }
            }
            else if(i == ROW_BUY_AGAIN && j < MAX_AMAZON_BUY_AGAIN_ITEMS && gSaveBlock2Ptr->amazonBuyAgainItem[j] != ITEM_NONE){
                sMenuDataPtr->currentRowItemList[i][sMenuDataPtr->itemNum[i]] = gSaveBlock2Ptr->amazonBuyAgainItem[j];
                sMenuDataPtr->itemNum[i]++;
            }
        }
    }
}

enum CarouselTypes
{
    CAROUSEL_NEED_TO_HEAL,
    CAROUSEL_TOURNAMENT_PREP,
    CAROUSEL_FOREST_EXPLORE,
    CAROUSEL_CAVE_EXPLORE,
    CAROUSEL_WATER_EXPLORE,
    CAROUSEL_ROUTE_EXPLORE,
    CAROUSEL_RANDOM,
    NUM_CAROUSELS,
};

#define NUM_RECOMMENDED_ITEMS 5

u8 getCarouselType(){
    u8 i;
    u16 currentHP = 0;
    u16 maxHP = 0;
    u16 partyHP;
    u8 partyStatus = 0;
    u8 PartySize = 0;
    u16 temp;
    struct Pokemon *pokemon = gPlayerParty;

    if(VarGet(VAR_STORYLINE_STATE) > STORY_COMPLETED_NAVAL_BASE && VarGet(VAR_STORYLINE_STATE) < STORY_EXPLORE_TREASUREISLAND)
        return CAROUSEL_TOURNAMENT_PREP;

    //Calculate the number of Pokemon in your party
    for (i = 0; i < PARTY_SIZE; i++, i++)
    {
        temp = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES);
        if (temp != SPECIES_NONE)
        {
            PartySize++;
        }
    }

    //Calculate the Max HP and Current HP of your party
    for (i = 0; i < PartySize; i++, i++)
    {
        currentHP += GetMonData(&gPlayerParty[i], MON_DATA_HP);
        maxHP += GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
    }

    //Calculate the Ailment of your party
    for (i = 0; i < PartySize; i++, i++)
    {
        temp = GetMonAilment(&gPlayerParty[i]);
        if(temp != AILMENT_NONE && temp != AILMENT_PKRS)
            partyStatus++;
    }

    partyStatus = 100 - ((partyStatus / PartySize) * 100);

    partyHP = (currentHP / maxHP) * 100;

    if(partyHP < 26 || partyStatus < 33)
        return CAROUSEL_NEED_TO_HEAL;

    if((gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE5) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE5)) || 
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE61) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE61)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(GLDNGTEPARK) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(GLDNGTEPARK)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(MARIN) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(MARIN)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE7) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE7)))
        return CAROUSEL_FOREST_EXPLORE;

    //PSF TODO Uncomment relevant lines when routes are created
    /*if((gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE15) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE15)) || 
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE20) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE20)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE30) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE30)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE32) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE32)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE51) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE51)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE62) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE62)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE72) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE72)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE76) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE76)))
        return CAROUSEL_WATER_EXPLORE;*/

    if((gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE30) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE30)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE32) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE32)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE62) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE62)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE72) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE72)))
        return CAROUSEL_WATER_EXPLORE;

    if((gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE1) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE1)) || 
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE2) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE2)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE8) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE8)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE9) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE9)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE11) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE11)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE12) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE12)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE13) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE13)) || 
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE14) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE14)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE17) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE17)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE18) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE18)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE19) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE19)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE21) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE21)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE22) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE22)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE25) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE25)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE30) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE30)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE38) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE38)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE43) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE43)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE49) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE49)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE61) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE61)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE63) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE63)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(PSFROUTE70) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(PSFROUTE70)))
        return CAROUSEL_ROUTE_EXPLORE;

    if((gSaveBlock1Ptr->location.mapNum == MAP_NUM(ALCATRAZ) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(ALCATRAZ)) ||
       (gSaveBlock1Ptr->location.mapNum == MAP_NUM(GLDNGTEBRIDGE) && gSaveBlock1Ptr->location.mapGroup == MAP_GROUP(GLDNGTEBRIDGE)))
        return CAROUSEL_CAVE_EXPLORE;

    return CAROUSEL_RANDOM;
}

void RecommendedInitializeArrayList(){
    u8 i;
    u8 CarouselType = getCarouselType();
    u8 randRow, randItemNum, randRow2;
    u8 availableRows[] = {
        ROW_MEDICINE,
        ROW_POKEBALLS,
        ROW_OTHER_ITEMS,
        ROW_POWER_UPS,
        ROW_BATTLE_ITEMS,
        ROW_BERRIES,
    };

    /*u8 availableTournamentRows[] = {
        ROW_BATTLE_ITEMS,
        ROW_TMS,
    };*/
    //TMs would cause issues in the recommended row

    u8 availableFieldRows[] = {
        ROW_POKEBALLS,
        ROW_OTHER_ITEMS,
    };

    for(i = 0; i < NUM_RECOMMENDED_ITEMS; i++){
        switch(CarouselType){
            case CAROUSEL_NEED_TO_HEAL:
                do{
                    //randRow = NeedToHealRows[Random() % (sizeof(NeedToHealRows)/sizeof(NeedToHealRows[0]))];
                    randRow = ROW_MEDICINE;
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
            case CAROUSEL_TOURNAMENT_PREP:
                do{
                    //randRow = NeedToHealRows[Random() % (sizeof(NeedToHealRows)/sizeof(NeedToHealRows[0]))];
                    randRow = ROW_BATTLE_ITEMS;
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
            case CAROUSEL_FOREST_EXPLORE:
                do{
                    randRow = availableFieldRows[Random() % (sizeof(availableFieldRows)/sizeof(availableFieldRows[0]))];
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_REPEL       &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_REPEL &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_REPEL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_LURE        &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_LURE  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_LURE    &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_POKE_BALL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_GREAT_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_ULTRA_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_NET_BALL) ||
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
            case CAROUSEL_WATER_EXPLORE:
                do{
                    randRow = availableFieldRows[Random() % (sizeof(availableFieldRows)/sizeof(availableFieldRows[0]))];
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_REPEL       &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_REPEL &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_REPEL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_LURE        &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_LURE  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_LURE    &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_POKE_BALL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_GREAT_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_ULTRA_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_NET_BALL    &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_DIVE_BALL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_LURE_BALL) ||
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
            case CAROUSEL_CAVE_EXPLORE:
                do{
                    randRow = availableFieldRows[Random() % (sizeof(availableFieldRows)/sizeof(availableFieldRows[0]))];
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_REPEL       &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_REPEL &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_REPEL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_LURE        &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_LURE  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_LURE    &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_POKE_BALL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_GREAT_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_ULTRA_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_DUSK_BALL) ||
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
            case CAROUSEL_ROUTE_EXPLORE:
                do{
                    randRow = availableFieldRows[Random() % (sizeof(availableFieldRows)/sizeof(availableFieldRows[0]))];
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_REPEL       &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_REPEL &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_REPEL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_LURE        &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_SUPER_LURE  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_MAX_LURE    &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_POKE_BALL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_GREAT_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_ULTRA_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_HEAL_BALL   &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_TIMER_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_QUICK_BALL  &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_REPEAT_BALL &&
                       sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] != ITEM_LUXURY_BALL) ||
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
            default:
                do{
                    randRow = availableRows[Random() % (sizeof(availableRows)/sizeof(availableRows[0]))];
                    randItemNum = (Random() + i)% sMenuDataPtr->itemNum[randRow];
                    sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] = sMenuDataPtr->currentRowItemList[randRow][randItemNum];
                }
                while(sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == ITEM_NONE || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][0] && i != 0) || 
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][1] && i != 1) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][2] && i != 2) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][3] && i != 3) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][4] && i != 4) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][5] && i != 5) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][6] && i != 6) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][7] && i != 7) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][8] && i != 8) ||  
                      (sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][i] == sMenuDataPtr->currentRowItemList[ROW_RECOMMENDED][9] && i != 9));
                sMenuDataPtr->itemNum[ROW_RECOMMENDED]++;

            break;
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

static const u8 sText_Help_Bar[]          = _("{DPAD_UPDOWN} Rows {DPAD_LEFTRIGHT} Items {A_BUTTON} Buy {B_BUTTON} Exit {START_BUTTON} Sort Rows");
static const u8 sText_Help_Bar_Buy[]      = _("{DPAD_UPDOWN} +1/-1 {DPAD_LEFTRIGHT} +5/-5 {A_BUTTON} Buy Now {B_BUTTON} Cancel");
static const u8 sText_Help_Bar_Complete[] = _("{A_BUTTON} Buy More {B_BUTTON} Return {START_BUTTON} Exit");
static const u8 sText_Money_Bar[]         = _("Money: ¥{STR_VAR_1}");
static const u8 sText_Price[]             = _("Price: ¥{STR_VAR_1}");
static const u8 sText_FirstRowName[]      = _("{STR_VAR_1}: {STR_VAR_2}");
static const u8 sText_ItemNameOwned[]     = _("{STR_VAR_1} - {STR_VAR_2} Owned");
static const u8 sText_ItemCost[]          = _("Item Cost:    ¥ {STR_VAR_1}");
static const u8 sText_DroneFee[]          = _("Drone Fee:    ¥ {STR_VAR_1}");
//static const u8 sText_DroneFee[]        = _("Drone Fee:    ¥ {STR_VAR_1} ({STR_VAR_2}%)");
static const u8 sText_OrderTotal[]        = _("Order Total: ¥ {STR_VAR_1}");
static const u8 sText_ItemPrice[]         = _("¥ {STR_VAR_1}");
static const u8 sText_DeliveryTo[]        = _("Delivery to {STR_VAR_1} ({STR_VAR_2})");


static const u8 sText_OrderDelivered[]       = _("Order Delivered!");
static const u8 sText_ThanksForBuying[]      = _("Thank you for your purchase!");
static const u8 sText_YouGot[]               = _("You got");
static const u8 sText_ItemNumber[]           = _("{STR_VAR_1} x{STR_VAR_2}");


static const u8 sText_noEnoughMoney[]        = _("Your account has been declined for insufficient funds!");

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
    u8 itemRow[NUM_MAX_ICONS_ROWNS_ON_SCREEN];

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    if(!sMenuDataPtr->buyScreen){
        // Row Icons
        x = 1;
        y = 2;
        x2 = 0;
        y2 = 4;

        for(i = 0; i < NUM_MAX_ICONS_ROWNS_ON_SCREEN; i++ ){
            switch(i){
                case 1:
                    itemRow[i] = i;
                    if(sMenuDataPtr->currentRowItemList[(GetCurrentRow() + itemRow[i]) % NUM_ROWS][0] == ITEM_NONE){
                        do{
                            itemRow[i]++;
                        }
                        while(sMenuDataPtr->currentRowItemList[(GetCurrentRow() + itemRow[i]) % NUM_ROWS][0] == ITEM_NONE);
                    }
                break;
                default:
                    itemRow[i] = itemRow[i-1] + 1;
                    if(sMenuDataPtr->currentRowItemList[(GetCurrentRow() + itemRow[i]) % NUM_ROWS][0] == ITEM_NONE){
                        do{
                            itemRow[i]++;
                        }
                        while(sMenuDataPtr->currentRowItemList[(GetCurrentRow() + itemRow[i]) % NUM_ROWS][0] == ITEM_NONE);
                    }
                break;
            }

            if(sMenuDataPtr->rowsSorted)
                temp = 2;
            else
                temp = 0;

            if(sMenuDataPtr->currentRow % NUM_ROWS == sMenuDataPtr->currentFirstShownRow + i)
                BlitBitmapToWindow(windowId, sRowSelector, ((x-1)*8) + x2, ((y-1)*8) + y2 + 4, 32, 24);

            switch((sMenuDataPtr->currentFirstShownRow + i + temp)){
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
                switch(i){
                    case 0:
                        itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow()) % NUM_ROWS][(sMenuDataPtr->currentFirstShownItem + j)];
                    break;
                    case 1:
                    case 2:
                        itemID = sMenuDataPtr->currentRowItemList[(GetCurrentRow() + itemRow[i]) % NUM_ROWS][j];
                    break;
                }
                
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
            switch(i){
                case 0:
                    str = Amazon_Rows[GetCurrentRow()].title;
                    StringCopy(gStringVar1, str);
                    str = gItems[sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem]].name;
                    StringCopy(gStringVar2, str);
                    StringExpandPlaceholders(gStringVar4, sText_FirstRowName);
                break;
                case 1:
                case 2:
                    StringCopy(gStringVar4, Amazon_Rows[(GetCurrentRow() + itemRow[i]) % NUM_ROWS].title);
                break;
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
                y = 7;
                AddTextPrinterParameterized4(windowId, 8, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, sText_ThanksForBuying); 

                x = 6;
                y = y + 2;
                AddTextPrinterParameterized4(windowId, 8, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, sText_YouGot); 
                
                x = 6;
                y = y + 2;
                str = gItems[itemID].name;
                StringCopy(gStringVar1, str); 
                ConvertIntToDecimalStringN(gStringVar2, quantity, STR_CONV_MODE_LEFT_ALIGN, 2);  
                StringExpandPlaceholders(gStringVar4, sText_ItemNumber);
                AddTextPrinterParameterized4(windowId, 8, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar4);

                /*
                //Item Icon --------------------------------------------------------------------------------------------------------------------
                x = 0;
                y = 0;
                x2 = 0;
                y2 = 0;
                MoveCurrenItemIcon(sMenuDataPtr->currentItem - sMenuDataPtr->currentFirstShownItem, (x * 8) + x2, (y * 8) + y2);*/
            }
        }
    }
    // Help Bar --------------------------------------------------------------------------------------------------------------------
    x = 0;
    y = 18;

    if(!sMenuDataPtr->buyScreen){
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar);
    }
    else{
        if(!sMenuDataPtr->buyWindow){
            if(!sMenuDataPtr->notEnoughMoneyWindow)
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar_Buy);  
            else
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_noEnoughMoney);  
        }
        else{
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar_Complete); 
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

    if(GetCurrentRow() != ROW_TMS && GetCurrentRow() != ROW_Z_CRYSTALS && GetCurrentRow() != ROW_MEGA_STONES){
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

        for(i = 0; i < MAX_AMAZON_BUY_AGAIN_ITEMS; i++){
            sMenuDataPtr->currentRowItemList[ROW_BUY_AGAIN][i] = gSaveBlock2Ptr->amazonBuyAgainItem[i];

            if(sMenuDataPtr->itemNum[ROW_BUY_AGAIN] < MAX_AMAZON_BUY_AGAIN_ITEMS && newItem)
                sMenuDataPtr->itemNum[ROW_BUY_AGAIN]++;
        }
            
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

                if(GetCurrentRow() == ROW_TMS || GetCurrentRow() == ROW_Z_CRYSTALS || GetCurrentRow() == ROW_MEGA_STONES)
                    AmazonItemInitializeArrayList();
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
            Menu_ChangeTilemap();

            if(GetCurrentRow() == ROW_BUY_AGAIN|| GetCurrentRow() == ROW_TMS || GetCurrentRow() == ROW_Z_CRYSTALS || GetCurrentRow() == ROW_MEGA_STONES){
                AmazonItemInitializeArrayList();
                sMenuDataPtr->currentItem = 0;
            }

            if(sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem] == ITEM_NONE)
                sMenuDataPtr->currentRow = ROW_MEDICINE;
                    
            PrintToWindow(WINDOW_1, FONT_BLACK);
            PlaySE(SE_SELECT);
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

                if(GetCurrentRow() == ROW_BUY_AGAIN|| 
                   GetCurrentRow() == ROW_TMS || 
                   GetCurrentRow() == ROW_Z_CRYSTALS || 
                   GetCurrentRow() == ROW_MEGA_STONES)
                    AmazonItemInitializeArrayList();

                if(GetCurrentRow() == ROW_TMS || GetCurrentRow() == ROW_Z_CRYSTALS || GetCurrentRow() == ROW_MEGA_STONES){
                    sMenuDataPtr->itemQuantity = 0;
                    PlaySE(SE_SELECT);
                    Menu_ChangeTilemap();

                    sMenuDataPtr->currentItem = 0;

                    if(sMenuDataPtr->currentRowItemList[GetCurrentRow()][sMenuDataPtr->currentItem] == ITEM_NONE)
                        sMenuDataPtr->currentRow = ROW_MEDICINE;
                    
                    PrintToWindow(WINDOW_1, FONT_BLACK);
                }

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
    if(JOY_NEW(START_BUTTON))
	{
        if(!sMenuDataPtr->buyScreen && !sMenuDataPtr->buyWindow){
            sMenuDataPtr->rowsSorted = !sMenuDataPtr->rowsSorted;
            PlaySE(SE_SELECT);

            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
        else if(sMenuDataPtr->buyWindow){
            PlaySE(SE_PC_OFF);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_MenuTurnOff;
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