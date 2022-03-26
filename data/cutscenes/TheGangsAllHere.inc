TheGangsAllHere_ObjectCleanUp_Script::
	setflag FLAG_TEMP_2
	return


TheGangsAllHere_WhatBringsYou_Dialogue::
	lock
	addvar VAR_PSFCITY15_STATE, 1
	playse SE_PIN
	playbgm MUS_RG_FOLLOW_ME, FALSE
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_WhatBringsYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_ToldMeToVisit
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_IsThisWhereYouWork
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_TheTowerYes
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_IHaventBeen
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_OfCourseNot
	callnative ClearMugshot
	closemessage
	special HealPlayerParty
	applymovement 4, FollowMe_Movement
	waitmovement 0
	setobjectxyperm 4, 6, 25
	fadedefaultbgm
	releaseall
	end


TheGangsAllHere_OfficeIsntThatWay_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_OfficeIsntThatWay
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TheGangsAllHere_OfficeIsntThatWay_Movement
	return


TheGangsAllHere_ThisIsOffice_Script::
	applymovement 4, FollowPlaceholder_Movement
	waitmovement 0
	applymovement 4, Common_Movement_FaceRight
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_ThisIsOffice
	closemessage
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, TheGangsAllHere_ThisIsOffice_Movement
	applymovement 4, TheGangsAllHere_ThisIsOffice_Movement
	waitmovement 0
	goto TheGangsAllHere_ComeOnIn_Dialogue
	end


TheGangsAllHere_ComeOnIn_Dialogue::
	addvar VAR_PSFCITY15_STATE, 1
	playbgm MUS_RG_ENCOUNTER_DEOXYS, FALSE
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 3, TheGangsAllHere_PsfbadbossWalkToDoor_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_ComeOnIn
	closemessage
	callnative ClearMugshot
	applymovement 4, TheGangsAllHere_PsfbadadminWalkToDesk_Movement
	waitmovement 0
	applymovement 3, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_AsYouAsked
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_IThoughtYouSaid
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_IDidIsee
	callnative ClearMugshot
	goto TheGangsAllHere_NotIntentionally_Dialogue
	end


TheGangsAllHere_NotIntentionally_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_NotIntentionally
	callnative ClearMugshot
	applymovement 4, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_LikeISaidWe
	callnative ClearMugshot
	applymovement 4, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_IHeardWonderfulThings
	callnative ClearMugshot
	applymovement 3, Common_Movement_FaceDown
	applymovement 4, TheGangsAllHere_GivePackageToPsfbadboss_Movement
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_ImThrilledTheTiming
	closemessage
	callnative ClearMugshot
	goto TheGangsAllHere_GiveDowsingMachine_Script
	end


TheGangsAllHere_GiveDowsingMachine_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 3, TheGangsAllHere_GivePackageToPsfchara1_Movement
	waitmovement 0
	giveitem ITEM_DOWSING_MACHINE, 1
	goto TheGangsAllHere_GiveDowsingMachine_Dialogue
	end


TheGangsAllHere_GiveDowsingMachine_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_TheVSSeekerWillAlert
	callnative ClearMugshot
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_NotToPlaceAnyUndue
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_OhWowThatMeans
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_WeKnowButNoPressure
	closemessage
	callnative ClearMugshot
	goto TheGangsAllHere_EndScene_Dialogue
	end


TheGangsAllHere_EndScene_Dialogue::
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_TimeForNumber7
	setvar VAR_0x8000, MUGSHOT_LANCE
	applymovement 3, Common_Movement_FaceDown
	applymovement 4, Common_Movement_FaceUp
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_WeShall
	callnative ClearMugshot
	applymovement 4, Common_Movement_FaceLeft
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheGangsAllHere_FeelFreeToContinue
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, TheGangsAllHere_MoveOutOfWay_Movement
	waitmovement 0
	applymovement 3, TheGangsAllHere_PsfbadbossWalkOut_Movement
	applymovement 4, TheGangsAllHere_PsfbadadminWalkOut_Movement
	waitmovement 0
	fadedefaultbgm
	removeobject 3
	removeobject 4
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	release
	end


Psfbadguy1Tower_10F_EventScript_Tom::
	trainerbattle_double TRAINER_ALVARO, Route104_Text_GinaIntro, Route104_Text_GinaDefeat, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_GinaPostBattle, MSGBOX_DEFAULT
	release
	end


Psfbadguy1Tower_10F_EventScript_Ian::
	trainerbattle_double TRAINER_RED, Route104_Text_MiaIntro, Route104_Text_MiaDefeat, Route104_Text_MiaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_MiaPostBattle, MSGBOX_DEFAULT
	release
	end


TheGangsAllHere_PsfbadadminWalkToZoey_Movement:
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

FollowPlaceholder_Movement:
	walk_down
	step_end

TheGangsAllHere_PsfbadbossWalkToDoor_Movement:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

TheGangsAllHere_PsfbadadminWalkToDesk_Movement:
	walk_down
	walk_right
	walk_right
	face_up
	delay_16
	delay_16
	step_end

TheGangsAllHere_GivePackageToPsfbadboss_Movement:
	walk_in_place_up
	step_end

TheGangsAllHere_GivePackageToPsfchara1_Movement:
	face_left
	walk_in_place_left
	step_end

TheGangsAllHere_MoveOutOfWay_Movement:
	walk_up
	face_down
	step_end

TheGangsAllHere_PsfbadbossWalkOut_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TheGangsAllHere_PsfbadadminWalkOut_Movement:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
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

gText_TheGangsAllHere_WhatBringsYou::
	.string "{PLAYER}! What brings you to League\n"
	.string "HQ?$"

gText_TheGangsAllHere_ToldMeToVisit::
	.string "Commissioner Psfbadboss told me to\n"
	.string "visit after I beat Psfleader3!$"

gText_TheGangsAllHere_IsThisWhereYouWork::
	.string "Is this where you work?$"

gText_TheGangsAllHere_TheTowerYes::
	.string "The Psfcompany3 Tower? Yes! League\n"
	.string "Ops? ...sort of. We wear a lot of hats!$"

gText_TheGangsAllHere_IHaventBeen::
	.string "I haven't been up here in a while\n"
	.string "though. I've an important delivery for\l"
	.string "the C.E.O., but the workers here in\l"
	.string "League Ops can be a little... rowdy. Do\l"
	.string "you mind if I tag along on your tour?\l"
	.string "I'll keep you in tip-top shape!$"

gText_TheGangsAllHere_OfCourseNot::
	.string "Of course not!$"

gText_TheGangsAllHere_OfficeIsntThatWay::
	.string "Hey {PLAYER}, the office isn't that\n"
	.string "way!$"

gText_TheGangsAllHere_ThisIsOffice::
	.string "This is Psfbadboss's office. After you.$"

gText_TheGangsAllHere_ComeOnIn::
	.string "{PLAYER}! Psfbadadmin! Come on in, I\n"
	.string "just finished an email! Glad you're both\l"
	.string "here, and excellent timing that you ran\l"
	.string "into each other.$"

gText_TheGangsAllHere_AsYouAsked::
	.string "As you asked, although I must say, it\n"
	.string "was not quite where you specified...$"

gText_TheGangsAllHere_IThoughtYouSaid::
	.string "I thought you said you had a delivery\n"
	.string "for the C.E.O.?$"

gText_TheGangsAllHere_IDidIsee::
	.string "I did. I see Psfbadboss neglected to\n"
	.string "reveal his full title...?$"

gText_TheGangsAllHere_NotIntentionally::
	.string "Not intentionally! I was just so swept\n"
	.string "up in your battle! Psfbadadmin, please\l"
	.string "tell me you'll go back and watch\l"
	.string "Psfbadadmin3's highlight reel later, it\l"
	.string "was fantastic.$"

gText_TheGangsAllHere_LikeISaidWe::
	.string "Like I said, we wear a lot of hats.$"

gText_TheGangsAllHere_IHeardWonderfulThings::
	.string "I heard wonderful things on the way\n"
	.string "over here, but I'll be certain to\l"
	.string "observe later. In any case, your\l"
	.string "package, Psfbadboss.$"

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
	.string "Time for Psfcompany4 number 7. Shall we,\n"
	.string "Psfbadadmin?$"

gText_TheGangsAllHere_WeShall::
	.string "We shall.$"

gText_TheGangsAllHere_FeelFreeToContinue::
	.string "Feel free to continue your tour without\n"
	.string "us, Zoey. Greatly appreciate your help\l"
	.string "in the battles. Hopefully supporting me\l"
	.string "wasn't too exhausting! Ah, and if you\l"
	.string "haven't already visited Psfbadadmin3,\l"
	.string "go do so. They're on Marketing, the\l"
	.string "second floor.$"