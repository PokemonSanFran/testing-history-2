Quest_CulturalPurity_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_BUGSY_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_CulturalPurity_HideLeader_Script_1
	compare VAR_RESULT, 2
	goto_if_lt Quest_CulturalPurity_HideLeader_Script_1
	return

Quest_CulturalPurity_HideLeader_Script_1:
	setflag FLAG_TEMP_1
	return

