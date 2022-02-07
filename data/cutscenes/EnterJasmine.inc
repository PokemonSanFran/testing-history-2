EnterPsfleader6_Event_Script::
	switch VAR_GYM_6_STATE
	case 3, EnterPsfleader6_Event_Script_2
	case 4, EnterPsfleader6_Event_Script_3
	case 5, EnterPsfleader6_Event_Script_4
	goto EnterPsfleader6_Psfleader6Intro_Dialogue
	return

EnterPsfleader6_Event_Script_2:
	goto EnterPsfleader6_StartGymBattle_Script
	return

EnterPsfleader6_Event_Script_3:
	goto EnterPsfleader6_PostDefeat1_Dialogue
	return

EnterPsfleader6_Event_Script_4:
	goto EnterPsfleader6_PostDefeat2_Dialogue
	return


EnterPsfleader6_Psfleader6Intro_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_JASMINE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader6_WatchYourStep, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_JASMINE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader6_GrowingAGarden
	setvar VAR_0x8000, MUGSHOT_JASMINE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader6_ItsEasyToDestroy
	callnative ClearMugshot
	setvar VAR_GYM_6_STATE, 3
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader6_StartGymBattle_Script
	return


EnterPsfleader6_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_JASMINE
	callnative DrawMugshot
	trainerbattle_single TRAINER_WINONA_1, gText_EnterPsfleader6_LetsSeeHowCareful, gText_EnterPsfleader6_WrongSoil, EnterPsfleader6_Psfleader6Defeated_Script, NO_MUSIC
	return


EnterPsfleader6_Psfleader6Defeated_Script::
	lockall
	setflag FLAG_BADGE06_GET
	setvar VAR_GYM_6_STATE, 4
	msgbox gText_EnterPsfleader6_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM06
	closemessage
	releaseall
	end


EnterPsfleader6_PostDefeat1_Dialogue::
	setvar VAR_GYM_6_STATE, 5
	lockall
	setvar VAR_0x8000, MUGSHOT_JASMINE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader6_ThatTechnicalMachineWill, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader6_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_JASMINE
	callnative DrawMugshot
	msgbox gText_EnterPsfleader6_AfterAGoodHaircut, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


gText_EnterPsfleader6_WatchYourStep::
	.string "Watch your step, there are thousands\n"
	.string "of different seeds under your feet. It\l"
	.string "was an incredible amount of work to get\l"
	.string "all these micro-climates in perfect\l"
	.string "working order…$"

gText_EnterPsfleader6_GrowingAGarden::
	.string "Growing a garden is much like raising a\n"
	.string "team of Pokémon - they require\l"
	.string "constant care and attention, and even\l"
	.string "the slightest miscalculation can ruin\l"
	.string "the entire crop.$"

gText_EnterPsfleader6_ItsEasyToDestroy::
	.string "It's easy to destroy a flower bed with\n"
	.string "poor planning, but luckily, Pokémon are\l"
	.string "more resilient.$"

gText_EnterPsfleader6_LetsSeeHowCareful::
	.string "Let's see how careful and diligent\n"
	.string "you've been in your cultivation.$"

gText_EnterPsfleader6_WrongSoil::
	.string "Wrong soil? Should I try partial shade?$"

gText_EnterPsfleader6_ThatTechnicalMachineWill::
	.string "That Technical Machine will plant a seed\n"
	.string "in your Pokémon's mind, allowing them to\l"
	.string "use the move Psfgymattack6.$"

gText_EnterPsfleader6_AfterAGoodHaircut::
	.string "After a good haircut and when I'm done\n"
	.string "repotting everybody, I'll have to get\l"
	.string "them some battle exposure against\l"
	.string "you!$"

gText_EnterPsfleader6_BadgeGet::
	.string "You received the Psfbadge6 Badge!$"
