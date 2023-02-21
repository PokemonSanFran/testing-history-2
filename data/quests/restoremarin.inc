Quest_Restoremarin_Debug_Script::
	addvar VAR_TEMP_0, 1
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RESTOREMARIN
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoremarin_Debug_Script_2
Quest_Restoremarin_Debug_Script_1:
	release
	end

Quest_Restoremarin_Debug_Script_2:
	givemon SPECIES_KRABBY, 20, ITEM_NONE
	givemon SPECIES_COPPERAJAH, 20, ITEM_NONE
	goto Quest_Restoremarin_Debug_Script_1


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
	msgbox gText_Restoremarin_YourePlayer, , SPEAKER_LENORA
	msgbox gText_Restoremarin_YeahImHelping, , SPEAKER_ZOEY
	msgbox gText_Restoremarin_AreYouHelping, , SPEAKER_LENORA
	msgbox gText_Restoremarin_IHearThat, , SPEAKER_ZOEY
	msgbox gText_Restoremarin_TheBestWay, , SPEAKER_LENORA
	msgbox gText_Restoremarin_RightBut, , SPEAKER_ZOEY
	msgbox gText_Restoremarin_HmmI, , SPEAKER_LENORA
	msgbox gText_Restoremarin_IHave, , SPEAKER_LENORA
	msgbox gText_Restoremarin_LikeTrainer, , SPEAKER_ZOEY
	msgbox gText_Restoremarin_OhIDidnt, , SPEAKER_LENORA
	msgbox gText_Restoremarin_TheresABattle, , SPEAKER_LENORA
	msgbox gText_Restoremarin_CanYouBring, , SPEAKER_LENORA
	msgbox gText_Restoremarin_IFIWant, , SPEAKER_LENORA
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed_A, , SPEAKER_LENORA
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed_B, , SPEAKER_LENORA
	msgbox gText_Restoremarin_ComeBack, , SPEAKER_LENORA
	startquest QUEST_RESTOREMARIN
	release
	end


Quest_Restoremarin_Active_Script::
	call Quest_Restoremarin_CheckProgress_Script
	compare VAR_TEMP_1, 1
	goto_if_eq Quest_Restoremarin_Active_Script_2
	compare VAR_TEMP_2, 1
	goto_if_eq Quest_Restoremarin_Active_Script_3
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed_A, , SPEAKER_LENORA
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed_B, , SPEAKER_LENORA
Quest_Restoremarin_Active_Script_1:
	goto Quest_Restoremarin_CheckPokemon_Script
	return

Quest_Restoremarin_Active_Script_2:
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed, , SPEAKER_LENORA
	goto Quest_Restoremarin_Active_Script_1

Quest_Restoremarin_Active_Script_3:
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed, , SPEAKER_LENORA
	goto Quest_Restoremarin_Active_Script_1


Quest_Restoremarin_CheckPokemon_Script::
	special ChoosePartyMon
	waitstate
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq Quest_Restoremarin_CheckPokemon_Script_2
Quest_Restoremarin_CheckPokemon_Script_1:
	compare VAR_RESULT, SPECIES_KRABBY
	goto_if_eq Quest_Restoremarin_CheckPokemon_Script_6
Quest_Restoremarin_CheckPokemon_Script_4:
	compare VAR_RESULT, SPECIES_COPPERAJAH
	goto_if_eq Quest_Restoremarin_CheckPokemon_Script_11
Quest_Restoremarin_CheckPokemon_Script_9:
	goto Quest_Restoremarin_Cancel_Dialogue
	return

Quest_Restoremarin_CheckPokemon_Script_2:
	goto Quest_Restoremarin_Cancel_Dialogue
	goto Quest_Restoremarin_CheckPokemon_Script_1

Quest_Restoremarin_CheckPokemon_Script_5:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTOREMARIN, SUB_QUEST_1
	goto Quest_Restoremarin_TakeMon_Dialogue
	goto Quest_Restoremarin_CheckPokemon_Script_4

Quest_Restoremarin_CheckPokemon_Script_6:
	compare VAR_TEMP_1, 1
	goto_if_ne Quest_Restoremarin_CheckPokemon_Script_5
	goto Quest_Restoremarin_CheckPokemon_Script_4

Quest_Restoremarin_CheckPokemon_Script_10:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTOREMARIN, SUB_QUEST_2
	goto Quest_Restoremarin_TakeMon_Dialogue
	goto Quest_Restoremarin_CheckPokemon_Script_9

Quest_Restoremarin_CheckPokemon_Script_11:
	compare VAR_TEMP_2, 1
	goto_if_ne Quest_Restoremarin_CheckPokemon_Script_10
	goto Quest_Restoremarin_CheckPokemon_Script_9


Quest_Restoremarin_TakeMon_Dialogue::
	msgbox gText_Restoremarin_Excellent, MSGBOX_NPC, SPEAKER_LENORA
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
	call Quest_Restoremarin_BufferStrings_Part1_Script
	msgbox gText_Restoremarin_WeNeed_A, , SPEAKER_LENORA
	call Quest_Restoremarin_BufferStrings_Part2_Script
	msgbox gText_Restoremarin_WeNeed_B, , SPEAKER_LENORA
	msgbox gText_Restoremarin_ComeBack, , SPEAKER_LENORA
	closemessage
	return


Quest_Restoremarin_Reward_Dialogue::
	compare VAR_QUEST_RESTOREMARIN, SAVE_BEFORE_LENORA_BATTLE
	goto_if_eq Quest_Restoremarin_Reward_Dialogue_2
Quest_Restoremarin_Reward_Dialogue_1:
	setvar VAR_QUEST_RESTOREMARIN, SAVE_BEFORE_LENORA_BATTLE
	msgbox gText_Quest_Restoremarin_IAskedA, , SPEAKER_LENORA
	msgbox gText_Quest_Restoremarin_IAbsolutely, , SPEAKER_ZOEY
	msgbox gText_Quest_Restoremarin_HellIKindaWanna, , SPEAKER_LENORA
	call Common_EventScript_SaveGame
	closemessage
	goto Quest_Restoremarin_StartBattle_Script
	return

Quest_Restoremarin_Reward_Dialogue_2:
	goto Quest_Restoremarin_StartBattle_Script
	goto Quest_Restoremarin_Reward_Dialogue_1


Quest_Restoremarin_StartBattle_Script::
	lock
	msgbox gText_Quest_Restoremarin_OkayChampion, , SPEAKER_LENORA
	trainerbattle_no_intro TRAINER_GRETA, gText_Quest_Restoremarin_YoureTougherThan
	closemessage
	goto Quest_Restoremarin_PostBattle_Dialogue
	return


Quest_Restoremarin_PostBattle_Dialogue::
	lock
	setvar VAR_QUEST_RESTOREMARIN, DEFEATED_LENORA
	msgbox gText_Quest_Restoremarin_ManIfTrainersSeeYou, , SPEAKER_LENORA
	msgbox gText_Quest_Restoremarin_IThinkYoureGiving, , SPEAKER_ZOEY
	msgbox gText_Quest_Restoremarin_AndICantWait, , SPEAKER_LENORA
	msgbox gText_Quest_Restoremarin_IsThatYourGoal, , SPEAKER_ZOEY
	msgbox gText_Quest_Restoremarin_YeahThingsWere, , SPEAKER_LENORA
	msgbox gText_Quest_Restoremarin_YouCantGoBack, , SPEAKER_ZOEY
	msgbox gText_Quest_Restoremarin_YouDontGet, , SPEAKER_LENORA
	msgbox gText_Quest_Restoremarin_IWasntHere, , SPEAKER_ZOEY
	msgbox gText_Quest_Restoremarin_YourHeartFeels, , SPEAKER_LENORA
	closemessage
	opendoor 12, 17
	waitdooranim
	applymovement 7, Common_Movement_WalkUp
	waitmovement 7
	removeobject 7
	playse SE_EXIT
	waitse
	closedoor 12, 17
	waitdooranim
	completequest QUEST_RESTOREMARIN
	call LetsGrabLunch_CheckRestorationProgress_Script
	release
	end


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

gText_Quest_Restoremarin_IAskedA::
	.string "I asked a few others Trainer for similar\n"
	.string "things. I think after a few tests, we\l"
	.string "might have something going here! You\l"
	.string "should stop by and help us test it out.$"

gText_Quest_Restoremarin_IAbsolutely::
	.string "I absolutely will!$"

gText_Quest_Restoremarin_HellIKindaWanna::
	.string "Hell, I kinda wanna see it for myself\n"
	.string "right now. Are you really all that?$"

gText_Quest_Restoremarin_OkayChampion::
	.string "Okay Champion, bring it on!$"

gText_Quest_Restoremarin_YoureTougherThan::
	.string "You're tougher than expected!$"

gText_Quest_Restoremarin_ManIfTrainersSeeYou::
	.string "Man, if Trainers see you backing this\n"
	.string "and people already know how strong you\l"
	.string "are... we've got a shot at real\l"
	.string "legitimacy.$"

gText_Quest_Restoremarin_IThinkYoureGiving::
	.string "I think you're giving me too much\n"
	.string "credit! Believe it or not, Ycombinator's\l"
	.string "Kickstart problem was a huge part of\l"
	.string "the reason I was able to hone my skills\l"
	.string "this much.$"

gText_Quest_Restoremarin_AndICantWait::
	.string "And I can't wait to turn that power\n"
	.string "against those assholes. They're gonna\l"
	.string "collapse under their own weight, and\l"
	.string "then we can reinstate all the old gyms\l"
	.string "and go back to when times were good\l"
	.string "and I was running this joint!$"

gText_Quest_Restoremarin_IsThatYourGoal::
	.string "Is that your goal? Just go to back to\n"
	.string "the past?$"

gText_Quest_Restoremarin_YeahThingsWere::
	.string "Yeah! Things were so much better\n"
	.string "before.$"

gText_Quest_Restoremarin_YouCantGoBack::
	.string "Lenora, you can't go back to the past.\n"
	.string "You've gotta stick to the reality we've\l"
	.string "got right now. I think what you're going\l"
	.string "to do here is going to make a real\l"
	.string "difference for Trainers, and that's\l"
	.string "awesome. But if you want the Trainers\l"
	.string "of the region to be the best they can\l"
	.string "be, I think we need to figure out a path\l"
	.string "forward... in the present. That's what\l"
	.string "Archer and I want to do.$"

gText_Quest_Restoremarin_YouDontGet::
	.string "You don't get it, {PLAYER}, you\n"
	.string "weren't here for before.$"

gText_Quest_Restoremarin_IWasntHere::
	.string "I wasn't here, but I'm here now. And\n"
	.string "while I'm new, I'm really starting to\l"
	.string "love it here and I want to help\l"
	.string "Trainers, and help people, just like you\l"
	.string "do. And we can do that, moving forward.$"

gText_Quest_Restoremarin_YourHeartFeels::
	.string "Your heart feels like its in the right\n"
	.string "place. I gotta get back to work. Let's\l"
	.string "at least get this test off the ground.$"
