Gldngtebridge_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Gldngtebridge_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Gldngtebridge_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Gldngtebridge_MapScripts_OnTransition
	return


Gldngtebridge_MapScripts_OnTransition::
	switch VAR_ROUTE113_STATE
	case 1, Gldngtebridge_MapScripts_OnTransition_2
	goto OffYouGo_ObjectCleanUp_Script
	return

Gldngtebridge_MapScripts_OnTransition_2:
	return
