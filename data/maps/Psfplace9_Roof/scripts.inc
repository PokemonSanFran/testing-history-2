Psfplace9_Roof_MapScripts::
	.byte 0


EnterPsfleader5_Event_Script::
	switch VAR_GYM_5_STATE
	case 3, EnterPsfleader5_Event_Script_2
	case 4, EnterPsfleader5_Event_Script_3
	case 5, EnterPsfleader5_Event_Script_4
	goto EnterPsfleader5_Psfleader5Intro_Dialogue
	return

EnterPsfleader5_Event_Script_2:
	goto EnterPsfleader5_StartGymBattle_Script
	return

EnterPsfleader5_Event_Script_3:
	goto EnterPsfleader5_PostDefeat1_Dialogue
	return

EnterPsfleader5_Event_Script_4:
	goto EnterPsfleader5_PostDefeat2_Dialogue
	return


EnterPsfleader5_Psfleader5Intro_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_AintItBeautiful, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_DoYouKnow
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_NoWh
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_IllTellYouWhy
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_YaKnowWhat
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_WeWould
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_WeWouldBlowThem
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_ThatRawPower
	callnative ClearMugshot
	setvar VAR_GYM_5_STATE, 3
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader5_StartGymBattle_Script
	return


EnterPsfleader5_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	trainerbattle_single TRAINER_NORMAN_1, gText_EnterPsfleader5_NowImGonnaShow, gText_EnterPsfleader5_ManDown, EnterPsfleader5_Psfleader5Defeated_Script, NO_MUSIC
	return


EnterPsfleader5_Psfleader5Defeated_Script::
	lockall
	setflag FLAG_BADGE05_GET
	setvar VAR_GYM_5_STATE, 4
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_YoureNoJoke
	callnative ClearMugshot
	msgbox gText_EnterPsfleader5_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM05
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	releaseall
	end


EnterPsfleader5_PostDefeat1_Dialogue::
	setvar VAR_GYM_5_STATE, 5
	lockall
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_MaybeMyDefense, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader5_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterPsfleader5_ManTheCompetition, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


gText_EnterPsfleader5_AintItBeautiful::
	.string "Ain't it beautiful? All of it! The bridge,\n"
	.string "the ocean, this base.$"

gText_EnterPsfleader5_DoYouKnow::
	.string "Do you know why I built the Gym into the\n"
	.string "base, {PLAYER}?$"

gText_EnterPsfleader5_NoWh::
	.string "No, wh -$"

gText_EnterPsfleader5_IllTellYouWhy::
	.string "I'll tell you why! Because this base\n"
	.string "represents the crown jewel of this\l"
	.string "here nation: our military defense.\l"
	.string "We're so strong, people don't even\l"
	.string "DREAM of attacking us!$"

gText_EnterPsfleader5_YaKnowWhat::
	.string "Ya know what happens if they did\n"
	.string "attack?$"

gText_EnterPsfleader5_WeWould::
	.string "We would -$"

gText_EnterPsfleader5_WeWouldBlowThem::
	.string "WE WOULD BLOW THEM TO SMITHEEREENS! Oh\n"
	.string "baby, just gets me excited thinking\l"
	.string "about how we can blow those idiots\l"
	.string "right back to the Stone Age.$"

gText_EnterPsfleader5_ThatRawPower::
	.string "That raw power is so inspiring, once I\n"
	.string "got the chance, I knew I wanted my\l"
	.string "career to have the energy of that\l"
	.string "legacy. That's why we're up here.$"

gText_EnterPsfleader5_NowImGonnaShow::
	.string "Now, I'm gonna show you that same raw\n"
	.string "defensive power! Buckle up, solider!$"

gText_EnterPsfleader5_WeGotACode::
	.string "We got a code Oscar Uniform Charlie\n"
	.string "Hotel on our hands.$"

gText_EnterPsfleader5_ScrambleTheJets::
	.string "Scramble the jets!$"

gText_EnterPsfleader5_ThreatNeutralized::
	.string "Threat neutralized.$"

gText_EnterPsfleader5_ManDown::
	.string "Man down, man down!$"

gText_EnterPsfleader5_YoureNoJoke::
	.string "You're no joke! My strategy is usually\n"
	.string "to wear the opponent out, but I ran out\l"
	.string "of gas quick against you!$"

gText_EnterPsfleader5_BadgeGet::
	.string "You received the Psfbadge5 Badge!$"

gText_EnterPsfleader5_MaybeMyDefense::
	.string "Maybe my defense wasn't strong\n"
	.string "enough? Should I start using\l"
	.string "Sandstorm? Maybe Toxic...$"

gText_EnterPsfleader5_ManTheCompetition::
	.string "Man, the competition at the League\n"
	.string "Finals is gonna a hell of a show. All you\l"
	.string "kids coming through here are gonna\l"
	.string "rise real quick through the ranks!$"
