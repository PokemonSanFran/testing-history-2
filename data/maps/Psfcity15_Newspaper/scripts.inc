Psfcity15_Newspaper_MapScripts::
	.byte 0


Psfcity15_Newspaper_InteractCherie_Event_Script::
	lock
	compare VAR_RUSTURF_TUNNEL_STATE, 1
	goto_if_ne Psfcity15_Newspaper_InteractCherie_Event_Script_2
	msgbox Psfcity15_Newspaper_InteractCherie_Event_Script_Text_0
	closemessage
Psfcity15_Newspaper_InteractCherie_Event_Script_1:
	release
	end

Psfcity15_Newspaper_InteractCherie_Event_Script_2:
	call Manhunt_Cherie_Battle_Script
	goto Psfcity15_Newspaper_InteractCherie_Event_Script_1


Psfcity15_Newspaper_InteractCherie_Event_Script_Text_0:
	.string "...$"
