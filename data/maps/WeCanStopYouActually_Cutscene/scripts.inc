WeCanStopYouActually_Cutscene_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, WeCanStopYouActually_Cutscene_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, WeCanStopYouActually_Cutscene_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

WeCanStopYouActually_Cutscene_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call WeCanStopYouActually_Cutscene_MapScripts_OnTransition
	return

WeCanStopYouActually_Cutscene_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 111, WeCanStopYouActaully_ArrestCutscene
	.2byte 0


WeCanStopYouActually_Cutscene_MapScripts_OnTransition::
	setflag FLAG_TEMP_1
	return
