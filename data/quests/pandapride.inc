Quest_Pandapride_CheckParty_Script::
	setvar VAR_0x8005, SPECIES_PANGORO
	special CheckSpecies
	compare VAR_RESULT, 0
	goto_if_ne Quest_Pandapride_CheckParty_Script_2
Quest_Pandapride_CheckParty_Script_1:
	setvar VAR_0x8005, SPECIES_PANCHAM
	special CheckSpecies
	compare VAR_RESULT, 0
	goto_if_ne Quest_Pandapride_CheckParty_Script_5
Quest_Pandapride_CheckParty_Script_4:
	goto Chinatown_Proudpanda_Shop_Script
	return

Quest_Pandapride_CheckParty_Script_2:
	bufferspeciesname 0, SPECIES_PANGORO
	goto Quest_Pandapride_Congratulations_Dialogue
	goto Quest_Pandapride_CheckParty_Script_1

Quest_Pandapride_CheckParty_Script_5:
	bufferspeciesname 0, SPECIES_PANCHAM
	goto Quest_Pandapride_Congratulations_Dialogue
	goto Quest_Pandapride_CheckParty_Script_4


Quest_Pandapride_Congratulations_Dialogue::
	msgbox gText_Pandapride_YouSawTheAd, , SPEAKER_SHOPKEEPER, TAIL_SHOUT, EMOTE_SHOCK
	msgbox gText_Pandapride_YoureTheOnly, , SPEAKER_SHOPKEEPER, , EMOTE_HAPPY
	giveitem ITEM_TM30
	completequest QUEST_PANDA_PRIDE
	release
	end


gText_Pandapride_YouSawTheAd::
	.string "Your {STR_VAR_1}! You saw the ad! I\n"
	.string "was starting to think nobody had seen\l"
	.string "it!$"

gText_Pandapride_YoureTheOnly::
	.string "You're the only person that followed\n"
	.string "through. I was going to give you a\l"
	.string "discount, but I think this will be more\l"
	.string "useful for you.$"
