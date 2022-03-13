LetsGrabLunch_HideObject_SetUp::
	compare VAR_STORYLINE_STATE, 31
	goto_if_ne LetsGrabLunch_HideObject_SetUp_2
LetsGrabLunch_HideObject_SetUp_1:
	compare VAR_STORYLINE_STATE, 32
	goto_if_ne LetsGrabLunch_HideObject_SetUp_4
	compare VAR_STORYLINE_STATE, 33
	goto_if_ne LetsGrabLunch_HideObject_SetUp_4
	return

LetsGrabLunch_HideObject_SetUp_2:
	setflag FLAG_TEMP_1
	goto LetsGrabLunch_HideObject_SetUp_1

LetsGrabLunch_HideObject_SetUp_4:
	setflag FLAG_TEMP_2
	return


LetsGrabLunch_ShowObject_SetUp::
	compare VAR_STORYLINE_STATE, 31
	goto_if_eq LetsGrabLunch_ShowObject_SetUp_2
LetsGrabLunch_ShowObject_SetUp_1:
	compare VAR_STORYLINE_STATE, 32
	goto_if_eq LetsGrabLunch_ShowObject_SetUp_4
	compare VAR_STORYLINE_STATE, 33
	goto_if_eq LetsGrabLunch_ShowObject_SetUp_4
	return

LetsGrabLunch_ShowObject_SetUp_2:
	setobjectxy 3, 14, 8
	setobjectxyperm 3, 14, 8
	goto LetsGrabLunch_ShowObject_SetUp_1

LetsGrabLunch_ShowObject_SetUp_4:
	clearflag FLAG_TEMP_2
	addobject 1
	return


LetsGrabLunch_StartConversation_Dialogue::
	lockall
	addvar VAR_STORYLINE_STATE, 1
	clearflag FLAG_TEMP_1
	addobject 3
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 3, LetsGrabLunch_WalkUpToPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_HuhWhatAreYouDoing
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_TakingABreak
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_YeahBeingOfficial
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_ThisAgain
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_HeyYouBeatMe
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto LetsGrabLunch_StartBattle_Script
	return


LetsGrabLunch_InteractBattle_Script::
	lockall
	faceplayer
	goto LetsGrabLunch_StartBattle_Script
	return


LetsGrabLunch_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_ButLetsSee
	closemessage
	callnative ClearMugshot
	goto LetsGrabLunch_PostBattle_Dialogue
	return


LetsGrabLunch_PostBattle_Dialogue::
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_GoodGame
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_ImGoingToBe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_HaventYouHad
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_NahThisIsCool
	callnative ClearMugshot
	closemessage
	fadedefaultbgm
	warpsilent MAP_PSFCAVE5_RESTAURANT, 14, 9
	releaseall
	end


LetsGrabLunch_DinerBooth_Dialogue::
	lockall
	addvar VAR_STORYLINE_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_OkayLetsHear
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_IWantToCreate
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_HuhThatsActually
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_YeahITried
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_Who
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_OhTheOldLeaders
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_YouKnowTheyre
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_IKnowItsHard
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_HmmNeverThought
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_YeahThisSounds
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_ItWouldBeSuch
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_HahaHowCanIHelp
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_CanYouTryTalking
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_WhatAreYouGoing
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_ImGoingToBring
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_Yeah
	callnative ClearMugshot
	closemessage
	end


LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_ImJustPlanning
	multichoicedefault 18, 6, MULTI_LUNCH_WARP, 1, TRUE
	switch VAR_RESULT
	case 0, LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_2
	case 1, LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_3
	case 2, LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_4
	case 3, LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_5
	goto LetsGrabLunch_CloseMenu
	return

LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_2:
	goto LetsGrabLunch_Psfcity13
	return

LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_3:
	goto LetsGrabLunch_Psfcity10
	return

LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_4:
	goto LetsGrabLunch_Psfcave5
	return

LetsGrabLunch_InteractPsfnativerivalDiner_Dialogue_5:
	goto LetsGrabLunch_Psfcity18
	return


LetsGrabLunch_CloseMenu::
	callnative ClearMugshot
	closemessage
	releaseall
	end


LetsGrabLunch_Psfcity13::
	msgbox gText_LetsGrabLunch_TheLeaderOfThat
	msgbox gText_LetsGrabLunch_DoYouWantPsfcity13, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LetsGrabLunch_Psfcity13_1
	warpsilent MAP_PSFCITY13, 9, 10
	return

LetsGrabLunch_Psfcity13_1:
	callnative ClearMugshot
	closemessage
	releaseall
	end


LetsGrabLunch_Psfcity10::
	msgbox gText_LetsGrabLunch_WasALittle
	msgbox gText_LetsGrabLunch_DoYouWantPsfcity10, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LetsGrabLunch_Psfcity10_1
	warpsilent MAP_PSFCITY13, 5, 15
	return

LetsGrabLunch_Psfcity10_1:
	callnative ClearMugshot
	closemessage
	releaseall
	end


LetsGrabLunch_Psfcave5::
	msgbox gText_LetsGrabLunch_AlmostWalkedOut
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_VeryRealistic
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_TheyreIntense
	msgbox gText_LetsGrabLunch_DoYouWantPsfcave5, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LetsGrabLunch_Psfcave5_1
	warpsilent MAP_PSFCAVE5, 17, 15
	return

LetsGrabLunch_Psfcave5_1:
	callnative ClearMugshot
	closemessage
	releaseall
	end


LetsGrabLunch_Psfcity18::
	random 2
	compare VAR_RESULT, 1
	goto_if_eq LetsGrabLunch_Psfcity18_2
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_IsTheOnlyPlace
LetsGrabLunch_Psfcity18_1:
	msgbox gText_LetsGrabLunch_DoYouWantPsfcity18, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LetsGrabLunch_Psfcity18_5
	warpsilent MAP_PSFCITY18, 9, 27
	return

LetsGrabLunch_Psfcity18_2:
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGrabLunch_RightHandMan
	goto LetsGrabLunch_Psfcity18_1

LetsGrabLunch_Psfcity18_5:
	callnative ClearMugshot
	closemessage
	releaseall
	end


LetsGrabLunch_FastForwardFirstRestoration_Quest::
	lock
	compare VAR_STORYLINE_STATE, 33
	goto_if_eq LetsGrabLunch_FastForwardFirstRestoration_Quest_2
	msgbox gText_LetsGrabLunch_FastForwardBlock
LetsGrabLunch_FastForwardFirstRestoration_Quest_1:
	closemessage
	releaseall
	end

LetsGrabLunch_FastForwardFirstRestoration_Quest_2:
	addvar VAR_STORYLINE_STATE, 1
	bufferpartymonnick 0, 1
	msgbox gText_LetsGrabLunch_FastForwardAdvance
	goto LetsGrabLunch_FastForwardFirstRestoration_Quest_1


LetsGrabLunch_WalkUpToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

gText_LetsGrabLunch_HuhWhatAreYouDoing::
	.string "Huh. What are you doing here? Shouldn't\n"
	.string "you be busy?$"

gText_LetsGrabLunch_TakingABreak::
	.string "Taking a break. I haven't had a chance\n"
	.string "to relax since I last saw you.$"

gText_LetsGrabLunch_YeahBeingOfficial::
	.string "Yeah, being Psfbadguy's official lapdog\n"
	.string "must be exhausting! Bummer.$"

gText_LetsGrabLunch_ThisAgain::
	.string "This again? And besides, I know you've\n"
	.string "been busy too. Psfregion loves their\l"
	.string "“hometown hero robbed of\l"
	.string "championship” narrative.$"

gText_LetsGrabLunch_HeyYouBeatMe::
	.string "Hey, you beat me fair and square… but\n"
	.string "the extra popularity can't hurt.$"

gText_LetsGrabLunch_ButLetsSee::
	.string "But let's see how robbed I really was!$"

gText_LetsGrabLunch_NahNotRobbed::
	.string "Nah, not robbed at all. You're legit as\n"
	.string "fuck.$"

gText_LetsGrabLunch_GoodGame::
	.string "Good game, but…I thought Psfregion1\n"
	.string "natives weren't cool with Mega\l"
	.string "Evolution?$"

gText_LetsGrabLunch_ImGoingToBe::
	.string "I'm going to be the best and change the\n"
	.string "world, I can't be hung up on what's\l"
	.string "“pure” and “right”. My team and I are\l"
	.string "going to use whatever tools we can to\l"
	.string "take down your bosses. As a matter of\l"
	.string "fact… I'm working on a project.$"

gText_LetsGrabLunch_HaventYouHad::
	.string "Haven't you had enough run-ins with the\n"
	.string "police already?$"

gText_LetsGrabLunch_NahThisIsCool::
	.string "Nah, this is cool, I swear. Actually, you\n"
	.string "said you're on break? Cool, we're\l"
	.string "grabbing lunch. My treat.$"

gText_LetsGrabLunch_OkayLetsHear::
	.string "Okay, let's hear about your pyramid\n"
	.string "scheme.$"

gText_LetsGrabLunch_IWantToCreate::
	.string "I want to create training centers all\n"
	.string "over Psfregion1, to help more Trainers\l"
	.string "get a real start, kind of like what\l"
	.string "Psfbadguy gave you. I wanna use the\l"
	.string "decommissioned Gyms, like the one you\l"
	.string "saw earlier today, as those hubs.$"

gText_LetsGrabLunch_HuhThatsActually::
	.string "Huh. That's actually a pretty cool idea.$"

gText_LetsGrabLunch_YeahITried::
	.string "Yeah! I tried to talk to Psfleader9 and\n"
	.string "Psfleader10, but they didn't take it\l"
	.string "nearly as well as you did.$"

gText_LetsGrabLunch_Who::
	.string "Who…?$"

gText_LetsGrabLunch_OhTheOldLeaders::
	.string "Oh, the old Leaders of the Psfcave5 and\n"
	.string "Psfcity10 Gyms. If we can revive those\l"
	.string "Gyms and strengthen our Trainers, then\l"
	.string "Trainers from other regions will want\l"
	.string "to come here, battle us, and help\l"
	.string "stimulate the region… without any\l"
	.string "interference from Psfbadguy.$"

gText_LetsGrabLunch_YouKnowTheyre::
	.string "You know, they're not as bad as you\n"
	.string "think. I still don't understand your\l"
	.string "problem with them.$"

gText_LetsGrabLunch_IKnowItsHard::
	.string "I know. It's hard to sit down and\n"
	.string "explain… but maybe it doesn't matter.\l"
	.string "Is that what Psfgoodteam got wrong?\l"
	.string "Rather than try to defeat a negative\l"
	.string "force, maybe we need to focus on being\l"
	.string "a stronger positive force.$"

gText_LetsGrabLunch_HmmNeverThought::
	.string "(Hmm. Never thought about it like that.)$"

gText_LetsGrabLunch_YeahThisSounds::
	.string "Yeah, this sounds really cool! Way\n"
	.string "better than I expected.$"

gText_LetsGrabLunch_ItWouldBeSuch::
	.string "It would be such a boon if the Champion\n"
	.string "was helping too…$"

gText_LetsGrabLunch_HahaHowCanIHelp::
	.string "Haha, how can I help?$"

gText_LetsGrabLunch_CanYouTryTalking::
	.string "Hmm. Can you try talking to Psfleader9\n"
	.string "or Psfleader10? Or maybe visit\l"
	.string "Psfcity13's Gym and see what we can\l"
	.string "do? Maybe there's even hope for\l"
	.string "Psfcity18's Gym… yeah, any of those\l"
	.string "are good starts.$"

gText_LetsGrabLunch_WhatAreYouGoing::
	.string "What are you going to do?$"

gText_LetsGrabLunch_ImGoingToBring::
	.string "I'm going to bring the idea to\n"
	.string "Psfgoodteam too. I think it's\l"
	.string "something everybody can rally behind,\l"
	.string "right?$"

gText_LetsGrabLunch_Yeah::
	.string "Yeah!$"

gText_LetsGrabLunch_ImJustPlanning::
	.string "I'm just planning out my pitch to\n"
	.string "Psfgoodteam. What are you up to? Have\l"
	.string "you decided which place you'll hit up\l"
	.string "first?$"

gText_LetsGrabLunch_TheLeaderOfThat::
	.string "The Leader of that Gym more or less\n"
	.string "disappeared after Psfbadguy shut it\l"
	.string "down. I know some of his Gym Trainers\l"
	.string "are still around… but I'm not sure\l"
	.string "where.$"

gText_LetsGrabLunch_DoYouWantPsfcity13::
	.string "Do you want to go to Psfcity13?$"

gText_LetsGrabLunch_WasALittle::
	.string "Psfleader9 was a little receptive to my\n"
	.string "idea. They said it was a “good first\l"
	.string "step”, but wouldn't sign on unless I\l"
	.string "had a plan for dismantling the entire\l"
	.string "Psfbadfguy League, which in their\l"
	.string "eyes, is a “total failure for our\l"
	.string "Trainers”.$"

gText_LetsGrabLunch_DoYouWantPsfcity10::
	.string "Do you want to go to Psfcity10?$"

gText_LetsGrabLunch_AlmostWalkedOut::
	.string "Psfleader10 almost walked out when I\n"
	.string "first proposed the idea. I think their\l"
	.string "exact quote was “I'd rather be dead\l"
	.string "than a “training stop” for more\l"
	.string "transplants”. They want Psfgoodteam\l"
	.string "to totally dismantle the new League,\l"
	.string "and restore their Gym to its former\l"
	.string "glory.$"

gText_LetsGrabLunch_VeryRealistic::
	.string "Very realistic, I see.$"

gText_LetsGrabLunch_TheyreIntense::
	.string "They're… intense.$"

gText_LetsGrabLunch_DoYouWantPsfcave5::
	.string "Do you want to go to Psfcave5?$"

gText_LetsGrabLunch_RightHandMan::
	.string "Alan was Psfleader7's right hand man. I\n"
	.string "wonder if he has any plans now that\l"
	.string "Psfleader7 is gone…?$"

gText_LetsGrabLunch_IsTheOnlyPlace::
	.string "You know, Psfcity18 is the only place\n"
	.string "that got to keep its Gym, but only\l"
	.string "because Psfleader7 is a friggin' snake.\l"
	.string "Man, what I'd give to see him get what\l"
	.string "he deserves…$"

gText_LetsGrabLunch_DoYouWantPsfcity18::
	.string "Do you want to go to Psfcity18?$"

gText_LetsGrabLunch_FastForwardAdvance::
	.string "You have restored the {STR_VAR_1}\n"
	.string "Gym. Good job kid. In the main game,\l"
	.string "that nickname will be replaced with the\l"
	.string "name of wherever you are.$"

gText_LetsGrabLunch_FastForwardBlock::
	.string "Come back when its time to do the\n"
	.string "restoration quests. Or if you already\l"
	.string "did them, go away!$"
