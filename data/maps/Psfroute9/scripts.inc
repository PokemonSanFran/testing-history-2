Psfroute9_MapScripts::
	.byte 0


NewAssholeAppears_PsfnativerivalWalkToPlayer::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	waitmovement 0
	switch VAR_TEMP_0
	case 0, NewAssholeAppears_PsfnativerivalWalkToPlayer_3
	case 1, NewAssholeAppears_PsfnativerivalWalkToPlayer_4
	case 2, NewAssholeAppears_PsfnativerivalWalkToPlayer_5
	case 3, NewAssholeAppears_PsfnativerivalWalkToPlayer_6
	case 4, NewAssholeAppears_PsfnativerivalWalkToPlayer_7
NewAssholeAppears_PsfnativerivalWalkToPlayer_1:
	waitmovement 0
	switch VAR_TEMP_1
	case 2, NewAssholeAppears_PsfnativerivalWalkToPlayer_10
	case 6, NewAssholeAppears_PsfnativerivalWalkToPlayer_11
NewAssholeAppears_PsfnativerivalWalkToPlayer_8:
	waitmovement 0
	goto PsfnativerivalAlpha_Event_Script
	return

NewAssholeAppears_PsfnativerivalWalkToPlayer_3:
	applymovement 1, NewAssholeAppears_X0_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_1

NewAssholeAppears_PsfnativerivalWalkToPlayer_4:
	applymovement 1, NewAssholeAppears_X1_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_1

NewAssholeAppears_PsfnativerivalWalkToPlayer_5:
	applymovement 1, NewAssholeAppears_X2_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_1

NewAssholeAppears_PsfnativerivalWalkToPlayer_6:
	applymovement 1, NewAssholeAppears_X3_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_1

NewAssholeAppears_PsfnativerivalWalkToPlayer_7:
	applymovement 1, NewAssholeAppears_X4_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_1

NewAssholeAppears_PsfnativerivalWalkToPlayer_10:
	applymovement 1, NewAssholeAppears_Y2_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_8

NewAssholeAppears_PsfnativerivalWalkToPlayer_11:
	applymovement 1, NewAssholeAppears_Y6_WalkToPlayer_Movement
	goto NewAssholeAppears_PsfnativerivalWalkToPlayer_8


PsfnativerivalAlpha_Event_Script::
	switch VAR_NATIVERIVALALPHA_STATE
	case 0, PsfnativerivalAlpha_Event_Script_2
	case 1, PsfnativerivalAlpha_Event_Script_3
	return

PsfnativerivalAlpha_Event_Script_2:
	goto NewAssholeAppears_PsfnativerivalIntro_Dialogue
	return

PsfnativerivalAlpha_Event_Script_3:
	goto PsfnativerivalAlpha_StartBattle_Script
	return


NewAssholeAppears_PsfnativerivalIntro_Dialogue::
	setvar VAR_NATIVERIVALALPHA_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_YouLookFamiliar, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_JustStarted, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	goto NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue
	return


NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	special GetNumberOfBadges
	switch VAR_TEMP_0
	case 0, NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_3
	case 1, NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_4
	msgbox gText_NewAssholeAppears_ColonizersAreReallyGetting, MSGBOX_NPC
NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_1:
	closemessage
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_WhatIsYourProblem, MSGBOX_NPC
	callnative ClearMugshot
	lockall
	call Common_EventScript_SaveGame
	closemessage
	goto PsfnativerivalAlpha_StartBattle_Script
	return

NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_3:
	msgbox gText_NewAssholeAppears_NotDoingMuchGood, MSGBOX_NPC
	goto NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_1

NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_4:
	msgbox gText_NewAssholeAppears_ThoughtIRecognized, MSGBOX_NPC
	goto NewAssholeAppears_PsfnativerivalBadgeJudge_Dialogue_1


PsfnativerivalAlpha_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	trainerbattle_single TRAINER_WALLY_MAUVILLE, gText_NewAssholeAppears_GoMindYourBusiness, gText_PsfnativerivalAlpha_HumanWin, PsfnativerivalAlphaDefeated_Dialogue, NO_MUSIC
	closemessage
	callnative ClearMugshot
	return


PsfnativerivalAlphaDefeated_Dialogue::
	lockall
	setvar VAR_PSFROUTE9_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_Whateveryournameis, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_GentrificationOfMyHome, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_YouSoundCrazyPerson, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_NotStupidJustIgnorant, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_SeeYouAround, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_IHopeNot, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	goto NewAssholeAppears_PsfnativerivalExit_Script
	return


NewAssholeAppears_PsfnativerivalExit_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 2, NewAssholeAppears_PsfnativerivalExit_Script_3
	case 6, NewAssholeAppears_PsfnativerivalExit_Script_4
NewAssholeAppears_PsfnativerivalExit_Script_1:
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end

NewAssholeAppears_PsfnativerivalExit_Script_3:
	applymovement 1, NewAssholeAppears_PsfnativerivalWalkAwaySouth_Movement
	goto NewAssholeAppears_PsfnativerivalExit_Script_1

NewAssholeAppears_PsfnativerivalExit_Script_4:
	applymovement 1, NewAssholeAppears_PsfnativerivalWalkAwayNorth_Movement
	goto NewAssholeAppears_PsfnativerivalExit_Script_1


NewAssholeAppears_X0_WalkToPlayer_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

NewAssholeAppears_X1_WalkToPlayer_Movement:
	walk_left
	walk_left
	walk_left
	step_end

NewAssholeAppears_X2_WalkToPlayer_Movement:
	walk_left
	walk_left
	step_end

NewAssholeAppears_X3_WalkToPlayer_Movement:
	walk_left
	step_end

NewAssholeAppears_X4_WalkToPlayer_Movement:
	step_end

NewAssholeAppears_Y2_WalkToPlayer_Movement:
	walk_up
	step_end

NewAssholeAppears_Y6_WalkToPlayer_Movement:
	walk_down
	step_end

NewAssholeAppears_PsfnativerivalWalkAwayNorth_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewAssholeAppears_PsfnativerivalWalkAwaySouth_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_NewAssholeAppears_YouLookFamiliar::
	.string "You look familiar. You flew here to do\n"
	.string "the Psfbadguy1 League Challenge,\l"
	.string "right?$"

gText_NewAssholeAppears_JustStarted::
	.string "Yeah! Just started not too long ago.\n"
	.string "Name's {PLAYER}.$"

gText_NewAssholeAppears_NotDoingMuchGood::
	.string "Judging from your Badge count, the\n"
	.string "program isn't doing you much good.$"

gText_NewAssholeAppears_ThoughtIRecognized::
	.string "...yeah I thought I recognized you.\n"
	.string "Guess you transplants aren't all a\l"
	.string "total joke!$"

gText_NewAssholeAppears_ColonizersAreReallyGetting::
	.string "Yeah, I heard about you from the guys.\n"
	.string "The colonizers are really getting a\l"
	.string "head start, huh?$"

gText_NewAssholeAppears_WhatIsYourProblem::
	.string "Woah, what the hell is your problem?$"

gText_NewAssholeAppears_GoMindYourBusiness::
	.string "Go mind your business in your own\n"
	.string "region.$"

gText_PsfnativerivalAlpha_HumanWin::
	.string "...you're tough.$"

gText_NewAssholeAppears_Whateveryournameis::
	.string "Are you done being an ass,\n"
	.string "whateveryournameis?$"

gText_NewAssholeAppears_GentrificationOfMyHome::
	.string "Archer, and only if you're done\n"
	.string "contributing to the gentrification of\l"
	.string "my home... but I doubt it. You're stupid,\l"
	.string "just like the rest of them.$"

gText_NewAssholeAppears_YouSoundCrazyPerson::
	.string "Excuse me!? You sound like a crazy\n"
	.string "person, but I'm the stupid one?$"

gText_NewAssholeAppears_NotStupidJustIgnorant::
	.string "I take that back - not stupid, just\n"
	.string "ignorant. I shouldn't be mad at you. The\l"
	.string "ignorance isn't entirely your fault.$"

gText_NewAssholeAppears_SeeYouAround::
	.string "See you around.$"

gText_NewAssholeAppears_IHopeNot::
	.string "I hope not.$"
