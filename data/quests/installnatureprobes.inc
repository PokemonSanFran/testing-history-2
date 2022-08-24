Quest_InstallNatureProbes_Interact_Liidia_Script::
	lock
	call Quest_InstallNatureProbes_CheckCompletionRate_Script
	returnqueststate QUEST_INSTALLNATUREPROBES
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_InstallNatureProbes_Interact_Liidia_Script_2
	case QUEST_MENU_SET_REWARD, Quest_InstallNatureProbes_Interact_Liidia_Script_3
	goto Quest_InstallNatureProbes_StartQuest_Dialogue
	return

Quest_InstallNatureProbes_Interact_Liidia_Script_2:
	goto Quest_InstallNatureProbes_Active_Dialogue
	return

Quest_InstallNatureProbes_Interact_Liidia_Script_3:
	goto Quest_InstallNatureProbes_Reward_Cutscene
	return


Quest_InstallNatureProbes_StartQuest_Dialogue::
	msgbox gText_InstallNatureProbes_GeezIGottaWorkTonight, MSGBOX_NPC
	msgbox gText_InstallNatureProbes_ActuallyYoureATrainer, MSGBOX_NPC
	msgbox gText_InstallNatureProbes_CanYouHelp, MSGBOX_NPC
	startquest QUEST_INSTALLNATUREPROBES
	release
	end


Quest_InstallNatureProbes_Active_Dialogue::
	msgbox gText_InstallNatureProbes_WhatProbes, MSGBOX_NPC
	compare VAR_TEMP_1, 0
	goto_if_gt Quest_InstallNatureProbes_Active_Dialogue_2
Quest_InstallNatureProbes_Active_Dialogue_1:
	compare VAR_TEMP_2, 0
	goto_if_gt Quest_InstallNatureProbes_Active_Dialogue_5
Quest_InstallNatureProbes_Active_Dialogue_4:
	compare VAR_TEMP_3, 0
	goto_if_gt Quest_InstallNatureProbes_Active_Dialogue_7
	return

Quest_InstallNatureProbes_Active_Dialogue_2:
	msgbox gText_InstallNatureProbes_TheProbeInTheForest, MSGBOX_NPC
	goto Quest_InstallNatureProbes_Active_Dialogue_1

Quest_InstallNatureProbes_Active_Dialogue_5:
	msgbox gText_InstallNatureProbes_TheProbeOnTheHill, MSGBOX_NPC
	goto Quest_InstallNatureProbes_Active_Dialogue_4

Quest_InstallNatureProbes_Active_Dialogue_7:
	msgbox gText_InstallNatureProbes_TheProbeByTheShore, MSGBOX_NPC
	return


Quest_InstallNatureProbes_CheckCompletionRate_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_CheckCompletionRate_Script_2
Quest_InstallNatureProbes_CheckCompletionRate_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_CheckCompletionRate_Script_5
Quest_InstallNatureProbes_CheckCompletionRate_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_CheckCompletionRate_Script_8
Quest_InstallNatureProbes_CheckCompletionRate_Script_7:
	compare VAR_TEMP_0, 3
	goto_if_eq Quest_InstallNatureProbes_CheckCompletionRate_Script_10
	return

Quest_InstallNatureProbes_CheckCompletionRate_Script_2:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_1, 1
	goto Quest_InstallNatureProbes_CheckCompletionRate_Script_1

Quest_InstallNatureProbes_CheckCompletionRate_Script_5:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_2, 0
	goto Quest_InstallNatureProbes_CheckCompletionRate_Script_4

Quest_InstallNatureProbes_CheckCompletionRate_Script_8:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_3, 0
	goto Quest_InstallNatureProbes_CheckCompletionRate_Script_7

Quest_InstallNatureProbes_CheckCompletionRate_Script_10:
	questmenu QUEST_MENU_SET_REWARD, QUEST_INSTALLNATUREPROBES
	return


Quest_InstallNatureProbes_Reward_Cutscene::
	msgbox gText_InstallNatureProbes_WowYouGotAll, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceAwayPlayer
	waitmovement 2
	playse SE_PC_LOGIN
	waitse
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 2
	msgbox gText_InstallNatureProbes_TheTrackingIsWorking, MSGBOX_NPC
	closemessage
	playse SE_POKENAV_CALL
	waitse
	msgbox gText_InstallNatureProbes_ThatsMyBoss
	msgbox gText_InstallNatureProbes_GoForLiidia
	closemessage
	delay 32
	msgbox gText_InstallNatureProbes_IUnderstand
	playse SE_POKENAV_HANG_UP
	waitse
	msgbox gText_InstallNatureProbes_HeThankedMe
	msgbox gText_InstallNatureProbes_IRealizeNow
	applymovement 2, Quest_InstallNatureProbes_LeaveStation_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Quest_InstallNatureProbes_WatchLiidiaLeave_Movement
	waitmovement 2
	removeobject 2
	completequest QUEST_INSTALLNATUREPROBES
	release
	end


Quest_InstallNatureProbes_LeaveStation_Movement:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Quest_InstallNatureProbes_WatchLiidiaLeave_Movement:
	delay_16
	face_right
	face_down
	step_end

gText_InstallNatureProbes_GeezIGottaWorkTonight::
	.string "$"

gText_InstallNatureProbes_ActuallyYoureATrainer::
	.string "$"

gText_InstallNatureProbes_CanYouHelp::
	.string "$"

gText_InstallNatureProbes_WhatProbes::
	.string "$"

gText_InstallNatureProbes_TheProbeInTheForest::
	.string "$"

gText_InstallNatureProbes_TheProbeOnTheHill::
	.string "$"

gText_InstallNatureProbes_TheProbeByTheShore::
	.string "$"

gText_InstallNatureProbes_WowYouGotAll::
	.string "$"

gText_InstallNatureProbes_TheTrackingIsWorking::
	.string "$"

gText_InstallNatureProbes_ThatsMyBoss::
	.string "$"

gText_InstallNatureProbes_GoForLiidia::
	.string "$"

gText_InstallNatureProbes_IUnderstand::
	.string "$"

gText_InstallNatureProbes_HeThankedMe::
	.string "$"

gText_InstallNatureProbes_IRealizeNow::
	.string "$"
