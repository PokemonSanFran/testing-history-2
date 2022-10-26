Quest_Restoremarin_MoveLenora_Script::
	compare VAR_STORYLINE_STATE, STORY_POST_BATTLE_ARCHER_TREASUREISLAND
	goto_if_gt Quest_Restoremarin_MoveLenora_Script_2
Quest_Restoremarin_MoveLenora_Script_1:
	return

Quest_Restoremarin_MoveLenora_Script_2:
	setobjectxy 7, 12, 18
	setobjectxyperm 7, 12, 18
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN
	goto Quest_Restoremarin_MoveLenora_Script_1


Quest_Restoremarin_HideLenora_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_HideLenora_Script_1
	return

Quest_Restoremarin_HideLenora_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_Restoremarin_StartQuest_Dialogue::
	startquest QUEST_RESTOREMARIN
	return


Quest_Restoremarin_CheckProgress_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_CheckProgress_Script_2
Quest_Restoremarin_CheckProgress_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_CheckProgress_Script_5
Quest_Restoremarin_CheckProgress_Script_4:
	switch VAR_TEMP_0
	case 0, Quest_Restoremarin_CheckProgress_Script_8
	case 1, Quest_Restoremarin_CheckProgress_Script_9
	case 2, Quest_Restoremarin_CheckProgress_Script_10
	return

Quest_Restoremarin_CheckProgress_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoremarin_CheckProgress_Script_1

Quest_Restoremarin_CheckProgress_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoremarin_CheckProgress_Script_4

Quest_Restoremarin_CheckProgress_Script_8:
	goto Quest_Restoremarin_First_Active_Dialogue
	return

Quest_Restoremarin_CheckProgress_Script_9:
	goto Quest_Restoremarin_Second_Active_Dialogue
	return

Quest_Restoremarin_CheckProgress_Script_10:
	questmenu QUEST_MENU_SET_REWARD, QUEST_RESTOREMARIN
	goto Quest_Restoremarin_Reward_Dialogue
	return


Quest_Restoremarin_First_Active_Dialogue::
	return


Quest_Restoremarin_Second_Active_Dialogue::
	return


Quest_Restoremarin_Reward_Dialogue::
	return

