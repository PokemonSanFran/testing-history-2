Quest_ButOnlyIn_Debug_Script::
	addvar VAR_TEMP_0, 1
	setvar VAR_DEFEATED_BACKYARD_COUNT, 30
	callnative CountDefeatedBackyard
	return


Quest_ButOnlyIn_HideGunda_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUTONLYINMYBACKYARD
	compare VAR_RESULT, 0
	goto_if_ne Quest_ButOnlyIn_HideGunda_Script_2
Quest_ButOnlyIn_HideGunda_Script_1:
	return

Quest_ButOnlyIn_HideGunda_Script_2:
	setflag FLAG_TEMP_6
	goto Quest_ButOnlyIn_HideGunda_Script_1


Quest_ButOnlyIn_HideNimby_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUTONLYINMYBACKYARD
	compare VAR_RESULT, 0
	goto_if_eq Quest_ButOnlyIn_HideNimby_Script_2
Quest_ButOnlyIn_HideNimby_Script_1:
	return

Quest_ButOnlyIn_HideNimby_Script_2:
	setflag FLAG_TEMP_1
	goto Quest_ButOnlyIn_HideNimby_Script_1


Quest_ButOnlyIn_Interact_Gunda_Script::
	lock
	faceplayer
	returnqueststate QUEST_BUTONLYINMYBACKYARD
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ButOnlyIn_Interact_Gunda_Script_2
	case QUEST_MENU_SET_REWARD, Quest_ButOnlyIn_Interact_Gunda_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_ButOnlyIn_Interact_Gunda_Script_4
	goto Quest_ButOnlyIn_StartQuest_Dialogue
	return

Quest_ButOnlyIn_Interact_Gunda_Script_2:
	goto Quest_ButOnlyIn_Active_Dialogue
	return

Quest_ButOnlyIn_Interact_Gunda_Script_3:
	goto Quest_ButOnlyIn_Reward_Dialogue
	return

Quest_ButOnlyIn_Interact_Gunda_Script_4:
	goto Quest_ButOnlyIn_Complete_Dialogue
	return


Quest_ButOnlyIn_StartQuest_Dialogue::
	msgbox gText_ButOnlyIn_TheresBuildingAApartment
	msgbox gText_ButOnlyIn_ButTheWildPokemonAroundHere
	msgbox gText_ButOnlyIn_CanYouHelpMeProve
	startquest QUEST_BUTONLYINMYBACKYARD
	release
	end


Quest_ButOnlyIn_Active_Dialogue::
	msgbox gText_ButOnlyIn_IJustWantTheKids, MSGBOX_NPC
	end


Quest_ButOnlyIn_Reward_Dialogue::
	msgbox gText_ButOnlyIn_TheHousingCrew
	giveitem ITEM_LETTER, 1
	msgbox gText_ButOnlyIn_YouKnowTheGolf
	completequest QUEST_BUTONLYINMYBACKYARD
	end


Quest_ButOnlyIn_Complete_Dialogue::
	msgbox gText_ButOnlyIn_WhatAShame, MSGBOX_NPC
	end


Quest_ButOnlyIn_Bar_Dialogue::
	lock
	msgbox gText_ButOnlyIn_AndAToastToTheGeniusGunda
	msgbox gText_ButOnlyIn_HereHere
	msgbox gText_ButOnlyIn_HowDidYouPull
	msgbox gText_ButOnlyIn_IMeanIfTheBirdsAreGone
	msgbox gText_ButOnlyIn_ItWasEasyToConvince
	msgbox gText_ButOnlyThe_AndSunsetRemains
	closemessage
	release
	end


gText_ButOnlyIn_TheresBuildingAApartment::
	.string "They're building an apartment complex\n"
	.string "here for low incoming housing! Its\l"
	.string "going to be a great development and\l"
	.string "help for people in the city.$"

gText_ButOnlyIn_ButTheWildPokemonAroundHere::
	.string "But the wild Pokemon around here... they\n"
	.string "can be aggressive. The environment\l"
	.string "committee is doing a final inspection\l"
	.string "and I'm afraid we wont pass if there's\l"
	.string "too many aggressive wild Pokemon.$"

gText_ButOnlyIn_CanYouHelpMeProve::
	.string "Can you help us out? We, the Committee\n"
	.string "for Reasonable Housing, want to make\l"
	.string "sure this inspection passes in a way\l"
	.string "that's best for everybody. I've heard\l"
	.string "the birds can be the most territorial.\l"
	.string "Can you knockout 27 or so Flying-type\l"
	.string "Pokemon on Psfroute7 and Psfroute32?\l"
	.string "That should help bring the levels down.$"

gText_ButOnlyIn_IJustWantTheKids::
	.string "I just want the kids to be safe!$"

gText_ButOnlyIn_TheHousingCrew::
	.string "The inspection just wrapped up but... it\n"
	.string "failed. Your work still wasn't enough.\l"
	.string "It's a bummer but we're going to work\l"
	.string "with the city to make sure this gets\l"
	.string "done right. Thank you for your help\l"
	.string "though! Take this.$"

gText_ButOnlyIn_YouKnowTheGolf::
	.string "You know the golf course over by\n"
	.string "Lakemerced? You can't get in there\l"
	.string "without an invitiation from a member.\l"
	.string "Take this and they'll let you in. There's\l"
	.string "tons of rare Pokemon on the course, so\l"
	.string "maybe it'll be worth it for you.$"

gText_ButOnlyIn_WhatAShame::
	.string "What a shame...$"

gText_ButOnlyIn_AndAToastToTheGeniusGunda::
	.string "And a toast to the genius Gunda!$"

gText_ButOnlyIn_HereHere::
	.string "here here!$"

gText_ButOnlyIn_HowDidYouPull::
	.string "how did you pull it off$"

gText_ButOnlyIn_IMeanIfTheBirdsAreGone::
	.string "i mean if the birds are gone, there's\n"
	.string "going to be more bugs and fish... and if\l"
	.string "the place is overrun with those, the\l"
	.string "enviromental freaks won't let anything\l"
	.string "develop.$"

gText_ButOnlyIn_ItWasEasyToConvince::
	.string "it was easy to convince some trainers\n"
	.string "to get rid of a sbitload of birds and\l"
	.string "bam! the hippies showed up and shut it\l"
	.string "all down. i didn't have to do anything$"

gText_ButOnlyThe_AndSunsetRemains::
	.string "and the Sunset remains hobo free! we're\n"
	.string "doing God's work, keeping our schools\l"
	.string "and familiies safe$"
