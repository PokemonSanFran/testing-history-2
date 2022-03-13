Psfcave5_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcave5_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcave5_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcave5_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcave5_MapScripts_OnTransition
	return

Psfcave5_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 34, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Psfcave5_MapScripts_OnTransition::
	call LetsGrabLunch_HideObject_SetUp
	call LetsGrabLunch_ShowObject_SetUp
	return


Psfcave5_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfcave5_UnlockedDestinations_Script
	return


Psfcave5_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 2, Psfcave5_UnlockedDestinations_Script_2
	return

Psfcave5_UnlockedDestinations_Script_2:
	goto Psfcave5_FerryState0_Script
	return


Psfcave5_FerryState0_Script::
	multichoicedefault 18, 8, PSFCAVE5_FERRY_DESTINATIONS_VER1, 2, TRUE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Psfcave5_FerryState0_Script_2
	case 1, Psfcave5_FerryState0_Script_3
	case MULTI_B_PRESSED, Psfcave5_FerryState0_Script_4
	return

Psfcave5_FerryState0_Script_2:
	warp MAP_PSFPLACE11, 8, 11
	return

Psfcave5_FerryState0_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfcave5_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

