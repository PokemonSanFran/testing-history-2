Pacifica_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Pacifica_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Pacifica_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Pacifica_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call BeachBattle_ObjectVisibility_Script
	call Quest_CutePokemon_HideMelissaC_Script
	call Quest_ShutDownMedicineMan_HideBusinessMan_Script
	call Quest_Hang20_ResetCount_Script
	call Quest_GetTheBand_HideBikerB_Script
	call Quest_Restorechinatown_HideJames_Pacifica_Script
	return

Pacifica_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_STORYLINE_STATE, STORY_EAST_SANFRAN_COMPLETE, TheStrikeStrikesBack_PhoneCall_Dialogue
	.2byte 0


Pacifica_Biker_Interact_Script::
	msgbox gText_Pacifica_PlaceholderBiker, MSGBOX_NPC
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_GETTHEBANDBACKTOGETHER
	compare VAR_RESULT, 0
	goto_if_ne Pacifica_Biker_Interact_Script_2
Pacifica_Biker_Interact_Script_1:
	end

Pacifica_Biker_Interact_Script_2:
	goto Quest_GetTheBand_Interact_BikerB_Dialogue
	goto Pacifica_Biker_Interact_Script_1


gText_Pacifica_PlaceholderBiker::
	.string "i am a biker, and this is placeholder\n"
	.string "text.$"

gText_Pacifica_PlaceholderOaklandFan::
	.string "i used to go to the Oakland stadium a\n"
	.string "lot. i sitll have my ticket stub!$"
