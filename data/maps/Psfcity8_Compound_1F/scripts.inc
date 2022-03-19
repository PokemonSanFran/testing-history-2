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
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 8, WhyAreYouHelpingThem_BackAtCompound_Dialogue
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
	case 6, Psfcity8_Compound_1F_MapScripts_OnTransition_10
	case 7, Psfcity8_Compound_1F_MapScripts_OnTransition_11
	case 8, Psfcity8_Compound_1F_MapScripts_OnTransition_12
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
	goto swagbag_ObjectHide_Script
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


Act1_1_ObjectCleanUp::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


Act1_2_ObjectSetUp::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


Psftransrival_Psfcity8_Compound_1F_InteractScript::
	lock
	compare VAR_STORYLINE_STATE, 9
	goto_if_eq Psftransrival_Psfcity8_Compound_1F_InteractScript_2
	call ImProbablyBetterThanYou_Annoyed_Dialogue
Psftransrival_Psfcity8_Compound_1F_InteractScript_1:
	release
	end

Psftransrival_Psfcity8_Compound_1F_InteractScript_2:
	goto Act1_1_Complete_Psftransrival_Dialogue
	goto Psftransrival_Psfcity8_Compound_1F_InteractScript_1


Psfbadadmin_Psfcity8_Compound_1F_InteractScript::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	goto_if_eq Psfbadadmin_Psfcity8_Compound_1F_InteractScript_2
	call swagbag_HelpPlayer_Script
Psfbadadmin_Psfcity8_Compound_1F_InteractScript_1:
	closemessage
	releaseall
	end

Psfbadadmin_Psfcity8_Compound_1F_InteractScript_2:
	goto_if_set FLAG_RECIEVED_LEFTOVERS, Psfbadadmin_Psfcity8_Compound_1F_InteractScript_5
	call TwoHoursAgo_TheyreEager_Dialogue
	goto Psfbadadmin_Psfcity8_Compound_1F_InteractScript_1

Psfbadadmin_Psfcity8_Compound_1F_InteractScript_5:
	goto_if_set FLAG_TEMP_1F, Psfbadadmin_Psfcity8_Compound_1F_InteractScript_8
	call swagbag_HelpPlayer_Script
	goto Psfbadadmin_Psfcity8_Compound_1F_InteractScript_1

Psfbadadmin_Psfcity8_Compound_1F_InteractScript_8:
	call TwoHoursAgo_ExplainLeftovers_Dialouge
	goto Psfbadadmin_Psfcity8_Compound_1F_InteractScript_1


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
