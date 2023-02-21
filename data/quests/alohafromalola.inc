Quest_Alohafromalola_SetGuardPosition::
	returnqueststate QUEST_ALOHAFROMALOLA
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_ne Quest_Alohafromalola_SetGuardPosition_2
	return

Quest_Alohafromalola_SetGuardPosition_1:
	setflag FLAG_TEMP_2
	return

Quest_Alohafromalola_SetGuardPosition_2:
	compare VAR_RESULT, QUEST_MENU_SET_REWARD
	goto_if_ne Quest_Alohafromalola_SetGuardPosition_1
	return


Quest_Alohafromalola_GuardInteract_Script::
	lock
	returnqueststate QUEST_ALOHAFROMALOLA
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_eq Quest_Alohafromalola_GuardInteract_Script_2
	msgbox gText_Alohafromalola_TheresAPrivate
	msgbox gText_Alohafromalola_WaitICanPerform
Quest_Alohafromalola_GuardInteract_Script_1:
	closemessage
	release
	end

Quest_Alohafromalola_GuardInteract_Script_2:
	msgbox gText_Alohafromalola_WeArePreparing
	goto Quest_Alohafromalola_GuardInteract_Script_1


Quest_Alohafromalola_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_WHITNEY_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_Alohafromalola_HideLeader_Script_2
	compare VAR_RESULT, 4
	goto_if_lt Quest_Alohafromalola_HideLeader_Script_2
Quest_Alohafromalola_HideLeader_Script_1:
	return

Quest_Alohafromalola_HideLeader_Script_2:
	setflag FLAG_TEMP_1
	goto Quest_Alohafromalola_HideLeader_Script_1


Quest_Alohafromalola_Interact_Event_Script::
	lock
	faceplayer
	returnqueststate QUEST_ALOHAFROMALOLA
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_eq Quest_Alohafromalola_Interact_Event_Script_1
	goto Quest_Alohafromalola_StartQuest_Dialogue
	return

Quest_Alohafromalola_Interact_Event_Script_1:
	goto Quest_Alohafromalola_CheckTime_Script
	return


Quest_Alohafromalola_StartQuest_Dialogue::
	msgbox gText_Alohafromalola_OhManIAm
	msgbox gText_Alohafromalola_OhPlayer
	msgbox gText_Alohafromalola_HeyThere
	msgbox gText_Alohafromalola_ImSupposedTo
	msgbox gText_Alohafromalola_OhYouCan
	msgbox gText_Alohafromalola_ComeBackTonight
	closemessage
	startquest QUEST_ALOHAFROMALOLA
	clearflag FLAG_TEMP_2
	addobject 2
	release
	end


Quest_Alohafromalola_GenerateRandomZCrystal_Script::
	additem ITEM_Z_POWER_RING, 1
	random 18
	switch VAR_RESULT
	case 0, Quest_Alohafromalola_GenerateRandomZCrystal_Script_3
	case 1, Quest_Alohafromalola_GenerateRandomZCrystal_Script_4
	case 2, Quest_Alohafromalola_GenerateRandomZCrystal_Script_5
	case 3, Quest_Alohafromalola_GenerateRandomZCrystal_Script_6
	case 4, Quest_Alohafromalola_GenerateRandomZCrystal_Script_7
	case 5, Quest_Alohafromalola_GenerateRandomZCrystal_Script_8
	case 6, Quest_Alohafromalola_GenerateRandomZCrystal_Script_9
	case 7, Quest_Alohafromalola_GenerateRandomZCrystal_Script_10
	case 8, Quest_Alohafromalola_GenerateRandomZCrystal_Script_11
	case 9, Quest_Alohafromalola_GenerateRandomZCrystal_Script_12
	case 10, Quest_Alohafromalola_GenerateRandomZCrystal_Script_13
	case 11, Quest_Alohafromalola_GenerateRandomZCrystal_Script_14
	case 12, Quest_Alohafromalola_GenerateRandomZCrystal_Script_15
	case 13, Quest_Alohafromalola_GenerateRandomZCrystal_Script_16
	case 14, Quest_Alohafromalola_GenerateRandomZCrystal_Script_17
	case 15, Quest_Alohafromalola_GenerateRandomZCrystal_Script_18
	case 16, Quest_Alohafromalola_GenerateRandomZCrystal_Script_19
	case 17, Quest_Alohafromalola_GenerateRandomZCrystal_Script_20
Quest_Alohafromalola_GenerateRandomZCrystal_Script_1:
	return

Quest_Alohafromalola_GenerateRandomZCrystal_Script_3:
	additem ITEM_BUGINIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_4:
	additem ITEM_DARKINIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_5:
	additem ITEM_DRAGONIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_6:
	additem ITEM_ELECTRIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_7:
	additem ITEM_FAIRIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_8:
	additem ITEM_FIGHTINIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_9:
	additem ITEM_FIRIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_10:
	additem ITEM_FLYINIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_11:
	additem ITEM_GHOSTIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_12:
	additem ITEM_GRASSIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_13:
	additem ITEM_GROUNDIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_14:
	additem ITEM_ICIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_15:
	additem ITEM_NORMALIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_16:
	additem ITEM_POISONIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_17:
	additem ITEM_PSYCHIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_18:
	additem ITEM_ROCKIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_19:
	additem ITEM_STEELIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1

Quest_Alohafromalola_GenerateRandomZCrystal_Script_20:
	additem ITEM_WATERIUM_Z, 1
	goto Quest_Alohafromalola_GenerateRandomZCrystal_Script_1


Quest_Alohafromalola_CheckTime_Script::
	gettime
	compare VAR_0x8000, 21
	goto_if_lt Quest_Alohafromalola_CheckTime_Script_3
Quest_Alohafromalola_CheckTime_Script_1:
	goto Quest_Alohafromalola_CheckParty_Script
	return

Quest_Alohafromalola_CheckTime_Script_2:
	msgbox gText_Alohafromalola_ComeBackTonight
	release
	end

Quest_Alohafromalola_CheckTime_Script_3:
	compare VAR_0x8000, 5
	goto_if_gt Quest_Alohafromalola_CheckTime_Script_2
	goto Quest_Alohafromalola_CheckTime_Script_1


Quest_Alohafromalola_CheckParty_Script::
	checkitemspace ITEM_POISONIUM_Z, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Alohafromalola_CheckParty_Script_2
Quest_Alohafromalola_CheckParty_Script_1:
	msgbox gText_Alohafromalola_YourParty
	release
	end

Quest_Alohafromalola_CheckParty_Script_2:
	goto Quest_Alohafromalola_MoveToExhibition_Dialogue
	goto Quest_Alohafromalola_CheckParty_Script_1


Quest_Alohafromalola_MoveToExhibition_Dialogue::
	msgbox gText_Alohafromalola_PerfectDidYou
	applymovement OBJ_EVENT_ID_PLAYER, Quest_Alohafromalola_WalkToExhibit_Movement
	applymovement 1, Quest_Alohafromalola_WalkToExhibit_Movement
	setvar VAR_WHITNEY_STATE, EXHIBITION_READY
	warpsilent MAP_SOMA_GYM, 0, 11, 17
	return


Quest_Alohafromalola_StartBattle_Dialogue::
	msgbox gText_Alohafromalola_ThankYouAll
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 1
	trainerbattle_continue_after_lose TRAINER_ASHLEY, gText_Alohafromalola_AndZMoves
	delay 60
	warpsilent MAP_SOMA_MUSEUM_ENTRANCE, 0, 9, 13
	return


Quest_Alohafromalola_SetLeaderPosition::
	setobjectxy 1, 8, 13
	turnobject 1, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return


Quest_Alohafromalola_PostBattle_Script::
	lock
	msgbox gText_Alohafromalola_YouWereGreat
	msgbox gText_Alohafromalola_IRealizeNowYouDont
	call Quest_Alohafromalola_GenerateRandomZCrystal_Script
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_Alohafromalola_WhitneyGaveYou
	msgbox gText_Alohafromalola_ImSureYouCan
	msgbox gText_Alohafromalola_GoingToTheBar
	applymovement 1, Quest_Alohafromalola_WalkToExhibit_Movement
	fadescreen FADE_TO_BLACK
	removeobject 1
	fadescreen FADE_FROM_BLACK
	setvar VAR_WHITNEY_STATE, QUEST_1_COMPLETE
	completequest QUEST_ALOHAFROMALOLA
	release
	end


Quest_Alohafromalola_WalkToExhibit_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_Alohafromalola_WeArePreparing::
	.string "$"

gText_Alohafromalola_TheresAPrivate::
	.string "$"

gText_Alohafromalola_WaitICanPerform::
	.string "$"

gText_Alohafromalola_OhManIAm::
	.string "$"

gText_Alohafromalola_OhPlayer::
	.string "$"

gText_Alohafromalola_HeyThere::
	.string "$"

gText_Alohafromalola_ImSupposedTo::
	.string "$"

gText_Alohafromalola_OhYouCan::
	.string "$"

gText_Alohafromalola_ComeBackTonight::
	.string "$"

gText_Alohafromalola_YourParty::
	.string "$"

gText_Alohafromalola_PerfectDidYou::
	.string "$"

gText_Alohafromalola_ThankYouAll::
	.string "$"

gText_Alohafromalola_AndZMoves::
	.string "$"

gText_Alohafromalola_YouWereGreat::
	.string "$"

gText_Alohafromalola_IRealizeNowYouDont::
	.string "$"

gText_Alohafromalola_WhitneyGaveYou::
	.string "{PLAYER} obtained a Z-Power Rang and\n"
	.string "a Z-Crystal!$"

gText_Alohafromalola_ImSureYouCan::
	.string "$"

gText_Alohafromalola_GoingToTheBar::
	.string "$"
