Alcatraz_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Alcatraz_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Alcatraz_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Alcatraz_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call YoungPadawan_HideMalva_Script
	call ResetAlcatrazExhibit_Script
	call YouRealizeTheyreEvilRight_HideObject_Script
	return

Alcatraz_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALCATRAZ_STATE, ARCHER_SUMMONED_ALCATRAZ, YouRealizeTheyreEvilRight_PlayerLandedDialogue
	.2byte 0


Alcatraz_MapScripts_OnTransition::
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
	clearflag TRAINER_FLAGS_START + TRAINER_ALCATRAZ_TRAINER_A
	clearflag TRAINER_FLAGS_START + TRAINER_ALCATRAZ_TRAINER_B
	clearflag TRAINER_FLAGS_START + TRAINER_ALCATRAZ_TRAINER_C
	clearflag TRAINER_FLAGS_START + TRAINER_ALCATRAZ_TRAINER_D
	clearflag TRAINER_FLAGS_START + TRAINER_ALCATRAZ_TRAINER_E
	clearflag TRAINER_FLAGS_START + TRAINER_ALCATRAZ_TRAINER_F
	compare VAR_ALCATRAZ_STATE, FIRST_ARRIVED_ALCATRAZ
	goto_if_eq ResetAlcatrazExhibit_Script_1
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


Alcatraz_EventScript_DeliveryD::
	returnqueststate QUEST_BODEGABURNOUT
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Alcatraz_EventScript_DeliveryD_2
Alcatraz_EventScript_DeliveryD_1:
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_AUTOCLOSE
	end

Alcatraz_EventScript_DeliveryD_2:
	goto Quest_Bodegaburnout_DeliveryD_Dialogue
	goto Alcatraz_EventScript_DeliveryD_1


gText_Alcatraz_IveHealedYourParty::
	.string "I've healed your party! You can battle\n"
	.string "these Trainers as often as you like.$"
