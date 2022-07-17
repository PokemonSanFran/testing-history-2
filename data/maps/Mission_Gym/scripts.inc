Mission_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Mission_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Mission_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_GYM_1_STATE
	case 3, Mission_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

Mission_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto EnterFalkner_StartGymBattle_ObjectSetup_Script
	return


EnterFalkner_Event_Script::
	switch VAR_GYM_1_STATE
	case 3, EnterFalkner_Event_Script_2
	case 4, EnterFalkner_Event_Script_3
	case 5, EnterFalkner_Event_Script_4
	goto EnterFalkner_PutMeatInOven_Dialogue
	return

EnterFalkner_Event_Script_2:
	goto EnterFalkner_StartGymBattle_Script
	return

EnterFalkner_Event_Script_3:
	goto EnterFalkner_PostDefeat1_Dialogue
	return

EnterFalkner_Event_Script_4:
	goto EnterFalkner_PostDefeat2_Dialogue
	return

