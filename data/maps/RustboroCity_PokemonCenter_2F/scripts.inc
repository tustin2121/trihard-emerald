RustboroCity_PokemonCenter_2F_MapScripts:: @ 8214EDE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

RustboroCity_PokemonCenter_2F_MapTable:
	map_script_2 VAR_LAST_WARP_ID, 3, Common_EventScript_SetPowerOffWeather
	.2byte 0

@ -----------------------------------------------------

RustboroCity_PokemonCenter_2F_EventScript_SleepingGirl::
	msgbox RustboroCity_PokemonCenter_2F_Text_SleepingGirl
	release
	end
RustboroCity_PokemonCenter_2F_Text_SleepingGirl:
	.string "She's not sleeping that well…$"

RustboroCity_PokemonCenter_2F_EventScript_SleepingGirlsBag::
	lock
	msgbox RustboroCity_PokemonCenter_2F_Text_SleepingGirlsBag, MSGBOX_DEFAULT
	trysteal ITEM_SODA_POP, 4, FLAG_ITEM_STOLEN_SODA_POP
	release
	end
RustboroCity_PokemonCenter_2F_Text_SleepingGirlsBag:
	.string "I don't think she'll notice if these\n"
	.string "is missing…$"


