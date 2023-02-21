WowYoureStrong_HideObject_Script::
	goto_if_unset FLAG_BADGE03_GET, WowYoureStrong_HideObject_Script_2
	compare VAR_SOMA_STATE, DEFEATED_WHITNEY
	goto_if_gt WowYoureStrong_HideObject_Script_2
WowYoureStrong_HideObject_Script_1:
	compare VAR_PSFROUTE9_STATE, SAVED_BEFORE_ARCHER_PSFROUTE9
	goto_if_eq WowYoureStrong_HideObject_Script_6
	return

WowYoureStrong_HideObject_Script_2:
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_6
	goto WowYoureStrong_HideObject_Script_1

WowYoureStrong_HideObject_Script_6:
	setflag FLAG_TEMP_6
	return


WowYoureStrong_WalkToPlayer_Script::
	lockall
	setvar VAR_SOMA_STATE, POST_WOW_YOURE_STRONG
	playse SE_PIN
	playbgm MUS_RG_ENCOUNTER_DEOXYS, TRUE
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	applymovement 1, WowYoureStrong_WalkToPlayer_Movement
	waitmovement 1
	setobjectxyperm 1, 28, 25
	goto WowYoureStrong_Intro_Dialogue
	return


WowYoureStrong_Intro_Dialogue::
	msgbox gText_WowYoureStrong_WhatAShow, , SPEAKER_ROSE
	msgbox gText_WowYoureStrong_OhUhThanksALot, , SPEAKER_ZOEY
	msgbox gText_WowYoureStrong_WhereMyManners, , SPEAKER_ROSE
	msgbox gText_WowYoureStrong_ShouldHaveKnown, , SPEAKER_ZOEY
	msgbox gText_WowYoureStrong_DreamBig, , SPEAKER_ROSE
	goto WowYoureStrong_ShowTower_Script
	return


WowYoureStrong_ShowTower_Script::
	fadescreen FADE_TO_BLACK
	TeleportCamera 7, 14
	special SpawnCameraObject
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, WowYoureStrong_PanCameraUp_Movement
	msgbox gText_WowYoureStrong_YouShouldComeBy, , SPEAKER_ROSE
	waitmovement OBJ_EVENT_ID_CAMERA
	closemessage
	fadescreen FADE_TO_BLACK
	TeleportCamera 28, 24
	special RemoveCameraObject
	fadescreen FADE_FROM_BLACK
	goto WowYoureStrong_End_Dialouge
	return


WowYoureStrong_End_Dialouge::
	msgbox gText_WowYoureStrong_MeetingWithMayor, , SPEAKER_ROSE
	closemessage
	applymovement 1, WowYoureStrong_WalkToMayor_Movement
	waitmovement 1
	removeobject 1
	playbgm MUS_RG_VERMILLION, TRUE
	compare VAR_PSFROUTE9_STATE, SAVED_BEFORE_ARCHER_PSFROUTE9
	goto_if_eq WowYoureStrong_End_Dialouge_2
	goto WowYourStrong_ArcherConfrontation_Dialogue
	return

WowYoureStrong_End_Dialouge_2:
	release
	end


WowYourStrong_ArcherConfrontation_Dialogue::
	applymovement 10, WowYoureStrong_ArcherToPlayer_Movement
	waitmovement 10
	msgbox gText_WowYoureStrong_IDontGetIt, , SPEAKER_ARCHER
	compare VAR_PSFROUTE9_STATE, DEFEATED_ARCHER_PSFROUTE9
	goto_if_eq WowYourStrong_ArcherConfrontation_Dialogue_2
	msgbox gText_WowYoureStrong_WhatAreYouTalking, , SPEAKER_ZOEY
WowYourStrong_ArcherConfrontation_Dialogue_1:
	msgbox gText_WowYoureStrong_IJustCant, , SPEAKER_ARCHER
	closemessage
	applymovement 10, WowYoureStrong_WalkToMayor_Movement
	waitmovement 10
	removeobject 10
	compare VAR_PSFROUTE9_STATE, DEFEATED_ARCHER_PSFROUTE9
	goto_if_eq WowYourStrong_ArcherConfrontation_Dialogue_6
	msgbox gText_WowYoureStrong_ThisRegionHasSome, , SPEAKER_ZOEY
WowYourStrong_ArcherConfrontation_Dialogue_5:
	closemessage
	release
	end

WowYourStrong_ArcherConfrontation_Dialogue_2:
	msgbox gText_WowYoureStrong_YouAgain, , SPEAKER_ZOEY
	goto WowYourStrong_ArcherConfrontation_Dialogue_1

WowYourStrong_ArcherConfrontation_Dialogue_6:
	msgbox gText_WowYoureStrong_IHopeThats, , SPEAKER_ZOEY
	goto WowYourStrong_ArcherConfrontation_Dialogue_5


WowYoureStrong_WalkToPlayer_Movement:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	face_up
	step_end

WowYoureStrong_PanCameraUp_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

WowYoureStrong_WalkToMayor_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WowYoureStrong_ArcherToPlayer_Movement:
	walk_up
	walk_up
	walk_right
	walk_right
	face_up
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
	.string "on the 38th floor.$"

gText_WowYoureStrong_MeetingWithMayor::
	.string "I have to run to a meeting with the\n"
	.string "Mayor. Again, excellent job against\l"
	.string "Whitney. I hope to see what else you\l"
	.string "can do!$"

gText_WowYoureStrong_IDontGetIt::
	.string "I don't get it. Do all of you transplants\n"
	.string "just worship the ground these tycoons\l"
	.string "walk on?$"

gText_WowYoureStrong_YouAgain::
	.string "You again? Are you following me? What is\n"
	.string "your deal?$"

gText_WowYoureStrong_WhatAreYouTalking::
	.string "What are you talking about?$"

gText_WowYoureStrong_IJustCant::
	.string "I just can't understand why you would\n"
	.string "willingly buy into a system that just\l"
	.string "makes these people more money. Do you\l"
	.string "think they need MORE money?$"

gText_WowYoureStrong_IHopeThats::
	.string "I hope that this isn't going to be a\n"
	.string "regular thing...$"

gText_WowYoureStrong_ThisRegionHasSome::
	.string "The region has some... characters.$"
