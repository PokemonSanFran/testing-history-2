SpeechSpeechSpeech_MoveObject_Script::
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_8
	setobjectxy 1, 10, 8
	setobjectxyperm 1, 10, 8
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectxy 3, 7, 3
	setobjectxyperm 3, 7, 3
	setobjectxy 2, 8, 3
	setobjectxyperm 2, 8, 3
	return


SpeechSpeechSpeech_MovePlayer_Script::
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 9
	TeleportCamera 9, 9
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 13, 8, 8
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 14, 11, 8
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 15, 7, 9
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 16, 9, 10
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 17, 10, 9
	createvobject OBJ_EVENT_GFX_AQUA_MEMBER_M, 18, 7, 10
	call SpeechSpeechSpeech_ResetFacing_Script
	return


SpeechSpeechSpeech_CrowdLookAround_Script::
	turnvobject 13, DIR_WEST
	delay 16
	turnvobject 15, DIR_EAST
	delay 16
	turnvobject 16, DIR_EAST
	delay 16
	turnvobject 18, DIR_EAST
	delay 16
	return


SpeechSpeechSpeech_ResetFacing_Script::
	turnvobject 13, DIR_NORTH
	turnvobject 14, DIR_NORTH
	turnvobject 15, DIR_NORTH
	turnvobject 16, DIR_NORTH
	turnvobject 17, DIR_NORTH
	turnvobject 18, DIR_NORTH
	return


SpeechSpeechSpeech_ProjectAssignment_ObjectSetUp_Script::
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_6
	setobjectxy 3, 11, 17
	setobjectxyperm 3, 11, 17
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	setobjectxy 2, 17, 15
	setobjectxyperm 2, 17, 15
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	setobjectxy 8, 16, 15
	setobjectxyperm 8, 16, 15
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxy 6, 19, 6
	setobjectxyperm 6, 19, 6
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	setobjectxy 5, 4, 6
	setobjectxyperm 5, 4, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 9, MOVEMENT_TYPE_LOOK_AROUND
	setobjectnewmovementtype 9, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxy 9, 11, 18
	setobjectxyperm 9, 11, 18
	setobjectmovementtype 10, MOVEMENT_TYPE_LOOK_AROUND
	setobjectnewmovementtype 10, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxy 10, 17, 16
	setobjectxyperm 10, 17, 16
	setobjectmovementtype 11, MOVEMENT_TYPE_LOOK_AROUND
	setobjectnewmovementtype 11, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxy 11, 19, 7
	setobjectxyperm 11, 19, 7
	setobjectmovementtype 12, MOVEMENT_TYPE_LOOK_AROUND
	setobjectnewmovementtype 12, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxy 12, 4, 7
	setobjectxyperm 12, 4, 7
	return


SpeechSpeechSpeech_PositionPlayer_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	fadescreen FADE_TO_BLACK
	call SpeechSpeechSpeech_MovePlayer_Script
	fadescreen FADE_FROM_BLACK
	goto SpeechSpeechSpeech_Intro_Dialogue
	return


SpeechSpeechSpeech_Intro_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ThankYouAll
	msgbox gText_SpeechSpeechSpeech_FirstOfAll
	callnative ClearMugshot
	closemessage
	call SpeechSpeechSpeech_CrowdLookAround_Script
	call SpeechSpeechSpeech_ResetFacing_Script
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ForAllYouve
	callnative ClearMugshot
	closemessage
	turnvobject 13, DIR_WEST
	delay 16
	turnvobject 15, DIR_EAST
	msgbox gText_SpeechSpeechSpeech_WaitWhat
	turnvobject 16, DIR_EAST
	delay 16
	turnvobject 18, DIR_EAST
	msgbox gText_SpeechSpeechSpeech_AreTheyEven
	closemessage
	call SpeechSpeechSpeech_ResetFacing_Script
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_HasMyFullConfidence
	callnative ClearMugshot
	closemessage
	goto SpeechSpeechSpeech_StartTransformation_Script
	return


SpeechSpeechSpeech_StartTransformation_Script::
	clearflag FLAG_TEMP_5
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, SpeechSpeechSpeech_PanCameraUp
	applymovement 7, SpeechSpeechSpeech_WalkBackstage
	waitmovement OBJ_EVENT_ID_CAMERA
	delay 32
	applymovement 7, SpeechSpeechSpeech_StartSpin
	waitmovement 7
	applymovement 5, SpeechSpeechSpeech_FinishSpin
	waitmovement 7
	removeobject 7
	clearflag FLAG_TEMP_8
	addobject 5
	delay 32
	applymovement 3, SpeechSpeechSpeech_WalkOutElite
	applymovement 2, SpeechSpeechSpeech_WalkOutElite
	applymovement 6, SpeechSpeechSpeech_WalkOutElite
	applymovement 5, SpeechSpeechSpeech_WalkOutElite
	applymovement 8, SpeechSpeechSpeech_StepAside
	applymovement OBJ_EVENT_ID_CAMERA, SpeechSpeechSpeech_PanCameraDown
	waitmovement OBJ_EVENT_ID_CAMERA
	special RemoveCameraObject
	goto SpeechSpeechSpeech_EliteReveal_Dialogue
	return


SpeechSpeechSpeech_EliteReveal_Dialogue::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_Us
	callnative ClearMugshot
	closemessage
	msgbox gText_SpeechSpeechSpeech_HolyShit
	closemessage
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 25
	setvar VAR_0x8007, 10
	special ShakeCamera
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	applymovement 10, Common_Movement_ExclamationMark
	applymovement 11, Common_Movement_ExclamationMark
	applymovement 12, Common_Movement_ExclamationMark
	waitmovement 0
	delay 100
	waitstate
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_IsAnybodyHurt
	callnative ClearMugshot
	closemessage
	msgbox gText_SpeechSpeechSpeech_Yeah
	msgbox gText_SpeechSpeechSpeech_HellYes
	closemessage
	applymovement 12, SpeechSpeechSpeech_LookAround
	waitmovement 12
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_YouAllKnowHowCompanies
	callnative ClearMugshot
	closemessage
	msgbox gText_SpeechSpeechSpeech_WereFinally
	closemessage
	applymovement 12, SpeechSpeechSpeech_LookAround
	msgbox gText_SpeechSpeechSpeech_ThisIsInsane
	closemessage
	waitmovement 12
	applymovement 2, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_WeWantToBegin
	callnative ClearMugshot
	closemessage
	applymovement 5, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_4LeadCharge
	callnative ClearMugshot
	closemessage
	applymovement 5, SpeechSpeechSpeech_WalkBackwards
	applymovement 6, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_3LeadCharge
	callnative ClearMugshot
	closemessage
	applymovement 6, SpeechSpeechSpeech_WalkBackwards
	applymovement 3, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_1LeadCharge
	callnative ClearMugshot
	closemessage
	applymovement 3, SpeechSpeechSpeech_WalkBackwards
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_IllBeHandling
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_PSFCAVE7_STATE, 1
	TeleportCamera 9, 9
	callnative DestroyVirtualObjects
	call SpeechSpeechSpeech_ProjectAssignment_ObjectSetUp_Script
	applymovement 1, SpeechSpeechSpeech_WalkToPlayer
	fadescreen FADE_FROM_BLACK
	waitmovement 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_DamnThisShit
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ItFeelsReally
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_Yeah
	compare VAR_STORYLINE_STATE, 104
	goto_if_ne SpeechSpeechSpeech_EliteReveal_Dialogue_2
	msgbox gText_SpeechSpeechSpeech_ByTheWay
SpeechSpeechSpeech_EliteReveal_Dialogue_1:
	msgbox gText_SpeechSpeechSpeech_Peace
	callnative ClearMugshot
	closemessage
	applymovement 1, SpeechSpeechSpeech_LeaveScreen
	waitmovement 0
	removeobject 1
	release
	end

SpeechSpeechSpeech_EliteReveal_Dialogue_2:
	msgbox gText_SpeechSpeechSpeech_YeahAlsoAre
	goto SpeechSpeechSpeech_EliteReveal_Dialogue_1


SpeechSpeechSpeech_PanCameraUp:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SpeechSpeechSpeech_WalkBackstage:
	walk_up
	walk_up
	walk_up
	step_end

SpeechSpeechSpeech_WalkOutElite:
	walk_down
	walk_down
	step_end

SpeechSpeechSpeech_PanCameraDown:
	walk_down
	walk_down
	walk_down
	step_end

SpeechSpeechSpeech_StepAside:
	lock_facing_direction
	walk_right
	walk_right
	unlock_facing_direction
	step_end

SpeechSpeechSpeech_WalkBackwards:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

SpeechSpeechSpeech_WalkToPlayer:
	walk_left
	face_down
	step_end

SpeechSpeechSpeech_LeaveScreen:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SpeechSpeechSpeech_StartSpin:
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	step_end

SpeechSpeechSpeech_FinishSpin:
	face_left
	face_down
	face_right
	face_up
	step_end

SpeechSpeechSpeech_LookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_up
	step_end

gText_SpeechSpeechSpeech_GoWarehouseRave::
	.string "Are you going to the Warehouse Rave?\n"
	.string "Sounds fun! Wish I had time to go.$"

gText_SpeechSpeechSpeech_ThankYouAll::
	.string "Thank you all for coming. For all your\n"
	.string "hard work. All your support. I have a\l"
	.string "few announcements for you all.$"

gText_SpeechSpeechSpeech_FirstOfAll::
	.string "First of all, I will be taking a leave of\n"
	.string "absence. Effectively immediately,\l"
	.string "Psfgoodadmin will be leading\l"
	.string "Psfgoodteam. She has my full trust and\l"
	.string "support.$"

gText_SpeechSpeechSpeech_ForAllYouve::
	.string "Thank you for all you’ve done for us,\n"
	.string "Psfgoodboss, I hope to live up to your\l"
	.string "example.$"

gText_SpeechSpeechSpeech_WaitWhat::
	.string "Wait what?$"

gText_SpeechSpeechSpeech_AreTheyEven::
	.string "Are they even qualified?$"

gText_SpeechSpeechSpeech_HasMyFullConfidence::
	.string "Yes, Psfgoodadmin has my full\n"
	.string "confidence, as well as the backing of…$"

gText_SpeechSpeechSpeech_Us::
	.string "… US! The Elite Four of Psfregion1!$"

gText_SpeechSpeechSpeech_HolyShit::
	.string "Holy shit ok, good enough for me!$"

gText_SpeechSpeechSpeech_IsAnybodyHurt::
	.string "Is anybody hurt? …no? Wonderful. Let’s\n"
	.string "continue. Psfnatrival’s restoration\l"
	.string "project has been going excellently,\l"
	.string "and we’re going to use that momentum\l"
	.string "for our next stage. It’s time to take\l"
	.string "the fight to Psfbadguy!$"

gText_SpeechSpeechSpeech_Yeah::
	.string "Yeah!$"

gText_SpeechSpeechSpeech_HellYes::
	.string "Hell yes! Woo! Wait, where did\n"
	.string "Psfgoodboss go?$"

gText_SpeechSpeechSpeech_YouAllKnowHowCompanies::
	.string "You all know how companies like\n"
	.string "Psfcompany8 and Psfcompany7 have\l"
	.string "ruined our lives and families. But with\l"
	.string "the combined popularity of the\l"
	.string "Champion, Elite Four and our manpower,\l"
	.string "I think we can hurt these people where\l"
	.string "it counts: their wallets. We can’t drive\l"
	.string "these parasitic companies out of the\l"
	.string "region… but all that money has to go\l"
	.string "somewhere. Let’s use that money to\l"
	.string "strengthen the region and create a\l"
	.string "brighter future for us all.$"

gText_SpeechSpeechSpeech_WereFinally::
	.string "We’re finally doing it…$"

gText_SpeechSpeechSpeech_ThisIsInsane::
	.string "This is insane yo. But seriously, did\n"
	.string "they just disappear?$"

gText_SpeechSpeechSpeech_WeWantToBegin::
	.string "We want to begin by attacking the\n"
	.string "biggest players in Psfregion1. Each of\l"
	.string "us will handle a different offensive\l"
	.string "plan.$"

gText_SpeechSpeechSpeech_4LeadCharge::
	.string "Psfelite4 will lead the charge against\n"
	.string "Psfcompany8.$"

gText_SpeechSpeechSpeech_3LeadCharge::
	.string "Psfelite3 will lead the charge against\n"
	.string "Psfcompany5.$"

gText_SpeechSpeechSpeech_1LeadCharge::
	.string "Psfelite1 will lead the charge against\n"
	.string "Psfcompany7.$"

gText_SpeechSpeechSpeech_IllBeHandling::
	.string "And I’ll be handling negotiations with\n"
	.string "the government, and operations here.\l"
	.string "Psfgoodadmin will be giving each of you\l"
	.string "assignments under one of the Elite\l"
	.string "Four members, so listen up.$"

gText_SpeechSpeechSpeech_DamnThisShit::
	.string "Damn, this shit is so crazy! The air is\n"
	.string "electric!$"

gText_SpeechSpeechSpeech_ItFeelsReally::
	.string "It feels really awesome to start making\n"
	.string "a difference around here.$"

gText_SpeechSpeechSpeech_YeahAlsoAre::
	.string "Also, are you heading to that party in\n"
	.string "Psfcity9 now? I'll catch up with you in\l"
	.string "a second, I just gotta talk to\l"
	.string "Psfgoodadmin first.$"

gText_SpeechSpeechSpeech_ByTheWay::
	.string "By the way, you and I are free to work\n"
	.string "with whoever we want. Just talk to the\l"
	.string "Elite Four member you want to team up\l"
	.string "with. I gotta go, I told Psfgoodadmin\l"
	.string "I’d help them set up something. Peace!$"

gText_SpeechSpeechSpeech_Peace::
	.string "Peace!$"