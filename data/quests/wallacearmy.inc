Quest_WallaceArmy_HideObject_Script::
	setflag FLAG_TEMP_1
	return


Quest_WallaceArmy_SetMovementType_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_SetMovementType_Script_1
	return

Quest_WallaceArmy_SetMovementType_Script_1:
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	return


Quest_WallaceArmy_PreQuest_Dialogue::
	goto_if_set FLAG_IS_CHAMPION, Quest_WallaceArmy_PreQuest_Dialogue_2
	msgbox gText_WallaceArmy_WhatMakesThemThinkTheyCanTreat, MSGBOX_NPC
Quest_WallaceArmy_PreQuest_Dialogue_1:
	end

Quest_WallaceArmy_PreQuest_Dialogue_2:
	goto Quest_WallaceArmy_QuestStart_Dialogue
	goto Quest_WallaceArmy_PreQuest_Dialogue_1


Quest_WallaceArmy_CheckQuestState_Script::
	lock
	faceplayer
	returnqueststate QUEST_WALLACEARMY
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_WallaceArmy_CheckQuestState_Script_2
	case QUEST_MENU_COMPLETE_QUEST, Quest_WallaceArmy_CheckQuestState_Script_3
	goto Quest_WallaceArmy_PreQuest_Dialogue
	return

Quest_WallaceArmy_CheckQuestState_Script_2:
	goto Quest_WallaceArmy_Active_Dialogue
	return

Quest_WallaceArmy_CheckQuestState_Script_3:
	goto Quest_WallaceArmy_CompleteDialogue
	return


Quest_WallaceArmy_QuestStart_Dialogue::
	msgbox gText_WallaceArmy_TheseKidsAreGonnaRuin
	msgbox gText_WallaceArmy_FirstTheBidNowTheDamnKids
	msgbox gText_WallaceArmy_OhTheChampionJustWhat
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WallaceArmy_TheLeagueDidntSend
	callnative ClearMugshot
	msgbox gText_WallaceArmy_SighWereMarinSolar
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WallaceArmy_YouThinkTheLeague
	callnative ClearMugshot
	msgbox gText_WallaceArmy_LookIHaveNoIdea
	startquest QUEST_WALLACEARMY
	return


Quest_WallaceArmy_Active_Dialogue::
	call Quest_WallaceArmy_CheckCompletionRate_Script
	call Quest_WallaceArmy_ListRemainingLocations_Script
	lock
	msgbox gText_WallaceArmy_LooksLikeThereStill
	end


Quest_WallaceArmy_PreBattleStan_Script::
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_PreBattleStan_Script_2
	closemessage
	return

Quest_WallaceArmy_PreBattleStan_Script_2:
	release
	end


Quest_WallaceArmy_LoadStanSpeech_Script::
	random 4
	switch VAR_RESULT
	case 0, Quest_WallaceArmy_LoadStanSpeech_Script_3
	case 1, Quest_WallaceArmy_LoadStanSpeech_Script_4
	case 2, Quest_WallaceArmy_LoadStanSpeech_Script_5
	case 3, Quest_WallaceArmy_LoadStanSpeech_Script_6
	case 4, Quest_WallaceArmy_LoadStanSpeech_Script_7
Quest_WallaceArmy_LoadStanSpeech_Script_1:
	return

Quest_WallaceArmy_LoadStanSpeech_Script_3:
	bufferstring STR_VAR_1, gText_Beauty3
	bufferspeciesname STR_VAR_2, SPECIES_MILOTIC
	goto Quest_WallaceArmy_LoadStanSpeech_Script_1

Quest_WallaceArmy_LoadStanSpeech_Script_4:
	bufferstring STR_VAR_1, gText_Coolness
	bufferspeciesname STR_VAR_2, SPECIES_GYARADOS
	goto Quest_WallaceArmy_LoadStanSpeech_Script_1

Quest_WallaceArmy_LoadStanSpeech_Script_5:
	bufferstring STR_VAR_1, gText_Cuteness
	bufferspeciesname STR_VAR_2, SPECIES_LUDICOLO
	goto Quest_WallaceArmy_LoadStanSpeech_Script_1

Quest_WallaceArmy_LoadStanSpeech_Script_6:
	bufferstring STR_VAR_1, gText_Smartness
	bufferspeciesname STR_VAR_2, SPECIES_WHISCASH
	goto Quest_WallaceArmy_LoadStanSpeech_Script_1

Quest_WallaceArmy_LoadStanSpeech_Script_7:
	bufferstring STR_VAR_1, gText_Toughness
	bufferspeciesname STR_VAR_2, SPECIES_WAILORD
	goto Quest_WallaceArmy_LoadStanSpeech_Script_1


Quest_WallaceArmy_Reward_Cutscene::
	setvar VAR_TEMP_0, 1
	questmenu QUEST_MENU_CHECK_REWARD, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Quest_WallaceArmy_Reward_Cutscene_2
	applymovement 1, Quest_WallaceArmy_ExclaimAndWalkToPlayer_Movement
	waitmovement 1
	msgbox gText_WallaceArmy_WereBackUp
	msgbox gText_WallaceArmy_TheStanArmyWillNeverDie
	closemessage
	call Quest_WallaceArmy_LeadStanAppearance_Script
	applymovement OBJ_EVENT_ID_PLAYER, Quest_WallaceArmy_ExclaimAndFaceNorth_Movement
	applymovement 1, Quest_WallaceArmy_ExclaimAndFaceNorth_Movement
	waitmovement 1
	msgbox gText_WallaceArmy_HowDidYouGetInHere
	msgbox gText_WallaceArmy_WhatIsThatMusic
	msgbox gText_WallaceArmy_OurArmyWillAlwaysPrevail
	closemessage
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	msgbox gText_WallaceArmy_ImLeahLeaderOfTheStanArmy
	msgbox gText_WallaceArmy_WaitYoureTheLeader
	msgbox gText_WallaceArmy_CanItOldMan
	msgbox gText_WallaceArmy_AndYouAttackingTheArmy
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	goto Quest_WallaceArmy_StartBattle_Script
	return

Quest_WallaceArmy_Reward_Cutscene_2:
	release
	end


Quest_WallaceArmy_StartBattle_Script::
	msgbox gText_WallaceArmy_ACrimePunishableByDeath
	trainerbattle_no_intro TRAINER_CHIP, gText_WallaceArmy_MyLord
	closemessage
	goto Quest_WallaceArmy_PostBattle_Script
	return


Quest_WallaceArmy_PostBattle_Script::
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	msgbox gText_WallaceArmy_WhyAreYouDefending
	msgbox gText_WallaceArmy_WeReallyHadNothing
	closemessage
	fadescreen FADE_TO_BLACK
	fadedefaultbgm
	delay 32
	call Quest_WallaceArmy_MoveAllObjects_Script
	fadescreen FADE_FROM_BLACK
	msgbox gText_WallaceArmy_ThatsTheWholeStorySee
	msgbox gText_WallaceArmy_ThereWasNoWallaceAtAll
	msgbox gText_WallaceArmy_IStillDontKnowWhoThatIs
	closemessage
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	msgbox gText_WallaceArmy_ImSorryForAttacking
	closemessage
	giveitem ITEM_LIFE_ORB, 1
	waitmessage
	applymovement 3, Quest_WallaceArmy_WalkOut_Movement
	waitmovement 3
	playse SE_EXIT
	waitse
	removeobject 3
	applymovement 1, Common_Movement_FaceUp
	waitmovement 1
	completequest QUEST_WALLACEARMY
	release
	end


Quest_WallaceArmy_CompleteDialogue::
	msgbox gText_WallaceArmy_ThankYouForStopping, MSGBOX_NPC
	end


Quest_WallaceArmy_MoveAllObjects_Script::
	setobjectxy 1, 2, 4
	setobjectxyperm 1, 2, 4
	setobjectxy 3, 1, 4
	setobjectxyperm 3, 1, 4
	applymovement 3, Common_Movement_FaceUp
	waitmovement 3
	setobjectxy OBJ_EVENT_ID_PLAYER, 1, 6
	TeleportCamera 1, 6
	return


Quest_WallaceArmy_LeadStanAppearance_Script::
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	addobject 3
	delay 16
	playse SE_EXIT
	waitse
	playbgm MUS_ENCOUNTER_CHAMPION, TRUE
	fadescreen FADE_FROM_BLACK
	return


Quest_WallaceArmy_ListRemainingLocations_Script::
	compare VAR_TEMP_1, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_2
Quest_WallaceArmy_ListRemainingLocations_Script_1:
	compare VAR_TEMP_2, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_5
Quest_WallaceArmy_ListRemainingLocations_Script_4:
	compare VAR_TEMP_3, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_8
Quest_WallaceArmy_ListRemainingLocations_Script_7:
	compare VAR_TEMP_4, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_11
Quest_WallaceArmy_ListRemainingLocations_Script_10:
	compare VAR_TEMP_5, 0
	goto_if_eq Quest_WallaceArmy_ListRemainingLocations_Script_14
Quest_WallaceArmy_ListRemainingLocations_Script_13:
	return

Quest_WallaceArmy_ListRemainingLocations_Script_2:
	bufferstring STR_VAR_1, gText_Alameda
	goto Quest_WallaceArmy_ListRemainingLocations_Script_1

Quest_WallaceArmy_ListRemainingLocations_Script_5:
	bufferstring STR_VAR_2, gText_Haightashbury
	goto Quest_WallaceArmy_ListRemainingLocations_Script_4

Quest_WallaceArmy_ListRemainingLocations_Script_8:
	bufferstring STR_VAR_3, gText_SOMA
	goto Quest_WallaceArmy_ListRemainingLocations_Script_7

Quest_WallaceArmy_ListRemainingLocations_Script_11:
	bufferstring STR_VAR_3, gText_Berkeley
	goto Quest_WallaceArmy_ListRemainingLocations_Script_10

Quest_WallaceArmy_ListRemainingLocations_Script_14:
	bufferstring STR_VAR_3, gText_Marin
	goto Quest_WallaceArmy_ListRemainingLocations_Script_13


Quest_WallaceArmy_CheckCompletionRate_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Quest_WallaceArmy_CheckCompletionRate_Script_2
	setvar VAR_TEMP_0, 0
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	setvar VAR_TEMP_3, 0
	setvar VAR_TEMP_4, 0
	setvar VAR_TEMP_5, 0
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_1
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_5
Quest_WallaceArmy_CheckCompletionRate_Script_4:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_2
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_8
Quest_WallaceArmy_CheckCompletionRate_Script_7:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_3
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_11
Quest_WallaceArmy_CheckCompletionRate_Script_10:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_4
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_14
Quest_WallaceArmy_CheckCompletionRate_Script_13:
	subquestmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY, SUB_QUEST_5
	compare VAR_RESULT, 0
	goto_if_ne Quest_WallaceArmy_CheckCompletionRate_Script_17
Quest_WallaceArmy_CheckCompletionRate_Script_16:
	compare VAR_TEMP_0, 5
	goto_if_eq Quest_WallaceArmy_CheckCompletionRate_Script_19
	return

Quest_WallaceArmy_CheckCompletionRate_Script_2:
	return

Quest_WallaceArmy_CheckCompletionRate_Script_5:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_1, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_4

Quest_WallaceArmy_CheckCompletionRate_Script_8:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_2, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_7

Quest_WallaceArmy_CheckCompletionRate_Script_11:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_3, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_10

Quest_WallaceArmy_CheckCompletionRate_Script_14:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_4, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_13

Quest_WallaceArmy_CheckCompletionRate_Script_17:
	addvar VAR_TEMP_0, 1
	addvar VAR_TEMP_5, 1
	goto Quest_WallaceArmy_CheckCompletionRate_Script_16

Quest_WallaceArmy_CheckCompletionRate_Script_19:
	questmenu QUEST_MENU_SET_REWARD, QUEST_WALLACEARMY
	return


Quest_WallaceArmy_ExclaimAndWalkToPlayer_Movement:
	emote_exclamation_mark
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	step_end

Quest_WallaceArmy_ExclaimAndFaceNorth_Movement:
	emote_exclamation_mark
	face_up
	step_end

Quest_WallaceArmy_WalkOut_Movement:
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

gText_WallaceArmy_WhatMakesThemThinkTheyCanTreat::
	.string "What makes them think they can treat\n"
	.string "us like this? You can't just back out\l"
	.string "like that...$"

gText_WallaceArmy_TheseKidsAreGonnaRuin::
	.string "These kids are gonna ruin my business!\n"
	.string "First the League, now this?$"

gText_WallaceArmy_FirstTheBidNowTheDamnKids::
	.string "First the bid goes tits up, and now some\n"
	.string "kids are going take my business apart...$"

gText_WallaceArmy_OhTheChampionJustWhat::
	.string "Oh, the Champion. Just what else does\n"
	.string "the League want to do now?!?$"

gText_WallaceArmy_TheLeagueDidntSend::
	.string "The League didn't send me! Why did you\n"
	.string "think so?$"

gText_WallaceArmy_SighWereMarinSolar::
	.string "*sigh* We're Marin Solar. We were working\n"
	.string "with the League to provide solar power\l"
	.string "for their fancy new statement. They\l"
	.string "had it all buttoned up, they signed a\l"
	.string "deal, and then a lawyer pulled a fast\l"
	.string "one and pulled out of the deal right\l"
	.string "after I got the materials and staff\l"
	.string "together. They said some shit about a\l"
	.string "better option. But I'm absolutely\l"
	.string "screwed! So I went online and wrote a\l"
	.string "nasty post about them... and the next\l"
	.string "thing I know, some kids called the\l"
	.string "'Wallace Army' are blowing up my phone,\l"
	.string "leaving bad reviews, and attacking my\l"
	.string "servers. We can't even get online! The\l"
	.string "League sent them!$"

gText_WallaceArmy_YouThinkTheLeague::
	.string "...You think the League sent Wallace\n"
	.string "stans after you?$"

gText_WallaceArmy_LookIHaveNoIdea::
	.string "Look, I don't even know what a stan is,\n"
	.string "but I do know that I haven't been able\l"
	.string "to log into all morning. I can't get any\l"
	.string "work done like this! My newphew is a\l"
	.string "computer guy and he told me the\l"
	.string "attacks are coming from specific spots\l"
	.string "in the region... but I don't even know\l"
	.string "where to start!$"

gText_WallaceArmy_LooksLikeThereStill::
	.string "According to my nephew, there are\n"
	.string "attacks from Alameda, Haightashbury,\l"
	.string "SOMA, Berkeley, and Marin.$"

gText_WallaceArmy_WereBackUp::
	.string "We're back up! I don't know what you\n"
	.string "did,but I can access my systems again!$"

gText_WallaceArmy_TheStanArmyWillNeverDie::
	.string "The Wallace Army will never die!$"

gText_WallaceArmy_HowDidYouGetInHere::
	.string "How did you get in here?$"

gText_WallaceArmy_WhatIsThatMusic::
	.string "...what is that music?$"

gText_WallaceArmy_OurArmyWillAlwaysPrevail::
	.string "Our Army will always prevail!$"

gText_WallaceArmy_ImLeahLeaderOfTheStanArmy::
	.string "I'm Leah, and I'm the Leader of the\n"
	.string "Wallace Army!$"

gText_WallaceArmy_WaitYoureTheLeader::
	.string "Wait, you're the leader? You?$"

gText_WallaceArmy_CanItOldMan::
	.string "Can it, old man.$"

gText_WallaceArmy_AndYouAttackingTheArmy::
	.string "And you! Champion {PLAYER},\n"
	.string "attacking the army?$"

gText_WallaceArmy_ACrimePunishableByDeath::
	.string "A crime punishable by death!$"

gText_WallaceArmy_MyLord::
	.string "My Lord...$"

gText_WallaceArmy_WhyAreYouDefending::
	.string "Why are you defending them anyways?\n"
	.string "You're young! Don't you understand the\l"
	.string "might of Wallace!$"

gText_WallaceArmy_WeReallyHadNothing::
	.string "We really had nothing to do with this\n"
	.string "Wallace thing, I swear.$"

gText_WallaceArmy_ThatsTheWholeStorySee::
	.string "That's the whole story, see? Those are\n"
	.string "all the messages. I didn't know\l"
	.string "anything about Wallace or anything.$"

gText_WallaceArmy_ThereWasNoWallaceAtAll::
	.string "...there was no Wallace at all.$"

gText_WallaceArmy_IStillDontKnowWhoThatIs::
	.string "I still don't know who that is.$"

gText_WallaceArmy_ImSorryForAttacking::
	.string "I'm sorry for mobilizing the Army. We will\n"
	.string "now retreat. Take this as an apology.$"

gText_WallaceArmy_ThankYouForStopping::
	.string "Thank you for stopping them! Now... can\n"
	.string "somebody explain who Wallace is?$"

gText_WallaceArmy_OhWallaceSama::
	.string "Oh Wallace-sama... so dreamy! The\n"
	.string "{STR_VAR_1}of his\l"
	.string "{STR_VAR_2}...oh! I can't get\l"
	.string "enough.$"

gText_WallaceArmy_MarinSolarTheySpoke::
	.string "Marin Solar? They spoke against our\n"
	.string "Lord, so we're taking them down!\l"
	.string "Anybody who gets in our way... is\l"
	.string "getting taken out!$"

gText_WallaceArmy_YouDidntHear::
	.string "You didn't hear? After Marin Solar heard\n"
	.string "that Wallace was going to perform at\l"
	.string "the Chase Center, they said refused to\l"
	.string "power a stadium that was hiring\l"
	.string "'tasteless hacks'. How dare they?!$"

gText_WallaceArmy_PostBattlePlaceholder1::
	.string "PostBattlePlaceholder1$"

gText_WallaceArmy_PostQuestPlaceholder1::
	.string "PostQuestPlaceholder1$"

gText_WallaceArmy_PostBattlePlaceholder2::
	.string "PostBattlePlaceholder2$"

gText_WallaceArmy_PostQuestPlaceholder2::
	.string "PostQuestPlaceholder2$"

gText_WallaceArmy_PostBattlePlaceholder3::
	.string "PostBattlePlaceholder3$"

gText_WallaceArmy_PostQuestPlaceholder3::
	.string "PostQuestPlaceholder3$"

gText_WallaceArmy_PostBattlePlaceholder4::
	.string "PostBattlePlaceholder4$"

gText_WallaceArmy_PostQuestPlaceholder4::
	.string "PostQuestPlaceholder4$"

gText_WallaceArmy_PostBattlePlaceholder5::
	.string "PostBattlePlaceholder5$"

gText_WallaceArmy_PostQuestPlaceholder5::
	.string "PostQuestPlaceholder5$"
