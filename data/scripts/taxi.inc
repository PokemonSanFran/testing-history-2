Taxi_Interact_Dialogue::
	lock
	msgbox gText_Taxi_ThanksForChoosing
	closemessage
	call Taxi_ConstructMenu_Script
	dynmultistack 0, 0, TRUE, 3, TRUE, 0, DYN_MULTICHOICE_CB_NONE
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
	goto Quest_Taxicabturnaroundland_Event_Script
	return


Taxi_ConstructMenu_Script::
	dynmultipush Taxi_ConstructMenu_Script_Text_0, 0
	dynmultipush Taxi_ConstructMenu_Script_Text_1, 1
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_TAXICABTURNAROUNDLAND
	compare VAR_RESULT, 0
	goto_if_ne Taxi_ConstructMenu_Script_2
Taxi_ConstructMenu_Script_1:
	return

Taxi_ConstructMenu_Script_2:
	dynmultipush Taxi_ConstructMenu_Script_Text_2, 2
	goto Taxi_ConstructMenu_Script_1


Taxi_Refuse_Dialogue::
	msgbox gText_Taxi_ChangedYourMind
	return


Taxi_ChooseLocation_Dialogue::
	fadescreen FADE_TO_BLACK
	call Taxi_ShowLocations_List
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


Taxi_ShowLocations_List::
	dynmultipush Taxi_ShowLocations_List_Text_0, 0
	dynmultipush Taxi_ShowLocations_List_Text_1, 1
	dynmultipush Taxi_ShowLocations_List_Text_2, 2
	dynmultistack 0, 0, TRUE, 3, TRUE, 0, DYN_MULTICHOICE_CB_NONE
	return


Taxi_StartBattle_Dialogue::
	showmoneybox 0, 0
	msgbox gText_Taxi_HereWeAre
	msgbox gText_Taxi_ItllCost
	msgbox gText_Taxi_WhatDoYouMean
	closemessage
	hidemoneybox
	trainerbattle_no_intro TRAINER_CABBIE_HALE, gText_Taxi_NowIWont
	fadescreen FADE_TO_BLACK
	msgbox gText_Taxi_NowIWont
	closemessage
	return


Taxi_ConstructMenu_Script_Text_0:
	.string "No.$"

Taxi_ConstructMenu_Script_Text_1:
	.string "Yes!$"

Taxi_ConstructMenu_Script_Text_2:
	.string "Something else.$"

Taxi_ShowLocations_List_Text_0:
	.string "Caphe City$"

Taxi_ShowLocations_List_Text_1:
	.string "Chasilla$"

Taxi_ShowLocations_List_Text_2:
	.string "Cresalta Vista$"

gText_Taxi_ThanksForChoosing::
	.string "$"

gText_Taxi_ChangedYourMind::
	.string "$"

gText_Taxi_ItllCost::
	.string "$"

gText_Taxi_HereWeAre::
	.string "$"

gText_Taxi_WhatDoYouMean::
	.string "$"

gText_Taxi_NowIWont::
	.string "$"
