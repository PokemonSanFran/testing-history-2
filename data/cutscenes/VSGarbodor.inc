VSGarbodor_Arrest_ObjectSetup_Script::
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFGOODTEAM
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFBADADMIN
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFTRANSRIVAL
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFBADBOSS
	setobjectxy 4, 26, 19
	setobjectxy 5, 26, 20
	setobjectxy 1, 21, 21
	setobjectxy 2, 21, 22
	setobjectxyperm 4, 26, 19
	setobjectxyperm 5, 26, 20
	setobjectxyperm 1, 21, 21
	setobjectxyperm 2, 21, 22
	return


VSGarbodor_Scouting_Dialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_IDidSomeScouting
	multichoicedefault 18, 6, MULTI_GARBADOR_CHOOSE, 3, TRUE
	goto VSGarbodor_ChooseSide_Script
	return


VSGarbodor_RandomSide_Script::
	random 2
	goto VSGarbodor_ChooseSide_Script
	return


VSGarbodor_ChooseSide_Script::
	switch VAR_RESULT
	case 0, VSGarbodor_ChooseSide_Script_2
	case 1, VSGarbodor_ChooseSide_Script_3
	case 2, VSGarbodor_ChooseSide_Script_4
	return

VSGarbodor_ChooseSide_Script_2:
	goto VSGarbodor_ChooseLeft_Script
	return

VSGarbodor_ChooseSide_Script_3:
	goto VSGarbodor_ChooseRight_Script
	return

VSGarbodor_ChooseSide_Script_4:
	goto VSGarbodor_RandomSide_Script
	return


VSGarbodor_ChooseLeft_Script::
	setvar VAR_ROUTE111_STATE, 1
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_ThenIllTakeTheRight
	callnative ClearMugshot
	closemessage
	applymovement 1, VSGarbodor_WalkFurtherRight
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, VSGarbodor_WalkTowardsLeftSide
	waitmovement 0
	removeobject 1
	releaseall
	end


VSGarbodor_ChooseRight_Script::
	setvar VAR_ROUTE111_STATE, 2
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_CoolIWanted
	callnative ClearMugshot
	closemessage
	applymovement 1, VSGarbodor_WalkFurtherLeft
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, VSGarbodor_WalkTowardsRightSide
	waitmovement 0
	removeobject 1
	releaseall
	end


VSGarbodor_PsfgoodteamGrunt1_Battle_Script::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_5, gText_VSGarbodor_ScrewThisStadium, gText_VSGarbodor_DamnTheyWereRight, VSGarbodor_PsfgoodteamGrunt1_Battle_Script
	msgbox gText_VSGarbodor_WelpIDidWhat, MSGBOX_AUTOCLOSE
	goto VSGarbodor_RemoveGrunt
	end


VSGarbodor_PsfgoodteamGrunt3_Battle_Script::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_3, gText_VSGarbodor_IsTheName, gText_VSGarbodor_TheyDidntPrepare, VSGarbodor_PsfgoodteamGrunt3_Battle_Script
	msgbox gText_VSGarbodor_OhThankGiratina, MSGBOX_AUTOCLOSE
	goto VSGarbodor_RemoveGrunt
	end


VSGarbodor_PsfgoodteamGrunt2_Battle_Script::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_2, gText_VSGarbodor_RightOnCue, gText_VSGarbodor_HmmIGuess, VSGarbodor_PsfgoodteamGrunt2_Battle_Script
	msgbox gText_VSGarbodor_BeingBad, MSGBOX_AUTOCLOSE
	goto VSGarbodor_RemoveGrunt
	end


VSGarbodor_PsfgoodteamGrunt4_Battle_Script::
	trainerbattle_single TRAINER_GRUNT_AQUA_HIDEOUT_4, gText_VSGarbodor_LookAtYou, gText_VSGarbodor_ThatsRight, VSGarbodor_PsfgoodteamGrunt4_Battle_Script
	msgbox gText_VSGarbodor_HaveFunCleaning, MSGBOX_AUTOCLOSE
	goto VSGarbodor_RemoveGrunt
	end


VS_Garbodor_CoreEncounter_Script::
	call Common_EventScript_SaveGame
	faceplayer
	setwildbattle SPECIES_GARBODOR, 40, ITEM_NONE
	waitse
	playmoncry SPECIES_GARBODOR, CRY_MODE_ENCOUNTER
	msgbox gText_VSGarbodor_Kuh
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_WON, VS_Garbodor_CoreEncounter_Script_3
VS_Garbodor_CoreEncounter_Script_1:
	release
	end

VS_Garbodor_CoreEncounter_Script_3:
	goto VSGarbodor_RemoveGrunt
	goto VS_Garbodor_CoreEncounter_Script_1


VSGarbodor_RemoveGrunt::
	lockall
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	call VSGarbodor_CheckDefeated_Script
	releaseall
	end


VSGarbodor_CheckDefeated_Script::
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, VSGarbodor_CheckDefeated_Script_4
VSGarbodor_CheckDefeated_Script_1:
	end

VSGarbodor_CheckDefeated_Script_2:
	goto VSGarbodor_MovePsftransrival_Script
	goto VSGarbodor_CheckDefeated_Script_1

VSGarbodor_CheckDefeated_Script_3:
	goto_if_set FLAG_DEFEATED_VOLTORB_1_NEW_MAUVILLE, VSGarbodor_CheckDefeated_Script_7
	goto VSGarbodor_CheckDefeated_Script_1

VSGarbodor_CheckDefeated_Script_4:
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, VSGarbodor_CheckDefeated_Script_3
	goto VSGarbodor_CheckDefeated_Script_1

VSGarbodor_CheckDefeated_Script_7:
	goto_if_set FLAG_DEFEATED_VOLTORB_2_NEW_MAUVILLE, VSGarbodor_CheckDefeated_Script_2
	goto VSGarbodor_CheckDefeated_Script_1


VSGarbodor_PreventCrossingSides_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_FeelingLonely
	closemessage
	callnative ClearMugshot
	compare VAR_ROUTE111_STATE, 2
	goto_if_eq VSGarbodor_PreventCrossingSides_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
VSGarbodor_PreventCrossingSides_Script_1:
	waitmovement 0
	releaseall
	end

VSGarbodor_PreventCrossingSides_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	goto VSGarbodor_PreventCrossingSides_Script_1


VSGarbodor_MovePsftransrival_Script::
	setvar VAR_ROUTE112_STATE, 1
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	clearflag FLAG_TEMP_1
	addobject 1
	compare VAR_TEMP_0, 10
	goto_if_lt VSGarbodor_MovePsftransrival_Script_2
	compare VAR_TEMP_1, 9
	goto_if_gt VSGarbodor_MovePsftransrival_Script_8
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	setobjectxy 1, 10, 6
	copyobjectxytoperm 1
	applymovement 1, PsftransrivalApproachNE
VSGarbodor_MovePsftransrival_Script_1:
	waitmovement 0
	goto VSGarbodor_DefeatedAll_Dialogue
	return

VSGarbodor_MovePsftransrival_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	compare VAR_TEMP_1, 9
	goto_if_gt VSGarbodor_MovePsftransrival_Script_5
	setobjectxy 1, 13, 6
	copyobjectxytoperm 1
	applymovement 1, PsftransrivalApproachNW
	goto VSGarbodor_MovePsftransrival_Script_1

VSGarbodor_MovePsftransrival_Script_5:
	setobjectxy 1, 11, 12
	copyobjectxytoperm 1
	applymovement 1, PsftransrivalApproachSW
	goto VSGarbodor_MovePsftransrival_Script_1

VSGarbodor_MovePsftransrival_Script_8:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setobjectxy 1, 22, 4
	copyobjectxytoperm 1
	applymovement 1, PsftransrivalApproachSE
	goto VSGarbodor_MovePsftransrival_Script_1


VSGarbodor_DefeatedAll_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_GodYouWereTaking
	closemessage
	callnative ClearMugshot
	applymovement 1, VSGarbodor_LookAround
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_WhateverMineWereEasy
	closemessage
	callnative ClearMugshot
	warpsilent MAP_PSFROUTE22, 255, 20, 22
	delay 100
	return


VSGarbodor_Arrest_Script::
	setvar VAR_STORYLINE_STATE, 20
	setvar VAR_ROUTE112_STATE, 2
	setvar VAR_ROUTE110_STATE, 4
	applymovement 14, Common_Movement_FaceUp
	applymovement 1, Common_Movement_FaceUp
	applymovement 2, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement 4, VSGarbodor_PerpWalk
	applymovement 5, VSGarbodor_PerpWalk
	applymovement 12, VSGarbodor_PerpWalk
	applymovement 13, VSGarbodor_PerpWalk
	waitmovement 0
	call VSGarbodor_CleanUpPerpWalk
	applymovement 14, Common_Movement_FaceDown
	applymovement 1, Common_Movement_FaceDown
	waitmovement 0
	goto VSGarbodor_Negotiating_Dialogue
	return


VSGarbodor_CleanUpPerpWalk::
	removeobject 4
	removeobject 5
	removeobject 12
	removeobject 13
	removeobject 3
	return


VSGarbodor_Arrest_ObjectCleanup_Script::
	removeobject 2
	removeobject 14
	setflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFBADADMIN
	return


VSGarbodor_Negotiating_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_VSGarbodor_AsWeWereNegotiating
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_DoneLikeYouGuys
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_VSGarbodor_ThankYouBoth
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_YeahImBeat, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq VSGarbodor_Negotiating_Dialogue_1
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_LetsBounce
	callnative ClearMugshot
	closemessage
	warpsilent MAP_PSFCITY8_COMPOUND_1F, 7, 3
	releaseall
	end

VSGarbodor_Negotiating_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_WeirdButOkay
	callnative ClearMugshot
	closemessage
	call VSGarbodor_FlyWithoutPlayer_Script
	releaseall
	end


VSGarbodor_FlyWithoutPlayer_Script::
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 1
	waitfieldeffect FLDEFF_NPCFLY_OUT
	return


VSGarbodor_ReturnToTheCompound_ObjectSetUp::
	setflag FLAG_TEMP_3
	setobjectxy 1, 7, 2
	setobjectxyperm 1, 7, 2
	setobjectmovementtype 1, MOVEMENT_ACTION_FACE_DOWN
	return


VSGarbodor_ReturnToTheCompound_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_ImGonnaGet
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_VSGarbodor_HehWellSee
	callnative ClearMugshot
	closemessage
	applymovement 1, VSGarbodor_WalkUpstairs
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	setvar VAR_STORYLINE_STATE, 21
	releaseall
	end


VSGarbodor_WalkTowardsLeftSide:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

VSGarbodor_WalkFurtherLeft:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VSGarbodor_WalkFurtherRight:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VSGarbodor_WalkTowardsRightSide:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

VSGarbodor_LookAround:
	face_up
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	step_end

PsftransrivalApproachSW:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PsftransrivalApproachNW:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PsftransrivalApproachSE:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

PsftransrivalApproachNE:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

VSGarbodor_PerpWalk:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

VSGarbodor_WalkUpstairs:
	walk_up
	step_end

gText_VSGarbodor_IDidSomeScouting::
	.string "I did some scouting while waiting for\n"
	.string "you. Both sides have two Garbodor and\l"
	.string "two Trainers guarding ‘em. Do you care\l"
	.string "which side you take?$"

gText_VSGarbodor_ThenIllTakeTheRight::
	.string "Then I'll take the right side. See you on\n"
	.string "the other side. Don't take too long!$"

gText_VSGarbodor_CoolIWanted::
	.string "Cool, I wanted the left side anyway. See\n"
	.string "you on the other side. Don't take too\l"
	.string "long!$"

gText_VSGarbodor_ScrewThisStadium::
	.string "Heh, we're Psfgoodteam! Screw this\n"
	.string "stadium and screw Psfbadguy!$"

gText_VSGarbodor_IsTheName::
	.string "Psfgoodteam is the name, and shutting\n"
	.string "this shit down is our game!$"

gText_VSGarbodor_DamnTheyWereRight::
	.string "Damn, they were right, you're strong…$"

gText_VSGarbodor_TheyDidntPrepare::
	.string "They didn't prepare us for this!$"

gText_VSGarbodor_WelpIDidWhat::
	.string "Welp, I did what I could! Good luck with\n"
	.string "that stinky shit.$"

gText_VSGarbodor_OhThankGiratina::
	.string "Oh thank Giratina, I can go back to the\n"
	.string "office now…$"

gText_VSGarbodor_Kuh::
	.string "Kuh!$"

gText_VSGarbodor_RightOnCue::
	.string "Right on cue, here come the heroes…$"

gText_VSGarbodor_LookAtYou::
	.string "Look at you, thinking you're making any\n"
	.string "difference!$"

gText_VSGarbodor_HmmIGuess::
	.string "Hmm, I guess I get to be the bad guy\n"
	.string "today!$"

gText_VSGarbodor_ThatsRight::
	.string "That's right, dance puppets!$"

gText_VSGarbodor_BeingBad::
	.string "Being bad was fun for a day!$"

gText_VSGarbodor_HaveFunCleaning::
	.string "Have fun cleaning up after us, kid.$"

gText_VSGarbodor_FeelingLonely::
	.string "Feeling lonely over there? I got this\n"
	.string "side, you handle that side!$"

gText_VSGarbodor_GodYouWereTaking::
	.string "God, you were taking forever. They don't\n"
	.string "teach efficiency in Orre, do they?$"

gText_VSGarbodor_WhateverMineWereEasy::
	.string "Whatever. Mine were easy, they just\n"
	.string "both used Self-Destruct before I\l"
	.string "could really get a move in. I already\l"
	.string "texted Psfbadadmin, he said meet in\l"
	.string "front of the construction site.$"

gText_VSGarbodor_AsWeWereNegotiating::
	.string "As we were negotiating, things started\n"
	.string "to get a little rowdy. The police aren't\l"
	.string "taking any chances this time, so\l"
	.string "they've halted escalation… for now.\l"
	.string "How's the Psfbadguy Task Force?$"

gText_VSGarbodor_DoneLikeYouGuys::
	.string "Done. Like you guys said, Psfgoodteam\n"
	.string "up to their shit as usual.$"

gText_VSGarbodor_ThankYouBoth::
	.string "Thank you both, and I'm sorry you had to\n"
	.string "get dragged into this. I'll work with\l"
	.string "our team to figure out what to do\l"
	.string "about the Championship. I think you\l"
	.string "two should head back to the Compound\l"
	.string "for now.$"

gText_VSGarbodor_YeahImBeat::
	.string "Yeah, I'm beat. Do you want a ride back\n"
	.string "to the Compound?$"

gText_VSGarbodor_WeirdButOkay::
	.string "Weird, but okay. I'll see you around.$"

gText_VSGarbodor_LetsBounce::
	.string "Let's bounce.$"

gText_VSGarbodor_ImGonnaGet::
	.string "I'm gonna get some sleep. Good shit on\n"
	.string "finishing your Badges. Can't wait to\l"
	.string "kick your ass at the Championship…\l"
	.string "whenever that is.$"

gText_VSGarbodor_HehWellSee::
	.string "Heh, we'll see. Good night.$"
