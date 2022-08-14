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
	buffernumberstring STR_VAR_1, VAR_NUM_TROLLEY_RIDES
	switch VAR_NUM_TROLLEY_RIDES
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
	incrementgamestat GAME_STAT_TROLLEY_RIDES
	addvar VAR_NUM_TROLLEY_RIDES, 1
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
	completequest QUEST_BETWEENASTONEANDAHARD
	release
	end

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
	msgbox gText_Quest_BetweenAStoneAndAHardPlace_WeShouldPivot, MSGBOX_NPC
	end


gText_Quest_BetweenAStoneAndAHardPlace_DidYouHear::
	.string "Did you hear about the promotion we're\n"
	.string "doing? Ride the trolleys in SanFran 10\l"
	.string "times, and get a mega powerful stone\l"
	.string "for pushing the limits of your\l"
	.string "Pokemons power!$"

gText_Quest_BetweenAStoneAndAHardPlace_YouShouldTry::
	.string "You should try out the trolleys around\n"
	.string "the region. They're a great way to get\l"
	.string "around!$"

gText_Quest_BetweenAStoneAndAHardPlace_AreYouNew::
	.string "Are you new to the region? You should\n"
	.string "really give the trolleys a try!$"

gText_Quest_BetweenAStoneAndAHardPlace_YoureARegular::
	.string "You're a regular, {PLAYER}! Thanks for\n"
	.string "supporting the trolley system. Come\l"
	.string "back when you've done 10 rides!$"

gText_Quest_BetweenAStoneAndAHardPlace_OhWowOnly::
	.string "Oh wow! {STR_VAR_1} rides! Excited\n"
	.string "to get your prize?$"

gText_Quest_BetweenAStoneAndAHardPlace_GladToSeeYoureEnjoying::
	.string "Glad to see you're enjoying the trolley\n"
	.string "system, {PLAYER}!$"

gText_Quest_BetweenAStoneAndAHardPlace_ForYourContinuedRidership::
	.string "For your continued ridership, we'd like\n"
	.string "to present you with a special\l"
	.string "evolutionary stones!$"

gText_Quest_BetweenAStoneAndAHardPlace_AhhPleaseDont::
	.string "Aaah, I can tell you're disappointed.\n"
	.string "Please don't be mad... we had some Mega\l"
	.string "Stones, but then we ran out. We had to\l"
	.string "reword the ad to keep people coming in,\l"
	.string "but all of the Trainers have been so\l"
	.string "mad!$"

gText_Quest_BetweenAStoneAndAHardPlace_Yeah::
	.string "...yeah. Not what I was expecting. But\n"
	.string "thanks, I guess.$"

gText_Quest_BetweenAStoneAndAHardPlace_WeShouldPivot::
	.string "We should pivot to a more hoonest\n"
	.string "advertising model. I don't think I can\l"
	.string "handle more angry messages on Twitter!$"
