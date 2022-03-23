Psfcity7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfcity7_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfcity7_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfcity7_MapScripts_OnTransition
	return


Psfcity7_MapScripts_OnTransition::
	switch VAR_PSFCITY7_STATE
	case 0, Psfcity7_MapScripts_OnTransition_2
	case 1, Psfcity7_MapScripts_OnTransition_3
	return

Psfcity7_MapScripts_OnTransition_2:
	call HowDoWeGetHome_HideObject_Script
	return

Psfcity7_MapScripts_OnTransition_3:
	call HowDoWeGetHome_ObjectCleanUp_Script
	call HowDoWeGetHome_ChangeCrowdMovementType_Script
	return

