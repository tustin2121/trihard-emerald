EverGrandeCity_PokemonCenter_2F_MapScripts:: @ 8229CE0
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PokemonCenter_2F_MapScript2_276C3B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PokemonCenter_2F_MapScript1_276BBE
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

EverGrandeCity_PokemonCenter_2F_EventScript_229CF5:: @ 8229CF5
	call OldaleTown_PokemonCenter_2F_EventScript_276EB7
	end

EverGrandeCity_PokemonCenter_2F_EventScript_229CFB:: @ 8229CFB
	call OldaleTown_PokemonCenter_2F_EventScript_2770B2
	end

EverGrandeCity_PokemonCenter_2F_EventScript_229D01:: @ 8229D01
	call OldaleTown_PokemonCenter_2F_EventScript_2771DB
	end

EverGrandeCity_PokemonCenter_2F_MapTable:
	map_script_2 VAR_LAST_WARP_ID, 2, Common_EventScript_SetPowerOffWeather
	.2byte 0

@ -----------------------------------------------------

EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoy::
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SleepingBoy
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoy:
	.string "Not quite sure if he's sleeping…$"

EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoysBag::
	lock
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag, MSGBOX_DEFAULT
	trysteal ITEM_FULL_RESTORE, 2, FLAG_ITEM_STOLEN_FULL_RESTORES
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag:
	.string "He's not gonna miss those…$"


EverGrandeCity_PokemonCenter_2F_EventScript_SnorlaxDoll::
	lock
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll, MSGBOX_CDESCRIBE
	givedecoration_std DECOR_SNORLAX_DOLL
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll2, MSGBOX_CDESCRIBE
	removeobject THIS_EVENT
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll:
	.string "Wow, that's a big plush!\p"
	.string "…\p"
	.string "Yoink!\p"
	.string "Ack!! It's heavy!!$"
EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll2:
	.string "Which is good, because you weren't\n"
	.string "sure how you were going to fit it\l"
	.string "into your bag.$"
