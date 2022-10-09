Marin_EliteHome_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Marin_EliteHome_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Marin_EliteHome_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Marin_EliteHome_Siebold_Visibility_Script
	return


Marin_EliteHome_Siebold_Visibility_Script::
	compare VAR_STORYLINE_STATE, STORY_START_CHAMPIONSHIP
	goto_if_lt Marin_EliteHome_Siebold_Visibility_Script_2
	compare VAR_STORYLINE_STATE, STORY_POST_YOU_REALIZE_WERE_EVIL
	goto_if_gt Marin_EliteHome_Siebold_Visibility_Script_2
Marin_EliteHome_Siebold_Visibility_Script_1:
	return

Marin_EliteHome_Siebold_Visibility_Script_2:
	setflag FLAG_TEMP_1
	goto Marin_EliteHome_Siebold_Visibility_Script_1


Marin_EliteHome_PictureFrame_Dialogue::
	lock
	compare VAR_LILYCOVE_CITY_STATE, 2
	goto_if_gt Marin_EliteHome_PictureFrame_Dialogue_2
	compare VAR_ROUTE116_STATE, 4
	goto_if_gt Marin_EliteHome_PictureFrame_Dialogue_3
	msgbox gText_Marin_EliteHome_ADigitalPhoto_Unknown, MSGBOX_AUTOCLOSE
Marin_EliteHome_PictureFrame_Dialogue_1:
	release
	end

Marin_EliteHome_PictureFrame_Dialogue_2:
	call MaskOff_QuestK_Dialogue
	goto Marin_EliteHome_PictureFrame_Dialogue_1

Marin_EliteHome_PictureFrame_Dialogue_3:
	msgbox gText_Marin_EliteHome_ADigitalPhoto, MSGBOX_AUTOCLOSE
	goto Marin_EliteHome_PictureFrame_Dialogue_1


gText_Marin_EliteHome_ADigitalPhoto_Unknown::
	.string "A digital photo frame. The picture being\n"
	.string "displayed shows two people together\l"
	.string "at a ramen restaurant.$"

gText_Marin_EliteHome_ADigitalPhoto::
	.string "A digital photo frame. The picture being\n"
	.string "displayed shows Siebold with somebody\l"
	.string "at a ramen restaurant.$"
