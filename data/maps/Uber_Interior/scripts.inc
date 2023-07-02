Uber_Interior_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Uber_Interior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Uber_Interior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Uber_Interior_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_TEMP_1, 0, Uber_Interior_PlayerFaceUp
	.2byte 0

Uber_Interior_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_1, 3, Quest_Persuasivepassenger_Driver1_Event_Script
	map_script_2 VAR_TEMP_1, 2, Quest_Persuasivepassenger_Driver2_Event_Script
	map_script_2 VAR_TEMP_1, 1, Quest_Persuasivepassenger_Driver3_Event_Script
	map_script_2 VAR_TEMP_1, 4, Quest_Persuasivepassenger_SetCutsceneVar_Script
	.2byte 0


Uber_Interior_PlayerFaceUp::
	setvar VAR_TEMP_1, 4
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

