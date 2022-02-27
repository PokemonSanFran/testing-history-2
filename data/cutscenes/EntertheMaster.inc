EnterTheMaster_HideObject_Script::
	setflag FLAG_HIDE_PSFROUTE61_PSFTRANSRIVAL
	return


EnterTheMaster_Object_SetUp_Script::
	clearflag FLAG_HIDE_PSFROUTE61_PSFTRANSRIVAL
	return


EnterTheMaster_Interact_Script::
	lockall
	faceplayer
	goto EnterTheMaster_ReadyDialogue
	return


EnterTheMaster_WalkingTrigger_Script::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto EnterTheMaster_ReadyDialogue
	return


EnterTheMaster_ReadyDialogue::
	setvar VAR_ROUTE116_STATE, 1
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_MorningReady
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AsReadyAs
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_DaddySentAnother
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_ThanksDad
	callnative ClearMugshot
	closemessage
	applymovement 1, EnterTheMaster_WalkIntoWoods
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	releaseall
	end


EnterTheMaster_InteractFollower_Script::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_HowDoYouThink
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_YouKnow
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_IThoughtGymLeaders
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_DoYouThinkTheyre
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_TiredAlready
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_IDontThinkTheres
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_YouThinkTheyve
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_TheyreGettingPaid
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_WelcomeTo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_ThanksYoure
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AndMyNotebook
	msgbox gText_EnterTheMaster_YouGaveNotebook
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_GettingThemToBattle
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_IsThatWhatYoure
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_EveryClientAlways
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AreEitherOfYou
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_YeahThatsTheBattleFrontier
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_HmmTheSmartass
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_OhDoesEachPart
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_SorryDidntGoTo
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_ScottIsTheFounder
	msgbox gText_EnterTheMaster_OneEternity
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_AndSoConcludes
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_SortaKindaNotReally
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_Oh
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_SoWhatsNext
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_EnterTheMaster_WellUntilNSFigures
	return


EnterTheMaster_WalkIntoWoods:
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
	.string "Psfgoodteam's shit. Its their fault\l"
	.string "we're stuck in this stupid forest.$"

gText_EnterTheMaster_IThoughtGymLeaders::
	.string "I thought Psfregion1's Gym Leaders\n"
	.string "would be tougher. I wonder how their\l"
	.string "old Elite Four stacks up to Unova's?$"

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
	.string "Psftransrival! {PLAYER}! Welcome to\n"
	.string "Psfcave2. Excellent work so far!$"

gText_EnterTheMaster_ThanksYoure::
	.string "Thanks. You're Psfelite?$"

gText_EnterTheMaster_AndMyNotebook::
	.string "Yeah! And my notebook?$"

gText_EnterTheMaster_YouGaveNotebook::
	.string "You gave Psfelite3 the notebook.$"

gText_EnterTheMaster_GettingThemToBattle::
	.string "I hope Pokémon 1 and Pokémon 2 in\n"
	.string "Psfcave1 weren't too much trouble.\l"
	.string "Getting them to battle without my\l"
	.string "direct commands was certainly a\l"
	.string "challenge.$"

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
