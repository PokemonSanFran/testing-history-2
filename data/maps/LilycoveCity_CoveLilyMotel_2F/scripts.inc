LilycoveCity_CoveLilyMotel_2F_MapScripts:: @ 82186D2
	.byte 0

lilycovecity_covelilymotel_2f_eventscript_gamedesigner:: @ 82186d3
	lock
	faceplayer
	call_if_unset flag_temp_2, lilycovecity_covelilymotel_2f_eventscript_showmecompleteddex
	call_if_set flag_temp_2, lilycovecity_covelilymotel_2f_eventscript_showdiploma
	specialvar var_result, hasallhoennmons
	compare var_result, true
	goto_if_eq lilycovecity_covelilymotel_2f_eventscript_allhoennmonsfanfare
	release
	end

lilycovecity_covelilymotel_2f_eventscript_showmecompleteddex:: @ 82186f9
	msgbox lilycovecity_covelilymotel_2f_text_showmecompleteddex, msgbox_default
	return

lilycovecity_covelilymotel_2f_eventscript_allhoennmonsfanfare:: @ 8218702
	setflag flag_temp_2
	playfanfare mus_obtain_item
	waitfanfare
	goto lilycovecity_covelilymotel_2f_eventscript_showdiploma
	end

lilycovecity_covelilymotel_2f_eventscript_showdiploma:: @ 821870f
	message lilycovecity_covelilymotel_2f_text_filledpokedexgiveyouthis
	waitmessage
	call common_eventscript_playgymbadgefanfare
	special special_showdiploma
	waitstate
	release
	end

lilycovecity_covelilymotel_2f_eventscript_programmer:: @ 8218720
	msgbox lilycovecity_covelilymotel_2f_text_imtheprogrammer, msgbox_npc
	end

lilycovecity_covelilymotel_2f_eventscript_graphicartist:: @ 8218729
	msgbox lilycovecity_covelilymotel_2f_text_imthegraphicartist, msgbox_npc
	end

lilycovecity_covelilymotel_2f_eventscript_fatman:: @ 8218732
	msgbox lilycovecity_covelilymotel_2f_text_girlsarecute, msgbox_npc
	end

lilycovecity_covelilymotel_2f_eventscript_woman:: @ 821873b
	msgbox lilycovecity_covelilymotel_2f_text_seabreezeticklesheart, msgbox_npc
	end

lilycovecity_covelilymotel_2f_eventscript_gameboykid:: @ 8218744
	msgbox lilycovecity_covelilymotel_2f_text_neverleavewithoutgameboy, msgbox_npc
	end

lilycovecity_covelilymotel_2f_eventscript_scott:: @ 821874d
	lock
	faceplayer
	goto_if_set flag_met_scott_in_lilycove, lilycovecity_covelilymotel_2f_eventscript_metscott
	msgbox lilycovecity_covelilymotel_2f_text_snoozingpreferbattles, msgbox_default
	addvar var_scott_state, 1
	setflag flag_met_scott_in_lilycove
	release
	end

lilycovecity_covelilymotel_2f_eventscript_metscott:: @ 821876a
	msgbox lilycovecity_covelilymotel_2f_text_contestsdotakestrategy, msgbox_default
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex: @ 8218774
	.string "I'm the Game Designer.\p"
	.string "Oh, is that right?\n"
	.string "You're working on a Pokédex?\p"
	.string "It's tough trying to complete it,\n"
	.string "but don't give up.\p"
	.string "If you do complete it, please come\n"
	.string "show me.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis: @ 821881C
	.string "Wow! That's awesome!\n"
	.string "Yep, it's totally awesome!\p"
	.string "This Pokédex is completely filled!\n"
	.string "You really must love Pokémon!\p"
	.string "I'm so impressed!\p"
	.string "Let me give you something in\n"
	.string "recognition of your feat!$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer: @ 82188D6
	.string "Me? You're talking to me?\n"
	.string "I'm the Programmer.\p"
	.string "I wonder what the Slots are\n"
	.string "like here.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist: @ 821892B
	.string "I'm the Graphic Artist! Aren't the\n"
	.string "Pokémon of Hoenn interesting?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute: @ 821896C
	.string "The girl Tubers, they're cute, hey?\n"
	.string "To battle against a cute Tuber…\p"
	.string "Whoop, it's so awesome!\p"
	.string "And the Twins! Aren't they cute?\n"
	.string "A 2-on-2 battle with Twins…\p"
	.string "Whoop, it's unbearably fun!$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart: @ 8218A21
	.string "The sea breeze tickles my heart.\n"
	.string "It feels wonderful here!$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy: @ 8218A5B
	.string "You never know when and where\n"
	.string "people will challenge you.\p"
	.string "That's why I never leave home without\n"
	.string "my Game Boy Advance.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles: @ 8218ACF
	.string "Scott: … … … … …\n"
	.string "… … … … … Zzz…\p"
	.string "… … … … … Huh?!\n"
	.string "Oh, sorry, sorry! I was snoozing!\p"
	.string "I came to check out this Pokémon\n"
	.string "Contest thing.\p"
	.string "I have to admit, it does look quite\n"
	.string "entertaining, but…\p"
	.string "Consider me a purist--I prefer\n"
	.string "battles and tough Trainers.\p"
	.string "But that's just me.\p"
	.string "{PLAYER}{KUN}, I hope you'll enjoy everything\n"
	.string "like the Gyms, Contests, Battle Tent,\l"
	.string "the whole works!$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy: @ 8218C33
	.string "Scott: I think it does take strategy\n"
	.string "to win a Contest.\p"
	.string "Devising Contest strategies is one way\n"
	.string "of becoming a better Trainer, I'd say.$"

