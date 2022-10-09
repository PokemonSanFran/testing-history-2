Quest_CutePokemon_Debug_Script::
	lock
	call Quest_CutePokemon_CountCompletedQuests_Script
	switch VAR_TEMP_0
	case 0, Quest_CutePokemon_Debug_Script_3
	case 1, Quest_CutePokemon_Debug_Script_4
	case 2, Quest_CutePokemon_Debug_Script_5
	case 3, Quest_CutePokemon_Debug_Script_6
Quest_CutePokemon_Debug_Script_1:
	release
	end

Quest_CutePokemon_Debug_Script_3:
	givemon SPECIES_DUSKULL, 100
	goto Quest_CutePokemon_Debug_Script_1

Quest_CutePokemon_Debug_Script_4:
	givemon SPECIES_SCRAFTY, 100
	goto Quest_CutePokemon_Debug_Script_1

Quest_CutePokemon_Debug_Script_5:
	givemon SPECIES_TEDDIURSA, 100
	goto Quest_CutePokemon_Debug_Script_1

Quest_CutePokemon_Debug_Script_6:
	givemon SPECIES_EISCUE, 100
	goto Quest_CutePokemon_Debug_Script_1


Quest_CutePokemon_HideMelissaA_Script::
	call Quest_CutePokemon_CountCompletedQuests_Script
	compare VAR_TEMP_0, 0
	goto_if_ne Quest_CutePokemon_HideMelissaA_Script_1
	return

Quest_CutePokemon_HideMelissaA_Script_1:
	setflag FLAG_TEMP_3
	return


Quest_CutePokemon_HideMelissaB_Script::
	call Quest_CutePokemon_CountCompletedQuests_Script
	compare VAR_TEMP_0, 1
	goto_if_ne Quest_CutePokemon_HideMelissaB_Script_1
	return

Quest_CutePokemon_HideMelissaB_Script_1:
	setflag FLAG_TEMP_5
	return


Quest_CutePokemon_HideMelissaC_Script::
	call Quest_CutePokemon_CountCompletedQuests_Script
	compare VAR_TEMP_0, 2
	goto_if_ne Quest_CutePokemon_HideMelissaC_Script_1
	return

Quest_CutePokemon_HideMelissaC_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_CutePokemon_HideMelissaD_Script::
	call Quest_CutePokemon_CountCompletedQuests_Script
	compare VAR_TEMP_0, 3
	goto_if_ne Quest_CutePokemon_HideMelissaD_Script_2
Quest_CutePokemon_HideMelissaD_Script_1:
	return

Quest_CutePokemon_HideMelissaD_Script_2:
	setflag FLAG_TEMP_6
	goto Quest_CutePokemon_HideMelissaD_Script_1


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
	msgbox gText_CutePokemon_ImTired, MSGBOX_NPC
	startquest QUEST_CUTEPOKEMON
	goto Quest_CutePokemon_Sub1_Event_Script
	return


Quest_CutePokemon_CountCompletedQuests_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_CountCompletedQuests_Script_2
Quest_CutePokemon_CountCompletedQuests_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_CountCompletedQuests_Script_5
Quest_CutePokemon_CountCompletedQuests_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_CountCompletedQuests_Script_8
Quest_CutePokemon_CountCompletedQuests_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CUTEPOKEMON, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_CutePokemon_CountCompletedQuests_Script_11
Quest_CutePokemon_CountCompletedQuests_Script_10:
	return

Quest_CutePokemon_CountCompletedQuests_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_CountCompletedQuests_Script_1

Quest_CutePokemon_CountCompletedQuests_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_CountCompletedQuests_Script_4

Quest_CutePokemon_CountCompletedQuests_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_CountCompletedQuests_Script_7

Quest_CutePokemon_CountCompletedQuests_Script_11:
	addvar VAR_TEMP_0, 1
	goto Quest_CutePokemon_CountCompletedQuests_Script_10


Quest_CutePokemon_SelectSubquest_Script::
	call Quest_CutePokemon_CountCompletedQuests_Script
	switch VAR_TEMP_0
	case 0, Quest_CutePokemon_SelectSubquest_Script_2
	case 1, Quest_CutePokemon_SelectSubquest_Script_3
	case 2, Quest_CutePokemon_SelectSubquest_Script_4
	case 3, Quest_CutePokemon_SelectSubquest_Script_5
	return

Quest_CutePokemon_SelectSubquest_Script_2:
	goto Quest_CutePokemon_Sub1_Event_Script
	return

Quest_CutePokemon_SelectSubquest_Script_3:
	goto Quest_CutePokemon_Sub2_Event_Script
	return

Quest_CutePokemon_SelectSubquest_Script_4:
	goto Quest_CutePokemon_Sub3_Event_Script
	return

Quest_CutePokemon_SelectSubquest_Script_5:
	goto Quest_CutePokemon_Sub4_Event_Script
	return


Quest_CutePokemon_CheckPokemon_Script::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq Quest_CutePokemon_CheckPokemon_Script_2
Quest_CutePokemon_CheckPokemon_Script_1:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	return

Quest_CutePokemon_CheckPokemon_Script_2:
	goto Quest_CutePokemon_CancelCheck_Dialogue
	goto Quest_CutePokemon_CheckPokemon_Script_1


Quest_CutePokemon_CancelCheck_Dialogue::
	msgbox gText_CutePokemon_ChangedYourMind
	release
	end


Quest_CutePokemon_Incorrect_Dialogue::
	addvar VAR_CUTE_POKEMON_GUESS, 1
	msgbox gText_CutePokemon_NoThatsNotIt
	release
	end


Quest_CutePokemon_ConfirmTake_Dialogue::
	msgbox gText_CutePokemon_ItsSoCute, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Quest_CutePokemon_ConfirmTake_Dialogue_2
Quest_CutePokemon_ConfirmTake_Dialogue_1:
	return

Quest_CutePokemon_ConfirmTake_Dialogue_2:
	goto Quest_CutePokemon_CancelCheck_Dialogue
	goto Quest_CutePokemon_ConfirmTake_Dialogue_1


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


Quest_CutePokemon_Sub1_Hints_Dialogue::
	msgbox gText_CutePokemon_ISawThisCute
	msgbox gText_CutePokemon_ItDoesntNormally
	compare VAR_CUTE_POKEMON_GUESS, 0
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_2
Quest_CutePokemon_Sub1_Hints_Dialogue_1:
	compare VAR_CUTE_POKEMON_GUESS, 1
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_5
Quest_CutePokemon_Sub1_Hints_Dialogue_4:
	compare VAR_CUTE_POKEMON_GUESS, 2
	goto_if_gt Quest_CutePokemon_Sub1_Hints_Dialogue_8
Quest_CutePokemon_Sub1_Hints_Dialogue_7:
	return

Quest_CutePokemon_Sub1_Hints_Dialogue_2:
	msgbox gText_CutePokemon_ItHasBig
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_1

Quest_CutePokemon_Sub1_Hints_Dialogue_5:
	msgbox gText_CutePokemon_ItsLooksLikeItsWearing
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_4

Quest_CutePokemon_Sub1_Hints_Dialogue_8:
	msgbox gText_CutePokemon_WearingASkull
	goto Quest_CutePokemon_Sub1_Hints_Dialogue_7


Quest_CutePokemon_Sub1_Correct_Dialogue::
	msgbox gText_CutePokemon_YesDuskull
	call Quest_CutePokemon_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CUTEPOKEMON, SUB_QUEST_1
	setvar VAR_CUTE_POKEMON_GUESS, 0
	goto Quest_CutePokemon_Sub1_ReturnToWork_Cutscene
	return


Quest_CutePokemon_Sub1_ReturnToWork_Cutscene::
	call Quest_CutePokemon_GiveItem_Script
	opendoor 9, 5
	waitdooranim
	applymovement 5, Quest_CutePokemon_WalkInside_Movement
	waitmovement 5
	playse SE_EXIT
	waitse
	removeobject 5
	closedoor 9, 5
	waitdooranim
	release
	end


Quest_CutePokemon_Sub2_Event_Script::
	call Quest_CutePokemon_Sub2_Battle_Script
	call Quest_CutePokemon_Sub2_Hints_Dialogue
	call Quest_CutePokemon_CheckPokemon_Script
	compare VAR_RESULT, SPECIES_SCRAFTY
	goto_if_eq Quest_CutePokemon_Sub2_Event_Script_1
	goto Quest_CutePokemon_Incorrect_Dialogue
	return

Quest_CutePokemon_Sub2_Event_Script_1:
	goto Quest_CutePokemon_Sub2_Correct_Dialogue
	return


Quest_CutePokemon_Sub2_Battle_Script::
	checktrainerflag TRAINER_RICKY_1
	goto_if 0, Quest_CutePokemon_Sub2_Battle_Script_2
Quest_CutePokemon_Sub2_Battle_Script_1:
	return

Quest_CutePokemon_Sub2_Battle_Script_2:
	msgbox gText_CutePokemon_HeyItsYou
	trainerbattle_no_intro TRAINER_RICKY_1, gText_CutePokemon_ButTheyreStillCute
	goto Quest_CutePokemon_Sub2_Battle_Script_1


Quest_CutePokemon_Sub2_Hints_Dialogue::
	msgbox gText_CutePokemon_ISawAnother
	msgbox gText_CutePokemon_BreedsWithDragons
	compare VAR_CUTE_POKEMON_GUESS, 0
	goto_if_gt Quest_CutePokemon_Sub2_Hints_Dialogue_2
Quest_CutePokemon_Sub2_Hints_Dialogue_1:
	compare VAR_CUTE_POKEMON_GUESS, 1
	goto_if_gt Quest_CutePokemon_Sub2_Hints_Dialogue_5
Quest_CutePokemon_Sub2_Hints_Dialogue_4:
	compare VAR_CUTE_POKEMON_GUESS, 2
	goto_if_gt Quest_CutePokemon_Sub2_Hints_Dialogue_8
Quest_CutePokemon_Sub2_Hints_Dialogue_7:
	return

Quest_CutePokemon_Sub2_Hints_Dialogue_2:
	msgbox gText_CutePokemon_ItsMostlyOrange
	goto Quest_CutePokemon_Sub2_Hints_Dialogue_1

Quest_CutePokemon_Sub2_Hints_Dialogue_5:
	msgbox gText_CutePokemon_TheyCanSprayAcid
	goto Quest_CutePokemon_Sub2_Hints_Dialogue_4

Quest_CutePokemon_Sub2_Hints_Dialogue_8:
	msgbox gText_CutePokemon_HasAMohawk
	goto Quest_CutePokemon_Sub2_Hints_Dialogue_7


Quest_CutePokemon_Sub2_Correct_Dialogue::
	msgbox gText_CutePokemon_YesScrafty
	call Quest_CutePokemon_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CUTEPOKEMON, SUB_QUEST_2
	setvar VAR_CUTE_POKEMON_GUESS, 0
	goto Quest_CutePokemon_Sub2_ReturnToWork_Cutscene
	return


Quest_CutePokemon_Sub2_ReturnToWork_Cutscene::
	call Quest_CutePokemon_GiveItem_Script
	opendoor 2, 16
	waitdooranim
	applymovement 9, Quest_CutePokemon_WalkInside_Movement
	waitmovement 9
	playse SE_EXIT
	waitse
	removeobject 9
	closedoor 2, 16
	waitdooranim
	release
	end


Quest_CutePokemon_Sub3_Battle_Script::
	checktrainerflag TRAINER_RICKY_2
	goto_if 0, Quest_CutePokemon_Sub3_Battle_Script_2
Quest_CutePokemon_Sub3_Battle_Script_1:
	return

Quest_CutePokemon_Sub3_Battle_Script_2:
	msgbox gText_CutePokemon_HeyItsYou
	trainerbattle_no_intro TRAINER_RICKY_2, gText_CutePokemon_ButTheyreStillCute
	goto Quest_CutePokemon_Sub3_Battle_Script_1


Quest_CutePokemon_Sub3_Event_Script::
	call Quest_CutePokemon_Sub3_Battle_Script
	call Quest_CutePokemon_Sub3_Hints_Dialogue
	call Quest_CutePokemon_CheckPokemon_Script
	compare VAR_RESULT, SPECIES_TEDDIURSA
	goto_if_eq Quest_CutePokemon_Sub3_Event_Script_1
	goto Quest_CutePokemon_Incorrect_Dialogue
	return

Quest_CutePokemon_Sub3_Event_Script_1:
	goto Quest_CutePokemon_Sub3_Correct_Dialogue
	return


Quest_CutePokemon_Sub3_Hints_Dialogue::
	msgbox gText_CutePokemon_ISawThisCute
	msgbox gText_CutePokemon_ItsANormal
	compare VAR_CUTE_POKEMON_GUESS, 0
	goto_if_gt Quest_CutePokemon_Sub3_Hints_Dialogue_2
Quest_CutePokemon_Sub3_Hints_Dialogue_1:
	compare VAR_CUTE_POKEMON_GUESS, 1
	goto_if_gt Quest_CutePokemon_Sub3_Hints_Dialogue_5
Quest_CutePokemon_Sub3_Hints_Dialogue_4:
	compare VAR_CUTE_POKEMON_GUESS, 2
	goto_if_gt Quest_CutePokemon_Sub3_Hints_Dialogue_8
Quest_CutePokemon_Sub3_Hints_Dialogue_7:
	return

Quest_CutePokemon_Sub3_Hints_Dialogue_2:
	msgbox gText_CutePokemon_IfYoureReallyLucky
	goto Quest_CutePokemon_Sub3_Hints_Dialogue_1

Quest_CutePokemon_Sub3_Hints_Dialogue_5:
	msgbox gText_CutePokemon_ItsAboutTwo
	goto Quest_CutePokemon_Sub3_Hints_Dialogue_4

Quest_CutePokemon_Sub3_Hints_Dialogue_8:
	msgbox gText_CutePokemon_ItLikesHoney
	goto Quest_CutePokemon_Sub3_Hints_Dialogue_7


Quest_CutePokemon_Sub3_Correct_Dialogue::
	msgbox gText_CutePokemon_YesTeddiursa
	call Quest_CutePokemon_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CUTEPOKEMON, SUB_QUEST_3
	setvar VAR_CUTE_POKEMON_GUESS, 0
	goto Quest_CutePokemon_Sub3_ReturnToWork_Cutscene
	return


Quest_CutePokemon_Sub3_ReturnToWork_Cutscene::
	call Quest_CutePokemon_GiveItem_Script
	opendoor 25, 33
	waitdooranim
	applymovement 2, Quest_CutePokemon_WalkInside_Movement
	waitmovement 2
	playse SE_EXIT
	waitse
	removeobject 2
	closedoor 25, 33
	waitdooranim
	release
	end


Quest_CutePokemon_Sub4_Battle_Script::
	checktrainerflag TRAINER_RICKY_3
	goto_if 0, Quest_CutePokemon_Sub4_Battle_Script_2
Quest_CutePokemon_Sub4_Battle_Script_1:
	return

Quest_CutePokemon_Sub4_Battle_Script_2:
	msgbox gText_CutePokemon_HeyItsYou
	trainerbattle_no_intro TRAINER_RICKY_3, gText_CutePokemon_ButTheyreStillCute
	goto Quest_CutePokemon_Sub4_Battle_Script_1


Quest_CutePokemon_Sub4_Event_Script::
	call Quest_CutePokemon_Sub4_Battle_Script
	call Quest_CutePokemon_Sub4_Hints_Dialogue
	call Quest_CutePokemon_CheckPokemon_Script
	compare VAR_RESULT, SPECIES_EISCUE
	goto_if_eq Quest_CutePokemon_Sub4_Event_Script_1
	goto Quest_CutePokemon_Incorrect_Dialogue
	return

Quest_CutePokemon_Sub4_Event_Script_1:
	goto Quest_CutePokemon_Sub4_Correct_Dialogue
	return


Quest_CutePokemon_Sub4_Hints_Dialogue::
	msgbox gText_CutePokemon_ISawThisCute
	msgbox gText_CutePokemon_ItLikesTheCold
	compare VAR_CUTE_POKEMON_GUESS, 0
	goto_if_gt Quest_CutePokemon_Sub4_Hints_Dialogue_2
Quest_CutePokemon_Sub4_Hints_Dialogue_1:
	compare VAR_CUTE_POKEMON_GUESS, 1
	goto_if_gt Quest_CutePokemon_Sub4_Hints_Dialogue_5
Quest_CutePokemon_Sub4_Hints_Dialogue_4:
	compare VAR_CUTE_POKEMON_GUESS, 2
	goto_if_gt Quest_CutePokemon_Sub4_Hints_Dialogue_8
Quest_CutePokemon_Sub4_Hints_Dialogue_7:
	return

Quest_CutePokemon_Sub4_Hints_Dialogue_2:
	msgbox gText_CutePokemon_ItLooksWorried
	goto Quest_CutePokemon_Sub4_Hints_Dialogue_1

Quest_CutePokemon_Sub4_Hints_Dialogue_5:
	msgbox gText_CutePokemon_ItsBlackAndWhite
	goto Quest_CutePokemon_Sub4_Hints_Dialogue_4

Quest_CutePokemon_Sub4_Hints_Dialogue_8:
	msgbox gText_CutePokemon_ItsFromGalar
	goto Quest_CutePokemon_Sub4_Hints_Dialogue_7


Quest_CutePokemon_Sub4_Correct_Dialogue::
	msgbox gText_CutePokemon_YesEiscue
	call Quest_CutePokemon_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CUTEPOKEMON, SUB_QUEST_4
	setvar VAR_CUTE_POKEMON_GUESS, 0
	goto Quest_CutePokemon_Sub4_ReturnToWork_Cutscene
	return


Quest_CutePokemon_Sub4_ReturnToWork_Cutscene::
	call Quest_CutePokemon_GiveItem_Script
	opendoor 16, 30
	waitdooranim
	applymovement 23, Quest_CutePokemon_WalkInside_Movement
	waitmovement 23
	playse SE_EXIT
	waitse
	removeobject 23
	closedoor 16, 30
	waitdooranim
	completequest QUEST_CUTEPOKEMON
	release
	end


Quest_CutePokemon_GiveItem_Script::
	msgbox gText_CutePokemon_IGottaGoMyBreak
	call Quest_CutePokemon_CountCompletedQuests_Script
	switch VAR_TEMP_0
	case 1, Quest_CutePokemon_GiveItem_Script_3
	case 2, Quest_CutePokemon_GiveItem_Script_4
	case 3, Quest_CutePokemon_GiveItem_Script_5
	case 4, Quest_CutePokemon_GiveItem_Script_6
Quest_CutePokemon_GiveItem_Script_1:
	closemessage
	return

Quest_CutePokemon_GiveItem_Script_3:
	giveitem ITEM_RED_SCARF, 1
	goto Quest_CutePokemon_GiveItem_Script_1

Quest_CutePokemon_GiveItem_Script_4:
	giveitem ITEM_GREEN_SCARF, 1
	goto Quest_CutePokemon_GiveItem_Script_1

Quest_CutePokemon_GiveItem_Script_5:
	giveitem ITEM_BLUE_SCARF, 1
	goto Quest_CutePokemon_GiveItem_Script_1

Quest_CutePokemon_GiveItem_Script_6:
	giveitem ITEM_PINK_SCARF, 1
	goto Quest_CutePokemon_GiveItem_Script_1


Quest_CutePokemon_PostQuest_Dialogue::
	return


Quest_CutePokemon_WalkInside_Movement:
	walk_left
	walk_up
	step_end

gText_CutePokemon_ChangedYourMind::
	.string "changed your mind? das coo$"

gText_CutePokemon_NoThatsNotIt::
	.string "no thats not it...$"

gText_CutePokemon_YesDuskull::
	.string "yes! duskull$"

gText_CutePokemon_ItsSoCute::
	.string "its so cute. are you sure i can have it?$"

gText_CutePokemon_IGottaGoMyBreak::
	.string "i gotta go my break is over. quick, take\n"
	.string "this, i made it!$"

gText_CutePokemon_ImTired::
	.string "i'm tired.... this job is so nuts! i work\n"
	.string "like 80 hours. i just wanna quit and be\l"
	.string "a trainer and catch cute pokemon...\l"
	.string "you're a trainer! can you catch cute\l"
	.string "pokemon for me?$"

gText_CutePokemon_ISawThisCute::
	.string "I saw this cute Pokémon I want! But I\n"
	.string "don't remember its name.. Can you catch\l"
	.string "me one? I'd love to explore but I'm too\l"
	.string "busy between my crazy job...$"

gText_CutePokemon_ItDoesntNormally::
	.string "it doesn't normally touch the ground$"

gText_CutePokemon_ItHasBig::
	.string "it has big eyes$"

gText_CutePokemon_ItsLooksLikeItsWearing::
	.string "it looks like its wearing something$"

gText_CutePokemon_WearingASkull::
	.string "looks like its wearing a skull$"

gText_CutePokemon_HeyItsYou::
	.string "hey its you i trained that cutie got me.\n"
	.string "lets battle!$"

gText_CutePokemon_ButTheyreStillCute::
	.string "but they're still soooo cute$"

gText_CutePokemon_ISawAnother::
	.string "I saw ANOTHER cute Pokémon! But I don't\n"
	.string "remember its name... Can you catch me\l"
	.string "one?$"

gText_CutePokemon_BreedsWithDragons::
	.string "It breeds with Dragon-type Pokémon!$"

gText_CutePokemon_ItsMostlyOrange::
	.string "Its mostly orange.$"

gText_CutePokemon_TheyCanSprayAcid::
	.string "They can spray acid!$"

gText_CutePokemon_HasAMohawk::
	.string "it has a mohawk$"

gText_CutePokemon_YesScrafty::
	.string "yas scrafty$"

gText_CutePokemon_ItsANormal::
	.string "Its a normal type$"

gText_CutePokemon_IfYoureReallyLucky::
	.string "if you're really lucky, they're green$"

gText_CutePokemon_ItsAboutTwo::
	.string "its about two feet tall$"

gText_CutePokemon_ItLikesHoney::
	.string "it likes honey$"

gText_CutePokemon_YesTeddiursa::
	.string "yasss Teddiursa!$"

gText_CutePokemon_ItLikesTheCold::
	.string "it likes the cold!$"

gText_CutePokemon_ItLooksWorried::
	.string "it looks worried all the time$"

gText_CutePokemon_ItsBlackAndWhite::
	.string "its black and white and kinda blue$"

gText_CutePokemon_ItsFromGalar::
	.string "its from galar$"

gText_CutePokemon_YesEiscue::
	.string "yass Eiscue!$"
