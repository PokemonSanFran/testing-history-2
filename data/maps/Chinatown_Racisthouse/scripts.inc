Chinatown_Racisthouse_MapScripts::
	.byte 0


Chinatown_Racisthouse_Scroll_Script::
	lock
	switch VAR_QUEST_CHINATOWN_TUNNELS
	case 2, Chinatown_Racisthouse_Scroll_Script_3
	case 3, Chinatown_Racisthouse_Scroll_Script_4
	case 4, Chinatown_Racisthouse_Scroll_Script_5
	call Chinatown_Racisthouse_ScrollNoWarp_Dialogue
Chinatown_Racisthouse_Scroll_Script_1:
	release
	end

Chinatown_Racisthouse_Scroll_Script_3:
	goto Quest_ChinatownTunnels_FirstScrollWarp_Script
	goto Chinatown_Racisthouse_Scroll_Script_1

Chinatown_Racisthouse_Scroll_Script_4:
	goto Chinatown_Racisthouse_ScrollWarp_Script
	goto Chinatown_Racisthouse_Scroll_Script_1

Chinatown_Racisthouse_Scroll_Script_5:
	goto Chinatown_Racisthouse_ScrollWarp_Script
	goto Chinatown_Racisthouse_Scroll_Script_1


Chinatown_Racisthouse_ScrollWarp_Script::
	lock
	playse SE_EXIT
	warpsilent MAP_CHINATOWN_TUNNEL, 1
	release
	end


Chinatown_Racisthouse_ScrollNoWarp_Dialogue::
	msgbox gText_Chinatown_Racisthouse_ScrollDesc, MSGBOX_SIGN
	return


gText_Chinatown_Racisthouse_ScrollDesc::
	.string "There is a beautiful red scroll hanging\n"
	.string "on the wall.$"
