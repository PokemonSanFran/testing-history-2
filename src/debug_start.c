#include "global.h"
#include "task.h"
#include "text.h"
#include "menu.h"
#include "sound.h"
#include "main.h"
#include "save.h"
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

extern const u8 gText_WhereWeDropping[];
extern const u8 gText_Prolouge[];
extern const u8 gText_StarterChoice[];
extern const u8 gText_BeforeFirst[];
extern const u8 gText_AfterFirst[];
extern const u8 gText_Cancel[];

extern u8 ThereCanOnlyBeOne_Debug_Script[];

static const struct MenuAction sMenuActions_DebugStartChoices[] = {
    {gText_Prolouge, NULL},
	{gText_StarterChoice, NULL},
	{gText_BeforeFirst, NULL},
	{gText_AfterFirst, NULL},
	{gText_Cancel, NULL}
};

static bool8 SetupDebugStartScreen(void);
static void InitDebugStartScreenWindows(void);
static void VBlankCB(void);
static void MainCB(void);
static void Task_DoDebugAskQuestion(u8 taskId);
static void ShowDebugStartChoices(void);
static void Task_DebugStartScreenChoice(u8 taskId);
static void CB2_FadeAndDoReset(void);
static void Task_GoToPrologue(u8 taskId);
static void Task_GoToStarterChoice(u8 taskId);
static void Task_GoToBeforeBianca(u8 taskId);
static void Task_GoToAfterBianca(u8 taskId);
static void DebugStart_NewGame(void);
static void DebugStart_BeginAdventure(void);

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

static const struct WindowTemplate sClearSaveTextWindow[] = {
	{
		.bg = 0,
		.tilemapLeft = 3,
		.tilemapTop = 15,
		.width = 26,
		.height = 4,
		.paletteNum = 15,
		.baseBlock = 11,
	},
	DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sDebugStartChoices[] = {
	{
		.bg = 0,
		.tilemapLeft = 3,
		.tilemapTop = 2,
		.width = 20,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 115,
	}
};

void CB2_InitDebugStartScreen(void)
{
	if (SetupDebugStartScreen())
		CreateTask(Task_DoDebugAskQuestion, 0);
}

static bool8 SetupDebugStartScreen(void)
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
			InitDebugStartScreenWindows();
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

static void InitDebugStartScreenWindows(void)
{
	InitWindows(sClearSaveTextWindow);
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

static void Task_DoDebugAskQuestion(u8 taskId)
{
	DrawStdFrameWithCustomTileAndPalette(0, FALSE, 2, 14);
	AddTextPrinterParameterized(0, FONT_NORMAL, gText_WhereWeDropping, 0, 1, 0, 0);
	ShowDebugStartChoices();
	gTasks[taskId].func = Task_DebugStartScreenChoice;
}
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
			gTasks[taskId].func = Task_GoToPrologue;
			break;

		case 1:
			PlaySE(SE_SELECT);
			gTasks[taskId].func = Task_GoToStarterChoice;
			break;
		case 2:
			PlaySE(SE_SELECT);
			gTasks[taskId].func = Task_GoToBeforeBianca;;
			break;
		case 3:
			PlaySE(SE_SELECT);
			gTasks[taskId].func = Task_GoToAfterBianca;
			break;
		case MENU_B_PRESSED:
		case 4:
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

static void Task_GoToPrologue(u8 taskId)
{
	DebugStart_NewGame();
    SetWarpDestination(MAP_GROUP(OAKLANDCOLISEUM_HALLWAY), MAP_NUM(OAKLANDCOLISEUM_HALLWAY), -1, 5, 12);
    WarpIntoMap();
	DebugStart_BeginAdventure();
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
