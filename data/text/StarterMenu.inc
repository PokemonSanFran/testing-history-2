StarterSelect_Script::
	setvar VAR_0x8000, MUGSHOT_HILDA
	fadescreen FADE_TO_BLACK
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
	bufferspeciesname 0, SPECIES_POLIWHIRL
	msgbox gText_StarterSelectPoliwhirlDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_3:
	bufferspeciesname 0, SPECIES_FLETCHINDER
	msgbox gText_StarterSelectFletchinderDesc
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_4:
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_5:
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_6:
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_7:
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_8:
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_9:
	goto StarterChoice_Menu
	return

StarterSelectMenu_Script_10:
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
	goto StarterSelect_0_ChoiceConfirm
	return

StarterChoice_Menu_4:
	goto StarterSelectMenu_Script
	return


StarterSelect_0_ChoiceConfirm::
	msgbox gText_StarterAreYouSure, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq StarterSelect_0_ChoiceConfirm_1
	givecustommon SPECIES_FLETCHINDER, 22, ITEM_SITRUS_BERRY, ITEM_GREAT_BALL, , 1
	goto StarterChosen_Script
	return

StarterSelect_0_ChoiceConfirm_1:
	goto StarterSelectMenu_Script
	return


StarterChosen_Script::
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	msgbox gText_StarterSelectionChosen
	waitfanfare
	call Common_EventScript_SaveGame
	return


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
