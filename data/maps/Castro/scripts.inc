Castro_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Castro_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Castro_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Castro_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_CASTRO
	call Quest_BlueRobbery_HideObject_Script
	return

Castro_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 21, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


gText_Castro_PlaceholderOaklandFan::
	.string "did you know that Toxic Spikes lose\n"
	.string "their potency after a few hours? safe\l"
	.string "to touch and everything$"
