KogaRaisonDetre_HideObjectKids_Script::
	setflag FLAG_TEMP_1
	return


KogaRaisonDetre_HideObjectMaid_Script::
	setflag FLAG_TEMP_2
	return


KogaRaisonDetre_ObjectCleanUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


KogaRaisonDetre_MoveIntoFoyer_Script::
	lock
	addvar VAR_ROUTE105_STATE, 1
	applymovement 1, KogaRaisonDetre_ComeDownStairs
	delay 48
	applymovement 2, KogaRaisonDetre_ComeDownStairs
	waitmovement 0
	release
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
	msgbox gText_KogaRaisonDetre_OhArceus
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
	release
	end


KogaRaisonDetre_ComeSit_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ComeSit, MSGBOX_NPC
	callnative ClearMugshot
	addvar VAR_ROUTE105_STATE, 1
	closemessage
	release
	end


KogaRaisonDetre_InteractAtTable_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IPickedOut
	closemessage
	callnative ClearMugshot
	release
	end


KogaRaisonDetre_Wine_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_HowMuch
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_ThatLastPartIsImportant
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_Shareholders
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_YeahTheCorporate
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
	callnative ClearMugshot
	applymovement 3, Common_Movement_FaceAwayPlayer
	waitmovement 3
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_IPray
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_WhatWasThat
	callnative ClearMugshot
	closemessage
	playse SE_DING_DONG
	waitfanfare
	msgbox gText_KogaRaisonDetre_DinnerIsServed
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_AhLetsEat
	closemessage
	callnative ClearMugshot
	applymovement 3, WalkToDiningRoom
	waitmovement 0
	release
	setobjectxy 3, 37, 5
	setobjectxyperm 3, 37, 5
	addvar VAR_ROUTE105_STATE, 1
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
	special DrawWholeMapView
	fadescreen FADE_FROM_BLACK
	applymovement OBJ_EVENT_ID_CAMERA, KogaRaisonDetre_PanCamera
	msgbox gText_KogaRaisonDetre_YourDadIsRed
	closemessage
	msgbox gText_KogaRaisonDetre_HowManyBadges
	closemessage
	msgbox gText_KogaRaisonDetre_DoIHaveToEat
	closemessage
	fadescreen FADE_TO_BLACK
	TeleportCamera 43, 5
	special RemoveCameraObject
	delay 60
	playse SE_POKENAV_CALL
	waitse
	fadescreen FADE_FROM_BLACK
	goto KogaRaisonDetre_RunToWork_Dialogue
	release
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
	delay 32
	applymovement 3, Common_Movement_FaceRight
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
	turnobject 5, DIR_NORTH
	setobjectnewmovementtype 4, MOVEMENT_TYPE_FACE_UP
	setobjectnewmovementtype 5, MOVEMENT_TYPE_FACE_UP
	lockall
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
	removeobject 3
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_ROUTE105_STATE, 1
	addvar VAR_ROUTE106_STATE, 1
	release
	end


KogaRaisonDetre_PreventPlayerLeaving_Script::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_KogaRaisonDetre_HasBeenSoGenerous
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end


KogaRaisonDetre_ComeDownStairs:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

KogaRaisonDetre_RunAroundPlayer:
	jump_2_left
	jump_2_right
	jump_2_left
	jump_2_right
	jump_2_left
	jump_2_right
	jump_2_left
	jump_2_right
	jump_2_left
	jump_2_right
	jump_2_left
	jump_2_right
	jump_2_left
	jump_2_right
	face_left
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
	.string "Koga has been so generous... I should\n"
	.string "stay.$"

gText_KogaRaisonDetre_HasBeenExpectingYou::
	.string "{PLAYER}, KOGA has been expecting\n"
	.string "you.$"

gText_KogaRaisonDetre_YoureHereInTheFlesh::
	.string "Aaaahhhh! {PLAYER}! You're here! In\n"
	.string "the flesh!$"

gText_KogaRaisonDetre_YoureAFreak::
	.string "…Alek, you're a freak.$"

gText_KogaRaisonDetre_MaybeTheyllSign::
	.string "Aren't you excited Summer?! Maybe\n"
	.string "they'll sign your {PLAYER} shirt!$"

gText_KogaRaisonDetre_ShutUp::
	.string "…shut up!$"

gText_KogaRaisonDetre_ShowUsHowYouTookDown::
	.string "Oh oh oh, show us how you took down\n"
	.string "Falkner! Can we see some battle moves?\l"
	.string "Oh come on yes, let's battle, right now,\l"
	.string "yeah yeah yeah!$"

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
	.string "excited. And don't let Summer's\l"
	.string "demeanor fool you. I think they've\l"
	.string "watched your battle against Whitney\l"
	.string "at least 40 times.$"

gText_KogaRaisonDetre_OhArceus::
	.string "Oh Arceus, Dad!$"

gText_KogaRaisonDetre_YourHouseIsBeautiful::
	.string "Your house is beautiful. Actually, the\n"
	.string "entire city is beautiful.$"

gText_KogaRaisonDetre_ItWasImportantToMe::
	.string "Thank you. It was important to me that\n"
	.string "I raised my family in Presidio. Most\l"
	.string "YCombinator employees want to be in\l"
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
	.string "Tenderloin, Oakland… so many of the\l"
	.string "places I've been to so far are hurting.$"

gText_KogaRaisonDetre_ItsBeenSaidThat::
	.string "I've noticed that Bianca doesn't quite\n"
	.string "see the region the way you do! I admire\l"
	.string "your compassion.$"

gText_KogaRaisonDetre_ToughToBeAround::
	.string "Do I really deserve all of this just\n"
	.string "because I'm decent at battles?$"

gText_KogaRaisonDetre_ICompletelyUnderstand::
	.string "I completely understand, trust me. When\n"
	.string "I worked in Chinatown, it wasn't this\l"
	.string "bad, but despite my best efforts,\l"
	.string "things have gotten worse.$"

gText_KogaRaisonDetre_ItsMuchEasier::
	.string "Come, let's talk.$"

gText_KogaRaisonDetre_ComeSit::
	.string "Over here!$"

gText_KogaRaisonDetre_IPickedOut::
	.string "Take a seat.$"

gText_KogaRaisonDetre_HowMuch::
	.string "How much do you know about Rose?$"

gText_KogaRaisonDetre_ThatLastPartIsImportant::
	.string "They don't have deep roots here, but\n"
	.string "they're a brilliant business person. I\l"
	.string "don't always see eye to eye with them,\l"
	.string "but they've never let down a\l"
	.string "shareholder.$"

gText_KogaRaisonDetre_Shareholders::
	.string "What shareholders?$"

gText_KogaRaisonDetre_YeahTheCorporate::
	.string "The corporate sponsors who helped us\n"
	.string "acquire the Pokémon League. Rose saw\l"
	.string "its potential and knew we could make it\l"
	.string "even bigger. Amazon, Uber and Facebook\l"
	.string "all quickly got on board.$"

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
	.string "Revenue from the Pokémon League is\l"
	.string "about to eclipse tourism in Alola too.$"

gText_KogaRaisonDetre_WoahWaitBigger::
	.string "Woah wait, bigger than Alolan tourism?$"

gText_KogaRaisonDetre_PeopleLoveBattles::
	.string "People love Pokémon battles. Rose knew\n"
	.string "if we used our resources to create a\l"
	.string "compelling product, we wouldn't need\l"
	.string "Dynamax or League HQs built into\l"
	.string "cathedrals. We've got what the people\l"
	.string "want to see.$"

gText_KogaRaisonDetre_TheBroadcasts::
	.string "The broadcasts?$"

gText_KogaRaisonDetre_MyKidsBeingObsessed::
	.string "Yes. My kids being obsessed with you\n"
	.string "isn't an accident. We're building rock\l"
	.string "stars.$"

gText_KogaRaisonDetre_WereGoingToMake::
	.string "Ycombinator is going to make SanFran\n"
	.string "the region where Trainers come to\l"
	.string "become rock stars. SanFran's new\l"
	.string "talent will attract the best and the\l"
	.string "brightest, and the region will be richer\l"
	.string "for it. We can uplift all of SanFran's\l"
	.string "citizens to something much much\l"
	.string "greater. You're an investment,\l"
	.string "{PLAYER}, but it's all part of a much\l"
	.string "bigger play.$"

gText_KogaRaisonDetre_IPray::
	.string "*sigh* I choose to believe that this is\n"
	.string "for the greater good.$"

gText_KogaRaisonDetre_WhatWasThat::
	.string "What did you sa -$"

gText_KogaRaisonDetre_DinnerIsServed::
	.string "Dinner is served!$"

gText_KogaRaisonDetre_AhLetsEat::
	.string "Ah, let's eat!$"

gText_KogaRaisonDetre_WereHonoredToHaveYou::
	.string "{PLAYER}, we're honored to have you in\n"
	.string "our home. Enjoy dinner!$"

gText_KogaRaisonDetre_YourDadIsRed::
	.string "Is it true your dad is Red from Pallet\n"
	.string "Town?$"

gText_KogaRaisonDetre_HowManyBadges::
	.string "How many badges did you have in Orre?$"

gText_KogaRaisonDetre_DoIHaveToEat::
	.string "Dad, I was right, {PLAYER} does like\n"
	.string "{STR_VAR_1}!$"

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
	.string "Ycombinator has a ton of money in warp\n"
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
	.string "in front of them.\n"
	.string "I wish he would go back to being a Gym\l"
	.string "Leader!$"

gText_KogaRaisonDetre_AndNowWeGoTo::
	.string "And now we go to Da Lin, for more details\n"
	.string "about last night's riots.$"

gText_KogaRaisonDetre_ThanksKen::
	.string "Thanks Ken. We're gathering details on\n"
	.string "the ground here, but it sounds like\l"
	.string "this riot was instigated by members of\l"
	.string "TeamRocket, culminating in violent\l"
	.string "attacks on the Tenderloin Police\l"
	.string "Force. Both sides sustained\l"
	.string "significant injury, and dozens of\l"
	.string "members of TeamRocket were taken into\l"
	.string "custody last night. Back to you, Ken.$"

gText_KogaRaisonDetre_WereAlsoLearningThat::
	.string "We're also learning that the Mayor's\n"
	.string "office released a press statement ten\l"
	.string "minutes ago, primarily addressing\l"
	.string "TeamRocket, asking for an end to the\l"
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
	.string "after the riots last night. TeamRocket\l"
	.string "keeps getting impressionable young\l"
	.string "folk involved in their nonsense… *sob* I\l"
	.string "hope the city can get rid of them!$"
