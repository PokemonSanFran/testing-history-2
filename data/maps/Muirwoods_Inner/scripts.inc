Muirwoods_Inner_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Muirwoods_Inner_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Muirwoods_Inner_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Muirwoods_Inner_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Muirwoods_Inner_MapScripts_OnTransition
	return

Muirwoods_Inner_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MUIRWOODS_STATE, 3, EnterTheMaster_ClearingIntro_Dialogue
	map_script_2 VAR_MUIRWOODS_STATE, 5, HaveYouSeenTheNews_AskHelp_Dialogue
	.2byte 0


Muirwoods_Inner_MapScripts_OnTransition::
	switch VAR_MUIRWOODS_STATE
	case 3, Muirwoods_Inner_MapScripts_OnTransition_2
	case 5, Muirwoods_Inner_MapScripts_OnTransition_3
	goto EnterTheMaster_HideObject_Script
	return

Muirwoods_Inner_MapScripts_OnTransition_2:
	goto EnterTheMaster_Clearing_Object_SetUp_Script
	return

Muirwoods_Inner_MapScripts_OnTransition_3:
	return


HaveYouSeenTheNews_SolvePuzzles_Script::
	addvar VAR_MUIRWOODS_STATE, 1
	msgbox HaveYouSeenTheNews_SolvePuzzles_Script_Text_0
	closemessage
	return


Muirwoods_Siebold_Interact_Script::
	lock
	faceplayer
	switch VAR_MUIRWOODS_STATE
	case 6, Muirwoods_Siebold_Interact_Script_3
	call EnterTheMaster_ExplainRobots_Dialogue
Muirwoods_Siebold_Interact_Script_1:
	closemessage
	release
	end

Muirwoods_Siebold_Interact_Script_3:
	msgbox gText_HaveYouSeenTheNews_SoundsLikeYouve, , SPEAKER_SIEBOLD
	goto Muirwoods_Siebold_Interact_Script_1


HaveYouSeenTheNews_SolvePuzzles_Script_Text_0:
	.string "you've solved Siebold's tests. go back\n"
	.string "now.$"
