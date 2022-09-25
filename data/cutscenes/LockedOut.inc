LockedOut_PreventPlayer_Script::
	lock
	goto_if_unset FLAG_TIMELINE_TRUE, LockedOut_PreventPlayer_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, LockedOut_DoorLocked
	waitmovement 0
	playse SE_FAILURE
	waitse
	msgbox gText_LockedOut_AccessDenied
	closemessage
	goto_if_unset FLAG_LOCKEDOUT_PLAYED, LockedOut_PreventPlayer_Script_5
	call LockedOut_WarpPlayer_Script
LockedOut_PreventPlayer_Script_4:
	closemessage
	release
	end

LockedOut_PreventPlayer_Script_2:
	release
	end

LockedOut_PreventPlayer_Script_5:
	call LockedOut_PhoneCall_Dialogue
	goto LockedOut_PreventPlayer_Script_4


LockedOut_PhoneCall_Dialogue::
	setflag FLAG_LOCKEDOUT_PLAYED
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LockedOut_ShitWait
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LockedOut_TryDoorAgain
	waitmovement 0
	playse SE_FAILURE
	waitse
	msgbox gText_LockedOut_AccessDenied
	closemessage
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	waitse
	pokenavcall LockedOut_PhoneCall_Dialogue_Text_0
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LockedOut_HeyIWasThinking
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LockedOut_ImLockedOut
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LockedOut_ThatsActuallyWhy
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LockedOut_IActuallyHadnt
	closemessage
	callnative ClearMugshot
	playse SE_POKENAV_HANG_UP
	waitse
	goto LockedOut_WarpPlayer_Script
	return


LockedOut_WarpPlayer_Script::
	msgbox gText_LockedOut_DoYouWant, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq LockedOut_WarpPlayer_Script_1
	return

LockedOut_WarpPlayer_Script_1:
	warpsilent MAP_ALAMEDA, 29, 33
	return


LockedOut_DoorLocked:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LockedOut_TryDoorAgain:
	walk_up
	delay_8
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LockedOut_PhoneCall_Dialogue_Text_0:
	.string "This phone is ringing.$"

gText_LockedOut_AccessDenied::
	.string "Access denied.$"

gText_LockedOut_ShitWait::
	.string "Shit wait, already?!$"

gText_LockedOut_HeyIWasThinking::
	.string "Hey {PLAYER}, I was thinking…$"

gText_LockedOut_ImLockedOut::
	.string "I’m locked out!$"

gText_LockedOut_ThatsActuallyWhy::
	.string "That’s actually why I called. I know you\n"
	.string "had a lot to lose with this, and I was\l"
	.string "right: Psfbadguy is straight up going\l"
	.string "to disown you. If you need someplace\l"
	.string "to go, you can absolutely crash with me\l"
	.string "in Alameda.$"

gText_LockedOut_IActuallyHadnt::
	.string "I actually hadn’t thought that far\n"
	.string "ahead… but thank you, a lot, Archer.$"

gText_LockedOut_DoYouWant::
	.string "Do you want to go to Archer’s home?$"
