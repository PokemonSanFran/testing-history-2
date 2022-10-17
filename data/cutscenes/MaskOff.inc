MaskOff_HideObject_Script::
	compare VAR_STORYLINE_STATE, STORY_START_TRUE_TIMELINE
	goto_if_lt MaskOff_HideObject_Script_1
	return

MaskOff_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return


MaskOff_TransformObject_Script::
	removeobject 1
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_DRAKE
	addobject 1
	return


MaskOff_QuestH_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, ASSIGNED_MASK_OFF
	goto_if_eq MaskOff_QuestH_Dialogue_2
MaskOff_QuestH_Dialogue_1:
	msgbox gText_MaskOff_IRememberMeeting
	msgbox gText_MaskOff_HeSaidEvenThen
	msgbox gText_MaskOff_IThinkThatAccident
	closemessage
	return

MaskOff_QuestH_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_MASK_OFF_STATE, 1
	goto MaskOff_QuestH_Dialogue_1


MaskOff_QuestF_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, GOT_MASK_OFF_CLUE_1
	goto_if_eq MaskOff_QuestF_Dialogue_2
MaskOff_QuestF_Dialogue_1:
	msgbox gText_MaskOff_IMissWorking
	msgbox gText_MaskOff_HeWouldLeaveRight
	closemessage
	return

MaskOff_QuestF_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_MASK_OFF_STATE, 1
	goto MaskOff_QuestF_Dialogue_1


MaskOff_QuestI_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, GOT_MASK_OFF_CLUE_2
	goto_if_eq MaskOff_QuestI_Dialogue_2
MaskOff_QuestI_Dialogue_1:
	msgbox gText_MaskOff_UsedToCome
	msgbox gText_MaskOff_TheyWouldJust
	msgbox gText_MaskOff_IThinkSoHe
	closemessage
	return

MaskOff_QuestI_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_MASK_OFF_STATE, 1
	goto MaskOff_QuestI_Dialogue_1


MaskOff_QuestD_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, GOT_MASK_OFF_CLUE_2
	goto_if_eq MaskOff_QuestD_Dialogue_2
MaskOff_QuestD_Dialogue_1:
	msgbox gText_MaskOff_UsedToBeHere
	msgbox gText_MaskOff_BookwormsTendToBe
	closemessage
	return

MaskOff_QuestD_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_MASK_OFF_STATE, 1
	goto MaskOff_QuestD_Dialogue_1


MaskOff_QuestK_Dialogue::
	msgbox gText_MaskOff_ADigitalPhoto, MSGBOX_AUTOCLOSE
	closemessage
	return


MaskOff_QuestG_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, GOT_MASK_OFF_CLUE_3
	goto_if_eq MaskOff_QuestG_Dialogue_2
MaskOff_QuestG_Dialogue_1:
	msgbox gText_MaskOff_GaveATalkHereOnce
	msgbox gText_MaskOff_WhateverHeDidWorked
	msgbox gText_MaskOff_WhenverHeLeft
	closemessage
	return

MaskOff_QuestG_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	addvar VAR_MASK_OFF_STATE, 1
	goto MaskOff_QuestG_Dialogue_1


MaskOff_QuestA_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, GOT_MASK_OFF_CLUE_5
	goto_if_eq MaskOff_QuestA_Dialogue_2
MaskOff_QuestA_Dialogue_1:
	msgbox gText_MaskOff_IUsedToSee
	msgbox gText_MaskOff_HeWorkedInThe
	msgbox gText_MaskOff_WatchingHimBattle
	closemessage
	return

MaskOff_QuestA_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	goto MaskOff_QuestA_Dialogue_1


MaskOff_QuestE_Dialogue::
	faceplayer
	compare VAR_MASK_OFF_STATE, GOT_MASK_OFF_CLUE_4
	goto_if_eq MaskOff_QuestE_Dialogue_2
MaskOff_QuestE_Dialogue_1:
	msgbox gText_MaskOff_WasBornAndRaised
	msgbox gText_MaskOff_IKnowHeUsedToLive
	msgbox gText_MaskOff_ItUsedToBeSuper
	closemessage
	return

MaskOff_QuestE_Dialogue_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatCanYou
	callnative ClearMugshot
	goto MaskOff_QuestE_Dialogue_1


MaskOff_Encounter_Giovanni_Dialogue::
	lock
	setvar VAR_MASK_OFF_STATE, SAVE_GIOVANNI_LAKEMERRITT_TRUE
	call Common_EventScript_SaveGame
	setvar VAR_MUGSHOT, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_FancyABattle, MSGBOX_NPC
	callnative ClearMugshot
	lock
	trainerbattle_no_intro TRAINER_SHELLY_SEAFLOOR_CAVERN, gText_GroupStages_Placeholder
	setvar VAR_MASK_OFF_STATE, DEFEATED_MASK_OFF_GIOVANNI
	setvar VAR_STORYLINE_STATE, STORY_DEFEATED_GIOVANNI
	goto MaskOff_PostBattle_Dialogue
	return


MaskOff_PostBattle_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_YouveMadeIncredible
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_ItsNiceToNotGet
	setvar VAR_MUGSHOT, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_YouWontNeedTo
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WhatDoYouMean
	setvar VAR_MUGSHOT, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_MaskOff_AllowMeTo
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	call MaskOff_TransformObject_Script
	lock
	fadescreen FADE_FROM_BLACK
	setvar VAR_MUGSHOT, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_TheOneAndOnly, MSGBOX_NPC
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	setvar VAR_MUGSHOT, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IFormedTeamRocket
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_ButWhyGo
	setvar VAR_MUGSHOT, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IHidMyIdentity
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_ThingsAre
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	delay 32
	fadescreen FADE_FROM_BLACK
	setvar VAR_MUGSHOT, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_ISee
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MaskOff_WaitWhatDO
	setvar VAR_MUGSHOT, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IHaventExplicitly
	setvar VAR_MUGSHOT, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_MaskOff_IShouldApologize
	callnative ClearMugshot
	closemessage
	goto MaskOff_End_Dialogue
	return


MaskOff_End_Dialogue::
	applymovement 1, MaskOff_WalkOffScreen
	waitmovement 1
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
	.string "Champion, {PLAYER}. TeamRocket is\l"
	.string "lucky to have another powerful ally$"

gText_MaskOff_ItsNiceToNotGet::
	.string "Thank you! It’s nice to not get crushed\n"
	.string "as easily anymore… wait! I was\l"
	.string "following a lead looking for Wikstrom. I\l"
	.string "think they train around here, and I\l"
	.string "want to try to convince them to work\l"
	.string "with us.$"

gText_MaskOff_YouWontNeedTo::
	.string "You won’t need to do much convincing,\n"
	.string "actually.$"

gText_MaskOff_WhatDoYouMean::
	.string "What do you mean?$"

gText_MaskOff_AllowMeTo::
	.string "Allow me to re-introduce myself. I am\n"
	.string "the leader of TeamRocket, member of\l"
	.string "the Elite Four,$"

gText_MaskOff_TheOneAndOnly::
	.string "the one and only… Wikstrom.$"

gText_MaskOff_IFormedTeamRocket::
	.string "I formed TeamRocket as a response to\n"
	.string "Ycombinator’s growing influence over\l"
	.string "the region a few years ago.$"

gText_MaskOff_ButWhyGo::
	.string "But why go into hiding as Giovanni?$"

gText_MaskOff_IHidMyIdentity::
	.string "I hid my identity because I was worried\n"
	.string "about my influence diluting the\l"
	.string "message. If people could unite under a\l"
	.string "symbol like Giovanni, then in theory,\l"
	.string "anybody could lead TeamRocket if\l"
	.string "something happened to me. And if the\l"
	.string "Elite Four wasn’t directly connected to\l"
	.string "TeamRocket, then they couldn’t\l"
	.string "retaliate against the others.$"

gText_MaskOff_ThingsAre::
	.string "Things are… a little different now. I\n"
	.string "met with Archer…$"

gText_MaskOff_ISee::
	.string "I see. If the Elite Four is going to\n"
	.string "present as a united front, I’ll need to\l"
	.string "give up leadership to Ariana. You know,\l"
	.string "I think they’ve purposely kept me in\l"
	.string "the dark about this.$"

gText_MaskOff_WaitWhatDO::
	.string "Wait, what do you mean?$"

gText_MaskOff_IHaventExplicitly::
	.string "I haven’t explicitly told them, but I’ve\n"
	.string "long suspected they know my secret.\l"
	.string "They have some reservations about\l"
	.string "taking a leadership role… but I know\l"
	.string "they can handle it.$"

gText_MaskOff_IShouldApologize::
	.string "I should apologize to Siebold for\n"
	.string "disappearing. But you should get some\l"
	.string "rest. Our war begins first thing in the\l"
	.string "morning.$"

gText_MaskOff_WhatCanYou::
	.string "Hi there. What can you tell me about\n"
	.string "Wikstrom?$"

gText_MaskOff_IUsedToSee::
	.string "I used to see Wikstrom all the time, but\n"
	.string "I'm pretty sure he moved away. He used\l"
	.string "to come back super late at night, so he\l"
	.string "must have been pulling really long\l"
	.string "hours.$"

gText_MaskOff_HeWorkedInThe::
	.string "He worked in the Mission as a business\n"
	.string "consultant for the little guy. It was\l"
	.string "awesome to see a member of the\l"
	.string "community become an Elite Four member!$"

gText_MaskOff_WatchingHimBattle::
	.string "Watching him battle was so awesome! I\n"
	.string "loved watching him use Ditto to\l"
	.string "confuse 'em before knocking them on\l"
	.string "their ass with super powerful moves...\l"
	.string "he would end matches so fast.$"

gText_MaskOff_UsedToBeHere::
	.string "Wikstrom used to be here all the time,\n"
	.string "but I only ever saw him by himself. He\l"
	.string "was kind of a loner.$"

gText_MaskOff_BookwormsTendToBe::
	.string "Bookworms tend to be like that though.\n"
	.string "Once he did an interview and all he\l"
	.string "talked about was non-fiction that he\l"
	.string "was into...$"

gText_MaskOff_WasBornAndRaised::
	.string "The Elite Four's Wikstrom was born and\n"
	.string "raised here in SanFran.$"

gText_MaskOff_IKnowHeUsedToLive::
	.string "I know he used to live in the Sunset,\n"
	.string "but ever since he disappeared, people\l"
	.string "haven't seen him.$"

gText_MaskOff_ItUsedToBeSuper::
	.string "He sometimes trained around here.\n"
	.string "Afterwards, he and his Pokemon would\l"
	.string "take a walk and relax by Lakemerritt.$"

gText_MaskOff_IMissWorking::
	.string "I miss working with Wikstrom. Whenever\n"
	.string "he made great progress, he would treat\l"
	.string "the entire team to ramen in Japantown!$"

gText_MaskOff_HeWouldLeaveRight::
	.string "He would leave right after, to stock up\n"
	.string "on supplies at his favorite shop in the\l"
	.string "Castro. He liked using Dusk Balls to do\l"
	.string "his captures, so after dinner was the\l"
	.string "best time.$"

gText_MaskOff_GaveATalkHereOnce::
	.string "Wikstrom gave a talk here once, where\n"
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
	.string "I remember meeting Wikstrom when he\n"
	.string "was 20. I interviewed him after his\l"
	.string "parents were killed by loan sharks.\l"
	.string "Tough break, but a tough kid too.$"

gText_MaskOff_HeSaidEvenThen::
	.string "He said even then that he didn't want\n"
	.string "anybody else to end up like his\l"
	.string "parents, so he worked for a long time\l"
	.string "to help small businesses grow and be\l"
	.string "sustainable. He did good work in the\l"
	.string "Mission.$"

gText_MaskOff_IThinkThatAccident::
	.string "I think that accident changed him\n"
	.string "though... never really saw him with a\l"
	.string "ton of friends, or out and about... like\l"
	.string "he hated the limelight.$"

gText_MaskOff_UsedToCome::
	.string "Siebold and Wikstrom used to come in\n"
	.string "together a lot.$"

gText_MaskOff_TheyWouldJust::
	.string "They would just talk about books the\n"
	.string "whole time.. I think Wikstrom really\l"
	.string "loved history.$"

gText_MaskOff_IThinkSoHe::
	.string "Wikstrom lived close by... in Sunset, I\n"
	.string "think, so he was here, with or without\l"
	.string "Siebold.$"

gText_MaskOff_ADigitalPhoto::
	.string "A digital photo frame. The picture being\n"
	.string "displayed shows Wikstrom and Siebold\l"
	.string "together at the ramen restaurantin\l"
	.string "Japantown.$"

gText_MaskOff_FancyABattle::
	.string "A surprise, seeing you here, {PLAYER}.\n"
	.string "I hear you've turned over a new leaf.\l"
	.string "Let's see if your new found\l"
	.string "convinction gives you power!$"
