Quest_ChinatownTunnels_Event_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_CHINATOWNTUNNELS
	compare VAR_RESULT, 0
	goto_if_ne Quest_ChinatownTunnels_Event_Script_2
Quest_ChinatownTunnels_Event_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CHINATOWNTUNNELS
	compare VAR_RESULT, 0
	goto_if_ne Quest_ChinatownTunnels_Event_Script_4
	return

Quest_ChinatownTunnels_Event_Script_2:
	goto Quest_ChinatownTunnels_Active_Event_Script
	goto Quest_ChinatownTunnels_Event_Script_1

Quest_ChinatownTunnels_Event_Script_4:
	return


Quest_ChinatownTunnels_Active_Event_Script::
	switch VAR_QUEST_CHINATOWN_TUNNELS
	case 0, Quest_ChinatownTunnels_Active_Event_Script_2
	case 1, Quest_ChinatownTunnels_Active_Event_Script_3
	return

Quest_ChinatownTunnels_Active_Event_Script_2:
	goto Quest_ChinatownTunnels_Intro_Dialogue
	return

Quest_ChinatownTunnels_Active_Event_Script_3:
	goto Quest_ChinatownTunnels_BadgeCheck_Dialogue
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


Chinatown_Racisthouse_ScrollWarp_Script::
	lock
	warpsilent MAP_CHINATOWN_TUNNEL, 1
	release
	end


Quest_ChinatownTunnels_PushScroll_Movement:
	walk_in_place_up
	emote_exclamation_mark
	step_end

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
