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
	returnqueststate QUEST_NOGOODDEED
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_gt Quest_NoGoodDeed_HideRainer_Script_5
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
	msgbox gText_NoGoodDeed_HeyYou, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_YoureTheOne, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_TheyJustKickedUs, , SPEAKER_RAINER
	trainerbattle_no_intro TRAINER_LOLA_4, gText_NoGoodDeed_Heartless
	goto Quest_NoGoodDeed_PostBattle_Script
	return


Quest_NoGoodDeed_PostBattle_Script::
	msgbox gText_NoGoodDeed_OkaySlowDown, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_YouSaid, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_SoTheyCame, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_WithNoContact, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_ThatCantBeRight, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_IToldYouBefore, , SPEAKER_RAINER
	startquest QUEST_NOGOODDEED
	goto Quest_NoGoodDeed_Rainer_Active_Dialogue
	return


Quest_NoGoodDeed_Rainer_Active_Dialogue::
	msgbox gText_NoGoodDeed_LetMeTalk, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_UhHuhIllBe, , SPEAKER_RAINER
	closemessage
	release
	end


Quest_NoGoodDeed_Rainer_Reward_Dialogue::
	msgbox gText_NoGoodDeed_HeyItMeansALot, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_TheyCameAndGot, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_IWishIHad, , SPEAKER_RAINER
	msgbox gText_NoGoodDeed_NoDontWorry, , SPEAKER_ZOEY
	applymovement 15, Common_Movement_WalkUp
	waitmovement 15
	playse SE_EXIT
	removeobject 15
	completequest QUEST_NOGOODDEED
	release
	end


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
	msgbox gText_NoGoodDeed_HeyYou, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_PlayerRight, SPEAKER_YCOMBINATOR_STAFF
	msgbox gText_NoGoodDeed_DoYouRemember, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_YeahIThinkSo, , SPEAKER_YCOMBINATOR_STAFF
	msgbox gText_NoGoodDeed_ITalkedTo, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_WeSaid, , SPEAKER_YCOMBINATOR_STAFF
	msgbox gText_NoGoodDeed_YouToldMe, , SPEAKER_ZOEY, , EMOTE_ANGRY
	msgbox gText_NoGoodDeed_OkayOkay, , SPEAKER_YCOMBINATOR_STAFF
	applymovement 5, Common_Movement_FaceAwayPlayer
	waitmovement 5
	msgbox gText_NoGoodDeed_HeyCanYou, SPEAKER_YCOMBINATOR_STAFF, , , PHONE_ON
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 5
	msgbox gText_NoGoodDeed_IMadeACall, , SPEAKER_YCOMBINATOR_STAFF
	msgbox gText_NoGoodDeed_YouCanGo, , SPEAKER_YCOMBINATOR_STAFF
	msgbox gText_NoGoodDeed_WaitSeriously, , SPEAKER_ZOEY
	msgbox gText_NoGoodDeed_AsAMatter, , SPEAKER_YCOMBINATOR_STAFF
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
	.string "Hey! You!$"

gText_NoGoodDeed_YoureTheOne::
	.string "youre that trainer that helped them\n"
	.string "kick us out of our place$"

gText_NoGoodDeed_TheyJustKickedUs::
	.string "they told us to kick rocks,\n"
	.string "misunderstanding my ass$"

gText_NoGoodDeed_Heartless::
	.string "they're heartless and you're no better$"

gText_NoGoodDeed_OkaySlowDown::
	.string "okay slow down$"

gText_NoGoodDeed_YouSaid::
	.string "you said they would helpm us relocate,\n"
	.string "that they wouldn't just put us out$"

gText_NoGoodDeed_SoTheyCame::
	.string "so they came, helped us out, plopped us\n"
	.string "in oakland and that was it$"

gText_NoGoodDeed_WithNoContact::
	.string "no contact no nothing, just back on the\n"
	.string "streets$"

gText_NoGoodDeed_ThatCantBeRight::
	.string "that can't be right...$"

gText_NoGoodDeed_IToldYouBefore::
	.string "i told you before, theyre all monsters$"

gText_NoGoodDeed_LetMeTalk::
	.string "let me talk to them$"

gText_NoGoodDeed_UhHuhIllBe::
	.string "uh huh. i'll be here. waiting. on the\n"
	.string "streets, where they want us.$"

gText_NoGoodDeed_HeyItMeansALot::
	.string "hey it means a lot that you made this\n"
	.string "right$"

gText_NoGoodDeed_TheyCameAndGot::
	.string "they did one better and got a room in\n"
	.string "here. there's a whole program they\l"
	.string "hooked up and everything to help us to\l"
	.string "something more stable$"

gText_NoGoodDeed_IWishIHad::
	.string "i wish i had something to give$"

gText_NoGoodDeed_NoDontWorry::
	.string "no dont worry about it$"

gText_NoGoodDeed_PlayerRight::
	.string "{PLAYER}, right?$"

gText_NoGoodDeed_DoYouRemember::
	.string "do you remember that building in town\n"
	.string "you wanted to revamp, but you had to\l"
	.string "empty the house first?$"

gText_NoGoodDeed_YeahIThinkSo::
	.string "yeah i think so$"

gText_NoGoodDeed_ITalkedTo::
	.string "i talked to those people that you\n"
	.string "thought were pokemon. you just\l"
	.string "dropped them off on th street? that\l"
	.string "wasn't the deal.$"

gText_NoGoodDeed_WeSaid::
	.string "we said we'd do what....?$"

gText_NoGoodDeed_YouToldMe::
	.string "you told me you'd help them out, you\n"
	.string "didn't want anybody to be put out$"

gText_NoGoodDeed_OkayOkay::
	.string "okay okay hold on$"

gText_NoGoodDeed_HeyCanYou::
	.string "hey can you do me a favor...$"

gText_NoGoodDeed_IMadeACall::
	.string "i made a call. we're gonna get them a\n"
	.string "room in Tenderloin.$"

gText_NoGoodDeed_YouCanGo::
	.string "you can go to Tenderloin right now, they\n"
	.string "should outside the hotel, you can see\l"
	.string "for yourself.$"

gText_NoGoodDeed_WaitSeriously::
	.string "wait seriously?$"

gText_NoGoodDeed_AsAMatter::
	.string "as a matter of fact, I might head over\n"
	.string "there too...$"
