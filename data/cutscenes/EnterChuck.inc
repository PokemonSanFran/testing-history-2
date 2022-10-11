EnterChuck_Event_Script::
	switch VAR_GYM_5_STATE
	case 3, EnterChuck_Event_Script_2
	case 4, EnterChuck_Event_Script_3
	case 5, EnterChuck_Event_Script_4
	goto EnterChuck_Intro_Dialogue
	return

EnterChuck_Event_Script_2:
	goto EnterChuck_StartBattle_Script
	return

EnterChuck_Event_Script_3:
	goto EnterChuck_PostDefeat1_Dialogue
	return

EnterChuck_Event_Script_4:
	goto EnterChuck_PostDefeat2_Dialogue
	return


EnterChuck_Intro_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_AintItBeautiful, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_DoYouKnow
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterChuck_NoWh
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_IllTellYouWhy
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_YaKnowWhat
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterChuck_WeWould
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_WeWouldBlowThem
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_ThatRawPower
	callnative ClearMugshot
	setvar VAR_GYM_5_STATE, GYM_SAVE_BEFORE_LEADER
	call Common_EventScript_SaveGame
	closemessage
	goto EnterChuck_StartBattle_Script
	return


EnterChuck_StartBattle_Script::
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	trainerbattle_single TRAINER_NORMAN_1, gText_EnterChuck_NowImGonnaShow, gText_EnterChuck_ManDown, EnterChuck_ChuckDefeated_Script, NO_MUSIC
	return


EnterChuck_ChuckDefeated_Script::
	lock
	setflag FLAG_BADGE05_GET
	setvar VAR_GYM_5_STATE, GYM_DEFEATED_LEADER
	setvar VAR_CHUCK_STATE, BATTLE_1_COMPLETE
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_YoureNoJoke
	callnative ClearMugshot
	msgbox gText_EnterChuck_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM05
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_FORTPOINT_STATE, DEFEATED_CHUCK
	release
	end


EnterChuck_PostDefeat1_Dialogue::
	setvar VAR_GYM_5_STATE, GYM_EXPLAINED_BADGE_AND_TM
	lock
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_MaybeMyDefense, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	release
	end


EnterChuck_PostDefeat2_Dialogue::
	lock
	setvar VAR_MUGSHOT, MUGSHOT_CHUCK
	callnative DrawMugshot
	msgbox gText_EnterChuck_ManTheCompetition, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	release
	end


gText_EnterChuck_AintItBeautiful::
	.string "Ain't it beautiful? All of it! The bridge,\n"
	.string "the ocean, this base.$"

gText_EnterChuck_DoYouKnow::
	.string "Do you know why I built the Gym into the\n"
	.string "base, {PLAYER}?$"

gText_EnterChuck_NoWh::
	.string "No, wh -$"

gText_EnterChuck_IllTellYouWhy::
	.string "I'll tell you why! Because this base\n"
	.string "represents the crown jewel of this\l"
	.string "here nation: our military defense.\l"
	.string "We're so strong, people don't even\l"
	.string "DREAM of attacking us!$"

gText_EnterChuck_YaKnowWhat::
	.string "Ya know what happens if they did\n"
	.string "attack?$"

gText_EnterChuck_WeWould::
	.string "We would -$"

gText_EnterChuck_WeWouldBlowThem::
	.string "WE WOULD BLOW THEM TO SMITHEEREENS! Oh\n"
	.string "baby, just gets me excited thinking\l"
	.string "about how we can blow those idiots\l"
	.string "right back to the Stone Age.$"

gText_EnterChuck_ThatRawPower::
	.string "That raw power is so inspiring, once I\n"
	.string "got the chance, I knew I wanted my\l"
	.string "career to have the energy of that\l"
	.string "legacy. That's why we're up here.$"

gText_EnterChuck_NowImGonnaShow::
	.string "Now, I'm gonna show you that same raw\n"
	.string "defensive power! Buckle up, solider!$"

gText_EnterChuck_WeGotACode::
	.string "We got a code Oscar Uniform Charlie\n"
	.string "Hotel on our hands.$"

gText_EnterChuck_ScrambleTheJets::
	.string "Scramble the jets!$"

gText_EnterChuck_ThreatNeutralized::
	.string "Threat neutralized.$"

gText_EnterChuck_ManDown::
	.string "Man down, man down!$"

gText_EnterChuck_YoureNoJoke::
	.string "You're no joke! My strategy is usually\n"
	.string "to wear the opponent out, but I ran out\l"
	.string "of gas quick against you!$"

gText_EnterChuck_BadgeGet::
	.string "You received the ChuckBadge Badge!$"

gText_EnterChuck_MaybeMyDefense::
	.string "Maybe my defense wasn't strong\n"
	.string "enough? Should I start using\l"
	.string "Sandstorm? Maybe Toxic...$"

gText_EnterChuck_ManTheCompetition::
	.string "Man, the competition at the League\n"
	.string "Finals is gonna a hell of a show. All you\l"
	.string "kids coming through here are gonna\l"
	.string "rise real quick through the ranks!$"
