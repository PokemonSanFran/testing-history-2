Psfroute8_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute8_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfroute8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfroute8_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfroute8_MapScripts_OnTransition
	return

Psfroute8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 FLAG_SYS_BRAILLE_DIG, TRUE, Debug_Script_2
	.2byte 0


Psfroute8_MapScripts_OnTransition::
	return

