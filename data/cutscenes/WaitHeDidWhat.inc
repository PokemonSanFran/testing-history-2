WaitHeDidWhat_HideObject_Script::
	setflag FLAG_TEMP_1
	return


WaitHeDidWhat_ShowObject_Script::
	clearflag FLAG_TEMP_1
	addobject 8
	return


WaitHeDidWhat_MeltdownSetUp_Script::
	setweather WEATHER_VOLCANIC_ASH
	doweather
	addobject 2
	setobjectxy 2, 2, 7
	setobjectxyperm 2, 2, 7
	return


WaitHeDidWhat_WatchOtherSemifinal::
	addvar VAR_ROUTE119_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	lockall
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
	releaseall
	end


WaitHeDidWhat_PsftransrivalMeltdown_Dialogue::
	random 4
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	switch VAR_RESULT
	case 0, WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_3
	case 1, WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_4
	case 2, WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_5
	case 3, WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_6
WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_1:
	callnative ClearMugshot
	closemessage
	return

WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_3:
	msgbox gText_WaitHeDidWhat_ILostToThat
	goto WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_1

WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_4:
	msgbox gText_WaitHeDidWhat_GetTheFuck
	goto WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_1

WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_5:
	msgbox gText_WaitHeDidWhat_HowCouldThisHappen
	goto WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_1

WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_6:
	msgbox gText_WaitHeDidWhat_AbsoluteBullshit
	goto WaitHeDidWhat_PsftransrivalMeltdown_Dialogue_1


yep::
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_IDontThinkYouCan
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_ImReallyHappy
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_ForPsfregion
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitHeDidWhat_SoClose
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

gText_WaitHeDidWhat_GoodShitDownThere::
	.string "Good shit down there! Time to crush\n"
	.string "this Psfnativerival kid. See you in the\l"
	.string "Finals!$"

gText_WaitHeDidWhat_InAStunningUpset::
	.string "In a stunning upset, the hometown hero,\n"
	.string "Psfnativerival defeats Psftransrival\l"
	.string "and moves onto the Finals! What a wild\l"
	.string "match!$"

gText_WaitHeDidWhat_HolyShit::
	.string "(...holy shit!)$"

gText_WaitHeDidWhat_WellTakeAQuick::
	.string "We'll take a quick break, and when we\n"
	.string "come back... your Championship match!\l"
	.string "Psfnativerival VS {PLAYER}, for all\l"
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
	.string "you, Psfnativerival.$"

gText_WaitHeDidWhat_ForPsfregion::
	.string "For Psfregion!$"

gText_WaitHeDidWhat_SoClose::
	.string "…so close.$"
