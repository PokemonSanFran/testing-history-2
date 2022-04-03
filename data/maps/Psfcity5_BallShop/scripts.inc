Psfcity5_BallShop_MapScripts::
	.byte 0


Psfcity5_Consulting_InteractDudley_Event_Script::
	lock
	compare VAR_RUSTURF_TUNNEL_STATE, 3
	goto_if_ne Psfcity5_Consulting_InteractDudley_Event_Script_2
	msgbox Psfcity5_Consulting_InteractDudley_Event_Script_Text_0
	closemessage
Psfcity5_Consulting_InteractDudley_Event_Script_1:
	release
	end

Psfcity5_Consulting_InteractDudley_Event_Script_2:
	call Manhunt_Dudley_Battle_Script
	goto Psfcity5_Consulting_InteractDudley_Event_Script_1


Psfcity5_Consulting_InteractDudley_Event_Script_Text_0:
	.string "...$"
