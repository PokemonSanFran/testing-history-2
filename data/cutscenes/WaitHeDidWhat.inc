WaitHeDidWhat_HideObject_Script::
	setflag FLAG_TEMP_1
	return


WaitHeDidWhat_ObjectSetUp_Script::
	call Finals_HideObject_Script
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_6
	setobjectxy 3, 10, 5
	setobjectxyperm 3, 10, 5
	return


WaitHeDidWhat_ObjectMidSetUp_Script::
	call Finals_HideObject_Script
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_6
	return


WaitHeDidWhat_MeltdownSetUp_Script::
	call Finals_HideObject_Script
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_3
	setobjectxy 2, 2, 7
	setobjectxyperm 2, 2, 7
	setobjectmovementtype 2, MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP
	return


WaitHeDidWhat_MeltdownPostSaveSetUp_Script::
	setobjectxyperm 5, 11, 2
	setobjectxy 5, 11, 2
	call Finals_HideObject_Script
	setflag FLAG_TEMP_3
	setobjectxy 2, 2, 7
	setobjectxyperm 2, 2, 7
	setobjectmovementtype 2, MOVEMENT_TYPE_WALK_SEQUENCE_RIGHT_LEFT_DOWN_UP
	setflag FLAG_TEMP_6
	return


WaitHeDidWhat_MovePlayerPostSave_Script::
	setobjectxy OBJ_EVENT_ID_PLAYER, 4, 6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	TeleportCamera 4, 6
	return


WaitHeDidWhat_RivalsGoToMatch_Script::
	lock
	applymovement 5, WaitHeDidWhat_StepAside
	applymovement OBJ_EVENT_ID_PLAYER, WaitHeDidWhat_GetOutOfWay
	applymovement 3, WaitHeDidWhat_WalkToArena
	opendoor 10, 1
	waitdooranim
	waitmovement 0
	playse SE_EXIT
	removeobject 3
	closedoor 10, 1
	waitdooranim
	goto WaitHeDidWhat_CalledToSkybox_Script
	return


WaitHeDidWhat_CalledToSkybox_Script::
	addvar VAR_STORYLINE_STATE, 1
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitse
	pokenavcall WaitHeDidWhat_CalledToSkybox_Script_Text_0
	waitmessage
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_CongratsComeOnUp
	callnative ClearMugshot
	playse SE_POKENAV_HANG_UP
	waitse
	release
	end


WaitHeDidWhat_WatchOtherSemifinal_Dialogue::
	addvar VAR_STORYLINE_STATE, 1
	lock
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_GoodShitDownThere
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, WaitHeDidWhat_GetOutOfWay
	opendoor 9, 1
	waitdooranim
	applymovement 8, WaitHeDidWhat_WalkToElevator
	waitmovement 0
	playse SE_EXIT
	removeobject 8
	closedoor 9, 1
	waitdooranim
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	TeleportCamera 9, 6
	fadescreen FADE_FROM_BLACK
	msgbox gText_WaitHeDidWhat_InAStunningUpset
	closemessage
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	applymovement 1, Common_Movement_ExclamationMark
	applymovement 7, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_HolyShit
	callnative ClearMugshot
	msgbox gText_WaitHeDidWhat_WellTakeAQuick
	closemessage
	applymovement 5, WaitHeDidWhat_EncouragePlayer
	applymovement 7, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_MakeSureYouGive
	closemessage
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_GoodLuck
	callnative ClearMugshot
	closemessage
	release
	end


WaitHeDidWhat_BiancaMeltdown_Dialogue::
	random 4
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	switch VAR_RESULT
	case 0, WaitHeDidWhat_BiancaMeltdown_Dialogue_3
	case 1, WaitHeDidWhat_BiancaMeltdown_Dialogue_4
	case 2, WaitHeDidWhat_BiancaMeltdown_Dialogue_5
	case 3, WaitHeDidWhat_BiancaMeltdown_Dialogue_6
WaitHeDidWhat_BiancaMeltdown_Dialogue_1:
	callnative ClearMugshot
	closemessage
	return

WaitHeDidWhat_BiancaMeltdown_Dialogue_3:
	msgbox gText_WaitHeDidWhat_ILostToThat
	goto WaitHeDidWhat_BiancaMeltdown_Dialogue_1

WaitHeDidWhat_BiancaMeltdown_Dialogue_4:
	msgbox gText_WaitHeDidWhat_GetTheFuck
	goto WaitHeDidWhat_BiancaMeltdown_Dialogue_1

WaitHeDidWhat_BiancaMeltdown_Dialogue_5:
	msgbox gText_WaitHeDidWhat_HowCouldThisHappen
	goto WaitHeDidWhat_BiancaMeltdown_Dialogue_1

WaitHeDidWhat_BiancaMeltdown_Dialogue_6:
	msgbox gText_WaitHeDidWhat_AbsoluteBullshit
	goto WaitHeDidWhat_BiancaMeltdown_Dialogue_1


WaitHeDidWhat_PreparePlayer_Script::
	lock
	faceplayer
	msgbox gText_WaitHeDidWhat_AreYouReady, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq WaitHeDidWhat_PreparePlayer_Script_2
WaitHeDidWhat_PreparePlayer_Script_1:
	release
	end

WaitHeDidWhat_PreparePlayer_Script_2:
	call GroupStages_MoveObjects_Script
	warpsilent MAP_PSFPLACE14_ARENA, 0
	goto WaitHeDidWhat_PreparePlayer_Script_1


WaitHeDidWhat_WalkIntoChampionshipPosition::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, WaitHeDidWhat_WalkToBattlefieldPosition
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_IDontThinkYouCan
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_ImReallyHappy
	callnative ClearMugshot
	addvar VAR_STORYLINE_STATE, 1
	call Common_EventScript_SaveGame
	goto WaitHeDidWhat_StartBattle_Script
	return


WaitHeDidWhat_StartBattle_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_ForPsfregion
	trainerbattle_no_intro TRAINER_STEVEN, gText_WaitHeDidWhat_SoClose
	closemessage
	callnative ClearMugshot
	goto WelcomeToTheHallOfFame_PostBattle_Dialogue
	return


WaitHeDidWhat_GetOutOfWay:
	walk_left
	face_right
	step_end

WaitHeDidWhat_WalkToElevator:
	walk_up
	walk_up
	step_end

WaitHeDidWhat_EncouragePlayer:
	walk_down
	walk_right
	walk_right
	step_end

WaitHeDidWhat_WalkToBattlefieldPosition:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

WaitHeDidWhat_StepAside:
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	step_end

WaitHeDidWhat_WalkToArena:
	walk_up
	walk_up
	walk_up
	walk_up
	delay_16
	step_end

WaitHeDidWhat_CalledToSkybox_Script_Text_0:
	.string "This phone is ringing.$"

gText_WaitHeDidWhat_AreYouReady::
	.string "Are you ready to battle for the\n"
	.string "Championship?$"

gText_WaitHeDidWhat_CongratsComeOnUp::
	.string "Congrats on making it to the Finals!\n"
	.string "Come to the Skybox to watch\l"
	.string "Bianca's battle!$"

gText_WaitHeDidWhat_GoodShitDownThere::
	.string "Good shit down there! Time to crush\n"
	.string "this Archer kid. See you in the\l"
	.string "Finals!$"

gText_WaitHeDidWhat_InAStunningUpset::
	.string "In a stunning upset, the hometown hero,\n"
	.string "Archer defeats Bianca\l"
	.string "and moves onto the Finals! What a wild\l"
	.string "match!$"

gText_WaitHeDidWhat_HolyShit::
	.string "(...holy shit!)$"

gText_WaitHeDidWhat_WellTakeAQuick::
	.string "We'll take a quick break, and when we\n"
	.string "come back... your Championship match!\l"
	.string "Archer VS {PLAYER}, for all\l"
	.string "the marbles!$"

gText_WaitHeDidWhat_MakeSureYouGive::
	.string "Make sure you give us a good show down\n"
	.string "there!$"

gText_WaitHeDidWhat_GoodLuck::
	.string "Good luck, {PLAYER}.$"

gText_WaitHeDidWhat_ILostToThat::
	.string "I lost to that absolute garbage\n"
	.string "Trainer? What happened?$"

gText_WaitHeDidWhat_GetTheFuck::
	.string "Get the fuck away from me!$"

gText_WaitHeDidWhat_HowCouldThisHappen::
	.string "How could this happen? Now I have to\n"
	.string "win another match just to get THIRD?!?$"

gText_WaitHeDidWhat_AbsoluteBullshit::
	.string "Absolute bullshit. Argh I cannot\n"
	.string "believe this shit…$"

gText_WaitHeDidWhat_IDontThinkYouCan::
	.string "{PLAYER}, I don't think you can beat\n"
	.string "me when I have home court advantage! I\l"
	.string "already beat one cheater, and I'm\l"
	.string "gonna take you down too!$"

gText_WaitHeDidWhat_ImReallyHappy::
	.string "I'm really happy for you! But I'm\n"
	.string "keeping my undefeated streak against\l"
	.string "you, Archer.$"

gText_WaitHeDidWhat_ForPsfregion::
	.string "For Psfregion!$"

gText_WaitHeDidWhat_SoClose::
	.string "…so close.$"
