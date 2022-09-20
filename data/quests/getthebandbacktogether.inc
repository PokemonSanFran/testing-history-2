Quest_GetTheBand_HideTedore_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ANGELDELIVERY
	compare VAR_RESULT, 0
	goto_if_eq Quest_GetTheBand_HideTedore_Script_1
	return

Quest_GetTheBand_HideTedore_Script_1:
	setflag FLAG_TEMP_4
	return


Quest_GetTheBand_HideBikerA_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_HideBikerA_Script_1
	return

Quest_GetTheBand_HideBikerA_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_GetTheBand_HideBikerB_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_HideBikerB_Script_1
	return

Quest_GetTheBand_HideBikerB_Script_1:
	setflag FLAG_TEMP_4
	return


Quest_GetTheBand_HideBikerC_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_HideBikerC_Script_1
	return

Quest_GetTheBand_HideBikerC_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_GetTheBand_HideBikerD_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_HideBikerD_Script_1
	return

Quest_GetTheBand_HideBikerD_Script_1:
	setflag FLAG_TEMP_6
	return


Quest_GetTheBand_HideBikerE_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_HideBikerE_Script_1
	return

Quest_GetTheBand_HideBikerE_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_GetTheBand_RemoveBikers_Script::
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	return


Quest_GetTheBand_Interact_BikerA_Dialogue::
	msgbox gText_GetTheBand_TheBikersSentYou, MSGBOX_NPC
	call Quest_GetTheBand_RemoveBikers_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_1
	call Quest_GetTheBand_CheckProgress_Script
	end


Quest_GetTheBand_Interact_BikerB_Dialogue::
	msgbox gText_GetTheBand_TheBikersSentYou, MSGBOX_NPC
	call Quest_GetTheBand_RemoveBikers_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_2
	call Quest_GetTheBand_CheckProgress_Script
	end


Quest_GetTheBand_Interact_BikerC_Dialogue::
	msgbox gText_GetTheBand_TheBikersSentYou, MSGBOX_NPC
	call Quest_GetTheBand_RemoveBikers_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_3
	call Quest_GetTheBand_CheckProgress_Script
	end


Quest_GetTheBand_Interact_BikerD_Dialogue::
	msgbox gText_GetTheBand_TheBikersSentYou, MSGBOX_NPC
	call Quest_GetTheBand_RemoveBikers_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_4
	call Quest_GetTheBand_CheckProgress_Script
	end


Quest_GetTheBand_Interact_BikerE_Dialogue::
	msgbox gText_GetTheBand_TheBikersSentYou, MSGBOX_NPC
	call Quest_GetTheBand_RemoveBikers_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_5
	call Quest_GetTheBand_CheckProgress_Script
	end


Quest_GetTheBand_CheckProgress_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_CheckProgress_Script_2
Quest_GetTheBand_CheckProgress_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_CheckProgress_Script_5
Quest_GetTheBand_CheckProgress_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_CheckProgress_Script_8
Quest_GetTheBand_CheckProgress_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_CheckProgress_Script_11
Quest_GetTheBand_CheckProgress_Script_10:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GETTHEBANDBACKTOGETHER, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_ne Quest_GetTheBand_CheckProgress_Script_14
Quest_GetTheBand_CheckProgress_Script_13:
	compare VAR_TEMP_0, 4
	goto_if_gt Quest_GetTheBand_CheckProgress_Script_17
Quest_GetTheBand_CheckProgress_Script_16:
	return

Quest_GetTheBand_CheckProgress_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_GetTheBand_CheckProgress_Script_1

Quest_GetTheBand_CheckProgress_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_GetTheBand_CheckProgress_Script_4

Quest_GetTheBand_CheckProgress_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_GetTheBand_CheckProgress_Script_7

Quest_GetTheBand_CheckProgress_Script_11:
	addvar VAR_TEMP_0, 1
	goto Quest_GetTheBand_CheckProgress_Script_10

Quest_GetTheBand_CheckProgress_Script_14:
	addvar VAR_TEMP_0, 1
	goto Quest_GetTheBand_CheckProgress_Script_13

Quest_GetTheBand_CheckProgress_Script_17:
	questmenu QUEST_MENU_SET_REWARD, QUEST_GETTHEBANDBACKTOGETHER
	goto Quest_GetTheBand_CheckProgress_Script_16


Quest_GetTheBand_Interact_Tedore_Script::
	lock
	faceplayer
	returnqueststate QUEST_GETTHEBANDBACKTOGETHER
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_GetTheBand_Interact_Tedore_Script_2
	case QUEST_MENU_SET_REWARD, Quest_GetTheBand_Interact_Tedore_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_GetTheBand_Interact_Tedore_Script_4
	goto Quest_GetTheBand_StartQuest_Dialogue
	return

Quest_GetTheBand_Interact_Tedore_Script_2:
	goto Quest_GetTheBand_Active_Dialogue
	return

Quest_GetTheBand_Interact_Tedore_Script_3:
	goto Quest_GetTheBand_Reward_Dialogue
	return

Quest_GetTheBand_Interact_Tedore_Script_4:
	goto Quest_GetTheBand_Completed_Dialogue
	return


Quest_GetTheBand_StartQuest_Dialogue::
	msgbox gText_GetTheBand_WeBuiltOutTheHQ
	msgbox gText_GetTheBand_KeepingInTouchIsHard
	msgbox gText_GetTheBand_CanYouTellBikersYouMeet
	msgbox gText_GetTheBand_YoullNeedBike
	startquest QUEST_GETTHEBANDBACKTOGETHER
	release
	end


Quest_GetTheBand_Active_Dialogue::
	call Quest_GetTheBand_CheckProgress_Script
	switch VAR_TEMP_0
	case 0, Quest_GetTheBand_Active_Dialogue_3
	case 1, Quest_GetTheBand_Active_Dialogue_4
	case 2, Quest_GetTheBand_Active_Dialogue_5
	case 3, Quest_GetTheBand_Active_Dialogue_5
	case 4, Quest_GetTheBand_Active_Dialogue_6
Quest_GetTheBand_Active_Dialogue_1:
	end

Quest_GetTheBand_Active_Dialogue_3:
	msgbox gText_GetTheBand_AnyLuckOnYourBike, MSGBOX_NPC
	goto Quest_GetTheBand_Active_Dialogue_1

Quest_GetTheBand_Active_Dialogue_4:
	msgbox gText_GetTheBand_OnePersonCameIn, MSGBOX_NPC
	goto Quest_GetTheBand_Active_Dialogue_1

Quest_GetTheBand_Active_Dialogue_5:
	msgbox gText_GetTheBand_TheyReallyStarting, MSGBOX_NPC
	goto Quest_GetTheBand_Active_Dialogue_1

Quest_GetTheBand_Active_Dialogue_6:
	msgbox gText_GetTheBand_WowItsSoGreat, MSGBOX_NPC
	goto Quest_GetTheBand_Active_Dialogue_1


Quest_GetTheBand_Reward_Dialogue::
	msgbox gText_GetTheBand_AllTheRooms
	msgbox gText_GetTheBand_ItFeelsAwesomeToHelp
	msgbox gText_GetTheBand_TakeThisUpgrade
	giveitem ITEM_UPGRADE, 1
	msgbox gText_GetTheBand_YourBikeGoesFaster, MSGBOX_NPC
	completequest QUEST_GETTHEBANDBACKTOGETHER
	release
	end


Quest_GetTheBand_Completed_Dialogue::
	msgbox gText_GetTheBand_HowsTheUpgrade, MSGBOX_NPC
	end


gText_GetTheBand_TheBikersSentYou::
	.string "the bikers sent you to find me? oh snap,\n"
	.string "i'll go to the dogpatch now$"

gText_GetTheBand_WeBuiltOutTheHQ::
	.string "$"

gText_GetTheBand_KeepingInTouchIsHard::
	.string "$"

gText_GetTheBand_CanYouTellBikersYouMeet::
	.string "$"

gText_GetTheBand_YoullNeedBike::
	.string "$"

gText_GetTheBand_AnyLuckOnYourBike::
	.string "$"

gText_GetTheBand_OnePersonCameIn::
	.string "$"

gText_GetTheBand_TheyReallyStarting::
	.string "$"

gText_GetTheBand_WowItsSoGreat::
	.string "$"

gText_GetTheBand_AllTheRooms::
	.string "$"

gText_GetTheBand_ItFeelsAwesomeToHelp::
	.string "$"

gText_GetTheBand_TakeThisUpgrade::
	.string "$"

gText_GetTheBand_YourBikeGoesFaster::
	.string "$"

gText_GetTheBand_HowsTheUpgrade::
	.string "$"
