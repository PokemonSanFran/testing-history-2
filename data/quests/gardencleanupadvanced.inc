Quest_GardenCleanUpAdvanced_HideObjects_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GARDENCLEANUP
	compare VAR_RESULT, 0
	goto_if_eq Quest_GardenCleanUpAdvanced_HideObjects_Script_2
Quest_GardenCleanUpAdvanced_HideObjects_Script_1:
	return

Quest_GardenCleanUpAdvanced_HideObjects_Script_2:
	setflag FLAG_TEMP_2
	goto Quest_GardenCleanUpAdvanced_HideObjects_Script_1


Quest_GardenCleanUpAdvanced_Event_Script::
	lock
	faceplayer
	returnqueststate QUEST_GARDENCLEANUPADVANCED
	switch VAR_RESULT
	case QUEST_MENU_COMPLETE_QUEST, Quest_GardenCleanUpAdvanced_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_GardenCleanUpAdvanced_Event_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_GardenCleanUpAdvanced_Event_Script_4
	goto Quest_GardenCleanUpAdvanced_Start_Dialogue
	return

Quest_GardenCleanUpAdvanced_Event_Script_2:
	goto Quest_GardenCleanUpAdvanced_Complete_Dialogue
	return

Quest_GardenCleanUpAdvanced_Event_Script_3:
	goto Quest_GardenCleanUpAdvanced_Reward_Dialogue
	return

Quest_GardenCleanUpAdvanced_Event_Script_4:
	goto Quest_GardenCleanUpAdvanced_Active_Dialogue
	return


Quest_GardenCleanUpAdvanced_Start_Dialogue::
	msgbox gText_GardenCleanUpAdvanced_WeStartedThisCommunityGarden
	giveitem ITEM_WAILMER_PAIL, 1
	compare VAR_QUEST_GARDENCLEANUPADVANCED, SAVED_BEFORE_BATTLE
	goto_if_gt Quest_GardenCleanUpAdvanced_Start_Dialogue_2
Quest_GardenCleanUpAdvanced_Start_Dialogue_1:
	msgbox gText_GardenCleanUpAdvanced_WildPokemonWereEatingItSo
	msgbox gText_GardenCleanUpAdvanced_ButOneKeptComing
	startquest QUEST_GARDENCLEANUPADVANCED
	release
	end

Quest_GardenCleanUpAdvanced_Start_Dialogue_2:
	goto Quest_GardenCleanUpAdvanced_Secret_Dialogue
	goto Quest_GardenCleanUpAdvanced_Start_Dialogue_1


Quest_GardenCleanUpAdvanced_Active_Dialogue::
	msgbox gText_GardenCleanUpAdvanced_ItDidntShowUpUntil
	release
	end


Quest_GardenCleanUpAdvanced_Reward_Dialogue::
	msgbox gText_GardenCleanUpAdvanced_AStrongGreedent
	giveitem ITEM_ORAN_BERRY, 1
	completequest QUEST_GARDENCLEANUPADVANCED
	release
	end


Quest_GardenCleanUpAdvanced_Complete_Dialogue::
	msgbox gText_GardenCleanUpAdvanced_ImSoProudOfMyGarden
	release
	end


Quest_GardenCleanUpAdvanced_InteractTree_Script::
	lock
	switch VAR_QUEST_GARDENCLEANUPADVANCED
	case HAS_NOT_INTERACTED, Quest_GardenCleanUpAdvanced_InteractTree_Script_2
	case SAVED_BEFORE_BATTLE, Quest_GardenCleanUpAdvanced_InteractTree_Script_3
	case INCOMPLETE_GARDEN_QUEST, Quest_GardenCleanUpAdvanced_InteractTree_Script_4
	case DEFEATED_GARDEN_BOSS, Quest_GardenCleanUpAdvanced_InteractTree_Script_4
	return

Quest_GardenCleanUpAdvanced_InteractTree_Script_2:
	goto Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene
	return

Quest_GardenCleanUpAdvanced_InteractTree_Script_3:
	goto Quest_GardenCleanUpAdvanced_Battle_Script
	return

Quest_GardenCleanUpAdvanced_InteractTree_Script_4:
	goto Quest_GardenCleanUpAdvanced_Tree_Dialogue
	return


Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene::
	setvar VAR_TEMP_0, 0
	msgbox gText_GardenCleanUpAdvanced_WhatAHugeTree
	msgbox gText_GardenCleanUpAdvanced_ShouldYouGiveItAShake, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_2
Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_5:
	call Quest_GardenCleanUpAdvanced_ShakeScreen_Script
	compare VAR_TEMP_0, 5
	goto_if_eq Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_8
	msgbox gText_GardenCleanUpAdvanced_TheHugeTreeDoesntMove, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_10
	goto Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_5

Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_2:
	release
	end

Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_4:
	goto Quest_GardenCleanUpAdvanced_FinalShake_Cutscene
	return

Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_8:
	goto Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_4

Quest_GardenCleanUpAdvanced_ShakeTree_Cutscene_10:
	setvar VAR_TEMP_0, 0
	release
	end


Quest_GardenCleanUpAdvanced_ShakeScreen_Script::
	addvar VAR_TEMP_0, 1
	delay 16
	setvar VAR_0x8004, 0
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 3
	setvar VAR_0x8007, 1
	special ShakeCamera
	waitstate
	delay 10
	return


Quest_GardenCleanUpAdvanced_FinalShake_Cutscene::
	msgbox gText_GardenCleanUpAdvanced_DidSomethingMove, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Quest_GardenCleanUpAdvanced_FinalShake_Cutscene_2
	call Quest_GardenCleanUpAdvanced_ShakeScreen_Script
	playmoncry SPECIES_GREEDENT, CRY_MODE_ENCOUNTER
	waitmoncry
	msgbox gText_GardenCleanUpAdvanced_SomethingSwoopedDown
	closemessage
	setvar VAR_QUEST_GARDENCLEANUPADVANCED, SAVED_BEFORE_BATTLE
	call Common_EventScript_SaveGame
	goto Quest_GardenCleanUpAdvanced_Battle_Script
	return

Quest_GardenCleanUpAdvanced_FinalShake_Cutscene_2:
	setvar VAR_TEMP_0, 0
	release
	end


Quest_GardenCleanUpAdvanced_Battle_Script::
	setwildbattle SPECIES_GREEDENT, 60, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Quest_GardenCleanUpAdvanced_Battle_Script_3
	case B_OUTCOME_WON, Quest_GardenCleanUpAdvanced_Battle_Script_3
Quest_GardenCleanUpAdvanced_Battle_Script_1:
	release
	end

Quest_GardenCleanUpAdvanced_Battle_Script_3:
	goto Quest_GardenCleanUpAdvanced_PostBattle_Cutscene
	goto Quest_GardenCleanUpAdvanced_Battle_Script_1


Quest_GardenCleanUpAdvanced_AddItems_Script::
	additem ITEM_ORAN_BERRY, 30
	additem ITEM_SITRUS_BERRY, 10
	additem ITEM_LANSAT_BERRY, 1
	additem ITEM_TAMATO_BERRY, 20
	additem ITEM_HONDEW_BERRY, 15
	additem ITEM_CHOPLE_BERRY, 5
	additem ITEM_STARF_BERRY, 1
	return


Quest_GardenCleanUpAdvanced_PostBattle_Cutscene::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_GARDENCLEANUPADVANCED
	compare VAR_RESULT, 0
	goto_if_ne Quest_GardenCleanUpAdvanced_PostBattle_Cutscene_2
Quest_GardenCleanUpAdvanced_PostBattle_Cutscene_1:
	setvar VAR_QUEST_GARDENCLEANUPADVANCED, DEFEATED_GARDEN_BOSS
	call Quest_GardenCleanUpAdvanced_AddItems_Script
	msgbox gText_GardenCleanUpAdvanced_TheAftershocks
	playfanfare MUS_OBTAIN_BERRY
	waitmessage
	waitfanfare
	msgbox gText_GardenCleanUpAdvanced_GotBerries
	release
	end

Quest_GardenCleanUpAdvanced_PostBattle_Cutscene_2:
	questmenu QUEST_MENU_SET_REWARD, QUEST_GARDENCLEANUPADVANCED
	goto Quest_GardenCleanUpAdvanced_PostBattle_Cutscene_1


Quest_GardenCleanUpAdvanced_Tree_Dialogue::
	msgbox gText_GardenCleanUpAdvanced_WhatAHugeTree
	compare VAR_QUEST_GARDENCLEANUPADVANCED, DEFEATED_GARDEN_BOSS
	goto_if_eq Quest_GardenCleanUpAdvanced_Tree_Dialogue_2
Quest_GardenCleanUpAdvanced_Tree_Dialogue_1:
	release
	end

Quest_GardenCleanUpAdvanced_Tree_Dialogue_2:
	msgbox gText_GardenCleanUpAdvanced_TheTreeWhere
	goto Quest_GardenCleanUpAdvanced_Tree_Dialogue_1


Quest_GardenCleanUpAdvanced_Secret_Dialogue::
	msgbox gText_GardenCleanUpAdvanced_ThereWasSomethingInThe
	goto Quest_GardenCleanUpAdvanced_Reward_Dialogue
	return


gText_GardenCleanUpAdvanced_WeStartedThisCommunityGarden::
	.string "We started this community garden\n"
	.string "thanks to you! I forgot to give you\l"
	.string "this, but we got an extra one in case\l"
	.string "you come back.$"

gText_GardenCleanUpAdvanced_WildPokemonWereEatingItSo::
	.string "wild pokemon were eating some fruit so\n"
	.string "we sprayed repelsd..$"

gText_GardenCleanUpAdvanced_ButOneKeptComing::
	.string "but one kept coming back. can you help\n"
	.string "us get rid of it$"

gText_GardenCleanUpAdvanced_ItDidntShowUpUntil::
	.string "it didn't show up until after we started\n"
	.string "spraying the repels...$"

gText_GardenCleanUpAdvanced_AStrongGreedent::
	.string "a strong greedent was hoarding the\n"
	.string "berries? wow! well you can keep them as\l"
	.string "thanks, and take this too!$"

gText_GardenCleanUpAdvanced_ImSoProudOfMyGarden::
	.string "i'm so proud of my garden!$"

gText_GardenCleanUpAdvanced_WhatAHugeTree::
	.string "What a huge tree...$"

gText_GardenCleanUpAdvanced_ShouldYouGiveItAShake::
	.string "Should you give it a shake?$"

gText_GardenCleanUpAdvanced_TheHugeTreeDoesntMove::
	.string "... ... ...\p"
	.string "The huge tree doesn't move an inch.$"

gText_GardenCleanUpAdvanced_DidSomethingMove::
	.string "Did something move in the upper branch?$"

gText_GardenCleanUpAdvanced_SomethingSwoopedDown::
	.string "Something swooped down from the tree\n"
	.string "and attacked!$"

gText_GardenCleanUpAdvanced_TheAftershocks::
	.string "The aftershocks of the battle caused a\n"
	.string "lot of berries to fall from the tree!$"

gText_GardenCleanUpAdvanced_GotBerries::
	.string "{PLAYER} got a bunch of berries.$"

gText_GardenCleanUpAdvanced_TheTreeWhere::
	.string "The used to be a Greedent that was\n"
	.string "hoarding the berries from Maria's\l"
	.string "community garden.$"

gText_GardenCleanUpAdvanced_ATreeMakingWeirdSounds::
	.string "What a huge tree...$"

gText_GardenCleanUpAdvanced_ThereWasSomethingInThe::
	.string "There was something in that tree? Yeah,\n"
	.string "we had a berry problem, how did you\l"
	.string "know?$"
