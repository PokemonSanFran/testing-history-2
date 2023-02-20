Quest_Hang20_ResetCount_Script::
	setvar VAR_DEFEATED_PACIFICA_COUNT, 0
	return


Quest_Hang20_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_MORTY_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_Hang20_HideLeader_Script_1
	compare VAR_RESULT, 5
	goto_if_lt Quest_Hang20_HideLeader_Script_1
	return

Quest_Hang20_HideLeader_Script_1:
	setflag FLAG_TEMP_6
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
	goto Quest_Hang20_StartQuest_Dialogue
	return

Quest_Hang20_Interact_Script_2:
	goto Quest_Hang20_Active_Dialogue
	return

Quest_Hang20_Interact_Script_3:
	goto Quest_Hang20_Reward_Dialogue
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
	msgbox gText_Hang20_HeyYouNewHere
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Hang20_YeahOrre
	callnative ClearMugshot
	msgbox gText_Hang20_OhDamnThatsLandLocked
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Hang20_WereTouchingTheSea
	callnative ClearMugshot
	msgbox gText_Hang20_NoWaves
	msgbox gText_Hang20_DoYouWannaLearn
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Hang20_OhIveNever
	callnative ClearMugshot
	msgbox gText_Hang20_ItsToughSoWeGotta
	msgbox gText_Hang20_WaitBeating
	msgbox gText_Hang20_WellTeachYouToSurfIf
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
	msgbox gText_Hang20_WellTeachYouToSurfIf, MSGBOX_NPC
Quest_Hang20_Active_Dialogue_1:
	end

Quest_Hang20_Active_Dialogue_2:
	msgbox gText_Hang20_AlmostThere, MSGBOX_NPC
	goto Quest_Hang20_Active_Dialogue_1

Quest_Hang20_Active_Dialogue_3:
	msgbox gText_Hang20_MaybeYoureTough, MSGBOX_NPC
	goto Quest_Hang20_Active_Dialogue_1

Quest_Hang20_Active_Dialogue_4:
	msgbox gText_Hang20_SawYouKickingAss, MSGBOX_NPC
	goto Quest_Hang20_Active_Dialogue_1


Quest_Hang20_Reward_Dialogue::
	msgbox gText_Hang20_DamnYouAreTough
	giveitem ITEM_HM03, 1
	msgbox gText_Hang20_OkaySoHeresHow
	closemessage
	applymovement 6, Quest_Hang20_SurfAway_Movement
	completequest QUEST_HANG20
	waitmovement 6
	removeobject 6
	release
	end


Quest_Hang20_Secret_Dialogue::
	msgbox gText_Hang20_OhShitYoure
	msgbox gText_Hang20_YoureSuperTough
	msgbox gText_Hang20_ImFromOrre
	msgbox gText_Hang20_WordItsMad
	giveitem ITEM_HM03, 1
	msgbox gText_Hang20_JustWalkUp
	closemessage
	applymovement 6, Quest_Hang20_SurfAway_Movement
	waitmovement 6
	removeobject 6
	questmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HANG20
	release
	end


Quest_Hang20_SurfAway_Movement:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

gText_Hang20_HeyYouNewHere::
	.string "Yoooo {PLAYER}, right? You're not\n"
	.string "SanFran born, right?$"

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
	.string "You tryna learn how to ride the waves?$"

gText_Hang20_OhIveNever::
	.string "Oh, I've never really given it a shot. Is\n"
	.string "it hard?$"

gText_Hang20_ItsToughSoWeGotta::
	.string "It's tough, so we gotta make sure you're\n"
	.string "ready.$"

gText_Hang20_WaitBeating::
	.string "Wait, beating you doesn't make me tough\n"
	.string "enough?$"

gText_Hang20_WellTeachYouToSurfIf::
	.string "I'll teach you to Surf if you can defeat\n"
	.string "30 Pokémon here in a row. No healing\l"
	.string "items, no accessing the PC, no leaving\l"
	.string "Pacifica.$"

gText_Hang20_AlmostThere::
	.string "Keep that energy!$"

gText_Hang20_MaybeYoureTough::
	.string "Maybe you're tough after all!$"

gText_Hang20_SawYouKickingAss::
	.string "I saw you kicking ass out there!$"

gText_Hang20_DamnYouAreTough::
	.string "Okay, beating me was no fluke, you're\n"
	.string "the real deal. Take this!$"

gText_Hang20_OkaySoHeresHow::
	.string "If you have a Pokémon in your party\n"
	.string "that can learn Surf, you can just walk\l"
	.string "onto the waves and handle it, no\l"
	.string "problem. Watch!$"

gText_Hang20_OhShitYoure::
	.string "Hey, you're {PLAYER}, right? Killer\n"
	.string "waves, right? Not as good as back home,\l"
	.string "but still sick.$"

gText_Hang20_YoureSuperTough::
	.string "Here to catch some waves?$"

gText_Hang20_ImFromOrre::
	.string "I'm from Orre! We're landlocked, so I\n"
	.string "never learned to Surf.$"

gText_Hang20_WordItsMad::
	.string "Word? It's mad easy to learn though,\n"
	.string "hold on...$"

gText_Hang20_JustWalkUp::
	.string "If you've got a Pokémon that can learn\n"
	.string "Surf, you can just walk onto the waves\l"
	.string "now, no problem! Check it!$"
