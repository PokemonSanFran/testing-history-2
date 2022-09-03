NewAssholeAppears_WalkToPlayer_Script::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	applymovement 1, Common_Movement_ExclamationMark
	playse SE_PIN
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	waitmovement 0
	switch VAR_TEMP_0
	case 0, NewAssholeAppears_WalkToPlayer_Script_3
	case 1, NewAssholeAppears_WalkToPlayer_Script_4
	case 2, NewAssholeAppears_WalkToPlayer_Script_5
	case 3, NewAssholeAppears_WalkToPlayer_Script_6
	case 4, NewAssholeAppears_WalkToPlayer_Script_7
NewAssholeAppears_WalkToPlayer_Script_1:
	waitmovement 0
	switch VAR_TEMP_1
	case 2, NewAssholeAppears_WalkToPlayer_Script_10
	case 6, NewAssholeAppears_WalkToPlayer_Script_11
NewAssholeAppears_WalkToPlayer_Script_8:
	waitmovement 0
	goto ArcherAlpha_Event_Script
	return

NewAssholeAppears_WalkToPlayer_Script_3:
	applymovement 1, NewAssholeAppears_X0_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_1

NewAssholeAppears_WalkToPlayer_Script_4:
	applymovement 1, NewAssholeAppears_X1_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_1

NewAssholeAppears_WalkToPlayer_Script_5:
	applymovement 1, NewAssholeAppears_X2_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_1

NewAssholeAppears_WalkToPlayer_Script_6:
	applymovement 1, NewAssholeAppears_X3_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_1

NewAssholeAppears_WalkToPlayer_Script_7:
	applymovement 1, NewAssholeAppears_X4_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_1

NewAssholeAppears_WalkToPlayer_Script_10:
	applymovement 1, NewAssholeAppears_Y2_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_8

NewAssholeAppears_WalkToPlayer_Script_11:
	applymovement 1, NewAssholeAppears_Y6_WalkToPlayer_Movement
	goto NewAssholeAppears_WalkToPlayer_Script_8


ArcherAlpha_Event_Script::
	switch VAR_PSFROUTE9_STATE
	case 0, ArcherAlpha_Event_Script_2
	case 1, ArcherAlpha_Event_Script_3
	return

ArcherAlpha_Event_Script_2:
	goto NewAssholeAppears_Intro_Dialogue
	return

ArcherAlpha_Event_Script_3:
	goto NewAssholeAppears_StartBattle_Script
	return


NewAssholeAppears_Intro_Dialogue::
	addvar VAR_PSFROUTE9_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_YouLookFamiliar, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_JustStarted, MSGBOX_NPC
	goto NewAssholeAppears_BadgeJudge_Dialogue
	return


NewAssholeAppears_BadgeJudge_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	special GetNumberOfBadges
	switch VAR_RESULT
	case 0, NewAssholeAppears_BadgeJudge_Dialogue_3
	case 1, NewAssholeAppears_BadgeJudge_Dialogue_4
	msgbox gText_NewAssholeAppears_ColonizersAreReallyGetting, MSGBOX_NPC
NewAssholeAppears_BadgeJudge_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_WhatIsYourProblem, MSGBOX_NPC
	callnative ClearMugshot
	lockall
	call Common_EventScript_SaveGame
	closemessage
	goto NewAssholeAppears_StartBattle_Script
	return

NewAssholeAppears_BadgeJudge_Dialogue_3:
	msgbox gText_NewAssholeAppears_NotDoingMuchGood, MSGBOX_NPC
	goto NewAssholeAppears_BadgeJudge_Dialogue_1

NewAssholeAppears_BadgeJudge_Dialogue_4:
	msgbox gText_NewAssholeAppears_ThoughtIRecognized, MSGBOX_NPC
	goto NewAssholeAppears_BadgeJudge_Dialogue_1


NewAssholeAppears_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	trainerbattle_single TRAINER_WALLY_MAUVILLE, gText_NewAssholeAppears_GoMindYourBusiness, gText_NewAssholeAppears_YoureTough, NewAssholeAppears_PostBattle_Script, NO_MUSIC
	closemessage
	callnative ClearMugshot
	return


NewAssholeAppears_PostBattle_Script::
	lockall
	addvar VAR_PSFROUTE9_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_Whateveryournameis, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_GentrificationOfMyHome, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_YouSoundCrazyPerson, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_NotStupidJustIgnorant, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_SeeYouAround, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_NewAssholeAppears_IHopeNot, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	goto NewAssholeAppears_ArcherExit_Script
	return


NewAssholeAppears_ArcherExit_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 2, NewAssholeAppears_ArcherExit_Script_3
	case 6, NewAssholeAppears_ArcherExit_Script_4
NewAssholeAppears_ArcherExit_Script_1:
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end

NewAssholeAppears_ArcherExit_Script_3:
	applymovement 1, NewAssholeAppears_ArcherWalkAwaySouth_Movement
	goto NewAssholeAppears_ArcherExit_Script_1

NewAssholeAppears_ArcherExit_Script_4:
	applymovement 1, NewAssholeAppears_ArcherWalkAwayNorth_Movement
	goto NewAssholeAppears_ArcherExit_Script_1


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

NewAssholeAppears_ArcherWalkAwayNorth_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

NewAssholeAppears_ArcherWalkAwaySouth_Movement:
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
	.string "the YCombinator League Challenge,\l"
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

gText_NewAssholeAppears_YoureTough::
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
