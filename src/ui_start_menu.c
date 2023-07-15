#include "global.h"
#include "ui_start_menu.h"
#include "strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "event_data.h"
#include "field_weather.h"
#include "frontier_pass.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_icon.h"
#include "item_use.h"
#include "international_string_util.h"
#include "link.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "option_menu.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "pokemon_icon.h"
#include "quests.h"
#include "quest_flavor_lookup.h"
#include "rtc.h"
#include "region_map.h"
#include "ui_map_system.h"
#include "trainer_card.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
#include "ui_options_menu.h"
#include "ui_amazon.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/flags.h"
#include "printf.h"
#include "mgba.h"
#include "ui_map_system.h"

/*
 * 
 */

//==========DEFINES==========//
struct MenuResources
{
    MainCallback savedCallback;     // determines callback to run when we exit. e.g. where do we want to go after closing the menu
    u8 gfxLoadState;
    u8 currentAppId;
    u8 TempAppId;
    bool8 areYouOnSecondScreen;
    bool8 areYouOnSecondScreenTemp;
    bool8 isAppSelectedForMove;
    bool8 shouldShowErrorMessage;
    u8 startMenuAppTempIndex[NUM_TOTAL_APPS];
    u8 PartyPokemonIcon;
    u8 PartyPokemonIcon_1;
    u8 PartyPokemonIcon_2;
    u8 PartyPokemonIcon_3;
    u8 PartyPokemonIcon_4;
    u8 PartyPokemonIcon_5;
    u8 PartyPokemonIcon_6;
};

enum WindowIds
{
    WINDOW_1,
};

//Defines
#define  NUM_APPS_PER_SCREEN    5

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
//static EWRAM_DATA u8  sMenuDataPtr->currentAppId = 0;
//static EWRAM_DATA u8  sMenuDataPtr->TempAppId = 0;
//static EWRAM_DATA bool8 sMenuDataPtr->areYouOnSecondScreen = FALSE;
//static EWRAM_DATA bool8 sMenuDataPtr->areYouOnSecondScreenTemp = FALSE;
//static EWRAM_DATA bool8 sMenuDataPtr->isAppSelectedForMove = FALSE;
//static EWRAM_DATA bool8 sMenuDataPtr->shouldShowErrorMessage = FALSE;
//static EWRAM_DATA u8 sMenuDataPtr->startMenuAppTempIndex[NUM_TOTAL_APPS];

//Pokemon Icons
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon 	 = 0;
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon_1  = 0;
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon_2  = 0;
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon_3  = 0;
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon_4  = 0;
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon_5  = 0;
//EWRAM_DATA static u8 sMenuDataPtr->PartyPokemonIcon_6  = 0;

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
static u8 GetCurrentAppfromIndex(u8 index);
static u8 GetCurrentSignal();
static u8 ShowSpeciesIcon(u8 slot, u8 x, u8 y);
static void DestroySpeciesIcon(u8 slot);
static void StartMenuTempIndextoIndex(void);
static void StartMenuIndextoTempIndex(void);

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
        .paletteNum = 0,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[]                       = INCBIN_U32("graphics/start_menu/tiles.4bpp.lz");
static const u32 sMenuTilemap[]                     = INCBIN_U32("graphics/start_menu/tilemap.bin.lz");

static const u16 sMenuPalette[]                     = INCBIN_U16("graphics/start_menu/palette.gbapal");

static const u16 sMenuPalette_Red[]      = INCBIN_U16("graphics/start_menu/palettes/red.gbapal");
static const u16 sMenuPalette_Black[]    = INCBIN_U16("graphics/start_menu/palettes/black.gbapal");
static const u16 sMenuPalette_Green[]    = INCBIN_U16("graphics/start_menu/palettes/green.gbapal");
static const u16 sMenuPalette_Blue[]     = INCBIN_U16("graphics/start_menu/palettes/blue.gbapal");
static const u16 sMenuPalette_Platinum[] = INCBIN_U16("graphics/start_menu/palettes/platinum.gbapal");
static const u16 sMenuPalette_Scarlet[]  = INCBIN_U16("graphics/start_menu/palettes/scarlet.gbapal");
static const u16 sMenuPalette_Violet[]   = INCBIN_U16("graphics/start_menu/palettes/violet.gbapal");
static const u16 sMenuPalette_White[]    = INCBIN_U16("graphics/start_menu/palettes/white.gbapal");
static const u16 sMenuPalette_Yellow[]   = INCBIN_U16("graphics/start_menu/palettes/yellow.gbapal");

static const u8 sStartMenuCursor_Gfx[]              = INCBIN_U8("graphics/start_menu/menu_cursor.4bpp");
static const u8 sStartMenuCursorMoveMode_Gfx[]      = INCBIN_U8("graphics/start_menu/menu_cursor_move.4bpp");
static const u8 sStartMenuCursorMoveMode2_Gfx[]     = INCBIN_U8("graphics/start_menu/menu_cursor_move2.4bpp");
static const u8 sStartMenuMoveModeText_Gfx[]        = INCBIN_U8("graphics/start_menu/move_mode.4bpp");
static const u8 sStartMenuNormalModeText1_Gfx[]     = INCBIN_U8("graphics/start_menu/normal_mode_bar.4bpp");
static const u8 sStartMenuNormalModeText2_Gfx[]     = INCBIN_U8("graphics/start_menu/normal_mode_bar_2.4bpp");
static const u8 sStartMenuRowIcon_Gfx[]             = INCBIN_U8("graphics/start_menu/menu_row_icon.4bpp");

//HP Bar
static const u8 sStartMenu_HPBar_Gfx[]              = INCBIN_U8("graphics/start_menu/hp_bar.4bpp");
static const u8 sStartMenu_HPBar_Full_Gfx[]         = INCBIN_U8("graphics/start_menu/hp_bar_full.4bpp");
static const u8 sStartMenu_HPBar_90_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_90_percent.4bpp");
static const u8 sStartMenu_HPBar_80_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_80_percent.4bpp");
static const u8 sStartMenu_HPBar_70_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_70_percent.4bpp");
static const u8 sStartMenu_HPBar_60_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_60_percent.4bpp");
static const u8 sStartMenu_HPBar_50_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_50_percent.4bpp");
static const u8 sStartMenu_HPBar_40_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_40_percent.4bpp");
static const u8 sStartMenu_HPBar_30_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_30_percent.4bpp");
static const u8 sStartMenu_HPBar_20_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_20_percent.4bpp");
static const u8 sStartMenu_HPBar_10_Percent_Gfx[]   = INCBIN_U8("graphics/start_menu/hp_bar_10_percent.4bpp");
static const u8 sStartMenu_HPBar_Fainted_Gfx[]      = INCBIN_U8("graphics/start_menu/hp_bar_fainted.4bpp");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  2, TEXT_COLOR_TRANSPARENT},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  1,  TEXT_COLOR_TRANSPARENT},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT,  11, TEXT_COLOR_TRANSPARENT},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT,  13, TEXT_COLOR_TRANSPARENT},
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Menu_Init(CB2_ReturnToField);
        DestroyTask(taskId);
    }
}

#define CURRENT_APP_ID_VAR VAR_CURRENT_START_MENU_APP
//#define DEBUG_VAR          VAR_TEMP_E

// This is our main initialization function if you want to call the menu from elsewhere
void Menu_Init(MainCallback callback)
{
    /*
    //This is to test a EWRAM issue when opening and closing the menu a lot
    u16 temp = VarGet(DEBUG_VAR);
    temp++;
    VarSet(DEBUG_VAR, temp);
    */

    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;
    
    sMenuDataPtr->currentAppId = VarGet(CURRENT_APP_ID_VAR) % NUM_APPS_PER_SCREEN;
    if(VarGet(CURRENT_APP_ID_VAR) >= NUM_APPS_PER_SCREEN){
        sMenuDataPtr->areYouOnSecondScreen = TRUE;
    }
    else{
        sMenuDataPtr->areYouOnSecondScreen = FALSE;
    }
    
    sMenuDataPtr->TempAppId = 0;
    sMenuDataPtr->areYouOnSecondScreenTemp = FALSE;
    sMenuDataPtr->isAppSelectedForMove = FALSE;
    sMenuDataPtr->shouldShowErrorMessage = FALSE;

    sMenuDataPtr->PartyPokemonIcon 	 = 0;
    sMenuDataPtr->PartyPokemonIcon_1  = 0;
    sMenuDataPtr->PartyPokemonIcon_2  = 0;
    sMenuDataPtr->PartyPokemonIcon_3  = 0;
    sMenuDataPtr->PartyPokemonIcon_4  = 0;
    sMenuDataPtr->PartyPokemonIcon_5  = 0;
    sMenuDataPtr->PartyPokemonIcon_6  = 0;

    //Initialize the apps the first time you open the start menu
    if(!FlagGet(FLAG_START_MENU_SETUP)){
        u8 i;
        for(i = 0; i < NUM_TOTAL_APPS; i++){
            gSaveBlock2Ptr->startMenuAppIndex[i] = (NUM_TOTAL_APPS -1) - i;
        }
        FlagSet(FLAG_START_MENU_SETUP);
    }

    StartMenuIndextoTempIndex();

    SetMainCallback2(Menu_RunSetup);
}

static void StartMenuTempIndextoIndex()
{
    u8 i;
    for(i = 0; i < NUM_TOTAL_APPS; i++){
        gSaveBlock2Ptr->startMenuAppIndex[i] = sMenuDataPtr->startMenuAppTempIndex[i];
    }
    sMenuDataPtr->currentAppId = sMenuDataPtr->TempAppId;
    sMenuDataPtr->areYouOnSecondScreen = sMenuDataPtr->areYouOnSecondScreenTemp;
}

static void StartMenuIndextoTempIndex()
{
    u8 i;
    for(i = 0; i < NUM_TOTAL_APPS; i++){
        sMenuDataPtr->startMenuAppTempIndex[i] = GetCurrentAppfromIndex(i);
    }
    sMenuDataPtr->TempAppId = sMenuDataPtr->currentAppId;
    sMenuDataPtr->areYouOnSecondScreenTemp = sMenuDataPtr->areYouOnSecondScreen;
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
    u8 x,y,i;

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

        // Pokemon Icons --------------------------------------------------------------------------------------------------------------------
        x = 2;
        y = 3;

        for(i = 0; i < PARTY_SIZE; i++){
            if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE)
                ShowSpeciesIcon(i, (x*8) + 4, (y*8));
            x = x + 4;
        }
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
        switch(gSaveBlock2Ptr->optionsVisual[VISUAL_OPTIONS_COLOR]){
            case OPTIONS_MENU_COLOR_BLACK:
                LoadPalette(sMenuPalette_Black, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_BLUE:
                LoadPalette(sMenuPalette_Blue, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_GREEN:
                LoadPalette(sMenuPalette_Green, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_PLATINUM:
                LoadPalette(sMenuPalette_Platinum, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_RED:
                LoadPalette(sMenuPalette_Red, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_SCARLET:
                LoadPalette(sMenuPalette_Scarlet, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_VIOLET:
                LoadPalette(sMenuPalette_Violet, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_WHITE:
                LoadPalette(sMenuPalette_White, 0, 32);
            break;
            case OPTIONS_MENU_COLOR_YELLOW:
                LoadPalette(sMenuPalette_Yellow, 0, 32);
            break;
            default:
                LoadPalette(sMenuPalette, 0, 32);
            break;
        }
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

static const u8 sText_App_None[] = _("No App");

static const u8 sText_App_Pokemon[] = _("Pokémon");
static const u8 sText_App_Bag[]     = _("Bag");
static const u8 sText_App_Map[]     = _("Map");
static const u8 sText_App_Quest[]   = _("Quest");
static const u8 sText_App_Dexnav[]  = _("Dexnav");
static const u8 sText_App_Pokedex[] = _("Pokédex");
static const u8 sText_App_Twitter[] = _("Twitter");
static const u8 sText_App_Options[] = _("Options");
static const u8 sText_App_Amazon[]  = _("Amazon");

static const u8 sText_Unknown_Location[] = _("Unknown");

static const u8 Time[] =  _("{STR_VAR_2}:{STR_VAR_3}$");
static const u8 Time2[] =  _("{STR_VAR_2}:0{STR_VAR_3}$");


static const u8 sText_App_Morning[] = _("Morning");
static const u8 sText_App_Day[]     = _("Day");
static const u8 sText_App_Evening[] = _("Evening");
static const u8 sText_App_Night[]   = _("Night");

static const u8 sText_Quest_No_Quest[]   = _("");

enum AppsIds
{
    APP_POKEMON,
    APP_BAG,
    APP_MAP,
    APP_QUEST,
    APP_DEXNAV,
    APP_POKEDEX,
    APP_TWITTER,
    APP_OPTIONS,
    APP_PROFILE,
    APP_AMAZON,
};

static const u8 sStartMenuApp_Pokemon_Gfx[]  = INCBIN_U8("graphics/start_menu/app_pokemon.4bpp");
static const u8 sStartMenuApp_Bag_Gfx[]      = INCBIN_U8("graphics/start_menu/app_bag.4bpp");
static const u8 sStartMenuApp_Map_Gfx[]      = INCBIN_U8("graphics/start_menu/app_map.4bpp");
static const u8 sStartMenuApp_Quest_Gfx[]    = INCBIN_U8("graphics/start_menu/app_quest.4bpp");
static const u8 sStartMenuApp_Dexnav_Gfx[]   = INCBIN_U8("graphics/start_menu/app_dexnav.4bpp");
static const u8 sStartMenuApp_Pokedex_Gfx[]  = INCBIN_U8("graphics/start_menu/app_pokedex.4bpp");
static const u8 sStartMenuApp_Twitter_Gfx[]  = INCBIN_U8("graphics/start_menu/app_twitter.4bpp");
static const u8 sStartMenuApp_Options_Gfx[]  = INCBIN_U8("graphics/start_menu/app_options.4bpp");
static const u8 sStartMenuApp_Profile_Gfx[]  = INCBIN_U8("graphics/start_menu/app_profile.4bpp");
static const u8 sStartMenuApp_Amazon_Gfx[]   = INCBIN_U8("graphics/start_menu/app_amazon.4bpp");
static const u8 sStartMenuApp_Default_Gfx[]  = INCBIN_U8("graphics/start_menu/app_default.4bpp");

static const u8 sStartMenuApp_Pokemon_Move_Mode_Gfx[]  = INCBIN_U8("graphics/start_menu/app_pokemon_move.4bpp");
static const u8 sStartMenuApp_Bag_Move_Mode_Gfx[]      = INCBIN_U8("graphics/start_menu/app_bag_move.4bpp");
static const u8 sStartMenuApp_Map_Move_Mode_Gfx[]      = INCBIN_U8("graphics/start_menu/app_map_move.4bpp");
static const u8 sStartMenuApp_Quest_Move_Mode_Gfx[]    = INCBIN_U8("graphics/start_menu/app_quest_move.4bpp");
static const u8 sStartMenuApp_Dexnav_Move_Mode_Gfx[]   = INCBIN_U8("graphics/start_menu/app_dexnav_move.4bpp");
static const u8 sStartMenuApp_Pokedex_Move_Mode_Gfx[]  = INCBIN_U8("graphics/start_menu/app_pokedex_move.4bpp");
static const u8 sStartMenuApp_Twitter_Move_Mode_Gfx[]  = INCBIN_U8("graphics/start_menu/app_twitter_move.4bpp");
static const u8 sStartMenuApp_Options_Move_Mode_Gfx[]  = INCBIN_U8("graphics/start_menu/app_options_move.4bpp");
static const u8 sStartMenuApp_Profile_Move_Mode_Gfx[]  = INCBIN_U8("graphics/start_menu/app_profile_move.4bpp");
static const u8 sStartMenuApp_Amazon_Move_Mode_Gfx[]   = INCBIN_U8("graphics/start_menu/app_amazon_move.4bpp");
static const u8 sStartMenuApp_Default_Move_Mode_Gfx[]  = INCBIN_U8("graphics/start_menu/app_default_move.4bpp");

static const u8 sStartMenuApp_Signal_0_Gfx[]  = INCBIN_U8("graphics/start_menu/signal_0.4bpp");
static const u8 sStartMenuApp_Signal_1_Gfx[]  = INCBIN_U8("graphics/start_menu/signal_1.4bpp");
static const u8 sStartMenuApp_Signal_2_Gfx[]  = INCBIN_U8("graphics/start_menu/signal_2.4bpp");
static const u8 sStartMenuApp_Signal_3_Gfx[]  = INCBIN_U8("graphics/start_menu/signal_3.4bpp");

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str_SelectedOption;
    const u8 *str_CurrentLocation = sText_Unknown_Location;
	const u8 *str_QuestFlavorLookup = gText_CommErrorEllipsis;
    u8 i, j;
    u8 CurrentApp = sMenuDataPtr->currentAppId;
    u8 x = 1;
    u8 y = 1;
    u8 hours = gLocalTime.hours;
	u8 minutes = gLocalTime.minutes;
    u8 strArray[16];
    u8 signal = GetCurrentSignal();
    u8 firstFavoritedQuest = getFirstFavoriteQuest();

    // Current App Title
    x = 19;
    y = 11;

    if(sMenuDataPtr->areYouOnSecondScreen)
        CurrentApp = CurrentApp + NUM_APPS_PER_SCREEN;

    switch(GetCurrentAppfromIndex(CurrentApp)){
        case APP_POKEMON:
            str_SelectedOption  = sText_App_Pokemon;	
        break;
        case APP_BAG:	
            str_SelectedOption = sText_App_Bag;	
        break;
        case APP_MAP:	
            str_SelectedOption = sText_App_Map;	
        break;			
        case APP_QUEST:	
            str_SelectedOption = sText_App_Quest;
        break;
        case APP_DEXNAV:		
            str_SelectedOption = sText_App_Dexnav;
        break;
        case APP_POKEDEX:	
            str_SelectedOption = sText_App_Pokedex;
        break;
        case APP_TWITTER:		
            str_SelectedOption = sText_App_Twitter;
        break;
        case APP_OPTIONS:	
            str_SelectedOption = sText_App_Options;
        break;
        case APP_PROFILE:	
            StringCopy(&strArray[0], gSaveBlock2Ptr->playerName);
            str_SelectedOption = strArray;
        break;
        case APP_AMAZON:	
            str_SelectedOption = sText_App_Amazon;
        break;
        default:	
            str_SelectedOption = sText_App_None;	
        break;
	}

    FillWindowPixelBuffer(windowId, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));
    AddTextPrinterParameterized4(windowId, 7, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, str_SelectedOption);

    // App Icons --------------------------------------------------------------------------------------------------------
    x = 1;
	y = 6;

    for(i = 0; i < NUM_APPS_PER_SCREEN; i++){
        switch(GetCurrentAppfromIndex(CurrentApp + NUM_TOTAL_APPS - i + 2)){
            case APP_POKEMON:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Pokemon_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Pokemon_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_BAG:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Bag_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Bag_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_MAP:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Map_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Map_Gfx, (x*8), (y*8), 40, 40);
            break;			
            case APP_QUEST:	
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Quest_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Quest_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_DEXNAV:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Dexnav_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Dexnav_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_POKEDEX:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Pokedex_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Pokedex_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_TWITTER:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Twitter_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Twitter_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_OPTIONS:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Options_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Options_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_PROFILE:
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Profile_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Profile_Gfx, (x*8), (y*8), 40, 40);
            break;
            case APP_AMAZON:	
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Amazon_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Amazon_Gfx, (x*8), (y*8), 40, 40);
            break;
            default:	
                if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
                    BlitBitmapToWindow(windowId, sStartMenuApp_Default_Move_Mode_Gfx, (x*8), (y*8), 40, 40);
                else
                    BlitBitmapToWindow(windowId, sStartMenuApp_Default_Gfx, (x*8), (y*8), 40, 40);
            break;
        }

        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && i != 2)
            BlitBitmapToWindow(windowId, sStartMenuCursorMoveMode_Gfx, (x*8), (y*8), 40, 40);

        x = x + 6;
    }

    // Move Mode Text --------------------------------------------------------------------------------------------------------
    x = 0;
	y = 18;

    if(FlagGet(FLAG_START_MENU_MOVE_MODE))
        BlitBitmapToWindow(windowId, sStartMenuMoveModeText_Gfx, (x*8), (y*8), 96, 16);
    else{
        BlitBitmapToWindow(windowId, sStartMenuNormalModeText1_Gfx, (x*8), (y*8), 88, 16);
        x = 12;
        BlitBitmapToWindow(windowId, sStartMenuNormalModeText2_Gfx, (x*8), (y*8), 120, 16);
    }

    // Selection Sprite --------------------------------------------------------------------------------------------------------
	x = 13;
	y = 6;

    BlitBitmapToWindow(windowId, sStartMenuCursor_Gfx, (x*8), (y*8), 40, 40);

    // Screen Indicator --------------------------------------------------------------------------------------------------------
    x = 14;
    y = 11;

    if(!FlagGet(FLAG_START_MENU_MOVE_MODE))
        BlitBitmapToWindow(windowId, sStartMenuRowIcon_Gfx, (x*8), (y*8), 16, 24);
    // HP Bars --------------------------------------------------------------------------------------------------------
    x = 1;
    y = 3;

    for(i = 0; i < PARTY_SIZE; i++){
        if(GetMonData(&gPlayerParty[i], MON_DATA_SPECIES) != SPECIES_NONE){
            u16 maxHP = GetMonData(&gPlayerParty[i], MON_DATA_MAX_HP);
            u16 currentHP = GetMonData(&gPlayerParty[i], MON_DATA_HP);

            BlitBitmapToWindow(windowId, sStartMenu_HPBar_Gfx, (x*8), (y*8), 24, 16);
            if(maxHP == currentHP)
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_Full_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.9) < currentHP && currentHP < maxHP)
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_90_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.8) < currentHP && currentHP < (maxHP * 0.9))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_80_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.7) < currentHP && currentHP < (maxHP * 0.8))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_70_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.6) < currentHP && currentHP < (maxHP * 0.7))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_60_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.5) < currentHP && currentHP < (maxHP * 0.6))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_50_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.4) < currentHP && currentHP < (maxHP * 0.5))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_40_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.3) < currentHP && currentHP < (maxHP * 0.4))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_30_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if((maxHP * 0.2) < currentHP && currentHP < (maxHP * 0.3))
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_20_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else if(currentHP != 0)
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_10_Percent_Gfx, (x*8), ((y+2)*8), 24, 8);
            else
                BlitBitmapToWindow(windowId, sStartMenu_HPBar_Fainted_Gfx, (x*8), ((y+2)*8), 24, 8);
        }
        x = x + 4;
    }

    // Signal ------------------------------------------------------------------------------------------------------------------------------------
    x = 21;
	y = 0;

    switch(signal){
        case 0:
            BlitBitmapToWindow(windowId, sStartMenuApp_Signal_0_Gfx, (x*8), (y*8), 16, 16);
        break;
        case 1:
            BlitBitmapToWindow(windowId, sStartMenuApp_Signal_1_Gfx, (x*8), (y*8), 16, 16);
        break;
        case 2:
            BlitBitmapToWindow(windowId, sStartMenuApp_Signal_2_Gfx, (x*8), (y*8), 16, 16);
        break;
        default:
            BlitBitmapToWindow(windowId, sStartMenuApp_Signal_3_Gfx, (x*8), (y*8), 16, 16);
        break;
    }

    //Time --------------------------------------------------------------------------------------------------------------------
	x = 24;
	y = 0;
	ConvertIntToDecimalStringN(gStringVar2, hours, STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar3, minutes, STR_CONV_MODE_LEFT_ALIGN, 2);
	if(minutes >= 10)
		StringExpandPlaceholders(gStringVar4, Time);
	else
		StringExpandPlaceholders(gStringVar4, Time2);
	AddTextPrinterParameterized4(windowId, 7, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

    // Current Location --------------------------------------------------------------------------------------------------------------------
	x = 1;
	y = 11;
    GetMapNameGeneric(gStringVar1, gMapHeader.regionMapSectionId);
	AddTextPrinterParameterized4(windowId, 7, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

    // Time of the Day --------------------------------------------------------------------------------------------------------------------
	x = 25;
	y = 2;

    if(hours >= 6 && hours < 10)
	    StringExpandPlaceholders(gStringVar1, sText_App_Morning);
    else if(hours < 19)
	    StringExpandPlaceholders(gStringVar1, sText_App_Day);
    else if(hours < 20)
	    StringExpandPlaceholders(gStringVar1, sText_App_Evening);
    else
	    StringExpandPlaceholders(gStringVar1, sText_App_Night);

    AddTextPrinterParameterized4(windowId, 7, (x*8), (y*8) + 2, 0, 0, sMenuWindowFontColors[FONT_BLACK], 0xFF, gStringVar1);

    // Quest Information --------------------------------------------------------------------------------------------------------------------
	x = 0;
	y = 14;
	
    if(!sMenuDataPtr->shouldShowErrorMessage){
        if(VarGet(VAR_STORYLINE_STATE) < STORY_CLEAR){
            str_QuestFlavorLookup = GetQuestDesc_PlayersAdventure();
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str_QuestFlavorLookup);
        }  
        else if(firstFavoritedQuest != SUB_QUEST_COUNT){
            GenerateQuestFlavorText(firstFavoritedQuest);
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);
        }
        else{
            str_QuestFlavorLookup = sText_Quest_No_Quest;
            AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str_QuestFlavorLookup);
        }
    }
    else{
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str_QuestFlavorLookup);
    }
    sMenuDataPtr->shouldShowErrorMessage = FALSE;

    PutWindowTilemap(windowId);
    CopyWindowToVram(windowId, 3);
}

static u8 ShowSpeciesIcon(u8 slot, u8 x, u8 y)
{
	u16 species = GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES);
	u32 personality = GetMonData(&gPlayerParty[slot], MON_DATA_PERSONALITY);
	/*/if (gBaseStats[species].flags = FLAG_GENDER_DIFFERENCE && GetGenderFromSpeciesAndPersonality(species, personality) == MON_FEMALE)
		LoadFemaleMonIconPalette(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES));
	else/*/
		LoadMonIconPalette(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES));

    switch(slot){
        case 0:
            sMenuDataPtr->PartyPokemonIcon = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, 0);

            gSprites[sMenuDataPtr->PartyPokemonIcon].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon;
        break;
        case 1:
            sMenuDataPtr->PartyPokemonIcon_1 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, 0);

            gSprites[sMenuDataPtr->PartyPokemonIcon_1].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_1;
        break;
        case 2:
            sMenuDataPtr->PartyPokemonIcon_2 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, 0);

            gSprites[sMenuDataPtr->PartyPokemonIcon_2].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_2;
        break;
        case 3:
            sMenuDataPtr->PartyPokemonIcon_3 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, 0);

            gSprites[sMenuDataPtr->PartyPokemonIcon_3].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_3;
        break;
        case 4:
            sMenuDataPtr->PartyPokemonIcon_4 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, 0);

            gSprites[sMenuDataPtr->PartyPokemonIcon_4].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_4;
        break;
        case 5:
            sMenuDataPtr->PartyPokemonIcon_5 = CreateMonIcon(GetMonData(&gPlayerParty[slot], MON_DATA_SPECIES), SpriteCB_MonIcon, x, y, 0, 0);

            gSprites[sMenuDataPtr->PartyPokemonIcon_5].invisible = FALSE;
            return sMenuDataPtr->PartyPokemonIcon_5;
        break;
    }
}

static void DestroySpeciesIcon(u8 slot)
{
    switch(slot){
        case 0:
            if (sMenuDataPtr->PartyPokemonIcon != 0xFF)
                DestroySprite(&gSprites[sMenuDataPtr->PartyPokemonIcon]);
            sMenuDataPtr->PartyPokemonIcon = 0xFF;
        break;
        case 1:
            if (sMenuDataPtr->PartyPokemonIcon_1 != 0xFF)
                DestroySprite(&gSprites[sMenuDataPtr->PartyPokemonIcon_1]);
            sMenuDataPtr->PartyPokemonIcon_1 = 0xFF;
        break;
        case 2:
            if (sMenuDataPtr->PartyPokemonIcon_2 != 0xFF)
                DestroySprite(&gSprites[sMenuDataPtr->PartyPokemonIcon_2]);
            sMenuDataPtr->PartyPokemonIcon_2 = 0xFF;
        break;
        case 3:
            if (sMenuDataPtr->PartyPokemonIcon_3 != 0xFF)
                DestroySprite(&gSprites[sMenuDataPtr->PartyPokemonIcon_3]);
            sMenuDataPtr->PartyPokemonIcon_3 = 0xFF;
        break;
        case 4:
            if (sMenuDataPtr->PartyPokemonIcon_4 != 0xFF)
                DestroySprite(&gSprites[sMenuDataPtr->PartyPokemonIcon_4]);
            sMenuDataPtr->PartyPokemonIcon_4 = 0xFF;
        break;
        case 5:
            if (sMenuDataPtr->PartyPokemonIcon_5 != 0xFF)
                DestroySprite(&gSprites[sMenuDataPtr->PartyPokemonIcon_5]);
            sMenuDataPtr->PartyPokemonIcon_5 = 0xFF;
        break;
    }
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

void Task_OpenSaveMenuStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		//PlayRainStoppingSoundEffect();
		//CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_ReturnToFieldWithOpenMenu);
    }
}

// App Callbacks ----------------------------------------------------------------------------------------------------
void Task_OpenPokedexFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_OpenPokedex);
		DestroyTask(taskId);
    }
}

void Task_OpenPokemonPartyFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu
    }
}

void Task_OpenBagFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu
    }
}

void Task_OpenTrainerCardFromStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
		
		if (InUnionRoom())
			ShowPlayerTrainerCard(CB2_ReturnToUIMenu); // Display trainer card
		else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
			ShowFrontierPass(CB2_ReturnToUIMenu); // Display frontier pass
		else
			ShowPlayerTrainerCard(CB2_ReturnToUIMenu); // Display trainer card
    }
}

void Task_OpenPokenavStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		PlayRainStoppingSoundEffect();
		CleanupOverworldWindowsAndTilemaps();
        CreateTask(Task_OpenMapSystemFromStartMenu, 0);
		//SetMainCallback2(CB2_InitPokeNav);  // Display PokeNav
    }
}  

void Task_OpenOptionsMenuStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Menu_FreeResources();
		PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        Options_Menu_Init(CB2_ReturnToUIMenu);
        //SetMainCallback2(Option_Menu_Init); // Display option menu
        gMain.savedCallback = CB2_ReturnToField;
    }
}

void Task_OpenAmazonStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        Menu_FreeResources();
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        Amazon_Init(CB2_ReturnToUIMenu);
        //SetMainCallback2(Option_Menu_Init); // Display option menu
        gMain.savedCallback = CB2_ReturnToUIMenu;
    }
}  

static u8 GetCurrentAppfromIndex(u8 index)
{
    if(index >= NUM_TOTAL_APPS)
        return gSaveBlock2Ptr->startMenuAppIndex[index % NUM_TOTAL_APPS];
    else
        return gSaveBlock2Ptr->startMenuAppIndex[index];
}

static u8 GetCurrentSignal()
{
    //this one will be modified depending on how the story works, its not something that I will do since I'm not involved with the story
    //here you can change the signal this menu will get in certain areas in the game
    //the flag 0x89 is currently being used so I can't insert it but when anyone inserts it just remove the comments below
    //if(FlagGet(FLAG_PHONE_NO_SERVICE)) 
    //    return 0;
    //else
        return 3;
}

static void ClearStartMenuDataBeforeExit()
{
    sMenuDataPtr->isAppSelectedForMove = FALSE;
    FlagClear(FLAG_START_MENU_MOVE_MODE);
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    u8 CurrentApp = sMenuDataPtr->currentAppId;

    if(sMenuDataPtr->areYouOnSecondScreen)
        CurrentApp = CurrentApp + NUM_APPS_PER_SCREEN;

    if (JOY_NEW(B_BUTTON))
    {
        if(FlagGet(FLAG_START_MENU_MOVE_MODE)){
            StartMenuTempIndextoIndex();
            FlagClear(FLAG_START_MENU_MOVE_MODE);
            sMenuDataPtr->isAppSelectedForMove = FALSE;
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
        else{
            PlaySE(SE_PC_OFF);
            ClearStartMenuDataBeforeExit();
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_MenuTurnOff;
        }
    }
	
	if (JOY_NEW(R_BUTTON) || JOY_NEW(L_BUTTON))
    {
        if(!FlagGet(FLAG_START_MENU_MOVE_MODE))
            sMenuDataPtr->areYouOnSecondScreen = !sMenuDataPtr->areYouOnSecondScreen;

        PrintToWindow(WINDOW_1, FONT_BLACK);
    }
	
	if (JOY_NEW(START_BUTTON) && !FlagGet(FLAG_START_MENU_MOVE_MODE))
    {
        PlaySE(SE_PC_OFF);
        ClearStartMenuDataBeforeExit();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_OpenSaveMenuStartMenu;

        PrintToWindow(WINDOW_1, FONT_BLACK);
    }

    if(JOY_NEW(DPAD_LEFT))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && sMenuDataPtr->isAppSelectedForMove){
            if(CurrentApp < NUM_TOTAL_APPS-1){
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp + 1];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp + 1] = tempAppIndex;
            }
            else{
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[0];
                gSaveBlock2Ptr->startMenuAppIndex[0] = tempAppIndex;
            }
        }

        if(sMenuDataPtr->currentAppId < NUM_APPS_PER_SCREEN-1){
            sMenuDataPtr->currentAppId++;
        }
        else{
            sMenuDataPtr->currentAppId = 0;
            sMenuDataPtr->areYouOnSecondScreen = !sMenuDataPtr->areYouOnSecondScreen;
        }

        if(sMenuDataPtr->areYouOnSecondScreen){
            u8 tempAppIndex = sMenuDataPtr->currentAppId + NUM_APPS_PER_SCREEN;
            VarSet(CURRENT_APP_ID_VAR, tempAppIndex);
        }
        else{
            u8 tempAppIndex = sMenuDataPtr->currentAppId;
            VarSet(CURRENT_APP_ID_VAR, tempAppIndex);
        }

        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if(JOY_NEW(DPAD_UP))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && sMenuDataPtr->isAppSelectedForMove){
            if(CurrentApp < NUM_TOTAL_APPS-1){
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp + 1];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp + 1] = tempAppIndex;
            }
            else{
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[0];
                gSaveBlock2Ptr->startMenuAppIndex[0] = tempAppIndex;
            }
        }

        if(sMenuDataPtr->currentAppId < NUM_APPS_PER_SCREEN-1){
            sMenuDataPtr->currentAppId++;
        }
        else{
            sMenuDataPtr->currentAppId = 0;
            sMenuDataPtr->areYouOnSecondScreen = !sMenuDataPtr->areYouOnSecondScreen;
        }
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_RIGHT))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && sMenuDataPtr->isAppSelectedForMove){
            if(CurrentApp > 0){
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp - 1];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp - 1] = tempAppIndex;
            }
            else{
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[NUM_TOTAL_APPS-1];
                gSaveBlock2Ptr->startMenuAppIndex[NUM_TOTAL_APPS-1] = tempAppIndex;
            }
        }

		if(sMenuDataPtr->currentAppId > 0){
			sMenuDataPtr->currentAppId--;
        }
		else{
			sMenuDataPtr->currentAppId = NUM_APPS_PER_SCREEN-1;
            sMenuDataPtr->areYouOnSecondScreen = !sMenuDataPtr->areYouOnSecondScreen;
        }

		if(sMenuDataPtr->areYouOnSecondScreen){
            u8 tempAppIndex = sMenuDataPtr->currentAppId + NUM_APPS_PER_SCREEN;
            VarSet(CURRENT_APP_ID_VAR, tempAppIndex);
        }
        else{
            u8 tempAppIndex = sMenuDataPtr->currentAppId;
            VarSet(CURRENT_APP_ID_VAR, tempAppIndex);
        }

		PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}
	
	if(JOY_NEW(DPAD_DOWN))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && sMenuDataPtr->isAppSelectedForMove){
            if(CurrentApp > 0){
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp - 1];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp - 1] = tempAppIndex;
            }
            else{
                u8 tempAppIndex;
                tempAppIndex = gSaveBlock2Ptr->startMenuAppIndex[CurrentApp];
                gSaveBlock2Ptr->startMenuAppIndex[CurrentApp] = gSaveBlock2Ptr->startMenuAppIndex[NUM_TOTAL_APPS-1];
                gSaveBlock2Ptr->startMenuAppIndex[NUM_TOTAL_APPS-1] = tempAppIndex;
            }
        }

		if(sMenuDataPtr->currentAppId > 0){
			sMenuDataPtr->currentAppId--;
        }
		else{
			sMenuDataPtr->currentAppId = NUM_APPS_PER_SCREEN-1;
            sMenuDataPtr->areYouOnSecondScreen = !sMenuDataPtr->areYouOnSecondScreen;
        }
		PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if (JOY_NEW(A_BUTTON))
    {
        if(!FlagGet(FLAG_START_MENU_MOVE_MODE)){
            ClearStartMenuDataBeforeExit();
            switch(GetCurrentAppfromIndex(CurrentApp))
            {
                case APP_BAG:
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenBagFromStartMenu;
                break;
                case APP_POKEDEX:
                    if(GetCurrentSignal() != 0){
                        PlaySE(SE_SELECT);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_OpenPokedexFromStartMenu;
                    }
                    else{
                        PlaySE(SE_BOO);
                        sMenuDataPtr->shouldShowErrorMessage = TRUE;
                    }
					
                break;
                case APP_POKEMON:
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenPokemonPartyFromStartMenu;
                break;
                case APP_PROFILE:
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenTrainerCardFromStartMenu;
                break;
                case APP_OPTIONS:
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenOptionsMenuStartMenu;
                break;
                case APP_QUEST:
                    if(GetCurrentSignal() != 0){
                        PlaySE(SE_SELECT);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_QuestMenu_OpenFromStartMenu;
                    }
                    else{
                        PlaySE(SE_BOO);
                        sMenuDataPtr->shouldShowErrorMessage = TRUE;
                    }
                break;
                case APP_TWITTER:
                    if(GetCurrentSignal() != 0){
                        PlaySE(SE_PC_OFF);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_MenuTurnOff;
                    }
                    else{
                        PlaySE(SE_BOO);
                        sMenuDataPtr->shouldShowErrorMessage = TRUE;
                    }
                break;
                case APP_MAP:
                    if(GetCurrentSignal() != 0){
                        PlaySE(SE_SELECT);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_OpenPokenavStartMenu;
                    }
                    else{
                        PlaySE(SE_BOO);
                        sMenuDataPtr->shouldShowErrorMessage = TRUE;
                    }
                break;
                case APP_AMAZON:
                    if(GetCurrentSignal() != 0){
                        PlaySE(SE_SELECT);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_OpenAmazonStartMenu;
                    }
                    else{
                        PlaySE(SE_BOO);
                        sMenuDataPtr->shouldShowErrorMessage = TRUE;
                    }
                break;
                case APP_DEXNAV:
                    if(GetCurrentSignal() != 0){
                        /*/
                        This should be added when this branch merges with the one with the dexnav and the HasMapMons its a 
                        function that checks that there are wild encounter in that specific area since there were reports
                        of the game crashing with ghoulslash's dexnav if there are no pokemon in some emulators so I think
                        its safer to add this as a check 
                        remove everything else in this if when we merge the dexnav
                        if(HasMapMons()){
                            PlaySE(SE_SELECT);
                            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                            gTasks[taskId].func = Task_OpenDexNavFromStartMenu;
                        }
                        else{
                            PlaySE(SE_BOO);
                            sMenuDataPtr->shouldShowErrorMessage = TRUE;
                        }
                        */
                        PlaySE(SE_PC_OFF);
                        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                        gTasks[taskId].func = Task_MenuTurnOff;
                    }
                    else{
                        PlaySE(SE_BOO);
                        sMenuDataPtr->shouldShowErrorMessage = TRUE;
                    }
                break;
            }
        }
        else{
            FlagClear(FLAG_START_MENU_MOVE_MODE);
            sMenuDataPtr->isAppSelectedForMove = FALSE;
		    PlaySE(SE_SELECT);
        }

        PrintToWindow(WINDOW_1, FONT_BLACK);
    } 

    if(JOY_NEW(SELECT_BUTTON))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE)){
            FlagClear(FLAG_START_MENU_MOVE_MODE);
            sMenuDataPtr->isAppSelectedForMove = FALSE;
        }
        else{
            FlagSet(FLAG_START_MENU_MOVE_MODE);
            sMenuDataPtr->isAppSelectedForMove = TRUE;
        }
		PlaySE(SE_SELECT);
        StartMenuIndextoTempIndex();

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}
}
