Quest_Restoretreasureisland_HideCilan_Outside_Script::
	setvar VAR_TEMP_0, 0
	compare VAR_STORYLINE_STATE, STORY_ARCHER_EXPLAIN_RESTORATION
	goto_if_lt Quest_Restoretreasureisland_HideCilan_Outside_Script_2
Quest_Restoretreasureisland_HideCilan_Outside_Script_1:
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTOREMARIN
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_HideCilan_Outside_Script_5
Quest_Restoretreasureisland_HideCilan_Outside_Script_4:
	goto_if_set FLAG_TIMELINE_FALSE, Quest_Restoretreasureisland_HideCilan_Outside_Script_8
Quest_Restoretreasureisland_HideCilan_Outside_Script_7:
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_Restoretreasureisland_HideCilan_Outside_Script_11
Quest_Restoretreasureisland_HideCilan_Outside_Script_10:
	return

Quest_Restoretreasureisland_HideCilan_Outside_Script_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_HideCilan_Outside_Script_1

Quest_Restoretreasureisland_HideCilan_Outside_Script_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_HideCilan_Outside_Script_4

Quest_Restoretreasureisland_HideCilan_Outside_Script_8:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_HideCilan_Outside_Script_7

Quest_Restoretreasureisland_HideCilan_Outside_Script_11:
	setflag FLAG_TEMP_1
	goto Quest_Restoretreasureisland_HideCilan_Outside_Script_10


Quest_Restoretreasureisland_Interact_Script::
	lock
	faceplayer
	switch VAR_QUEST_RESTORETREASUREISLAND
	case RESTORETREASUREISLAND_NOT_STARTED, Quest_Restoretreasureisland_Interact_Script_2
	case SAVE_BEFORE_CILAN_BATTLE, Quest_Restoretreasureisland_Interact_Script_3
	case DEFEATED_CILAN, Quest_Restoretreasureisland_Interact_Script_4
	return

Quest_Restoretreasureisland_Interact_Script_2:
	goto Quest_Restoretreasureisland_Intro_Dialogue
	return

Quest_Restoretreasureisland_Interact_Script_3:
	goto Quest_Restoretreasureisland_StartBattle_Script
	return

Quest_Restoretreasureisland_Interact_Script_4:
	goto Quest_Restoretreasureisland_Active_Script
	return


Quest_Restoretreasureisland_Intro_Dialogue::
	lock
	setvar VAR_QUEST_RESTORETREASUREISLAND, SAVE_BEFORE_CILAN_BATTLE
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_ExpandedPlaceholder_Empty
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExpandedPlaceholder_Empty
	call Common_EventScript_SaveGame
	closemessage
	goto Quest_Restoretreasureisland_StartBattle_Script
	return


Quest_Restoretreasureisland_StartBattle_Script::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_ExpandedPlaceholder_Empty
	trainerbattle_no_intro TRAINER_CILAN_TREASUREISLAND, gText_ExpandedPlaceholder_Empty
	closemessage
	callnative ClearMugshot
	goto Quest_Restoretreasureisland_PostBattle_Dialogue
	return


Quest_Restoretreasureisland_PostBattle_Dialogue::
	setvar VAR_QUEST_RESTORETREASUREISLAND, DEFEATED_CILAN
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_ExpandedPlaceholder_Empty
	callnative ClearMugshot
	startquest QUEST_RESTORETREASUREISLAND
	return


Quest_Restoretreasureisland_Active_Script::
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_DoYouHave
	callnative ClearMugshot
	multichoice2 1, 1, Quest_Restoretreasureisland_CheckList, 0, 1, 0
	closemessage
	switch VAR_RESULT
	case 0, Quest_Restoretreasureisland_Active_Script_2
	case 1, Quest_Restoretreasureisland_Active_Script_3
	case 2, Quest_Restoretreasureisland_Active_Script_4
	case 3, Quest_Restoretreasureisland_Active_Script_5
	case 4, Quest_Restoretreasureisland_Active_Script_6
	case MULTI_B_PRESSED, Quest_Restoretreasureisland_Active_Script_6
	return

Quest_Restoretreasureisland_Active_Script_2:
	goto Quest_Restoretreasureisland_Handle_FlameOrb_Script
	return

Quest_Restoretreasureisland_Active_Script_3:
	goto Quest_Restoretreasureisland_Handle_TR27_Script
	return

Quest_Restoretreasureisland_Active_Script_4:
	goto Quest_Restoretreasureisland_Handle_PsychoShift_Script
	return

Quest_Restoretreasureisland_Active_Script_5:
	goto Quest_Restoretreasureisland_Handle_EffectSpore_Script
	return

Quest_Restoretreasureisland_Active_Script_6:
	goto Quest_Restoretreasureisland_Cancel_Dialogue
	return


Quest_Restoretreasureisland_Cancel_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_NothingWellThen, MSGBOX_NPC
	callnative ClearMugshot
	end


Quest_Restoretreasureisland_AlreadyDone_Script::
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_WaitYouAlready
	callnative ClearMugshot
	goto Quest_Restoretreasureisland_Active_Script
	return


Quest_Restoretreasureisland_ConfirmTake_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_HeyYouSure, MSGBOX_YESNO
	callnative ClearMugshot
	compare VAR_RESULT, NO
	goto_if_eq Quest_Restoretreasureisland_ConfirmTake_Dialogue_1
	msgbox gText_Restoretreasureisland_Thanks
	closemessage
	return

Quest_Restoretreasureisland_ConfirmTake_Dialogue_1:
	goto Quest_Restoretreasureisland_Cancel_Dialogue
	return


Quest_Restoretreasureisland_CheckSubquestProgress::
	setvar VAR_TEMP_0, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_CheckSubquestProgress_2
Quest_Restoretreasureisland_CheckSubquestProgress_1:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_CheckSubquestProgress_5
Quest_Restoretreasureisland_CheckSubquestProgress_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_CheckSubquestProgress_8
Quest_Restoretreasureisland_CheckSubquestProgress_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_CheckSubquestProgress_11
Quest_Restoretreasureisland_CheckSubquestProgress_10:
	compare VAR_TEMP_0, 4
	goto_if_eq Quest_Restoretreasureisland_CheckSubquestProgress_14
Quest_Restoretreasureisland_CheckSubquestProgress_13:
	return

Quest_Restoretreasureisland_CheckSubquestProgress_2:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_CheckSubquestProgress_1

Quest_Restoretreasureisland_CheckSubquestProgress_5:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_CheckSubquestProgress_4

Quest_Restoretreasureisland_CheckSubquestProgress_8:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_CheckSubquestProgress_7

Quest_Restoretreasureisland_CheckSubquestProgress_11:
	addvar VAR_TEMP_0, 1
	goto Quest_Restoretreasureisland_CheckSubquestProgress_10

Quest_Restoretreasureisland_CheckSubquestProgress_14:
	questmenu QUEST_MENU_SET_REWARD, QUEST_RESTORETREASUREISLAND
	goto Quest_Restoretreasureisland_CheckSubquestProgress_13


Quest_Restoretreasureisland_HandleProgress_Dialogue::
	call Quest_Restoretreasureisland_CheckSubquestProgress
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_RESTORETREASUREISLAND
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_HandleProgress_Dialogue_1
	goto Quest_Restoretreasureisland_Active_Script
	return

Quest_Restoretreasureisland_HandleProgress_Dialogue_1:
	goto Quest_Restoretreasureisland_Reward_Dialogue
	return


Quest_Restoretreasureisland_Handle_FlameOrb_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_Handle_FlameOrb_Script_2
Quest_Restoretreasureisland_Handle_FlameOrb_Script_1:
	bufferitemname STR_VAR_1, ITEM_FLAME_ORB
	bufferstring STR_VAR_2, Quest_Restoretreasureisland_Handle_FlameOrb_Script_Text_0
	checkitem ITEM_FLAME_ORB, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_Handle_FlameOrb_Script_4
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_YouDontHave
	callnative ClearMugshot
	goto Quest_Restoretreasureisland_Active_Script
	return

Quest_Restoretreasureisland_Handle_FlameOrb_Script_2:
	goto Quest_Restoretreasureisland_AlreadyDone_Script
	goto Quest_Restoretreasureisland_Handle_FlameOrb_Script_1

Quest_Restoretreasureisland_Handle_FlameOrb_Script_4:
	call Quest_Restoretreasureisland_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORETREASUREISLAND, SUB_QUEST_1
	removeitem ITEM_FLAME_ORB, 1
	goto Quest_Restoretreasureisland_HandleProgress_Dialogue
	return


Quest_Restoretreasureisland_Handle_TR27_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_Handle_TR27_Script_2
Quest_Restoretreasureisland_Handle_TR27_Script_1:
	bufferitemname STR_VAR_1, ITEM_TM27
	bufferstring STR_VAR_2, Quest_Restoretreasureisland_Handle_TR27_Script_Text_0
	checkitem ITEM_TM27, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_Handle_TR27_Script_4
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_YouDontHave
	callnative ClearMugshot
	goto Quest_Restoretreasureisland_Active_Script
	return

Quest_Restoretreasureisland_Handle_TR27_Script_2:
	goto Quest_Restoretreasureisland_AlreadyDone_Script
	goto Quest_Restoretreasureisland_Handle_TR27_Script_1

Quest_Restoretreasureisland_Handle_TR27_Script_4:
	call Quest_Restoretreasureisland_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORETREASUREISLAND, SUB_QUEST_2
	removeitem ITEM_TM27, 1
	goto Quest_Restoretreasureisland_HandleProgress_Dialogue
	return


Quest_Restoretreasureisland_Handle_PsychoShift_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_Handle_PsychoShift_Script_2
Quest_Restoretreasureisland_Handle_PsychoShift_Script_1:
	special ChoosePartyMon
	waitstate
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferstring STR_VAR_1, gText_PokemonPsychoShift
	bufferstring STR_VAR_2, Quest_Restoretreasureisland_Handle_PsychoShift_Script_Text_0
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq Quest_Restoretreasureisland_Handle_PsychoShift_Script_5
Quest_Restoretreasureisland_Handle_PsychoShift_Script_4:
	compare VAR_RESULT, SPECIES_BEHEEYEM
	goto_if_eq Quest_Restoretreasureisland_Handle_PsychoShift_Script_7
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_YouDontHave
	callnative ClearMugshot
	goto Quest_Restoretreasureisland_Active_Script
	return

Quest_Restoretreasureisland_Handle_PsychoShift_Script_2:
	goto Quest_Restoretreasureisland_AlreadyDone_Script
	goto Quest_Restoretreasureisland_Handle_PsychoShift_Script_1

Quest_Restoretreasureisland_Handle_PsychoShift_Script_5:
	goto Quest_Restoretreasureisland_Cancel_Dialogue
	goto Quest_Restoretreasureisland_Handle_PsychoShift_Script_4

Quest_Restoretreasureisland_Handle_PsychoShift_Script_7:
	special BufferMonNickname
	call Quest_Restoretreasureisland_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORETREASUREISLAND, SUB_QUEST_3
	goto Quest_Restoretreasureisland_HandleProgress_Dialogue
	return


Quest_Restoretreasureisland_Handle_EffectSpore_Script::
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_RESTORETREASUREISLAND, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_Restoretreasureisland_Handle_EffectSpore_Script_2
Quest_Restoretreasureisland_Handle_EffectSpore_Script_1:
	special ChoosePartyMon
	waitstate
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	bufferstring STR_VAR_1, gText_PokemonEffectSpore
	bufferstring STR_VAR_2, Quest_Restoretreasureisland_Handle_PsychoShift_Script_Text_0
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq Quest_Restoretreasureisland_Handle_EffectSpore_Script_5
Quest_Restoretreasureisland_Handle_EffectSpore_Script_4:
	compare VAR_RESULT, SPECIES_SHROOMISH
	goto_if_eq Quest_Restoretreasureisland_Handle_EffectSpore_Script_7
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_Restoretreasureisland_YouDontHave
	callnative ClearMugshot
	goto Quest_Restoretreasureisland_Active_Script
	return

Quest_Restoretreasureisland_Handle_EffectSpore_Script_2:
	goto Quest_Restoretreasureisland_AlreadyDone_Script
	goto Quest_Restoretreasureisland_Handle_EffectSpore_Script_1

Quest_Restoretreasureisland_Handle_EffectSpore_Script_5:
	goto Quest_Restoretreasureisland_Cancel_Dialogue
	goto Quest_Restoretreasureisland_Handle_EffectSpore_Script_4

Quest_Restoretreasureisland_Handle_EffectSpore_Script_7:
	special BufferMonNickname
	call Quest_Restoretreasureisland_ConfirmTake_Dialogue
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_RESTORETREASUREISLAND, SUB_QUEST_4
	goto Quest_Restoretreasureisland_HandleProgress_Dialogue
	return


Quest_Restoretreasureisland_Reward_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_CILAN
	callnative DrawMugshot
	msgbox gText_ExpandedPlaceholder_Empty
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ExpandedPlaceholder_Empty
	callnative ClearMugshot
	closemessage
	opendoor 5, 12
	waitdooranim
	applymovement 2, Common_Movement_WalkUp
	waitmovement 2
	removeobject 2
	playse SE_EXIT
	waitse
	closedoor 5, 12
	waitdooranim
	completequest QUEST_RESTORETREASUREISLAND
	call LetsGrabLunch_CheckRestorationProgress_Script
	release
	end


Quest_Restoretreasureisland_Handle_FlameOrb_Script_Text_0:
	.string "You don't have a $"

Quest_Restoretreasureisland_Handle_TR27_Script_Text_0:
	.string "You don't have a$"

Quest_Restoretreasureisland_Handle_PsychoShift_Script_Text_0:
	.string "That isn't $"

Quest_Restoretreasureisland_CheckList::
	.string "Flame Orb$"
	.string "TR27$"
	.string "Psycho Shift$"
	.string "Effect Spore$"
	.string "Nothing yet.$"
	.string "$"

gText_Restoretreasureisland_DoYouHave::
	.string "do you have any of the pieces?$"

gText_Restoretreasureisland_NothingWellThen::
	.string "nothing well then what are you doing\n"
	.string "here$"

gText_Restoretreasureisland_WaitYouAlready::
	.string "wait you already gave me one of those.$"

gText_Restoretreasureisland_HeyYouSure::
	.string "hey you sure you wanna give me your\n"
	.string "{STR_VAR_1}? i'm keeping it forever$"

gText_Restoretreasureisland_YouDontHave::
	.string "{STR_VAR_2}{STR_VAR_1}!$"

gText_Restoretreasureisland_Thanks::
	.string "thanks!$"