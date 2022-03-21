PsfbadbossWalkToPsfchara1_Script::
	lockall
	setvar VAR_PSFCITY15_STATE, 2
	playse SE_PIN
	playbgm MUS_RG_ENCOUNTER_DEOXYS, TRUE
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, PsfbadbossWalkToPsfchara1_Movement
	waitmovement 0
	goto PsfbadbossIntro_Dialogue
	return


PsfbadbossIntro_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_PsfbadbossWhatAShow_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Psfchara1YouWorkAt_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_PsfbadbossWhereMyManners_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Psfchara1ShouldHaveKnown_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_PsfbadbossDreamBig_Text1
	callnative ClearMugshot
	goto ShowPsfcompany3Tower_Script
	return


ShowPsfcompany3Tower_Script::
	fadescreen FADE_TO_BLACK
	callnative DrawMugshot
	msgbox gText_PsfbadbossYouShouldComeBy_Text1
	callnative ClearMugshot
	fadescreen FADE_FROM_BLACK
	goto EndMeetPsfbadboss_Dialouge
	return


EndMeetPsfbadboss_Dialouge::
	callnative DrawMugshot
	msgbox gText_PsfbadbossMeetingWithMayor_Text1
	callnative ClearMugshot
	closemessage
	applymovement 1, PsfBadbossWalkToMayor_Movement
	waitmovement 0
	removeobject 1
	playbgm MUS_RG_VERMILLION, TRUE
	releaseall
	end


PsfbadbossWalkToPsfchara1_Movement:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

PsfBadbossWalkToMayor_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

gText_PsfbadbossWhatAShow_Text1::
	.string "{PLAYER}! What a show! That was\n"
	.string "marvelous! Flying you in from Orre was\l"
	.string "absolutely worth it, for that battle\l"
	.string "alone.$"

gText_Psfchara1YouWorkAt_Text1::
	.string "Oh uh, thanks a lot, that's very nice. I'm\n"
	.string "guessing you work at Psfbadguy1…?$"

gText_PsfbadbossWhereMyManners_Text1::
	.string "Hah! Oh my, I'm sorry. Where are my\n"
	.string "manners? My name is Psfbadboss, and\l"
	.string "I'm the Psfbadguy1 League\l"
	.string "Commissioner.$"

gText_Psfchara1ShouldHaveKnown_Text1::
	.string "Oh! I guess I should have known that.\n"
	.string "Well um, thanks so much for the\l"
	.string "opportunity! I'm excited to be the\l"
	.string "region's next Champion.$"

gText_PsfbadbossDreamBig_Text1::
	.string "Dream big {PLAYER}! That's the\n"
	.string "attitude we wanna see. We're big\l"
	.string "dreamers over at Psfbadguy1 too.\l"
	.string "That's why we built the Psfcompany3\l"
	.string "Tower!$"

gText_PsfbadbossYouShouldComeBy_Text1::
	.string "You should come by once you're done\n"
	.string "exploring the city proper, my office is\l"
	.string "on the 10th floor.$"

gText_PsfbadbossMeetingWithMayor_Text1::
	.string "I have to run to a meeting with the\n"
	.string "Mayor. Again, excellent job against\l"
	.string "Psfleader3. I hope to see what else you\l"
	.string "can do!$"
