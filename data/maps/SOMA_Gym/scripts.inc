SOMA_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SOMA_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SOMA_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call EnterWhitney_LeaderPosition_Script
	call Quest_Alohafromalola_SetLeaderPosition_Battle_Script
	return

SOMA_Gym_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_WHITNEY_STATE, EXHIBITION_READY, Quest_Alohafromalola_StartBattle_Dialogue
	.2byte 0

