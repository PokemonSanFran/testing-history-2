TheStrikeStrikesBack_ObjectSetup_Script::
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFGOODTEAM
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFBADADMIN
	hideobjectat 14, MAP_PSFROUTE22
	return


TheStrikeStrikesBack_CrowdFacesNorth_Script::
	playse SE_PIN
	applymovement 6, TheStrikeStrikesBack_FaceNorth
	applymovement 7, Common_Movement_FaceUp
	applymovement 8, TheStrikeStrikesBack_FaceNorth
	applymovement 9, Common_Movement_FaceUp
	applymovement 10, Common_Movement_FaceUp
	applymovement 11, TheStrikeStrikesBack_FaceNorth
	applymovement 1, TheStrikeStrikesBack_FaceNorth
	applymovement 2, TheStrikeStrikesBack_FaceNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return


TheStrikeStrikesBack_FlyIntoFrame::
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	waitfieldeffect FLDEFF_NPCFLY_OUT
	addobject 1
	return


TheStrikeStrikesBack_FlyOutFrame::
	applymovement 1, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject 1
	applymovement OBJ_EVENT_ID_PLAYER, TurnInivisible
	waitfieldeffect FLDEFF_NPCFLY_OUT
	setflag FLAG_SPAWN_INVISIBLE
	warpsilent MAP_PSFROUTE22, 255, 21, 25
	setflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFTRANSRIVAL
	return


TheStrikeStrikesBack_PhoneCall_Dialogue::
	lockall
	setvar VAR_ROUTE110_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	playse SE_POKENAV_CALL
	waitse
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_HelloPlayer
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_OhHi
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_IKnowImLate
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_CongratsOnYourFeat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_ThankYou
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_CutToTheChase
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_SureRightNow
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_AsSoonAsYouCan
	callnative ClearMugshot
	closemessage
	playse SE_POKENAV_HANG_UP
	waitse
	msgbox gText_TheStrikeStrikesBack_DoYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq TheStrikeStrikesBack_PhoneCall_Dialogue_1
	closemessage
	warpsilent MAP_PSFROUTE22, 255, 21, 25
	return

TheStrikeStrikesBack_PhoneCall_Dialogue_1:
	closemessage
	return


TheStrikeStrikesBack_Congrats_Dialogue::
	lockall
	setvar VAR_ROUTE110_STATE, 1
	clearflag FLAG_HIDE_ROUTE_128_STEVEN
	call TheStrikeStrikesBack_FlyIntoFrame
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_CongratsOnAll
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_DidYouFlyAll
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_AskedMeToPick
	closemessage
	callnative ClearMugshot
	call TheStrikeStrikesBack_FlyOutFrame
	delay 100
	goto TheStrikeStrikesBack_Intro_Dialogue
	return


TheStrikeStrikesBack_Intro_Dialogue::
	setvar VAR_ROUTE110_STATE, 2
	call TheStrikeStrikesBack_FlyIntoFrame
	clearflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFTRANSRIVAL
	applymovement OBJ_EVENT_ID_PLAYER, TurnVisible
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_AndCongratulations
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_ISawThemOn
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_WellHeresTheProblem
	callnative ClearMugshot
	closemessage
	applymovement 3, TheStrikeStrikesBack_WalkIntoFrame
	applymovement 4, TheStrikeStrikesBack_WalkIntoFrame
	applymovement 5, TheStrikeStrikesBack_WalkIntoFrame
	waitmovement 0
	call TheStrikeStrikesBack_CrowdFacesNorth_Script
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_MyNameIs
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_WeAreFighting
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_TheCityDoubles
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_ManagementTriples
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_TheCityQuadruples
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_TheseDemandsAreMore
	callnative ClearMugshot
	closemessage
	applymovement 3, TheStrikeStrikesBack_WalkOutFrame
	applymovement 4, TheStrikeStrikesBack_WalkOutFrame
	applymovement 5, TheStrikeStrikesBack_WalkOutFrame
	applymovement 1, Common_Movement_FaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 9, Common_Movement_FaceDown
	applymovement 7, Common_Movement_FaceLeft
	applymovement 6, Common_Movement_FaceRight
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_SighOfCourse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_WaitWhatThatsInsane
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_AgreedAndThats
	compare VAR_ROUTE105_STATE, 0
	goto_if_gt TheStrikeStrikesBack_Intro_Dialogue_2
TheStrikeStrikesBack_Intro_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_AgitatedWildGarbodor
	callnative ClearMugshot
	closemessage
	applymovement 2, TheStrikeStrikesBack_WalkOutFrame
	waitmovement 0
	applymovement 1, TheStrikeStrikesBack_GoToPlayer
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_TheStrikeStrikesBack_IllBeInThere
	callnative ClearMugshot
	closemessage
	applymovement 1, TheStrikeStrikesBack_WalkOutFrame
	waitmovement 0
	call TheStrikeStrikesBack_ObjectCleanup_Script
	releaseall
	end

TheStrikeStrikesBack_Intro_Dialogue_2:
	msgbox gText_TheStrikeStrikesBack_ThePoliceAreWorking
	goto TheStrikeStrikesBack_Intro_Dialogue_1


TheStrikeStrikesBack_ObjectCleanup_Script::
	setflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFGOODTEAM
	setflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFTRANSRIVAL
	setflag FLAG_HIDE_THESTRIKESTRIKESBACK_PSFBADADMIN
	removeobject 2
	removeobject 1
	removeobject 3
	removeobject 4
	removeobject 5
	return


TheStrikeStrikesBack_FaceNorth:
	emote_exclamation_mark
	face_up
	step_end

TheStrikeStrikesBack_WalkIntoFrame:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

TheStrikeStrikesBack_WalkOutFrame:
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

TurnInivisible:
	set_invisible
	step_end

TurnVisible:
	set_visible
	step_end

TheStrikeStrikesBack_GoToPlayer:
	walk_left
	face_up
	step_end

gText_TheStrikeStrikesBack_CongratsOnAll::
	.string "Hey {PLAYER}. Congrats on all eight\n"
	.string "badges! Didn't think you had it in you.$"

gText_TheStrikeStrikesBack_DidYouFlyAll::
	.string "…thanks, I think. Did you fly all the way\n"
	.string "here to tell me that?$"

gText_TheStrikeStrikesBack_AskedMeToPick::
	.string "Nah. Psfbadadmin asked me to pick you\n"
	.string "up. Turns out they need our help. Let's\l"
	.string "go.$"

gText_TheStrikeStrikesBack_AndCongratulations::
	.string "Thanks, Psftransrival! And\n"
	.string "congratulations to you, {PLAYER}.\l"
	.string "You're caught up on the strikes, right?$"

gText_TheStrikeStrikesBack_ISawThemOn::
	.string "Yeah, I saw them on the news. Why are we\n"
	.string "involved though?$"

gText_TheStrikeStrikesBack_WellHeresTheProblem::
	.string "Well, here's the problem. We - ! oh Lord.$"

gText_TheStrikeStrikesBack_MyNameIs::
	.string "My name is Psfgoodboss, and I am the\n"
	.string "leader of Psfgoodteam.$"

gText_TheStrikeStrikesBack_WeAreFighting::
	.string "We are fighting alongside the\n"
	.string "construction workers here, and we are\l"
	.string "hoping to come to a reasonable\l"
	.string "conclusion for all. We are requesting,\l"
	.string "no, DEMANDING:$"

gText_TheStrikeStrikesBack_TheCityDoubles::
	.string "1. The city doubles the pay of these\n"
	.string "workers.$"

gText_TheStrikeStrikesBack_ManagementTriples::
	.string "2. Management triples their safety and\n"
	.string "anti-harassment certifications.$"

gText_TheStrikeStrikesBack_TheCityQuadruples::
	.string "3. The city quadruples the workers'\n"
	.string "break times.$"

gText_TheStrikeStrikesBack_TheseDemandsAreMore::
	.string "These demands are more than\n"
	.string "reasonable, and the hard workers will\l"
	.string "continue to strike until they are\l"
	.string "treated fairly and equitably.$"

gText_TheStrikeStrikesBack_SighOfCourse::
	.string "Sigh, of course. Well, they're the reason\n"
	.string "we brought you here. We've received\l"
	.string "intel that Psfgoodteam is planning on\l"
	.string "using exploding Pokemon to bring down\l"
	.string "the construction site. The strike is\l"
	.string "just a distraction.$"

gText_TheStrikeStrikesBack_WaitWhatThatsInsane::
	.string "Wait, what? That's insane!$"

gText_TheStrikeStrikesBack_AgreedAndThats::
	.string "Agreed, and that's why we need you two\n"
	.string "while Psfbadboss and I work on a\l"
	.string "peaceful solution.$"

gText_TheStrikeStrikesBack_ThePoliceAreWorking::
	.string "The police are working to make sure the\n"
	.string "protests remain civil but we don't want\l"
	.string "a repeat of the riots in Psfcity12.$"

gText_TheStrikeStrikesBack_AgitatedWildGarbodor::
	.string "We think Psfgoodteam agitated wild\n"
	.string "Garbodor, and we need you to capture\l"
	.string "or knock them out while Psfbadboss and\l"
	.string "I negotiate with Psfgoodboss. Time is\l"
	.string "of the essence!$"

gText_TheStrikeStrikesBack_IllBeInThere::
	.string "{PLAYER}, I'll be in there when you're\n"
	.string "ready.$"

gText_TheStrikeStrikesBack_HelloPlayer::
	.string "Hello {PLAYER}!$"

gText_TheStrikeStrikesBack_OhHi::
	.string "Psfbadboss! Aren't you busy...?$"

gText_TheStrikeStrikesBack_IKnowImLate::
	.string "So busy in fact, that I'm late in\n"
	.string "congratulating you. I hear you've got\l"
	.string "all eight badges!$"

gText_TheStrikeStrikesBack_CongratsOnYourFeat::
	.string "Nonsense, I'm never too busy to\n"
	.string "congratulate you on all eight badges!$"

gText_TheStrikeStrikesBack_ThankYou::
	.string "Heh, thanks! Means a lot.$"

gText_TheStrikeStrikesBack_CutToTheChase::
	.string "You're right though, we're both about to\n"
	.string "be very busy. I'll cut to the chase.\l"
	.string "Could you head down to Psfroute22?\l"
	.string "Psfbadadmin will meet you there and\l"
	.string "explain everything.$"

gText_TheStrikeStrikesBack_SureRightNow::
	.string "Sure. Right now?$"

gText_TheStrikeStrikesBack_AsSoonAsYouCan::
	.string "As soon as you can.$"

gText_TheStrikeStrikesBack_DoYouWant::
	.string "Do you want to go to Psfroute22?$"
