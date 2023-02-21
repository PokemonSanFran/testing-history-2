RabiesOutbreak_Officer_Event_Script::
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_RABIESOUTBREAK
	compare VAR_RESULT, 0
	goto_if_ne RabiesOutbreak_Officer_Event_Script_2
RabiesOutbreak_Officer_Event_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RABIESOUTBREAK
	compare VAR_RESULT, 0
	goto_if_ne RabiesOutbreak_Officer_Event_Script_5
RabiesOutbreak_Officer_Event_Script_4:
	msgbox gText_RabiesOutbreak_ThisOutbreak, MSGBOX_NPC, SPEAKER_DEFAULT
	end

RabiesOutbreak_Officer_Event_Script_2:
	goto RabiesOutbreak_Reward_Dialogue
	goto RabiesOutbreak_Officer_Event_Script_1

RabiesOutbreak_Officer_Event_Script_5:
	goto RabiesOutbreak_CompleteQuest_Dialogue
	goto RabiesOutbreak_Officer_Event_Script_4


RabiesOutbreak_Reward_Dialogue::
	msgbox gText_RabiesOutbreak_INoticed, MSGBOX_NPC, SPEAKER_DEFAULT
	msgbox gText_RabiesOutbreak_ImHelping, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_RabiesOutbreak_Rabies, MSGBOX_NPC, SPEAKER_DEFAULT
	closemessage
	call RabiesOutbreak_GiveReward_Script
	completequest QUEST_RABIESOUTBREAK
	end


RabiesOutbreak_GiveReward_Script::
	giveitem ITEM_LUXURY_BALL, 10
	return


RabiesOutbreak_CompleteQuest_Dialogue::
	msgbox gText_RabiesOutbreak_CrazyWhatYou, MSGBOX_NPC, SPEAKER_DEFAULT
	end


gText_RabiesOutbreak_ThisOutbreak::
	.string "This outbreak is like nothing I've seen\n"
	.string "before!$"

gText_RabiesOutbreak_INoticed::
	.string "I noticed you were engaging a lot of\n"
	.string "Glameow. What are you up to?$"

gText_RabiesOutbreak_ImHelping::
	.string "I'm helping with the rabies outbreak! I\n"
	.string "saw online you were rewarding Trainers\l"
	.string "that can help bring the numbers down.$"

gText_RabiesOutbreak_Rabies::
	.string "Rabies? I don't know where you saw\n"
	.string "that, but there's no rabies outbreak.\l"
	.string "Oddly enough, the Glameow here all seem\l"
	.string "to be spreading Pokérus at alarmingly\l"
	.string "high rates. But you came all the way\l"
	.string "out here to help... I might have\l"
	.string "something for you. Hold on.$"

gText_RabiesOutbreak_CrazyWhatYou::
	.string "Crazy what you can read online...\n"
	.string "rabies? Can Pokémon even get rabies?$"
