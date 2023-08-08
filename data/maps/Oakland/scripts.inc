Oakland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Oakland_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Oakland_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Oakland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Oakland_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_OAKLAND
	call WarehouseRave_HideObject_Script
	call Quest_GetTheBand_HideBikerC_Script
	call Quest_NoGoodDeed_HideRainer_Script
	call Quest_Restaurantexpansion_HideObjects_Script
	return

Oakland_MapScripts_MAP_SCRIPT_ON_RESUME:
	call_if_quest_active QUEST_DANCEBATTLE, Quest_Dancebattle_CreateCrowd_Script
	return

Oakland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_WAREHOUSE_RAVE_STATE, DEFEATED_KOGA_OAKLAND, WarehouseRave_OutsideWarehouse_Dialogue
	.2byte 0


Oakland_Biker_Interact_Script::
	msgbox gText_Oakland_PlaceholderBiker, MSGBOX_NPC
	call Quest_GetTheBand_CheckQuestAndBike_Script
	compare VAR_RESULT, 0
	goto_if_ne Oakland_Biker_Interact_Script_3
Oakland_Biker_Interact_Script_1:
	end

Oakland_Biker_Interact_Script_2:
	goto Quest_GetTheBand_Interact_BikerC_Dialogue
	goto Oakland_Biker_Interact_Script_1

Oakland_Biker_Interact_Script_3:
	compare VAR_TEMP_1, 0
	goto_if_ne Oakland_Biker_Interact_Script_2
	goto Oakland_Biker_Interact_Script_1


gText_Oakland_PlaceholderBiker::
	.string "i am a biker, and this is placeholder\n"
	.string "text.$"

gText_Oakland_PlaceholderOaklandFan::
	.string "I'm off to buy some shelves for my\n"
	.string "Drasna bobblehead set!$"
