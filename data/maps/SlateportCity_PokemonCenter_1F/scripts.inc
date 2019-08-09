SlateportCity_PokemonCenter_1F_MapScripts:: @ 820DABF
	map_script MAP_SCRIPT_ON_LOAD, SlateportCity_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SlateportCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

SlateportCity_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 3, 3, 0x5, 1
	return

SlateportCity_PokemonCenter_1F_OnTransition: @ 820DACA
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

SlateportCity_PokemonCenter_1F_NurseScript:: @ 820DAD3
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


SlateportCity_Mart_MartScript:: @ 820DC49
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart SlateportCity_Mart_Pokemart_20DC60
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

SlateportCity_Mart_Pokemart_20DC60: @ 820DC60
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ETHER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

SlateportCity_PokemonCenter_1F_PCMan::
	lock
	faceplayer
	msgbox SlateportCity_PokemonCenter_1F_Text_PCMan, MSGBOX_CDIALOG
	applymovement THIS_EVENT, Common_Movement_FaceUp
	waitmovement 0
	release
	end
SlateportCity_PokemonCenter_1F_Text_PCMan:
	.string "Just five more minutes!\p"
	.string "Someone is wrong on the internet and I\n"
	.string "have to correct them.$"


SlateportCity_PokemonCenter_1F_EventScript_BattleTipSailor:: @ 820DAE1
	msgbox SlateportCity_PokemonCenter_1F_Text_20DAF3, MSGBOX_NPC
	end
SlateportCity_PokemonCenter_1F_Text_20DAF3: @ 820DAF3
	.string "Want a tip for battling?\p"
	.string "I'd say it's raising different kinds\n"
	.string "of Pokémon in a balanced manner.\p"
	.string "It's no good to make just one\n"
	.string "Pokémon strong.\p"
	.string "If it has a type disadvantage,\n"
	.string "it might not stand a chance.$"


SlateportCity_PokemonCenter_1F_EventScript_20DAEA:: @ 820DAEA
	msgbox SlateportCity_PokemonCenter_1F_Text_20DBBC, MSGBOX_NPC
	end
SlateportCity_PokemonCenter_1F_Text_20DBBC: @ 820DBBC
	.string "I trade Pokémon with my friends.\p"
	.string "If a traded Pokémon is holding an\n"
	.string "item, it makes me twice as happy!$"


SlateportCity_Mart_EventScript_20DC76:: @ 820DC76
	msgbox SlateportCity_Mart_Text_20DC88, MSGBOX_NPC
	end
SlateportCity_Mart_Text_20DC88: @ 820DC88
	.string "The Market does have some interesting\n"
	.string "merchandise.\p"
	.string "But there are some items you can only\n"
	.string "get at a Pokémon Center Mart.$"


SlateportCity_Mart_EventScript_20DC7F:: @ 820DC7F
	msgbox SlateportCity_Mart_Text_20DCF8, MSGBOX_NPC
	end
SlateportCity_Mart_Text_20DCF8: @ 820DCF8
	.string "A Great Ball is better than a Poké Ball\n"
	.string "at catching Pokémon.\p"
	.string "With this, I should be able to get that\n"
	.string "elusive Pokémon…$"

