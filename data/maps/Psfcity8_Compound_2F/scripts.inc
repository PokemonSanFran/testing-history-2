Psfcity8_Compound_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity8_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity8_Compound_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
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
	fadescreen FADE_TO_BLACK
	callnative HealPlayerParty
	call RestInBed_StillBlack_Script
	call RestInBed_Progression_Script
	fadescreen FADE_FROM_BLACK
	closemessage
	releaseall
	end

RestInBed_Script_2:
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	goto RestInBed_Script_1


RestInBed_Progression_Script::
	fadescreen FADE_FROM_BLACK
	checkitem ITEM_FASHION_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq RestInBed_Progression_Script_3
RestInBed_Progression_Script_1:
	switch VAR_STORYLINE_STATE
	case 9, RestInBed_Progression_Script_8
RestInBed_Progression_Script_6:
	releaseall
	end

RestInBed_Progression_Script_2:
	giveitem ITEM_FASHION_CASE
	goto RestInBed_Progression_Script_1

RestInBed_Progression_Script_3:
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq RestInBed_Progression_Script_2
	goto RestInBed_Progression_Script_1

RestInBed_Progression_Script_8:
	call RestInBed_FerryRepaired_Dialogue
	goto RestInBed_Progression_Script_6


RestInBed_FerryRepaired_Dialogue::
	addvar VAR_STORYLINE_STATE, 1
	pokenavcall blank
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ThatsDifferent
	callnative ClearMugshot
	pokenavcall gText_FerryRepaired
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TooBadTheresNoFerry
	callnative ClearMugshot
	compare VAR_FAINTED_FOG_STATE, 1
	goto_if_gt RestInBed_FerryRepaired_Dialogue_1
	return

RestInBed_FerryRepaired_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FindAWayThrough
	callnative ClearMugshot
	return


RestInBed_StillBlack_Script::
	switch VAR_STORYLINE_STATE
	case 21, RestInBed_StillBlack_Script_2
	case 23, RestInBed_StillBlack_Script_3
	return

RestInBed_StillBlack_Script_2:
	call OffYouGo_WakeUp_Dialogue
	return

RestInBed_StillBlack_Script_3:
	call WhyAreYouHelpingThem_StartChampionship_Dialogue
	return


WhyAreYouHelpingThem_StartChampionship_Dialogue::
	msgbox gText_WhyAreYouHelpingThem_AreYouReadyToBegin, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WhyAreYouHelpingThem_StartChampionship_Dialogue_1
	addvar VAR_STORYLINE_STATE, 1
	warpsilent MAP_EVER_GRANDE_CITY, 255, 20, 20
	return

WhyAreYouHelpingThem_StartChampionship_Dialogue_1:
	closemessage
	fadescreen FADE_FROM_BLACK
	releaseall
	end


FashionCaseReminder_Script::
	goto_if_unset FLAG_USED_FASHION_CASE, FashionCaseReminder_Script_1
	release
	return

FashionCaseReminder_Script_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setflag FLAG_USED_FASHION_CASE
	lockall
	msgbox gText_FashionCaseReminder_Text1
	special OpenPokeblockCaseOnFeeder
	waitstate
	msgbox gText_FashionCaseReminder_Text2
	closemessage
	release
	end


gText_RestInBed_Text1::
	.string "Let's get some rest...when should we\n"
	.string "wake up?$"

gText_FashionCaseReminder_Text1::
	.string "What outfit do you want to wear today?$"

gText_FashionCaseReminder_Text2::
	.string "You can change your outfit whenever\n"
	.string "you like by using the Fashion Case,\l"
	.string "found in your Bag's Key Items pocket.$"

blank::
	.string "$"

gText_FerryRepaired::
	.string "A message from the PSFSUBWAY\n"
	.string "System. The following service\l"
	.string "routes are now operational:\p"
	.string "Psfplace11 to Psfcity17\p"
	.string "Psfcity17 to Psfcity9\p"
	.string "We appreciate your patience\n"
	.string "while the remaining routes are\l"
	.string "restored.$"

gText_ThatsDifferent::
	.string "That's a different notification...$"

gText_TooBadTheresNoFerry::
	.string "Looks like east Psfregion1 is next! Too\n"
	.string "bad there's no ferry directly to the\l"
	.string "Gym in Psfcity11...$"

gText_FindAWayThrough::
	.string "Hopefully, I'll find a way through the\n"
	.string "fog after that...$"
