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
	warpdoor MAP_SOUTH_BAY_YCCOMPOUND_1F, 255, 6, 9
	closemessage
	waitstate
	end


Zoey_WalkInside:
	walk_up
	step_end

gText_ImProbablyBetterThanYou_ZoeyText1::
	.string "*deep breath* Let's do this.$"
