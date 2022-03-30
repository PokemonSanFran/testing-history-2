YouRealizeWereEvilRight_Object_Setup_Script::
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	setobjectxy 9, 10, 13
	setobjectxyperm 9, 10, 13
	setobjectxy 14, 9, 20
	setobjectxyperm 14, 9, 20
	setobjectxy 2, 7, 12
	setobjectxyperm 2, 7, 12
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 9, MOVEMENT_TYPE_FACE_LEFT
	return


YouRealizeWereEvilRight_Object_Cleanup_Script::
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
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


YouRealizeWereEvilRight_PhoneCall_Dialogue::
	lockall
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	addvar VAR_STORYLINE_STATE, 1
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitse
	pokenavcall YouRealizeWereEvilRight_PhoneCall_Dialogue_Text_0
	waitmessage
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_SorryToBotherYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_YeahImOnMyWay
	callnative ClearMugshot
	addvar VAR_PSFBADGUY1TOWER_2F_STATE, 1
	msgbox gText_YouRealizeWereEvilRight_WouldYouLikeToGo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq YouRealizeWereEvilRight_PhoneCall_Dialogue_1
	warpsilent MAP_PSFBADGUY1TOWER_2F, 255, 7, 14
	return

YouRealizeWereEvilRight_PhoneCall_Dialogue_1:
	closemessage
	releaseall
	end


YouRealizeWereEvilRight_Open_Dialogue::
	lockall
	addvar VAR_PSFBADGUY1TOWER_2F_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_WereEnamored
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_ItsBeenSuperRewarding
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_HoweverTheNext
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_ItWouldBeBetter
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_AreYouSayingIHave
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_WereNotHere
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_WaitI
	callnative ClearMugshot
	closemessage
	applymovement 14, YouRealizeWereEvilRight_WalkToTable
	waitmovement 0
	setobjectxy 14, 10, 15
	setobjectxyperm 14, 10, 15
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_ExcellentTiming
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_IThinkYourKindness
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_ShitUsedToBe
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_UsedToBeASmall
	callnative ClearMugshot
	closemessage
	applymovement 9, YouRealizeWereEvilRight_MoveAwayFromTable
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_HidingBehindTheirMask
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_WasActingInGoodFaith
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_TheLocalPolice
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouRealizeWereEvilRight_IKnowThis
	callnative ClearMugshot
	closemessage
	return


YouRealizeWereEvilRight_WalkToTable:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	face_left
	step_end

YouRealizeWereEvilRight_MoveAwayFromTable:
	walk_right
	walk_up
	walk_down
	walk_down
	walk_up
	face_left
	step_end

YouRealizeWereEvilRight_PhoneCall_Dialogue_Text_0:
	.string "This phone is ringing.$"

gText_YouRealizeWereEvilRight_SorryToBotherYou::
	.string "Hello {PLAYER}! Sorry to bother you,\n"
	.string "but there is a slight situation here at\l"
	.string "Psfbadguy1tower. It's rather urgent.\l"
	.string "Please come to the second floor as\l"
	.string "soon as you can.$"

gText_YouRealizeWereEvilRight_YeahImOnMyWay::
	.string "Yeah, I'm on my way over!$"

gText_YouRealizeWereEvilRight_WouldYouLikeToGo::
	.string "Would you like to go to\n"
	.string "Psfbadguy1tower?$"

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
	.string "Psfbadguy sponsored Trainer is so\l"
	.string "intimately involved with the same\l"
	.string "structure that we sunset when we took\l"
	.string "over.$"

gText_YouRealizeWereEvilRight_ItWouldBeBetter::
	.string "It would be better if you found other\n"
	.string "extracurricular activities instead. A\l"
	.string "popular way to give back is\l"
	.string "volunteering at a shelter, or perhaps\l"
	.string "helping the researchers in Psfcity11\l"
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
	.string "Psfgoodteam.$"

gText_YouRealizeWereEvilRight_ShitUsedToBe::
	.string "(Shit, Psfnativerival did mention he\n"
	.string "wanted their help. Was that all a ploy?)$"

gText_YouRealizeWereEvilRight_UsedToBeASmall::
	.string "Psfgoodteam used to be a small problem,\n"
	.string "but they're growing increasingly\l"
	.string "violent and dangerous. For the good of\l"
	.string "the region, and our plans, we need to\l"
	.string "shut them down for good.$"

gText_YouRealizeWereEvilRight_HidingBehindTheirMask::
	.string "Psfgoodboss is a coward. Hiding behind\n"
	.string "their mask because they know their\l"
	.string "entire operation is completely illegal…$"

gText_YouRealizeWereEvilRight_WasActingInGoodFaith::
	.string "Precisely. If Psfgoodteam was acting in\n"
	.string "good faith, they'd work with us, no\l"
	.string "masks, no subterfuge.$"

gText_YouRealizeWereEvilRight_TheLocalPolice::
	.string "The local police have agreed to\n"
	.string "continue to work with us to eliminate\l"
	.string "Psfgoodteam. {PLAYER}, as you have\l"
	.string "before, we'd like you and Psftransrival\l"
	.string "to work alongside us to finish them.$"

gText_YouRealizeWereEvilRight_IKnowThis::
	.string "I know this is a lot to take in at once,\n"
	.string "{PLAYER}. I think you should go back\l"
	.string "to the Compound in Psfcity3, take a\l"
	.string "day, and think about this. You don't\l"
	.string "want to make any career ruining\l"
	.string "decisions in haste. When you're ready\l"
	.string "to help, just come back here tomorrow.$"
