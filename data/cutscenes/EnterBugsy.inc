EnterBugsy_BugsyIntro_Dialogue::
	addvar VAR_GYM_2_STATE, 1
	addvar VAR_GYM_2_STATE, 1
	addvar VAR_GYM_2_STATE, 1
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_ReachingTheSummit, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_TotallyWornOut
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterBugsy_YeahFromOrre
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_ManyMountainsLikeSinnoh
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_EverythingIsSoFlat
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterBugsy_HikedUpAMountain
	callnative ClearMugshot
	applymovement 1, Common_Movement_FaceAwayPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_ThisCheapImitation
	callnative ClearMugshot
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	call Common_EventScript_SaveGame
	closemessage
	goto EnterBugsy_StartGymBattle_Script
	return


EnterBugsy_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	trainerbattle_single TRAINER_BRAWLY_1, gText_EnterBugsy_EnGarde, gText_EnterBugsy_ItsAnHonorToLose, EnterBugsy_BugsyDefeated_Script, NO_MUSIC
	return


EnterBugsy_BugsyDefeated_Script::
	lockall
	setflag FLAG_BADGE02_GET
	addvar VAR_GYM_2_STATE, 1
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_ExploitedMyMistakes
	callnative ClearMugshot
	msgbox gText_EnterBugsy_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM02
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


EnterBugsy_PostDefeat1_Dialogue::
	addvar VAR_GYM_2_STATE, 1
	lockall
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_TradedPokemonUpTo, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterBugsy_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_BUGSY
	callnative DrawMugshot
	msgbox gText_EnterBugsy_NextTimeWeBattle, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


gText_EnterBugsy_ReachingTheSummit::
	.string "Congratulations on reaching the\n"
	.string "summit, {PLAYER}! I'm Bugsy.$"

gText_EnterBugsy_TotallyWornOut::
	.string "Most Trainers are totally worn out when\n"
	.string "they reach me. Are you a foreigner?$"

gText_EnterBugsy_YeahFromOrre::
	.string "Yeah, from Orre.$"

gText_EnterBugsy_ManyMountainsLikeSinnoh::
	.string "Ah yes. Many mountains, like Sinnoh.\n"
	.string "Sinnoh is a physically demanding\l"
	.string "region. The slopes, mountains, and\l"
	.string "marshes... Trainers have to train their\l"
	.string "bodies and minds alongside their\l"
	.string "Pokémon!$"

gText_EnterBugsy_EverythingIsSoFlat::
	.string "But in SanFran, everything is so flat\n"
	.string "and stale and uninspired... and pudgy.$"

gText_EnterBugsy_HikedUpAMountain::
	.string "(Flat? I hiked up a mountain just to get\n"
	.string "here!)$"

gText_EnterBugsy_ThisCheapImitation::
	.string "And Japantown... this cheap imitation.\n"
	.string "These people have no idea what Sinnoh\l"
	.string "is! They've bastardized our traditions\l"
	.string "and cultures. I'll show you how a true\l"
	.string "trainer from Sinnoh battles!$"

gText_EnterBugsy_EnGarde::
	.string "En garde!$"

gText_EnterBugsy_MyHeartIsRacing::
	.string "My heart is racing!$"

gText_EnterBugsy_ImNotFinishedYet::
	.string "I'm not finished yet. I've got this!$"

gText_EnterBugsy_Sinnoh1Orre0::
	.string "Sinnoh 1, Orre 0!$"

gText_EnterBugsy_ItsAnHonorToLose::
	.string "It's an honor to lose to you.$"

gText_EnterBugsy_ExploitedMyMistakes::
	.string "Thank you, {PLAYER}. You exploited my\n"
	.string "mistakes amazingly. I hope you're\l"
	.string "proud!$"

gText_EnterBugsy_BadgeGet::
	.string "You received the BugsyBadge Badge!$"

gText_EnterBugsy_TradedPokemonUpTo::
	.string "Traded Pokémon up to Level\n"
	.string "Psfgymlevel2 will recognize your\l"
	.string "BugsyBadge Badge and the skill it\l"
	.string "represents. That TM teaches\l"
	.string "Psfgymattacknum2, which does exactly\l"
	.string "what it sounds like!$"

gText_EnterBugsy_NextTimeWeBattle::
	.string "Next time we battle, I'll be better. I\n"
	.string "won't let you, or the Sinnoh people,\l"
	.string "down!$"
