OffYouGo_Pre_ObjectSetup_Script::
	setflag FLAG_HIDE_OFFYOUGO_PSFTRANSRIVAL
	setflag FLAG_HIDE_OFFYOUGO_PSFBADADMIN
	return


OffYouGo_ObjectSetup_Script::
	clearflag FLAG_HIDE_OFFYOUGO_PSFTRANSRIVAL
	clearflag FLAG_HIDE_OFFYOUGO_PSFBADADMIN
	return


OffYouGo_ObjectCleanUp_Script::
	setflag FLAG_HIDE_OFFYOUGO_PSFBADADMIN
	return


OffYouGo_WakeUp_Dialogue::
	setvar VAR_ROUTE113_STATE, 1
	lockall
	setvar VAR_STORYLINE_STATE, 22
	playse SE_POKENAV_CALL
	waitse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_HuhHello
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_HeyWhereAreYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_YeahImInBed
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_ComeOnGetUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_WaitingForMe
	callnative ClearMugshot
	closemessage
	msgbox gText_VSGarbador_PleaseMeetMeOn
	msgbox gText_VSGarbador_IllBeRightOver
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_YeahIDidntSee
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_UghFine
	callnative ClearMugshot
	closemessage
	playse SE_POKENAV_HANG_UP
	waitse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_HowAreTheyAlways
	callnative ClearMugshot
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	end


OffYouGo_WelcomeParty_Dialogue::
	setvar VAR_ROUTE113_STATE, 2
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_WelcomeToTheParty
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_HonestlyItsFine
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_NeitherWasI
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_WellYoureBothHere
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_ThanksButWho
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_AsYesYoureNot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_SoWhereIs
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_AhYesWellTheyHave
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbador_WeirdOkay
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
	msgbox gText_VSGarbador_OhWait
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_IDoWishThey
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbador_IllHurrySo
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_GoodLuck
	callnative ClearMugshot
	closemessage
	releaseall
	end


OffYouGo_InteractPsfbadadmin::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_VSGarbador_ItMightBeAGood, MSGBOX_NPC
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

gText_VSGarbador_RingRing::
	.string "Ring ring…$"

gText_VSGarbador_HuhHello::
	.string "Huh? Hello?$"

gText_VSGarbador_HeyWhereAreYou::
	.string "Hey, where are you? Are you still\n"
	.string "asleep?$"

gText_VSGarbador_YeahImInBed::
	.string "…yeah, I'm in bed.$"

gText_VSGarbador_ComeOnGetUp::
	.string "Come on get up, didn't you see\n"
	.string "Psfbadmin's text? We're waiting for\l"
	.string "you!$"

gText_VSGarbador_WaitingForMe::
	.string "Waiting for me…? Hold on, let me read…$"

gText_VSGarbador_PleaseMeetMeOn::
	.string "Psfbadadmin: {PLAYER} and\n"
	.string "Psftransrival, please meet me on the\l"
	.string "northern side of Psfplace17. (32 mins\l"
	.string "ago)$"

gText_VSGarbador_IllBeRightOver::
	.string "Psftransrival: I'll be right over! (31\n"
	.string "mins ago)$"

gText_VSGarbador_YeahIDidntSee::
	.string "Yeah, I didn't see that. I guess I'm on\n"
	.string "my way.$"

gText_VSGarbador_UghFine::
	.string "Ugh, fine, get your ass down here!$"

gText_VSGarbador_HowAreTheyAlways::
	.string "(How are they always up so early…?)$"

gText_VSGarbador_WelcomeToTheParty::
	.string "Welcome to the party, sleepyhead.$"

gText_VSGarbador_HonestlyItsFine::
	.string "Honestly {PLAYER}, it's fine. I wasn't\n"
	.string "expecting Psftransrival to be awake so\l"
	.string "early!$"

gText_VSGarbador_NeitherWasI::
	.string "…neither was I.$"

gText_VSGarbador_WellYoureBothHere::
	.string "Well, you're both here now. As you may\n"
	.string "have guessed, the construction delays\l"
	.string "are going to delay the Championship by\l"
	.string "a few weeks. Rather than kill your\l"
	.string "momentum now, Psfelite3 has agreed to\l"
	.string "train you both, and Psfbadguy will be\l"
	.string "footing the bill.$"

gText_VSGarbador_ThanksButWho::
	.string "Thanks but - who the hell is that?$"

gText_VSGarbador_AsYesYoureNot::
	.string "Ah yes, you're not from here. Psfelite3\n"
	.string "is one of the members of the disbanded\l"
	.string "Psfregion1 Elite Four. A powerful\l"
	.string "trainer indeed, and we think this is an\l"
	.string "excellent opportunity for you both.$"

gText_VSGarbador_SoWhereIs::
	.string "So, where is this dude?$"

gText_VSGarbador_AhYesWellTheyHave::
	.string "Ah yes, well, they have… unconventional\n"
	.string "training methods. In the middle of\l"
	.string "Psfcave1, you'll find a pathway leading\l"
	.string "underground where Psfelite3 has\l"
	.string "hidden their notebook. Once you get it,\l"
	.string "you'll get your next instructions.$"

gText_VSGarbador_WeirdOkay::
	.string "Weird. Okay. Sounds easy enough,\n"
	.string "though. Let's make a race of it!$"

gText_VSGarbador_OhWait::
	.string "Oh wait!$"

gText_VSGarbador_IDoWishThey::
	.string "I do wish they'd slow down just a little…\n"
	.string "two more things, {PLAYER}. First, the\l"
	.string "training requires teamwork.\l"
	.string "Psftransrival is going to get stuck\l"
	.string "without you pretty quickly. Second,\l"
	.string "there's very little cell service in\l"
	.string "Psfcave1 and Psfcave2. And now that\l"
	.string "they're already inside, I can't message\l"
	.string "them. So can you fill them in?$"

gText_VSGarbador_IllHurrySo::
	.string "Haha, yeah. I'll hurry so they're not\n"
	.string "waiting too long!$"

gText_VSGarbador_GoodLuck::
	.string "Good luck!$"

gText_VSGarbador_ItMightBeAGood::
	.string "It might be a good idea to stock up\n"
	.string "before you go in. I know the training is\l"
	.string "extensive, but there is a town,\l"
	.string "Psfcity10, after Psfcave1.$"
