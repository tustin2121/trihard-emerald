EverGrandeCity_PokemonLeague_2F_MapScripts:: @ 8229D07
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PokemonLeague_2F_MapTable
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0


EverGrandeCity_PokemonLeague_2F_MapTable: @ 8255C41
	map_script_2 VAR_LAST_WARP_ID, 3, Common_EventScript_SetPowerOffWeather
	.2byte 0

@ -----------------------------------------------------

EverGrandeCity_PokemonLeague_2F_EventScript_SleepingGirl::
	msgbox EverGrandeCity_PokemonLeague_2F_Text_SleepingGirl
	release
	end
EverGrandeCity_PokemonLeague_2F_Text_SleepingGirl:
	.string "She's sleeping…$"

EverGrandeCity_PokemonLeague_2F_EventScript_SleepingGirlsBag::
	lock
	msgbox EverGrandeCity_PokemonLeague_2F_Text_SleepingGirlsBag, MSGBOX_DEFAULT
	trysteal ITEM_FULL_RESTORE, 2, FLAG_ITEM_STOLEN_FROM_PHOEBE
	msgbox EverGrandeCity_PokemonLeague_2F_Text_SleepingGirlsBag2, MSGBOX_DEFAULT
	release
	end
EverGrandeCity_PokemonLeague_2F_Text_SleepingGirlsBag:
	.string "She's got a boat-load of these…\n"
	.string "She won't miss a couple…$"
EverGrandeCity_PokemonLeague_2F_Text_SleepingGirlsBag2:
	.string "Man, who is this chick? She must be\n"
	.string "some big hot shot with all this stuff.$"

