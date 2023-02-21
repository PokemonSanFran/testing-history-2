EnterJasmine_Event_Script::
	switch VAR_GYM_6_STATE
	case GYM_SAVE_BEFORE_LEADER, EnterJasmine_Event_Script_2
	case GYM_DEFEATED_LEADER, EnterJasmine_Event_Script_3
	case GYM_EXPLAINED_BADGE_AND_TM, EnterJasmine_Event_Script_4
	goto EnterJasmine_Intro_Dialogue
	return

EnterJasmine_Event_Script_2:
	goto EnterJasmine_StartGymBattle_Script
	return

EnterJasmine_Event_Script_3:
	goto EnterJasmine_PostGymBattle1_Dialogue
	return

EnterJasmine_Event_Script_4:
	goto EnterJasmine_PostGymBattle2_Dialogue
	return


EnterJasmine_Intro_Dialogue::
	lock
	msgbox gText_EnterJasmine_WatchYourStep, MSGBOX_NPC, SPEAKER_JASMINE
	msgbox gText_EnterJasmine_GrowingAGarden, , SPEAKER_JASMINE
	msgbox gText_EnterJasmine_ItsEasyToDestroy, , SPEAKER_JASMINE
	setvar VAR_GYM_6_STATE, GYM_SAVE_BEFORE_LEADER
	call Common_EventScript_SaveGame
	closemessage
	goto EnterJasmine_StartGymBattle_Script
	return


EnterJasmine_StartGymBattle_Script::
	trainerbattle_single TRAINER_WINONA_1, gText_EnterJasmine_LetsSeeHowCareful, gText_EnterJasmine_WrongSoil, EnterJasmine_PostGymBattle_Script, NO_MUSIC
	return


EnterJasmine_PostGymBattle_Script::
	lock
	setflag FLAG_BADGE06_GET
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_GYM_6_STATE, GYM_DEFEATED_LEADER
	setvar VAR_JASMINE_STATE, BATTLE_1_COMPLETE
	msgbox gText_EnterJasmine_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM06
	closemessage
	release
	end


EnterJasmine_PostGymBattle1_Dialogue::
	setvar VAR_GYM_6_STATE, GYM_EXPLAINED_BADGE_AND_TM
	lock
	msgbox gText_EnterJasmine_ThatTechnicalMachineWill, MSGBOX_NPC, SPEAKER_JASMINE
	closemessage
	release
	end


EnterJasmine_PostGymBattle2_Dialogue::
	lock
	msgbox gText_EnterJasmine_AfterAGoodHaircut, MSGBOX_NPC, SPEAKER_JASMINE
	closemessage
	release
	end


gText_EnterJasmine_WatchYourStep::
	.string "Watch your step, there are thousands\n"
	.string "of different seeds under your feet. It\l"
	.string "was an incredible amount of work to get\l"
	.string "all these micro-climates in perfect\l"
	.string "working order…$"

gText_EnterJasmine_GrowingAGarden::
	.string "Growing a garden is much like raising a\n"
	.string "team of Pokémon - they require\l"
	.string "constant care and attention, and even\l"
	.string "the slightest miscalculation can ruin\l"
	.string "the entire crop.$"

gText_EnterJasmine_ItsEasyToDestroy::
	.string "It's easy to destroy a flower bed with\n"
	.string "poor planning, but luckily, Pokémon are\l"
	.string "more resilient.$"

gText_EnterJasmine_LetsSeeHowCareful::
	.string "Let's see how careful and diligent\n"
	.string "you've been in your cultivation.$"

gText_EnterJasmine_WrongSoil::
	.string "Wrong soil? Should I try partial shade?$"

gText_EnterJasmine_ThatTechnicalMachineWill::
	.string "That Technical Machine will plant a seed\n"
	.string "in your Pokémon's mind, allowing them to\l"
	.string "use the move Psfgymattack6.$"

gText_EnterJasmine_AfterAGoodHaircut::
	.string "After a good haircut and when I'm done\n"
	.string "repotting everybody, I'll have to get\l"
	.string "them some battle exposure against\l"
	.string "you!$"

gText_EnterJasmine_BadgeGet::
	.string "You received the JasmineBadge Badge!$"
