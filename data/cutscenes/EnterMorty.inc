EnterMorty_Event_Script::
	switch VAR_GYM_4_STATE
	case GYM_SAVE_BEFORE_LEADER, EnterMorty_Event_Script_2
	case GYM_DEFEATED_LEADER, EnterMorty_Event_Script_3
	case GYM_EXPLAINED_BADGE_AND_TM, EnterMorty_Event_Script_4
	goto EnterMorty_MortyIntro_Dialogue
	return

EnterMorty_Event_Script_2:
	goto EnterMorty_StartGymBattle_Script
	return

EnterMorty_Event_Script_3:
	goto EnterMorty_PostDefeat1_Dialogue
	return

EnterMorty_Event_Script_4:
	goto EnterMorty_PostDefeat2_Dialogue
	return


EnterMorty_MortyIntro_Dialogue::
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_SuhDude, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_EvenBeenBattleResort, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterMorty_No, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_BruhYouveGotta, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterMorty_OhUhSoundsCool, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_ForRealISwear, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterMorty_SoundsExciting, MSGBOX_NPC
	setvar VAR_GYM_4_STATE, GYM_SAVE_BEFORE_LEADER
	call Common_EventScript_SaveGame
	closemessage
	goto EnterMorty_StartGymBattle_Script
	return


EnterMorty_StartGymBattle_Script::
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	trainerbattle_single TRAINER_FLANNERY_1, gText_EnterMorty_HaHaNoYeah, gText_EnterMorty_ImNotTrippin, EnterMorty_MortyDefeated_Script, NO_MUSIC
	return


EnterMorty_MortyDefeated_Script::
	lock
	setflag FLAG_BADGE04_GET
	setflag FLAG_CONSTRUCTION_BREAKING_NEWS
	setvar VAR_GYM_4_STATE, GYM_DEFEATED_LEADER
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_ThatBattleWasHype, MSGBOX_NPC
	msgbox gText_EnterMorty_BadgeGet
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM17
	closemessage
	callnative ClearMugshot
	addvar VAR_STORYLINE_STATE, 1
	release
	end


EnterMorty_PostDefeat1_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_KeepingTheBabiesSafe, MSGBOX_NPC
	callnative ClearMugshot
	setvar VAR_GYM_4_STATE, GYM_EXPLAINED_BADGE_AND_TM
	closemessage
	release
	end


EnterMorty_PostDefeat2_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_MORTY
	callnative DrawMugshot
	msgbox gText_EnterMorty_HeadOutToHoenn, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	release
	end


gText_EnterMorty_SuhDude::
	.string "Suh dude. Name's Morty. Sick job making\n"
	.string "it up here!$"

gText_EnterMorty_EvenBeenBattleResort::
	.string "Ever been to the Battle Resort?$"

gText_EnterMorty_No::
	.string "... no?$"

gText_EnterMorty_BruhYouveGotta::
	.string "Bruh, you've gotta go some day. Sickest\n"
	.string "place to breed Pokémon in the WORLD.\l"
	.string "And I've been to them all. The breeze in\l"
	.string "your hair, the sand in your tires, the\l"
	.string "faint smell of ocean... man that shit\l"
	.string "just hits, you know? Gets me all fired\l"
	.string "up!$"

gText_EnterMorty_OhUhSoundsCool::
	.string "Oh uh, sounds cool I guess...$"

gText_EnterMorty_ForRealISwear::
	.string "For real, I swear, the Eggs like... prefer\n"
	.string "the quiet environment or something.\l"
	.string "Like yeah, these Berkeley perks is\l"
	.string "hella crisp, but there's something\l"
	.string "about being out there, riding back and\l"
	.string "forth, that really does it for me. It's\l"
	.string "like... meditation or some shit, fasho. I\l"
	.string "be straight GIGGIN'.$"

gText_EnterMorty_SoundsExciting::
	.string "Sounds exciting. Or relaxing? I can't\n"
	.string "really tell.$"

gText_EnterMorty_HaHaNoYeah::
	.string "Ha ha, no, yeah. All right, I know you\n"
	.string "didn't come here to talk about Eggs.\l"
	.string "You tryna scramble?$"

gText_EnterMorty_DamnSonYouHit::
	.string "Damn son, you hit hard!$"

gText_EnterMorty_AightTimeToRep::
	.string "Aight, time to rep Berkeley strong!$"

gText_EnterMorty_YourSquadIsHella::
	.string "Your squad is hella over easy.$"

gText_EnterMorty_ImNotTrippin::
	.string "I'm not trippin' - that was hella tight.\n"
	.string "Harder than a 15-minute egg.$"

gText_EnterMorty_ThatBattleWasHype::
	.string "That battle was HYPE! I fuck with that\n"
	.string "skill, mad heavy. You earned this.$"

gText_EnterMorty_KeepingTheBabiesSafe::
	.string "Protect is for keeping the babies safe,\n"
	.string "like an eggshell! Just don't use it over\l"
	.string "and over and over again, ‘cause it gets\l"
	.string "real jank, real quick, like an eggshell.$"

gText_EnterMorty_HeadOutToHoenn::
	.string "I'm gonna head out to Hoenn and breed a\n"
	.string "whole new squad! I can't wait to fight\l"
	.string "you again, {PLAYER} .$"

gText_EnterMorty_BadgeGet::
	.string "You received the MortyBadge Badge!$"
