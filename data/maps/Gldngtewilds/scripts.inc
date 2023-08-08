Gldngtewilds_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Gldngtewilds_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Gldngtewilds_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_GLDNGTEWILDS_NORTH
	setflag FLAG_VISITED_GLDNGTEWILDS_WEST
	setflag FLAG_VISITED_GLDNGTEWILDS_EAST
	setflag FLAG_VISITED_GLDNGTEWILDS_SOUTH
	call Quest_Restorechinatown_HideBlackbelt_Gldngtewilds_Script
	call Quest_Employedeverafter_Gldngtewilds_HideBrideA_Script
	call_if_quest_complete QUEST_EMPLOYEDEVERAFTER, Quest_Employedeverafter_Gldngtewilds_HideBrideMissing_Script
	call Quest_Employedeverafter_MoveBrideA_Gldngtewilds_Script
	call_if_quest_complete QUEST_EMPLOYEDEVERAFTER, Quest_Employedeverafter_CleanUpWeddingParty_Script
	return


Gldngtewilds_EventScript_BlackbeltF::
	trainerbattle_single TRAINER_BLACKBELT_F, gText_ExpandedPlaceholder_Empty, gText_ExpandedPlaceholder_Empty
	compare VAR_QUEST_RESTORECHINATOWN, FIND_BLACKBELTS
	goto_if_eq Gldngtewilds_EventScript_BlackbeltF_2
Gldngtewilds_EventScript_BlackbeltF_1:
	msgbox gText_ExpandedPlaceholder_Empty, MSGBOX_AUTOCLOSE
	end

Gldngtewilds_EventScript_BlackbeltF_2:
	goto Quest_Restorechinatown_Recruit_Blackbelt_F_Dialogue
	goto Gldngtewilds_EventScript_BlackbeltF_1


Gldngtewilds_EventScript_Helen::
	trainerbattle_single TRAINER_HELEN, gText_Gldngtewilds_HaveYouEver, gText_Gldngtewilds_NotReadyForBattle
	goto_if_quest_not_inactive QUEST_EMPLOYEDEVERAFTER, Quest_Employedeverafter_BrideMissing_Interact_Script
	msgbox gText_Gldngtewilds_ImSupposedToBeGetting, MSGBOX_NPC, SPEAKER_HELEN
	end


gText_Gldngtewilds_HaveYouEver::
	.string "Have you ever gotten cold feet?$"

gText_Gldngtewilds_NotReadyForBattle::
	.string "I'm not ready for battle or marriage...$"

gText_Gldngtewilds_ImSupposedToBeGetting::
	.string "I'm supposed to be getting married\n"
	.string "today. But I don't think I can do it...$"
