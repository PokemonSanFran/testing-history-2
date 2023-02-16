CongratsYoureanAsshole_ObjectCleanUp_Script::
	call Salesforcetower_Leagueops_CheckRewardStatus_Script
	setobjectxy 9, 34, 56
	setobjectxyperm 9, 34, 56
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_UP
	setobjectxy 3, 33, 2
	setobjectxyperm 3, 33, 2
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	setobjectxy 8, 5, 2
	setobjectxyperm 8, 5, 2
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_DOWN
	return


CongratsYoureAnAsshole_Intro_Dialogue::
	compare VAR_SALESFORCETOWER_CONFERENCE_STATE, START_FALSE_TIMELINE
	goto_if_eq CongratsYoureAnAsshole_Intro_Dialogue_2
CongratsYoureAnAsshole_Intro_Dialogue_1:
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, START_FALSE_TIMELINE
	msgbox gText_CongratsYoureanAsshole_WelcomeBack, MSGBOX_NPC, SPEAKER_OAK
	msgbox gText_CongratsYoureanAsshole_YeahIWantToWork, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	msgbox gText_CongratsYoureanAsshole_WevePreparedAStatement, MSGBOX_DEFAULT, SPEAKER_OAK
	msgbox gText_CongratsYoureanAsshole_WedLikeYouTwoToSignal, MSGBOX_DEFAULT, SPEAKER_KOGA
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 9
	msgbox gText_CongratsYoureanAsshole_TheresNoTurningBack, MSGBOX_DEFAULT, SPEAKER_KOGA
	closemessage
	return

CongratsYoureAnAsshole_Intro_Dialogue_2:
	goto CongratsYoureanAsshole_FalseTimelineSplit_Script
	goto CongratsYoureAnAsshole_Intro_Dialogue_1


CongratsYoureanAsshole_FalseTimelineSplit_Script::
	faceplayer
	msgbox gText_CongratsYoureanAsshole_WereGoingToSend, MSGBOX_YESNO, SPEAKER_KOGA
	compare VAR_RESULT, NO
	goto_if_eq CongratsYoureanAsshole_FalseTimelineSplit_Script_1
	setflag FLAG_TIMELINE_FALSE
	setvar VAR_STORYLINE_STATE, STORY_START_FALSE_TIMELINE
	fadescreen FADE_TO_BLACK
	msgbox gText_CongratsYoureanAsshole_PresenceIn
	fadescreen FADE_FROM_BLACK
	msgbox gText_CongratsYoureanAsshole_ThankYouForThat, MSGBOX_DEFAULT, SPEAKER_SABRINA
	msgbox gText_CongratsYoureanAsshole_ThingsWillTake, MSGBOX_DEFAULT, SPEAKER_KOGA
	msgbox gText_CongratsYoureanAsshole_ThatsTheSpirit, MSGBOX_DEFAULT, SPEAKER_KOGA
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	call CongratsYoureanAsshole_ObjectCleanUp_Script
	fadescreen FADE_FROM_BLACK
	release
	end

CongratsYoureanAsshole_FalseTimelineSplit_Script_1:
	msgbox gText_CongratsYoureanAsshole_OfCouseIfTheres, MSGBOX_DEFAULT, SPEAKER_KOGA
	closemessage
	release
	end


CongratsYoureanAsshole_WalkTowardsPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

CongratsYoureanAsshole_WalkTowardsPlayerB:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_CongratsYoureanAsshole_WelcomeBack::
	.string "Welcome back, {PLAYER}! A good night’s\n"
	.string "sleep, I hope? Thought things over?$"

gText_CongratsYoureanAsshole_YeahIWantToWork::
	.string "Yeah. I want to work with you guys and\n"
	.string "make sure the League’s next season is\l"
	.string "as successful as possible.$"

gText_CongratsYoureanAsshole_WevePreparedAStatement::
	.string "We’ve prepared a statement reinforcing\n"
	.string "our commitment to ending TeamRocket’s\l"
	.string "operations. We want them to know we’re\l"
	.string "officially working with the police and\l"
	.string "that their days are numbered.$"

gText_CongratsYoureanAsshole_WedLikeYouTwoToSignal::
	.string "We’d like you to signal boost that\n"
	.string "statement online as soon as it’s\l"
	.string "posted. A public condemnation from the\l"
	.string "most powerful Trainer will send a\l"
	.string "strong message.$"

gText_CongratsYoureanAsshole_TheresNoTurningBack::
	.string "There’s no turning back from this- once\n"
	.string "the statement is out the region\l"
	.string "natives aren’t going to be so friendly\l"
	.string "to you. If there’s anything you need to\l"
	.string "do before sending the message, handle\l"
	.string "it now. Come back and talk to me when\l"
	.string "you’re ready.$"

gText_CongratsYoureanAsshole_WereGoingToSend::
	.string "We’re going to send this message out\n"
	.string "now. Ready?$"

gText_CongratsYoureanAsshole_OfCouseIfTheres::
	.string "Of course. If there’s anything you need\n"
	.string "to do before then, handle it now. Come\l"
	.string "back and talk to me when you’re ready.$"

gText_CongratsYoureanAsshole_PresenceIn::
	.string "TeamRocket’s presence in SanFran makes\n"
	.string "for a worse region for all. Starting\l"
	.string "today, we’ll be working with the police\l"
	.string "dept and the champion to put an end to\l"
	.string "their terrorist activities.$"

gText_CongratsYoureanAsshole_ThankYouForThat::
	.string "Thank you for that… worldwide, our\n"
	.string "message is getting positive reception,\l"
	.string "but within the region, there is still\l"
	.string "some negativity.$"

gText_CongratsYoureanAsshole_ThingsWillTake::
	.string "Things will take time.$"

gText_CongratsYoureanAsshole_ThatsTheSpirit::
	.string "That’s the spirit! Oak, Sabrina, and I all\n"
	.string "have different missions for you. Come\l"
	.string "talk to us our offices when you're\l"
	.string "ready.$"
