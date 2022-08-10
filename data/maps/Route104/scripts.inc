
#define LID_BRINEY 8
#define LID_RIVAL 34

Route104_MapScripts:: @ 81ECC32
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route104_MapScript2_FrameTable
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_OnTransition
	.byte 0

Route104_MapScript2_FrameTable: @ 81ECC3D
	map_script_2 VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE, 1, Route104_EventScript_BrineyDepartForDewford
	.2byte 0

@ -----------------------------------------------------

Route104_OnTransition: @ 81ECC4E
	call Common_EventScript_SetupRivalGender
	call Route104_EventScript_1ECC78
	call Route104_EventScript_1ECC5E
	end

Route104_EventScript_1ECC78:: @ 81ECC78
	compare VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE, 1
	goto_if_ge Common_EventScript_NopReturn
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, Common_EventScript_NopReturn
	goto_if_unset FLAG_REGISTER_RIVAL_POKENAV, Common_EventScript_NopReturn
	setobjectxyperm LID_RIVAL, 17, 52
	return

Route104_EventScript_1ECC5E:: @ 81ECC5E
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_EventScript_1ECC74
	goto_if_unset FLAG_BADGE03_GET, Route104_EventScript_1ECC74
	clearflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return
Route104_EventScript_1ECC74:: @ 81ECC74
	setflag FLAG_HIDE_ROUTE_104_WHITE_HERB_FLORIST
	return

@ -----------------------------------------------------
@ Signs

Route104_SignScript_BrineyCottage:: @ 81ED018
	msgbox Route104_Text_1EDA8C, MSGBOX_SIGN
	end
Route104_Text_1EDA8C: @ 81EDA8C
	.string "{PLACE}Mr. Briney's Cottage$"


Route104_SignScript_FlowerShop:: @ 81ED033
	msgbox Route104_Text_1EDAD6, MSGBOX_SIGN
	end
Route104_Text_1EDAD6: @ 81EDAD6
	.string "{PLACE}Pretty Petal Flower Shop$"


Route104_SignScript_Signpost1:: @ 81ED021
	msgbox Route104_Text_1EDAA1, MSGBOX_SIGN
	end
Route104_Text_1EDAA1: @ 81EDAA1
	.string "Route 1O4\n"
	.string "{RIGHT_ARROW} Petalburg City$"


Route104_SignScript_Signpost2:: @ 81ED02A
	msgbox Route104_Text_1EDABC, MSGBOX_SIGN
	end
Route104_Text_1EDABC: @ 81EDABC
	.string "Route 1O4\n"
	.string "{UP_ARROW} Rustboro City$"


Route104_SignScript_TipsSign:: @ 81ED03C
	msgbox Route104_Text_1EDAEF, MSGBOX_DESCRIBE
	end
Route104_Text_1EDAEF: @ 81EDAEF
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "In the Hoenn region there are pairs\n"
	.string "of trainers who challenge others\l"
	.string "for 2-on-2 Pokémon battles called\l"
	.string "double battles.\p"
	.string "In a double battle, the trainer must\n"
	.string "send out two Pokémon, the one at the\l"
	.string "left of the list and the top one.\l"
	.string "Watch how Pokémon are lined up.$"

@ -----------------------------------------------------
@ Items

Route104_EventScript_ItemPPUp:: @ 8290CFF
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route104_EventScript_ItemPokeBall:: @ 8290D0C
	giveitem_std ITEM_POKE_BALL, 1, 1
	end

Route104_EventScript_ItemXAccuracy:: @ 8290D19
	giveitem_std ITEM_X_ACCURACY, 1, 1
	end

Route104_EventScript_ItemPotion:: @ 8290D26
	giveitem_std ITEM_POTION, 1, 1
	end

@ -----------------------------------------------------
@ People

Route104_EventScript_OldChestoLady:: @ 81ECF8C
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104, Route104_EventScript_1ECFC3
	msgbox Route104_Text_2A6D86, MSGBOX_DEFAULT
	giveitem_std ITEM_CHESTO_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CHESTO_BERRY_ROUTE_104
	msgbox Route104_Text_2A6E32, MSGBOX_DEFAULT
	release
	end
Route104_EventScript_1ECFC3:: @ 81ECFC3
	msgbox Route104_Text_2A6E32, MSGBOX_DEFAULT
	release
	end
Route104_Text_2A6D86: @ 82A6D86
	.string "If you see berries growing in loamy\n"
	.string "soil, feel free to take them.\p"
	.string "But make sure you plant a berry in the\n"
	.string "same spot. That's common courtesy.\p"
	.string "Here, I'll share this with you.$"
Route104_Text_2A6E32: @ 82A6E32
	.string "The way you look, you must be a\n"
	.string "trainer, no?\p"
	.string "Trainers often make Pokémon hold\n"
	.string "berries.\p"
	.string "It's up to you whether to grow berries\n"
	.string "or use them.$"


Route104_EventScript_FlowerShopLady:: @ 81ECFCD
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_WHITE_HERB, Route104_EventScript_1ECFFC
	msgbox Route104_Text_1ED96A, MSGBOX_DEFAULT
	giveitem_std ITEM_WHITE_HERB
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_WHITE_HERB
	release
	end
Route104_Text_1ED96A: @ 81ED96A
	.string "This flower shop started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping.\p"
	.string "I don't need this {REF}white herb{END} anymore.\n"
	.string "Would you take it, please?$"
Route104_EventScript_1ECFFC:: @ 81ECFFC
	msgbox Route104_Text_1EDA0F, MSGBOX_DEFAULT
	release
	end
Route104_Text_1EDA0F: @ 81EDA0F
	.string "This flower shop started selling\n"
	.string "saplings recently.\p"
	.string "It made me so happy, I went overboard\n"
	.string "shopping. Where should I put them?$"


Route104_EventScript_SeasideGirl:: @ 81ED006
	msgbox Route104_Text_1ED5EC, MSGBOX_NPC
	end
Route104_Text_1ED5EC: @ 81ED5EC
	.string "That seaside cottage is where\n"
	.string "Mr. Briney lives.\p"
	.string "He was once a mighty sailor who never\n"
	.string "feared the sea, however stormy.$"


Route104_EventScript_SeasideContemplator:: @ 81ED00F
	msgbox Route104_Text_1ED662, MSGBOX_DIALOG
	end
Route104_Text_1ED662: @ 81ED662
	.string "The sea, huh?\p"
	.string "I wonder what it's like at the bottom\n"
	.string "of the sea?$"


Route104_EventScript_GrassBoy:: @ 81ED045
	msgbox Route104_Text_1ED6A2, MSGBOX_NPC
	end
Route104_Text_1ED6A2: @ 81ED6A2
	.string "If you're going to throw a Poké Ball,\n"
	.string "weaken the wild Pokémon first.\p"
	.string "It will be easier to catch if it's been\n"
	.string "poisoned, burned, or lulled to sleep.$"


Route104_EventScript_TheifLady:: @ 81ED04E
	msgbox Route104_Text_1ED735, MSGBOX_NPC
	end
Route104_Text_1ED735: @ 81ED735
	.string "You're a thief if you try to steal\n"
	.string "someone else's Pokémon.\p"
	.string "You should throw Poké Balls only at\n"
	.string "wild Pokémon.$"


Route104_EventScript_TMKid:: @ 81ED057
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM09, Route104_EventScript_1ED086
	msgbox Route104_Text_1ED838, MSGBOX_DEFAULT
	giveitem_std ITEM_TM09
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM09
	release
	end
Route104_Text_1ED838: @ 81ED838
	.string "I like filling my mouth with seeds,\n"
	.string "then spitting them out fast!\p"
	.string "You can have this, so you try it out!\p"
	.string "Use it on a Pokémon, and it will learn\n"
	.string "a move for firing seeds rapidly.$"
Route104_EventScript_1ED086:: @ 81ED086
	msgbox Route104_Text_1ED8E7, MSGBOX_DEFAULT
	release
	end
Route104_Text_1ED8E7: @ 81ED8E7
	.string "A word of advice!\p"
	.string "A TM, or Technical Machine, can be used\n"
	.string "as many times as you want.\p"
	.string "So don't hesitate to fill out your\n"
	.string "party's moveset with TMs you like!$"


Route104_EventScript_NotTrainer:: @ 81ED090
	msgbox Route104_Text_1ED7A2, MSGBOX_NPC
	end
Route104_Text_1ED7A2: @ 81ED7A2
	.string "Oh, no, I'm not a trainer.\p"
	.string "But that's right, if trainers lock eyes,\n"
	.string "it's a challenge to battle.\p"
	.string "If you don't want to battle, stay out\n"
	.string "of their sight.$"

@ -----------------------------------------------------
@ Trainers

Route104_TrainerScript_Ivan:: @ 81ED35F
	trainerbattle_single TRAINER_IVAN, Route104_Text_2954BD, Route104_Text_295509
	msgbox Route104_Text_29554E, MSGBOX_AUTOCLOSE
	end
Route104_Text_2954BD: @ 82954BD
	.string "Ah! An adoring fan!\n"
	.string "I'm {BOLD}The{END} Water Pokémon expert!\p"
	.string "Huh?\n"
	.string "You don't know me?$"
Route104_Text_295509: @ 8295509
	.string "I thought I wasn't too bad, if I may\n"
	.string "say so, but I guess not… Bleah…$"
Route104_Text_29554E: @ 829554E
	.string "I got too into fishing.\n"
	.string "I forgot I had to raise my Pokémon…$"



Route104_TrainerScript_Billy:: @ 81ED376
	trainerbattle_single TRAINER_BILLY, Route104_Text_29558A, Route104_Text_2955B4
	msgbox Route104_Text_2955E8, MSGBOX_AUTOCLOSE
	end
Route104_Text_29558A: @ 829558A
	.string "Leaving footprints in the sand is\n"
	.string "so fun!$"
Route104_Text_2955B4: @ 82955B4
	.string "Waah! I got sand in my shoes!\n"
	.string "They're all gritty!$"
Route104_Text_2955E8: @ 82955E8
	.string "I want to leave my footprints in\n"
	.string "the sand everywhere, but they\l"
	.string "disappear quickly…$"



Route104_TrainerScript_Haley:: @ 81ED38D
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_29563A, Route104_Text_29566F, Route104_EventScript_1ED3CE
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ED424
	msgbox Route104_Text_295689, MSGBOX_DEFAULT
	release
	end
Route104_Text_29563A: @ 829563A
	.string "Should I…\n"
	.string "Or shouldn't I?\p"
	.string "Okay, sure, I will battle!$"
Route104_Text_29566F: @ 829566F
	.string "I shouldn't have battled…$"
Route104_Text_295689: @ 8295689
	.string "If you're faced with a decision and\n"
	.string "you let someone else choose for you,\l"
	.string "you will regret it, however things\l"
	.string "turn out.$"
Route104_EventScript_1ED3CE:: @ 81ED3CE
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route104_Text_29576B, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end
Route104_Text_29576B: @ 829576B
	.string "You're strong, but should I register\n"
	.string "you in my PokéNav?\l"
	.string "Maybe I shouldn't…\p"
	.string "Okay, sure, I will register you!$"
Route104_EventScript_1ED424:: @ 81ED424
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_2957D7, Route104_Text_2957F0
	msgbox Route104_Text_29580C, MSGBOX_AUTOCLOSE
	end
Route104_Text_2957D7: @ 82957D7
	.string "Come on, battle with me!$"
Route104_Text_2957F0: @ 82957F0
	.string "Ohh…\n"
	.string "I thought I could win…$"
Route104_Text_29580C: @ 829580C
	.string "I made the decision to battle, so\n"
	.string "I can accept this loss with grace.\p"
	.string "I am still upset about losing!$"



Route104_TrainerScript_Winston:: @ 81ED43B
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_295870, Route104_Text_2958AD, Route104_EventScript_1ED47C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ED4D2
	msgbox Route104_Text_2958C1, MSGBOX_DEFAULT
	release
	end
Route104_Text_295870: @ 8295870
	.string "Oh, sure, I'll accept your challenge.\n"
	.string "I have a lot of money.$"
Route104_Text_2958AD: @ 82958AD
	.string "Why couldn't I win?$"
Route104_Text_2958C1: @ 82958C1
	.string "There are some things money can't buy.\n"
	.string "For everything else there's Master Ball.$"
Route104_EventScript_1ED47C:: @ 81ED47C
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route104_Text_29595A, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end
Route104_Text_29595A: @ 829595A
	.string "You had enough money to buy a PokéNav?\n"
	.string "I didn't think you had it in you.\p"
	.string "I will gladly register you.\n"
	.string "After all, I have plenty of money too.$"
Route104_EventScript_1ED4D2:: @ 81ED4D2
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_2959BC, Route104_Text_2959FC
	msgbox Route104_Text_295A1E, MSGBOX_AUTOCLOSE
	end
Route104_Text_2959BC: @ 82959BC
	.string "After I lost to you, I learned a bunch\n"
	.string "of things about Pokémon.$"
Route104_Text_2959FC: @ 82959FC
	.string "I lost again?\n"
	.string "Why couldn't I win?$"
Route104_Text_295A1E: @ 8295A1E
	.string "I'm fabulously wealthy, but I can't\n"
	.string "seem to win at Pokémon…\p"
	.string "It's so befuddling…$"



Route104_TrainerScript_Cindy:: @ 81ED4E9
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_295A7E, Route104_Text_295ABB, Route104_EventScript_1ED52A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ED580
	msgbox Route104_Text_295AC3, MSGBOX_DEFAULT
	release
	end
Route104_Text_295A7E: @ 8295A7E
	.string "We must have been fated to meet.\n"
	.string "May I ask you for a battle?$"
Route104_Text_295ABB: @ 8295ABB
	.string "Oh, my!$"
Route104_Text_295AC3: @ 8295AC3
	.string "“Hello” is the beginning of “good-bye.”\n"
	.string "I hope we meet again.$"
Route104_EventScript_1ED52A:: @ 81ED52A
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route104_Text_295B60, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end
Route104_Text_295B60: @ 8295B60
	.string "We should commemorate how we seem\n"
	.string "to be drawn to each other.\p"
	.string "Let's register each other in our\n"
	.string "PokéNavs.$"
Route104_EventScript_1ED580:: @ 81ED580
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_295BC8, Route104_Text_295BFA
	msgbox Route104_Text_295C1F, MSGBOX_AUTOCLOSE
	end
Route104_Text_295BC8: @ 8295BC8
	.string "Hello, we meet again.\n"
	.string "May I ask you for a battle?$"
Route104_Text_295BFA: @ 8295BFA
	.string "Oh, my…\n"
	.string "I did the best that I could…$"
Route104_Text_295C1F: @ 8295C1F
	.string "“Hello” is the beginning of “good-bye.”\n"
	.string "I hope we meet again.$"



Route104_TrainerScript_Gina:: @ 81ED597
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_2952BB, Route104_Text_2952E6, Route104_Text_295330
	msgbox Route104_Text_2952FE, MSGBOX_DEFAULT
	release
	end
Route104_Text_2952BB: @ 82952BB
	.string "Gina: Okay, let's battle with our\n"
	.string "Pokémon!$"
Route104_Text_2952E6: @ 82952E6
	.string "Gina: Losing upsets me!$"
Route104_Text_2952FE: @ 82952FE
	.string "Gina: You are strong!\n"
	.string "We have to train lots more!$"
Route104_Text_295330: @ 8295330
	.string "Gina: Oh? Only one Pokémon?\n"
	.string "Then, we don't battle with you.\p"
	.string "If there's only one Pokémon, it will\n"
	.string "be lonesome. That's not nice.$"
Route104_TrainerScript_Mia:: @ 81ED5B6
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_2953AF, Route104_Text_2953E1, Route104_Text_295449
	msgbox Route104_Text_29540D, MSGBOX_DEFAULT
	release
	end
Route104_Text_2953AF: @ 82953AF
	.string "Mia: We are twins, so we battle\n"
	.string "Pokémon together.$"
Route104_Text_2953E1: @ 82953E1
	.string "Mia: We battled together, but we\n"
	.string "both lost…$"
Route104_Text_29540D: @ 829540D
	.string "Mia: We will train our Pokémon more\n"
	.string "and be strong like you.$"
Route104_Text_295449: @ 8295449
	.string "Mia: You want to battle with us?\p"
	.string "It's a big no-no if you don't have two\n"
	.string "Pokémon with you.\l"
	.string "We're too strong for you!$"



Route104_TrainerScript_Darian:: @ 81ED5D5
	trainerbattle_single TRAINER_DARIAN, Route104_Text_295C5D, Route104_Text_295CC9
	msgbox Route104_Text_295CD3, MSGBOX_AUTOCLOSE
	end
Route104_Text_295C5D: @ 8295C5D
	.string "I fished up a tough-looking Pokémon!\p"
	.string "It has this magical quality to it!\n"
	.string "It surely looks tough, yes it does!$"
Route104_Text_295CC9: @ 8295CC9
	.string "What the…$"
Route104_Text_295CD3: @ 8295CD3
	.string "Hey, Magikarp, you sure don't live up\n"
	.string "to your name, do you?$"


@ -----------------------------------------------------
@ Briney Sailing

Route104_EventScript_BrineyDepartForDewford:: @ 81ECC47
	lockall
	setobjectpriority LID_BRINEY, MAP_ROUTE104, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_ROUTE104, 0
	applymovement LID_BRINEY, Route104_Movement_1ED359
	waitmovement 0
	removeobject LID_BRINEY
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ED34F
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	goto Briney_EventScript_Route104_Dewford
	@ continue sequence in briney_boat.inc
	end
Route104_Movement_1ED359: @ 81ED359
	walk_down
	walk_down
	step_end
Route104_Movement_1ED34F: @ 81ED34F
	walk_left
	walk_down
	walk_down
	step_end


Route104_EventScript_BrineyArriveFromDewford::
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9914
	waitmovement 0
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	clearflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat 4, MAP_DEWFORD_TOWN
	setvar VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE, 2
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	warp MAP_ROUTE104_MR_BRINEYS_HOUSE, 255, 5, 4
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	waitstate
	release
	end


@ -----------------------------------------------------
@ Cutscene: Meet Logan

#define LID_LOGAN 35

Route104_TriggerScript_MeetLogan_ExitForest::
	lock
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_Y, 42
	call Route104_EventScript_MeetLogan_Main1
	@ Run up to player
	setobjectxyperm THIS_EVENT, 22, 52
	addobject THIS_EVENT
	selectpointer Route104_MovementTable_MeetLogan_ExitForest1_Logan, VAR_INTERACT_Y
	applymovement THIS_EVENT, 0
	waitmovement 0
	selectpointer Route104_MovementTable_MeetLogan_ExitForest1_Player, VAR_INTERACT_Y
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	@ Talk
	call Route104_EventScript_MeetLogan_Main2
	@ Run away
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_MeetLogan_ExitForest2_Player
	selectpointer Route104_MovementTable_MeetLogan_ExitForest2_Logan, VAR_INTERACT_Y
	applymovement THIS_EVENT, 0
	waitmovement 0
	goto Route104_EventScript_MeetLogan_Main3

Route104_TriggerScript_MeetLogan_ExitLedge::
	lock
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_X, 30
	call Route104_EventScript_MeetLogan_Main1
	@ Run up to ledge
	setobjectxyperm THIS_EVENT, 26, 56
	addobject THIS_EVENT
	selectpointer Route104_MovementTable_MeetLogan_ExitLedge1_Player, VAR_INTERACT_X
	applymovement EVENT_OBJ_ID_PLAYER, 0
	applymovement THIS_EVENT, Route104_Movement_MeetLogan_ExitLedge1_Logan
	applymovement 2, Common_Movement_WalkDown2
	waitmovement EVENT_OBJ_ID_PLAYER
	waitmovement THIS_EVENT
	@ Talk
	call Route104_EventScript_MeetLogan_Main2
	@ Run through the NPC girl inevitably
	applymovement THIS_EVENT, Route104_Movement_MeetLogan_ExitLedge2_Logan
	waitmovement 0
	goto Route104_EventScript_MeetLogan_Main3


Route104_EventScript_MeetLogan_Main1:
	markasdialog
	setvar VAR_LAST_TALKED, LID_LOGAN
	message Route104_Text_MeetLogan1
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	waitbuttonpress
	closemessage
	return
Route104_EventScript_MeetLogan_Main2:
	msgbox Route104_Text_MeetLogan2
	closemessage
	return
Route104_EventScript_MeetLogan_Main3:
	@ Clean up
	setvar VAR_LOGAN_STATE, 3
	removeobject THIS_EVENT
	setobjectxyperm THIS_EVENT, 39, 34
	moveobjectoffscreen THIS_EVENT
	release
	end

Route104_Text_MeetLogan1:
	.string "Hey! Hey, uh, {PLAYER}? {PLAYER}!$"
Route104_Text_MeetLogan2:
	.string "Hey! You're the {PLAYER_guy} who saved\n"
	.string "me, right?\p"
	.string "I'm {RIVAL_HERO}. I don't know how to\n"
	.string "thank you enough.\p"
	.string "I was trying to get a Pokémon of my\n"
	.string "own so I could run away from home.\p"
	.string "I can't stand my family. They're too\n"
	.string "nosey and never let me do anything.\p"
	.string "Of course that Gym Leader was a jerk\n"
	.string "and wouldn't help me, but I think\l"
	.string "he's being kicked out now.\p"
	.string "Anyway, I'm running away on my own\n"
	.string "journey now, to become champion!\p"
	.string "Don't tell my parents, alright?\n"
	.string "I don't need them breathing down\l"
	.string "my neck…\p"
	.string "See ya around!$"

.align 2
Route104_MovementTable_MeetLogan_ExitForest1_Player:
	.4byte Common_Movement_WalkInPlaceDown
	.4byte Common_Movement_WalkInPlaceDown
	.4byte Common_Movement_WalkInPlaceRight
	.4byte Common_Movement_WalkInPlaceRight
	.4byte Common_Movement_WalkInPlaceUp
	.4byte 0
Route104_MovementTable_MeetLogan_ExitForest1_Logan:
	.4byte Route104_Movement_MeetLogan_ExitForest1_Logan1
	.4byte Route104_Movement_MeetLogan_ExitForest1_Logan2
	.4byte Route104_Movement_MeetLogan_ExitForest1_Logan3
	.4byte Route104_Movement_MeetLogan_ExitForest1_Logan4
	.4byte Route104_Movement_MeetLogan_ExitForest1_Logan5
	.4byte 0
Route104_MovementTable_MeetLogan_ExitForest2_Logan:
	.4byte Route104_Movement_MeetLogan_ExitForest2_Logan1
	.4byte Route104_Movement_MeetLogan_ExitForest2_Logan1
	.4byte Route104_Movement_MeetLogan_ExitForest2_Logan2
	.4byte Route104_Movement_MeetLogan_ExitForest2_Logan2
	.4byte Route104_Movement_MeetLogan_ExitForest2_Logan2
	.4byte 0
Route104_MovementTable_MeetLogan_ExitLedge1_Player:
	.4byte Route104_Movement_MeetLogan_ExitLedge1_Player1
	.4byte Route104_Movement_MeetLogan_ExitLedge1_Player2
	.4byte Route104_Movement_MeetLogan_ExitLedge1_Player3
	.4byte Route104_Movement_MeetLogan_ExitLedge1_Player4
	.4byte 0


Route104_Movement_MeetLogan_ExitForest1_Logan1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_up
	delay_4
	step_end
Route104_Movement_MeetLogan_ExitForest1_Logan2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_up
	delay_4
	step_end
Route104_Movement_MeetLogan_ExitForest1_Logan3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	delay_4
	step_end
Route104_Movement_MeetLogan_ExitForest1_Logan4:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	delay_4
	step_end
Route104_Movement_MeetLogan_ExitForest1_Logan5:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_down
	delay_4
	step_end

Route104_Movement_MeetLogan_ExitForest2_Logan1:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route104_Movement_MeetLogan_ExitForest2_Logan2:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route104_Movement_MeetLogan_ExitForest2_Player:
	delay_8
	walk_in_place_fastest_left
	step_end

Route104_Movement_MeetLogan_ExitLedge1_Player1:
	walk_down
	walk_left
	step_end
Route104_Movement_MeetLogan_ExitLedge1_Player2:
	walk_down
	walk_left
	walk_left
	step_end
Route104_Movement_MeetLogan_ExitLedge1_Player3:
	walk_down
	walk_left
	walk_left
	walk_left
	step_end
Route104_Movement_MeetLogan_ExitLedge1_Player4:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
Route104_Movement_MeetLogan_ExitLedge1_Logan:
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	delay_4
	step_end
Route104_Movement_MeetLogan_ExitLedge2_Logan:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

#undef LID_LOGAN

@ -----------------------------------------------------
@ Cutscene: Meet Rival

Route104_EventScript_Rival:: @ 81ECC9E
	lockall
	setvar VAR_0x8008, 1
	applymovement LID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto Route104_EventScript_RivalMain

Route104_TriggerScript_MrBrineyRival:: @ 81ECCB3
	lockall
	setflag FLAG_HIDE_RUSBORO_CITY_RIVAL
	setvar VAR_RUSTBORO_STATE, 8
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	addobject LID_RIVAL
	clearflag FLAG_HIDE_ROUTE_104_RIVAL
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ECF86
	waitmovement 0
	applymovement LID_RIVAL, Common_Movement_WalkDown1
	waitmovement 0
	delay 20
	setvar VAR_0x8008, 0
	call Common_EventScript_PlayRivalMusic
	playse SE_PIN
	applymovement LID_RIVAL, Common_Movement_ExclamationMarkAndWait
	goto Route104_EventScript_RivalMain
Route104_Movement_1ECF86: @ 81ECF86
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Route104_EventScript_RivalMain:: @ 81ECD33
	markasdialog
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_PostRivalBattle
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_RivalMain2
	setflag FLAG_REGISTER_RIVAL_POKENAV
	selectpointer_ongender Route104_Text_RivalMain1_Male, Route104_Text_RivalMain1_Female
	msgbox_selected
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	selectpointer_ongender Route104_Text_RivalMain2_Male, Route104_Text_RivalMain2_Female
	msgbox_selected MSGBOX_DESCRIBE
	waitfanfare
	closemessage
	delay 30
	markasdialog
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ECDCD
	applymovement LID_RIVAL, Route104_Movement_1ECDC8
	selectpointer_ongender Route104_Text_RivalMain3_Male, Route104_Text_RivalMain3_Female
	msgbox_selected
	closemessage
	waitmovement 0
	applymovement LID_RIVAL, Route104_Movement_1ECDCA
	waitmovement 0
	moveobjectoffscreen 34
	selectpointer_ongender Route104_Text_RivalMain4_Male, Route104_Text_RivalMain4_Female
	msgbox_selected MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_EventScript_RivalBattle
	selectpointer_ongender Route104_Text_RivalMain5_Male, Route104_Text_RivalMain5_Female
	msgbox_selected
	call Common_EventScript_FadeMusicToMapMusic
	releaseall
	end
Route104_Text_RivalMain1_Male: @ 81EDBFF
	.string "May: Oh, {P_PLAYER}!\n"
	.string "Hey! How have you been doing?\p"
	.string "I was just visiting Mr. Briney.\n"
	.string "He was telling me how you saved his\l"
	.string "Wingull.\p"
	.string "I… didn't think you had it in you…\n"
	.string "Uh… “it” being spunkiness! Yes!\p"
	.string "We should swap numbers! Just in\n"
	.string "case! Never know, right? Hahaha!$"
Route104_Text_RivalMain1_Female: @ 81EDF04
	.string "Brendan: Gah, {P_PLAYER}! Hi!\p"
	.string "H-How have you been? Got a new badge,\n"
	.string "huh? That's good.\p"
	.string "I was just visiting Mr. Briney.\n"
	.string "He told me you saved his Peeko.\p"
	.string "I… honestly didn't think you were\n"
	.string "capable of compa- erm… compass! Skills!\p"
	.string "Anyway, swap numbers? Ha! Haaa…$"
Route104_Text_RivalMain2_Male: @ 81EDC8F
	.string "{PLAYER} registered May\n"
	.string "in the PokéNav.$"
Route104_Text_RivalMain2_Female: @ 81EDFA0
	.string "{PLAYER} registered Brendan\n"
	.string "in the PokéNav.$"
Route104_Movement_1ECDCD: @ 81ECDCD
	delay_4
	walk_in_place_fastest_left
	step_end
Route104_Movement_1ECDC8: @ 81ECDC8
	walk_slow_left
	step_end
Route104_Text_RivalMain3_Male: @ 81EDCB1
	.string "May: So, uh, {PLAYER}, how many Pokémon\n"
	.string "have you ki- caught?$"
Route104_Text_RivalMain3_Female: @ 81EDFC6
	.string "Brendan: {PLAYER}, how's your Pokémon…\n"
	.string "collection coming?$"
Route104_Movement_1ECDCA: @ 81ECDCA
	walk_down
	face_right
	step_end
Route104_Text_RivalMain4_Male: @ 81EDCED
	.string "How about a little battle?\p"
	.string "I just wanna see how far you've come.$"
Route104_Text_RivalMain4_Female: @ 81EE009
	.string "Want to check out how good I am with\n"
	.string "a battle?$"
Route104_Text_RivalMain5_Male: @ 81EDD2A
	.string "May: Oh, what's the matter?\p"
	.string "You too chicken?\p"
	.string "That's not very good for a trainer!$"
Route104_Text_RivalMain5_Female: @ 81EE04D
	.string "Brendan: What's the matter? Don't have\n"
	.string "any confidence in yourself?$"

Route104_EventScript_RivalMain2:: @ 81ECDD0
	selectpointer_ongender Route104_Text_RivalMain6_Male, Route104_Text_RivalMain6_Female
	msgbox_selected MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq Route104_EventScript_RivalBattle
	selectpointer_ongender Route104_Text_RivalMain5_Male, Route104_Text_RivalMain5_Female
	msgbox_selected
	releaseall
	end
Route104_Text_RivalMain6_Male: @ 81EDD9F
	.string "May: So, what do you think?\n"
	.string "How about a little battle here?$"
Route104_Text_RivalMain6_Female: @ 81EE094
	.string "Brendan: What's up?\n"
	.string "Want to have a battle with me?$"

Route104_EventScript_RivalBattle:: @ 81ECDED
	call_on_gender Route104_EventScript_RivalBattle_Male, Route104_EventScript_RivalBattle_Female
	end

Route104_EventScript_RivalBattle_Male:
	msgbox Route104_Text_RivalMain7_Male, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route104_EventScript_1ECE36
	case 1, Route104_EventScript_1ECE49
	case 2, Route104_EventScript_1ECE5C
	end
Route104_Text_RivalMain7_Male: @ 81EDDDB
	.string "May: I'm not going to lose to someone\n"
	.string "like you!$"

Route104_EventScript_RivalBattle_Female: @ 81ECF09
	msgbox Route104_Text_RivalMain7_Female, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route104_EventScript_1ECF4D
	case 1, Route104_EventScript_1ECF60
	case 2, Route104_EventScript_1ECF73
	end
Route104_Text_RivalMain7_Female: @ 81EE0C7
	.string "Brendan: I won't go easy on someone\n"
	.string "like you!$"

Route104_EventScript_1ECE36:: @ 81ECE36
	trainerbattle_no_intro TRAINER_MAY_14, Route104_Text_1EDE18
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_PostRivalBattle
	end
Route104_EventScript_1ECE49:: @ 81ECE49
	trainerbattle_no_intro TRAINER_MAY_15, Route104_Text_1EDE18
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_PostRivalBattle
	end
Route104_EventScript_1ECE5C:: @ 81ECE5C
	trainerbattle_no_intro TRAINER_MAY_10, Route104_Text_1EDE18
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_PostRivalBattle
	end
Route104_Text_1EDE18: @ 81EDE18
	.string "Yikes!\n"
	.string "You're worse than I expected!$"

Route104_EventScript_1ECF4D:: @ 81ECF4D
	trainerbattle_no_intro TRAINER_BRENDAN_10, Route104_Text_1EE107
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_PostRivalBattle
	end
Route104_EventScript_1ECF60:: @ 81ECF60
	trainerbattle_no_intro TRAINER_BRENDAN_12, Route104_Text_1EE107
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_PostRivalBattle
	end
Route104_EventScript_1ECF73:: @ 81ECF73
	trainerbattle_no_intro TRAINER_BRENDAN_11, Route104_Text_1EE107
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_PostRivalBattle
	end
Route104_Text_1EE107: @ 81EE107
	.string "Sheesh!\n"
	.string "You're worse than I thought!$"

Route104_EventScript_PostRivalBattle:: @ 81ECF38
	selectpointer_ongender Route104_Text_1EDE3E, Route104_Text_1EE120
	msgbox_selected
	compare VAR_0x8008, 0
	call_if_eq Common_EventScript_FadeMusicToMapMusic
	releaseall
	end
Route104_Text_1EDE3E: @ 81EDE3E
	.string "May: I can tell you've gotten pretty\n"
	.string "tough with the way you handle Pokémon.\p"
	.string "But instead of only making them\n"
	.string "fight, you should be like Mr. Briney.\p"
	.string "It's important to become friends with\n"
	.string "Pokémon, too.$"
Route104_Text_1EE120: @ 81EE120
	.string "Brendan: You've gotten pretty decent\n"
	.string "at handling Pokémon.\p"
	.string "But, you know, you shouldn't just be\n"
	.string "making Pokémon fight.\p"
	.string "Like Mr. Briney, it's important to\n"
	.string "become friends with your Pokémon.$"

#undef LID_BRINEY
#undef LID_RIVAL
