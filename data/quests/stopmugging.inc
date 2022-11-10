Quest_StopMugging_HideObject_Script::
	setflag FLAG_TEMP_2
	removeobject 2
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_eq Quest_StopMugging_HideObject_Script_2
Quest_StopMugging_HideObject_Script_1:
	return

Quest_StopMugging_HideObject_Script_2:
	setflag FLAG_TEMP_3
	goto Quest_StopMugging_HideObject_Script_1


Quest_StopMugging_Trigger_Script::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_StopMugging_Trigger_Script_2
	goto Quest_StopMugging_RunIntoPlayer_Dialogue
	return

Quest_StopMugging_Trigger_Script_2:
	release
	end


Quest_StopMugging_RevealObject_Script::
	clearflag FLAG_TEMP_3
	clearflag FLAG_TEMP_2
	addobject 3
	addobject 4
	addobject 2
	return


Quest_StopMugging_RunIntoPlayer_Dialogue::
	lock
	call Quest_StopMugging_RevealObject_Script
	startquest QUEST_STOPMUGGING
	msgbox gText_StopMugging_StopThem
	closemessage
	applymovement 3, Quest_StopMugging_SlamIntoPlayerA_Movement
	applymovement 4, Quest_StopMugging_SlamIntoPlayerB_Movement
	waitmovement 4
	applymovement OBJ_EVENT_ID_PLAYER, Quest_StopMugging_FlyBackwards_Movement
	waitmovement OBJ_EVENT_ID_PLAYER
	delay 30
	applymovement 2, Quest_StopMugging_CatchUp_Movement
	waitmovement 2
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_STOPMUGGING
	compare VAR_RESULT, 0
	goto_if_ne Quest_StopMugging_RunIntoPlayer_Dialogue_2
Quest_StopMugging_RunIntoPlayer_Dialogue_1:
	msgbox gText_StopMugging_TheyTook
	closemessage
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_WhatTheHell
	callnative ClearMugshot
	msgbox gText_StopMugging_WeNeedThat
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_YouNeedSomebodyElse
	callnative ClearMugshot
	msgbox gText_StopMugging_YouDontUnderstand
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_YouTriedToMug
	callnative ClearMugshot
	goto Quest_StopMugging_StartBattle_Script
	return

Quest_StopMugging_RunIntoPlayer_Dialogue_2:
	goto Quest_StopMugging_StartBattle_Script
	goto Quest_StopMugging_RunIntoPlayer_Dialogue_1


Quest_StopMugging_StartBattle_Script::
	msgbox gText_StopMugging_WeDontHaveTimeFor
	closemessage
	applymovement 3, Common_Movement_WalkDown
	waitmovement 3
	trainerbattle_continue_after_lose TRAINER_MUGGERA_MUGGERB, gText_StopMugging_Shit
	goto Quest_StopMugging_PostBattle_Script
	return


Quest_StopMugging_PostBattle_Script::
	lock
	checktrainerflag TRAINER_MUGGERA_MUGGERB
	goto_if 1, Quest_StopMugging_PostBattle_Script_2
	msgbox gText_StopMugging_NowStayOut
	call Quest_StopMugging_Complete_Dialogue
	call Quest_StopMugging_Heal_Dialogue
Quest_StopMugging_PostBattle_Script_1:
	release
	end

Quest_StopMugging_PostBattle_Script_2:
	msgbox gText_StopMugging_DamnThisGuy
	call Quest_StopMugging_Complete_Dialogue
	goto Quest_StopMugging_PostBattle_Script_1


Quest_StopMugging_Complete_Dialogue::
	closemessage
	applymovement 3, Quest_StopMugging_LookAround_Movement
	waitmovement 3
	msgbox gText_StopMugging_ShitIDroppedThePhone
	closemessage
	applymovement 4, Quest_StopMugging_LookAround_Movement
	waitmovement 4
	msgbox gText_StopMugging_TheAssholeMust
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_IThinkYoure
	callnative ClearMugshot
	msgbox gText_StopMugging_WellTry
	closemessage
	applymovement 4, Quest_StopMugging_WalkAwayB_Movement
	applymovement 3, Quest_StopMugging_WalkAwayA_Movement
	completequest QUEST_STOPMUGGING
	waitmovement 3
	removeobject 3
	removeobject 4
	return


Quest_StopMugging_Heal_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_StopMugging_ImGladIWas
	callnative ClearMugshot
	special HealPlayerParty
	special ResetHealLocationToSOMA
	warpsilent MAP_SOMA, 25, 31
	release
	end


Quest_StopMugging_SlamIntoPlayerA_Movement:
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	lock_facing_direction
	jump_2_up
	delay_16
	delay_16
	walk_down
	unlock_facing_direction
	step_end

Quest_StopMugging_SlamIntoPlayerB_Movement:
	walk_faster_left
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	face_right
	step_end

Quest_StopMugging_FlyBackwards_Movement:
	face_up
	lock_facing_direction
	jump_2_down
	walk_up
	unlock_facing_direction
	step_end

Quest_StopMugging_CatchUp_Movement:
	walk_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Quest_StopMugging_LookAround_Movement:
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_down
	step_end

Quest_StopMugging_WalkAwayB_Movement:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Quest_StopMugging_WalkAwayA_Movement:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

gText_StopMugging_StopThem::
	.string "Help! Stop them!$"

gText_StopMugging_TheyTook::
	.string "They took my phone! Please help!$"

gText_StopMugging_WhatTheHell::
	.string "What the hell are you doing?$"

gText_StopMugging_WeNeedThat::
	.string "We need that phone!$"

gText_StopMugging_YouNeedSomebodyElse::
	.string "You NEED somebody else's phone?$"

gText_StopMugging_YouDontUnderstand::
	.string "You don't understand! Gimme that phone,\n"
	.string "quick!$"

gText_StopMugging_YouTriedToMug::
	.string "You tried to mug somebody and ran into\n"
	.string "me. What's to understand?$"

gText_StopMugging_WeDontHaveTimeFor::
	.string "We don't have time for this!$"

gText_StopMugging_Shit::
	.string "Shit!$"

gText_StopMugging_DamnThisGuy::
	.string "Damn, you're not messing around...$"

gText_StopMugging_NowStayOut::
	.string "Now stay out of our way!$"

gText_StopMugging_ShitIDroppedThePhone::
	.string "Shit, I dropped the phone when I ran\n"
	.string "into them... and I can't find it now!$"

gText_StopMugging_TheAssholeMust::
	.string "The asshole must have grabbed it and\n"
	.string "ran away!$"

gText_StopMugging_IThinkYoure::
	.string "I think you're the assholes here.$"

gText_StopMugging_WellTry::
	.string "We'll try something else man. Let's get\n"
	.string "out of here.$"

gText_StopMugging_ImGladIWas::
	.string "I'm glad I was able to slow them down...\n"
	.string "but I need to heal now.$"
