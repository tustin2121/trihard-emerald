VerdanturfTown_PokemonCenter_2F_MapScripts:: @ 8202897
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_PokemonCenter_2F_FrameTable
	map_script MAP_SCRIPT_ON_LOAD, VerdanturfTown_PokemonCenter_2F_OnLoad
	.byte 0

VerdanturfTown_PokemonCenter_2F_FrameTable:
	map_script_2 VAR_LAST_WARP_ID, 2, VerdanturfTown_PokemonCenter_2F_EventScript_WalkedInOn
	map_script_2 VAR_LAST_WARP_ID, 7, VerdanturfTown_PokemonCenter_2F_EventScript_AfterKickout
	.2byte 0

VerdanturfTown_PokemonCenter_2F_OnLoad:
	call_if_set FLAG_VERDANTURF_CENTER_INCIDENT, VerdanturfTown_PokemonCenter_2F_EventScript_AfterKickout_LockRoom
	end
	

@ -----------------------------------------------------

#define LID_CAM 4
#define LID_REP 6
#define LID_WOMAN 5
VerdanturfTown_PokemonCenter_2F_EventScript_AfterKickout:
	setvar VAR_LAST_WARP_ID, 0
	setflag FLAG_VERDANTURF_CENTER_INCIDENT @fallthrough
	removeobject LID_WOMAN
	setobjectxyperm LID_WOMAN, 18, 6
	setobjectmovementtype LID_WOMAN, MOVEMENT_TYPE_INVISIBLE
	addobject LID_WOMAN
	setmetatile 18, 5, 0x32B, FALSE @Set tile to non-warp tile
	return
VerdanturfTown_PokemonCenter_2F_EventScript_AfterKickout_LockRoom:
	setobjectxyperm LID_WOMAN, 18, 6
	setobjectmovementtype LID_WOMAN, MOVEMENT_TYPE_INVISIBLE
	setmetatile 18, 5, 0x32B, FALSE @Set tile to non-warp tile
	return

@ -----------------------------------------------------

VerdanturfTown_PokemonCenter_2F_EventScript_WalkedInOn:
	lockall
	applymovement LID_CAM, Common_Movement_AngryAndWait
	playse SE_PIN
	delay 4
	applymovement LID_REP, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 4
	applymovement LID_WOMAN, Common_Movement_QuestionMark
	playse SE_PIN
	waitmovement LID_CAM
	@
	applymovement LID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement LID_PLAYER
	markasdialog 10
	message VerdanturfTown_PokemonCenter_2F_Text_WalkedInOn1
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	@
	applymovement LID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement LID_PLAYER
	markasdialog -10
	message VerdanturfTown_PokemonCenter_2F_Text_WalkedInOn2
	waitmessage
	waitbuttonpress
	@
	applymovement LID_REP, VerdanturfTown_PokemonCenter_2F_Movement_WalkedInOn3a
	applymovement LID_PLAYER, VerdanturfTown_PokemonCenter_2F_Movement_WalkedInOn3b
	waitmovement LID_PLAYER
	opendoor 14, 16
	waitdooranim
	applymovement LID_REP, Common_Movement_WalkUp1
	applymovement LID_PLAYER, Common_Movement_WalkUp1
	waitmovement LID_PLAYER
	@
	warptodynamic
	waitstate
	releaseall
	end
VerdanturfTown_PokemonCenter_2F_Text_WalkedInOn1:
	.string "Oi! Down in front!\n"
	.string "You ruined the shot!$"
VerdanturfTown_PokemonCenter_2F_Text_WalkedInOn2:
	.string "We need you to leave, {PLAYER_sir}!\n"
	.string "We're conducting an interview!$"
VerdanturfTown_PokemonCenter_2F_Movement_WalkedInOn3a:
	walk_in_place_up
	walk_in_place_up
	step_end
VerdanturfTown_PokemonCenter_2F_Movement_WalkedInOn3b:
	walk_in_place_left
	walk_in_place_up
	step_end


#undef LID_CAM 
#undef LID_REP 
#undef LID_WOMAN 

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


