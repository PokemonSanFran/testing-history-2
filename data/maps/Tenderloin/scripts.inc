Tenderloin_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Tenderloin_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Tenderloin_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Tenderloin_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Tenderloin_MapScripts_OnTransition
	return

Tenderloin_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto Tenderloin_MapScripts_OnLoad
	return


Tenderloin_MapScripts_OnTransition::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne Tenderloin_MapScripts_OnTransition_1
	return

Tenderloin_MapScripts_OnTransition_1:
	call EnterAriana_ObjectCleanUp_Script
	return


Tenderloin_MapScripts_OnLoad::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne Tenderloin_MapScripts_OnLoad_1
	return

Tenderloin_MapScripts_OnLoad_1:
	call EnterAriana_SetConeTiles_Script
	return

