Psfcity15_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity15_Gym_MapScripts_OnTransition
	return

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_GYM_3_STATE, 1, EnterPsfleader3_WalkToBattlefield_Script
	.2byte 0


Psfcity15_Gym_MapScripts_OnTransition::
	switch VAR_GYM_3_STATE
	case 1, Psfcity15_Gym_MapScripts_OnTransition_2
	case 2, Psfcity15_Gym_MapScripts_OnTransition_3
	return

Psfcity15_Gym_MapScripts_OnTransition_2:
	goto EnterPsfleader3_ObjectSetUp_Script
	return

Psfcity15_Gym_MapScripts_OnTransition_3:
	goto EnterPsfleader3_StartBattle_ObjectSetup_Script
	return


Psfleader3_Event_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	switch VAR_GYM_3_STATE
	case 2, Psfleader3_Event_Script_2
	case 3, Psfleader3_Event_Script_3
	case 4, Psfleader3_Event_Script_4
	case 5, Psfleader3_Event_Script_5
	return

Psfleader3_Event_Script_2:
	goto EnterPsfleader3_MuseumArrangement_Dialogue
	return

Psfleader3_Event_Script_3:
	goto EnterPsfleader3_StartBattle_Script
	return

Psfleader3_Event_Script_4:
	goto EnterPsfleader3_PostBattle_Dialogue
	return

Psfleader3_Event_Script_5:
	goto EnterPsfleader3_PostBattle_Dialogue2
	return

