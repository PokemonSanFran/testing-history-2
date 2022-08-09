Gldngtewilds_Spring_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Gldngtewilds_Spring_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Gldngtewilds_Spring_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_FreshwaterEvolution_HideObject_Script
	return


Gldngtewilds_Spring_Bystander_Event_Script::
	returnqueststate QUEST_FRESHWATEREVOLUTION
	switch VAR_RESULT
	case 4, Gldngtewilds_Spring_Bystander_Event_Script_2
	msgbox gText_Gldngtewilds_Spring_ThisPlace, MSGBOX_NPC
	end

Gldngtewilds_Spring_Bystander_Event_Script_2:
	msgbox gText_Quest_FreshwaterEvolution_IWonderWhat, MSGBOX_NPC
	return


gText_Gldngtewilds_Spring_ThisPlace::
	.string "Man, this place is absolutely beautiful!$"
