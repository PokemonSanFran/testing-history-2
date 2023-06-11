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
	call FlyingBlind_DetermineLocation_Script
	msgbox gText_Homeless_SpareChangeOldMan, MSGBOX_YESNO, VAR_MSGBOX_SPEAKER
	compare VAR_RESULT, YES
	goto_if_eq Homeless_AskDonation_Dialogue_2
	msgbox gText_Homeless_WereAllHurtin, , VAR_MSGBOX_SPEAKER
Homeless_AskDonation_Dialogue_1:
	hidemoneybox
	return

Homeless_AskDonation_Dialogue_2:
	removemoney 1000, 0
	special RandomlyBoostPartyMemberFriendship
	updatemoneybox 0
	msgbox gText_Homeless_AppreciateIt, , VAR_MSGBOX_SPEAKER
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
