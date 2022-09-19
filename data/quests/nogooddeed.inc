Quest_NoGoodDeed_HideEmployee_Script::
	returnqueststate QUEST_NOGOODDEED
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_gt Quest_NoGoodDeed_HideEmployee_Script_1
	return

Quest_NoGoodDeed_HideEmployee_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_NoGoodDeed_HideRainer_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGSCOPE
	compare VAR_RESULT, 0
	goto_if_eq Quest_NoGoodDeed_HideRainer_Script_2
Quest_NoGoodDeed_HideRainer_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_NOGOODDEED
	compare VAR_RESULT, 0
	goto_if_ne Quest_NoGoodDeed_HideRainer_Script_5
Quest_NoGoodDeed_HideRainer_Script_4:
	return

Quest_NoGoodDeed_HideRainer_Script_2:
	setflag FLAG_TEMP_3
	goto Quest_NoGoodDeed_HideRainer_Script_1

Quest_NoGoodDeed_HideRainer_Script_5:
	setflag FLAG_TEMP_3
	goto Quest_NoGoodDeed_HideRainer_Script_4


Quest_NoGoodDeed_HideRainer_Hotel_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_NOGOODDEED
	compare VAR_RESULT, 0
	goto_if_eq Quest_NoGoodDeed_HideRainer_Hotel_Script_2
Quest_NoGoodDeed_HideRainer_Hotel_Script_1:
	return

Quest_NoGoodDeed_HideRainer_Hotel_Script_2:
	setflag FLAG_TEMP_3
	goto Quest_NoGoodDeed_HideRainer_Hotel_Script_1


Quest_NoGoodDeed_Rainer_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_NOGOODDEED
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_NoGoodDeed_Rainer_Interact_Script_2
	case QUEST_MENU_SET_REWARD, Quest_NoGoodDeed_Rainer_Interact_Script_3
	goto Quest_NoGoodDeed_StartQuest_Dialogue
	return

Quest_NoGoodDeed_Rainer_Interact_Script_2:
	goto Quest_NoGoodDeed_Rainer_Active_Dialogue
	return

Quest_NoGoodDeed_Rainer_Interact_Script_3:
	goto Quest_NoGoodDeed_Rainer_Reward_Dialogue
	return


Quest_NoGoodDeed_StartQuest_Dialogue::
	msgbox gText_NoGoodDeed_HeyYou
	msgbox gText_NoGoodDeed_YoureTheOne
	msgbox gText_NoGoodDeed_TheyJustKickedUs
	trainerbattle_no_intro TRAINER_LOLA_4, gText_NoGoodDeed_Heartless
	goto Quest_NoGoodDeed_PostBattle_Script
	return


Quest_NoGoodDeed_PostBattle_Script::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_OkaySlowDown
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_YouSaid
	msgbox gText_NoGoodDeed_SoTheyCame
	msgbox gText_NoGoodDeed_WithNoContact
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_ThatCantBeRight
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_IToldYouBefore
	goto Quest_NoGoodDeed_Rainer_Active_Dialogue
	return


Quest_NoGoodDeed_Rainer_Active_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_LetMeTalk
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_UhHuhIllBe
	closemessage
	release
	end


Quest_NoGoodDeed_Rainer_Reward_Dialogue::
	msgbox gText_NoGoodDeed_HeyItMeansALot
	msgbox gText_NoGoodDeed_TheyCameAndGot
	msgbox gText_NoGoodDeed_IWishIHad
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_NoDontWorry
	callnative ClearMugshot
	applymovement 15, Common_Movement_WalkUp
	waitmovement 15
	playse SE_EXIT
	removeobject 15
	return


Quest_NoGoodDeed_YCEmployee_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_NOGOODDEED
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_NoGoodDeed_YCEmployee_Interact_Script_2
	goto Quest_BuildingScope_Event_Script
	return

Quest_NoGoodDeed_YCEmployee_Interact_Script_2:
	goto Quest_NoGoodDeed_Employee_Active_Dialogue
	return


Quest_NoGoodDeed_Employee_Active_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_HeyYou
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_PlayerRight
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_DoYouRemember
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_YeahIThinkSo
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_ITalkedTo
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_WeSaid
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_YouToldMe
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_OkayOkay
	applymovement 5, Common_Movement_FaceAwayPlayer
	waitmovement 5
	msgbox gText_NoGoodDeed_HeyCanYou
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 5
	msgbox gText_NoGoodDeed_IMadeACall
	msgbox gText_NoGoodDeed_YouCanGo
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NoGoodDeed_WaitSeriously
	callnative ClearMugshot
	msgbox gText_NoGoodDeed_AsAMatter
	closemessage
	applymovement 5, Quest_NoGoodDeed_LeaveScene_Movement
	waitmovement 5
	removeobject 5
	questmenu QUEST_MENU_SET_REWARD, QUEST_NOGOODDEED
	release
	end


Quest_NoGoodDeed_LeaveScene_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

gText_NoGoodDeed_HeyYou::
	.string "$"

gText_NoGoodDeed_YoureTheOne::
	.string "$"

gText_NoGoodDeed_TheyJustKickedUs::
	.string "$"

gText_NoGoodDeed_Heartless::
	.string "$"

gText_NoGoodDeed_OkaySlowDown::
	.string "$"

gText_NoGoodDeed_YouSaid::
	.string "$"

gText_NoGoodDeed_SoTheyCame::
	.string "$"

gText_NoGoodDeed_WithNoContact::
	.string "$"

gText_NoGoodDeed_ThatCantBeRight::
	.string "$"

gText_NoGoodDeed_IToldYouBefore::
	.string "$"

gText_NoGoodDeed_LetMeTalk::
	.string "$"

gText_NoGoodDeed_UhHuhIllBe::
	.string "$"

gText_NoGoodDeed_HeyItMeansALot::
	.string "$"

gText_NoGoodDeed_TheyCameAndGot::
	.string "$"

gText_NoGoodDeed_IWishIHad::
	.string "$"

gText_NoGoodDeed_NoDontWorry::
	.string "$"

gText_NoGoodDeed_PlayerRight::
	.string "$"

gText_NoGoodDeed_DoYouRemember::
	.string "$"

gText_NoGoodDeed_YeahIThinkSo::
	.string "$"

gText_NoGoodDeed_ITalkedTo::
	.string "$"

gText_NoGoodDeed_WeSaid::
	.string "$"

gText_NoGoodDeed_YouToldMe::
	.string "$"

gText_NoGoodDeed_OkayOkay::
	.string "$"

gText_NoGoodDeed_HeyCanYou::
	.string "$"

gText_NoGoodDeed_IMadeACall::
	.string "$"

gText_NoGoodDeed_YouCanGo::
	.string "$"

gText_NoGoodDeed_WaitSeriously::
	.string "$"

gText_NoGoodDeed_AsAMatter::
	.string "$"
