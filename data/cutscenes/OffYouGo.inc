OffYouGo_ObjectCleanUp_Script::
	compare VAR_GOLDENGATEBRIDGE_STATE, CALLED_BY_BIANCA
	goto_if_ne OffYouGo_ObjectCleanUp_Script_2
OffYouGo_ObjectCleanUp_Script_1:
	return

OffYouGo_ObjectCleanUp_Script_2:
	setflag FLAG_TEMP_1
	goto OffYouGo_ObjectCleanUp_Script_1


OffYouGo_WarpPlayer_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 11
	goto_if_lt OffYouGo_WarpPlayer_Script_3
OffYouGo_WarpPlayer_Script_1:
	return

OffYouGo_WarpPlayer_Script_2:
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 16, 11
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	TeleportCamera 16, 11
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	fadescreen FADE_FROM_BLACK
	goto OffYouGo_WelcomeParty_Dialogue
	goto OffYouGo_WarpPlayer_Script_1

OffYouGo_WarpPlayer_Script_3:
	compare VAR_GOLDENGATEBRIDGE_STATE, POST_OFF_YOU_GO
	goto_if_lt OffYouGo_WarpPlayer_Script_2
	goto OffYouGo_WarpPlayer_Script_1


OffYouGo_WakeUp_Dialogue::
	setvar VAR_GOLDENGATEBRIDGE_STATE, CALLED_BY_BIANCA
	setvar VAR_STORYLINE_STATE, STORY_ASSIGNED_SIEBOLD_QUESTS
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitmessage
	msgbox gText_OffYouGo_HuhHello, , SPEAKER_ZOEY, , PHONE_ON
	msgbox gText_OffYouGo_HeyWhereAreYou, , SPEAKER_BIANCA, , PHONE_ON
	msgbox gText_OffYouGo_YeahImInBed, , SPEAKER_ZOEY, , PHONE_ON
	msgbox gText_OffYouGo_ComeOnGetUp, , SPEAKER_BIANCA, , PHONE_ON
	msgbox gText_OffYouGo_WaitingForMe, , SPEAKER_ZOEY, , PHONE_ON
	closemessage
	msgbox gText_OffYouGo_PleaseMeetMeOn
	msgbox gText_OffYouGo_IllBeRightOver, , PHONE_ON
	msgbox gText_OffYouGo_YeahIDidntSee, , SPEAKER_ZOEY
	msgbox gText_OffYouGo_UghFine, , SPEAKER_BIANCA
	closemessage
	playse SE_POKENAV_HANG_UP
	waitse
	msgbox gText_OffYouGo_HowAreTheyAlways, , SPEAKER_ZOEY, TAIL_THOUGHT
	closemessage
	return


OffYouGo_WelcomeParty_Dialogue::
	setvar VAR_GOLDENGATEBRIDGE_STATE, POST_OFF_YOU_GO
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, BIANCA_INSIDE_TUNNEL
	msgbox gText_OffYouGo_WelcomeToTheParty, , SPEAKER_BIANCA
	msgbox gText_OffYouGo_HonestlyItsFine, , SPEAKER_OAK
	msgbox gText_OffYouGo_NeitherWasI, , SPEAKER_ZOEY
	msgbox gText_OffYouGo_WellYoureBothHere, , SPEAKER_OAK
	closemessage
	applymovement 1, Common_Movement_FaceRight
	waitmovement 1
	msgbox gText_OffYouGo_ThanksButWho, , SPEAKER_BIANCA
	closemessage
	applymovement 2, Common_Movement_FaceLeft
	waitmovement 2
	msgbox gText_OffYouGo_AsYesYoureNot, , SPEAKER_OAK
	msgbox gText_OffYouGo_SoWhereIs, , SPEAKER_BIANCA
	msgbox gText_OffYouGo_AhYesWellTheyHave, , SPEAKER_OAK
	msgbox gText_OffYouGo_WeirdOkay, , SPEAKER_BIANCA
	closemessage
	applymovement 1, Common_Movement_FaceUp
	waitmovement 1
	applymovement 2, Common_Movement_FaceUp
	applymovement 1, OffYouGo_WalkNorth
	waitmovement 1
	playse SE_EXIT
	waitse
	removeobject 1
	msgbox gText_OffYouGo_OhWait, , SPEAKER_OAK
	closemessage
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	msgbox gText_OffYouGo_IDoWishThey, , SPEAKER_OAK
	msgbox gText_OffYouGo_IllHurrySo, , SPEAKER_ZOEY
	msgbox gText_OffYouGo_GoodLuck, , SPEAKER_OAK
	closemessage
	releaseall
	end


OffYouGo_InteractOak_Event_Script::
	lockall
	call OffYouGo_WarpPlayer_Script
	msgbox gText_OffYouGo_ItMightBeAGood, MSGBOX_NPC, SPEAKER_OAK
	closemessage
	releaseall
	end


OffYouGo_WalkNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

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
	.string "Come on get up, didn't you see Oak's\n"
	.string "text? We're waiting for you!$"

gText_OffYouGo_WaitingForMe::
	.string "Waiting for me…? Hold on, let me read…$"

gText_OffYouGo_PleaseMeetMeOn::
	.string "Oak: {PLAYER} and Bianca, please meet\n"
	.string "me on the northern side of\l"
	.string "Gldngtebridge. (32 mins ago)$"

gText_OffYouGo_IllBeRightOver::
	.string "Bianca: I'll be right over! (31 mins ago)$"

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
	.string "expecting Bianca to be awake so early!$"

gText_OffYouGo_NeitherWasI::
	.string "…neither was I.$"

gText_OffYouGo_WellYoureBothHere::
	.string "Well, you're both here now. As you may\n"
	.string "have guessed, the construction delays\l"
	.string "are going to delay the Championship by\l"
	.string "a few weeks. Rather than kill your\l"
	.string "momentum now, Siebold has agreed to\l"
	.string "train you both, and Ycombinator will be\l"
	.string "footing the bill.$"

gText_OffYouGo_ThanksButWho::
	.string "Thanks but - who the hell is that?$"

gText_OffYouGo_AsYesYoureNot::
	.string "Ah yes, you're not from here. Siebold is\n"
	.string "one of the members of the disbanded\l"
	.string "Sanfran Elite Four. A powerful trainer\l"
	.string "indeed, and we think this is an\l"
	.string "excellent opportunity for you both.$"

gText_OffYouGo_SoWhereIs::
	.string "So, where is this dude?$"

gText_OffYouGo_AhYesWellTheyHave::
	.string "Ah yes, well, they have… unconventional\n"
	.string "training methods. In the middle of\l"
	.string "Robinwilltunnel, you'll find a pathway\l"
	.string "leading underground where Siebold has\l"
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
	.string "training requires teamwork. Bianca is\l"
	.string "going to get stuck without you pretty\l"
	.string "quickly. Second, there's very little\l"
	.string "cell service in Robinwilltunnel and\l"
	.string "Muirwoods. And now that they're\l"
	.string "already inside, I can't message them.\l"
	.string "So can you fill them in?$"

gText_OffYouGo_IllHurrySo::
	.string "Haha, yeah. I'll hurry so they're not\n"
	.string "waiting too long!$"

gText_OffYouGo_GoodLuck::
	.string "Good luck!$"

gText_OffYouGo_ItMightBeAGood::
	.string "It might be a good idea to stock up\n"
	.string "before you go in. I know the training is\l"
	.string "extensive, but there is a town, Marin,\l"
	.string "after Robinwilltunnel.$"
