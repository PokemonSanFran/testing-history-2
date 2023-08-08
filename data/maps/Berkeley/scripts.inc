Berkeley_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Berkeley_MapScripts_MAP_SCRIPT_ON_TRANSITION
	map_script MAP_SCRIPT_ON_RETURN_TO_FIELD, Berkeley_MapScripts_MAP_SCRIPT_ON_RETURN_TO_FIELD
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Berkeley_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Berkeley_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	setflag FLAG_VISITED_BERKELEY
	call Quest_Rightingwrongs_Item_Visibility_Script
	call Quest_Rightingwrongs_Berekley_HideRobber_Script
	call swagbag2_SetUp_Object_Script
	call Quest_GetTheBand_HideBikerA_Script
	call SorryAboutMyFriends_Ariana_Visible_Script
	call Quest_StealTheAxe_UnlockDoor_Script
	return

Berkeley_MapScripts_MAP_SCRIPT_ON_RETURN_TO_FIELD:
	goto Quest_Rightingwrongs_Teacher_Visibility_Script
	return

Berkeley_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_BERKELEY_STATE, DEFEATED_MORTY, SorryAboutMyFriends_CheckCutscene_Script
	.2byte 0


Berkeley_Stan_Interact_Script::
	lock
	call Quest_WallaceArmy_LoadStanSpeech_Script
	msgbox gText_WallaceArmy_OhWallaceSama, MSGBOX_NPC
	call Quest_WallaceArmy_PreBattleStan_Script
	trainerbattle_single TRAINER_BERKELEY_STAN, gText_WallaceArmy_MarinSolarTheySpoke, gText_WallaceArmy_MyLord, Berkeley_Stan_PostBattle_Script
	goto Berkeley_Stan_PostBattle_Script
	return


Berkeley_Stan_PostBattle_Script::
	subquestmenu QUEST_MENU_COMPLETE_QUEST, QUEST_WALLACEARMY, SUB_QUEST_4
	call Quest_WallaceArmy_CheckCompletionRate_Script
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_WALLACEARMY
	compare VAR_RESULT, 0
	goto_if_eq Berkeley_Stan_PostBattle_Script_2
	msgbox gText_WallaceArmy_PostQuestPlaceholder1
Berkeley_Stan_PostBattle_Script_1:
	release
	end

Berkeley_Stan_PostBattle_Script_2:
	msgbox gText_WallaceArmy_PostBattlePlaceholder1
	goto Berkeley_Stan_PostBattle_Script_1


Berkeley_Biker_Interact_Script::
	msgbox gText_Berkeley_PlaceholderBiker, MSGBOX_NPC
	call Quest_GetTheBand_CheckQuestAndBike_Script
	compare VAR_RESULT, 0
	goto_if_ne Berkeley_Biker_Interact_Script_3
Berkeley_Biker_Interact_Script_1:
	end

Berkeley_Biker_Interact_Script_2:
	goto Quest_GetTheBand_Interact_BikerA_Dialogue
	goto Berkeley_Biker_Interact_Script_1

Berkeley_Biker_Interact_Script_3:
	compare VAR_TEMP_1, 0
	goto_if_ne Berkeley_Biker_Interact_Script_2
	goto Berkeley_Biker_Interact_Script_1


Berkeley_University_Locked_Door_Script::
	msgbox gText_Berkeley_TheDoor, MSGBOX_SIGN
	call Quest_StealTheAxe_LockedDoor_Dialogue
	release
	end


Berekley_Leland_Interact_Script::
	lock
	bufferspeciesname STR_VAR_1, SPECIES_STUFFUL
	bufferitemname STR_VAR_3, ITEM_COIN_CASE
	switch VAR_BERKELEY_AXE_STATE
	case AXE_UNTOUCHED, Berekley_Leland_Interact_Script_2
	case AXE_STOLEN, Berekley_Leland_Interact_Script_3
	case AXE_ASKED, Berekley_Leland_Interact_Script_4
	case AXE_THROWN_AWAY, Berekley_Leland_Interact_Script_4
	case AXE_TURNED_OVER, Berekley_Leland_Interact_Script_5
	return

Berekley_Leland_Interact_Script_2:
	goto Berkeley_Leland_Story_Dialogue
	return

Berekley_Leland_Interact_Script_3:
	goto Quest_StealTheAxe_DiscussStolen_Dialogue
	return

Berekley_Leland_Interact_Script_4:
	goto Quest_StealTheAxe_AskAxe_Dialogue
	return

Berekley_Leland_Interact_Script_5:
	goto Quest_StealTheAxe_HasAxe_Dialogue
	return


Berkeley_Leland_Story_Dialogue::
	msgbox gText_Berkeley_IAttended, MSGBOX_NPC, SPEAKER_LELAND
	return


gText_Berkeley_PlaceholderBiker::
	.string "i am a biker, and this is placeholder\n"
	.string "text.$"

gText_Berkeley_TheDoor::
	.string "The door is locked.$"

gText_Berkeley_IAttended::
	.string "You know, I used to go to\n"
	.string "Berkeleyuniversity! I was on their\l"
	.string "football team, and helped win the\l"
	.string "{STR_VAR_3} so many years ago.\l"
	.string "There's an old legend that it actually\l"
	.string "gives the holders power, but I'm proof\l"
	.string "that its nonsense. The {STR_VAR_3}\l"
	.string "means so much to me and my teammates,\l"
	.string "but its just a symbol.$"
