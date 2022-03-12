Psfcity8_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Psfcity8_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity8_MapScripts_MAP_SCRIPT_ON_LOAD:
	compare FLAG_SYS_GAME_CLEAR, 0
	goto_if_ne Psfcity8_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Psfcity8_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 3, 8, 0x239, TRUE
	setmetatile 3, 9, 0x241, TRUE
	return

Psfcity8_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, NewGameSetUp
	.2byte 0


Champion_TurnPlayerAwayHome::
	lockall
	msgbox Champion_TurnPlayerAwayHome_Text_0
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end


NewGameSetUp::
	setflag FLAG_HIDE_PSFCITY7_PSFGOODADMIN
	goto ImProbablyBetterThanYou_Intro
	return


ImProbablyBetterThanYou_Intro::
	lockall
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara1Text1
	callnative ClearMugshot
	closemessage
	goto ImProbablyBetterThanYou_WalkInside_Movement
	return


DontLeavePsfcity8_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_DontLeavePsfcity8_Text1
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, DontLeavePsfcity_Movement
	return


ImProbablyBetterThanYou_WalkInside_Movement::
	warpdoor MAP_PSFCITY8_COMPOUND_1F, 255, 5, 9
	waitstate
	end


DontLeavePsfcity_Movement:
	walk_down
	step_end

Champion_TurnPlayerAwayHome_Text_0:
	.string "You don't live here anymore!$"

gText_ImProbablyBetterThanYou_Psfchara1Text1::
	.string "{COLOR 09}<deep breath>\n"
	.string "{COLOR DARK_GRAY}Let's do this.$"

gText_DontLeavePsfcity8_Text1::
	.string "I don't think I should leave Psfcity8\n"
	.string "yet...$"
