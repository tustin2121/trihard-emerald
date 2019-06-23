
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


Route104_EventScript_1ED090:: @ 81ED090
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






Route104_EventScript_1ED35F:: @ 81ED35F
	trainerbattle_single TRAINER_IVAN, Route104_Text_2954BD, Route104_Text_295509
	msgbox Route104_Text_29554E, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_1ED376:: @ 81ED376
	trainerbattle_single TRAINER_BILLY, Route104_Text_29558A, Route104_Text_2955B4
	msgbox Route104_Text_2955E8, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_1ED38D:: @ 81ED38D
	trainerbattle_single TRAINER_HALEY_1, Route104_Text_29563A, Route104_Text_29566F, Route104_EventScript_1ED3CE
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ED424
	setvar VAR_0x8004, 604
	specialvar VAR_RESULT, sub_813B4E0
	compare VAR_RESULT, 0
	goto_if_eq Route104_EventScript_1ED3F8
	msgbox Route104_Text_295689, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED3CE:: @ 81ED3CE
	special sub_80B4808
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_1ED3DF
	release
	end

Route104_EventScript_1ED3DF:: @ 81ED3DF
	msgbox Route104_Text_29576B, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_1ED3F8:: @ 81ED3F8
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_1ED40B
	msgbox Route104_Text_295689, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED40B:: @ 81ED40B
	msgbox Route104_Text_2956FF, MSGBOX_DEFAULT
	register_matchcall TRAINER_HALEY_1
	release
	end

Route104_EventScript_1ED424:: @ 81ED424
	trainerbattle_rematch TRAINER_HALEY_1, Route104_Text_2957D7, Route104_Text_2957F0
	msgbox Route104_Text_29580C, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_1ED43B:: @ 81ED43B
	trainerbattle_single TRAINER_WINSTON_1, Route104_Text_295870, Route104_Text_2958AD, Route104_EventScript_1ED47C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ED4D2
	setvar VAR_0x8004, 136
	specialvar VAR_RESULT, sub_813B4E0
	compare VAR_RESULT, 0
	goto_if_eq Route104_EventScript_1ED4A6
	msgbox Route104_Text_2958C1, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED47C:: @ 81ED47C
	special sub_80B4808
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_1ED48D
	release
	end

Route104_EventScript_1ED48D:: @ 81ED48D
	msgbox Route104_Text_29595A, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_1ED4A6:: @ 81ED4A6
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_1ED4B9
	msgbox Route104_Text_2958C1, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED4B9:: @ 81ED4B9
	msgbox Route104_Text_2958F8, MSGBOX_DEFAULT
	register_matchcall TRAINER_WINSTON_1
	release
	end

Route104_EventScript_1ED4D2:: @ 81ED4D2
	trainerbattle_rematch TRAINER_WINSTON_1, Route104_Text_2959BC, Route104_Text_2959FC
	msgbox Route104_Text_295A1E, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_1ED4E9:: @ 81ED4E9
	trainerbattle_single TRAINER_CINDY_1, Route104_Text_295A7E, Route104_Text_295ABB, Route104_EventScript_1ED52A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ED580
	setvar VAR_0x8004, 114
	specialvar VAR_RESULT, sub_813B4E0
	compare VAR_RESULT, 0
	goto_if_eq Route104_EventScript_1ED554
	msgbox Route104_Text_295AC3, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED52A:: @ 81ED52A
	special sub_80B4808
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_1ED53B
	release
	end

Route104_EventScript_1ED53B:: @ 81ED53B
	msgbox Route104_Text_295B60, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end

Route104_EventScript_1ED554:: @ 81ED554
	goto_if_set FLAG_HAS_MATCH_CALL, Route104_EventScript_1ED567
	msgbox Route104_Text_295AC3, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED567:: @ 81ED567
	msgbox Route104_Text_295B01, MSGBOX_DEFAULT
	register_matchcall TRAINER_CINDY_1
	release
	end

Route104_EventScript_1ED580:: @ 81ED580
	trainerbattle_rematch TRAINER_CINDY_1, Route104_Text_295BC8, Route104_Text_295BFA
	msgbox Route104_Text_295C1F, MSGBOX_AUTOCLOSE
	end

Route104_EventScript_1ED597:: @ 81ED597
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_2952BB, Route104_Text_2952E6, Route104_Text_295330
@	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_2952FE, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED5B6:: @ 81ED5B6
	trainerbattle_double TRAINER_GINA_AND_MIA_1, Route104_Text_2953AF, Route104_Text_2953E1, Route104_Text_295449
@	special GetPlayerBigGuyGirlString
	msgbox Route104_Text_29540D, MSGBOX_DEFAULT
	release
	end

Route104_EventScript_1ED5D5:: @ 81ED5D5
	trainerbattle_single TRAINER_DARIAN, Route104_Text_295C5D, Route104_Text_295CC9
	msgbox Route104_Text_295CD3, MSGBOX_AUTOCLOSE
	end













































Route104_Text_1EE0C7: @ 81EE0C7
	.string "Brendan: I know you just became\n"
	.string "a trainer, but I won't go easy!$"










@ -----------------------------------------------------
@ Rival

Route104_EventScript_Rival:: @ 81ECC9E
	lockall
	setvar VAR_0x8008, 1
	applymovement LID_RIVAL, Common_Movement_FacePlayer
	waitmovement 0
	goto Route104_EventScript_1ECD33

Route104_TriggerScript_MrBrineyRival:: @ 81ECCB3
	lockall
	setflag FLAG_HIDE_RUSBORO_CITY_RIVAL
	setvar VAR_RUSTBORO_STATE, 8
	setvar VAR_0x4063, 2
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
	applymovement LID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	goto Route104_EventScript_1ECD33
Route104_Movement_1ECF86: @ 81ECF86
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Route104_EventScript_1ECD33:: @ 81ECD33
	markasdialog
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route104_EventScript_1ECD4B
	compare VAR_RESULT, FEMALE
	goto_if_eq Route104_EventScript_1ECE6F
	end

Route104_EventScript_1ECD4B:: @ 81ECD4B
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_1ECE1C
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_1ECDD0
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox Route104_Text_1EDBFF, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	message Route104_Text_1EDC8F, MSGTYPE_DESCRIBE
	waitfanfare
	waitmessage
	waitbuttonpress
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ECDCD
	applymovement LID_RIVAL, Route104_Movement_1ECDC8
	msgbox Route104_Text_1EDCB1, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement LID_RIVAL, Route104_Movement_1ECDCA
	waitmovement 0
	moveobjectoffscreen 34
	msgbox Route104_Text_1EDCED, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ECDED
	msgbox Route104_Text_1EDD2A, MSGBOX_DEFAULT
	call Common_EventScript_FadeMusicToMapMusic
	releaseall
	end
Route104_Text_1EDBFF: @ 81EDBFF
	.string "May: Oh, hi, {PLAYER}!\p"
	.string "DEVON upgraded your PokéNav with\n"
	.string "the MATCH CALL system, huh?\p"
	.string "We should register each other so we\n"
	.string "can get in contact anytime.$"
Route104_Text_1EDC8F: @ 81EDC8F
	.string "{PLAYER} registered May\n"
	.string "in the PokéNav.$"
Route104_Movement_1ECDCD: @ 81ECDCD
	delay_4
	walk_in_place_fastest_left
	step_end
Route104_Movement_1ECDC8: @ 81ECDC8
	walk_slow_left
	step_end
Route104_Text_1EDCB1: @ 81EDCB1
	.string "May: Oh, by the way, {PLAYER},\n"
	.string "how's your Pokédex coming along?$"
Route104_Movement_1ECDCA: @ 81ECDCA
	walk_down
	face_right
	step_end
Route104_Text_1EDCED: @ 81EDCED
	.string "Mine's looking pretty decent.\n"
	.string "So…\l"
	.string "How about a little battle?$"

Route104_EventScript_1ECDD0:: @ 81ECDD0
	msgbox Route104_Text_1EDD9F, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ECDED
	msgbox Route104_Text_1EDD2A, MSGBOX_DEFAULT
	releaseall
	end
Route104_Text_1EDD9F: @ 81EDD9F
	.string "May: So, what do you think?\n"
	.string "How about a little battle here?$"
Route104_Text_1EDD2A: @ 81EDD2A
	.string "May: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "Pokémon very much?\p"
	.string "That's not very good for a trainer!$"

Route104_EventScript_1ECDED:: @ 81ECDED
	msgbox Route104_Text_1EDDDB, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route104_EventScript_1ECE36
	case 1, Route104_EventScript_1ECE49
	case 2, Route104_EventScript_1ECE5C
	end
Route104_Text_1EDDDB: @ 81EDDDB
	.string "May: You just became a trainer,\n"
	.string "{PLAYER}. I'm not going to lose!$"

Route104_EventScript_1ECE36:: @ 81ECE36
	trainerbattle_no_intro TRAINER_MAY_14, Route104_Text_1EDE18
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_1ECE1C
	end
Route104_EventScript_1ECE49:: @ 81ECE49
	trainerbattle_no_intro TRAINER_MAY_15, Route104_Text_1EDE18
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_1ECE1C
	end
Route104_EventScript_1ECE5C:: @ 81ECE5C
	trainerbattle_no_intro TRAINER_MAY_10, Route104_Text_1EDE18
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_1ECE1C
	end
Route104_Text_1EDE18: @ 81EDE18
	.string "Yikes!\n"
	.string "You're better than I expected!$"

Route104_EventScript_1ECE1C:: @ 81ECE1C
	msgbox Route104_Text_1EDE3E, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq Common_EventScript_FadeMusicToMapMusic
	releaseall
	end
Route104_Text_1EDE3E: @ 81EDE3E
	.string "May: I can tell you've gotten pretty\n"
	.string "good with the way you handle Pokémon.\p"
	.string "But instead of only making them\n"
	.string "battle, you should be like MR. BRINEY.\p"
	.string "It's important to become friends with\n"
	.string "Pokémon, too.$"


Route104_EventScript_1ECE6F:: @ 81ECE6F
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE_104, Route104_EventScript_1ECF38
	goto_if_set FLAG_REGISTER_RIVAL_POKENAV, Route104_EventScript_1ECEEC
	setflag FLAG_REGISTER_RIVAL_POKENAV
	msgbox Route104_Text_1EDF04, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox Route104_Text_1EDFA0, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ECDCD
	applymovement LID_RIVAL, Route104_Movement_1ECDC8
	msgbox Route104_Text_1EDFC6, MSGBOX_DEFAULT
	closemessage
	waitmovement 0
	applymovement LID_RIVAL, Route104_Movement_1ECDCA
	waitmovement 0
	moveobjectoffscreen 34
	msgbox Route104_Text_1EE009, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ECF09
	msgbox Route104_Text_1EE04D, MSGBOX_DEFAULT
	call Common_EventScript_FadeMusicToMapMusic
	releaseall
	end
Route104_Text_1EDF04: @ 81EDF04
	.string "Brendan: Oh, hey, {PLAYER}!\p"
	.string "Cool, you had DEVON install the MATCH\n"
	.string "CALL system on your PokéNav!\p"
	.string "Let's register each other in our\n"
	.string "PokéNavS so we can keep in touch.$"
Route104_Text_1EDFA0: @ 81EDFA0
	.string "{PLAYER} registered BRENDAN\n"
	.string "in the PokéNav.$"
Route104_Text_1EDFC6: @ 81EDFC6
	.string "Brendan: {PLAYER}, how's your Pokédex?\n"
	.string "Have you filled in any pages yet?$"
Route104_Text_1EE009: @ 81EE009
	.string "Me, I'm doing great!\p"
	.string "Want to check out how good I am with\n"
	.string "a battle?$"


Route104_EventScript_1ECEEC:: @ 81ECEEC
	msgbox Route104_Text_1EE094, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route104_EventScript_1ECF09
	msgbox Route104_Text_1EE04D, MSGBOX_DEFAULT
	releaseall
	end
Route104_Text_1EE094: @ 81EE094
	.string "Brendan: What's up?\n"
	.string "Want to have a battle with me?$"
Route104_Text_1EE04D: @ 81EE04D
	.string "Brendan: What's the matter? Don't have\n"
	.string "any confidence in your Pokémon?$"

Route104_EventScript_1ECF09:: @ 81ECF09
	msgbox Route104_Text_1EE0C7, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route104_EventScript_1ECF4D
	case 1, Route104_EventScript_1ECF60
	case 2, Route104_EventScript_1ECF73
	end

Route104_EventScript_1ECF4D:: @ 81ECF4D
	trainerbattle_no_intro TRAINER_BRENDAN_10, Route104_Text_1EE107
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_1ECF38
	end
Route104_EventScript_1ECF60:: @ 81ECF60
	trainerbattle_no_intro TRAINER_BRENDAN_12, Route104_Text_1EE107
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_1ECF38
	end
Route104_EventScript_1ECF73:: @ 81ECF73
	trainerbattle_no_intro TRAINER_BRENDAN_11, Route104_Text_1EE107
	setflag FLAG_DEFEATED_RIVAL_ROUTE_104
	goto Route104_EventScript_1ECF38
	end
Route104_Text_1EE107: @ 81EE107
	.string "Hmm…\n"
	.string "You're pretty good.$"

Route104_EventScript_1ECF38:: @ 81ECF38
	msgbox Route104_Text_1EE120, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq Common_EventScript_FadeMusicToMapMusic
	releaseall
	end
Route104_Text_1EE120: @ 81EE120
	.string "Brendan: You've gotten pretty decent\n"
	.string "at handling Pokémon.\p"
	.string "But, you know, you shouldn't just be\n"
	.string "making Pokémon battle.\p"
	.string "Like Mr. Briney, it's important to\n"
	.string "become friends with your Pokémon.$"


#undef LID_RIVAL
