Quest_StolenTrade_HideObjectA_Script::
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_STOLENTRADE
	compare VAR_RESULT, 0
	goto_if_eq Quest_StolenTrade_HideObjectA_Script_1
	return

Quest_StolenTrade_HideObjectA_Script_1:
	setflag FLAG_TEMP_4
	return


Quest_StolenTrade_HideObjectB_Script::
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_STOLENTRADE
	compare VAR_RESULT, 0
	goto_if_ne Quest_StolenTrade_HideObjectB_Script_1
	return

Quest_StolenTrade_HideObjectB_Script_1:
	setflag FLAG_TEMP_3
	return


Quest_StolenTrade_Interact_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOLENTRADE
	compare VAR_RESULT, 0
	goto_if_ne Quest_StolenTrade_Interact_Script_2
Quest_StolenTrade_Interact_Script_1:
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_STOLENTRADE
	compare VAR_RESULT, 0
	goto_if_ne Quest_StolenTrade_Interact_Script_4
	call Quest_StolenTrade_AskForTrade_Dialogue
	return

Quest_StolenTrade_Interact_Script_2:
	goto Quest_StolenTrade_QuestComplete_Dialogue
	goto Quest_StolenTrade_Interact_Script_1

Quest_StolenTrade_Interact_Script_4:
	call Quest_StolenTrade_PostTrade_Dialogue
	return


Quest_StolenTrade_AskForTrade_Dialogue::
	lock
	givemon SPECIES_BAGON, 20, ITEM_NONE
	bufferspeciesname STR_VAR_1, SPECIES_SWIRLIX
	bufferspeciesname STR_VAR_2, SPECIES_GURDURR
	msgbox gText_StolenTrade_DoYouKnowHow, MSGBOX_NPC, SPEAKER_BRONSON
	msgbox gText_StolenTrade_YeahYouTrade, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_StolenTrade_ExactlyIWantTo, MSGBOX_NPC, SPEAKER_BRONSON
	msgbox gText_StolenTrade_WillYouTrade, MSGBOX_YESNO, SPEAKER_BRONSON
	compare VAR_RESULT, YES
	goto_if_eq Quest_StolenTrade_AskForTrade_Dialogue_1
	goto Quest_StoleTrade_NoTrade_Script
	return

Quest_StolenTrade_AskForTrade_Dialogue_1:
	goto Quest_StolenTrade_DoTrade_Script
	return


Quest_StoleTrade_NoTrade_Script::
	msgbox gText_StolenTrade_NoBigDeal, MSGBOX_NPC, SPEAKER_BRONSON
	release
	end


Quest_StolenTrade_DoTrade_Script::
	bufferspeciesname STR_VAR_1, SPECIES_SWIRLIX
	bufferspeciesname STR_VAR_2, SPECIES_GURDURR
	setvar VAR_0x8008, INGAME_TRADE_HORSEA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	compare VAR_0x800A, PARTY_NOTHING_CHOSEN
	goto_if_eq Quest_StolenTrade_DoTrade_Script_2
Quest_StolenTrade_DoTrade_Script_1:
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	compare VAR_RESULT, VAR_0x8009
	goto_if_ne Quest_StolenTrade_DoTrade_Script_5
Quest_StolenTrade_DoTrade_Script_4:
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	goto Quest_StolenTrade_RunAfterTrade_Script
	return

Quest_StolenTrade_DoTrade_Script_2:
	goto Quest_StoleTrade_NoTrade_Script
	goto Quest_StolenTrade_DoTrade_Script_1

Quest_StolenTrade_DoTrade_Script_5:
	goto Quest_StoleTrade_NoTrade_Script
	goto Quest_StolenTrade_DoTrade_Script_4


Quest_StolenTrade_RunAfterTrade_Script::
	bufferspeciesname STR_VAR_1, SPECIES_SWIRLIX
	bufferspeciesname STR_VAR_2, SPECIES_GURDURR
	msgbox gText_StolenTrade_GottaGo, MSGBOX_NPC, SPEAKER_BRONSON
	applymovement OBJ_EVENT_ID_PLAYER, Quest_StolenTrade_WatchRunAway_Movement
	applymovement 8, Quest_StolenTrade_RunAway_Movement
	waitmovement 0
	removeobject 8
	msgbox gText_StolenTrade_WaitWhat, MSGBOX_DEFAULT, SPEAKER_ZOEY
	startquest QUEST_STOLENTRADE
	release
	end


Quest_StolenTrade_PostTrade_Dialogue::
	lock
	bufferspeciesname STR_VAR_1, SPECIES_SLURPUFF
	bufferspeciesname STR_VAR_2, SPECIES_CONKELDURR
	msgbox gText_StolenTrade_GimmeBackMy, MSGBOX_NPC, SPEAKER_ZOEY
	closemessage
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox gText_StolenTrade_LookImSorryBut, MSGBOX_NPC, SPEAKER_BRONSON
	msgbox gText_StolenTrade_IDontWannaHear, MSGBOX_NPC, SPEAKER_ZOEY
	closemessage
	goto Quest_StolenTrade_StartBattle_Script
	return


Quest_StolenTrade_StartBattle_Script::
	lock
	msgbox gText_StolenTrade_ImKeepingThis, MSGBOX_DEFAULT, SPEAKER_BRONSON
	closemessage
	trainerbattle_no_intro TRAINER_STOLENTRADE_THIEF, gText_StolenTrade_YouDontUnderstand
	goto Quest_StolenTrade_PostBattle_Dialogue
	return


Quest_StolenTrade_PostBattle_Dialogue::
	lock
	bufferspeciesname STR_VAR_1, SPECIES_SLURPUFF
	bufferspeciesname STR_VAR_2, SPECIES_CONKELDURR
	msgbox gText_StolenTrade_GiveItBack, MSGBOX_NPC, SPEAKER_ZOEY
	closemessage
	msgbox gText_StolenTrade_OkayOkay, MSGBOX_NPC, SPEAKER_BRONSON
	givemon SPECIES_CONKELDURR, 40, ITEM_NONE
	completequest QUEST_STOLENTRADE
	release
	end


Quest_StolenTrade_QuestComplete_Dialogue::
	lock
	bufferspeciesname STR_VAR_1, SPECIES_SLURPUFF
	bufferspeciesname STR_VAR_2, SPECIES_CONKELDURR
	msgbox gText_StolenTrade_YoureNotTakingBack, MSGBOX_NPC, SPEAKER_ZOEY
	msgbox gText_StolenTrade_NoIJustCaught, MSGBOX_NPC, SPEAKER_BRONSON
	closemessage
	return


Quest_StolenTrade_WatchRunAway_Movement:
	delay_4
	face_right
	delay_4
	delay_4
	delay_4
	delay_4
	delay_4
	face_up
	delay_4
	delay_4
	step_end

Quest_StolenTrade_RunAway_Movement:
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

gText_StolenTrade_DoYouKnowHow::
	.string "Do you know how tradebacks work?$"

gText_StolenTrade_YeahYouTrade::
	.string "Yeah, you trade Pokémon and then\n"
	.string "immediately trade them back, right?$"

gText_StolenTrade_ExactlyIWantTo::
	.string "Exactly! I want to evolve my\n"
	.string "{STR_VAR_1}, which requires a trade.$"

gText_StolenTrade_WillYouTrade::
	.string "Do you have a {STR_VAR_2}? Will you\n"
	.string "trade it for my {STR_VAR_1}? We can\l"
	.string "trade right back afterwards.$"

gText_StolenTrade_GottaGo::
	.string "Okay, gotta go, bye!$"

gText_StolenTrade_WaitWhat::
	.string "Wait, what? Come back! My\n"
	.string "{STR_VAR_2}!$"

gText_StolenTrade_NoBigDeal::
	.string "No big deal. Let me know if you change\n"
	.string "your mind.$"

gText_StolenTrade_GimmeBackMy::
	.string "Gimme back my {STR_VAR_2}!$"

gText_StolenTrade_LookImSorryBut::
	.string "Look I'm sorry but I gotta -$"

gText_StolenTrade_IDontWannaHear::
	.string "I don't wanna hear it! You stole from me,\n"
	.string "and you're not getting away again.$"

gText_StolenTrade_ImKeepingThis::
	.string "...I'm keeping this {STR_VAR_2}!$"

gText_StolenTrade_YouDontUnderstand::
	.string "You don't understand! They're going to\n"
	.string "fire me!$"

gText_StolenTrade_GiveItBack::
	.string "Give it back! Now.$"

gText_StolenTrade_OkayOkay::
	.string "Okay okay...$"

gText_StolenTrade_YoureNotTakingBack::
	.string "You're not taking back your\n"
	.string "{STR_VAR_1}?$"

gText_StolenTrade_NoIJustCaught::
	.string "I just caught it to trade with sombody.\n"
	.string "The {STR_VAR_2} was to help me with\l"
	.string "construction. My boss is going to fire\l"
	.string "me unless I can double out work output\l"
	.string "in the next week, and I have bills to\l"
	.string "pay....$"
