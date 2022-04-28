Psfcity14_Ramen_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity14_Ramen_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity14_Ramen_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	return


Psfcity14_Ramen_InteractFanny_Event_Script::
	lock
	switch VAR_LILYCOVE_CITY_STATE
	case 1, Psfcity14_Ramen_InteractFanny_Event_Script_3
	case 2, Psfcity14_Ramen_InteractFanny_Event_Script_4
	case 8, Psfcity14_Ramen_InteractFanny_Event_Script_5
	call MaskOff_QuestI_Dialogue
	release
	end

Psfcity14_Ramen_InteractFanny_Event_Script_3:
	return

Psfcity14_Ramen_InteractFanny_Event_Script_4:
	return

Psfcity14_Ramen_InteractFanny_Event_Script_5:
	return

