Quest_StealTheAxe_HideLeader_Script::
	special GetNumberOfBadges
	compare VAR_CHUCK_STATE, BATTLE_1_COMPLETE
	goto_if_ne Quest_StealTheAxe_HideLeader_Script_2
Quest_StealTheAxe_HideLeader_Script_1:
	compare VAR_RESULT, 6
	goto_if_lt Quest_StealTheAxe_HideLeader_Script_5
Quest_StealTheAxe_HideLeader_Script_4:
	switch VAR_ALAMEDA_STATE
	case START_SURVIVAL_CHANCE, Quest_StealTheAxe_HideLeader_Script_8
	case POST_SURVIVAL_CHANCE, Quest_StealTheAxe_HideLeader_Script_8
	case WHY_ARE_YOU_HELPING_THEM, Quest_StealTheAxe_HideLeader_Script_8
	case POST_EARTHQUAKE, Quest_StealTheAxe_HideLeader_Script_8
	case START_EARTHQUAKE_RESCUE, Quest_StealTheAxe_HideLeader_Script_8
	case POST_EARTHQUAKE_RESCUE, Quest_StealTheAxe_HideLeader_Script_8
	case MEET_AT_PSFROUTE8, Quest_StealTheAxe_HideLeader_Script_8
	return

Quest_StealTheAxe_HideLeader_Script_2:
	setflag FLAG_TEMP_5
	goto Quest_StealTheAxe_HideLeader_Script_1

Quest_StealTheAxe_HideLeader_Script_5:
	setflag FLAG_TEMP_5
	goto Quest_StealTheAxe_HideLeader_Script_4

Quest_StealTheAxe_HideLeader_Script_8:
	setflag FLAG_TEMP_5
	return


Quest_StealTheAxe_Event_Script::
	setvar VAR_TEMP_0, 0
	bufferitemname STR_VAR_2, ITEM_COIN_CASE
	returnqueststate QUEST_STEALTHEAXE
	lock
	faceplayer
	switch VAR_RESULT
	case QUEST_MENU_SET_REWARD, Quest_StealTheAxe_Event_Script_3
	case QUEST_MENU_SET_ACTIVE, Quest_StealTheAxe_Event_Script_4
	call Quest_StealTheAxe_CheckItem_Script
	goto Quest_StealTheAxe_StartQuest_Dialogue
Quest_StealTheAxe_Event_Script_1:
	release
	end

Quest_StealTheAxe_Event_Script_3:
	goto Quest_StealTheAxe_Reward_Dialogue
	goto Quest_StealTheAxe_Event_Script_1

Quest_StealTheAxe_Event_Script_4:
	goto Quest_StealTheAxe_Active_Dialogue
	goto Quest_StealTheAxe_Event_Script_1


Quest_StealTheAxe_StartQuest_Dialogue::
	msgbox gText_StealTheAxe_PlayerGetToSee, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_ShouldntYouBe, , SPEAKER_ZOEY, , EMOTE_CONFUSE
	msgbox gText_StealTheAxe_ThatsExactlyWhy, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_IJustCameFromThe, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_IKeepHearingAbout, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_JustLikeWhitney, , SPEAKER_CHUCK, , EMOTE_ANGRY
	msgbox gText_StealTheAxe_IStillDontKnow, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_SomebodyWithMyCreds, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_ButIfSomebody, , SPEAKER_CHUCK
	startquest QUEST_STEALTHEAXE
	msgbox gText_StealTheAxe_IllBeHere, , SPEAKER_CHUCK
	closemessage
	release
	end


Quest_StealTheAxe_Active_Dialogue::
	msgbox gText_StealTheAxe_WhatsTheSitrep, MSGBOX_NPC, SPEAKER_CHUCK
	msgbox gText_StealTheAxe_GainingATactical, , SPEAKER_CHUCK
	closemessage
	release
	end


Quest_StealTheAxe_Reward_Dialogue::
	playse SE_PIN
	applymovement 21, Common_Movement_ExclamationMark
	msgbox gText_StealTheAxe_MissionComplete, , SPEAKER_CHUCK, TAIL_SHOUT, EMOTE_HAPPY
	goto Quest_StealTheAxe_Conclusion_Dialogue
	return


Quest_StealTheAxe_Conclusion_Dialogue::
	applymovement 21, Common_Movement_FaceAwayPlayer
	waitmovement 21
	bufferspeciesname STR_VAR_1, SPECIES_TOXAPEX
	msgbox gText_StealTheAxe_NowLetsHave, , SPEAKER_CHUCK, TAIL_WHISPER
	closemessage
	playse SE_PIN
	applymovement 21, Common_Movement_ExclamationMark
	msgbox gText_StealTheAxe_ItsNotDoing, , SPEAKER_CHUCK, TAIL_WHISPER, EMOTE_ANGRY
	msgbox gText_StealTheAxe_StatsAreHoldingSteady, , SPEAKER_CHUCK, TAIL_WHISPER, EMOTE_ANGRY
	applymovement 21, Common_Movement_FacePlayer
	waitmovement 21
	msgbox gText_StealTheAxe_IGotSomeBadIntel, , SPEAKER_CHUCK
	closemessage
	call Quest_StealTheAxe_HandleMoney_Script
	msgbox gText_StealTheAxe_SeeYouOnTheBattlefield, , SPEAKER_CHUCK
	applymovement 21, Quest_StealTheAxe_LeaveNavalBase_Movement
	completequest QUEST_STEALTHEAXE
	removeobject 21
	setvar VAR_CHUCK_STATE, QUEST_1_COMPLETE
	release
	end


Quest_StealTheAxe_HandleMoney_Script::
	showmoneybox 0, 0
	waitbuttonpress
	compare VAR_TEMP_0, 0
	goto_if_gt Quest_StealTheAxe_HandleMoney_Script_2
	addmoney 4000
Quest_StealTheAxe_HandleMoney_Script_1:
	playse SE_SHOP
	updatemoneybox 0
	waitse
	waitbuttonpress
	hidemoneybox
	closemessage
	return

Quest_StealTheAxe_HandleMoney_Script_2:
	addmoney 8000
	goto Quest_StealTheAxe_HandleMoney_Script_1


Quest_StealTheAxe_CheckItem_Script::
	checkitem ITEM_COIN_CASE, 1
	compare VAR_RESULT, 0
	goto_if_ne Quest_StealTheAxe_CheckItem_Script_2
Quest_StealTheAxe_CheckItem_Script_1:
	return

Quest_StealTheAxe_CheckItem_Script_2:
	goto Quest_StealTheAxe_SecretComplete_Dialogue
	goto Quest_StealTheAxe_CheckItem_Script_1


Quest_StealTheAxe_SecretComplete_Dialogue::
	setvar VAR_TEMP_0, 1
	msgbox gText_StealTheAxe_PlayerGetToSee, , SPEAKER_CHUCK
	msgbox gText_StealTheAxe_IsThatTheAxe, MSGBOX_YESNO, SPEAKER_CHUCK, , EMOTE_SHOCK
	compare VAR_RESULT, 0
	goto_if_ne Quest_StealTheAxe_SecretComplete_Dialogue_2
	msgbox gText_StealTheAxe_ISeeWhen, , SPEAKER_CHUCK
Quest_StealTheAxe_SecretComplete_Dialogue_1:
	release
	end

Quest_StealTheAxe_SecretComplete_Dialogue_2:
	goto Quest_StealTheAxe_Conclusion_Dialogue
	goto Quest_StealTheAxe_SecretComplete_Dialogue_1


Quest_StealTheAxe_CheckIfNight_Script::
	gettime
	setvar VAR_TEMP_2, 0
	compare VAR_0x8000, 20
	goto_if_gt Quest_StealTheAxe_CheckIfNight_Script_2
	compare VAR_0x8000, 6
	goto_if_lt Quest_StealTheAxe_CheckIfNight_Script_2
Quest_StealTheAxe_CheckIfNight_Script_1:
	return

Quest_StealTheAxe_CheckIfNight_Script_2:
	setvar VAR_TEMP_2, 1
	goto Quest_StealTheAxe_CheckIfNight_Script_1


Quest_StealTheAxe_UnlockDoor_Script::
	call Quest_StealTheAxe_CheckIfNight_Script
	compare VAR_TEMP_2, 1
	goto_if_eq Quest_StealTheAxe_UnlockDoor_Script_1
	return

Quest_StealTheAxe_UnlockDoor_Script_1:
	setflag FLAG_TEMP_3
	release
	end


Quest_StealTheAxe_LockedDoor_Dialogue::
	returnqueststate QUEST_STEALTHEAXE
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_eq Quest_StealTheAxe_LockedDoor_Dialogue_2
Quest_StealTheAxe_LockedDoor_Dialogue_1:
	return

Quest_StealTheAxe_LockedDoor_Dialogue_2:
	msgbox gText_StealTheAxe_IShould, , SPEAKER_ZOEY, TAIL_THOUGHT
	goto Quest_StealTheAxe_LockedDoor_Dialogue_1


Quest_StealTheAxe_LeaveNavalBase_Movement:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

gText_StealTheAxe_IShould::
	.string "Hmm... I should come back tonight.$"

gText_StealTheAxe_PlayerGetToSee::
	.string "{PLAYER}! Good to see you.$"

gText_StealTheAxe_ShouldntYouBe::
	.string "Shouldn't you be fighting some war or\n"
	.string "something?$"

gText_StealTheAxe_ThatsExactlyWhy::
	.string "That's exactly why I'm here!$"

gText_StealTheAxe_IJustCameFromThe::
	.string "I just came from Berkeleyuniversity.\n"
	.string "They've got a display for the\l"
	.string "{STR_VAR_2}, one of the prized\l"
	.string "possessions of their Athletic\l"
	.string "department.$"

gText_StealTheAxe_IKeepHearingAbout::
	.string "I've heard rumors that this axe\n"
	.string "provides incredible power to the\l"
	.string "wielder!$"

gText_StealTheAxe_JustLikeWhitney::
	.string "But just like Whtiney, they've got it\n"
	.string "sealed up in some glass case! Just the\l"
	.string "intelligence that had it in our active\l"
	.string "possesion would be a huge tactical\l"
	.string "advantage!$"

gText_StealTheAxe_IStillDontKnow::
	.string "I still don't know what this tactical\n"
	.string "advantage is for...$"

gText_StealTheAxe_SomebodyWithMyCreds::
	.string "Somebody with my credentials can't be\n"
	.string "seen sneaking into Berkeleyuniversity\l"
	.string "at night, slipping past all the guards,\l"
	.string "and stealing the {STR_VAR_2} with\l"
	.string "almost zero security...$"

gText_StealTheAxe_ButIfSomebody::
	.string "But if somebody else did that, I would\n"
	.string "be willing to pay hansomely for it.$"

gText_StealTheAxe_IllBeHere::
	.string "I'll be here.$"

gText_StealTheAxe_WhatsTheSitrep::
	.string "What's the sitrep?$"

gText_StealTheAxe_GainingATactical::
	.string "My analysis tells me that the best\n"
	.string "strategic window to infilitate\l"
	.string "Berkeleyuniversity and get the\l"
	.string "{STR_VAR_2} is between 21:00 and\l"
	.string "6:00.$"

gText_StealTheAxe_MissionComplete::
	.string "Mission complete!$"

gText_StealTheAxe_NowLetsHave::
	.string "Now let's have my {STR_VAR_1} hold\n"
	.string "it...$"

gText_StealTheAxe_ItsNotDoing::
	.string "...its not doing anything!$"

gText_StealTheAxe_StatsAreHoldingSteady::
	.string "Stats are holding steady... mood hasn't\n"
	.string "changed. This isn't making any\l"
	.string "difference!$"

gText_StealTheAxe_IGotSomeBadIntel::
	.string "I got some bad intel out there. I think\n"
	.string "this thing is a hunk of junk. You can\l"
	.string "keep it. And as promised...$"

gText_StealTheAxe_SeeYouOnTheBattlefield::
	.string "See you on the battlefield solider.$"

gText_StealTheAxe_IsThatTheAxe::
	.string "Is that the {STR_VAR_2}? I would\n"
	.string "pay very handsomely if I could buy it\l"
	.string "from you, {PLAYER}.$"

gText_StealTheAxe_ISeeWhen::
	.string "I see. When you change your mind, I'll be\n"
	.string "here.$"
