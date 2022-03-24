Psfcity17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity17_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Psfcity17_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity17_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity17_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity17_MapScripts_OnTransition
	return

Psfcity17_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto Psfcity17_MapScripts_OnLoad
	return

Psfcity17_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_NATIVERIVALBETA_STATE, 3, SurvivalChance333_ExplainOperation
	map_script_2 VAR_NATIVERIVALBETA_STATE, 5, WhyAreYouHelpingThem_MissionDebrief_Dialogue
	.2byte 0


Psfcity17_MapScripts_OnTransition::
	switch VAR_NATIVERIVALBETA_STATE
	case 0, Psfcity17_MapScripts_OnTransition_2
	case 1, Psfcity17_MapScripts_OnTransition_3
	case 2, Psfcity17_MapScripts_OnTransition_4
	case 3, Psfcity17_MapScripts_OnTransition_5
	case 4, Psfcity17_MapScripts_OnTransition_6
	case 5, Psfcity17_MapScripts_OnTransition_7
	return

Psfcity17_MapScripts_OnTransition_2:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_3:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_4:
	goto AssholesHome_HideObject_Script
	return

Psfcity17_MapScripts_OnTransition_5:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_6:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_7:
	goto WhyAreYouHelpingThem_ObjectDebriefSetUp_Script
	return


Psfcity17_MapScripts_OnLoad::
	compare VAR_NATIVERIVALBETA_STATE, 3
	goto_if_gt Psfcity17_MapScripts_OnLoad_1
	return

Psfcity17_MapScripts_OnLoad_1:
	call Psfplace2_PostRaidTiles_Script
	return


Psfplace2_PostRaidTiles_Script::
	call SurvivalChance333_FreezeIce
	call SurvivalChance333_SetLava
	call SurvivalChance333_BlowOpenDoors
	return


Psfcity17_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfcity17_UnlockedDestinations_Script
	return


Psfcity17_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Psfcity17_UnlockedDestinations_Script_2
	case 1, Psfcity17_UnlockedDestinations_Script_3
	return

Psfcity17_UnlockedDestinations_Script_2:
	goto Psfcity17_FerryState0_Script
	return

Psfcity17_UnlockedDestinations_Script_3:
	goto Psfcity17_FerryState1_Script
	return


Psfcity17_FerryState0_Script::
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER1, 2, FALSE
	switch VAR_RESULT
	case 0, Psfcity17_FerryState0_Script_3
	case 1, Psfcity17_FerryState0_Script_4
	case MULTI_B_PRESSED, Psfcity17_FerryState0_Script_5
Psfcity17_FerryState0_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Psfcity17_FerryState0_Script_3:
	warp MAP_PSFPLACE11, 8, 11
	goto Psfcity17_FerryState0_Script_1

Psfcity17_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState0_Script_1

Psfcity17_FerryState0_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState0_Script_1


Psfcity17_FerryState1_Script::
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER2, 2, FALSE
	switch VAR_RESULT
	case 0, Psfcity17_FerryState1_Script_3
	case 1, Psfcity17_FerryState1_Script_4
	case 2, Psfcity17_FerryState1_Script_5
	case MULTI_B_PRESSED, Psfcity17_FerryState1_Script_6
Psfcity17_FerryState1_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Psfcity17_FerryState1_Script_3:
	warp MAP_PSFPLACE11, 8, 11
	goto Psfcity17_FerryState1_Script_1

Psfcity17_FerryState1_Script_4:
	warp MAP_PSFCAVE7, 15, 22
	goto Psfcity17_FerryState1_Script_1

Psfcity17_FerryState1_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState1_Script_1

Psfcity17_FerryState1_Script_6:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState1_Script_1

