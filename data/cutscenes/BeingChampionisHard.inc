BeingChampionIsHard_ObjectCleanUp_Script::
	compare VAR_STORYLINE_STATE, STORY_WON_FINALS
	goto_if_ne BeingChampionIsHard_ObjectCleanUp_Script_2
BeingChampionIsHard_ObjectCleanUp_Script_1:
	return

BeingChampionIsHard_ObjectCleanUp_Script_2:
	setflag FLAG_TEMP_1
	goto BeingChampionIsHard_ObjectCleanUp_Script_1


BeingChampionIsHard_TimeSkip::
	fadescreen FADE_TO_BLACK
	msgbox gText_BeingChampionIsHard_OneMonthLater
	closemessage
	goto BeingChampionIsHard_PostTimeSkip
	return


BeingChampionIsHard_PostTimeSkip::
	playse SE_EXIT
	waitse
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, BeingChampionIsHard_WalkToOak
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_SighGoodMorning
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_GoodMorningChampion
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_ItsAlmostBeenAMonth
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_OfCourseNot
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_PleaseArceusLetItBe
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_YouveActuallyGotNothing
	closemessage
	callnative ClearMugshot
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_YouWereStarting
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_YouCouldTell
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_ThisIsOurFirst
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_WoWWhatToDo
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_YouShouldGoTo
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_ThatsWhereTheyFilm
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_ThereAlsoUsed
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_SoundsLikeItll
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_BeingChampionIsHard_ThePleasureIsAllOurs
	closemessage
	callnative ClearMugshot
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_EXIT
	removeobject 1
	setvar VAR_STORYLINE_STATE, STORY_EXPLORE_TREASUREISLAND
	releaseall
	end


BeingChampionIsHard_WalkToOak:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

gText_BeingChampionIsHard_OneMonthLater::
	.string "One month later…$"

gText_BeingChampionIsHard_SighGoodMorning::
	.string "sigh* Good morning Oak.$"

gText_BeingChampionIsHard_GoodMorningChampion::
	.string "Good morning Champion {PLAYER}.$"

gText_BeingChampionIsHard_ItsAlmostBeenAMonth::
	.string "It's almost been a month… doesn't\n"
	.string "saying that get old?$"

gText_BeingChampionIsHard_OfCourseNot::
	.string "Of course not. You've earned it! Now on\n"
	.string "the docket for today…$"

gText_BeingChampionIsHard_PleaseArceusLetItBe::
	.string "(Please Arceus, let it be an easy day. I\n"
	.string "swear it's been six interviews a day, an\l"
	.string "exhibition on every news network…\l"
	.string "being officially sponsored is great,\l"
	.string "but shit, I need a day off!)$"

gText_BeingChampionIsHard_YouveActuallyGotNothing::
	.string "You've actually got nothing.$"

gText_BeingChampionIsHard_YouWereStarting::
	.string "You were starting to look a little\n"
	.string "ragged, and a few sponsors complained.\l"
	.string "So we're giving you a few days off.$"

gText_BeingChampionIsHard_YouCouldTell::
	.string "eh heh, you could tell?$"

gText_BeingChampionIsHard_ThisIsOurFirst::
	.string "It's fine. This is our first time doing\n"
	.string "it, so perhaps we haven't really figured\l"
	.string "out striking a balance yet.$"

gText_BeingChampionIsHard_WoWWhatToDo::
	.string "Wow, what to do with my days off…$"

gText_BeingChampionIsHard_YouShouldGoTo::
	.string "You should go to Treasureisland! The\n"
	.string "construction on Psfroute30 and\l"
	.string "Psfroute25 has finally been completed,\l"
	.string "and its a fun place to sightsee.$"

gText_BeingChampionIsHard_ThatsWhereTheyFilm::
	.string "That's where they film movies, right?$"

gText_BeingChampionIsHard_ThereAlsoUsed::
	.string "Correct. There also used to be a Gym\n"
	.string "there, but it's been decommissioned.$"

gText_BeingChampionIsHard_SoundsLikeItll::
	.string "Sounds like it'll be cool. Thanks!$"

gText_BeingChampionIsHard_ThePleasureIsAllOurs::
	.string "My pleasure. I'll be checking in, but\n"
	.string "don't hesitate to reach out.$"
