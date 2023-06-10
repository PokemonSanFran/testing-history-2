Pacifica_Gemhouse_MapScripts::
	.byte 0


Quest_GemArtist_Event_Script::
	lock
	goto_if_quest_complete QUEST_GEMARTIST, Quest_Gemartist_Complete_Dialogue
	goto_if_quest_active QUEST_GEMARTIST, Quest_Gemartist_Active_Dialogue
	goto_if_quest_inactive QUEST_GEMARTIST, Pacifica_Gemhouse_Artist_Dialogue
	release
	end


Pacifica_Gemhouse_Artist_Dialogue::
	msgbox gText_Pacifica_Gemhouse_LivingByTheBeach, MSGBOX_NPC
	end


gText_Pacifica_Gemhouse_LivingByTheBeach::
	.string "Living by the beach is so perfect. The\n"
	.string "sounds of the waves, the beautiful\l"
	.string "shimmer of the glasss... *sigh*$"
