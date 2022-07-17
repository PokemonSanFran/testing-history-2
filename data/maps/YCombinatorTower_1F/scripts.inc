YCombinatorTower_1F_MapScripts::
	.byte 0


YCombinatorTower_BlockedStairs_Dialogue::
	lockall
	msgbox YCombinatorTowerElevator_BlockedStairs_Text1, MSGBOX_NPC
	closemessage
	releaseall
	end


YCombinatorTowerElevator_BlockedStairs_Text1::
	.string "Sorry, this floor is employees only.$"
