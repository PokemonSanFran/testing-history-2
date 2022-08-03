Quest_IceCreamCrafting_HidePatron_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ICECREAMCRAFTING
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_HidePatron_Script_1
	return

Quest_IceCreamCrafting_HidePatron_Script_1:
	setflag FLAG_TEMP_1
	return


Quest_IceCreamCrafting_Event_Script::
	msgbox gText_Quest_IceCreamCrafting_WelcomeToMarble, MSGBOX_NPC
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_ICECREAMCRAFTING
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_Event_Script_2
Quest_IceCreamCrafting_Event_Script_1:
	call Quest_IceCreamCrafting_CheckBerries_Script
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ICECREAMCRAFTING
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_Event_Script_5
Quest_IceCreamCrafting_Event_Script_4:
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_ICECREAMCRAFTING
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_Event_Script_7
	return

Quest_IceCreamCrafting_Event_Script_2:
	goto Berkeley_IceCreamShop_Cashier_Event_Script
	goto Quest_IceCreamCrafting_Event_Script_1

Quest_IceCreamCrafting_Event_Script_5:
	goto Quest_IceCreamCrafting_GiveRecipe_Dialogue
	goto Quest_IceCreamCrafting_Event_Script_4

Quest_IceCreamCrafting_Event_Script_7:
	goto Quest_IceCreamCrafting_TakeBerries_Dialogue
	return


Quest_IceCreamCrafting_GiveRecipe_Dialogue::
	msgbox gText_Quest_IceCreamCrafting_IfYouWant, MSGBOX_NPC
	end


Quest_IceCreamCrafting_TakeBerries_Dialogue::
	lock
	msgbox gText_Quest_IceCreamCrafting_SickYouBrought, MSGBOX_NPC
	closemessage
	call Quest_IceCreamCrafting_TakeBerries_Script
	giveitem ITEM_SHERBET_SURPRISE, 6
	applymovement 2, Quest_IceCreamCrafting_ToCounter_Movement
	waitmovement 2
	applymovement 1, Quest_IceCreamCrafting_StepRight_Movement
	waitmovement 1
	msgbox gText_Quest_IceCreamCrafting_WhatTheHell
	msgbox gText_Quest_IceCreamCrafting_WhatDoYouMean
	msgbox gText_Quest_IceCreamCrafting_MyPokemonGotWeaker
	msgbox gText_Quest_IceCreamCrafting_YeahWeCleanOut
	msgbox gText_Quest_IceCreamCrafting_ICantBelieveThis
	closemessage
	applymovement 2, Quest_IceCreamCrafting_BackToSeat_Movement
	waitmovement 2
	call Quest_IceCreamCrafting_RemovePokemon_Script
	applymovement 2, Quest_IceCreamCrafting_LeaveShop_Movement
	waitmovement 2
	playse SE_EXIT
	removeobject 2
	applymovement 1, Quest_IceCreamCrafting_SlideBack_Movement
	waitmovement 1
	release
	completequest QUEST_ICECREAMCRAFTING
	end


Quest_IceCreamCrafting_RemovePokemon_Script::
	playse SE_BALL_OPEN
	waitse
	setflag FLAG_TEMP_1
	removeobject 3
	return


Quest_IceCreamCrafting_TakeBerries_Script::
	removeitem ITEM_PECHA_BERRY, 3
	removeitem ITEM_NANAB_BERRY, 2
	removeitem ITEM_RABUTA_BERRY, 1
	return


Quest_IceCreamCrafting_CheckBerries_Script::
	setvar VAR_TEMP_8, 0
	checkitem ITEM_PECHA_BERRY, 3
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_CheckBerries_Script_2
Quest_IceCreamCrafting_CheckBerries_Script_1:
	checkitem ITEM_NANAB_BERRY, 2
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_CheckBerries_Script_5
Quest_IceCreamCrafting_CheckBerries_Script_4:
	checkitem ITEM_RABUTA_BERRY, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_IceCreamCrafting_CheckBerries_Script_8
Quest_IceCreamCrafting_CheckBerries_Script_7:
	compare VAR_TEMP_8, 3
	goto_if_eq Quest_IceCreamCrafting_CheckBerries_Script_10
	return

Quest_IceCreamCrafting_CheckBerries_Script_2:
	addvar VAR_TEMP_8, 1
	goto Quest_IceCreamCrafting_CheckBerries_Script_1

Quest_IceCreamCrafting_CheckBerries_Script_5:
	addvar VAR_TEMP_8, 1
	goto Quest_IceCreamCrafting_CheckBerries_Script_4

Quest_IceCreamCrafting_CheckBerries_Script_8:
	addvar VAR_TEMP_8, 1
	goto Quest_IceCreamCrafting_CheckBerries_Script_7

Quest_IceCreamCrafting_CheckBerries_Script_10:
	questmenu QUEST_MENU_SET_REWARD, QUEST_ICECREAMCRAFTING
	return


Quest_IceCreamCrafting_ToCounter_Movement:
	walk_faster_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_up
	step_end

Quest_IceCreamCrafting_StepRight_Movement:
	lock_facing_direction
	walk_right
	step_end

Quest_IceCreamCrafting_BackToSeat_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	step_end

Quest_IceCreamCrafting_LeaveShop_Movement:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

Quest_IceCreamCrafting_SlideBack_Movement:
	lock_facing_direction
	walk_left
	step_end

gText_Quest_IceCreamCrafting_WelcomeToMarble::
	.string "Welcome to the Marble Slab!$"

gText_Quest_IceCreamCrafting_IfYouWant::
	.string "We're actually not serving customers\n"
	.string "yet, today is just our soft open! If\l"
	.string "you want to try our signature Sherbet\l"
	.string "Surprise, bring in 3 Pecha Berries, 2\l"
	.string "Nanab Berries, and 1 Rabuta Berry!$"

gText_Quest_IceCreamCrafting_SickYouBrought::
	.string "Sick, you brought the berries! Okay, I'll\n"
	.string "make this.... and here you go!$"

gText_Quest_IceCreamCrafting_WhatTheHell::
	.string "What the hell are you serving us? What\n"
	.string "is going on?$"

gText_Quest_IceCreamCrafting_WhatDoYouMean::
	.string "What do you mean? Did your Pokémon not\n"
	.string "like their treat?$"

gText_Quest_IceCreamCrafting_MyPokemonGotWeaker::
	.string "My Pokémon got weaker after eating it!\n"
	.string "What gives?$"

gText_Quest_IceCreamCrafting_YeahWeCleanOut::
	.string "Yeah! We clean out your Pokémon bodies\n"
	.string "so you can toughen them up the way\l"
	.string "they should be! That's what our ad\l"
	.string "said, right?$"

gText_Quest_IceCreamCrafting_ICantBelieveThis::
	.string "...I can't believe this shit! I wanted to\n"
	.string "toughen my team up! Ugh!$"
