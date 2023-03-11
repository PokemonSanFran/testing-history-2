Psfroute2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute2_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute2_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restaurantexpansion2_HideStaffE_Script
	return


Psfroute2_EventScript_Anthony_Script::
	trainerbattle_single TRAINER_CASHIER, gText_Anthony_PreBattle, gText_Anthony_PostBattle, Quest_Restaurantexpansion2_TrainerE_PostBattle_Script
	call Quest_Restaurantexpansion2_TrainerE_PostBattle_Script
	return


gText_Anthony_PreBattle::
	.string "$"

gText_Anthony_PostBattle::
	.string "$"
