Chinatown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Chinatown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_PETALBURG_WOODS_STATE
	case 1, Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case 2, Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	case 3, Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	call HowDisappointing_HideObject_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	call HowDisappointing_HideTeamRocket_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	call HowDisappointing_HidePolice_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	call HowDisappointing_HidePolice_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 41, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


gText_Chinatown_IMissTheOld::
	.string "I miss the old days. I get so nostalgic\n"
	.string "for my childhood...I loved growing up in\l"
	.string "these streets.$"