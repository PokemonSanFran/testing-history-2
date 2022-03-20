NoGoggles_PreventProgress::
	lock
	compare VAR_FAINTED_FOG_STATE, 0
	goto_if_eq NoGoggles_PreventProgress_2
NoGoggles_PreventProgress_1:
	checkitem ITEM_GO_GOGGLES, 1
	compare VAR_RESULT, 0
	goto_if_eq NoGoggles_PreventProgress_4
	return

NoGoggles_PreventProgress_2:
	setvar VAR_FAINTED_FOG_STATE, 1
	goto NoGoggles_PreventProgress_1

NoGoggles_PreventProgress_4:
	msgbox NoGoggles_PreventProgress_Text_0, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	release
	end


NoGoggles_PreventProgress_Text_0:
	.string "A wild Mewtwo jumped out of the bushes\n"
	.string "and kicked your ass.$"
