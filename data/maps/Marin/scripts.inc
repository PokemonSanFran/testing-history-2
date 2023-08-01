Marin_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Marin_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Marin_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Restoremarin_HideLenora_Script
	call Quest_Restoremarin_MoveLenora_Script
	call Marin_HideBianca_Script
	call Marin_HideLiidia_Script
	call Quest_BerrySustaiability_HideLeader_Script
	call Quest_GetTheBand_HideBikerD_Script
	call IGuessWeShouldBeNiceNow_HidePopup_Script
	call LetsGrabLunch_CheckRestorationProgress_Script
	call Quest_Manofmanyhats_CheckDoorLock_Script
	call Quest_Breaktheinternet_MarinGirl_Visibility_Script
	return

Marin_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Marin_LockRangerDoor_Script
	return

Marin_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_MARIN_STATE, ROBINWILLIAMSTUNNEL_PUZZLES_SOLVED, IGuessWeShouldBeNiceNow_ExitCave_Script
	map_script_2 VAR_STORYLINE_STATE, STORY_RESTORATION_1_COMPLETE, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Marin_HideBianca_Script::
	setflag FLAG_TEMP_3
	return


Marin_HideLiidia_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES
	compare VAR_RESULT, 0
	goto_if_ne Marin_HideLiidia_Script_2
Marin_HideLiidia_Script_1:
	return

Marin_HideLiidia_Script_2:
	setflag FLAG_TEMP_4
	goto Marin_HideLiidia_Script_1


Marin_LockRangerDoor_Script::
	compare VAR_QUEST_MANOFMANYHATS, OPEN_LOCKED_DOOR
	goto_if_lt Marin_LockRangerDoor_Script_1
	return

Marin_LockRangerDoor_Script_1:
	setmetatile 13, 8, 0x23B, TRUE
	return


Marin_RangerStationDoor_Script::
	lock
	msgbox gText_Marin_TheDoorIsLocked, MSGBOX_SIGN
	goto_if_quest_active QUEST_MANOFMANYHATS, Quest_Manofmanyhats_EnterDoorCombination_Dialogue
	return


Marin_Stan_Interact_Script::
	lock
	call Quest_WallaceArmy_LoadStanSpeech_Script
	msgbox gText_WallaceArmy_OhWallaceSama, MSGBOX_NPC
	call Quest_WallaceArmy_PreBattleStan_Script
	trainerbattle_single TRAINER_MARIN_STAN, gText_WallaceArmy_MarinSolarTheySpoke, gText_WallaceArmy_MyLord, Marin_Stan_PostBattle_Script
	goto Marin_Stan_PostBattle_Script
	return


Marin_Stan_PostBattle_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WALLACEARMY, SUB_QUEST_5
	call Quest_WallaceArmy_CheckCompletionRate_Script
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Marin_Stan_PostBattle_Script_2
	msgbox gText_WallaceArmy_PostQuestPlaceholder1
Marin_Stan_PostBattle_Script_1:
	release
	end

Marin_Stan_PostBattle_Script_2:
	msgbox gText_WallaceArmy_PostBattlePlaceholder1
	goto Marin_Stan_PostBattle_Script_1


Marin_HideMapNamePopup_Script::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return


Marin_Biker_Interact_Script::
	msgbox gText_Marin_PlaceholderBiker, MSGBOX_NPC
	call Quest_GetTheBand_CheckQuestAndBike_Script
	compare VAR_RESULT, 0
	goto_if_ne Marin_Biker_Interact_Script_3
Marin_Biker_Interact_Script_1:
	end

Marin_Biker_Interact_Script_2:
	goto Quest_GetTheBand_Interact_BikerD_Dialogue
	goto Marin_Biker_Interact_Script_1

Marin_Biker_Interact_Script_3:
	compare VAR_TEMP_1, 0
	goto_if_ne Marin_Biker_Interact_Script_2
	goto Marin_Biker_Interact_Script_1


Marin_Lenora_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_RESTOREMARIN
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Marin_Lenora_Interact_Script_2
	case QUEST_MENU_SET_REWARD, Marin_Lenora_Interact_Script_3
	call Marin_Lenora_PreQuest_Dialogue
	return

Marin_Lenora_Interact_Script_2:
	call Quest_Restoremarin_Active_Script
	return

Marin_Lenora_Interact_Script_3:
	call Quest_Restoremarin_Reward_Dialogue
	return


Marin_Lenora_PreQuest_Dialogue::
	compare VAR_STORYLINE_STATE, STORY_POST_BATTLE_ARCHER_TREASUREISLAND
	goto_if_gt Marin_Lenora_PreQuest_Dialogue_1
	call Marin_Lenora_Dialogue
	return

Marin_Lenora_PreQuest_Dialogue_1:
	goto Quest_Restoremarin_StartQuest_Dialogue
	return


Marin_Lenora_Dialogue::
	msgbox gText_Marin_IUsedToBe, MSGBOX_NPC
	end


Marin_Girl_Interact_Script::
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_NPC
	goto_if_quest_active QUEST_BREAKTHEINTERNET, Quest_Breaktheinternet_Marin_Script
	end


gText_Marin_PlaceholderBiker::
	.string "i am a biker, and this is placeholder\n"
	.string "text.$"

gText_Marin_TheDoorIsLocked::
	.string "The door is locked.$"

gText_Marin_IUsedToBe::
	.string "i used to be the leader of the gym in\n"
	.string "town!$"
