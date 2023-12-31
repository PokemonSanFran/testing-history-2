Alcatraz_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call YouRealizeTheyreEvilRight_HideGarbodor_Script
	call Alcatraz_B2F_ObjectVisibility_Script
	call Quest_Redomugging_Hide_Muggers_Script
	return

Alcatraz_B2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALCATRAZ_STATE, PRE_YOU_REALIZE_THEYRE_EVIL_RIGHT, YouRealizeTheyreEvilRight_PlayerArrived2F_Dialogue
	map_script_2 VAR_ALCATRAZ_STATE, PRE_SPEECHSPEECH, SpeechSpeechSpeech_PositionPlayer_Script
	map_script_2 VAR_STORYLINE_STATE, STORY_1ST_TAKEDOWN, OneDown_SetUpObject_Script
	.2byte 0


Alcatraz_B2F_ObjectVisibility_Script::
	switch VAR_ALCATRAZ_STATE
	case 0, Alcatraz_B2F_ObjectVisibility_Script_2
	case FIRST_ARRIVED_ALCATRAZ, Alcatraz_B2F_ObjectVisibility_Script_3
	case BATTLED_MALVA, Alcatraz_B2F_ObjectVisibility_Script_4
	case PRE_YOU_REALIZE_THEYRE_EVIL_RIGHT, Alcatraz_B2F_ObjectVisibility_Script_5
	case POST_YOU_REALIZE_THEYRE_EVIL_RIGHT, Alcatraz_B2F_ObjectVisibility_Script_6
	case LAST_CHANCE_TRUE_TIMELINE_START, Alcatraz_B2F_ObjectVisibility_Script_7
	case START_TRUE_TIMELINE, Alcatraz_B2F_ObjectVisibility_Script_8
	case PRE_SPEECHSPEECH, Alcatraz_B2F_ObjectVisibility_Script_9
	case POST_SPEECHSPEECH, Alcatraz_B2F_ObjectVisibility_Script_10
	return

Alcatraz_B2F_ObjectVisibility_Script_2:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_3:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_4:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_5:
	call YouRealizeTheyreEvilRight_Basement_SetUpObjects_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_6:
	call LetsGettheBandBackTogether_HideObject_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_7:
	call LetsGettheBandBackTogether_HideObject_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_8:
	call YouRealizeTheyreEvilRight_HideBasement_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_9:
	call SpeechSpeechSpeech_MoveObject_Script
	return

Alcatraz_B2F_ObjectVisibility_Script_10:
	call SpeechSpeechSpeech_ProjectAssignment_ObjectSetUp_Script
	return


Alcatraz_B2F_Archer_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_MORNING_OF_TIMELINE_SPLIT, Alcatraz_B2F_Archer_Event_Script_3
Alcatraz_B2F_Archer_Event_Script_1:
	release
	end

Alcatraz_B2F_Archer_Event_Script_3:
	call LetsGettheBandBackTogether_MeetInBasement_Script
	goto Alcatraz_B2F_Archer_Event_Script_1


Alcatraz_B2F_Malva_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_RAVE_OR_SPEECH_COMPLETE, Alcatraz_B2F_Malva_Event_Script_3
	case STORY_RAVE_AND_SPEECH_COMPLETE, Alcatraz_B2F_Malva_Event_Script_4
Alcatraz_B2F_Malva_Event_Script_1:
	closemessage
	release
	end

Alcatraz_B2F_Malva_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC, SPEAKER_MALVA
	goto Alcatraz_B2F_Malva_Event_Script_1

Alcatraz_B2F_Malva_Event_Script_4:
	goto Quest_Breaktheinternet_EliteFour_Dialogue
	goto Alcatraz_B2F_Malva_Event_Script_1


Alcatraz_B2F_Drasna_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_RAVE_OR_SPEECH_COMPLETE, Alcatraz_B2F_Drasna_Event_Script_3
	case STORY_RAVE_AND_SPEECH_COMPLETE, Alcatraz_B2F_Drasna_Event_Script_4
Alcatraz_B2F_Drasna_Event_Script_1:
	closemessage
	release
	end

Alcatraz_B2F_Drasna_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC, SPEAKER_DRASNA
	goto Alcatraz_B2F_Drasna_Event_Script_1

Alcatraz_B2F_Drasna_Event_Script_4:
	msgbox Alcatraz_B2F_Drasna_Event_Script_Text_0, MSGBOX_NPC, SPEAKER_DRASNA
	goto Alcatraz_B2F_Drasna_Event_Script_1


Alcatraz_B2F_Siebold_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_RAVE_OR_SPEECH_COMPLETE, Alcatraz_B2F_Siebold_Event_Script_3
	case STORY_RAVE_AND_SPEECH_COMPLETE, Alcatraz_B2F_Siebold_Event_Script_4
Alcatraz_B2F_Siebold_Event_Script_1:
	closemessage
	release
	end

Alcatraz_B2F_Siebold_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC, SPEAKER_SIEBOLD
	goto Alcatraz_B2F_Siebold_Event_Script_1

Alcatraz_B2F_Siebold_Event_Script_4:
	goto Quest_Taxicabturnaround_EliteFour_Dialogue
	goto Alcatraz_B2F_Siebold_Event_Script_1


Alcatraz_B2F_Wikstrom_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_RAVE_OR_SPEECH_COMPLETE, Alcatraz_B2F_Wikstrom_Event_Script_3
	case STORY_RAVE_AND_SPEECH_COMPLETE, Alcatraz_B2F_Wikstrom_Event_Script_4
Alcatraz_B2F_Wikstrom_Event_Script_1:
	closemessage
	release
	end

Alcatraz_B2F_Wikstrom_Event_Script_3:
	msgbox gText_SpeechSpeechSpeech_GoWarehouseRave, MSGBOX_NPC, SPEAKER_WIKSTROM
	goto Alcatraz_B2F_Wikstrom_Event_Script_1

Alcatraz_B2F_Wikstrom_Event_Script_4:
	goto Quest_Bodegaburnout_EliteFour_Dialogue
	goto Alcatraz_B2F_Wikstrom_Event_Script_1


Alcatraz_B2F_Drasna_Event_Script_Text_0:
	.string "I don't have a takedown quest for you.$"
