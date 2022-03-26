TwoHoursAgo_ObjectSetUp::
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_1
	setobjectmovementtype 2, MOVEMENT_TYPE_WANDER_AROUND
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_gt TwoHoursAgo_ObjectSetUp_1
	return

TwoHoursAgo_ObjectSetUp_1:
	setflag FLAG_TEMP_2
	return


TwoHoursAgo_CameraToPlayer_Script::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 6
	special TeleportCamera
	return


TwoHoursAgo_FashionCaseReminder_Script::
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	lock
	msgbox gText_WhatOutfitDoYou
	special OpenPokeblockCaseOnFeeder
	waitstate
	msgbox gText_YouCanChangeYourOutfit
	closemessage
	release
	end


TwoHoursAgo_TheyreEager_Dialogue::
	msgbox gText_TwoHoursAgo_LooksLikeWokeUp, MSGBOX_NPC
	callnative ClearMugshot
	goto TwoHoursAgo_ExplainLeague_ObjectSetUp_Script
	return


TwoHoursAgo_ExplainLeague_ObjectSetUp_Script::
	lock
	fadescreen FADE_TO_BLACK
	setobjectxy 2, 4, 6
	turnobject 2, DIR_WEST
	setobjectnewmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	call TwoHoursAgo_CameraToPlayer_Script
	goto TwoHoursAgo_ExplainLeague_Script
	return


TwoHoursAgo_ExplainLeague_Script::
	setflag FLAG_RECIEVED_LEFTOVERS
	setflag FLAG_TEMP_1F
	lockall
	msgbox gText_TwoHoursAgo_YoureInARace
	msgbox gText_TwoHoursAgo_TheTouranemtnWillTest
	msgbox gText_TwoHoursAgo_WeExpectTheBest
	closemessage
	fadescreen FADE_FROM_BLACK
	goto TwoHoursAgo_LeftoversPokeballs_Dialogue
	return


TwoHoursAgo_LeftoversPokeballs_Dialogue::
	setflag FLAG_TEMP_1F
	callnative DrawMugshot
	msgbox gText_TwoHoursAgo_CafeIsAlwaysSoDelicious
	callnative ClearMugshot
	lockall
	giveitem ITEM_LEFTOVERS
	giveitem ITEM_POKE_BALL, 5
	closemessage
	releaseall
	end


TwoHoursAgo_ExplainLeftovers_Dialouge::
	bufferleadmonspeciesname 0
	msgbox gText_TwoHoursAgo_CanHoldThose, MSGBOX_NPC
	callnative ClearMugshot
	return


gText_WhatOutfitDoYou::
	.string "What outfit do you want to wear today?$"

gText_YouCanChangeYourOutfit::
	.string "You can change your outfit whenever\n"
	.string "you like by using the Fashion Case,\l"
	.string "found in your Bag's Key Items pocket.$"

gText_TwoHoursAgo_LooksLikeWokeUp::
	.string "Looks like Psftransrival woke up early\n"
	.string "and already left! They're eager, I'll\l"
	.string "give them that. I guess they didn't\l"
	.string "need the explanation... or breakfast.$"

gText_TwoHoursAgo_YoureInARace::
	.string "You're in a race against hundreds of\n"
	.string "other Pokémon Trainers, to see who can\l"
	.string "beat our 8 Gym Leaders first. The first\l"
	.string "16 Trainers to do so, will qualify for\l"
	.string "the Championship Tournament, held in a\l"
	.string "few weeks.$"

gText_TwoHoursAgo_TheTouranemtnWillTest::
	.string "The tournament will test all of your\n"
	.string "skills as a Trainer, but the win will\l"
	.string "become a Psfbadguy1 sponsored career\l"
	.string "Pokémon Trainer.$"

gText_TwoHoursAgo_WeExpectTheBest::
	.string "We expect the best from you and\n"
	.string "Psftransrival! If you fail to qualify\l"
	.string "for the Championship, we'll be\l"
	.string "terminating your contract, and you'll\l"
	.string "be on your own... but we know that won't\l"
	.string "be the case! So don't worry.$"

gText_TwoHoursAgo_CafeIsAlwaysSoDelicious::
	.string "Psfcompany2 is always so delicious! Too\n"
	.string "bad Psftransrival didn't eat with us. I\l"
	.string "guess you can take their portion of\l"
	.string "the food, and I bought you both\l"
	.string "PokéBalls, but you can have theirs too!$"

gText_TwoHoursAgo_CanHoldThose::
	.string "Your {STR_VAR_1} can hold those\n"
	.string "Leftovers to restore HP during battle.\l"
	.string "Now, you should get a move on! Don't let\l"
	.string "Psftransrival get too far ahead of\l"
	.string "you!$"