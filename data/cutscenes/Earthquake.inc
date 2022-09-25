Earthquake_HideObject_Script::
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_2
	setobjectxyperm 3, 28, 33
	turnobject 3, DIR_NORTH
	return


Earthquake_HideTransport_Script::
	compare VAR_ALAMEDA_STATE, START_CHAMPIONSHIP_CLEAN_RAID
	goto_if_gt Earthquake_HideTransport_Script_2
	return

Earthquake_HideTransport_Script_1:
	setflag FLAG_TEMP_1F
	return

Earthquake_HideTransport_Script_2:
	compare VAR_ALAMEDA_STATE, MEET_AT_PSFROUTE8
	goto_if_lt Earthquake_HideTransport_Script_1
	return


Earthquake_PostRescue_Objects_Script::
	clearflag FLAG_TEMP_1
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_4
	addobject 3
	addobject 13
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 15, 32, 10
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 16, 31, 12
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 17, 31, 11
	turnvobject 16, DIR_EAST
	turnvobject 17, DIR_EAST
	setobjectxy OBJ_EVENT_ID_PLAYER, 32, 13
	setobjectxy 3, 33, 12
	setobjectxy 13, 33, 11
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	applymovement 13, Common_Movement_FaceLeft
	turnobject 3, DIR_WEST
	TeleportCamera 32, 13
	return


Earthquake_ThatNight_Dialogue::
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	addobject 1
	applymovement 1, Common_Movement_FaceDown
	msgbox gText_Earthquake_ThatNight
	closemessage
	fadescreen FADE_FROM_BLACK
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 8
	setvar VAR_0x8006, 25
	setvar VAR_0x8007, 5
	special ShakeCamera
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 1, Common_Movement_ExclamationMark
	waitstate
	playse SE_M_EARTHQUAKE
	special ShakeCamera
	delay 100
	waitstate
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_AreYouOkay
	callnative ClearMugshot
	closemessage
	msgbox gText_Earthquake_OhArceus
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Earthquake_WalkOutOfBed
	msgbox gText_Earthquake_HelpMe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_ImFine
	callnative ClearMugshot
	closemessage
	applymovement 1, Earthquake_WalkToWall
	waitmovement 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ThePowersDead
	callnative ClearMugshot
	closemessage
	applymovement 1, Earthquake_RunOutside
	waitmovement 1
	playse SE_EXIT
	waitse
	removeobject 1
	applymovement OBJ_EVENT_ID_PLAYER, Earthquake_RunFromBedOutside
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_ALAMEDA_STATE, POST_EARTHQUAKE
	warp MAP_ALAMEDA, 2
	return


Earthquake_ShowDestroyedCity_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_HolyShit
	closemessage
	callnative ClearMugshot
	fadescreen FADE_TO_BLACK
	TeleportCamera 11, 7
	special SpawnCameraObject
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, Earthquake_PanCameraDown
	waitmovement OBJ_EVENT_ID_CAMERA
	fadescreen FADE_TO_BLACK
	TeleportCamera 33, 26
	special SpawnCameraObject
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, Earthquake_PanCameraUp
	waitmovement OBJ_EVENT_ID_CAMERA
	fadescreen FADE_TO_BLACK
	TeleportCamera 29, 33
	fadescreen FADE_FROM_BLACK
	goto Earthquake_StartRescue_Dialogue
	return


Earthquake_StartRescue_Dialogue::
	special RemoveCameraObject
	addobject 13
	applymovement 13, Earthquake_WalkToPair
	waitmovement 13
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_OhYoureOkay
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_YeahWhyDidnt
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_CellTowersWere
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_SoundsLikeWere
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_ImGoingToMakeAnother
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_OfCourse
	closemessage
	callnative ClearMugshot
	applymovement 3, Earthquake_WalkAwayA
	applymovement 13, Earthquake_WalkAwayB
	waitmovement 3
	waitmovement 13
	removeobject 3
	removeobject 13
	setvar VAR_ALAMEDA_STATE, START_EARTHQUAKE_RESCUE
	release
	end


Earthquake_PostRescue_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_OkayThingsSeemToBe
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	call Earthquake_PostRescue_Objects_Script
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_WeveManagedToReestablish
	callnative ClearMugshot
	closemessage
	applymovement 13, Earthquake_Pace
	waitmovement 13
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_IReally
	playse SE_POKENAV_CALL
	waitse
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_AMessageFromThe
	callnative ClearMugshot
	closemessage
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_ThatsATrap
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_WhatDoYouMean
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ShitWeNever
	callnative ClearMugshot
	closemessage
	applymovement 3, Common_Movement_FaceUp
	waitmovement 3
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_IGotAMessage
	applymovement 13, Earthquake_TurnToPlayer
	waitmovement 13
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_WaitWhat
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ItGetsCrazier
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_WeBattledBut
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_ThatDoesntMake
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ItsJustABunch
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_IDontThinkSo
	callnative ClearMugshot
	closemessage
	applymovement 3, Common_Movement_FaceDown
	waitmovement 3
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_HowCanYouTrust
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_TheSecondHalf
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_SoSomebodyWantsUs
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_IThinkItsOn
	callnative ClearMugshot
	closemessage
	applymovement 3, Common_Movement_FaceUp
	waitmovement 3
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_FineTheThreeOfUs
	callnative ClearMugshot
	closemessage
	setvar VAR_STORYLINE_STATE, STORY_POST_EARTHQUAKE
	setvar VAR_ALAMEDA_STATE, MEET_AT_PSFROUTE8
	goto Earthquake_AskPlayerWarp_Script
	return


Earthquake_AskPlayerWarp_Script::
	applymovement 3, Earthquake_TurnToPlayer
	waitmovement 3
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ImGonnaHead, MSGBOX_YESNO
	closemessage
	callnative ClearMugshot
	compare VAR_RESULT, YES
	goto_if_eq Earthquake_AskPlayerWarp_Script_2
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_OkayWeve
	closemessage
	callnative ClearMugshot
	fadescreen FADE_TO_BLACK
	removeobject 15
	removeobject 16
	removeobject 17
	removeobject 3
	removeobject 13
	fadescreen FADE_FROM_BLACK
	release
	end

Earthquake_AskPlayerWarp_Script_2:
	warpsilent MAP_PSFROUTE8, 255, 10, 24
	end


Earthquake_WalkToWall:
	walk_up
	walk_up
	step_end

Earthquake_RunOutside:
	player_run_right
	player_run_up
	step_end

Earthquake_RunFromBedOutside:
	player_run_right
	player_run_right
	player_run_right
	player_run_right
	player_run_right
	player_run_up
	player_run_up
	player_run_up
	step_end

Earthquake_WalkOutOfBed:
	walk_right
	step_end

Earthquake_PanCameraDown:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Earthquake_PanCameraUp:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Earthquake_PanCameraLeft:
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
	step_end

Earthquake_WalkToPair:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

Earthquake_WalkAwayA:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Earthquake_WalkAwayB:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Earthquake_Pace:
	walk_right
	walk_up
	walk_up
	walk_down
	walk_down
	walk_up
	walk_up
	walk_down
	walk_down
	step_end

Earthquake_TurnToPlayer:
	walk_left
	face_down
	step_end

gText_Earthquake_ThatNight::
	.string "That night…$"

gText_Earthquake_AreYouOkay::
	.string "{PLAYER}, are you okay?$"

gText_Earthquake_OhArceus::
	.string "Oh Arceus, no!$"

gText_Earthquake_HelpMe::
	.string "Help me!$"

gText_Earthquake_ImFine::
	.string "I'm fine. Do you hear people screaming?$"

gText_Earthquake_ThePowersDead::
	.string "The power's dead. This… isn't good.$"

gText_Earthquake_HolyShit::
	.string "Holy shit.$"

gText_Earthquake_OhYoureOkay::
	.string "Oh Arceus, you're okay!$"

gText_Earthquake_YeahWhyDidnt::
	.string "Yeah, why didn't you just call?$"

gText_Earthquake_CellTowersWere::
	.string "Cell towers were destroyed… like\n"
	.string "everything else. Emily just told me\l"
	.string "that the docks are destroyed too.$"

gText_Earthquake_SoundsLikeWere::
	.string "Sounds like we're on our own.$"

gText_Earthquake_ImGoingToMakeAnother::
	.string "*sigh* I'm going to make another lap\n"
	.string "around Alameda and see who else I can\l"
	.string "help, and I've asked other TeamRocket\l"
	.string "members to do the same. Could you two -$"

gText_Earthquake_OfCourse::
	.string "Of course. Let's meet back in the town\n"
	.string "center in a bit.$"

gText_Earthquake_OkayThingsSeemToBe::
	.string "Okay… things seem to be stabilizing. I\n"
	.string "should go meet Ariana in the center of\l"
	.string "town.$"

gText_Earthquake_WeveManagedToReestablish::
	.string "We've managed to re-establish cell\n"
	.string "communications. The authorities claim\l"
	.string "they're on their way… Arceus knows how\l"
	.string "useful they'll actually be. Ina reports\l"
	.string "that our ranks suffered heavy\l"
	.string "casualties in the quake. Mark says our\l"
	.string "supply caches were also hit hard.$"

gText_Earthquake_IReally::
	.string "I really don't know how TeamRocket is\n"
	.string "going to hold up under this stress.$"

gText_Earthquake_AMessageFromThe::
	.string "My phone got a message from the Events\n"
	.string "account? Now?$"

gText_Earthquake_ThatsATrap::
	.string "That's a trap.$"

gText_Earthquake_WhatDoYouMean::
	.string "What do you mean? That doesn't make\n"
	.string "any sense.$"

gText_Earthquake_ShitWeNever::
	.string "Shit, we never got a chance to tell you.$"

gText_Earthquake_IGotAMessage::
	.string "Archer and I got a message from that\n"
	.string "account a few days ago. I went to a\l"
	.string "warehouse in Oakland, and Koga trapped\l"
	.string "me there and attacked me.$"

gText_Earthquake_WaitWhat::
	.string "Wait what?$"

gText_Earthquake_ItGetsCrazier::
	.string "It gets crazier.$"

gText_Earthquake_WeBattledBut::
	.string "We battled but… he threw the battle.\n"
	.string "And then told me to run. It was like he\l"
	.string "wasn't even trying.$"

gText_Earthquake_ThatDoesntMake::
	.string "That doesn't make any sense. Okay,\n"
	.string "what's this message trying to do…$"

gText_Earthquake_ItsJustABunch::
	.string "“TM15@18030122@37.75030467013338,\n"
	.string "-122.3798002138461” It's just a bunch\l"
	.string "of nonsense. Maybe a glitch?$"

gText_Earthquake_IDontThinkSo::
	.string "…I don't think so. Koga was really\n"
	.string "trying to help me. Even when I had\l"
	.string "dinner with him, their energy was\l"
	.string "different from everybody else in\l"
	.string "Ycombinator.$"

gText_Earthquake_HowCanYouTrust::
	.string "How can you trust them after ALL of\n"
	.string "this?$"

gText_Earthquake_TheSecondHalf::
	.string "The second half of that message are\n"
	.string "GPS coordinates, if that counts for\l"
	.string "anything.$"

gText_Earthquake_SoSomebodyWantsUs::
	.string "So somebody wants us to go somewhere.\n"
	.string "Where is that?$"

gText_Earthquake_IThinkItsOn::
	.string "I think it's on the mainland, by\n"
	.string "Psfroute8. Let's take a small team to\l"
	.string "go investigate.$"

gText_Earthquake_FineTheThreeOfUs::
	.string "Fine. The three of us and maybe a few\n"
	.string "more… nobody can take all of us at\l"
	.string "once.$"

gText_Earthquake_ImGonnaHead::
	.string "I'm gonna head over to Psfroute8 right\n"
	.string "now. Want to come with me?$"

gText_Earthquake_OkayWeve::
	.string "Okay, we've all got our orders. Let's\n"
	.string "stay in touch.$"
