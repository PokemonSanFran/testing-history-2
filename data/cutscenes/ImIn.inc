ImIn_HideObject_OutsideHouse_Script::
	setflag FLAG_TEMP_2
	compare VAR_STORYLINE_STATE, STORY_BEFORE_SABRINA_BREAKIN
	goto_if_ne ImIn_HideObject_OutsideHouse_Script_1
	compare VAR_TOWER_RAID_STATE, 0
	goto_if_ne ImIn_HideObject_OutsideHouse_Script_1
	return

ImIn_HideObject_OutsideHouse_Script_1:
	setflag FLAG_TEMP_1
	return


ImIn_PreBianca_Object_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setobjectxy 4, 6, 56
	setobjectxyperm 4, 6, 56
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	return


ImIn_SaveBianca_Object_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setobjectxy 4, 7, 53
	setobjectxyperm 4, 7, 53
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	return


ImIn_RevealRoseWarp_Script::
	compare VAR_TOWER_RAID_STATE, SAVE_BIANCA_SALESFORCETOWER
	goto_if_gt ImIn_RevealRoseWarp_Script_2
ImIn_RevealRoseWarp_Script_1:
	return

ImIn_RevealRoseWarp_Script_2:
	setmetatile 10, 55, 0x2DF, FALSE
	special DrawWholeMapView
	goto ImIn_RevealRoseWarp_Script_1


ImIn_DestroyWall_Script::
	compare VAR_TOWER_RAID_STATE, 0
	goto_if_ne ImIn_DestroyWall_Script_2
ImIn_DestroyWall_Script_1:
	return

ImIn_DestroyWall_Script_2:
	setmetatile 15, 13, 0x0A7, FALSE
	special DrawWholeMapView
	goto ImIn_DestroyWall_Script_1


ImIn_CutsceneSetup_OutsideHouse_Script::
	clearflag FLAG_TEMP_1
	addobject 1
	addobject 2
	addobject 3
	addobject 4
	addobject 5
	return


ImIn_ReleaseFromBall_Script::
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_TEMP_2
	addobject 6
	playmoncry SPECIES_MACHAMP, CRY_MODE_ENCOUNTER
	waitmoncry
	return


ImIn_ObjectSetUp_InsideHouse_Script::
	setobjectxyperm 1, 15, 4
	setobjectxyperm 2, 16, 3
	setobjectxyperm 3, 17, 4
	setobjectxyperm 4, 18, 5
	setobjectxyperm 5, 19, 3
	return


ImIn_MoveObject_BeforeWarp_Script::
	addobject 1
	addobject 2
	addobject 3
	addobject 4
	addobject 5
	setobjectxy 1, 10, 3
	setobjectxy 3, 10, 4
	setobjectxy 4, 12, 3
	setobjectxy 5, 12, 4
	setobjectxy 2, 11, 2
	setobjectxy OBJ_EVENT_ID_PLAYER, 11, 4
	TeleportCamera 11, 4
	applymovement 1, Common_Movement_FaceRight
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceLeft
	applymovement 2, Common_Movement_FaceDown
	applymovement 5, Common_Movement_FaceLeft
	waitmovement 2
	return


ImIn_CheckPlayer_Script::
	lock
	compare VAR_STORYLINE_STATE, STORY_BEFORE_SABRINA_BREAKIN
	goto_if_ne ImIn_CheckPlayer_Script_2
	goto ImIn_StartHouseBreak_Script
	return

ImIn_CheckPlayer_Script_2:
	release
	end


ImIn_StartHouseBreak_Script::
	setvar VAR_TOWER_RAID_STATE, BROKEN_IN_SABRINA
	fadescreen FADE_TO_BLACK
	call ImIn_CutsceneSetup_OutsideHouse_Script
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, ImIn_ApproachHouse
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 3, Common_Movement_FaceDown
	msgbox gText_ImIn_WereCertainNobody, , SPEAKER_SIEBOLD
	msgbox gText_ImIn_HasntLeftWorkEarly, , SPEAKER_DRASNA
	msgbox gText_ImIn_WereInPosition, , SPEAKER_ARIANA, , , PHONE_ON
	closemessage
	applymovement 5, ImIn_WalkAroundHouse
	waitmovement 5
	applymovement 1, Common_Movement_FaceRight
	applymovement 2, Common_Movement_FaceRight
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_ImIn_TheSideDoorWill, , SPEAKER_ARCHER
	msgbox gText_ImIn_LetsMoveThen, , SPEAKER_MALVA
	closemessage
	applymovement 5, ImIn_WalkToSideDoor
	waitmovement 5
	call ImIn_ReleaseFromBall_Script
	msgbox gText_ImIn_BrickBreakSureComes, , SPEAKER_ARCHER
	closemessage
	playse SE_M_BRICK_BREAK
	applymovement 6, ImIn_AttackHouse
	waitse
	waitmovement 6
	call ImIn_DestroyWall_Script
	applymovement 6, ImIn_WalkIntoHouseA
	applymovement 1, ImIn_WalkIntoHouseB
	applymovement 2, ImIn_WalkIntoHouseC
	applymovement 3, ImIn_WalkIntoHouseD
	applymovement 4, ImIn_WalkIntoHouseE
	applymovement 5, ImIn_WalkIntoHouseF
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	waitse
	waitmovement 1
	removeobject 6
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	release
	end


ImIn_UnlockDoor_Script::
	setmetatile 11, 6, 0x228, FALSE
	special DrawWholeMapView
	return


Imin_BeginHouseSearch_Script::
	lock
	setvar VAR_TOWER_RAID_STATE, SEARCHING_SABRINA_HOUSE
	msgbox gText_ImIn_OkaySpreadOut, , SPEAKER_MALVA
	closemessage
	applymovement 1, ImIn_SpreadOutHouse
	applymovement 2, ImIn_SpreadOutHouse
	applymovement 3, ImIn_SpreadOutHouse
	applymovement 4, ImIn_SpreadOutHouse
	applymovement 5, ImIn_SpreadOutHouse
	waitmovement 5
	setobjectxy 1, 2, 7
	setobjectxy 2, 18, 9
	setobjectxy 3, 10, 11
	setobjectxy 4, 15, 17
	setobjectxy 5, 3, 13
	setobjectxyperm 1, 2, 7
	setobjectxyperm 2, 18, 9
	setobjectxyperm 3, 10, 11
	setobjectxyperm 4, 15, 17
	setobjectxyperm 5, 3, 13
	release
	end


ImIn_FindLockedDoor_Script::
	lock
	setvar VAR_TOWER_RAID_STATE, FOUND_SABRINA_WARP_DOOR
	msgbox gText_ImIn_IFoundADoor, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_GuessWereAllLooking, , SPEAKER_ARCHER
	closemessage
	release
	end


ImIn_InteractDoor_Script::
	checkitem ITEM_MAGMA_EMBLEM
	compare VAR_RESULT, 0
	goto_if_ne ImIn_InteractDoor_Script_2
ImIn_InteractDoor_Script_1:
	msgbox ImIn_InteractDoor_Script_Text_0, MSGBOX_AUTOCLOSE
	return

ImIn_InteractDoor_Script_2:
	goto ImIn_EnterCorrectCode_Script
	goto ImIn_InteractDoor_Script_1


ImIn_EnterCorrectCode_Script::
	lock
	setvar VAR_TOWER_RAID_STATE, SABRINA_WARP_DOOR_UNLOCKED
	playse SE_DING_DONG
	waitse
	playse SE_SLIDING_DOOR
	call ImIn_UnlockDoor_Script
	delay 16
	fadescreen FADE_TO_BLACK
	call ImIn_MoveObject_BeforeWarp_Script
	fadescreen FADE_FROM_BLACK
	msgbox gText_ImIn_WereIn, , SPEAKER_SIEBOLD
	msgbox gText_ImIn_OnceYoureAllThrough, , SPEAKER_ARIANA, , , PHONE_ON
	msgbox gText_ImIn_ImTooOldFor, , SPEAKER_DRASNA
	msgbox gText_ImIn_ThesePeopleAreFighting, , SPEAKER_KAREN
	closemessage
	applymovement 1, Common_Movement_WalkRight
	waitmovement 1
	removeobject 1
	playse SE_WARP_OUT
	applymovement 3, ImIn_WalkToWarpFromLeft
	waitmovement 3
	removeobject 3
	playse SE_WARP_OUT
	applymovement 4, Common_Movement_WalkLeft
	waitmovement 4
	removeobject 4
	playse SE_WARP_OUT
	applymovement 2, Common_Movement_WalkDown
	waitmovement 2
	removeobject 2
	playse SE_WARP_OUT
	applymovement 5, ImIn_WalkToWarpFromRight
	waitmovement 5
	removeobject 5
	playse SE_WARP_OUT
	setvar VAR_STORYLINE_STATE, STORY_WARP_TILE_ACCESSIBLE
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, TRUE_RAID_START
	release
	end


ImIn_MakeRaidPartyVisible_Script::
	compare VAR_TOWER_RAID_STATE, SABRINA_WARP_DOOR_UNLOCKED
	goto_if_ne ImIn_MakeRaidPartyVisible_Script_1
	return

ImIn_MakeRaidPartyVisible_Script_1:
	setflag FLAG_TEMP_2
	return


ImIn_PostWarpSplit_Dialogue::
	lock
	setvar VAR_TOWER_RAID_STATE, TEAM_ENTERED_SALESFORCETOWER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp2
	msgbox gText_ImIn_WereAllIn, , SPEAKER_SIEBOLD
	msgbox gText_ImIn_LetTheMarch, , SPEAKER_ARIANA, , , PHONE_ON
	msgbox gText_ImIn_LetsGoSecure, , SPEAKER_SIEBOLD
	closemessage
	applymovement 5, ImIn_WalkAwayFromWarpA
	applymovement 4, ImIn_WalkAwayFromWarpA
	msgbox gText_ImIn_ThisPlaceIsProbably, , SPEAKER_KAREN
	msgbox gText_ImIn_HasAnOfficeOn, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_FloorThenLets, , SPEAKER_MALVA
	closemessage
	applymovement 3, ImIn_WalkAwayFromWarpC
	applymovement 6, ImIn_WalkAwayFromWarpC
	applymovement 7, ImIn_WalkAwayFromWarpC
	delay 30
	fadescreen FADE_TO_BLACK
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	fadescreen FADE_FROM_BLACK
	release
	end


ImIn_PreventPlayerProgress_Script::
	compare VAR_TOWER_RAID_STATE, SAVE_BIANCA_SALESFORCETOWER
	goto_if_gt ImIn_PreventPlayerProgress_Script_2
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_ImIn_OfficeIsOn, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, ImIn_WalkAwayStairs
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

ImIn_PreventPlayerProgress_Script_2:
	release
	end


ImIn_OfficeReveal_Dialogue::
	lock
	setvar VAR_TOWER_RAID_STATE, SAVE_BIANCA_SALESFORCETOWER
	playbgm MUS_ENCOUNTER_MAY, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, ImIn_ApproachDesk_Movement
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_ImIn_DoYouLikeMy, , SPEAKER_BIANCA
	closemessage
	msgbox gText_ImIn_WhatAreYouDoing, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_IDidntChooseToAlign, , SPEAKER_BIANCA
	msgbox gText_ImIn_WaitTrash, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_WasDestryogingThisRegion, , SPEAKER_BIANCA
	msgbox gText_ImIn_SoYouJustDontCare, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_LookAllThisHelping, , SPEAKER_BIANCA
	msgbox gText_ImIn_DaddyWontBeAble, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	applymovement 4, ImIn_WalkFromDesk_Movement
	waitmovement 4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	call Common_EventScript_SaveGame
	closemessage
	goto ImIn_StartBiancaBattle_Script
	return


ImIn_StartBiancaBattle_Script::
	lock
	msgbox gText_ImIn_AreDeadDoYou, , SPEAKER_BIANCA
	closemessage
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, gText_ImIn_HowDoesThisKeep
	goto ImIn_BiancaDefeated_Dialogue
	return


ImIn_InteractBiancaBattle_Script::
	compare VAR_TOWER_RAID_STATE, SAVE_BIANCA_SALESFORCETOWER
	goto_if_eq ImIn_InteractBiancaBattle_Script_2
ImIn_InteractBiancaBattle_Script_1:
	return

ImIn_InteractBiancaBattle_Script_2:
	playbgm MUS_ENCOUNTER_MAY, TRUE
	goto ImIn_StartBiancaBattle_Script
	goto ImIn_InteractBiancaBattle_Script_1


ImIn_BiancaDefeated_Dialogue::
	lock
	setvar VAR_TOWER_RAID_STATE, DEFEATED_BIANCA_SALESFORCETOWER
	msgbox gText_ImIn_Wheres, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_WhatsTheSecret, , SPEAKER_BIANCA
	msgbox gText_ImIn_EverythingAboutIsBullshit, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_ImIn_Floor, , SPEAKER_BIANCA
	call ImIn_RevealRoseWarp_Script
	closemessage
	release
	end


ImIn_PostBiancaBattle_Interact_Dialogue::
	compare VAR_TOWER_RAID_STATE, DEFEATED_BIANCA_SALESFORCETOWER
	goto_if_eq ImIn_PostBiancaBattle_Interact_Dialogue_2
ImIn_PostBiancaBattle_Interact_Dialogue_1:
	return

ImIn_PostBiancaBattle_Interact_Dialogue_2:
	msgbox gText_ImIn_AllThatTraining, MSGBOX_NPC, SPEAKER_BIANCA
	goto ImIn_PostBiancaBattle_Interact_Dialogue_1


ImIn_InteractBianca_Event_Script::
	lock
	switch VAR_TOWER_RAID_STATE
	case SAVE_BIANCA_SALESFORCETOWER, ImIn_InteractBianca_Event_Script_3
	call ImIn_PostBiancaBattle_Interact_Dialogue
ImIn_InteractBianca_Event_Script_1:
	closemessage
	release
	end

ImIn_InteractBianca_Event_Script_3:
	call ImIn_InteractBiancaBattle_Script
	goto ImIn_InteractBianca_Event_Script_1


ImIn_ApproachHouse:
	walk_up
	step_end

ImIn_WalkAroundHouse:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkToSideDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

ImIn_AttackHouse:
	lock_facing_direction
	walk_left
	walk_right
	step_end

ImIn_WalkIntoHouseA:
	walk_left
	step_end

ImIn_WalkIntoHouseB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

ImIn_WalkIntoHouseC:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

ImIn_WalkIntoHouseD:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

ImIn_WalkIntoHouseE:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

ImIn_WalkIntoHouseF:
	walk_down
	walk_left
	step_end

ImIn_SpreadOutHouse:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkToWarpFromLeft:
	walk_up
	walk_right
	step_end

ImIn_WalkToWarpFromRight:
	walk_up
	walk_left
	step_end

ImIn_WalkAwayFromWarpA:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

ImIn_WalkAwayFromWarpB:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkAwayFromWarpC:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

ImIn_WalkAwayFromWarpD:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkAwayFromWarpE:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkAwayStairs:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

ImIn_ApproachDesk_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkFromDesk_Movement:
	walk_right
	walk_up
	walk_up
	walk_up
	face_left
	step_end

ImIn_InteractDoor_Script_Text_0:
	.string "Find the thing to unlock this door!$"

gText_ImIn_WereCertainNobody::
	.string "We're certain nobody is home?$"

gText_ImIn_HasntLeftWorkEarly::
	.string "Sabrina hasn't left work early a day in\n"
	.string "their life. Ycombinator is led by\l"
	.string "monsters, but at least they're\l"
	.string "hard-working monsters.$"

gText_ImIn_WereInPosition::
	.string "We're in position at Tenderloin. Ready\n"
	.string "to mobilize this diversion when you are.$"

gText_ImIn_TheSideDoorWill::
	.string "The side door will definitely work,\n"
	.string "didn't see an alarm either.$"

gText_ImIn_LetsMoveThen::
	.string "Let's move then!$"

gText_ImIn_BrickBreakSureComes::
	.string "Brick Break sure comes in handy when\n"
	.string "most houses are made of the stuff.$"

gText_ImIn_OkaySpreadOut::
	.string "Okay, spread out. We're looking for the\n"
	.string "warp panel. Use the walkies if you see\l"
	.string "anything.$"

gText_ImIn_IFoundADoor::
	.string "I found a door with an electronic lock!\n"
	.string "It takes six digits.$"

gText_ImIn_GuessWereAllLooking::
	.string "Guess we're all looking for any numbers\n"
	.string "that seem important. No way it's just\l"
	.string "their birthday, right?$"

gText_ImIn_WereIn::
	.string "Ariana, we're in. Everybody remember the\n"
	.string "plan?$"

gText_ImIn_OnceYoureAllThrough::
	.string "Once you're all through the panel, I'll\n"
	.string "lead the diversion protest at the\l"
	.string "front doors of the tower. Security will\l"
	.string "be focused on us, letting you to the\l"
	.string "executive levels and hopefully find\l"
	.string "Rose.$"

gText_ImIn_ImTooOldFor::
	.string "I'm too old for scaling mountains.\n"
	.string "Siebold and I can get into the\l"
	.string "production studio and get ready to\l"
	.string "broadcast that confession.$"

gText_ImIn_ThesePeopleAreFighting::
	.string "These people are fighting to kill. Stay\n"
	.string "safe.$"

gText_ImIn_WereAllIn::
	.string "We're all in.$"

gText_ImIn_LetTheMarch::
	.string "Let the march begin… good luck!$"

gText_ImIn_LetsGoSecure::
	.string "Drasna, let's go secure the studio.$"

gText_ImIn_ThisPlaceIsProbably::
	.string "This place is probably crawling with\n"
	.string "Trainers. Let's spread out.$"

gText_ImIn_HasAnOfficeOn::
	.string "Rose has an office on the 10th floor,\n"
	.string "I've been there myself.$"

gText_ImIn_FloorThenLets::
	.string "10th floor then, let's move!$"

gText_ImIn_OfficeIsOn::
	.string "Rose's office is on Floor 10.$"

gText_ImIn_DoYouLikeMy::
	.string "Do you like my new office?$"

gText_ImIn_WhatAreYouDoing::
	.string "Bianca, what are you doing here?$"

gText_ImIn_IDidntChooseToAlign::
	.string "I didn't choose to align myself with the\n"
	.string "ghetto trash. Turns out, if you stick\l"
	.string "with the good guys, you get a sick job\l"
	.string "and a corner office.$"

gText_ImIn_WaitTrash::
	.string "Wait, trash? Did you hear what these\n"
	.string "people did to Alameda?$"

gText_ImIn_WasDestryogingThisRegion::
	.string "TeamRocket was destroying this region\n"
	.string "with their idiocy. We wiped ‘em out. And\l"
	.string "you decided to help them? After\l"
	.string "everything Ycombinator did for you?$"

gText_ImIn_SoYouJustDontCare::
	.string "So you just don't care that you work\n"
	.string "for murderers?$"

gText_ImIn_LookAllThisHelping::
	.string "Look, all this helping people shit is\n"
	.string "cool, but I came here to be the best.\l"
	.string "I'm done losing to scrubs and I'm done\l"
	.string "pretending to care.$"

gText_ImIn_DaddyWontBeAble::
	.string "Daddy won't be able to buy your way out\n"
	.string "of this one.$"

gText_ImIn_AreDeadDoYou::
	.string "If you and Archer are dead, do you think\n"
	.string "I get to be Champion instead?$"

gText_ImIn_HowDoesThisKeep::
	.string "How does this keep happening?!?!?$"

gText_ImIn_Wheres::
	.string "Where's Rose?!$"

gText_ImIn_WhatsTheSecret::
	.string "What's the secret? What am I missing?\n"
	.string "Why do I keep LOSING?$"

gText_ImIn_EverythingAboutIsBullshit::
	.string "Everything about Ycombinator is\n"
	.string "bullshit. You're not any stronger. The\l"
	.string "region isn't any better. But as long as\l"
	.string "they have stans like you, they're going\l"
	.string "to continue to get richer and more\l"
	.string "toxic. Tell me where Rose is.$"

gText_ImIn_Floor::
	.string "Floor 11.$"

gText_ImIn_AllThatTraining::
	.string "…all that training…$"
