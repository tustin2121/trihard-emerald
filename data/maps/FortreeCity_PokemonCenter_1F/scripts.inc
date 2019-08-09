FortreeCity_PokemonCenter_1F_MapScripts:: @ 82173D8
	map_script MAP_SCRIPT_ON_LOAD, FortreeCity_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

FortreeCity_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 3, 3, 0x5, 1
	return

FortreeCity_PokemonCenter_1F_OnTransition: @ 82173E3
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

@ -----------------------------------------------------

FortreeCity_PokemonCenter_1F_NurseScript:: @ 82173E7
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


FortreeCity_Mart_MartScript:: @ 8217666
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart FortreeCity_Mart_Pokemart_217680
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
FortreeCity_Mart_Pokemart_217680: @ 8217680
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	@ .2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

FortreeCity_PokemonCenter_1F_PC::
	lockall
	msgbox FortreeCity_PokemonCenter_1F_PC_Text, MSGBOX_DEFAULT
	releaseall
	end
FortreeCity_PokemonCenter_1F_PC_Text:
	.string "The screen is blue, and there is random\n"
	.string "text all over it.$"


FortreeCity_PokemonCenter_1F_EventScript_2173F5:: @ 82173F5
	msgbox FortreeCity_PokemonCenter_1F_Text_217410, MSGBOX_NPC
	end
FortreeCity_PokemonCenter_1F_Text_217410: @ 8217410
	.string "Listen, kid, are you working\n"
	.string "on a Pokédex?\p"
	.string "Hmm… Go to the Safari Zone.\n"
	.string "That's my suggestion.$"


FortreeCity_PokemonCenter_1F_EventScript_2173FE:: @ 82173FE
	msgbox FortreeCity_PokemonCenter_1F_Text_21746D, MSGBOX_NPC
	end
FortreeCity_PokemonCenter_1F_Text_21746D: @ 821746D
	@ TODO: replace with stuff
	.string "Have you done anything at\n"
	.string "the RECORD CORNER?\p"
	.string "It's pretty neat. It mixes and matches\n"
	.string "the records of TRAINERS.\p"
	.string "I don't know quite how it works,\n"
	.string "but it's cool. It's exciting, even!$"


FortreeCity_PokemonCenter_1F_EventScript_217407:: @ 8217407
	msgbox FortreeCity_PokemonCenter_1F_Text_21751F, MSGBOX_NPC
	end
FortreeCity_PokemonCenter_1F_Text_21751F: @ 821751F
	.string "Oh, wow, you have a PokéNav!\n"
	.string "And it's just like mine!\p"
	.string "Do you know about PokéNav's\n"
	.string "Match Call system?\p"
	.string "Access it, and you can chat with\n"
	.string "registered trainers anytime.\p"
	.string "It also shows you which trainers\n"
	.string "want a rematch with you.\p"
	.string "It's really nifty! Those Devon guys\n"
	.string "sure know what they're doing!$"


FortreeCity_Mart_EventScript_SuperRepelGirl:: @ 8217698
	msgbox FortreeCity_Mart_Text_2176B3, MSGBOX_NPC
	end
FortreeCity_Mart_Text_2176B3: @ 82176B3
	.string "Super Repel lasts a long time,\n"
	.string "and it gets the job done.\p"
	.string "It's much better than an ordinary\n"
	.string "Repel.$"


FortreeCity_Mart_EventScript_2176A1:: @ 82176A1
	msgbox FortreeCity_Mart_Text_217715, MSGBOX_NPC
	end
FortreeCity_Mart_Text_217715: @ 8217715
	.string "I always stock up on more items than\n"
	.string "I'm sure I'll need.\p"
	.string "You never know what might happen.\n"
	.string "Better to be safe than sorry!$"


FortreeCity_Mart_EventScript_2176AA:: @ 82176AA
	msgbox FortreeCity_Mart_Text_21778E, MSGBOX_NPC
	end
FortreeCity_Mart_Text_21778E: @ 821778E
	.string "A Rare Candy makes a Pokémon grow\n"
	.string "immediately by one level.$"
