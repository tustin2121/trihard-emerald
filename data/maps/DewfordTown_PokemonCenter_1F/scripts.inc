DewfordTown_PokemonCenter_1F_MapScripts:: @ 81FC523
	map_script MAP_SCRIPT_ON_LOAD, DewfordTown_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, DewfordTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

DewfordTown_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 3, 3, 0x5, 1
	return

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

DewfordTown_PokemonCenter_1F_EventScript_1FC545:: @ 81FC545
	msgbox DewfordTown_PokemonCenter_1F_Text_1FC557, MSGBOX_NPC
	end
DewfordTown_PokemonCenter_1F_Text_1FC557: @ 81FC557
	.string "There's a stone cavern at the edge\n"
	.string "of town.\p"
	.string "I've heard you can find rare stones\n"
	.string "there.$"


DewfordTown_PokemonCenter_1F_EventScript_GuyWithHeadphones::
	lock
	markasdialog
	msgbox DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text
	msgbox DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_DESC, MSGBOX_CDESCRIBE
	compare VAR_LETTER_INTERNETMUSIC_LOVERS, 1
	call_if_eq DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Delivery
	release
	end
DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text:
	.string "So we back in the gym,\n"
	.string "got our Pokémon dodging from\l"
	.string "side to side.\p"
	.string "Side, side to side…$"
DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_DESC:
	.string "He seems to be totally absorbed\n"
	.string "in a strange music video.$"
DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Delivery:
	faceplayer
	msgbox DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_Delivery1, MSGBOX_CDIALOG
	setvar VAR_LETTER_INTERNETMUSIC_LOVERS, 2
	takeitem ITEM_LETTER, 1
	msgbox DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_Delivery2, MSGBOX_CDESCRIBE
	msgbox DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_Delivery3, MSGBOX_CDIALOG
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 4
	return
DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_Delivery1:
	.string "Huh? What are you staring at?!\p"
	.string "What? You have a letter for me??$"
DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_Delivery2:
	.string "{PLAYER} handed over the letter.$"
DewfordTown_PokemonCenter_1F_GuyWithHeadphones_Text_Delivery3:
	.string "Oh, it's from that girl who always\n"
	.string "writes me in the comment section…\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Oh, wow, this seems to be hot stuff!\p"
	.string "Ha ha, thank you so much for delivering\n"
	.string "this to me.\p"
	.string "I'm really glad that she wrote me\n"
	.string "this letter.\p"
	.string "Hm? What's with that look?\p"
	.string "Reward? Pfft, no. Go ask her.\n"
	.string "I didn't promise you jack.$"

