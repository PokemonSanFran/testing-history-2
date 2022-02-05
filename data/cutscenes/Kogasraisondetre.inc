KogaRaisonDetre_InteractGuard_Dialogue::
	lockall
	msgbox gText_KogaRaisonDetre_HasBeenExpectingYou, MSGBOX_NPC
	releaseall
	end


KogaRaisonDetre_MoveIntoFoyer_Script::
	lockall
	applymovement 1, KogaRaisonDetre_ComeDownStairs
	delay 48
	applymovement 2, KogaRaisonDetre_ComeDownStairs
	waitmovement 0
	releaseall
	goto KogaRaisonDetre_KidsMeetPlayer_Dialogue
	end


KogaRaisonDetre_KidsMeetPlayer_Dialogue::
	msgbox gText_KogaRaisonDetre_YoureHereInTheFlesh
	msgbox gText_KogaRaisonDetre_YoureAFreak
	closemessage
	applymovement 1, KogaRaisonDetre_RunAroundPlayer
	msgbox gText_KogaRaisonDetre_MaybeTheyllSign
	msgbox gText_KogaRaisonDetre_ShutUp
	msgbox gText_KogaRaisonDetre_ShowUsHowYouTookDown
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_AllRightAllRight
	applymovement 3, KogaRaisonDetre_WalkIntoFoyer
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_YouDontWantToScare
	callnative ClearMugshot
	msgbox gText_KogaRaisonDetre_GonnaGoGet
	closemessage
	applymovement 1, KogaRaisonDetre_RunUpstairs
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_SorryAboutThat
	callnative ClearMugshot
	applymovement 2, Common_Movement_FaceLeft
	waitmovement 0
	msgbox gText_KogaRaisonDetre_OhMyGod
	closemessage
	applymovement 2, KogaRaisonDetre_RunUpstairs
	waitmovement 0
	removeobject 2
	removeobject 1
	goto KogaRaisonDetre_CityDiscussion_Dialogue
	end


KogaRaisonDetre_CityDiscussion_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, KogaRaisonDetre_WalkFromEntrance
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_YourHouseIsBeautiful
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ItWasImportantToMe
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ButItsHardToJustify
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IveBeenStruggling
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ItsBeenSaidThat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ToughToBeAround
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ICompletelyUnderstand
	closemessage
	applymovement 3, KogaRaisonDetre_WalkTowardsLiving
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ItsMuchEasier
	closemessage
	callnative ClearMugshot
	applymovement 3, KogaRaisonDetre_WalkToDining
	waitmovement 0
	setobjectxy 3, 3, 4
	setobjectxyperm 3, 3, 4
	turnobject 3, DIR_EAST
	releaseall
	end


KogaRaisonDetre_ComeSit_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ComeSit, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_ROUTE105_STATE, 2
	closemessage
	releaseall
	end


KogaRaisonDetre_InteractAtTable::
	lockall
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IPickedOut
	closemessage
	callnative ClearMugshot
	releaseall
	end


KogaRaisonDetre_Wine_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_HowMuch
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IJustRecentlyMet
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ThatLastPartIsImportant
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_WhatDoYouMean
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_DoYouKnowHow
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IsntItMostly
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_UsedToBe
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_WoahWaitBigger
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_PeopleLoveBattles
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_TheBroadcasts
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_MyKidsBeingObsessed
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_WereGoingToMake
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IBroughtYouHere
	callnative ClearMugshot
	closemessage
	playse SE_DING_DONG
	waitfanfare
	msgbox gText_KogaRaisonDetre_DinnerIsServed
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_AhExcellent
	closemessage
	callnative ClearMugshot
	applymovement 3, WalkToDiningRoom
	waitmovement 0
	releaseall
	setobjectxy 3, 37, 5
	setobjectxyperm 3, 37, 5
	setvar VAR_ROUTE105_STATE, 3
	end


KogaRaisonDetre_StartDinner_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 36
	goto_if_eq KogaRaisonDetre_StartDinner_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, WalkToTableFromRight
KogaRaisonDetre_StartDinner_Script_1:
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_WereHonoredToHaveYou
	callnative ClearMugshot
	closemessage
	fadescreen FADE_TO_BLACK
	addobject 1
	addobject 2
	setobjectxy 2, 42, 7
	setobjectxy 1, 40, 7
	setobjectxy 3, 37, 5
	turnobject 2, DIR_NORTH
	turnobject 1, DIR_NORTH
	goto KogaRaisonDetre_DinnerConversation_Dialogue
	end

KogaRaisonDetre_StartDinner_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, WalkToTableFromLeft
	goto KogaRaisonDetre_StartDinner_Script_1


KogaRaisonDetre_DinnerConversation_Dialogue::
	special SpawnCameraObject
	setvar VAR_0x8004, 37
	setvar VAR_0x8005, 5
	special TeleportCamera
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, KogaRaisonDetre_PanCamera
	msgbox gText_KogaRaisonDetre_YourDadIsRed
	closemessage
	msgbox gText_KogaRaisonDetre_HowManyBadges
	closemessage
	msgbox gText_KogaRaisonDetre_DoIHaveToEat
	closemessage
	fadescreen FADE_TO_BLACK
	special ReturnCameraToPlayer
	special RemoveCameraObject
	delay 60
	playse SE_POKENAV_CALL
	waitfanfare
	fadescreen FADE_FROM_BLACK
	goto KogaRaisonDetre_RunToWork_Dialogue
	releaseall
	end


KogaRaisonDetre_RunToWork_Dialogue::
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_SorryThatsMyPhone
	callnative ClearMugshot
	closemessage
	applymovement 3, KogaRaisonDetre_StepAwayFromTable
	waitmovement 0
	applymovement 3, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ShitTheresAnUrgent
	callnative ClearMugshot
	closemessage
	applymovement 3, KogaRaisonDetre_KissKids
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_WaitIThoughtThat
	callnative ClearMugshot
	msgbox gText_KogaRaisonDetre_YeahItDoes
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_What
	callnative ClearMugshot
	msgbox gText_KogaRaisonDetre_TonOfMoneyInWarp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_OhDamnYouWerent
	callnative ClearMugshot
	msgbox gText_KogaRaisonDetre_IDontKnowWhy
	closemessage
	applymovement 2, KogaRaisonDetre_LeaveDiningRoom
	waitmovement 0
	fadescreen FADE_TO_BLACK
	removeobject 2
	removeobject 1
	msgbox KogaRaisonDetre_RunToWork_Dialogue_Text_0
	closemessage
	goto KogaRaisonDetre_NewsStory_Script
	end


KogaRaisonDetre_NewsStory_Script::
	setobjectxy 4, 44, 4
	turnobject 4, DIR_NORTH
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
	fadescreen FADE_FROM_BLACK
	special TurnOnTVScreen
	delay 60
	msgbox gText_KogaRaisonDetre_AndNowWeGoTo
	msgbox gText_KogaRaisonDetre_ThanksKen
	msgbox gText_KogaRaisonDetre_WereAlsoLearningThat
	closemessage
	special TurnOffTVScreen
	applymovement 4, WalkToThePlayer
	waitmovement 0
	msgbox gText_KogaRaisonDetre_IsThereSobAnyhingElse
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_AreYouOkay
	callnative ClearMugshot
	msgbox gText_KogaRaisonDetre_MySobSonIsInTheICU
	closemessage
	applymovement 4, KogaRaisonDetre_LeaveDiningRoomCrying
	waitmovement 0
	removeobject 4
	setvar VAR_ROUTE105_STATE, 4
	setvar VAR_ROUTE106_STATE, 1
	releaseall
	end


KogaRaisonDetre_PreventPlayerLeaving_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_HasBeenSoGenerous
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end


KogaRaisonDetre_ComeDownStairs:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

KogaRaisonDetre_RunAroundPlayer:
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	walk_left
	walk_right
	step_end

KogaRaisonDetre_WalkIntoFoyer:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

KogaRaisonDetre_RunUpstairs:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

KogaRaisonDetre_WalkFromEntrance:
	walk_up
	walk_left
	walk_left
	walk_up
	step_end

KogaRaisonDetre_WalkTowardsLiving:
	walk_up
	face_down
	step_end

KogaRaisonDetre_WalkToDining:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WalkToDiningRoom:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WalkToTableFromLeft:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

WalkToTableFromRight:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

KogaRaisonDetre_PanCamera:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

KogaRaisonDetre_StepAwayFromTable:
	walk_left
	step_end

KogaRaisonDetre_KissKids:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_slow_left
	delay_16
	walk_in_place_slow_right
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

KogaRaisonDetre_LeaveDiningRoom:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WalkToThePlayer:
	walk_right
	walk_right
	walk_right
	face_down
	step_end

KogaRaisonDetre_LeaveDiningRoomCrying:
	walk_up
	walk_up
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

KogaRaisonDetre_RunToWork_Dialogue_Text_0:
	.string "The next morning…$"

gText_KogaRaisonDetre_HasBeenSoGenerous::
	.string "Psfbadadmin2 has been so generous... I\n"
	.string "should stay.$"

gText_KogaRaisonDetre_HasBeenExpectingYou::
	.string "{PLAYER}, PSFBADADMIN2 has been\n"
	.string "expecting you.$"

gText_KogaRaisonDetre_YoureHereInTheFlesh::
	.string "Aaaahhhh! {PLAYER}! You're here! In\n"
	.string "the flesh!$"

gText_KogaRaisonDetre_YoureAFreak::
	.string "…Alek, you're a freak.$"

gText_KogaRaisonDetre_MaybeTheyllSign::
	.string "Aren't you excited Raghnall?! Maybe\n"
	.string "they'll sign your {PLAYER} shirt!$"

gText_KogaRaisonDetre_ShutUp::
	.string "…shut up!$"

gText_KogaRaisonDetre_ShowUsHowYouTookDown::
	.string "Oh oh oh, show us how you took down\n"
	.string "Psfleader1! Can we see some battle\l"
	.string "moves? Oh come on yes, let's battle,\l"
	.string "right now, yeah yeah yeah!$"

gText_KogaRaisonDetre_AllRightAllRight::
	.string "All right, all right, calm down. I told you\n"
	.string "you'd have to stifle your excitement,\l"
	.string "didn't I?$"

gText_KogaRaisonDetre_YouDontWantToScare::
	.string "You don't want to scare {PLAYER}\n"
	.string "away, do you?$"

gText_KogaRaisonDetre_GonnaGoGet::
	.string "No no no! Oh, I'm gonna go get all my\n"
	.string "League stuff, I'll be right back!$"

gText_KogaRaisonDetre_SorryAboutThat::
	.string "Sorry about that. They get… very\n"
	.string "excited. And don't let Raghnall's\l"
	.string "demeanor fool you. I think they've\l"
	.string "watched your battle against\l"
	.string "Psfleader3 at least 40 times.$"

gText_KogaRaisonDetre_OhMyGod::
	.string "Oh my god, Dad!$"

gText_KogaRaisonDetre_YourHouseIsBeautiful::
	.string "Your house is beautiful. Actually, the\n"
	.string "entire city is beautiful.$"

gText_KogaRaisonDetre_ItWasImportantToMe::
	.string "Thank you. It was important to me that\n"
	.string "I raised my family in Psfcity3. Most\l"
	.string "Psfbadguy1 employees want to be in\l"
	.string "the city - close to the office and the\l"
	.string "nightlife.$"

gText_KogaRaisonDetre_ButItsHardToJustify::
	.string "But it's hard to justify raising a family\n"
	.string "there. It's expensive on this side,\l"
	.string "sure, but it's less dangerous… and the\l"
	.string "city is suffering.$"

gText_KogaRaisonDetre_IveBeenStruggling::
	.string "I've been struggling to find the right\n"
	.string "word for it, but suffering is good.\l"
	.string "Psfcity12, Psfcity9… so many of the\l"
	.string "places I've been to so far are hurting.$"

gText_KogaRaisonDetre_ItsBeenSaidThat::
	.string "It's been said that most skilled\n"
	.string "Trainers are unusually compassionate,\l"
	.string "and I guess that means you too!$"

gText_KogaRaisonDetre_ToughToBeAround::
	.string "It's tough to be around, especially as\n"
	.string "you guys are treating me so well, you\l"
	.string "know? Do I really deserve all of this\l"
	.string "just because I'm decent at battles?$"

gText_KogaRaisonDetre_ICompletelyUnderstand::
	.string "I completely understand, trust me.$"

gText_KogaRaisonDetre_ItsMuchEasier::
	.string "It's much easier to have these talks\n"
	.string "over wine.$"

gText_KogaRaisonDetre_ComeSit::
	.string "Come, sit.$"

gText_KogaRaisonDetre_IPickedOut::
	.string "I picked out an excellent Chardonnay\n"
	.string "for you. Come have a seat.$"

gText_KogaRaisonDetre_HowMuch::
	.string "How much do you know about\n"
	.string "Psfbadboss?$"

gText_KogaRaisonDetre_IJustRecentlyMet::
	.string "I just recently met them. They're the\n"
	.string "CEO, and the League Commissioner, and\l"
	.string "prefer working alongside people.$"

gText_KogaRaisonDetre_ThatLastPartIsImportant::
	.string "That last part is important -\n"
	.string "Psfbadboss grew up here. They take\l"
	.string "great pride in Psfregion1, and want all\l"
	.string "of their work at Psfbadguy1 to go\l"
	.string "towards making the entire region a\l"
	.string "better place to live. It's why we\l"
	.string "acquired the Pokémon League.\l"
	.string "Psfbadboss saw its potential and knew\l"
	.string "we could use its draw and our resources\l"
	.string "to make it even better, and bring in\l"
	.string "Trainers like you.$"

gText_KogaRaisonDetre_WhatDoYouMean::
	.string "What do you mean?$"

gText_KogaRaisonDetre_DoYouKnowHow::
	.string "Do you know how the Kanto region makes\n"
	.string "the majority of its revenue?$"

gText_KogaRaisonDetre_IsntItMostly::
	.string "Isn't it mostly manufacturing?$"

gText_KogaRaisonDetre_UsedToBe::
	.string "Used to be. But after Red took the\n"
	.string "League by storm back in '96, the League\l"
	.string "has been the primary economic driver.\l"
	.string "Estimates show that revenue from the\l"
	.string "Pokémon League is about to eclipse\l"
	.string "tourism in Alola too.$"

gText_KogaRaisonDetre_WoahWaitBigger::
	.string "Woah wait, bigger than Alolan tourism?$"

gText_KogaRaisonDetre_PeopleLoveBattles::
	.string "People love Pokémon battles.\n"
	.string "Psfbadboss knew if we used our\l"
	.string "resources to create a compelling\l"
	.string "product, we wouldn't need Dynamax or\l"
	.string "League HQs built into cathedrals. We've\l"
	.string "got what the people want to see.$"

gText_KogaRaisonDetre_TheBroadcasts::
	.string "The broadcasts?$"

gText_KogaRaisonDetre_MyKidsBeingObsessed::
	.string "Yes. My kids being obsessed with you\n"
	.string "isn't an accident. We're building\l"
	.string "rockstars.$"

gText_KogaRaisonDetre_WereGoingToMake::
	.string "We're going to make Psfregion1 the\n"
	.string "region where rock stars are born.\l"
	.string "Trainers are going to want to emulate\l"
	.string "you! The region will be richer for it. It\l"
	.string "can afford to uplift all of its citizens\l"
	.string "to something much much greater. You're\l"
	.string "an investment, {PLAYER}, but it's all\l"
	.string "part of a much bigger play.$"

gText_KogaRaisonDetre_IBroughtYouHere::
	.string "I brought you here to thank you\n"
	.string "{PLAYER}. You're part of the puzzle\l"
	.string "that is going to bring these people out\l"
	.string "of poverty. You're part of the\l"
	.string "solution.$"

gText_KogaRaisonDetre_DinnerIsServed::
	.string "Dinner is served!$"

gText_KogaRaisonDetre_AhExcellent::
	.string "Ah excellent, passion makes me hungry.$"

gText_KogaRaisonDetre_WereHonoredToHaveYou::
	.string "{PLAYER}, we're honored to have you in\n"
	.string "our home. Enjoy dinner!$"

gText_KogaRaisonDetre_YourDadIsRed::
	.string "Is it true your dad is Red from Pallet\n"
	.string "Town?$"

gText_KogaRaisonDetre_HowManyBadges::
	.string "How many badges did you have in Orre?$"

gText_KogaRaisonDetre_DoIHaveToEat::
	.string "Dad, do I have to eat all my asparagus?$"

gText_KogaRaisonDetre_SorryThatsMyPhone::
	.string "Sorry, that's my phone and I need to\n"
	.string "take that.$"

gText_KogaRaisonDetre_ShitTheresAnUrgent::
	.string "Shit, there's an urgent matter at work.\n"
	.string "I'm so sorry kids, I'll try to hurry back.\l"
	.string "{PLAYER}, we've already set up one of\l"
	.string "the guest rooms for you, and hopefully\l"
	.string "I'll be able to join you for breakfast\l"
	.string "before you leave again. If I don't see\l"
	.string "you, have an excellent night.$"

gText_KogaRaisonDetre_WaitIThoughtThat::
	.string "Wait, I thought that hallway just goes\n"
	.string "upstairs?$"

gText_KogaRaisonDetre_YeahItDoes::
	.string "Yeah, it does. Daddy just teleports to\n"
	.string "work!$"

gText_KogaRaisonDetre_What::
	.string "…what?$"

gText_KogaRaisonDetre_TonOfMoneyInWarp::
	.string "Psfbadguy has a ton of money in warp\n"
	.string "tiles. All the executives have panels\l"
	.string "from their house to their office\l"
	.string "installed. He literally teleports to\l"
	.string "work, everyday.$"

gText_KogaRaisonDetre_OhDamnYouWerent::
	.string "Oh damn, you weren't kidding.$"

gText_KogaRaisonDetre_IDontKnowWhy::
	.string "I don't know why they bother. Our\n"
	.string "parents are never even home. They're\l"
	.string "trying so hard to save the world,\l"
	.string "they're totally ignoring the one right\l"
	.string "in front of them.$"

gText_KogaRaisonDetre_AndNowWeGoTo::
	.string "And now we go to Da Lin, for more details\n"
	.string "about last night's riots.$"

gText_KogaRaisonDetre_ThanksKen::
	.string "Thanks Ken. We're gathering details on\n"
	.string "the ground here, but it sounds like\l"
	.string "this riot was instigated by members of\l"
	.string "Psfgoodteam, culminating in violent\l"
	.string "attacks on the Psfcity12 Police Force.\l"
	.string "Both sides sustained significant\l"
	.string "injury, and dozens of members of\l"
	.string "Psfgoodteam were taken into custody\l"
	.string "last night. Back to you, Ken.$"

gText_KogaRaisonDetre_WereAlsoLearningThat::
	.string "We're also learning that the Mayor's\n"
	.string "office released a press statement ten\l"
	.string "minutes ago, primarily addressing\l"
	.string "Psfgoodteam, asking for an end to the\l"
	.string "violence and begging them to “work\l"
	.string "with us, not against us”. We'll have\l"
	.string "more updates within the hour.$"

gText_KogaRaisonDetre_IsThereSobAnyhingElse::
	.string "Is there *sob* anything else I can get\n"
	.string "you *sob*, Lord {PLAYER}?$"

gText_KogaRaisonDetre_AreYouOkay::
	.string "Are you okay? What's wrong?$"

gText_KogaRaisonDetre_MySobSonIsInTheICU::
	.string "I'm sorry. My… *sob* son is in the ICU\n"
	.string "after the riots last night.\l"
	.string "Psfgoodteam keeps getting\l"
	.string "impressionable young folk involved in\l"
	.string "their nonsense… *sob* I hope the city\l"
	.string "can get rid of them!$"
