OldAssholeAppears_WalktoBianca_Script::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 12
	goto_if_eq OldAssholeAppears_WalktoBianca_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, OldAssholeAppears_WalkWesttoBianca_Movement
OldAssholeAppears_WalktoBianca_Script_1:
	waitmovement 0
	goto OldAssholeAppears_Intro_Dialogue
	return

OldAssholeAppears_WalktoBianca_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, OldAssholeAppears_WalkNorthtoBianca_Movement
	goto OldAssholeAppears_WalktoBianca_Script_1


OldAssholeAppears_Intro_Dialogue::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	applymovement 1, Common_Movement_FaceDown
	msgbox gText_OldAssholeAppears_StandingOnVolcano
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_ImSorryWhat
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_RegionCloseFaultline
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_DontKnowMagical
	goto OldAssholeAppears_HealPlayer_Dialogue
	return


OldAssholeAppears_HealPlayer_Dialogue::
	setvar VAR_LOMBARDSTREET_STATE, NOT_SEEN_BIANCA_LOMBARD
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_IllHealYou
	playse SE_USE_ITEM
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_OhUhThanks
	special HealPlayerParty
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_DaddyShippedFullRestores
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto OldAssholeAppears_StartBattle_Script
	return


OldAssholeAppears_Interact_Script::
	lockall
	faceplayer
	goto OldAssholeAppears_StartBattle_Script
	return


OldAssholeAppears_StartBattle_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_HowFarBehind
	closemessage
	callnative ClearMugshot
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_103_MUDKIP, gText_OldAssholeAppers_ImStartingToQuestion
	goto OldAssholeAppears_GiveCorviknightCard_Script
	return


OldAssholeAppears_GiveCorviknightCard_Script::
	lockall
	applymovement 1, Common_Movement_FacePlayer
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_TakingThisAllSeriously
	callnative ClearMugshot
	giveitem ITEM_SS_TICKET
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_FamiliarWith, MSGBOX_YESNO
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	compare VAR_RESULT, 1
	goto_if_eq OldAssholeAppears_GiveCorviknightCard_Script_2
	msgbox gText_OldAssholeAppears_LetsYouCallARide
OldAssholeAppears_GiveCorviknightCard_Script_1:
	msgbox gText_OldAssholeAppears_LetsYouUse
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_YouveBeenSuperNice
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_OldAssholeAppears_NowWereEven
	callnative ClearMugshot
	closemessage
	goto OldAssholeAppears_BiancaExit_Script
	return

OldAssholeAppears_GiveCorviknightCard_Script_2:
	msgbox gText_OldAssholeAppears_ThoughtSo
	goto OldAssholeAppears_GiveCorviknightCard_Script_1


OldAssholeAppears_BiancaExit_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	applymovement 1, OldAssholeAppears_BiancaExit_Movement
	waitmovement 0
	fadedefaultbgm
	removeobject 1
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


OldAssholeAppears_WalkNorthtoBianca_Movement:
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_up
	step_end

OldAssholeAppears_WalkWesttoBianca_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_up
	step_end

OldAssholeAppears_BiancaExit_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

gText_OldAssholeAppears_StandingOnVolcano::
	.string "You know, we're probably standing on a\n"
	.string "volcano, {PLAYER}.$"

gText_OldAssholeAppears_ImSorryWhat::
	.string "I'm sorry, what?$"

gText_OldAssholeAppears_RegionCloseFaultline::
	.string "Or, what used to be one at least. Turns\n"
	.string "out this region is close to a tectonic\l"
	.string "faultline, which when they shift, make\l"
	.string "a bunch of tiny volcanoes, all over the\l"
	.string "place. It's kind of magical when you\l"
	.string "think about it, huh?$"

gText_OldAssholeAppears_DontKnowMagical::
	.string "I don't know about magical, but it's\n"
	.string "pretty neat, yeah!$"

gText_OldAssholeAppears_IllHealYou::
	.string "Tell you what - I do have something\n"
	.string "magical for you, but you'll have to beat\l"
	.string "me for it first! Here, I'll heal your\l"
	.string "Pokémon for you.$"

gText_OldAssholeAppears_OhUhThanks::
	.string "Oh uh, thanks!$"

gText_OldAssholeAppears_DaddyShippedFullRestores::
	.string "Not me, Daddy shipped over those Full\n"
	.string "Restores.$"

gText_OldAssholeAppears_HowFarBehind::
	.string "Now, let's see how far behind you are!$"

gText_OldAssholeAppers_ImStartingToQuestion::
	.string "I'm starting to question all those\n"
	.string "years at the private battle academy...$"

gText_OldAssholeAppears_TakingThisAllSeriously::
	.string "Good to see you're taking this all\n"
	.string "seriously, {PLAYER}! My rival should\l"
	.string "be strong to keep me sharp! Well, true\l"
	.string "to my word...$"

gText_OldAssholeAppears_FamiliarWith::
	.string "Are you familiar with Uber?$"

gText_OldAssholeAppears_ThoughtSo::
	.string "Thought so. They're everywhere, right?$"

gText_OldAssholeAppears_LetsYouCallARide::
	.string "Don't have it in Orre? Uber lets you call\n"
	.string "a ride from anywhere to anywhere else\l"
	.string "that you've been.$"

gText_OldAssholeAppears_LetsYouUse::
	.string "That card lets you use Uber for free! I\n"
	.string "went to the Salesforcetower, and the\l"
	.string "League Commissioner gave me these for\l"
	.string "being the first Challenger to visit! It\l"
	.string "also lets you use the Subway System\l"
	.string "for free, but I think I'll stick to Uber.\l"
	.string "Less homeless people to deal with, you\l"
	.string "know?$"

gText_OldAssholeAppears_YouveBeenSuperNice::
	.string "Thanks! You've been super nice today!$"

gText_OldAssholeAppears_NowWereEven::
	.string "Now we're even after I ditched\n"
	.string "breakfast. All right, time to go\l"
	.string "challenge the Fortpoint Gym. So glad\l"
	.string "Daddy sent me these Go-Goggles,\l"
	.string "because they're impossible to find new.\l"
	.string "And like hell I'm gonna get one from the\l"
	.string "locals...$"
