WarpToBlackMap::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, NewGameZoeyDialogue
	return


NewGameZoeyDialogue::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Movement_SetInvisible
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StarterSelectZoeyText1
	msgbox gText_StarterSelectZoeyText2
	callnative ClearMugshot
	goto NewGameNarratorDialogue
	return


NewGameNarratorDialogue::
	msgbox gText_StarterSelectGameText1
	closemessage
	call Common_EventScript_SaveGame
	closemessage
	goto StarterSelect_Menu
	return


StarterSelect_Menu::
	msgbox gText_StarterSelectGameText2
	closemessage
	multichoice 0, 0, MULTI_STARTER_SELECT, TRUE
	switch VAR_RESULT
	case 0, StarterSelect_Menu_2
	case 1, StarterSelect_Menu_3
	case 2, StarterSelect_Menu_4
	case 3, StarterSelect_Menu_5
	case 4, StarterSelect_Menu_6
	case 5, StarterSelect_Menu_7
	case 6, StarterSelect_Menu_8
	case 7, StarterSelect_Menu_9
	case 8, StarterSelect_Menu_10
	return

StarterSelect_Menu_2:
	setvar VAR_STARTER_MON, 0
	bufferspeciesname 0, SPECIES_POLIWHIRL
	msgbox gText_StarterSelectPoliwhirlDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_3:
	setvar VAR_STARTER_MON, 1
	bufferspeciesname 0, SPECIES_FLETCHINDER
	msgbox gText_StarterSelectFletchinderDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_4:
	setvar VAR_STARTER_MON, 2
	bufferspeciesname 0, SPECIES_PETILIL
	msgbox gText_StarterSelectFletchinderDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_5:
	setvar VAR_STARTER_MON, 3
	bufferspeciesname 0, SPECIES_FLAAFFY
	msgbox gText_StarterSelectFlaaffyDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_6:
	setvar VAR_STARTER_MON, 4
	bufferspeciesname 0, SPECIES_MAREANIE
	msgbox gText_StarterSelectMareanieDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_7:
	setvar VAR_STARTER_MON, 5
	bufferspeciesname 0, SPECIES_ARON
	msgbox gText_StarterSelectAronDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_8:
	setvar VAR_STARTER_MON, 6
	bufferspeciesname 0, SPECIES_SWINUB
	msgbox gText_StarterSelectSwinubDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_9:
	setvar VAR_STARTER_MON, 7
	bufferspeciesname 0, SPECIES_HATTREM
	msgbox gText_StarterSelectHattremDesc
	goto StarterChoice_Menu
	return

StarterSelect_Menu_10:
	setvar VAR_STARTER_MON, 8
	bufferspeciesname 0, SPECIES_PANCHAM
	msgbox gText_StarterSelectPanchamDesc
	goto StarterChoice_Menu
	return


StarterChoice_Menu::
	multichoice 50, 6, MULTI_STARTER_SUMMARY, TRUE
	switch VAR_RESULT
	case 0, StarterChoice_Menu_2
	case 1, StarterChoice_Menu_3
	case 2, StarterChoice_Menu_4
	return

StarterChoice_Menu_2:
	msgbox gText_StarterSelectSummaryErrorMessage
	goto StarterSelect_Menu
	return

StarterChoice_Menu_3:
	goto StarterSelectConfirm
	return

StarterChoice_Menu_4:
	goto StarterSelect_Menu
	return


StarterSelectConfirm::
	msgbox gText_StarterAreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq StarterSelectConfirm_1
	switch VAR_STARTER_MON
	case 0, StarterSelectConfirm_6
	case 1, StarterSelectConfirm_7
	case 2, StarterSelectConfirm_8
	case 3, StarterSelectConfirm_9
	case 4, StarterSelectConfirm_10
	case 5, StarterSelectConfirm_11
	case 6, StarterSelectConfirm_12
	case 7, StarterSelectConfirm_13
	case 8, StarterSelectConfirm_14
StarterSelectConfirm_4:
	goto StarterSelectEnd
	return

StarterSelectConfirm_1:
	goto StarterSelect_Menu
	return

StarterSelectConfirm_6:
	givecustommon SPECIES_POLIWHIRL, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	goto StarterSelectConfirm_4

StarterSelectConfirm_7:
	givecustommon SPECIES_FLETCHINDER, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	goto StarterSelectConfirm_4

StarterSelectConfirm_8:
	givecustommon SPECIES_PETILIL, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectConfirm_4

StarterSelectConfirm_9:
	givecustommon SPECIES_FLAAFFY, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectConfirm_4

StarterSelectConfirm_10:
	givecustommon SPECIES_MAREANIE, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectConfirm_4

StarterSelectConfirm_11:
	givecustommon SPECIES_ARON, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectConfirm_4

StarterSelectConfirm_12:
	givecustommon SPECIES_SWINUB, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	goto StarterSelectConfirm_4

StarterSelectConfirm_13:
	givecustommon SPECIES_HATTREM, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	goto StarterSelectConfirm_4

StarterSelectConfirm_14:
	givecustommon SPECIES_PANCHAM, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	goto StarterSelectConfirm_4


StarterSelectEnd::
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_StarterSelectionChosen
	waitfanfare
	call Common_EventScript_SaveGame
	closemessage
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 22
	releaseall
	end


gText_StarterSelectZoeyText1::
	.string "Almost packed and ready to go! I still\n"
	.string "can't believe I made it...$"

gText_StarterSelectZoeyText2::
	.string "But the rules say I can only bring one\n"
	.string "of you guys. Man, this sucks. I promise,\l"
	.string "once we're the Champion, we'll come\l"
	.string "back for the rest of you! But for now,\l"
	.string "it's all business...$"

gText_StarterSelectGameText1::
	.string "Due to the delicate ecosystem of the\n"
	.string "region, Trainers are permitted to bring\l"
	.string "one Pokémon from outside the region\l"
	.string "into the region with them. Please\l"
	.string "choose one Pokémon to accompany you\l"
	.string "on your adventure. You will not be able\l"
	.string "to access the others during your\l"
	.string "playthrough, so choose wisely.$"

gText_StarterSelectGameText2::
	.string "Please choose a Pokémon to bring with\n"
	.string "you to SanFran.$"

gText_StarterSelectGameText3::
	.string "You have selected {VAR_0x8001}.$"

gText_StarterSelectSummaryErrorMessage::
	.string "In the next version, this will lead to\n"
	.string "the Pokémon summary screen.$"

gText_StarterSelectPoliwhirlDesc::
	.string "{VAR_0x8001} excels in the rain and gives plenty of\n"
	.string "options for Trainers.$"

gText_StarterSelectFletchinderDesc::
	.string "{VAR_0x8001} can provide offense or support with\n"
	.string "its high Speed.$"

gText_StarterSelectPetililDesc::
	.string "{VAR_0x8001} best utilizies its high Special Attack\n"
	.string "in the sun.$"

gText_StarterSelectFlaaffyDesc::
	.string "{VAR_0x8001} boasts a high Special Attack and\n"
	.string "diverse move pool.$"

gText_StarterSelectMareanieDesc::
	.string "{VAR_0x8001} uses Defense and Special Defense to\n"
	.string "wear down foes.$"

gText_StarterSelectAronDesc::
	.string "{VAR_0x8001} leverages its high Attack and Defense\n"
	.string "to provide physical support.$"

gText_StarterSelectSwinubDesc::
	.string "{VAR_0x8001} hits most types for super- effective\n"
	.string "damage with its high attack.$"

gText_StarterSelectHattremDesc::
	.string "{VAR_0x8001}'s high Special Attack and Special\n"
	.string "Defense makes it ideal for special\l"
	.string "support.$"

gText_StarterSelectPanchamDesc::
	.string "{VAR_0x8001} makes up for low Speed with high\n"
	.string "Attack and unique typing.$"

gText_StarterAreYouSure::
	.string "Are you sure you want to choose {VAR_0x8001}?$"

gText_StarterSelectionChosen::
	.string "You chose to bring {VAR_0x8001} to SanFran.$"
