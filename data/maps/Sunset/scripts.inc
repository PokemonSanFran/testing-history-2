Sunset_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Sunset_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Sunset_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Sunset_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Sunset_MapScripts_OnTransition
	return

Sunset_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto Sunset_MapScripts_OnLoad
	return


Sunset_MapScripts_OnTransition::
	call ImIn_HideObject_OutsideHouse_Script
	return


Sunset_MapScripts_OnLoad::
	compare VAR_MAUVILLE_CITY_STATE, 0
	goto_if_ne Sunset_MapScripts_OnLoad_1
	return

Sunset_MapScripts_OnLoad_1:
	call ImIn_DestroyWall_Script
	return


Sabrina_House_LockedDoor_Script::
	msgbox gText_Sunset_LockedDoor, MSGBOX_SIGN
	end


gText_Sunset_LockedDoor::
	.string "The front door is locked.$"
