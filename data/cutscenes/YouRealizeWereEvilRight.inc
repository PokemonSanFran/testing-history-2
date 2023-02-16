YouRealizeWereEvilRight_Object_Setup_Script::
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	return


YouRealizeWereEvilRight_Object_Cleanup_Script::
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	setobjectxy 9, 21, 29
	setobjectxyperm 9, 21, 29
	return


YouRealizeWereEvilRight_PhoneCall_Dialogue::
	lockall
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	msgbox gText_YouRealizeWereEvilRight_SorryToBotherYou, , SPEAKER_OAK, , PHONE_ON
	msgbox gText_YouRealizeWereEvilRight_YeahImOnMyWay, , SPEAKER_ZOEY, , PHONE_ON
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, PRE_YOU_REALIZE_WERE_EVIL_RIGHT
	warpsilent MAP_SALESFORCETOWER_LEAGUEOPS, 17, 29
	return


YouRealizeWereEvilRight_Open_Dialogue::
	lockall
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_YOU_REALIZE_WERE_EVIL_RIGHT
	setflag FLAG_ARCHER_CALL_ALCATRAZ
	setvar VAR_STORYLINE_STATE, STORY_POST_YOU_REALIZE_WERE_EVIL
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	setflag FLAG_ARCHER_CALL_ALCATRAZ
	setvar VAR_STORYLINE_STATE, STORY_POST_YOU_REALIZE_WERE_EVIL
	msgbox gText_YouRealizeWereEvilRight_WereEnamored, , SPEAKER_OAK
	msgbox gText_YouRealizeWereEvilRight_ItsBeenSuperRewarding, , SPEAKER_ZOEY
	msgbox gText_YouRealizeWereEvilRight_HoweverTheNext, , SPEAKER_OAK
	msgbox gText_YouRealizeWereEvilRight_ItWouldBeBetter, , SPEAKER_SABRINA
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_YouRealizeWereEvilRight_AreYouSayingIHave, , SPEAKER_ZOEY
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox gText_YouRealizeWereEvilRight_WereNotHere, , SPEAKER_OAK
	msgbox gText_YouRealizeWereEvilRight_WaitI, , SPEAKER_ZOEY
	closemessage
	applymovement 9, YouRealizeWereEvilRight_WalkToTable
	waitmovement 9
	setobjectxy 9, 21, 29
	setobjectxyperm 9, 21, 29
	msgbox gText_YouRealizeWereEvilRight_ExcellentTiming, , SPEAKER_OAK
	msgbox gText_YouRealizeWereEvilRight_IThinkYourKindness, , SPEAKER_KOGA
	msgbox gText_YouRealizeWereEvilRight_ShitUsedToBe, , SPEAKER_ZOEY
	msgbox gText_YouRealizeWereEvilRight_UsedToBeASmall, , SPEAKER_KOGA
	closemessage
	applymovement 3, YouRealizeWereEvilRight_MoveAwayFromTable
	waitmovement 3
	msgbox gText_YouRealizeWereEvilRight_HidingBehindTheirMask, , SPEAKER_OAK
	msgbox gText_YouRealizeWereEvilRight_WasActingInGoodFaith, , SPEAKER_OAK
	msgbox gText_YouRealizeWereEvilRight_TheLocalPolice, , SPEAKER_SABRINA
	msgbox gText_YouRealizeWereEvilRight_IKnowThis, , SPEAKER_OAK
	closemessage
	return


YouRealizeWereEvilRight_WalkToTable:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	face_left
	step_end

YouRealizeWereEvilRight_MoveAwayFromTable:
	walk_left
	walk_up
	walk_down
	walk_down
	walk_up
	face_right
	step_end

gText_YouRealizeWereEvilRight_SorryToBotherYou::
	.string "Hello {PLAYER}! Sorry to bother you,\n"
	.string "but there is a slight situation here at\l"
	.string "Salesforcetower. It's rather urgent.\l"
	.string "Please come to the second floor.$"

gText_YouRealizeWereEvilRight_YeahImOnMyWay::
	.string "Yeah, I'm on my way over!$"

gText_YouRealizeWereEvilRight_WouldYouLikeToGo::
	.string "Would you like to go to\n"
	.string "Salesforcetower?$"

gText_YouRealizeWereEvilRight_ThisWay::
	.string "This way.$"

gText_YouRealizeWereEvilRight_WereEnamored::
	.string "We're enamored with the work you're\n"
	.string "doing and that you've become a\l"
	.string "mainstay with the professional\l"
	.string "battling community.$"

gText_YouRealizeWereEvilRight_ItsBeenSuperRewarding::
	.string "It's been super rewarding!$"

gText_YouRealizeWereEvilRight_HoweverTheNext::
	.string "However, the next season of the\n"
	.string "Challenge is coming up, and we're\l"
	.string "slightly concerned with your\l"
	.string "activities and the perception that a\l"
	.string "Ycombinator sponsored Trainer is so\l"
	.string "intimately involved with the same\l"
	.string "structure that we sunset when we took\l"
	.string "over.$"

gText_YouRealizeWereEvilRight_ItWouldBeBetter::
	.string "It would be better if you found other\n"
	.string "extracurricular activities instead. A\l"
	.string "popular way to give back is\l"
	.string "volunteering at a shelter, or perhaps\l"
	.string "helping the researchers in Berkeley\l"
	.string "complete the Pokédex.$"

gText_YouRealizeWereEvilRight_AreYouSayingIHave::
	.string "Are you saying I have to stop with the\n"
	.string "project?$"

gText_YouRealizeWereEvilRight_WereNotHere::
	.string "We're not here to tell you exactly what\n"
	.string "to do. We would, however, need to\l"
	.string "strongly reconsider sponsoring a\l"
	.string "Trainer who was actively undermining\l"
	.string "our efforts to establish ourselves as\l"
	.string "the best and most legitimate route for\l"
	.string "Trainers looking to grow. We don't ever\l"
	.string "want to be in that situation, so you\l"
	.string "need to think very carefully about\l"
	.string "what projects you decide to dedicate\l"
	.string "yourself to.$"

gText_YouRealizeWereEvilRight_WaitI::
	.string "Wait… I…$"

gText_YouRealizeWereEvilRight_ExcellentTiming::
	.string "Excellent timing.$"

gText_YouRealizeWereEvilRight_IThinkYourKindness::
	.string "I think your kindness is being\n"
	.string "manipulated, {PLAYER}. Our data\l"
	.string "suggests that the very Gyms that\l"
	.string "you're turning into “community\l"
	.string "centers” are actually being used as\l"
	.string "recruitment and training hubs for\l"
	.string "TeamRocket.$"

gText_YouRealizeWereEvilRight_ShitUsedToBe::
	.string "(Shit, Archer did mention he wanted\n"
	.string "their help. Was that all a ploy?)$"

gText_YouRealizeWereEvilRight_UsedToBeASmall::
	.string "TeamRocket used to be a small problem,\n"
	.string "but they're growing increasingly\l"
	.string "violent and dangerous. For the good of\l"
	.string "the region, and our plans, we need to\l"
	.string "shut them down for good.$"

gText_YouRealizeWereEvilRight_HidingBehindTheirMask::
	.string "Giovanni is a coward. Hiding behind\n"
	.string "their mask because they know their\l"
	.string "entire operation is completely illegal…$"

gText_YouRealizeWereEvilRight_WasActingInGoodFaith::
	.string "Precisely. If TeamRocket was acting in\n"
	.string "good faith, they'd work with us, no\l"
	.string "masks, no subterfuge.$"

gText_YouRealizeWereEvilRight_TheLocalPolice::
	.string "The local police have agreed to\n"
	.string "continue to work with us to eliminate\l"
	.string "TeamRocket. {PLAYER}, as you have\l"
	.string "before, we'd like you and Bianca to work\l"
	.string "alongside us to finish them.$"

gText_YouRealizeWereEvilRight_IKnowThis::
	.string "I know this is a lot to take in at once,\n"
	.string "{PLAYER}. I think you should go back\l"
	.string "to the Compound in Presidio, take a\l"
	.string "day, and think about this. You don't\l"
	.string "want to make any career ruining\l"
	.string "decisions in haste. When you're ready\l"
	.string "to help, just come back here tomorrow.$"
