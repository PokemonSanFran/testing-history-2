SouthBay_YCCompound_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_LITTLEROOT_INTRO_STATE
	case 3, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto Swagbag_SetUpRoom
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, ImProbablyBetterThanYou_BiancaIntro_Dialogue
	.2byte 0


Swagbag_SetUpRoom::
	setobjectxyperm 1, 8, -1
	hideobjectat 1, MAP_SOUTH_BAY_YCCOMPOUND_1F
	setobjectxyperm 2, 6, 4
	setobjectxyperm 3, 7, 4
	return


ImProbablyBetterThanYou_BiancaIntro_Dialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WalkInside_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, BiancaIntro_Movement
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text1
	closemessage
	applymovement 1, BiancaLookAround_Movement
	waitmovement 3
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text2
	closemessage
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text3
	callnative ClearMugshot
	closemessage
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text4
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text5
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text6
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text7
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text8
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text9
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text10
	applymovement 1, BiancaGestureUpstairs_Movement
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text11
	callnative ClearMugshot
	applymovement 1, BiancaBackToCouch_Movement
	closemessage
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	return


BiancaAnnoyed_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	switch VAR_TEMP_0
	case 1, BiancaAnnoyed_Dialogue_3
	case 2, BiancaAnnoyed_Dialogue_4
	msgbox gText_ImProbablyBetterThanYou_BiancaAnnoy_Text1, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
BiancaAnnoyed_Dialogue_1:
	callnative ClearMugshot
	closemessage
	return

BiancaAnnoyed_Dialogue_3:
	msgbox gText_ImProbablyBetterThanYou_BiancaAnnoy_Text2, MSGBOX_NPC
	setvar VAR_TEMP_0, 2
	goto BiancaAnnoyed_Dialogue_1

BiancaAnnoyed_Dialogue_4:
	msgbox gText_ImProbablyBetterThanYou_BiancaAnnoy_Text3, MSGBOX_NPC
	setvar VAR_TEMP_0, 2
	goto BiancaAnnoyed_Dialogue_1


ImProbablyBetterThanYou_ShouldUnpack::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_ShouldUnpack_Dialogue
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkInside_Movement
	waitmovement 0
	releaseall
	return


WalkInside_Movement:
	walk_up
	step_end

BiancaIntro_Movement:
	walk_right
	walk_down
	step_end

BiancaBackToCouch_Movement:
	walk_up
	walk_left
	step_end

BiancaLookAround_Movement:
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_down
	delay_16
	delay_16
	step_end

BiancaGestureUpstairs_Movement:
	face_up
	delay_16
	step_end

gText_ImProbablyBetterThanYou_BiancaIntro_Text1::
	.string "You must be {PLAYER}. Great to meet\n"
	.string "you!$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text2::
	.string "Kinda shabby, huh? I thought YC was\n"
	.string "pulling out all the stops for us, but\l"
	.string "there's not a butler in sight! And no\l"
	.string "private tennis courts! Not that I ever\l"
	.string "play, but it's the principle of the\l"
	.string "thing...$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text3::
	.string "Oh yeah uh, it's too bad...$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text4::
	.string "*internal* This house is friggin' huge!\n"
	.string "Bigger than anywhere I've ever stayed,\l"
	.string "that's for sure...$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text5::
	.string "My flight was earlier today, so I've just\n"
	.string "been waiting around.$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text6::
	.string "I ordered some food too - Doordash is\n"
	.string "the same here as it is back in Unova,\l"
	.string "and my Mom's card is still on the\l"
	.string "account! I'm sure she gets... points or\l"
	.string "something, right?$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text7::
	.string "Where are you from?$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text8::
	.string "Agate Village, Orre. You?$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text9::
	.string "Undella Town, Unova. Agate, right? I\n"
	.string "don't think I've heard of it... oh well.\l"
	.string "Probably just as boring as Undella. SO\l"
	.string "GLAD to be out of there!$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text10::
	.string "I know our orientation is supposed to\n"
	.string "start soon, or something like that. I\l"
	.string "took the bedroom on the left, so the\l"
	.string "one to the right is yours. I tried to\l"
	.string "take the good one because I got here\l"
	.string "first...$"

gText_ImProbablyBetterThanYou_BiancaIntro_Text11::
	.string "but both rooms are exactly the same!\n"
	.string "Let's chill after you unpack.$"

gText_ImProbablyBetterThanYou_BiancaAnnoy_Text1::
	.string "Go check out your room!$"

gText_ImProbablyBetterThanYou_BiancaAnnoy_Text2::
	.string "Oh man, are you trying to do some\n"
	.string "bonding or something? Lemme finish\l"
	.string "this truffle burger first...$"

gText_ImProbablyBetterThanYou_BiancaAnnoy_Text3::
	.string "Nom nom nom...$"

gText_ImProbablyBetterThanYou_ShouldUnpack_Dialogue::
	.string "I should check out my room!$"
