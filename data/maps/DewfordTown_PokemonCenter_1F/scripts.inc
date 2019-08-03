DewfordTown_PokemonCenter_1F_MapScripts:: @ 81FC523
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, DewfordTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

DewfordTown_PokemonCenter_1F_OnTransition: @ 81FC52E
	setrespawn HEAL_LOCATION_DEWFORD_TOWN
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

DewfordTown_PokemonCenter_1F_NurseScript:: @ 81FC537
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end

@ -----------------------------------------------------

DewfordTown_PokemonCenter_1F_PC::
	lockall
	msgbox DewfordTown_PokemonCenter_1F_PC_Text, MSGBOX_DEFAULT
	releaseall
	end
DewfordTown_PokemonCenter_1F_PC_Text:
	.string "{PLAYER} tries to turn on the PC, but it\n"
	.string "seems to be unplugged.$"


DewfordTown_PokemonCenter_1F_EventScript_1FC545:: @ 81FC545
	msgbox DewfordTown_PokemonCenter_1F_Text_1FC557, MSGBOX_NPC
	end
DewfordTown_PokemonCenter_1F_Text_1FC557: @ 81FC557
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"


DewfordTown_PokemonCenter_1F_EventScript_GuyWithHeadphones::
	msgbox DewfordTown_PokemonCenter_1F_Text_1FC5AE, MSGBOX_DIALOG
	msgbox DewfordTown_PokemonCenter_1F_Text_1FC5AE_DESC, MSGBOX_DESCRIBE
	end
DewfordTown_PokemonCenter_1F_Text_1FC5AE:
	.string "So we back in the gym,\n"
	.string "got our Pokémon dodging from\l"
	.string "side to side.\p"
	.string "Side, side to side…$"
DewfordTown_PokemonCenter_1F_Text_1FC5AE_DESC:
	.string "He seems to be totally absorbed\n"
	.string "in a strange music video.$"

