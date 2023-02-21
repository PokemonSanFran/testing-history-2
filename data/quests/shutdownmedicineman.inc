Quest_ShutDownMedicineMan_HideDealer_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_SHUTDOWNMEDICINEMAN
	compare VAR_RESULT, 0
	goto_if_ne Quest_ShutDownMedicineMan_HideDealer_Script_2
Quest_ShutDownMedicineMan_HideDealer_Script_1:
	return

Quest_ShutDownMedicineMan_HideDealer_Script_2:
	setflag FLAG_TEMP_3
	goto Quest_ShutDownMedicineMan_HideDealer_Script_1


Quest_ShutDownMedicineMan_ControlLeaderVisibility::
	special GetNumberOfBadges
	compare VAR_PRYCE_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_ShutDownMedicineMan_ControlLeaderVisibility_2
	compare VAR_RESULT, 8
	goto_if_lt Quest_ShutDownMedicineMan_ControlLeaderVisibility_2
Quest_ShutDownMedicineMan_ControlLeaderVisibility_1:
	return

Quest_ShutDownMedicineMan_ControlLeaderVisibility_2:
	setflag FLAG_TEMP_3
	goto Quest_ShutDownMedicineMan_ControlLeaderVisibility_1


Quest_ShutDownMedicineMan_Interact_Leader_Script::
	lock
	faceplayer
	returnqueststate QUEST_SHUTDOWNMEDICINEMAN
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_ShutDownMedicineMan_Interact_Leader_Script_2
	case QUEST_MENU_SET_REWARD, Quest_ShutDownMedicineMan_Interact_Leader_Script_3
	goto Quest_ShutDownMedicineMan_StartQuest_Dialogue
	return

Quest_ShutDownMedicineMan_Interact_Leader_Script_2:
	goto Quest_ShutDownMedicineMan_ActiveDialogue
	return

Quest_ShutDownMedicineMan_Interact_Leader_Script_3:
	goto Quest_ShutDownMedicineMan_Reward_Dialogue
	return


Quest_ShutDownMedicineMan_StartQuest_Dialogue::
	msgbox gText_ShutDownMedicineMan_WeHaveAnAssociate, , SPEAKER_DEFAULT
	msgbox gText_ShutDownMedicineMan_WantToMakeSure, , SPEAKER_DEFAULT
	startquest QUEST_SHUTDOWNMEDICINEMAN
	return


Quest_ShutDownMedicineMan_ActiveDialogue::
	msgbox gText_ShutDownMedicineMan_LetMeKnowWhen, MSGBOX_NPC, SPEAKER_DEFAULT
	end


Quest_ShutDownMedicineMan_MakePurchase_Dialogue::
	lock
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_SHUTDOWNMEDICINEMAN
	compare VAR_RESULT, 0
	goto_if_eq Quest_ShutDownMedicineMan_MakePurchase_Dialogue_2
	questmenu QUEST_MENU_SET_REWARD, QUEST_SHUTDOWNMEDICINEMAN
	msgbox gText_ShutDownMedicineMan_OkayMadeThePurchase, , SPEAKER_ZOEY, TAIL_THOUGHT
	msgbox gText_ShutDownMedicineMan_HeyCanIGetASelfie, , SPEAKER_ZOEY
	msgbox gText_ShutDownMedicineMan_OhMyGodYes, , SPEAKER_DEFAULT
	closemessage
	release
	end

Quest_ShutDownMedicineMan_MakePurchase_Dialogue_2:
	release
	end


Quest_ShutDownMedicineMan_Reward_Dialogue::
	msgbox gText_ShutDownMedicineMan_GoodWork, , SPEAKER_DEFAULT
	giveitem ITEM_ABILITY_CAPSULE, 1
	giveitem ITEM_ABILITY_PATCH, 1
	call Quest_ShutDownMedicineMan_HandleMoney_Script
	opendoor 28, 15
	waitdooranim
	applymovement 5, Quest_ShutDownMedicineMan_WalkInside_Movement
	waitmovement 5
	removeobject 5
	playse SE_EXIT
	closedoor 28, 15
	completequest QUEST_SHUTDOWNMEDICINEMAN
	return


Quest_ShutDownMedicineMan_HandleMoney_Script::
	showmoneybox 0, 0
	waitbuttonpress
	addmoney 2000
	playse SE_SHOP
	updatemoneybox 0
	waitse
	waitbuttonpress
	hidemoneybox
	closemessage
	return


Quest_ShutDownMedicineMan_WalkInside_Movement:
	walk_left
	walk_up
	step_end

gText_ShutDownMedicineMan_WeHaveAnAssociate::
	.string "we have an... associate over by\n"
	.string "lakemerrit that is selling herbal\l"
	.string "products$"

gText_ShutDownMedicineMan_WantToMakeSure::
	.string "we want to make sure his customer\n"
	.string "service is up to par, could you help us\l"
	.string "with a mystery shop? just go buy\l"
	.string "something and take a pic with him and\l"
	.string "then come back to me$"

gText_ShutDownMedicineMan_LetMeKnowWhen::
	.string "let me know when you're able to buy from\n"
	.string "that dude$"

gText_ShutDownMedicineMan_OkayMadeThePurchase::
	.string "okay made the purchase, now...$"

gText_ShutDownMedicineMan_HeyCanIGetASelfie::
	.string "hey can i get a selfie?$"

gText_ShutDownMedicineMan_OhMyGodYes::
	.string "absolutely yes! i hope you enjoy!$"

gText_ShutDownMedicineMan_GoodWork::
	.string "good work. got just the proof i needed.\n"
	.string "here's your payment.$"
