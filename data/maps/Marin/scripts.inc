Marin_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Marin_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Marin_HideBianca_Script
	call Marin_HideLiidia_Script
	call Quest_BerrySustaiability_HideLeader_Script
	call Quest_GetTheBand_HideBikerD_Script
	call IGuessWeShouldBeNiceNow_HidePopup_Script
	return

Marin_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Marin_LockRangerDoor_Script
	return

Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MARIN_STATE, ROBINWILLIAMSTUNNEL_PUZZLES_SOLVED, IGuessWeShouldBeNiceNow_ExitCave_Script
	map_script_2 VAR_STORYLINE_STATE, STORY_RESTORATION_1_COMPLETE, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Marin_HideBianca_Script::
	setflag FLAG_TEMP_3
	return


Marin_HideLiidia_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES
	compare VAR_RESULT, 0
	goto_if_ne Marin_HideLiidia_Script_2
Marin_HideLiidia_Script_1:
	return

Marin_HideLiidia_Script_2:
	setflag FLAG_TEMP_4
	goto Marin_HideLiidia_Script_1


Marin_LockRangerDoor_Script::
	checkitem ITEM_KEY_TO_ROOM_1, 1
	compare VAR_RESULT, 0
	goto_if_eq Marin_LockRangerDoor_Script_1
	return

Marin_LockRangerDoor_Script_1:
	setmetatile 13, 8, 0x23B, TRUE
	return


Marin_RangerStationDoor_Script::
	lock
	checkitem ITEM_KEY_TO_ROOM_1, 1
	compare VAR_RESULT, 0
	goto_if_eq Marin_RangerStationDoor_Script_1
	return

Marin_RangerStationDoor_Script_1:
	msgbox gText_Marin_TheDoorIsLocked, MSGBOX_SIGN
	release
	end


Marin_Stan_Interact_Script::
	lock
	call Quest_WallaceArmy_LoadStanSpeech_Script
	msgbox gText_WallaceArmy_OhWallaceSama, MSGBOX_NPC
	call Quest_WallaceArmy_PreBattleStan_Script
	trainerbattle_single TRAINER_LOLA_5, gText_WallaceArmy_MarinSolarTheySpoke, gText_WallaceArmy_MyLord, Marin_Stan_PostBattle_Script
	goto Marin_Stan_PostBattle_Script
	return


Marin_Stan_PostBattle_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WALLACEARMY, SUB_QUEST_5
	call Quest_WallaceArmy_CheckCompletionRate_Script
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Marin_Stan_PostBattle_Script_2
	msgbox gText_WallaceArmy_PostQuestPlaceholder1
Marin_Stan_PostBattle_Script_1:
	release
	end

Marin_Stan_PostBattle_Script_2:
	msgbox gText_WallaceArmy_PostBattlePlaceholder1
	goto Marin_Stan_PostBattle_Script_1


Marin_HideMapNamePopup_Script::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return


Marin_Biker_Interact_Script::
	msgbox gText_Marin_PlaceholderBiker, MSGBOX_NPC
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_GETTHEBANDBACKTOGETHER
	compare VAR_RESULT, 0
	goto_if_ne Marin_Biker_Interact_Script_2
Marin_Biker_Interact_Script_1:
	end

Marin_Biker_Interact_Script_2:
	goto Quest_GetTheBand_Interact_BikerD_Dialogue
	goto Marin_Biker_Interact_Script_1


gText_Marin_PlaceholderBiker::
	.string "i am a biker, and this is placeholder\n"
	.string "text.$"

gText_Marin_TheDoorIsLocked::
	.string "The door is locked.$"
