Psfcave2_Inner_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcave2_Inner_MapScripts_OnTransition
	return

Psfcave2_Inner_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE116_STATE, 3, EnterTheMaster_ClearingIntro_Dialogue
	map_script_2 VAR_ROUTE116_STATE, 5, HaveYouSeenTheNews_AskHelp_Dialogue
	.2byte 0


Psfcave2_Inner_MapScripts_OnTransition::
	switch VAR_ROUTE116_STATE
	case 3, Psfcave2_Inner_MapScripts_OnTransition_2
	case 5, Psfcave2_Inner_MapScripts_OnTransition_3
	goto EnterTheMaster_HideObject_Script
	return

Psfcave2_Inner_MapScripts_OnTransition_2:
	goto EnterTheMaster_Clearing_Object_SetUp_Script
	return

Psfcave2_Inner_MapScripts_OnTransition_3:
	return


HaveYouSeenTheNews_SolvePuzzles_Script::
	addvar VAR_ROUTE116_STATE, 1
	msgbox HaveYouSeenTheNews_SolvePuzzles_Script_Text_0
	closemessage
	return


Psfcave2_Psfelite3_Interact_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	switch VAR_ROUTE116_STATE
	case 6, Psfcave2_Psfelite3_Interact_Script_3
	msgbox gText_EnterTheMaster_WellUntilNSFigures
Psfcave2_Psfelite3_Interact_Script_1:
	callnative ClearMugshot
	closemessage
	release
	end

Psfcave2_Psfelite3_Interact_Script_3:
	msgbox gText_HaveYouSeenTheNews_SoundsLikeYouve
	goto Psfcave2_Psfelite3_Interact_Script_1


HaveYouSeenTheNews_SolvePuzzles_Script_Text_0:
	.string "you've solved Psfelite3's tests. go\n"
	.string "back now.$"
