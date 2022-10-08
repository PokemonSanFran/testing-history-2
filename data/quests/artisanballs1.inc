Quest_ArtisanBalls1_DebugA_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_1
	msgbox Quest_ArtisanBalls1_DebugA_Script_Text_0
	release
	end


Quest_ArtisanBalls1_DebugB_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_3
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_4
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_5
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_6
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS1, SUB_QUEST_7
	questmenu QUEST_MENU_SET_REWARD, QUEST_ARTISANBALLS1
	msgbox Quest_ArtisanBalls1_DebugB_Script_Text_0
	release
	end


Quest_ArtisanBalls2_DebugA_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_1
	msgbox Quest_ArtisanBalls2_DebugA_Script_Text_0
	release
	end


Quest_ArtisanBalls2_DebugB_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_3
	call Quest_ArtisanBalls2_CheckReward_Script
	msgbox Quest_ArtisanBalls2_DebugB_Script_Text_0
	warp MAP_JAPANTOWN, 4, 16
	release
	end


Quest_ArtisanBalls3_DebugA_Script::
	questmenu QUEST_MENU_SET_REWARD, QUEST_ARTISANBALLS3
	msgbox Quest_ArtisanBalls3_DebugA_Script_Text_0
	release
	end


Quest_ArtisanBalls3_HideSilph_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ARTISANBALLS3
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls3_HideSilph_Script_1
	return

Quest_ArtisanBalls3_HideSilph_Script_1:
	setflag FLAG_TEMP_4
	return


Quest_ArtisanBalls2_HideEmployees_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls2_HideEmployees_Script_2
Quest_ArtisanBalls2_HideEmployees_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls2_HideEmployees_Script_5
Quest_ArtisanBalls2_HideEmployees_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls2_HideEmployees_Script_8
Quest_ArtisanBalls2_HideEmployees_Script_7:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS3
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls2_HideEmployees_Script_10
	return

Quest_ArtisanBalls2_HideEmployees_Script_2:
	setflag FLAG_TEMP_1
	goto Quest_ArtisanBalls2_HideEmployees_Script_1

Quest_ArtisanBalls2_HideEmployees_Script_5:
	setflag FLAG_TEMP_2
	goto Quest_ArtisanBalls2_HideEmployees_Script_4

Quest_ArtisanBalls2_HideEmployees_Script_8:
	setflag FLAG_TEMP_3
	goto Quest_ArtisanBalls2_HideEmployees_Script_7

Quest_ArtisanBalls2_HideEmployees_Script_10:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


Quest_ArtisanBalls1_CheckStatus_Script::
	returnqueststate QUEST_ARTISANBALLS1
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ArtisanBalls1_CheckStatus_Script_2
	case QUEST_MENU_SET_REWARD, Quest_ArtisanBalls1_CheckStatus_Script_3
	goto Quest_ArtisanBalls1_Start_Dialogue
	return

Quest_ArtisanBalls1_CheckStatus_Script_2:
	goto Quest_ArtisanBalls1_Active_Dialogue
	return

Quest_ArtisanBalls1_CheckStatus_Script_3:
	goto Quest_ArtisanBalls1_Reward_Dialogue
	return


Quest_ArtisanBalls1_Start_Dialogue::
	msgbox gText_Quest_ArtisanBalls_IGotFired, MSGBOX_NPC
	call Quest_ArtisanBalls1_GiveFirstSet
	startquest QUEST_ARTISANBALLS1
	msgbox gText_Quest_ArtisanBalls_ComeBack, MSGBOX_NPC
	end


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


Quest_ArtisanBalls1_Active_Dialogue::
	msgbox gText_Quest_ArtisanBalls_HowIsProgress, MSGBOX_NPC
	call Quest_ArtisanBalls1_During_ReplenishBalls_Script
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_ArtisanBalls1_Active_Dialogue_2
	msgbox gText_Quest_ArtisanBalls__ThoseBallsCanBe, MSGBOX_NPC
	end

Quest_ArtisanBalls1_Active_Dialogue_2:
	msgbox gText_Quest_ArtisanBalls_JustMadeThatToday, MSGBOX_NPC
	end


Quest_ArtisanBalls1_During_ReplenishBalls_Script::
	setvar VAR_TEMP_0, 0
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
	msgbox gText_Quest_ArtisanBalls_SoTheyAllWork, MSGBOX_NPC
	call Quest_ArtisanBalls1_GiveReward_Script
	completequest QUEST_ARTISANBALLS1
	end


Quest_ArtisanBalls1_GiveReward_Script::
	giveitem ITEM_CHERISH_BALL, 1
	setvar VAR_TEMP_5, 1
	return


Quest_ArtisanBalls2_HideTrainerFalse_Script::
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls2_HideTrainerFalse_Script_2
Quest_ArtisanBalls2_HideTrainerFalse_Script_1:
	return

Quest_ArtisanBalls2_HideTrainerFalse_Script_2:
	setflag FLAG_TEMP_C
	goto Quest_ArtisanBalls2_HideTrainerFalse_Script_1


Quest_ArtisanBalls2_HideTrainerTrue_Script::
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls2_HideTrainerTrue_Script_2
Quest_ArtisanBalls2_HideTrainerTrue_Script_1:
	return

Quest_ArtisanBalls2_HideTrainerTrue_Script_2:
	setflag FLAG_TEMP_C
	goto Quest_ArtisanBalls2_HideTrainerTrue_Script_1


Quest_ArtisanBalls2_CheckActiveAndHide_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ARTISANBALLS2
	call Quest_ArtisanBalls2_HideTrainerFalse_Script
	return


Quest_ArtisanBalls2_CheckTrainerA_Script::
	call Quest_ArtisanBalls2_CheckActiveAndHide_Script
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_1
	call Quest_ArtisanBalls2_HideTrainerTrue_Script
	return


Quest_ArtisanBalls2_CheckTrainerB_Script::
	call Quest_ArtisanBalls2_CheckActiveAndHide_Script
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_2
	call Quest_ArtisanBalls2_HideTrainerTrue_Script
	return


Quest_ArtisanBalls2_CheckTrainerC_Script::
	call Quest_ArtisanBalls2_CheckActiveAndHide_Script
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_3
	call Quest_ArtisanBalls2_HideTrainerTrue_Script
	return


Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script::
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script_2
	msgbox gText_Quest_ArtisanBalls2_LookingToBuyOr, MSGBOX_YESNO
Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script_1:
	return

Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script_2:
	msgbox gText_Quest_ArtisanBalls2_LookingToBuyActive, MSGBOX_YESNO
	goto Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script_1


Quest_ArtisanBalls2_ShopQuestChoice_Script::
	faceplayer
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ARTISANBALLS2
	call Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script
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
	case 0, Quest_ArtisanBalls2_GenerateDailyBall_Script_3
	case 1, Quest_ArtisanBalls2_GenerateDailyBall_Script_4
	case 2, Quest_ArtisanBalls2_GenerateDailyBall_Script_5
	case 3, Quest_ArtisanBalls2_GenerateDailyBall_Script_6
	case 4, Quest_ArtisanBalls2_GenerateDailyBall_Script_7
	case 5, Quest_ArtisanBalls2_GenerateDailyBall_Script_8
	case 6, Quest_ArtisanBalls2_GenerateDailyBall_Script_9
Quest_ArtisanBalls2_GenerateDailyBall_Script_1:
	goto Quest_ArtisanBalls2_AskRandomBall_Script
	return

Quest_ArtisanBalls2_GenerateDailyBall_Script_3:
	bufferitemname STR_VAR_3, ITEM_FAST_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1

Quest_ArtisanBalls2_GenerateDailyBall_Script_4:
	bufferitemname STR_VAR_3, ITEM_LEVEL_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1

Quest_ArtisanBalls2_GenerateDailyBall_Script_5:
	bufferitemname STR_VAR_3, ITEM_LURE_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1

Quest_ArtisanBalls2_GenerateDailyBall_Script_6:
	bufferitemname STR_VAR_3, ITEM_HEAVY_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1

Quest_ArtisanBalls2_GenerateDailyBall_Script_7:
	bufferitemname STR_VAR_3, ITEM_LOVE_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1

Quest_ArtisanBalls2_GenerateDailyBall_Script_8:
	bufferitemname STR_VAR_3, ITEM_FRIEND_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1

Quest_ArtisanBalls2_GenerateDailyBall_Script_9:
	bufferitemname STR_VAR_3, ITEM_MOON_BALL
	goto Quest_ArtisanBalls2_GenerateDailyBall_Script_1


Quest_ArtisanBalls2_AskRandomBall_Script::
	showmoneybox 0, 0
	msgbox gText_Quest_ArtisanBalls2_IMadeA, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Quest_ArtisanBalls2_AskRandomBall_Script_2
	call Quest_ArtisanBalls2_DeclineRandomBall_Script
Quest_ArtisanBalls2_AskRandomBall_Script_1:
	hidemoneybox
	release
	end

Quest_ArtisanBalls2_AskRandomBall_Script_2:
	call Quest_ArtisanBalls2_BuyRandomBall_Script
	goto Quest_ArtisanBalls2_AskRandomBall_Script_1


Quest_ArtisanBalls2_BuyRandomBall_Script::
	removemoney 1300, 0
	updatemoneybox 0
	switch VAR_TEMP_1
	case 0, Quest_ArtisanBalls2_BuyRandomBall_Script_3
	case 1, Quest_ArtisanBalls2_BuyRandomBall_Script_4
	case 2, Quest_ArtisanBalls2_BuyRandomBall_Script_5
	case 3, Quest_ArtisanBalls2_BuyRandomBall_Script_6
	case 4, Quest_ArtisanBalls2_BuyRandomBall_Script_7
	case 5, Quest_ArtisanBalls2_BuyRandomBall_Script_8
	case 6, Quest_ArtisanBalls2_BuyRandomBall_Script_9
Quest_ArtisanBalls2_BuyRandomBall_Script_1:
	return

Quest_ArtisanBalls2_BuyRandomBall_Script_3:
	giveitem ITEM_FAST_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1

Quest_ArtisanBalls2_BuyRandomBall_Script_4:
	giveitem ITEM_LEVEL_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1

Quest_ArtisanBalls2_BuyRandomBall_Script_5:
	giveitem ITEM_LURE_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1

Quest_ArtisanBalls2_BuyRandomBall_Script_6:
	giveitem ITEM_HEAVY_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1

Quest_ArtisanBalls2_BuyRandomBall_Script_7:
	giveitem ITEM_LOVE_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1

Quest_ArtisanBalls2_BuyRandomBall_Script_8:
	giveitem ITEM_FRIEND_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1

Quest_ArtisanBalls2_BuyRandomBall_Script_9:
	giveitem ITEM_MOON_BALL, 1
	goto Quest_ArtisanBalls2_BuyRandomBall_Script_1


Quest_ArtisanBalls2_DeclineRandomBall_Script::
	msgbox gText_Quest_ArtisanBalls2_NoWorries, MSGBOX_NPC
	return


Quest_ArtisanBalls2_During_ProgressCheck_Script::
	returnqueststate QUEST_ARTISANBALLS2
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ArtisanBalls2_During_ProgressCheck_Script_2
	case QUEST_MENU_SET_REWARD, Quest_ArtisanBalls2_During_ProgressCheck_Script_3
	goto Quest_ArtisanBalls2_Start_Dialogue
	return

Quest_ArtisanBalls2_During_ProgressCheck_Script_2:
	goto Quest_ArtisanBalls2_Active_Dialogue
	return

Quest_ArtisanBalls2_During_ProgressCheck_Script_3:
	goto Quest_ArtisanBalls2_Reward_Dialogue
	return


Quest_ArtisanBalls2_Start_Dialogue::
	msgbox gText_Quest_ArtisanBalls2_ImReadyToExpand, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_ThatsAmazing, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_INeedHelp, MSGBOX_NPC
	startquest QUEST_ARTISANBALLS2
	end


Quest_ArtisanBalls2_Active_Dialogue::
	setvar VAR_TEMP_0, 0
	call Quest_ArtisanBalls2_CheckReward_Script
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_ArtisanBalls2_Active_Dialogue_2
	msgbox gText_Quest_ArtisanBalls2_FindingHelp, MSGBOX_NPC
Quest_ArtisanBalls2_Active_Dialogue_1:
	end

Quest_ArtisanBalls2_Active_Dialogue_2:
	msgbox gText_Quest_ArtisanBalls2_WowPeopleAre, MSGBOX_NPC
	goto Quest_ArtisanBalls2_Active_Dialogue_1


Quest_ArtisanBalls_TrainerA_Event_Script::
	trainerbattle_single TRAINER_FELIX, gText_Quest_ArtisanBalls2_YoudThink, gText_Quest_ArtisanBalls2_NotEvenClose, Quest_ArtisanBalls_TrainerA_PostBattle_Script
	return


Quest_ArtisanBalls_TrainerA_PostBattle_Script::
	lock
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_1
	call Quest_ArtisanBalls2_CheckReward_Script
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_WhereDidYouGet, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_MyGirlfriend, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_OfficeManagerRight, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_WaitReally, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	release
	end


Quest_ArtisanBalls_TrainerB_Event_Script::
	trainerbattle_single TRAINER_VIOLET, gText_Quest_ArtisanBalls2_MyPersonalBrand, gText_Quest_ArtisanBalls2_IHopeGettingDefeated, Quest_ArtisanBalls_TrainerB_PostBattle_Script
	return


Quest_ArtisanBalls_TrainerB_PostBattle_Script::
	lock
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_2
	call Quest_ArtisanBalls2_CheckReward_Script
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_WhereDidYouGet, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_ISawThe, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_YouSaidYouWereInto, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_OhManWhat, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	release
	end


Quest_ArtisanBalls_TrainerC_Event_Script::
	trainerbattle_single TRAINER_ROSE_2, gText_Quest_ArtisanBalls2_IMissHelpingPeople, gText_Quest_ArtisanBalls2_DidIHelpYou, Quest_ArtisanBalls_TrainerC_PostBattle_Script
	return


Quest_ArtisanBalls_TrainerC_PostBattle_Script::
	lock
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_ARTISANBALLS2, SUB_QUEST_3
	call Quest_ArtisanBalls2_CheckReward_Script
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_WhereDidYouGet, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_IMetTheVendor, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls2_IfYouLikeHelping, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls2_ThatWouldBe, MSGBOX_NPC
	fadescreen FADE_TO_BLACK
	removeobject 2
	fadescreen FADE_FROM_BLACK
	release
	end


Quest_ArtisanBalls2_CheckReward_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls2_CheckReward_Script_2
Quest_ArtisanBalls2_CheckReward_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls2_CheckReward_Script_5
Quest_ArtisanBalls2_CheckReward_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS2, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls2_CheckReward_Script_8
Quest_ArtisanBalls2_CheckReward_Script_7:
	compare VAR_TEMP_0, 3
	goto_if_eq Quest_ArtisanBalls2_CheckReward_Script_11
Quest_ArtisanBalls2_CheckReward_Script_10:
	return

Quest_ArtisanBalls2_CheckReward_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls2_CheckReward_Script_1

Quest_ArtisanBalls2_CheckReward_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls2_CheckReward_Script_4

Quest_ArtisanBalls2_CheckReward_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_ArtisanBalls2_CheckReward_Script_7

Quest_ArtisanBalls2_CheckReward_Script_11:
	questmenu QUEST_MENU_SET_REWARD, QUEST_ARTISANBALLS2
	goto Quest_ArtisanBalls2_CheckReward_Script_10


Quest_ArtisanBalls2_Reward_Dialogue::
	msgbox gText_Quest_ArtisanBalls2_IThinkIHaveTheStaff, MSGBOX_NPC
	call Quest_ArtisanBalls2_GiveReward_Script
	completequest QUEST_ARTISANBALLS2
	end


Quest_ArtisanBalls2_GiveReward_Script::
	giveitem ITEM_DREAM_BALL, 5
	setvar VAR_TEMP_5, 1
	return


Quest_ArtisanBalls3_ShopQuestChoice_Script::
	faceplayer
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ARTISANBALLS3
	call Quest_ArtisanBalls2_ShopQuestChoiceChoosePrompt_Script
	compare VAR_RESULT, YES
	goto_if_eq Quest_ArtisanBalls3_ShopQuestChoice_Script_1
	goto Quest_ArtisanBalls3_DuringProgressCheck_Script
	return

Quest_ArtisanBalls3_ShopQuestChoice_Script_1:
	goto Quest_ArtisanBalls3_GenerateMart_Script
	return


Quest_ArtisanBalls3_GenerateMart_Script::
	lock
	faceplayer
	msgbox gText_Quest_ArtisanBalls3_WhatBallsDoYou
	waitmessage
	pokemart ArtisanBallsShop
	msgbox gText_Quest_ArtisanBalls3_ThanksAgain, MSGBOX_NPC
	release
	return


	.align 2
ArtisanBallsShop:
	.2byte ITEM_FAST_BALL
	.2byte ITEM_LEVEL_BALL
	.2byte ITEM_LURE_BALL
	.2byte ITEM_HEAVY_BALL
	.2byte ITEM_LOVE_BALL
	.2byte ITEM_FRIEND_BALL
	.2byte ITEM_MOON_BALL
	.2byte ITEM_NONE

Quest_ArtisanBalls3_DuringProgressCheck_Script::
	returnqueststate QUEST_ARTISANBALLS3
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ArtisanBalls3_DuringProgressCheck_Script_2
	goto Quest_ArtisanBalls3_Start_Dialogue
	return

Quest_ArtisanBalls3_DuringProgressCheck_Script_2:
	goto Quest_ArtisanBalls3_Active_Dialogue
	return


Quest_ArtisanBalls3_Start_Dialogue::
	msgbox gText_Quest_ArtisanBalls3_BusinessHasBeen, MSGBOX_NPC
	msgbox gText_Quest_ArtisanBalls3_IveBeenTalkingTo, MSGBOX_NPC
	startquest QUEST_ARTISANBALLS3
	release
	end


Quest_ArtisanBalls3_Active_Dialogue::
	msgbox gText_Quest_ArtisanBalls3_CantWaitToSee, MSGBOX_NPC
	end


Quest_ArtisanBalls3_Reward_Cutscene::
	addvar VAR_TEMP_3, 99
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ARTISANBALLS3
	compare VAR_RESULT, 0
	goto_if_eq Quest_ArtisanBalls3_Reward_Cutscene_2
	lock
	applymovement 2, Quest_ArtisanBalls3_LeaveRoom_Movement
	waitmovement 2
	playse SE_EXIT
	removeobject 2
	applymovement 1, Quest_ArtisanBalls3_RunToDoor_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 1
	msgbox gText_Quest_ArtisanBalls3_DidYouHearThat, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ArtisanBalls3_NoButItSounds, MSGBOX_DEFAULT
	callnative ClearMugshot
	msgbox gText_Quest_ArtisanBalls3_TheyWantToAcquire, MSGBOX_DEFAULT
	call Quest_ArtisanBalls3_GiveReward_Script
	completequest QUEST_ARTISANBALLS3
	end

Quest_ArtisanBalls3_Reward_Cutscene_2:
	release
	end


Quest_ArtisanBalls3_GiveReward_Script::
	giveitem ITEM_MASTER_BALL, 1
	setvar VAR_TEMP_5, 1
	return


Quest_ArtisanBalls3_Post_Dialogue::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS3
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls3_Post_Dialogue_2
Quest_ArtisanBalls3_Post_Dialogue_1:
	release
	end

Quest_ArtisanBalls3_Post_Dialogue_2:
	lock
	msgbox gText_Quest_ArtisanBalls_TheDoorIsLockedBut, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Quest_ArtisanBalls3_Post_Dialogue_4
	goto Quest_ArtisanBalls3_Post_Dialogue_1

Quest_ArtisanBalls3_Post_Dialogue_4:
	msgbox gText_Quest_ArtisanBalls_ToMyCustomers, MSGBOX_SIGN
	goto Quest_ArtisanBalls3_Post_Dialogue_1


Quest_ArtisanBalls_BetweenStates_Dialogue::
	msgbox gText_Quest_ArtisanBalls3_ImSoExcitedForWhat, MSGBOX_NPC
	end


Quest_ArtisanBalls3_ChangeDoorMetatile_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ARTISANBALLS3
	compare VAR_RESULT, 0
	goto_if_ne Quest_ArtisanBalls3_ChangeDoorMetatile_Script_2
Quest_ArtisanBalls3_ChangeDoorMetatile_Script_1:
	return

Quest_ArtisanBalls3_ChangeDoorMetatile_Script_2:
	setmetatile 4, 15, 0x014, TRUE
	goto Quest_ArtisanBalls3_ChangeDoorMetatile_Script_1


Quest_ArtisanBalls3_LeaveRoom_Movement:
	walk_down
	walk_right
	walk_down
	step_end

Quest_ArtisanBalls3_RunToDoor_Movement:
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_down
	face_right
	jump_in_place_right
	jump_in_place_right
	step_end

Quest_ArtisanBalls1_DebugA_Script_Text_0:
	.string "you caught a pokemon in a fast ball.$"

Quest_ArtisanBalls1_DebugB_Script_Text_0:
	.string "you caught 7 pokemon in 7 different\n"
	.string "balls$"

Quest_ArtisanBalls2_DebugA_Script_Text_0:
	.string "you recruited one person$"

Quest_ArtisanBalls2_DebugB_Script_Text_0:
	.string "you recruited all the people$"

Quest_ArtisanBalls3_DebugA_Script_Text_0:
	.string "you defeated a gym leader while you had\n"
	.string "a ball$"

gText_Quest_ArtisanBalls_WhichPokeBall::
	.string "Sergey has noted on all of his craft\n"
	.string "Poke Balls. Which one would you like to\l"
	.string "read about?$"

gText_Quest_ArtisanBalls_ExplainFast::
	.string "$"

gText_Quest_ArtisanBalls_ExplainLevel::
	.string "$"

gText_Quest_ArtisanBalls_ExplainLure::
	.string "$"

gText_Quest_ArtisanBalls_ExplainHeavy::
	.string "$"

gText_Quest_ArtisanBalls_ExplainLove::
	.string "$"

gText_Quest_ArtisanBalls_ExplainFriend::
	.string "$"

gText_Quest_ArtisanBalls_ExplainMoon::
	.string "$"

gText_Quest_ArtisanBalls_IGotFired::
	.string "I make craft PokéBalls. I'm tired of\n"
	.string "working for somebody else, and want to\l"
	.string "open a shop selling my Balls! Would you\l"
	.string "be willing to test my PokeBalls?$"

gText_Quest_ArtisanBalls_SergeyGaveYou::
	.string "{PLAYER} obtained a set of craft\n"
	.string "PokéBalls!$"

gText_Quest_ArtisanBalls_ComeBack::
	.string "That set has one of each: Fast, Level,\n"
	.string "Lure, Love, Friend and a Moon Ball. The\l"
	.string "books explain how to best use them.\l"
	.string "Come back if you need more PokeBalls.$"

gText_Quest_ArtisanBalls_HowIsProgress::
	.string "How is progress going?$"

gText_Quest_ArtisanBalls__ThoseBallsCanBe::
	.string "Those balls can be tricky to use! You\n"
	.string "gotta make sure you're picking the\l"
	.string "right targets.$"

gText_Quest_ArtisanBalls_DidYouRunOut::
	.string "Did you run out? Here, I'll help you...$"

gText_Quest_ArtisanBalls_JustMadeThatToday::
	.string "Just made those today. Let me know how\n"
	.string "they do!$"

gText_Quest_ArtisanBalls_SoTheyAllWork::
	.string "So they all work well? Fantastic. Thank\n"
	.string "you so much for your help! Time to\l"
	.string "start reaching out and really selling\l"
	.string "them. Take this as a thanks!$"

gText_Quest_ArtisanBalls2_LookingToBuyOr::
	.string "Hey {PLAYER}! Are you here to buy, or\n"
	.string "do you wanna hear the latest news with\l"
	.string "the business?$"

gText_Quest_ArtisanBalls2_LookingToBuyActive::
	.string "Hey {PLAYER}! Are you here to buy, or\n"
	.string "do you have an update?$"

gText_Quest_ArtisanBalls2_IMadeA::
	.string "I made a small batch this morning. Want\n"
	.string "{STR_VAR_3} for ¥1300?$"

gText_Quest_ArtisanBalls2_NoWorries::
	.string "I'll be here if you change your mind.$"

gText_Quest_ArtisanBalls2_ImReadyToExpand::
	.string "Things are going well, and I think I'm\n"
	.string "ready to expand.$"

gText_Quest_ArtisanBalls2_ThatsAmazing::
	.string "That's amazing! Congrats Sergey!$"

gText_Quest_ArtisanBalls2_INeedHelp::
	.string "I need help though. There's a lot of\n"
	.string "work to do, so I'm going to need to hire\l"
	.string "people... I think I need an office\l"
	.string "manager, customer service rep, and a\l"
	.string "marketing manger. Could you help me\l"
	.string "find some people? I want to hire people\l"
	.string "that really use and understand my\l"
	.string "products. There's gotta be Trainers\l"
	.string "out there that are using my Balls,\l"
	.string "right?$"

gText_Quest_ArtisanBalls2_WowPeopleAre::
	.string "Wow! People are slowly trickling in... I\n"
	.string "think we can actually pull this off!$"

gText_Quest_ArtisanBalls2_FindingHelp::
	.string "Finding help is tough, isn't it?$"

gText_Quest_ArtisanBalls2_YoudThink::
	.string "You'd think office management and\n"
	.string "Pokémon management would be similar...$"

gText_Quest_ArtisanBalls2_NotEvenClose::
	.string "Not even close!$"

gText_Quest_ArtisanBalls2_WhereDidYouGet::
	.string "Where did you get those PokéBalls?$"

gText_Quest_ArtisanBalls2_MyGirlfriend::
	.string "My girlfriend got them for me as a\n"
	.string "present! I guess there's some craft\l"
	.string "seller making them.$"

gText_Quest_ArtisanBalls2_OfficeManagerRight::
	.string "You mentioned Office Management,\n"
	.string "right? The guy who made those balls is\l"
	.string "actually looking to hire somebody for\l"
	.string "that. You should talk to him, he's in\l"
	.string "Japantown.$"

gText_Quest_ArtisanBalls2_WaitReally::
	.string "Wait, really? I absolutely need a new\n"
	.string "gig, and that sounds amazing! Thank\l"
	.string "you so much.$"

gText_Quest_ArtisanBalls2_MyPersonalBrand::
	.string "My personal brand is the most important\n"
	.string "thing!$"

gText_Quest_ArtisanBalls2_IHopeGettingDefeated::
	.string "I hope gettind defeated doesn't hurt\n"
	.string "my brand...$"

gText_Quest_ArtisanBalls2_ISawThe::
	.string "I saw the collection on Twitter and\n"
	.string "wanted to try them out. Why?$"

gText_Quest_ArtisanBalls2_YouSaidYouWereInto::
	.string "You said you were into branding, right?\n"
	.string "The guy who made those balls is\l"
	.string "actually looking to hire somebody for\l"
	.string "that. You should talk to him, he's in\l"
	.string "Japantown.$"

gText_Quest_ArtisanBalls2_OhManWhat::
	.string "Oh man, what? I gotta get over there\n"
	.string "right now!$"

gText_Quest_ArtisanBalls2_IMissHelpingPeople::
	.string "I miss helping people. Serving is my\n"
	.string "passion!$"

gText_Quest_ArtisanBalls2_DidIHelpYou::
	.string "Did I help you today?$"

gText_Quest_ArtisanBalls2_IfYouLikeHelping::
	.string "If you like helping people, the guy who\n"
	.string "made those Balls is looking for a\l"
	.string "customer service rep. You should go to\l"
	.string "Japantown and talk to him!$"

gText_Quest_ArtisanBalls2_IMetTheVendor::
	.string "I met the vendor a local business trade\n"
	.string "show!$"

gText_Quest_ArtisanBalls2_ThatWouldBe::
	.string "That would be amazing! I'll head over\n"
	.string "there now.$"

gText_Quest_ArtisanBalls2_IThinkIHaveTheStaff::
	.string "I think I have the staff to finally\n"
	.string "expand out. It's all thanks to you. I\l"
	.string "was able to do a limited run of a new\l"
	.string "ball, and I want you to have some!$"

gText_Quest_ArtisanBalls3_WhatBallsDoYou::
	.string "What PokéBalls do you need today?$"

gText_Quest_ArtisanBalls3_ThanksAgain::
	.string "Thanks again!$"

gText_Quest_ArtisanBalls3_BusinessHasBeen::
	.string "Business has been crazy! The new staff\n"
	.string "really has been amazing, we've got a\l"
	.string "good product, and I'm doing what I love.$"

gText_Quest_ArtisanBalls3_IveBeenTalkingTo::
	.string "I've been talking to some Silph Co.\n"
	.string "executives too. They want to acquire\l"
	.string "us! I want to see if we can do a big\l"
	.string "marketing push soon so I can keep\l"
	.string "showing them growth. Could you do me\l"
	.string "one last favor? Go defeat one of the\l"
	.string "Gym Leaders in SanFran using a Pokémon\l"
	.string "in one of those Balls.$"

gText_Quest_ArtisanBalls3_CantWaitToSee::
	.string "I can't wait to see your battle!$"

gText_Quest_ArtisanBalls3_DidYouHearThat::
	.string "Did you hear that?!?!?$"

gText_Quest_ArtisanBalls3_NoButItSounds::
	.string "No, but it sounds like something good!$"

gText_Quest_ArtisanBalls3_TheyWantToAcquire::
	.string "They want to acquire us! We're getting a\n"
	.string "huge buyout, and we get to keep\l"
	.string "working at Silph as part of their new\l"
	.string "craft division! This was all thanks to\l"
	.string "you, {PLAYER}. I couldn't have asked\l"
	.string "for more. They gave us this to\l"
	.string "celebrate the acquisition, but I want\l"
	.string "you to have it.$"

gText_Quest_ArtisanBalls3_ImSoExcitedForWhat::
	.string "I'm so excited for what will come next!$"

gText_Quest_ArtisanBalls_TheDoorIsLockedBut::
	.string "The door is locked, but there is a sign\n"
	.string "on the door: This location has been\l"
	.string "closed. Please direct all questions to\l"
	.string "support at silph.co. Thank you for\l"
	.string "choosing Silph Co.!\p"
	.string "There is another note below it. Do you\n"
	.string "want to read it?$"

gText_Quest_ArtisanBalls_ToMyCustomers::
	.string "To my loyal customers,\n"
	.string "Silph laid us all off. They bought my\l"
	.string "company, took the patents, and laid us\l"
	.string "all off. I feel so... used. Thank you for\l"
	.string "your support as we grew and thank you\l"
	.string "for enjoying our products. Special\l"
	.string "thanks to {PLAYER}, who always\l"
	.string "believed in us.\p"
	.string "- Sergey$"
