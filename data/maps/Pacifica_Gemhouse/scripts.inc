Pacifica_Gemhouse_MapScripts::
	.byte 0


Quest_GemArtist_Event_Script::
	lock
	returnqueststate QUEST_GEMARTIST
	switch VAR_RESULT
	case 1, Quest_GemArtist_Event_Script_2
	case 2, Quest_GemArtist_Event_Script_3
	case 3, Quest_GemArtist_Event_Script_3
	case 4, Quest_GemArtist_Event_Script_4
	return

Quest_GemArtist_Event_Script_2:
	goto Pacifica_Gemhouse_Artist_Dialogue
	return

Quest_GemArtist_Event_Script_3:
	goto Quest_GemArtist_AskForGlass_Dialogue
	return

Quest_GemArtist_Event_Script_4:
	goto Quest_GemArtist_WantGem_Dialogue
	return


Pacifica_Gemhouse_Artist_Dialogue::
	msgbox gText_Pacifica_Gemhouse_LivingByTheBeach, MSGBOX_NPC
	end


gText_Pacifica_Gemhouse_LivingByTheBeach::
	.string "Living by the beach is so perfect. The\n"
	.string "sounds of the waves, the beautiful\l"
	.string "shimmer of the glasss... *sigh*$"
