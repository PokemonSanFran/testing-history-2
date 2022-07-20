ANewStrike_BreakingNews_Dialogue::
	clearflag FLAG_CONSTRUCTION_BREAKING_NEWS
	lockall
	pokenavcall gText_ANewStrike_ConstructionCrew
	waitmessage
	closemessage
	goto ANewStrike_PlayerSelf_Dialogue
	return


ANewStrike_PlayerSelf_Dialogue::
	setvar VAR_0x8000, MUGSHOT_HILDA
	callnative DrawMugshot
	msgbox gText_ANewStrike_OhDamn
	closemessage
	callnative ClearMugshot
	releaseall
	end


gText_ANewStrike_ConstructionCrew::
	.string "BREAKING NEWS: Chasecenter\n"
	.string "construction crew has declared\l"
	.string "a strike.\p"
	.string "Their demands at this time are\n"
	.string "unclear, but this puts the\l"
	.string "upcoming dates of the Psfbadguy\l"
	.string "League Championship in danger.\l"
	.string "Anonymous sources claim that\l"
	.string "TeamRocket is responsible for\l"
	.string "instigating this protest, but\l"
	.string "we'll have more information as\l"
	.string "the situation develops.$"

gText_ANewStrike_OhDamn::
	.string "Oh damn. I wonder what they'll do if the\n"
	.string "Championship has to be delayed…$"
