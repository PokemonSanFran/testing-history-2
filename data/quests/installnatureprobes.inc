Quest_InstallNatureProbes_Interact_Liidia_Script::
	lock
	call Quest_InstallNatureProbes_CheckCompletionRate_Script
	returnqueststate QUEST_INSTALLNATUREPROBES
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_InstallNatureProbes_Interact_Liidia_Script_2
	case QUEST_MENU_SET_REWARD, Quest_InstallNatureProbes_Interact_Liidia_Script_3
	goto Quest_InstallNatureProbes_StartQuest_Dialogue
	return

Quest_InstallNatureProbes_Interact_Liidia_Script_2:
	goto Quest_InstallNatureProbes_Active_Dialogue
	return

Quest_InstallNatureProbes_Interact_Liidia_Script_3:
	goto Quest_InstallNatureProbes_Reward_Cutscene
	return


Quest_InstallNatureProbes_StartQuest_Dialogue::
	msgbox gText_InstallNatureProbes_GeezIGottaWorkTonight, MSGBOX_NPC
	msgbox gText_InstallNatureProbes_CanYouHelp, MSGBOX_NPC
	msgbox gText_InstallNatureProbes_YouHaveAPokedex, MSGBOX_NPC
	startquest QUEST_INSTALLNATUREPROBES
	release
	end


Quest_InstallNatureProbes_Active_Dialogue::
	call Quest_InstallNatureProbes_CheckCompletionRate_Script
	msgbox gText_InstallNatureProbes_WhatProbes, MSGBOX_NPC
	compare VAR_TEMP_1, 0
	goto_if_eq Quest_InstallNatureProbes_Active_Dialogue_2
Quest_InstallNatureProbes_Active_Dialogue_1:
	compare VAR_TEMP_2, 0
	goto_if_eq Quest_InstallNatureProbes_Active_Dialogue_5
Quest_InstallNatureProbes_Active_Dialogue_4:
	compare VAR_TEMP_3, 0
	goto_if_eq Quest_InstallNatureProbes_Active_Dialogue_7
	return

Quest_InstallNatureProbes_Active_Dialogue_2:
	msgbox gText_InstallNatureProbes_TheProbeInTheForest, MSGBOX_NPC
	goto Quest_InstallNatureProbes_Active_Dialogue_1

Quest_InstallNatureProbes_Active_Dialogue_5:
	msgbox gText_InstallNatureProbes_TheProbeOnTheHill, MSGBOX_NPC
	goto Quest_InstallNatureProbes_Active_Dialogue_4

Quest_InstallNatureProbes_Active_Dialogue_7:
	msgbox gText_InstallNatureProbes_TheProbeByTheShore, MSGBOX_NPC
	return


Quest_InstallNatureProbes_InstallForestProbe_Script::
	lock
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_InstallForestProbe_Script_2
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_InstallNatureProbes_YeahThisSeemsToMatch
	callnative ClearMugshot
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_INSTALLNATUREPROBES, SUB_QUEST_1
	call Quest_InstallNatureProbes_CheckCompletionRate_Script
	playse SE_CONTEST_HEART
	msgbox gText_InstallNatureProbes_PlayerInstalledForest
	waitse
	waitmessage
	release
	return

Quest_InstallNatureProbes_InstallForestProbe_Script_2:
	msgbox gText_InstallNatureProbes_ThereIsAProbe, MSGBOX_SIGN
	release
	end


Quest_InstallNatureProbes_InstallHillProbe_Script::
	lock
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_InstallHillProbe_Script_2
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_InstallNatureProbes_ThisIsAsGoodOfAHill
	callnative ClearMugshot
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_INSTALLNATUREPROBES, SUB_QUEST_2
	call Quest_InstallNatureProbes_CheckCompletionRate_Script
	playse SE_CONTEST_HEART
	msgbox gText_InstallNatureProbes_PlayerInstalledHill
	waitse
	waitmessage
	release
	end

Quest_InstallNatureProbes_InstallHillProbe_Script_2:
	msgbox gText_InstallNatureProbes_ThereIsAProbe, MSGBOX_SIGN
	release
	end


Quest_InstallNatureProbes_InstallShoreProbe_Script::
	lock
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_InstallShoreProbe_Script_2
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_InstallNatureProbes_JustGottaMakeSure
	callnative ClearMugshot
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_INSTALLNATUREPROBES, SUB_QUEST_3
	call Quest_InstallNatureProbes_CheckCompletionRate_Script
	playse SE_CONTEST_HEART
	msgbox gText_InstallNatureProbes_PlayerInstalledShore
	waitse
	waitmessage
	release
	end

Quest_InstallNatureProbes_InstallShoreProbe_Script_2:
	msgbox gText_InstallNatureProbes_ThereIsAProbe, MSGBOX_SIGN
	release
	end


Quest_InstallNatureProbes_CheckCompletionRate_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_INSTALLNATUREPROBES
	compare VAR_RESULT, 0
	goto_if_eq Quest_InstallNatureProbes_CheckCompletionRate_Script_2
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_CheckCompletionRate_Script_5
Quest_InstallNatureProbes_CheckCompletionRate_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_CheckCompletionRate_Script_8
Quest_InstallNatureProbes_CheckCompletionRate_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_INSTALLNATUREPROBES, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_InstallNatureProbes_CheckCompletionRate_Script_11
Quest_InstallNatureProbes_CheckCompletionRate_Script_10:
	compare VAR_TEMP_0, 3
	goto_if_eq Quest_InstallNatureProbes_CheckCompletionRate_Script_13
	return

Quest_InstallNatureProbes_CheckCompletionRate_Script_2:
	release
	return

Quest_InstallNatureProbes_CheckCompletionRate_Script_5:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_1, 1
	goto Quest_InstallNatureProbes_CheckCompletionRate_Script_4

Quest_InstallNatureProbes_CheckCompletionRate_Script_8:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_2, 1
	goto Quest_InstallNatureProbes_CheckCompletionRate_Script_7

Quest_InstallNatureProbes_CheckCompletionRate_Script_11:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_3, 1
	goto Quest_InstallNatureProbes_CheckCompletionRate_Script_10

Quest_InstallNatureProbes_CheckCompletionRate_Script_13:
	questmenu QUEST_MENU_SET_REWARD, QUEST_INSTALLNATUREPROBES
	return


Quest_InstallNatureProbes_Reward_Cutscene::
	msgbox gText_InstallNatureProbes_WowYouGotAll, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceAwayPlayer
	waitmovement 2
	playse SE_PC_LOGIN
	waitse
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 2
	msgbox gText_InstallNatureProbes_TheTrackingIsWorking, MSGBOX_NPC
	closemessage
	msgbox gText_InstallNatureProbes_OkayDone, MSGBOX_NPC
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_InstallNatureProbes_PokedexUpgradedWith
	waitmessage
	waitfanfare
	closemessage
	playse SE_POKENAV_CALL
	waitse
	msgbox gText_InstallNatureProbes_ThatsMyBoss
	applymovement 2, Common_Movement_FaceAwayPlayer
	waitmovement 2
	msgbox gText_InstallNatureProbes_GoForLiidia
	closemessage
	delay 32
	msgbox gText_InstallNatureProbes_IUnderstand
	closemessage
	playse SE_POKENAV_HANG_UP
	waitse
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 2
	msgbox gText_InstallNatureProbes_HeThankedMe
	msgbox gText_InstallNatureProbes_IRealizeNow
	closemessage
	applymovement 2, Quest_InstallNatureProbes_LeaveStation_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Quest_InstallNatureProbes_WatchLiidiaLeave_Movement
	waitmovement 2
	removeobject 2
	completequest QUEST_INSTALLNATUREPROBES
	release
	end


Quest_InstallNatureProbes_LeaveStation_Movement:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Quest_InstallNatureProbes_WatchLiidiaLeave_Movement:
	delay_16
	face_right
	face_down
	step_end

gText_InstallNatureProbes_GeezIGottaWorkTonight::
	.string "Geez, I gotta work late tonight if I'm\n"
	.string "going to finish these reports and the\l"
	.string "install...\p"
	.string "Actually, you're a Trainer! Trainers are\n"
	.string "exploring places and shit, right?$"

gText_InstallNatureProbes_CanYouHelp::
	.string "Can you help me with something? I don't\n"
	.string "think it'll put you too far out of your\l"
	.string "way. I need to install three probes in\l"
	.string "Miurwoods for tracking Pokémon\l"
	.string "movement. One in the deepest part of\l"
	.string "the forest, one up on the tallest hill,\l"
	.string "and one over by the lakeshore.\l"
	.string "Installing is really easy, you just clip\l"
	.string "them to the sign posts that we've\l"
	.string "already got set up there.$"

gText_InstallNatureProbes_YouHaveAPokedex::
	.string "You've got a PokéDex? Great. I can\n"
	.string "upgrade it with the SanFran Habitat\l"
	.string "Mode if you help me out.$"

gText_InstallNatureProbes_WhatProbes::
	.string "What probes did you already install in\n"
	.string "Miurwoods?$"

gText_InstallNatureProbes_TheProbeInTheForest::
	.string "One probe goes in the deepest part of\n"
	.string "the forest.$"

gText_InstallNatureProbes_TheProbeOnTheHill::
	.string "One probe goes on the tallest hill.$"

gText_InstallNatureProbes_TheProbeByTheShore::
	.string "One probe goes by the lake shore.$"

gText_InstallNatureProbes_WowYouGotAll::
	.string "Wow! You got all of them in? Let's test\n"
	.string "that...$"

gText_InstallNatureProbes_TheTrackingIsWorking::
	.string "The tracking is working! You did great,\n"
	.string "thank you so much. Could I see your\l"
	.string "Pokédex please? Oh, this isn't the\l"
	.string "Sanfran model... Orre? Fascinating. It\l"
	.string "should work the same...$"

gText_InstallNatureProbes_ThatsMyBoss::
	.string "That's my boss, let me just answer that.$"

gText_InstallNatureProbes_GoForLiidia::
	.string "Go for Liidia!$"

gText_InstallNatureProbes_IUnderstand::
	.string "...I understand.$"

gText_InstallNatureProbes_HeThankedMe::
	.string "He thanked me... and then told me that\n"
	.string "my job was redundant. He told I'm fired,\l"
	.string "and have to leave the premises\l"
	.string "immediately.$"

gText_InstallNatureProbes_IRealizeNow::
	.string "I realize now, I think you put me out of\n"
	.string "a job. How could I be so... naive?$"

gText_InstallNatureProbes_YeahThisSeemsToMatch::
	.string "Yeah, this seems to match the\n"
	.string "description... deepest part of the\l"
	.string "forest.$"

gText_InstallNatureProbes_PlayerInstalledForest::
	.string "{PLAYER} installed the probe in the\n"
	.string "forest.$"

gText_InstallNatureProbes_ThisIsAsGoodOfAHill::
	.string "This is as good as a hill as I'm going to\n"
	.string "find, right?$"

gText_InstallNatureProbes_PlayerInstalledHill::
	.string "{PLAYER} installed the probe on the\n"
	.string "hill.$"

gText_InstallNatureProbes_JustGottaMakeSure::
	.string "Just gotta make sure its attached\n"
	.string "correctly...$"

gText_InstallNatureProbes_PlayerInstalledShore::
	.string "{PLAYER} installed the probe by the\n"
	.string "shore.$"

gText_InstallNatureProbes_ThereIsAProbe::
	.string "There is a probe attached to the sign\n"
	.string "post.$"

gText_InstallNatureProbes_OkayDone::
	.string "Okay, done!$"

gText_InstallNatureProbes_PokedexUpgradedWith::
	.string "{PLAYER}'s Pokédex was upgraded with\n"
	.string "Habitat Mode!$"
