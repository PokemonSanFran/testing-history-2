EnterWhitney_LeaderPosition_Script::
	switch VAR_GYM_3_STATE
	case 0, EnterWhitney_LeaderPosition_Script_2
	case 1, EnterWhitney_LeaderPosition_Script_3
	goto EnterWhitney_StartBattle_ObjectSetup_Script
	return

EnterWhitney_LeaderPosition_Script_2:
	return

EnterWhitney_LeaderPosition_Script_3:
	setflag FLAG_TEMP_1
	return


EnterWhitney_ObjectSetUp_Script::
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	return


EnterWhitney_StartBattle_ObjectSetup_Script::
	setflag FLAG_TEMP_1
	setobjectxy 1, 10, 6
	setobjectxyperm 1, 10, 6
	setobjectmovementtype 1, MOVEMENT_TYPE_LOOK_AROUND
	return


AutomaticSolvePuzzle_Script::
	lock
	setvar VAR_GYM_3_STATE, GYM_PUZZLE_COMPLETE
	msgbox AutomaticSolvePuzzle_Script_Text_0, MSGBOX_NPC
	closemessage
	release
	end


EnterWhitney_WalkToBattlefield_Script::
	setvar VAR_GYM_3_STATE, GYM_LEADER_ON_BATTLEFIELD
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, EnterWhitney_WalkToBattlefield_Movement
	waitmovement 0
	releaseall
	end


Whitney_Event_Script::
	lockall
	switch VAR_GYM_3_STATE
	case 2, Whitney_Event_Script_2
	case 3, Whitney_Event_Script_3
	case 4, Whitney_Event_Script_4
	case 5, Whitney_Event_Script_5
	return

Whitney_Event_Script_2:
	goto EnterWhitney_MuseumArrangement_Dialogue
	return

Whitney_Event_Script_3:
	goto EnterWhitney_StartBattle_Script
	return

Whitney_Event_Script_4:
	goto EnterWhitney_PostBattle_Dialogue
	return

Whitney_Event_Script_5:
	goto EnterWhitney_PostBattle_Dialogue2
	return


EnterWhitney_MuseumArrangement_Dialogue::
	setvar VAR_GYM_3_STATE, GYM_LEADER_ON_BATTLEFIELD
	msgbox gText_EnterWhitney_IWasThinking, MSGBOX_NPC, SPEAKER_WHITNEY
	closemessage
	applymovement 1, WhitneyLookAround_Movement
	waitmovement 0
	msgbox gText_EnterWhitney_HasYourVisit, , SPEAKER_WHITNEY
	msgbox gText_EnterWhitney_UhYup, MSGBOX_DEFAULT, SPEAKER_ZOEY
	msgbox gText_EnterWhitney_ICanHearTheOrre, , SPEAKER_WHITNEY
	call Common_EventScript_SaveGame
	closemessage
	goto EnterWhitney_StartBattle_Script
	return


EnterWhitney_StartBattle_Script::
	trainerbattle_single TRAINER_WATTSON_1, gText_EnterWhitney_LetsSeeHow, gText_EnterWhitney_IfThisBattle, EnterWhitney_Defeated_Script, NO_MUSIC
	return


EnterWhitney_Defeated_Script::
	setflag FLAG_BADGE03_GET
	setvar VAR_SALESFORCETOWER_CONFERENCE_STATE, DEFEATED_WHITNEY
	setvar VAR_GYM_3_STATE, GYM_DEFEATED_LEADER
	addvar VAR_STORYLINE_STATE, 1
	setvar VAR_WHITNEY_STATE, BATTLE_1_COMPLETE
	msgbox gText_EnterWhitney_WowIllReallyNeed, , SPEAKER_WHITNEY
	closemessage
	msgbox gText_EnterWhitney_YouRecieved
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM34
	call Act1_1_Check_Script
	releaseall
	end


EnterWhitney_PostBattle_Dialogue::
	setvar VAR_GYM_3_STATE, GYM_EXPLAINED_BADGE_AND_TM
	msgbox gText_EnterWhitney_ThatPositiveSanction, MSGBOX_NPC, SPEAKER_WHITNEY
	closemessage
	releaseall
	end


EnterWhitney_PostBattle_Dialogue2::
	msgbox gText_EnterWhitney_WellNeedToBattle, MSGBOX_NPC, SPEAKER_WHITNEY
	closemessage
	releaseall
	end


EnterWhitney_WalkToBattlefield_Movement:
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

WhitneyLookAround_Movement:
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

gText_EnterWhitney_IWasThinking::
	.string "I was thinking about the arrangement\n"
	.string "of the museum. Museums tend to\l"
	.string "organize through etic categories, but\l"
	.string "I always wonder... how far off are we\l"
	.string "from their emic counterparts...? Sorry,\l"
	.string "I'm Whitney, Chief of the SOMA Gym!$"

gText_EnterWhitney_HasYourVisit::
	.string "Has your visit been a positive time\n"
	.string "investment? There was a ton of\l"
	.string "qualitative research into curating the\l"
	.string "best possible experience for both\l"
	.string "patrons and challengers.$"

gText_EnterWhitney_UhYup::
	.string "Uh... yup. Yeah. It's cool.$"

gText_EnterWhitney_ICanHearTheOrre::
	.string "I can hear the Orre in you. Enchanting.$"

gText_EnterWhitney_LetsSeeHow::
	.string "Let's see how your socialization\n"
	.string "impacted your battling ability!$"

gText_EnterWhitney_TimeToPay::
	.string "Time to pay your tribute.$"

gText_EnterWhitney_IfThisBattle::
	.string "If this battle is any indication, your\n"
	.string "assimilation is going perfectly!$"

gText_EnterWhitney_YouRecieved::
	.string "You recieved the WhitneyBadge Badge!$"

gText_EnterWhitney_WowIllReallyNeed::
	.string "Wow, I'll really need to re-think my\n"
	.string "tactical core values. Awesome battle,\l"
	.string "{PLAYER}!$"

gText_EnterWhitney_ThatPositiveSanction::
	.string "That positive sanction means that\n"
	.string "traded Pokémon up to Level Psflevel3\l"
	.string "will obey you. Psfgymattacknum3 is like\l"
	.string "a shaman in your pocket and will teach\l"
	.string "Psfgymattacknum1, allowing your clan\l"
	.string "to Psfgymattackdesc3.$"

gText_EnterWhitney_WellNeedToBattle::
	.string "We'll need to battle again in the future.\n"
	.string "I want to increase our data set - a\l"
	.string "sample size of one isn't enough for any\l"
	.string "conclusions about our relative skill\l"
	.string "levels!$"
