BeachBattle_ObjectSetUp_Script::
	setflag FLAG_HIDE_BEACHBATTLE_PSFTRANSRIVAL
	end


BeachBattle_BattleSetUp_Script::
	setobjectxyperm 1, 10, 24
	return


BeachBattle_PsftransrivalWalkToPlayer::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_BeachBattle_HeyPlayer
	closemessage
	callnative ClearMugshot
	playse SE_PIN
	clearflag FLAG_HIDE_BEACHBATTLE_PSFTRANSRIVAL
	addobject 1
	applymovement OBJ_EVENT_ID_PLAYER, BeachBattle_ExclaimAndTurn
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement 1, BeachBattle_ApproachFromSouth
	waitmovement 0
	goto BeachBattle_Psfnativerival_Event_Script
	return


BeachBattle_Interact_Script::
	faceplayer
	goto BeachBattle_Psfnativerival_Event_Script
	return


BeachBattle_Psfnativerival_Event_Script::
	switch VAR_ROUTE107_STATE
	case 0, BeachBattle_Psfnativerival_Event_Script_2
	case 1, BeachBattle_Psfnativerival_Event_Script_3
	return

BeachBattle_Psfnativerival_Event_Script_2:
	goto BeachBattle_Approach_Dialogue
	return

BeachBattle_Psfnativerival_Event_Script_3:
	goto BeachBattle_StartBattle_Script
	return


BeachBattle_Approach_Dialogue::
	setvar VAR_ROUTE107_STATE, 1
	setobjectxyperm 1, 10, 24
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_BeachBattle_ImHeadingNorth
	special GetNumberOfBadges
	switch VAR_TEMP_0
	case 8, BeachBattle_Approach_Dialogue_2
	case 7, BeachBattle_Approach_Dialogue_3
	case 6, BeachBattle_Approach_Dialogue_4
	case 5, BeachBattle_Approach_Dialogue_5
	case 4, BeachBattle_Approach_Dialogue_6
	return

BeachBattle_Approach_Dialogue_2:
	goto BeachBattle_EightBadges_Dialogue
	return

BeachBattle_Approach_Dialogue_3:
	goto BeachBattle_SevenBadges_Dialogue
	return

BeachBattle_Approach_Dialogue_4:
	goto BeachBattle_SixBadges_Dialogue
	return

BeachBattle_Approach_Dialogue_5:
	goto BeachBattle_FiveBadges_Dialogue
	return

BeachBattle_Approach_Dialogue_6:
	goto BeachBattle_FourBadges_Dialogue
	return


BeachBattle_EightBadges_Dialogue::
	msgbox gText_BeachBattle_OhShit
	goto BeachBattle_SaveProgress
	return


BeachBattle_SevenBadges_Dialogue::
	msgbox gText_BeachBattle_OhNiceLastOne
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeachBattle_JustTheOneIn
	goto BeachBattle_SaveProgress
	return


BeachBattle_SixBadges_Dialogue::
	msgbox gText_BeachBattle_TwoLeft
	goto BeachBattle_SaveProgress
	return


BeachBattle_FiveBadges_Dialogue::
	msgbox gText_BeachBattle_HmmOnlyFive
	goto BeachBattle_SaveProgress
	return


BeachBattle_FourBadges_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_BeachBattle_ImNotSureThatSlow
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeachBattle_IveBeenALittleDistracted
	goto BeachBattle_SaveProgress
	return


BeachBattle_SaveProgress::
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto BeachBattle_StartBattle_Script
	return


BeachBattle_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_BeachBattle_MyBrainIsScrambled
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, gText_BeachBattle_ImLegitShook
	closemessage
	callnative ClearMugshot
	goto BeachBattle_PostBattle_Dialogue
	return


BeachBattle_PostBattle_Dialogue::
	lockall
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	setvar VAR_ROUTE107_STATE, 2
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeachBattle_WellImNotSurprised
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_BeachBattle_UghIShouldBe
	goto_if_set FLAG_BADGE05_GET, BeachBattle_PostBattle_Dialogue_2
BeachBattle_PostBattle_Dialogue_1:
	msgbox gText_BeachBattle_NextTimeIllHave
	callnative ClearMugshot
	closemessage
	applymovement 1, BeachBattle_WalkAway
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	releaseall
	end

BeachBattle_PostBattle_Dialogue_2:
	msgbox gText_BeachBattle_IfItTakesATeam
	goto BeachBattle_PostBattle_Dialogue_1


BeachBattle_ExclaimAndTurn:
	emote_exclamation_mark
	face_down
	step_end

BeachBattle_ApproachFromSouth:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BeachBattle_WalkAway:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_BeachBattle_HeyPlayer::
	.string "Hey, {PLAYER}!!$"

gText_BeachBattle_ImHeadingNorth::
	.string "I'm heading north for my last Badge.\n"
	.string "How's your challenge holding up?$"

gText_BeachBattle_OhShit::
	.string "Oh shit! You beat me to eight badges -\n"
	.string "guess I underestimated you!$"

gText_BeachBattle_OhNiceLastOne::
	.string "Oh nice, last one too! Which one?$"

gText_BeachBattle_JustTheOneIn::
	.string "Just the one in {STR_VAR_1} City.\n"
	.string "Headed there now.$"

gText_BeachBattle_TwoLeft::
	.string "Two left, that's what I figured.$"

gText_BeachBattle_HmmOnlyFive::
	.string "Hmm, only five? Guessed you'd be\n"
	.string "further along by now!$"

gText_BeachBattle_ImNotSureThatSlow::
	.string "{PLAYER}, I'm not sure that slow and\n"
	.string "steady always win the race… you gotta\l"
	.string "pick it up!$"

gText_BeachBattle_IveBeenALittleDistracted::
	.string "I've been a little… distracted! But I'll\n"
	.string "make it up for sure, don't worry.$"

gText_BeachBattle_MyBrainIsScrambled::
	.string "My brain is scrambled from running\n"
	.string "around all day. Let's see if I can beat\l"
	.string "you without breaking a sweat!$"

gText_BeachBattle_ImLegitShook::
	.string "I'm legit shook. You're even stronger\n"
	.string "than I thought!$"

gText_BeachBattle_WellImNotSurprised::
	.string "Well, I'm not surprised you've already\n"
	.string "got seven Badges, that was tough!$"

gText_BeachBattle_UghIShouldBe::
	.string "Ugh, I should be stronger than that.$"

gText_BeachBattle_IfItTakesATeam::
	.string "If it takes a team as good as yours to\n"
	.string "beat Psfleader5, then I might need to\l"
	.string "rethink things…$"

gText_BeachBattle_NextTimeIllHave::
	.string "Next time, I'll have you figured out!$"
