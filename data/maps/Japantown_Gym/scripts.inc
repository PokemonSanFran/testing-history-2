Japantown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Japantown_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Japantown_Gym_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Japantown_Gym_LeaderVisibility_Script
	return


EnterBugsy_Event_Script::
	switch VAR_GYM_2_STATE
	case 3, EnterBugsy_Event_Script_2
	case 4, EnterBugsy_Event_Script_3
	case 5, EnterBugsy_Event_Script_4
	goto EnterBugsy_BugsyIntro_Dialogue
	return

EnterBugsy_Event_Script_2:
	goto EnterBugsy_StartGymBattle_Script
	return

EnterBugsy_Event_Script_3:
	goto EnterBugsy_PostDefeat1_Dialogue
	return

EnterBugsy_Event_Script_4:
	goto EnterBugsy_PostDefeat2_Dialogue
	return


Japantown_Gym_HideLeaderScript::
	setflag FLAG_TEMP_1
	return


Japantown_Gym_LeaderVisibility_Script::
	switch VAR_BUGSY_STATE
	case BATTLE_1_COMPLETE, Japantown_Gym_LeaderVisibility_Script_2
	case QUEST_1_COMPLETE, Japantown_Gym_LeaderVisibility_Script_3
	return

Japantown_Gym_LeaderVisibility_Script_2:
	call Japantown_Gym_HideLeaderScript
	return

Japantown_Gym_LeaderVisibility_Script_3:
	call Japantown_Gym_HideLeaderScript
	return


Japantown_Gym_Entrance_Guy_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_HYBRIDCULTURE, SUB_QUEST_3
	call Quest_HybridCulture_CheckSubquests_Script
	msgbox gText_Japantown_Gym_ThePayapaBerry, MSGBOX_NPC
	applymovement 2, Common_Movement_FaceLeft
	end


gText_Japantown_Gym_ThePayapaBerry::
	.string "A lot of staff that train here to try\n"
	.string "stock up on Payapa and Shuca Berries.\l"
	.string "At first they were super expensive,\l"
	.string "since they don't really grow in SanFran.\l"
	.string "But the trainers from SanFran all give\l"
	.string "berries when defeated, and the\l"
	.string "trainers from Sinnoh all give berries\l"
	.string "from their homeland - which include the\l"
	.string "Payapa and the Shuca Berries! Needless\l"
	.string "to say, Trainers from Sinnoh became\l"
	.string "super popular super fast.$"
