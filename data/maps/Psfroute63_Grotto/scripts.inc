Psfroute63_Grotto_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute63_Grotto_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfroute63_Grotto_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfroute63_Grotto_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Hiddengrottomapping_PannenVisibility_Script
	call Quest_Hiddengrottomapping2_RemoveJournalPage3_Script
	return

Psfroute63_Grotto_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, Quest_Hiddengrottomapping_MarkSubquestBiome_Script
	map_script_2 VAR_TEMP_0, 1, Quest_Hiddengrottomapping_StartQuest_Dialogue
	.2byte 0

