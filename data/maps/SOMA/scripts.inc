SOMA_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SOMA_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SOMA_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_StopMugging_HideObject_Script
	return

SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call SOMA_MapScripts_OnTransition
	return

SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SOMA_STATE, 1, WowYoureStrong_WalkToPlayer_Script
	.2byte 0


SOMA_MapScripts_OnTransition::
	call Quest_StopMugging_HideObject_Script
	call Twitter_HideReporter_Script
	call WowYoureStrong_HideObject_Script
	return


SOMA_SocialMediaReporter_Dialogue::
	setflag FLAG_MET_SOCIALMEDIA_REPORTER
	msgbox gText_SOMA_SocialMediaIs, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SOMA_TotallyIHunted, MSGBOX_DEFAULT
	callnative ClearMugshot
	msgbox gText_SOMA_OhRight, MSGBOX_DEFAULT
	closemessage
	applymovement 5, SOMA_WalkInside
	playse SE_EXIT
	waitmovement 5
	removeobject 5
	return


SOMA_WalkInside:
	walk_left
	walk_up
	step_end

gText_SOMA_SocialMediaIs::
	.string "Social media is getting out of control!\n"
	.string "I spend more of my day trying to verify\l"
	.string "wild claims than actually reporting on\l"
	.string "real news.$"

gText_SOMA_TotallyIHunted::
	.string "Totally! I hunted a bunch of Glameow in\n"
	.string "Bernalheights only for the whole story\l"
	.string "to be totally bogus.$"

gText_SOMA_OhRight::
	.string "Oh right, the rabies outbreak! So\n"
	.string "ridiculous. I want to try to\l"
	.string "investigate where all these claims are\l"
	.string "coming from, because I think its only\l"
	.string "going to get worse. You're a Trainer,\l"
	.string "right? Let's exchange contact info.\l"
	.string "Keep your eyes peeled on social media\l"
	.string "for any more bogus stories, and I'll hit\l"
	.string "you up once I find a good lead.$"
