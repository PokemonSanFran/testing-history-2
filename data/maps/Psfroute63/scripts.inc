Psfroute63_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute63_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Psfroute63_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Psfroute63_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfroute63_MapScripts_OnTransition
	return

Psfroute63_MapScripts_MAP_SCRIPT_ON_RESUME:
	checktrainerflag TRAINER_GRUNT_AQUA_HIDEOUT_1
	goto_if 1, Psfroute63_MapScripts_MAP_SCRIPT_ON_RESUME_1
	return

Psfroute63_MapScripts_MAP_SCRIPT_ON_RESUME_1:
	goto HousingProtest_CleanUp
	return


Psfroute63_MapScripts_OnTransition::
	switch VAR_ROUTE101_STATE
	case 0, Psfroute63_MapScripts_OnTransition_2
	case 1, Psfroute63_MapScripts_OnTransition_3
	case 2, Psfroute63_MapScripts_OnTransition_4
	case 3, Psfroute63_MapScripts_OnTransition_5
	case 5, Psfroute63_MapScripts_OnTransition_6
	return

Psfroute63_MapScripts_OnTransition_2:
	goto HousingProtest_ObjectSetUp
	return

Psfroute63_MapScripts_OnTransition_3:
	goto HousingProtest_PostSave_ObjectSetUp
	return

Psfroute63_MapScripts_OnTransition_4:
	goto HousingProtest_CleanUpKatell
	return

Psfroute63_MapScripts_OnTransition_5:
	goto HousingProtest_CleanUpKatell
	return

Psfroute63_MapScripts_OnTransition_6:
	goto SorryAboutMyFriends_CleanUp
	return


HousingProtest_ObjectSetUp::
	setflag FLAG_HIDE_HOUSING_PROTEST_GRUNT
	setflag FLAG_HIDE_HOUSING_PROTEST_PKMN
	setflag FLAG_HIDE_HOUSING_PROTEST_KATELL
	setflag FLAG_HIDE_SORRYFRIENDS_PSFGOODADMIN
	return


HousingProtest_PostSave_ObjectSetUp::
	setobjectxyperm 12, 1, 18
	setobjectxyperm 10, 1, 20
	setobjectxyperm 11, 2, 20
	return


HousingProtest_CleanUp::
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


HousingProtest_CleanUpKatell::
	setflag FLAG_HIDE_HOUSING_PROTEST_KATELL
	clearflag FLAG_HIDE_SORRYFRIENDS_PSFGOODADMIN
	setvar VAR_ROUTE101_STATE, 3
	return


SorryAboutMyFriends_CleanUp::
	setflag FLAG_HIDE_SORRYFRIENDS_PSFGOODADMIN
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
	goto HousingProtest_KatellWalkOutside
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
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_WalkSouthFromKatell
	waitmovement 0
	return


HousingProtest_KatellWalkOutside::
	opendoor 2, 17
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	clearflag FLAG_HIDE_HOUSING_PROTEST_KATELL
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
	goto HousingProtest_KatellTalkToCrowd_Dialogue
	return


HousingProtest_KatellTalkToCrowd_Dialogue::
	msgbox gText_HousingProtest_WeCanComeTo
	closemessage
	call HousingProtest_MovePlayerIntoPosition
	clearflag FLAG_HIDE_HOUSING_PROTEST_GRUNT
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	addobject 10
	addobject 11
	applymovement 10, HousingProtest_ApproachKatell
	applymovement 11, HousingProtest_ApproachKatell
	waitmovement 0
	applymovement 12, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement 0
	msgbox gText_HousingProtest_OnlyThingWereUnderstanding
	applymovement 12, Common_Movement_WalkUp
	waitmovement 0
	applymovement 12, Common_Movement_FaceDown
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
	waitfanfare
	clearflag FLAG_HIDE_HOUSING_PROTEST_PKMN
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
	applymovement OBJ_EVENT_ID_PLAYER, HousingProtest_DefendKatell
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
	setvar VAR_ROUTE101_STATE, 1
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
	goto HousingProtest_BattleWin_Dialogue
	return


HousingProtest_StartBattle_PostSave_Script::
	locktarget
	setobjectnewmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 6, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	msgbox gText_HousingProtest_FineWithMe, MSGBOX_NPC
	closemessage
	trainerbattle_no_intro TRAINER_GRUNT_AQUA_HIDEOUT_1, gText_HousingProtest_ThisIsNotHowThis
	goto HousingProtest_BattleWin_Dialogue
	return


HousingProtest_BattleWin_Dialogue::
	lockall
	addvar VAR_STORYLINE_STATE, 1
	setobjectnewmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 6, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	playse SE_BALL_OPEN
	waitfanfare
	removeobject 13
	setvar VAR_ROUTE101_STATE, 2
	msgbox gText_HousingProtest_YouProudNow
	msgbox gText_HousingProtest_KeepOnLicking
	closemessage
	call HousingProtest_GruntsWalkAwayScript
	releaseall
	end


HousingProtest_GruntsWalkAwayScript::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 21
	goto_if_eq HousingProtest_GruntsWalkAwayScript_2
	call HousingProtest_MoveGruntsExit
HousingProtest_GruntsWalkAwayScript_1:
	waitmovement 0
	removeobject 11
	removeobject 10
	fadedefaultbgm
	return

HousingProtest_GruntsWalkAwayScript_2:
	call HousingProtest_MoveGruntsAroundPlayer_Script
	goto HousingProtest_GruntsWalkAwayScript_1


HousingProtest_MoveGruntsExit::
	applymovement 11, HousingProtest_WalkSouthFromKatell
	applymovement 10, HousingProtest_WalkSouthFromKatell
	return


HousingProtest_MoveGruntsAroundPlayer_Script::
	applymovement 10, HousingProtest_WalkAroundPlayer
	applymovement 11, HousingProtest_WalkAroundPlayer
	return


HousingProtest_TalkToKatell::
	compare VAR_ROUTE101_STATE, 2
	goto_if_eq HousingProtest_TalkToKatell_1
	goto HousingProtest_TalkToKatellAgain
	return

HousingProtest_TalkToKatell_1:
	goto HousingProtest_TalkToKatellFirst
	return


HousingProtest_TalkToKatellFirst::
	setvar VAR_ROUTE101_STATE, 3
	lockall
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
	releaseall
	end


HousingProtest_TalkToKatellAgain::
	lockall
	msgbox gText_HousingProtest_ShouldHireThatSecurity, MSGBOX_NPC
	releaseall
	end


SorryAboutMyFriends_WalkToScene_Script::
	lockall
	call HousingProtest_MovePlayerIntoPosition
	goto SorryAboutMyFriends_Intro_Dialogue
	return


SorryAboutMyFriends_Intro_Dialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 14, Common_Movement_FaceRight
	waitmovement 0
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_CongratsOnYourWin
	goto SorryAboutMyFriends_Continue_Dialogue
	return


SorryAboutMyFriends_TalkToIntro_Dialogue::
	lockall
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	compare VAR_ROUTE101_STATE, 4
	goto_if_eq SorryAboutMyFriends_TalkToIntro_Dialogue_2
SorryAboutMyFriends_TalkToIntro_Dialogue_1:
	msgbox gText_SorryAboutMyFriends_CongratsOnYourWin, MSGBOX_NPC
	goto SorryAboutMyFriends_Continue_Dialogue
	return

SorryAboutMyFriends_TalkToIntro_Dialogue_2:
	msgbox gText_SorryAboutMyFriends_WorldNeedsMoreCompassion, MSGBOX_NPC
	goto SorryAboutMyFriends_CheckBadge_Script
	goto SorryAboutMyFriends_TalkToIntro_Dialogue_1


SorryAboutMyFriends_Continue_Dialogue::
	lockall
	callnative ClearMugshot
	setvar VAR_ROUTE101_STATE, 4
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ItWasWait
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_YourePartOf
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_DidINotMention
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WaitThatWas
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_UnfortunateWorldview
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_AreYouGuysHelping
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ThereWasAProtest
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_IWasTheOneWhoShut
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WhenTheyMentionedPowerful
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_UhHuh
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_OurHeartsAreInTheRightPlace
	msgbox gText_SorryAboutMyFriends_TrackDownTheMembers
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_GotPrettyFiredUp
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WorldNeedsMoreCompassion
	callnative ClearMugshot
	goto SorryAboutMyFriends_CheckBadge_Script
	return


SorryAboutMyFriends_CheckBadge_Script::
	lockall
	goto_if_set FLAG_BADGE04_GET, SorryAboutMyFriends_CheckBadge_Script_1
	goto SorryAboutMyFriends_GetBadgeFirst_Dialogue
	return

SorryAboutMyFriends_CheckBadge_Script_1:
	goto SorryAboutMyFriends_GiveTicket_Script
	return


SorryAboutMyFriends_GetBadgeFirst_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WaitHoldOn
	callnative ClearMugshot
	fadedefaultbgm
	releaseall
	end


SorryAboutMyFriends_GiveTicket_Script::
	giveitem ITEM_SS_TICKET, 1
	setvar VAR_ROUTE101_STATE, 5
	addvar VAR_FERRY_STATE, 1
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_IGiveYouALot
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_IAppreciateTheGesture
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WantedYouToGoThere
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ExcellentPlaceToTrain
	callnative ClearMugshot
	compare VAR_FAINTED_FOG_STATE, 0
	goto_if_gt SorryAboutMyFriends_GiveTicket_Script_2
SorryAboutMyFriends_GiveTicket_Script_1:
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_FollowSomeMoreLeads
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_AfterWeBattled
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ThankYouEnjoy
	callnative ClearMugshot
	closemessage
	applymovement 14, SorryAboutMyFriends_WalkSouth
	waitmovement 0
	removeobject 14
	fadedefaultbgm
	releaseall
	end

SorryAboutMyFriends_GiveTicket_Script_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WaitForTheFog
	callnative ClearMugshot
	goto SorryAboutMyFriends_GiveTicket_Script_1


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

HousingProtest_ApproachKatell:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HousingProtest_DefendKatell:
	walk_left
	walk_left
	walk_left
	face_down
	step_end

HousingProtest_StepAside:
	walk_left
	face_down
	step_end

HousingProtest_WalkSouthFromKatell:
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

SorryAboutMyFriends_WalkSouth:
	walk_down
	walk_down
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
	.string "If we, the people of Psfcity9 can't\n"
	.string "stay here, nobody can. Let's bring it\l"
	.string "down!$"

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

gText_HousingProtest_ICanTakeBoth::
	.string "I can take both of you. Leave him alone,\n"
	.string "or you're going through me.$"

gText_HousingProtest_FineWithMe::
	.string "Pfft, fine with me. Turtonator,\n"
	.string "Flamethrower!$"

gText_HousingProtest_GoPoundSand::
	.string "Go pound sand, and stay out of\n"
	.string "Psfgoodteam's way.$"

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
	.string "Psfgoodteam has a tendency to pick on\l"
	.string "the defenseless like me.$"

gText_HousingProtest_WhyWereProtesting::
	.string "Why were people protesting?$"

gText_HousingProtest_EntitledToLiveAnyWhere::
	.string "Some of the citizens of Psfcity9 feel\n"
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

gText_SorryAboutMyFriends_CongratsOnYourWin::
	.string "{PLAYER}. Congrats on your win in\n"
	.string "Psfcity11.$"

gText_SorryAboutMyFriends_ItWasWait::
	.string "Thanks! It was - wait.$"

gText_SorryAboutMyFriends_YourePartOf::
	.string "You're part of Psfgoodteam, right?$"

gText_SorryAboutMyFriends_DidINotMention::
	.string "*sigh* Yeah, did I not mention that when\n"
	.string "we met in Psfcity12?$"

gText_SorryAboutMyFriends_WaitThatWas::
	.string "Wait, that was Psfgoodteam? Everytime\n"
	.string "I run into them, they're attacking\l"
	.string "innocent people!$"

gText_SorryAboutMyFriends_UnfortunateWorldview::
	.string "Actually, that... unfortunate worldview\n"
	.string "is why I'm here.$"

gText_SorryAboutMyFriends_AreYouGuysHelping::
	.string "What do you mean? Are you guys helping\n"
	.string "or hurting people? What's your deal?$"

gText_SorryAboutMyFriends_ThereWasAProtest::
	.string "There was a protest here earlier that\n"
	.string "involved the Psfrocketacro, that\l"
	.string "apparently began to get out of hand.\l"
	.string "Two memb -$"

gText_SorryAboutMyFriends_IWasTheOneWhoShut::
	.string "I know. I was the one who shut your\n"
	.string "goons down. They were trying to\l"
	.string "destroy this building! Or take it back?\l"
	.string "I'm not really sure, but it was messed\l"
	.string "up.$"

gText_SorryAboutMyFriends_WhenTheyMentionedPowerful::
	.string "Well then, when they mentioned powerful\n"
	.string "Trainer, I should have assumed. And I'm\l"
	.string "very very sorry for their actions. We're\l"
	.string "all about peace and non-violence.$"

gText_SorryAboutMyFriends_UhHuh::
	.string "Uh huh.$"

gText_SorryAboutMyFriends_OurHeartsAreInTheRightPlace::
	.string "I hope our Psfcity12 work shows that\n"
	.string "our hearts are in the right place. I'm\l"
	.string "actually here to fix this mess too.$"

gText_SorryAboutMyFriends_TrackDownTheMembers::
	.string "I've been trying to track down the\n"
	.string "Psfgoodteam members that you battled,\l"
	.string "but they're gone! Their names aren't\l"
	.string "familiar, so they must be new... I've\l"
	.string "already reprimanded our Recruitment\l"
	.string "and Training team. We can't afford to\l"
	.string "have idiots like that making us look\l"
	.string "bad.$"

gText_SorryAboutMyFriends_GotPrettyFiredUp::
	.string "I got pretty fired up when I fought\n"
	.string "them. I hate when people pick on the\l"
	.string "defenseless, but I'm glad you're not\l"
	.string "cool with it either.$"

gText_SorryAboutMyFriends_WaitHoldOn::
	.string "Actually, you should get the Psfbadge4\n"
	.string "first. Let's talk when you do.$"

gText_SorryAboutMyFriends_WorldNeedsMoreCompassion::
	.string "The world needs more compassion like\n"
	.string "yours, {PLAYER}. If we could just\l"
	.string "take the time to learn about each\l"
	.string "other... actually, I have a good\l"
	.string "learning opportunity for you. Here.$"

gText_SorryAboutMyFriends_IGiveYouALot::
	.string "I give you a lot of apology gifts. I hope\n"
	.string "we stop screwing up and this is the\l"
	.string "last one!$"

gText_SorryAboutMyFriends_IAppreciateTheGesture::
	.string "I appreciate the gesture, but doesn't\n"
	.string "my pass from Psfbadguy1 get me to\l"
	.string "Psfcave7?$"

gText_SorryAboutMyFriends_WantedYouToGoThere::
	.string "It could, if Psfbadguy1 wanted you to\n"
	.string "go there. But now you can!$"

gText_SorryAboutMyFriends_ExcellentPlaceToTrain::
	.string "You'll learn a lot about Psfregion1 by\n"
	.string "going, and it's an excellent place to\l"
	.string "train for the Gym Challenge. With that,\l"
	.string "you can go to Psfcave7 from the\l"
	.string "Psfcity17 Ferry.$"

gText_SorryAboutMyFriends_WaitForTheFog::
	.string "(Guess I should go while I wait for the\n"
	.string "fog to clear...)$"

gText_SorryAboutMyFriends_FollowSomeMoreLeads::
	.string "Do you know which way Rabia and Vitomar\n"
	.string "went? I'm going to follow some more\l"
	.string "leads.$"

gText_SorryAboutMyFriends_AfterWeBattled::
	.string "After we battled, they went towards\n"
	.string "Psfcity17.$"

gText_SorryAboutMyFriends_ThankYouEnjoy::
	.string "Thank you {PLAYER}. Enjoy Psfcave7.$"
