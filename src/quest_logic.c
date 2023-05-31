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

u8 Quest_Rockcollector_CheckTakenStoneFlags(void){
    u16 stoneFlag = 0;
    u8 numTakenStones = 0;
    bool8 allStonesTaken = FALSE;

    for (stoneFlag = FLAG_ITEM_ROCKCOLLECTOR_STONE_START; stoneFlag < QUEST_ROCKCOLLECTOR_SUB_COUNT; stoneFlag++){
        if (FlagGet(stoneFlag)){
            numTakenStones++;
        }
    }

    if (numTakenStones == QUEST_ROCKCOLLECTOR_SUB_COUNT)
        allStonesTaken = TRUE;

    gSpecialVar_Result = allStonesTaken;
    return allStonesTaken;
}

bool8 Quest_Rockcollector_CheckBagAllStones(void){
    u8 i = 0;
    u8 countNumStonesInBag = 0;
    bool8 hasAllStones = FALSE;

    for (i = 0; i < QUEST_ROCKCOLLECTOR_SUB_COUNT; i++){
        if(CheckBagHasItem(FIRST_EVOLUTION_STONE_INDEX+i,1)){
            countNumStonesInBag++;
        }
    }

    if (countNumStonesInBag == QUEST_ROCKCOLLECTOR_SUB_COUNT){
        hasAllStones = TRUE;
    }

    gSpecialVar_Result = hasAllStones;
    return hasAllStones;
}

void Quest_Rockcollector_TakeAllStonesFromBag(void){
    u8 i = 0;

    if(Quest_Rockcollector_CheckBagAllStones()){
        for (i = 0; i < QUEST_ROCKCOLLECTOR_SUB_COUNT; i++){
            RemoveBagItem(FIRST_EVOLUTION_STONE_INDEX+1,1);
            QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR,FLAG_SET_COMPLETED,(SUB_QUEST_1 + i));
        }
    }
}


void Quest_Rockcollector_CheckSubquestTakeStone(void){
    u8 i = 0, j = 0, k = 0;
    u16 currentStone, currentQuest, currentFlag;

    for (i = 0; i < QUEST_ROCKCOLLECTOR_SUB_COUNT; i++){

        currentStone = FIRST_EVOLUTION_STONE_INDEX + i;
        currentQuest = i;
        currentFlag = FLAG_ITEM_ROCKCOLLECTOR_STONE_START + i;

        //if ((!QuestMenu_GetSetSubquestState(FLAG_GET_COMPLETED,QUEST_ROCKCOLLECTOR,currentQuest)) && (CheckBagHasItem(currentStone,1))){
        if (1 == 1){
            RemoveBagItem(currentStone,1);
            CopyItemName(currentStone, gStringVar1);
            StringCopy(gStringVar2,"this");
            QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR,FLAG_SET_COMPLETED,currentQuest);
            j++;

            if (!FlagGet(currentFlag)){
                k++;
            }
        }
        VarSet(VAR_TEMP_1,j);
        VarSet(VAR_TEMP_2,k);
    }
}

u16 Quest_Rockcollector_CountRemainingSubquests(void){
    u8 currentQuest;
    u16 numRemainingQuests = QUEST_ROCKCOLLECTOR_SUB_COUNT;

    for (currentQuest = 0; currentQuest < QUEST_ROCKCOLLECTOR_SUB_COUNT; currentQuest++){

        if (QuestMenu_GetSetSubquestState(QUEST_ROCKCOLLECTOR,FLAG_GET_COMPLETED,currentQuest)){
            numRemainingQuests--;
        }

    }
        gSpecialVar_Result = numRemainingQuests;
        ConvertIntToDecimalStringN(gStringVar1,numRemainingQuests,STR_CONV_MODE_LEFT_ALIGN,2);
        return numRemainingQuests;
}
