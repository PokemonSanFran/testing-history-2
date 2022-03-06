Psfcity8_Compound_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity8_Compound_1F_MapScripts_OnTransition
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, ImProbablyBetterThanYou_PsftransrivalIntro_Dialogue
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Swagbag_WelcomeToPsfregion1_Dialogue
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, WhyAreYouHelpingThem_BackAtCompound_Dialogue
	map_script_2 VAR_STORYLINE_STATE, 20, VSGarbodor_ReturnToTheCompound_Dialogue
	.2byte 0


Psfcity8_Compound_1F_MapScripts_OnTransition::
	switch VAR_STORYLINE_STATE
	case 9, Psfcity8_Compound_1F_MapScripts_OnTransition_3
	case 10, Psfcity8_Compound_1F_MapScripts_OnTransition_4
	case 20, Psfcity8_Compound_1F_MapScripts_OnTransition_5
Psfcity8_Compound_1F_MapScripts_OnTransition_1:
	switch VAR_LITTLEROOT_INTRO_STATE
	case 1, Psfcity8_Compound_1F_MapScripts_OnTransition_7
	case 3, Psfcity8_Compound_1F_MapScripts_OnTransition_8
	case 4, Psfcity8_Compound_1F_MapScripts_OnTransition_9
	case 5, Psfcity8_Compound_1F_MapScripts_OnTransition_10
	case 6, Psfcity8_Compound_1F_MapScripts_OnTransition_11
	case 7, Psfcity8_Compound_1F_MapScripts_OnTransition_12
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_3:
	goto Act1_1_ObjectCleanUp
	goto Psfcity8_Compound_1F_MapScripts_OnTransition_1

Psfcity8_Compound_1F_MapScripts_OnTransition_4:
	goto Act1_2_ObjectSetUp
	goto Psfcity8_Compound_1F_MapScripts_OnTransition_1

Psfcity8_Compound_1F_MapScripts_OnTransition_5:
	goto VSGarbodor_ReturnToTheCompound_ObjectSetUp
	goto Psfcity8_Compound_1F_MapScripts_OnTransition_1

Psfcity8_Compound_1F_MapScripts_OnTransition_7:
	goto ImProbablyBetterThanYou_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_8:
	goto Swagbag_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_9:
	goto ExplorePsfcity8_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_10:
	goto TwoHoursAgo_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_11:
	goto WorkingFerry_SetUp_Script
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_12:
	goto WhyAreYouHelpingThem_BackAtCompound_ObjectSetUp_Script
	return


ImProbablyBetterThanYou_ObjectSetUp::
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1_2
	setflag FLAG_HIDE_COMPOUND_POKEDEX_LEFT
	setflag FLAG_HIDE_COMPOUND_POKEDEX_RIGHT
	setflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL_2
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1
	return


Swagbag_ObjectSetUp::
	clearflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL_2
	clearflag FLAG_HIDE_COMPOUND_PSFBADADMIN1
	turnobject 3, DIR_WEST
	clearflag FLAG_HIDE_COMPOUND_POKEDEX_LEFT
	clearflag FLAG_HIDE_COMPOUND_POKEDEX_RIGHT
	setflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL
	return


ExplorePsfcity8_ObjectSetUp::
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 3, 8, 6
	return


TwoHoursAgo_ObjectSetUp::
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1
	clearflag FLAG_HIDE_COMPOUND_PSFBADADMIN1_2
	special GetNumberOfBadges
	compare VAR_TEMP_0, 4
	goto_if_gt TwoHoursAgo_ObjectSetUp_1
	return

TwoHoursAgo_ObjectSetUp_1:
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1_2
	return


Act1_1_ObjectCleanUp::
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN1_2
	clearflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL
	return


Act1_2_ObjectSetUp::
	setflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL
	return


Psftransrival_Compound_Script::
	compare VAR_STORYLINE_STATE, 9
	goto_if_eq Psftransrival_Compound_Script_1
	goto PsftransrivalAnnoyed_Dialogue
	return

Psftransrival_Compound_Script_1:
	goto Act1_1_Complete_Psftransrival_Dialogue
	return


PsftransrivalAnnoyed_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	switch VAR_TEMP_0
	case 1, PsftransrivalAnnoyed_Dialogue_3
	case 2, PsftransrivalAnnoyed_Dialogue_4
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalAnnoy_Text1, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
PsftransrivalAnnoyed_Dialogue_1:
	callnative ClearMugshot
	closemessage
	return

PsftransrivalAnnoyed_Dialogue_3:
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalAnnoy_Text2, MSGBOX_NPC
	setvar VAR_TEMP_0, 2
	goto PsftransrivalAnnoyed_Dialogue_1

PsftransrivalAnnoyed_Dialogue_4:
	msgbox gText_ImProbablyBetterThanYou_PsftransrivalAnnoy_Text3, MSGBOX_NPC
	setvar VAR_TEMP_0, 2
	goto PsftransrivalAnnoyed_Dialogue_1


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
	applymovement 2, PsftransrivalFollowPsfbadadmin1ToTable_Movement
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
	applymovement 2, PsftransrivalWalkOutside_Movement
	waitmovement 0
	playse SE_EXIT
	removeobject 2
	setflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL_2
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


Act1_1_Complete_Psftransrival_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_WhatsYourProgress, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_OnlyThree
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_YeahThatBusted
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_INeedToFigure
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_HardToComeBy
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_ImSureIllFigure
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

PsftransrivalIntro_Movement:
	walk_right
	walk_down
	step_end

PsftransrivalBackToCouch_Movement:
	walk_up
	walk_left
	step_end

PsftransrivalLookAround_Movement:
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

PsftransrivalGestureUpstairs_Movement:
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

PsftransrivalFollowPsfbadadmin1ToTable_Movement:
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

PsftransrivalWalkOutside_Movement:
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

gText_Act1_1_Complete_WhatsYourProgress::
	.string "Damn I'm beat. Getting five badges in\n"
	.string "one day was a hustle! What about you?$"

gText_Act1_1_Complete_OnlyThree::
	.string "Only three so far. I'm praying the ferry\n"
	.string "is fixed tomorrow.$"

gText_Act1_1_Complete_YeahThatBusted::
	.string "Yeah, that busted ferry sucks. I'm\n"
	.string "going to challenge the Psfcity5 and\l"
	.string "Psfcity18 Gyms tomorrow, and the ferry\l"
	.string "will definately be fixed after that, so\l"
	.string "Psfcity11 Gym will be last.$"

gText_Act1_1_Complete_INeedToFigure::
	.string "I need to figure out how to get some\n"
	.string "Go-Goggles too...$"

gText_Act1_1_Complete_HardToComeBy::
	.string "They're hard to come by right now. I\n"
	.string "only got these because Daddys knows\l"
	.string "the manufactuer over in Kanto.$"

gText_Act1_1_Complete_ImSureIllFigure::
	.string "I'm sure I'll figure something out.$"

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
	.string "Looks like Psftransrival woke up early\n"
	.string "and already left! They're eager, I'll\l"
	.string "give them that. I guess they didn't\l"
	.string "need the explanation... or breakfast.$"

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
	.string "Psftransrival! If you fail to qualify\l"
	.string "for the Championship, we'll be\l"
	.string "terminating your contract, and you'll\l"
	.string "be on your own... but we know that won't\l"
	.string "be the case! So don't worry.$"

gText_TwoHoursAgo_LeftoversPokeballs_Text1::
	.string "Psfcompany2 is always so delicious! Too\n"
	.string "bad Psftransrival didn't eat with us. I\l"
	.string "guess you can take their portion of\l"
	.string "the food, and I bought you both\l"
	.string "PokéBalls, but you can have theirs too!$"

gText_TwoHoursAgo_ExplainLeftovers_Text1::
	.string "Your {STR_VAR_1} can hold those\n"
	.string "Leftovers to restore HP during battle.\l"
	.string "Now, you should get a move on! Don't let\l"
	.string "Psftransrival get too far ahead of\l"
	.string "you!$"
