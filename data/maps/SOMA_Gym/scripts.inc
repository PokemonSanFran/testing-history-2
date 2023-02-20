SOMA_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SOMA_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SOMA_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto SOMA_Gym_MapScripts_OnTransition
	return

SOMA_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_WHITNEY_STATE, EXHIBITION_READY, Quest_Alohafromalola_StartBattle_Dialogue
	.2byte 0


SOMA_Gym_MapScripts_OnTransition::
	switch VAR_GYM_3_STATE
	case 0, SOMA_Gym_MapScripts_OnTransition_2
	case 1, SOMA_Gym_MapScripts_OnTransition_3
	goto EnterWhitney_StartBattle_ObjectSetup_Script
	return

SOMA_Gym_MapScripts_OnTransition_2:
	return

SOMA_Gym_MapScripts_OnTransition_3:
	setflag FLAG_TEMP_1
	return


Whitney_Event_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	switch VAR_GYM_3_STATE
	case 2, Whitney_Event_Script_2
	case 3, Whitney_Event_Script_3
	case 4, Whitney_Event_Script_4
	case 5, Whitney_Event_Script_5
	return

Whitney_Event_Script_2:
	goto EnterWhitney_MuseumArrangement_Dialogue
	return

Whitney_Event_Script_3:
	goto EnterWhitney_StartBattle_Script
	return

Whitney_Event_Script_4:
	goto EnterWhitney_PostBattle_Dialogue
	return

Whitney_Event_Script_5:
	goto EnterWhitney_PostBattle_Dialogue2
	return

