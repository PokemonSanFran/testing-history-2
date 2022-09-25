OneDown_SetUpObject_Script::
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 16, 14
	TeleportCamera 16, 14
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 8, Common_Movement_FaceUp
	applymovement 2, Common_Movement_FaceUp
	waitmovement 2
	fadescreen FADE_FROM_BLACK
	lock
	goto OneDown_StartCutscene_Script
	return


OneDown_StartCutscene_Script::
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_OneDown_IJustGotFilled
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OneDown_ThanksAndYouve
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_OneDown_IDidntThinkIHad
	callnative ClearMugshot
	closemessage
	applymovement 8, Common_Movement_FaceRight
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_OneDown_SoundsLikeWereBoth
	callnative ClearMugshot
	closemessage
	goto OneDown_StartEarthquake_Script
	return


OneDown_StartEarthquake_Script::
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 4
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, 25
	setvar VAR_0x8007, 10
	special ShakeCamera
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 2, Common_Movement_ExclamationMark
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 8
	waitstate
	playse SE_M_EARTHQUAKE
	special ShakeCamera
	delay 100
	waitstate
	goto OneDown_Finish_Dialogue
	return


OneDown_Finish_Dialogue::
	applymovement 2, Common_Movement_FaceLeft
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_OneDown_MyOldBones
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OneDown_WhatDoYouMean
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_OneDown_YoureGonnaCall
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_OneDown_WeGetQuakes
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_OneDown_GuessYoureRight
	callnative ClearMugshot
	closemessage
	applymovement 8, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_OneDown_GetSomeRest
	callnative ClearMugshot
	closemessage
	applymovement 8, Common_Movement_FaceRight
	applymovement 2, Common_Movement_FaceLeft
	waitmovement 2
	setvar VAR_STORYLINE_STATE, STORY_1ST_TAKEDOWN
	release
	end


OneDown_WalkToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

OneDown_WalkOffScreen:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OneDown_ArianaWalkAway:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_OneDown_IJustGotFilled::
	.string "I just got filled in… that was\n"
	.string "absolutely incredible!$"

gText_OneDown_ThanksAndYouve::
	.string "Thanks. And you've been an awesome\n"
	.string "leader too. These people love you.$"

gText_OneDown_IDidntThinkIHad::
	.string "I didn't think I had it in me, to be\n"
	.string "honest. Giovan- Wikstrom knew better,\l"
	.string "I guess.$"

gText_OneDown_SoundsLikeWereBoth::
	.string "Sounds like we're both having excellent\n"
	.string "days! My talks with the region's\l"
	.string "council have been much more productive\l"
	.string "than I expected. I think we're actually\l"
	.string "making some damn progress! If we keep\l"
	.string "this up -$"

gText_OneDown_MyOldBones::
	.string "My old bones can't handle those quakes\n"
	.string "like I used to! My mind is starting to\l"
	.string "slip too, I tell ya.$"

gText_OneDown_WhatDoYouMean::
	.string "What do you mean?$"

gText_OneDown_YoureGonnaCall::
	.string "You're gonna call me a crazy ol' coot.\n"
	.string "But I swear, these quakes feel\l"
	.string "familiar. And different. Like I\l"
	.string "recognize ‘em. Crazy right?$"

gText_OneDown_WeGetQuakes::
	.string "We get quakes all the time. The\n"
	.string "SanAndreasFault will do that, you\l"
	.string "know? I'm sure they all start to feel\l"
	.string "the same.$"

gText_OneDown_GuessYoureRight::
	.string "Guess you're right, kid.$"

gText_OneDown_GetSomeRest::
	.string "I know its been a long day, {PLAYER},\n"
	.string "you should get some rest. You're still\l"
	.string "staying at Archer's place in Alameda,\l"
	.string "right?$"
