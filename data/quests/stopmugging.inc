Quest_StopMugging_HideObject_Script::
	setflag FLAG_TEMP_2
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_eq Quest_StopMugging_HideObject_Script_1
	return

Quest_StopMugging_HideObject_Script_1:
	setflag FLAG_TEMP_3
	return


Quest_StopMugging_Trigger_Script::
	lock
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_StopMugging_Trigger_Script_2
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_StopMugging_Trigger_Script_4
	call Quest_StopMugging_Main_Dialogue
	return

Quest_StopMugging_Trigger_Script_2:
	release
	end

Quest_StopMugging_Trigger_Script_4:
	call Quest_StopMugging_ResumeMugging_Dialogue
	return


Quest_StopMugging_MoveIntoPlace_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_eq Quest_StopMugging_MoveIntoPlace_Script_2
Quest_StopMugging_MoveIntoPlace_Script_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_Hey, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 3
	waitmovement 4
	applymovement 3, Quest_StopMugging_WalkToPlayerA_Movement
	applymovement 4, Quest_StopMugging_WalkToPlayerB_Movement
	waitmovement 0
	return

Quest_StopMugging_MoveIntoPlace_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	goto Quest_StopMugging_MoveIntoPlace_Script_1


Quest_StopMugging_Main_Dialogue::
	startquest QUEST_STOPMUGGING
	addobject 3
	addobject 4
	addobject 2
	applymovement 3, Quest_StopMugging_WalkAwayA_Movement
	applymovement 4, Quest_StopMugging_WalkAwayA_Movement
	waitmovement 4
	msgbox gText_StopMugging_HurryItUp, MSGBOX_DEFAULT
	msgbox gText_StopMugging_OhArceusOkay, MSGBOX_DEFAULT
	msgbox gText_StopMugging_IfYouDontHurry, MSGBOX_DEFAULT
	closemessage
	call Quest_StopMugging_MoveIntoPlace_Script
	msgbox gText_StopMugging_TheHellDo, MSGBOX_DEFAULT
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_GetOutOfHere, MSGBOX_DEFAULT
	callnative ClearMugshot
	goto Quest_StopMugging_StartBattle_Script
	return


Quest_StopMugging_StartBattle_Script::
	lock
	msgbox gText_StopMugging_GuessWereGetting, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MUGGERA_MUGGERB, gText_StopMugging_Shit
	goto Quest_StopMugging_PostBattle_Dialogue
	return


Quest_StopMugging_ResumeMugging_Dialogue::
	call Quest_StopMugging_MoveIntoPlace_Script
	msgbox gText_StopMugging_YouAgain, MSGBOX_DEFAULT
	goto Quest_StopMugging_StartBattle_Script
	return


Quest_StopMugging_PostBattle_Dialogue::
	call Quest_StopMugging_HideObject_Script
	lock
	msgbox gText_StopMugging_DamnYoureScary, MSGBOX_DEFAULT
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_LeaveNow, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	applymovement 3, Quest_StopMugging_WalkAwayA_Movement
	applymovement 4, Quest_StopMugging_WalkAwayB_Movement
	waitmovement 0
	removeobject 3
	removeobject 4
	completequest QUEST_STOPMUGGING
	end


Quest_StopMugging_WalkToPlayerA_Movement:
	walk_down
	face_right
	step_end

Quest_StopMugging_WalkToPlayerB_Movement:
	walk_down
	step_end

Quest_StopMugging_WalkAwayA_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Quest_StopMugging_WalkAwayB_Movement:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_StopMugging_HurryItUp::
	.string "Hurry it up, your phone and your wallet!$"

gText_StopMugging_OhArceusOkay::
	.string "*sob* Oh Arceus okay, please don't hurt\n"
	.string "me...$"

gText_StopMugging_IfYouDontHurry::
	.string "If you don't hurry up, we're gonna have\n"
	.string "a problem.$"

gText_StopMugging_Hey::
	.string "Hey!$"

gText_StopMugging_TheHellDo::
	.string "The hell do you want?$"

gText_StopMugging_GetOutOfHere::
	.string "Get out of here! Leave them alone!$"

gText_StopMugging_GuessWereGetting::
	.string "Guess we're getting two wallets in one\n"
	.string "alley!$"

gText_StopMugging_Shit::
	.string "Shit!$"

gText_StopMugging_DamnYoureScary::
	.string "Damn, you're scary as all hell, we don't\n"
	.string "want no trouble...$"

gText_StopMugging_LeaveNow::
	.string "Leave. Now.$"

gText_StopMugging_YouAgain::
	.string "You again? Didn't we already kick your\n"
	.string "ass once?$"
