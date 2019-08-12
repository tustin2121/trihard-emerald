FallarborTown_PokemonCenter_2F_MapScripts:: @ 8200EEB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FallarborTown_PokemonCenter_2F_MapScript2_276C3B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FallarborTown_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_LOAD, FallarborTown_PokemonCenter_2F_MapScript1_276BBE
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

FallarborTown_PokemonCenter_2F_EventScript_200F00:: @ 8200F00
	call OldaleTown_PokemonCenter_2F_EventScript_276EB7
	end

FallarborTown_PokemonCenter_2F_EventScript_200F06:: @ 8200F06
	call OldaleTown_PokemonCenter_2F_EventScript_2770B2
	end

FallarborTown_PokemonCenter_2F_EventScript_200F0C:: @ 8200F0C
	call OldaleTown_PokemonCenter_2F_EventScript_2771DB
	end

FallarborTown_PokemonCenter_2F_MapTable:
	map_script_2 VAR_LAST_WARP_ID, 2, Common_EventScript_SetPowerOffWeather
	.2byte 0

@ -----------------------------------------------------

FallarborTown_PokemonCenter_2F_EventScript_SleepingGirl::
	msgbox FallarborTown_PokemonCenter_2F_Text_SleepingGirl
	release
	end
FallarborTown_PokemonCenter_2F_Text_SleepingGirl:
	.string "What kind of person sleeps with their\n"
	.string "hat on…?$"

FallarborTown_PokemonCenter_2F_EventScript_SleepingGirlsBag::
	lock
	msgbox FallarborTown_PokemonCenter_2F_Text_SleepingGirlsBag, MSGBOX_DEFAULT
	trysteal ITEM_THUNDER_STONE, 1, FLAG_ITEM_STOLEN_THUNDER_STONE
	release
	end
FallarborTown_PokemonCenter_2F_Text_SleepingGirlsBag:
	.string "Oh, those're pretty…\n"
	.string "But just the one…$"

