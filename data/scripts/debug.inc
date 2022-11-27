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
	msgbox Debug_Script_1_Text_0
	return


Debug_Script_2::
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_RETURNDOLL
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_BRINGFRUIT
	setvar VAR_STORYLINE_STATE, STORY_CLEAR
	msgbox Debug_Script_2_Text_0
	msgbox gText_Quest_ReturnDoll_Desc
	msgbox Debug_Script_2_Text_1
	return


Debug_Script_3::
	setvar VAR_STORYLINE_STATE, STORY_CLEAR
	questmenu QUEST_MENU_SET_ACTIVE, QUEST_BRINGFIRETYPE
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RETURNDOLL
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BRINGFRUIT
	msgbox Debug_Script_3_Text_0
	msgbox gText_Quest_BringFruit_Desc
	msgbox Debug_Script_3_Text_1
	return


Debug_Script_4::
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BRINGFIRETYPE
	questmenu QUEST_MENU_SET_REWARD, QUEST_STOPMUGGING
	msgbox Debug_Script_4_Text_0
	msgbox Debug_Script_3_Text_1
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


Debug_Script_1_Text_0:
	.string "please run Script 2, then script 3, then\n"
	.string "script 4.$"

Debug_Script_2_Text_0:
	.string "this is scenario Active and Favorite.\n"
	.string "The start menu should display:$"

Debug_Script_2_Text_1:
	.string "Please press {START_BUTTON}, open the Quest Menu, and\n"
	.string "press {SELECT_BUTTON} on the quest Return Doll and\l"
	.string "Bring Fruit$"

Debug_Script_3_Text_0:
	.string "this is scenario Active. The start menu\n"
	.string "should display:$"

Debug_Script_3_Text_1:
	.string "Please press {START_BUTTON}.$"

Debug_Script_4_Text_0:
	.string "This is scenario NULL. The start menu\n"
	.string "should not be displaying anything.$"

Debug_CheckWeekDay_Text::
	.string "Aaaah, yes!\l"
	.string "{STR_VAR_1}s are made for dads!\l"
	.string "And dad's car!$"

Debug_FlagsNotSetMessage_Text::
	.string "feature unavailable$"
