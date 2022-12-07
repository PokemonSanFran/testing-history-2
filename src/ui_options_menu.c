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
#include "main_menu.h"
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
#define  MAX_OPTIONS_PER_SETTING                    100 // For the Volume Options

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
static EWRAM_DATA bool8 ShouldShowDiscardDialogue = FALSE;
static EWRAM_DATA u8  currentOptionId = 0;
static EWRAM_DATA u8  currentScreenId = 0;
static EWRAM_DATA u8  currentFirstOption = 0;
static EWRAM_DATA bool8 areYouNotOnSettingsHub = FALSE;

//static EWRAM_DATA u8 Temporal_Options_Preset_Settings[NUM_OF_PRESET_OPTIONS];       //This is a temporal data used for the Discard Feature on Leave Dialog
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

static void HandlePresetData();
static void ChangePresetDataToCustom();

static void CopySaveBlockDataToTemporalData();
static void CopyTemporalDataToSaveBlockData();
static void ResetSaveBlocData();
bool8 AreYouOnCustomPresetData();

void CopyTemporalDataToSaveBlockData()
{
    u8 i, j;

    for(i = 0 ;i < NUM_OF_PRESET_OPTIONS; i++){
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

void ResetSaveBlocData()
{
    u8 i, j;

    for(i = 0 ;i < NUM_OF_PRESET_OPTIONS; i++){
        switch(i){
            case GAME_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_GAME_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsGame[j] = 0;
                }
            break;
            case BATTLE_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_BATTLE_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsBattle[j] = 0;
                }
            break;
            case VISUAL_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_VISUAL_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsVisual[j] = 0;
                }
            break;
            case MUSIC_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_MUSIC_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsMusic[j] = 0;
                }
            break;
            case RANDOM_SETTINGS:
                for(j = 0 ;j < NUM_OPTIONS_RANDOM_SETTINGS; j++){
                    gSaveBlock2Ptr->optionsRandom[j] = 0;
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
static const u16 sMenuPalette[] = INCBIN_U16("graphics/ui_menus/options_menu/palette_custom.gbapal");

static const u16 sMenuPalette_Red[]      = INCBIN_U16("graphics/ui_menus/options_menu/palettes/red.gbapal");
static const u16 sMenuPalette_Black[]    = INCBIN_U16("graphics/ui_menus/options_menu/palettes/black.gbapal");
static const u16 sMenuPalette_Green[]    = INCBIN_U16("graphics/ui_menus/options_menu/palettes/green.gbapal");
static const u16 sMenuPalette_Blue[]     = INCBIN_U16("graphics/ui_menus/options_menu/palettes/blue.gbapal");
static const u16 sMenuPalette_Platinum[] = INCBIN_U16("graphics/ui_menus/options_menu/palettes/platinum.gbapal");
static const u16 sMenuPalette_Scarlet[]  = INCBIN_U16("graphics/ui_menus/options_menu/palettes/scarlet.gbapal");
static const u16 sMenuPalette_Violet[]   = INCBIN_U16("graphics/ui_menus/options_menu/palettes/violet.gbapal");
static const u16 sMenuPalette_White[]    = INCBIN_U16("graphics/ui_menus/options_menu/palettes/white.gbapal");
static const u16 sMenuPalette_Yellow[]   = INCBIN_U16("graphics/ui_menus/options_menu/palettes/yellow.gbapal");
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

void CB2_InitUIOptionMenu(void)
{
    s32 i;

    ResetSpriteData();
    FreeAllSpritePalettes();
    ResetTasks();
    ResetBgsAndClearDma3BusyFlags(0);
    DeactivateAllTextPrinters();

    for (i = 0; i < 2; i++)
        FillWindowPixelBuffer(i, PIXEL_FILL(0));

    FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, DISPLAY_TILE_WIDTH, DISPLAY_TILE_HEIGHT);
    LoadUserWindowBorderGfx(0, 1u, 0xD0u);
    Menu_LoadStdPalAt(0xE0);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    StopMapMusic();
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    RunTextPrinters();
    UpdatePaletteFade();
    FillPalette(RGB_BLACK, 0, 2);
    Options_Menu_Init(CB2_InitMainMenu);
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
    FlagClear(FLAG_OPTION_MENU_SETUP);

    //Initializes Data for the First Time
    if(!FlagGet(FLAG_OPTION_MENU_SETUP)){
        ResetSaveBlocData();
        ChangePresetDataToCustom();
        FlagSet(FLAG_OPTION_MENU_SETUP);
    }

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

    ShouldShowDiscardDialogue = FALSE;

    try_free(ShouldShowDiscardDialogue);
    try_free(currentOptionId);
    try_free(currentScreenId);
    try_free(currentFirstOption);
    try_free(areYouNotOnSettingsHub);

    //try_free(Temporal_Options_Preset_Settings);
    try_free(Temporal_Options_Game_Settings);
    try_free(Temporal_Options_Battle_Settings);
    try_free(Temporal_Options_Music_Settings);
    try_free(Temporal_Options_Visual_Settings);
    try_free(Temporal_Options_Random_Settings);
    
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
        currentOptionId++;
    }
	else if(currentOptionId >= (GetCurrentScreenOptionNumber() - 1)){ //If you are in the last option go to the first one
		currentOptionId = 0;
		currentFirstOption = 0;
    }
    else if(currentOptionId >= (finalhalfScreen - 1)){
        currentOptionId++;
    }
	else{
        currentOptionId++;
        currentFirstOption++;
    }
}

static void PressedUpButton(){
    u8 halfScreen = ((NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN) - 1) / 2;
    u8 finalhalfScreen = GetCurrentScreenOptionNumber() - halfScreen;
    u8 cursorPosition = (currentOptionId - currentFirstOption);

    if(currentOptionId > halfScreen && currentOptionId <= (finalhalfScreen - 1)){
        currentOptionId--;
        currentFirstOption--;
    }
	else if(currentOptionId == 0){ //If you are in the first option go to the last one
		currentOptionId = GetCurrentScreenOptionNumber() - 1;
		currentFirstOption = GetCurrentScreenOptionNumber() - NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN;
    }
    else{
        currentOptionId--;
    }
}

#define OPTION_NAME_LENGTH 20
#define MAX_OPTION_DESCRIPTION_LENGTH 100

struct OptionData
{
    const u8 title[OPTION_NAME_LENGTH];
    const u8 options[OPTION_NAME_LENGTH][MAX_OPTIONS_PER_SETTING];
    const u8 optionDescription[MAX_OPTION_DESCRIPTION_LENGTH][MAX_OPTIONS_PER_SETTING];
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


static const u8 sText_Discard_Text[]        = _("Are you sure you want to leave without\nsaving the changes?");

static const u8 sText_Help_Bar_Discard[]        = _("{A_BUTTON} Yes {B_BUTTON} Cancel {START_BUTTON} Save");
static const u8 sText_Help_Bar_Settings_Hub[]   = _("{DPAD_LEFTRIGHT} Preset {A_BUTTON} Explore {B_BUTTON} Discard {START_BUTTON} Save");
static const u8 sText_Help_Bar_Settings_Page[]  = _("{DPAD_LEFTRIGHT} Change {B_BUTTON} Discard {START_BUTTON} Save {L_BUTTON}{R_BUTTON} Next Page");
// Preset

struct OptionData Hub_Options[NUM_OF_PRESET_OPTIONS] = {
    [GAME_SETTINGS] =
    {
        .title = _("Game Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Speedrun Description"),
            _("Custom Description"),
            },
        .numOptions = 3,
    },
    [BATTLE_SETTINGS] =
    {
        .title = _("Battle Settings"),
        .options = { 
            _("Default"),
            _("Challenge"),
            _("Speedrun"),
            _("Nuzlocke"),
            _("Kaizo"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Challenge Description"),
            _("Speedrun Description"),
            _("Nuzlocke Description"),
            _("Kaizo Description"),
            _("Custom Description"),
            },
        .numOptions = 6,
    },
    [VISUAL_SETTINGS] =
    {
        .title = _("Visual Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Speedrun Description"),
            _("Custom Description"),
            },
        .numOptions = 3,
    },
    [MUSIC_SETTINGS] =
    {
        .title = _("Music Settings"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            _("Custom"),
            },
        .optionDescription = { 
            _("PSF Description"),
            _("LGPE Description"),
            _("HGSS Description"),
            _("ORAS Description"),
            _("BDSP Description"),
            _("BW2 Description"),
            _("XY Description"),
            _("USUM Description"),
            _("SWSH Description"),
            _("SV Description"),
            _("Custom Description"),
            },
        .numOptions = 11,
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
        .optionDescription = { 
            _("Default Description"),
            _("Sane Description"),
            _("Crazy Description"),
            _("Total Chaos Description"),
            _("Custom Description"),
            },
        .numOptions = 5,
    },
};

enum GamePresetOptionsID
{
    GAME_PRESET_DEFAULT,
    GAME_PRESET_SPEEDRUN,
    GAME_PRESET_CUSTOM,
};

enum BattlePresetOptionsID
{
    BATTLE_PRESET_DEFAULT,
    BATTLE_PRESET_CHALLENGE,
    BATTLE_PRESET_SPEEDRUN,
    BATTLE_PRESET_NUZLOCKE,
    BATTLE_PRESET_KAIZO,
    BATTLE_PRESET_CUSTOM,
};

enum VisualPresetOptionsID
{
    VISUAL_PRESET_DEFAULT,
    VISUAL_PRESET_SPEEDRUN,
    VISUAL_PRESET_CUSTOM,
};

enum MusicPresetOptionsID
{
    MUSIC_PRESET_DEFAULT,
    MUSIC_PRESET_LGPE,
    MUSIC_PRESET_HGSS,
    MUSIC_PRESET_ORAS,
    MUSIC_PRESET_BDSP,
    MUSIC_PRESET_BW2,
    MUSIC_PRESET_XY,
    MUSIC_PRESET_USUM,
    MUSIC_PRESET_SWSH,
    MUSIC_PRESET_SV,
    MUSIC_PRESET_CUSTOM,
};

enum RandomPresetOptionsID
{
    RANDOM_PRESET_DEFAULT,
    RANDOM_PRESET_SANE,
    RANDOM_PRESET_CRAZY,
    RANDOM_PRESET_TOTAL_CHAOS,
    RANDOM_PRESET_CUSTOM,
};

enum RandomOptionsForOptionsMenu
{
    RANDOM_DEFAULT,
    RANDOM_RANDOM,
    RANDOM_CHAOS,
};

#define MAX_VOLUME 19

static u8 Preset_Options[NUM_OF_PRESET_OPTIONS][NUM_MAX_SETTINGS][MAX_OPTIONS_PER_SETTING] = {
    [GAME_SETTINGS] =
    {
        [GAME_PRESET_DEFAULT]  = {
            [GAME_OPTIONS_PRESET]            = GAME_PRESET_DEFAULT, 
            [GAME_OPTIONS_SAVE_BOOT]         = 1, 
            [GAME_OPTIONS_BUTTON_MODE]       = 1, 
            [GAME_OPTIONS_SAVE_BEHAVIOR]     = 1, 
            [GAME_OPTIONS_RUN]               = 1, 
            [GAME_OPTIONS_PUZZLE_DIFFICULTY] = 0, 
            [GAME_OPTIONS_ITEM_SORT]         = 2
        },
        [GAME_PRESET_SPEEDRUN] = {
            [GAME_OPTIONS_PRESET]            = GAME_PRESET_SPEEDRUN, 
            [GAME_OPTIONS_SAVE_BOOT]         = 1, 
            [GAME_OPTIONS_BUTTON_MODE]       = 1, 
            [GAME_OPTIONS_SAVE_BEHAVIOR]     = 1, 
            [GAME_OPTIONS_RUN]               = 2, 
            [GAME_OPTIONS_PUZZLE_DIFFICULTY] = 0, 
            [GAME_OPTIONS_ITEM_SORT]         = 4
        }
    },
    [BATTLE_SETTINGS] =
    {
        [BATTLE_PRESET_DEFAULT]  = {
            [BATTLE_OPTIONS_PRESET]                 = BATTLE_PRESET_DEFAULT, 
            [BATTLE_OPTIONS_EXPERIENCE]             = 0, 
            [BATTLE_OPTIONS_EXP_MULTIPLIER]         = 0, 
            [BATTLE_OPTIONS_LEVEL]                  = 0, 
            [BATTLE_OPTIONS_SWITCH_STYLE]           = 0, 
            [BATTLE_OPTIONS_TAKE_WILD_ITEMS]        = 0, 
            [BATTLE_OPTIONS_LAST_USED_BALL]         = 0,
            [BATTLE_OPTIONS_QUICK_RUN]              = 0, 
            [BATTLE_OPTIONS_BATTLE_DIFFICULTY]      = 0, 
            [BATTLE_OPTIONS_FAINTED_MON]            = 0, 
            [BATTLE_OPTIONS_FIRST_POKEMON_CATCH]    = 0, 
            [BATTLE_OPTIONS_NICKNAME]               = 0, 
            [BATTLE_OPTIONS_WITHEOUT]               = 0,
            [BATTLE_OPTIONS_ITEM_HEALING]           = 0, 
            [BATTLE_OPTIONS_CENTER_HEALING]         = 0, 
            [BATTLE_OPTIONS_MOVE_HEALING]           = 0, 
            [BATTLE_OPTIONS_BAG_ITEMS]              = 0, 
            [BATTLE_OPTIONS_OPPONENTS_ITEMS]        = 0, 
            [BATTLE_OPTIONS_BASE_STAT_EQUALIZER]    = 0,
            [BATTLE_OPTIONS_ONE_TYPE_CHALLENGE]     = 0, 
            [BATTLE_OPTIONS_TYPE_ICONS]             = 0, 
            [BATTLE_OPTIONS_ANIMATIONS]             = 0, 
            [BATTLE_OPTIONS_INTRO]                  = 0, 
            [BATTLE_OPTIONS_HP_SPEED]               = 0, 
            [BATTLE_OPTIONS_EXP_SPEED]              = 0
        },
        [BATTLE_PRESET_SPEEDRUN]  = {
            [BATTLE_OPTIONS_PRESET]                 = BATTLE_PRESET_SPEEDRUN, 
            [BATTLE_OPTIONS_EXPERIENCE]             = 0, 
            [BATTLE_OPTIONS_EXP_MULTIPLIER]         = 0, 
            [BATTLE_OPTIONS_LEVEL]                  = 0, 
            [BATTLE_OPTIONS_SWITCH_STYLE]           = 0, 
            [BATTLE_OPTIONS_TAKE_WILD_ITEMS]        = 0, 
            [BATTLE_OPTIONS_LAST_USED_BALL]         = 0,
            [BATTLE_OPTIONS_QUICK_RUN]              = 0, 
            [BATTLE_OPTIONS_BATTLE_DIFFICULTY]      = 0, 
            [BATTLE_OPTIONS_FAINTED_MON]            = 0, 
            [BATTLE_OPTIONS_FIRST_POKEMON_CATCH]    = 0, 
            [BATTLE_OPTIONS_NICKNAME]               = 0, 
            [BATTLE_OPTIONS_WITHEOUT]               = 0,
            [BATTLE_OPTIONS_ITEM_HEALING]           = 0, 
            [BATTLE_OPTIONS_CENTER_HEALING]         = 0, 
            [BATTLE_OPTIONS_MOVE_HEALING]           = 0, 
            [BATTLE_OPTIONS_BAG_ITEMS]              = 0, 
            [BATTLE_OPTIONS_OPPONENTS_ITEMS]        = 0, 
            [BATTLE_OPTIONS_BASE_STAT_EQUALIZER]    = 0,
            [BATTLE_OPTIONS_ONE_TYPE_CHALLENGE]     = 0, 
            [BATTLE_OPTIONS_TYPE_ICONS]             = 0, 
            [BATTLE_OPTIONS_ANIMATIONS]             = 0, 
            [BATTLE_OPTIONS_INTRO]                  = 0, 
            [BATTLE_OPTIONS_HP_SPEED]               = 0, 
            [BATTLE_OPTIONS_EXP_SPEED]              = 0
        },
        [BATTLE_PRESET_NUZLOCKE]  = {
            [BATTLE_OPTIONS_PRESET]                 = BATTLE_PRESET_NUZLOCKE, 
            [BATTLE_OPTIONS_EXPERIENCE]             = 0, 
            [BATTLE_OPTIONS_EXP_MULTIPLIER]         = 0, 
            [BATTLE_OPTIONS_LEVEL]                  = 0, 
            [BATTLE_OPTIONS_SWITCH_STYLE]           = 0, 
            [BATTLE_OPTIONS_TAKE_WILD_ITEMS]        = 0, 
            [BATTLE_OPTIONS_LAST_USED_BALL]         = 0,
            [BATTLE_OPTIONS_QUICK_RUN]              = 0, 
            [BATTLE_OPTIONS_BATTLE_DIFFICULTY]      = 0, 
            [BATTLE_OPTIONS_FAINTED_MON]            = 0, 
            [BATTLE_OPTIONS_FIRST_POKEMON_CATCH]    = 0, 
            [BATTLE_OPTIONS_NICKNAME]               = 0, 
            [BATTLE_OPTIONS_WITHEOUT]               = 0,
            [BATTLE_OPTIONS_ITEM_HEALING]           = 0, 
            [BATTLE_OPTIONS_CENTER_HEALING]         = 0, 
            [BATTLE_OPTIONS_MOVE_HEALING]           = 0, 
            [BATTLE_OPTIONS_BAG_ITEMS]              = 0, 
            [BATTLE_OPTIONS_OPPONENTS_ITEMS]        = 0, 
            [BATTLE_OPTIONS_BASE_STAT_EQUALIZER]    = 0,
            [BATTLE_OPTIONS_ONE_TYPE_CHALLENGE]     = 0, 
            [BATTLE_OPTIONS_TYPE_ICONS]             = 0, 
            [BATTLE_OPTIONS_ANIMATIONS]             = 0, 
            [BATTLE_OPTIONS_INTRO]                  = 0, 
            [BATTLE_OPTIONS_HP_SPEED]               = 0, 
            [BATTLE_OPTIONS_EXP_SPEED]              = 0
        },
        [BATTLE_PRESET_KAIZO]  = {
            [BATTLE_OPTIONS_PRESET]                 = BATTLE_PRESET_KAIZO, 
            [BATTLE_OPTIONS_EXPERIENCE]             = 0, 
            [BATTLE_OPTIONS_EXP_MULTIPLIER]         = 0, 
            [BATTLE_OPTIONS_LEVEL]                  = 0, 
            [BATTLE_OPTIONS_SWITCH_STYLE]           = 0, 
            [BATTLE_OPTIONS_TAKE_WILD_ITEMS]        = 0, 
            [BATTLE_OPTIONS_LAST_USED_BALL]         = 0,
            [BATTLE_OPTIONS_QUICK_RUN]              = 0, 
            [BATTLE_OPTIONS_BATTLE_DIFFICULTY]      = 0, 
            [BATTLE_OPTIONS_FAINTED_MON]            = 0, 
            [BATTLE_OPTIONS_FIRST_POKEMON_CATCH]    = 0, 
            [BATTLE_OPTIONS_NICKNAME]               = 0, 
            [BATTLE_OPTIONS_WITHEOUT]               = 0,
            [BATTLE_OPTIONS_ITEM_HEALING]           = 0, 
            [BATTLE_OPTIONS_CENTER_HEALING]         = 0, 
            [BATTLE_OPTIONS_MOVE_HEALING]           = 0, 
            [BATTLE_OPTIONS_BAG_ITEMS]              = 0, 
            [BATTLE_OPTIONS_OPPONENTS_ITEMS]        = 0, 
            [BATTLE_OPTIONS_BASE_STAT_EQUALIZER]    = 0,
            [BATTLE_OPTIONS_ONE_TYPE_CHALLENGE]     = 0, 
            [BATTLE_OPTIONS_TYPE_ICONS]             = 0, 
            [BATTLE_OPTIONS_ANIMATIONS]             = 0, 
            [BATTLE_OPTIONS_INTRO]                  = 0, 
            [BATTLE_OPTIONS_HP_SPEED]               = 0, 
            [BATTLE_OPTIONS_EXP_SPEED]              = 0
        },
    },
    [VISUAL_SETTINGS] =
    {
        [VISUAL_PRESET_DEFAULT]  = {
            [VISUAL_OPTIONS_PRESET]          = VISUAL_PRESET_DEFAULT, 
            [VISUAL_OPTIONS_UNITS]           = 1, 
            [VISUAL_OPTIONS_TEXT_SPEED]      = 2, 
            [VISUAL_OPTIONS_FRAME_TYPE]      = 0, 
            [VISUAL_OPTIONS_FONT_SWITCHER]   = 0, 
            [VISUAL_OPTIONS_COLOR]           = 6, 
        },
        [VISUAL_PRESET_SPEEDRUN] = {
            [VISUAL_OPTIONS_PRESET]          = VISUAL_PRESET_SPEEDRUN, 
            [VISUAL_OPTIONS_UNITS]           = 1, 
            [VISUAL_OPTIONS_TEXT_SPEED]      = 4, 
            [VISUAL_OPTIONS_FRAME_TYPE]      = 0, 
            [VISUAL_OPTIONS_FONT_SWITCHER]   = 0, 
            [VISUAL_OPTIONS_COLOR]           = 6, 
        }
    },
    [MUSIC_SETTINGS] =
    {
        [MUSIC_PRESET_DEFAULT]  = {
            [MUSIC_OPTIONS_PRESET]          = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_DEFAULT, 
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_DEFAULT, 
        },
        [MUSIC_PRESET_LGPE]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_LGPE, 
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_LGPE, 
        },
        [MUSIC_PRESET_HGSS]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_HGSS, 
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_HGSS, 
        },
        [MUSIC_PRESET_ORAS]  = {
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_ORAS, 
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_ORAS, 
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_ORAS, 
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_ORAS, 
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_ORAS, 
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_ORAS, 
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_ORAS, 
        },
        [MUSIC_PRESET_BDSP]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_BDSP, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_BDSP,
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_BDSP,
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_BDSP,
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_BDSP,
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_BDSP,
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_BDSP,
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_BDSP,
        },
        [MUSIC_PRESET_BW2]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_BW2, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME,
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_BW2,
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_BW2,
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_BW2,
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_BW2,
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_BW2,
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_BW2,
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_BW2,
        },
        [MUSIC_PRESET_XY]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_XY, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_XY,
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_XY,
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_XY,
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_XY,
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_XY,
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_XY,
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_XY,
        },
        [MUSIC_PRESET_USUM]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_USUM, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME,
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_USUM,
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_USUM,
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_USUM,
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_USUM,
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_USUM,
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_USUM,
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_USUM,
        },
        [MUSIC_PRESET_SWSH]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_SWSH, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME,
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_SWSH,
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_SWSH,
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_SWSH,
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_SWSH,
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_SWSH,
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_SWSH,
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_SWSH,
        },
        [MUSIC_PRESET_SV]  = {
            [MUSIC_OPTIONS_PRESET]           = MUSIC_PRESET_SV, 
            [MUSIC_OPTIONS_SOUND_EFFECT]     = MAX_VOLUME, 
            [MUSIC_OPTIONS_MUSIC]            = MAX_VOLUME, 
            [MUSIC_OPTIONS_SPEAKER]          = OPTIONS_SOUND_STEREO,
            [MUSIC_OPTIONS_SURF]             = MUSIC_PRESET_DEFAULT,
            [MUSIC_OPTIONS_BIKE]             = MUSIC_PRESET_DEFAULT,
            [MUSIC_OPTIONS_WILD]             = MUSIC_PRESET_SV,
            [MUSIC_OPTIONS_TRAINER]          = MUSIC_PRESET_SV,
            [MUSIC_OPTIONS_GYM]              = MUSIC_PRESET_SV,
            [MUSIC_OPTIONS_TOURNAMENT]       = MUSIC_PRESET_SV,
            [MUSIC_OPTIONS_CHAMPION]         = MUSIC_PRESET_SV,
        },
    }, 
    [RANDOM_SETTINGS] =
    {
        [RANDOM_PRESET_DEFAULT]  = {
            [RANDOM_OPTIONS_PRESET]             = RANDOM_PRESET_DEFAULT, 
            [RANDOM_OPTIONS_STARTER]            = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_WILD_BATTLE]        = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TRAINER_BATTLE]     = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_EVOLUTION]          = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_EVOLUTION_METHOD]   = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TYPE_EFFECTIVENESS] = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_BASE_STATS]         = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TYPES]              = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_ABILITIES]          = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_LEVEL_UP_MOVES]     = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TMS]                = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_MOVE_TUTORS]        = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_LEARNSETS]          = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_ITEMS]              = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_STATIC_ENCOUNTERS]  = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TRAINERS]           = RANDOM_DEFAULT, 
        },
        [RANDOM_PRESET_SANE]  = {
            [RANDOM_OPTIONS_PRESET]             = RANDOM_PRESET_SANE, 
            [RANDOM_OPTIONS_STARTER]            = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_WILD_BATTLE]        = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_TRAINER_BATTLE]     = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_EVOLUTION]          = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_EVOLUTION_METHOD]   = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TYPE_EFFECTIVENESS] = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_BASE_STATS]         = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TYPES]              = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_ABILITIES]          = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_LEVEL_UP_MOVES]     = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TMS]                = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_MOVE_TUTORS]        = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_LEARNSETS]          = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_ITEMS]              = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_STATIC_ENCOUNTERS]  = RANDOM_DEFAULT, 
            [RANDOM_OPTIONS_TRAINERS]           = RANDOM_DEFAULT, 
        },
        [RANDOM_PRESET_CRAZY]  = {
            [RANDOM_OPTIONS_PRESET]             = RANDOM_PRESET_CRAZY, 
            [RANDOM_OPTIONS_STARTER]            = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_WILD_BATTLE]        = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_TRAINER_BATTLE]     = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_EVOLUTION]          = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_EVOLUTION_METHOD]   = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_TYPE_EFFECTIVENESS] = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_BASE_STATS]         = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_TYPES]              = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_ABILITIES]          = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_LEVEL_UP_MOVES]     = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_TMS]                = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_MOVE_TUTORS]        = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_LEARNSETS]          = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_ITEMS]              = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_STATIC_ENCOUNTERS]  = RANDOM_RANDOM, 
            [RANDOM_OPTIONS_TRAINERS]           = RANDOM_RANDOM, 
        },
        [RANDOM_PRESET_TOTAL_CHAOS]  = {
            [RANDOM_OPTIONS_PRESET]             = RANDOM_PRESET_TOTAL_CHAOS, 
            [RANDOM_OPTIONS_STARTER]            = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_WILD_BATTLE]        = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_TRAINER_BATTLE]     = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_EVOLUTION]          = RANDOM_CHAOS + 1, 
            [RANDOM_OPTIONS_EVOLUTION_METHOD]   = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_TYPE_EFFECTIVENESS] = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_BASE_STATS]         = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_TYPES]              = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_ABILITIES]          = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_LEVEL_UP_MOVES]     = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_TMS]                = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_MOVE_TUTORS]        = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_LEARNSETS]          = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_ITEMS]              = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_STATIC_ENCOUNTERS]  = RANDOM_CHAOS, 
            [RANDOM_OPTIONS_TRAINERS]           = RANDOM_CHAOS, 
        },
    },
};

void HandlePresetData()
{
    u8 i, j;

    if(AreYouOnCustomPresetData()){
        switch(currentScreenId){
            case GAME_SETTINGS:
                for(i = 1 ;i < NUM_OPTIONS_GAME_SETTINGS; i++){
                    Temporal_Options_Game_Settings[i] = gSaveBlock2Ptr->optionsGame[i];
                }
            break;
            case BATTLE_SETTINGS:
                for(i = 1 ;i < NUM_OPTIONS_BATTLE_SETTINGS; i++){
                    Temporal_Options_Battle_Settings[i] = gSaveBlock2Ptr->optionsBattle[i];
                }
            break;
            case VISUAL_SETTINGS:
                for(i = 1 ;i < NUM_OPTIONS_VISUAL_SETTINGS; i++){
                    Temporal_Options_Visual_Settings[i] = gSaveBlock2Ptr->optionsVisual[i];
                }
            break;
            case MUSIC_SETTINGS:
                for(i = 1 ;i < NUM_OPTIONS_MUSIC_SETTINGS; i++){
                    Temporal_Options_Music_Settings[i] = gSaveBlock2Ptr->optionsMusic[i];
                }
            break;
            case RANDOM_SETTINGS:
                for(i = 1 ;i < NUM_OPTIONS_RANDOM_SETTINGS; i++){
                    Temporal_Options_Random_Settings[i] = gSaveBlock2Ptr->optionsRandom[i];
                }
            break;
        }
    }
    else{
        switch(currentScreenId){
            case GAME_SETTINGS:
                for(i = 0 ;i < NUM_OPTIONS_GAME_SETTINGS; i++){
                    Temporal_Options_Game_Settings[i] = Preset_Options[GAME_SETTINGS][Temporal_Options_Game_Settings[0]][i];
                }
            break;
            case BATTLE_SETTINGS:
                for(i = 0 ;i < NUM_OPTIONS_BATTLE_SETTINGS; i++){
                    Temporal_Options_Battle_Settings[i] = Preset_Options[BATTLE_SETTINGS][Temporal_Options_Battle_Settings[0]][i];
                }
            break;
            case VISUAL_SETTINGS:
                for(i = 0 ;i < NUM_OPTIONS_VISUAL_SETTINGS; i++){
                    Temporal_Options_Visual_Settings[i] = Preset_Options[VISUAL_SETTINGS][Temporal_Options_Visual_Settings[0]][i];
                }
            break;
            case MUSIC_SETTINGS:
                for(i = 0 ;i < NUM_OPTIONS_MUSIC_SETTINGS; i++){
                    Temporal_Options_Music_Settings[i] = Preset_Options[MUSIC_SETTINGS][Temporal_Options_Music_Settings[0]][i];
                }
            break;
            case RANDOM_SETTINGS:
                for(i = 0 ;i < NUM_OPTIONS_RANDOM_SETTINGS; i++){
                    Temporal_Options_Random_Settings[i] = Preset_Options[RANDOM_SETTINGS][Temporal_Options_Random_Settings[0]][i];
                }
            break;
        }
    }
}

bool8 AreYouOnCustomPresetData()
{
    switch(currentScreenId){
        case GAME_SETTINGS:
            return (Temporal_Options_Game_Settings[0] == GAME_PRESET_CUSTOM);
        break;
        case BATTLE_SETTINGS:
            return (Temporal_Options_Battle_Settings[0] == BATTLE_PRESET_CUSTOM);
        break;
         case VISUAL_SETTINGS:
            return (Temporal_Options_Visual_Settings[0] == VISUAL_PRESET_CUSTOM);
        break;
        case MUSIC_SETTINGS:
            return (Temporal_Options_Music_Settings[0] == MUSIC_PRESET_CUSTOM);
        break;
        case RANDOM_SETTINGS:
            return (Temporal_Options_Random_Settings[0] == RANDOM_PRESET_CUSTOM);
        break;
    }
}

void ChangePresetDataToCustom()
{
    gSaveBlock2Ptr->optionsGame[0] = GAME_PRESET_CUSTOM;
    gSaveBlock2Ptr->optionsBattle[0] = BATTLE_PRESET_CUSTOM;
    gSaveBlock2Ptr->optionsVisual[0] = VISUAL_PRESET_CUSTOM;
    gSaveBlock2Ptr->optionsMusic[0] = MUSIC_PRESET_CUSTOM;
    gSaveBlock2Ptr->optionsRandom[0] = RANDOM_PRESET_CUSTOM;
}

// For Game Settings asdf
struct OptionData GameSettings_Settings_Options[NUM_OPTIONS_GAME_SETTINGS] = {
    [GAME_OPTIONS_PRESET] =
    {
        .title = _("Game Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Speedrun Description"),
            _("Custom Description"),
            },
        .numOptions = 3,
    },
    [GAME_OPTIONS_SAVE_BOOT] =
    {
        .title = _("Save Boot"),
        .options = { 
            _("Traditional"),
            _("Continue"),
            },
        .optionDescription = { 
            _("Traditional Description"),
            _("Continue Description"),
            },
        .numOptions = 2,
    },
    [GAME_OPTIONS_BUTTON_MODE] =
    {
        .title = _("Button Mode"),
        .options = { 
            _("Normal"),
            _("{L_BUTTON}{R_BUTTON}"),
            _("{L_BUTTON} {EMOJI_EQUALS} {A_BUTTON}"),
            },
        .optionDescription = { 
            _("Normal Description"),
            _("{L_BUTTON}{R_BUTTON} Description"),
            _("{L_BUTTON} {EMOJI_EQUALS} {A_BUTTON} Description"),
            },
        .numOptions = 3,
    },
    [GAME_OPTIONS_SAVE_BEHAVIOR] =
    {
        .title = _("Save Behavior"),
        .options = { 
            _("Automatic"),
            _("Manual"),
            },
        .optionDescription = { 
            _("Automatic Description"),
            _("Manual Description"),
            },
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
        .optionDescription = { 
            _("Always Description"),
            _("Toogle Description"),
            _("Manual Description"),
            },
        .numOptions = 3,
    },
    [GAME_OPTIONS_PUZZLE_DIFFICULTY] =
    {
        .title = _("Puzzle Difficulty"),
        .options = { 
            _("Normal"),
            _("Easy"),
            },
        .optionDescription = { 
            _("Normal Description"),
            _("Easy Description"),
            },
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
        .optionDescription = { 
            _("Off"),
            _("Name"),
            _("Type"),
            _("Amount"),
            _("Recency"),
            },
        .numOptions = 5,
    },
};

// For Battle Settings

struct OptionData BattleSettings_Settings_Options[NUM_OPTIONS_BATTLE_SETTINGS] = {
    [BATTLE_OPTIONS_PRESET] =
    {
        .title = _("Battle Settings"),
        .options = { 
            _("Default"),
            _("Challenge"),
            _("Speedrun"),
            _("Nuzlocke"),
            _("Kaizo"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Challenge Description"),
            _("Speedrun Description"),
            _("Nuzlocke Description"),
            _("Kaizo Description"),
            _("Custom Description"),
            },
        .numOptions = 6,
    },
    [BATTLE_OPTIONS_EXPERIENCE] =
    {
        .title = _("Experience"),
        .options = { 
                _("All"),
                _("Party"),
                _("Active"),
            },
        .optionDescription = { 
                _("All"),
                _("Party"),
                _("Active"),
            },
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
        .optionDescription = { 
                _("Normal"),
                _("1.5"),
                _("2"),
                _("0"),
            },
        .numOptions = 4,
    },
    [BATTLE_OPTIONS_LEVEL] =
    {
        .title = _("Level"),
        .options = { 
                _("Level Cap"),
                _("No Cap"),
            },
        .optionDescription = { 
                _("Level Cap"),
                _("No Cap"),
            },
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_SWITCH_STYLE] =
    {
        .title = _("Switch Style"),
        .options = { 
            _("Shift"),
            _("Set"),
            },
        .optionDescription = { 
            _("Shift"),
            _("Set"),
            },
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
        .optionDescription = { 
                _("Never"),
                _("Ask"),
                _("Always"),
            },
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
        .optionDescription = { 
                _("Always"),
                _("Best Ball"),
                _("After 1 Ball"),
            },
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
        .optionDescription = { 
                _("B -> A"),
                _("R"),
                _("Off"),
            },
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
        .optionDescription = { 
                _("Cinematic"),
                _("Standard"),
                _("Challenge"),
                _("Kaizo"),
            },
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
        .optionDescription = { 
                _("Allowed"),
                _("Box"),
                _("Release"),
            },
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
        .optionDescription = { 
                _("Default"),
                _("First Only"),
                _("Duplicate"),
            },
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
        .optionDescription = { 
                _("Ask"),
                _("Forced"),
                _("None"),
            },
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
        .optionDescription = { 
                _("Default"),
                _("Respawn"),
                _("Death"),
            },
        .numOptions = 3,
    },
    [BATTLE_OPTIONS_ITEM_HEALING] =
    {
        .title = _("Item Healing"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = { 
                _("Allowed"),
                _("Disabled"),
            },
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_CENTER_HEALING] =
    {
        .title = _("Center Healing"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = { 
                _("Allowed"),
                _("Disabled"),
            },
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
        .optionDescription = { 
                _("Allowed"),
                _("No Boss"),
                _("No Trainer"),
                _("4 Only"),
                _("No Items"),
            },
        .numOptions = 5,
    },
    [BATTLE_OPTIONS_OPPONENTS_ITEMS] =
    {
        .title = _("Opponent Items"),
        .options = { 
                _("Allowed"),
                _("Disabled"),
            },
        .optionDescription = { 
                _("Allowed"),
                _("Disabled"),
            },
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
        .optionDescription = { 
                _("Disabled"),
                _("100"),
                _("255"),
                _("500"),
            },
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
        .optionDescription = { 
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
        .numOptions = NUMBER_OF_MON_TYPES + 1,
    },
    [BATTLE_OPTIONS_TYPE_ICONS] =
    {
        .title = _("Type Icons"),
        .options = { 
                _("Show"),
                _("Hide"),
            },
        .optionDescription = { 
                _("Show"),
                _("Hide"),
            },
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_ANIMATIONS] =
    {
        .title = _("Animations"),
        .options = { 
                _("Animated"),
                _("Skip"),
            },
        .optionDescription = { 
                _("Animated"),
                _("Skip"),
            },
        .numOptions = 2,
    },
    [BATTLE_OPTIONS_INTRO] =
    {
        .title = _("Intro"),
        .options = { 
                _("Normal"),
                _("Skip"),
            },
        .optionDescription = { 
                _("Normal"),
                _("Skip"),
            },
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
        .optionDescription = { 
                _("Fast"),
                _("Normal"),
                _("Instant"),
            },
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
        .optionDescription = { 
                _("Fast"),
                _("Normal"),
                _("Instant"),
            },
        .numOptions = 3,
    },
};

// For Visual Settings

struct OptionData VisualSettings_Settings_Options[NUM_OPTIONS_VISUAL_SETTINGS] = {
    [VISUAL_OPTIONS_PRESET] =
    {
        .title = _("Visual Settings"),
        .options = { 
            _("Default"),
            _("Speedrun"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Speedrun Description"),
            _("Custom Description"),
            },
        .numOptions = 3,
    },
    [VISUAL_OPTIONS_UNITS] =
    {
        .title = _("Units"),
        .options = { 
            _("Metric"),
            _("Imperial"),
            },
        .optionDescription = { 
            _("Metric"),
            _("Imperial"),
            },
        .numOptions = 2,
    },
    [VISUAL_OPTIONS_TEXT_SPEED] =
    {
        .title = _("Text Speed"),
        .options = { 
            _("Slow"),
            _("Medium"),
            _("Fast"),
            _("Faster"),
            _("Instant"),
            },
        .optionDescription = { 
            _("Slow"),
            _("Medium"),
            _("Fast"),
            _("Faster"),
            _("Instant"),
            },
        .numOptions = 5,
    },
    [VISUAL_OPTIONS_FRAME_TYPE] =
    {
        .title = _("Frame Type"),
        .options = { 
            _("Frame 1"),
            _("Frame 2"),
            _("Frame 3"),
            _("Frame 4"),
            _("Frame 5"),
            _("Frame 6"),
            _("Frame 7"),
            _("Frame 8"),
            _("Frame 9"),
            _("Frame 10"),
            _("Frame 11"),
            _("Frame 12"),
            _("Frame 13"),
            _("Frame 14"),
            _("Frame 15"),
            _("Frame 16"),
            _("Frame 17"),
            _("Frame 18"),
            _("Frame 19"),
            _("Frame 20"),
            },
        .optionDescription = { 
            _("Frame 1"),
            _("Frame 2"),
            _("Frame 3"),
            _("Frame 4"),
            _("Frame 5"),
            _("Frame 6"),
            _("Frame 7"),
            _("Frame 8"),
            _("Frame 9"),
            _("Frame 10"),
            _("Frame 11"),
            _("Frame 12"),
            _("Frame 13"),
            _("Frame 14"),
            _("Frame 15"),
            _("Frame 16"),
            _("Frame 17"),
            _("Frame 18"),
            _("Frame 19"),
            _("Frame 20"),
            },
        .numOptions = 20,
    },
    [VISUAL_OPTIONS_FONT_SWITCHER] =
    {
        .title = _("Font Switcher"),
        .options = { 
            _("Emerald"),
            _("Fire Red"),
            },
        .optionDescription = { 
            _("Emerald"),
            _("Fire Red"),
            },
        .numOptions = 2,
    },
    [VISUAL_OPTIONS_COLOR] =
    {
        .title = _("Color"),
        .options = { 
            _("Red"),
            _("Green"),
            _("Blue"),
            _("Yellow"),
            _("Black"),
            _("White"),
            _("Platinum"),
            _("Scarlet"),
            _("Violet"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Red"),
            _("Green"),
            _("Blue"),
            _("Yellow"),
            _("Black"),
            _("White"),
            _("Platinum"),
            _("Scarlet"),
            _("Violet"),
            _("Custom"),
            },
        .numOptions = 10,
    },
};

// For Music Settings

struct OptionData MusicSettings_Settings_Options[NUM_OPTIONS_MUSIC_SETTINGS] = {
    [MUSIC_OPTIONS_PRESET] =
    {
        .title = _("Music Settings"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            _("Custom"),
            },
        .optionDescription = { 
            _("PSF Description"),
            _("LGPE Description"),
            _("HGSS Description"),
            _("ORAS Description"),
            _("BDSP Description"),
            _("BW2 Description"),
            _("XY Description"),
            _("USUM Description"),
            _("SWSH Description"),
            _("SV Description"),
            _("Custom Description"),
            },
        .numOptions = 11,
    },
    [MUSIC_OPTIONS_SOUND_EFFECT] =
    {
        .title = _("Sound Effect"),
        .options = { 
            _("1"),
            _("2"),
            _("3"),
            _("4"),
            _("5"),
            _("6"),
            _("7"),
            _("8"),
            _("9"),
            _("10"),
            _("11"),
            _("12"),
            _("13"),
            _("14"),
            _("15"),
            _("16"),
            _("17"),
            _("18"),
            _("19"),
            _("20"),
            },
        .optionDescription = { 
            _("1"),
            _("2"),
            _("3"),
            _("4"),
            _("5"),
            _("6"),
            _("7"),
            _("8"),
            _("9"),
            _("10"),
            _("11"),
            _("12"),
            _("13"),
            _("14"),
            _("15"),
            _("16"),
            _("17"),
            _("18"),
            _("19"),
            _("20"),
            },
        .numOptions = 20,
    },
    [MUSIC_OPTIONS_MUSIC] =
    {
        .title = _("Music"),
        .options = { 
            _("1"),
            _("2"),
            _("3"),
            _("4"),
            _("5"),
            _("6"),
            _("7"),
            _("8"),
            _("9"),
            _("10"),
            _("11"),
            _("12"),
            _("13"),
            _("14"),
            _("15"),
            _("16"),
            _("17"),
            _("18"),
            _("19"),
            _("20"),
            },
        .optionDescription = { 
            _("1"),
            _("2"),
            _("3"),
            _("4"),
            _("5"),
            _("6"),
            _("7"),
            _("8"),
            _("9"),
            _("10"),
            _("11"),
            _("12"),
            _("13"),
            _("14"),
            _("15"),
            _("16"),
            _("17"),
            _("18"),
            _("19"),
            _("20"),
            },
        .numOptions = 20,
    },
    [MUSIC_OPTIONS_SPEAKER] =
    {
        .title = _("Speaker"),
        .options = { 
            _("Mono"),
            _("Stereo"),
            },
        .optionDescription = { 
            _("Mono"),
            _("Stereo"),
            },
        .numOptions = 2,
    },
    [MUSIC_OPTIONS_SURF] =
    {
        .title = _("Surf"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SV"),
            },
        .numOptions = 9,
    },
    [MUSIC_OPTIONS_BIKE] =
    {
        .title = _("Bike"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .numOptions = 10,
    },
    [MUSIC_OPTIONS_WILD] =
    {
        .title = _("Wild"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .numOptions = 10,
    },
    [MUSIC_OPTIONS_TRAINER] =
    {
        .title = _("Trainer"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .numOptions = 10,
    },
    [MUSIC_OPTIONS_GYM] =
    {
        .title = _("Gym"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .numOptions = 10,
    },
    [MUSIC_OPTIONS_TOURNAMENT] =
    {
        .title = _("Tournament"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .numOptions = 10,
    },
    [MUSIC_OPTIONS_CHAMPION] =
    {
        .title = _("Champion"),
        .options = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .optionDescription = { 
            _("PSF"),
            _("LGPE"),
            _("HGSS"),
            _("ORAS"),
            _("BDSP"),
            _("BW2"),
            _("XY"),
            _("USUM"),
            _("SWSH"),
            _("SV"),
            },
        .numOptions = 10,
    },
};

// For Random Settings

struct OptionData RandomSettings_Settings_Options[NUM_OPTIONS_RANDOM_SETTINGS] = {
    [RANDOM_OPTIONS_PRESET] =
    {
        .title = _("Random Settings"),
        .options = { 
            _("Default"),
            _("Sane"),
            _("Crazy"),
            _("Total Chaos"),
            _("Custom"),
            },
        .optionDescription = { 
            _("Default Description"),
            _("Sane Description"),
            _("Crazy Description"),
            _("Total Chaos Description"),
            _("Custom Description"),
            },
        .numOptions = 5,
    },
    [RANDOM_OPTIONS_STARTER] =
    {
        .title = _("Starter"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_WILD_BATTLE] =
    {
        .title = _("Wild Battle"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_TRAINER_BATTLE] =
    {
        .title = _("Trainer Battle"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_EVOLUTION] =
    {
        .title = _("Evolution"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Legends"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Legends"),
            _("Chaos"),
            },
        .numOptions = 4,
    },
    [RANDOM_OPTIONS_EVOLUTION_METHOD] =
    {
        .title = _("Evolution Method"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_TYPE_EFFECTIVENESS] =
    {
        .title = _("Type Effectiveness"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_BASE_STATS] =
    {
        .title = _("Base Stats"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_TYPES] =
    {
        .title = _("Types"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_ABILITIES] =
    {
        .title = _("Abilities"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_LEVEL_UP_MOVES] =
    {
        .title = _("Level Up Moves"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_TMS] =
    {
        .title = _("TMs"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_MOVE_TUTORS] =
    {
        .title = _("Move Tutors"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_LEARNSETS] =
    {
        .title = _("Learnsets"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_ITEMS] =
    {
        .title = _("Items"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_STATIC_ENCOUNTERS] =
    {
        .title = _("Static Encounters"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    },
    [RANDOM_OPTIONS_TRAINERS] =
    {
        .title = _("Trainers"),
        .options = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .optionDescription = { 
            _("Default"),
            _("Random"),
            _("Chaos"),
            },
        .numOptions = 3,
    }
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
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, VisualSettings_Settings_Options[GetCurrentSlotOption(i)].title);
                    y = y + 2;
                }
            break;
            case MUSIC_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, MusicSettings_Settings_Options[GetCurrentSlotOption(i)].title);
                    y = y + 2;
                }
            break;
            default:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, RandomSettings_Settings_Options[GetCurrentSlotOption(i)].title);
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

            switch(i){
                case GAME_SETTINGS:
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[0].options[Temporal_Options_Game_Settings[0]]);
                break;
                case BATTLE_SETTINGS:
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, BattleSettings_Settings_Options[0].options[Temporal_Options_Battle_Settings[0]]);
                break;
                case VISUAL_SETTINGS:
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, VisualSettings_Settings_Options[0].options[Temporal_Options_Visual_Settings[0]]);
                break;
                case MUSIC_SETTINGS:
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, MusicSettings_Settings_Options[0].options[Temporal_Options_Music_Settings[0]]);
                break;
                case RANDOM_SETTINGS:
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, RandomSettings_Settings_Options[0].options[Temporal_Options_Random_Settings[0]]);
                break;
            }
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
            case VISUAL_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, VisualSettings_Settings_Options[GetCurrentSlotOption(i)].options[Temporal_Options_Visual_Settings[GetCurrentSlotOption(i)]]);
                    y = y + 2;
                }
            break;
            case MUSIC_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, MusicSettings_Settings_Options[GetCurrentSlotOption(i)].options[Temporal_Options_Music_Settings[GetCurrentSlotOption(i)]]);
                    y = y + 2;
                }
            break;
            case RANDOM_SETTINGS:
                for(i = 0; i < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN; i++){
                    AddTextPrinterParameterized4(windowId, 8, (x*8) + 6, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, RandomSettings_Settings_Options[GetCurrentSlotOption(i)].options[Temporal_Options_Random_Settings[GetCurrentSlotOption(i)]]);
                    y = y + 2;
                }
            break;
        }
        
    }

    // Option Description --------------------------------------------------------------------------------------------------------------------
    // Only gets displayed you are on the Settings Hub
    x = 0;
    y = 14;
    if(ShouldShowDiscardDialogue){
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Discard_Text);
    }
    else if(!areYouNotOnSettingsHub){
        switch(currentScreenId){
            case GAME_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[0].optionDescription[Temporal_Options_Game_Settings[0]]);
            break;
            case BATTLE_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, BattleSettings_Settings_Options[0].optionDescription[Temporal_Options_Battle_Settings[0]]);
            break;
            case VISUAL_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, VisualSettings_Settings_Options[0].optionDescription[Temporal_Options_Visual_Settings[0]]);
            break;
            case MUSIC_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, MusicSettings_Settings_Options[0].optionDescription[Temporal_Options_Music_Settings[0]]);
            break;
            case RANDOM_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, RandomSettings_Settings_Options[0].optionDescription[Temporal_Options_Random_Settings[0]]);
            break;
        }
    }
    else{
        switch(currentScreenId){
            case GAME_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, GameSettings_Settings_Options[currentOptionId].optionDescription[Temporal_Options_Game_Settings[currentOptionId]]);
            break;
            case BATTLE_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, BattleSettings_Settings_Options[currentOptionId].optionDescription[Temporal_Options_Battle_Settings[currentOptionId]]);
            break;
            case VISUAL_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, VisualSettings_Settings_Options[currentOptionId].optionDescription[Temporal_Options_Visual_Settings[currentOptionId]]);
            break;
            case MUSIC_SETTINGS:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, MusicSettings_Settings_Options[currentOptionId].optionDescription[Temporal_Options_Music_Settings[currentOptionId]]);
            break;
            default:
                AddTextPrinterParameterized4(windowId, 8, (x*8) + 4, (y*8) + 4, 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, RandomSettings_Settings_Options[currentOptionId].optionDescription[Temporal_Options_Random_Settings[currentOptionId]]);
            break;
        }
    }

    // Help Bar --------------------------------------------------------------------------------------------------------------------
    x = 0;
    y = 18;
    if(ShouldShowDiscardDialogue){
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar_Discard);
    }
    else if(!areYouNotOnSettingsHub){
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar_Settings_Hub);
    }
    else{
        AddTextPrinterParameterized4(windowId, 8, (x*8)+4, (y*8), 0, 0, sMenuWindowFontColors[FONT_WHITE], 0xFF, sText_Help_Bar_Settings_Page);
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

static void RecolorWindow(){
    FreeAllSpritePalettes();
    switch(Temporal_Options_Visual_Settings[VISUAL_OPTIONS_COLOR]){
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
    mgba_printf(MGBA_LOG_WARN, "Color %d", Temporal_Options_Visual_Settings[VISUAL_OPTIONS_COLOR]);
    //SetMainCallback2(CB2_InitUIOptionMenu);
    //DestroyTask(taskId);
}

/* This is the meat of the UI. This is where you wait for player inputs and can branch to other tasks accordingly */
static void Task_MenuMain(u8 taskId)
{
    if(JOY_NEW(DPAD_UP) && !ShouldShowDiscardDialogue)
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
            PressedUpButton();
        }
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_DOWN) && !ShouldShowDiscardDialogue)
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

    if(JOY_NEW(DPAD_LEFT) && !ShouldShowDiscardDialogue)
	{
        if(!areYouNotOnSettingsHub || currentOptionId == 0){
            if((currentScreenId == GAME_SETTINGS && Temporal_Options_Game_Settings[0] > 0) ||
               (currentScreenId == BATTLE_SETTINGS && Temporal_Options_Battle_Settings[0] > 0) ||
               (currentScreenId == VISUAL_SETTINGS && Temporal_Options_Visual_Settings[0] > 0) ||
               (currentScreenId == MUSIC_SETTINGS && Temporal_Options_Music_Settings[0] > 0) ||
               (currentScreenId == RANDOM_SETTINGS && Temporal_Options_Random_Settings[0] > 0)){
                switch(currentScreenId){
                    case GAME_SETTINGS:
                        Temporal_Options_Game_Settings[0]--;
                    break;
                    case BATTLE_SETTINGS:
                        Temporal_Options_Battle_Settings[0]--;
                    break;
                    case VISUAL_SETTINGS:
                        Temporal_Options_Visual_Settings[0]--;
                    break;
                    case MUSIC_SETTINGS:
                        Temporal_Options_Music_Settings[0]--;
                    break;
                    default:
                        Temporal_Options_Random_Settings[0]--;
                    break;
                }
            }
            else{
                switch(currentScreenId){
                    case GAME_SETTINGS:
                        Temporal_Options_Game_Settings[0] = GameSettings_Settings_Options[0].numOptions - 1;
                    break;
                    case BATTLE_SETTINGS:
                        Temporal_Options_Battle_Settings[0] = BattleSettings_Settings_Options[0].numOptions - 1;
                    break;
                    case VISUAL_SETTINGS:
                        Temporal_Options_Visual_Settings[0] = VisualSettings_Settings_Options[0].numOptions - 1;
                    break;
                    case MUSIC_SETTINGS:
                        Temporal_Options_Music_Settings[0] = MusicSettings_Settings_Options[0].numOptions - 1;
                    break;
                    default:
                        Temporal_Options_Random_Settings[0] = RandomSettings_Settings_Options[0].numOptions - 1;
                    break;
                }
            }

            HandlePresetData();
            if(currentScreenId == VISUAL_SETTINGS)
                RecolorWindow();
        }
        else{
            switch(currentScreenId){
                case GAME_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Game_Settings[currentOptionId] > 0){
                            Temporal_Options_Game_Settings[currentOptionId]--;
                        }
                        else
                            Temporal_Options_Game_Settings[currentOptionId] = GameSettings_Settings_Options[currentOptionId].numOptions - 1;
                    }
                break;
                case BATTLE_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Battle_Settings[currentOptionId] > 0)
                            Temporal_Options_Battle_Settings[currentOptionId]--;
                        else
                            Temporal_Options_Battle_Settings[currentOptionId] = BattleSettings_Settings_Options[currentOptionId].numOptions - 1;
                    }
                break;
                case VISUAL_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Visual_Settings[currentOptionId] > 0)
                            Temporal_Options_Visual_Settings[currentOptionId]--;
                        else
                            Temporal_Options_Visual_Settings[currentOptionId] = VisualSettings_Settings_Options[currentOptionId].numOptions - 1;

                        if(currentOptionId == VISUAL_OPTIONS_COLOR)
                            RecolorWindow();
                    }
                break;
                case MUSIC_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Music_Settings[currentOptionId] > 0)
                            Temporal_Options_Music_Settings[currentOptionId]--;
                        else
                            Temporal_Options_Music_Settings[currentOptionId] = MusicSettings_Settings_Options[currentOptionId].numOptions - 1;
                    }
                break;
                case RANDOM_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Random_Settings[currentOptionId] > 0)
                            Temporal_Options_Random_Settings[currentOptionId]--;
                        else
                            Temporal_Options_Random_Settings[currentOptionId] = RandomSettings_Settings_Options[currentOptionId].numOptions - 1;
                    }
                break;
            }
        }
        PlaySE(SE_SELECT);

        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if(JOY_NEW(DPAD_RIGHT) && !ShouldShowDiscardDialogue)
	{
        if(!areYouNotOnSettingsHub || currentOptionId == 0){
            if((currentScreenId == GAME_SETTINGS   && Temporal_Options_Game_Settings[0]   <= GameSettings_Settings_Options[0].numOptions - 1) ||
               (currentScreenId == BATTLE_SETTINGS && Temporal_Options_Battle_Settings[0] <= BattleSettings_Settings_Options[0].numOptions - 1) ||
               (currentScreenId == VISUAL_SETTINGS && Temporal_Options_Visual_Settings[0] <= VisualSettings_Settings_Options[0].numOptions - 1) ||
               (currentScreenId == MUSIC_SETTINGS  && Temporal_Options_Music_Settings[0]  <= MusicSettings_Settings_Options[0].numOptions - 1) ||
               (currentScreenId == RANDOM_SETTINGS && Temporal_Options_Random_Settings[0] <= RandomSettings_Settings_Options[0].numOptions - 1)){
                switch(currentScreenId){
                    case GAME_SETTINGS:
                        Temporal_Options_Game_Settings[0]++;
                    break;
                    case BATTLE_SETTINGS:
                        Temporal_Options_Battle_Settings[0]++;
                    break;
                    case VISUAL_SETTINGS:
                        Temporal_Options_Visual_Settings[0]++;
                    break;
                    case MUSIC_SETTINGS:
                        Temporal_Options_Music_Settings[0]++;
                    break;
                    default:
                        Temporal_Options_Random_Settings[0]++;
                    break;
                }
            }
            else{
                switch(currentScreenId){
                    case GAME_SETTINGS:
                        Temporal_Options_Game_Settings[0] = 0;
                    break;
                    case BATTLE_SETTINGS:
                        Temporal_Options_Battle_Settings[0] = 0;
                    break;
                    case VISUAL_SETTINGS:
                        Temporal_Options_Visual_Settings[0] = 0;
                    break;
                    case MUSIC_SETTINGS:
                        Temporal_Options_Music_Settings[0] = 0;
                    break;
                    default:
                        Temporal_Options_Random_Settings[0] = 0;
                    break;

                    
                }
            }

            mgba_printf(MGBA_LOG_WARN, "Asdf %d", Temporal_Options_Music_Settings[0]);
            HandlePresetData();

            if(currentScreenId == VISUAL_SETTINGS)
                RecolorWindow();
        }
        else{
            switch(currentScreenId){
                case GAME_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Game_Settings[currentOptionId] < GameSettings_Settings_Options[currentOptionId].numOptions - 1){
                            Temporal_Options_Game_Settings[currentOptionId]++;
                        }
                        else
                            Temporal_Options_Game_Settings[currentOptionId] = 0;
                    }
                break;
                case BATTLE_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Battle_Settings[currentOptionId] < BattleSettings_Settings_Options[currentOptionId].numOptions - 1){
                            Temporal_Options_Battle_Settings[currentOptionId]++;
                        }
                        else
                            Temporal_Options_Battle_Settings[currentOptionId] = 0;
                    }
                break;
                case VISUAL_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Visual_Settings[currentOptionId] < VisualSettings_Settings_Options[currentOptionId].numOptions - 1){
                            Temporal_Options_Visual_Settings[currentOptionId]++;
                        }
                        else
                            Temporal_Options_Visual_Settings[currentOptionId] = 0;

                        if(currentOptionId == VISUAL_OPTIONS_COLOR)
                            RecolorWindow();
                    }
                break;
                case MUSIC_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Music_Settings[currentOptionId] < MusicSettings_Settings_Options[currentOptionId].numOptions - 1){
                            Temporal_Options_Music_Settings[currentOptionId]++;
                        }
                        else
                            Temporal_Options_Music_Settings[currentOptionId] = 0;
                    }
                break;
                case RANDOM_SETTINGS:
                    if(AreYouOnCustomPresetData() || currentOptionId == 0){
                        if(Temporal_Options_Random_Settings[currentOptionId] < RandomSettings_Settings_Options[currentOptionId].numOptions - 1){
                            Temporal_Options_Random_Settings[currentOptionId]++;
                        }
                        else
                            Temporal_Options_Random_Settings[currentOptionId] = 0;
                    }
                break;
            }
        }
        PlaySE(SE_SELECT);
        PrintToWindow(WINDOW_1, FONT_BLACK);
	}

    if (JOY_NEW(A_BUTTON))
    {
        if(!areYouNotOnSettingsHub && !ShouldShowDiscardDialogue){
            areYouNotOnSettingsHub = !areYouNotOnSettingsHub;
            HandlePresetData();
            currentOptionId = 0;
            currentFirstOption = 0;

            if(currentScreenId == VISUAL_SETTINGS){
                RecolorWindow();
            }  

            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
        else if(areYouNotOnSettingsHub && ShouldShowDiscardDialogue){
            ShouldShowDiscardDialogue = FALSE;
            areYouNotOnSettingsHub = !areYouNotOnSettingsHub;
            currentOptionId = 0;
            currentFirstOption = 0;
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
        else if(ShouldShowDiscardDialogue && !areYouNotOnSettingsHub){
            PlaySE(SE_PC_OFF);
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            gTasks[taskId].func = Task_MenuTurnOff;
        }
    }

    if (JOY_NEW(B_BUTTON))
    {
        if(AreYouOnCustomPresetData())
            ShouldShowDiscardDialogue = !ShouldShowDiscardDialogue;
        else{
            areYouNotOnSettingsHub = !areYouNotOnSettingsHub;
            currentOptionId = 0;
            currentFirstOption = 0;
        }
        
        PrintToWindow(WINDOW_1, FONT_BLACK);
    }

    if (JOY_NEW(START_BUTTON))
    {
        ShouldShowDiscardDialogue = FALSE;

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

    if (JOY_NEW(L_BUTTON) && !ShouldShowDiscardDialogue)
    {
        if(areYouNotOnSettingsHub){
            if(currentScreenId > 0){
			    currentScreenId--;
            }
            else{
                currentScreenId = NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN - 1;
            }

            currentOptionId = 0;
            currentFirstOption = 0;
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
    }

    if (JOY_NEW(R_BUTTON) && !ShouldShowDiscardDialogue)
    {
        if(areYouNotOnSettingsHub){
            if(currentScreenId < NUM_OF_POSSIBLE_OPTIONS_THAT_FIT_ON_SCREEN-1){
                currentScreenId++;
            }
            else{
                currentScreenId = 0;
            }

            currentOptionId = 0;
            currentFirstOption = 0;
            PrintToWindow(WINDOW_1, FONT_BLACK);
        }
    }
}