Psfroute17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute17_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Psfroute17_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Psfroute17_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restorechinatown_HideBlackbelt_Psfroute17_Script
	call Quest_Ultrawormholeresearch_ControlTotemVisibility
	return

Psfroute17_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_Ultrawormholeresearch_TryRemoveTotem_Script
	return


Psfroute17_EventScript_BlackbeltE::
	trainerbattle_single TRAINER_BLACKBELT_E, gText_ExpandedPlaceholder_Empty, gText_ExpandedPlaceholder_Empty
	compare VAR_QUEST_RESTORECHINATOWN, FIND_BLACKBELTS
	goto_if_eq Psfroute17_EventScript_BlackbeltE_2
Psfroute17_EventScript_BlackbeltE_1:
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_AUTOCLOSE
	end

Psfroute17_EventScript_BlackbeltE_2:
	goto Quest_Restorechinatown_Recruit_Blackbelt_E_Dialogue
	goto Psfroute17_EventScript_BlackbeltE_1


Psfroute17_EventScript_DeliveryA::
	trainerbattle_single TRAINER_BODEGA_1, gText_ExpandedPlaceholder_Empty, gText_ExpandedPlaceholder_Empty
	returnqueststate QUEST_BODEGABURNOUT
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Psfroute17_EventScript_DeliveryA_2
Psfroute17_EventScript_DeliveryA_1:
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_AUTOCLOSE
	end

Psfroute17_EventScript_DeliveryA_2:
	goto Quest_Bodegaburnout_DeliveryA_Dialogue
	goto Psfroute17_EventScript_DeliveryA_1

