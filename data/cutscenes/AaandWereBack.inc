AaandWereBack_ObjectSetUp_Script::
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_2
	return


AaandWereBack_ObjectHide_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


Act1_1_Check_Script::
	compare VAR_STORYLINE_STATE, 9
	goto_if_eq Act1_1_Check_Script_1
	return

Act1_1_Check_Script_1:
	call AaandWereBack_Monologue
	return


AaandWereBack_Monologue::
	lock
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_GotAllThree
	callnative ClearMugshot
	closemessage
	call AaandWereBack_WarpToCompound_Script
	release
	end


AaandWereBack_WarpToCompound_Script::
	addvar VAR_LITTLEROOT_INTRO_STATE, 1
	msgbox gText_AaandWereBack_Question, MSGBOX_YESNO
	closemessage
	compare VAR_RESULT, YES
	goto_if_eq AaandWereBack_WarpToCompound_Script_1
	return

AaandWereBack_WarpToCompound_Script_1:
	warpsilent MAP_PSFCITY8, 255, 3, 10
	return


AaandWereBack_Bianca_Dialogue::
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_WhatsYourProgress, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_OnlyThree
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_YeahThatBusted
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_INeedToFigure
	setvar VAR_0x8000, MUGSHOT_BIANCA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_HardToComeBy
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_ImSureIllFigure
	callnative ClearMugshot
	closemessage
	return


AaandWereBack_FerryRepaired_Dialogue::
	addvar VAR_STORYLINE_STATE, 1
	msgbox gText_AaandWereBack_OpeningMessage, MSGBOX_POKENAV
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_ThatsDifferent
	callnative ClearMugshot
	pokenavcall gText_AaandWereBack_FerryMessage
	waitmessage
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_TooBadTheresNoFerry
	callnative ClearMugshot
	compare VAR_FAINTED_FOG_STATE, 1
	goto_if_gt AaandWereBack_FerryRepaired_Dialogue_2
AaandWereBack_FerryRepaired_Dialogue_1:
	closemessage
	return

AaandWereBack_FerryRepaired_Dialogue_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AaandWereBack_FindAWayThrough
	callnative ClearMugshot
	goto AaandWereBack_FerryRepaired_Dialogue_1


gText_AaandWereBack_GotAllThree::
	.string "I've got all three Badges from this side\n"
	.string "of the mainland. The ferry to Oakland\l"
	.string "looks like it's going to be broken utnil\l"
	.string "at least tomorrow, and I can't head\l"
	.string "west without Go-Goggles. It's been a\l"
	.string "long day... I think I should head back\l"
	.string "to SouthBay and call it a night.$"

gText_AaandWereBack_Question::
	.string "Do you want to go back to SouthBay?$"

gText_AaandWereBack_WhatsYourProgress::
	.string "Damn I'm beat. Getting five badges in\n"
	.string "one day was a hustle! What about you?$"

gText_AaandWereBack_OnlyThree::
	.string "Only three so far. I'm praying the ferry\n"
	.string "is fixed tomorrow.$"

gText_AaandWereBack_YeahThatBusted::
	.string "Yeah, that busted ferry sucks. I'm\n"
	.string "going to challenge the Castro and\l"
	.string "HaightAshbury Gyms tomorrow, and the ferry\l"
	.string "will definately be fixed after that, so\l"
	.string "Berkeley Gym will be last.$"

gText_AaandWereBack_INeedToFigure::
	.string "I need to figure out how to get some\n"
	.string "Go-Goggles too...$"

gText_AaandWereBack_HardToComeBy::
	.string "They're hard to come by right now. I\n"
	.string "only got these because Daddys knows\l"
	.string "the manufactuer over in Kanto.$"

gText_AaandWereBack_ImSureIllFigure::
	.string "I'm sure I'll figure something out.$"

gText_AaandWereBack_OpeningMessage::
	.string "You have recieved a message from\n"
	.string "PSFSUBWAY.$"

gText_AaandWereBack_FerryMessage::
	.string "A message from the PSFSUBWAY\n"
	.string "System. The following service\l"
	.string "routes are now operational:\p"
	.string "FerryBuilding to Alameda\p"
	.string "Alameda to Oakland\p"
	.string "We appreciate your patience\n"
	.string "while the remaining routes are\l"
	.string "restored.$"

gText_AaandWereBack_ThatsDifferent::
	.string "That's a different notification...$"

gText_AaandWereBack_TooBadTheresNoFerry::
	.string "Looks like east SanFran is next! Too\n"
	.string "bad there's no ferry directly to the\l"
	.string "Gym in Berkeley...$"

gText_AaandWereBack_FindAWayThrough::
	.string "Hopefully, I'll find a way through the\n"
	.string "fog after that...$"
