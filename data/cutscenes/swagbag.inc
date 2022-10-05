Swagbag_ObjectSetUp::
	turnobject 2, DIR_WEST
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxy 1, 6, 4
	setobjectxyperm 1, 6, 4
	return


Swagbag_IncrementState_Script::
	setvar VAR_PLAYER_HOME_STATE, CHECKED_OUT_BEDROOM
	return


swagbag_ObjectHide_Script::
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_RIGHT
	turnobject 2, DIR_EAST
	setobjectxy 2, 8, 6
	setobjectxyperm 2, 8, 6
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	return


Swagbag_WelcomeToSanFran_Dialogue::
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	lockall
	playse SE_PIN
	playbgm MUS_RG_FOLLOW_ME, TRUE
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, swagbag_GreetPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WelcomeToRegion
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_GreatThePrivateCar
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_ExcellentYouveAlready
	callnative ClearMugshot
	closemessage
	applymovement 1, swagbag_TurnFaceOak_Movement
	waitmovement 1
	goto Swagbag_LeagueStipend_Dialogue
	end


Swagbag_LeagueStipend_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_SoFirstYoullEach
	msgbox gText_Swagbag_BecauseTheBoard
	closemessage
	addmoney 50000, 0
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_SYS_QUEST_MENU_GET
	givecustommon SPECIES_SLOWKING_GALARIAN, 100, ITEM_ASSAULT_VEST, ITEM_BEAST_BALL, NATURE_CALM, 2, 252, 0, 12, 124, 120, 0, 31, 0, 31, 31, 31, 31, MOVE_SURF, MOVE_PSYCHIC, MOVE_FLAMETHROWER, MOVE_SPLASH
	givecustommon SPECIES_KYOGRE, 100, ITEM_BLUE_ORB, ITEM_LURE_BALL, NATURE_MODEST, 0, 0, 0, 4, 252, 0, 252, 31, 31, 31, 31, 31, 31, MOVE_SURF, MOVE_CALM_MIND, MOVE_SPLASH, MOVE_ICE_BEAM
	givecustommon SPECIES_ZACIAN_CROWNED_SWORD, 100, ITEM_GROUNDIUM_Z, ITEM_DUSK_BALL, NATURE_ADAMANT, 0, 0, 252, 4, 252, 0, 0, 31, 31, 31, 31, 31, 31, MOVE_PLAY_ROUGH, MOVE_SPLASH, MOVE_DIG, MOVE_CRUNCH
	goto Swagbag_PokedexApps_Dialogue
	end


Swagbag_PokedexApps_Dialogue::
	msgbox gText_Swagbag_AlsoWeveGoneAhead
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_InvasiveMuch
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_WellAskNextTime
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_TeachyTVSoIShould
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_Correct
	callnative ClearMugshot
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_Swagbag_PlayerRecivedMoney
	waitmessage
	waitfanfare
	goto Swagbag_WhenCanWeStart_Dialogue
	return


Swagbag_WhenCanWeStart_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_IBelieveThatsEverything
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_YeahWhenTheTutorial
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_TheGymChallengeOfficially
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Swagbag_FineIllExploreTheCity
	closemessage
	callnative ClearMugshot
	applymovement 1, swagbag_LeaveCompound
	waitmovement 0
	playse SE_EXIT
	removeobject 1
	goto Swagbag_DontLeaveSouthbay_Dialogue
	return


Swagbag_DontLeaveSouthbay_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Swagbag_IllBeWorkingOnMyLaptop
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Swagbag_GotItThanks
	closemessage
	callnative ClearMugshot
	applymovement 2, swagbag_WalkToLaptop
	waitmovement 0
	fadedefaultbgm
	startquest QUEST_PLAYERSADVENTURE
	releaseall
	end


swagbag_HelpPlayer_Script::
	msgbox gText_Swagbag_InTheActualGame, MSGBOX_NPC
	callnative ClearMugshot
	applymovement 2, Common_Movement_FaceRight
	waitmovement 0
	return


swagbag_PreventPlayerLeavingSouthbay_Event_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_DontLeaveSouthbay_Text1
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, swagbag_WalkBackwards
	waitmovement 0
	releaseall
	end


swagbag_TurnFaceOak_Movement:
	walk_up
	face_down
	step_end

swagbag_GreetPlayer:
	face_up
	walk_up
	delay_16
	step_end

swagbag_LeaveCompound:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

swagbag_WalkToLaptop:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

swagbag_WalkBackwards:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

gText_Swagbag_WelcomeToRegion::
	.string "{PLAYER}! Welcome to SanFran! How was\n"
	.string "your flight?$"

gText_Swagbag_GreatThePrivateCar::
	.string "Great! The private car from the airport\n"
	.string "was a surprise, but everything was\l"
	.string "super smooth, thanks!$"

gText_Swagbag_ExcellentYouveAlready::
	.string "Excellent. You've already seen the\n"
	.string "house, so we can skip the tour... I have\l"
	.string "some presents!$"

gText_Swagbag_SoFirstYoullEach::
	.string "So first, you'll each be getting a\n"
	.string "stipend from the League, which should\l"
	.string "be hitting your accounts soon. That\l"
	.string "money is yours, no strings attached, so\l"
	.string "do whatever you like with it. Just don't\l"
	.string "spend it all in one place!$"

gText_Swagbag_BecauseTheBoard::
	.string "*muttering* Because the board absolutely\n"
	.string "won't let us give you any more...$"

gText_Swagbag_AlsoWeveGoneAhead::
	.string "Next, we've gone ahead and loaded the\n"
	.string "newest OS onto your phones last night.$"

gText_Swagbag_InvasiveMuch::
	.string "Invasive much?$"

gText_Swagbag_WellAskNextTime::
	.string "Ha ha, we'll ask next time. Another perk:\n"
	.string "you've also got the cutting edge\l"
	.string "versions of all the best apps...\l"
	.string "TeachyTV, FameChecker, QuestLog, and\l"
	.string "of course, the we've changed your\l"
	.string "Pokedex regions to SanFran mode.$"

gText_Swagbag_TeachyTVSoIShould::
	.string "Teachy TV... so I should use that if I\n"
	.string "have a question or get stuck?$"

gText_Swagbag_Correct::
	.string "Right! All of the other apps have\n"
	.string "tutorials, so if you press {START_BUTTON} later and\l"
	.string "select an app, it'll walk you through all\l"
	.string "of them.$"

gText_Swagbag_PlayerRecivedMoney::
	.string "{PLAYER} received ¥50000, and\n"
	.string "updated phone apps from Oak.$"

gText_Swagbag_IBelieveThatsEverything::
	.string "I believe that's everything. Questions?$"

gText_Swagbag_YeahWhenTheTutorial::
	.string "We can't start until tomorrow?$"

gText_Swagbag_TheGymChallengeOfficially::
	.string "Correct, the Gym Challenge officially\n"
	.string "starts tomorrow. I suggest you get a\l"
	.string "good night's sleep, and over breakfast,\l"
	.string "I'll explain how it all works.$"

gText_Swagbag_FineIllExploreTheCity::
	.string "...fine. I'll explore the city a bit! Maybe\n"
	.string "I'll see you around, {PLAYER}.$"

gText_Swagbag_IllBeWorkingOnMyLaptop::
	.string "{PLAYER}, I'll be working on my laptop\n"
	.string "here for the next few hours. If you've\l"
	.string "got any questions, don't be afraid to\l"
	.string "ask. It's fine if you explore, but don't\l"
	.string "leave Southbay, okay?$"

gText_Swagbag_GotItThanks::
	.string "Got it. Thanks for all the help, Oak! I'm\n"
	.string "still so stoked for the opportunity\l"
	.string "and the Challenge!$"

gText_Swagbag_InTheActualGame::
	.string "In the actual game, this will be a list of\n"
	.string "questions that the player can ask and\l"
	.string "getr answers to. Tutorial level shit.$"

gText_DontLeaveSouthbay_Text1::
	.string "I don't think I should leave Southbay\n"
	.string "yet...$"
