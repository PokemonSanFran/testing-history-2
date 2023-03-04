Quest_StealTheAxe_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_CHUCK_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_StealTheAxe_HideLeader_Script_2
Quest_StealTheAxe_HideLeader_Script_1:
	compare VAR_RESULT, 6
	goto_if_lt Quest_StealTheAxe_HideLeader_Script_5
Quest_StealTheAxe_HideLeader_Script_4:
	switch VAR_ALAMEDA_STATE
	case START_SURVIVAL_CHANCE, Quest_StealTheAxe_HideLeader_Script_8
	case POST_SURVIVAL_CHANCE, Quest_StealTheAxe_HideLeader_Script_8
	case WHY_ARE_YOU_HELPING_THEM, Quest_StealTheAxe_HideLeader_Script_8
	case POST_EARTHQUAKE, Quest_StealTheAxe_HideLeader_Script_8
	case START_EARTHQUAKE_RESCUE, Quest_StealTheAxe_HideLeader_Script_8
	case POST_EARTHQUAKE_RESCUE, Quest_StealTheAxe_HideLeader_Script_8
	case MEET_AT_PSFROUTE8, Quest_StealTheAxe_HideLeader_Script_8
	return

Quest_StealTheAxe_HideLeader_Script_2:
	setflag FLAG_TEMP_5
	goto Quest_StealTheAxe_HideLeader_Script_1

Quest_StealTheAxe_HideLeader_Script_5:
	setflag FLAG_TEMP_5
	goto Quest_StealTheAxe_HideLeader_Script_4

Quest_StealTheAxe_HideLeader_Script_8:
	setflag FLAG_TEMP_5
	return


Quest_StealTheAxe_Event_Script::
	return


Quest_StealTheAxe_CheckTime_Script::
	gettime
	compare VAR_0x8000, 21
	goto_if_lt Quest_StealTheAxe_CheckTime_Script_2
	return

Quest_StealTheAxe_CheckTime_Script_1:
	setflag FLAG_TEMP_3
	release
	end

Quest_StealTheAxe_CheckTime_Script_2:
	compare VAR_0x8000, 5
	goto_if_gt Quest_StealTheAxe_CheckTime_Script_1
	return


Quest_StealTheAxe_LockedDoor_Dialogue::
	returnqueststate QUEST_STEALTHEAXE
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_eq Quest_StealTheAxe_LockedDoor_Dialogue_2
Quest_StealTheAxe_LockedDoor_Dialogue_1:
	return

Quest_StealTheAxe_LockedDoor_Dialogue_2:
	msgbox gText_StealTheAxe_IShould, , SPEAKER_ZOEY, TAIL_THOUGHT
	goto Quest_StealTheAxe_LockedDoor_Dialogue_1


gText_StealTheAxe_IShould::
	.string "Hmm... I should come back tonight.$"
