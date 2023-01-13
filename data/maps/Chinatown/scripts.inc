Chinatown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Chinatown_MapScripts_MAP_SCRIPT_ON_LOAD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Chinatown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Chinatown_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call HowDisappointing_ManageObject_Script
	call Quest_CulturalPurity_HideLeader_Script
	call Quest_CulturalPurity_HideBackUp_Script
	call Quest_CulturalPurity_MoveGuard_Script
	call Quest_Restorechinatown_HidePewfatOutside_Script
	call LetsGrabLunch_CheckRestorationProgress_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_LOAD:
	call Quest_Restorechinatown_LockGymDoor_Script
	return

Chinatown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_RESTORATION_1_COMPLETE, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Chinatown_LockGymDoor_Script::
	returnqueststate QUEST_RESTORECHINATOWN
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Chinatown_LockGymDoor_Script_2
	setmetatile 22, 3, 0x2B7, TRUE
	special DrawWholeMapView
	return

Chinatown_LockGymDoor_Script_2:
	return


Chinatown_GymDoor_Dialogue::
	returnqueststate QUEST_HOW_DISAPPOINTING
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_eq Chinatown_GymDoor_Dialogue_2
	returnqueststate QUEST_RESTORECHINATOWN
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Chinatown_GymDoor_Dialogue_5
	msgbox gText_Chinatown_TheDoorIsLocked, MSGBOX_SIGN
	end

Chinatown_GymDoor_Dialogue_2:
	msgbox gText_ImSupposed, MSGBOX_SIGN
	return

Chinatown_GymDoor_Dialogue_5:
	msgbox gText_Chinatown_TheDoorIsOpen, MSGBOX_SIGN
	return


gText_ImSupposed::
	.string "I'm supposed to wait outside.$"

gText_Chinatown_TheDoorIsOpen::
	.string "The door is open.$"

gText_Chinatown_TheDoorIsLocked::
	.string "The door is locked.$"

gText_Chinatown_IMissTheOld::
	.string "I miss the old days. I get so nostalgic\n"
	.string "for my childhood...I loved growing up in\l"
	.string "these streets.$"
