HowDisappointing_ManageObject_Script::
	switch VAR_HOW_DISAPPOINTING_STATE
	case MISSION_ASSIGNED, HowDisappointing_ManageObject_Script_3
	case GYM_RAID_STARTED, HowDisappointing_ManageObject_Script_4
	case SAVED_BEFORE_ARIANA, HowDisappointing_ManageObject_Script_4
	call HowDisappointing_HideAll_Script
HowDisappointing_ManageObject_Script_1:
	return

HowDisappointing_ManageObject_Script_3:
	call HowDisappointing_HideTeamRocket_Script
	goto HowDisappointing_ManageObject_Script_1

HowDisappointing_ManageObject_Script_4:
	call HowDisappointing_HidePolice_Script
	goto HowDisappointing_ManageObject_Script_1


HowDisappointing_HideAll_Script::
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
	setobjectxy 5, 35, 20
	setobjectxyperm 5, 35, 20
	setobjectxy 6, 37, 0
	setobjectxyperm 6, 37, 0
	turnobject 6, DIR_WEST
	setobjectxy 7, 17, 16
	setobjectxyperm 7, 17, 16
	turnobject 6, DIR_EAST
	return


HowDisappointing_DeterminePlayerPath_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 5
	goto_if_gt HowDisappointing_DeterminePlayerPath_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
HowDisappointing_DeterminePlayerPath_Script_1:
	fadescreen FADE_TO_BLACK
	waitmovement OBJ_EVENT_ID_PLAYER
	setobjectxy OBJ_EVENT_ID_PLAYER, 28, 9
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	TeleportCamera 28, 9
	fadescreen FADE_FROM_BLACK
	return

HowDisappointing_DeterminePlayerPath_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	goto HowDisappointing_DeterminePlayerPath_Script_1


HowDisappointing_StartRaid_Dialogue::
	lock
	call HowDisappointing_DeterminePlayerPath_Script
	msgbox gText_HowDisappointing_ThanksForJoining
	msgbox gText_HowDisappointing_OnceTheyTry
	closemessage
	applymovement 1, Common_Movement_WalkInPlaceUp
	applymovement 2, Common_Movement_WalkInPlaceUp
	applymovement 3, Common_Movement_WalkInPlaceUp
	msgbox gText_HowDisappointing_YesSir
	waitmovement 3
	msgbox gText_HowDisappointing_OhAndChampion
	msgbox gText_HowDisappointing_YeahQuestion, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_HowDisappointing_TryToNotLet
	msgbox gText_HowDisappointing_Yeah, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_HowDisappointing_Hehehehee
	closemessage
	goto HowDisappointing_RaidMovement_Script
	return


HowDisappointing_MoveRaidIntoPosition_Script::
	setobjectxy 1, 20, 5
	setobjectxy 2, 21, 5
	setobjectxy 3, 23, 5
	setobjectxy OBJ_EVENT_ID_PLAYER, 24, 5
	TeleportCamera 24, 5
	setobjectxy 4, 22, 4
	return


HowDisappointing_RaidMovement_Script::
	fadescreen FADE_TO_BLACK
	call HowDisappointing_MoveRaidIntoPosition_Script
	delay 16
	fadescreen FADE_FROM_BLACK
	setvar VAR_HOW_DISAPPOINTING_STATE, GYM_RAID_STARTED
	opendoor 5, 8
	waitdooranim
	applymovement 4, HowDisappointing_RunIntoGymD
	waitmovement 4
	playse SE_EXIT
	removeobject 4
	applymovement 1, HowDisappointing_RunIntoGymA
	applymovement 2, HowDisappointing_RunIntoGymB
	applymovement 3, HowDisappointing_RunIntoGymC
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
	call HowDisappointing_ManageObject_Script
	release
	end


HowDisappointing_Interfact_Ariana_Script::
	lock
	compare VAR_HOW_DISAPPOINTING_STATE, SAVED_BEFORE_ARIANA
	goto_if_eq HowDisappointing_Interfact_Ariana_Script_2
HowDisappointing_Interfact_Ariana_Script_1:
	setvar VAR_HOW_DISAPPOINTING_STATE, SAVED_BEFORE_ARIANA
	msgbox gText_HowDisappointing_HowDisappointing, MSGBOX_NPC, SPEAKER_ARIANA
	msgbox gText_HowDisappointing_ImTiredOfYou, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_HowDisappointing_IveNeverLied, , SPEAKER_ARIANA
	msgbox gText_HowDisappointing_ThenWhyAreYou, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_HowDisappointing_TheseCompanies, , SPEAKER_ARIANA
	msgbox gText_HowDisappointing_AllISeeIs, MSGBOX_DEFAULT, SPEAKER_ZOEY
	call Common_EventScript_SaveGame
	goto HowDisappointing_StartBattle_Script
	return

HowDisappointing_Interfact_Ariana_Script_2:
	goto HowDisappointing_StartBattle_Script
	goto HowDisappointing_Interfact_Ariana_Script_1


HowDisappointing_StartBattle_Script::
	lock
	msgbox gText_HowDisappointing_SighHowDisappointing, MSGBOX_NPC, SPEAKER_ARIANA
	trainerbattle_no_intro TRAINER_SHELLY_WEATHER_INSTITUTE, gText_HowDisappointing_YouAllDidYour
	goto HowDisappointing_ArrestScene_Dialogue
	return


HowDisappointing_ArrestScene_Dialogue::
	lock
	setvar VAR_HOW_DISAPPOINTING_STATE, DEFEATED_ARIANA_CHINATOWN
	clearflag FLAG_TEMP_1
	addobject 1
	setobjectxyperm 1, 35, 13
	setobjectxy 1, 35, 13
	applymovement 1, HowDisappointing_WalkToArrest
	waitmovement 0
	msgbox gText_HowDisappointing_YoureUnderArrest
	questmenu QUEST_MENU_SET_REWARD, QUEST_HOW_DISAPPOINTING
	warpsilent MAP_SALESFORCETOWER_LEAGUEOPS, 32, 53
	return


HowDisappointing_MissionComplete_Dialogue::
	lock
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_HOW_DISAPPOINTING_STATE, HOW_DISAPPOINTING_COMPLETE
	msgbox gText_HowDisappointing_ExcellentWorkEverybody, , SPEAKER_ROSE, , EMOTE_HAPPY
	closemessage
	applymovement 4, Common_Movement_WalkUp
	applymovement 7, Common_Movement_WalkUp
	applymovement 5, Common_Movement_WalkRight
	fadescreen FADE_TO_BLACK
	delay 30
	call Salesforcetower_Leagueops_ClearSecondaryCharacters_Script
	fadescreen FADE_FROM_BLACK
	completequest QUEST_HOW_DISAPPOINTING
	release
	call ExhibitionBattle_TimeSkip_Script
	end


HowDisappointing_WalkIntoFormationNorthLeft_Movement:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

HowDisappointing_WalkIntoFormationNorthRight_Movement:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

HowDisappointing_WalkIntoFormationEast_Movement:
	walk_left
	step_end

HowDisappointing_WalkIntoFormationFinal_Movement:
	walk_down
	face_up
	step_end

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
	delay_16
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

HowDisappointing_EscapeA:
	delay_16
	walk_down
	walk_down
	walk_down
	face_left
	emote_exclamation_mark
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	step_end

HowDisappointing_EscapeB:
	delay_16
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

HowDisappointing_WalkToArrest:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

HowDisappointing_LeaveRoomA:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
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

gText_HowDisappointing_IAppreciate::
	.string "I appreciate you handling that,\n"
	.string "{PLAYER}.$"

gText_HowDisappointing_ImSupposed::
	.string "I'm supposed to wait outside.$"
