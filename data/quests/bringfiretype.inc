Quest_BringFireType_Interact_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BRINGFIRETYPE
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFireType_Interact_Script_2
Quest_BringFireType_Interact_Script_1:
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BRINGFIRETYPE
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFireType_Interact_Script_5
	call Quest_BringFireType_PreQuest_Script
Quest_BringFireType_Interact_Script_4:
	closemessage
	end

Quest_BringFireType_Interact_Script_2:
	goto Quest_BringFireType_PostQuest_Dialogue
	goto Quest_BringFireType_Interact_Script_1

Quest_BringFireType_Interact_Script_5:
	call Quest_BringFireType_DuringQuest_Dialogue
	goto Quest_BringFireType_Interact_Script_4


Quest_BringFireType_PostQuest_Dialogue::
	msgbox gText_BringFireType_WhatCanIGetYou, MSGBOX_NPC
	return


Quest_BringFireType_PlayerHasFireType_Script::
	msgbox gText_BringFireType_YouCaughtA, MSGBOX_NPC
	questmenu QUEST_MENU_SET_REWARD, QUEST_BRINGFIRETYPE
	giveitem ITEM_TM13_ICE_BEAM, 1
	completequest QUEST_BRINGFIRETYPE
	return


Quest_BringFireType_CheckFireType_Script::
	special IsFireTypeInParty
	compare VAR_RESULT, 0
	goto_if_ne Quest_BringFireType_CheckFireType_Script_1
	msgbox gText_BringFireType_IWonderIfICould, MSGBOX_NPC
	return

Quest_BringFireType_CheckFireType_Script_1:
	call Quest_BringFireType_PlayerHasFireType_Script
	return


Quest_BringFireType_PreQuest_Script::
	msgbox gText_BringFireType_WereOutOfPropane, MSGBOX_NPC
	startquest QUEST_BRINGFIRETYPE
	return


Quest_BringFireType_DuringQuest_Dialogue::
	msgbox gText_BringFireType_MarginsOnThis, MSGBOX_NPC
	call Quest_BringFireType_CheckFireType_Script
	return


gText_BringFireType_WhatCanIGetYou::
	.string "{PLAYER}! What can get I you today?$"

gText_BringFireType_YouCaughtA::
	.string "You caught a POKEMON for me? Are you\n"
	.string "sure? That's absolutely huge! Here, let\l"
	.string "me give you something, since I won't\l"
	.string "need it now.$"

gText_BringFireType_IWonderIfICould::
	.string "I wonder if I could lure a Fire-type\n"
	.string "here with the smell of food...$"

gText_BringFireType_WereOutOfPropane::
	.string "We're out of propane, so I'm closing up\n"
	.string "shop today. I wish I could use a\l"
	.string "Fire-type Pokémon for this grill...$"

gText_BringFireType_MarginsOnThis::
	.string "Margins on this stand are so slim... I\n"
	.string "can't even afford to live, never mind\l"
	.string "upgrade!$"
