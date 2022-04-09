GroupStages_Lockers_ObjectSetUp_Script::
	setobjectxyperm 2, 10, 3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_6
	return


GroupStages_Lockers_ObjectCleanUp_Script::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	return


GroupStages_Skybox_ObjectSetup_Script::
	setobjectxyperm 8, 16, 6
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_DOWN
	return


GroupStages_GreetBeforeStart_Dialogue::
	lock
	applymovement 2, GroupStages_WalkToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_GroupStages_Blank
	closemessage
	callnative ClearMugshot
	applymovement 2, GroupStages_LeaveLockers
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 2
	fadedefaultbgm
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_ROUTE119_STATE, 1
	release
	end


GroupStages_PreparePlayer_Script::
	lock
	faceplayer
	msgbox gText_GroupStages_OnceYouStart, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq GroupStages_PreparePlayer_Script_2
GroupStages_PreparePlayer_Script_1:
	release
	end

GroupStages_PreparePlayer_Script_2:
	call GroupStages_ChooseParty_Script
	setflag FLAG_PSFPLACE14_TOURNAMENT_HAPPENING
	call GroupStages_MoveObjects_Script
	compare VAR_ROUTE119_STATE, 4
	goto_if_ne GroupStages_PreparePlayer_Script_5
GroupStages_PreparePlayer_Script_4:
	warpsilent MAP_PSFPLACE14_ARENA, 255, 5, 6
	goto GroupStages_PreparePlayer_Script_1

GroupStages_PreparePlayer_Script_5:
	setvar VAR_ROUTE119_STATE, 1
	goto GroupStages_PreparePlayer_Script_4


GroupStages_MoveObjects_Script::
	applymovement 5, Common_Movement_WalkInPlaceUp
	opendoor 10, 1
	waitdooranim
	applymovement 5, Common_Movement_WalkUp
	playse SE_EXIT
	waitse
	removeobject 5
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 9, GroupStages_MoveObjects_Script_3
	case 10, GroupStages_MoveObjects_Script_4
	case 11, GroupStages_MoveObjects_Script_5
GroupStages_MoveObjects_Script_1:
	waitmovement 0
	playse SE_EXIT
	return

GroupStages_MoveObjects_Script_3:
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_PlayerLeaveLockers_Left
	goto GroupStages_MoveObjects_Script_1

GroupStages_MoveObjects_Script_4:
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_PlayerLeaveLockers
	goto GroupStages_MoveObjects_Script_1

GroupStages_MoveObjects_Script_5:
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_PlayerLeaveLockers_Right
	goto GroupStages_MoveObjects_Script_1


GroupStages_ChooseParty_Script::
	special SavePlayerParty
	frontier_set FRONTIER_DATA_LVL_MODE, 2
	setvar VAR_0x8005, 3
	special ChoosePartyForBattleFrontier
	waitstate
	dome_reduceparty
	return


GroupStages_RoundRobinMatch_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_GroupStages_Blank
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	msgbox gText_GroupStages_Blank
	closemessage
	switch VAR_ROUTE119_STATE
	case 1, GroupStages_RoundRobinMatch_Script_3
	case 2, GroupStages_RoundRobinMatch_Script_4
	case 3, GroupStages_RoundRobinMatch_Script_5
GroupStages_RoundRobinMatch_Script_1:
	goto GroupStages_PostRoundRobinMatch_Script
	return

GroupStages_RoundRobinMatch_Script_3:
	trainerbattle_no_intro TRAINER_QUINCY, gText_GroupStages_Blank
	goto GroupStages_RoundRobinMatch_Script_1

GroupStages_RoundRobinMatch_Script_4:
	trainerbattle_no_intro TRAINER_KATELYNN, gText_GroupStages_Blank
	goto GroupStages_RoundRobinMatch_Script_1

GroupStages_RoundRobinMatch_Script_5:
	trainerbattle_no_intro TRAINER_EDGAR, gText_GroupStages_Blank
	goto GroupStages_RoundRobinMatch_Script_1


GroupStages_PostRoundRobinMatch_Script::
	lock
	addvar VAR_ROUTE119_STATE, 1
	special LoadPlayerParty
	special HealPlayerParty
	compare VAR_ROUTE119_STATE, 4
	goto_if_eq GroupStages_PostRoundRobinMatch_Script_2
GroupStages_PostRoundRobinMatch_Script_1:
	msgbox gText_GroupStages_Blank
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_GetPlayerIntoPosition
	applymovement 1, GroupStages_WalkOffStage
	waitmovement 0
	msgbox gText_GroupStages_Blank
	call GroupStages_ChooseParty_Script
	removeobject 1
	call Psfplace14_Arena_MapScripts_OnTransition
	addobject 1
	goto GroupStages_RoundRobinMatch_Script
	return

GroupStages_PostRoundRobinMatch_Script_2:
	goto GroupStages_RoundRobinGroupComplete_Script
	goto GroupStages_PostRoundRobinMatch_Script_1


GroupStages_RoundRobinGroupComplete_Script::
	addvar VAR_STORYLINE_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_WalkToCenterStage
	waitmovement 0
	msgbox gText_GroupStages_Blank
	special DoDomeConfetti
	playse SE_APPLAUSE
	waitse
	warpsilent MAP_PSFPLACE14_LOCKERS, 255, 10, 3
	return


GroupStages_WalkToPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

GroupStages_LeaveLockers:
	walk_in_place_down
	step_end

GroupStages_PlayerLeaveLockers:
	walk_up
	walk_up
	step_end

GroupStages_PlayerLeaveLockers_Left:
	walk_right
	walk_up
	step_end

GroupStages_PlayerLeaveLockers_Right:
	walk_left
	walk_up
	step_end

GroupStages_WalkOffStage:
	walk_right
	walk_right
	step_end

GroupStages_GetPlayerIntoPosition:
	walk_left
	face_right
	step_end

GroupStages_WalkToCenterStage:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

gText_GroupStages_Blank::
	.string "...$"

gText_GroupStages_OnceYouStart::
	.string "Once you start the Group Stage, there's\n"
	.string "no turning back. You must complete the\l"
	.string "group stage before you can leave\l"
	.string "again, and you must complete the\l"
	.string "tournament before you can leave\l"
	.string "Psfplace14. Are you ready to continue?$"

gText_GroupStages_PlayerReturnToArena::
	.string "Paging competitor {PLAYER}.\n"
	.string "{PLAYER}. Please return to the arena\l"
	.string "for your scheduled match.$"

gText_GroupStages_OhRight::
	.string "Oh right, I can't leave once the\n"
	.string "tournament has started...$"