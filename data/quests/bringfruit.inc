Quest_BringFruit_HideObject_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RETURNDOLL
	compare VAR_RESULT, 0
	goto_if_eq Quest_BringFruit_HideObject_Script_2
Quest_BringFruit_HideObject_Script_1:
	checkitem ITEM_LOST_DOLL, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_HideObject_Script_4
	return

Quest_BringFruit_HideObject_Script_2:
	setflag FLAG_TEMP_3
	goto Quest_BringFruit_HideObject_Script_1

Quest_BringFruit_HideObject_Script_4:
	setflag FLAG_TEMP_3
	return


Quest_BringFruit_Interact_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RETURNDOLL
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_Interact_Script_2
Quest_BringFruit_Interact_Script_1:
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_RETURNDOLL
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_Interact_Script_5
Quest_BringFruit_Interact_Script_4:
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_RETURNDOLL
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_Interact_Script_8
	goto Quest_BringFruit_PreQuestScript
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
	msgbox gText_BringFruit_IHeardMommy, MSGBOX_NPC
	end


Quest_BringFruit_CheckPlayerBag_Script::
	checkitemspace ITEM_CHOICE_BAND, 1
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
	msgbox gText_BringFruit_YouCanHave, MSGBOX_DEFAULT
	giveitem ITEM_CHOICE_BAND, 1
	completequest QUEST_RETURNDOLL
	return


Quest_BringFruit_PlayerBagFull_Script::
	msgbox gText_BringFruit_YourBagLooks, MSGBOX_NPC
	end


Quest_BringFruit_DuringQuest_Script::
	checkitem ITEM_LOST_DOLL, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFruit_DuringQuest_Script_1
	msgbox gText_BringFruit_WhenImGrownUp, MSGBOX_NPC
	end

Quest_BringFruit_DuringQuest_Script_1:
	goto Quest_BringFruit_PlayerHasDoll_Script
	return


Quest_BringFruit_PlayerHasDoll_Script::
	msgbox gText_BringFruit_ThatsMyDoll, MSGBOX_NPC
	removeitem ITEM_LOST_DOLL, 1
	questmenu QUEST_MENU_SET_REWARD, QUEST_RETURNDOLL
	goto Quest_BringFruit_CheckPlayerBag_Script
	return


Quest_BringFruit_PreQuestScript::
	msgbox gText_BringFruit_DaddyAndI, MSGBOX_NPC
	msgbox gText_BringFruit_WhenImGrownUp, MSGBOX_NPC
	startquest QUEST_RETURNDOLL
	return


gText_BringFruit_DaddyAndI::
	.string "Daddy and I moved here from Sunset. I\n"
	.string "like it here, but I miss my doll.$"

gText_BringFruit_WhenImGrownUp::
	.string "When I'm a grown up like you, I'm going\n"
	.string "to go back and get my doll!$"

gText_BringFruit_ThatsMyDoll::
	.string "That's my doll! MY DOLL! You found her!\n"
	.string "Thank you so much!$"

gText_BringFruit_YouCanHave::
	.string "You can have her headband! It matched\n"
	.string "her dress, but I want you to have it\l"
	.string "instead.$"

gText_BringFruit_IHeardMommy::
	.string "I heard Mommy tell her friend we got\n"
	.string "priced out of our old neighborhood.\l"
	.string "What does priced out mean?$"

gText_BringFruit_YourBagLooks::
	.string "YOU BAG IS FULL! Take some stuff out of\n"
	.string "your bag, I wanna give you something.$"
