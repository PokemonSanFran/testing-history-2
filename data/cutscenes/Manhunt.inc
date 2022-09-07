Manhunt_TowerObjectSetUp_Script::
	setobjectxy 2, 8, 6
	setobjectxyperm 2, 8, 6
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	return


Manhunt_HideGiovanni_Script::
	setflag FLAG_TEMP_1
	return


Manhunt_HideBianca_Script::
	setflag FLAG_TEMP_2
	return


Manhunt_Assignment_Dialogue::
	lock
	compare VAR_MANHUNT_STATE, 0
	goto_if_ne Manhunt_Assignment_Dialogue_2
	addvar VAR_MANHUNT_STATE, 1
	setvar VAR_MUGSHOT, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_Manhunt_GoFind, MSGBOX_NPC
	callnative ClearMugshot
	release
	end

Manhunt_Assignment_Dialogue_2:
	call AlwaysWatchingWazowski_IgnoringPlayer_Dialogue
	end


Manhunt_Cherie_Battle_Script::
	lock
	playse SE_EXIT
	waitse
	clearflag FLAG_TEMP_2
	addobject 2
	applymovement 2, Manhunt_WalkInNewspaper
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_HeyWereTrying, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Manhunt_YeahIWrote
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_Blessed
	callnative ClearMugshot
	msgbox gText_Manhunt_WaitYoureThatKid
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_ThatsUs
	callnative ClearMugshot
	msgbox gText_Manhunt_IShouldHaveRecognized
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_HeyWeJustWant
	callnative ClearMugshot
	msgbox gText_Manhunt_AsAMatterOfFact
	multi_fixed_2_vs_1 TRAINER_RICK, gText_Manhunt_PleaseDontHurtUs, TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	addvar VAR_MANHUNT_STATE, 1
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_StartTalking
	callnative ClearMugshot
	msgbox gText_Manhunt_ISwearIDontKnow
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_IKnowYouKnow
	callnative ClearMugshot
	msgbox gText_Manhunt_TheOnlyLeadIHave
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_ThatsAStart
	callnative ClearMugshot
	msgbox gText_Manhunt_NowPleaseLeave, MSGBOX_AUTOCLOSE
	applymovement 2, Manhunt_LeaveNewspaper
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 2
	release
	end


Manhunt_Teodoro_Battle_Script::
	lock
	playse SE_EXIT
	waitse
	clearflag FLAG_TEMP_2
	addobject 2
	applymovement 2, Manhunt_WalkIntoConsulting
	msgbox gText_Manhunt_WhatAreSomeKids, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_YouGonnaMakeThisEasy
	callnative ClearMugshot
	msgbox gText_Manhunt_WhatTheHellAreYou
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_WeKnowYoureWorkingWith
	callnative ClearMugshot
	msgbox gText_Manhunt_YeahIDidSomeWork
	multi_fixed_2_vs_1 TRAINER_ALLEN, gText_Manhunt_DamnPunks, TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	addvar VAR_MANHUNT_STATE, 1
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_WhatDoYouKnow
	callnative ClearMugshot
	msgbox gText_Manhunt_LookIDontKnowWhat
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_GoodInTheWorld
	callnative ClearMugshot
	msgbox gText_Manhunt_TheOnlyWeirdThing
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_ThatsInPresidio
	callnative ClearMugshot
	msgbox gText_Manhunt_GodForbidSomeGoodPeople, MSGBOX_AUTOCLOSE
	applymovement 2, Manhunt_LeaveConsulting
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 2
	release
	end


Manhunt_Dudley_Battle_Script::
	lock
	playse SE_EXIT
	waitse
	clearflag FLAG_TEMP_2
	addobject 2
	applymovement 2, Manhunt_WalkIntoBallShop
	applymovement 1, Manhunt_ExclaimAndTurn
	msgbox gText_Manhunt_HowCanIHelp, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_CutTheShit
	callnative ClearMugshot
	msgbox gText_Manhunt_WoahTheChampion
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_WhatDoYouKnow
	callnative ClearMugshot
	msgbox gText_Manhunt_YeahTheyreOneOf
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_BecauseWereBusting
	callnative ClearMugshot
	msgbox gText_Manhunt_WhatDidTheyBuy
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_ImSureWeCanHelp
	callnative ClearMugshot
	msgbox gText_Manhunt_WoahWaitHold
	multi_fixed_2_vs_1 TRAINER_TIANA, gText_Manhunt_ShitMan, TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	addvar VAR_MANHUNT_STATE, 1
	msgbox gText_Manhunt_ShitMan
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_AndWereDoingOurs
	callnative ClearMugshot
	msgbox gText_Manhunt_TheyBoughtABunch
	setvar VAR_MUGSHOT, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_Manhunt_WhatElse
	callnative ClearMugshot
	msgbox gText_Manhunt_OneTimeTheyHadDelivered
	msgbox gText_Manhunt_Sob, MSGBOX_AUTOCLOSE
	applymovement 2, Manhunt_LeaveBallShop
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 2
	release
	end


Manhunt_TransformTreestoTallGrass::
	setmetatile 24, 29, 0x015, TRUE
	setmetatile 24, 28, 0x015, TRUE
	setmetatile 24, 27, 0x015, TRUE
	setmetatile 24, 26, 0x015, TRUE
	return


Manhunt_Matthew_Battle_Script::
	clearflag FLAG_TEMP_2
	addobject 2
	call Manhunt_TransformTreestoTallGrass
	applymovement 2, Manhunt_WalkOntoRoute
	waitmovement 0
	msgbox gText_Manhunt_OhDamnLooksLike
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_WhosHe
	callnative ClearMugshot
	msgbox gText_Manhunt_YeahToldMeYoud
	multi_fixed_2_vs_1 TRAINER_HOPE, gText_Manhunt_IFeelBadForAll, TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	addvar VAR_MANHUNT_STATE, 1
	msgbox gText_Manhunt_IFeelBadForAll, MSGBOX_AUTOCLOSE
	applymovement 2, Manhunt_LeaveRoute
	waitmovement 0
	removeobject 2
	release
	end


Manhunt_Encounter_Giovanni_Dialogue::
	lock
	call Common_EventScript_SaveGame
	clearflag FLAG_TEMP_2
	addobject 2
	applymovement 2, Manhunt_ApproachAtLake
	waitmovement 0
	setvar VAR_MUGSHOT, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_Manhunt_StopHurtingPeople, MSGBOX_NPC
	callnative ClearMugshot
	lock
	multi_fixed_2_vs_1 TRAINER_MATT, gText_Manhunt_IfIDontHave, TRAINER_MAY_LILYCOVE_MUDKIP, TRAINER_BACK_PIC_MAY
	addvar VAR_MANHUNT_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_MUGSHOT, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_Manhunt_IWontFightYouAnyFurther
	compare VAR_STORYLINE_STATE, 47
	goto_if_eq Manhunt_Encounter_Giovanni_Dialogue_2
Manhunt_Encounter_Giovanni_Dialogue_1:
	callnative ClearMugshot
	pokenavcall Manhunt_Encounter_Giovanni_Dialogue_Text_0
	waitmessage
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Manhunt_IllBeAtTheEntrance
	setvar VAR_MUGSHOT, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_Manhunt_WhatWaitUhOkay
	callnative ClearMugshot
	warpsilent MAP_SALESFORCETOWER_2F, 255, 8, 7
	return

Manhunt_Encounter_Giovanni_Dialogue_2:
	msgbox gText_Manhunt_TheRegionIsYours
	goto Manhunt_Encounter_Giovanni_Dialogue_1


Manhunt_MissionComplete_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	applymovement 2, Common_Movement_FaceDown
	waitmovement 0
	addvar VAR_STORYLINE_STATE, 1
	addvar VAR_MANHUNT_STATE, 1
	setvar VAR_MUGSHOT, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_Manhunt_GoodWork
	callnative ClearMugshot
	release
	call ExhibitionBattle_TimeSkip_Script
	end


Manhunt_WalkInNewspaper:
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Manhunt_LeaveNewspaper:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Manhunt_WalkIntoConsulting:
	walk_up
	walk_up
	jump_2_up
	face_right
	step_end

Manhunt_LeaveConsulting:
	walk_down
	jump_down
	walk_down
	walk_down
	step_end

Manhunt_WalkIntoBallShop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Manhunt_ExclaimAndTurn:
	emote_exclamation_mark
	face_up
	delay_16
	faceplayer
	step_end

Manhunt_LeaveBallShop:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Manhunt_WalkOntoRoute:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Manhunt_LeaveRoute:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Manhunt_ApproachAtLake:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Manhunt_Encounter_Giovanni_Dialogue_Text_0:
	.string "This phone is ringing.$"

gText_Manhunt_GoFind::
	.string "Go find Giovanni. Bianca will help. The\n"
	.string "newspaper in SOMA is a good place to\l"
	.string "start, they ran a story on TeamRocket\l"
	.string "last year.$"

gText_Manhunt_HeyWereTrying::
	.string "Hey, we're trying to find Giovanni, and\n"
	.string "we were told you might have a\l"
	.string "connection.$"

gText_Manhunt_YeahIWrote::
	.string "Yeah, I wrote the TeamRocket\n"
	.string "leadership piece a few months back. It\l"
	.string "was more than time to see such a great\l"
	.string "group of youngsters really start to\l"
	.string "get the recognition they deserve. And\l"
	.string "getting to really sit down with\l"
	.string "Giovanni... I feel blessed to have been\l"
	.string "able to do it!$"

gText_Manhunt_Blessed::
	.string "Blessed? TeamRocket? Ugh, they've\n"
	.string "infected you too.$"

gText_Manhunt_WaitYoureThatKid::
	.string "...wait. You're that {PLAYER} kid,\n"
	.string "aren't you?$"

gText_Manhunt_ThatsUs::
	.string "That's us.$"

gText_Manhunt_IShouldHaveRecognized::
	.string "I should have recognized you two\n"
	.string "sooner. What're you doing snooping\l"
	.string "around here? Haven't you two helped\l"
	.string "enough?$"

gText_Manhunt_HeyWeJustWant::
	.string "Hey, we just want to talk!$"

gText_Manhunt_AsAMatterOfFact::
	.string "As a matter of fact, get the hell out of\n"
	.string "here. Everything you two do is just\l"
	.string "hurting the region and lining the\l"
	.string "pockets of people who don't even care.\l"
	.string "Get out!$"

gText_Manhunt_PleaseDontHurtUs::
	.string "...Please don't hurt us any further. What\n"
	.string "do you want?$"

gText_Manhunt_StartTalking::
	.string "Start talking. Who's Giovanni behind the\n"
	.string "mask?$"

gText_Manhunt_ISwearIDontKnow::
	.string "Giovanni? I swear, I don't know who he\n"
	.string "is. Nobody does. I'm a reporter.... I\l"
	.string "wouldn't keep that a secret.$"

gText_Manhunt_IKnowYouKnow::
	.string "I KNOW you know some shit.$"

gText_Manhunt_TheOnlyLeadIHave::
	.string "The only lead I have is a consulting\n"
	.string "firm in Mission... there's money flowing\l"
	.string "between there and TeamRocket, or, at\l"
	.string "least there was. I never figured out\l"
	.string "what was going on though.$"

gText_Manhunt_ThatsAStart::
	.string "That's a start…$"

gText_Manhunt_NowPleaseLeave::
	.string "Now please... leave us alone.$"

gText_Manhunt_WhatAreSomeKids::
	.string "What are some kids doing here?$"

gText_Manhunt_YouGonnaMakeThisEasy::
	.string "You gonna make this easy? Or are you\n"
	.string "gonna keep protecting TeamRocket?$"

gText_Manhunt_WhatTheHellAreYou::
	.string "TeamRocket? What the hell are you\n"
	.string "talking about?$"

gText_Manhunt_WeKnowYoureWorkingWith::
	.string "We know you're working with TeamRocket,\n"
	.string "and we need to find their leader.$"

gText_Manhunt_YeahIDidSomeWork::
	.string "Yeah, I did some work for them a while\n"
	.string "back. What about it? Gonna rat us out\l"
	.string "to your bosses?$"

gText_Manhunt_DamnPunks::
	.string "Damn punks.$"

gText_Manhunt_WhatDoYouKnow::
	.string "What do you know about TeamRocket?$"

gText_Manhunt_LookIDontKnowWhat::
	.string "Look, I don't know what you're digging\n"
	.string "for. TeamRocket is all above ground,\l"
	.string "nothing to hide, just trying to do some\l"
	.string "damn good in the world.$"

gText_Manhunt_GoodInTheWorld::
	.string "Good in the world, bullshit. There's\n"
	.string "gotta be something unusual. Keep\l"
	.string "thinking!$"

gText_Manhunt_TheOnlyWeirdThing::
	.string "The only weird thing about them was\n"
	.string "buying Balls in bulk from that\l"
	.string "Speciality Ball Shop... but seriously,\l"
	.string "there's nothing interesting there.$"

gText_Manhunt_ThatsInPresidio::
	.string "That's in Presidio. Let's move.$"

gText_Manhunt_GodForbidSomeGoodPeople::
	.string "God forbid some good people try to make\n"
	.string "some change without these tech\l"
	.string "cronies ruining it for everybody.$"

gText_Manhunt_HowCanIHelp::
	.string "How can I help -$"

gText_Manhunt_CutTheShit::
	.string "Cut the shit.$"

gText_Manhunt_WoahTheChampion::
	.string "woah, the Champion. Are you looking to\n"
	.string "change -$"

gText_Manhunt_YeahTheyreOneOf::
	.string "TeamRocket? Yeah, they're one of our\n"
	.string "customers, why?$"

gText_Manhunt_BecauseWereBusting::
	.string "Because we're busting their shit up.\n"
	.string "They're buying in bulk from you. What\l"
	.string "are they buying?$"

gText_Manhunt_WhatDidTheyBuy::
	.string "What did they buy? I don't think I'm\n"
	.string "supposed to divulge that, but I can\l"
	.string "ask my boss.$"

gText_Manhunt_ImSureWeCanHelp::
	.string "I'm sure we can help you divulge a\n"
	.string "little.$"

gText_Manhunt_WoahWaitHold::
	.string "Woah wait hold on!$"

gText_Manhunt_ShitMan::
	.string "Shit man, I'm just doing my job!$"

gText_Manhunt_AndWereDoingOurs::
	.string "And we're doing ours. Start talking.$"

gText_Manhunt_TheyBoughtABunch::
	.string "They bought a bunch of Dusk Balls in\n"
	.string "bulk. I don't know why, I don't know\l"
	.string "where they were going or what they\l"
	.string "were doing.$"

gText_Manhunt_WhatElse::
	.string "What else! Think hard, or else.$"

gText_Manhunt_OneTimeTheyHadDelivered::
	.string "One time they had them delivered to\n"
	.string "Psfroute62, but I swear that doesn't\l"
	.string "mean anything! Please don't hurt me...$"

gText_Manhunt_Sob::
	.string "sob...$"

gText_Manhunt_OhDamnLooksLike::
	.string "Oh damn, looks like he was right.$"

gText_Manhunt_WhosHe::
	.string "Who's he?$"

gText_Manhunt_YeahToldMeYoud::
	.string "Yeah, Giovanni told me you'd be coming.\n"
	.string "But I wonder how tough you actually\l"
	.string "are!$"

gText_Manhunt_IFeelBadForAll::
	.string "I feel bad for all the innocent people\n"
	.string "you've been harassing... you're no joke.\l"
	.string "Giovanni wants you to meet him at the\l"
	.string "Lake, after sunset. Just the two of\l"
	.string "you - no police or Psfbadguy cronies,\l"
	.string "or the trail goes cold again. Up to you.$"

gText_Manhunt_StopHurtingPeople::
	.string "Stop hurting people. I'm here.$"

gText_Manhunt_IfIDontHave::
	.string "If I don't have the strength to beat\n"
	.string "you, perhaps I don't have the strength\l"
	.string "to save SanFran after all.$"

gText_Manhunt_IWontFightYouAnyFurther::
	.string "*sniff* I won't fight you any further.\n"
	.string "Call your backup.$"

gText_Manhunt_TheRegionIsYours::
	.string "TeamRocket is finished. The region is\n"
	.string "yours now.$"

gText_Manhunt_IllBeAtTheEntrance::
	.string "Oak, I've defeated Giovanni. I'll be at\n"
	.string "the entrance to Lakemerritt.$"

gText_Manhunt_WhatWaitUhOkay::
	.string "What!? Wait uh - okay um, excellent\n"
	.string "work! I'll send the police right over.\l"
	.string "This is amazing!$"

gText_Manhunt_GoodWork::
	.string "Good work.$"
