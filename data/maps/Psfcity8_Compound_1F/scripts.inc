Psfcity8_Compound_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity8_Compound_1F_MapScripts_OnTransition
	return

Psfcity8_Compound_1F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, ImProbablyBetterThanYou_PsftransrivalIntro_Dialogue
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, Swagbag_WelcomeToPsfregion1_Dialogue
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 7, WhyAreYouHelpingThem_BackAtCompound_Dialogue
	map_script_2 VAR_STORYLINE_STATE, 20, VSGarbodor_ReturnToTheCompound_Dialogue
	.2byte 0


Psfcity8_Compound_1F_MapScripts_OnTransition::
	switch VAR_STORYLINE_STATE
	case 9, Psfcity8_Compound_1F_MapScripts_OnTransition_3
	case 10, Psfcity8_Compound_1F_MapScripts_OnTransition_4
	case 20, Psfcity8_Compound_1F_MapScripts_OnTransition_5
Psfcity8_Compound_1F_MapScripts_OnTransition_1:
	switch VAR_LITTLEROOT_INTRO_STATE
	case 1, Psfcity8_Compound_1F_MapScripts_OnTransition_7
	case 3, Psfcity8_Compound_1F_MapScripts_OnTransition_8
	case 4, Psfcity8_Compound_1F_MapScripts_OnTransition_9
	case 5, Psfcity8_Compound_1F_MapScripts_OnTransition_10
	case 6, Psfcity8_Compound_1F_MapScripts_OnTransition_11
	case 7, Psfcity8_Compound_1F_MapScripts_OnTransition_12
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_3:
	goto Act1_1_ObjectCleanUp
	goto Psfcity8_Compound_1F_MapScripts_OnTransition_1

Psfcity8_Compound_1F_MapScripts_OnTransition_4:
	goto Act1_2_ObjectSetUp
	goto Psfcity8_Compound_1F_MapScripts_OnTransition_1

Psfcity8_Compound_1F_MapScripts_OnTransition_5:
	goto VSGarbodor_ReturnToTheCompound_ObjectSetUp
	goto Psfcity8_Compound_1F_MapScripts_OnTransition_1

Psfcity8_Compound_1F_MapScripts_OnTransition_7:
	goto ImProbablyBetterThanYou_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_8:
	goto Swagbag_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_9:
	goto ExplorePsfcity8_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_10:
	goto TwoHoursAgo_ObjectSetUp
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_11:
	goto WorkingFerry_SetUp_Script
	return

Psfcity8_Compound_1F_MapScripts_OnTransition_12:
	goto WhyAreYouHelpingThem_BackAtCompound_ObjectSetUp_Script
	return


ExplorePsfcity8_ObjectSetUp::
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm 3, 8, 6
	return


TwoHoursAgo_ObjectSetUp::
	special GetNumberOfBadges
	compare VAR_TEMP_0, 4
	goto_if_gt TwoHoursAgo_ObjectSetUp_1
	return

TwoHoursAgo_ObjectSetUp_1:
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN
	return


Act1_1_ObjectCleanUp::
	setflag FLAG_HIDE_COMPOUND_PSFBADADMIN
	clearflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL
	return


Act1_2_ObjectSetUp::
	setflag FLAG_HIDE_COMPOUND_PSFTRANSRIVAL
	return


Psftransrival_Compound_Script::
	compare VAR_STORYLINE_STATE, 9
	goto_if_eq Psftransrival_Compound_Script_1
	goto ImProbablyBetterThanYou_Annoyed_Dialogue
	return

Psftransrival_Compound_Script_1:
	goto Act1_1_Complete_Psftransrival_Dialogue
	return


Psfbadadmin_Compound_Script::
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Psfbadadmin_Compound_Script_1
	return

Psfbadadmin_Compound_Script_1:
	goto swagbag_HelpPlayer_Script
	return


TwoHoursAgo_TheyreEager_Dialogue::
	goto_if_set FLAG_RECIEVED_LEFTOVERS_PSFBADADMIN1, TwoHoursAgo_TheyreEager_Dialogue_2
TwoHoursAgo_TheyreEager_Dialogue_1:
	lockall
	faceplayer
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TwoHoursAgo_TheyreEager_Text1, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	goto TwoHoursAgo_ExplainLeague_SetUp
	return

TwoHoursAgo_TheyreEager_Dialogue_2:
	goto TwoHoursAgo_ExplainLeftovers_Dialouge
	goto TwoHoursAgo_TheyreEager_Dialogue_1


TwoHoursAgo_ExplainLeague_SetUp::
	lock
	fadescreen FADE_TO_BLACK
	setobjectxy 6, 4, 6
	turnobject 6, DIR_WEST
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_LEFT
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 6
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	call CameraToPlayer_Movement
	goto TwoHoursAgo_ExplainLeague_Script
	return


TwoHoursAgo_ExplainLeague_Script::
	lockall
	msgbox gText_TwoHoursAgo_ExplainLeague_Text1
	msgbox gText_TwoHoursAgo_ExplainLeague_Text2
	msgbox gText_TwoHoursAgo_ExplainLeague_Text3
	closemessage
	fadescreen FADE_FROM_BLACK
	goto TwoHoursAgo_LeftoversPokeballs_Dialogue
	return


TwoHoursAgo_LeftoversPokeballs_Dialogue::
	setflag FLAG_RECIEVED_LEFTOVERS_PSFBADADMIN1
	callnative DrawMugshot
	msgbox gText_TwoHoursAgo_LeftoversPokeballs_Text1
	lockall
	giveitem ITEM_LEFTOVERS
	giveitem ITEM_POKE_BALL, 5
	callnative ClearMugshot
	closemessage
	releaseall
	end


TwoHoursAgo_ExplainLeftovers_Dialouge::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	bufferleadmonspeciesname 0
	msgbox gText_TwoHoursAgo_ExplainLeftovers_Text1, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


Act1_1_Complete_Psftransrival_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_WhatsYourProgress, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_OnlyThree
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_YeahThatBusted
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_INeedToFigure
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_HardToComeBy
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Act1_1_Complete_ImSureIllFigure
	callnative ClearMugshot
	closemessage
	releaseall
	end


CameraToPlayer_Movement::
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 6
	special TeleportCamera
	return


Psfcity8_Compound_1F_InteractPsfbadadmin::
	lockall
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	goto_if_eq Psfcity8_Compound_1F_InteractPsfbadadmin_1
	return

Psfcity8_Compound_1F_InteractPsfbadadmin_1:
	goto swagbag_HelpPlayer_Script
	return


gText_Act1_1_Complete_WhatsYourProgress::
	.string "Damn I'm beat. Getting five badges in\n"
	.string "one day was a hustle! What about you?$"

gText_Act1_1_Complete_OnlyThree::
	.string "Only three so far. I'm praying the ferry\n"
	.string "is fixed tomorrow.$"

gText_Act1_1_Complete_YeahThatBusted::
	.string "Yeah, that busted ferry sucks. I'm\n"
	.string "going to challenge the Psfcity5 and\l"
	.string "Psfcity18 Gyms tomorrow, and the ferry\l"
	.string "will definately be fixed after that, so\l"
	.string "Psfcity11 Gym will be last.$"

gText_Act1_1_Complete_INeedToFigure::
	.string "I need to figure out how to get some\n"
	.string "Go-Goggles too...$"

gText_Act1_1_Complete_HardToComeBy::
	.string "They're hard to come by right now. I\n"
	.string "only got these because Daddys knows\l"
	.string "the manufactuer over in Kanto.$"

gText_Act1_1_Complete_ImSureIllFigure::
	.string "I'm sure I'll figure something out.$"

gText_TwoHoursAgo_TheyreEager_Text1::
	.string "Looks like Psftransrival woke up early\n"
	.string "and already left! They're eager, I'll\l"
	.string "give them that. I guess they didn't\l"
	.string "need the explanation... or breakfast.$"

gText_TwoHoursAgo_ExplainLeague_Text1::
	.string "You're in a race against hundreds of\n"
	.string "other Pokémon Trainers, to see who can\l"
	.string "beat our 8 Gym Leaders first. The first\l"
	.string "16 Trainers to do so, will qualify for\l"
	.string "the Championship Tournament, held in a\l"
	.string "few weeks.$"

gText_TwoHoursAgo_ExplainLeague_Text2::
	.string "The tournament will test all of your\n"
	.string "skills as a Trainer, but the win will\l"
	.string "become a Psfbadguy1 sponsored career\l"
	.string "Pokémon Trainer.$"

gText_TwoHoursAgo_ExplainLeague_Text3::
	.string "We expect the best from you and\n"
	.string "Psftransrival! If you fail to qualify\l"
	.string "for the Championship, we'll be\l"
	.string "terminating your contract, and you'll\l"
	.string "be on your own... but we know that won't\l"
	.string "be the case! So don't worry.$"

gText_TwoHoursAgo_LeftoversPokeballs_Text1::
	.string "Psfcompany2 is always so delicious! Too\n"
	.string "bad Psftransrival didn't eat with us. I\l"
	.string "guess you can take their portion of\l"
	.string "the food, and I bought you both\l"
	.string "PokéBalls, but you can have theirs too!$"

gText_TwoHoursAgo_ExplainLeftovers_Text1::
	.string "Your {STR_VAR_1} can hold those\n"
	.string "Leftovers to restore HP during battle.\l"
	.string "Now, you should get a move on! Don't let\l"
	.string "Psftransrival get too far ahead of\l"
	.string "you!$"
