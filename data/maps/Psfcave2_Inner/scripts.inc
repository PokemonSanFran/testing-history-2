Psfcave2_Inner_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcave2_Inner_MapScripts_OnTransition
	return

Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE116_STATE, 3, EnterTheMaster_ClearingIntro_Dialogue
	map_script_2 VAR_ROUTE116_STATE, 7, HaveYouSeenTheNews_AskHelp_Dialogue
	.2byte 0


Psfcave2_Inner_MapScripts_OnTransition::
	switch VAR_ROUTE116_STATE
	case 0, Psfcave2_Inner_MapScripts_OnTransition_2
	case 3, Psfcave2_Inner_MapScripts_OnTransition_3
	case 7, Psfcave2_Inner_MapScripts_OnTransition_4
	case 8, Psfcave2_Inner_MapScripts_OnTransition_5
	return

Psfcave2_Inner_MapScripts_OnTransition_2:
	goto EnterTheMaster_HideObject_Script
	return

Psfcave2_Inner_MapScripts_OnTransition_3:
	goto EnterTheMaster_Clearing_Object_SetUp_Script
	return

Psfcave2_Inner_MapScripts_OnTransition_4:
	goto HaveYouSeenTheNews_Object_SetUp_Script
	return

Psfcave2_Inner_MapScripts_OnTransition_5:
	goto HaveYouSeenTheNews_Object_CleanUp_Script
	return


HaveYouSeenTheNews_SolvePuzzles::
	setvar VAR_ROUTE116_STATE, 7
	msgbox HaveYouSeenTheNews_SolvePuzzles_Text_0
	closemessage
	return


HaveYouSeenTheNews_SolvePuzzles_Text_0:
	.string "you've solved Psfelite3's tests. go back now.$"
