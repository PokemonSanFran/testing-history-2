MaskOff_HideObject_Script::
	setflag FLAG_TEMP_1
	return


MaskOff_TransformObject_Script::
	removeobject 1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_DRAKE
	addobject 1
	return


MaskOff_QuestH_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 1
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
	addvar VAR_LILYCOVE_CITY_STATE, 1
	goto MaskOff_QuestH_Dialogue_1


MaskOff_QuestF_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 2
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
	addvar VAR_LILYCOVE_CITY_STATE, 1
	goto MaskOff_QuestF_Dialogue_1


MaskOff_QuestI_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 3
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
	addvar VAR_LILYCOVE_CITY_STATE, 1
	goto MaskOff_QuestI_Dialogue_1


MaskOff_QuestD_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 3
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
	addvar VAR_LILYCOVE_CITY_STATE, 1
	goto MaskOff_QuestD_Dialogue_1


MaskOff_QuestK_Dialogue::
	msgbox gText_MaskOff_ADigitalPhoto, MSGBOX_AUTOCLOSE
	closemessage
	return


MaskOff_QuestG_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 4
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
	addvar VAR_LILYCOVE_CITY_STATE, 1
	goto MaskOff_QuestG_Dialogue_1


MaskOff_QuestA_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 4
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
	addvar VAR_LILYCOVE_CITY_STATE, 1
	goto MaskOff_QuestA_Dialogue_1


MaskOff_QuestE_Dialogue::
	faceplayer
	compare VAR_LILYCOVE_CITY_STATE, 5
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
	goto MaskOff_QuestE_Dialogue_1


MaskOff_Encounter_Psfgoodboss_Dialogue::
	lock
	setvar VAR_LILYCOVE_CITY_STATE, 7
	call Common_EventScript_SaveGame
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_FancyABattle, MSGBOX_NPC
	callnative ClearMugshot
	lock
	trainerbattle_no_intro TRAINER_SHELLY_SEAFLOOR_CAVERN, gText_GroupStages_Blank
	addvar VAR_LILYCOVE_CITY_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	goto MaskOff_PostBattle_Dialogue
	return


MaskOff_PostBattle_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_YouveMadeIncredible
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_ItsNiceToNotGet
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_YouWontNeedTo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatDoYouMean
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_AllowMeTo
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	call MaskOff_TransformObject_Script
	lock
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_TheOneAndOnly, MSGBOX_NPC
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IFormedPsfgoodteam
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_ButWhyGo
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IHidMyIdentity
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_ThingsAre
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	delay 32
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_ISee
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WaitWhatDO
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IHaventExplicitly
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IShouldApologize
	callnative ClearMugshot
	closemessage
	goto MaskOff_End_Dialogue
	return


MaskOff_End_Dialogue::
	applymovement 1, MaskOff_WalkOffScreen
	waitmovement 0
	removeobject 1
	release
	end


MaskOff_WalkOffScreen:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_MaskOff_YouveMadeIncredible::
	.string "You’ve made incredible progress since we\n"
	.string "last battled. But of course, you’re the\l"
	.string "Champion, {PLAYER}. Psfgoodteam is\l"
	.string "lucky to have another powerful ally$"

gText_MaskOff_ItsNiceToNotGet::
	.string "Thank you! It’s nice to not get crushed\n"
	.string "as easily anymore… wait! I was\l"
	.string "following a lead looking for Psfelite4.\l"
	.string "I think they train around here, and I\l"
	.string "want to try to convince them to work\l"
	.string "with us.$"

gText_MaskOff_YouWontNeedTo::
	.string "You won’t need to do much convincing,\n"
	.string "actually.$"

gText_MaskOff_WhatDoYouMean::
	.string "What do you mean?$"

gText_MaskOff_AllowMeTo::
	.string "Allow me to re-introduce myself. I am\n"
	.string "the leader of Psfgoodteam, member of\l"
	.string "the Elite Four,$"

gText_MaskOff_TheOneAndOnly::
	.string "the one and only… Psfelite4.$"

gText_MaskOff_IFormedPsfgoodteam::
	.string "I formed Psfgoodteam as a response to\n"
	.string "Psfbadguy’s growing influence over the\l"
	.string "region a few years ago.$"

gText_MaskOff_ButWhyGo::
	.string "But why go into hiding as Psfelite4?$"

gText_MaskOff_IHidMyIdentity::
	.string "I hid my identity because I was worried\n"
	.string "about my influence diluting the\l"
	.string "message. If people could unite under a\l"
	.string "symbol like Psfgoodboss, then in\l"
	.string "theory, anybody could lead\l"
	.string "Psfgoodteam if something happened to\l"
	.string "me. And if the Elite Four wasn’t directly\l"
	.string "connected to Psfgoodteam, then they\l"
	.string "couldn’t retaliate against the others.$"

gText_MaskOff_ThingsAre::
	.string "Things are… a little different now. I\n"
	.string "met with Psfnativerival…$"

gText_MaskOff_ISee::
	.string "I see. If the Elite Four is going to\n"
	.string "present as a united front, I’ll need to\l"
	.string "give up leadership to Psfgoodadmin.\l"
	.string "You know, I think they’ve purposely\l"
	.string "kept me in the dark about this.$"

gText_MaskOff_WaitWhatDO::
	.string "Wait, what do you mean?$"

gText_MaskOff_IHaventExplicitly::
	.string "I haven’t explicitly told them, but I’ve\n"
	.string "long suspected they know my secret.\l"
	.string "They have some reservations about\l"
	.string "taking a leadership role… but I know\l"
	.string "they can handle it.$"

gText_MaskOff_IShouldApologize::
	.string "I should apologize to Psfelite3 for\n"
	.string "disappearing. But you should get some\l"
	.string "rest. Our war begins first thing in the\l"
	.string "morning.$"

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
	.string "Psfelite3 together at the ramen\l"
	.string "restaurantin Psfcity14.$"

gText_MaskOff_FancyABattle::
	.string "A surprise, seeing you here, {PLAYER}.\n"
	.string "I hear you've turned over a new leaf.\l"
	.string "Let's see if your new found\l"
	.string "convinction gives you power!$"
