Psfcity12_MapScripts::
	.byte 0


CheckMegaScript::
	givecustommon SPECIES_BLASTOISE, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	givecustommon SPECIES_LARVITAR, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	special GetMegaEvolutionPartyMember
	switch VAR_TEMP_0
	case 0, CheckMegaScript_3
	case 1, CheckMegaScript_4
	bufferitemname 0, ITEM_POTION
CheckMegaScript_1:
	goto_if_set FLAG_SYS_NATIONAL_DEX, CheckMegaScript_7
	msgbox CheckMegaScript_Text_1
CheckMegaScript_6:
	closemessage
	return

CheckMegaScript_3:
	bufferpartymonnick 0, VAR_RESULT
	goto CheckMegaScript_1

CheckMegaScript_4:
	bufferpartymonnick 1, VAR_RESULT
	goto CheckMegaScript_1

CheckMegaScript_7:
	msgbox CheckMegaScript_Text_0
	goto CheckMegaScript_6


CheckMegaScript_Text_0:
	.string "Your {STR_VAR_1} is capable of Mega\n"
	.string "Evolution, if memory serves me right.$"

CheckMegaScript_Text_1:
	.string "flag false$"
