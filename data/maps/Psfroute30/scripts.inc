Psfroute30_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfroute30_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RESUME, Psfroute30_MapScripts_MAP_SCRIPT_ON_RESUME
	.byte 0

Psfroute30_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Ultrawormholeresearch_ControlTotemVisibility
	return

Psfroute30_MapScripts_MAP_SCRIPT_ON_RESUME:
	call Quest_Ultrawormholeresearch_TryRemoveTotem_Script
	return


Psfroute30_ConstructionWorker_Dialogue::
	msgbox Psfroute30_TheBridgeIs, MSGBOX_NPC
	end


Psfroute30_TheBridgeIs::
	.string "The bridge is under construction.$"
