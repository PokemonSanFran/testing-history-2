Gldngtepark_Pannen_House_MapScripts::
	.byte 0


Gldngtepark_Pannen_House_Event_Script::
	lock
	faceplayer
	goto_if_quest_inactive QUEST_HIDDENGROTTOMAPPING, Quest_Hiddengrottomapping2_Event_Script
	goto_if_quest_active QUEST_HIDDENGROTTOMAPPING2, Quest_Hiddengrottomapping2_Event_Script
	goto_if_quest_complete QUEST_HIDDENGROTTOMAPPING2, Quest_Hiddengrottomapping2_Complete_Dialogue
	goto Quest_Hiddengrottomapping_Event_Script
	return


Gldngtepark_Pannen_Wife_Default_Dialogue::
	msgbox gText_Gldngtepark_Pannen_Wife_MyHusbandIs, , SPEAKER_NANCY
	closemessage
	end


gText_Gldngtepark_Pannen_Wife_MyHusbandIs::
	.string "My husband is a researcher in unusual\n"
	.string "Pokemon habitats. You're a Trainer,\l"
	.string "right? I'm sure you'll run into him in\l"
	.string "your travels.$"
