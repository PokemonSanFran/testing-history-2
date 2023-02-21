ThereCanOnlyBeOne_LoadFromSave_Script::
	goto_if_set FLAG_SYS_POKEMON_GET, ThereCanOnlyBeOne_LoadFromSave_Script_1
	compare VAR_STARTER_MON, 0
	goto_if_ne ThereCanOnlyBeOne_LoadFromSave_Script_2
	goto ThereCanOnlyBeOne_PlayerMonologue
	return

ThereCanOnlyBeOne_LoadFromSave_Script_1:
	goto ThereCanOnlyBeOne_WarpPlayer_Script
	return

ThereCanOnlyBeOne_LoadFromSave_Script_2:
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script
	return


ThereCanOnlyBeOne_PlayerMonologue::
	lock
	msgbox gText_ThereCanOnlyBe_AlmostPackedAndReady, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_TALK, EMOTE_HAPPY, PHONE_OFF
	msgbox gText_ThereCanOnlyBe_ButTheRulesSay, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_TALK, EMOTE_SAD, PHONE_OFF
	goto ThereCanOnlyBeOne_Narrator_Dialogue
	return


ThereCanOnlyBeOne_Debug_Script::
	givecustommon SPECIES_GRENINJA, 100, ITEM_LEFTOVERS, ITEM_LURE_BALL, NATURE_MODEST, 2, 0, 0, 4, 252, 0, 252, 31, 31, 31, 31, 31, 31, MOVE_SURF, MOVE_CALM_MIND, MOVE_SPLASH, MOVE_ICE_BEAM
	givecustommon SPECIES_PANGORO, 100, ITEM_EXPERT_BELT, ITEM_DREAM_BALL, NATURE_ADAMANT, 2, 0, 252, 0, 252, 0, 4, 31, 31, 31, 31, 31, 31, MOVE_DRAIN_PUNCH, MOVE_DIG, MOVE_SUPERPOWER, MOVE_SPLASH
	setflag FLAG_SYS_B_DASH
	return


ThereCanOnlyBeOne_Narrator_Dialogue::
	call ThereCanOnlyBeOne_Debug_Script
	msgbox gText_ThereCanOnlyBe_DueToTheDelicateEcosystem
	closemessage
	setvar VAR_STARTER_MON, 9
	call Common_EventScript_SaveGame
	closemessage
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script
	return


ThereCanOnlyBeOne_StarterSelectMenu_Script::
	msgbox gText_ThereCanOnlyBe_PleaseChooseAPokemon
	closemessage
	multichoice2 0, 0, ThereCanOnlyBeOne_StarterList, 1, 1, 0
	switch VAR_RESULT
	case 0, ThereCanOnlyBeOne_StarterSelectMenu_Script_3
	case 1, ThereCanOnlyBeOne_StarterSelectMenu_Script_4
	case 2, ThereCanOnlyBeOne_StarterSelectMenu_Script_5
	case 3, ThereCanOnlyBeOne_StarterSelectMenu_Script_6
	case 4, ThereCanOnlyBeOne_StarterSelectMenu_Script_7
	case 5, ThereCanOnlyBeOne_StarterSelectMenu_Script_8
	case 6, ThereCanOnlyBeOne_StarterSelectMenu_Script_9
	case 7, ThereCanOnlyBeOne_StarterSelectMenu_Script_10
	case 8, ThereCanOnlyBeOne_StarterSelectMenu_Script_11
ThereCanOnlyBeOne_StarterSelectMenu_Script_1:
	goto ThereCanOnlyBeOne_StarterChoiceMenu_Script
	return

ThereCanOnlyBeOne_StarterSelectMenu_Script_3:
	setvar VAR_STARTER_MON, 0
	bufferspeciesname 0, SPECIES_SCYTHER
	msgbox gText_ThereCanOnlyBe_StarterSelectScytherDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_4:
	setvar VAR_STARTER_MON, 1
	bufferspeciesname 0, SPECIES_CHARMANDER
	msgbox gText_ThereCanOnlyBe_StarterSelectCharcadetDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_5:
	setvar VAR_STARTER_MON, 2
	bufferspeciesname 0, SPECIES_PETILIL
	msgbox gText_ThereCanOnlyBe_StarterSelectCharcadetDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_6:
	setvar VAR_STARTER_MON, 3
	bufferspeciesname 0, SPECIES_FLAAFFY
	msgbox gText_ThereCanOnlyBe_StarterSelectFlaaffyDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_7:
	setvar VAR_STARTER_MON, 4
	bufferspeciesname 0, SPECIES_MAREANIE
	msgbox gText_ThereCanOnlyBe_StarterSelectMareanieDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_8:
	setvar VAR_STARTER_MON, 5
	bufferspeciesname 0, SPECIES_ARON
	msgbox gText_ThereCanOnlyBe_StarterSelectAronDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_9:
	setvar VAR_STARTER_MON, 6
	bufferspeciesname 0, SPECIES_SWINUB
	msgbox gText_ThereCanOnlyBe_StarterSelectSwinubDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_10:
	setvar VAR_STARTER_MON, 7
	bufferspeciesname 0, SPECIES_HATTREM
	msgbox gText_ThereCanOnlyBe_StarterSelectHattremDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1

ThereCanOnlyBeOne_StarterSelectMenu_Script_11:
	setvar VAR_STARTER_MON, 8
	bufferspeciesname 0, SPECIES_PANCHAM
	msgbox gText_ThereCanOnlyBe_StarterSelectPanchamDesc
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script_1


ThereCanOnlyBeOne_StarterChoiceMenu_Script::
	multichoice 50, 6, MULTI_STARTER_SUMMARY, TRUE
	switch VAR_RESULT
	case 0, ThereCanOnlyBeOne_StarterChoiceMenu_Script_2
	case 1, ThereCanOnlyBeOne_StarterChoiceMenu_Script_3
	case 2, ThereCanOnlyBeOne_StarterChoiceMenu_Script_4
	return

ThereCanOnlyBeOne_StarterChoiceMenu_Script_2:
	msgbox gText_ThereCanOnlyBe_StarterSelectSummaryErrorMessage
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script
	return

ThereCanOnlyBeOne_StarterChoiceMenu_Script_3:
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script
	return

ThereCanOnlyBeOne_StarterChoiceMenu_Script_4:
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script
	return


ThereCanOnlyBeOne_StarterSelectConfirm_Script::
	msgbox gText_ThereCanOnlyBe_StarterAreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ThereCanOnlyBeOne_StarterSelectConfirm_Script_1
	switch VAR_STARTER_MON
	case 0, ThereCanOnlyBeOne_StarterSelectConfirm_Script_6
	case 1, ThereCanOnlyBeOne_StarterSelectConfirm_Script_7
	case 2, ThereCanOnlyBeOne_StarterSelectConfirm_Script_8
	case 3, ThereCanOnlyBeOne_StarterSelectConfirm_Script_9
	case 4, ThereCanOnlyBeOne_StarterSelectConfirm_Script_10
	case 5, ThereCanOnlyBeOne_StarterSelectConfirm_Script_11
	case 6, ThereCanOnlyBeOne_StarterSelectConfirm_Script_12
	case 7, ThereCanOnlyBeOne_StarterSelectConfirm_Script_13
	case 8, ThereCanOnlyBeOne_StarterSelectConfirm_Script_14
ThereCanOnlyBeOne_StarterSelectConfirm_Script_4:
	goto ThereCanOnlyBeOne_StarterSelectEnd_Script
	return

ThereCanOnlyBeOne_StarterSelectConfirm_Script_1:
	goto ThereCanOnlyBeOne_StarterSelectMenu_Script
	return

ThereCanOnlyBeOne_StarterSelectConfirm_Script_6:
	givecustommon SPECIES_SCYTHER, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	bufferspeciesname 0, SPECIES_SCYTHER
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_7:
	givecustommon SPECIES_CHARMANDER, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	bufferspeciesname 0, SPECIES_CHARMANDER
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_8:
	givecustommon SPECIES_PETILIL, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	bufferspeciesname 0, SPECIES_PETILIL
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_9:
	givecustommon SPECIES_FLAAFFY, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	bufferspeciesname 0, SPECIES_FLAAFFY
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_10:
	givecustommon SPECIES_MAREANIE, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	bufferspeciesname 0, SPECIES_MAREANIE
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_11:
	givecustommon SPECIES_ARON, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	bufferspeciesname 0, SPECIES_ARON
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_12:
	givecustommon SPECIES_SWINUB, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	bufferspeciesname 0, SPECIES_SWINUB
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_13:
	givecustommon SPECIES_HATTREM, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	bufferspeciesname 0, SPECIES_HATTREM
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4

ThereCanOnlyBeOne_StarterSelectConfirm_Script_14:
	givecustommon SPECIES_PANCHAM, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	bufferspeciesname 0, SPECIES_PANCHAM
	goto ThereCanOnlyBeOne_StarterSelectConfirm_Script_4


ThereCanOnlyBeOne_StarterSelectEnd_Script::
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_ThereCanOnlyBe_YouChoseToBring
	waitfanfare
	call Common_EventScript_SaveGame
	closemessage
	goto ThereCanOnlyBeOne_WarpPlayer_Script
	return


ThereCanOnlyBeOne_WarpPlayer_Script::
	lock
	clearflag FLAG_SPAWN_INVISIBLE
	warpsilent MAP_SOUTHBAY, 255, 3, 10
	return


ThereCanOnlyBeOne_StarterList::
	.string "Scyther$"
	.string "Charcadet$"
	.string "Petilil$"
	.string "Flaaffy$"
	.string "Mareanie$"
	.string "Aron$"
	.string "Swinub$"
	.string "Hattrem$"
	.string "Pancham$"
	.string "$"

gText_ThereCanOnlyBe_AlmostPackedAndReady::
	.string "Almost packed and ready to go! I still\n"
	.string "can't believe I made it...$"

gText_ThereCanOnlyBe_ButTheRulesSay::
	.string "But the rules say I can only bring one\n"
	.string "of you guys. Man, this sucks. I promise,\l"
	.string "once we're the Champion, we'll come\l"
	.string "back for the rest of you! But for now,\l"
	.string "it's all business...$"

gText_ThereCanOnlyBe_DueToTheDelicateEcosystem::
	.string "Due to the delicate ecosystem of the\n"
	.string "region, Trainers are permitted to bring\l"
	.string "one Pokémon from outside the region\l"
	.string "into the region with them. Please\l"
	.string "choose one Pokémon to accompany you\l"
	.string "on your adventure. You will not be able\l"
	.string "to access the others during your\l"
	.string "playthrough, so choose wisely.$"

gText_ThereCanOnlyBe_PleaseChooseAPokemon::
	.string "Please choose a Pokémon to bring with\n"
	.string "you to SanFran.$"

gText_ThereCanOnlyBe_YouHaveSelected::
	.string "You have selected {STR_VAR_1}.$"

gText_ThereCanOnlyBe_StarterSelectSummaryErrorMessage::
	.string "In the next version, this will lead to\n"
	.string "the Pokémon summary screen.$"

gText_ThereCanOnlyBe_StarterSelectScytherDesc::
	.string "{STR_VAR_1} uses its Ability and\n"
	.string "Speed to overwhelm opponents.$"

gText_ThereCanOnlyBe_StarterSelectCharcadetDesc::
	.string "{STR_VAR_1} evolves into powerful\n"
	.string "Fire-type Pokemon with physical or\l"
	.string "special coverage.$"

gText_ThereCanOnlyBe_StarterSelectPetililDesc::
	.string "{STR_VAR_1} best utilizies its high\n"
	.string "Special Attack in the sun.$"

gText_ThereCanOnlyBe_StarterSelectFlaaffyDesc::
	.string "{STR_VAR_1} boasts a high Special\n"
	.string "Attack and diverse move pool.$"

gText_ThereCanOnlyBe_StarterSelectMareanieDesc::
	.string "{STR_VAR_1} uses Defense and\n"
	.string "Special Defense to wear down foes.$"

gText_ThereCanOnlyBe_StarterSelectAronDesc::
	.string "{STR_VAR_1} leverages its high\n"
	.string "Attack and Defense to provide\l"
	.string "physical support.$"

gText_ThereCanOnlyBe_StarterSelectSwinubDesc::
	.string "{STR_VAR_1} hits most types for\n"
	.string "super- effective damage with its high\l"
	.string "attack.$"

gText_ThereCanOnlyBe_StarterSelectHattremDesc::
	.string "{STR_VAR_1}'s high Special Attack\n"
	.string "and Special Defense makes it ideal for\l"
	.string "special support.$"

gText_ThereCanOnlyBe_StarterSelectPanchamDesc::
	.string "{STR_VAR_1} makes up for low Speed\n"
	.string "with high Attack and unique typing.$"

gText_ThereCanOnlyBe_StarterAreYouSure::
	.string "Are you sure you want to choose\n"
	.string "{STR_VAR_1}?$"

gText_ThereCanOnlyBe_YouChoseToBring::
	.string "You chose to bring {STR_VAR_1} to\n"
	.string "SanFran.$"
