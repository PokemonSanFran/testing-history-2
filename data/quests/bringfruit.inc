Quest_BringFruit_Interact_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BRINGFRUIT
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_Interact_Script_2
Quest_BringFruit_Interact_Script_1:
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_BRINGFRUIT
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_Interact_Script_5
Quest_BringFruit_Interact_Script_4:
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BRINGFRUIT
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_Interact_Script_8
	goto Quest_BringFruit_CheckBadges
Quest_BringFruit_Interact_Script_7:
	closemessage
	end

Quest_BringFruit_Interact_Script_2:
	goto Quest_BringFruit_PostQuest_Script
	goto Quest_BringFruit_Interact_Script_1

Quest_BringFruit_Interact_Script_5:
	goto Quest_BringFruit_CheckPlayerBag_Script
	goto Quest_BringFruit_Interact_Script_4

Quest_BringFruit_Interact_Script_8:
	goto Quest_BringFruit_DuringQuest_Script
	goto Quest_BringFruit_Interact_Script_7


Quest_BringFruit_PostQuest_Script::
	compare VAR_STORYLINE_STATE, STORY_WON_FINALS
	goto_if_lt Quest_BringFruit_PostQuest_Script_2
	msgbox gText_BringFruit_ChampionPlayerMyFriend, MSGBOX_NPC, SPEAKER_HESTER
Quest_BringFruit_PostQuest_Script_1:
	end

Quest_BringFruit_PostQuest_Script_2:
	msgbox gText_BringFruit_PlayerMyFriend, MSGBOX_NPC, SPEAKER_HESTER
	goto Quest_BringFruit_PostQuest_Script_1


Quest_BringFruit_CheckPlayerBag_Script::
	msgbox gText_BringFruit_MuchMoreNicer, MSGBOX_NPC, SPEAKER_HESTER
	checkitemspace ITEM_LEFTOVERS, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_CheckPlayerBag_Script_1
	goto Quest_BringFruit_PlayerBagFull_Script
	return

Quest_BringFruit_CheckPlayerBag_Script_1:
	lock
	faceplayer
	call Quest_BringFruit_PlayerBagHasSpace_Script
	release
	end


Quest_BringFruit_PlayerBagHasSpace_Script::
	giveitem ITEM_LEFTOVERS, 1
	showmoneybox 0, 0
	delay 30
	addmoney 30000, 0
	updatemoneybox
	delay 60
	waitbuttonpress
	hidemoneybox
	completequest QUEST_BRINGFRUIT
	return


Quest_BringFruit_PlayerBagFull_Script::
	msgbox gText_BringFruit_YouCarrySoMuch, MSGBOX_NPC, SPEAKER_HESTER
	end


Quest_BringFruit_DuringQuest_Script::
	checkitem ITEM_WATMEL_BERRY, 6
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_DuringQuest_Script_1
	msgbox gText_BringFruit_PleaseDontLeave, MSGBOX_NPC, SPEAKER_HESTER
	end

Quest_BringFruit_DuringQuest_Script_1:
	goto Quest_BringFruit_PlayerHasFruit_Script
	return


Quest_BringFruit_PlayerHasFruit_Script::
	msgbox gText_BringFruit_MyFriendThose, MSGBOX_NPC, SPEAKER_HESTER
	msgbox gText_BringFruit_YeahYouSeemed, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_BringFruit_YesYesYes, MSGBOX_NPC, SPEAKER_HESTER
	msgbox gText_BringFruit_ItWasJustAFew, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_BringFruit_NoNoNo, MSGBOX_NPC, SPEAKER_HESTER
	removeitem ITEM_WATMEL_BERRY, 6
	questmenu QUEST_MENU_SET_REWARD, QUEST_BRINGFRUIT
	goto Quest_BringFruit_CheckPlayerBag_Script
	return


Quest_BringFruit_PreQuestScript::
	msgbox gText_BringFruit_CouldIPlease, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_BringFruit_SorryMyFriend, MSGBOX_NPC, SPEAKER_HESTER
	msgbox gText_BringFruit_AwThoseAre, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_BringFruit_IUsuallyGo, MSGBOX_NPC, SPEAKER_HESTER
	msgbox gText_BringFruit_ThatsOkayCan, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_BringFruit_IJustNeedSix, MSGBOX_NPC, SPEAKER_HESTER
	msgbox gText_BringFruit_OkayIThink, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_BringFruit_PleaseDontLeave, MSGBOX_NPC, SPEAKER_HESTER
	msgbox gText_BringFruit_ActuallyIllBeRight, MSGBOX_NPC, SPEAKER_ZOEY
	startquest QUEST_BRINGFRUIT
	return


Quest_BringFruit_NotEnoughBadges::
	msgbox gText_BringFruit_IAmStillSetting, MSGBOX_NPC, SPEAKER_HESTER
	return


Quest_BringFruit_CheckBadges::
	special GetNumberOfBadges
	compare VAR_RESULT, 0
	goto_if_gt Quest_BringFruit_CheckBadges_2
	call Quest_BringFruit_NotEnoughBadges
Quest_BringFruit_CheckBadges_1:
	release
	end

Quest_BringFruit_CheckBadges_2:
	call Quest_BringFruit_PreQuestScript
	goto Quest_BringFruit_CheckBadges_1


gText_BringFruit_IAmStillSetting::
	.string "Sorry my friend, I am still setting up.\n"
	.string "Please come back later!$"

gText_BringFruit_CouldIPlease::
	.string "Could I please have a cup of Watmel and\n"
	.string "Pinap Berries?$"

gText_BringFruit_SorryMyFriend::
	.string "Sorry my friend, I don't have any more\n"
	.string "Watmel Berry right now!$"

gText_BringFruit_AwThoseAre::
	.string "(Aw, those are my favorite!) Okay, could\n"
	.string "I just get Pinap instead?$"

gText_BringFruit_IUsuallyGo::
	.string "I usually go to the farmer's market\n"
	.string "before work, but I had to run here to\l"
	.string "open up in time...$"

gText_BringFruit_ThatsOkayCan::
	.string "That's okay, can I just get Pinap\n"
	.string "Berries instead with extra chili-lime?$"

gText_BringFruit_IJustNeedSix::
	.string "I just need six Watmel Berries to make\n"
	.string "it through this shift... those are my\l"
	.string "best sellers!$"

gText_BringFruit_OkayIThink::
	.string "(Okay, I think I need to get this guy\n"
	.string "some Watmel Berries.)$"

gText_BringFruit_PleaseDontLeave::
	.string "Please don't leave a negative review\n"
	.string "online! I usually have lots and lots of\l"
	.string "fruits!$"

gText_BringFruit_ActuallyIllBeRight::
	.string "Actually, I'll be right back...$"

gText_BringFruit_MyFriendThose::
	.string "My friend! Those Watmel Berries!$"

gText_BringFruit_YeahYouSeemed::
	.string "Yeah, you seemed stressed out, so I\n"
	.string "brought you some. Six, right?$"

gText_BringFruit_YesYesYes::
	.string "Yes yes yes! I pay you, you're so nice\n"
	.string "ma'amsir.$"

gText_BringFruit_ItWasJustAFew::
	.string "It was just a few berries, it's no big\n"
	.string "deal!$"

gText_BringFruit_NoNoNo::
	.string "No no no, you are so kind!$"

gText_BringFruit_MuchMoreNicer::
	.string "Much more nicer than other Trainer!$"

gText_BringFruit_YouCarrySoMuch::
	.string "You carry so much my friend! Empty your\n"
	.string "bag and come back.$"

gText_BringFruit_PlayerMyFriend::
	.string "{PLAYER} my friend! Watmel and Pinap\n"
	.string "with extra chili lime?$"

gText_BringFruit_ChampionPlayerMyFriend::
	.string "Champion {PLAYER}, my friend! Watmel\n"
	.string "and Pinap with extra chili lime?$"
