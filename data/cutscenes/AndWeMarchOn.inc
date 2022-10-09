AndWeMarchOn_ObjectVisibility_Script::
	switch VAR_ROUTE108_STATE
	case 0, AndWeMarchOn_ObjectVisibility_Script_3
	case 1, AndWeMarchOn_ObjectVisibility_Script_4
AndWeMarchOn_ObjectVisibility_Script_1:
	return

AndWeMarchOn_ObjectVisibility_Script_3:
	call AndWeMarchOn_ObjectSetUp_Script
	goto AndWeMarchOn_ObjectVisibility_Script_1

AndWeMarchOn_ObjectVisibility_Script_4:
	call AndWeMarchOn_ObjectCleanUp_Script
	goto AndWeMarchOn_ObjectVisibility_Script_1


AndWeMarchOn_ObjectSetUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


AndWeMarchOn_ObjectCleanUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


AndWeMarchOn_MoveCameraToParade_Script::
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 9
	special TeleportCamera
	special SpawnCameraObject
	return


AndWeMarchOn_StartParadeMovement_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, AndWeMarchOn_WatchParade
	waitmovement 0
	fadescreen FADE_TO_BLACK
	call AndWeMarchOn_MoveCameraToParade_Script
	setobjectxyperm 9, 26, 10
	setobjectxy 9, 26, 10
	setobjectxy 10, 30, 10
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, AndWeMarchOn_PanCameraParadeStop
	applymovement 5, AndWeMarchOn_ParadeProcession
	applymovement 10, AndWeMarchOn_ParadeProcession
	applymovement 9, AndWeMarchOn_ParadeProcession
	applymovement 8, AndWeMarchOn_ParadeProcession
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_WowPeopleHere
	callnative ClearMugshot
	closemessage
	waitmovement 0
	special RemoveCameraObject
	msgbox gText_AndWeMarchOn_AndNowSomeWords
	closemessage
	goto AndWeMarchOn_Opening_Dialogue
	return


AndWeMarchOn_Opening_Dialogue::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	applymovement 5, AndWeMarchOn_LookAroundCrowd
	waitmovement 0
	playse SE_APPLAUSE
	applymovement 5, AndWeMarchOn_WalkToFloatCenter
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_SanFran
	callnative ClearMugshot
	closemessage
	playse SE_BANG
	waitse
	playse SE_BANG
	waitse
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_ThankYouForSupporting
	callnative ClearMugshot
	closemessage
	playse SE_APPLAUSE
	waitse
	applymovement 5, AndWeMarchOn_PaceBackForth
	waitmovement 0
	goto AndWeMarchOn_InviteOntoStage_Dialogue
	return


AndWeMarchOn_InviteOntoStage_Dialogue::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_WeHaveASpecialGuest
	callnative ClearMugshot
	closemessage
	applymovement 6, AndWeMarchOn_WalkOntoStage
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_RupertHereIsTheWinner
	callnative ClearMugshot
	closemessage
	msgbox gText_AndWeMarchOn_Boo
	msgbox gText_AndWeMarchOn_LetsGo
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_ButThatsNotGoing
	callnative ClearMugshot
	closemessage
	msgbox gText_AndWeMarchOn_YayRupert
	goto AndWeMarchOn_StartCutsceneBattle_Script
	return


AndWeMarchOn_StartCutsceneBattle_Script::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_RupertAreYouReady
	callnative ClearMugshot
	msgbox gText_AndWeMarchOn_Woo
	msgbox gText_AndWeMarchOn_Yeah
	closemessage
	applymovement 5, AndWeMarchOn_WalkToLeftSide
	applymovement 6, AndWeMarchOn_LookAroundCrowd
	waitmovement 0
	applymovement 6, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_LetsRock
	callnative ClearMugshot
	closemessage
	msgbox gText_AndWeMarchOn_AndOurBattle
	closemessage
	goto AndWeMarchOn_CutsceneBattleScript
	return


AndWeMarchOn_CutsceneBattleScript::
	applymovement OBJ_EVENT_ID_CAMERA, AndWeMarchOn_CenterBattleFrame
	playse SE_BALL_OPEN
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_TEMP_1
	addobject 1
	addobject 2
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	waitmoncry
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	waitmoncry
	playse SE_BALL_OPEN
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_TEMP_2
	addobject 3
	addobject 4
	playmoncry SPECIES_AZUMARILL, CRY_MODE_ENCOUNTER
	waitmoncry
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox gText_AndWeMarchOn_AttackPatternSigma
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_HelpingHand
	closemessage
	callnative ClearMugshot
	applymovement 1, AndWeMarchOn_Attack
	applymovement 2, AndWeMarchOn_Attack
	waitmovement 0
	fadescreen FADE_TO_BLACK
	playse SE_M_THUNDERBOLT
	waitse
	setobjectxy 3, 21, 9
	setobjectxy 4, 21, 11
	turnobject 3, DIR_EAST
	turnobject 4, DIR_EAST
	playse SE_FAINT
	waitse
	fadescreen FADE_FROM_BLACK
	msgbox gText_AndWeMarchOn_AndWithASupercharged
	goto AndWeMarchOn_PostBattle_Dialogue
	return


AndWeMarchOn_PostBattle_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_DamnThatsHow
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_LetsGiveItUp
	closemessage
	callnative ClearMugshot
	playse SE_APPLAUSE
	waitse
	playse SE_BALL_OPEN
	waitse
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	applymovement 6, AndWeMarchOn_WalkOffStage
	waitmovement 0
	goto AndWeMarchOn_PostBattleSpeech_Dialogue
	return


AndWeMarchOn_PostBattleSpeech_Dialogue::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_ItsBeenAWildYear
	playse SE_APPLAUSE
	waitse
	applymovement 5, AndWeMarchOn_WalkToSouthStage
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_OhItsNotAllBad
	callnative ClearMugshot
	closemessage
	applymovement 5, AndWeMarchOn_WalkToNorthStage
	waitmovement 0
	msgbox gText_AndWeMarchOn_Boo
	msgbox gText_AndWeMarchOn_FuckTheseGuys
	msgbox gText_AndWeMarchOn_GiveUsBackOur
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_ButHeyItsNot
	callnative ClearMugshot
	closemessage
	msgbox gText_AndWeMarchOn_Traitor
	msgbox gText_AndWeMarchOn_DownWith
	msgbox gText_AndWeMarchOn_WhatASlimeball
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_JustNotTheWay
	callnative ClearMugshot
	closemessage
	applymovement 5, AndWeMarchOn_GoBackToCenter
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_WeveGotAResponsibility
	callnative ClearMugshot
	closemessage
	goto AndWeMarchOn_ParadeEnd_Script
	return


AndWeMarchOn_ParadeEnd_Script::
	playse SE_APPLAUSE
	playse SE_APPLAUSE
	waitse
	fadescreen FADE_TO_BLACK
	removeobject 5
	removeobject 8
	setflag FLAG_TEMP_3
	addvar VAR_ROUTE108_STATE, 1
	special ReturnCameraToPlayer
	fadescreen FADE_FROM_BLACK
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end


AndWeMarchOn_WatchParade:
	face_down
	step_end

AndWeMarchOn_PanCameraParadeStop:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AndWeMarchOn_ParadeProcession:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AndWeMarchOn_WalkToBattle:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AndWeMarchOn_LookAroundCrowd:
	face_up
	delay_16
	face_down
	delay_16
	step_end

AndWeMarchOn_WalkToFloatCenter:
	walk_right
	walk_right
	walk_down
	face_right
	step_end

AndWeMarchOn_PaceBackForth:
	walk_up
	walk_up
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	delay_16
	walk_up
	walk_up
	step_end

AndWeMarchOn_WalkOntoStage:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

AndWeMarchOn_WalkToLeftSide:
	walk_left
	face_right
	step_end

AndWeMarchOn_Attack:
	walk_fast_right
	walk_fast_right
	step_end

AndWeMarchOn_WalkOffStage:
	walk_down
	walk_down
	walk_down
	face_up
	step_end

AndWeMarchOn_WalkToSouthStage:
	walk_right
	walk_right
	walk_right
	step_end

AndWeMarchOn_WalkToNorthStage:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AndWeMarchOn_GoBackToCenter:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

AndWeMarchOn_WalkCameraToParade:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

AndWeMarchOn_CenterBattleFrame:
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

gText_AndWeMarchOn_WowPeopleHere::
	.string "Wow, people here really love their\n"
	.string "Double Battles… but then why is\l"
	.string "Singles the official League format?$"

gText_AndWeMarchOn_AndNowSomeWords::
	.string "And now, some words from our Grand\n"
	.string "Marshall, Malva!$"

gText_AndWeMarchOn_SanFran::
	.string "SanFran!$"

gText_AndWeMarchOn_ThankYouForSupporting::
	.string "Thank you for supporting our annual\n"
	.string "Doubles Parade! This has been a fuckin'\l"
	.string "blast! Who's having a good time?!$"

gText_AndWeMarchOn_WeHaveASpecialGuest::
	.string "We have a special guest for you all\n"
	.string "today! Rupert, please come up to the\l"
	.string "stage!$"

gText_AndWeMarchOn_RupertHereIsTheWinner::
	.string "Rupert here is the winner of the Mission\n"
	.string "Preparatory School graduation\l"
	.string "tournament! NORMALLY, the winner\l"
	.string "normally gets a scholarship from the\l"
	.string "SanFran League. But our new corporate\l"
	.string "overlords have decided that growing\l"
	.string "the in-region talent isn't a budget\l"
	.string "priority!$"

gText_AndWeMarchOn_Boo::
	.string "Boo!$"

gText_AndWeMarchOn_LetsGo::
	.string "Let's go Rupert!$"

gText_AndWeMarchOn_ButThatsNotGoing::
	.string "But that's not going to stop us from\n"
	.string "nurturing that talent ourselves!$"

gText_AndWeMarchOn_YayRupert::
	.string "Yaaaay Rupert!$"

gText_AndWeMarchOn_RupertAreYouReady::
	.string "Rupert, are you ready to bring an old\n"
	.string "master out of retirement?$"

gText_AndWeMarchOn_Woo::
	.string "Woooo!$"

gText_AndWeMarchOn_Yeah::
	.string "Yeah!$"

gText_AndWeMarchOn_LetsRock::
	.string "Let's rock!$"

gText_AndWeMarchOn_AndOurBattle::
	.string "And our battle is underway!$"

gText_AndWeMarchOn_AttackPatternSigma::
	.string "Attack pattern Sigma!$"

gText_AndWeMarchOn_HelpingHand::
	.string "Helping Hand! Breaking Swipe!$"

gText_AndWeMarchOn_AndWithASupercharged::
	.string "And with a supercharged Breaking Swipe,\n"
	.string "Malva ends the battle in one turn! The\l"
	.string "exhibition winner is the Elite Four's\l"
	.string "MALVA!$"

gText_AndWeMarchOn_DamnThatsHow::
	.string "Damn, that's how she beat me too… wait,\n"
	.string "did they say Elite Four? SanFran\l"
	.string "doesn't have those, does it?$"

gText_AndWeMarchOn_LetsGiveItUp::
	.string "Let's give it up for Rupert!$"

gText_AndWeMarchOn_ItsBeenAWildYear::
	.string "It's been a wild year, hasn't it? Who's\n"
	.string "loving our new Pokémon League? The\l"
	.string "League that's too good for the likes of\l"
	.string "young Rupert.$"

gText_AndWeMarchOn_OhItsNotAllBad::
	.string "Oh, it's not all bad, is it? Yeah, our\n"
	.string "beloved elected officials sold our\l"
	.string "League to the highest bidder. And yeah,\l"
	.string "they've bulldozed all of our traditions\l"
	.string "and replaced them with some soulless\l"
	.string "husk of a League. AND YEAH, they\l"
	.string "pushed our entire battling community\l"
	.string "out and replaced them with highly paid\l"
	.string "drones that couldn't battle their way\l"
	.string "out of a paper bag….$"

gText_AndWeMarchOn_FuckTheseGuys::
	.string "Fuck these guys!$"

gText_AndWeMarchOn_GiveUsBackOur::
	.string "Give us back our League!$"

gText_AndWeMarchOn_ButHeyItsNot::
	.string "But hey! It's not all bad, right?\n"
	.string "Haightashbury got to keep its Gym!$"

gText_AndWeMarchOn_Traitor::
	.string "Traitor!$"

gText_AndWeMarchOn_DownWith::
	.string "Down with Pryce!$"

gText_AndWeMarchOn_WhatASlimeball::
	.string "What a slimeball!$"

gText_AndWeMarchOn_JustNotTheWay::
	.string "…just not the way we would have hoped.$"

gText_AndWeMarchOn_WeveGotAResponsibility::
	.string "We've got a responsibility here. The\n"
	.string "profit motive can not… WILL NOT erase\l"
	.string "our history. It lives on in our hearts.\l"
	.string "In our stories Our legends. And no\l"
	.string "corporation, Ycombinator or otherwise,\l"
	.string "can take that away from us!$"
