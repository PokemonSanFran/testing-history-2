Treasureisland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Treasureisland_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Treasureisland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Treasureisland_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_TREASUREISLAND
	call LetsGrabLunch_HideArcher_Outside_Script
	call Quest_Restoretreasureisland_HideCilan_Outside_Script
	call LetsGrabLunch_CheckRestorationProgress_Script
	return

Treasureisland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_RESTORATION_1_COMPLETE, YouRealizeWereEvilRight_PhoneCall_Dialogue
	.2byte 0


Treasureisland_Movies_Dialogue::
	msgbox Treasureisland_Movies_Dialogue_Text_0, MSGBOX_SIGN
	end


Treasureisland_Movies_Dialogue_Text_0:
	.string "this is a movie theater. the cafe is\n"
	.string "inside.$"
