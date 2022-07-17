Battle8_SetUpObject_Script::
	setflag FLAG_TEMP_1
	return


Battle8_StartBattle_ObjectSetUp_Script::
	setobjectxyperm 1, 19, 16
	setobjectxy 1, 19, 16
	return


Battle8_ArcherWalksOut_Script::
	lock
	addvar VAR_ROUTE109_STATE, 1
	opendoor 19, 13
	waitdooranim
	clearflag FLAG_TEMP_1
	addobject 1
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	applymovement 1, Battle8_WalkOutOfHouse
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 26
	goto_if_ne Battle8_ArcherWalksOut_Script_2
Battle8_ArcherWalksOut_Script_1:
	waitmovement 0
	closedoor 19, 13
	waitdooranim
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Battle8_HellYesSRank
	closemessage
	callnative ClearMugshot
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	goto Battle8_ExplainAttraction_Dialogue
	return

Battle8_ArcherWalksOut_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Battle8_GetOutOfWay
	goto Battle8_ArcherWalksOut_Script_1


Battle8_ExplainAttraction_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Battle8_YouKnowIWasInGoodMood
	compare VAR_TEMP_0, 26
	goto_if_eq Battle8_ExplainAttraction_Dialogue_2
Battle8_ExplainAttraction_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Battle8_GreatToSeeYouToo
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Battle8_PrimaryAttraction
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Battle8_SoWhatsTheChallenge
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Battle8_TheSistersAreExperts
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto Battle8_StartBattle_Script
	return

Battle8_ExplainAttraction_Dialogue_2:
	closemessage
	callnative ClearMugshot
	applymovement 1, Battle8_WalkToPlayer
	waitmovement 0
	goto Battle8_ExplainAttraction_Dialogue_1


Battle8_StartBattle_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Battle8_YouTalkALot
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_WALLY_VR_3, gText_Battle8_MaybeINeed
	goto Battle8_ArcherDefeated_Dialogue
	return


Battle8_InteractBattle_Script::
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Battle8_YouTalkALot, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_WALLY_VR_3, gText_Battle8_MaybeINeed
	goto Battle8_ArcherDefeated_Dialogue
	return


Battle8_ArcherDefeated_Dialogue::
	lock
	addvar VAR_ROUTE109_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Battle8_YouKnowItDoesnt
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Battle8_YeahThatsPart
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Battle8_WhatSituation
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Battle8_NotJustLikeMe
	closemessage
	callnative ClearMugshot
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 18
	goto_if_eq Battle8_ArcherDefeated_Dialogue_2
Battle8_ArcherDefeated_Dialogue_1:
	applymovement 1, Battle8_WalkToTheWest
	waitmovement 0
	removeobject 1
	fadedefaultbgm
	release
	end

Battle8_ArcherDefeated_Dialogue_2:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	goto Battle8_ArcherDefeated_Dialogue_1


Battle8_WalkOutOfHouse:
	walk_down
	step_end

Battle8_GetOutOfWay:
	walk_right
	step_end

Battle8_WalkToPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Battle8_WalkToTheWest:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

gText_Battle8_HellYesSRank::
	.string "Hell yes, S Rank, I nailed that!$"

gText_Battle8_YouKnowIWasInGoodMood::
	.string "You know, I was in a good mood, and now\n"
	.string "all of a sudden…$"

gText_Battle8_GreatToSeeYouToo::
	.string "Great to see you too. What rank thing\n"
	.string "were you talking about?$"

gText_Battle8_PrimaryAttraction::
	.string "Primary attraction of FishermansWharf\n"
	.string "- the Seven Sisters Challenge. It used\l"
	.string "to be a lot more popular when 1v1\l"
	.string "battles were a novelty- before the\l"
	.string "corporations declared it as the\l"
	.string "official League format.$"

gText_Battle8_SoWhatsTheChallenge::
	.string "So, what's the challenge? And how do\n"
	.string "you get an S Rank?$"

gText_Battle8_TheSistersAreExperts::
	.string "The sisters are experts in 1v1, and\n"
	.string "you've got to beat all of them, in a row,\l"
	.string "in as few turns as possible. I've heard\l"
	.string "a rumor that Drasna got an SS Rank\l"
	.string "once, but those guys are on a\l"
	.string "different level… but you're not even\l"
	.string "close to that.$"

gText_Battle8_YouTalkALot::
	.string "You talk a lot of shit for somebody\n"
	.string "that's never beaten me.$"

gText_Battle8_MaybeINeed::
	.string "Maybe I need to get an SS Rank to keep\n"
	.string "up with you…$"

gText_Battle8_YouKnowItDoesnt::
	.string "You know, it doesn't have to be like\n"
	.string "this. I'm not out to get you.$"

gText_Battle8_YeahThatsPart::
	.string "Yeah, that's part of the problem. Your\n"
	.string "ignorance of the situation and your\l"
	.string "skill almost makes it worse.$"

gText_Battle8_WhatSituation::
	.string "What situation? I'm just doing the Gym\n"
	.string "Challenge. Just like you.$"

gText_Battle8_NotJustLikeMe::
	.string "Not just like me. Nothing like me. I'm\n"
	.string "going to be better than you cheaters,\l"
	.string "no question.$"
