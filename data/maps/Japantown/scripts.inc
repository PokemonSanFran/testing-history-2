Japantown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Japantown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Japantown_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Japantown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_JAPANTOWN
	call Quest_HybridCulture_HideLeader_Script
	call Quest_GetTheBand_HideBikerE_Script
	call Quest_CutePokemon_HideMelissaA_Script
	return

Japantown_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Quest_ArtisanBalls3_ChangeDoorMetatile_Script
	return


Japantown_FashionDesigner_Script::
	msgbox gText_Japantown_ImAFashion, MSGBOX_NPC
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HYBRIDCULTURE, SUB_QUEST_2
	call Quest_HybridCulture_CheckSubquests_Script
	end


Japantown_Biker_Interact_Script::
	msgbox gText_Japantown_PlaceholderBiker, MSGBOX_NPC
	call Quest_GetTheBand_CheckQuestAndBike_Script
	compare VAR_RESULT, 0
	goto_if_ne Japantown_Biker_Interact_Script_3
Japantown_Biker_Interact_Script_1:
	end

Japantown_Biker_Interact_Script_2:
	goto Quest_GetTheBand_Interact_BikerE_Dialogue
	goto Japantown_Biker_Interact_Script_1

Japantown_Biker_Interact_Script_3:
	compare VAR_TEMP_1, 0
	goto_if_ne Japantown_Biker_Interact_Script_2
	goto Japantown_Biker_Interact_Script_1


gText_Japantown_PlaceholderBiker::
	.string "i am a biker, and this is placeholder\n"
	.string "text.$"

gText_Japantown_ImAFashion::
	.string "I'm a fashion designer. I can't afford\n"
	.string "to travel to Sinnoh... but I love when\l"
	.string "their tourists come here! They're\l"
	.string "always wearing the latest styles and\l"
	.string "fashions, and so much of it doesn't\l"
	.string "translate when looking online.$"
