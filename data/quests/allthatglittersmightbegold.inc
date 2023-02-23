Quest_Allthatglittersmightbegold_StartSparkle_Script::
	returnqueststate QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	compare VAR_RESULT, QUEST_MENU_COMPLETE_QUEST
	goto_if_ne Quest_Allthatglittersmightbegold_StartSparkle_Script_2
Quest_Allthatglittersmightbegold_StartSparkle_Script_1:
	return

Quest_Allthatglittersmightbegold_StartSparkle_Script_2:
	dofieldeffectsparkle 45, 66, 0
	goto Quest_Allthatglittersmightbegold_StartSparkle_Script_1


Quest_Allthatglittersmightbegold_Interact_Elior_Script::
	lock
	faceplayer
	returnqueststate QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_Allthatglittersmightbegold_Interact_Elior_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Quest_Allthatglittersmightbegold_Interact_Elior_Script_3
	case QUEST_MENU_SET_REWARD, Quest_Allthatglittersmightbegold_Interact_Elior_Script_4
	goto Quest_Allthatglittersmightbegold_StartQuest_Dialogue
	return

Quest_Allthatglittersmightbegold_Interact_Elior_Script_2:
	goto Quest_Allthatglittersmightbegold_Active_Dialogue
	return

Quest_Allthatglittersmightbegold_Interact_Elior_Script_3:
	goto Quest_Allthatglittersmightbegold_Completed_Dialogue
	return

Quest_Allthatglittersmightbegold_Interact_Elior_Script_4:
	goto Quest_Allthatglittersmightbegold_Reward_Dialogue
	return


Quest_Allthatglittersmightbegold_StartQuest_Dialogue::
	msgbox gText_Allthatglittersmightbegold_HeyThere, MSGBOX_NPC, SPEAKER_ELIOR, 
	closemessage
	goto Quest_Allthatglittersmightbegold_BeforeVideo_Script
	return


Quest_Allthatglittersmightbegold_BeforeVideo_Script::
	setflag FLAG_DEFEATED_SUDOWOODO
	setflag FLAG_SPAWN_INVISIBLE
	setflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, NOT_SHOWN_PICTURE
	warpsilent MAP_UNDERWATER_PSFROUTE15, 45, 66
	return


Quest_Allthatglittersmightbegold_ShowVideo_Dialogue::
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, SHOWN_PICTURE
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	setvar VAR_TEMP_1, 0
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	delay 30
	msgbox gText_Allthatglittersmightbegold_SeeThatThere, , SPEAKER_ELIOR, , EMOTE_SHOCK
	closemessage
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	clearflag FLAG_DEFEATED_SUDOWOODO
	clearflag FLAG_SPAWN_INVISIBLE
	delay 30
	warpsilent MAP_PSFROUTE15, 40, 61
	return


Quest_Allthatglittersmightbegold_AfterVideo_Dialogue::
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, QUEST_ASSIGNED
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_Allthatglittersmightbegold_ImTooOld, , SPEAKER_ELIOR, 
	startquest QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	msgbox gText_Allthatglittersmightbegold_Holla, , SPEAKER_ELIOR, 
	release
	end


Quest_Allthatglittersmightbegold_Active_Dialogue::
	msgbox gText_Allthatglittersmightbegold_YouHeadingDown, MSGBOX_YESNO, SPEAKER_ELIOR, 
	msgbox gText_Allthatglittersmightbegold_OkayIPut, , SPEAKER_ELIOR, 
	closemessage
	warpsilent MAP_UNDERWATER_PSFROUTE15, 42, 19
	return


Quest_Allthatglittersmightbegold_CoreEncounter_Script::
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	call Common_EventScript_SaveGame
	faceplayer
	setwildbattle SPECIES_FLOATZEL, 60, ITEM_NONE
	playmoncry SPECIES_FLOATZEL, CRY_MODE_ENCOUNTER
	waitmoncry
	playse SE_SHINY
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	waitse
	delay 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	closemessage
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	switch VAR_RESULT
	case B_OUTCOME_CAUGHT, Quest_Allthatglittersmightbegold_CoreEncounter_Script_3
	case B_OUTCOME_WON, Quest_Allthatglittersmightbegold_CoreEncounter_Script_4
Quest_Allthatglittersmightbegold_CoreEncounter_Script_1:
	release
	end

Quest_Allthatglittersmightbegold_CoreEncounter_Script_3:
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, CAUGHT_SHINY
	goto Quest_Allthatglittersmightbegold_CoreEncounter_Script_1

Quest_Allthatglittersmightbegold_CoreEncounter_Script_4:
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, DEFEATED_SHINY
	call Quest_Allthatglittersmightbegold_RemoveFloatzel_Script
	goto Quest_Allthatglittersmightbegold_CoreEncounter_Script_1


Quest_Allthatglittersmightbegold_RemoveFloatzel_Script::
	call Quest_Allthatglittersmightbegold_StartSparkle_Script
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers FADE_FROM_BLACK
	msgbox gText_Allthatglittersmightbegold_WaitWasThat, , SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_SHOCK
	questmenu QUEST_MENU_SET_REWARD, QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	closemessage
	return


Quest_Allthatglittersmightbegold_ReturnSurface_Script::
	msgbox gText_Allthatglittersmightbegold_DoYouWantToReturn, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq Quest_Allthatglittersmightbegold_ReturnSurface_Script_1
	return

Quest_Allthatglittersmightbegold_ReturnSurface_Script_1:
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, POST_DIVE
	warpsilent MAP_PSFROUTE15, 40, 61
	return


Quest_Allthatglittersmightbegold_CheckSuccess_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_QUEST_GLITTERS_GOLD_STATE, QUEST_ASSIGNED
	goto_if_quest_reward QUEST_ALLTHATGLITTERSMIGHTBEGOLD, Quest_Allthatglittersmightbegold_Reward_Dialogue
	goto Quest_Allthatglittersmightbegold_EmptyHanded_Dialogue
	return


Quest_Allthatglittersmightbegold_EmptyHanded_Dialogue::
	msgbox gText_Allthatglittersmightbegold_CouldntFindIt, , SPEAKER_ELIOR, , EMOTE_SWEAT
	closemessage
	end


Quest_Allthatglittersmightbegold_Reward_Dialogue::
	msgbox gText_Allthatglittersmightbegold_YouGotTheTreasure, , SPEAKER_ELIOR, , EMOTE_HAPPY
	compare VAR_QUEST_GLITTERS_GOLD_STATE, CAUGHT_SHINY
	goto_if_eq Quest_Allthatglittersmightbegold_Reward_Dialogue_2
	msgbox gText_Allthatglittersmightbegold_AShameYou, , SPEAKER_ELIOR, , EMOTE_SAD
Quest_Allthatglittersmightbegold_Reward_Dialogue_1:
	msgbox gText_Allthatglittersmightbegold_IWasThinking, , SPEAKER_ELIOR, 
	call Quest_Allthatglittersmightbegold_GiveReward_Script
	completequest QUEST_ALLTHATGLITTERSMIGHTBEGOLD
	closemessage
	end

Quest_Allthatglittersmightbegold_Reward_Dialogue_2:
	msgbox gText_Allthatglittersmightbegold_AtLeastYou, , SPEAKER_ELIOR, 
	goto Quest_Allthatglittersmightbegold_Reward_Dialogue_1


Quest_Allthatglittersmightbegold_GiveReward_Script::
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_Allthatglittersmightbegold_GaveYou
	additem ITEM_HM08
	waitmessage
	waitfanfare
	msgbox gText_Allthatglittersmightbegold_OkayIfYou, , SPEAKER_ELIOR, 
	return


Quest_Allthatglittersmightbegold_Completed_Dialogue::
	msgbox gText_Allthatglittersmightbegold_IfYouFind, MSGBOX_NPC, SPEAKER_ELIOR, , EMOTE_HAPPY
	return


gText_Allthatglittersmightbegold_HeyThere::
	.string "Hey there, young one. You look like\n"
	.string "you're up for a challenge! My boat here\l"
	.string "and I, we go fishing out in the Bay\l"
	.string "every weekend. My newphew got me one\l"
	.string "of them fancy underside camera for my\l"
	.string "boat, and I was watching it and... well\l"
	.string "come look!$"

gText_Allthatglittersmightbegold_SeeThatThere::
	.string "See that there sparkle? You know there\n"
	.string "used to be a big old gold rush around\l"
	.string "these parts. I betcha that's there\l"
	.string "some gold!$"

gText_Allthatglittersmightbegold_ImTooOld::
	.string "I'm too old to go on adventures\n"
	.string "anymore, but I'll cut you a deal. I'll\l"
	.string "lend you my diving equipment, and if\l"
	.string "you go down and get it for me, we'll\l"
	.string "split it... you keep 70%!$"

gText_Allthatglittersmightbegold_OkayIPut::
	.string "Okay! I put a beacon down there for\n"
	.string "you, just talk to it when you're ready\l"
	.string "to come back, and I'll pull ya up.$"

gText_Allthatglittersmightbegold_YouHeadingDown::
	.string "You heading down there?$"

gText_Allthatglittersmightbegold_ReadyTo::
	.string "Ready to come back up?$"

gText_Allthatglittersmightbegold_CouldntFindIt::
	.string "Couldn't find it yet? No matter, I'm sure\n"
	.string "its down there somewhere.$"

gText_Allthatglittersmightbegold_YouGotTheTreasure::
	.string "You got the treasure?!? Let me see!\n"
	.string "...Oh. It was just a Pokémon?$"

gText_Allthatglittersmightbegold_AShameYou::
	.string "A shame you didn't catch it!$"

gText_Allthatglittersmightbegold_AtLeastYou::
	.string "At least you caught it, I hope its\n"
	.string "strong as it is sparkly!$"

gText_Allthatglittersmightbegold_IWasThinking::
	.string "I was thinking while you were down\n"
	.string "there, I'm too old for that diving\l"
	.string "nonsense. Let me teach you something...$"

gText_Allthatglittersmightbegold_OkayIfYou::
	.string "Okay! If you have a Pokémon with you\n"
	.string "that can learn Dive, you can explore\l"
	.string "the ocean floor. Maybe you'll find\l"
	.string "treasure after all!$"

gText_Allthatglittersmightbegold_IfYouFind::
	.string "If you find something truly amazing\n"
	.string "down there, let me know about it! I'll\l"
	.string "trade you more gear for a fun story.$"

gText_Allthatglittersmightbegold_GaveYou::
	.string "Elior taught your Pokémon how to Dive!$"

gText_Allthatglittersmightbegold_Holla::
	.string "Holla at me when you're ready to head\n"
	.string "down.$"

gText_Allthatglittersmightbegold_DoYouWantToReturn::
	.string "Do you want to return to Elior on\n"
	.string "Psfroute15?$"

gText_Allthatglittersmightbegold_WaitWasThat::
	.string "Wait, was that the sparkle? Let me go\n"
	.string "tell Elior...$"
