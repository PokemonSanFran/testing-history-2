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
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 2
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
	release
	end


Debug_FlagsNotSetOverworldConfigMessage::
	lockall
	message Debug_FlagsNotSetOverworldConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end


Debug_FlagsNotSetBattleConfigMessage::
	lockall
	message Debug_FlagsNotSetBattleConfigMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end


Debug_Script_1::
	completequest QUEST_RESTOREHAIGHTASHBURY
	givecustommon SPECIES_BRELOOM, 100, ITEM_LEFTOVERS, ITEM_FRIEND_BALL, NATURE_ADAMANT, 0, 48, 252, 6, 204, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_SPORE, MOVE_SUBSTITUTE, MOVE_MACH_PUNCH, MOVE_FOCUS_PUNCH
	givecustommon SPECIES_SNORLAX, 100, ITEM_CHESTO_BERRY, ITEM_DREAM_BALL, NATURE_CAREFUL, 0, 136, 96, 60, 6, 0, 212, 31, 31, 31, 31, 31, 31, MOVE_CURSE, MOVE_REST, MOVE_BODY_SLAM, MOVE_SHADOW_BALL
	givecustommon SPECIES_STARMIE, 100, ITEM_LUM_BERRY, ITEM_DIVE_BALL, NATURE_MODEST, 0, 0, 0, 6, 252, 252, 0, 0, 31, 31, 31, 31, 31, MOVE_SURF, MOVE_PSYCHIC, MOVE_THUNDERBOLT, MOVE_ICE_BEAM, TRUE
	end


Debug_Script_2::
	warp MAP_HAIGHTASHBURY, 1
	end


Debug_Script_3::
	warp MAP_BATTLE_FRONTIER_EXCHANGE_SERVICE_CORNER, 0
	end


Debug_Script_4::
	call BattleFrontier_ScottsHouse_EventScript_Give1BattlePoint
	end


Debug_Script_5::
	givefrontierbattlepoints 10
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


Debug_CheckSaveBlock::
	callnative CheckSaveBlock1Size
	msgbox Debug_SaveBlock1Size, MSGBOX_DEFAULT
	callnative CheckSaveBlock2Size
	msgbox Debug_SaveBlock2Size, MSGBOX_DEFAULT
	callnative CheckPokemonStorageSize
	msgbox Debug_PokemonStorageSize, MSGBOX_DEFAULT
	release
	end


Debug_FlagsNotSetOverworldConfigMessage_Text::
	.string "Feature unavailable!\n"
	.string "Please define a usable flag in:\l"
	.string "'include/config/overworld.h'!$"

Debug_FlagsNotSetBattleConfigMessage_Text::
	.string "Feature unavailable!\n"
	.string "Please define a usable flag in:\l"
	.string "'include/config/battle.h'!$"

Debug_SaveBlock1Size::
	.string "SaveBlock1 size:\n"
	.string "{STR_VAR_1}/{STR_VAR_2}$"

Debug_SaveBlock2Size::
	.string "SaveBlock2 size:\n"
	.string "{STR_VAR_1}/{STR_VAR_2}$"

Debug_PokemonStorageSize::
	.string "{PKMN}Storage size:\n"
	.string "{STR_VAR_1}/{STR_VAR_2}$"
