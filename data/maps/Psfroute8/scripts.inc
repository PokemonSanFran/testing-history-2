Psfroute8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute8_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Psfroute8_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfroute8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfroute8_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call ThisIsntRandom_HideObject_AboveGround_Script
	return

Psfroute8_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Psfroute8_MapScripts_OnLoad
	return

Psfroute8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_C, 0, ThisIsntRandom_CheckDoor_Script
	.2byte 0


Psfroute8_UncoverSecretLab_Script::
	setmetatile 11, 17, METATILE_General_CaveEntrance_Bottom, FALSE
	setmetatile 10, 16, 0x055, FALSE
	setmetatile 11, 16, 0x056, FALSE
	setmetatile 12, 16, 0x057, FALSE
	setmetatile 10, 17, 0x05D, FALSE
	setmetatile 12, 17, 0x05F, FALSE
	setmetatile 10, 18, 0x065, FALSE
	setmetatile 11, 18, 0x066, FALSE
	setmetatile 12, 18, 0x067, FALSE
	special DrawWholeMapView
	compare VAR_UNDERGROUNDLAB_STATE, LAB_NOT_DISCOVERED
	goto_if_eq Psfroute8_UncoverSecretLab_Script_1
	return

Psfroute8_UncoverSecretLab_Script_1:
	addvar VAR_UNDERGROUNDLAB_STATE, PLAYER_DISCOVERED_LAB
	setvar VAR_TEMP_C, 0
	return


Psfroute8_MapScripts_OnLoad::
	compare VAR_UNDERGROUNDLAB_STATE, 0
	goto_if_ne Psfroute8_MapScripts_OnLoad_1
	return

Psfroute8_MapScripts_OnLoad_1:
	call Psfroute8_UncoverSecretLab_Script
	return

