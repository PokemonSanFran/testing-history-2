HowDoWeGetHome_HideObject_Script::
	setflag FLAG_TEMP_1
	return


HowDoWeGetHome_ObjectCleanUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


HowDoWeGetHome_ChangeCrowdMovementType_Script::
	setobjectmovementtype 14, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 11, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 2, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 12, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 10, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 5, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 8, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 9, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectmovementtype 13, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	return


HowDoWeGetHome_MovePlayerOffPath_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	compare VAR_TEMP_1, 6
	goto_if_eq HowDoWeGetHome_MovePlayerOffPath_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
HowDoWeGetHome_MovePlayerOffPath_Script_1:
	waitmovement 0
	goto HowDoWeGetHome_MoveCameraToFight_Script
	return

HowDoWeGetHome_MovePlayerOffPath_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	goto HowDoWeGetHome_MovePlayerOffPath_Script_1


HowDoWeGetHome_MoveCameraToFight_Script::
	addvar VAR_DOGPATCH_STATE, 1
	locktarget
	fadescreen FADE_TO_BLACK
	TeleportCamera 14, 9
	fadescreen FADE_FROM_BLACK
	goto HowDoWeGetHome_StartFight_Dialogue
	return


HowDoWeGetHome_StartFight_Dialogue::
	msgbox gText_HowDoWeGetHome_LookWeDontWant
	msgbox gText_HowDoWeGetHome_OrJustLeave
	msgbox gText_HowDoWeGetHome_LosersYouWannaSay
	msgbox gText_HowDoWeGetHome_YouThinkYouScareMe
	goto HowDoWeGetHome_ArianaGetsInvolved_Dialogue
	return


HowDoWeGetHome_ArianaGetsInvolved_Dialogue::
	clearflag FLAG_TEMP_1
	addobject 1
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDoWeGetHome_YoChillOut
	callnative ClearMugshot
	closemessage
	call HowDoWeGetHome_ArianaEntrance
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDoWeGetHome_WereDoneWithThisBeef
	callnative ClearMugshot
	msgbox gText_HowDoWeGetHome_ShouldntIMessYou
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDoWeGetHome_TheWayYouThinkItIs
	callnative ClearMugshot
	goto HowDoWeGetHome_CrowdRecgonizesAriana_Dialogue
	return


HowDoWeGetHome_CrowdRecgonizesAriana_Dialogue::
	applymovement 14, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceUp
	applymovement 11, Common_Movement_FaceLeft
	msgbox gText_HowDoWeGetHome_IThinkThats
	applymovement 2, Common_Movement_FaceRight
	applymovement 12, Common_Movement_FaceLeft
	applymovement 4, Common_Movement_FaceRight
	applymovement 10, Common_Movement_FaceLeft
	msgbox gText_HowDoWeGetHome_BetterBackDown
	applymovement 5, Common_Movement_FaceDown
	applymovement 8, Common_Movement_FaceUp
	msgbox gText_HowDoWeGetHome_ThreeTrainersAtOnce
	applymovement 9, Common_Movement_FaceDown
	applymovement 13, Common_Movement_FaceUp
	msgbox gText_HowDoWeGetHome_Worldstar
	closemessage
	goto HowDoWeGetHome_MadisonHowDoWeGetHome_Dialogue
	return


HowDoWeGetHome_MadisonHowDoWeGetHome_Dialogue::
	applymovement 6, Common_Movement_LookAround
	waitmovement 0
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_HowDoWeGetHome_YouKnowWhatWhatever
	closemessage
	applymovement 6, HowDoWeGetHome_DialogueFightNorth
	waitmovement 0
	removeobject 6
	applymovement 1, Common_Movement_LookAround
	waitmovement 0
	applymovement 1, HowDoWeGetHome_DialogueFightSouth
	waitmovement 0
	removeobject 1
	fadescreen FADE_TO_BLACK
	special ReturnCameraToPlayer
	fadescreen FADE_FROM_BLACK
	call HowDoWeGetHome_SetCrowdMovementType_Script
	releaseall
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	end


HowDoWeGetHome_ArianaEntrance::
	lock
	playse SE_PIN
	applymovement 14, HowDoWeGetHome_ExclaimRight
	applymovement 3, HowDoWeGetHome_ExclaimRight
	applymovement 11, HowDoWeGetHome_ExclaimRight
	applymovement 2, HowDoWeGetHome_ExclaimRight
	applymovement 4, HowDoWeGetHome_ExclaimRight
	applymovement 12, HowDoWeGetHome_ExclaimRight
	applymovement 10, HowDoWeGetHome_ExclaimRight
	applymovement 5, HowDoWeGetHome_ExclaimLeft
	applymovement 8, HowDoWeGetHome_ExclaimLeft
	applymovement 9, HowDoWeGetHome_ExclaimLeft
	applymovement 13, HowDoWeGetHome_ExclaimLeft
	applymovement 1, HowDoWeGetHome_WalkIntoFight
	waitmovement 0
	applymovement 6, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	return


HowDoWeGetHome_SetCrowdMovementType_Script::
	setobjectnewmovementtype 14, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 3, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 11, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 2, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 4, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 12, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 10, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 5, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 8, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 9, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	setobjectnewmovementtype 13, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectnewmovementtype 7, MOVEMENT_TYPE_WANDER_LEFT_AND_RIGHT
	return


HowDoWeGetHome_WalkIntoFight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HowDoWeGetHome_ExclaimLeft:
	emote_exclamation_mark
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	step_end

HowDoWeGetHome_ExclaimRight:
	emote_exclamation_mark
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end

HowDoWeGetHome_DialogueFightSouth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

HowDoWeGetHome_DialogueFightNorth:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HowDoWeGetHome_MovePlayerOffPath_South:
	walk_right
	face_up
	step_end

HowDoWeGetHome_MovePlayerOffPath_North:
	walk_right
	face_down
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
