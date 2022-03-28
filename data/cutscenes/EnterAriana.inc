EnterPsfgoodadmin_ObjectCleanUp_Script::
	setobjectxyperm 6, 2, 40
	setobjectxyperm 7, 2, 41
	setobjectxyperm 10, 2, 42
	setflag FLAG_TEMP_2
	return


EnterPsfgoodadmin_SetConeTiles_Script::
	setmetatile 3, 37, 0x2E9, TRUE
	setmetatile 3, 39, 0x2E9, TRUE
	special DrawWholeMapView
	return


EnterPsfgoodadmin_InteractSiarl_Script::
	checkitem ITEM_MEGA_RING, 1
	compare VAR_RESULT, 0
	goto_if_ne EnterPsfgoodadmin_InteractSiarl_Script_1
	goto EnterPsfgoodadmin_Intro_Dialogue
	return

EnterPsfgoodadmin_InteractSiarl_Script_1:
	goto EnterPsfgoodadmin_GruntApologize_Dialogue
	return


EnterPsfgoodadmin_Intro_Dialogue::
	lockall
	msgbox gText_EnterPsfgoodadmin_WhoTheHell
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_NoSorry
	callnative ClearMugshot
	msgbox gText_EnterPsfgoodadmin_TryingToHelpEverybody
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ImNotInLine
	callnative ClearMugshot
	msgbox gText_EnterPsfgoodadmin_SwearToArceus
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WaitListen
	callnative ClearMugshot
	msgbox gText_EnterPsfgoodadmin_NoPunk
	applymovement 1, Common_Movement_FaceDown
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_HoldOn
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPsfgoodadmin_PsfgoodadminWalkToPlayer_Movement
	waitmovement 0
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	goto EnterPsfgoodadmin_Explain_Dialogue
	return


EnterPsfgoodadmin_Explain_Dialogue::
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_DidYouListen
	closemessage
	callnative ClearMugshot
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_EnterPsfgoodadmin_TryingToCut
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WhatYouHeard
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WhatProblem
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_AsshatInterrupted
	callnative ClearMugshot
	closemessage
	goto EnterPsfgoodadmin_Apology_Dialogue
	return


EnterPsfgoodadmin_Apology_Dialogue::
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ShouldntTheCones
	callnative ClearMugshot
	msgbox gText_EnterPsfgoodadmin_IForgotToSet
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_BeratedSomebody
	callnative ClearMugshot
	msgbox gText_EnterPsfgoodadmin_Sorry
	closemessage
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WhatsYourName
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 0
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_EnterPsfgoodadmin_IGotHeated
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_DontRuin
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceRight
	msgbox gText_EnterPsfgoodadmin_ShouldBeNear
	closemessage
	applymovement 1, EnterPsfgoodadmin_HopOverTable_Movement
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_NeedToWalk
	callnative ClearMugshot
	closemessage
	applymovement 1, EnterPsfgoodadmin_WalkToLine_Movement
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfgoodadmin_PlayerWalkToLine_Movement
	goto EnterPsfgoodadmin_ExplainHope_Dialogue
	return


EnterPsfgoodadmin_ExplainHope_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WhatIsEverybody
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_Hope
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WaitHope
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ICanGet
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ThatsAmazing
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_CityIsntSuperChill
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ButYoureHelping
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_YoureNotFromHere
	callnative ClearMugshot
	closemessage
	applymovement 1, EnterPsfgoodadmin_PlaceConesA_Movement
	waitmovement 0
	setmetatile 3, 37, 0x2E9, TRUE
	special DrawWholeMapView
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfgoodadmin_WatchPlaceCones_Movement
	applymovement 1, EnterPsfgoodadmin_PlaceConesB_Movement
	waitmovement 0
	setmetatile 3, 39, 0x2E9, TRUE
	special DrawWholeMapView
	applymovement 1, EnterPsfgoodadmin_PlaceConesC_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_BetweenTheCones
	callnative ClearMugshot
	closemessage
	call LineMovementEvent_Script
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue
	return


LineMovementEvent_Script::
	playse SE_PIN
	applymovement 6, EnterPsfgoodadmin_MoveLine1_Movement
	applymovement 7, EnterPsfgoodadmin_MoveLine2_Movement
	applymovement 10, EnterPsfgoodadmin_MoveLine3_Movement
	waitmovement 0
	setobjectxy 6, 2, 40
	setobjectxy 7, 2, 41
	setobjectxy 10, 2, 42
	setobjectxyperm 6, 2, 40
	setobjectxyperm 7, 2, 41
	setobjectxyperm 10, 2, 42
	return


EnterPsfgoodadmin_GiveKeystone_Dialogue::
	applymovement 1, Common_Movement_WalkLeft
	applymovement 1, Common_Movement_FacePlayer
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ThereYouGo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_AGym
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_WellGoodLuck
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	giveitem ITEM_MEGA_RING
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_IfYouHaveThat
	special CheckMegaEvolutionPartyMember
	compare VAR_TEMP_1, 6
	goto_if_lt EnterPsfgoodadmin_GiveKeystone_Dialogue_2
EnterPsfgoodadmin_GiveKeystone_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_ThankYouSo
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_HopeThatMakes
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_EnterPsfgoodadmin_IGottaGo
	callnative ClearMugshot
	closemessage
	applymovement 1, Psfgoodadmin_WalkAway
	waitmovement 0
	removeobject 1
	fadedefaultbgm
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end

EnterPsfgoodadmin_GiveKeystone_Dialogue_2:
	switch VAR_TEMP_1
	case 0, EnterPsfgoodadmin_GiveKeystone_Dialogue_6
	case 1, EnterPsfgoodadmin_GiveKeystone_Dialogue_7
	case 2, EnterPsfgoodadmin_GiveKeystone_Dialogue_8
	case 3, EnterPsfgoodadmin_GiveKeystone_Dialogue_9
	case 4, EnterPsfgoodadmin_GiveKeystone_Dialogue_10
	case 5, EnterPsfgoodadmin_GiveKeystone_Dialogue_11
EnterPsfgoodadmin_GiveKeystone_Dialogue_4:
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	compare VAR_TEMP_2, 1
	goto_if_ne EnterPsfgoodadmin_GiveKeystone_Dialogue_12
	msgbox gTextEnterPsfgoodadmin_CanMegaEvolveSomeday
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_1

EnterPsfgoodadmin_GiveKeystone_Dialogue_6:
	bufferpartymonnick 0, 0
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_4

EnterPsfgoodadmin_GiveKeystone_Dialogue_7:
	bufferpartymonnick 0, 1
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_4

EnterPsfgoodadmin_GiveKeystone_Dialogue_8:
	bufferpartymonnick 0, 2
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_4

EnterPsfgoodadmin_GiveKeystone_Dialogue_9:
	bufferpartymonnick 0, 3
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_4

EnterPsfgoodadmin_GiveKeystone_Dialogue_10:
	bufferpartymonnick 0, 4
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_4

EnterPsfgoodadmin_GiveKeystone_Dialogue_11:
	bufferpartymonnick 0, 5
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_4

EnterPsfgoodadmin_GiveKeystone_Dialogue_12:
	msgbox gTextEnterPsfgoodadmin_CanMegaEvolve
	goto EnterPsfgoodadmin_GiveKeystone_Dialogue_1


EnterPsfgoodadmin_GruntApologize_Dialogue::
	lockall
	msgbox gText_EnterPsfgoodadmin_SorryAgain
	closemessage
	releaseall
	end


EnterPsfgoodadmin_PsfgoodadminWalkToPlayer_Movement:
	walk_down
	walk_down
	walk_down
	face_left
	step_end

EnterPsfgoodadmin_HopOverTable_Movement:
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

EnterPsfgoodadmin_WalkToLine_Movement:
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
	walk_left
	walk_left
	walk_left
	face_player
	step_end

EnterPsfgoodadmin_PlayerWalkToLine_Movement:
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
	walk_left
	walk_left
	face_up
	step_end

EnterPsfgoodadmin_WatchPlaceCones_Movement:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	walk_right
	face_down
	step_end

EnterPsfgoodadmin_PlaceConesA_Movement:
	walk_right
	face_left
	walk_in_place_left
	step_end

EnterPsfgoodadmin_PlaceConesB_Movement:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_in_place_left
	step_end

EnterPsfgoodadmin_PlaceConesC_Movement:
	walk_right
	face_left
	step_end

EnterPsfgoodadmin_MoveLine1_Movement:
	emote_exclamation_mark
	walk_down
	walk_down
	walk_down
	face_up
	step_end

EnterPsfgoodadmin_MoveLine2_Movement:
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

EnterPsfgoodadmin_MoveLine3_Movement:
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

Psfgoodadmin_LookAround_Movement:
	step_end

Psfgoodadmin_WalkAway:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_EnterPsfgoodadmin_WhoTheHell::
	.string "Woah, who the hell do you think you are?$"

gText_EnterPsfgoodadmin_NoSorry::
	.string "No sorry, I'm just trying to get\n"
	.string "through, are you able to -$"

gText_EnterPsfgoodadmin_TryingToHelpEverybody::
	.string "Look, we're trying to help everybody\n"
	.string "here, and we're doing the best we can.\l"
	.string "You gotta get in line like everybody\l"
	.string "else.$"

gText_EnterPsfgoodadmin_ImNotInLine::
	.string "I'm not in line, I'm trying to -$"

gText_EnterPsfgoodadmin_SwearToArceus::
	.string "Trying to get in front! I know! I swear\n"
	.string "to Arceus, you follow the rules like\l"
	.string "everybody else, or you get nothing.$"

gText_EnterPsfgoodadmin_WaitListen::
	.string "Wait, listen to me -$"

gText_EnterPsfgoodadmin_NoPunk::
	.string "NO punk, YOU listen to ME. What the hell\n"
	.string "makes you think -$"

gText_EnterPsfgoodadmin_HoldOn::
	.string "Siarl, hold on.$"

gText_EnterPsfgoodadmin_DidYouListen::
	.string "Siarl, did you listen to them?$"

gText_EnterPsfgoodadmin_TryingToCut::
	.string "Yeah, they're trying to cut the line!$"

gText_EnterPsfgoodadmin_WhatYouHeard::
	.string "Siarl, that's what you heard... but not\n"
	.string "what they said.$"

gText_EnterPsfgoodadmin_WhatProblem::
	.string "Sorry. What seems to be the problem?$"

gText_EnterPsfgoodadmin_AsshatInterrupted::
	.string "Thanks. Before this asshat interrupted\n"
	.string "me, I was trying to explain that your\l"
	.string "line is blocking the road. Nobody can\l"
	.string "get through. Could you do something\l"
	.string "about that?$"

gText_EnterPsfgoodadmin_ShouldntTheCones::
	.string "Damn. Siarl, shouldn't the cones prevent\n"
	.string "that from happening?$"

gText_EnterPsfgoodadmin_IForgotToSet::
	.string "...I forgot to set up the cones.$"

gText_EnterPsfgoodadmin_BeratedSomebody::
	.string "Oh? So, you screwed up, then berated\n"
	.string "somebody when they tried to ask you to\l"
	.string "fix it. Asshat sounds about right.$"

gText_EnterPsfgoodadmin_Sorry::
	.string "...Sorry Psfgoodadmin.$"

gText_EnterPsfgoodadmin_WhatsYourName::
	.string "What's your name? ...{PLAYER}.$"

gText_EnterPsfgoodadmin_IGotHeated::
	.string "Sorry I got so heated {PLAYER}. It's\n"
	.string "been rough -$"

gText_EnterPsfgoodadmin_DontRuin::
	.string "Siarl, don't ruin a perfectly good\n"
	.string "apology with an excuse. Where are the\l"
	.string "cones?$"

gText_EnterPsfgoodadmin_ShouldBeNear::
	.string "...they should be near the backstock\n"
	.string "pallet.$"

gText_EnterPsfgoodadmin_NeedToWalk::
	.string "I need to walk for a second. Let's walk,\n"
	.string "{PLAYER}.$"

gText_EnterPsfgoodadmin_WhatIsEverybody::
	.string "What is everybody lining up for?$"

gText_EnterPsfgoodadmin_Hope::
	.string "Hope.$"

gText_EnterPsfgoodadmin_WaitHope::
	.string "Wait, hope?$"

gText_EnterPsfgoodadmin_ICanGet::
	.string "Sorry, I can get whimsical sometimes!\n"
	.string "One of the biggest challenges of being\l"
	.string "unhoused is access to food and\l"
	.string "sanitary supplies. My colleagues and I,\l"
	.string "the Psfrocketacro, set up around the\l"
	.string "city and hand out kits.$"

gText_EnterPsfgoodadmin_ThatsAmazing::
	.string "Oh wow, that's amazing! But why are you\n"
	.string "in an alleyway?$"

gText_EnterPsfgoodadmin_CityIsntSuperChill::
	.string "The city isn't super chill with us, for\n"
	.string "complicated reasons. We move around a\l"
	.string "lot and choose unconventional\l"
	.string "locations in order to avoid the cops.\l"
	.string "It sucks, but it works.$"

gText_EnterPsfgoodadmin_ButYoureHelping::
	.string "Wait, but you're helping people! Why\n"
	.string "isn't the city supporting you?$"

gText_EnterPsfgoodadmin_YoureNotFromHere::
	.string "Clearly, you're not from here, are you? I\n"
	.string "can't remember a point in my lifetime\l"
	.string "where the city helped people,\l"
	.string "{PLAYER}.$"

gText_EnterPsfgoodadmin_BetweenTheCones::
	.string "Yo, if you're between the cones, move\n"
	.string "behind the second one. Wanna make sure\l"
	.string "there's a path for people to get\l"
	.string "through.$"

gText_EnterPsfgoodadmin_ThereYouGo::
	.string "There you go. Sorry about all of that.\n"
	.string "What's in Psfcity14?$"

gText_EnterPsfgoodadmin_AGym::
	.string "A Gym! I'm taking part in the League\n"
	.string "Challenge.$"

gText_EnterPsfgoodadmin_WellGoodLuck::
	.string "Ah, well good luck. Actually... a League\n"
	.string "Challenger that isn't from here... take\l"
	.string "this.$"

gText_EnterPsfgoodadmin_IfYouHaveThat::
	.string "If you have that and your Pokémon is\n"
	.string "holding the appropriate Mega Stone,\l"
	.string "you'll be able to Mega Evolve that\l"
	.string "Pokémon. Most natives aren't chill with\l"
	.string "Mega Evolution, but you can make your\l"
	.string "own decisions.$"

gTextEnterPsfgoodadmin_CanMegaEvolve::
	.string "Your {STR_VAR_1} is capable of Mega\n"
	.string "Evolution, if memory serves me right.$"

gTextEnterPsfgoodadmin_CanMegaEvolveSomeday::
	.string "I'm pretty sure {STR_VAR_1} can do\n"
	.string "it once its fully-evolved!$"

gText_EnterPsfgoodadmin_ThankYouSo::
	.string "That's amazing, thank you so much!$"

gText_EnterPsfgoodadmin_HopeThatMakes::
	.string "Hope that makes up for the hassle. I\n"
	.string "found it earlier, but you can totally\l"
	.string "have it. Some tech bro was probably\l"
	.string "being careless.$"

gText_EnterPsfgoodadmin_IGottaGo::
	.string "I gotta go back before Siarl cusses out\n"
	.string "another innocent victim. Stay safe out\l"
	.string "there.$"

gText_EnterPsfgoodadmin_SorryAgain::
	.string "Sorry again about before.$"
