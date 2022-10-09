Quest_VSDeoxys_HideObject_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_VSDEOXYS
	compare VAR_RESULT, 0
	goto_if_eq Quest_VSDeoxys_HideObject_Script_2
Quest_VSDeoxys_HideObject_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_VSDEOXYS
	compare VAR_RESULT, 0
	goto_if_ne Quest_VSDeoxys_HideObject_Script_4
	return

Quest_VSDeoxys_HideObject_Script_2:
	setflag FLAG_TEMP_1
	goto Quest_VSDeoxys_HideObject_Script_1

Quest_VSDeoxys_HideObject_Script_4:
	setflag FLAG_TEMP_1
	return


Quest_VSDeoxys_CoreEnounter_Script::
	setwildbattle SPECIES_MINIOR_CORE_ORANGE, 30, ITEM_NONE
	msgbox gText_Quest_VSDeoxys_Cry
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	closemessage
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Quest_VSDeoxys_CoreEnounter_Script_2
	case B_OUTCOME_WON, Quest_VSDeoxys_CoreEnounter_Script_2
	return

Quest_VSDeoxys_CoreEnounter_Script_2:
	goto Quest_VSDeoxys_Victory_Script
	return


Quest_VSDeoxys_Victory_Script::
	removeobject 1
	completequest QUEST_VSDEOXYS
	return


gText_Quest_VSDeoxys_Cry::
	.string "Miiiiii!$"
