LetsFixThis_HideObjectHouse_Script::
	setflag FLAG_TEMP_1
	return


LetsFixThis_EliteVideo_Dialogue::
	lock
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	addobject 1
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_LetsFixThis_PeopleOf
	setvar VAR_0x8000, MUGSHOT_CAITLIN
	callnative DrawMugshot
	msgbox gText_LetsFixThis_WeWillBeGiving
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_LetsFixThis_WePrayTheGovernment
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_LetsFixThis_ButWeWillNot
	callnative ClearMugshot
	closemessage
	goto LetsFixThis_GetMessage_Dialogue
	return


LetsFixThis_GetMessage_Dialogue::
	applymovement 1, Common_Movement_FaceLeft
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	playse SE_POKENAV_CALL
	waitse
	pokenavcall LetsFixThis_GetMessage_Dialogue_Text_0
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFixThis_OhLooksLike
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFixThis_ComeCelebrate
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsFixThis_SoundsLikeIt
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFixThis_IMightGoALittle
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsFixThis_WhatreThey
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFixThis_TheyWantAllHands
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LetsFixThis_GuessIShould
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_LetsFixThis_ActuallyGivenHowMuch
	callnative ClearMugshot
	closemessage
	addvar VAR_ALCATRAZ_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_FORTREE_CITY_STATE, 1
	setflag FLAG_LOCKEDOUT_PLAYED
	applymovement 1, LetFixThis_WalkOutHouse
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	release
	end


LetFixThis_WalkOutHouse:
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

LetsFixThis_GetMessage_Dialogue_Text_0:
	.string "You have a new text.$"

gText_LetsFixThis_PeopleOf::
	.string "People of SanFran, your Elite Four has\n"
	.string "returned! We could not continue to\l"
	.string "stand by and watch these corporations\l"
	.string "destroy our home for profits.$"

gText_LetsFixThis_WeWillBeGiving::
	.string "We will be giving our full support and\n"
	.string "efforts to assisting TeamRocket in\l"
	.string "their mission to help the people of\l"
	.string "this region, alongside Champion\l"
	.string "{PLAYER} and our hometown hero,\l"
	.string "Archer.$"

gText_LetsFixThis_WePrayTheGovernment::
	.string "We pray the government of SanFran will\n"
	.string "open their eyes to the damage these\l"
	.string "companies have done…$"

gText_LetsFixThis_ButWeWillNot::
	.string "…but we will not sit quietly and wait for\n"
	.string "salvation to come to us! We must join\l"
	.string "together to save ourselves and fight\l"
	.string "to restore the glory of SanFran!$"

gText_LetsFixThis_OhLooksLike::
	.string "Oh, looks like we all got the same\n"
	.string "message… It's from the TeamRocket\l"
	.string "Event Bot.$"

gText_LetsFixThis_ComeCelebrate::
	.string "“Come celebrate the return of the Elite\n"
	.string "Four! Tonight, in the Oakland Packing\l"
	.string "District. Follow the music to the\l"
	.string "center warehouse!”$"

gText_LetsFixThis_SoundsLikeIt::
	.string "Sounds like it could be fun. You going\n"
	.string "to go?$"

gText_LetsFixThis_IMightGoALittle::
	.string "I might go a little later. I don’t love\n"
	.string "warehouse raves, but this is a special\l"
	.string "occasion, you know? The other reason\l"
	.string "I’m here is actually to tell you Ariana\l"
	.string "new initiatives.$"

gText_LetsFixThis_WhatreThey::
	.string "What’re they up to?$"

gText_LetsFixThis_TheyWantAllHands::
	.string "They want all hands on deck at\n"
	.string "Alcatraz. We’re converting it into a new\l"
	.string "base, and there’s gonna be a big meeting\l"
	.string "to talk about next steps.$"

gText_LetsFixThis_GuessIShould::
	.string "Guess I should go to that, right?$"

gText_LetsFixThis_ActuallyGivenHowMuch::
	.string "Actually, given how much work there is\n"
	.string "to get done, I don’t think it matters\l"
	.string "what you do first. I already said I’d\l"
	.string "head to Alcatraz. Either way, I’ll see\l"
	.string "you later?$"
