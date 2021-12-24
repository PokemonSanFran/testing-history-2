Psfroute1_MapScripts::
	.byte 0


FlyingBlind_CheckFainted_Script::
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, 0
	goto_if_eq FlyingBlind_CheckFainted_Script_2
	return

FlyingBlind_CheckFainted_Script_1:
	goto FlyingBlind_Dialogue
	return

FlyingBlind_CheckFainted_Script_2:
	compare VAR_FAINTED_FOG_STATE, 1
	goto_if_eq FlyingBlind_CheckFainted_Script_1
	return


FlyingBlind_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_FlyingBlind_NotSoEasy
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_GuessingYouSaw
	callnative ClearMugshot
	msgbox gText_FlyingBlind_NotJustYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_Karl
	callnative ClearMugshot
	msgbox gText_FlyingBlind_YouReallyBrandNew
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_WaitTheFogHas
	callnative ClearMugshot
	msgbox gText_FlyingBlind_NotVeryWell
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_NoResponse
	callnative ClearMugshot
	msgbox gText_FlyingBlind_EverSinceYouPeople
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_GottaFindSomebody
	msgbox gText_FlyingBlind_ThankYouSoMuch
	callnative ClearMugshot
	closemessage
	setvar VAR_FAINTED_FOG_STATE, 2
	goto FlyingBlind_CheckMoney_Script
	return


FlyingBlind_CheckMoney_Script::
	checkmoney 1000
	compare VAR_RESULT, 0
	goto_if_ne FlyingBlind_CheckMoney_Script_2
FlyingBlind_CheckMoney_Script_1:
	end

FlyingBlind_CheckMoney_Script_2:
	call FlyingBlind_AskDonation_Dialogue
	goto FlyingBlind_CheckMoney_Script_1


FlyingBlind_AskDonation_Dialogue::
	showmoneybox 0, 0
	msgbox gText_FlyingBlind_SpareChangeOldMan, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FlyingBlind_AskDonation_Dialogue_2
	msgbox gText_FlyingBlind_WereAllHurtin
FlyingBlind_AskDonation_Dialogue_1:
	hidemoneybox
	closemessage
	end

FlyingBlind_AskDonation_Dialogue_2:
	removemoney 1000, 0
	updatemoneybox 0
	msgbox gText_FlyingBlind_AppreciateIt
	goto FlyingBlind_AskDonation_Dialogue_1


FlyingBlind_WishLuck_Dialogue::
	msgbox gText_FlyingBlind_WishLuck_Dialogue
	closemessage
	end


gText_FlyingBlind_NotSoEasy::
	.string "Heh, not so easy out there, is it?$"

gText_FlyingBlind_GuessingYouSaw::
	.string "I'm guessing you saw earlier?$"

gText_FlyingBlind_NotJustYou::
	.string "It's not just you kid. Unless you've\n"
	.string "been here for a while, you've got no\l"
	.string "chance seeing through that thick ass\l"
	.string "fog. Karl don't take no prisoners.$"

gText_FlyingBlind_Karl::
	.string "Karl?$"

gText_FlyingBlind_YouReallyBrandNew::
	.string "Damn, you really brand new here, huh?\n"
	.string "The fog's name is Karl.$"

gText_FlyingBlind_WaitTheFogHas::
	.string "Wait, the fog has - okay so how do\n"
	.string "transplants normally handle the fog?$"

gText_FlyingBlind_NotVeryWell::
	.string "Not very well, I reckon, hehehe.$"

gText_FlyingBlind_NoResponse::
	.string "...$"

gText_FlyingBlind_EverSinceYouPeople::
	.string "Ever since you people showed up,\n"
	.string "Go-Goggles are always out of stock.\l"
	.string "They let you see through all this\l"
	.string "nonsense. You could getcha a Pokémon\l"
	.string "that knows Defog but uh, most of ‘em\l"
	.string "live on the other side of Karl! Karl\l"
	.string "don't come through every day though,\l"
	.string "so you could try to wait it out.$"

gText_FlyingBlind_GottaFindSomebody::
	.string "(I've gotta find somebody that has\n"
	.string "Go-Goggles, then. I don't have time to\l"
	.string "wait!)$"

gText_FlyingBlind_ThankYouSoMuch::
	.string "Thank you so much for your help.$"

gText_FlyingBlind_SpareChangeOldMan::
	.string "Hey uh, spare ¥1000 for an old man down\n"
	.string "on his luck?$"

gText_FlyingBlind_AppreciateIt::
	.string "Appreciate it. Good luck doing...\n"
	.string "whatever you kids do.$"

gText_FlyingBlind_WereAllHurtin::
	.string "I know, we're all hurtin' out here. Have a\n"
	.string "nice day, ya hear?$"

gText_FlyingBlind_WishLuck_Dialogue::
	.string "This fog is rough. Be careful out there,\n"
	.string "kid.$"
