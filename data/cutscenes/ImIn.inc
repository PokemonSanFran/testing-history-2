ImIn_HideObject_OutsideHouse_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


ImIn_HideStairsGuard_Script::
	setflag FLAG_TEMP_1F
	return


ImIn_ShowPsftransrival_Script::
	setflag FLAG_TEMP_1F
	clearflag FLAG_TEMP_4
	addobject 9
	return


ImIn_HidePsftransrival_Script::
	setflag FLAG_TEMP_4
	return


ImIn_ResumeSave_Script::
	call ImIn_ShowPsftransrival_Script
	call ImIn_MovePsftransrival_Script
	return


ImIn_MovePsftransrival_Script::
	setobjectxy 9, 12, 26
	setobjectxyperm 9, 12, 26
	return


ImIn_DestroyWall_Script::
	setmetatile 15, 13, 0x0A7, FALSE
	special DrawWholeMapView
	return


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


ImIn_ObjectSetUp_PostWarp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	clearflag FLAG_TEMP_9
	call ImIn_HideStairsGuard_Script
	return


ImIn_CheckPlayer_Script::
	lock
	compare VAR_STORYLINE_STATE < 109, 0
	goto_if_ne ImIn_CheckPlayer_Script_2
	goto ImIn_StartHouseBreak_Script
	return

ImIn_CheckPlayer_Script_2:
	release
	end


ImIn_StartHouseBreak_Script::
	addvar VAR_MAUVILLE_CITY_STATE, 1
	fadescreen FADE_TO_BLACK
	call ImIn_CutsceneSetup_OutsideHouse_Script
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, ImIn_ApproachHouse
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement 3, Common_Movement_FaceDown
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_ImIn_WereCertainNobody
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ImIn_HasntLeftWorkEarly
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ImIn_WereInPosition
	closemessage
	callnative ClearMugshot
	applymovement 5, ImIn_WalkAroundHouse
	waitmovement 5
	applymovement 1, Common_Movement_FaceRight
	applymovement 2, Common_Movement_FaceRight
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ImIn_TheSideDoorWill
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_ImIn_LetsMoveThen
	closemessage
	callnative ClearMugshot
	applymovement 5, ImIn_WalkToSideDoor
	waitmovement 5
	call ImIn_ReleaseFromBall_Script
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ImIn_BrickBreakSureComes
	callnative ClearMugshot
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
	addvar VAR_MAUVILLE_CITY_STATE, 1
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_ImIn_OkaySpreadOut
	closemessage
	callnative ClearMugshot
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
	addvar VAR_MAUVILLE_CITY_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_IFoundADoor
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ImIn_GuessWereAllLooking
	callnative ClearMugshot
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
	addvar VAR_MAUVILLE_CITY_STATE, 1
	playse SE_DING_DONG
	waitse
	playse SE_SLIDING_DOOR
	call ImIn_UnlockDoor_Script
	delay 16
	fadescreen FADE_TO_BLACK
	call ImIn_MoveObject_BeforeWarp_Script
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_ImIn_WereIn
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ImIn_OnceYoureAllThrough
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ImIn_ImTooOldFor
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_ImIn_ThesePeopleAreFighting
	callnative ClearMugshot
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
	addvar VAR_STORYLINE_STATE, 1
	release
	end


ImIn_PostWarpSplit_Dialogue::
	lock
	addvar VAR_MAUVILLE_CITY_STATE, 1
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_ImIn_WereAllIn
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ImIn_LetTheMarch
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_ImIn_LetsGoSecure
	closemessage
	callnative ClearMugshot
	applymovement 17, ImIn_WalkAwayFromWarpB
	applymovement 16, ImIn_WalkAwayFromWarpA
	waitmovement 16
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_ImIn_ThisPlaceIsProbably
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_HasAnOfficeOn
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_ImIn_FloorThenLets
	closemessage
	callnative ClearMugshot
	applymovement 15, ImIn_WalkAwayFromWarpC
	applymovement 18, ImIn_WalkAwayFromWarpD
	applymovement 19, ImIn_WalkAwayFromWarpE
	waitmovement 18
	removeobject 15
	removeobject 16
	removeobject 17
	removeobject 18
	removeobject 19
	release
	end


ImIn_PreventPlayerProgress_Script::
	compare VAR_MAUVILLE_CITY_STATE, 6
	goto_if_gt ImIn_PreventPlayerProgress_Script_2
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_OfficeIsOn
	callnative ClearMugshot
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
	addvar VAR_MAUVILLE_CITY_STATE, 1
	playbgm MUS_ENCOUNTER_MAY, TRUE
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_DoYouLikeMy
	closemessage
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, ImIn_ApproachDesk
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_WhatAreYouDoing
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_IDidntChooseToAlign
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_WaitTrash
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_WasDestryogingThisRegion
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_SoYouJustDontCare
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_LookAllThisHelping
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_DaddyWontBeAble
	closemessage
	callnative ClearMugshot
	applymovement 9, ImIn_WalkFromDesk
	waitmovement 9
	call Common_EventScript_SaveGame
	closemessage
	goto ImIn_StartPsftransrivalBattle_Script
	return


ImIn_StartPsftransrivalBattle_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_AreDeadDoYou
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, gText_ImIn_HowDoesThisKeep
	goto ImIn_PsftransrivalDefeated_Dialogue
	return


ImIn_InteractPsftransrivalBattle_Script::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_DaddyWontBeAble, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, gText_ImIn_HowDoesThisKeep
	goto ImIn_PsftransrivalDefeated_Dialogue
	return


ImIn_PsftransrivalDefeated_Dialogue::
	lock
	addvar VAR_MAUVILLE_CITY_STATE, 1
	call ImIn_MovePsftransrival_Script
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_Wheres
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_WhatsTheSecret
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ImIn_EverythingAboutIsBullshit
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_Floor
	callnative ClearMugshot
	closemessage
	release
	end


ImIn_PostPsftransrivalBattle_Interact_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ImIn_AllThatTraining, MSGBOX_NPC
	callnative ClearMugshot
	return


ImIn_InteractPsftransrival_Event_Script::
	lock
	switch VAR_MAUVILLE_CITY_STATE
	case 6, ImIn_InteractPsftransrival_Event_Script_3
	call ImIn_PostPsftransrivalBattle_Interact_Dialogue
ImIn_InteractPsftransrival_Event_Script_1:
	closemessage
	release
	end

ImIn_InteractPsftransrival_Event_Script_3:
	call ImIn_InteractPsftransrivalBattle_Script
	goto ImIn_InteractPsftransrival_Event_Script_1


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
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkAwayFromWarpB:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

ImIn_WalkAwayFromWarpC:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
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

ImIn_ApproachDesk:
	walk_right
	walk_right
	walk_right
	step_end

ImIn_WalkFromDesk:
	walk_down
	walk_left
	walk_left
	step_end

ImIn_InteractDoor_Script_Text_0:
	.string "Find the thing to unlock this door!$"

gText_ImIn_WereCertainNobody::
	.string "We're certain nobody is home?$"

gText_ImIn_HasntLeftWorkEarly::
	.string "Psfbadadmin3 hasn't left work early a\n"
	.string "day in their life. Psfbadguy is led by\l"
	.string "monsters, but at least they're\l"
	.string "hard-working monsters.$"

gText_ImIn_WereInPosition::
	.string "We're in position at Psfcity12. Ready to\n"
	.string "mobilize this diversion when you are.$"

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
	.string "Psfgoodadmin, we're in. Everybody\n"
	.string "remember the plan?$"

gText_ImIn_OnceYoureAllThrough::
	.string "Once you're all through the panel, I'll\n"
	.string "lead the diversion protest at the\l"
	.string "front doors of the tower. Security will\l"
	.string "be focused on us, letting you to the\l"
	.string "executive levels and hopefully find\l"
	.string "Psfbadboss.$"

gText_ImIn_ImTooOldFor::
	.string "I'm too old for scaling mountains.\n"
	.string "Psfelite3 and I can get into the\l"
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
	.string "Psfelite2, let's go secure the studio.$"

gText_ImIn_ThisPlaceIsProbably::
	.string "This place is probably crawling with\n"
	.string "Trainers. Let's spread out.$"

gText_ImIn_HasAnOfficeOn::
	.string "Psfbadboss has an office on the 10th\n"
	.string "floor, I've been there myself.$"

gText_ImIn_FloorThenLets::
	.string "10th floor then, let's move!$"

gText_ImIn_OfficeIsOn::
	.string "Psfbadboss's office is on Floor 10.$"

gText_ImIn_DoYouLikeMy::
	.string "Do you like my new office?$"

gText_ImIn_WhatAreYouDoing::
	.string "Psftransrival, what are you doing here?$"

gText_ImIn_IDidntChooseToAlign::
	.string "I didn't choose to align myself with the\n"
	.string "ghetto trash. Turns out, if you stick\l"
	.string "with the good guys, you get a sick job\l"
	.string "and a corner office.$"

gText_ImIn_WaitTrash::
	.string "Wait, trash? Did you hear what these\n"
	.string "people did to Psfcity17?$"

gText_ImIn_WasDestryogingThisRegion::
	.string "Psfgoodteam was destroying this region\n"
	.string "with their idiocy. We wiped ‘em out. And\l"
	.string "you decided to help them? After\l"
	.string "everything Psfbadguy did for you?$"

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
	.string "If you and Psfnativerival are dead, do\n"
	.string "you think I get to be Champion\l"
	.string "instead?$"

gText_ImIn_HowDoesThisKeep::
	.string "How does this keep happening?!?!?$"

gText_ImIn_Wheres::
	.string "Where's Psfbadboss?!$"

gText_ImIn_WhatsTheSecret::
	.string "What's the secret? What am I missing?\n"
	.string "Why do I keep LOSING?$"

gText_ImIn_EverythingAboutIsBullshit::
	.string "Everything about Psfbadguy is bullshit.\n"
	.string "You're not any stronger. The region\l"
	.string "isn't any better. But as long as they\l"
	.string "have stans like you, they're going to\l"
	.string "continue to get richer and more toxic.\l"
	.string "Tell me where Psfbadboss is.$"

gText_ImIn_Floor::
	.string "Floor 11.$"

gText_ImIn_AllThatTraining::
	.string "…all that training…$"
