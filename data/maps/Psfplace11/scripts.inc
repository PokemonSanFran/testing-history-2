Psfplace11_MapScripts::
	.byte 0


Psfplace11_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfplace11_UnlockedDestinations_Script
	return


Psfplace11_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Psfplace11_UnlockedDestinations_Script_3
Psfplace11_UnlockedDestinations_Script_1:
	goto Psfplace11_SetDestination_Script
	return

Psfplace11_UnlockedDestinations_Script_3:
	multichoicedefault 18, 8, PSFPLACE11_FERRY_DESTINATIONS_VER1, 2, FALSE
	goto Psfplace11_UnlockedDestinations_Script_1


Psfplace11_SetDestination_Script::
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Psfplace11_SetDestination_Script_2
	case 1, Psfplace11_SetDestination_Script_3
	case MULTI_B_PRESSED, Psfplace11_SetDestination_Script_4
	return

Psfplace11_SetDestination_Script_2:
	warp MAP_PSFCITY17, 3, 16
	return

Psfplace11_SetDestination_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfplace11_SetDestination_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_WhereWould::
	.string "Where would you like to go?$"
