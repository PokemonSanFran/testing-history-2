Salesforcetower_1F_MapScripts::
	.byte 0


Salesforcetower_BlockedStairs_Dialogue::
	lockall
	msgbox SalesforcetowerElevator_BlockedStairs_Text1, MSGBOX_NPC
	closemessage
	releaseall
	end


SalesforcetowerElevator_BlockedStairs_Text1::
	.string "Sorry, this floor is employees only.$"
