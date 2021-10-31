SouthBay_YCCompound_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SouthBay_YCCompound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SouthBay_YCCompound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, Swagbag_IncrementIntroState_Script
	.2byte 0


Swagbag_IncrementIntroState_Script::
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	return

