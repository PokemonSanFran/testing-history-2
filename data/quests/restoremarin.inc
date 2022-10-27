Quest_Restoremarin_MoveLenora_Script::
	compare VAR_STORYLINE_STATE, STORY_POST_BATTLE_ARCHER_TREASUREISLAND
	goto_if_gt Quest_Restoremarin_MoveLenora_Script_2
Quest_Restoremarin_MoveLenora_Script_1:
	return

Quest_Restoremarin_MoveLenora_Script_2:
	setobjectxy 7, 12, 18
	setobjectxyperm 7, 12, 18
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN
	goto Quest_Restoremarin_MoveLenora_Script_1


Quest_Restoremarin_HideLenora_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_HideLenora_Script_1
	return

Quest_Restoremarin_HideLenora_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_Restoremarin_CheckProgress_Script::
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_CheckProgress_Script_2
Quest_Restoremarin_CheckProgress_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_CheckProgress_Script_5
Quest_Restoremarin_CheckProgress_Script_4:
	compare VAR_TEMP_0, 2
	goto_if_eq Quest_Restoremarin_CheckProgress_Script_8
Quest_Restoremarin_CheckProgress_Script_7:
	return

Quest_Restoremarin_CheckProgress_Script_2:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_1, 1
	goto Quest_Restoremarin_CheckProgress_Script_1

Quest_Restoremarin_CheckProgress_Script_5:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_2, 1
	goto Quest_Restoremarin_CheckProgress_Script_4

Quest_Restoremarin_CheckProgress_Script_8:
	questmenu QUEST_MENU_SET_REWARD, QUEST_RESTOREMARIN
	goto Quest_Restoremarin_CheckProgress_Script_7


Quest_Restoremarin_BufferStrings_Part1_Script::
	bufferspeciesname STR_VAR_1, SPECIES_KRABBY
	buffermovename STR_VAR_2, MOVE_KNOCK_OFF
	return


Quest_Restoremarin_BufferStrings_Part2_Script::
	bufferspeciesname STR_VAR_1, SPECIES_COPPERAJAH
	buffermovename STR_VAR_2, MOVE_POWER_WHIP
	return


Quest_Restoremarin_StartQuest_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	msgbox gText_Restoremarin_YourePlayer
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Restoremarin_YeahImHelping
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	msgbox gText_Restoremarin_AreYouHelping
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Restoremarin_IHearThat
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	msgbox gText_Restoremarin_TheBestWay
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Restoremarin_RightBut
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	msgbox gText_Restoremarin_HmmI
	msgbox gText_Restoremarin_IHave
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Restoremarin_LikeTrainer
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	msgbox gText_Restoremarin_OhIDidnt
	msgbox gText_Restoremarin_TheresABattle
	msgbox gText_Restoremarin_CanYouBring
	msgbox gText_Restoremarin_IFIWant
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed_A
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed_B
	msgbox gText_Restoremarin_ComeBack
	callnative ClearMugshot
	startquest QUEST_RESTOREMARIN
	release
	end


Quest_Restoremarin_Active_Script::
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	call Quest_Restoremarin_CheckProgress_Script
	compare VAR_TEMP_1, 1
	goto_if_eq Quest_Restoremarin_Active_Script_2
	compare VAR_TEMP_2, 1
	goto_if_eq Quest_Restoremarin_Active_Script_3
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed_A
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed_B
Quest_Restoremarin_Active_Script_1:
	call Quest_Restoremarin_CheckPokemon_Script
	callnative ClearMugshot
	goto Quest_Restoremarin_JudgeMon_Script
	return

Quest_Restoremarin_Active_Script_2:
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed
	goto Quest_Restoremarin_Active_Script_1

Quest_Restoremarin_Active_Script_3:
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed
	goto Quest_Restoremarin_Active_Script_1


Quest_Restoremarin_CheckPokemon_Script::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq Quest_Restoremarin_CheckPokemon_Script_2
Quest_Restoremarin_CheckPokemon_Script_1:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	return

Quest_Restoremarin_CheckPokemon_Script_2:
	goto Quest_Restoremarin_Cancel_Dialogue
	goto Quest_Restoremarin_CheckPokemon_Script_1


Quest_Restoremarin_JudgeMon_Script::
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq Quest_Restoremarin_JudgeMon_Script_3
Quest_Restoremarin_JudgeMon_Script_1:
	compare VAR_RESULT, SPECIES_COPPERAJAH
	goto_if_eq Quest_Restoremarin_JudgeMon_Script_8
Quest_Restoremarin_JudgeMon_Script_6:
	goto Quest_Restoremarin_Cancel_Dialogue
	return

Quest_Restoremarin_JudgeMon_Script_2:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTOREMARIN, SUB_QUEST_1
	goto Quest_Restoremarin_TakeMon_Dialogue
	goto Quest_Restoremarin_JudgeMon_Script_1

Quest_Restoremarin_JudgeMon_Script_3:
	compare VAR_TEMP_1, 1
	goto_if_ne Quest_Restoremarin_JudgeMon_Script_2
	goto Quest_Restoremarin_JudgeMon_Script_1

Quest_Restoremarin_JudgeMon_Script_7:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTOREMARIN, SUB_QUEST_2
	goto Quest_Restoremarin_TakeMon_Dialogue
	goto Quest_Restoremarin_JudgeMon_Script_6

Quest_Restoremarin_JudgeMon_Script_8:
	compare VAR_TEMP_2, 1
	goto_if_ne Quest_Restoremarin_JudgeMon_Script_7
	goto Quest_Restoremarin_JudgeMon_Script_6


Quest_Restoremarin_TakeMon_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	msgbox gText_Restoremarin_Excellent, MSGBOX_NPC
	callnative ClearMugshot
	call Quest_Restoremarin_CheckProgress_Script
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_RESTOREMARIN
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_TakeMon_Dialogue_2
Quest_Restoremarin_TakeMon_Dialogue_1:
	end

Quest_Restoremarin_TakeMon_Dialogue_2:
	goto Quest_Restoremarin_Reward_Dialogue
	goto Quest_Restoremarin_TakeMon_Dialogue_1


Quest_Restoremarin_Cancel_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_LENORA
	callnative DrawMugshot
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed_A
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed_B
	msgbox gText_Restoremarin_ComeBack
	callnative ClearMugshot
	closemessage
	return


Quest_Restoremarin_Reward_Dialogue::
	msgbox Quest_Restoremarin_Reward_Dialogue_Text_0
	return


Quest_Restoremarin_Reward_Dialogue_Text_0:
	.string "test$"

gText_Restoremarin_YourePlayer::
	.string "You're {PLAYER} - Archer mentioned\n"
	.string "you'd be coming.$"

gText_Restoremarin_YeahImHelping::
	.string "Yeah, I'm helping them get their project\n"
	.string "off the ground.$"

gText_Restoremarin_AreYouHelping::
	.string "I meant what I said to Archer. I'll help\n"
	.string "get this off the ground, but we still\l"
	.string "need to figure out the next steps to\l"
	.string "taking down the whole League.$"

gText_Restoremarin_IHearThat::
	.string "That's a future goal though, right? We\n"
	.string "want to focus on helping Trainers in\l"
	.string "the region now.$"

gText_Restoremarin_TheBestWay::
	.string "I'm not interested in bandaid fixes.\n"
	.string "This new League is hurting people now,\l"
	.string "right?$"

gText_Restoremarin_RightBut::
	.string "Right! But we have something we can do,\n"
	.string "right now, to make things better, right\l"
	.string "now. Archer is gonna make this happen,\l"
	.string "but it would mean so much to get you\l"
	.string "onboard.$"

gText_Restoremarin_HmmI::
	.string "Hmm. That kid does seem driven. Let's\n"
	.string "see what I can do.$"

gText_Restoremarin_IHave::
	.string "I want to help Trainers learn to adapt.\n"
	.string "When everything that Trainers trust\l"
	.string "are stripped away, how can they make\l"
	.string "the best of the hand they've been\l"
	.string "dealt?$"

gText_Restoremarin_LikeTrainer::
	.string "Like the Trainers of SanFran?$"

gText_Restoremarin_OhIDidnt::
	.string "Oh! I didn't think of it like that. You're\n"
	.string "right.$"

gText_Restoremarin_TheresABattle::
	.string "There's a Battle Facility in Hoenn and\n"
	.string "Sinnoh that has a similar concept. A\l"
	.string "trainer's Pokémon is taken away from\l"
	.string "them, and they are forced to use rental\l"
	.string "Pokémon. How hard would that be for us\l"
	.string "to do...?$"

gText_Restoremarin_CanYouBring::
	.string "Can you bring me two Pokémon?$"

gText_Restoremarin_IFIWant::
	.string "If I want to start my own Battle\n"
	.string "Factory, we'll need to streamline to\l"
	.string "teaching moves to Pokémon.$"

gText_Restoremarin_DidYouFind::
	.string "Did you find the Pokémon I mentioned?$"

gText_Restoremarin_WeNeed_A::
	.string "We need a {STR_VAR_1} that knows\n"
	.string "{STR_VAR_2},$"

gText_Restoremarin_WeNeed_B::
	.string "and a {STR_VAR_1} that knows\n"
	.string "{STR_VAR_2}.$"

gText_Restoremarin_ComeBack::
	.string "Come back when you've caught one.$"

gText_Restoremarin_WeNeed::
	.string "We still need a {STR_VAR_1} that\n"
	.string "knows {STR_VAR_2}, but we're close!$"

gText_Restoremarin_Excellent::
	.string "Excellent! This is perfect.$"
