YouCantStopMe_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


YouCantStopMe_MoveObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setobjectxy 2, 15, 5
	setobjectxyperm 2, 15, 5
	setobjectnewmovementtype 2, MOVEMENT_TYPE_FACE_DOWN
	return


YouCantStopMe_ObjectCleanUp_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	setflag FLAG_TEMP_3
	return


YouCantStopMe_LocatePlayer_Script::
	clearflag FLAG_TEMP_1
	playse SE_EXIT
	waitse
	addobject 1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	switch VAR_TEMP_1
	case 5, YouCantStopMe_LocatePlayer_Script_3
	case 6, YouCantStopMe_LocatePlayer_Script_4
	case 7, YouCantStopMe_LocatePlayer_Script_5
	case 8, YouCantStopMe_LocatePlayer_Script_6
YouCantStopMe_LocatePlayer_Script_1:
	waitmovement 1
	return

YouCantStopMe_LocatePlayer_Script_3:
	applymovement 1, YouCantStopMe_WalkToPlayerY5
	goto YouCantStopMe_LocatePlayer_Script_1

YouCantStopMe_LocatePlayer_Script_4:
	applymovement 1, YouCantStopMe_WalkToPlayerY6
	goto YouCantStopMe_LocatePlayer_Script_1

YouCantStopMe_LocatePlayer_Script_5:
	applymovement 1, YouCantStopMe_WalkToPlayerY7
	goto YouCantStopMe_LocatePlayer_Script_1

YouCantStopMe_LocatePlayer_Script_6:
	applymovement 1, YouCantStopMe_WalkToPlayerY8
	goto YouCantStopMe_LocatePlayer_Script_1


YouCantStopMe_LastChance_Dialogue::
	lock
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_Wait
	callnative ClearMugshot
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	call YouCantStopMe_LocatePlayer_Script
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_PleaseItIsntToo
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_PeopleOnDied
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_YesItsUnforuntate
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_DoYouReally
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_IKnowYouWant
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_LookAtTheJobs
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_WeveWorkedVeryHard
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_EverybodyDeservesAGoodLife
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_DotDotDot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_TheyreNotMurderers
	setvar VAR_0x8000, MUGSHOT_LANCE
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_DotDotDot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_IThoughtSo
	closemessage
	callnative ClearMugshot
	applymovement 1, YouCantStopMe_LeaveFloor
	waitmovement 1
	playse SE_EXIT
	waitse
	removeobject 1
	addvar VAR_TOWER_RAID_STATE, 1
	release
	end


YouCantStopMe_Confront_Dialogue::
	playbgm MUS_RG_ENCOUNTER_DEOXYS, TRUE
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_WhatDoYouWant, MSGBOX_NPC
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_OneMassCasualty
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_HahIThinkMass
	callnative ClearMugshot
	closemessage
	applymovement 2, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_DidYouEverCare
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_ImNotJustifying
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_YouReallyDontGive
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_NopeIDoWish
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_JustAGlorified
	callnative ClearMugshot
	closemessage
	addvar VAR_TOWER_RAID_STATE, 1
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_ne YouCantStopMe_Confront_Dialogue_2
	compare VAR_TEMP_1, 5
	goto_if_ne YouCantStopMe_Confront_Dialogue_2
YouCantStopMe_Confront_Dialogue_1:
	applymovement 2, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, YouCantStopMe_WalkBackwards
	waitmovement 2
	waitmovement OBJ_EVENT_ID_PLAYER
	call Common_EventScript_SaveGame
	closemessage
	goto YouCantStopMe_StartBossBattle_Script
	return

YouCantStopMe_Confront_Dialogue_2:
	fadescreen FADE_TO_BLACK
	applymovement 2, Common_Movement_FaceDown
	waitmovement 2
	setobjectxy 2, 15, 4
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setobjectxy OBJ_EVENT_ID_PLAYER, 15, 5
	TeleportCamera 15, 5
	fadescreen FADE_FROM_BLACK
	goto YouCantStopMe_Confront_Dialogue_1


YouCantStopMe_StartBossBattle_Script::
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_YouCantStopMe_YouWere, MSGBOX_NPC
	closemessage
	callnative ClearMugshot
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, gText_YouCantStopMe_WowGuessWeShould
	goto WeCanStopYouActually_PostBattle_Dialogue
	return


YouCantStopMe_WalkToPlayerY5:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

YouCantStopMe_WalkToPlayerY6:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

YouCantStopMe_WalkToPlayerY7:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

YouCantStopMe_WalkToPlayerY8:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

YouCantStopMe_LeaveFloor:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YouCantStopMe_WalkBackwards:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

gText_YouCantStopMe_Wait::
	.string "{PLAYER}! Wait!$"

gText_YouCantStopMe_PleaseItIsntToo::
	.string "Please! It isn’t too late to fix things.$"

gText_YouCantStopMe_PeopleOnDied::
	.string "People on Alameda died, Oak! We can’t fix\n"
	.string "that.$"

gText_YouCantStopMe_YesItsUnforuntate::
	.string "*sigh* Yes, it's unfortunate that there\n"
	.string "was some collateral damage, but it’s for\l"
	.string "the better! The region will be better!\l"
	.string "We’re going to usher in a new age!$"

gText_YouCantStopMe_DoYouReally::
	.string "Do you all really think you did the right\n"
	.string "thing? Don’t you get that this is\l"
	.string "insane?!$"

gText_YouCantStopMe_IKnowYouWant::
	.string "I know you want to help people. But we\n"
	.string "are too! Look at the jobs we create -$"

gText_YouCantStopMe_LookAtTheJobs::
	.string "Look at the jobs you’ve destroyed! The\n"
	.string "families! Careers! While you watch from\l"
	.string "your towers and skyboxes, I was out\l"
	.string "there with people. You have no idea how\l"
	.string "they live.$"

gText_YouCantStopMe_WeveWorkedVeryHard::
	.string "We’ve worked very hard to get where we\n"
	.string "are. We’ve earned every penny and we\l"
	.string "deserve to have a good life!$"

gText_YouCantStopMe_EverybodyDeservesAGoodLife::
	.string "Everybody deserves a good life. But\n"
	.string "since you weren’t aware - the people\l"
	.string "I’ve met in SanFran are hard-working.\l"
	.string "And suffering. Because of things you\l"
	.string "did. You’re all hurting people! All to\l"
	.string "pump some stats and make more money\l"
	.string "that you don’t even need! What makes\l"
	.string "you more deserving than them?$"

gText_YouCantStopMe_TheyreNotMurderers::
	.string "They’re not murderers. You are. I just\n"
	.string "beat everybody on the way up here,\l"
	.string "including Bianca. I don’t want to hurt\l"
	.string "you too.$"

gText_YouCantStopMe_DotDotDot::
	.string "…$"

gText_YouCantStopMe_IThoughtSo::
	.string "I thought so.$"

gText_YouCantStopMe_WhatDoYouWant::
	.string "*sigh* What do you want? We’re busy!$"

gText_YouCantStopMe_OneMassCasualty::
	.string "One mass casualty event wasn’t\n"
	.string "enough?! Ruining a region!? Becoming a\l"
	.string "multi-billionaire? What else do you\l"
	.string "want?$"

gText_YouCantStopMe_HahIThinkMass::
	.string "Hah! I think mass casualty is a little\n"
	.string "dramatic, don’t you think? A few people\l"
	.string "died. They shouldn’t have aligned\l"
	.string "themselves with terrorists. They were\l"
	.string "getting in the way of shareholder\l"
	.string "profits, which is why I have work to do,\l"
	.string "actually…$"

gText_YouCantStopMe_DidYouEverCare::
	.string "Did you ever care about any of this?$"

gText_YouCantStopMe_ImNotJustifying::
	.string "I’m not justifying myself to some kid,\n"
	.string "and I don’t need to either.$"

gText_YouCantStopMe_YouReallyDontGive::
	.string "You really don’t give a shit.$"

gText_YouCantStopMe_NopeIDoWish::
	.string "Nope! I do wish you had just played your\n"
	.string "role though. Bianca isn’t as… charming\l"
	.string "as you, so we’ve gotta keep them behind\l"
	.string "the scenes, you know? Gotta find a new\l"
	.string "kid, I guess.$"

gText_YouCantStopMe_JustAGlorified::
	.string "I was just a glorified PR puppet for\n"
	.string "you?!$"

gText_YouCantStopMe_YouWere::
	.string "You were. Now you’re annoying. Soon to\n"
	.string "be dead.$"

gText_YouCantStopMe_WowGuessWeShould::
	.string "Wow! Guess we should have taken you\n"
	.string "out sooner, huh?$"
