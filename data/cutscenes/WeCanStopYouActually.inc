WeCanStopYouActually_FixPlayerPosition_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_ne WeCanStopYouActually_FixPlayerPosition_Script_1
	compare VAR_TEMP_1, 6
	goto_if_ne WeCanStopYouActually_FixPlayerPosition_Script_1
	return

WeCanStopYouActually_FixPlayerPosition_Script_1:
	fadescreen FADE_TO_BLACK
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	setobjectxy 2, 15, 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setobjectxy OBJ_EVENT_ID_PLAYER, 15, 6
	TeleportCamera 15, 6
	fadescreen FADE_FROM_BLACK
	return


WeCanStopYouActually_PostBattle_Dialogue::
	lock
	call WeCanStopYouActually_FixPlayerPosition_Script
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_SoWhatsYourPlan
	msgbox gText_WeCanStopYouActually_BeepBeep
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_ThatsTheAuthorities
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_OhNo
	callnative ClearMugshot
	closemessage
	applymovement 2, WeCanStopYouActually_RunToDesk
	waitmovement 2
	special TurnOnTVScreen
	delay 16
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8000, MUGSHOT_N
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_IAmChiefOperatingOfficer
	callnative ClearMugshot
	closemessage
	fadescreen FADE_FROM_BLACK
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_WaitTheHell
	msgbox gText_WeCanStopYouActually_Ring
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_FindThem
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_IDontCare
	callnative ClearMugshot
	closemessage
	applymovement 2, WeCanStopYouActually_RageRun
	waitmovement 2
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_TheyToldYou
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_I
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceLeft
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_Security
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_WeAlreadyBeatThem
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_ImNotGoingToPrison
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_WalkDown
	waitmovement 2
	goto WeCanStopYouActually_StartBossBattle_Script
	return


WeCanStopYouActually_StartBossBattle_Script::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_AndIllFrigginKill
	callnative ClearMugshot
	closemessage
	trainerbattle_no_intro TRAINER_STEVEN, gText_WeCanStopYouActually_Nonono
	goto WeCanStopYouActually_Arrest_Dialogue
	return


WeCanStopYouActually_Arrest_Dialogue::
	lock
	addvar VAR_MAUVILLE_CITY_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	clearflag FLAG_TEMP_2
	addobject 3
	addobject 4
	msgbox gText_WeCanStopYouActually_YoureUnderArrest
	closemessage
	applymovement 3, WeCanStopYouActually_ArrestWalkInA
	applymovement 4, WeCanStopYouActually_ArrestWalkInB
	applymovement OBJ_EVENT_ID_PLAYER, WeCanStopYouActually_ArrestWalkInC
	waitmovement 4
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WeCanStopYouActually_ForWhat
	callnative ClearMugshot
	closemessage
	warpsilent MAP_WE_CAN_STOP_YOU_ACTUALLY_CUTSCENE, 255, 4, 4
	end


WeCanStopYouActaully_ArrestCutscene::
	addvar VAR_STORYLINE_STATE, 1
	lockall
	applymovement 1, WeCanStopYouActually_MarchLeft
	applymovement 2, WeCanStopYouActually_MarchRight
	applymovement 3, WeCanStopYouActually_MarchLeft
	applymovement 14, WeCanStopYouActually_MarchRight
	waitmovement 14
	applymovement OBJ_EVENT_ID_PLAYER, WeCanStopYouActually_StepAside
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 16
	addobject 4
	applymovement 4, WeCanStopYouActually_WalkOutOfBuilding
	delay 16
	addobject 5
	applymovement 5, WeCanStopYouActually_WalkOutOfBuilding
	delay 16
	addobject 6
	applymovement 6, WeCanStopYouActually_WalkOutOfBuilding
	delay 16
	addobject 7
	applymovement 7, WeCanStopYouActually_WalkOutOfBuilding
	delay 16
	addobject 8
	applymovement 8, WeCanStopYouActually_WalkOutOfBuilding
	delay 16
	addobject 9
	applymovement 9, WeCanStopYouActually_WalkOutOfBuilding
	delay 16
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	return


WeCanStopYouActually_RunToDesk:
	walk_up
	step_end

WeCanStopYouActually_RageRun:
	walk_faster_left
	walk_faster_right
	walk_faster_right
	walk_faster_left
	walk_faster_left
	walk_faster_right
	walk_faster_right
	walk_faster_left
	walk_faster_left
	walk_faster_right
	face_down
	step_end

WeCanStopYouActually_ArrestWalkInA:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	face_right
	step_end

WeCanStopYouActually_ArrestWalkInB:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	face_left
	step_end

WeCanStopYouActually_ArrestWalkInC:
	walk_right
	walk_right
	face_left
	step_end

WeCanStopYouActually_MarchLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	delay_8
	face_up
	step_end

WeCanStopYouActually_MarchRight:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	face_up
	step_end

WeCanStopYouActually_WalkOutOfBuilding:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

WeCanStopYouActually_StepAside:
	walk_right
	face_left
	step_end

gText_WeCanStopYouActually_SoWhatsYourPlan::
	.string "So, what’s your plan, beat me up and try\n"
	.string "to expose me? Nobody is going to\l"
	.string "believe the terrorists that stormed\l"
	.string "our office building. You’re all going to\l"
	.string "get arrested, the money will keep\l"
	.string "flowing in, and life is going to keep\l"
	.string "moving on.$"

gText_WeCanStopYouActually_BeepBeep::
	.string "*beep* *beep*$"

gText_WeCanStopYouActually_ThatsTheAuthorities::
	.string "That’s the authorities, probably here to\n"
	.string "pick you up.$"

gText_WeCanStopYouActually_OhNo::
	.string "…oh no.$"

gText_WeCanStopYouActually_IAmChiefOperatingOfficer::
	.string "I am Psfbadadmin2, the Psfbadguy Chief\n"
	.string "Operating Officer. This is my\l"
	.string "confession. Two days ago, Psfbadguy\l"
	.string "triggered a machine that is\l"
	.string "responsible for the devastating\l"
	.string "earthquake on Psfcity17. We did it to\l"
	.string "flush out and destroy …$"

gText_WeCanStopYouActually_WaitTheHell::
	.string "WHAT THE HELL ARE THEY DOING?$"

gText_WeCanStopYouActually_Ring::
	.string "*ring*$"

gText_WeCanStopYouActually_FindThem::
	.string "FIND THEM! SHUT THAT DOWN!$"

gText_WeCanStopYouActually_IDontCare::
	.string "I don’t care WHERE THEY ARE JUST END\n"
	.string "THIS SHIT! I thought they were\l"
	.string "MISSING! HOW DID THIS HAPPEN?$"

gText_WeCanStopYouActually_TheyToldYou::
	.string "YOU! They told you! That’s how you found\n"
	.string "out! And now if they confess… they\l"
	.string "don’t have to take it from you.$"

gText_WeCanStopYouActually_I::
	.string "I -$"

gText_WeCanStopYouActually_Security::
	.string "PSFTRANSRIVAL! PSFBADADMIN3!\n"
	.string "SECURITY!$"

gText_WeCanStopYouActually_WeAlreadyBeatThem::
	.string "We already beat them. You’re alone.$"

gText_WeCanStopYouActually_ImNotGoingToPrison::
	.string "…I’m not going to prison. I’m NOT GOING TO\n"
	.string "JAIL…$"

gText_WeCanStopYouActually_AndIllFrigginKill::
	.string "And I’ll FRIGGIN’ KILL YOU!$"

gText_WeCanStopYouActually_Nonono::
	.string "Nonononononono….$"

gText_WeCanStopYouActually_YoureUnderArrest::
	.string "Psfbadboss, you’re under arrest!$"

gText_WeCanStopYouActually_ForWhat::
	.string "For what? Using the tools YOUR BOSSES\n"
	.string "gave me? We’re all going down together!\l"
	.string "You’re all toast!$"

gText_WeCanStopYouActually_AndTomorrowStarts::
	.string "And tomorrow starts the beginning of\n"
	.string "the second season of Psfbadguy’s\l"
	.string "Championship League! Trainers from all\l"
	.string "over Psfregion1 will be battling all\l"
	.string "over to find out who will be this\l"
	.string "season’s Champ. Psfbadboss2, the new\l"
	.string "Psfbadguy CEO released a statement\l"
	.string "yesterday, showing their excitement\l"
	.string "for this new chapter in Psfbadguy\l"
	.string "history. Psfbadguy’s entire executive\l"
	.string "team were all charged with conspiracy\l"
	.string "and murder, and are currently waiting\l"
	.string "trial. The previous Champion,\l"
	.string "{PLAYER}, was unavailable for\l"
	.string "comment.$"
