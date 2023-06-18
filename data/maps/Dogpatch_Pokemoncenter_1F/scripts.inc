Dogpatch_Pokemoncenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Dogpatch_Pokemoncenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Dogpatch_Pokemoncenter_1F_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setrespawn HEAL_LOCATION_DOGPATCH
	end


Dogpatch_Pokemoncenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, 1
	call Common_EventScript_PkmnCenterNurse
	release
	end


Dogpatch_Pokemoncenter_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart OldaleTown_Mart_Pokemart_Basic
	call Quest_Bodegaburnout_CheckSubquestState_Script
	msgbox gText_PleaseComeAgain
	release
	end

