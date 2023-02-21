YouCantStopMe_HideObject_Script::
	setflag FLAG_TEMP_1
	setflag FLAG_TEMP_2
	return


YouCantStopMe_MoveObject_Script::
	call YouCantStopMe_HideObject_Script
	setobjectxy 4, 15, 5
	setobjectxyperm 4, 15, 5
	setobjectnewmovementtype 4, MOVEMENT_TYPE_FACE_DOWN
	return


YouCantStopMe_ObjectCleanUp_Script::
	call YouCantStopMe_HideObject_Script
	setflag FLAG_TEMP_3
	return


YouCantStopMe_MoveOakPlayer_Script::
	clearflag FLAG_TEMP_1
	playse SE_EXIT
	waitse
	addobject 1
	applymovement 1, Common_Movement_WalkDown
	fadescreen FADE_TO_BLACK
	applymovement 1, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	delay 30
	setobjectxy 1, 5, 7
	setobjectxy OBJ_EVENT_ID_PLAYER, 6, 7
	TeleportCamera 6, 7
	fadescreen FADE_FROM_BLACK
	return


YouCantStopMe_LastChance_Dialogue::
	lock
	msgbox gText_YouCantStopMe_Wait, , SPEAKER_OAK
	closemessage
	call YouCantStopMe_MoveOakPlayer_Script
	msgbox gText_YouCantStopMe_PleaseItIsntToo, , SPEAKER_OAK
	msgbox gText_YouCantStopMe_PeopleOnDied, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_YesItsUnforuntate, , SPEAKER_OAK
	msgbox gText_YouCantStopMe_DoYouReally, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_IKnowYouWant, , SPEAKER_OAK
	msgbox gText_YouCantStopMe_LookAtTheJobs, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_WeveWorkedVeryHard, , SPEAKER_OAK
	msgbox gText_YouCantStopMe_EverybodyDeservesAGoodLife, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_DotDotDot, , SPEAKER_OAK
	msgbox gText_YouCantStopMe_TheyreNotMurderers, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_DotDotDot, , SPEAKER_OAK
	msgbox gText_YouCantStopMe_IThoughtSo, , SPEAKER_ZOEY
	closemessage
	applymovement 1, YouCantStopMe_LeaveFloor_Movement
	waitmovement 1
	playse SE_EXIT
	waitse
	removeobject 1
	setvar VAR_TOWER_RAID_STATE, STOPPED_BY_OAK
	release
	end


YouCantStopMe_Confront_Dialogue::
	lock
	playbgm MUS_RG_ENCOUNTER_DEOXYS, TRUE
	msgbox gText_YouCantStopMe_WhatDoYouWant, MSGBOX_NPC, SPEAKER_ROSE
	msgbox gText_YouCantStopMe_OneMassCasualty, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_HahIThinkMass, , SPEAKER_ROSE
	closemessage
	applymovement 4, Common_Movement_FaceUp
	msgbox gText_YouCantStopMe_DidYouEverCare, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_ImNotJustifying, , SPEAKER_ROSE
	msgbox gText_YouCantStopMe_YouReallyDontGive, , SPEAKER_ZOEY
	msgbox gText_YouCantStopMe_NopeIDoWish, , SPEAKER_ROSE
	msgbox gText_YouCantStopMe_JustAGlorified, , SPEAKER_ZOEY
	closemessage
	setvar VAR_TOWER_RAID_STATE, SAVE_ROSE_SALESFORCETOWER
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	compare VAR_TEMP_0, 15
	goto_if_ne YouCantStopMe_Confront_Dialogue_2
	compare VAR_TEMP_1, 5
	goto_if_ne YouCantStopMe_Confront_Dialogue_2
YouCantStopMe_Confront_Dialogue_1:
	applymovement 4, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, YouCantStopMe_WalkBackwards_Movement
	waitmovement 4
	waitmovement OBJ_EVENT_ID_PLAYER
	call Common_EventScript_SaveGame
	closemessage
	goto YouCantStopMe_StartBossBattle_Script
	return

YouCantStopMe_Confront_Dialogue_2:
	fadescreen FADE_TO_BLACK
	delay 30
	applymovement 4, Common_Movement_FaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setobjectxy 4, 15, 4
	setobjectxy OBJ_EVENT_ID_PLAYER, 15, 5
	TeleportCamera 15, 5
	fadescreen FADE_FROM_BLACK
	goto YouCantStopMe_Confront_Dialogue_1


YouCantStopMe_StartBossBattle_Script::
	msgbox gText_YouCantStopMe_YouWere, MSGBOX_NPC, SPEAKER_ROSE
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, gText_YouCantStopMe_WowGuessWeShould
	goto WeCanStopYouActually_PostBattle_Dialogue
	return


YouCantStopMe_LeaveFloor_Movement:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

YouCantStopMe_WalkBackwards_Movement:
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
	.string "*sigh* What do you want? I'm working on an\n"
	.string "important email.$"

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
