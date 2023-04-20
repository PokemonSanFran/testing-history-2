Castro_IT_MapScripts::
	.byte 0


Castro_IT_Interact_Clerk_Script::
	goto_if_quest_not_inactive QUEST_FOODTRUCKBUREACRACY, Quest_Foodtruckbureaucracy_IT_Active_Dialogue
	goto Castro_IT_Clerk_Dialogue
	return


Castro_IT_Clerk_Dialogue::
	msgbox gText_Castro_IT_UghTheWalk, , MSGBOX_NPC, SPEAKER_WALDRON
	end


gText_Castro_IT_UghTheWalk::
	.string "Ugh, the walk from the trolley stop is\n"
	.string "brutal. Wish I could get one closer...$"
