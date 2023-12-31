#include "global.h"
#include "battle.h"
#include "constants/trainers.h"
#include "battle_anim.h"
#include "battle_setup.h"
#include "constants/moves.h"
#include "constants/abilities.h"
#include "pokedex.h"
#include "event_object_movement.h"
#include "event_data.h"
#include "fieldmap.h"
#include "item.h"
#include "malloc.h"
#include "mazegen.h"
#include "quests.h"
#include "money.h"
#include "party_menu.h"
#include "../gflib/string_util.h"
#include "quest_logic.h"
#include "hidden_grotto.h"
#include "overworld.h"
#include "random.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/map_groups.h"
#include "constants/sound.h"
#include "field_control_avatar.h"
#include "battle_main.h"
#include "script_pokemon_util.h"
#include "sound.h"
#include "strings.h"
#include "constants/region_map_sections.h"
#include "region_map.h"

u32 GetCurrentMap(void)
{
    u32 currentMapGroup = gSaveBlock1Ptr->location.mapGroup;
    u32 currentMapNum = gSaveBlock1Ptr->location.mapNum;

    return (currentMapNum | (currentMapGroup << 8));
}

u16 Quest_Generic_CountRemainingSubquests(u16 relevantQuest)
{
    u16 numRemainingQuests = sSideQuests[relevantQuest].numSubquests;
    u16 totalNumSubquests = numRemainingQuests;
    u8 currentSubQuest;

    for (currentSubQuest = 0; currentSubQuest < totalNumSubquests; currentSubQuest++)
    {
        if (QuestMenu_GetSetSubquestState(relevantQuest, FLAG_GET_COMPLETED, currentSubQuest))
        {
            numRemainingQuests--;
        }
    }

    gSpecialVar_Result = numRemainingQuests;
    ConvertIntToDecimalStringN(gStringVar1, numRemainingQuests, STR_CONV_MODE_LEFT_ALIGN, 2);
    return numRemainingQuests;
}

void Quest_Generic_CompleteSubquests(u16 relevantQuest)
{
    u16 totalNumSubquests = sSideQuests[relevantQuest].numSubquests;
    u8 currentSubQuest;

    for (currentSubQuest = 0; currentSubQuest < totalNumSubquests; currentSubQuest++)
    {
        QuestMenu_GetSetSubquestState(relevantQuest, FLAG_SET_COMPLETED, currentSubQuest);
    }
}

// ***********************************************************************
// Quest: Kitchen Volunteering
// ***********************************************************************

void Quest_Kitchenvolunteering_GeneratePantryItem(void);
static void Quest_Kitchenvolunteering_CompleteSubQuest(void);
void Quest_Kitchenvolunteering_CheckProgressAndSetReward(void);
void Quest_Kitchenvolunteering_ChooseRandomPantryItem(void);
static void Quest_Kitchenvolunteering_RestoreChosenPantryItem(void);

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
    return Quest_Generic_CountRemainingSubquests(QUEST_ROCKCOLLECTOR);
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
// ***********************************************************************
static const u32 GROTTO_SUBQUEST_MAP[NUM_GROTTO_ROUTES][2]=
{
    {MAP_PSFROUTE1_GROTTO,SUB_QUEST_1},
    {MAP_PSFROUTE30_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE9_GROTTO,SUB_QUEST_1},
    {MAP_PSFROUTE70_GROTTO,SUB_QUEST_1},
    {MAP_PSFROUTE17_GROTTO,SUB_QUEST_3},
    {MAP_PSFROUTE22_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE20_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE49_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE38_GROTTO,SUB_QUEST_1},
    {MAP_PSFROUTE14_GROTTO,SUB_QUEST_1},
    {MAP_PSFROUTE21_GROTTO,SUB_QUEST_3},
    {MAP_PSFROUTE7_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE63_GROTTO,SUB_QUEST_3},
    {MAP_PSFROUTE11_GROTTO,SUB_QUEST_3},
    {MAP_PSFROUTE32_GROTTO,SUB_QUEST_5},
    {MAP_PSFROUTE62_GROTTO,SUB_QUEST_5},
    {MAP_PSFROUTE76_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE72_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE18_GROTTO,SUB_QUEST_1},
    {MAP_PSFROUTE61_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE43_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE5_GROTTO,SUB_QUEST_4},
    {MAP_PSFROUTE15_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE51_GROTTO,SUB_QUEST_2},
    {MAP_PSFROUTE8_GROTTO,SUB_QUEST_3},
    {MAP_PSFROUTE13_GROTTO,SUB_QUEST_3},
};

void Quest_Hiddengrottomapping_MarkSubquestBiome(void) {
    u32 subquest = 0;
    bool8 foundGrotto = FALSE;
    u8 i;

    for (i = 0; i < NUM_GROTTO_ROUTES; i++) {
        if (GROTTO_SUBQUEST_MAP[i][0] == GetCurrentMap()) {
            subquest = GROTTO_SUBQUEST_MAP[i][1];
            foundGrotto = TRUE;
            break;
        }
    }

    if (foundGrotto) {
        if (!QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING, FLAG_GET_COMPLETED, subquest)) {
            QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING, FLAG_SET_COMPLETED, subquest);
        }
    }
}

u16 Quest_Hiddengrottomapping_CountCompletedSubquests(void){
    return Quest_Generic_CountRemainingSubquests(QUEST_HIDDENGROTTOMAPPING);
}


bool8 Quest_Hiddengrottomapping_CheckSubquestsForReward(void){
    u8 i;
    bool8 allSubquestsComplete = TRUE;

    return (Quest_Hiddengrottomapping_CountCompletedSubquests() == QUEST_HIDDENGROTTOMAPPING_SUB_COUNT);
}

// ***********************************************************************
// Quest: Hidden Grotto Mapping 2
// ***********************************************************************

u16 Quest_Hiddengrottomapping2_CountCompletedSubquests(void){
    return Quest_Generic_CountRemainingSubquests(QUEST_HIDDENGROTTOMAPPING2);
}

bool8 Quest_Hiddengrottomapping2_CheckForJournalPage(void){
    u16 currentJournalPage;
    bool8 hasJournalPages = FALSE;
    u8 i;

    for (i = 0; i < QUEST_HIDDENGROTTOMAPPING2_SUB_COUNT; i++){
        currentJournalPage = ITEM_PANNEN_JOURNAL_PAGE_1 + i;

        if (CheckBagHasItem(currentJournalPage,1)){
            RemoveBagItem(currentJournalPage,1);
            QuestMenu_GetSetSubquestState(QUEST_HIDDENGROTTOMAPPING2,FLAG_SET_COMPLETED,i);
            hasJournalPages = TRUE;
        }
    }
    return hasJournalPages;
}

// ***********************************************************************
// Quest: Ultra Wormhole Research
// ***********************************************************************

#define BEAST  0
#define TOTEM  1
#define NUM_TOTEM_MON (QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT - 1)

static const u32 TOTEM_POKEMON_LIST[NUM_TOTEM_MON][9]=
{
    {MAP_PSFROUTE14, SPECIES_TYROGUE, ITEM_FOCUS_BAND, 3, 6, 5, 2, 1, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 1)},
    {MAP_PSFROUTE62, SPECIES_AMPHAROS, ITEM_LEFTOVERS, 0, 4, 2, 6, 5, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 2)},
    {MAP_PSFROUTE30, SPECIES_SCYTHER, ITEM_SILVER_POWDER, 5, 2, 3, 1, 0, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 3)},
    {MAP_PSFROUTE15, SPECIES_POLITOED, ITEM_DAMP_ROCK, 1, 5, 6, 4, 2, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 4)},
    {MAP_PSFROUTE17, SPECIES_KINGLER, ITEM_MYSTIC_WATER, 6, 3, 1, 0, 4, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 5)},
    {MAP_PSFROUTE22, SPECIES_MUNCHLAX, ITEM_LEFTOVERS, 2, 0, 4, 5, 6, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 6)},
    {MAP_PSFROUTE61, SPECIES_SKARMORY, ITEM_ROCKY_HELMET, 6, 2, 1, 3, 5, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 7)},
    {MAP_PSFROUTE49, SPECIES_GARCHOMP, ITEM_CHOICE_SCARF, 4, 3, 0, 6, 1, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 8)},
    {MAP_PSFROUTE38, SPECIES_DUSKNOIR, ITEM_SPELL_TAG, 1, 4, 6, 2, 3, (FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 9)},
};
    //PSF TODO need to make new totem formes
    //totem formes have larger heights and weights but don't follow any specific rule
    //shiny locked off
    //when bred, produces a normal species of that pokemon
    //always have one specific ability
    //spawn with three perfect IVs
    //Compared to their non-Totem counterparts, every Totem Pokémon's weight is increased less than appropriately to its height. If a Pokémon's density were to remain the same between its Totem and non-Totem variants, a Totem Pokémon twice the height should be eight times the weight.
    //Not a unique form in the pokedex
    //fixed natures and move sets and level
    //wild map, totem species, held item, totem atk, totem def, totem speed, totem spatk, totem spdef, totem flag

static const u32 ULTRA_BEAST_LIST[QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT][9]=
{
    {MAP_ULTRA_PALDEA,SPECIES_POIPOLE,ITEM_BEAST_BALL,3,1,6,5,0},
    {MAP_ULTRA_UNOVA,SPECIES_PHEROMOSA,ITEM_BEAST_BALL,6,4,0,5,2},
    {MAP_ULTRA_ORRE,SPECIES_GUZZLORD,ITEM_BEAST_BALL,1,2,5,4,6},
    {MAP_ULTRA_SINNOH,SPECIES_BLACEPHALON,ITEM_BEAST_BALL,0,3,6,2,1},
    {MAP_ULTRA_HOENN,SPECIES_CELESTEELA,ITEM_BEAST_BALL,2,4,1,6,5},
    {MAP_ULTRA_ALOLA,SPECIES_BUZZWOLE,ITEM_BEAST_BALL,3,0,2,6,1},
    {MAP_ULTRA_KALOS,SPECIES_STAKATAKA,ITEM_BEAST_BALL,0,4,4,1,6},
    {MAP_ULTRA_JOHTO,SPECIES_NIHILEGO,ITEM_BEAST_BALL,5,3,2,0,1},
    {MAP_ULTRA_GALAR,SPECIES_KARTANA,ITEM_BEAST_BALL,1,6,5,0,4},
    {MAP_ULTRA_KANTO,SPECIES_XURKITREE,ITEM_BEAST_BALL,6,3,0,4,2},
};

bool8 Quest_Ultrawormholeresearch_ShouldTotemNotSpawn(void) {
    u16 totemFlag = FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 1;
    u8 i;

    if (!QuestMenu_GetSetQuestState(QUEST_ULTRAWORMHOLERESEARCH, FLAG_GET_ACTIVE)) {
        return TRUE;
    }

    for (i = 0; i < NUM_TOTEM_MON; i++) {
        if (TOTEM_POKEMON_LIST[i][0] == GetCurrentMap() && FlagGet(totemFlag + i)) {
            return TRUE;
        }
    }

    return FALSE;
}

void Quest_Ultrawormholeresearch_PlayTotemCry(void) {
    u8 i;

    for (i = 0; i < NUM_TOTEM_MON ; i++) {
        if (TOTEM_POKEMON_LIST[i][0] == GetCurrentMap()) {
            PlayCry_Script(TOTEM_POKEMON_LIST[i][1], CRY_MODE_ENCOUNTER);
            break;
        }
    }
}

void Quest_Ultrawormholeresearch_SetTotemBoost(u8 type, u8 i) {
    const u32* boostList;
    u8 j;

    if (type == TOTEM) {
        boostList = &TOTEM_POKEMON_LIST[i][2];
    } else if (type == BEAST) {
        boostList = &ULTRA_BEAST_LIST[i][2];
    } else {
    }

    gSpecialVar_0x8000 = B_POSITION_OPPONENT_LEFT;
    for (j = 0; j < 5; j++) {
        *(&gSpecialVar_0x8001 + j) = boostList[j];
    }

    SetTotemBoost();
}

void Quest_Ultrawormholeresearch_SetTotemBattle(void) {
    u16 totemMon, totemHeldItem;
    u8 i;
    u32 mapId = GetCurrentMap();

    for (i = 0; i < NUM_TOTEM_MON; i++) {
        if (TOTEM_POKEMON_LIST[i][0] == mapId) {
            totemMon = TOTEM_POKEMON_LIST[i][1];
            totemHeldItem = TOTEM_POKEMON_LIST[i][2];

            CreateScriptedWildMon(totemMon, 100, totemHeldItem);
            Quest_Ultrawormholeresearch_SetTotemBoost(TOTEM, i);
            return;
        }
    }
}

void Quest_Ultrawormholeresearch_SetDefeatedTotemFlag(void) {
    u8 i;
    u16 totemFlag = FLAG_QUEST_ULTRAWORMHOLE_FIRST_TOTEM + 1;
    u32 mapId = GetCurrentMap();

    for (i = 0; i < NUM_TOTEM_MON; i++) {
        if (TOTEM_POKEMON_LIST[i][0] == mapId) {
            FlagSet(totemFlag + i);
            return;
        }
    }
}

u32 Quest_Ultrawormholeresearch_BufferTotemPokemonName(void){
    u8 i;

    for (i = 0; i < NUM_TOTEM_MON; i++) {
        if (TOTEM_POKEMON_LIST[i][0] == GetCurrentMap()) {
            return TOTEM_POKEMON_LIST[i][1];
        }
    }
}

void Quest_Ultrawormholeresearch_PlayUltraBeastCry(void) {
    u8 i;

    for (i = 0; i < QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT; i++) {
        if (ULTRA_BEAST_LIST[i][0] == GetCurrentMap()) {
            PlayCry_Script(ULTRA_BEAST_LIST[i][1], CRY_MODE_ENCOUNTER);
            break;
        }
    }
}

void Quest_Ultrawormholeresearch_SetUltraBeastBattle(void){
    u16 ultraBeastMon, ultraBeastHeldItem;
    u8 i;

    for (i = 0; i < QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT; i++) {
        if (ULTRA_BEAST_LIST[i][0] == GetCurrentMap()) {

            ultraBeastMon = ULTRA_BEAST_LIST[i][1];
            ultraBeastHeldItem = ULTRA_BEAST_LIST[i][2];

            CreateScriptedWildMon(ultraBeastMon,100,ultraBeastHeldItem);
            Quest_Ultrawormholeresearch_SetTotemBoost(BEAST,i);
            break;
        }
    }
}

u32 Quest_Ultrawormholeresearch_BufferUltraBeastPokemonName(void){
    u8 i;

    for (i = 0; i < QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT; i++) {
        if (ULTRA_BEAST_LIST[i][0] == GetCurrentMap()) {
            return ULTRA_BEAST_LIST[i][1];
        }
    }
}

void Quest_Ultrawormholeresearch_SetSubquestForUltraBeast(void){
    u8 i;

    for (i = 0; i < QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT; i++) {
        if (ULTRA_BEAST_LIST[i][0] == GetCurrentMap()) {
            QuestMenu_GetSetSubquestState(QUEST_ULTRAWORMHOLERESEARCH,FLAG_SET_COMPLETED,i);
            break;
        }
    }
}

u16 Quest_Ultrawormholeresearch_CountRemainingSubquests(void){
    return Quest_Generic_CountRemainingSubquests(QUEST_ULTRAWORMHOLERESEARCH);
}

// ***********************************************************************
// Quest: Gem Artist
// ***********************************************************************

u8 Quest_Gemartist_GetMonFirstMoveType(void)
{
    u16 firstMove = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MOVE1, NULL);
    u16 selectedSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES, NULL);
    return gBattleMoves[firstMove].type;
}

void Quest_Gemartist_BufferFirstMoveName(void)
{
    u16 selectedSpecies = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES, NULL);
    u16 firstMove = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_MOVE1, NULL);

    gSpecialVar_0x8000 = selectedSpecies;
    gSpecialVar_0x8001 = firstMove;

            switch(Quest_Gemartist_GetMonFirstMoveType()){
            case TYPE_NORMAL: gSpecialVar_0x8003 = ITEM_NORMAL_GEM;
			break;
            case TYPE_FIGHTING: gSpecialVar_0x8003 = ITEM_FIGHTING_GEM;
			break;
            case TYPE_FLYING: gSpecialVar_0x8003 = ITEM_FLYING_GEM;
			break;
            case TYPE_POISON: gSpecialVar_0x8003 = ITEM_POISON_GEM;
			break;
            case TYPE_GROUND: gSpecialVar_0x8003 = ITEM_GROUND_GEM;
			break;
            case TYPE_ROCK: gSpecialVar_0x8003 = ITEM_ROCK_GEM;
			break;
            case TYPE_BUG: gSpecialVar_0x8003 = ITEM_BUG_GEM;
			break;
            case TYPE_GHOST: gSpecialVar_0x8003 = ITEM_GHOST_GEM;
			break;
            case TYPE_STEEL: gSpecialVar_0x8003 = ITEM_STEEL_GEM;
			break;
            case TYPE_FIRE: gSpecialVar_0x8003 = ITEM_FIRE_GEM;
			break;
            case TYPE_WATER: gSpecialVar_0x8003 = ITEM_WATER_GEM;
			break;
            case TYPE_GRASS: gSpecialVar_0x8003 = ITEM_GRASS_GEM;
			break;
            case TYPE_ELECTRIC: gSpecialVar_0x8003 = ITEM_ELECTRIC_GEM;
			break;
            case TYPE_PSYCHIC: gSpecialVar_0x8003 = ITEM_PSYCHIC_GEM;
			break;
            case TYPE_ICE: gSpecialVar_0x8003 = ITEM_ICE_GEM;
			break;
            case TYPE_DRAGON: gSpecialVar_0x8003 = ITEM_DRAGON_GEM;
			break;
            case TYPE_DARK: gSpecialVar_0x8003 = ITEM_DARK_GEM;
			break;
            case TYPE_FAIRY: gSpecialVar_0x8003 = ITEM_FAIRY_GEM;
			break;
        }
}

void Quest_Gemartist_SetGemFlag(void)
{
    u16 type = gSpecialVar_Result;

    if (type > TYPE_STEEL){
        --type;
    }
    FlagSet(type + FLAG_CRAFTED_FIRST_GEM);
}

u8 Quest_Gemartist_CountRemainingUniqueGems(void)
{
    u16 numRemainingGems = NUMBER_OF_MON_TYPES - 1;
    u16 maxNumberGems = numRemainingGems;
    u16 currentFlag = FLAG_CRAFTED_FIRST_GEM;
    u8 i;

    for (i = 0; i < maxNumberGems; i++)
    {
        if (FlagGet(currentFlag+i)){
            --numRemainingGems;
        }
    }
    return numRemainingGems;
}

// ***********************************************************************
// Quest: Taxicabturnaround
// ***********************************************************************

#define SEA 0
#define SKY 1
#define LAND 2

static const u32 TAXICAB_LOCATION_MAP[QUEST_TAXICABTURNAROUND_SUB_COUNT][3]=
{
    {MAP_TREASUREISLAND,SUB_QUEST_1,SEA},
    {MAP_SUNSET,SUB_QUEST_2,SEA},
    {MAP_GLDNGTEPARK,SUB_QUEST_3,SEA},
    {MAP_PRESIDIO,SUB_QUEST_4,SEA},
    {MAP_PACIFICA,SUB_QUEST_5,SEA},
    {MAP_ALAMEDA,SUB_QUEST_6,SEA},
    {MAP_CASTRO,SUB_QUEST_7,SKY},
    {MAP_MISSION,SUB_QUEST_8,SKY},
    {MAP_DOGPATCH,SUB_QUEST_9,SKY},
    {MAP_SOUTHBAY,SUB_QUEST_10,SKY},
    {MAP_OAKLAND,SUB_QUEST_11,SKY},
    {MAP_HAIGHTASHBURY,SUB_QUEST_12,SKY},
    {MAP_MARIN,SUB_QUEST_13,LAND},
    {MAP_BERKELEY,SUB_QUEST_14,LAND},
    {MAP_TENDERLOIN,SUB_QUEST_15,LAND},
    {MAP_CHINATOWN,SUB_QUEST_16,LAND},
    {MAP_JAPANTOWN,SUB_QUEST_17,LAND},
    {MAP_SOMA,SUB_QUEST_18,LAND},
    {MAP_BERNALHEIGHTS,SUB_QUEST_19,LAND},
};

u8 Quest_Taxicabturnaround_LookUpCorrespondingSubquest(void){
    u8 i;

    for (i = 0; i < QUEST_TAXICABTURNAROUND_SUB_COUNT; i++) {
        if (TAXICAB_LOCATION_MAP[i][0] == GetCurrentMap()) {
            return i;
        }
    }
    return 99;
}

u8 Quest_Taxicabturnaround_LookUpQuestType(void)
{
    u8 index = Quest_Taxicabturnaround_LookUpCorrespondingSubquest();
    return TAXICAB_LOCATION_MAP[index][2];
}

bool8 Quest_Taxicabturnaround_IsSubquestComplete(void){
    u8 index = Quest_Taxicabturnaround_LookUpCorrespondingSubquest();
    u8 subquest = TAXICAB_LOCATION_MAP[index][1];

    if (QuestMenu_GetSetSubquestState(QUEST_TAXICABTURNAROUND, FLAG_GET_COMPLETED, subquest)){
        return TRUE;
    }else{
        return FALSE;
    }
}

bool8 Quest_Taxicabturnaround_CheckSeaPokemon(void){
    //1.1m and can learn surf
    u32 species = 0, height = 0;
    u32 requiredHeight = 11;
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);

    height = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(species), 0);

    if ((!CanLearnTeachableMove(species,MOVE_SURF)) || (height < requiredHeight)){

        doesPokemonMatch = FALSE;
    }

    return doesPokemonMatch;
}

bool8 Quest_Taxicabturnaround_CheckSkyPokemon(void){
    //80 base speed and can learn fly
    u32 species = 0, speed = 0;
    u32 requiredSpeed= 80;
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);

    speed = gSpeciesInfo[species].baseSpeed;

    if ((!CanLearnTeachableMove(species,MOVE_FLY)) || (speed < requiredSpeed)){

        doesPokemonMatch = FALSE;
    }

    return doesPokemonMatch;
}

bool8 Quest_Taxicabturnaround_CheckLandPokemon(void){
    //32kg and field egg group
    u32 species = 0, weight = 0;
    u32 requiredWeight = 320;
    u32 eggGroup[2] = {0,0};
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);
    eggGroup[0] = gSpeciesInfo[species].eggGroups[0];
    eggGroup[1] = gSpeciesInfo[species].eggGroups[1];

    weight = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(species), 1);

    if (((eggGroup[0] != EGG_GROUP_FIELD) && (eggGroup[1] != EGG_GROUP_FIELD)) || (weight < requiredWeight)){
        doesPokemonMatch = FALSE;
    }

    return doesPokemonMatch;
}

bool8 Quest_Taxicabturnaround_CheckRequiredPokemon(void){
    u8 index = Quest_Taxicabturnaround_LookUpCorrespondingSubquest();
    u8 neededType = TAXICAB_LOCATION_MAP[index][2];

    switch(neededType){
        case SEA:
            return Quest_Taxicabturnaround_CheckSeaPokemon();
        case SKY:
            return Quest_Taxicabturnaround_CheckSkyPokemon();
        case LAND:
            return Quest_Taxicabturnaround_CheckLandPokemon();
        default:
            return FALSE;
    }
}

void Quest_Taxicabturnaround_MarkSubquestComplete(void){
    u32 subquest = 0;
    bool8 foundTaxi = FALSE;
    u8 i;

    for (i = 0; i < QUEST_TAXICABTURNAROUND_SUB_COUNT; i++) {
        if (TAXICAB_LOCATION_MAP[i][0] == GetCurrentMap()) {
            subquest = TAXICAB_LOCATION_MAP[i][1];
            foundTaxi = TRUE;
            break;
        }
    }

    if (foundTaxi) {
        if (!QuestMenu_GetSetSubquestState(QUEST_TAXICABTURNAROUND, FLAG_GET_COMPLETED, subquest)) {
            QuestMenu_GetSetSubquestState(QUEST_TAXICABTURNAROUND, FLAG_SET_COMPLETED, subquest);
        }
    }
}

u16 Quest_Taxicabturnaround_CountRemainingSubquests(void){
    return Quest_Generic_CountRemainingSubquests(QUEST_TAXICABTURNAROUND);
}

bool8 Quest_Taxicabturnaround_CheckReadyForNext(void){
    u16 numRemainingQuests = QUEST_TAXICABTURNAROUND_SUB_COUNT;
    u8 currentSubQuest;
    u8 questType;
    u8 completedLand = 0, completedSky = 0, completedSea = 0;
    u8 requiredComplete = 1;

    for (currentSubQuest = 0; currentSubQuest < QUEST_TAXICABTURNAROUND_SUB_COUNT; currentSubQuest++)
    {
        if (QuestMenu_GetSetSubquestState(QUEST_TAXICABTURNAROUND, FLAG_GET_COMPLETED, currentSubQuest))
        {
            questType = TAXICAB_LOCATION_MAP[currentSubQuest][2];

            switch(questType){
                case LAND: completedLand++;
                           break;
                case SEA: completedSea++;
                          break;
                case SKY: completedSky++;
                          break;
                default: break;
            }
        }
    }

    return (\
            (completedLand > requiredComplete) &&\
            (completedSky > requiredComplete) &&\
            (completedSea > requiredComplete)\
           );
}

// ***********************************************************************
// Quest: Bodega Burnout
// ***********************************************************************

#define DELIVER 0
#define RESCUE 1
#define CATCH_STRONG 2
#define CATCH_COLD  3
#define CATCH_SMART 4
#define CATCH_FAIRY 5

static const u32 POKE_MART_MAP[QUEST_BODEGABURNOUT_SUB_COUNT][4]=
{
    {MAP_SOMA_POKEMONCENTER_1F,SUB_QUEST_1,DELIVER,MAP_PSFROUTE17},
    {MAP_SUNSET_POKEMONCENTER_1F,SUB_QUEST_2,DELIVER,MAP_TWINPEAKS},
    {MAP_GLDNGTEPARK_POKEMONCENTER_1F,SUB_QUEST_3,DELIVER,MAP_PSFROUTE18},
    {MAP_TENDERLOIN_POKEMONCENTER_1F,SUB_QUEST_4,DELIVER,MAP_ALCATRAZ},
    {MAP_PACIFICA_POKEMONCENTER_1F,SUB_QUEST_5,DELIVER,MAP_TENDERLOIN},
    {MAP_BERNALHEIGHTS_POKEMONCENTER_1F,SUB_QUEST_6,DELIVER,MAP_SOMA},

    {MAP_DOGPATCH_POKEMONCENTER_1F,SUB_QUEST_7,RESCUE,MAP_PSFROUTE13},
    {MAP_MISSION_POKEMONCENTER_1F,SUB_QUEST_8,RESCUE,MAP_PSFROUTE8},
    {MAP_CHINATOWN_POKEMONCENTER_1F,SUB_QUEST_9,RESCUE,MAP_CHINATOWN},
    {MAP_JAPANTOWN_POKEMONCENTER_1F,SUB_QUEST_10,RESCUE,MAP_PSFROUTE9},
    {MAP_CASTRO_POKEMONCENTER_1F,SUB_QUEST_11,RESCUE,MAP_PSFROUTE1},
    {MAP_PRESIDIO_POKEMONCENTER_1F,SUB_QUEST_12,RESCUE,MAP_PSFROUTE30},

    {MAP_OAKLAND_POKEMONCENTER_1F,SUB_QUEST_13,CATCH_STRONG,},
    {MAP_MARIN_POKEMONCENTER_1F,SUB_QUEST_14,CATCH_STRONG,},
    {MAP_HAIGHTASHBURY_POKEMONCENTER_1F,SUB_QUEST_15,CATCH_COLD,},
    {MAP_TREASUREISLAND_POKEMONCENTER_1F,SUB_QUEST_16,CATCH_COLD,},
    {MAP_SOUTHBAY_POKEMON_CENTER_1F,SUB_QUEST_17,CATCH_SMART,},
    {MAP_ALAMEDA_POKEMONCENTER_1F,SUB_QUEST_18,CATCH_SMART,},
    {MAP_BERKELEY_POKEMONCENTER_1F,SUB_QUEST_19,CATCH_FAIRY,},
};

static const u8* const bodegaParametersTextArray[19][2]=
{
    {gText_Bodegaburnout_PersonA,gText_Psfroute17},
    {gText_Bodegaburnout_PersonB,gText_Twinpeaks},
    {gText_Bodegaburnout_PersonC,gText_Psfroute18},
    {gText_Bodegaburnout_PersonD,gText_Alcatraz},
    {gText_Bodegaburnout_PersonE,gText_Tenderloin},
    {gText_Bodegaburnout_PersonF,gText_Soma},
    {gText_Bodegaburnout_PersonG,gText_Psfroute13},
    {gText_Bodegaburnout_PersonH,gText_Psfroute8},
    {gText_Bodegaburnout_PersonI,gText_Chinatown},
    {gText_Bodegaburnout_PersonJ,gText_Psfroute9},
    {gText_Bodegaburnout_PersonK,gText_Psfroute1},
    {gText_Bodegaburnout_PersonL,gText_Psfroute30},
    {gText_Bodegaburnout_StrongMon,gText_Bodegaburnout_AssistWithStocking},
    {gText_Bodegaburnout_StrongMon,gText_Bodegaburnout_AssistWithStocking},
    {gText_Bodegaburnout_ColdMon,gText_Bodegaburnout_HelpKeepFood},
    {gText_Bodegaburnout_ColdMon,gText_Bodegaburnout_HelpKeepFood},
    {gText_Bodegaburnout_SmartMon,gText_Bodegaburnout_BalanceOurBooks},
    {gText_Bodegaburnout_SmartMon,gText_Bodegaburnout_BalanceOurBooks},
    {gText_Bodegaburnout_FairyMon,gText_Bodegaburnout_RaiseTheMood},
};

u8 Quest_Bodegaburnout_LookUpCorrespondingSubquest(void){
    u8 i;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][0] == GetCurrentMap()) {
            return i;
        }
    }
    return 99;
}

bool8 Quest_Bodegaburnout_IsSubquestComplete(void){
    u8 index = Quest_Bodegaburnout_LookUpCorrespondingSubquest();
    u8 subquest = POKE_MART_MAP[index][1];

    if (QuestMenu_GetSetSubquestState(QUEST_BODEGABURNOUT, FLAG_GET_COMPLETED, subquest)){
        return TRUE;
    }else{
        return FALSE;
    }
}

void Quest_Bodegaburnout_Catch_MarkSubquestComplete(void){
    u32 subquest = 0;
    bool8 foundTaxi = FALSE;
    u8 i;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][0] == GetCurrentMap()) {
            subquest = POKE_MART_MAP[i][1];
            foundTaxi = TRUE;
            break;
        }
    }

    if (foundTaxi) {
        if (!QuestMenu_GetSetSubquestState(QUEST_BODEGABURNOUT, FLAG_GET_COMPLETED, subquest)) {
            QuestMenu_GetSetSubquestState(QUEST_BODEGABURNOUT, FLAG_SET_COMPLETED, subquest);
        }
    }
}

u16 Quest_Bodegaburnout_CountRemainingSubquests(void){
    return Quest_Generic_CountRemainingSubquests(QUEST_BODEGABURNOUT);
}

bool8 Quest_Bodegaburnout_CheckReadyForNext(void){
    u16 numRemainingQuests = QUEST_BODEGABURNOUT_SUB_COUNT;
    u8 currentSubQuest;
    u8 questType;
    u8 completedDeliver = 0, completedRescue = 0, completedCatch = 0;
    u8 requiredComplete = 1;

    for (currentSubQuest = 0; currentSubQuest < QUEST_BODEGABURNOUT_SUB_COUNT; currentSubQuest++)
    {
        if (QuestMenu_GetSetSubquestState(QUEST_BODEGABURNOUT, FLAG_GET_COMPLETED, currentSubQuest))
        {
            questType = POKE_MART_MAP[currentSubQuest][2];

            switch(questType){
                case CATCH_STRONG:
                case CATCH_COLD:
                case CATCH_SMART:
                case CATCH_FAIRY:
                    completedCatch++;
                    break;
                case DELIVER: completedDeliver++;
                  break;
                case RESCUE: completedRescue++;
                 break;
                default: break;
            }
        }
    }

    return (
            (completedDeliver > requiredComplete) &&
            (completedRescue > requiredComplete) &&
            (completedCatch > requiredComplete)
           );
}

u32 Quest_Bodegaburnout_GetQuestType(void){
    u32 quest_type = 0;
    bool8 foundTaxi = FALSE;
    u8 i;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][0] == GetCurrentMap()) {
            return POKE_MART_MAP[i][2];
        }
    }
    return 99;
}

void Quest_Bodegaburnout_LoadRequestText(void){
    u8 i;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][0] == GetCurrentMap()) {
            StringCopy(gStringVar1,bodegaParametersTextArray[i][0]);
            StringCopy(gStringVar2,bodegaParametersTextArray[i][1]);
            StringCopy(gStringVar3,gText_Pokemon);
        }
    }
}

bool8 Quest_Bodegaburnout_CheckStrongPokemon(void){
    //Human-like egg group AND 18 decimeters
    u32 species = 0, height = 0;
    u32 eggGroup[2] = {0,0};
    u32 requiredHeight = 18;
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);
    eggGroup[0] = gSpeciesInfo[species].eggGroups[0];
    eggGroup[1] = gSpeciesInfo[species].eggGroups[1];
    height = GetPokedexHeightWeight(SpeciesToNationalPokedexNum(species), 0);

    if (
            (
             (eggGroup[0] != EGG_GROUP_HUMAN_LIKE) &&
             (eggGroup[1] != EGG_GROUP_HUMAN_LIKE)
            )
            ||
            (height < requiredHeight)
       )
            {
                doesPokemonMatch = FALSE;
            }
    return doesPokemonMatch;
}

bool8 Quest_Bodegaburnout_CheckColdPokemon(void){
    u32 species = 0;
    u32 type[2] = {0,0};
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);
    type[0] = gSpeciesInfo[species].types[0];
    type[1] = gSpeciesInfo[species].types[1];

        if (
             (type[0] != TYPE_ICE) &&
             (type[1] != TYPE_ICE)
           )
            {
                doesPokemonMatch = FALSE;
            }
    return doesPokemonMatch;
}

bool8 Quest_Bodegaburnout_CheckSmartPokemon(void){
    //Pokemon that like Bitter food have an easier time becoming Smart in Contest Data, so only pokemon that like bitter flavors
    u32 species = 0, nature = 0;
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);
    nature = GetNature(&gPlayerParty[gSpecialVar_0x8004]);

    if (
        (nature != NATURE_GENTLE) &&
        (nature != NATURE_SASSY) &&
        (nature != NATURE_CALM) &&
        (nature != NATURE_CAREFUL)
       )
    {
        doesPokemonMatch = FALSE;
    }

    return doesPokemonMatch;
}

bool8 Quest_Bodegaburnout_CheckFairyPokemon(void){
    u32 species = 0;
    u32 eggGroup[2] = {0,0};
    u32 type[2] = {0,0};
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);
    eggGroup[0] = gSpeciesInfo[species].eggGroups[0];
    eggGroup[1] = gSpeciesInfo[species].eggGroups[1];
    type[0] = gSpeciesInfo[species].types[0];
    type[1] = gSpeciesInfo[species].types[1];

        if (
             (eggGroup[0] != EGG_GROUP_FAIRY) &&
             (eggGroup[1] != EGG_GROUP_FAIRY)
             &&
             (type[0] != TYPE_FAIRY) &&
             (type[1] != TYPE_FAIRY)
           )
            {
                doesPokemonMatch = FALSE;
            }
    return doesPokemonMatch;
}

bool8 Quest_Bodegaburnout_CheckRequiredPokemon(void){
    u8 index = Quest_Bodegaburnout_LookUpCorrespondingSubquest();
    u8 neededType = POKE_MART_MAP[index][2];

    switch(neededType){
        case CATCH_STRONG:
            return Quest_Bodegaburnout_CheckStrongPokemon();
        case CATCH_COLD:
            return Quest_Bodegaburnout_CheckColdPokemon();
        case CATCH_SMART:
            return Quest_Bodegaburnout_CheckSmartPokemon();
        case CATCH_FAIRY:
            return Quest_Bodegaburnout_CheckFairyPokemon();
        default:
            return FALSE;
    }
}

bool8 Quest_Bodegaburnout_CheckLocationAndMatchItem(void){
    u8 i;
    u16 bodegaPackage = ITEM_BODEGA_DELIVERY_FIRST;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][0] == GetCurrentMap()) {
            bodegaPackage += i;
            gSpecialVar_0x8000 = bodegaPackage;
            gSpecialVar_0x8001 = 1;
            break;
        }
    }
    return CheckBagHasItem(bodegaPackage,1);
}


u8 Quest_Bodegaburnout_GetIndexFirstRescue(void){
    u8 i;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][2] == RESCUE){
            break;
        }
    }
    return i;
}

void Quest_Bodegaburnout_CheckAndSetRescueFlag(void){
    u8 j, k = 0;
    u16 rescueFlag = FLAG_QUEST_BODEGA_RESCUE_FLAGS_START;
    bool8 flagStatus;
    bool8 questStatus = QuestMenu_GetSetQuestState(QUEST_BODEGABURNOUT, FLAG_GET_ACTIVE);

    for (j = Quest_Bodegaburnout_GetIndexFirstRescue(); j < QUEST_BODEGABURNOUT_SUB_COUNT; j++) {
        if (POKE_MART_MAP[k][3] == GetCurrentMap()) {
            rescueFlag += k;

            flagStatus = FlagGet(rescueFlag);
            if (!flagStatus && !questStatus){
                FlagSet(rescueFlag);
                FlagSet(FLAG_QUEST_BODEGA_RESCUE1); //PSF TODO Is this a debug line?
            }
            break;
        }
        k++;
    }
}

void Quest_Bodegaburnout_ClearRescueFlag(void){
    u8 j, k = 0;
    u16 rescueFlag = FLAG_QUEST_BODEGA_RESCUE_FLAGS_START;

    for (j = Quest_Bodegaburnout_GetIndexFirstRescue(); j < QUEST_BODEGABURNOUT_SUB_COUNT; j++) {
        if (POKE_MART_MAP[j][0] == GetCurrentMap()) {
            rescueFlag += k;

            if (FlagGet(rescueFlag)){
                FlagClear(rescueFlag);
            }
            break;
        }
        k++;
    }
}

void Quest_Bodegaburnout_DeliveryRescue_MarkSubquestCompleteAndRemoveItem(void){
    u8 i;
    u16 bodegaPackage = ITEM_BODEGA_DELIVERY_FIRST;

    for (i = 0; i < QUEST_BODEGABURNOUT_SUB_COUNT; i++) {
        if (POKE_MART_MAP[i][3] == GetCurrentMap()) {
            QuestMenu_GetSetSubquestState(QUEST_BODEGABURNOUT, FLAG_SET_COMPLETED,POKE_MART_MAP[i][1]);

            if (POKE_MART_MAP[i][2] == DELIVER) {
                bodegaPackage += i;
                RemoveBagItem(bodegaPackage,1);
            }
            break;
        }
    }
}

// ***********************************************************************
// Quest: Break The Internet
// ***********************************************************************

u8 Quest_Breaktheinternet_Count_CompletedSocialMedia(void){
    u8 i, numCompletedQuests = 0;
    u16 relevantQuest = SOCIAL_MEDIA_QUESTS_START;

    for (i = 0; i < COUNT_SOCIAL_MEDIA_QUESTS;i++){
        if (QuestMenu_GetSetQuestState(relevantQuest,FLAG_GET_COMPLETED)){
            numCompletedQuests++;
        }
        relevantQuest++;
    }
    return numCompletedQuests;
}

u16 Quest_Breaktheinternet_CountRemainingSubquests(void)
{
    return Quest_Generic_CountRemainingSubquests(QUEST_BREAKTHEINTERNET);
}

// ***********************************************************************
// Quest: Warehouse Warfare
// ***********************************************************************

u16 Quest_Warehousewarfare_CountRemainingSubquests(void)
{
    return Quest_Generic_CountRemainingSubquests(QUEST_WAREHOUSEWARFARE);
}

// ***********************************************************************
// Quest: Persuasive Passenger
// ***********************************************************************

u16 Quest_Persuasivepassenger_CountRemainingSubquests(void)
{
    return Quest_Generic_CountRemainingSubquests(QUEST_PERSUASIVEPASSENGER);
}

bool8 Quest_Persuasivepassenger_ShouldPlayFirstDriver(void)
{
    u16 completedQuests = Quest_Persuasivepassenger_CountRemainingSubquests();
    bool8 questActive = QuestMenu_GetSetQuestState(QUEST_PERSUASIVEPASSENGER,FLAG_GET_ACTIVE);
    bool8 onCorrectMap = (MAP_ALAMEDA == GetCurrentMap());
    bool8 shouldPlay = FALSE;

    if ((completedQuests == 3) && (questActive) && (onCorrectMap)){
        shouldPlay == TRUE;
    }

    return shouldPlay;
}

bool8 Quest_Persuasivepassenger_ShouldPlaySecondDriver(void)
{
    u16 completedQuests = Quest_Persuasivepassenger_CountRemainingSubquests();
    bool8 questActive = QuestMenu_GetSetQuestState(QUEST_PERSUASIVEPASSENGER,FLAG_GET_ACTIVE);
    bool8 onCorrectMap = (MAP_HAIGHTASHBURY == GetCurrentMap());
    bool8 shouldPlay = FALSE;

    if ((completedQuests == 2) && (questActive) && (onCorrectMap)){
        shouldPlay == TRUE;
    }

    return shouldPlay;
}

bool8 Quest_Persuasivepassenger_ShouldPlayThirdDriver(void)
{
    u16 completedQuests = Quest_Persuasivepassenger_CountRemainingSubquests();
    bool8 questActive = QuestMenu_GetSetQuestState(QUEST_PERSUASIVEPASSENGER,FLAG_GET_ACTIVE);
    bool8 shouldPlay = FALSE;

    if ((completedQuests == 1) && (questActive)){
        shouldPlay == TRUE;
    }

    return shouldPlay;
}

u16 Quest_Persuasivepassenger_CheckQuestAndChooseDriver(void){
    bool8 questActive = QuestMenu_GetSetQuestState(QUEST_PERSUASIVEPASSENGER,FLAG_GET_ACTIVE);
    u16 questResult = 99;

    if (questActive == TRUE){

        if (Quest_Persuasivepassenger_ShouldPlayFirstDriver())
            questResult = 3;

        if (Quest_Persuasivepassenger_ShouldPlaySecondDriver())
            questResult = 2;

        if (Quest_Persuasivepassenger_ShouldPlayThirdDriver())
            questResult = 1;

    }
    return questResult;
}

bool8 Quest_Persuasivepassenger_CheckNeededItems(void){
    bool8 hasSitrus = CheckBagHasItem(ITEM_SITRUS_BERRY,3);
    bool8 hasHoney = CheckBagHasItem(ITEM_HONEY,5);
    bool8 hasWatmel = CheckBagHasItem(ITEM_WATMEL_BERRY,1);
    bool8 hasLemonade = CheckBagHasItem(ITEM_LEMONADE,2);

    bool8 hasNeededItems = FALSE;

    if (hasSitrus && hasHoney && hasWatmel && hasLemonade){
        hasNeededItems = TRUE;
    }
    return hasNeededItems;
}
void Quest_Persuasivepassenger_TakeNeededItems(void){
    if (Quest_Persuasivepassenger_CheckNeededItems()){
        RemoveBagItem(ITEM_SITRUS_BERRY,3);
        RemoveBagItem(ITEM_HONEY,5);
        RemoveBagItem(ITEM_WATMEL_BERRY,1);
        RemoveBagItem(ITEM_LEMONADE,2);
    }
}

// ***********************************************************************
// Quest: Skill Library
// ***********************************************************************

u16 Quest_Skilllibrary_CountObtainedTechnicalMachines(void){
    u16 count = 0, i = 0;
    u16 machineRange = (ITEM_TM01 + NUM_TECHNICAL_MACHINES);

    for (i = ITEM_TM01;i < machineRange;i++){
        if (CheckBagHasItem(i,1))
            count++;
    }

    return count;
}

void Quest_Skilllibrary_StoreAndCompare(void){
    u16 numMachines = Quest_Skilllibrary_CountObtainedTechnicalMachines();
    u16 previousNumMachines = VarGet(VAR_QUEST_SKILLLIBRARY_TM_COUNT);
    u16 diff = (numMachines - previousNumMachines);
    u16 remainingMachines = (NUM_TECHNICAL_MACHINES - numMachines);
    bool8 hasMoreMachines = FALSE;

    if (diff > 0){
        VarSet(VAR_QUEST_SKILLLIBRARY_TM_COUNT,numMachines);
        ConvertIntToDecimalStringN(gStringVar2, diff, STR_CONV_MODE_LEFT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, remainingMachines, STR_CONV_MODE_LEFT_ALIGN, 3);
        hasMoreMachines = TRUE;
    }

    gSpecialVar_Result = hasMoreMachines;
    ConvertIntToDecimalStringN(gStringVar1, numMachines, STR_CONV_MODE_LEFT_ALIGN, 3);
}

u16 Quest_Skilllibrary_GetPercentage(void){
    u16 numMachines = Quest_Skilllibrary_CountObtainedTechnicalMachines();

    return (numMachines / NUM_TECHNICAL_MACHINES) * 100;
}

void Quest_Skilllibrary_Debug(void){
    u16 i = 0;
    u16 machineRange = (ITEM_TM01 + NUM_TECHNICAL_MACHINES);

    for (i = ITEM_TM01;i < machineRange;i++){
        AddBagItem(i,1);
    }
}

// ***********************************************************************
// Quest: Mutual Aid Fund
// ***********************************************************************

u8 Quest_Mutualaidfund_CountDigits(u32 askAmount){
    u8 digits = 0;
    u32 temp = askAmount;

    while (temp != 0){
        temp /= 10;
        digits++;
    }
    return digits;
}

u32 Quest_Mutaidaidfund_CalculateMoneyAndText(void){
    u8 questProgress = VarGet(VAR_QUEST_MUTUALAIDFUND_AMOUNT);
    u32 askAmount = 0, numDigits = 0;

    switch(questProgress){
        case 0: askAmount = 5000;
            break;
        case 1: askAmount = 10000;
            break;
        case 2: askAmount = 20000;
            break;
        case 3: askAmount = 30000;
            break;
        case 4: askAmount = 40000;
            break;
        case 5: askAmount = 50000;
            break;
        case 6: askAmount = 100000;
            break;
        case 7: askAmount = 200000;
            break;
        case 8: askAmount = 300000;
            break;
        case 9: askAmount = 400000;
            break;
        case 10: askAmount = 500000;
            break;
        case 11: askAmount = 800000;
            break;
        case 12: askAmount = 1000000;
            break;
        case 13: askAmount = 3280000;
            break;
    }

    numDigits = Quest_Mutualaidfund_CountDigits(askAmount);
    ConvertIntToDecimalStringN(gStringVar1,askAmount,STR_CONV_MODE_LEFT_ALIGN,numDigits);

    return askAmount;
}

bool8 Quest_Mutualaidfund_CheckMoney(void){
    u32 askAmount = Quest_Mutaidaidfund_CalculateMoneyAndText();

    return (IsEnoughMoney(&gSaveBlock1Ptr->money,askAmount));
}

void Quest_Mutualaidfund_TakeDonation(void){
    u32 askAmount = Quest_Mutaidaidfund_CalculateMoneyAndText();

    RemoveMoney(&gSaveBlock1Ptr->money,askAmount);
}

// ***********************************************************************
// Quest: Volunteer Firefighter
// ***********************************************************************

bool8 Quest_Volunteerfirefighter_CheckIfWater(void)
{
    u32 species = 0;
    u32 type[2] = {0,0};
    bool8 doesPokemonMatch = TRUE;

    species = GetMonData(&gPlayerParty[gSpecialVar_0x8004],MON_DATA_SPECIES,NULL);
    type[0] = gSpeciesInfo[species].types[0];
    type[1] = gSpeciesInfo[species].types[1];

        if (
             (type[0] != TYPE_WATER) &&
             (type[1] != TYPE_WATER)
           )
            {
                doesPokemonMatch = FALSE;
            }
    return doesPokemonMatch;
}


u8 Quest_Volunteerfirefighter_GetRemainingNumberOfMons(void)
{
    u8 numberCapturedMons = VarGet(VAR_QUEST_VOLUNTEER_FIREFIGHTER_COUNT);
    u8 remainingCapturedMons = (REQUIRED_NUMBER_OF_POKEMON - numberCapturedMons);

    ConvertIntToDecimalStringN(gStringVar1, remainingCapturedMons, STR_CONV_MODE_LEFT_ALIGN, 1);
    return remainingCapturedMons;
}

// ***********************************************************************
// Quest: Bruce Lee
// ***********************************************************************
bool8 Quest_Brucelee_UpdateType(u16 days)
{
    u16 randomType = Random() % NUMBER_OF_MON_TYPES;

    if (days != 0){

        while(randomType == TYPE_MYSTERY)
            randomType = Random () % NUMBER_OF_MON_TYPES;

        VarSet(VAR_QUEST_BRUCE_LEE_DAILY_TYPE,randomType);
    }
}

bool8 Quest_Brucelee_BufferTypeName(void)
{
    u16 dailyType = VarGet(VAR_QUEST_BRUCE_LEE_DAILY_TYPE);
    StringCopy(gStringVar1,gTypeNames[dailyType]);
}

bool8 Quest_Brucelee_CheckIfPartyTypes(void)
{
    u8 i;
    u16 species;
    u16 dailyType = VarGet(VAR_QUEST_BRUCE_LEE_DAILY_TYPE);

    bool8 partyMatchesType = TRUE;

    struct Pokemon *pokemon;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        pokemon = &gPlayerParty[i];
        if (GetMonData(pokemon, MON_DATA_SANITY_HAS_SPECIES) && !GetMonData(pokemon, MON_DATA_IS_EGG))
        {
            species = GetMonData(pokemon, MON_DATA_SPECIES);
            if (gSpeciesInfo[species].types[0] != dailyType && gSpeciesInfo[species].types[1] != dailyType)
            {
                partyMatchesType = FALSE;
            }
        }
    }
    return partyMatchesType;
}
// ***********************************************************************
// Quest: Restore Treasure Island
// ***********************************************************************

bool8 Quest_Restoretreasureisland_CheckIfKnowsPsychoShift(void)
{
    bool8 knowsPsychoShift = FALSE;
    u16 moveChecked = 0, moveSlot = 0;

    for (moveSlot = MON_DATA_MOVE1; moveSlot < MON_DATA_MOVE4; moveSlot++)
    {
        moveChecked = GetMonData(&gPlayerParty[gSpecialVar_0x8004], moveSlot, NULL);
        if (moveChecked == MOVE_PSYCHO_SHIFT)
        {
            return knowsPsychoShift = TRUE;
        }
    }

    return knowsPsychoShift;
}

bool8 Quest_Restoretreasureisland_CheckIfPokemonHasEffectSpore(void)
{
    //bool8 hasEffectSpore = FALSE;
    //u16 abilitySlot = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_ABILITY_NUM, NULL);
    //u32 species = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES, NULL);

    return (ABILITY_EFFECT_SPORE == GetMonAbility(&gPlayerParty[gSpecialVar_0x8004]));
}

u16 Quest_Restoretreasureisland_CheckRemainingSubquests(void)
{
    return Quest_Generic_CountRemainingSubquests(QUEST_RESTORETREASUREISLAND);
}

// ***********************************************************************
// Quest: Restore Marin
// ***********************************************************************

u16 Quest_Restoremarin_CheckRemainingSubquests(void)
{
    return Quest_Generic_CountRemainingSubquests(QUEST_RESTOREMARIN);
}

// ***********************************************************************
// Quest: Artisan Balls 3
// ***********************************************************************
void Quest_ArtisanBalls3_MarkRewardIfApricornBall(void)
{
    bool8 isArtisanBall3Active = QuestMenu_GetSetQuestState(QUEST_ARTISANBALLS3,FLAG_GET_ACTIVE);

    if (isArtisanBall3Active)
    {

        for (gActiveBattler = 0; gActiveBattler < gBattlersCount; gActiveBattler++)
        {
            if (GetBattlerSide(gActiveBattler) == B_SIDE_OPPONENT
                    && !(gBattleTypeFlags & (BATTLE_TYPE_EREADER_TRAINER
                            | BATTLE_TYPE_FRONTIER
                            | BATTLE_TYPE_LINK
                            | BATTLE_TYPE_RECORDED_LINK
                            | BATTLE_TYPE_TRAINER_HILL)))
            {
                HandleSetPokedexFlag(SpeciesToNationalPokedexNum(gBattleMons[gActiveBattler].species), FLAG_SET_SEEN, gBattleMons[gActiveBattler].personality);
            }

            // If the Player sends out a Pokémon caught with an apricorn ball, and their opponent is a Gym Leader or alternatively, if they're fighting in
            // the Chase Center Arena, set the QUEST_ARTISANBALLS3 as ready to hand out the Player a reward.
            if (GetBattlerSide(gActiveBattler) == B_SIDE_PLAYER
                    && IS_ITEM_APRICORN_BALL(GetMonData(&gPlayerParty[gBattlerPartyIndexes[gActiveBattler]], MON_DATA_POKEBALL))
                    && ((gTrainers[gTrainerBattleOpponent_A].trainerClass == TRAINER_CLASS_LEADER || gTrainers[gTrainerBattleOpponent_B].trainerClass == TRAINER_CLASS_LEADER)
                        || GetCurrentMap() == MAP_CHASECENTER_ARENA))
                QuestMenu_GetSetQuestState(QUEST_ARTISANBALLS3, FLAG_SET_REWARD);
        }
    }
}
// ***********************************************************************
// Quest: Ice Cream Crafting
// ***********************************************************************
bool8 Quest_IceCreamCrafting_CheckNeededItems(void){
    bool8 hasPecha = CheckBagHasItem(ITEM_PECHA_BERRY,3);
    bool8 hasNanab = CheckBagHasItem(ITEM_NANAB_BERRY,2);
    bool8 hasRabuta = CheckBagHasItem(ITEM_RABUTA_BERRY,1);

    bool8 hasNeededItems = FALSE;

    if (hasPecha && hasNanab && hasRabuta){
        hasNeededItems = TRUE;
    }
    return hasNeededItems;
}

// ***********************************************************************
// Quest: Freshwater Evolution
// ***********************************************************************
// Scans the Player's party.
// If the Player has 6 Shiny Octillery, the function returns TRUE. If they don't, it returns FALSE.
// The function stores the nickname of the last Octillery scanned inside of gStringVar1/STR_VAR_1.
bool8 IsPartyFullOfShinyOctillery(void)
{
    u8 count = 0, partyCount = CalculatePlayerPartyCount();
    u16 species = 0;

    for (gSpecialVar_0x8004 = 0; gSpecialVar_0x8004 <= partyCount; gSpecialVar_0x8004++)
    {
        species = GetMonData(&gPlayerParty[gSpecialVar_0x8004], MON_DATA_SPECIES);
        if (species == SPECIES_OCTILLERY)
        {
            if (IsMonShiny(&gPlayerParty[gSpecialVar_0x8004]))
            {
                count++;
            }
            else
            {
                GetMonNickname(&gPlayerParty[gSpecialVar_0x8004], gStringVar1);
                break;
            }
        }
    }

    return (count == partyCount) ? TRUE : FALSE;
}
