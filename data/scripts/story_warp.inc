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
	warp MAP_ALAMEDA, 20, 5
	return


HousingProtest_Storywarp_Script::
	call AssholesHome_Storywarp_Script
	addvar VAR_STORYLINE_STATE, 1
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
	addvar VAR_STORYLINE_STATE, 1
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
	return


YoungPadawan_Storywarp_Script::
	return


WaitYouWentWhere_Storywarp_Script::
	return


EnterChuck_Storywarp_Script::
	return


YouLookTired_Storywarp_Script::
	return


Kogasraisondetre_Storywarp_Script::
	return


BeachBattle_Storywarp_Script::
	return


EnterJasmine_Storywarp_Script::
	return


ANewStrike_Storywarp_Script::
	return


AndWeMarchOn_Storywarp_Script::
	return


EnterPryce_Storywarp_Script::
	return


Battle8_Storywarp_Script::
	return


EnterClair_Storywarp_Script::
	return


TheStrikeStrikesBack_Storywarp_Script::
	return


VSGarbodor_Storywarp_Script::
	return


UnknownAlcatrazCutscene_Storywarp_Script::
	return


OffYouGo_Storywarp_Script::
	return


IGuessWeShouldBeNiceNow_Storywarp_Script::
	return


EntertheMaster_Storywarp_Script::
	return


HaveYouSeenTheNews_Storywarp_Script::
	return


WelcometotheWarRoom_Storywarp_Script::
	return


SurvivalChance333_Storywarp_Script::
	return


WhyAreYouHelpingThem_Storywarp_Script::
	return


HeresHowThisIsGoingToGo_Storywarp_Script::
	return


WhyDidntYouRatMeOut_Storywarp_Script::
	return


GroupStages_Storywarp_Script::
	return


Finals_Storywarp_Script::
	return


WaitHeDidWhat_Storywarp_Script::
	return


WelcometotheHallofFame_Storywarp_Script::
	return


BeingChampionisHard_Storywarp_Script::
	return


LetsGrabLunch_Storywarp_Script::
	return


RestoreChinatown_Storywarp_Script::
	return


RestoreTreasureIsland_Storywarp_Script::
	return


RestoreMain_Storywarp_Script::
	return


RestoreHaightAshbury_Storywarp_Script::
	return


YouRealizeWereEvilRight_Storywarp_Script::
	return


YouRealizeTheyreEvilRight_Storywarp_Script::
	return


CongratsYoureanAsshole_Storywarp_Script::
	return


YouHaveYourOrders_Storywarp_Script::
	return


HowDisappointing_Storywarp_Script::
	return


LetsBurnThisMotherDown_Storywarp_Script::
	return


Manhunt_Storywarp_Script::
	return


ExhibitionBattle_Storywarp_Script::
	return


MaybeIFuckedUp_Storywarp_Script::
	return


OkayLetsFixit_Storywarp_Script::
	return


LetsGettheBandBackTogether_Storywarp_Script::
	return


MaskOff_Storywarp_Script::
	return


LetsFixThis_Storywarp_Script::
	return


LockedOut_Storywarp_Script::
	return


WarehouseRave_Storywarp_Script::
	return


SpeechSpeechSpeech_Storywarp_Script::
	return


OneDown_Storywarp_Script::
	return


Earthquake_Storywarp_Script::
	return


ThisIsntRandom_Storywarp_Script::
	return


WaitEvenThen_Storywarp_Script::
	return


LetsFinishThis_Storywarp_Script::
	return


ImIn_Storywarp_Script::
	return


YouCantStopMe_Storywarp_Script::
	return


WeCanStopYouActually_Storywarp_Script::
	return

