Psfcity12_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity12_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Psfcity12_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Psfcity12_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity12_MapScripts_OnTransition
	return

Psfcity12_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto Psfcity12_MapScripts_OnLoad
	return


Psfcity12_MapScripts_OnTransition::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne Psfcity12_MapScripts_OnTransition_1
	return

Psfcity12_MapScripts_OnTransition_1:
	call EnterPsfgoodadmin_ObjectCleanUp_Script
	return


Psfcity12_MapScripts_OnLoad::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne Psfcity12_MapScripts_OnLoad_1
	return

Psfcity12_MapScripts_OnLoad_1:
	call EnterPsfgoodadmin_SetConeTiles_Script
	return

