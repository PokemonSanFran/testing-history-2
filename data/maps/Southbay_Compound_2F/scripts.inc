Southbay_Compound_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Southbay_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Southbay_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, Swagbag_IncrementIntroState_Script
	.2byte 0


Southbay_Compound_2F_Bed_Script::
	lock
	call YouRealizeTheyreEvilRight_CantSleep_Script
	callnative HealPlayerParty
	fadescreen FADE_TO_BLACK
	delay 16
	msgbox gText_BedScript_WhenShouldWake
	closemessage
	call PlayersHouse_2F_EventScript_SetWallClock
	switch VAR_STORYLINE_STATE
	case 9, Southbay_Compound_2F_Bed_Script_3
	case 24, Southbay_Compound_2F_Bed_Script_4
	case 26, Southbay_Compound_2F_Bed_Script_5
	case 42, Southbay_Compound_2F_Bed_Script_6
	case 99, Southbay_Compound_2F_Bed_Script_7
	case 101, Southbay_Compound_2F_Bed_Script_8
	case 106, Southbay_Compound_2F_Bed_Script_9
	fadescreen FADE_FROM_BLACK
Southbay_Compound_2F_Bed_Script_1:
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	goto_if_eq Southbay_Compound_2F_Bed_Script_12
Southbay_Compound_2F_Bed_Script_11:
	release
	end

Southbay_Compound_2F_Bed_Script_3:
	call AaandWereBack_FerryRepaired_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_4:
	call OffYouGo_WakeUp_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_5:
	call WhyAreYouHelpingThem_StartChampionship_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_6:
	call YouRealizeTheyreEvilRight_NoIdea_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_7:
	call YouRealizeTheyreEvilRight_NoIdea_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_8:
	call LetsFixThis_EliteVideo_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_9:
	call Earthquake_ThatNight_Dialogue
	goto Southbay_Compound_2F_Bed_Script_1

Southbay_Compound_2F_Bed_Script_12:
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	giveitem ITEM_FASHION_CASE
	goto Southbay_Compound_2F_Bed_Script_11


gText_BedScript_WhenShouldWake::
	.string "Let's get some rest...when should we\n"
	.string "wake up?$"
