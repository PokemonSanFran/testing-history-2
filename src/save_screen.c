#include "global.h"
#include "task.h"
#include "debug_start.h"
#include "start_menu.h"
#include "text.h"
#include "menu.h"
#include "sound.h"
#include "main.h"
#include "palette.h"
#include "gpu_regs.h"
#include "bg.h"
#include "text_window.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "naming_screen.h"
#include "overworld.h"
#include "event_data.h"
#include "safari_zone.h"
#include "new_game.h"
#include "play_time.h"
#include "script.h"
#include "field_screen_effect.h"
#include "random.h"
#include "save.h"

extern const u8 gText_ConfirmSave[];
extern const u8 gText_DifferentSaveFile[];
extern const u8 gText_AlreadySavedFile[];
extern const u8 gText_SavingDontTurnOff[];
extern const u8 gText_PlayerSavedGame[];
extern const u8 gText_SaveError[];
extern const u8 gText_SavingDontTurnOffPower[];

static u8 SaveFileExistsCallback(void);
static bool8 SetupDebugStartScreen(void);
void Task_SaveScreenTurnOff(u8 taskId);
void CB2_InitSaveScreen(void);
static bool8 SetupSaveScreen(void);
static void InitSaveScreenWindows(void);
static void Task_DoSaveAskQuestion(u8 taskId);
static void VBlankCB(void);
static void MainCB(void);
static void Task_DoDebugAskQuestion(u8 taskId);
static u8 Task_SaveScreenChoice(u8 taskId);
static void Task_SaveScreenCallback(void);
static void ShowDebugStartChoices(void);
static void Task_DebugStartScreenChoice(u8 taskId);
static void CB2_FadeAndDoReset(void);
static void Task_GoToStarterChoice(u8 taskId);
static void Task_GoToBeforeBianca(u8 taskId);
static void Task_GoToAfterBianca(u8 taskId);
static void DebugStart_NewGame(void);
static void DebugStart_BeginAdventure(void);

EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveInfoWindowId = 0;
u8 saveStatus = 0;

static const struct BgTemplate sClearSaveBgTemplates[2] = {
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sSaveGameTextWindow[] = {
    {
        .bg = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 11,
        /*
           .bg = 0,
           .tilemapLeft = 25,
           .tilemapTop = 13,
           .width = 18,
           .height = 4,
           .paletteNum = 15,
           .baseBlock = 11,
           */
    },
    DUMMY_WIN_TEMPLATE
};

enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

void CB2_InitSaveScreen(void)
{
    if (SetupSaveScreen())
        CreateTask(Task_DoSaveAskQuestion, 0);
}

static bool8 SetupSaveScreen(void)
{
    u16 i;

    switch (gMain.state) {
        case 0:
        default:
            SetVBlankCallback(NULL);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
            SetGpuReg(REG_OFFSET_BG0HOFS, 0);
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0);
            SetGpuReg(REG_OFFSET_BG3VOFS, 0);
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
            DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
            DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
            ResetPaletteFade();
            gPlttBufferUnfaded[0] = RGB_WHITE;
            gPlttBufferFaded[0] = RGB_WHITE;
            gPlttBufferUnfaded[1] = RGB(5, 10, 14);
            gPlttBufferFaded[1] = RGB(5, 10, 14);
            for (i = 0; i < 0x10; i++)
                ((u16 *)(VRAM + 0x20))[i] = 0x1111;

            for (i = 0; i < 0x400; i++)
                ((u16 *)(BG_SCREEN_ADDR(30)))[i] = 0x0001;
            ResetTasks();
            ResetSpriteData();
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sClearSaveBgTemplates, ARRAY_COUNT(sClearSaveBgTemplates));
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(3);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            InitSaveScreenWindows();
            BeginNormalPaletteFade(PALETTES_BG, 0, 0x10, 0, RGB_WHITEALPHA);
            EnableInterrupts(INTR_FLAG_VBLANK);
            SetVBlankCallback(VBlankCB);
            gMain.state = 1;
            break;
        case 1:
            UpdatePaletteFade();
            if (!gPaletteFade.active) {
                SetMainCallback2(MainCB);
                return TRUE;
            }
    }
    return FALSE;
}

static void InitSaveScreenWindows(void)
{
    InitWindows(sSaveGameTextWindow);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, PIXEL_FILL(0));
    LoadWindowGfx(0, 0, 2, 224);
    LoadPalette(gStandardMenuPalette, 0xF0, 0x20);
}

static void VBlankCB(void)
{
    TransferPlttBuffer();
}

static void MainCB(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_DoSaveAskQuestion(u8 taskId)
{
    DrawStdFrameWithCustomTileAndPalette(0, FALSE, 2, 14);
    AddTextPrinterParameterized(0, FONT_NORMAL, gText_ConfirmSave, 0, 1, 0, 0);
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    Task_SaveScreenCallback();
}

static void Task_SaveScreenCallback(void)
{
    switch(Menu_ProcessInput())
    //switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
        case 0: // Yes
            switch (gSaveFileStatus)
            {
                case SAVE_STATUS_EMPTY:
                case SAVE_STATUS_CORRUPT:
                    if (gDifferentSaveFile == FALSE)
                    {
                        sSaveDialogCallback = SaveFileExistsCallback;
                        //return SAVE_IN_PROGRESS;
                        //saveStatus = SAVE_IN_PROGRESS;
                    }
                    //sSaveDialogCallback = SaveSavingMessageCallback;
                    //return SAVE_IN_PROGRESS;
                    break;
                default:
                    break;
                    //sSaveDialogCallback = SaveFileExistsCallback;
                    //return SAVE_IN_PROGRESS;
            }
            break;
        case -1: // B Button
        case 1: // No
            BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
            DestroyTask(taskId);
            gTasks[taskId].func = Task_SaveScreenTurnOff;
    }
    //return SAVE_IN_PROGRESS;
}

static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        //ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        //sSaveDialogCallback = SaveSavingMessageCallback;
    }

    return SAVE_IN_PROGRESS;
}

/*
   static void ShowDebugStartChoices(void)
   {
   u8 windowId;
   LoadMessageBoxAndBorderGfx();
   windowId = AddWindow(sDebugStartChoices);
   DrawStdWindowFrame(windowId, FALSE);
   PrintMenuTable(windowId, ARRAY_COUNT(sMenuActions_DebugStartChoices),
   sMenuActions_DebugStartChoices);
   InitMenuInUpperLeftCornerNormal(windowId, ARRAY_COUNT(sMenuActions_DebugStartChoices), 0);
   CopyWindowToVram(windowId, 3);
   }
   static void Task_DebugStartScreenChoice(u8 taskId)
   {
   u8 debugConstant = Menu_ProcessInput();
   switch (debugConstant) {
   case 0:
   PlaySE(SE_SELECT);
   gTasks[taskId].func = Task_GoToStarterChoice;
   break;
   case 1:
   PlaySE(SE_SELECT);
   gTasks[taskId].func = Task_GoToBeforeBianca;;
   break;
   case 2:
   PlaySE(SE_SELECT);
   gTasks[taskId].func = Task_GoToAfterBianca;
   break;
   case MENU_B_PRESSED:
   case 3:
   PlaySE(SE_SELECT);
   DestroyTask(taskId);
   SetMainCallback2(CB2_FadeAndDoReset);
   break;
   }
   }
   static void CB2_FadeAndDoReset(void)
   {
   switch (gMain.state) {
   case 0:
   default:
   BeginNormalPaletteFade(PALETTES_BG, 0, 0, 0x10, RGB_WHITEALPHA);
   gMain.state = 1;
   break;
   case 1:
   UpdatePaletteFade();
   if (!gPaletteFade.active) {
   FreeAllWindowBuffers();
   DoSoftReset();
   }
   break;
   }
   }
   static void Task_GoToStarterChoice(u8 taskId)
   {
//Erase all variables for a new game
DebugStart_NewGame();
//Skip monologue
VarSet(VAR_STARTER_MON, 1);
//Set callbacks and go to overworld
DebugStart_BeginAdventure();
}
static void Task_GoToBeforeBianca(u8 taskId)
{
//Erase all variables for a new game
DebugStart_NewGame();
//Give player Pokémon to finish playthrough
ScriptContext_SetupScript(ThereCanOnlyBeOne_Debug_Script);
//Set warp to outside the compound, then warp
SetWarpDestination(0, 0, 255, 3, 10);
DoWarp();
//Set callbacks and go to overworld
DebugStart_BeginAdventure();
}
static void Task_GoToAfterBianca(u8 taskId)
{
    //Erase all variables for a new game
    DebugStart_NewGame();
    //Give player Pokémon to finish playthrough
    ScriptContext_SetupScript(ThereCanOnlyBeOne_Debug_Script);
    //Set player to after Bianca's intro
    VarSet(VAR_PLAYER_HOME_STATE, HAS_MET_BIANCA);
    //Set warp to inside the player's room, then warp
    SetWarpDestination(2, 1, 0, -1, -1);
    DoWarp();
    //Set callbacks and go to overworld
    DebugStart_BeginAdventure();
}
static void DebugStart_GenerateID(void)
{
    u32 trainerId = ((Random() << 16) | Random());
    SetTrainerId(trainerId, gSaveBlock2Ptr->playerTrainerId);
}
static void DebugStart_NewGame(void)
{
    FieldClearVBlankHBlankCallbacks();
    StopMapMusic();
    ResetSafariZoneFlag();
    NewGameInitData();
    ResetInitialPlayerAvatarState();
    PlayTimeCounter_Start();
    ScriptContext_Init();
    UnlockPlayerFieldControls();
    gFieldCallback2 = NULL;
    DoMapLoadLoop(&gMain.state);
    SetFieldVBlankCallback();
    DebugStart_GenerateID();
}
static void DebugStart_BeginAdventure(void)
{
    SetMainCallback1(CB1_Overworld);
    SetMainCallback2(CB2_Overworld);
}
*/
