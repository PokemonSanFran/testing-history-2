SouthBay_MapScripts::
	.byte 0


ImProbablyBetterThanYou_Intro::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_ZoeyText1
	callnative ClearMugshot
	goto ImProbablyBetterThanYou_WalkInside
	return


ImProbablyBetterThanYou_WalkInside::
	applymovement 2, Zoey_WalkInside
	waitmovement 0
	release
	return


Zoey_WalkInside:
	walk_up
	step_end

gText_ImProbablyBetterThanYou_ZoeyText1::
	.string "deep breath Let's do this.$"
