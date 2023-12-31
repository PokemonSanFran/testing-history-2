Salesforcetower_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Salesforcetower_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Salesforcetower_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Salesforcetower_2F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Salesforcetower_2F_MapScripts_OnTransition
	return

Salesforcetower_2F_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SALESFORCETOWER_CONFERENCE_STATE, PRE_WELCOME_TO_THE_WAR_ROOM, Salesforcetower_2F_MovePlayerIntoPosition_Script
	map_script_2 VAR_SALESFORCETOWER_CONFERENCE_STATE, PRE_YOU_REALIZE_WERE_EVIL_RIGHT, Salesforcetower_2F_MovePlayerIntoPosition_Script
	map_script_2 VAR_LETS_BURN_THIS_MOTHER_STATE, DEFEATED_ARCHER_ALCATRAZ, LetsBurnThisMotherDown_MissionComplete_Dialogue
	map_script_2 VAR_HOW_DISAPPOINTING_STATE, DEFEATED_ARIANA_CHINATOWN, HowDisappointing_MissionComplete_Dialogue
	map_script_2 VAR_MANHUNT_STATE, DEFEATED_MANHUNT_GIOVANNI, Manhunt_MissionComplete_Dialogue
	map_script_2 VAR_TOWER_RAID_STATE, SABRINA_WARP_DOOR_UNLOCKED, ImIn_PostWarpSplit_Dialogue
	.2byte 0


Salesforcetower_2F_MapScripts_OnTransition::
	switch VAR_SALESFORCETOWER_CONFERENCE_STATE
	case 0, Salesforcetower_2F_MapScripts_OnTransition_3
	case STEPPED_INTO_SABRINA_ROOM, Salesforcetower_2F_MapScripts_OnTransition_3
	case POST_ALWAYS_WATCHING_WAZOWSKI, Salesforcetower_2F_MapScripts_OnTransition_3
	case POST_WELCOME_TO_THE_WAR_ROOM, Salesforcetower_2F_MapScripts_OnTransition_3
	case PRE_WELCOME_TO_THE_WAR_ROOM, Salesforcetower_2F_MapScripts_OnTransition_4
	case PRE_YOU_REALIZE_WERE_EVIL_RIGHT, Salesforcetower_2F_MapScripts_OnTransition_5
	case POST_YOU_REALIZE_THEYRE_EVIL_RIGHT, Salesforcetower_2F_MapScripts_OnTransition_6
	case START_FALSE_TIMELINE, Salesforcetower_2F_MapScripts_OnTransition_7
	call WelcomeToTheWarRoom_Object_Hide_Script
Salesforcetower_2F_MapScripts_OnTransition_1:
	goto_if_set FLAG_TIMELINE_FALSE, Salesforcetower_2F_MapScripts_OnTransition_9
	return

Salesforcetower_2F_MapScripts_OnTransition_3:
	call WelcomeToTheWarRoom_Object_Hide_Script
	goto Salesforcetower_2F_MapScripts_OnTransition_1

Salesforcetower_2F_MapScripts_OnTransition_4:
	call WelcomeToTheWarRoom_Object_Setup_Script
	goto Salesforcetower_2F_MapScripts_OnTransition_1

Salesforcetower_2F_MapScripts_OnTransition_5:
	call YouRealizeWereEvilRight_Object_Setup_Script
	goto Salesforcetower_2F_MapScripts_OnTransition_1

Salesforcetower_2F_MapScripts_OnTransition_6:
	call YouRealizeWereEvilRight_Object_Cleanup_Script
	goto Salesforcetower_2F_MapScripts_OnTransition_1

Salesforcetower_2F_MapScripts_OnTransition_7:
	call CongratsYoureanAsshole_ObjectCleanUp_Script
	goto Salesforcetower_2F_MapScripts_OnTransition_1

Salesforcetower_2F_MapScripts_OnTransition_9:
	switch VAR_MANHUNT_STATE
	case 0, Salesforcetower_2F_MapScripts_OnTransition_13
	switch VAR_HOW_DISAPPOINTING_STATE
	case MISSION_NOT_ASSIGNED, Salesforcetower_2F_MapScripts_OnTransition_16
	call YouHaveYourOrders_ObjectSetUp_Script
	compare VAR_LETS_BURN_THIS_MOTHER_STATE, DEFEATED_ARCHER_ALCATRAZ
	goto_if_eq Salesforcetower_2F_MapScripts_OnTransition_18
	return

Salesforcetower_2F_MapScripts_OnTransition_13:
	return

Salesforcetower_2F_MapScripts_OnTransition_16:
	return

Salesforcetower_2F_MapScripts_OnTransition_18:
	return


Salesforcetower_2F_MovePlayerIntoPosition_Script::
	lock
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 17
	goto_if_ne Salesforcetower_2F_MovePlayerIntoPosition_Script_2
Salesforcetower_2F_MovePlayerIntoPosition_Script_1:
	switch VAR_SALESFORCETOWER_CONFERENCE_STATE
	case PRE_WELCOME_TO_THE_WAR_ROOM, Salesforcetower_2F_MovePlayerIntoPosition_Script_5
	case PRE_YOU_REALIZE_WERE_EVIL_RIGHT, Salesforcetower_2F_MovePlayerIntoPosition_Script_6
	return

Salesforcetower_2F_MovePlayerIntoPosition_Script_2:
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 17, 33
	TeleportCamera 17, 33
	fadescreen FADE_FROM_BLACK
	goto Salesforcetower_2F_MovePlayerIntoPosition_Script_1

Salesforcetower_2F_MovePlayerIntoPosition_Script_5:
	goto WelcomeToTheWarRoom_ExplainSitaution_Dialogue
	return

Salesforcetower_2F_MovePlayerIntoPosition_Script_6:
	goto YouRealizeWereEvilRight_Open_Dialogue
	return


Salesforcetower_2F_Oak_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_2ND_TEAMROCKET_TAKEDOWN, Salesforcetower_2F_Oak_Event_Script_3
	release
	end

Salesforcetower_2F_Oak_Event_Script_3:
	return


Salesforcetower_2F_Koga_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_START_FALSE_TIMELINE, Salesforcetower_2F_Koga_Event_Script_3
	case STORY_1ST_TEAMROCKET_TAKEDOWN, Salesforcetower_2F_Koga_Event_Script_4
	case STORY_2ND_TEAMROCKET_TAKEDOWN, Salesforcetower_2F_Koga_Event_Script_5
Salesforcetower_2F_Koga_Event_Script_1:
	release
	end

Salesforcetower_2F_Koga_Event_Script_3:
	call YouHaveYourOrders_Assignment_Dialogue
	goto Salesforcetower_2F_Koga_Event_Script_1

Salesforcetower_2F_Koga_Event_Script_4:
	call YouHaveYourOrders_Assignment_Dialogue
	goto Salesforcetower_2F_Koga_Event_Script_1

Salesforcetower_2F_Koga_Event_Script_5:
	call YouHaveYourOrders_Assignment_Dialogue
	goto Salesforcetower_2F_Koga_Event_Script_1


Salesforcetower_2F_Sabrina_Event_Script::
	lock
	switch VAR_STORYLINE_STATE
	case STORY_START_FALSE_TIMELINE, Salesforcetower_2F_Sabrina_Event_Script_3
	case STORY_1ST_TEAMROCKET_TAKEDOWN, Salesforcetower_2F_Sabrina_Event_Script_4
	case STORY_2ND_TEAMROCKET_TAKEDOWN, Salesforcetower_2F_Sabrina_Event_Script_5
	call AlwaysWatchingWazowski_IgnoringPlayer_Dialogue
Salesforcetower_2F_Sabrina_Event_Script_1:
	release
	end

Salesforcetower_2F_Sabrina_Event_Script_3:
	call Manhunt_Assignment_Dialogue
	goto Salesforcetower_2F_Sabrina_Event_Script_1

Salesforcetower_2F_Sabrina_Event_Script_4:
	call Manhunt_Assignment_Dialogue
	goto Salesforcetower_2F_Sabrina_Event_Script_1

Salesforcetower_2F_Sabrina_Event_Script_5:
	call Manhunt_Assignment_Dialogue
	goto Salesforcetower_2F_Sabrina_Event_Script_1

