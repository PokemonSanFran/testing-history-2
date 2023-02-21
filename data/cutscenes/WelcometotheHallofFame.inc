WelcomeToTheHallOfFame_PostBattle_Dialogue::
	msgbox gText_WelcomeToTheHallOfFame_YourChampion
	closemessage
	special DoDomeConfetti
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
	clearflag FLAG_TEMP_1
	addobject 2
	applymovement 2, WelcomeToTheHallOfFame_MoveRoseToPodium
	applymovement 1, WelcomeToTheHallOfFame_WalkOutOfWay
	waitmovement 2
	msgbox gText_WelcomeToTheHallOfFame_ToTheHundreds, , SPEAKER_ROSE
	closemessage
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	fadescreen FADE_TO_BLACK
	setobjectxy OBJ_EVENT_ID_PLAYER, 9, 6
	setobjectxy 1, 8, 7
	setobjectxy 2, 7, 7
	turnobject 1, DIR_SOUTH
	turnobject 2, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	TeleportCamera 9, 6
	fadescreen FADE_FROM_BLACK
	msgbox gText_WelcomeToTheHallOfFame_AndNowLetsCreate, , SPEAKER_ROSE
	closemessage
	setvar VAR_CHASECENTER_TOURNAMENT_STATE, NO_TOURNAMENT
	clearflag FLAG_CHASECENTER_TOURNAMENT_HAPPENING
	setvar VAR_STORYLINE_STATE, STORY_WON_FINALS
	setflag FLAG_IS_CHAMPION
	fadescreenspeed FADE_TO_BLACK, 24
	special HealPlayerParty
	call WelcometotheHallofFame_GameClear_Script
	waitstate
	releaseall
	end


WelcometotheHallofFame_GameClear_Script::
	special GameClear
	return


WelcomeToTheHallOfFame_MoveRoseToPodium:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

WelcomeToTheHallOfFame_WalkOutOfWay:
	walk_right
	walk_up
	face_down
	step_end

gText_WelcomeToTheHallOfFame_YourChampion::
	.string "SanFran! Your Champion! {PLAYER}!$"

gText_WelcomeToTheHallOfFame_ToTheHundreds::
	.string "To the hundreds of you, here, in the\n"
	.string "stands. To the millions of you,\l"
	.string "watching from all over the world. To all\l"
	.string "the fans. We say “Thank you, from the\l"
	.string "bottom of our hearts”. This first\l"
	.string "season was absolutely a success, and\l"
	.string "we can't wait to do it again.$"

gText_WelcomeToTheHallOfFame_AndNowLetsCreate::
	.string "And now, let's create history together.\n"
	.string "I am proud to present the first\l"
	.string "inductee to the Ycombinator Hall of\l"
	.string "Fame. Psfregion's Champion:\l"
	.string "{PLAYER}.$"
