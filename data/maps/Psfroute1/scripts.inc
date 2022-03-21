Psfroute1_MapScripts::
	.byte 0


Psfroute1_InteractHomeless_Script::
	lockall
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, 0
	goto_if_eq Psfroute1_InteractHomeless_Script_3
Psfroute1_InteractHomeless_Script_2:
	random 2
	switch VAR_RESULT
	case 0, Psfroute1_InteractHomeless_Script_8
	case 1, Psfroute1_InteractHomeless_Script_9
Psfroute1_InteractHomeless_Script_6:
	release
	end

Psfroute1_InteractHomeless_Script_1:
	goto FlyingBlind_Dialogue
	return

Psfroute1_InteractHomeless_Script_3:
	compare VAR_FAINTED_FOG_STATE, 1
	goto_if_eq Psfroute1_InteractHomeless_Script_1
	goto Psfroute1_InteractHomeless_Script_2

Psfroute1_InteractHomeless_Script_8:
	call Homeless_CheckMoney_Script
	goto Psfroute1_InteractHomeless_Script_6

Psfroute1_InteractHomeless_Script_9:
	call Homeless_WishLuck_Dialogue
	goto Psfroute1_InteractHomeless_Script_6


Homeless_CheckMoney_Script::
	checkmoney 1000
	compare VAR_RESULT, 0
	goto_if_ne Homeless_CheckMoney_Script_1
	call Homeless_WishLuck_Dialogue
	return

Homeless_CheckMoney_Script_1:
	call Homeless_AskDonation_Dialogue
	return


Homeless_AskDonation_Dialogue::
	showmoneybox 0, 0
	msgbox gText_Homeless_SpareChangeOldMan, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Homeless_AskDonation_Dialogue_2
	msgbox gText_Homeless_WereAllHurtin
Homeless_AskDonation_Dialogue_1:
	hidemoneybox
	return

Homeless_AskDonation_Dialogue_2:
	removemoney 1000, 0
	updatemoneybox 0
	msgbox gText_Homeless_AppreciateIt
	goto Homeless_AskDonation_Dialogue_1


Homeless_WishLuck_Dialogue::
	msgbox gText_Homeless_WishLuck, MSGBOX_NPC
	closemessage
	return


gText_Homeless_SpareChangeOldMan::
	.string "Hey uh, spare ¥1000 for an old man down\n"
	.string "on his luck?$"

gText_Homeless_AppreciateIt::
	.string "Appreciate it. Good luck doing...\n"
	.string "whatever you kids do.$"

gText_Homeless_WereAllHurtin::
	.string "I know, we're all hurtin' out here. Have a\n"
	.string "nice day, ya hear?$"

gText_Homeless_WishLuck::
	.string "This fog is rough. Be careful out there,\n"
	.string "kid.$"
