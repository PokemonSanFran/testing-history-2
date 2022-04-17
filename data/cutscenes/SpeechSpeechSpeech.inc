SpeechSpeechSpeech_MoveObject_Script::
	setflag FLAG_TEMP_4
	setobjectxy 1, 11, 8
	setobjectxyperm 1, 11, 8
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectxy 3, 8, 3
	setobjectxyperm 3, 8, 3
	setobjectxy 2, 8, 6
	setobjectxyperm 2, 8, 6
	return


SpeechSpeechSpeech_Intro_Dialogue::
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ThankYouAll
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_FirstOfAll
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ForAllYouve
	msgbox gText_SpeechSpeechSpeech_WaitWhat
	msgbox gText_SpeechSpeechSpeech_AreTheyEven
	setvar VAR_0x8000, MUGSHOT_GIOVANNI
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_HasMyFullConfidence
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_Us
	msgbox gText_SpeechSpeechSpeech_HolyShit
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_IsAnybodyHurt
	msgbox gText_SpeechSpeechSpeech_Yeah
	msgbox gText_SpeechSpeechSpeech_HellYes
	setvar VAR_0x8000, MUGSHOT_ARIANA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_YouAllKnowHowCompanies
	msgbox gText_SpeechSpeechSpeech_WereFinally
	msgbox gText_SpeechSpeechSpeech_ThisIsInsane
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_WeWantToBegin
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_4LeadCharge
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_3LeadCharge
	setvar VAR_0x8000, MUGSHOT_GRIMSLEY
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_1LeadCharge
	setvar VAR_0x8000, MUGSHOT_SHAUNTAL
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_IllBeHandling
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_DamnThisShit
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ItFeelsReally
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_Yeah
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_YeahAlsoAre
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_ByTheWay
	setvar VAR_0x8000, MUGSHOT_HUGH
	callnative DrawMugshot
	msgbox gText_SpeechSpeechSpeech_Peace
	return


gText_SpeechSpeechSpeech_ThankYouAll::
	.string "Thank you all for coming. For all your\n"
	.string "hard work. All your support. I have a\l"
	.string "few announcements for you all.$"

gText_SpeechSpeechSpeech_FirstOfAll::
	.string "First of all, I will be taking a leave of\n"
	.string "absence. Effectively immediately,\l"
	.string "Psfgoodadmin will be leading\l"
	.string "Psfgoodteam. She has my full trust and\l"
	.string "support.$"

gText_SpeechSpeechSpeech_ForAllYouve::
	.string "Thank you for all you’ve done for us,\n"
	.string "Psfgoodboss, I hope to live up to your\l"
	.string "example.$"

gText_SpeechSpeechSpeech_WaitWhat::
	.string "Wait what?$"

gText_SpeechSpeechSpeech_AreTheyEven::
	.string "Are they even qualified?$"

gText_SpeechSpeechSpeech_HasMyFullConfidence::
	.string "Yes, Psfgoodadmin has my full\n"
	.string "confidence, as well as the backing of…$"

gText_SpeechSpeechSpeech_Us::
	.string "… US! The Elite Four of Psfregion1!$"

gText_SpeechSpeechSpeech_HolyShit::
	.string "Holy shit ok, good enough for me!$"

gText_SpeechSpeechSpeech_IsAnybodyHurt::
	.string "Is anybody hurt? …no? Wonderful. Let’s\n"
	.string "continue. Psfnatrival’s restoration\l"
	.string "project has been going excellently,\l"
	.string "and we’re going to use that momentum\l"
	.string "for our next stage. It’s time to take\l"
	.string "the fight to Psfbadguy!$"

gText_SpeechSpeechSpeech_Yeah::
	.string "Yeah!$"

gText_SpeechSpeechSpeech_HellYes::
	.string "Hell yes! Woo! Wait, where did\n"
	.string "Psfgoodboss go?$"

gText_SpeechSpeechSpeech_YouAllKnowHowCompanies::
	.string "You all know how companies like\n"
	.string "Psfcompany8 and Psfcompany7 have\l"
	.string "ruined our lives and families. But with\l"
	.string "the combined popularity of the\l"
	.string "Champion, Elite Four and our manpower,\l"
	.string "I think we can hurt these people where\l"
	.string "it counts: their wallets. We can’t drive\l"
	.string "these parasitic companies out of the\l"
	.string "region… but all that money has to go\l"
	.string "somewhere. Let’s use that money to\l"
	.string "strengthen the region and create a\l"
	.string "brighter future for us all.$"

gText_SpeechSpeechSpeech_WereFinally::
	.string "We’re finally doing it…$"

gText_SpeechSpeechSpeech_ThisIsInsane::
	.string "This is insane yo. But seriously, did\n"
	.string "they just disappear?$"

gText_SpeechSpeechSpeech_WeWantToBegin::
	.string "We want to begin by attacking the\n"
	.string "biggest players in Psfregion1. Each of\l"
	.string "us will handle a different offensive\l"
	.string "plan.$"

gText_SpeechSpeechSpeech_4LeadCharge::
	.string "Psfelite4 will lead the charge against\n"
	.string "Psfcompany8.$"

gText_SpeechSpeechSpeech_3LeadCharge::
	.string "Psfelite3 will lead the charge against\n"
	.string "Psfcompany5.$"

gText_SpeechSpeechSpeech_1LeadCharge::
	.string "Psfelite1 will lead the charge against\n"
	.string "Psfcompany7.$"

gText_SpeechSpeechSpeech_IllBeHandling::
	.string "And I’ll be handling negotiations with\n"
	.string "the government, and operations here.\l"
	.string "Psfgoodadmin will be giving each of you\l"
	.string "assignments under one of the Elite\l"
	.string "Four members, so listen up.$"

gText_SpeechSpeechSpeech_DamnThisShit::
	.string "Damn, this shit is so crazy! The air is\n"
	.string "electric!$"

gText_SpeechSpeechSpeech_ItFeelsReally::
	.string "It feels really awesome to start making\n"
	.string "a difference around here.$"

gText_SpeechSpeechSpeech_YeahAlsoAre::
	.string "Also, are you heading to that party in\n"
	.string "Psfcity9 now? I'll catch up with you in\l"
	.string "a second, I just gotta talk to\l"
	.string "Psfgoodadmin first.$"

gText_SpeechSpeechSpeech_ByTheWay::
	.string "By the way, you and I are free to work\n"
	.string "with whoever we want. Just talk to the\l"
	.string "Elite Four member you want to team up\l"
	.string "with. I gotta go, I told Psfgoodadmin\l"
	.string "I’d help them with some planning. Peace!$"

gText_SpeechSpeechSpeech_Peace::
	.string "Peace!$"
