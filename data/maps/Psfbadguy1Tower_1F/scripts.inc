Psfbadguy1Tower_1F_MapScripts::
	.byte 0


Psfbadguy1Tower_BlockedStairs_Dialogue::
	lockall
	msgbox Psfbadguy1TowerElevator_BlockedStairs_Text1, MSGBOX_NPC
	closemessage
	releaseall
	end


Psfbadguy1TowerElevator_BlockedStairs_Text1::
	.string "Sorry, this floor is employees only.$"
