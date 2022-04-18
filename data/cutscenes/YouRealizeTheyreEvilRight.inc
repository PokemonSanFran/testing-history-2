YouRealizeTheyreEvilRight_HideObject_Script::
	compare VAR_PSFCAVE7_STATE, 3
	goto_if_ne YouRealizeTheyreEvilRight_HideObject_Script_1
	return

YouRealizeTheyreEvilRight_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return


YouRealizeTheyreEvilRight_ShowObject_Script::
	compare VAR_PSFCAVE7_STATE, 3
	goto_if_eq YouRealizeTheyreEvilRight_ShowObject_Script_1
	return

YouRealizeTheyreEvilRight_ShowObject_Script_1:
	addobject 11
	return


YouRealizeTheyreEvilRight_ShowBasement_Script::
	clearflag FLAG_HIDE_YOUREALIZE_B2F_GROUP
	setflag FLAG_TEMP_1
	return


YouRealizeTheyreEvilRight_HideGarbodor_Script::
	setflag FLAG_TEMP_4
	return


YouRealizeTheyreEvilRight_HideBasement_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	setflag FLAG_TEMP_9
	return


YouRealizeTheyreEvilRight_CallPlayer_Dialogue::
	lock
	addvar VAR_PSFCAVE7_STATE, 1
	giveitem ITEM_HM03
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HolyShit
	callnative ClearMugshot
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitse
	pokenavcall YouRealizeTheyreEvilRight_CallPlayer_Dialogue_Text_0
	waitmessage
	bufferpartymonnick 0, 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_AwesomeJobIn
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TheyDontLove
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YouSeemSurprised
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YoureNot
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IveBeenTrying
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WhatDoYouMean
	checkitem ITEM_HM03
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	compare VAR_RESULT, 0
	goto_if_ne YouRealizeTheyreEvilRight_CallPlayer_Dialogue_2
	msgbox gText_YouRealizeTheyreEvilRight_YoullNeedToCross
YouRealizeTheyreEvilRight_CallPlayer_Dialogue_1:
	playse SE_POKENAV_HANG_UP
	waitse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IDontKnowIf
	callnative ClearMugshot
	closemessage
	release
	end

YouRealizeTheyreEvilRight_CallPlayer_Dialogue_2:
	msgbox gText_YouRealizeTheyreEvilRight_IWannaShowYou
	goto YouRealizeTheyreEvilRight_CallPlayer_Dialogue_1


YouRealizeTheyreEvilRight_PlayerLandedDialogue::
	lock
	givecustommon SPECIES_KYOGRE, 100, ITEM_BLUE_ORB, ITEM_LURE_BALL, NATURE_MODEST, 0, 0, 0, 4, 252, 0, 252, 31, 31, 31, 31, 31, 31, MOVE_SURF, MOVE_CALM_MIND, MOVE_ORIGIN_PULSE, MOVE_ICE_BEAM
	addvar VAR_PSFCAVE7_STATE, 1
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ImHereWhere
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_SwimAroundThe
	callnative ClearMugshot
	closemessage
	playse SE_POKENAV_HANG_UP
	waitse
	release
	end


YouRealizeTheyreEvilRight_InteractPsfnativerival::
	lock
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WelcomeToTheReal, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	applymovement 11, Common_Movement_WalkUp
	waitmovement 0
	playse SE_EXIT
	waitse
	setflag FLAG_TEMP_1
	removeobject 11
	release
	end


YouRealizeTheyreEvil_Ghost1_Battle_Script::
	trainerbattle_single TRAINER_VALERIE_1, gText_YouRealizeTheyreEvilRight_DotDotDot, gText_YouRealizeTheyreEvilRight_DotDotDot, YouRealizeTheyreEvil_Ghost1_Battle_Script
	msgbox gText_YouRealizeTheyreEvilRight_WhileAlcatraz, MSGBOX_AUTOCLOSE
	goto YouRealizeTheyreEvilRight_RemoveGhost
	end


YouRealizeTheyreEvil_Ghost2_Battle_Script::
	trainerbattle_single TRAINER_ATSUSHI, gText_YouRealizeTheyreEvilRight_DotDotDot, gText_YouRealizeTheyreEvilRight_DotDotDot, YouRealizeTheyreEvil_Ghost2_Battle_Script
	msgbox gText_YouRealizeTheyreEvilRight_AsThePrisonPopulation, MSGBOX_AUTOCLOSE
	goto YouRealizeTheyreEvilRight_RemoveGhost
	end


YouRealizeTheyreEvil_Ghost3_Battle_Script::
	trainerbattle_single TRAINER_TASHA, gText_YouRealizeTheyreEvilRight_DotDotDot, gText_YouRealizeTheyreEvilRight_DotDotDot, YouRealizeTheyreEvil_Ghost3_Battle_Script
	msgbox gText_YouRealizeTheyreEvilRight_TheInmateWasAlso, MSGBOX_AUTOCLOSE
	goto YouRealizeTheyreEvilRight_RemoveGhost
	end


YouRealizeTheyreEvil_Ghost4_Battle_Script::
	trainerbattle_single TRAINER_CEDRIC, gText_YouRealizeTheyreEvilRight_DotDotDot, gText_YouRealizeTheyreEvilRight_DotDotDot, YouRealizeTheyreEvil_Ghost4_Battle_Script
	msgbox gText_YouRealizeTheyreEvilRight_TheProtests, MSGBOX_AUTOCLOSE
	goto YouRealizeTheyreEvilRight_RemoveGhost
	end


YouRealizeTheyreEvilRight_RemoveGhost::
	lock
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


YouRealizeTheyreEvil_ReleaseGarbodor_Script::
	applymovement 1, YouRealizeTheyreEvilRight_StepBackward
	waitmovement 0
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_TEMP_4
	addobject 4
	playmoncry SPECIES_GARBODOR, CRY_MODE_ENCOUNTER
	waitmoncry
	playse SE_SHINY
	waitse
	return


YouRealizeTheyreEvilRight_PlayerArrived2F_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, YouRealizeTheyreEvilRight_WalkToGroup
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TheChampionHasArrived
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_NiceToMeetYou
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HasBeenUsing
	callnative ClearMugshot
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	applymovement 2, Common_Movement_ExclamationMark
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WowSuperResourceful
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WhyAreWeHere
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ICanFinallyProve
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DidYouDragMe
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YesWaitNo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DoesntDoAnythingForThis
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ICanProve
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_How
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_Look
	callnative ClearMugshot
	closemessage
	call YouRealizeTheyreEvil_ReleaseGarbodor_Script
	applymovement 2, Common_Movement_FaceLeft
	applymovement 3, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThisIsOne
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IHadToGo
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThisOneIsLevel
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ButTheyDefinitelyCan
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DoesntLearnThatNaturally
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_SoUsedATM
	fadescreen FADE_TO_BLACK
	msgbox YouRealizeTheyreEvilRight_PlayerArrived2F_Dialogue_Text_0
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_NoItMustHaveBeenBred
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TakeACloserLook
	goto YouRealizeTheyreEvilRight_StartQuestions_Script
	return


YouRealizeTheyreEvilRight_StartQuestions_Script::
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DoYouSeeNow, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq YouRealizeTheyreEvilRight_StartQuestions_Script_2
	call YouRealizeTheyreEvilRight_EndQuestions_Script
YouRealizeTheyreEvilRight_StartQuestions_Script_1:
	goto YouRealizeTheyreEvilRight_Framing_Dialogue
	return

YouRealizeTheyreEvilRight_StartQuestions_Script_2:
	call YouRealizeTheyreEvilRight_AskProperties_Script
	goto YouRealizeTheyreEvilRight_StartQuestions_Script_1


YouRealizeTheyreEvilRight_AskProperties_Script::
	msgbox gText_YouRealizeTheyreEvilRight_AhVeryAstute
	multichoicedefault 18, 6, MULTI_GARBADOR_PROPERTIES, 1, FALSE
	switch VAR_RESULT
	case 0, YouRealizeTheyreEvilRight_AskProperties_Script_2
	goto YouRealizeTheyreEvilRight_EndQuestions_Script
	return

YouRealizeTheyreEvilRight_AskProperties_Script_2:
	goto YouRealizeTheyreEvilRight_AskMoves_Script
	return


YouRealizeTheyreEvilRight_AskMoves_Script::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WaitWhichMove
	multichoicedefault 18, 6, MULTI_GARBADOR_MOVES, 0, TRUE
	switch VAR_RESULT
	case 2, YouRealizeTheyreEvilRight_AskMoves_Script_2
	goto YouRealizeTheyreEvilRight_EndQuestions_Script
	return

YouRealizeTheyreEvilRight_AskMoves_Script_2:
	goto YouRealizeTheyreEvilRight_CorrectAnswer_Script
	return


YouRealizeTheyreEvilRight_CorrectAnswer_Script::
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_VeryClever
	setvar VAR_TEMP_0, 99
	goto YouRealizeTheyreEvilRight_Framing_Dialogue
	return


YouRealizeTheyreEvilRight_EndQuestions_Script::
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TheTipOff
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_So
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HazeCanOnly
	return


YouRealizeTheyreEvilRight_Framing_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IDontGetIt
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HasBeenFramingYou
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YouAlsoMetUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ButPsfgoodadminSaid
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YeahNobodyKnows
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WhyWhyDoAll
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ExistsToMakeMoney
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_CantArgueWithThat
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IJoinedThe
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_AndThatsWhyWere
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YepIThinkItsFinally
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_KidIfTheEliteFour
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThingsAreDifferentNow
	callnative ClearMugshot
	closemessage
	applymovement 1, YouRealizeTheyreEvilRight_WalkAroundToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_LookIKnowThis
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YeahOkay
	addvar VAR_PSFCAVE7_STATE, 1
	compare VAR_TEMP_0, 99
	goto_if_eq YouRealizeTheyreEvilRight_Framing_Dialogue_2
YouRealizeTheyreEvilRight_Framing_Dialogue_1:
	callnative ClearMugshot
	closemessage
	end

YouRealizeTheyreEvilRight_Framing_Dialogue_2:
	call YouRealizeTheyreEvilRight_AskPlayerGift_Script
	goto YouRealizeTheyreEvilRight_Framing_Dialogue_1


YouRealizeTheyreEvilRight_AskPlayerGift_Script::
	playse SE_CONTEST_HEART
	applymovement 4, YouRealizeTheyreEvilRight_ShowAffection
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThisGarbodor, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq YouRealizeTheyreEvilRight_AskPlayerGift_Script_2
	call YouRealizeTheyreEvilRight_GiveGift_Script
YouRealizeTheyreEvilRight_AskPlayerGift_Script_1:
	callnative ClearMugshot
	closemessage
	release
	end

YouRealizeTheyreEvilRight_AskPlayerGift_Script_2:
	call YouRealizeTheyreEvilRight_LeaveGift_Script
	goto YouRealizeTheyreEvilRight_AskPlayerGift_Script_1


YouRealizeTheyreEvilRight_LeaveGift_Script::
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThatsFineIll
	return


YouRealizeTheyreEvilRight_GiveGift_Script::
	givecustommon SPECIES_GARBODOR, 40, ITEM_BLACK_SLUDGE, ITEM_CHERISH_BALL, NATURE_JOLLY, 2, 0, 0, 0, 0, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_HAZE, MOVE_SELF_DESTRUCT, MOVE_STOMPING_TANTRUM, MOVE_SLUDGE_BOMB, TRUE
	compare VAR_RESULT, 0
	goto_if_eq YouRealizeTheyreEvilRight_GiveGift_Script_2
	call YouRealizeTheyreEvilRight_SendGiftToPC_Script
YouRealizeTheyreEvilRight_GiveGift_Script_1:
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TakeGoodCare
	return

YouRealizeTheyreEvilRight_GiveGift_Script_2:
	call YouRealizeTheyreEvilRight_SendGiftToParty_Script
	goto YouRealizeTheyreEvilRight_GiveGift_Script_1


YouRealizeTheyreEvilRight_SendGiftToParty_Script::
	call YouRealizeTheyreEvilRight_RecievedGiftFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq YouRealizeTheyreEvilRight_SendGiftToParty_Script_1
	return

YouRealizeTheyreEvilRight_SendGiftToParty_Script_1:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	return


YouRealizeTheyreEvilRight_SendGiftToPC_Script::
	call YouRealizeTheyreEvilRight_RecievedGiftFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq YouRealizeTheyreEvilRight_SendGiftToPC_Script_2
YouRealizeTheyreEvilRight_SendGiftToPC_Script_1:
	call Common_EventScript_TransferredToPC
	return

YouRealizeTheyreEvilRight_SendGiftToPC_Script_2:
	call Common_EventScript_NameReceivedBoxMon
	goto YouRealizeTheyreEvilRight_SendGiftToPC_Script_1


YouRealizeTheyreEvilRight_RecievedGiftFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_GARBODOR
	removeobject 4
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_YouRealizeTheyreEvilRight_ObtainedGift
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_GARBODOR
	return


YouRealizeTheyreEvilRight_CantSleep_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IsStillWaiting
	callnative ClearMugshot
	closemessage
	release
	end


YouRealizeTheyreEvilRight_NoIdea_Dialogue::
	fadescreen FADE_FROM_BLACK
	addvar VAR_STORYLINE_STATE, 1
	goto_if_set FLAG_TIMELINE_TIMETRAVEL, YouRealizeTheyreEvilRight_NoIdea_Dialogue_2
YouRealizeTheyreEvilRight_NoIdea_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IHaveNoIdeaWhat
	callnative ClearMugshot
	closemessage
	return

YouRealizeTheyreEvilRight_NoIdea_Dialogue_2:
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OkayLetsFixIt_PaceNightmare
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OkayLetsFixIt_WhatTheHell
	goto YouRealizeTheyreEvilRight_NoIdea_Dialogue_1


YouRealizeTheyreEvilRight_StepBackward:
	lock_facing_direction
	walk_up
	walk_in_place_down
	unlock_facing_direction
	step_end

YouRealizeTheyreEvilRight_WalkToGroup:
	walk_right
	walk_right
	walk_up
	step_end

YouRealizeTheyreEvilRight_WalkAroundToPlayer:
	walk_left
	walk_down
	walk_down
	face_right
	step_end

YouRealizeTheyreEvilRight_ShowAffection:
	emote_heart
	jump_in_place_down
	jump_in_place_down
	step_end

YouRealizeTheyreEvilRight_CallPlayer_Dialogue_Text_0:
	.string "This phone is ringing.$"

YouRealizeTheyreEvilRight_PlayerArrived2F_Dialogue_Text_0:
	.string "This will show a flashback to the police\n"
	.string "chief explaining that TMs were taken\l"
	.string "out of circulation$"

gText_YouRealizeTheyreEvilRight_HolyShit::
	.string "Holy shit. That was intense. Guess I\n"
	.string "need to think all this over, but\l"
	.string "something isn't adding up.$"

gText_YouRealizeTheyreEvilRight_AwesomeJobIn::
	.string "Awesome job in {STR_VAR_1}. I heard\n"
	.string "all about it, and I'm so happy things\l"
	.string "are getting off the ground. I heard you\l"
	.string "got a phone call and disappeared.\l"
	.string "Everything okay?$"

gText_YouRealizeTheyreEvilRight_TheyDontLove::
	.string "Psfbadguy called me. They don't love\n"
	.string "our project.$"

gText_YouRealizeTheyreEvilRight_YouSeemSurprised::
	.string "You seem surprised.$"

gText_YouRealizeTheyreEvilRight_YoureNot::
	.string "You're not?$"

gText_YouRealizeTheyreEvilRight_IveBeenTrying::
	.string "I've been trying to tell you the whole\n"
	.string "time, these guys are ruthless. Cruel,\l"
	.string "even. Good timing though, I think I can\l"
	.string "finally explain everything to you.$"

gText_YouRealizeTheyreEvilRight_WhatDoYouMean::
	.string "What do you mean?$"

gText_YouRealizeTheyreEvilRight_IWannaShowYou::
	.string "I wanna show you instead. Come to\n"
	.string "Psfcave7.$"

gText_YouRealizeTheyreEvilRight_YoullNeedToCross::
	.string "I wanna show you but you'll need to\n"
	.string "cross some water to get here. You know\l"
	.string "how to Surf, right? No? Go learn from\l"
	.string "the Surfers in Psfcity4, and then meet\l"
	.string "me on Psfcave7.$"

gText_YouRealizeTheyreEvilRight_IDontKnowIf::
	.string "(I don't know if I can afford to get\n"
	.string "pulled any deeper into this…)$"

gText_YouRealizeTheyreEvilRight_ImHereWhere::
	.string "I'm here! Where are you?$"

gText_YouRealizeTheyreEvilRight_SwimAroundThe::
	.string "Come swim around the southwest side of\n"
	.string "the island! You'll see me.$"

gText_YouRealizeTheyreEvilRight_WelcomeToTheReal::
	.string "Welcome to the real Psfcave7. I'm going\n"
	.string "down to the second level, but you\l"
	.string "should explore here first before\l"
	.string "coming straight down.$"

gText_YouRealizeTheyreEvilRight_DotDotDot::
	.string "…$"

gText_YouRealizeTheyreEvilRight_WhileAlcatraz::
	.string "While Alcatraz was a prison, it was\n"
	.string "absolutely not a state of the art\l"
	.string "facility - rather, criminals deemed\l"
	.string "“dangerous” were thrown into Alcatraz\l"
	.string "with little regard for health,\l"
	.string "rehabilitation, or even due process of\l"
	.string "law, with a preponderance of\l"
	.string "marginalized communities being locked\l"
	.string "away.$"

gText_YouRealizeTheyreEvilRight_AsThePrisonPopulation::
	.string "As the prison population grew, pressure\n"
	.string "mounted both internally and externally\l"
	.string "in order to demand a better quality of\l"
	.string "life for the prisoners. The prison riot\l"
	.string "that started the occupation of the\l"
	.string "island came from an out of control\l"
	.string "guard killing an inmate for a minor\l"
	.string "violation.$"

gText_YouRealizeTheyreEvilRight_TheInmateWasAlso::
	.string "The inmate was also a member of\n"
	.string "SanFran's indingeous population, killed\l"
	.string "on the land that was stolen from their\l"
	.string "ancestors. The occupation called for\l"
	.string "the dissolution of the prison, transfer\l"
	.string "of prisoners to locations with humane\l"
	.string "conditions, and the return of the land\l"
	.string "back to its original owners.$"

gText_YouRealizeTheyreEvilRight_TheProtests::
	.string "The protests gained national attention\n"
	.string "and seemed to be gathering interest,\l"
	.string "particularly with the help of\l"
	.string "Psfelite2's support, and pressure\l"
	.string "mounted on the government to comply.\l"
	.string "At the height of tension, an\l"
	.string "earthquake broke out, destroying a\l"
	.string "large portion of the prison and killing\l"
	.string "inmates and guards and effectively\l"
	.string "ending the occupation.$"

gText_YouRealizeTheyreEvilRight_TheChampionHasArrived::
	.string "The Champion has arrived! Great to meet\n"
	.string "you, I'm Psfelite2, and I'm the leader\l"
	.string "of the Psfregion1 Elite Four. Or, I was.\l"
	.string "Now I'm not really sure what I do.$"

gText_YouRealizeTheyreEvilRight_NiceToMeetYou::
	.string "Nice to meet you! …Psfnativerival,\n"
	.string "where are we?$"

gText_YouRealizeTheyreEvilRight_HasBeenUsing::
	.string "Psfgoodteam has been using Psfcave's\n"
	.string "abandoned prison as a training ground.$"

gText_YouRealizeTheyreEvilRight_WowSuperResourceful::
	.string "Wow! Super resourceful. Genius, even.$"

gText_YouRealizeTheyreEvilRight_WhyAreWeHere::
	.string "Why are we here?$"

gText_YouRealizeTheyreEvilRight_ICanFinallyProve::
	.string "I can finally prove that Psfbadguy is\n"
	.string "worse than we originally thought. Once\l"
	.string "I do that, I want all of us to find a way\l"
	.string "to work together to protect\l"
	.string "Psfregion1 from their bullshit.$"

gText_YouRealizeTheyreEvilRight_DidYouDragMe::
	.string "Did you drag me out here to join a\n"
	.string "terrorist organiziation? Did you hear\l"
	.string "ANYTHING I said on the phone?$"

gText_YouRealizeTheyreEvilRight_YesWaitNo::
	.string "Yes! Wait, no… No, Yes!$"

gText_YouRealizeTheyreEvilRight_DoesntDoAnythingForThis::
	.string "Psfgoodteam doesn't do anything for\n"
	.string "this region. You're attacking innocent\l"
	.string "people, trying to destroy buildings -\l"
	.string "fuck, I absolutely should have turned\l"
	.string "you in!$"

gText_YouRealizeTheyreEvilRight_ICanProve::
	.string "{PLAYER}, listen! I can prove that\n"
	.string "none of that is true.$"

gText_YouRealizeTheyreEvilRight_How::
	.string "How?!?$"

gText_YouRealizeTheyreEvilRight_Look::
	.string "Look.$"

gText_YouRealizeTheyreEvilRight_ThisIsOne::
	.string "This is one of the Garbodor from the\n"
	.string "Psfplace14 strike. {PLAYER}, you\l"
	.string "were told that Psfgoodteam planted\l"
	.string "these to blow up the construction\l"
	.string "site, right?$"

gText_YouRealizeTheyreEvilRight_IHadToGo::
	.string "Yeah. Psftransrival and I had to go\n"
	.string "down there and defeat them and your\l"
	.string "goons.$"

gText_YouRealizeTheyreEvilRight_ThisOneIsLevel::
	.string "This one is Level 40. Garbodor learns\n"
	.string "Explosion at Level 53.$"

gText_YouRealizeTheyreEvilRight_ButTheyDefinitelyCan::
	.string "But they definitely can explode… so\n"
	.string "they're using Self-Destruct instead,\l"
	.string "right?$"

gText_YouRealizeTheyreEvilRight_DoesntLearnThatNaturally::
	.string "Right. But Garbodor doesn't learn that\n"
	.string "naturally. It can only be inherited\l"
	.string "from its parents, or taught via a\l"
	.string "Technical Machine.$"

gText_YouRealizeTheyreEvilRight_SoUsedATM::
	.string "Okay, so Psfgoodteam used a TM… wait.$"

gText_YouRealizeTheyreEvilRight_NoItMustHaveBeenBred::
	.string "No, it must have been bred then.$"

gText_YouRealizeTheyreEvilRight_TakeACloserLook::
	.string "Take a closer look.$"

gText_YouRealizeTheyreEvilRight_DoYouSeeNow::
	.string "Do you see now?$"

gText_YouRealizeTheyreEvilRight_AhVeryAstute::
	.string "Ah, very astute. What seemed off to\n"
	.string "you?$"

gText_YouRealizeTheyreEvilRight_WaitWhichMove::
	.string "Wait, which move tipped you off?$"

gText_YouRealizeTheyreEvilRight_VeryClever::
	.string "Very clever, {PLAYER}! You realized\n"
	.string "that Haze can only be passed down from\l"
	.string "the Yamask family, and Yamask can't\l"
	.string "learn Self-Destruct. This Garbrador\l"
	.string "had to learn the move via TM.$"

gText_YouRealizeTheyreEvilRight_TheTipOff::
	.string "The tip-off is that this Garbodor knows\n"
	.string "Haze.$"

gText_YouRealizeTheyreEvilRight_So::
	.string "…so?$"

gText_YouRealizeTheyreEvilRight_HazeCanOnly::
	.string "Haze can only be passed down from the\n"
	.string "Yamask family, and Yamask can't learn\l"
	.string "Self-Destruct. This Garbrador had to\l"
	.string "learn the move via TM.$"

gText_YouRealizeTheyreEvilRight_IDontGetIt::
	.string "I don't get it then. So this Garbodor\n"
	.string "was taught Self-Destruct. What does\l"
	.string "that mean?$"

gText_YouRealizeTheyreEvilRight_HasBeenFramingYou::
	.string "Psfnativerival… Psfbadguy has been\n"
	.string "framing you?$"

gText_YouRealizeTheyreEvilRight_YouAlsoMetUp::
	.string "{PLAYER}, you also met up with\n"
	.string "Psfgoodteam in Psfcity9 too, right?$"

gText_YouRealizeTheyreEvilRight_ButPsfgoodadminSaid::
	.string "…yeah. But Psfgoodadmin said that\n"
	.string "situation was super weird and was\l"
	.string "trying to track them down.$"

gText_YouRealizeTheyreEvilRight_YeahNobodyKnows::
	.string "Yeah, nobody knows who they are or\n"
	.string "where they came from. I'm pretty sure\l"
	.string "Psfbadguy has been sending in agents\l"
	.string "to make us look shitty. Between that\l"
	.string "and whatever else Psfbadguy is\l"
	.string "feeding you, I'm not surprised you feel\l"
	.string "the way you do.$"

gText_YouRealizeTheyreEvilRight_WhyWhyDoAll::
	.string "Why? Why do all this to just to screw\n"
	.string "with you guys?$"

gText_YouRealizeTheyreEvilRight_ExistsToMakeMoney::
	.string "Psfbadguy exists to make money. They\n"
	.string "don't care about you. Or us. Or the\l"
	.string "region. You weren't here when they\l"
	.string "first bought the League. They were\l"
	.string "ruthless. Fired thousands of people,\l"
	.string "dismantled and reshaped communities -\l"
	.string "all for their agenda.$"

gText_YouRealizeTheyreEvilRight_CantArgueWithThat::
	.string "Can't argue with that.$"

gText_YouRealizeTheyreEvilRight_IJoinedThe::
	.string "I joined the League Challenge to try to\n"
	.string "change things from the inside. But now\l"
	.string "I'm certain that we need external\l"
	.string "pressure in order to improve things for\l"
	.string "all of us.$"

gText_YouRealizeTheyreEvilRight_AndThatsWhyWere::
	.string "And that's why we're all here?$"

gText_YouRealizeTheyreEvilRight_YepIThinkItsFinally::
	.string "Yep. I think it's finally time we all come\n"
	.string "together to expose Psfbadguy for the\l"
	.string "assholes that they are, and start to\l"
	.string "take power back for the people.$"

gText_YouRealizeTheyreEvilRight_KidIfTheEliteFour::
	.string "Kid, if the Elite Four couldn't stop them\n"
	.string "in their prime, I don't know what you\l"
	.string "think Psfgoodteam will be able to do.\l"
	.string "Matter of fact, going solo might\l"
	.string "actually be better! Hell, I was able to\l"
	.string "start the Psfcave7 campaigns without\l"
	.string "any help.$"

gText_YouRealizeTheyreEvilRight_ThingsAreDifferentNow::
	.string "Look Psfelite2… things are different\n"
	.string "now. We've been fighting the good fight\l"
	.string "without any help so far… and look where\l"
	.string "that's gotten us. Perhaps they're onto\l"
	.string "something, and it's time for some real\l"
	.string "collective action.$"

gText_YouRealizeTheyreEvilRight_LookIKnowThis::
	.string "Look, I know this is a lot of information\n"
	.string "to take in. I know you're going to make\l"
	.string "the right decision. Go home. Get some\l"
	.string "sleep. Come back here when you're ready\l"
	.string "to work with us, okay?$"

gText_YouRealizeTheyreEvilRight_YeahOkay::
	.string "Yeah… okay.$"

gText_YouRealizeTheyreEvilRight_ThisGarbodor::
	.string "Hey, this Garbodor seems to have taken\n"
	.string "a liking to you, and you seem to\l"
	.string "understand it pretty well. Do you want\l"
	.string "it?$"

gText_YouRealizeTheyreEvilRight_TakeGoodCare::
	.string "Take good care of it.$"

gText_YouRealizeTheyreEvilRight_ThatsFineIll::
	.string "That's fine, I'll find a good home for it.$"

gText_YouRealizeTheyreEvilRight_IsStillWaiting::
	.string "Psfnativerival is still waiting for me at\n"
	.string "Psfcave7…$"

gText_YouRealizeTheyreEvilRight_DoYouWantToGo::
	.string "Do you want to go to bed?$"

gText_YouRealizeTheyreEvilRight_IHaveNoIdeaWhat::
	.string "…I have no idea what I'm going to do. Do\n"
	.string "I help Psfbadguy and the police end\l"
	.string "Psfgoodteam permanently? Or do I help\l"
	.string "Psfgoodteam clear their name and help\l"
	.string "the people of Psfregion1?$"

gText_YouRealizeTheyreEvilRight_ObtainedGift::
	.string "{PLAYER} was given the\n"
	.string "{STR_VAR_2}.$"
