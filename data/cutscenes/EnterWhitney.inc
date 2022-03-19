EnterPsfleader3_ObjectSetUp_Script::
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	end


EnterPsfleader3_StartBattle_ObjectSetup_Script::
	setobjectxy 1, 10, 6
	setobjectxyperm 1, 10, 6
	end


EnterPsfleader3_HidePuzzle_Script::
	compare VAR_GYM_3_STATE, 0
	goto_if_gt EnterPsfleader3_HidePuzzle_Script_1
	return

EnterPsfleader3_HidePuzzle_Script_1:
	setflag FLAG_TEMP_1
	return


AutomaticSolvePuzzle_Script::
	lockall
	msgbox AutomaticSolvePuzzle_Script_Text_0, MSGBOX_NPC
	closemessage
	release
	addvar VAR_GYM_3_STATE, 1
	end


EnterPsfleader3_WalkToBattlefield_Script::
	addvar VAR_GYM_3_STATE, 1
	lock
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, EnterPsfleader3_WalkToBattlefield_Movement
	waitmovement 0
	releaseall
	end


EnterPsfleader3_MuseumArrangement_Dialogue::
	addvar VAR_GYM_3_STATE, 1
	msgbox gText_EnterPsfleader3_IWasThinking, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	applymovement 1, Psfleader3LookAround_Movement
	waitmovement 0
	callnative DrawMugshot
	msgbox gText_EnterPsfleader3_HasYourVisit
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_EnterPsfleader3_UhYup
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	msgbox gText_EnterPsfleader3_ICanHearTheOrre
	callnative ClearMugshot
	call Common_EventScript_SaveGame
	closemessage
	goto EnterPsfleader3_StartBattle_Script
	return


EnterPsfleader3_StartBattle_Script::
	setvar VAR_0x8000, MUGSHOT_WHITNEY
	callnative DrawMugshot
	trainerbattle_single TRAINER_WATTSON_1, gText_EnterPsfleader3_LetsSeeHow, gText_EnterPsfleader3_IfThisBattle, EnterPsfleader3_Defeated_Script, NO_MUSIC
	return


EnterPsfleader3_Defeated_Script::
	setflag FLAG_BADGE03_GET
	addvar VAR_PSFCITY15_STATE, 1
	addvar VAR_GYM_3_STATE, 1
	addvar VAR_STORYLINE_STATE, 1
	msgbox gText_EnterPsfleader3_WowIllReallyNeed
	closemessage
	callnative ClearMugshot
	msgbox gText_EnterPsfleader3_YouRecieved
	call Common_EventScript_PlayGymBadgeFanfare
	giveitem ITEM_TM34
	call Act1_1_Check_Script
	releaseall
	end


EnterPsfleader3_PostBattle_Dialogue::
	addvar VAR_GYM_3_STATE, 1
	msgbox gText_EnterPsfleader3_ThatPositiveSanction, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader3_PostBattle_Dialogue2::
	callnative DrawMugshot
	msgbox gText_EnterPsfleader3_WellNeedToBattle, MSGBOX_NPC
	callnative ClearMugshot
	closemessage
	releaseall
	end


EnterPsfleader3_WalkToBattlefield_Movement:
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
	.string "Puzzle is solved.$"

gText_EnterPsfleader3_IWasThinking::
	.string "I was thinking about the arrangement\n"
	.string "of the museum. Museums tend to\l"
	.string "organize through etic categories, but\l"
	.string "I always wonder... how far off are we\l"
	.string "from their emic counterparts...? Sorry,\l"
	.string "I'm Psfleader3, Chief of the Psfcity15\l"
	.string "Gym!$"

gText_EnterPsfleader3_HasYourVisit::
	.string "Has your visit been a positive time\n"
	.string "investment? There was a ton of\l"
	.string "qualitative research into curating the\l"
	.string "best possible experience for both\l"
	.string "patrons and challengers.$"

gText_EnterPsfleader3_UhYup::
	.string "Uh... yup. Yeah. It's cool.$"

gText_EnterPsfleader3_ICanHearTheOrre::
	.string "I can hear the Orre in you. Enchanting.$"

gText_EnterPsfleader3_LetsSeeHow::
	.string "Let's see how your socialization\n"
	.string "impacted your battling ability!$"

gText_EnterPsfleader3_TimeToPay::
	.string "Time to pay your tribute.$"

gText_EnterPsfleader3_IfThisBattle::
	.string "If this battle is any indication, your\n"
	.string "assimilation is going perfectly!$"

gText_EnterPsfleader3_YouRecieved::
	.string "You recieved the Psfbadge3 Badge!$"

gText_EnterPsfleader3_WowIllReallyNeed::
	.string "Wow, I'll really need to re-think my\n"
	.string "tactical core values. Awesome battle,\l"
	.string "{PLAYER}!$"

gText_EnterPsfleader3_ThatPositiveSanction::
	.string "That positive sanction means that\n"
	.string "traded Pokémon up to Level Psflevel3\l"
	.string "will obey you. Psfgymattacknum3 is like\l"
	.string "a shaman in your pocket and will teach\l"
	.string "Psfgymattacknum1, allowing your clan\l"
	.string "to Psfgymattackdesc3.$"

gText_EnterPsfleader3_WellNeedToBattle::
	.string "We'll need to battle again in the future.\n"
	.string "I want to increase our data set - a\l"
	.string "sample size of one isn't enough for any\l"
	.string "conclusions about our relative skill\l"
	.string "levels!$"
