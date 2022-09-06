Lakemerritt_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Lakemerritt_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Lakemerritt_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_ShutDownMedicineMan_HideDealer_Script
	call Lakemerritt_ObjectVisibility_Script
	return


Lakemerritt_ObjectVisibility_Script::
	setflag FLAG_TEMP_2
	goto_if_set FLAG_TIMELINE_TRUE, Lakemerritt_ObjectVisibility_Script_9
Lakemerritt_ObjectVisibility_Script_7:
	goto_if_set FLAG_TIMELINE_FALSE, Lakemerritt_ObjectVisibility_Script_6
Lakemerritt_ObjectVisibility_Script_5:
	compare VAR_STORYLINE_STATE, STORY_ASSIGNED_SIEBOLD_QUESTS
	goto_if_lt Lakemerritt_ObjectVisibility_Script_3
	call Manhunt_HideGiovanni_Script
	return

Lakemerritt_ObjectVisibility_Script_1:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_ARCHIE
	return

Lakemerritt_ObjectVisibility_Script_2:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_ARCHIE
	return

Lakemerritt_ObjectVisibility_Script_3:
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_ARCHIE
	return

Lakemerritt_ObjectVisibility_Script_6:
	compare VAR_MANHUNT_STATE, DEFEATED_MANHUNT_GIOVANNI
	goto_if_lt Lakemerritt_ObjectVisibility_Script_2
	goto Lakemerritt_ObjectVisibility_Script_5

Lakemerritt_ObjectVisibility_Script_9:
	compare VAR_MASK_OFF_STATE, DEFEATED_MASK_OFF_GIOVANNI
	goto_if_lt Lakemerritt_ObjectVisibility_Script_1
	goto Lakemerritt_ObjectVisibility_Script_7


Lakemerritt_InteractWikstrom_Event_Script::
	lock
	goto_if_set FLAG_TIMELINE_TRUE, Lakemerritt_InteractWikstrom_Event_Script_9
Lakemerritt_InteractWikstrom_Event_Script_7:
	goto_if_set FLAG_TIMELINE_FALSE, Lakemerritt_InteractWikstrom_Event_Script_6
Lakemerritt_InteractWikstrom_Event_Script_5:
	compare VAR_STORYLINE_STATE, 25
	goto_if_lt Lakemerritt_InteractWikstrom_Event_Script_4
Lakemerritt_InteractWikstrom_Event_Script_1:
	release
	end

Lakemerritt_InteractWikstrom_Event_Script_2:
	call MaskOff_Encounter_Giovanni_Dialogue
	goto Lakemerritt_InteractWikstrom_Event_Script_1

Lakemerritt_InteractWikstrom_Event_Script_3:
	call Manhunt_Encounter_Giovanni_Dialogue
	goto Lakemerritt_InteractWikstrom_Event_Script_1

Lakemerritt_InteractWikstrom_Event_Script_4:
	msgbox Lakemerritt_InteractWikstrom_Event_Script_Text_0, MSGBOX_AUTOCLOSE
	goto Lakemerritt_InteractWikstrom_Event_Script_1

Lakemerritt_InteractWikstrom_Event_Script_6:
	compare VAR_RUSTURF_TUNNEL_STATE, 4
	goto_if_gt Lakemerritt_InteractWikstrom_Event_Script_3
	goto Lakemerritt_InteractWikstrom_Event_Script_5

Lakemerritt_InteractWikstrom_Event_Script_9:
	compare VAR_LILYCOVE_CITY_STATE, 3
	goto_if_gt Lakemerritt_InteractWikstrom_Event_Script_2
	goto Lakemerritt_InteractWikstrom_Event_Script_7


LakeMerritt_Herb_Dealer_Script::
	lock
	faceplayer
	msgbox gText_Lakemerritt_HeyManWhatCanI
	waitmessage
	pokemart HerbDealerShop
	msgbox gText_Lakemerritt_ThanksComeAgain
	goto Quest_ShutDownMedicineMan_MakePurchase_Dialogue
	return


	.align 2
HerbDealerShop:
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_NONE

Lakemerritt_Interact_HerbBystander_Dialogue::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_SHUTDOWNMEDICINEMAN
	compare VAR_RESULT, 0
	goto_if_ne Lakemerritt_Interact_HerbBystander_Dialogue_2
	msgbox gText_Lakemerritt_ThisGuyIs, MSGBOX_NPC
Lakemerritt_Interact_HerbBystander_Dialogue_1:
	end

Lakemerritt_Interact_HerbBystander_Dialogue_2:
	msgbox gText_Lakemerritt_OhManDidYouHear, MSGBOX_NPC
	goto Lakemerritt_Interact_HerbBystander_Dialogue_1


Lakemerritt_InteractWikstrom_Event_Script_Text_0:
	.string "random flavor text about training here$"

gText_Lakemerritt_HeyManWhatCanI::
	.string "hey man what can i get you today$"

gText_Lakemerritt_ThanksComeAgain::
	.string "thanks come again!$"

gText_Lakemerritt_ThisGuyIs::
	.string "this guy has the best herbs, and so\n"
	.string "much cheaper than the place in\l"
	.string "Pacifica! I don't think this guy is like\l"
	.string "totally above board...$"

gText_Lakemerritt_OhManDidYouHear::
	.string "oh man did you hear? the herb guy got\n"
	.string "shut down. looks like somebody ratted\l"
	.string "him out for not having a license. now we\l"
	.string "can only buy from that place in\l"
	.string "Pacifica!$"
