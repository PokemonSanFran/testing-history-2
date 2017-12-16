#include "global.h"
#include "battle.h"
#include "battle_controllers.h"
#include "link.h"
#include "task.h"
#include "battle_ai_script_commands.h"
#include "battle_anim.h"
#include "pokemon.h"
#include "constants/species.h"
#include "recorded_battle.h"
#include "util.h"
#include "constants/abilities.h"
#include "battle_message.h"

extern u32 gBattleExecBuffer;
extern void (*gBattleMainFunc)(void);
extern void (*gBattleBankFunc[BATTLE_BANKS_COUNT])(void);
extern u8 gBanksByIdentity[BATTLE_BANKS_COUNT];
extern u8 gActionSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gMoveSelectionCursor[BATTLE_BANKS_COUNT];
extern u8 gNoOfAllBanks;
extern u8 gActiveBank;
extern u8 gUnknown_0202428C;
extern u32 gUnknown_02022FF4;
extern u8 gUnknown_0203C7B4;
extern u16 gBattlePartyID[BATTLE_BANKS_COUNT];
extern u8 gBattleBufferA[BATTLE_BANKS_COUNT][0x200];
extern u8 gBattleBufferB[BATTLE_BANKS_COUNT][0x200];
extern u8 gUnknown_02022D08;
extern u8 gUnknown_02022D09;
extern u8 gUnknown_02022D0A;
extern u8 gBankAttacker;
extern u8 gBankTarget;
extern u8 gAbsentBankFlags;
extern u8 gEffectBank;
extern u16 gBattleWeather;
extern struct BattlePokemon gBattleMons[BATTLE_BANKS_COUNT];
extern u16 gCurrentMove;
extern u16 gLastUsedMove;
extern u16 gChosenMove;
extern u16 gLastUsedItem;
extern u8 gBattleOutcome;
extern u8 gLastUsedAbility;
extern u8 gStringBank;

static EWRAM_DATA u8 sBattleBuffersTransferData[0x100] = {};

extern const struct BattleMove gBattleMoves[];

extern void task00_08081A90(u8 taskId); // cable_club
extern void sub_81B8D64(u8 bank, u8 arg1); // party_menu

// this file's funcionts
static void CreateTasksForSendRecvLinkBuffers(void);
static void SetControllersVariablesInLinkBattle(void);
static void SetControllersVariables(void);
static void SetBattlePartyIds(void);
static void Task_HandleSendLinkBuffersData(u8 taskId);
static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId);

void HandleLinkBattleSetup(void)
{
    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        if (gWirelessCommType)
            sub_800B488();
        if (!gReceivedRemoteLinkPlayers)
            OpenLink();
        CreateTask(task00_08081A90, 0);
        CreateTasksForSendRecvLinkBuffers();
    }
}

void SetUpBattleVarsAndBirchZigzagoon(void)
{
    s32 i;

    gBattleMainFunc = nullsub_20;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
    {
        gBattleBankFunc[i] = nullsub_21;
        gBanksByIdentity[i] = 0xFF;
        gActionSelectionCursor[i] = 0;
        gMoveSelectionCursor[i] = 0;
    }

    HandleLinkBattleSetup();
    gBattleExecBuffer = 0;
    ClearBattleAnimationVars();
    ClearBattleMonForms();
    BattleAI_HandleItemUseBeforeAISetup(0xF);

    if (gBattleTypeFlags & BATTLE_TYPE_FIRST_BATTLE)
    {
        ZeroEnemyPartyMons();
        CreateMon(&gEnemyParty[0], SPECIES_ZIGZAGOON, 2, 32, 0, 0, 0, 0);
        i = 0;
        SetMonData(&gEnemyParty[0], MON_DATA_HELD_ITEM, &i);
    }

    gUnknown_02022FF4 = 0;
    gUnknown_0202428C = 0;
}

void sub_8032768(void)
{
    s32 i;
    u8 *data;

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        sub_8184DA4(1);
    else
        sub_8184DA4(2);

    if (!(gBattleTypeFlags & BATTLE_TYPE_RECORDED))
        RecordedBattle_SaveParties();

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
        SetControllersVariablesInLinkBattle();
    else
        SetControllersVariables();

    SetBattlePartyIds();

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gNoOfAllBanks; i++)
            sub_81B8D64(i, 0);
    }

    for (i = 0; i < sizeof(gBattleStruct->field_1A4); i++)
        *(gBattleStruct->field_1A4 + i) = 0;

    for (i = 0; i < sizeof(gBattleStruct->field_204); i++)
        *(gBattleStruct->field_204 + i) = 0;
}

static void SetControllersVariables(void)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_INGAME_PARTNER)
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            gBattleBankFunc[0] = SetControllerToRecordedPlayer;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetControllerToOpponent;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetControllerToPlayerPartner;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetControllerToOpponent;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
        }
        else
        {
            gBattleBankFunc[0] = SetControllerToPlayer;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetControllerToOpponent;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetControllerToPlayerPartner;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetControllerToOpponent;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
        }

        gNoOfAllBanks = 4;

        sub_81B8D64(0, 0);
        sub_81B8D64(1, 0);
        sub_81B8D64(2, 1);
        sub_81B8D64(3, 1);

        gBattlePartyID[0] = 0;
        gBattlePartyID[1] = 0;
        gBattlePartyID[2] = 3;
        gBattlePartyID[3] = 3;
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        gBattleMainFunc = BeginBattleIntro;

        if (gBattleTypeFlags & BATTLE_TYPE_SAFARI)
            gBattleBankFunc[0] = SetControllerToSafari;
        else if (gBattleTypeFlags & BATTLE_TYPE_WALLY_TUTORIAL)
            gBattleBankFunc[0] = SetControllerToWally;
        else
            gBattleBankFunc[0] = SetControllerToPlayer;

        gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

        gBattleBankFunc[1] = SetControllerToOpponent;
        gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

        gNoOfAllBanks = 2;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
            {
                if (gBattleTypeFlags & BATTLE_TYPE_x80000000)
                {
                    gBattleMainFunc = BeginBattleIntro;

                    gBattleBankFunc[0] = SetControllerToRecordedPlayer;
                    gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

                    gBattleBankFunc[1] = SetControllerToRecordedOpponent;
                    gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

                    gNoOfAllBanks = 2;
                }
                else // see how the banks are switched
                {
                    gBattleBankFunc[1] = SetControllerToRecordedPlayer;
                    gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

                    gBattleBankFunc[0] = SetControllerToRecordedOpponent;
                    gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

                    gNoOfAllBanks = 2;
                }
            }
            else
            {
                gBattleBankFunc[0] = SetControllerToRecordedPlayer;
                gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

                gBattleBankFunc[1] = SetControllerToOpponent;
                gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;
            }
        }
    }
    else
    {
        gBattleMainFunc = BeginBattleIntro;

        gBattleBankFunc[0] = SetControllerToPlayer;
        gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

        gBattleBankFunc[1] = SetControllerToOpponent;
        gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

        gBattleBankFunc[2] = SetControllerToPlayer;
        gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

        gBattleBankFunc[3] = SetControllerToOpponent;
        gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

        gNoOfAllBanks = 4;

        if (gBattleTypeFlags & BATTLE_TYPE_RECORDED)
        {
            if (gBattleTypeFlags & BATTLE_TYPE_MULTI && gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
            {
                gBattleMainFunc = BeginBattleIntro;

                gBattleBankFunc[0] = SetControllerToRecordedPlayer;
                gBanksByIdentity[0] = 0;

                gBattleBankFunc[1] = SetControllerToOpponent;
                gBanksByIdentity[1] = 1;

                gBattleBankFunc[2] = SetControllerToRecordedPlayer;
                gBanksByIdentity[2] = 2;

                gBattleBankFunc[3] = SetControllerToOpponent;
                gBanksByIdentity[3] = 3;

                gNoOfAllBanks = 4;

                sub_81B8D64(0, 0);
                sub_81B8D64(1, 0);
                sub_81B8D64(2, 1);
                sub_81B8D64(3, 1);

                gBattlePartyID[0] = 0;
                gBattlePartyID[1] = 0;
                gBattlePartyID[2] = 3;
                gBattlePartyID[3] = 3;
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_MULTI)
            {
                u8 var; // multiplayer Id in a recorded battle?

                for (var = gUnknown_0203C7B4, i = 0; i < BATTLE_BANKS_COUNT; i++)
                {
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        sub_81B8D64(gLinkPlayers[i].lp_field_18, 0);
                        break;
                    case 1:
                    case 2:
                        sub_81B8D64(gLinkPlayers[i].lp_field_18, 1);
                        break;
                    }

                    if (i == var)
                    {
                        gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetControllerToRecordedPlayer;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON1;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON2;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                    else if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[var].lp_field_18 & 1))
                            || ((gLinkPlayers[i].lp_field_18 & 1) && (gLinkPlayers[var].lp_field_18 & 1)))
                    {
                        gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetControllerToRecordedPlayer;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON1;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_PLAYER_MON2;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                    else
                    {
                        gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetControllerToRecordedOpponent;
                        switch (gLinkPlayers[i].lp_field_18)
                        {
                        case 0:
                        case 3:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_OPPONENT_MON1;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                            break;
                        case 1:
                        case 2:
                            gBanksByIdentity[gLinkPlayers[i].lp_field_18] = IDENTITY_OPPONENT_MON2;
                            gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                            break;
                        }
                    }
                }
            }
            else if (gBattleTypeFlags & BATTLE_TYPE_WILD)
            {
                gBattleBankFunc[0] = SetControllerToRecordedPlayer;
                gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

                gBattleBankFunc[2] = SetControllerToRecordedPlayer;
                gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

                if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
                {
                  gBattleBankFunc[1] = SetControllerToRecordedOpponent;
                  gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

                  gBattleBankFunc[3] = SetControllerToRecordedOpponent;
                  gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
                }
                else
                {
                  gBattleBankFunc[1] = SetControllerToOpponent;
                  gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

                  gBattleBankFunc[3] = SetControllerToOpponent;
                  gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;
                }
            }
            else
            {
                gBattleBankFunc[1] = SetControllerToRecordedPlayer;
                gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

                gBattleBankFunc[3] = SetControllerToRecordedPlayer;
                gBanksByIdentity[3] = IDENTITY_PLAYER_MON2;

                if (gBattleTypeFlags & BATTLE_TYPE_x2000000)
                {
                    gBattleBankFunc[0] = SetControllerToRecordedOpponent;
                    gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

                    gBattleBankFunc[2] = SetControllerToRecordedOpponent;
                    gBanksByIdentity[2] = IDENTITY_OPPONENT_MON2;
                }
                else
                {
                    gBattleBankFunc[0] = SetControllerToOpponent;
                    gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

                    gBattleBankFunc[2] = SetControllerToOpponent;
                    gBanksByIdentity[2] = IDENTITY_OPPONENT_MON2;
                }
            }
        }
    }
}

static void SetControllersVariablesInLinkBattle(void)
{
    s32 i;
    u8 multiplayerId;

    if (!(gBattleTypeFlags & BATTLE_TYPE_DOUBLE))
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattleBankFunc[0] = SetControllerToPlayer;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetControllerToLinkOpponent;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gNoOfAllBanks = 2;
        }
        else
        {
            gBattleBankFunc[1] = SetControllerToPlayer;
            gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[0] = SetControllerToLinkOpponent;
            gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

            gNoOfAllBanks = 2;
        }
    }
    else if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI) && gBattleTypeFlags & BATTLE_TYPE_DOUBLE)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattleBankFunc[0] = SetControllerToPlayer;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetControllerToLinkOpponent;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetControllerToPlayer;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetControllerToLinkOpponent;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }
        else
        {
            gBattleBankFunc[1] = SetControllerToPlayer;
            gBanksByIdentity[1] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[0] = SetControllerToLinkOpponent;
            gBanksByIdentity[0] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[3] = SetControllerToPlayer;
            gBanksByIdentity[3] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[2] = SetControllerToLinkOpponent;
            gBanksByIdentity[2] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }
    }
    else if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
    {
        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
        {
            gBattleMainFunc = BeginBattleIntro;

            gBattleBankFunc[0] = SetControllerToPlayer;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetControllerToOpponent;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetControllerToLinkPartner;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetControllerToOpponent;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }
        else
        {
            gBattleBankFunc[0] = SetControllerToLinkPartner;
            gBanksByIdentity[0] = IDENTITY_PLAYER_MON1;

            gBattleBankFunc[1] = SetControllerToLinkOpponent;
            gBanksByIdentity[1] = IDENTITY_OPPONENT_MON1;

            gBattleBankFunc[2] = SetControllerToPlayer;
            gBanksByIdentity[2] = IDENTITY_PLAYER_MON2;

            gBattleBankFunc[3] = SetControllerToLinkOpponent;
            gBanksByIdentity[3] = IDENTITY_OPPONENT_MON2;

            gNoOfAllBanks = 4;
        }

        sub_81B8D64(0, 0);
        sub_81B8D64(1, 0);
        sub_81B8D64(2, 1);
        sub_81B8D64(3, 1);
        gBattlePartyID[0] = 0;
        gBattlePartyID[1] = 0;
        gBattlePartyID[2] = 3;
        gBattlePartyID[3] = 3;
    }
    else
    {
        multiplayerId = GetMultiplayerId();

        if (gBattleTypeFlags & BATTLE_TYPE_WILD)
            gBattleMainFunc = BeginBattleIntro;

        for (i = 0; i < BATTLE_BANKS_COUNT; i++)
        {
            switch (gLinkPlayers[i].lp_field_18)
            {
            case 0:
            case 3:
                sub_81B8D64(gLinkPlayers[i].lp_field_18, 0);
                break;
            case 1:
            case 2:
                sub_81B8D64(gLinkPlayers[i].lp_field_18, 1);
                break;
            }

            if (i == multiplayerId)
            {
                gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetControllerToPlayer;
                switch (gLinkPlayers[i].lp_field_18)
                {
                case 0:
                case 3:
                    gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 0;
                    gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                    break;
                case 1:
                case 2:
                    gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 2;
                    gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                    break;
                }
            }
            else
            {
                if ((!(gLinkPlayers[i].lp_field_18 & 1) && !(gLinkPlayers[multiplayerId].lp_field_18 & 1))
                 || ((gLinkPlayers[i].lp_field_18 & 1) && (gLinkPlayers[multiplayerId].lp_field_18 & 1)))
                {
                    gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetControllerToLinkPartner;
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 0;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                        break;
                    case 1:
                    case 2:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 2;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                        break;
                    }
                }
                else
                {
                    gBattleBankFunc[gLinkPlayers[i].lp_field_18] = SetControllerToLinkOpponent;
                    switch (gLinkPlayers[i].lp_field_18)
                    {
                    case 0:
                    case 3:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 1;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 0;
                        break;
                    case 1:
                    case 2:
                        gBanksByIdentity[gLinkPlayers[i].lp_field_18] = 3;
                        gBattlePartyID[gLinkPlayers[i].lp_field_18] = 3;
                        break;
                    }
                }
            }
        }

        gNoOfAllBanks = 4;
    }
}

static void SetBattlePartyIds(void)
{
    s32 i, j;

    if (!(gBattleTypeFlags & BATTLE_TYPE_MULTI))
    {
        for (i = 0; i < gNoOfAllBanks; i++)
        {
            for (j = 0; j < 6; j++)
            {
                if (i < 2)
                {
                    if (GET_BANK_SIDE2(i) == SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG) == 0)
                        {
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG) == 0)
                        {
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                }
                else
                {
                    if (GET_BANK_SIDE2(i) == SIDE_PLAYER)
                    {
                        if (GetMonData(&gPlayerParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES) != SPECIES_NONE  // Probably a typo by Game Freak. The rest use SPECIES2.
                         && GetMonData(&gPlayerParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gPlayerParty[j], MON_DATA_IS_EGG) == 0
                         && gBattlePartyID[i - 2] != j)
                        {
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                    else
                    {
                        if (GetMonData(&gEnemyParty[j], MON_DATA_HP) != 0
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_NONE
                         && GetMonData(&gEnemyParty[j], MON_DATA_SPECIES2) != SPECIES_EGG
                         && GetMonData(&gEnemyParty[j], MON_DATA_IS_EGG) == 0
                         && gBattlePartyID[i - 2] != j)
                        {
                            gBattlePartyID[i] = j;
                            break;
                        }
                    }
                }
            }
        }

        if (gBattleTypeFlags & BATTLE_TYPE_TWO_OPPONENTS)
            gBattlePartyID[1] = 0, gBattlePartyID[3] = 3;
    }
}

static void PrepareBufferDataTransfer(u8 bufferId, u8 *data, u16 size)
{
    s32 i;

    if (gBattleTypeFlags & BATTLE_TYPE_LINK)
    {
        PrepareBufferDataTransferLink(bufferId, size, data);
    }
    else
    {
        switch (bufferId)
        {
        case 0:
            for (i = 0; i < size; i++)
            {
                gBattleBufferA[gActiveBank][i] = *data;
                data++;
            }
            break;
        case 1:
            for (i = 0; i < size; i++)
            {
                gBattleBufferB[gActiveBank][i] = *data;
                data++;
            }
            break;
        }
    }
}

static void CreateTasksForSendRecvLinkBuffers(void)
{
    gUnknown_02022D08 = CreateTask(Task_HandleSendLinkBuffersData, 0);
    gTasks[gUnknown_02022D08].data[11] = 0;
    gTasks[gUnknown_02022D08].data[12] = 0;
    gTasks[gUnknown_02022D08].data[13] = 0;
    gTasks[gUnknown_02022D08].data[14] = 0;
    gTasks[gUnknown_02022D08].data[15] = 0;

    gUnknown_02022D09 = CreateTask(Task_HandleCopyReceivedLinkBuffersData, 0);
    gTasks[gUnknown_02022D09].data[12] = 0;
    gTasks[gUnknown_02022D09].data[13] = 0;
    gTasks[gUnknown_02022D09].data[14] = 0;
    gTasks[gUnknown_02022D09].data[15] = 0;

    gUnknown_02022D0A = 0;
}

enum
{
    LINK_BUFF_BUFFER_ID,
    LINK_BUFF_ACTIVE_BANK,
    LINK_BUFF_ATTACKER,
    LINK_BUFF_TARGET,
    LINK_BUFF_SIZE_LO,
    LINK_BUFF_SIZE_HI,
    LINK_BUFF_ABSENT_BANK_FLAGS,
    LINK_BUFF_EFFECT_BANK,
    LINK_BUFF_DATA
};

void PrepareBufferDataTransferLink(u8 bufferId, u16 size, u8 *data)
{
    s32 alignedSize;
    s32 i;

    alignedSize = size - size % 4 + 4;
    if (gTasks[gUnknown_02022D08].data[14] + alignedSize + LINK_BUFF_DATA + 1 > BATTLE_BUFFER_LINK_SIZE)
    {
        gTasks[gUnknown_02022D08].data[12] = gTasks[gUnknown_02022D08].data[14];
        gTasks[gUnknown_02022D08].data[14] = 0;
    }
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_BUFFER_ID] = bufferId;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ACTIVE_BANK] = gActiveBank;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ATTACKER] = gBankAttacker;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_TARGET] = gBankTarget;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_SIZE_LO] = alignedSize;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_SIZE_HI] = (alignedSize & 0x0000FF00) >> 8;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_ABSENT_BANK_FLAGS] = gAbsentBankFlags;
    gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_EFFECT_BANK] = gEffectBank;

    for (i = 0; i < size; i++)
        gLinkBattleSendBuffer[gTasks[gUnknown_02022D08].data[14] + LINK_BUFF_DATA + i] = data[i];

    gTasks[gUnknown_02022D08].data[14] = gTasks[gUnknown_02022D08].data[14] + alignedSize + LINK_BUFF_DATA;
}

static void Task_HandleSendLinkBuffersData(u8 taskId)
{
    u16 var;
    u16 blockSize;

    switch (gTasks[taskId].data[11])
    {
    case 0:
        gTasks[taskId].data[10] = 100;
        gTasks[taskId].data[11]++;
        break;
    case 1:
        gTasks[taskId].data[10]--;
        if (gTasks[taskId].data[10] == 0)
            gTasks[taskId].data[11]++;
        break;
    case 2:
        if (gWirelessCommType)
        {
            gTasks[taskId].data[11]++;
        }
        else
        {
            if (gBattleTypeFlags & BATTLE_TYPE_BATTLE_TOWER)
                var = 2;
            else
                var = (gBattleTypeFlags & BATTLE_TYPE_MULTI) ? 4 : 2;

            if (GetLinkPlayerCount_2() >= var)
            {
                if (IsLinkMaster())
                {
                    sub_800A620();
                    gTasks[taskId].data[11]++;
                }
                else
                {
                    gTasks[taskId].data[11]++;
                }
            }
        }
        break;
    case 3:
        if (gTasks[taskId].data[15] != gTasks[taskId].data[14])
        {
            if (gTasks[taskId].data[13] == 0)
            {
                if (gTasks[taskId].data[15] > gTasks[taskId].data[14]
                 && gTasks[taskId].data[15] == gTasks[taskId].data[12])
                {
                    gTasks[taskId].data[12] = 0;
                    gTasks[taskId].data[15] = 0;
                }
                blockSize = (gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_LO] | (gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_HI] << 8)) + LINK_BUFF_DATA;
                SendBlock(bitmask_all_link_players_but_self(), &gLinkBattleSendBuffer[gTasks[taskId].data[15]], blockSize);
                gTasks[taskId].data[11]++;
            }
            else
            {
                gTasks[taskId].data[13]--;
                break;
            }
        }
        break;
    case 4:
        if (sub_800A520())
        {
            blockSize = gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_LO] | (gLinkBattleSendBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_HI] << 8);
            gTasks[taskId].data[13] = 1;
            gTasks[taskId].data[15] = gTasks[taskId].data[15] + blockSize + LINK_BUFF_DATA;
            gTasks[taskId].data[11] = 3;
        }
        break;
    case 5:
        gTasks[taskId].data[13]--;
        if (gTasks[taskId].data[13] == 0)
        {
            gTasks[taskId].data[13] = 1;
            gTasks[taskId].data[11] = 3;
        }
        break;
    }
}

// fix me
void sub_8033648(void)
{
    u8 i;
    s32 j;
    u16 r6;
    u8 *recvBuffer;
    u8 *dest;
    u8 *src;

    if (gReceivedRemoteLinkPlayers != 0 && (gBattleTypeFlags & BATTLE_TYPE_20))
    {
        sub_8011BD0();
        for (i = 0; i < GetLinkPlayerCount(); i++)
        {
            if (GetBlockReceivedStatus() & gBitTable[i])
            {
                ResetBlockReceivedFlag(i);
                recvBuffer = (u8 *)gBlockRecvBuffer[i];
                #ifndef NONMATCHING
                    asm("");
                    recvBuffer = (u8 *)&gBlockRecvBuffer[i];
                #endif
                r6 = gBlockRecvBuffer[i][2];

                if (gTasks[gUnknown_02022D09].data[14] + 9 + r6 > 0x1000)
                {
                    gTasks[gUnknown_02022D09].data[12] = gTasks[gUnknown_02022D09].data[14];
                    gTasks[gUnknown_02022D09].data[14] = 0;
                }

                dest = &gLinkBattleRecvBuffer[gTasks[gUnknown_02022D09].data[14]];
                src = recvBuffer;

                for (j = 0; j < r6 + 8; j++)
                    dest[j] = src[j];

                gTasks[gUnknown_02022D09].data[14] = gTasks[gUnknown_02022D09].data[14] + r6 + 8;
            }
        }
    }
}

static void Task_HandleCopyReceivedLinkBuffersData(u8 taskId)
{
    u16 blockSize;
    u8 bank;
    u8 var;

    if (gTasks[taskId].data[15] != gTasks[taskId].data[14])
    {
        if (gTasks[taskId].data[15] > gTasks[taskId].data[14]
         && gTasks[taskId].data[15] == gTasks[taskId].data[12])
        {
            gTasks[taskId].data[12] = 0;
            gTasks[taskId].data[15] = 0;
        }
        bank = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_ACTIVE_BANK];
        blockSize = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_LO] | (gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_SIZE_HI] << 8);

        switch (gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 0])
        {
        case 0:
            if (gBattleExecBuffer & gBitTable[bank])
                return;

            memcpy(gBattleBufferA[bank], &gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 8], blockSize);
            sub_803F850(bank);

            if (!(gBattleTypeFlags & BATTLE_TYPE_WILD))
            {
                gBankAttacker = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 2];
                gBankTarget = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 3];
                gAbsentBankFlags = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 6];
                gEffectBank = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 7];
            }
            break;
        case 1:
            memcpy(gBattleBufferB[bank], &gLinkBattleRecvBuffer[gTasks[taskId].data[15] + 8], blockSize);
            break;
        case 2:
            var = gLinkBattleRecvBuffer[gTasks[taskId].data[15] + LINK_BUFF_DATA];
            gBattleExecBuffer &= ~(gBitTable[bank] << (var * 4));
            break;
        }

        gTasks[taskId].data[15] = gTasks[taskId].data[15] + blockSize + LINK_BUFF_DATA;
    }
}

void EmitGetMonData(u8 bufferId, u8 requestId, u8 monToCheck)
{
    sBattleBuffersTransferData[0] = CONTROLLER_GETMONDATA;
    sBattleBuffersTransferData[1] = requestId;
    sBattleBuffersTransferData[2] = monToCheck;
    sBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitGetRawMonData(u8 bufferId, u8 monId, u8 bytes)
{
    sBattleBuffersTransferData[0] = CONTROLLER_GETRAWMONDATA;
    sBattleBuffersTransferData[1] = monId;
    sBattleBuffersTransferData[2] = bytes;
    sBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitSetMonData(u8 bufferId, u8 requestId, u8 monToCheck, u8 bytes, void *data)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_SETMONDATA;
    sBattleBuffersTransferData[1] = requestId;
    sBattleBuffersTransferData[2] = monToCheck;
    for (i = 0; i < bytes; i++)
        sBattleBuffersTransferData[3 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 3 + bytes);
}

void EmitSetRawMonData(u8 bufferId, u8 monId, u8 bytes, void *data)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_SETRAWMONDATA;
    sBattleBuffersTransferData[1] = monId;
    sBattleBuffersTransferData[2] = bytes;
    for (i = 0; i < bytes; i++)
        sBattleBuffersTransferData[3 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, bytes + 3);
}

void EmitLoadMonSprite(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_LOADMONSPRITE;
    sBattleBuffersTransferData[1] = CONTROLLER_LOADMONSPRITE;
    sBattleBuffersTransferData[2] = CONTROLLER_LOADMONSPRITE;
    sBattleBuffersTransferData[3] = CONTROLLER_LOADMONSPRITE;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitSwitchInAnim(u8 bufferId, u8 partyId, bool8 dontClearSubstituteBit)
{
    sBattleBuffersTransferData[0] = CONTROLLER_SWITCHINANIM;
    sBattleBuffersTransferData[1] = partyId;
    sBattleBuffersTransferData[2] = dontClearSubstituteBit;
    sBattleBuffersTransferData[3] = 5;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitReturnMonToBall(u8 bufferId, u8 arg1)
{
    sBattleBuffersTransferData[0] = CONTROLLER_RETURNMONTOBALL;
    sBattleBuffersTransferData[1] = arg1;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 2);
}

void EmitDrawTrainerPic(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_DRAWTRAINERPIC;
    sBattleBuffersTransferData[1] = CONTROLLER_DRAWTRAINERPIC;
    sBattleBuffersTransferData[2] = CONTROLLER_DRAWTRAINERPIC;
    sBattleBuffersTransferData[3] = CONTROLLER_DRAWTRAINERPIC;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitTrainerSlide(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_TRAINERSLIDE;
    sBattleBuffersTransferData[1] = CONTROLLER_TRAINERSLIDE;
    sBattleBuffersTransferData[2] = CONTROLLER_TRAINERSLIDE;
    sBattleBuffersTransferData[3] = CONTROLLER_TRAINERSLIDE;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitTrainerSlideBack(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_TRAINERSLIDEBACK;
    sBattleBuffersTransferData[1] = CONTROLLER_TRAINERSLIDEBACK;
    sBattleBuffersTransferData[2] = CONTROLLER_TRAINERSLIDEBACK;
    sBattleBuffersTransferData[3] = CONTROLLER_TRAINERSLIDEBACK;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitFaintAnimation(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_FAINTANIMATION;
    sBattleBuffersTransferData[1] = CONTROLLER_FAINTANIMATION;
    sBattleBuffersTransferData[2] = CONTROLLER_FAINTANIMATION;
    sBattleBuffersTransferData[3] = CONTROLLER_FAINTANIMATION;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitPaletteFade(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_PALETTEFADE;
    sBattleBuffersTransferData[1] = CONTROLLER_PALETTEFADE;
    sBattleBuffersTransferData[2] = CONTROLLER_PALETTEFADE;
    sBattleBuffersTransferData[3] = CONTROLLER_PALETTEFADE;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitSuccessBallThrowAnim(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_SUCCESSBALLTHROWANIM;
    sBattleBuffersTransferData[1] = CONTROLLER_SUCCESSBALLTHROWANIM;
    sBattleBuffersTransferData[2] = CONTROLLER_SUCCESSBALLTHROWANIM;
    sBattleBuffersTransferData[3] = CONTROLLER_SUCCESSBALLTHROWANIM;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitBallThrowAnim(u8 bufferId, u8 caseId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_BALLTHROWANIM;
    sBattleBuffersTransferData[1] = caseId;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 2);
}

void EmitPause(u8 bufferId, u8 toWait, void *data)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_PAUSE;
    sBattleBuffersTransferData[1] = toWait;
    for (i = 0; i < toWait * 3; i++)
        sBattleBuffersTransferData[2 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, toWait * 3 + 2);
}

void EmitMoveAnimation(u8 bufferId, u16 move, u8 turnOfMove, u16 movePower, s32 dmg, u8 friendship, struct DisableStruct *disableStructPtr, u8 multihit)
{
    sBattleBuffersTransferData[0] = CONTROLLER_MOVEANIMATION;
    sBattleBuffersTransferData[1] = move;
    sBattleBuffersTransferData[2] = (move & 0xFF00) >> 8;
    sBattleBuffersTransferData[3] = turnOfMove;
    sBattleBuffersTransferData[4] = movePower;
    sBattleBuffersTransferData[5] = (movePower & 0xFF00) >> 8;
    sBattleBuffersTransferData[6] = dmg;
    sBattleBuffersTransferData[7] = (dmg & 0x0000FF00) >> 8;
    sBattleBuffersTransferData[8] = (dmg & 0x00FF0000) >> 16;
    sBattleBuffersTransferData[9] = (dmg & 0xFF000000) >> 24;
    sBattleBuffersTransferData[10] = friendship;
    sBattleBuffersTransferData[11] = multihit;
    if (WEATHER_HAS_EFFECT2)
    {
        sBattleBuffersTransferData[12] = gBattleWeather;
        sBattleBuffersTransferData[13] = (gBattleWeather & 0xFF00) >> 8;
    }
    else
    {
        sBattleBuffersTransferData[12] = 0;
        sBattleBuffersTransferData[13] = 0;
    }
    sBattleBuffersTransferData[14] = 0;
    sBattleBuffersTransferData[15] = 0;
    memcpy(&sBattleBuffersTransferData[16], disableStructPtr, sizeof(struct DisableStruct));
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 16 + sizeof(struct DisableStruct));
}

void EmitPrintString(u8 bufferId, u16 stringID)
{
    s32 i;
    struct StringInfoBattle* stringInfo;

    sBattleBuffersTransferData[0] = CONTROLLER_PRINTSTRING;
    sBattleBuffersTransferData[1] = gBattleOutcome;
    sBattleBuffersTransferData[2] = stringID;
    sBattleBuffersTransferData[3] = (stringID & 0xFF00) >> 8;

    stringInfo = (struct StringInfoBattle*)(&sBattleBuffersTransferData[4]);
    stringInfo->currentMove = gCurrentMove;
    stringInfo->originallyUsedMove = gChosenMove;
    stringInfo->lastItem = gLastUsedItem;
    stringInfo->lastAbility = gLastUsedAbility;
    stringInfo->scrActive = gBattleScripting.bank;
    stringInfo->unk1605E = gBattleStruct->field_52;
    stringInfo->hpScale = gBattleStruct->hpScale;
    stringInfo->StringBank = gStringBank;
    stringInfo->moveType = gBattleMoves[gCurrentMove].type;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
        stringInfo->abilities[i] = gBattleMons[i].ability;
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        stringInfo->textBuffs[0][i] = gBattleTextBuff1[i];
        stringInfo->textBuffs[1][i] = gBattleTextBuff2[i];
        stringInfo->textBuffs[2][i] = gBattleTextBuff3[i];
    }
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, sizeof(struct StringInfoBattle) + 4);
}

void EmitPrintSelectionString(u8 bufferId, u16 stringID)
{
    s32 i;
    struct StringInfoBattle *stringInfo;

    sBattleBuffersTransferData[0] = CONTROLLER_PRINTSTRINGPLAYERONLY;
    sBattleBuffersTransferData[1] = CONTROLLER_PRINTSTRINGPLAYERONLY;
    sBattleBuffersTransferData[2] = stringID;
    sBattleBuffersTransferData[3] = (stringID & 0xFF00) >> 8;

    stringInfo = (struct StringInfoBattle*)(&sBattleBuffersTransferData[4]);
    stringInfo->currentMove = gCurrentMove;
    stringInfo->originallyUsedMove = gChosenMove;
    stringInfo->lastItem = gLastUsedItem;
    stringInfo->lastAbility = gLastUsedAbility;
    stringInfo->scrActive = gBattleScripting.bank;
    stringInfo->unk1605E = gBattleStruct->field_52;

    for (i = 0; i < BATTLE_BANKS_COUNT; i++)
        stringInfo->abilities[i] = gBattleMons[i].ability;
    for (i = 0; i < TEXT_BUFF_ARRAY_COUNT; i++)
    {
        stringInfo->textBuffs[0][i] = gBattleTextBuff1[i];
        stringInfo->textBuffs[1][i] = gBattleTextBuff2[i];
        stringInfo->textBuffs[2][i] = gBattleTextBuff3[i];
    }
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, sizeof(struct StringInfoBattle) + 4);
}

void EmitChooseAction(u8 bufferId, u8 arg1, u16 arg2)
{
    sBattleBuffersTransferData[0] = CONTROLLER_CHOOSEACTION;
    sBattleBuffersTransferData[1] = arg1;
    sBattleBuffersTransferData[2] = arg2;
    sBattleBuffersTransferData[3] = (arg2 & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitUnknownYesNoBox(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_UNKNOWNYESNOBOX;
    sBattleBuffersTransferData[1] = CONTROLLER_UNKNOWNYESNOBOX;
    sBattleBuffersTransferData[2] = CONTROLLER_UNKNOWNYESNOBOX;
    sBattleBuffersTransferData[3] = CONTROLLER_UNKNOWNYESNOBOX;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitChooseMove(u8 bufferId, bool8 isDoubleBattle, bool8 NoPpNumber, struct ChooseMoveStruct *movePpData)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_CHOOSEMOVE;
    sBattleBuffersTransferData[1] = isDoubleBattle;
    sBattleBuffersTransferData[2] = NoPpNumber;
    sBattleBuffersTransferData[3] = 0;
    for (i = 0; i < sizeof(*movePpData); i++)
        sBattleBuffersTransferData[4 + i] = *((u8*)(movePpData) + i);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, sizeof(*movePpData) + 4);
}

void EmitChooseItem(u8 bufferId, u8 *arg1)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_OPENBAG;
    for (i = 0; i < 3; i++)
        sBattleBuffersTransferData[1 + i] = arg1[i];
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitChoosePokemon(u8 bufferId, u8 caseId, u8 arg2, u8 abilityId, u8* arg4)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_CHOOSEPOKEMON;
    sBattleBuffersTransferData[1] = caseId;
    sBattleBuffersTransferData[2] = arg2;
    sBattleBuffersTransferData[3] = abilityId;
    for (i = 0; i < 3; i++)
        sBattleBuffersTransferData[4 + i] = arg4[i];
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 8);  // but only 7 bytes were written
}

void EmitCmd23(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_23;
    sBattleBuffersTransferData[1] = CONTROLLER_23;
    sBattleBuffersTransferData[2] = CONTROLLER_23;
    sBattleBuffersTransferData[3] = CONTROLLER_23;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

// why is the argument u16 if it's being cast to s16 anyway?
void EmitHealthBarUpdate(u8 bufferId, u16 hpValue)
{
    sBattleBuffersTransferData[0] = CONTROLLER_HEALTHBARUPDATE;
    sBattleBuffersTransferData[1] = 0;
    sBattleBuffersTransferData[2] = (s16)hpValue;
    sBattleBuffersTransferData[3] = ((s16)hpValue & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

// why is the argument u16 if it's being cast to s16 anyway?
void EmitExpUpdate(u8 bufferId, u8 partyId, u16 expPoints)
{
    sBattleBuffersTransferData[0] = CONTROLLER_EXPUPDATE;
    sBattleBuffersTransferData[1] = partyId;
    sBattleBuffersTransferData[2] = (s16)expPoints;
    sBattleBuffersTransferData[3] = ((s16)expPoints & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitStatusIconUpdate(u8 bufferId, u32 status1, u32 status2)
{
    sBattleBuffersTransferData[0] = CONTROLLER_STATUSICONUPDATE;
    sBattleBuffersTransferData[1] = status1;
    sBattleBuffersTransferData[2] = (status1 & 0x0000FF00) >> 8;
    sBattleBuffersTransferData[3] = (status1 & 0x00FF0000) >> 16;
    sBattleBuffersTransferData[4] = (status1 & 0xFF000000) >> 24;
    sBattleBuffersTransferData[5] = status2;
    sBattleBuffersTransferData[6] = (status2 & 0x0000FF00) >> 8;
    sBattleBuffersTransferData[7] = (status2 & 0x00FF0000) >> 16;
    sBattleBuffersTransferData[8] = (status2 & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 9);
}

void EmitStatusAnimation(u8 bufferId, bool8 status2, u32 status)
{
    sBattleBuffersTransferData[0] = CONTROLLER_STATUSANIMATION;
    sBattleBuffersTransferData[1] = status2;
    sBattleBuffersTransferData[2] = status;
    sBattleBuffersTransferData[3] = (status & 0x0000FF00) >> 8;
    sBattleBuffersTransferData[4] = (status & 0x00FF0000) >> 16;
    sBattleBuffersTransferData[5] = (status & 0xFF000000) >> 24;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 6);
}

void EmitStatusXor(u8 bufferId, u8 b)
{
    sBattleBuffersTransferData[0] = CONTROLLER_STATUSXOR;
    sBattleBuffersTransferData[1] = b;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 2);
}

void EmitDataTransfer(u8 bufferId, u16 size, void *data)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_DATATRANSFER;
    sBattleBuffersTransferData[1] = CONTROLLER_DATATRANSFER;
    sBattleBuffersTransferData[2] = size;
    sBattleBuffersTransferData[3] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        sBattleBuffersTransferData[4 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, size + 4);
}

void EmitDMA3Transfer(u8 bufferId, void *dst, u16 size, void *data)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_DMA3TRANSFER;
    sBattleBuffersTransferData[1] = (u32)(dst);
    sBattleBuffersTransferData[2] = ((u32)(dst) & 0x0000FF00) >> 8;
    sBattleBuffersTransferData[3] = ((u32)(dst) & 0x00FF0000) >> 16;
    sBattleBuffersTransferData[4] = ((u32)(dst) & 0xFF000000) >> 24;
    sBattleBuffersTransferData[5] = size;
    sBattleBuffersTransferData[6] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        sBattleBuffersTransferData[7 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, size + 7);
}

void EmitPlayBGM(u8 bufferId, u16 songId, void *unusedDumbDataParameter)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_31;
    sBattleBuffersTransferData[1] = songId;
    sBattleBuffersTransferData[2] = (songId & 0xFF00) >> 8;
    for (i = 0; i < songId; i++) // ????
        sBattleBuffersTransferData[3 + i] = *(u8*)(unusedDumbDataParameter++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, songId + 3);
}

void EmitCmd32(u8 bufferId, u16 size, void *data)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_32;
    sBattleBuffersTransferData[1] = size;
    sBattleBuffersTransferData[2] = (size & 0xFF00) >> 8;
    for (i = 0; i < size; i++)
        sBattleBuffersTransferData[3 + i] = *(u8*)(data++);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, size + 3);
}

void EmitTwoReturnValues(u8 bufferId, u8 arg1, u16 arg2)
{
    sBattleBuffersTransferData[0] = CONTROLLER_TWORETURNVALUES;
    sBattleBuffersTransferData[1] = arg1;
    sBattleBuffersTransferData[2] = arg2;
    sBattleBuffersTransferData[3] = (arg2 & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitChosenMonReturnValue(u8 bufferId, u8 b, u8 *c)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_CHOSENMONRETURNVALUE;
    sBattleBuffersTransferData[1] = b;
    for (i = 0; i < 3; i++)
        sBattleBuffersTransferData[2 + i] = c[i];
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 5);
}

void EmitOneReturnValue(u8 bufferId, u16 arg1)
{
    sBattleBuffersTransferData[0] = CONTROLLER_ONERETURNVALUE;
    sBattleBuffersTransferData[1] = arg1;
    sBattleBuffersTransferData[2] = (arg1 & 0xFF00) >> 8;
    sBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitOneReturnValue_Duplicate(u8 bufferId, u16 b)
{
    sBattleBuffersTransferData[0] = CONTROLLER_ONERETURNVALUE_DUPLICATE;
    sBattleBuffersTransferData[1] = b;
    sBattleBuffersTransferData[2] = (b & 0xFF00) >> 8;
    sBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitCmd37(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_37;
    sBattleBuffersTransferData[1] = CONTROLLER_37;
    sBattleBuffersTransferData[2] = CONTROLLER_37;
    sBattleBuffersTransferData[3] = CONTROLLER_37;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitCmd38(u8 bufferId, u8 b)
{
    sBattleBuffersTransferData[0] = CONTROLLER_38;
    sBattleBuffersTransferData[1] = b;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 2);
}

void EmitCmd39(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_39;
    sBattleBuffersTransferData[1] = CONTROLLER_39;
    sBattleBuffersTransferData[2] = CONTROLLER_39;
    sBattleBuffersTransferData[3] = CONTROLLER_39;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitCmd40(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_40;
    sBattleBuffersTransferData[1] = CONTROLLER_40;
    sBattleBuffersTransferData[2] = CONTROLLER_40;
    sBattleBuffersTransferData[3] = CONTROLLER_40;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitHitAnimation(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_HITANIMATION;
    sBattleBuffersTransferData[1] = CONTROLLER_HITANIMATION;
    sBattleBuffersTransferData[2] = CONTROLLER_HITANIMATION;
    sBattleBuffersTransferData[3] = CONTROLLER_HITANIMATION;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitCmd42(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_42;
    sBattleBuffersTransferData[1] = CONTROLLER_42;
    sBattleBuffersTransferData[2] = CONTROLLER_42;
    sBattleBuffersTransferData[3] = CONTROLLER_42;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitPlaySE(u8 bufferId, u16 songId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_EFFECTIVENESSSOUND;
    sBattleBuffersTransferData[1] = songId;
    sBattleBuffersTransferData[2] = (songId & 0xFF00) >> 8;
    sBattleBuffersTransferData[3] = 0;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitPlayFanfareOrBGM(u8 bufferId, u16 songId, bool8 playBGM)
{
    sBattleBuffersTransferData[0] = CONTROLLER_PLAYFANFAREORBGM;
    sBattleBuffersTransferData[1] = songId;
    sBattleBuffersTransferData[2] = (songId & 0xFF00) >> 8;
    sBattleBuffersTransferData[3] = playBGM;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitFaintingCry(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_FAINTINGCRY;
    sBattleBuffersTransferData[1] = CONTROLLER_FAINTINGCRY;
    sBattleBuffersTransferData[2] = CONTROLLER_FAINTINGCRY;
    sBattleBuffersTransferData[3] = CONTROLLER_FAINTINGCRY;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitIntroSlide(u8 bufferId, u8 terrainId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_INTROSLIDE;
    sBattleBuffersTransferData[1] = terrainId;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 2);
}

void EmitIntroTrainerBallThrow(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_INTROTRAINERBALLTHROW;
    sBattleBuffersTransferData[1] = CONTROLLER_INTROTRAINERBALLTHROW;
    sBattleBuffersTransferData[2] = CONTROLLER_INTROTRAINERBALLTHROW;
    sBattleBuffersTransferData[3] = CONTROLLER_INTROTRAINERBALLTHROW;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitDrawPartyStatusSummary(u8 bufferId, struct HpAndStatus* hpAndStatus, u8 arg2)
{
    s32 i;

    sBattleBuffersTransferData[0] = CONTROLLER_DRAWPARTYSTATUSSUMMARY;
    sBattleBuffersTransferData[1] = arg2 & 0x7F;
    sBattleBuffersTransferData[2] = (arg2 & 0x80) >> 7;
    sBattleBuffersTransferData[3] = CONTROLLER_DRAWPARTYSTATUSSUMMARY;
    for (i = 0; i < (s32)(sizeof(struct HpAndStatus) * 6); i++)
        sBattleBuffersTransferData[4 + i] = *(i + (u8*)(hpAndStatus));
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, sizeof(struct HpAndStatus) * 6 + 4);
}

void EmitCmd49(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_49;
    sBattleBuffersTransferData[1] = CONTROLLER_49;
    sBattleBuffersTransferData[2] = CONTROLLER_49;
    sBattleBuffersTransferData[3] = CONTROLLER_49;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitCmd50(u8 bufferId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_50;
    sBattleBuffersTransferData[1] = CONTROLLER_50;
    sBattleBuffersTransferData[2] = CONTROLLER_50;
    sBattleBuffersTransferData[3] = CONTROLLER_50;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitSpriteInvisibility(u8 bufferId, bool8 isInvisible)
{
    sBattleBuffersTransferData[0] = CONTROLLER_SPRITEINVISIBILITY;
    sBattleBuffersTransferData[1] = isInvisible;
    sBattleBuffersTransferData[2] = CONTROLLER_SPRITEINVISIBILITY;
    sBattleBuffersTransferData[3] = CONTROLLER_SPRITEINVISIBILITY;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitBattleAnimation(u8 bufferId, u8 animationId, u16 argument)
{
    sBattleBuffersTransferData[0] = CONTROLLER_BATTLEANIMATION;
    sBattleBuffersTransferData[1] = animationId;
    sBattleBuffersTransferData[2] = argument;
    sBattleBuffersTransferData[3] = (argument & 0xFF00) >> 8;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 4);
}

void EmitLinkStandbyMsg(u8 bufferId, u8 arg1, bool32 arg2)
{
    bool8 arg2_ = arg2;
    sBattleBuffersTransferData[0] = CONTROLLER_LINKSTANDBYMSG;
    sBattleBuffersTransferData[1] = arg1;

    if (arg2_)
        sBattleBuffersTransferData[3] = sBattleBuffersTransferData[2] = sub_81850DC(&sBattleBuffersTransferData[4]);
    else
        sBattleBuffersTransferData[3] = sBattleBuffersTransferData[2] = 0;

    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, sBattleBuffersTransferData[2] + 4);
}

void EmitResetActionMoveSelection(u8 bufferId, u8 caseId)
{
    sBattleBuffersTransferData[0] = CONTROLLER_RESETACTIONMOVESELECTION;
    sBattleBuffersTransferData[1] = caseId;
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, 2);
}

void EmitCmd55(u8 bufferId, u8 arg1)
{
    sBattleBuffersTransferData[0] = CONTROLLER_55;
    sBattleBuffersTransferData[1] = arg1;
    sBattleBuffersTransferData[2] = gSaveBlock2Ptr->field_CA9_b;
    sBattleBuffersTransferData[3] = gSaveBlock2Ptr->field_CA9_b;
    sBattleBuffersTransferData[5] = sBattleBuffersTransferData[4] = sub_81850DC(&sBattleBuffersTransferData[6]);
    PrepareBufferDataTransfer(bufferId, sBattleBuffersTransferData, sBattleBuffersTransferData[4] + 6);
}
