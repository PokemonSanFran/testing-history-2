Psfplace11_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfplace11_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfplace11_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfplace11_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfplace11_MapScripts_OnTransition
	return

Psfplace11_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE117_STATE, 1, SurvivalChance333_MovePlayerIntoPosition
	map_script_2 VAR_ROUTE117_STATE, 2, SurvivalChance333_ExplainPlan
	.2byte 0


Psfplace11_MapScripts_OnTransition::
	switch VAR_ROUTE117_STATE
	case 0, Psfplace11_MapScripts_OnTransition_2
	case 1, Psfplace11_MapScripts_OnTransition_3
	return

Psfplace11_MapScripts_OnTransition_2:
	goto SurvivalChance333_HideObject_Script
	return

Psfplace11_MapScripts_OnTransition_3:
	goto SurvivalChance333_ObjectSetUp_Script
	return


Psfplace11_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfplace11_UnlockedDestinations_Script
	return


Psfplace11_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Psfplace11_UnlockedDestinations_Script_2
	case 1, Psfplace11_UnlockedDestinations_Script_3
	case 9, Psfplace11_UnlockedDestinations_Script_4
	return

Psfplace11_UnlockedDestinations_Script_2:
	goto Psfplace11_FerryState0_Script
	return

Psfplace11_UnlockedDestinations_Script_3:
	goto Psfplace11_FerryState0_Script
	return

Psfplace11_UnlockedDestinations_Script_4:
	goto Psfplace11_FerryState1_Script
	return


Psfplace11_FerryState0_Script::
	multichoicedefault 18, 8, PSFPLACE11_FERRY_DESTINATIONS_VER1, 2, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Psfplace11_FerryState0_Script_2
	case 1, Psfplace11_FerryState0_Script_3
	case MULTI_B_PRESSED, Psfplace11_FerryState0_Script_4
	return

Psfplace11_FerryState0_Script_2:
	warp MAP_PSFCITY17, 3, 16
	return

Psfplace11_FerryState0_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfplace11_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


Psfplace11_FerryState1_Script::
	multichoicedefault 18, 8, PSFPLACE11_FERRY_DESTINATIONS_VER2, 2, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Psfplace11_FerryState1_Script_2
	case 1, Psfplace11_FerryState1_Script_3
	case 2, Psfplace11_FerryState1_Script_4
	case MULTI_B_PRESSED, Psfplace11_FerryState1_Script_5
	return

Psfplace11_FerryState1_Script_2:
	warp MAP_PSFCITY17, 3, 16
	return

Psfplace11_FerryState1_Script_3:
	warp MAP_PSFCITY17, 3, 16
	return

Psfplace11_FerryState1_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfplace11_FerryState1_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_WhereWould::
	.string "Where would you like to go?$"
