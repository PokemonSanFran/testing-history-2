YoungPadawan_Intro_Dialogue::
	lock
	clearflag FLAG_TEMP_2
	addobject 9
	playbgm MUS_ENCOUNTER_ELITE_FOUR, TRUE
	applymovement 9, YoungPadawan_GetOffBoat
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_WowYouLookTired
	call Common_EventScript_OutOfCenterPartyHeal
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_DidTheChallenge
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_ThankYou
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_DontMentionIt
	callnative ClearMugshot
	closemessage
	applymovement 9, YoungPadawan_LookAtOcean
	applymovement OBJ_EVENT_ID_PLAYER, YoungPadawan_StepDownWalkBeside
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_LearnALot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_TheStoryOfTheIsland
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_ThatQuakeWasOne
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_HistoryBooksAreCrazy
	callnative ClearMugshot
	closemessage
	applymovement 9, YoungPadawan_WalkBackToPlayer
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_MakesYouWonder
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_MakesSenseYeah
	goto YoungPadawan_StartBattle_Script
	return


YoungPadawan_StartBattle_Script::
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_YouveGotAGoodSpirit
	callnative ClearMugshot
	closemessage
	trainerbattle_continue_after_lose TRAINER_SIDNEY, gText_YoungPadawan_DontBeatYourselfUp
	goto YoungPadawan_PostBattle_Dialogue
	return


YoungPadawan_PostBattle_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	checktrainerflag TRAINER_SIDNEY
	goto_if 1, YoungPadawan_PostBattle_Dialogue_2
	special HealPlayerParty
	msgbox gText_YoungPadawan_KeepTraining
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_IveNeverBattled
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_YeahTotally
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_UntilThenHeres
	closemessage
	callnative ClearMugshot
YoungPadawan_PostBattle_Dialogue_1:
	giveitem ITEM_GO_GOGGLES, 1
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_ThoseCanBeTough
	callnative ClearMugshot
	closemessage
	applymovement 9, YoungPadawan_WalkUpStairs
	fadedefaultbgm
	applymovement OBJ_EVENT_ID_PLAYER, YoungPadawan_GetOutOfWay
	waitmovement 0
	removeobject 9
	addvar VAR_ALCATRAZ_STATE, 1
	addvar VAR_ALCATRAZ_EXHIBIT_STATE, 1
	release
	end

YoungPadawan_PostBattle_Dialogue_2:
	msgbox gText_YoungPadawan_DidYouHack
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YoungPadawan_GotItYouWon
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YoungPadawan_KeepItSecretToo
	callnative ClearMugshot
	closemessage
	giveitem ITEM_POWER_ANKLET, 1
	giveitem ITEM_POWER_BAND, 1
	giveitem ITEM_POWER_BRACER, 1
	giveitem ITEM_POWER_LENS, 1
	giveitem ITEM_POWER_WEIGHT, 1
	giveitem ITEM_POWER_BELT, 1
	goto YoungPadawan_PostBattle_Dialogue_1


YoungPadawan_GetOffBoat:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YoungPadawan_StepDownWalkBeside:
	walk_down
	face_left
	step_end

YoungPadawan_LookAtOcean:
	walk_left
	step_end

YoungPadawan_WalkBackToPlayer:
	walk_down
	walk_right
	face_up
	step_end

YoungPadawan_WalkUpStairs:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YoungPadawan_GetOutOfWay:
	walk_left
	delay_16
	walk_right
	face_up
	step_end

gText_YoungPadawan_WowYouLookTired::
	.string "Wow, you look tired! Let me help.$"

gText_YoungPadawan_DidTheChallenge::
	.string "Did the challenge kick your ass? Those\n"
	.string "kids are tough.$"

gText_YoungPadawan_ThankYou::
	.string "Thank you!$"

gText_YoungPadawan_DontMentionIt::
	.string "Don't mention it.$"

gText_YoungPadawan_LearnALot::
	.string "Learn a lot up there?$"

gText_YoungPadawan_TheStoryOfTheIsland::
	.string "The story of the island is crazy. And I\n"
	.string "didn't realize the earthquakes here\l"
	.string "could be that vicious.$"

gText_YoungPadawan_ThatQuakeWasOne::
	.string "That quake was one for the history\n"
	.string "books! Shook me to my core.$"

gText_YoungPadawan_HistoryBooksAreCrazy::
	.string "History books are crazy. Losers don't\n"
	.string "get a pre-release copy to leave their\l"
	.string "edits in the margins... the winners just\l"
	.string "say whatever they want, and everybody\l"
	.string "has to deal with it.$"

gText_YoungPadawan_MakesYouWonder::
	.string "Makes you wonder how committed to\n"
	.string "accuracy the winners are. Old geezers\l"
	.string "like me, who were around for the\l"
	.string "history in the making, have a\l"
	.string "responsibility to set the record\l"
	.string "straight. Gotta make sure the truth\l"
	.string "doesn't get lost, you know?$"

gText_YoungPadawan_MakesSenseYeah::
	.string "Makes sense, yeah. But the government\n"
	.string "doesn't have any reason to lie, which is\l"
	.string "a relief.$"

gText_YoungPadawan_YouveGotAGoodSpirit::
	.string "Hah! You got a good spirit. Let's see\n"
	.string "how long you can hold up against your\l"
	.string "elders!$"

gText_YoungPadawan_DidIUnderestimate::
	.string "Did I underestimate you?$"

gText_YoungPadawan_KidYoureSomethingElse::
	.string "Kid, you're something else! But it ends\n"
	.string "here.$"

gText_YoungPadawan_DontBeatYourselfUp::
	.string "Heh, don't beat yourself up. I got at\n"
	.string "least 50 years on ya.$"

gText_YoungPadawan_ThisAintHowItWas::
	.string "This ain't how it was supposed to go!$"

gText_YoungPadawan_DidYouHack::
	.string "Did you hack the Matrix? Maybe you got\n"
	.string "REAL lucky on a randomizer run? ... We're\l"
	.string "gonna pretend I won, okay?$"

gText_YoungPadawan_GotItYouWon::
	.string "Haha got it, you won.$"

gText_YoungPadawan_KeepItSecretToo::
	.string "Keep it secret too. Here, take these.$"

gText_YoungPadawan_KeepTraining::
	.string "Keep training! Once you learn a little\n"
	.string "bit more about the world, let's battle\l"
	.string "again.$"

gText_YoungPadawan_IveNeverBattled::
	.string "(I've never battled anybody so strong!)$"

gText_YoungPadawan_YeahTotally::
	.string "Yeah, totally!$"

gText_YoungPadawan_UntilThenHeres::
	.string "Until then, here's a consolation prize.$"

gText_YoungPadawan_ThoseCanBeTough::
	.string "Those can be tough to get if you're not\n"
	.string "from here. Good luck with the rest of\l"
	.string "your challenge, {PLAYER}.$"
