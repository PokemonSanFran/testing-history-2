Ferrybuilding_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Ferrybuilding_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Ferrybuilding_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Ferrybuilding_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Ferrybuilding_MapScripts_OnTransition
	return

Ferrybuilding_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ROUTE117_STATE, 1, SurvivalChance333_MovePlayerIntoPosition
	map_script_2 VAR_ROUTE117_STATE, 2, SurvivalChance333_ExplainPlan_Dialogue
	.2byte 0


Ferrybuilding_MapScripts_OnTransition::
	switch VAR_ROUTE117_STATE
	case 1, Ferrybuilding_MapScripts_OnTransition_2
	goto SurvivalChance333_HideObject_Script
	return

Ferrybuilding_MapScripts_OnTransition_2:
	return


Ferrybuilding_InteractFerryAttendant_Script::
	lock
	compare VAR_STORYLINE_STATE, 10
	goto_if_lt Ferrybuilding_InteractFerryAttendant_Script_1
	goto Ferrybuilding_ChooseFerryDestination_Script
	return

Ferrybuilding_InteractFerryAttendant_Script_1:
	msgbox gText_Ferrybuilding_OutOfOrder, MSGBOX_NPC
	release
	end


Ferrybuilding_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Ferrybuilding_UnlockedDestinations_Script
	return


Ferrybuilding_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Ferrybuilding_UnlockedDestinations_Script_2
	case 1, Ferrybuilding_UnlockedDestinations_Script_3
	case 2, Ferrybuilding_UnlockedDestinations_Script_4
	return

Ferrybuilding_UnlockedDestinations_Script_2:
	goto Ferrybuilding_FerryState0_Script
	return

Ferrybuilding_UnlockedDestinations_Script_3:
	goto Ferrybuilding_FerryState0_Script
	return

Ferrybuilding_UnlockedDestinations_Script_4:
	goto Ferrybuilding_FerryState1_Script
	return


Ferrybuilding_FerryState0_Script::
	multichoicedefault 18, 8, FERRYBUILDING_FERRY_DESTINATIONS_VER1, 2, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Ferrybuilding_FerryState0_Script_2
	case 1, Ferrybuilding_FerryState0_Script_3
	case MULTI_B_PRESSED, Ferrybuilding_FerryState0_Script_4
	return

Ferrybuilding_FerryState0_Script_2:
	warp MAP_ALAMEDA, 3, 16
	return

Ferrybuilding_FerryState0_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Ferrybuilding_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


Ferrybuilding_FerryState1_Script::
	multichoicedefault 18, 8, FERRYBUILDING_FERRY_DESTINATIONS_VER2, 2, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Ferrybuilding_FerryState1_Script_2
	case 1, Ferrybuilding_FerryState1_Script_3
	case 2, Ferrybuilding_FerryState1_Script_4
	case MULTI_B_PRESSED, Ferrybuilding_FerryState1_Script_5
	return

Ferrybuilding_FerryState1_Script_2:
	warp MAP_ALAMEDA, 3, 16
	return

Ferrybuilding_FerryState1_Script_3:
	warp MAP_TREASUREISLAND, 15, 36
	return

Ferrybuilding_FerryState1_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Ferrybuilding_FerryState1_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_WhereWould::
	.string "Where would you like to go?$"

gText_Ferrybuilding_OutOfOrder::
	.string "Unfortunately, the ferry is currently\n"
	.string "out of order. Please come back later.$"
