Treasureisland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Treasureisland_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Treasureisland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Treasureisland_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Treasureisland_MapScripts_OnTransition
	return

Treasureisland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_RESTORATION_1_COMPLETE, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Treasureisland_MapScripts_OnTransition::
	switch VAR_STORYLINE_STATE
	case 38, Treasureisland_MapScripts_OnTransition_2
	goto LetsGrabLunch_HideObject_Script
	return

Treasureisland_MapScripts_OnTransition_2:
	return


Treasureisland_Movies_Dialogue::
	msgbox Treasureisland_Movies_Dialogue_Text_0, MSGBOX_SIGN
	end


Treasureisland_Movies_Dialogue_Text_0:
	.string "this is a movie theater. the cafe is\n"
	.string "inside.$"
