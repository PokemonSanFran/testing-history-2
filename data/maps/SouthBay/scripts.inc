SouthBay_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SouthBay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SouthBay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, ImProbablyBetterThanYou_Intro
	.2byte 0


ImProbablyBetterThanYou_Intro::
	lockall
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_ZoeyText1
	callnative ClearMugshot
	closemessage
	goto ImProbablyBetterThanYou_WalkInside
	return


ImProbablyBetterThanYou_WalkInside::
	warpdoor MAP_SOUTH_BAY_YCCOMPOUND_1F, 255, 5, 9
	waitstate
	end


gText_ImProbablyBetterThanYou_ZoeyText1::
	.string "{COLOR 09}<deep breath>\n"
	.string "{COLOR DARK_GRAY}Let's do this.$"
