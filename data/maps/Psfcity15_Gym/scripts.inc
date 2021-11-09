Psfcity15_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	switch VAR_GYM_3_STATE
	case 1, Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2
	return

Psfcity15_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION_2:
	goto ArrangementMuseum_ObjectSetUp
	return


ArrangementMuseum_ObjectSetUp::
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


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


MuseumArrangement_Dialogue::
	lockall
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
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
	closemessage
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	trainerbattle_single TRAINER_CALVIN_1, gText_MuseumArrangement_Text4, MuseumArrangement_Dialogue_Text_0, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	return


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

MuseumArrangement_Dialogue_Text_0:
	.string "yep$"

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
	.string "I can hear the Orre in you. Enchanting.\n"
	.string "Let's see how your socialization\l"
	.string "impacted your battling ability!$"

gText_Psfleader4_1_AIWin::
	.string "Time to pay your tribute.$"

gText_Psfleader4_1_HumanWin::
	.string "If this battle is any indication, your\n"
	.string "assimilation is going perfectly!$"

gText_Psfleader4_1_PostBattle::
	.string "Wow, I'll really need to re-think my\n"
	.string "tactical core values. Awesome battle,\l"
	.string "{PLAYER}!$"
