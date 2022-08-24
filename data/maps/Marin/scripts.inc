Marin_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Marin_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Marin_HideBianca_Script
	call Marin_HideLiidia_Script
	return

Marin_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Marin_LockRangerDoor_Script
	return

Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE115_STATE, 1, IGuessWeShouldBeNiceNow_ExitCave_Script
	map_script_2 VAR_STORYLINE_STATE, 41, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Marin_HideBianca_Script::
	switch VAR_ROUTE115_STATE
	setflag FLAG_TEMP_3
	removeobject 1
	return


Marin_HideLiidia_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES
	compare VAR_RESULT, 0
	goto_if_ne Marin_HideLiidia_Script_1
	return

Marin_HideLiidia_Script_1:
	setflag FLAG_TEMP_4
	return


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


gText_Marin_TheDoorIsLocked::
	.string "The door is locked.$"
