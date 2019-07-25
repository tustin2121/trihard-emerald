Route116_MapScripts:: @ 81F2C0C
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_MapScript1_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_MapScript2_FrameTable
	.byte 0

@ -----------------------------------------------------

Route116_OnTransition: @ 81F2C1C
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_1F2C47
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Common_EventScript_HideMapNamePopup
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_NORTH
	call_if_eq UnusualWeather_StartGroudonWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_SOUTH
	call_if_eq UnusualWeather_StartGroudonWeather
	end

Route116_EventScript_1F2C47:: @ 81F2C47
	setobjectxyperm 21, 38, 10
	return

@ -----------------------------------------------------

Route116_MapScript1_OnLoad: @ 81F2C4F
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_NORTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute116North
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_116_SOUTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute116South
	end

@ -----------------------------------------------------

Route116_MapScript2_FrameTable: @ 81F2C66
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

@ -----------------------------------------------------
@ Items

Route116_EventScript_ItemXSpecial:: @ 8290E78
	giveitem_std ITEM_X_SPECIAL, 1, 1
	end

Route116_EventScript_ItemEther:: @ 8290E85
	giveitem_std ITEM_ETHER, 1, 1
	end

Route116_EventScript_ItemRepel:: @ 8290E92
	giveitem_std ITEM_REPEL, 1, 1
	end

Route116_EventScript_ItemHPUp:: @ 8290E9F
	giveitem_std ITEM_HP_UP, 1, 1
	end

Route116_EventScript_ItemPotion:: @ 8290EAC
	giveitem_std ITEM_POTION, 1, 1
	end

@ -----------------------------------------------------
@ People

Route116_EventScript_1F2C70:: @ 81F2C70
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_1F2C8E
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_1F2C98
	msgbox Route116_Text_1F3140, MSGBOX_DEFAULT
	release
	end
Route116_Text_1F3140: @ 81F3140
	.string "Nnn… Roar!\p"
	.string "I want to dig that tunnel!$"
Route116_EventScript_1F2C8E:: @ 81F2C8E
	msgbox Route116_Text_1F32C1, MSGBOX_DEFAULT
	release
	end
Route116_Text_1F32C1: @ 81F32C1
	.string "Nnn… Roar!\p"
	.string "That goofy goon hightailed it out of\n"
	.string "the tunnel! I can go back to digging!$"
Route116_EventScript_1F2C98:: @ 81F2C98
	msgbox Route116_Text_1F3166, MSGBOX_DEFAULT
	release
	end
Route116_Text_1F3166: @ 81F3166
	.string "Nnn… Roar!\n"
	.string "What's going on?\p"
	.string "I was digging the tunnel without any\n"
	.string "tools when some goon ordered me out!\p"
	.string "That tunnel's filled with Pokémon\n"
	.string "that react badly to loud noises.\l"
	.string "They could cause an uproar.\p"
	.string "That's why we stopped using heavy\n"
	.string "equipment for tunneling…\p"
	.string "I'm worried that the goon will do\n"
	.string "something stupid and startle the\l"
	.string "Pokémon into an uproar.$"



Route116_EventScript_1F2CA2:: @ 81F2CA2
	@ Dummied out
	end
@ 	lock
@ 	faceplayer
@ 	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_1F2D2B
@ 	msgbox Route116_Text_1F3317, MSGBOX_DEFAULT
@ 	goto Route116_EventScript_1F2CBB
@ 	end
@ Route116_Text_1F3317: @ 81F3317
@ 	.string "Oh! It's you!\p"
@ 	.string "You're that person who not only helped\n"
@ 	.string "me in Petalburg Woods, but also got\l"
@ 	.string "back my stolen package and then even\l"
@ 	.string "graciously delivered it to SLATEPORT!\p"
@ 	.string "CAPT. STERN informed us that the\n"
@ 	.string "package arrived, too!\p"
@ 	.string "I thank you very, very much!\p"
@ 	.string "Why, if I were a rain cloud, I would\n"
@ 	.string "shower you with gratitude and hail\l"
@ 	.string "you as a hero!\p"
@ 	.string "For you, the most wonderful TRAINER,\n"
@ 	.string "I bear good news!\p"
@ 	.string "Recently, our company developed\n"
@ 	.string "a new kind of POKé BALL.\p"
@ 	.string "As a token of our appreciation, this\n"
@ 	.string "is our gift to our wonderful TRAINER!$"
@ Route116_EventScript_1F2CBB:: @ 81F2CBB
@ 	setflag FLAG_MET_DEVON_EMPLOYEE
@ 	giveitem_std ITEM_REPEAT_BALL
@ 	compare VAR_RESULT, 0
@ 	goto_if_eq Route116_EventScript_1F2D39
@ 	msgbox Route116_Text_1F3521, MSGBOX_DEFAULT
@ 	closemessage
@ 	compare VAR_FACING, 2
@ 	call_if_eq Route116_EventScript_1F2D15
@ 	compare VAR_FACING, 1
@ 	call_if_eq Route116_EventScript_1F2D15
@ 	compare VAR_FACING, 3
@ 	call_if_eq Route116_EventScript_1F2D15
@ 	compare VAR_FACING, 4
@ 	call_if_eq Route116_EventScript_1F2D20
@ 	removeobject VAR_LAST_TALKED
@ 	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_CORP_3F_EMPLOYEE
@ 	setflag FLAG_RECEIVED_REPEAT_BALL
@ 	release
@ 	end
@ Route116_Text_1F3521: @ 81F3521
@ 	.string "Our new POKé BALL will be available\n"
@ 	.string "at the Pokémon MART in RUSTBORO.\p"
@ 	.string "Please do try it out!\n"
@ 	.string "Thank you and bye-bye!$"
@ Route116_EventScript_1F2D15:: @ 81F2D15
@ 	applymovement VAR_LAST_TALKED, Route116_Movement_1F2D43
@ 	waitmovement 0
@ 	return
@ Route116_Movement_1F2D43: @ 81F2D43
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	step_end
@ Route116_EventScript_1F2D20:: @ 81F2D20
@ 	applymovement VAR_LAST_TALKED, Route116_Movement_1F2D4C
@ 	waitmovement 0
@ 	return
@ Route116_Movement_1F2D4C: @ 81F2D4C
@ 	walk_down
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	walk_left
@ 	step_end
@ Route116_EventScript_1F2D2B:: @ 81F2D2B
@ 	msgbox Route116_Text_1F35CE, MSGBOX_DEFAULT
@ 	goto Route116_EventScript_1F2CBB
@ 	end
@ Route116_Text_1F35CE: @ 81F35CE
@ 	.string "As a token of our appreciation for\n"
@ 	.string "your delivering our package, I have\l"
@ 	.string "a gift of a new kind of POKé BALL\l"
@ 	.string "for our most wonderful TRAINER!$"
@ Route116_EventScript_1F2D39:: @ 81F2D39
@ 	msgbox Route116_Text_1F3593, MSGBOX_DEFAULT
@ 	release
@ 	end
@ Route116_Text_1F3593: @ 81F3593
@ 	.string "Your BAG is jam-packed.\n"
@ 	.string "I can't give you this REPEAT BALL.$"



Route116_EventScript_Briney:: @ 81F2D84
	lock
	faceplayer
	msgbox Route116_Text_1F309D, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	release
	end
Route116_TriggerScript_BrineyTrigger:: @ 81F2D95
	lockall
	applymovement 11, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route116_Text_1F309D, MSGBOX_DEFAULT
	setvar VAR_ROUTE116_STATE, 2
	releaseall
	end
Route116_Text_1F309D: @ 81F309D
	.string "Ohhh, what am I to do?\p"
	.string "We were on our walk, Peeko and I, when\n"
	.string "we were jumped by an odd thug…\p"
	.string "The scoundrel made off with my\n"
	.string "darling Peeko!\p"
	.string "Wrrrooooooaaaar! Peeko!$"



Route116_EventScript_1F2DB6:: @ 81F2DB6
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES, 1
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2DF1
	specialvar VAR_RESULT, FoundBlackGlasses
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2DE2
	msgbox Route116_Text_1F3657, MSGBOX_DEFAULT
	release
	end
Route116_EventScript_1F2DE2:: @ 81F2DE2
	msgbox Route116_Text_1F3718, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_1F2E2A
	end
Route116_Text_1F3718: @ 81F3718
	.string "Hmm…\n"
	.string "I can't find my glasses anywhere…\l"
	.string "Maybe they're not around here…$"
Route116_EventScript_1F2DF1:: @ 81F2DF1
	msgbox Route116_Text_1F3657, MSGBOX_DEFAULT
	msgbox Route116_Text_1F3688, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2E1B
	msgbox Route116_Text_1F375E, MSGBOX_DEFAULT
	release
	end
Route116_Text_1F3657: @ 81F3657
	.string "I dropped my glasses…\n"
	.string "Can you help me find them?$"
Route116_Text_1F3688: @ 81F3688
	.string "Those glasses!\n"
	.string "May I see them for a second?$"
Route116_Text_1F375E: @ 81F375E
	.string "Hmm…\n"
	.string "These are BlackGlasses.\l"
	.string "They're not what I'm looking for…$"
Route116_EventScript_1F2E1B:: @ 81F2E1B
	msgbox Route116_Text_1F36B4, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_1F2E2A
	end
Route116_Text_1F36B4: @ 81F36B4
	.string "Hmm…\n"
	.string "These are BlackGlasses.\l"
	.string "They're not what I'm looking for…\p"
	.string "Maybe my glasses aren't around\n"
	.string "here…$"
Route116_EventScript_1F2E2A:: @ 81F2E2A
	delay 20
	compare VAR_FACING, 2
	call_if_eq Route116_EventScript_1F2E5E
	compare VAR_FACING, 1
	call_if_eq Route116_EventScript_1F2E5E
	compare VAR_FACING, 3
	call_if_eq Route116_EventScript_1F2E5E
	compare VAR_FACING, 4
	call_if_eq Route116_EventScript_1F2E69
	removeobject VAR_LAST_TALKED
	release
	end
Route116_EventScript_1F2E5E:: @ 81F2E5E
	applymovement VAR_LAST_TALKED, Route116_Movement_1F2E74
	waitmovement 0
	return
Route116_Movement_1F2E74: @ 81F2E74
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
Route116_EventScript_1F2E69:: @ 81F2E69
	applymovement VAR_LAST_TALKED, Route116_Movement_1F2E7E
	waitmovement 0
	return
Route116_Movement_1F2E7E: @ 81F2E7E
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ -----------------------------------------------------
@ Signs

Route116_EventScript_1F2D57:: @ 81F2D57
	msgbox Route116_Text_1F379D, MSGBOX_SIGN
	end
Route116_Text_1F379D: @ 81F379D
	.string "Route 116\n"
	.string "{LEFT_ARROW} Rustboro City$"


Route116_EventScript_1F2D60:: @ 81F2D60
	msgbox Route116_Text_1F37B7, MSGBOX_SIGN
	end
Route116_Text_1F37B7: @ 81F37B7
	.string "{PLACE}Rusturf Tunnel{END}\n"
	.string "“Linking Rustboro and Verdanturf\p"
	.string "“The tunnel project has been\n"
	.string "canceled.”$"


Route116_EventScript_1F2D69:: @ 81F2D69
	msgbox Route116_Text_1F380F, MSGBOX_SIGN
	end
Route116_Text_1F380F: @ 81F380F
	.string "{PLACE}Tunneler's Rest House{END}$"


Route116_EventScript_1F2D72:: @ 81F2D72
	msgbox Route116_Text_1F3825, MSGBOX_SIGN
	end
Route116_Text_1F3825: @ 81F3825
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "If you want to stop a Pokémon from\n"
	.string "evolving, press the B Button while it\l"
	.string "is trying to evolve.\l"
	.string "The startled Pokémon will stop.\p"
	.string "This is called an evolution cancel.$"


Route116_EventScript_1F2D7B:: @ 81F2D7B
	msgbox Route116_Text_1F38D4, MSGBOX_SIGN
	end
Route116_Text_1F38D4: @ 81F38D4
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "Your BAG has several POCKETS.\p"
	.string "Items you obtain are automatically\n"
	.string "placed in the appropriate POCKETS.\p"
	.string "No TRAINER can afford to be without\n"
	.string "a BAG of their own.$"

@ -----------------------------------------------------
@ Trainers

Route116_EventScript_1F2E89:: @ 81F2E89
	trainerbattle_single TRAINER_JOEY, Route116_Text_29BB79, Route116_Text_29BB9A
	msgbox Route116_Text_29BBC6, MSGBOX_AUTOCLOSE
	end
Route116_Text_29BB79: @ 829BB79
	.string "My Pokémon rule!\n"
	.string "Check them out!$"
Route116_Text_29BB9A: @ 829BB9A
	.string "Ouch! A scrape!\n"
	.string "I have to put on a bandage!$"
Route116_Text_29BBC6: @ 829BBC6
	.string "Bandages are signs of toughness!\n"
	.string "I've got another one!$"



Route116_EventScript_1F2EA0:: @ 81F2EA0
	trainerbattle_single TRAINER_JOSE, Route116_Text_29BBFD, Route116_Text_29BC25
	msgbox Route116_Text_29BC42, MSGBOX_AUTOCLOSE
	end
Route116_Text_29BBFD: @ 829BBFD
	.string "My Bug Pokémon are tough!\n"
	.string "Let's battle!$"
Route116_Text_29BC25: @ 829BC25
	.string "I lost!\n"
	.string "I thought I had you!$"
Route116_Text_29BC42: @ 829BC42
	.string "Bug Pokémon evolve quickly.\n"
	.string "So they get strong quickly, too.$"



Route116_EventScript_1F2EB7:: @ 81F2EB7
	trainerbattle_single TRAINER_JERRY_1, Route116_Text_29BD0C, Route116_Text_29BD66, Route116_EventScript_1F2EF8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F2F4E
	msgbox Route116_Text_29BD92, MSGBOX_DEFAULT
	release
	end
Route116_Text_29BD0C: @ 829BD0C
	.string "We learn all sorts of things at the\n"
	.string "Trainer's School.\p"
	.string "I want to test things out for real!$"
Route116_Text_29BD66: @ 829BD66
	.string "I slacked off in school…\n"
	.string "That's why I lost.$"
Route116_Text_29BD92: @ 829BD92
	.string "I'll have to redo some courses at\n"
	.string "the Trainer's School.\l"
	.string "If I don't, Roxanne will be steamed.$"
Route116_EventScript_1F2EF8:: @ 81F2EF8
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route116_Text_29BE71, MSGBOX_DEFAULT
	register_matchcall TRAINER_JERRY_1
	release
	end
Route116_Text_29BE71: @ 829BE71
	.string "I learned at the Trainer's School\n"
	.string "that a PokéNav can register trainers.\p"
	.string "I don't really get what that means,\n"
	.string "so can I just try it?$"
Route116_EventScript_1F2F4E:: @ 81F2F4E
	trainerbattle_rematch TRAINER_JERRY_1, Route116_Text_29BEF3, Route116_Text_29BF4C
	msgbox Route116_Text_29BF68, MSGBOX_AUTOCLOSE
	end
Route116_Text_29BEF3: @ 829BEF3
	.string "I've been studying seriously at the\n"
	.string "Trainer's School.\l"
	.string "I won't lose like I did last time.$"
Route116_Text_29BF4C: @ 829BF4C
	.string "Hunh?\n"
	.string "I studied diligently.$"
Route116_Text_29BF68: @ 829BF68
	.string "I'll have to redo some courses at\n"
	.string "the Trainer's School.\l"
	.string "If I don't, Roxanne will be steamed.$"



Route116_EventScript_1F2F65:: @ 81F2F65
	trainerbattle_single TRAINER_CLARK, Route116_Text_29BACD, Route116_Text_29BB0F
	msgbox Route116_Text_29BB31, MSGBOX_AUTOCLOSE
	end
Route116_Text_29BACD: @ 829BACD
	.string "If the tunnel doesn't go through, then\n"
	.string "I'll just go over the top.$"
Route116_Text_29BB0F: @ 829BB0F
	.string "Gasp… Gasp…\n"
	.string "Losing made me tired…$"
Route116_Text_29BB31: @ 829BB31
	.string "It's no big deal if there's no tunnel.\n"
	.string "To a hiker, mountains are roads!$"



Route116_EventScript_1F2F7C:: @ 81F2F7C
	trainerbattle_single TRAINER_JANICE, Route116_Text_29BC7F, Route116_Text_29BCB3
	msgbox Route116_Text_29BCCC, MSGBOX_AUTOCLOSE
	end
Route116_Text_29BC7F: @ 829BC7F
	.string "Let me teach you how strong my\n"
	.string "adorable Pokémon is!$"
Route116_Text_29BCB3: @ 829BCB3
	.string "You're a notch above me…$"
Route116_Text_29BCCC: @ 829BCCC
	.string "Pokémon that possess cuteness and\n"
	.string "power, that's ideal, I think.$"



Route116_EventScript_1F2F93:: @ 81F2F93
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_29BFC5, Route116_Text_29BFFA, Route116_EventScript_1F2FD4
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route116_EventScript_1F302A
	msgbox Route116_Text_29C010, MSGBOX_DEFAULT
	release
	end
Route116_Text_29BFC5: @ 829BFC5
	.string "I study at school, and I study on\n"
	.string "the way home, too!$"
Route116_Text_29BFFA: @ 829BFFA
	.string "I'm in shock--I lost?$"
Route116_Text_29C010: @ 829C010
	.string "Awww, I'll never become an elegant\n"
	.string "trainer like Roxanne this way!$"
Route116_EventScript_1F2FD4:: @ 81F2FD4
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route116_Text_29C096, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end
Route116_Text_29C096: @ 829C096
	.string "Oh, wow! Isn't that a PokéNav?\n"
	.string "I have one, too! Please register me!$"
Route116_EventScript_1F302A:: @ 81F302A
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_29C0DA, Route116_Text_29C11F
	msgbox Route116_Text_29C13B, MSGBOX_AUTOCLOSE
	end
Route116_Text_29C0DA: @ 829C0DA
	.string "I studied a whole lot since I saw you.\n"
	.string "You must see my achievements!$"
Route116_Text_29C11F: @ 829C11F
	.string "I'm in shock.\n"
	.string "I lost again?$"
Route116_Text_29C13B: @ 829C13B
	.string "You've beaten Roxanne?\n"
	.string "I can't beat you, then. Not yet.$"



Route116_EventScript_1F3041:: @ 81F3041
	trainerbattle_single TRAINER_SARAH, Route116_Text_29C173, Route116_Text_29C1B8
	msgbox Route116_Text_29C1EA, MSGBOX_AUTOCLOSE
	end
Route116_Text_29C173: @ 829C173
	.string "Just so you know, I've never once been\n"
	.string "bested by anyone at anything.$"
Route116_Text_29C1B8: @ 829C1B8
	.string "Oh, my goodness.\n"
	.string "This is a new experience for me.$"
Route116_Text_29C1EA: @ 829C1EA
	.string "My life of luxury affords me all that\n"
	.string "I could possibly desire.\p"
	.string "However, when it comes to Pokémon,\n"
	.string "my wealth has no meaning.$"



Route116_EventScript_1F3058:: @ 81F3058
	trainerbattle_single TRAINER_DAWSON, Route116_Text_29C266, Route116_Text_29C2C2
	msgbox Route116_Text_29C2DD, MSGBOX_AUTOCLOSE
	end
Route116_Text_29C266: @ 829C266
	.string "When you lay your eyes on my Pokémon's\n"
	.string "gorgeous fur, their beauty will render\l"
	.string "you helpless!$"
Route116_Text_29C2C2: @ 829C2C2
	.string "Oh, baby, say it isn't so!$"
Route116_Text_29C2DD: @ 829C2DD
	.string "Oh, no, no, no!\n"
	.string "You've mussed up my Pokémon's fur!\l"
	.string "You've ruined my hairdo, too!\l"
	.string "I'll have to call my stylist now!$"



Route116_EventScript_1F306F:: @ 81F306F
	trainerbattle_single TRAINER_DEVAN, Route116_Text_29C350, Route116_Text_29C365
	msgbox Route116_Text_29C380, MSGBOX_AUTOCLOSE
	end
Route116_Text_29C350: @ 829C350
	.string "We'll rock you hard!$"
Route116_Text_29C365: @ 829C365
	.string "Aiyiyi!\n"
	.string "No contest at all!$"
Route116_Text_29C380: @ 829C380
	.string "I should try different Pokémon\n"
	.string "types, that's what I ought to do.$"



Route116_EventScript_1F3086:: @ 81F3086
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_29C3C1, Route116_Text_29C3F7
	msgbox Route116_Text_29C418, MSGBOX_AUTOCLOSE
	end
Route116_Text_29C3C1: @ 829C3C1
	.string "It's a dead end up here.\n"
	.string "I'm bored, so can we battle?$"
Route116_Text_29C3F7: @ 829C3F7
	.string "That was fun even though I lost.$"
Route116_Text_29C418: @ 829C418
	.string "Want to stay here and keep\n"
	.string "me company?$"

