Psfroute9_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute9_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute9_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfroute9_MapScripts_OnTransition
	return


Psfroute9_MapScripts_OnTransition::
	compare VAR_PSFROUTE9_STATE, 1
	goto_if_gt Psfroute9_MapScripts_OnTransition_1
	return

Psfroute9_MapScripts_OnTransition_1:
	setflag FLAG_TEMP_1
	return

