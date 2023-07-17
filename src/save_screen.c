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

struct SampleUiState
{
    MainCallback savedCallback;

    u8 loadState;

    u8 mode;

    u8 monIconSpriteId;

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

static EWRAM_DATA struct SampleUiState *sSampleUiState = NULL;
static EWRAM_DATA u8 *sBg1TilemapBuffer = NULL;

EWRAM_DATA static u8 sSaveDialogTimer = 0;

#define MON_ICON_X     39
#define MON_ICON_Y     36

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

static const struct BgTemplate sSampleUiBgTemplates[] =
{
    {

        .bg = 0,

        .charBaseIndex = 0,

        .mapBaseIndex = 31,

        .priority = 1
    },
    {

        .bg = 1,

        .charBaseIndex = 3,

        .mapBaseIndex = 30,

        .priority = 2
    }

};

static const struct WindowTemplate sSampleUiWindowTemplates[] =
{
    [WIN_MON_INFO] =
    {

        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 9,
        .width = 26,
        .height = 10,

        .paletteNum = 15,

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

enum FontColor
{
    FONT_BLACK,
    FONT_WHITE,
    FONT_RED,
    FONT_BLUE,
};
static const u8 sSampleUiWindowFontColors[][3] =
{

    [FONT_BLACK]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_DARK_GRAY,  TEXT_COLOR_LIGHT_GRAY},
    [FONT_WHITE]  = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_WHITE,      TEXT_COLOR_DARK_GRAY},
    [FONT_RED]    = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_RED,        TEXT_COLOR_LIGHT_GRAY},
    [FONT_BLUE]   = {TEXT_COLOR_TRANSPARENT, TEXT_COLOR_BLUE,       TEXT_COLOR_LIGHT_GRAY},
};

static void SampleUi_SetupCB(void);
static void SampleUi_MainCB(void);
static void SampleUi_VBlankCB(void);

static void Task_SampleUiWaitFadeIn(u8 taskId);
static void Task_SampleUiMainInput(u8 taskId);
static void Task_SampleUiWaitFadeAndBail(u8 taskId);
static void Task_SampleUiWaitFadeAndExitGracefully(u8 taskId);

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

            if (SampleUi_LoadGraphics() == TRUE)
            {

                gMain.state++;
            }
            break;
        case 4:

            SampleUi_InitWindows();
            gMain.state++;
            break;
        case 5:

            sSampleUiState->monIconDexNum = NATIONAL_DEX_BULBASAUR;

            FreeMonIconPalettes();

            LoadMonIconPalettes();

            SampleUi_DrawMonIcon(sSampleUiState->monIconDexNum);

            SaveMapView();
            sSampleUiState->mode = SAVE_ASK;
            SampleUi_PrintUiMonInfo();

            taskId = CreateTask(Task_SampleUiWaitFadeIn, 0);
            gMain.state++;
            break;
        case 6:

            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
            gMain.state++;
            break;
        case 7:

            SetVBlankCallback(SampleUi_VBlankCB);
            SetMainCallback2(SampleUi_MainCB);
            break;
    }
}

static void SampleUi_MainCB(void)
{
    RunTasks();

    AnimateSprites();
    BuildOamBuffer();
    DoScheduledBgTilemapCopiesToVram();
    UpdatePaletteFade();
}

static void SampleUi_VBlankCB(void)
{

    LoadOam();

    ProcessSpriteCopyRequests();

    TransferPlttBuffer();
}

static void Task_SampleUiWaitFadeIn(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        gTasks[taskId].func = Task_SampleUiMainInput;
    }
}

static void SaveScreen_CheckSave(void){
    sSampleUiState->mode = SAVE_CHECK;

    if (gDifferentSaveFile == TRUE){
        sSampleUiState->mode = SAVE_OVERWRITE;
    }else{
        SaveScreen_DoSave();
    }
    SampleUi_PrintUiMonInfo();
}

static void SaveScreen_ReturnToMenu(void){
    SampleUi_FadeAndBail();
}

static void SaveScreen_ReturnToField(void){
    SampleUi_FadeAndBail();

}

static void Task_SampleUiMainInput(u8 taskId)
{
    switch(sSampleUiState->mode)
    {
        case SAVE_ASK:
            if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(START_BUTTON))){
                SaveScreen_CheckSave();
            }

            if (JOY_NEW(B_BUTTON)){
                SaveScreen_ReturnToMenu();
            }

            break;

        case SAVE_CHECK:
        case SAVE_IN_PROGRESS:
        case SAVE_CANCELED:
            break;

        case SAVE_ERROR:
        case SAVE_SUCCESS:
            if ((JOY_NEW(A_BUTTON)) || (JOY_NEW(START_BUTTON))){
                SaveScreen_ReturnToField();
            }

            if (JOY_NEW(B_BUTTON)){
                SaveScreen_ReturnToMenu();
            }
            break;

        case SAVE_OVERWRITE:
            if (JOY_NEW(START_BUTTON)){
                SaveScreen_DoSave();
            }else if(JOY_NEW(ANY_BUTTON_BUT_START)){
                SaveScreen_ReturnToMenu();
            }
            break;
        default:
            break;
    }
}

static void SaveScreen_DoSave(void)
{
    u8 saveStatus;

    PlaySE(SE_SELECT);

    sSampleUiState->mode = SAVE_IN_PROGRESS;
    SampleUi_PrintUiMonInfo();

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

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSampleUiState->savedCallback);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}

static void Task_SampleUiWaitFadeAndExitGracefully(u8 taskId)
{

    if (!gPaletteFade.active)
    {
        SetMainCallback2(sSampleUiState->savedCallback);
        SampleUi_FreeResources();
        DestroyTask(taskId);
    }
}

static bool8 SampleUi_InitBgs(void)
{

    const u32 TILEMAP_BUFFER_SIZE = (1024 * 2);

    ResetAllBgsCoordinates();

    sBg1TilemapBuffer = AllocZeroed(TILEMAP_BUFFER_SIZE);
    if (sBg1TilemapBuffer == NULL)
    {

        return FALSE;
    }

    ResetBgsAndClearDma3BusyFlags(0);

    InitBgsFromTemplates(0, sSampleUiBgTemplates, NELEMS(sSampleUiBgTemplates));

    SetBgTilemapBuffer(1, sBg1TilemapBuffer);

    ScheduleBgCopyTilemapToVram(1);

    ShowBg(0);
    ShowBg(1);

    return TRUE;
}

static void SampleUi_FadeAndBail(void)
{
    BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    CreateTask(Task_SampleUiWaitFadeAndBail, 0);

    SetVBlankCallback(SampleUi_VBlankCB);
    SetMainCallback2(SampleUi_MainCB);
}

static bool8 SampleUi_LoadGraphics(void)
{
    switch (sSampleUiState->loadState)
    {
        case 0:

            ResetTempTileDataBuffers();

            DecompressAndCopyTileDataToVram(1, sSampleUiTiles, 0, 0, 0);
            sSampleUiState->loadState++;
            break;
        case 1:

            if (FreeTempTileDataBuffersIfPossible() != TRUE)
            {

                LZDecompressWram(sSampleUiTilemap, sBg1TilemapBuffer);
                sSampleUiState->loadState++;
            }
            break;
        case 2:

            LoadPalette(sSampleUiPalette, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

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

    InitWindows(sSampleUiWindowTemplates);

    DeactivateAllTextPrinters();

    ScheduleBgCopyTilemapToVram(0);

    FillWindowPixelBuffer(WIN_MON_INFO, PIXEL_FILL(TEXT_COLOR_TRANSPARENT));

    PutWindowTilemap(WIN_MON_INFO);

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

    CopyWindowToVram(WIN_MON_INFO, COPYWIN_GFX);
}

static void SampleUi_DrawMonIcon(u16 dexNum)
{

    u16 speciesId = NationalPokedexNumToSpecies(dexNum);

    sSampleUiState->monIconSpriteId = CreateMonIcon(speciesId, SpriteCB_MonIcon, MON_ICON_X, MON_ICON_Y, 4, 0);

    gSprites[sSampleUiState->monIconSpriteId].oam.priority = 0;
}

static void SampleUi_FreeResources(void)
{

    if (sSampleUiState != NULL)
    {
        Free(sSampleUiState);
    }
    if (sBg1TilemapBuffer != NULL)
    {
        Free(sBg1TilemapBuffer);
    }

    FreeAllWindowBuffers();

    ResetSpriteData();
}
