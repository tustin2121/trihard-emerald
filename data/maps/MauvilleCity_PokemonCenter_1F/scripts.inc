MauvilleCity_PokemonCenter_1F_MapScripts:: @ 8210E5B
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, MauvilleCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

MauvilleCity_PokemonCenter_1F_OnLoad:
	@ Set the PC screen metatile to the evil face if it is out of view.
	getplayerxy VAR_TEMP_1, VAR_TEMP_2
	compare VAR_TEMP_1, 10
	goto_if_gt MauvilleCity_PokemonCenter_1F_OnLoad_SetEvilFace
	compare VAR_TEMP_1, 2
	goto_if_lt MauvilleCity_PokemonCenter_1F_OnLoad_SetEvilFace
	compare VAR_TEMP_2, 8
	goto_if_gt MauvilleCity_PokemonCenter_1F_OnLoad_SetEvilFace
	return

MauvilleCity_PokemonCenter_1F_OnLoad_SetEvilFace:
	setmetatile 3, 3, 0x31D, 1
	return

MauvilleCity_PokemonCenter_1F_OnTransition: @ 8210E66
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call PokemonCenter_1F_SetMrBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_210E74
	end

MauvilleCity_PokemonCenter_1F_EventScript_210E74:: @ 8210E74
	special ScrSpecial_SetMauvilleOldManEventObjGfx
	end

@ -----------------------------------------------------

MauvilleCity_PokemonCenter_1F_NurseScript:: @ 8210E78
	setvar VAR_0x800B, 1 @ This is used for ApplyMovement? Why is this not just using THIS_EVENT
	lock
	faceplayer
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG  @ markasdialog
	goto_if_set FLAG_TEMP_5, PokemonCenter_1F_NurseHealScript_Talk
	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
	setyesnotext gYN_Sure, gYN_No
	select_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, PokemonCenter_1F_NurseText_NurseHealPrompt, MauvilleCity_PokemonCenter_1F_NurseText_NurseHealPrompt
	msgbox_selected MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PokemonCenter_1F_NurseHealScript_Heal
	
	message PokemonCenter_1F_NurseText_NurseGoodbye
	waitmessage
	waitbuttonpress
	release
	end
MauvilleCity_PokemonCenter_1F_NurseText_NurseHealPrompt:
	.string "Welcome to the Pokémon Center!\p"
	.string "All of our rooms are unavailable at\n"
	.string "this time, but we can offer cots.\p"
	.string "Would you like a cot\n"
	.string "for the {TIME_OF_DAY}?$"

MauvilleCity_PokemonCenter_1F_Hipster::
	markasdialog
	goto MauvilleCity_PokemonCenter_1F_EventScript_28E066
	end

MauvilleCity_Mart_MartScript:: @ 82110E6
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart_211100
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart_211100: @ 8211100
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

MauvilleCity_PokemonCenter_1F_PC::
	lockall
	msgbox MauvilleCity_PokemonCenter_1F_PC_Text, MSGBOX_DEFAULT
	releaseall
	end
MauvilleCity_PokemonCenter_1F_PC_Text:
	.string "Is… is that faint laughter?$"

MauvilleCity_PokemonCenter_1F_PC_TriggerFace::
	special DoEvilPCFaceFade
	setvar VAR_TEMP_0, 1
	end

@ -----------------------------------------------------

MauvilleCity_PokemonCenter_1F_EventScript_210E86:: @ 8210E86
	msgbox MauvilleCity_PokemonCenter_1F_Text_210EA1, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_1F_Text_210EA1: @ 8210EA1
	.string "That man over there, he says weird\n"
	.string "things!\p"
	.string "He's funny in a weird way.\n"
	.string "I doubt I'll forget about him!$"


MauvilleCity_PokemonCenter_1F_EventScript_PCLady:: @ 8210E8F
	msgbox MauvilleCity_PokemonCenter_1F_Text_210F06, MSGBOX_NPC
	setvar VAR_TEMP_0, 0
	setmetatile 3, 3, 0x31D, 1
	end
MauvilleCity_PokemonCenter_1F_Text_210F06: @ 8210F06
	.string "I think I'm seeing things…\p"
	.string "Is it just me, or did that PC in the\n"
	.string "corner have an evil grin for a moment…?$"


MauvilleCity_PokemonCenter_1F_EventScript_210E98:: @ 8210E98
	msgbox MauvilleCity_PokemonCenter_1F_Text_210F8A, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_1F_Text_210F8A: @ 8210F8A
	.string "There are rooms upstairs in\n"
	.string "the Pokémon Center.\p"
	.string "They built them so trainers can\n"
	.string "get some rest after traveling!$"


MauvilleCity_Mart_EventScript_21111C:: @ 821111C
	msgbox MauvilleCity_Mart_Text_21112E, MSGBOX_NPC
	end
MauvilleCity_Mart_Text_21112E: @ 821112E
	.string "There are items that temporarily\n"
	.string "elevate the stats of Pokémon.\p"
	.string "The ones I know you use in battle\n"
	.string "are X ATTACK and X DEFEND…\p"
	.string "I do believe that there are others\n"
	.string "like them.$"


MauvilleCity_Mart_EventScript_211125:: @ 8211125
	msgbox MauvilleCity_Mart_Text_2111D8, MSGBOX_NPC
	end
MauvilleCity_Mart_Text_2111D8: @ 82111D8
	.string "Use a certain move, or use an item\n"
	.string "instead…\p"
	.string "The Trainer's decisions determine how\n"
	.string "battles turn out, I think.$"
