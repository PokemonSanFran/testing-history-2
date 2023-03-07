Mission_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Mission_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Mission_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call EnterFalkner_StartGymBattle_ObjectSetup_Script
	call Mission_Gym_Leader_Visibility_Script
	return


Mission_Gym_Leader_Visibility_Script::
	switch VAR_FALKNER_STATE
	case NO_BADGE, Mission_Gym_Leader_Visibility_Script_3
	case QUEST_2_COMPLETE, Mission_Gym_Leader_Visibility_Script_3
	case BATTLE_2_COMPLETE, Mission_Gym_Leader_Visibility_Script_3
	setflag FLAG_TEMP_1
	return

Mission_Gym_Leader_Visibility_Script_3:
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

