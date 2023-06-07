Hiddengrotto_EnterGrotto_Dialogue::
	lock
	special HiddenGrotto_LoadDiscoveredGrottoText
	msgbox gText_Hiddengrottomapping_Blank, MSGBOX_YESNO, SPEAKER_ZOEY, TAIL_THOUGHT, EMOTE_CONFUSE
	compare VAR_RESULT, YES
	goto_if_eq Hiddengrotto_EnterGrotto_Dialogue_2
Hiddengrotto_EnterGrotto_Dialogue_1:
	release
	end

Hiddengrotto_EnterGrotto_Dialogue_2:
	special HiddenGrotto_LoadGrottoAndWarpPlayer
	goto Hiddengrotto_EnterGrotto_Dialogue_1


gText_Hiddengrottomapping_Blank::
	.string "{STR_VAR_1}$"

gText_Hiddengrottomapping_LookYouveFound::
	.string "Look!\n"
	.string "You've found a narrow path!\p"
	.string "Will you follow it?$"

gText_LookIveFound::
	.string "Look! I've found a narrow path! Should I\n"
	.string "follow it?$"

gText_WowHiddenPath::
	.string "Wow! A hidden path! Shall I venture\n"
	.string "forth?$"

gText_OhWhatsThis::
	.string "Oh, what's this? A secret passage!\n"
	.string "Should I explore it?$"

gText_AmazingHiddenTrail::
	.string "Amazing! A hidden trail! Do I dare to\n"
	.string "investigate it?$"

gText_HmmConcealedPath::
	.string "Hmm, a concealed path. Should I find out\n"
	.string "where it leads?$"

gText_MysteriousRoute::
	.string "A mysterious route revealed! Should I\n"
	.string "brave its unknown depths?$"

gText_OhMyConcealedGrotto::
	.string "Oh my, a concealed grotto! Should I\n"
	.string "satisfy my curiosity and enter?$"

gText_IntriguingSecretPassage::
	.string "Intriguing! A secret passage\n"
	.string "discovered! Should I follow it and see\l"
	.string "what lies ahead?$"

gText_WhoaHiddenEntrance::
	.string "Whoa, a hidden entrance! Should I take\n"
	.string "the plunge and see where it leads?$"

gText_HiddenTrailEmerges::
	.string "A hidden trail emerges! Should I\n"
	.string "succumb to the allure of the unknown?$"

gText_OhWhatDoWeHave::
	.string "Oh, what do we have here? A covert path\n"
	.string "beckons me. Should I explore it?$"

gText_ConcealedPathwayAppears::
	.string "A concealed pathway appears! Do I feel\n"
	.string "the excitement building?$"

gText_MyCuriosityPiqued::
	.string "My curiosity is piqued! A hidden grotto\n"
	.string "stands before me. Should I step\l"
	.string "inside?$"

gText_LookClandestinePassage::
	.string "Look! A clandestine passage! Can I\n"
	.string "resist the chance to uncover its\l"
	.string "secrets?$"

gText_OhSecretRoute::
	.string "Oh, a secret route revealed! Can I\n"
	.string "resist the call of adventure?$"

gText_HmmObscuredPath::
	.string "Hmm, an obscured path. Does the thrill\n"
	.string "of the unknown compel me to follow it?$"

gText_ConcealedEntranceDiscovered::
	.string "A concealed entrance discovered! Can I\n"
	.string "resist the temptation to enter?$"

gText_WhatsThisCovertPathway::
	.string "What's this? A covert pathway opens up!\n"
	.string "Can I wait to see what awaits me?$"

gText_IntriguingHiddenTrail::
	.string "Intriguing! A hidden trail unraveled!\n"
	.string "Can I seize this opportunity to\l"
	.string "explore?$"

gText_HiddenGrottoMaterializes::
	.string "A hidden grotto materializes! Do I\n"
	.string "sense a thrilling journey ahead?$"
