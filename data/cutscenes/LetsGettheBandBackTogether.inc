LetsGettheBandBackTogether_HideObject_Script::
	compare VAR_STORYLINE_STATE, 43
	goto_if_eq LetsGettheBandBackTogether_HideObject_Script_2
LetsGettheBandBackTogether_HideObject_Script_1:
	setflag FLAG_TEMP_5
	setflag FLAG_TEMP_6
	setflag FLAG_TEMP_7
	setflag FLAG_TEMP_8
	setflag FLAG_TEMP_9
	return

LetsGettheBandBackTogether_HideObject_Script_2:
	setflag FLAG_TEMP_2
	goto LetsGettheBandBackTogether_HideObject_Script_1


LetsGettheBandBackTogether_PreventPlayerEnterTower_Script::
	goto_if_set FLAG_TIMELINE_TIMETRAVEL, LetsGettheBandBackTogether_PreventPlayerEnterTower_Script_2
LetsGettheBandBackTogether_PreventPlayerEnterTower_Script_1:
	release
	end

LetsGettheBandBackTogether_PreventPlayerEnterTower_Script_2:
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_IDontThinkIShould
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	goto LetsGettheBandBackTogether_PreventPlayerEnterTower_Script_1


LetsGettheBandBackTogether_MeetInBasement_Script::
	compare VAR_ALCATRAZ_STATE, LAST_CHANCE_TRUE_TIMELINE_START
	goto_if_eq LetsGettheBandBackTogether_MeetInBasement_Script_2
LetsGettheBandBackTogether_MeetInBasement_Script_1:
	lock
	playse SE_PIN
	waitse
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 1
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_IDidntThinkYouWere, MSGBOX_NPC
	goto_if_set FLAG_TIMELINE_TIMETRAVEL, LetsGettheBandBackTogether_MeetInBasement_Script_5
LetsGettheBandBackTogether_MeetInBasement_Script_4:
	msgbox gText_LetsGetTheBandBackTogether_IReallyThinkWith
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_WaitTheEliteFour
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_OkayKindaThatsActually
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_WhatAmIMissing
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_HasntBeenHeardFromEver
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_LetsSplitUp
	msgbox gText_LetsGetTheBandBackTogether_BeforeWeStart
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_OhYeahOfCourse
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_IllWriteUpAPost
	setvar VAR_ALCATRAZ_STATE, LAST_CHANCE_TRUE_TIMELINE_START
	callnative ClearMugshot
	closemessage
	release
	end

LetsGettheBandBackTogether_MeetInBasement_Script_2:
	goto LetsGettheBandBackTogether_TrueTimelineSplit_Script
	goto LetsGettheBandBackTogether_MeetInBasement_Script_1

LetsGettheBandBackTogether_MeetInBasement_Script_5:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_IHadAnInsane
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	goto LetsGettheBandBackTogether_MeetInBasement_Script_4


LetsGettheBandBackTogether_TrueTimelineSplit_Script::
	lock
	faceplayer
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_ReadyToGoLive, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq LetsGettheBandBackTogether_TrueTimelineSplit_Script_2
	setvar VAR_ALCATRAZ_STATE, START_TRUE_TIMELINE
	setvar VAR_STORYLINE_STATE, STORY_START_TRUE_TIMELINE
	setflag FLAG_TIMELINE_TRUE
	setvar VAR_MASK_OFF_STATE, ASSIGNED_MASK_OFF
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_Yes
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	msgbox gText_LetsGetTheBandBackTogether_WereSickOf
	closemessage
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_LetsSplitUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_AnyLeads
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_OkayGetGoing
	callnative ClearMugshot
	closemessage
	applymovement 1, LetsGettheBandBackTogether_WalkOffScreen
	waitmovement 1
	playse SE_EXIT
	waitse
	removeobject 1
	release
	end

LetsGettheBandBackTogether_TrueTimelineSplit_Script_2:
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsGetTheBandBackTogether_YeahIGetIt
	callnative ClearMugshot
	closemessage
	release
	end


LetsGettheBandBackTogether_WalkOffScreen:
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

gText_LetsGetTheBandBackTogether_IDidntThinkYouWere::
	.string "I didn’t think you were coming back. I\n"
	.string "can’t believe it worked!$"

gText_LetsGetTheBandBackTogether_IHadAnInsane::
	.string "I had an insane dream last night, which\n"
	.string "really helped.$"

gText_LetsGetTheBandBackTogether_IReallyThinkWith::
	.string "I really think with you and the Elite\n"
	.string "Four here, we’ve got a fighting chance.$"

gText_LetsGetTheBandBackTogether_WaitTheEliteFour::
	.string "Wait, the Elite Four too?$"

gText_LetsGetTheBandBackTogether_OkayKindaThatsActually::
	.string "Okay, kinda. That’s actually the next\n"
	.string "step. Malva and Drasna convinced\l"
	.string "Siebold to work with us too, but we’ve\l"
	.string "gotta find Wikstrom if we really want\l"
	.string "to present a united front.$"

gText_LetsGetTheBandBackTogether_WhatAmIMissing::
	.string "What am I missing? Can’t we just call\n"
	.string "them or something?$"

gText_LetsGetTheBandBackTogether_HasntBeenHeardFromEver::
	.string "Wikstrom hasn’t been heard from ever\n"
	.string "since Ycombinator took over. Just up\l"
	.string "and disappeared. I thought the other\l"
	.string "members would have heard from him, but\l"
	.string "Drasna said he’s been totally gone.\l"
	.string "They’re not even sure if they’re in the\l"
	.string "region anymore.$"

gText_LetsGetTheBandBackTogether_BeforeWeStart::
	.string "We should start rallying the people\n"
	.string "behind our cause. You’re the champ,\l"
	.string "after all, let’s put that clout to work.$"

gText_LetsGetTheBandBackTogether_OhYeahOfCourse::
	.string "Oh, yeah, of course. What were you\n"
	.string "thinking?$"

gText_LetsGetTheBandBackTogether_IllWriteUpAPost::
	.string "I’ll write up a post and you can share it.\n"
	.string "Once you do, though, Ycombinator is\l"
	.string "probably gonna cut you off, so if there\l"
	.string "are any perks you wanna use before you\l"
	.string "lose access you should do it now. Let\l"
	.string "me know when you’re good to go.$"

gText_LetsGetTheBandBackTogether_ReadyToGoLive::
	.string "Ready to go live?$"

gText_LetsGetTheBandBackTogether_YeahIGetIt::
	.string "Yeah, I get it. Nervous?$"

gText_LetsGetTheBandBackTogether_Yes::
	.string "Yes!$"

gText_LetsGetTheBandBackTogether_WereSickOf::
	.string "We’re sick of Ycombinator’s shit. We’re\n"
	.string "tired of the lies, the attacks, and the\l"
	.string "greed. Let’s take back our region,\l"
	.string "together.$"

gText_LetsGetTheBandBackTogether_LetsSplitUp::
	.string "Let’s split up. I’m going to talk to Ariana\n"
	.string "and try to convince them of the plan\l"
	.string "going forward. Can you see if you can\l"
	.string "get an idea where Wikstrom might be?$"

gText_LetsGetTheBandBackTogether_AnyLeads::
	.string "Where do I even start?$"

gText_LetsGetTheBandBackTogether_OkayGetGoing::
	.string "Try the newspaper in SOMA, they did an\n"
	.string "interview with Wikstrom right before he\l"
	.string "disappeared. I’m gonna make some moves\l"
	.string "too.$"

gText_LetsGetTheBandBackTogether_IDontThinkIShould::
	.string "…I don’t think I should go in there. I\n"
	.string "know how this ends.$"
