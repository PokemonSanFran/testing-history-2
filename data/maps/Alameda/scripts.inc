Alameda_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Alameda_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Alameda_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Alameda_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Alameda_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_ALAMEDA
	call Alameda_LayoutSwap_Script
	call Quest_StealTheAxe_HideLeader_Script
	call Alameda_ObjectVisibility_Script
	call Quest_CutePokemon_HideMelissaD_Script
	call Earthquake_HideTransport_Script
	return

Alameda_MapScripts_MAP_SCRIPT_ON_LOAD:
	goto Alameda_MapScripts_OnLoad
	return

Alameda_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_ALAMEDA_STATE, START_SURVIVAL_CHANCE, SurvivalChance333_ExplainOperation
	map_script_2 VAR_ALAMEDA_STATE, WHY_ARE_YOU_HELPING_THEM, WhyAreYouHelpingThem_MissionDebrief_Dialogue
	map_script_2 VAR_ALAMEDA_STATE, POST_EARTHQUAKE, Earthquake_ShowDestroyedCity_Script
	map_script_2 VAR_ALAMEDA_STATE, POST_EARTHQUAKE_RESCUE, Earthquake_PostRescue_Dialogue
	map_script_2 VAR_STORYLINE_STATE, STORY_POST_DYNAMAX_BOSS, LetsFinishThis_MovePlayer_Script
	.2byte 0


Alameda_ObjectVisibility_Script::
	switch VAR_ALAMEDA_STATE
	case 0, Alameda_ObjectVisibility_Script_3
	case SAVE_ARCHER_ALAMEDA, Alameda_ObjectVisibility_Script_4
	case START_SURVIVAL_CHANCE, Alameda_ObjectVisibility_Script_5
	case WHY_ARE_YOU_HELPING_THEM, Alameda_ObjectVisibility_Script_6
	case POST_EARTHQUAKE, Alameda_ObjectVisibility_Script_7
	case POST_EARTHQUAKE_RESCUE, Alameda_ObjectVisibility_Script_8
	case POST_THIS_ISNT_RANDOM, Alameda_ObjectVisibility_Script_9
	call AssholesHome_HideObject_Script
	call SurvivalChance333_HideObject_Alameda_Script
Alameda_ObjectVisibility_Script_1:
	return

Alameda_ObjectVisibility_Script_3:
	goto SurvivalChance333_HideObject_Alameda_Script
	goto Alameda_ObjectVisibility_Script_1

Alameda_ObjectVisibility_Script_4:
	call SurvivalChance333_HideObject_Alameda_Script
	goto Alameda_ObjectVisibility_Script_1

Alameda_ObjectVisibility_Script_5:
	call AssholesHome_HideObject_Script
	goto Alameda_ObjectVisibility_Script_1

Alameda_ObjectVisibility_Script_6:
	call WhyAreYouHelpingThem_ObjectDebriefSetUp_Script
	goto Alameda_ObjectVisibility_Script_1

Alameda_ObjectVisibility_Script_7:
	call Earthquake_HideObject_Script
	goto Alameda_ObjectVisibility_Script_1

Alameda_ObjectVisibility_Script_8:
	call Earthquake_HideObject_Script
	goto Alameda_ObjectVisibility_Script_1

Alameda_ObjectVisibility_Script_9:
	call LetsFinishThis_ObjectSetUp_Script
	goto Alameda_ObjectVisibility_Script_1


Alameda_LayoutSwap_Script::
	compare VAR_ALAMEDA_STATE, START_CHAMPIONSHIP_CLEAN_RAID
	goto_if_gt Alameda_LayoutSwap_Script_1
	return

Alameda_LayoutSwap_Script_1:
	setmaplayoutindex LAYOUT_ALAMEDA_POST_EARTHQUAKE
	return


Alameda_MapScripts_OnLoad::
	compare VAR_ALAMEDA_STATE, START_SURVIVAL_CHANCE
	goto_if_gt Alameda_MapScripts_OnLoad_2
	return

Alameda_MapScripts_OnLoad_1:
	call Navalbase_PostRaidTiles_Script
	return

Alameda_MapScripts_OnLoad_2:
	compare VAR_ALAMEDA_STATE, START_CHAMPIONSHIP_CLEAN_RAID
	goto_if_lt Alameda_MapScripts_OnLoad_1
	return


Navalbase_PostRaidTiles_Script::
	call SurvivalChance333_FreezeIce
	call SurvivalChance333_SetLava
	call SurvivalChance333_BlowOpenDoors
	return


Alameda_ChooseFerryDestination_Script::
	msgbox gText_WhereWould, MSGBOX_NPC
	goto Alameda_UnlockedDestinations_Script
	return


Alameda_UnlockedDestinations_Script::
	switch VAR_FERRY_STATE
	case FERRY_DEFAULT, Alameda_UnlockedDestinations_Script_2
	case FERRY_ALAMEDA_AVAILABLE, Alameda_UnlockedDestinations_Script_2
	case FERRY_ALCATRAZ_AVAILABLE, Alameda_UnlockedDestinations_Script_3
	return

Alameda_UnlockedDestinations_Script_2:
	goto Alameda_FerryState0_Script
	return

Alameda_UnlockedDestinations_Script_3:
	goto Alameda_FerryState1_Script
	return


Alameda_FerryState0_Script::
	multichoicedefault 18, 8, ALAMEDA_FERRY_DESTINATIONS_VER1, 2, FALSE
	switch VAR_RESULT
	case 0, Alameda_FerryState0_Script_3
	case 1, Alameda_FerryState0_Script_4
	case MULTI_B_PRESSED, Alameda_FerryState0_Script_5
Alameda_FerryState0_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Alameda_FerryState0_Script_3:
	warp MAP_FERRYBUILDING, 8, 11
	goto Alameda_FerryState0_Script_1

Alameda_FerryState0_Script_4:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Alameda_FerryState0_Script_1

Alameda_FerryState0_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Alameda_FerryState0_Script_1


Alameda_FerryState1_Script::
	multichoicedefault 18, 8, ALAMEDA_FERRY_DESTINATIONS_VER2, 2, FALSE
	switch VAR_RESULT
	case 0, Alameda_FerryState1_Script_3
	case 1, Alameda_FerryState1_Script_4
	case 2, Alameda_FerryState1_Script_5
	case MULTI_B_PRESSED, Alameda_FerryState1_Script_6
Alameda_FerryState1_Script_1:
	call Common_EventScript_FerryDepartIsland
	return

Alameda_FerryState1_Script_3:
	warp MAP_FERRYBUILDING, 8, 11
	goto Alameda_FerryState1_Script_1

Alameda_FerryState1_Script_4:
	warp MAP_ALCATRAZ, 48, 61
	goto Alameda_FerryState1_Script_1

Alameda_FerryState1_Script_5:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Alameda_FerryState1_Script_1

Alameda_FerryState1_Script_6:
	goto SlateportCity_Harbor_EventScript_CancelDestinationSelect
	goto Alameda_FerryState1_Script_1


Alameda_Person1_Fisherman::
	compare VAR_ALAMEDA_STATE, START_EARTHQUAKE_RESCUE
	goto_if_eq Alameda_Person1_Fisherman_2
	msgbox Alameda_Person1_Fisherman_Text_1, MSGBOX_NPC
	end

Alameda_Person1_Fisherman_2:
	addvar VAR_ALAMEDA_STATE, 2
	msgbox Alameda_Person1_Fisherman_Text_0, MSGBOX_NPC
	end


Alameda_Stan_Interact_Script::
	lock
	call Quest_WallaceArmy_LoadStanSpeech_Script
	msgbox gText_WallaceArmy_OhWallaceSama, MSGBOX_NPC
	call Quest_WallaceArmy_PreBattleStan_Script
	trainerbattle_single TRAINER_ALAMEDA_STAN, gText_WallaceArmy_MarinSolarTheySpoke, gText_WallaceArmy_MyLord, Alameda_Stan_PostBattle_Script
	goto Alameda_Stan_PostBattle_Script
	return


Alameda_Stan_PostBattle_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WALLACEARMY, SUB_QUEST_1
	call Quest_WallaceArmy_CheckCompletionRate_Script
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Alameda_Stan_PostBattle_Script_2
	msgbox gText_WallaceArmy_PostQuestPlaceholder1
Alameda_Stan_PostBattle_Script_1:
	release
	end

Alameda_Stan_PostBattle_Script_2:
	msgbox gText_WallaceArmy_PostBattlePlaceholder1
	goto Alameda_Stan_PostBattle_Script_1


Alameda_Landlord_Dialogue::
	msgbox gText_Alameda_ManAfterThese, MSGBOX_NPC
	specialvar VAR_RESULT, Quest_Persuasivepassenger_CountRemainingSubquests
	compare VAR_RESULT, 2
	goto_if_eq Alameda_Landlord_Dialogue_2
Alameda_Landlord_Dialogue_1:
	end

Alameda_Landlord_Dialogue_2:
	goto Quest_Persuasivepassenger_Landlord_Battle_Script
	goto Alameda_Landlord_Dialogue_1


Alameda_Person1_Fisherman_Text_0:
	.string "thanks for saving me!$"

Alameda_Person1_Fisherman_Text_1:
	.string "i am a dude!$"

gText_Alameda_ManAfterThese::
	.string "Man, after this rent hikes, I'm gonna\n"
	.string "make a killing on this building!$"
