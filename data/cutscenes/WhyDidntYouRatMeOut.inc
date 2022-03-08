WhyDidntYouRatMeOut_HideObject_Script::
	setflag FLAG_HIDE_WHYDIDNTRAT_STANDS_PSFNATIVERIVAL
	return


WhyDidntYouRatMeOut_StopPlayerLeaving::
	lockall
	clearflag FLAG_HIDE_WHYDIDNTRAT_STANDS_PSFNATIVERIVAL
	addvar VAR_ROUTE119_STATE, 1
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
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	waitse
	warpsilent MAP_PSFPLACE14_STANDS, 4, 6
	return

WhyDidntYouRatMeOut_StopPlayerLeaving_2:
	applymovement 3, WhyDidntYouRatMeOut_WalkToPlayerLeft
	goto WhyDidntYouRatMeOut_StopPlayerLeaving_1


WhyDidntYouRatMeOut_ConversationInStands::
	addvar VAR_ROUTE119_STATE, 1
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
	callnative ClearMugshot
	closemessage
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
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_NoCalmDown
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
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_MyGroupIsStarting
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_OhDoYouKnowThat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_UhYeahWeMet
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_IMeantToTell
	msgbox gText_WhyDidntYouRatMeOut_WinsTheirGroup
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyDidntYouRatMeOut_YourGroupIsNext
	return


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
	.string "Psfnativerival's group!$"

gText_WhyDidntYouRatMeOut_WinsTheirGroup::
	.string "And Psftransrival wins their group,\n"
	.string "without losing a single Pokémon! What\l"
	.string "an incredible display of force from\l"
	.string "this Unovan superstar!$"

gText_WhyDidntYouRatMeOut_YourGroupIsNext::
	.string "Your group is up next! When you're\n"
	.string "ready, just walk down the stairs and\l"
	.string "talk to the security guard in front of\l"
	.string "the Stadium doors. Good luck!$"
