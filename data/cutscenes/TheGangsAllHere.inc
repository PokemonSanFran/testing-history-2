TheGangsAllHere_ObjectCleanUp_Script::
	call Salesforcetower_Leagueops_EmptyConferenceRoomOffices
	return


TheGangsAllHere_MidMission_Object_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setobjectxy 3, 6, 46
	setobjectxy 5, 5, 56
	setobjectxyperm 5, 5, 56
	return


TheGangsAllHere_ObjectSetup_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setobjectxy 5, 5, 56
	setobjectxyperm 5, 5, 56
	return


TheGangsAllHere_MoveOakToStairs_Script::
	addobject 3
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_DOWN
	setobjectxy 3, 16, 9
	setobjectxyperm 3, 16, 9
	return


TheGangsAllHere_OakAppearStairs_Script::
	lock
	playse SE_EXIT
	waitse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 16
	goto_if_eq TheGangsAllHere_OakAppearStairs_Script_2
	call TheGangsAllHere_MoveOakToStairs_Script
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 3, TheGangAllHere_WalkStairsToElevator_Movement
	waitmovement 3
TheGangsAllHere_OakAppearStairs_Script_1:
	goto TheGangsAllHere_WhatBringsYou_Dialogue
	return

TheGangsAllHere_OakAppearStairs_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, TheGangsAllHere_StepAsideOak_Movement
	waitmovement OBJ_EVENT_ID_PLAYER
	call TheGangsAllHere_MoveOakToStairs_Script
	applymovement 3, TheGangsAllHere_WalkStairs_FacePlayer_Movement
	waitmovement 3
	goto TheGangsAllHere_OakAppearStairs_Script_1


TheGangsAllHere_WhatBringsYou_Dialogue::
	lock
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, START_THE_GANGS_ALL_HERE
	playbgm MUS_RG_FOLLOW_ME, FALSE
	msgbox gText_TheGangsAllHere_WhatBringsYou, , SPEAKER_OAK
	msgbox gText_TheGangsAllHere_ToldMeToVisit, , SPEAKER_ZOEY
	msgbox gText_TheGangsAllHere_IsThisWhereYouWork, , SPEAKER_ZOEY
	msgbox gText_TheGangsAllHere_TheTowerYes, , SPEAKER_OAK
	msgbox gText_TheGangsAllHere_IHaventBeen, , SPEAKER_OAK
	msgbox gText_TheGangsAllHere_OfCourseNot, , SPEAKER_ZOEY
	closemessage
	special HealPlayerParty
	applymovement 3, FollowMe_Movement
	waitmovement 3
	setobjectxy 3, 6, 46
	setobjectxyperm 3, 6, 46
	fadedefaultbgm
	releaseall
	end


TheGangsAllHere_OfficeIsntThatWay_Script::
	lockall
	msgbox gText_TheGangsAllHere_OfficeIsntThatWay, , SPEAKER_OAK
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TheGangsAllHere_OfficeIsntThatWay_Movement
	return


TheGangsAllHere_WalkHallway_Script::
	applymovement 3, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	fadescreen FADE_TO_BLACK
	delay 30
	setobjectxy OBJ_EVENT_ID_PLAYER, 5, 52
	setobjectxy 3, 6, 52
	TeleportCamera 5, 52
	fadescreen FADE_FROM_BLACK
	return


TheGangsAllHere_ThisIsOffice_Script::
	lock
	faceplayer
	msgbox gText_TheGangsAllHere_ThisIsOffice, , SPEAKER_OAK
	closemessage
	call TheGangsAllHere_WalkHallway_Script
	goto TheGangsAllHere_ComeOnIn_Dialogue
	return


TheGangsAllHere_ComeOnIn_Dialogue::
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_THE_GANGS_ALL_HERE
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	playse SE_PIN
	applymovement 5, Common_Movement_ExclamationMark
	waitmovement 5
	applymovement 5, TheGangsAllHere_RoseWalkToDoor_Movement
	msgbox gText_TheGangsAllHere_ComeOnIn, , SPEAKER_ROSE
	closemessage
	msgbox gText_TheGangsAllHere_AsYouAsked, , SPEAKER_OAK
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 3, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_TheGangsAllHere_IThoughtYouSaid, , SPEAKER_ZOEY
	msgbox gText_TheGangsAllHere_IDidIsee, , SPEAKER_OAK
	goto TheGangsAllHere_NotIntentionally_Dialogue
	end


TheGangsAllHere_NotIntentionally_Dialogue::
	msgbox gText_TheGangsAllHere_NotIntentionally, , SPEAKER_ROSE
	compare VAR_SALESFORCETOWER_PRODUCTION_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	goto_if_eq TheGangsAllHere_NotIntentionally_Dialogue_2
TheGangsAllHere_NotIntentionally_Dialogue_1:
	msgbox gText_TheGangsAllHere_InAnyCase
	applymovement 3, Common_Movement_WalkInPlaceDown
	waitmovement 3
	msgbox gText_TheGangsAllHere_ImThrilledTheTiming, , SPEAKER_ROSE
	closemessage
	goto TheGangsAllHere_GiveDowsingMachine_Script
	end

TheGangsAllHere_NotIntentionally_Dialogue_2:
	msgbox gText_TheGangsAllHere_PleaseTellMe
	msgbox gText_TheGangsAllHere_IHeardWonderfulThings, , SPEAKER_OAK
	goto TheGangsAllHere_NotIntentionally_Dialogue_1


TheGangsAllHere_GiveDowsingMachine_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 5, TheGangsAllHere_GivePackageToPlayerChar_Movement
	waitmovement 5
	giveitem ITEM_DOWSING_MACHINE, 1
	goto TheGangsAllHere_GiveDowsingMachine_Dialogue
	end


TheGangsAllHere_GiveDowsingMachine_Dialogue::
	msgbox gText_TheGangsAllHere_TheVSSeekerWillAlert, , SPEAKER_ROSE
	applymovement 3, Common_Movement_FacePlayer
	waitmovement 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox gText_TheGangsAllHere_NotToPlaceAnyUndue, , SPEAKER_OAK
	msgbox gText_TheGangsAllHere_OhWowThatMeans, , SPEAKER_ZOEY
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	msgbox gText_TheGangsAllHere_WeKnowButNoPressure, , SPEAKER_ROSE
	goto TheGangsAllHere_EndScene_Dialogue
	return


TheGangsAllHere_EndScene_Dialogue::
	msgbox gText_TheGangsAllHere_TimeForNumber7
	closemessage
	applymovement 3, Common_Movement_FaceDown
	msgbox gText_TheGangsAllHere_WeShall, , SPEAKER_OAK
	applymovement 3, Common_Movement_FacePlayer
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	msgbox gText_TheGangsAllHere_FeelFreeToContinue, , SPEAKER_OAK
	compare VAR_SALESFORCETOWER_CONFERENCE_STATE, POST_ALWAYS_WATCHING_WAZOWSKI
	goto_if_ne TheGangsAllHere_EndScene_Dialogue_2
TheGangsAllHere_EndScene_Dialogue_1:
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TheGangsAllHere_WatchPairLeave_Movement
	applymovement 5, TheGangsAllHere_RoseWalkOut_Movement
	applymovement 3, TheGangsAllHere_OakWalkOut_Movement
	waitmovement 3
	fadedefaultbgm
	removeobject 5
	removeobject 3
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	release
	end

TheGangsAllHere_EndScene_Dialogue_2:
	msgbox gText_TheGangsAllHere_AhAndIf
	goto TheGangsAllHere_EndScene_Dialogue_1


TheGangsAllHere_OakWalkToPlayer_Movement:
	face_right
	step_end

TheGangsAllHere_OfficeIsntThatWay_Movement:
	walk_down
	step_end

TheGangsAllHere_ThisIsOffice_Movement:
	walk_right
	walk_right
	walk_right
	step_end

TheGangsAllHere_RoseWalkToDoor_Movement:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_left
	face_up
	step_end

TheGangsAllHere_GivePackageToPlayerChar_Movement:
	walk_left
	face_up
	walk_in_place_up
	step_end

TheGangsAllHere_WatchPairLeave_Movement:
	delay_16
	delay_16
	face_up
	step_end

TheGangsAllHere_RoseWalkOut_Movement:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TheGangsAllHere_OakWalkOut_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

FollowMe_Movement:
	walk_left
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

TheGangsAllHere_StepAsideOak_Movement:
	walk_down
	walk_right
	face_left
	step_end

TheGangsAllHere_WalkStairs_FacePlayer_Movement:
	walk_down
	walk_down
	emote_exclamation_mark
	face_right
	step_end

TheGangAllHere_WalkStairsToElevator_Movement:
	walk_down
	walk_right
	walk_right
	step_end

gText_TheGangsAllHere_WhatBringsYou::
	.string "{PLAYER}! What brings you to League\n"
	.string "HQ?$"

gText_TheGangsAllHere_ToldMeToVisit::
	.string "Commissioner Rose told me to visit\n"
	.string "after I beat Whitney!$"

gText_TheGangsAllHere_IsThisWhereYouWork::
	.string "Is this where you work?$"

gText_TheGangsAllHere_TheTowerYes::
	.string "My office is on this floor, yeah! This is\n"
	.string "League Ops, and everybody here is\l"
	.string "solely dedicated to making sure the\l"
	.string "Ycombinator Pokemon League is a\l"
	.string "success.$"

gText_TheGangsAllHere_IHaventBeen::
	.string "I've an important delivery for the\n"
	.string "C.E.O., but the workers here in League\l"
	.string "Ops can be a little... rowdy. Do you mind\l"
	.string "if I tag along on your tour? I'll keep\l"
	.string "you in tip-top shape!$"

gText_TheGangsAllHere_OfCourseNot::
	.string "Of course not!$"

gText_TheGangsAllHere_OfficeIsntThatWay::
	.string "Hey {PLAYER}, the office isn't that\n"
	.string "way!$"

gText_TheGangsAllHere_ThisIsOffice::
	.string "This is Rose's office. After you.$"

gText_TheGangsAllHere_ComeOnIn::
	.string "{PLAYER}! Oak! Come on in, I just\n"
	.string "finished an email! Glad you're both\l"
	.string "here, and excellent timing that you ran\l"
	.string "into each other.$"

gText_TheGangsAllHere_AsYouAsked::
	.string "As you asked, I have your package.$"

gText_TheGangsAllHere_IThoughtYouSaid::
	.string "I thought you said you had a delivery\n"
	.string "for the C.E.O.?$"

gText_TheGangsAllHere_IDidIsee::
	.string "I did. I see Rose neglected to reveal\n"
	.string "his full title...?$"

gText_TheGangsAllHere_NotIntentionally::
	.string "Not intentionally! I was just so swept\n"
	.string "up in your battle!$"

gText_TheGangsAllHere_PleaseTellMe::
	.string "Oak, please tell me you'll go back and\n"
	.string "watch Sabrina's highlight reel later, it\l"
	.string "was fantastic.$"

gText_TheGangsAllHere_LikeISaidWe::
	.string "Like I said, we wear a lot of hats.$"

gText_TheGangsAllHere_IHeardWonderfulThings::
	.string "I heard wonderful things on the way\n"
	.string "over here, but I'll be certain to\l"
	.string "observe later.$"

gText_TheGangsAllHere_InAnyCase::
	.string "In any case, your pacakge, Rose.$"

gText_TheGangsAllHere_ImThrilledTheTiming::
	.string "I'm thrilled the timing worked out,\n"
	.string "because the package actually isn't for\l"
	.string "me!$"

gText_TheGangsAllHere_TheVSSeekerWillAlert::
	.string "The VS Seeker will alert Trainers in the\n"
	.string "area that you want a rematch. It uses\l"
	.string "steps to charge, so I guess you'll burn\l"
	.string "some calories alongside your Pokémon.\l"
	.string "I'm excited to see how you use our\l"
	.string "tools!$"

gText_TheGangsAllHere_NotToPlaceAnyUndue::
	.string "Not to place any undue pressure on you,\n"
	.string "but we personally reviewed all of the\l"
	.string "applicants to our little program. You\l"
	.string "were exceptionally popular among the\l"
	.string "team, so we're very excited to see you\l"
	.string "perform well!$"

gText_TheGangsAllHere_OhWowThatMeans::
	.string "Oh. Wow! That means a lot. I'll\n"
	.string "absolutely put it to use!$"

gText_TheGangsAllHere_WeKnowButNoPressure::
	.string "We know. But no pressure. Enjoy your\n"
	.string "journey!$"

gText_TheGangsAllHere_TimeForNumber7::
	.string "Time for Starbucks coffee number 7.\n"
	.string "Shall we, Oak?$"

gText_TheGangsAllHere_WeShall::
	.string "We shall.$"

gText_TheGangsAllHere_FeelFreeToContinue::
	.string "Feel free to continue your tour without\n"
	.string "us, {PLAYER}. Greatly appreciate your\l"
	.string "help in the battles. Hopefully\l"
	.string "supporting me wasn't too exhausting!$"

gText_TheGangsAllHere_AhAndIf::
	.string "Ah, and if you haven't already visited\n"
	.string "Sabrina, go do so. They're on Marketing,\l"
	.string "the second floor.$"
