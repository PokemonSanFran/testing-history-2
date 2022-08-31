Quest_GardenCleanUp_Debug_Script::
	addvar VAR_TEMP_0, 1
	setvar VAR_DEFEATED_GARDEN_POKEMON, 47
	callnative CountDefeatedGardenMons
	msgbox Quest_GardenCleanUp_Debug_Script_Text_0
	warp MAP_PSFROUTE21, 8, 7
	return


Quest_GardenCleanUp_HideObjects_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GARDENCLEANUP
	compare VAR_RESULT, 0
	goto_if_ne Quest_GardenCleanUp_HideObjects_Script_2
Quest_GardenCleanUp_HideObjects_Script_1:
	return

Quest_GardenCleanUp_HideObjects_Script_2:
	setflag FLAG_TEMP_2
	goto Quest_GardenCleanUp_HideObjects_Script_1


Quest_GardenCleanUpAdvanced_HideObjects_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GARDENCLEANUP
	compare VAR_RESULT, 0
	goto_if_eq Quest_GardenCleanUpAdvanced_HideObjects_Script_2
Quest_GardenCleanUpAdvanced_HideObjects_Script_1:
	return

Quest_GardenCleanUpAdvanced_HideObjects_Script_2:
	setflag FLAG_TEMP_2
	goto Quest_GardenCleanUpAdvanced_HideObjects_Script_1


Quest_GardenCleanUp_ClearGarden_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GARDENCLEANUP
	compare VAR_RESULT, 0
	goto_if_ne Quest_GardenCleanUp_ClearGarden_Script_2
Quest_GardenCleanUp_ClearGarden_Script_1:
	return

Quest_GardenCleanUp_ClearGarden_Script_2:
	setmetatile 4, 4, 0x01C, FALSE
	setmetatile 2, 6, 0x1CE, FALSE
	setmetatile 2, 7, 0x1D6, TRUE
	setmetatile 2, 8, 0x1DE, TRUE
	setmetatile 3, 6, 0x1CF, FALSE
	setmetatile 3, 7, 0x1D7, TRUE
	setmetatile 3, 8, 0x1DF, TRUE
	special DrawWholeMapView
	goto Quest_GardenCleanUp_ClearGarden_Script_1


Quest_GardenCleanUp_CheckCompletion_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GARDENCLEANUP
	compare VAR_RESULT, 0
	goto_if_ne Quest_GardenCleanUp_CheckCompletion_Script_2
Quest_GardenCleanUp_CheckCompletion_Script_1:
	return

Quest_GardenCleanUp_CheckCompletion_Script_2:
	goto Quest_GardenCleanUpAdvanced_Event_Script
	goto Quest_GardenCleanUp_CheckCompletion_Script_1


Quest_GardenCleanUp_Event_Script::
	lock
	call Quest_GardenCleanUp_CheckCompletion_Script
	returnqueststate QUEST_GARDENCLEANUP
	switch VAR_RESULT
	case QUEST_MENU_COMPLETE_QUEST, Quest_GardenCleanUp_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_GardenCleanUp_Event_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_GardenCleanUp_Event_Script_4
	goto Quest_GardenCleanUp_Start_Dialogue
	return

Quest_GardenCleanUp_Event_Script_2:
	goto Quest_GardenCleanUp_Complete_Dialogue
	return

Quest_GardenCleanUp_Event_Script_3:
	goto Quest_GardenCleanUp_Reward_Cutscene
	return

Quest_GardenCleanUp_Event_Script_4:
	goto Quest_GardenCleanUp_Active_Dialogue
	return


Quest_GardenCleanUp_Start_Dialogue::
	lock
	faceplayer
	msgbox gText_GardenCleanUp_ILearned
	msgbox gText_GardenCleanUp_ITriedTo
	msgbox gText_GardenCleanUp_CouldYouHelp
	startquest QUEST_GARDENCLEANUP
	setvar VAR_DEFEATED_GARDEN_POKEMON, 0
	release
	end


Quest_GardenCleanUp_Active_Dialogue::
	compare VAR_DEFEATED_GARDEN_POKEMON, 46
	goto_if_gt Quest_GardenCleanUp_Active_Dialogue_2
	compare VAR_DEFEATED_GARDEN_POKEMON, 40
	goto_if_gt Quest_GardenCleanUp_Active_Dialogue_3
	compare VAR_DEFEATED_GARDEN_POKEMON, 30
	goto_if_gt Quest_GardenCleanUp_Active_Dialogue_4
	compare VAR_DEFEATED_GARDEN_POKEMON, 20
	goto_if_gt Quest_GardenCleanUp_Active_Dialogue_5
	compare VAR_DEFEATED_GARDEN_POKEMON, 10
	goto_if_gt Quest_GardenCleanUp_Active_Dialogue_6
	msgbox gText_GardenCleanUp_ThankYouForYourHelp, MSGBOX_NPC
Quest_GardenCleanUp_Active_Dialogue_1:
	end

Quest_GardenCleanUp_Active_Dialogue_2:
	msgbox gText_GardenCleanUp_SoClose, MSGBOX_NPC
	goto Quest_GardenCleanUp_Active_Dialogue_1

Quest_GardenCleanUp_Active_Dialogue_3:
	msgbox gText_GardenCleanUp_ItsReallyStarting, MSGBOX_NPC
	goto Quest_GardenCleanUp_Active_Dialogue_1

Quest_GardenCleanUp_Active_Dialogue_4:
	msgbox gText_GardenCleanUp_WowYouBeatALot, MSGBOX_NPC
	goto Quest_GardenCleanUp_Active_Dialogue_1

Quest_GardenCleanUp_Active_Dialogue_5:
	msgbox gText_GardenCleanUp_ITriedToGoEarlier, MSGBOX_NPC
	goto Quest_GardenCleanUp_Active_Dialogue_1

Quest_GardenCleanUp_Active_Dialogue_6:
	msgbox gText_GardenCleanUp_DidYouGoOver, MSGBOX_NPC
	goto Quest_GardenCleanUp_Active_Dialogue_1


Quest_GardenCleanUp_Reward_Cutscene::
	faceplayer
	msgbox gText_GardenCleanUp_OhMyGodYoureDone
	applymovement 4, Quest_GardenCleanUp_RunToGarden_Movement
	waitmovement 4
	removeobject 4
	completequest QUEST_GARDENCLEANUP
	release
	end


Quest_GardenCleanUp_Complete_Dialogue::
	msgbox gText_GardenCleanUp_ImSoExcitedToStartPlanting, MSGBOX_NPC
	end


Quest_GardenCleanUpAdvanced_Event_Script::
	returnqueststate QUEST_GARDENCLEANUPADVANCED
	switch VAR_RESULT
	case QUEST_MENU_COMPLETE_QUEST, Quest_GardenCleanUpAdvanced_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_GardenCleanUpAdvanced_Event_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_GardenCleanUpAdvanced_Event_Script_4
	goto Quest_GardenCleanUp_Start_Dialogue
	return

Quest_GardenCleanUpAdvanced_Event_Script_2:
	goto Quest_GardenCleanUp_Complete_Dialogue
	return

Quest_GardenCleanUpAdvanced_Event_Script_3:
	goto Quest_GardenCleanUp_Reward_Cutscene
	return

Quest_GardenCleanUpAdvanced_Event_Script_4:
	goto Quest_GardenCleanUp_Active_Dialogue
	return


Quest_GardenCleanUpAdvanced_Start_Dialogue::
	return


Quest_GardenCleanUpAdvanced_Active_Dialogue::
	return


Quest_GardenCleanUpAdvanced_Reward_Dialogue::
	return


Quest_GardenCleanUpAdvanced_Complete_Dialogue::
	return


Quest_GardenCleanUpAdvanced_InteractTree_Cutscene::
	return


Quest_GardenCleanUp_RunToGarden_Movement:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

Quest_GardenCleanUp_Debug_Script_Text_0:
	.string "if the garden quest is active, go\n"
	.string "defeat one more on Psfroute21$"

gText_GardenCleanUp::
	.string "$"

gText_GardenCleanUp_ILearned::
	.string "$"

gText_GardenCleanUp_ITriedTo::
	.string "$"

gText_GardenCleanUp_CouldYouHelp::
	.string "$"

gText_GardenCleanUp_SoClose::
	.string "$"

gText_GardenCleanUp_ItsReallyStarting::
	.string "$"

gText_GardenCleanUp_WowYouBeatALot::
	.string "$"

gText_GardenCleanUp_ITriedToGoEarlier::
	.string "$"

gText_GardenCleanUp_DidYouGoOver::
	.string "$"

gText_GardenCleanUp_ThankYouForYourHelp::
	.string "$"

gText_GardenCleanUp_OhMyGodYoureDone::
	.string "$"

gText_GardenCleanUp_ImSoExcitedToStartPlanting::
	.string "$"
