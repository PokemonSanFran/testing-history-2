Psfcity10_EliteHome_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity10_EliteHome_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity10_EliteHome_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity10_EliteHome_OnTransition
	return


Psfcity10_EliteHome_OnTransition::
	compare VAR_STORYLINE_STATE, 100
	goto_if_lt Psfcity10_EliteHome_OnTransition_1
	return

Psfcity10_EliteHome_OnTransition_1:
	call MaskOff_HideObject_Script
	return


Psfcity10_EliteHome_PictureFrame_Dialogue::
	lock
	compare VAR_LILYCOVE_CITY_STATE, 2
	goto_if_gt Psfcity10_EliteHome_PictureFrame_Dialogue_2
	compare VAR_ROUTE116_STATE, 4
	goto_if_gt Psfcity10_EliteHome_PictureFrame_Dialogue_3
	msgbox gText_Psfcity10_EliteHome_ADigitalPhoto_Unknown, MSGBOX_AUTOCLOSE
Psfcity10_EliteHome_PictureFrame_Dialogue_1:
	release
	end

Psfcity10_EliteHome_PictureFrame_Dialogue_2:
	call MaskOff_QuestK_Dialogue
	goto Psfcity10_EliteHome_PictureFrame_Dialogue_1

Psfcity10_EliteHome_PictureFrame_Dialogue_3:
	msgbox gText_Psfcity10_EliteHome_ADigitalPhoto, MSGBOX_AUTOCLOSE
	goto Psfcity10_EliteHome_PictureFrame_Dialogue_1


gText_Psfcity10_EliteHome_ADigitalPhoto_Unknown::
	.string "A digital photo frame. The picture being\n"
	.string "displayed shows two people together\l"
	.string "at a ramen restaurant.$"

gText_Psfcity10_EliteHome_ADigitalPhoto::
	.string "A digital photo frame. The picture being\n"
	.string "displayed shows Psfelite3 with\l"
	.string "somebody at a ramen restaurant.$"
