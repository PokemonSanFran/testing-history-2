OkayLetsFixit_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


OkayLetsFixIt_ShowObject_Script::
	setflag FLAG_TEMP_2
	return


OkayLetsFixit_ReachTop_Script::
	checkitem ITEM_METEORITE, 1
	compare VAR_RESULT, 0
	goto_if_eq OkayLetsFixit_ReachTop_Script_2
	lock
	applymovement OBJ_EVENT_ID_PLAYER, OkayLetsFixit_WalkToPeak
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_OkayLetsFixIt_TheBambooStar
	closemessage
	playse SE_M_DETECT
	dofieldeffectsparkle 17, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	delay 150
	clearflag FLAG_TEMP_1
	addobject 1
	fadescreen FADE_FROM_WHITE
	msgbox gText_OkayLetsFixIt_ImGladYouCame, , SPEAKER_HIKO
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OkayLetsFixit_LookAround
	waitmovement 0
	msgbox gText_OkayLetsFixIt_WhatWhereDidYou, , SPEAKER_ZOEY
	msgbox gText_OkayLetsFixIt_HaveYouRealized, , SPEAKER_HIKO
	msgbox gText_OkayLetsFixIt_InComingHere, , SPEAKER_ZOEY
	msgbox gText_OkayLetsFixIt_LetsLookBack, , SPEAKER_HIKO
	closemessage
	warpsilent MAP_OKAY_LETS_FIXIT_FLASHBACK, 255, 9, 4
	end

OkayLetsFixit_ReachTop_Script_2:
	release
	end


OkayLetsFixit_StartFlashback_Script::
	lock
	setvar VAR_STORYLINE_STATE, STORY_BEGIN_LETS_FIX_IT
	msgbox gText_OkayLetsFixIt_ThisWasTheNight, , SPEAKER_ZOEY
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	msgbox gText_OkayLetsFixIt_Why, , SPEAKER_HIKO
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_OkayLetsFixIt_IWasTryingToHelp, , SPEAKER_ZOEY
	msgbox gText_OkayLetsFixIt_WouldYouChoose, , SPEAKER_HIKO
	msgbox gText_OkayLetsFixIt_IfICouldDoItOver, , SPEAKER_ZOEY
	closemessage
	delay 30
	warpsilent MAP_TWINPEAKS, 255, 17, 43
	end


OkayLetsFixit_ReturnToPeak_Script::
	lock
	clearflag FLAG_TEMP_1
	addobject 1
	call OkayLetsFixit_TimelineReset_Script
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, OkayLetsFixit_WatchCliffWalk
	applymovement 1, OkayLetsFixit_WalkOffCliff
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, OkayLetsFixit_PanCamera
	waitmovement OBJ_EVENT_ID_CAMERA
	waitmovement 1
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_OkayLetsFixIt_WaitWhatWhoAreYou, , SPEAKER_ZOEY
	msgbox gText_OkayLetsFixIt_IHopeYouMake, , SPEAKER_HIKO
	closemessage
	playse SE_ORB
	fadescreen FADE_TO_WHITE
	delay 150
	removeobject 1
	clearflag FLAG_TEMP_2
	addobject 2
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	waitmoncry
	warpsilent MAP_PRESIDIO_COMPOUND_1F, 255, 9, 7
	return


OkayLetsFixit_TimelineReset_Script::
	setflag FLAG_TIMELINE_TIMETRAVEL
	clearflag FLAG_TIMELINE_FALSE
	setvar VAR_STORYLINE_STATE, STORY_MORNING_AFTER_TIMETRAVEL
	setvar VAR_MANHUNT_STATE, NOT_ASSIGNED
	setvar VAR_LETS_BURN_THIS_MOTHER_STATE, NOT_ASSIGNED
	setvar VAR_HOW_DISAPPOINTING_STATE, MISSION_NOT_ASSIGNED
	return


OkayLetsFixit_WalkToPeak:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OkayLetsFixit_LookAround:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	face_up
	delay_16
	face_down
	delay_16
	face_left
	step_end

OkayLetsFixit_WalkOffCliff:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OkayLetsFixit_PanCamera:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OkayLetsFixit_WatchCliffWalk:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OkayLetsFixIt_PaceNightmare:
	walk_down
	walk_left
	walk_left
	walk_right
	walk_right
	step_end

gText_OkayLetsFixIt_TheBambooStar::
	.string "The Bamboo Star is glowing!$"

gText_OkayLetsFixIt_ImGladYouCame::
	.string "Ah {PLAYER}, I'm glad you came. I'm\n"
	.string "Hiko.$"

gText_OkayLetsFixIt_WhatWhereDidYou::
	.string "What… where… did you come from?! What\n"
	.string "the hell is going on?$"

gText_OkayLetsFixIt_HaveYouRealized::
	.string "Have you realized the error in your\n"
	.string "ways?$"

gText_OkayLetsFixIt_InComingHere::
	.string "In coming here? Yeah, I think -$"

gText_OkayLetsFixIt_LetsLookBack::
	.string "Let's look back.$"

gText_OkayLetsFixIt_ThisWasTheNight::
	.string "This was the night I decided to help\n"
	.string "Ycombinator.$"

gText_OkayLetsFixIt_Why::
	.string "Why?$"

gText_OkayLetsFixIt_IWasTryingToHelp::
	.string "I was trying to help. I thought that was\n"
	.string "the right thing! But… I'm not sure now$"

gText_OkayLetsFixIt_WouldYouChoose::
	.string "Would you choose differently?$"

gText_OkayLetsFixIt_IfICouldDoItOver::
	.string "If I could do it over? I think so. I\n"
	.string "think I made the problem worse.$"

gText_OkayLetsFixIt_WaitWhatWhoAreYou::
	.string "Wait what - who are you? How are you -$"

gText_OkayLetsFixIt_IHopeYouMake::
	.string "I hope you make the right decision this\n"
	.string "time, {PLAYER}.$"

gText_OkayLetsFixIt_WhatTheHell::
	.string "What the hell was that? That dream was…\n"
	.string "insane. What the hell did I eat for\l"
	.string "dinner?$"
