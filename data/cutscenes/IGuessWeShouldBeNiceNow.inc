IGuessWeShouldBeNiceNow_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


IGuessWeShouldBeNiceNow_ObjectSetup_Script::
	setflag FLAG_TEMP_2
	return


IGuessWeShouldBeNiceNow_PuzzlePrepareObject_Script::
	setobjectxy 1, 8, 23
	setobjectxyperm 1, 8, 23
	setflag FLAG_TEMP_2
	return


IGuessWeShouldBeNiceNow_PuzzleStartObject_Script::
	setobjectxy 1, 15, 19
	setobjectxyperm 1, 15, 19
	setflag FLAG_TEMP_2
	return


IGuessWeShouldBeNiceNow_PuzzleBSolvedObject_Script::
	setobjectxy 1, 8, 6
	setobjectxyperm 1, 8, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectxy 5, 7, 9
	setobjectxyperm 5, 7, 9
	return


IGuessWeShouldBeNiceNow_PostCleanUp_Script::
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_1
	setobjectxy 5, 7, 9
	setobjectxyperm 5, 7, 9
	return


IGuessWeShouldBeNiceNow_BiancaInteract_Event_Script::
	lock
	faceplayer
	switch VAR_ROBINWILLIAMSTUNNEL_STATE
	case BIANCA_EXPLAINED_PUZZLE, IGuessWeShouldBeNiceNow_BiancaInteract_Event_Script_2
	case PUZZLE_2_SOLVED, IGuessWeShouldBeNiceNow_BiancaInteract_Event_Script_3
	return

IGuessWeShouldBeNiceNow_BiancaInteract_Event_Script_2:
	goto IGuessWeShouldBeNiceNow_AskPlayer_Script
	return

IGuessWeShouldBeNiceNow_BiancaInteract_Event_Script_3:
	goto IGuessWeShouldBeNiceNow_ReadyPlayer_Dialogue
	return


IGuessWeShouldBeNiceNow_FirstEnterMaze_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 1, IGuessWeShouldBeNiceNow_WalkToPlayer
	waitmovement 0
	msgbox gText_IGuessWeShouldBeNiceNow_TookLongEnough, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_WeCantComplete, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_OhShitWellUh, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_YouAlreadyKnow, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_ThatsFineWellLive, , SPEAKER_BIANCA
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	msgbox gText_IGuessWeShouldBeNiceNow_IAnalyzedTheRoom, , SPEAKER_BIANCA
	applymovement 1, Common_Movement_FaceLeft
	msgbox gText_IGuessWeShouldBeNiceNow_YouSolvePuzzleA, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_AndThenISolvePuzzle, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_ICouldOnlyAnalyze, , SPEAKER_BIANCA
	closemessage
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, BIANCA_EXPLAINED_PUZZLE
	goto IGuessWeShouldBeNiceNow_AskPlayer_Script
	return


IGuessWeShouldBeNiceNow_AskPlayer_Script::
	lock
	msgbox gText_IGuessWeShouldBeNiceNow_Ready, MSGBOX_YESNO, , SPEAKER_BIANCA
	compare VAR_RESULT, NO
	goto_if_eq IGuessWeShouldBeNiceNow_AskPlayer_Script_1
	goto IGuessWeShouldBeNiceNow_StartPuzzle_Script
	return

IGuessWeShouldBeNiceNow_AskPlayer_Script_1:
	goto IGuessWeShouldBeNiceNow_PreparePlayer_Dialogue
	return


IGuessWeShouldBeNiceNow_PreparePlayer_Dialogue::
	msgbox gText_IGuessWeShouldBeNiceNow_WellGoGetReady, , SPEAKER_BIANCA
	closemessage
	end


IGuessWeShouldBeNiceNow_StartPuzzle_Script::
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, PUZZLE_1_UNSOLVED
	lock
	closemessage
	applymovement 1, IGuessWeShouldBeNiceNow_WalkIntoMaze
	waitmovement 0
	setobjectxy 1, 15, 19
	setobjectxyperm 1, 15, 19
	msgbox gText_IGuessWeShouldBeNiceNow_IMemorizedThisWhile, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_OnIt, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	release
	end


IGuessWeShouldBeNiceNow_SolvedPuzzleA::
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, PUZZLE_1_SOLVED
	playse SE_SWITCH
	waitse
	msgbox gText_IGuessWeShouldBeNiceNow_OkayYourTurn, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_LetsSeeOhWow, , SPEAKER_BIANCA
	closemessage
	return


IGuessWeShouldBeNiceNow_SolvedPuzzleB::
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, PUZZLE_2_SOLVED
	playse SE_SWITCH
	waitse
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 9
	special TeleportCamera
	fadescreen FADE_FROM_BLACK
	applymovement 5, Common_Movement_WalkLeft
	waitmovement 0
	fadescreen FADE_TO_BLACK
	turnobject 1, DIR_NORTH
	setobjectxy 1, 9, 12
	setobjectxyperm 1, 9, 12
	special ReturnCameraToPlayer
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, IGuessWeShouldBeNiceNow_WalkRight
	waitmovement 0
	msgbox gText_IGuessWeShouldBeNiceNow_SomethingIsMissing, , SPEAKER_BIANCA
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, IGuessWeShouldBeNiceNow_ApproachBookB
	applymovement 1, IGuessWeShouldBeNiceNow_ApproachBookA
	waitmovement 0
	msgbox gText_IGuessWeShouldBeNiceNow_IfIWereACrustyOld, , SPEAKER_BIANCA
	closemessage
	applymovement 1, Common_Movement_WalkUp
	waitmovement 0
	goto IGuessWeShouldBeNiceNow_BossProtectBook_Script
	return


IGuessWeShouldBeNiceNow_BossProtectBook_Script::
	playmoncry SPECIES_GENGAR, CRY_MODE_ENCOUNTER
	playmoncry SPECIES_CHANDELURE, CRY_MODE_ENCOUNTER
	waitse
	msgbox gText_IGuessWeShouldBeNiceNow_Roar, MSGBOX_AUTOCLOSE
	clearflag FLAG_TEMP_2
	addobject 2
	addobject 3
	addobject 6
	msgbox gText_IGuessWeShouldBeNiceNow_BingoIllTake, , SPEAKER_BIANCA
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	call Common_EventScript_SaveGame
	goto IGuessWeShouldBeNiceNow_CoreEncounter_Script
	return


IGuessWeShouldBeNiceNow_CoreEncounter_Script::
	setwildbattle SPECIES_GENGAR, 60, ITEM_LIFE_ORB, SPECIES_GASTLY, 70, ITEM_ORAN_BERRY
	playmoncry SPECIES_GENGAR, CRY_MODE_ENCOUNTER
	msgbox gText_IGuessWeShouldBeNiceNow_Roar
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	multi_fixed_wild TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_WON, IGuessWeShouldBeNiceNow_CoreEncounter_Script_3
IGuessWeShouldBeNiceNow_CoreEncounter_Script_1:
	release
	end

IGuessWeShouldBeNiceNow_CoreEncounter_Script_3:
	goto IGuessWeShouldBeNiceNow_ClearBossPokemon_Script
	goto IGuessWeShouldBeNiceNow_CoreEncounter_Script_1


IGuessWeShouldBeNiceNow_ReadyPlayer_Dialogue::
	lock
	msgbox gText_IGuessWeShouldBeNiceNow_Ready, MSGBOX_NPC, SPEAKER_BIANCA
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	release
	end


IGuessWeShouldBeNiceNow_ClearBossPokemon_Script::
	setvar VAR_ROBINWILLIAMSTUNNEL_STATE, SIEBOLD_BOSS_DEFEATED
	lock
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 2
	removeobject 3
	removeobject 6
	fadescreenswapbuffers FADE_FROM_BLACK
	goto IGuessWeShouldBeNiceNow_PostBoss_Dialogue
	return


IGuessWeShouldBeNiceNow_PostBoss_Dialogue::
	applymovement 1, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox gText_IGuessWeShouldBeNiceNow_OkayImStarting, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_WhatAmIMissing, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_ThosePuzzlesWerent, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_YeahIHadToThink, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_ExactlyYouHad, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_SoTheyreTraining, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_OrTryingAtLeast, , SPEAKER_BIANCA
	closemessage
	applymovement 1, IGuessWeShouldBeNiceNow_GetBook
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	removeobject 4
	msgbox gText_IGuessWeShouldBeNiceNow_SaysOnTheBack, , SPEAKER_BIANCA
	applymovement 1, IGuessWeShouldBeNiceNow_LookAround
	waitmovement 0
	msgbox gText_IGuessWeShouldBeNiceNow_WhewThatWasExhausting, MSGBOX_YESNO, , SPEAKER_BIANCA
	setvar VAR_ROUTE115_STATE, 1
	compare VAR_RESULT, YES
	goto_if_eq IGuessWeShouldBeNiceNow_PostBoss_Dialogue_2
	msgbox gText_IGuessWeShouldBeNiceNow_WellTheChallenges
IGuessWeShouldBeNiceNow_PostBoss_Dialogue_1:
	closemessage
	applymovement 1, IGuessWeShouldBeNiceNow_LeaveCave
	waitmovement 0
	removeobject 1
	release
	end

IGuessWeShouldBeNiceNow_PostBoss_Dialogue_2:
	msgbox gText_IGuessWeShouldBeNiceNow_GreatSeeYou
	goto IGuessWeShouldBeNiceNow_PostBoss_Dialogue_1


IGuessWeShouldBeNiceNow_HidePopup_Script::
	compare VAR_MARIN_STATE, ROBINWILLIAMSTUNNEL_PUZZLES_SOLVED
	goto_if_eq IGuessWeShouldBeNiceNow_HidePopup_Script_1
	return

IGuessWeShouldBeNiceNow_HidePopup_Script_1:
	call Marin_HideMapNamePopup_Script
	return


IGuessWeShouldBeNiceNow_ExitCave_Script::
	lock
	setvar VAR_MARIN_STATE, BIANCA_INVITED_AIRBNB
	playse SE_EXIT
	waitse
	clearflag FLAG_TEMP_3
	addobject 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, IGuessWeShouldBeNiceNow_WalkOutCave
	waitmovement 0
	goto IGuessWeShouldBeNiceNow_End_Dialogue
	return


IGuessWeShouldBeNiceNow_End_Dialogue::
	setvar VAR_MUIRWOODS_STATE, BIANCA_WAITING_MUIRWOODS
	msgbox gText_IGuessWeShouldBeNiceNow_CoolPerfectTiming, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_WhatTookYouSoLong, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_ISpottedAnInteresting, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_WaitWhat, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_AllOfMyPokemon, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_IDidntKnow, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_DaddyOwnsA, , SPEAKER_BIANCA
	msgbox gText_IGuessWeShouldBeNiceNow_WaitWhatIThought, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_IGuessWeShouldBeNiceNow_YeahDaddysPlace, , SPEAKER_BIANCA
	closemessage
	applymovement 1, IGuessWeShouldBeNiceNow_GestureHouse
	waitmovement 0
	msgbox gText_IGuessWeShouldBeNiceNow_ImGonnaCrash, , SPEAKER_BIANCA
	closemessage
	applymovement 1, IGuessWeShouldBeNiceNow_WalkTowardsHouse_Movement
	msgbox gText_IGuessWeShouldBeNiceNow_IHopeItsMyVersion, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	waitmovement 1
	removeobject 1
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warpsilent MAP_MARIN, 6, 33
	release
	end


IGuessWeShouldBeNiceNow_WalkToPlayer:
	walk_down
	face_left
	step_end

IGuessWeShouldBeNiceNow_WalkIntoMaze:
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IGuessWeShouldBeNiceNow_ApproachBookA:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_up
	step_end

IGuessWeShouldBeNiceNow_ApproachBookB:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

IGuessWeShouldBeNiceNow_WalkRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

IGuessWeShouldBeNiceNow_GetBook:
	walk_up
	walk_up
	walk_in_place_faster_up
	step_end

IGuessWeShouldBeNiceNow_LookAround:
	face_left
	delay_16
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	face_down
	step_end

IGuessWeShouldBeNiceNow_LeaveCave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

IGuessWeShouldBeNiceNow_WalkOutCave:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_up
	face_left
	step_end

IGuessWeShouldBeNiceNow_GestureHouse:
	face_right
	delay_16
	delay_16
	face_left
	step_end

IGuessWeShouldBeNiceNow_WalkTowardsHouse_Movement:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_IGuessWeShouldBeNiceNow_TookLongEnough::
	.string "Took long enough. I looked around and -$"

gText_IGuessWeShouldBeNiceNow_WeCantComplete::
	.string "We can't complete the puzzles alone.\n"
	.string "Oak told me after you took off.$"

gText_IGuessWeShouldBeNiceNow_OhShitWellUh::
	.string "Oh shit. Well uh, what else did I miss?$"

gText_IGuessWeShouldBeNiceNow_YouAlreadyKnow::
	.string "You already know. There's no service\n"
	.string "down here, and they said it was the\l"
	.string "same for Muirwoods. We're more or less\l"
	.string "on our own.$"

gText_IGuessWeShouldBeNiceNow_ThatsFineWellLive::
	.string "That's fine. We'll live.$"

gText_IGuessWeShouldBeNiceNow_IAnalyzedTheRoom::
	.string "I analyzed the room while I waited, and\n"
	.string "we need to alternate solving puzzles.$"

gText_IGuessWeShouldBeNiceNow_YouSolvePuzzleA::
	.string "You solve puzzle A, and stand on a\n"
	.string "pressure switch. That opens door B, and\l"
	.string "then I solve puzzle B. I stand on\l"
	.string "another switch…$"

gText_IGuessWeShouldBeNiceNow_AndThenISolvePuzzle::
	.string "And then I solve puzzle C. Do you know\n"
	.string "how far it goes?$"

gText_IGuessWeShouldBeNiceNow_ICouldOnlyAnalyze::
	.string "Nope. I could only analyze one deep\n"
	.string "before I got stuck.$"

gText_IGuessWeShouldBeNiceNow_Ready::
	.string "Ready?$"

gText_IGuessWeShouldBeNiceNow_WellGoGetReady::
	.string "Well, go get ready and come back when\n"
	.string "you are. I'll be here.$"

gText_IGuessWeShouldBeNiceNow_IMemorizedThisWhile::
	.string "I memorized this while I was waiting for\n"
	.string "you… okay! You should be clear to start\l"
	.string "on the other side!$"

gText_IGuessWeShouldBeNiceNow_OnIt::
	.string "On it!$"

gText_IGuessWeShouldBeNiceNow_OkayYourTurn::
	.string "Okay, your turn!$"

gText_IGuessWeShouldBeNiceNow_LetsSeeOhWow::
	.string "Let's see… oh wow, this one is even\n"
	.string "easier than the last! Okay…got it! I\l"
	.string "think this is the last one {PLAYER}!$"

gText_IGuessWeShouldBeNiceNow_SomethingIsMissing::
	.string "Something is missing…$"

gText_IGuessWeShouldBeNiceNow_IfIWereACrustyOld::
	.string "If I were a crusty old dude trying to\n"
	.string "grift YCombinator out of some cash,\l"
	.string "there would be something guarding this\l"
	.string "book, right?$"

gText_IGuessWeShouldBeNiceNow_Roar::
	.string "ROAR$"

gText_IGuessWeShouldBeNiceNow_BingoIllTake::
	.string "Bingo. I'll take the one on the right.\n"
	.string "Ready, {PLAYER}?$"

gText_IGuessWeShouldBeNiceNow_OkayImStarting::
	.string "Okay, *pant* I'm starting to understand\n"
	.string "the training now…A little.$"

gText_IGuessWeShouldBeNiceNow_WhatAmIMissing::
	.string "*pant* What am I missing?$"

gText_IGuessWeShouldBeNiceNow_ThosePuzzlesWerent::
	.string "Those puzzles weren't physically tough,\n"
	.string "but we had to think. And those\l"
	.string "battles… we couldn't brute force them,\l"
	.string "right?$"

gText_IGuessWeShouldBeNiceNow_YeahIHadToThink::
	.string "Yeah, I had to think about a strategy.$"

gText_IGuessWeShouldBeNiceNow_ExactlyYouHad::
	.string "Exactly. You had to think under\n"
	.string "pressure when you were already worn\l"
	.string "down.$"

gText_IGuessWeShouldBeNiceNow_SoTheyreTraining::
	.string "So they're training our mental\n"
	.string "toughness…?$"

gText_IGuessWeShouldBeNiceNow_OrTryingAtLeast::
	.string "Or, trying at least. I'll grab this…$"

gText_IGuessWeShouldBeNiceNow_SaysOnTheBack::
	.string "Says on the back cover, “Bring to the\n"
	.string "deepest part of Muirwoods.$"

gText_IGuessWeShouldBeNiceNow_WhewThatWasExhausting::
	.string "Whew, that was exhausting. How about we\n"
	.string "crash at my place nearby in Marin and\l"
	.string "then tackle Muirwoods tomorrow?$"

gText_IGuessWeShouldBeNiceNow_GreatSeeYou::
	.string "Great, see you in Marin!$"

gText_IGuessWeShouldBeNiceNow_WellTheChallenges::
	.string "Well, the challenges need both of us…\n"
	.string "and I'm tired. So I'm going to crash -\l"
	.string "you're welcome to try Muirwoods by\l"
	.string "yourself though.$"

gText_IGuessWeShouldBeNiceNow_CoolPerfectTiming::
	.string "Cool, perfect timing.$"

gText_IGuessWeShouldBeNiceNow_WhatTookYouSoLong::
	.string "What took you so long? You're usually in\n"
	.string "front.$"

gText_IGuessWeShouldBeNiceNow_ISpottedAnInteresting::
	.string "I spotted an interesting Pokémon while\n"
	.string "we were working on the puzzles, so I\l"
	.string "went back and caught it! It was\l"
	.string "actually my first time catching\l"
	.string "something.$"

gText_IGuessWeShouldBeNiceNow_WaitWhat::
	.string "Wait, what?$"

gText_IGuessWeShouldBeNiceNow_AllOfMyPokemon::
	.string "All of my Pokémon are normally bred in\n"
	.string "Unova and sent to me. But I wanted to\l"
	.string "try raising one from scratch, just to\l"
	.string "see how it compares.$"

gText_IGuessWeShouldBeNiceNow_IDidntKnow::
	.string "(I didn't know you could DO that.) Oh,\n"
	.string "well… congrats!$"

gText_IGuessWeShouldBeNiceNow_DaddyOwnsA::
	.string "Daddy owns a Airbnb out here. I called\n"
	.string "him earlier and had him kick out the\l"
	.string "people that were staying there, so it\l"
	.string "should be good for us now.$"

gText_IGuessWeShouldBeNiceNow_WaitWhatIThought::
	.string "Wait what? I thought YCombinator -$"

gText_IGuessWeShouldBeNiceNow_YeahDaddysPlace::
	.string "Yeah, Daddy's place is way nicer than\n"
	.string "some motel or whatever. It's on the\l"
	.string "eastern side of town.$"

gText_IGuessWeShouldBeNiceNow_ImGonnaCrash::
	.string "I'm gonna crash, but I'll leave the door\n"
	.string "open for you. Let's meet at the\l"
	.string "entrance of Muirwoods tomorrow\l"
	.string "morning! DIRECTOR'S NOTE: Just go\l"
	.string "there now.$"

gText_IGuessWeShouldBeNiceNow_IHopeItsMyVersion::
	.string "I hope it's my version of morning, and\n"
	.string "not yours…$"
