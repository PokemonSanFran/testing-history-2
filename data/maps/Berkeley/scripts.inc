Berkeley_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Berkeley_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Berkeley_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Berkeley_MapScripts_OnTransition
	return


Berkeley_MapScripts_OnTransition::
	goto swagbag2_SetUp_Object_Script
	return

