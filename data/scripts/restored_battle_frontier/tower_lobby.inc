BattleTower_MapScripts::
	.byte 0


BattleTower_EventScript_PlayerFaceNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end


BattleTower_EventScript_GetChallengeStatus::
	frontier_getstatus
	end


BattleTower_EventScript_QuitWithoutSaving::
	lock
	faceplayer
	msgbox BattleTower_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	tower_set TOWER_DATA_WIN_STREAK, 0
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_0, 255
	release
	end


BattleTower_EventScript_WonChallenge::
	lock
	faceplayer
	message BattleTower_Text_CongratsBeatenSeven
	waitmessage
	call BattleTower_EventScript_GiveRibbons
	call BattleTower_EventScript_GiveBattlePoints
	call BattleTower_EventScript_AskSaveBattle2
	goto BattleTower_EventScript_LookForwardToChallenge
	return


BattleTower_EventScript_GiveRibbons::
	tower_giveribbons
	compare VAR_RESULT, 0
	goto_if_eq BattleTower_EventScript_GiveRibbons_2
	message BattleTower_Text_HereAreSomeRibbons
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox BattleTower_Text_PutRibbonOnMons, MSGBOX_DEFAULT
	return

BattleTower_EventScript_GiveRibbons_2:
	return


BattleTower_EventScript_GiveBattlePoints::
	msgbox BattleTower_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	buffernumberstring STR_VAR_1, 10
	givefrontierbattlepoints 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	return


BattleTower_EventScript_LookForwardToChallenge::
	msgbox BattleTower_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	special LoadPlayerPartyBattleFrontier
	setvar VAR_TEMP_0, 255
	release
	end


BattleTower_EventScript_LostChallenge::
	special LoadPlayerPartyBattleFrontier
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	goto_if_ne BattleTower_EventScript_LostChallenge_2
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleTower_EventScript_LostChallenge_2
BattleTower_EventScript_LostChallenge_1:
	tower_get TOWER_DATA_WIN_STREAK
	compare VAR_RESULT, 0
	goto_if_ne BattleTower_EventScript_LostChallenge_7
BattleTower_EventScript_LostChallenge_6:
	goto BattleTower_EventScript_CancelWinStreak
	return

BattleTower_EventScript_LostChallenge_2:
	goto BattleTower_EventScript_CancelWinStreak
	goto BattleTower_EventScript_LostChallenge_1

BattleTower_EventScript_LostChallenge_7:
	goto BattleTower_EventScript_LostThanksForPlaying
	goto BattleTower_EventScript_LostChallenge_6


BattleTower_EventScript_CancelWinStreak::
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, FALSE
	goto BattleTower_EventScript_LostThanksForPlaying
	return


BattleTower_EventScript_LostThanksForPlaying::
	lock
	faceplayer
	message BattleTower_Text_ThankYouForPlaying
	waitmessage
	call BattleTower_EventScript_AskSaveBattle2
	msgbox BattleTower_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 255
	release
	end


BattleTower_EventScript_AskSaveBattle2::
	message BattleTower_Text_RecordWillBeSaved
	waitmessage
	frontier_checkairshow
	special HealPlayerParty
	tower_save 0
	playse SE_SAVE
	waitse
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	compare VAR_RESULT, TRUE
	goto_if_eq BattleTower_EventScript_AskSaveBattle2_2
	message BattleTower_Text_RecordLastMatch
	waitmessage
	call EventScript_Construct_YesNo_NoSelected_Menu_Script
	compare VAR_RESULT, YES
	goto_if_eq BattleTower_EventScript_AskSaveBattle2_5
BattleTower_EventScript_AskSaveBattle2_4:
	return

BattleTower_EventScript_AskSaveBattle2_2:
	return

BattleTower_EventScript_AskSaveBattle2_5:
	call BattleFrontier_EventScript_SaveBattle2
	goto BattleTower_EventScript_AskSaveBattle2_4


EventScript_Construct_YesNo_NoSelected_Menu_Script::
	dynmultipush gText_Yes, YES
	dynmultipush gText_No, NO
	dynmultistack 19, 6, FALSE, 2, FALSE, NO, DYN_MULTICHOICE_CB_NONE
	return


BattleFrontier_EventScript_SaveBattle2::
	frontier_savebattle
	compare VAR_RESULT, 0
	goto_if_ne BattleFrontier_EventScript_SaveBattle2_2
	msgbox BattleFrontier_BattleTowerBattleRoom_Text_RecordCouldntBeSaved, MSGBOX_DEFAULT
BattleFrontier_EventScript_SaveBattle2_1:
	return

BattleFrontier_EventScript_SaveBattle2_2:
	playse SE_SAVE
	msgbox BattleTower_Text_BattleRecordedOnPass, MSGBOX_DEFAULT
	goto BattleFrontier_EventScript_SaveBattle2_1


BattleTower_EventScript_ResumeChallenge::
	lock
	faceplayer
	message BattleTower_Text_WeveBeenWaitingForYou
	waitmessage
	message BattleTower_Text_ProgressWillBeSaved
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	goto BattleTower_EventScript_EnterElevator
	end


BattleTower_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_TOWER
	compare VAR_LAST_TALKED, 3
	goto_if_eq BattleTower_EventScript_Attendant_2
BattleTower_EventScript_Attendant_1:
	switch VAR_LAST_TALKED
	case 1, BattleTower_EventScript_Attendant_6
	case 2, BattleTower_EventScript_Attendant_7
	case 3, BattleTower_EventScript_Attendant_8
	case 4, BattleTower_EventScript_Attendant_9
BattleTower_EventScript_Attendant_4:
	goto BattleTower_EventScript_AskEnterChallenge
	return

BattleTower_EventScript_Attendant_2:
	clearflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	goto BattleTower_EventScript_Attendant_1

BattleTower_EventScript_Attendant_6:
	msgbox BattleTower_Text_WelcomSingleBattle, MSGBOX_DEFAULT
	goto BattleTower_EventScript_Attendant_4

BattleTower_EventScript_Attendant_7:
	msgbox BattleTower_Text_WelcomeDoubleBattle, MSGBOX_DEFAULT
	goto BattleTower_EventScript_Attendant_4

BattleTower_EventScript_Attendant_8:
	msgbox BattleTower_Text_WelcomeMultiBattle, MSGBOX_DEFAULT
	goto BattleTower_EventScript_Attendant_4

BattleTower_EventScript_Attendant_9:
	msgbox BattleTower_Text_WelcomeLinkMultiBattle, MSGBOX_DEFAULT
	goto BattleTower_EventScript_Attendant_4


BattleTower_EventScript_AskEnterChallenge::
	switch VAR_LAST_TALKED
	case 1, BattleTower_EventScript_AskEnterChallenge_3
	case 2, BattleTower_EventScript_AskEnterChallenge_4
	case 3, BattleTower_EventScript_AskEnterChallenge_5
	case 4, BattleTower_EventScript_AskEnterChallenge_6
BattleTower_EventScript_AskEnterChallenge_1:
	call BattleFrontier_Challenge_Info_Exit_Menu
	switch VAR_RESULT
	case 0, BattleTower_EventScript_AskEnterChallenge_8
	case 1, BattleTower_EventScript_AskEnterChallenge_9
	case 2, BattleTower_EventScript_AskEnterChallenge_10
	case MULTI_B_PRESSED, BattleTower_EventScript_AskEnterChallenge_11
	return

BattleTower_EventScript_AskEnterChallenge_3:
	message BattleTower_Text_TakeSinglesChallenge
	goto BattleTower_EventScript_AskEnterChallenge_1

BattleTower_EventScript_AskEnterChallenge_4:
	message BattleTower_Text_TakeDoublesChallenge
	goto BattleTower_EventScript_AskEnterChallenge_1

BattleTower_EventScript_AskEnterChallenge_5:
	message BattleTower_Text_TakeMultisChallenge
	goto BattleTower_EventScript_AskEnterChallenge_1

BattleTower_EventScript_AskEnterChallenge_6:
	message BattleTower_Text_TakeLinkMultisChallenge
	goto BattleTower_EventScript_AskEnterChallenge_1

BattleTower_EventScript_AskEnterChallenge_8:
	goto BattleTower_EventScript_TryEnterChallenge
	return

BattleTower_EventScript_AskEnterChallenge_9:
	goto BattleTower_EventScript_ExplainChallenge
	return

BattleTower_EventScript_AskEnterChallenge_10:
	goto BattleTower_EventScript_CancelChallenge
	return

BattleTower_EventScript_AskEnterChallenge_11:
	goto BattleTower_EventScript_CancelChallenge
	return


BattleFrontier_Challenge_Info_Exit_Menu::
	waitmessage
	dynmultichoice 18, 4, FALSE, 3, 0, DYN_MULTICHOICE_CB_NONE, gText_Challenge, gText_Info3, gText_Exit
	return


BattleTower_EventScript_TryEnterChallenge::
	switch VAR_LAST_TALKED
	case 1, BattleTower_EventScript_TryEnterChallenge_3
	case 2, BattleTower_EventScript_TryEnterChallenge_4
	case 3, BattleTower_EventScript_TryEnterChallenge_5
	case 4, BattleTower_EventScript_TryEnterChallenge_6
BattleTower_EventScript_TryEnterChallenge_1:
	setvar VAR_RESULT, 1
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleTower_EventScript_NotEnoughValidMons
	special SavePlayerPartyBattleFrontier
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	switch VAR_LAST_TALKED
	case 1, BattleTower_EventScript_TryEnterChallenge_9
	case 2, BattleTower_EventScript_TryEnterChallenge_10
	case 3, BattleTower_EventScript_TryEnterChallenge_11
	case 4, BattleTower_EventScript_TryEnterChallenge_11
BattleTower_EventScript_TryEnterChallenge_7:
	fadescreen FADE_TO_BLACK
	frontier_get FRONTIER_DATA_LVL_MODE
	copyvar VAR_0x8004, VAR_RESULT
	switch VAR_LAST_TALKED
	case 1, BattleTower_EventScript_TryEnterChallenge_14
	case 2, BattleTower_EventScript_TryEnterChallenge_15
	case 3, BattleTower_EventScript_TryEnterChallenge_16
	case 4, BattleTower_EventScript_TryEnterChallenge_16
BattleTower_EventScript_TryEnterChallenge_12:
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleTower_EventScript_LoadPartyCancelChallenge
	msgbox BattleTower_Text_OkayToSaveBeforeEntering, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleTower_EventScript_TryEnterChallenge_18
	case YES, BattleTower_EventScript_TryEnterChallenge_19
	case MULTI_B_PRESSED, BattleTower_EventScript_TryEnterChallenge_20
	return

BattleTower_EventScript_TryEnterChallenge_3:
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleTower_EventScript_TryEnterChallenge_1

BattleTower_EventScript_TryEnterChallenge_4:
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleTower_EventScript_TryEnterChallenge_1

BattleTower_EventScript_TryEnterChallenge_5:
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_MULTIS
	goto BattleTower_EventScript_TryEnterChallenge_1

BattleTower_EventScript_TryEnterChallenge_6:
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto BattleTower_EventScript_TryEnterChallenge_1

BattleTower_EventScript_TryEnterChallenge_9:
	msgbox BattleTower_Text_SelectThreeMons, MSGBOX_DEFAULT
	goto BattleTower_EventScript_TryEnterChallenge_7

BattleTower_EventScript_TryEnterChallenge_10:
	msgbox BattleTower_Text_PleaseSelectFourMons, MSGBOX_DEFAULT
	goto BattleTower_EventScript_TryEnterChallenge_7

BattleTower_EventScript_TryEnterChallenge_11:
	msgbox BattleTower_Text_PleaseSelectTwoMons, MSGBOX_DEFAULT
	goto BattleTower_EventScript_TryEnterChallenge_7

BattleTower_EventScript_TryEnterChallenge_14:
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleTower_EventScript_TryEnterChallenge_12

BattleTower_EventScript_TryEnterChallenge_15:
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	goto BattleTower_EventScript_TryEnterChallenge_12

BattleTower_EventScript_TryEnterChallenge_16:
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleTower_EventScript_TryEnterChallenge_12

BattleTower_EventScript_TryEnterChallenge_18:
	goto BattleTower_EventScript_LoadPartyCancelChallenge
	return

BattleTower_EventScript_TryEnterChallenge_19:
	goto BattleTower_EventScript_SaveBeforeChallenge
	return

BattleTower_EventScript_TryEnterChallenge_20:
	goto BattleTower_EventScript_LoadPartyCancelChallenge
	return


BattleTower_EventScript_SaveBeforeChallenge::
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	setvar VAR_TEMP_0, 0
	tower_init
	tower_set TOWER_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	compare VAR_LAST_TALKED, 4
	goto_if_eq BattleTower_EventScript_SaveBeforeChallenge_2
BattleTower_EventScript_SaveBeforeChallenge_1:
	startmenu_savescreen
	setvar VAR_TEMP_0, 255
	compare VAR_RESULT, FALSE
	goto_if_eq BattleTower_EventScript_SaveBeforeChallenge_5
BattleTower_EventScript_SaveBeforeChallenge_4:
	call BattleTower_EventScript_HandleMultiplayer
	goto BattleTower_EventScript_EnterElevator
	return

BattleTower_EventScript_SaveBeforeChallenge_2:
	tower_save 0
	goto BattleTower_EventScript_SaveBeforeChallenge_1

BattleTower_EventScript_SaveBeforeChallenge_5:
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS
	goto BattleTower_EventScript_CancelChallenge
	goto BattleTower_EventScript_SaveBeforeChallenge_4


BattleTower_EventScript_HandleMultiplayer::
	compare VAR_LAST_TALKED, 4
	goto_if_eq BattleTower_EventScript_HandleMultiplayer_2
BattleTower_EventScript_HandleMultiplayer_1:
	return

BattleTower_EventScript_HandleMultiplayer_2:
	specialvar VAR_RESULT, IsWirelessAdapterConnected
	compare VAR_RESULT, 0
	goto_if_ne BattleTower_EventScript_HandleMultiplayer_5
BattleTower_EventScript_HandleMultiplayer_4:
	goto BattleTower_EventScript_TryCableLink
	goto BattleTower_EventScript_HandleMultiplayer_1

BattleTower_EventScript_HandleMultiplayer_5:
	goto BattleTower_EventScript_TryWirelessLink
	goto BattleTower_EventScript_HandleMultiplayer_4


BattleTower_EventScript_TryWirelessLink::
	setvar VAR_0x8004, LINK_GROUP_BATTLE_TOWER
	goto BattleTower_EventScript_ChooseLeader
	end


BattleTower_EventScript_ChooseLeader::
	message CableClub_Text_ChooseGroupLeaderOfTwo
	waitmessage
	multichoice 16, 6, MULTI_LINK_LEADER, FALSE
	switch VAR_RESULT
	case 0, BattleTower_EventScript_ChooseLeader_3
	case 1, BattleTower_EventScript_ChooseLeader_4
	case 2, BattleTower_EventScript_ChooseLeader_5
	case MULTI_B_PRESSED, BattleTower_EventScript_ChooseLeader_6
BattleTower_EventScript_ChooseLeader_1:
	end

BattleTower_EventScript_ChooseLeader_3:
	goto BattleTower_EventScript_TryJoinGroup
	goto BattleTower_EventScript_ChooseLeader_1

BattleTower_EventScript_ChooseLeader_4:
	goto BattleTower_EventScript_TryBecomeLeader
	goto BattleTower_EventScript_ChooseLeader_1

BattleTower_EventScript_ChooseLeader_5:
	goto BattleTower_EventScript_CancelChallenge
	goto BattleTower_EventScript_ChooseLeader_1

BattleTower_EventScript_ChooseLeader_6:
	goto BattleTower_EventScript_CancelChallenge
	goto BattleTower_EventScript_ChooseLeader_1


BattleTower_EventScript_TryJoinGroup::
	call CableClub_EventScript_TryJoinLinkGroup
	switch VAR_RESULT
	case LINKUP_SUCCESS, BattleTower_EventScript_TryJoinGroup_3
	case LINKUP_FAILED, BattleTower_EventScript_TryJoinGroup_4
	case LINKUP_RETRY_ROLE_ASSIGN, BattleTower_EventScript_TryJoinGroup_5
	case LINKUP_FAILED_BATTLE_TOWER, BattleTower_EventScript_TryJoinGroup_6
BattleTower_EventScript_TryJoinGroup_1:
	release
	return

BattleTower_EventScript_TryJoinGroup_3:
	goto BattleTower_EventScript_WirelessLinkSuccessful
	goto BattleTower_EventScript_TryJoinGroup_1

BattleTower_EventScript_TryJoinGroup_4:
	goto BattleTower_EventScript_ChooseLeader
	goto BattleTower_EventScript_TryJoinGroup_1

BattleTower_EventScript_TryJoinGroup_5:
	goto BattleTower_EventScript_TryJoinGroup
	goto BattleTower_EventScript_TryJoinGroup_1

BattleTower_EventScript_TryJoinGroup_6:
	goto BattleTower_EventScript_AbortLink
	goto BattleTower_EventScript_TryJoinGroup_1


BattleTower_EventScript_TryBecomeLeader::
	call CableClub_EventScript_TryBecomeLinkLeader
	switch VAR_RESULT
	case LINKUP_SUCCESS, BattleTower_EventScript_TryBecomeLeader_3
	case LINKUP_FAILED, BattleTower_EventScript_TryBecomeLeader_4
	case LINKUP_RETRY_ROLE_ASSIGN, BattleTower_EventScript_TryBecomeLeader_5
	case LINKUP_FAILED_BATTLE_TOWER, BattleTower_EventScript_TryBecomeLeader_6
BattleTower_EventScript_TryBecomeLeader_1:
	release
	return

BattleTower_EventScript_TryBecomeLeader_3:
	goto BattleTower_EventScript_WirelessLinkSuccessful
	goto BattleTower_EventScript_TryBecomeLeader_1

BattleTower_EventScript_TryBecomeLeader_4:
	goto BattleTower_EventScript_ChooseLeader
	goto BattleTower_EventScript_TryBecomeLeader_1

BattleTower_EventScript_TryBecomeLeader_5:
	goto BattleTower_EventScript_TryBecomeLeader
	goto BattleTower_EventScript_TryBecomeLeader_1

BattleTower_EventScript_TryBecomeLeader_6:
	goto BattleTower_EventScript_AbortLink
	goto BattleTower_EventScript_TryBecomeLeader_1


BattleTower_EventScript_WirelessLinkSuccessful::
	call BattleTower_EventScript_LinkSuccessful
	goto BattleTower_EventScript_EnterElevator
	end


BattleTower_EventScript_TryCableLink::
	setvar VAR_0x8004, USING_BATTLE_TOWER
	message gText_PleaseWaitForLink
	waitmessage
	setvar VAR_0x8005, 0
	special TryBattleLinkup
	waitstate
	switch VAR_RESULT
	case LINKUP_SUCCESS, BattleTower_EventScript_TryCableLink_3
	case LINKUP_SOMEONE_NOT_READY, BattleTower_EventScript_TryCableLink_4
	case LINKUP_DIFF_SELECTIONS, BattleTower_EventScript_TryCableLink_5
	case LINKUP_WRONG_NUM_PLAYERS, BattleTower_EventScript_TryCableLink_6
	case LINKUP_FAILED, BattleTower_EventScript_TryCableLink_7
	case LINKUP_CONNECTION_ERROR, BattleTower_EventScript_TryCableLink_8
	case LINKUP_FAILED_BATTLE_TOWER, BattleTower_EventScript_TryCableLink_9
BattleTower_EventScript_TryCableLink_1:
	end

BattleTower_EventScript_TryCableLink_3:
	goto BattleTower_EventScript_CableLinkSuccessful
	goto BattleTower_EventScript_TryCableLink_1

BattleTower_EventScript_TryCableLink_4:
	goto CableClub_EventScript_AbortLinkSomeoneNotReady
	goto BattleTower_EventScript_TryCableLink_1

BattleTower_EventScript_TryCableLink_5:
	goto BattleTower_EventScript_AbortLinkDifferentSelections
	goto BattleTower_EventScript_TryCableLink_1

BattleTower_EventScript_TryCableLink_6:
	goto BattleTower_EventScript_AbortLinkIncorrectNumberOfPlayers
	goto BattleTower_EventScript_TryCableLink_1

BattleTower_EventScript_TryCableLink_7:
	goto BattleTower_EventScript_CancelChallenge
	goto BattleTower_EventScript_TryCableLink_1

BattleTower_EventScript_TryCableLink_8:
	goto CableClub_EventScript_AbortLinkConnectionError
	goto BattleTower_EventScript_TryCableLink_1

BattleTower_EventScript_TryCableLink_9:
	goto BattleTower_EventScript_AbortLink
	goto BattleTower_EventScript_TryCableLink_1


BattleTower_EventScript_AbortLinkDifferentSelections::
	special CloseLink
	compare VAR_0x8005, 3
	goto_if_eq BattleTower_EventScript_AbortLinkDifferentSelections_2
BattleTower_EventScript_AbortLinkDifferentSelections_1:
	msgbox Text_PlayersMadeDifferentSelections, MSGBOX_DEFAULT
	release
	end

BattleTower_EventScript_AbortLinkDifferentSelections_2:
	goto BattleTower_EventScript_FriendDifferentSelection
	goto BattleTower_EventScript_AbortLinkDifferentSelections_1


BattleTower_EventScript_FriendDifferentSelection::
	msgbox BattleTower_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
	msgbox BattleTower_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
	release
	end


BattleTower_EventScript_AbortLinkIncorrectNumberOfPlayers::
	msgbox BattleTower_Text_LinkMultiOnlyForTwoPlayers, MSGBOX_DEFAULT
	special CloseLink
	msgbox CableClub_Text_IncorrectNumberOfParticipants, MSGBOX_DEFAULT
	release
	end


BattleTower_EventScript_AbortLink::
	special CloseLink
	switch VAR_0x8005
	case 0, BattleTower_EventScript_AbortLink_3
	case 1, BattleTower_EventScript_AbortLink_4
	case 2, BattleTower_EventScript_AbortLink_5
BattleTower_EventScript_AbortLink_1:
	msgbox BattleTower_Text_ChooseDifferentMonsMatchLvlMode, MSGBOX_DEFAULT
	release
	end

BattleTower_EventScript_AbortLink_3:
	msgbox BattleTower_Text_FriendChoseDifferentLvlMode, MSGBOX_DEFAULT
	goto BattleTower_EventScript_AbortLink_1

BattleTower_EventScript_AbortLink_4:
	msgbox BattleTower_Text_FriendAlsoSelectedMon, MSGBOX_DEFAULT
	goto BattleTower_EventScript_AbortLink_1

BattleTower_EventScript_AbortLink_5:
	msgbox BattleTower_Text_FriendAlsoSelectedMons, MSGBOX_DEFAULT
	goto BattleTower_EventScript_AbortLink_1


BattleTower_EventScript_CableLinkSuccessful::
	call BattleTower_EventScript_LinkSuccessful
	special TrySetBattleTowerLinkType
	goto BattleTower_EventScript_EnterElevator
	end


BattleTower_EventScript_LinkSuccessful::
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	message BattleTower_Text_SaveGameBeforeShowingIn
	waitmessage
	tower_save CHALLENGE_STATUS_SAVING
	special SaveForBattleTowerLink
	waitstate
	playse SE_SAVE
	waitse
	return


BattleTower_EventScript_ExplainChallenge::
	switch VAR_LAST_TALKED
	case 1, BattleTower_EventScript_ExplainChallenge_3
	case 2, BattleTower_EventScript_ExplainChallenge_4
	case 3, BattleTower_EventScript_ExplainChallenge_5
	case 4, BattleTower_EventScript_ExplainChallenge_6
BattleTower_EventScript_ExplainChallenge_1:
	goto BattleTower_EventScript_AskEnterChallenge
	end

BattleTower_EventScript_ExplainChallenge_3:
	msgbox BattleTower_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ExplainChallenge_1

BattleTower_EventScript_ExplainChallenge_4:
	msgbox BattleTower_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ExplainChallenge_1

BattleTower_EventScript_ExplainChallenge_5:
	msgbox BattleTower_Text_ExplainMultisChallenge, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ExplainChallenge_1

BattleTower_EventScript_ExplainChallenge_6:
	msgbox BattleTower_Text_ExplainLinkMultisChallenge, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ExplainChallenge_1


BattleTower_EventScript_ShowResults::
	lockall
	switch VAR_RESULT
	case FRONTIER_MODE_SINGLES, BattleTower_EventScript_ShowResults_3
	case FRONTIER_MODE_DOUBLES, BattleTower_EventScript_ShowResults_4
	case FRONTIER_MODE_MULTIS, BattleTower_EventScript_ShowResults_5
	case FRONTIER_MODE_LINK_MULTIS, BattleTower_EventScript_ShowResults_6
BattleTower_EventScript_ShowResults_1:
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleTower_EventScript_ShowResults_3:
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_SINGLES
	goto BattleTower_EventScript_ShowResults_1

BattleTower_EventScript_ShowResults_4:
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_DOUBLES
	goto BattleTower_EventScript_ShowResults_1

BattleTower_EventScript_ShowResults_5:
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_MULTIS
	goto BattleTower_EventScript_ShowResults_1

BattleTower_EventScript_ShowResults_6:
	frontier_results FRONTIER_FACILITY_TOWER, FRONTIER_MODE_LINK_MULTIS
	goto BattleTower_EventScript_ShowResults_1


BattleTower_EventScript_ShowSinglesResults::
	setvar VAR_RESULT, FRONTIER_MODE_SINGLES
	goto BattleTower_EventScript_ShowResults
	return


BattleTower_EventScript_ShowDoublesResults::
	setvar VAR_RESULT, FRONTIER_MODE_DOUBLES
	goto BattleTower_EventScript_ShowResults
	return


BattleTower_EventScript_ShowMultisResults::
	setvar VAR_RESULT, FRONTIER_MODE_MULTIS
	goto BattleTower_EventScript_ShowResults
	return


BattleTower_EventScript_ShowLinkMultisResults::
	setvar VAR_RESULT, FRONTIER_MODE_LINK_MULTIS
	goto BattleTower_EventScript_ShowResults
	return


BattleTower_EventScript_NotEnoughValidMons::
	call BattleTower_EventScript_GetModeandFormat
	switch VAR_0x8007
	case 51, BattleTower_EventScript_NotEnoughValidMons_3
	case 52, BattleTower_EventScript_NotEnoughValidMons_4
	case 53, BattleTower_EventScript_NotEnoughValidMons_5
	case 101, BattleTower_EventScript_NotEnoughValidMons_6
	case 102, BattleTower_EventScript_NotEnoughValidMons_7
	case 103, BattleTower_EventScript_NotEnoughValidMons_8
BattleTower_EventScript_NotEnoughValidMons_1:
	release
	end

BattleTower_EventScript_NotEnoughValidMons_3:
	msgbox BattleTower_Text_NotEnoughValidMonsLv50Singles, MSGBOX_DEFAULT
	goto BattleTower_EventScript_NotEnoughValidMons_1

BattleTower_EventScript_NotEnoughValidMons_4:
	msgbox BattleTower_Text_NotEnoughValidMonsLv50Doubles, MSGBOX_DEFAULT
	goto BattleTower_EventScript_NotEnoughValidMons_1

BattleTower_EventScript_NotEnoughValidMons_5:
	msgbox BattleTower_Text_NotEnoughValidMonsLv50Multis, MSGBOX_DEFAULT
	goto BattleTower_EventScript_NotEnoughValidMons_1

BattleTower_EventScript_NotEnoughValidMons_6:
	msgbox BattleTower_Text_NotEnoughValidMonsLvOpenSingles, MSGBOX_DEFAULT
	goto BattleTower_EventScript_NotEnoughValidMons_1

BattleTower_EventScript_NotEnoughValidMons_7:
	msgbox BattleTower_Text_NotEnoughValidMonsLvOpenDoubles, MSGBOX_DEFAULT
	goto BattleTower_EventScript_NotEnoughValidMons_1

BattleTower_EventScript_NotEnoughValidMons_8:
	msgbox BattleTower_Text_NotEnoughValidMonsLvOpenMultis, MSGBOX_DEFAULT
	goto BattleTower_EventScript_NotEnoughValidMons_1


BattleTower_EventScript_GetModeandFormat::
	setvar VAR_0x8007, 0
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleTower_EventScript_GetModeandFormat_3
	case FRONTIER_LVL_OPEN, BattleTower_EventScript_GetModeandFormat_4
	addvar VAR_0x8007, 200
BattleTower_EventScript_GetModeandFormat_1:
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_EventScript_GetModeandFormat_8
	case FRONTIER_MODE_DOUBLES, BattleTower_EventScript_GetModeandFormat_9
	addvar VAR_0x8007, 3
BattleTower_EventScript_GetModeandFormat_6:
	return

BattleTower_EventScript_GetModeandFormat_3:
	addvar VAR_0x8007, 50
	goto BattleTower_EventScript_GetModeandFormat_1

BattleTower_EventScript_GetModeandFormat_4:
	addvar VAR_0x8007, 100
	goto BattleTower_EventScript_GetModeandFormat_1

BattleTower_EventScript_GetModeandFormat_8:
	addvar VAR_0x8007, 1
	goto BattleTower_EventScript_GetModeandFormat_6

BattleTower_EventScript_GetModeandFormat_9:
	addvar VAR_0x8007, 2
	goto BattleTower_EventScript_GetModeandFormat_6


BattleTower_EventScript_LoadPartyCancelChallenge::
	goto BattleTower_EventScript_CancelChallenge
	return


BattleTower_EventScript_CancelChallenge::
	special CloseLink
	msgbox BattleTower_Text_LookForwardToAnotherChallenge, MSGBOX_DEFAULT
	release
	end


BattleTower_EventScript_EnterElevator::
	incrementgamestat GAME_STAT_ENTERED_BATTLE_TOWER
	setvar VAR_0x8004, FRONTIER_UTIL_FUNC_SET_PARTY_ORDER
	call BattleTower_EventScript_GetPartySize
	special CallFrontierUtilFunc
	setvar VAR_RESULT, 0
	goto BattleTower_EventScript_WaitForLinkOpponentLoad
	return


BattleTower_EventScript_WaitForLinkOpponentLoad::
	tower_loadlinkopponents
	delay 1
	compare VAR_RESULT, 6
	goto_if_ne BattleTower_EventScript_WaitForLinkOpponentLoad_2
BattleTower_EventScript_WaitForLinkOpponentLoad_1:
	call BattleTower_EventScript_ShowYouToBattleRoom
	clearflag FLAG_CANCEL_BATTLE_ROOM_CHALLENGE
	setflag FLAG_HIDE_FACILITY_OPPONENT
	setvar VAR_TEMP_0, 0
	warp MAP_HAIGHTASHBURY_GYM_BATTLE_ROOM, 4, 8
	waitstate
	end

BattleTower_EventScript_WaitForLinkOpponentLoad_2:
	goto BattleTower_EventScript_WaitForLinkOpponentLoad
	goto BattleTower_EventScript_WaitForLinkOpponentLoad_1


BattleTower_EventScript_ShowYouToBattleRoom::
	call BattleTower_EventScript_BufferModeText
	compare VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_LINK_MULTIS
	goto_if_eq BattleTower_EventScript_ShowYouToBattleRoom_2
	msgbox BattleTower_Text_ShowYouToBattleRoom, MSGBOX_DEFAULT
BattleTower_EventScript_ShowYouToBattleRoom_1:
	call BattleTower_EventScript_WalkToElevator
	return

BattleTower_EventScript_ShowYouToBattleRoom_2:
	messageautoscroll BattleTower_Text_ShowYouToBattleRoom
	waitmessage
	delay 48
	goto BattleTower_EventScript_ShowYouToBattleRoom_1


BattleTower_EventScript_WalkToElevator::
	closemessage
	call BattleTower_EventScript_SetAttendantTalkedTo
	call BattleTower_EventScript_GetDoorXCoord
	applymovement VAR_LAST_TALKED, BattleTower_StepAside_Movement
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Movement_WalkToElevator
	waitmovement 0
	opendoor VAR_0x8004, 1
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, BattleTower_Movement_PlayerEnterElevator
	waitmovement 0
	closedoor VAR_0x8004, 1
	waitdooranim
	return


BattleTower_StepAside_Movement:
	walk_right
	face_left
	step_end

BattleTower_Movement_WalkToElevator:
	walk_up
	walk_up
	walk_up
	step_end

BattleTower_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleTower_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

BattleTower_EventScript_BufferModeText::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_EventScript_BufferModeText_3
	case FRONTIER_MODE_DOUBLES, BattleTower_EventScript_BufferModeText_4
	case FRONTIER_MODE_MULTIS, BattleTower_EventScript_BufferModeText_5
	case FRONTIER_MODE_LINK_MULTIS, BattleTower_EventScript_BufferModeText_6
BattleTower_EventScript_BufferModeText_1:
	return

BattleTower_EventScript_BufferModeText_3:
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	goto BattleTower_EventScript_BufferModeText_1

BattleTower_EventScript_BufferModeText_4:
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	goto BattleTower_EventScript_BufferModeText_1

BattleTower_EventScript_BufferModeText_5:
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	goto BattleTower_EventScript_BufferModeText_1

BattleTower_EventScript_BufferModeText_6:
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	goto BattleTower_EventScript_BufferModeText_1


BattleTower_EventScript_SetAttendantTalkedTo::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_EventScript_SetAttendantTalkedTo_3
	case FRONTIER_MODE_DOUBLES, BattleTower_EventScript_SetAttendantTalkedTo_4
	case FRONTIER_MODE_MULTIS, BattleTower_EventScript_SetAttendantTalkedTo_5
	case FRONTIER_MODE_LINK_MULTIS, BattleTower_EventScript_SetAttendantTalkedTo_6
BattleTower_EventScript_SetAttendantTalkedTo_1:
	return

BattleTower_EventScript_SetAttendantTalkedTo_3:
	setvar VAR_LAST_TALKED, 1
	goto BattleTower_EventScript_SetAttendantTalkedTo_1

BattleTower_EventScript_SetAttendantTalkedTo_4:
	setvar VAR_LAST_TALKED, 2
	goto BattleTower_EventScript_SetAttendantTalkedTo_1

BattleTower_EventScript_SetAttendantTalkedTo_5:
	setvar VAR_LAST_TALKED, 3
	goto BattleTower_EventScript_SetAttendantTalkedTo_1

BattleTower_EventScript_SetAttendantTalkedTo_6:
	setvar VAR_LAST_TALKED, 4
	goto BattleTower_EventScript_SetAttendantTalkedTo_1


BattleTower_EventScript_GetDoorXCoord::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_EventScript_GetDoorXCoord_3
	case FRONTIER_MODE_DOUBLES, BattleTower_EventScript_GetDoorXCoord_4
	case FRONTIER_MODE_MULTIS, BattleTower_EventScript_GetDoorXCoord_5
	case FRONTIER_MODE_LINK_MULTIS, BattleTower_EventScript_GetDoorXCoord_6
BattleTower_EventScript_GetDoorXCoord_1:
	return

BattleTower_EventScript_GetDoorXCoord_3:
	setvar VAR_0x8004, 6
	goto BattleTower_EventScript_GetDoorXCoord_1

BattleTower_EventScript_GetDoorXCoord_4:
	setvar VAR_0x8004, 10
	goto BattleTower_EventScript_GetDoorXCoord_1

BattleTower_EventScript_GetDoorXCoord_5:
	setvar VAR_0x8004, 14
	goto BattleTower_EventScript_GetDoorXCoord_1

BattleTower_EventScript_GetDoorXCoord_6:
	setvar VAR_0x8004, 18
	goto BattleTower_EventScript_GetDoorXCoord_1


BattleTower_EventScript_GetPartySize::
	switch VAR_FRONTIER_BATTLE_MODE
	case FRONTIER_MODE_SINGLES, BattleTower_EventScript_GetPartySize_3
	case FRONTIER_MODE_DOUBLES, BattleTower_EventScript_GetPartySize_4
	case FRONTIER_MODE_MULTIS, BattleTower_EventScript_GetPartySize_5
	case FRONTIER_MODE_LINK_MULTIS, BattleTower_EventScript_GetPartySize_6
BattleTower_EventScript_GetPartySize_1:
	return

BattleTower_EventScript_GetPartySize_3:
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	goto BattleTower_EventScript_GetPartySize_1

BattleTower_EventScript_GetPartySize_4:
	setvar VAR_0x8005, FRONTIER_DOUBLES_PARTY_SIZE
	goto BattleTower_EventScript_GetPartySize_1

BattleTower_EventScript_GetPartySize_5:
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleTower_EventScript_GetPartySize_1

BattleTower_EventScript_GetPartySize_6:
	setvar VAR_0x8005, FRONTIER_MULTI_PARTY_SIZE
	goto BattleTower_EventScript_GetPartySize_1


BattleTower_EventScript_RulesBoard::
	lockall
	msgbox BattleTower_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ReadRulesBoard
	end


BattleTower_EventScript_ReadRulesBoard::
	message BattleTower_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_TOWER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleTower_EventScript_ReadRulesBoard_3
	case 1, BattleTower_EventScript_ReadRulesBoard_4
	case 2, BattleTower_EventScript_ReadRulesBoard_5
	case 3, BattleTower_EventScript_ReadRulesBoard_6
	case 4, BattleTower_EventScript_ReadRulesBoard_7
	case MULTI_B_PRESSED, BattleTower_EventScript_ReadRulesBoard_7
BattleTower_EventScript_ReadRulesBoard_1:
	goto BattleTower_EventScript_ReadRulesBoard
	end

BattleTower_EventScript_ReadRulesBoard_3:
	msgbox BattleTower_Text_ExplainTowerRules, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ReadRulesBoard_1

BattleTower_EventScript_ReadRulesBoard_4:
	msgbox BattleTower_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ReadRulesBoard_1

BattleTower_EventScript_ReadRulesBoard_5:
	msgbox BattleTower_Text_ExplainSalonRules, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ReadRulesBoard_1

BattleTower_EventScript_ReadRulesBoard_6:
	msgbox BattleTower_Text_ExplainMultiLinkRules, MSGBOX_DEFAULT
	goto BattleTower_EventScript_ReadRulesBoard_1

BattleTower_EventScript_ReadRulesBoard_7:
	releaseall
	end


BattleFrontier_EventScript_GetCantRecordBattle2::
	frontier_get FRONTIER_DATA_RECORD_DISABLED
	return


BattleFrontier_EventScript_GetLvlMode2::
	frontier_get FRONTIER_DATA_LVL_MODE
	return


BattleTower_Text_DirectYouToBattleRoom::
	.string "I'll direct you to your BATTLE ROOM now.$"

BattleTower_Text_DidntSaveBeforeQuitting::
	.string "Excuse me!\p"
	.string "You didn't save before you quit your\n"
	.string "challenge last time.\p"
	.string "Because of that, your challenge so far\n"
	.string "has been disqualified. Sorry!$"

BattleTower_Text_CongratsBeatenSeven::
	.string "Congratulations! You've beaten all 10\n"
	.string "Trainers!\p"
	.string "$"

BattleTower_Text_ReceivedPrize::
	.string "{PLAYER} received the prize\n"
	.string "{STR_VAR_1}.$"

BattleTower_Text_ThankYouForPlaying::
	.string "Thank you for playing!\p"
	.string "$"

BattleTower_Text_RecordWillBeSaved::
	.string "Your record will be saved. Please wait.$"

BattleTower_Text_WeveBeenWaitingForYou::
	.string "We've been waiting for you!\p"
	.string "$"

BattleTower_Text_ProgressWillBeSaved::
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress will be saved. Please wait.$"

BattleTower_Text_AboutToFace50thTrainer::
	.string "You're finally about to face the 50th\n"
	.string "TRAINER.\p"
	.string "From here on, every time you beat seven\n"
	.string "TRAINERS in a row, your POKéMON will\l"
	.string "receive a commemorative RIBBON.\p"
	.string "Good luck!$"

BattleTower_Text_HereAreSomeRibbons::
	.string "Here are some RIBBONS for beating\n"
	.string "seven tough TRAINERS in a row.\p"
	.string "{PLAYER} received some RIBBONS!$"

BattleTower_Text_PutRibbonOnMons::
	.string "{PLAYER} put the RIBBONS on the\n"
	.string "challenger POKéMON.$"

BattleTower_Text_DescribeFeelingsAboutBattleTower::
	.string "Excuse me, do you have a moment?\p"
	.string "Can you describe your feelings when\n"
	.string "you're about to begin a BATTLE TOWER\l"
	.string "match, or when you've either won or\l"
	.string "lost a match?$"

BattleTower_Text_FeelWhatWhenYouBegin::
	.string "Okay, what are your feelings when\n"
	.string "you're about to begin a match?$"

BattleTower_Text_FeelWhatWhenYouveWon::
	.string "What do you feel when you've won a\n"
	.string "match?$"

BattleTower_Text_FeelWhatWhenYouveLost::
	.string "Can I hear about your feelings when you\n"
	.string "have lost a match?$"

BattleTower_Text_DontThinkMuchAboutIt::
	.string "Oh, so you don't think much about it?\n"
	.string "You're one cool customer.$"

BattleTower_Text_ChangedYourMind::
	.string "Hunh? You changed your mind? I guess\n"
	.string "you're fickle.$"

BattleTower_Text_ThatsHowYouFeel::
	.string "Okay, so that's how you feel? That's\n"
	.string "quite original.\p"
	.string "Thanks!$"

BattleTower_Text_WinsInRowRecorded::
	.string "The number of matches you win in a row\n"
	.string "is recorded.\p"
	.string "I'd better not get beaten in an\n"
	.string "embarrassing way!$"

BattleTower_Text_CanLeaveUntilLossOrSevenWins::
	.string "Once you've entered the BATTLE TOWER,\n"
	.string "you can't leave until you either lose or\l"
	.string "you beat seven TRAINERS in a row.\p"
	.string "You'd best be certain that you're up to\n"
	.string "the challenge.$"

BattleTower_Text_LookForwardToAnotherChallenge::
	.string "We look forward to seeing you on\n"
	.string "another challenge!$"

BattleTower_Text_WhichLevelMode::
	.string "The BATTLE ROOM offers two levels of\n"
	.string "challenge, Level 50 and Open Level.\l"
	.string "Which is your choice?$"

BattleTower_Text_OkayToSaveBeforeEntering::
	.string "Before entering a BATTLE ROOM, your\n"
	.string "progress must be saved. Is that okay?$"

BattleTower_Text_ShowYouToBattleRoom::
	.string "Right this way to the {STR_VAR_1}\n"
	.string "Battle Room. Good luck!$"

BattleTower_Text_RecordLastMatch::
	.string "Shall I record your last BATTLE TOWER\n"
	.string "match on your FRONTIER PASS?$"

BattleTower_Text_NotEnoughValidMonsLv50Singles::
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Text_NotEnoughValidMonsLvOpenSingles::
	.string "Excuse me!\p"
	.string "You don't have three eligible POKéMON.\p"
	.string "You must have three different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Text_NotEnoughValidMonsLv50Doubles::
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "of Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Text_NotEnoughValidMonsLvOpenDoubles::
	.string "Excuse me!\p"
	.string "You don't have four eligible POKéMON.\p"
	.string "You must have four different POKéMON\n"
	.string "to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Text_NotEnoughValidMonsLv50Multis::
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON of\n"
	.string "Level 50 or less to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Text_NotEnoughValidMonsLvOpenMultis::
	.string "Excuse me!\p"
	.string "You don't have two eligible POKéMON.\p"
	.string "You must have two different POKéMON to\n"
	.string "enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when you are ready.$"

BattleTower_Text_WelcomSingleBattle::
	.string "Where the talents of TRAINERS are put\n"
	.string "to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the SINGLE BATTLE\n"
	.string "ROOMS.$"

BattleTower_Text_TakeSinglesChallenge::
	.string "Would you like to take the SINGLE\n"
	.string "BATTLE ROOM challenge?$"

BattleTower_Text_ExplainSinglesChallenge::
	.string "The BATTLE TOWER's SINGLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "SINGLE BATTLES with three POKéMON.\p"
	.string "There are many SINGLE BATTLE ROOMS in\n"
	.string "the BATTLE TOWER for team battles.\p"
	.string "In each of the SINGLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven, you\n"
	.string "will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleTower_Text_SelectThreeMons::
	.string "Now please select the three POKéMON\n"
	.string "that are to be entered.$"

BattleTower_Text_WelcomeDoubleBattle::
	.string "Where the talents of TRAINERS are put\n"
	.string "to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the DOUBLE BATTLE\n"
	.string "ROOMS.$"

BattleTower_Text_TakeDoublesChallenge::
	.string "Would you like to take the DOUBLE\n"
	.string "BATTLE ROOM challenge?$"

BattleTower_Text_ExplainDoublesChallenge::
	.string "The BATTLE TOWER's DOUBLE BATTLE\n"
	.string "ROOMS are facilities for conducting\l"
	.string "DOUBLE BATTLES with four POKéMON.\p"
	.string "There are many DOUBLE BATTLE ROOMS in\n"
	.string "the BATTLE TOWER for team battles.\p"
	.string "In each of the DOUBLE BATTLE ROOMS,\n"
	.string "seven TRAINERS await your challenge.\p"
	.string "If you manage to defeat all seven, you\n"
	.string "will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleTower_Text_PleaseSelectFourMons::
	.string "Now please select the four POKéMON\n"
	.string "that are to be entered.$"

BattleTower_Text_WelcomeMultiBattle::
	.string "Where the talents of TRAINERS are put\n"
	.string "to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the MULTI BATTLE\n"
	.string "ROOMS.$"

BattleTower_Text_TakeMultisChallenge::
	.string "Would you like to take the MULTI BATTLE\n"
	.string "ROOM challenge?$"

BattleTower_Text_ExplainMultisChallenge::
	.string "The BATTLE TOWER's MULTI BATTLE ROOMS\n"
	.string "are facilities for conducting MULTI\l"
	.string "BATTLES.\p"
	.string "For MULTI BATTLES, you must partner\n"
	.string "with a TRAINER in the TOWER and enter\l"
	.string "with two POKéMON each.\p"
	.string "Inside the TOWER is a room named the\n"
	.string "BATTLE SALON where you may meet other\l"
	.string "TRAINERS.\p"
	.string "There, you must find a TRAINER to act\n"
	.string "as your partner in MULTI BATTLES.\p"
	.string "Once you have partnered up, you will be\n"
	.string "shown to a MULTI BATTLE ROOM.\p"
	.string "In the MULTI BATTLE ROOM, seven tag\n"
	.string "teams await your challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "If you want to interrupt your\n"
	.string "challenge, please save the game.\p"
	.string "If you don't save before interrupting,\n"
	.string "you will be disqualified.$"

BattleTower_Text_PleaseSelectTwoMons::
	.string "Now please select the two POKéMON that\n"
	.string "are to be entered.$"

BattleTower_Text_WelcomeLinkMultiBattle::
	.string "Where the talents of TRAINERS are put\n"
	.string "to the test!\p"
	.string "Welcome to the BATTLE TOWER!\p"
	.string "I am your guide to the LINK MULTI\n"
	.string "BATTLE ROOMS.$"

BattleTower_Text_TakeLinkMultisChallenge::
	.string "Would you like to take the LINK MULTI\n"
	.string "BATTLE ROOM challenge?$"

BattleTower_Text_ExplainLinkMultisChallenge::
	.string "The BATTLE TOWER's MULTI BATTLE ROOMS\n"
	.string "are facilities for conducting MULTI\l"
	.string "BATTLES with a friend.\p"
	.string "You must link with your friend using\n"
	.string "Wireless Adapters or a Game Boy\l"
	.string "Advance Game Link cable.\p"
	.string "You must partner with your friend and\n"
	.string "enter two different kinds of POKéMON.\p"
	.string "There are many MULTI BATTLE ROOMS in\n"
	.string "the BATTLE TOWER for team battles.\p"
	.string "In a MULTI BATTLE ROOM, seven tag\n"
	.string "teams await you and your friend to\l"
	.string "make a tag-team challenge.\p"
	.string "If you manage to defeat all seven\n"
	.string "teams, you will earn Battle Points.\p"
	.string "Please beware that unlike other ROOMS,\n"
	.string "you may not interrupt your challenge.\p"
	.string "Once you start, you must battle seven\n"
	.string "MULTI BATTLES in a row nonstop.$"

BattleTower_Text_LinkMultiOnlyForTwoPlayers::
	.string "The LINK MULTI BATTLE ROOM challenge\n"
	.string "is only for two linked players.$"

BattleTower_Text_FriendAlsoSelectedMon::
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1}.$"

BattleTower_Text_FriendAlsoSelectedMons::
	.string "Your friend has also selected the\n"
	.string "POKéMON {STR_VAR_1} and\l"
	.string "{STR_VAR_2}.$"

BattleTower_Text_FriendChoseDifferentLvlMode::
	.string "Your friend has chosen a different\n"
	.string "battle level.$"

BattleTower_Text_ChooseDifferentMonsMatchLvlMode::
	.string "Please choose two POKéMON different\n"
	.string "from your friend's, match the level you\l"
	.string "wish to enter, and register again.$"

BattleTower_Text_SaveGameBeforeShowingIn::
	.string "I will save the game before showing you\n"
	.string "in. Please wait.$"

BattleTower_Text_CongratsDefeatedMaiden::
	.string "Congratulations! You have defeated\n"
	.string "the SALON MAIDEN and swept seven\l"
	.string "TRAINERS!$"

BattleTower_Text_AwardYouTheseBattlePoints::
	.string "In recognition of your infinite talent,\n"
	.string "we award you these Battle Point(s).$"

BattleTower_Text_RulesAreListed::
	.string "The BATTLE TOWER rules are listed.$"

BattleTower_Text_ReadWhichHeading::
	.string "Which heading do you want to read?$"

BattleTower_Text_ExplainTowerRules::
	.string "The BATTLE TOWER is a facility where\n"
	.string "four types of battles are waged--\l"
	.string "SINGLE BATTLE, DOUBLE BATTLE, MULTI\l"
	.string "BATTLE, and LINK MULTI BATTLE.\p"
	.string "For each of these types, there are\n"
	.string "separate BATTLE ROOMS.\p"
	.string "Please speak with a guide offering the\n"
	.string "type of battle you wish to enter.$"

BattleTower_Text_ExplainMonRules::
	.string "Depending on the BATTLE ROOM you are\n"
	.string "entering, you will be required to take a\l"
	.string "certain number of POKéMON.\p"
	.string "The SINGLE BATTLE mode requires three\n"
	.string "POKéMON.\p"
	.string "The DOUBLE BATTLE mode requires four,\n"
	.string "and the MULTI modes both require two.$"

BattleTower_Text_ExplainSalonRules::
	.string "The BATTLE SALON is where you must find\n"
	.string "a partner to form a tag team for the\l"
	.string "MULTI BATTLE ROOM challenge.\p"
	.string "Choose the best partner for you by\n"
	.string "examining other TRAINERS' POKéMON and\l"
	.string "their moves.\p"
	.string "You may choose a new tag partner after\n"
	.string "winning seven straight matches.$"

BattleTower_Text_ExplainMultiLinkRules::
	.string "The LINK MULTI BATTLE Mode is for two\n"
	.string "friends to mount a challenge together.\p"
	.string "You and your friend must be linked with\n"
	.string "Wireless Adapters or a GBA Game Link\l"
	.string "cable.\p"
	.string "You must choose two POKéMON at the\n"
	.string "registration counter.\p"
	.string "These POKéMON must be different from\n"
	.string "those of your friend.\p"
	.string "You may not interrupt this challenge in\n"
	.string "the middle, unlike other modes.$"

BattleTower_Text_BattleRecordedOnPass::
	.string "{PLAYER}'s battle result was recorded\n"
	.string "on the FRONTIER PASS.$"
