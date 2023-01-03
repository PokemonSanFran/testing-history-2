Chasecenter_Lockers_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Chasecenter_Lockers_MapScripts_OnTransition
	return

Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_LOAD:
	return

Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_START_CHAMPIONSHIP, HeresHowThisIsGoingToGo_VirtualObjectSetUp_Script
	map_script_2 VAR_STORYLINE_STATE, STORY_CHAMPIONSHIP_EXPLAINED, HeresHowThisIsGoingToGo_CleanUpVObjects_Script
	.2byte 0

Chasecenter_Lockers_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_START_CHAMPIONSHIP, HeresHowThisIsGoingToGo_ExplainLeagueDialogue
	map_script_2 VAR_STORYLINE_STATE, STORY_BIANCA_WON_GROUP, GroupStages_GreetBeforeStart_Dialogue
	map_script_2 VAR_STORYLINE_STATE, STORY_SEMIFINAL_COMPLETE, WaitHeDidWhat_RivalsGoToMatch_Script
	map_script_2 VAR_STORYLINE_STATE, STORY_POST_DIANTHA, ExhibitionBattle_PostBattle_Dialogue
	.2byte 0


Chasecenter_Lockers_MapScripts_OnTransition::
	switch VAR_STORYLINE_STATE
	case STORY_START_CHAMPIONSHIP, Chasecenter_Lockers_MapScripts_OnTransition_2
	case STORY_CHAMPIONSHIP_EXPLAINED, Chasecenter_Lockers_MapScripts_OnTransition_3
	case STORY_BIANCA_WON_GROUP, Chasecenter_Lockers_MapScripts_OnTransition_4
	case STORY_READY_GROUP_STAGE, Chasecenter_Lockers_MapScripts_OnTransition_5
	case STORY_GROUP_STATE_COMPLETE, Chasecenter_Lockers_MapScripts_OnTransition_6
	case STORY_SEMIFINAL_COMPLETE, Chasecenter_Lockers_MapScripts_OnTransition_7
	case STORY_WATCH_SEMIFINAL, Chasecenter_Lockers_MapScripts_OnTransition_8
	case STORY_READY_FINALS, Chasecenter_Lockers_MapScripts_OnTransition_9
	case STORY_SAVE_FINALS, Chasecenter_Lockers_MapScripts_OnTransition_10
	case STORY_POST_DIANTHA, Chasecenter_Lockers_MapScripts_OnTransition_11
	case STORY_CONGRATULATED_BY_ROSE, Chasecenter_Lockers_MapScripts_OnTransition_12
	call WaitHeDidWhat_ObjectMidSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_2:
	call HeresHowThisIsGoingToGo_ObjectSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_3:
	call HeresHowThisIsGoingToGo_ShowArcherandBianca
	return

Chasecenter_Lockers_MapScripts_OnTransition_4:
	call GroupStages_Lockers_ObjectSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_5:
	call GroupStages_Lockers_ObjectCleanUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_6:
	call Finals_HideObject_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_7:
	call WaitHeDidWhat_ObjectSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_8:
	call WaitHeDidWhat_ObjectMidSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_9:
	call WaitHeDidWhat_MeltdownSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_10:
	call WaitHeDidWhat_MeltdownPostSaveSetUp_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_11:
	call ExhibitionBattle_HideObject_Script
	return

Chasecenter_Lockers_MapScripts_OnTransition_12:
	call ExhibitionBattle_HideObject_Script
	return


Chasecenter_Lockers_Bianca_Event_Script::
	lock
	faceplayer
	switch VAR_STORYLINE_STATE
	case STORY_READY_FINALS, Chasecenter_Lockers_Bianca_Event_Script_3
	case STORY_CONGRATULATED_BY_ROSE, Chasecenter_Lockers_Bianca_Event_Script_4
Chasecenter_Lockers_Bianca_Event_Script_1:
	closemessage
	callnative ClearMugshot
	release
	end

Chasecenter_Lockers_Bianca_Event_Script_3:
	call WaitHeDidWhat_BiancaMeltdown_Dialogue
	goto Chasecenter_Lockers_Bianca_Event_Script_1

Chasecenter_Lockers_Bianca_Event_Script_4:
	call ExhibitionBattle_Bianca_Dialogue
	goto Chasecenter_Lockers_Bianca_Event_Script_1


Chasecenter_Lockers_InteractArenaGuard_Script::
	lock
	faceplayer
	switch VAR_CHASECENTER_TOURNAMENT_STATE
	case PRE_BATTLE_1, Chasecenter_Lockers_InteractArenaGuard_Script_3
	case PRE_BATTLE_4, Chasecenter_Lockers_InteractArenaGuard_Script_4
	case PRE_BATTLE_5, Chasecenter_Lockers_InteractArenaGuard_Script_5
Chasecenter_Lockers_InteractArenaGuard_Script_1:
	switch VAR_STORYLINE_STATE
	case STORY_SAVE_DIANTHA, Chasecenter_Lockers_InteractArenaGuard_Script_7
	return

Chasecenter_Lockers_InteractArenaGuard_Script_3:
	goto GroupStages_PreparePlayer_Script
	goto Chasecenter_Lockers_InteractArenaGuard_Script_1

Chasecenter_Lockers_InteractArenaGuard_Script_4:
	goto Finals_PreparePlayer_Script
	goto Chasecenter_Lockers_InteractArenaGuard_Script_1

Chasecenter_Lockers_InteractArenaGuard_Script_5:
	goto WaitHeDidWhat_PreparePlayer_Script
	goto Chasecenter_Lockers_InteractArenaGuard_Script_1

Chasecenter_Lockers_InteractArenaGuard_Script_7:
	goto ExhibitionBattle_MoveFromDoor_Script
	return


Chasecenter_Lockers_Information_Script::
	lock
	msgbox gText_Chasecenter_Lockers_WHatWouldYouLike, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Chasecenter_Lockers_Information_Script_1
	goto Chasecenter_Lockers_TournamentRules_Dialgoue
	return

Chasecenter_Lockers_Information_Script_1:
	goto BattleFrontier_BattleDomeLobby_EventScript_ShowPrevTourneyTree
	return


Chasecenter_Lockers_TournamentRules_Dialgoue::
	fadescreen FADE_TO_BLACK
	compare VAR_CHASECENTER_TOURNAMENT_STATE, PRE_BATTLE_4
	goto_if_lt Chasecenter_Lockers_TournamentRules_Dialgoue_2
Chasecenter_Lockers_TournamentRules_Dialgoue_1:
	msgbox gText_Chasecenter_Lockers_Information_InTheFinalStage
	closemessage
	fadescreen FADE_FROM_BLACK
	return

Chasecenter_Lockers_TournamentRules_Dialgoue_2:
	msgbox gText_Chasecenter_Lockers_Information_ForTheGroupStage
	msgbox gText_Chasecenter_Lockers_Information_TheTrainerWith
	goto Chasecenter_Lockers_TournamentRules_Dialgoue_1


gText_Chasecenter_Lockers_Information_ForTheGroupStage::
	.string "For the Group Stage, you'll be randomly\n"
	.string "split into four groups of four\l"
	.string "trainers. You'll battle all of the other\l"
	.string "Trainers in your group, and each match\l"
	.string "will be on a different terrain\l"
	.string "battlefield. You will bring six Pokémon\l"
	.string "with you, and choose three before the\l"
	.string "start of each match in the Group\l"
	.string "Stage. You will be healed after every\l"
	.string "match, but you may not use items from\l"
	.string "your bag during battle.$"

gText_Chasecenter_Lockers_Information_TheTrainerWith::
	.string "The Trainer with the best record in a\n"
	.string "group will proceed to the Semi-Finals.\l"
	.string "In the event of a tie, we will go to a\l"
	.string "tiebreaker.$"

gText_Chasecenter_Lockers_Information_InTheFinalStage::
	.string "In the Final Stage, you will be paired\n"
	.string "against another winning Trainer from a\l"
	.string "different Group. You will battle on a\l"
	.string "neutral battlefield, with a full party\l"
	.string "of six. The Semi-Final winners will then\l"
	.string "face off for the Championship!\l"
	.string "Trainers can change their six Pokémon\l"
	.string "between matches, but are still not\l"
	.string "permitted to use items during battle.$"

gText_Chasecenter_Lockers_WHatWouldYouLike::
	.string "What information would you like? Press\n"
	.string "Yes for Bracket, and No for Rules.$"
