Southbay_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Southbay_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Southbay_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Southbay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Southbay_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SOUTHBAY
	call Quest_AngelDelivery_Hide_BikerB_Script
	return

Southbay_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto_if_set FLAG_SYS_GAME_CLEAR, Southbay_MapScripts_MAP_SCRIPT_ON_LOAD_1
	return

Southbay_MapScripts_MAP_SCRIPT_ON_LOAD_1:
	setmetatile 3, 9, 0x239, TRUE
	setmetatile 3, 8, 0x239, TRUE
	return

Southbay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PLAYER_HOME_STATE, 0, ImProbablyBetterThanYou_StandingOutside_Dialogue
	.2byte 0


Champion_TurnPlayerAwayHome_Script::
	goto_if_set FLAG_SYS_GAME_CLEAR, Champion_TurnPlayerAwayHome_Script_1
	return

Champion_TurnPlayerAwayHome_Script_1:
	lockall
	msgbox gText_RemindPlayerNewHome
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, swagbag_WalkBackwards
	waitmovement 0
	releaseall
	end


gText_RemindPlayerNewHome::
	.string "You don't live here anymore!$"
