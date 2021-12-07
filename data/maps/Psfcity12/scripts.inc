Psfcity12_MapScripts::
	.byte 0


CheckMegaScript::
	givecustommon SPECIES_BLASTOISE, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_LARVITAR, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_CHARMELEON, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	special CheckMegaEvolutionPartyMember
	switch VAR_TEMP_1
	case 0, CheckMegaScript_3
	case 1, CheckMegaScript_4
	case 2, CheckMegaScript_5
	case 3, CheckMegaScript_6
	case 4, CheckMegaScript_7
	case 5, CheckMegaScript_8
	msgbox CheckMegaScript_Text_0
CheckMegaScript_1:
	msgbox gTextCanMegaEvolve
	closemessage
	return

CheckMegaScript_3:
	bufferpartymonnick 0, 0
	goto CheckMegaScript_1

CheckMegaScript_4:
	bufferpartymonnick 0, 1
	goto CheckMegaScript_1

CheckMegaScript_5:
	bufferpartymonnick 0, 2
	goto CheckMegaScript_1

CheckMegaScript_6:
	bufferpartymonnick 0, 3
	goto CheckMegaScript_1

CheckMegaScript_7:
	bufferpartymonnick 0, 4
	goto CheckMegaScript_1

CheckMegaScript_8:
	bufferpartymonnick 0, 5
	goto CheckMegaScript_1


CheckMegaScript_Text_0:
	.string "its working i swear$"

gTextCanMegaEvolve::
	.string "Your {STR_VAR_1} is capable of Mega\n"
	.string "Evolution, if memory serves me right.$"
