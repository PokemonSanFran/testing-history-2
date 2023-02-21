AlwaysWatchingWazowski_FloorWelcome_Script::
	lock
	goto_if_set FLAG_TEMP_2, AlwaysWatchingWazowski_FloorWelcome_Script_2
	setvar VAR_SALESFORCETOWER_PRODUCTION_STATE, STEPPED_INTO_SABRINA_ROOM
	msgbox gText_AlwaysWatchingWazowski_WelcomePlayer, MSGBOX_DEFAULT, SPEAKER_SABRINA
	releaseall
	end

AlwaysWatchingWazowski_FloorWelcome_Script_2:
	setvar VAR_SALESFORCETOWER_PRODUCTION_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	release
	end


AlwaysWatchingWazowski_MovePlayerIntoPlace_Script::
	lock
	setvar VAR_SALESFORCETOWER_PRODUCTION_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp2
	fadescreen FADE_TO_BLACK
	waitmovement OBJ_EVENT_ID_PLAYER
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 9
	TeleportCamera 9, 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp2
	fadescreen FADE_FROM_BLACK
	waitmovement OBJ_EVENT_ID_PLAYER
	playbgm MUS_MT_PYRE, FALSE
	applymovement 2, Common_Movement_FacePlayer
	goto AlwaysWatchingWazowski_Intro_Dialogue
	return


AlwaysWatchingWazowski_Intro_Dialogue::
	msgbox gText_AlwaysWatchingWazowski_IImagineAllTheScreens, MSGBOX_DEFAULT, SPEAKER_SABRINA
	compare VAR_SOMA_STATE, START_THE_GANGS_ALL_HERE
	goto_if_gt AlwaysWatchingWazowski_Intro_Dialogue_2
	msgbox gText_AlwaysWatchingWazowski_IWishYouHadVisited, MSGBOX_DEFAULT, SPEAKER_SABRINA
AlwaysWatchingWazowski_Intro_Dialogue_1:
	goto AlwaysWatchingWazowski_HowDidYouKnow_Dialogue
	return

AlwaysWatchingWazowski_Intro_Dialogue_2:
	msgbox gText_AlwaysWatchingWazowski_IWishHadPickedADifferentTime, MSGBOX_DEFAULT, SPEAKER_SABRINA
	goto AlwaysWatchingWazowski_Intro_Dialogue_1


AlwaysWatchingWazowski_HowDidYouKnow_Dialogue::
	msgbox gText_AlwaysWatchingWazowski_WaitHowDidYouKnow, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_TALK, EMOTE_CONFUSE
	msgbox gText_AlwaysWatchingWazowski_LookAroundDoYouThink, MSGBOX_DEFAULT, SPEAKER_SABRINA
	msgbox gText_AlwaysWatchingWazowski_SecurityUsedToAlsoPerform, MSGBOX_DEFAULT, SPEAKER_SABRINA
	goto AlwaysWatchingWazowski_MarketingandProduction_Dialogue
	return


AlwaysWatchingWazowski_MarketingandProduction_Dialogue::
	msgbox gText_AlwaysWatchingWazowski_OhOkayYeah, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_AlwaysWatchingWazowski_WeDevelopContent, MSGBOX_DEFAULT, SPEAKER_SABRINA
	msgbox gText_AlwaysWatchingWazowski_WhatDoYouMeanMe, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_AlwaysWatchingWazowski_YouCanSeeForYourself, MSGBOX_DEFAULT, SPEAKER_SABRINA
	closemessage
	goto AlwaysWatchingWazowski_ProgramCutscene_Script
	return


AlwaysWatchingWazowski_ProgramCutscene_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	fadescreen FADE_TO_BLACK
	msgbox gText_AlwaysWatchingWazowski_OurBiggestContentInitiative, MSGBOX_DEFAULT, SPEAKER_SABRINA
	msgbox gText_AlwaysWatchingWazowski_WhatDoYouMean, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_AlwaysWatchingWazowski_TensOfThousandsOfKids, MSGBOX_DEFAULT, SPEAKER_SABRINA
	msgbox gText_AlwaysWatchingWazowski_ToPutItSimply, MSGBOX_DEFAULT, SPEAKER_SABRINA
	msgbox gText_AlwaysWatchingWazowski_HistoricallyOurInRegion, MSGBOX_DEFAULT, SPEAKER_SABRINA
	compare VAR_PSFROUTE9_STATE, HAS_NOT_MET_ARCHER
	goto_if_gt AlwaysWatchingWazowski_ProgramCutscene_Script_2
AlwaysWatchingWazowski_ProgramCutscene_Script_1:
	closemessage
	fadescreen FADE_FROM_BLACK
	goto AlwaysWatchingWazowski_MyProductivityHasDropped_Dialogue
	return

AlwaysWatchingWazowski_ProgramCutscene_Script_2:
	msgbox gText_AlwaysWatchingWazowski_WaitHesDoingTheLeagueChallenge, MSGBOX_DEFAULT, SPEAKER_ZOEY
	goto AlwaysWatchingWazowski_ProgramCutscene_Script_1


AlwaysWatchingWazowski_MyProductivityHasDropped_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_AlwaysWatchingWazowski_IImagineThisHasBeenVery, MSGBOX_DEFAULT, SPEAKER_SABRINA
	applymovement 2, Common_Movement_FaceUp
	fadedefaultbgm
	msgbox gText_AlwaysWatchingWazowski_SorryToBugYou, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	releaseall
	end


AlwaysWatchingWazowski_IgnoringPlayer_Dialogue::
	lockall
	msgbox gText_AlwaysWatchingWazowski__IgnorePlayer, SPEAKER_MARKETING_STAFF
	closemessage
	releaseall
	end


PlayerCharDeskWalkFromLeft_Movement:
	walk_right
	face_up
	step_end

PlayerCharDeskWalkFromRight_Movement:
	walk_left
	walk_left
	face_up
	step_end

gText_AlwaysWatchingWazowski_WelcomePlayer::
	.string "Welcome {PLAYER}!$"

gText_AlwaysWatchingWazowski_IImagineAllTheScreens::
	.string "I imagine all the screens can be quite\n"
	.string "overwhelming. I never really think\l"
	.string "about how many we have until somebody\l"
	.string "new visits.$"

gText_AlwaysWatchingWazowski_IWishHadPickedADifferentTime::
	.string "I wish Oak had picked a different time\n"
	.string "to tell you to come see me. I have at\l"
	.string "least 493 more minutes of work, and\l"
	.string "don't have the 12 minutes required to\l"
	.string "appropriately entertain you...$"

gText_AlwaysWatchingWazowski_IWishYouHadVisited::
	.string "I wish you had visited Rose first. I\n"
	.string "have at least 493 more minutes of work\l"
	.string "and don't have the 12 minutes required\l"
	.string "to appropriately entertain you...$"

gText_AlwaysWatchingWazowski_WaitHowDidYouKnow::
	.string "Wait, how did you know that stuff?$"

gText_AlwaysWatchingWazowski_LookAroundDoYouThink::
	.string "Look around. Do you think there's\n"
	.string "anything in the region that I don't\l"
	.string "see?$"

gText_AlwaysWatchingWazowski_SecurityUsedToAlsoPerform::
	.string "YCombinator security used to also\n"
	.string "perform surveillance, but my team was\l"
	.string "more than efficient enough to perform\l"
	.string "that on top of their existing duties.$"

gText_AlwaysWatchingWazowski_OhOkayYeah::
	.string "...oh. Okay. Yeah, there's a lot of\n"
	.string "screens. This is Marketing and\l"
	.string "Production, right?$"

gText_AlwaysWatchingWazowski_WeDevelopContent::
	.string "We develop content across all of our\n"
	.string "social platforms and optimize the\l"
	.string "perception of our brand to the world.\l"
	.string "Although right now, our primary project\l"
	.string "is actually you.$"

gText_AlwaysWatchingWazowski_WhatDoYouMeanMe::
	.string "What do you mean, me?$"

gText_AlwaysWatchingWazowski_YouCanSeeForYourself::
	.string "You can see for yourself. Turn to your\n"
	.string "left in 3....2...1....$"

gText_AlwaysWatchingWazowski_OurBiggestContentInitiative::
	.string "Our biggest content initiative right\n"
	.string "now is broadcasting the race between\l"
	.string "all the League Challengers. My models\l"
	.string "predict that this will increase our\l"
	.string "sentiment among the professional\l"
	.string "battling community by 40%, and 88%\l"
	.string "among the casual battling communities.\l"
	.string "Never mind what it will do for your\l"
	.string "career.$"

gText_AlwaysWatchingWazowski_WhatDoYouMean::
	.string "What do you mean?$"

gText_AlwaysWatchingWazowski_TensOfThousandsOfKids::
	.string "Tens of thousands of kids at home\n"
	.string "watching you all right now. Everybody\l"
	.string "loves competition, and even more so,\l"
	.string "they love watching their favorites\l"
	.string "progress. Our inbound sponsorship\l"
	.string "requests have skyrocketed 44.15% , and\l"
	.string "the challenge just started.$"

gText_AlwaysWatchingWazowski_ToPutItSimply::
	.string "To put it simply, you're all going to be\n"
	.string "superstars.$"

gText_AlwaysWatchingWazowski_HistoricallyOurInRegion::
	.string "Historically, our in-region sentiment\n"
	.string "has been primarily negative, but even\l"
	.string "here, people want to see their\l"
	.string "hometown hero do well.$"

gText_AlwaysWatchingWazowski_WaitHesDoingTheLeagueChallenge::
	.string "(Wait, he's doing the League challenge?\n"
	.string "After all that shit talk? What a\l"
	.string "hypocrite!)$"

gText_AlwaysWatchingWazowski_IImagineThisHasBeenVery::
	.string "I imagine this has been very\n"
	.string "educational for you, {PLAYER}. But I\l"
	.string "can see my productivity has dropped\l"
	.string "14% as a result of this conversation,\l"
	.string "and I have some content that needs to\l"
	.string "be scheduled very soon.$"

gText_AlwaysWatchingWazowski_SorryToBugYou::
	.string "Sorry to bug you. I'll keep trying to put\n"
	.string "on a good show!$"

gText_AlwaysWatchingWazowski__IgnorePlayer::
	.string "...$"
