Quest_Redomugging_Hide_Victim_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_eq Quest_Redomugging_Hide_Victim_Script_2
Quest_Redomugging_Hide_Victim_Script_1:
	return

Quest_Redomugging_Hide_Victim_Script_2:
	setflag FLAG_TEMP_1
	goto Quest_Redomugging_Hide_Victim_Script_1


Quest_Redomugging_Hide_Muggers_Script::
	setvar VAR_TEMP_0, 0
	compare VAR_ALCATRAZ_STATE, PRE_SPEECHSPEECH
	goto_if_gt Quest_Redomugging_Hide_Muggers_Script_2
Quest_Redomugging_Hide_Muggers_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_Redomugging_Hide_Muggers_Script_5
Quest_Redomugging_Hide_Muggers_Script_4:
	compare VAR_TEMP_0, 2
	goto_if_ne Quest_Redomugging_Hide_Muggers_Script_8
Quest_Redomugging_Hide_Muggers_Script_7:
	return

Quest_Redomugging_Hide_Muggers_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Redomugging_Hide_Muggers_Script_1

Quest_Redomugging_Hide_Muggers_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Redomugging_Hide_Muggers_Script_4

Quest_Redomugging_Hide_Muggers_Script_8:
	setflag FLAG_TEMP_3
	goto Quest_Redomugging_Hide_Muggers_Script_7


Quest_Redomugging_MovePlayer_Alcatraz_Script::
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 11, 14
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	turnobject 14, DIR_EAST
	TeleportCamera 11, 14
	fadescreen FADE_FROM_BLACK
	return


Quest_Redomugging_Interact_Script::
	lock
	returnqueststate QUEST_REDOMUGGING
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_Redomugging_Interact_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_Redomugging_Interact_Script_4
	case QUEST_MENU_SET_REWARD, Quest_Redomugging_Interact_Script_5
	call Quest_Redomugging_StartQuest_Dialogue
Quest_Redomugging_Interact_Script_1:
	release
	end

Quest_Redomugging_Interact_Script_3:
	call Quest_Redomugging_Active_Dialogue
	goto Quest_Redomugging_Interact_Script_1

Quest_Redomugging_Interact_Script_4:
	call Quest_Redomugging_Completed_Dialogue
	goto Quest_Redomugging_Interact_Script_1

Quest_Redomugging_Interact_Script_5:
	call Quest_Redomugging_Reward_Dialogue
	goto Quest_Redomugging_Interact_Script_1


Quest_Redomugging_StartQuest_Dialogue::
	call Quest_Redomugging_MovePlayer_Alcatraz_Script
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_WaitArentYou
	callnative ClearMugshot
	msgbox gText_Redomugging_OhHellNot
	callnative DrawMugshot
	msgbox gText_Redomugging_WaitDidIPick
	callnative ClearMugshot
	msgbox gText_Redomugging_NahWereStill
	callnative DrawMugshot
	msgbox gText_Redomugging_SinceWhenDo
	callnative ClearMugshot
	msgbox gText_Redomugging_ThePersonWe
	msgbox gText_Redomugging_WeCaughtThem
	msgbox gText_Redomugging_YeahWeWere
	callnative DrawMugshot
	msgbox gText_Redomugging_FramingYouGuys
	callnative ClearMugshot
	msgbox gText_Redomugging_ExactlyWeCant
	callnative DrawMugshot
	msgbox gText_Redomugging_IsItToo
	callnative ClearMugshot
	msgbox gText_Redomugging_MaybeNot
	msgbox gText_Redomugging_MaybeHeadDownTo
	closemessage
	startquest QUEST_REDOMUGGING
	return


Quest_Redomugging_Active_Dialogue::
	msgbox gText_Redomugging_AnyLuck, MSGBOX_NPC
	return


Quest_Redomugging_Interact_Victim_Script::
	lock
	returnqueststate QUEST_REDOMUGGING
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_Redomugging_Interact_Victim_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_Redomugging_Interact_Victim_Script_4
	call Quest_Redomugging_TooBusy_Dialogue
Quest_Redomugging_Interact_Victim_Script_1:
	closemessage
	release
	end

Quest_Redomugging_Interact_Victim_Script_3:
	call Quest_Redomugging_StealPhone_Dialogue
	goto Quest_Redomugging_Interact_Victim_Script_1

Quest_Redomugging_Interact_Victim_Script_4:
	call Quest_Redomugging_MissingPhone_Dialogue
	goto Quest_Redomugging_Interact_Victim_Script_1


Quest_Redomugging_TooBusy_Dialogue::
	msgbox gText_Redomugging_Sorry
	return


Quest_Redomugging_StealPhone_Dialogue::
	faceplayer
	msgbox gText_Redomugging_HeyThereHow
	closemessage
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 3
	msgbox gText_Redomugging_ChampionPlayer
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_YeahThatWasMe
	callnative ClearMugshot
	msgbox gText_Redomugging_WhatBringsYou
	callnative DrawMugshot
	msgbox gText_Redomugging_UhIWanted
	callnative ClearMugshot
	msgbox gText_Redomugging_WowYouReallyAre
	msgbox gText_Redomugging_WhileYoureHere
	closemessage
	fadescreen FADE_TO_BLACK
	delay 60
	setobjectxy OBJ_EVENT_ID_PLAYER, 12, 15
	TeleportCamera 12, 15
	turnobject 3, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	fadescreen FADE_FROM_BLACK
	msgbox gText_Redomugging_OhManThisIsGreat
	closemessage
	applymovement 3, Quest_Redomugging_LeaveRoom_Movement
	dofieldeffectsparkle 12, 14, 0
	waitfieldeffect FLDEFF_SPARKLE
	delay 10
	waitmovement 3
	removeobject 3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	dofieldeffectsparkle 12, 14, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_OkayGottaGrab
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement OBJ_EVENT_ID_PLAYER
	giveitem ITEM_FAME_CHECKER
	questmenu QUEST_MENU_SET_REWARD, QUEST_REDOMUGGING
	return


Quest_Redomugging_SpottedByReporter_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_REDOMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_Redomugging_SpottedByReporter_Script_2
Quest_Redomugging_SpottedByReporter_Script_1:
	release
	end

Quest_Redomugging_SpottedByReporter_Script_2:
	lock
	faceplayer
	msgbox gText_Redomugging_HeyWerentYouMid
	closemessage
	fadescreen FADE_TO_BLACK
	delay 30
	setobjectxy OBJ_EVENT_ID_PLAYER, 12, 15
	TeleportCamera 12, 15
	fadescreen FADE_FROM_BLACK
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_IGottaGet
	callnative ClearMugshot
	goto Quest_Redomugging_SpottedByReporter_Script_1


Quest_Redomugging_LeaveNewspaper_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_REDOMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_Redomugging_LeaveNewspaper_Script_2
Quest_Redomugging_LeaveNewspaper_Script_1:
	release
	end

Quest_Redomugging_LeaveNewspaper_Script_2:
	lock
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_INeedTo
	callnative ClearMugshot
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	closemessage
	goto Quest_Redomugging_LeaveNewspaper_Script_1


Quest_Redomugging_MissingPhone_Dialogue::
	msgbox gText_Redomugging_HeyYouDisappeared, MSGBOX_NPC
	return


Quest_Redomugging_Reward_Dialogue::
	call Quest_Redomugging_MovePlayer_Alcatraz_Script
	msgbox gText_Redomugging_YouDidAwesome
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Redomugging_Thanks
	callnative ClearMugshot
	msgbox gText_Redomugging_WellTakeThat
	closemessage
	msgbox gText_Redomugging_PlayerGave, MSGBOX_AUTOCLOSE
	removeitem ITEM_FAME_CHECKER
	msgbox gText_Redomugging_AwesomeWellGive
	closemessage
	applymovement 14, Quest_Redomugging_WalkOffScreen_Movement
	completequest QUEST_REDOMUGGING
	waitmovement 14
	removeobject 14
	return


Quest_Redomugging_Completed_Dialogue::
	msgbox gText_Redomugging_EvenBetterThan, MSGBOX_NPC
	return


Quest_Redomugging_LeaveRoom_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Quest_Redomugging_WalkOffScreen_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_Redomugging_WaitArentYou::
	.string "Wait, aren't you the muggers from SOMA?$"

gText_Redomugging_OhHellNot::
	.string "Oh hell, not again.$"

gText_Redomugging_WaitDidIPick::
	.string "Wait, did I pick the wrong side? There's\n"
	.string "no way Teamrocket is intentionally\l"
	.string "working with muggers.$"

gText_Redomugging_NahWereStill::
	.string "Nah, we're still the good guys, you just\n"
	.string "got it twisted.$"

gText_Redomugging_SinceWhenDo::
	.string "Since when do the good guys mug people\n"
	.string "for their phones?$"

gText_Redomugging_ThePersonWe::
	.string "The person we stole that phone from...\n"
	.string "they're a reporter. They're about to\l"
	.string "release a story about those riots in\l"
	.string "Tenderloin... but they got it all wrong.$"

gText_Redomugging_WeCaughtThem::
	.string "Our tech guys were able to see some of\n"
	.string "the stuff they were cooking up, and its\l"
	.string "crazy! They're saying we started the\l"
	.string "riot just to cause chaos and some\l"
	.string "other bullshit.$"

gText_Redomugging_YeahWeWere::
	.string "Without their phone, they can't log into\n"
	.string "their servers to work on the story, so\l"
	.string "we were going to steal it and hope that\l"
	.string "our guys could just wipe all their work.$"

gText_Redomugging_FramingYouGuys::
	.string "Hmm. Getting the story wrong seems to\n"
	.string "be normal for the news around here.$"

gText_Redomugging_ExactlyWeCant::
	.string "Exactly! We can't go back to SOMA now\n"
	.string "though, and that story is gonna drop\l"
	.string "any day now.$"

gText_Redomugging_IsItToo::
	.string "...is it too crazy to send somebody\n"
	.string "else? Could I try to grab it?$"

gText_Redomugging_MaybeNot::
	.string "Maybe not?$"

gText_Redomugging_MaybeHeadDownTo::
	.string "Maybe head to the newspaper in SOMA\n"
	.string "and see if you can get in a room with\l"
	.string "the reporter. Let us know if you get\l"
	.string "lucky!$"

gText_Redomugging_AnyLuck::
	.string "Any luck getting that phone?$"

gText_Redomugging_Sorry::
	.string "Sorry, I have to meet this deadline...$"

gText_Redomugging_HeyThereHow::
	.string "Hey there, how can I -$"

gText_Redomugging_ChampionPlayer::
	.string "Champion {PLAYER}! You're here! And\n"
	.string "you're the one that saved me from\l"
	.string "those muggers too. I keep telling\l"
	.string "everybody it was you, and nobody\l"
	.string "believes me.$"

gText_Redomugging_YeahThatWasMe::
	.string "Yeah, that was me.$"

gText_Redomugging_WhatBringsYou::
	.string "What are you doing here? Celebrities\n"
	.string "usually don't waltz into newspapers.$"

gText_Redomugging_UhIWanted::
	.string "Uh, I wanted to check on you! Make sure\n"
	.string "you were okay after that mugging. I\l"
	.string "know people get shaken up.$"

gText_Redomugging_WowYouReallyAre::
	.string "Wow! You really are the best. I was a\n"
	.string "little rattled, but I got my phone back\l"
	.string "and got away while you battled them.\l"
	.string "All is well!$"

gText_Redomugging_WhileYoureHere::
	.string "While you're here, how about an\n"
	.string "interview? I see you're publicly\l"
	.string "supporting Teamrocket, and I'd love to\l"
	.string "pick your brain!$"

gText_Redomugging_OhManThisIsGreat::
	.string "Oh man, this is so juicy! Okay, I gotta\n"
	.string "run to the restroom, but don't go\l"
	.string "anywhere,okay?$"

gText_Redomugging_OkayGottaGrab::
	.string "They left their phone! Perfect, let's\n"
	.string "grab it, turn it off, and get out of\l"
	.string "here.$"

gText_Redomugging_HeyWerentYouMid::
	.string "Hey, weren't you like, mid-interview?$"

gText_Redomugging_IGottaGet::
	.string "I need to get out of here without being\n"
	.string "seen...$"

gText_Redomugging_INeedTo::
	.string "I gotta get this reporter's phone to\n"
	.string "Alcatraz!$"

gText_Redomugging_HeyYouDisappeared::
	.string "Hey, you disappeared! I figured you got\n"
	.string "busy, totally fine. Sucks though, I\l"
	.string "seem to have misplaced my phone... I'm\l"
	.string "so absentminded!$"

gText_Redomugging_YouDidAwesome::
	.string "You did awesome, oh man!$"

gText_Redomugging_Thanks::
	.string "Thanks!$"

gText_Redomugging_WellTakeThat::
	.string "We'll take that off your hands...$"

gText_Redomugging_PlayerGave::
	.string "{PLAYER} gave the reporter's phone\n"
	.string "to Teamrocket.$"

gText_Redomugging_AwesomeWellGive::
	.string "Awesome, we'll give this to our guys and\n"
	.string "see if they stop this story from\l"
	.string "getting out.$"

gText_Redomugging_EvenBetterThan::
	.string "Even better than we expected - our\n"
	.string "guys were able to use that phone to\l"
	.string "wipe out all that guys shitty work.\l"
	.string "That interview about you is also gone,\l"
	.string "no worries.$"
