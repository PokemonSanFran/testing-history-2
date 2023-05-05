Gldngtepark_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Gldngtepark_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gldngtepark_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Gldngtepark_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Biomeresearch_HideLeader_Script
	return

Gldngtepark_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 21, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


gText_Gldgtepark_PlaceholderOaklandFan::
	.string "I wish i could wear my signed Champion's\n"
	.string "cape, but I know i'll just get it dirty$"
