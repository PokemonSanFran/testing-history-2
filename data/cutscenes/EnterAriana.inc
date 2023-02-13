EnterAriana_ObjectCleanUp_Script::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne EnterAriana_ObjectCleanUp_Script_2
EnterAriana_ObjectCleanUp_Script_1:
	return

EnterAriana_ObjectCleanUp_Script_2:
	setobjectxyperm 10, 3, 44
	setobjectxyperm 11, 3, 45
	setobjectxyperm 12, 3, 46
	setflag FLAG_TEMP_2
	goto EnterAriana_ObjectCleanUp_Script_1


EnterAriana_SetConeTiles_Script::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne EnterAriana_SetConeTiles_Script_2
EnterAriana_SetConeTiles_Script_1:
	return

EnterAriana_SetConeTiles_Script_2:
	setmetatile 4, 37, 0x344, TRUE
	setmetatile 4, 43, 0x344, TRUE
	special DrawWholeMapView
	goto EnterAriana_SetConeTiles_Script_1


EnterAriana_InteractSiarl_Script::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne EnterAriana_InteractSiarl_Script_1
	goto EnterAriana_Intro_Dialogue
	return

EnterAriana_InteractSiarl_Script_1:
	goto EnterAriana_GruntApologize_Dialogue
	return


EnterAriana_PreventPlayerProgress_Dialogue::
	lock
	setvar VAR_TEMP_1, 0
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne EnterAriana_PreventPlayerProgress_Dialogue_2
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 38, EnterAriana_PreventPlayerProgress_Dialogue_6
	case 40, EnterAriana_PreventPlayerProgress_Dialogue_7
	case 42, EnterAriana_PreventPlayerProgress_Dialogue_8
EnterAriana_PreventPlayerProgress_Dialogue_4:
	waitmovement 0
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_EnterAriana_NoCutting, MSGBOX_DEFAULT, SPEAKER_RESIDENT_A
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

EnterAriana_PreventPlayerProgress_Dialogue_2:
	release
	end

EnterAriana_PreventPlayerProgress_Dialogue_6:
	applymovement 10, Common_Movement_ExclamationMark
	goto EnterAriana_PreventPlayerProgress_Dialogue_4

EnterAriana_PreventPlayerProgress_Dialogue_7:
	applymovement 11, Common_Movement_ExclamationMark
	goto EnterAriana_PreventPlayerProgress_Dialogue_4

EnterAriana_PreventPlayerProgress_Dialogue_8:
	applymovement 12, Common_Movement_ExclamationMark
	goto EnterAriana_PreventPlayerProgress_Dialogue_4


EnterAriana_Intro_Dialogue::
	lockall
	msgbox gText_EnterAriana_WhoTheHell, MSGBOX_DEFAULT, SPEAKER_SIARL, , EMOTE_ANGRY
	msgbox gText_EnterAriana_NoSorry, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_TryingToHelpEverybody, MSGBOX_DEFAULT, SPEAKER_SIARL, , EMOTE_ANGRY
	msgbox gText_EnterAriana_ImNotInLine, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_SwearToArceus, MSGBOX_DEFAULT, SPEAKER_SIARL, TAIL_SHOUT, EMOTE_ANGRY
	msgbox gText_EnterAriana_WaitListen, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_SHOUT
	msgbox gText_EnterAriana_NoPunk, MSGBOX_DEFAULT, SPEAKER_SIARL, TAIL_SHOUT, EMOTE_ANGRY
	applymovement 1, Common_Movement_FaceDown
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	msgbox gText_EnterAriana_HoldOn, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, EnterAriana_ArianaWalkToPlayer_Movement
	waitmovement 1
	applymovement 2, Common_Movement_FaceRight
	waitmovement 2
	goto EnterAriana_Explain_Dialogue
	return


EnterAriana_Explain_Dialogue::
	msgbox gText_EnterAriana_DidYouListen, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	applymovement 2, Common_Movement_Delay48
	waitmovement 2
	applymovement 2, Common_Movement_FaceRight
	waitmovement 2
	msgbox gText_EnterAriana_TryingToCut, MSGBOX_DEFAULT, SPEAKER_SIARL, , EMOTE_ANGRY
	msgbox gText_EnterAriana_WhatYouHeard, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	msgbox gText_EnterAriana_WhatProblem, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_AsshatInterrupted, MSGBOX_DEFAULT, SPEAKER_ZOEY, , EMOTE_ANGRY
	closemessage
	goto EnterAriana_Apology_Dialogue
	return


EnterAriana_Apology_Dialogue::
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	msgbox gText_EnterAriana_ShouldntTheCones, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_IForgotToSet, MSGBOX_DEFAULT, SPEAKER_SIARL, TAIL_WHISPER, EMOTE_SWEAT
	msgbox gText_EnterAriana_BeratedSomebody, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_Sorry, MSGBOX_DEFAULT, SPEAKER_SIARL
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 1
	msgbox gText_EnterAriana_WhatsYourName, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	msgbox gText_EnterAriana_IGotHeated, , SPEAKER_SIARL
	msgbox gText_EnterAriana_DontRuin, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 2, Common_Movement_FaceRight
	msgbox gText_EnterAriana_ShouldBeNear, , SPEAKER_SIARL
	closemessage
	applymovement 1, EnterAriana_HopOverTable_Movement
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	msgbox gText_EnterAriana_NeedToWalk, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, EnterAriana_WalkToLine_Movement
	applymovement OBJ_EVENT_ID_PLAYER, EnterAriana_PlayerWalkToLine_Movement
	goto EnterAriana_ExplainHope_Dialogue
	return


EnterAriana_ExplainHope_Dialogue::
	msgbox gText_EnterAriana_WhatIsEverybody, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_Hope, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_WaitHope, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_ICanGet, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_ThatsAmazing, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_CityIsntSuperChill, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_ButYoureHelping, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_YoureNotFromHere, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, EnterAriana_PlaceConesA_Movement
	waitmovement 1
	setmetatile 4, 37, 0x344, TRUE
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, EnterAriana_WatchPlaceCones_Movement
	applymovement 1, EnterAriana_PlaceConesB_Movement
	waitmovement 1
	setmetatile 4, 43, 0x344, TRUE
	special DrawWholeMapView
	applymovement 1, EnterAriana_PlaceConesC_Movement
	waitmovement 1
	msgbox gText_EnterAriana_BetweenTheCones, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	call EnterAriana_MoveLine_Script
	goto EnterAriana_GiveKeystone_Dialogue
	return


EnterAriana_MoveLine_Script::
	playse SE_PIN
	applymovement 10, EnterAriana_MoveLine1_Movement
	applymovement 11, EnterAriana_MoveLine1_Movement
	applymovement 12, EnterAriana_MoveLine1_Movement
	waitmovement 0
	setobjectxy 10, 3, 44
	setobjectxy 11, 3, 45
	setobjectxy 12, 3, 46
	setobjectxyperm 10, 3, 44
	setobjectxyperm 11, 3, 45
	setobjectxyperm 12, 3, 46
	return


EnterAriana_GiveKeystone_Dialogue::
	applymovement 1, EnterAriana_FacePlayer_Movement
	waitmovement 1
	msgbox gText_EnterAriana_ThereYouGo, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_AGym, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_WellGoodLuck, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 1
	giveitem ITEM_MEGA_RING
	msgbox gText_EnterAriana_IfYouHaveThat, MSGBOX_DEFAULT, SPEAKER_ARIANA
	special CheckMegaEvolutionPartyMember
	compare VAR_TEMP_1, 6
	goto_if_lt EnterAriana_GiveKeystone_Dialogue_2
EnterAriana_GiveKeystone_Dialogue_1:
	msgbox gText_EnterAriana_ThankYouSo, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterAriana_HopeThatMakes, MSGBOX_DEFAULT, SPEAKER_ARIANA
	msgbox gText_EnterAriana_IGottaGo, MSGBOX_DEFAULT, SPEAKER_ARIANA
	closemessage
	applymovement 1, EnterAriana_WalkAway_Movement
	waitmovement 1
	removeobject 1
	fadedefaultbgm
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end

EnterAriana_GiveKeystone_Dialogue_2:
	switch VAR_TEMP_1
	case 0, EnterAriana_GiveKeystone_Dialogue_6
	case 1, EnterAriana_GiveKeystone_Dialogue_7
	case 2, EnterAriana_GiveKeystone_Dialogue_8
	case 3, EnterAriana_GiveKeystone_Dialogue_9
	case 4, EnterAriana_GiveKeystone_Dialogue_10
	case 5, EnterAriana_GiveKeystone_Dialogue_11
EnterAriana_GiveKeystone_Dialogue_4:
	compare VAR_TEMP_2, 1
	goto_if_ne EnterAriana_GiveKeystone_Dialogue_12
	msgbox gTextEnterAriana_CanMegaEvolveSomeday, MSGBOX_DEFAULT, SPEAKER_ARIANA
	goto EnterAriana_GiveKeystone_Dialogue_1

EnterAriana_GiveKeystone_Dialogue_6:
	bufferpartymonnick 0, 0
	goto EnterAriana_GiveKeystone_Dialogue_4

EnterAriana_GiveKeystone_Dialogue_7:
	bufferpartymonnick 0, 1
	goto EnterAriana_GiveKeystone_Dialogue_4

EnterAriana_GiveKeystone_Dialogue_8:
	bufferpartymonnick 0, 2
	goto EnterAriana_GiveKeystone_Dialogue_4

EnterAriana_GiveKeystone_Dialogue_9:
	bufferpartymonnick 0, 3
	goto EnterAriana_GiveKeystone_Dialogue_4

EnterAriana_GiveKeystone_Dialogue_10:
	bufferpartymonnick 0, 4
	goto EnterAriana_GiveKeystone_Dialogue_4

EnterAriana_GiveKeystone_Dialogue_11:
	bufferpartymonnick 0, 5
	goto EnterAriana_GiveKeystone_Dialogue_4

EnterAriana_GiveKeystone_Dialogue_12:
	msgbox gTextEnterAriana_CanMegaEvolve, MSGBOX_DEFAULT, SPEAKER_ARIANA
	goto EnterAriana_GiveKeystone_Dialogue_1


EnterAriana_GruntApologize_Dialogue::
	msgbox gText_EnterAriana_SorryAgain, MSGBOX_NPC, SPEAKER_SIARL
	end


EnterAriana_ArianaWalkToPlayer_Movement:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

EnterAriana_HopOverTable_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	jump_2_down
	face_left
	step_end

EnterAriana_WalkToLine_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	face_player
	step_end

EnterAriana_PlayerWalkToLine_Movement:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EnterAriana_WatchPlaceCones_Movement:
	face_right
	face_up
	delay_16
	delay_16
	face_down
	step_end

EnterAriana_PlaceConesA_Movement:
	walk_right
	walk_up
	walk_up
	face_left
	walk_in_place_left
	step_end

EnterAriana_PlaceConesB_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	walk_in_place_left
	step_end

EnterAriana_PlaceConesC_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

EnterAriana_MoveLine1_Movement:
	emote_exclamation_mark
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_up
	step_end

EnterAriana_MoveLine2_Movement:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	walk_right
	walk_down
	walk_right
	walk_down
	walk_down
	walk_left
	face_up
	step_end

EnterAriana_MoveLine3_Movement:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	face_up
	step_end

EnterAriana_FacePlayer_Movement:
	walk_left
	face_up
	step_end

EnterAriana_WalkAway_Movement:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_EnterAriana_NoCutting::
	.string "No cutting the line!$"

gText_EnterAriana_WhoTheHell::
	.string "Woah, who the hell do you think you are?$"

gText_EnterAriana_NoSorry::
	.string "No sorry, I'm just trying to get\n"
	.string "through, are you able to -$"

gText_EnterAriana_TryingToHelpEverybody::
	.string "Look, we're trying to help everybody\n"
	.string "here, and we're doing the best we can.\l"
	.string "You gotta get in line like everybody\l"
	.string "else.$"

gText_EnterAriana_ImNotInLine::
	.string "I'm not in line, I'm trying to -$"

gText_EnterAriana_SwearToArceus::
	.string "Trying to get in front! I know! I swear\n"
	.string "to Arceus, you follow the rules like\l"
	.string "everybody else, or you get nothing.$"

gText_EnterAriana_WaitListen::
	.string "Wait, listen to me -$"

gText_EnterAriana_NoPunk::
	.string "NO punk, YOU listen to ME. What the hell\n"
	.string "makes you think -$"

gText_EnterAriana_HoldOn::
	.string "Siarl, hold on.$"

gText_EnterAriana_DidYouListen::
	.string "Siarl, did you listen to them?$"

gText_EnterAriana_TryingToCut::
	.string "Yeah, they're trying to cut the line!$"

gText_EnterAriana_WhatYouHeard::
	.string "Siarl, that's what you heard... but not\n"
	.string "what they said.$"

gText_EnterAriana_WhatProblem::
	.string "Sorry. What seems to be the problem?$"

gText_EnterAriana_AsshatInterrupted::
	.string "Thanks. Before this asshat interrupted\n"
	.string "me, I was trying to explain that your\l"
	.string "line is blocking the road. Nobody can\l"
	.string "get through. Could you do something\l"
	.string "about that?$"

gText_EnterAriana_ShouldntTheCones::
	.string "Damn. Siarl, shouldn't the cones prevent\n"
	.string "that from happening?$"

gText_EnterAriana_IForgotToSet::
	.string "...I forgot to set up the cones.$"

gText_EnterAriana_BeratedSomebody::
	.string "Oh? So, you screwed up, then berated\n"
	.string "somebody when they tried to ask you to\l"
	.string "fix it. Asshat sounds about right.$"

gText_EnterAriana_Sorry::
	.string "...Sorry Ariana.$"

gText_EnterAriana_WhatsYourName::
	.string "What's your name? ...{PLAYER}.$"

gText_EnterAriana_IGotHeated::
	.string "Sorry I got so heated {PLAYER}. It's\n"
	.string "been rough -$"

gText_EnterAriana_DontRuin::
	.string "Siarl, don't ruin a perfectly good\n"
	.string "apology with an excuse. Where are the\l"
	.string "cones?$"

gText_EnterAriana_ShouldBeNear::
	.string "...they should be near the backstock\n"
	.string "pallet.$"

gText_EnterAriana_NeedToWalk::
	.string "I need to walk for a second. Let's walk,\n"
	.string "{PLAYER}.$"

gText_EnterAriana_WhatIsEverybody::
	.string "What is everybody lining up for?$"

gText_EnterAriana_Hope::
	.string "Hope.$"

gText_EnterAriana_WaitHope::
	.string "Wait, hope?$"

gText_EnterAriana_ICanGet::
	.string "Sorry, I can get whimsical sometimes!\n"
	.string "One of the biggest challenges of being\l"
	.string "unhoused is access to food and\l"
	.string "sanitary supplies. My colleagues and I,\l"
	.string "the RocketAcronym, set up around the\l"
	.string "city and hand out kits.$"

gText_EnterAriana_ThatsAmazing::
	.string "Oh wow, that's amazing! But why are you\n"
	.string "in an alleyway?$"

gText_EnterAriana_CityIsntSuperChill::
	.string "The city isn't super chill with us, for\n"
	.string "complicated reasons. We move around a\l"
	.string "lot and choose unconventional\l"
	.string "locations in order to avoid the cops.\l"
	.string "It sucks, but it works.$"

gText_EnterAriana_ButYoureHelping::
	.string "Wait, but you're helping people! Why\n"
	.string "isn't the city supporting you?$"

gText_EnterAriana_YoureNotFromHere::
	.string "Clearly, you're not from here, are you? I\n"
	.string "can't remember a point in my lifetime\l"
	.string "where the city helped people,\l"
	.string "{PLAYER}.$"

gText_EnterAriana_BetweenTheCones::
	.string "Yo, clear a path between the cones.$"

gText_EnterAriana_ThereYouGo::
	.string "There you go. Sorry about all of that.\n"
	.string "What's in Japantown?$"

gText_EnterAriana_AGym::
	.string "A Gym! I'm taking part in the League\n"
	.string "Challenge.$"

gText_EnterAriana_WellGoodLuck::
	.string "Ah, well good luck. Actually... a League\n"
	.string "Challenger that isn't from here... take\l"
	.string "this.$"

gText_EnterAriana_IfYouHaveThat::
	.string "If you have that and your Pokémon is\n"
	.string "holding the appropriate Mega Stone,\l"
	.string "you'll be able to Mega Evolve that\l"
	.string "Pokémon. Most natives aren't chill with\l"
	.string "Mega Evolution, but you can make your\l"
	.string "own decisions.$"

gTextEnterAriana_CanMegaEvolve::
	.string "Your {STR_VAR_1} is capable of Mega\n"
	.string "Evolution, if memory serves me right.$"

gTextEnterAriana_CanMegaEvolveSomeday::
	.string "I'm pretty sure {STR_VAR_1} can do\n"
	.string "it once its fully-evolved!$"

gText_EnterAriana_ThankYouSo::
	.string "That's amazing, thank you so much!$"

gText_EnterAriana_HopeThatMakes::
	.string "Hope that makes up for the hassle. It\n"
	.string "fell off the back of a truck, but you\l"
	.string "can totally have it.$"

gText_EnterAriana_IGottaGo::
	.string "I gotta go back before Siarl cusses out\n"
	.string "another innocent victim. Stay safe out\l"
	.string "there.$"

gText_EnterAriana_SorryAgain::
	.string "Sorry again about before.$"
