Psfroute25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute25_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Psfroute25_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfroute25_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfroute25_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return

Psfroute25_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Psfroute25_MapScripts_OnLoad
	return

Psfroute25_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_DEWFORD_TOWN_STATE, 2, ThisIsntRandom_UndergroundDoor_Dialogue
	.2byte 0


Psfroute25_MapScripts_OnLoad::
	switch VAR_DEWFORD_TOWN_STATE
	case 1, Psfroute25_MapScripts_OnLoad_2
	case 2, Psfroute25_MapScripts_OnLoad_3
	call ThisIsntRandom_UnlockElectronicDoor_Script
	setflag FLAG_TEMP_1
	return

Psfroute25_MapScripts_OnLoad_2:
	setflag FLAG_TEMP_1
	return

Psfroute25_MapScripts_OnLoad_3:
	return

