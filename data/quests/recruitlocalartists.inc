Quest_Recruitlocalartists_Sabrina_Visibility_Script::
	setvar VAR_TEMP_0, 0
	special GetNumberOfBadges
	compare VAR_RESULT, 5
	goto_if_lt Quest_Recruitlocalartists_Sabrina_Visibility_Script_2
Quest_Recruitlocalartists_Sabrina_Visibility_Script_1:
	returnqueststate QUEST_RECRUITLOCALARTISTS
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Quest_Recruitlocalartists_Sabrina_Visibility_Script_5
Quest_Recruitlocalartists_Sabrina_Visibility_Script_4:
	compare VAR_STORYLINE_STATE, STORY_ARCHER_EXPLAIN_RESTORATION
	goto_if_gt Quest_Recruitlocalartists_Sabrina_Visibility_Script_9
Quest_Recruitlocalartists_Sabrina_Visibility_Script_7:
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_Recruitlocalartists_Sabrina_Visibility_Script_13
Quest_Recruitlocalartists_Sabrina_Visibility_Script_12:
	return

Quest_Recruitlocalartists_Sabrina_Visibility_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_Sabrina_Visibility_Script_1

Quest_Recruitlocalartists_Sabrina_Visibility_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_Sabrina_Visibility_Script_4

Quest_Recruitlocalartists_Sabrina_Visibility_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_Sabrina_Visibility_Script_7

Quest_Recruitlocalartists_Sabrina_Visibility_Script_9:
	compare VAR_STORYLINE_STATE, STORY_RECIEVED_BAMBOO_STAR
	goto_if_ne Quest_Recruitlocalartists_Sabrina_Visibility_Script_8
	goto Quest_Recruitlocalartists_Sabrina_Visibility_Script_7

Quest_Recruitlocalartists_Sabrina_Visibility_Script_13:
	setflag FLAG_TEMP_2
	goto Quest_Recruitlocalartists_Sabrina_Visibility_Script_12


Quest_Recruitlocalartists_Smeargle_Visibility_Script::
	call Quest_Recruitlocalartists_SetSmearglePosition_Script
	setvar VAR_TEMP_0, 0
	returnqueststate QUEST_RECRUITLOCALARTISTS
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_ne Quest_Recruitlocalartists_Smeargle_Visibility_Script_2
Quest_Recruitlocalartists_Smeargle_Visibility_Script_1:
	compare VAR_QUEST_RECRUITLOLCAARTISTS, SMEARGLE_LOCAL_2
	goto_if_ne Quest_Recruitlocalartists_Smeargle_Visibility_Script_5
Quest_Recruitlocalartists_Smeargle_Visibility_Script_4:
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_Recruitlocalartists_Smeargle_Visibility_Script_8
Quest_Recruitlocalartists_Smeargle_Visibility_Script_7:
	return

Quest_Recruitlocalartists_Smeargle_Visibility_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_Smeargle_Visibility_Script_1

Quest_Recruitlocalartists_Smeargle_Visibility_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_Smeargle_Visibility_Script_4

Quest_Recruitlocalartists_Smeargle_Visibility_Script_8:
	setflag FLAG_TEMP_1
	goto Quest_Recruitlocalartists_Smeargle_Visibility_Script_7


Quest_Recruitlocalartists_SetSmearglePosition_Script::
	random 8
	switch VAR_RESULT
	case 0, Quest_Recruitlocalartists_SetSmearglePosition_Script_3
	case 1, Quest_Recruitlocalartists_SetSmearglePosition_Script_4
	case 2, Quest_Recruitlocalartists_SetSmearglePosition_Script_5
	case 3, Quest_Recruitlocalartists_SetSmearglePosition_Script_6
	case 4, Quest_Recruitlocalartists_SetSmearglePosition_Script_7
	case 5, Quest_Recruitlocalartists_SetSmearglePosition_Script_8
	case 6, Quest_Recruitlocalartists_SetSmearglePosition_Script_9
	case 7, Quest_Recruitlocalartists_SetSmearglePosition_Script_10
	setobjectxy 4, 12, 4
	setobjectxyperm 4, 12, 4
Quest_Recruitlocalartists_SetSmearglePosition_Script_1:
	return

Quest_Recruitlocalartists_SetSmearglePosition_Script_3:
	setobjectxy 4, 3, 8
	setobjectxyperm 4, 3, 8
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_4:
	setobjectxy 4, 2, 14
	setobjectxyperm 4, 2, 14
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_5:
	setobjectxy 4, 7, 19
	setobjectxyperm 4, 7, 19
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_6:
	setobjectxy 4, 15, 19
	setobjectxyperm 4, 15, 19
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_7:
	setobjectxy 4, 36, 24
	setobjectxyperm 4, 36, 24
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_8:
	setobjectxy 4, 29, 13
	setobjectxyperm 4, 29, 13
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_9:
	setobjectxy 4, 21, 13
	setobjectxyperm 4, 21, 13
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1

Quest_Recruitlocalartists_SetSmearglePosition_Script_10:
	setobjectxy 4, 25, 4
	setobjectxyperm 4, 25, 4
	goto Quest_Recruitlocalartists_SetSmearglePosition_Script_1


Quest_Recruitlocalartists_CountSubquest_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RECRUITLOCALARTISTS, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Recruitlocalartists_CountSubquest_Script_2
Quest_Recruitlocalartists_CountSubquest_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RECRUITLOCALARTISTS, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_Recruitlocalartists_CountSubquest_Script_5
Quest_Recruitlocalartists_CountSubquest_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RECRUITLOCALARTISTS, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_Recruitlocalartists_CountSubquest_Script_8
Quest_Recruitlocalartists_CountSubquest_Script_7:
	return

Quest_Recruitlocalartists_CountSubquest_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_CountSubquest_Script_1

Quest_Recruitlocalartists_CountSubquest_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_CountSubquest_Script_4

Quest_Recruitlocalartists_CountSubquest_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_Recruitlocalartists_CountSubquest_Script_7


Quest_Recruitlocalartists_ProgressReward_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RECRUITLOCALARTISTS
	compare VAR_RESULT, 0
	goto_if_eq Quest_Recruitlocalartists_ProgressReward_Script_2
	call Quest_Recruitlocalartists_CountSubquest_Script
	compare VAR_TEMP_0, 3
	goto_if_eq Quest_Recruitlocalartists_ProgressReward_Script_5
Quest_Recruitlocalartists_ProgressReward_Script_4:
	return
	closemessage
	return

Quest_Recruitlocalartists_ProgressReward_Script_2:
	release
	end

Quest_Recruitlocalartists_ProgressReward_Script_5:
	questmenu QUEST_MENU_SET_REWARD, QUEST_RECRUITLOCALARTISTS
	goto Quest_Recruitlocalartists_ProgressReward_Script_4


Quest_Recruitlocalartists_StartQuest_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_SABRINA
	compare VAR_SALESFORCETOWER_PRODUCTION_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	goto_if_ne Quest_Recruitlocalartists_StartQuest_Dialogue_2
Quest_Recruitlocalartists_StartQuest_Dialogue_1:
	applymovement 3, Common_Movement_FaceUp
	waitmovement 3
	callnative DrawMugshot
	msgbox gText_Recruitlocalartists_TheseMurals
	callnative ClearMugshot
	closemessage
	faceplayer
	callnative DrawMugshot
	msgbox gText_Recruitlocalartists_TheLocalsLove
	callnative ClearMugshot
	closemessage
	applymovement 3, Quest_Recruitlocalartists_LeaveMission_Movement
	startquest QUEST_RECRUITLOCALARTISTS
	fadescreen FADE_TO_BLACK
	removeobject 3
	delay 30
	fadescreen FADE_FROM_BLACK
	release
	end

Quest_Recruitlocalartists_StartQuest_Dialogue_2:
	faceplayer
	callnative DrawMugshot
	msgbox gText_Recruitlocalartists_HelloPlayer
	closemessage
	callnative ClearMugshot
	goto Quest_Recruitlocalartists_StartQuest_Dialogue_1


Quest_Recruitlocalartists_First_Dialogue::
	addvar VAR_QUEST_RECRUITLOLCAARTISTS, 1
	msgbox gText_Recruitlocalartists_TheMurals, MSGBOX_NPC
	end


Quest_Recruitlocalartists_Second_Dialogue::
	addvar VAR_QUEST_RECRUITLOLCAARTISTS, 1
	lock
	faceplayer
	clearflag FLAG_TEMP_1
	addobject 4
	setobjectxy 4, 36, 2
	applymovement 4, Quest_Recruitlocalartists_RunPastScreen_Movement
	msgbox gText_Recruitlocalartists_ISawOne
	closemessage
	waitmovement 4
	fadescreen FADE_TO_BLACK
	delay 60
	call Quest_Recruitlocalartists_SetSmearglePosition_Script
	fadescreen FADE_FROM_BLACK
	release
	end


Quest_Recruitlocalartists_CoreEncounter_Script::
	lock
	call Common_EventScript_SaveGame
	faceplayer
	call Quest_Recruitlocalartists_SetSmeargle_Script
	playmoncry SPECIES_SMEARGLE, CRY_MODE_ENCOUNTER
	msgbox gText_Recruitlocalartists_Smear
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	closemessage
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Quest_Recruitlocalartists_CoreEncounter_Script_2
	case B_OUTCOME_WON, Quest_Recruitlocalartists_CoreEncounter_Script_3
	return

Quest_Recruitlocalartists_CoreEncounter_Script_2:
	call Quest_Recruitlocalartists_ClearSmeargleSub_Script
	return

Quest_Recruitlocalartists_CoreEncounter_Script_3:
	call Quest_Recruitlocalartists_SmeargleRunAway_Script
	return


Quest_Recruitlocalartists_SetSmeargle_Script::
	call Quest_Recruitlocalartists_CountSubquest_Script
	switch VAR_TEMP_0
	case 0, Quest_Recruitlocalartists_SetSmeargle_Script_3
	case 1, Quest_Recruitlocalartists_SetSmeargle_Script_4
	case 2, Quest_Recruitlocalartists_SetSmeargle_Script_5
Quest_Recruitlocalartists_SetSmeargle_Script_1:
	return

Quest_Recruitlocalartists_SetSmeargle_Script_3:
	setwildbattle SPECIES_SMEARGLE, 25, ITEM_NONE
	goto Quest_Recruitlocalartists_SetSmeargle_Script_1

Quest_Recruitlocalartists_SetSmeargle_Script_4:
	setwildbattle SPECIES_SMEARGLE, 30, ITEM_NONE
	goto Quest_Recruitlocalartists_SetSmeargle_Script_1

Quest_Recruitlocalartists_SetSmeargle_Script_5:
	setwildbattle SPECIES_SMEARGLE, 50, ITEM_NONE
	goto Quest_Recruitlocalartists_SetSmeargle_Script_1


Quest_Recruitlocalartists_RemoveSmeargle_Script::
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	return


Quest_Recruitlocalartists_SmeargleRunAway_Script::
	lock
	call Quest_Recruitlocalartists_RemoveSmeargle_Script
	msgbox gText_Recruitlocalartists_TheSmeargleRan, MSGBOX_AUTOCLOSE
	release
	end


Quest_Recruitlocalartists_ClearSmeargleSub_Script::
	call Quest_Recruitlocalartists_RemoveSmeargle_Script
	call Quest_Recruitlocalartists_CountSubquest_Script
	switch VAR_TEMP_0
	case 0, Quest_Recruitlocalartists_ClearSmeargleSub_Script_3
	case 1, Quest_Recruitlocalartists_ClearSmeargleSub_Script_4
	case 2, Quest_Recruitlocalartists_ClearSmeargleSub_Script_5
Quest_Recruitlocalartists_ClearSmeargleSub_Script_1:
	call Quest_Recruitlocalartists_ProgressReward_Script
	return

Quest_Recruitlocalartists_ClearSmeargleSub_Script_3:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RECRUITLOCALARTISTS, SUB_QUEST_1
	goto Quest_Recruitlocalartists_ClearSmeargleSub_Script_1

Quest_Recruitlocalartists_ClearSmeargleSub_Script_4:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RECRUITLOCALARTISTS, SUB_QUEST_2
	goto Quest_Recruitlocalartists_ClearSmeargleSub_Script_1

Quest_Recruitlocalartists_ClearSmeargleSub_Script_5:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RECRUITLOCALARTISTS, SUB_QUEST_3
	goto Quest_Recruitlocalartists_ClearSmeargleSub_Script_1


Quest_Recruitlocalartists_Active_Dialogue::
	msgbox gText_Recruitlocalartists_YouStillHavent, MSGBOX_NPC
	end


Quest_Recruitlocalartists_CompleteQuest_Dialogue::
	lock
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 2
	waitse
	msgbox gText_Recruitlocalartists_TheyWerePokemon
	msgbox gText_Recruitlocalartists_WellThenIDont
	completequest QUEST_RECRUITLOCALARTISTS
	release
	end


Quest_Recruitlocalartists_RunPastScreen_Movement:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

Quest_Recruitlocalartists_LeaveMission_Movement:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_Recruitlocalartists_Smear::
	.string "Smear!$"

gText_Recruitlocalartists_TheSmeargleRan::
	.string "The Smeargle ran away!$"

gText_Recruitlocalartists_TheMurals::
	.string "The murals are painted by this rag tag\n"
	.string "group! They come in, paint real fast\l"
	.string "and then proof, they're gone!$"

gText_Recruitlocalartists_ISawOne::
	.string "I saw one of those mural painters once.\n"
	.string "I'll tell you a secret... they're\l"
	.string "Pokémon!$"

gText_Recruitlocalartists_YouStillHavent::
	.string "You still haven't found those mural\n"
	.string "artists?$"

gText_Recruitlocalartists_TheyWerePokemon::
	.string "They were Pokémon?! Fascinating. Those\n"
	.string "murals were incredibly complex and\l"
	.string "yet... hmm.$"

gText_Recruitlocalartists_WellThenIDont::
	.string "Well then I don't want to hire them,\n"
	.string "obviously. They're better off with a\l"
	.string "Trainer. A shame they won't be painting\l"
	.string "in Mission anymore, but I'll just have\l"
	.string "to find somebody else. Thanks for your\l"
	.string "help.$"

gText_Recruitlocalartists_TheseMurals::
	.string "These murals... they're a cornerstone of\n"
	.string "the culture of this city. They depict\l"
	.string "the growth and struggles of not only\l"
	.string "this community, but the region as a\l"
	.string "whole.$"

gText_Recruitlocalartists_TheLocalsLove::
	.string "The locals love them too. I want to\n"
	.string "figure out how Ycombinator can work\l"
	.string "with these artists to create a\l"
	.string "marketing campaign that really\l"
	.string "resonates with the people. Can you\l"
	.string "help me track down the artists? Come\l"
	.string "to the Production Studio in the\l"
	.string "Salesforcetower once you've found\l"
	.string "them.$"

gText_Recruitlocalartists_HelloPlayer::
	.string "Hello {PLAYER}. We haven't formerly\n"
	.string "met yet, but I'm Sabrina, VP of\l"
	.string "Marketing for Ycombinator. We've\l"
	.string "always been very impressed with your\l"
	.string "work.$"
