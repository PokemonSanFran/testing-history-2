Fishermanswharf_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Fishermanswharf_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Fishermanswharf_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	.2byte 0


Fishermanswharf_InteractFerryAttendant_Script::
	lock
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq Fishermanswharf_InteractFerryAttendant_Script_1
	goto Fishermanswharf_ChooseFerryDestination_Script
	return

Fishermanswharf_InteractFerryAttendant_Script_1:
	msgbox gText_PreventPlayerFerry_ImSorryYou, MSGBOX_NPC
	release
	end


Fishermanswharf_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Fishermanswharf_UnlockedDestinations_Script
	return


Fishermanswharf_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	goto Fishermanswharf_FerryState0_Script
	return


Fishermanswharf_FerryState0_Script::
	multichoicedefault 18, 8, FISHERMANSWHARF_FERRY_DESTINATIONS_VER1, 0, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Fishermanswharf_FerryState0_Script_2
	case 1, Fishermanswharf_FerryState0_Script_3
	case MULTI_B_PRESSED, Fishermanswharf_FerryState0_Script_4
	return

Fishermanswharf_FerryState0_Script_2:
	warp MAP_ALCATRAZ, 48, 61
	return

Fishermanswharf_FerryState0_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Fishermanswharf_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_PreventPlayerFerry_ImSorryYou::
	.string "I'm sorry, you don't appear to have the\n"
	.string "correct ticket to board the Ferry to\l"
	.string "Alcatraz.$"
