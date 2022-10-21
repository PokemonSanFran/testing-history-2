swagbag_Storywarp_Script::
	setvar VAR_PLAYER_HOME_STATE, POST_SWAGBAG
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_PLAYERSADVENTURE
	warp MAP_SOUTHBAY_COMPOUND_1F, 0
	return


ReadySetI_Storywarp_Script::
	call swagbag_Storywarp_Script
	setvar VAR_PLAYER_HOME_STATE, SLEPT_AFTER_SWAGBAG
	setvar VAR_PLAYER_HOME_STATE, OPENED_FASHION_CASE
	setflag FLAG_RECIEVED_LEFTOVERS
	additem ITEM_LEFTOVERS, 1
	warp MAP_SOUTHBAY, 0
	return


EnterFalkner_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	additem ITEM_TM01
	setflag FLAG_BADGE01_GET
	setvar VAR_FALKNER_STATE, BATTLE_1_COMPLETE
	setvar VAR_GYM_1_STATE, GYM_DEFEATED_LEADER
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_MISSION, 0
	return


EnterBugsy_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	additem ITEM_TM02
	setflag FLAG_BADGE02_GET
	setvar VAR_BUGSY_STATE, BATTLE_1_COMPLETE
	setvar VAR_GYM_2_STATE, GYM_DEFEATED_LEADER
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_JAPANTOWN, 0
	return


EnterWhitney_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	additem ITEM_TM03
	setflag FLAG_BADGE03_GET
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, DEFEATED_WHITNEY
	setvar VAR_WHITNEY_STATE, BATTLE_1_COMPLETE
	setvar VAR_GYM_3_STATE, GYM_DEFEATED_LEADER
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_SOMA, 4
	return


NewAssholeAppears_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_PSFROUTE9_STATE, DEFEATED_ARCHER_PSFROUTE9
	warp MAP_PSFROUTE9, 1, 0
	return


OldAssholeAppears_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_LOMBARDSTREET_STATE, DEFEATED_BIANCA_LOMBARD
	warp MAP_LOMBARDSTREET, 15, 10
	return


GroupofAssholesAppears_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	setvar VAR_GROUP_OF_ASSHOLES_STATE, PLAYER_HAS_DEFEATED_TEAM_ROCKET
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_FISHERMANSWHARF, 31, 6
	return


FlyingBlind_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	setvar VAR_FAINTED_FOG_STATE, 1
	warp MAP_PSFROUTE1, 79, 15
	return


WowYoureStrong_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	setvar VAR_SOMA_STATE, POST_WOW_YOURE_STRONG
	warp MAP_SOMA, 0
	return


TheGangsAllHere_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_THE_GANGS_ALL_HERE
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_SALESFORCETOWER_LEAGUEOPS, 5, 53
	return


AlwaysWatchingWazokwski_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	setvar VAR_SALESFORCETOWER_PRODUCTION_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	warp MAP_SALESFORCETOWER_PRODUCTION, 9, 7
	return


EnterAriana_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	additem ITEM_MEGA_RING, 1
	warp MAP_TENDERLOIN, 2, 40
	return


HowDoWeGetHome_Storywarp_Script::
	call ReadySetI_Storywarp_Script
	setvar VAR_DOGPATCH_STATE, POST_HOW_DO_WE_GET_HOME
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_DOGPATCH, 11, 21
	return


AaandWereBack_Storywarp_Script::
	call EnterFalkner_Storywarp_Script
	call EnterBugsy_Storywarp_Script
	call EnterWhitney_Storywarp_Script
	call NewAssholeAppears_Storywarp_Script
	call OldAssholeAppears_Storywarp_Script
	call GroupofAssholesAppears_Storywarp_Script
	call WowYoureStrong_Storywarp_Script
	call TheGangsAllHere_Storywarp_Script
	call EnterAriana_Storywarp_Script
	call HowDoWeGetHome_Storywarp_Script
	setvar VAR_STORYLINE_STATE, STORY_FERRY_FIXED
	setvar VAR_PLAYER_HOME_STATE, FINISHED_1_1
	warp MAP_SOUTHBAY_COMPOUND_2F, 0
	return


AssholesHome_Storywarp_Script::
	call AaandWereBack_Storywarp_Script
	setvar VAR_ALAMEDA_STATE, DEFEATED_ARCHER_ALAMEDA
	setvar VAR_STORYLINE_STATE, STORY_DEFEAT_ARCHER_ALAMEDA
	warp MAP_ALAMEDA, 20, 5
	return


HousingProtest_Storywarp_Script::
	call AssholesHome_Storywarp_Script
	setvar VAR_STORYLINE_STATE, STORY_DEFEAT_BERKELEY_PROTEST
	setvar VAR_PSFROUTE63_STATE, DEFEATED_TEAMROCKET_PSFROUTE63
	warp MAP_PSFROUTE63, 7, 14
	return


swagbag2_Storywarp_Script::
	call HousingProtest_Storywarp_Script
	setvar VAR_BERKELEY_STATE, SWAGBAG_2_COMPLETE
	warp MAP_BERKELEY, 1
	return


EnterMorty_Storywarp_Script::
	call swagbag2_Storywarp_Script
	additem ITEM_TM04
	setflag FLAG_CONSTRUCTION_BREAKING_NEWS
	setflag FLAG_BADGE04_GET
	setvar VAR_MORTY_STATE, BATTLE_1_COMPLETE
	setvar VAR_GYM_4_STATE, GYM_DEFEATED_LEADER
	setvar VAR_BERKELEY_STATE, DEFEATED_MORTY
	setvar VAR_STORYLINE_STATE, STORY_DEFEAT_MORTY
	warp MAP_BERKELEY, 0
	return


SorryAboutMyFriends_Storywarp_Script::
	call EnterMorty_Storywarp_Script
	setvar VAR_BERKELEY_STATE, GOT_ALCATRAZ_TICKET
	setvar VAR_FERRY_STATE, FERRY_ALCATRAZ_AVAILABLE
	additem ITEM_MYSTIC_TICKET, 1
	warp MAP_BERKELEY, 0
	return


TheStorySoFar_Storywarp_Script::
	call SorryAboutMyFriends_Storywarp_Script
	setvar VAR_ALCATRAZ_EXHIBIT_STATE, ALCATRAZ_EXHIBIT_REWARD
	setvar VAR_ALCATRAZ_STATE, FIRST_ARRIVED_ALCATRAZ
	warp MAP_ALCATRAZ, 37, 59
	return


YoungPadawan_Storywarp_Script::
	call TheStorySoFar_Storywarp_Script
	setvar VAR_STORYLINE_STATE, STORY_COMPLETE_ALCATRAZ
	setvar VAR_ALCATRAZ_STATE, BATTLED_MALVA
	setvar VAR_ALCATRAZ_EXHIBIT_STATE, ALCATRAZ_EXHIBIT_COMPLETE
	additem ITEM_GO_GOGGLES, 1
	warp MAP_ALCATRAZ, 37, 59
	return


WaitYouWentWhere_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	setvar VAR_WAIT_YOU_WENT_WHERE, POST_WAITYOUWENTWHERE
	warp MAP_PSFROUTE19, 3, 1
	return


EnterChuck_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	setflag FLAG_BADGE05_GET
	msgbox EnterChuck_Storywarp_Script_Text_0
	setvar VAR_GYM_5_STATE, GYM_DEFEATED_LEADER
	setvar VAR_CHUCK_STATE, BATTLE_1_COMPLETE
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_FORTPOINT_STATE, DEFEATED_CHUCK
	warp MAP_FORTPOINT, 0
	return


YouLookTired_Storywarp_Script::
	call EnterChuck_Storywarp_Script
	setvar VAR_FORTPOINT_STATE, MET_KOGA_OUTSIDE_GYM
	warp MAP_FORTPOINT, 0
	return


Kogasraisondetre_Storywarp_Script::
	call YouLookTired_Storywarp_Script
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_KOGA_RAISON_DETRE_STATE, POST_KOGA_RAISON_DETRE
	setvar VAR_KOGA_MANSION_STATE, FINISHED_KOGA_RAISON
	warp MAP_PRESIDIO_MANSION, 0
	return


BeachBattle_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	setvar VAR_BEACH_BATTLE_STATE, POST_BEACH_BATTLE
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_PACIFICA, 10, 23
	return


EnterJasmine_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	setflag FLAG_BADGE06_GET
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_GYM_6_STATE, GYM_DEFEATED_LEADER
	setvar VAR_JASMINE_STATE, BATTLE_1_COMPLETE
	warp MAP_GLDNGTEPARK, 0
	return


ANewStrike_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	clearflag FLAG_CONSTRUCTION_BREAKING_NEWS
	return


AndWeMarchOn_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	setvar VAR_HAIGHTASHBURY_STATE, PARADE_COMPLETE
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_HAIGHTASHBURY, 23, 7
	return


EnterPryce_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	additem ITEM_TM07
	setflag FLAG_BADGE07_GET
	setvar VAR_PRYCE_STATE, BATTLE_1_COMPLETE
	setvar VAR_GYM_7_STATE, GYM_DEFEATED_LEADER
	addvar VAR_STORYLINE_STATE, 1
	return


Battle8_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	setvar VAR_BATTLE_8_STATE, DEFEATED_ARCHER_PAINTEDLADIES
	addvar VAR_STORYLINE_STATE, 1
	warp MAP_PAINTEDLADIES, 19, 16
	return


EnterClair_Storywarp_Script::
	call YoungPadawan_Storywarp_Script
	additem ITEM_TM08
	setflag FLAG_BADGE08_GET
	setvar VAR_CLAIR_STATE, BATTLE_1_COMPLETE
	setvar VAR_GYM_8_STATE, GYM_DEFEATED_LEADER
	addvar VAR_STORYLINE_STATE, 1
	return


TheStrikeStrikesBack_Storywarp_Script::
	call Kogasraisondetre_Storywarp_Script
	call BeachBattle_Storywarp_Script
	call EnterJasmine_Storywarp_Script
	call ANewStrike_Storywarp_Script
	call AndWeMarchOn_Storywarp_Script
	call EnterPryce_Storywarp_Script
	call Battle8_Storywarp_Script
	call EnterClair_Storywarp_Script
	setvar VAR_CONSTRUCTION_STRIKE_STATE, START_VS_GARBODOR
	setvar VAR_STORYLINE_STATE, STORY_CALLED_TO_CONSTRUCTION
	warp MAP_PSFROUTE22, 0
	return


VSGarbodor_Storywarp_Script::
	call TheStrikeStrikesBack_Storywarp_Script
	setvar VAR_CONSTRUCTION_STRIKE_STATE, TEAM_ROCKET_ARRESTED
	setvar VAR_STORYLINE_STATE, STORY_NEED_SLEEP_BEFORE_SIEBOLD
	warp MAP_PSFROUTE22, 0
	return


UnknownAlcatrazCutscene_Storywarp_Script::
	return


OffYouGo_Storywarp_Script::
	call VSGarbodor_Storywarp_Script
	setvar VAR_GOLDENGATEBRIDGE_STATE, POST_OFF_YOU_GO
	setvar VAR_STORYLINE_STATE, STORY_ASSIGNED_SIEBOLD_QUESTS
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, BIANCA_INSIDE_TUNNEL
	warp MAP_SOUTHBAY_COMPOUND_2F, 0
	return


IGuessWeShouldBeNiceNow_Storywarp_Script::
	call OffYouGo_Storywarp_Script
	setvar VAR_MUIRWOODS_STATE, BIANCA_WAITING_MUIRWOODS
	setvar VAR_MARIN_STATE, ROBINWILLIAMSTUNNEL_PUZZLES_SOLVED
	warp MAP_MARIN, 0
	return


EntertheMaster_Storywarp_Script::
	call IGuessWeShouldBeNiceNow_Storywarp_Script
	setvar VAR_MUIRWOODS_STATE, MET_SIEBOLD
	warp MAP_MUIRWOODS_INNER, 0
	return


HaveYouSeenTheNews_Storywarp_Script::
	call EntertheMaster_Storywarp_Script
	setvar VAR_MUIRWOODS_STATE, POST_HAVE_YOU_SEEN_THE_NEWS
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, PRE_WELCOME_TO_THE_WAR_ROOM
	warp MAP_SALESFORCETOWER_LEAGUEOPS, 17, 29
	return


WelcometotheWarRoom_Storywarp_Script::
	call HaveYouSeenTheNews_Storywarp_Script
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_WELCOME_TO_THE_WAR_ROOM
	setvar VAR_FERRYBUILDING_STATE, CHIEF_LEFT_WAR_ROOM
	warp MAP_SALESFORCETOWER_LEAGUEOPS, 17, 29
	return


SurvivalChance333_Storywarp_Script::
	call WelcometotheWarRoom_Storywarp_Script
	setvar VAR_ALAMEDA_STATE, POST_SURVIVAL_CHANCE
	setvar VAR_FERRYBUILDING_STATE, DEFEATED_SURVIVAL_CHANCE_BATTLE
	warp MAP_ALAMEDA, 0
	return


WhyAreYouHelpingThem_Storywarp_Script::
	call SurvivalChance333_Storywarp_Script
	setvar VAR_NAVALBASE_STATE, DEFEATED_ARCHER_NAVALBASE
	setvar VAR_PLAYER_HOME_STATE, NEXT_DAY_CHAMPIONSHIP
	setvar VAR_STORYLINE_STATE, STORY_COMPLETED_NAVAL_BASE
	warp MAP_ALAMEDA, 0
	return


WhyAreYouHelpingThemSleep_Storywarp_Script::
	call WhyAreYouHelpingThem_Storywarp_Script
	setvar VAR_STORYLINE_STATE, STORY_START_CHAMPIONSHIP
	setvar VAR_ALAMEDA_STATE, SLEPT_AFTER_RAID
	warp MAP_CHASECENTER_LOCKERS, 9, 6
	return


HeresHowThisIsGoingToGo_Storywarp_Script::
	call WhyAreYouHelpingThemSleep_Storywarp_Script
	setvar VAR_STORYLINE_STATE, STORY_CHAMPIONSHIP_EXPLAINED
	warp MAP_CHASECENTER_LOCKERS, 9, 6
	return


WhyDidntYouRatMeOut_Storywarp_Script::
	call HeresHowThisIsGoingToGo_Storywarp_Script
	setvar VAR_STORYLINE_STATE, STORY_BIANCA_WON_GROUP
	return


GroupStages_Storywarp_Script::
	call WhyDidntYouRatMeOut_Storywarp_Script
	return


Finals_Storywarp_Script::
	call GroupStages_Storywarp_Script
	return


WaitHeDidWhat_Storywarp_Script::
	call Finals_Storywarp_Script
	return


WelcometotheHallofFame_Storywarp_Script::
	call WaitHeDidWhat_Storywarp_Script
	return


BeingChampionisHard_Storywarp_Script::
	call WelcometotheHallofFame_Storywarp_Script
	return


LetsGrabLunch_Storywarp_Script::
	call BeingChampionisHard_Storywarp_Script
	return


RestoreChinatown_Storywarp_Script::
	call LetsGrabLunch_Storywarp_Script
	return


RestoreTreasureIsland_Storywarp_Script::
	call RestoreChinatown_Storywarp_Script
	return


RestoreMain_Storywarp_Script::
	call RestoreTreasureIsland_Storywarp_Script
	return


RestoreHaightAshbury_Storywarp_Script::
	call RestoreMain_Storywarp_Script
	return


YouRealizeWereEvilRight_Storywarp_Script::
	call RestoreHaightAshbury_Storywarp_Script
	return


YouRealizeTheyreEvilRight_Storywarp_Script::
	call YouRealizeWereEvilRight_Storywarp_Script
	return


CongratsYoureanAsshole_Storywarp_Script::
	call YouRealizeTheyreEvilRight_Storywarp_Script
	return


YouHaveYourOrders_Storywarp_Script::
	call CongratsYoureanAsshole_Storywarp_Script
	return


HowDisappointing_Storywarp_Script::
	call YouHaveYourOrders_Storywarp_Script
	return


LetsBurnThisMotherDown_Storywarp_Script::
	call HowDisappointing_Storywarp_Script
	return


Manhunt_Storywarp_Script::
	call LetsBurnThisMotherDown_Storywarp_Script
	return


ExhibitionBattle_Storywarp_Script::
	call Manhunt_Storywarp_Script
	return


MaybeIFuckedUp_Storywarp_Script::
	call ExhibitionBattle_Storywarp_Script
	return


OkayLetsFixit_Storywarp_Script::
	call MaybeIFuckedUp_Storywarp_Script
	return


LetsGettheBandBackTogether_Storywarp_Script::
	call OkayLetsFixit_Storywarp_Script
	return


MaskOff_Storywarp_Script::
	call LetsGettheBandBackTogether_Storywarp_Script
	return


LetsFixThis_Storywarp_Script::
	call MaskOff_Storywarp_Script
	return


LockedOut_Storywarp_Script::
	call LetsFixThis_Storywarp_Script
	return


WarehouseRave_Storywarp_Script::
	call LockedOut_Storywarp_Script
	return


SpeechSpeechSpeech_Storywarp_Script::
	call WarehouseRave_Storywarp_Script
	return


OneDown_Storywarp_Script::
	call SpeechSpeechSpeech_Storywarp_Script
	return


Earthquake_Storywarp_Script::
	call OneDown_Storywarp_Script
	return


ThisIsntRandom_Storywarp_Script::
	call Earthquake_Storywarp_Script
	return


WaitEvenThen_Storywarp_Script::
	call ThisIsntRandom_Storywarp_Script
	return


LetsFinishThis_Storywarp_Script::
	call WaitEvenThen_Storywarp_Script
	return


ImIn_Storywarp_Script::
	call LetsFinishThis_Storywarp_Script
	return


YouCantStopMe_Storywarp_Script::
	call ImIn_Storywarp_Script
	return


WeCanStopYouActually_Storywarp_Script::
	call YouCantStopMe_Storywarp_Script
	return


EnterChuck_Storywarp_Script_Text_0:
	.string "yep$"
