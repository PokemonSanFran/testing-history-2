Psfcity6_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity6_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity6_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_GYM_1_STATE
	case 3, Psfcity6_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

Psfcity6_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto EnterPsfleader1_StartGymBattle_ObjectSetup
	return


EnterPsfleader1_StartGymBattle_ObjectSetup::
	setobjectxyperm 1, 6, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	end


EnterPsfleader1_Event_Script::
	switch VAR_GYM_1_STATE
	case 3, EnterPsfleader1_Event_Script_2
	case 4, EnterPsfleader1_Event_Script_3
	case 5, EnterPsfleader1_Event_Script_4
	goto EnterPsfleader1_PutMeatInOven_Dialogue
	return

EnterPsfleader1_Event_Script_2:
	goto EnterPsfleader1_StartGymBattle_Script
	return

EnterPsfleader1_Event_Script_3:
	goto EnterPsfleader1_PostDefeat1_Dialogue
	return

EnterPsfleader1_Event_Script_4:
	goto EnterPsfleader1_PostDefeat2_Dialogue
	return


EnterPsfleader1_PutMeatInOven_Dialogue::
	lockall
	setvar VAR_GYM_1_STATE, 3
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_OneMoreLadle
	callnative ClearMugshot
	closemessage
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	applymovement 1, Common_Movement_WalkInPlaceUp
	waitmovement 0
	closemessage
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_MeatsInOven, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	call EnterPsfleader1_DetermineMovementToBattlefield
	goto EnterPsfleader1_Intro_Dialogue
	return


EnterPsfleader1_DetermineMovementToBattlefield::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 2
	goto_if_eq EnterPsfleader1_DetermineMovementToBattlefield_2
	applymovement 1, EnterPsfleader1_WalkWestToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader1_PlayerWalkToBattlefieldFromDown
EnterPsfleader1_DetermineMovementToBattlefield_1:
	waitmovement 0
	return

EnterPsfleader1_DetermineMovementToBattlefield_2:
	applymovement 1, EnterPsfleader1_WalkSouthToBattlefield
	compare VAR_TEMP_0, 7
	goto_if_eq EnterPsfleader1_DetermineMovementToBattlefield_5
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader1_PlayerWalkToBattlefieldFromRight
	goto EnterPsfleader1_DetermineMovementToBattlefield_1

EnterPsfleader1_DetermineMovementToBattlefield_5:
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader1_PlayerWalkToBattlefieldFromLeft
	goto EnterPsfleader1_DetermineMovementToBattlefield_1


EnterPsfleader1_Intro_Dialogue::
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_MyLatestCreation
	msgbox gText_EnterPsfleader1_YourSenseOfTaste
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader1_StartGymBattle_Script
	return


EnterPsfleader1_StartGymBattle_Script::
	givecustommon SPECIES_GRENINJA, 100, ITEM_ROCKY_HELMET, ITEM_ULTRA_BALL, NATURE_ADAMANT, 2, 0, 252, 0, 252, 6, 0, 31, 31, 31, 31, 31, 31, MOVE_WATER_SHURIKEN, MOVE_FEINT, MOVE_EARTHQUAKE, MOVE_PROTECT
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	trainerbattle_single TRAINER_ROXANNE_1, gText_EnterPsfleader1_IThinkYouTalk, gText_EnterPsfleader1_WoahSuperSour, EnterPsfleader1_Psfleader1Defeated_Script, NO_MUSIC
	return


EnterPsfleader1_Psfleader1Defeated_Script::
	lockall
	setflag FLAG_BADGE01_GET
	setvar VAR_GYM_1_STATE, 4
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_ThatWasDelicious
	callnative ClearMugshot
	msgbox gText_EnterPsfleader1_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM01
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_OhTheMeat
	callnative ClearMugshot
	closemessage
	call EnterPsfleader1_DetermineMovementBackToStove_Script
	waitmovement 0
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


EnterPsfleader1_DetermineMovementBackToStove_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 7
	goto_if_eq EnterPsfleader1_DetermineMovementBackToStove_Script_1
	applymovement 1, EnterPsfleader1_WalkEastBackToStove
	return

EnterPsfleader1_DetermineMovementBackToStove_Script_1:
	applymovement 1, EnterPsfleader1_WalkNorthBackToStove
	return


EnterPsfleader1_PostDefeat1_Dialogue::
	lockall
	setvar VAR_GYM_1_STATE, 5
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_WithThatBadge
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader1_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_FALKNER
	callnative DrawMugshot
	msgbox gText_EnterPsfleader1_LetsCookTogether
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader1_WalkSouthToBattlefield:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_left
	step_end

EnterPsfleader1_WalkWestToBattlefield:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_left
	step_end

EnterPsfleader1_PlayerWalkToBattlefieldFromLeft:
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

EnterPsfleader1_PlayerWalkToBattlefieldFromDown:
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

EnterPsfleader1_PlayerWalkToBattlefieldFromRight:
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

EnterPsfleader1_WalkEastBackToStove:
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

EnterPsfleader1_WalkNorthBackToStove:
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

gText_EnterPsfleader1_OneMoreLadle::
	.string "Hold on! I've got one more ladle of Pinap\n"
	.string "braising liquid, and then into the\l"
	.string "oven...$"

gText_EnterPsfleader1_MeatsInOven::
	.string "Cool, meat's in the oven.$"

gText_EnterPsfleader1_MyLatestCreation::
	.string "Ticket said you're {PLAYER}, right?\n"
	.string "I'm Psfleader1, head chef of Poc-Chuc\l"
	.string "and the Gym Leader here. After you\l"
	.string "lose, I'll treat you to my latest\l"
	.string "creation: Galifeu au Vin Burrito with a\l"
	.string "Pinap glaze. It's my first time making\l"
	.string "it, but from that amazing smell, it's\l"
	.string "gonna be great.$"

gText_EnterPsfleader1_YourSenseOfTaste::
	.string "Did you know that a lot of your sense of\n"
	.string "taste actually is because of your\l"
	.string "sense of smell? All of your senses work\l"
	.string "together to create your culinary\l"
	.string "experiences. I'll show how I do that in\l"
	.string "battle too! Let's see if I can\l"
	.string "overwhelm your palette before my meat\l"
	.string "burns!$"

gText_EnterPsfleader1_IThinkYouTalk::
	.string "I think you talk more about food than\n"
	.string "you do battling...$"

gText_EnterPsfleader1_FirstHitOfSpice::
	.string "Whoa, that felt just like the first hit\n"
	.string "of spice on the tip of my tongue!$"

gText_EnterPsfleader1_SimmerWasntEnough::
	.string "Guess a simmer wasn't enough - I've\n"
	.string "gotta crank it up to a rolling boil!$"

gText_EnterPsfleader1_WhatABitterDefeat::
	.string "Ouch, what a bitter defeat. Try adding\n"
	.string "Sitrus Berries?$"

gText_EnterPsfleader1_WoahSuperSour::
	.string "Woah, super sour! I'll add some Micle\n"
	.string "Berry.$"

gText_EnterPsfleader1_ThatWasDelicious::
	.string "That was delicious! I'm absolutely\n"
	.string "satiated. Here's the Psfbadge1, and my\l"
	.string "favorite Technical Machine.$"

gText_EnterPsfleader1_OhTheMeat::
	.string "Oh, the meat!$"

gText_EnterPsfleader1_BadgeGet::
	.string "You recieved the Psfbadge1 Badge!$"

gText_EnterPsfleader1_WithThatBadge::
	.string "With that Badge, traded Pokémon up to\n"
	.string "Level Psflevel1 will now obey you. And\l"
	.string "Psfgymattacknum1 is one of my most\l"
	.string "delicious moves, it allows your Pokémon\l"
	.string "to Psfgymattackdesc1.$"

gText_EnterPsfleader1_LetsCookTogether::
	.string "Let's cook together again soon! Now if\n"
	.string "you'll excuse me...$"
