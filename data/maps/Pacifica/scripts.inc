Pacifica_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Pacifica_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Pacifica_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Pacifica_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Pacifica_MapScripts_OnTransition
	return

Pacifica_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 21, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


Pacifica_MapScripts_OnTransition::
	switch VAR_ROUTE107_STATE
	case 0, Pacifica_MapScripts_OnTransition_2
	case 1, Pacifica_MapScripts_OnTransition_3
	call BeachBattle_ObjectSetUp_Script
	return

Pacifica_MapScripts_OnTransition_2:
	return

Pacifica_MapScripts_OnTransition_3:
	call BeachBattle_BattleSetUp_Script
	return

