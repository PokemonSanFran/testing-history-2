SOMA_Sanitation_MapScripts::
	.byte 0


SOMA_Sanitation_Interact_Clerk_Script::
	goto_if_quest_not_inactive QUEST_FOODTRUCKBUREACRACY, Quest_Foodtruckbureaucracy_Sani_Active_Dialogue
	goto SOMA_Sanitation_Clerk_Dialogue
	return


SOMA_Sanitation_Clerk_Dialogue::
	msgbox gText_SOMA_Sanitation_CouldTheInternet, , MSGBOX_NPC, SPEAKER_WALDRON
	end


gText_SOMA_Sanitation_CouldTheInternet::
	.string "The internet here is so slow! I've been\n"
	.string "told the problem is a router, but good\l"
	.string "luck getting one from IT!$"
