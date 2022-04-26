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
	map_script_2 VAR_NATIVERIVALBETA_STATE, 8, Earthquake_ShowDestroyedCity_Script
	map_script_2 VAR_NATIVERIVALBETA_STATE, 11, Earthquake_PostRescue_Dialogue
	map_script_2 VAR_STORYLINE_STATE, 108, LetsFinishThis_MovePlayer_Script
	.2byte 0


Psfcity17_MapScripts_OnTransition::
	call Psfcity17_LayoutSwap_Script
	switch VAR_NATIVERIVALBETA_STATE
	case 0, Psfcity17_MapScripts_OnTransition_2
	case 1, Psfcity17_MapScripts_OnTransition_3
	case 3, Psfcity17_MapScripts_OnTransition_4
	case 5, Psfcity17_MapScripts_OnTransition_5
	case 8, Psfcity17_MapScripts_OnTransition_6
	case 9, Psfcity17_MapScripts_OnTransition_7
	case 13, Psfcity17_MapScripts_OnTransition_8
	call AssholesHome_HideObject_Script
	call SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_2:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_3:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return

Psfcity17_MapScripts_OnTransition_4:
	call AssholesHome_HideObject_Script
	return

Psfcity17_MapScripts_OnTransition_5:
	goto WhyAreYouHelpingThem_ObjectDebriefSetUp_Script
	return

Psfcity17_MapScripts_OnTransition_6:
	call Earthquake_HideObject_Script
	return

Psfcity17_MapScripts_OnTransition_7:
	call Earthquake_HideObject_Script
	return

Psfcity17_MapScripts_OnTransition_8:
	call LetsFinishThis_ObjectSetUp_Script
	return


Psfcity17_LayoutSwap_Script::
	compare VAR_NATIVERIVALBETA_STATE, 7
	goto_if_gt Psfcity17_LayoutSwap_Script_1
	return

Psfcity17_LayoutSwap_Script_1:
	setmaplayoutindex LAYOUT_PSFCITY17_POST_EARTHQUAKE
	return


Psfcity17_MapScripts_OnLoad::
	compare VAR_NATIVERIVALBETA_STATE, 3
	goto_if_gt Psfcity17_MapScripts_OnLoad_2
	return

Psfcity17_MapScripts_OnLoad_1:
	call Psfplace2_PostRaidTiles_Script
	return

Psfcity17_MapScripts_OnLoad_2:
	compare VAR_NATIVERIVALBETA_STATE, 7
	goto_if_lt Psfcity17_MapScripts_OnLoad_1
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
	case 2, Psfcity17_UnlockedDestinations_Script_4
	return

Psfcity17_UnlockedDestinations_Script_2:
	goto Psfcity17_FerryState0_Script
	return

Psfcity17_UnlockedDestinations_Script_3:
	goto Psfcity17_FerryState1_Script
	return

Psfcity17_UnlockedDestinations_Script_4:
	goto Psfcity17_FerryState2_Script
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


Psfcity17_FerryState2_Script::
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER3, 2, FALSE
	switch VAR_RESULT
	case 0, Psfcity17_FerryState2_Script_3
	case 1, Psfcity17_FerryState2_Script_4
	case 2, Psfcity17_FerryState2_Script_5
	case 3, Psfcity17_FerryState2_Script_6
	case MULTI_B_PRESSED, Psfcity17_FerryState2_Script_7
Psfcity17_FerryState2_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Psfcity17_FerryState2_Script_3:
	warp MAP_PSFPLACE11, 8, 11
	goto Psfcity17_FerryState2_Script_1

Psfcity17_FerryState2_Script_4:
	warp MAP_PSFCAVE7, 15, 22
	goto Psfcity17_FerryState2_Script_1

Psfcity17_FerryState2_Script_5:
	warp MAP_PSFCAVE5, 15, 36
	goto Psfcity17_FerryState2_Script_1

Psfcity17_FerryState2_Script_6:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState2_Script_1

Psfcity17_FerryState2_Script_7:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState2_Script_1


Psfcity17_Person1_Fisherman::
	compare VAR_NATIVERIVALBETA_STATE, 9
	goto_if_eq Psfcity17_Person1_Fisherman_2
Psfcity17_Person1_Fisherman_1:
	end

Psfcity17_Person1_Fisherman_2:
	msgbox Psfcity17_Person1_Fisherman_Text_0, MSGBOX_NPC
	addvar VAR_NATIVERIVALBETA_STATE, 2
	goto Psfcity17_Person1_Fisherman_1


Psfcity17_Person1_Fisherman_Text_0:
	.string "thanks for saving me!$"
