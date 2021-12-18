Psfcity7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity7_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity7_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	compare VAR_PSFCITY7_STATE, 0
	goto_if_gt Psfcity7_MapScripts_MAP_SCRIPT_ON_TRANSITION_1
	return

Psfcity7_MapScripts_MAP_SCRIPT_ON_TRANSITION_1:
	call HowDoWeGetHome_PostSetUp_Script
	return


HowDoWeGetHome_PanCameraToFight_Script::
	setvar VAR_PSFCITY7_STATE, 1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	locktarget
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, HowDoWeGetHome_PanCamera_9_9
	waitmovement 0
	goto HowDoWeGetHome_StartFight_Dialogue
	return


HowDoWeGetHome_DecideCameraPath::
	return


HowDoWeGetHome_StartFight_Dialogue::
	msgbox gText_HowDoWeGetHome_LookWeDontWant
	msgbox gText_HowDoWeGetHome_OrJustLeave
	msgbox gText_HowDoWeGetHome_LosersYouWannaSay
	msgbox gText_HowDoWeGetHome_YouThinkYouScareMe
	goto HowDoWeGetHome_PsfgoodadminGetsInvolved_Dialogue
	return


HowDoWeGetHome_PsfgoodadminGetsInvolved_Dialogue::
	addobject 1
	clearflag FLAG_HIDE_PSFCITY7_PSFGOODADMIN
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDoWeGetHome_YoChillOut
	callnative ClearMugshot
	closemessage
	call HowDoWeGetHome_PsfgoodadminEntrance
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDoWeGetHome_WereDoneWithThisBeef
	callnative ClearMugshot
	msgbox gText_HowDoWeGetHome_ShouldntIMessYou
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDoWeGetHome_TheWayYouThinkItIs
	callnative ClearMugshot
	goto HowDoWeGetHome_CrowdRecgonizesPsfgoodadmin_Dialogue
	return


HowDoWeGetHome_CrowdRecgonizesPsfgoodadmin_Dialogue::
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
	goto HowDoWeGetHome_MadisonWalkAway_Dialogue
	return


HowDoWeGetHome_MadisonWalkAway_Dialogue::
	applymovement 6, Common_Movement_LookAround
	waitmovement 0
	applymovement 6, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_HowDoWeGetHome_YouKnowWhatWhatever
	closemessage
	applymovement 6, WalkAway_DialogueFightNorth
	waitmovement 0
	removeobject 6
	applymovement 1, Common_Movement_LookAround
	waitmovement 0
	applymovement 1, WalkAway_DialogueFightSouth
	waitmovement 0
	removeobject 1
	applymovement OBJ_EVENT_ID_CAMERA, HowDoWeGetHome_ReversePanCamera_9_9
	waitmovement 0
	special RemoveCameraObject
	call HowDoWeGetHome_ObjectCleanUp_Script
	releaseall
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	end


HowDoWeGetHome_PsfgoodadminEntrance::
	lockall
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


HowDoWeGetHome_ObjectCleanUp_Script::
	lock
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
	release
	return


HowDoWeGetHome_PostSetUp_Script::
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


HowDoWeGetHome_PanCamera_9_9:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

HowDoWeGetHome_ReversePanCamera_9_9:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

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

WalkAway_DialogueFightSouth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WalkAway_DialogueFightNorth:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_HowDoWeGetHome_LookWeDontWant::
	.string "Look, we don't want to be here any more\n"
	.string "than you want us here, but we're both\l"
	.string "going to have to deal with it!$"

gText_HowDoWeGetHome_OrJustLeave::
	.string "Or, just leave! You shouldn't be here. Go\n"
	.string "to the Psfcity12, where you losers\l"
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
	.string "I think that's Psfgoodadmin, right? The\n"
	.string "Psfgoodteam Admin?$"

gText_HowDoWeGetHome_BetterBackDown::
	.string "Yeah, Madison better back down.$"

gText_HowDoWeGetHome_ThreeTrainersAtOnce::
	.string "Dude, I'm pretty sure they took down\n"
	.string "three trainers at once a few weeks ago.$"

gText_HowDoWeGetHome_Worldstar::
	.string "Worldstarrrrrr!$"

gText_HowDoWeGetHome_YouKnowWhatWhatever::
	.string "...Actually you know what, whatever.$"
