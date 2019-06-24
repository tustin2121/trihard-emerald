PetalburgCity_PokemonCenter_2F_MapScripts:: @ 8207D41
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_PokemonCenter_2F_FrameTable
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_PokemonCenter_2F_OnLoad
	@ map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

PetalburgCity_PokemonCenter_2F_FrameTable: @ 8255C41
	map_script_2 VAR_LAST_WARP_ID, 1, PetalburgCity_PokemonCenter_2F_EventScript_WalkedInOn
	map_script_2 VAR_LAST_WARP_ID, 5, PetalburgCity_PokemonCenter_2F_EventScript_AfterKickout
	.2byte 0

PetalburgCity_PokemonCenter_2F_MapTable: @ 8255C41
	map_script_2 VAR_LAST_WARP_ID, 3, Common_EventScript_SetPowerOffWeather
	map_script_2 VAR_TEMP_1, 0, PetalburgCity_PokemonCenter_2F_OnLoad
	.2byte 0

PetalburgCity_PokemonCenter_2F_OnLoad:
	pokecenter_sitonbed 2, 17
	call_if_set FLAG_PETALBURG_CENTER_INCIDENT, PetalburgCity_PokemonCenter_2F_EventScript_AfterKickout_LockRoom
	end

PetalburgCity_PokemonCenter_2F_EventScript_AfterKickout:
	setvar VAR_LAST_WARP_ID, 0
	setflag FLAG_PETALBURG_CENTER_INCIDENT
	goto PetalburgCity_PokemonCenter_2F_EventScript_AfterKickout_LockRoom
	end
PetalburgCity_PokemonCenter_2F_EventScript_AfterKickout_LockRoom:
	setobjectxyperm 4, 14, 3
	setobjectmovementtype 4, MOVEMENT_TYPE_INVISIBLE
	setmetatile 14, 3, 0x322, TRUE @Set tile to non-warp tile
	end

@ -----------------------------------------------------

PetalburgCity_PokemonCenter_2F_EventScript_WalkedInOn::
	setvar VAR_LAST_WARP_ID, 0
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED, 2
	playse SE_PIN
	applymovement 5, PetalburgCity_PokemonCenter_2F_Movement_WalkedInOn
	applymovement 6, PetalburgCity_PokemonCenter_2F_Movement_WalkedInOn
	waitmovement 0
	message PetalburgCity_PokemonCenter_2F_Text_WalkedInOn, MSGTYPE_DIALOG
	waitmessage
	@ applymovement 6, PetalburgCity_PokemonCenter_2F_Movement_WalkedInOn2
	@ delay 4
	warptodynamic
	end
PetalburgCity_PokemonCenter_2F_Text_WalkedInOn:
	.string "AAAIIIIIIIIEEEEEEEE!!!!!!!$"
PetalburgCity_PokemonCenter_2F_Movement_WalkedInOn:
	emote_exclamation_mark
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	step_end
@ PetalburgCity_PokemonCenter_2F_Movement_WalkedInOn2:
@ 	walk_fast_right
@ 	walk_fast_down
@ 	step_end



PetalburgCity_PokemonCenter_2F_EventScript_SleepingGirl::
	msgbox PetalburgCity_PokemonCenter_2F_Text_SleepingGirl
	release
	end
PetalburgCity_PokemonCenter_2F_Text_SleepingGirl:
	.string "She's sleeping…$"

PetalburgCity_PokemonCenter_2F_EventScript_SleepingGirlsBag::
	lock
	msgbox PetalburgCity_PokemonCenter_2F_Text_SleepingGirlsBag, MSGBOX_DEFAULT
	trysteal ITEM_POTION, 2, FLAG_ITEM_STOLEN_PETALBURG_POTION
	release
	end
PetalburgCity_PokemonCenter_2F_Text_SleepingGirlsBag:
	.string "She's not gonna miss those…$"
