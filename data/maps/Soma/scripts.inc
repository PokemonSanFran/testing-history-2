SOMA_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto SOMA_MapScripts_OnTransition
	return

SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SOMA_STATE, 1, WowYoureStrong_WalkToPlayer_Script
	.2byte 0


SOMA_MapScripts_OnTransition::
	goto_if_unset FLAG_BADGE03_GET, SOMA_MapScripts_OnTransition_1
	compare VAR_SOMA_STATE, 1
	goto_if_gt SOMA_MapScripts_OnTransition_1
	return

SOMA_MapScripts_OnTransition_1:
	setflag FLAG_TEMP_1
	return

