Quest_CutePokemon_Event_Script::
	lock
	faceplayer
	returnqueststate QUEST_CUTEPOKEMON
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_CutePokemon_Event_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Quest_CutePokemon_Event_Script_3
	goto Quest_CutePokemon_StartQuest_Script
	return

Quest_CutePokemon_Event_Script_2:
	goto Quest_CutePokemon_SelectSubquest_Script
	return

Quest_CutePokemon_Event_Script_3:
	goto Quest_CutePokemon_PostQuest_Dialogue
	return


Quest_CutePokemon_StartQuest_Script::
	startquest QUEST_CUTEPOKEMON
	return


Quest_CutePokemon_SelectSubquest_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_SelectSubquest_Script_2
Quest_CutePokemon_SelectSubquest_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_SelectSubquest_Script_5
Quest_CutePokemon_SelectSubquest_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_SelectSubquest_Script_8
Quest_CutePokemon_SelectSubquest_Script_7:
	switch VAR_TEMP_0
	case 0, Quest_CutePokemon_SelectSubquest_Script_11
	return

Quest_CutePokemon_SelectSubquest_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_SelectSubquest_Script_1

Quest_CutePokemon_SelectSubquest_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_SelectSubquest_Script_4

Quest_CutePokemon_SelectSubquest_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_SelectSubquest_Script_7

Quest_CutePokemon_SelectSubquest_Script_11:
	goto Quest_CutePokemon_Sub1_Event_Script
	return


Quest_CutePokemon_Sub1_Event_Script::
	call Quest_CutePokemon_Sub1_Hints_Dialogue
	call Quest_CutePokemon_CheckPokemon_Script
	compare VAR_RESULT, SPECIES_DUSKULL
	goto_if_eq Quest_CutePokemon_Sub1_Event_Script_1
	goto Quest_CutePokemon_Incorrect_Dialogue
	return

Quest_CutePokemon_Sub1_Event_Script_1:
	goto Quest_CutePokemon_Sub1_Correct_Dialogue
	return


Quest_CutePokemon_CancelCheck_Dialogue::
	msgbox gText_CutePokemon_ChangedYourMind
	release
	end


Quest_CutePokemon_Incorrect_Dialogue::
	addvar VAR_CUTE_POKEMON_GUESS, 1
	msgbox gText_CutePokemon_NoThatsNotIt
	release
	end


Quest_CutePokemon_Sub1_Correct_Dialogue::
	msgbox gText_CutePokemon_YesDuskull
	msgbox gText_CutePokemon_ItsSoCute, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Quest_CutePokemon_Sub1_Correct_Dialogue_2
Quest_CutePokemon_Sub1_Correct_Dialogue_1:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CUTEPOKEMON, SUB_QUEST_1
	msgbox gText_CutePokemon_IGottaGoMyBreak
	closemessage
	opendoor 15, 18
	waitdooranim
	applymovement 3, Quest_CutePokemon_WalkInside_Movement
	waitmovement 3
	playse SE_EXIT
	waitse
	removeobject 3
	release
	end

Quest_CutePokemon_Sub1_Correct_Dialogue_2:
	goto Quest_CutePokemon_CancelCheck_Dialogue
	goto Quest_CutePokemon_Sub1_Correct_Dialogue_1


Quest_CutePokemon_CheckPokemon_Script::
	special ChoosePartyMon
	waitstate
	compare VAR_RESULT, 255
	goto_if_eq Quest_CutePokemon_CheckPokemon_Script_2
Quest_CutePokemon_CheckPokemon_Script_1:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	return

Quest_CutePokemon_CheckPokemon_Script_2:
	goto Quest_CutePokemon_CancelCheck_Dialogue
	goto Quest_CutePokemon_CheckPokemon_Script_1


Quest_CutePokemon_Sub1_Hints_Dialogue::
	msgbox gText_CutePokemon_ISawThisCute
	compare VAR_CUTE_POKEMON_GUESS, -1
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_2
Quest_CutePokemon_Sub1_Hints_Dialogue_1:
	compare VAR_CUTE_POKEMON_GUESS, 0
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_5
Quest_CutePokemon_Sub1_Hints_Dialogue_4:
	compare VAR_CUTE_POKEMON_GUESS, 1
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_8
Quest_CutePokemon_Sub1_Hints_Dialogue_7:
	compare VAR_CUTE_POKEMON_GUESS, 2
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_11
Quest_CutePokemon_Sub1_Hints_Dialogue_10:
	return

Quest_CutePokemon_Sub1_Hints_Dialogue_2:
	msgbox gText_CutePokemon_ItDoesntNormally
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_1

Quest_CutePokemon_Sub1_Hints_Dialogue_5:
	msgbox gText_CutePokemon_ItHasBig
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_4

Quest_CutePokemon_Sub1_Hints_Dialogue_8:
	msgbox gText_CutePokemon_ItsLooksLikeItsWearing
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_7

Quest_CutePokemon_Sub1_Hints_Dialogue_11:
	msgbox gText_CutePokemon_WearingASkull
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_10


Quest_CutePokemon_PostQuest_Dialogue::
	return


Quest_CutePokemon_WalkInside_Movement:
	walk_left
	walk_up
	step_end

gText_CutePokemon_ChangedYourMind::
	.string "$"

gText_CutePokemon_NoThatsNotIt::
	.string "$"

gText_CutePokemon_YesDuskull::
	.string "$"

gText_CutePokemon_ItsSoCute::
	.string "$"

gText_CutePokemon_IGottaGoMyBreak::
	.string "$"

gText_CutePokemon_ISawThisCute::
	.string "$"

gText_CutePokemon_ItDoesntNormally::
	.string "$"

gText_CutePokemon_ItHasBig::
	.string "$"

gText_CutePokemon_ItsLooksLikeItsWearing::
	.string "$"

gText_CutePokemon_WearingASkull::
	.string "$"
