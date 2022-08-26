Quest_WallaceArmy_HideObject_Script::
	setflag FLAG_TEMP_1
	return


Quest_WallaceArmy_PreQuest_Dialogue::
	goto_if_set FLAG_IS_CHAMPION, Quest_WallaceArmy_PreQuest_Dialogue_2
	msgbox gText_WallaceArmy_WhatMakesThemThinkTheyCanTreat, MSGBOX_NPC
Quest_WallaceArmy_PreQuest_Dialogue_1:
	end

Quest_WallaceArmy_PreQuest_Dialogue_2:
	goto Quest_WallaceArmy_QuestStart_Dialogue
	goto Quest_WallaceArmy_PreQuest_Dialogue_1


Quest_WallaceArmy_CheckQuestState_Script::
	lock
	returnqueststate QUEST_WALLACEARMY
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_WallaceArmy_CheckQuestState_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Quest_WallaceArmy_CheckQuestState_Script_3
	goto Quest_WallaceArmy_PreQuest_Dialogue
	return

Quest_WallaceArmy_CheckQuestState_Script_2:
	goto Quest_WallaceArmy_Active_Dialogue
	return

Quest_WallaceArmy_CheckQuestState_Script_3:
	goto Quest_WallaceArmy_CompleteDialogue
	return


Quest_WallaceArmy_QuestStart_Dialogue::
	msgbox gText_WallaceArmy_TheseKidsAreGonnaRuin, MSGBOX_NPC
	msgbox gText_WallaceArmy_FirstTheBidNowTheDamnKids
	msgbox gText_WallaceArmy_OhTheChampionJustWhat
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WallaceArmy_TheLeagueDidntSend
	callnative ClearMugshot
	msgbox gText_WallaceArmy_SighWereMarinSolar
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WallaceArmy_YouThinkTheLeague
	callnative ClearMugshot
	msgbox gText_WallaceArmy_LookIHaveNoIdea
	startquest QUEST_WALLACEARMY
	return


Quest_WallaceArmy_Active_Dialogue::
	call Quest_WallaceArmy_CheckCompletionRate_Script
	call Quest_WallaceArmy_ListRemainingLocations_Script
	lock
	msgbox gText_WallaceArmy_LooksLikeThereStill
	end


Quest_WallaceArmy_Reward_Cutscene::
	lock
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Quest_WallaceArmy_Reward_Cutscene_2
	applymovement 1, Quest_WallaceArmy_ExclaimAndWalkToPlayer_Movement
	waitmovement 1
	msgbox gText_WallaceArmy_WereBackUp
	msgbox gText_WallaceArmy_TheStanArmyWillNeverDie
	closemessage
	call Quest_WallaceArmy_LeadStanAppearance_Script
	applymovement OBJ_EVENT_ID_PLAYER, Quest_WallaceArmy_ExclaimAndFaceNorth_Movement
	applymovement 1, Quest_WallaceArmy_ExclaimAndFaceNorth_Movement
	waitmovement 1
	msgbox gText_WallaceArmy_HowDidYouGetInHere
	msgbox gText_WallaceArmy_WhatIsThatMusic
	msgbox gText_WallaceArmy_OurArmyWillAlwaysPrevail
	closemessage
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	msgbox gText_WallaceArmy_ImLeahLeaderOfTheStanArmy
	msgbox gText_WallaceArmy_WaitYoureTheLeader
	msgbox gText_WallaceArmy_CanItOldMan
	msgbox gText_WallaceArmy_AndYouAttackingTheArmy
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	goto Quest_WallaceArmy_StartBattle_Script
	return

Quest_WallaceArmy_Reward_Cutscene_2:
	setvar VAR_TEMP_0, 1
	release
	end


Quest_WallaceArmy_StartBattle_Script::
	msgbox gText_WallaceArmy_ACrimePunishableByDeath
	trainerbattle_no_intro TRAINER_ROSE_3, gText_WallaceArmy_MyLord
	closemessage
	goto Quest_WallaceArmy_PostBattle_Script
	return


Quest_WallaceArmy_PostBattle_Script::
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	msgbox gText_WallaceArmy_WhyAreYouDefending
	msgbox gText_WallaceArmy_WeReallyHadNothing
	fadescreen FADE_TO_BLACK
	fadedefaultbgm
	delay 32
	call Quest_WallaceArmy_MoveAllObjects_Script
	fadescreen FADE_FROM_BLACK
	msgbox gText_WallaceArmy_ThatsTheWholeStorySee
	msgbox gText_WallaceArmy_ThereWasNoWallaceAtAll
	msgbox gText_WallaceArmy_IStillDontKnowWhoThatIs
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	msgbox gText_WallaceArmy_ImSorryForAttacking
	giveitem ITEM_LIFE_ORB, 1
	applymovement 3, Quest_WallaceArmy_WalkOut_Movement
	waitmovement 3
	playse SE_EXIT
	waitse
	removeobject 3
	applymovement 1, Common_Movement_FaceUp
	waitmovement 1
	completequest QUEST_WALLACEARMY
	release
	end


Quest_WallaceArmy_CompleteDialogue::
	msgbox gText_WallaceArmy_ThankYouForStopping, MSGBOX_NPC
	end


Quest_WallaceArmy_MoveAllObjects_Script::
	setobjectxy 1, 2, 4
	setobjectxyperm 1, 2, 4
	setobjectxy 3, 2, 4
	setobjectxyperm 3, 2, 4
	applymovement 3, Common_Movement_FaceUp
	waitmovement 3
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 6
	TeleportCamera 1, 6
	return


Quest_WallaceArmy_LeadStanAppearance_Script::
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	addobject 3
	delay 16
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	fadescreen FADE_FROM_BLACK
	return


Quest_WallaceArmy_ListRemainingLocations_Script::
	compare VAR_TEMP_1, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_2
Quest_WallaceArmy_ListRemainingLocations_Script_1:
	compare VAR_TEMP_2, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_5
Quest_WallaceArmy_ListRemainingLocations_Script_4:
	compare VAR_TEMP_3, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_8
Quest_WallaceArmy_ListRemainingLocations_Script_7:
	compare VAR_TEMP_4, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_11
Quest_WallaceArmy_ListRemainingLocations_Script_10:
	compare VAR_TEMP_5, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_14
Quest_WallaceArmy_ListRemainingLocations_Script_13:
	return

Quest_WallaceArmy_ListRemainingLocations_Script_2:
	bufferstring STR_VAR_1, gText_Alameda
	goto Quest_WallaceArmy_ListRemainingLocations_Script_1

Quest_WallaceArmy_ListRemainingLocations_Script_5:
	bufferstring STR_VAR_2, gText_Haightashbury
	goto Quest_WallaceArmy_ListRemainingLocations_Script_4

Quest_WallaceArmy_ListRemainingLocations_Script_8:
	bufferstring STR_VAR_3, gText_SOMA
	goto Quest_WallaceArmy_ListRemainingLocations_Script_7

Quest_WallaceArmy_ListRemainingLocations_Script_11:
	bufferstring STR_VAR_3, gText_Berkeley
	goto Quest_WallaceArmy_ListRemainingLocations_Script_10

Quest_WallaceArmy_ListRemainingLocations_Script_14:
	bufferstring STR_VAR_3, gText_Marin
	goto Quest_WallaceArmy_ListRemainingLocations_Script_13


Quest_WallaceArmy_CheckCompletionRate_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Quest_WallaceArmy_CheckCompletionRate_Script_2
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_5
Quest_WallaceArmy_CheckCompletionRate_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_8
Quest_WallaceArmy_CheckCompletionRate_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_11
Quest_WallaceArmy_CheckCompletionRate_Script_10:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_14
Quest_WallaceArmy_CheckCompletionRate_Script_13:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_17
Quest_WallaceArmy_CheckCompletionRate_Script_16:
	compare VAR_TEMP_0, 5
	goto_if_eq Quest_WallaceArmy_CheckCompletionRate_Script_19
	return

Quest_WallaceArmy_CheckCompletionRate_Script_2:
	return

Quest_WallaceArmy_CheckCompletionRate_Script_5:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_1, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_4

Quest_WallaceArmy_CheckCompletionRate_Script_8:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_2, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_7

Quest_WallaceArmy_CheckCompletionRate_Script_11:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_3, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_10

Quest_WallaceArmy_CheckCompletionRate_Script_14:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_4, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_13

Quest_WallaceArmy_CheckCompletionRate_Script_17:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_5, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_16

Quest_WallaceArmy_CheckCompletionRate_Script_19:
	questmenu QUEST_MENU_SET_REWARD, QUEST_WALLACEARMY
	return


Quest_WallaceArmy_ExclaimAndWalkToPlayer_Movement:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Quest_WallaceArmy_ExclaimAndFaceNorth_Movement:
	emote_exclamation_mark
	face_up
	step_end

Quest_WallaceArmy_WalkOut_Movement:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_WallaceArmy_WhatMakesThemThinkTheyCanTreat::
	.string "$"

gText_WallaceArmy_TheseKidsAreGonnaRuin::
	.string "$"

gText_WallaceArmy_FirstTheBidNowTheDamnKids::
	.string "$"

gText_WallaceArmy_OhTheChampionJustWhat::
	.string "$"

gText_WallaceArmy_TheLeagueDidntSend::
	.string "$"

gText_WallaceArmy_SighWereMarinSolar::
	.string "$"

gText_WallaceArmy_YouThinkTheLeague::
	.string "$"

gText_WallaceArmy_LookIHaveNoIdea::
	.string "$"

gText_WallaceArmy_LooksLikeThereStill::
	.string "$"

gText_WallaceArmy_WereBackUp::
	.string "$"

gText_WallaceArmy_TheStanArmyWillNeverDie::
	.string "$"

gText_WallaceArmy_HowDidYouGetInHere::
	.string "$"

gText_WallaceArmy_WhatIsThatMusic::
	.string "$"

gText_WallaceArmy_OurArmyWillAlwaysPrevail::
	.string "$"

gText_WallaceArmy_ImLeahLeaderOfTheStanArmy::
	.string "$"

gText_WallaceArmy_WaitYoureTheLeader::
	.string "$"

gText_WallaceArmy_CanItOldMan::
	.string "$"

gText_WallaceArmy_AndYouAttackingTheArmy::
	.string "$"

gText_WallaceArmy_ACrimePunishableByDeath::
	.string "$"

gText_WallaceArmy_MyLord::
	.string "$"

gText_WallaceArmy_WhyAreYouDefending::
	.string "$"

gText_WallaceArmy_WeReallyHadNothing::
	.string "$"

gText_WallaceArmy_ThatsTheWholeStorySee::
	.string "$"

gText_WallaceArmy_ThereWasNoWallaceAtAll::
	.string "$"

gText_WallaceArmy_IStillDontKnowWhoThatIs::
	.string "$"

gText_WallaceArmy_ImSorryForAttacking::
	.string "$"

gText_WallaceArmy_ThankYouForStopping::
	.string "$"
