WarehouseRave_SetUpRave_Script::
	setweather WEATHER_FOG_DIAGONAL
	doweather
	playbgm MUS_RG_GAME_CORNER, TRUE
	return


WarehouseRave_HideObject_Script::
	compare VAR_WAREHOUSE_RAVE_STATE, DEFEATED_KOGA_OAKLAND
	goto_if_ne WarehouseRave_HideObject_Script_1
	return

WarehouseRave_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return


WarehouseRave_MoveObject_Script::
	setobjectxy 1, 5, 5
	setobjectxyperm 1, 5, 5
	return


WarehouseRave_ControlExits_Script::
	switch VAR_WAREHOUSE_RAVE_STATE
	case SAVE_KOGA_OAKLAND, WarehouseRave_ControlExits_Script_2
	case DEFEATED_KOGA_OAKLAND, WarehouseRave_ControlExits_Script_3
	case TOLD_ARCHER_ABOUT_KOGA, WarehouseRave_ControlExits_Script_4
	return

WarehouseRave_ControlExits_Script_2:
	call WarehouseRave_PostSaveUnlock
	return

WarehouseRave_ControlExits_Script_3:
	call WarehouseRave_MakeExplosionHole_Script
	return

WarehouseRave_ControlExits_Script_4:
	call WarehouseRave_MakeExplosionHole_Script
	return


WarehouseRave_PostSaveUnlock::
	setmetatile 9, 6, 0x208, FALSE
	setmetatile 9, 7, 0x210, FALSE
	setmetatile 9, 8, 0x218, FALSE
	special DrawWholeMapView
	checktrainerflag TRAINER_TABITHA_MT_CHIMNEY
	goto_if 1, WarehouseRave_PostSaveUnlock_1
	return

WarehouseRave_PostSaveUnlock_1:
	call WarehouseRave_MakeExplosionHole_Script
	return


WarehouseRave_MakeExplosionHole_Script::
	setmetatile 9, 1, 0x09F, FALSE
	setmetatile 9, 2, 0x0A7, FALSE
	special DrawWholeMapView
	return


WarehouseRave_LockDoors_Script::
	setmetatile 9, 6, 0x214, FALSE
	setmetatile 9, 7, 0x214, FALSE
	setmetatile 9, 8, 0x214, FALSE
	special DrawWholeMapView
	playse SE_SLIDING_DOOR
	waitse
	return


WarehouseRave_Intro_Dialogue::
	lock
	msgbox gText_WarehouseRave_IsThisPlace, , SPEAKER_ZOEY
	closemessage
	call WarehouseRave_LockDoors_Script
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_WarehouseRave_WhatTheHell, , SPEAKER_ZOEY
	closemessage
	clearflag FLAG_TEMP_1
	addobject 1
	applymovement 1, WarehouseRave_WalkOutShadows
	waitmovement 0
	msgbox gText_WarehouseRave_ImSorryWeHad, , SPEAKER_KOGA
	msgbox gText_WarehouseRave_WhyAmITrapped, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_HasBeenPredicting, , SPEAKER_KOGA
	msgbox gText_WarehouseRave_SoIDecideTo, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_HasInstructed, , SPEAKER_KOGA
	closemessage
	setvar VAR_WAREHOUSE_RAVE_STATE, SAVE_KOGA_OAKLAND
	applymovement OBJ_EVENT_ID_PLAYER, WarehouseRave_WalkToBattle
	waitmovement 0
	call Common_EventScript_SaveGame
	goto WarehouseRave_Battle_Script
	return


Warehourse_Interact_Script::
	faceplayer
	call WarehouseRave_LockDoors_Script
	goto WarehouseRave_Battle_Script
	return


WarehouseRave_Battle_Script::
	lock
	msgbox gText_WarehouseRave_PrepareToFight, , SPEAKER_KOGA
	trainerbattle_no_intro TRAINER_TABITHA_MT_CHIMNEY, gText_WarehouseRave_YesTheyllBelieve
	closemessage
	goto WarehouseRave_PostBattle_Script
	return


WarehouseRave_PostBattle_Script::
	lock
	setvar VAR_WAREHOUSE_RAVE_STATE, DEFEATED_KOGA_OAKLAND
	msgbox gText_WarehouseRave_IFailedToKill, , SPEAKER_KOGA
	msgbox gText_WarehouseRave_JustLike, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_YouNeedToGet, , SPEAKER_KOGA
	msgbox gText_WarehouseRave_WaitWhyAreYou, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_Now, , SPEAKER_KOGA
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WarehouseRave_RunOutTheWarehouse
	waitmovement 0
	warpsilent MAP_OAKLAND, 1
	return


WarehouseRave_OutsideWarehouse_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, WarehouseRave_ExitWarehouse
	waitmovement 0
	playse SE_PIN
	waitse
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, WarehouseRave_RunToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox gText_WarehouseRave_WhenIGotHere, , SPEAKER_ARCHER
	msgbox gText_WarehouseRave_ItWasATrap, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_HolyShitThatWas, , SPEAKER_ARCHER
	msgbox gText_WarehouseRave_TheBattleFelt, , SPEAKER_ZOEY
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_WarehouseRave_AndThenHeToldMe, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_ThatDoesntMake, , SPEAKER_ARCHER
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_WarehouseRave_WhatDoYouMean, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_CameToTown, , SPEAKER_ARCHER
	msgbox gText_WarehouseRave_MaybeItIsGuilt, , SPEAKER_ZOEY
	msgbox gText_WarehouseRave_WhateverImGlad, , SPEAKER_ARCHER
	compare VAR_STORYLINE_STATE, STORY_RECIVED_RAVE_INVITE
	goto_if_ne WarehouseRave_OutsideWarehouse_Dialogue_2
	msgbox gText_WarehouseRave_GladYouDidnt
WarehouseRave_OutsideWarehouse_Dialogue_1:
	closemessage
	applymovement 1, WarehouseRave_LeaveCity
	waitmovement 0
	removeobject 1
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_WAREHOUSE_RAVE_STATE, TOLD_ARCHER_ABOUT_KOGA
	end

WarehouseRave_OutsideWarehouse_Dialogue_2:
	msgbox gText_WarehouseRave_ImHeadingIntoTheCity
	msgbox gText_WarehouseRave_IllSeeYou
	goto WarehouseRave_OutsideWarehouse_Dialogue_1


WarehouseRave_WalkOutShadows:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WarehouseRave_WalkToBattle:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

WarehouseRave_RunOutTheWarehouse:
	player_run_right
	player_run_right
	player_run_right
	player_run_up
	player_run_up
	player_run_up
	step_end

WarehouseRave_ExitWarehouse:
	face_up
	step_end

WarehouseRave_RunToPlayer:
	player_run_up
	player_run_up
	player_run_up
	player_run_up
	player_run_up
	player_run_up
	walk_left
	step_end

WarehouseRave_LeaveCity:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_WarehouseRave_IsThisPlace::
	.string "…is this place empty?$"

gText_WarehouseRave_WhatTheHell::
	.string "What the hell is going on?!$"

gText_WarehouseRave_ImSorryWeHad::
	.string "I'm sorry we had to trick you,\n"
	.string "{PLAYER}.$"

gText_WarehouseRave_WhyAmITrapped::
	.string "Why am I trapped here?!$"

gText_WarehouseRave_HasBeenPredicting::
	.string "Ycombinator has been predicting this\n"
	.string "for a while now, unfortunately. We've\l"
	.string "always had a few plans in case your\l"
	.string "empathy became unmanageable.$"

gText_WarehouseRave_SoIDecideTo::
	.string "So I decide to help people and you trap\n"
	.string "me in a warehouse?$"

gText_WarehouseRave_HasInstructed::
	.string "Ycombinator has instructed me to\n"
	.string "neutralize this new threat.$"

gText_WarehouseRave_PrepareToFight::
	.string "Prepare to fight for your life!$"

gText_WarehouseRave_YesTheyllBelieve::
	.string "Yes… they'll believe I was overpowered\n"
	.string "by the Champion…$"

gText_WarehouseRave_IFailedToKill::
	.string "I failed to kill you, but you're about to\n"
	.string "become internal enemy number one. If I\l"
	.string "were you, I wouldn't go back to the\l"
	.string "Presidio Compound.$"

gText_WarehouseRave_JustLike::
	.string "(Just like Archer said.)$"

gText_WarehouseRave_YouNeedToGet::
	.string "You need to get out of here before I\n"
	.string "report the results.$"

gText_WarehouseRave_WaitWhyAreYou::
	.string "Wait, why are you helping me?$"

gText_WarehouseRave_Now::
	.string "Now!$"

gText_WarehouseRave_WhenIGotHere::
	.string "When I got here the front door was\n"
	.string "locked, and then the side blew open!\l"
	.string "What the hell happened?$"

gText_WarehouseRave_ItWasATrap::
	.string "It was a trap. Koga tried to kill me!\n"
	.string "But…$"

gText_WarehouseRave_HolyShitThatWas::
	.string "Holy shit that was fast! An attempt on\n"
	.string "your LIFE? Ycombinator is out of\l"
	.string "control.$"

gText_WarehouseRave_TheBattleFelt::
	.string "The battle felt like they were trying to\n"
	.string "lose.$"

gText_WarehouseRave_AndThenHeToldMe::
	.string "And then he told me to get out of here.\n"
	.string "He didn't call for backup or anything.$"

gText_WarehouseRave_ThatDoesntMake::
	.string "That doesn't make any sense. You think\n"
	.string "that creep regrets selling us out?$"

gText_WarehouseRave_WhatDoYouMean::
	.string "What do you mean?$"

gText_WarehouseRave_CameToTown::
	.string "He's like Pryce - once Ycombinator came\n"
	.string "to town, he jumped ship. He was playing\l"
	.string "both sides for a while, both working on\l"
	.string "Ycombinator's board and running the\l"
	.string "Gym in Chinatown.$"

gText_WarehouseRave_MaybeItIsGuilt::
	.string "Maybe it is guilt. So weird.$"

gText_WarehouseRave_WhateverImGlad::
	.string "Whatever. I'm glad you're okay, even if\n"
	.string "the reasoning is weird.$"

gText_WarehouseRave_ImHeadingIntoTheCity::
	.string "I'm heading into the city to start to\n"
	.string "get to work on our assignments. I'm so\l"
	.string "psyched about finally starting to chip\l"
	.string "away at these assholes, you know?$"

gText_WarehouseRave_GladYouDidnt::
	.string "Glad you didn't need me though! Damn,\n"
	.string "fighting the top brass now, you're still\l"
	.string "getting stronger. I'll see you at\l"
	.string "Alcatraz.$"

gText_WarehouseRave_IllSeeYou::
	.string "I'll see you around.$"
