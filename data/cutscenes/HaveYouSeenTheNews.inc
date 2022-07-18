HaveYouSeenTheNews_AskHelp_Dialogue::
	addvar VAR_ROUTE116_STATE, 1
	setvar VAR_SALESFORCETOWER_2F_STATE, 3
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, EnterTheMaster_ApproachSiebold
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_WedLikeYourHelp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_ShitWhatDid
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_YoureStartingToSound
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_HowAreWeGoing
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_NoTimeToExplain, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq HaveYouSeenTheNews_AskHelp_Dialogue_1
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_CoolTheCar
	callnative ClearMugshot
	closemessage
	releaseall
	warpsilent MAP_SALESFORCETOWER_2F, 255, 7, 14
	end

HaveYouSeenTheNews_AskHelp_Dialogue_1:
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_FineButDontDawdle
	callnative ClearMugshot
	closemessage
	applymovement 3, HaveYouSeenTheNews_LeaveClearingA
	applymovement 1, HaveYouSeenTheNews_LeaveClearingB
	waitmovement 0
	playse SE_EXIT
	waitse
	removeobject 1
	removeobject 3
	return


HaveYouSeenTheNews_LeaveClearingA:
	walk_down
	walk_down
	walk_down
	step_end

HaveYouSeenTheNews_LeaveClearingB:
	walk_down
	walk_down
	step_end

gText_HaveYouSeenTheNews_WedLikeYourHelp::
	.string "We'd like your help again.$"

gText_HaveYouSeenTheNews_ShitWhatDid::
	.string "Shit, what did TeamRocket do now?$"

gText_HaveYouSeenTheNews_YoureStartingToSound::
	.string "You're starting to sound like a native…\n"
	.string "they've completely infiltrated our\l"
	.string "social media platforms. The mayor was\l"
	.string "impressed with your work at\l"
	.string "ChaseCenter, and thinks you two might\l"
	.string "be able to help.$"

gText_HaveYouSeenTheNews_HowAreWeGoing::
	.string "How are we going to help? Sounds a\n"
	.string "little above us.$"

gText_HaveYouSeenTheNews_NoTimeToExplain::
	.string "No time to explain! We're heading to\n"
	.string "Salesforcetower right now. Do you want\l"
	.string "to ride in our Uber, {PLAYER}?$"

gText_HaveYouSeenTheNews_FineButDontDawdle::
	.string "Fine, but don't dawdle. Come to the\n"
	.string "second floor.$"

gText_HaveYouSeenTheNews_SoundsLikeYouve::
	.string "Sounds like you've been deputized, kid.\n"
	.string "Just make sure you don't end up a pawn,\l"
	.string "yeah? You've got real potential.$"

gText_HaveYouSeenTheNews_CoolTheCar::
	.string "Cool, the car is waiting in Marin.$"
