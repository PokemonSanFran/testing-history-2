SOMA_Newspaper_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_Newspaper_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

SOMA_Newspaper_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Manhunt_HideBianca_Newspaper_Script
	call Quest_Redomugging_Hide_Victim_Script
	return


SOMA_Newspaper_InteractCherie_Event_Script::
	lock
	goto_if_set FLAG_TIMELINE_FALSE, SOMA_Newspaper_InteractCherie_Event_Script_2
	switch VAR_MASK_OFF_STATE
	case 0, SOMA_Newspaper_InteractCherie_Event_Script_10
	case 8, SOMA_Newspaper_InteractCherie_Event_Script_11
	call MaskOff_QuestH_Dialogue
SOMA_Newspaper_InteractCherie_Event_Script_1:
	release
	end

SOMA_Newspaper_InteractCherie_Event_Script_2:
	switch VAR_MANHUNT_STATE
	case NOT_ASSIGNED, SOMA_Newspaper_InteractCherie_Event_Script_6
	case ASSIGNED_FIND_GIOVANNI, SOMA_Newspaper_InteractCherie_Event_Script_7
	msgbox SOMA_Newspaper_InteractCherie_Event_Script_Text_0, MSGBOX_AUTOCLOSE
	goto SOMA_Newspaper_InteractCherie_Event_Script_1

SOMA_Newspaper_InteractCherie_Event_Script_6:
	return

SOMA_Newspaper_InteractCherie_Event_Script_7:
	call Manhunt_Cherie_Battle_Script
	goto SOMA_Newspaper_InteractCherie_Event_Script_1

SOMA_Newspaper_InteractCherie_Event_Script_10:
	return

SOMA_Newspaper_InteractCherie_Event_Script_11:
	return


SOMA_Newspaper_InteractCherie_Event_Script_Text_0:
	.string "...$"
