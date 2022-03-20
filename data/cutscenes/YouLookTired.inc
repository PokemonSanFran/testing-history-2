YouLookTired_BlockMansionAccess_Script::
	compare VAR_PSFPLACE9_STATE, 2
	goto_if_lt YouLookTired_BlockMansionAccess_Script_1
	return

YouLookTired_BlockMansionAccess_Script_1:
	setobjectxy 2, 14, 11
	setobjectxyperm 2, 14, 11
	return


YouLookTired_HideObjects_Script::
	setflag FLAG_TEMP_1
	return

