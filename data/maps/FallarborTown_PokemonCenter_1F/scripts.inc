FallarborTown_PokemonCenter_1F_MapScripts:: @ 8200BCD
	map_script MAP_SCRIPT_ON_LOAD, FallarborTown_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FallarborTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

FallarborTown_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 3, 3, 0x5, 1
	return

FallarborTown_PokemonCenter_1F_OnTransition: @ 8200BD8
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

FallarborTown_PokemonCenter_1F_NurseScript:: @ 8200BE1
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


FallarborTown_Mart_MartScript:: @ 81FFCBF
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart FallarborTown_Mart_Pokemart_1FFCD8
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
FallarborTown_Mart_Pokemart_1FFCD8: @ 81FFCD8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ELIXIR
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

FallarborTown_PokemonCenter_1F_EventScript_200BEF:: @ 8200BEF
	msgbox FallarborTown_PokemonCenter_1F_Text_200E22, MSGBOX_NPC
	end
FallarborTown_PokemonCenter_1F_Text_200E22: @ 8200E22
	.string "I wonder what Pokémon looked like\n"
	.string "long, long ago?\p"
	.string "Maybe the {REF}Fossil Maniac{END} at the edge\n"
	.string "of town will know.$"


FallarborTown_PokemonCenter_1F_EventScript_200BF8:: @ 8200BF8
	msgbox FallarborTown_PokemonCenter_1F_Text_200E8B, MSGBOX_NPC
	end
FallarborTown_PokemonCenter_1F_Text_200E8B: @ 8200E8B
	.string "In the fields of Fallarbor, we plant\n"
	.string "seedlings of hardy trees that thrive\l"
	.string "even in volcanic ash.$"


FallarborTown_Mart_EventScript_SkittyLady:: @ 81FFCF4
	msgbox FallarborTown_Mart_Text_1FFD19, MSGBOX_NPC
	end
FallarborTown_Mart_Text_1FFD19: @ 81FFD19
	.string "I'm having a hard time deciding if I\n"
	.string "should make my Skitty evolve or not.\p"
	.string "I only have to use this {ITEM}Moon Stone{END},\n"
	.string "but it's so hard to decide…\p"
	.string "If I make it evolve, it will become\n"
	.string "much stronger.\p"
	.string "But it will look so different, too.$"


FallarborTown_Mart_EventScript_1FFD06:: @ 81FFD06
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, 0
	msgbox FallarborTown_Mart_Text_1FFDFA, MSGBOX_CDIALOG
	waitmoncry
	release
	end
FallarborTown_Mart_Text_1FFDFA: @ 81FFDFA
	.string "Skitty: Miyao?$"


FallarborTown_Mart_EventScript_NuggetMan:: @ 81FFCFD
	msgbox FallarborTown_Mart_Text_1FFE09, MSGBOX_NPC
	end
FallarborTown_Mart_Text_1FFE09: @ 81FFE09
	.string "This {ITEM}Nugget{END} I found here…\n"
	.string "I suppose I'll have to sell it, seeing\l"
	.string "as how it has no other use.$"


@ -----------------------------------------------------
@ Move Tutor
FallarborTown_Mart_EventScript_MoveTutor:: @ 82C80B6
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_METRONOME, FallarborTown_Mart_EventScript_2C8114
	msgbox FallarborTown_Mart_Text_2C7449, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_Mart_EventScript_2C810A
	call FallarborTown_Mart_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_Mart_EventScript_2C810A
	msgbox FallarborTown_Mart_Text_2C7582, MSGBOX_DEFAULT
	setvar VAR_0x8005, 8
	call EventScript_ShowPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq FallarborTown_Mart_EventScript_2C810A
	setflag FLAG_MOVE_TUTOR_TAUGHT_METRONOME
	goto FallarborTown_Mart_EventScript_2C8114
	end
FallarborTown_Mart_Text_2C7449: @ 82C7449
	.string "I want all sorts of things!\n"
	.string "But I used up my allowance…\p"
	.string "Wouldn't it be nice if there were\n"
	.string "a spell that made money appear when\l"
	.string "you waggle a finger?\p"
	.string "If you want, I can teach your Pokémon\n"
	.string "the move Metronome.\p"
	.string "Money won't appear, but your Pokémon\n"
	.string "will waggle a finger. Yes?$"
FallarborTown_Mart_Text_2C7582: @ 82C7582
	.string "Okay! I'll teach it!\n"
	.string "Which Pokémon should I teach?$"
FallarborTown_Mart_EventScript_2C810A:: @ 82C810A
	msgbox FallarborTown_Mart_Text_2C7556, MSGBOX_DEFAULT
	release
	end
FallarborTown_Mart_Text_2C7556: @ 82C7556
	.string "Okay. I'll be here if you change\n"
	.string "your mind.$"
FallarborTown_Mart_EventScript_2C8114:: @ 82C8114
	msgbox FallarborTown_Mart_Text_2C75B5, MSGBOX_DEFAULT
	release
	end
FallarborTown_Mart_Text_2C75B5: @ 82C75B5
	.string "When a Pokémon waggles its finger\n"
	.string "like a Metronome, all sorts of nice\l"
	.string "things happen.\p"
	.string "Wouldn't it be nice if we could\n"
	.string "use it, too?$"


FallarborTown_PokemonCenter_1F_Lanette:: @ 8200C01
	lock
	special DoPCBangShakingEffect
	playse SE_W070
	waitstate
	delay 30
	msgbox FallarborTown_PokemonCenter_1F_Text_200C6B, MSGBOX_DIALOG
	release
	end
FallarborTown_PokemonCenter_1F_Text_200C6B: @ 8200C6B
	.string "Why. Won't. You. Work?!\p"
	.string "I must have been working on this stupid\n"
	.string "PC for DAYS now!\p"
	.string "I HATE working in Tech Support!$"

