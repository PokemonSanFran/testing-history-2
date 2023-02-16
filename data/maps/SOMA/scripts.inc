SOMA_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SOMA_MapScripts_MAP_SCRIPT_ON_RESUME
	map_script MAP_SCRIPT_ON_TRANSITION, SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

SOMA_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_StopMugging_HideObject_Script
	return

SOMA_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_StopMugging_HideObject_Script
	call Twitter_HideReporter_Script
	call WowYoureStrong_HideObject_Script
	call Quest_BuildingAnExhibit_HideLeader_Script
	return

SOMA_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_SOMA_STATE, 1, WowYoureStrong_WalkToPlayer_Script
	.2byte 0


SOMA_SocialMediaReporter_Dialogue::
	setflag FLAG_MET_SOCIALMEDIA_REPORTER
	msgbox gText_SOMA_SocialMediaIs, MSGBOX_NPC, SPEAKER_ISMAIL
	msgbox gText_SOMA_TotallyIHunted, MSGBOX_DEFAULT, , SPEAKER_ZOEY
	msgbox gText_SOMA_OhRight, MSGBOX_DEFAULT, SPEAKER_ISMAIL
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

SOMA_Stan_Interact_Script::
	lock
	call Quest_WallaceArmy_LoadStanSpeech_Script
	msgbox gText_WallaceArmy_OhWallaceSama, MSGBOX_NPC
	call Quest_WallaceArmy_PreBattleStan_Script
	trainerbattle_single TRAINER_LOLA_3, gText_WallaceArmy_MarinSolarTheySpoke, gText_WallaceArmy_MyLord, SOMA_Stan_PostBattle_Script
	goto SOMA_Stan_PostBattle_Script
	return


SOMA_Stan_PostBattle_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WALLACEARMY, SUB_QUEST_3
	call Quest_WallaceArmy_CheckCompletionRate_Script
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq SOMA_Stan_PostBattle_Script_2
	msgbox gText_WallaceArmy_PostQuestPlaceholder1, , SPEAKER_STAN_SOMA
SOMA_Stan_PostBattle_Script_1:
	release
	end

SOMA_Stan_PostBattle_Script_2:
	msgbox gText_WallaceArmy_PostBattlePlaceholder1, , SPEAKER_STAN_SOMA
	goto SOMA_Stan_PostBattle_Script_1


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
