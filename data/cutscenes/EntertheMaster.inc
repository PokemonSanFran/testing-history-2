EnterTheMaster_HideBianca_Entrance_Script::
	compare VAR_MUIRWOODS_STATE, BIANCA_WAITING_MUIRWOODS
	goto_if_ne EnterTheMaster_HideBianca_Entrance_Script_2
EnterTheMaster_HideBianca_Entrance_Script_1:
	return

EnterTheMaster_HideBianca_Entrance_Script_2:
	setflag FLAG_TEMP_1
	goto EnterTheMaster_HideBianca_Entrance_Script_1


EnterTheMaster_ObjectsVisible_Script::
	switch VAR_MUIRWOODS_STATE
	case 1, EnterTheMaster_ObjectsVisible_Script_3
	case 2, EnterTheMaster_ObjectsVisible_Script_4
	goto EnterTheMaster_HideObject_Script
EnterTheMaster_ObjectsVisible_Script_1:
	return

EnterTheMaster_ObjectsVisible_Script_3:
	goto EnterTheMaster_Object_SetUp_Script
	goto EnterTheMaster_ObjectsVisible_Script_1

EnterTheMaster_ObjectsVisible_Script_4:
	goto EnterTheMaster_Object_SetUp_Script
	goto EnterTheMaster_ObjectsVisible_Script_1


EnterTheMaster_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


EnterTheMaster_Object_SetUp_Script::
	setflag FLAG_TEMP_3
	return


EnterTheMaster_Clearing_Object_SetUp_Script::
	setflag FLAG_TEMP_3
	return


EnterTheMaster_Interact_Script::
	lock
	faceplayer
	goto EnterTheMaster_Ready_Dialogue
	return


EnterTheMaster_WalkingTrigger_Script::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto EnterTheMaster_Ready_Dialogue
	return


EnterTheMaster_Ready_Dialogue::
	setvar VAR_MUIRWOODS_STATE, BIANCA_ENTERED_MUIRWOODS
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_MorningReady
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AsReadyAs
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_DaddySentAnother
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_ThanksDad
	callnative ClearMugshot
	closemessage
	applymovement 1, EnterTheMaster_WalkIntoWoods
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	release
	end


EnterTheMaster_InteractFollower_Script::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	random 4
	switch VAR_RESULT
	case 0, EnterTheMaster_InteractFollower_Script_3
	case 1, EnterTheMaster_InteractFollower_Script_4
	case 2, EnterTheMaster_InteractFollower_Script_5
	case 3, EnterTheMaster_InteractFollower_Script_6
EnterTheMaster_InteractFollower_Script_1:
	closemessage
	callnative ClearMugshot
	release
	end

EnterTheMaster_InteractFollower_Script_3:
	msgbox gText_EnterTheMaster_HowDoYouThink, MSGBOX_NPC
	goto EnterTheMaster_InteractFollower_Script_1

EnterTheMaster_InteractFollower_Script_4:
	msgbox gText_EnterTheMaster_YouKnow, MSGBOX_NPC
	goto EnterTheMaster_InteractFollower_Script_1

EnterTheMaster_InteractFollower_Script_5:
	msgbox gText_EnterTheMaster_IThoughtGymLeaders, MSGBOX_NPC
	goto EnterTheMaster_InteractFollower_Script_1

EnterTheMaster_InteractFollower_Script_6:
	msgbox gText_EnterTheMaster_DoYouThinkTheyre, MSGBOX_NPC
	goto EnterTheMaster_InteractFollower_Script_1


EnterTheMaster_LeaveWoods_Script::
	lock
	faceplayer
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_TiredAlready
	closemessage
	callnative ClearMugshot
	return


EnterTheMaster_CompleteMaze_Dialogue::
	setvar VAR_MUIRWOODS_STATE, MUIRWOODS_MAZE_COMPLETE
	lock
	addobject 1
	setobjectxy 1, 24, 22
	setobjectxyperm 1, 24, 22
	faceplayer
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_IDontThinkTheres
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_YouThinkTheyve
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_TheyreGettingPaid
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterTheMaster_WalkIntoWoods
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	release
	end


EnterTheMaster_ClearingIntro_Dialogue::
	setvar VAR_MUIRWOODS_STATE, MET_SIEBOLD
	applymovement OBJ_EVENT_ID_PLAYER, EnterTheMaster_ApproachSiebold
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_WelcomeTo
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_ThanksYoure
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AndMyNotebook
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceLeft
	applymovement 1, EnterTheMaster_GiveNotebook
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_GettingThemToBattle
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_IsThatWhatYoure
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_EveryClientAlways
	closemessage
	callnative ClearMugshot
	applymovement 1, EnterTheMaster_StandNextToPlayer
	waitmovement 0
	applymovement 2, EnterTheMaster_Pace
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AreEitherOfYou
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_YeahThatsTheBattleFrontier
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_HmmTheSmartass
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_OhDoesEachPart
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_SorryDidntGoTo
	applymovement 1, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_ScottIsTheFounder
	fadescreen FADE_TO_BLACK
	msgbox gText_EnterTheMaster_OneEternity
	applymovement 1, Common_Movement_FaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AndSoConcludes
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_SortaKindaNotReally
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_Oh
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_SoWhatsNext
	setvar VAR_MUGSHOT, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_WellUntilNSFigures
	callnative ClearMugshot
	closemessage
	end


EnterTheMaster_WalkIntoWoods:
	walk_up
	step_end

EnterTheMaster_GiveNotebook:
	walk_up
	face_right
	delay_16
	walk_in_place_slow_right
	step_end

EnterTheMaster_StandNextToPlayer:
	walk_down
	face_up
	step_end

EnterTheMaster_Pace:
	walk_left
	walk_left
	walk_right
	walk_right
	walk_left
	walk_left
	walk_right
	walk_right
	face_down
	step_end

EnterTheMaster_ApproachSiebold:
	walk_up
	step_end

gText_EnterTheMaster_MorningReady::
	.string "Morning. Ready to find this old dude?$"

gText_EnterTheMaster_AsReadyAs::
	.string "As ready as I'm going to be!$"

gText_EnterTheMaster_DaddySentAnother::
	.string "Daddy sent another care package, so if\n"
	.string "we stick together, I'll keep you healed\l"
	.string "up.$"

gText_EnterTheMaster_ThanksDad::
	.string "Thanks… dad?$"

gText_EnterTheMaster_HowDoYouThink::
	.string "How do you think my new Pokémon is\n"
	.string "faring? I'm curious to see how it\l"
	.string "integrates with the rest of my team.$"

gText_EnterTheMaster_YouKnow::
	.string "You know, I'm really sick of\n"
	.string "TeamRocket's shit. Its their fault\l"
	.string "we're stuck in this stupid forest.$"

gText_EnterTheMaster_IThoughtGymLeaders::
	.string "I thought SanFran's Gym Leaders would\n"
	.string "be tougher. I wonder how their old Elite\l"
	.string "Four stacks up to Unova's?$"

gText_EnterTheMaster_DoYouThinkTheyre::
	.string "Do you think they're going to be worth\n"
	.string "all this hassle?$"

gText_EnterTheMaster_TiredAlready::
	.string "Tired already? I'll be waiting here.$"

gText_EnterTheMaster_IDontThinkTheres::
	.string "I don't think there's anywhere else for\n"
	.string "them to be… they've gotta be in here.$"

gText_EnterTheMaster_YouThinkTheyve::
	.string "You think they've just been alone in\n"
	.string "here, waiting for us for Dialga knows\l"
	.string "how long?$"

gText_EnterTheMaster_TheyreGettingPaid::
	.string "They're getting paid.$"

gText_EnterTheMaster_WelcomeTo::
	.string "Bianca! {PLAYER}! Welcome to\n"
	.string "Muirwoods. Excellent work so far!$"

gText_EnterTheMaster_ThanksYoure::
	.string "Thanks. You're Siebold?$"

gText_EnterTheMaster_AndMyNotebook::
	.string "Yeah! And my notebook?$"

gText_EnterTheMaster_GettingThemToBattle::
	.string "I hope Pokémon 1 and Pokémon 2 in\n"
	.string "Robinwilltunnel weren't too much\l"
	.string "trouble. Getting them to battle\l"
	.string "without my direct commands was\l"
	.string "certainly a challenge.$"

gText_EnterTheMaster_IsThatWhatYoure::
	.string "Is that what you're teaching us?\n"
	.string "Battling with our eyes closed? Sounds\l"
	.string "useful.$"

gText_EnterTheMaster_EveryClientAlways::
	.string "Every client always sends me a\n"
	.string "smartass… Let's get started.$"

gText_EnterTheMaster_AreEitherOfYou::
	.string "Are either of you familiar with the\n"
	.string "Scott's Trainer Theory?$"

gText_EnterTheMaster_YeahThatsTheBattleFrontier::
	.string "Yeah, that's the Battle Frontier guy,\n"
	.string "right?$"

gText_EnterTheMaster_HmmTheSmartass::
	.string "Hmm, the smartass actually knows\n"
	.string "something!$"

gText_EnterTheMaster_OhDoesEachPart::
	.string "Oh… does each part of this training map\n"
	.string "to each of those principles?$"

gText_EnterTheMaster_SorryDidntGoTo::
	.string "Sorry, didn't go to Battle prep school.\n"
	.string "Who is Scott and what are these\l"
	.string "principles?$"

gText_EnterTheMaster_ScottIsTheFounder::
	.string "Scott is the founder of an amusement\n"
	.string "park in Hoenn. Its attractions were\l"
	.string "designed to test what Scott believed\l"
	.string "were the qualities that all Master\l"
	.string "trainers require…$"

gText_EnterTheMaster_OneEternity::
	.string "One eternity later…$"

gText_EnterTheMaster_AndSoConcludes::
	.string "…and so concludes my theory on how\n"
	.string "your silly little tests correspond with\l"
	.string "each of Scott's 7 principles.$"

gText_EnterTheMaster_SortaKindaNotReally::
	.string "…sorta, kinda, not really. If you think\n"
	.string "life is going to map one to one like\l"
	.string "that for you, you've got a rude\l"
	.string "awakening ahead.$"

gText_EnterTheMaster_Oh::
	.string "…Oh.$"

gText_EnterTheMaster_SoWhatsNext::
	.string "So what's next?$"

gText_EnterTheMaster_WellUntilNSFigures::
	.string "Well, until NS figures out what these\n"
	.string "quests are, just leave and come back.$"
