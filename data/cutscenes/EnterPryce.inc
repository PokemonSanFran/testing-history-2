EnterPsfleader7_StartGymBattle_ObjectSetup::
	setobjectxyperm 1, 11, 10
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	end


EnterPsfleader7_Event_Script::
	switch VAR_GYM_7_STATE
	case 3, EnterPsfleader7_Event_Script_2
	case 4, EnterPsfleader7_Event_Script_3
	case 5, EnterPsfleader7_Event_Script_4
	goto EnterPsfleader7_MumbleToSelf_Dialogue
	return

EnterPsfleader7_Event_Script_2:
	goto EnterPsfleader7_FacePlayerBeforeBattle
	return

EnterPsfleader7_Event_Script_3:
	goto EnterPsfleader7_PostDefeat1_Dialogue
	return

EnterPsfleader7_Event_Script_4:
	goto EnterPsfleader7_PostDefeat2_Dialogue
	return


EnterPsfleader7_MumbleToSelf_Dialogue::
	setvar VAR_GYM_7_STATE, 3
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_StupidParade
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPsfleader7_PaceLeftFrontOfDesk
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_TheyJustDontUnderstand
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPsfleader7_PaceRightFrontOfDesk
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_LookIWasWilling
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_HeyYouSeemBusy
	closemessage
	callnative ClearMugshot
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_ShitShitShit, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterPsfleader7_TakeDrugs
	waitmovement 0
	call EnterPsfleader7_CalculateMovement_Script
	waitmovement 0
	return


EnterPsfleader7_CalculateMovement_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_0
	case 8, EnterPsfleader7_CalculateMovement_Script_3
	case 9, EnterPsfleader7_CalculateMovement_Script_4
	case 10, EnterPsfleader7_CalculateMovement_Script_5
	case 11, EnterPsfleader7_CalculateMovement_Script_6
	case 12, EnterPsfleader7_CalculateMovement_Script_7
	case 13, EnterPsfleader7_CalculateMovement_Script_8
	case 14, EnterPsfleader7_CalculateMovement_Script_9
	case 15, EnterPsfleader7_CalculateMovement_Script_10
	case 16, EnterPsfleader7_CalculateMovement_Script_11
EnterPsfleader7_CalculateMovement_Script_1:
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	goto EnterPsf7leader_ExplainLab_Dialogue
	return

EnterPsfleader7_CalculateMovement_Script_3:
	call EnterPsfleader7_PlayerPosition8
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_4:
	call EnterPsfleader7_PlayerPosition9
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_5:
	call EnterPsfleader7_PlayerPosition10
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_6:
	call EnterPsfleader7_PlayerPosition11
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_7:
	call EnterPsfleader7_PlayerPosition12
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_8:
	call EnterPsfleader7_PlayerPosition13
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_9:
	call EnterPsfleader7_PlayerPosition14
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_10:
	call EnterPsfleader7_PlayerPosition15
	goto EnterPsfleader7_CalculateMovement_Script_1

EnterPsfleader7_CalculateMovement_Script_11:
	call EnterPsfleader7_PlayerPosition16
	goto EnterPsfleader7_CalculateMovement_Script_1


EnterPsfleader7_PlayerPosition8::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom8
	return


EnterPsfleader7_PlayerPosition9::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom9
	return


EnterPsfleader7_PlayerPosition10::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom10
	return


EnterPsfleader7_PlayerPosition11::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkAroundToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom11
	return


EnterPsfleader7_PlayerPosition12::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom12
	return


EnterPsfleader7_PlayerPosition13::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom13
	return


EnterPsfleader7_PlayerPosition14::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom14
	return


EnterPsfleader7_PlayerPosition15::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom15
	return


EnterPsfleader7_PlayerPosition16::
	applymovement 1, EnterPsfleader7_Psfleader7_WalkToBattlefield
	applymovement OBJ_EVENT_ID_PLAYER, EnterPsfleader7_MovePlayerFrom16
	return


EnterPsf7leader_ExplainLab_Dialogue::
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_SoBackHere
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_WaitDoesTheLeague
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader7_StartGymBattle_Script
	return


EnterPsfleader7_FacePlayerBeforeBattle::
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_IDontKnow, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, gText_EnterPsfleader7_UghIThinkThisBatch
	goto EnterPsfleader7_Psfleader7Defeated_Script
	return


EnterPsfleader7_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_IDontKnow
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_TATE_AND_LIZA_1, gText_EnterPsfleader7_UghIThinkThisBatch
	goto EnterPsfleader7_Psfleader7Defeated_Script
	return


EnterPsfleader7_Psfleader7Defeated_Script::
	lockall
	setflag FLAG_BADGE07_GET
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_GYM_7_STATE, 4
	msgbox gText_EnterPsfleader7_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM07
	closemessage
	call EnterPsfleader7_MoveBacktoDesk_Script
	waitmovement 0
	releaseall
	end


EnterPsfleader7_MoveBacktoDesk_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 12
	goto_if_ne EnterPsfleader7_MoveBacktoDesk_Script_1
	applymovement 1, EnterPsfleader7_WalkAroundBackToDesk
	return

EnterPsfleader7_MoveBacktoDesk_Script_1:
	applymovement 1, EnterPsfleader7_WalkBackToDesk
	return


EnterPsfleader7_PostDefeat1_Dialogue::
	lockall
	setvar VAR_GYM_7_STATE, 5
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_TMAreLikeDrugs
	closemessage
	callnative ClearMugshot
	releaseall
	end


EnterPsfleader7_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_PRYCE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader7_LetsSee
	closemessage
	callnative ClearMugshot
	releaseall
	end


EnterPsfleader7_PaceLeftFrontOfDesk:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

EnterPsfleader7_PaceRightFrontOfDesk:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

EnterPsfleader7_TakeDrugs:
	walk_left
	walk_left
	walk_in_place_slow_up
	step_end

EnterPsfleader7_Psfleader7_WalkToBattlefield:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

EnterPsfleader7_MovePlayerFrom8:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EnterPsfleader7_MovePlayerFrom9:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPsfleader7_MovePlayerFrom10:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPsfleader7_MovePlayerFrom11:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPsfleader7_MovePlayerFrom12:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EnterPsfleader7_MovePlayerFrom13:
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

EnterPsfleader7_MovePlayerFrom14:
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

EnterPsfleader7_MovePlayerFrom15:
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

EnterPsfleader7_MovePlayerFrom16:
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

EnterPsfleader7_Psfleader7_WalkAroundToBattlefield:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

EnterPsfleader7_WalkBackToDesk:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

EnterPsfleader7_WalkAroundBackToDesk:
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

gText_EnterPsfleader7_StupidParade::
	.string "*grumble* stupid fucking parade…$"

gText_EnterPsfleader7_TheyJustDontUnderstand::
	.string "*mutter* They just don't understand… it\n"
	.string "was either their way or the highway…\l"
	.string "and I kept the Gym! And now I'm the\l"
	.string "traitor?$"

gText_EnterPsfleader7_LookIWasWilling::
	.string "*grumble* Look, I was willing to play ball,\n"
	.string "and I was rewarded. Haters gonna just\l"
	.string "hate…$"

gText_EnterPsfleader7_HeyYouSeemBusy::
	.string "Hey, you seem busy, but are you\n"
	.string "Psfleader7?$"

gText_EnterPsfleader7_ShitShitShit::
	.string "! Shit. Shit shit shit hi, are you a\n"
	.string "challenger? Hold on yeah, hold on. NOPE,\l"
	.string "not doing this sober, hold on… Lemme\l"
	.string "just…$"

gText_EnterPsfleader7_SoBackHere::
	.string "So back here, I experiment with new\n"
	.string "synthetic drugs. Always trying to get\l"
	.string "an edge, you know? Let's see if I can\l"
	.string "battle under the influence of MGB-07.$"

gText_EnterPsfleader7_WaitDoesTheLeague::
	.string "Wait, does the League let you battle\n"
	.string "under the influence like that?$"

gText_EnterPsfleader7_IDontKnow::
	.string "I don't know the rules… but I'm sure\n"
	.string "they won't stop me either way. It's\l"
	.string "good to have power!$"

gText_EnterPsfleader7_UghIThinkThisBatch::
	.string "Ugh, I think this batch makes me too\n"
	.string "nauseous…$"

gText_EnterPsfleader7_TMAreLikeDrugs::
	.string "TMs are like drugs, right? They alter\n"
	.string "your brain chemistry and let you see\l"
	.string "stuff you'd never see otherwise… that\l"
	.string "one will teach Psfgymattack7.$"

gText_EnterPsfleader7_LetsSee::
	.string "Let's see if I can bang out MGB-08 while\n"
	.string "I'm riding this high…$"

gText_EnterPsfleader7_BadgeGet::
	.string "You received the Psfbadge7 Badge!$"
