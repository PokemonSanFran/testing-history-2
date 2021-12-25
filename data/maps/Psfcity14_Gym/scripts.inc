Psfcity14_Gym_MapScripts::
	.byte 0


EnterPsfleader2_Event_Script::
	switch VAR_GYM_2_STATE
	case 3, EnterPsfleader2_Event_Script_2
	case 4, EnterPsfleader2_Event_Script_3
	case 5, EnterPsfleader2_Event_Script_4
	goto EnterPsfleader2_Psfleader2Intro_Dialogue
	return

EnterPsfleader2_Event_Script_2:
	goto EnterPsfleader2_StartGymBattle_Script
	return

EnterPsfleader2_Event_Script_3:
	goto EnterPsfleader2_PostDefeat1_Dialogue
	return

EnterPsfleader2_Event_Script_4:
	goto EnterPsfleader2_PostDefeat2_Dialogue
	return


EnterPsfleader2_Psfleader2Intro_Dialogue::
	setvar VAR_GYM_2_STATE, 3
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_ReachingTheSummit, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_TotallyWornOut
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_YeahFromOrre
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_ManyMountainsLikeSinnoh
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_EverythingIsSoFlat
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_HikedUpAMountain
	callnative ClearMugshot
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_ThisCheapImitation
	callnative ClearMugshot
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader2_StartGymBattle_Script
	return


EnterPsfleader2_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	trainerbattle_single TRAINER_BRAWLY_1, gText_EnterPsfleader2_EnGarde, gText_EnterPsfleader2_ItsAnHonorToLose, EnterPsfleader2_Psfleader2Defeated_Script, NO_MUSIC
	return


EnterPsfleader2_Psfleader2Defeated_Script::
	lockall
	setflag FLAG_BADGE02_GET
	setvar VAR_GYM_2_STATE, 4
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_ExploitedMyMistakes
	callnative ClearMugshot
	msgbox gText_EnterPsfleader2_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM02
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


EnterPsfleader2_PostDefeat1_Dialogue::
	setvar VAR_GYM_2_STATE, 5
	lockall
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_TradedPokemonUpTo, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader2_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader2_NextTimeWeBattle, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


gText_EnterPsfleader2_ReachingTheSummit::
	.string "Congratulations on reaching the\n"
	.string "summit, {PLAYER}! I'm Psfleader2.$"

gText_EnterPsfleader2_TotallyWornOut::
	.string "Most Trainers are totally worn out when\n"
	.string "they reach me. Are you a foreigner?$"

gText_EnterPsfleader2_YeahFromOrre::
	.string "Yeah, from Orre.$"

gText_EnterPsfleader2_ManyMountainsLikeSinnoh::
	.string "Ah yes. Many mountains, like Sinnoh.\n"
	.string "Sinnoh is a physically demanding\l"
	.string "region. The slopes, mountains, and\l"
	.string "marshes... Trainers have to train their\l"
	.string "bodies and minds alongside their\l"
	.string "Pokémon!$"

gText_EnterPsfleader2_EverythingIsSoFlat::
	.string "But in Psfregion1, everything is so flat\n"
	.string "and stale and uninspired... and pudgy.$"

gText_EnterPsfleader2_HikedUpAMountain::
	.string "(Flat? I hiked up a mountain just to get\n"
	.string "here!)$"

gText_EnterPsfleader2_ThisCheapImitation::
	.string "And Psfcity14... this cheap imitation.\n"
	.string "These people have no idea what Sinnoh\l"
	.string "is! They've bastardized our traditions\l"
	.string "and cultures. I'll show you how a true\l"
	.string "trainer from Sinnoh battles!$"

gText_EnterPsfleader2_EnGarde::
	.string "En garde!$"

gText_EnterPsfleader2_MyHeartIsRacing::
	.string "My heart is racing!$"

gText_EnterPsfleader2_ImNotFinishedYet::
	.string "I'm not finished yet. I've got this!$"

gText_EnterPsfleader2_Sinnoh1Orre0::
	.string "Sinnoh 1, Orre 0!$"

gText_EnterPsfleader2_ItsAnHonorToLose::
	.string "It's an honor to lose to you.$"

gText_EnterPsfleader2_ExploitedMyMistakes::
	.string "Thank you, {PLAYER}. You exploited my\n"
	.string "mistakes amazingly. I hope you're\l"
	.string "proud!$"

gText_EnterPsfleader2_BadgeGet::
	.string "You received the Psfbadge2 Badge!$"

gText_EnterPsfleader2_TradedPokemonUpTo::
	.string "Traded Pokémon up to Level\n"
	.string "Psfgymlevel2 will recognize your\l"
	.string "Psfbadge2 Badge and the skill it\l"
	.string "represents. That TM teaches\l"
	.string "Psfgymattacknum2, which does exactly\l"
	.string "what it sounds like!$"

gText_EnterPsfleader2_NextTimeWeBattle::
	.string "Next time we battle, I'll be better. I\n"
	.string "won't let you, or the Sinnoh people,\l"
	.string "down!$"
