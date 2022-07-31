Quest_HauntABuilding_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_3
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_HideObject_Script_1
	return

Quest_HauntABuilding_HideObject_Script_1:
	setflag FLAG_TEMP_2
	return


Quest_HauntABuilding_Interact_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_HAUNTABUILDING
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_Interact_Script_1
	goto Quest_HauntABuilding_Activate_Dialogue
	return

Quest_HauntABuilding_Interact_Script_1:
	goto Quest_HauntABuilding_AskPokemon_Dialogue
	return


Quest_HauntABuilding_Activate_Dialogue::
	lock
	msgbox gText_HauntABuilding_IDontKnow, MSGBOX_DEFAULT
	msgbox gText_HauntABuilding_OhMaybeYou, MSGBOX_NPC
	msgbox gText_HauntABuilding_IToldTheDeveloper, MSGBOX_NPC
	msgbox gText_HauntABuilding_IWouldDoIt, MSGBOX_NPC
	msgbox gText_HauntABuilding_BringSomeScary, MSGBOX_NPC
	startquest QUEST_HAUNTABUILDING
	release
	end


Quest_HauntABuilding_AskPokemon_Dialogue::
	msgbox gText_HauntABuilding_DoYouHaveAScary, MSGBOX_NPC
	goto Quest_HauntABuilding_CheckPokemon_Script
	return


Quest_HauntABuilding_CheckPokemon_Script::
	special ChoosePartyMon
	waitstate
	specialvar VAR_RESULT, CountPartyNonEggMons
	compare VAR_RESULT, 1
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_2
Quest_HauntABuilding_CheckPokemon_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_5
Quest_HauntABuilding_CheckPokemon_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_8
Quest_HauntABuilding_CheckPokemon_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_13
Quest_HauntABuilding_CheckPokemon_Script_12:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_18
Quest_HauntABuilding_CheckPokemon_Script_17:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_23
Quest_HauntABuilding_CheckPokemon_Script_22:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_6
	compare VAR_RESULT, 0
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_28
Quest_HauntABuilding_CheckPokemon_Script_27:
	goto Quest_HauntABuilding_NoPokemon_Dialogue
	return

Quest_HauntABuilding_CheckPokemon_Script_2:
	goto Quest_HauntABuilding_LastPokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_1

Quest_HauntABuilding_CheckPokemon_Script_5:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_LITWICK
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_10
	goto Quest_HauntABuilding_CheckPokemon_Script_4

Quest_HauntABuilding_CheckPokemon_Script_8:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_LITWICK
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_15
	goto Quest_HauntABuilding_CheckPokemon_Script_7

Quest_HauntABuilding_CheckPokemon_Script_10:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HAUNTABUILDING, SUB_QUEST_1
	goto Quest_HauntABuilding_TakePokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_4

Quest_HauntABuilding_CheckPokemon_Script_13:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_SINISTEA
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_20
	goto Quest_HauntABuilding_CheckPokemon_Script_12

Quest_HauntABuilding_CheckPokemon_Script_15:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HAUNTABUILDING, SUB_QUEST_2
	goto Quest_HauntABuilding_TakePokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_7

Quest_HauntABuilding_CheckPokemon_Script_18:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_SINISTEA
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_25
	goto Quest_HauntABuilding_CheckPokemon_Script_17

Quest_HauntABuilding_CheckPokemon_Script_20:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HAUNTABUILDING, SUB_QUEST_3
	goto Quest_HauntABuilding_TakePokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_12

Quest_HauntABuilding_CheckPokemon_Script_23:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_CHANDELURE
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_30
	goto Quest_HauntABuilding_CheckPokemon_Script_22

Quest_HauntABuilding_CheckPokemon_Script_25:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HAUNTABUILDING, SUB_QUEST_4
	goto Quest_HauntABuilding_TakePokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_17

Quest_HauntABuilding_CheckPokemon_Script_28:
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_TREVENANT
	goto_if_eq Quest_HauntABuilding_CheckPokemon_Script_32
	goto Quest_HauntABuilding_CheckPokemon_Script_27

Quest_HauntABuilding_CheckPokemon_Script_30:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HAUNTABUILDING, SUB_QUEST_5
	goto Quest_HauntABuilding_TakePokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_22

Quest_HauntABuilding_CheckPokemon_Script_32:
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HAUNTABUILDING, SUB_QUEST_6
	goto Quest_HauntABuilding_TakePokemon_Dialogue
	goto Quest_HauntABuilding_CheckPokemon_Script_27


Quest_HauntABuilding_TakePokemon_Script::
	msgbox Quest_HauntABuilding_TakePokemon_Script_Text_0
	return


Quest_HauntABuilding_TakePokemon_Dialogue::
	call Quest_HauntABuilding_TakePokemon_Script
	msgbox gText_HauntABuilding_OhPerfect, MSGBOX_NPC
	call Quest_HauntABuilding_AllPokemonCheck_Script
	compare VAR_TEMP_0, 6
	goto_if_eq Quest_HauntABuilding_TakePokemon_Dialogue_2
Quest_HauntABuilding_TakePokemon_Dialogue_1:
	release
	end

Quest_HauntABuilding_TakePokemon_Dialogue_2:
	goto Quest_HauntABuilding_AllPokemon_Dialogue
	goto Quest_HauntABuilding_TakePokemon_Dialogue_1


Quest_HauntABuilding_AllPokemonCheck_Script::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_AllPokemonCheck_Script_2
Quest_HauntABuilding_AllPokemonCheck_Script_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_AllPokemonCheck_Script_5
Quest_HauntABuilding_AllPokemonCheck_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_AllPokemonCheck_Script_8
Quest_HauntABuilding_AllPokemonCheck_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_AllPokemonCheck_Script_11
Quest_HauntABuilding_AllPokemonCheck_Script_10:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_AllPokemonCheck_Script_14
Quest_HauntABuilding_AllPokemonCheck_Script_13:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING, SUB_QUEST_6
	compare VAR_RESULT, 0
	goto_if_ne Quest_HauntABuilding_AllPokemonCheck_Script_16
	return

Quest_HauntABuilding_AllPokemonCheck_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_HauntABuilding_AllPokemonCheck_Script_1

Quest_HauntABuilding_AllPokemonCheck_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_HauntABuilding_AllPokemonCheck_Script_4

Quest_HauntABuilding_AllPokemonCheck_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_HauntABuilding_AllPokemonCheck_Script_7

Quest_HauntABuilding_AllPokemonCheck_Script_11:
	addvar VAR_TEMP_0, 1
	goto Quest_HauntABuilding_AllPokemonCheck_Script_10

Quest_HauntABuilding_AllPokemonCheck_Script_14:
	addvar VAR_TEMP_0, 1
	goto Quest_HauntABuilding_AllPokemonCheck_Script_13

Quest_HauntABuilding_AllPokemonCheck_Script_16:
	addvar VAR_TEMP_0, 1
	return


Quest_HauntABuilding_NoPokemon_Dialogue::
	msgbox gText_HauntABuilding_NothingYet, MSGBOX_NPC
	end


Quest_HauntABuilding_LastPokemon_Dialogue::
	msgbox gText_HauntABuilding_YouCantGiveMe, MSGBOX_NPC
	end


Quest_HauntABuilding_AllPokemon_Dialogue::
	msgbox gText_HauntABuilding_OhIThinkWereReady, MSGBOX_NPC
	goto Quest_HauntABuilding_ScareCutscene_Script
	return


Quest_HauntABuilding_ScareCutscene_Script::
	clearflag FLAG_TEMP_1
	playse SE_EXIT
	addobject 2
	applymovement 1, Common_Movement_FaceLeft
	applymovement 2, HauntABuilding_WalkToPair_Movement
	waitmovement 0
	msgbox gText_HauntABuilding_OkayImHere, MSGBOX_DEFAULT
	closemessage
	playmoncry SPECIES_GENGAR, CRY_MODE_ENCOUNTER
	waitmoncry
	playbgm MUS_MT_PYRE, TRUE
	msgbox gText_HauntABuilding_WhatWasThat, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_BLACK, 0
	call Quest_HauntABuilding_MoveDeveloper_Script
	fadescreenspeed FADE_FROM_BLACK, 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_HauntABuilding_HowDidI, MSGBOX_DEFAULT
	closemessage
	fadescreenspeed FADE_TO_BLACK, 0
	playmoncry SPECIES_TREVENANT, CRY_MODE_ENCOUNTER
	waitmoncry
	call Quest_HauntABuilding_MakeGhostsVisibleA_Script
	fadescreenspeed FADE_FROM_BLACK, 0
	playse SE_PIN
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_HauntABuilding_ImOuttaHere, MSGBOX_DEFAULT
	closemessage
	applymovement 2, HauntABuilding_Flee_Movement
	waitmovement 0
	playse SE_EXIT
	removeobject 2
	fadescreenspeed FADE_TO_BLACK, 0
	call Quest_HauntABuilding_HideObject_Script
	fadescreenspeed FADE_FROM_BLACK, 0
	goto Quest_HauntABuilding_ThankPlayer_Dialogue
	return


Quest_HauntABuilding_MoveDeveloper_Script::
	setobjectxy 2, 4, 4
	applymovement 2, Common_Movement_FaceUp
	waitmovement 2
	applymovement 1, Common_Movement_FaceUp
	waitmovement 2
	return


Quest_HauntABuilding_MakeGhostsVisibleA_Script::
	clearflag FLAG_TEMP_3
	addobject 3
	addobject 4
	addobject 5
	return


Quest_HauntABuilding_ThankPlayer_Dialogue::
	fadedefaultbgm
	msgbox gText_HauntABuilding_ItWorked, MSGBOX_NPC
	call Quest_HauntABuilding_GiveReward_Script
	msgbox gText_HauntABuilding_ImGoingToCelebrate, MSGBOX_NPC
	closemessage
	applymovement 1, HauntABuilding_LeaveHouse_Movement
	waitmovement 0
	playse SE_EXIT
	removeobject 1
	release
	end


Quest_HauntABuilding_GiveReward_Script::
	giveitem ITEM_TM38
	return


Quest_HauntABuilding_EndQuestCheck_Script::
	addvar VAR_TEMP_9, 1
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_HAUNTABUILDING
	compare VAR_RESULT, TRUE
	goto_if_eq Quest_HauntABuilding_EndQuestCheck_Script_2
	call Quest_HauntABuilding_AllPokemonCheck_Script
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_HAUNTABUILDING
	compare VAR_TEMP_0, 6
	goto_if_eq Quest_HauntABuilding_EndQuestCheck_Script_6
Quest_HauntABuilding_EndQuestCheck_Script_4:
	release
	end

Quest_HauntABuilding_EndQuestCheck_Script_2:
	release
	end

Quest_HauntABuilding_EndQuestCheck_Script_5:
	goto Quest_HauntABuilding_EndQuest_Dialogue
	goto Quest_HauntABuilding_EndQuestCheck_Script_4

Quest_HauntABuilding_EndQuestCheck_Script_6:
	compare VAR_TEMP_1, 26
	goto_if_eq Quest_HauntABuilding_EndQuestCheck_Script_8
	goto Quest_HauntABuilding_EndQuestCheck_Script_4

Quest_HauntABuilding_EndQuestCheck_Script_8:
	compare VAR_TEMP_2, 6
	goto_if_eq Quest_HauntABuilding_EndQuestCheck_Script_5
	goto Quest_HauntABuilding_EndQuestCheck_Script_4


Quest_HauntABuilding_EndQuest_Dialogue::
	playse SE_PIN
	applymovement 3, Common_Movement_ExclamationMark
	waitmovement 3
	applymovement 3, HauntABuilding_ApproachPlayer_Movement
	waitmovement 3
	lock
	msgbox gText_HauntABuilding_WhatWereYouDoing, MSGBOX_DEFAULT
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HauntABuilding_WhatDoYouMean, MSGBOX_DEFAULT
	callnative ClearMugshot
	msgbox gText_HauntABuilding_AFriend, MSGBOX_DEFAULT
	closemessage
	completequest QUEST_HAUNTABUILDING
	release
	end


HauntABuilding_WalkToPair_Movement:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

HauntABuilding_Flee_Movement:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	step_end

HauntABuilding_LeaveHouse_Movement:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	face_up
	delay_16
	step_end

HauntABuilding_ApproachPlayer_Movement:
	walk_right
	walk_right
	face_up
	step_end

Quest_HauntABuilding_TakePokemon_Script_Text_0:
	.string "okay taking the thingy now$"

gText_HauntABuilding_IDontKnow::
	.string "I don't know what to do...I can't let\n"
	.string "them have this!$"

gText_HauntABuilding_OhMaybeYou::
	.string "Oh! Maybe you can help me.$"

gText_HauntABuilding_IToldTheDeveloper::
	.string "I told the developer trying to convert\n"
	.string "this place into a mansion that I wasn't\l"
	.string "going to sell. But they keep coming\l"
	.string "back and harrassing me... so I finally\l"
	.string "told them the place was haunted. Now I\l"
	.string "need to convince them that its\l"
	.string "actually haunted!$"

gText_HauntABuilding_IWouldDoIt::
	.string "I'd do it, but I can't leave. It's weird\n"
	.string "and complicated, but I have to stay\l"
	.string "here.$"

gText_HauntABuilding_BringSomeScary::
	.string "Can you help me? Bring me some scary\n"
	.string "Pokémon. I think two Litwick, two\l"
	.string "Sinistea, a Chandelure, and a Trevanant\l"
	.string "should do the trick. Come back at\l"
	.string "night, okay?$"

gText_HauntABuilding_DoYouHaveAScary::
	.string "You're back! Do you have a scary\n"
	.string "Pokémon?$"

gText_HauntABuilding_OhPerfect::
	.string "Oh, perfect! This will work nicely.$"

gText_HauntABuilding_NothingYet::
	.string "Nothing yet? Okay. Make sure you come\n"
	.string "back at night!$"

gText_HauntABuilding_YouCantGiveMe::
	.string "You can't give me your last Pokémon!$"

gText_HauntABuilding_OhIThinkWereReady::
	.string "Oh! I've got all six now. I think we're\n"
	.string "ready!$"

gText_HauntABuilding_OkayImHere::
	.string "Okay, I'm here, at night, like you\n"
	.string "requested... and I don't see anything\l"
	.string "looking haunted. Are you ready to sell?$"

gText_HauntABuilding_WhatWasThat::
	.string "...what was that?$"

gText_HauntABuilding_HowDidI::
	.string "How did I get over here?$"

gText_HauntABuilding_ImOuttaHere::
	.string "I'm outta here! This IS haunted!$"

gText_HauntABuilding_ItWorked::
	.string "It worked! Thank you so much! Please\n"
	.string "take this reward.$"

gText_HauntABuilding_ImGoingToCelebrate::
	.string "You know, I wouldn't mind if the house\n"
	.string "was going to be built for people that\l"
	.string "needed it... but they were just going to\l"
	.string "put a stupid luxury condo here. We\l"
	.string "don't need more of these, you know? I'm\l"
	.string "going out to celebrate, this was great!\l"
	.string "See you around.$"

gText_HauntABuilding_WhatWereYouDoing::
	.string "I've seen you coming and going a few\n"
	.string "times and I'm just curious - why do ya\l"
	.string "keep going into the abandoned house?$"

gText_HauntABuilding_WhatDoYouMean::
	.string "What do you mean abandoned? I'm\n"
	.string "helping a friend!$"

gText_HauntABuilding_AFriend::
	.string "A friend? Nobody lived there for 50\n"
	.string "years since that Hunter kid died in\l"
	.string "there. Must be some crazy social media\l"
	.string "thing...$"
