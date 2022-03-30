Psfcity8_Compound_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity8_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity8_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, Swagbag_IncrementIntroState_Script
	.2byte 0


Psfcity8_Compound_2F_Bed_Script::
	lock
	compare VAR_PSFCAVE7_STATE, 4
	goto_if_eq Psfcity8_Compound_2F_Bed_Script_2
	compare VAR_PSFCAVE7_STATE, 3
	goto_if_eq Psfcity8_Compound_2F_Bed_Script_2
Psfcity8_Compound_2F_Bed_Script_1:
	callnative HealPlayerParty
	fadescreen FADE_TO_BLACK
	delay 16
	msgbox gText_BedScript_WhenShouldWake
	closemessage
	call PlayersHouse_2F_EventScript_SetWallClock
	switch VAR_STORYLINE_STATE
	case 9, Psfcity8_Compound_2F_Bed_Script_8
	case 24, Psfcity8_Compound_2F_Bed_Script_9
	case 26, Psfcity8_Compound_2F_Bed_Script_10
	case 42, Psfcity8_Compound_2F_Bed_Script_11
	fadescreen FADE_FROM_BLACK
Psfcity8_Compound_2F_Bed_Script_6:
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq Psfcity8_Compound_2F_Bed_Script_14
Psfcity8_Compound_2F_Bed_Script_13:
	release
	end

Psfcity8_Compound_2F_Bed_Script_2:
	call YouRealizeTheyreEvilRight_CantSleep_Dialogue
	goto Psfcity8_Compound_2F_Bed_Script_1

Psfcity8_Compound_2F_Bed_Script_8:
	call AaandWereBack_FerryRepaired_Dialogue
	goto Psfcity8_Compound_2F_Bed_Script_6

Psfcity8_Compound_2F_Bed_Script_9:
	call OffYouGo_WakeUp_Dialogue
	goto Psfcity8_Compound_2F_Bed_Script_6

Psfcity8_Compound_2F_Bed_Script_10:
	call WhyAreYouHelpingThem_StartChampionship_Dialogue
	goto Psfcity8_Compound_2F_Bed_Script_6

Psfcity8_Compound_2F_Bed_Script_11:
	call YouRealizeTheyreEvilRight_NoIdea_Dialogue
	goto Psfcity8_Compound_2F_Bed_Script_6

Psfcity8_Compound_2F_Bed_Script_14:
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	giveitem ITEM_FASHION_CASE
	goto Psfcity8_Compound_2F_Bed_Script_13


gText_BedScript_WhenShouldWake::
	.string "Let's get some rest...when should we\n"
	.string "wake up?$"
