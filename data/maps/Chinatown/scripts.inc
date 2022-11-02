Chinatown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Chinatown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Chinatown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call HowDisappointing_ManageObject_Script
	call Quest_CulturalPurity_HideLeader_Script
	call Quest_CulturalPurity_HideBackUp_Script
	call Quest_CulturalPurity_MoveGuard_Script
	call Quest_Restorechinatown_HidePewfatOutside_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Quest_Restorechinatown_LockGymDoor_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_RESTORATION_1_COMPLETE, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


gText_Chinatown_IMissTheOld::
	.string "I miss the old days. I get so nostalgic\n"
	.string "for my childhood...I loved growing up in\l"
	.string "these streets.$"
