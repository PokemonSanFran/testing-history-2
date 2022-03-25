TheStorySoFar_ExplainExhibit_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox gText_TheStorySoFar_WelcomeToExhibit
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	setvar VAR_PSFCAVE7_EXHIBIT_STATE, 1
	waitmovement 0
	release
	end


Psfcave7_InteractWithAttendant_Script::
	lock
	applymovement 8, Common_Movement_FacePlayer
	goto TheStorySoFar_Event_Script
	return


TheStorySoFar_EntranceTrigger_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	applymovement 8, Common_Movement_FaceLeft
	goto TheStorySoFar_Event_Script
	return


TheStorySoFar_Event_Script::
	waitmovement 0
	switch VAR_PSFCAVE7_EXHIBIT_STATE
	case 0, TheStorySoFar_Event_Script_2
	case 1, TheStorySoFar_Event_Script_3
	case 2, TheStorySoFar_Event_Script_4
	case 3, TheStorySoFar_Event_Script_5
	case 4, TheStorySoFar_Event_Script_6
	return

TheStorySoFar_Event_Script_2:
	goto TheStorySoFar_ExplainExhibit_Dialogue
	return

TheStorySoFar_Event_Script_3:
	goto TheStorySoFar_CheckNumberDefeated_Script
	return

TheStorySoFar_Event_Script_4:
	goto TheStorySoFar_AwardPlayer_Script
	return

TheStorySoFar_Event_Script_5:
	goto TheStorySoFar_Congratulate_Dialogue
	return

TheStorySoFar_Event_Script_6:
	goto Psfcave7Attendant_HealPlayer_Script
	return


TheStorySoFar_CheckNumberDefeated_Script::
	special CheckNumPsfcave7ExhibitDefeated
	msgbox gText_TheStorySoFar_YoureNotQuiteDone
	switch VAR_RESULT
	case 0, TheStorySoFar_CheckNumberDefeated_Script_3
	case 1, TheStorySoFar_CheckNumberDefeated_Script_4
	case 2, TheStorySoFar_CheckNumberDefeated_Script_5
	case 3, TheStorySoFar_CheckNumberDefeated_Script_6
	case 4, TheStorySoFar_CheckNumberDefeated_Script_7
	case 5, TheStorySoFar_CheckNumberDefeated_Script_8
TheStorySoFar_CheckNumberDefeated_Script_1:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_11
TheStorySoFar_CheckNumberDefeated_Script_9:
	closemessage
	release
	end

TheStorySoFar_CheckNumberDefeated_Script_3:
	msgbox gText_TheStorySoFar_YouNeedToDefeat6
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_4:
	msgbox gText_TheStorySoFar_YouNeedToDefeat5
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_5:
	msgbox gText_TheStorySoFar_YouNeedToDefeat4
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_6:
	msgbox gText_TheStorySoFar_YouNeedToDefeat3
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_7:
	msgbox gText_TheStorySoFar_YouNeedToDefeat2
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_8:
	msgbox gText_TheStorySoFar_YouNeedToDefeat1
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_10:
	msgbox gText_TheStorySoFar_AreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_15
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	call ResetPsfcave7Exhibit_Script
TheStorySoFar_CheckNumberDefeated_Script_14:
	waitmovement 0
	goto TheStorySoFar_CheckNumberDefeated_Script_9

TheStorySoFar_CheckNumberDefeated_Script_11:
	compare VAR_TEMP_1, 16
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_10
	goto TheStorySoFar_CheckNumberDefeated_Script_9

TheStorySoFar_CheckNumberDefeated_Script_15:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	goto TheStorySoFar_CheckNumberDefeated_Script_14


TheStorySoFar_AwardPlayer_Script::
	addvar VAR_PSFCAVE7_EXHIBIT_STATE, 1
	setvar VAR_PSFCAVE7_STATE, 1
	msgbox gText_TheStorySoFar_ExcellentWork
	giveitem ITEM_MACHO_BRACE, 1
	closemessage
	release
	end


TheStorySoFar_Congratulate_Dialogue::
	lock
	msgbox gText_TheStorySoFar_WeHopeYouReturn
	closemessage
	release
	end


TheStorySoFar_StartBattle1_Script::
	trainerbattle_single TRAINER_ALBERTO, gText_TheStorySoFar_IHopeYouDont, gText_TheStorySoFar_SlowDown, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_DontForgetToStop, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign1_Dialogue::
	msgbox gText_TheStorySoFar_OriginallyBuiltAsAPrison, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle2_Script::
	trainerbattle_single TRAINER_ED, gText_TheStorySoFar_IThinkDefense, gText_TheStorySoFar_NotStrongEnough, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_TheBestOffense, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign2_Dialogue::
	msgbox gText_TheStorySoFar_TheCriminalUnderbelly, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle3_Script::
	trainerbattle_single TRAINER_DECLAN, gText_TheStorySoFar_TheresSomethingSpecial, gText_TheStorySoFar_ImNotSpecial, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_ItsHardToDoAnything, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign3_Dialogue::
	msgbox gText_TheStorySoFar_ThePrisonersBeganToTurn, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle4_Script::
	trainerbattle_single TRAINER_FREDRICK, gText_TheStorySoFar_PhysicallyDefensiveMasterpiece, gText_TheStorySoFar_ButLikeTheShip, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_HumansWillAlwaysFind, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign4_Dialogue::
	msgbox gText_TheStorySoFar_AsTensionsBetweenThePrisoners, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle5_Script::
	trainerbattle_single TRAINER_ZANDER, gText_TheStorySoFar_BrokenBonesHealEasily, gText_TheStorySoFar_SomePeopleNeverRecover, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_MakingSureToTakeCare, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign5_Dialogue::
	msgbox gText_TheStorySoFar_TheNaturalDisasterLeft, MSGBOX_SIGN
	return


TheStorySoFar_StartBattle6_Script::
	trainerbattle_single TRAINER_LEAH, gText_TheStorySoFar_HowToughAreYou, gText_TheStorySoFar_TurnsOutPrettyTough, TheStorySoFar_RunDefeatedCheck_Script, NO_MUSIC
	msgbox gText_TheStorySoFar_IHearVoicesStanding, MSGBOX_AUTOCLOSE
	return


TheStorySoFar_ReadSign6_Dialogue::
	msgbox gText_TheStorySoFar_ParksAndRecreation, MSGBOX_SIGN
	return


TheStorySoFar_RunDefeatedCheck_Script::
	special CheckNumPsfcave7ExhibitDefeated
	end


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

gText_TheStorySoFar_AreYouSure::
	.string "Are you sure you want to leave?$"

gText_TheStorySoFar_YouNeedToDefeat6::
	.string "You need to defeat six more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat5::
	.string "You need to defeat five more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat4::
	.string "You need to defeat four more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat3::
	.string "You need to defeat three more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat2::
	.string "You need to defeat two more staff\n"
	.string "members without leaving to complete\l"
	.string "the challenge.$"

gText_TheStorySoFar_YouNeedToDefeat1::
	.string "You need to defeat one more staff\n"
	.string "member without leaving to complete the\l"
	.string "challenge.$"

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
	.string "of their most vocal allies was\l"
	.string "Psfelite2, the strongest member of the\l"
	.string "Psfregion1 Elite Four. Psfelite2\l"
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
