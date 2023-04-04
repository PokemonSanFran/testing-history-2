Southbay_Compound_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Southbay_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Southbay_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PLAYER_HOME_STATE, HAS_MET_BIANCA, Swagbag_IncrementState_Script
	.2byte 0


Southbay_Compound_2F_Bed_Script::
	lock
	call YouRealizeTheyreEvilRight_CantSleep_Script
	callnative HealPlayerParty
	fadescreen FADE_TO_BLACK
	delay 16
	gettime
	call BedScript_DetermineTimeOfDay
	call BedScript_SetNewTime_Script
	goto BedScript_AdvanceStory_Script
	return


BedScript_SetNewTime_Script::
	msgbox gText_BedScript_WhenShouldWake
	closemessage
	switch VAR_RESULT
	case 0, BedScript_SetNewTime_Script_3
	case 1, BedScript_SetNewTime_Script_4
	case 2, BedScript_SetNewTime_Script_5
	case 3, BedScript_SetNewTime_Script_6
	case MULTI_B_PRESSED, BedScript_SetNewTime_Script_6
BedScript_SetNewTime_Script_1:
	return

BedScript_SetNewTime_Script_3:
	initclock 6, 0
	goto BedScript_SetNewTime_Script_1

BedScript_SetNewTime_Script_4:
	initclock 14, 0
	goto BedScript_SetNewTime_Script_1

BedScript_SetNewTime_Script_5:
	initclock 21, 0
	goto BedScript_SetNewTime_Script_1

BedScript_SetNewTime_Script_6:
	goto BedScript_CancelSleep_Script
	goto BedScript_SetNewTime_Script_1


BedScript_CancelSleep_Script::
	fadescreen FADE_FROM_BLACK
	end


BedScript_DetermineTimeOfDay::
	gettime
	compare VAR_RESULT, 16
	goto_if_lt BedScript_DetermineTimeOfDay_2
BedScript_DetermineTimeOfDay_1:
	compare VAR_RESULT, 9
	goto_if_lt BedScript_DetermineTimeOfDay_5
BedScript_DetermineTimeOfDay_4:
	compare VAR_RESULT, 15
	goto_if_gt BedScript_DetermineTimeOfDay_7
	return

BedScript_DetermineTimeOfDay_2:
	bufferstring STR_VAR_3, BedScript_DetermineTimeOfDay_Text_0
	goto BedScript_DetermineTimeOfDay_1

BedScript_DetermineTimeOfDay_5:
	bufferstring STR_VAR_3, BedScript_DetermineTimeOfDay_Text_1
	goto BedScript_DetermineTimeOfDay_4

BedScript_DetermineTimeOfDay_7:
	bufferstring STR_VAR_3, BedScript_DetermineTimeOfDay_Text_2
	return


BedScript_AdvanceStory_Script::
	switch VAR_STORYLINE_STATE
	case 0, BedScript_AdvanceStory_Script_3
	case 9, BedScript_AdvanceStory_Script_4
	case 24, BedScript_AdvanceStory_Script_5
	case 26, BedScript_AdvanceStory_Script_6
	case STORY_POST_YOU_REALIZE_WERE_EVIL, BedScript_AdvanceStory_Script_7
	case STORY_MORNING_AFTER_TIMETRAVEL, BedScript_AdvanceStory_Script_8
	case 101, BedScript_AdvanceStory_Script_9
	case 106, BedScript_AdvanceStory_Script_10
BedScript_AdvanceStory_Script_1:
	fadescreen FADE_FROM_BLACK
	release
	end

BedScript_AdvanceStory_Script_3:
	call TwoHoursAgo_GiveFashionCase_Script
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_4:
	call AaandWereBack_FerryRepaired_Dialogue
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_5:
	call OffYouGo_WakeUp_Dialogue
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_6:
	call WhyAreYouHelpingThem_StartChampionship_Dialogue
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_7:
	call YouRealizeTheyreEvilRight_NoIdea_Dialogue
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_8:
	call YouRealizeTheyreEvilRight_NoIdea_Dialogue
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_9:
	call LetsFixThis_EliteVideo_Dialogue
	goto BedScript_AdvanceStory_Script_1

BedScript_AdvanceStory_Script_10:
	call Earthquake_ThatNight_Dialogue
	goto BedScript_AdvanceStory_Script_1


BedScript_DetermineTimeOfDay_Text_0:
	.string "Midday$"

BedScript_DetermineTimeOfDay_Text_1:
	.string "Morning$"

BedScript_DetermineTimeOfDay_Text_2:
	.string "Night$"

gText_BedScript_WhenShouldWake::
	.string "It is currently {STR_VAR_3}. What\n"
	.string "time of day do you want to wake up\l"
	.string "tomorrow?$"

BedScript_TimeOptions::
	.string "Morning$"
	.string "Midday$"
	.string "Night$"
	.string "Cancel$"
	.string "$"
