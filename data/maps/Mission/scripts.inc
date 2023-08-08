Mission_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Mission_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Mission_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_MISSION
	call Quest_Recruitlocalartists_Sabrina_Visibility_Script
	call Quest_Recruitlocalartists_Smeargle_Visibility_Script
	call Quest_Restaurantexpansion_Mission_Leader_Visibilty_Script
	return


Mission_1_Interact_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RECRUITLOCALARTISTS
	compare VAR_QUEST_RECRUITLOLCAARTISTS, SMEARGLE_NO_LOCALS
	goto_if_eq Mission_1_Interact_Script_3
Mission_1_Interact_Script_2:
	msgbox gText_Mission_Placeholder, MSGBOX_NPC
	end

Mission_1_Interact_Script_1:
	goto Quest_Recruitlocalartists_First_Dialogue
	return

Mission_1_Interact_Script_3:
	compare VAR_RESULT, 0
	goto_if_ne Mission_1_Interact_Script_1
	goto Mission_1_Interact_Script_2


Mission_2_Interact_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RECRUITLOCALARTISTS
	compare VAR_QUEST_RECRUITLOLCAARTISTS, SMEARGLE_LOCAL_1
	goto_if_eq Mission_2_Interact_Script_3
Mission_2_Interact_Script_2:
	msgbox gText_Mission_Placeholder, MSGBOX_NPC
	end

Mission_2_Interact_Script_1:
	goto Quest_Recruitlocalartists_Second_Dialogue
	return

Mission_2_Interact_Script_3:
	compare VAR_RESULT, 0
	goto_if_ne Mission_2_Interact_Script_1
	goto Mission_2_Interact_Script_2


Mission_3_Interact_Script::
	msgbox gText_Mission_Placeholder, MSGBOX_NPC
	checktrainerflag TRAINER_PERSUASIVE_LANDLORD
	goto_if 1, Mission_3_Interact_Script_2
Mission_3_Interact_Script_1:
	end

Mission_3_Interact_Script_2:
	goto Quest_Persuasivepassenger_Sibling_Dialogue
	goto Mission_3_Interact_Script_1


gText_Mission_Placeholder::
	.string "$"
