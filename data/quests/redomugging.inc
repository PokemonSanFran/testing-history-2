Quest_Redomugging_Hide_Victim_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_eq Quest_Redomugging_Hide_Victim_Script_2
Quest_Redomugging_Hide_Victim_Script_1:
	return

Quest_Redomugging_Hide_Victim_Script_2:
	setflag FLAG_TEMP_1
	goto Quest_Redomugging_Hide_Victim_Script_1


Quest_Redomugging_Hide_Muggers_Script::
	setvar VAR_TEMP_0, 0
	compare VAR_ALCATRAZ_STATE, PRE_SPEECHSPEECH
	goto_if_gt Quest_Redomugging_Hide_Muggers_Script_2
Quest_Redomugging_Hide_Muggers_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_Redomugging_Hide_Muggers_Script_5
Quest_Redomugging_Hide_Muggers_Script_4:
	compare VAR_TEMP_0, 2
	goto_if_ne Quest_Redomugging_Hide_Muggers_Script_8
Quest_Redomugging_Hide_Muggers_Script_7:
	return

Quest_Redomugging_Hide_Muggers_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Redomugging_Hide_Muggers_Script_1

Quest_Redomugging_Hide_Muggers_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Redomugging_Hide_Muggers_Script_4

Quest_Redomugging_Hide_Muggers_Script_8:
	setflag FLAG_TEMP_3
	goto Quest_Redomugging_Hide_Muggers_Script_7


Quest_Redomugging_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_REDOMUGGING
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_Redomugging_Interact_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_Redomugging_Interact_Script_4
	case QUEST_MENU_SET_REWARD, Quest_Redomugging_Interact_Script_5
	call Quest_Redomugging_StartQuest_Dialogue
Quest_Redomugging_Interact_Script_1:
	release
	end

Quest_Redomugging_Interact_Script_3:
	call Quest_Redomugging_Active_Dialogue
	goto Quest_Redomugging_Interact_Script_1

Quest_Redomugging_Interact_Script_4:
	call Quest_Redomugging_Completed_Dialogue
	goto Quest_Redomugging_Interact_Script_1

Quest_Redomugging_Interact_Script_5:
	call Quest_Redomugging_Reward_Dialogue
	goto Quest_Redomugging_Interact_Script_1


Quest_Redomugging_StartQuest_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_WaitArentYou
	callnative ClearMugshot
	msgbox gText_Redomugging_OhHellNot
	callnative DrawMugshot
	msgbox gText_Redomugging_WaitDidIPick
	callnative ClearMugshot
	msgbox gText_Redomugging_NahWereStill
	callnative DrawMugshot
	msgbox gText_Redomugging_SinceWhenDo
	callnative ClearMugshot
	msgbox gText_Redomugging_ThePersonWe
	msgbox gText_Redomugging_WeCaughtThem
	msgbox gText_Redomugging_YeahWeWere
	callnative DrawMugshot
	msgbox gText_Redomugging_FramingYouGuys
	callnative ClearMugshot
	msgbox gText_Redomugging_ExactlyWeCant
	callnative DrawMugshot
	msgbox gText_Redomugging_IsItToo
	callnative ClearMugshot
	msgbox gText_Redomugging_MaybeNot
	msgbox gText_Redomugging_MaybeHeadDownTo
	closemessage
	startquest QUEST_REDOMUGGING
	return


Quest_Redomugging_Active_Dialogue::
	msgbox gText_Redomugging_AnyLuck, MSGBOX_NPC
	return


Quest_Redomugging_Interact_Victim_Script::
	lock
	returnqueststate QUEST_REDOMUGGING
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_Redomugging_Interact_Victim_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_Redomugging_Interact_Victim_Script_4
	call Quest_Redomugging_TooBusy_Dialogue
Quest_Redomugging_Interact_Victim_Script_1:
	closemessage
	release
	end

Quest_Redomugging_Interact_Victim_Script_3:
	call Quest_Redomugging_StealPhone_Dialogue
	goto Quest_Redomugging_Interact_Victim_Script_1

Quest_Redomugging_Interact_Victim_Script_4:
	call Quest_Redomugging_MissingPhone_Dialogue
	goto Quest_Redomugging_Interact_Victim_Script_1


Quest_Redomugging_TooBusy_Dialogue::
	msgbox gText_Redomugging_Sorry
	return


Quest_Redomugging_StealPhone_Dialogue::
	faceplayer
	msgbox gText_Redomugging_HeyThereHow
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox gText_Redomugging_ChampionPlayer
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_YeahThatWasMe
	callnative ClearMugshot
	msgbox gText_Redomugging_WhatBringsYou
	callnative DrawMugshot
	msgbox gText_Redomugging_UhIWanted
	callnative CleaMugshot
	msgbox gText_Redomugging_WowYouReallyAre
	msgbox gText_Redomugging_WhileYoureHere
	closemessage
	fadescreen FADE_TO_BLACK
	delay 120
	setobjectxy OBJ_EVENT_ID_PLAYER, 12, 15
	TeleportCamera 12, 15
	fadescreen FADE_FROM_BLACK
	msgbox gText_Redomugging_OhManThisIsGreat
	closemessage
	applymovement 3, Quest_Redomugging_LeaveRoom_Movement
	dofieldeffectsparkle 12, 14, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	waitmovement 3
	removeobject 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_OkayGottaGrab
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	giveitem ITEM_FAME_CHECKER
	questmenu QUEST_MENU_SET_REWARD, QUEST_REDOMUGGING
	return


Quest_Redomugging_SpottedByReporter_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_REDOMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_Redomugging_SpottedByReporter_Script_2
Quest_Redomugging_SpottedByReporter_Script_1:
	release
	end

Quest_Redomugging_SpottedByReporter_Script_2:
	lock
	faceplayer
	msgbox gText_Redomugging_HeyWerentYouMid
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	setobjectxy OBJ_EVENT_ID_PLAYER, 12, 15
	TeleportCamera 12, 15
	fadescreen FADE_FROM_BLACK
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_IGottaGet
	callnative ClearMugshot
	goto Quest_Redomugging_SpottedByReporter_Script_1


Quest_Redomugging_MissingPhone_Dialogue::
	msgbox gText_Redomugging_HeyYouDisappeared, MSGBOX_NPC
	return


Quest_Redomugging_Reward_Dialogue::
	msgbox gText_Redomugging_YouDidAwesome
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_Thanks
	callnative ClearMugshot
	msgbox gText_Redomugging_WellTakeThat
	closemessage
	msgbox gText_Redomugging_PlayerGave, MSGBOX_AUTOCLOSE
	removeitem ITEM_FAME_CHECKER
	msgbox gText_Redomugging_AwesomeWellGive
	closemessage
	applymovement 14, Quest_Redomugging_WalkOffScreen_Movement
	completequest QUEST_REDOMUGGING
	waitmovement 14
	removeobject 14
	return


Quest_Redomugging_Completed_Dialogue::
	msgbox gText_Redomugging_EvenBetterThan, MSGBOX_NPC
	return


Quest_Redomugging_WalkOffScreen_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_Redomugging_WaitArentYou::
	.string "$"

gText_Redomugging_OhHellNot::
	.string "$"

gText_Redomugging_WaitDidIPick::
	.string "$"

gText_Redomugging_NahWereStill::
	.string "$"

gText_Redomugging_SinceWhenDo::
	.string "$"

gText_Redomugging_ThePersonWe::
	.string "$"

gText_Redomugging_WeCaughtThem::
	.string "$"

gText_Redomugging_YeahWeWere::
	.string "$"

gText_Redomugging_FramingYouGuys::
	.string "$"

gText_Redomugging_ExactlyWeCant::
	.string "$"

gText_Redomugging_IsItToo::
	.string "$"

gText_Redomugging_MaybeNot::
	.string "$"

gText_Redomugging_MaybeHeadDownTo::
	.string "$"

gText_Redomugging_AnyLuck::
	.string "$"

gText_Redomugging_YouDidAwesome::
	.string "$"

gText_Redomugging_Thanks::
	.string "$"

gText_Redomugging_WellTakeThat::
	.string "$"

gText_Redomugging_PlayerGave::
	.string "$"

gText_Redomugging_AwesomeWellGive::
	.string "$"

gText_Redomugging_EvenBetterThan::
	.string "$"
