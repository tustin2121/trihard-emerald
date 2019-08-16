PacifidlogTown_PokemonCenter_1F_MapScripts:: @ 82034A7
	map_script MAP_SCRIPT_ON_LOAD, PacifidlogTown_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_PokemonCenter_1F_MapScript1_277C30
	.byte 0

PacifidlogTown_PokemonCenter_1F_OnTransition: @ 82034B2
	setrespawn HEAL_LOCATION_PACIFIDLOG_TOWN
	end

PacifidlogTown_PokemonCenter_1F_OnLoad:
	setmetatile 13, 4, 0x32A, TRUE
	end

@ -----------------------------------------------------

PacifidlogTown_PokemonCenter_1F_NurseScript:: @ 82034B6
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end

@ -----------------------------------------------------

PacifidlogTown_PokemonCenter_1F_PC_Boy::
	lockall
	faceplayer
	msgbox PacifidlogTown_PokemonCenter_1F_PC_Boy_Text, MSGBOX_DEFAULT
	applymovement THIS_EVENT, Common_Movement_FaceUp
	waitmovement 0
	releaseall
	end
PacifidlogTown_PokemonCenter_1F_PC_Boy_Text:
	.string "Wait your turn.$"


PacifidlogTown_PokemonCenter_1F_EventScript_2034C4:: @ 82034C4
	msgbox PacifidlogTown_PokemonCenter_1F_Text_2034DF, MSGBOX_NPC
	end
PacifidlogTown_PokemonCenter_1F_Text_2034DF: @ 82034DF
	.string "Pacifidlog Town is so remote,\n"
	.string "the League often forgets about us.\p"
	.string "It's lucky we have a Center here\n"
	.string "at all, really.$"


PacifidlogTown_PokemonCenter_1F_EventScript_2034CD:: @ 82034CD
	msgbox PacifidlogTown_PokemonCenter_1F_Text_20350F, MSGBOX_NPC
	end
PacifidlogTown_PokemonCenter_1F_Text_20350F: @ 820350F
	.string "Pacifidlog Town floats on top of\n"
	.string "a colony of Corsola.\p"
	.string "If I told you that, would you believe\n"
	.string "me?$"


PacifidlogTown_PokemonCenter_1F_EventScript_2034D6:: @ 82034D6
	msgbox PacifidlogTown_PokemonCenter_1F_Text_20356F, MSGBOX_NPC
	end
PacifidlogTown_PokemonCenter_1F_Text_20356F: @ 820356F
	.string "The ancestors of the people in\n"
	.string "Pacifidlog were said to have been\l"
	.string "born on boats and then lived and died \l"
	.string "aboard them.\p"
	.string "I understand that they lived that way\n"
	.string "because they were searching for\l"
	.string "something.$"


PacifidlogTown_PokemonCenter_1F_FreePokeballBox::
	lock
	goto_if_set FLAG_TEMP_1D, PacifidlogTown_PokemonCenter_1F_FreePokeballBoxFlagged
	setyesnotext gYN_Sure, gYN_Nah
	msgbox PacifidlogTown_PokemonCenter_1F_FreePokeballBox_Text, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_ReleaseEnd
	giveitem_std ITEM_POKE_BALL, 10
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_TEMP_1D
	release
	end
PacifidlogTown_PokemonCenter_1F_FreePokeballBox_Text:
	.string "This box of free Poké Ball handouts\n"
	.string "should probably be behind the counter.\p"
	.string "Take a couple sets?$"
PacifidlogTown_PokemonCenter_1F_FreePokeballBoxFlagged:
	msgbox PacifidlogTown_PokemonCenter_1F_FreePokeballBox_Text2
	release
	end
PacifidlogTown_PokemonCenter_1F_FreePokeballBox_Text2:
	.string "This box of free Poké Ball handouts\n"
	.string "should probably be behind the counter.$"

