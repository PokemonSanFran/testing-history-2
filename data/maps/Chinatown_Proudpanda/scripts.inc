Chinatown_Proudpanda_MapScripts::
	.byte 0


Chinatown_Proudpanda_Employee_Script::
	lock
	faceplayer
	returnqueststate QUEST_PANDA_PRIDE
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Chinatown_Proudpanda_Employee_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Chinatown_Proudpanda_Employee_Script_4
	call Chinatown_Proudpanda_DefaultGreeting_Dialogue
Chinatown_Proudpanda_Employee_Script_1:
	goto Chinatown_Proudpanda_Shop_Script
	return

Chinatown_Proudpanda_Employee_Script_3:
	call Chinatown_Proudpanda_DefaultGreeting_Dialogue
	goto Quest_Pandapride_CheckParty_Script
	goto Chinatown_Proudpanda_Employee_Script_1

Chinatown_Proudpanda_Employee_Script_4:
	call Chinatown_Proudpanda_HappyGreeting_Dialogue
	goto Chinatown_Proudpanda_Employee_Script_1


Chinatown_Proudpanda_HappyGreeting_Dialogue::
	msgbox gText_ProudPanda_Player, , SPEAKER_SHOPKEEPER, , EMOTE_HAPPY
	waitmessage
	return


Chinatown_Proudpanda_DefaultGreeting_Dialogue::
	msgbox gText_ProduPanda_WhatCan, , SPEAKER_SHOPKEEPER
	waitmessage
	return


Chinatown_Proudpanda_Shop_Script::
	pokemart ProudPandaShop
	goto_if_quest_complete QUEST_PANDA_PRIDE, Chinatown_Proudpanda_HappyThanks_Dialogue
	goto Chinatown_Proudpanda_DefaultThanks_Dialogue
	return


Chinatown_Proudpanda_DefaultThanks_Dialogue::
	msgbox gText_Proudpanda_Thanks, , SPEAKER_SHOPKEEPER
	closemessage
	return


Chinatown_Proudpanda_HappyThanks_Dialogue::
	msgbox gText_Proudpanda_GoodToSee, , SPEAKER_SHOPKEEPER
	closemessage
	return


	.align 2
ProudPandaShop:
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_CHARCOAL
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_MAGNET
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_POISON_BARB
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_TWISTED_SPOON
	.2byte ITEM_SILVER_POWDER
	.2byte ITEM_HARD_STONE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_DRAGON_FANG
	.2byte ITEM_BLACK_GLASSES
	.2byte ITEM_METAL_COAT
	.2byte ITEM_NONE

gText_ProduPanda_WhatCan::
	.string "Welcome to the Proud Panda, what can I\n"
	.string "get for you?$"

gText_Proudpanda_Thanks::
	.string "Thanks for coming in!$"

gText_ProudPanda_Player::
	.string "{PLAYER}! What do you need?$"

gText_Proudpanda_GoodToSee::
	.string "Good to see you {PLAYER}!$"
