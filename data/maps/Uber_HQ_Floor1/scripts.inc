Uber_HQ_Floor1_MapScripts::
	.byte 0


Uber_HQ_Floor1_StairsGuard_Dialogue::
	msgbox gText_Uber_HQ_Floor1_SorryNo, MSGBOX_NPC, SPEAKER_UBER_GRUNT2
	goto_if_set FLAG_QUEST_PERSUASIVE_PASSENGER_PLAYER_KIDNAPPED, Uber_HQ_Floor1_StairsGuard_Dialogue_2
Uber_HQ_Floor1_StairsGuard_Dialogue_1:
	end

Uber_HQ_Floor1_StairsGuard_Dialogue_2:
	goto Quest_Persuasivepassenger_Grunt2_Event_Script
	goto Uber_HQ_Floor1_StairsGuard_Dialogue_1


gText_Uber_HQ_Floor1_SorryNo::
	.string "Sorry, no entry for non-employees.$"
