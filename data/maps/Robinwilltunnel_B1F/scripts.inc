Robinwilltunnel_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Robinwilltunnel_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Robinwilltunnel_B1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Robinwilltunnel_B1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Robinwilltunnel_B1F_MapScripts_OnTransition
	return

Robinwilltunnel_B1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROBINWILLIAMSTUNNEL_STATE, 1, IGuessWeShouldBeNiceNow_FirstEnterMaze_Dialogue
	.2byte 0


Robinwilltunnel_B1F_MapScripts_OnTransition::
	switch VAR_ROBINWILLIAMSTUNNEL_STATE
	case 0, Robinwilltunnel_B1F_MapScripts_OnTransition_2
	case 1, Robinwilltunnel_B1F_MapScripts_OnTransition_3
	case 2, Robinwilltunnel_B1F_MapScripts_OnTransition_4
	case 3, Robinwilltunnel_B1F_MapScripts_OnTransition_5
	case 4, Robinwilltunnel_B1F_MapScripts_OnTransition_6
	case 5, Robinwilltunnel_B1F_MapScripts_OnTransition_7
	case 6, Robinwilltunnel_B1F_MapScripts_OnTransition_8
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_2:
	goto IGuessWeShouldBeNiceNow_HideObject_Script
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_3:
	goto IGuessWeShouldBeNiceNow_ObjectSetup_Script
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_4:
	goto IGuessWeShouldBeNiceNow_PuzzlePrepareObject_Script
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_5:
	goto IGuessWeShouldBeNiceNow_PuzzleStartObject_Script
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_6:
	goto IGuessWeShouldBeNiceNow_PuzzleStartObject_Script
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_7:
	goto IGuessWeShouldBeNiceNow_PuzzleBSolvedObject_Script
	return

Robinwilltunnel_B1F_MapScripts_OnTransition_8:
	goto IGuessWeShouldBeNiceNow_PostCleanUp_Script
	return

