Route108_MapScripts:: @ 81EE689
	.byte 0

@ -----------------------------------------------------
@ Items

Route108_EventScript_ItemStarPiece:: @ 8290D4D
	giveitem_std ITEM_STAR_PIECE, 1, 1
	end

@ -----------------------------------------------------
@ Trainers

Route108_TrainerScript_Jerome:: @ 81EE68A
	trainerbattle_single TRAINER_JEROME, Route108_Text_296D10, Route108_Text_296D3C
	msgbox Route108_Text_296D6E, MSGBOX_AUTOCLOSE
	end
Route108_Text_296D10: @ 8296D10
	.string "My dream is to swim the world's seven\n"
	.string "seas!$"
Route108_Text_296D3C: @ 8296D3C
	.string "I won't be able to swim the seven seas\n"
	.string "like this…$"
Route108_Text_296D6E: @ 8296D6E
	.string "Playing with marine Pokémon is one of\n"
	.string "the pleasures of swimming!$"



Route108_TrainerScript_Matthew:: @ 81EE6A1
	trainerbattle_single TRAINER_MATTHEW, Route108_Text_296DAF, Route108_Text_296DEA
	msgbox Route108_Text_296E03, MSGBOX_AUTOCLOSE
	end
Route108_Text_296DAF: @ 8296DAF
	.string "Ahoy, there! Are you going out to\n"
	.string "the Abandoned Ship, too?$"
Route108_Text_296DEA: @ 8296DEA
	.string "I'm sinking!\n"
	.string "Glub… Glub…$"
Route108_Text_296E03: @ 8296E03
	.string "Some people even go inside that\n"
	.string "Abandoned Ship.$"



Route108_TrainerScript_Tara:: @ 81EE6B8
	trainerbattle_single TRAINER_TARA, Route108_Text_296E33, Route108_Text_296E71
	selectpointer_ongender Route108_Text_296E7A_Male, Route108_Text_296E7A_Female
	msgbox_selected MSGBOX_AUTOCLOSE
	end
Route108_Text_296E33: @ 8296E33
	.string "My liar of a boyfriend told me that\n"
	.string "I look great in a bikini…$"
Route108_Text_296E71: @ 8296E71
	.string "Oh, boo!$"
Route108_Text_296E7A_Male:
	.string "You think I look great, right?\n"
	.string "Don't you lie to me too!$"
Route108_Text_296E7A_Female: @ 8296E7A
	.string "Even if it's a lie, I love being told\n"
	.string "I look great…\l"
	.string "Don't you agree?$"



Route108_TrainerScript_Missy:: @ 81EE6CF
	trainerbattle_single TRAINER_MISSY, Route108_Text_296EC7, Route108_Text_296EFC
	msgbox Route108_Text_296F2A, MSGBOX_AUTOCLOSE
	end
Route108_Text_296EC7: @ 8296EC7
	.string "I love the sea!\n"
	.string "I forget all my worries when I swim!$"
Route108_Text_296EFC: @ 8296EFC
	.string "When I lose a battle, I get all\n"
	.string "stressed out!$"
Route108_Text_296F2A: @ 8296F2A
	.string "Work off your stress by swimming!\n"
	.string "It's so healthy!$"



Route108_TrainerScript_Carolina:: @ 81EE6E6
	trainerbattle_single TRAINER_CAROLINA, Route108_Text_297094, Route108_Text_2970D7
	msgbox Route108_Text_2970F0, MSGBOX_AUTOCLOSE
	end
Route108_Text_297094: @ 8297094
	.string "I take huge pride in my Pokémon.\n"
	.string "We'll show you one speedy battle!$"
Route108_Text_2970D7: @ 82970D7
	.string "That wasn't cute at all.$"
Route108_Text_2970F0: @ 82970F0
	.string "Since I'm at sea like this, I wouldn't\n"
	.string "mind putting on a pink, frilly swimsuit…$"



Route108_TrainerScript_Cory:: @ 81EE6FD
	trainerbattle_single TRAINER_CORY_1, Route108_Text_296F5D, Route108_Text_296F93, Route108_EventScript_1EE729
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route108_EventScript_1EE748
	msgbox Route108_Text_296FB0, MSGBOX_DEFAULT
	release
	end
Route108_Text_296F5D: @ 8296F5D
	.string "I love Water-type Pokémon.\n"
	.string "I love other Pokémon, too!$"
Route108_Text_296F93: @ 8296F93
	.string "Waaah! I lost!\n"
	.string "Waaah! Waaah!$"
Route108_Text_296FB0: @ 8296FB0
	.string "Shouting is good for me!\n"
	.string "It uplifts me!$"
Route108_EventScript_1EE729:: @ 81EE729
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route108_Text_296FD8, MSGBOX_DEFAULT
	register_matchcall TRAINER_CORY_1
	release
	end
Route108_Text_296FD8: @ 8296FD8
	.string "I love tough trainers, too!\n"
	.string "Register me in your PokéNav!$"
Route108_EventScript_1EE748:: @ 81EE748
	trainerbattle_rematch TRAINER_CORY_1, Route108_Text_297011, Route108_Text_297036
	msgbox Route108_Text_297059, MSGBOX_AUTOCLOSE
	end
Route108_Text_297011: @ 8297011
	.string "Win or lose, I love battling at sea!$"
Route108_Text_297036: @ 8297036
	.string "Waaah! I lost again!\n"
	.string "Waaah! Waaah!$"
Route108_Text_297059: @ 8297059
	.string "If you're faced with a challenge,\n"
	.string "try shouting at the sea!$"

