Oakland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Oakland_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Oakland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Oakland_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Oakland_MapScripts_OnTransition
	return

Oakland_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_FORTREE_CITY_STATE, 3, WarehouseRave_OutsideWarehouse_Dialogue
	.2byte 0


Oakland_MapScripts_OnTransition::
	switch VAR_FORTREE_CITY_STATE
	case 3, Oakland_MapScripts_OnTransition_2
	call WarehouseRave_HideObject_Script
	return

Oakland_MapScripts_OnTransition_2:
	return

