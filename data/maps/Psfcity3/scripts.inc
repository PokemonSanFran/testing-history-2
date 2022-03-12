Psfcity3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Psfcity3_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity3_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare FLAG_SYS_GAME_CLEAR, 0
	goto_if_ne Psfcity3_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Psfcity3_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 3, 9, 0x22F, FALSE
	return

Psfcity3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 17, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0

