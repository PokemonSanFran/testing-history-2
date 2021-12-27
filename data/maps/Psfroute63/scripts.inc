Psfroute63_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute63_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfroute63_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfroute63_MapScripts_OnTransition
	return


Psfroute63_MapScripts_OnTransition::
	switch VAR_ROUTE101_STATE
	case 0, Psfroute63_MapScripts_OnTransition_2
	case 2, Psfroute63_MapScripts_OnTransition_3
	return

Psfroute63_MapScripts_OnTransition_2:
	goto HousingProtest_ObjectSetUp
	return

Psfroute63_MapScripts_OnTransition_3:
	goto HousingProtest_CleanUp
	return


HousingProtest_ObjectSetUp::
	setflag FLAG_HIDE_HOUSING_PROTEST_GRUNT
	setflag FLAG_HIDE_RABIA_PKMN
	setflag FLAG_HIDE_HOUSING_PROTEST_KATELL
	return


HousingProtest_CleanUp::
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	return


HousingProtest_StartChanting_Dialogue::
	locktarget
	msgbox gText_HousingProtest_RichAndRude
	msgbox gText_HousingProtest_YoureNoGood
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_EverybodySoAngry
	callnative ClearMugshot
	msgbox gText_HousingProtest_ArentGoingToStand
	msgbox gText_HousingProtest_CantKeepPushing
	msgbox gText_HousingProtest_DeserveToLive
	goto HousingProtest_KatellWalkOutside
	end


HousingProtest_KatellWalkOutside::
	opendoor 2, 17
	waitdooranim
	addobject 12
	applymovement 12, Common_Movement_WalkDown
	applymovement 12, Common_Movement_WalkDown
	waitmovement 0
	closedoor 2, 17
	waitdooranim
	applymovement 12, Common_Movement_LookAround
	applymovement 12, Common_Movement_FaceDown
	waitmovement 0
	goto HousingProtest_KatellTalkToCrowd_Dialogue
	return


HousingProtest_KatellTalkToCrowd_Dialogue::
	msgbox gText_HousingProtest_WeCanComeTo
	msgbox gText_HousingProtest_OnlyThingWereUnderstanding
	closemessage
	addobject 10
	addobject 11
	applymovement 10, HousingProtest_ApproachKatell
	applymovement 11, HousingProtest_ApproachKatell
	waitmovement 0
	applymovement 12, Common_Movement_ExclamationMark
	playse SE_PIN
	applymovement 12, Common_Movement_WalkUp
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
	applymovement 6, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_HousingProtest_Yeah
	applymovement 3, Common_Movement_ExclamationMark
	msgbox gText_HousingProtest_LetsDoThis
	waitmovement 0
	applymovement 8, Common_Movement_ExclamationMark
	msgbox gText_HousingProtest_ScrewThese
	waitmovement 0
	closemessage
	playse SE_BALL_OPEN
	waitfanfare
	addobject 13
	playmoncry SPECIES_TURTONATOR, CRY_MODE_ENCOUNTER
	waitmoncry
	addobject 13
	msgbox gText_HousingProtest_ToTryReason
	msgbox gText_HousingProtest_AintAThreat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HousingProtest_CutItOut
	callnative ClearMugshot
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
	call Common_EventScript_SaveGame
	closemessage
	goto HousingProtest_StartBattle_Script
	return


HousingProtest_StartBattle_Script::
	lockall
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_1, gText_HousingProtest_FineWithMe, gText_HousingProtest_ThisIsNotHowThis, HousingProtest_BattleWin_Dialogue, NO_MUSIC
	closemessage
	return


HousingProtest_BattleWin_Dialogue::
	setvar VAR_ROUTE101_STATE, 2
	msgbox gText_HousingProtest_YouProudNow
	msgbox gText_HousingProtest_KeepOnLicking
	return


HousingProtest_TalkToKatell::
	msgbox gText_HousingProtest_HasATendency
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


HousingProtest_TalkToKatellAgain::
	msgbox gText_HousingProtest_ShouldHireThatSecurity
	return


HousingProtest_ApproachKatell:
	walk_up
	walk_up
	walk_up
	walk_up
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

gText_HousingProtest_ICanTakeBoth::
	.string "I can take both of you. Leave him alone,\n"
	.string "or you're going through me.$"

gText_HousingProtest_FineWithMe::
	.string "Pfft, fine with me. Turtonator,\n"
	.string "Flamethrower!$"

gText_HousingProtest_GoPoundSand::
	.string "Go pound sand, and stay out of Team\n"
	.string "Rocket's way.$"

gText_HousingProtest_ThisIsNotHowThis::
	.string "Shit... this is not how this was supposed\n"
	.string "to go down.$"

gText_HousingProtest_YouProudNow::
	.string "You proud now? C'mon Vitomir.$"

gText_HousingProtest_KeepOnLicking::
	.string "Keep on licking those boots, fam.\n"
	.string "Dumbass...$"

gText_HousingProtest_HasATendency::
	.string "Thank you very much. You're right, Team\n"
	.string "Rocket has a tendency to pick on the\l"
	.string "defenseless like me.$"

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
