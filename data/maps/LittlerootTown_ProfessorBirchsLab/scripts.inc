#define LID_BIRCH 2
#define LID_RIVAL 3

LittlerootTown_ProfessorBirchsLab_MapScripts:: @ 81F9C91
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_MapScript1_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_MapScript2_FrameTable
	.byte 0

LittlerootTown_ProfessorBirchsLab_MapScript1_OnTransition: @ 81F9CA1
	call Common_EventScript_SetupRivalGender
	call LittlerootTown_ProfessorBirchsLab_EventScript_2720AD
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7
	compare VAR_0x40D3, 4
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3
	compare VAR_0x40D3, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CCD:: @ 81F9CCD
	specialvar VAR_RESULT, HasAllHoennMons
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9
	setobjectmovementtype LID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LID_RIVAL, 5, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CE9:: @ 81F9CE9
	setvar VAR_0x40D3, 4
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF3:: @ 81F9CF3
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9CF7:: @ 81F9CF7
	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
	setobjectmovementtype LID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
	setobjectxyperm LID_RIVAL, 5, 10
	end

@ -----------------------------------------------------

LittlerootTown_ProfessorBirchsLab_MapScript2_1F9D06: @ 81F9D06
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40
	map_script_2 VAR_0x40D3, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_0x40D3, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45
	map_script_2 VAR_0x40D3, 3, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_0x40D3, 6, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71
	map_script_2 VAR_0x40D3, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	map_script_2 VAR_0x40D3, 5, LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D40:: @ 81F9D40
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D45:: @ 81F9D45
	turnobject EVENT_OBJ_ID_PLAYER, 2
	addobject LID_BIRCH
	addobject LID_RIVAL
	turnobject LID_RIVAL, 2
	setobjectxy LID_RIVAL, 5, 5
	turnobject LID_BIRCH, 1
	setobjectxy LID_BIRCH, 6, 4
	turnobject 1, 4
	setobjectxy 1, 10, 10
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D71:: @ 81F9D71
	addobject LID_RIVAL
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1F9D75:: @ 81F9D75
	addobject 4
	addobject 5
	addobject 6
	addobject LID_RIVAL
	turnobject 4, 1
	setobjectxy 4, 8, 4
	turnobject 5, 1
	setobjectxy 5, 9, 4
	turnobject 6, 1
	setobjectxy 6, 10, 4
	turnobject LID_BIRCH, 1
	setobjectxy LID_BIRCH, 6, 4
	turnobject LID_RIVAL, 4
	setobjectxy LID_RIVAL, 5, 5
	end

@ -----------------------------------------------------

LittlerootTown_ProfessorBirchsLab_MapScript2_FrameTable: @ 81F9DB9
	map_script_2 VAR_BIRCH_LAB_STATE, 2, LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB
	map_script_2 VAR_BIRCH_LAB_STATE, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67
	map_script_2 VAR_0x40D3, 1, LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80
	map_script_2 VAR_0x40D3, 4, LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62
	.2byte 0

@ -----------------------------------------------------
@ Cutscene: After starter Select

LittlerootTown_ProfessorBirchsLab_EventScript_1F9DDB:: @ 81F9DDB
	lockall
	flagasdialog
	bufferleadmonspeciesname 0
	message LittlerootTown_ProfessorBirchsLab_Text_1FA74D
	waitmessage
	message LittlerootTown_ProfessorBirchsLab_Text_1FA74E, MSGTYPE_CDESCRIBE
	waitmessage
	playfanfare MUS_FANFA4
	waitfanfare
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8B1
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17
	end
LittlerootTown_ProfessorBirchsLab_Text_1FA74D: @ 81FA74D
	.string "Prof. Birch: So your name is {PLAYER}.\n"
	.string "That's quite a unique name!\p"
	.string "And you say you don't have a Pokémon\n"
	.string "of your own yet?\p"
	.string "Well, as thanks for rescuing me, you\n"
	.string "can keep the Pokémon you used earlier.\p"
	.string "$"
LittlerootTown_ProfessorBirchsLab_Text_1FA74E:
	.string "{PLAYER} received the {STR_VAR_1}!$"
LittlerootTown_ProfessorBirchsLab_Text_1FA8B1: @ 81FA8B1
	.string "Prof. Birch: While you're at it, why not\n"
	.string "give a nickname to that {STR_VAR_1}?$"

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E17:: @ 81F9E17
	flagasdialog
	setyesnotext gYN_No, gYN_Yeah
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA8F6, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end
LittlerootTown_ProfessorBirchsLab_Text_1FA8F6: @ 81FA8F6
	.string "Prof. Birch: If you work at Pokémon\n"
	.string "and gain experience, I think you'll make\l"
	.string "an pretty good trainer.\p"
	.string "My {RIVAL_son}, {RIVAL}, is also studying\n"
	.string "Pokémon while helping me out.\p"
	.string "{PLAYER}, don't you think it might be\n"
	.string "a good idea to go see {RIVAL}?$"

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48:: @ 81F9E48
	flagasdialog
	addvar VAR_TEMP_A, 1
	selectpointer_clamp LittlerootTown_ProfessorBirchsLab_TextArray_1FAA35, VAR_TEMP_A
	setyesnotext gYN_No, 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA35, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1F9E48
	end
LittlerootTown_ProfessorBirchsLab_Text_1FAA35: @ 81FAA35
	.string "Prof. Birch: Oh, don't be that way.\n"
	.string "You should go meet my kid.$"
.align 2
LittlerootTown_ProfessorBirchsLab_TextArray_1FAA35:
	.4byte gYN_Yeah
	.4byte gYN_Fine1
	.4byte gYN_Fine2
	.4byte gYN_Fine3
	.4byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E36:: @ 81F9E36
	flagasdialog
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA9D5
	clearflag FLAG_HIDE_ROUTE_101_BOY
	setvar VAR_BIRCH_LAB_STATE, 3
	@ TriHard Emerald: Force Save
	special ForceSaveGame
	waitstate
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Text_1FA9D5: @ 81FA9D5
	.string "Prof. Birch: Great!\n"
	.string "{RIVAL} should be happy, too.\p"
	.string "Get {RIVAL_them} to teach you what it\n"
	.string "means to be a trainer.$"

@ -----------------------------------------------------
@ Cutscene: After Rival Fight

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E67:: @ 81F9E67
	lockall
	flagasdialog
	applymovement LID_RIVAL, Common_Movement_WalkInPlaceLeft
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_1F9E78
	waitmovement 0
	message LittlerootTown_ProfessorBirchsLab_Text_1FAB22_1
	waitmessage
	applymovement LID_RIVAL, LittlerootTown_ProfessorBirchsLab_Movement_RivalRunOut
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerWatch
	waitmovement 0
	playse SE_TOY_KABE
	removeobject LID_RIVAL
	delay 40
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_PlayerWatch2
	
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAB22_2
	call LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAC4B
	@ closemessage
	giveitem_std ITEM_POKE_BALL, 5
	compare VAR_RESULT, 0
	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAE40
	setvar VAR_RESULT, 0
	setvar VAR_BIRCH_LAB_STATE, 5
	setflag FLAG_ADVENTURE_STARTED
	clearflag FLAG_HIDE_OLDALE_ROADBLOCK_AFTERMATCH
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	setvar VAR_0x4050, 3
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Movement_1F9E78: @ 81F9E78
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
LittlerootTown_ProfessorBirchsLab_Text_1FAB22_1: @ 81FAB22
	.string "Prof. Birch: Oh, hi, {PLAYER}!\p"
	.string "I heard you beat {RIVAL} on\n"
	.string "your first try. That's excellent!\p"
	.string "$"
LittlerootTown_ProfessorBirchsLab_Text_1FAB22_2:
	.string "…Don't worry about {RIVAL_them}.\p"
	.string "{RIVAL}'s been helping with my research\n"
	.string "for a long time.\p"
	.string "{RIVAL} has an extensive history as\n"
	.string "a trainer already.\p"
	.string "Here, {PLAYER}, I ordered this for my\n"
	.string "research, but I think you should have\l"
	.string "this Pokédex.$"
LittlerootTown_ProfessorBirchsLab_Movement_RivalRunOut: @ 81FA3E0
	emote_angry
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
LittlerootTown_ProfessorBirchsLab_Movement_PlayerWatch:
	delay_16
	face_down
	delay_16
	delay_16
	delay_8
	step_end
LittlerootTown_ProfessorBirchsLab_Movement_PlayerWatch2:
	delay_16
	delay_16
	delay_16
	face_up
	step_end
LittlerootTown_ProfessorBirchsLab_Text_1FAC4B: @ 81FAC4B
	.string "Prof. Birch: The Pokédex is a high-tech\n"
	.string "tool that automatically makes a record\l"
	.string "of any Pokémon you meet or catch.\p"
	.string "My {RIVAL_son}, {RIVAL}, goes everywhere\n"
	.string "with it.\p"
	.string "Whenever {RIVAL_they} catches a rare Pokémon\n"
	.string "and records its data in the Pokédex,\l"
	.string "why, {RIVAL} looks for me while I'm out\l"
	.string "doing fieldwork, and shows me.\p"
	.string "Oh, and you should take these too.$"
LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE:: @ 81FA3CE
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAEF3
	return
LittlerootTown_ProfessorBirchsLab_Text_1FAEF3: @ 81FAEF3
	.string "Oh? Your bag is full somehow.$"
LittlerootTown_ProfessorBirchsLab_Text_1FAE40:
	.string "Prof. Birch: It's more fun if you have\n"
	.string "a lot of Pokémon with you.\l"
	.string "And safer too.\p"
	.string "Good luck out there!$"
	

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex:: @ 81FA3AC
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FAC32, MSGTYPE_CDESCRIBE
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	special sub_81AFDA0
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setvar VAR_FREE_POKEBALL_STATE, 1
	return
LittlerootTown_ProfessorBirchsLab_Text_1FAC32: @ 81FAC32
	.string "{PLAYER} received the Pokédex!$"


@ -----------------------------------------------------
@ Cutscene: After Champion

LittlerootTown_ProfessorBirchsLab_EventScript_1F9E80:: @ 81F9E80
	lockall
	flagasdialog
	delay 30
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB16D, MSGBOX_DEFAULT
	closemessage
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F46
	waitmovement 0
	delay 20
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 10
	playse SE_TK_KASYA
	delay 20
	applymovement 3, Common_Movement_WalkInPlaceRight
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	selectpointer_ongender LittlerootTown_ProfessorBirchsLab_Text_1FB30F, LittlerootTown_ProfessorBirchsLab_Text_1FB38E
	msgbox_selected
	closemessage
	playse SE_PC_ON
	waitse
	delay 20
	applymovement 2, LittlerootTown_ProfessorBirchsLab_Movement_1F9F58
	waitmovement 0
	applymovement 3, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB419
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB436, MSGTYPE_CDESCRIBE
	waitmessage
	waitfanfare
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	@ "You've become champion..."
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466
	closemessage
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	setflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	setvar VAR_0x40D3, 2
	setvar VAR_SCOTT_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_NATIONAL_DEX
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB16D: @ 81FB16D
	.string "Prof. Birch: Now…\p"
	.string "{PLAYER} and {RIVAL}, I've had the two\n"
	.string "of you help me study Pokémon.\p"
	.string "Thanks to your help, new facts\n"
	.string "are coming to light.\p"
	.string "It appears that in the Hoenn region,\n"
	.string "there are also Pokémon from other\l"
	.string "regions.\p"
	.string "It goes to show how rich and varied\n"
	.string "the natural environments of Hoenn\l"
	.string "happen to be.\p"
	.string "That's why I think it's necessary for\n"
	.string "me to upgrade your Pokédex to\l"
	.string "the NATIONAL Mode.\p"
	.string "Here, let me see your Pokédex units.$"
LittlerootTown_ProfessorBirchsLab_Text_1FB419: @ 81FB419
	.string "Prof. Birch: Okay, all done!$"
LittlerootTown_ProfessorBirchsLab_Text_1FB436: @ 81FB436
	.string "{PLAYER}'s Pokédex was upgraded\n"
	.string "to the NATIONAL Mode!$"
LittlerootTown_ProfessorBirchsLab_Movement_1F9F46: @ 81F9F46
	walk_left
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end
LittlerootTown_ProfessorBirchsLab_Movement_1F9F58: @ 81F9F58
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_ProfessorBirchsLab_Text_1FB30F: @ 81FB30F
	.string "May: Eheheh!\p"
	.string "It's so cool that even my Pokédex\n"
	.string "is getting updated!\p"
	.string "It's because you went out and caught\n"
	.string "so many Pokémon, {PLAYER}!$"
LittlerootTown_ProfessorBirchsLab_Text_1FB38E: @ 81FB38E
	.string "Brendan: I went out all over Hoenn\n"
	.string "and checked out Pokémon.\p"
	.string "You can thank me for getting\n"
	.string "the NATIONAL Mode Pokédex.\p"
	.string "Yep, you're lucky, {PLAYER}!$"

@ -----------------------------------------------------
@ Cutscene: After Pokedex Complete

LittlerootTown_ProfessorBirchsLab_EventScript_1F9F62:: @ 81F9F62
	lockall
	flagasdialog
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C
	waitmovement 0
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB5F9
	setvar VAR_0x40D3, 5
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB5F9: @ 81FB5F9
	.string "Prof. Birch: Oh, {PLAYER}!\n"
	.string "Let's have a look at your Pokédex.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Yes, there's no doubt about it.\p"
	.string "You really have completed the Hoenn\n"
	.string "region's Pokédex.\p"
	.string "That's more than just impressive.\p"
	.string "I have a gift for you.\p"
	.string "Consider it my show of appreciation\n"
	.string "for the fantastic work you've done.\p"
	.string "My gift is a rare Pokémon only found\n"
	.string "in another region!\p"
	.string "You can have any one of these\n"
	.string "three Pokémon!$"
LittlerootTown_ProfessorBirchsLab_Movement_1F9F7C: @ 81F9F7C
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end


LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F:: @ 81FA24F
	playfanfare MUS_FANFA4
	message LittlerootTown_ProfessorBirchsLab_Text_1FB9D7, MSGTYPE_DESCRIBE
	waitmessage
	waitfanfare
	return
LittlerootTown_ProfessorBirchsLab_Text_1FB9D7: @ 81FB9D7
	.string "{PLAYER} received the {STR_VAR_1}\n"
	.string "from Prof. Birch!$"


LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2:: @ 81FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_2737A0
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD:: @ 81FA0FD
	erasemonpic
	flagasdialog
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBA2C
	setvar VAR_0x40D3, 6
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Text_1FBA2C: @ 81FBA2C
	.string "Prof. Birch: Listen, {PLAYER}.\n"
	.string "You've completed the Hoenn Pokédex,\l"
	.string "but your Pokémon journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is Pokémon.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"


LittlerootTown_ProfessorBirchsLab_EventScript_1F9FBB:: @ 81F9FBB
	release
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	drawmonpic SPECIES_CYNDAQUIL, 10, 3
	flagasdialog
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB7F6
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB7F6: @ 81FB7F6
	.string "Prof. Birch: The FIRE Pokémon\n"
	.string "CYNDAQUIL caught your eye!\p"
	.string "You're as sharp as ever!\p"
	.string "So the CYNDAQUIL is your choice?$"
LittlerootTown_ProfessorBirchsLab_EventScript_1FA06C:: @ 81FA06C
	bufferspeciesname 0, SPECIES_CYNDAQUIL
	setvar VAR_TEMP_1, 155
	givemon SPECIES_CYNDAQUIL, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA0A1:: @ 81FA0A1
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA0CC:: @ 81FA0CC
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 4
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	end


LittlerootTown_ProfessorBirchsLab_EventScript_1F9FEF:: @ 81F9FEF
	release
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	drawmonpic SPECIES_TOTODILE, 10, 3
	flagasdialog
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB869
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB869: @ 81FB869
	.string "Prof. Birch: The WATER Pokémon\n"
	.string "TOTODILE is your choice!\p"
	.string "You know how to pick a good one.\p"
	.string "So, you'll take the TOTODILE?$"
LittlerootTown_ProfessorBirchsLab_EventScript_1FA10D:: @ 81FA10D
	bufferspeciesname 0, SPECIES_TOTODILE
	setvar VAR_TEMP_1, 158
	givemon SPECIES_TOTODILE, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA142
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA142:: @ 81FA142
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA16D:: @ 81FA16D
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 5
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	end


LittlerootTown_ProfessorBirchsLab_EventScript_1FA023:: @ 81FA023
	release
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA057
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	drawmonpic SPECIES_CHIKORITA, 10, 3
	flagasdialog
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB8E0
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA061
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB8E0: @ 81FB8E0
	.string "Prof. Birch: The GRASS Pokémon\n"
	.string "CHIKORITA is your choice!\p"
	.string "You sure know what you're doing.\p"
	.string "So, you'll take the CHIKORITA?$"
LittlerootTown_ProfessorBirchsLab_EventScript_1FA1AE:: @ 81FA1AE
	bufferspeciesname 0, SPECIES_CHIKORITA
	setvar VAR_TEMP_1, 152
	givemon SPECIES_CHIKORITA, 5, ITEM_NONE
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E
	erasemonpic
	goto LittlerootTown_ProfessorBirchsLab_EventScript_273811
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA1E3:: @ 81FA1E3
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	call LittlerootTown_ProfessorBirchsLab_EventScript_27378B
	call Common_EventScript_NameReceivedPokemon
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0FD
	end
LittlerootTown_ProfessorBirchsLab_EventScript_1FA20E:: @ 81FA20E
	call LittlerootTown_ProfessorBirchsLab_EventScript_1FA24F
	removeobject 6
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	call LittlerootTown_ProfessorBirchsLab_EventScript_273797
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA0F2
	end


LittlerootTown_ProfessorBirchsLab_EventScript_1FA061:: @ 81FA061
	erasemonpic
	flagasdialog
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB959
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB959: @ 81FB959
	.string "Prof. Birch: Take your time before\n"
	.string "you decide.\p"
	.string "They're all invaluable Pokémon.$"


LittlerootTown_ProfessorBirchsLab_EventScript_1FA057:: @ 81FA057
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FBAF8, MSGBOX_DEFAULT
	releaseall
	end
LittlerootTown_ProfessorBirchsLab_Text_1FBAF8: @ 81FBAF8
	.string "You received the promised Pokémon.\n"
	.string "Better leave the others alone.$"


@ -----------------------------------------------------
@ People

LittlerootTown_ProfessorBirchsLab_EventScript_BirchAide:: @ 81F9F84
	lock
	faceplayer
	flagasdialog
	compare VAR_BIRCH_LAB_STATE, 3
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1
	goto_if_set FLAG_BIRCH_AIDE_MET, LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA4E2, MSGBOX_DEFAULT
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	setflag FLAG_BIRCH_AIDE_MET
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FA4E2: @ 81FA4E2
	.string "Hunh? Prof. Birch? \n"
	.string "He's away on fieldwork right now.\p"
	.string "… I'm sure he did tell you to see him\n"
	.string "here, but he's not here right now.\p"
	.string "… … Yes, I understand, you were\n"
	.string "expecting him to be here! He is not!\p"
	.string "I believe he went north of town.\n"
	.string "Go bother him there, and not me.$"
LittlerootTown_ProfessorBirchsLab_EventScript_1F9FB1:: @ 81F9FB1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA6CE, MSGBOX_DEFAULT
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FA6CE: @ 81FA6CE
	.string "Prof. Birch is studying the habitats\n"
	.string "and distribution of Pokémon.\p"
	.string "The Prof enjoys {RIVAL}'s help, too.\n"
	.string "There's a lot of love there.$"
LittlerootTown_ProfessorBirchsLab_EventScript_1F9FA7:: @ 81F9FA7
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FA641, MSGBOX_DEFAULT
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FA641: @ 81FA641
	.string "The Prof isn't one for doing desk work.\n"
	.string "He's the type of person who would\l"
	.string "rather go outside and experience\l"
	.string "things than read about them here.$"



LittlerootTown_ProfessorBirchsLab_EventScript_ProfBirch:: @ 81FA25A
	lock
	faceplayer
	flagasdialog
	compare VAR_0x40D3, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A
	compare VAR_0x40D3, 2
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA294
	goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_1FA2D2
	goto LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E
	end

LittlerootTown_ProfessorBirchsLab_EventScript_1FA28A:: @ 81FA28A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB787, MSGBOX_DEFAULT
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB787: @ 81FB787
	.string "Prof. Birch: These are rare Pokémon\n"
	.string "only found in another region!\p"
	.string "You can have any one of these\n"
	.string "three Pokémon!$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA294:: @ 81FA294
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB466, MSGBOX_DEFAULT
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB466: @ 81FB466
	.string "Prof. Birch: But listen.\n"
	.string "You've become the Champion,\l"
	.string "but your Pokémon journey isn't over.\p"
	.string "There is no end to the road\n"
	.string "that is Pokémon.\p"
	.string "Somewhere, there is a grassy patch\n"
	.string "that's waiting for you!$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA29E:: @ 81FA29E
	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare VAR_0x40D3, 3
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_272141
	compare VAR_BIRCH_LAB_STATE, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAA74, MSGBOX_DEFAULT
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FAA74: @ 81FAA74
	.string "Prof. Birch: {RIVAL}?\n"
	.string "Gone home, I think.\p"
	.string "Or maybe that kid's scrabbling around\n"
	.string "in tall grass again somewhere…\p"
	.string "If you or your Pokémon get tired,\n"
	.string "you should get some rest at home.$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA3C4:: @ 81FA3C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAD6F, MSGBOX_DEFAULT
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FAD6F: @ 81FAD6F
	.string "Prof. Birch: Countless Pokémon\n"
	.string "await you!\p"
	.string "Argh, I'm getting the itch to get out\n"
	.string "and do fieldwork again!$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA2D2:: @ 81FA2D2
Route101_EventScript_1FA2D2:: @ 81FA2D2
	msgbox Route101_Text_2B5F52, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox Route101_Text_2B603A, MSGBOX_CDESCRIBE
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_0x40DA, 2
	release
	end
Route101_Text_2B5F52: @ 82B5F52
	.string "Prof. Birch: Oh, {PLAYER}!\n"
	.string "I've already heard about you!\p"
	.string "It seems your PokéNav's been\n"
	.string "upgraded with Match Call.\p"
	.string "Well, I should register, too!\p"
	.string "That way, I'd be able to examine\n"
	.string "your Pokédex even while you're\l"
	.string "out in the field.\p"
	.string "… … … … … …$"
Route101_Text_2B603A: @ 82B603A
	.string "Registered Prof. Birch\n"
	.string "in the PokéNav.$"

	.string "Prof. Birch: When one has both\n"
	.string "the Pokédex and PokéNav, studying\l"
	.string "Pokémon becomes more fun, eh?$"


@ LittlerootTown_ProfessorBirchsLab_EventScript_1FA352:: @ 81FA352
@ 	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FADD7, MSGBOX_DEFAULT
@ 	giveitem_std ITEM_POKE_BALL, 5
@ 	compare VAR_RESULT, 0
@ 	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3CE
@ 	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAE40, MSGBOX_DEFAULT
@ 	setvar VAR_RESULT, 0
@ 	return

@ LittlerootTown_ProfessorBirchsLab_EventScript_1FA37F:: @ 81FA37F
@ 	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF3F, MSGBOX_DEFAULT
@ 	giveitem_std ITEM_POKE_BALL, 5
@ 	compare VAR_RESULT, 0
@ 	call_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7
@ 	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FAF8E, MSGBOX_DEFAULT
@ 	setvar VAR_RESULT, 1
@ 	return

@ LittlerootTown_ProfessorBirchsLab_EventScript_1FA3D7:: @ 81FA3D7
@ 	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB05D, MSGBOX_DEFAULT
@ 	return



LittlerootTown_ProfessorBirchsLab_EventScript_Rival:: @ 81FA3EC
	lock
	faceplayer
	flagasdialog
	compare VAR_0x40D3, 5
	goto_if_eq LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A
	compare VAR_0x40D3, 6
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA465
	compare VAR_0x40D3, 2
	goto_if_ge LittlerootTown_ProfessorBirchsLab_EventScript_1FA490
	selectpointer_ongender LittlerootTown_ProfessorBirchsLab_Text_1FAF08, LittlerootTown_ProfessorBirchsLab_Text_1FB073
	msgbox_selected
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FAF08: @ 81FAF08
	.string "May: I wonder where I should go look\n"
	.string "for Pokémon next?$"
LittlerootTown_ProfessorBirchsLab_Text_1FB073: @ 81FB073
	.string "Brendan: Where should I look for\n"
	.string "Pokémon next…$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA43A:: @ 81FA43A
	selectpointer_ongender LittlerootTown_ProfessorBirchsLab_Text_1FBB68, LittlerootTown_ProfessorBirchsLab_Text_1FBC2D
	msgbox_selected
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FBB68: @ 81FBB68
	.string "May: {PLAYER}, after this…\n"
	.string "What are you going to do?\p"
	.string "Are you going to keep battling\n"
	.string "and sharpening your skills?\p"
	.string "Or are you going to try filling\n"
	.string "the National Pokédex?\p"
	.string "I'm staying here to help the PROF.$"
LittlerootTown_ProfessorBirchsLab_Text_1FBC2D: @ 81FBC2D
	.string "Brendan: Rather than collecting\n"
	.string "Pokémon, I prefer slowly and \l"
	.string "steadily raising the one I chose.$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA465:: @ 81FA465
	selectpointer_ongender LittlerootTown_ProfessorBirchsLab_Text_1FBC8D, LittlerootTown_ProfessorBirchsLab_Text_1FBCD2
	msgbox_selected
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FBC8D: @ 81FBC8D
	.string "May: Oh, hi, {PLAYER}!\n"
	.string "Have you gone to that place,\l"
	.string "the Battle Frontier?$"
LittlerootTown_ProfessorBirchsLab_Text_1FBCD2: @ 81FBCD2
	.string "Brendan: Hey, {PLAYER}!\n"
	.string "Have you gone out to that place,\l"
	.string "the Battle Frontier?$"

LittlerootTown_ProfessorBirchsLab_EventScript_1FA490:: @ 81FA490
	selectpointer_ongender LittlerootTown_ProfessorBirchsLab_Text_1FB528, LittlerootTown_ProfessorBirchsLab_Text_1FB58A
	msgbox_selected
	release
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB528: @ 81FB528
	.string "May: I think I'll take a short break\n"
	.string "from fieldwork.\p"
	.string "I think I'll help the Prof here for\n"
	.string "a while.$"
LittlerootTown_ProfessorBirchsLab_Text_1FB58A: @ 81FB58A
	.string "Brendan: For the time being,\n"
	.string "I'm taking a break from fieldwork.\p"
	.string "I'll be helping out the Prof here\n"
	.string "for a while.$"


@ -----------------------------------------------------
@ Objects in the world

LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC1:: @ 81FA4BB
	goto_if_set FLAG_TEMP_5, LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC1_A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ResearchPC1, MSGBOX_DESCRIBE
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	setflag FLAG_TEMP_5
	end
LittlerootTown_ProfessorBirchsLab_Text_ResearchPC1: @ 81FB0E7
	.string "It's a PC used for research.\p"
	.string "You rearrange the desktop icons to\n"
	.string "make a crude knob.$"
LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC1_A:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ResearchPC1A, MSGBOX_DESCRIBE
	end
LittlerootTown_ProfessorBirchsLab_Text_ResearchPC1A:
	.string "It's a PC used for anatomical research.$"


LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC2:: @ 81FA4BB
	goto_if_set FLAG_TEMP_6, LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC2_A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ResearchPC2, MSGBOX_DESCRIBE
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	setflag FLAG_TEMP_6
	end
LittlerootTown_ProfessorBirchsLab_Text_ResearchPC2: @ 81FB0E7
	.string "It's a PC used for research.\p"
	.string "You change the desktop background to\n"
	.string "fill the screen with an old gif.$"
LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC2_A:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ResearchPC2A, MSGBOX_DESCRIBE
	end
LittlerootTown_ProfessorBirchsLab_Text_ResearchPC2A:
	.string "It's a PC used for research of\n"
	.string "babies' ability to dance.$"


LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC3:: @ 81FA4BB
	goto_if_set FLAG_TEMP_7, LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC3_A
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ResearchPC3, MSGBOX_DESCRIBE
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	setflag FLAG_TEMP_7
	end
LittlerootTown_ProfessorBirchsLab_Text_ResearchPC3: @ 81FB0E7
	.string "It's a PC used for research.\p"
	.string "You press a set of keys on the\n"
	.string "keyboard, and the screen flickers.$"
LittlerootTown_ProfessorBirchsLab_EventScript_ResearchPC3_A:
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ResearchPC3A, MSGBOX_DESCRIBE
	end
LittlerootTown_ProfessorBirchsLab_Text_ResearchPC3A:
	.string "It's a PC used for upside-down research.$"


LittlerootTown_ProfessorBirchsLab_EventScript_PokemonBooks:: @ 81FA4C4
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB124, MSGBOX_DESCRIBE
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB124: @ 81FB124
	.string "It's crammed with books on Pokémon.$"


LittlerootTown_ProfessorBirchsLab_EventScript_HardBook:: @ 81FA4CD
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB148, MSGBOX_DESCRIBE
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB148: @ 81FB148
	.string "It's a book that's too hard to read.$"


LittlerootTown_ProfessorBirchsLab_EventScript_HealMachine:: @ 81FA3E3
	msgbox LittlerootTown_ProfessorBirchsLab_Text_1FB0A2, MSGBOX_DESCRIBE
	end
LittlerootTown_ProfessorBirchsLab_Text_1FB0A2: @ 81FB0A2
	.string "It's a serious-looking machine.\n"
	.string "The prof must use this for research.$"


@ -----------------------------------------------------

LittlerootTown_ProfessorBirchsLab_EventScript_1FA4D6:: @ 81FA4D6
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_1FBD1A
	waitmessage
	clearflag FLAG_SCOTT_CALL_NATIONAL_DEX
	releaseall
	end



@ LittlerootTown_ProfessorBirchsLab_Text_1FADD7: @ 81FADD7
@ 	.string "May: Oh, wow, {PLAYER}!\n"
@ 	.string "You got a Pokédex, too!\p"
@ 	.string "That's great! Just like me!\n"
@ 	.string "I've got something for you, too!$"

@ LittlerootTown_ProfessorBirchsLab_Text_1FAE40: @ 81FAE40
@ 	.string "May: It's fun if you can get a lot of\n"
@ 	.string "Pokémon!\p"
@ 	.string "I'm going to look all over the place\n"
@ 	.string "because I want different Pokémon.\p"
@ 	.string "If I find any cute Pokémon, I'll catch\n"
@ 	.string "them with POKé BALLS!$"

@ LittlerootTown_ProfessorBirchsLab_Text_1FAEF3: @ 81FAEF3
@ 	.string "Oh? Your BAG's full.$"



@ LittlerootTown_ProfessorBirchsLab_Text_1FAF3F: @ 81FAF3F
@ 	.string "Brendan: Huh…\n"
@ 	.string "So you got a Pokédex, too.\p"
@ 	.string "Well then, here.\n"
@ 	.string "I'll give you these.$"

@ LittlerootTown_ProfessorBirchsLab_Text_1FAF8E: @ 81FAF8E
@ 	.string "Brendan: You know it's more fun to\n"
@ 	.string "have a whole bunch of Pokémon.\p"
@ 	.string "I'm going to explore all over the place\n"
@ 	.string "to find different Pokémon.\p"
@ 	.string "If I find any cool Pokémon, you bet\n"
@ 	.string "I'll try to get them with POKé BALLS.$"

@ LittlerootTown_ProfessorBirchsLab_Text_1FB05D: @ 81FB05D
@ 	.string "Hey, your BAG's full.$"



LittlerootTown_ProfessorBirchsLab_Text_1FBD1A: @ 81FBD1A
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"

#undef LID_BIRCH
#undef LID_RIVAL
