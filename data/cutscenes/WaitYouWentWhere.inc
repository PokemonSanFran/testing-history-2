WaitYouWentWhere_ObjectSetUp::
	special GetNumberOfBadges
	compare VAR_TEMP_0, 7
	goto_if_lt WaitYouWentWhere_ObjectSetUp_5
WaitYouWentWhere_ObjectSetUp_3:
	setflag FLAG_HIDE_WAITYOUWENTWHERE_PSFBADADMIN
WaitYouWentWhere_ObjectSetUp_1:
	end

WaitYouWentWhere_ObjectSetUp_2:
	clearflag FLAG_HIDE_WAITYOUWENTWHERE_PSFBADADMIN
	goto WaitYouWentWhere_ObjectSetUp_1

WaitYouWentWhere_ObjectSetUp_4:
	compare VAR_ROUTE104_STATE, 1
	goto_if_lt WaitYouWentWhere_ObjectSetUp_2
	goto WaitYouWentWhere_ObjectSetUp_3

WaitYouWentWhere_ObjectSetUp_5:
	compare VAR_PSFCAVE7_STATE, 2
	goto_if_eq WaitYouWentWhere_ObjectSetUp_4
	goto WaitYouWentWhere_ObjectSetUp_3


WaitYouWentWhere_PlayerSetUp::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_1, 1
	goto_if_eq WaitYouWentWhere_PlayerSetUp_1
	compare VAR_TEMP_0, 40
	goto_if_eq WaitYouWentWhere_PlayerSetUp_2
	return

WaitYouWentWhere_PlayerSetUp_1:
	applymovement OBJ_EVENT_ID_PLAYER, WaitYouWentWhere_PlayerFromSouth
	return

WaitYouWentWhere_PlayerSetUp_2:
	applymovement OBJ_EVENT_ID_PLAYER, WaitYouWentWhere_PlayerFromWest
	return


WaitYouWentWhere_FirstInteract_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_WelcomeBackFrom, MSGBOX_NPC
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_YeahThanksFor
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_IHaveSomeBusiness
	closemessage
	callnative ClearMugshot
	call WaitYouWentWhere_PlayerSetUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Player_WaitYouWentWhere_WalkWest
	applymovement 1, Psfbadadmin_WaitYouWentWhere_WalkWest
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_IActuallyJustGot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_ThePassWeGave
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_GaveMeAPass
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_WhatAPainIn
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_YeahIveSeenThem
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_YesBeforeWeRevamped
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_OrreHasALot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_NoOffense
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_WaitYouWentWhere_GoingThisWay
	callnative ClearMugshot
	closemessage
	applymovement 1, WaitYouWentWhere_WalkUpHill
	waitmovement 0
	removeobject 1
	releaseall
	setvar VAR_ROUTE104_STATE, 1
	end


WaitYouWentWhere_PlayerFromSouth:
	walk_right
	walk_up
	face_left
	step_end

WaitYouWentWhere_PlayerFromWest:
	walk_down
	walk_right
	walk_right
	walk_up
	face_left
	step_end

Player_WaitYouWentWhere_WalkWest:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Psfbadadmin_WaitYouWentWhere_WalkWest:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_right
	step_end

WaitYouWentWhere_WalkUpHill:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WaitYouWentWhere_WalkSouth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_WaitYouWentWhere_WelcomeBackFrom::
	.string "Ah {PLAYER}, welcome back from\n"
	.string "Psfcity11! I hear you defeated\l"
	.string "Psfleader4, as expected from you.$"

gText_WaitYouWentWhere_YeahThanksFor::
	.string "Yeah, thanks for your help. Where are\n"
	.string "you going?$"

gText_WaitYouWentWhere_IHaveSomeBusiness::
	.string "I have some business to attend to in\n"
	.string "Psfcity12. I assume you're heading\l"
	.string "west, let's walk together. How has your\l"
	.string "training been?$"

gText_WaitYouWentWhere_IActuallyJustGot::
	.string "I actually just got back from Psfcave7,\n"
	.string "which was really interesting.$"

gText_WaitYouWentWhere_ThePassWeGave::
	.string "The pass we gave you doesn't let you go\n"
	.string "there…$"

gText_WaitYouWentWhere_GaveMeAPass::
	.string "Yeah, a Psfgoodteam member gave me a\n"
	.string "pass as an apology. It's complicated.$"

gText_WaitYouWentWhere_WhatAPainIn::
	.string "Uh, Psfgoodteam, what a pain in my ass.\n"
	.string "They're an organization created from\l"
	.string "the base of prisoner sympathizers, and\l"
	.string "they've branded themselves as total\l"
	.string "anti-establishment anarchists. They\l"
	.string "make a lot of noise for no real reason.$"

gText_WaitYouWentWhere_YeahIveSeenThem::
	.string "Yeah, I've seen them around. What's the\n"
	.string "deal with the Elite Four? Psfregion1\l"
	.string "used to have one?$"

gText_WaitYouWentWhere_YesBeforeWeRevamped::
	.string "Yes, before we revamped their League\n"
	.string "structure. They used to be the\l"
	.string "strongest Trainers in Psfregion1, but\l"
	.string "we hope that trainers like you and\l"
	.string "Psftransrival will be able to outshine\l"
	.string "them soon. Ugh, and finally, we're done\l"
	.string "dealing with Double Battles… what a\l"
	.string "mess.$"

gText_WaitYouWentWhere_OrreHasALot::
	.string "Orre has a lot of double battles!\n"
	.string "They're not that bad.$"

gText_WaitYouWentWhere_NoOffense::
	.string "No offense - I'm sure they're fine, but\n"
	.string "certainly not fit for a world-class\l"
	.string "League!$"

gText_WaitYouWentWhere_GoingThisWay::
	.string "Well, time to hike this miserable hill.\n"
	.string "I'll save you the hassle. Stay out of\l"
	.string "trouble, okay?$"
