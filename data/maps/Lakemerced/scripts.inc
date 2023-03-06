Lakemerced_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Lakemerced_MapScripts_MAP_SCRIPT_ON_TRANSITION
	.byte 0

Lakemerced_MapScripts_MAP_SCRIPT_ON_TRANSITION:
	call Quest_Theboywhocriedwithwolves_Ambrogio_Visibility_Script
	return


Lakemerced_Membersonly_Dialogue::
	questmenu QUEST_MENU_CHECK_COMPLETE, QUEST_BUTONLYINMYBACKYARD
	compare VAR_RESULT, 0
	goto_if_ne Lakemerced_Membersonly_Dialogue_2
	lock
	msgbox gText_Lakemerced_Accessdenied, , SPEAKER_SPEAKER
	msgbox gText_Lakemerced_Firstplacethateven, , SPEAKER_ZOEY, TAIL_THOUGHT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement OBJ_EVENT_ID_PLAYER
	release
	end

Lakemerced_Membersonly_Dialogue_2:
	release
	end


gText_Lakemerced_Accessdenied::
	.string "Access is denied. This area is members\n"
	.string "only.$"

gText_Lakemerced_Firstplacethateven::
	.string "First place that even Ycombinator\n"
	.string "couldn't get me into...$"
