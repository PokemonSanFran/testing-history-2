ExhibitionBattle_HideObject_Script::
	setflag FLAG_TEMP_3
	return


ExhibitionBattle_TimeSkip_Script::
	compare VAR_STORYLINE_STATE, 48
	goto_if_eq ExhibitionBattle_TimeSkip_Script_1
	return

ExhibitionBattle_TimeSkip_Script_1:
	special HealPlayerParty
	fadescreen FADE_TO_BLACK
	msgbox gText_ExhibitionBattle_TimeSkip, MSGBOX_AUTOCLOSE
	warpsilent MAP_PSFPLACE14_SKYBOX, 10, 3
	return


ExhibitionBattle_PrepPlayer_Script::
	lock
	addvar VAR_STORYLINE_STATE, 1
	applymovement 5, WaitHeDidWhat_EncouragePlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_OkayTime, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ExhibitionBattle_PrepPlayer_Script_2
	callnative ClearMugshot
	fadescreen FADE_TO_BLACK
	msgbox gText_ExhibitionBattle_AndNow, MSGBOX_AUTOCLOSE
	warpsilent MAP_PSFPLACE14_ARENA, 1
	return

ExhibitionBattle_PrepPlayer_Script_2:
	msgbox gText_ExhibitionBattle_NervousStill, MSGBOX_AUTOCLOSE
	callnative ClearMugshot
	end


ExhibitionBattle_MoveFromDoor_Script::
	lock
	faceplayer
	msgbox gText_ExhibitionBattle_ForYourExhibition, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq ExhibitionBattle_MoveFromDoor_Script_2
ExhibitionBattle_MoveFromDoor_Script_1:
	release
	end

ExhibitionBattle_MoveFromDoor_Script_2:
	call GroupStages_MoveObjects_Script
	warpsilent MAP_PSFPLACE14_ARENA, 1
	goto ExhibitionBattle_MoveFromDoor_Script_1


ExhibitionBattle_SetChampionName_Script::
	random 2
	compare VAR_RESULT, 1
	goto_if_eq ExhibitionBattle_SetChampionName_Script_1
	bufferstring STR_VAR_3, ExhibitionBattle_SetChampionName_Script_Text_1
	return

ExhibitionBattle_SetChampionName_Script_1:
	bufferstring STR_VAR_3, ExhibitionBattle_SetChampionName_Script_Text_0
	return


ExhibitionBattle_BattleDiantha_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, WaitHeDidWhat_WalkToBattlefieldPosition
	waitmovement 0
	msgbox gText_ExhibitionBattle_CanTheGrand, MSGBOX_AUTOCLOSE
	applymovement 1, Common_Movement_WalkLeft
	waitmovement 0
	call ExhibitionBattle_SetChampionName_Script
	trainerbattle_continue_after_lose TRAINER_WALLACE, gText_ExhibitionBattle_Incredible
	special HealPlayerParty
	msgbox gText_ExhibitionBattle_WhatAnAmazing, MSGBOX_AUTOCLOSE
	addvar VAR_STORYLINE_STATE, 1
	warpsilent MAP_PSFPLACE14_LOCKERS, 255, 9, 5
	return


ExhibitionBattle_PostBattle_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_ThatWasPositively
	checktrainerflag TRAINER_WALLACE
	goto_if 0, ExhibitionBattle_PostBattle_Dialogue_2
ExhibitionBattle_PostBattle_Dialogue_1:
	msgbox gText_ExhibitionBattle_ImConvinced
	callnative ClearMugshot
	closemessage
	release
	end

ExhibitionBattle_PostBattle_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_IveNeverSeen
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	goto ExhibitionBattle_PostBattle_Dialogue_1


ExhibitionBattle_Psftransrival_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	compare VAR_TEMP_F, 0
	goto_if_gt ExhibitionBattle_Psftransrival_Dialogue_2
	setvar VAR_TEMP_F, 1
	msgbox gText_ExhibitionBattle_SickBattleOut
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_YeahIHeardALittle
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_ImHeadingUpTheir
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_IsntThat
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_IveBeenWorkignWith
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_IThinkYoureGonna
	return

ExhibitionBattle_Psftransrival_Dialogue_2:
	msgbox gText_ExhibitionBattle_IWonderIfThat
	return


ExhibitionBattle_Psfbadadmin3_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_IDidntSeeYour, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_UhhThanks
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_YourWorkDismantling
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_ImHappy
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_WithTheirEntireLeadership
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_WaitTheEliteFour
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_NotReallyItsASlight
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExhibitionBattle_NowUhYoureWelcome
	callnative ClearMugshot
	closemessage
	release
	end


ExhibitionBattle_FalseCredits_Script::
	lock
	fadescreen FADE_TO_BLACK
	call Common_EventScript_SaveGame
	msgbox ExhibitionBattle_FalseCredits_Script_Text_0, MSGBOX_AUTOCLOSE
	release
	closemessage
	warpsilent MAP_PSFROUTE22, 2
	return


ExhibitionBattle_SetChampionName_Script_Text_0:
	.string "Serena$"

ExhibitionBattle_SetChampionName_Script_Text_1:
	.string "Calem$"

ExhibitionBattle_FalseCredits_Script_Text_0:
	.string "False credits roll. The....End?$"

gText_ExhibitionBattle_TimeSkip::
	.string "A few weeks later...$"

gText_ExhibitionBattle_OkayTime::
	.string "Okay, time for your exhibition battle.\n"
	.string "Winning or losing doesn't matter… just\l"
	.string "give us a good show! Are you ready?$"

gText_ExhibitionBattle_NervousStill::
	.string "Nervous still? No worries. Just head\n"
	.string "into the stadium when you're ready.$"

gText_ExhibitionBattle_AndNow::
	.string "And now, the Psfregion1 Champion….\n"
	.string "{PLAYER}!!!$"

gText_ExhibitionBattle_CanTheGrand::
	.string "Can the Grand Duchess hold a candle to\n"
	.string "our superstar? Let's get the\l"
	.string "exhibition underway!$"

gText_ExhibitionBattle_Incredible::
	.string "Incredible! You remind me of\n"
	.string "{STR_VAR_3}… So fierce.$"

gText_ExhibitionBattle_Serena::
	.string "Serena$"

gText_ExhibitionBattle_Calem::
	.string "Calem$"

gText_ExhibitionBattle_WhatAnAmazing::
	.string "What an amazing show of skill from\n"
	.string "these elite Trainers! I'm so fired up\l"
	.string "for this League season, are you all\l"
	.string "ready?$"

gText_ExhibitionBattle_ThatWasPositively::
	.string "That was positively electric! Your best\n"
	.string "battle yet! Incredible! I couldn't have\l"
	.string "asked for a better kickoff.$"

gText_ExhibitionBattle_IveNeverSeen::
	.string "(I've never seen anybody so excited to\n"
	.string "see me lose!)$"

gText_ExhibitionBattle_ImConvinced::
	.string "I'm convinced. This is going to be the\n"
	.string "best League season ever. The sponsors\l"
	.string "are excited, we've got a villain as the\l"
	.string "reigning Champion, viewership is at an\l"
	.string "all-time high, and we're going to make\l"
	.string "it big! *sniff* I'm getting emotional.\l"
	.string "You've done excellently, {PLAYER}.$"

gText_ExhibitionBattle_SickBattleOut::
	.string "Sick battle out there. I'm hoping my\n"
	.string "facilities are as hype as that.$"

gText_ExhibitionBattle_YeahIHeardALittle::
	.string "Yeah, I heard a little bit of that; what\n"
	.string "are you working on now?$"

gText_ExhibitionBattle_ImHeadingUpTheir::
	.string "I'm heading up their community outreach\n"
	.string "program. We're going to set up a bunch\l"
	.string "of Battle Facilities all around the\l"
	.string "region.$"

gText_ExhibitionBattle_IsntThat::
	.string "(Isn't that…)$"

gText_ExhibitionBattle_IveBeenWorkignWith::
	.string "I've been working with a developer who\n"
	.string "thinks we can convert some of the\l"
	.string "low-income housing into those\l"
	.string "facilities, meaning they'll be\l"
	.string "accessible all over the region! I can't\l"
	.string "wait to build more opportunities for\l"
	.string "Trainers. Being the Champion would\l"
	.string "have been cool, but this gig is amazing\l"
	.string "too.$"

gText_ExhibitionBattle_IThinkYoureGonna::
	.string "I think you're gonna do great.$"

gText_ExhibitionBattle_IWonderIfThat::
	.string "I wonder if that development in\n"
	.string "Psfcity7 has been committed yet…$"

gText_ExhibitionBattle_IDidntSeeYour::
	.string "I didn't see your match, but the\n"
	.string "dashboards show me that people were\l"
	.string "very excited.$"

gText_ExhibitionBattle_UhhThanks::
	.string "…uhh, thanks?$"

gText_ExhibitionBattle_YourWorkDismantling::
	.string "Your work dismantling Psfgoodteam was\n"
	.string "excellent, by the way.$"

gText_ExhibitionBattle_ImHappy::
	.string "I'm happy I was able to help!$"

gText_ExhibitionBattle_WithTheirEntireLeadership::
	.string "With their entire leadership core in\n"
	.string "custody, we now basically control the\l"
	.string "narrative around them. We're planning a\l"
	.string "campaign to show the people of the\l"
	.string "region the true dangers of collective\l"
	.string "organizations like Psfgoodteam and\l"
	.string "the Elite Four.$"

gText_ExhibitionBattle_WaitTheEliteFour::
	.string "Wait, the Elite Four has a whole\n"
	.string "organization?$"

gText_ExhibitionBattle_NotReallyItsASlight::
	.string "Not really. It's a slight\n"
	.string "reinterpretation of reality, but the\l"
	.string "message is for the greater good! We're\l"
	.string "going to make a huge difference in\l"
	.string "shutting down copycat groups, and it's\l"
	.string "all thanks to your work.$"

gText_ExhibitionBattle_NowUhYoureWelcome::
	.string "Wow uh, you're welcome.$"

gText_ExhibitionBattle_ForYourExhibition::
	.string "Are you ready for your exhibition?$"
