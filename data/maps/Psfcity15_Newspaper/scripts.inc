Psfcity15_Newspaper_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity15_Newspaper_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity15_Newspaper_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity15_Newspaper_MapScripts_OnTransition
	return


Psfcity15_Newspaper_InteractCherie_Event_Script::
	lock
	goto_if_set FLAG_TIMELINE_FALSE, Psfcity15_Newspaper_InteractCherie_Event_Script_2
	switch VAR_RUSTURF_TUNNEL_STATE
	case 8, Psfcity15_Newspaper_InteractCherie_Event_Script_9
	call MaskOff_QuestH_Dialogue
Psfcity15_Newspaper_InteractCherie_Event_Script_1:
	release
	end

Psfcity15_Newspaper_InteractCherie_Event_Script_2:
	switch VAR_RUSTURF_TUNNEL_STATE
	case 1, Psfcity15_Newspaper_InteractCherie_Event_Script_6
	msgbox Psfcity15_Newspaper_InteractCherie_Event_Script_Text_0, MSGBOX_AUTOCLOSE
	goto Psfcity15_Newspaper_InteractCherie_Event_Script_1

Psfcity15_Newspaper_InteractCherie_Event_Script_6:
	call Manhunt_Cherie_Battle_Script
	goto Psfcity15_Newspaper_InteractCherie_Event_Script_1

Psfcity15_Newspaper_InteractCherie_Event_Script_9:
	return


Psfcity15_Newspaper_MapScripts_OnTransition::
	setflag FLAG_TEMP_2
	return


Psfcity15_Newspaper_InteractCherie_Event_Script_Text_0:
	.string "...$"