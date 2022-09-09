Quest_WarehouseWarfare_CompleteAllDebug_Script::
	addvar VAR_TEMP_0, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WAREHOUSEWARFARE, SUB_QUEST_1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WAREHOUSEWARFARE, SUB_QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WAREHOUSEWARFARE, SUB_QUEST_3
	return


Quest_WarehouseWarfare_CheckBodegaProgress_Script::
	setvar VAR_TEMP_0, 0
	call Quest_WarehouseWarfare_CheckBodegaProgress1_Script
	call Quest_WarehouseWarfare_CheckBodegaProgress2_Script
	call Quest_WarehouseWarfare_CheckBodegaProgress3_Script
	call Quest_WarehouseWarfare_CheckBodegaProgress4_Script
	call Quest_WarehouseWarfare_CheckBodegaProgress5_Script
	call Quest_WarehouseWarfare_CheckBodegaProgress6_Script
	compare VAR_TEMP_0, 5
	goto_if_gt Quest_WarehouseWarfare_CheckBodegaProgress_Script_1
	return

Quest_WarehouseWarfare_CheckBodegaProgress_Script_1:
	call Quest_WarehouseWarfare_CallPlayer_Dialogue
	return


Quest_WarehouseWarfare_CheckBodegaProgress1_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress1_Script_2
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress1_Script_5
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress1_Script_8
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress1_Script_11
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress1_Script_14
	return

Quest_WarehouseWarfare_CheckBodegaProgress1_Script_2:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress1_Script_5:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress1_Script_8:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress1_Script_11:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress1_Script_14:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_CheckBodegaProgress2_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_6
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress2_Script_2
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_7
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress2_Script_5
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_8
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress2_Script_8
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_9
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress2_Script_11
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_10
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress2_Script_14
	return

Quest_WarehouseWarfare_CheckBodegaProgress2_Script_2:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress2_Script_5:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress2_Script_8:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress2_Script_11:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress2_Script_14:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_CheckBodegaProgress3_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_11
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress3_Script_2
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_12
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress3_Script_5
	return

Quest_WarehouseWarfare_CheckBodegaProgress3_Script_2:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress3_Script_5:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_CheckBodegaProgress4_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_13
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress4_Script_2
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_14
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress4_Script_5
	return

Quest_WarehouseWarfare_CheckBodegaProgress4_Script_2:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress4_Script_5:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_CheckBodegaProgress5_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_15
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress5_Script_2
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_16
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress5_Script_5
	return

Quest_WarehouseWarfare_CheckBodegaProgress5_Script_2:
	addvar VAR_TEMP_0, 1
	return

Quest_WarehouseWarfare_CheckBodegaProgress5_Script_5:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_CheckBodegaProgress6_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BODEGABURNOUT, SUB_QUEST_17
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckBodegaProgress6_Script_2
	return

Quest_WarehouseWarfare_CheckBodegaProgress6_Script_2:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_CallPlayer_Dialogue::
	lock
	playse SE_POKENAV_CALL
	msgbox gText_WarehouseWarfare_HeyIsThisPlayer
	msgbox gText_WarehouseWarfare_WeReallyAppreciate
	msgbox gText_WarehouseWarfare_WedLoveToWorkWith
	closemessage
	startquest QUEST_WAREHOUSEWARFARE
	release
	end


Quest_WarehouseWarfare_Interact_Event_Script::
	lock
	faceplayer
	returnqueststate QUEST_WAREHOUSEWARFARE
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_WarehouseWarfare_Interact_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_WarehouseWarfare_Interact_Event_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_WarehouseWarfare_Interact_Event_Script_4
	goto Quest_WarehouseWarfare_Welcome_Dialogue
	return

Quest_WarehouseWarfare_Interact_Event_Script_2:
	goto Quest_WarehouseWarfare_Active_Dialogue
	return

Quest_WarehouseWarfare_Interact_Event_Script_3:
	goto Quest_WarehouseWarfare_Reward_Dialogue
	return

Quest_WarehouseWarfare_Interact_Event_Script_4:
	goto Quest_WarehouseWarfare_Complete_Dialogue
	return


Quest_WarehouseWarfare_CheckSubquestProgress_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WAREHOUSEWARFARE, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckSubquestProgress_Script_2
Quest_WarehouseWarfare_CheckSubquestProgress_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WAREHOUSEWARFARE, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckSubquestProgress_Script_5
Quest_WarehouseWarfare_CheckSubquestProgress_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WAREHOUSEWARFARE, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_WarehouseWarfare_CheckSubquestProgress_Script_7
	return

Quest_WarehouseWarfare_CheckSubquestProgress_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_WarehouseWarfare_CheckSubquestProgress_Script_1

Quest_WarehouseWarfare_CheckSubquestProgress_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_WarehouseWarfare_CheckSubquestProgress_Script_4

Quest_WarehouseWarfare_CheckSubquestProgress_Script_7:
	addvar VAR_TEMP_0, 1
	return


Quest_WarehouseWarfare_Active_Dialogue::
	call Quest_WarehouseWarfare_CheckSubquestProgress_Script
	switch VAR_TEMP_0
	case 0, Quest_WarehouseWarfare_Active_Dialogue_2
	case 1, Quest_WarehouseWarfare_Active_Dialogue_3
	case 2, Quest_WarehouseWarfare_Active_Dialogue_4
	return

Quest_WarehouseWarfare_Active_Dialogue_2:
	goto Quest_WarehouseWarfare_ExplainBarge1_Dialogue
	return

Quest_WarehouseWarfare_Active_Dialogue_3:
	goto Quest_WarehouseWarfare_ExplainBarge2_Dialogue
	return

Quest_WarehouseWarfare_Active_Dialogue_4:
	goto Quest_WarehouseWarfare_ExplainBarge3_Dialogue
	return


Quest_WarehouseWarfare_ExplainBarge1_Dialogue::
	return


Quest_WarehouseWarfare_ExplainBarge2_Dialogue::
	return


Quest_WarehouseWarfare_ExplainBarge3_Dialogue::
	return


Quest_WarehouseWarfare_Welcome_Dialogue::
	msgbox gText_WarehouseWarfare_WelcomeTo, MSGBOX_NPC
	end


Quest_WarehouseWarfare_Reward_Dialogue::
	msgbox gText_WarehouseWarfare_HolyMoly, MSGBOX_NPC
	end


Quest_WarehouseWarfare_Complete_Dialogue::
	msgbox gText_WarehouseWarfare_ThanksAgain, MSGBOX_NPC
	end


gText_WarehouseWarfare_HeyIsThisPlayer::
	.string "Hey, is this {PLAYER}?$"

gText_WarehouseWarfare_WeReallyAppreciate::
	.string "We really appreciate all the work you're\n"
	.string "doing for the Shopkeepers Union! Most\l"
	.string "Trainers don't give us the time of day.$"

gText_WarehouseWarfare_WedLoveToWorkWith::
	.string "We've seen your work around the region,\n"
	.string "and would love to work with you in the\l"
	.string "future, if you're interested. Can you\l"
	.string "swing by the Shopkeepers Union HQ in\l"
	.string "Pacifica? We're right next to the\l"
	.string "Center.$"

gText_WarehouseWarfare_WelcomeTo::
	.string "Welcome to the Shopkeepers Union!$"

gText_WarehouseWarfare_HolyMoly::
	.string "Holy moly you did it.$"

gText_WarehouseWarfare_ThanksAgain::
	.string "Thanks again!$"
