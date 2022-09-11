Quest_DexCompletion_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_DEXCOMPLETION
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_DexCompletion_Interact_Script_2
	case QUEST_MENU_SET_REWARD, Quest_DexCompletion_Interact_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_DexCompletion_Interact_Script_4
	goto Quest_DexCompletion_StartQuest_Dialogue
	return

Quest_DexCompletion_Interact_Script_2:
	goto Quest_DexCompletion_Active_Dialogue
	return

Quest_DexCompletion_Interact_Script_3:
	goto Quest_DexCompletion_Reward_Dialogue
	return

Quest_DexCompletion_Interact_Script_4:
	goto Quest_DexCompletion_Completed_Dialogue
	return


Quest_DexCompletion_StartQuest_Dialogue::
	msgbox gText_DexCompletion_WeAreTheResearch
	msgbox gText_DexCompletion_WeNormallyStudy
	msgbox gText_DexCompletion_ButTheLastFewYears
	msgbox gText_DexCompletion_YoureATrainer
	startquest QUEST_DEXCOMPLETION
	call Quest_DexCompletion_MarkQuests_Script
	release
	end


Quest_DexCompletion_Debug_Script::
	addvar VAR_TEMP_0, 1
	setvar VAR_0x8006, 100
	compare VAR_0x8006, 99
	goto_if_gt Quest_DexCompletion_Debug_Script_2
Quest_DexCompletion_Debug_Script_1:
	compare VAR_0x8006, 49
	goto_if_gt Quest_DexCompletion_Debug_Script_5
Quest_DexCompletion_Debug_Script_4:
	return

Quest_DexCompletion_Debug_Script_2:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_DEXCOMPLETION, SUB_QUEST_2
	goto Quest_DexCompletion_Debug_Script_1

Quest_DexCompletion_Debug_Script_5:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_DEXCOMPLETION, SUB_QUEST_1
	goto Quest_DexCompletion_Debug_Script_4


Quest_DexCompletion_MarkQuests_Script::
	callnative ScriptGetPokedexInfo
	compare VAR_0x8006, 99
	goto_if_gt Quest_DexCompletion_MarkQuests_Script_2
Quest_DexCompletion_MarkQuests_Script_1:
	compare VAR_0x8006, 49
	goto_if_gt Quest_DexCompletion_MarkQuests_Script_5
Quest_DexCompletion_MarkQuests_Script_4:
	return

Quest_DexCompletion_MarkQuests_Script_2:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_DEXCOMPLETION, SUB_QUEST_2
	goto Quest_DexCompletion_MarkQuests_Script_1

Quest_DexCompletion_MarkQuests_Script_5:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_DEXCOMPLETION, SUB_QUEST_1
	goto Quest_DexCompletion_MarkQuests_Script_4


Quest_DexCompletion_CheckSubquestProgress_Script::
	setvar VAR_TEMP_1, 0
	checkitem ITEM_OVAL_CHARM, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_DexCompletion_CheckSubquestProgress_Script_2
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_DEXCOMPLETION, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_DexCompletion_CheckSubquestProgress_Script_5
	setvar VAR_TEMP_1, 2
Quest_DexCompletion_CheckSubquestProgress_Script_4:
	return

Quest_DexCompletion_CheckSubquestProgress_Script_2:
	setvar VAR_TEMP_1, 1
	return

Quest_DexCompletion_CheckSubquestProgress_Script_5:
	setvar VAR_TEMP_1, 3
	goto Quest_DexCompletion_CheckSubquestProgress_Script_4


Quest_DexCompletion_Active_Dialogue::
	call Quest_DexCompletion_MarkQuests_Script
	call Quest_DexCompletion_CheckSubquestProgress_Script
	switch VAR_TEMP_1
	case 1, Quest_DexCompletion_Active_Dialogue_2
	case 2, Quest_DexCompletion_Active_Dialogue_3
	case 3, Quest_DexCompletion_Active_Dialogue_4
	return

Quest_DexCompletion_Active_Dialogue_2:
	goto Quest_DexCompletion_Sub100Progress_Dialogue
	return

Quest_DexCompletion_Active_Dialogue_3:
	goto Quest_DexCompletion_Sub50Progress_Dialogue
	return

Quest_DexCompletion_Active_Dialogue_4:
	goto Quest_DexCompletion_FirstReward_Dialogue
	return


Quest_DexCompletion_Sub50Progress_Dialogue::
	msgbox gText_DexCompletion_HowIsYourPokeDex, MSGBOX_NPC
	end


Quest_DexCompletion_FirstReward_Dialogue::
	msgbox gText_DexCompletion_HowIsYourPokeDex
	msgbox gText_DexCompletion_OhWow50
	msgbox gText_DexCompletion_ThankYouSoMuch, MSGBOX_NPC
	giveitem ITEM_OVAL_CHARM, 1
	release
	end


Quest_DexCompletion_MarkReward_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_DEXCOMPLETION, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_DexCompletion_MarkReward_Script_2
Quest_DexCompletion_MarkReward_Script_1:
	return

Quest_DexCompletion_MarkReward_Script_2:
	questmenu QUEST_MENU_SET_REWARD, QUEST_DEXCOMPLETION
	goto Quest_DexCompletion_Reward_Dialogue
	goto Quest_DexCompletion_MarkReward_Script_1


Quest_DexCompletion_Sub100Progress_Dialogue::
	call Quest_DexCompletion_MarkReward_Script
	msgbox gText_DexCompletion_HowIsYourPokeDex100, MSGBOX_NPC
	end


Quest_DexCompletion_Reward_Dialogue::
	msgbox gText_DexCompletion_HowIsYourPokeDex100
	msgbox gText_DexCompletion_OhWow100
	msgbox gText_DexCompletion_ThisIsAmazing
	giveitem ITEM_SHINY_CHARM, 1
	completequest QUEST_DEXCOMPLETION
	release
	end


Quest_DexCompletion_Completed_Dialogue::
	msgbox gText_DexCompletion_HeyPlayer, MSGBOX_NPC
	end


gText_DexCompletion_WeAreTheResearch::
	.string "we are the research people$"

gText_DexCompletion_WeNormallyStudy::
	.string "we normally study pokemon and their\n"
	.string "interactions in the region but$"

gText_DexCompletion_ButTheLastFewYears::
	.string "the last few years havbe been rough.\n"
	.string "the league$"

gText_DexCompletion_YoureATrainer::
	.string "you're a trainer right can you help us?\n"
	.string "come back after you've completed at\l"
	.string "least 50% of the pokedex$"

gText_DexCompletion_HowIsYourPokeDex::
	.string "how is your pokedex coming? 50% isn't\n"
	.string "too much, right$"

gText_DexCompletion_OhWow50::
	.string "oh wow 50% you're awesome$"

gText_DexCompletion_ThankYouSoMuch::
	.string "tysm take this$"

gText_DexCompletion_HowIsYourPokeDex100::
	.string "how is your pokedex coming? are you\n"
	.string "done?$"

gText_DexCompletion_OhWow100::
	.string "oh wow 100% you fuckin did it$"

gText_DexCompletion_ThisIsAmazing::
	.string "this is amazing, here take this$"

gText_DexCompletion_HeyPlayer::
	.string "hey {PLAYER} welcome back$"
