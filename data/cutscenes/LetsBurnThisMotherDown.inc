LetsBurnThisMotherDown_ObjectSetUp_Script::
	setobjectxy 2, 8, 6
	setobjectxyperm 2, 8, 6
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	return


LetsBurnThisMotherDown_ObjectMove_Script::
	clearflag FLAG_TEMP_5
	addobject 11
	setobjectxyperm 11, 11, 12
	setobjectmovementtype 11, MOVEMENT_TYPE_FACE_LEFT
	return


LetsBurnThisMotherDown_ObjectShow_Script::
	clearflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	addobject 5
	setobjectxy 5, 1, 8
	setobjectxyperm 5, 1, 8
	return


LetsBurnThisMotherDown_ObjectHide_Script::
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	return


LetsBurnThisMotherDown_Assignment_Dialogue::
	compare VAR_LILYCOVE_CONTEST_LOBBY_STATE, 0
	goto_if_ne LetsBurnThisMotherDown_Assignment_Dialogue_2
	addvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_WeStillNeedToFind, MSGBOX_NPC
	msgbox gText_LetsBurnThisMotherDown_YoureCloserToThe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_INeedToTalk
	callnative ClearMugshot
	closemessage
	release
	end

LetsBurnThisMotherDown_Assignment_Dialogue_2:
	msgbox LetsBurnThisMotherDown_Assignment_Dialogue_Text_0
	closemessage
	end


LetsBurnThisMotherDown_ConfrontPlayer::
	lock
	addvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	clearflag FLAG_TEMP_5
	addobject 5
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement 5, LetsBurnThisMotherDown_WalkTowardsPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_YouChoseTheWrong
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_IKnowYouWant
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_YouDontThinkWeve
	closemessage
	callnative ClearMugshot
	applymovement 5, Common_Movement_WalkDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_TheyIgnoreUs
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_DotDotDot
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_IAlwaysHeld
	call Common_EventScript_SaveGame
	closemessage
	goto LetsBurnThisMotherDown_StartBattle_Script
	return


LetsBurnThisMotherDown_StartBattle_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 1
	goto_if_ne LetsBurnThisMotherDown_StartBattle_Script_2
	compare VAR_TEMP_1, 9
	goto_if_eq LetsBurnThisMotherDown_StartBattle_Script_3
	applymovement OBJ_EVENT_ID_PLAYER, LetsBurnThisMotherDown_WalkFromUp
LetsBurnThisMotherDown_StartBattle_Script_1:
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_ImGoingForRevolution
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_WALLY_VR_5, gText_LetsBurnThisMotherDown_DamnIt
	goto LetsBurnThisMotherDown_PostBattle_Dialogue
	return

LetsBurnThisMotherDown_StartBattle_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, LetsBurnThisMotherDown_WalkFromRight
	goto LetsBurnThisMotherDown_StartBattle_Script_1

LetsBurnThisMotherDown_StartBattle_Script_3:
	goto LetsBurnThisMotherDown_StartBattle_Script_1


LetsBurnThisMotherDown_PostBattle_Dialogue::
	addvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_ItDoesntMatter
	callnative ClearMugshot
	closemessage
	applymovement 5, LetsBurnThisMotherDown_WalkBackwards
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_ItsNotFair
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_HyperBeam
	callnative ClearMugshot
	closemessage
	playse SE_M_HYPER_BEAM
	waitse
	fadescreen FADE_TO_WHITE
	applymovement 5, LetsBurnThisMotherDown_HitByHyperBeam
	waitmovement 0
	fadescreen FADE_FROM_WHITE
	clearflag FLAG_TEMP_6
	addobject 6
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	applymovement 6, LetsBurnThisMotherDown_Attack
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_WhatTheHell
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_IFollowedYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_NoITheyreNot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_YeahNoShit
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_IKnow
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_TheCopsShould
	callnative ClearMugshot
	closemessage
	clearflag FLAG_TEMP_7
	addobject 7
	addobject 8
	applymovement 7, LetsBurnThisMotherDown_ArrestA
	applymovement 8, LetsBurnThisMotherDown_ArrestB
	waitmovement 0
	fadescreen FADE_TO_BLACK
	fadedefaultbgm
	warpsilent MAP_SALESFORCETOWER_2F, 255, 10, 12
	release
	end


LetsBurnThisMotherDown_MissionComplete_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_ImSorryIReally
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_YoureYoung
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_ImStillShocked
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_LetsBurnThisMotherDown_ThePoliceTold
	closemessage
	callnative ClearMugshot
	addvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	applymovement 11, LetsBurnThisMotherDown_LeaveRoom
	waitmovement 0
	removeobject 11
	release
	call ExhibitionBattle_TimeSkip_Script
	end


LetsBurnThisMotherDown_WalkTowardsPlayer:
	walk_down
	walk_down
	walk_down
	step_end

LetsBurnThisMotherDown_WalkBackwards:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

LetsBurnThisMotherDown_HitByHyperBeam:
	walk_up
	walk_right
	step_end

LetsBurnThisMotherDown_Attack:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LetsBurnThisMotherDown_ArrestA:
	walk_down
	step_end

LetsBurnThisMotherDown_ArrestB:
	walk_down
	walk_left
	walk_down
	face_right
	step_end

LetsBurnThisMotherDown_WalkFromRight:
	walk_down
	walk_left
	face_up
	step_end

LetsBurnThisMotherDown_WalkFromUp:
	walk_right
	walk_down
	walk_down
	walk_left
	face_up
	step_end

LetsBurnThisMotherDown_LeaveRoom:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LetsBurnThisMotherDown_Assignment_Dialogue_Text_0:
	.string "...$"

gText_LetsBurnThisMotherDown_WeStillNeedToFind::
	.string "We still need to find their new base of\n"
	.string "operations and their leader,\l"
	.string "Giovanni. Ever since we shut down\l"
	.string "NavalBase, we haven't been able to\l"
	.string "make any progress on either of these\l"
	.string "fronts.$"

gText_LetsBurnThisMotherDown_YoureCloserToThe::
	.string "{PLAYER}, you're closer to the\n"
	.string "community. Perhaps there's something\l"
	.string "you've learned or could poke around to\l"
	.string "see if you can find traces of their new\l"
	.string "hideout.$"

gText_LetsBurnThisMotherDown_INeedToTalk::
	.string "(I need to talk to Archer… I\n"
	.string "think I can still save him. I need to\l"
	.string "get to RobinWillTunnel.)$"

gText_LetsBurnThisMotherDown_YouChoseTheWrong::
	.string "You chose the wrong side!$"

gText_LetsBurnThisMotherDown_IKnowYouWant::
	.string "Archer, I know you want to do\n"
	.string "good. But this isn't the way! If you\l"
	.string "want real meaningful change, let's work\l"
	.string "with them. They're good people. We all\l"
	.string "want the same thing!$"

gText_LetsBurnThisMotherDown_YouDontThinkWeve::
	.string "You don't think we've tried that? You\n"
	.string "just got here, {PLAYER} . People here\l"
	.string "in RobinWillTunnel, died trying to do things\l"
	.string "the right way. They don't care.$"

gText_LetsBurnThisMotherDown_TheyIgnoreUs::
	.string "They ignore us, and when we get fed up\n"
	.string "and take matters into our own hands,\l"
	.string "they label us terrorists. They frame\l"
	.string "us. They try to turn our region against\l"
	.string "us. For what? Feeding the homeless?\l"
	.string "Asking workers to be treated fairly?\l"
	.string "{PLAYER} , these people are monsters.$"

gText_LetsBurnThisMotherDown_DotDotDot::
	.string "…$"

gText_LetsBurnThisMotherDown_IAlwaysHeld::
	.string "I always held back before. I didn't\n"
	.string "think it was fair to you, you didn't\l"
	.string "know the whole situation. But you know\l"
	.string "enough now, and still chose wrong.$"

gText_LetsBurnThisMotherDown_ImGoingForRevolution::
	.string "I'm going for revolution. With or\n"
	.string "without you.$"

gText_LetsBurnThisMotherDown_DamnIt::
	.string "Damn it! I can't keep up!$"

gText_LetsBurnThisMotherDown_ItDoesntMatter::
	.string "It doesn't matter if you were holding\n"
	.string "back. I'm better than you.$"

gText_LetsBurnThisMotherDown_ItsNotFair::
	.string "It's not fair…$"

gText_LetsBurnThisMotherDown_HyperBeam::
	.string "Hyper Beam!$"

gText_LetsBurnThisMotherDown_WhatTheHell::
	.string "What the hell are you doing here?$"

gText_LetsBurnThisMotherDown_IFollowedYou::
	.string "I followed you. You two were always\n"
	.string "weirdly close. I was starting to think\l"
	.string "you double-crossed us, so I followed\l"
	.string "you.$"

gText_LetsBurnThisMotherDown_NoITheyreNot::
	.string "No, I… they're not like the rest of\n"
	.string "TeamRocket. I thought we could work\l"
	.string "with them. I was wrong.$"

gText_LetsBurnThisMotherDown_YeahNoShit::
	.string "Yeah, no shit! None of these people can\n"
	.string "be trusted. Ugh, {PLAYER} , you could\l"
	.string "have gotten seriously hurt.$"

gText_LetsBurnThisMotherDown_IKnow::
	.string "I know, I know. I'm sorry.$"

gText_LetsBurnThisMotherDown_TheCopsShould::
	.string "The cops should be right behind me. You\n"
	.string "can't be fucking up like this.$"

gText_LetsBurnThisMotherDown_ImSorryIReally::
	.string "I'm sorry. I really thought I could\n"
	.string "change their mind.$"

gText_LetsBurnThisMotherDown_YoureYoung::
	.string "You're young, and it ended well.\n"
	.string "Shutting down their new base before it\l"
	.string "even gets off the ground is a major\l"
	.string "win!$"

gText_LetsBurnThisMotherDown_ImStillShocked::
	.string "I'm still shocked they were using the\n"
	.string "inside of RobinWillTunnel. Absolutely insane.$"

gText_LetsBurnThisMotherDown_ThePoliceTold::
	.string "The police told me they're going to\n"
	.string "treat the entire island as a crime\l"
	.string "scene and see if they can find\l"
	.string "anything else regarding TeamRocket.$"
