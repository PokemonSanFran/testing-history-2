AndWeMarchOn_ObjectSetUp_Script::
	setflag FLAG_HIDE_ANDWEMARCHON_BATTLE1
	setflag FLAG_HIDE_ANDWEMARCHON_BATTLE2
	end


AndWeMarchOn_StartParadeMovement::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_WowPeopleHere
	applymovement 10, AndWeMarchOn_ParadeProcession
	applymovement 9, AndWeMarchOn_ParadeProcession
	applymovement 8, AndWeMarchOn_ParadeProcession
	applymovement 7, AndWeMarchOn_ParadeProcession
	applymovement 5, AndWeMarchOn_ParadeProcession
	msgbox gText_AndWeMarchOn_AndNowSomeWords
	closemessage
	goto AndWeMarchOn_Opening_Dialogue
	return


AndWeMarchOn_Opening_Dialogue::
	applymovement 5, AndWeMarchOn_LookAroundCrowd
	waitmovement 0
	playse SE_APPLAUSE
	applymovement 5, AndWeMarchOn_WalkToFloatCenter
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_Psfregion1
	callnative ClearMugshot
	closemessage
	playse SE_BANG
	waitfanfare
	playse SE_BANG
	waitfanfare
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_ThankYouForSupporting
	callnative ClearMugshot
	closemessage
	playse SE_APPLAUSE
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
	closemessage
	msgbox gText_AndWeMarchOn_Woo
	msgbox gText_AndWeMarchOn_Yeah
	applymovement 5, AndWeMarchOn_WalkToLeftSide
	applymovement 6, AndWeMarchOn_LookAroundCrowd
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
	playse SE_BALL_OPEN
	playse SE_BALL_OPEN
	waitfanfare
	clearflag FLAG_HIDE_ANDWEMARCHON_BATTLE1
	addobject 1
	addobject 2
	playmoncry SPECIES_GROUDON, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_KYOGRE, CRY_MODE_ENCOUNTER
	waitmoncry
	playse SE_BALL_OPEN
	playse SE_BALL_OPEN
	waitfanfare
	clearflag FLAG_HIDE_ANDWEMARCHON_BATTLE2
	addobject 3
	addobject 4
	playmoncry SPECIES_AZUMARILL, CRY_MODE_ENCOUNTER
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
	waitfanfare
	setobjectxy 3, 25, 9
	setobjectxy 4, 25, 10
	turnobject 3, DIR_EAST
	turnobject 4, DIR_EAST
	playse SE_FAINT
	waitfanfare
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
	waitfanfare
	applymovement 6, AndWeMarchOn_WalkOffStage
	goto AndWeMarchOn_PostBattleSpeech_Dialogue
	return


AndWeMarchOn_PostBattleSpeech_Dialogue::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_AndWeMarchOn_ItsBeenAWildYear
	playse SE_BOO
	waitfanfare
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
	waitfanfare
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_ANDWEMARCHON_PARADE
	fadescreen FADE_FROM_BLACK
	releaseall
	end


AndWeMarchOn_ParadeProcession:
	step_end

AndWeMarchOn_LookAroundCrowd:
	step_end

AndWeMarchOn_WalkToFloatCenter:
	step_end

AndWeMarchOn_PaceBackForth:
	step_end

AndWeMarchOn_WalkOntoStage:
	step_end

AndWeMarchOn_WalkToLeftSide:
	step_end

AndWeMarchOn_Attack:
	step_end

AndWeMarchOn_WalkOffStage:
	step_end

AndWeMarchOn_WalkToSouthStage:
	step_end

AndWeMarchOn_WalkToNorthStage:
	step_end

AndWeMarchOn_GoBackToCenter:
	step_end

gText_AndWeMarchOn_WowPeopleHere::
	.string "Wow, people here really love their\n"
	.string "Double Battles… but then why is\l"
	.string "Singles the official League format?$"

gText_AndWeMarchOn_AndNowSomeWords::
	.string "And now, some words from our Grand\n"
	.string "Marshall, Psfelite1!$"

gText_AndWeMarchOn_Psfregion1::
	.string "Psfregion1!$"

gText_AndWeMarchOn_ThankYouForSupporting::
	.string "Thank you for supporting our annual\n"
	.string "Doubles Parade! This has been a fuckin'\l"
	.string "blast! Who's having a good time?!$"

gText_AndWeMarchOn_WeHaveASpecialGuest::
	.string "We have a special guest for you all\n"
	.string "today! Rupert, please come up to the\l"
	.string "stage!$"

gText_AndWeMarchOn_RupertHereIsTheWinner::
	.string "Rupert here is the winner of the\n"
	.string "Psfcity6 Preparatory School\l"
	.string "graduation tournament! NORMALLY, the\l"
	.string "winner normally gets a scholarship from\l"
	.string "the Psfregion1 League. But our new\l"
	.string "corporate overlords have decided that\l"
	.string "growing the in-region talent isn't a\l"
	.string "budget priority!$"

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
	.string "Psfelite1 ends the battle in one turn!\l"
	.string "The exhibition winner is the Elite\l"
	.string "Four's PSFELITE1!$"

gText_AndWeMarchOn_DamnThatsHow::
	.string "Damn, that's how she beat me too… wait,\n"
	.string "did they say Elite Four? Psfregion1\l"
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
	.string "Psfcity18 got to keep its Gym!$"

gText_AndWeMarchOn_Traitor::
	.string "Traitor!$"

gText_AndWeMarchOn_DownWith::
	.string "Down with Psfleader7!$"

gText_AndWeMarchOn_WhatASlimeball::
	.string "What a slimeball!$"

gText_AndWeMarchOn_JustNotTheWay::
	.string "…just not the way we would have hoped.$"

gText_AndWeMarchOn_WeveGotAResponsibility::
	.string "We've got a responsibility here. The\n"
	.string "profit motive can not… WILL NOT erase\l"
	.string "our history. It lives on in our hearts.\l"
	.string "In our stories Our legends. And no\l"
	.string "corporation, Psfbadguy or otherwise,\l"
	.string "can take that away from us!$"
