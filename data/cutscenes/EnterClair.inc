EnterPsfleader8_Event_Script::
	switch VAR_GYM_8_STATE
	case 3, EnterPsfleader8_Event_Script_2
	case 4, EnterPsfleader8_Event_Script_3
	case 5, EnterPsfleader8_Event_Script_4
	goto EnterPsfleader8_AskAboutGym_Dialogue
	return

EnterPsfleader8_Event_Script_2:
	goto EnterPsfleader8_FacePlayerBeforeBattle
	return

EnterPsfleader8_Event_Script_3:
	goto EnterPsfleader8_PostDefeat1_Dialogue
	return

EnterPsfleader8_Event_Script_4:
	goto EnterPsfleader8_PostDefeat2_Dialogue
	return


EnterPsfleader8_AskAboutGym_Dialogue::
	setvar VAR_GYM_8_STATE, 3
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_SkatingAround, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_ItsInteresting
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_OhComeOn
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_WeirdItsWeird
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_IveAlwaysSaid
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_WhenIWasAwarded
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader8_StartGymBattle_Script
	return


EnterPsfleader8_FacePlayerBeforeBattle::
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_ButTheyNeverWill, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_JUAN_1, gText_EnterPsfleader8_AhIGotTooGreedy
	goto EnterPsfleader8_Psfleader8Deafeated_Script
	return


EnterPsfleader8_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_ButTheyNeverWill
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_JUAN_1, gText_EnterPsfleader8_AhIGotTooGreedy
	goto EnterPsfleader8_Psfleader8Deafeated_Script
	return


EnterPsfleader8_Psfleader8Deafeated_Script::
	lockall
	setflag FLAG_BADGE08_GET
	setvar VAR_GYM_8_STATE, 4
	msgbox gText_EnterPsfleader8_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM08
	closemessage
	releaseall
	end


EnterPsfleader8_PostDefeat1_Dialogue::
	lockall
	setvar VAR_GYM_8_STATE, 5
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_ThatTMwill, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	releaseall
	end


EnterPsfleader8_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterPsfleader8_IGetSoEmotional, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	releaseall
	end


gText_EnterPsfleader8_SkatingAround::
	.string "Skating around the rink down there, you\n"
	.string "put on quite the show, {PLAYER}! What\l"
	.string "do you think of the place?$"

gText_EnterPsfleader8_ItsInteresting::
	.string "It's… interesting?$"

gText_EnterPsfleader8_OhComeOn::
	.string "Oh come on, you won't hurt my feelings.$"

gText_EnterPsfleader8_WeirdItsWeird::
	.string "Weird. It's weird.$"

gText_EnterPsfleader8_IveAlwaysSaid::
	.string "Excellent! I've always said, “Be the\n"
	.string "strange you want to see in the world!”\l"
	.string "And I've busted my ass to make this\l"
	.string "place stranger than fiction… and\l"
	.string "better than art.$"

gText_EnterPsfleader8_WhenIWasAwarded::
	.string "When I was awarded this Gym, I knew I\n"
	.string "had to keep pushing the boundaries.\l"
	.string "It's important to me to keep bending\l"
	.string "the rules, keep everybody guessing,\l"
	.string "thinking, racking their brains to\l"
	.string "figure me out…$"

gText_EnterPsfleader8_ButTheyNeverWill::
	.string "But they never will. Now let's see if you\n"
	.string "can handle the magic!$"

gText_EnterPsfleader8_AhIGotTooGreedy::
	.string "Ah, I got too greedy and tried to have\n"
	.string "it all!$"

gText_EnterPsfleader8_ThatTMwill::
	.string "That TM will teach your Pokémon\n"
	.string "Psfgymattack8. I hope it's as useful\l"
	.string "for you as it has been for me!$"

gText_EnterPsfleader8_IGetSoEmotional::
	.string "I get so emotional every time I think of\n"
	.string "trainers walking out with my badge. Not\l"
	.string "because I'm upset… but I'm proud. Now\l"
	.string "go you magical bitch, conquer the\l"
	.string "world!$"

gText_EnterPsfleader8_BadgeGet::
	.string "You received the Psfbadge8 Badge!$"
