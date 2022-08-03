TwitterPost_RabiesOutbreak_Script::
	lock
	msgbox gText_Twitter_RabiesOutBreak_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_RABIESOUTBREAK
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_RabiesOutbreak_Script_2
TwitterPost_RabiesOutbreak_Script_1:
	closemessage
	end

TwitterPost_RabiesOutbreak_Script_2:
	startquest QUEST_RABIESOUTBREAK
	goto TwitterPost_RabiesOutbreak_Script_1


Twitter_HideReporter_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RABIESOUTBREAK
	compare VAR_RESULT, 0
	goto_if_eq Twitter_HideReporter_Script_1
	goto_if_set FLAG_MET_SOCIALMEDIA_REPORTER, Twitter_HideReporter_Script_1
	return

Twitter_HideReporter_Script_1:
	setflag FLAG_TEMP_4
	return


TwitterPost_CheckProgress_Script::
	lock
	goto_if_set FLAG_MET_SOCIALMEDIA_REPORTER, TwitterPost_CheckProgress_Script_2
	msgbox gText_Twitter_ThereWasAnError, MSGBOX_DEFAULT
	closemessage
	end

TwitterPost_CheckProgress_Script_2:
	return


TwitterPost_BlueRobbery_Script::
	call TwitterPost_CheckProgress_Script
	showmonpic SPECIES_QUAGSIRE, 10, 3
	msgbox gText_Twitter_BlueRobbery_Message, MSGBOX_DEFAULT
	hidemonpic
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_BLUEROBBERRY
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_BlueRobbery_Script_2
TwitterPost_BlueRobbery_Script_1:
	closemessage
	end

TwitterPost_BlueRobbery_Script_2:
	startquest QUEST_BLUEROBBERRY
	goto TwitterPost_BlueRobbery_Script_1


TwitterPost_IceCreamCrafting_Script::
	call TwitterPost_CheckProgress_Script
	msgbox gText_Twitter_IceCreamCrafting_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_ICECREAMCRAFTING
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_IceCreamCrafting_Script_2
TwitterPost_IceCreamCrafting_Script_1:
	closemessage
	end

TwitterPost_IceCreamCrafting_Script_2:
	startquest QUEST_ICECREAMCRAFTING
	goto TwitterPost_IceCreamCrafting_Script_1


TwitterPost_VSDeoxys_Script::
	call TwitterPost_CheckProgress_Script
	msgbox gText_Twitter_VSDeoxys_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_VSDEOXYS
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_VSDeoxys_Script_2
TwitterPost_VSDeoxys_Script_1:
	closemessage
	end

TwitterPost_VSDeoxys_Script_2:
	startquest QUEST_VSDEOXYS
	goto TwitterPost_VSDeoxys_Script_1


TwitterPost_ChinatownTunnels_Script::
	call TwitterPost_CheckProgress_Script
	msgbox gText_Twitter_ChinatownTunnels_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_CHINATOWNTUNNELS
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_ChinatownTunnels_Script_2
TwitterPost_ChinatownTunnels_Script_1:
	closemessage
	end

TwitterPost_ChinatownTunnels_Script_2:
	startquest QUEST_CHINATOWNTUNNELS
	goto TwitterPost_ChinatownTunnels_Script_1


TwitterPost_FreshwaterEvolution_Script::
	call TwitterPost_CheckProgress_Script
	msgbox gText_Twitter_FreshwaterEvolution_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_FRESHWATEREVOLUTION
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_FreshwaterEvolution_Script_2
TwitterPost_FreshwaterEvolution_Script_1:
	closemessage
	end

TwitterPost_FreshwaterEvolution_Script_2:
	startquest QUEST_FRESHWATEREVOLUTION
	goto TwitterPost_FreshwaterEvolution_Script_1


TwitterPost_GemArtist_Script::
	call TwitterPost_CheckProgress_Script
	msgbox gText_Twitter_GemArtist_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_GEMARTIST
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_GemArtist_Script_2
TwitterPost_GemArtist_Script_1:
	closemessage
	end

TwitterPost_GemArtist_Script_2:
	startquest QUEST_GEMARTIST
	goto TwitterPost_GemArtist_Script_1


TwitterPost_BetweenAStoneAndAHardPlace_Script::
	call TwitterPost_CheckProgress_Script
	msgbox gText_Twitter_BetweenAStoneAndAHardPlace_Message, MSGBOX_DEFAULT
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_BETWEENASTONEANDAHARD
	compare VAR_RESULT, 0
	goto_if_ne TwitterPost_BetweenAStoneAndAHardPlace_Script_2
TwitterPost_BetweenAStoneAndAHardPlace_Script_1:
	closemessage
	end

TwitterPost_BetweenAStoneAndAHardPlace_Script_2:
	startquest QUEST_BETWEENASTONEANDAHARD
	goto TwitterPost_BetweenAStoneAndAHardPlace_Script_1


gText_Twitter_ThereWasAnError::
	.string "There was an error displying this\n"
	.string "content. Please try again later.$"

gText_Twitter_RabiesOutBreak_Message::
	.string "My cousin told me there's a mass rabies\n"
	.string "outbreak in Bernalheights! Feral\l"
	.string "Glameow are attacking pets and people,\l"
	.string "accelerating the spread of the\l"
	.string "disease. He heard the ASPCA is gonna\l"
	.string "hook people up who can subdue or\l"
	.string "capture Glameow to reduce their impact\l"
	.string "on the local community. I'll be doing my\l"
	.string "part! hashtagDefeat10Glameow$"

gText_Twitter_BlueRobbery_Message::
	.string "Last night our store's window was\n"
	.string "smashed and our stuff was stolen... I\l"
	.string "caught this brunette and her\l"
	.string "Wobbuffet in 4K stealing from us. I've\l"
	.string "seen her in Castro, and I need Twitter\l"
	.string "to hashtagdoitsthing and help me get\l"
	.string "justice for small business!$"

gText_Twitter_IceCreamCrafting_Message::
	.string "Calling all Trainers! We're a new ice\n"
	.string "cream shop in Berkeley, and we've got\l"
	.string "the perfect smoothie to clean out your\l"
	.string "Pokémon and make them easier to train.\l"
	.string "Bring 3 Pecha Berry, 2 Nanab Berry, and\l"
	.string "a Rabuta Berry, and we'll make the first\l"
	.string "one for free! hashtagdetox$"

gText_Twitter_VSDeoxys_Message::
	.string "$"

gText_Twitter_ChinatownTunnels_Message::
	.string "$"

gText_Twitter_FreshwaterEvolution_Message::
	.string "$"

gText_Twitter_GemArtist_Message::
	.string "$"

gText_Twitter_BetweenAStoneAndAHardPlace_Message::
	.string "$"
