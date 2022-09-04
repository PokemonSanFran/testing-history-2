Quest_ChinatownTunnels_HideTreasure_Script::
	setflag FLAG_TEMP_2
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CHINATOWNTUNNELS
	compare VAR_RESULT, 0
	goto_if_ne Quest_ChinatownTunnels_HideTreasure_Script_1
	return

Quest_ChinatownTunnels_HideTreasure_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_ChinatownTunnels_Event_Script::
	returnqueststate QUEST_CULTURALPURITY
	switch VAR_RESULT
	case QUEST_MENU_COMPLETE_QUEST, Quest_ChinatownTunnels_Event_Script_3
	case QUEST_MENU_CHECK_ACTIVE, Quest_ChinatownTunnels_Event_Script_4
	msgbox gText_Chinatown_IMissTheOld, MSGBOX_NPC
Quest_ChinatownTunnels_Event_Script_1:
	release
	end

Quest_ChinatownTunnels_Event_Script_3:
	msgbox gText_Quest_ChinatownTunnels_ICannotThank, MSGBOX_NPC
	goto Quest_ChinatownTunnels_Event_Script_1

Quest_ChinatownTunnels_Event_Script_4:
	goto Quest_ChinatownTunnels_Active_Event_Script
	goto Quest_ChinatownTunnels_Event_Script_1


Quest_ChinatownTunnels_Active_Event_Script::
	switch VAR_QUEST_CHINATOWN_TUNNELS
	case NEVER_SPOKEN_ELDER, Quest_ChinatownTunnels_Active_Event_Script_2
	case SPOKEN_ELDER_FIRST_TIME, Quest_ChinatownTunnels_Active_Event_Script_3
	case SENT_TO_FIND_RED_SCROLL, Quest_ChinatownTunnels_Active_Event_Script_4
	case FOUND_RED_SCROLL, Quest_ChinatownTunnels_Active_Event_Script_5
	return

Quest_ChinatownTunnels_Active_Event_Script_2:
	goto Quest_ChinatownTunnels_Intro_Dialogue
	return

Quest_ChinatownTunnels_Active_Event_Script_3:
	goto Quest_ChinatownTunnels_BadgeCheck_Dialogue
	return

Quest_ChinatownTunnels_Active_Event_Script_4:
	goto Quest_ChinatownTunnels_WaitingScroll_Dialogue
	return

Quest_ChinatownTunnels_Active_Event_Script_5:
	goto Quest_ChinatownTunnels_WaitingScroll_Dialogue
	return


Quest_ChinatownTunnels_Intro_Dialogue::
	lock
	msgbox gText_Quest_ChinatownTunnels_OhoHowCanIHelp, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ChinatownTunnels_IHeardOnlineThatYou, MSGBOX_NPC
	callnative ClearMugshot
	addvar VAR_QUEST_CHINATOWN_TUNNELS, 1
	goto Quest_ChinatownTunnels_BadgeCheck_Dialogue
	return


Quest_ChinatownTunnels_BadgeCheck_Dialogue::
	lock
	special GetNumberOfBadges
	compare VAR_TEMP_0, 3
	goto_if_gt Quest_ChinatownTunnels_BadgeCheck_Dialogue_2
	msgbox gText_Quest_ChinatownTunnels_YoureNotStrongEnough, MSGBOX_NPC
Quest_ChinatownTunnels_BadgeCheck_Dialogue_1:
	release
	end

Quest_ChinatownTunnels_BadgeCheck_Dialogue_2:
	goto Quest_ChinatownTunnels_RevealSecret_Dialogue
	goto Quest_ChinatownTunnels_BadgeCheck_Dialogue_1


Quest_ChinatownTunnels_RevealSecret_Dialogue::
	addvar VAR_QUEST_CHINATOWN_TUNNELS, 1
	msgbox gText_Quest_ChinatownTunnels_HmmYouLookStrong, MSGBOX_NPC
	closemessage
	applymovement 8, Common_Movement_FaceAwayPlayer
	waitmovement 8
	delay 16
	applymovement 8, Common_Movement_FacePlayer
	waitmovement 8
	msgbox gText_Quest_ChinatownTunnels_YouveHeardCorrectly, MSGBOX_NPC
	closemessage
	release
	end


Quest_ChinatownTunnels_FirstScrollWarp_Script::
	lock
	call Chinatown_Racisthouse_ScrollNoWarp_Dialogue
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ChinatownTunnels_WaitIsThis, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Quest_ChinatownTunnels_PushScroll_Movement
	delay 4
	playse SE_PIN
	waitmovement OBJ_EVENT_ID_PLAYER
	msgbox gText_Quest_ChinatownTunnels_TheresNoWall, MSGBOX_DEFAULT
	addvar VAR_QUEST_CHINATOWN_TUNNELS, 1
	goto Chinatown_Racisthouse_ScrollWarp_Script
	return


Quest_ChinatownTunnels_WaitingScroll_Dialogue::
	msgbox gText_Quest_ChinatownTunnels_HaveYou, MSGBOX_NPC
	end


Quest_ChinatownTunnels_Treasure_Script::
	lock
	msgbox gText_Quest_ChinatownTunnels_ThereIsAnOrnate, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ChinatownTunnels_ThisMustBe, MSGBOX_DEFAULT
	callnative ClearMugshot
	msgbox gText_Quest_ChinatownTunnels_ThatWontBe, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_TEMP_2
	addobject 2
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 6
	goto_if_ne Quest_ChinatownTunnels_Treasure_Script_2
Quest_ChinatownTunnels_Treasure_Script_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitse
	applymovement 2, Quest_ChinatownTunnels_WalkToPlayer_Movement
	waitmovement 2
	msgbox gText_Quest_ChinatownTunnels_ThankYouFor, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ChinatownTunnels_NoProblemThisBox, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_ChinatownTunnels_IMayHaveMislead, MSGBOX_NPC
	closemessage
	applymovement 2, Quest_ChinatownTunnels_TakeTreasure_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Quest_ChinatownTunnels_MoveWhileTreasure_Movement
	delay 16
	delay 16
	removeobject 1
	playse SE_CLICK
	waitse
	waitmovement 2
	playse SE_PIN
	waitse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_ChinatownTunnels_YouHad, MSGBOX_DEFAULT
	callnative ClearMugshot
	applymovement 2, Common_Movement_FaceLeft
	msgbox gText_Quest_ChinatownTunnels_IUsedToLiveHere, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Common_Movement_FaceLeft
	waitmovement 2
	msgbox gText_Quest_ChinatownTunnels_IAsked, MSGBOX_DEFAULT
	closemessage
	applymovement 2, Quest_ChinatownTunnels_LeaveTunnel_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 2
	removeobject 2
	completequest QUEST_CHINATOWNTUNNELS
	release
	end

Quest_ChinatownTunnels_Treasure_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Quest_ChinatownTunnels_MoveToTreasureFront_Movement
	waitmovement OBJ_EVENT_ID_PLAYER
	goto Quest_ChinatownTunnels_Treasure_Script_1


Quest_ChinatownTunnels_PushScroll_Movement:
	walk_in_place_up
	emote_exclamation_mark
	step_end

Quest_ChinatownTunnels_LeaveTunnel_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Quest_ChinatownTunnels_TakeTreasure_Movement:
	walk_up
	walk_in_place_up
	step_end

Quest_ChinatownTunnels_WalkToPlayer_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Quest_ChinatownTunnels_MoveToTreasureFront_Movement:
	walk_down
	walk_right
	step_end

Quest_ChinatownTunnels_MoveWhileTreasure_Movement:
	walk_left
	face_right
	step_end

gText_Quest_ChinatownTunnels_IAsked::
	.string "I asked one of the children in town to\n"
	.string "post a story about hidden treasure,\l"
	.string "hoping somebody strong could help me\l"
	.string "get in here. I tried to reason with\l"
	.string "these thugs, but as you know, they\l"
	.string "don't like to listen. Your kindness will\l"
	.string "not be forgotten. Thank you so much,\l"
	.string "young Trainer.$"

gText_Quest_ChinatownTunnels_IMayHaveMislead::
	.string "I may have mislead you. I'm sorry.$"

gText_Quest_ChinatownTunnels_IUsedToLiveHere::
	.string "I used to live here. I didn't dig this\n"
	.string "tunnel though - it was always here. I\l"
	.string "used it for storage away from my wife,\l"
	.string "haha! When I was drafted many years\l"
	.string "ago, I lost my home and while I was\l"
	.string "gone, I lost my family. When I returned,\l"
	.string "my home had been taken, and access to\l"
	.string "the tunnel was gone. My treasure is\l"
	.string "simple... photos of my family. Its all I\l"
	.string "have left of them.$"

gText_Quest_ChinatownTunnels_NoProblemThisBox::
	.string "No problem. This box is locked though.\n"
	.string "We have to find the key.$"

gText_Quest_ChinatownTunnels_ThankYouFor::
	.string "Thank you for dealing with those thugs.\n"
	.string "I was able to follow you inside.$"

gText_Quest_ChinatownTunnels_ThatWontBe::
	.string "That won't be neccesary.$"

gText_Quest_ChinatownTunnels_ThereIsAnOrnate::
	.string "This is an ornate box on the ground.\n"
	.string "There is clearly something inside, but\l"
	.string "it is locked.$"

gText_Quest_ChinatownTunnels_ThisMustBe::
	.string "This must be the treasure! Ugh, do I\n"
	.string "have to find a key too?$"

gText_Quest_ChinatownTunnels_YouHad::
	.string "You had the key the entire time?$"

gText_Quest_ChinatownTunnels_OhoHowCanIHelp::
	.string "Oho, how can I help you, lad?$"

gText_Quest_ChinatownTunnels_IHeardOnlineThatYou::
	.string "I heard there's a secret treasure\n"
	.string "hidden in this town. Do you know\l"
	.string "anything about that?$"

gText_Quest_ChinatownTunnels_YoureNotStrongEnough::
	.string "You're not strong enough for this\n"
	.string "treasure. Come back after you've got 4\l"
	.string "badges.$"

gText_Quest_ChinatownTunnels_HmmYouLookStrong::
	.string "Hmm, you look strong enough for the\n"
	.string "task.$"

gText_Quest_ChinatownTunnels_YouveHeardCorrectly::
	.string "You've heard correctly. There are\n"
	.string "secret tunnels under the city, and\l"
	.string "hidden in them is a treasure greater\l"
	.string "than anybody knows. Of course, I'm too\l"
	.string "old to go get it now. Find it, and I'll\l"
	.string "split it with you. The entrance is\l"
	.string "guarded by a red scroll, but I don't\l"
	.string "remember where that is...$"

gText_Quest_ChinatownTunnels_WaitIsThis::
	.string "Wait, is this the red scroll that guy was\n"
	.string "talking about...?$"

gText_Quest_ChinatownTunnels_TheresNoWall::
	.string "There's no wall behind the scroll!$"

gText_Quest_ChinatownTunnels_HaveYou::
	.string "Have you had any luck finding the red\n"
	.string "scroll?$"

gText_Quest_ChinatownTunnels_ICannotThank::
	.string "I cannot thank you enough.$"
