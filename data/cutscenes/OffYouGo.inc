OffYouGo_ObjectCleanUp_Script::
	setflag FLAG_TEMP_1
	return


OffYouGo_WakeUp_Dialogue::
	setvar VAR_ROUTE113_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitse
	pokenavcall OffYouGo_WakeUp_Dialogue_Text_0
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_HuhHello
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_HeyWhereAreYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_YeahImInBed
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_ComeOnGetUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_WaitingForMe
	callnative ClearMugshot
	closemessage
	msgbox gText_OffYouGo_PleaseMeetMeOn
	msgbox gText_OffYouGo_IllBeRightOver
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_YeahIDidntSee
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_UghFine
	callnative ClearMugshot
	closemessage
	playse SE_POKENAV_HANG_UP
	waitse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_HowAreTheyAlways
	callnative ClearMugshot
	closemessage
	return


OffYouGo_WelcomeParty_Dialogue::
	addvar VAR_ROUTE113_STATE, 1
	addvar VAR_ROUTE114_STATE, 1
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_WelcomeToTheParty
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_HonestlyItsFine
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_NeitherWasI
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_WellYoureBothHere
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_ThanksButWho
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_AsYesYoureNot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_SoWhereIs
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_AhYesWellTheyHave
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OffYouGo_WeirdOkay
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	applymovement 2, Common_Movement_FaceUp
	applymovement 1, OffYouGo_WalkNorth
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_OhWait
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_IDoWishThey
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OffYouGo_IllHurrySo
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_GoodLuck
	callnative ClearMugshot
	closemessage
	releaseall
	end


OffYouGo_InteractPsfbadadmin_Event_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_OffYouGo_ItMightBeAGood, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


OffYouGo_WalkNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OffYouGo_WakeUp_Dialogue_Text_0:
	.string "This phone is ringing.$"

gText_OffYouGo_RingRing::
	.string "Ring ring…$"

gText_OffYouGo_HuhHello::
	.string "Huh? Hello?$"

gText_OffYouGo_HeyWhereAreYou::
	.string "Hey, where are you? Are you still\n"
	.string "asleep?$"

gText_OffYouGo_YeahImInBed::
	.string "…yeah, I'm in bed.$"

gText_OffYouGo_ComeOnGetUp::
	.string "Come on get up, didn't you see\n"
	.string "Psfbadmin's text? We're waiting for\l"
	.string "you!$"

gText_OffYouGo_WaitingForMe::
	.string "Waiting for me…? Hold on, let me read…$"

gText_OffYouGo_PleaseMeetMeOn::
	.string "Psfbadadmin: {PLAYER} and\n"
	.string "Psftransrival, please meet me on the\l"
	.string "northern side of Psfplace17. (32 mins\l"
	.string "ago)$"

gText_OffYouGo_IllBeRightOver::
	.string "Psftransrival: I'll be right over! (31\n"
	.string "mins ago)$"

gText_OffYouGo_YeahIDidntSee::
	.string "Yeah, I didn't see that. I guess I'm on\n"
	.string "my way.$"

gText_OffYouGo_UghFine::
	.string "Ugh, fine, get your ass down here!$"

gText_OffYouGo_HowAreTheyAlways::
	.string "(How are they always up so early…?)$"

gText_OffYouGo_WelcomeToTheParty::
	.string "Welcome to the party, sleepyhead.$"

gText_OffYouGo_HonestlyItsFine::
	.string "Honestly {PLAYER}, it's fine. I wasn't\n"
	.string "expecting Psftransrival to be awake so\l"
	.string "early!$"

gText_OffYouGo_NeitherWasI::
	.string "…neither was I.$"

gText_OffYouGo_WellYoureBothHere::
	.string "Well, you're both here now. As you may\n"
	.string "have guessed, the construction delays\l"
	.string "are going to delay the Championship by\l"
	.string "a few weeks. Rather than kill your\l"
	.string "momentum now, Psfelite3 has agreed to\l"
	.string "train you both, and Psfbadguy will be\l"
	.string "footing the bill.$"

gText_OffYouGo_ThanksButWho::
	.string "Thanks but - who the hell is that?$"

gText_OffYouGo_AsYesYoureNot::
	.string "Ah yes, you're not from here. Psfelite3\n"
	.string "is one of the members of the disbanded\l"
	.string "Psfregion1 Elite Four. A powerful\l"
	.string "trainer indeed, and we think this is an\l"
	.string "excellent opportunity for you both.$"

gText_OffYouGo_SoWhereIs::
	.string "So, where is this dude?$"

gText_OffYouGo_AhYesWellTheyHave::
	.string "Ah yes, well, they have… unconventional\n"
	.string "training methods. In the middle of\l"
	.string "Psfcave1, you'll find a pathway leading\l"
	.string "underground where Psfelite3 has\l"
	.string "hidden their notebook. Once you get it,\l"
	.string "you'll get your next instructions.$"

gText_OffYouGo_WeirdOkay::
	.string "Weird. Okay. Sounds easy enough,\n"
	.string "though. Let's make a race of it!$"

gText_OffYouGo_OhWait::
	.string "Oh wait!$"

gText_OffYouGo_IDoWishThey::
	.string "I do wish they'd slow down just a little…\n"
	.string "two more things, {PLAYER}. First, the\l"
	.string "training requires teamwork.\l"
	.string "Psftransrival is going to get stuck\l"
	.string "without you pretty quickly. Second,\l"
	.string "there's very little cell service in\l"
	.string "Psfcave1 and Psfcave2. And now that\l"
	.string "they're already inside, I can't message\l"
	.string "them. So can you fill them in?$"

gText_OffYouGo_IllHurrySo::
	.string "Haha, yeah. I'll hurry so they're not\n"
	.string "waiting too long!$"

gText_OffYouGo_GoodLuck::
	.string "Good luck!$"

gText_OffYouGo_ItMightBeAGood::
	.string "It might be a good idea to stock up\n"
	.string "before you go in. I know the training is\l"
	.string "extensive, but there is a town,\l"
	.string "Psfcity10, after Psfcave1.$"
