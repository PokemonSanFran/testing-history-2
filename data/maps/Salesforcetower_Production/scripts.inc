Salesforcetower_Production_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Salesforcetower_Production_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Salesforcetower_Production_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Salesforcetower_GuardRaidFloors_Script
	call Salesforcetower_Production_Sabrina_Visibility_Script
	return


Salesforcetower_Production_Sabrina_Visibility_Script::
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	special GetNumberOfBadges
	compare VAR_RESULT, 4
	goto_if_gt Salesforcetower_Production_Sabrina_Visibility_Script_2
Salesforcetower_Production_Sabrina_Visibility_Script_1:
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_RECRUITLOCALARTISTS
	compare VAR_RESULT, 0
	goto_if_ne Salesforcetower_Production_Sabrina_Visibility_Script_5
Salesforcetower_Production_Sabrina_Visibility_Script_4:
	compare VAR_STORYLINE_STATE, STORY_ARCHER_EXPLAIN_RESTORATION
	goto_if_gt Salesforcetower_Production_Sabrina_Visibility_Script_9
Salesforcetower_Production_Sabrina_Visibility_Script_7:
	compare VAR_TEMP_0, 0
	goto_if_gt Salesforcetower_Production_Sabrina_Visibility_Script_13
	compare VAR_TEMP_1, 2
	goto_if_eq Salesforcetower_Production_Sabrina_Visibility_Script_13
Salesforcetower_Production_Sabrina_Visibility_Script_12:
	return

Salesforcetower_Production_Sabrina_Visibility_Script_2:
	addvar VAR_TEMP_1, 1
	goto Salesforcetower_Production_Sabrina_Visibility_Script_1

Salesforcetower_Production_Sabrina_Visibility_Script_5:
	addvar VAR_TEMP_1, 1
	goto Salesforcetower_Production_Sabrina_Visibility_Script_4

Salesforcetower_Production_Sabrina_Visibility_Script_8:
	addvar VAR_TEMP_0, 1
	goto Salesforcetower_Production_Sabrina_Visibility_Script_7

Salesforcetower_Production_Sabrina_Visibility_Script_9:
	compare VAR_STORYLINE_STATE, STORY_RECIEVED_BAMBOO_STAR
	goto_if_ne Salesforcetower_Production_Sabrina_Visibility_Script_8
	goto Salesforcetower_Production_Sabrina_Visibility_Script_7

Salesforcetower_Production_Sabrina_Visibility_Script_13:
	setflag FLAG_TEMP_2
	goto Salesforcetower_Production_Sabrina_Visibility_Script_12


Salesforcetower_Interact_Sabrina_Script::
	returnqueststate QUEST_RECRUITLOCALARTISTS
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Salesforcetower_Interact_Sabrina_Script_2
	case QUEST_MENU_SET_REWARD, Salesforcetower_Interact_Sabrina_Script_3
	goto AlwaysWatchingWazowski_IgnoringPlayer_Dialogue
	return

Salesforcetower_Interact_Sabrina_Script_2:
	goto Quest_Recruitlocalartists_Active_Dialogue
	return

Salesforcetower_Interact_Sabrina_Script_3:
	goto Quest_Recruitlocalartists_CompleteQuest_Dialogue
	return

