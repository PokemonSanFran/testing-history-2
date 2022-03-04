Psfcity17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity17_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Psfcity17_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity17_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity17_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity17_MapScripts_OnTransition
	return

Psfcity17_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare VAR_NATIVERIVALBETA_STATE, 3
	goto_if_gt Psfcity17_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Psfcity17_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	call Psfplace2_PostRaidTiles_Script
	return

Psfcity17_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_NATIVERIVALBETA_STATE, 3, SurvivalChance333_ExplainOperation
	.2byte 0


Psfcity17_MapScripts_OnTransition::
	switch VAR_NATIVERIVALBETA_STATE
	case 0, Psfcity17_MapScripts_OnTransition_2
	return

Psfcity17_MapScripts_OnTransition_2:
	goto SurvivalChance333_HideObject_Psfcity17_Script
	return


Psfplace2_PostRaidTiles_Script::
	call SurvivalChance333_FreezeIce
	call SurvivalChance333_SetLava
	call SurvivalChance333_BlowOpenDoors
	return


Psfcity17_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfcity17_UnlockedDestinations_Script
	return


Psfcity17_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case 0, Psfcity17_UnlockedDestinations_Script_2
	case 1, Psfcity17_UnlockedDestinations_Script_3
	return

Psfcity17_UnlockedDestinations_Script_2:
	goto Psfcity17_FerryState0_Script
	return

Psfcity17_UnlockedDestinations_Script_3:
	goto Psfcity17_FerryState1_Script
	return


Psfcity17_FerryState0_Script::
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER1, 2, FALSE
	switch VAR_RESULT
	case 0, Psfcity17_FerryState0_Script_3
	case 1, Psfcity17_FerryState0_Script_4
	case MULTI_B_PRESSED, Psfcity17_FerryState0_Script_5
Psfcity17_FerryState0_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Psfcity17_FerryState0_Script_3:
	warp MAP_PSFPLACE11, 8, 11
	goto Psfcity17_FerryState0_Script_1

Psfcity17_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState0_Script_1

Psfcity17_FerryState0_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState0_Script_1


Psfcity17_FerryState1_Script::
	multichoicedefault 18, 8, PSFCITY17_FERRY_DESTINATIONS_VER2, 2, FALSE
	switch VAR_RESULT
	case 0, Psfcity17_FerryState1_Script_3
	case 1, Psfcity17_FerryState1_Script_4
	case 2, Psfcity17_FerryState1_Script_5
	case MULTI_B_PRESSED, Psfcity17_FerryState1_Script_6
Psfcity17_FerryState1_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Psfcity17_FerryState1_Script_3:
	warp MAP_PSFPLACE11, 8, 11
	goto Psfcity17_FerryState1_Script_1

Psfcity17_FerryState1_Script_4:
	warp MAP_PSFCAVE7, 15, 22
	goto Psfcity17_FerryState1_Script_1

Psfcity17_FerryState1_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState1_Script_1

Psfcity17_FerryState1_Script_6:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Psfcity17_FerryState1_Script_1


AssholesHome_PsfnativerivalWalkToPlayer::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	waitmovement 0
	applymovement 3, AssholesHomes_WalkToPlayer_Movement
	waitmovement 0
	goto AssholesHome_PsfnativerivalBeta_Event_Script
	return


AssholesHome_PsfnativerivalBeta_Event_Script::
	switch VAR_NATIVERIVALBETA_STATE
	case 0, AssholesHome_PsfnativerivalBeta_Event_Script_2
	case 1, AssholesHome_PsfnativerivalBeta_Event_Script_3
	return

AssholesHome_PsfnativerivalBeta_Event_Script_2:
	goto AssholesHome_Psfnativerival_Dialogue
	return

AssholesHome_PsfnativerivalBeta_Event_Script_3:
	goto PsfnativerivalBeta_StartBattle_Script
	return


AssholesHome_Psfnativerival_Dialogue::
	setvar VAR_NATIVERIVALBETA_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_AssholesHome_JudgingFromSwarm
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AssholesHome_ReallyHopingLastTime
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_AssholesHome_JustCurious
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto PsfnativerivalBeta_StartBattle_Script
	return


PsfnativerivalBeta_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AssholesHome_IDoubtYoureGoing
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_WALLY_VR_1, gText_AssholesHome_ThrowsTheirMoney
	goto PsfnativerivalBetaDefeated_Dialogue
	return


PsfnativerivalBetaDefeated_Dialogue::
	lockall
	setvar VAR_NATIVERIVALBETA_STATE, 2
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_AssholesHome_SoMuchForThe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AssholesHome_NameInsteadOf
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_AssholesHome_ILikeBeingPushed
	compare VAR_PSFBADGUY1TOWER_2F_STATE, 2
	goto_if_eq PsfnativerivalBetaDefeated_Dialogue_2
PsfnativerivalBetaDefeated_Dialogue_1:
	callnative ClearMugshot
	closemessage
	applymovement 3, AssholesHome_PsfnativerivalWalkAway_Movement
	waitmovement 0
	fadedefaultbgm
	removeobject 3
	addvar VAR_STORYLINE_STATE, 1
	releaseall
	end

PsfnativerivalBetaDefeated_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AssholesHome_ISawThatYoure
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_AssholesHome_YoureRightItsHypocritical
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AssholesHome_WhatAWeirdKid
	goto PsfnativerivalBetaDefeated_Dialogue_1


AssholesHomes_WalkToPlayer_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AssholesHome_PsfnativerivalWalkAway_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_AssholesHome_JudgingFromSwarm::
	.string "Judging from the swarm of transplants\n"
	.string "on the island this morning, I'm guessing\l"
	.string "the ferry is fixed.$"

gText_AssholesHome_ReallyHopingLastTime::
	.string "*sigh* I was really hoping last time was\n"
	.string "the last time. What do you want?$"

gText_AssholesHome_JustCurious::
	.string "Just curious if you're ready for\n"
	.string "Psfleader4.$"

gText_AssholesHome_IDoubtYoureGoing::
	.string "I doubt you're going to be able to\n"
	.string "accurately judge that.$"

gText_AssholesHome_NotAgain::
	.string "Not again!$"

gText_AssholesHome_GuessYouReally::
	.string "Guess you really worked for those\n"
	.string "Badges!$"

gText_AssholesHome_GuessICanJudge::
	.string "Guess I can judge. You're not ready for\n"
	.string "Psfleader4.$"

gText_AssholesHome_ThrowsTheirMoney::
	.string "Psfbadguy1 throws their money around,\n"
	.string "and the strong get stronger...$"

gText_AssholesHome_SoMuchForThe::
	.string "So much for the home-court advantage.\n"
	.string "gg... {PLAYER}, right?$"

gText_AssholesHome_NameInsteadOf::
	.string "Oh wow, a name instead of an insult.$"

gText_AssholesHome_ILikeBeingPushed::
	.string "I like being pushed to my limits like\n"
	.string "that. You're stronger than the rest of\l"
	.string "them, that's for sure. See you around.$"

gText_AssholesHome_ISawThatYoure::
	.string "Wait! I saw that you're participating in\n"
	.string "the League Challenge like the rest of\l"
	.string "us. After all the insults and endless\l"
	.string "complaints about it, what am I missing?$"

gText_AssholesHome_YoureRightItsHypocritical::
	.string "You're right, it's hypocritical. But I'm\n"
	.string "tired of fighting a system from the\l"
	.string "outside. I'm going to try and change it\l"
	.string "from the inside out. I'm excited to be\l"
	.string "able to beat you along the way.$"

gText_AssholesHome_WhatAWeirdKid::
	.string "(What a weird kid...)$"
