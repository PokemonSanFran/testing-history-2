Psfroute61_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute61_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Psfroute61_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Psfroute61_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_ArtisanBalls2_CheckTrainerC_Script
	call EnterTheMaster_Muirwoods_Entrance_ObjectSetup_Script
	call Quest_Ultrawormholeresearch_ControlTotemVisibility
	return

Psfroute61_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_Ultrawormholeresearch_TryRemoveTotem_Script
	return

