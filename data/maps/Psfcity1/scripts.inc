Psfcity1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity1_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Psfcity1_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Psfcity1_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity1_MapScripts_OnTransition
	return

Psfcity1_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto Psfcity1_MapScripts_OnLoad
	return


Psfcity1_MapScripts_OnTransition::
	call ImIn_HideObject_OutsideHouse_Script
	return


Psfcity1_MapScripts_OnLoad::
	compare VAR_MAUVILLE_CITY_STATE, 0
	goto_if_ne Psfcity1_MapScripts_OnLoad_1
	return

Psfcity1_MapScripts_OnLoad_1:
	call ImIn_DestroyWall_Script
	return


Psfbadadmin3_House_LockedDoor_Script::
	msgbox gText_Psfcity1_LockedDoor, MSGBOX_SIGN
	end


gText_Psfcity1_LockedDoor::
	.string "The front door is locked.$"
