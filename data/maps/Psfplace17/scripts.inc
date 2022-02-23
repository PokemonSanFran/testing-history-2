Psfplace17_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Psfplace17_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Psfplace17_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	goto Psfplace17_MapScripts_OnTransition
	return


Psfplace17_MapScripts_OnTransition::
	switch VAR_ROUTE113_STATE
	case 0, Psfplace17_MapScripts_OnTransition_2
	case 1, Psfplace17_MapScripts_OnTransition_3
	case 2, Psfplace17_MapScripts_OnTransition_4
	return

Psfplace17_MapScripts_OnTransition_2:
	goto OffYouGo_Pre_ObjectSetup_Script
	return

Psfplace17_MapScripts_OnTransition_3:
	goto OffYouGo_ObjectSetup_Script
	return

Psfplace17_MapScripts_OnTransition_4:
	goto OffYouGo_ObjectCleanUp_Script
	return

