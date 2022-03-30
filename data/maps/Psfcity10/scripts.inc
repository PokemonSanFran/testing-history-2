Psfcity10_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity10_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity10_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity10_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity10_MapScripts_OnTransition
	return

Psfcity10_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE115_STATE, 1, IGuessWeShouldBeNiceNow_ExitCave_Script
	map_script_2 VAR_STORYLINE_STATE, 41, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Psfcity10_MapScripts_OnTransition::
	switch VAR_ROUTE115_STATE
	goto Psfcity10_HidePsftransrival_Script
	return


Psfcity10_HidePsftransrival_Script::
	setflag FLAG_TEMP_3
	removeobject 1
	return

