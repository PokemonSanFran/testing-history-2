Psfcave7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcave7_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcave7_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcave7_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Psfcave7_MapScripts_OnTransition
	return

Psfcave7_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PSFCAVE7_STATE, 3, YouRealizeTheyreEvilRight_PlayerLandedDialogue
	.2byte 0


Psfcave7_MapScripts_OnTransition::
	call Psfcave7_ExhibitCheck_Script
	call YouRealizeTheyreEvilRight_HideObject_Script
	call YouRealizeTheyreEvilRight_ShowObject_Script
	return


Psfcave7_ExhibitCheck_Script::
	call ResetPsfcave7Exhibit_Script
	compare VAR_PSFCAVE7_EXHIBIT_STATE, 2
	goto_if_lt Psfcave7_ExhibitCheck_Script_1
	return

Psfcave7_ExhibitCheck_Script_1:
	setflag FLAG_TEMP_2
	return


Psfcave7Attendant_HealPlayer_Script::
	lock
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox gText_Psfcave7_IveHealedYourParty
	call ResetPsfcave7Exhibit_Script
	closemessage
	release
	end


ResetPsfcave7Exhibit_Script::
	clearflag TRAINER_FLAGS_START + TRAINER_ALBERTO
	clearflag TRAINER_FLAGS_START + TRAINER_ED
	clearflag TRAINER_FLAGS_START + TRAINER_DECLAN
	clearflag TRAINER_FLAGS_START + TRAINER_FREDRICK
	clearflag TRAINER_FLAGS_START + TRAINER_ZANDER
	clearflag TRAINER_FLAGS_START + TRAINER_LEAH
	compare VAR_PSFCAVE7_STATE, 2
	goto_if_lt ResetPsfcave7Exhibit_Script_1
	return

ResetPsfcave7Exhibit_Script_1:
	setvar VAR_PSFCAVE7_EXHIBIT_STATE, 0
	return


Psfcave7_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfcave7_UnlockedDestinations_Script
	return


Psfcave7_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	goto Psfcave7_FerryState0_Script
	return


Psfcave7_FerryState0_Script::
	multichoicedefault 18, 8, PSFCAVE7_FERRY_DESTINATIONS_VER1, 0, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Psfcave7_FerryState0_Script_2
	case 1, Psfcave7_FerryState0_Script_3
	case 2, Psfcave7_FerryState0_Script_4
	case MULTI_B_PRESSED, Psfcave7_FerryState0_Script_5
	return

Psfcave7_FerryState0_Script_2:
	warp MAP_PSFPLACE13, 5, 6
	return

Psfcave7_FerryState0_Script_3:
	warp MAP_PSFCITY17, 3, 16
	return

Psfcave7_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfcave7_FerryState0_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


gText_Psfcave7_IveHealedYourParty::
	.string "I've healed your party! You can battle\n"
	.string "these Trainers as often as you like.$"
