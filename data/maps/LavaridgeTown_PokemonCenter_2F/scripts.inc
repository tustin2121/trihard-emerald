LavaridgeTown_PokemonCenter_2F_MapScripts:: @ 81FFC97
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LavaridgeTown_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

LavaridgeTown_PokemonCenter_2F_MapTable:
	map_script_2 VAR_LAST_WARP_ID, 1, Common_EventScript_SetPowerOffWeather
	.2byte 0

@ -----------------------------------------------------

LavaridgeTown_PokemonCenter_2F_EventScript_SleepingBoy::
	msgbox LavaridgeTown_PokemonCenter_2F_Text_SleepingBoy
	release
	end
LavaridgeTown_PokemonCenter_2F_Text_SleepingBoy:
	.string "He's passed out…$"

LavaridgeTown_PokemonCenter_2F_EventScript_SleepingBoysBag::
	lock
	msgbox LavaridgeTown_PokemonCenter_2F_Text_SleepingBoysBag, MSGBOX_DEFAULT
	trysteal ITEM_SHOAL_SHELL, 1, FLAG_ITEM_STOLEN_SHOAL_SHELL
	release
	end
LavaridgeTown_PokemonCenter_2F_Text_SleepingBoysBag:
	.string "He probably isn't using this.$"

