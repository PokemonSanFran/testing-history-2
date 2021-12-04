Psfcity12_MapScripts::
	.byte 0


CheckMegaScript::
	givecustommon SPECIES_BLASTOISE, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_LARVITAR, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_CHARMELEON, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	special GetMegaEvolutionPartyMember
	switch VAR_TEMP_0
	case 0, CheckMegaScript_3
	case 1, CheckMegaScript_4
	case 2, CheckMegaScript_5
	case 3, CheckMegaScript_6
	case 4, CheckMegaScript_7
	case 5, CheckMegaScript_8
	case 6, CheckMegaScript_9
CheckMegaScript_1:
	goto_if_set FLAG_SYS_NATIONAL_DEX, CheckMegaScript_11
CheckMegaScript_10:
	closemessage
	return

CheckMegaScript_3:
	msgbox CheckMegaScript_Text_0
	goto CheckMegaScript_1

CheckMegaScript_4:
	msgbox CheckMegaScript_Text_1
	goto CheckMegaScript_1

CheckMegaScript_5:
	msgbox CheckMegaScript_Text_2
	goto CheckMegaScript_1

CheckMegaScript_6:
	msgbox CheckMegaScript_Text_3
	goto CheckMegaScript_1

CheckMegaScript_7:
	msgbox CheckMegaScript_Text_4
	goto CheckMegaScript_1

CheckMegaScript_8:
	msgbox CheckMegaScript_Text_5
	goto CheckMegaScript_1

CheckMegaScript_9:
	msgbox CheckMegaScript_Text_6
	goto CheckMegaScript_1

CheckMegaScript_11:
	msgbox CheckMegaScript_Text_7
	goto CheckMegaScript_10


CheckMegaScript_Text_0:
	.string "case is 0$"

CheckMegaScript_Text_1:
	.string "case is 1$"

CheckMegaScript_Text_2:
	.string "case is 2$"

CheckMegaScript_Text_3:
	.string "case is 3$"

CheckMegaScript_Text_4:
	.string "case is 4$"

CheckMegaScript_Text_5:
	.string "case is 5$"

CheckMegaScript_Text_6:
	.string "case is 6$"

CheckMegaScript_Text_7:
	.string "Your {STR_VAR_1} is capable of Mega\n"
	.string "Evolution, if memory serves me right.$"
