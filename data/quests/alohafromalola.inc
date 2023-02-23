Quest_Alohafromalola_SetGuardPosition_Script::
	returnqueststate QUEST_ALOHAFROMALOLA
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_ne Quest_Alohafromalola_SetGuardPosition_Script_2
	return

Quest_Alohafromalola_SetGuardPosition_Script_1:
	setflag FLAG_TEMP_2
	return

Quest_Alohafromalola_SetGuardPosition_Script_2:
	compare VAR_RESULT, QUEST_MENU_SET_REWARD
	goto_if_ne Quest_Alohafromalola_SetGuardPosition_Script_1
	return


Quest_Alohafromalola_GuardInteract_Script::
	lock
	returnqueststate QUEST_ALOHAFROMALOLA
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_eq Quest_Alohafromalola_GuardInteract_Script_2
	msgbox gText_Alohafromalola_TheresAPrivate, , SPEAKER_GUARD
	msgbox gText_Alohafromalola_WaitICanPerform, , SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_ANGRY
Quest_Alohafromalola_GuardInteract_Script_1:
	closemessage
	release
	end

Quest_Alohafromalola_GuardInteract_Script_2:
	msgbox gText_Alohafromalola_WeArePreparing, , SPEAKER_GUARD
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
	setflag FLAG_TEMP_3
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
	msgbox gText_Alohafromalola_OhManIAm, , SPEAKER_WHITNEY, TAIL_WHISPER, EMOTE_SAD
	msgbox gText_Alohafromalola_OhPlayer, , SPEAKER_WHITNEY, , EMOTE_SHOCK
	msgbox gText_Alohafromalola_HeyThere, , SPEAKER_ZOEY, , EMOTE_CONFUSE
	msgbox gText_Alohafromalola_ImSupposedTo, , SPEAKER_WHITNEY, , EMOTE_ANGRY
	msgbox gText_Alohafromalola_OhYouCan, , SPEAKER_WHITNEY, TAIL_SHOUT, EMOTE_SHOCK
	msgbox gText_Alohafromalola_ComeBackTonight, , SPEAKER_WHITNEY, , EMOTE_HAPPY
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
	random 1
	compare VAR_RESULT, 0
	goto_if_eq Quest_Alohafromalola_CheckParty_Script_2
Quest_Alohafromalola_CheckParty_Script_1:
	msgbox gText_Alohafromalola_YourParty, , SPEAKER_WHITNEY
	release
	end

Quest_Alohafromalola_CheckParty_Script_2:
	goto Quest_Alohafromalola_MoveToExhibition_Dialogue
	goto Quest_Alohafromalola_CheckParty_Script_1


Quest_Alohafromalola_MoveToExhibition_Dialogue::
	msgbox gText_Alohafromalola_PerfectDidYou, , SPEAKER_WHITNEY, , EMOTE_HAPPY
	setvar VAR_WHITNEY_STATE, EXHIBITION_READY
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warpsilent MAP_SOMA_GYM, 255, 11, 6
	return


Quest_Alohafromalola_CreateCrowd_Script::
	createvobject OBJ_EVENT_GFX_WOMAN_5, 5, 11, 3, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 6, 11, 4, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 7, 11, 5, 3, DIR_EAST
	createvobject OBJ_EVENT_GFX_WOMAN_5, 8, 11, 6, 3, DIR_EAST
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement OBJ_EVENT_ID_PLAYER
	return


Quest_Alohafromalola_SetLeaderPosition_Battle_Script::
	compare VAR_WHITNEY_STATE, EXHIBITION_READY
	goto_if_eq Quest_Alohafromalola_SetLeaderPosition_Battle_Script_1
	return

Quest_Alohafromalola_SetLeaderPosition_Battle_Script_1:
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	setobjectxy 1, 15, 6
	setobjectxyperm 1, 15, 6
	return


Quest_Alohafromalola_StartBattle_Dialogue::
	call Quest_Alohafromalola_CreateCrowd_Script
	msgbox gText_Alohafromalola_ThankYouAll, , SPEAKER_WHITNEY, TAIL_SHOUT, EMOTE_HAPPY
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 1
	setvar VAR_WHITNEY_STATE, EXHIBITION_COMPLETE
	trainerbattle_continue_after_lose TRAINER_ASHLEY, gText_Alohafromalola_AndZMoves
	delay 60
	warpsilent MAP_SOMA_MUSEUM_ENTRANCE, 255, 9, 13
	return


Quest_Alohafromalola_SetLeaderPosition_Thanks_Script::
	compare VAR_WHITNEY_STATE, EXHIBITION_COMPLETE
	goto_if_eq Quest_Alohafromalola_SetLeaderPosition_Thanks_Script_2
Quest_Alohafromalola_SetLeaderPosition_Thanks_Script_1:
	return

Quest_Alohafromalola_SetLeaderPosition_Thanks_Script_2:
	clearflag FLAG_TEMP_3
	setobjectxy 1, 9, 12
	setobjectxyperm 1, 9, 12
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	goto Quest_Alohafromalola_SetLeaderPosition_Thanks_Script_1


Quest_Alohafromalola_PostBattle_Script::
	lock
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_Alohafromalola_YouWereGreat, , SPEAKER_WHITNEY, , EMOTE_HAPPY
	msgbox gText_Alohafromalola_IRealizeNowYouDont, , SPEAKER_WHITNEY
	call Quest_Alohafromalola_GenerateRandomZCrystal_Script
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_Alohafromalola_WhitneyGaveYou
	msgbox gText_Alohafromalola_GoingToTheBar, , SPEAKER_WHITNEY, , EMOTE_SWEAT
	closemessage
	applymovement 1, Quest_Alohafromalola_WalkToExhibit_Movement
	fadescreen FADE_TO_BLACK
	delay 15
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
	walk_up
	walk_up
	walk_up
	step_end

gText_Alohafromalola_WeArePreparing::
	.string "We are preparing for a private\n"
	.string "exhibition opening. Please come back\l"
	.string "another time.$"

gText_Alohafromalola_TheresAPrivate::
	.string "There is a private exhibition opening\n"
	.string "tonight. Please come back another\l"
	.string "time.$"

gText_Alohafromalola_WaitICanPerform::
	.string "Wait, I can perform at the opening but I\n"
	.string "can't be there?$"

gText_Alohafromalola_OhManIAm::
	.string "Oh, this is an absolute mess. Worse than\n"
	.string "the blunder of Tohjo Falls, I'll say.$"

gText_Alohafromalola_OhPlayer::
	.string "Oh, {PLAYER}!$"

gText_Alohafromalola_HeyThere::
	.string "Hey Whitney, you seem... stressed?$"

gText_Alohafromalola_ImSupposedTo::
	.string "I'm supposed to have an exhibition\n"
	.string "battle against one of the Alola Island\l"
	.string "Kahunas tonight for the opening of our\l"
	.string "'Aloha from Alola' exhibit. I just\l"
	.string "recived a call telling me they're\l"
	.string "cancelling! People were coming for a\l"
	.string "real battle demonstration, and I don't\l"
	.string "have a suitable substiute...$"

gText_Alohafromalola_OhYouCan::
	.string "Oh! You! You're skilled!$"

gText_Alohafromalola_ComeBackTonight::
	.string "Come back tonight, with 3 Pokémon that\n"
	.string "can be found in Alola. You'll have to do\l"
	.string "on such short notice!$"

gText_Alohafromalola_YourParty::
	.string "Your party needs to be 3 Pokémon, and\n"
	.string "only those that can be found in Alola.\l"
	.string "You can look at the exhibit posters\l"
	.string "around the lobby if you're unsure of\l"
	.string "what Pokémon are found there.$"

gText_Alohafromalola_PerfectDidYou::
	.string "Your party looks perfect, and your\n"
	.string "timing is excellent. Let's get in there!$"

gText_Alohafromalola_ThankYouAll::
	.string "Thank you all for attending our\n"
	.string "exhibition! For our finale, {PLAYER}\l"
	.string "has graceiously offered to battle\l"
	.string "against the Alolan might of Z-Moves!$"

gText_Alohafromalola_AndZMoves::
	.string "Not even Z-Moves can stop you!$"

gText_Alohafromalola_YouWereGreat::
	.string "You were astounding! Thank you so much.$"

gText_Alohafromalola_IRealizeNowYouDont::
	.string "You won even though we weren't on an\n"
	.string "even playing field... but you can take\l"
	.string "this! I can get another one.$"

gText_Alohafromalola_WhitneyGaveYou::
	.string "{PLAYER} obtained a Z-Power Ring and\n"
	.string "a Z-Crystal!$"

gText_Alohafromalola_GoingToTheBar::
	.string "And now for some Alolan liberations!$"