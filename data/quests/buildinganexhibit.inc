Quest_BuildingAnExhibit_Debug_Script::
	setvar VAR_TEMP_0, 1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_1
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_2
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_3
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	call Quest_BuildingAnExhibit_CheckSubquests_Script
	return


Quest_BuildingAnExhibit_HideLeader_Script::
	compare VAR_WHITNEY_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_BuildingAnExhibit_HideLeader_Script_2
Quest_BuildingAnExhibit_HideLeader_Script_1:
	return

Quest_BuildingAnExhibit_HideLeader_Script_2:
	setflag FLAG_TEMP_5
	goto Quest_BuildingAnExhibit_HideLeader_Script_1


Quest_BuildingAnExhibit_CheckSubquests_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BUILDINGANEXHIBIT
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingAnExhibit_CheckSubquests_Script_2
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_BuildingAnExhibit_CheckSubquests_Script_5
Quest_BuildingAnExhibit_CheckSubquests_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_BuildingAnExhibit_CheckSubquests_Script_8
Quest_BuildingAnExhibit_CheckSubquests_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_BuildingAnExhibit_CheckSubquests_Script_11
Quest_BuildingAnExhibit_CheckSubquests_Script_10:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_BuildingAnExhibit_CheckSubquests_Script_14
Quest_BuildingAnExhibit_CheckSubquests_Script_13:
	compare VAR_TEMP_0, QUEST_BUILDINGANEXHIBIT_SUB_COUNT
	goto_if_eq Quest_BuildingAnExhibit_CheckSubquests_Script_17
Quest_BuildingAnExhibit_CheckSubquests_Script_16:
	return

Quest_BuildingAnExhibit_CheckSubquests_Script_2:
	return

Quest_BuildingAnExhibit_CheckSubquests_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_BuildingAnExhibit_CheckSubquests_Script_4

Quest_BuildingAnExhibit_CheckSubquests_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_BuildingAnExhibit_CheckSubquests_Script_7

Quest_BuildingAnExhibit_CheckSubquests_Script_11:
	addvar VAR_TEMP_0, 1
	goto Quest_BuildingAnExhibit_CheckSubquests_Script_10

Quest_BuildingAnExhibit_CheckSubquests_Script_14:
	addvar VAR_TEMP_0, 1
	goto Quest_BuildingAnExhibit_CheckSubquests_Script_13

Quest_BuildingAnExhibit_CheckSubquests_Script_17:
	questmenu QUEST_MENU_SET_REWARD, QUEST_BUILDINGANEXHIBIT
	goto Quest_BuildingAnExhibit_CheckSubquests_Script_16


Quest_BuildingAnExhibit_Interact_Leader_Script::
	lock
	faceplayer
	call Quest_BuildingAnExhibit_CheckSubquests_Script
	returnqueststate QUEST_BUILDINGANEXHIBIT
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_BuildingAnExhibit_Interact_Leader_Script_2
	case QUEST_MENU_SET_REWARD, Quest_BuildingAnExhibit_Interact_Leader_Script_3
	goto Quest_BuildingAnExhibit_StartQuest_Dialogue
	return

Quest_BuildingAnExhibit_Interact_Leader_Script_2:
	goto Quest_BuildingAnExhibit_Active_Dialogue
	return

Quest_BuildingAnExhibit_Interact_Leader_Script_3:
	goto Quest_BuildingAnExhibit_Reward_Dialogue
	return


Quest_BuildingAnExhibit_StartQuest_Dialogue::
	msgbox gText_BuildingAnExhibit_HeyPlayer
	msgbox gText_BuildingAnExhibit_WereBuilding
	msgbox gText_BuildingAnExhibit_ThereAreSomeReallyHard
	startquest QUEST_BUILDINGANEXHIBIT
	release
	end


Quest_BuildingAnExhibit_Active_Dialogue::
	msgbox gText_BuildingAnExhibit_ItsLikeHuntingANeedle
	return


Quest_BuildingAnExhibit_Interact_PersonA_Script::
	lock
	returnqueststate QUEST_BUILDINGANEXHIBIT
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_BuildingAnExhibit_Interact_PersonA_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_BuildingAnExhibit_Interact_PersonA_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_BuildingAnExhibit_Interact_PersonA_Script_4
	msgbox gText_Pacifica_PlaceholderOaklandFan, MSGBOX_NPC
Quest_BuildingAnExhibit_Interact_PersonA_Script_1:
	end

Quest_BuildingAnExhibit_Interact_PersonA_Script_3:
	goto Quest_BuildingAnExhibit_Active_PersonA_Script
	goto Quest_BuildingAnExhibit_Interact_PersonA_Script_1

Quest_BuildingAnExhibit_Interact_PersonA_Script_4:
	msgbox gText_BuildingAnExhibit_MyHomeWasInvaded, MSGBOX_NPC
	goto Quest_BuildingAnExhibit_Interact_PersonA_Script_1


Quest_BuildingAnExhibit_Active_PersonA_Script::
	faceplayer
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingAnExhibit_Active_PersonA_Script_2
Quest_BuildingAnExhibit_Active_PersonA_Script_1:
	goto Quest_BuildingAnExhibit_PersonA_Decline_Dialogue
	return

Quest_BuildingAnExhibit_Active_PersonA_Script_2:
	call Quest_BuildingAnExhibit_PersonA_Explain_Dialogue
	goto Quest_BuildingAnExhibit_Active_PersonA_Script_1


Quest_BuildingAnExhibit_PersonA_Explain_Dialogue::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	msgbox gText_BuildingAnExhibit_MyTicketsFromThe2015ChampionshipGame
	msgbox gText_BuildingAnExhibit_ThatMatchWasElectric
	return


Quest_BuildingAnExhibit_PersonA_Decline_Dialogue::
	msgbox gText_BuildingAnExhibit_ThatExhibitSoundsCool, MSGBOX_NPC
	end


Quest_BuildingAnExhibit_Interact_PersonB_Script::
	lock
	returnqueststate QUEST_BUILDINGANEXHIBIT
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_BuildingAnExhibit_Interact_PersonB_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_BuildingAnExhibit_Interact_PersonB_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_BuildingAnExhibit_Interact_PersonB_Script_4
	msgbox gText_Gldgtepark_PlaceholderOaklandFan, MSGBOX_NPC
Quest_BuildingAnExhibit_Interact_PersonB_Script_1:
	end

Quest_BuildingAnExhibit_Interact_PersonB_Script_3:
	goto Quest_BuildingAnExhibit_Active_PersonB_Script
	goto Quest_BuildingAnExhibit_Interact_PersonB_Script_1

Quest_BuildingAnExhibit_Interact_PersonB_Script_4:
	msgbox gText_BuildingAnExhibit_TheChampionsCapeIsGone, MSGBOX_NPC
	goto Quest_BuildingAnExhibit_Interact_PersonB_Script_1


Quest_BuildingAnExhibit_Active_PersonB_Script::
	faceplayer
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingAnExhibit_Active_PersonB_Script_2
Quest_BuildingAnExhibit_Active_PersonB_Script_1:
	goto Quest_BuildingAnExhibit_PersonB_Decline_Dialogue
	return

Quest_BuildingAnExhibit_Active_PersonB_Script_2:
	call Quest_BuildingAnExhibit_PersonB_Explain_Dialogue
	goto Quest_BuildingAnExhibit_Active_PersonB_Script_1


Quest_BuildingAnExhibit_PersonB_Explain_Dialogue::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	msgbox gText_BuildingAnExhibit_TheyWereTrulyOneOfMy
	msgbox gText_BuildingAnExhibit_ItWasSoGreatToSee
	return


Quest_BuildingAnExhibit_PersonB_Decline_Dialogue::
	msgbox gText_BuildingAnExhibit_AsATeacherIWant, MSGBOX_NPC
	end


Quest_BuildingAnExhibit_Interact_PersonC_Script::
	lock
	returnqueststate QUEST_BUILDINGANEXHIBIT
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_BuildingAnExhibit_Interact_PersonC_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_BuildingAnExhibit_Interact_PersonC_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_BuildingAnExhibit_Interact_PersonC_Script_4
	msgbox gText_Castro_PlaceholderOaklandFan, MSGBOX_NPC
Quest_BuildingAnExhibit_Interact_PersonC_Script_1:
	end

Quest_BuildingAnExhibit_Interact_PersonC_Script_3:
	goto Quest_BuildingAnExhibit_Active_PersonC_Script
	goto Quest_BuildingAnExhibit_Interact_PersonC_Script_1

Quest_BuildingAnExhibit_Interact_PersonC_Script_4:
	msgbox gText_BuildingAnExhibit_IWasMugged, MSGBOX_NPC
	goto Quest_BuildingAnExhibit_Interact_PersonC_Script_1


Quest_BuildingAnExhibit_Active_PersonC_Script::
	faceplayer
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingAnExhibit_Active_PersonC_Script_2
Quest_BuildingAnExhibit_Active_PersonC_Script_1:
	goto Quest_BuildingAnExhibit_PersonC_Decline_Dialogue
	return

Quest_BuildingAnExhibit_Active_PersonC_Script_2:
	call Quest_BuildingAnExhibit_PersonC_Explain_Dialogue
	goto Quest_BuildingAnExhibit_Active_PersonC_Script_1


Quest_BuildingAnExhibit_PersonC_Explain_Dialogue::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	msgbox gText_BuildingAnExhibit_IWasAJanitor
	msgbox gText_BuildingAnExhibit_TheseSpikesWereSpecial
	return


Quest_BuildingAnExhibit_PersonC_Decline_Dialogue::
	msgbox gText_BuildingAnExhibit_IDontHoldOnto, MSGBOX_NPC
	end


Quest_BuildingAnExhibit_Interact_PersonD_Script::
	lock
	returnqueststate QUEST_BUILDINGANEXHIBIT
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_BuildingAnExhibit_Interact_PersonD_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_BuildingAnExhibit_Interact_PersonD_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_BuildingAnExhibit_Interact_PersonD_Script_4
	msgbox gText_Oakland_PlaceholderOaklandFan, MSGBOX_NPC
Quest_BuildingAnExhibit_Interact_PersonD_Script_1:
	end

Quest_BuildingAnExhibit_Interact_PersonD_Script_3:
	goto Quest_BuildingAnExhibit_Active_PersonD_Script
	goto Quest_BuildingAnExhibit_Interact_PersonD_Script_1

Quest_BuildingAnExhibit_Interact_PersonD_Script_4:
	msgbox gText_BuildingAnExhibit_MyBobbleheads, MSGBOX_NPC
	goto Quest_BuildingAnExhibit_Interact_PersonD_Script_1


Quest_BuildingAnExhibit_Active_PersonD_Script::
	faceplayer
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingAnExhibit_Active_PersonD_Script_2
Quest_BuildingAnExhibit_Active_PersonD_Script_1:
	goto Quest_BuildingAnExhibit_PersonD_Decline_Dialogue
	return

Quest_BuildingAnExhibit_Active_PersonD_Script_2:
	call Quest_BuildingAnExhibit_PersonD_Explain_Dialogue
	goto Quest_BuildingAnExhibit_Active_PersonD_Script_1


Quest_BuildingAnExhibit_PersonD_Explain_Dialogue::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_BUILDINGANEXHIBIT, SUB_QUEST_4
	msgbox gText_BuildingAnExhibit_OhMyBobbleheadCollection
	msgbox gText_BuildingAnExhibit_ItsTheLastThing
	return


Quest_BuildingAnExhibit_PersonD_Decline_Dialogue::
	msgbox gText_BuildingAnExhibit_ImSorryICouldNeverPart, MSGBOX_NPC
	end


Quest_BuildingAnExhibit_Reward_Dialogue::
	msgbox gText_BuildingAnExhibit_TrackedThemAllDown
	fadescreen FADE_TO_BLACK
	msgbox gText_BuildingAnExhibit_PlayerExplainedTheir
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox gText_BuildingAnExhibit_WowAllOfThem
	msgbox gText_BuildingAnExhibit_NoMatterThisWasEducational
	msgbox gText_BuildingAnExhibit_IAppreciateYourEfforts
	giveitem ITEM_TM01, 1
	msgbox gText_BuildingAnExhibit_IllSeeYouAround
	closemessage
	applymovement 7, Quest_BuildingAnExhibit_WalkAway_Movement
	waitmovement 7
	removeobject 7
	setvar VAR_WHITNEY_STATE, QUEST_1_COMPLETE
	completequest QUEST_BUILDINGANEXHIBIT
	release
	end


Quest_BuildingAnExhibit_WalkAway_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

gText_BuildingAnExhibit_HeyPlayer::
	.string "Hey {PLAYER}$"

gText_BuildingAnExhibit_WereBuilding::
	.string "were building an exhibit for the oakland\n"
	.string "colisseum. real sad to see it being torn\l"
	.string "down, you know$"

gText_BuildingAnExhibit_ThereAreSomeReallyHard::
	.string "there are some really hard items that\n"
	.string "we can't seem too get a hold off. can\l"
	.string "you help us? we need... a ticket stub to\l"
	.string "the last battle in the stadium, a\l"
	.string "signed champion's cape, the toxic\l"
	.string "spikes from the field of the first\l"
	.string "battle, a limited edition set of Drasna\l"
	.string "bobbleheads.$"

gText_BuildingAnExhibit_ItsLikeHuntingANeedle::
	.string "its like hunting a needle in a haystack!$"

gText_BuildingAnExhibit_MyHomeWasInvaded::
	.string "my home was invdaded, they took so much\n"
	.string "stuff including the ticket stubs. i\l"
	.string "can't shake the feeling its related to\l"
	.string "that exhibit you were talkinga bout...$"

gText_BuildingAnExhibit_MyTicketsFromThe2015ChampionshipGame::
	.string "my tickets from the 2015 championship\n"
	.string "match are among my prized possessions$"

gText_BuildingAnExhibit_ThatMatchWasElectric::
	.string "that match was absolutely electric! i'll\n"
	.string "never forget that.$"

gText_BuildingAnExhibit_ThatExhibitSoundsCool::
	.string "that exhibit sounds cool, but I could\n"
	.string "never give up my tickets.$"

gText_BuildingAnExhibit_TheChampionsCapeIsGone::
	.string "The signed cape is gone! I was attacked\n"
	.string "by a hooded figure with an aerodactyl.\l"
	.string "they made me hand it off.$"

gText_BuildingAnExhibit_TheyWereTrulyOneOfMy::
	.string "the old champion was one of my\n"
	.string "students. one of my favorites too.\l"
	.string "after they became champion, he came by\l"
	.string "and gave me a signed cape to thank me$"

gText_BuildingAnExhibit_ItWasSoGreatToSee::
	.string "it was so great to see them do well, and\n"
	.string "even greater to see them acknowledge\l"
	.string "me!$"

gText_BuildingAnExhibit_AsATeacherIWant::
	.string "as a teacher, i know this exhibit is\n"
	.string "important for teaching, but I couldn't\l"
	.string "possibly donate it$"

gText_BuildingAnExhibit_IWasMugged::
	.string "i have a bit of a gambling problem... and\n"
	.string "i had to gamble away the spikes. i lost\l"
	.string "everything. my wife is gonna kill me...$"

gText_BuildingAnExhibit_IWasAJanitor::
	.string "i was a janitor at the old Oakland\n"
	.string "colisseum. this ninja from another\l"
	.string "region had come to challenge the Elite\l"
	.string "Four and he was so cool and used these\l"
	.string "to help him win.$"

gText_BuildingAnExhibit_TheseSpikesWereSpecial::
	.string "she didn't become champion but i\n"
	.string "thought they were cool so I took them\l"
	.string "home and they're part of my collection$"

gText_BuildingAnExhibit_IDontHoldOnto::
	.string "Janine is one of my favorite trainers.\n"
	.string "an idol even! this is as close as I'm\l"
	.string "going to get from him. i can't give 'em\l"
	.string "up$"

gText_BuildingAnExhibit_MyBobbleheads::
	.string "my bobbleheads were taken! i was going\n"
	.string "to the hardware store for shelves, I\l"
	.string "set them down on the counter and\l"
	.string "forgot them... and when i went back,\l"
	.string "they were gone!$"

gText_BuildingAnExhibit_OhMyBobbleheadCollection::
	.string "oh my bobblehead collection is amazing.\n"
	.string "they're one of a kind, because all the\l"
	.string "heads are Drasna instead of each of\l"
	.string "the Elite Four members.$"

gText_BuildingAnExhibit_ItsTheLastThing::
	.string "my son worked at the factory that\n"
	.string "created these and these were created\l"
	.string "by mistake... but he knew that Drasna\l"
	.string "was my favorite, so he brought them\l"
	.string "home for me! i'll never forget.$"

gText_BuildingAnExhibit_ImSorryICouldNeverPart::
	.string "Oh? You're looking to buy them from me?\n"
	.string "Sorry, I could never part with them.$"

gText_BuildingAnExhibit_TrackedThemAllDown::
	.string "You tracked them all down? Well, let's\n"
	.string "hear the details!$"

gText_BuildingAnExhibit_PlayerExplainedTheir::
	.string "{PLAYER} explained their encounters\n"
	.string "with the owners of the items.$"

gText_BuildingAnExhibit_WowAllOfThem::
	.string "wow, all of them are unwilling to sell.\n"
	.string "increidible.$"

gText_BuildingAnExhibit_NoMatterThisWasEducational::
	.string "no matter. this was educational, at\n"
	.string "least. a shame though.$"

gText_BuildingAnExhibit_IAppreciateYourEfforts::
	.string "i appreciate your efforts. Please take\n"
	.string "this.$"

gText_BuildingAnExhibit_IllSeeYouAround::
	.string "I'll see you around$"
