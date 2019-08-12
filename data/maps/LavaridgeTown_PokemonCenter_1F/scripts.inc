LavaridgeTown_PokemonCenter_1F_MapScripts:: @ 81FFAFA
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, LavaridgeTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

LavaridgeTown_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 8, 3, 0x5, 1
	return

LavaridgeTown_PokemonCenter_1F_OnTransition: @ 81FFB05
	setrespawn HEAL_LOCATION_LAVARIDGE_TOWN
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

LavaridgeTown_PokemonCenter_1F_NurseScript:: @ 81FFB0E
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


LavaridgeTown_Mart_MartScript:: @ 81FF9CE
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart_1FF9E8
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart_1FF9E8: @ 81FF9E8
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ELIXIR
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	@ .2byte ITEM_REVIVE
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

LavaridgeTown_PokemonCenter_1F_PC_Girl::
	lock
	faceplayer
	markasdialog
	msgbox LavaridgeTown_PokemonCenter_1F_PC_Girl_Text, MSGBOX_DEFAULT
	applymovement THIS_EVENT, Common_Movement_FaceUp
	waitmovement 0
	release
	end
LavaridgeTown_PokemonCenter_1F_PC_Girl_Text:
	.string "Stop it and leave.\p"
	.string "Now. Get out!$"


LavaridgeTown_PokemonCenter_1F_EventScript_1FFB2E:: @ 81FFB2E
	msgbox LavaridgeTown_PokemonCenter_1F_Text_1FFC21, MSGBOX_NPC
	end
LavaridgeTown_PokemonCenter_1F_Text_1FFC21: @ 81FFC21
	.string "That girl by the PC is so mean!\n"
	.string "…sniffle… …sob…$"


LavaridgeTown_PokemonCenter_1F_EventScript_1FFB1C:: @ 81FFB1C
	msgbox LavaridgeTown_PokemonCenter_1F_Text_1FFBAD, MSGBOX_NPC
	end
LavaridgeTown_PokemonCenter_1F_Text_1FFBAD: @ 81FFBAD
	.string "It's sort of magical how just sitting\n"
	.string "in a hot-spring pool can invigorate.\p"
	.string "I wish I could let my Pokémon\n"
	.string "soak, too.$"


LavaridgeTown_PokemonCenter_1F_EventScript_1FFB25:: @ 81FFB25
	msgbox LavaridgeTown_PokemonCenter_1F_Text_1FFB37, MSGBOX_NPC
	end
LavaridgeTown_PokemonCenter_1F_Text_1FFB37: @ 81FFB37
	.string "I think Pokémon get closer to their\n"
	.string "TRAINERS if they spend time together.\p"
	.string "The longer the better.\n"
	.string "That's what I think.$"


LavaridgeTown_Mart_EventScript_1FF9FE:: @ 81FF9FE
	msgbox LavaridgeTown_Mart_Text_1FFA10, MSGBOX_NPC
	end
LavaridgeTown_Mart_Text_1FFA10: @ 81FFA10
	.string "Use X SPEED to add to a Pokémon's\n"
	.string "SPEED in battle.\p"
	.string "That will help it get in the first\n"
	.string "strike--a decided advantage!$"


LavaridgeTown_Mart_EventScript_1FFA07:: @ 81FFA07
	msgbox LavaridgeTown_Mart_Text_1FFA83, MSGBOX_NPC
	end
LavaridgeTown_Mart_Text_1FFA83: @ 81FFA83
	.string "On Mt. Chimney's peak, there's a local\n"
	.string "specialty that you can buy only there.\p"
	.string "Give it to a Pokémon--it will be elated.$"
