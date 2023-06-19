Taxi_Interact_Dialogue::
	lock
	call_if_quest_reward QUEST_TAXICABTURNAROUND, Quest_Taxicabturnaround_Reward_Dialogue
	call Quest_Taxicabturnaround_CheckNextStage_Script
	bufferstring STR_VAR_1, Taxi_Interact_Dialogue_Text_0
	msgbox gText_Taxi_ThanksForChoosing
	closemessage
	call Taxi_ConstructMenu_Script
	dynmultistack 0, 0, TRUE, 3, TRUE, 1, DYN_MULTICHOICE_CB_NONE
	switch VAR_RESULT
	case 0, Taxi_Interact_Dialogue_2
	case 1, Taxi_Interact_Dialogue_3
	case 2, Taxi_Interact_Dialogue_4
	return

Taxi_Interact_Dialogue_2:
	goto Taxi_Refuse_Dialogue
	return

Taxi_Interact_Dialogue_3:
	goto Taxi_ChooseLocation_Dialogue
	return

Taxi_Interact_Dialogue_4:
	goto Quest_Taxicabturnaround_AskPokemon_Dialogue
	return


Taxi_ConstructMenu_Script::
	dynmultipush Taxi_ConstructMenu_Script_Text_0, NO
	dynmultipush Taxi_ConstructMenu_Script_Text_1, YES
	specialvar VAR_0x8008, Quest_Taxicabturnaround_IsSubquestComplete
	returnqueststate QUEST_TAXICABTURNAROUND
	compare VAR_RESULT, QUEST_MENU_UNLOCK_QUEST
	goto_if_gt Taxi_ConstructMenu_Script_3
Taxi_ConstructMenu_Script_1:
	return

Taxi_ConstructMenu_Script_2:
	dynmultipush Taxi_ConstructMenu_Script_Text_2, 2
	goto Taxi_ConstructMenu_Script_1

Taxi_ConstructMenu_Script_3:
	compare VAR_0x8008, 0
	goto_if_eq Taxi_ConstructMenu_Script_2
	goto Taxi_ConstructMenu_Script_1


Taxi_Refuse_Dialogue::
	msgbox gText_Taxi_ChangedYourMind
	closemessage
	release
	end


Taxi_ChooseLocation_Dialogue::
	fadescreen FADE_TO_BLACK
	call Taxi_ConstructLocations_List
	dynmultistack 0, 0, TRUE, 3, TRUE, 0, DYN_MULTICHOICE_CB_NONE
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq Taxi_ChooseLocation_Dialogue_2
Taxi_ChooseLocation_Dialogue_1:
	specialvar VAR_RESULT, Taxi_CalculateFeeAndCharge
	compare VAR_RESULT, 0
	goto_if_eq Taxi_ChooseLocation_Dialogue_5
Taxi_ChooseLocation_Dialogue_4:
	call Taxi_WarpToLocation_Script
	release
	end

Taxi_ChooseLocation_Dialogue_2:
	fadescreen FADE_FROM_BLACK
	goto Taxi_Refuse_Dialogue
	goto Taxi_ChooseLocation_Dialogue_1

Taxi_ChooseLocation_Dialogue_5:
	call Taxi_StartBattle_Dialogue
	goto Taxi_ChooseLocation_Dialogue_4


Taxi_WarpToLocation_Script::
	switch VAR_TAXI_DESTINATION
	case 0, Taxi_WarpToLocation_Script_2
	case 1, Taxi_WarpToLocation_Script_3
	case 2, Taxi_WarpToLocation_Script_4
	return

Taxi_WarpToLocation_Script_2:
	warpsilent MAP_TENDERLOIN, 0
	return

Taxi_WarpToLocation_Script_3:
	warpsilent MAP_BERKELEY, 0
	return

Taxi_WarpToLocation_Script_4:
	warpsilent MAP_PACIFICA, 0
	return


Taxi_ConstructLocations_List::
	goto_if_unset FLAG_VISITED_LITTLEROOT_TOWN, Taxi_ConstructLocations_List_2
Taxi_ConstructLocations_List_1:
	goto_if_unset FLAG_VISITED_OLDALE_TOWN, Taxi_ConstructLocations_List_5
Taxi_ConstructLocations_List_4:
	goto_if_unset FLAG_VISITED_DEWFORD_TOWN, Taxi_ConstructLocations_List_8
Taxi_ConstructLocations_List_7:
	dynmultipush Taxi_ConstructLocations_List_Text_3, MULTI_B_PRESSED
	return

Taxi_ConstructLocations_List_2:
	dynmultipush Taxi_ConstructLocations_List_Text_0, 0
	goto Taxi_ConstructLocations_List_1

Taxi_ConstructLocations_List_5:
	dynmultipush Taxi_ConstructLocations_List_Text_1, 1
	goto Taxi_ConstructLocations_List_4

Taxi_ConstructLocations_List_8:
	dynmultipush Taxi_ConstructLocations_List_Text_2, 2
	goto Taxi_ConstructLocations_List_7


Taxi_StartBattle_Dialogue::
	showmoneybox 0, 0
	special Taxi_BufferDestinationMapName
	msgbox gText_Taxi_HereWeAre
	msgbox gText_Taxi_ItllCost
	msgbox gText_Taxi_WhatDoYouMean
	closemessage
	hidemoneybox
	trainerbattle_no_intro TRAINER_CABBIE_HALE, gText_Taxi_AintYouStrong
	fadescreen FADE_TO_BLACK
	msgbox gText_Taxi_NowIWont
	closemessage
	return


Taxi_Interact_Dialogue_Text_0:
	.string "2000$"

Taxi_ConstructMenu_Script_Text_0:
	.string "No.$"

Taxi_ConstructMenu_Script_Text_1:
	.string "Yes!$"

Taxi_ConstructMenu_Script_Text_2:
	.string "Something else.$"

Taxi_ConstructLocations_List_Text_0:
	.string "Caphe City$"

Taxi_ConstructLocations_List_Text_1:
	.string "Chasilla$"

Taxi_ConstructLocations_List_Text_2:
	.string "Cresalta Vista$"

Taxi_ConstructLocations_List_Text_3:
	.string "Never mind.$"

gText_Taxi_ThanksForChoosing::
	.string "Thanks for choosing Taxicab! The base\n"
	.string "fare is ¥{STR_VAR_1}, do you want a\l"
	.string "ride?$"

gText_Taxi_ChangedYourMind::
	.string "Changed your mind? That's fine. We'll be\n"
	.string "here!$"

gText_Taxi_HereWeAre::
	.string "Okay kid, here's your stop,\n"
	.string "{STR_VAR_1}.$"

gText_Taxi_ItllCost::
	.string "That'll be ¥{STR_VAR_2}.$"

gText_Taxi_WhatDoYouMean::
	.string "Hey, just a minute there friend! You\n"
	.string "don't even have enough for the fare?!\l"
	.string "I come out to earn a living, don't I? So\l"
	.string "why you gotta tax me like this?$"

gText_Taxi_AintYouStrong::
	.string "Well aren't you a strong one? Too\n"
	.string "strong for me!$"

gText_Taxi_NowIWont::
	.string "Now I won't make enough money to send\n"
	.string "back home to my family in Hoenn...$"
