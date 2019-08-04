EverGrandeCity_PokemonCenter_1F_MapScripts:: @ 8229A34
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_PokemonCenter_1F_OnTransition: @ 8229A3F
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_1
	call_if_unset FLAG_MET_SCOTT_IN_EVERGRANDE, EverGrandeCity_PokemonCenter_1F_EventScript_229A4C
	end

EverGrandeCity_PokemonCenter_1F_EventScript_229A4C:: @ 8229A4C
	goto_if_unset FLAG_BADGE06_GET, Common_EventScript_NopReturn
	@ clearflag FLAH_UNUSED_0x319
	return

@ -----------------------------------------------------

EverGrandeCity_PokemonCenter_1F_NurseScript:: @ 8229A59
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


EverGrandeCity_PokemonCenter_1F_EventScript_MartScript:: @ 81FC240
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart EverGrandeCity_PokemonCenter_1F_Pokemart_1FC260
	msgbox gText_Mart_Goodbye, MSGBOX_CDIALOG
	release
	end
.align 2
EverGrandeCity_PokemonCenter_1F_Pokemart_1FC260: @ 81FC260
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	@ .2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------
@ People

EverGrandeCity_PokemonCenter_1F_EventScript_229A67:: @ 8229A67
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229ADA, MSGBOX_NPC
	end
EverGrandeCity_PokemonCenter_1F_Text_229ADA: @ 8229ADA
	.string "The Pokémon League is only a short\n"
	.string "distance after the Victory Road.\p"
	.string "If you've come this far, what choice\n"
	.string "do you have but to keep going?$"


EverGrandeCity_PokemonCenter_1F_EventScript_229A70:: @ 8229A70
	msgbox EverGrandeCity_PokemonCenter_1F_Text_229B62, MSGBOX_NPC
	end
EverGrandeCity_PokemonCenter_1F_Text_229B62: @ 8229B62
	.string "The long and harrowing Victory Road…\p"
	.string "It's like reliving the path one has\n"
	.string "traveled in life…\p"
	.string "Believe in your Pokémon and give it\n"
	.string "your very best!$"


EverGrandeCity_PokemonCenter_1F_EventScript_PcKid::
	msgbox EverGrandeCity_PokemonCenter_1F_Text_PcKid, MSGBOX_NPC
	end
EverGrandeCity_PokemonCenter_1F_Text_PcKid:
	.string "No one knows where that Azumarill\n"
	.string "angrily guarding the PC came from,\l"
	.string "or why it chose that spot to guard.$"


EverGrandeCity_PokemonCenter_1F_EventScript_PcAzum::
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_REVERSE
	msgbox EverGrandeCity_PokemonCenter_1F_Text_PcAzum, MSGBOX_DIALOG
	waitmoncry
	selectpointer EverGrandeCity_PokemonCenter_1F_MovementTable_PcAzum_Player, VAR_FACING
	applymovement EVENT_OBJ_ID_PLAYER, 0
	selectpointer EverGrandeCity_PokemonCenter_1F_MovementTable_PcAzum_Mon, VAR_FACING
	applymovement THIS_EVENT, 0
	playse SE_W233B
	waitmovement 0
	release
	end
EverGrandeCity_PokemonCenter_1F_Text_PcAzum:
	.string "Azumarill: Briiippppp!$"
EverGrandeCity_PokemonCenter_1F_MovementTable_PcAzum_Mon::
	.4byte Common_Movement_NoOp
	.4byte Common_Movement_NoOp
	.4byte EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Mon1
	.4byte EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Mon2
	.4byte Common_Movement_NoOp
	.4byte 0
EverGrandeCity_PokemonCenter_1F_MovementTable_PcAzum_Player::
	.4byte Common_Movement_NoOp
	.4byte Common_Movement_NoOp
	.4byte EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Player1
	.4byte EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Player2
	.4byte Common_Movement_NoOp
	.4byte 0
EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Mon1:
	lock_facing_direction
	slide_down
	slide_up
	unlock_facing_direction
	step_end
EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Mon2:
	lock_facing_direction
	slide_right
	slide_left
	unlock_facing_direction
	step_end
EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Player1:
	lock_facing_direction
	slide_down
	unlock_facing_direction
	step_end
EverGrandeCity_PokemonCenter_1F_Movement_PcAzum_Player2:
	lock_facing_direction
	slide_right
	unlock_facing_direction
	step_end


