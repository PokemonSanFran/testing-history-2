Psfroute13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute13_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute13_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restaurantexpansion2_HideStaffA_Script
	return


Psfroute13_EventScript_Auguste_Script::
	trainerbattle_single TRAINER_HOSTESS, gText_Auguste_PreBattle, gText_Auguste_PostBattle, Quest_Restaurantexpansion2_TrainerA_PostBattle_Script
	call Quest_Restaurantexpansion2_TrainerA_PostBattle_Script
	return


gText_Auguste_PreBattle::
	.string "$"

gText_Auguste_PostBattle::
	.string "$"
