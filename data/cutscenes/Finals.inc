Finals_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_6
	return


Finals_PreparePlayer_Script::
	lock
	faceplayer
	msgbox gText_Finals_YourSemiFinal, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq Finals_PreparePlayer_Script_2
Finals_PreparePlayer_Script_1:
	release
	end

Finals_PreparePlayer_Script_2:
	call GroupStages_MoveObjects_Script
	warpsilent MAP_CHASECENTER_ARENA, 255, 5, 6
	goto Finals_PreparePlayer_Script_1


Finals_StopPlayerLeaveLockers_Script::
	lock
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Finals_YourMatchIsUp
	closemessage
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end


Finals_StartSemifinals_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_GroupStages_Placeholder
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	msgbox gText_GroupStages_Placeholder
	closemessage
	trainerbattle_no_intro TRAINER_HALLE, gText_GroupStages_Placeholder
	setvar VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_5
	call GroupStages_RoundRobinGroupComplete_Script
	return


gText_Finals_YourSemiFinal::
	.string "Your Semifinal match is next. Are you\n"
	.string "ready?$"

gText_Finals_YourMatchIsUp::
	.string "Your match is up next! Where are you\n"
	.string "going?$"
