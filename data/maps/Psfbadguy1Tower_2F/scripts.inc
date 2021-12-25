Psfbadguy1Tower_2F_MapScripts::
	.byte 0


AlwaysWatchingWazowski_CheckMeeting_Script::
	setvar VAR_PSFBADGUY1TOWER_2F_STATE, 1
	goto AlwaysWatchingWazowski_FloorWelcome_Script
	return


AlwaysWatchingWazowski_FloorWelcome_Script::
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Intro_Text1
	closemessage
	callnative ClearMugshot
	end


AlwaysWatchingWazowski_MovePlayerIntoPlace_Script::
	lockall
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	setvar VAR_PSFBADGUY1TOWER_2F_STATE, 2
	compare VAR_TEMP_0, 7
	goto_if_eq AlwaysWatchingWazowski_MovePlayerIntoPlace_Script_2
	applymovement OBJ_EVENT_ID_PLAYER, Psfchara1DeskWalkFromRight_Movement
AlwaysWatchingWazowski_MovePlayerIntoPlace_Script_1:
	waitmovement 0
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	goto AlwaysWatchingWazowski_Intro_Dialogue
	return

AlwaysWatchingWazowski_MovePlayerIntoPlace_Script_2:
	applymovement OBJ_EVENT_ID_PLAYER, Psfchara1DeskWalkFromLeft_Movement
	goto AlwaysWatchingWazowski_MovePlayerIntoPlace_Script_1


AlwaysWatchingWazowski_Intro_Dialogue::
	setflag FLAG_MEET_PSFBADADMIN3
	playbgm MUS_MT_PYRE, FALSE
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Intro_Text2
	callnative ClearMugshot
	goto AlwaysWatchingWazowski_WishYouHadVisited_Dialogue
	return


AlwaysWatchingWazowski_WishYouHadVisited_Dialogue::
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	compare VAR_PSFCITY15_STATE, 4
	goto_if_eq AlwaysWatchingWazowski_WishYouHadVisited_Dialogue_2
	msgbox gText_AlwaysWatchingWazowski_WishYouHadVisited_Text2
AlwaysWatchingWazowski_WishYouHadVisited_Dialogue_1:
	callnative ClearMugshot
	goto AlwaysWatchingWazowski_HowDidYouKnow_Dialogue
	return

AlwaysWatchingWazowski_WishYouHadVisited_Dialogue_2:
	msgbox gText_AlwaysWatchingWazowski_WishYouHadVisited_Text1
	goto AlwaysWatchingWazowski_WishYouHadVisited_Dialogue_1


AlwaysWatchingWazowski_HowDidYouKnow_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_HowDidYouKnow_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_HowDidYouKnow_Text2
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_HowDidYouKnow_Text3
	callnative ClearMugshot
	goto AlwaysWatchingWazowski_MarketingandProduction_Dialogue
	return


AlwaysWatchingWazowski_MarketingandProduction_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_MarketingandProduction_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_MarketingandProduction_Text2
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_MarketingandProduction_Text3
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_MarketingandProduction_Text4
	callnative ClearMugshot
	closemessage
	goto AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Script
	return


AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	fadescreen FADE_TO_BLACK
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text1
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text2
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text3
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text4
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text5
	callnative ClearMugshot
	compare VAR_NATIVERIVALALPHA_STATE, 0
	goto_if_gt AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Script_2
AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Script_1:
	closemessage
	fadescreen FADE_FROM_BLACK
	goto AlwaysWatchingWazowski_MyProductivityHasDropped_Dialogue
	return

AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Script_2:
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text6
	callnative ClearMugshot
	goto AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Script_1


AlwaysWatchingWazowski_MyProductivityHasDropped_Dialogue::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	setvar VAR_0x8000, MUGSHOT_SABRINA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_MyProductivityHasDropped_Text1
	applymovement 2, Common_Movement_FaceUp
	fadedefaultbgm
	callnative ClearMugshot
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_AlwaysWatchingWazowski_MyProductivityHasDropped_Text2
	callnative ClearMugshot
	waitmovement 0
	closemessage
	releaseall
	end


AlwaysWatchingWazowski_IgnoringPsfchara1_Dialogue::
	lockall
	msgbox gText_AlwaysWatchingWazowski__IgnoringPsfchara1_Text1
	closemessage
	releaseall
	end


Psfchara1DeskWalkFromLeft_Movement:
	walk_right
	face_up
	step_end

Psfchara1DeskWalkFromRight_Movement:
	walk_left
	walk_left
	face_up
	step_end

gText_AlwaysWatchingWazowski_Intro_Text1::
	.string "Welcome {PLAYER}!$"

gText_AlwaysWatchingWazowski_Intro_Text2::
	.string "I imagine all the screens can be quite\n"
	.string "overwhelming. I never really think\l"
	.string "about how many we have until somebody\l"
	.string "new comes to visit.$"

gText_AlwaysWatchingWazowski_WishYouHadVisited_Text1::
	.string "I wish Psfbadadmin1 had picked a\n"
	.string "different time to tell you to come\l"
	.string "visit. I have at least 493 more minutes\l"
	.string "of work, and don't have the 12 minutes\l"
	.string "required to appropriately entertain\l"
	.string "you...$"

gText_AlwaysWatchingWazowski_WishYouHadVisited_Text2::
	.string "I wish you had visited Psfbadboss\n"
	.string "first. I have at least 493 more minutes\l"
	.string "of work and don't have the 12 minutes\l"
	.string "required to appropriately entertain\l"
	.string "you...$"

gText_AlwaysWatchingWazowski_HowDidYouKnow_Text1::
	.string "Wait, how did you know that stuff?$"

gText_AlwaysWatchingWazowski_HowDidYouKnow_Text2::
	.string "Look around. Do you think there's\n"
	.string "anything in the region that I don't\l"
	.string "see?$"

gText_AlwaysWatchingWazowski_HowDidYouKnow_Text3::
	.string "Psfbadguy1 security used to also\n"
	.string "perform surveillance, but my team was\l"
	.string "more than efficient enough to perform\l"
	.string "that on top of their existing duties.$"

gText_AlwaysWatchingWazowski_MarketingandProduction_Text1::
	.string "...oh. Okay. Yeah, there's a lot of\n"
	.string "screens. This is Marketing and\l"
	.string "Production, right?$"

gText_AlwaysWatchingWazowski_MarketingandProduction_Text2::
	.string "We develop content across all of our\n"
	.string "social platforms and optimize the\l"
	.string "perception of our brand to the world.\l"
	.string "Although right now, our primary project\l"
	.string "is actually you.$"

gText_AlwaysWatchingWazowski_MarketingandProduction_Text3::
	.string "What do you mean, me?$"

gText_AlwaysWatchingWazowski_MarketingandProduction_Text4::
	.string "You can see for yourself. Turn to your\n"
	.string "left in 3....2...1....$"

gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text1::
	.string "Our biggest content initiative right\n"
	.string "now is broadcasting the race between\l"
	.string "all the League Challengers. My models\l"
	.string "predict that this will increase our\l"
	.string "sentiment among the professional\l"
	.string "battling community by 40%, and 88%\l"
	.string "among the casual battling communities.\l"
	.string "Never mind what it will do for your\l"
	.string "career.$"

gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text2::
	.string "What do you mean?$"

gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text3::
	.string "Tens of thousands of kids at home\n"
	.string "watching you all right now. Everybody\l"
	.string "loves competition, and even more so,\l"
	.string "they love watching their favorites\l"
	.string "progress. Our inbound sponsorship\l"
	.string "requests have skyrocketed 44.15%\l"
	.string "percent, and the challenge only\l"
	.string "started this morning.$"

gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text4::
	.string "To put it simply, you're all going to be\n"
	.string "superstars.$"

gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text5::
	.string "Historically, our in-region sentiment\n"
	.string "has been primarily negative, but even\l"
	.string "here, people want to see their\l"
	.string "hometown hero do well.$"

gText_AlwaysWatchingWazowski_Psfchara2ProgramCutscene_Text6::
	.string "(Wait, he's doing the League challenge?\n"
	.string "After all that shit talk? What a\l"
	.string "hypocrite!)$"

gText_AlwaysWatchingWazowski_MyProductivityHasDropped_Text1::
	.string "I imagine this has been very\n"
	.string "educational for you, {PLAYER}. But I\l"
	.string "can see my productivity has dropped\l"
	.string "14% as a result of this conversation,\l"
	.string "and I have some content that needs to\l"
	.string "be scheduled very soon.$"

gText_AlwaysWatchingWazowski_MyProductivityHasDropped_Text2::
	.string "Sorry to bug you. I'll keep trying to put\n"
	.string "on a good show!$"

gText_AlwaysWatchingWazowski__IgnoringPsfchara1_Text1::
	.string "...$"
