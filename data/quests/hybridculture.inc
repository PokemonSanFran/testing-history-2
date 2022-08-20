Quest_HybridCulture_HideLeader_Script::
	compare VAR_BUGSY_STATE, QUEST_1_COMPLETE
	goto_if_ne Quest_HybridCulture_HideLeader_Script_1
	return

Quest_HybridCulture_HideLeader_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_HybridCulture_CheckSubquests_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_HYBRIDCULTURE
	compare VAR_RESULT, 0
	goto_if_eq Quest_HybridCulture_CheckSubquests_Script_2
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HYBRIDCULTURE, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_HybridCulture_CheckSubquests_Script_5
Quest_HybridCulture_CheckSubquests_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HYBRIDCULTURE, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_HybridCulture_CheckSubquests_Script_8
Quest_HybridCulture_CheckSubquests_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HYBRIDCULTURE, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_HybridCulture_CheckSubquests_Script_11
Quest_HybridCulture_CheckSubquests_Script_10:
	compare VAR_TEMP_0, 3
	goto_if_eq Quest_HybridCulture_CheckSubquests_Script_14
Quest_HybridCulture_CheckSubquests_Script_13:
	return

Quest_HybridCulture_CheckSubquests_Script_2:
	return

Quest_HybridCulture_CheckSubquests_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_HybridCulture_CheckSubquests_Script_4

Quest_HybridCulture_CheckSubquests_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_HybridCulture_CheckSubquests_Script_7

Quest_HybridCulture_CheckSubquests_Script_11:
	addvar VAR_TEMP_0, 1
	goto Quest_HybridCulture_CheckSubquests_Script_10

Quest_HybridCulture_CheckSubquests_Script_14:
	questmenu QUEST_MENU_SET_REWARD, QUEST_HYBRIDCULTURE
	goto Quest_HybridCulture_CheckSubquests_Script_13


Quest_HybridCulture_Event_Script::
	lock
	call Quest_HybridCulture_CheckSubquests_Script
	returnqueststate QUEST_HYBRIDCULTURE
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_HybridCulture_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_HybridCulture_Event_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_HybridCulture_Event_Script_4
	goto Quest_HybridCulture_StartQuest_Dialogue
	return

Quest_HybridCulture_Event_Script_2:
	goto Quest_HybridCulture_Active_Dialogue
	return

Quest_HybridCulture_Event_Script_3:
	goto Quest_HybridCulture_Reward_Dialogue
	return

Quest_HybridCulture_Event_Script_4:
	goto Quest_HybridCulture_Complete_Dialogue
	return


Quest_HybridCulture_StartQuest_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_HeyThanksFor, MSGBOX_NPC
	msgbox gText_Quest_HybridCulture_IThinkINeedToLearn, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_HaveYouStarted, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_IHaventYet, MSGBOX_NPC
	msgbox gText_Quest_HybridCulture_CanYouHelp, MSGBOX_NPC
	callnative ClearMugshot
	startquest QUEST_HYBRIDCULTURE
	end


Quest_HybridCulture_Active_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_HaveYouHad, MSGBOX_NPC
	callnative ClearMugshot
	end


Quest_HybridCulture_Reward_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_OhWhatDidYouLearn, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	fadescreen FADE_TO_BLACK
	msgbox gText_Quest_HybridCulture_PlayerExplained
	closemessage
	fadescreen FADE_FROM_BLACK
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_ThankYou, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	call Quest_HybridCulture_GiveReward_Script
	completequest QUEST_HYBRIDCULTURE
	setvar VAR_BUGSY_STATE, QUEST_2_COMPLETE
	end


Quest_HybridCulture_GiveReward_Script::
	giveitem ITEM_MASTER_BALL, 1
	return


Quest_HybridCulture_Complete_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_Quest_HybridCulture_IHaveSoMuch, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	applymovement 1, Quest_HybridCulture_WalkBackIntoGym_Movement
	waitmovement 1
	opendoor 17, 6
	waitdooranim
	applymovement 1, Common_Movement_WalkUp2
	waitmovement 1
	playse SE_EXIT
	removeobject 1
	waitse
	closedoor 17, 6
	end


Quest_HybridCulture_WalkBackIntoGym_Movement:
	walk_down
	walk_right
	walk_right
	face_up
	step_end

gText_Quest_HybridCulture_HeyThanksFor::
	.string "Hey, thanks again for your help in\n"
	.string "Chinatown. That was a rough situation,\l"
	.string "but was a wake up call. That's not\l"
	.string "anything like what I want to be.$"

gText_Quest_HybridCulture_IThinkINeedToLearn::
	.string "I think I need to learn more about the\n"
	.string "culture of SanFran.$"

gText_Quest_HybridCulture_HaveYouStarted::
	.string "Have you started with just Japantown?\n"
	.string "Maybe find the best parts of your\l"
	.string "culture and see how they're\l"
	.string "represented here.$"

gText_Quest_HybridCulture_IHaventYet::
	.string "I haven't yet. But perhaps that's a\n"
	.string "good idea.$"

gText_Quest_HybridCulture_CanYouHelp::
	.string "Can you help with that? You're a\n"
	.string "traveling Trainer, so you'll see more of\l"
	.string "Japantown than I will. What are the\l"
	.string "great parts of Japantown culture?$"

gText_Quest_HybridCulture_HaveYouHad::
	.string "Have you had any luck learning about\n"
	.string "Japantown culture?$"

gText_Quest_HybridCulture_OhWhatDidYouLearn::
	.string "Oh! What did you learn?$"

gText_Quest_HybridCulture_PlayerExplained::
	.string "{PLAYER} explained what they learned\n"
	.string "about Japantown's food, traditions,\l"
	.string "and fashion.$"

gText_Quest_HybridCulture_ThankYou::
	.string "Thank you. *sniff* In a way, it is\n"
	.string "beautiful to see my country\l"
	.string "appreciated in this new way. I'm glad\l"
	.string "the people here love my culture as much\l"
	.string "I do. Please, take this!$"

gText_Quest_HybridCulture_IHaveSoMuch::
	.string "I think for now, I'll go back to my Gym.\n"
	.string "Now that you're stronger, I'd love to\l"
	.string "battle you again!$"
