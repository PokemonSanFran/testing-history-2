WelcomeToTheHallOfFame_PostBattle_Dialogue::
	msgbox gText_WelcomeToTheHallOfFame_YourChampion
	closemessage
	special DoDomeConfetti
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
	clearflag FLAG_TEMP_1
	addobject 2
	applymovement 2, WelcomeToTheHallOfFame_MovePsfbadbossToPodium
	applymovement 1, WelcomeToTheHallOfFame_WalkOutOfWay
	waitmovement 0
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheHallOfFame_ToTheHundreds
	callnative ClearMugshot
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
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheHallOfFame_AndNowLetsCreate
	callnative ClearMugshot
	closemessage
	setvar VAR_ROUTE119_STATE, 0
	clearflag FLAG_PSFPLACE14_TOURNAMENT_HAPPENING
	addvar VAR_STORYLINE_STATE, 1
	fadescreenspeed FADE_TO_BLACK, 24
	special HealPlayerParty
	special GameClear
	waitstate
	releaseall
	end


WelcomeToTheHallOfFame_MovePsfbadbossToPodium:
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
	.string "Psfregion1! Your Champion! {PLAYER}!$"

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
	.string "inductee to the Psfbadguy Hall of\l"
	.string "Fame. Psfregion's Champion:\l"
	.string "{PLAYER}.$"
