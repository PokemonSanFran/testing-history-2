EnterClair_Event_Script::
	switch VAR_GYM_8_STATE
	case 3, EnterClair_Event_Script_2
	case 4, EnterClair_Event_Script_3
	case 5, EnterClair_Event_Script_4
	goto EnterClair_AskAboutGym_Dialogue
	return

EnterClair_Event_Script_2:
	goto EnterClair_FacePlayerBeforeBattle_Script
	return

EnterClair_Event_Script_3:
	goto EnterClair_PostGymBattle1_Dialogue
	return

EnterClair_Event_Script_4:
	goto EnterClair_PostGymBattle2_Dialogue
	return


EnterClair_AskAboutGym_Dialogue::
	setvar VAR_GYM_8_STATE, 3
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_SkatingAround, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterClair_ItsInteresting
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_OhComeOn
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterClair_WeirdItsWeird
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_IveAlwaysSaid
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_WhenIWasAwarded
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterClair_StartGymBattle_Script
	return


EnterClair_FacePlayerBeforeBattle_Script::
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_ButTheyNeverWill, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_JUAN_1, gText_EnterClair_AhIGotTooGreedy
	goto EnterClair_ClairDeafeated_Script
	return


EnterClair_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_ButTheyNeverWill
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_JUAN_1, gText_EnterClair_AhIGotTooGreedy
	goto EnterClair_ClairDeafeated_Script
	return


EnterClair_ClairDeafeated_Script::
	lock
	setflag FLAG_BADGE08_GET
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_GYM_8_STATE, 1
	msgbox gText_EnterClair_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM08
	closemessage
	release
	end


EnterClair_PostGymBattle1_Dialogue::
	lock
	setvar VAR_GYM_8_STATE, 5
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_ThatTMwill, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	release
	end


EnterClair_PostGymBattle2_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_CLAIR
	callnative DrawMugshot
	msgbox gText_EnterClair_IGetSoEmotional, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	release
	end


gText_EnterClair_SkatingAround::
	.string "Skating around the rink down there, you\n"
	.string "put on quite the show, {PLAYER}! What\l"
	.string "do you think of the place?$"

gText_EnterClair_ItsInteresting::
	.string "It's… interesting?$"

gText_EnterClair_OhComeOn::
	.string "Oh come on, you won't hurt my feelings.$"

gText_EnterClair_WeirdItsWeird::
	.string "Weird. It's weird.$"

gText_EnterClair_IveAlwaysSaid::
	.string "Excellent! I've always said, “Be the\n"
	.string "strange you want to see in the world!”\l"
	.string "And I've busted my ass to make this\l"
	.string "place stranger than fiction… and\l"
	.string "better than art.$"

gText_EnterClair_WhenIWasAwarded::
	.string "When I was awarded this Gym, I knew I\n"
	.string "had to keep pushing the boundaries.\l"
	.string "It's important to me to keep bending\l"
	.string "the rules, keep everybody guessing,\l"
	.string "thinking, racking their brains to\l"
	.string "figure me out…$"

gText_EnterClair_ButTheyNeverWill::
	.string "But they never will. Now let's see if you\n"
	.string "can handle the magic!$"

gText_EnterClair_AhIGotTooGreedy::
	.string "Ah, I got too greedy and tried to have\n"
	.string "it all!$"

gText_EnterClair_ThatTMwill::
	.string "That TM will teach your Pokémon\n"
	.string "Psfgymattack8. I hope it's as useful\l"
	.string "for you as it has been for me!$"

gText_EnterClair_IGetSoEmotional::
	.string "I get so emotional every time I think of\n"
	.string "trainers walking out with my badge. Not\l"
	.string "because I'm upset… but I'm proud. Now\l"
	.string "go you magical bitch, conquer the\l"
	.string "world!$"

gText_EnterClair_BadgeGet::
	.string "You received the ClairBadge Badge!$"
