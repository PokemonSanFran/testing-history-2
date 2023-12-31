Psfroute63_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute63_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Psfroute63_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Psfroute63_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Psfroute63_MapScripts_OnTransition
	call Quest_Restaurantexpansion2_HideStaffD_Script
	return

Psfroute63_MapScripts_MAP_SCRIPT_ON_RESUME:
	goto Psfroute63_MapScripts_OnResume
	return


Psfroute63_MapScripts_OnResume::
	checktrainerflag TRAINER_HOUSINGPROTEST_ROCKET
	goto_if 1, Psfroute63_MapScripts_OnResume_1
	return

Psfroute63_MapScripts_OnResume_1:
	goto HousingProtest_CleanUp_Script
	return


Psfroute63_MapScripts_OnTransition::
	switch VAR_PSFROUTE63_STATE
	case PROTEST_NOTSTARTED, Psfroute63_MapScripts_OnTransition_2
	case SAVE_TEAMROCKET_PSFROUTE63, Psfroute63_MapScripts_OnTransition_3
	case DEFEATED_TEAMROCKET_PSFROUTE63, Psfroute63_MapScripts_OnTransition_4
	return

Psfroute63_MapScripts_OnTransition_2:
	goto HousingProtest_ObjectSetUp_Script
	return

Psfroute63_MapScripts_OnTransition_3:
	goto HousingProtest_PostSave_ObjectSetUp_Script
	return

Psfroute63_MapScripts_OnTransition_4:
	goto HousingProtest_CleanUp_Landlord_Script
	return


Psfroute63_EventScript_Ferran_Script::
	trainerbattle_single TRAINER_BUSSER, gText_Ferran_PreBattle, gText_Ferran_PostBattle, Quest_Restaurantexpansion2_TrainerD_PostBattle_Script
	call Quest_Restaurantexpansion2_TrainerE_PostBattle_Script
	return


gText_Ferran_PreBattle::
	.string "$"

gText_Ferran_PostBattle::
	.string "$"
