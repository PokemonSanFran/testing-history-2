Psfcave3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcave3_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcave3_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcave3_MapScripts_OnTransition
	return


Psfcave3_MapScripts_OnTransition::
	compare VAR_STORYLINE_STATE, 26
	goto_if_gt Psfcave3_MapScripts_OnTransition_1
	return

Psfcave3_MapScripts_OnTransition_1:
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_ne Psfcave3_MapScripts_OnTransition_3
	goto_if_unset FLAG_TIMELINE_FALSE, Psfcave3_MapScripts_OnTransition_3
	return

Psfcave3_MapScripts_OnTransition_3:
	call Manhunt_HideObject_Script
	return


Psfcave3_InteractPsfelite4_Event_Script::
	lock
	switch VAR_RUSTURF_TUNNEL_STATE
	case 5, Psfcave3_InteractPsfelite4_Event_Script_3
	msgbox Psfcave3_InteractPsfelite4_Event_Script_Text_0, MSGBOX_AUTOCLOSE
Psfcave3_InteractPsfelite4_Event_Script_1:
	release
	end

Psfcave3_InteractPsfelite4_Event_Script_3:
	call Manhunt_Encounter_Psfgoodboss_Dialogue
	goto Psfcave3_InteractPsfelite4_Event_Script_1


Psfcave3_InteractPsfelite4_Event_Script_Text_0:
	.string "...$"
