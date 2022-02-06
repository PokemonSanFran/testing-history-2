Psfcity4_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity4_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity4_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity3_MapScripts_OnTransition
	return


Psfcity3_MapScripts_OnTransition::
	switch VAR_ROUTE107_STATE
	case 0, Psfcity3_MapScripts_OnTransition_2
	case 1, Psfcity3_MapScripts_OnTransition_3
	return

Psfcity3_MapScripts_OnTransition_2:
	call BeachBattle_ObjectSetUp_Script
	return

Psfcity3_MapScripts_OnTransition_3:
	call BeachBattle_BattleSetUp_Script
	return

