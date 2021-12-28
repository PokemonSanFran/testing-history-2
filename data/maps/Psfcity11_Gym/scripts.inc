Psfcity11_Gym_MapScripts::
	.byte 0


EnterPsfleader4_Event_Script::
	switch VAR_GYM_4_STATE
	case 3, EnterPsfleader4_Event_Script_2
	case 4, EnterPsfleader4_Event_Script_3
	case 5, EnterPsfleader4_Event_Script_4
	goto EnterPsfleader4_Psfleader4Intro_Dialogue
	return

EnterPsfleader4_Event_Script_2:
	goto EnterPsfleader4_StartGymBattle_Script
	return

EnterPsfleader4_Event_Script_3:
	goto EnterPsfleader4_PostDefeat1_Dialogue
	return

EnterPsfleader4_Event_Script_4:
	goto EnterPsfleader4_PostDefeat2_Dialogue
	return


EnterPsfleader4_Psfleader4Intro_Dialogue::
	setvar VAR_GYM_4_STATE, 3
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_SuhDude, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_EvenBeenBattleResort, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_No, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_BruhYouveGotta, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_OhUhSoundsCool, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_ForRealISwear, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_SoundsExciting, MSGBOX_NPC
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader4_StartGymBattle_Script
	return


EnterPsfleader4_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	trainerbattle_single TRAINER_FLANNERY_1, gText_EnterPsfleader4_HaHaNoYeah, gText_EnterPsfleader4_ImNotTrippin, EnterPsfleader4_Psfleader4Defeated_Script, NO_MUSIC
	return


EnterPsfleader4_Psfleader4Defeated_Script::
	lockall
	setflag FLAG_BADGE04_GET
	setvar VAR_GYM_4_STATE, 4
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_ThatBattleWasHype, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_EnterPsfleader4_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM17
	closemessage
	addvar VAR_STORYLINE_STATE, 1
	releaseall
	end


EnterPsfleader4_PostDefeat1_Dialogue::
	setvar VAR_GYM_4_STATE, 5
	lockall
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_KeepingTheBabiesSafe, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader4_PostDefeat2_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader4_HeadOutToHoenn, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


gText_EnterPsfleader4_SuhDude::
	.string "Suh dude. Name's Psfleader4. Sick job\n"
	.string "making it up here!$"

gText_EnterPsfleader4_EvenBeenBattleResort::
	.string "Ever been to the Battle Resort?$"

gText_EnterPsfleader4_No::
	.string "... no?$"

gText_EnterPsfleader4_BruhYouveGotta::
	.string "Bruh, you've gotta go some day. Sickest\n"
	.string "place to breed Pokémon in the WORLD.\l"
	.string "And I've been to them all. The breeze in\l"
	.string "your hair, the sand in your tires, the\l"
	.string "faint smell of ocean... man that shit\l"
	.string "just hits, you know? Gets me all fired\l"
	.string "up!$"

gText_EnterPsfleader4_OhUhSoundsCool::
	.string "Oh uh, sounds cool I guess...$"

gText_EnterPsfleader4_ForRealISwear::
	.string "For real, I swear, the Eggs like... prefer\n"
	.string "the quiet environment or something.\l"
	.string "Like yeah, these Psfcity11 perks is\l"
	.string "hella crisp, but there's something\l"
	.string "about being out there, riding back and\l"
	.string "forth, that really does it for me. It's\l"
	.string "like... meditation or some shit, fasho. I\l"
	.string "be straight GIGGIN'.$"

gText_EnterPsfleader4_SoundsExciting::
	.string "Sounds exciting. Or relaxing? I can't\n"
	.string "really tell.$"

gText_EnterPsfleader4_HaHaNoYeah::
	.string "Ha ha, no, yeah. All right, I know you\n"
	.string "didn't come here to talk about Eggs.\l"
	.string "You tryna scramble?$"

gText_EnterPsfleader4_DamnSonYouHit::
	.string "Damn son, you hit hard!$"

gText_EnterPsfleader4_AightTimeToRep::
	.string "Aight, time to rep Psfcity11 strong!$"

gText_EnterPsfleader4_YourSquadIsHella::
	.string "Your squad is hella over easy.$"

gText_EnterPsfleader4_ImNotTrippin::
	.string "I'm not trippin' - that was hella tight.\n"
	.string "Harder than a 15-minute egg.$"

gText_EnterPsfleader4_ThatBattleWasHype::
	.string "That battle was HYPE! I fuck with that\n"
	.string "skill, mad heavy. You earned this.$"

gText_EnterPsfleader4_KeepingTheBabiesSafe::
	.string "Protect is for keeping the babies safe,\n"
	.string "like an eggshell! Just don't use it over\l"
	.string "and over and over again, ‘cause it gets\l"
	.string "real janky, real quick, like an eggshell.$"

gText_EnterPsfleader4_HeadOutToHoenn::
	.string "I'm gonna head out to Hoenn and breed a\n"
	.string "whole new squad! I can't wait to fight\l"
	.string "you again, {PLAYER} .$"

gText_EnterPsfleader4_BadgeGet::
	.string "You received the Psfbadge4 Badge!$"
