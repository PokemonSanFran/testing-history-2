Presidio_Improv_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Presidio_Improv_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Presidio_Improv_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_BuildingScope_ToggleObjects_Script
	return
