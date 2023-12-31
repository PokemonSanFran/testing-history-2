Psfroute62_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute62_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Psfroute62_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Psfroute62_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Psfroute62_RouteFlag_Script
	call Quest_Ultrawormholeresearch_ControlTotemVisibility
	goto Psfroute62_MapScripts_OnTransition
	return

Psfroute62_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_Ultrawormholeresearch_TryRemoveTotem_Script
	return


Psfroute62_RouteFlag_Script::
	goto_if_set FLAG_VISITED_OAKLANDCOLISEUM, Psfroute62_RouteFlag_Script_3
Psfroute62_RouteFlag_Script_1:
	return

Psfroute62_RouteFlag_Script_2:
	setflag FLAG_VISITED_PSFROUTE62
	goto Psfroute62_RouteFlag_Script_1

Psfroute62_RouteFlag_Script_3:
	goto_if_set FLAG_VISITED_OAKLAND, Psfroute62_RouteFlag_Script_2
	goto Psfroute62_RouteFlag_Script_1


Psfroute62_MapScripts_OnTransition::
	setflag FLAG_TEMP_2
	return


Psfroute62_InteractMatthew_Event_Script::
	lock
	goto_if_set FLAG_TIMELINE_FALSE, Psfroute62_InteractMatthew_Event_Script_2
	switch VAR_MASK_OFF_STATE
	case NOT_ASSIGNED, Psfroute62_InteractMatthew_Event_Script_10
	case ASSIGNED_MASK_OFF, Psfroute62_InteractMatthew_Event_Script_10
	case GOT_MASK_OFF_CLUE_1, Psfroute62_InteractMatthew_Event_Script_10
	case GOT_MASK_OFF_CLUE_2, Psfroute62_InteractMatthew_Event_Script_10
	case GOT_MASK_OFF_CLUE_3, Psfroute62_InteractMatthew_Event_Script_10
	call MaskOff_QuestE_Dialogue
Psfroute62_InteractMatthew_Event_Script_1:
	release
	end

Psfroute62_InteractMatthew_Event_Script_2:
	switch VAR_MANHUNT_STATE
	case NOT_ASSIGNED, Psfroute62_InteractMatthew_Event_Script_6
	case GOT_MANHUNT_CLUE_3, Psfroute62_InteractMatthew_Event_Script_7
	msgbox Psfroute62_InteractMatthew_Event_Script_Text_0, MSGBOX_AUTOCLOSE
	goto Psfroute62_InteractMatthew_Event_Script_1

Psfroute62_InteractMatthew_Event_Script_6:
	return

Psfroute62_InteractMatthew_Event_Script_7:
	call Manhunt_Matthew_Battle_Script
	goto Psfroute62_InteractMatthew_Event_Script_1

Psfroute62_InteractMatthew_Event_Script_10:
	return


Psfroute62_InteractMatthew_Event_Script_Text_0:
	.string "...$"
