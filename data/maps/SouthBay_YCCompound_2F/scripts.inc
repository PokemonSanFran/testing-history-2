SouthBay_YCCompound_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SouthBay_YCCompound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SouthBay_YCCompound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, Swagbag_IncrementIntroState_Script
	.2byte 0


Swagbag_IncrementIntroState_Script::
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	end


RestInBed_Script::
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq RestInBed_Script_2
RestInBed_Script_1:
	lockall
	msgbox gText_RestInBed_Text1
	closemessage
	call PlayersHouse_2F_EventScript_SetWallClock
	call Common_EventScript_OutOfCenterPartyHeal
	checkitem ITEM_FASHION_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq RestInBed_Script_5
RestInBed_Script_4:
	releaseall
	end

RestInBed_Script_2:
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	goto RestInBed_Script_1

RestInBed_Script_5:
	giveitem ITEM_FASHION_CASE
	goto RestInBed_Script_4


gText_RestInBed_Text1::
	.string "Let's get some rest...when should we\n"
	.string "wake up?$"
