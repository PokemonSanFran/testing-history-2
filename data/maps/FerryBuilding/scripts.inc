FerryBuilding_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FerryBuilding_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FerryBuilding_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FerryBuilding_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto FerryBuilding_MapScripts_OnTransition
	return

FerryBuilding_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE117_STATE, 1, SurvivalChance333_MovePlayerIntoPosition
	map_script_2 VAR_ROUTE117_STATE, 2, SurvivalChance333_ExplainPlan_Dialogue
	.2byte 0


FerryBuilding_MapScripts_OnTransition::
	switch VAR_ROUTE117_STATE
	case 1, FerryBuilding_MapScripts_OnTransition_2
	goto SurvivalChance333_HideObject_Script
	return

FerryBuilding_MapScripts_OnTransition_2:
	return


FerryBuilding_InteractFerryAttendant_Script::
	lock
	compare VAR_STORYLINE_STATE, 10
	goto_if_lt FerryBuilding_InteractFerryAttendant_Script_1
	goto FerryBuilding_ChooseFerryDestination_Script
	return

FerryBuilding_InteractFerryAttendant_Script_1:
	msgbox gText_FerryBuilding_OutOfOrder, MSGBOX_NPC
	release
	end


FerryBuilding_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto FerryBuilding_UnlockedDestinations_Script
	return


FerryBuilding_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, FerryBuilding_UnlockedDestinations_Script_2
	case 1, FerryBuilding_UnlockedDestinations_Script_3
	case 2, FerryBuilding_UnlockedDestinations_Script_4
	return

FerryBuilding_UnlockedDestinations_Script_2:
	goto FerryBuilding_FerryState0_Script
	return

FerryBuilding_UnlockedDestinations_Script_3:
	goto FerryBuilding_FerryState0_Script
	return

FerryBuilding_UnlockedDestinations_Script_4:
	goto FerryBuilding_FerryState1_Script
	return


FerryBuilding_FerryState0_Script::
	multichoicedefault 18, 8, PSFPLACE11_FERRY_DESTINATIONS_VER1, 2, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, FerryBuilding_FerryState0_Script_2
	case 1, FerryBuilding_FerryState0_Script_3
	case MULTI_B_PRESSED, FerryBuilding_FerryState0_Script_4
	return

FerryBuilding_FerryState0_Script_2:
	warp MAP_PSFCITY17, 3, 16
	return

FerryBuilding_FerryState0_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

FerryBuilding_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


FerryBuilding_FerryState1_Script::
	multichoicedefault 18, 8, PSFPLACE11_FERRY_DESTINATIONS_VER2, 2, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, FerryBuilding_FerryState1_Script_2
	case 1, FerryBuilding_FerryState1_Script_3
	case 2, FerryBuilding_FerryState1_Script_4
	case MULTI_B_PRESSED, FerryBuilding_FerryState1_Script_5
	return

FerryBuilding_FerryState1_Script_2:
	warp MAP_PSFCITY17, 3, 16
	return

FerryBuilding_FerryState1_Script_3:
	warp MAP_PSFCAVE5, 15, 36
	return

FerryBuilding_FerryState1_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

FerryBuilding_FerryState1_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_WhereWould::
	.string "Where would you like to go?$"

gText_FerryBuilding_OutOfOrder::
	.string "Unfortunately, the ferry is currently\n"
	.string "out of order. Please come back later.$"
