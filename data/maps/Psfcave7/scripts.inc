Psfcave7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcave7_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Psfcave7_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Psfcave7_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Psfcave7_ExhibitCheck_Script
	call Psfcave7_MapScripts_OnTransition
	return

Psfcave7_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_PSFCAVE7_STATE, 3, YouRealizeTheyreEvilRight_PlayerLandedDialogue
	.2byte 0


Psfcave7_MapScripts_OnTransition::
	call YouRealizeTheyreEvilRight_HideObject_Script
	call YouRealizeTheyreEvilRight_ShowObject_Script
	return


Psfcave7_ExhibitCheck_Script::
	compare VAR_PSFCAVE7_EXHIBIT_STATE, 2
	goto_if_lt Psfcave7_ExhibitCheck_Script_1
	return

Psfcave7_ExhibitCheck_Script_1:
	call ResetPsfcave7Exhibit_Script
	removeobject 9
	end


TheStorySoFar_ExplainExhibit_Dialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_TheStorySoFar_WelcomeToExhibit
	closemessage
	setvar VAR_PSFCAVE7_EXHIBIT_STATE, 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end


TheStorySoFar_InteractWithAttendant_Script::
	lockall
	applymovement 8, Common_Movement_FacePlayer
	goto TheStorySoFar_Event_Script
	return


TheStorySoFar_EntranceTrigger_Script::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 8, Common_Movement_FaceLeft
	goto TheStorySoFar_Event_Script
	return


TheStorySoFar_Event_Script::
	waitmovement 0
	switch VAR_PSFCAVE7_EXHIBIT_STATE
	case 0, TheStorySoFar_Event_Script_2
	case 1, TheStorySoFar_Event_Script_3
	case 2, TheStorySoFar_Event_Script_4
	case 3, TheStorySoFar_Event_Script_5
	case 4, TheStorySoFar_Event_Script_6
	return

TheStorySoFar_Event_Script_2:
	goto TheStorySoFar_ExplainExhibit_Dialogue
	return

TheStorySoFar_Event_Script_3:
	goto TheStorySoFar_CheckNumberDefeated_Script
	return

TheStorySoFar_Event_Script_4:
	goto TheStorySoFar_AwardPlayer_Script
	return

TheStorySoFar_Event_Script_5:
	goto TheStorySoFar_Congratulate_Dialogue
	return

TheStorySoFar_Event_Script_6:
	goto Psfcave7Attendant_HealPlayer_Script
	goto TheStorySoFar_CheckNumberDefeated_Script
	return


TheStorySoFar_CheckNumberDefeated_Script::
	special CheckNumPsfcave7ExhibitDefeated
	lockall
	msgbox gText_TheStorySoFar_YoureNotQuiteDone
	switch VAR_RESULT
	case 0, TheStorySoFar_CheckNumberDefeated_Script_3
	case 1, TheStorySoFar_CheckNumberDefeated_Script_4
	case 2, TheStorySoFar_CheckNumberDefeated_Script_5
	case 3, TheStorySoFar_CheckNumberDefeated_Script_6
	case 4, TheStorySoFar_CheckNumberDefeated_Script_7
	case 5, TheStorySoFar_CheckNumberDefeated_Script_8
TheStorySoFar_CheckNumberDefeated_Script_1:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_11
TheStorySoFar_CheckNumberDefeated_Script_9:
	closemessage
	releaseall
	end

TheStorySoFar_CheckNumberDefeated_Script_3:
	msgbox gText_TheStorySoFar_YouNeedToDefeat6
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_4:
	msgbox gText_TheStorySoFar_YouNeedToDefeat5
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_5:
	msgbox gText_TheStorySoFar_YouNeedToDefeat4
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_6:
	msgbox gText_TheStorySoFar_YouNeedToDefeat3
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_7:
	msgbox gText_TheStorySoFar_YouNeedToDefeat2
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_8:
	msgbox gText_TheStorySoFar_YouNeedToDefeat1
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_10:
	msgbox gText_TheStorySoFar_AreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_15
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	call ResetPsfcave7Exhibit_Script
TheStorySoFar_CheckNumberDefeated_Script_14:
	waitmovement 0
	goto TheStorySoFar_CheckNumberDefeated_Script_9

TheStorySoFar_CheckNumberDefeated_Script_11:
	compare VAR_TEMP_1, 16
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_10
	goto TheStorySoFar_CheckNumberDefeated_Script_9

TheStorySoFar_CheckNumberDefeated_Script_15:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	goto TheStorySoFar_CheckNumberDefeated_Script_14


TheStorySoFar_AwardPlayer_Script::
	lockall
	setvar VAR_PSFCAVE7_EXHIBIT_STATE, 3
	setvar VAR_PSFCAVE7_STATE, 1
	msgbox gText_TheStorySoFar_ExcellentWork
	giveitem ITEM_MACHO_BRACE, 1
	closemessage
	releaseall
	end


TheStorySoFar_Congratulate_Dialogue::
	lockall
	msgbox gText_TheStorySoFar_WeHopeYouReturn
	closemessage
	releaseall
	end


Psfcave7Attendant_HealPlayer_Script::
	lockall
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox gText_TheStorySoFar_IveHealedYourParty
	call ResetPsfcave7Exhibit_Script
	closemessage
	releaseall
	end


ResetPsfcave7Exhibit_Script::
	clearflag TRAINER_FLAGS_START + TRAINER_ALBERTO
	clearflag TRAINER_FLAGS_START + TRAINER_ED
	clearflag TRAINER_FLAGS_START + TRAINER_DECLAN
	clearflag TRAINER_FLAGS_START + TRAINER_FREDRICK
	clearflag TRAINER_FLAGS_START + TRAINER_ZANDER
	clearflag TRAINER_FLAGS_START + TRAINER_LEAH
	compare VAR_PSFCAVE7_STATE, 2
	goto_if_lt ResetPsfcave7Exhibit_Script_1
	return

ResetPsfcave7Exhibit_Script_1:
	setvar VAR_PSFCAVE7_EXHIBIT_STATE, 0
	return


TheStorySoFar_StartBattle1_Script::
	trainerbattle_single TRAINER_ALBERTO, gText_TheStorySoFar_IHopeYouDont, gText_TheStorySoFar_SlowDown, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_DontForgetToStop, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign1_Dialogue::
	msgbox gText_TheStorySoFar_OriginallyBuiltAsAPrison, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle2_Script::
	trainerbattle_single TRAINER_ED, gText_TheStorySoFar_IThinkDefense, gText_TheStorySoFar_NotStrongEnough, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_TheBestOffense, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign2_Dialogue::
	msgbox gText_TheStorySoFar_TheCriminalUnderbelly, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle3_Script::
	trainerbattle_single TRAINER_DECLAN, gText_TheStorySoFar_TheresSomethingSpecial, gText_TheStorySoFar_ImNotSpecial, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_ItsHardToDoAnything, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign3_Dialogue::
	msgbox gText_TheStorySoFar_ThePrisonersBeganToTurn, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle4_Script::
	trainerbattle_single TRAINER_FREDRICK, gText_TheStorySoFar_PhysicallyDefensiveMasterpiece, gText_TheStorySoFar_ButLikeTheShip, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_HumansWillAlwaysFind, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign4_Dialogue::
	msgbox gText_TheStorySoFar_AsTensionsBetweenThePrisoners, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle5_Script::
	trainerbattle_single TRAINER_ZANDER, gText_TheStorySoFar_BrokenBonesHealEasily, gText_TheStorySoFar_SomePeopleNeverRecover, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_MakingSureToTakeCare, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign5_Dialogue::
	msgbox gText_TheStorySoFar_TheNaturalDisasterLeft, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle6_Script::
	trainerbattle_single TRAINER_LEAH, gText_TheStorySoFar_HowToughAreYou, gText_TheStorySoFar_TurnsOutPrettyTough, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_IHearVoicesStanding, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign6_Dialogue::
	msgbox gText_TheStorySoFar_ParksAndRecreation, MSGBOX_SIGN
	return


TheStorySoFar_RunDefeatedCheck_Script::
	special CheckNumPsfcave7ExhibitDefeated
	end


YoungPadawan_Intro_Dialogue::
	lockall
	clearflag FLAG_HIDE_STORYSOFAR_PSFELITE1
	addobject 9
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	applymovement 9, YoungPadawan_GetOffBoat
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_WowYouLookTired
	call Common_EventScript_OutOfCenterPartyHeal
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_DidTheChallenge
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_ThankYou
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_DontMentionIt
	callnative ClearMugshot
	closemessage
	applymovement 9, YoungPadawan_LookAtOcean
	applymovement OBJ_EVENT_ID_PLAYER, YoungPadawan_StepDownWalkBeside
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_LearnALot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_TheStoryOfTheIsland
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_ThatQuakeWasOne
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_HistoryBooksAreCrazy
	callnative ClearMugshot
	closemessage
	applymovement 9, YoungPadawan_WalkBackToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_MakesYouWonder
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_MakesSenseYeah
	goto YoungPadawan_StartBattle_Script
	return


YoungPadawan_StartBattle_Script::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_YouveGotAGoodSpirit
	callnative ClearMugshot
	closemessage
	trainerbattle_continue_after_lose TRAINER_SIDNEY, gText_YoungPadawan_DontBeatYourselfUp
	goto YoungPadawan_PostBattle_Dialogue
	return


YoungPadawan_PostBattle_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	checktrainerflag TRAINER_SIDNEY
	goto_if 1, YoungPadawan_PostBattle_Dialogue_2
	special HealPlayerParty
	msgbox gText_YoungPadawan_KeepTraining
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_IveNeverBattled
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_YeahTotally
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_UntilThenHeres
	closemessage
	callnative ClearMugshot
YoungPadawan_PostBattle_Dialogue_1:
	giveitem ITEM_GO_GOGGLES, 1
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_ThoseCanBeTough
	callnative ClearMugshot
	closemessage
	applymovement 9, YoungPadawan_WalkUpStairs
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, YoungPadawan_GetOutOfWay
	waitmovement 0
	removeobject 9
	setvar VAR_PSFCAVE7_STATE, 2
	setvar VAR_PSFCAVE7_EXHIBIT_STATE, 4
	releaseall
	end

YoungPadawan_PostBattle_Dialogue_2:
	msgbox gText_YoungPadawan_DidYouHack
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_GotItYouWon
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_KeepItSecretToo
	callnative ClearMugshot
	closemessage
	giveitem ITEM_POWER_ANKLET, 1
	giveitem ITEM_POWER_BAND, 1
	giveitem ITEM_POWER_BRACER, 1
	giveitem ITEM_POWER_LENS, 1
	giveitem ITEM_POWER_WEIGHT, 1
	giveitem ITEM_POWER_BELT, 1
	goto YoungPadawan_PostBattle_Dialogue_1


Psfcave7_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Psfcave7_UnlockedDestinations_Script
	return


Psfcave7_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	goto Psfcave7_FerryState0_Script
	return


Psfcave7_FerryState0_Script::
	multichoicedefault 18, 8, PSFCAVE7_FERRY_DESTINATIONS_VER1, 0, FALSE
	call SlateportCity_Harbor_EventScript_BoardFerry
	switch VAR_RESULT
	case 0, Psfcave7_FerryState0_Script_2
	case 1, Psfcave7_FerryState0_Script_3
	case 2, Psfcave7_FerryState0_Script_4
	case MULTI_B_PRESSED, Psfcave7_FerryState0_Script_5
	return

Psfcave7_FerryState0_Script_2:
	warp MAP_PSFPLACE13, 5, 6
	return

Psfcave7_FerryState0_Script_3:
	warp MAP_PSFCITY17, 3, 16
	return

Psfcave7_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return

Psfcave7_FerryState0_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	return


YoungPadawan_GetOffBoat:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YoungPadawan_StepDownWalkBeside:
	walk_down
	face_left
	step_end

YoungPadawan_LookAtOcean:
	walk_left
	step_end

YoungPadawan_WalkBackToPlayer:
	walk_down
	walk_right
	face_up
	step_end

YoungPadawan_WalkUpStairs:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YoungPadawan_GetOutOfWay:
	walk_left
	delay_16
	walk_right
	face_up
	step_end

gText_YoungPadawan_WowYouLookTired::
	.string "Wow, you look tired! Let me help.$"

gText_YoungPadawan_DidTheChallenge::
	.string "Did the challenge kick your ass? Those\n"
	.string "kids are tough.$"

gText_YoungPadawan_ThankYou::
	.string "Thank you!$"

gText_YoungPadawan_DontMentionIt::
	.string "Don't mention it.$"

gText_YoungPadawan_LearnALot::
	.string "Learn a lot up there?$"

gText_YoungPadawan_TheStoryOfTheIsland::
	.string "The story of the island is crazy. And I\n"
	.string "didn't realize the earthquakes here\l"
	.string "could be that vicious.$"

gText_YoungPadawan_ThatQuakeWasOne::
	.string "That quake was one for the history\n"
	.string "books! Shook me to my core.$"

gText_YoungPadawan_HistoryBooksAreCrazy::
	.string "History books are crazy. Losers don't\n"
	.string "get a pre-release copy to leave their\l"
	.string "edits in the margins... the winners just\l"
	.string "say whatever they want, and everybody\l"
	.string "has to deal with it.$"

gText_YoungPadawan_MakesYouWonder::
	.string "Makes you wonder how committed to\n"
	.string "accuracy the winners are. Old geezers\l"
	.string "like me, who were around for the\l"
	.string "history in the making, have a\l"
	.string "responsibility to set the record\l"
	.string "straight. Gotta make sure the truth\l"
	.string "doesn't get lost, you know?$"

gText_YoungPadawan_MakesSenseYeah::
	.string "Makes sense, yeah. But the government\n"
	.string "doesn't have any reason to lie, which is\l"
	.string "a relief.$"

gText_YoungPadawan_YouveGotAGoodSpirit::
	.string "Hah! You got a good spirit. Let's see\n"
	.string "how long you can hold up against your\l"
	.string "elders!$"

gText_YoungPadawan_DidIUnderestimate::
	.string "Did I underestimate you?$"

gText_YoungPadawan_KidYoureSomethingElse::
	.string "Kid, you're something else! But it ends\n"
	.string "here.$"

gText_YoungPadawan_DontBeatYourselfUp::
	.string "Heh, don't beat yourself up. I got at\n"
	.string "least 50 years on ya.$"

gText_YoungPadawan_ThisAintHowItWas::
	.string "This ain't how it was supposed to go!$"

gText_YoungPadawan_DidYouHack::
	.string "Did you hack the Matrix? Maybe you got\n"
	.string "REAL lucky on a randomizer run? ... We're\l"
	.string "gonna pretend I won, okay?$"

gText_YoungPadawan_GotItYouWon::
	.string "Haha got it, you won.$"

gText_YoungPadawan_KeepItSecretToo::
	.string "Keep it secret too. Here, take these.$"

gText_YoungPadawan_KeepTraining::
	.string "Keep training! Once you learn a little\n"
	.string "bit more about the world, let's battle\l"
	.string "again.$"

gText_YoungPadawan_IveNeverBattled::
	.string "(I've never battled anybody so strong!)$"

gText_YoungPadawan_YeahTotally::
	.string "Yeah, totally!$"

gText_YoungPadawan_UntilThenHeres::
	.string "Until then, here's a consolation prize.$"

gText_YoungPadawan_ThoseCanBeTough::
	.string "Those can be tough to get if you're not\n"
	.string "from here. Good luck with the rest of\l"
	.string "your challenge, {PLAYER}.$"

gText_TheStorySoFar_WelcomeToExhibit::
	.string "Welcome to the Psfcave7 Exhibit. To\n"
	.string "learn about the island, you'll need to\l"
	.string "battle our staff. Trainers who can\l"
	.string "defeat all six without leaving the park\l"
	.string "or being defeated will complete the\l"
	.string "challenge and win a prize! If you leave,\l"
	.string "you'll need to start the challenge over\l"
	.string "again.$"

gText_TheStorySoFar_YoureNotQuiteDone::
	.string "You're not quite done.$"

gText_TheStorySoFar_AreYouSure::
	.string "Are you sure you want to leave?$"

gText_TheStorySoFar_YouNeedToDefeat6::
	.string "You need to defeat six more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat5::
	.string "You need to defeat five more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat4::
	.string "You need to defeat four more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat3::
	.string "You need to defeat three more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat2::
	.string "You need to defeat two more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat1::
	.string "You need to defeat one more staff\n"
	.string "member without leaving to complete the\l"
	.string "challenge.$"

gText_TheStorySoFar_IHopeYouDont::
	.string "I hope you don't rush through the plaza\n"
	.string "here!$"

gText_TheStorySoFar_SlowDown::
	.string "Slow down!$"

gText_TheStorySoFar_DontForgetToStop::
	.string "Don't forget to stop and smell the\n"
	.string "roses.$"

gText_TheStorySoFar_OriginallyBuiltAsAPrison::
	.string "Psfcave7 was originally built as a\n"
	.string "prison for Psfregion1's most dangerous\l"
	.string "criminals. Psfcave7 Prison was\l"
	.string "nationally praised for its state of the\l"
	.string "art facilities, forward thinking\l"
	.string "approach to rehabilitation, and no\l"
	.string "escape attempts.$"

gText_TheStorySoFar_IThinkDefense::
	.string "I think the best defense is an\n"
	.string "overwhelming offense.$"

gText_TheStorySoFar_NotStrongEnough::
	.string "Not strong enough!$"

gText_TheStorySoFar_TheBestOffense::
	.string "The best offense is the kind that gets\n"
	.string "stronger with time.$"

gText_TheStorySoFar_TheCriminalUnderbelly::
	.string "The Psfregion1 criminal underbelly,\n"
	.string "using agents within the prison, staged\l"
	.string "a prison riot. The agents took guards\l"
	.string "hostage, and demanded that the\l"
	.string "government turn the island over to the\l"
	.string "prisoners. This occupation lasted for\l"
	.string "years, and the demands of the\l"
	.string "prisoners grew more unreasonable as\l"
	.string "time went on.$"

gText_TheStorySoFar_TheresSomethingSpecial::
	.string "There's something special about power\n"
	.string "in large groups...$"

gText_TheStorySoFar_ImNotSpecial::
	.string "I'm not special on my own.$"

gText_TheStorySoFar_ItsHardToDoAnything::
	.string "It's hard to do anything meaningful on\n"
	.string "your own. We're made to work together!$"

gText_TheStorySoFar_ThePrisonersBeganToTurn::
	.string "The prisoners began to turn to the\n"
	.string "citizens of the region for support. One\l"
	.string "of their most vocal allies was\l"
	.string "Psfelite2, the strongest member of the\l"
	.string "Psfregion1 Elite Four. Psfelite2\l"
	.string "organized public rallies and marches,\l"
	.string "demanding for the release of the\l"
	.string "prisoners into society, citing the need\l"
	.string "for a different rehabilitation\l"
	.string "approach.$"

gText_TheStorySoFar_PhysicallyDefensiveMasterpiece::
	.string "Psfcave7 is a physically defensive\n"
	.string "masterpiece, isn't it?$"

gText_TheStorySoFar_ButLikeTheShip::
	.string "But like the ship that couldn't sink...$"

gText_TheStorySoFar_HumansWillAlwaysFind::
	.string "Humans will always find a way to ruin\n"
	.string "perfection.$"

gText_TheStorySoFar_AsTensionsBetweenThePrisoners::
	.string "As tensions between the prisoners,\n"
	.string "their sympathizers, and the\l"
	.string "government reached a fever pitch,\l"
	.string "disaster suddenly struck. An\l"
	.string "unprecedented earthquake ripped\l"
	.string "through the eastern seaboard of the\l"
	.string "region, destroying the structure of\l"
	.string "the prison. Hundreds were injured, and\l"
	.string "many were killed.$"

gText_TheStorySoFar_BrokenBonesHealEasily::
	.string "Broken bones heal easily, but the spirit\n"
	.string "is a whole other matter.$"

gText_TheStorySoFar_SomePeopleNeverRecover::
	.string "Some people never recover!$"

gText_TheStorySoFar_MakingSureToTakeCare::
	.string "Making sure to take care of your soul is\n"
	.string "important!$"

gText_TheStorySoFar_TheNaturalDisasterLeft::
	.string "The natural disaster left the prisoners\n"
	.string "broken and defeated, and they quickly\l"
	.string "surrendered. The prisoners were\l"
	.string "charged with conspiracy and\l"
	.string "instigation, seperated, and sent to\l"
	.string "different prisons around the nation.\l"
	.string "Psfcave7 was shut down.$"

gText_TheStorySoFar_HowToughAreYou::
	.string "How tough are you?$"

gText_TheStorySoFar_TurnsOutPrettyTough::
	.string "Turns out, pretty tough!$"

gText_TheStorySoFar_IHearVoicesStanding::
	.string "Sometimes, I hear voices standing here\n"
	.string "all day.$"

gText_TheStorySoFar_ParksAndRecreation::
	.string "The Psfregion1 Parks and Recreation\n"
	.string "has dedicated this plaza to the guards\l"
	.string "who lost their lives in the disaster and\l"
	.string "the struggle that divided the region\l"
	.string "for so long. Late at night, some say you\l"
	.string "can hear their spirits, still fighting\l"
	.string "to this day to keep our region safe\l"
	.string "from criminals.$"

gText_TheStorySoFar_ExcellentWork::
	.string "Excellent work! For completing the\n"
	.string "challenge, here is your prize!$"

gText_TheStorySoFar_WeHopeYouReturn::
	.string "Congratulations! We hope you return\n"
	.string "for more training!$"

gText_TheStorySoFar_IveHealedYourParty::
	.string "I've healed your party! You can battle\n"
	.string "these Trainers as often as you like.$"
