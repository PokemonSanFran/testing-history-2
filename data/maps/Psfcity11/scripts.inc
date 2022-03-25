Psfcity11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity11_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity11_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity11_MapScripts_OnTransition
	return


Psfcity11_MapScripts_OnTransition::
	goto swagbag2_SetUp_Object_Script
	return

