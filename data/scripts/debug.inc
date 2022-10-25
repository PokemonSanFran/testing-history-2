Debug_ShowFieldMessageStringVar4::
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	releaseall
	end


Debug_CheatStart::
	lockall
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_ZIGZAGOON_BATTLE
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_BIRCH
	setflag FLAG_HIDE_ROUTE_101_BIRCH_STARTERS_BAG
	setvar VAR_BIRCH_LAB_STATE, 2
	setvar VAR_ROUTE101_STATE, 3
	givemon SPECIES_TREECKO, 20, ITEM_NONE
	givemon SPECIES_TORCHIC, 20, ITEM_NONE
	givemon SPECIES_MUDKIP, 20, ITEM_NONE
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_CABLE_CLUB_TUTORIAL_STATE, 1
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setvar VAR_LITTLEROOT_HOUSES_STATE_BRENDAN, 2
	setvar VAR_LITTLEROOT_HOUSES_STATE_MAY, 2
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setflag FLAG_RECEIVED_BIKE
	additem ITEM_ACRO_BIKE
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setvar VAR_ROUTE116_STATE, 2
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	closemessage
	release
	end


Debug_FlagsNotSetMessage::
	lockall
	message Debug_FlagsNotSetMessage_Text
	waitmessage
	waitbuttonpress
	releaseall
	end


Debug_Weather::
	setweather WEATHER_FOG_DIAGONAL
	doweather
	return


Debug_Script_1::
	switch VAR_STORYLINE_STATE
	case 1, Debug_Script_1_3
	case 2, Debug_Script_1_4
	case 3, Debug_Script_1_5
	case 4, Debug_Script_1_6
	case 5, Debug_Script_1_7
	case 6, Debug_Script_1_8
	case 7, Debug_Script_1_9
	case 8, Debug_Script_1_10
	case 9, Debug_Script_1_11
	case 10, Debug_Script_1_12
	case 11, Debug_Script_1_13
	case 12, Debug_Script_1_14
	case 13, Debug_Script_1_15
	case 14, Debug_Script_1_16
	case 15, Debug_Script_1_17
	case 16, Debug_Script_1_18
	case 17, Debug_Script_1_19
	case 18, Debug_Script_1_20
	case 19, Debug_Script_1_21
	case 20, Debug_Script_1_22
	case 21, Debug_Script_1_23
	case 22, Debug_Script_1_24
	case 23, Debug_Script_1_25
	case 24, Debug_Script_1_26
	case 25, Debug_Script_1_27
	case 26, Debug_Script_1_28
	case 27, Debug_Script_1_29
	case 28, Debug_Script_1_30
	case 29, Debug_Script_1_31
	case 30, Debug_Script_1_32
	case 31, Debug_Script_1_33
	case 32, Debug_Script_1_34
	case 33, Debug_Script_1_35
	case 34, Debug_Script_1_36
	case 35, Debug_Script_1_37
	case 36, Debug_Script_1_38
	case 37, Debug_Script_1_39
	case 38, Debug_Script_1_40
	case 39, Debug_Script_1_41
	case 40, Debug_Script_1_42
	case 41, Debug_Script_1_43
	case 42, Debug_Script_1_44
	case 43, Debug_Script_1_45
	case 44, Debug_Script_1_46
	case 45, Debug_Script_1_47
	case 46, Debug_Script_1_48
	case 47, Debug_Script_1_49
	case 48, Debug_Script_1_50
	case 49, Debug_Script_1_51
	case 50, Debug_Script_1_52
	case 51, Debug_Script_1_53
	case 52, Debug_Script_1_54
	case 53, Debug_Script_1_55
	case 54, Debug_Script_1_56
	case 55, Debug_Script_1_57
	case 56, Debug_Script_1_58
	case 57, Debug_Script_1_59
	case 58, Debug_Script_1_60
	case 59, Debug_Script_1_61
	case 60, Debug_Script_1_62
	case 61, Debug_Script_1_63
	case 62, Debug_Script_1_64
	case 63, Debug_Script_1_65
	case 64, Debug_Script_1_66
	case 65, Debug_Script_1_67
	case 66, Debug_Script_1_68
	case 67, Debug_Script_1_69
	case 68, Debug_Script_1_70
	case 69, Debug_Script_1_71
	case 70, Debug_Script_1_72
	case 71, Debug_Script_1_73
	case 72, Debug_Script_1_74
Debug_Script_1_1:
	closemessage
	return

Debug_Script_1_3:
	msgbox Debug_Script_1_Text_0
	goto Debug_Script_1_1

Debug_Script_1_4:
	msgbox Debug_Script_1_Text_1
	goto Debug_Script_1_1

Debug_Script_1_5:
	msgbox Debug_Script_1_Text_2
	goto Debug_Script_1_1

Debug_Script_1_6:
	msgbox Debug_Script_1_Text_3
	goto Debug_Script_1_1

Debug_Script_1_7:
	msgbox Debug_Script_1_Text_4
	goto Debug_Script_1_1

Debug_Script_1_8:
	msgbox Debug_Script_1_Text_5
	goto Debug_Script_1_1

Debug_Script_1_9:
	msgbox Debug_Script_1_Text_6
	goto Debug_Script_1_1

Debug_Script_1_10:
	msgbox Debug_Script_1_Text_7
	goto Debug_Script_1_1

Debug_Script_1_11:
	msgbox Debug_Script_1_Text_8
	goto Debug_Script_1_1

Debug_Script_1_12:
	msgbox Debug_Script_1_Text_9
	goto Debug_Script_1_1

Debug_Script_1_13:
	msgbox Debug_Script_1_Text_10
	goto Debug_Script_1_1

Debug_Script_1_14:
	msgbox Debug_Script_1_Text_11
	goto Debug_Script_1_1

Debug_Script_1_15:
	msgbox Debug_Script_1_Text_12
	goto Debug_Script_1_1

Debug_Script_1_16:
	msgbox Debug_Script_1_Text_13
	goto Debug_Script_1_1

Debug_Script_1_17:
	msgbox Debug_Script_1_Text_14
	goto Debug_Script_1_1

Debug_Script_1_18:
	msgbox Debug_Script_1_Text_15
	goto Debug_Script_1_1

Debug_Script_1_19:
	msgbox Debug_Script_1_Text_16
	goto Debug_Script_1_1

Debug_Script_1_20:
	msgbox Debug_Script_1_Text_17
	goto Debug_Script_1_1

Debug_Script_1_21:
	msgbox Debug_Script_1_Text_18
	goto Debug_Script_1_1

Debug_Script_1_22:
	msgbox Debug_Script_1_Text_19
	goto Debug_Script_1_1

Debug_Script_1_23:
	msgbox Debug_Script_1_Text_20
	goto Debug_Script_1_1

Debug_Script_1_24:
	msgbox Debug_Script_1_Text_21
	goto Debug_Script_1_1

Debug_Script_1_25:
	msgbox Debug_Script_1_Text_22
	goto Debug_Script_1_1

Debug_Script_1_26:
	msgbox Debug_Script_1_Text_23
	goto Debug_Script_1_1

Debug_Script_1_27:
	msgbox Debug_Script_1_Text_24
	goto Debug_Script_1_1

Debug_Script_1_28:
	msgbox Debug_Script_1_Text_25
	goto Debug_Script_1_1

Debug_Script_1_29:
	msgbox Debug_Script_1_Text_26
	goto Debug_Script_1_1

Debug_Script_1_30:
	msgbox Debug_Script_1_Text_27
	goto Debug_Script_1_1

Debug_Script_1_31:
	msgbox Debug_Script_1_Text_28
	goto Debug_Script_1_1

Debug_Script_1_32:
	msgbox Debug_Script_1_Text_29
	goto Debug_Script_1_1

Debug_Script_1_33:
	msgbox Debug_Script_1_Text_30
	goto Debug_Script_1_1

Debug_Script_1_34:
	msgbox Debug_Script_1_Text_31
	goto Debug_Script_1_1

Debug_Script_1_35:
	msgbox Debug_Script_1_Text_32
	goto Debug_Script_1_1

Debug_Script_1_36:
	msgbox Debug_Script_1_Text_33
	goto Debug_Script_1_1

Debug_Script_1_37:
	msgbox Debug_Script_1_Text_34
	goto Debug_Script_1_1

Debug_Script_1_38:
	msgbox Debug_Script_1_Text_35
	goto Debug_Script_1_1

Debug_Script_1_39:
	msgbox Debug_Script_1_Text_36
	goto Debug_Script_1_1

Debug_Script_1_40:
	msgbox Debug_Script_1_Text_37
	goto Debug_Script_1_1

Debug_Script_1_41:
	msgbox Debug_Script_1_Text_38
	goto Debug_Script_1_1

Debug_Script_1_42:
	msgbox Debug_Script_1_Text_39
	goto Debug_Script_1_1

Debug_Script_1_43:
	msgbox Debug_Script_1_Text_40
	goto Debug_Script_1_1

Debug_Script_1_44:
	msgbox Debug_Script_1_Text_41
	goto Debug_Script_1_1

Debug_Script_1_45:
	msgbox Debug_Script_1_Text_42
	goto Debug_Script_1_1

Debug_Script_1_46:
	msgbox Debug_Script_1_Text_43
	goto Debug_Script_1_1

Debug_Script_1_47:
	msgbox Debug_Script_1_Text_44
	goto Debug_Script_1_1

Debug_Script_1_48:
	msgbox Debug_Script_1_Text_45
	goto Debug_Script_1_1

Debug_Script_1_49:
	msgbox Debug_Script_1_Text_46
	goto Debug_Script_1_1

Debug_Script_1_50:
	msgbox Debug_Script_1_Text_47
	goto Debug_Script_1_1

Debug_Script_1_51:
	msgbox Debug_Script_1_Text_48
	goto Debug_Script_1_1

Debug_Script_1_52:
	msgbox Debug_Script_1_Text_49
	goto Debug_Script_1_1

Debug_Script_1_53:
	msgbox Debug_Script_1_Text_50
	goto Debug_Script_1_1

Debug_Script_1_54:
	msgbox Debug_Script_1_Text_51
	goto Debug_Script_1_1

Debug_Script_1_55:
	msgbox Debug_Script_1_Text_52
	goto Debug_Script_1_1

Debug_Script_1_56:
	msgbox Debug_Script_1_Text_53
	goto Debug_Script_1_1

Debug_Script_1_57:
	msgbox Debug_Script_1_Text_54
	goto Debug_Script_1_1

Debug_Script_1_58:
	msgbox Debug_Script_1_Text_55
	goto Debug_Script_1_1

Debug_Script_1_59:
	msgbox Debug_Script_1_Text_56
	goto Debug_Script_1_1

Debug_Script_1_60:
	msgbox Debug_Script_1_Text_57
	goto Debug_Script_1_1

Debug_Script_1_61:
	msgbox Debug_Script_1_Text_58
	goto Debug_Script_1_1

Debug_Script_1_62:
	msgbox Debug_Script_1_Text_59
	goto Debug_Script_1_1

Debug_Script_1_63:
	msgbox Debug_Script_1_Text_60
	goto Debug_Script_1_1

Debug_Script_1_64:
	msgbox Debug_Script_1_Text_61
	goto Debug_Script_1_1

Debug_Script_1_65:
	msgbox Debug_Script_1_Text_62
	goto Debug_Script_1_1

Debug_Script_1_66:
	msgbox Debug_Script_1_Text_63
	goto Debug_Script_1_1

Debug_Script_1_67:
	msgbox Debug_Script_1_Text_64
	goto Debug_Script_1_1

Debug_Script_1_68:
	msgbox Debug_Script_1_Text_65
	goto Debug_Script_1_1

Debug_Script_1_69:
	msgbox Debug_Script_1_Text_66
	goto Debug_Script_1_1

Debug_Script_1_70:
	msgbox Debug_Script_1_Text_67
	goto Debug_Script_1_1

Debug_Script_1_71:
	msgbox Debug_Script_1_Text_68
	goto Debug_Script_1_1

Debug_Script_1_72:
	msgbox Debug_Script_1_Text_69
	goto Debug_Script_1_1

Debug_Script_1_73:
	msgbox Debug_Script_1_Text_70
	goto Debug_Script_1_1

Debug_Script_1_74:
	msgbox Debug_Script_1_Text_71
	goto Debug_Script_1_1


Debug_Script_2::
	return


Debug_Script_3::
	return


Debug_Script_4::
	return


Debug_Script_5::
	return


Debug_Script_6::
	end


Debug_Script_7::
	end


Debug_Script_8::
	end


Debug_Script_9::
	end


Debug_Script_10::
	end


Debug_Script_1_Text_0:
	.string "1$"

Debug_Script_1_Text_1:
	.string "2$"

Debug_Script_1_Text_2:
	.string "3$"

Debug_Script_1_Text_3:
	.string "4$"

Debug_Script_1_Text_4:
	.string "5$"

Debug_Script_1_Text_5:
	.string "6$"

Debug_Script_1_Text_6:
	.string "7$"

Debug_Script_1_Text_7:
	.string "8$"

Debug_Script_1_Text_8:
	.string "9$"

Debug_Script_1_Text_9:
	.string "10$"

Debug_Script_1_Text_10:
	.string "11$"

Debug_Script_1_Text_11:
	.string "12$"

Debug_Script_1_Text_12:
	.string "13$"

Debug_Script_1_Text_13:
	.string "14$"

Debug_Script_1_Text_14:
	.string "15$"

Debug_Script_1_Text_15:
	.string "16$"

Debug_Script_1_Text_16:
	.string "17$"

Debug_Script_1_Text_17:
	.string "18$"

Debug_Script_1_Text_18:
	.string "19$"

Debug_Script_1_Text_19:
	.string "20$"

Debug_Script_1_Text_20:
	.string "21$"

Debug_Script_1_Text_21:
	.string "22$"

Debug_Script_1_Text_22:
	.string "23$"

Debug_Script_1_Text_23:
	.string "24$"

Debug_Script_1_Text_24:
	.string "25$"

Debug_Script_1_Text_25:
	.string "26$"

Debug_Script_1_Text_26:
	.string "27$"

Debug_Script_1_Text_27:
	.string "28$"

Debug_Script_1_Text_28:
	.string "29$"

Debug_Script_1_Text_29:
	.string "30$"

Debug_Script_1_Text_30:
	.string "31$"

Debug_Script_1_Text_31:
	.string "32$"

Debug_Script_1_Text_32:
	.string "33$"

Debug_Script_1_Text_33:
	.string "34$"

Debug_Script_1_Text_34:
	.string "35$"

Debug_Script_1_Text_35:
	.string "36$"

Debug_Script_1_Text_36:
	.string "37$"

Debug_Script_1_Text_37:
	.string "38$"

Debug_Script_1_Text_38:
	.string "39$"

Debug_Script_1_Text_39:
	.string "40$"

Debug_Script_1_Text_40:
	.string "41$"

Debug_Script_1_Text_41:
	.string "42$"

Debug_Script_1_Text_42:
	.string "43$"

Debug_Script_1_Text_43:
	.string "44$"

Debug_Script_1_Text_44:
	.string "45$"

Debug_Script_1_Text_45:
	.string "46$"

Debug_Script_1_Text_46:
	.string "47$"

Debug_Script_1_Text_47:
	.string "48$"

Debug_Script_1_Text_48:
	.string "49$"

Debug_Script_1_Text_49:
	.string "50$"

Debug_Script_1_Text_50:
	.string "51$"

Debug_Script_1_Text_51:
	.string "52$"

Debug_Script_1_Text_52:
	.string "53$"

Debug_Script_1_Text_53:
	.string "54$"

Debug_Script_1_Text_54:
	.string "55$"

Debug_Script_1_Text_55:
	.string "56$"

Debug_Script_1_Text_56:
	.string "57$"

Debug_Script_1_Text_57:
	.string "58$"

Debug_Script_1_Text_58:
	.string "59$"

Debug_Script_1_Text_59:
	.string "60$"

Debug_Script_1_Text_60:
	.string "61$"

Debug_Script_1_Text_61:
	.string "62$"

Debug_Script_1_Text_62:
	.string "63$"

Debug_Script_1_Text_63:
	.string "64$"

Debug_Script_1_Text_64:
	.string "65$"

Debug_Script_1_Text_65:
	.string "66$"

Debug_Script_1_Text_66:
	.string "67$"

Debug_Script_1_Text_67:
	.string "68$"

Debug_Script_1_Text_68:
	.string "69$"

Debug_Script_1_Text_69:
	.string "70$"

Debug_Script_1_Text_70:
	.string "71$"

Debug_Script_1_Text_71:
	.string "72$"

Debug_CheckWeekDay_Text::
	.string "Aaaah, yes!\l"
	.string "{STR_VAR_1}s are made for dads!\l"
	.string "And dad's car!$"

Debug_FlagsNotSetMessage_Text::
	.string "feature unavailable$"
