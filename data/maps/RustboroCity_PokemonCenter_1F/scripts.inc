RustboroCity_PokemonCenter_1F_MapScripts:: @ 8214D62
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, RustboroCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition: @ 8214D6D
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

RustboroCity_PokemonCenter_1F_NurseScript:: @ 8214D76
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


RustboroCity_Mart_EventScript_MartScript:: @ 8214F06
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	goto_if_unset FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_214F21
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, RustboroCity_Mart_EventScript_214F48
	end

RustboroCity_Mart_EventScript_214F21:: @ 8214F21
	pokemart RustboroCity_Mart_Pokemart_214F30
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

RustboroCity_Mart_Pokemart_214F30: @ 8214F30
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ETHER
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

RustboroCity_Mart_EventScript_214F48:: @ 8214F48
	pokemart RustboroCity_Mart_Pokemart_214F58
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
RustboroCity_Mart_Pokemart_214F58: @ 8214F58
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

RustboroCity_PokemonCenter_1F_PC::
	lock
	setvar VAR_0x8004, 0
	special DoPCTurnOnEffect
	playse SE_PC_ON
	message RustboroCity_PokemonCenter_1F_PC_Text
	waitmessage
	waitse
	waitbuttonpress
	msgbox RustboroCity_PokemonCenter_1F_PC_Text_NoKeyboard, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	release
	end
RustboroCity_PokemonCenter_1F_PC_Text:
	.string "{PLAYER} booted up the PC.$"
RustboroCity_PokemonCenter_1F_PC_Text_NoKeyboard:
	.string "It says “No keyboard detected. Press\n"
	.string "F1 to continue.”$"


RustboroCity_PokemonCenter_1F_EventScript_214D84:: @ 8214D84
	msgbox RustboroCity_PokemonCenter_1F_Text_214D9F, MSGBOX_NPC
	end
RustboroCity_PokemonCenter_1F_Text_214D9F: @ 8214D9F
	.string "My Pokémon has a naive nature, and my\n"
	.string "friend's has a jolly nature.\p"
	.string "Just like people, Pokémon each have\n"
	.string "different personalities too!$"


RustboroCity_PokemonCenter_1F_EventScript_214D8D:: @ 8214D8D
	msgbox RustboroCity_PokemonCenter_1F_Text_214E13, MSGBOX_NPC
	end
RustboroCity_PokemonCenter_1F_Text_214E13: @ 8214E13
	.string "Just like people, there are male and\n"
	.string "female Pokémon.\p"
	.string "And just like people, it doesn't make\n"
	.string "any difference which they are.$"


RustboroCity_PokemonCenter_1F_EventScript_214D96:: @ 8214D96
	msgbox RustboroCity_PokemonCenter_1F_Text_214E81, MSGBOX_NPC
	end
RustboroCity_PokemonCenter_1F_Text_214E81: @ 8214E81
	@ TODO: Change text for Techniques
	.string "The man next door gave me an HM!\p"
	.string "I used it to teach my Pokémon how to\n"
	.string "CUT down skinny trees.$"


RustboroCity_Mart_EventScript_214F74:: @ 8214F74
	msgbox RustboroCity_Mart_Text_214F8F, MSGBOX_NPC
	end
RustboroCity_Mart_Text_214F8F: @ 8214F8F
	.string "I bought some Paralyze Heal and\n"
	.string "Antidotes.\p"
	.string "Just in case I run into Shroomish\n"
	.string "in Petalburg Woods.$"


RustboroCity_Mart_EventScript_214F7D:: @ 8214F7D
	msgbox RustboroCity_Mart_Text_214FF1, MSGBOX_NPC
	end
RustboroCity_Mart_Text_214FF1: @ 8214FF1
	.string "My Pokémon evolved.\n"
	.string "It has a lot of HP now.\p"
	.string "I should buy {ITEM}Super Potions{END} for it\n"
	.string "instead of ordinary Potions.$"


RustboroCity_Mart_EventScript_EscapeRopeBoy:: @ 8214F86
	msgbox RustboroCity_Mart_Text_21505C, MSGBOX_NPC
	end
RustboroCity_Mart_Text_21505C: @ 821505C
	.string "I got an {ITEM}Escape Rope{END} just in\n"
	.string "case I get lost in a cave.\p"
	.string "I just need to use it to get back to\n"
	.string "the entrance.$"
