Alcatraz_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Alcatraz_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Alcatraz_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Alcatraz_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Alcatraz_MapScripts_OnTransition
	return

Alcatraz_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALCATRAZ_STATE, 3, YouRealizeTheyreEvilRight_PlayerLandedDialogue
	.2byte 0


Alcatraz_MapScripts_OnTransition::
	call Alcatraz_ExhibitCheck_Script
	call YouRealizeTheyreEvilRight_HideObject_Script
	call YouRealizeTheyreEvilRight_ShowObject_Script
	return


Alcatraz_ExhibitCheck_Script::
	call ResetAlcatrazExhibit_Script
	compare VAR_ALCATRAZ_EXHIBIT_STATE, 2
	goto_if_lt Alcatraz_ExhibitCheck_Script_1
	return

Alcatraz_ExhibitCheck_Script_1:
	setflag FLAG_TEMP_2
	return


AlcatrazAttendant_HealPlayer_Script::
	lock
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox gText_Alcatraz_IveHealedYourParty
	call ResetAlcatrazExhibit_Script
	closemessage
	release
	end


ResetAlcatrazExhibit_Script::
	clearflag TRAINER_FLAGS_START + TRAINER_ALBERTO
	clearflag TRAINER_FLAGS_START + TRAINER_ED
	clearflag TRAINER_FLAGS_START + TRAINER_DECLAN
	clearflag TRAINER_FLAGS_START + TRAINER_FREDRICK
	clearflag TRAINER_FLAGS_START + TRAINER_ZANDER
	clearflag TRAINER_FLAGS_START + TRAINER_LEAH
	compare VAR_ALCATRAZ_STATE, 2
	goto_if_lt ResetAlcatrazExhibit_Script_1
	return

ResetAlcatrazExhibit_Script_1:
	setvar VAR_ALCATRAZ_EXHIBIT_STATE, 0
	return


Alcatraz_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Alcatraz_UnlockedDestinations_Script
	return


Alcatraz_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	goto Alcatraz_FerryState0_Script
	return


Alcatraz_FerryState0_Script::
	multichoicedefault 18, 8, ALCATRAZ_FERRY_DESTINATIONS_VER1, 0, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Alcatraz_FerryState0_Script_2
	case 1, Alcatraz_FerryState0_Script_3
	case 2, Alcatraz_FerryState0_Script_4
	case MULTI_B_PRESSED, Alcatraz_FerryState0_Script_5
	return

Alcatraz_FerryState0_Script_2:
	warp MAP_FISHERMANSWHARF, 5, 6
	return

Alcatraz_FerryState0_Script_3:
	warp MAP_ALAMEDA, 3, 16
	return

Alcatraz_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Alcatraz_FerryState0_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_Alcatraz_IveHealedYourParty::
	.string "I've healed your party! You can battle\n"
	.string "these Trainers as often as you like.$"
