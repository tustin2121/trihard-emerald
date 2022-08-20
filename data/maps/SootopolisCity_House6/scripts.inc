SootopolisCity_House6_MapScripts:: @ 8226F5B
	map_script MAP_SCRIPT_STEAL_CHECK, Common_EventScript_StealCheck_CheckSingleNPC_NoLeft
	.byte 0

SootopolisCity_House6_EventScript_226F5C:: @ 8226F5C
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_226FA3
	msgbox SootopolisCity_House6_Text_226FC3, MSGBOX_YESNO
	compare VAR_RESULT, 0
	call_if_eq SootopolisCity_House6_EventScript_226F99
	msgbox SootopolisCity_House6_Text_227034, MSGBOX_DEFAULT
	givedecoration_std 117
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_House6_EventScript_226FAD
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end
SootopolisCity_House6_Text_226FC3: @ 8226FC3
	.string "Hello! You're our first guest in\n"
	.string "a good while.\p"
	.string "You've brightened up my day, so I'll\n"
	.string "give you a big WAILMER DOLL.$"
SootopolisCity_House6_Text_227034: @ 8227034
	.string "Take good care of it!$"
SootopolisCity_House6_EventScript_226F99:: @ 8226F99
	msgbox SootopolisCity_House6_Text_22708F, MSGBOX_DEFAULT
	release
	end
SootopolisCity_House6_Text_22708F: @ 822708F
	.string "Are you sure?\n"
	.string "You don't want this DOLL?$"
SootopolisCity_House6_EventScript_226FA3:: @ 8226FA3
	msgbox SootopolisCity_House6_Text_2270B7, MSGBOX_DEFAULT
	release
	end
SootopolisCity_House6_Text_2270B7: @ 82270B7
	.string "I love plush DOLLS!$"
SootopolisCity_House6_EventScript_226FAD:: @ 8226FAD
	bufferdecorationname 1, 117
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_22704A, MSGBOX_DEFAULT
	release
	end
SootopolisCity_House6_Text_22704A: @ 822704A
	.string "Oh, you want it, but not right now?\n"
	.string "Okay, then I'll hold it for you.$"


SootopolisCity_House6_EventScript_StealSpot::
	lock
	setdynamicwarp MAP_SOOTOPOLIS_CITY, 9, 255, 255  @ Spot to get thrown out to
	msgbox SootopolisCity_House6_Text_StealSpot, MSGBOX_DEFAULT
	trysteal ITEM_LIECHI_BERRY, 4, FLAG_DAILY_ITEM_STOLEN_SOOTOPOLIS_BERRY
	release
	end
SootopolisCity_House6_Text_StealSpot:
	.string "Oh, those are pretty berries…!$"


