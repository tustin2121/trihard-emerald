FortreeCity_House7_MapScripts::
	.byte 0

FortreeCity_House7_EventScript_Boy::
	msgbox FortreeCity_House7_Text_Boy, MSGBOX_NPC
	end
FortreeCity_House7_Text_Boy:
	.string "I was really excited when we first\n"
	.string "moved here. Living in a tree city!\l"
	.string "How awesome is that?!\p"
	.string "But then the first thunderstorm rolled\n"
	.string "through, and it's really scary living\l"
	.string "so high up in the air!$"


FortreeCity_House7_EventScript_StealSpot::
	lock
	msgbox FortreeCity_House7_Text_StealSpot, MSGBOX_DEFAULT
	trysteal_money 1500, FLAG_ITEM_STOLEN_FORTREE_HOUSE
	release
	end
FortreeCity_House7_Text_StealSpot:
	.string "You peak inside the sock drawer…\p"
	.string "People really shouldn't stash\n"
	.string "savings away in places like this.$"
