Presidio_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Presidio_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Presidio_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Presidio_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Presidio_MapScripts_OnTransition
	return

Presidio_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 21, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


Presidio_MapScripts_OnTransition::
	call YouLookTired_BlockMansionAccess_Script
	return


Presidio_MansionGuard_InteractScript::
	lock
	compare VAR_FORTPOINT_STATE, 2
	goto_if_lt Presidio_MansionGuard_InteractScript_2
	msgbox gText_KogaRaisonDetre_HasBeenExpectingYou, MSGBOX_NPC
Presidio_MansionGuard_InteractScript_1:
	releaseall
	end

Presidio_MansionGuard_InteractScript_2:
	msgbox Presidio_MansionGuard_InteractScript_Text_0
	goto Presidio_MansionGuard_InteractScript_1


Presidio_MansionGuard_InteractScript_Text_0:
	.string "...$"
