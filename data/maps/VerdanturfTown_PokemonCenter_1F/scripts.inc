VerdanturfTown_PokemonCenter_1F_MapScripts:: @ 8202726
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, VerdanturfTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

@ -----------------------------------------------------

VerdanturfTown_PokemonCenter_1F_OnTransition: @ 8202731
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

VerdanturfTown_PokemonCenter_1F_NurseScript:: @ 820273A
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


VerdanturfTown_Mart_MartScript:: @ 8202587
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart_2025A0
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart_2025A0: @ 82025A0
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ELIXIR
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

VerdanturfTown_PokemonCenter_1F_EventScript_202748:: @ 8202748
	msgbox VerdanturfTown_PokemonCenter_1F_Text_20275A, MSGBOX_NPC
	end
VerdanturfTown_PokemonCenter_1F_Text_20275A: @ 820275A
	.string "You can't consider yourself a real\n"
	.string "Trainer if you don't have faith\l"
	.string "in your Pokémon.\p"
	.string "Only those people who can believe\n"
	.string "in their battling Pokémon can win\l"
	.string "through to the very end.$"


VerdanturfTown_PokemonCenter_1F_EventScript_202751:: @ 8202751
	msgbox VerdanturfTown_PokemonCenter_1F_Text_20280B, MSGBOX_NPC
	end
VerdanturfTown_PokemonCenter_1F_Text_20280B: @ 820280B
	.string "The reason why anyone would visit\n"
	.string "Verdanturf…\p"
	.string "It's the Contest Hall. It goes without\n"
	.string "saying.\p"
	.string "Or is there somebody here that you\n"
	.string "came to see?$"


VerdanturfTown_Mart_EventScript_XSpecialBoy:: @ 82025BA
	msgbox VerdanturfTown_Mart_Text_2025D5, MSGBOX_NPC
	end
VerdanturfTown_Mart_Text_2025D5: @ 82025D5
	.string "For any Pokémon match, X SPECIAL\n"
	.string "is crucial.\p"
	.string "It jacks up the power of some moves\n"
	.string "even though it's only for one battle.$"


VerdanturfTown_Mart_EventScript_2025C3:: @ 82025C3
	msgbox VerdanturfTown_Mart_Text_20264C, MSGBOX_NPC
	end
VerdanturfTown_Mart_Text_20264C: @ 820264C
	.string "They don't seem to sell any winning\n"
	.string "strategy guides for the CONTEST HALL…\p"
	.string "It seems one must rely on one's\n"
	.string "own wits after all…$"


VerdanturfTown_Mart_EventScript_NestBallFan:: @ 82025CC
	msgbox VerdanturfTown_Mart_Text_2026C9, MSGBOX_NPC
	end
VerdanturfTown_Mart_Text_2026C9: @ 82026C9
	.string "The {ITEM}Nest Ball{END} works better on\n"
	.string "weakened Pokémon.\p"
	.string "Verdanturf is the only place you can\n"
	.string "buy it.$"


VerdanturfTown_PokemonCenter_1F_SleepingOldMan::
	msgbox VerdanturfTown_PokemonCenter_1F_SleepingOldMan_Text, MSGBOX_CDIALOG
	msgbox VerdanturfTown_PokemonCenter_1F_SleepingOldMan_Text_DESC, MSGBOX_CDESCRIBE
	releaseall
	end
VerdanturfTown_PokemonCenter_1F_SleepingOldMan_Text::
	.string "Zzz…\p"
	.string "Show you how to catch…!$"
VerdanturfTown_PokemonCenter_1F_SleepingOldMan_Text_DESC::
	.string "He fell asleep while he\n"
	.string "was watching some ASMR…$"
