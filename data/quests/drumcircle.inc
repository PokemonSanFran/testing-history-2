Quest_DrumCircle_Interact_Event_Script::
	lock
	faceplayer
	returnqueststate QUEST_DRUMCIRCLE
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_DrumCircle_Interact_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_DrumCircle_Interact_Event_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_DrumCircle_Interact_Event_Script_4
	goto Quest_DrumCircle_ExplainQuest_Dialogue
	return

Quest_DrumCircle_Interact_Event_Script_2:
	goto Quest_DrumCircle_ActiveDialogue
	return

Quest_DrumCircle_Interact_Event_Script_3:
	goto Quest_DrumCircle_RewardCutscene
	return

Quest_DrumCircle_Interact_Event_Script_4:
	goto Quest_DrumCircle_CheckVenueCompletion_Script
	return


Quest_DrumCircle_ExplainQuest_Dialogue::
	msgbox gText_DrumCircle_YoureATrainerWantAChallenge, , SPEAKER_TONALLI
	msgbox gText_DrumCircle_BattleAllOfUs, , SPEAKER_DRUMMER_B
	msgbox gText_DrumCircle_IfYouWin, , SPEAKER_DRUMMER_C
	msgbox gText_DrumCircle_IfYouLose, , SPEAKER_DRUMMER_D
	msgbox gText_DrumCircle_WhatDoYouSay, MSGBOX_YESNO, SPEAKER_TONALLI
	compare VAR_RESULT, YES
	goto_if_eq Quest_DrumCircle_ExplainQuest_Dialogue_1
	goto Quest_DrumCircle_DeclineQuest_Dialogue
	return

Quest_DrumCircle_ExplainQuest_Dialogue_1:
	goto Quest_DrumCircle_StartQuest_Dialogue
	return


Quest_DrumCircle_DeclineQuest_Dialogue::
	msgbox gText_DrumCircle_HehNotReady, , SPEAKER_TONALLI
	release
	end


Quest_DrumCircle_StartQuest_Dialogue::
	msgbox gText_DrumCircle_ThatsWhatImTalking, , SPEAKER_TONALLI
	startquest QUEST_DRUMCIRCLE
	goto Quest_DrumCircle_ActiveDialogue
	return


Quest_DrumCircle_ActiveDialogue::
	msgbox gText_DrumCircle_WantAHeal, MSGBOX_YESNO, SPEAKER_TONALLI
	compare VAR_RESULT, YES
	goto_if_eq Quest_DrumCircle_ActiveDialogue_2
Quest_DrumCircle_ActiveDialogue_1:
	goto Quest_DrumCircle_BattleA_Script
	return

Quest_DrumCircle_ActiveDialogue_2:
	special HealPlayerParty
	goto Quest_DrumCircle_ActiveDialogue_1


Quest_DrumCircle_BattleA_Script::
	applymovement 23, Quest_DrumCircle_HopFace_Movement
	playse SE_BIKE_HOP
	waitse
	waitmovement 23
	closemessage
	msgbox gText_DrumCircle_MyTurn, , SPEAKER_DRUMMER_D
	trainerbattle_no_intro TRAINER_DUSTY_2, gText_DrumCircle_OhNo
	goto Quest_DrumCircle_BattleB_Script
	return


Quest_DrumCircle_BattleB_Script::
	applymovement 24, Quest_DrumCircle_HopFace_Movement
	playse SE_BIKE_HOP
	waitse
	waitmovement 24
	closemessage
	msgbox gText_DrumCircle_MyTurn, , SPEAKER_DRUMMER_C
	trainerbattle_no_intro TRAINER_DUSTY_3, gText_DrumCircle_OhNo
	goto Quest_DrumCircle_BattleC_Script
	return


Quest_DrumCircle_BattleC_Script::
	applymovement 25, Quest_DrumCircle_HopFace_Movement
	playse SE_BIKE_HOP
	waitse
	waitmovement 25
	closemessage
	msgbox gText_DrumCircle_MyTurn, , SPEAKER_DRUMMER_B
	trainerbattle_no_intro TRAINER_DUSTY_4, gText_DrumCircle_OhNo
	goto Quest_DrumCircle_BattleD_Script
	return


Quest_DrumCircle_BattleD_Script::
	applymovement 26, Quest_DrumCircle_HopFace_Movement
	playse SE_BIKE_HOP
	waitse
	waitmovement 26
	closemessage
	msgbox gText_DrumCircle_MyTurn, , SPEAKER_TONALLI
	trainerbattle_no_intro TRAINER_DUSTY_5, gText_DrumCircle_OhNo
	goto Quest_DrumCircle_RewardCutscene
	return


Quest_DrumCircle_RewardCutscene::
	msgbox gText_DrumCircle_YoureNoJoke, , SPEAKER_DRUMMER_B
	msgbox gText_DrumCircle_WayToGoIdiot, , SPEAKER_DRUMMER_D
	msgbox gText_DrumCircle_DudeIsntThat, , SPEAKER_DRUMMER_C
	msgbox gText_DrumCircle_HowWasISupposed, , SPEAKER_TONALLI
	msgbox gText_DrumCircle_ThatWasOneOfAKind, , SPEAKER_DRUMMER_D
	msgbox gText_DrumCircle_IgnoreThemYouWon, , SPEAKER_TONALLI
	giveitem ITEM_OLD_GATEAU, 1
	msgbox gText_DrumCircle_ComeBackSoWeCanWin, , SPEAKER_TONALLI
	completequest QUEST_DRUMCIRCLE
	release
	end


Quest_DrumCircle_CheckVenueCompletion_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_LASTMUSICVENUEINSANFRANCISCO
	compare VAR_RESULT, 0
	goto_if_ne Quest_DrumCircle_CheckVenueCompletion_Script_1
	goto Quest_DrumCircle_Completed_NoVenue_Dialogue
	return

Quest_DrumCircle_CheckVenueCompletion_Script_1:
	goto Quest_LastMusicVenue_InformDrummers_Dialogue
	return


Quest_DrumCircle_Completed_NoVenue_Dialogue::
	msgbox gText_DrumCircle_YouGuysAreDrummers, , SPEAKER_ZOEY
	msgbox gText_DrumCircle_WeLostOurVenue, , SPEAKER_TONALLI
	msgbox gText_DrumCircle_MakingEnds, , SPEAKER_TONALLI
	closemessage
	release
	end


Quest_DrumCircle_HopFace_Movement:
	face_player
	lock_facing_direction
	jump_in_place_up
	jump_in_place_up
	step_end

gText_DrumCircle_YoureATrainerWantAChallenge::
	.string "youre a trainer, want a challenge?$"

gText_DrumCircle_BattleAllOfUs::
	.string "battle all of us back to back, no\n"
	.string "healing at all$"

gText_DrumCircle_IfYouWin::
	.string "if you win, you get a super rare prize$"

gText_DrumCircle_IfYouLose::
	.string "if you lose, you gotta fork over double\n"
	.string "the prize money$"

gText_DrumCircle_WhatDoYouSay::
	.string "sound good?$"

gText_DrumCircle_HehNotReady::
	.string "not ready for all that? i get it.$"

gText_DrumCircle_ThatsWhatImTalking::
	.string "that's what I'm talking about!$"

gText_DrumCircle_WantAHeal::
	.string "wanna heal before we get started?$"

gText_DrumCircle_MyTurn::
	.string "my turn!$"

gText_DrumCircle_OhNo::
	.string "oh no!$"

gText_DrumCircle_YoureNoJoke::
	.string "you're no joke$"

gText_DrumCircle_WayToGoIdiot::
	.string "way to go idiot!$"

gText_DrumCircle_DudeIsntThat::
	.string "dude isn't that {PLAYER}$"

gText_DrumCircle_HowWasISupposed::
	.string "how was I supposed to know it was them$"

gText_DrumCircle_ThatWasOneOfAKind::
	.string "that was one of a kind! mom is gonna kill\n"
	.string "us.$"

gText_DrumCircle_IgnoreThemYouWon::
	.string "look, ignore them. you won fair and\n"
	.string "square, take this.$"

gText_DrumCircle_ComeBackSoWeCanWin::
	.string "come challenge us again somebody so we\n"
	.string "can win it back!$"

gText_DrumCircle_YouGuysAreDrummers::
	.string "you guys are drummers, right? why are\n"
	.string "you doing high stakes battles?$"

gText_DrumCircle_WeLostOurVenue::
	.string "we used to play around the Gym. Pryce\n"
	.string "was cool with us and we got paid as\l"
	.string "performers and everything. when the\l"
	.string "league came in, they kicked us out and\l"
	.string "all the local venues are getting bought\l"
	.string "up by the league to become arenas$"

gText_DrumCircle_MakingEnds::
	.string "making ends meet without a venue has\n"
	.string "been tough, so we had to get creative!\l"
	.string "and it was working until you showed\l"
	.string "up...$"
