OldaleTown_PokemonCenter_1F_MapScripts:: @ 81FC006
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, OldaleTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition: @ 81FC011
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

OldaleTown_PokemonCenter_1F_NurseScript:: @ 81FC01A
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


OldaleTown_Mart_EventScript_MartScript:: @ 81FC240
	lock
	faceplayer
	message gText_Mart_Welcome
	waitmessage
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_1FC26C
	pokemart OldaleTown_Mart_Pokemart_1FC260
	msgbox gText_Mart_Goodbye, MSGBOX_DEFAULT
	release
	end
OldaleTown_Mart_Pokemart_1FC260: @ 81FC260
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

OldaleTown_Mart_EventScript_1FC26C:: @ 81FC26C
	pokemart OldaleTown_Mart_Pokemart_1FC27C
	msgbox gText_Mart_Goodbye, MSGBOX_DEFAULT
	release
	end
	.align 2
OldaleTown_Mart_Pokemart_1FC27C: @ 81FC27C
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

OldaleTown_PokemonCenter_1F_PC::
	lockall
	msgbox Text_PCOutOfOrder, MSGBOX_DEFAULT
	releaseall
	end
Text_PCOutOfOrder:
	.string "There's a sign on the PC that says\n"
	.string "“Out of Order” with a frowny face.$"


OldaleTown_PokemonCenter_1F_EventScript_1FC028:: @ 81FC028
	msgbox OldaleTown_PokemonCenter_1F_Text_1FC059, MSGBOX_NPC
	end
OldaleTown_PokemonCenter_1F_Text_1FC059: @ 81FC059
	.string "That PC in the corner there is\n"
	.string "for any Pokémon Trainer to use.\p"
	.string "Though I have yet to see a working one.$"
	

OldaleTown_PokemonCenter_1F_EventScript_1FC031:: @ 81FC031
	msgbox OldaleTown_PokemonCenter_1F_Text_1FC0CD, MSGBOX_NPC
	end
OldaleTown_PokemonCenter_1F_Text_1FC0CD: @ 81FC0CD
	.string "Pokémon Centers are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\p"
	.string "Well, technically the taxpayers are\n"
	.string "paying for them, but…\l"
	.string "YOU never have to pay for it!$"


OldaleTown_PokemonCenter_1F_EventScript_1FC03A:: @ 81FC03A
	lock
	faceplayer
	msgbox OldaleTown_PokemonCenter_1F_Text_1FC148, MSGBOX_DEFAULT
	release
	end
OldaleTown_PokemonCenter_1F_Text_1FC148: @ 81FC148
	.string "The second floor of every Pokémon\n"
	.string "Center is the Trainer's Lounge.\p"
	.string "You can go upstairs to rest, relax,\n"
	.string "and even get a room for the night.$"


OldaleTown_Mart_EventScript_1FC28A:: @ 81FC28A
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_Mart_EventScript_1FC29F
	msgbox OldaleTown_Mart_Text_1FC2B2, MSGBOX_DEFAULT
	release
	end
OldaleTown_Mart_EventScript_1FC29F:: @ 81FC29F
	msgbox OldaleTown_Mart_Text_1FC2F3, MSGBOX_DEFAULT
	release
	end
OldaleTown_Mart_Text_1FC2B2: @ 81FC2B2
	.string "The counter to the left of the shop\n"
	.string "gives out Poké Balls for free!\l"
	.string "But they seem to be out right now.$"
OldaleTown_Mart_Text_1FC2F3: @ 81FC2F3
	.string "The counter to the left of the shop\n"
	.string "gives out Poké Balls for free!\p"
	.string "I'm going to get a bunch of Poké Balls\n"
	.string "and catch a bunch of Pokémon!$"


OldaleTown_Mart_EventScript_1FC2A9:: @ 81FC2A9
	msgbox OldaleTown_Mart_Text_1FC338, MSGBOX_NPC
	end
OldaleTown_Mart_Text_1FC338: @ 81FC338
	.string "If a Pokémon gets hurt in battle,\n"
	.string "it loses HP, or Hit Points.\p"
	.string "If it loses all of its HP, it will\n"
	.string "faint, and probably die.\p"
	.string "Make sure to take care of your Pokémon\n"
	.string "with Potions and other healing.$"
