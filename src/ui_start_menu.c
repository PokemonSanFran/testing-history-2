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
#include "quests.h"
#include "rtc.h"
#include "region_map.h"
#include "trainer_card.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text_window.h"
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

//Defines
#define  NUM_APPS_PER_SCREEN    5

//==========EWRAM==========//
static EWRAM_DATA struct MenuResources *sMenuDataPtr = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;
static EWRAM_DATA u8  currentAppId = 0;
static EWRAM_DATA bool8 areYouOnSecondScreen = FALSE;
static EWRAM_DATA bool8 isAppSelectedForMove = FALSE;

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
        .width = 29,        // width (per 8 pixels)
        .height = 19,       // height (per 8 pixels)
        .paletteNum = 0,   // palette index to use for text
        .baseBlock = 1,     // tile start in VRAM
    },
};

static const u32 sMenuTiles[]                   = INCBIN_U32("graphics/start_menu/tiles.4bpp.lz");
static const u32 sMenuTilemap[]                 = INCBIN_U32("graphics/start_menu/tilemap.bin.lz");
static const u16 sMenuPalette[]                 = INCBIN_U16("graphics/start_menu/palette.gbapal");
static const u8 sStartMenuCursor_Gfx[]          = INCBIN_U8("graphics/start_menu/menu_cursor.4bpp");
static const u8 sStartMenuCursorMoveMode_Gfx[]  = INCBIN_U8("graphics/start_menu/menu_cursor_move.4bpp");
static const u8 sStartMenuCursorMoveMode2_Gfx[] = INCBIN_U8("graphics/start_menu/menu_cursor_move2.4bpp");
static const u8 sStartMenuMoveModeText_Gfx[]    = INCBIN_U8("graphics/start_menu/move_mode.4bpp");
static const u8 sStartMenuRowIcon_Gfx[]         = INCBIN_U8("graphics/start_menu/menu_row_icon.4bpp");

enum Colors
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sMenuWindowFontColors[][3] = 
{
    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT,  15,  13},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT,  14,  13},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT,  11, 12},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT,  13, 14},
};

//==========FUNCTIONS==========//
// UI loader template
void Task_OpenMenuFromStartMenu(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    if (!gPaletteFade.active)
    {
        CleanupOverworldWindowsAndTilemaps();
        Menu_Init(CB2_ReturnToFieldWithOpenMenu);
        DestroyTask(taskId);
    }
}

// This is our main initialization function if you want to call the menu from elsewhere
void Menu_Init(MainCallback callback)
{
    if ((sMenuDataPtr = AllocZeroed(sizeof(struct MenuResources))) == NULL)
    {
        SetMainCallback2(callback);
        return;
    }

    // initialize stuff
    sMenuDataPtr->gfxLoadState = 0;
    sMenuDataPtr->savedCallback = callback;

    //Initialize the apps the first time you open the start menu
    if(!FlagGet(FLAG_START_MENU_SETUP)){
        u8 i;
        for(i = 0; i < NUM_TOTAL_APPS; i++){
            gSaveBlock2Ptr->startMenuAppIndex[i] = i;
        }
        FlagSet(FLAG_START_MENU_SETUP);
    }

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

static void PrintToWindow(u8 windowId, u8 colorIdx)
{
    const u8 *str_SelectedOption;
    const u8 *str_CurrentLocation = sText_Unknown_Location;
    u8 i, j;
    u8 CurrentApp = currentAppId;
    u8 x = 1;
    u8 y = 1;
    u8 hours = gLocalTime.hours;
	u8 minutes = gLocalTime.minutes;
    u8 strArray[16];

    // Current App Title
    x = 17;
    y = 10;

    if(areYouOnSecondScreen)
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
    AddTextPrinterParameterized4(windowId, 7, (x*8), (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, str_SelectedOption);

    // App Icons --------------------------------------------------------------------------------------------------------
    x = 3;
	y = 6;

    for(i = 0; i < NUM_APPS_PER_SCREEN; i++){
        if(areYouOnSecondScreen)
            j = i + NUM_APPS_PER_SCREEN;
        else
            j = i;

        switch(GetCurrentAppfromIndex(j)){
            case APP_POKEMON:
                BlitBitmapToWindow(windowId, sStartMenuApp_Pokemon_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_BAG:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Bag_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_MAP:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Map_Gfx, (x*8), (y*8), 24, 24);
            break;			
            case APP_QUEST:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Quest_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_DEXNAV:		
                BlitBitmapToWindow(windowId, sStartMenuApp_Dexnav_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_POKEDEX:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Pokedex_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_TWITTER:		
                BlitBitmapToWindow(windowId, sStartMenuApp_Twitter_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_OPTIONS:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Options_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_PROFILE:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Profile_Gfx, (x*8), (y*8), 24, 24);
            break;
            case APP_AMAZON:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Amazon_Gfx, (x*8), (y*8), 24, 24);
            break;
            default:	
                BlitBitmapToWindow(windowId, sStartMenuApp_Default_Gfx, (x*8), (y*8), 24, 24);
            break;
        }

        x = x + 4;

        if(i == 2)
            x++;
    }

    // Move Mode Text --------------------------------------------------------------------------------------------------------
    x = 5;
	y = 0;

    if(FlagGet(FLAG_START_MENU_MOVE_MODE))
        BlitBitmapToWindow(windowId, sStartMenuMoveModeText_Gfx, (x*8), (y*8), 72, 16);

    // Selection Sprite --------------------------------------------------------------------------------------------------------
	x = (currentAppId*4)+3;
	y = 6;

    if(!FlagGet(FLAG_START_MENU_MOVE_MODE)){
        if(currentAppId < 3)
            BlitBitmapToWindow(windowId, sStartMenuCursor_Gfx, (x*8), (y*8), 24, 24);
        else
            BlitBitmapToWindow(windowId, sStartMenuCursor_Gfx, ((x + 1)*8), (y*8), 24, 24);
    }
    else{
        if(currentAppId < 3)
            BlitBitmapToWindow(windowId, sStartMenuCursorMoveMode_Gfx, (x*8), (y*8), 24, 24);
        else
            BlitBitmapToWindow(windowId, sStartMenuCursorMoveMode_Gfx, ((x + 1)*8), (y*8), 24, 24);
    }

    // Screen Indicator --------------------------------------------------------------------------------------------------------
    x = 14;
    y = 10;

    if(areYouOnSecondScreen){
        CurrentApp = CurrentApp + 6;
        BlitBitmapToWindow(windowId, sStartMenuRowIcon_Gfx, ((x + 1)*8), (y*8), 8, 8);
    }
    else{
        BlitBitmapToWindow(windowId, sStartMenuRowIcon_Gfx, (x*8), (y*8), 8, 8);
    }

    //Time --------------------------------------------------------------------------------------------------------------------
	x = 18;
	y = 2;
	ConvertIntToDecimalStringN(gStringVar2, hours, STR_CONV_MODE_RIGHT_ALIGN, 2);
	ConvertIntToDecimalStringN(gStringVar3, minutes, STR_CONV_MODE_LEFT_ALIGN, 2);
	if(minutes >= 10)
		StringExpandPlaceholders(gStringVar4, Time);
	else
		StringExpandPlaceholders(gStringVar4, Time2);
	AddTextPrinterParameterized4(windowId, 7, (x*8)+4, (y*8) + 1, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar4);

    // Current Location --------------------------------------------------------------------------------------------------------------------
	x = 4;
	y = 10;
    GetMapNameGeneric(gStringVar1, gMapHeader.regionMapSectionId);
	AddTextPrinterParameterized4(windowId, 7, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, gStringVar1);

    // Quest Information --------------------------------------------------------------------------------------------------------------------
	x = 0;
	y = 14;
	AddTextPrinterParameterized4(windowId, 7, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_App_None);

    // ------------------------------------------------------------------------------------------------------------------------------------

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
			ShowPlayerTrainerCard(sMenuDataPtr->savedCallback); // Display trainer card
		else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
			ShowFrontierPass(sMenuDataPtr->savedCallback); // Display frontier pass
		else
			ShowPlayerTrainerCard(sMenuDataPtr->savedCallback); // Display trainer card
    }
}

void Task_OpenOptionsMenuStartMenu(u8 taskId)
{
    if (!gPaletteFade.active)
    {
		PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToField;
    }
}

static u8 GetCurrentAppfromIndex(u8 index)
{
    return gSaveBlock2Ptr->startMenuAppIndex[index];
}

static void ClearStartMenuDataBeforeExit()
{
    isAppSelectedForMove = FALSE;
    FlagClear(FLAG_START_MENU_MOVE_MODE);
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    u8 CurrentApp = currentAppId;

    if(areYouOnSecondScreen)
        CurrentApp = CurrentApp + NUM_APPS_PER_SCREEN;

    if (JOY_NEW(B_BUTTON) || JOY_NEW(START_BUTTON))
    {
        PlaySE(SE_PC_OFF);
        ClearStartMenuDataBeforeExit();
        BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
        gTasks[taskId].func = Task_MenuTurnOff;
    }

    if(JOY_NEW(DPAD_RIGHT))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && isAppSelectedForMove){
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

        if(currentAppId < NUM_APPS_PER_SCREEN-1){
            currentAppId++;
        }
        else{
            currentAppId = 0;
            areYouOnSecondScreen = !areYouOnSecondScreen;
        }
        PlaySE(SE_SELECT);
	}

    if(JOY_NEW(DPAD_LEFT))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE) && isAppSelectedForMove){
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

		if(currentAppId > 0){
			currentAppId--;
        }
		else{
			currentAppId = NUM_APPS_PER_SCREEN-1;
            areYouOnSecondScreen = !areYouOnSecondScreen;
        }
		PlaySE(SE_SELECT);
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
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_OpenPokedexFromStartMenu;
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
                    PlaySE(SE_SELECT);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_QuestMenu_OpenFromStartMenu;
                break;
                case APP_TWITTER:
                    PlaySE(SE_PC_OFF);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_MenuTurnOff;
                break;
                case APP_MAP:
                    PlaySE(SE_PC_OFF);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_MenuTurnOff;
                break;
                case APP_AMAZON:
                    PlaySE(SE_PC_OFF);
                    BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
                    gTasks[taskId].func = Task_MenuTurnOff;
                break;
            }
        }
        else{
            isAppSelectedForMove = !isAppSelectedForMove;
            PlaySE(SE_SELECT);
        }
    } 

    if(JOY_NEW(SELECT_BUTTON))
	{
        if(FlagGet(FLAG_START_MENU_MOVE_MODE))
            FlagClear(FLAG_START_MENU_MOVE_MODE);
        else
            FlagSet(FLAG_START_MENU_MOVE_MODE);
        
        isAppSelectedForMove = FALSE;
		PlaySE(SE_SELECT);
	}
	
	PrintToWindow(WINDOW_1, FONT_BLACK);
}