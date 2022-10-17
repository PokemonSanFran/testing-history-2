ThisIsntRandom_CheckDoor_Script::
	setvar VAR_TEMP_C, 1
	compare VAR_UNDERGROUNDLAB_STATE, PLAYER_DISCOVERED_LAB
	goto_if_eq ThisIsntRandom_CheckDoor_Script_1
	return

ThisIsntRandom_CheckDoor_Script_1:
	compare VAR_STORYLINE_STATE, STORY_POST_EARTHQUAKE
	goto_if_eq ThisIsntRandom_CheckDoor_Script_3
	return

ThisIsntRandom_CheckDoor_Script_3:
	call ThisIsntRandom_UnlockDoor_Dialogue
	return


ThisIsntRandom_HideObject_AboveGround_Script::
	compare VAR_UNDERGROUNDLAB_STATE, LAB_NOT_DISCOVERED
	goto_if_ne ThisIsntRandom_HideObject_AboveGround_Script_2
	compare VAR_STORYLINE_STATE, STORY_POST_EARTHQUAKE
	goto_if_ne ThisIsntRandom_HideObject_AboveGround_Script_2
ThisIsntRandom_HideObject_AboveGround_Script_1:
	return

ThisIsntRandom_HideObject_AboveGround_Script_2:
	setflag FLAG_TEMP_1
	goto ThisIsntRandom_HideObject_AboveGround_Script_1


ThisIsntRandom_ObjectSetUp_Script::
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 11, 18
	TeleportCamera 11, 18
	clearflag FLAG_TEMP_1
	addobject 1
	setobjectxy 1, 10, 19
	applymovement 1, Common_Movement_FaceUp
	addobject 2
	setobjectxy 2, 11, 19
	applymovement 2, Common_Movement_FaceUp
	addobject 3
	setobjectxy 3, 12, 19
	applymovement 3, Common_Movement_FaceUp
	fadescreen FADE_FROM_BLACK
	return


ThisIsntRandom_UnlockDoor_Dialogue::
	lock
	call ThisIsntRandom_ObjectSetUp_Script
	setvar VAR_UNDERGROUNDLAB_STATE, TEAMROCKET_DISCOVERED_LAB
	playse SE_PIN
	waitse
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_OhIsLiterally
	callnative ClearMugshot
	closemessage
	applymovement 1, ThisIsRandom_WalkDownStairsA
	playse SE_EXIT
	waitse
	applymovement 3, ThisIsRandom_WalkDownStairsC
	playse SE_EXIT
	waitse
	applymovement 2, ThisIsRandom_WalkDownStairsB
	playse SE_EXIT
	waitse
	waitmovement 2
	removeobject 2
	removeobject 1
	removeobject 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	playse SE_EXIT
	warp MAP_PSFROUTE25, 0
	end


ThisIsntRandom_UnlockElectronicDoor_Script::
	setmetatile 7, 0, 0x269, TRUE
	setmetatile 7, 1, 0x271, TRUE
	setmetatile 7, 2, 0x22F, FALSE
	setmetatile 7, 3, 0x242, FALSE
	special DrawWholeMapView
	return


ThisIsntRandom_UndergroundDoor_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_AndNowMyTurn
	callnative ClearMugshot
	closemessage
	applymovement 3, ThisIsntRandom_WalkToKeypad
	waitmovement 3
	playse SE_DING_DONG
	waitse
	playse SE_BANG
	waitse
	call ThisIsntRandom_UnlockElectronicDoor_Script
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_HowDidYou
	callnative ClearMugshot
	closemessage
	applymovement 3, Common_Movement_FaceLeft
	waitmovement 3
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_TheSecondSet
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_SoIsActuallyTrying
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_AboutToFindOut
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_IfWereAllGoing
	callnative ClearMugshot
	closemessage
	applymovement 3, ThisIsntRandom_WalkDownHallwayA
	applymovement 2, ThisIsntRandom_WalkDownHallwayB
	applymovement 1, ThisIsntRandom_WalkDownHallwayC
	waitmovement 1
	setflag FLAG_TEMP_1
	removeobject 3
	removeobject 2
	removeobject 1
	setvar VAR_UNDERGROUNDLAB_STATE, DRASNA_UNLOCKED_DOOR
	release
	end


ThisIsntRandom_WalkIntoLab_Dialogue::
	lock
	setvar VAR_UNDERGROUNDLAB_STATE, TEAM_INSIDE_LAB
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_LooksOldAsHell
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_TakeThese
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_WalkieTalkies
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_ToStayInTOuch
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_Yup
	callnative ClearMugshot
	closemessage
	applymovement 1, ThisIsntRandom_WalkIntoLabA
	applymovement 3, ThisIsntRandom_WalkIntoLabB
	applymovement 2, ThisIsntRandom_WalkIntoLabC
	waitmovement 2
	removeobject 2
	removeobject 1
	removeobject 3
	release
	end


ThisIsntRandom_CheckProgressA_Script::
	goto_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, ThisIsntRandom_CheckProgressA_Script_1
	call ThisIsntRandom_DefeatedFirst_Script
	return

ThisIsntRandom_CheckProgressA_Script_1:
	goto ThisIsntRandom_StopProgress_Script
	return


ThisIsntRandom_CheckProgressB_Script::
	goto_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, ThisIsntRandom_CheckProgressB_Script_1
	call ThisIsntRandom_DefeatedSecond_Script
	return

ThisIsntRandom_CheckProgressB_Script_1:
	goto ThisIsntRandom_StopProgress_Script
	return


ThisIsntRandom_StopProgress_Script::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	random 2
	switch VAR_RESULT
	case 0, ThisIsntRandom_StopProgress_Script_3
	case 1, ThisIsntRandom_StopProgress_Script_4
ThisIsntRandom_StopProgress_Script_1:
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

ThisIsntRandom_StopProgress_Script_3:
	msgbox gText_ThisIsntRandom_ItsInPain
	goto ThisIsntRandom_StopProgress_Script_1

ThisIsntRandom_StopProgress_Script_4:
	msgbox gText_ThisIsntRandom_IWonderIfICan
	goto ThisIsntRandom_StopProgress_Script_1


ThisIsntRandom_CoreEncounter_Script::
	call Common_EventScript_SaveGame
	faceplayer
	goto_if_unset FLAG_DEFEATED_VOLTORB_3_NEW_MAUVILLE, ThisIsntRandom_CoreEncounter_Script_2
	goto_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, ThisIsntRandom_CoreEncounter_Script_3
ThisIsntRandom_CoreEncounter_Script_1:
	msgbox gText_VSGarbodor_Kuh
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, ThisIsntRandom_CoreEncounter_Script_8
	case B_OUTCOME_WON, ThisIsntRandom_CoreEncounter_Script_8
ThisIsntRandom_CoreEncounter_Script_6:
	release
	end

ThisIsntRandom_CoreEncounter_Script_2:
	setwildbattle SPECIES_DONPHAN, 60, ITEM_NONE
	playmoncry SPECIES_DONPHAN, CRY_MODE_ENCOUNTER
	goto ThisIsntRandom_CoreEncounter_Script_1

ThisIsntRandom_CoreEncounter_Script_3:
	setwildbattle SPECIES_GOLURK, 60, ITEM_NONE
	playmoncry SPECIES_GOLURK, CRY_MODE_ENCOUNTER
	goto ThisIsntRandom_CoreEncounter_Script_1

ThisIsntRandom_CoreEncounter_Script_8:
	goto ThisIsntRandom_RemoveMon_Script
	goto ThisIsntRandom_CoreEncounter_Script_6


ThisIsntRandom_RemoveMon_Script::
	lock
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


ThisIsntRandom_DefeatedFirst_Script::
	lock
	setvar VAR_UNDERGROUNDLAB_STATE, FREED_LAB_POKEMON_1
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_AreYouGuysSeeing
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_YeahIWasAbleTo
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_IGotAttackedButYeah
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_BothHugeProblems
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_RightLooksLikeTheyWanted
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_ButAllOfTheseMachines
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_ImJustTellingYouWhat
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_LetsKeepLooking
	callnative ClearMugshot
	closemessage
	release
	end


ThisIsntRandom_DefeatedSecond_Script::
	lock
	setvar VAR_UNDERGROUNDLAB_STATE, FREED_LAB_POKEMON_2
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_IFoundSomeAccessLogs
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_CanYouGetMeTheExact
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_IThinkSoHoldOn
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_ThoseMonsters
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_AreThoseDatesSpecial
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_TheSecondDateIsOne
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_SilicobraGravelerLarvitar
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_NumelPiloswineNidoking
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_TheyreAllGround
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_SoWhat
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_TheDocumentationCalledOut
	setvar VAR_MUGSHOT, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_AndGroundTypesTo
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_OhNoIDidnt
	setvar VAR_MUGSHOT, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_AndTheyAttackedUs
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_ThisIsntRandom_LetsKeepGoing
	callnative ClearMugshot
	closemessage
	release
	end


ThisIsRandom_WalkDownStairsA:
	walk_up
	walk_up
	walk_right
	step_end

ThisIsRandom_WalkDownStairsB:
	walk_right
	walk_up
	walk_up
	walk_left
	step_end

ThisIsRandom_WalkDownStairsC:
	walk_up
	walk_up
	walk_left
	step_end

ThisIsntRandom_WalkToKeypad:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

ThisIsntRandom_WalkDownHallwayA:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ThisIsntRandom_WalkDownHallwayB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ThisIsntRandom_WalkDownHallwayC:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

ThisIsntRandom_WalkIntoLabA:
	walk_down
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

ThisIsntRandom_WalkIntoLabB:
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	delay_16
	delay_16
	step_end

ThisIsntRandom_WalkIntoLabC:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

gText_ThisIsntRandom_OhIsLiterally::
	.string "Oh, “TM15” is literally the 15th\n"
	.string "Technical Machine! I feel pretty dumb,\l"
	.string "but damn good work.$"

gText_ThisIsntRandom_AndNowMyTurn::
	.string "And now my turn…$"

gText_ThisIsntRandom_HowDidYou::
	.string "How did you…?$"

gText_ThisIsntRandom_TheSecondSet::
	.string "The second set of numbers was the door\n"
	.string "code.$"

gText_ThisIsntRandom_SoIsActuallyTrying::
	.string "So… is Koga actually trying to help us?$"

gText_ThisIsntRandom_AboutToFindOut::
	.string "About to find out. Let’s rage!$"

gText_ThisIsntRandom_IfWereAllGoing::
	.string "Hmm. If we’re all going, we should be\n"
	.string "okay. Let’s see.$"

gText_ThisIsntRandom_DidYouKnowThereWas::
	.string "Ariana, did you know there was a secret\n"
	.string "tunnel underneath Ferrybuilding?$"

gText_ThisIsntRandom_IfPeopleKnew::
	.string "If people knew about it it wouldn’t be a\n"
	.string "secret…$"

gText_ThisIsntRandom_DidYouKnowAbout::
	.string "Hey ARCHER, did you know about the\n"
	.string "secret laboratory under the ocean?$"

gText_ThisIsntRandom_DotDotDot::
	.string "…$"

gText_ThisIsntRandom_LooksOldAsHell::
	.string "Looks old as hell. And empty. Let’s split\n"
	.string "up and see what we turn up.$"

gText_ThisIsntRandom_TakeThese::
	.string "Take these.$"

gText_ThisIsntRandom_WalkieTalkies::
	.string "Walkie talkies?$"

gText_ThisIsntRandom_ToStayInTOuch::
	.string "To stay in touch in case we find\n"
	.string "anything.$"

gText_ThisIsntRandom_Yup::
	.string "Yup!$"

gText_ThisIsntRandom_AreYouGuysSeeing::
	.string "Are you guys seeing Pokémon strapped\n"
	.string "to machines?$"

gText_ThisIsntRandom_YeahIWasAbleTo::
	.string "Yeah, I was able to set the poor thing\n"
	.string "free though.$"

gText_ThisIsntRandom_IGotAttackedButYeah::
	.string "I got attacked, but yeah, I dealt with\n"
	.string "it. I found some documentation too -\l"
	.string "this place is called the Infinity\l"
	.string "Energy Amplification Center. The goal\l"
	.string "was to use Water and Electric-type\l"
	.string "Pokémon to help combat fires and power\l"
	.string "outages.$"

gText_ThisIsntRandom_BothHugeProblems::
	.string "Both huge problems in our area…$"

gText_ThisIsntRandom_RightLooksLikeTheyWanted::
	.string "Right! Looks like they wanted to\n"
	.string "extract the energy from Pokémon, beef\l"
	.string "it up, and direct it to locations all\l"
	.string "over the region. Testing went well, but\l"
	.string "the extraction was painful and\l"
	.string "traumatic for the Pokémon, so they\l"
	.string "shut it down… 53 years ago.$"

gText_ThisIsntRandom_ButAllOfTheseMachines::
	.string "But all of these machines are on! These\n"
	.string "Pokémon are suffering now!$"

gText_ThisIsntRandom_ImJustTellingYouWhat::
	.string "I’m just telling you what I’m reading!$"

gText_ThisIsntRandom_LetsKeepLooking::
	.string "Let’s keep looking, and freeing more\n"
	.string "Pokémon then.$"

gText_ThisIsntRandom_IFoundSomeAccessLogs::
	.string "I found some access logs! A bunch of\n"
	.string "dates of 1968, two in 1971, and then\l"
	.string "three… in the last week.$"

gText_ThisIsntRandom_CanYouGetMeTheExact::
	.string "Ariana… can you get me the exact dates\n"
	.string "of the ones in 1971?$"

gText_ThisIsntRandom_IThinkSoHoldOn::
	.string "I think so, hold on… yeah! Oh, when I get\n"
	.string "into this screen, I can see all the data\l"
	.string "for each specific test. 1971… April\l"
	.string "22nd, and June 4th.$"

gText_ThisIsntRandom_ThoseMonsters::
	.string "*gasp* Those monsters. *sobs* They were\n"
	.string "trying to kill us!$"

gText_ThisIsntRandom_AreThoseDatesSpecial::
	.string "What? Are those dates special?$"

gText_ThisIsntRandom_TheSecondDateIsOne::
	.string "The second date is the end of the\n"
	.string "Alcatraz riots. What types of Pokémon\l"
	.string "did you guys fight down here?$"

gText_ThisIsntRandom_SilicobraGravelerLarvitar::
	.string "Silicobra, Graveler, Larvitar…$"

gText_ThisIsntRandom_NumelPiloswineNidoking::
	.string "Numel, Piloswine, Nidoking…$"

gText_ThisIsntRandom_TheyreAllGround::
	.string "They’re all Ground types.$"

gText_ThisIsntRandom_SoWhat::
	.string "So what?$"

gText_ThisIsntRandom_TheDocumentationCalledOut::
	.string "The documentation called out specific\n"
	.string "types of Pokémon. Use Water-types to\l"
	.string "fight fires, -$"

gText_ThisIsntRandom_AndGroundTypesTo::
	.string "*sigh* And ground types to trigger\n"
	.string "Earthquakes. Those bastards used this\l"
	.string "system to attack Alcatraz.$"

gText_ThisIsntRandom_OhNoIDidnt::
	.string "Oh no. I didn’t recognize the earlier\n"
	.string "names, but the activities in the last\l"
	.string "few days… their access signature is\l"
	.string "Rose.$"

gText_ThisIsntRandom_AndTheyAttackedUs::
	.string "And they attacked us too. Wait? Why\n"
	.string "attack innocent people?$"

gText_ThisIsntRandom_LetsKeepGoing::
	.string "…Let’s keep going.$"

gText_ThisIsntRandom_ItsInPain::
	.string "That Pokemon looks likes its in pain...$"

gText_ThisIsntRandom_IWonderIfICan::
	.string "I wonder if I can help that Pokemon...$"
