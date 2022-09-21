WelcomeToTheWarRoom_Object_Hide_Script::
	setflag FLAG_TEMP_8
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_9
	return


WelcomeToTheWarRoom_Object_Setup_Script::
	setflag FLAG_TEMP_9
	setflag FLAG_TEMP_4
	setobjectxy 3, 10, 9
	setobjectxy 4, 10, 11
	setobjectxyperm 3, 10, 9
	setobjectxyperm 4, 10, 11
	return


WelcomeToTheWarRoom_FaceSpeakerRose::
	applymovement 4, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	applymovement 13, Common_Movement_FaceDown
	applymovement 12, Common_Movement_FaceDown
	applymovement 9, Common_Movement_FaceDown
	applymovement 10, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerArnav::
	applymovement 4, Common_Movement_FaceUp
	applymovement 3, Common_Movement_WalkInPlaceFasterDown
	applymovement 13, Common_Movement_FaceUp
	applymovement 12, Common_Movement_FaceUp
	applymovement 9, Common_Movement_FaceRight
	applymovement 10, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerOliver::
	applymovement 4, Common_Movement_WalkInPlaceFasterLeft
	applymovement 3, Common_Movement_FaceUp
	applymovement 13, Common_Movement_FaceUp
	applymovement 12, Common_Movement_FaceUp
	applymovement 9, Common_Movement_FaceRight
	applymovement 10, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerChief::
	applymovement 4, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	applymovement 13, Common_Movement_WalkInPlaceFasterLeft
	applymovement 12, Common_Movement_FaceUp
	applymovement 9, Common_Movement_FaceDown
	applymovement 10, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerMayor::
	applymovement 4, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	applymovement 13, Common_Movement_FaceDown
	applymovement 12, Common_Movement_WalkInPlaceFasterLeft
	applymovement 9, Common_Movement_FaceDown
	applymovement 10, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerBianca::
	applymovement 4, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceLeft
	applymovement 13, Common_Movement_FaceLeft
	applymovement 12, Common_Movement_FaceUp
	applymovement 9, Common_Movement_FaceDown
	applymovement 10, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerPlayer::
	applymovement 4, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	applymovement 13, Common_Movement_FaceLeft
	applymovement 12, Common_Movement_FaceLeft
	applymovement 9, Common_Movement_FaceDown
	applymovement 10, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerOak::
	applymovement 4, Common_Movement_FaceLeft
	applymovement 3, Common_Movement_FaceLeft
	applymovement 13, Common_Movement_FaceUp
	applymovement 12, Common_Movement_FaceUp
	applymovement 9, Common_Movement_WalkInPlaceFasterRight
	applymovement 10, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_ExplainSitaution_Dialogue::
	lock
	addvar VAR_SALESFORCETOWER_2F_STATE, 1
	setvar VAR_ROUTE117_STATE, 1
	call WelcomeToTheWarRoom_FaceSpeakerRose
	applymovement 11, WelcomeToTheWarRoom_Pace
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_OkayEverybodyLetsHearIt
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerArnav
	msgbox gText_WelcomeToTheWarRoom_AllMajorSocialMedia
	call WelcomeToTheWarRoom_FaceSpeakerOliver
	msgbox gText_WelcomeToTheWarRoom_TheNewOwnersOfOUrAccounts
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_WeveLongTheorized
	call WelcomeToTheWarRoom_FaceSpeakerMayor
	msgbox gText_WelcomeToTheWarRoom_ThatsWhereYouKids
	call WelcomeToTheWarRoom_FaceSpeakerBianca
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_HellYeahWedLoveTo
	call WelcomeToTheWarRoom_FaceSpeakerPlayer
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_ImHappyToHelp
	call WelcomeToTheWarRoom_FaceSpeakerRose
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_EverybodyUnderstand
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_WeveAlreadyOutlined
	call WelcomeToTheWarRoom_FaceSpeakerBianca
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_WhyCantWeJust
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_GladToHear
	call WelcomeToTheWarRoom_FaceSpeakerBianca
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_GotItChief
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_GreatWellStartTheOperation
	closemessage
	applymovement 13, WelcomeToTheWarRoom_ChiefLeaveRoom
	waitmovement 0
	removeobject 13
	call WelcomeToTheWarRoom_FaceSpeakerMayor
	msgbox gText_WelcomeToTheWarRoom_DontPayHimNoMind
	closemessage
	applymovement 3, WelcomeToTheWarRoom_ReturnToDeskA
	applymovement 4, WelcomeToTheWarRoom_ReturnToDeskB
	applymovement 12, WelcomeToTheWarRoom_MayorLeaveRoom
	applymovement 11, WelcomeToTheWarRoom_RoseLeaveRoom
	waitmovement 0
	removeobject 12
	removeobject 11
	applymovement 9, WelcomeToTheWarRoom_AddressTrainers
	applymovement 10, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_ThatsAgainYouTwo
	closemessage
	callnative ClearMugshot
	applymovement 9, WelcomeToTheWarRoom_OakLeaveRoom
	waitmovement 0
	removeobject 9
	applymovement 10, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_ImGoingToHeadOver, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WelcomeToTheWarRoom_ExplainSitaution_Dialogue_1
	closemessage
	callnative ClearMugshot
	warpsilent MAP_PSFROUTE22, 255, 16, 5
	return

WelcomeToTheWarRoom_ExplainSitaution_Dialogue_1:
	msgbox gText_WelcomeToTheWarRoom_OkayIllMeetYou
	closemessage
	callnative ClearMugshot
	applymovement 10, WelcomeToTheWarRoom_BiancaLeaveRoom
	waitmovement 0
	removeobject 10
	releaseall
	end


WelcomeToTheWarRoom_Pace:
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

WelcomeToTheWarRoom_ChiefLeaveRoom:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_ReturnToDeskA:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	step_end

WelcomeToTheWarRoom_ReturnToDeskB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

WelcomeToTheWarRoom_MayorLeaveRoom:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_RoseLeaveRoom:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_AddressTrainers:
	walk_left
	walk_down
	walk_down
	walk_down
	face_right
	step_end

WelcomeToTheWarRoom_OakLeaveRoom:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_BiancaLeaveRoom:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

gText_WelcomeToTheWarRoom_OkayEverybodyLetsHearIt::
	.string "Okay everybody, let's hear it from the\n"
	.string "top.$"

gText_WelcomeToTheWarRoom_AllMajorSocialMedia::
	.string "All major social media networks were\n"
	.string "attacked this morning. This hack is\l"
	.string "wild - we've been locked out of our\l"
	.string "accounts and the administrative teams\l"
	.string "of those networks can't get us back in.$"

gText_WelcomeToTheWarRoom_TheNewOwnersOfOUrAccounts::
	.string "The new owners of our accounts have\n"
	.string "been pushing a narrative about\l"
	.string "Psfbadguy's “crimes against the\l"
	.string "region”. They're calling for everybody\l"
	.string "to boycott the League and the\l"
	.string "upcoming Championship. We've found\l"
	.string "evidence that the perpetrators are at\l"
	.string "Navalbase.$"

gText_WelcomeToTheWarRoom_WeveLongTheorized::
	.string "We've long theorized that Navalbase is\n"
	.string "TeamRocket's primary base of\l"
	.string "operations so we've got reason to\l"
	.string "believe that they're the ones behind\l"
	.string "this cyber-attack. We have\l"
	.string "authorization to raid their\l"
	.string "headquarters and are looking -$"

gText_WelcomeToTheWarRoom_ThatsWhereYouKids::
	.string "That's where you kids come in! Ya really\n"
	.string "impressed me back at Chasecenter, and\l"
	.string "we'd like you to assist us in the raid.\l"
	.string "You'll work under Chief Bill, and help us\l"
	.string "shut down those clowns once and for\l"
	.string "all.$"

gText_WelcomeToTheWarRoom_HellYeahWedLoveTo::
	.string "Hell yeah, we'd love to.$"

gText_WelcomeToTheWarRoom_ImHappyToHelp::
	.string "I'm happy to help.$"

gText_WelcomeToTheWarRoom_EverybodyUnderstand::
	.string "Everybody understand what they're\n"
	.string "doing?$"

gText_WelcomeToTheWarRoom_WeveAlreadyOutlined::
	.string "We've already outlined a battle plan.\n"
	.string "Kids, you're gonna come with me and\l"
	.string "take the ferry.$"

gText_WelcomeToTheWarRoom_WhyCantWeJust::
	.string "Why can't we just Fly over?$"

gText_WelcomeToTheWarRoom_GladToHear::
	.string "Glad to hear I'm answering to kids now!\n"
	.string "We're splitting up our force into cells\l"
	.string "to avoid detection and increase\l"
	.string "agility.$"

gText_WelcomeToTheWarRoom_GotItChief::
	.string "…got it Chief.$"

gText_WelcomeToTheWarRoom_GreatWellStartTheOperation::
	.string "Great. We'll start the operation as soon\n"
	.string "as you're ready. Meet me outside\l"
	.string "Navalbase.$"

gText_WelcomeToTheWarRoom_DontPayHimNoMind::
	.string "Don't pay him no mind, he's just a little\n"
	.string "stern. Looks like we all got jobs to do,\l"
	.string "let's get ‘er done!$"

gText_WelcomeToTheWarRoom_ThatsAgainYouTwo::
	.string "Thanks again you two. Be careful out\n"
	.string "there!$"

gText_WelcomeToTheWarRoom_ImGoingToHeadOver::
	.string "I'm going to head over to Ferrybuilding.\n"
	.string "Want to come with?$"

gText_WelcomeToTheWarRoom_OkayIllMeetYou::
	.string "Okay, I'll meet you over there.$"
