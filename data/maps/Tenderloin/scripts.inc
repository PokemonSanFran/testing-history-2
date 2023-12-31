Tenderloin_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Tenderloin_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Tenderloin_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Tenderloin_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_TENDERLOIN
	call EnterAriana_ObjectCleanUp_Script
	call Quest_NoGoodDeed_HideRainer_Hotel_Script
	call Quest_Manofmanyhats_Liidia_Attendant_Visibility_Script
	call Quest_NeighborhoodCleanUp4_Object_Visibility_Script
	return

Tenderloin_MapScripts_MAP_SCRIPT_ON_LOAD:
	call EnterAriana_SetConeTiles_Script
	return


Tenderloin_EventScript_DeliveryE::
	returnqueststate QUEST_BODEGABURNOUT
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Tenderloin_EventScript_DeliveryE_2
Tenderloin_EventScript_DeliveryE_1:
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_AUTOCLOSE
	end

Tenderloin_EventScript_DeliveryE_2:
	goto Quest_Bodegaburnout_DeliveryE_Dialogue
	goto Tenderloin_EventScript_DeliveryE_1

