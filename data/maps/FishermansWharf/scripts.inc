FishermansWharf_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FishermansWharf_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

FishermansWharf_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	.2byte 0


FishermansWharf_InteractFerryAttendant_Script::
	lock
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq FishermansWharf_InteractFerryAttendant_Script_1
	goto FishermansWharf_ChooseFerryDestination_Script
	return

FishermansWharf_InteractFerryAttendant_Script_1:
	msgbox gText_PreventPlayerFerry_ImSorryYou, MSGBOX_NPC
	release
	end


FishermansWharf_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto FishermansWharf_UnlockedDestinations_Script
	return


FishermansWharf_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	goto FishermansWharf_FerryState0_Script
	return


FishermansWharf_FerryState0_Script::
	multichoicedefault 18, 8, FISHERMANSWHARF_FERRY_DESTINATIONS_VER1, 0, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, FishermansWharf_FerryState0_Script_2
	case 1, FishermansWharf_FerryState0_Script_3
	case MULTI_B_PRESSED, FishermansWharf_FerryState0_Script_4
	return

FishermansWharf_FerryState0_Script_2:
	warp MAP_ALCATRAZ, 15, 22
	return

FishermansWharf_FerryState0_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

FishermansWharf_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_PreventPlayerFerry_ImSorryYou::
	.string "I'm sorry, you don't appear to have the\n"
	.string "correct ticket to board the Ferry to\l"
	.string "Alcatraz.$"
