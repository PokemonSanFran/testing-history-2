Psfplace16_MapScripts::
	.byte 0


Psfplace16_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfplace16_UnlockedDestinations_Script
	return


Psfplace16_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Psfplace16_UnlockedDestinations_Script_3
Psfplace16_UnlockedDestinations_Script_1:
	goto Psfplace16_SetDestination_Script
	return

Psfplace16_UnlockedDestinations_Script_3:
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER1, 2, FALSE
	goto Psfplace16_UnlockedDestinations_Script_1


Psfplace16_SetDestination_Script::
	call Common_EventScript_FerryDepartIsland
	switch VAR_RESULT
	case 0, Psfplace16_SetDestination_Script_2
	case 1, Psfplace16_SetDestination_Script_3
	case MULTI_B_PRESSED, Psfplace16_SetDestination_Script_4
	return

Psfplace16_SetDestination_Script_2:
	warp MAP_PSFPLACE11, 8, 11
	return

Psfplace16_SetDestination_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfplace16_SetDestination_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

