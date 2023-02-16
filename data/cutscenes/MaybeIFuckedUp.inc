MaybeIFuckedUp_ShowOri_Script::
	compare VAR_STORYLINE_STATE, STORY_CONGRATULATED_BY_ROSE
	goto_if_ne MaybeIFuckedUp_ShowOri_Script_1
	return

MaybeIFuckedUp_ShowOri_Script_1:
	setflag FLAG_TEMP_6
	return


MaybeIFuckedUp_Dialogue::
	lock
	setvar VAR_STORYLINE_STATE, STORY_RECIEVED_BAMBOO_STAR
	applymovement 12, MaybeIFuckedUp_WalkToPlayer
	waitmovement 0
	msgbox gText_MaybeIFuckedUp_ExcuseMeLad, , SPEAKER_ORI
	closemessage
	applymovement 12, Common_Movement_WalkUp
	waitmovement 0
	msgbox gText_MaybeIFuckedUp_OhHi, , SPEAKER_ZOEY
	callnative ClearMugshot
	msgbox gText_MaybeIFuckedUp_ItsGoodToMeetYou, , SPEAKER_ORI
	msgbox gText_MaybeIFuckedUp_ItHasBeenACrazy, , SPEAKER_ZOEY
	callnative ClearMugshot
	msgbox gText_MaybeIFuckedUp_YourDecisions, , SPEAKER_ORI
	giveitem ITEM_METEORITE, 1
	msgbox gText_MaybeIFuckedUp_AskYourself, , SPEAKER_ORI
	msgbox gText_MaybeIFuckedUp_IfYouFindYourself, , SPEAKER_ORI
	msgbox gText_MaybeIFuckedUp_UhOkay, , SPEAKER_ZOEY
	callnative ClearMugshot
	msgbox gText_MaybeIFuckedUp_OfCourse, , SPEAKER_ORI
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MaybeIFuckedUp_WatchOriWalk
	applymovement 12, MaybeIFuckedUp_WalkOffScreen
	waitmovement 12
	removeobject 12
	msgbox gText_MaybeIFuckedUp_WhatTheHellWasThat, , SPEAKER_ZOEY
	callnative ClearMugshot
	release
	end


MaybeIFuckedUp_WalkToPlayer:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	face_up
	step_end

MaybeIFuckedUp_WalkOffScreen:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MaybeIFuckedUp_WatchOriWalk:
	delay_16
	delay_16
	delay_16
	face_right
	step_end

gText_MaybeIFuckedUp_ExcuseMeLad::
	.string "Excuse me, lad.$"

gText_MaybeIFuckedUp_OhHi::
	.string "Oh hi!$"

gText_MaybeIFuckedUp_ItsGoodToMeetYou::
	.string "It’s good to meet you, Champion\n"
	.string "{PLAYER}. You’ve had quite an impact\l"
	.string "since you arrived here, don’t you think?$"

gText_MaybeIFuckedUp_ItHasBeenACrazy::
	.string "It has been a crazy ride…$"

gText_MaybeIFuckedUp_YourDecisions::
	.string "Your decisions have had a great impact…\n"
	.string "but not everything is always\l"
	.string "permanent. Take this.$"

gText_MaybeIFuckedUp_AskYourself::
	.string "Ask yourself -$"

gText_MaybeIFuckedUp_IfYouFindYourself::
	.string "If you find yourself having regrets\n"
	.string "about the path you’ve chosen, bring\l"
	.string "that to the highest point in the\l"
	.string "region. I have a friend who can help\l"
	.string "you.$"

gText_MaybeIFuckedUp_UhOkay::
	.string "Uh… okay? Thanks, I guess.$"

gText_MaybeIFuckedUp_OfCourse::
	.string "Of course, my child.$"

gText_MaybeIFuckedUp_WhatTheHellWasThat::
	.string "(...what the hell was that? And where’s\n"
	.string "the tallest point?)$"
