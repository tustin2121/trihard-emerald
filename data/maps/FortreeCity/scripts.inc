FortreeCity_MapScripts:: @ 81E25A4
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

@ -----------------------------------------------------

FortreeCity_OnTransition: @ 81E25AF
	setflag FLAG_VISITED_FORTREE_CITY
	end

@ -----------------------------------------------------

FortreeCity_OnResume: @ 81E25B3
	setstepcallback 2
	end

@ -----------------------------------------------------
@ Signs

FortreeCity_EventScript_1E2602:: @ 81E2602
	msgbox FortreeCity_Text_1E2AAC, MSGBOX_SIGN
	end
FortreeCity_Text_1E2AAC: @ 81E2AAC
	.string "{PLACE}Fortree City{END}\n"
	.string "“The treetop city that frolics with\l"
	.string "nature.”$"


FortreeCity_EventScript_DecorShop:: @ 81E2602
	msgbox FortreeCity_Text_DecorShop, MSGBOX_SIGN
	end
FortreeCity_Text_DecorShop: @ 81E2AAC
	.string "{PLACE}Secret Base Decor Shop{END}\n"
	.string "“Furnish your bushy abode!”$"


FortreeCity_EventScript_1E260B:: @ 81E260B
	msgbox FortreeCity_Text_1E2AE6, MSGBOX_SIGN
	end
FortreeCity_Text_1E2AE6: @ 81E2AE6
	.string "{GYM}Fortree City Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Winona\p"
	.string "“The bird user taking flight into\n"
	.string "the world.”$"

@ -----------------------------------------------------
@ People

FortreeCity_EventScript_1E25B6:: @ 81E25B6
	msgbox FortreeCity_Text_1E2676, MSGBOX_NPC
	end
FortreeCity_Text_1E2676: @ 81E2676
	.string "No one believes me, but I saw this\n"
	.string "gigantic Pokémon in the sky.\p"
	.string "It seemed to squirm as it flew toward\n"
	.string "Route 131.\p"
	.string "By the way… Sniff…\n"
	.string "Um… You, uh… smell singed.\p"
	.string "Were you at a volcano or something?$"


FortreeCity_EventScript_1E25BF:: @ 81E25BF
	msgbox FortreeCity_Text_1E27B6, MSGBOX_NPC
	end
FortreeCity_Text_1E27B6: @ 81E27B6
	.string "I've got my pride-and-joy Pokémon\n"
	.string "with me. This time, I'll beat Winona.$"


FortreeCity_EventScript_1E25DE:: @ 81E25DE
	msgbox FortreeCity_Text_1E27FE, MSGBOX_NPC
	end
FortreeCity_Text_1E27FE: @ 81E27FE
	.string "The ground absorbs rainwater, and\n"
	.string "trees grow by drinking that water…\p"
	.string "Our Fortree City exists because\n"
	.string "there's both water and soil.$"


FortreeCity_EventScript_1E25E7:: @ 81E25E7
	msgbox FortreeCity_Text_1E2880, MSGBOX_NPC
	end
FortreeCity_Text_1E2880: @ 81E2880
	.string "The city consists of homes built on\n"
	.string "trees.\p"
	.string "Perhaps because of that lifestyle,\n"
	.string "everyone is healthy and lively.\p"
	.string "Why, even myself--I feel as if I've\n"
	.string "grown thirty years younger.$"


FortreeCity_EventScript_1E25F0:: @ 81E25F0
	msgbox FortreeCity_Text_1E292E, MSGBOX_NPC
	end
FortreeCity_Text_1E292E: @ 81E292E
	.string "Living on top of trees is okay.\p"
	.string "But sometimes bug Pokémon come in\n"
	.string "through windows.\l"
	.string "It can be really startling.$"


FortreeCity_EventScript_1E25F9:: @ 81E25F9
	msgbox FortreeCity_Text_1E299D, MSGBOX_NPC
	end
FortreeCity_Text_1E299D: @ 81E299D
	.string "There are Pokémon that evolve when\n"
	.string "you trade them! That's what I heard.$"



FortreeCity_EventScript_1E2614:: @ 81E2614
	lock
	faceplayer
	msgbox FortreeCity_Text_1E2A08, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq FortreeCity_EventScript_1E2645
	release
	end
FortreeCity_Text_1E2A08: @ 81E2A08
	.string "Something unseeable is in the way.\p"
	.string "Want to poke it with a stick?$"
FortreeCity_EventScript_1E2645:: @ 81E2645
	msgbox FortreeCity_Text_1E2A48, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_KecleonShowAnim
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, Common_Movement_WalkRight1
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end
FortreeCity_Text_1E2A48: @ 81E2A48
	.string "{PLAYER} poked the air with a stick.\p"
	.string "An invisible Pokémon became completely\n"
	.string "visible!\p"
	.string "The startled Pokémon fled!$"

