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


LetsBurnThisMotherDown_Interact_Oak_Script::
	returnqueststate QUEST_LETS_BURN_THIS_MOTHER_DOWN
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, LetsBurnThisMotherDown_Interact_Oak_Script_2
	case QUEST_MENU_COMPLETE_QUEST, LetsBurnThisMotherDown_Interact_Oak_Script_3
	goto LetsBurnThisMotherDown_StartQuest_Dialogue
	return

LetsBurnThisMotherDown_Interact_Oak_Script_2:
	goto LetsBurnThisMotherDown_ActiveQuest_Dialogue
	return

LetsBurnThisMotherDown_Interact_Oak_Script_3:
	goto LetsBurnThisMotherDown_CompleteQuest_Dialogue
	return


LetsBurnThisMotherDown_ActiveQuest_Dialogue::
	msgbox gText_LetsBurnThisMotherDown_YoureCloserToThe, MSGBOX_NPC, SPEAKER_OAK
	end


LetsBurnThisMotherDown_CompleteQuest_Dialogue::
	msgbox gText_LetsBurnThisMotherDown_ImStillShocked, MSGBOX_NPC, SPEAKER_OAK
	end


LetsBurnThisMotherDown_StartQuest_Dialogue::
	setvar VAR_LETS_BURN_THIS_MOTHER_STATE, ASSIGNED_BURN_MOTHER
	msgbox gText_LetsBurnThisMotherDown_WeStillNeedToFind, MSGBOX_NPC, SPEAKER_OAK
	msgbox gText_LetsBurnThisMotherDown_YoureCloserToThe, , SPEAKER_OAK
	msgbox gText_LetsBurnThisMotherDown_INeedToTalk, MSGBOX_DEFAULT, SPEAKER_ZOEY
	startquest QUEST_LETS_BURN_THIS_MOTHER_DOWN
	closemessage
	release
	end


LetsBurnThisMotherDown_CheckActiveQuest_Script::
	goto_if_quest_active QUEST_LETS_BURN_THIS_MOTHER_DOWN, LetsBurnThisMotherDown_ConfrontPlayer
	release
	end


LetsBurnThisMotherDown_ConfrontPlayer::
	lock
	compare VAR_LETS_BURN_THIS_MOTHER_STATE, SAVE_ARCHER_ALCATRAZ
	goto_if_eq LetsBurnThisMotherDown_ConfrontPlayer_2
	setvar VAR_LETS_BURN_THIS_MOTHER_STATE, SAVE_ARCHER_ALCATRAZ
	clearflag FLAG_TEMP_5
	addobject 5
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	applymovement 5, LetsBurnThisMotherDown_WalkTowardsPlayer
	waitmovement 0
	msgbox gText_LetsBurnThisMotherDown_YouChoseTheWrong, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_IKnowYouWant, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_YouDontThinkWeve, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	applymovement 5, Common_Movement_WalkDown
	waitmovement 0
	msgbox gText_LetsBurnThisMotherDown_TheyIgnoreUs, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_DotDotDot, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_IAlwaysHeld, MSGBOX_DEFAULT, SPEAKER_ZOEY
	call Common_EventScript_SaveGame
	closemessage
	goto LetsBurnThisMotherDown_StartBattle_Script
	return

LetsBurnThisMotherDown_ConfrontPlayer_2:
	release
	end


LetsBurnThisMotherDown_StartBattle_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 1
	goto_if_ne LetsBurnThisMotherDown_StartBattle_Script_2
	compare VAR_TEMP_1, 9
	goto_if_eq LetsBurnThisMotherDown_StartBattle_Script_3
	applymovement OBJ_EVENT_ID_PLAYER, LetsBurnThisMotherDown_WalkFromUp
LetsBurnThisMotherDown_StartBattle_Script_1:
	waitmovement 0
	msgbox gText_LetsBurnThisMotherDown_ImGoingForRevolution, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	trainerbattle_no_intro TRAINER_WALLY_VR_5, gText_LetsBurnThisMotherDown_DamnIt
	goto LetsBurnThisMotherDown_PostBattle_Dialogue
	return

LetsBurnThisMotherDown_StartBattle_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, LetsBurnThisMotherDown_WalkFromRight
	goto LetsBurnThisMotherDown_StartBattle_Script_1

LetsBurnThisMotherDown_StartBattle_Script_3:
	goto LetsBurnThisMotherDown_StartBattle_Script_1


LetsBurnThisMotherDown_PostBattle_Dialogue::
	setvar VAR_LETS_BURN_THIS_MOTHER_STATE, DEFEATED_ARCHER_ALCATRAZ
	questmenu QUEST_MENU_SET_REWARD, QUEST_LETS_BURN_THIS_MOTHER_DOWN
	msgbox gText_LetsBurnThisMotherDown_ItDoesntMatter, MSGBOX_DEFAULT, SPEAKER_ZOEY
	closemessage
	applymovement 5, LetsBurnThisMotherDown_WalkBackwards
	waitmovement 0
	msgbox gText_LetsBurnThisMotherDown_ItsNotFair, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_HyperBeam, , SPEAKER_BIANCA
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
	msgbox gText_LetsBurnThisMotherDown_WhatTheHell, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_IFollowedYou, , SPEAKER_BIANCA
	msgbox gText_LetsBurnThisMotherDown_NoITheyreNot, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_YeahNoShit, , SPEAKER_BIANCA
	msgbox gText_LetsBurnThisMotherDown_IKnow, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_TheCopsShould, , SPEAKER_BIANCA
	closemessage
	clearflag FLAG_TEMP_7
	addobject 7
	addobject 8
	applymovement 7, LetsBurnThisMotherDown_ArrestA
	applymovement 8, LetsBurnThisMotherDown_ArrestB
	waitmovement 0
	fadescreen FADE_TO_BLACK
	fadedefaultbgm
	warpsilent MAP_SALESFORCETOWER_LEAGUEOPS, 34, 5
	release
	end


LetsBurnThisMother_ShowRose_Script::
	setobjectxy 5, 33, 5
	setobjectxyperm 5, 33, 5
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return


LetsBurnThisMotherDown_MissionComplete_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	msgbox gText_LetsBurnThisMotherDown_ImSorryIReally, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_LetsBurnThisMotherDown_YoureYoung, , SPEAKER_ROSE
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 5, Common_Movement_FaceUp
	msgbox gText_LetsBurnThisMotherDown_ImStillShocked, , SPEAKER_OAK
	msgbox gText_LetsBurnThisMotherDown_ThePoliceTold, , SPEAKER_ROSE
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	applymovement 5, LetsBurnThisMotherDown_LeaveRoom
	waitmovement 5
	call Salesforcetower_Leagueops_ClearSecondaryCharacters_Script
	completequest QUEST_LETS_BURN_THIS_MOTHER_DOWN
	setvar VAR_LETS_BURN_THIS_MOTHER_STATE, BURN_MOTHER_COMPLETE
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

gText_LetsBurnThisMotherDown_WeStillNeedToFind::
	.string "We still need to find their new base of\n"
	.string "operations and their leader, Giovanni.\l"
	.string "Ever since we shut down Navalbase, we\l"
	.string "haven't been able to make any progress\l"
	.string "on either of these fronts.$"

gText_LetsBurnThisMotherDown_YoureCloserToThe::
	.string "{PLAYER}, you're closer to the\n"
	.string "community. Perhaps there's something\l"
	.string "you've learned or could poke around to\l"
	.string "see if you can find traces of their new\l"
	.string "hideout.$"

gText_LetsBurnThisMotherDown_INeedToTalk::
	.string "(I need to talk to Archer… I think I can\n"
	.string "still save him. I need to get to\l"
	.string "Alcatraz.)$"

gText_LetsBurnThisMotherDown_YouChoseTheWrong::
	.string "You chose the wrong side!$"

gText_LetsBurnThisMotherDown_IKnowYouWant::
	.string "Archer, I know you want to do good. But\n"
	.string "this isn't the way! If you want real\l"
	.string "meaningful change, let's work with\l"
	.string "them. They're good people. We all want\l"
	.string "the same thing!$"

gText_LetsBurnThisMotherDown_YouDontThinkWeve::
	.string "You don't think we've tried that? You\n"
	.string "just got here, {PLAYER}. People here\l"
	.string "in Alcatraz died trying to do things\l"
	.string "the right way. They don't care.$"

gText_LetsBurnThisMotherDown_TheyIgnoreUs::
	.string "They ignore us, and when we get fed up\n"
	.string "and take matters into our own hands,\l"
	.string "they label us terrorists. They frame\l"
	.string "us. They try to turn our region against\l"
	.string "us. For what? Feeding the homeless?\l"
	.string "Asking workers to be treated fairly?\l"
	.string "{PLAYER}, these people are monsters.$"

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
	.string "be trusted. Ugh, {PLAYER}, you could\l"
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
	.string "inside of Alcatraz. Absolutely insane.$"

gText_LetsBurnThisMotherDown_ThePoliceTold::
	.string "The police told me they're going to\n"
	.string "treat the entire island as a crime\l"
	.string "scene and see if they can find\l"
	.string "anything else regarding TeamRocket.$"
