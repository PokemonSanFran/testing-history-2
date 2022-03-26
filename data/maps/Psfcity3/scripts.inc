Psfcity3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity3_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity3_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity3_MapScripts_OnTransition
	return

Psfcity3_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, 21, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


Psfcity3_MapScripts_OnTransition::
	call YouLookTired_BlockMansionAccess_Script
	return


Psfcity3_MansionGuard_InteractScript::
	lock
	compare VAR_PSFPLACE9_STATE, 2
	goto_if_lt Psfcity3_MansionGuard_InteractScript_2
	msgbox gText_KogaRaisonDetre_HasBeenExpectingYou, MSGBOX_NPC
Psfcity3_MansionGuard_InteractScript_1:
	releaseall
	end

Psfcity3_MansionGuard_InteractScript_2:
	msgbox Psfcity3_MansionGuard_InteractScript_Text_0
	goto Psfcity3_MansionGuard_InteractScript_1


Psfcity3_MansionGuard_InteractScript_Text_0:
	.string "...$"
