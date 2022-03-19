Psfcity14_Gym_MapScripts::
	.byte 0


EnterPsfleader2_Event_Script::
	switch VAR_GYM_2_STATE
	case 3, EnterPsfleader2_Event_Script_2
	case 4, EnterPsfleader2_Event_Script_3
	case 5, EnterPsfleader2_Event_Script_4
	goto EnterPsfleader2_Psfleader2Intro_Dialogue
	return

EnterPsfleader2_Event_Script_2:
	goto EnterPsfleader2_StartGymBattle_Script
	return

EnterPsfleader2_Event_Script_3:
	goto EnterPsfleader2_PostDefeat1_Dialogue
	return

EnterPsfleader2_Event_Script_4:
	goto EnterPsfleader2_PostDefeat2_Dialogue
	return

