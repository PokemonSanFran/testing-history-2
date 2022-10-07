TwoHoursAgo_ObjectSetUp::
	setflag FLAG_TEMP_1
	setobjectmovementtype 2, MOVEMENT_TYPE_WANDER_AROUND
	compare VAR_PLAYER_HOME_STATE, OPENED_FASHION_CASE
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
	setvar VAR_PLAYER_HOME_STATE, OPENED_FASHION_CASE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhatOutfitDoYou
	callnative ClearMugshot
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
	.string "Oh, I should get dressed!$"

gText_YouCanChangeYourOutfit::
	.string "You can change your outfit whenever\n"
	.string "you like by using the Fashion Case,\l"
	.string "found in your Bag's Key Items pocket.$"

gText_TwoHoursAgo_LooksLikeWokeUp::
	.string "Looks like Bianca woke up early and\n"
	.string "already left! They're eager, I'll give\l"
	.string "them that. I guess they didn't need the\l"
	.string "explanation... or breakfast.$"

gText_TwoHoursAgo_YoureInARace::
	.string "You're in a race against hundreds of\n"
	.string "other Pokémon Trainers, to see who can\l"
	.string "beat our 8 Gym Leaders first. The first\l"
	.string "16 Trainers to do so, will qualify for\l"
	.string "the Championship Tournament, held in a\l"
	.string "few weeks.$"

gText_TwoHoursAgo_TheTouranemtnWillTest::
	.string "The tournament will test all of your\n"
	.string "skills as a Trainer, but the winner will\l"
	.string "become a Ycombinator-sponsored\l"
	.string "career Pokémon Trainer.$"

gText_TwoHoursAgo_WeExpectTheBest::
	.string "We expect the best from you and Bianca!\n"
	.string "If you fail to qualify for the\l"
	.string "Championship, we'll be terminating your\l"
	.string "contract, and you'll be on your own...\l"
	.string "but we know that won't be the case! So\l"
	.string "don't worry.$"

gText_TwoHoursAgo_CafeIsAlwaysSoDelicious::
	.string "CafeVenetia is always so delicious! Too\n"
	.string "bad Bianca didn't eat with us. I guess\l"
	.string "you can take their portion of the food,\l"
	.string "and I bought you both PokéBalls, but\l"
	.string "you can have theirs too!$"

gText_TwoHoursAgo_CanHoldThose::
	.string "Your {STR_VAR_1} can hold those\n"
	.string "Leftovers to restore HP during battle.\l"
	.string "Now, you should get a move on! Don't let\l"
	.string "Bianca get too far ahead of you!$"
