Quest_BuildingScope_MoveEmployee_Script::
	returnqueststate QUEST_BUILDINGSCOPE
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Quest_BuildingScope_MoveEmployee_Script_1
	return

Quest_BuildingScope_MoveEmployee_Script_1:
	setobjectxy 5, 5, 1
	setobjectxyperm 5, 5, 1
	return


Quest_BuildingScope_ToggleObjects_Script::
	returnqueststate QUEST_BUILDINGSCOPE
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_BuildingScope_ToggleObjects_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_BuildingScope_ToggleObjects_Script_4
	call Quest_BuildingScope_HideSquatters_Script
	call Quest_BuildingScope_HideConstruction_Script
Quest_BuildingScope_ToggleObjects_Script_1:
	return

Quest_BuildingScope_ToggleObjects_Script_3:
	call Quest_BuildingScope_HideConstruction_Script
	goto Quest_BuildingScope_ToggleObjects_Script_1

Quest_BuildingScope_ToggleObjects_Script_4:
	call Quest_BuildingScope_HideSquatters_Script
	goto Quest_BuildingScope_ToggleObjects_Script_1


Quest_BuildingScope_HideSquatters_Script::
	setflag FLAG_TEMP_1
	return


Quest_BuildingScope_HideConstruction_Script::
	setflag FLAG_TEMP_2
	return


Quest_BuildingScope_Event_Script::
	lock
	returnqueststate QUEST_BUILDINGSCOPE
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_BuildingScope_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_BuildingScope_Event_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_BuildingScope_Event_Script_4
	goto Quest_BuildingScope_CheckBadges_Script
	return

Quest_BuildingScope_Event_Script_2:
	faceplayer
	goto Quest_BuildingScope_Employee_Active_Dialogue
	return

Quest_BuildingScope_Event_Script_3:
	faceplayer
	goto Quest_BuildingScope_Reward_Dialogue
	return

Quest_BuildingScope_Event_Script_4:
	faceplayer
	goto Quest_BuildingScope_CheckNoGoodDeed_Script
	return


Quest_BuildingScope_CheckBadges_Script::
	special GetNumberOfBadges
	compare VAR_TEMP_0, 5
	goto_if_lt Quest_BuildingScope_CheckBadges_Script_1
	goto Quest_BuildingScope_StartQuest_Dialogue
	return

Quest_BuildingScope_CheckBadges_Script_1:
	goto Quest_BuildingScope_ScaredEmployee_Dialogue
	return


Quest_BuildingScope_ScaredEmployee_Dialogue::
	msgbox gText_BuildingScope_HowBadCouldItBe
	release
	end


Quest_BuildingScope_StartQuest_Dialogue::
	faceplayer
	msgbox gText_BuildingScope_OhYourePlayer
	msgbox gText_BuildingScope_TheresABuildingIn
	msgbox gText_BuildingScope_AnimalsOrPokemon
	closemessage
	applymovement 5, Common_Movement_WalkDown
	waitmovement 5
	startquest QUEST_BUILDINGSCOPE
	release
	end


Quest_BuildingScope_Employee_Active_Dialogue::
	msgbox gText_BuildingScope_OneDayIll, MSGBOX_NPC
	end


Quest_BuildingScope_Squatters_Cutscene::
	lock
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_BUILDINGSCOPE
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingScope_Squatters_Cutscene_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	addobject 1
	addobject 3
	addobject 4
	applymovement 1, Quest_BuildingScope_WalkToPlayer_Movement
	applymovement 3, Quest_BuildingScope_WalkToPlayer_Movement
	applymovement 4, Quest_BuildingScope_WalkToPlayer_Movement
	waitmovement 4
	goto Quest_BuildingScope_BattleSquatters_Script
	return

Quest_BuildingScope_Squatters_Cutscene_2:
	release
	end


Quest_BuildingScope_BattleSquatters_Script::
	msgbox gText_BuildingScope_FinallyHadTheBalls
	trainerbattle_no_intro TRAINER_LOLA_1, gText_BuildingScope_WhyWontYou
	msgbox gText_BuildingScope_ThrowingGasAtUs
	trainerbattle_no_intro TRAINER_LOLA_2, gText_BuildingScope_YouDisgustMe
	msgbox gText_BuildingSCope_NothingIsEverGood
	trainerbattle_no_intro TRAINER_LOLA_3, gText_BuildingScope_Scum
	goto Quest_BuildingScope_PostBattle_Dialogue
	return


Quest_BuildingScope_PostBattle_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BuildingScope_NobodyIsTryingTo
	callnative ClearMugshot
	msgbox gText_BuildingScope_ThrowingShitAt
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BuildingScope_SomebodyAskedMe
	callnative ClearMugshot
	msgbox gText_BuildingScope_UhHuhPokemon
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BuildingScope_LookTheGuyIWas
	callnative ClearMugshot
	msgbox gText_BuildingScope_NotLikeWeGotAnywhere
	closemessage
	questmenu QUEST_MENU_SET_REWARD, QUEST_BUILDINGSCOPE
	release
	end


Quest_BuildingScope_Reward_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BuildingScope_IGotInto
	callnative ClearMugshot
	msgbox gText_BuildingScope_WaitPeopleWere
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BuildingScope_YeahTheyWere
	callnative ClearMugshot
	msgbox gText_BuildingScope_OhWowWell
	msgbox gText_BuildingScope_IllSendSomebody
	showmoneybox 0, 0
	waitbuttonpress
	addmoney 50000
	playse SE_SHOP
	updatemoneybox 0
	waitse
	waitbuttonpress
	hidemoneybox
	closemessage
	completequest QUEST_BUILDINGSCOPE
	release
	end


Quest_BuildingScope_PostQuest_Dialogue::
	msgbox gText_BuildingScope_WeHired, MSGBOX_NPC
	end


Quest_NoGoodDeed_FollowUp_Dialogue::
	return


Quest_BuildingScope_CheckNoGoodDeed_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_NOGOODDEED
	compare VAR_RESULT, 0
	goto_if_eq Quest_BuildingScope_CheckNoGoodDeed_Script_1
	goto Quest_NoGoodDeed_FollowUp_Dialogue
	return

Quest_BuildingScope_CheckNoGoodDeed_Script_1:
	goto Quest_BuildingScope_PostQuest_Dialogue
	return


Quest_BuildingScope_WalkToPlayer_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_BuildingScope_HowBadCouldItBe::
	.string "How bad could it be...? Come on, just\n"
	.string "barge in there and tell 'em what's what!$"

gText_BuildingScope_OhYourePlayer::
	.string "Oh! You're {PLAYER}. Maybe... you can\n"
	.string "help me? I work for YCombinator, in the\l"
	.string "League Ops Division$"

gText_BuildingScope_TheresABuildingIn::
	.string "this building is adbandoned, so the\n"
	.string "league wants to buy it to turn it into a\l"
	.string "battle arena. But I'm pretty sure its\l"
	.string "overrun by beasts! Nasty things, they\l"
	.string "attack whenever we try to go inside.$"

gText_BuildingScope_AnimalsOrPokemon::
	.string "Animals... or pokemon or something. Can\n"
	.string "you go in there and clear them out,\l"
	.string "because you're tougher than me!$"

gText_BuildingScope_OneDayIll::
	.string "one day i'll have some balls$"

gText_BuildingScope_FinallyHadTheBalls::
	.string "Finally had the balls to come in here\n"
	.string "yourself huh$"

gText_BuildingScope_WhyWontYou::
	.string "why wont you leave us alone$"

gText_BuildingScope_ThrowingGasAtUs::
	.string "throwing gas cans through the windows,\n"
	.string "setting off stike bombs, playing loud\l"
	.string "music... what is wrong with you?$"

gText_BuildingScope_YouDisgustMe::
	.string "you disgust me.$"

gText_BuildingSCope_NothingIsEverGood::
	.string "nothing is ever good about for you guys\n"
	.string "huh$"

gText_BuildingScope_Scum::
	.string "scum.$"

gText_BuildingScope_NobodyIsTryingTo::
	.string "nobody is trying to hurt you$"

gText_BuildingScope_ThrowingShitAt::
	.string "throwing shit through the windows?\n"
	.string "what the hell is that?$"

gText_BuildingScope_SomebodyAskedMe::
	.string "somebody asked me to help clear out\n"
	.string "some aggressive pokemon. we had no\l"
	.string "idea there were people in here$"

gText_BuildingScope_UhHuhPokemon::
	.string "uh huh. pokemon? really?$"

gText_BuildingScope_LookTheGuyIWas::
	.string "look, the guy I was helping seemed\n"
	.string "super nice. he doesn't seem like the\l"
	.string "kind of guy to attack people. let me go\l"
	.string "talk to him and clear it up$"

gText_BuildingScope_NotLikeWeGotAnywhere::
	.string "not like we got anywhere to go$"

gText_BuildingScope_IGotInto::
	.string "I got inside no problem, but there were\n"
	.string "no pokemon, just some people living\l"
	.string "there!$"

gText_BuildingScope_WaitPeopleWere::
	.string "wait people? like actual humans? not\n"
	.string "some beasts?$"

gText_BuildingScope_YeahTheyWere::
	.string "yeah! they're living there because they\n"
	.string "have nowhere else to go$"

gText_BuildingScope_OhWowWell::
	.string "oh wow well we can't have that. i\n"
	.string "suppose we're effectiely taking their\l"
	.string "home away, but I'll work with the team\l"
	.string "to find a better place for them.\l"
	.string "everybody wins!$"

gText_BuildingScope_IllSendSomebody::
	.string "i'll send somebody over right now. thank\n"
	.string "you for subduing the ani - those\l"
	.string "people. what a misunderstanding! and\l"
	.string "this is for you...$"

gText_BuildingScope_WeHired::
	.string "we hired the best contractors from\n"
	.string "Vermilion City to work on the building.\l"
	.string "we might even be done AHEAD of\l"
	.string "schedule!$"
