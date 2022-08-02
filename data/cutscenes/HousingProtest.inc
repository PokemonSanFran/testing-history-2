HousingProtest_ObjectSetUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	return


HousingProtest_PostSave_ObjectSetUp_Script::
	setobjectxyperm 12, 1, 18
	setobjectxyperm 10, 1, 20
	setobjectxyperm 11, 2, 20
	setflag FLAG_TEMP_4
	return


HousingProtest_CleanUp_Landlord_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	clearflag FLAG_TEMP_4
	return


HousingProtest_CleanUp_Script::
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 6, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 5
	removeobject 7
	removeobject 8
	removeobject 9
	return


HousingProtest_StartChanting_Dialogue::
	locktarget
	msgbox gText_HousingProtest_RichAndRude
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox gText_HousingProtest_YoureNoGood
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_EverybodySoAngry
	callnative ClearMugshot
	msgbox gText_HousingProtest_ArentGoingToStand
	msgbox gText_HousingProtest_CantKeepPushing
	msgbox gText_HousingProtest_DeserveToLive
	closemessage
	goto HousingProtest_LandlordWalkOutside_Script
	return


HousingProtest_MovePlayerIntoPosition::
	locktarget
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 6, HousingProtest_MovePlayerIntoPosition_3
	case 7, HousingProtest_MovePlayerIntoPosition_4
	case 8, HousingProtest_MovePlayerIntoPosition_5
	case 9, HousingProtest_MovePlayerIntoPosition_6
HousingProtest_MovePlayerIntoPosition_1:
	waitmovement 0
	checktrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_1
	goto_if 1, HousingProtest_MovePlayerIntoPosition_7
	return

HousingProtest_MovePlayerIntoPosition_3:
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_WalkPlayer1Left
	goto HousingProtest_MovePlayerIntoPosition_1

HousingProtest_MovePlayerIntoPosition_4:
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_WalkPlayer2Left
	goto HousingProtest_MovePlayerIntoPosition_1

HousingProtest_MovePlayerIntoPosition_5:
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_WalkPlayer3Left
	goto HousingProtest_MovePlayerIntoPosition_1

HousingProtest_MovePlayerIntoPosition_6:
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_WalkPlayer4Left
	goto HousingProtest_MovePlayerIntoPosition_1

HousingProtest_MovePlayerIntoPosition_7:
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_WalkSouthFromLandlord
	waitmovement 0
	return


HousingProtest_LandlordWalkOutside_Script::
	opendoor 2, 17
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	clearflag FLAG_TEMP_3
	addobject 12
	applymovement 12, Common_Movement_WalkDown
	waitmovement 0
	applymovement 12, Common_Movement_WalkDown
	waitmovement 0
	closedoor 2, 17
	waitdooranim
	applymovement 12, Common_Movement_LookAround
	waitmovement 0
	applymovement 12, Common_Movement_FaceDown
	waitmovement 0
	goto HousingProtest_LandlordTalkToCrowd_Dialogue
	return


HousingProtest_LandlordTalkToCrowd_Dialogue::
	msgbox gText_HousingProtest_WeCanComeTo
	closemessage
	call HousingProtest_MovePlayerIntoPosition
	clearflag FLAG_TEMP_1
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	addobject 10
	addobject 11
	applymovement 10, HousingProtest_ApproachLandlord
	applymovement 11, HousingProtest_ApproachLandlord
	waitmovement 0
	applymovement 12, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	msgbox gText_HousingProtest_OnlyThingWereUnderstanding
	closemessage
	applymovement 12, HousingProtest_BackUp
	waitmovement 0
	msgbox gText_HousingProtest_AreYouTrying
	msgbox gText_HousingProtest_TheyCantArrest
	msgbox gText_HousingProtest_AintGonnaBeNothing
	closemessage
	applymovement 10, Common_Movement_FaceRight
	applymovement 11, Common_Movement_FaceRight
	msgbox gText_HousingProtest_PeopleCantStayHere
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	applymovement 2, Common_Movement_FaceLeft
	applymovement 3, Common_Movement_FaceLeft
	applymovement 4, Common_Movement_FaceLeft
	applymovement 5, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_FaceLeft
	applymovement 7, Common_Movement_FaceLeft
	applymovement 8, Common_Movement_FaceLeft
	applymovement 9, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_HousingProtest_Yeah
	applymovement 3, Common_Movement_ExclamationMark
	msgbox gText_HousingProtest_LetsDoThis
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	msgbox gText_HousingProtest_ScrewThese
	waitmovement 0
	closemessage
	applymovement 10, Common_Movement_FaceUp
	applymovement 11, Common_Movement_FaceUp
	waitmovement 0
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_TEMP_2
	addobject 13
	playmoncry SPECIES_TURTONATOR, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox gText_HousingProtest_ToTryReason
	msgbox gText_HousingProtest_AintAThreat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_CutItOut
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_DefendLandlord
	applymovement 12, HousingProtest_StepAside
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_EveryTimeISee
	callnative ClearMugshot
	msgbox gText_HousingProtest_TheseClowns
	msgbox gText_HousingProtest_ThisAintYourBusiness
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_ICanTakeBoth
	callnative ClearMugshot
	closemessage
	addvar VAR_ROUTE101_STATE, 1
	copyobjectxytoperm 12
	copyobjectxytoperm 10
	copyobjectxytoperm 11
	call Common_EventScript_SaveGame
	closemessage
	goto HousingProtest_StartBattle_Script
	return


HousingProtest_StartBattle_Script::
	lockall
	msgbox gText_HousingProtest_FineWithMe
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_1, gText_HousingProtest_ThisIsNotHowThis
	goto HousingProtest_PostBattle_Dialogue
	return


HousingProtest_StartBattle_PostSave_Script::
	locktarget
	setobjectnewmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 6, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	msgbox gText_HousingProtest_FineWithMe, MSGBOX_NPC
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_1, gText_HousingProtest_ThisIsNotHowThis
	goto HousingProtest_PostBattle_Dialogue
	return


HousingProtest_PostBattle_Dialogue::
	lockall
	addvar VAR_STORYLINE_STATE, 1
	setobjectnewmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 6, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	playse SE_BALL_OPEN
	waitse
	removeobject 13
	addvar VAR_ROUTE101_STATE, 1
	msgbox gText_HousingProtest_YouProudNow
	msgbox gText_HousingProtest_KeepOnLicking
	closemessage
	call HousingProtest_GruntsAwalkAway_Script
	releaseall
	end


HousingProtest_GruntsAwalkAway_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 21
	goto_if_eq HousingProtest_GruntsAwalkAway_Script_2
	call HousingProtest_MoveGruntsExit_Script
HousingProtest_GruntsAwalkAway_Script_1:
	waitmovement 0
	removeobject 11
	removeobject 10
	fadedefaultbgm
	return

HousingProtest_GruntsAwalkAway_Script_2:
	call HousingProtest_MoveGruntsAroundPlayer_Script
	goto HousingProtest_GruntsAwalkAway_Script_1


HousingProtest_MoveGruntsExit_Script::
	applymovement 11, HousingProtest_WalkSouthFromLandlord
	applymovement 10, HousingProtest_WalkSouthFromLandlord
	return


HousingProtest_MoveGruntsAroundPlayer_Script::
	applymovement 10, HousingProtest_WalkAroundPlayer
	applymovement 11, HousingProtest_WalkAroundPlayer
	return


HousingProtest_InteractLandlord_Script::
	lock
	compare VAR_ROUTE101_STATE, 2
	goto_if_lt HousingProtest_InteractLandlord_Script_2
	compare VAR_TEMP_4, 3
	goto_if_ne HousingProtest_InteractLandlord_Script_3
	msgbox gText_HousingProtest_ShouldHireThatSecurity, MSGBOX_NPC
HousingProtest_InteractLandlord_Script_1:
	closemessage
	release
	end

HousingProtest_InteractLandlord_Script_2:
	msgbox gText_HousingProtest_OhGod, MSGBOX_NPC
	goto HousingProtest_InteractLandlord_Script_1

HousingProtest_InteractLandlord_Script_3:
	call HousingProtest_InteractLandlord_Dialogue
	goto HousingProtest_InteractLandlord_Script_1


HousingProtest_InteractLandlord_Dialogue::
	addvar VAR_TEMP_4, 1
	msgbox gText_HousingProtest_HasATendency, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_WhyWereProtesting
	callnative ClearMugshot
	msgbox gText_HousingProtest_EntitledToLiveAnyWhere
	msgbox gText_HousingProtest_SubjectToTheSameRent
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_SoPeopleWereComing
	callnative ClearMugshot
	msgbox gText_HousingProtest_IGuessSo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_WhatAboutThePolice
	callnative ClearMugshot
	msgbox gText_HousingProtest_MoreAndMoreCommon
	return


HousingProtest_WalkPlayer1Left:
	walk_left
	step_end

HousingProtest_WalkPlayer2Left:
	walk_left
	walk_left
	step_end

HousingProtest_WalkPlayer3Left:
	walk_left
	walk_left
	walk_left
	step_end

HousingProtest_WalkPlayer4Left:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

HousingProtest_ApproachLandlord:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HousingProtest_BackUp:
	lock_facing_direction
	walk_slow_up
	delay_16
	unlock_facing_direction
	step_end

HousingProtest_DefendLandlord:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

HousingProtest_StepAside:
	walk_left
	face_down
	step_end

HousingProtest_WalkSouthFromLandlord:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

HousingProtest_WalkAroundPlayer:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_HousingProtest_RichAndRude::
	.string "Hey you! Rich and rude! We don't like\n"
	.string "your attitude!$"

gText_HousingProtest_YoureNoGood::
	.string "Hey you! You're no good! Treat the\n"
	.string "people like you should!$"

gText_HousingProtest_EverybodySoAngry::
	.string "Why is everybody so angry?$"

gText_HousingProtest_ArentGoingToStand::
	.string "We aren't going to stand for this any\n"
	.string "longer!$"

gText_HousingProtest_CantKeepPushing::
	.string "You can't keep pushing us out!$"

gText_HousingProtest_DeserveToLive::
	.string "We deserve to live here too!$"

gText_HousingProtest_WeCanComeTo::
	.string "I'm sure we can come to some\n"
	.string "understanding here, please...$"

gText_HousingProtest_OnlyThingWereUnderstanding::
	.string "The only thing we're understanding is\n"
	.string "that you need to leave, and take your\l"
	.string "fancy apartments with you!$"

gText_HousingProtest_AreYouTrying::
	.string "Are you trying to intimidate me? I'll\n"
	.string "call the police!$"

gText_HousingProtest_TheyCantArrest::
	.string "They can't arrest of all us, right?$"

gText_HousingProtest_AintGonnaBeNothing::
	.string "Ain't gonna be nothing to defend when\n"
	.string "we done...$"

gText_HousingProtest_PeopleCantStayHere::
	.string "If we, the people of Oakland can't stay\n"
	.string "here, nobody can. Let's bring it down!$"

gText_HousingProtest_Yeah::
	.string "Yeah!$"

gText_HousingProtest_LetsDoThis::
	.string "Let's do this!$"

gText_HousingProtest_ScrewThese::
	.string "Screw these developers!$"

gText_HousingProtest_ToTryReason::
	.string "I came outside to try to reason with\n"
	.string "you trash, and you're threatening me\l"
	.string "and my building?$"

gText_HousingProtest_AintAThreat::
	.string "Ain't a threat. We promising. Call ya\n"
	.string "boys!$"

gText_HousingProtest_CutItOut::
	.string "Cut it out!$"

gText_HousingProtest_EveryTimeISee::
	.string "Every time I see you guys, you're\n"
	.string "attacking innocent people. Don't you\l"
	.string "have something more productive to do?$"

gText_HousingProtest_TheseClowns::
	.string "Innocent? These clowns?! Damn, you\n"
	.string "transplants really got it twisted.$"

gText_HousingProtest_ThisAintYourBusiness::
	.string "This ain't your business. You should\n"
	.string "un-involve yourself.$"

gText_HousingProtest_OhGod::
	.string "Oh god... they're going to kill me!$"

gText_HousingProtest_ICanTakeBoth::
	.string "I can take both of you. Leave him alone,\n"
	.string "or you're going through me.$"

gText_HousingProtest_FineWithMe::
	.string "Pfft, fine with me. Turtonator,\n"
	.string "Flamethrower!$"

gText_HousingProtest_GoPoundSand::
	.string "Go pound sand, and stay out of\n"
	.string "TeamRocket's way.$"

gText_HousingProtest_ThisIsNotHowThis::
	.string "Shit... this is not how this was supposed\n"
	.string "to go down.$"

gText_HousingProtest_YouProudNow::
	.string "You proud now? C'mon Vitomir.$"

gText_HousingProtest_KeepOnLicking::
	.string "Keep on licking those boots, fam.\n"
	.string "Dumbass...$"

gText_HousingProtest_HasATendency::
	.string "Thank you very much. You're right,\n"
	.string "TeamRocket has a tendency to pick on\l"
	.string "the defenseless like me.$"

gText_HousingProtest_WhyWereProtesting::
	.string "Why were people protesting?$"

gText_HousingProtest_EntitledToLiveAnyWhere::
	.string "Some of the citizens of Oakland feel\n"
	.string "that they are... entitled to live\l"
	.string "anywhere within their city limits.$"

gText_HousingProtest_SubjectToTheSameRent::
	.string "I don't get why they don't think they're\n"
	.string "subject to the same rent rules and\l"
	.string "regulations as the rest of us.$"

gText_HousingProtest_SoPeopleWereComing::
	.string "So people were coming to take the\n"
	.string "building from you?$"

gText_HousingProtest_IGuessSo::
	.string "I guess so.$"

gText_HousingProtest_WhatAboutThePolice::
	.string "What about the police?$"

gText_HousingProtest_MoreAndMoreCommon::
	.string "I'm sure they would have stopped it, but\n"
	.string "these protests are getting more and\l"
	.string "more common. The police can't be\l"
	.string "everywhere at once!$"

gText_HousingProtest_ShouldHireThatSecurity::
	.string "I suppose I should hire that security\n"
	.string "guard sooner rather than later...$"
