PacifidlogTown_MapScripts:: @ 81EBAB1
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_MapScript1_1EBAC0
	.byte 0

PacifidlogTown_OnTransition: @ 81EBABC
	setflag FLAG_VISITED_PACIFIDLOG_TOWN
	end

PacifidlogTown_MapScript1_1EBAC0: @ 81EBAC0
	setstepcallback 3
	end

PacifidlogTown_EventScript_1EBAC3:: @ 81EBAC3
	msgbox PacifidlogTown_Text_1EBB6C, MSGBOX_NPC
	end
PacifidlogTown_Text_1EBB6C: @ 81EBB6C
	.string "See, isn't it neat?\n"
	.string "These houses are on water!\p"
	.string "I was born here!$"


PacifidlogTown_EventScript_1EBACC:: @ 81EBACC
	msgbox PacifidlogTown_Text_1EBAE7, MSGBOX_NPC
	end
PacifidlogTown_Text_1EBAE7: @ 81EBAE7
	.string "The sea between Pacifidlog and\n"
	.string "Slateport has a fast-running tide.\p"
	.string "If you decide to surf, you could end\n"
	.string "up swept away somewhere else.$"


PacifidlogTown_EventScript_1EBAD5:: @ 81EBAD5
	msgbox PacifidlogTown_Text_1EBBAC, MSGBOX_NPC
	end
PacifidlogTown_Text_1EBBAC: @ 81EBBAC
	.string "The Sky Pillar?\p"
	.string "…Oh, you must mean that tall, tall\n"
	.string "tower a little further out.\p"
	.string "If you asked me, I wouldn't climb it.\n"
	.string "It's too scary to get up that high.\p"
	.string "Life at sea level in Pacifidlog,\n"
	.string "that suits me fine.$"


PacifidlogTown_EventScript_1EBADE:: @ 81EBADE
	msgbox PacifidlogTown_Text_1EBC7A, MSGBOX_SIGN
	end
PacifidlogTown_Text_1EBC7A: @ 81EBC7A
	.string "{PLACE}Pacifidlog Town{END}\p"
	.string "“Where the morning sun smiles upon\n"
	.string "the waters.”$"


PacifidlogTown_EventScript_TransportMossdeep::
	lock
	faceplayer
	markasdialog
	askforboat PacifidlogTown_Text_TransportMossdeep_Ask, PacifidlogTown_Text_TransportMossdeep_Decline, PacifidlogTown_Text_TransportMossdeep_NoMoney, PacifidlogTown_Text_TransportMossdeep_Embark
	warpcustom MAP_MOSSDEEP_CITY, 255, 54, 37
	waitstate
	end
PacifidlogTown_Text_TransportMossdeep_Ask:
	.string "Oh, hello! I'm going back home to\n"
	.string "{PLACE}Mossdeep{END} soon.\p"
	.string "If you're heading the same way,\n"
	.string "I think ¥100 will cover the fuel.$"
PacifidlogTown_Text_TransportMossdeep_Decline:
	.string "Oh, alright.$"
PacifidlogTown_Text_TransportMossdeep_NoMoney:
	.string "Ah ah, no stiffing me, young {PLAYER_man}.$"
PacifidlogTown_Text_TransportMossdeep_Embark:
	.string "Yay! Let's head out now!$"


PacifidlogTown_EventScript_TransportSlateport::
	lock
	faceplayer
	markasdialog
	askforboat PacifidlogTown_Text_TransportSlateport_Ask, PacifidlogTown_Text_TransportSlateport_Decline, PacifidlogTown_Text_TransportSlateport_NoMoney, PacifidlogTown_Text_TransportSlateport_Embark
	setvar VAR_CROSS_MAP_TRIGGER, 1
	warpcustom MAP_SLATEPORT_CITY, 255, 44, 14
	waitstate
	end
PacifidlogTown_Text_TransportSlateport_Ask:
	.string "G'day. Heading to {PLACE}Slateport{END}.\n"
	.string "One way trip. ¥100. Wanna ride?$"
PacifidlogTown_Text_TransportSlateport_Decline:
	.string "A'ie, mate.$"
PacifidlogTown_Text_TransportSlateport_NoMoney:
	.string "See 'em Poké Backs firs'.$"
PacifidlogTown_Text_TransportSlateport_Embark:
	.string "Les'go.$"

