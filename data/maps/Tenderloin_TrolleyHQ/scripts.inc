Tenderloin_TrolleyHQ_MapScripts::
	.byte 0


Tenderloin_TrolleyHQ_Manager_Quest_Script::
	lock
	faceplayer
	goto_if_quest_inactive QUEST_ROCKCOLLECTOR, Quest_BetweenAStoneAndAHardPlace_Event_Script
	goto Quest_Rockcollector_Event_Script
	return


Tenderloin_TrolleyHQ_CounterWorker_Dialogue::
	msgbox gText_Tenderloin_TrolleyHQ_DoYouHave, MSGBOX_NPC
	end


Tenderloin_TrolleyHQ_Machine_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BETWEENASTONEANDAHARD
	compare VAR_RESULT, 0
	goto_if_ne Tenderloin_TrolleyHQ_Machine_Script_2
Tenderloin_TrolleyHQ_Machine_Script_1:
	msgbox Tenderloin_TrolleyHQ_Machine_Script_Text_0, MSGBOX_SIGN
	end

Tenderloin_TrolleyHQ_Machine_Script_2:
	questmenu QUEST_MENU_SET_REWARD, QUEST_BETWEENASTONEANDAHARD
	goto Tenderloin_TrolleyHQ_Machine_Script_1


Tenderloin_TrolleyHQ_Interact_Clerk_Script::
	goto_if_quest_not_inactive QUEST_FOODTRUCKBUREACRACY, Quest_Foodtruckbureaucracy_DOT_Active_Dialogue
	goto Tenderloin_TrolleyHQ_Clerk_Dialogue
	return


Tenderloin_TrolleyHQ_Clerk_Dialogue::
	msgbox gText_Tenderloin_TrolleyHQ_IHateHaving, MSGBOX_NPC, SPEAKER_ISIDORE
	end


Tenderloin_TrolleyHQ_Machine_Script_Text_0:
	.string "if that quest is acitve,\pyou rode the BART ten times.\pTalk to the guy now$"

gText_Tenderloin_TrolleyHQ_IHateHaving::
	.string "I hate having to leave the office to\n"
	.string "get food... but ordering Doordash is so\l"
	.string "expensive!$"

gText_Tenderloin_TrolleyHQ_DoYouHave::
	.string "Do you have any idea what it takes to\n"
	.string "make sure all the trolleys run on time?\l"
	.string "Especially when ridership is down...$"
