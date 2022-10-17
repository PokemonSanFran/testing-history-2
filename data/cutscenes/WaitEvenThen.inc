WaitEvenThen_TurnOnMachine_Script::
	setmetatile 32, 2, 0x2D8, TRUE
	setmetatile 33, 2, 0x2D9, TRUE
	setmetatile 34, 2, 0x2DA, TRUE
	setmetatile 35, 2, 0x2DB, TRUE
	setmetatile 32, 3, 0x2E0, TRUE
	setmetatile 33, 3, 0x2E1, TRUE
	setmetatile 34, 3, 0x2E2, TRUE
	setmetatile 35, 3, 0x2E3, TRUE
	special DrawWholeMapView
	return


WaitEvenThen_BossSetUp_Script::
	clearflag FLAG_TEMP_1
	addobject 2
	addobject 3
	addobject 1
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP
	setobjectxyperm 3, 39, 4
	setobjectxy 3, 39, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectxy 1, 34, 6
	setobjectxyperm 1, 34, 6
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	setobjectxy 2, 33, 7
	setobjectxyperm 2, 33, 7
	setobjectxy 6, 33, 5
	setobjectxyperm 6, 33, 5
	return


WaitEvenThen_ObjectSetUp_Script::
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 25, 4
	TeleportCamera 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	clearflag FLAG_TEMP_1
	addobject 1
	setobjectxy 1, 25, 5
	applymovement 1, Common_Movement_FaceRight
	addobject 2
	setobjectxy 2, 24, 4
	applymovement 2, Common_Movement_FaceRight
	addobject 3
	setobjectxy 3, 24, 5
	applymovement 3, Common_Movement_FaceRight
	fadescreen FADE_FROM_BLACK
	return


WaitEvenThen_PrepareBossEncounter_Dialogue::
	lock
	call WaitEvenThen_ObjectSetUp_Script
	applymovement OBJ_EVENT_ID_PLAYER, WaitEvenThen_WalkToSleepingA
	applymovement 1, WaitEvenThen_WalkToSleepingB
	applymovement 2, WaitEvenThen_WalkToSleepingC
	applymovement 3, WaitEvenThen_WalkToSleepingD
	waitmovement 3
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_IFoundTheAccess
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_AndICanHandle
	callnative ClearMugshot
	closemessage
	applymovement 3, WaitEvenThen_WalkToComputer
	waitmovement 3
	playse SE_PC_LOGIN
	waitse
	delay 10
	playse SE_PC_ON
	waitse
	call WaitEvenThen_TurnOnMachine_Script
	applymovement 6, Common_Movement_WalkDown
	playmoncry SPECIES_EXCADRILL, CRY_MODE_ENCOUNTER
	waitmoncry
	setvar VAR_UNDERGROUNDLAB_STATE, SAVE_BEFORE_DYNAMAX
	msgbox gText_IGuessWeShouldBeNiceNow_Roar, MSGBOX_AUTOCLOSE
	setobjectxy 1, 34, 6
	setobjectxyperm 1, 34, 6
	setobjectxy 2, 33, 7
	setobjectxyperm 2, 33, 7
	setobjectxyperm 3, 39, 4
	setobjectxy 3, 39, 4
	setobjectnewmovementtype 3, MOVEMENT_TYPE_FACE_UP
	call Common_EventScript_SaveGame
	goto WaitEvenThen_BossEncounter_Script
	return


WaitEvenThen_MovePlayerToBoss::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 33
	goto_if_ne WaitEvenThen_MovePlayerToBoss_2
	compare VAR_TEMP_1, 6
	goto_if_ne WaitEvenThen_MovePlayerToBoss_2
WaitEvenThen_MovePlayerToBoss_1:
	goto WaitEvenThen_BossEncounter_Script
	return

WaitEvenThen_MovePlayerToBoss_2:
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 33, 6
	TeleportCamera 33, 6
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	fadescreen FADE_FROM_BLACK
	goto WaitEvenThen_MovePlayerToBoss_1


WaitEvenThen_BossEncounter_Script::
	setwildbattle SPECIES_EXCADRILL, 70, ITEM_MUSCLE_BAND, SPECIES_NONE
	playmoncry SPECIES_EXCADRILL, CRY_MODE_ENCOUNTER
	msgbox gText_IGuessWeShouldBeNiceNow_Roar, MSGBOX_AUTOCLOSE
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	multi_fixed_wild TRAINER_WALLY_VR_2, TRAINER_BACK_PIC_WALLY
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, WaitEvenThen_BossEncounter_Script_3
	case B_OUTCOME_WON, WaitEvenThen_BossEncounter_Script_3
WaitEvenThen_BossEncounter_Script_1:
	release
	end

WaitEvenThen_BossEncounter_Script_3:
	goto WaitEvenThen_ClearBossPokemon_Script
	goto WaitEvenThen_BossEncounter_Script_1


WaitEvenThen_ClearBossPokemon_Script::
	setvar VAR_UNDERGROUNDLAB_STATE, DEFEATED_DYNAMAX
	lock
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject 6
	fadescreenswapbuffers FADE_FROM_BLACK
	goto WaitEvenThen_PostBossDialogue
	return


WaitEvenThen_PostBossDialogue::
	lock
	setvar VAR_STORYLINE_STATE, STORY_POST_DYNAMAX_BOSS
	setvar VAR_ALAMEDA_STATE, POST_THIS_ISNT_RANDOM
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 1, Common_Movement_FaceDown
	applymovement 3, Common_Movement_FaceDown
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_DamnAPowerSpot
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_AndTheGovernment
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_IllHaveSomeOther
	callnative ClearMugshot
	closemessage
	applymovement 3, WaitEvenThen_LeaveLabA
	applymovement 2, WaitEvenThen_LeaveLabB
	waitmovement 2
	applymovement 1, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_ComingWithMe, MSGBOX_YESNO
	callnative ClearMugshot
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq WaitEvenThen_PostBossDialogue_2
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WaitEvenThen_MeetUsIn
	closemessage
	callnative ClearMugshot
	applymovement 1, WaitEvenThen_WalkAwayFromPlayer
	waitmovement 1
	removeobject 1
	removeobject 3
	removeobject 2
	release
	end

WaitEvenThen_PostBossDialogue_2:
	warp MAP_ALAMEDA, 255, 34, 13
	end


WaitEvenThen_WalkToSleepingA:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	face_up
	step_end

WaitEvenThen_WalkToSleepingB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

WaitEvenThen_WalkToSleepingC:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	face_up
	step_end

WaitEvenThen_WalkToSleepingD:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

WaitEvenThen_WalkToComputer:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
	step_end

WaitEvenThen_LeaveLabA:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WaitEvenThen_LeaveLabB:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WaitEvenThen_WalkAwayFromPlayer:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

gText_WaitEvenThen_IFoundTheAccess::
	.string "I found the access commands. I think I\n"
	.string "can turn this off, but I’m certain that\l"
	.string "it's going to attack us when we do.$"

gText_WaitEvenThen_AndICanHandle::
	.string "{PLAYER} and I can handle it. Let it\n"
	.string "rip!$"

gText_WaitEvenThen_Yerrrraaaa::
	.string "Yerrrraaaaaa!$"

gText_WaitEvenThen_DamnAPowerSpot::
	.string "Damn, a Power Spot, all the way out\n"
	.string "here?$"

gText_WaitEvenThen_AndTheGovernment::
	.string "Between Ycombinator and the\n"
	.string "government, I guess nothing is off\l"
	.string "limits.$"

gText_WaitEvenThen_IllHaveSomeOther::
	.string "I’ll have some other TeamRocket members\n"
	.string "clear out the rest of the trapped\l"
	.string "Pokémon… Let’s go back to Alameda.$"

gText_WaitEvenThen_ComingWithMe::
	.string "Coming with me, {PLAYER}?$"

gText_WaitEvenThen_MeetUsIn::
	.string "Meet us in the center of town, okay?$"
