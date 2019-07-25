PetalburgCity_Mart_MapScripts:: @ 8207D68
	.byte 0

@ -----------------------------------------------------

PetalburgCity_House3_EventScript_Woman::
	lock
	goto_if_set FLAG_RECEIVED_TM53, PetalburgCity_House3_EventScript_Woman2
	faceplayer
	markasdialog
	msgbox PetalburgCity_House3_Text_Woman1a
	giveitem_std ITEM_TM53
	setflag FLAG_RECEIVED_TM53
	msgbox PetalburgCity_House3_Text_Woman1b
	release
	end
PetalburgCity_House3_Text_Woman1a:
	.string "We're taking a trip to {REF}Galar{END} in\n"
	.string "a month's time.\p"
	.string "So we're making lists and cleaning\n"
	.string "the house in preparation.\p"
	.string "Here, we don't need this, but you\n"
	.string "might find it useful.$"
PetalburgCity_House3_Text_Woman1b:
	.string "That TM teaches Surf, a pretty\n"
	.string "powerful water move.\p"
	.string "Pokémon that can learn it can also\n"
	.string "be ridden on to cross bodies of water,\l"
	.string "assuming you have the right badge.\p"
	.string "We won't need it in Galar.$"
PetalburgCity_House3_EventScript_Woman2::
	msgbox PetalburgCity_House3_Text_Woman2, MSGBOX_NPC
	end
PetalburgCity_House3_Text_Woman2:
	.string "I can't wait to see the sights.\p"
	.string "I hear they have amazing Pokémon\n" 
	.string "battles there, the likes of which\l"
	.string "you've never seen before!\p"
	.string "Oh! We can't forget the camera!$"


PetalburgCity_House3_EventScript_Man::
	msgbox PetalburgCity_House3_Text_Man, MSGBOX_NPC
	end
PetalburgCity_House3_Text_Man:
	.string "There's so much work to be done\n"
	.string "before we leave for {REF}Galar{END}…\p"
	.string "I need to make sure our passports\n"
	.string "and other papers are in order.\p"
	.string "I've also heard they have stringent\n"
	.string "laws against Invasive Pokémon Species,\l"
	.string "so I have to see if they'll even allow\l"
	.string "our Kirlia into the region.$"


PetalburgCity_House3_EventScript_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, 0
	msgbox PetalburgCity_House3_Text_Kirlia, MSGBOX_DEFAULT
	waitmoncry
	release
	end
PetalburgCity_House3_Text_Kirlia:
	.string "Kirlia: Prrri!$"

