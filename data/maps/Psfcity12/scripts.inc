Psfcity12_MapScripts::
	.byte 0


CheckMegaScript::
	givecustommon SPECIES_BLASTOISE, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_LARVITAR, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_CHARMELEON, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	special CheckMegaEvolutionPartyMember
	compare VAR_TEMP_1, 6
	goto_if_lt CheckMegaScript_2
CheckMegaScript_1:
	msgbox CheckMegaScript_Text_7
	closemessage
	return

CheckMegaScript_2:
	switch VAR_TEMP_1
	case 0, CheckMegaScript_5
	case 1, CheckMegaScript_6
	case 2, CheckMegaScript_7
	case 3, CheckMegaScript_8
	case 4, CheckMegaScript_9
	case 5, CheckMegaScript_10
	msgbox CheckMegaScript_Text_6
	goto CheckMegaScript_1

CheckMegaScript_5:
	msgbox CheckMegaScript_Text_0
	goto CheckMegaScript_1

CheckMegaScript_6:
	msgbox CheckMegaScript_Text_1
	goto CheckMegaScript_1

CheckMegaScript_7:
	msgbox CheckMegaScript_Text_2
	goto CheckMegaScript_1

CheckMegaScript_8:
	msgbox CheckMegaScript_Text_3
	goto CheckMegaScript_1

CheckMegaScript_9:
	msgbox CheckMegaScript_Text_4
	goto CheckMegaScript_1

CheckMegaScript_10:
	msgbox CheckMegaScript_Text_5
	goto CheckMegaScript_1


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
	.string "its working i swear$"

CheckMegaScript_Text_7:
	.string "enjoy the ring.$"

gTextCanMegaEvolve::
	.string "Your {STR_VAR_1} is capable of Mega\n"
	.string "Evolution, if memory serves me right.$"
