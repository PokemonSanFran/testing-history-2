EnterPryce_StartBattle_ObjectSetup_Script::
	setobjectxyperm 1, 11, 10
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


EnterPryce_Event_Script::
	switch VAR_GYM_7_STATE
	case GYM_SAVE_BEFORE_LEADER, EnterPryce_Event_Script_2
	case GYM_DEFEATED_LEADER, EnterPryce_Event_Script_3
	case GYM_EXPLAINED_BADGE_AND_TM, EnterPryce_Event_Script_4
	goto EnterPryce_MumbleToSelf_Dialogue
	return

EnterPryce_Event_Script_2:
	goto EnterPryce_FacePlayerBeforeBattle_Script
	return

EnterPryce_Event_Script_3:
	goto EnterPryce_PostDefeat1_Dialogue
	return

EnterPryce_Event_Script_4:
	goto EnterPryce_PostDefeat2_Dialogue
	return


EnterPryce_MumbleToSelf_Dialogue::
	setvar VAR_GYM_7_STATE, GYM_SAVE_BEFORE_LEADER
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_StupidParade
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPryce_PaceLeftFrontOfDesk
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_TheyJustDontUnderstand
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPryce_PaceRightFrontOfDesk
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_LookIWasWilling
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPryce_HeyYouSeemBusy
	closemessage
	callnative ClearMugshot
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_ShitShitShit, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPryce_TakeDrugs
	waitmovement 0
	goto EnterPryce_CalculateMovement_Script
	return


EnterPryce_CalculateMovement_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 8, EnterPryce_CalculateMovement_Script_3
	case 9, EnterPryce_CalculateMovement_Script_4
	case 10, EnterPryce_CalculateMovement_Script_5
	case 11, EnterPryce_CalculateMovement_Script_6
	case 12, EnterPryce_CalculateMovement_Script_7
	case 13, EnterPryce_CalculateMovement_Script_8
	case 14, EnterPryce_CalculateMovement_Script_9
	case 15, EnterPryce_CalculateMovement_Script_10
	case 16, EnterPryce_CalculateMovement_Script_11
EnterPryce_CalculateMovement_Script_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto EnterPsf7leader_ExplainLab_Dialogue
	return

EnterPryce_CalculateMovement_Script_3:
	call EnterPryce_PlayerPosition8
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_4:
	call EnterPryce_PlayerPosition9
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_5:
	call EnterPryce_PlayerPosition10
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_6:
	call EnterPryce_PlayerPosition11
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_7:
	call EnterPryce_PlayerPosition12
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_8:
	call EnterPryce_PlayerPosition13
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_9:
	call EnterPryce_PlayerPosition14
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_10:
	call EnterPryce_PlayerPosition15
	goto EnterPryce_CalculateMovement_Script_1

EnterPryce_CalculateMovement_Script_11:
	call EnterPryce_PlayerPosition16
	goto EnterPryce_CalculateMovement_Script_1


EnterPryce_PlayerPosition8::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom8
	return


EnterPryce_PlayerPosition9::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom9
	return


EnterPryce_PlayerPosition10::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom10
	return


EnterPryce_PlayerPosition11::
	applymovement 1, EnterPryce_Pryce_WalkAroundToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom11
	return


EnterPryce_PlayerPosition12::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom12
	return


EnterPryce_PlayerPosition13::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom13
	return


EnterPryce_PlayerPosition14::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom14
	return


EnterPryce_PlayerPosition15::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom15
	return


EnterPryce_PlayerPosition16::
	applymovement 1, EnterPryce_Pryce_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPryce_MovePlayerFrom16
	return


EnterPsf7leader_ExplainLab_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_SoBackHere
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPryce_WaitDoesTheLeague
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPryce_StartBattle_Script
	return


EnterPryce_FacePlayerBeforeBattle_Script::
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_IDontKnow, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, gText_EnterPryce_UghIThinkThisBatch
	goto EnterPryce_PostBattle_Script
	return


EnterPryce_StartBattle_Script::
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_IDontKnow
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, gText_EnterPryce_UghIThinkThisBatch
	goto EnterPryce_PostBattle_Script
	return


EnterPryce_PostBattle_Script::
	lock
	setflag FLAG_BADGE07_GET
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_GYM_7_STATE, GYM_DEFEATED_LEADER
	msgbox gText_EnterPryce_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM07
	closemessage
	call EnterPryce_MoveBacktoDesk_Script
	waitmovement 0
	release
	end


EnterPryce_MoveBacktoDesk_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 12
	goto_if_ne EnterPryce_MoveBacktoDesk_Script_1
	applymovement 1, EnterPryce_WalkAroundBackToDesk
	return

EnterPryce_MoveBacktoDesk_Script_1:
	applymovement 1, EnterPryce_WalkBackToDesk
	return


EnterPryce_PostDefeat1_Dialogue::
	lock
	setvar VAR_GYM_7_STATE, GYM_DEFEATED_LEADER
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_TMAreLikeDrugs, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	applymovement 1, Common_Movement_FaceUp
	waitmovement 0
	release
	end


EnterPryce_PostDefeat2_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPryce_LetsSee
	closemessage
	callnative ClearMugshot
	release
	end


EnterPryce_PaceLeftFrontOfDesk:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

EnterPryce_PaceRightFrontOfDesk:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

EnterPryce_TakeDrugs:
	walk_left
	walk_left
	walk_in_place_slow_up
	step_end

EnterPryce_Pryce_WalkToBattlefield:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

EnterPryce_MovePlayerFrom8:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom9:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom10:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom11:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom12:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom13:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom14:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom15:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_MovePlayerFrom16:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPryce_Pryce_WalkAroundToBattlefield:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

EnterPryce_WalkBackToDesk:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EnterPryce_WalkAroundBackToDesk:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

gText_EnterPryce_StupidParade::
	.string "*grumble* stupid fucking parade…$"

gText_EnterPryce_TheyJustDontUnderstand::
	.string "*mutter* They just don't understand… it\n"
	.string "was either their way or the highway…\l"
	.string "and I kept the Gym! And now I'm the\l"
	.string "traitor?$"

gText_EnterPryce_LookIWasWilling::
	.string "*grumble* Look, I was willing to play ball,\n"
	.string "and I was rewarded. Haters gonna just\l"
	.string "hate…$"

gText_EnterPryce_HeyYouSeemBusy::
	.string "Hey, you seem busy, but are you Pryce?$"

gText_EnterPryce_ShitShitShit::
	.string "! Shit. Shit shit shit hi, are you a\n"
	.string "challenger? Hold on yeah, hold on. NOPE,\l"
	.string "not doing this sober, hold on… Lemme\l"
	.string "just…$"

gText_EnterPryce_SoBackHere::
	.string "So back here, I experiment with new\n"
	.string "synthetic drugs. Always trying to get\l"
	.string "an edge, you know? Let's see if I can\l"
	.string "battle under the influence of MGB-07.$"

gText_EnterPryce_WaitDoesTheLeague::
	.string "Wait, does the League let you battle\n"
	.string "under the influence like that?$"

gText_EnterPryce_IDontKnow::
	.string "I don't know the rules… but I'm sure\n"
	.string "they won't stop me either way. It's\l"
	.string "good to have power!$"

gText_EnterPryce_UghIThinkThisBatch::
	.string "Ugh, I think this batch makes me too\n"
	.string "nauseous…$"

gText_EnterPryce_TMAreLikeDrugs::
	.string "TMs are like drugs, right? They alter\n"
	.string "your brain chemistry and let you see\l"
	.string "stuff you'd never see otherwise… that\l"
	.string "one will teach Psfgymattack7.$"

gText_EnterPryce_LetsSee::
	.string "Let's see if I can bang out MGB-08 while\n"
	.string "I'm riding this high…$"

gText_EnterPryce_BadgeGet::
	.string "You received the PryceBadge Badge!$"
