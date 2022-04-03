Psfroute62_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute62_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute62_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfroute62_MapScripts_OnTransition
	return


Psfroute62_MapScripts_OnTransition::
	compare VAR_RUSTURF_TUNNEL_STATE, 4
	goto_if_ne Psfroute62_MapScripts_OnTransition_1
	return

Psfroute62_MapScripts_OnTransition_1:
	call Manhunt_HideObject_Script
	return

