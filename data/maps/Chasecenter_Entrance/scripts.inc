Chasecenter_Entrance_MapScripts::
	.byte 0


Chasecenter_Entrance_KeepPlayerInside_Script::
	lock
	compare VAR_STORYLINE_STATE, 51
	goto_if_eq Chasecenter_Entrance_KeepPlayerInside_Script_2
Chasecenter_Entrance_KeepPlayerInside_Script_1:
	goto_if_set FLAG_CHASECENTER_TOURNAMENT_HAPPENING, Chasecenter_Entrance_KeepPlayerInside_Script_5
Chasecenter_Entrance_KeepPlayerInside_Script_4:
	release
	end

Chasecenter_Entrance_KeepPlayerInside_Script_2:
	goto ExhibitionBattle_FalseCredits_Script
	goto Chasecenter_Entrance_KeepPlayerInside_Script_1

Chasecenter_Entrance_KeepPlayerInside_Script_5:
	msgbox gText_GroupStages_OhRight, , SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_SWEAT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto Chasecenter_Entrance_KeepPlayerInside_Script_4

