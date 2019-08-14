LavaridgeTown_Mart_MapScripts:: @ 81FF9CD
	.byte 0

LavaridgeTown_Mart_EventScript_Lady::
	lock
	faceplayer
	markasdialog
	msgbox LavaridgeTown_Mart_Text_Lady1
	msgbox LavaridgeTown_Mart_Text_Lady2, MSGBOX_CDESCRIBE
	release
	end
LavaridgeTown_Mart_Text_Lady1:
	.string "Ah! Thief! Get out!$"
LavaridgeTown_Mart_Text_Lady2:
	.string "The old lady begins feebly swinging a\n"
	.string "walking stick at you, in an attempt to\l"
	.string "either hit you or conduct your singing.$"

