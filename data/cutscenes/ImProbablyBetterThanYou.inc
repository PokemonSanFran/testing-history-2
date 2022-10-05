ImProbablyBetterThanYou_ObjectSetUp::
	setflag FLAG_TEMP_2
	return


ImProbablyBetterThanYou_MovePlayerInside_Script::
	warpdoor MAP_SOUTHBAY_COMPOUND_1F, 255, 5, 9
	waitstate
	end


ImProbablyBetterThanYou_StandingOutside_Dialogue::
	lockall
	setvar VAR_PLAYER_HOME_STATE, HAS_NOT_MET_BIANCA
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_DeepBreath
	callnative ClearMugshot
	closemessage
	call ImProbablyBetterThanYou_MovePlayerInside_Script
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	return


ImProbablyBetterThanYou_BiancaIntro_Dialogue::
	setvar VAR_PLAYER_HOME_STATE, HAS_MET_BIANCA
	lockall
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, ImProbablyBetterThanYou_WalkToPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_GreatToMeet
	closemessage
	callnative ClearMugshot
	goto ImProbablyBetterThanYou_KindaShabby_Dialogue
	end


ImProbablyBetterThanYou_KindaShabby_Dialogue::
	applymovement 1, ImProbablyBetterThanYou_LookAround
	waitmovement 0
	msgbox gText_ImProbablyBetterThanYou_KindaShabbyHuh
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_OhYeahUh
	msgbox gText_ImProbablyBetterThanYou_ThisHouseIsFriggin
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_MyFlightWasEarlierToday
	goto ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue
	end


ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_IOrderedSomeFoodToo
	msgbox gText_ImProbablyBetterThanYou_WhereAreYouFrom
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_AgateVillageOrre
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_UndellaTownUnova
	goto ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue
	end


ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_IKnowOurOrientation
	applymovement 1, ImProbablyBetterThanYou_GestureUpstairs
	waitmovement 0
	msgbox gText_ImProbablyBetterThanYou_ButBothRooms
	callnative ClearMugshot
	closemessage
	applymovement 1, ImProbablyBetterThanYou_WalkToCouch
	waitmovement 0
	fadedefaultbgm
	releaseall
	end


ImProbablyBetterThanYou_PreventPlayerLeaving_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_IShouldCheckOut
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end


ImProbablyBetterThanYou_Annoyed_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	switch VAR_TEMP_0
	case 1, ImProbablyBetterThanYou_Annoyed_Dialogue_3
	case 2, ImProbablyBetterThanYou_Annoyed_Dialogue_4
	msgbox gText_ImProbablyBetterThanYou_GoCheckOutYourRoom, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
ImProbablyBetterThanYou_Annoyed_Dialogue_1:
	callnative ClearMugshot
	closemessage
	applymovement 1, ImProbablyBetterThanYou_GoBackToFood
	waitmovement 0
	return

ImProbablyBetterThanYou_Annoyed_Dialogue_3:
	msgbox gText_ImProbablyBetterThanYou_OhManAreYouTrying, MSGBOX_NPC
	addvar VAR_TEMP_0, 1
	goto ImProbablyBetterThanYou_Annoyed_Dialogue_1

ImProbablyBetterThanYou_Annoyed_Dialogue_4:
	msgbox gText_ImProbablyBetterThanYou_NomNomNom
	goto ImProbablyBetterThanYou_Annoyed_Dialogue_1


ImProbablyBetterThanYou_WalkToPlayer:
	walk_right
	walk_down
	step_end

ImProbablyBetterThanYou_WalkToCouch:
	walk_up
	walk_left
	step_end

ImProbablyBetterThanYou_LookAround:
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

ImProbablyBetterThanYou_GestureUpstairs:
	face_up
	delay_16
	delay_16
	face_down
	step_end

ImProbablyBetterThanYou_GoBackToFood:
	face_original_direction
	step_end

gText_ImProbablyBetterThanYou_DeepBreath::
	.string "*sigh* (Let's do this.)$"

gText_ImProbablyBetterThanYou_GreatToMeet::
	.string "You must be {PLAYER}! Welcome to the\n"
	.string "most boring place in the SanFran\l"
	.string "region... Southbay.$"

gText_ImProbablyBetterThanYou_KindaShabbyHuh::
	.string "Kinda shabby, huh? I thought\n"
	.string "YCombinator was pulling out all the\l"
	.string "stops for us, but there's not a butler\l"
	.string "in sight! And no private tennis courts!\l"
	.string "Not that I ever play, but it's the\l"
	.string "principle of the thing...$"

gText_ImProbablyBetterThanYou_OhYeahUh::
	.string "Oh yeah uh, it's too bad...$"

gText_ImProbablyBetterThanYou_ThisHouseIsFriggin::
	.string "*internal* This house is friggin' huge!\n"
	.string "Bigger than anywhere I've ever stayed,\l"
	.string "that's for sure...$"

gText_ImProbablyBetterThanYou_MyFlightWasEarlierToday::
	.string "My flight was earlier today, so I've just\n"
	.string "been waiting around.$"

gText_ImProbablyBetterThanYou_IOrderedSomeFoodToo::
	.string "I ordered some food too - DoorDash is\n"
	.string "the same here as it is back in Unova,\l"
	.string "and my Mom's card is still on the\l"
	.string "account! I'm sure she gets... points or\l"
	.string "something, right?$"

gText_ImProbablyBetterThanYou_WhereAreYouFrom::
	.string "Where are you from?$"

gText_ImProbablyBetterThanYou_AgateVillageOrre::
	.string "Agate Village, Orre. You?$"

gText_ImProbablyBetterThanYou_UndellaTownUnova::
	.string "Undella Town, Unova. Agate, right? I\n"
	.string "don't think I've heard of it... oh well.\l"
	.string "Probably just as boring as Undella. SO\l"
	.string "GLAD to be out of there!$"

gText_ImProbablyBetterThanYou_IKnowOurOrientation::
	.string "I know our orientation is supposed to\n"
	.string "start soon, or something like that. I\l"
	.string "took the bedroom on the left, so the\l"
	.string "one to the right is yours. I tried to\l"
	.string "take the good one because I got here\l"
	.string "first...$"

gText_ImProbablyBetterThanYou_ButBothRooms::
	.string "but both rooms are exactly the same!\n"
	.string "Let's chill after you unpack.$"

gText_ImProbablyBetterThanYou_GoCheckOutYourRoom::
	.string "Go check out your room!$"

gText_ImProbablyBetterThanYou_OhManAreYouTrying::
	.string "Oh man, are you trying to do some\n"
	.string "bonding or something? Lemme finish\l"
	.string "this truffle burger first...$"

gText_ImProbablyBetterThanYou_NomNomNom::
	.string "Nom nom nom...$"

gText_ImProbablyBetterThanYou_IShouldCheckOut::
	.string "I should check out my room!$"
