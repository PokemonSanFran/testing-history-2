Dogpatch_BIkerhq_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Dogpatch_BIkerhq_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Dogpatch_BIkerhq_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, Dogpatch_BIkerhq_CheckAcceptance_Script
	.2byte 0


Dogpatch_BIkerhq_CheckAcceptance_Script::
	addvar VAR_TEMP_0, 1
	lock
	returnqueststate QUEST_ANGELDELIVERY
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Dogpatch_BIkerhq_CheckAcceptance_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Dogpatch_BIkerhq_CheckAcceptance_Script_3
	goto Dogpatch_BIkerhq_KickOut_Cutscene
	return

Dogpatch_BIkerhq_CheckAcceptance_Script_2:
	goto Quest_AngelDelivery_StartBattle_Cutscene
	return

Dogpatch_BIkerhq_CheckAcceptance_Script_3:
	release
	end


Dogpatch_BIkerhq_GuardsBlockDoor_Cutscene::
	applymovement 1, Dogpatch_BIkerhq_GuardFromLeft_Movement
	applymovement 2, Dogpatch_BIkerhq_GuardFromRight_Movement
	waitmovement 2
	msgbox gText_Dogpatch_BIkerhq_ClubMembersOnly
	closemessage
	return


Dogpatch_BIkerhq_KickOut_Cutscene::
	call Dogpatch_BIkerhq_GuardsBlockDoor_Cutscene
	warp MAP_DOGPATCH, 2, 21
	release
	end


gText_Dogpatch_BIkerhq_ClubMembersOnly::
	.string "Sorry, members only. You'll have to\n"
	.string "leave.$"
