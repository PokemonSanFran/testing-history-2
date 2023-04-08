Sunset_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Sunset_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_LOAD, Sunset_MapScripts_MAP_SCRIPT_ON_LOAD
	.byte 0

Sunset_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call ImIn_HideObject_OutsideHouse_Script
	call Quest_ReturnDoll_HideObject_Script
	call Quest_StolenTrade_HideObjectA_Script
	call Quest_CutePokemon_HideMelissaB_Script
	call Quest_ButOnlyIn_HideGunda_Script
	return

Sunset_MapScripts_MAP_SCRIPT_ON_LOAD:
	call ImIn_DestroyWall_Script
	return


Sabrina_House_LockedDoor_Script::
	msgbox gText_Sunset_LockedDoor, MSGBOX_SIGN
	end


Waite_Interact_Script::
	msgbox gText_Sunset_ICantBelieve, , SPEAKER_WAITE, TAIL_WHISPER
	special GetNumberOfBadges
	goto_if_set FLAG_BADGE05_GET, Quest_Foodtruckbureaucracy_Food_Interact_Script
	end


gText_Sunset_ICantBelieve::
	.string "I can't believe this shit!$"

gText_Sunset_LockedDoor::
	.string "The front door is locked.$"
