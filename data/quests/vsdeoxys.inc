Quest_VSDeoxys_HideObject_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_VSDEOXYS
	compare VAR_RESULT, 0
	goto_if_eq Quest_VSDeoxys_HideObject_Script_1
	return

Quest_VSDeoxys_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return

