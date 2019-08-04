Route109_MapScripts:: @ 81EE75F
	.byte 0
	
@ -----------------------------------------------------
@ Signs

Route109_SignScript_SeashoreHouse:: @ 81EEA2B
	msgbox Route109_Text_1EF185, MSGBOX_SIGN
	end
Route109_Text_1EF185: @ 81EF185
	.string "{PLACE}Seashore House{END}\p"
	.string "“May hot battles rage on hot sands!\n"
	.string "The place for hot trainers!”$"

Route109_SignScript_TrainerTips:: @ 81EEA34
	msgbox Route109_Text_1EF1D5, MSGBOX_DESCRIBE
	end
Route109_Text_1EF1D5: @ 81EF1D5
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "Pokémon at the same level may not\n"
	.string "always have identical stats.\p"
	.string "Pokémon raised by trainers are said\n"
	.string "to grow stronger than wild Pokémon.$"

@ -----------------------------------------------------
@ Items

Route109_EventScript_ItemPPUp:: @ 8290D5A
	giveitem_std ITEM_PP_UP, 1, 1
	end

Route109_EventScript_ItemPotion:: @ 8290D67
	giveitem_std ITEM_POTION, 1, 1
	end

@ -----------------------------------------------------
@ People

Route109_EventScript_SandHutHouseGirl:: @ 81EE995
	msgbox Route109_Text_1EEEB4, MSGBOX_NPC
	end
Route109_Text_1EEEB4: @ 81EEEB4
	.string "Yo, trainers!\n"
	.string "Whether you're hot to trot,\l"
	.string "or cool cat not,\l"
	.string "chill at my papa's spot!$"


Route109_EventScript_SandcastleBoy:: @ 81EE99E
	lock
	faceplayer
	msgbox Route109_Text_1EEFB0, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
Route109_Text_1EEFB0: @ 81EEFB0
	.string "Our sand castle's taking a long time\n"
	.string "to make.$"


Route109_EventScript_SandcastleGirl:: @ 81EE9B5
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOFT_SAND, Route109_EventScript_1EE9F2
	msgbox Route109_Text_1EEFDE, MSGBOX_DEFAULT
	giveitem_std ITEM_SOFT_SAND
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_RECEIVED_SOFT_SAND
	release
	end
Route109_Text_1EEFDE: @ 81EEFDE
	.string "You can have this!$"
Route109_EventScript_1EE9F2:: @ 81EE9F2
	msgbox Route109_Text_1EEFF1, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
Route109_Text_1EEFF1: @ 81EEFF1
	.string "We're going to get all the sand from\n"
	.string "the beach and make a big castle!\p"
	.string "And then we're going to be a king and\n"
	.string "queen.\p"
	.string "We'll let you be a servant.$"


Route109_EventScript_Mother:: @ 81EEA06
	msgbox Route109_Text_1EEF08, MSGBOX_NPC
	end
Route109_Text_1EEF08: @ 81EEF08
	.string "Little kids can dart around so quickly…\p"
	.string "You don't dare take your eyes off them\n"
	.string "for an instant. It's very taxing.\p"
	.string "Mine are with my Pokémon, so they\n"
	.string "should be okay, but…$"


Route109_EventScript_ZiggyMan:: @ 81EEA0F
	msgbox Route109_Text_1EF080, MSGBOX_NPC
	end
Route109_Text_1EF080: @ 81EF080
	.string "The water around these parts is clean.\p"
	.string "But, I get my Zigzagoon to pick up\n"
	.string "litter from the shoreline at times.\p"
	.string "Dirty water becomes rain and joins our\n"
	.string "rivers, which we drink from…\p"
	.string "If we pollute the sea, it all comes\n"
	.string "back to haunt us eventually.$"

Route109_EventScript_Zigzagoon:: @ 81EEA18
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, 0
	msgbox Route109_Text_1EF173, MSGBOX_DEFAULT
	waitmoncry
	release
	end
Route109_Text_1EF173: @ 81EF173
	.string "Zigzagoon: Guguu?$"

@ -----------------------------------------------------
@ Trainers

Route109_TrainerScript_David:: @ 81EEA3D
	trainerbattle_single TRAINER_DAVID, Route109_Text_297140, Route109_Text_29717D
	msgbox Route109_Text_297191, MSGBOX_AUTOCLOSE
	end
Route109_Text_297140: @ 8297140
	.string "Hiyah! Look at my chiseled abs!\n"
	.string "This is what you call “cut”!$"
Route109_Text_29717D: @ 829717D
	.string "Aiyah!\n"
	.string "Flubbed out!$"
Route109_Text_297191: @ 8297191
	.string "Hiyah!\p"
	.string "My sculpted abs have nothing to do\n"
	.string "with Pokémon battles!$"



Route109_TrainerScript_Alice:: @ 81EEA54
	trainerbattle_single TRAINER_ALICE, Route109_Text_2971D1, Route109_Text_2971FD
	msgbox Route109_Text_29720F, MSGBOX_AUTOCLOSE
	end
Route109_Text_2971D1: @ 82971D1
	.string "Are you properly protected against\n"
	.string "the sun?$"
Route109_Text_2971FD: @ 82971FD
	.string "Ouch, ouch, ouch!$"
Route109_Text_29720F: @ 829720F
	.string "Cheeks are the most prone to burning!$"



Route109_TrainerScript_Huey:: @ 81EEA6B
	trainerbattle_single TRAINER_HUEY, Route109_Text_297235, Route109_Text_29727B
	msgbox Route109_Text_29728C, MSGBOX_AUTOCLOSE
	end
Route109_Text_297235: @ 8297235
	.string "I've laid my anchor in ports around\n"
	.string "the world, but Slateport's are best.$"
Route109_Text_29727B: @ 829727B
	.string "I was distracted!$"
Route109_Text_29728C: @ 829728C
	.string "I was too busy thinking about harbors\n"
	.string "I can lay anchor in around here.\l"
	.string "Wink wink.$"



Route109_TrainerScript_Edmond:: @ 81EEA82
	trainerbattle_single TRAINER_EDMOND, Route109_Text_2972B3, Route109_Text_2972CE
	msgbox Route109_Text_2972ED, MSGBOX_AUTOCLOSE
	end
Route109_Text_2972B3: @ 82972B3
	.string "Urrrrppp…\n"
	.string "Battle? With me?$"
Route109_Text_2972CE: @ 82972CE
	.string "Urp… Ooooooohhhhhh…\n"
	.string "Urrrrpppp…$"
Route109_Text_2972ED: @ 82972ED
	.string "I'm usually stronger than this!\n"
	.string "I'm just seasick as a dog!\p"
	.string "I'm a sailor, but…$"



Route109_TrainerScript_Ricky:: @ 81EEA99
	trainerbattle_single TRAINER_RICKY_1, Route109_Text_29733B, Route109_Text_297379, Route109_EventScript_1EEAC5
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route109_EventScript_1EEAE4
	msgbox Route109_Text_297380, MSGBOX_DEFAULT
	release
	end
Route109_Text_29733B: @ 829733B
	.string "I'm thirsty… I could go for a soda pop\n"
	.string "at the Seashore House…$"
Route109_Text_297379: @ 8297379
	.string "Groan…$"
Route109_Text_297380: @ 8297380
	.string "I'm getting famished… My inner tube\n"
	.string "looks like a giant doughnut…$"
Route109_EventScript_1EEAC5:: @ 81EEAC5
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route109_Text_2973C1, MSGBOX_DEFAULT
	register_matchcall TRAINER_RICKY_1
	release
	end
Route109_Text_2973C1: @ 82973C1
	.string "Will you have another match with me\n"
	.string "when I'm not all thirsty?$"
Route109_EventScript_1EEAE4:: @ 81EEAE4
	trainerbattle_rematch TRAINER_RICKY_1, Route109_Text_2973FF, Route109_Text_297437
	msgbox Route109_Text_297458, MSGBOX_AUTOCLOSE
	end
Route109_Text_2973FF: @ 82973FF
	.string "I'm hungry, but I've got enough pep in\n"
	.string "me for a battle!$"
Route109_Text_297437: @ 8297437
	.string "I lost…\n"
	.string "It's because I'm hungry…$"
Route109_Text_297458: @ 8297458
	.string "When you eat on a beach, everything\n"
	.string "seems to taste a little better.$"



Route109_TrainerScript_Lola:: @ 81EEAFB
	trainerbattle_single TRAINER_LOLA_1, Route109_Text_29749C, Route109_Text_2974CF, Route109_EventScript_1EEB27
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route109_EventScript_1EEB46
	msgbox Route109_Text_2974D6, MSGBOX_DEFAULT
	release
	end
Route109_Text_29749C: @ 829749C
	.string "Doesn't a beach umbrella look like\n"
	.string "a giant flower?$"
Route109_Text_2974CF: @ 82974CF
	.string "Mommy!$"
Route109_Text_2974D6: @ 82974D6
	.string "If you look at the beach from the sky,\n"
	.string "it looks like a big flower garden!$"
Route109_EventScript_1EEB27:: @ 81EEB27
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route109_Text_297520, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA_1
	release
	end
Route109_Text_297520: @ 8297520
	.string "Me?\n"
	.string "I'm here every day!$"
Route109_EventScript_1EEB46:: @ 81EEB46
	trainerbattle_rematch TRAINER_LOLA_1, Route109_Text_297538, Route109_Text_297576
	msgbox Route109_Text_29757D, MSGBOX_AUTOCLOSE
	end
Route109_Text_297538: @ 8297538
	.string "I'm not losing to you again!\n"
	.string "That's why I have my inner tube!$"
Route109_Text_297576: @ 8297576
	.string "Mommy!$"
Route109_Text_29757D: @ 829757D
	.string "If I have an inner tube, me and my\n"
	.string "Pokémon's cuteness goes way up!$"




Route109_TrainerScript_Austina:: @ 81EEB5D
	trainerbattle_single TRAINER_AUSTINA, Route109_Text_2975C0, Route109_Text_297601
	msgbox Route109_Text_29762A, MSGBOX_AUTOCLOSE
	end
Route109_Text_2975C0: @ 82975C0
	.string "I can't swim without my inner tube,\n"
	.string "but I won't lose at Pokémon!$"
Route109_Text_297601: @ 8297601
	.string "Did I lose because I have an inner\n"
	.string "tube?$"
Route109_Text_29762A: @ 829762A
	.string "My inner tube is a fashion item.\n"
	.string "I can't be seen without it.$"



Route109_TrainerScript_Gwen:: @ 81EEB74
	trainerbattle_single TRAINER_GWEN, Route109_Text_297667, Route109_Text_297691
	msgbox Route109_Text_2976A4, MSGBOX_AUTOCLOSE
	end
Route109_Text_297667: @ 8297667
	.string "Hi, big trainer.\n"
	.string "Will you battle with me?$"
Route109_Text_297691: @ 8297691
	.string "Oh, you're strong.$"
Route109_Text_2976A4: @ 82976A4
	.string "How did you get to be so strong?$"



Route109_TrainerScript_Carter:: @ 81EEB8B
	trainerbattle_single TRAINER_CARTER, Route109_Text_2976C5, Route109_Text_2976FC
	msgbox Route109_Text_297715, MSGBOX_AUTOCLOSE
	end
Route109_Text_2976C5: @ 82976C5
	.string "Wahahah! This dude's going to catch\n"
	.string "himself a big one!$"
Route109_Text_2976FC: @ 82976FC
	.string "This dude just lost one…$"
Route109_Text_297715: @ 8297715
	.string "This dude thinks you're a big one.\n"
	.string "No, you're a big-one-to-be!$"



Route109_TrainerScript_Paul:: @ 81EEBA2
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_297754, Route109_Text_2977B0, Route109_Text_29781D
	msgbox Route109_Text_2977C7, MSGBOX_AUTOCLOSE
	end
Route109_Text_297754: @ 8297754
	.string "Paul: Well, this is a mood-breaker.\p"
	.string "I wish you wouldn't disturb our\n"
	.string "precious time together.$"
Route109_Text_2977B0: @ 82977B0
	.string "Paul: Well, I give up.$"
Route109_Text_2977C7: @ 82977C7
	.string "Paul: Well, don't tell anyone that\n"
	.string "we're here.\l"
	.string "This is just our private world of two!$"
Route109_Text_29781D: @ 829781D
	.string "Paul: We're totally, deeply in love.\n"
	.string "That's why we make our Pokémon battle\l"
	.string "together.$"

Route109_TrainerScript_Mel:: @ 81EEBBD
	trainerbattle_double TRAINER_MEL_AND_PAUL, Route109_Text_297872, Route109_Text_2978BD, Route109_Text_29792E
	msgbox Route109_Text_2978F1, MSGBOX_AUTOCLOSE
	end
Route109_Text_297872: @ 8297872
	.string "Mel: We're, like, totally in love.\n"
	.string "Our romance is heating up all of Hoenn!$"
Route109_Text_2978BD: @ 82978BD
	.string "Mel: We lost, and it's my fault!\n"
	.string "Paul will hate me!$"
Route109_Text_2978F1: @ 82978F1
	.string "Mel: Um, Paul, are you angry with me?\n"
	.string "Please don't be angry.$"
Route109_Text_29792E: @ 829792E
	.string "Mel: We're, like, deeply and truly in love.\n"
	.string "That's why we make our Pokémon\l"
	.string "battle together.$"



Route109_TrainerScript_Chandler:: @ 81EEBD8
	trainerbattle_single TRAINER_CHANDLER, Route109_Text_29798A, Route109_Text_2979AE
	msgbox Route109_Text_2979BF, MSGBOX_AUTOCLOSE
	end
Route109_Text_29798A: @ 829798A
	.string "Tadaah! See?\n"
	.string "My inner tube's round!$"
Route109_Text_2979AE: @ 82979AE
	.string "Oh, oh!\n"
	.string "Too bad!$"
Route109_Text_2979BF: @ 82979BF
	.string "After I showed you my round inner\n"
	.string "tube, too…$"



Route109_TrainerScript_Hailey:: @ 81EEBEF
	trainerbattle_single TRAINER_HAILEY, Route109_Text_2979EC, Route109_Text_297A15
	msgbox Route109_Text_297A40, MSGBOX_AUTOCLOSE
	end
Route109_Text_2979EC: @ 82979EC
	.string "I can't swim, so I'm pretending\n"
	.string "to swim.$"
Route109_Text_297A15: @ 8297A15
	.string "I thought so!\n"
	.string "I didn't think we could win.$"
Route109_Text_297A40: @ 8297A40
	.string "When I learn how to swim, I think\n"
	.string "my Pokémon will become tougher.$"



Route109_TrainerScript_Elijah:: @ 81EEC06
	trainerbattle_single TRAINER_ELIJAH, Route109_Text_297A82, Route109_Text_297AC7
	msgbox Route109_Text_297AE5, MSGBOX_AUTOCLOSE
	end
Route109_Text_297A82: @ 8297A82
	.string "For a guy as macho as me, this kind\n"
	.string "of Pokémon is the perfect match!$"
Route109_Text_297AC7: @ 8297AC7
	.string "I'm cool even in defeat, hey?$"
Route109_Text_297AE5: @ 8297AE5
	.string "For a guy as macho as me, a port\n"
	.string "is the perfect setting!\p"
	.string "I guess I'll head for Slateport.$"


@ -----------------------------------------------------
@ Briney

Route109_EventScript_1EE910:: @ 81EE910
	lock
	faceplayer
	markasdialog
	message Route109_Text_1EEE17
	waitmessage
	multichoicedefault 21, 8, 14, 1, 0
	switch VAR_RESULT
	case 0, Route109_EventScript_1EE972
	case 1, Route109_EventScript_1EE98B
	case 127, Route109_EventScript_1EE98B
	end
Route109_Text_1EEE17: @ 81EEE17
	.string "Mr. Briney: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"
Route109_EventScript_1EE972:: @ 81EE972
	msgbox Route109_Text_1EED06, MSGBOX_DEFAULT
	closemessage
	goto Route109_EventScript_DepartForDewford
	end
Route109_Text_1EED06: @ 81EED06
	.string "Mr. Briney: Dewford it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "Peeko, we're setting sail, my darling!$"
Route109_EventScript_1EE98B:: @ 81EE98B
	msgbox Route109_Text_1EEE72, MSGBOX_DEFAULT
	release
	end
Route109_Text_1EEE72: @ 81EEE72
	.string "Mr. Briney: You just tell me whenever\n"
	.string "you need to set sail again!$"

Route109_EventScript_DepartForDewford:: @ 81EE760
	call Route109_EventScript_271E95
	setobjectpriority 2, MAP_ROUTE109, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_ROUTE109, 0
	applymovement 2, Common_Movement_WalkDown1
	waitmovement 0
	removeobject 2
	selectpointer Route109_MovementTable_PlayerWalk, VAR_FACING
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	goto Briney_EventScript_Slateport_Dewford
	end

.align 2
Route109_MovementTable_PlayerWalk:
	.4byte Common_Movement_WalkDown1
	.4byte Route109_Movement_1EE8FD
	.4byte Common_Movement_WalkDown1
	.4byte Route109_Movement_1EE908
	.4byte Route109_Movement_1EE905
	.4byte 0
Route109_Movement_1EE8FD: @ 81EE8FD
	walk_down
	walk_down
	step_end
Route109_Movement_1EE905: @ 81EE905
	walk_right
	walk_down
	step_end
Route109_Movement_1EE908: @ 81EE908
	walk_left
	walk_down
	step_end

@ -----------------------------------------------------
@ Briney scripts

Route109_EventScript_BrineyArriveFromDewford::
	@ continued sequence from briney_boat.inc
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9918
	waitmovement 0
	setobjectxyperm 2, 21, 26
	addobject 2
	setobjectpriority 2, MAP_ROUTE109, 0
	applymovement 2, DewfordTown_Movement_1E991F
	waitmovement 0
	clearflag FLAG_HIDE_ROUTE_108_MR_BRINEY
	addobject 1
	clearflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	setflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	hideobjectat 4, MAP_DEWFORD_TOWN
	call_if_unset FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_1E9790
	call_if_set FLAG_DELIVERED_DEVON_GOODS, DewfordTown_EventScript_1E9799
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	resetobjectpriority 2, MAP_ROUTE109
	moveobjectoffscreen 2
	release
	end

DewfordTown_EventScript_1E9790:: @ 81E9790
	msgbox DewfordTown_Text_1EEC1D, MSGBOX_DEFAULT
	return
DewfordTown_Text_1EEC1D: @ 81EEC1D
	.string "Mr. Briney: Ahoy!\n"
	.string "We've made land in Slateport!\p"
	.string "I heard about a museum exhibition\n"
	.string "going on right now.\p"
	.string "Why don't you take this\n"
	.string "opportunity and attend it?$"

DewfordTown_EventScript_1E9799:: @ 81E9799
	msgbox DewfordTown_Text_1EEDA7, MSGBOX_DEFAULT
	return
DewfordTown_Text_1EEDA7: @ 81EEDA7
	.string "Mr. Briney: Ahoy! We've made land in\n"
	.string "Slateport!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"
