SurvivalChance333_HideObject_Script::
	setflag FLAG_TEMP_1
	return


SurvivalChance333_HideObject_Alameda_Script::
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_4
	return


SurvivalChance333_MovePlayerIntoPosition::
	lock
	setvar VAR_FERRYBUILDING_STATE, PLAYER_READY_SURVIVAL_CHANCE_BATTLE
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 12
	goto_if_ne SurvivalChance333_MovePlayerIntoPosition_1
	return

SurvivalChance333_MovePlayerIntoPosition_1:
	applymovement OBJ_EVENT_ID_PLAYER, SurvivalChance333_WalkToChief
	waitmovement 0
	return


SurvivalChance333_SetUpRaidObject_Script::
	setobjectxyperm 4, 18, 12
	setobjectxyperm 5, 21, 12
	setobjectxyperm 6, 22, 12
	setobjectxyperm 7, 23, 12
	setobjectxyperm 8, 19, 12
	setobjectxy 4, 18, 12
	setobjectxy 5, 21, 12
	setobjectxy 6, 22, 12
	setobjectxy 7, 23, 12
	setobjectxy 8, 19, 12
	setobjectxy OBJ_EVENT_ID_PLAYER, 24, 11
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	return


SurvivalChance333_BlowOpenDoors::
	setmetatile 22, 11, 0x0A7, FALSE
	setmetatile 18, 11, 0x0A7, FALSE
	special DrawWholeMapView
	return


SurvivalChance333_ExplainPlan_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 25
	msgbox gText_SurvivalChance333_HeresThe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_IsSomethingWrong
	callnative ClearMugshot
	msgbox gText_SurvivalChance333_ISpent15Years
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_WoahWerePlentyTough
	callnative ClearMugshot
	msgbox gText_SurvivalChance333_RightKidsWithZero
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_HeyWeDidntAsk
	callnative ClearMugshot
	msgbox gText_SurvivalChance333_AndIDidntAsk
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_IllProveIt
	callnative ClearMugshot
	setvar VAR_FERRYBUILDING_STATE, SAVE_SURVIVAL_CHANCE_BATTLE
	call Common_EventScript_SaveGame
	goto SurvivalChance333_Battle_Script
	return


SurvivalChance333_Battle_Script::
	msgbox gText_SurvivalChance333_WontEvenBeAFair
	closemessage
	multi_fixed_2_vs_1 TRAINER_TIFFANY, gText_SurvivalChance333_Hmph, TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	goto SurvivalChance333_PostBattle_Script
	return


SurvivalChance333_PostBattle_Script::
	setvar VAR_FERRYBUILDING_STATE, DEFEATED_SURVIVAL_CHANCE_BATTLE
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_DoYouGetItNow
	callnative ClearMugshot
	msgbox gText_SurvivalChance333_YoureAPairOfKids
	closemessage
	setvar VAR_ALAMEDA_STATE, START_SURVIVAL_CHANCE
	warpsilent MAP_ALAMEDA, 255, 21, 24
	return


SurvivalChance333_MoveCameraFreeze_Script::
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8004, 38
	setvar VAR_0x8005, 11
	special TeleportCamera
	delay 16
	addobject 10
	addobject 9
	fadescreen FADE_FROM_BLACK
	goto SurvivalChance333_FreezeIce
	return


SurvivalChance333_FreezeIce::
	setmetatile 39, 12, 0x0C5, TRUE
	setmetatile 39, 11, 0x0C5, TRUE
	special DrawWholeMapView
	delay 16
	setmetatile 38, 10, 0x0C5, TRUE
	setmetatile 39, 10, 0x0C5, TRUE
	setmetatile 38, 9, 0x0C5, TRUE
	special DrawWholeMapView
	delay 16
	setmetatile 39, 9, 0x0C5, TRUE
	setmetatile 37, 8, 0x0C5, TRUE
	setmetatile 38, 8, 0x0C5, TRUE
	setmetatile 39, 8, 0x0C5, TRUE
	special DrawWholeMapView
	delay 16
	setmetatile 37, 7, 0x0C5, TRUE
	setmetatile 38, 7, 0x0C5, TRUE
	setmetatile 39, 7, 0x0C5, TRUE
	special DrawWholeMapView
	return


SurvivalChance333_MoveCameraLava_Script::
	fadescreen FADE_TO_BLACK
	special ReturnCameraToPlayer
	setvar VAR_0x8004, 12
	setvar VAR_0x8005, 8
	special TeleportCamera
	delay 16
	addobject 12
	addobject 11
	fadescreen FADE_FROM_BLACK
	goto SurvivalChance333_SetLava
	return


SurvivalChance333_SetLava::
	setmetatile 11, 9, 0x333, TRUE
	special DrawWholeMapView
	delay 16
	setmetatile 11, 8, 0x333, TRUE
	setmetatile 11, 10, 0x333, TRUE
	special DrawWholeMapView
	delay 16
	setmetatile 11, 7, 0x333, TRUE
	setmetatile 11, 11, 0x333, TRUE
	setmetatile 11, 6, 0x333, TRUE
	setmetatile 11, 12, 0x333, TRUE
	special DrawWholeMapView
	delay 16
	setmetatile 11, 3, 0x333, TRUE
	setmetatile 11, 4, 0x333, TRUE
	setmetatile 11, 5, 0x333, TRUE
	setmetatile 11, 13, 0x333, TRUE
	setmetatile 30, 4, 0x333, TRUE
	setmetatile 30, 5, 0x333, TRUE
	setmetatile 30, 6, 0x333, TRUE
	setmetatile 30, 7, 0x333, TRUE
	setmetatile 30, 8, 0x333, TRUE
	setmetatile 30, 9, 0x333, TRUE
	setmetatile 30, 10, 0x333, TRUE
	setmetatile 30, 11, 0x333, TRUE
	setmetatile 30, 12, 0x333, TRUE
	setmetatile 30, 13, 0x333, TRUE
	setmetatile 30, 14, 0x333, TRUE
	setmetatile 30, 15, 0x333, TRUE
	setmetatile 30, 16, 0x333, TRUE
	special DrawWholeMapView
	return


SurvivalChance333_ExplainOperation::
	lock
	setvar VAR_ALAMEDA_STATE, 4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox gText_SurvivalChance333_SoThatsThePlan
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_OneProblemForUs
	callnative ClearMugshot
	msgbox gText_SurvivalChance333_HereWeGo
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_IKnowWereSupposed
	callnative ClearMugshot
	msgbox gText_SurvivalChance333_OhHellThatsRight
	closemessage
	applymovement 7, SurvivalChance333_GiveTM
	applymovement 8, SurvivalChance333_GiveTM
	waitmovement 0
	giveitem ITEM_TM40
	closemessage
	applymovement 7, SurvivalChance333_BackToPosition
	applymovement 8, SurvivalChance333_BackToPosition
	waitmovement 0
	msgbox gText_SurvivalChance333_IAlwaysForget
	msgbox gText_SurvivalChance333_NoSir
	msgbox gText_SurvivalChance333_LetsGetThisParty
	closemessage
	goto SurvivalChance333_TacticalPlan_Cutscene_Script
	return


SurvivalChance333_TacticalPlan_Cutscene_Script::
	lock
	call SurvivalChance333_MoveCameraFreeze_Script
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_ThoseRoutesFrozen
	callnative ClearMugshot
	closemessage
	call SurvivalChance333_MoveCameraLava_Script
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_MeltingTheBedrock
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	call SurvivalChance333_SetUpRaidObject_Script
	TeleportCamera 24, 11
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_TheyllBlowTheWall
	callnative ClearMugshot
	closemessage
	playse SE_M_EXPLOSION
	waitse
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special ShakeCamera
	waitstate
	call SurvivalChance333_BlowOpenDoors
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_SurvivalChance333_Showtime
	callnative ClearMugshot
	closemessage
	applymovement 4, SurvivalChance333_RunInsideA
	applymovement 5, SurvivalChance333_RunInsideB
	applymovement 6, SurvivalChance333_RunInsideA
	applymovement 7, SurvivalChance333_RunInsideC
	applymovement 8, SurvivalChance333_RunInsideC
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	playse SE_EXIT
	waitse
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	release
	end


SurvivalChance333_WalkToChief:
	walk_right
	walk_up
	walk_up
	step_end

SurvivalChance333_GiveTM:
	walk_down
	walk_down
	face_left
	walk_in_place_slow_left
	step_end

SurvivalChance333_BackToPosition:
	walk_up
	walk_up
	step_end

SurvivalChance333_RunInsideA:
	walk_up
	step_end

SurvivalChance333_RunInsideB:
	walk_right
	walk_up
	step_end

SurvivalChance333_RunInsideC:
	walk_left
	walk_up
	step_end

gText_SurvivalChance333_HeresThe::
	.string "*sigh* Here's the fuckin' plan. We're gonna\n"
	.string "-$"

gText_SurvivalChance333_IsSomethingWrong::
	.string "Is something wrong Chief?$"

gText_SurvivalChance333_ISpent15Years::
	.string "I spent 15 years in the military,\n"
	.string "dedicated my life to tactical warfare\l"
	.string "and I've never run a failed operation…\l"
	.string "and now somehow I'm doing the dirty\l"
	.string "work for some tech bros. And while I'm\l"
	.string "Ycombinator's bitch, I have to babysit\l"
	.string "two hotshots from nowhere as I try to\l"
	.string "infiltrate a terrorist organization.$"

gText_SurvivalChance333_WoahWerePlentyTough::
	.string "Woah, we're plenty tough! You don't need\n"
	.string "to babysit us!$"

gText_SurvivalChance333_RightKidsWithZero::
	.string "Right, kids with zero operations\n"
	.string "experience who battled some foot\l"
	.string "soldiers and Garbador are supposedly\l"
	.string "tactical masterminds?$"

gText_SurvivalChance333_HeyWeDidntAsk::
	.string "Hey, we didn't ask to be here!$"

gText_SurvivalChance333_AndIDidntAsk::
	.string "And I didn't ask for you. But here we\n"
	.string "are.$"

gText_SurvivalChance333_IllProveIt::
	.string "I'll prove it then. Battle me.$"

gText_SurvivalChance333_WontEvenBeAFair::
	.string "Won't even be a fair fight. I could take\n"
	.string "both of you at the same time, with my\l"
	.string "eyes closed.$"

gText_SurvivalChance333_Hmph::
	.string "Hmph!$"

gText_SurvivalChance333_DoYouGetItNow::
	.string "Do you get it now? We're the real deal.$"

gText_SurvivalChance333_YoureAPairOfKids::
	.string "…look. You're a pair of kids that are in\n"
	.string "way over your heads, with absolutely no\l"
	.string "place in a police raid. But I'm stuck\l"
	.string "with you, and you're both obviously\l"
	.string "tough as all hell. Let's make the most\l"
	.string "of it.$"

gText_SurvivalChance333_SoThatsThePlan::
	.string "So that's the plan. Any questions?$"

gText_SurvivalChance333_OneProblemForUs::
	.string "One problem for us.$"

gText_SurvivalChance333_HereWeGo::
	.string "Here we go… what?$"

gText_SurvivalChance333_IKnowWereSupposed::
	.string "I know we're supposed to blast the\n"
	.string "walls to drive out the TeamRocket\l"
	.string "members, but {PLAYER} and I don't\l"
	.string "have the Self-Destruct TM.$"

gText_SurvivalChance333_OhHellThatsRight::
	.string "Oh hell, that's right. Not your fault.\n"
	.string "Marcus, Phillip, give ‘em yours.$"

gText_SurvivalChance333_IAlwaysForget::
	.string "I always forget - we took those out of\n"
	.string "circulation in SanFran a few years ago.\l"
	.string "Criminals were using them for too many\l"
	.string "smash and grabs, so now they're for\l"
	.string "police use only. Any other questions?$"

gText_SurvivalChance333_NoSir::
	.string "NO sir.$"

gText_SurvivalChance333_LetsGetThisParty::
	.string "Let's get this party started.$"

gText_SurvivalChance333_ThoseRoutesFrozen::
	.string "Those routes frozen over seals off a\n"
	.string "water escape…$"

gText_SurvivalChance333_MeltingTheBedrock::
	.string "Melting the bedrock prevents an\n"
	.string "underground escape…$"

gText_SurvivalChance333_TheyllBlowTheWall::
	.string "They'll blow the wall, and we'll dive in!$"

gText_SurvivalChance333_Showtime::
	.string "Showtime!$"
