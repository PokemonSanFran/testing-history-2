#ifndef GUARD_CONSTANTS_QUESTS_H
#define GUARD_CONSTANTS_QUESTS_H

//questmenu scripting command params
#define QUEST_MENU_OPEN                 0   //opens the quest menu (questId = 0)
#define QUEST_MENU_UNLOCK_QUEST         1   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_ACTIVE           2   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_SET_REWARD           3   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_COMPLETE_QUEST       4   //questId = QUEST_X (0-indexed)
#define QUEST_MENU_CHECK_UNLOCKED       5   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_INACTIVE       6 //check if a questID is inactive. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_ACTIVE         7   //checks if questId has been unlocked. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_REWARD         8  //checks if questId is in Reward state. Returns result to gSpecialVar_Result
#define QUEST_MENU_CHECK_COMPLETE       9   //checks if questId has been completed. Returns result to gSpecialVar_Result
#define QUEST_MENU_BUFFER_QUEST_NAME    10   //buffers a quest name to gStringVar1
#define QUEST_MENU_SET_FAVORITE         11
#define QUEST_MENU_UNCOMPLETE_QUEST     12

// quest number defines
#define QUEST_PLAYERSADVENTURE	0
#define QUEST_RETURNDOLL	1
#define QUEST_BRINGFRUIT	2
#define QUEST_BRINGFIRETYPE	3
#define QUEST_STOPMUGGING	4
#define QUEST_STOLENTRADE	5
#define QUEST_HAUNTABUILDING	6
#define QUEST_RABIESOUTBREAK	7
#define QUEST_BLUEROBBERRY	8
#define QUEST_ICECREAMCRAFTING	9
#define QUEST_VSDEOXYS	10
#define QUEST_CHINATOWNTUNNELS	11
#define QUEST_FRESHWATEREVOLUTION	12
#define QUEST_GEMARTIST	13
#define QUEST_BETWEENASTONEANDAHARD	14
#define QUEST_RIGHTINGWRONGS	15
#define QUEST_ENTERTHEDRAGON	16
#define QUEST_BREAKTHEINTERNET	17
#define QUEST_SHUTDOWNMEDICINEMAN	18
#define QUEST_BUILDINGSCOPE	19
#define QUEST_NOGOODDEED	20
#define QUEST_IMPROVBATTLING	21
#define QUEST_IMPROVBATTLINGCHAMPIONSHIP	22
#define QUEST_INSTALLNATUREPROBES	23
#define QUEST_MANOFMANYHATS	24
#define QUEST_RECRUITLOCALARTISTS	25
#define QUEST_RESTAURANTEXPANSION1	26
#define QUEST_RESTAURANTEXPANSION2	27
#define QUEST_SIEBOLDSTRAINING    28 
#define QUEST_CULTURALPURITY	29
#define QUEST_HYBRIDCULTURE	30
#define QUEST_ALOHAFROMALOLA	31
#define QUEST_BUILDINGANEXHIBIT	32
#define QUEST_UNKNOWNMORTYQUESTA	33
#define QUEST_UNKNOWNMORTYQUESTB	34
#define QUEST_STEALTHEAXE   35
#define QUEST_UNKNOWNCHUCKQUESTB	36
#define QUEST_BIOMERESEARCH	37
#define QUEST_BERRYSUSTAINABILITY	38
#define QUEST_THEONLYHEADSHOPINTOWN	39
#define QUEST_INVERSEHALLUCINOGENIC	40
#define QUEST_UNKNOWNCLAIRQUESTA	41
#define QUEST_UNKNOWNCLAIRQUESTB	42
#define QUEST_CONTRACTORPORYGON	43
#define QUEST_ANGELDELIVERY	44
#define QUEST_GETTHEBANDBACKTOGETHER	45
#define QUEST_FOODTRUCKBUREACRACY	46
#define QUEST_DETECTIVEARIANA	47
#define QUEST_UNKNOWNBRUCELEEQUEST	48
#define QUEST_CHALLENGEOFTHE7SISTERS	49
#define QUEST_ESPORTS	50
#define QUEST_CUTEPOKEMON	51
#define QUEST_WALLACEARMY	52
#define QUEST_DEXCOMPLETION	53
#define QUEST_TEMPORARYSHELTER 54
#define QUEST_KITCHENVOLUNTEERING	55
#define QUEST_ARTISANBALLS1	56
#define QUEST_ARTISANBALLS2	57
#define QUEST_ARTISANBALLS3	58
#define QUEST_SHELTERSWITCHEROO	59
#define QUEST_SHELTERTAXISOLUTION	60
#define QUEST_LASTMUSICVENUEINSANFRANCISCO	61
#define QUEST_GARDENCLEANUP	62
#define QUEST_GARDENCLEANUPADVANCED	63
#define QUEST_EMPLOYEDEVERAFTER	64
#define QUEST_BUTONLYINMYBACKYARD	65
#define QUEST_NEIGHBORHOODCLEANUP	66
#define QUEST_NEIGHBORHOODCLEANUP2	67
#define QUEST_NEIGHBORHOODCLEANUP3	68
#define QUEST_NEIGHBORHOODCLEANUP4	69
#define QUEST_ROCKCOLLECTOR	70
#define QUEST_HANG20	71
#define QUEST_ALLTHATGLITTERSMIGHTBEGOLD	72
#define QUEST_UNKNOWNFISHINGQUEST	73
#define QUEST_HIDDENGROTTOMAPPING	74
#define QUEST_HIDDENGROTTOMAPPING2	75
#define QUEST_ULTRAWORMHOLERESEARCH	76
#define QUEST_UNKNOWNGOVERNMENTSOCIALMEDIAQUEST	77
#define QUEST_DRUMCIRCLE	78
#define QUEST_UNKNOWNPROP22QUEST	79
#define QUEST_UNKNOWNTIMETRAVELQUEST	80
#define QUEST_UNKNOWNCONSTRUCTIONSTRIKEQUEST	81
#define QUEST_IBELIEVEICANFLY	82
#define QUEST_WILDFIRERISK	83
#define QUEST_THEBOYWHOCRIESWITHWOLVES	84
#define QUEST_UNKNOWNTROLLEYPROBLEM	85
#define QUEST_UNKNOWNLANDFILLQUEST	86
#define QUEST_TAXICABTURNAROUNDSEA	87
#define QUEST_TAXICABTURNAROUNDAIR	88
#define QUEST_TAXICABTURNAROUNDLAND	89
#define QUEST_PERSUASIVEPASSENGER	90
#define QUEST_BODEGABURNOUT	91
#define QUEST_WAREHOUSEWARFARE	92
#define QUEST_RESTORETOTHEIRFORMERGLORY	93
#define QUEST_HOW_DISAPPOINTING 94
#define QUEST_LETS_BURN_THIS_MOTHER_DOWN 95
#define QUEST_MANHUNT 96
#define QUEST_RESTORECHINATOWN  97
#define QUEST_RESTOREMARIN  98
#define QUEST_RESTORETREASUREISLAND 99
#define QUEST_RESTOREHAIGHTASHBURY  100
#define QUEST_REDOMUGGING 101
#define QUEST_PANDA_PRIDE   102
#define QUEST_BECOMECHAMPION    103
#define QUEST_DANCEBATTLE      104
#define QUEST_COUNT (QUEST_DANCEBATTLE + 1)

#define SUB_QUEST_1          0
#define SUB_QUEST_2          1
#define SUB_QUEST_3          2
#define SUB_QUEST_4          3
#define SUB_QUEST_5          4
#define SUB_QUEST_6          5
#define SUB_QUEST_7          6
#define SUB_QUEST_8          7
#define SUB_QUEST_9          8
#define SUB_QUEST_10         9
#define SUB_QUEST_11        10
#define SUB_QUEST_12        11
#define SUB_QUEST_13        12
#define SUB_QUEST_14        13
#define SUB_QUEST_15        14
#define SUB_QUEST_16        15
#define SUB_QUEST_17        16
#define SUB_QUEST_18        17
#define SUB_QUEST_19        18
#define SUB_QUEST_20        19
#define SUB_QUEST_21        20
#define SUB_QUEST_22        21
#define SUB_QUEST_23        22
#define SUB_QUEST_24        23
#define SUB_QUEST_25        24
#define SUB_QUEST_26        25
#define SUB_QUEST_27        26
#define SUB_QUEST_28        27
#define SUB_QUEST_29        28
#define SUB_QUEST_30        29

#define QUEST_HAUNTABUILDING_SUB_COUNT 6
#define QUEST_RIGHTINGWRONGS_SUB_COUNT	4
#define QUEST_BREAKTHEINTERNET_SUB_COUNT	3
#define QUEST_IMPROVBATTLING_SUB_COUNT	4
#define QUEST_INSTALLNATUREPROBES_SUB_COUNT	3
#define QUEST_RESTAURANTEXPANSION1_SUB_COUNT	4
#define QUEST_RESTAURANTEXPANSION2_SUB_COUNT	5
#define QUEST_SIEBOLDSTRAINING_SUB_COUNT    4
#define QUEST_HYBRIDCULTURE_SUB_COUNT	3
#define QUEST_BUILDINGANEXHIBIT_SUB_COUNT	4
#define QUEST_BIOMERESEARCH_SUB_COUNT	8
#define QUEST_BERRYSUSTAINABILITY_SUB_COUNT	6
#define QUEST_CONTRACTORPORYGON_SUB_COUNT	3
#define QUEST_GETTHEBANDBACKTOGETHER_SUB_COUNT	5
#define QUEST_DETECTIVEARIANA_SUB_COUNT	3
#define QUEST_CHALLENGEOFTHE7SISTERS_SUB_COUNT	7
#define QUEST_CUTEPOKEMON_SUB_COUNT	4
#define QUEST_WALLACEARMY_SUB_COUNT	5
#define QUEST_DEXCOMPLETION_SUB_COUNT	2
#define QUEST_KITCHENVOLUNTEERING_SUB_COUNT	5
#define QUEST_ARTISANBALLS_SUB_COUNT	7
#define QUEST_ARTISANBALLS2_SUB_COUNT	3
#define QUEST_SHELTERSWITCHEROO_SUB_COUNT	5
#define QUEST_SHELTERTAXISOLUTION_SUB_COUNT	5
#define QUEST_NEIGHBORHOODCLEANUP_SUB_COUNT	5
#define QUEST_NEIGHBORHOODCLEANUP2_SUB_COUNT	4
#define QUEST_NEIGHBORHOODCLEANUP3_SUB_COUNT	3
#define QUEST_ROCKCOLLECTOR_SUB_COUNT	10
#define QUEST_HIDDENGROTTOMAPPING_SUB_COUNT	5
#define QUEST_HIDDENGROTTOMAPPING2_SUB_COUNT	3
#define QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT	10
#define QUEST_WILDFIRERISK_SUB_COUNT	3
#define QUEST_THEBOYWHOCRIESWITHWOLVES_SUB_COUNT	9
#define QUEST_TAXICABTURNAROUNDSEA_SUB_COUNT	5
#define QUEST_TAXICABTURNAROUNDAIR_SUB_COUNT	5
#define QUEST_TAXICABTURNAROUNDLAND_SUB_COUNT	7
#define QUEST_PERSUASIVEPASSENGER_SUB_COUNT	3
#define QUEST_BODEGABURNOUT_SUB_COUNT	17
#define QUEST_WAREHOUSEWARFARE_SUB_COUNT	3
#define QUEST_RESTORETOTHEIRFORMERGLORY_SUB_COUNT	4
#define QUEST_RESTOREMARIN_SUB_COUNT    2
#define QUEST_RESTORECHINATOWN_SUB_COUNT 7
#define QUEST_RESTORETREASUREISLAND_SUB_COUNT   4
#define QUEST_RECRUITLOCALARTISTS_SUB_COUNT 3
#define QUEST_BECOMECHAMPION_SUB_COUNT  4

#define SUB_QUEST_COUNT (QUEST_HAUNTABUILDING_SUB_COUNT + QUEST_RIGHTINGWRONGS_SUB_COUNT + QUEST_BREAKTHEINTERNET_SUB_COUNT + QUEST_IMPROVBATTLING_SUB_COUNT + QUEST_INSTALLNATUREPROBES_SUB_COUNT + QUEST_RESTAURANTEXPANSION1_SUB_COUNT + QUEST_RESTAURANTEXPANSION2_SUB_COUNT + QUEST_SIEBOLDSTRAINING_SUB_COUNT + QUEST_HYBRIDCULTURE_SUB_COUNT + QUEST_BUILDINGANEXHIBIT_SUB_COUNT + QUEST_BIOMERESEARCH_SUB_COUNT + QUEST_BERRYSUSTAINABILITY_SUB_COUNT + QUEST_CONTRACTORPORYGON_SUB_COUNT + QUEST_GETTHEBANDBACKTOGETHER_SUB_COUNT + QUEST_DETECTIVEARIANA_SUB_COUNT + QUEST_CHALLENGEOFTHE7SISTERS_SUB_COUNT + QUEST_CUTEPOKEMON_SUB_COUNT + QUEST_WALLACEARMY_SUB_COUNT + QUEST_DEXCOMPLETION_SUB_COUNT + QUEST_KITCHENVOLUNTEERING_SUB_COUNT + QUEST_ARTISANBALLS_SUB_COUNT + QUEST_ARTISANBALLS2_SUB_COUNT + QUEST_SHELTERSWITCHEROO_SUB_COUNT + QUEST_SHELTERTAXISOLUTION_SUB_COUNT + QUEST_NEIGHBORHOODCLEANUP_SUB_COUNT + QUEST_NEIGHBORHOODCLEANUP2_SUB_COUNT + QUEST_NEIGHBORHOODCLEANUP3_SUB_COUNT + QUEST_ROCKCOLLECTOR_SUB_COUNT + QUEST_HIDDENGROTTOMAPPING_SUB_COUNT + QUEST_HIDDENGROTTOMAPPING2_SUB_COUNT + QUEST_ULTRAWORMHOLERESEARCH_SUB_COUNT + QUEST_WILDFIRERISK_SUB_COUNT + QUEST_THEBOYWHOCRIESWITHWOLVES_SUB_COUNT + QUEST_TAXICABTURNAROUNDSEA_SUB_COUNT + QUEST_TAXICABTURNAROUNDAIR_SUB_COUNT + QUEST_TAXICABTURNAROUNDLAND_SUB_COUNT + QUEST_PERSUASIVEPASSENGER_SUB_COUNT + QUEST_BODEGABURNOUT_SUB_COUNT + QUEST_WAREHOUSEWARFARE_SUB_COUNT + QUEST_RESTORETOTHEIRFORMERGLORY_SUB_COUNT + QUEST_RESTOREMARIN_SUB_COUNT + QUEST_RESTORECHINATOWN_SUB_COUNT + QUEST_RESTORETREASUREISLAND_SUB_COUNT + QUEST_RECRUITLOCALARTISTS + QUEST_BECOMECHAMPION_SUB_COUNT)

#define QUEST_ARRAY_COUNT (SUB_QUEST_COUNT > QUEST_COUNT ? SUB_QUEST_COUNT : QUEST_COUNT)
#endif // GUARD_CONSTANTS_QUESTS_H
