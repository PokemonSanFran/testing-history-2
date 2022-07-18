Oaklandferry_MapScripts::
	.byte 0


Oaklandferry_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Oaklandferry_UnlockedDestinations_Script
	return


Oaklandferry_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Oaklandferry_UnlockedDestinations_Script_3
Oaklandferry_UnlockedDestinations_Script_1:
	goto Oaklandferry_SetDestination_Script
	return

Oaklandferry_UnlockedDestinations_Script_3:
	multichoicedefault 18, 8, ALAMEDA_FERRY_DESTINATIONS_VER1, 2, FALSE
	goto Oaklandferry_UnlockedDestinations_Script_1


Oaklandferry_SetDestination_Script::
	call Common_EventScript_FerryDepartIsland
	switch VAR_RESULT
	case 0, Oaklandferry_SetDestination_Script_2
	case 1, Oaklandferry_SetDestination_Script_3
	case MULTI_B_PRESSED, Oaklandferry_SetDestination_Script_4
	return

Oaklandferry_SetDestination_Script_2:
	warp MAP_FERRYBUILDING, 8, 11
	return

Oaklandferry_SetDestination_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Oaklandferry_SetDestination_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

