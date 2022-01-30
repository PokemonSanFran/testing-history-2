ImProbablyBetterThanYou_PsftransrivalIntro_Dialogue::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WalkInside_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, PsftransrivalIntro_Movement
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text1
	closemessage
	goto ImProbablyBetterThanYou_KindaShabby_Dialogue
	end


ImProbablyBetterThanYou_KindaShabby_Dialogue::
	applymovement 1, PsftransrivalLookAround_Movement
	waitmovement 3
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text2
	closemessage
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text3
	callnative ClearMugshot
	closemessage
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text4
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text5
	goto ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue
	end


ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text6
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text7
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text8
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text9
	goto ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue
	end


ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text10
	applymovement 1, PsftransrivalGestureUpstairs_Movement
	waitmovement 0
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text11
	callnative ClearMugshot
	closemessage
	applymovement 1, PsftransrivalBackToCouch_Movement
	waitmovement 0
	playbgm MUS_BIRCH_LAB, TRUE
	releaseall
	end


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
	end


gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text1::
	.string "You must be {PLAYER}. Great to meet\n"
	.string "you!$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text2::
	.string "Kinda shabby, huh? I thought\n"
	.string "Psfbadguy1 was pulling out all the\l"
	.string "stops for us, but there's not a butler\l"
	.string "in sight! And no private tennis courts!\l"
	.string "Not that I ever play, but it's the\l"
	.string "principle of the thing...$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text3::
	.string "Oh yeah uh, it's too bad...$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text4::
	.string "*internal* This house is friggin' huge!\n"
	.string "Bigger than anywhere I've ever stayed,\l"
	.string "that's for sure...$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text5::
	.string "My flight was earlier today, so I've just\n"
	.string "been waiting around.$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text6::
	.string "I ordered some food too - Psfcompany1\n"
	.string "is the same here as it is back in Unova,\l"
	.string "and my Mom's card is still on the\l"
	.string "account! I'm sure she gets... points or\l"
	.string "something, right?$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text7::
	.string "Where are you from?$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text8::
	.string "Agate Village, Orre. You?$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text9::
	.string "Undella Town, Unova. Agate, right? I\n"
	.string "don't think I've heard of it... oh well.\l"
	.string "Probably just as boring as Undella. SO\l"
	.string "GLAD to be out of there!$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text10::
	.string "I know our orientation is supposed to\n"
	.string "start soon, or something like that. I\l"
	.string "took the bedroom on the left, so the\l"
	.string "one to the right is yours. I tried to\l"
	.string "take the good one because I got here\l"
	.string "first...$"

gText_ImProbablyBetterThanYou_PsftransrivalIntro_Text11::
	.string "but both rooms are exactly the same!\n"
	.string "Let's chill after you unpack.$"

gText_ImProbablyBetterThanYou_PsftransrivalAnnoy_Text1::
	.string "Go check out your room!$"

gText_ImProbablyBetterThanYou_PsftransrivalAnnoy_Text2::
	.string "Oh man, are you trying to do some\n"
	.string "bonding or something? Lemme finish\l"
	.string "this truffle burger first...$"

gText_ImProbablyBetterThanYou_PsftransrivalAnnoy_Text3::
	.string "Nom nom nom...$"

gText_ImProbablyBetterThanYou_ShouldUnpack_Dialogue::
	.string "I should check out my room!$"
