Psfroute8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute8_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfroute8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfroute8_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfroute8_MapScripts_OnTransition
	return

Psfroute8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	.2byte 0


Psfroute8_UncoverSecretLab_Script::
	setmetatile 10, 16, 0x055, FALSE
	setmetatile 11, 16, 0x056, FALSE
	setmetatile 12, 16, 0x057, FALSE
	setmetatile 10, 17, 0x05D, FALSE
	setmetatile 11, 17, METATILE_General_CaveEntrance_Bottom, FALSE
	setmetatile 12, 17, 0x05F, FALSE
	setmetatile 10, 18, 0x065, FALSE
	setmetatile 11, 18, 0x066, FALSE
	setmetatile 12, 18, 0x067, FALSE
	special DrawWholeMapView
	return


Psfroute8_MapScripts_OnTransition::
	goto_if_set FLAG_SYS_BRAILLE_DIG, Psfroute8_MapScripts_OnTransition_1
	return

Psfroute8_MapScripts_OnTransition_1:
	call Psfroute8_UncoverSecretLab_Script
	return

