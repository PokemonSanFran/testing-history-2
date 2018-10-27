#include "global.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "random.h"
#include "battle_tower.h"
#include "field_specials.h"
#include "battle.h"
#include "script_pokemon_util_80F87D8.h"
#include "main.h"
#include "window.h"
#include "menu.h"
#include "text.h"
#include "battle_records.h"
#include "international_string_util.h"
#include "string_util.h"
#include "constants/battle_frontier.h"

extern u8 gUnknown_0203CEF8[];

extern void (* const gUnknown_08611C18[])(void);
extern const u16 gUnknown_08611BFC[][2];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];
extern const struct WindowTemplate gUnknown_08611C74;

extern void sub_81B8558(void);

// This file's functions.
u8 sub_81A3B30(u8 facility);
void ShowTowerResultsWindow(u8);
void ShowDomeResultsWindow(u8);
void ShowPalaceResultsWindow(u8);
void ShowPikeResultsWindow(void);
void sub_81A2C94(u8);
void ShowArenaResultsWindow(void);
void sub_81A2F38(void);
void sub_81A2FF8(void);

void sub_81A1780(void)
{
    gUnknown_08611C18[gSpecialVar_0x8004]();
}

void sub_81A17A0(void)
{
    VarSet(VAR_TEMP_0, 0xFF);
    switch (gSaveBlock2Ptr->frontier.field_CA8)
    {
    case 0:
        break;
    case 1:
        sub_813A878(0);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 4:
        sub_813A878(0);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 3:
        sub_813A878(1);
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    case 2:
        VarSet(VAR_TEMP_0, gSaveBlock2Ptr->frontier.field_CA8);
        break;
    }
}

void sub_81A1830(void)
{
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 currSymbol = sub_81A3B30(facility);
    if (currSymbol == 2)
        currSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
    case 0:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA8;
        break;
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.lvlMode;
        break;
    case 2:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.curChallengeBattleNum;
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA9_a;
        break;
    case 5:
        gSpecialVar_Result = gBattleOutcome;
        gBattleOutcome = 0;
        break;
    case 6:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_CA9_b;
        break;
    case 7:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.field_D00 & gUnknown_08611BFC[facility][currSymbol];
        break;
    }
}

void sub_81A1968(void)
{
    s32 i;
    u8 facility = VarGet(VAR_FRONTIER_FACILITY);
    u8 currSymbol = sub_81A3B30(facility);
    if (currSymbol == 2)
        currSymbol = 1;

    switch (gSpecialVar_0x8005)
    {
	case 0:
        gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8006;
        break;
    case 1:
        gSaveBlock2Ptr->frontier.lvlMode = gSpecialVar_0x8006;
        break;
    case 2:
        gSaveBlock2Ptr->frontier.curChallengeBattleNum = gSpecialVar_0x8006;
        break;
    case 3:
        gSaveBlock2Ptr->frontier.field_CA9_a = gSpecialVar_0x8006;
        break;
    case 4:
        for (i = 0; i < 4; i++)
            gSaveBlock2Ptr->frontier.selectedPartyMons[i] = gUnknown_0203CEF8[i];
        break;
    case 6:
        gSaveBlock2Ptr->frontier.field_CA9_b = gSpecialVar_0x8006;
        break;
    case 7:
        gSaveBlock2Ptr->frontier.field_D00 |= gUnknown_08611BFC[facility][currSymbol];
        break;
    }
}

void sub_81A1AD4(void)
{
    s32 i;

    sub_81B8558();
    for (i = 0; i < gSpecialVar_0x8005; i++)
        gUnknown_0203CEF8[i] = gSaveBlock2Ptr->frontier.selectedPartyMons[i];
    ReducePlayerPartyToThree();
}

void sub_81A1B1C(void)
{
    DoSoftReset();
}

void sub_81A1B28(void)
{
    gFacilityTrainers = gBattleFrontierTrainers;
}

void sub_81A1B38(void)
{
    u8 i;

    for (i = 0; i < 4; i++)
    {
        u16 monId = gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1;
        if (monId < PARTY_SIZE)
            gSaveBlock1Ptr->playerParty[gSaveBlock2Ptr->frontier.selectedPartyMons[i] - 1] = gPlayerParty[i];
    }
}

void sub_81A1B98(void)
{
    if (gSpecialVar_0x8006 > 3)
        gSpecialVar_0x8006 = 0;
    switch (gSpecialVar_0x8005)
    {
    case 0:
        ShowTowerResultsWindow(gSpecialVar_0x8006);
        break;
    case 1:
        ShowDomeResultsWindow(gSpecialVar_0x8006);
        break;
    case 2:
        ShowPalaceResultsWindow(gSpecialVar_0x8006);
        break;
    case 5:
        ShowPikeResultsWindow();
        break;
    case 4:
        sub_81A2C94(gSpecialVar_0x8006);
        break;
    case 3:
        ShowArenaResultsWindow();
        break;
    case 6:
        sub_81A2F38();
        break;
    case 7:
        sub_81A2FF8();
        break;
    }
}

bool8 sub_81A1C24(u32 flags)
{
    if (gSaveBlock2Ptr->frontier.field_CDC & flags)
        return TRUE;
    else
        return FALSE;
}

void sub_81A1C4C(const u8 *str, s32 y)
{
    s32 x = GetStringCenterAlignXOffset(1, str, 0xE0);
    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x, y, TEXT_SPEED_FF, NULL);
}

void PrintHyphens(s32 y)
{
    s32 i;
    u8 text[37];

    for (i = 0; i < 36; i++)
        text[i] = CHAR_HYPHEN;
    text[i] = EOS;

    y = (y * 8) + 1;
    AddTextPrinterParameterized(gRecordsWindowId, 1, text, 4, y, TEXT_SPEED_FF, NULL);
}

extern const u8 gText_WinStreak[];
extern const u8 gText_Record[];
extern const u8 gText_Current[];
extern const u8 gText_RoomsCleared[];
extern const u8 gText_Prev[];
extern const u8 gText_SingleBattleRoomResults[];
extern const u8 gText_DoubleBattleRoomResults[];
extern const u8 gText_MultiBattleRoomResults[];
extern const u8 gText_LinkMultiBattleRoomResults[];
extern const u8 gText_Lv502[];
extern const u8 gText_OpenLv[];
extern const u8 gText_RentalSwap[];
extern const u8 gText_ClearStreak[];
extern const u8 gText_Total[];
extern const u8 gText_Championships[];
extern const u8 gText_SingleBattleTourneyResults[];
extern const u8 gText_DoubleBattleTourneyResults[];
extern const u8 gText_SingleBattleHallResults[];
extern const u8 gText_DoubleBattleHallResults[];
extern const u8 gText_BattleChoiceResults[];
extern const u8 gText_TimesCleared[];
extern const u8 gText_KOsInARow[];
extern const u8 gText_SetKOTourneyResults[];
extern const u8 gText_TimesVar1[];
extern const u8 gText_BattleSwapSingleResults[];
extern const u8 gText_BattleSwapDoubleResults[];

// Battle Tower.
void TowerPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

void TowerPrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.towerRecordWinStreaks[battleMode][lvlMode];
    TowerPrintStreak(gText_Record, num, x1, x2, y);
}

u16 TowerGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.towerWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

void TowerPrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = TowerGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(2);
        else
            isCurrent = sub_81A1C24(1);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x8000);
        else
            isCurrent = sub_81A1C24(0x4000);
        break;
    case FRONTIER_MODE_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x20000);
        else
            isCurrent = sub_81A1C24(0x10000);
        break;
    case FRONTIER_MODE_LINK_MULTIS:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x80000);
        else
            isCurrent = sub_81A1C24(0x40000);
        break;
    }

    if (isCurrent == TRUE)
        TowerPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        TowerPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

void ShowTowerResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_DOUBLES)
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleRoomResults);
    else if (battleMode == FRONTIER_MODE_MULTIS)
        StringExpandPlaceholders(gStringVar4, gText_MultiBattleRoomResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_LinkMultiBattleRoomResults);

    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 132, 49);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 132, 65);
    TowerPrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 97);
    TowerPrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 132, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Dome.
u16 DomeGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.domeWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

void PrintTwoStrings(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str1, x1, y, TEXT_SPEED_FF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

void DomePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = DomeGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(8);
        else
            isCurrent = sub_81A1C24(4);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x200000);
        else
            isCurrent = sub_81A1C24(0x100000);
        break;
    }

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_ClearStreak, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_ClearStreak, winStreak, x1, x2, y);
}

void ShowDomeResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleTourneyResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleTourneyResults);

    sub_81A1C4C(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 64, 121, 33);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_50], 64, 121, 49);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_50], 64, 112, 65);
    DomePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 64, 121, 97);
    PrintTwoStrings(gText_Record, gText_ClearStreak, gSaveBlock2Ptr->frontier.domeRecordWinStreaks[battleMode][FRONTIER_LVL_OPEN], 64, 121, 113);
    PrintTwoStrings(gText_Total, gText_Championships, gSaveBlock2Ptr->frontier.domeTotalChampionships[battleMode][FRONTIER_LVL_OPEN], 64, 112, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Palace.
void PalacePrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

void PalacePrintRecordStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.palaceRecordWinStreaks[battleMode][lvlMode];
    PalacePrintStreak(gText_Record, num, x1, x2, y);
}

u16 PalaceGetWinStreak(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.palaceWinStreaks[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

void PalacePrintPrevOrCurrentStreak(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PalaceGetWinStreak(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x20);
        else
            isCurrent = sub_81A1C24(0x10);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x800000);
        else
            isCurrent = sub_81A1C24(0x400000);
    }

    if (isCurrent == TRUE)
        PalacePrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        PalacePrintStreak(gText_Prev, winStreak, x1, x2, y);
}

void ShowPalaceResultsWindow(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_SingleBattleHallResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_DoubleBattleHallResults);

    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_50, 72, 131, 49);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_50, 72, 131, 65);
    PalacePrintPrevOrCurrentStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 97);
    PalacePrintRecordStreak(battleMode, FRONTIER_LVL_OPEN, 72, 131, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Pike.
u16 PikeGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.pikeWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

void PikePrintCleared(const u8 *str1, const u8 *str2, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str1, x1, y, TEXT_SPEED_FF, NULL);
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, str2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

void PikePrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = PikeGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x800);
    else
        isCurrent = sub_81A1C24(0x400);

    if (isCurrent == TRUE)
        PrintTwoStrings(gText_Current, gText_RoomsCleared, winStreak, x1, x2, y);
    else
        PrintTwoStrings(gText_Prev, gText_RoomsCleared, winStreak, x1, x2, y);
}

void ShowPikeResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    StringExpandPlaceholders(gStringVar4, gText_BattleChoiceResults);
    sub_81A1C4C(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_50, 64, 114, 33);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_50], 64, 114, 49);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_50], 64, 114, 65);
    PikePrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 64, 114, 97);
    PikePrintCleared(gText_Record, gText_RoomsCleared, gSaveBlock2Ptr->frontier.pikeRecordStreaks[FRONTIER_LVL_OPEN], 64, 114, 113);
    PikePrintCleared(gText_Total, gText_TimesCleared, gSaveBlock2Ptr->frontier.pikeTotalStreaks[FRONTIER_LVL_OPEN], 64, 114, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Arena.
void ArenaPrintStreak(const u8 *str, u16 num, u8 x1, u8 x2, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num > 9999)
        num = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_KOsInARow);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);
}

void ArenaPrintRecordStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    u16 num = gSaveBlock2Ptr->frontier.arenaRecordStreaks[lvlMode];
    ArenaPrintStreak(gText_Record, num, x1, x2, y);
}

u16 ArenaGetWinStreak(u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.arenaWinStreaks[lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

void ArenaPrintPrevOrCurrentStreak(u8 lvlMode, u8 x1, u8 x2, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = ArenaGetWinStreak(lvlMode);

    if (lvlMode != FRONTIER_LVL_50)
        isCurrent = sub_81A1C24(0x80);
    else
        isCurrent = sub_81A1C24(0x40);

    if (isCurrent == TRUE)
        ArenaPrintStreak(gText_Current, winStreak, x1, x2, y);
    else
        ArenaPrintStreak(gText_Prev, winStreak, x1, x2, y);
}

void ShowArenaResultsWindow(void)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    PrintHyphens(10);
    StringExpandPlaceholders(gStringVar4, gText_SetKOTourneyResults);
    sub_81A1C4C(gStringVar4, 2);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 16, 49, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 16, 97, TEXT_SPEED_FF, NULL);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_50, 72, 126, 49);
    ArenaPrintRecordStreak(FRONTIER_LVL_50, 72, 126, 65);
    ArenaPrintPrevOrCurrentStreak(FRONTIER_LVL_OPEN, 72, 126, 97);
    ArenaPrintRecordStreak(FRONTIER_LVL_OPEN, 72, 126, 113);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

// Battle Factory.
void sub_81A2A28(const u8 *str, u16 num1, u16 num2, u8 x1, u8 x2, u8 x3, u8 y)
{
    AddTextPrinterParameterized(gRecordsWindowId, 1, str, x1, y, TEXT_SPEED_FF, NULL);
    if (num1 > 9999)
        num1 = 9999;
    ConvertIntToDecimalStringN(gStringVar1, num1, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_WinStreak);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x2, y, TEXT_SPEED_FF, NULL);

    ConvertIntToDecimalStringN(gStringVar1, num2, STR_CONV_MODE_RIGHT_ALIGN, 4);
    StringExpandPlaceholders(gStringVar4, gText_TimesVar1);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gStringVar4, x3, y, TEXT_SPEED_FF, NULL);
}

void sub_81A2B04(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    u16 num1 = gSaveBlock2Ptr->frontier.field_DEA[battleMode][lvlMode];
    u16 num2 = gSaveBlock2Ptr->frontier.field_DFA[battleMode][lvlMode];
    sub_81A2A28(gText_Record, num1, num2, x1, x2, x3, y);
}

u16 sub_81A2B70(u8 battleMode, u8 lvlMode)
{
    u16 winStreak = gSaveBlock2Ptr->frontier.field_DE2[battleMode][lvlMode];
    if (winStreak > 9999)
        return 9999;
    else
        return winStreak;
}

u16 sub_81A2BA0(u8 battleMode, u8 lvlMode)
{
    u16 rents = gSaveBlock2Ptr->frontier.field_DF2[battleMode][lvlMode];
    if (rents > 9999)
        return 9999;
    else
        return rents;
}

void sub_81A2BD0(u8 battleMode, u8 lvlMode, u8 x1, u8 x2, u8 x3, u8 y)
{
    bool8 isCurrent;
    u16 winStreak = sub_81A2B70(battleMode, lvlMode);
    u16 rents = sub_81A2BA0(battleMode, lvlMode);
    switch (battleMode)
    {
    default:
    case FRONTIER_MODE_SINGLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x200);
        else
            isCurrent = sub_81A1C24(0x100);
        break;
    case FRONTIER_MODE_DOUBLES:
        if (lvlMode != FRONTIER_LVL_50)
            isCurrent = sub_81A1C24(0x2000000);
        else
            isCurrent = sub_81A1C24(0x1000000);
        break;
    }

    if (isCurrent == TRUE)
        sub_81A2A28(gText_Current, winStreak, rents, x1, x2, x3, y);
    else
        sub_81A2A28(gText_Prev, winStreak, rents, x1, x2, x3, y);
}

void sub_81A2C94(u8 battleMode)
{
    gRecordsWindowId = AddWindow(&gUnknown_08611C74);
    NewMenuHelpers_DrawStdWindowFrame(gRecordsWindowId, FALSE);
    FillWindowPixelBuffer(gRecordsWindowId, 0x11);
    if (battleMode == FRONTIER_MODE_SINGLES)
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapSingleResults);
    else
        StringExpandPlaceholders(gStringVar4, gText_BattleSwapDoubleResults);

    sub_81A1C4C(gStringVar4, 0);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_Lv502, 8, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_RentalSwap, 152, 33, TEXT_SPEED_FF, NULL);
    AddTextPrinterParameterized(gRecordsWindowId, 1, gText_OpenLv, 8, 97, TEXT_SPEED_FF, NULL);
    PrintHyphens(10);
    sub_81A2BD0(battleMode, FRONTIER_LVL_50, 8, 64, 158, 49);
    sub_81A2B04(battleMode, FRONTIER_LVL_50, 8, 64, 158, 65);
    sub_81A2BD0(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 113);
    sub_81A2B04(battleMode, FRONTIER_LVL_OPEN, 8, 64, 158, 129);
    PutWindowTilemap(gRecordsWindowId);
    CopyWindowToVram(gRecordsWindowId, 3);
}

