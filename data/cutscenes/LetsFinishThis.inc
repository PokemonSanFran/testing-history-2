LetsFinishThis_ObjectSetUp_Script::
	setflag FLAG_TEMP_2
	setobjectxy 13, 32, 12
	setobjectxyperm 13, 32, 12
	setobjectxy 3, 33, 12
	setobjectxyperm 3, 33, 12
	return


LetsFinishThis_MovePlayer_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 34
	goto_if_ne LetsFinishThis_MovePlayer_Script_2
	compare VAR_TEMP_1, 13
	goto_if_ne LetsFinishThis_MovePlayer_Script_2
LetsFinishThis_MovePlayer_Script_1:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto LetsFinishThis_Debrief_Dialogue
	return

LetsFinishThis_MovePlayer_Script_2:
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 34, 13
	TeleportCamera 34, 13
	fadescreen FADE_FROM_BLACK
	goto LetsFinishThis_MovePlayer_Script_1


LetsFinishThis_Debrief_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_IDontThinkIm
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_ThatPartDoesnt
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_ButInnocentPeople
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_PerfevtlySane
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_ButTheyWerentAlways
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_HasAlwaysBeenRuthless
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_ThatsWhatIMean
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_PerhapsDesperate
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_MaybeNowItsTime
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_NowMightBeTheTime
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_PublicSentimentIsStrong
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_EvenIfWePullIt
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_TheyCameForTheKings
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_SoBreakInto
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_APublicConfession
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_IWasBeingSarcastic
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_TheHardestPartOfThatPlan
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_TwoOldCoots
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_TheWarpPanels
	callnative ClearMugshot
	closemessage
	goto LetsFinishThis_GoToFlashback_Script
	return


LetsFinishThis_GoToFlashback_Script::
	fadescreen FADE_TO_BLACK
	msgbox LetsFinishThis_GoToFlashback_Script_Text_0, MSGBOX_AUTOCLOSE
	fadescreen FADE_FROM_BLACK
	goto LetsFinishThis_StartPlanning_Dialogue
	return


LetsFinishThis_StartPlanning_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_NobodyHasSeen
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_WhatAbout
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 18, LetsFinishThis_WalkToPlayer
	waitmovement 18
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_LetsFinishThis_WereOntoSomething
	callnative ClearMugshot
	closemessage
	applymovement 18, LetsFinishThis_WalkAway
	waitmovement 18
	addvar VAR_STORYLINE_STATE, 1
	release
	end


LetsFinishThis_WalkToPlayer:
	walk_right
	face_up
	step_end

LetsFinishThis_WalkAway:
	walk_left
	face_up
	step_end

LetsFinishThis_GoToFlashback_Script_Text_0:
	.string "this is a flashback to Psfbadadmin's\n"
	.string "kids explaining the warp panels.$"

gText_LetsFinishThis_IDontThinkIm::
	.string "I don’t think I’m surprised by Psfbadguy,\n"
	.string "but the government too? All those\l"
	.string "talks, those negotiations… aren’t they\l"
	.string "supposed to protect their citizens?$"

gText_LetsFinishThis_ThatPartDoesnt::
	.string "That part doesn’t surprise me. Old age\n"
	.string "getting to you? We all know, money is\l"
	.string "their only constituent.$"

gText_LetsFinishThis_ButInnocentPeople::
	.string "But innocent people? Attacking an\n"
	.string "entire island just to wipe out\l"
	.string "TeamRocket? This is insane!$"

gText_LetsFinishThis_PerfevtlySane::
	.string "Perfectly sane. It worked on\n"
	.string "RobinWillTunnel didn’t it? There’s no\l"
	.string "peaceful path forward. Do you all get\l"
	.string "it now? They’re poised to kill!$"

gText_LetsFinishThis_ButTheyWerentAlways::
	.string "But they weren’t always, were they?$"

gText_LetsFinishThis_HasAlwaysBeenRuthless::
	.string "Psfbadguy has always been ruthless!\n"
	.string "Killing is… new though.$"

gText_LetsFinishThis_ThatsWhatIMean::
	.string "That’s what I mean. We spun up this\n"
	.string "awesome Battle Facility program, we\l"
	.string "attacked the operations of their\l"
	.string "corporate partners, our message is\l"
	.string "really getting out there! I think\l"
	.string "they’re nervous.$"

gText_LetsFinishThis_PerhapsDesperate::
	.string "Perhaps desperate.$"

gText_LetsFinishThis_MaybeNowItsTime::
	.string "Maybe now it's the time to really bring\n"
	.string "the fight to them!$"

gText_LetsFinishThis_NowMightBeTheTime::
	.string "Now might be the time. Arceus knows\n"
	.string "we’ve explored every other path.$"

gText_LetsFinishThis_PublicSentimentIsStrong::
	.string "Public sentiment is strong as hell. A\n"
	.string "confrontation and confession might be\l"
	.string "a moonshot, but it's a helluva shot,\l"
	.string "right?$"

gText_LetsFinishThis_EvenIfWePullIt::
	.string "Even if we pull it off, will exposing\n"
	.string "them even matter? Or work?$"

gText_LetsFinishThis_TheyCameForTheKings::
	.string "They came for the Kings and missed.\n"
	.string "This may be our only chance to fight\l"
	.string "back.$"

gText_LetsFinishThis_SoBreakInto::
	.string "So, break into YCombinatortower, force\n"
	.string "a confession from Rose, broadcast it\l"
	.string "using their equipment and public\l"
	.string "sentiment will come crashing down.\l"
	.string "Right?$"

gText_LetsFinishThis_APublicConfession::
	.string "A public confession would force the\n"
	.string "government to take action.$"

gText_LetsFinishThis_IWasBeingSarcastic::
	.string "I was being sarcastic!$"

gText_LetsFinishThis_TheHardestPartOfThatPlan::
	.string "The hardest part of that plan is\n"
	.string "actually just getting to Rose. The rest\l"
	.string "of that is fairly plausible, given we\l"
	.string "survive.$"

gText_LetsFinishThis_TwoOldCoots::
	.string "Two old coots, some has-beens, and a\n"
	.string "bunch of kids running into the belly of\l"
	.string "the beast? Count me the hell in.$"

gText_LetsFinishThis_TheWarpPanels::
	.string "The warp panels!$"

gText_LetsFinishThis_NobodyHasSeen::
	.string "Nobody has seen Koga since their stunt\n"
	.string "in the warehouse. Cops have been\l"
	.string "crawling all over that neighborhood\l"
	.string "and house looking for him.$"

gText_LetsFinishThis_WhatAbout::
	.string "What about Sabrina? That workaholic\n"
	.string "absolutely has a panel in their place\l"
	.string "too. And no police looking for them.$"

gText_LetsFinishThis_WereOntoSomething::
	.string "We’re onto something. You should go\n"
	.string "prepare! Once we start, I don’t think\l"
	.string "there’s any turning back. Meet us\l"
	.string "outside Koga’s house in Sunset.$"
