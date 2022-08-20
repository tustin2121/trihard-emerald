DewfordTown_House2_MapScripts:: @ 81FE22D
	map_script MAP_SCRIPT_STEAL_CHECK, DewfordTown_House2_StealSpot_StealCheck
	.byte 0

DewfordTown_House2_EventScript_1FE22E:: @ 81FE22E
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_1FE267
	msgbox DewfordTown_House2_Text_1FE27A, MSGBOX_DEFAULT
	giveitem_std ITEM_SILK_SCARF
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_House2_EventScript_1FE25D
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end
DewfordTown_House2_Text_1FE27A: @ 81FE27A
	.string "Gorge your eyes on this!\p"
	.string "It's a SILK SCARF. It's right at the\n"
	.string "cutting edge of fashion, yeah!\p"
	.string "Oh, I can see your eyes twinkling!\n"
	.string "You appreciate my dazzling style!\p"
	.string "Oh, you're a delight!\n"
	.string "Here you go. I want you to have it!$"
DewfordTown_House2_EventScript_1FE25D:: @ 81FE25D
	msgbox DewfordTown_House2_Text_1FE356, MSGBOX_DEFAULT
	release
	end
DewfordTown_House2_Text_1FE356: @ 81FE356
	.string "Oh, you don't have room?\p"
	.string "Now, listen tight, this SCARF is a must-\n"
	.string "have! Why, I would sell all my items\l"
	.string "in order to get it!$"
DewfordTown_House2_EventScript_1FE267:: @ 81FE267
	msgbox DewfordTown_House2_Text_1FE3D1, MSGBOX_DEFAULT
	release
	end
DewfordTown_House2_Text_1FE3D1: @ 81FE3D1
	.string "The SILK SCARF raises the power of\n"
	.string "NORMAL-type moves.\p"
	.string "It's a marvelous SCARF that will go\n"
	.string "with almost all Pokémon!$"


DewfordTown_House2_EventScript_1FE271:: @ 81FE271
	msgbox DewfordTown_House2_Text_1FE444, MSGBOX_NPC
	end
DewfordTown_House2_Text_1FE444: @ 81FE444
	.string "Wow, you bothered to cross the sea\n"
	.string "to visit DEWFORD?\p"
	.string "Did you maybe come here because you\n"
	.string "heard about BRAWLY?\p"
	.string "He's so cool…\n"
	.string "Everyone idolizes him.$"


DewfordTown_House2_StealSpot::
	lock
	msgbox DewfordTown_House2_StealSpot_Text, MSGBOX_DEFAULT
	trysteal_money 1000, FLAG_ITEM_STOLEN_DEWFORD_HOUSE
	release
	end
DewfordTown_House2_StealSpot_Text:
	.string "This vase looks expensive…\n"
	.string "Peered inside…\p"
	.string "Huh. This is a weird place to\n"
	.string "store your savings…$"

DewfordTown_House2_StealSpot_StealCheck:
	@ Check little brother
	setvar VAR_0x8000, 2
	callnative GetObjectFacingAndPosition
	compare VAR_RESULT, DIR_EAST
	goto_if_eq DewfordTown_House2_StealSpot_Caught2
	@ Check older brother
	setvar VAR_0x8000, 1
	callnative GetObjectFacingAndPosition
	compare VAR_RESULT, DIR_NORTH
	goto_if_eq DewfordTown_House2_StealSpot_Caught1
	@ Neither noticed, success
	setvar VAR_RESULT, 1
	return
DewfordTown_House2_StealSpot_Caught2:
	closemessage
	applymovement 2, Common_Movement_ExclamationMarkAndWait
	playse SE_PIN
	waitmovement 2
	markasdialog 7
	goto DewfordTown_House2_StealSpot_Caught
DewfordTown_House2_StealSpot_Caught1:
	closemessage
	applymovement 1, Common_Movement_ExclamationMarkAndWait
	playse SE_PIN
	waitmovement 1 @fallthrough
	markasdialog -8
DewfordTown_House2_StealSpot_Caught:
	message DewfordTown_House2_StealSpot_Caught_Text
	waitmessage
	waitbuttonpress
	closemessage
	setvar VAR_CROSS_MAP_TRIGGER, 1
	warp MAP_DEWFORD_TOWN, 4, -1, -1
	waitstate
	release
	end
DewfordTown_House2_StealSpot_Caught_Text:
	.string "Hey! What are you doing?!$"
