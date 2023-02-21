WeCanStopYouActually_FixPlayerPosition_Script::
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_ne WeCanStopYouActually_FixPlayerPosition_Script_1
	compare VAR_TEMP_1, 6
	goto_if_ne WeCanStopYouActually_FixPlayerPosition_Script_1
	return

WeCanStopYouActually_FixPlayerPosition_Script_1:
	fadescreen FADE_TO_BLACK
	applymovement 4, Common_Movement_FaceDown
	waitmovement 4
	setobjectxy 4, 15, 5
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setobjectxy OBJ_EVENT_ID_PLAYER, 15, 6
	TeleportCamera 15, 6
	fadescreen FADE_FROM_BLACK
	return


WeCanStopYouActually_PostBattle_Dialogue::
	lock
	call WeCanStopYouActually_FixPlayerPosition_Script
	msgbox gText_WeCanStopYouActually_SoWhatsYourPlan, , SPEAKER_ROSE
	msgbox gText_WeCanStopYouActually_BeepBeep
	msgbox gText_WeCanStopYouActually_ThatsTheAuthorities, , SPEAKER_ROSE
	msgbox gText_WeCanStopYouActually_OhNo, , SPEAKER_ROSE
	closemessage
	applymovement 4, WeCanStopYouActually_RunToDesk
	waitmovement 4
	playse SE_PC_LOGIN
	special TurnOnTVScreen
	delay 30
	fadescreen FADE_TO_BLACK
	msgbox gText_WeCanStopYouActually_IAmChiefOperatingOfficer, , SPEAKER_KOGA
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox gText_WeCanStopYouActually_WaitTheHell, , SPEAKER_ROSE
	playse SE_POKENAV_CALL
	waitse
	msgbox gText_WeCanStopYouActually_Ring
	msgbox gText_WeCanStopYouActually_FindThem, , SPEAKER_ROSE
	msgbox gText_WeCanStopYouActually_IDontCare, , SPEAKER_ROSE
	closemessage
	applymovement 4, WeCanStopYouActually_RageRun
	waitmovement 4
	msgbox gText_WeCanStopYouActually_TheyToldYou, , SPEAKER_ROSE
	msgbox gText_WeCanStopYouActually_I, , SPEAKER_ZOEY
	closemessage
	applymovement 4, Common_Movement_FaceLeft
	msgbox gText_WeCanStopYouActually_Security, , SPEAKER_ROSE
	msgbox gText_WeCanStopYouActually_WeAlreadyBeatThem, , SPEAKER_ZOEY
	closemessage
	applymovement 4, Common_Movement_FaceDown
	waitmovement 4
	msgbox gText_WeCanStopYouActually_ImNotGoingToPrison, , SPEAKER_ROSE
	closemessage
	applymovement 4, Common_Movement_WalkDown
	waitmovement 4
	goto WeCanStopYouActually_StartBossBattle_Script
	return


WeCanStopYouActually_StartBossBattle_Script::
	msgbox gText_WeCanStopYouActually_AndIllFrigginKill, , SPEAKER_ROSE
	closemessage
	trainerbattle_no_intro TRAINER_STEVEN, gText_WeCanStopYouActually_Nonono
	goto WeCanStopYouActually_Arrest_Dialogue
	return


WeCanStopYouActually_Arrest_Dialogue::
	lock
	setvar VAR_TOWER_RAID_STATE, DEFEATED_ROSE_SALESFORCETOWER
	setvar VAR_STORYLINE_STATE, STORY_CLEAR
	clearflag FLAG_TEMP_2
	addobject 2
	addobject 3
	msgbox gText_WeCanStopYouActually_YoureUnderArrest
	closemessage
	applymovement 2, WeCanStopYouActually_ArrestWalkInA
	applymovement 3, WeCanStopYouActually_ArrestWalkInB
	applymovement OBJ_EVENT_ID_PLAYER, WeCanStopYouActually_ArrestWalkInC
	waitmovement 3
	msgbox gText_WeCanStopYouActually_ForWhat, , SPEAKER_ROSE
	closemessage
	warpsilent MAP_WE_CAN_STOP_YOU_ACTUALLY_CUTSCENE, 0
	end


WeCanStopYouActaully_ArrestCutscene::
	lockall
	applymovement 1, WeCanStopYouActually_MarchRight
	applymovement 2, WeCanStopYouActually_MarchLeft
	applymovement 3, WeCanStopYouActually_MarchRight
	applymovement 14, WeCanStopYouActually_MarchLeft
	waitmovement 14
	applymovement OBJ_EVENT_ID_PLAYER, WeCanStopYouActually_StepAside
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 8
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
	waitmovement 9
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	removeobject 8
	removeobject 9
	addobject 10
	random 4
	compare VAR_RESULT, 1
	goto_if_eq WeCanStopYouActaully_ArrestCutscene_2
	applymovement 10, WeCanStopYouActually_SalutePlayer
WeCanStopYouActaully_ArrestCutscene_1:
	delay 32
	waitmovement 10
	addobject 11
	random 4
	compare VAR_RESULT, 1
	goto_if_eq WeCanStopYouActaully_ArrestCutscene_6
	applymovement 11, WeCanStopYouActually_SalutePlayer
WeCanStopYouActaully_ArrestCutscene_5:
	delay 32
	waitmovement 11
	addobject 12
	random 4
	compare VAR_RESULT, 1
	goto_if_eq WeCanStopYouActaully_ArrestCutscene_10
	applymovement 12, WeCanStopYouActually_SalutePlayer
WeCanStopYouActaully_ArrestCutscene_9:
	delay 32
	waitmovement 12
	addobject 13
	random 4
	compare VAR_RESULT, 1
	goto_if_eq WeCanStopYouActaully_ArrestCutscene_14
	applymovement 13, WeCanStopYouActually_SalutePlayer
WeCanStopYouActaully_ArrestCutscene_13:
	delay 32
	waitmovement 13
	removeobject 11
	removeobject 12
	removeobject 13
	removeobject 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	fadescreenspeed FADE_TO_BLACK, 24
	special HealPlayerParty
	msgbox gText_WeCanStopYouActually_TheNextDay, MSGBOX_AUTOCLOSE
	msgbox gText_WeCanStopYouActually_AndTomorrowStarts
	closemessage
	special GameClear
	waitstate
	releaseall
	end

WeCanStopYouActaully_ArrestCutscene_2:
	applymovement 10, WeCanStopYouActually_SalutePlayerHeart
	goto WeCanStopYouActaully_ArrestCutscene_1

WeCanStopYouActaully_ArrestCutscene_6:
	applymovement 11, WeCanStopYouActually_SalutePlayerHeart
	goto WeCanStopYouActaully_ArrestCutscene_5

WeCanStopYouActaully_ArrestCutscene_10:
	applymovement 12, WeCanStopYouActually_SalutePlayerHeart
	goto WeCanStopYouActaully_ArrestCutscene_9

WeCanStopYouActaully_ArrestCutscene_14:
	applymovement 13, WeCanStopYouActually_SalutePlayerHeart
	goto WeCanStopYouActaully_ArrestCutscene_13


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
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WeCanStopYouActually_StepAside:
	walk_right
	face_left
	step_end

WeCanStopYouActually_SalutePlayerHeart:
	walk_down
	face_right
	emote_heart
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

WeCanStopYouActually_SalutePlayer:
	walk_down
	face_right
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
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
	.string "I am Koga, the Ycombinator Chief\n"
	.string "Operating Officer. This is my\l"
	.string "confession. Two days ago, Ycombinator\l"
	.string "triggered a machine that is\l"
	.string "responsible for the devastating\l"
	.string "earthquake on Alameda. We did it to\l"
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
	.string "BIANCA! SABRINA! SECURITY!$"

gText_WeCanStopYouActually_WeAlreadyBeatThem::
	.string "We already beat them. You’re alone.$"

gText_WeCanStopYouActually_ImNotGoingToPrison::
	.string "…I’m not going to prison. I’m NOT GOING TO\n"
	.string "JAIL…$"

gText_WeCanStopYouActually_AndIllFrigginKill::
	.string "And I’ll FRIGGIN’ KILL YOU!$"

gText_WeCanStopYouActually_Nonono::
	.string "Nonononononono…$"

gText_WeCanStopYouActually_YoureUnderArrest::
	.string "Rose, you’re under arrest!$"

gText_WeCanStopYouActually_ForWhat::
	.string "For what? Using the tools YOUR BOSSES\n"
	.string "gave me? We’re all going down together!\l"
	.string "You’re all toast!$"

gText_WeCanStopYouActually_TheNextDay::
	.string "A few months later...$"

gText_WeCanStopYouActually_AndTomorrowStarts::
	.string "And tomorrow starts the beginning of\n"
	.string "the second season of Ycombinator’s\l"
	.string "Championship League! Trainers from all\l"
	.string "over SanFran will be battling all over\l"
	.string "to find out who will be this season’s\l"
	.string "Champ. Rose2, the new Ycombinator CEO\l"
	.string "released a statement yesterday,\l"
	.string "showing their excitement for this new\l"
	.string "chapter in Ycombinator history.\l"
	.string "Ycombinator’s entire executive team\l"
	.string "were all charged with conspiracy and\l"
	.string "murder, and are currently waiting trial.\l"
	.string "The previous Champion, {PLAYER}, was\l"
	.string "unavailable for comment.$"
