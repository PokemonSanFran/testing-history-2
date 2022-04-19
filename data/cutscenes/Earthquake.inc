Earthquake_ThatNight_Dialogue::
	fadescreen FADE_TO_BLACK
	clearflag FLAG_TEMP_1
	addobject 1
	msgbox gText_Earthquake_ThatNight
	closemessage
	fadescreen FADE_FROM_BLACK
	playse SE_M_EARTHQUAKE
	setvar VAR_0x8004, 8
	setvar VAR_0x8005, 8
	setvar VAR_0x8006, 25
	setvar VAR_0x8007, 5
	special ShakeCamera
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement 1, Common_Movement_ExclamationMark
	waitstate
	playse SE_M_EARTHQUAKE
	special ShakeCamera
	delay 100
	waitstate
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_AreYouOkay
	callnative ClearMugshot
	closemessage
	msgbox gText_Earthquake_OhArceus
	msgbox gText_Earthquake_HelpMe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_ImFine
	callnative ClearMugshot
	closemessage
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ThePowersDead
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_HolyShit
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_OhYoureOkay
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_YeahWhyDidnt
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_CellTowersWere
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_SoundsLikeWere
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_ImGoingToMakeAnother
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_OfCourse
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_OkayThingsSeemToBe
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_WeveManagedToReestablish
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_IReally
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_AMessageFromThe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_ThatsATrap
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_WhatDoYouMean
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ShitWeNever
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_IGotAMessage
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_WaitWhat
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ItGetsCrazier
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_WeBattledBut
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_ThatDoesntMake
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ItsJustABunch
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_IDontThinkSo
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_HowCanYouTrust
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_TheSecondHalf
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Earthquake_SoSomebodyWantsUs
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_IThinkItsOn
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_FineTheThreeOfUs
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_Earthquake_ImGonnaHead
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_Earthquake_OkayWeve
	return


gText_Earthquake_ThatNight::
	.string "That night…$"

gText_Earthquake_AreYouOkay::
	.string "{PLAYER}, are you okay?$"

gText_Earthquake_OhArceus::
	.string "Oh Arceus, no!$"

gText_Earthquake_HelpMe::
	.string "Help me!$"

gText_Earthquake_ImFine::
	.string "I'm fine. Do you hear people screaming?$"

gText_Earthquake_ThePowersDead::
	.string "The power's dead. This… isn't good.$"

gText_Earthquake_HolyShit::
	.string "Holy shit.$"

gText_Earthquake_OhYoureOkay::
	.string "Oh Arceus, you're okay!$"

gText_Earthquake_YeahWhyDidnt::
	.string "Yeah, why didn't you just call?$"

gText_Earthquake_CellTowersWere::
	.string "Cell towers were destroyed… like\n"
	.string "everything else. Emily just told me\l"
	.string "that the docks are destroyed too.$"

gText_Earthquake_SoundsLikeWere::
	.string "Sounds like we're on our own.$"

gText_Earthquake_ImGoingToMakeAnother::
	.string "*sigh* I'm going to make another lap\n"
	.string "around Psfcity17 and see who else I\l"
	.string "can help, and I've asked other\l"
	.string "Psfgoodteam members to do the same.\l"
	.string "Could you two -$"

gText_Earthquake_OfCourse::
	.string "Of course. Let's meet back in the town\n"
	.string "center in a bit.$"

gText_Earthquake_OkayThingsSeemToBe::
	.string "Okay… things seem to be stabilizing. I\n"
	.string "should go meet Psfgoodadmin in the\l"
	.string "center of town.$"

gText_Earthquake_WeveManagedToReestablish::
	.string "We've managed to re-establish cell\n"
	.string "communications. The authorities claim\l"
	.string "they're on their way… Arceus knows how\l"
	.string "useful they'll actually be. Ina reports\l"
	.string "that our ranks suffered heavy\l"
	.string "casualties in the quake. Mark says our\l"
	.string "supply caches were also hit hard.$"

gText_Earthquake_IReally::
	.string "I really don't know how Psfgoodteam is\n"
	.string "going to hold up under this stress.$"

gText_Earthquake_AMessageFromThe::
	.string "A message from the Events account?\n"
	.string "Now?$"

gText_Earthquake_ThatsATrap::
	.string "That's a trap.$"

gText_Earthquake_WhatDoYouMean::
	.string "What do you mean? That doesn't make\n"
	.string "any sense.$"

gText_Earthquake_ShitWeNever::
	.string "Shit, we never got a chance to tell you.$"

gText_Earthquake_IGotAMessage::
	.string "Psfnativerival and I got a message from\n"
	.string "that account a few days ago. I went to\l"
	.string "a warehouse in Psfcity9, and\l"
	.string "Psfbadadmin2 trapped me there and\l"
	.string "attacked me.$"

gText_Earthquake_WaitWhat::
	.string "Wait what?$"

gText_Earthquake_ItGetsCrazier::
	.string "It gets crazier.$"

gText_Earthquake_WeBattledBut::
	.string "We battled but… he threw the battle.\n"
	.string "And then told me to run. It was like he\l"
	.string "wasn't even trying.$"

gText_Earthquake_ThatDoesntMake::
	.string "That doesn't make any sense. Okay,\n"
	.string "what's this message trying to do…$"

gText_Earthquake_ItsJustABunch::
	.string "“TM15@18030122@37.75030467013338,\n"
	.string "-122.3798002138461” It's just a bunch\l"
	.string "of nonsense. Maybe a glitch?$"

gText_Earthquake_IDontThinkSo::
	.string "…I don't think so. Psfbadadmin2 was\n"
	.string "really trying to help me. Even when I\l"
	.string "had dinner with him, their energy was\l"
	.string "different from everybody else in\l"
	.string "Psfbadguy.$"

gText_Earthquake_HowCanYouTrust::
	.string "How can you trust them after ALL of\n"
	.string "this?$"

gText_Earthquake_TheSecondHalf::
	.string "The second half of that message are\n"
	.string "GPS coordinates, if that counts for\l"
	.string "anything.$"

gText_Earthquake_SoSomebodyWantsUs::
	.string "So somebody wants us to go somewhere.\n"
	.string "Where is that?$"

gText_Earthquake_IThinkItsOn::
	.string "I think it's on the mainland, by\n"
	.string "Psfplace11. Let's take a small team to\l"
	.string "go investigate.$"

gText_Earthquake_FineTheThreeOfUs::
	.string "Fine. The three of us and maybe a few\n"
	.string "more… nobody can take all of us at\l"
	.string "once.$"

gText_Earthquake_ImGonnaHead::
	.string "I'm gonna head over to Psfplace11 right\n"
	.string "now. Want to come with me?$"

gText_Earthquake_OkayWeve::
	.string "Okay, we've all got our orders. Let's\n"
	.string "stay in touch.$"
