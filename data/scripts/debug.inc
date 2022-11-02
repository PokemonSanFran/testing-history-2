Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end


Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	closemessage
	release
	end


Debug_FlagsNotSetMessage::
	lockall
	message Debug_FlagsNotSetMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end


Debug_Weather::
	setweather WEATHER_FOG_DIAGONAL
	doweather
	return


Debug_Script_1::
	warp MAP_PACIFICA, 6, 17
	return


Debug_Script_2::
	warp MAP_CHINATOWN_GYM, 0
	return


Debug_Script_3::
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_A
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_B
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_C
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_D
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_E
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_F
	setflag TRAINER_FLAGS_START + TRAINER_BLACKBELT_G
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_1
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_2
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_3
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_4
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_5
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_6
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORECHINATOWN, SUB_QUEST_7
	addvar VAR_QUEST_RESTORECHINATOWN, 1
	call Quest_Restorechinatown_CheckProgress_Script
	warp MAP_CHINATOWN_GYM, 0
	return


Debug_Script_4::
	call LetsGrabLunch_CheckRestorationProgress_Script
	return


Debug_Script_5::
	return


Debug_Script_6::
	end


Debug_Script_7::
	end


Debug_Script_8::
	end


Debug_Script_9::
	end


Debug_Script_10::
	end


Debug_CheckWeekDay_Text::
	.string "Aaaah, yes!\l"
	.string "{STR_VAR_1}s are made for dads!\l"
	.string "And dad's car!$"

Debug_FlagsNotSetMessage_Text::
	.string "feature unavailable$"
