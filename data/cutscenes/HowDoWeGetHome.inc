HowDoWeGetHome_PostSceneObjectCleanUp_Script::
	compare VAR_DOGPATCH_STATE, PRE_HOW_DO_WE_GET_HOME
	goto_if_gt HowDoWeGetHome_PostSceneObjectCleanUp_Script_2
HowDoWeGetHome_PostSceneObjectCleanUp_Script_1:
	return

HowDoWeGetHome_PostSceneObjectCleanUp_Script_2:
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_1
	setobjectmovementtype 14, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 11, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 2, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 12, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 10, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 5, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 9, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 13, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	goto HowDoWeGetHome_PostSceneObjectCleanUp_Script_1


HowDoWeGetHome_FerryFixed_Script::
	compare VAR_STORYLINE_STATE, STORY_WEST_SANFRAN_COMPLETE
	goto_if_gt HowDoWeGetHome_FerryFixed_Script_2
HowDoWeGetHome_FerryFixed_Script_1:
	return

HowDoWeGetHome_FerryFixed_Script_2:
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_1
	goto HowDoWeGetHome_FerryFixed_Script_1


HowDoWeGetHome_YellingDistance_Dialogue::
	setvar VAR_DOGPATCH_STATE, POST_HOW_DO_WE_GET_HOME
	locktarget
	msgbox gText_HowDoWeGetHome_LookWeDontWant, , SPEAKER_JULIUS
	msgbox gText_HowDoWeGetHome_OrJustLeave, , SPEAKER_MADISON
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	fadescreen FADE_TO_BLACK
	waitmovement OBJ_EVENT_ID_PLAYER
	setobjectxy OBJ_EVENT_ID_PLAYER, 7, 22
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	TeleportCamera 7, 22
	fadescreen FADE_FROM_BLACK
	msgbox gText_HowDoWeGetHome_LosersYouWannaSay, , SPEAKER_JULIUS
	msgbox gText_HowDoWeGetHome_YouThinkYouScareMe, , SPEAKER_MADISON
	closemessage
	goto HowDoWeGetHome_ArianaGetsInvolved_Dialogue
	return


HowDoWeGetHome_ArianaGetsInvolved_Dialogue::
	applymovement 21, HowDoWeGetHome_LeaveFight_Movement
	applymovement 1, Common_Movement_FaceLeft
	waitmovement 1
	msgbox gText_HowDoWeGetHome_YoChillOut, , SPEAKER_ARIANA
	closemessage
	call HowDoWeGetHome_ArianaEntrance_Script
	msgbox gText_HowDoWeGetHome_WereDoneWithThisBeef, , SPEAKER_ARIANA
	msgbox gText_HowDoWeGetHome_ShouldntIMessYou, , SPEAKER_MADISON
	msgbox gText_HowDoWeGetHome_TheWayYouThinkItIs, , SPEAKER_ARIANA
	goto HowDoWeGetHome_CrowdRecgonizesAriana_Dialogue
	return


HowDoWeGetHome_CrowdRecgonizesAriana_Dialogue::
	applymovement 14, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceUp
	applymovement 11, Common_Movement_FaceLeft
	msgbox gText_HowDoWeGetHome_IThinkThats, , SPEAKER_STRANDED_A
	applymovement 2, Common_Movement_FaceRight
	applymovement 12, Common_Movement_FaceLeft
	applymovement 4, Common_Movement_FaceRight
	applymovement 10, Common_Movement_FaceLeft
	msgbox gText_HowDoWeGetHome_BetterBackDown, , SPEAKER_RESIDENT_E
	applymovement 5, Common_Movement_FaceDown
	msgbox gText_HowDoWeGetHome_ThreeTrainersAtOnce, , SPEAKER_RESIDENT_F
	applymovement 13, Common_Movement_FaceDown
	applymovement 9, Common_Movement_FaceUp
	msgbox gText_HowDoWeGetHome_Worldstar, , SPEAKER_RESIDENT_B
	closemessage
	goto HowDoWeGetHome_MadisonHowDoWeGetHome_Dialogue
	return


HowDoWeGetHome_MadisonHowDoWeGetHome_Dialogue::
	applymovement 6, Common_Movement_LookAround
	waitmovement 0
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_HowDoWeGetHome_YouKnowWhatWhatever, , SPEAKER_MADISON
	closemessage
	applymovement 6, HowDoWeGetHome_Madison_LeaveFight_Movement
	applymovement OBJ_EVENT_ID_PLAYER, HowDoWeGetHome_MoveOutOfWay_Movement
	delay 120
	applymovement 1, Common_Movement_LookAround
	waitmovement 1
	applymovement 1, HowDoWeGetHome_LeaveFight_Movement
	delay 60
	fadescreen FADE_TO_BLACK
	delay 60
	removeobject 6
	removeobject 1
	removeobject 21
	call HowDoWeGetHome_SetCrowdMovementType_Script
	call HowDoWeGetHome_SetCrowdNewMovementType_Script
	fadescreen FADE_FROM_BLACK
	releaseall
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	end


HowDoWeGetHome_ArianaEntrance_Script::
	lock
	playse SE_PIN
	applymovement 14, HowDoWeGetHome_ExclaimDown
	applymovement 3, HowDoWeGetHome_ExclaimDown
	applymovement 11, HowDoWeGetHome_ExclaimDown
	applymovement 5, HowDoWeGetHome_ExclaimDown
	applymovement 9, HowDoWeGetHome_ExclaimDown
	applymovement 13, HowDoWeGetHome_ExclaimDown
	applymovement 2, HowDoWeGetHome_ExclaimUp
	applymovement 4, HowDoWeGetHome_ExclaimUp
	applymovement 12, HowDoWeGetHome_ExclaimUp
	applymovement 10, HowDoWeGetHome_ExclaimUp
	applymovement 1, HowDoWeGetHome_WalkIntoFight_Movement
	waitmovement 0
	applymovement 6, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	return


HowDoWeGetHome_SetCrowdNewMovementType_Script::
	setobjectnewmovementtype 14, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 11, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 2, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 12, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 10, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 5, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 9, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 13, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 7, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	return


HowDoWeGetHome_SetCrowdMovementType_Script::
	setobjectmovementtype 14, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 11, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 2, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 12, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 10, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 5, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 9, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 13, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	return


HowDoWeGetHome_WalkIntoFight_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

HowDoWeGetHome_ExclaimDown:
	emote_exclamation_mark
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

HowDoWeGetHome_ExclaimUp:
	emote_exclamation_mark
	face_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

HowDoWeGetHome_LeaveFight_Movement:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HowDoWeGetHome_Madison_LeaveFight_Movement:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HowDoWeGetHome_MovePlayerOffPath_South:
	walk_right
	face_up
	step_end

HowDoWeGetHome_MovePlayerOffPath_North:
	walk_right
	face_down
	step_end

HowDoWeGetHome_MoveOutOfWay_Movement:
	walk_left
	walk_down
	face_up
	step_end

gText_HowDoWeGetHome_LookWeDontWant::
	.string "Look, we don't want to be here any more\n"
	.string "than you want us here, but we're both\l"
	.string "going to have to deal with it!$"

gText_HowDoWeGetHome_OrJustLeave::
	.string "Or, just leave! You shouldn't be here. Go\n"
	.string "to the Tenderloin, where you losers\l"
	.string "belong.$"

gText_HowDoWeGetHome_LosersYouWannaSay::
	.string "Losers? You wanna say that shit to my\n"
	.string "face?$"

gText_HowDoWeGetHome_YouThinkYouScareMe::
	.string "Absolutely. You think you scare me,\n"
	.string "pretty boy? I'll rearrange your face!$"

gText_HowDoWeGetHome_YoChillOut::
	.string "Yo, chill out!$"

gText_HowDoWeGetHome_WereDoneWithThisBeef::
	.string "We're done with this beef. Right now.\n"
	.string "We're going to try to make the best of\l"
	.string "this situation, and try to stay out of\l"
	.string "your way. But you guys absolutely need\l"
	.string "to relax. We'll be gone as soon as we\l"
	.string "can.$"

gText_HowDoWeGetHome_ShouldntIMessYou::
	.string "Why the hell shouldn't I mess you up\n"
	.string "too?$"

gText_HowDoWeGetHome_TheWayYouThinkItIs::
	.string "That's not going to go the way you\n"
	.string "think it is.$"

gText_HowDoWeGetHome_IThinkThats::
	.string "I think that's Ariana, right? The\n"
	.string "TeamRocket Admin?$"

gText_HowDoWeGetHome_BetterBackDown::
	.string "Yeah, Madison better back down.$"

gText_HowDoWeGetHome_ThreeTrainersAtOnce::
	.string "Dude, I'm pretty sure they took down\n"
	.string "three trainers at once a few weeks ago.$"

gText_HowDoWeGetHome_Worldstar::
	.string "Worldstarrrrrr!$"

gText_HowDoWeGetHome_YouKnowWhatWhatever::
	.string "...Actually you know what, whatever.$"
