Quest_Allthatglittersmightbegold_StartSparkle_Script::
	returnqueststate QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	compare VAR_RESULT, QUEST_MENU_COMPLETE_QUEST
	goto_if_ne Quest_Allthatglittersmightbegold_StartSparkle_Script_2
Quest_Allthatglittersmightbegold_StartSparkle_Script_1:
	return

Quest_Allthatglittersmightbegold_StartSparkle_Script_2:
	dofieldeffectsparkle 46, 30 0
	dofieldeffectsparkle 47, 31 0
	dofieldeffectsparkle 48, 32 0
	dofieldeffectsparkle 49, 33 0
	setvar VAR_TEMP_1, 1
	goto Quest_Allthatglittersmightbegold_StartSparkle_Script_1


Quest_Allthatglittersmightbegold_Interact_Elior_Script::
	lock
	faceplayer
	returnqueststate QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	switch VAR_RESULT

Quest_Allthatglittersmightbegold_StartQuest_Dialogue::
	return


Quest_Allthatglittersmightbegold_ContinueAfterPhoto_Dialogue::
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, QUEST_ASSIGNED
	return


Quest_Allthatglittersmightbegold_ShowPhoto_Script::
	setflag FLAG_SPAWN_INVISIBLE
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, NOT_SHOWN_PICTURE
	warpsilent MAP_UNDERWATER_PSFROUTE15, 46, 30
	return


Quest_Allthatglittersmightbegold_Treasure_Dialogue::
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, SHOWN_PICTURE
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	msgbox Quest_Allthatglittersmightbegold_Treasure_Dialogue_Text_0
	closemessage
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	clearflag FLAG_SPAWN_INVISIBLE
	warpsilent MAP_PSFROUTE15, 46, 30
	return


Quest_Allthatglittersmightbegold_Active_Dialogue::
	return


Quest_Allthatglittersmightbegold_Reward_Dialogue::
	return


Quest_Allthatglittersmightbegold_GiveReward_Script::
	return


Quest_Allthatglittersmightbegold_Completed_Dialogue::
	return


Quest_Allthatglittersmightbegold_Treasure_Dialogue_Text_0:
	.string "yeah that's the fuckin' treasure right there$"
