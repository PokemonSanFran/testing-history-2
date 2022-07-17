Alcatraz_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Alcatraz_B2F_MapScripts_OnTransition
	return

Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PSFCAVE7_STATE, 4, YouRealizeTheyreEvilRight_PlayerArrived2F_Dialogue
	map_script_2 VAR_PSFCAVE7_STATE, 8, SpeechSpeechSpeech_PositionPlayer_Script
	map_script_2 VAR_STORYLINE_STATE, 105, OneDown_SetUpObject_Script
	.2byte 0


Alcatraz_B2F_MapScripts_OnTransition::
	call YouRealizeTheyreEvilRight_HideGarbodor_Script
	switch VAR_PSFCAVE7_STATE
	case 0, Alcatraz_B2F_MapScripts_OnTransition_2
	case 1, Alcatraz_B2F_MapScripts_OnTransition_3
	case 2, Alcatraz_B2F_MapScripts_OnTransition_4
	case 3, Alcatraz_B2F_MapScripts_OnTransition_5
	case 5, Alcatraz_B2F_MapScripts_OnTransition_6
	case 6, Alcatraz_B2F_MapScripts_OnTransition_7
	case 7, Alcatraz_B2F_MapScripts_OnTransition_8
	case 8, Alcatraz_B2F_MapScripts_OnTransition_9
	case 9, Alcatraz_B2F_MapScripts_OnTransition_10
	return

Alcatraz_B2F_MapScripts_OnTransition_2:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_3:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_4:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_5:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_6:
	call LetsGettheBandBackTogether_HideObject_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_7:
	call LetsGettheBandBackTogether_HideObject_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_8:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_9:
	call SpeechSpeechSpeech_MoveObject_Script
	return

Alcatraz_B2F_MapScripts_OnTransition_10:
	call SpeechSpeechSpeech_ProjectAssignment_ObjectSetUp_Script
	return


Alcatraz_B2F_Archer_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case 43, Alcatraz_B2F_Archer_Event_Script_3
Alcatraz_B2F_Archer_Event_Script_1:
	release
	end

Alcatraz_B2F_Archer_Event_Script_3:
	call LetsGettheBandBackTogether_MeetInBasement_Script
	goto Alcatraz_B2F_Archer_Event_Script_1


Alcatraz_B2F_Malva_Event_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	switch VAR_STORYLINE_STATE
	case 103, Alcatraz_B2F_Malva_Event_Script_3
	case 104, Alcatraz_B2F_Malva_Event_Script_4
Alcatraz_B2F_Malva_Event_Script_1:
	closemessage
	callnative ClearMugshot
	release
	end

Alcatraz_B2F_Malva_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC
	goto Alcatraz_B2F_Malva_Event_Script_1

Alcatraz_B2F_Malva_Event_Script_4:
	msgbox Alcatraz_B2F_Malva_Event_Script_Text_0, MSGBOX_NPC
	addvar VAR_STORYLINE_STATE, 1
	goto Alcatraz_B2F_Malva_Event_Script_1


Alcatraz_B2F_Drasna_Event_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	switch VAR_STORYLINE_STATE
	case 103, Alcatraz_B2F_Drasna_Event_Script_3
	case 104, Alcatraz_B2F_Drasna_Event_Script_4
Alcatraz_B2F_Drasna_Event_Script_1:
	closemessage
	callnative ClearMugshot
	release
	end

Alcatraz_B2F_Drasna_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC
	goto Alcatraz_B2F_Drasna_Event_Script_1

Alcatraz_B2F_Drasna_Event_Script_4:
	msgbox Alcatraz_B2F_Drasna_Event_Script_Text_0, MSGBOX_NPC
	goto Alcatraz_B2F_Drasna_Event_Script_1


Alcatraz_B2F_Siebold_Event_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	switch VAR_STORYLINE_STATE
	case 103, Alcatraz_B2F_Siebold_Event_Script_3
	case 104, Alcatraz_B2F_Siebold_Event_Script_4
Alcatraz_B2F_Siebold_Event_Script_1:
	closemessage
	callnative ClearMugshot
	release
	end

Alcatraz_B2F_Siebold_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC
	goto Alcatraz_B2F_Siebold_Event_Script_1

Alcatraz_B2F_Siebold_Event_Script_4:
	msgbox Alcatraz_B2F_Siebold_Event_Script_Text_0, MSGBOX_NPC
	addvar VAR_STORYLINE_STATE, 1
	goto Alcatraz_B2F_Siebold_Event_Script_1


Alcatraz_B2F_Wikstrom_Event_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	switch VAR_STORYLINE_STATE
	case 103, Alcatraz_B2F_Wikstrom_Event_Script_3
	case 104, Alcatraz_B2F_Wikstrom_Event_Script_4
Alcatraz_B2F_Wikstrom_Event_Script_1:
	closemessage
	callnative ClearMugshot
	release
	end

Alcatraz_B2F_Wikstrom_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC
	goto Alcatraz_B2F_Wikstrom_Event_Script_1

Alcatraz_B2F_Wikstrom_Event_Script_4:
	msgbox Alcatraz_B2F_Siebold_Event_Script_Text_0, MSGBOX_NPC
	addvar VAR_STORYLINE_STATE, 1
	goto Alcatraz_B2F_Wikstrom_Event_Script_1


Alcatraz_B2F_Malva_Event_Script_Text_0:
	.string "you've started and finished a takedown\n"
	.string "quest.$"

Alcatraz_B2F_Drasna_Event_Script_Text_0:
	.string "I don't have a takedown quest for you.$"

Alcatraz_B2F_Siebold_Event_Script_Text_0:
	.string "you've started and finished a takedown quest.$"
