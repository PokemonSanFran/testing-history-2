MaskOff_HideObject_Script::
	setflag FLAG_TEMP_1
	return


MaskOff_QuestH_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 1
	goto_if_eq MaskOff_QuestH_Dialogue_2
MaskOff_QuestH_Dialogue_1:
	msgbox gText_MaskOff_IRememberMeeting
	msgbox gText_MaskOff_HeSaidEvenThen
	msgbox gText_MaskOff_IThinkThatAccident
	closemessage
	return

MaskOff_QuestH_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestH_Dialogue_1


MaskOff_QuestF_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 2
	goto_if_eq MaskOff_QuestF_Dialogue_2
MaskOff_QuestF_Dialogue_1:
	msgbox gText_MaskOff_IMissWorking
	msgbox gText_MaskOff_HeWouldLeaveRight
	closemessage
	return

MaskOff_QuestF_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestF_Dialogue_1


MaskOff_QuestI_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 3
	goto_if_eq MaskOff_QuestI_Dialogue_2
MaskOff_QuestI_Dialogue_1:
	msgbox gText_MaskOff_UsedToCome
	msgbox gText_MaskOff_TheyWouldJust
	msgbox gText_MaskOff_IThinkSoHe
	closemessage
	return

MaskOff_QuestI_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestI_Dialogue_1


MaskOff_QuestD_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 3
	goto_if_eq MaskOff_QuestD_Dialogue_2
MaskOff_QuestD_Dialogue_1:
	msgbox gText_MaskOff_UsedToBeHere
	msgbox gText_MaskOff_BookwormsTendToBe
	closemessage
	return

MaskOff_QuestD_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestD_Dialogue_1


MaskOff_QuestK_Dialogue::
	msgbox gText_MaskOff_ADigitalPhoto
	closemessage
	return


MaskOff_QuestG_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 4
	goto_if_eq MaskOff_QuestG_Dialogue_2
MaskOff_QuestG_Dialogue_1:
	msgbox gText_MaskOff_GaveATalkHereOnce
	msgbox gText_MaskOff_WhateverHeDidWorked
	msgbox gText_MaskOff_WhenverHeLeft
	closemessage
	return

MaskOff_QuestG_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestG_Dialogue_1


MaskOff_QuestA_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 4
	goto_if_eq MaskOff_QuestA_Dialogue_2
MaskOff_QuestA_Dialogue_1:
	msgbox gText_MaskOff_IUsedToSee
	msgbox gText_MaskOff_HeWorkedInThe
	msgbox gText_MaskOff_WatchingHimBattle
	closemessage
	return

MaskOff_QuestA_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestA_Dialogue_1


MaskOff_QuestE_Dialogue::
	faceplayer
	compare VAR_RUSTURF_TUNNEL_STATE, 5
	goto_if_eq MaskOff_QuestE_Dialogue_2
MaskOff_QuestE_Dialogue_1:
	msgbox gText_MaskOff_WasBornAndRaised
	msgbox gText_MaskOff_IKnowHeUsedToLive
	msgbox gText_MaskOff_ItUsedToBeSuper
	closemessage
	return

MaskOff_QuestE_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	goto MaskOff_QuestE_Dialogue_1


MaskOff_Encounter_Psfgoodboss_Dialogue::
	lock
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	call Common_EventScript_SaveGame
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_FancyABattle, MSGBOX_NPC
	callnative ClearMugshot
	lock
	trainerbattle_no_intro TRAINER_SHELLY_SEAFLOOR_CAVERN, gText_GroupStages_Blank
	addvar VAR_RUSTURF_TUNNEL_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	callnative ClearMugshot
	return


gText_MaskOff_WhatCanYou::
	.string "Hi there. What can you tell me about\n"
	.string "Psfelite4?$"

gText_MaskOff_IUsedToSee::
	.string "I used to see Psfelite4 all the time,\n"
	.string "but I'm pretty sure he moved away. He\l"
	.string "used to come back super late at night,\l"
	.string "so he must have been pulling really\l"
	.string "long hours.$"

gText_MaskOff_HeWorkedInThe::
	.string "He worked in the Psfcity6 as a business\n"
	.string "consultant for the little guy. It was\l"
	.string "awesome to see a member of the\l"
	.string "community become an Elite Four member!$"

gText_MaskOff_WatchingHimBattle::
	.string "Watching him battle was so awesome! I\n"
	.string "loved watching use Ditto to confuse\l"
	.string "'em before knocking them on their ass\l"
	.string "with super powerful moves... he would\l"
	.string "end matches so fast.$"

gText_MaskOff_UsedToBeHere::
	.string "Psfelite4 used to be here all the time,\n"
	.string "but I only ever saw him by himself. He\l"
	.string "was kind of a loner.$"

gText_MaskOff_BookwormsTendToBe::
	.string "Bookworms tend to be like that though.\n"
	.string "Once he did an interview and all he\l"
	.string "talked about was non-fiction that he\l"
	.string "was into...$"

gText_MaskOff_WasBornAndRaised::
	.string "The Elite Four's Psfelite4 was born and\n"
	.string "raised here in Psfregion1.$"

gText_MaskOff_IKnowHeUsedToLive::
	.string "I know he used to live in the Psfcity1,\n"
	.string "but ever since he disappeared, people\l"
	.string "haven't seen him.$"

gText_MaskOff_ItUsedToBeSuper::
	.string "It used to be super common to see him\n"
	.string "zipping around in the skies. Psfelite4\l"
	.string "is one of the few trainers that flies\l"
	.string "on his Pokémon to travel around!$"

gText_MaskOff_IMissWorking::
	.string "I miss working with Psfelite4. Whenever\n"
	.string "he made great progress, he would treat\l"
	.string "the entire team to ramen in Psfcity14!$"

gText_MaskOff_HeWouldLeaveRight::
	.string "He would leave right after, even when it\n"
	.string "was late. He liked using Dusk Balls to\l"
	.string "do his captures, so after dinner was\l"
	.string "the best time.$"

gText_MaskOff_GaveATalkHereOnce::
	.string "Psfelite4 gave a talk here once, where\n"
	.string "he talked about the importance of\l"
	.string "training your Pokémon in their natural\l"
	.string "habitat. He says the connection to\l"
	.string "their home was where they grew the\l"
	.string "best. Never seen a book to back that\l"
	.string "up though...$"

gText_MaskOff_WhateverHeDidWorked::
	.string "Whatever he did worked though! His\n"
	.string "entire battle style revolved around\l"
	.string "tricking people and then overwhelming\l"
	.string "them with crazy power... it was awesome\l"
	.string "to watch, especially when he used his\l"
	.string "ace, Ditto.$"

gText_MaskOff_WhenverHeLeft::
	.string "Whenever he left here, I never saw him\n"
	.string "taking the bus - he would just Fly away\l"
	.string "from the front steps!$"

gText_MaskOff_IRememberMeeting::
	.string "I remember meeting Psfelite4 when he\n"
	.string "was 20. I interviewed him after his\l"
	.string "parents were killed by loan sharks.\l"
	.string "Tough break, but a tough kid too.$"

gText_MaskOff_HeSaidEvenThen::
	.string "He said even then that he didn't want\n"
	.string "anybody else to end up like his\l"
	.string "parents, so he worked for a long time\l"
	.string "to help small businesses grow and be\l"
	.string "sustainable. He did good work in the\l"
	.string "Psfcity6.$"

gText_MaskOff_IThinkThatAccident::
	.string "I think that accident changed him\n"
	.string "though... never really saw him with a\l"
	.string "ton of friends, or out and about... like\l"
	.string "he hated the limelight.$"

gText_MaskOff_UsedToCome::
	.string "Psfelite3 and Psfelite4 used to come in\n"
	.string "together a lot.$"

gText_MaskOff_TheyWouldJust::
	.string "They would just talk about books the\n"
	.string "whole time.. I think Psfelite4 really\l"
	.string "loved history.$"

gText_MaskOff_IThinkSoHe::
	.string "Psfelite4 lived close by... in Psfcity1, I\n"
	.string "think, so he was here, with or without\l"
	.string "Psfelite3.$"

gText_MaskOff_ADigitalPhoto::
	.string "A digital photo frame. The picture being\n"
	.string "displayed shows Psfelite4 and\l"
	.string "Psfelite3 together at a ramen\l"
	.string "restaurant.$"

gText_MaskOff_FancyABattle::
	.string "A surprise, seeing you here, {PLAYER}.\n"
	.string "I hear you've turned over a new leaf.\l"
	.string "Let's see if your new found\l"
	.string "convinction gives you power!$"
