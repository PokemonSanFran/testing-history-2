NoGoggles_PreventProgress::
	lock
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, 0
	goto_if_eq NoGoggles_PreventProgress_1
	return

NoGoggles_PreventProgress_1:
	msgbox NoGoggles_PreventProgress_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	release
	compare VAR_FAINTED_FOG_STATE, 0
	goto_if_eq NoGoggles_PreventProgress_4
NoGoggles_PreventProgress_3:
	end

NoGoggles_PreventProgress_4:
	setvar VAR_FAINTED_FOG_STATE, 1
	goto NoGoggles_PreventProgress_3


FlyingBlind_CheckFainted_Script::
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, 0
	goto_if_eq FlyingBlind_CheckFainted_Script_3
FlyingBlind_CheckFainted_Script_2:
	release
	return

FlyingBlind_CheckFainted_Script_1:
	goto FlyingBlind_Dialogue
	return

FlyingBlind_CheckFainted_Script_3:
	compare VAR_FAINTED_FOG_STATE, 1
	goto_if_eq FlyingBlind_CheckFainted_Script_1
	goto FlyingBlind_CheckFainted_Script_2


FlyingBlind_Dialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_FlyingBlind_NotSoEasy
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_GuessingYouSaw
	callnative ClearMugshot
	msgbox gText_FlyingBlind_NotJustYou
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_Karl
	callnative ClearMugshot
	msgbox gText_FlyingBlind_YouReallyBrandNew
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_WaitTheFogHas
	callnative ClearMugshot
	msgbox gText_FlyingBlind_NotVeryWell
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_NoResponse
	callnative ClearMugshot
	msgbox gText_FlyingBlind_EverSinceYouPeople
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_FlyingBlind_GottaFindSomebody
	msgbox gText_FlyingBlind_ThankYouSoMuch
	callnative ClearMugshot
	setvar VAR_FAINTED_FOG_STATE, 2
	call Homeless_CheckMoney_Script
	closemessage
	release
	end


NoGoggles_PreventProgress_Text_0:
	.string "A wild Mewtwo jumped out of the bushes\n"
	.string "and kicked your ass.$"

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
	.string "that knows Defog, or meet a local takes\l"
	.string "a liking to you and offers to lend you\l"
	.string "theirs. Karl don't come through every\l"
	.string "day though, so you could try to wait it\l"
	.string "out.$"

gText_FlyingBlind_GottaFindSomebody::
	.string "(I've gotta find somebody that has\n"
	.string "Go-Goggles, then. I don't have time to\l"
	.string "wait!)$"

gText_FlyingBlind_ThankYouSoMuch::
	.string "Thank you so much for your help.$"
