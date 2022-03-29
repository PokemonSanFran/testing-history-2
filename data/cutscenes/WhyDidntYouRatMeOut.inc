WhyDidntYouRatMeOut_HideObject_Script::
	setflag FLAG_TEMP_4
	return


WhyDidntYouRatMeOut_CleanUpObject_Script::
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_3
	return


WhyDidntYouRatMeOut_StopPlayerLeaving::
	lock
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	applymovement 3, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_HeyWait
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 9
	goto_if_eq WhyDidntYouRatMeOut_StopPlayerLeaving_2
	applymovement 3, WhyDidntYouRatMeOut_WalkToPlayerRight
WhyDidntYouRatMeOut_StopPlayerLeaving_1:
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_CanWeTalk
	callnative ClearMugshot
	closemessage
	playse SE_EXIT
	warpsilent MAP_PSFPLACE14_STANDS, 4, 6
	return

WhyDidntYouRatMeOut_StopPlayerLeaving_2:
	applymovement 3, WhyDidntYouRatMeOut_WalkToPlayerLeft
	goto WhyDidntYouRatMeOut_StopPlayerLeaving_1


WhyDidntYouRatMeOut_ConversationInStands::
	applymovement OBJ_EVENT_ID_PLAYER, WhyDidntYouRatMeOut_WalkSlowlyUpStairsLeft
	applymovement 1, WhyDidntYouRatMeOut_WalkSlowlyUpStairsRight
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_WhatDoYouWant
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_IDidntThinkWed
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_IsSomethingWrongWith
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_ThatsNotWhatI
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_UhHuh
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_WhenYouWalkedIn
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_WhyDidntYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_IStillHaventDecided
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_WaitShit
	closemessage
	callnative ClearMugshot
	applymovement 1, WhyDidntYouRatMeOut_WalkBackward
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_NoCalmDown
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_LookPlayer
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_NoYouLook
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_WasNiceToMe4
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_ThankYouAndImSorry
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_UhHuhLetsSeeHow
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_NoSeriouslyItMeans
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_LikeEveryOtherTime
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_YouKnowThem
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_YeahTheyreIn
	callnative ClearMugshot
	closemessage
	playse SE_POKENAV_CALL
	waitse
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_MyGroupIsStarting
	callnative ClearMugshot
	closemessage
	clearflag FLAG_TEMP_2
	addobject 2
	applymovement 1, WhyDidntYouRatMeOut_LeaveStands
	applymovement 2, WhyDidntYouRatMeOut_EnterStands
	waitmovement 0
	removeobject 1
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_OhDoYouKnowThat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_UhYeahWeMet
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_IMeantToTell
	callnative ClearMugshot
	closemessage
	playse SE_EXIT
	warpsilent MAP_PSFPLACE14_SKYBOX, 10, 3
	return


WhyDidntYouRatMeOut_LookAround::
	turnobject 2, DIR_EAST
	turnobject 4, DIR_EAST
	turnobject 6, DIR_EAST
	turnobject 8, DIR_EAST
	delay 20
	turnobject 2, DIR_SOUTH
	turnobject 4, DIR_SOUTH
	turnobject 6, DIR_SOUTH
	turnobject 8, DIR_SOUTH
	delay 20
	turnobject 1, DIR_EAST
	turnobject 3, DIR_EAST
	turnobject 5, DIR_EAST
	turnobject 7, DIR_EAST
	delay 20
	turnobject 1, DIR_SOUTH
	turnobject 3, DIR_SOUTH
	turnobject 5, DIR_SOUTH
	turnobject 7, DIR_SOUTH
	delay 20
	return


WhyDidntYouRatMeOut_WatchPsftransrivalMatches::
	lockall
	msgbox gText_WhyDidntYouRatMeOut_WinsTheirGroup
	closemessage
	call WhyDidntYouRatMeOut_LookAround
	applymovement 7, WhyDidntYouRatMeOut_WalkUpToPlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_YourGroupIsNext
	closemessage
	callnative ClearMugshot
	addvar VAR_STORYLINE_STATE, 1
	releaseall
	end


WhyDidntYouRatMeOut_WalkToPlayerLeft:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

WhyDidntYouRatMeOut_WalkToPlayerRight:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

WhyDidntYouRatMeOut_WalkSlowlyUpStairsRight:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	face_left
	step_end

WhyDidntYouRatMeOut_WalkSlowlyUpStairsLeft:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	face_right
	step_end

WhyDidntYouRatMeOut_WalkBackward:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

WhyDidntYouRatMeOut_LeaveStands:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WhyDidntYouRatMeOut_EnterStands:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	face_left
	step_end

WhyDidntYouRatMeOut_WalkUpToPlayer:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

gText_WhyDidntYouRatMeOut_HeyWait::
	.string "Hey, {PLAYER}, wait.$"

gText_WhyDidntYouRatMeOut_CanWeTalk::
	.string "Can we talk for a second?$"

gText_WhyDidntYouRatMeOut_WhatDoYouWant::
	.string "What do you want?$"

gText_WhyDidntYouRatMeOut_IDidntThinkWed::
	.string "I didn't think we'd see each other here\n"
	.string "today.$"

gText_WhyDidntYouRatMeOut_IsSomethingWrongWith::
	.string "Is something wrong with your brain\n"
	.string "where you have to insult me every\l"
	.string "chance you get? I'm a better Trainer\l"
	.string "than you, of course I'm here.$"

gText_WhyDidntYouRatMeOut_ThatsNotWhatI::
	.string "That's not what I meant! ...I don't know\n"
	.string "what I meant.$"

gText_WhyDidntYouRatMeOut_UhHuh::
	.string "Uh huh.$"

gText_WhyDidntYouRatMeOut_WhenYouWalkedIn::
	.string "When you walked in, I was actually just\n"
	.string "going to bail. Totally thought you were\l"
	.string "going to report me the first shot you\l"
	.string "got.$"

gText_WhyDidntYouRatMeOut_WhyDidntYou::
	.string "Why didn't you?$"

gText_WhyDidntYouRatMeOut_IStillHaventDecided::
	.string "I still haven't decided that I'm not.$"

gText_WhyDidntYouRatMeOut_WaitShit::
	.string "Wait shit -$"

gText_WhyDidntYouRatMeOut_NoCalmDown::
	.string "No, calm down. It's just... this is your\n"
	.string "home. And you obviously care about it.\l"
	.string "And I think that's what gives me pause\l"
	.string "with Psfgoodteam. I see people trying\l"
	.string "to do good things, and trying to help\l"
	.string "people... and then I see Psfgoodteam\l"
	.string "with all their bullshit, and it makes me\l"
	.string "wonder “How can they possibly support\l"
	.string "that?”$"

gText_WhyDidntYouRatMeOut_LookPlayer::
	.string "Look {PLAYER} -$"

gText_WhyDidntYouRatMeOut_NoYouLook::
	.string "No, you look. I think you feel like you\n"
	.string "need to fight here. I'm just here for\l"
	.string "me. And... I don't think it's my place to\l"
	.string "take that from you. Not like that.$"

gText_WhyDidntYouRatMeOut_WasNiceToMe4::
	.string "(Psfgoodadmin and Psfnativerival...\n"
	.string "even Psfgoodboss was nice to me. What\l"
	.string "am I missing?)$"

gText_WhyDidntYouRatMeOut_ThankYouAndImSorry::
	.string "...Thank you. And I'm sorry I've been\n"
	.string "such an ass to you. You don't deserve\l"
	.string "that.$"

gText_WhyDidntYouRatMeOut_UhHuhLetsSeeHow::
	.string "Uh huh. Let's see how long this lasts.$"

gText_WhyDidntYouRatMeOut_NoSeriouslyItMeans::
	.string "No seriously, it means a lot... but I still\n"
	.string "have to crush you in the Championship.$"

gText_WhyDidntYouRatMeOut_LikeEveryOtherTime::
	.string "Like every other time you've beaten me,\n"
	.string "right. Besides, we're not going to meet\l"
	.string "until the Finals. You're not even going\l"
	.string "to make it through Psftransrival!$"

gText_WhyDidntYouRatMeOut_YouKnowThem::
	.string "You know them?$"

gText_WhyDidntYouRatMeOut_YeahTheyreIn::
	.string "Yeah, they're in the program with me.\n"
	.string "Insanely talented, and super smart.\l"
	.string "Good luck.$"

gText_WhyDidntYouRatMeOut_MyGroupIsStarting::
	.string "My group is starting soon. Later,\n"
	.string "cheater.$"

gText_WhyDidntYouRatMeOut_OhDoYouKnowThat::
	.string "Oh, do you know that Trainer,\n"
	.string "{PLAYER}?$"

gText_WhyDidntYouRatMeOut_UhYeahWeMet::
	.string "Uh… yeah, we met a few times.$"

gText_WhyDidntYouRatMeOut_IMeantToTell::
	.string "I meant to tell you earlier - the\n"
	.string "Psfbadguy executives have a fully\l"
	.string "catered skybox to watch the\l"
	.string "Championship. We're about to watch\l"
	.string "Psftransrival's group!$"

gText_WhyDidntYouRatMeOut_WinsTheirGroup::
	.string "And Psftransrival wins their group,\n"
	.string "without losing a single Pokémon! What\l"
	.string "an incredible display of force from\l"
	.string "this Unovan superstar!$"

gText_WhyDidntYouRatMeOut_YourGroupIsNext::
	.string "Your group is up next! Head through the\n"
	.string "locker room and you'll reach the arena.\l"
	.string "Good luck!$"
