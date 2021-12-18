Psfcity15_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_GYM_3_STATE
	case 1, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	case 2, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_3
	case 3, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_4
	return

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto ArrangementMuseum_ObjectSetUp
	return

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_3:
	goto Psfleader3StartBattle_ObjectSetup
	return

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_4:
	goto Psfleader3StartBattle_ObjectSetup
	return


ArrangementMuseum_ObjectSetUp::
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	end


Psfleader3StartBattle_ObjectSetup::
	setobjectxyperm 1, 10, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	end


AutomaticSolvePuzzle_Script::
	setflag FLAG_SOLVED_GYM_3_PUZZLE
	setvar VAR_GYM_3_STATE, 1
	msgbox AutomaticSolvePuzzle_Script_Text_0, MSGBOX_NPC
	return


Psfleader3WalkToBattlefield_Script::
	setvar VAR_GYM_3_STATE, 2
	lockall
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Psfleader3WalkToBattlefield_Movement
	waitmovement 0
	releaseall
	end


Psfleader3_Event_Script::
	switch VAR_GYM_3_STATE
	case 2, Psfleader3_Event_Script_2
	case 3, Psfleader3_Event_Script_3
	case 4, Psfleader3_Event_Script_4
	case 5, Psfleader3_Event_Script_5
	return

Psfleader3_Event_Script_2:
	goto MuseumArrangement_Dialogue
	return

Psfleader3_Event_Script_3:
	goto Psfleader3StartBattle_Script
	return

Psfleader3_Event_Script_4:
	goto Psfleader3PostBattle_Dialogue
	return

Psfleader3_Event_Script_5:
	goto Psfleader3PostBattle_Dialogue2
	return


MuseumArrangement_Dialogue::
	lockall
	setvar VAR_GYM_3_STATE, 3
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	faceplayer
	msgbox gText_MuseumArrangement_Text1
	callnative ClearMugshot
	applymovement 1, Psfleader3LookAround_Movement
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_MuseumArrangement_Text2
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_MuseumArrangement_Text3
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	msgbox gText_MuseumArrangement_Text4
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto Psfleader3StartBattle_Script
	return


Psfleader3StartBattle_Script::
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	trainerbattle_single TRAINER_WATTSON_1, gText_MuseumArrangement_Text5, gText_Psfleader3Alpha_HumanWin, Psfleader3Defeated_Script, NO_MUSIC
	return


Psfleader3Defeated_Script::
	lockall
	setflag FLAG_BADGE03_GET
	clearflag FLAG_HIDE_PSFCITY15_PSFBADBOSS
	setvar VAR_PSFCITY15_STATE, 1
	setvar VAR_GYM_3_STATE, 4
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	msgbox gText_Psfleader3PostBattle_Text1
	closemessage
	callnative ClearMugshot
	msgbox gText_Psfleader3BadgeGet_Text1
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM34
	addvar VAR_STORYLINE_STATE, 1
	call Act1_1_Check_Script
	releaseall
	end


Psfleader3PostBattle_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	msgbox gText_Psfleader3PostBattle_Text2, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	setvar VAR_GYM_3_STATE, 5
	end


Psfleader3PostBattle_Dialogue2::
	lockall
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	msgbox gText_Psfleader3PostBattle_Text3, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


Psfleader3WalkToBattlefield_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	face_left
	step_end

Psfleader3LookAround_Movement:
	face_up
	delay_16
	face_down
	delay_16
	face_right
	delay_16
	face_left
	step_end

AutomaticSolvePuzzle_Script_Text_0:
	.string "Puzzle is solved. Leave and come back.$"

gText_MuseumArrangement_Text1::
	.string "I was thinking about the arrangement\n"
	.string "of the museum. Museums tend to\l"
	.string "organize through etic categories, but\l"
	.string "I always wonder... how far off are we\l"
	.string "from their emic counterparts...? Sorry,\l"
	.string "I'm Psfleader3, Chief of the Psfcity15\l"
	.string "Gym!$"

gText_MuseumArrangement_Text2::
	.string "Has your visit been a positive time\n"
	.string "investment? There was a ton of\l"
	.string "qualitative research into curating the\l"
	.string "best possible experience for both\l"
	.string "patrons and challengers.$"

gText_MuseumArrangement_Text3::
	.string "Uh... yup. Yeah. It's cool.$"

gText_MuseumArrangement_Text4::
	.string "I can hear the Orre in you. Enchanting.$"

gText_MuseumArrangement_Text5::
	.string "Let's see how your socialization\n"
	.string "impacted your battling ability!$"

gText_Psfleader3Alpha_AIWin::
	.string "Time to pay your tribute.$"

gText_Psfleader3Alpha_HumanWin::
	.string "If this battle is any indication, your\n"
	.string "assimilation is going perfectly!$"

gText_Psfleader3BadgeGet_Text1::
	.string "You recieved the Psfbadge3 Badge!$"

gText_Psfleader3PostBattle_Text1::
	.string "Wow, I'll really need to re-think my\n"
	.string "tactical core values. Awesome battle,\l"
	.string "{PLAYER}!$"

gText_Psfleader3PostBattle_Text2::
	.string "That positive sanction means that\n"
	.string "traded Pokémon up to Level Psflevel3\l"
	.string "will obey you. Psfgymattacknum3 is like\l"
	.string "a shaman in your pocket and will teach\l"
	.string "Psfgymattacknum1, allowing your clan\l"
	.string "to Psfgymattackdesc3.$"

gText_Psfleader3PostBattle_Text3::
	.string "We'll need to battle again in the future.\n"
	.string "I want to increase our data set - a\l"
	.string "sample size of one isn't enough for any\l"
	.string "conclusions about our relative skill\l"
	.string "levels!$"
