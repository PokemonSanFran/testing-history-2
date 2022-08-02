Quest_BlueRobbery_HideObject_Script::
	setflag FLAG_TEMP_1
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BLUEROBBERRY
	compare VAR_RESULT, 0
	goto_if_ne Quest_BlueRobbery_HideObject_Script_1
	return

Quest_BlueRobbery_HideObject_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_BlueRobbery_Restaurant_HideObject_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BLUEROBBERRY
	compare VAR_RESULT, 0
	goto_if_eq Quest_BlueRobbery_Restaurant_HideObject_Script_1
	return

Quest_BlueRobbery_Restaurant_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_BlueRobbery_FakeRobber_Event_Script::
	lock
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_BLUEROBBERRY
	compare VAR_RESULT, 0
	goto_if_ne Quest_BlueRobbery_FakeRobber_Event_Script_2
Quest_BlueRobbery_FakeRobber_Event_Script_1:
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BLUEROBBERRY
	compare VAR_RESULT, 0
	goto_if_ne Quest_BlueRobbery_FakeRobber_Event_Script_5
Quest_BlueRobbery_FakeRobber_Event_Script_4:
	release
	end

Quest_BlueRobbery_FakeRobber_Event_Script_2:
	call Quest_BlueRobbery_FakeRobber_Dialogue
	goto Quest_BlueRobbery_FakeRobber_Event_Script_1

Quest_BlueRobbery_FakeRobber_Event_Script_5:
	goto Quest_BlueRobbery_PreBattle_Dialogue
	goto Quest_BlueRobbery_FakeRobber_Event_Script_4


Quest_BlueRobbery_FakeRobber_Dialogue::
	msgbox gText_BlueRobbery_ILoveMyWobbuffet, MSGBOX_NPC
	applymovement 1, BlueRobbery_FaceLove_Movement
	playse SE_BIKE_HOP
	applymovement 2, BlueRobbery_FaceHop_Movement
	waitse
	waitmovement 0
	playmoncry SPECIES_WOBBUFFET, CRY_MODE_ENCOUNTER
	msgbox gText_BlueRobbery_Wobb, MSGBOX_AUTOCLOSE
	waitmoncry
	release
	end


Quest_BlueRobbery_PreBattle_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BlueRobbery_IThinkThat
	msgbox gText_BlueRobbery_BoldOfYou, MSGBOX_DEFAULT
	callnative ClearMugshot
	msgbox gText_BlueRobbery_OhArceus, MSGBOX_NPC
	callnative DrawMugshot
	msgbox gText_BlueRobbery_HowCanYou, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_BlueRobbery_ItsNot, MSGBOX_NPC
	callnative DrawMugshot
	msgbox gText_BlueRobbery_LikelyStory, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	trainerbattle_no_intro TRAINER_FAKEROBBER, gText_BlueRobbery_LeaveMeAlone
	goto Quest_BlueRobbery_PostBattle_Script
	return


Quest_BlueRobbery_PostBattle_Script::
	lock
	playse SE_BALL_OPEN
	waitse
	setflag FLAG_TEMP_2
	removeobject 2
	clearflag FLAG_TEMP_1
	msgbox gText_BlueRobbery_AreYouHappy, MSGBOX_NPC
	callnative DrawMugshot
	msgbox gText_BlueRobbery_IDontUnderstand, MSGBOX_NPC
	callnative ClearMugshot
	addobject 3
	applymovement OBJ_EVENT_ID_PLAYER, BlueRobbery_GetOutOfWay_Movement
	applymovement 3, BlueRobbery_WalkToArrest_Movement
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject 3
	removeobject 1
	removeobject 2
	fadescreen FADE_FROM_BLACK
	completequest QUEST_BLUEROBBERRY
	release
	end


Quest_BlueRobbery_DinnerBrag_Dialogue::
	lock
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox gText_BlueRobbery_SoTwitterGot
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox gText_BlueRobbery_YeahAndThen
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox gText_BlueRobbery_InsaneSoTheHeat
	applymovement 3, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox gText_BlueRobbery_OffScotFree
	closemessage
	release
	end


BlueRobbery_FaceLove_Movement:
	face_right
	emote_heart
	step_end

BlueRobbery_FaceHop_Movement:
	face_left
	jump_in_place_left
	step_end

BlueRobbery_GetOutOfWay_Movement:
	walk_up
	face_down
	step_end

BlueRobbery_GetOutOfWayLeft_Movement:
	walk_right
	walk_up
	step_end

BlueRobbery_WalkToArrest_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

gText_BlueRobbery_ILoveMyWobbuffet::
	.string "I love my Wobbuffet so much!$"

gText_BlueRobbery_Wobb::
	.string "Wobb!$"

gText_BlueRobbery_IThinkThat::
	.string "(I think thats the person from Twitter!\n"
	.string "The thief!)$"

gText_BlueRobbery_BoldOfYou::
	.string "Bold of you to just be out and about.\n"
	.string "Are you serious?$"

gText_BlueRobbery_OhArceus::
	.string "Oh Arceus, another one? I'm telling you,\n"
	.string "I didn't steal shit!$"

gText_BlueRobbery_HowCanYou::
	.string "How can you say that? There's video!$"

gText_BlueRobbery_ItsNot::
	.string "It's not me! I don't even go to\n"
	.string "Tenderloin!$"

gText_BlueRobbery_LikelyStory::
	.string "Likely story. I hate when people think\n"
	.string "they can do whatever they want.$"

gText_BlueRobbery_LeaveMeAlone::
	.string "Leave me alone!$"

gText_BlueRobbery_AreYouHappy::
	.string "Are you happy now? Attacking innocent\n"
	.string "people because Twitter said so?$"

gText_BlueRobbery_IDontUnderstand::
	.string "I don't understand why you thought\n"
	.string "this would work for you!$"

gText_BlueRobbery_SoTwitterGot::
	.string "So Twitter got the wrong person?\n"
	.string "Started a whole campaign around the\l"
	.string "wrong kid?$"

gText_BlueRobbery_YeahAndThen::
	.string "Yeah! And then she got arrested\n"
	.string "everything! They were celebrating\l"
	.string "saying 'We got the Tenderloin theif!'$"

gText_BlueRobbery_InsaneSoTheHeat::
	.string "Insane. So the heat is just off you?\n"
	.string "That's it?$"

gText_BlueRobbery_OffScotFree::
	.string "Off scot free! Its like an angel helped\n"
	.string "me out.$"
