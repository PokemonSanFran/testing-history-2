SorryAboutMyFriends_Ariana_Visible_Script::
	compare VAR_BERKELEY_STATE, DEFEATED_MORTY
	goto_if_ne SorryAboutMyFriends_Ariana_Visible_Script_2
SorryAboutMyFriends_Ariana_Visible_Script_1:
	return

SorryAboutMyFriends_Ariana_Visible_Script_2:
	setflag FLAG_TEMP_5
	goto SorryAboutMyFriends_Ariana_Visible_Script_1


SorryAboutMyFriends_CheckCutscene_Script::
	lock
	goto_if_unset FLAG_TEMP_5, SorryAboutMyFriends_CheckCutscene_Script_2
SorryAboutMyFriends_CheckCutscene_Script_1:
	release
	end

SorryAboutMyFriends_CheckCutscene_Script_2:
	goto SorryAboutMyFriends_Intro_Dialogue
	goto SorryAboutMyFriends_CheckCutscene_Script_1


SorryAboutMyFriends_Intro_Dialogue::
	lock
	playbgm MUS_RG_ENCOUNTER_ROCKET, FALSE
	applymovement 5, SorryAboutMyFriends_WalkToPlayer_Movement
	waitmovement 5
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_HowGoes
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ItWasWait
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_YourePartOf
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_DidINotMention
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WaitThatWas
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_UnfortunateWorldview
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_AreYouGuysHelping
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ThereWasAProtest
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_IWasTheOneWhoShut
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WhenTheyMentionedPowerful
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_UhHuh
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_OurHeartsAreInTheRightPlace
	msgbox gText_SorryAboutMyFriends_TrackDownTheMembers
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_GotPrettyFiredUp
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WorldNeedsMoreCompassion
	goto SorryAboutMyFriends_GiveTicket_Script
	return


SorryAboutMyFriends_GiveTicket_Script::
	giveitem ITEM_MYSTIC_TICKET, 1
	setvar VAR_BERKELEY_STATE, GOT_ALCATRAZ_TICKET
	setvar VAR_FERRY_STATE, FERRY_ALCATRAZ_AVAILABLE
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_IGiveYouALot
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_IAppreciateTheGesture
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WantedYouToGoThere
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ExcellentPlaceToTrain
	compare VAR_FAINTED_FOG_STATE, 0
	goto_if_gt SorryAboutMyFriends_GiveTicket_Script_2
SorryAboutMyFriends_GiveTicket_Script_1:
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_FollowSomeMoreLeads
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_AfterWeBattled
	setvar VAR_MUGSHOT, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_ThankYouEnjoy
	closemessage
	callnative ClearMugshot
	applymovement 5, SorryAboutMyFriends_WalkSouth
	waitmovement 5
	removeobject 5
	fadedefaultbgm
	release
	end

SorryAboutMyFriends_GiveTicket_Script_2:
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SorryAboutMyFriends_WaitForTheFog
	goto SorryAboutMyFriends_GiveTicket_Script_1


SorryAboutMyFriends_WalkSouth:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SorryAboutMyFriends_WalkToPlayer_Movement:
	emote_exclamation_mark
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

gText_SorryAboutMyFriends_HowGoes::
	.string "{PLAYER}. How goes your Gym\n"
	.string "Challenge?$"

gText_SorryAboutMyFriends_ItWasWait::
	.string "Good thanks! It's been - wait.$"

gText_SorryAboutMyFriends_YourePartOf::
	.string "You're part of TeamRocket, right?$"

gText_SorryAboutMyFriends_DidINotMention::
	.string "*sigh* Yeah, did I not mention that when\n"
	.string "we met in Tenderloin?$"

gText_SorryAboutMyFriends_WaitThatWas::
	.string "Wait, that was TeamRocket? Everytime I\n"
	.string "run into them, they're attacking\l"
	.string "innocent people!$"

gText_SorryAboutMyFriends_UnfortunateWorldview::
	.string "Actually, that... unfortunate worldview\n"
	.string "is why I'm here.$"

gText_SorryAboutMyFriends_AreYouGuysHelping::
	.string "What do you mean? Are you guys helping\n"
	.string "or hurting people? What's your deal?$"

gText_SorryAboutMyFriends_ThereWasAProtest::
	.string "There was a protest here earlier that\n"
	.string "involved the RocketAcronym, that\l"
	.string "apparently began to get out of hand.\l"
	.string "Two memb -$"

gText_SorryAboutMyFriends_IWasTheOneWhoShut::
	.string "I know. I was the one who shut your\n"
	.string "goons down. They were trying to\l"
	.string "destroy this building! Or take it back?\l"
	.string "I'm not really sure, but it was messed\l"
	.string "up.$"

gText_SorryAboutMyFriends_WhenTheyMentionedPowerful::
	.string "Well then, when they mentioned powerful\n"
	.string "Trainer, I should have assumed. And I'm\l"
	.string "very very sorry for their actions. We're\l"
	.string "all about peace and non-violence.$"

gText_SorryAboutMyFriends_UhHuh::
	.string "Uh huh.$"

gText_SorryAboutMyFriends_OurHeartsAreInTheRightPlace::
	.string "I hope our Tenderloin work shows that\n"
	.string "our hearts are in the right place. I'm\l"
	.string "actually here to fix this mess too.$"

gText_SorryAboutMyFriends_TrackDownTheMembers::
	.string "I've been trying to track down the\n"
	.string "TeamRocket members that you battled,\l"
	.string "but they're gone! Their names aren't\l"
	.string "familiar, so they must be new... I've\l"
	.string "already reprimanded our Recruitment\l"
	.string "and Training team. We can't afford to\l"
	.string "have idiots like that making us look\l"
	.string "bad.$"

gText_SorryAboutMyFriends_GotPrettyFiredUp::
	.string "I got pretty fired up when I fought\n"
	.string "them. I hate when people pick on the\l"
	.string "defenseless, but I'm glad you're not\l"
	.string "cool with it either.$"

gText_SorryAboutMyFriends_WaitHoldOn::
	.string "Actually, you should get the\n"
	.string "MortyBadge first. Let's talk when you\l"
	.string "do.$"

gText_SorryAboutMyFriends_WorldNeedsMoreCompassion::
	.string "The world needs more compassion like\n"
	.string "yours, {PLAYER}. If we could just\l"
	.string "take the time to learn about each\l"
	.string "other... actually, I have a good\l"
	.string "learning opportunity for you. Here.$"

gText_SorryAboutMyFriends_IGiveYouALot::
	.string "I give you a lot of apology gifts. I hope\n"
	.string "we stop screwing up and this is the\l"
	.string "last one!$"

gText_SorryAboutMyFriends_IAppreciateTheGesture::
	.string "I appreciate the gesture, but doesn't\n"
	.string "my pass from YCombinator get me to\l"
	.string "Alcatraz?$"

gText_SorryAboutMyFriends_WantedYouToGoThere::
	.string "It could, if YCombinator wanted you to\n"
	.string "go there. But now you can!$"

gText_SorryAboutMyFriends_ExcellentPlaceToTrain::
	.string "You'll learn a lot about SanFran by\n"
	.string "going, and it's an excellent place to\l"
	.string "train for the Gym Challenge. With that,\l"
	.string "you can go to Alcatraz from the\l"
	.string "Alameda Ferry.$"

gText_SorryAboutMyFriends_WaitForTheFog::
	.string "(Guess I should go while I wait for the\n"
	.string "fog to clear...)$"

gText_SorryAboutMyFriends_FollowSomeMoreLeads::
	.string "Do you know which way Rabia and Vitomar\n"
	.string "went? I'm going to follow some more\l"
	.string "leads.$"

gText_SorryAboutMyFriends_AfterWeBattled::
	.string "After we battled, they went towards\n"
	.string "Alameda.$"

gText_SorryAboutMyFriends_ThankYouEnjoy::
	.string "Thank you {PLAYER}. Enjoy Alcatraz.$"
