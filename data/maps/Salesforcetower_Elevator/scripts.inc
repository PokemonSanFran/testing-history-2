Salesforcetower_Elevator_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Salesforcetower_Elevator_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Salesforcetower_Elevator_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Salesforcetower_Elevator_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Salesforcetower_Elevator_MapScripts_OnTransition
	return

Salesforcetower_Elevator_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_TEMP_0, 0, Salesforcetower_Elevator_AttendantMissing_Dialogue
	.2byte 0


Salesforcetower_Elevator_MapScripts_OnTransition::
	compare VAR_MAUVILLE_CITY_STATE, 4
	goto_if_gt Salesforcetower_Elevator_MapScripts_OnTransition_1
	goto_if_unset FLAG_BADGE03_GET, Salesforcetower_Elevator_MapScripts_OnTransition_1
	return

Salesforcetower_Elevator_MapScripts_OnTransition_1:
	goto Salesforcetower_Elevator_HideAttendant_Script
	return


Salesforcetower_Elevator_AttendantMissing_Dialogue::
	setvar VAR_TEMP_0, 1
	compare VAR_MAUVILLE_CITY_STATE, 4
	goto_if_gt Salesforcetower_Elevator_AttendantMissing_Dialogue_1
	goto_if_unset FLAG_BADGE03_GET, Salesforcetower_Elevator_AttendantMissing_Dialogue_1
	release
	end

Salesforcetower_Elevator_AttendantMissing_Dialogue_1:
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Salesforcetower_Elevator_TheAttendantIsGone
	closemessage
	callnative ClearMugshot
	release
	end


Salesforcetower_Elevator_HideAttendant_Script::
	setflag FLAG_TEMP_1
	return


Salesforcetower_ElevatorAttendant_Script::
	lock
	faceplayer
	setvar VAR_0x8004, 0
	goto_if_set FLAG_TEMP_2, Salesforcetower_ElevatorAttendant_Script_2
Salesforcetower_ElevatorAttendant_Script_1:
	copyvar VAR_0x8005, VAR_DEPT_STORE_FLOOR
	special ShowSalesforcetowerElevatorFloorSelect
	message gText_WhichFloorWouldYouLike
	waitmessage
	setvar VAR_0x8004, 0
	goto SalesforcetowerElevator_EventScript_ChooseFromX
	end

Salesforcetower_ElevatorAttendant_Script_2:
	call SalesforcetowerElevator_EventScript_SetFloor
	goto Salesforcetower_ElevatorAttendant_Script_1


SalesforcetowerElevator_EventScript_ChooseFromX::
	specialvar VAR_RESULT, GetTowerFloorDefaultFloorChoice
	switch VAR_RESULT
	case 0, SalesforcetowerElevator_EventScript_ChooseFromX_3
	case 1, SalesforcetowerElevator_EventScript_ChooseFromX_4
	case 2, SalesforcetowerElevator_EventScript_ChooseFromX_5
	case 3, SalesforcetowerElevator_EventScript_ChooseFromX_6
SalesforcetowerElevator_EventScript_ChooseFromX_1:
	goto SalesforcetowerElevator_EventScript_ChooseFloor
	end

SalesforcetowerElevator_EventScript_ChooseFromX_3:
	multichoicedefault 0, 0, MULTI_FLOORS, 0, FALSE
	goto SalesforcetowerElevator_EventScript_ChooseFromX_1

SalesforcetowerElevator_EventScript_ChooseFromX_4:
	multichoicedefault 0, 0, MULTI_FLOORS, 1, FALSE
	goto SalesforcetowerElevator_EventScript_ChooseFromX_1

SalesforcetowerElevator_EventScript_ChooseFromX_5:
	multichoicedefault 0, 0, MULTI_FLOORS, 2, FALSE
	goto SalesforcetowerElevator_EventScript_ChooseFromX_1

SalesforcetowerElevator_EventScript_ChooseFromX_6:
	multichoicedefault 0, 0, MULTI_FLOORS, 3, FALSE
	goto SalesforcetowerElevator_EventScript_ChooseFromX_1


SalesforcetowerElevator_EventScript_ChooseFloor::
	switch VAR_RESULT
	case 0, SalesforcetowerElevator_EventScript_ChooseFloor_3
	case 1, SalesforcetowerElevator_EventScript_ChooseFloor_4
	case 2, SalesforcetowerElevator_EventScript_ChooseFloor_5
	case 3, SalesforcetowerElevator_EventScript_ChooseFloor_6
	case 4, SalesforcetowerElevator_EventScript_ChooseFloor_7
	case ( MULTI_B_PRESSED ), SalesforcetowerElevator_EventScript_ChooseFloor_8
SalesforcetowerElevator_EventScript_ChooseFloor_1:
	end

SalesforcetowerElevator_EventScript_ChooseFloor_3:
	goto SalesforcetowerElevator_EventScript_10thFloor
	goto SalesforcetowerElevator_EventScript_ChooseFloor_1

SalesforcetowerElevator_EventScript_ChooseFloor_4:
	goto SalesforcetowerElevator_EventScript_5thFloor
	goto SalesforcetowerElevator_EventScript_ChooseFloor_1

SalesforcetowerElevator_EventScript_ChooseFloor_5:
	goto SalesforcetowerElevator_EventScript_2ndFloor
	goto SalesforcetowerElevator_EventScript_ChooseFloor_1

SalesforcetowerElevator_EventScript_ChooseFloor_6:
	goto SalesforcetowerElevator_EventScript_1stFloor
	goto SalesforcetowerElevator_EventScript_ChooseFloor_1

SalesforcetowerElevator_EventScript_ChooseFloor_7:
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	goto SalesforcetowerElevator_EventScript_ChooseFloor_1

SalesforcetowerElevator_EventScript_ChooseFloor_8:
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	goto SalesforcetowerElevator_EventScript_ChooseFloor_1


SalesforcetowerElevator_EventScript_1stFloor::
	setvar VAR_0x8006, SALESFORCETOWER_FLOORNUM_1F
	setdynamicwarp MAP_SALESFORCETOWER_1F, 255, 8, 2
	compare VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_1F
	goto_if_eq SalesforcetowerElevator_EventScript_1stFloor_2
SalesforcetowerElevator_EventScript_1stFloor_1:
	call SalesforcetowerElevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_1F
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	end

SalesforcetowerElevator_EventScript_1stFloor_2:
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	goto SalesforcetowerElevator_EventScript_1stFloor_1


SalesforcetowerElevator_EventScript_2ndFloor::
	setvar VAR_0x8006, SALESFORCETOWER_FLOORNUM_2F
	setdynamicwarp MAP_SALESFORCETOWER_2F, 255, 9, 39
	compare VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_2F
	goto_if_eq SalesforcetowerElevator_EventScript_2ndFloor_2
SalesforcetowerElevator_EventScript_2ndFloor_1:
	call SalesforcetowerElevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_2F
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	end

SalesforcetowerElevator_EventScript_2ndFloor_2:
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	goto SalesforcetowerElevator_EventScript_2ndFloor_1


SalesforcetowerElevator_EventScript_5thFloor::
	setvar VAR_0x8006, SALESFORCETOWER_FLOORNUM_5F
	setdynamicwarp MAP_SALESFORCETOWER_5F, 255, 16, 28
	compare VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_5F
	goto_if_eq SalesforcetowerElevator_EventScript_5thFloor_2
SalesforcetowerElevator_EventScript_5thFloor_1:
	call SalesforcetowerElevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_5F
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	end

SalesforcetowerElevator_EventScript_5thFloor_2:
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	goto SalesforcetowerElevator_EventScript_5thFloor_1


SalesforcetowerElevator_EventScript_10thFloor::
	setvar VAR_0x8006, SALESFORCETOWER_FLOORNUM_10F
	setdynamicwarp MAP_SALESFORCETOWER_10F, 255, 8, 2
	compare VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_10F
	goto_if_eq SalesforcetowerElevator_EventScript_10thFloor_2
SalesforcetowerElevator_EventScript_10thFloor_1:
	call SalesforcetowerElevator_EventScript_MoveElevator
	setvar VAR_DEPT_STORE_FLOOR, SALESFORCETOWER_FLOORNUM_10F
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	end

SalesforcetowerElevator_EventScript_10thFloor_2:
	goto SalesforcetowerElevator_EventScript_ExitFloorSelect
	goto SalesforcetowerElevator_EventScript_10thFloor_1


SalesforcetowerElevator_EventScript_ExitFloorSelect::
	special CloseDeptStoreElevatorWindow
	release
	end


SalesforcetowerElevator_EventScript_MoveElevator::
	special CloseDeptStoreElevatorWindow
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	waitse
	special MoveElevator
	waitstate
	setflag FLAG_TEMP_2
	return


SalesforcetowerElevator_EventScript_SetFloor::
	special SetSalesforcetowerFloor
	return


gText_Salesforcetower_Elevator_TheAttendantIsGone::
	.string "The attendant is gone...but I don't\n"
	.string "think the elevator works without their\l"
	.string "keycard. Guess I have to take the\l"
	.string "stairs.$"