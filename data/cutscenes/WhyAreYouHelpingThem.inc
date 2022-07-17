WhyAreYouHelpingThem_HideObject_Script::
	setflag FLAG_TEMP_3
	return


WhyAreYouHelpingThem_ObjectCleanUp_Script::
	setflag FLAG_TEMP_4
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_1
	return


WhyAreYouHelpingThem_MoveObject_Script::
	setobjectxy 1, 2, 16
	setobjectxyperm 1, 2, 16
	return


WhyAreYouHelpingThem_MoveObjectBoss_Script::
	setobjectxy 1, 2, 16
	setobjectxyperm 1, 2, 16
	setobjectxy 3, 7, 3
	setobjectxyperm 3, 7, 3
	return


WhyAreYouHelpingThem_MoveObjectAriana_Script::
	setflag FLAG_TEMP_2
	setobjectxy 2, 1, 9
	setobjectxyperm 2, 1, 9
	setobjectxy 1, 2, 16
	setobjectxyperm 1, 2, 16
	turnobject 2, DIR_NORTH
	return


WhyAreYouHelpingThem_BlowHoleWall::
	setmetatile 12, 1, 0x3F2, FALSE
	special DrawWholeMapView
	return


WhyAreYouHelpingThem_ObjectSetUpPostSave_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setobjectxy 4, 6, 3
	setobjectxyperm 4, 6, 3
	turnobject 4, DIR_WEST
	setobjectxy 1, 2, 16
	setobjectxyperm 1, 2, 16
	return


WhyAreYouHelpingThem_ObjectDebriefSetUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	setobjectxyperm 4, 26, 4
	setobjectxyperm 5, 25, 6
	setobjectxyperm 6, 27, 6
	setobjectxyperm 7, 25, 7
	setobjectxyperm 8, 27, 7
	return


WhyAreYouHelpingThem_BackAtCompound_ObjectSetUp_Script::
	setflag FLAG_TEMP_3
	setobjectxy 1, 6, 6
	setobjectxy 2, 6, 5
	setobjectxyperm 1, 6, 6
	setobjectxyperm 2, 6, 5
	turnobject 2, DIR_SOUTH
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return


WhyAreYouHelpingThem_StartRaid::
	lock
	addvar VAR_ROUTE118_STATE, 1
	playse SE_FAILURE
	playse SE_FAILURE
	playse SE_FAILURE
	playse SE_FAILURE
	applymovement 1, Common_Movement_FaceDown
	applymovement 7, WhyAreYouHelpingThem_PoliceRunIn
	applymovement 8, WhyAreYouHelpingThem_PoliceRunIn
	applymovement 9, WhyAreYouHelpingThem_PoliceRunIn
	waitmovement 0
	msgbox gText_WhyAreYouHelpingThem_StructuralBreach, MSGBOX_AUTOCLOSE
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_DefenseMode
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WeShouldRedefine
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_LetsSplitUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WhaFineIllTry
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_SeeYa
	callnative ClearMugshot
	closemessage
	applymovement 1, WhyAreYouHelpingThem_PoliceRunIn
	waitmovement 0
	removeobject 7
	removeobject 8
	removeobject 9
	call WhyAreYouHelpingThem_MoveObject_Script
	release
	end


WhyAreYouHelpingThem_WitnessBattle::
	addvar VAR_ROUTE118_STATE, 1
	lock
	applymovement 3, WhyAreYouHelpingThem_FleeTheBattle
	waitmovement 0
	call WhyAreYouHelpingThem_MoveObjectBoss_Script
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_GoAfterIllHold
	callnative ClearMugshot
	closemessage
	release
	end


WhyAreYouHelpingThem_PreBattleBoss_Script::
	lock
	applymovement 3, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, WhyAreYouHelpingThem_ApproachGiovanni
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_ItsAShameThatThe
	callnative ClearMugshot
	closemessage
	applymovement 3, Common_Movement_WalkLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_ButBeatingYou
	callnative ClearMugshot
	closemessage
	trainerbattle_continue_after_lose TRAINER_ARCHIE, gText_WhyAreYouHelpingThem_WaitAMinute
	goto WhyAreYouHelpingThem_PostBattleBoss_Dialogue
	return


WhyAreYouHelpingThem_PostBattleBoss_Dialogue::
	addvar VAR_ROUTE118_STATE, 1
	addobject 2
	call WhyAreYouHelpingThem_MoveObjectAriana_Script
	checktrainerflag TRAINER_ARCHIE
	goto_if 1, WhyAreYouHelpingThem_PostBattleBoss_Dialogue_2
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_IDidntEvenTouch
WhyAreYouHelpingThem_PostBattleBoss_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_ImSorryYouHad
	callnative ClearMugshot
	closemessage
	applymovement 2, WhyAreYouHelpingThem_WalkPastPlayer
	applymovement 3, WhyAreYouHelpingThem_HealAndFaceAdmin
	waitmovement 0
	call Common_EventScript_OutOfCenterPartyHeal
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_IHandledTheBrat
	callnative ClearMugshot
	closemessage
	playse SE_PIN
	waitse
	applymovement 2, WhyAreYouHelpingThem_ExclaimAndFacePlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_DamnYouToo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WhatWasAllThatShit
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WeveGotToHelp
	callnative ClearMugshot
	closemessage
	applymovement 3, WhyAreYouHelpingThem_BeginEscape
	applymovement 2, WhyAreYouHelpingThem_BeginEscape
	waitmovement 0
	goto WhyAreYouHelpingThem_ExplodeWall_Script
	return

WhyAreYouHelpingThem_PostBattleBoss_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_YoureIncredible
	closemessage
	callnative ClearMugshot
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	giveitem ITEM_MASTER_BALL, 1
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_AndNowWeHave
	goto WhyAreYouHelpingThem_PostBattleBoss_Dialogue_1


WhyAreYouHelpingThem_ExplodeWall_Script::
	playse SE_M_EXPLOSION
	waitse
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	call WhyAreYouHelpingThem_BlowHoleWall
	clearflag FLAG_TEMP_3
	playse SE_EXIT
	waitse
	addobject 4
	applymovement 4, WhyAreYouHelpingThem_WalkOutOfHole
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_ThisPlaceIs
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WeCantLeavePeople
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WeDontHaveTime
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_IThinkTheyreRight
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_Sigh
	callnative ClearMugshot
	closemessage
	applymovement 3, WhyAreYouHelpingThem_WalkIntoHoleA
	applymovement 2, WhyAreYouHelpingThem_WalkIntoHoleB
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 2
	removeobject 3
	applymovement 4, WhyAreYouHelpingThem_ApproachPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_YoureWorkingWith
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	goto WhyAreYouHelpingThem_StartBattle_Script
	return


WhyAreYouHelpingThem_InteractBattle_Script::
	lock
	faceplayer
	goto WhyAreYouHelpingThem_StartBattle_Script
	return


WhyAreYouHelpingThem_StartBattle_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_AlwaysHaveBeen
	trainerbattle_no_intro TRAINER_WALLY_VR_2, gText_WhyAreYouHelpingThem_AnotherVictory
	closemessage
	callnative ClearMugshot
	goto WhyAreYouHelpingThem_PostBattle_Dialogue
	return


WhyAreYouHelpingThem_PostBattle_Dialogue::
	addvar VAR_ROUTE118_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_TellsMeYoureAll
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WhyWouldIt
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_Player
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	applymovement 4, WhyAreYouHelpingThem_WalkIntoHoleC
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 4
	setobjectxyperm 1, 1, 8
	addobject 1
	applymovement 1, WhyAreYouHelpingThem_RunToPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_IGotKnockedOut
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_NoILostToo
	callnative ClearMugshot
	closemessage
	addvar VAR_NATIVERIVALBETA_STATE, 1
	fadescreen FADE_TO_BLACK
	warpsilent MAP_ALAMEDA, 255, 26, 6
	return


WhyAreYouHelpingThem_MissionDebrief_Dialogue::
	addvar VAR_NATIVERIVALBETA_STATE, 1
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_WhyAreYouHelpingThem_GreatWorkInThere
	closemessage
	applymovement 6, Common_Movement_WalkUp
	waitmovement 0
	msgbox gText_WhyAreYouHelpingThem_WeSpottedAndTheir
	closemessage
	applymovement 6, WhyAreYouHelpingThem_BackInFormation
	waitmovement 0
	msgbox gText_WhyAreYouHelpingThem_AShameStillWeveShutDown
	closemessage
	applymovement 4, Common_Movement_WalkDown
	waitmovement 0
	msgbox gText_WhyAreYouHelpingThem_NotBadInThere
	closemessage
	release
	end


WhyAreYouHelpingThem_BackAtCompound_Dialogue::
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, WhyAreYouHelpingThem_WalkIntoHome
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WhatADay
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_ItWasADay
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_GoodNewsWhileYouWere
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_OhThatWasFast
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_DontWorryAboutIt
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_NowIveGotALot
	callnative ClearMugshot
	closemessage
	applymovement 2, WhyAreYouHelpingThem_LeaveCompoundA
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 2
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_WhyAreYouHelpingThem_WeveAllGot
	callnative ClearMugshot
	closemessage
	applymovement 1, WhyAreYouHelpingThem_LeaveCompoundB
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	release
	end


WhyAreYouHelpingThem_StartChampionship_Dialogue::
	addvar VAR_NATIVERIVALBETA_STATE, 1
	msgbox gText_WhyAreYouHelpingThem_AreYouReadyToBegin, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq WhyAreYouHelpingThem_StartChampionship_Dialogue_1
	addvar VAR_STORYLINE_STATE, 1
	warpsilent MAP_CHASECENTER_LOCKERS, 9, 6
	return

WhyAreYouHelpingThem_StartChampionship_Dialogue_1:
	closemessage
	return


WhyAreYouHelpingThem_PoliceRunIn:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WhyAreYouHelpingThem_FleeTheBattle:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WhyAreYouHelpingThem_ApproachGiovanni:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WhyAreYouHelpingThem_WalkPastPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

WhyAreYouHelpingThem_BeginEscape:
	walk_right
	walk_right
	walk_right
	step_end

WhyAreYouHelpingThem_ExclaimAndFacePlayer:
	emote_exclamation_mark
	face_left
	step_end

WhyAreYouHelpingThem_WalkOutOfHole:
	walk_down
	walk_left
	walk_left
	walk_left
	face_down
	step_end

WhyAreYouHelpingThem_WalkIntoHoleA:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

WhyAreYouHelpingThem_WalkIntoHoleB:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

WhyAreYouHelpingThem_WalkIntoHoleC:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

WhyAreYouHelpingThem_ApproachBossAndPlayer:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WhyAreYouHelpingThem_HealAndFaceAdmin:
	walk_in_place_slow_left
	delay_16
	delay_16
	face_down
	step_end

WhyAreYouHelpingThem_ApproachPlayer:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

WhyAreYouHelpingThem_RunToPlayer:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

WhyAreYouHelpingThem_BackInFormation:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

WhyAreYouHelpingThem_WalkToPlayerFormation:
	walk_right
	walk_down
	step_end

WhyAreYouHelpingThem_WalkIntoHome:
	walk_up
	walk_up
	walk_up
	step_end

WhyAreYouHelpingThem_LeaveCompoundA:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_down
	face_down
	step_end

WhyAreYouHelpingThem_LeaveCompoundB:
	walk_down
	walk_down
	walk_down
	step_end

gText_WhyAreYouHelpingThem_StructuralBreach::
	.string "STRUCTURAL BREACH DETECTED. BASE IS\n"
	.string "NOW SHIFTING TO DEFENSE MODE.\l"
	.string "EVACUATE IMMEDIATELY.$"

gText_WhyAreYouHelpingThem_DefenseMode::
	.string "“Defense mode” is pretty advanced for\n"
	.string "some abandoned buildings.$"

gText_WhyAreYouHelpingThem_WeShouldRedefine::
	.string "We should redefine abandoned…$"

gText_WhyAreYouHelpingThem_LetsSplitUp::
	.string "Let's split up. I'm faster than you and\n"
	.string "can cut off the leaders before they\l"
	.string "escape.$"

gText_WhyAreYouHelpingThem_WhaFineIllTry::
	.string "wha - fine, I'll try to find the source\n"
	.string "of the hack and shut it down.$"

gText_WhyAreYouHelpingThem_SeeYa::
	.string "See ya.$"

gText_WhyAreYouHelpingThem_GoAfterIllHold::
	.string "Go after Giovanni! I'll hold this one\n"
	.string "off.$"

gText_WhyAreYouHelpingThem_ItsAShameThatThe::
	.string "It's a shame that the cops have totally\n"
	.string "infiltrated our youth.$"

gText_WhyAreYouHelpingThem_ButBeatingYou::
	.string "But beating you is going to be the best\n"
	.string "route out of here.$"

gText_WhyAreYouHelpingThem_WaitAMinute::
	.string "Wait a minute…$"

gText_WhyAreYouHelpingThem_YoureIncredible::
	.string "You're incredible. Or a cheater. Can't\n"
	.string "quite tell. Either way, you can have\l"
	.string "this.$"

gText_WhyAreYouHelpingThem_AndNowWeHave::
	.string "And now we have to act like I won.$"

gText_WhyAreYouHelpingThem_IDidntEvenTouch::
	.string "…I didn't even touch him…$"

gText_WhyAreYouHelpingThem_ImSorryYouHad::
	.string "I'm sorry you had to experience that. I\n"
	.string "hope you eventually understand what's\l"
	.string "at stake here, {PLAYER}. Let me help\l"
	.string "you.$"

gText_WhyAreYouHelpingThem_IHandledTheBrat::
	.string "I handled the brat. I'm guessing you\n"
	.string "beat -$"

gText_WhyAreYouHelpingThem_DamnYouToo::
	.string "Damn, you too, {PLAYER}?$"

gText_WhyAreYouHelpingThem_WhatWasAllThatShit::
	.string "What was all that shit you tried to tell\n"
	.string "me before?! What the hell is\l"
	.string "TeamRocket doing?$"

gText_WhyAreYouHelpingThem_WeveGotToHelp::
	.string "We've got to help more comrades escape.\n"
	.string "Another time.$"

gText_WhyAreYouHelpingThem_ThisPlaceIs::
	.string "This place is swarming with cops. You\n"
	.string "two need to get the hell out, right now.\l"
	.string "This goes straight out.$"

gText_WhyAreYouHelpingThem_WeCantLeavePeople::
	.string "We can't leave people behind.$"

gText_WhyAreYouHelpingThem_WeDontHaveTime::
	.string "We don't have time for this! If you get\n"
	.string "arrested, this all falls apart! You.\l"
	.string "Need. To. Go.$"

gText_WhyAreYouHelpingThem_IThinkTheyreRight::
	.string "I think they're right.$"

gText_WhyAreYouHelpingThem_Sigh::
	.string "…*sigh*$"

gText_WhyAreYouHelpingThem_YoureWorkingWith::
	.string "You're working with TeamRocket too?!?$"

gText_WhyAreYouHelpingThem_AlwaysHaveBeen::
	.string "Always have been.$"

gText_WhyAreYouHelpingThem_AnotherVictory::
	.string "*sigh* Another victory for the\n"
	.string "establishment.$"

gText_WhyAreYouHelpingThem_TellsMeYoureAll::
	.string "Ariana tells me you're all good\n"
	.string "guys… now all this shit? And you? None\l"
	.string "of this makes any sense!$"

gText_WhyAreYouHelpingThem_WhyWouldIt::
	.string "Why would it? You don't see what your\n"
	.string "bosses are doing to SanFran. You\l"
	.string "don't see what you're doing to\l"
	.string "SanFran.$"

gText_WhyAreYouHelpingThem_Player::
	.string "{PLAYER}!$"

gText_WhyAreYouHelpingThem_IGotKnockedOut::
	.string "I got knocked out. Did you stop\n"
	.string "Giovanni?$"

gText_WhyAreYouHelpingThem_NoILostToo::
	.string "No, I lost too.$"

gText_WhyAreYouHelpingThem_GreatWorkInThere::
	.string "Great work in there, team. Andre, what's\n"
	.string "the sitrep regarding TeamRocket\l"
	.string "leadership?$"

gText_WhyAreYouHelpingThem_WeSpottedAndTheir::
	.string "We spotted Giovanni and their\n"
	.string "lieutenant escaping on Pokemon by\l"
	.string "using the move Fly. We were unable to\l"
	.string "track them given our resources.$"

gText_WhyAreYouHelpingThem_AShameStillWeveShutDown::
	.string "A shame. Still, we've shut down their\n"
	.string "primary base of operations, and we\l"
	.string "arrested a bunch of these shitheads.\l"
	.string "This was an absolute win!$"

gText_WhyAreYouHelpingThem_NotBadInThere::
	.string "Not bad in there. Oak wants you\n"
	.string "kids back at SouthBay Compound.$"

gText_WhyAreYouHelpingThem_WhatADay::
	.string "What… a day. I know that was a lot of\n"
	.string "pressure, but from what I hear, you\l"
	.string "were both fantastic. Thank you.$"

gText_WhyAreYouHelpingThem_ItWasADay::
	.string "…it was a day.$"

gText_WhyAreYouHelpingThem_GoodNewsWhileYouWere::
	.string "Good news - while you were training in\n"
	.string "MuirWoods, construction on ChaseCenter\l"
	.string "finished up. The Group Stage will start\l"
	.string "in 3 days. Hopefully, that's enough time\l"
	.string "to rest up and get ready.$"

gText_WhyAreYouHelpingThem_OhThatWasFast::
	.string "Oh, that was fast. How did you…$"

gText_WhyAreYouHelpingThem_DontWorryAboutIt::
	.string "Don't worry about it! You two just\n"
	.string "focus on winning!$"

gText_WhyAreYouHelpingThem_NowIveGotALot::
	.string "Now, I've got a lot of work to do\n"
	.string "between now and then. I'll see you both\l"
	.string "in a few days!$"

gText_WhyAreYouHelpingThem_WeveAllGot::
	.string "We've all got some work to do! I'll see\n"
	.string "you around, {PLAYER}.$"

gText_WhyAreYouHelpingThem_AreYouReadyToBegin::
	.string "Are you ready to begin the\n"
	.string "Championship?$"
