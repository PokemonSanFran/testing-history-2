#include "global.h"
#include "hall_of_fame.h"
#include "task.h"
#include "palette.h"
#include "sprite.h"
#include "pokemon.h"
#include "text.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "main.h"
#include "sound.h"
#include "songs.h"
#include "decompress.h"
#include "save.h"
#include "window.h"
#include "bg.h"
#include "species.h"
#include "game_stat.h"
#include "blend_palette.h"
#include "string_util.h"
#include "m4a.h"
#include "international_string_util.h"
#include "unknown_task.h"
#include "trig.h"
#include "rng.h"
#include "event_data.h"

struct HallofFameMon
{
    u32 tid;
    u32 personality;
    u16 species : 9;
    u16 lvl : 7;
    u8 nick[10];
};

struct HallofFameMons
{
    struct HallofFameMon mons[6];
};

extern struct HallofFameMons *gHofMonsPtr;

struct HofGfx
{
    u16 state;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u8 field_C;
    u8 field_D;
    u8 field_E;
    u8 field_F;
    u8 field_10;
    u8 field_11;
    u8 tilemap1[0x1000];
    u8 tilemap2[0x1000];
};

extern struct HofGfx *gUnknown_0203BCDC;

extern u32 gUnknown_0203BCD4;
extern bool8 HasHallOfFameRecords;
extern u8 gDecompressionBuffer[];
extern struct MusicPlayerInfo gMPlay_BGM;
extern MainCallback gGameContinueCallback;
extern u32 gDamagedSaveSectors;
extern u8 gReservedSpritePaletteCount;

#define HALL_OF_FAME_MAX_TEAMS 50

extern const u8 gUnknown_085E53FC[];
extern const struct SpriteTemplate gUnknown_085E54D0;
extern const struct BgTemplate gUnknown_085E5374[3];
extern const struct CompressedSpriteSheet sHallOfFame_ConfettiSpriteSheet;
extern const struct CompressedSpritePalette sHallOfFame_ConfettiSpritePalette;
extern const u16 gHallOfFame_Pal[];
extern const u8 gUnknown_085E5388[];
extern const u8 gUnknown_085E538C[];
extern const struct HallofFameMon sDummyFameMon;
extern const struct WindowTemplate gUnknown_085E5380;
extern const s16 sHallOfFame_MonsFullTeamPositions[][4];
extern const s16 sHallOfFame_MonsHalfTeamPositions[][4];
extern const u32 gUnknown_085E5508[];

// strings
extern const u8 gText_SavingDontTurnOffPower[];
extern const u8 gText_LeagueChamp[];
extern const u8 gText_HOFNumber[];
extern const u8 gText_PickNextCancel[];
extern const u8 gText_PickCancel[];
extern const u8 gText_UnkCtrlF800Exit[];
extern const u8 gText_HOFCorrupted[];
extern const u8 gText_WelcomeToHOF[];
extern const u8 gText_Number[];
extern const u8 gText_Level[];
extern const u8 gText_IDNumber[];
extern const u8 gText_Name[];
extern const u8 gText_MainMenuTime[];

extern void sub_81973C4(u8, u8);
extern u16 AddTextPrinterParametrized(u8 windowId, u8 fontId, const u8 *str, u8 speed, void ( *callback)(u16, struct TextPrinter *), u8 fgColor, u8 bgColor, u8 shadowColor);
extern void sub_8175620(void);
extern u8 TrySavingData(u8);
extern u8 sub_818D3E4(u16 species, u32 trainerId, u32 personality, u8 flags, s16 x, s16 y, u8, u16);
extern void sub_8197434(u8, u8);
extern u16 sub_818D97C(u8 playerGender, u8);
extern u16 sub_818D8AC(u16, u8, s16, s16, u8, u16);
extern const void* stdpal_get(u8);
extern void sub_80987D4(u8, u8, u16, u8);
extern u16 sub_818D820(u16);
extern u16 sub_818D8F0(u16);
extern u16 sub_818D7D8(u16 species, u32 trainerId, u32 personality, u8 arg3, s16 sp0, s16 sp1, u8 sp2, u16 sp3);
extern void sub_8198204(u8 *dst, const u8 *src, u8, u8, u8);
extern bool8 sub_80F9C30(void);
extern void sub_8198314(void);
extern void sub_8137C3C(void);
extern void sub_8198180(const u8 *src, u8, u8);
extern void sub_80F9BF4(u16, u16, u8);
extern void sub_81980F0(u8, u8, u8, u8, u16);
extern void sub_80F9BCC(u16, u16, u8);
extern bool8 sub_80F9C1C(void);
extern u16 SpeciesToPokedexNum(u16 species);
extern void dp13_810BB8C(void);
extern void sub_81971D0(void);
extern void sub_8197200(void);
extern void sub_8152254(void);
extern void sub_81525D0(u8);
extern void sub_8152438(u8, void*);
extern void sub_8152474(u8, u8, u8);
extern void sub_81522D4(void);
extern bool32 sub_81521C0(u8);
extern u8 sub_81524C4(const void *arg0, s16 arg1, s16 arg2, s16 arg3, s16 arg4, u8 arg5, s16 arg6);

// this file's functions
void ClearVramOamPltt_LoadHofPal(void);
void sub_8174F70(void);
void sub_8174FAC(void);
bool8 sub_81751FC(void);
static void SetCallback2AfterHallOfFameDisplay(void);
bool8 sub_8175024(void);
static void Task_Hof_InitMonData(u8 taskId);
static void Task_Hof_InitTeamSaveData(u8 taskId);
static void Task_Hof_SetMonDisplayTask(u8 taskId);
static void Task_Hof_TrySaveData(u8 taskId);
static void Task_Hof_WaitForFrames(u8 taskId);
static void Task_Hof_DisplayMon(u8 taskId);
static void Task_Hof_PrintMonInfoAfterAnimating(u8 taskId);
static void Task_Hof_TryDisplayAnotherMon(u8 taskId);
static void Task_Hof_PaletteFadeAndPrintWelcomeText(u8 taskId);
static void sub_8173DC0(u8 taskId);
static void sub_8173EA4(u8 taskId);
static void sub_8173EE4(u8 taskId);
static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskId);
static void Task_Hof_ExitOnKeyPressed(u8 taskId);
static void Task_Hof_HandlePaletteOnExit(u8 taskId);
static void Task_Hof_HandleExit(u8 taskId);
static void Task_HofPC_CopySaveData(u8 taskId);
static void Task_HofPC_PrintDataIsCorrupted(u8 taskId);
static void Task_HofPC_DrawSpritesPrintText(u8 taskId);
static void Task_HofPC_PrintMonInfo(u8 taskId);
static void Task_HofPC_HandleInput(u8 taskId);
static void Task_HofPC_HandlePaletteOnExit(u8 taskId);
static void Task_HofPC_HandleExit(u8 taskId);
static void Task_HofPC_ExitOnButtonPress(u8 taskId);
void SpriteCB_GetOnScreenAndAnimate(struct Sprite *sprite);
void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 unused1, u8 unused2);
void HallOfFame_PrintWelcomeText(u8 unusedPossiblyWindowId, u8 unused2);
void HallOfFame_PrintPlayerInfo(u8 unused1, u8 unused2);
void sub_8175364(u8 taskId);

void VBlankCB_HallOfFame(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
}

void CB2_HallOfFame(void)
{
    RunTasks();
    RunTextPrinters();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
}

static bool8 InitHallOfFameScreen(void)
{
    switch (gMain.state)
    {
    case 0:
        SetVBlankCallback(NULL);
        ClearVramOamPltt_LoadHofPal();
        gUnknown_0203BCDC = AllocZeroed(sizeof(*gUnknown_0203BCDC));
        gMain.state = 1;
        break;
    case 1:
        sub_8174F70();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0x3F42);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0x710);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        sub_8174FAC();
        gUnknown_0203BCDC->state = 0;
        gMain.state++;
        break;
    case 3:
        if (!sub_8175024())
        {
            SetVBlankCallback(VBlankCB_HallOfFame);
            BeginNormalPaletteFade(-1, 0, 0x10, 0, 0);
            gMain.state++;
        }
        break;
    case 4:
        UpdatePaletteFade();
        if (!gPaletteFade.active)
        {
            SetMainCallback2(CB2_HallOfFame);
            PlayBGM(BGM_DENDOU);
            return FALSE;
        }
        break;
    }
    return TRUE;
}

#define tDontSaveData       data[0]
#define tDisplayedMonId     data[1]
#define tPokesNumber        data[2]
#define tFrameCount         data[3]
#define tPlayerSpriteID     data[4]
#define tMonSpriteId(i)     data[i + 5]

void CB2_DoHallOfFameScreen(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].tDontSaveData = FALSE;
        gHofMonsPtr = AllocZeroed(sizeof(*gHofMonsPtr));
    }
}

void CB2_DoHallOfFameScreenDontSaveData(void)
{
    if (!InitHallOfFameScreen())
    {
        u8 taskId = CreateTask(Task_Hof_InitMonData, 0);
        gTasks[taskId].tDontSaveData = TRUE;
        gHofMonsPtr = AllocZeroed(sizeof(*gHofMonsPtr));
    }
}

static void Task_Hof_InitMonData(u8 taskId)
{
    u16 i, j;

    gTasks[taskId].tPokesNumber = 0; // valid pokes

    for (i = 0; i < 6; i++)
    {
        u8 nick[POKEMON_NAME_LENGTH + 2];
        if (GetMonData(&gPlayerParty[i], MON_DATA_SPECIES))
        {
            gHofMonsPtr->mons[i].species = GetMonData(&gPlayerParty[i], MON_DATA_SPECIES2);
            gHofMonsPtr->mons[i].tid = GetMonData(&gPlayerParty[i], MON_DATA_OT_ID);
            gHofMonsPtr->mons[i].personality = GetMonData(&gPlayerParty[i], MON_DATA_PERSONALITY);
            gHofMonsPtr->mons[i].lvl = GetMonData(&gPlayerParty[i], MON_DATA_LEVEL);
            GetMonData(&gPlayerParty[i], MON_DATA_NICKNAME, nick);
            for (j = 0; j < POKEMON_NAME_LENGTH; j++)
            {
                gHofMonsPtr->mons[i].nick[j] = nick[j];
            }
            gTasks[taskId].tPokesNumber++;
        }
        else
        {
            gHofMonsPtr->mons[i].species = 0;
            gHofMonsPtr->mons[i].tid = 0;
            gHofMonsPtr->mons[i].personality = 0;
            gHofMonsPtr->mons[i].lvl = 0;
            gHofMonsPtr->mons[i].nick[0] = EOS;
        }
    }

    gUnknown_0203BCD4 = 0;
    gTasks[taskId].tDisplayedMonId = 0;
    gTasks[taskId].tPlayerSpriteID = 0xFF;

    for (i = 0; i < 6; i++)
    {
        gTasks[taskId].tMonSpriteId(i) = 0xFF;
    }

    if (gTasks[taskId].tDontSaveData)
        gTasks[taskId].func = Task_Hof_SetMonDisplayTask;
    else
        gTasks[taskId].func = Task_Hof_InitTeamSaveData;
}

static void Task_Hof_InitTeamSaveData(u8 taskId)
{
    u16 i;
    struct HallofFameMons* lastSavedTeam = (struct HallofFameMons*)(gDecompressionBuffer);

    if (!HasHallOfFameRecords)
    {
        memset(gDecompressionBuffer, 0, 0x2000);
    }
    else
    {
        if (sub_81534D0(3) != TRUE)
            memset(gDecompressionBuffer, 0, 0x2000);
    }

    for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, lastSavedTeam++)
    {
        if (lastSavedTeam->mons[0].species == 0)
            break;
    }
    if (i >= HALL_OF_FAME_MAX_TEAMS)
    {
        struct HallofFameMons *afterTeam = (struct HallofFameMons*)(gDecompressionBuffer);
        struct HallofFameMons *beforeTeam = (struct HallofFameMons*)(gDecompressionBuffer);
        afterTeam++;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS - 1; i++, beforeTeam++, afterTeam++)
        {
            *beforeTeam = *afterTeam;
        }
        lastSavedTeam--;
    }
    *lastSavedTeam = *gHofMonsPtr;

    sub_81973C4(0, 0);
    AddTextPrinterParametrized(0, 1, gText_SavingDontTurnOffPower, 0, NULL, 2, 1, 3);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_Hof_TrySaveData;
}

static void Task_Hof_TrySaveData(u8 taskId)
{
    gGameContinueCallback = CB2_DoHallOfFameScreenDontSaveData;
    if (TrySavingData(3) == 0xFF && gDamagedSaveSectors != 0)
    {
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        FreeAllWindowBuffers();

        if (gUnknown_0203BCDC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203BCDC);
        if (gHofMonsPtr != NULL)
            FREE_AND_SET_NULL(gHofMonsPtr);

        DestroyTask(taskId);
    }
    else
    {
        PlaySE(SE_SAVE);
        gTasks[taskId].func = Task_Hof_WaitForFrames;
        gTasks[taskId].tFrameCount = 32;
    }
}

static void Task_Hof_WaitForFrames(u8 taskId)
{
    if (gTasks[taskId].tFrameCount)
        gTasks[taskId].tFrameCount--;
    else
        gTasks[taskId].func = Task_Hof_SetMonDisplayTask;
}

static void Task_Hof_SetMonDisplayTask(u8 taskId)
{
    gTasks[taskId].func = Task_Hof_DisplayMon;
}

#define tDestinationX  data1
#define tDestinationY  data2
#define tSpecies       data7

static void Task_Hof_DisplayMon(u8 taskId)
{
    u8 spriteId;
    s16 xPos, yPos, field4, field6;

    u16 currMonId = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currMonId];

    if (gTasks[taskId].tPokesNumber > 3)
    {
        xPos = sHallOfFame_MonsFullTeamPositions[currMonId][0];
        yPos = sHallOfFame_MonsFullTeamPositions[currMonId][1];
        field4 = sHallOfFame_MonsFullTeamPositions[currMonId][2];
        field6 = sHallOfFame_MonsFullTeamPositions[currMonId][3];
    }
    else
    {
        xPos = sHallOfFame_MonsHalfTeamPositions[currMonId][0];
        yPos = sHallOfFame_MonsHalfTeamPositions[currMonId][1];
        field4 = sHallOfFame_MonsHalfTeamPositions[currMonId][2];
        field6 = sHallOfFame_MonsHalfTeamPositions[currMonId][3];
    }

    if (currMon->species == SPECIES_EGG)
        field6 += 10;

    spriteId = sub_818D3E4(currMon->species, currMon->tid, currMon->personality, 1, xPos, yPos, currMonId, 0xFFFF);
    gSprites[spriteId].tDestinationX = field4;
    gSprites[spriteId].tDestinationY = field6;
    gSprites[spriteId].data0 = 0;
    gSprites[spriteId].tSpecies = currMon->species;
    gSprites[spriteId].callback = SpriteCB_GetOnScreenAndAnimate;
    gTasks[taskId].tMonSpriteId(currMonId) = spriteId;
    sub_8197434(0, 1);
    gTasks[taskId].func = Task_Hof_PrintMonInfoAfterAnimating;
}

static void Task_Hof_PrintMonInfoAfterAnimating(u8 taskId)
{
    u16 currMonId = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currMonId];
    struct Sprite *monSprite = &gSprites[gTasks[taskId].tMonSpriteId(currMonId)];

    if (monSprite->callback == SpriteCallbackDummy)
    {
        monSprite->oam.affineMode = 0;
        HallOfFame_PrintMonInfo(currMon, 0, 14);
        gTasks[taskId].tFrameCount = 120;
        gTasks[taskId].func = Task_Hof_TryDisplayAnotherMon;
    }
}

static void Task_Hof_TryDisplayAnotherMon(u8 taskId)
{
    u16 currPokeID = gTasks[taskId].tDisplayedMonId;
    struct HallofFameMon* currMon = &gHofMonsPtr->mons[currPokeID];

    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
    }
    else
    {
        gUnknown_0203BCD4 |= (0x10000 << gSprites[gTasks[taskId].tMonSpriteId(currPokeID)].oam.paletteNum);
        if (gTasks[taskId].tDisplayedMonId <= 4 && currMon[1].species != SPECIES_NONE) // there is another pokemon to display
        {
            gTasks[taskId].tDisplayedMonId++;
            BeginNormalPaletteFade(gUnknown_0203BCD4, 0, 12, 12, 0x63B0);
            gSprites[gTasks[taskId].tMonSpriteId(currPokeID)].oam.priority = 1;
            gTasks[taskId].func = Task_Hof_DisplayMon;
        }
        else
        {
            gTasks[taskId].func = Task_Hof_PaletteFadeAndPrintWelcomeText;
        }
    }
}

static void Task_Hof_PaletteFadeAndPrintWelcomeText(u8 taskId)
{
    u16 i;

    BeginNormalPaletteFade(0xFFFF0000, 0, 0, 0, 0);
    for (i = 0; i < 6; i++)
    {
        if (gTasks[taskId].tMonSpriteId(i) != 0xFF)
            gSprites[gTasks[taskId].tMonSpriteId(i)].oam.priority = 0;
    }

    HallOfFame_PrintWelcomeText(0, 15);
    PlaySE(SE_DENDOU);
    gTasks[taskId].tFrameCount = 400;
    gTasks[taskId].func = sub_8173DC0;
}

static void sub_8173DC0(u8 taskId)
{
    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
        if ((gTasks[taskId].tFrameCount & 3) == 0 && gTasks[taskId].tFrameCount > 110)
            sub_81751FC();
    }
    else
    {
        u16 i;
        for (i = 0; i < 6; i++)
        {
            if (gTasks[taskId].tMonSpriteId(i) != 0xFF)
                gSprites[gTasks[taskId].tMonSpriteId(i)].oam.priority = 1;
        }
        BeginNormalPaletteFade(gUnknown_0203BCD4, 0, 12, 12, 0x63B0);
        FillWindowPixelBuffer(0, 0);
        CopyWindowToVram(0, 3);
        gTasks[taskId].tFrameCount = 7;
        gTasks[taskId].func = sub_8173EA4;
    }
}

static void sub_8173EA4(u8 taskId)
{
    if (gTasks[taskId].tFrameCount >= 16)
    {
        gTasks[taskId].func = sub_8173EE4;
    }
    else
    {
        gTasks[taskId].tFrameCount++;
        SetGpuReg(REG_OFFSET_BLDALPHA, gTasks[taskId].tFrameCount * 256);
    }
}

static void sub_8173EE4(u8 taskId)
{
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
    ShowBg(0);
    ShowBg(1);
    ShowBg(3);
    gTasks[taskId].tPlayerSpriteID = sub_818D8AC(sub_818D97C(gSaveBlock2Ptr->playerGender, 1), 1, 120, 72, 6, 0xFFFF);
    AddWindow(&gUnknown_085E5380);
    sub_80987D4(1, gSaveBlock2Ptr->optionsWindowFrameType, 0x21D, 0xD0);
    LoadPalette(stdpal_get(1), 0xE0, 0x20);
    gTasks[taskId].tFrameCount = 120;
    gTasks[taskId].func = Task_Hof_WaitAndPrintPlayerInfo;
}

static void Task_Hof_WaitAndPrintPlayerInfo(u8 taskId)
{
    if (gTasks[taskId].tFrameCount != 0)
    {
        gTasks[taskId].tFrameCount--;
    }
    else if (gSprites[gTasks[taskId].tPlayerSpriteID].pos1.x != 192)
    {
        gSprites[gTasks[taskId].tPlayerSpriteID].pos1.x++;
    }
    else
    {
        FillBgTilemapBufferRect_Palette0(0, 0, 0, 0, 0x20, 0x20);
        HallOfFame_PrintPlayerInfo(1, 2);
        sub_81973C4(0, 0);
        AddTextPrinterParametrized(0, 1, gText_LeagueChamp, 0, NULL, 2, 1, 3);
        CopyWindowToVram(0, 3);
        gTasks[taskId].func = Task_Hof_ExitOnKeyPressed;
    }
}

static void Task_Hof_ExitOnKeyPressed(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
    {
        FadeOutBGM(4);
        gTasks[taskId].func = Task_Hof_HandlePaletteOnExit;
    }
}

static void Task_Hof_HandlePaletteOnExit(u8 taskId)
{
    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    BeginNormalPaletteFade(-1, 8, 0, 0x10, 0);
    gTasks[taskId].func = Task_Hof_HandleExit;
}

static void Task_Hof_HandleExit(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        s32 i;

        for (i = 0; i < 6; i++)
        {
            u8 spriteId = gTasks[taskId].tMonSpriteId(i);
            if (spriteId != 0xFF)
            {
                FreeOamMatrix(gSprites[spriteId].oam.matrixNum);
                sub_818D820(spriteId);
            }
        }

        sub_818D8F0(gTasks[taskId].tPlayerSpriteID);
        HideBg(0);
        HideBg(1);
        HideBg(3);
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskId);

        if (gUnknown_0203BCDC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203BCDC);
        if (gHofMonsPtr != NULL)
            FREE_AND_SET_NULL(gHofMonsPtr);

        SetCallback2AfterHallOfFameDisplay();
    }
}

static void SetCallback2AfterHallOfFameDisplay(void)
{
    SetMainCallback2(sub_8175620);
}

#undef tDontSaveData
#undef tDisplayedPoke
#undef tPokesNumber
#undef tFrameCount
#undef tPlayerSpriteID
#undef tMonSpriteId

#define tCurrTeamNo     data[0]
#define tCurrPageNo     data[1]
#define tCurrPokeId     data[2]
#define tPokesNo        data[4]
#define tMonSpriteId(i) data[i + 5]

void CB2_DoHallOfFamePC(void)
{
    switch (gMain.state)
    {
    case 0:
    default:
        SetVBlankCallback(NULL);
        ClearVramOamPltt_LoadHofPal();
        gUnknown_0203BCDC = AllocZeroed(sizeof(*gUnknown_0203BCDC));
        gMain.state = 1;
        break;
    case 1:
        sub_8174F70();
        gMain.state++;
        break;
    case 2:
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        sub_8174FAC();
        gMain.state++;
        break;
    case 3:
        if (!sub_8175024())
        {
            struct HallofFameMons *fameMons = (struct HallofFameMons*)(gDecompressionBuffer);
            fameMons->mons[0] = sDummyFameMon;
            sub_80F9BCC(0, 0, 0);
            SetVBlankCallback(VBlankCB_HallOfFame);
            gMain.state++;
        }
        break;
    case 4:
        RunTasks();
        AnimateSprites();
        BuildOamBuffer();
        UpdatePaletteFade();
        if (!sub_80F9C1C())
            gMain.state++;
        break;
    case 5:
        {
            u8 taskId, i;

            SetGpuReg(REG_OFFSET_BLDCNT, 0x3F42);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0x710);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            taskId = CreateTask(Task_HofPC_CopySaveData, 0);

            for (i = 0; i < 6; i++)
            {
                gTasks[taskId].tMonSpriteId(i) = 0xFF;
            }

            gHofMonsPtr = AllocZeroed(0x2000);
            SetMainCallback2(CB2_HallOfFame);
        }
        break;
    }
}

static void Task_HofPC_CopySaveData(u8 taskId)
{
    sub_81980F0(0, 0x1E, 0, 0xC, 0x226);
    if (sub_81534D0(3) != 1)
    {
        gTasks[taskId].func = Task_HofPC_PrintDataIsCorrupted;
    }
    else
    {
        u16 i;
        struct HallofFameMons* savedTeams;

        CpuCopy16(gDecompressionBuffer, gHofMonsPtr, 0x2000);
        savedTeams = gHofMonsPtr;
        for (i = 0; i < HALL_OF_FAME_MAX_TEAMS; i++, savedTeams++)
        {
            if (savedTeams->mons[0].species == SPECIES_NONE)
                break;
        }

        if (i < HALL_OF_FAME_MAX_TEAMS)
            gTasks[taskId].tCurrTeamNo = i - 1;
        else
            gTasks[taskId].tCurrTeamNo = HALL_OF_FAME_MAX_TEAMS - 1;

        gTasks[taskId].tCurrPageNo = GetGameStat(GAME_STAT_ENTERED_HOF);

        gTasks[taskId].func = Task_HofPC_DrawSpritesPrintText;
    }
}

static void Task_HofPC_DrawSpritesPrintText(u8 taskId)
{
    struct HallofFameMons* savedTeams = gHofMonsPtr;
    struct HallofFameMon* currMon;
    u16 i;

    for (i = 0; i < gTasks[taskId].tCurrTeamNo; i++)
        savedTeams++;

    currMon = &savedTeams->mons[0];
    gUnknown_0203BCD4 = 0;
    gTasks[taskId].tCurrPokeId = 0;
    gTasks[taskId].tPokesNo = 0;

    for (i = 0; i < 6; i++, currMon++)
    {
        if (currMon->species != 0)
            gTasks[taskId].tPokesNo++;
    }

    currMon = &savedTeams->mons[0];

    for (i = 0; i < 6; i++, currMon++)
    {
        if (currMon->species != 0)
        {
            u16 spriteId;
            s16 posX, posY;

            if (gTasks[taskId].tPokesNo > 3)
            {
                posX = sHallOfFame_MonsFullTeamPositions[i][2];
                posY = sHallOfFame_MonsFullTeamPositions[i][3];
            }
            else
            {
                posX = sHallOfFame_MonsHalfTeamPositions[i][2];
                posY = sHallOfFame_MonsHalfTeamPositions[i][3];
            }

            if (currMon->species == SPECIES_EGG)
                posY += 10;

            spriteId = sub_818D7D8(currMon->species, currMon->tid, currMon->personality, 1, posX, posY, i, 0xFFFF);
            gSprites[spriteId].oam.priority = 1;
            gTasks[taskId].tMonSpriteId(i) = spriteId;
        }
        else
        {
            gTasks[taskId].tMonSpriteId(i) = 0xFF;
        }
    }

    BlendPalettes(0xFFFF0000, 0xC, 0x63B0);

    ConvertIntToDecimalStringN(gStringVar1, gTasks[taskId].tCurrPageNo, STR_CONV_MODE_RIGHT_ALIGN, 3);
    StringExpandPlaceholders(gStringVar4, gText_HOFNumber);

    if (gTasks[taskId].tCurrTeamNo <= 0)
        sub_8198204(gStringVar4, gText_PickCancel, 0, 0, 1);
    else
        sub_8198204(gStringVar4, gText_PickNextCancel, 0, 0, 1);

    gTasks[taskId].func = Task_HofPC_PrintMonInfo;
}

static void Task_HofPC_PrintMonInfo(u8 taskId)
{
    struct HallofFameMons* savedTeams = gHofMonsPtr;
    struct HallofFameMon* currMon;
    u16 i;
    u16 currMonID;

    for (i = 0; i < gTasks[taskId].tCurrTeamNo; i++)
        savedTeams++;

    for (i = 0; i < 6; i++)
    {
        u16 spriteId = gTasks[taskId].tMonSpriteId(i);
        if (spriteId != 0xFF)
            gSprites[spriteId].oam.priority = 1;
    }

    currMonID = gTasks[taskId].tMonSpriteId(gTasks[taskId].tCurrPokeId);
    gSprites[currMonID].oam.priority = 0;
    gUnknown_0203BCD4 = (0x10000 << gSprites[currMonID].oam.paletteNum) ^ 0xFFFF0000;
    BlendPalettesUnfaded(gUnknown_0203BCD4, 0xC, 0x63B0);

    currMon = &savedTeams->mons[gTasks[taskId].tCurrPokeId];
    if (currMon->species != SPECIES_EGG)
    {
        StopCryAndClearCrySongs();
        PlayCry1(currMon->species, 0);
    }
    HallOfFame_PrintMonInfo(currMon, 0, 14);

    gTasks[taskId].func = Task_HofPC_HandleInput;
}

static void Task_HofPC_HandleInput(u8 taskId)
{
    u16 i;

    if (gMain.newKeys & A_BUTTON)
    {
        if (gTasks[taskId].tCurrTeamNo != 0) // prepare another team to view
        {
            gTasks[taskId].tCurrTeamNo--;
            for (i = 0; i < 6; i++)
            {
                u8 spriteId = gTasks[taskId].tMonSpriteId(i);
                if (spriteId != 0xFF)
                {
                    sub_818D820(spriteId);
                    gTasks[taskId].tMonSpriteId(i) = 0xFF;
                }
            }
            if (gTasks[taskId].tCurrPageNo != 0)
                gTasks[taskId].tCurrPageNo--;
            gTasks[taskId].func = Task_HofPC_DrawSpritesPrintText;
        }
        else // no more teams to view, turn off hall of fame PC
        {
            if (IsCryPlayingOrClearCrySongs())
            {
                StopCryAndClearCrySongs();
                m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
            }
            gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
        }
    }
    else if (gMain.newKeys & B_BUTTON) // turn off hall of fame PC
    {
        if (IsCryPlayingOrClearCrySongs())
        {
            StopCryAndClearCrySongs();
            m4aMPlayVolumeControl(&gMPlay_BGM, 0xFFFF, 0x100);
        }
        gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
    }
    else if (gMain.newKeys & DPAD_UP && gTasks[taskId].tCurrPokeId != 0) // change mon -1
    {
        gTasks[taskId].tCurrPokeId--;
        gTasks[taskId].func = Task_HofPC_PrintMonInfo;
    }
    else if (gMain.newKeys & DPAD_DOWN && gTasks[taskId].tCurrPokeId < gTasks[taskId].tPokesNo - 1) // change mon +1
    {
        gTasks[taskId].tCurrPokeId++;
        gTasks[taskId].func = Task_HofPC_PrintMonInfo;
    }
}

static void Task_HofPC_HandlePaletteOnExit(u8 taskId)
{
    struct HallofFameMons* fameMons;

    CpuCopy16(gPlttBufferFaded, gPlttBufferUnfaded, 0x400);
    fameMons = (struct HallofFameMons*)(gDecompressionBuffer);
    fameMons->mons[0] = sDummyFameMon;
    sub_80F9BF4(0, 0, 0);
    gTasks[taskId].func = Task_HofPC_HandleExit;
}

static void Task_HofPC_HandleExit(u8 taskId)
{
    if (!sub_80F9C30())
    {
        u8 i;

        for (i = 0; i < 6; i++)
        {
            u16 spriteId = gTasks[taskId].tMonSpriteId(i);
            if (spriteId != 0xFF)
            {
                sub_818D820(spriteId);
                gTasks[taskId].tMonSpriteId(i) = 0xFF;
            }
        }

        HideBg(0);
        HideBg(1);
        HideBg(3);
        sub_8198314();
        FreeAllWindowBuffers();
        UnsetBgTilemapBuffer(1);
        UnsetBgTilemapBuffer(3);
        ResetBgsAndClearDma3BusyFlags(0);
        DestroyTask(taskId);

        if (gUnknown_0203BCDC != NULL)
            FREE_AND_SET_NULL(gUnknown_0203BCDC);
        if (gHofMonsPtr != NULL)
            FREE_AND_SET_NULL(gHofMonsPtr);

        sub_8137C3C();
    }
}

static void Task_HofPC_PrintDataIsCorrupted(u8 taskId)
{
    sub_8198180(gText_UnkCtrlF800Exit, 8, 1);
    sub_81973C4(0, 0);
    AddTextPrinterParametrized(0, 1, gText_HOFCorrupted, 0, NULL, 2, 1, 3);
    CopyWindowToVram(0, 3);
    gTasks[taskId].func = Task_HofPC_ExitOnButtonPress;
}

static void Task_HofPC_ExitOnButtonPress(u8 taskId)
{
    if (gMain.newKeys & A_BUTTON)
        gTasks[taskId].func = Task_HofPC_HandlePaletteOnExit;
}

#undef tCurrTeamNo
#undef tCurrPageNo
#undef tCurrPokeId
#undef tPokesNo
#undef tMonSpriteId

void HallOfFame_PrintWelcomeText(u8 unusedPossiblyWindowId, u8 unused2)
{
    FillWindowPixelBuffer(0, 0);
    PutWindowTilemap(0);
    box_print(0, 1, GetStringCenterAlignXOffset(1, gText_WelcomeToHOF, 0xD0), 1, gUnknown_085E5388, 0, gText_WelcomeToHOF);
    CopyWindowToVram(0, 3);
}

void HallOfFame_PrintMonInfo(struct HallofFameMon* currMon, u8 unused1, u8 unused2)
{
    u8 text[30];
    u8 *stringPtr;
    s32 dexNumber;
    s32 width;

    FillWindowPixelBuffer(0, 0);
    PutWindowTilemap(0);

    // dex number
    if (currMon->species != SPECIES_EGG)
    {
        stringPtr = StringCopy(text, gText_Number);
        dexNumber = SpeciesToPokedexNum(currMon->species);
        if (dexNumber != 0xFFFF)
        {
            stringPtr[0] = (dexNumber / 100) + CHAR_0;
            stringPtr++;
            dexNumber %= 100;
            stringPtr[0] = (dexNumber / 10) + CHAR_0;
            stringPtr++;
            stringPtr[0] = (dexNumber % 10) + CHAR_0;
            stringPtr++;
        }
        else
        {
            *(stringPtr)++ = CHAR_QUESTION_MARK;
            *(stringPtr)++ = CHAR_QUESTION_MARK;
            *(stringPtr)++ = CHAR_QUESTION_MARK;
        }
        stringPtr[0] = EOS;
        box_print(0, 1, 0x10, 1, gUnknown_085E5388, -1, text);
    }

    // nick, species names, gender and level
    memcpy(text, currMon->nick, POKEMON_NAME_LENGTH);
    text[POKEMON_NAME_LENGTH] = EOS;
    if (currMon->species == SPECIES_EGG)
    {
        width = GetStringCenterAlignXOffset(1, text, 0xD0);
        box_print(0, 1, width, 1, gUnknown_085E5388, -1, text);
        CopyWindowToVram(0, 3);
    }
    else
    {
        width = GetStringRightAlignXOffset(1, text, 0x80);
        box_print(0, 1, width, 1, gUnknown_085E5388, -1, text);

        text[0] = CHAR_SLASH;
        stringPtr = StringCopy(text + 1, gSpeciesNames[currMon->species]);

        if (currMon->species != SPECIES_NIDORAN_M && currMon->species != SPECIES_NIDORAN_F)
        {
            switch (GetGenderFromSpeciesAndPersonality(currMon->species, currMon->personality))
            {
            case MON_MALE:
                stringPtr[0] = CHAR_MALE;
                stringPtr++;
                break;
            case MON_FEMALE:
                stringPtr[0] = CHAR_FEMALE;
                stringPtr++;
                break;
            }
        }

        stringPtr[0] = EOS;
        box_print(0, 1, 0x80, 1, gUnknown_085E5388, -1, text);

        stringPtr = StringCopy(text, gText_Level);
        ConvertIntToDecimalStringN(stringPtr, currMon->lvl, STR_CONV_MODE_LEFT_ALIGN, 3);
        box_print(0, 1, 0x24, 0x11, gUnknown_085E5388, -1, text);

        stringPtr = StringCopy(text, gText_IDNumber);
        ConvertIntToDecimalStringN(stringPtr, (u16)(currMon->tid), STR_CONV_MODE_LEADING_ZEROS, 5);
        box_print(0, 1, 0x68, 0x11, gUnknown_085E5388, -1, text);

        CopyWindowToVram(0, 3);
    }
}

void HallOfFame_PrintPlayerInfo(u8 unused1, u8 unused2)
{
    u8 text[20];
    u32 width;
    u16 trainerId;

    FillWindowPixelBuffer(1, 0x11);
    PutWindowTilemap(1);
    SetWindowBorderStyle(1, FALSE, 0x21D, 0xD);
    box_print(1, 1, 0, 1, gUnknown_085E538C, -1, gText_Name);

    width = GetStringRightAlignXOffset(1, gSaveBlock2Ptr->playerName, 0x70);
    box_print(1, 1, width, 1, gUnknown_085E538C, -1, gSaveBlock2Ptr->playerName);

    trainerId = (gSaveBlock2Ptr->playerTrainerId[0]) | (gSaveBlock2Ptr->playerTrainerId[1] << 8);
    box_print(1, 1, 0, 0x11, gUnknown_085E538C, 0, gText_IDNumber);
    text[0] = (trainerId % 100000) / 10000 + CHAR_0;
    text[1] = (trainerId % 10000) / 1000 + CHAR_0;
    text[2] = (trainerId % 1000) / 100 + CHAR_0;
    text[3] = (trainerId % 100) / 10 + CHAR_0;
    text[4] = (trainerId % 10) / 1 + CHAR_0;
    text[5] = EOS;
    width = GetStringRightAlignXOffset(1, text, 0x70);
    box_print(1, 1, width, 0x11, gUnknown_085E538C, -1, text);

    box_print(1, 1, 0, 0x21, gUnknown_085E538C, -1, gText_MainMenuTime);
    text[0] = (gSaveBlock2Ptr->playTimeHours / 100) + CHAR_0;
    text[1] = (gSaveBlock2Ptr->playTimeHours % 100) / 10 + CHAR_0;
    text[2] = (gSaveBlock2Ptr->playTimeHours % 10) + CHAR_0;

    if (text[0] == CHAR_0)
        text[0] = CHAR_SPACE;
    if (text[0] == CHAR_SPACE && text[1] == CHAR_0)
        text[8] = CHAR_SPACE;

    text[3] = CHAR_COLON;
    text[4] = (gSaveBlock2Ptr->playTimeMinutes % 100) / 10 + CHAR_0;
    text[5] = (gSaveBlock2Ptr->playTimeMinutes % 10) + CHAR_0;
    text[6] = EOS;

    width = GetStringRightAlignXOffset(1, text, 0x70);
    box_print(1, 1, width, 0x21, gUnknown_085E538C, -1, text);

    CopyWindowToVram(1, 3);
}

void ClearVramOamPltt_LoadHofPal(void)
{
    u32 vramOffset, oamOffset, plttOffset;
    u32 vramSize, oamSize, plttSize;

    vramOffset = (VRAM);
    vramSize = VRAM_SIZE;
    while (TRUE)
    {
        DmaFill16(3, 0, vramOffset, 0x1000);
        vramOffset += 0x1000;
        vramSize -= 0x1000;
        if (vramSize <= 0x1000)
        {
            DmaFill16(3, 0, vramOffset, vramSize);
            break;
        }
    }

    oamOffset = OAM;
    oamSize = OAM_SIZE;
    DmaFill32(3, 0, oamOffset, oamSize);

    plttOffset = PLTT;
    plttSize = PLTT_SIZE;
    DmaFill16(3, 0, plttOffset, plttSize);

    ResetPaletteFade();
    LoadPalette(gHallOfFame_Pal, 0, 0x20);
}

void sub_8174F70(void)
{
    remove_some_task();
    ResetTasks();
    ResetSpriteData();
    reset_temp_tile_data_buffers();
    dp13_810BB8C();
    FreeAllSpritePalettes();
    gReservedSpritePaletteCount = 8;
    LoadCompressedObjectPic(&sHallOfFame_ConfettiSpriteSheet);
    LoadCompressedObjectPalette(&sHallOfFame_ConfettiSpritePalette);
}

void sub_8174FAC(void)
{
    ResetBgsAndClearDma3BusyFlags(0);
    InitBgsFromTemplates(0, gUnknown_085E5374, ARRAY_COUNT(gUnknown_085E5374));
    SetBgTilemapBuffer(1, gUnknown_0203BCDC->tilemap1);
    SetBgTilemapBuffer(3, gUnknown_0203BCDC->tilemap2);
    ChangeBgX(0, 0, 0);
    ChangeBgY(0, 0, 0);
    ChangeBgX(1, 0, 0);
    ChangeBgY(1, 0, 0);
    ChangeBgX(3, 0, 0);
    ChangeBgY(3, 0, 0);
}

bool8 sub_8175024(void)
{
    switch (gUnknown_0203BCDC->state)
    {
    case 0:
        decompress_and_copy_tile_data_to_vram(1, gUnknown_085E5508, 0, 0, 0);
        break;
    case 1:
        if (free_temp_tile_data_buffers_if_possible())
            return TRUE;
        break;
    case 2:
        FillBgTilemapBufferRect_Palette0(1, 1, 0, 0, 0x20, 2);
        FillBgTilemapBufferRect_Palette0(1, 0, 0, 3, 0x20, 0xB);
        FillBgTilemapBufferRect_Palette0(1, 1, 0, 0xE, 0x20, 6);
        FillBgTilemapBufferRect_Palette0(3, 2, 0, 0, 0x20, 0x20);

        CopyBgTilemapBufferToVram(1);
        CopyBgTilemapBufferToVram(3);
        break;
    case 3:
        sub_81971D0();
        sub_8197200();
        break;
    case 4:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
        ShowBg(0);
        ShowBg(1);
        ShowBg(3);
        gUnknown_0203BCDC->state = 0;
        return FALSE;
    }

    gUnknown_0203BCDC->state++;
    return TRUE;
}

void SpriteCB_GetOnScreenAndAnimate(struct Sprite *sprite)
{
    if (sprite->pos1.x != sprite->tDestinationX
        || sprite->pos1.y != sprite->tDestinationY)
    {
        if (sprite->pos1.x < sprite->tDestinationX)
            sprite->pos1.x += 15;
        if (sprite->pos1.x > sprite->tDestinationX)
            sprite->pos1.x -= 15;

        if (sprite->pos1.y < sprite->tDestinationY)
            sprite->pos1.y += 10;
        if (sprite->pos1.y > sprite->tDestinationY)
            sprite->pos1.y -= 10;
    }
    else
    {
        s16 species = sprite->tSpecies;

        if (species == SPECIES_EGG)
            DoMonFrontSpriteAnimation(sprite, species, TRUE, 3);
        else
            DoMonFrontSpriteAnimation(sprite, species, FALSE, 3);
    }
}

#undef tDestinationX
#undef tDestinationY
#undef tSpecies

static void sub_81751A4(struct Sprite* sprite)
{
    if (sprite->pos2.y > 120)
    {
        DestroySprite(sprite);
    }
    else
    {
        u16 rand;
        u8 tableID;

        sprite->pos2.y++;
        sprite->pos2.y += sprite->data1;

        tableID = sprite->data0;
        rand = (Random() % 4) + 8;
        sprite->pos2.x = rand * gSineTable[tableID] / 256;

        sprite->data0 += 4;
    }
}

bool8 sub_81751FC(void)
{
    u8 spriteID;
    struct Sprite* sprite;

    s16 posX = Random() % 240;
    s16 posY = -(Random() % 8);

    spriteID = CreateSprite(&gUnknown_085E54D0, posX, posY, 0);
    sprite = &gSprites[spriteID];

    StartSpriteAnim(sprite, Random() % 17);

    if (Random() & 3)
        sprite->data1 = 0;
    else
        sprite->data1 = 1;

    return FALSE;
}

void sub_8175280(void)
{
    u8 taskId;

    gSpecialVar_0x8004 = 180;
    taskId = CreateTask(sub_8175364, 0);
    if (taskId != 0xFF)
    {
        gTasks[taskId].data[1] = gSpecialVar_0x8004;
        gSpecialVar_0x8005 = taskId;
    }
}

void sub_81752C0(void)
{
    u8 taskId;

    if ((taskId = FindTaskIdByFunc(sub_8175364)) != 0xFF)
        DestroyTask(taskId);

    sub_8152254();
    FreeSpriteTilesByTag(0x3E9);
    FreeSpritePaletteByTag(0x3E9);
}

struct UnknownStruct912B4
{
    s16 field_0;
    s16 field_2;
    s16 field_4;
    s16 field_6;
    s16 field_8;
    s16 field_A;
    s16 field_C;
    s16 field_E;
    s16 field_10;
    s16 field_12;
    s16 field_14;
    s16 field_16;
    s16 field_18;
    s16 field_1A;
    s16 field_1C;
    s16 field_1E;
    s16 field_20;
    s16 field_22;
    s16 field_24;
    s16 field_26;
    s16 field_28;
};

void sub_81752F4(struct UnknownStruct912B4 *unkStruct)
{
    if (unkStruct->field_E > 110)
    {
        gTasks[unkStruct->field_28].data[15]--;
        sub_81525D0(unkStruct->field_16);
    }
    else
    {
        u8 var;
        s32 rand;

        unkStruct->field_E++;
        unkStruct->field_E += unkStruct->field_1C;

        var = unkStruct->field_1A;
        rand = Random();
        rand &= 3;
        rand += 8;
        unkStruct->field_C = (rand) * ((gSineTable[var])) / 256;

        unkStruct->field_1A += 4;
    }
}

void sub_8175364(u8 taskId)
{
    u32 var = 0;
    u16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        if (!sub_81521C0(0x40))
        {
            DestroyTask(taskId);
            gSpecialVar_0x8004 = var;
            gSpecialVar_0x8005 = 0xFFFF;
        }
        LoadCompressedObjectPic(&sHallOfFame_ConfettiSpriteSheet);
        LoadCompressedObjectPalette(&sHallOfFame_ConfettiSpritePalette);
        data[0]++;
        break;
    case 1:
        if (data[1] != 0 && data[1] % 3 == 0)
        {
            var = sub_81524C4(gUnknown_085E53FC, 0x3E9, 0x3E9, Random() % 240, -(Random() % 8), Random() % 0x11, var);
            if (var != 0xFF)
            {
                sub_8152438(var, sub_81752F4);
                if ((Random() & 3) == 0)
                    sub_8152474(var, 1, 1);
                sub_8152474(var, 7, taskId);
                data[15]++;
            }
        }
        sub_81522D4();
        if (data[1] != 0)
            data[1]--;
        else if (data[15] == 0)
            data[0] = 0xFF;
        break;
    case 0xFF:
        sub_81752C0();
        gSpecialVar_0x8004 = var;
        gSpecialVar_0x8005 = 0xFFFF;
        break;
    }
}
