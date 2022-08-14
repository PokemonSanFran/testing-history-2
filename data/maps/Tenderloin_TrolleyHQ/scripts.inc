Tenderloin_TrolleyHQ_MapScripts::
	.byte 0


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


Tenderloin_TrolleyHQ_Machine_Script_Text_0:
	.string "if that quest is acitve,\pyou rode the BART ten times.\pTalk to the guy now$"

gText_Tenderloin_TrolleyHQ_DoYouHave::
	.string "Do you have any idea what it takes to\n"
	.string "make sure all the trolleys run on time?\l"
	.string "Especially when ridership is down...$"
