HowDisappointing_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_5
	return


HowDisappointing_HideTeamRocket_Script::
	setflag FLAG_TEMP_5
	return


HowDisappointing_HidePolice_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_4
	setobjectxy 5, 17, 2
	setobjectxyperm 5, 17, 2
	return


HowDisappointing_StartRaid_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto HowDisappointing_RaidMovement_Script
	msgbox gText_HowDisappointing_ThanksForJoining
	closemessage
	applymovement 4, HowDisappointing_WalkToPlayer
	waitmovement 4
	msgbox gText_HowDisappointing_OnceTheyTry
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	applymovement 2, Common_Movement_WalkInPlaceUp
	applymovement 3, Common_Movement_WalkInPlaceUp
	msgbox gText_HowDisappointing_YesSir
	msgbox gText_HowDisappointing_OhAndChampion
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_YeahQuestion
	callnative ClearMugshot
	msgbox gText_HowDisappointing_TryToNotLet
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_Yeah
	callnative ClearMugshot
	msgbox gText_HowDisappointing_Hehehehee
	closemessage
	goto HowDisappointing_RaidMovement_Script
	return


HowDisappointing_RaidMovement_Script::
	fadescreen FADE_TO_BLACK
	delay 16
	fadescreen FADE_FROM_BLACK
	addvar VAR_PETALBURG_WOODS_STATE, 1
	opendoor 5, 8
	waitdooranim
	applymovement 4, HowDisappointing_RunIntoGymD
	waitmovement 4
	playse SE_EXIT
	removeobject 4
	applymovement 3, HowDisappointing_RunIntoGymC
	applymovement 1, HowDisappointing_RunIntoGymA
	applymovement 2, HowDisappointing_RunIntoGymB
	waitmovement 2
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	waitse
	waitse
	waitse
	removeobject 1
	removeobject 2
	removeobject 3
	closedoor 5, 8
	waitdooranim
	playse SE_M_EXPLOSION
	waitse
	playse SE_M_EXPLOSION
	waitse
	clearflag FLAG_TEMP_5
	playse SE_EXIT
	addobject 6
	applymovement 6, HowDisappointing_EscapeA
	waitmovement 6
	playse SE_EXIT
	waitse
	addobject 7
	applymovement 7, HowDisappointing_EscapeB
	waitmovement 7
	playse SE_EXIT
	waitse
	addobject 5
	applymovement 5, HowDisappointing_Escape
	waitmovement 0
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setobjectxy 5, 17, 2
	setobjectxyperm 5, 17, 2
	release
	end


HowDisappointing_Interfact_Ariana_Script::
	lock
	compare VAR_PETALBURG_WOODS_STATE, 3
	goto_if_eq HowDisappointing_Interfact_Ariana_Script_2
HowDisappointing_Interfact_Ariana_Script_1:
	addvar VAR_PETALBURG_WOODS_STATE, 1
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_HowDisappointing, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_ImTiredOfYou
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_IveNeverLied
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_ThenWhyAreYou
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_TheseCompanies
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_AllISeeIs
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	goto HowDisappointing_StartBattle_Script
	return

HowDisappointing_Interfact_Ariana_Script_2:
	goto HowDisappointing_StartBattle_Script
	goto HowDisappointing_Interfact_Ariana_Script_1


HowDisappointing_StartBattle_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_HowDisappointing_SighHowDisappointing, MSGBOX_NPC
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_SHELLY_WEATHER_INSTITUTE, gText_HowDisappointing_YouAllDidYour
	goto HowDisappointing_ArrestScene_Dialogue
	return


HowDisappointing_ArrestScene_Dialogue::
	lock
	clearflag FLAG_TEMP_1
	addobject 1
	setobjectxyperm 1, 17, 8
	setobjectxy 1, 17, 8
	applymovement 1, HowDisappointing_WalkToArrest
	waitmovement 0
	msgbox gText_HowDisappointing_YoureUnderArrest
	addvar VAR_PETALBURG_WOODS_STATE, 1
	warpsilent MAP_YCOMBINATORTOWER_2F, 255, 16, 26
	return


HowDisappointing_PostMissionObjectSetUp_Script::
	setobjectxy 14, 16, 28
	setobjectxyperm 14, 16, 28
	setobjectmovementtype 14, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_TEMP_8
	clearflag FLAG_TEMP_7
	clearflag FLAG_TEMP_5
	addobject 10
	addobject 13
	addobject 11
	setobjectxyperm 10, 15, 26
	setobjectxyperm 13, 17, 26
	setobjectxyperm 11, 16, 25
	setobjectmovementtype 13, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 10, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_DOWN
	return


HowDisappointing_MissionComplete_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_HowDisappointing_ExcellentWorkEverybody
	callnative ClearMugshot
	closemessage
	applymovement 10, HowDisappointing_LeaveRoomA
	applymovement 13, HowDisappointing_LeaveRoomB
	applymovement 11, HowDisappointing_LeaveRoomB
	waitmovement 0
	removeobject 10
	removeobject 13
	removeobject 11
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_PETALBURG_WOODS_STATE, 1
	release
	call ExhibitionBattle_TimeSkip_Script
	end


HowDisappointing_WalkToPlayer:
	walk_right
	face_down
	step_end

HowDisappointing_RunIntoGymA:
	walk_up
	walk_right
	walk_right
	walk_up
	step_end

HowDisappointing_RunIntoGymB:
	walk_up
	walk_right
	walk_up
	step_end

HowDisappointing_RunIntoGymC:
	walk_up
	walk_left
	walk_up
	step_end

HowDisappointing_RunIntoGymD:
	walk_up
	step_end

HowDisappointing_Escape:
	jump_2_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

HowDisappointing_EscapeA:
	walk_down
	jump_2_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

HowDisappointing_EscapeB:
	jump_2_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

HowDisappointing_WalkToArrest:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HowDisappointing_LeaveRoomA:
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

HowDisappointing_LeaveRoomB:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_HowDisappointing_ThanksForJoining::
	.string "Thanks for joining us {PLAYER}. Now,\n"
	.string "this operation is going to be pretty\l"
	.string "straightforward. We’re walking in,\l"
	.string "warrant in hand, and arresting\l"
	.string "terrorists on sight. We suspect there’s\l"
	.string "a hidden room or something, and they’ll\l"
	.string "start running out of there as soon as\l"
	.string "we show up. That’s where our Champion\l"
	.string "comes into play.$"

gText_HowDisappointing_OnceTheyTry::
	.string "Once they try to give us the slip, you’ll\n"
	.string "be in charge of hunting down the\l"
	.string "escaped members. We suspect they’ll\l"
	.string "flee into the city, but we’ll try to get\l"
	.string "you a readout of how many of ‘em we\l"
	.string "lose. You don’t have to perform any\l"
	.string "arrests, just subdue them long enough\l"
	.string "for an officer to grab ‘em. Make sense,\l"
	.string "ya’ll?$"

gText_HowDisappointing_YesSir::
	.string "Yes sir!$"

gText_HowDisappointing_OhAndChampion::
	.string "Oh, and Champion?$"

gText_HowDisappointing_YeahQuestion::
	.string "Yeah?$"

gText_HowDisappointing_TryToNotLet::
	.string "Try to not let the leaders go this time,\n"
	.string "okay?$"

gText_HowDisappointing_Yeah::
	.string "…yeah.$"

gText_HowDisappointing_Hehehehee::
	.string "Hehehehehe.$"

gText_HowDisappointing_HowDisappointing::
	.string "How disappointing to see you like this.\n"
	.string "Not here for a friendly chat?$"

gText_HowDisappointing_ImTiredOfYou::
	.string "I’m tired of you feeding lies to me every\n"
	.string "time we talk. Come on, it’s over.$"

gText_HowDisappointing_IveNeverLied::
	.string "I’ve never lied to you, {PLAYER}. I can\n"
	.string "see how deeply you care about\l"
	.string "protecting people.$"

gText_HowDisappointing_ThenWhyAreYou::
	.string "Then why are you so intent on\n"
	.string "destroying it all?$"

gText_HowDisappointing_TheseCompanies::
	.string "These companies… they don’t care about\n"
	.string "you! Or us! Why is this that so hard to\l"
	.string "see?$"

gText_HowDisappointing_AllISeeIs::
	.string "All I see is you trying to lie again. We’re\n"
	.string "done talking. You can come quietly, or I\l"
	.string "can make you.$"

gText_HowDisappointing_SighHowDisappointing::
	.string "*sigh* How disappointing.$"

gText_HowDisappointing_YouAllDidYour::
	.string "You all did your best…$"

gText_HowDisappointing_YoureUnderArrest::
	.string "TeamRocket, you’re under arrest!$"

gText_HowDisappointing_ExcellentWorkEverybody::
	.string "Excellent work everybody! Lenora,\n"
	.string "Cilan, and Ariana have all been\l"
	.string "arrested, and all of the Gyms were\l"
	.string "successfully shut down. The region will\l"
	.string "see how quickly we’re responding to\l"
	.string "these threats, and hopefully, this will\l"
	.string "slow their efforts.$"
