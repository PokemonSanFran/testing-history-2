Psfcave7_MapScripts::
	.byte 0


TheStorySoFar_Event_Script::
	switch VAR_PSFCAVE7_STATE
	case 0, TheStorySoFar_Event_Script_2
	case 1, TheStorySoFar_Event_Script_3
	return

TheStorySoFar_Event_Script_2:
	goto TheStorySoFar_ExplainExhibit_Dialogue
	return

TheStorySoFar_Event_Script_3:
	goto TheStorySoFar_CheckNumberDefeated_Script
	return


TheStorySoFar_ExplainExhibit_Dialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_TheStorySoFar_WelcomeToExhibit
	setvar VAR_PSFCAVE7_STATE, 1
	releaseall
	end


TheStorySoFar_InteractWithAttendant_Script::
	lockall
	msgbox gText_TheStorySoFar_YoureNotQuiteDone, MSGBOX_NPC
	goto TheStorySoFar_CheckNumberDefeated_Script
	return


TheStorySoFar_CheckNumberDefeated_Script::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	switch VAR_RESULT
	case 0, TheStorySoFar_CheckNumberDefeated_Script_2
	case 1, TheStorySoFar_CheckNumberDefeated_Script_3
	case 2, TheStorySoFar_CheckNumberDefeated_Script_4
	case 3, TheStorySoFar_CheckNumberDefeated_Script_5
	case 4, TheStorySoFar_CheckNumberDefeated_Script_6
	case 5, TheStorySoFar_CheckNumberDefeated_Script_7
	return

TheStorySoFar_CheckNumberDefeated_Script_2:
	msgbox gText_TheStorySoFar_YouNeedToDefeat6
	return

TheStorySoFar_CheckNumberDefeated_Script_3:
	msgbox gText_TheStorySoFar_YouNeedToDefeat5
	return

TheStorySoFar_CheckNumberDefeated_Script_4:
	msgbox gText_TheStorySoFar_YouNeedToDefeat4
	return

TheStorySoFar_CheckNumberDefeated_Script_5:
	msgbox gText_TheStorySoFar_YouNeedToDefeat3
	return

TheStorySoFar_CheckNumberDefeated_Script_6:
	msgbox gText_TheStorySoFar_YouNeedToDefeat2
	return

TheStorySoFar_CheckNumberDefeated_Script_7:
	msgbox gText_TheStorySoFar_YouNeedToDefeat1
	return


TheStorySoFar_StartBattle1_Script::
	lockall
	checktrainerflag TRAINER_ALBERTO
	goto_if 1, TheStorySoFar_StartBattle1_Script_2
	trainerbattle_single TRAINER_ALBERTO, gText_TheStorySoFar_IHopeYouDont, gText_TheStorySoFar_SlowDown, TheStorySoFar_DefeatedTrainer1_Script, NO_MUSIC
TheStorySoFar_StartBattle1_Script_1:
	releaseall
	end

TheStorySoFar_StartBattle1_Script_2:
	msgbox gText_TheStorySoFar_DontForgetToStop, MSGBOX_NPC
	goto TheStorySoFar_StartBattle1_Script_1


TheStorySoFar_DefeatedTrainer1_Script::
	compare VAR_PSFCAVE7_STATE, 1
	goto_if_eq TheStorySoFar_DefeatedTrainer1_Script_1
	return

TheStorySoFar_DefeatedTrainer1_Script_1:
	applymovement 4, Common_Movement_WalkUp
	waitmovement 0
	return


TheStorySoFar_ReadSign1_Dialogue::
	msgbox gText_TheStorySoFar_OriginallyBuiltAsAPrison, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle2_Script::
	lockall
	checktrainerflag TRAINER_ED
	goto_if 1, TheStorySoFar_StartBattle2_Script_1
	trainerbattle_single TRAINER_ED, gText_TheStorySoFar_IThinkDefense, gText_TheStorySoFar_NotStrongEnough, TheStorySoFar_DefeatedTrainer2_Script, NO_MUSIC
	releaseall
	end

TheStorySoFar_StartBattle2_Script_1:
	msgbox gText_TheStorySoFar_TheBestOffense, MSGBOX_NPC
	return


TheStorySoFar_DefeatedTrainer2_Script::
	compare VAR_PSFCAVE7_STATE, 1
	goto_if_eq TheStorySoFar_DefeatedTrainer2_Script_1
	return

TheStorySoFar_DefeatedTrainer2_Script_1:
	applymovement 7, Common_Movement_WalkUp
	waitmovement 0
	return


TheStorySoFar_ReadSign2_Dialogue::
	msgbox gText_TheStorySoFar_TheCriminalUnderbelly, MSGBOX_SIGN
	return


gText_TheStorySoFar_WelcomeToExhibit::
	.string "Welcome to the Psfcave7 Exhibit. To\n"
	.string "learn about the island, you'll need to\l"
	.string "battle our staff. Trainers who can\l"
	.string "defeat all six without leaving the park\l"
	.string "or being defeated will complete the\l"
	.string "challenge and win a prize! If you leave,\l"
	.string "you'll need to start the challenge over\l"
	.string "again.$"

gText_TheStorySoFar_YoureNotQuiteDone::
	.string "You're not quite done.$"

gText_TheStorySoFar_YouNeedToDefeat6::
	.string "You need to defeat six more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge. Are you sure you want to\l"
	.string "leave?$"

gText_TheStorySoFar_YouNeedToDefeat5::
	.string "You need to defeat five more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge. Are you sure you want to\l"
	.string "leave?$"

gText_TheStorySoFar_YouNeedToDefeat4::
	.string "You need to defeat four more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge. Are you sure you want to\l"
	.string "leave?$"

gText_TheStorySoFar_YouNeedToDefeat3::
	.string "You need to defeat three more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge. Are you sure you want to\l"
	.string "leave?$"

gText_TheStorySoFar_YouNeedToDefeat2::
	.string "You need to defeat two more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge. Are you sure you want to\l"
	.string "leave?$"

gText_TheStorySoFar_YouNeedToDefeat1::
	.string "You need to defeat one more staff\n"
	.string "member without leaving to complete the\l"
	.string "challenge. Are you sure you want to\l"
	.string "leave?$"

gText_TheStorySoFar_IHopeYouDont::
	.string "I hope you don't rush through the plaza\n"
	.string "here!$"

gText_TheStorySoFar_SlowDown::
	.string "Slow down!$"

gText_TheStorySoFar_DontForgetToStop::
	.string "Don't forget to stop and smell the\n"
	.string "roses.$"

gText_TheStorySoFar_OriginallyBuiltAsAPrison::
	.string "Psfcave7 was originally built as a\n"
	.string "prison for Psfregion1's most dangerous\l"
	.string "criminals. Psfcave7 Prison was\l"
	.string "nationally praised for its state of the\l"
	.string "art facilities, forward thinking\l"
	.string "approach to rehabilitation, and no\l"
	.string "escape attempts.$"

gText_TheStorySoFar_IThinkDefense::
	.string "I think the best defense is an\n"
	.string "overwhelming offense.$"

gText_TheStorySoFar_NotStrongEnough::
	.string "Not strong enough!$"

gText_TheStorySoFar_TheBestOffense::
	.string "The best offense is the kind that gets\n"
	.string "stronger with time.$"

gText_TheStorySoFar_TheCriminalUnderbelly::
	.string "The Psfregion1 criminal underbelly,\n"
	.string "using agents within the prison, staged\l"
	.string "a prison riot. The agents took guards\l"
	.string "hostage, and demanded that the\l"
	.string "government turn the island over to the\l"
	.string "prisoners. This occupation lasted for\l"
	.string "years, and the demands of the\l"
	.string "prisoners grew more unreasonable as\l"
	.string "time went on.$"

gText_TheStorySoFar_TheresSomethingSpecial::
	.string "There's something special about power\n"
	.string "in large groups...$"

gText_TheStorySoFar_ImNotSpecial::
	.string "I'm not special on my own.$"

gText_TheStorySoFar_ItsHardToDoAnything::
	.string "It's hard to do anything meaningful on\n"
	.string "your own. We're made to work together!$"

gText_TheStorySoFar_ThePrisonersBeganToTurn::
	.string "The prisoners began to turn to the\n"
	.string "citizens of the region for support. One\l"
	.string "of their most vocal allies was Drasna,\l"
	.string "the strongest member of the\l"
	.string "Psfregion1 Elite Four. Drasna\l"
	.string "organized public rallies and marches,\l"
	.string "demanding for the release of the\l"
	.string "prisoners into society, citing the need\l"
	.string "for a different rehabilitation\l"
	.string "approach.$"

gText_TheStorySoFar_PhysicallyDefensiveMasterpiece::
	.string "Psfcave7 is a physically defensive\n"
	.string "masterpiece, isn't it?$"

gText_TheStorySoFar_ButLikeTheShip::
	.string "But like the ship that couldn't sink...$"

gText_TheStorySoFar_HumansWillAlwaysFind::
	.string "Humans will always find a way to ruin\n"
	.string "perfection.$"

gText_TheStorySoFar_AsTensionsBetweenThePrisoners::
	.string "As tensions between the prisoners,\n"
	.string "their sympathizers, and the\l"
	.string "government reached a fever pitch,\l"
	.string "disaster suddenly struck. An\l"
	.string "unprecedented earthquake ripped\l"
	.string "through the eastern seaboard of the\l"
	.string "region, destroying the structure of\l"
	.string "the prison. Hundreds were injured, and\l"
	.string "many were killed.$"

gText_TheStorySoFar_BrokenBonesHealEasily::
	.string "Broken bones heal easily, but the spirit\n"
	.string "is a whole other matter.$"

gText_TheStorySoFar_SomePeopleNeverRecover::
	.string "Some people never recover!$"

gText_TheStorySoFar_MakingSureToTakeCare::
	.string "Making sure to take care of your soul is\n"
	.string "important!$"

gText_TheStorySoFar_TheNaturalDisasterLeft::
	.string "The natural disaster left the prisoners\n"
	.string "broken and defeated, and they quickly\l"
	.string "surrendered. The prisoners were\l"
	.string "charged with conspiracy and\l"
	.string "instigation, seperated, and sent to\l"
	.string "different prisons around the nation.\l"
	.string "Psfcave7 was shut down.$"

gText_TheStorySoFar_HowToughAreYou::
	.string "How tough are you?$"

gText_TheStorySoFar_TurnsOutPrettyTough::
	.string "Turns out, pretty tough!$"

gText_TheStorySoFar_IHearVoicesStanding::
	.string "Sometimes, I hear voices standing here\n"
	.string "all day.$"

gText_TheStorySoFar_ParksAndRecreation::
	.string "The Psfregion1 Parks and Recreation\n"
	.string "has dedicated this plaza to the guards\l"
	.string "who lost their lives in the disaster and\l"
	.string "the struggle that divided the region\l"
	.string "for so long. Late at night, some say you\l"
	.string "can hear their spirits, still fighting\l"
	.string "to this day to keep our region safe\l"
	.string "from criminals.$"

gText_TheStorySoFar_ExcellentWork::
	.string "Excellent work! For completing the\n"
	.string "challenge, here is your prize!$"

gText_TheStorySoFar_WeHopeYouReturn::
	.string "Congratulations! We hope you return\n"
	.string "for more training!$"

gText_TheStorySoFar_IveHealedYourParty::
	.string "I've healed your party! You can battle\n"
	.string "these Trainers as often as you like.$"
