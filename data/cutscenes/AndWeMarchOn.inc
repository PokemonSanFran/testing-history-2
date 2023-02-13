AndWeMarchOn_ObjectVisibility_Script::
	switch VAR_HAIGHTASHBURY_STATE
	case PARADE_NOT_STARTED, AndWeMarchOn_ObjectVisibility_Script_3
	case PARADE_COMPLETE, AndWeMarchOn_ObjectVisibility_Script_4
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
	applymovement OBJ_EVENT_ID_PLAYER, AndWeMarchOn_WatchParade_Movement
	waitmovement 0
	fadescreen FADE_TO_BLACK
	call AndWeMarchOn_MoveCameraToParade_Script
	setobjectxyperm 9, 26, 10
	setobjectxy 9, 26, 10
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, AndWeMarchOn_PanCameraParadeStop_Movement
	applymovement 5, AndWeMarchOn_ParadeProcession_Movement
	applymovement 9, AndWeMarchOn_ParadeProcession_Movement
	applymovement 8, AndWeMarchOn_ParadeProcession_Movement
	applymovement 7, AndWeMarchOn_ParadeProcession_Movement
	msgbox gText_AndWeMarchOn_WowPeopleHere, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_CONFUSE
	closemessage
	waitmovement 0
	special RemoveCameraObject
	msgbox gText_AndWeMarchOn_AndNowSomeWords, MSGBOX_DEFAULT, SPEAKER_ANNOUNCER
	closemessage
	goto AndWeMarchOn_Opening_Dialogue
	return


AndWeMarchOn_Opening_Dialogue::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	applymovement 5, AndWeMarchOn_LookAroundCrowd_Movement
	waitmovement 0
	playse SE_APPLAUSE
	applymovement 5, AndWeMarchOn_WalkToFloatCenter_Movement
	waitmovement 0
	msgbox gText_AndWeMarchOn_SanFran, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT, EMOTE_HAPPY
	closemessage
	playse SE_BANG
	waitse
	playse SE_BANG
	waitse
	msgbox gText_AndWeMarchOn_ThankYouForSupporting, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT, EMOTE_HAPPY
	playse SE_APPLAUSE
	waitse
	applymovement 5, AndWeMarchOn_PaceBackForth_Movement
	waitmovement 0
	goto AndWeMarchOn_InviteOntoStage_Dialogue
	return


AndWeMarchOn_InviteOntoStage_Dialogue::
	msgbox gText_AndWeMarchOn_WeHaveASpecialGuest, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT, EMOTE_HAPPY
	closemessage
	applymovement 26, AndWeMarchOn_WalkOntoStage_Movement
	waitmovement 0
	msgbox gText_AndWeMarchOn_RupertHereIsTheWinner, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	closemessage
	msgbox gText_AndWeMarchOn_Boo, MSGBOX_DEFAULT, SPEAKER_CROWD_A
	msgbox gText_AndWeMarchOn_LetsGo, MSGBOX_DEFAULT, SPEAKER_CROWD_B
	msgbox gText_AndWeMarchOn_ButThatsNotGoing, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	closemessage
	msgbox gText_AndWeMarchOn_YayRupert, MSGBOX_DEFAULT, SPEAKER_CROWD_C
	goto AndWeMarchOn_StartCutsceneBattle_Script
	return


AndWeMarchOn_StartCutsceneBattle_Script::
	msgbox gText_AndWeMarchOn_RupertAreYouReady, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	msgbox gText_AndWeMarchOn_Woo, MSGBOX_DEFAULT, SPEAKER_CROWD_D
	msgbox gText_AndWeMarchOn_Yeah, MSGBOX_DEFAULT, SPEAKER_CROWD_A
	closemessage
	applymovement 5, AndWeMarchOn_WalkToLeftSide_Movement
	applymovement 26, AndWeMarchOn_LookAroundCrowd_Movement
	waitmovement 0
	applymovement 26, Common_Movement_FaceLeft
	waitmovement 0
	msgbox gText_AndWeMarchOn_LetsRock, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	closemessage
	msgbox gText_AndWeMarchOn_AndOurBattle, MSGBOX_DEFAULT, SPEAKER_ANNOUNCER
	closemessage
	goto AndWeMarchOn_CutsceneBattleScript
	return


AndWeMarchOn_CutsceneBattleScript::
	applymovement OBJ_EVENT_ID_CAMERA, AndWeMarchOn_CenterBattleFrame_Movement
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
	msgbox gText_AndWeMarchOn_AttackPatternSigma, MSGBOX_DEFAULT, SPEAKER_RUPERT
	msgbox gText_AndWeMarchOn_HelpingHand, MSGBOX_DEFAULT, SPEAKER_MALVA
	closemessage
	applymovement 1, AndWeMarchOn_Attack_Movement
	applymovement 2, AndWeMarchOn_Attack_Movement
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
	msgbox gText_AndWeMarchOn_AndWithASupercharged, MSGBOX_DEFAULT, SPEAKER_ANNOUNCER
	goto AndWeMarchOn_PostBattle_Dialogue
	return


AndWeMarchOn_PostBattle_Dialogue::
	msgbox gText_AndWeMarchOn_DamnThatsHow, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_SHOCK
	msgbox gText_AndWeMarchOn_LetsGiveItUp, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT, EMOTE_HAPPY
	playse SE_APPLAUSE
	waitse
	playse SE_BALL_OPEN
	waitse
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	applymovement 26, AndWeMarchOn_WalkOffStage_Movement
	waitmovement 0
	goto AndWeMarchOn_PostBattleSpeech_Dialogue
	return


AndWeMarchOn_PostBattleSpeech_Dialogue::
	msgbox gText_AndWeMarchOn_ItsBeenAWildYear, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	closemessage
	playse SE_APPLAUSE
	waitse
	applymovement 5, AndWeMarchOn_WalkToSouthStage_Movement
	waitmovement 0
	msgbox gText_AndWeMarchOn_OhItsNotAllBad, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	closemessage
	applymovement 5, AndWeMarchOn_WalkToNorthStage_Movement
	waitmovement 0
	msgbox gText_AndWeMarchOn_Boo, MSGBOX_DEFAULT, SPEAKER_CROWD_B
	msgbox gText_AndWeMarchOn_FuckTheseGuys, MSGBOX_DEFAULT, SPEAKER_CROWD_C, TAIL_SHOUT, EMOTE_ANGRY
	msgbox gText_AndWeMarchOn_GiveUsBackOur, MSGBOX_DEFAULT, SPEAKER_CROWD_D, TAIL_SHOUT, EMOTE_ANGRY
	msgbox gText_AndWeMarchOn_ButHeyItsNot, MSGBOX_DEFAULT, SPEAKER_MALVA, TAIL_SHOUT
	msgbox gText_AndWeMarchOn_Traitor, MSGBOX_DEFAULT, SPEAKER_CROWD_A, TAIL_SHOUT, EMOTE_ANGRY
	msgbox gText_AndWeMarchOn_DownWith, MSGBOX_DEFAULT, SPEAKER_CROWD_B, TAIL_SHOUT, EMOTE_ANGRY
	msgbox gText_AndWeMarchOn_WhatASlimeball, MSGBOX_DEFAULT, SPEAKER_CROWD_C, TAIL_SHOUT, EMOTE_ANGRY
	msgbox gText_AndWeMarchOn_JustNotTheWay, MSGBOX_DEFAULT, SPEAKER_MALVA
	closemessage
	applymovement 5, AndWeMarchOn_GoBackToCenter_Movement
	waitmovement 0
	msgbox gText_AndWeMarchOn_WeveGotAResponsibility, MSGBOX_DEFAULT, SPEAKER_MALVA
	closemessage
	goto AndWeMarchOn_ParadeEnd_Script
	return


AndWeMarchOn_ParadeEnd_Script::
	playse SE_APPLAUSE
	playse SE_APPLAUSE
	waitse
	fadescreen FADE_TO_BLACK
	removeobject 5
	removeobject 9
	removeobject 8
	removeobject 7
	setflag FLAG_TEMP_3
	setvar VAR_HAIGHTASHBURY_STATE, PARADE_COMPLETE
	special ReturnCameraToPlayer
	fadescreen FADE_FROM_BLACK
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end


AndWeMarchOn_WatchParade_Movement:
	face_down
	step_end

AndWeMarchOn_PanCameraParadeStop_Movement:
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

AndWeMarchOn_ParadeProcession_Movement:
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

AndWeMarchOn_WalkToBattle_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AndWeMarchOn_LookAroundCrowd_Movement:
	face_up
	delay_16
	face_down
	delay_16
	step_end

AndWeMarchOn_WalkToFloatCenter_Movement:
	walk_right
	walk_right
	walk_down
	face_right
	step_end

AndWeMarchOn_PaceBackForth_Movement:
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

AndWeMarchOn_WalkOntoStage_Movement:
	walk_up
	walk_up
	walk_up
	face_left
	step_end

AndWeMarchOn_WalkToLeftSide_Movement:
	walk_left
	face_right
	step_end

AndWeMarchOn_Attack_Movement:
	walk_fast_right
	walk_fast_right
	step_end

AndWeMarchOn_WalkOffStage_Movement:
	walk_down
	walk_down
	walk_down
	face_up
	step_end

AndWeMarchOn_WalkToSouthStage_Movement:
	walk_right
	walk_right
	walk_right
	step_end

AndWeMarchOn_WalkToNorthStage_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

AndWeMarchOn_GoBackToCenter_Movement:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

AndWeMarchOn_WalkCameraToParade_Movement:
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

AndWeMarchOn_CenterBattleFrame_Movement:
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
