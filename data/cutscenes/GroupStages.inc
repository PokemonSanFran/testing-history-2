GroupStages_Lockers_ObjectSetUp_Script::
	setobjectxyperm 2, 10, 3
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_6
	return


GroupStages_Lockers_ObjectCleanUp_Script::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_6
	return


GroupStages_Skybox_ObjectSetup_Script::
	setobjectxyperm 8, 16, 6
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_DOWN
	return


GroupStages_GreetBeforeStart_Dialogue::
	lock
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement 2, GroupStages_WalkToPlayer
	waitmovement 2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_GroupStages_EasyPeasy
	closemessage
	callnative ClearMugshot
	applymovement 2, GroupStages_LeaveLockers
	waitmovement 2
	playse SE_EXIT
	waitse
	removeobject 2
	fadedefaultbgm
	setvar VAR_STORYLINE_STATE, STORY_READY_GROUP_STAGE
	setvar VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_1
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
	setflag FLAG_CHASECENTER_TOURNAMENT_HAPPENING
	call GroupStages_MoveObjects_Script
	compare VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_4
	goto_if_ne GroupStages_PreparePlayer_Script_5
GroupStages_PreparePlayer_Script_4:
	warpsilent MAP_CHASECENTER_ARENA, 255, 5, 6
	goto GroupStages_PreparePlayer_Script_1

GroupStages_PreparePlayer_Script_5:
	setvar VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_1
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
	waitmovement OBJ_EVENT_ID_PLAYER
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
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_GroupStages_Placeholder
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 1
	msgbox gText_GroupStages_Placeholder
	closemessage
	switch VAR_CHASECENTER_TOURNAMENT_STATE
	case PRE_BATTLE_1, GroupStages_RoundRobinMatch_Script_3
	case PRE_BATTLE_2, GroupStages_RoundRobinMatch_Script_4
	case PRE_BATTLE_3, GroupStages_RoundRobinMatch_Script_5
GroupStages_RoundRobinMatch_Script_1:
	goto GroupStages_PostRoundRobinMatch_Script
	return

GroupStages_RoundRobinMatch_Script_3:
	trainerbattle_no_intro TRAINER_QUINCY, gText_GroupStages_Placeholder
	goto GroupStages_RoundRobinMatch_Script_1

GroupStages_RoundRobinMatch_Script_4:
	trainerbattle_no_intro TRAINER_KATELYNN, gText_GroupStages_Placeholder
	goto GroupStages_RoundRobinMatch_Script_1

GroupStages_RoundRobinMatch_Script_5:
	trainerbattle_no_intro TRAINER_EDGAR, gText_GroupStages_Placeholder
	goto GroupStages_RoundRobinMatch_Script_1


GroupStages_PostRoundRobinMatch_Script::
	lock
	addvar VAR_CHASECENTER_TOURNAMENT_STATE, 1
	special LoadPlayerParty
	special HealPlayerParty
	compare VAR_CHASECENTER_TOURNAMENT_STATE, 4
	goto_if_eq GroupStages_PostRoundRobinMatch_Script_2
GroupStages_PostRoundRobinMatch_Script_1:
	msgbox gText_GroupStages_Placeholder
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_GetPlayerIntoPosition
	applymovement 1, GroupStages_WalkOffStage
	waitmovement 1
	msgbox gText_GroupStages_Placeholder
	call GroupStages_ChooseParty_Script
	removeobject 1
	call Chasecenter_Arena_MapScripts_OnTransition
	addobject 1
	goto GroupStages_RoundRobinMatch_Script
	return

GroupStages_PostRoundRobinMatch_Script_2:
	goto GroupStages_RoundRobinGroupComplete_Script
	goto GroupStages_PostRoundRobinMatch_Script_1


GroupStages_RoundRobinGroupComplete_Script::
	setvar VAR_STORYLINE_STATE, STORY_GROUP_STATE_COMPLETE
	applymovement OBJ_EVENT_ID_PLAYER, GroupStages_WalkToCenterStage
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_GroupStages_Placeholder
	special DoDomeConfetti
	playse SE_APPLAUSE
	waitse
	warpsilent MAP_CHASECENTER_LOCKERS, 255, 10, 3
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

gText_GroupStages_EasyPeasy::
	.string "Easy peasy! Good luck in there!$"

gText_GroupStages_Placeholder::
	.string "this is placeholder text.$"

gText_GroupStages_OnceYouStart::
	.string "Once you start the Group Stage, there's\n"
	.string "no turning back. You must complete the\l"
	.string "group stage before you can leave\l"
	.string "again, and you must complete the\l"
	.string "tournament before you can leave\l"
	.string "Chasecenter. Are you ready to\l"
	.string "continue?$"

gText_GroupStages_PlayerReturnToArena::
	.string "Paging competitor {PLAYER}.\n"
	.string "{PLAYER}. Please return to the arena\l"
	.string "for your scheduled match.$"

gText_GroupStages_OhRight::
	.string "Oh right, I can't leave once the\n"
	.string "tournament has started...$"
