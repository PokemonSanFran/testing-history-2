Act1_1_Check_Script::
	compare VAR_STORYLINE_STATE, 9
	goto_if_eq Act1_1_Check_Script_1
	return

Act1_1_Check_Script_1:
	call Act1_1_Complete_Monologue
	return


Act1_1_Complete_Monologue::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_GotAllThree
	callnative ClearMugshot
	closemessage
	call Act1_1_Complete_WarpToCompound_Script
	release
	end


Act1_1_Complete_WarpToCompound_Script::
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	msgbox gText_Act1_1_Complete_Question, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq Act1_1_Complete_WarpToCompound_Script_1
	return

Act1_1_Complete_WarpToCompound_Script_1:
	warpsilent MAP_PSFCITY8, 255, 3, 10
	return


gText_Act1_1_Complete_GotAllThree::
	.string "I've got all three Badges from this side\n"
	.string "of the mainland. The ferry to Psfcity9\l"
	.string "looks like it's going to be broken utnil\l"
	.string "at least tomorrow, and I can't head\l"
	.string "west without Go-Goggles. It's been a\l"
	.string "long day... I think I should head back\l"
	.string "to Psfcity8 and call it a night.$"

gText_Act1_1_Complete_Question::
	.string "Do you want to go back to Psfcity8?$"
