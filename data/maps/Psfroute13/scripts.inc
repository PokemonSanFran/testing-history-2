Psfroute13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute13_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute13_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restaurantexpansion2_HideStaffA_Script
	return


Psfroute13_EventScript_RestaurantStaffA_Script::
	setvar VAR_MSGBOX_EMOTE, EMOTE_DEFAULT
	setvar VAR_MSGBOX_TAIL, TAIL_DEFAULT
	setvar VAR_MSGBOX_SPEAKER, SPEAKER_AUGUSTE
	setvar VAR_MSGBOX_PHONE, PHONE_OFF
	trainerbattle_single TRAINER_HOSTESS, gText_Restaurantexpansion2_PreBattleA, gText_Restaurantexpansion2_PostBattleA, Quest_Restaurantexpansion2_TrainerA_PostBattle_Script
	call Quest_Restaurantexpansion2_TrainerA_PostBattle_Script
	return


gText_Restaurantexpansion2_PreBattleA::
	.string "$"

gText_Restaurantexpansion2_PostBattleA::
	.string "$"
