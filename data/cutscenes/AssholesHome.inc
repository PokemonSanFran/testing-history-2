AssholesHome_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	return


AssholesHome_WalkToPlayer_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	applymovement 3, AssholesHomes_WalkToPlayer_Movement
	waitmovement 0
	goto AssholesHome_Archer_Dialogue
	return


AssholesHome_BattleEvent_Script::
	lock
	faceplayer
	switch VAR_ALAMEDA_STATE
	case HAS_NOT_ENCOUNTERED_ARCHER, AssholesHome_BattleEvent_Script_2
	case SAVE_ARCHER_ALAMEDA, AssholesHome_BattleEvent_Script_3
	return

AssholesHome_BattleEvent_Script_2:
	goto AssholesHome_Archer_Dialogue
	return

AssholesHome_BattleEvent_Script_3:
	goto AssholesHome_StartBattle_Script
	return


AssholesHome_Archer_Dialogue::
	setvar VAR_ALAMEDA_STATE, SAVE_ARCHER_ALAMEDA
	msgbox gText_AssholesHome_JudgingFromSwarm, MSGBOX_DEFAULT, SPEAKER_ARCHER
	msgbox gText_AssholesHome_ReallyHopingLastTime, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	call Common_EventScript_SaveGame
	closemessage
	goto AssholesHome_StartBattle_Script
	return


AssholesHome_StartBattle_Script::
	lockall
	msgbox gText_AssholesHome_JustCurious, MSGBOX_DEFAULT, SPEAKER_ARCHER
	msgbox gText_AssholesHome_IDoubtYoureGoing, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	trainerbattle_no_intro TRAINER_WALLY_VR_1, gText_AssholesHome_ThrowsTheirMoney
	goto AssholesHome_PostBattle_Dialogue
	return


AssholesHome_PostBattle_Dialogue::
	lockall
	setvar VAR_STORYLINE_STATE, STORY_DEFEAT_ARCHER_ALAMEDA
	setvar VAR_ALAMEDA_STATE, DEFEATED_ARCHER_ALAMEDA
	msgbox gText_AssholesHome_SoMuchForThe, MSGBOX_DEFAULT, SPEAKER_ARCHER
	msgbox gText_AssholesHome_NameInsteadOf, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_AssholesHome_ILikeBeingPushed, MSGBOX_DEFAULT, SPEAKER_ARCHER
	compare VAR_SALESFORCETOWER_PRODUCTION_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	goto_if_eq AssholesHome_PostBattle_Dialogue_2
AssholesHome_PostBattle_Dialogue_1:
	closemessage
	applymovement 3, AssholesHome_WalkAway_Movement
	waitmovement 0
	fadedefaultbgm
	removeobject 3
	release
	end

AssholesHome_PostBattle_Dialogue_2:
	msgbox gText_AssholesHome_ISawThatYoure, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_AssholesHome_YoureRightItsHypocritical, MSGBOX_DEFAULT, SPEAKER_ARCHER
	msgbox gText_AssholesHome_WhatAWeirdKid, MSGBOX_DEFAULT, SPEAKER_ZOEY
	goto AssholesHome_PostBattle_Dialogue_1


AssholesHomes_WalkToPlayer_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

AssholesHome_WalkAway_Movement:
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
	.string "Just curious if you're ready for the\n"
	.string "next Gym Leader.$"

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
	.string "Morty.$"

gText_AssholesHome_ThrowsTheirMoney::
	.string "YCombinator throws their money around,\n"
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
