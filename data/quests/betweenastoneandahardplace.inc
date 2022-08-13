Quest_BetweenAStoneAndAHardPlace_Event_Script::
	returnqueststate QUEST_BETWEENASTONEANDAHARD
	switch VAR_RESULT
	case 1, Quest_BetweenAStoneAndAHardPlace_Event_Script_2
	case 2, Quest_BetweenAStoneAndAHardPlace_Event_Script_3
	case 3, Quest_BetweenAStoneAndAHardPlace_Event_Script_4
	case 4, Quest_BetweenAStoneAndAHardPlace_Event_Script_5
	return

Quest_BetweenAStoneAndAHardPlace_Event_Script_2:
	goto Tenderloin_TrolleyHQ_CounterWorker_Dialogue
	return

Quest_BetweenAStoneAndAHardPlace_Event_Script_3:
	goto Quest_BetweenAStoneAndAHardPlace_Active_Dialogue
	return

Quest_BetweenAStoneAndAHardPlace_Event_Script_4:
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue
	return

Quest_BetweenAStoneAndAHardPlace_Event_Script_5:
	goto Quest_BetweenAStoneAndAHardPlace_Complete_Dialogue
	return


Quest_BetweenAStoneAndAHardPlace_Active_Dialogue::
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_DidYouHear, MSGBOX_NPC
	buffernumberstring STR_VAR_1, GAME_STAT_TROLLEY_RIDES
	switch GAME_STAT_TROLLEY_RIDES
	case 0, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_3
	case 1, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_4
	case 2, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_4
	case 3, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_4
	case 4, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_5
	case 5, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_5
	case 6, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_5
	case 7, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_6
	case 8, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_6
	case 9, Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_6
Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_1:
	end

Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_3:
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_YouShouldTry, MSGBOX_NPC
	goto Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_4:
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_AreYouNew, MSGBOX_NPC
	goto Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_5:
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_YoureARegular, MSGBOX_NPC
	goto Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_6:
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_OhWowOnly, MSGBOX_NPC
	goto Quest_BetweenAStoneAndAHardPlace_Active_Dialogue_1


Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue::
	buffernumberstring STR_VAR_1, GAME_STAT_TROLLEY_RIDES
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_GladToSeeYoureEnjoying, MSGBOX_NPC
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_ForYourContinuedRidership, MSGBOX_NPC
	random 10
	switch VAR_RESULT
	case 0, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_3
	case 1, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_4
	case 2, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_5
	case 3, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_6
	case 4, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_7
	case 5, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_8
	case 6, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_9
	case 7, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_10
	case 8, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_11
	case 9, Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_12
Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1:
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_AhhPleaseDont, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_Yeah, MSGBOX_NPC
	callnative ClearMugshot
	return

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_3:
	giveitem ITEM_ICE_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_4:
	giveitem ITEM_FIRE_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_5:
	giveitem ITEM_WATER_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_6:
	giveitem ITEM_THUNDER_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_7:
	giveitem ITEM_LEAF_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_8:
	giveitem ITEM_MOON_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_9:
	giveitem ITEM_SUN_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_10:
	giveitem ITEM_SHINY_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_11:
	giveitem ITEM_DUSK_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1

Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_12:
	giveitem ITEM_DAWN_STONE
	goto Quest_BetweenAStoneAndAHardPlace_Reward_Dialogue_1


Quest_BetweenAStoneAndAHardPlace_Complete_Dialogue::
	return


gText_Quest_BetweenAStoneAndAHardPlace::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_DidYouHear::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_YouShouldTry::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_AreYouNew::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_YoureARegular::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_OhWowOnly::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_GladToSeeYoureEnjoying::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_ForYourContinuedRidership::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_AhhPleaseDont::
	.string "$"

gText_Quest_BetweenAStoneAndAHardPlace_Yeah::
	.string "$"