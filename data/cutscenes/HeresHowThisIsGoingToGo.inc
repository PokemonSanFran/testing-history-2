HeresHowThisIsGoingToGo_ObjectSetUp_Script::
	setflag FLAG_TEMP_6
	return


HeresHowThisIsGoingToGo_Lockers_ObjectCleanUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_4
	return


HeresHowThisIsGoingToGo_ConstructionCompleted_Script::
	compare VAR_STORYLINE_STATE, STORY_COMPLETED_NAVAL_BASE
	goto_if_gt HeresHowThisIsGoingToGo_ConstructionCompleted_Script_2
HeresHowThisIsGoingToGo_ConstructionCompleted_Script_1:
	return

HeresHowThisIsGoingToGo_ConstructionCompleted_Script_2:
	setmetatile 19, 13, 0x371, TRUE
	setmetatile 19, 14, 0x379, TRUE
	setmetatile 19, 15, 0x381, TRUE
	setmetatile 19, 16, 0x389, TRUE
	setmetatile 19, 17, 0x391, TRUE
	setmetatile 20, 13, 0x372, TRUE
	setmetatile 20, 14, 0x37A, TRUE
	setmetatile 20, 15, 0x382, TRUE
	setmetatile 20, 16, 0x38A, TRUE
	setmetatile 20, 17, 0x392, TRUE
	setmetatile 21, 13, 0x373, TRUE
	setmetatile 21, 14, 0x37B, TRUE
	setmetatile 21, 15, 0x383, FALSE
	setmetatile 21, 16, 0x38B, TRUE
	setmetatile 21, 17, 0x393, TRUE
	setmetatile 22, 17, 0x394, TRUE
	setmetatile 22, 14, 0x37C, TRUE
	setmetatile 22, 13, 0x374, TRUE
	setmetatile 22, 16, 0x38C, TRUE
	setmetatile 22, 15, 0x384, TRUE
	setmetatile 23, 15, 0x385, TRUE
	setmetatile 23, 14, 0x37D, TRUE
	setmetatile 23, 13, 0x375, TRUE
	setmetatile 23, 16, 0x38D, TRUE
	setmetatile 23, 17, 0x395, TRUE
	setmetatile 21, 18, 0x211, FALSE
	special DrawWholeMapView
	goto HeresHowThisIsGoingToGo_ConstructionCompleted_Script_1


HeresHowThisIsGoingToGo_VirtualObjectSetUp_Script::
	createvobject OBJ_EVENT_GFX_BOY_2, 6, 8, 5, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MAN_2, 7, 9, 5, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_F, 8, 10, 5, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_OLD_WOMAN, 9, 11, 5, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_HEX_MANIAC, 10, 12, 5, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY_3, 11, 13, 5, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_BOY_1, 12, 6, 6, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_LITTLE_GIRL, 13, 7, 6, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MAN_1, 14, 8, 6, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_RUNNING_TRIATHLETE_M, 15, 10, 6, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_WOMAN_4, 16, 12, 6, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_MYSTERY_GIFT_MAN, 17, 13, 6, 3, DIR_NORTH
	createvobject OBJ_EVENT_GFX_LITTLE_BOY, 18, 6, 5, 3, DIR_NORTH
	return


HeresHowThisIsGoingToGo_CleanUpVObjects_Script::
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	removeobject 10
	removeobject 11
	removeobject 12
	removeobject 13
	removeobject 14
	removeobject 15
	removeobject 16
	removeobject 17
	callnative DestroyVirtualObjects
	return


HeresHowThisIsGoingToGo_ExplainLeagueDialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 2, Common_Movement_FaceUp
	applymovement 3, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_HeresHowThisIsGoingToGo_CongratulationsOnAll
	callnative ClearMugshot
	msgbox gText_HeresHowThisIsGoingToGo_WooYay
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_HeresHowThisIsGoingToGo_ImSureNone
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_HeresHowThisIsGoingToGo_WaitIDid
	callnative ClearMugshot
	msgbox gText_HeresHowThisIsGoingToGo_DotDotDot
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_HeresHowThisIsGoingToGo_SoIllGoOver
	closemessage
	callnative ClearMugshot
	applymovement 1, Common_Movement_FaceLeft
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_HeresHowThisIsGoingToGo_YourGroupsAnd
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	setvar VAR_STORYLINE_STATE, STORY_CHAMPIONSHIP_EXPLAINED
	playse SE_EXIT
	waitse
	removeobject 1
	removeobject 4
	call HeresHowThisIsGoingToGo_CleanUpVObjects_Script
	fadescreen FADE_FROM_BLACK
	applymovement 3, HeresHowThisIsGoingToGo_GoToBracket
	waitmovement 3
	releaseall
	end


HeresHowThisIsGoingToGo_LeaveLockersA:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

HeresHowThisIsGoingToGo_LeaveLockersB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

HeresHowThisIsGoingToGo_GoToBracket:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

gText_HeresHowThisIsGoingToGo_CongratulationsOnAll::
	.string "Congratulations on all of your hard\n"
	.string "work! Welcome to the first stage of the\l"
	.string "SanFran League Championship!$"

gText_HeresHowThisIsGoingToGo_WooYay::
	.string "Woo! Yay!$"

gText_HeresHowThisIsGoingToGo_ImSureNone::
	.string "I'm sure none of you read the\n"
	.string "information email -$"

gText_HeresHowThisIsGoingToGo_WaitIDid::
	.string "Wait, I did! Did nobody else?$"

gText_HeresHowThisIsGoingToGo_DotDotDot::
	.string "…$"

gText_HeresHowThisIsGoingToGo_SoIllGoOver::
	.string "So here's the simple explanation: Win\n"
	.string "five battles in a row, and you'll be the\l"
	.string "Champion! If you want the more\l"
	.string "detailed version, you can view the\l"
	.string "rules on the monitor to my right.$"

gText_HeresHowThisIsGoingToGo_YourGroupsAnd::
	.string "Your groups, and the eventual final\n"
	.string "bracket, can also be seen on the\l"
	.string "monitor. We'll be starting with Group A\l"
	.string "in two hours. Good luck.$"
