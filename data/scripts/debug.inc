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
	addvar VAR_TEMP_0, 1
	setweather WEATHER_FOG_DIAGONAL
	doweather
	return


Debug_Script_1::
	setflag FLAG_QUEST_ULTRAWORMHOLE_DONDOZO
	setflag FLAG_QUEST_ULTRAWORMHOLE_VOLCARONA
	setflag FLAG_QUEST_ULTRAWORMHOLE_DUSCLOPS
	setflag FLAG_QUEST_ULTRAWORMHOLE_CAMERUPT
	setflag FLAG_QUEST_ULTRAWORMHOLE_DEINO
	setflag FLAG_QUEST_ULTRAWORMHOLE_NOIVERN
	setflag FLAG_QUEST_ULTRAWORMHOLE_SHUCKLE
	setflag FLAG_QUEST_ULTRAWORMHOLE_KINGLER
	setflag FLAG_QUEST_ULTRAWORMHOLE_ORBEETLE
	setflag FLAG_QUEST_ULTRAWORMHOLE_DONPHAN
	additem ITEM_MASTER_BALL, 20
	warp MAP_SALESFORCETOWER_LAB, 0
	return


Debug_Script_2::
	end


Debug_Script_3::
	warp MAP_ULTRA_KANTO, 2, 2
	end


Debug_Script_4::
	call Quest_Ultrawormholeresearch_RanFromUltraBeast_Script
	end


Debug_Script_5::
	end


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
