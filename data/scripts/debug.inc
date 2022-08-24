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
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setflag FLAG_RECEIVED_BIKE
	giveitem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	closemessage
	release
	end


Debug_Script_1::
	warp MAP_MUIRWOODS, 45, 9
	end


Debug_Script_2::
	warp MAP_MARIN, 13, 10
	end


Debug_Script_3::
	end


Debug_Script_4::
	end


Debug_Script_5::
	end


Debug_Script_6::
	end


Debug_Script_7::
	warp MAP_PSFROUTE61, 23, 4
	end


Debug_Script_8::
	warp MAP_PSFROUTE70, 4, 11
	end


Debug_Script_9::
	warp MAP_PSFROUTE21, 30, 5
	end


Debug_Script_10::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_3
	call Quest_ArtisanBalls2_CheckReward_Script
	end


Debug_CheckWeekDay_Text::
	.string "Aaaah, yes!\l"
	.string "{STR_VAR_1}s are made for dads!\l"
	.string "And dad's car!$"
