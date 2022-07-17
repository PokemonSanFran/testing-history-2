EnterFalkner_StartGymBattle_ObjectSetup_Script::
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


EnterFalkner_PutMeatInOven_Dialogue::
	lockall
	addvar VAR_GYM_1_STATE, 1
	addvar VAR_GYM_1_STATE, 1
	addvar VAR_GYM_1_STATE, 1
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_OneMoreLadle
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	closemessage
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_MeatsInOven, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	call EnterFalkner_DetermineMovementToBattlefield_Script
	goto EnterFalkner_Intro_Dialogue
	return


EnterFalkner_DetermineMovementToBattlefield_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 2
	goto_if_eq EnterFalkner_DetermineMovementToBattlefield_Script_2
	applymovement 1, EnterFalkner_WalkWestToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterFalkner_PlayerWalkToBattlefieldFromDown
EnterFalkner_DetermineMovementToBattlefield_Script_1:
	waitmovement 0
	return

EnterFalkner_DetermineMovementToBattlefield_Script_2:
	applymovement 1, EnterFalkner_WalkSouthToBattlefield
	compare VAR_TEMP_0, 7
	goto_if_eq EnterFalkner_DetermineMovementToBattlefield_Script_5
	applymovement OBJ_EVENT_ID_PLAYER, EnterFalkner_PlayerWalkToBattlefieldFromRight
	goto EnterFalkner_DetermineMovementToBattlefield_Script_1

EnterFalkner_DetermineMovementToBattlefield_Script_5:
	applymovement OBJ_EVENT_ID_PLAYER, EnterFalkner_PlayerWalkToBattlefieldFromLeft
	goto EnterFalkner_DetermineMovementToBattlefield_Script_1


EnterFalkner_Intro_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_MyLatestCreation
	msgbox gText_EnterFalkner_YourSenseOfTaste
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterFalkner_StartGymBattle_Script
	return


EnterFalkner_StartGymBattle_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	trainerbattle_single TRAINER_ROXANNE_1, gText_EnterFalkner_IThinkYouTalk, gText_EnterFalkner_WoahSuperSour, EnterFalkner_FalknerDefeated_Script, NO_MUSIC
	return


EnterFalkner_FalknerDefeated_Script::
	lockall
	setflag FLAG_BADGE01_GET
	addvar VAR_GYM_1_STATE, 1
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_ThatWasDelicious
	callnative ClearMugshot
	msgbox gText_EnterFalkner_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM01
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_OhTheMeat
	callnative ClearMugshot
	closemessage
	call EnterFalkner_DetermineMovementBackToStove_Script
	waitmovement 0
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


EnterFalkner_DetermineMovementBackToStove_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 7
	goto_if_eq EnterFalkner_DetermineMovementBackToStove_Script_1
	applymovement 1, EnterFalkner_WalkEastBackToStove
	return

EnterFalkner_DetermineMovementBackToStove_Script_1:
	applymovement 1, EnterFalkner_WalkNorthBackToStove
	return


EnterFalkner_PostDefeat1_Dialogue::
	lockall
	addvar VAR_GYM_1_STATE, 1
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_WithThatBadge, MSGBOX_NPC
	callnative ClearMugshot
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	closemessage
	releaseall
	end


EnterFalkner_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterFalkner_LetsCookTogether
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterFalkner_WalkSouthToBattlefield:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

EnterFalkner_WalkWestToBattlefield:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_left
	step_end

EnterFalkner_PlayerWalkToBattlefieldFromLeft:
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_right
	step_end

EnterFalkner_PlayerWalkToBattlefieldFromDown:
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	face_right
	step_end

EnterFalkner_PlayerWalkToBattlefieldFromRight:
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_right
	step_end

EnterFalkner_WalkEastBackToStove:
	emote_exclamation_mark
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	face_up
	walk_left
	face_up
	step_end

EnterFalkner_WalkNorthBackToStove:
	emote_exclamation_mark
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	walk_left
	face_up
	step_end

gText_EnterFalkner_OneMoreLadle::
	.string "Hold on! I've got one more ladle of Pinap\n"
	.string "braising liquid, and then into the\l"
	.string "oven...$"

gText_EnterFalkner_MeatsInOven::
	.string "Cool, meat's in the oven.$"

gText_EnterFalkner_MyLatestCreation::
	.string "Ticket said you're {PLAYER}, right?\n"
	.string "I'm Falkner, head chef of Poc-Chuc and\l"
	.string "the Gym Leader here. After you lose,\l"
	.string "I'll treat you to my latest creation:\l"
	.string "Galifeu au Vin Burrito with a Pinap\l"
	.string "glaze. It's my first time making it, but\l"
	.string "from that amazing smell, it's gonna be\l"
	.string "great.$"

gText_EnterFalkner_YourSenseOfTaste::
	.string "Did you know that a lot of your sense of\n"
	.string "taste actually is because of your\l"
	.string "sense of smell? All of your senses work\l"
	.string "together to create your culinary\l"
	.string "experiences. I'll show how I do that in\l"
	.string "battle too! Let's see if I can\l"
	.string "overwhelm your palette before my meat\l"
	.string "burns!$"

gText_EnterFalkner_IThinkYouTalk::
	.string "I think you talk more about food than\n"
	.string "you do battling...$"

gText_EnterFalkner_FirstHitOfSpice::
	.string "Whoa, that felt just like the first hit\n"
	.string "of spice on the tip of my tongue!$"

gText_EnterFalkner_SimmerWasntEnough::
	.string "Guess a simmer wasn't enough - I've\n"
	.string "gotta crank it up to a rolling boil!$"

gText_EnterFalkner_WhatABitterDefeat::
	.string "Ouch, what a bitter defeat. Try adding\n"
	.string "Sitrus Berries?$"

gText_EnterFalkner_WoahSuperSour::
	.string "Woah, super sour! I'll add some Micle\n"
	.string "Berry.$"

gText_EnterFalkner_ThatWasDelicious::
	.string "That was delicious! I'm absolutely\n"
	.string "satiated. Here's the FalknerBadge, and\l"
	.string "my favorite Technical Machine.$"

gText_EnterFalkner_OhTheMeat::
	.string "Oh, the meat!$"

gText_EnterFalkner_BadgeGet::
	.string "You recieved the FalknerBadge Badge!$"

gText_EnterFalkner_WithThatBadge::
	.string "With that Badge, traded Pokémon up to\n"
	.string "Level Psflevel1 will now obey you. And\l"
	.string "Psfgymattacknum1 is one of my most\l"
	.string "delicious moves, it allows your Pokémon\l"
	.string "to Psfgymattackdesc1.$"

gText_EnterFalkner_LetsCookTogether::
	.string "Let's cook together again soon! Now if\n"
	.string "you'll excuse me...$"
