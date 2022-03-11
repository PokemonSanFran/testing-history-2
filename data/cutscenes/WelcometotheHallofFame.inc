WelcomeToTheHallOfFame_PostBattle_Dialogue::
	msgbox gText_WelcomeToTheHallOfFame_YourChampion
	closemessage
	special DoDomeConfetti
	playse SE_M_ENCORE2
	call BattleFrontier_BattleDomeBattleRoom_EventScript_AudienceLookAround
	delay 60
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheHallOfFame_ToTheHundreds
	setvar VAR_0x8000, MUGSHOT_GHETSIS
	callnative DrawMugshot
	msgbox gText_WelcomeToTheHallOfFame_AndNowLetsCreate
	return


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
