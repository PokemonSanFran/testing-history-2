Marin_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Marin_MapScripts_OnTransition
	return

Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE115_STATE, 1, IGuessWeShouldBeNiceNow_ExitCave_Script
	map_script_2 VAR_STORYLINE_STATE, 41, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Marin_MapScripts_OnTransition::
	switch VAR_ROUTE115_STATE
	goto Marin_HideBianca_Script
	return


Marin_HideBianca_Script::
	setflag FLAG_TEMP_3
	removeobject 1
	return

