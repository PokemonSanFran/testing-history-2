SouthBay_YCCompound_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_LITTLEROOT_INTRO_STATE
	case 1, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case 3, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	case 4, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	case 5, SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto ImProbablyBetterThanYou_ObjectSetUp
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto Swagbag_ObjectSetUp
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	goto Started2HoursAgo_ObjectSetUp
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION_5:
	goto TwoHoursAgo_ObjectSetUp
	return

SouthBay_YCCompound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, ImProbablyBetterThanYou_BiancaIntro_Dialogue
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Swagbag_WelcomeToSanFran_Dialogue
	.2byte 0


ImProbablyBetterThanYou_ObjectSetUp::
	setflag FLAG_HIDE_SOUTHBAY_POKEDEX_LEFT
	setflag FLAG_HIDE_SOUTHBAY_POKEDEX_RIGHT
	return


Swagbag_ObjectSetUp::
	setobjectxyperm 1, -8, -8
	setobjectxyperm 2, 6, 4
	setobjectxyperm 3, 7, 4
	clearflag FLAG_HIDE_SOUTHBAY_POKEDEX_LEFT
	clearflag FLAG_HIDE_SOUTHBAY_POKEDEX_RIGHT
	return


Started2HoursAgo_ObjectSetUp::
	return


TwoHoursAgo_ObjectSetUp::
	return


ImProbablyBetterThanYou_BiancaIntro_Dialogue::
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, WalkInside_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, BiancaIntro_Movement
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text1
	closemessage
	goto ImProbablyBetterThanYou_KindaShabby_Dialogue
	end


ImProbablyBetterThanYou_KindaShabby_Dialogue::
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
	goto ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue
	end


ImProbablyBetterThanYou_FoodAndWhereYouFrom_Dialogue::
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
	goto ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue
	end


ImProbablyBetterThanYou_TookTheLeftBedroom_Dialogue::
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text10
	applymovement 1, BiancaGestureUpstairs_Movement
	waitmovement 0
	msgbox gText_ImProbablyBetterThanYou_BiancaIntro_Text11
	callnative ClearMugshot
	closemessage
	applymovement 1, BiancaBackToCouch_Movement
	waitmovement 0
	fadedefaultbgm
	releaseall
	end


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
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_ImProbablyBetterThanYou_ShouldUnpack_Dialogue
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WalkInside_Movement
	waitmovement 0
	releaseall
	end


Swagbag_WelcomeToSanFran_Dialogue::
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	lockall
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, OakGreetPlayer_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToSanFran_Text1
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToSanFran_Text2
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToSanFran_Text3
	callnative ClearMugshot
	closemessage
	applymovement 3, OakWalkToTable_Movement
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, PlayerFollowOakToTable_Movement
	applymovement 2, BiancaFollowOakToTable_Movement
	waitmovement 0
	goto Swagbag_LeagueStipend_Dialogue
	end


Swagbag_LeagueStipend_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_LeagueStipend_Text1
	msgbox gText_Swagbag_LeagueStipend_Text2
	callnative ClearMugshot
	closemessage
	addmoney 50000, 0
	goto Swagbag_PokedexApps_Dialogue
	end


Swagbag_PokedexApps_Dialogue::
	return


Swagbag_WhenCanWeStart_Dialogue::
	return


Swagbag_DontLeaveSouthBay::
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
	delay_16
	face_down
	step_end

OakGreetPlayer_Movement:
	face_up
	walk_up
	delay_16
	step_end

OakWalkToTable_Movement:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_down
	step_end

BiancaFollowOakToTable_Movement:
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

PlayerFollowOakToTable_Movement:
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

gText_Swagbag_WelcomeToSanFran_Text1::
	.string "{PLAYER}! Welcome to SanFran! How was\n"
	.string "your flight?$"

gText_Swagbag_WelcomeToSanFran_Text2::
	.string "Great! The private car from the airport\n"
	.string "was a surprise, but everything was\l"
	.string "super smooth, thanks!$"

gText_Swagbag_WelcomeToSanFran_Text3::
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
	.string "Berkeley, it might be ready.$"

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
	.string "You received $50000, a PokéDex, and new\n"
	.string "phone Apps from YC!$"

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

gText_Swagbag_DontLeaveSouthBay_Text1::
	.string "{PLAYER}, I'll be working on my laptop\n"
	.string "here for the next few hours. If you've\l"
	.string "got any questions, don't be afraid to\l"
	.string "ask. It's fine if you explore, but don't\l"
	.string "leave South Bay, okay?$"

gText_Swagbag_DontLeaveSouthBay_Text2::
	.string "Got it. Thanks for all the help, Oak! I'm\n"
	.string "still so stoked for the opportunity\l"
	.string "and the Challenge!$"
