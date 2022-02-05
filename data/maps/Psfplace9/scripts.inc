Psfplace9_MapScripts::
	.byte 0


YouLookTired_InteractPsfbadadmin2_Script::
	lock
	applymovement 1, Common_Movement_FacePlayer
	goto YouLookTired_Intro_Dialogue
	return


YouLookTired_Trigger_Script::
	lock
	call YouLookTired_WalkToPsfbadadmin2_Script
	applymovement 1, Common_Movement_FacePlayer
	goto YouLookTired_Intro_Dialogue
	return


YouLookTired_WalkToPsfbadadmin2_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 7, YouLookTired_WalkToPsfbadadmin2_Script_3
	case 8, YouLookTired_WalkToPsfbadadmin2_Script_4
	case 9, YouLookTired_WalkToPsfbadadmin2_Script_5
	case 10, YouLookTired_WalkToPsfbadadmin2_Script_6
YouLookTired_WalkToPsfbadadmin2_Script_1:
	waitmovement 0
	return

YouLookTired_WalkToPsfbadadmin2_Script_3:
	applymovement OBJ_EVENT_ID_PLAYER, YouLookTired_WalkFrom7
	goto YouLookTired_WalkToPsfbadadmin2_Script_1

YouLookTired_WalkToPsfbadadmin2_Script_4:
	applymovement OBJ_EVENT_ID_PLAYER, YouLookTired_WalkFrom8
	goto YouLookTired_WalkToPsfbadadmin2_Script_1

YouLookTired_WalkToPsfbadadmin2_Script_5:
	applymovement OBJ_EVENT_ID_PLAYER, YouLookTired_WalkFrom9
	goto YouLookTired_WalkToPsfbadadmin2_Script_1

YouLookTired_WalkToPsfbadadmin2_Script_6:
	applymovement OBJ_EVENT_ID_PLAYER, YouLookTired_WalkFrom10
	goto YouLookTired_WalkToPsfbadadmin2_Script_1


YouLookTired_Intro_Dialogue::
	playbgm MUS_MT_PYRE, FALSE
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_SorryToInterrupt
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_YeahWhatsUp
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_GladIWasAbleToRun
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_IGuessYouDoToo
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_ChiefOperatingOfficer
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_IKeepHearingThat
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	goto YouLookTired_BadgeJudge_Script
	return


YouLookTired_BadgeJudge_Script::
	goto_if_set FLAG_BADGE05_GET, YouLookTired_BadgeJudge_Script_1
	goto YouLookTired_NoBadge_Dialogue
	return

YouLookTired_BadgeJudge_Script_1:
	special GetNumberOfBadges
	compare VAR_TEMP_0, 8
	goto_if_eq YouLookTired_BadgeJudge_Script_4
	goto YouLookTired_OnlyThisBadge_Dialogue
	return

YouLookTired_BadgeJudge_Script_4:
	goto YouLookTired_AllBadges_Dialogue
	return


YouLookTired_AllBadges_Dialogue::
	msgbox gText_YouLookTired_FormallPsfbadguy1ongratulate
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_ItsBeenAnInterestingRide
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_IImagineYoureProbably
	goto YouLookTired_AcceptInvite
	return


YouLookTired_OnlyThisBadge_Dialogue::
	msgbox gText_YouLookTired_CanBeAHandful
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_ItsBeenAnInterestingRide
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_IImagineYoureProbably
	goto YouLookTired_AcceptInvite
	return


YouLookTired_NoBadge_Dialogue::
	msgbox gText_YouLookTired_AsLongAsYouDont
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_IKnowYoureRacing
	goto YouLookTired_AcceptInvite
	return


YouLookTired_AcceptInvite::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_ItHasBeenAWhile
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_WontBeAnIssue
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_WestOfHere
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_MyHouseHas
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_ImNotReally
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_Nonsense
	goto YouLookTired_DataCollection_Dialogue
	return


YouLookTired_DataCollection_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_YouCanDoThat
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_DataIsTheMost
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouLookTired_IllSeeYouForDinner
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouLookTired_YesThanksAgain
	callnative ClearMugshot
	closemessage
	call YouLookTired_WalkAway_Script
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	setvar VAR_PSFPLACE9_STATE, 2
	releaseall
	end


YouLookTired_WalkAway_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 6
	goto_if_eq YouLookTired_WalkAway_Script_1
	applymovement 1, YouLookTired_WalkAwayFrom7
	return

YouLookTired_WalkAway_Script_1:
	applymovement 1, YouLookTired_WalkAwayFrom6
	return


YouLookTired_WalkFrom7:
	walk_up
	face_left
	step_end

YouLookTired_WalkFrom8:
	walk_up
	walk_up
	walk_left
	step_end

YouLookTired_WalkFrom9:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

YouLookTired_WalkFrom10:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

YouLookTired_WalkAwayFrom6:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

YouLookTired_WalkAwayFrom7:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_YouLookTired_SorryToInterrupt::
	.string "Sorry to interrupt - are you\n"
	.string "{PLAYER}?$"

gText_YouLookTired_YeahWhatsUp::
	.string "Yeah, what's up?$"

gText_YouLookTired_GladIWasAbleToRun::
	.string "Ah, Psfbadadmin3 was right, glad I was\n"
	.string "able to run into you. I'm Psfbadadmin2.$"

gText_YouLookTired_IGuessYouDoToo::
	.string "Psfbadadmin3... they work for\n"
	.string "Psfbadguy1, right? So I guess you do\l"
	.string "too?$"

gText_YouLookTired_ChiefOperatingOfficer::
	.string "Yes sorry, I'm the Psfbadguy1 Chief\n"
	.string "Operating Officer, and Psfbadboss's\l"
	.string "right hand. It's a pleasure to meet you,\l"
	.string "we're all very impressed with you.$"

gText_YouLookTired_IKeepHearingThat::
	.string "Yeah, I keep hearing that! It's a little\n"
	.string "overwhelming.$"

gText_YouLookTired_AsLongAsYouDont::
	.string "As long as you don't let it get to your\n"
	.string "head, you've got nothing to worry\l"
	.string "about. Take pride in your talent!$"

gText_YouLookTired_IKnowYoureRacing::
	.string "I know you're racing against the other\n"
	.string "Trainers, but I'd love to have you over\l"
	.string "to my place for dinner. I bet you\l"
	.string "haven't had a home-cooked meal in a\l"
	.string "while, what do you say? I'm very\l"
	.string "confident one dinner won't set you\l"
	.string "back terribly far.$"

gText_YouLookTired_CanBeAHandful::
	.string "So far, you're certainly living up to\n"
	.string "your title! Congratulations on\l"
	.string "defeating Psfleader5, I know they can\l"
	.string "be... a handful.$"

gText_YouLookTired_ItsBeenAnInterestingRide::
	.string "It's been an interesting ride, but I'm\n"
	.string "going to keep giving it my all. Thanks.$"

gText_YouLookTired_IImagineYoureProbably::
	.string "I imagine you're probably exhausted.\n"
	.string "Why don't you come over to my place for\l"
	.string "dinner? I bet you haven't had a\l"
	.string "home-cooked meal in a while, what do\l"
	.string "you say?$"

gText_YouLookTired_FormallPsfbadguy1ongratulate::
	.string "Well, you're certainly living up to your\n"
	.string "legend. Let me be the first to formally\l"
	.string "congratulate you on your qualification\l"
	.string "in the Championship!$"

gText_YouLookTired_ItHasBeenAWhile::
	.string "Oh! You're right, it has been a while, are\n"
	.string "you sure that's fine on such short\l"
	.string "notice?$"

gText_YouLookTired_WontBeAnIssue::
	.string "Won't be an issue at all! I'd love to\n"
	.string "really get to know the prodigy Trainer\l"
	.string "we're investing in.$"

gText_YouLookTired_WestOfHere::
	.string "I live in Psfcity3, west of here.$"

gText_YouLookTired_MyHouseHas::
	.string "My house has the teal shutters, it'll be\n"
	.string "easy to spot. Swing by later, and we'll\l"
	.string "fix up one of my favorites. Preferred\l"
	.string "varietal?$"

gText_YouLookTired_ImNotReally::
	.string "I'm not really a wine drinker, I'll just -$"

gText_YouLookTired_Nonsense::
	.string "Nonsense. I'll pull some data from\n"
	.string "Psfcompany1 and find something to\l"
	.string "suite your tastes!$"

gText_YouLookTired_YouCanDoThat::
	.string "You can do that?$"

gText_YouLookTired_DataIsTheMost::
	.string "Of course! Data is the most powerful\n"
	.string "resource in the world - Psfbadguy1 has\l"
	.string "quite the vast library available to us.$"

gText_YouLookTired_IllSeeYouForDinner::
	.string "I'll see you for dinner then?$"

gText_YouLookTired_YesThanksAgain::
	.string "Yes! Thanks again.$"