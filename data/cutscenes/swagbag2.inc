swagbag2_SetUp_Object_Script::
	setflag FLAG_TEMP_1
	return


swagbag2_OakWalkOutGym_Script::
	opendoor 10, 8
	waitdooranim
	clearflag FLAG_TEMP_1
	addobject 1
	applymovement 1, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, swagbag2_GetOutOfWay
	waitmovement 0
	closedoor 10, 8
	waitdooranim
	goto swagbag2_Intro_Dialogue
	return


swagbag2_Intro_Dialogue::
	playbgm MUS_RG_FOLLOW_ME, FALSE
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_ItWasAPleasure
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_ItsALot
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_SoundsLikeYouveRun
	applymovement 1, swagbag2_LookAwayAndBack
	waitmovement 0
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, swagbag2_Intro_Dialogue_1
	goto swagbag2_BringToCenter_Dialogue
	return

swagbag2_Intro_Dialogue_1:
	goto swagbag2_DiscussCosts_Dialogue
	return


swagbag2_DiscussCosts_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_IAssumeYouveAlready
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_TheyWereVeryHelpful
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_TheBreedingCenterStaff
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_TheBreedingCenterOffers
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_ThatsTooBad
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_HopefullyTheyllHaveIt
	callnative ClearMugshot
	goto swagbag2_Scene_End_Script
	return


swagbag2_BringToCenter_Dialogue::
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_HaveYouSeenThe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_NoShouldI
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_IveGotAFewMinutes
	callnative ClearMugshot
	closemessage
	applymovement 1, swagbag2_WalkToCenter
	applymovement OBJ_EVENT_ID_PLAYER, swagbag2_PlayerWalkToCenter
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_DontLetTheirDemeanor
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_WowThatsAwesome
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_YouShouldReallyTalk
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_swagbag2_IWillThanks
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_HappyToHelp
	applymovement 1, swagbag2_LookAwayAndBack
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_swagbag2_NowIveGottaRun
	callnative ClearMugshot
	goto swagbag2_Scene_End_Script
	return


swagbag2_Scene_End_Script::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, swagbag2_LetOakLeave
	applymovement 1, swagbag2_LeaveCity
	waitmovement 0
	removeobject 1
	addvar VAR_PSFCITY11_STATE, 1
	fadedefaultbgm
	release
	end


swagbag2_GetOutOfWay:
	walk_down
	face_up
	step_end

swagbag2_LookAwayAndBack:
	face_left
	delay_16
	delay_16
	face_down
	step_end

swagbag2_LeaveCity:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

swagbag2_WalkToCenter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_down
	step_end

swagbag2_PlayerWalkToCenter:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	face_up
	step_end

swagbag2_LetOakLeave:
	walk_right
	walk_up
	walk_left
	face_up
	step_end

gText_swagbag2_ItWasAPleasure::
	.string "Hello {PLAYER}! It was a pleasure\n"
	.string "seeing you at the Tower yesterday. How\l"
	.string "are you liking east SanFran?$"

gText_swagbag2_ItsALot::
	.string "...It's a lot. People are much less happy\n"
	.string "here than back on the mainland.$"

gText_swagbag2_SoundsLikeYouveRun::
	.string "Ah, sounds like you've run into\n"
	.string "TeamRocket a few times. Don't mind\l"
	.string "them, they don't represent all of us, I\l"
	.string "promise.$"

gText_swagbag2_IAssumeYouveAlready::
	.string "I assume you've already taken\n"
	.string "advantage of the Breeding Center in\l"
	.string "preparation for your battle with\l"
	.string "Morty?$"

gText_swagbag2_TheyWereVeryHelpful::
	.string "Yes! They were very helpful in helping\n"
	.string "me prepare.$"

gText_swagbag2_TheBreedingCenterStaff::
	.string "The Breeding Center staff mentioned\n"
	.string "some pretty high fees for using their\l"
	.string "services. How do ordinary Trainers\l"
	.string "afford it so they can take on Morty\l"
	.string "too?$"

gText_swagbag2_TheBreedingCenterOffers::
	.string "The Breeding Center offers its\n"
	.string "Bronze-tier services to all, at a\l"
	.string "significantly cheaper cost than that\l"
	.string "of your Gold membership. The school is\l"
	.string "working on a program to subsidize the\l"
	.string "Gold level for those involved in the\l"
	.string "League Challenge, they just... couldn't\l"
	.string "work out the details in time.$"

gText_swagbag2_ThatsTooBad::
	.string "Hmm... that's too bad. But awesome that\n"
	.string "they're working on it!$"

gText_swagbag2_HopefullyTheyllHaveIt::
	.string "Yes, hopefully they'll have it all\n"
	.string "smoothed out in the next year or ten.\l"
	.string "Now, I've gotta run. Good luck in there!$"

gText_swagbag2_HaveYouSeenThe::
	.string "Have you seen the Berkeley Breeding\n"
	.string "Center? Truly state of the art.$"

gText_swagbag2_NoShouldI::
	.string "No, should I?$"

gText_swagbag2_IveGotAFewMinutes::
	.string "I've got a few minutes, let me show you!$"

gText_swagbag2_DontLetTheirDemeanor::
	.string "Don't let their demeanor fool you -\n"
	.string "Morty is actually one of the leading\l"
	.string "experts in Pokémon Breeding and\l"
	.string "Battling. His entire team is bred using\l"
	.string "this facility's Gold tier experience.\l"
	.string "Access to those same services is a\l"
	.string "perk of being a part of the YC Program.$"

gText_swagbag2_WowThatsAwesome::
	.string "Wow, that's awesome!$"

gText_swagbag2_YouShouldReallyTalk::
	.string "You should really talk to the staff.\n"
	.string "They're obsessed with delighting\l"
	.string "Trainers like you, and I'm sure they're\l"
	.string "expecting you.$"

gText_swagbag2_IWillThanks::
	.string "I will. Thanks for the tip!$"

gText_swagbag2_HappyToHelp::
	.string "Happy to help!$"

gText_swagbag2_NowIveGottaRun::
	.string "Now, I've gotta run. Good luck in there!$"
