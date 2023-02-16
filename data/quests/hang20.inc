Quest_Hang20_ResetCount_Script::
	setvar VAR_DEFEATED_PACIFICA_COUNT, 0
	return


Quest_Hang20_Debug_Script::
	addvar VAR_TEMP_0, 1
	setvar VAR_DEFEATED_PACIFICA_COUNT, 47
	callnative CountDefeatedPacifica
	return


Quest_Hang20_Interact_Script::
	lock
	faceplayer
	returnqueststate QUEST_HANG20
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_Hang20_Interact_Script_2
	case QUEST_MENU_SET_REWARD, Quest_Hang20_Interact_Script_3
	case QUEST_MENU_COMPLETE_QUEST, Quest_Hang20_Interact_Script_4
	goto Quest_Hang20_StartQuest_Dialogue
	return

Quest_Hang20_Interact_Script_2:
	goto Quest_Hang20_Active_Dialogue
	return

Quest_Hang20_Interact_Script_3:
	goto Quest_Hang20_Reward_Dialogue
	return

Quest_Hang20_Interact_Script_4:
	goto Quest_Hang20_Completed_Dialogue
	return


Quest_Hang20_CheckPreCompletion::
	compare VAR_DEFEATED_PACIFICA_COUNT, 29
	goto_if_gt Quest_Hang20_CheckPreCompletion_2
Quest_Hang20_CheckPreCompletion_1:
	return

Quest_Hang20_CheckPreCompletion_2:
	goto Quest_Hang20_Secret_Dialogue
	goto Quest_Hang20_CheckPreCompletion_1


Quest_Hang20_StartQuest_Dialogue::
	call Quest_Hang20_CheckPreCompletion
	msgbox gText_Hang20_HeyYouNewHere, SPEAKER_DEFAULT
	msgbox gText_Hang20_YeahOrre, , SPEAKER_ZOEY
	msgbox gText_Hang20_OhDamnThatsLandLocked, , SPEAKER_DEFAULT
	msgbox gText_Hang20_WereTouchingTheSea, , SPEAKER_ZOEY
	msgbox gText_Hang20_NoWaves, , SPEAKER_DEFAULT
	msgbox gText_Hang20_DoYouWannaLearn, , SPEAKER_DEFAULT
	msgbox gText_Hang20_OhIveNever, , SPEAKER_ZOEY
	msgbox gText_Hang20_ItsToughSoWeGotta, , SPEAKER_DEFAULT
	msgbox gText_Hang20_WellTeachYouToSurfIf, , SPEAKER_DEFAULT
	closemessage
	startquest QUEST_HANG20
	release
	end


Quest_Hang20_Active_Dialogue::
	compare VAR_DEFEATED_PACIFICA_COUNT, 28
	goto_if_gt Quest_Hang20_Active_Dialogue_2
	compare VAR_DEFEATED_PACIFICA_COUNT, 20
	goto_if_gt Quest_Hang20_Active_Dialogue_3
	compare VAR_DEFEATED_PACIFICA_COUNT, 10
	goto_if_gt Quest_Hang20_Active_Dialogue_4
	msgbox gText_Hang20_WellTeachYouToSurfIf, MSGBOX_NPC, SPEAKER_DEFAULT
Quest_Hang20_Active_Dialogue_1:
	end

Quest_Hang20_Active_Dialogue_2:
	msgbox gText_Hang20_AlmostThere, MSGBOX_NPC, SPEAKER_DEFAULT
	goto Quest_Hang20_Active_Dialogue_1

Quest_Hang20_Active_Dialogue_3:
	msgbox gText_Hang20_MaybeYoureTough, MSGBOX_NPC, SPEAKER_DEFAULT
	goto Quest_Hang20_Active_Dialogue_1

Quest_Hang20_Active_Dialogue_4:
	msgbox gText_Hang20_SawYouKickingAss, MSGBOX_NPC, SPEAKER_DEFAULT
	goto Quest_Hang20_Active_Dialogue_1


Quest_Hang20_Reward_Dialogue::
	msgbox gText_Hang20_DamnYouAreTough, , SPEAKER_DEFAULT
	msgbox gText_Hang20_AlthoughIAlreadyKnew, , SPEAKER_DEFAULT
	msgbox gText_Hang20_WaitYouKnew, , SPEAKER_ZOEY
	msgbox gText_Hang20_AnywaysWeGotYouABoard, , SPEAKER_DEFAULT
	giveitem ITEM_SOOT_SACK, 1
	msgbox gText_Hang20_OkaySoHeresHow, , SPEAKER_DEFAULT
	fadescreen FADE_TO_BLACK
	delay 32
	fadescreen FADE_FROM_BLACK
	msgbox gText_Hang20_YoureANatural, , SPEAKER_DEFAULT
	completequest QUEST_HANG20
	release
	end


Quest_Hang20_Completed_Dialogue::
	msgbox gText_Hang20_HowsTheWaves, MSGBOX_NPC, SPEAKER_DEFAULT
	end


Quest_Hang20_Secret_Dialogue::
	msgbox gText_Hang20_OhShitYoure, , SPEAKER_DEFAULT
	msgbox gText_Hang20_YoureSuperTough, , SPEAKER_DEFAULT
	giveitem ITEM_SOOT_SACK, 1
	msgbox gText_Hang20_JustWalkUp, , SPEAKER_DEFAULT
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HANG20
	release
	end


gText_Hang20_HeyYouNewHere::
	.string "Hey you new here? You don't look like\n"
	.string "you're from here.$"

gText_Hang20_YeahOrre::
	.string "Yeah, I'm from Orre.$"

gText_Hang20_OhDamnThatsLandLocked::
	.string "Oh damn, that's land locked, right?$"

gText_Hang20_WereTouchingTheSea::
	.string "We're touching the sea, but not\n"
	.string "anything you can surf in,\l"
	.string "unfortunately.$"

gText_Hang20_NoWaves::
	.string "No waves? Damn that sucks!$"

gText_Hang20_DoYouWannaLearn::
	.string "do you wanna learn to surf$"

gText_Hang20_OhIveNever::
	.string "oh ive never done it but it looks cool$"

gText_Hang20_ItsToughSoWeGotta::
	.string "its tough, so we gotta make sure you're\n"
	.string "tough enough to handle it$"

gText_Hang20_WellTeachYouToSurfIf::
	.string "we'll teach you to surf if you can\n"
	.string "defeat 30 pokemon here in a row. no\l"
	.string "healing, no changing pokemon, no\l"
	.string "leaving.$"

gText_Hang20_AlmostThere::
	.string "almost there, keep at it!$"

gText_Hang20_MaybeYoureTough::
	.string "maybe you're tough after al!$"

gText_Hang20_SawYouKickingAss::
	.string "saw you kicking ass out there$"

gText_Hang20_DamnYouAreTough::
	.string "damn you are tough$"

gText_Hang20_AlthoughIAlreadyKnew::
	.string "although i already knew that. you're\n"
	.string "{PLAYER}$"

gText_Hang20_WaitYouKnew::
	.string "wait you knew who i was$"

gText_Hang20_AnywaysWeGotYouABoard::
	.string "anyways, we got you a surfboard.\n"
	.string "figured you didn't have one$"

gText_Hang20_OkaySoHeresHow::
	.string "okay so heres how you surf....$"

gText_Hang20_YoureANatural::
	.string "you're a natural! you're ready to shred\n"
	.string "your way around the region.$"

gText_Hang20_HowsTheWaves::
	.string "how's the waves?$"

gText_Hang20_OhShitYoure::
	.string "oh shit you're {PLAYER}$"

gText_Hang20_YoureSuperTough::
	.string "you're super tough. do you surf? we've\n"
	.string "got an extra board.$"

gText_Hang20_JustWalkUp::
	.string "just walk up to the waves and press {A_BUTTON}$"
