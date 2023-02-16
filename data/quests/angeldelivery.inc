Quest_AngelDelivery_Hide_BikerA_Script::
	questmenu QUEST_MENU_CHECK_INACTIVE, QUEST_ANGELDELIVERY
	compare VAR_RESULT, 0
	goto_if_eq Quest_AngelDelivery_Hide_BikerA_Script_2
Quest_AngelDelivery_Hide_BikerA_Script_1:
	return

Quest_AngelDelivery_Hide_BikerA_Script_2:
	setflag FLAG_TEMP_5
	goto Quest_AngelDelivery_Hide_BikerA_Script_1


Quest_AngelDelivery_Hide_BikerB_Script::
	returnqueststate QUEST_ANGELDELIVERY
	compare VAR_RESULT, QUEST_MENU_SET_ACTIVE
	goto_if_gt Quest_AngelDelivery_Hide_BikerB_Script_2
Quest_AngelDelivery_Hide_BikerB_Script_1:
	return

Quest_AngelDelivery_Hide_BikerB_Script_2:
	setflag FLAG_TEMP_5
	goto Quest_AngelDelivery_Hide_BikerB_Script_1


Quest_AngelDelivery_StartQuest_Dialogue::
	lock
	faceplayer
	call Quest_AngelDelivery_BikerA_Active_Dialogue
	msgbox gText_AngelDelivery_ShitMyBike
	msgbox gText_AngelDelivery_CanYouDeliever
	giveitem ITEM_SCANNER, 1
	closemessage
	startquest QUEST_ANGELDELIVERY
	release
	end


Quest_AngelDelivery_BikerA_Active_Dialogue::
	questmenu QUEST_MENU_CHECK_ACTIVE, QUEST_ANGELDELIVERY
	compare VAR_RESULT, 0
	goto_if_ne Quest_AngelDelivery_BikerA_Active_Dialogue_1
	return

Quest_AngelDelivery_BikerA_Active_Dialogue_1:
	msgbox gText_AngelDelivery_HopefullyICanGetThisFixed, MSGBOX_NPC
	end


Quest_AngelDelivery_BikerB_Event_Script::
	lock
	returnqueststate QUEST_ANGELDELIVERY
	switch VAR_RESULT
	case QUEST_MENU_SET_ACTIVE, Quest_AngelDelivery_BikerB_Event_Script_2
	case QUEST_MENU_SET_REWARD, Quest_AngelDelivery_BikerB_Event_Script_3
	goto Quest_AngelDelivery_BikerB_Inactive_Dialogue
	return

Quest_AngelDelivery_BikerB_Event_Script_2:
	goto Quest_AngelDelivery_BikerB_Active_Dialogue
	return

Quest_AngelDelivery_BikerB_Event_Script_3:
	goto Quest_AngelDelivery_BikerB_Reward_Dialogue
	return


Quest_AngelDelivery_BikerB_Inactive_Dialogue::
	msgbox gText_AngelDelivery_ShitTheyreLate, MSGBOX_NPC
	end


Quest_AngelDelivery_BikerB_Active_Dialogue::
	faceplayer
	msgbox gText_AngelDelivery_ShitTheyreLate
	msgbox gText_AngelDelivery_OhTheySentYou
	msgbox gText_AngelDelivery_PlayerGaveThe
	removeitem ITEM_SCANNER, 1
	msgbox gText_AngelDelivery_ICantThankYouBut
	msgbox gText_AngelDelivery_TellThemThePassword
	closemessage
	questmenu QUEST_MENU_SET_REWARD, QUEST_ANGELDELIVERY
	release
	end


Quest_AngelDelivery_BikerB_Reward_Dialogue::
	msgbox gText_AngelDelivery_IllCatchUpWithYou, MSGBOX_NPC
	end


Quest_AngelDelivery_StartBattle_Cutscene::
	call Dogpatch_BIkerhq_GuardsBlockDoor_Cutscene
	msgbox gText_AngelDelivery_WaitThePassword, , SPEAKER_ZOEY
	closemessage
	playse SE_PIN
	applymovement 1, Common_Movement_QuestionMark
	applymovement 2, Common_Movement_QuestionMark
	applymovement 3, Common_Movement_ExclamationMark
	applymovement 4, Common_Movement_ExclamationMark
	waitse
	waitmovement 4
	msgbox gText_AngelDelivery_LetsHearEmOut
	closemessage
	applymovement 1, Quest_AngelDelivery_BackOffLeft_Movement
	applymovement 2, Quest_AngelDelivery_BackOffRight_Movement
	waitmovement 2
	fadescreen FADE_TO_BLACK
	msgbox gText_AngelDelivery_PlayerExplained
	waitbuttonpress
	closemessage
	fadescreen FADE_FROM_BLACK
	msgbox gText_AngelDelivery_WellDamnAnybodyWhoHelps
	msgbox gText_AngelDelivery_MatterOfFatIGotSomething
	closemessage
	applymovement 3, Quest_AngelDelivery_WalkToPlayer_Movement
	goto Quest_AngelDelivery_StartBattle_Script
	return


Quest_AngelDelivery_StartBattle_Script::
	msgbox gText_AngelDelivery_ButLetsSeeIfYoureToughEnough
	trainerbattle_no_intro TRAINER_FOSTER, gText_AngelDelivery_YeahYoureTough
	closemessage
	goto Quest_AngelDelivery_PostBattle_Script
	return


Quest_AngelDelivery_PostBattle_Script::
	msgbox gText_AngelDelivery_AsPromised
	closemessage
	giveitem ITEM_MACH_BIKE, 1
	msgbox gText_AngelDelivery_OneOfYourOwn
	closemessage
	completequest QUEST_ANGELDELIVERY
	release
	end


Dogpatch_BIkerhq_GuardFromLeft_Movement:
	walk_faster_right
	face_down
	step_end

Dogpatch_BIkerhq_GuardFromRight_Movement:
	walk_faster_left
	face_down
	step_end

Quest_AngelDelivery_BackOffLeft_Movement:
	face_right
	lock_facing_direction
	walk_left
	step_end

Quest_AngelDelivery_BackOffRight_Movement:
	face_left
	lock_facing_direction
	walk_right
	step_end

Quest_AngelDelivery_WalkToPlayer_Movement:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

gText_AngelDelivery_ShitMyBike::
	.string "Shit my bike is broken$"

gText_AngelDelivery_CanYouDeliever::
	.string "you're that hotshot trainer right? can\n"
	.string "you help me out and deliever this$"

gText_AngelDelivery_HopefullyICanGetThisFixed::
	.string "hopefully i can get this fixed...$"

gText_AngelDelivery_ShitTheyreLate::
	.string "shit they're late...$"

gText_AngelDelivery_OhTheySentYou::
	.string "oh, they sent you? why didn't they just\n"
	.string "call...$"

gText_AngelDelivery_PlayerGaveThe::
	.string "you gave the thingy to the other biker.$"

gText_AngelDelivery_ICantThankYouBut::
	.string "I can't thank you enough$"

gText_AngelDelivery_TellThemThePassword::
	.string "if they give you trouble, just recite\n"
	.string "the password 'fixies rule'$"

gText_AngelDelivery_IllCatchUpWithYou::
	.string "I'll catch up with you later$"

gText_AngelDelivery_WaitThePassword::
	.string "wait i know the password$"

gText_AngelDelivery_LetsHearEmOut::
	.string "what? okay, let's hear 'em out.$"

gText_AngelDelivery_PlayerExplained::
	.string "{PLAYER} explained the situation to\n"
	.string "the gang.$"

gText_AngelDelivery_WellDamnAnybodyWhoHelps::
	.string "Well damn, anybody who helps us out in a\n"
	.string "bind is an honoary member. Welcome to\l"
	.string "the bikerz, {PLAYER}!$"

gText_AngelDelivery_MatterOfFatIGotSomething::
	.string "Matter of fact, I got something for ya\n"
	.string "to celebrate your initation.$"

gText_AngelDelivery_YeahYoureTough::
	.string "yeah youre hella tough!$"

gText_AngelDelivery_ButLetsSeeIfYoureToughEnough::
	.string "But let's see if you're tough enough to\n"
	.string "use it!$"

gText_AngelDelivery_AsPromised::
	.string "As promised!$"

gText_AngelDelivery_OneOfYourOwn::
	.string "One of your own! I know Uber has those\n"
	.string "rent-bikes all over, but this is yours,\l"
	.string "free of charge.$"
