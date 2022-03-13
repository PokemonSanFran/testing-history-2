YouRealizeTheyreEvilRight_HideObject_Script::
	compare VAR_STORYLINE_STATE, 35
	goto_if_lt YouRealizeTheyreEvilRight_HideObject_Script_1
	return

YouRealizeTheyreEvilRight_HideObject_Script_1:
	setflag FLAG_TEMP_1
	return


YouRealizeTheyreEvilRight_ShowObject_Script::
	compare VAR_STORYLINE_STATE, 35
	goto_if_eq YouRealizeTheyreEvilRight_ShowObject_Script_1
	return

YouRealizeTheyreEvilRight_ShowObject_Script_1:
	addobject 11
	return


YouRealizeTheyreEvilRight_CallPlayer_Dialogue::
	lockall
	clearflag FLAG_SCOTT_CALL_FORTREE_GYM
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HolyShit
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_AwesomeJobIn
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TheyDontLove
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YouSeemSurprised
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YoureNot
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IveBeenTrying
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WhatDoYouMean
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IWannaShowYou
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YoullNeedToCross
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IDontKnowIf
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ImHereWhere
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_SwimAroundThe
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WelcomeToTheReal
	msgbox gText_YouRealizeTheyreEvilRight_WhileAlcatraz
	msgbox gText_YouRealizeTheyreEvilRight_AsThePrisonPopulation
	msgbox gText_YouRealizeTheyreEvilRight_TheInmateWasAlso
	msgbox gText_YouRealizeTheyreEvilRight_TheProtests
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TheChampionHasArrived
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_NiceToMeetYou
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HasBeenUsing
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WowSuperResourceful
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WhyAreWeHere
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ICanFinallyProve
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DidYouDragMe
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YesWaitNo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DoesntDoAnythingForThis
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ICanProve
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_How
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_Look
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThisIsOne
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IHadToGo
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThisOneIsLevel
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ButTheyDefinitelyCan
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DoesntLearnThatNaturally
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_SoUsedATM
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_NoItMustHaveBeenBred
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TakeACloserLook
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_DoYouSeeNow
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_AhVeryAstute
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WaitWhichMove
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_VeryClever
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TheTipOff
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_So
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HazeCanOnly
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IDontGetIt
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_HasBeenFramingYou
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YouAlsoMetUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ButPsfgoodadminSaid
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YeahNobodyKnows
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_WhyWhyDoAll
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ExistsToMakeMoney
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_CantArgueWithThat
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IJoinedThe
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_AndThatsWhyWere
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YepIThinkItsFinally
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_KidIfTheEliteFour
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThingsAreDifferentNow
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_LookIKnowThis
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_YeahOkay
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThisGarbodor
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_TakeGoodCare
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_ThatsFineIll
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IsStillWaiting
	msgbox gText_YouRealizeTheyreEvilRight_DoYouWantToGo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouRealizeTheyreEvilRight_IHaveNoIdeaWhat
	return


gText_YouRealizeTheyreEvilRight_HolyShit::
	.string "Holy shit. That was intense. Guess I\n"
	.string "need to think all this over, but\l"
	.string "something isn't adding up.$"

gText_YouRealizeTheyreEvilRight_AwesomeJobIn::
	.string "Awesome job in PsfcityX. I heard all\n"
	.string "about it, and I'm so happy things are\l"
	.string "getting off the ground. I heard you\l"
	.string "got a phone call and disappeared.\l"
	.string "Everything okay?$"

gText_YouRealizeTheyreEvilRight_TheyDontLove::
	.string "Psfbadguy called me. They don't love\n"
	.string "our project.$"

gText_YouRealizeTheyreEvilRight_YouSeemSurprised::
	.string "You seem surprised.$"

gText_YouRealizeTheyreEvilRight_YoureNot::
	.string "You're not?$"

gText_YouRealizeTheyreEvilRight_IveBeenTrying::
	.string "I've been trying to tell you the whole\n"
	.string "time, these guys are ruthless. Cruel,\l"
	.string "even. Good timing though, I think I can\l"
	.string "finally explain everything to you.$"

gText_YouRealizeTheyreEvilRight_WhatDoYouMean::
	.string "What do you mean?$"

gText_YouRealizeTheyreEvilRight_IWannaShowYou::
	.string "I wanna show you instead. Come to\n"
	.string "Psfcave7.$"

gText_YouRealizeTheyreEvilRight_YoullNeedToCross::
	.string "I wanna show you but you'll need to\n"
	.string "cross some water to get here. You know\l"
	.string "how to Surf, right? No? Go learn from\l"
	.string "the Surfers in Psfcity4, and then meet\l"
	.string "me on Psfcave7.$"

gText_YouRealizeTheyreEvilRight_IDontKnowIf::
	.string "(I don't know if I can afford to get\n"
	.string "pulled any deeper into this…)$"

gText_YouRealizeTheyreEvilRight_ImHereWhere::
	.string "I'm here! Where are you?$"

gText_YouRealizeTheyreEvilRight_SwimAroundThe::
	.string "Come swim around the southwest side of\n"
	.string "the island! You'll see me.$"

gText_YouRealizeTheyreEvilRight_WelcomeToTheReal::
	.string "Welcome to the real Psfcave7. I'm going\n"
	.string "down to the second level, but you\l"
	.string "should explore here first before\l"
	.string "coming straight down.$"

gText_YouRealizeTheyreEvilRight_WhileAlcatraz::
	.string "While Alcatraz was a prison, it was\n"
	.string "absolutely not a state of the art\l"
	.string "facility - rather, criminals deemed\l"
	.string "“dangerous” were thrown into Alcatraz\l"
	.string "with little regard for health,\l"
	.string "rehabilitation, or even due process of\l"
	.string "law, with a preponderance of\l"
	.string "marginalized communities being locked\l"
	.string "away.$"

gText_YouRealizeTheyreEvilRight_AsThePrisonPopulation::
	.string "As the prison population grew, pressure\n"
	.string "mounted both internally and externally\l"
	.string "in order to demand a better quality of\l"
	.string "life for the prisoners. The prison riot\l"
	.string "that started the occupation of the\l"
	.string "island came from an out of control\l"
	.string "guard killing an inmate for a minor\l"
	.string "violation.$"

gText_YouRealizeTheyreEvilRight_TheInmateWasAlso::
	.string "The inmate was also a member of\n"
	.string "SanFran's indingeous population, killed\l"
	.string "on the land that was stolen from their\l"
	.string "ancestors. The occupation called for\l"
	.string "the dissolution of the prison, transfer\l"
	.string "of prisoners to locations with humane\l"
	.string "conditions, and the return of the land\l"
	.string "back to its original owners.$"

gText_YouRealizeTheyreEvilRight_TheProtests::
	.string "The protests gained national attention\n"
	.string "and seemed to be gathering interest,\l"
	.string "particularly with the help of Drasna's\l"
	.string "support, and pressure mounted on the\l"
	.string "government to comply. At the height of\l"
	.string "tension, an earthquake broke out,\l"
	.string "destroying a large portion of the\l"
	.string "prison and killing inmates and guards\l"
	.string "and effectively ending the occupation.$"

gText_YouRealizeTheyreEvilRight_TheChampionHasArrived::
	.string "The Champion has arrived! Great to meet\n"
	.string "you, I'm Psfelite2, and I'm the leader\l"
	.string "of the Psfregion1 Elite Four. Or, I was.\l"
	.string "Now I'm not really sure what I do.$"

gText_YouRealizeTheyreEvilRight_NiceToMeetYou::
	.string "Nice to meet you! …Psfnativerival,\n"
	.string "where are we?$"

gText_YouRealizeTheyreEvilRight_HasBeenUsing::
	.string "Psfgoodteam has been using Psfcave's\n"
	.string "abandoned prison as a training ground.$"

gText_YouRealizeTheyreEvilRight_WowSuperResourceful::
	.string "Wow! Super resourceful. Genius, even.$"

gText_YouRealizeTheyreEvilRight_WhyAreWeHere::
	.string "Why are we here?$"

gText_YouRealizeTheyreEvilRight_ICanFinallyProve::
	.string "I can finally prove that Psfbadguy is\n"
	.string "worse than we originally thought. Once\l"
	.string "I do that, I want all of us to find a way\l"
	.string "to work together to protect\l"
	.string "Psfregion1 from their bullshit.$"

gText_YouRealizeTheyreEvilRight_DidYouDragMe::
	.string "Did you drag me out here to join a\n"
	.string "terrorist organiziation? Did you hear\l"
	.string "ANYTHING I said on the phone?$"

gText_YouRealizeTheyreEvilRight_YesWaitNo::
	.string "Yes! Wait, no… No, Yes!$"

gText_YouRealizeTheyreEvilRight_DoesntDoAnythingForThis::
	.string "Psfgoodteam doesn't do anything for\n"
	.string "this region. You're attacking innocent\l"
	.string "people, trying to destroy buildings -\l"
	.string "fuck, I absolutely should have turned\l"
	.string "you in!$"

gText_YouRealizeTheyreEvilRight_ICanProve::
	.string "{PLAYER}, listen! I can prove that\n"
	.string "none of that is true.$"

gText_YouRealizeTheyreEvilRight_How::
	.string "How?!?$"

gText_YouRealizeTheyreEvilRight_Look::
	.string "Look.$"

gText_YouRealizeTheyreEvilRight_ThisIsOne::
	.string "This is one of the Garbador from the\n"
	.string "Psfplace14 strike. {PLAYER}, you\l"
	.string "were told that Psfgoodteam planted\l"
	.string "these to blow up the construction\l"
	.string "site, right?$"

gText_YouRealizeTheyreEvilRight_IHadToGo::
	.string "Yeah. Psftransrival and I had to go\n"
	.string "down there and defeat them and your\l"
	.string "goons.$"

gText_YouRealizeTheyreEvilRight_ThisOneIsLevel::
	.string "This one is Level 40. Garbador learns\n"
	.string "Explosion at Level 53.$"

gText_YouRealizeTheyreEvilRight_ButTheyDefinitelyCan::
	.string "But they definitely can explode… so\n"
	.string "they're using Self-Destruct instead,\l"
	.string "right?$"

gText_YouRealizeTheyreEvilRight_DoesntLearnThatNaturally::
	.string "Right. But Garbador doesn't learn that\n"
	.string "naturally. It can only be inherited\l"
	.string "from its parents, or taught via a\l"
	.string "Technical Machine.$"

gText_YouRealizeTheyreEvilRight_SoUsedATM::
	.string "Okay, so Psfgoodteam used a TM… wait.$"

gText_YouRealizeTheyreEvilRight_NoItMustHaveBeenBred::
	.string "No, it must have been bred then.$"

gText_YouRealizeTheyreEvilRight_TakeACloserLook::
	.string "Take a closer look.$"

gText_YouRealizeTheyreEvilRight_DoYouSeeNow::
	.string "Do you see now?$"

gText_YouRealizeTheyreEvilRight_AhVeryAstute::
	.string "Ah, very astute. What seemed off to\n"
	.string "you?$"

gText_YouRealizeTheyreEvilRight_WaitWhichMove::
	.string "Wait, which move tipped you off?$"

gText_YouRealizeTheyreEvilRight_VeryClever::
	.string "Very clever, {PLAYER}! You realized\n"
	.string "that Haze can only be passed down from\l"
	.string "the Yamask family, and Yamask can't\l"
	.string "learn Self-Destruct. This Garbrador\l"
	.string "had to learn the move via TM.$"

gText_YouRealizeTheyreEvilRight_TheTipOff::
	.string "The tip-off is that this Garbador knows\n"
	.string "Haze.$"

gText_YouRealizeTheyreEvilRight_So::
	.string "…so?$"

gText_YouRealizeTheyreEvilRight_HazeCanOnly::
	.string "Haze can only be passed down from the\n"
	.string "Yamask family, and Yamask can't learn\l"
	.string "Self-Destruct. This Garbrador had to\l"
	.string "learn the move via TM.$"

gText_YouRealizeTheyreEvilRight_IDontGetIt::
	.string "I don't get it then. So this Garbador\n"
	.string "was taught Self-Destruct. What does\l"
	.string "that mean?$"

gText_YouRealizeTheyreEvilRight_HasBeenFramingYou::
	.string "Psfnativerival… Psfbadguy has been\n"
	.string "framing you?$"

gText_YouRealizeTheyreEvilRight_YouAlsoMetUp::
	.string "{PLAYER}, you also met up with\n"
	.string "Psfgoodteam in Psfcity9 too, right?$"

gText_YouRealizeTheyreEvilRight_ButPsfgoodadminSaid::
	.string "…yeah. But Psfgoodadmin said that\n"
	.string "situation was super weird and was\l"
	.string "trying to track them down.$"

gText_YouRealizeTheyreEvilRight_YeahNobodyKnows::
	.string "Yeah, nobody knows who they are or\n"
	.string "where they came from. I'm pretty sure\l"
	.string "Psfbadguy has been sending in agents\l"
	.string "to make us look shitty. Between that\l"
	.string "and whatever else Psfbadguy is\l"
	.string "feeding you, I'm not surprised you feel\l"
	.string "the way you do.$"

gText_YouRealizeTheyreEvilRight_WhyWhyDoAll::
	.string "Why? Why do all this to just to screw\n"
	.string "with you guys?$"

gText_YouRealizeTheyreEvilRight_ExistsToMakeMoney::
	.string "Psfbadguy exists to make money. They\n"
	.string "don't care about you. Or us. Or the\l"
	.string "region. You weren't here when they\l"
	.string "first bought the League. They were\l"
	.string "ruthless. Fired thousands of people,\l"
	.string "dismantled and reshaped communities -\l"
	.string "all for their agenda.$"

gText_YouRealizeTheyreEvilRight_CantArgueWithThat::
	.string "Can't argue with that.$"

gText_YouRealizeTheyreEvilRight_IJoinedThe::
	.string "I joined the League Challenge to try to\n"
	.string "change things from the inside. But now\l"
	.string "I'm certain that we need external\l"
	.string "pressure in order to improve things for\l"
	.string "all of us.$"

gText_YouRealizeTheyreEvilRight_AndThatsWhyWere::
	.string "And that's why we're all here?$"

gText_YouRealizeTheyreEvilRight_YepIThinkItsFinally::
	.string "Yep. I think it's finally time we all come\n"
	.string "together to expose Psfbadguy for the\l"
	.string "assholes that they are, and start to\l"
	.string "take power back for the people.$"

gText_YouRealizeTheyreEvilRight_KidIfTheEliteFour::
	.string "Kid, if the Elite Four couldn't stop them\n"
	.string "in their prime, I don't know what you\l"
	.string "think Psfgoodteam will be able to do.\l"
	.string "Matter of fact, going solo might\l"
	.string "actually be better! Hell, I was able to\l"
	.string "start the Psfcave7 campaigns without\l"
	.string "any help.$"

gText_YouRealizeTheyreEvilRight_ThingsAreDifferentNow::
	.string "Look Psfelite2… things are different\n"
	.string "now. We've been fighting the good fight\l"
	.string "without any help so far… and look where\l"
	.string "that's gotten us. Perhaps they're onto\l"
	.string "something, and it's time for some real\l"
	.string "collective action.$"

gText_YouRealizeTheyreEvilRight_LookIKnowThis::
	.string "Look, I know this is a lot of information\n"
	.string "to take in. I know you're going to make\l"
	.string "the right decision. Go home. Get some\l"
	.string "sleep. Come back here when you're ready\l"
	.string "to work with us, okay?$"

gText_YouRealizeTheyreEvilRight_YeahOkay::
	.string "Yeah… okay.$"

gText_YouRealizeTheyreEvilRight_ThisGarbodor::
	.string "Hey, this Garbador seems to have taken\n"
	.string "a liking to you, and you seem to\l"
	.string "understand it pretty well. Do you want\l"
	.string "it?$"

gText_YouRealizeTheyreEvilRight_TakeGoodCare::
	.string "Take good care of it.$"

gText_YouRealizeTheyreEvilRight_ThatsFineIll::
	.string "That's fine, I'll find a good home for it.$"

gText_YouRealizeTheyreEvilRight_IsStillWaiting::
	.string "Psfnativerival is still waiting for me at\n"
	.string "Psfcave7…$"

gText_YouRealizeTheyreEvilRight_DoYouWantToGo::
	.string "Do you want to go to bed?$"

gText_YouRealizeTheyreEvilRight_IHaveNoIdeaWhat::
	.string "…I have no idea what I'm going to do. Do\n"
	.string "I help Psfbadguy and the police end\l"
	.string "Psfgoodteam permanently? Or do I help\l"
	.string "Psfgoodteam clear their name and help\l"
	.string "the people of Psfregion1?$"
