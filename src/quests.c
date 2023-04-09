//PSF TODO when the player first opens this, there should be a tutorial to play to explain features and functionality
//PSF TODO If a player recives a 2nd quest via startquest and the player has still never opened the questlog and done the tutorial, force the tutorial
#include "global.h"
#include "strings.h"
#include "quest_strings.h"
#include "bg.h"
#include "data.h"
#include "decompress.h"
#include "gpu_regs.h"
#include "graphics.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "list_menu.h"
#include "item_use.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "palette.h"
#include "party_menu.h"
#include "scanline_effect.h"
#include "sound.h"
#include "string_util.h"
#include "task.h"
#include "text_window.h"
#include "quests.h"
#include "overworld.h"
#include "event_data.h"
#include "constants/items.h"
#include "constants/field_weather.h"
#include "constants/songs.h"
#include "constants/rgb.h"
#include "constants/event_objects.h"
#include "event_object_movement.h"
#include "pokemon_icon.h"
#include "quest_flavor_lookup.h"

#include "random.h"

#define tPageItems      data[4]
#define tItemPcParam    data[6]

struct QuestMenuResources {
	MainCallback savedCallback;
	u8 moveModeOrigPos;
	u8 spriteIconSlot;
	u16 oldPaletteTag;
	u8 maxShowed;
	u8 nItems;
	u8 scrollIndicatorArrowPairId;
	s16 data[3];
	u8 filterMode;
	u8 parentQuest;
	bool8 restoreCursor;
	bool8 initialLoad;
};

struct QuestMenuStaticResources {
	MainCallback savedCallback;
	u16 scroll;
	u16 row;
	u8 initialized;
	u16 storedScrollOffset;
	u16 storedRowPosition;
};

// RAM
EWRAM_DATA static struct QuestMenuResources *sStateDataPtr = NULL;
EWRAM_DATA static u8 *sBg1TilemapBuffer = NULL;
EWRAM_DATA static struct ListMenuItem *sListMenuItems = NULL;
EWRAM_DATA static struct QuestMenuStaticResources sListMenuState = {0};
EWRAM_DATA static u8 sItemMenuIconSpriteIds[12] = {0};        // from pokefirered src/item_menu_icons.c
EWRAM_DATA static void *questNamePointer = NULL;
EWRAM_DATA static u8 **questNameArray = NULL;

// This File's Functions
void QuestMenu_Init(u8 a0, MainCallback callback);
static void MainCB(void);
static void VBlankCB(void);
static void RunSetup(void);

static bool8 SetupGraphics(void);
static bool8 LoadGraphics(void);
static void QuestMenu_InitWindows(void);
static bool8 InitBackgrounds(void);
static void InitItems(void);
static bool8 AllocateResourcesForListMenu(void);
static void AllocateMemoryForArray();
static void PlaceTopMenuScrollIndicatorArrows(void);
static void SetInitializedFlag(u8 a0);

static u8 GetCursorPosition(void);
static void SetCursorPosition(void);
static void SetScrollPosition(void);
static bool8 IfScrollIsOutOfBounds(void);
static bool8 IfRowIsOutOfBounds(void);
static void SaveScrollAndRow(s16 *data);

static void ClearModeOnStartup(void);
static void WriteModeToSaveBlock(u8 mode);
static u8 ManageMode(u8 action);
static u8 ToggleAlphaMode(u8 mode);
static u8 ToggleSubsavedQuestMode(u8 mode);
static u8 IncrementMode(u8 mode);
static bool8 IsSubsavedQuestMode(void);
static bool8 IsNotFilteredMode(void);
static bool8 IsAlphaMode(void);
static void SetInitalLoadTrue(void);
static void SetInitalLoadFalse(void);
static bool8 IsInitalLoad(void);
static void GetSavedQuestMode(void);
static void LoadSavedQuestMode(u8 taskId);

static u16 BuildMenuTemplate(void);
static u8 GetModeAndGenerateList();
static u8 CountNumberListRows();
static u8 *DefineQuestOrder();
static u8 GenerateSubquestList();
static u8 GenerateList(bool8 isFiltered);
static void AssignCancelNameAndId(u8 numRow);

static u8 CountUnlockedQuests(void);
static u8 CountInactiveQuests(void);
static u8 CountActiveQuests(void);
static u8 CountRewardQuests(void);
static u8 CountCompletedQuests(void);
static u8 CountFavoriteQuests(void);

static void PopulateEmptyRow(u8 countQuest);
static void PrependQuestNumber(u8 countQuest);
static void SetFavoriteQuest(u8 countQuest);
static void PopulateQuestName(u8 countQuest);
static void PopulateSubquestName(u8 parentQuest, u8 countQuest);
static u8 PopulateListRowNameAndId(u8 row, u8 countQuest);
static bool8 DoesQuestHaveChildrenAndNotInactive(u16 itemId);
static void AddSubQuestButton(u8 countQuest);

static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId,
                const u8 *str, u8 x, u8 y, u8 letterSpacing, u8 lineSpacing, u8 speed,
                u8 colorIdx);

static void MoveCursorFunc(s32 itemIndex, bool8 onInit,
                           struct ListMenu *list);
static void PlayCursorSound(bool8 firstRun);
static void PrintDetailsForCancel();
static void GenerateAndPrintQuestDetails(s32 questId);
static void GenerateQuestLocation(s32 questId);
static void PrintQuestLocation(s32 questId);
static void UpdateQuestDesc(s32 questId);
static void UpdateQuestDoneDesc(s32 questId);
static const u8 *GetQuestDesc(s32 questId);
static const u8 *GetQuestDoneDesc(s32 questId);
static void PrintQuestFlavorText(s32 questId);

static bool8 IsQuestUnlocked(s32 questId);
static bool8 IsQuestActiveState(s32 questId);
static bool8 IsQuestInactiveState(s32 questId);
static bool8 IsQuestRewardState(s32 questId);
static bool8 IsQuestCompletedState(s32 questId);
static bool8 IsSubquestCompletedState(s32 questId);

static void DetermineSpriteType(s32 questId);
static void QuestMenu_CreateSprite(u16 itemId, u8 idx, u8 spriteType);
static void ResetSpriteState(void);
static void QuestMenu_DestroySprite(u8 idx);

static void GenerateStateAndPrint(u8 windowId, u32 itemId, u8 y);
static u8 GenerateSubquestState(u8 questId);
static u8 GenerateQuestState(u8 questId);
static void PrintQuestState(u8 windowId, u8 y, u8 colorIndex);

static void GenerateAndPrintHeader(void);
static void GenerateDenominatorNumQuests(void);
static void GenerateNumeratorNumQuests(void);
static void GenerateMenuContext(void);
static void PrintNumQuests(void);
static void PrintMenuContext(void);
static void PrintTypeFilterButton(void);

static void Task_Main(u8 taskId);
static u8 ManageFavorites(u8 index);
static u8 CheckFavoriteAndRemove(u8 quest);
static void Task_QuestMenuCleanUp(u8 taskId);
static void RestoreSavedScrollAndRow(s16 *data);
static void ResetCursorToTop(s16 *data);
static void QuestMenu_RemoveScrollIndicatorArrowPair(void);
static void EnterSubsavedQuestModeAndCleanUp(u8 taskId, s16 *data, s32 input);
static void ChangeModeAndCleanUp(u8 taskId);
static void ToggleAlphaModeAndCleanUp(u8 taskId);
static void ToggleFavoriteAndCleanUp(u8 taskId, u8 selectedQuestId);
static bool8 CheckSelectedIsCancel(u8 selectedQuestId);
static void ReturnFromSubquestAndCleanUp(u8 taskId);

static void SetGpuRegBaseForFade(void);
static void InitFadeVariables(u8 taskId, u8 blendWeight, u8 frameDelay,
                              u8 frameTimerBase, u8 delta);
static void PrepareFadeOut(u8 taskId);
static bool8 HandleFadeOut(u8 taskId);
static void PrepareFadeIn(u8 taskId);
static bool8 HandleFadeIn(u8 taskId);
static void Task_FadeOut(u8 taskId);
static void Task_FadeIn(u8 taskId);

static void Task_QuestMenuWaitFadeAndBail(u8 taskId);
static void FadeAndBail(void);
static void FreeResources(void);
static void TurnOffQuestMenu(u8 taskId);
static void Task_QuestMenuTurnOff1(u8 taskId);
static void Task_QuestMenuTurnOff2(u8 taskId);

// Tiles, palettes and tilemaps for the Quest Menu
static const u32 sQuestMenuTiles[] =
        INCBIN_U32("graphics/quest_menu/menu.4bpp.lz");
static const u32 sQuestMenuBgPals[] =
        INCBIN_U32("graphics/quest_menu/menu_pal.gbapal.lz");
static const u32 sQuestMenuTilemap[] =
        INCBIN_U32("graphics/quest_menu/tilemap.bin.lz");

//Strings used for the Quest Menu
static const u8 sText_Empty[] = _("");
static const u8 sText_AllHeader[] = _("All Missions");
static const u8 sText_InactiveHeader[] = _("Inactive Missions");
static const u8 sText_ActiveHeader[] = _("Active Missions");
static const u8 sText_RewardHeader[] = _("Reward Available");
static const u8 sText_CompletedHeader[] =
        _("Completed Missions");
static const u8 sText_QuestNumberDisplay[] =
        _("{STR_VAR_1}/{STR_VAR_2}");
static const u8 sText_Unk[] = _("??????");
static const u8 sText_Active[] = _("Active");
static const u8 sText_Reward[] = _("Reward");
static const u8 sText_Complete[] = _("Done");
static const u8 sText_ShowLocation[] =
        _("Location: {STR_VAR_2}");
static const u8 sText_StartForMore[] =
        _("Start for more details.");
static const u8 sText_ReturnRecieveReward[] =
        _("Return to {STR_VAR_2}\nto recieve your reward!");
static const u8 sText_SubQuestButton[] = _(" {A_BUTTON}");
static const u8 sText_Type[] = _("{R_BUTTON}Type");
static const u8 sText_Caught[] = _("Caught");
static const u8 sText_Found[] = _("Found");
static const u8 sText_Read[] = _("Read");
static const u8 sText_Gave[] = _("Gave");
static const u8 sText_Met[] = _("Met");
static const u8 sText_Arrested[] = _("Arrested");
static const u8 sText_Debunked[] = _("Debunked");
static const u8 sText_Discovered[] = _("Discovered");
static const u8 sText_Delievered[] = _("Delievered");
static const u8 sText_Followed[] = _("Followed");
static const u8 sText_Listened[] = _("Listened");
static const u8 sText_Defeated[] = _("Defeated");
static const u8 sText_Completed[] = _("Completed");
static const u8 sText_PutIn[] = _("Put In");
static const u8 sText_Distributed[] = _("Distributed");
static const u8 sText_Recruited[] = _("Recruited");
static const u8 sText_Informed[] = _("Informed");
static const u8 sText_Investigated[] = _("Investigated");
static const u8 sText_Tested[] = _("Tested");
static const u8 sText_Helped[] = _("Helped");
static const u8 sText_Restored[] = _("Restored");
static const u8 sText_Back[] = _("Back");
static const u8 sText_DotSpace[] = _(". ");
static const u8 sText_Close[] = _("Close");
static const u8 sText_ColorGreen[] = _("{COLOR}{GREEN}");
static const u8 sText_AZ[] = _(" A-Z");

///////////////////////////////////////////////////////////////////////////////
//////////////////////BEGIN SUBQUEST CUSTOMIZATION/////////////////////////////

//Declaration of subquest structures. Edits to subquests are made here.
#define sub_quest(i, n, d, m, s, st, t) {.id = i, .name = n, .desc = d, .map = m, .sprite = s, .spritetype = st, .type = t}
static const struct SubQuest
	sHauntABuilding_Sub[QUEST_HAUNTABUILDING_SUB_COUNT] = {
	sub_quest(
	        0,
	        gText_Quest_HauntABuilding_Sub1_Name,
	        gText_Quest_HauntABuilding_Sub1_Desc,
	        gText_Quest_HauntABuilding_Sub1_Map,
	        SPECIES_LITWICK,
	        PKMN,
	        sText_Found
	),
	sub_quest(
	        1,
	        gText_Quest_HauntABuilding_Sub2_Name,
	        gText_Quest_HauntABuilding_Sub2_Desc,
	        gText_Quest_HauntABuilding_Sub2_Map,
	        SPECIES_LITWICK,
	        PKMN,
	        sText_Found
	),
	sub_quest(
	        2,
	        gText_Quest_HauntABuilding_Sub3_Name,
	        gText_Quest_HauntABuilding_Sub3_Desc,
	        gText_Quest_HauntABuilding_Sub3_Map,
	        SPECIES_SINISTEA,
	        PKMN,
	        sText_Found
	),
	sub_quest(
	        3,
	        gText_Quest_HauntABuilding_Sub4_Name,
	        gText_Quest_HauntABuilding_Sub4_Desc,
	        gText_Quest_HauntABuilding_Sub4_Map,
	        SPECIES_SINISTEA,
	        PKMN,
	        sText_Found
	),
	sub_quest(
	        4,
	        gText_Quest_HauntABuilding_Sub5_Name,
	        gText_Quest_HauntABuilding_Sub5_Desc,
	        gText_Quest_HauntABuilding_Sub5_Map,
	        SPECIES_CHANDELURE,
	        PKMN,
	        sText_Found
	),
	sub_quest(
	        5,
	        gText_Quest_HauntABuilding_Sub6_Name,
	        gText_Quest_HauntABuilding_Sub6_Desc,
	        gText_Quest_HauntABuilding_Sub6_Map,
	        SPECIES_TREVENANT,
	        PKMN,
	        sText_Found
	),
};

static const struct SubQuest sRightingWrongs_Sub[QUEST_RIGHTINGWRONGS_SUB_COUNT] = {
	sub_quest(
	        20,
	        gText_Quest_RightingWrongs_Sub1_Name,
	        gText_Quest_RightingWrongs_Sub1_Desc,
	        gText_Quest_RightingWrongs_Sub1_Map,
	        OBJ_EVENT_GFX_WOMAN_5,
	        OBJECT,
	        sText_Followed
	),
	sub_quest(
	        21,
	        gText_Quest_RightingWrongs_Sub2_Name,
	        gText_Quest_RightingWrongs_Sub2_Desc,
	        gText_Quest_RightingWrongs_Sub2_Map,
	        OBJ_EVENT_GFX_RICH_BOY,
	        OBJECT,
	        sText_Listened
	),
	sub_quest(
	        22,
	        gText_Quest_RightingWrongs_Sub3_Name,
	        gText_Quest_RightingWrongs_Sub3_Desc,
	        gText_Quest_RightingWrongs_Sub3_Map,
	        OBJ_EVENT_GFX_EXPERT_F,
	        OBJECT,
	        sText_Read
	),
	sub_quest(
	        23,
	        gText_Quest_RightingWrongs_Sub4_Name,
	        gText_Quest_RightingWrongs_Sub4_Desc,
	        gText_Quest_RightingWrongs_Sub4_Map,
	        OBJ_EVENT_GFX_WOMAN_5,
	        OBJECT,
	        sText_Arrested
	),
};

static const struct SubQuest sBreakTheInternet_Sub[QUEST_BREAKTHEINTERNET_SUB_COUNT] = {
	sub_quest(
	        24,
	        gText_Quest_BreakTheInternet_Sub1_Name,
	        gText_Quest_BreakTheInternet_Sub1_Desc,
	        gText_Quest_BreakTheInternet_Sub1_Map,
	        OBJ_EVENT_GFX_REPORTER_F,
	        OBJECT,
	        sText_Debunked
	),
	sub_quest(
	        25,
	        gText_Quest_BreakTheInternet_Sub2_Name,
	        gText_Quest_BreakTheInternet_Sub2_Desc,
	        gText_Quest_BreakTheInternet_Sub2_Map,
	        OBJ_EVENT_GFX_REPORTER_M,
	        OBJECT,
	        sText_Debunked
	),
	sub_quest(
	        26,
	        gText_Quest_BreakTheInternet_Sub3_Name,
	        gText_Quest_BreakTheInternet_Sub3_Desc,
	        gText_Quest_BreakTheInternet_Sub3_Map,
	        SPECIES_SLURPUFF,
	        PKMN,
	        sText_Defeated
	),
};

static const struct SubQuest sImprovBattling_Sub[QUEST_IMPROVBATTLING_SUB_COUNT] = {
	sub_quest(
	        27,
	        gText_Quest_ImprovBattling_Sub1_Name,
	        gText_Quest_ImprovBattling_Sub1_Desc,
	        gText_Quest_ImprovBattling_Sub1_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Completed
	),
	sub_quest(
	        28,
	        gText_Quest_ImprovBattling_Sub2_Name,
	        gText_Quest_ImprovBattling_Sub2_Desc,
	        gText_Quest_ImprovBattling_Sub2_Map,
	        ITEM_GREAT_BALL,
	        ITEM,
	        sText_Completed
	),
	sub_quest(
	        29,
	        gText_Quest_ImprovBattling_Sub3_Name,
	        gText_Quest_ImprovBattling_Sub3_Desc,
	        gText_Quest_ImprovBattling_Sub3_Map,
	        ITEM_ULTRA_BALL,
	        ITEM,
	        sText_Completed
	),
	sub_quest(
	        30,
	        gText_Quest_ImprovBattling_Sub4_Name,
	        gText_Quest_ImprovBattling_Sub4_Desc,
	        gText_Quest_ImprovBattling_Sub4_Map,
	        ITEM_MASTER_BALL,
	        ITEM,
	        sText_Completed
	),
};

static const struct SubQuest sInstallNatureProbes_Sub[QUEST_INSTALLNATUREPROBES_SUB_COUNT] = {
	sub_quest(
	        31,
	        gText_Quest_InstallNatureProbes_Sub1_Name,
	        gText_Quest_InstallNatureProbes_Sub1_Desc,
	        gText_Quest_InstallNatureProbes_Sub1_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        sText_PutIn
	),
	sub_quest(
	        32,
	        gText_Quest_InstallNatureProbes_Sub2_Name,
	        gText_Quest_InstallNatureProbes_Sub2_Desc,
	        gText_Quest_InstallNatureProbes_Sub2_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        sText_PutIn
	),
	sub_quest(
	        33,
	        gText_Quest_InstallNatureProbes_Sub3_Name,
	        gText_Quest_InstallNatureProbes_Sub3_Desc,
	        gText_Quest_InstallNatureProbes_Sub3_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        sText_PutIn
	),
};

static const struct SubQuest sRestaurantExpansion1_Sub[QUEST_RESTAURANTEXPANSION1_SUB_COUNT] = {
	sub_quest(
	        34,
	        gText_Quest_RestaurantExpansion1_Sub1_Name,
	        gText_Quest_RestaurantExpansion1_Sub1_Desc,
	        gText_Quest_RestaurantExpansion1_Sub1_Map,
	        OBJ_EVENT_GFX_NURSE,
	        OBJECT,
	        sText_Distributed
	),
	sub_quest(
	        35,
	        gText_Quest_RestaurantExpansion1_Sub2_Name,
	        gText_Quest_RestaurantExpansion1_Sub2_Desc,
	        gText_Quest_RestaurantExpansion1_Sub2_Map,
	        OBJ_EVENT_GFX_NURSE,
	        OBJECT,
	        sText_Distributed
	),
	sub_quest(
	        36,
	        gText_Quest_RestaurantExpansion1_Sub3_Name,
	        gText_Quest_RestaurantExpansion1_Sub3_Desc,
	        gText_Quest_RestaurantExpansion1_Sub3_Map,
	        OBJ_EVENT_GFX_NURSE,
	        OBJECT,
	        sText_Distributed
	),
	sub_quest(
	        37,
	        gText_Quest_RestaurantExpansion1_Sub4_Name,
	        gText_Quest_RestaurantExpansion1_Sub4_Desc,
	        gText_Quest_RestaurantExpansion1_Sub4_Map,
	        OBJ_EVENT_GFX_NURSE,
	        OBJECT,
	        sText_Distributed
	),
};

static const struct SubQuest sRestaurantExpansion2_Sub[QUEST_RESTAURANTEXPANSION2_SUB_COUNT] = {
	sub_quest(
	        38,
	        gText_Quest_RestaurantExpansion2_Sub1_Name,
	        gText_Quest_RestaurantExpansion2_Sub1_Desc,
	        gText_Quest_RestaurantExpansion2_Sub1_Map,
	        OBJ_EVENT_GFX_LINK_RECEPTIONIST,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        39,
	        gText_Quest_RestaurantExpansion2_Sub2_Name,
	        gText_Quest_RestaurantExpansion2_Sub2_Desc,
	        gText_Quest_RestaurantExpansion2_Sub2_Map,
	        OBJ_EVENT_GFX_MAN_4,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        40,
	        gText_Quest_RestaurantExpansion2_Sub3_Name,
	        gText_Quest_RestaurantExpansion2_Sub3_Desc,
	        gText_Quest_RestaurantExpansion2_Sub3_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        41,
	        gText_Quest_RestaurantExpansion2_Sub4_Name,
	        gText_Quest_RestaurantExpansion2_Sub4_Desc,
	        gText_Quest_RestaurantExpansion2_Sub4_Map,
	        OBJ_EVENT_GFX_TEALA,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        42,
	        gText_Quest_RestaurantExpansion2_Sub5_Name,
	        gText_Quest_RestaurantExpansion2_Sub5_Desc,
	        gText_Quest_RestaurantExpansion2_Sub5_Map,
	        OBJ_EVENT_GFX_ROOFTOP_SALE_WOMAN,
	        OBJECT,
	        sText_Recruited
	),
};

static const struct SubQuest sHybridCulture_Sub[QUEST_HYBRIDCULTURE_SUB_COUNT] = {
	sub_quest(
	        43,
	        gText_Quest_HybridCulture_Sub1_Name,
	        gText_Quest_HybridCulture_Sub1_Desc,
	        gText_Quest_HybridCulture_Sub1_Map,
	        OBJ_EVENT_GFX_GENTLEMAN,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        44,
	        gText_Quest_HybridCulture_Sub2_Name,
	        gText_Quest_HybridCulture_Sub2_Desc,
	        gText_Quest_HybridCulture_Sub2_Map,
	        OBJ_EVENT_GFX_WOMAN_5,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        45,
	        gText_Quest_HybridCulture_Sub3_Name,
	        gText_Quest_HybridCulture_Sub3_Desc,
	        gText_Quest_HybridCulture_Sub3_Map,
	        OBJ_EVENT_GFX_MAN_2,
	        OBJECT,
	        sText_Discovered
	),
};

static const struct SubQuest sBuildingAnExhibit_Sub[QUEST_BUILDINGANEXHIBIT_SUB_COUNT] = {
	sub_quest(
	        46,
	        gText_Quest_BuildingAnExhibit_Sub1_Name,
	        gText_Quest_BuildingAnExhibit_Sub1_Desc,
	        gText_Quest_BuildingAnExhibit_Sub1_Map,
	        OBJ_EVENT_GFX_YOUNGSTER,
	        OBJECT,
	        sText_Found
	),
	sub_quest(
	        47,
	        gText_Quest_BuildingAnExhibit_Sub2_Name,
	        gText_Quest_BuildingAnExhibit_Sub2_Desc,
	        gText_Quest_BuildingAnExhibit_Sub2_Map,
	        OBJ_EVENT_GFX_HIKER,
	        OBJECT,
	        sText_Found
	),
	sub_quest(
	        48,
	        gText_Quest_BuildingAnExhibit_Sub3_Name,
	        gText_Quest_BuildingAnExhibit_Sub3_Desc,
	        gText_Quest_BuildingAnExhibit_Sub3_Map,
	        OBJ_EVENT_GFX_BEAUTY,
	        OBJECT,
	        sText_Found
	),
	sub_quest(
	        49,
	        gText_Quest_BuildingAnExhibit_Sub4_Name,
	        gText_Quest_BuildingAnExhibit_Sub4_Desc,
	        gText_Quest_BuildingAnExhibit_Sub4_Map,
	        OBJ_EVENT_GFX_OLD_MAN,
	        OBJECT,
	        sText_Found
	),
};

static const struct SubQuest sBiomeResearch_Sub[QUEST_BIOMERESEARCH_SUB_COUNT] = {
	sub_quest(
	        50,
	        gText_Quest_BiomeResearch_Sub1_Name,
	        gText_Quest_BiomeResearch_Sub1_Desc,
	        gText_Quest_BiomeResearch_Sub1_Map,
	        SPECIES_JYNX,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        51,
	        gText_Quest_BiomeResearch_Sub2_Name,
	        gText_Quest_BiomeResearch_Sub2_Desc,
	        gText_Quest_BiomeResearch_Sub2_Map,
	        SPECIES_JYNX,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        52,
	        gText_Quest_BiomeResearch_Sub3_Name,
	        gText_Quest_BiomeResearch_Sub3_Desc,
	        gText_Quest_BiomeResearch_Sub3_Map,
	        SPECIES_BALTOY,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        53,
	        gText_Quest_BiomeResearch_Sub4_Name,
	        gText_Quest_BiomeResearch_Sub4_Desc,
	        gText_Quest_BiomeResearch_Sub4_Map,
	        SPECIES_BALTOY,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        54,
	        gText_Quest_BiomeResearch_Sub5_Name,
	        gText_Quest_BiomeResearch_Sub5_Desc,
	        gText_Quest_BiomeResearch_Sub5_Map,
	        SPECIES_PIDGEY,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        55,
	        gText_Quest_BiomeResearch_Sub6_Name,
	        gText_Quest_BiomeResearch_Sub6_Desc,
	        gText_Quest_BiomeResearch_Sub6_Map,
	        SPECIES_PIDGEY,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        56,
	        gText_Quest_BiomeResearch_Sub7_Name,
	        gText_Quest_BiomeResearch_Sub7_Desc,
	        gText_Quest_BiomeResearch_Sub7_Map,
	        SPECIES_SEVIPER,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        57,
	        gText_Quest_BiomeResearch_Sub8_Name,
	        gText_Quest_BiomeResearch_Sub8_Desc,
	        gText_Quest_BiomeResearch_Sub8_Map,
	        SPECIES_SEVIPER,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sBerrySustainability_Sub[QUEST_BERRYSUSTAINABILITY_SUB_COUNT] = {
	sub_quest(
	        58,
	        gText_Quest_BerrySustainability_Sub1_Name,
	        gText_Quest_BerrySustainability_Sub1_Desc,
	        gText_Quest_BerrySustainability_Sub1_Map,
	        ITEM_ORAN_BERRY,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        59,
	        gText_Quest_BerrySustainability_Sub2_Name,
	        gText_Quest_BerrySustainability_Sub2_Desc,
	        gText_Quest_BerrySustainability_Sub2_Map,
	        ITEM_PINAP_BERRY,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        60,
	        gText_Quest_BerrySustainability_Sub3_Name,
	        gText_Quest_BerrySustainability_Sub3_Desc,
	        gText_Quest_BerrySustainability_Sub3_Map,
	        ITEM_RAZZ_BERRY,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        61,
	        gText_Quest_BerrySustainability_Sub4_Name,
	        gText_Quest_BerrySustainability_Sub4_Desc,
	        gText_Quest_BerrySustainability_Sub4_Map,
	        ITEM_BELUE_BERRY,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        62,
	        gText_Quest_BerrySustainability_Sub5_Name,
	        gText_Quest_BerrySustainability_Sub5_Desc,
	        gText_Quest_BerrySustainability_Sub5_Map,
	        ITEM_WATMEL_BERRY,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        63,
	        gText_Quest_BerrySustainability_Sub6_Name,
	        gText_Quest_BerrySustainability_Sub6_Desc,
	        gText_Quest_BerrySustainability_Sub6_Map,
	        ITEM_LIECHI_BERRY,
	        ITEM,
	        sText_Delievered
	),
};

static const struct SubQuest sContractorPorygon_Sub[QUEST_CONTRACTORPORYGON_SUB_COUNT] = {
	sub_quest(
	        64,
	        gText_Quest_ContractorPorygon_Sub1_Name,
	        gText_Quest_ContractorPorygon_Sub1_Desc,
	        gText_Quest_ContractorPorygon_Sub1_Map,
	        OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F,
	        OBJECT,
	        sText_Delievered
	),
	sub_quest(
	        65,
	        gText_Quest_ContractorPorygon_Sub2_Name,
	        gText_Quest_ContractorPorygon_Sub2_Desc,
	        gText_Quest_ContractorPorygon_Sub2_Map,
	        OBJ_EVENT_GFX_TEALA,
	        OBJECT,
	        sText_Delievered
	),
	sub_quest(
	        66,
	        gText_Quest_ContractorPorygon_Sub3_Name,
	        gText_Quest_ContractorPorygon_Sub3_Desc,
	        gText_Quest_ContractorPorygon_Sub3_Map,
	        OBJ_EVENT_GFX_COOK,
	        OBJECT,
	        sText_Delievered
	),
};

static const struct SubQuest sGetTheBandBackTogether_Sub[QUEST_GETTHEBANDBACKTOGETHER_SUB_COUNT] = {
	sub_quest(
	        67,
	        gText_Quest_GetTheBandBackTogether_Sub1_Name,
	        gText_Quest_GetTheBandBackTogether_Sub1_Desc,
	        gText_Quest_GetTheBandBackTogether_Sub1_Map,
	        OBJ_EVENT_GFX_BOY_1,
	        OBJECT,
	        sText_Informed
	),
	sub_quest(
	        68,
	        gText_Quest_GetTheBandBackTogether_Sub2_Name,
	        gText_Quest_GetTheBandBackTogether_Sub2_Desc,
	        gText_Quest_GetTheBandBackTogether_Sub2_Map,
	        OBJ_EVENT_GFX_TEALA,
	        OBJECT,
	        sText_Informed
	),
	sub_quest(
	        69,
	        gText_Quest_GetTheBandBackTogether_Sub3_Name,
	        gText_Quest_GetTheBandBackTogether_Sub3_Desc,
	        gText_Quest_GetTheBandBackTogether_Sub3_Map,
	        OBJ_EVENT_GFX_WOMAN_2,
	        OBJECT,
	        sText_Informed
	),
	sub_quest(
	        70,
	        gText_Quest_GetTheBandBackTogether_Sub4_Name,
	        gText_Quest_GetTheBandBackTogether_Sub4_Desc,
	        gText_Quest_GetTheBandBackTogether_Sub4_Map,
	        OBJ_EVENT_GFX_COOK,
	        OBJECT,
	        sText_Informed
	),
	sub_quest(
	        71,
	        gText_Quest_GetTheBandBackTogether_Sub5_Name,
	        gText_Quest_GetTheBandBackTogether_Sub5_Desc,
	        gText_Quest_GetTheBandBackTogether_Sub5_Map,
	        OBJ_EVENT_GFX_GAMEBOY_KID,
	        OBJECT,
	        sText_Informed
	),
};

static const struct SubQuest sFoodTruckBureacracy_Sub[QUEST_FOODTRUCKBUREACRACY_SUB_COUNT] = {
	sub_quest(
	        72,
	        gText_Quest_FoodTruckBureacracy_Sub1_Name,
	        gText_Quest_FoodTruckBureacracy_Sub1_Desc,
	        gText_Quest_FoodTruckBureacracy_Sub1_Map,
	        OBJ_EVENT_GFX_BARD,
	        OBJECT,
	        sText_Delievered
	),
	sub_quest(
	        73,
	        gText_Quest_FoodTruckBureacracy_Sub2_Name,
	        gText_Quest_FoodTruckBureacracy_Sub2_Desc,
	        gText_Quest_FoodTruckBureacracy_Sub2_Map,
	        OBJ_EVENT_GFX_PICNICKER,
	        OBJECT,
	        sText_Delievered
	),
	sub_quest(
	        74,
	        gText_Quest_FoodTruckBureacracy_Sub3_Name,
	        gText_Quest_FoodTruckBureacracy_Sub3_Desc,
	        gText_Quest_FoodTruckBureacracy_Sub3_Map,
	        OBJ_EVENT_GFX_TEALA,
	        OBJECT,
	        sText_Delievered
	),
	sub_quest(
	        75,
	        gText_Quest_FoodTruckBureacracy_Sub4_Name,
	        gText_Quest_FoodTruckBureacracy_Sub4_Desc,
	        gText_Quest_FoodTruckBureacracy_Sub4_Map,
	        OBJ_EVENT_GFX_GIRL_2,
	        OBJECT,
	        sText_Delievered
	),
};

static const struct SubQuest sDetectiveAriana_Sub[QUEST_DETECTIVEARIANA_SUB_COUNT] = {
	sub_quest(
	        76,
	        gText_Quest_DetectiveAriana_Sub1_Name,
	        gText_Quest_DetectiveAriana_Sub1_Desc,
	        gText_Quest_DetectiveAriana_Sub1_Map,
	        OBJ_EVENT_GFX_MAN_2,
	        OBJECT,
	        sText_Investigated
	),
	sub_quest(
	        77,
	        gText_Quest_DetectiveAriana_Sub2_Name,
	        gText_Quest_DetectiveAriana_Sub2_Desc,
	        gText_Quest_DetectiveAriana_Sub2_Map,
	        OBJ_EVENT_GFX_OLD_WOMAN,
	        OBJECT,
	        sText_Investigated
	),
	sub_quest(
	        78,
	        gText_Quest_DetectiveAriana_Sub3_Name,
	        gText_Quest_DetectiveAriana_Sub3_Desc,
	        gText_Quest_DetectiveAriana_Sub3_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Investigated
	),
};

static const struct SubQuest sChallengeOfThe7Sisters_Sub[QUEST_CHALLENGEOFTHE7SISTERS_SUB_COUNT] = {
	sub_quest(
	        79,
	        gText_Quest_ChallengeOfThe7Sisters_Sub1_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub1_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub1_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
	sub_quest(
	        80,
	        gText_Quest_ChallengeOfThe7Sisters_Sub2_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub2_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub2_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
	sub_quest(
	        81,
	        gText_Quest_ChallengeOfThe7Sisters_Sub3_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub3_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub3_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
	sub_quest(
	        82,
	        gText_Quest_ChallengeOfThe7Sisters_Sub4_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub4_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub4_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
	sub_quest(
	        83,
	        gText_Quest_ChallengeOfThe7Sisters_Sub5_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub5_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub5_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
	sub_quest(
	        84,
	        gText_Quest_ChallengeOfThe7Sisters_Sub6_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub6_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub6_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
	sub_quest(
	        85,
	        gText_Quest_ChallengeOfThe7Sisters_Sub7_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Sub7_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_Sub7_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Completed
	),
};

static const struct SubQuest sCutePokemon_Sub[QUEST_CUTEPOKEMON_SUB_COUNT] = {
	sub_quest(
	        86,
	        gText_Quest_CutePokemon_Sub1_Name,
	        gText_Quest_CutePokemon_Sub1_Desc,
	        gText_Quest_CutePokemon_Sub1_Map,
	        SPECIES_DUSKULL,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        87,
	        gText_Quest_CutePokemon_Sub2_Name,
	        gText_Quest_CutePokemon_Sub2_Desc,
	        gText_Quest_CutePokemon_Sub2_Map,
	        SPECIES_SCRAFTY,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        88,
	        gText_Quest_CutePokemon_Sub3_Name,
	        gText_Quest_CutePokemon_Sub3_Desc,
	        gText_Quest_CutePokemon_Sub3_Map,
	        SPECIES_TEDDIURSA,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        89,
	        gText_Quest_CutePokemon_Sub4_Name,
	        gText_Quest_CutePokemon_Sub4_Desc,
	        gText_Quest_CutePokemon_Sub4_Map,
	        SPECIES_EISCUE,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sWallaceArmy_Sub[QUEST_WALLACEARMY_SUB_COUNT] = {
	sub_quest(
	        90,
	        gText_Quest_WallaceArmy_Sub2_Name,
	        gText_Quest_WallaceArmy_Sub2_Desc,
	        gText_Quest_WallaceArmy_Sub2_Map,
	        OBJ_EVENT_GFX_GIRL_1,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        91,
	        gText_Quest_WallaceArmy_Sub3_Name,
	        gText_Quest_WallaceArmy_Sub3_Desc,
	        gText_Quest_WallaceArmy_Sub3_Map,
	        OBJ_EVENT_GFX_SAILOR,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        92,
	        gText_Quest_WallaceArmy_Sub4_Name,
	        gText_Quest_WallaceArmy_Sub4_Desc,
	        gText_Quest_WallaceArmy_Sub4_Map,
	        OBJ_EVENT_GFX_DEVON_EMPLOYEE,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        93,
	        gText_Quest_WallaceArmy_Sub5_Name,
	        gText_Quest_WallaceArmy_Sub5_Desc,
	        gText_Quest_WallaceArmy_Sub5_Map,
	        OBJ_EVENT_GFX_MAN_4,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        94,
	        gText_Quest_WallaceArmy_Sub6_Name,
	        gText_Quest_WallaceArmy_Sub6_Desc,
	        gText_Quest_WallaceArmy_Sub6_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        sText_Defeated
	),
};

static const struct SubQuest sDexCompletion_Sub[QUEST_DEXCOMPLETION_SUB_COUNT] = {
	sub_quest(
	        95,
	        gText_Quest_DexCompletion_Sub1_Name,
	        gText_Quest_DexCompletion_Sub1_Desc,
	        gText_Quest_DexCompletion_Sub1_Map,
	        ITEM_OVAL_CHARM,
	        ITEM,
	        sText_Completed
	),
	sub_quest(
	        96,
	        gText_Quest_DexCompletion_Sub2_Name,
	        gText_Quest_DexCompletion_Sub2_Desc,
	        gText_Quest_DexCompletion_Sub2_Map,
	        ITEM_SHINY_CHARM,
	        ITEM,
	        sText_Completed
	),
};

static const struct SubQuest sKitchenVolunteering_Sub[QUEST_KITCHENVOLUNTEERING_SUB_COUNT] = {
	sub_quest(
	        97,
	        gText_Quest_KitchenVolunteering_Sub1_Name,
	        gText_Quest_KitchenVolunteering_Sub1_Desc,
	        gText_Quest_KitchenVolunteering_Sub1_Map,
	        ITEM_BIG_MALASADA,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        98,
	        gText_Quest_KitchenVolunteering_Sub2_Name,
	        gText_Quest_KitchenVolunteering_Sub2_Desc,
	        gText_Quest_KitchenVolunteering_Sub2_Map,
	        ITEM_BIG_MALASADA,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        99,
	        gText_Quest_KitchenVolunteering_Sub3_Name,
	        gText_Quest_KitchenVolunteering_Sub3_Desc,
	        gText_Quest_KitchenVolunteering_Sub3_Map,
	        ITEM_BIG_MALASADA,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        100,
	        gText_Quest_KitchenVolunteering_Sub4_Name,
	        gText_Quest_KitchenVolunteering_Sub4_Desc,
	        gText_Quest_KitchenVolunteering_Sub4_Map,
	        ITEM_BIG_MALASADA,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        101,
	        gText_Quest_KitchenVolunteering_Sub5_Name,
	        gText_Quest_KitchenVolunteering_Sub5_Desc,
	        gText_Quest_KitchenVolunteering_Sub5_Map,
	        ITEM_BIG_MALASADA,
	        ITEM,
	        sText_Found
	),
};

static const struct SubQuest sArtisanBalls_Sub[QUEST_ARTISANBALLS_SUB_COUNT] = {
	sub_quest(
	        102,
	        gText_Quest_ArtisanBalls_Sub1_Name,
	        gText_Quest_ArtisanBalls_Sub1_Desc,
	        gText_Quest_ArtisanBalls_Sub1_Map,
	        ITEM_FAST_BALL,
	        ITEM,
	        sText_Tested
	),
	sub_quest(
	        103,
	        gText_Quest_ArtisanBalls_Sub2_Name,
	        gText_Quest_ArtisanBalls_Sub2_Desc,
	        gText_Quest_ArtisanBalls_Sub2_Map,
	        ITEM_LEVEL_BALL,
	        ITEM,
	        sText_Tested
	),
	sub_quest(
	        104,
	        gText_Quest_ArtisanBalls_Sub3_Name,
	        gText_Quest_ArtisanBalls_Sub3_Desc,
	        gText_Quest_ArtisanBalls_Sub3_Map,
	        ITEM_LURE_BALL,
	        ITEM,
	        sText_Tested
	),
	sub_quest(
	        105,
	        gText_Quest_ArtisanBalls_Sub4_Name,
	        gText_Quest_ArtisanBalls_Sub4_Desc,
	        gText_Quest_ArtisanBalls_Sub4_Map,
	        ITEM_HEAVY_BALL,
	        ITEM,
	        sText_Tested
	),
	sub_quest(
	        106,
	        gText_Quest_ArtisanBalls_Sub5_Name,
	        gText_Quest_ArtisanBalls_Sub5_Desc,
	        gText_Quest_ArtisanBalls_Sub5_Map,
	        ITEM_LOVE_BALL,
	        ITEM,
	        sText_Tested
	),
	sub_quest(
	        107,
	        gText_Quest_ArtisanBalls_Sub6_Name,
	        gText_Quest_ArtisanBalls_Sub6_Desc,
	        gText_Quest_ArtisanBalls_Sub6_Map,
	        ITEM_FRIEND_BALL,
	        ITEM,
	        sText_Tested
	),
	sub_quest(
	        108,
	        gText_Quest_ArtisanBalls_Sub7_Name,
	        gText_Quest_ArtisanBalls_Sub7_Desc,
	        gText_Quest_ArtisanBalls_Sub7_Map,
	        ITEM_MOON_BALL,
	        ITEM,
	        sText_Tested
	),
};

static const struct SubQuest sArtisanBalls2_Sub[QUEST_ARTISANBALLS2_SUB_COUNT] = {
	sub_quest(
	        109,
	        gText_Quest_ArtisanBalls2_Sub1_Name,
	        gText_Quest_ArtisanBalls2_Sub1_Desc,
	        gText_Quest_ArtisanBalls2_Sub1_Map,
	        OBJ_EVENT_GFX_MANIAC,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        110,
	        gText_Quest_ArtisanBalls2_Sub2_Name,
	        gText_Quest_ArtisanBalls2_Sub2_Desc,
	        gText_Quest_ArtisanBalls2_Sub2_Map,
	        OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        111,
	        gText_Quest_ArtisanBalls2_Sub3_Name,
	        gText_Quest_ArtisanBalls2_Sub3_Desc,
	        gText_Quest_ArtisanBalls2_Sub3_Map,
	        OBJ_EVENT_GFX_MAN_1,
	        OBJECT,
	        sText_Recruited
	),
};

static const struct SubQuest sShelterSwitcheroo_Sub[QUEST_SHELTERSWITCHEROO_SUB_COUNT] = {
	sub_quest(
	        112,
	        gText_Quest_ShelterSwitcheroo_Sub1_Name,
	        gText_Quest_ShelterSwitcheroo_Sub1_Desc,
	        gText_Quest_ShelterSwitcheroo_Sub1_Map,
	        ITEM_REAPER_CLOTH,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        113,
	        gText_Quest_ShelterSwitcheroo_Sub2_Name,
	        gText_Quest_ShelterSwitcheroo_Sub2_Desc,
	        gText_Quest_ShelterSwitcheroo_Sub2_Map,
	        ITEM_REAPER_CLOTH,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        114,
	        gText_Quest_ShelterSwitcheroo_Sub3_Name,
	        gText_Quest_ShelterSwitcheroo_Sub3_Desc,
	        gText_Quest_ShelterSwitcheroo_Sub3_Map,
	        ITEM_REAPER_CLOTH,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        115,
	        gText_Quest_ShelterSwitcheroo_Sub4_Name,
	        gText_Quest_ShelterSwitcheroo_Sub4_Desc,
	        gText_Quest_ShelterSwitcheroo_Sub4_Map,
	        ITEM_REAPER_CLOTH,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        116,
	        gText_Quest_ShelterSwitcheroo_Sub5_Name,
	        gText_Quest_ShelterSwitcheroo_Sub5_Desc,
	        gText_Quest_ShelterSwitcheroo_Sub5_Map,
	        ITEM_REAPER_CLOTH,
	        ITEM,
	        sText_Delievered
	),
};

static const struct SubQuest sShelterTaxiSolution_Sub[QUEST_SHELTERTAXISOLUTION_SUB_COUNT] = {
	sub_quest(
	        117,
	        gText_Quest_ShelterTaxiSolution_Sub1_Name,
	        gText_Quest_ShelterTaxiSolution_Sub1_Desc,
	        gText_Quest_ShelterTaxiSolution_Sub1_Map,
	        SPECIES_CORVIKNIGHT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        118,
	        gText_Quest_ShelterTaxiSolution_Sub2_Name,
	        gText_Quest_ShelterTaxiSolution_Sub2_Desc,
	        gText_Quest_ShelterTaxiSolution_Sub2_Map,
	        SPECIES_CORVIKNIGHT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        119,
	        gText_Quest_ShelterTaxiSolution_Sub3_Name,
	        gText_Quest_ShelterTaxiSolution_Sub3_Desc,
	        gText_Quest_ShelterTaxiSolution_Sub3_Map,
	        SPECIES_CORVIKNIGHT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        120,
	        gText_Quest_ShelterTaxiSolution_Sub4_Name,
	        gText_Quest_ShelterTaxiSolution_Sub4_Desc,
	        gText_Quest_ShelterTaxiSolution_Sub4_Map,
	        SPECIES_CORVIKNIGHT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        121,
	        gText_Quest_ShelterTaxiSolution_Sub5_Name,
	        gText_Quest_ShelterTaxiSolution_Sub5_Desc,
	        gText_Quest_ShelterTaxiSolution_Sub5_Map,
	        SPECIES_CORVIKNIGHT,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sNeighborhoodCleanUp_Sub[QUEST_NEIGHBORHOODCLEANUP_SUB_COUNT] = {
	sub_quest(
	        122,
	        gText_Quest_NeighborhoodCleanUp_Sub1_Name,
	        gText_Quest_NeighborhoodCleanUp_Sub1_Desc,
	        gText_Quest_NeighborhoodCleanUp_Sub1_Map,
	        OBJ_EVENT_GFX_MAN_2,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        123,
	        gText_Quest_NeighborhoodCleanUp_Sub2_Name,
	        gText_Quest_NeighborhoodCleanUp_Sub2_Desc,
	        gText_Quest_NeighborhoodCleanUp_Sub2_Map,
	        OBJ_EVENT_GFX_FISHERMAN,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        124,
	        gText_Quest_NeighborhoodCleanUp_Sub3_Name,
	        gText_Quest_NeighborhoodCleanUp_Sub3_Desc,
	        gText_Quest_NeighborhoodCleanUp_Sub3_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        125,
	        gText_Quest_NeighborhoodCleanUp_Sub4_Name,
	        gText_Quest_NeighborhoodCleanUp_Sub4_Desc,
	        gText_Quest_NeighborhoodCleanUp_Sub4_Map,
	        OBJ_EVENT_GFX_BEAUTY,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        126,
	        gText_Quest_NeighborhoodCleanUp_Sub5_Name,
	        gText_Quest_NeighborhoodCleanUp_Sub5_Desc,
	        gText_Quest_NeighborhoodCleanUp_Sub5_Map,
	        OBJ_EVENT_GFX_GIRL_1,
	        OBJECT,
	        sText_Defeated
	),
};

static const struct SubQuest sNeighborhoodCleanUp2_Sub[QUEST_NEIGHBORHOODCLEANUP2_SUB_COUNT] = {
	sub_quest(
	        127,
	        gText_Quest_NeighborhoodCleanUp2_Sub1_Name,
	        gText_Quest_NeighborhoodCleanUp2_Sub1_Desc,
	        gText_Quest_NeighborhoodCleanUp2_Sub1_Map,
	        OBJ_EVENT_GFX_MAN_2,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        128,
	        gText_Quest_NeighborhoodCleanUp2_Sub2_Name,
	        gText_Quest_NeighborhoodCleanUp2_Sub2_Desc,
	        gText_Quest_NeighborhoodCleanUp2_Sub2_Map,
	        OBJ_EVENT_GFX_FISHERMAN,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        129,
	        gText_Quest_NeighborhoodCleanUp2_Sub3_Name,
	        gText_Quest_NeighborhoodCleanUp2_Sub3_Desc,
	        gText_Quest_NeighborhoodCleanUp2_Sub3_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        130,
	        gText_Quest_NeighborhoodCleanUp2_Sub4_Name,
	        gText_Quest_NeighborhoodCleanUp2_Sub4_Desc,
	        gText_Quest_NeighborhoodCleanUp2_Sub4_Map,
	        OBJ_EVENT_GFX_BEAUTY,
	        OBJECT,
	        sText_Defeated
	),
};

static const struct SubQuest sNeighborhoodCleanUp3_Sub[QUEST_NEIGHBORHOODCLEANUP3_SUB_COUNT] = {
	sub_quest(
	        131,
	        gText_Quest_NeighborhoodCleanUp3_Sub1_Name,
	        gText_Quest_NeighborhoodCleanUp3_Sub1_Desc,
	        gText_Quest_NeighborhoodCleanUp3_Sub1_Map,
	        OBJ_EVENT_GFX_MAN_2,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        132,
	        gText_Quest_NeighborhoodCleanUp3_Sub2_Name,
	        gText_Quest_NeighborhoodCleanUp3_Sub2_Desc,
	        gText_Quest_NeighborhoodCleanUp3_Sub2_Map,
	        OBJ_EVENT_GFX_FISHERMAN,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        133,
	        gText_Quest_NeighborhoodCleanUp3_Sub3_Name,
	        gText_Quest_NeighborhoodCleanUp3_Sub3_Desc,
	        gText_Quest_NeighborhoodCleanUp3_Sub3_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Defeated
	),
};

static const struct SubQuest sRockCollector_Sub[QUEST_ROCKCOLLECTOR_SUB_COUNT] = {
	sub_quest(
	        134,
	        gText_Quest_RockCollector_Sub1_Name,
	        gText_Quest_RockCollector_Sub1_Desc,
	        gText_Quest_RockCollector_Sub1_Map,
	        ITEM_FIRE_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        135,
	        gText_Quest_RockCollector_Sub2_Name,
	        gText_Quest_RockCollector_Sub2_Desc,
	        gText_Quest_RockCollector_Sub2_Map,
	        ITEM_WATER_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        136,
	        gText_Quest_RockCollector_Sub3_Name,
	        gText_Quest_RockCollector_Sub3_Desc,
	        gText_Quest_RockCollector_Sub3_Map,
	        ITEM_THUNDER_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        137,
	        gText_Quest_RockCollector_Sub4_Name,
	        gText_Quest_RockCollector_Sub4_Desc,
	        gText_Quest_RockCollector_Sub4_Map,
	        ITEM_LEAF_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        138,
	        gText_Quest_RockCollector_Sub5_Name,
	        gText_Quest_RockCollector_Sub5_Desc,
	        gText_Quest_RockCollector_Sub5_Map,
	        ITEM_MOON_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        139,
	        gText_Quest_RockCollector_Sub6_Name,
	        gText_Quest_RockCollector_Sub6_Desc,
	        gText_Quest_RockCollector_Sub6_Map,
	        ITEM_SUN_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        140,
	        gText_Quest_RockCollector_Sub7_Name,
	        gText_Quest_RockCollector_Sub7_Desc,
	        gText_Quest_RockCollector_Sub7_Map,
	        ITEM_SHINY_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        141,
	        gText_Quest_RockCollector_Sub8_Name,
	        gText_Quest_RockCollector_Sub8_Desc,
	        gText_Quest_RockCollector_Sub8_Map,
	        ITEM_DUSK_BALL,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        142,
	        gText_Quest_RockCollector_Sub9_Name,
	        gText_Quest_RockCollector_Sub9_Desc,
	        gText_Quest_RockCollector_Sub9_Map,
	        ITEM_DAWN_STONE,
	        ITEM,
	        sText_Delievered
	),
	sub_quest(
	        143,
	        gText_Quest_RockCollector_Sub10_Name,
	        gText_Quest_RockCollector_Sub10_Desc,
	        gText_Quest_RockCollector_Sub10_Map,
	        ITEM_ICE_STONE,
	        ITEM,
	        sText_Delievered
	),
};

static const struct SubQuest sHiddenGrottoMapping_Sub[QUEST_HIDDENGROTTOMAPPING_SUB_COUNT] = {
	sub_quest(
	        144,
	        gText_Quest_HiddenGrottoMapping_Sub1_Name,
	        gText_Quest_HiddenGrottoMapping_Sub1_Desc,
	        gText_Quest_HiddenGrottoMapping_Sub1_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        145,
	        gText_Quest_HiddenGrottoMapping_Sub2_Name,
	        gText_Quest_HiddenGrottoMapping_Sub2_Desc,
	        gText_Quest_HiddenGrottoMapping_Sub2_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        146,
	        gText_Quest_HiddenGrottoMapping_Sub3_Name,
	        gText_Quest_HiddenGrottoMapping_Sub3_Desc,
	        gText_Quest_HiddenGrottoMapping_Sub3_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        147,
	        gText_Quest_HiddenGrottoMapping_Sub4_Name,
	        gText_Quest_HiddenGrottoMapping_Sub4_Desc,
	        gText_Quest_HiddenGrottoMapping_Sub4_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        148,
	        gText_Quest_HiddenGrottoMapping_Sub5_Name,
	        gText_Quest_HiddenGrottoMapping_Sub5_Desc,
	        gText_Quest_HiddenGrottoMapping_Sub5_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
};

static const struct SubQuest sHiddenGrottoMapping2_Sub[QUEST_HIDDENGROTTOMAPPING2_SUB_COUNT] = {
	sub_quest(
	        149,
	        gText_Quest_HiddenGrottoMapping2_Sub1_Name,
	        gText_Quest_HiddenGrottoMapping2_Sub1_Desc,
	        gText_Quest_HiddenGrottoMapping2_Sub1_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        150,
	        gText_Quest_HiddenGrottoMapping2_Sub2_Name,
	        gText_Quest_HiddenGrottoMapping2_Sub2_Desc,
	        gText_Quest_HiddenGrottoMapping2_Sub2_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
	sub_quest(
	        151,
	        gText_Quest_HiddenGrottoMapping2_Sub3_Name,
	        gText_Quest_HiddenGrottoMapping2_Sub3_Desc,
	        gText_Quest_HiddenGrottoMapping2_Sub3_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sText_Discovered
	),
};

static const struct SubQuest sUltraWormholeResearch_Sub[QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT] = {
	sub_quest(
	        152,
	        gText_Quest_UltraWormholeResearch_Sub1_Name,
	        gText_Quest_UltraWormholeResearch_Sub1_Desc,
	        gText_Quest_UltraWormholeResearch_Sub1_Map,
	        SPECIES_POIPOLE,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        153,
	        gText_Quest_UltraWormholeResearch_Sub2_Name,
	        gText_Quest_UltraWormholeResearch_Sub2_Desc,
	        gText_Quest_UltraWormholeResearch_Sub2_Map,
	        SPECIES_DUSCLOPS,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        154,
	        gText_Quest_UltraWormholeResearch_Sub3_Name,
	        gText_Quest_UltraWormholeResearch_Sub3_Desc,
	        gText_Quest_UltraWormholeResearch_Sub3_Map,
	        SPECIES_VOLCARONA,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        155,
	        gText_Quest_UltraWormholeResearch_Sub4_Name,
	        gText_Quest_UltraWormholeResearch_Sub4_Desc,
	        gText_Quest_UltraWormholeResearch_Sub4_Map,
	        SPECIES_CAMERUPT,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        156,
	        gText_Quest_UltraWormholeResearch_Sub5_Name,
	        gText_Quest_UltraWormholeResearch_Sub5_Desc,
	        gText_Quest_UltraWormholeResearch_Sub5_Map,
	        SPECIES_DEINO,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        157,
	        gText_Quest_UltraWormholeResearch_Sub6_Name,
	        gText_Quest_UltraWormholeResearch_Sub6_Desc,
	        gText_Quest_UltraWormholeResearch_Sub6_Map,
	        SPECIES_NOIVERN,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        158,
	        gText_Quest_UltraWormholeResearch_Sub7_Name,
	        gText_Quest_UltraWormholeResearch_Sub7_Desc,
	        gText_Quest_UltraWormholeResearch_Sub7_Map,
	        SPECIES_SHUCKLE,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        159,
	        gText_Quest_UltraWormholeResearch_Sub8_Name,
	        gText_Quest_UltraWormholeResearch_Sub8_Desc,
	        gText_Quest_UltraWormholeResearch_Sub8_Map,
	        SPECIES_KINGLER,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        160,
	        gText_Quest_UltraWormholeResearch_Sub9_Name,
	        gText_Quest_UltraWormholeResearch_Sub9_Desc,
	        gText_Quest_UltraWormholeResearch_Sub9_Map,
	        SPECIES_ORBEETLE,
	        PKMN,
	        sText_Caught
	),
	sub_quest(
	        161,
	        gText_Quest_UltraWormholeResearch_Sub10_Name,
	        gText_Quest_UltraWormholeResearch_Sub10_Desc,
	        gText_Quest_UltraWormholeResearch_Sub10_Map,
	        SPECIES_DONPHAN,
	        PKMN,
	        sText_Caught
	),
};

static const struct SubQuest sWildfireRisk_Sub[QUEST_WILDFIRERISK_SUB_COUNT] = {
	sub_quest(
	        162,
	        gText_Quest_WildfireRisk_Sub1_Name,
	        gText_Quest_WildfireRisk_Sub1_Desc,
	        gText_Quest_WildfireRisk_Sub1_Map,
	        ITEM_FIRE_GEM,
	        ITEM,
	        sText_Defeated
	),
	sub_quest(
	        163,
	        gText_Quest_WildfireRisk_Sub2_Name,
	        gText_Quest_WildfireRisk_Sub2_Desc,
	        gText_Quest_WildfireRisk_Sub2_Map,
	        ITEM_FLYING_GEM,
	        ITEM,
	        sText_Defeated
	),
	sub_quest(
	        164,
	        gText_Quest_WildfireRisk_Sub3_Name,
	        gText_Quest_WildfireRisk_Sub3_Desc,
	        gText_Quest_WildfireRisk_Sub3_Map,
	        ITEM_ELECTRIC_GEM,
	        ITEM,
	        sText_Defeated
	),
};

static const struct SubQuest sTheBoyWhoCriesWithWolves_Sub[QUEST_THEBOYWHOCRIESWITHWOLVES_SUB_COUNT]
	= {
	sub_quest(
	        165,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub1_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub1_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub1_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        166,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub2_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub2_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub2_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        167,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub3_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub3_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub3_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        168,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub4_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub4_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub4_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        169,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub5_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub5_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub5_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        170,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub6_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub6_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub6_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        171,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub7_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub7_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub7_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        172,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub8_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub8_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub8_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
	sub_quest(
	        173,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub9_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub9_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Sub9_Map,
	        ITEM_POKE_BALL,
	        ITEM,
	        sText_Found
	),
};

static const struct SubQuest sTaxicabTurnAroundSea_Sub[QUEST_TAXICABTURNAROUNDSEA_SUB_COUNT] = {
	sub_quest(
	        174,
	        gText_Quest_TaxicabTurnAroundSea_Sub1_Name,
	        gText_Quest_TaxicabTurnAroundSea_Sub1_Desc,
	        gText_Quest_TaxicabTurnAroundSea_Sub1_Map,
	        SPECIES_LAPRAS,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        175,
	        gText_Quest_TaxicabTurnAroundSea_Sub2_Name,
	        gText_Quest_TaxicabTurnAroundSea_Sub2_Desc,
	        gText_Quest_TaxicabTurnAroundSea_Sub2_Map,
	        SPECIES_LAPRAS,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        176,
	        gText_Quest_TaxicabTurnAroundSea_Sub3_Name,
	        gText_Quest_TaxicabTurnAroundSea_Sub3_Desc,
	        gText_Quest_TaxicabTurnAroundSea_Sub3_Map,
	        SPECIES_LAPRAS,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        177,
	        gText_Quest_TaxicabTurnAroundSea_Sub4_Name,
	        gText_Quest_TaxicabTurnAroundSea_Sub4_Desc,
	        gText_Quest_TaxicabTurnAroundSea_Sub4_Map,
	        SPECIES_LAPRAS,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        178,
	        gText_Quest_TaxicabTurnAroundSea_Sub5_Name,
	        gText_Quest_TaxicabTurnAroundSea_Sub5_Desc,
	        gText_Quest_TaxicabTurnAroundSea_Sub5_Map,
	        SPECIES_LAPRAS,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sTaxicabTurnAroundAir_Sub[QUEST_TAXICABTURNAROUNDAIR_SUB_COUNT] = {
	sub_quest(
	        179,
	        gText_Quest_TaxicabTurnAroundAir_Sub1_Name,
	        gText_Quest_TaxicabTurnAroundAir_Sub1_Desc,
	        gText_Quest_TaxicabTurnAroundAir_Sub1_Map,
	        SPECIES_PIDGEOT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        180,
	        gText_Quest_TaxicabTurnAroundAir_Sub2_Name,
	        gText_Quest_TaxicabTurnAroundAir_Sub2_Desc,
	        gText_Quest_TaxicabTurnAroundAir_Sub2_Map,
	        SPECIES_PIDGEOT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        181,
	        gText_Quest_TaxicabTurnAroundAir_Sub3_Name,
	        gText_Quest_TaxicabTurnAroundAir_Sub3_Desc,
	        gText_Quest_TaxicabTurnAroundAir_Sub3_Map,
	        SPECIES_PIDGEOT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        182,
	        gText_Quest_TaxicabTurnAroundAir_Sub4_Name,
	        gText_Quest_TaxicabTurnAroundAir_Sub4_Desc,
	        gText_Quest_TaxicabTurnAroundAir_Sub4_Map,
	        SPECIES_PIDGEOT,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        183,
	        gText_Quest_TaxicabTurnAroundAir_Sub5_Name,
	        gText_Quest_TaxicabTurnAroundAir_Sub5_Desc,
	        gText_Quest_TaxicabTurnAroundAir_Sub5_Map,
	        SPECIES_PIDGEOT,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sTaxicabTurnAroundLand_Sub[QUEST_TAXICABTURNAROUNDLAND_SUB_COUNT] = {
	sub_quest(
	        184,
	        gText_Quest_TaxicabTurnAroundLand_Sub1_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub1_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub1_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        185,
	        gText_Quest_TaxicabTurnAroundLand_Sub2_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub2_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub2_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        186,
	        gText_Quest_TaxicabTurnAroundLand_Sub3_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub3_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub3_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        187,
	        gText_Quest_TaxicabTurnAroundLand_Sub4_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub4_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub4_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        188,
	        gText_Quest_TaxicabTurnAroundLand_Sub5_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub5_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub5_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        189,
	        gText_Quest_TaxicabTurnAroundLand_Sub6_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub6_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub6_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        190,
	        gText_Quest_TaxicabTurnAroundLand_Sub7_Name,
	        gText_Quest_TaxicabTurnAroundLand_Sub7_Desc,
	        gText_Quest_TaxicabTurnAroundLand_Sub7_Map,
	        SPECIES_DODRIO,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sPersuasivePassenger_Sub[QUEST_PERSUASIVEPASSENGER_SUB_COUNT] = {
	sub_quest(
	        191,
	        gText_Quest_PersuasivePassenger_Sub1_Name,
	        gText_Quest_PersuasivePassenger_Sub1_Desc,
	        gText_Quest_PersuasivePassenger_Sub1_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        sText_Helped
	),
	sub_quest(
	        192,
	        gText_Quest_PersuasivePassenger_Sub2_Name,
	        gText_Quest_PersuasivePassenger_Sub2_Desc,
	        gText_Quest_PersuasivePassenger_Sub2_Map,
	        OBJ_EVENT_GFX_WOMAN_1,
	        OBJECT,
	        sText_Helped
	),
	sub_quest(
	        193,
	        gText_Quest_PersuasivePassenger_Sub3_Name,
	        gText_Quest_PersuasivePassenger_Sub3_Desc,
	        gText_Quest_PersuasivePassenger_Sub3_Map,
	        OBJ_EVENT_GFX_HIKER,
	        OBJECT,
	        sText_Defeated
	),
};

static const struct SubQuest sBodegaBurnout_Sub[QUEST_BODEGABURNOUT_SUB_COUNT] = {
	sub_quest(
	        194,
	        gText_Quest_BodegaBurnout_Sub1_Name,
	        gText_Quest_BodegaBurnout_Sub1_Desc,
	        gText_Quest_BodegaBurnout_Sub1_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        195,
	        gText_Quest_BodegaBurnout_Sub2_Name,
	        gText_Quest_BodegaBurnout_Sub2_Desc,
	        gText_Quest_BodegaBurnout_Sub2_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        196,
	        gText_Quest_BodegaBurnout_Sub3_Name,
	        gText_Quest_BodegaBurnout_Sub3_Desc,
	        gText_Quest_BodegaBurnout_Sub3_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        197,
	        gText_Quest_BodegaBurnout_Sub4_Name,
	        gText_Quest_BodegaBurnout_Sub4_Desc,
	        gText_Quest_BodegaBurnout_Sub4_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        198,
	        gText_Quest_BodegaBurnout_Sub5_Name,
	        gText_Quest_BodegaBurnout_Sub5_Desc,
	        gText_Quest_BodegaBurnout_Sub5_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        199,
	        gText_Quest_BodegaBurnout_Sub6_Name,
	        gText_Quest_BodegaBurnout_Sub6_Desc,
	        gText_Quest_BodegaBurnout_Sub6_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        200,
	        gText_Quest_BodegaBurnout_Sub7_Name,
	        gText_Quest_BodegaBurnout_Sub7_Desc,
	        gText_Quest_BodegaBurnout_Sub7_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        201,
	        gText_Quest_BodegaBurnout_Sub8_Name,
	        gText_Quest_BodegaBurnout_Sub8_Desc,
	        gText_Quest_BodegaBurnout_Sub8_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        202,
	        gText_Quest_BodegaBurnout_Sub9_Name,
	        gText_Quest_BodegaBurnout_Sub9_Desc,
	        gText_Quest_BodegaBurnout_Sub9_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        203,
	        gText_Quest_BodegaBurnout_Sub10_Name,
	        gText_Quest_BodegaBurnout_Sub10_Desc,
	        gText_Quest_BodegaBurnout_Sub10_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        204,
	        gText_Quest_BodegaBurnout_Sub11_Name,
	        gText_Quest_BodegaBurnout_Sub11_Desc,
	        gText_Quest_BodegaBurnout_Sub11_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        205,
	        gText_Quest_BodegaBurnout_Sub12_Name,
	        gText_Quest_BodegaBurnout_Sub12_Desc,
	        gText_Quest_BodegaBurnout_Sub12_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        206,
	        gText_Quest_BodegaBurnout_Sub13_Name,
	        gText_Quest_BodegaBurnout_Sub13_Desc,
	        gText_Quest_BodegaBurnout_Sub13_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        207,
	        gText_Quest_BodegaBurnout_Sub14_Name,
	        gText_Quest_BodegaBurnout_Sub14_Desc,
	        gText_Quest_BodegaBurnout_Sub14_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        208,
	        gText_Quest_BodegaBurnout_Sub15_Name,
	        gText_Quest_BodegaBurnout_Sub15_Desc,
	        gText_Quest_BodegaBurnout_Sub15_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        209,
	        gText_Quest_BodegaBurnout_Sub16_Name,
	        gText_Quest_BodegaBurnout_Sub16_Desc,
	        gText_Quest_BodegaBurnout_Sub16_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
	sub_quest(
	        210,
	        gText_Quest_BodegaBurnout_Sub17_Name,
	        gText_Quest_BodegaBurnout_Sub17_Desc,
	        gText_Quest_BodegaBurnout_Sub17_Map,
	        SPECIES_DITTO,
	        PKMN,
	        sText_Gave
	),
};

static const struct SubQuest sWarehouseWarfare_Sub[QUEST_WAREHOUSEWARFARE_SUB_COUNT] = {
	sub_quest(
	        211,
	        gText_Quest_WarehouseWarfare_Sub1_Name,
	        gText_Quest_WarehouseWarfare_Sub1_Desc,
	        gText_Quest_WarehouseWarfare_Sub1_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        212,
	        gText_Quest_WarehouseWarfare_Sub2_Name,
	        gText_Quest_WarehouseWarfare_Sub2_Desc,
	        gText_Quest_WarehouseWarfare_Sub2_Map,
	        OBJ_EVENT_GFX_ROOFTOP_SALE_WOMAN,
	        OBJECT,
	        sText_Defeated
	),
	sub_quest(
	        213,
	        gText_Quest_WarehouseWarfare_Sub3_Name,
	        gText_Quest_WarehouseWarfare_Sub3_Desc,
	        gText_Quest_WarehouseWarfare_Sub3_Map,
	        OBJ_EVENT_GFX_MAN_5,
	        OBJECT,
	        sText_Defeated
	),
};

static const struct SubQuest
	sRestoreToTheirFormerGlory_Sub[QUEST_RESTORETOTHEIRFORMERGLORY_SUB_COUNT] = {
	sub_quest(
	        214,
	        gText_Quest_RestoreToTheirFormerGlory_Sub1_Name,
	        gText_Quest_RestoreToTheirFormerGlory_Sub1_Desc,
	        gText_Quest_RestoreToTheirFormerGlory_Sub1_Map,
	        OBJ_EVENT_GFX_WALLY,
	        OBJECT,
	        sText_Restored
	),
	sub_quest(
	        215,
	        gText_Quest_RestoreToTheirFormerGlory_Sub2_Name,
	        gText_Quest_RestoreToTheirFormerGlory_Sub2_Desc,
	        gText_Quest_RestoreToTheirFormerGlory_Sub2_Map,
	        OBJ_EVENT_GFX_WALLY,
	        OBJECT,
	        sText_Restored
	),
	sub_quest(
	        216,
	        gText_Quest_RestoreToTheirFormerGlory_Sub3_Name,
	        gText_Quest_RestoreToTheirFormerGlory_Sub3_Desc,
	        gText_Quest_RestoreToTheirFormerGlory_Sub3_Map,
	        OBJ_EVENT_GFX_WALLY,
	        OBJECT,
	        sText_Restored
	),
	sub_quest(
	        217,
	        gText_Quest_RestoreToTheirFormerGlory_Sub4_Name,
	        gText_Quest_RestoreToTheirFormerGlory_Sub4_Desc,
	        gText_Quest_RestoreToTheirFormerGlory_Sub4_Map,
	        OBJ_EVENT_GFX_WALLY,
	        OBJECT,
	        sText_Restored
	),
};
static const struct SubQuest
	sRestoreMarin_Sub[QUEST_RESTOREMARIN_SUB_COUNT] = {
	sub_quest(
	        218,
	        gText_Quest_RestoreMarin_Sub1_Name,
	        gText_Quest_RestoreMarin_Sub1_Desc,
	        gText_Quest_RestoreMarin_Sub1_Map,
	        SPECIES_KRABBY,
	        PKMN,
            sText_Caught
	),
	sub_quest(
	        219,
	        gText_Quest_RestoreMarin_Sub2_Name,
	        gText_Quest_RestoreMarin_Sub2_Desc,
	        gText_Quest_RestoreMarin_Sub2_Map,
	        SPECIES_COPPERAJAH,
	        PKMN,
            sText_Caught
	),
};
static const struct SubQuest sRestoreChinatown_Sub[QUEST_RESTORECHINATOWN_SUB_COUNT] = {
    sub_quest(
            220,
            gText_Quest_RestoreChinatown_Sub1_Name,
            gText_Quest_RestoreChinatown_Sub1_Desc,
            gText_Quest_RestoreChinatown_Sub1_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
    sub_quest(
            221,
            gText_Quest_RestoreChinatown_Sub2_Name,
            gText_Quest_RestoreChinatown_Sub2_Desc,
            gText_Quest_RestoreChinatown_Sub2_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
    sub_quest(
            222,
            gText_Quest_RestoreChinatown_Sub3_Name,
            gText_Quest_RestoreChinatown_Sub3_Desc,
            gText_Quest_RestoreChinatown_Sub3_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
    sub_quest(
            223,
            gText_Quest_RestoreChinatown_Sub4_Name,
            gText_Quest_RestoreChinatown_Sub4_Desc,
            gText_Quest_RestoreChinatown_Sub4_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
    sub_quest(
            224,
            gText_Quest_RestoreChinatown_Sub5_Name,
            gText_Quest_RestoreChinatown_Sub5_Desc,
            gText_Quest_RestoreChinatown_Sub5_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
    sub_quest(
            225,
            gText_Quest_RestoreChinatown_Sub6_Name,
            gText_Quest_RestoreChinatown_Sub6_Desc,
            gText_Quest_RestoreChinatown_Sub6_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
    sub_quest(
            226,
            gText_Quest_RestoreChinatown_Sub7_Name,
            gText_Quest_RestoreChinatown_Sub7_Desc,
            gText_Quest_RestoreChinatown_Sub7_Map,
            OBJ_EVENT_GFX_BLACK_BELT,
            OBJECT,
            sText_Recruited
            ),
};
static const struct SubQuest
	sRestoreTreasureisland_Sub[QUEST_RESTORETREASUREISLAND_SUB_COUNT] = {
	sub_quest(
	        227,
	        gText_Quest_RestoreTreasureisland_Sub1_Name,
	        gText_Quest_RestoreTreasureisland_Sub1_Desc,
	        gText_Quest_RestoreTreasureisland_Sub1_Map,
	        ITEM_FLAME_ORB,
	        ITEM,
            sText_Found
	),
	sub_quest(
	        228,
	        gText_Quest_RestoreTreasureisland_Sub2_Name,
	        gText_Quest_RestoreTreasureisland_Sub2_Desc,
	        gText_Quest_RestoreTreasureisland_Sub2_Map,
	        ITEM_TM27,
	        ITEM,
            sText_Found
	),
	sub_quest(
	        229,
	        gText_Quest_RestoreTreasureisland_Sub3_Name,
	        gText_Quest_RestoreTreasureisland_Sub3_Desc,
	        gText_Quest_RestoreTreasureisland_Sub3_Map,
	        SPECIES_BEHEEYEM,
	        PKMN,
            sText_Found
	),
	sub_quest(
	        230,
	        gText_Quest_RestoreTreasureisland_Sub4_Name,
	        gText_Quest_RestoreTreasureisland_Sub4_Desc,
	        gText_Quest_RestoreTreasureisland_Sub4_Map,
	        SPECIES_SHROOMISH,
	        PKMN,
            sText_Found
	),
};
static const struct SubQuest
    sRecruitLocalArtists_Sub[QUEST_RECRUITLOCALARTISTS_SUB_COUNT] = {
	sub_quest(
	        231,
            gText_Quest_Recruitlocalartists_Sub1_Name,
            gText_Quest_Recruitlocalartists_Sub1_Desc,
            gText_Quest_Recruitlocalartists_Sub1_Map,
	        SPECIES_SMEARGLE,
	        PKMN,
            sText_Caught
	),
	sub_quest(
	        232,
            gText_Quest_Recruitlocalartists_Sub2_Name,
            gText_Quest_Recruitlocalartists_Sub2_Desc,
            gText_Quest_Recruitlocalartists_Sub2_Map,
	        SPECIES_SMEARGLE,
	        PKMN,
            sText_Caught
	),
	sub_quest(
	        233,
            gText_Quest_Recruitlocalartists_Sub3_Name,
            gText_Quest_Recruitlocalartists_Sub3_Desc,
            gText_Quest_Recruitlocalartists_Sub3_Map,
	        SPECIES_SMEARGLE,
	        PKMN,
            sText_Caught
	),
};
static const struct SubQuest
	sBecomeChampion_Sub[QUEST_BECOMECHAMPION_SUB_COUNT] = {
	sub_quest(
	        234,
	        gText_Quest_BecomeChampion_Sub1_Name,
	        gText_Quest_BecomeChampion_Sub1_Desc,
	        gText_Quest_BecomeChampion_Sub1_Map,
            OBJ_EVENT_GFX_SIDNEY,
            OBJECT,
            sText_Defeated
	),
	sub_quest(
	        235,
	        gText_Quest_BecomeChampion_Sub2_Name,
	        gText_Quest_BecomeChampion_Sub2_Desc,
	        gText_Quest_BecomeChampion_Sub2_Map,
            OBJ_EVENT_GFX_GLACIA,
            OBJECT,
            sText_Defeated
	),
	sub_quest(
	        236,
	        gText_Quest_BecomeChampion_Sub3_Name,
	        gText_Quest_BecomeChampion_Sub3_Desc,
	        gText_Quest_BecomeChampion_Sub3_Map,
            OBJ_EVENT_GFX_DRAKE,
            OBJECT,
            sText_Defeated
	),
	sub_quest(
	        237,
	        gText_Quest_BecomeChampion_Sub4_Name,
	        gText_Quest_BecomeChampion_Sub4_Desc,
	        gText_Quest_BecomeChampion_Sub4_Map,
            OBJ_EVENT_GFX_PHOEBE,
            OBJECT,
            sText_Defeated
	),
};

static const struct SubQuest sSieboldsTraining_Sub[QUEST_RESTAURANTEXPANSION2_SUB_COUNT] = {
	sub_quest(
	        238,
	        gText_Quest_SieboldsTraining_Sub1_Name,
	        gText_Quest_SieboldsTraining_Sub1_Desc,
	        gText_Quest_SieboldsTraining_Sub1_Map,
	        OBJ_EVENT_GFX_LINK_RECEPTIONIST,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        239,
	        gText_Quest_SieboldsTraining_Sub2_Name,
	        gText_Quest_SieboldsTraining_Sub2_Desc,
	        gText_Quest_SieboldsTraining_Sub2_Map,
	        OBJ_EVENT_GFX_MAN_4,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        240,
	        gText_Quest_SieboldsTraining_Sub3_Name,
	        gText_Quest_SieboldsTraining_Sub3_Desc,
	        gText_Quest_SieboldsTraining_Sub3_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,
	        OBJECT,
	        sText_Recruited
	),
	sub_quest(
	        241,
	        gText_Quest_SieboldsTraining_Sub4_Name,
	        gText_Quest_SieboldsTraining_Sub4_Desc,
	        gText_Quest_SieboldsTraining_Sub4_Map,
	        OBJ_EVENT_GFX_TEALA,
	        OBJECT,
	        sText_Recruited
	),
};

////////////////////////END SUBQUEST CUSTOMIZATION/////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
////////////////////////BEGIN QUEST CUSTOMIZATION//////////////////////////////

//Declaration of side quest structures. Edits to quests are made here.
#define side_quest(n, d, dd, m, s, st, sq, ns) {.name = n, .desc = d, .donedesc = dd, .map = m, .sprite = s, .spritetype = st, .subquests = sq, .numSubquests = ns}
static const struct SideQuest sSideQuests[QUEST_COUNT] = {
	side_quest(
	        gText_Quest_PlayersAdventure_Name,
	        gText_Quest_PlayersAdventure_Desc,
	        gText_Quest_PlayersAdventure_DoneDesc,
	        gText_Quest_PlayersAdventure_Map,
	        OBJ_EVENT_GFX_BRENDAN_NORMAL,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ReturnDoll_Name,
	        gText_Quest_ReturnDoll_Desc,
	        gText_Quest_ReturnDoll_DoneDesc,
	        gText_Quest_ReturnDoll_Map,
	        OBJ_EVENT_GFX_LITTLE_GIRL,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BringFruit_Name,
	        gText_Quest_BringFruit_Desc,
	        gText_Quest_BringFruit_DoneDesc,
	        gText_Quest_BringFruit_Map,
	        OBJ_EVENT_GFX_POKEFAN_M,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BringFireType_Name,
	        gText_Quest_BringFireType_Desc,
	        gText_Quest_BringFireType_DoneDesc,
	        gText_Quest_BringFireType_Map,
	        OBJ_EVENT_GFX_MAN_1,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_StopMugging_Name,
	        gText_Quest_StopMugging_Desc,
	        gText_Quest_StopMugging_DoneDesc,
	        gText_Quest_StopMugging_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_StolenTrade_Name,
	        gText_Quest_StolenTrade_Desc,
	        gText_Quest_StolenTrade_DoneDesc,
	        gText_Quest_StolenTrade_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        NULL,
	        6
	),
	side_quest(
	        gText_Quest_HauntABuilding_Name,
	        gText_Quest_HauntABuilding_Desc,
	        gText_Quest_HauntABuilding_DoneDesc,
	        gText_Quest_HauntABuilding_Map,
	        OBJ_EVENT_GFX_GIRL_2,
	        OBJECT,
	        sHauntABuilding_Sub,
	        6
	),
	side_quest(
	        gText_Quest_RabiesOutbreak_Name,
	        gText_Quest_RabiesOutbreak_Desc,
	        gText_Quest_RabiesOutbreak_DoneDesc,
	        gText_Quest_RabiesOutbreak_Map,
	        SPECIES_GLAMEOW,
	        PKMN,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BlueRobbery_Name,
	        gText_Quest_BlueRobbery_Desc,
	        gText_Quest_BlueRobbery_DoneDesc,
	        gText_Quest_BlueRobbery_Map,
	        SPECIES_WOBBUFFET,
	        PKMN,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_IceCreamCrafting_Name,
	        gText_Quest_IceCreamCrafting_Desc,
	        gText_Quest_IceCreamCrafting_DoneDesc,
	        gText_Quest_IceCreamCrafting_Map,
	        ITEM_NANAB_BERRY,
	        ITEM,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_VSDeoxys_Name,
	        gText_Quest_VSDeoxys_Desc,
	        gText_Quest_VSDeoxys_DoneDesc,
	        gText_Quest_VSDeoxys_Map,
	        SPECIES_DEOXYS_SPEED,
	        PKMN,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ChinatownTunnels_Name,
	        gText_Quest_ChinatownTunnels_Desc,
	        gText_Quest_ChinatownTunnels_DoneDesc,
	        gText_Quest_ChinatownTunnels_Map,
	        OBJ_EVENT_GFX_OLD_MAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_FreshwaterEvolution_Name,
	        gText_Quest_FreshwaterEvolution_Desc,
	        gText_Quest_FreshwaterEvolution_DoneDesc,
	        gText_Quest_FreshwaterEvolution_Map,
	        SPECIES_OCTILLERY,
	        PKMN,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_GemArtist_Name,
	        gText_Quest_GemArtist_Desc,
	        gText_Quest_GemArtist_DoneDesc,
	        gText_Quest_GemArtist_Map,
	        ITEM_NORMAL_GEM,
	        ITEM,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BetweenAStoneAndAHardPlace_Name,
	        gText_Quest_BetweenAStoneAndAHardPlace_Desc,
	        gText_Quest_BetweenAStoneAndAHardPlace_DoneDesc,
	        gText_Quest_BetweenAStoneAndAHardPlace_Map,
	        ITEM_FIRE_STONE,
	        ITEM,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_RightingWrongs_Name,
	        gText_Quest_RightingWrongs_Desc,
	        gText_Quest_RightingWrongs_DoneDesc,
	        gText_Quest_RightingWrongs_Map,
	        OBJ_EVENT_GFX_BOY_1,
	        OBJECT,
	        sRightingWrongs_Sub,
	        4
	),
	side_quest(
	        gText_Quest_EnterTheDragon_Name,
	        gText_Quest_EnterTheDragon_Desc,
	        gText_Quest_EnterTheDragon_DoneDesc,
	        gText_Quest_EnterTheDragon_Map,
	        SPECIES_HITMONLEE,
	        PKMN,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BreakTheInternet_Name,
	        gText_Quest_BreakTheInternet_Desc,
	        gText_Quest_BreakTheInternet_DoneDesc,
	        gText_Quest_BreakTheInternet_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,
	        OBJECT,
	        sBreakTheInternet_Sub,
	        3
	),
	side_quest(
	        gText_Quest_ShutDownMedicineMan_Name,
	        gText_Quest_ShutDownMedicineMan_Desc,
	        gText_Quest_ShutDownMedicineMan_DoneDesc,
	        gText_Quest_ShutDownMedicineMan_Map,
	        OBJ_EVENT_GFX_RICH_BOY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BuildingScope_Name,
	        gText_Quest_BuildingScope_Desc,
	        gText_Quest_BuildingScope_DoneDesc,
	        gText_Quest_BuildingScope_Map,
	        OBJ_EVENT_GFX_MAGMA_MEMBER_M,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_NoGoodDeed_Name,
	        gText_Quest_NoGoodDeed_Desc,
	        gText_Quest_NoGoodDeed_DoneDesc,
	        gText_Quest_NoGoodDeed_Map,
	        OBJ_EVENT_GFX_MOM,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ImprovBattling_Name,
	        gText_Quest_ImprovBattling_Desc,
	        gText_Quest_ImprovBattling_DoneDesc,
	        gText_Quest_ImprovBattling_Map,
	        OBJ_EVENT_GFX_RICH_BOY,
	        OBJECT,
	        sImprovBattling_Sub,
	        4
	),
	side_quest(
	        gText_Quest_ImprovBattlingChampionship_Name,
	        gText_Quest_ImprovBattlingChampionship_Desc,
	        gText_Quest_ImprovBattlingChampionship_DoneDesc,
	        gText_Quest_ImprovBattlingChampionship_Map,
	        OBJ_EVENT_GFX_RICH_BOY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_InstallNatureProbes_Name,
	        gText_Quest_InstallNatureProbes_Desc,
	        gText_Quest_InstallNatureProbes_DoneDesc,
	        gText_Quest_InstallNatureProbes_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        sInstallNatureProbes_Sub,
	        3
	),
	side_quest(
	        gText_Quest_ManOfManyHats_Name,
	        gText_Quest_ManOfManyHats_Desc,
	        gText_Quest_ManOfManyHats_DoneDesc,
	        gText_Quest_ManOfManyHats_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_RecruitLocalArtists_Name,
	        gText_Quest_RecruitLocalArtists_Desc,
	        gText_Quest_RecruitLocalArtists_DoneDesc,
	        gText_Quest_RecruitLocalArtists_Map,
	        OBJ_EVENT_GFX_MAGMA_MEMBER_F,
	        OBJECT,
            sRecruitLocalArtists_Sub,
	        3
	),
	side_quest(
	        gText_Quest_RestaurantExpansion1_Name,
	        gText_Quest_RestaurantExpansion1_Desc,
	        gText_Quest_RestaurantExpansion1_DoneDesc,
	        gText_Quest_RestaurantExpansion1_Map,
	        OBJ_EVENT_GFX_ROXANNE,
	        OBJECT,
	        sRestaurantExpansion1_Sub,
	        4
	),
	side_quest(
	        gText_Quest_RestaurantExpansion2_Name,
	        gText_Quest_RestaurantExpansion2_Desc,
	        gText_Quest_RestaurantExpansion2_DoneDesc,
	        gText_Quest_RestaurantExpansion2_Map,
	        OBJ_EVENT_GFX_ROXANNE,
	        OBJECT,
	        sRestaurantExpansion2_Sub,
	        5
	),
	side_quest(
	        gText_Quest_SieboldsTraining_Name,
	        gText_Quest_SieboldsTraining_Desc,
	        gText_Quest_SieboldsTraining_DoneDesc,
	        gText_Quest_SieboldsTraining_Map,
	        OBJ_EVENT_GFX_GLACIA,
	        OBJECT,
	        sSieboldsTraining_Sub,
	        4
	),
	side_quest(
	        gText_Quest_CulturalPurity_Name,
	        gText_Quest_CulturalPurity_Desc,
	        gText_Quest_CulturalPurity_DoneDesc,
	        gText_Quest_CulturalPurity_Map,
	        OBJ_EVENT_GFX_BRAWLY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_HybridCulture_Name,
	        gText_Quest_HybridCulture_Desc,
	        gText_Quest_HybridCulture_DoneDesc,
	        gText_Quest_HybridCulture_Map,
	        OBJ_EVENT_GFX_BRAWLY,
	        OBJECT,
	        sHybridCulture_Sub,
	        3
	),
	side_quest(
	        gText_Quest_AlohaFromAlola_Name,
	        gText_Quest_AlohaFromAlola_Desc,
	        gText_Quest_AlohaFromAlola_DoneDesc,
	        gText_Quest_AlohaFromAlola_Map,
	        OBJ_EVENT_GFX_WATTSON,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BuildingAnExhibit_Name,
	        gText_Quest_BuildingAnExhibit_Desc,
	        gText_Quest_BuildingAnExhibit_DoneDesc,
	        gText_Quest_BuildingAnExhibit_Map,
	        OBJ_EVENT_GFX_WATTSON,
	        OBJECT,
	        sBuildingAnExhibit_Sub,
	        4
	),
	side_quest(
	        gText_Quest_UnknownMortyQuestA_Name,
	        gText_Quest_UnknownMortyQuestA_Desc,
	        gText_Quest_UnknownMortyQuestA_DoneDesc,
	        gText_Quest_UnknownMortyQuestA_Map,
	        OBJ_EVENT_GFX_FLANNERY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownMortyQuestB_Name,
	        gText_Quest_UnknownMortyQuestB_Desc,
	        gText_Quest_UnknownMortyQuestB_DoneDesc,
	        gText_Quest_UnknownMortyQuestB_Map,
	        OBJ_EVENT_GFX_FLANNERY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_StealTheAxe_Name,
	        gText_Quest_StealTheAxe_Desc,
	        gText_Quest_StealTheAxe_DoneDesc,
	        gText_Quest_StealTheAxe_Map,
	        OBJ_EVENT_GFX_NORMAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownChuckQuestB_Name,
	        gText_Quest_UnknownChuckQuestB_Desc,
	        gText_Quest_UnknownChuckQuestB_DoneDesc,
	        gText_Quest_UnknownChuckQuestB_Map,
	        OBJ_EVENT_GFX_NORMAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BiomeResearch_Name,
	        gText_Quest_BiomeResearch_Desc,
	        gText_Quest_BiomeResearch_DoneDesc,
	        gText_Quest_BiomeResearch_Map,
	        OBJ_EVENT_GFX_WINONA,
	        OBJECT,
	        sBiomeResearch_Sub,
	        8
	),
	side_quest(
	        gText_Quest_BerrySustainability_Name,
	        gText_Quest_BerrySustainability_Desc,
	        gText_Quest_BerrySustainability_DoneDesc,
	        gText_Quest_BerrySustainability_Map,
	        OBJ_EVENT_GFX_WINONA,
	        OBJECT,
	        sBerrySustainability_Sub,
	        6
	),
	side_quest(
	        gText_Quest_TheOnlyHeadShopInTown_Name,
	        gText_Quest_TheOnlyHeadShopInTown_Desc,
	        gText_Quest_TheOnlyHeadShopInTown_DoneDesc,
	        gText_Quest_TheOnlyHeadShopInTown_Map,
	        OBJ_EVENT_GFX_TATE,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_InverseHallucinogenic_Name,
	        gText_Quest_InverseHallucinogenic_Desc,
	        gText_Quest_InverseHallucinogenic_DoneDesc,
	        gText_Quest_InverseHallucinogenic_Map,
	        OBJ_EVENT_GFX_TATE,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownClairQuestA_Name,
	        gText_Quest_UnknownClairQuestA_Desc,
	        gText_Quest_UnknownClairQuestA_DoneDesc,
	        gText_Quest_UnknownClairQuestA_Map,
	        OBJ_EVENT_GFX_JUAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownClairQuestB_Name,
	        gText_Quest_UnknownClairQuestB_Desc,
	        gText_Quest_UnknownClairQuestB_DoneDesc,
	        gText_Quest_UnknownClairQuestB_Map,
	        OBJ_EVENT_GFX_JUAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ContractorPorygon_Name,
	        gText_Quest_ContractorPorygon_Desc,
	        gText_Quest_ContractorPorygon_DoneDesc,
	        gText_Quest_ContractorPorygon_Map,
	        OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F,
	        OBJECT,
	        sContractorPorygon_Sub,
	        3
	),
	side_quest(
	        gText_Quest_AngelDelivery_Name,
	        gText_Quest_AngelDelivery_Desc,
	        gText_Quest_AngelDelivery_DoneDesc,
	        gText_Quest_AngelDelivery_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_GetTheBandBackTogether_Name,
	        gText_Quest_GetTheBandBackTogether_Desc,
	        gText_Quest_GetTheBandBackTogether_DoneDesc,
	        gText_Quest_GetTheBandBackTogether_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_M,
	        OBJECT,
	        sGetTheBandBackTogether_Sub,
	        5
	),
	side_quest(
	        gText_Quest_FoodTruckBureacracy_Name,
	        gText_Quest_FoodTruckBureacracy_Desc,
	        gText_Quest_FoodTruckBureacracy_DoneDesc,
	        gText_Quest_FoodTruckBureacracy_Map,
	        OBJ_EVENT_GFX_YOUNGSTER,
	        OBJECT,
	        sFoodTruckBureacracy_Sub,
	        4
	),
	side_quest(
	        gText_Quest_DetectiveAriana_Name,
	        gText_Quest_DetectiveAriana_Desc,
	        gText_Quest_DetectiveAriana_DoneDesc,
	        gText_Quest_DetectiveAriana_Map,
	        OBJ_EVENT_GFX_MAGMA_MEMBER_F,
	        OBJECT,
	        sDetectiveAriana_Sub,
	        3
	),
	side_quest(
	        gText_Quest_UnknownBruceLeeQuest_Name,
	        gText_Quest_UnknownBruceLeeQuest_Desc,
	        gText_Quest_UnknownBruceLeeQuest_DoneDesc,
	        gText_Quest_UnknownBruceLeeQuest_Map,
	        OBJ_EVENT_GFX_BLACK_BELT,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ChallengeOfThe7Sisters_Name,
	        gText_Quest_ChallengeOfThe7Sisters_Desc,
	        gText_Quest_ChallengeOfThe7Sisters_DoneDesc,
	        gText_Quest_ChallengeOfThe7Sisters_Map,
	        OBJ_EVENT_GFX_HEX_MANIAC,
	        OBJECT,
	        sChallengeOfThe7Sisters_Sub,
	        7
	),
	side_quest(
	        gText_Quest_Esports_Name,
	        gText_Quest_Esports_Desc,
	        gText_Quest_Esports_DoneDesc,
	        gText_Quest_Esports_Map,
	        OBJ_EVENT_GFX_BOY_2,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_CutePokemon_Name,
	        gText_Quest_CutePokemon_Desc,
	        gText_Quest_CutePokemon_DoneDesc,
	        gText_Quest_CutePokemon_Map,
	        OBJ_EVENT_GFX_WOMAN_5,
	        OBJECT,
	        sCutePokemon_Sub,
	        4
	),
	side_quest(
	        gText_Quest_WallaceArmy_Name,
	        gText_Quest_WallaceArmy_Desc,
	        gText_Quest_WallaceArmy_DoneDesc,
	        gText_Quest_WallaceArmy_Map,
	        OBJ_EVENT_GFX_SAILOR,
	        OBJECT,
	        sWallaceArmy_Sub,
	        5
	),
	side_quest(
	        gText_Quest_DexCompletion_Name,
	        gText_Quest_DexCompletion_Desc,
	        gText_Quest_DexCompletion_DoneDesc,
	        gText_Quest_DexCompletion_Map,
	        OBJ_EVENT_GFX_SCIENTIST_2,
	        OBJECT,
	        sDexCompletion_Sub,
	        2
	),
	side_quest(
	        gText_Quest_CableCarDancing_Name,
	        gText_Quest_CableCarDancing_Desc,
	        gText_Quest_CableCarDancing_DoneDesc,
	        gText_Quest_CableCarDancing_Map,
	        OBJ_EVENT_GFX_COOK,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_KitchenVolunteering_Name,
	        gText_Quest_KitchenVolunteering_Desc,
	        gText_Quest_KitchenVolunteering_DoneDesc,
	        gText_Quest_KitchenVolunteering_Map,
	        OBJ_EVENT_GFX_SCIENTIST_1,
	        OBJECT,
	        sKitchenVolunteering_Sub,
	        5
	),
	side_quest(
	        gText_Quest_ArtisanBalls1_Name,
	        gText_Quest_ArtisanBalls1_Desc,
	        gText_Quest_ArtisanBalls1_DoneDesc,
	        gText_Quest_ArtisanBalls1_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,
	        OBJECT,
	        sArtisanBalls_Sub,
	        7
	),
	side_quest(
	        gText_Quest_ArtisanBalls2_Name,
	        gText_Quest_ArtisanBalls2_Desc,
	        gText_Quest_ArtisanBalls2_DoneDesc,
	        gText_Quest_ArtisanBalls2_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,
	        OBJECT,
	        sArtisanBalls2_Sub,
	        3
	),
	side_quest(
	        gText_Quest_ArtisanBalls3_Name,
	        gText_Quest_ArtisanBalls3_Desc,
	        gText_Quest_ArtisanBalls3_DoneDesc,
	        gText_Quest_ArtisanBalls3_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ShelterSwitcheroo_Name,
	        gText_Quest_ShelterSwitcheroo_Desc,
	        gText_Quest_ShelterSwitcheroo_DoneDesc,
	        gText_Quest_ShelterSwitcheroo_Map,
	        OBJ_EVENT_GFX_FAT_MAN,
	        OBJECT,
	        sShelterSwitcheroo_Sub,
	        5
	),
	side_quest(
	        gText_Quest_ShelterTaxiSolution_Name,
	        gText_Quest_ShelterTaxiSolution_Desc,
	        gText_Quest_ShelterTaxiSolution_DoneDesc,
	        gText_Quest_ShelterTaxiSolution_Map,
	        OBJ_EVENT_GFX_FAT_MAN,
	        OBJECT,
	        sShelterTaxiSolution_Sub,
	        5
	),
	side_quest(
	        gText_Quest_LastMusicVenueInSanFrancisco_Name,
	        gText_Quest_LastMusicVenueInSanFrancisco_Desc,
	        gText_Quest_LastMusicVenueInSanFrancisco_DoneDesc,
	        gText_Quest_LastMusicVenueInSanFrancisco_Map,
	        OBJ_EVENT_GFX_YOUNGSTER,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_GardenCleanup_Name,
	        gText_Quest_GardenCleanup_Desc,
	        gText_Quest_GardenCleanup_DoneDesc,
	        gText_Quest_GardenCleanup_Map,
	        OBJ_EVENT_GFX_SCHOOL_KID_M,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_GardenCleanupAdvanced_Name,
	        gText_Quest_GardenCleanupAdvanced_Desc,
	        gText_Quest_GardenCleanupAdvanced_DoneDesc,
	        gText_Quest_GardenCleanupAdvanced_Map,
	        OBJ_EVENT_GFX_SCHOOL_KID_M,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_EmployedEverAfter_Name,
	        gText_Quest_EmployedEverAfter_Desc,
	        gText_Quest_EmployedEverAfter_DoneDesc,
	        gText_Quest_EmployedEverAfter_Map,
	        OBJ_EVENT_GFX_BEAUTY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_ButOnlyInMyBackyard_Name,
	        gText_Quest_ButOnlyInMyBackyard_Desc,
	        gText_Quest_ButOnlyInMyBackyard_DoneDesc,
	        gText_Quest_ButOnlyInMyBackyard_Map,
	        OBJ_EVENT_GFX_WOMAN_3,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_NeighborhoodCleanUp_Name,
	        gText_Quest_NeighborhoodCleanUp_Desc,
	        gText_Quest_NeighborhoodCleanUp_DoneDesc,
	        gText_Quest_NeighborhoodCleanUp_Map,
	        OBJ_EVENT_GFX_POKEFAN_M,
	        OBJECT,
	        sNeighborhoodCleanUp_Sub,
	        5
	),
	side_quest(
	        gText_Quest_NeighborhoodCleanUp2_Name,
	        gText_Quest_NeighborhoodCleanUp2_Desc,
	        gText_Quest_NeighborhoodCleanUp2_DoneDesc,
	        gText_Quest_NeighborhoodCleanUp2_Map,
	        OBJ_EVENT_GFX_POKEFAN_M,
	        OBJECT,
	        sNeighborhoodCleanUp2_Sub,
	        4
	),
	side_quest(
	        gText_Quest_NeighborhoodCleanUp3_Name,
	        gText_Quest_NeighborhoodCleanUp3_Desc,
	        gText_Quest_NeighborhoodCleanUp3_DoneDesc,
	        gText_Quest_NeighborhoodCleanUp3_Map,
	        OBJ_EVENT_GFX_POKEFAN_M,
	        OBJECT,
	        sNeighborhoodCleanUp3_Sub,
	        3
	),
	side_quest(
	        gText_Quest_NeighborhoodCleanUp4_Name,
	        gText_Quest_NeighborhoodCleanUp4_Desc,
	        gText_Quest_NeighborhoodCleanUp4_DoneDesc,
	        gText_Quest_NeighborhoodCleanUp4_Map,
	        OBJ_EVENT_GFX_WOMAN_4,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_RockCollector_Name,
	        gText_Quest_RockCollector_Desc,
	        gText_Quest_RockCollector_DoneDesc,
	        gText_Quest_RockCollector_Map,
	        OBJ_EVENT_GFX_COOK,
	        OBJECT,
	        sRockCollector_Sub,
	        10
	),
	side_quest(
	        gText_Quest_Hang20_Name,
	        gText_Quest_Hang20_Desc,
	        gText_Quest_Hang20_DoneDesc,
	        gText_Quest_Hang20_Map,
	        OBJ_EVENT_GFX_SWIMMER_M,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_AllThatGlittersMightBeGold_Name,
	        gText_Quest_AllThatGlittersMightBeGold_Desc,
	        gText_Quest_AllThatGlittersMightBeGold_DoneDesc,
	        gText_Quest_AllThatGlittersMightBeGold_Map,
	        OBJ_EVENT_GFX_FISHERMAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownFishingQuest_Name,
	        gText_Quest_UnknownFishingQuest_Desc,
	        gText_Quest_UnknownFishingQuest_DoneDesc,
	        gText_Quest_UnknownFishingQuest_Map,
	        OBJ_EVENT_GFX_FISHERMAN,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_HiddenGrottoMapping_Name,
	        gText_Quest_HiddenGrottoMapping_Desc,
	        gText_Quest_HiddenGrottoMapping_DoneDesc,
	        gText_Quest_HiddenGrottoMapping_Map,
	        OBJ_EVENT_GFX_CAMPER,
	        OBJECT,
	        sHiddenGrottoMapping_Sub,
	        5
	),
	side_quest(
	        gText_Quest_HiddenGrottoMapping2_Name,
	        gText_Quest_HiddenGrottoMapping2_Desc,
	        gText_Quest_HiddenGrottoMapping2_DoneDesc,
	        gText_Quest_HiddenGrottoMapping2_Map,
	        OBJ_EVENT_GFX_TWIN,
	        OBJECT,
	        sHiddenGrottoMapping2_Sub,
	        3
	),
	side_quest(
	        gText_Quest_UltraWormholeResearch_Name,
	        gText_Quest_UltraWormholeResearch_Desc,
	        gText_Quest_UltraWormholeResearch_DoneDesc,
	        gText_Quest_UltraWormholeResearch_Map,
	        OBJ_EVENT_GFX_OLD_MAN,
	        OBJECT,
	        sUltraWormholeResearch_Sub,
	        10
	),
	side_quest(
	        gText_Quest_UnknownGovernmentSocialMediaQuest_Name,
	        gText_Quest_UnknownGovernmentSocialMediaQuest_Desc,
	        gText_Quest_UnknownGovernmentSocialMediaQuest_DoneDesc,
	        gText_Quest_UnknownGovernmentSocialMediaQuest_Map,
	        ITEM_FAME_CHECKER,
	        ITEM,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_DrumCircle_Name,
	        gText_Quest_DrumCircle_Desc,
	        gText_Quest_DrumCircle_DoneDesc,
	        gText_Quest_DrumCircle_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownProp22Quest_Name,
	        gText_Quest_UnknownProp22Quest_Desc,
	        gText_Quest_UnknownProp22Quest_DoneDesc,
	        gText_Quest_UnknownProp22Quest_Map,
	        OBJ_EVENT_GFX_NINJA_BOY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownTimeTravelQuest_Name,
	        gText_Quest_UnknownTimeTravelQuest_Desc,
	        gText_Quest_UnknownTimeTravelQuest_DoneDesc,
	        gText_Quest_UnknownTimeTravelQuest_Map,
	        OBJ_EVENT_GFX_RIVAL_BRENDAN_NORMAL,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownConstructionStrikeQuest_Name,
	        gText_Quest_UnknownConstructionStrikeQuest_Desc,
	        gText_Quest_UnknownConstructionStrikeQuest_DoneDesc,
	        gText_Quest_UnknownConstructionStrikeQuest_Map,
	        OBJ_EVENT_GFX_BOY_2,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_IBelieveICanFly_Name,
	        gText_Quest_IBelieveICanFly_Desc,
	        gText_Quest_IBelieveICanFly_DoneDesc,
	        gText_Quest_IBelieveICanFly_Map,
	        OBJ_EVENT_GFX_BEAUTY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_WildfireRisk_Name,
	        gText_Quest_WildfireRisk_Desc,
	        gText_Quest_WildfireRisk_DoneDesc,
	        gText_Quest_WildfireRisk_Map,
	        OBJ_EVENT_GFX_ARTIST,
	        OBJECT,
	        sWildfireRisk_Sub,
	        3
	),
	side_quest(
	        gText_Quest_TheBoyWhoCriesWithWolves_Name,
	        gText_Quest_TheBoyWhoCriesWithWolves_Desc,
	        gText_Quest_TheBoyWhoCriesWithWolves_DoneDesc,
	        gText_Quest_TheBoyWhoCriesWithWolves_Map,
	        OBJ_EVENT_GFX_GENTLEMAN,
	        OBJECT,
	        sTheBoyWhoCriesWithWolves_Sub,
	        9
	),
	side_quest(
	        gText_Quest_UnknownTrolleyProblem_Name,
	        gText_Quest_UnknownTrolleyProblem_Desc,
	        gText_Quest_UnknownTrolleyProblem_DoneDesc,
	        gText_Quest_UnknownTrolleyProblem_Map,
	        OBJ_EVENT_GFX_CYCLING_TRIATHLETE_F,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_UnknownLandfillQuest_Name,
	        gText_Quest_UnknownLandfillQuest_Desc,
	        gText_Quest_UnknownLandfillQuest_DoneDesc,
	        gText_Quest_UnknownLandfillQuest_Map,
	        OBJ_EVENT_GFX_NINJA_BOY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_TaxicabTurnaroundSea_Name,
	        gText_Quest_TaxicabTurnaroundSea_Desc,
	        gText_Quest_TaxicabTurnaroundSea_DoneDesc,
	        gText_Quest_TaxicabTurnaroundSea_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        sTaxicabTurnAroundSea_Sub,
	        5
	),
	side_quest(
	        gText_Quest_TaxicabTurnaroundAir_Name,
	        gText_Quest_TaxicabTurnaroundAir_Desc,
	        gText_Quest_TaxicabTurnaroundAir_DoneDesc,
	        gText_Quest_TaxicabTurnaroundAir_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        sTaxicabTurnAroundAir_Sub,
	        5
	),
	side_quest(
	        gText_Quest_TaxicabTurnaroundLand_Name,
	        gText_Quest_TaxicabTurnaroundLand_Desc,
	        gText_Quest_TaxicabTurnaroundLand_DoneDesc,
	        gText_Quest_TaxicabTurnaroundLand_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        sTaxicabTurnAroundLand_Sub,
	        7
	),
	side_quest(
	        gText_Quest_PersuasivePassenger_Name,
	        gText_Quest_PersuasivePassenger_Desc,
	        gText_Quest_PersuasivePassenger_DoneDesc,
	        gText_Quest_PersuasivePassenger_Map,
	        OBJ_EVENT_GFX_GIRL_3,
	        OBJECT,
	        sPersuasivePassenger_Sub,
	        3
	),
	side_quest(
	        gText_Quest_BodegaBurnout_Name,
	        gText_Quest_BodegaBurnout_Desc,
	        gText_Quest_BodegaBurnout_DoneDesc,
	        gText_Quest_BodegaBurnout_Map,
	        OBJ_EVENT_GFX_TWIN,
	        OBJECT,
	        sBodegaBurnout_Sub,
	        17
	),
	side_quest(
	        gText_Quest_WarehouseWarfare_Name,
	        gText_Quest_WarehouseWarfare_Desc,
	        gText_Quest_WarehouseWarfare_DoneDesc,
	        gText_Quest_WarehouseWarfare_Map,
	        OBJ_EVENT_GFX_GENTLEMAN,
	        OBJECT,
	        sWarehouseWarfare_Sub,
	        3
	),
	side_quest(
	        gText_Quest_RestoreToTheirFormerGlory_Name,
	        gText_Quest_RestoreToTheirFormerGlory_Desc,
	        gText_Quest_RestoreToTheirFormerGlory_DoneDesc,
	        gText_Quest_RestoreToTheirFormerGlory_Map,
	        OBJ_EVENT_GFX_WALLY,
	        OBJECT,
	        sRestoreToTheirFormerGlory_Sub,
	        4
	),
	side_quest(
	        gText_Quest_HowDisappointing_Name,
	        gText_Quest_HowDisappointing_Desc,
	        gText_Quest_HowDisappointing_DoneDesc,
	        gText_Quest_HowDisappointing_Map,
	        OBJ_EVENT_GFX_AQUA_MEMBER_F,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_LetsBurnThisMotherDown_Name,
	        gText_Quest_LetsBurnThisMotherDown_Desc,
	        gText_Quest_LetsBurnThisMotherDown_DoneDesc,
	        gText_Quest_LetsBurnThisMotherDown_Map,
	        OBJ_EVENT_GFX_WALLY,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_Manhunt_Name,
	        gText_Quest_Manhunt_Desc,
	        gText_Quest_Manhunt_DoneDesc,
	        gText_Quest_Manhunt_Map,
	        OBJ_EVENT_GFX_ARCHIE,
	        OBJECT,
	        NULL,
	        0
	),

	side_quest(
	        gText_Quest_RestoreChinatown_Name,
	        gText_Quest_RestoreChinatown_Desc,
	        gText_Quest_RestoreChinatown_DoneDesc,
	        gText_Quest_RestoreChinatown_Map,
	        OBJ_EVENT_GFX_BLACK_BELT,
	        OBJECT,
            sRestoreChinatown_Sub,
	        7
	),

	side_quest(
	        gText_Quest_RestoreMarin_Name,
	        gText_Quest_RestoreMarin_Desc,
	        gText_Quest_RestoreMarin_DoneDesc,
	        gText_Quest_RestoreMarin_Map,
	        OBJ_EVENT_GFX_NOLAND,
	        OBJECT,
            sRestoreMarin_Sub,
	        2
	),

	side_quest(
	        gText_Quest_RestoreTreasureisland_Name,
	        gText_Quest_RestoreTreasureisland_Desc,
	        gText_Quest_RestoreTreasureisland_DoneDesc,
	        gText_Quest_RestoreTreasureisland_Map,
	        OBJ_EVENT_GFX_LUCY,
	        OBJECT,
	        sRestoreTreasureisland_Sub,
	        4
	),

	side_quest(
	        gText_Quest_RestoreHaightashbury_Name,
	        gText_Quest_RestoreHaightashbury_Desc,
	        gText_Quest_RestoreHaightashbury_DoneDesc,
            gText_Quest_RestoreHaightashbury_Map,
	        OBJ_EVENT_GFX_MAN_3,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_RedoMugging_Name,
	        gText_Quest_RedoMugging_Desc,
	        gText_Quest_RedoMugging_DoneDesc,
	        gText_Quest_RedoMugging_Map,
	        OBJ_EVENT_GFX_HIKER,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_PandaPride_Name,
	        gText_Quest_PandaPride_Desc,
	        gText_Quest_PandaPride_DoneDesc,
	        gText_Quest_PandaPride_Map,
	        OBJ_EVENT_GFX_MART_EMPLOYEE,
	        OBJECT,
	        NULL,
	        0
	),
	side_quest(
	        gText_Quest_BecomeChampion_Name,
	        gText_Quest_BecomeChampion_Desc,
	        gText_Quest_BecomeChampion_DoneDesc,
	        gText_Quest_BecomeChampion_Map,
	        OBJ_EVENT_GFX_PHOEBE,
	        OBJECT,
            sBecomeChampion_Sub,
	        4
	),
	side_quest(
	        gText_Quest_Dancebattle_Name,
	        gText_Quest_Dancebattle_Desc,
	        gText_Quest_Dancebattle_DoneDesc,
	        gText_Quest_Dancebattle_Map,
	        OBJ_EVENT_GFX_PHOEBE,
	        OBJECT,
            NULL,
	        0
	)
};
////////////////////////END QUEST CUSTOMIZATION////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

//BG layer defintions
static const struct BgTemplate sQuestMenuBgTemplates[2] = {
	{
		//All text and content is loaded to this window
		.bg = 0,
		.charBaseIndex = 0,
		.mapBaseIndex = 31,
		.priority = 1
	},
	{
		///Backgrounds and UI elements are loaded to this window
		.bg = 1,
		.charBaseIndex = 3,
		.mapBaseIndex = 30,
		.priority = 2
	}
};

//Window definitions
static const struct WindowTemplate sQuestMenuHeaderWindowTemplates[] = {
	{
		//0: Content window
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 2,
		.width = 30,
		.height = 8,
		.paletteNum = 15,
		.baseBlock = 1
	},
	{
		//1: Footer window
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 12,
		.width = 30,
		.height = 12,
		.paletteNum = 15,
		.baseBlock = 361
	},
	{
		// 2: Header window
		.bg = 0,
		.tilemapLeft = 0,
		.tilemapTop = 0,
		.width = 30,
		.height = 2,
		.paletteNum = 15,
		.baseBlock = 721
	},
	DUMMY_WIN_TEMPLATE
};

//Font color combinations for printed text
static const u8 sQuestMenuWindowFontColors[][4] = {
	{
		//Header of Quest Menu
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_DARK_GRAY,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Reward state progress indicator
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_RED,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Done state progress indicator
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_GREEN,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Active state progress indicator
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_BLUE,
		TEXT_COLOR_TRANSPARENT
	},
	{
		//Footer flavor text
		TEXT_COLOR_TRANSPARENT,
		TEXT_COLOR_WHITE,
		TEXT_COLOR_TRANSPARENT
	},
};

//Functions begin here

//ported from firered by ghoulslash
void QuestMenu_Init(u8 a0, MainCallback callback)
{
	u8 i;
    DebugPrintf("i = %d. But also a = 0x%x", i, i);

	if (a0 >= 2) {
		SetMainCallback2(callback);
		return;
	}

	if ((sStateDataPtr = Alloc(sizeof(struct QuestMenuResources))) == NULL) {
		SetMainCallback2(callback);
		return;
	}

	if (a0 != 1) {
		sListMenuState.savedCallback = callback;
		sListMenuState.scroll = sListMenuState.row = 0;
	}

	sStateDataPtr->moveModeOrigPos = 0xFF;
	sStateDataPtr->spriteIconSlot = 0;
	sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
	sStateDataPtr->savedCallback = 0;
	for (i = 0; i < 3; i++) {
		sStateDataPtr->data[i] = 0;
	}

	SetMainCallback2(RunSetup);
}

static void MainCB(void)
{
	RunTasks();
	AnimateSprites();
	BuildOamBuffer();
	DoScheduledBgTilemapCopiesToVram();
	UpdatePaletteFade();
}

static void VBlankCB(void)
{
	LoadOam();
	ProcessSpriteCopyRequests();
	TransferPlttBuffer();
}

static void RunSetup(void)
{
	while (1) {
		if (SetupGraphics() == TRUE) {
			break;
		}
	}
}

static bool8 SetupGraphics(void)
{
	u8 taskId;
	switch (gMain.state) {
		case 0:
			SetVBlankHBlankCallbacksToNull();
			ClearScheduledBgCopiesToVram();
			gMain.state++;
			break;
		case 1:
			ScanlineEffect_Stop();
			gMain.state++;
			break;
		case 2:
			FreeAllSpritePalettes();
			gMain.state++;
			break;
		case 3:
			ResetPaletteFade();
			gMain.state++;
			break;
		case 4:
			ResetSpriteData();
			gMain.state++;
			break;
		case 5:
			ResetSpriteState();
			gMain.state++;
			break;
		case 6:
			ResetTasks();
			gMain.state++;
			break;
		case 7:
			if (InitBackgrounds()) {
				sStateDataPtr->data[0] = 0;
				gMain.state++;
			} else {
				FadeAndBail();
				return TRUE;
			}
			break;
		case 8:
			if (LoadGraphics() == TRUE) {
				gMain.state++;
			}
			break;
		case 9:
			QuestMenu_InitWindows();
			gMain.state++;
			break;
		case 10:
			ClearModeOnStartup();
			InitItems();
			SetCursorPosition();
			SetScrollPosition();
			gMain.state++;
			break;
		case 11:
			if (AllocateResourcesForListMenu()) {
				gMain.state++;
			} else {
				FadeAndBail();
				return TRUE;
			}
			break;
		case 12:
			AllocateMemoryForArray();
			BuildMenuTemplate();
			gMain.state++;
			break;
		case 13:
			GenerateAndPrintHeader();
			gMain.state++;
			break;
		case 14:
			SetInitalLoadTrue();
			gMain.state++;
			break;
		case 15:
			taskId = CreateTask(Task_Main, 0);
			gTasks[taskId].data[0] = ListMenuInit(&gMultiuseListMenuTemplate,
			                                      sListMenuState.scroll,
			                                      sListMenuState.row);
			gMain.state++;
			break;
		case 16:
			PlaceTopMenuScrollIndicatorArrows();
			gMain.state++;
			break;
		case 17:
			gMain.state++;
			break;
		case 18:
			if (sListMenuState.initialized == 1) {
				BlendPalettes(0xFFFFFFFF, 16, RGB_BLACK);
			}
			gMain.state++;
			break;
		case 19:
			if (sListMenuState.initialized == 1) {
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
			} else {
				BeginNormalPaletteFade(0xFFFFFFFF, 0, 16, 0, RGB_BLACK);
				SetInitializedFlag(1);
			}
			gMain.state++;
			break;
		default:
			SetVBlankCallback(VBlankCB);
			SetMainCallback2(MainCB);
			return TRUE;
	}
	return FALSE;
}

static bool8 LoadGraphics(void)
{
	switch (sStateDataPtr->data[0]) {
		case 0:
			ResetTempTileDataBuffers();
			DecompressAndCopyTileDataToVram(1, sQuestMenuTiles, 0, 0, 0);
			sStateDataPtr->data[0]++;
			break;
		case 1:
			if (FreeTempTileDataBuffersIfPossible() != TRUE) {
				LZDecompressWram(sQuestMenuTilemap, sBg1TilemapBuffer);
				sStateDataPtr->data[0]++;
			}
			break;
		case 2:
			LoadCompressedPalette(sQuestMenuBgPals, 0x00, 0x60);
			sStateDataPtr->data[0]++;
			break;
		case 3:
			sStateDataPtr->data[0]++;
			break;
		default:
			sStateDataPtr->data[0] = 0;
			return TRUE;
	}
	return FALSE;
}

static void QuestMenu_InitWindows(void)
{
	u8 i;

	InitWindows(sQuestMenuHeaderWindowTemplates);
	DeactivateAllTextPrinters();

	for (i = 0; i < 3; i++) {
		FillWindowPixelBuffer(i, 0x00);
		PutWindowTilemap(i);
	}

	ScheduleBgCopyTilemapToVram(0);
}

static bool8 InitBackgrounds(void)
{
	ResetAllBgsCoordinatesAndBgCntRegs();
	sBg1TilemapBuffer = Alloc(0x800);
	if (sBg1TilemapBuffer == NULL) {
		return FALSE;
	}

	memset(sBg1TilemapBuffer, 0, 0x800);
	ResetBgsAndClearDma3BusyFlags(0);
	InitBgsFromTemplates(0, sQuestMenuBgTemplates,
	                     NELEMS(sQuestMenuBgTemplates));
	SetBgTilemapBuffer(1, sBg1TilemapBuffer);
	ScheduleBgCopyTilemapToVram(1);
	SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
	SetGpuReg(REG_OFFSET_BLDCNT, 0);
	ShowBg(0);
	ShowBg(1);
	return TRUE;
}

static void InitItems(void)
{
	sStateDataPtr->nItems = (CountNumberListRows()) - 1;

	sStateDataPtr->maxShowed = sStateDataPtr->nItems + 1 <= 4 ?
	                           sStateDataPtr->nItems + 1 : 4;
}

#define try_alloc(ptr__, size) ({ \
		void ** ptr = (void **)&(ptr__);             \
		*ptr = Alloc(size);                 \
		if (*ptr == NULL)                   \
		{                                   \
			FreeResources();                  \
			FadeAndBail();                  \
			return FALSE;                   \
		}                                   \
	})

static bool8 AllocateResourcesForListMenu(void)
{
	try_alloc(sListMenuItems,
	          sizeof(struct ListMenuItem) * CountNumberListRows() + 1);
	return TRUE;
}

void AllocateMemoryForArray(void)
{
	u8 i;
	u8 allocateRows = QUEST_ARRAY_COUNT + 1;

	questNameArray = Alloc(sizeof(void *) * allocateRows);

	for (i = 0; i < allocateRows; i++) {
		questNameArray[i] = Alloc(sizeof(u8) * 32);
	}
}

static void PlaceTopMenuScrollIndicatorArrows(void)
{
	u8 listSize = CountNumberListRows();

	if (listSize < sStateDataPtr->maxShowed) {
		listSize = sStateDataPtr->maxShowed;
	}

	sStateDataPtr->scrollIndicatorArrowPairId =
	        AddScrollIndicatorArrowPairParameterized(2, 94, 8, 90,
	                        (listSize - sStateDataPtr->maxShowed), 110, 110, &sListMenuState.scroll);
}

static void SetInitializedFlag(u8 a0)
{
	sListMenuState.initialized = a0;
}

static u8 GetCursorPosition(void)
{
	return sListMenuState.scroll + sListMenuState.row;
}

static void SetCursorPosition(void)
{
	if (IfScrollIsOutOfBounds()) {
		sListMenuState.scroll = (sStateDataPtr->nItems + 1) -
		                        sStateDataPtr->maxShowed;
	}

	if (IfRowIsOutOfBounds()) {
		if (sStateDataPtr->nItems + 1 < 2) {
			sListMenuState.row = 0;
		} else {
			sListMenuState.row = sStateDataPtr->nItems;
		}
	}
}


static void SetScrollPosition(void)
{
	u8 i;

	if (sListMenuState.row > 3) {
		for (i = 0; i <= sListMenuState.row - 3;
		     sListMenuState.row--, sListMenuState.scroll++, i++) {
			if (sListMenuState.scroll + sStateDataPtr->maxShowed ==
			    sStateDataPtr->nItems + 1) {
				break;
			}
		}
	}
}

bool8 IfScrollIsOutOfBounds(void)
{
	if (sListMenuState.scroll != 0
	    && sListMenuState.scroll + sStateDataPtr->maxShowed >
	    sStateDataPtr->nItems + 1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

bool8 IfRowIsOutOfBounds(void)
{
	if (sListMenuState.scroll + sListMenuState.row >= sStateDataPtr->nItems +
	    1) {
		return TRUE;
	} else {
		return FALSE;
	}
}

static void SaveScrollAndRow(s16 *data)
{
	ListMenuGetScrollAndRow(data[0], &sListMenuState.storedScrollOffset,
	                        &sListMenuState.storedRowPosition);
}


void ClearModeOnStartup(void)
{
	sStateDataPtr->filterMode = 0;
}

void WriteModeToSaveBlock(u8 mode)
{
	if (IsSubsavedQuestMode() == FALSE) {
		gSaveBlock2Ptr->savedQuestMode = mode;
	}
}

static u8 ManageMode(u8 action)
{
	u8 mode = sStateDataPtr->filterMode;

	switch (action) {
		case SUB:
			mode = ToggleSubsavedQuestMode(mode);
			break;

		case ALPHA:
			mode = ToggleAlphaMode(mode);
			sStateDataPtr->restoreCursor = FALSE;
			break;

		default:
			mode = IncrementMode(mode);
			sStateDataPtr->restoreCursor = FALSE;
			break;
	}
	WriteModeToSaveBlock(mode);
	return mode;
}

u8 ToggleSubsavedQuestMode(u8 mode)
{
	if (IsSubsavedQuestMode()) {
		mode -= SORT_SUBQUEST;
		sStateDataPtr->restoreCursor = TRUE;
	} else {
		mode += SORT_SUBQUEST;
		sStateDataPtr->restoreCursor = FALSE;
	}

	return mode;
}

u8 ToggleAlphaMode(u8 mode)
{
	if (IsAlphaMode()) {
		mode -= SORT_DEFAULT_AZ;
	} else {
		mode += SORT_DEFAULT_AZ;
	}

	return mode;
}

u8 IncrementMode(u8 mode)
{
	if (mode % 10 == SORT_DONE) {
		mode -= SORT_DONE;
	} else {
		mode++;
	}

	return mode;
}

static bool8 IsSubsavedQuestMode(void)
{
	if (sStateDataPtr->filterMode > SORT_DONE_AZ) {
		return TRUE;
	} else {
		return FALSE;
	}
}

static bool8 IsNotFilteredMode(void)
{
	u8 mode = sStateDataPtr->filterMode % 10;

	if (mode == FLAG_GET_UNLOCKED) {
		return TRUE;
	} else {
		return FALSE;
	}
}

static bool8 IsAlphaMode(void)
{
	if (sStateDataPtr->filterMode < SORT_SUBQUEST
	    && sStateDataPtr->filterMode > SORT_DONE) {
		return TRUE;
	} else {
		return FALSE;
	}
}

static void SetInitalLoadTrue(void)
{
	sStateDataPtr->initialLoad = TRUE;
}

static void SetInitalLoadFalse(void)
{
	sStateDataPtr->initialLoad = FALSE;
}

static bool8 IsInitalLoad(void)
{
	bool8 initialLoad = sStateDataPtr->initialLoad;
	return initialLoad;
}

static void GetSavedQuestMode(void)
{
	sStateDataPtr->filterMode = gSaveBlock2Ptr->savedQuestMode;
}

static void LoadSavedQuestMode(u8 taskId)
{
	if (IsInitalLoad()) {
		SetInitalLoadFalse();
		GetSavedQuestMode();
		Task_QuestMenuCleanUp(taskId);
	}
}

static u16 BuildMenuTemplate(void)
{
	u8 lastRow = GetModeAndGenerateList();

	AssignCancelNameAndId(lastRow);

	gMultiuseListMenuTemplate.totalItems = CountNumberListRows();
	gMultiuseListMenuTemplate.items = sListMenuItems;
	gMultiuseListMenuTemplate.windowId = 0;
	gMultiuseListMenuTemplate.header_X = 0;
	gMultiuseListMenuTemplate.cursor_X = 15;
	gMultiuseListMenuTemplate.item_X = 23;
	gMultiuseListMenuTemplate.lettersSpacing = 1;
	gMultiuseListMenuTemplate.itemVerticalPadding = 2;
	gMultiuseListMenuTemplate.upText_Y = 2;
	gMultiuseListMenuTemplate.maxShowed = sStateDataPtr->maxShowed;
	gMultiuseListMenuTemplate.fontId = 2;
	gMultiuseListMenuTemplate.cursorPal = 2;
	gMultiuseListMenuTemplate.fillValue = 0;
	gMultiuseListMenuTemplate.cursorShadowPal = 0;
	gMultiuseListMenuTemplate.moveCursorFunc = MoveCursorFunc;
	gMultiuseListMenuTemplate.itemPrintFunc = GenerateStateAndPrint;
	gMultiuseListMenuTemplate.scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD;
	gMultiuseListMenuTemplate.cursorKind = 0;
}

u8 GetModeAndGenerateList()
{
	if (IsSubsavedQuestMode()) {
		return GenerateSubquestList();
	} else {
		return GenerateList(!IsNotFilteredMode());
	}
}

static u8 CountNumberListRows()
{
	u8 mode = sStateDataPtr->filterMode % 10;

	if (IsSubsavedQuestMode()) {
		return sSideQuests[sStateDataPtr->parentQuest].numSubquests + 1;
	}

	switch (mode) {
		case SORT_DEFAULT:
			return QUEST_COUNT + 1;
		case SORT_INACTIVE:
			return CountInactiveQuests() + 1;
		case SORT_ACTIVE:
			return CountActiveQuests() + 1;
		case SORT_REWARD:
			return CountRewardQuests() + 1;
		case SORT_DONE:
			return CountCompletedQuests() + 1;
	}

}

u8 *DefineQuestOrder()
{
	static u8 sortedList[QUEST_COUNT];
	u8 a, c, d, e;
	u8 placeholderVariable;

	for (a = 0; a < QUEST_COUNT; a++) {
		sortedList[a] = a;
	}

	if (IsAlphaMode()) {
		for (c = 0; c < QUEST_COUNT; c++) {
			for (d = c + 1; d < QUEST_COUNT; d++) {
				if (StringCompare(sSideQuests[sortedList[c]].name,
				                  sSideQuests[sortedList[d]].name) > 0) {
					placeholderVariable = sortedList[c];
					sortedList[c] = sortedList[d];
					sortedList[d] = placeholderVariable;
				}
			}
		}
	}

	return sortedList;
}

u8 GenerateSubquestList()
{
	u8 parentQuest = sStateDataPtr->parentQuest;
	u8 mode = sStateDataPtr->filterMode % 10;
	u8 lastRow = 0, numRow = 0, countQuest = 0;

	for (numRow = 0; numRow < sSideQuests[parentQuest].numSubquests; numRow++) {
		PrependQuestNumber(countQuest);
		PopulateSubquestName(parentQuest, countQuest);
		PopulateListRowNameAndId(numRow, countQuest);

		countQuest++;
		lastRow = numRow + 1;
	}
	return lastRow;
}

u8 GenerateList(bool8 isFiltered)
{
	u8 mode = sStateDataPtr-> filterMode % 10;
	u8 lastRow = 0, numRow = 0, offset = 0, newRow = 0, countQuest = 0,
	   selectedQuestId = 0;
	u8 *sortedQuestList;

	sortedQuestList = DefineQuestOrder();

	for (countQuest = 0; countQuest < sStateDataPtr->nItems; countQuest++) {
		selectedQuestId = *(sortedQuestList + countQuest);

		if (isFiltered && !QuestMenu_GetSetQuestState(selectedQuestId, mode)) {
			continue;
		}

		PopulateEmptyRow(selectedQuestId);

		if (QuestMenu_GetSetQuestState(selectedQuestId, FLAG_GET_FAVORITE)) {
			SetFavoriteQuest(selectedQuestId);
			newRow = numRow;
			numRow++;
		} else {
			newRow = CountFavoriteQuests() + offset;
			offset++;
		}

		PopulateQuestName(selectedQuestId);
		PopulateListRowNameAndId(newRow, selectedQuestId);
	}
	return numRow + offset;
}

u8 getFirstFavoriteQuest(){
	u8 i;

	for(i = 0; i < SUB_QUEST_COUNT; i++){
		if(QuestMenu_GetSetQuestState(i, FLAG_GET_FAVORITE) && QuestMenu_GetSetQuestState(i,FLAG_GET_ACTIVE))
			return i;
	}

	for(i = 0; i < SUB_QUEST_COUNT; i++){
		if(QuestMenu_GetSetQuestState(i,FLAG_GET_ACTIVE))
			return i;
	}
	
	return SUB_QUEST_COUNT;
}

static void AssignCancelNameAndId(u8 numRow)
{
	if (IsSubsavedQuestMode()) {
		sListMenuItems[numRow].name = sText_Back;
	} else {
		sListMenuItems[numRow].name = sText_Close;
	}

	sListMenuItems[numRow].id = LIST_CANCEL;
}

u8 QuestMenu_GetSetSubquestState(u8 quest, u8 caseId, u8 childQuest)
{

	u8 uniqueId = sSideQuests[quest].subquests[childQuest].id;
	u8  index = uniqueId / 8; //8 bits per byte
	u8	bit = uniqueId % 8;
	u8	mask = 1 << bit;

	switch (caseId) {
		case FLAG_GET_COMPLETED:
			return gSaveBlock2Ptr->subQuests[index] & mask;
		case FLAG_SET_COMPLETED:
			gSaveBlock2Ptr->subQuests[index] |= mask;
			return 1;
	}

	return -1;
}

u8 QuestMenu_GetSetQuestState(u8 quest, u8 caseId)
{
	u8 index = quest * 5 / 8;
	u8 bit = quest * 5 % 8;
	u8 mask = 0, index2 = 0, bit2 = 0, index3 = 0, bit3 = 0, mask2 = 0,
	   mask3 = 0;

	// 0 : locked
	// 1 : actived
	// 2 : rewarded
	// 3 : completed
	// 4 : favorited

	switch (caseId) {
		case FLAG_GET_UNLOCKED:
		case FLAG_SET_UNLOCKED:
			break;
		case FLAG_GET_INACTIVE:
		case FLAG_GET_ACTIVE:
		case FLAG_SET_ACTIVE:
		case FLAG_REMOVE_ACTIVE:
			bit += 1;
			break;
		case FLAG_GET_REWARD:
		case FLAG_SET_REWARD:
		case FLAG_REMOVE_REWARD:
			bit += 2;
			break;
		case FLAG_GET_COMPLETED:
		case FLAG_SET_COMPLETED:
        case FLAG_REMOVE_COMPLETED:
			bit += 3;
			break;
		case FLAG_GET_FAVORITE:
		case FLAG_SET_FAVORITE:
		case FLAG_REMOVE_FAVORITE:
			bit += 4;
			break;
	}
	if (bit >= 8) {
		index += 1;
		bit %= 8;
	}
	mask = 1 << bit;

	switch (caseId) {
		case FLAG_GET_UNLOCKED:
			return gSaveBlock2Ptr->questData[index] & mask;
		case FLAG_SET_UNLOCKED:
			gSaveBlock2Ptr->questData[index] |= mask;
			return 1;
		case FLAG_GET_INACTIVE:
			bit2 = bit + 1;
			bit3 = bit + 2;
			index2 = index;
			index3 = index;

			if (bit2 >= 8) {
				index2 += 1;
				bit2 %= 8;
			}
			if (bit3 >= 8) {
				index3 += 1;
				bit3 %= 8;
			}

			mask2 = 1 << bit2;
			mask3 = 1 << bit3;
			return !(gSaveBlock2Ptr->questData[index] & mask) && \
			       !(gSaveBlock2Ptr->questData[index2] & mask2) && \
			       !(gSaveBlock2Ptr->questData[index3] & mask3);
		case FLAG_GET_ACTIVE:
			return gSaveBlock2Ptr->questData[index] & mask;
		case FLAG_SET_ACTIVE:
			gSaveBlock2Ptr->questData[index] |= mask;
			return 1;
		case FLAG_REMOVE_ACTIVE:
			gSaveBlock2Ptr->questData[index] &= ~mask;
			return 1;
		case FLAG_GET_REWARD:
			return gSaveBlock2Ptr->questData[index] & mask;
		case FLAG_SET_REWARD:
			gSaveBlock2Ptr->questData[index] |= mask;
			return 1;
		case FLAG_REMOVE_REWARD:
			gSaveBlock2Ptr->questData[index] &= ~mask;
			return 1;
		case FLAG_GET_COMPLETED:
			return gSaveBlock2Ptr->questData[index] & mask;
		case FLAG_SET_COMPLETED:
			gSaveBlock2Ptr->questData[index] |= mask;
			CheckFavoriteAndRemove(quest);
			return 1;
        case FLAG_REMOVE_COMPLETED:
			gSaveBlock2Ptr->questData[index] &= ~mask;
			return 1;
		case FLAG_GET_FAVORITE:
			return gSaveBlock2Ptr->questData[index] & mask;
		case FLAG_SET_FAVORITE:
			gSaveBlock2Ptr->questData[index] |= mask;
			return 1;
		case FLAG_REMOVE_FAVORITE:
			gSaveBlock2Ptr->questData[index] &= ~mask;
			return 1;
	}
	return -1;  //failure
}

u8 CountUnlockedQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++) {
		if (QuestMenu_GetSetQuestState(i, FLAG_GET_UNLOCKED)) {
			q++;
		}
	}
	return q;
}

u8 CountInactiveQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++) {
		if (QuestMenu_GetSetQuestState(i, FLAG_GET_INACTIVE)) {
			q++;
		}
	}
	return q;
}

u8 CountActiveQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++) {
		if (QuestMenu_GetSetQuestState(i, FLAG_GET_ACTIVE)) {
			q++;
		}
	}
	return q;
}

u8 CountRewardQuests(void)
{
	u8 q = 0, i = 0;

	for (i = 0; i < QUEST_COUNT; i++) {
		if (QuestMenu_GetSetQuestState(i, FLAG_GET_REWARD)) {
			q++;
		}
	}
	return q;
}

u8 CountCompletedQuests(void)
{
	u8 q = 0, i = 0;

	u8 parentQuest = sStateDataPtr->parentQuest;

	if (IsSubsavedQuestMode()) {
		for (i = 0; i < sSideQuests[parentQuest].numSubquests; i++) {
			if (QuestMenu_GetSetSubquestState(parentQuest, FLAG_GET_COMPLETED, i)) {
				q++;
			}
		}
	} else {
		for (i = 0; i < QUEST_COUNT; i++) {
			if (QuestMenu_GetSetQuestState(i, FLAG_GET_COMPLETED)) {
				q++;
			}
		}
	}

	return q;
}

u8 CountFavoriteQuests(void)
{
	u8 q = 0, i = 0, x = 0;
	u8 mode = sStateDataPtr->filterMode % 10;

	for (i = 0; i < QUEST_COUNT; i++) {
		if (QuestMenu_GetSetQuestState(i, FLAG_GET_FAVORITE)) {
			if (QuestMenu_GetSetQuestState(i, mode)) {
				x++;
			}
			q++;
		}
	}

	if (IsNotFilteredMode()) {
		return q;
	} else {
		return x;
	}

}

void PopulateEmptyRow(u8 countQuest)
{
	questNamePointer = StringCopy(questNameArray[countQuest], sText_Empty);
}
void PrependQuestNumber(u8 countQuest)
{
	questNamePointer = ConvertIntToDecimalStringN(questNameArray[countQuest],
	                   countQuest + 1, STR_CONV_MODE_LEFT_ALIGN, 2);
	questNamePointer = StringAppend(questNamePointer,
	                                sText_DotSpace);
}

void SetFavoriteQuest(u8 countQuest)
{
	questNamePointer = StringAppend(questNameArray[countQuest],
	                                sText_ColorGreen);
}

void PopulateQuestName(u8 countQuest)
{
	if (QuestMenu_GetSetQuestState(countQuest, FLAG_GET_UNLOCKED)) {
		StringExpandPlaceholders(gStringVar4, sSideQuests[countQuest].name);
		questNamePointer = StringAppend(questNameArray[countQuest], gStringVar4);
		AddSubQuestButton(countQuest);
	} else {
		StringAppend(questNameArray[countQuest], sText_Unk);
	}
}

void PopulateSubquestName(u8 parentQuest, u8 countQuest)
{
	if (IsSubquestCompletedState(countQuest)) {
		StringExpandPlaceholders(gStringVar4,
		                         sSideQuests[parentQuest].subquests[countQuest].name);
		questNamePointer = StringAppend(questNameArray[countQuest], gStringVar4);
	} else {
		questNamePointer = StringAppend(questNamePointer, sText_Unk);
	}
}

u8 PopulateListRowNameAndId(u8 row, u8 countQuest)
{
	sListMenuItems[row].name = questNameArray[countQuest];
	sListMenuItems[row].id = countQuest;
}

static bool8 DoesQuestHaveChildrenAndNotInactive(u16 itemId)
{
	if (sSideQuests[itemId].numSubquests != 0
	    && QuestMenu_GetSetQuestState(itemId, FLAG_GET_UNLOCKED)
	    && !QuestMenu_GetSetQuestState(itemId, FLAG_GET_INACTIVE)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void AddSubQuestButton(u8 countQuest)
{
	if (DoesQuestHaveChildrenAndNotInactive(countQuest)) {
		questNamePointer = StringAppend(questNameArray[countQuest],
		                                sText_SubQuestButton);
	}

}
static void QuestMenu_AddTextPrinterParameterized(u8 windowId, u8 fontId,
                const u8 *str, u8 x, u8 y,
                u8 letterSpacing, u8 lineSpacing, u8 speed, u8 colorIdx)
{
	AddTextPrinterParameterized4(windowId, fontId, x, y, letterSpacing,
	                             lineSpacing,
	                             sQuestMenuWindowFontColors[colorIdx], speed, str);
}

static void MoveCursorFunc(s32 questId, bool8 onInit,
                           struct ListMenu *list)
{
	PlayCursorSound(onInit);

	if (sStateDataPtr->moveModeOrigPos == 0xFF) {
		QuestMenu_DestroySprite(sStateDataPtr->spriteIconSlot ^ 1);
		sStateDataPtr->spriteIconSlot ^= 1;

		if (questId == LIST_CANCEL) {
			PrintDetailsForCancel();
		} else {
			GenerateAndPrintQuestDetails(questId);
			DetermineSpriteType(questId);
		}
	}
}

static void PlayCursorSound(bool8 firstRun)
{
	if (firstRun == FALSE) {
		PlaySE(SE_RG_BAG_CURSOR);
	}
}

static void PrintDetailsForCancel()
{
	FillWindowPixelBuffer(1, 0);

	QuestMenu_AddTextPrinterParameterized(1, 2, sText_Empty, 2, 3, 2, 0, 0,
	                                      0);
	QuestMenu_AddTextPrinterParameterized(1, 2, sText_Empty, 40, 19, 5, 0, 0,
	                                      0);

	QuestMenu_CreateSprite(-1, sStateDataPtr->spriteIconSlot, ITEM);
}

void GenerateAndPrintQuestDetails(s32 questId)
{
	GenerateQuestLocation(questId);
	PrintQuestLocation(questId);
	GenerateQuestFlavorText(questId);
	PrintQuestFlavorText(questId);
}
void GenerateQuestLocation(s32 questId)
{
	if (!IsSubsavedQuestMode()) {
		StringCopy(gStringVar2, sSideQuests[questId].map);
	} else {
		StringCopy(gStringVar2,
		           sSideQuests[sStateDataPtr->parentQuest].subquests[questId].map);
	}

	StringExpandPlaceholders(gStringVar4, sText_ShowLocation);
}
void PrintQuestLocation(s32 questId)
{
	FillWindowPixelBuffer(1, 0);
	QuestMenu_AddTextPrinterParameterized(1, 2, gStringVar4, 2, 3, 2, 0, 0,
	                                      4);
}
void GenerateQuestFlavorText(s32 questId)
{
	if (IsSubsavedQuestMode() == FALSE) {
		if (IsQuestInactiveState(questId) == TRUE) {
			StringCopy(gStringVar1, sText_StartForMore);
		}
		if (IsQuestActiveState(questId) == TRUE) {
			UpdateQuestDesc(questId);
		}
		if (IsQuestRewardState(questId) == TRUE) {
			StringCopy(gStringVar1, sText_ReturnRecieveReward);
		}
		if (IsQuestCompletedState(questId) == TRUE) {
			UpdateQuestDoneDesc(questId);
		}
	} else {
		if (IsSubquestCompletedState(questId) == TRUE) {
			StringCopy(gStringVar1,
			           sSideQuests[sStateDataPtr->parentQuest].subquests[questId].desc);
		} else {
			StringCopy(gStringVar1, sText_Empty);
		}
	}

	StringExpandPlaceholders(gStringVar3, gStringVar1);
}
void UpdateQuestDesc(s32 questId)
{
	StringExpandPlaceholders(gStringVar1, GetQuestDesc(questId));
}

void UpdateQuestDoneDesc(s32 questId)
{
	StringExpandPlaceholders(gStringVar1, GetQuestDoneDesc(questId));
}

const u8 *GetQuestDesc(s32 questId)
{
	switch (questId) {
		case QUEST_PLAYERSADVENTURE:
			return GetQuestDesc_PlayersAdventure();
			break;
		case QUEST_BRINGFRUIT:
			return GetQuestDesc_BringFruit();
			break;
		case QUEST_RABIESOUTBREAK:
			return GetQuestDesc_RabiesOutbreak();
			break;
		case QUEST_BETWEENASTONEANDAHARD:
			return GetQuestDesc_BetweenAStoneAndAHardPlace();
			break;
		default:
			return sSideQuests[questId].desc;
	}
}

const u8 *GetQuestDoneDesc(s32 questId)
{
	switch (questId) {
		case QUEST_PLAYERSADVENTURE:
			return GetQuestDoneDesc_PlayersAdventure();
		default:
			return sSideQuests[questId].donedesc;
	}
}

void PrintQuestFlavorText(s32 questId)
{
	QuestMenu_AddTextPrinterParameterized(1, 2, gStringVar3, 40, 19, 5, 0, 0,
	                                      4);
}

bool8 IsSubquestCompletedState(s32 questId)
{
	if (QuestMenu_GetSetSubquestState(sStateDataPtr->parentQuest,
	                                  FLAG_GET_COMPLETED,
	                                  questId)) {
		return TRUE;
	} else {
		return FALSE;
	}
}
bool8 IsQuestRewardState(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_REWARD)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

bool8 IsQuestInactiveState(s32 questId)
{
	if (!QuestMenu_GetSetQuestState(questId, FLAG_GET_ACTIVE)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

bool8 IsQuestActiveState(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_ACTIVE)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

bool8 IsQuestCompletedState(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_COMPLETED)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

bool8 IsQuestUnlocked(s32 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_UNLOCKED)) {
		return TRUE;
	} else {
		return FALSE;
	}
}

void DetermineSpriteType(s32 questId)
{
	u16 spriteId;
	u8 spriteType;

	if (IsSubsavedQuestMode() == FALSE) {
		spriteId = sSideQuests[questId].sprite;
		spriteType = sSideQuests[questId].spritetype;

		QuestMenu_CreateSprite(spriteId, sStateDataPtr->spriteIconSlot,
		                       spriteType);
	} else if (IsSubquestCompletedState(questId) == TRUE) {
		spriteId =
		        sSideQuests[sStateDataPtr->parentQuest].subquests[questId].sprite;
		spriteType =
		        sSideQuests[sStateDataPtr->parentQuest].subquests[questId].spritetype;
		QuestMenu_CreateSprite(spriteId, sStateDataPtr->spriteIconSlot,
		                       spriteType);
	} else {
		QuestMenu_CreateSprite(ITEM_NONE, sStateDataPtr->spriteIconSlot, ITEM);
	}
	QuestMenu_DestroySprite(sStateDataPtr->spriteIconSlot ^ 1);
	sStateDataPtr->spriteIconSlot ^= 1;
}
static void QuestMenu_CreateSprite(u16 itemId, u8 idx, u8 spriteType)
{
	u8 *ptr = &sItemMenuIconSpriteIds[10];
	u8 spriteId;
	struct SpriteSheet spriteSheet;
	struct CompressedSpritePalette spritePalette;
	struct SpriteTemplate *spriteTemplate;

	if (ptr[idx] == 0xFF) {
		FreeSpriteTilesByTag(102 + idx);
		FreeSpritePaletteByTag(102 + idx);

		switch (spriteType) {
			case OBJECT:
				spriteId = CreateObjectGraphicsSprite(itemId, SpriteCallbackDummy, 20,
				                                      132, 0);
				break;
			case ITEM:
				spriteId = AddItemIconSprite(102 + idx, 102 + idx, itemId);
				break;
			case PKMN:
				LoadMonIconPalettes();
				spriteId = CreateMonIcon(itemId, SpriteCallbackDummy, 20, 132, 0, 1);
				break;
			default:
				break;
		}

		gSprites[spriteId].oam.objMode = ST_OAM_OBJ_BLEND;

		if (spriteId != MAX_SPRITES) {
			ptr[idx] = spriteId;

			if (spriteType == ITEM) {
				gSprites[spriteId].x2 = 24;
				gSprites[spriteId].y2 = 140;
			}
		}
	}
}

void ResetSpriteState(void)
{
	u16 i;

	for (i = 0; i < NELEMS(sItemMenuIconSpriteIds); i++) {
		sItemMenuIconSpriteIds[i] = 0xFF;
	}
}

static void QuestMenu_DestroySprite(u8 idx)
{
	u8 *ptr = &sItemMenuIconSpriteIds[10];

	if (ptr[idx] != 0xFF) {
		u16 palTag = GetSpritePaletteTagByPaletteNum(
		                     gSprites[ptr[idx]].oam.paletteNum);
		DestroySprite(&gSprites[ptr[idx]]);
		ptr[idx] = 0xFF;

		if (sStateDataPtr->oldPaletteTag != palTag) {
			if (sStateDataPtr->oldPaletteTag != 0) {
				FreeSpriteTilesByTag(sStateDataPtr->oldPaletteTag);
				sStateDataPtr->oldPaletteTag = palTag;
			}
		}
	}
}

static void GenerateStateAndPrint(u8 windowId, u32 questId,
                                  u8 y)
{
	u8 colorIndex;

	if (questId != LIST_CANCEL) {
		if (IsSubsavedQuestMode()) {
			colorIndex = GenerateSubquestState(questId);
		} else {
			colorIndex = GenerateQuestState(questId);
		}

		PrintQuestState(windowId, y, colorIndex);
	}
}

u8 GenerateSubquestState(u8 questId)
{
	u8 parentQuest = sStateDataPtr->parentQuest;

	if (QuestMenu_GetSetSubquestState(parentQuest, FLAG_GET_COMPLETED,
	                                  questId)) {
		StringCopy(gStringVar4, sSideQuests[parentQuest].subquests[questId].type);
	} else {
		StringCopy(gStringVar4, sText_Empty);
	}

	return 2;
}

u8 GenerateQuestState(u8 questId)
{
	if (QuestMenu_GetSetQuestState(questId, FLAG_GET_COMPLETED)) {
		StringCopy(gStringVar4, sText_Complete);
		return 2;
	} else if (QuestMenu_GetSetQuestState(questId, FLAG_GET_REWARD)) {
		StringCopy(gStringVar4, sText_Reward);
		return 1;
	} else if (QuestMenu_GetSetQuestState(questId, FLAG_GET_ACTIVE)) {
		StringCopy(gStringVar4, sText_Active);
		return 3;
	} else {
		StringCopy(gStringVar4, sText_Empty);
	}
}

void PrintQuestState(u8 windowId, u8 y, u8 colorIndex)
{
	QuestMenu_AddTextPrinterParameterized(windowId, 0, gStringVar4, 200, y, 0,
	                                      0, 0xFF, colorIndex);
}

static void GenerateAndPrintHeader(void)
{
	GenerateDenominatorNumQuests();
	GenerateNumeratorNumQuests();
	GenerateMenuContext();

	PrintNumQuests();
	PrintMenuContext();

	if (!IsSubsavedQuestMode()) {
		PrintTypeFilterButton();
	}
}
static void GenerateDenominatorNumQuests(void)
{
	ConvertIntToDecimalStringN(gStringVar2, QUEST_COUNT,
	                           STR_CONV_MODE_LEFT_ALIGN, 6);
}

static void GenerateNumeratorNumQuests(void)
{
	u8 mode = sStateDataPtr->filterMode % 10;
	u8 parentQuest = sStateDataPtr->parentQuest;

	switch (mode) {
		case SORT_DEFAULT:
			ConvertIntToDecimalStringN(gStringVar1, CountUnlockedQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN,
			                           6);
			break;
		case SORT_INACTIVE:
			ConvertIntToDecimalStringN(gStringVar1, CountInactiveQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN,
			                           6);
			break;
		case SORT_ACTIVE:
			ConvertIntToDecimalStringN(gStringVar1, CountActiveQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN, 6);
			break;
		case SORT_REWARD:
			ConvertIntToDecimalStringN(gStringVar1, CountRewardQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN, 6);
			break;
		case SORT_DONE:
			ConvertIntToDecimalStringN(gStringVar1, CountCompletedQuests(),
			                           STR_CONV_MODE_LEFT_ALIGN,
			                           6);
			break;
	}

	if (IsSubsavedQuestMode()) {
		ConvertIntToDecimalStringN(gStringVar2,
		                           sSideQuests[parentQuest].numSubquests,
		                           STR_CONV_MODE_LEFT_ALIGN, 6);
		ConvertIntToDecimalStringN(gStringVar1, CountCompletedQuests(),
		                           STR_CONV_MODE_LEFT_ALIGN,
		                           6);
	}
}

static void GenerateMenuContext(void)
{
	u8 mode = sStateDataPtr->filterMode % 10;
	u8 parentQuest = sStateDataPtr->parentQuest;

	switch (mode) {
		case SORT_DEFAULT:
			questNamePointer = StringCopy(questNameArray[QUEST_ARRAY_COUNT],
			                              sText_AllHeader);
			break;
		case SORT_INACTIVE:
			questNamePointer = StringCopy(questNameArray[QUEST_ARRAY_COUNT],
			                              sText_InactiveHeader);
			break;
		case SORT_ACTIVE:
			questNamePointer = StringCopy(questNameArray[QUEST_ARRAY_COUNT],
			                              sText_ActiveHeader);
			break;
		case SORT_REWARD:
			questNamePointer = StringCopy(questNameArray[QUEST_ARRAY_COUNT],
			                              sText_RewardHeader);
			break;
		case SORT_DONE:
			questNamePointer = StringCopy(questNameArray[QUEST_ARRAY_COUNT],
			                              sText_CompletedHeader);
			break;
	}

	if (IsAlphaMode()) {
		questNamePointer = StringAppend(questNameArray[QUEST_ARRAY_COUNT],
		                                sText_AZ);
	}
	if (IsSubsavedQuestMode()) {
		StringExpandPlaceholders(gStringVar4, sSideQuests[parentQuest].name);
		questNamePointer = StringCopy(questNameArray[QUEST_ARRAY_COUNT],
		                              gStringVar4);
	}
}

static void PrintNumQuests(void)
{
	StringExpandPlaceholders(gStringVar4, sText_QuestNumberDisplay);
	QuestMenu_AddTextPrinterParameterized(2, 0, gStringVar4, 167, 1, 0, 1, 0,
	                                      0);
}
static void PrintMenuContext(void)
{
	QuestMenu_AddTextPrinterParameterized(2, 0,
	                                      questNameArray[QUEST_ARRAY_COUNT], 10, 1, 0, 1, 0, 0);
}
static void PrintTypeFilterButton(void)
{
	QuestMenu_AddTextPrinterParameterized(2, 0, sText_Type, 198, 1,
	                                      0, 1, 0, 0);

}

static void Task_Main(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	s32 input = ListMenu_ProcessInput(data[0]);

	u8 selectedQuestId = sListMenuItems[GetCursorPosition()].id;

	if (!gPaletteFade.active) {
		ListMenuGetScrollAndRow(data[0], &sListMenuState.scroll,
		                        &sListMenuState.row);

		//LoadSavedQuestMode(taskId);
        //PSF TODO this doesn't work correctly. 
        //The goal is when the user closes the quest menu and reopens it, the user goes back to the quest that they were previously looking at.

		switch (input) {
			case LIST_NOTHING_CHOSEN:
				if (JOY_NEW(R_BUTTON)) {
					ChangeModeAndCleanUp(taskId);
				}
				if (JOY_NEW(START_BUTTON)) {
					ToggleAlphaModeAndCleanUp(taskId);
				}
				if (JOY_NEW(SELECT_BUTTON)) {
					ToggleFavoriteAndCleanUp(taskId, selectedQuestId);
				}
				break;

			case LIST_CANCEL:
				if (IsSubsavedQuestMode()) {
					ReturnFromSubquestAndCleanUp(taskId);
				} else {
					TurnOffQuestMenu(taskId);
				}
				break;

			default:
				if (!IsSubsavedQuestMode()) {
					EnterSubsavedQuestModeAndCleanUp(taskId, data, input);
				}
				break;
		}
	}
}

u8 ManageFavorites(u8 selectedQuestId)
{
	if (QuestMenu_GetSetQuestState(selectedQuestId, FLAG_GET_FAVORITE)) {
		QuestMenu_GetSetQuestState(selectedQuestId, FLAG_REMOVE_FAVORITE);
	} else {
		QuestMenu_GetSetQuestState(selectedQuestId, FLAG_SET_FAVORITE);
	}
}

u8 CheckFavoriteAndRemove(u8 quest)
{
	if (QuestMenu_GetSetQuestState(quest, FLAG_GET_FAVORITE)) {
		QuestMenu_GetSetQuestState(quest, FLAG_REMOVE_FAVORITE);
	}
}

static void Task_QuestMenuCleanUp(u8 taskId)
{
	s16 *data = gTasks[taskId].data;

	QuestMenu_RemoveScrollIndicatorArrowPair();
	DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
	ClearStdWindowAndFrameToTransparent(2, FALSE);

	GenerateAndPrintHeader();
	AllocateResourcesForListMenu();
	BuildMenuTemplate();
	PlaceTopMenuScrollIndicatorArrows();

	if (sStateDataPtr->restoreCursor == TRUE) {
		RestoreSavedScrollAndRow(data);
	} else {
		ResetCursorToTop(data);
	}

}

static void RestoreSavedScrollAndRow(s16 *data)
{
	data[0] = ListMenuInit(&gMultiuseListMenuTemplate,
	                       sListMenuState.storedScrollOffset,
	                       sListMenuState.storedRowPosition);
}
static void ResetCursorToTop(s16 *data)
{
	sListMenuState.row = 0;
	sListMenuState.scroll = 0;
	data[0] = ListMenuInit(&gMultiuseListMenuTemplate, sListMenuState.scroll,
	                       sListMenuState.row);
}

static void QuestMenu_RemoveScrollIndicatorArrowPair(void)
{
	if (sStateDataPtr->scrollIndicatorArrowPairId != 0xFF) {
		RemoveScrollIndicatorArrowPair(sStateDataPtr->scrollIndicatorArrowPairId);
		sStateDataPtr->scrollIndicatorArrowPairId = 0xFF;
	}
}


void EnterSubsavedQuestModeAndCleanUp(u8 taskId, s16 *data,
                                      s32 input)
{
	if (DoesQuestHaveChildrenAndNotInactive(input)) {
		PrepareFadeOut(taskId);

		PlaySE(SE_SELECT);
		sStateDataPtr->parentQuest = input;
		sStateDataPtr->filterMode = ManageMode(SUB);
		SaveScrollAndRow(data);
		gTasks[taskId].func = Task_FadeOut;
	}
}
void ChangeModeAndCleanUp(u8 taskId)
{
	if (!IsSubsavedQuestMode()) {
		PlaySE(SE_SELECT);
		sStateDataPtr->filterMode = ManageMode(INCREMENT);
		Task_QuestMenuCleanUp(taskId);
	}
}
void ToggleAlphaModeAndCleanUp(u8 taskId)
{
	if (!IsSubsavedQuestMode()) {
		PlaySE(SE_SELECT);
		sStateDataPtr->filterMode = ManageMode(ALPHA);
		Task_QuestMenuCleanUp(taskId);
	}
}
void ToggleFavoriteAndCleanUp(u8 taskId, u8 selectedQuestId)
{
	if (!IsSubsavedQuestMode()
	    && !CheckSelectedIsCancel(selectedQuestId)) {
		PlaySE(SE_SELECT);
		ManageFavorites(selectedQuestId);
		sStateDataPtr->restoreCursor = FALSE;
		Task_QuestMenuCleanUp(taskId);
	}
}
bool8 CheckSelectedIsCancel(u8 selectedQuestId)
{
	if (selectedQuestId == (0xFF - 1)) {
		return TRUE;
	} else {
		return FALSE;
	}
}
void ReturnFromSubquestAndCleanUp(u8 taskId)
{
	PrepareFadeOut(taskId);

	PlaySE(SE_SELECT);
	sStateDataPtr->filterMode = ManageMode(SUB);
	gTasks[taskId].func = Task_FadeOut;
}

static void SetGpuRegBaseForFade()
{
	//Sets the GPU registers to prepare for a hardware fade
	SetGpuReg(REG_OFFSET_BLDCNT,
	          BLDCNT_TGT1_OBJ | BLDCNT_TGT1_BG0 | BLDCNT_TGT2_BG1 |
	          BLDCNT_EFFECT_BLEND);      //Blend Sprites and BG0 into BG1
	SetGpuReg(REG_OFFSET_BLDY, 0);
}

#define MAX_FADE_INTENSITY 16
#define MIN_FADE_INTENSITY 0

void InitFadeVariables(u8 taskId, u8 blendWeight, u8 frameDelay,
                       u8 frameTimerBase, u8 delta)
{
	gTasks[taskId].data[1] = blendWeight;
	gTasks[taskId].data[2] = frameDelay;
	gTasks[taskId].data[3] = gTasks[taskId].data[frameTimerBase];
	gTasks[taskId].data[4] = delta;
}


static void PrepareFadeOut(u8 taskId)
{
	SetGpuRegBaseForFade();
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(MAX_FADE_INTENSITY, 0));
	InitFadeVariables(taskId, MAX_FADE_INTENSITY, 0, 2, 2);
}

static bool8 HandleFadeOut(u8 taskId)
{
	if (gTasks[taskId].data[3]-- != 0) {
		return FALSE;
	}

	//Set the timer, decrease the fade weight by the delta, increase the delta by the timer
	gTasks[taskId].data[3] = gTasks[taskId].data[2];
	gTasks[taskId].data[1] -= gTasks[taskId].data[4];
	gTasks[taskId].data[2] += gTasks[taskId].data[3];

	//When blend weight runs out, set final blend and quit
	if (gTasks[taskId].data[1] <= 0) {
		SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, gTasks[taskId].data[1]));
		return TRUE;
	}
	//Set intermediate blend state
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1],
	                MAX_FADE_INTENSITY - gTasks[taskId].data[1]));
	return FALSE;
}

static void PrepareFadeIn(u8 taskId)
{
	SetGpuRegBaseForFade();
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0,
	                MAX_FADE_INTENSITY));
	InitFadeVariables(taskId, MIN_FADE_INTENSITY, 0, 1, 2);
}

static bool8 HandleFadeIn(u8 taskId)
{
	//Set the timer, ncrease the fade weight by the delta,
	gTasks[taskId].data[3] = gTasks[taskId].data[2];
	gTasks[taskId].data[1] += gTasks[taskId].data[4];

	//When blend weight reaches max, set final blend and quit
	if (gTasks[taskId].data[1] >= MAX_FADE_INTENSITY) {
		SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(MAX_FADE_INTENSITY,
		                MIN_FADE_INTENSITY));
		return TRUE;
	}
	//Set intermediate blend state
	SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(gTasks[taskId].data[1],
	                MAX_FADE_INTENSITY - gTasks[taskId].data[1]));
	return FALSE;
}

static void Task_FadeOut(u8 taskId)
{
	if (HandleFadeOut(taskId)) {
		PrepareFadeIn(taskId);
		Task_QuestMenuCleanUp(taskId);
		gTasks[taskId].func = Task_FadeIn;
	}
}

static void Task_FadeIn(u8 taskId)
{
	if (HandleFadeIn(taskId)) {
		gTasks[taskId].func = Task_Main;
	}
}

static void Task_QuestMenuWaitFadeAndBail(u8 taskId)
{
	if (!gPaletteFade.active) {
		SetMainCallback2(sListMenuState.savedCallback);
		FreeResources();
		DestroyTask(taskId);
	}
}

static void FadeAndBail(void)
{
	BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
	CreateTask(Task_QuestMenuWaitFadeAndBail, 0);
	SetVBlankCallback(VBlankCB);
	SetMainCallback2(MainCB);
}


#define try_free(ptr) ({        \
		void ** ptr__ = (void **)&(ptr);   \
		if (*ptr__ != NULL)                \
			Free(*ptr__);                  \
	})

static void FreeResources(void)
{
	int i;

	try_free(sStateDataPtr);
	try_free(sBg1TilemapBuffer);
	try_free(sListMenuItems);

	for (i = QUEST_ARRAY_COUNT; i > -1; i--) {
		try_free(questNameArray[i]);
	}

	try_free(questNameArray);
	FreeAllWindowBuffers();
}

void TurnOffQuestMenu(u8 taskId)
{
	SetInitializedFlag(0);
	gTasks[taskId].func = Task_QuestMenuTurnOff1;
}
static void Task_QuestMenuTurnOff1(u8 taskId)
{
	BeginNormalPaletteFade(0xFFFFFFFF, 0, 0, 16, RGB_BLACK);
	gTasks[taskId].func = Task_QuestMenuTurnOff2;
}

static void Task_QuestMenuTurnOff2(u8 taskId)
{
	s16 *data = gTasks[taskId].data;

	if (!gPaletteFade.active) {
		DestroyListMenuTask(data[0], &sListMenuState.scroll, &sListMenuState.row);
		if (sStateDataPtr->savedCallback != NULL) {
			SetMainCallback2(sStateDataPtr->savedCallback);
		} else {
			SetMainCallback2(sListMenuState.savedCallback);
		}

		QuestMenu_RemoveScrollIndicatorArrowPair();
		FreeResources();
		DestroyTask(taskId);
	}
}

void Task_QuestMenu_OpenFromStartMenu(u8 taskId)
{
	s16 *data = gTasks[taskId].data;
	if (!gPaletteFade.active) {
		CleanupOverworldWindowsAndTilemaps();
		QuestMenu_Init(tItemPcParam, CB2_ReturnToUIMenu); //CB2_ReturnToFieldWithOpenMenu
		DestroyTask(taskId);
	}
}

void QuestMenu_CopyQuestName(u8 *dst, u8 questId)
{
	StringCopy(dst, sSideQuests[questId].name);
}

void QuestMenu_CopySubquestName(u8 *dst, u8 parentId, u8 childId)
{
	StringCopy(dst, sSideQuests[parentId].subquests[childId].name);
}

void QuestMenu_ResetMenuSaveData(void)
{
	memset(&gSaveBlock2Ptr->savedQuestMode, 0,
	       sizeof(gSaveBlock2Ptr->savedQuestMode));
	memset(&gSaveBlock2Ptr->questData, 0,
	       sizeof(gSaveBlock2Ptr->questData));
	memset(&gSaveBlock2Ptr->subQuests, 0,
	       sizeof(gSaveBlock2Ptr->subQuests));
}
