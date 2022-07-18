CongratsYoureanAsshole_ObjectSetUp_Script::
	addobject 11
	setobjectxy 11, 9, 21
	setobjectxyperm 11, 9, 21
	return


CongratsYoureanAsshole_ObjectCleanUp_Script::
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	setflag FLAG_TEMP_9
	setobjectxy 14, 10, 15
	setobjectxyperm 14, 10, 15
	setobjectxy 9, 10, 13
	setobjectxyperm 9, 10, 13
	setobjectxy 2, 7, 12
	setobjectxyperm 2, 7, 12
	setobjectmovementtype 14, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	return


CongratsYourAssAsshole_Intro_Dialogue::
	compare VAR_SALESFORCETOWER_2F_STATE, 6
	goto_if_eq CongratsYourAssAsshole_Intro_Dialogue_2
CongratsYourAssAsshole_Intro_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_WelcomeBack, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_YeahIWantToWork
	callnative ClearMugshot
	closemessage
	call CongratsYoureanAsshole_ObjectSetUp_Script
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_WhyAreYouHere
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_WevePreparedAStatement
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_WedLikeYouTwoToSignal
	applymovement 14, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	addvar VAR_SALESFORCETOWER_2F_STATE, 1
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_TheresNoTurningBack
	callnative ClearMugshot
	closemessage
	return

CongratsYourAssAsshole_Intro_Dialogue_2:
	goto CongratsYoureanAsshole_FalseTimelineSplit_Script
	goto CongratsYourAssAsshole_Intro_Dialogue_1


CongratsYoureanAsshole_FalseTimelineSplit_Script::
	faceplayer
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_WereGoingToSend, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq CongratsYoureanAsshole_FalseTimelineSplit_Script_1
	fadescreen FADE_TO_BLACK
	msgbox gText_CongratsYoureanAsshole_PresenceIn
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_ThankYouForThat
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_ThingsWillTake
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_ThatsTheSpirit
	callnative ClearMugshot
	closemessage
	setflag FLAG_TIMELINE_FALSE
	addvar VAR_STORYLINE_STATE, 1
	return

CongratsYoureanAsshole_FalseTimelineSplit_Script_1:
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_OfCouseIfTheres
	callnative ClearMugshot
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

gText_CongratsYoureanAsshole_HellYeahThatsAwesome::
	.string "Hell yeah, that’s awesome. Welcome to\n"
	.string "the squad.$"

gText_CongratsYoureanAsshole_WhyAreYouHere::
	.string "Why are you here?$"

gText_CongratsYoureanAsshole_IHiredThem::
	.string "I hired them. Their help was invaluable\n"
	.string "in the past, and when I presented the\l"
	.string "offer, they didn’t hesitate.$"

gText_CongratsYoureanAsshole_ExcellentWeKnew::
	.string "Excellent! We knew you’d make the right\n"
	.string "choice.$"

gText_CongratsYoureanAsshole_WevePreparedAStatement::
	.string "We’ve prepared a statement reinforcing\n"
	.string "our commitment to ending TeamRocket’s\l"
	.string "operations. We want them to know we’re\l"
	.string "officially working with the police and\l"
	.string "that their days are numbered.$"

gText_CongratsYoureanAsshole_WedLikeYouTwoToSignal::
	.string "We’d like you two to signal boost that\n"
	.string "statement online as soon as it’s\l"
	.string "posted. A public condemnation from the\l"
	.string "two most powerful Trainers will send a\l"
	.string "strong message.$"

gText_CongratsYoureanAsshole_The50000Followers::
	.string "The 50,000 followers Daddy bought me\n"
	.string "are gonna love this!$"

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
	.string "talk to us when you're ready.$"
