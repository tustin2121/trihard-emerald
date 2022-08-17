OldaleTown_PokemonCenter_2F_MapScripts:: @ 81FC218
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

@ -----------------------------------------------------

OldaleTown_PokemonCenter_2F_EventScript_RoadblockDoor::
	goto_if_unset FLAG_ADVENTURE_STARTED, PokemonCenter_2F_EventScript_OccupiedSign
	msgbox OldaleTown_PokemonCenter_2F_Text_RoadblockDoor, MSGBOX_DESCRIBE
	end
OldaleTown_PokemonCenter_2F_Text_RoadblockDoor:
	.string "The door is open, but you can't get\n"
	.string "through even if you wanted to.\p"
	.string "There's three people inside tending\n"
	.string "to a boy who looks very badly hurt.$"

OldaleTown_PokemonCenter_2F_EventScript_Mother::
	msgbox OldaleTown_PokemonCenter_2F_Text_Mother, MSGBOX_DESCRIBE
	end
OldaleTown_PokemonCenter_2F_Text_Mother:
	.string "This woman looks like she's incredibly\n"
	.string "distressed.$"

@ -----------------------------------------------------

OldaleTown_PokemonCenter_2F_EventScript_MudkipDoll::
	lock
	msgbox OldaleTown_PokemonCenter_2F_Text_MudkipDoll, MSGBOX_CDESCRIBE
	givedecoration_std DECOR_MUDKIP_DOLL
	removeobject THIS_EVENT
	release
	end
OldaleTown_PokemonCenter_2F_Text_MudkipDoll:
	.string "Someone left behind a Mudkip Doll?\p"
	.string "…\p"
	.string "Yoink.$"

