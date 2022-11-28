#ifndef GUARD_QUESTS_H
#define GUARD_QUESTS_H

#include "constants/quests.h"

#define SORT_DEFAULT 0
#define SORT_INACTIVE 1
#define SORT_ACTIVE 2
#define SORT_REWARD 3
#define SORT_DONE 4

#define SORT_DEFAULT_AZ 10
#define SORT_INACTIVE_AZ 11
#define SORT_ACTIVE_AZ 12
#define SORT_REWARD_AZ 13
#define SORT_DONE_AZ 14

#define SORT_SUBQUEST 100

#define INCREMENT 1
#define ALPHA 2 
#define SUB 3

#define OBJECT 1
#define ITEM 2
#define PKMN 3

struct SubQuest
{
    const u8 id;
	const u8 *name;
	const u8 *desc;
	const u8 *map;
	const u16 sprite;
    const u8 spritetype;
    const u8 *type;
}; 

struct SideQuest
{
	const u8 *name;
	const u8 *desc;
	const u8 *donedesc;
	const u8 *map;
	const u16 sprite;
    const u8 spritetype;
	const struct SubQuest *subquests;
	const u8 numSubquests;
}; 

extern const struct SubQuest gHauntABuilding_Sub[QUEST_HAUNTABUILDING_SUB_COUNT];
extern const struct SubQuest gRightingWrongs_Sub[QUEST_RIGHTINGWRONGS_SUB_COUNT];
extern const struct SubQuest gBreakTheInternet_Sub[QUEST_BREAKTHEINTERNET_SUB_COUNT];
extern const struct SubQuest gImprovBattling_Sub[QUEST_IMPROVBATTLING_SUB_COUNT];
extern const struct SubQuest gInstallNatureProbes_Sub[QUEST_INSTALLNATUREPROBES_SUB_COUNT];
extern const struct SubQuest gRestaurantExpansion1_Sub[QUEST_RESTAURANTEXPANSION1_SUB_COUNT];
extern const struct SubQuest gRestaurantExpansion2_Sub[QUEST_RESTAURANTEXPANSION2_SUB_COUNT];
extern const struct SubQuest gHybridCulture_Sub[QUEST_HYBRIDCULTURE_SUB_COUNT];
extern const struct SubQuest gBuildingAnExhibit_Sub[QUEST_BUILDINGANEXHIBIT_SUB_COUNT];
extern const struct SubQuest gBiomeResearch_Sub[QUEST_BIOMERESEARCH_SUB_COUNT];
extern const struct SubQuest gBerrySustainability_Sub[QUEST_BERRYSUSTAINABILITY_SUB_COUNT];
extern const struct SubQuest gContractorPorygon_Sub[QUEST_CONTRACTORPORYGON_SUB_COUNT];
extern const struct SubQuest gGetTheBandBackTogether_Sub[QUEST_GETTHEBANDBACKTOGETHER_SUB_COUNT];
extern const struct SubQuest gFoodTruckBureacracy_Sub[QUEST_FOODTRUCKBUREACRACY_SUB_COUNT];
extern const struct SubQuest gDetectiveAriana_Sub[QUEST_DETECTIVEARIANA_SUB_COUNT];
extern const struct SubQuest gChallengeOfThe7Sisters_Sub[QUEST_CHALLENGEOFTHE7SISTERS_SUB_COUNT];
extern const struct SubQuest gCutePokemon_Sub[QUEST_CUTEPOKEMON_SUB_COUNT];
extern const struct SubQuest gDexCompletion_Sub[QUEST_DEXCOMPLETION_SUB_COUNT];
extern const struct SubQuest gKitchenVolunteering_Sub[QUEST_KITCHENVOLUNTEERING_SUB_COUNT];
extern const struct SubQuest gArtisanBalls_Sub[QUEST_ARTISANBALLS_SUB_COUNT];
extern const struct SubQuest gArtisanBalls2_Sub[QUEST_ARTISANBALLS2_SUB_COUNT];
extern const struct SubQuest gShelterSwitcheroo_Sub[QUEST_SHELTERSWITCHEROO_SUB_COUNT];
extern const struct SubQuest gShelterTaxiSolution_Sub[QUEST_SHELTERTAXISOLUTION_SUB_COUNT];
extern const struct SubQuest gNeighborhoodCleanUp_Sub[QUEST_NEIGHBORHOODCLEANUP_SUB_COUNT];
extern const struct SubQuest gNeighborhoodCleanUp2_Sub[QUEST_NEIGHBORHOODCLEANUP2_SUB_COUNT];
extern const struct SubQuest gNeighborhoodCleanUp3_Sub[QUEST_NEIGHBORHOODCLEANUP3_SUB_COUNT];
extern const struct SubQuest gRockCollector_Sub[QUEST_ROCKCOLLECTOR_SUB_COUNT];
extern const struct SubQuest gHiddenGrottoMapping_Sub[QUEST_HIDDENGROTTOMAPPING_SUB_COUNT];
extern const struct SubQuest gHiddenGrottoMapping2_Sub[QUEST_HIDDENGROTTOMAPPING2_SUB_COUNT];
extern const struct SubQuest gUltraWormholeResearch_Sub[QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT];
extern const struct SubQuest gWildfireRisk_Sub[QUEST_WILDFIRERISK_SUB_COUNT];
extern const struct SubQuest gTheBoyWhoCriesWithWolves_Sub[QUEST_THEBOYWHOCRIESWITHWOLVES_SUB_COUNT];
extern const struct SubQuest gTaxicabTurnAroundSea_Sub[QUEST_TAXICABTURNAROUNDSEA_SUB_COUNT];
extern const struct SubQuest gTaxicabTurnAroundAir_Sub[QUEST_TAXICABTURNAROUNDAIR_SUB_COUNT];
extern const struct SubQuest gTaxicabTurnAroundLand_Sub[QUEST_TAXICABTURNAROUNDLAND_SUB_COUNT];
extern const struct SubQuest gPersuasivePassenger_Sub[QUEST_PERSUASIVEPASSENGER_SUB_COUNT];
extern const struct SubQuest gBodegaBurnout_Sub[QUEST_BODEGABURNOUT_SUB_COUNT];
extern const struct SubQuest gWarehouseWarfare_Sub[QUEST_WAREHOUSEWARFARE_SUB_COUNT];
extern const struct SubQuest gRestoreToTheirFormerGlory_Sub[QUEST_RESTORETOTHEIRFORMERGLORY_SUB_COUNT];
extern const struct SideQuest gSideQuests[QUEST_COUNT];

enum QuestCases
{
	FLAG_GET_UNLOCKED,      // check if quest is unlocked
	FLAG_GET_INACTIVE, //check if quest is unlocked but has no other state
	FLAG_GET_ACTIVE,        // check if quest is active
	FLAG_GET_REWARD,     // check if quest is ready for reward
	FLAG_GET_COMPLETED,     // check if quest is completed
	FLAG_GET_FAVORITE,     // check if quest is favorited
	FLAG_SET_UNLOCKED,      // mark quest as unlocked
	FLAG_SET_INACTIVE, //mark quest as inactive
	FLAG_SET_ACTIVE,        // mark quest as active
	FLAG_SET_REWARD,     // mark quest ready for reward
	FLAG_SET_COMPLETED,     // mark completed quest
	FLAG_SET_FAVORITE,     // mark quest as a favorite
	FLAG_REMOVE_INACTIVE, //remove inactive flag from quest
	FLAG_REMOVE_ACTIVE, //remove active flag from quest
	FLAG_REMOVE_REWARD, //remove reward flag from quest
	FLAG_REMOVE_FAVORITE, //remove favorite flag from quest
};

// functions
void QuestMenu_Init(u8 a0, MainCallback callback);
u8 QuestMenu_GetSetSubquestState(u8 quest, u8 caseId, u8 childQuest);
u8 QuestMenu_GetSetQuestState(u8 quest, u8 caseId);
void Task_QuestMenu_OpenFromStartMenu(u8);
void QuestMenu_CopyQuestName(u8 *dst, u8 questId);
void QuestMenu_CopySubquestName(u8 *dst, u8 parentId, u8 childId);
void QuestMenu_ResetMenuSaveData(void);
u8 getFirstFavoriteQuest();
void GenerateQuestFlavorText(s32 questId);

#endif // GUARD_QUESTS_H
