SlateportCity_PokemonCenter_2F_MapScripts:: @ 820DC21
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_PokemonCenter_2F_MapScript2_276C3B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_PokemonCenter_2F_MapScript2_276B6C
	map_script MAP_SCRIPT_ON_LOAD, SlateportCity_PokemonCenter_2F_MapScript1_276BBE
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

SlateportCity_PokemonCenter_2F_EventScript_20DC36:: @ 820DC36
	call OldaleTown_PokemonCenter_2F_EventScript_276EB7
	end

SlateportCity_PokemonCenter_2F_EventScript_20DC3C:: @ 820DC3C
	call OldaleTown_PokemonCenter_2F_EventScript_2770B2
	end

SlateportCity_PokemonCenter_2F_EventScript_20DC42:: @ 820DC42
	call OldaleTown_PokemonCenter_2F_EventScript_2771DB
	end

@ -----------------------------------------------------

SlateportCity_BattleTentLobby_EventScript_LikeGuy:: @ 8208A3D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM41, SlateportCity_BattleTentLobby_EventScript_208A74
	msgbox SlateportCity_BattleTentLobby_Text_208B4E, MSGBOX_DEFAULT
	giveitem_std ITEM_TM41
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM41
	msgbox SlateportCity_BattleTentLobby_Text_208C5C, MSGBOX_DEFAULT
	release
	end
SlateportCity_BattleTentLobby_EventScript_208A74:: @ 8208A74
	msgbox SlateportCity_BattleTentLobby_Text_208C5C, MSGBOX_DEFAULT
	release
	end
SlateportCity_BattleTentLobby_Text_208B4E: @ 8208B4E
	.string "So, like, I couldn't find myself any\n"
	.string "Pokémon that were, like, for me.\p"
	.string "So, I figured, like, hey, I should file\n"
	.string "a complaint to the guy there?\p"
	.string "And he wouldn't hear me out, like, hey!\n"
	.string "So, like, total bummer, man!\p"
	.string "Hey, like, you! Zip it, you know?\n"
	.string "Just, you know, take this!$"
SlateportCity_BattleTentLobby_Text_208C5C: @ 8208C5C
	.string "That's, like, TM41, you know?\n"
	.string "Hey, it's Torment, you hearing me?\p"
	.string "Like, it won't let the other guy\n"
	.string "use the same move twice in a row, see?\p"
	.string "Hey, now, you listen here, like,\n"
	.string "I'm not laying a torment on you!$"

