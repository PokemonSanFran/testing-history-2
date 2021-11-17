Psfcity8_Compound_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_LITTLEROOT_INTRO_STATE
	case 1, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case 3, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	case 4, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	case 5, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto ImProbablyBetterThanYou_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto Swagbag_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	goto ExplorePsfcity8_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	goto TwoHoursAgo_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, ImProbablyBetterThanYou_Psfchara4Intro_Dialogue
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Swagbag_WelcomeToPsfregion1_Dialogue
	.2byte 0


ImProbablyBetterThanYou_ObjectSetUp::
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1_2
	setflag FLAG_HIDE_COMPOUND_POKEDEX_LEFT
	setflag FLAG_HIDE_COMPOUND_POKEDEX_RIGHT
	setflag FLAG_HIDE_COMPOUND_PSFCHARA4_2
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1
	return


Swagbag_ObjectSetUp::
	clearflag FLAG_HIDE_COMPOUND_PSFCHARA4_2
	clearflag FLAG_HIDE_COMPOUND_PSFBADADMIN1
	turnobject 3, DIR_WEST
	clearflag FLAG_HIDE_COMPOUND_POKEDEX_LEFT
	clearflag FLAG_HIDE_COMPOUND_POKEDEX_RIGHT
	setflag FLAG_HIDE_COMPOUND_PSFCHARA4
	return


ExplorePsfcity8_ObjectSetUp::
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 3, 8, 6
	return


TwoHoursAgo_ObjectSetUp::
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1
	clearflag FLAG_HIDE_COMPOUND_PSFBADADMIN1_2
	return


ImProbablyBetterThanYou_Psfchara4Intro_Dialogue::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WalkInside_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Psfchara4Intro_Movement
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text1
	closemessage
	goto ImProbablyBetterThanYou_KindaShabby_Dialogue
	end


ImProbablyBetterThanYou_KindaShabby_Dialogue::
	applymovement 1, Psfchara4LookAround_Movement
	waitmovement 3
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text2
	closemessage
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text3
	callnative ClearMugshot
	closemessage
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text4
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text5
	goto ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue
	end


ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text6
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text7
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text8
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text9
	goto ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue
	end


ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text10
	applymovement 1, Psfchara4GestureUpstairs_Movement
	waitmovement 0
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Intro_Text11
	callnative ClearMugshot
	closemessage
	applymovement 1, Psfchara4BackToCouch_Movement
	waitmovement 0
	playbgm MUS_BIRCH_LAB, TRUE
	releaseall
	end


Psfchara4Annoyed_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	switch VAR_TEMP_0
	case 1, Psfchara4Annoyed_Dialogue_3
	case 2, Psfchara4Annoyed_Dialogue_4
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Annoy_Text1, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
Psfchara4Annoyed_Dialogue_1:
	callnative ClearMugshot
	closemessage
	return

Psfchara4Annoyed_Dialogue_3:
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Annoy_Text2, MSGBOX_NPC
	setvar VAR_TEMP_0, 2
	goto Psfchara4Annoyed_Dialogue_1

Psfchara4Annoyed_Dialogue_4:
	msgbox gText_ImProbablyBetterThanYou_Psfchara4Annoy_Text3, MSGBOX_NPC
	setvar VAR_TEMP_0, 2
	goto Psfchara4Annoyed_Dialogue_1


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


Swagbag_WelcomeToPsfregion1_Dialogue::
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	lockall
	playse SE_PIN
	playbgm MUS_RG_FOLLOW_ME, TRUE
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, Psfbadadmin1GreetPlayer_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToPsfregion1_Text1
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToPsfregion1_Text2
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToPsfregion1_Text3
	callnative ClearMugshot
	closemessage
	applymovement 3, Psfbadadmin1WalkToTable_Movement
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFollowPsfbadadmin1ToTable_Movement
	applymovement 2, Psfchara4FollowPsfbadadmin1ToTable_Movement
	waitmovement 0
	goto Swagbag_LeagueStipend_Dialogue
	end


Swagbag_LeagueStipend_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_LeagueStipend_Text1
	msgbox gText_Swagbag_LeagueStipend_Text2
	closemessage
	addmoney 50000, 0
	goto Swagbag_PokedexApps_Dialogue
	end


Swagbag_PokedexApps_Dialogue::
	msgbox gText_Swagbag_PokedexApps_Text1
	msgbox gText_Swagbag_PokedexApps_Text2
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text3
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text4
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text5
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text6
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text7
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text8
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_PokedexApps_Text9
	callnative ClearMugshot
	removeobject 5
	removeobject 4
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_Swagbag_PokedexApps_Text10
	waitmessage
	waitfanfare
	goto Swagbag_WhenCanWeStart_Dialogue
	return


Swagbag_WhenCanWeStart_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WhenCanWeStart_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_WhenCanWeStart_Text2
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WhenCanWeStart_Text3
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_WhenCanWeStart_Text4
	callnative ClearMugshot
	closemessage
	applymovement 2, Psfchara4WalkOutside_Movement
	waitmovement 0
	playse SE_EXIT
	removeobject 2
	setflag FLAG_HIDE_COMPOUND_PSFCHARA4_2
	delay 30
	goto Swagbag_DontLeavePsfcity8
	return


Swagbag_DontLeavePsfcity8::
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_DontLeavePsfcity8_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_DontLeavePsfcity8_Text2
	closemessage
	callnative ClearMugshot
	applymovement 3, Psfbadadmin1WalkToLaptop_Movement
	waitmovement 0
	playbgm MUS_BIRCH_LAB, TRUE
	releaseall
	end


Swagbag_AnnoyPsfbadadmin1_Script::
	lockall
	faceplayer
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_AnnoyPsfbadadmin1_Text1, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	turnobject 3, DIR_EAST
	releaseall
	end


TwoHoursAgo_TheyreEager_Dialogue::
	goto_if_set FLAG_RECIEVED_LEFTOVERS_PSFBADADMIN1, TwoHoursAgo_TheyreEager_Dialogue_2
TwoHoursAgo_TheyreEager_Dialogue_1:
	lockall
	faceplayer
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TwoHoursAgo_TheyreEager_Text1, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	goto TwoHoursAgo_ExplainLeague_SetUp
	return

TwoHoursAgo_TheyreEager_Dialogue_2:
	goto TwoHoursAgo_ExplainLeftovers_Dialouge
	goto TwoHoursAgo_TheyreEager_Dialogue_1


TwoHoursAgo_ExplainLeague_SetUp::
	lock
	fadescreen FADE_TO_BLACK
	setobjectxy 6, 4, 6
	turnobject 6, DIR_WEST
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_LEFT
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	call CameraToPlayer_Movement
	goto TwoHoursAgo_ExplainLeague_Script
	return


TwoHoursAgo_ExplainLeague_Script::
	lockall
	msgbox gText_TwoHoursAgo_ExplainLeague_Text1
	msgbox gText_TwoHoursAgo_ExplainLeague_Text2
	msgbox gText_TwoHoursAgo_ExplainLeague_Text3
	closemessage
	fadescreen FADE_FROM_BLACK
	goto TwoHoursAgo_LeftoversPokeballs_Dialogue
	return


TwoHoursAgo_LeftoversPokeballs_Dialogue::
	setflag FLAG_RECIEVED_LEFTOVERS_PSFBADADMIN1
	callnative DrawMugshot
	msgbox gText_TwoHoursAgo_LeftoversPokeballs_Text1
	lockall
	giveitem ITEM_LEFTOVERS
	giveitem ITEM_POKE_BALL, 5
	callnative ClearMugshot
	closemessage
	releaseall
	end


TwoHoursAgo_ExplainLeftovers_Dialouge::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	bufferleadmonspeciesname 0
	msgbox gText_TwoHoursAgo_ExplainLeftovers_Text1, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


CameraToPlayer_Movement::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 6
	special TeleportCamera
	return


WalkInside_Movement:
	walk_up
	step_end

Psfchara4Intro_Movement:
	walk_right
	walk_down
	step_end

Psfchara4BackToCouch_Movement:
	walk_up
	walk_left
	step_end

Psfchara4LookAround_Movement:
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

Psfchara4GestureUpstairs_Movement:
	face_up
	delay_16
	delay_16
	face_down
	step_end

Psfbadadmin1GreetPlayer_Movement:
	face_up
	walk_up
	delay_16
	step_end

Psfbadadmin1WalkToTable_Movement:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end

Psfchara4FollowPsfbadadmin1ToTable_Movement:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

PlayerFollowPsfbadadmin1ToTable_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Psfchara4WalkOutside_Movement:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

Psfbadadmin1WalkToLaptop_Movement:
	walk_left
	walk_left
	walk_down
	face_right
	step_end

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text1::
	.string "You must be {PLAYER}. Great to meet\n"
	.string "you!$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text2::
	.string "Kinda shabby, huh? I thought\n"
	.string "Psfbadguy1 was pulling out all the\l"
	.string "stops for us, but there's not a butler\l"
	.string "in sight! And no private tennis courts!\l"
	.string "Not that I ever play, but it's the\l"
	.string "principle of the thing...$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text3::
	.string "Oh yeah uh, it's too bad...$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text4::
	.string "*internal* This house is friggin' huge!\n"
	.string "Bigger than anywhere I've ever stayed,\l"
	.string "that's for sure...$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text5::
	.string "My flight was earlier today, so I've just\n"
	.string "been waiting around.$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text6::
	.string "I ordered some food too - Psfcompany1\n"
	.string "is the same here as it is back in Unova,\l"
	.string "and my Mom's card is still on the\l"
	.string "account! I'm sure she gets... points or\l"
	.string "something, right?$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text7::
	.string "Where are you from?$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text8::
	.string "Agate Village, Orre. You?$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text9::
	.string "Undella Town, Unova. Agate, right? I\n"
	.string "don't think I've heard of it... oh well.\l"
	.string "Probably just as boring as Undella. SO\l"
	.string "GLAD to be out of there!$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text10::
	.string "I know our orientation is supposed to\n"
	.string "start soon, or something like that. I\l"
	.string "took the bedroom on the left, so the\l"
	.string "one to the right is yours. I tried to\l"
	.string "take the good one because I got here\l"
	.string "first...$"

gText_ImProbablyBetterThanYou_Psfchara4Intro_Text11::
	.string "but both rooms are exactly the same!\n"
	.string "Let's chill after you unpack.$"

gText_ImProbablyBetterThanYou_Psfchara4Annoy_Text1::
	.string "Go check out your room!$"

gText_ImProbablyBetterThanYou_Psfchara4Annoy_Text2::
	.string "Oh man, are you trying to do some\n"
	.string "bonding or something? Lemme finish\l"
	.string "this truffle burger first...$"

gText_ImProbablyBetterThanYou_Psfchara4Annoy_Text3::
	.string "Nom nom nom...$"

gText_ImProbablyBetterThanYou_ShouldUnpack_Dialogue::
	.string "I should check out my room!$"

gText_Swagbag_WelcomeToPsfregion1_Text1::
	.string "{PLAYER}! Welcome to Psfregion1! How\n"
	.string "was your flight?$"

gText_Swagbag_WelcomeToPsfregion1_Text2::
	.string "Great! The private car from the airport\n"
	.string "was a surprise, but everything was\l"
	.string "super smooth, thanks!$"

gText_Swagbag_WelcomeToPsfregion1_Text3::
	.string "Excellent. You've already seen the\n"
	.string "house, so we can skip the tour... I have\l"
	.string "some presents!$"

gText_Swagbag_LeagueStipend_Text1::
	.string "So first, you'll each be getting a\n"
	.string "stipend from the League, which should\l"
	.string "be hitting your accounts soon. That\l"
	.string "money is yours, no strings attached, so\l"
	.string "do whatever you like with it. Just don't\l"
	.string "spend it all in one place!$"

gText_Swagbag_LeagueStipend_Text2::
	.string "*muttering* Because the board absolutely\n"
	.string "won't let us give you any more...$"

gText_Swagbag_PokedexApps_Text1::
	.string "Next, a newly upgraded PokéDex. It\n"
	.string "tracks all of the Pokémon you'll see\l"
	.string "and capture. There's some more habitat\l"
	.string "functionality, but it wasn't quite\l"
	.string "ready for primetime yet. By the time\l"
	.string "you visit the Research Institute in\l"
	.string "Psfcity11, it might be ready.$"

gText_Swagbag_PokedexApps_Text2::
	.string "Also, we've gone ahead and pre-loaded\n"
	.string "our internal apps onto your phones\l"
	.string "last night.$"

gText_Swagbag_PokedexApps_Text3::
	.string "Invasive much?$"

gText_Swagbag_PokedexApps_Text4::
	.string "Ha ha, we'll ask next time. You've now\n"
	.string "got access to our internal versions of\l"
	.string "QuestLog, Teachy TV, and Fame Checker.$"

gText_Swagbag_PokedexApps_Text5::
	.string "Teachy TV... so I should use that if I\n"
	.string "have a question or get stuck?$"

gText_Swagbag_PokedexApps_Text6::
	.string "Correct.$"

gText_Swagbag_PokedexApps_Text7::
	.string "And the Fame Checker - that's the app\n"
	.string "that logs important facts about\l"
	.string "important people, right?$"

gText_Swagbag_PokedexApps_Text8::
	.string "Bingo! You're actually the beta testers\n"
	.string "of QuestLog, but it's used to keep\l"
	.string "track of all the things you're working\l"
	.string "on. We'll occasionally send you things\l"
	.string "to do, so don't forget to read those\l"
	.string "notifications!$"

gText_Swagbag_PokedexApps_Text9::
	.string "Hmmm... those all sound pretty useful.\n"
	.string "Sweet, thanks!$"

gText_Swagbag_PokedexApps_Text10::
	.string "{PLAYER} received ¥50000, a PokéDex,\n"
	.string "and new phone applications from\l"
	.string "Psfbadadmin1.$"

gText_Swagbag_WhenCanWeStart_Text1::
	.string "I believe that's everything. Questions?$"

gText_Swagbag_WhenCanWeStart_Text2::
	.string "Yeah, when's the tutorial over? I wanna\n"
	.string "get a move on!$"

gText_Swagbag_WhenCanWeStart_Text3::
	.string "The Gym Challenge officially starts\n"
	.string "tomorrow. I suggest you get a good\l"
	.string "night's sleep, and over breakfast, I'll\l"
	.string "explain how it all works.$"

gText_Swagbag_WhenCanWeStart_Text4::
	.string "...fine. I'll explore the city a bit! Maybe\n"
	.string "I'll see you around, {PLAYER}.$"

gText_Swagbag_DontLeavePsfcity8_Text1::
	.string "{PLAYER}, I'll be working on my laptop\n"
	.string "here for the next few hours. If you've\l"
	.string "got any questions, don't be afraid to\l"
	.string "ask. It's fine if you explore, but don't\l"
	.string "leave South Bay, okay?$"

gText_Swagbag_DontLeavePsfcity8_Text2::
	.string "Got it. Thanks for all the help,\n"
	.string "Psfbadadmin1! I'm still so stoked for\l"
	.string "the opportunity and the Challenge!$"

gText_Swagbag_AnnoyPsfbadadmin1_Text1::
	.string "In the actual game, this will be a list of\n"
	.string "questions that the player can ask and\l"
	.string "getr answers to. Tutorial level shit.$"

gText_TwoHoursAgo_TheyreEager_Text1::
	.string "Looks like Psfchara4 woke up early and\n"
	.string "already left! They're eager, I'll give\l"
	.string "them that. I guess they didn't need the\l"
	.string "explanation... or breakfast.$"

gText_TwoHoursAgo_ExplainLeague_Text1::
	.string "You're in a race against hundreds of\n"
	.string "other Pokémon Trainers, to see who can\l"
	.string "beat our 8 Gym Leaders first. The first\l"
	.string "16 Trainers to do so, will qualify for\l"
	.string "the Championship Tournament, held in a\l"
	.string "few weeks.$"

gText_TwoHoursAgo_ExplainLeague_Text2::
	.string "The tournament will test all of your\n"
	.string "skills as a Trainer, but the win will\l"
	.string "become a Psfbadguy1 sponsored career\l"
	.string "Pokémon Trainer.$"

gText_TwoHoursAgo_ExplainLeague_Text3::
	.string "We expect the best from you and\n"
	.string "Psfchara4! If you fail to qualify for\l"
	.string "the Championship, we'll be terminating\l"
	.string "your contract, and you'll be on your\l"
	.string "own... but we know that won't be the\l"
	.string "case! So don't worry.$"

gText_TwoHoursAgo_LeftoversPokeballs_Text1::
	.string "Psfcompany2 is always so delicious! Too\n"
	.string "bad Psfchara4 didn't eat with us. I\l"
	.string "guess you can take their portion of\l"
	.string "the food, and I bought you both\l"
	.string "PokéBalls, but you can have theirs too!$"

gText_TwoHoursAgo_ExplainLeftovers_Text1::
	.string "Your {STR_VAR_1} can hold those\n"
	.string "Leftovers to restore HP during battle.\l"
	.string "Now, you should get a move on! Don't let\l"
	.string "Psfchara4 get too far ahead of you!$"