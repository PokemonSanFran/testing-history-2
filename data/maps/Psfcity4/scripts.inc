Psfcity4_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity4_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity4_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 17, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


Psfcity4_MapScripts_OnTransition::
	switch VAR_ROUTE107_STATE
	case 0, Psfcity4_MapScripts_OnTransition_2
	case 1, Psfcity4_MapScripts_OnTransition_3
	return

Psfcity4_MapScripts_OnTransition_2:
	call BeachBattle_ObjectSetUp_Script
	return

Psfcity4_MapScripts_OnTransition_3:
	call BeachBattle_BattleSetUp_Script
	return

