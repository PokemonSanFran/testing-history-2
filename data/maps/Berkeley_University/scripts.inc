Berkeley_University_MapScripts::
	.byte 0


Berkeley_University_DisplayCase_Script::
	lock
	bufferitemname STR_VAR_3, ITEM_COIN_CASE
	msgbox gText_Berkeley_University_DisplayCase, MSGBOX_SIGN
	switch VAR_BERKELEY_AXE_STATE
	case AXE_UNTOUCHED, Berkeley_University_DisplayCase_Script_2
	case AXE_STOLEN, Berkeley_University_DisplayCase_Script_3
	case AXE_THROWN_AWAY, Berkeley_University_DisplayCase_Script_3
	case AXE_TURNED_OVER, Berkeley_University_DisplayCase_Script_4
	return

Berkeley_University_DisplayCase_Script_2:
	goto Quest_StealTheAxe_AxeUntouched_Script
	return

Berkeley_University_DisplayCase_Script_3:
	goto Quest_StealTheAxe_AxeStolen_Dialogue
	return

Berkeley_University_DisplayCase_Script_4:
	goto Quest_StealTheAxe_TurnedOverAxe_Dialogue
	return


gText_Berkeley_University_DisplayCase::
	.string "The display case has a collection of\n"
	.string "medals, trophies, and photos.$"
