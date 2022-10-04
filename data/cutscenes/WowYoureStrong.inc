WowYoureStrong_HideObject_Script::
	goto_if_unset FLAG_BADGE03_GET, WowYoureStrong_HideObject_Script_1
	compare VAR_SOMA_STATE, 1
	goto_if_gt WowYoureStrong_HideObject_Script_1
	return

WowYoureStrong_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return


WowYoureStrong_WalkToPlayer_Script::
	lockall
	setvar VAR_SOMA_STATE, 2
	playse SE_PIN
	playbgm MUS_RG_ENCOUNTER_DEOXYS, TRUE
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, WowYoureStrong_WalkToPlayer_Movement
	waitmovement 0
	goto WowYoureStrong_Intro_Dialogue
	return


WowYoureStrong_Intro_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_WhatAShow
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_OhUhThanksALot
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_WhereMyManners
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_ShouldHaveKnown
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_DreamBig
	callnative ClearMugshot
	goto WowYoureStrong_ShowTower_Script
	return


WowYoureStrong_ShowTower_Script::
	fadescreen FADE_TO_BLACK
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_YouShouldComeBy
	callnative ClearMugshot
	fadescreen FADE_FROM_BLACK
	goto WowYoureStrong_End_Dialouge
	return


WowYoureStrong_End_Dialouge::
	callnative DrawMugshot
	msgbox gText_WowYoureStrong_MeetingWithMayor
	callnative ClearMugshot
	closemessage
	applymovement 1, PsfBadbossWalkToMayor_Movement
	waitmovement 0
	removeobject 1
	playbgm MUS_RG_VERMILLION, TRUE
	releaseall
	end


WowYoureStrong_WalkToPlayer_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

PsfBadbossWalkToMayor_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

gText_WowYoureStrong_WhatAShow::
	.string "{PLAYER}! What a show! That was\n"
	.string "marvelous! Flying you in from Orre was\l"
	.string "absolutely worth it, for that battle\l"
	.string "alone.$"

gText_WowYoureStrong_OhUhThanksALot::
	.string "Oh uh, thanks a lot, that's very nice. I'm\n"
	.string "guessing you work at YCombinator…?$"

gText_WowYoureStrong_WhereMyManners::
	.string "Hah! Oh my, I'm sorry. Where are my\n"
	.string "manners? My name is Rose, and I'm the\l"
	.string "YCombinator League Commissioner,\l"
	.string "appointed by our corporate sponsors,\l"
	.string "Twitter, Amazon, and Uber.$"

gText_WowYoureStrong_ShouldHaveKnown::
	.string "Oh! I guess I should have known that.\n"
	.string "Well um, thanks so much for the\l"
	.string "opportunity! I'm excited to be the\l"
	.string "region's next Champion.$"

gText_WowYoureStrong_DreamBig::
	.string "Dream big {PLAYER}! That's the\n"
	.string "attitude we wanna see. We're big\l"
	.string "dreamers over at YCombinator too.\l"
	.string "That's why we built the Salesforce\l"
	.string "Tower!$"

gText_WowYoureStrong_YouShouldComeBy::
	.string "You should come by once you're done\n"
	.string "exploring the city proper, my office is\l"
	.string "on the 10th floor.$"

gText_WowYoureStrong_MeetingWithMayor::
	.string "I have to run to a meeting with the\n"
	.string "Mayor. Again, excellent job against\l"
	.string "Whitney. I hope to see what else you\l"
	.string "can do!$"
