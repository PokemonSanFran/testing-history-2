Quest_CulturalPurity_HideBackUp_Script::
	setflag FLAG_TEMP_3
	return


Quest_CulturalPurity_MoveGuard_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CULTURALPURITY
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_MoveGuard_Script_2
Quest_CulturalPurity_MoveGuard_Script_1:
	return

Quest_CulturalPurity_MoveGuard_Script_2:
	setobjectxy 10, 16, 19
	setobjectxyperm 10, 16, 19
	goto Quest_CulturalPurity_MoveGuard_Script_1


Quest_CulturalPurity_HideBugsyInside_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_CULTURALPURITY
	compare VAR_RESULT, 0
	goto_if_eq Quest_CulturalPurity_HideBugsyInside_Script_1
	return

Quest_CulturalPurity_HideBugsyInside_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_CulturalPurity_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_BUGSY_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_CulturalPurity_HideLeader_Script_2
	compare VAR_RESULT, 2
	goto_if_lt Quest_CulturalPurity_HideLeader_Script_2
Quest_CulturalPurity_HideLeader_Script_1:
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_CULTURALPURITY
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_HideLeader_Script_7
Quest_CulturalPurity_HideLeader_Script_6:
	compare VAR_HOW_DISAPPOINTING_STATE, 0
	goto_if_gt Quest_CulturalPurity_HideLeader_Script_11
Quest_CulturalPurity_HideLeader_Script_9:
	return

Quest_CulturalPurity_HideLeader_Script_2:
	setflag FLAG_TEMP_2
	goto Quest_CulturalPurity_HideLeader_Script_1

Quest_CulturalPurity_HideLeader_Script_7:
	setflag FLAG_TEMP_2
	goto Quest_CulturalPurity_HideLeader_Script_6

Quest_CulturalPurity_HideLeader_Script_10:
	setflag FLAG_TEMP_2
	goto Quest_CulturalPurity_HideLeader_Script_9

Quest_CulturalPurity_HideLeader_Script_11:
	compare VAR_HOW_DISAPPOINTING_STATE, HOW_DISAPPOINTING_COMPLETE
	goto_if_ne Quest_CulturalPurity_HideLeader_Script_10
	goto Quest_CulturalPurity_HideLeader_Script_9


Quest_CulturalPurity_Interact_Event_Script::
	lock
	faceplayer
	returnqueststate QUEST_CULTURALPURITY
	switch VAR_RESULT
	goto Quest_CulturalPurity_QuestStart_Dialogue
	return


Quest_CulturalPurity_QuestStart_Dialogue::
	msgbox gText_CulturalPurity_Player
	msgbox gText_CulturalPurity_IReadOnline
	msgbox gText_CulturalPurity_TheSaidToStart
	applymovement 9, Quest_CulturalPurity_LeaderWalkAway_Movement
	waitmovement 9
	removeobject 9
	startquest QUEST_CULTURALPURITY
	release
	end


Quest_CulturalPurity_CheckProgress_Script::
	setvar VAR_TEMP_0, 0
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_CULTURALPURITY
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_CheckProgress_Script_2
Quest_CulturalPurity_CheckProgress_Script_1:
	checkitem ITEM_KEY_TO_ROOM_1, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_CheckProgress_Script_5
Quest_CulturalPurity_CheckProgress_Script_4:
	checkitem ITEM_KEY_TO_ROOM_2, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_CheckProgress_Script_8
Quest_CulturalPurity_CheckProgress_Script_7:
	checkitem ITEM_KEY_TO_ROOM_4, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_CheckProgress_Script_11
Quest_CulturalPurity_CheckProgress_Script_10:
	checkitem ITEM_KEY_TO_ROOM_6, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_CulturalPurity_CheckProgress_Script_14
Quest_CulturalPurity_CheckProgress_Script_13:
	return

Quest_CulturalPurity_CheckProgress_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_CulturalPurity_CheckProgress_Script_1

Quest_CulturalPurity_CheckProgress_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_CulturalPurity_CheckProgress_Script_4

Quest_CulturalPurity_CheckProgress_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_CulturalPurity_CheckProgress_Script_7

Quest_CulturalPurity_CheckProgress_Script_11:
	addvar VAR_TEMP_0, 1
	goto Quest_CulturalPurity_CheckProgress_Script_10

Quest_CulturalPurity_CheckProgress_Script_14:
	addvar VAR_TEMP_0, 1
	goto Quest_CulturalPurity_CheckProgress_Script_13


Quest_CulturalPurity_BackroomA_Interact_Script::
	lock
	faceplayer
	msgbox gText_CulturalPurity_GoAway
	call Quest_CulturalPurity_CheckProgress_Script
	compare VAR_TEMP_0, 1
	goto_if_eq Quest_CulturalPurity_BackroomA_Interact_Script_2
Quest_CulturalPurity_BackroomA_Interact_Script_1:
	release
	end

Quest_CulturalPurity_BackroomA_Interact_Script_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CulturalPurity_WaitIKnowThePassword
	callnative ClearMugshot
	msgbox gText_CulturalPurity_OhHereYouGo
	giveitem ITEM_KEY_TO_ROOM_1, 1
	goto Quest_CulturalPurity_BackroomA_Interact_Script_1


Quest_CulturalPurity_BackroomB_Interact_Script::
	lock
	faceplayer
	msgbox gText_CulturalPurity_GoAway
	call Quest_CulturalPurity_CheckProgress_Script
	compare VAR_TEMP_0, 2
	goto_if_eq Quest_CulturalPurity_BackroomB_Interact_Script_2
Quest_CulturalPurity_BackroomB_Interact_Script_1:
	release
	end

Quest_CulturalPurity_BackroomB_Interact_Script_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CulturalPurity_WaitIKnowThePassword
	callnative ClearMugshot
	msgbox gText_CulturalPurity_OhHereYouGo
	giveitem ITEM_KEY_TO_ROOM_2, 1
	goto Quest_CulturalPurity_BackroomB_Interact_Script_1


Quest_CulturalPurity_BackroomC_Interact_Script::
	lock
	faceplayer
	msgbox gText_CulturalPurity_GoAway
	call Quest_CulturalPurity_CheckProgress_Script
	compare VAR_TEMP_0, 3
	goto_if_eq Quest_CulturalPurity_BackroomC_Interact_Script_2
Quest_CulturalPurity_BackroomC_Interact_Script_1:
	release
	end

Quest_CulturalPurity_BackroomC_Interact_Script_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CulturalPurity_WaitIKnowThePassword
	callnative ClearMugshot
	msgbox gText_CulturalPurity_OhHereYouGo
	giveitem ITEM_KEY_TO_ROOM_4, 1
	goto Quest_CulturalPurity_BackroomC_Interact_Script_1


Quest_CulturalPurity_BackroomD_Interact_Script::
	lock
	faceplayer
	msgbox gText_CulturalPurity_GoAway
	call Quest_CulturalPurity_CheckProgress_Script
	compare VAR_TEMP_0, 4
	goto_if_eq Quest_CulturalPurity_BackroomD_Interact_Script_2
Quest_CulturalPurity_BackroomD_Interact_Script_1:
	release
	end

Quest_CulturalPurity_BackroomD_Interact_Script_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CulturalPurity_WaitIKnowThePassword
	callnative ClearMugshot
	msgbox gText_CulturalPurity_OhHereYouGo
	giveitem ITEM_KEY_TO_ROOM_6, 1
	goto Quest_CulturalPurity_BackroomD_Interact_Script_1


Quest_CulturalPurity_Racist_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_CULTURALPURITY
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_CulturalPurity_Racist_Interact_Script_2
	goto Quest_CulturalPurity_Racist_FirstGuard_Dialogue
	return

Quest_CulturalPurity_Racist_Interact_Script_2:
	goto Quest_CulturalPurity_ObjectSetUp_Script
	return


Quest_CulturalPurity_ObjectSetUp_Script::
	fadescreen FADE_TO_BLACK
	call Quest_CulturalPurity_MakeBugsyVisible_Script
	call Quest_CulturalPurity_MakeBackupVisible_Script
	setobjectxyperm 9, 14, 20
	setobjectxy 9, 14, 20
	turnobject 9, DIR_NORTH
	setobjectxyperm 12, 14, 19
	setobjectxy 12, 14, 19
	fadescreen FADE_FROM_BLACK
	goto Quest_CulturalPurity_Battle_Script
	return


Quest_CulturalPurity_Racist_FirstGuard_Dialogue::
	msgbox gText_CulturalPurity_GoAway
	call Quest_CulturalPurity_CheckProgress_Script
	compare VAR_TEMP_0, 5
	goto_if_eq Quest_CulturalPurity_Racist_FirstGuard_Dialogue_2
Quest_CulturalPurity_Racist_FirstGuard_Dialogue_1:
	release
	end

Quest_CulturalPurity_Racist_FirstGuard_Dialogue_2:
	goto Quest_CulturalPurity_BugsyJoin_Dialogue
	goto Quest_CulturalPurity_Racist_FirstGuard_Dialogue_1


Quest_CulturalPurity_MakeBugsyVisible_Script::
	clearflag FLAG_TEMP_2
	addobject 9
	return


Quest_CulturalPurity_MakeBackupVisible_Script::
	clearflag FLAG_TEMP_3
	addobject 12
	return


Quest_CulturalPurity_BugsyJoin_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_CulturalPurity_IFiguredItOut
	callnative ClearMugshot
	call Quest_CulturalPurity_MakeBugsyVisible_Script
	applymovement 9, Quest_CulturalPurity_BugsyWalkToGuard_Movement
	waitmovement 9
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_CulturalPurity_IHaveTheCodeButWeNeed
	callnative ClearMugshot
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_CulturalPurity_YepGotEm
	callnative ClearMugshot
	msgbox gText_CulturalPurity_LetMeSee
	call Quest_CulturalPurity_LoseTiles_Script
	msgbox gText_CulturalPurity_HeyCleetus
	call Quest_CulturalPurity_BackupWalkOut_Script
	questmenu QUEST_MENU_SET_REWARD, QUEST_CULTURALPURITY
	goto Quest_CulturalPurity_Battle_Script
	return


Quest_CulturalPurity_LoseTiles_Script::
	removeitem ITEM_KEY_TO_ROOM_1, 1
	removeitem ITEM_KEY_TO_ROOM_2, 1
	removeitem ITEM_KEY_TO_ROOM_4, 1
	removeitem ITEM_KEY_TO_ROOM_6, 1
	return


Quest_CulturalPurity_BackupWalkOut_Script::
	opendoor 15, 18
	waitdooranim
	call Quest_CulturalPurity_MakeBackupVisible_Script
	applymovement 12, Quest_CulturalPurity_BackupWalkOutside_Movement
	waitmovement 12
	closedoor 15, 18
	applymovement 9, Common_Movement_FaceUp
	waitmovement 9
	return


Quest_CulturalPurity_Battle_Script::
	msgbox gText_CulturalPurity_WellThenItsTimeForYourInitation
	multi_fixed_2_vs_2 TRAINER_RANDALL, gText_CulturalPurity_OneOfUs, TRAINER_PARKER, gText_CulturalPurity_OneOfUs, TRAINER_BRAWLY_1, TRAINER_BACK_PIC_WALLY
	goto Quest_CulturalPurity_PostBattle_Script
	return


Quest_CulturalPurity_PostBattle_Script::
	msgbox gText_CulturalPurity_WowWelcomeInside
	closemessage
	applymovement 10, Quest_CulturalPurity_StepAside_Movement
	waitmovement 10
	opendoor 15, 18
	applymovement 9, Quest_CulturalPurity_WalkInside_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Quest_CulturalPurity_FollowBugsy_Movement
	waitmovement OBJ_EVENT_ID_PLAYER
	warp MAP_CHINATOWN_RACISTHOUSE, 0
	return


Quest_CulturalPurity_InsideClubhouse_Dialogue::
	lock
	addvar VAR_TEMP_0, 1
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_CULTURALPURITY
	compare VAR_RESULT, 0
	goto_if_eq Quest_CulturalPurity_InsideClubhouse_Dialogue_2
	applymovement 2, Quest_CulturalPurity_WalkToPlayer_Movement
	waitmovement 2
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_CulturalPurity_NeverMind
	callnative ClearMugshot
	closemessage
	giveitem ITEM_ORAN_BERRY, 1
	setvar VAR_MUGSHOT, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_CulturalPurity_IHaveSomeThiking
	callnative ClearMugshot
	closemessage
	applymovement 2, Quest_CulturalPurity_LeaveClubhouse_Movement
	waitmovement 2
	playse SE_EXIT
	removeobject 2
	waitse
	setvar VAR_BUGSY_STATE, QUEST_1_COMPLETE
	completequest QUEST_CULTURALPURITY
	release
	end

Quest_CulturalPurity_InsideClubhouse_Dialogue_2:
	release
	end


Quest_CulturalPurity_LeaderWalkAway_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Quest_CulturalPurity_BugsyWalkToGuard_Movement:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Quest_CulturalPurity_BackupWalkOutside_Movement:
	walk_down
	walk_left
	face_down
	step_end

Quest_CulturalPurity_StepAside_Movement:
	lock_facing_direction
	walk_right
	step_end

Quest_CulturalPurity_WalkInside_Movement:
	walk_right
	walk_up
	walk_up
	step_end

Quest_CulturalPurity_FollowBugsy_Movement:
	walk_up
	walk_up
	step_end

Quest_CulturalPurity_WalkToPlayer_Movement:
	walk_left
	walk_down
	step_end

Quest_CulturalPurity_LeaveClubhouse_Movement:
	walk_left
	walk_down
	step_end

gText_CulturalPurity_Player::
	.string "{PLAYER} Hello!$"

gText_CulturalPurity_IReadOnline::
	.string "i read online about a group of people in\n"
	.string "chinatown who have stayed tru$"

gText_CulturalPurity_TheSaidToStart::
	.string "they said start at the center... what\n"
	.string "does that mean?$"

gText_CulturalPurity_GoAway::
	.string "go away.$"

gText_CulturalPurity_WaitIKnowThePassword::
	.string "wait i know the password$"

gText_CulturalPurity_OhHereYouGo::
	.string "oh here you go$"

gText_CulturalPurity_IFiguredItOut::
	.string "i figured it out!$"

gText_CulturalPurity_IHaveTheCodeButWeNeed::
	.string "i have the code word, but need all the\n"
	.string "tiles$"

gText_CulturalPurity_YepGotEm::
	.string "yep got em here$"

gText_CulturalPurity_LetMeSee::
	.string "let me see your tiles.$"

gText_CulturalPurity_HeyCleetus::
	.string "hey cleetus!$"

gText_CulturalPurity_WellThenItsTimeForYourInitation::
	.string "Well then, its time for your initation!$"

gText_CulturalPurity_OneOfUs::
	.string "one of us one of us$"

gText_CulturalPurity_WowWelcomeInside::
	.string "wow welcome inside$"

gText_CulturalPurity_NeverMind::
	.string "never mind. they're just nationalists.$"

gText_CulturalPurity_IHaveSomeThiking::
	.string "i have some thinking to do.$"
