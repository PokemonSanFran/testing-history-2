Haightashbury_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Haightashbury_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Haightashbury_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Inversehallucinogenic_ControlTrainerVisibility_Script
	call Haightashbury_Gym_Leader_Visibility_Script
	call_if_quest_complete QUEST_RESTOREHAIGHTASHBURY, Quest_Restorehaightashbury_Leader_Visibility_Script
	goto Haightashbury_Gym_MapScripts_OnTransition
	return


Haightashbury_Gym_Leader_Visibility_Script::
	switch VAR_PRYCE_STATE
	case BATTLE_1_COMPLETE, Haightashbury_Gym_Leader_Visibility_Script_3
	return

Haightashbury_Gym_Leader_Visibility_Script_1:
	return

Haightashbury_Gym_Leader_Visibility_Script_3:
	call Quest_ShutDownMedicineMan_HideLeaderInGym_Script
	goto Haightashbury_Gym_Leader_Visibility_Script_1


Haightashbury_Gym_MapScripts_OnTransition::
	switch VAR_GYM_7_STATE
	case 3, Haightashbury_Gym_MapScripts_OnTransition_2
	return

Haightashbury_Gym_MapScripts_OnTransition_2:
	goto EnterPryce_StartBattle_ObjectSetup_Script
	return


Haightashbury_Gym_EventScript_Merril::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end


Haightashbury_Gym_EventScript_Kinsey::
	return


Haightashbury_Gym_EventScript_Kaley::
	return


Haightashbury_Gym_EventScript_Torey::
	return


Haightashbury_Gym_PryceRematch_Script::
	goto_if_quest_complete QUEST_RESTOREMARIN, Quest_Restorehaightashbury_Dialogue
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 0
	goto_if_ne Haightashbury_Gym_PryceRematch_Script_1
	goto Haightashbury_Gym_PostRematch_Dialogue
	return

Haightashbury_Gym_PryceRematch_Script_1:
	goto Haightashbury_Gym_PreRematch_Dialogue
	return


Haightashbury_Gym_PreRematch_Dialogue::
	msgbox gText_Haightashbury_Gym_PlayerAreYou, MSGBOX_NPC, SPEAKER_PRYCE
	trainerbattle_no_intro TRAINER_DRUG_PRYCE, gText_Haightashbury_Gym_IShouldTryBattlingSober
	goto Haightashbury_Gym_PostRematch_Dialogue
	return


Haightashbury_Gym_PostRematch_Dialogue::
	msgbox gText_Haightashbury_Gym_OohImBurned, MSGBOX_NPC, SPEAKER_PRYCE
	closemessage
	release
	end


gText_Haightashbury_Gym_PlayerAreYou::
	.string "{PLAYER}! So glad I don't have to hold\n"
	.string "back anymore... and I can break out the\l"
	.string "real good batches!$"

gText_Haightashbury_Gym_IShouldTryBattlingSober::
	.string "I should try battling sober some day...$"

gText_Haightashbury_Gym_OohImBurned::
	.string "Oof, I'm burned out! Let's battle again\n"
	.string "tomorrow, okay?$"
