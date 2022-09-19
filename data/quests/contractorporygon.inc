Quest_ContractorPorygon_Debug_Script::
	addvar VAR_TEMP_0, 1
	additem ITEM_LAVA_COOKIE, 1
	additem ITEM_RAGE_CANDY_BAR, 1
	additem ITEM_PEWTER_CRUNCHIES, 1
	end


Quest_ContractorPorygon_StartQuest_Dialogue::
	lock
	faceplayer
	msgbox gText_ContractorPorygon_HeyWereAStartup
	msgbox gText_ContractorPorygon_WeHaventEatenOrSlept
	msgbox gText_ContractorPorygon_WhenWeDoGetHungry
	closemessage
	startquest QUEST_CONTRACTORPORYGON
	release
	end


Quest_ContractorPorygon_Subquest1_Ineligible_Dialogue::
	msgbox gText_ContractorPorygon_WantToGetOutThisUpgrade, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	end


Quest_ContractorPorygon_Subquest2_Ineligible_Dialogue::
	msgbox gText_ContractorPorygon_TheyWantMeToReplicate, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	end


Quest_ContractorPorygon_Subquest3_Ineligible_Dialogue::
	msgbox gText_ContractorPorygon_NotReallyHungryYet, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	end


Quest_ContractorPorygon_Subquest1_Request_Dialogue::
	lock
	faceplayer
	msgbox gText_ContractorPorygon_OkayGoodStoppingPoint
	msgbox gText_ContractorPorygon_CouldIGetDumplings
	checkitem ITEM_PEWTER_CRUNCHIES, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_ContractorPorygon_Subquest1_Request_Dialogue_2
Quest_ContractorPorygon_Subquest1_Request_Dialogue_1:
	closemessage
	release
	end

Quest_ContractorPorygon_Subquest1_Request_Dialogue_2:
	goto Quest_ContractorPorygon_Subquest1_Thanks_Dialogue
	goto Quest_ContractorPorygon_Subquest1_Request_Dialogue_1


Quest_ContractorPorygon_Subquest2_Request_Dialogue::
	lock
	faceplayer
	msgbox gText_ContractorPorygon_IThinkTheDisc
	msgbox gText_ContractorPorygon_AreYouStillGetting
	checkitem ITEM_LAVA_COOKIE, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_ContractorPorygon_Subquest2_Request_Dialogue_2
Quest_ContractorPorygon_Subquest2_Request_Dialogue_1:
	closemessage
	release
	end

Quest_ContractorPorygon_Subquest2_Request_Dialogue_2:
	goto Quest_ContractorPorygon_Subquest2_Thanks_Dialogue
	goto Quest_ContractorPorygon_Subquest2_Request_Dialogue_1


Quest_ContractorPorygon_Subquest3_Request_Dialogue::
	lock
	faceplayer
	msgbox gText_ContractorPorygon_TheProgressTheyreMaking
	msgbox gText_ContractorPorygon_IDidntRealize
	checkitem ITEM_RAGE_CANDY_BAR, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_ContractorPorygon_Subquest3_Request_Dialogue_2
Quest_ContractorPorygon_Subquest3_Request_Dialogue_1:
	closemessage
	release
	end

Quest_ContractorPorygon_Subquest3_Request_Dialogue_2:
	goto Quest_ContractorPorygon_Reward_Dialogue
	goto Quest_ContractorPorygon_Subquest3_Request_Dialogue_1


Quest_ContractorPorygon_GivePorygon_Script::
	switch VAR_LAST_TALKED
	case 2, Quest_ContractorPorygon_GivePorygon_Script_3
	case 1, Quest_ContractorPorygon_GivePorygon_Script_4
	case 3, Quest_ContractorPorygon_GivePorygon_Script_5
Quest_ContractorPorygon_GivePorygon_Script_1:
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_ContractorPorygon_YouRecievedA
	waitmessage
	waitfanfare
	return

Quest_ContractorPorygon_GivePorygon_Script_3:
	bufferspeciesname STR_VAR_2, SPECIES_PORYGON
	givecustommon SPECIES_PORYGON, 1, ITEM_EVIOLITE, ITEM_POKE_BALL, NATURE_MODEST, 1, 0, 0, 0, 0, 0, 0, , , , , , , MOVE_TRI_ATTACK, MOVE_NONE, MOVE_NONE, MOVE_NONE
	goto Quest_ContractorPorygon_GivePorygon_Script_1

Quest_ContractorPorygon_GivePorygon_Script_4:
	bufferspeciesname STR_VAR_2, SPECIES_PORYGON_Z
	givecustommon SPECIES_PORYGON_Z, 47, ITEM_DUBIOUS_DISC, ITEM_POKE_BALL, NATURE_BOLD, 0, 132, 0, 252, 72, 52, 0, 31, 31, 31, 31, 31, 31, MOVE_NASTY_PLOT, MOVE_HYPER_BEAM, MOVE_EERIE_IMPULSE, MOVE_RECOVER
	goto Quest_ContractorPorygon_GivePorygon_Script_1

Quest_ContractorPorygon_GivePorygon_Script_5:
	bufferspeciesname STR_VAR_2, SPECIES_PORYGON2
	givecustommon SPECIES_PORYGON2, 26, ITEM_UPGRADE, ITEM_POKE_BALL, NATURE_QUIET, 1, 252, 0, 160, 0, 16, 80, , , , , , , MOVE_TRICK_ROOM, MOVE_NONE, MOVE_NONE, MOVE_NONE
	goto Quest_ContractorPorygon_GivePorygon_Script_1


Quest_ContractorPorygon_Subquest1_Thanks_Dialogue::
	lock
	faceplayer
	msgbox gText_ContractorPorygon_ScoreSalad
	closemessage
	call Quest_ContractorPorygon_GivePorygon_Script
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CONTRACTORPORYGON, SUB_QUEST_1
	release
	end


Quest_ContractorPorygon_Subquest2_Thanks_Dialogue::
	lock
	faceplayer
	msgbox gText_ContractorPorygon_YesssDumpling
	closemessage
	call Quest_ContractorPorygon_GivePorygon_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CONTRACTORPORYGON, SUB_QUEST_2
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	release
	end


Quest_ContractorPorygon_Subquest1_Script::
	special GetNumberOfBadges
	compare VAR_RESULT, 3
	goto_if_lt Quest_ContractorPorygon_Subquest1_Script_2
Quest_ContractorPorygon_Subquest1_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CONTRACTORPORYGON, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_eq Quest_ContractorPorygon_Subquest1_Script_4
	goto Quest_ContractorPorygon_Focused_Dialogue
	return

Quest_ContractorPorygon_Subquest1_Script_2:
	goto Quest_ContractorPorygon_Subquest1_Ineligible_Dialogue
	goto Quest_ContractorPorygon_Subquest1_Script_1

Quest_ContractorPorygon_Subquest1_Script_4:
	goto Quest_ContractorPorygon_Subquest1_Request_Dialogue
	return


Quest_ContractorPorygon_Subquest2_Script::
	special GetNumberOfBadges
	compare VAR_RESULT, 6
	goto_if_lt Quest_ContractorPorygon_Subquest2_Script_2
Quest_ContractorPorygon_Subquest2_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CONTRACTORPORYGON, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_eq Quest_ContractorPorygon_Subquest2_Script_4
	goto Quest_ContractorPorygon_Focused_Dialogue
	return

Quest_ContractorPorygon_Subquest2_Script_2:
	goto Quest_ContractorPorygon_Subquest2_Ineligible_Dialogue
	goto Quest_ContractorPorygon_Subquest2_Script_1

Quest_ContractorPorygon_Subquest2_Script_4:
	goto Quest_ContractorPorygon_Subquest2_Request_Dialogue
	return


Quest_ContractorPorygon_Subquest3_Script::
	setvar VAR_TEMP_2, 0
	special GetNumberOfBadges
	compare VAR_RESULT, 7
	goto_if_gt Quest_ContractorPorygon_Subquest3_Script_2
Quest_ContractorPorygon_Subquest3_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CONTRACTORPORYGON, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_ContractorPorygon_Subquest3_Script_5
Quest_ContractorPorygon_Subquest3_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_CONTRACTORPORYGON, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_ContractorPorygon_Subquest3_Script_8
Quest_ContractorPorygon_Subquest3_Script_7:
	compare VAR_TEMP_2, 3
	goto_if_eq Quest_ContractorPorygon_Subquest3_Script_10
	goto Quest_ContractorPorygon_Subquest3_Ineligible_Dialogue
	return

Quest_ContractorPorygon_Subquest3_Script_2:
	addvar VAR_TEMP_2, 1
	goto Quest_ContractorPorygon_Subquest3_Script_1

Quest_ContractorPorygon_Subquest3_Script_5:
	addvar VAR_TEMP_2, 1
	goto Quest_ContractorPorygon_Subquest3_Script_4

Quest_ContractorPorygon_Subquest3_Script_8:
	addvar VAR_TEMP_2, 1
	goto Quest_ContractorPorygon_Subquest3_Script_7

Quest_ContractorPorygon_Subquest3_Script_10:
	goto Quest_ContractorPorygon_Subquest3_Request_Dialogue
	return


Quest_ContractorPorygon_HandleMoney_Script::
	showmoneybox 0, 0
	waitbuttonpress
	addmoney 200000
	playse SE_SHOP
	updatemoneybox 0
	waitse
	waitbuttonpress
	hidemoneybox
	closemessage
	return


Quest_ContractorPorygon_Reward_Dialogue::
	msgbox gText_ContractorPorygon_HellYesCurry
	msgbox gText_ContractorPorygon_ThisShouldPay
	call Quest_ContractorPorygon_HandleMoney_Script
	msgbox gText_ContractorPorygon_AndForHelpingUs
	call Quest_ContractorPorygon_GivePorygon_Script
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_CONTRACTORPORYGON, SUB_QUEST_3
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	completequest QUEST_CONTRACTORPORYGON
	release
	end


Quest_ContractorPorygon_Completed_Dialogue::
	msgbox gText_ContractorPorygon_IThinkWereGonnaMake, MSGBOX_NPC
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement VAR_LAST_TALKED
	end


Quest_ContractorPorygon_Focused_Dialogue::
	lock
	msgbox gText_ContractorPorygon_Focused
	closemessage
	release
	end


Quest_ContractorPorygon_Interact_Shan_Script::
	returnqueststate QUEST_CONTRACTORPORYGON
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ContractorPorygon_Interact_Shan_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Quest_ContractorPorygon_Interact_Shan_Script_3
	goto Quest_ContractorPorygon_StartQuest_Dialogue
	return

Quest_ContractorPorygon_Interact_Shan_Script_2:
	goto Quest_ContractorPorygon_Subquest3_Script
	return

Quest_ContractorPorygon_Interact_Shan_Script_3:
	goto Quest_ContractorPorygon_Completed_Dialogue
	return


Quest_ContractorPorygon_Interact_Evan_Script::
	returnqueststate QUEST_CONTRACTORPORYGON
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ContractorPorygon_Interact_Evan_Script_2
	goto Quest_ContractorPorygon_Focused_Dialogue
	return

Quest_ContractorPorygon_Interact_Evan_Script_2:
	goto Quest_ContractorPorygon_Subquest1_Script
	return


Quest_ContractorPorygon_Interact_Nathan_Script::
	returnqueststate QUEST_CONTRACTORPORYGON
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ContractorPorygon_Interact_Nathan_Script_2
	goto Quest_ContractorPorygon_Focused_Dialogue
	return

Quest_ContractorPorygon_Interact_Nathan_Script_2:
	goto Quest_ContractorPorygon_Subquest2_Script
	return


gText_ContractorPorygon_HeyWereAStartup::
	.string "hey we're a startup. the league asked\n"
	.string "us to replicate the work of Cinnabar\l"
	.string "Pokemon Lab and create Porygon... and\l"
	.string "its evolutions... in one work$"

gText_ContractorPorygon_WeHaventEatenOrSlept::
	.string "its a tough task. we haven't eaten or\n"
	.string "slept in about 90 hours$"

gText_ContractorPorygon_WhenWeDoGetHungry::
	.string "when we do get hungry, we're not gonna\n"
	.string "have time to get food. could you swing\l"
	.string "by later and grab food for us? we'll\l"
	.string "tell you what we want.$"

gText_ContractorPorygon_WantToGetOutThisUpgrade::
	.string "want to get out this up-grade.... and i'm\n"
	.string "so close! after this block of code, I'll\l"
	.string "eat...$"

gText_ContractorPorygon_TheyWantMeToReplicate::
	.string "they want me to replicate the dubious\n"
	.string "disc? that's why its DUBIOUS!$"

gText_ContractorPorygon_NotReallyHungryYet::
	.string "not really hungry right now... maybe\n"
	.string "later though. you're probably\l"
	.string "wondering why we couldn't just order\l"
	.string "delievery, right? well, we're testing\l"
	.string "the Porygon on our phones! can't use\l"
	.string "them for anything else while the tests\l"
	.string "are running, haha.$"

gText_ContractorPorygon_OkayGoodStoppingPoint::
	.string "okay, good stopping point!$"

gText_ContractorPorygon_CouldIGetDumplings::
	.string "could i get some dumplings? dumpling\n"
	.string "king in the sunset is the best spot for\l"
	.string "them.$"

gText_ContractorPorygon_IThinkTheDisc::
	.string "i think the disc is done....$"

gText_ContractorPorygon_AreYouStillGetting::
	.string "i hear you were getting us food, is that\n"
	.string "still a thing? Yeah? can I get a salad\l"
	.string "from Sweetgreeen? It's in Berkeley.$"

gText_ContractorPorygon_TheProgressTheyreMaking::
	.string "the progress they're making is fucking\n"
	.string "insane! are the prototypes working\l"
	.string "well?$"

gText_ContractorPorygon_IDidntRealize::
	.string "i didn't realize how hungry i was gonna\n"
	.string "be$"

gText_ContractorPorygon_ScoreSalad::
	.string "score! salad. thank you so much! i just\n"
	.string "finished this, give is a try.$"

gText_ContractorPorygon_YesssDumpling::
	.string "yesssss dumplings this is gonna be so\n"
	.string "good. here, take this Pokemon.$"

gText_ContractorPorygon_HellYesCurry::
	.string "hellllll yes curry! UGH this shit is\n"
	.string "gonna slap.$"

gText_ContractorPorygon_ThisShouldPay::
	.string "This cash should cover the cost of\n"
	.string "lunch, right??$"

gText_ContractorPorygon_AndForHelpingUs::
	.string "And for helping us, you can have this\n"
	.string "too. You're a beta tester!$"

gText_ContractorPorygon_IThinkWereGonnaMake::
	.string "I think we're gonna make the deadline!$"

gText_ContractorPorygon_Focused::
	.string "Hmm.....$"

gText_ContractorPorygon_YouRecievedA::
	.string "You recieved a {STR_VAR_2}!$"
