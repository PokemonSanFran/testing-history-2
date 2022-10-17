YouHaveYourOrders_ObjectSetUp_Script::
	setobjectxy 14, 16, 28
	setobjectxyperm 14, 16, 28
	setobjectmovementtype 14, MOVEMENT_TYPE_FACE_UP
	return


YouHaveYourOrders_Assignment_Dialogue::
	compare VAR_HOW_DISAPPOINTING_STATE, 0
	goto_if_ne YouHaveYourOrders_Assignment_Dialogue_2
	setvar VAR_HOW_DISAPPOINTING_STATE, MISSION_ASSIGNED
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_AreYouSure, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_ItCantBeTougher
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_HmmGoodPoint
	callnative ClearMugshot
	closemessage
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	applymovement 14, YouHaveYourOrders_WalkToOfficeA
	compare VAR_TEMP_0, 10
	goto_if_ne YouHaveYourOrders_Assignment_Dialogue_5
	compare VAR_TEMP_1, 14
	goto_if_eq YouHaveYourOrders_Assignment_Dialogue_6
	applymovement OBJ_EVENT_ID_PLAYER, YouHaveYourOrders_WalkToOfficeB_FromDown
YouHaveYourOrders_Assignment_Dialogue_4:
	applymovement 14, YouHaveYourOrders_PaceInOffice
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_LawEnforcementHasConfirmed
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_WhyAllAtOnce
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_ThatWouldCompletelyCut
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CongratsYoureanAsshole_OhWoWYouGuys
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_CorrectEachOfUs
	compare VAR_STORYLINE_STATE, STORY_START_FALSE_TIMELINE
	goto_if_eq YouHaveYourOrders_Assignment_Dialogue_11
YouHaveYourOrders_Assignment_Dialogue_10:
	compare VAR_TEMP_0, 0
	goto_if_eq YouHaveYourOrders_Assignment_Dialogue_14
YouHaveYourOrders_Assignment_Dialogue_13:
	applymovement 14, YouHaveYourOrders_LookOutWindow
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_ThankYouAsUsual
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_IStillFeelLike
	callnative ClearMugshot
	closemessage
	applymovement 14, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_InCaseYouHavent
	callnative ClearMugshot
	closemessage
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_YouWereAGym
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_ItWasOneOfMyGreatest
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_WasThatHard
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_AtTheTimeNo
	applymovement 14, YouHaveYourOrders_LookOutWindow
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_ICouldGoShut
	callnative ClearMugshot
	msgbox gText_YouHaveYourOrders_DoYouWantTo, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_ne YouHaveYourOrders_Assignment_Dialogue_17
YouHaveYourOrders_Assignment_Dialogue_16:
	closemessage
	end

YouHaveYourOrders_Assignment_Dialogue_2:
	msgbox YouHaveYourOrders_Assignment_Dialogue_Text_0
	closemessage
	end

YouHaveYourOrders_Assignment_Dialogue_5:
	applymovement OBJ_EVENT_ID_PLAYER, YouHaveYourOrders_WalkToOfficeB_FromRight
	goto YouHaveYourOrders_Assignment_Dialogue_4

YouHaveYourOrders_Assignment_Dialogue_6:
	applymovement OBJ_EVENT_ID_PLAYER, YouHaveYourOrders_WalkToOfficeB_FromUp
	goto YouHaveYourOrders_Assignment_Dialogue_4

YouHaveYourOrders_Assignment_Dialogue_11:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_TheyInvolved
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_WeHiredThem
	goto YouHaveYourOrders_Assignment_Dialogue_10

YouHaveYourOrders_Assignment_Dialogue_14:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_WhatAbout
	setvar VAR_MUGSHOT, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouHaveYourOrders_OurIntelligenceTells
	goto YouHaveYourOrders_Assignment_Dialogue_13

YouHaveYourOrders_Assignment_Dialogue_17:
	warpsilent MAP_CHINATOWN, 255, 5, 12
	goto YouHaveYourOrders_Assignment_Dialogue_16


YouHaveYourOrders_WalkToOfficeA:
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	step_end

YouHaveYourOrders_WalkToOfficeB_FromUp:
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

YouHaveYourOrders_WalkToOfficeB_FromRight:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

YouHaveYourOrders_WalkToOfficeB_FromDown:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

YouHaveYourOrders_WalkToOfficeC:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	face_down
	step_end

YouHaveYourOrders_PaceInOffice:
	walk_left
	walk_left
	walk_right
	walk_right
	walk_left
	walk_left
	walk_right
	walk_right
	face_up
	step_end

YouHaveYourOrders_LeaveOffice:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

YouHaveYourOrders_LookOutWindow:
	face_down
	step_end

YouHaveYourOrders_Assignment_Dialogue_Text_0:
	.string "...$"

gText_YouHaveYourOrders_AreYouSure::
	.string "{PLAYER}, are you sure you're ready\n"
	.string "for this mission?$"

gText_YouHaveYourOrders_ItCantBeTougher::
	.string "It can't be tougher than any of the\n"
	.string "other ones, right?$"

gText_YouHaveYourOrders_HmmGoodPoint::
	.string "Hmm. Good point. Let's go to my office.$"

gText_YouHaveYourOrders_OohSomeAction::
	.string "Ooh, some action? Hell yeah.$"

gText_YouHaveYourOrders_LawEnforcementHasConfirmed::
	.string "Law enforcement has confirmed the old\n"
	.string "Gyms have been repurposed as\l"
	.string "TeamRocket recruitment and training\l"
	.string "centers.The city has loaned us enough\l"
	.string "officers to perform three\l"
	.string "simultaneous raids.$"

gText_YouHaveYourOrders_WhyAllAtOnce::
	.string "Why all at once?$"

gText_YouHaveYourOrders_ThatWouldCompletelyCut::
	.string "That would completely cut off their\n"
	.string "ability to escape or continue to grow.$"

gText_CongratsYoureanAsshole_OhWoWYouGuys::
	.string "Oh wow, you guys aren’t messing around.$"

gText_YouHaveYourOrders_CorrectEachOfUs::
	.string "Each of us will be leading a different\n"
	.string "raid. Bianca will go to Treasureisland,\l"
	.string "and I'll deal with Marin. {PLAYER},\l"
	.string "you'll take on Chinatown.$"

gText_YouHaveYourOrders_TheyInvolved::
	.string "Bianca? How did they get invovled?$"

gText_YouHaveYourOrders_WeHiredThem::
	.string "We hired them. Their help was invaluable\n"
	.string "in the past, and when we presented the\l"
	.string "offer, they didn’t hesitate.$"

gText_YouHaveYourOrders_WhatAbout::
	.string "What about Haightashbury?$"

gText_YouHaveYourOrders_OurIntelligenceTells::
	.string "Our intelligence tells us that we'll be\n"
	.string "able to take that one with a smaller\l"
	.string "team.$"

gText_YouHaveYourOrders_AlrightShowingWeaklings::
	.string "Alright! Showing weaklings who's boss!\n"
	.string "I'm gonna go get ready and meet up with\l"
	.string "the force.$"

gText_YouHaveYourOrders_ThankYouAsUsual::
	.string "*sigh* Thank you, as usual. I sometimes\n"
	.string "wonder who is actually benefiting from\l"
	.string "this relationship.$"

gText_YouHaveYourOrders_IStillFeelLike::
	.string "I still feel like it's me! I'll do anything\n"
	.string "to help protect what we've built.$"

gText_YouHaveYourOrders_InCaseYouHavent::
	.string "In case you haven't already heard, I\n"
	.string "used to be the leader of the Chinatown\l"
	.string "Gym.$"

gText_YouHaveYourOrders_YouWereAGym::
	.string "You were a Gym Leader?$"

gText_YouHaveYourOrders_ItWasOneOfMyGreatest::
	.string "It was one of my greatest\n"
	.string "accomplishments. But when Ycombinator\l"
	.string "came along and I saw them beginning to\l"
	.string "usher in a new age for the region, I\l"
	.string "knew I wanted to help them. I made sure\l"
	.string "I was absolutely invaluable to them,\l"
	.string "and that's how I ended up in this spot\l"
	.string "now.$"

gText_YouHaveYourOrders_WasThatHard::
	.string "Was that hard?$"

gText_YouHaveYourOrders_AtTheTimeNo::
	.string "At the time? No. I believed - I believe I\n"
	.string "did the right thing. But it is a piece of\l"
	.string "my past that I miss. I left it behind to\l"
	.string "pursue something bigger, and there's a\l"
	.string "little bit of guilt there, you know?$"

gText_YouHaveYourOrders_ICouldGoShut::
	.string "I could go shut down that Gym, but I'm a\n"
	.string "coward. I don't have the Nuggets to go\l"
	.string "and destroy what I helped create.$"

gText_YouHaveYourOrders_DoYouWantTo::
	.string "Do you want to go to Chinatown?$"
