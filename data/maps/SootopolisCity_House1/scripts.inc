SootopolisCity_House1_MapScripts:: @ 822694C
	map_script MAP_SCRIPT_STEAL_CHECK, Common_EventScript_StealCheck_CheckSingleNPC_NoUp
	.byte 0

SootopolisCity_House1_EventScript_22694D:: @ 822694D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM31, SootopolisCity_House1_EventScript_226984
	msgbox SootopolisCity_House1_Text_2269A1, MSGBOX_DEFAULT
	giveitem_std ITEM_TM31
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM31
	msgbox SootopolisCity_House1_Text_226A13, MSGBOX_DEFAULT
	release
	end
SootopolisCity_House1_Text_2269A1: @ 82269A1
	.string "For thirty years I've remained in\n"
	.string "SOOTOPOLIS honing my skills.\p"
	.string "I developed a shattering TM.\n"
	.string "I bequeath it to you!$"
SootopolisCity_House1_EventScript_226984:: @ 8226984
	msgbox SootopolisCity_House1_Text_226A13, MSGBOX_DEFAULT
	release
	end
SootopolisCity_House1_Text_226A13: @ 8226A13
	.string "TM31 contains BRICK BREAK! It's a move\n"
	.string "so horrible that I can't describe it.$"

SootopolisCity_House1_EventScript_22698E:: @ 822698E
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KECLEON, 0
	msgbox SootopolisCity_House1_Text_226A60, MSGBOX_DEFAULT
	waitmoncry
	release
	end
SootopolisCity_House1_Text_226A60: @ 8226A60
	.string "KECLEON: Puu puhyaah.$"


SootopolisCity_House1_EventScript_StealSpot::
	lock
	setdynamicwarp MAP_SOOTOPOLIS_CITY, 4, 255, 255  @ Spot to get thrown out to
	msgbox SootopolisCity_House1_StealSpot_Text, MSGBOX_DEFAULT
	trysteal ITEM_BLACK_BELT, 1, FLAG_ITEM_STOLEN_SOOTOPOLIS_BLACKBELT
	release
	end
SootopolisCity_House1_StealSpot_Text:
	.string "He's got quite the collection here…$"



