FallarborTown_MapScripts:: @ 81EB1FA
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

@ -----------------------------------------------------

FallarborTown_OnTransition: @ 81EB200
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

@ -----------------------------------------------------
@ Signs

FallarborTown_EventScript_1EB250:: @ 81EB250
	msgbox FallarborTown_Text_1EB4C2, MSGBOX_SIGN
	end
FallarborTown_Text_1EB4C2: @ 81EB4C2
	.string "{PLACE}Pokémon Contest{END}\n"
	.string "“May the Classiest Pokémon Rise!”$"


FallarborTown_EventScript_1EB259:: @ 81EB259
	msgbox FallarborTown_Text_1EB4FE, MSGBOX_SIGN
	end
FallarborTown_Text_1EB4FE: @ 81EB4FE
	.string "{PLACE}Fallarbor Town{END}\n"
	.string "“A farm community with small gardens.”$"


FallarborTown_EventScript_1EB262:: @ 81EB262
	msgbox FallarborTown_Text_1EB534, MSGBOX_SIGN
	end
FallarborTown_Text_1EB534: @ 81EB534
	.string "{PLACE}Move Tutor's House{END}\n"
	.string "“New moves taught to Pokémon.”$"

@ -----------------------------------------------------
@ People

FallarborTown_EventScript_1EB20C:: @ 81EB20C
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_1EB221
	msgbox FallarborTown_Text_1EB26B
	release
	end
FallarborTown_Text_1EB26B: @ 81EB26B
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of Prof. Cozmo's home…$"
FallarborTown_EventScript_1EB221:: @ 81EB221
	msgbox FallarborTown_Text_1EB2DE
	release
	end
FallarborTown_Text_1EB2DE: @ 81EB2DE
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say Meteor Falls was gouged out\n"
	.string "by a falling meteorite long ago.$"


FallarborTown_EventScript_1EB22B:: @ 81EB22B
	msgbox FallarborTown_Text_1EB35F, MSGBOX_NPC
	end
FallarborTown_Text_1EB35F: @ 81EB35F
	.string "See! Take a look!\n"
	.string "This is my precious Azurill!\p"
	.string "It's slick and smooth and plushy, too!$"


FallarborTown_EventScript_1EB234:: @ 81EB234
	msgbox FallarborTown_Text_1EB3CA, MSGBOX_NPC
	end
FallarborTown_Text_1EB3CA: @ 81EB3CA
	.string "Have you already challenged Flannery,\n"
	.string "the leader of {GYM}Lavaridge Gym{END}?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the Elite Four in the\l"
	.string "Pokémon League at one point.\p"
	.string "It wouldn't surprise me to see Flannery\n"
	.string "become a great trainer in her own\l"
	.string "right.$"


FallarborTown_EventScript_1EB23D:: @ 81EB23D
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, 0
	msgbox FallarborTown_Text_1EB3B5, MSGBOX_CDIALOG
	waitmoncry
	release
	end
FallarborTown_Text_1EB3B5: @ 81EB3B5
	.string "Azurill: Rooreelooo.$"

