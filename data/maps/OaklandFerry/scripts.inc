OaklandFerry_MapScripts::
	.byte 0


OaklandFerry_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto OaklandFerry_UnlockedDestinations_Script
	return


OaklandFerry_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, OaklandFerry_UnlockedDestinations_Script_3
OaklandFerry_UnlockedDestinations_Script_1:
	goto OaklandFerry_SetDestination_Script
	return

OaklandFerry_UnlockedDestinations_Script_3:
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER1, 2, FALSE
	goto OaklandFerry_UnlockedDestinations_Script_1


OaklandFerry_SetDestination_Script::
	call Common_EventScript_FerryDepartIsland
	switch VAR_RESULT
	case 0, OaklandFerry_SetDestination_Script_2
	case 1, OaklandFerry_SetDestination_Script_3
	case MULTI_B_PRESSED, OaklandFerry_SetDestination_Script_4
	return

OaklandFerry_SetDestination_Script_2:
	warp MAP_PSFPLACE11, 8, 11
	return

OaklandFerry_SetDestination_Script_3:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

OaklandFerry_SetDestination_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

