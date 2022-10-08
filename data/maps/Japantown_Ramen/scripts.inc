Japantown_Ramen_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Japantown_Ramen_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Japantown_Ramen_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_BlueRobbery_Restaurant_HideObject_Script
	return


Japantown_Ramen_InteractFanny_Event_Script::
	lock
	switch VAR_LILYCOVE_CITY_STATE
	case NOT_ASSIGNED, Japantown_Ramen_InteractFanny_Event_Script_3
	case ASSIGNED_MASK_OFF, Japantown_Ramen_InteractFanny_Event_Script_3
	case GOT_MASK_OFF_CLUE_1, Japantown_Ramen_InteractFanny_Event_Script_3
	case DEFEATED_MASK_OFF_GIOVANNI, Japantown_Ramen_InteractFanny_Event_Script_3
	call MaskOff_QuestI_Dialogue
	release
	end

Japantown_Ramen_InteractFanny_Event_Script_3:
	return


Japantown_Ramen_FoodCulture_Script::
	msgbox gText_Japantown_Ramen_TheRamenIsGreat, MSGBOX_NPC
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HYBRIDCULTURE, SUB_QUEST_1
	call Quest_HybridCulture_CheckSubquests_Script
	end


gText_Japantown_Ramen_TheRamenIsGreat::
	.string "The ramen is great, but my favorite item\n"
	.string "on the menu are the Poffins! Poffins\l"
	.string "are a Sinnoh dessert, but here they use\l"
	.string "all sorts of flavors you can't find\l"
	.string "overseas! The tastiest are the yellow\l"
	.string "Poke Bean! Or wait, is it the\l"
	.string "Casteliacone flavor...?$"
