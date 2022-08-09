Quest_GemArtist_AskForGlass_Dialogue::
	msgbox gText_Quest_GemArtist_AhYouSaw, MSGBOX_NPC
	call Quest_GemArtist_CheckBag_Script
	compare VAR_RESULT, 0
	goto_if_ne Quest_GemArtist_AskForGlass_Dialogue_1
	goto Quest_GemArtist_NotEnough_Script
	return

Quest_GemArtist_AskForGlass_Dialogue_1:
	goto Quest_GemArtist_GiveFirstGem_Script
	return


Quest_GemArtist_WantGem_Dialogue::
	msgbox gText_Quest_GemArtist_YoureBack, MSGBOX_NPC
	call Quest_GemArtist_CheckBag_Script
	compare VAR_RESULT, 0
	goto_if_ne Quest_GemArtist_WantGem_Dialogue_1
	goto Quest_GemArtist_NotEnough_Script
	return

Quest_GemArtist_WantGem_Dialogue_1:
	goto Quest_GemArtist_GiveNextGem_Script
	return


Quest_GemArtist_NotEnough_Script::
	msgbox gText_Quest_GemArtist_OhYouDont, MSGBOX_NPC
	end


Quest_GemArtist_CheckBag_Script::
	additem ITEM_RARE_CANDY, 10
	checkitem ITEM_RARE_CANDY, 10
	return


Quest_GemArtist_GiveFirstGem_Script::
	call Quest_GemArtist_MakeGem_Script
	msgbox gText_Quest_GemArtist_JustLikeTheAd, MSGBOX_NPC
	questmenu QUEST_MENU_SET_REWARD, QUEST_GEMARTIST
	completequest QUEST_GEMARTIST
	end


Quest_GemArtist_GiveNextGem_Script::
	call Quest_GemArtist_MakeGem_Script
	msgbox gText_Quest_GemArtist_ThereYouGo, MSGBOX_NPC
	release
	end


Quest_GemArtist_RandomOrChosenGem_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_GEMARTIST
	compare VAR_RESULT, 0
	goto_if_eq Quest_GemArtist_RandomOrChosenGem_Script_2
	multichoice 16, 0, MULTI_STARTER_SELECT, FALSE
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq Quest_GemArtist_RandomOrChosenGem_Script_5
Quest_GemArtist_RandomOrChosenGem_Script_1:
	return

Quest_GemArtist_RandomOrChosenGem_Script_2:
	random 17
	goto Quest_GemArtist_RandomOrChosenGem_Script_1

Quest_GemArtist_RandomOrChosenGem_Script_5:
	goto Quest_GemArtist_CancelGem_Dialogue
	goto Quest_GemArtist_RandomOrChosenGem_Script_1


Quest_GemArtist_MakeGem_Script::
	call Quest_GemArtist_RandomOrChosenGem_Script
	applymovement 1, Common_Movement_FaceRight
	waitmovement 1
	msgbox gText_Quest_GemArtist_NowJustToDoThis
	closemessage
	delay 30
	faceplayer
	switch VAR_RESULT
	case 0, Quest_GemArtist_MakeGem_Script_3
	case 1, Quest_GemArtist_MakeGem_Script_4
	case 2, Quest_GemArtist_MakeGem_Script_5
	case 3, Quest_GemArtist_MakeGem_Script_6
	case 4, Quest_GemArtist_MakeGem_Script_7
	case 5, Quest_GemArtist_MakeGem_Script_8
	case 6, Quest_GemArtist_MakeGem_Script_9
	case 7, Quest_GemArtist_MakeGem_Script_10
	case 8, Quest_GemArtist_MakeGem_Script_11
	case 9, Quest_GemArtist_MakeGem_Script_12
	case 10, Quest_GemArtist_MakeGem_Script_13
	case 11, Quest_GemArtist_MakeGem_Script_14
	case 12, Quest_GemArtist_MakeGem_Script_15
	case 13, Quest_GemArtist_MakeGem_Script_16
	case 14, Quest_GemArtist_MakeGem_Script_17
	case 15, Quest_GemArtist_MakeGem_Script_18
	case 16, Quest_GemArtist_MakeGem_Script_19
	case 17, Quest_GemArtist_MakeGem_Script_20
Quest_GemArtist_MakeGem_Script_1:
	removeitem ITEM_RARE_CANDY, 10
	return

Quest_GemArtist_MakeGem_Script_3:
	giveitem ITEM_NORMAL_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_4:
	giveitem ITEM_FIRE_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_5:
	giveitem ITEM_WATER_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_6:
	giveitem ITEM_ELECTRIC_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_7:
	giveitem ITEM_GRASS_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_8:
	giveitem ITEM_ICE_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_9:
	giveitem ITEM_FIGHTING_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_10:
	giveitem ITEM_POISON_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_11:
	giveitem ITEM_GROUND_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_12:
	giveitem ITEM_FLYING_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_13:
	giveitem ITEM_PSYCHIC_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_14:
	giveitem ITEM_BUG_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_15:
	giveitem ITEM_ROCK_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_16:
	giveitem ITEM_GHOST_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_17:
	giveitem ITEM_DRAGON_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_18:
	giveitem ITEM_DARK_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_19:
	giveitem ITEM_STEEL_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1

Quest_GemArtist_MakeGem_Script_20:
	giveitem ITEM_FAIRY_GEM, 1
	goto Quest_GemArtist_MakeGem_Script_1


Quest_GemArtist_CancelGem_Dialogue::
	msgbox gText_Quest_GemArtist_ChangedYourMind, MSGBOX_NPC
	end


gText_Quest_GemArtist_AhYouSaw::
	.string "Ah, you saw my ad on Twitter! Well, do\n"
	.string "you have 10 Beach Glass?$"

gText_Quest_GemArtist_YoureBack::
	.string "You're back! Did you bring 10 more Beach\n"
	.string "Glass?$"

gText_Quest_GemArtist_OhYouDont::
	.string "Oh, you don't have enough Beach Glass.\n"
	.string "Go get some and come back!$"

gText_Quest_GemArtist_JustLikeTheAd::
	.string "Just like the ad said, here's your\n"
	.string "beautiful Unovaian Gem. Enjoy!$"

gText_Quest_GemArtist_ThereYouGo::
	.string "There you go!$"

gText_Quest_GemArtist_NowJustToDoThis::
	.string "Okay, now just melt these down...$"

gText_Quest_GemArtist_ChangedYourMind::
	.string "Changed your mind?$"
