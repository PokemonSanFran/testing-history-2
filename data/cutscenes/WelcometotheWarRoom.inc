WelcomeToTheWarRoom_Object_Setup_Script::
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_5
	return


WelcomeToTheWarRoom_Object_Hide_Script::
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setobjectxy 3, 34, 2
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	return


WelcomeToTheWarRoom_FaceSpeakerRose::
	applymovement 2, Common_Movement_FaceUp
	applymovement 1, Common_Movement_FaceUp
	applymovement 7, Common_Movement_FaceUp
	applymovement 6, Common_Movement_FaceUp
	applymovement 3, Common_Movement_FaceUp
	applymovement 4, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerArnav::
	applymovement 2, Common_Movement_FaceRight
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	applymovement 7, Common_Movement_FaceUp
	applymovement 6, Common_Movement_FaceUp
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerOliver::
	applymovement 2, Common_Movement_WalkInPlaceFasterDown
	applymovement 1, Common_Movement_FaceLeft
	applymovement 7, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_FaceLeft
	applymovement 3, Common_Movement_FaceUp
	applymovement 4, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerChief::
	applymovement 2, Common_Movement_FaceRight
	applymovement 1, Common_Movement_FaceDown
	applymovement 7, Common_Movement_WalkInPlaceFasterLeft
	applymovement 6, Common_Movement_FaceUp
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerMayor::
	applymovement 2, Common_Movement_FaceDown
	applymovement 1, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceDown
	applymovement 6, Common_Movement_WalkInPlaceFasterLeft
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerBianca::
	applymovement 2, Common_Movement_FaceDown
	applymovement 1, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_FaceUp
	applymovement 3, Common_Movement_FaceDown
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerPlayer::
	applymovement 2, Common_Movement_FaceDown
	applymovement 1, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_FaceLeft
	applymovement 3, Common_Movement_FaceDown
	applymovement 4, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return


WelcomeToTheWarRoom_FaceSpeakerOak::
	applymovement 2, Common_Movement_FaceLeft
	applymovement 1, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_FaceUp
	applymovement 3, Common_Movement_WalkInPlaceFasterRight
	applymovement 4, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


WelcomeToTheWarRoom_ExplainSitaution_Dialogue::
	lock
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_WELCOME_TO_THE_WAR_ROOM
	setvar VAR_FERRYBUILDING_STATE, CHIEF_LEFT_WAR_ROOM
	call WelcomeToTheWarRoom_FaceSpeakerRose
	applymovement 5, WelcomeToTheWarRoom_Pace_Movement
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_GHETSIS
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
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_HellYeahWedLoveTo
	call WelcomeToTheWarRoom_FaceSpeakerPlayer
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_ImHappyToHelp
	call WelcomeToTheWarRoom_FaceSpeakerRose
	setvar VAR_MUGSHOT, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_EverybodyUnderstand
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_WeveAlreadyOutlined
	call WelcomeToTheWarRoom_FaceSpeakerBianca
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_WhyCantWeJust
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_GladToHear
	call WelcomeToTheWarRoom_FaceSpeakerBianca
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_GotItChief
	closemessage
	callnative ClearMugshot
	call WelcomeToTheWarRoom_FaceSpeakerChief
	msgbox gText_WelcomeToTheWarRoom_GreatWellStartTheOperation
	closemessage
	applymovement 7, WelcomeToTheWarRoom_ChiefLeaveRoom_Movement
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject 7
	fadescreen FADE_FROM_BLACK
	call WelcomeToTheWarRoom_FaceSpeakerMayor
	msgbox gText_WelcomeToTheWarRoom_DontPayHimNoMind
	closemessage
	applymovement 1, WelcomeToTheWarRoom_LeaveRight_Movement
	applymovement 2, WelcomeToTheWarRoom_LeaveLeft_Movement
	applymovement 5, WelcomeToTheWarRoom_RoseLeaveRoom_Movement
	applymovement 6, WelcomeToTheWarRoom_ChiefLeaveRoom_Movement
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject 6
	removeobject 5
	removeobject 1
	removeobject 2
	fadescreen FADE_FROM_BLACK
	applymovement 3, WelcomeToTheWarRoom_AddressTrainers_Movement
	applymovement 4, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 3
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_ThatsAgainYouTwo
	closemessage
	callnative ClearMugshot
	applymovement 3, WelcomeToTheWarRoom_OakLeaveRoom_Movement
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject 3
	fadescreen FADE_FROM_BLACK
	applymovement 4, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WelcomeToTheWarRoom_ImGoingToHeadOver, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WelcomeToTheWarRoom_ExplainSitaution_Dialogue_1
	closemessage
	callnative ClearMugshot
	warpsilent MAP_PSFROUTE8, 18, 90
	return

WelcomeToTheWarRoom_ExplainSitaution_Dialogue_1:
	msgbox gText_WelcomeToTheWarRoom_OkayIllMeetYou
	closemessage
	callnative ClearMugshot
	applymovement 4, WelcomeToTheWarRoom_BiancaLeaveRoom_Movement
	fadescreen FADE_TO_BLACK
	removeobject 4
	fadescreen FADE_FROM_BLACK
	release
	end


WelcomeToTheWarRoom_Pace_Movement:
	walk_left
	walk_left
	walk_right
	walk_right
	walk_left
	walk_left
	walk_right
	walk_right
	face_down
	step_end

WelcomeToTheWarRoom_ChiefLeaveRoom_Movement:
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

WelcomeToTheWarRoom_LeaveLeft_Movement:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_LeaveRight_Movement:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_AddressTrainers_Movement:
	walk_left
	walk_down
	face_right
	step_end

WelcomeToTheWarRoom_RoseLeaveRoom_Movement:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WelcomeToTheWarRoom_OakLeaveRoom_Movement:
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

WelcomeToTheWarRoom_BiancaLeaveRoom_Movement:
	walk_left
	walk_down
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
	.string "Ycombinator's “crimes against the\l"
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
