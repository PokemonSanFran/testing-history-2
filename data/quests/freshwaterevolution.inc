Quest_FreshwaterEvolution_HideObject_Script::
	setflag FLAG_TEMP_1
	return


Quest_FreshwaterEvolution_CheckPartyAndQuest_Script::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_FRESHWATEREVOLUTION
	compare VAR_RESULT, 0
	goto_if_ne Quest_FreshwaterEvolution_CheckPartyAndQuest_Script_2
Quest_FreshwaterEvolution_CheckPartyAndQuest_Script_1:
	release
	end

Quest_FreshwaterEvolution_CheckPartyAndQuest_Script_2:
	goto Quest_FreshwaterEvolution_StartCutscene_Dialogue
	goto Quest_FreshwaterEvolution_CheckPartyAndQuest_Script_1


Quest_FreshwaterEvolution_AlreadyShiny_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_FreshwaterEvolution_OhWaitYoure, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	call Quest_FreshwaterEvolution_Recall_Script
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end


Quest_FreshwaterEvolution_StartCutscene_Dialogue::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 30
	playse SE_BALL_OPEN
	waitse
	clearflag FLAG_TEMP_1
	addobject 2
	playmoncry SPECIES_OCTILLERY, CRY_MODE_ENCOUNTER
	waitmoncry
	compare VAR_0x8000, 999
	goto_if_eq Quest_FreshwaterEvolution_StartCutscene_Dialogue_2
Quest_FreshwaterEvolution_StartCutscene_Dialogue_1:
	bufferleadmonspeciesname STR_VAR_1
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_FreshwaterEvolution_OkayLetsSee, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	applymovement 2, Quest_FreshwaterEvolution_JumpIntoWater_Movement
	waitmovement 2
	hideobjectat 2, MAP_GLDNGTEWILDS_SPRING
	delay 120
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement OBJ_EVENT_ID_PLAYER
	waitse
	showobjectat 2, MAP_GLDNGTEWILDS_SPRING
	applymovement 2, Quest_FreshwaterEvolution_JumpOutWater_Movement
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	playmoncry SPECIES_OCTILLERY, CRY_MODE_HIGH_PITCH
	waitmoncry
	waitmovement 2
	msgbox gText_Quest_FreshwaterEvolution_LooksVery, MSGBOX_DEFAULT
	closemessage
	call Quest_FreshwaterEvolution_Recall_Script
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_FreshwaterEvolution_TheColorChangedBut, MSGBOX_DEFAULT
	callnative ClearMugshot
	goto Quest_FreshwaterEvolution_BystanderScene_Script
	return

Quest_FreshwaterEvolution_StartCutscene_Dialogue_2:
	goto Quest_FreshwaterEvolution_AlreadyShiny_Dialogue
	goto Quest_FreshwaterEvolution_StartCutscene_Dialogue_1


Quest_FreshwaterEvolution_BystanderScene_Script::
	applymovement 1, Quest_FreshwaterEvolution_WalkToPlayer_Movement
	waitmovement 1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	msgbox gText_Quest_FreshwaterEvolution_HahaAreYouTrying, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_FreshwaterEvolution_YeahYouKnow, MSGBOX_DEFAULT
	callnative ClearMugshot
	msgbox gText_Quest_FreshwaterEvolution_BeenSeeingIt, MSGBOX_DEFAULT
	msgbox gText_Quest_FreshwaterEvolution_ThereIsSomething, MSGBOX_DEFAULT
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_FreshwaterEvolution_GoodToKnow, MSGBOX_DEFAULT
	callnative ClearMugshot
	closemessage
	completequest QUEST_FRESHWATEREVOLUTION
	release
	end


Quest_FreshwaterEvolution_Recall_Script::
	playse SE_BALL_OPEN
	waitse
	removeobject 2
	return


Quest_FreshwaterEvolution_JumpIntoWater_Movement:
	face_down
	delay_16
	jump_2_down
	step_end

Quest_FreshwaterEvolution_JumpOutWater_Movement:
	jump_in_place_up
	jump_2_up
	face_right
	jump_in_place_right
	jump_in_place_right
	step_end

Quest_FreshwaterEvolution_WalkToPlayer_Movement:
	walk_right
	walk_right
	face_down
	step_end

gText_Quest_FreshwaterEvolution_OhWaitYoure::
	.string "Oh wait, you're already shiny...$"

gText_Quest_FreshwaterEvolution_OkayLetsSee::
	.string "Okay let's see... come on\n"
	.string "{STR_VAR_1}, hop in the water!$"

gText_Quest_FreshwaterEvolution_LooksVery::
	.string "{STR_VAR_1} looks very distressed!$"

gText_Quest_FreshwaterEvolution_TheColorChangedBut::
	.string "The color changed, but I don't think its\n"
	.string "a shiny now...$"

gText_Quest_FreshwaterEvolution_HahaAreYouTrying::
	.string "Hahaha are you trying that Shiny\n"
	.string "Octillery trick from Twitter?$"

gText_Quest_FreshwaterEvolution_YeahYouKnow::
	.string "Yeah, you know about that?$"

gText_Quest_FreshwaterEvolution_BeenSeeingIt::
	.string "Been seeing it a lot lately! Octopuses\n"
	.string "naturally change color when under\l"
	.string "stress, and they're seawater animals.\l"
	.string "Any ol' octopus would react that way.\l"
	.string "Poor thing, it'll probably be fine after\l"
	.string "chilling in your Pokeball for a bit.$"

gText_Quest_FreshwaterEvolution_GoodToKnow::
	.string "Good to know...$"

gText_Quest_FreshwaterEvolution_ThereIsSomething::
	.string "There is something weird about this\n"
	.string "spring though. I was training a\l"
	.string "Graveler here, and it suddenly evolved\l"
	.string "on its own! No Linking Cord or anything!$"

gText_Quest_FreshwaterEvolution_IWonderWhat::
	.string "I wonder what other Pokemon will evolve\n"
	.string "here?$"
