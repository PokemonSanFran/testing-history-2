HaveYouSeenTheNews_Object_SetUp_Script::
	clearflag FLAG_HIDE_PSFCAVE2_PSFBADADMIN
	return


HaveYouSeenTheNews_Object_CleanUp_Script::
	setflag FLAG_HIDE_PSFCAVE2_PSFELITE3
	return


HaveYouSeenTheNews_AskHelp_Dialogue::
	setvar VAR_ROUTE116_STATE, 8
	setvar VAR_PSFBADGUY1TOWER_2F_STATE, 3
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, EnterTheMaster_ApproachPsfelite3
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
	warpsilent MAP_PSFBADGUY1TOWER_2F, 255, 7, 14
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


HaveYouSeenTheNews_Interact_Script::
	lockall
	setvar VAR_0x8000, MUGSHOT_MARSHAL
	callnative DrawMugshot
	msgbox gText_HaveYouSeenTheNews_SoundsLikeYouve
	callnative ClearMugshot
	closemessage
	releaseall
	end


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
	.string "Shit, what did Psfgoodteam do now?$"

gText_HaveYouSeenTheNews_YoureStartingToSound::
	.string "You're starting to sound like a native…\n"
	.string "they've completely infiltrated our\l"
	.string "social media platforms. The mayor was\l"
	.string "impressed with your work at\l"
	.string "Psfplace14, and thinks you two might\l"
	.string "be able to help.$"

gText_HaveYouSeenTheNews_HowAreWeGoing::
	.string "How are we going to help? Sounds a\n"
	.string "little above us.$"

gText_HaveYouSeenTheNews_NoTimeToExplain::
	.string "No time to explain! We're heading to\n"
	.string "Psfbadguy1tower right now. Do you\l"
	.string "want to ride in our Psfcompany5,\l"
	.string "{PLAYER}?$"

gText_HaveYouSeenTheNews_FineButDontDawdle::
	.string "Fine, but don't dawdle. Come to the\n"
	.string "second floor.$"

gText_HaveYouSeenTheNews_SoundsLikeYouve::
	.string "Sounds like you've been deputized, kid.\n"
	.string "Just make sure you don't end up a pawn,\l"
	.string "yeah? You've got real potential.$"

gText_HaveYouSeenTheNews_CoolTheCar::
	.string "Cool, the car is waiting in Psfcity10.$"
