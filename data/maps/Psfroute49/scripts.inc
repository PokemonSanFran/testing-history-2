Psfroute49_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute49_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute49_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restaurantexpansion2_HideStaffC_Script
	return


Psfroute49_EventScript_Alice_Script::
	trainerbattle_single TRAINER_JAINTOR, gText_Alice_PreBattle, gText_Alice_PostBattle, Quest_Restaurantexpansion2_TrainerC_PostBattle_Script
	call Quest_Restaurantexpansion2_TrainerC_PostBattle_Script
	return


gText_Alice_PreBattle::
	.string "$"

gText_Alice_PostBattle::
	.string "$"
