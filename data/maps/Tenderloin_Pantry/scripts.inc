Tenderloin_Pantry_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Tenderloin_Pantry_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Tenderloin_Pantry_MapScripts_MAP_SCRIPT_ON_LOAD:
	return


Tenderloin_Pantry_CheckDoor_Script::
	msgbox gText_Tenderloin_Pantry_TheDoorIsLocked, MSGBOX_AUTOCLOSE
	checkitem ITEM_STORAGE_KEY, 1
	compare VAR_RESULT, 0
	goto_if_ne Tenderloin_Pantry_CheckDoor_Script_2
Tenderloin_Pantry_CheckDoor_Script_1:
	end

Tenderloin_Pantry_CheckDoor_Script_2:
	goto Tenderloin_Pantry_UnlockDoor_Script
	goto Tenderloin_Pantry_CheckDoor_Script_1


Tenderloin_Pantry_UnlockDoor_Script::
	bufferitemname STR_VAR_1, ITEM_STORAGE_KEY
	msgbox gText_Tenderloin_Pantry_UseTheKeyTo, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Tenderloin_Pantry_UnlockDoor_Script_2
	closemessage
	end

Tenderloin_Pantry_UnlockDoor_Script_2:
	closemessage
	warpdoor MAP_TENDERLOIN_PANTRY_MAZE, 0
	waitstate
	end


gText_Tenderloin_Pantry_TheDoorIsLocked::
	.string "The door is locked.$"

gText_Tenderloin_Pantry_UseTheKeyTo::
	.string "Use the {STR_VAR_1} to unlock the\n"
	.string "door?$"
