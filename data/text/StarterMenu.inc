StarterSelect_Script::
	setvar VAR_0x8000, MUGSHOT_HILDA
	lockall
	callnative DrawMugshot
	msgbox gText_StarterSelectZoeyText1
	msgbox gText_StarterSelectZoeyText2
	callnative ClearMugshot
	msgbox gText_StarterSelectGameText1
	closemessage
	call Common_EventScript_SaveGame
	closemessage
	goto StarterSelectMenu_Script
	return


StarterSelectMenu_Script::
	msgbox gText_StarterSelectGameText2
	closemessage
	multichoice 0, 0, MULTI_STARTER_SELECT, TRUE
	switch VAR_RESULT
	case 0, StarterSelectMenu_Script_2
	case 1, StarterSelectMenu_Script_3
	case 2, StarterSelectMenu_Script_4
	case 3, StarterSelectMenu_Script_5
	case 4, StarterSelectMenu_Script_6
	case 5, StarterSelectMenu_Script_7
	case 6, StarterSelectMenu_Script_8
	case 7, StarterSelectMenu_Script_9
	case 8, StarterSelectMenu_Script_10
	return

StarterSelectMenu_Script_2:
	setvar VAR_TEMP_0, 0
	bufferspeciesname 0, SPECIES_POLIWHIRL
	msgbox gText_StarterSelectPoliwhirlDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_3:
	setvar VAR_TEMP_0, 1
	bufferspeciesname 0, SPECIES_FLETCHINDER
	msgbox gText_StarterSelectFletchinderDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_4:
	setvar VAR_TEMP_0, 2
	bufferspeciesname 0, SPECIES_PETILIL
	msgbox gText_StarterSelectFletchinderDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_5:
	setvar VAR_TEMP_0, 3
	bufferspeciesname 0, SPECIES_FLAAFFY
	msgbox gText_StarterSelectFlaaffyDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_6:
	setvar VAR_TEMP_0, 4
	bufferspeciesname 0, SPECIES_MAREANIE
	msgbox gText_StarterSelectMareanieDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_7:
	setvar VAR_TEMP_0, 5
	bufferspeciesname 0, SPECIES_ARON
	msgbox gText_StarterSelectAronDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_8:
	setvar VAR_TEMP_0, 6
	bufferspeciesname 0, SPECIES_SWINUB
	msgbox gText_StarterSelectSwinubDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_9:
	setvar VAR_TEMP_0, 7
	bufferspeciesname 0, SPECIES_HATTREM
	msgbox gText_StarterSelectHattremDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_10:
	setvar VAR_TEMP_0, 8
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
	goto StarterSelectMenu_Script
	return

StarterChoice_Menu_3:
	goto StarterSelectChoiceConfirm
	return

StarterChoice_Menu_4:
	goto StarterSelectMenu_Script
	return


StarterSelectChoiceConfirm::
	msgbox gText_StarterAreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq StarterSelectChoiceConfirm_1
	switch VAR_TEMP_0
	case 0, StarterSelectChoiceConfirm_6
	case 1, StarterSelectChoiceConfirm_7
	case 2, StarterSelectChoiceConfirm_8
	case 3, StarterSelectChoiceConfirm_9
	case 4, StarterSelectChoiceConfirm_10
	case 5, StarterSelectChoiceConfirm_11
	case 6, StarterSelectChoiceConfirm_12
	case 7, StarterSelectChoiceConfirm_13
	case 8, StarterSelectChoiceConfirm_14
StarterSelectChoiceConfirm_4:
	goto StarterChosen_Script
	return

StarterSelectChoiceConfirm_1:
	goto StarterSelectMenu_Script
	return

StarterSelectChoiceConfirm_6:
	givecustommon SPECIES_POLIWHIRL, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_7:
	givecustommon SPECIES_FLETCHINDER, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_8:
	givecustommon SPECIES_PETILIL, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_9:
	givecustommon SPECIES_FLAAFFY, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_10:
	givecustommon SPECIES_MAREANIE, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_11:
	givecustommon SPECIES_ARON, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 0
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_12:
	givecustommon SPECIES_SWINUB, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_13:
	givecustommon SPECIES_HATTREM, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 2
	goto StarterSelectChoiceConfirm_4

StarterSelectChoiceConfirm_14:
	givecustommon SPECIES_PANCHAM, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	goto StarterSelectChoiceConfirm_4


StarterChosen_Script::
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_StarterSelectionChosen
	waitfanfare
	call Common_EventScript_SaveGame
	closemessage
	fadescreen FADE_FROM_BLACK
	release
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
	.string "You have selected {STR_VAR_1}.$"

gText_StarterSelectSummaryErrorMessage::
	.string "In the next version, this will lead to\n"
	.string "the Pokémon summary screen.$"

gText_StarterSelectPoliwhirlDesc::
	.string "{STR_VAR_1} excels in the rain and\n"
	.string "gives plenty of options for Trainers.$"

gText_StarterSelectFletchinderDesc::
	.string "{STR_VAR_1} can provide offense or\n"
	.string "support with its high Speed.$"

gText_StarterSelectPetililDesc::
	.string "{STR_VAR_1} best utilizies its high\n"
	.string "Special Attack in the sun.$"

gText_StarterSelectFlaaffyDesc::
	.string "{STR_VAR_1} boasts a high Special\n"
	.string "Attack and diverse move pool.$"

gText_StarterSelectMareanieDesc::
	.string "{STR_VAR_1} uses Defense and\n"
	.string "Special Defense to wear down foes.$"

gText_StarterSelectAronDesc::
	.string "{STR_VAR_1} leverages its high\n"
	.string "Attack and Defense to provide\l"
	.string "physical support.$"

gText_StarterSelectSwinubDesc::
	.string "{STR_VAR_1} hits most types for\n"
	.string "super- effective damage with its high\l"
	.string "attack.$"

gText_StarterSelectHattremDesc::
	.string "{STR_VAR_1}'s high Special Attack\n"
	.string "and Special Defense makes it ideal for\l"
	.string "special support.$"

gText_StarterSelectPanchamDesc::
	.string "{STR_VAR_1} makes up for low Speed\n"
	.string "with high Attack and unique typing.$"

gText_StarterAreYouSure::
	.string "Are you sure you want to choose\n"
	.string "{STR_VAR_1}?$"

gText_StarterSelectionChosen::
	.string "You chose to bring {STR_VAR_1} to\n"
	.string "SanFran.$"
