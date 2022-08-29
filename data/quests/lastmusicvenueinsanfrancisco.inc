Quest_LastMusicVenue_Debug_Script::
	questmenu QUEST_MENU_SET_REWARD, QUEST_LASTMUSICVENUEINSANFRANCISCO
	warp MAP_JAPANTOWN, 15, 16
	release
	end


Quest_LastMusicVenue_CheckDrummerImpact::
	returnqueststate QUEST_LASTMUSICVENUEINSANFRANCISCO
	compare VAR_RESULT, QUEST_MENU_SET_REWARD
	goto_if_lt Quest_LastMusicVenue_CheckDrummerImpact_1
	return

Quest_LastMusicVenue_CheckDrummerImpact_1:
	call Quest_LastMusicVenue_HideVenueDrummers
	call Quest_LastMusicVenue_ChangeMusic
	return


Quest_LastMusicVenue_HideVenueDrummers::
	setflag FLAG_TEMP_1
	return


Quest_LastMusicVenue_HidePublicDrummers::
	returnqueststate QUEST_LASTMUSICVENUEINSANFRANCISCO
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_gt Quest_LastMusicVenue_HidePublicDrummers_1
	return

Quest_LastMusicVenue_HidePublicDrummers_1:
	setflag FLAG_TEMP_6
	return


Quest_LastMusicVenue_ChangeMusic::
	playbgm MUS_RG_FUCHSIA, TRUE
	return


Quest_LastMusicVenue_StartQuest_Script::
	msgbox gText_Quest_LastMusicVenue_IHopeYoureNot, MSGBOX_NPC
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_Quest_LastMusicVenue_WhyIsThat, MSGBOX_NPC
	callnative ClearMugshot
	msgbox gText_Quest_LastMusicVenue_ItsAViciousCycle, MSGBOX_NPC
	msgbox gText_Quest_LastMusicVenue_YoureYoungDoYouKnow, MSGBOX_NPC
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_DRUMCIRCLE
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	compare VAR_RESULT, 0
	goto_if_ne Quest_LastMusicVenue_StartQuest_Script_2
	msgbox gText_Quest_LastMusicVenue_IllKeepMyEyesPeeled, MSGBOX_NPC
Quest_LastMusicVenue_StartQuest_Script_1:
	callnative ClearMugshot
	startquest QUEST_LASTMUSICVENUEINSANFRANCISCO
	release
	end

Quest_LastMusicVenue_StartQuest_Script_2:
	msgbox gText_Quest_LastMusicVenue_ActuallyIMetSome, MSGBOX_NPC
	msgbox gText_Quest_LastMusicVenue_TheDrumCircle, MSGBOX_NPC
	goto Quest_LastMusicVenue_StartQuest_Script_1


Quest_LastMusicVenue_Active_Dialogue::
	msgbox gText_Quest_LastMusicVenue_AnyLuck, MSGBOX_NPC
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_DRUMCIRCLE
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	compare VAR_RESULT, 0
	goto_if_ne Quest_LastMusicVenue_Active_Dialogue_2
	msgbox gText_Quest_LastMusicVenue_ImStillLooking, MSGBOX_NPC
Quest_LastMusicVenue_Active_Dialogue_1:
	callnative ClearMugshot
	release
	end

Quest_LastMusicVenue_Active_Dialogue_2:
	msgbox gText_Quest_LastMusicVenue_IHavent, MSGBOX_NPC
	goto Quest_LastMusicVenue_Active_Dialogue_1


Quest_LastMusicVenue_InformDrummers_Dialogue::
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LastMusicVenue_HaveYouGuysSeen
	callnative ClearMugshot
	msgbox gText_LastMusicVenue_Nah
	setvar VAR_MUGSHOT, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_LastMusicVenue_YouNeed
	callnative ClearMugshot
	msgbox gText_LastMusicVenue_ThisCouldBe
	closemessage
	fadescreen FADE_TO_BLACK
	removeobject 23
	removeobject 24
	removeobject 25
	removeobject 26
	fadescreen FADE_FROM_BLACK
	questmenu QUEST_MENU_SET_REWARD, QUEST_LASTMUSICVENUEINSANFRANCISCO
	release
	end


Quest_LastMusicVenue_Reward_Dialogue::
	msgbox gText_Quest_LastMusicVenue_TheseDrummers, MSGBOX_NPC
	msgbox gText_Quest_LastMusicVenue_TurnsOutTheyKnow, MSGBOX_NPC
	call Quest_LastMusicVenue_GiveReward_Script
	completequest QUEST_LASTMUSICVENUEINSANFRANCISCO
	release
	end


Quest_LastMusicVenue_GiveReward_Script::
	giveitem ITEM_STARF_BERRY, 1
	return


gText_Quest_LastMusicVenue_IHopeYoureNot::
	.string "I hope you're not here to see any\n"
	.string "music... ain't nothing playing today. Or\l"
	.string "tomorrow. Or any day after that.$"

gText_Quest_LastMusicVenue_WhyIsThat::
	.string "Why is that?$"

gText_Quest_LastMusicVenue_ItsAViciousCycle::
	.string "*sigh* Its a vicious cycle. The League\n"
	.string "keeps buying up concert venues to\l"
	.string "turn into arenas for their crazy new\l"
	.string "League. The local musicians don't have\l"
	.string "venues to perform in, so they stop. The\l"
	.string "remaining venues can't book new\l"
	.string "musicians because they've all quit. So\l"
	.string "when the League wants to buy another\l"
	.string "property... we jump at the chance.$"

gText_Quest_LastMusicVenue_YoureYoungDoYouKnow::
	.string "You're young, do you know any music\n"
	.string "artists looking for a venue? Even just\l"
	.string "one or two would be huge.$"

gText_Quest_LastMusicVenue_ActuallyIMetSome::
	.string "Actually, I met some! Let me see if\n"
	.string "they're interested.$"

gText_Quest_LastMusicVenue_TheDrumCircle::
	.string "(The drum circle in Haightashbury would\n"
	.string "be perfect for this!)$"

gText_Quest_LastMusicVenue_IllKeepMyEyesPeeled::
	.string "I'll keep my eyes peeled as I travel!$"

gText_Quest_LastMusicVenue_AnyLuck::
	.string "Any luck finding some artists?$"

gText_Quest_LastMusicVenue_IHavent::
	.string "I haven't had a chance to talk to them\n"
	.string "yet!$"

gText_Quest_LastMusicVenue_ImStillLooking::
	.string "I'm still looking for somebody! But\n"
	.string "you're right, it's hard...$"

gText_Quest_LastMusicVenue_TheseDrummers::
	.string "These dummers are amazing! They're so\n"
	.string "happy to be here, and we were able to\l"
	.string "work something out!$"

gText_Quest_LastMusicVenue_TurnsOutTheyKnow::
	.string "Turns out they know other artists too!$"

gText_LastMusicVenue_HaveYouGuysSeen::
	.string "Have you guys seen the Masonic venue?$"

gText_LastMusicVenue_Nah::
	.string "Nah, what's that?$"

gText_LastMusicVenue_YouNeed::
	.string "You need to get down there! They're\n"
	.string "really looking for musicians and I\l"
	.string "think you'd be a good fit.$"

gText_LastMusicVenue_ThisCouldBe::
	.string "This could be our shot yo!$"
