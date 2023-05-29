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
