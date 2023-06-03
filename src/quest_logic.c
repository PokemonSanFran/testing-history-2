#include "global.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "fieldmap.h"
#include "item.h"
#include "malloc.h"
#include "mazegen.h"
#include "quests.h"
#include "../gflib/string_util.h"
#include "quest_logic.h"
#include "hidden_grotto.h"

#include "overworld.h"
#include "random.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "field_control_avatar.h"

void Quest_Kitchenvolunteering_GeneratePantryItem(void);
static void Quest_Kitchenvolunteering_CompleteSubQuest(void);
void Quest_Kitchenvolunteering_CheckProgressAndSetReward(void);
void Quest_Kitchenvolunteering_ChooseRandomPantryItem(void);
static void Quest_Kitchenvolunteering_RestoreChosenPantryItem(void);

// ***********************************************************************
// Quest: Kitchen Volunteering
// -----------------------------------------------------------------------
// This contains all the quest functions required for
// the quest Kitchen Volunteering.
// ***********************************************************************

void Quest_Kitchenvolunteering_CreatePantryMaze(void){
    SeedRng(gSaveBlock1Ptr->mazeLayoutSeed);
    GenerateMazeMap(5, 5, &gMazeTemplates[CAVE_STAIRS_TEMPLATE_SET]);
    Quest_Kitchenvolunteering_RestoreChosenPantryItem();
}

void Quest_Kitchenvolunteering_GeneratePantryItem(void){
    u16 i,j,k;

    i = VarGet(VAR_LAST_TALKED);
    j = (ITEM_GOLD_TEETH - 1 + i);

    gSpecialVar_0x8000 = j;
    gSpecialVar_0x8001 = 1;

    Quest_Kitchenvolunteering_CompleteSubQuest();
}

static void Quest_Kitchenvolunteering_CompleteSubQuest(void){
    u8 i = 0;

    i = VarGet(VAR_LAST_TALKED) - 1;
    QuestMenu_GetSetSubquestState(QUEST_KITCHENVOLUNTEERING,FLAG_SET_COMPLETED,(SUB_QUEST_1 + i));
}

void Quest_Kitchenvolunteering_CheckProgressAndSetReward(void){

    if (Quest_Kitchenvolunteering_CountRemainingItems() == 0){
        QuestMenu_GetSetQuestState(QUEST_KITCHENVOLUNTEERING,FLAG_REMOVE_ACTIVE);
        QuestMenu_GetSetQuestState(QUEST_KITCHENVOLUNTEERING,FLAG_SET_REWARD);
    }
}

u8 Quest_Kitchenvolunteering_CountRemainingItems(void){
    u8 i = 0,j = 0;

    for (i = 0; i <QUEST_KITCHENVOLUNTEERING_SUB_COUNT;i++){

        if (QuestMenu_GetSetSubquestState(QUEST_KITCHENVOLUNTEERING,FLAG_GET_COMPLETED,(SUB_QUEST_1 + i))){
            FlagSet(FLAG_TEMP_1 + i);
            j++;
        }
    }
    return (QUEST_KITCHENVOLUNTEERING_SUB_COUNT - j);
}

void Quest_Kitchenvolunteering_ChooseRandomPantryItem(void){
    u16 generatedItem = (Random() % (ITEM_TRI_PASS - ITEM_GOLD_TEETH + 1) + ITEM_GOLD_TEETH);
    CopyItemName(generatedItem, gStringVar1);
    VarSet(VAR_QUEST_KITCHEN_ASSIGNED_ITEMS,generatedItem);
}

static void Quest_Kitchenvolunteering_RestoreChosenPantryItem(void){
    u16 chosenItem = (VarGet(VAR_QUEST_KITCHEN_ASSIGNED_ITEMS));
    u16 itemOffset = chosenItem - ITEM_GOLD_TEETH;
    if (QuestMenu_GetSetQuestState(QUEST_KITCHENVOLUNTEERING,FLAG_GET_COMPLETED)){
        if (!CheckBagHasItem(chosenItem,1)){
            FlagClear(FLAG_TEMP_1 + itemOffset);
        }
    }
}

// ***********************************************************************
// Quest: Rock Collector
// -----------------------------------------------------------------------
// This contains all the quest functions required for
// the quest Rock Collector
// ***********************************************************************

bool8 Quest_Rockcollector_CheckTakenStoneFlags(void)
{
    u8 numTakenStones = 0;
    u16 i;

    for (i = 0; i < ROCKCOLLECTOR_STONES_COUNT; i++)
    {
        if (FlagGet(FLAG_ITEM_ROCKCOLLECTOR_STONE_START + i))
        {
            numTakenStones++;
        }
    }

    gSpecialVar_Result = (numTakenStones == QUEST_ROCKCOLLECTOR_SUB_COUNT);
    return gSpecialVar_Result;
}

bool8 Quest_Rockcollector_CheckBagAllStones(void)
{
    u8 countNumStonesInBag = 0;
    u8 i;

    for (i = 0; i < QUEST_ROCKCOLLECTOR_SUB_COUNT; i++)
    {
        if (CheckBagHasItem(FIRST_EVOLUTION_STONE_INDEX + i, 1))
        {
            countNumStonesInBag++;
        }
    }

    gSpecialVar_Result = (countNumStonesInBag == QUEST_ROCKCOLLECTOR_SUB_COUNT);
    return gSpecialVar_Result;
}

void Quest_Rockcollector_TakeAllStonesFromBag(void){
    u8 i = 0;

    if(Quest_Rockcollector_CheckBagAllStones()){
        for (i = 0; i < QUEST_ROCKCOLLECTOR_SUB_COUNT; i++){
            RemoveBagItem(FIRST_EVOLUTION_STONE_INDEX+i,1);
            QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR,FLAG_SET_COMPLETED,(SUB_QUEST_1 + i));
        }
    }
}

void Quest_Rockcollector_CheckSubquestTakeStone(void)
{
    u8 numExternalStones = 0;
    u8 numTakenStones = 0;
    u8 currentQuest = 0;
    u16 currentStone, currentFlag;

    for (currentQuest = 0; currentQuest < QUEST_ROCKCOLLECTOR_SUB_COUNT; currentQuest++)
    {
        currentStone = FIRST_EVOLUTION_STONE_INDEX + currentQuest;
        currentFlag = FLAG_ITEM_ROCKCOLLECTOR_STONE_START + currentQuest;

        if (!QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR, FLAG_GET_COMPLETED, currentQuest) && CheckBagHasItem(currentStone, 1))
        {
            RemoveBagItem(currentStone, 1);
            CopyItemName(currentStone, gStringVar1);
            QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR, FLAG_SET_COMPLETED, currentQuest);
            numTakenStones++;

            if (!FlagGet(currentFlag))
            {
                numExternalStones++;
            }
        }
    }

    VarSet(VAR_TEMP_1, numTakenStones);
    VarSet(VAR_TEMP_2, numExternalStones);
}

u16 Quest_Rockcollector_CountRemainingSubquests(void)
{
    u16 numRemainingQuests = QUEST_ROCKCOLLECTOR_SUB_COUNT;
    u8 currentQuest;

    for (currentQuest = 0; currentQuest < QUEST_ROCKCOLLECTOR_SUB_COUNT; currentQuest++)
    {
        if (QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR, FLAG_GET_COMPLETED, currentQuest))
        {
            numRemainingQuests--;
        }
    }

    gSpecialVar_Result = numRemainingQuests;
    ConvertIntToDecimalStringN(gStringVar1, numRemainingQuests, STR_CONV_MODE_LEFT_ALIGN, 2);
    return numRemainingQuests;
}

void Quest_Rockcollector_RespawnStones(void)
{
    u16 flags[ROCKCOLLECTOR_STONES_COUNT];
    u16 i;


    if(QuestMenu_GetSetQuestState(QUEST_ROCKCOLLECTOR,FLAG_GET_COMPLETED)){
        for (i = 0; i < ROCKCOLLECTOR_STONES_COUNT; i++)
        {
            flags[i] = FLAG_ITEM_ROCKCOLLECTOR_STONE_START + i;
            FlagClear(flags[i]);
        }
    }
}

// ***********************************************************************
// Quest: Hidden Grotto Mapping
// -----------------------------------------------------------------------
// This contains all the quest functions required for
// the quest Hidden Grotto Mapping.
// ***********************************************************************

const u32 GROTTO_SUBQUEST_MAP[NUM_GROTTO_ROUTES][2]=
{
    {MAP_PSFROUTE1,SUB_QUEST_3},
    {MAP_PSFROUTE30,SUB_QUEST_2},
    {MAP_PSFROUTE9,SUB_QUEST_3},
    {MAP_PSFROUTE70,SUB_QUEST_3},
    {MAP_PSFROUTE17_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE22,SUB_QUEST_2},
    {MAP_PSFROUTE49,SUB_QUEST_2},
    {MAP_PSFROUTE38,SUB_QUEST_2},
    {MAP_PSFROUTE14,SUB_QUEST_3},
    {MAP_PSFROUTE21_GROTTO,SUB_QUEST_3},
    {MAP_PSFROUTE19,SUB_QUEST_4},
    {MAP_PSFROUTE7,SUB_QUEST_1},
    {MAP_PSFROUTE63_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE12,SUB_QUEST_4},
    {MAP_PSFROUTE11_GROTTO,SUB_QUEST_5},
    {MAP_PSFROUTE32,SUB_QUEST_5},
    {MAP_PSFROUTE62,SUB_QUEST_2},
    {MAP_PSFROUTE72,SUB_QUEST_2},
    {MAP_PSFROUTE18,SUB_QUEST_3},
    {MAP_PSFROUTE61,SUB_QUEST_1},
    {MAP_PSFROUTE43,SUB_QUEST_1},
    {MAP_PSFROUTE5,SUB_QUEST_1},
    {MAP_PSFROUTE15,SUB_QUEST_2},
    {MAP_PSFROUTE25,SUB_QUEST_2},
    {MAP_PSFROUTE8_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE13_GROTTO,SUB_QUEST_4},
};

void Quest_Hiddengrottomapping_MarkSubquestBiome(void) {
    u32 currentMapGroup = gSaveBlock1Ptr->location.mapGroup;
    u32 currentMapNum = gSaveBlock1Ptr->location.mapNum;
    u32 mapId = (currentMapNum | (currentMapGroup << 8));
    u32 subquest = 0;
    u8 i;

    for (i = 0; i < NUM_GROTTO_ROUTES; i++) {
        if (GROTTO_SUBQUEST_MAP[i][0] == mapId) {
            subquest = GROTTO_SUBQUEST_MAP[i][1];
            break;
        }
    }

    if (subquest) {
        if (!QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING, FLAG_GET_COMPLETED, subquest)) {
            QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING, FLAG_SET_COMPLETED, subquest);
        }
    }

}

bool8 Quest_Hiddengrottomapping_CheckSubquestsForReward(void){
    u8 i;
    bool8 allSubquestsComplete = TRUE;

    for (i = 0; i < QUEST_HIDDENGROTTOMAPPING_SUB_COUNT; i++){
        if (!QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING,FLAG_GET_COMPLETED,i)){
            allSubquestsComplete = FALSE;
            break;
        }
    }
    return (allSubquestsComplete);
}

// ***********************************************************************
// Quest: Hidden Grotto Mapping 2
// -----------------------------------------------------------------------
// This contains all the quest functions required for
// the quest Hidden Grotto Mapping 2.
// ***********************************************************************

void Quest_Hiddengrottomapping_RemoveJournalPage(void){
    u32 currentMapGroup = gSaveBlock1Ptr->location.mapGroup;
    u32 currentMapNum = gSaveBlock1Ptr->location.mapNum;
    u32 mapId = (currentMapNum | (currentMapGroup << 8));
    u32 subquest = 0;
    u8 i;

    for (i = 0; i < NUM_GROTTO_ROUTES; i++) {
        if (GROTTO_SUBQUEST_MAP[i][0] == mapId) {
            if (QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING2,FLAG_GET_COMPLETED,i)){
                FlagSet(FLAG_TEMP_3);
            }
        }
    }
