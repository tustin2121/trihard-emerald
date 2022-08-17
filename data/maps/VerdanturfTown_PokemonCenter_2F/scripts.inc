VerdanturfTown_PokemonCenter_2F_MapScripts:: @ 8202897
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0



@ -----------------------------------------------------


VerdanturfTown_BattleTentLobby_EventScript_201A7B:: @ 8201A7B
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM45, VerdanturfTown_BattleTentLobby_EventScript_201AB2
	msgbox VerdanturfTown_BattleTentLobby_Text_201D9E, MSGBOX_DEFAULT
	giveitem_std ITEM_TM45
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM45
	msgbox VerdanturfTown_BattleTentLobby_Text_201E43, MSGBOX_DEFAULT
	release
	end
VerdanturfTown_BattleTentLobby_Text_201D9E: @ 8201D9E
	.string "My feelings toward my Pokémon…\n"
	.string "The attraction runs deep…\p"
	.string "Oh, hi, you didn't see that, did you?\n"
	.string "Well, it doesn't matter.\p"
	.string "How would you like this TM for\n"
	.string "your Pokémon?$"
VerdanturfTown_BattleTentLobby_EventScript_201AB2:: @ 8201AB2
	msgbox VerdanturfTown_BattleTentLobby_Text_201E43, MSGBOX_DEFAULT
	release
	end
VerdanturfTown_BattleTentLobby_Text_201E43: @ 8201E43
	.string "My feelings toward my Pokémon…\n"
	.string "I'm sure the attraction is mutual!\p"
	.string "They battle exactly the way I want\n"
	.string "them to!$"


