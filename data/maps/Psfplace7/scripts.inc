Psfplace7_MapScripts::
	.byte 0


OldAssholeAppears_PsftransrivalWalkToPlayer::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 12
	goto_if_eq OldAssholeAppears_PsftransrivalWalkToPlayer_2
	applymovement OBJ_EVENT_ID_PLAYER, OldAssholeAppears_WalkWesttoPsftransrival_Movement
OldAssholeAppears_PsftransrivalWalkToPlayer_1:
	waitmovement 0
	goto PsftransrivalAlpha_Event_Script
	return

OldAssholeAppears_PsftransrivalWalkToPlayer_2:
	applymovement OBJ_EVENT_ID_PLAYER, OldAssholeAppears_WalkNorthtoPsftransrival_Movement
	goto OldAssholeAppears_PsftransrivalWalkToPlayer_1


PsftransrivalAlpha_Event_Script::
	switch VAR_NATIVETRANSALPHA_STATE
	case 0, PsftransrivalAlpha_Event_Script_2
	case 1, PsftransrivalAlpha_Event_Script_3
	return

PsftransrivalAlpha_Event_Script_2:
	goto OldAssholeAppears_Intro_Dialogue
	return

PsftransrivalAlpha_Event_Script_3:
	goto OldAssholeAppears_StartBattle_Script
	return


OldAssholeAppears_Intro_Dialogue::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	applymovement 1, Common_Movement_FaceDown
	msgbox gText_OldAssholeAppears_StandingOnVolcano
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_ImSorryWhat
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_RegionCloseFaultline
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_DontKnowMagical
	callnative ClearMugshot
	goto OldAssholeAppears_HealPlayer_Dialogue
	return


OldAssholeAppears_HealPlayer_Dialogue::
	setvar VAR_NATIVETRANSALPHA_STATE, 1
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_IllHealYou
	playse SE_USE_ITEM
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_OhUhThanks
	special HealPlayerParty
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_DaddyShippedFullRestores
	callnative ClearMugshot
	setvar VAR_PSFPLACE7_STATE, 1
	call Common_EventScript_SaveGame
	closemessage
	goto OldAssholeAppears_StartBattle_Script
	return


OldAssholeAppears_ResumeBattle_Script::
	faceplayer
	goto OldAssholeAppears_StartBattle_Script
	return


OldAssholeAppears_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_HowFarBehind, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	givecustommon SPECIES_BLASTOISE, 100, ITEM_BLASTOISINITE, ITEM_QUICK_BALL, NATURE_TIMID, , , 4, , 252, , 252, 31, 31, 31, 31, 31, 31, MOVE_RAPID_SPIN, MOVE_DARK_PULSE, MOVE_AURA_SPHERE, MOVE_ICE_BEAM
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, gText_PsftransrivalAlpha_HumanWin
	goto OldAssholeAppears_GiveCorviknightCard_Script
	return


OldAssholeAppears_GiveCorviknightCard_Script::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_TakingThisAllSeriously
	callnative ClearMugshot
	giveitem ITEM_SS_TICKET
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	callnative ClearMugshot
	msgbox gText_OldAssholeAppears_FamiliarwithPsfcompany5, MSGBOX_YESNO
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	compare VAR_RESULT, 1
	goto_if_eq OldAssholeAppears_GiveCorviknightCard_Script_2
	msgbox gText_OldAssholeAppears_LetsYouCallARide
OldAssholeAppears_GiveCorviknightCard_Script_1:
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_LetsYouUsePsfcompany5ForFree
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_YouveBeenSuperNice
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_NowWereEven
	callnative ClearMugshot
	closemessage
	goto OldAssholeAppears_PsftransrivalExit_Script
	return

OldAssholeAppears_GiveCorviknightCard_Script_2:
	msgbox gText_OldAssholeAppears_ThoughtSo
	goto OldAssholeAppears_GiveCorviknightCard_Script_1


OldAssholeAppears_PsftransrivalExit_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	applymovement 1, OldAssholeAppears_PsftransrivalExit_Movement
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	releaseall
	end


OldAssholeAppears_WalkNorthtoPsftransrival_Movement:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_up
	step_end

OldAssholeAppears_WalkWesttoPsftransrival_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

OldAssholeAppears_PsftransrivalExit_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

gText_OldAssholeAppears_StandingOnVolcano::
	.string "You know, we're probably standing on a\n"
	.string "volcano, {PLAYER}.$"

gText_OldAssholeAppears_ImSorryWhat::
	.string "I'm sorry, what?$"

gText_OldAssholeAppears_RegionCloseFaultline::
	.string "Or, what used to be one at least. Turns\n"
	.string "out this region is close to a tectonic\l"
	.string "faultline, which when they shift, make\l"
	.string "a bunch of tiny volcanoes, all over the\l"
	.string "place. It's kind of magical when you\l"
	.string "think about it, huh?$"

gText_OldAssholeAppears_DontKnowMagical::
	.string "I don't know about magical, but it's\n"
	.string "pretty neat, yeah!$"

gText_OldAssholeAppears_IllHealYou::
	.string "Tell you what - I do have something\n"
	.string "magical for you, but you'll have to beat\l"
	.string "me for it first! Here, I'll heal your\l"
	.string "Pokémon for you.$"

gText_OldAssholeAppears_OhUhThanks::
	.string "Oh uh, thanks!$"

gText_OldAssholeAppears_DaddyShippedFullRestores::
	.string "Not me, Daddy shipped over those Full\n"
	.string "Restores.$"

gText_OldAssholeAppears_HowFarBehind::
	.string "Now, let's see how far behind you are!$"

gText_PsftransrivalAlpha_HumanWin::
	.string "I'm starting to question all those\n"
	.string "years at the private battle academy...$"

gText_OldAssholeAppears_TakingThisAllSeriously::
	.string "Good to see you're taking this all\n"
	.string "seriously, {PLAYER}! My rival should\l"
	.string "be strong to keep me sharp! Well, true\l"
	.string "to my word...$"

gText_OldAssholeAppears_FamiliarwithPsfcompany5::
	.string "Are you familiar with Psfcompany5?$"

gText_OldAssholeAppears_ThoughtSo::
	.string "Thought so. They're everywhere, right?$"

gText_OldAssholeAppears_LetsYouCallARide::
	.string "Don't have it in Orre? Psfcompany5 lets\n"
	.string "you call a ride from anywhere to\l"
	.string "anywhere else that you've been.$"

gText_OldAssholeAppears_LetsYouUsePsfcompany5ForFree::
	.string "That card lets you use Psfcompany5 for\n"
	.string "free! I went to the Psfbadguy1tower,\l"
	.string "and the League Commissioner gave me\l"
	.string "these for being the first Challenger to\l"
	.string "visit! It also lets you use the Subway\l"
	.string "System for free, but I think I'll stick\l"
	.string "to Psfcompany5. Less homeless people\l"
	.string "to deal with, you know?$"

gText_OldAssholeAppears_YouveBeenSuperNice::
	.string "Thanks! You've been super nice today!$"

gText_OldAssholeAppears_NowWereEven::
	.string "Now we're even after I ditched\n"
	.string "breakfast. All right, time to go\l"
	.string "challenge the Psfplace9 Gym. So glad\l"
	.string "Daddy sent me these Go-Goggles!$"