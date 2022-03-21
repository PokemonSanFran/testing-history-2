Psfplace13_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfplace13_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfplace13_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	.2byte 0


Psfplace13_InteractFerryAttendant_Script::
	lock
	checkitem ITEM_MYSTIC_TICKET, 1
	compare VAR_RESULT, 0
	goto_if_eq Psfplace13_InteractFerryAttendant_Script_1
	goto Psfplace13_ChooseFerryDestination_Script
	return

Psfplace13_InteractFerryAttendant_Script_1:
	msgbox gText_PreventPlayerFerry_ImSorryYou, MSGBOX_NPC
	release
	end


gText_PreventPlayerFerry_ImSorryYou::
	.string "I'm sorry, you don't appear to have the\n"
	.string "correct ticket to board the Ferry to\l"
	.string "Psfcave7.$"
