MossdeepCity_PokemonCenter_1F_MapScripts:: @ 822223F
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MossdeepCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

MossdeepCity_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 3, 3, 0x5, 1
	return

MossdeepCity_PokemonCenter_1F_OnTransition: @ 822224A
	setrespawn HEAL_LOCATION_MOSSDEEP_CITY
	end

@ -----------------------------------------------------

MossdeepCity_PokemonCenter_1F_NurseScript:: @ 822224E
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


MossdeepCity_Mart_MartScript:: @ 82223C8
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart_2223E0
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart_2223E0: @ 82223E0
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_FULL_HEAL
	@ .2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

MossdeepCity_Mart_EventScript_2223F6:: @ 82223F6
	msgbox MossdeepCity_Mart_Text_222411, MSGBOX_NPC
	end
MossdeepCity_Mart_Text_222411: @ 8222411
	@ TODO REMOVE
	.string "Revive is fantastic!\p"
	.string "Give it to a fainted Pokémon,\n"
	.string "and the Pokémon will arise.\p"
	.string "But be careful, Revive doesn't restore\n"
	.string "the used-up PP of moves.$"


MossdeepCity_Mart_EventScript_2223FF:: @ 82223FF
	msgbox MossdeepCity_Mart_Text_2224A0, MSGBOX_NPC
	end
MossdeepCity_Mart_Text_2224A0: @ 82224A0
	.string "Max Repel keeps all weak Pokémon away.\p"
	.string "Out of all the Repel sprays, it lasts\n"
	.string "the longest.$"


MossdeepCity_Mart_EventScript_222408:: @ 8222408
	msgbox MossdeepCity_Mart_Text_2224FA, MSGBOX_NPC
	end
MossdeepCity_Mart_Text_2224FA: @ 82224FA
	.string "The Net and Dive Balls are rare Poké\n"
	.string "Balls that are only made in Mossdeep.\p"
	.string "A Net BALL is effective against\n"
	.string "Bug-type and Water-type Pokémon.\p"
	.string "A Dive Ball works best on Pokémon\n"
	.string "at the bottom of the sea.$"


MossdeepCity_PokemonCenter_1F_EventScript_22225C:: @ 822225C
	msgbox MossdeepCity_PokemonCenter_1F_Text_22226E, MSGBOX_NPC
	end
MossdeepCity_PokemonCenter_1F_Text_22226E: @ 822226E
	.string "The Gym Leaders in this town are\n"
	.string "a formidable duo.\p"
	.string "Their combination attacks are, like,\n"
	.string "excellent and wow!$"


MossdeepCity_PokemonCenter_1F_EventScript_222265:: @ 8222265
	msgbox MossdeepCity_PokemonCenter_1F_Text_2222D9, MSGBOX_NPC
	end
MossdeepCity_PokemonCenter_1F_Text_2222D9: @ 82222D9
	.string "Depending on the special abilities of\n"
	.string "Pokémon, some moves might change\l"
	.string "or not work at all.$"


MossdeepCity_PokemonCenter_1F_PC::
	lockall
	msgbox MossdeepCity_PokemonCenter_1F_PC_Text, MSGBOX_DEFAULT
	releaseall
	end
MossdeepCity_PokemonCenter_1F_PC_Text:
	.string "There's a music video playing on loop.\p"
	.string "A man is dancing and singing about how\n"
	.string "he intends to never give up someone,\l"
	.string "nor let them down,\l"
	.string "nor run them around,\l"
	.string "and desert them.$"
