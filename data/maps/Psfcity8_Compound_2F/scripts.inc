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
	call Common_EventScript_OutOfCenterPartyHeal
	call RestInBed_Progression_Script
	closemessage
	releaseall
	end

RestInBed_Script_2:
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	goto RestInBed_Script_1


RestInBed_Progression_Script::
	checkitem ITEM_FASHION_CASE, 1
	compare VAR_RESULT, 0
	goto_if_eq RestInBed_Progression_Script_3
RestInBed_Progression_Script_1:
	compare VAR_STORYLINE_STATE, 9
	goto_if_eq RestInBed_Progression_Script_6
	return

RestInBed_Progression_Script_2:
	giveitem ITEM_FASHION_CASE
	goto RestInBed_Progression_Script_1

RestInBed_Progression_Script_3:
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq RestInBed_Progression_Script_2
	goto RestInBed_Progression_Script_1

RestInBed_Progression_Script_6:
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
	goto_if_gt RestInBed_Progression_Script_8
	return

RestInBed_Progression_Script_8:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FindAWayThrough
	callnative ClearMugshot
	return


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
