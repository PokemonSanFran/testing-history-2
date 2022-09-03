Quest_CulturalPurity_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_BUGSY_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_CulturalPurity_HideLeader_Script_2
	compare VAR_RESULT, 2
	goto_if_lt Quest_CulturalPurity_HideLeader_Script_2
Quest_CulturalPurity_HideLeader_Script_1:
	compare VAR_HOW_DISAPPOINTING_STATE, 0
	goto_if_gt Quest_CulturalPurity_HideLeader_Script_7
	return

Quest_CulturalPurity_HideLeader_Script_2:
	setflag FLAG_TEMP_2
	goto Quest_CulturalPurity_HideLeader_Script_1

Quest_CulturalPurity_HideLeader_Script_6:
	setflag FLAG_TEMP_2
	return

Quest_CulturalPurity_HideLeader_Script_7:
	compare VAR_HOW_DISAPPOINTING_STATE, HOW_DISAPPOINTING_COMPLETE
	goto_if_ne Quest_CulturalPurity_HideLeader_Script_6
	return


Quest_CulturalPurity_Interact_Event_Script::
	returnqueststate QUEST_CULTURALPURITY
	switch VAR_RESULT
	return

	end


Quest_CulturalPurity_QuestStart_Dialogue::
	return


Quest_CulturalPurity_QuestActive_Dialogue::
	return


Quest_CulturalPurity_QuestReward_Dialogue::
	return

