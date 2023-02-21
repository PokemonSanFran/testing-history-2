TheStorySoFar_ExplainExhibit_Dialogue::
	lock
	msgbox gText_TheStorySoFar_WelcomeToExhibit, , SPEAKER_ATTENDANT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_ALCATRAZ_EXHIBIT_STATE, ALCATRAZ_EXHIBIT_START
	release
	end


Alcatraz_InteractWithAttendant_Script::
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
	waitmovement 8
	switch VAR_ALCATRAZ_EXHIBIT_STATE
	case 0, TheStorySoFar_Event_Script_2
	case ALCATRAZ_EXHIBIT_START, TheStorySoFar_Event_Script_3
	case ALCATRAZ_EXHIBIT_FINISH, TheStorySoFar_Event_Script_4
	case ALCATRAZ_EXHIBIT_REWARD, TheStorySoFar_Event_Script_5
	case ALCATRAZ_EXHIBIT_COMPLETE, TheStorySoFar_Event_Script_6
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
	goto AlcatrazAttendant_HealPlayer_Script
	return


TheStorySoFar_CheckNumberDefeated_Script::
	special CheckNumAlcatrazExhibitDefeated
	compare VAR_RESULT, 5
	goto_if_gt TheStorySoFar_CheckNumberDefeated_Script_2
TheStorySoFar_CheckNumberDefeated_Script_1:
	msgbox gText_TheStorySoFar_YoureNotQuiteDone, , SPEAKER_ATTENDANT
	switch VAR_RESULT
	case 0, TheStorySoFar_CheckNumberDefeated_Script_6
	case 1, TheStorySoFar_CheckNumberDefeated_Script_7
	case 2, TheStorySoFar_CheckNumberDefeated_Script_8
	case 3, TheStorySoFar_CheckNumberDefeated_Script_9
	case 4, TheStorySoFar_CheckNumberDefeated_Script_10
	case 5, TheStorySoFar_CheckNumberDefeated_Script_11
TheStorySoFar_CheckNumberDefeated_Script_4:
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 37
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_14
TheStorySoFar_CheckNumberDefeated_Script_12:
	closemessage
	release
	end

TheStorySoFar_CheckNumberDefeated_Script_2:
	goto TheStorySoFar_AwardPlayer_Script
	goto TheStorySoFar_CheckNumberDefeated_Script_1

TheStorySoFar_CheckNumberDefeated_Script_6:
	msgbox gText_TheStorySoFar_YouNeedToDefeat6, , SPEAKER_ATTENDANT
	goto TheStorySoFar_CheckNumberDefeated_Script_4

TheStorySoFar_CheckNumberDefeated_Script_7:
	msgbox gText_TheStorySoFar_YouNeedToDefeat5, , SPEAKER_ATTENDANT
	goto TheStorySoFar_CheckNumberDefeated_Script_4

TheStorySoFar_CheckNumberDefeated_Script_8:
	msgbox gText_TheStorySoFar_YouNeedToDefeat4, , SPEAKER_ATTENDANT
	goto TheStorySoFar_CheckNumberDefeated_Script_4

TheStorySoFar_CheckNumberDefeated_Script_9:
	msgbox gText_TheStorySoFar_YouNeedToDefeat3, , SPEAKER_ATTENDANT
	goto TheStorySoFar_CheckNumberDefeated_Script_4

TheStorySoFar_CheckNumberDefeated_Script_10:
	msgbox gText_TheStorySoFar_YouNeedToDefeat2, , SPEAKER_ATTENDANT
	goto TheStorySoFar_CheckNumberDefeated_Script_4

TheStorySoFar_CheckNumberDefeated_Script_11:
	msgbox gText_TheStorySoFar_YouNeedToDefeat1, , SPEAKER_ATTENDANT
	goto TheStorySoFar_CheckNumberDefeated_Script_4

TheStorySoFar_CheckNumberDefeated_Script_13:
	msgbox gText_TheStorySoFar_AreYouSure, MSGBOX_YESNO, SPEAKER_ATTENDANT
	compare VAR_RESULT, NO
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_18
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	call ResetAlcatrazExhibit_Script
TheStorySoFar_CheckNumberDefeated_Script_17:
	waitmovement 0
	goto TheStorySoFar_CheckNumberDefeated_Script_12

TheStorySoFar_CheckNumberDefeated_Script_14:
	compare VAR_TEMP_1, 60
	goto_if_eq TheStorySoFar_CheckNumberDefeated_Script_13
	goto TheStorySoFar_CheckNumberDefeated_Script_12

TheStorySoFar_CheckNumberDefeated_Script_18:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	goto TheStorySoFar_CheckNumberDefeated_Script_17


TheStorySoFar_AwardPlayer_Script::
	setvar VAR_ALCATRAZ_EXHIBIT_STATE, ALCATRAZ_EXHIBIT_REWARD
	setvar VAR_ALCATRAZ_STATE, FIRST_ARRIVED_ALCATRAZ
	msgbox gText_TheStorySoFar_ExcellentWork, , SPEAKER_ATTENDANT
	giveitem ITEM_MACHO_BRACE, 1
	closemessage
	goto YoungPadawan_Intro_Dialogue
	release
	end


TheStorySoFar_Congratulate_Dialogue::
	lock
	msgbox gText_TheStorySoFar_WeHopeYouReturn, , SPEAKER_ATTENDANT
	closemessage
	release
	end


TheStorySoFar_StartBattle1_Script::
	trainerbattle_single TRAINER_ALBERTO, gText_TheStorySoFar_IHopeYouDont, gText_TheStorySoFar_SlowDown, TheStorySoFar_ReadSign1_Dialogue, NO_MUSIC
	msgbox gText_TheStorySoFar_DontForgetToStop, MSGBOX_AUTOCLOSE, SPEAKER_MACK
	return


TheStorySoFar_ReadSign1_Dialogue::
	special CheckNumAlcatrazExhibitDefeated
	msgbox gText_TheStorySoFar_SpeakerStarted
	msgbox gText_TheStorySoFar_OriginallyBuiltAsAPrison, MSGBOX_SIGN, , SPEAKER_SPEAKER
	return


TheStorySoFar_StartBattle2_Script::
	trainerbattle_single TRAINER_ED, gText_TheStorySoFar_IThinkDefense, gText_TheStorySoFar_NotStrongEnough, TheStorySoFar_ReadSign2_Dialogue, NO_MUSIC
	msgbox gText_TheStorySoFar_TheBestOffense, MSGBOX_AUTOCLOSE, SPEAKER_TYZONN
	return


TheStorySoFar_ReadSign2_Dialogue::
	special CheckNumAlcatrazExhibitDefeated
	msgbox gText_TheStorySoFar_SpeakerStarted
	msgbox gText_TheStorySoFar_TheCriminalUnderbelly, MSGBOX_SIGN, SPEAKER_SPEAKER
	return


TheStorySoFar_StartBattle3_Script::
	trainerbattle_single TRAINER_DECLAN, gText_TheStorySoFar_TheresSomethingSpecial, gText_TheStorySoFar_ImNotSpecial, TheStorySoFar_ReadSign3_Dialogue, NO_MUSIC
	msgbox gText_TheStorySoFar_ItsHardToDoAnything, MSGBOX_AUTOCLOSE, SPEAKER_WILL2
	return


TheStorySoFar_ReadSign3_Dialogue::
	special CheckNumAlcatrazExhibitDefeated
	msgbox gText_TheStorySoFar_SpeakerStarted
	msgbox gText_TheStorySoFar_ThePrisonersBeganToTurn, MSGBOX_SIGN, SPEAKER_SPEAKER
	return


TheStorySoFar_StartBattle4_Script::
	trainerbattle_single TRAINER_FREDRICK, gText_TheStorySoFar_PhysicallyDefensiveMasterpiece, gText_TheStorySoFar_ButLikeTheShip, TheStorySoFar_ReadSign4_Dialogue, NO_MUSIC
	msgbox gText_TheStorySoFar_HumansWillAlwaysFind, MSGBOX_AUTOCLOSE, , SPEAKER_RONNY
	return


TheStorySoFar_ReadSign4_Dialogue::
	special CheckNumAlcatrazExhibitDefeated
	msgbox gText_TheStorySoFar_SpeakerStarted
	msgbox gText_TheStorySoFar_AsTensionsBetweenThePrisoners, MSGBOX_SIGN, SPEAKER_SPEAKER
	return


TheStorySoFar_StartBattle5_Script::
	trainerbattle_single TRAINER_ZANDER, gText_TheStorySoFar_BrokenBonesHealEasily, gText_TheStorySoFar_SomePeopleNeverRecover, TheStorySoFar_ReadSign5_Dialogue, NO_MUSIC
	msgbox gText_TheStorySoFar_MakingSureToTakeCare, MSGBOX_AUTOCLOSE, , SPEAKER_DAX
	return


TheStorySoFar_ReadSign5_Dialogue::
	special CheckNumAlcatrazExhibitDefeated
	msgbox gText_TheStorySoFar_SpeakerStarted
	msgbox gText_TheStorySoFar_TheNaturalDisasterLeft, MSGBOX_SIGN, SPEAKER_SPEAKER
	return


TheStorySoFar_StartBattle6_Script::
	trainerbattle_single TRAINER_LEAH, gText_TheStorySoFar_HowToughAreYou, gText_TheStorySoFar_TurnsOutPrettyTough, TheStorySoFar_ReadSign6_Dialogue, NO_MUSIC
	msgbox gText_TheStorySoFar_IHearVoicesStanding, MSGBOX_AUTOCLOSE, , SPEAKER_BRENNAN
	return


TheStorySoFar_ReadSign6_Dialogue::
	special CheckNumAlcatrazExhibitDefeated
	msgbox gText_TheStorySoFar_SpeakerStarted
	msgbox gText_TheStorySoFar_ParksAndRecreation, MSGBOX_SIGN, SPEAKER_SPEAKER
	return


TheStorySoFar_RunDefeatedCheck_Script::
	special CheckNumAlcatrazExhibitDefeated
	end


gText_TheStorySoFar_WelcomeToExhibit::
	.string "Welcome to the Alcatraz Exhibit! If\n"
	.string "you're looking to learn about the\l"
	.string "island's history and culture, you'll\l"
	.string "need to complete our challenge! Across\l"
	.string "the island, there are six audio spots.\l"
	.string "Stepping on an audio spot will teach\l"
	.string "you some history, but you'll have the\l"
	.string "defeat the Trainer guarding it. If you\l"
	.string "can defeat all six Trainers without\l"
	.string "leaving the park, you'll win a prize! If\l"
	.string "you leave, you'll need to start the\l"
	.string "challenge over again.$"

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
	.string "Alcatraz was originally built as a\n"
	.string "prison for SanFran's most dangerous\l"
	.string "criminals. Alcatraz Prison was\l"
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
	.string "The SanFran criminal underbelly, using\n"
	.string "agents within the prison, staged a\l"
	.string "prison riot. The agents took guards\l"
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
	.string "the strongest member of the SanFran\l"
	.string "Elite Four. Drasna organized public\l"
	.string "rallies and marches, demanding for the\l"
	.string "release of the prisoners into society,\l"
	.string "citing the need for a different\l"
	.string "rehabilitation approach.$"

gText_TheStorySoFar_PhysicallyDefensiveMasterpiece::
	.string "Alcatraz is a physically defensive\n"
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
	.string "Alcatraz was shut down.$"

gText_TheStorySoFar_HowToughAreYou::
	.string "How tough are you?$"

gText_TheStorySoFar_TurnsOutPrettyTough::
	.string "Turns out, pretty tough!$"

gText_TheStorySoFar_IHearVoicesStanding::
	.string "Sometimes, I hear voices standing here\n"
	.string "all day.$"

gText_TheStorySoFar_ParksAndRecreation::
	.string "The SanFran Parks and Recreation has\n"
	.string "dedicated this plaza to the guards who\l"
	.string "lost their lives in the disaster and the\l"
	.string "struggle that divided the region for so\l"
	.string "long. Late at night, some say you can\l"
	.string "hear their spirits, still fighting to\l"
	.string "this day to keep our region safe from\l"
	.string "criminals.$"

gText_TheStorySoFar_ExcellentWork::
	.string "Excellent work! For completing the\n"
	.string "challenge, here is your prize!$"

gText_TheStorySoFar_WeHopeYouReturn::
	.string "Congratulations! We hope you return\n"
	.string "for more training!$"

gText_TheStorySoFar_SpeakerStarted::
	.string "The speaker beneath your feet starting\n"
	.string "talking!$"
