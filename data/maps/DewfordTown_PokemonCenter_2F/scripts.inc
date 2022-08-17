DewfordTown_PokemonCenter_2F_MapScripts:: @ 81FC615
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE,DewfordTown_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

DewfordTown_PokemonCenter_2F_MapTable:
	map_script_2 VAR_LAST_WARP_ID, 2, Common_EventScript_SetPowerOffWeather
	.2byte 0

@ -----------------------------------------------------

DewfordTown_PokemonCenter_2F_EventScript_SleepingBoy::
	msgbox DewfordTown_PokemonCenter_2F_Text_SleepingBoy
	release
	end
DewfordTown_PokemonCenter_2F_Text_SleepingBoy:
	.string "He's sleeping soundly…$"

DewfordTown_PokemonCenter_2F_EventScript_SleepingBoysBag::
	lock
	msgbox DewfordTown_PokemonCenter_2F_Text_SleepingBoysBag, MSGBOX_DEFAULT
	trysteal ITEM_TIMER_BALL, 4, FLAG_ITEM_STOLEN_TIMER_BALLS
	release
	end
DewfordTown_PokemonCenter_2F_Text_SleepingBoysBag:
	.string "He's not gonna miss those…$"



DewfordTown_PokemonCenter_2F_EventScript_MarillDoll::
	lock
	msgbox DewfordTown_PokemonCenter_2F_Text_MarillDoll, MSGBOX_CDESCRIBE
	givedecoration_std DECOR_MARILL_DOLL
	removeobject THIS_EVENT
	release
	end
DewfordTown_PokemonCenter_2F_Text_MarillDoll:
	.string "Someone left behind a Marill Doll?\p"
	.string "…\p"
	.string "Yoink.$"