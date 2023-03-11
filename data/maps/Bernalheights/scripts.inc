Bernalheights_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Bernalheights_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Bernalheights_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restaurantexpansion2_HideStaffB_Script
	return


Bernalheights_EventScript_Julia_Script::
	trainerbattle_single TRAINER_CHEF, gText_Julia_PreBattle, gText_Julia_PostBattle, Quest_Restaurantexpansion2_TrainerB_PostBattle_Script
	call Quest_Restaurantexpansion2_TrainerB_PostBattle_Script
	return


gText_Julia_PreBattle::
	.string "$"

gText_Julia_PostBattle::
	.string "$"
