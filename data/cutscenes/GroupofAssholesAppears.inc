GroupOfAssholesAppears_CheckPartySize::
	special HasEnoughMonsForDoubleBattle
	compare VAR_RESULT, PLAYER_HAS_TWO_USABLE_MONS
	goto_if_eq GroupOfAssholesAppears_CheckPartySize_1
	goto GroupOfAssholesAppears_MovePlayerAway_Script
	return

GroupOfAssholesAppears_CheckPartySize_1:
	goto GroupOfAssholesAppears_GroupAssault_Dialogue
	return


GroupOfAssholesAppears_MovePlayerAway_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_IThinkINeedMore
	callnative ClearMugshot
	closemessage
	call GroupOfAssholesAppears_DecidePlayerMovement_NotEnoughMons_Script
	releaseall
	end


GroupOfAssholesAppears_DecidePlayerMovement_NotEnoughMons_Script::
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	switch VAR_TEMP_1
	case 36, GroupOfAssholesAppears_DecidePlayerMovement_NotEnoughMons_Script_3
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
GroupOfAssholesAppears_DecidePlayerMovement_NotEnoughMons_Script_1:
	waitmovement 0
	return

GroupOfAssholesAppears_DecidePlayerMovement_NotEnoughMons_Script_3:
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	goto GroupOfAssholesAppears_DecidePlayerMovement_NotEnoughMons_Script_1


GroupOfAssholesAppears_GroupAssault_Dialogue::
	lockall
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_YouShouldBeAshamed
	applymovement 2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_HaventYouDoneEnough
	applymovement 3, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_GiveJelenaBack
	applymovement 7, GroupOfAssholesAppears_LookAround_Movement
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_IDontKnowWho
	applymovement 4, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_WeDontWantToHear
	applymovement 7, Common_Movement_FaceLeft
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_RuinLives
	applymovement 5, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_NotIfWeHave
	closemessage
	call GroupOfAssholesAppears_PlayerToDavid_Script
	goto GroupOfAssholesAppears_PlayerIntervene_Dialogue
	return


GroupOfAssholesAppears_PlayerToDavid_Script::
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	switch VAR_TEMP_1
	case 36, GroupOfAssholesAppears_PlayerToDavid_Script_3
	applymovement OBJ_EVENT_ID_PLAYER, GroupOfAssholesAppears_WalkFromWest_Movement
GroupOfAssholesAppears_PlayerToDavid_Script_1:
	waitmovement 0
	return

GroupOfAssholesAppears_PlayerToDavid_Script_3:
	applymovement OBJ_EVENT_ID_PLAYER, GroupOfAssholesAppears_WalkFromEast_Movement
	goto GroupOfAssholesAppears_PlayerToDavid_Script_1


GroupOfAssholesAppears_PlayerIntervene_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_WhatTheHell
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceRight
	applymovement 3, Common_Movement_FaceRight
	applymovement 5, Common_Movement_FaceLeft
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_NothingWrongWith
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_ThisIsntAProtest
	callnative ClearMugshot
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_OhThankArceus
	closemessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	applymovement OBJ_EVENT_ID_PLAYER, GroupOfAssholesAppears_LookAround_Movement
	waitmovement 0
	msgbox gText_GroupOfAssholesAppears_HeMightBeAsking
	callnative ClearMugshot
	addvar VAR_GROUP_OF_ASSHOLES_STATE, 1
	call Common_EventScript_SaveGame
	closemessage
	goto GroupOfAssholes_StartBattle_Script
	return


GroupOfAssholes_PostSaveTrigger_Script::
	lockall
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	applymovement 3, Common_Movement_FaceRight
	applymovement 4, Common_Movement_FaceLeft
	waitmovement 0
	goto GroupOfAssholes_StartBattle_Script
	return


GroupOfAssholesAppears_GruntInteract_Script::
	lockall
	msgbox gText_GroupOfAssholesAppears_GoDefend, MSGBOX_NPC
	closemessage
	release
	end


GroupOfAssholes_StartBattle_Script::
	lockall
	applymovement 7, Common_Movement_FaceDown
	waitmovement 0
	trainerbattle_double TRAINER_IHSAN_AND_EMMITT, gText_GroupOfAssholesAppears_WhoTheHellYouThink, gText_GroupOfAssholesAppears_WoahWhoDidWePick, gText_GroupOfAssholesAppears_NotEnoughMons, GroupOfAssholesAppears_GroupLeaves_Dialogue, NO_MUSIC
	closemessage
	return


GroupOfAssholesAppears_GroupLeaves_Dialogue::
	lockall
	addvar VAR_GROUP_OF_ASSHOLES_STATE, 1
	msgbox gText_GroupOfAssholesAppears_PfftLooksLikeTheLeagueSent
	msgbox gText_GroupOfAssholesAppears_YouBothMakeMeSick
	closemessage
	applymovement 1, GroupOfAssholesAppears_LeaveFishermanswharf_Slot1_Movement
	applymovement 2, GroupOfAssholesAppears_LeaveFishermanswharf_Slot2_Movement
	applymovement 3, GroupOfAssholesAppears_LeaveFishermanswharf_Slot3_Movement
	applymovement 4, GroupOfAssholesAppears_LeaveFishermanswharf_Slot4_Movement
	applymovement 5, GroupOfAssholesAppears_LeaveFishermanswharf_Slot5_Movement
	applymovement 6, GroupOfAssholesAppears_LeaveFishermanswharf_Slot6_Movement
	waitmovement 0
	removeobject 1
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	removeobject 6
	fadedefaultbgm
	msgbox gText_GroupOfAssholesAppears_DontComeBackAssholes
	goto GroupOfAssholesAppears_ExplainTeam_Dialogue
	return


GroupOfAssholesAppears_ExplainTeam_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_GroupOfAssholesAppears_ThankYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_AreYouGoing
	callnative ClearMugshot
	msgbox gText_GroupOfAssholesAppears_GonnaNeedToPop
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_WhyWereTheyBullying
	callnative ClearMugshot
	msgbox gText_GroupOfAssholesAppears_SomethingStupidLikeThat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_ThatDoesntMakeAny
	callnative ClearMugshot
	msgbox gText_GroupOfAssholesAppears_MementoBoutique
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_ASouvenirShop
	callnative ClearMugshot
	msgbox gText_GroupOfAssholesAppears_WhenIPitchedIt
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_GroupOfAssholesAppears_ThatMakesSense
	callnative ClearMugshot
	goto GroupOfAssholesAppears_GiveRewards_Dialogue
	return


GroupOfAssholesAppears_GiveRewards_Dialogue::
	msgbox gText_GroupOfAssholesAppears_YoullHaveToCome
	giveitem ITEM_MACH_BIKE
	msgbox gText_GroupOfAssholesAppears_IfYouPutThatOn
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


GroupOfAssholesAppears_LookForXanax_Dialogue::
	lockall
	applymovement 7, GroupOfAssholesAppears_LookAround_Movement
	compare VAR_GROUP_OF_ASSHOLES_STATE, 1
	goto_if_eq GroupOfAssholesAppears_LookForXanax_Dialogue_2
	msgbox gText_GroupOfAssholesAppears_WhereDidIPut
GroupOfAssholesAppears_LookForXanax_Dialogue_1:
	closemessage
	releaseall
	end

GroupOfAssholesAppears_LookForXanax_Dialogue_2:
	msgbox gText_GroupOfAssholesAppears_Cries
	goto GroupOfAssholesAppears_LookForXanax_Dialogue_1


GroupOfAssholesAppears_LookAround_Movement:
	face_left
	delay_16
	face_right
	delay_16
	step_end

GroupOfAssholesAppears_WalkFromEast_Movement:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

GroupOfAssholesAppears_WalkFromWest_Movement:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

GroupOfAssholesAppears_LeaveFishermanswharf_Slot1_Movement:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GroupOfAssholesAppears_LeaveFishermanswharf_Slot2_Movement:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GroupOfAssholesAppears_LeaveFishermanswharf_Slot3_Movement:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GroupOfAssholesAppears_LeaveFishermanswharf_Slot4_Movement:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GroupOfAssholesAppears_LeaveFishermanswharf_Slot5_Movement:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GroupOfAssholesAppears_LeaveFishermanswharf_Slot6_Movement:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

gText_GroupOfAssholesAppears_IThinkINeedMore::
	.string "I think I'm going to need at least two\n"
	.string "healthy Pokémon for this.$"

gText_GroupOfAssholesAppears_NotEnoughMons::
	.string "Only one Pokémon with you? Bahahaha,\n"
	.string "come back when you're serious.$"

gText_GroupOfAssholesAppears_YouShouldBeAshamed::
	.string "You should be ashamed!$"

gText_GroupOfAssholesAppears_HaventYouDoneEnough::
	.string "Haven't you done enough already?$"

gText_GroupOfAssholesAppears_GiveJelenaBack::
	.string "Give Jelena back her store!$"

gText_GroupOfAssholesAppears_IDontKnowWho::
	.string "Oh Arceus, I don't know who Jelena is or\n"
	.string "what you want, or what I did to any of\l"
	.string "you!$"

gText_GroupOfAssholesAppears_WeDontWantToHear::
	.string "We don't want to hear it! How many lives\n"
	.string "are you going to try to ruin?$"

gText_GroupOfAssholesAppears_RuinLives::
	.string "Ruin lives? I'm opening a store!$"

gText_GroupOfAssholesAppears_NotIfWeHave::
	.string "Not if we have anything to say about it.$"

gText_GroupOfAssholesAppears_WhatTheHell::
	.string "What the hell is going on here? Why are\n"
	.string "you ganging up on this guy?$"

gText_GroupOfAssholesAppears_NothingWrongWith::
	.string "Nothing wrong with a little protest, kid.\n"
	.string "And where do you get off, defending\l"
	.string "this guy?$"

gText_GroupOfAssholesAppears_ThisIsntAProtest::
	.string "This isn't a protest. This is\n"
	.string "straight-up intimidation. Leave him\l"
	.string "alone!$"

gText_GroupOfAssholesAppears_OhThankArceus::
	.string "Oh thank Arceus, I don't know what they\n"
	.string "were going to do or what I did to them...\l"
	.string "I don't have anything to give you yet!\l"
	.string "Please, just leave me alone!$"

gText_GroupOfAssholesAppears_HeMightBeAsking::
	.string "He might be asking, but I'm not. Leave.$"

gText_GroupOfAssholesAppears_WhoTheHellYouThink::
	.string "I don't know who the hell you think you\n"
	.string "are, but anybody defending this trash\l"
	.string "clearly isn't going to be reasoned with.\l"
	.string "We'll show you!$"

gText_GroupOfAssholesAppears_Cries::
	.string "*cries*$"

gText_GroupOfAssholesAppears_ThatllShowYou::
	.string "That'll show you. Stay out of our way!$"

gText_GroupOfAssholesAppears_WoahWhoDidWePick::
	.string "Woah, who did we pick a fight with?$"

gText_GroupOfAssholesAppears_PfftLooksLikeTheLeagueSent::
	.string "Pfft, looks like the League sent by\n"
	.string "some enforcers to clear us out. Lame as\l"
	.string "hell.$"

gText_GroupOfAssholesAppears_YouBothMakeMeSick::
	.string "You both make me sick. Leave our people\n"
	.string "alone! *spits*$"

gText_GroupOfAssholesAppears_DontComeBackAssholes::
	.string "Yeah! And don't come back assholes!$"

gText_GroupOfAssholesAppears_ThankYou::
	.string "Thank you so much...$"

gText_GroupOfAssholesAppears_AreYouGoing::
	.string "Are you going to be okay?$"

gText_GroupOfAssholesAppears_GonnaNeedToPop::
	.string "Honestly? Gonna need to pop several\n"
	.string "Xanax after I come down from this\l"
	.string "panic attack, but I'll survive for sure.$"

gText_GroupOfAssholesAppears_WhyWereTheyBullying::
	.string "Why were they bullying you? Who are\n"
	.string "they?$"

gText_GroupOfAssholesAppears_SomethingStupidLikeThat::
	.string "Uhh... I think RockerGang or something\n"
	.string "stupid like that. I don't know what\l"
	.string "they want from me, they're like this\l"
	.string "band of idiots that just roll around\l"
	.string "everywhere, getting high and telling\l"
	.string "people they can't do things. Guess it\l"
	.string "was my turn.$"

gText_GroupOfAssholesAppears_ThatDoesntMakeAny::
	.string "That doesn't make any sense! You're\n"
	.string "just trying to open a.... Uh...$"

gText_GroupOfAssholesAppears_MementoBoutique::
	.string "Memento Boutique!$"

gText_GroupOfAssholesAppears_ASouvenirShop::
	.string "A souvenir shop?$"

gText_GroupOfAssholesAppears_WhenIPitchedIt::
	.string "When I pitched it to the League, it was\n"
	.string "a little more...upscale than some tacky\l"
	.string "place to buy snow globes and magnets.\l"
	.string "We're talking handcrafted items from\l"
	.string "the people of SanFran!$"

gText_GroupOfAssholesAppears_ThatMakesSense::
	.string "Oh, yeah... that makes sense.$"

gText_GroupOfAssholesAppears_YoullHaveToCome::
	.string "You'll have to come by once I open! And\n"
	.string "here, take this!$"

gText_GroupOfAssholesAppears_IfYouPutThatOn::
	.string "If you put that on, it'll point you\n"
	.string "towards hidden shit on the ground. My\l"
	.string "sister gave that to me... but I'm like\l"
	.string "literally never going to use it. Me? Dig\l"
	.string "around in the dirt? Wearing that?\l"
	.string "Absolutely not.$"

gText_GroupOfAssholesAppears_WhereDidIPut::
	.string "Now, where did I put those pills...?$"

gText_GroupOfAssholesAppears_GoDefend::
	.string "Go ahead, defend this clown!$"
