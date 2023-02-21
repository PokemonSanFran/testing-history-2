ANewStrike_BreakingNews_Dialogue::
	clearflag FLAG_CONSTRUCTION_BREAKING_NEWS
	lockall
	playse SE_POKENAV_CALL
	waitse
	playse SE_POKENAV_CALL
	msgbox gText_ANewStrike_ConstructionCrew, MSGBOX_DEFAULT, SPEAKER_NEWS, TAIL_DEFAULT, EMOTE_DEFAULT, PHONE_ON
	closemessage
	goto ANewStrike_PlayerSelf_Dialogue
	return


ANewStrike_PlayerSelf_Dialogue::
	msgbox gText_ANewStrike_OhDamn, MSGBOX_DEFAULT, SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_CONFUSE, PHONE_OFF
	closemessage
	releaseall
	end


gText_ANewStrike_ConstructionCrew::
	.string "BREAKING NEWS: Chasecenter\n"
	.string "construction crew has declared\l"
	.string "a strike.\p"
	.string "Their demands at this time are\n"
	.string "unclear, but this puts the\l"
	.string "upcoming dates of the\l"
	.string "YCombinator League\l"
	.string "Championship in danger.\l"
	.string "Anonymous sources claim that\l"
	.string "TeamRocket is responsible for\l"
	.string "instigating this protest, but\l"
	.string "we'll have more information as\l"
	.string "the situation develops.$"

gText_ANewStrike_OhDamn::
	.string "Oh damn. I wonder what they'll do if the\n"
	.string "Championship has to be delayed…$"
