SOMA_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SOMA_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SOMA_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_StopMugging_HideObject_Script
	return

SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_SOMA
	call Quest_StopMugging_HideObject_Script
	call Twitter_HideReporter_Script
	call WowYoureStrong_HideObject_Script
	return

SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SALESFORCETOWER_CONFERENCE_STATE, DEFEATED_WHITNEY, WowYoureStrong_WalkToPlayer_Script
	.2byte 0


SOMA_Stan_Interact_Script::
	lock
	call Quest_WallaceArmy_LoadStanSpeech_Script
	msgbox gText_WallaceArmy_OhWallaceSama, MSGBOX_NPC
	call Quest_WallaceArmy_PreBattleStan_Script
	trainerbattle_single TRAINER_SOMA_STAN, gText_WallaceArmy_MarinSolarTheySpoke, gText_WallaceArmy_MyLord, SOMA_Stan_PostBattle_Script
	goto SOMA_Stan_PostBattle_Script
	return


SOMA_Stan_PostBattle_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WALLACEARMY, SUB_QUEST_3
	call Quest_WallaceArmy_CheckCompletionRate_Script
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq SOMA_Stan_PostBattle_Script_2
	msgbox gText_WallaceArmy_PostQuestPlaceholder1, , SPEAKER_STAN_SOMA
SOMA_Stan_PostBattle_Script_1:
	release
	end

SOMA_Stan_PostBattle_Script_2:
	msgbox gText_WallaceArmy_PostBattlePlaceholder1, , SPEAKER_STAN_SOMA
	goto SOMA_Stan_PostBattle_Script_1


SOMA_EventScript_DeliveryF::
	returnqueststate QUEST_BODEGABURNOUT
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt SOMA_EventScript_DeliveryF_2
SOMA_EventScript_DeliveryF_1:
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_AUTOCLOSE
	end

SOMA_EventScript_DeliveryF_2:
	goto Quest_Bodegaburnout_DeliveryF_Dialogue
	goto SOMA_EventScript_DeliveryF_1

