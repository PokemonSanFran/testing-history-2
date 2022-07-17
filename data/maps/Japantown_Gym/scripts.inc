Japantown_Gym_MapScripts::
	.byte 0


EnterBugsy_Event_Script::
	switch VAR_GYM_2_STATE
	case 3, EnterBugsy_Event_Script_2
	case 4, EnterBugsy_Event_Script_3
	case 5, EnterBugsy_Event_Script_4
	goto EnterBugsy_BugsyIntro_Dialogue
	return

EnterBugsy_Event_Script_2:
	goto EnterBugsy_StartGymBattle_Script
	return

EnterBugsy_Event_Script_3:
	goto EnterBugsy_PostDefeat1_Dialogue
	return

EnterBugsy_Event_Script_4:
	goto EnterBugsy_PostDefeat2_Dialogue
	return

