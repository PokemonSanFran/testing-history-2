Quest_ArtisanBalls3_HideSilph_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ARTISANBALLS3
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls3_HideSilph_Script_1
	return

Quest_ArtisanBalls3_HideSilph_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_ArtisanBalls1_CheckStatus_Script::
	returnqueststate QUEST_ARTISANBALLS1
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ArtisanBalls1_CheckStatus_Script_2
	case QUEST_MENU_SET_REWARD, Quest_ArtisanBalls1_CheckStatus_Script_3
	goto Quest_ArtisanBalls1_Start_Dialogue
	return

Quest_ArtisanBalls1_CheckStatus_Script_2:
	goto Quest_ArtisanBalls1_During_Dialogue
	return

Quest_ArtisanBalls1_CheckStatus_Script_3:
	goto Quest_ArtisanBalls1_Reward_Dialogue
	return


Quest_ArtisanBalls1_Start_Dialogue::
	msgbox gText_Quest_ArtisanBalls_IGotFired, MSGBOX_NPC
	call Quest_ArtisanBalls1_GiveFirstSet
	startquest QUEST_ARTISANBALLS1
	return


Quest_ArtisanBalls1_GiveFirstSet::
	additem ITEM_FAST_BALL, 1
	additem ITEM_LEVEL_BALL, 1
	additem ITEM_LURE_BALL, 1
	additem ITEM_HEAVY_BALL, 1
	additem ITEM_LOVE_BALL, 1
	additem ITEM_FRIEND_BALL, 1
	additem ITEM_MOON_BALL, 1
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_Quest_ArtisanBalls_SergeyGaveYou
	waitmessage
	waitfanfare
	return


Quest_ArtisanBalls1_During_Dialogue::
	msgbox gText_Quest_ArtisanBalls_HowIsProgress, MSGBOX_NPC
	call Quest_ArtisanBalls1_During_ReplenishBalls_Script
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_ArtisanBalls1_During_Dialogue_2
	msgbox gText_Quest_ArtisanBalls__ThoseBallsCanBe, MSGBOX_NPC
	end

Quest_ArtisanBalls1_During_Dialogue_2:
	msgbox gText_Quest_ArtisanBalls_JustMadeThatToday, MSGBOX_NPC
	end


Quest_ArtisanBalls1_During_ReplenishBalls_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_2
Quest_ArtisanBalls1_During_ReplenishBalls_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_5
Quest_ArtisanBalls1_During_ReplenishBalls_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_10
Quest_ArtisanBalls1_During_ReplenishBalls_Script_9:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_15
Quest_ArtisanBalls1_During_ReplenishBalls_Script_14:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_20
Quest_ArtisanBalls1_During_ReplenishBalls_Script_19:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_6
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_25
Quest_ArtisanBalls1_During_ReplenishBalls_Script_24:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS1, SUB_QUEST_7
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_30
Quest_ArtisanBalls1_During_ReplenishBalls_Script_29:
	return

Quest_ArtisanBalls1_During_ReplenishBalls_Script_2:
	checkitem ITEM_FAST_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_7
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_1

Quest_ArtisanBalls1_During_ReplenishBalls_Script_5:
	checkitem ITEM_LEVEL_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_12
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_4

Quest_ArtisanBalls1_During_ReplenishBalls_Script_7:
	giveitem ITEM_FAST_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_1

Quest_ArtisanBalls1_During_ReplenishBalls_Script_10:
	checkitem ITEM_LURE_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_17
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_9

Quest_ArtisanBalls1_During_ReplenishBalls_Script_12:
	giveitem ITEM_LEVEL_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_4

Quest_ArtisanBalls1_During_ReplenishBalls_Script_15:
	checkitem ITEM_HEAVY_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_22
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_14

Quest_ArtisanBalls1_During_ReplenishBalls_Script_17:
	giveitem ITEM_LURE_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_9

Quest_ArtisanBalls1_During_ReplenishBalls_Script_20:
	checkitem ITEM_LOVE_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_27
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_19

Quest_ArtisanBalls1_During_ReplenishBalls_Script_22:
	giveitem ITEM_HEAVY_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_14

Quest_ArtisanBalls1_During_ReplenishBalls_Script_25:
	checkitem ITEM_FRIEND_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_32
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_24

Quest_ArtisanBalls1_During_ReplenishBalls_Script_27:
	giveitem ITEM_LOVE_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_19

Quest_ArtisanBalls1_During_ReplenishBalls_Script_30:
	checkitem ITEM_MOON_BALL, 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls1_During_ReplenishBalls_Script_34
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_29

Quest_ArtisanBalls1_During_ReplenishBalls_Script_32:
	giveitem ITEM_FRIEND_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_24

Quest_ArtisanBalls1_During_ReplenishBalls_Script_34:
	giveitem ITEM_MOON_BALL, 1
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls1_During_ReplenishBalls_Script_29


Quest_ArtisanBalls1_Reward_Dialogue::
	msgbox gText_Quest_ArtisanBalls_MyOrdersWentUp, MSGBOX_NPC
	call Quest_ArtisanBalls1_GiveReward_Script
	completequest QUEST_ARTISANBALLS1
	end


Quest_ArtisanBalls1_GiveReward_Script::
	giveitem ITEM_CHERISH_BALL, 1
	return


Quest_ArtisanBalls2_ShopQuestChoice_Script::
	msgbox gText_Quest_ArtisanBalls2_LookingToBuyOr, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Quest_ArtisanBalls2_ShopQuestChoice_Script_1
	goto Quest_ArtisanBalls2_During_ProgressCheck_Script
	return

Quest_ArtisanBalls2_ShopQuestChoice_Script_1:
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script
	return


Quest_ArtisanBalls2_GenerateDailyBall_Script::
	random 6
	copyvar VAR_TEMP_1, VAR_RESULT
	switch VAR_RESULT
	case 0, Quest_ArtisanBalls2_GenerateDailyBall_Script_2
	case 1, Quest_ArtisanBalls2_GenerateDailyBall_Script_3
	case 2, Quest_ArtisanBalls2_GenerateDailyBall_Script_4
	case 3, Quest_ArtisanBalls2_GenerateDailyBall_Script_5
	case 4, Quest_ArtisanBalls2_GenerateDailyBall_Script_6
	case 5, Quest_ArtisanBalls2_GenerateDailyBall_Script_7
	case 6, Quest_ArtisanBalls2_GenerateDailyBall_Script_8
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_2:
	bufferstring STR_VAR_1, ITEM_FAST_BALL
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_3:
	bufferstring STR_VAR_1, ITEM_LEVEL_BALL
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_4:
	bufferstring STR_VAR_1, ITEM_LURE_BALL
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_5:
	bufferstring STR_VAR_1, ITEM_HEAVY_BALL
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_6:
	bufferstring STR_VAR_1, ITEM_LOVE_BALL
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_7:
	bufferstring STR_VAR_1, ITEM_FRIEND_BALL
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_8:
	bufferstring STR_VAR_1, ITEM_MOON_BALL
	return


Quest_ArtisanBalls2_AskRandomBall_Script::
	msgbox gText_Quest_ArtisanBalls2_IMadeA, MSGBOX_NPC
	return


Quest_ArtisanBalls2_BuyRandomBall_Script::
	return


Quest_ArtisanBalls2_DeclineRandomBall_Script::
	return


Quest_ArtisanBalls2_Start_Dialogue::
	return


Quest_ArtisanBalls2_During_ProgressCheck_Script::
	return


Quest_ArtisanBalls2_During_Dialogue::
	return


Quest_ArtisanBalls2_Reward_Dialogue::
	return


Quest_ArtisanBalls2_GiveReward_Script::
	return


Quest_ArtisanBalls3_ShopQuestChoice_Script::
	return


Quest_ArtisanBalls3_GenerateMart_Script::
	return


Quest_ArtisanBalls3_DuringProgressCheck_Script::
	return


Quest_ArtisanBalls3_Start_Dialogue::
	return


Quest_ArtisanBalls3_During_Dialogue::
	return


Quest_ArtisanBalls3_Reward_Dialogue::
	return


Quest_ArtisanBalls3_GiveReward_Script::
	return


Quest_ArtisanBalls3_Post_Dialogue::
	return


gText_Quest_ArtisanBalls_IGotFired::
	.string "$"

gText_Quest_ArtisanBalls_SergeyGaveYou::
	.string "$"

gText_Quest_ArtisanBalls_HowIsProgress::
	.string "$"

gText_Quest_ArtisanBalls__ThoseBallsCanBe::
	.string "$"

gText_Quest_ArtisanBalls_DidYouRunOut::
	.string "$"

gText_Quest_ArtisanBalls_JustMadeThatToday::
	.string "$"

gText_Quest_ArtisanBalls_MyOrdersWentUp::
	.string "$"
