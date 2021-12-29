Psfplace11_MapScripts::
	.byte 0


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
