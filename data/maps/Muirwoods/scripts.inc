Muirwoods_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Muirwoods_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Muirwoods_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call EnterTheMaster_Muirwoods_ObjectSetup_Script
	return


Muirwoods_ForestSign_Script::
	msgbox gText_Muirwoods_RegionParkSign, MSGBOX_SIGN
	returnqueststate QUEST_INSTALLNATUREPROBES
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Muirwoods_ForestSign_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Muirwoods_ForestSign_Script_3
	release
	end

Muirwoods_ForestSign_Script_2:
	goto Quest_InstallNatureProbes_InstallForestProbe_Script
	return

Muirwoods_ForestSign_Script_3:
	msgbox gText_InstallNatureProbes_ThereIsAProbe, MSGBOX_SIGN
	return


Muirwoods_HillSign_Script::
	msgbox gText_Muirwoods_RegionParkSign, MSGBOX_SIGN
	returnqueststate QUEST_INSTALLNATUREPROBES
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Muirwoods_HillSign_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Muirwoods_HillSign_Script_3
	release
	end

Muirwoods_HillSign_Script_2:
	goto Quest_InstallNatureProbes_InstallHillProbe_Script
	return

Muirwoods_HillSign_Script_3:
	msgbox gText_InstallNatureProbes_ThereIsAProbe, MSGBOX_SIGN
	return


Muirwoods_ShoreSign_Script::
	msgbox gText_Muirwoods_RegionParkSign, MSGBOX_SIGN
	returnqueststate QUEST_INSTALLNATUREPROBES
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Muirwoods_ShoreSign_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Muirwoods_ShoreSign_Script_3
	release
	end

Muirwoods_ShoreSign_Script_2:
	goto Quest_InstallNatureProbes_InstallShoreProbe_Script
	return

Muirwoods_ShoreSign_Script_3:
	msgbox gText_InstallNatureProbes_ThereIsAProbe, MSGBOX_SIGN
	return


gText_Muirwoods_RegionParkSign::
	.string "Muirwoods Regional Park$"
