LittlerootTown_MapScripts:: @ 81E7DCB
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MapScript1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScript2_FrameTable
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_MapScript2_WarpIntoMap
	.byte 0

#define LID_DAD 4

LittlerootTown_MapScript1_OnTransition: @ 81E7DDB
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	call Common_EventScript_SetupRivalGender
	compare VAR_LITTLEROOT_INTRO_STATE, 2
	call_if_eq LittlerootTown_EventScript_1E7E67
	call_if_unset FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_1E7E6F
	compare VAR_0x4050, 3
	call_if_eq LittlerootTown_EventScript_1E7E92
	compare VAR_LITTLEROOT_HOUSES_STATE, 4
	call_if_eq LittlerootTown_EventScript_1E7E5C
	compare VAR_LITTLEROOT_HOUSES_STATE_2, 4
	call_if_eq LittlerootTown_EventScript_1E7E5C
	compare VAR_OLDALE_STATE, 1
	call_if_eq LittlerootTown_EventScript_1E7E53
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	call_if_eq LittlerootTown_EventScript_1E7E4F
	compare VAR_0x40D3, 1
	call_if_eq LittlerootTown_EventScript_1E7E4B
	compare VAR_0x40D3, 2
	call_if_eq LittlerootTown_EventScript_1E7E45
	end

LittlerootTown_MapScript2_FrameTable: @ 81E7EC1
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_EventScript_1E7EDB
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 2, LittlerootTown_EventScript_1E7EF9
	map_script_2 VAR_0x40D3, 1, LittlerootTown_EventScript_1E7FB1
	.2byte 0

LittlerootTown_MapScript2_WarpIntoMap: @ 81E7FE2
	map_script_2 VAR_0x40D3, 1, LittlerootTown_EventScript_1E7FEC
	.2byte 0

@ -----------------------------------------------------

LittlerootTown_EventScript_1E7E67:: @ 81E7E67
	setobjectxyperm LID_DAD, 14, 8
	return

LittlerootTown_EventScript_1E7E6F:: @ 81E7E6F
	compare VAR_0x4050, 0
	goto_if_eq LittlerootTown_EventScript_1E7E86
	setobjectxyperm 1, 10, 1
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return
LittlerootTown_EventScript_1E7E86:: @ 81E7E86
	setobjectxyperm 1, 7, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_DOWN
	return

LittlerootTown_EventScript_1E7E92:: @ 81E7E92
	@ clearflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setobjectmovementtype LID_DAD, MOVEMENT_TYPE_FACE_DOWN
	@ checkplayergender
	@ compare VAR_RESULT, MALE
	@ call_if_eq LittlerootTown_EventScript_1E7EB1
	@ compare VAR_RESULT, FEMALE
	@ call_if_eq LittlerootTown_EventScript_1E7EB9
	return
@ LittlerootTown_EventScript_1E7EB1:: @ 81E7EB1
@ 	setobjectxyperm LID_DAD, 5, 9
@ 	return
@ LittlerootTown_EventScript_1E7EB9:: @ 81E7EB9
@ 	setobjectxyperm LID_DAD, 14, 9
@ 	return

LittlerootTown_EventScript_1E7E5C:: @ 81E7E5C
	setvar VAR_LITTLEROOT_HOUSES_STATE, 5
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 5
	return

LittlerootTown_EventScript_1E7E53:: @ 81E7E53
	setvar VAR_OLDALE_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	return

LittlerootTown_EventScript_1E7E4F:: @ 81E7E4F
	setflag FLAG_RIVAL_LEFT_FOR_ROUTE103
	return

LittlerootTown_EventScript_1E7E4B:: @ 81E7E4B
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LittlerootTown_EventScript_1E7E45:: @ 81E7E45
	setvar VAR_0x40D3, 3
	return


LittlerootTown_EventScript_1E7EDB:: @ 81E7EDB
	lockall
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_1E7F17
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 255, 8, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_1E7EF9:: @ 81E7EF9
	lockall
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	call LittlerootTown_EventScript_1E7F17
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	warpsilent MAP_LITTLEROOT_TOWN_MAYS_HOUSE_1F, 255, 2, 8
	waitstate
	releaseall
	end

LittlerootTown_EventScript_1E7F17:: @ 81E7F17
	delay 15
	playse SE_DANSA
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_Intro_ProtagJumpOutOfVan
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LID_DAD
	applymovement LID_DAD, LittlerootTown_Movement_Intro_Dad1
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	applymovement LID_DAD, LittlerootTown_Movement_Intro_Dad2
	waitmovement 0
	flagasdialog
	setyesnotext gYN_Yep_, gYN_Elipsis2
	msgbox LittlerootTown_Text_Dad_Opening1, MSGBOX_YESNO
	msgbox LittlerootTown_Text_Dad_Opening2, MSGBOX_DEFAULT
	closemessage
	applymovement LID_DAD, LittlerootTown_Movement_Intro_Dad3
	@ applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_Intro_Protag2
	waitmovement 0
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_Intro_Dad4
	@ waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_Intro_Protag2
	waitmovement 0
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MOM_OUTSIDE
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_PETALBURG_CITY
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_FAT_MAN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	return
LittlerootTown_Movement_Intro_ProtagJumpOutOfVan: @ 81E7FAC
	jump_right
	delay_16
	delay_16
	delay_16
	step_end
LittlerootTown_Movement_Intro_Dad1: @ 81E7F98
	walk_down
	step_end
LittlerootTown_Movement_Intro_Dad2: @ 81E7F9A
	walk_down
	walk_in_place_fastest_left
	step_end
LittlerootTown_Text_Dad_Opening1: @ 81E86BC
	.string "Dad: Hey, kiddo.\p"
	.string "How was the ride back there? I'm\n"
	.string "sorry they didn't have room up front.\p"
	.string "So… This is Littleroot Town.$"
	@ Hm… / ………
LittlerootTown_Text_Dad_Opening2:
	.string "Don't start so soon with that attitude.\n"
	.string "Give it a chance first, please?\p"
	.string "Here, let's check out our new home.\n"
	.string "You'll have your own bedroom.\l"
	.string "You can mope all you want in there.\p"
	.string "Com'on, let's go inside.$"
	@ Dad opens door and steps back. Player Moves slowly inside.
	@ Cutscene continues inside.
LittlerootTown_Movement_Intro_Dad3: @ 81E7F9D
	delay_16
	delay_8
	walk_up
	step_end
LittlerootTown_Movement_Intro_Dad4: @ 81E7FA1
	walk_in_place_slow_up
	delay_16
	walk_in_place_down
	delay_16
	delay_16
	delay_16
	face_left
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	walk_left
	walk_up
	set_invisible
	delay_16
	step_end

LittlerootTown_Movement_Intro_Protag2: @ 81E7FA4
	delay_8
	face_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_right
	delay_16
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	set_invisible
	delay_16
	step_end
LittlerootTown_Movement_Intro_Protag3: @ 81E7FA9
	walk_up
	walk_up
	step_end



	







LittlerootTown_EventScript_1E7FB1:: @ 81E7FB1
	lockall
	playse SE_PIN
	flagasdialog
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	delay 80
	msgbox LittlerootTown_Text_1E8DA2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_RIVAL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCH
	delay 20
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 255, 6, 5
	waitstate
	releaseall
	end
LittlerootTown_Text_1E8DA2: @ 81E8DA2
	.string "Prof. Birch: Well, well, {PLAYER}!\n"
	.string "That was good work out there!\p"
	.string "I knew there was something special\n"
	.string "about you when I first saw you,\l"
	.string "but I never expected this.\p"
	.string "Oh, yes. Do you still have the Pokédex\n"
	.string "I gave you?\p"
	.string "I have something to show you.\n"
	.string "Let's go to my lab.$"


LittlerootTown_EventScript_1E7FEC:: @ 81E7FEC
	addobject 8
	addobject 7
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_EventScript_1E8004
	goto LittlerootTown_EventScript_1E8013
	end
LittlerootTown_EventScript_1E8004:: @ 81E8004
	setobjectxy 7, 6, 10
	setobjectxy 8, 5, 10
	end
LittlerootTown_EventScript_1E8013:: @ 81E8013
	setobjectxy 7, 13, 10
	setobjectxy 8, 14, 10
	end

@ -----------------------------------------------------
@ Signs

LittlerootTown_EventScript_1E8151:: @ 81E8151
	msgbox LittlerootTown_Text_1E8D32, MSGBOX_SIGN
	end
LittlerootTown_Text_1E8D32: @ 81E8D32
	.string "{PLACE}Littleroot Town{END}\n"
	.string "“A town that can't be shaded any hue.”$"


LittlerootTown_EventScript_1E815A:: @ 81E815A
	msgbox LittlerootTown_Text_1E8D69, MSGBOX_SIGN
	end
LittlerootTown_Text_1E8D69: @ 81E8D69
	.string "{PLACE}Prof. Birch's Pokémon Lab{END}$"


LittlerootTown_EventScript_1E8163:: @ 81E8163
	lockall
	selectpointer_ongender LittlerootTown_Text_1E8D83, LittlerootTown_Text_1E8D8E
	msgbox_selected MSGBOX_SIGN
	releaseall
	end
LittlerootTown_Text_1E8D83: @ 81E8D83
	.string "{PLACE}{PLAYER}'s House{END}$"


LittlerootTown_EventScript_1E818F:: @ 81E818F
	lockall
	selectpointer_ongender LittlerootTown_Text_1E8D8E, LittlerootTown_Text_1E8D83
	msgbox_selected MSGBOX_SIGN
	releaseall
	end
LittlerootTown_Text_1E8D8E: @ 81E8D8E
	.string "{PLACE}Prof. Birch's House{END}$"


@ -----------------------------------------------------
@ People

LittlerootTown_EventScript_ScienceGuy:: @ 81E8022
	msgbox LittlerootTown_Text_1E8ACF, MSGBOX_NPC
	end
LittlerootTown_Text_1E8ACF: @ 81E8ACF
	.string "Did you know you can use Poké Balls\n"
	.string "to catch up to six Pokémon?!\p"
	.string "The power of science is staggering!$"


LittlerootTown_EventScript_RandomBoy:: @ 81E802B
	goto_if_set FLAG_TEMP_5, LittlerootTown_EventScript_RandomBoy_2
	lock 
	faceplayer
	message LittlerootTown_Text_1E8B25, MSGTYPE_DIALOG
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_Angry
	applymovement THIS_EVENT, Common_Movement_AngryReaction
	message LittlerootTown_Text_1E8B26, MSGTYPE_DIALOG
	waitmovement 0
	waitmessage
	waitbuttonpress
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	setflag FLAG_TEMP_5
	release
	end
LittlerootTown_Text_1E8B25: @ 81E8B25
	.string "Prof. Birch and his wife run the lab\n"
	.string "in town. They're quite a power couple.\p"
	.string "His {RIVAL_son} has also taken to\n"
	.string "helping {RIVAL_their} parents with research.\p"
	.string "It's amazing what a family can do\n"
	.string "together!\p"
	.string "$"
LittlerootTown_Text_1E8B26:
	.string "… … … Woah! I-I'm sorry! I didn't mean\n"
	.string "anything by it!$"
LittlerootTown_EventScript_RandomBoy_2:
	msgbox LittlerootTown_Text_1E8B252, MSGBOX_NPC
	end
LittlerootTown_Text_1E8B252:
	.string "I-I'm sorry. Don't yell anymore, please.$"
LittlerootTown_Movement_RandomBoy:
	@ emote_exclamation_mark
	emote_angry
	step_end
	


@ -----------------------------------------------------
@ Little boy who stops you

LittlerootTown_EventScript_1E8034:: @ 81E8034
	lock
	faceplayer
	flagasdialog
	goto_if_set FLAG_ADVENTURE_STARTED, LittlerootTown_EventScript_1E8087
	goto_if_set FLAG_RESCUED_BIRCH, LittlerootTown_EventScript_1E807A
	compare VAR_0x4050, 0
	goto_if_ne LittlerootTown_EventScript_1E805D
	msgbox LittlerootTown_Text_1E8BB8, MSGBOX_DEFAULT
	release
	end
LittlerootTown_Text_1E8BB8: @ 81E8BB8
	.string "Um, um, um!\p"
	.string "If you go outside and go in the grass,\n"
	.string "wild Pokémon will jump out!$"
LittlerootTown_EventScript_1E8087:: @ 81E8087
	msgbox LittlerootTown_Text_1E8D07, MSGBOX_DEFAULT
	release
	end
LittlerootTown_Text_1E8D07: @ 81E8D07
	.string "Are you going to catch Pokémon?\n"
	.string "Good luck!$"
LittlerootTown_EventScript_1E807A:: @ 81E807A
	msgbox LittlerootTown_Text_1E8CE3, MSGBOX_DEFAULT
	release
	end
LittlerootTown_Text_1E8CE3: @ 81E8CE3
	.string "Boy, am I glad you went and rescued\n"
	.string "the Professor.$"
LittlerootTown_EventScript_1E805D:: @ 81E805D
	msgbox LittlerootTown_Text_1E8C3A, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_0x4050, 2
	release
	end
LittlerootTown_Text_1E8C3A: @ 81E8C3A
	.string "I can hear someone shouting down the\n"
	.string "road here.\p"
	.string "What should I do? I don't know what to\n"
	.string "do! Somebody has to go help…$"

LittlerootTown_EventScript_1E811F:: @ 81E811F
	lockall
	flagasdialog
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox LittlerootTown_Text_1E8C3A, MSGBOX_DEFAULT
	closemessage
	applymovement 1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setvar VAR_0x4050, 2
	releaseall
	end

LittlerootTown_EventScript_1E80AD:: @ 81E80AD
	flagasdialog
	msgbox LittlerootTown_Text_1E8BB8, MSGBOX_DEFAULT
	closemessage
	applymovement 1, LittlerootTown_Movement_1E80DF
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_1E80EB
	waitmovement 0
	msgbox LittlerootTown_Text_1E8C07, MSGBOX_DEFAULT
	closemessage
	return
LittlerootTown_Text_1E8C07: @ 81E8C07
	.string "It's dangerous if you don't have\n"
	.string "your own Pokémon.$"
LittlerootTown_Movement_1E80DF: @ 81E80DF
	walk_down
	step_end
LittlerootTown_Movement_1E80EB: @ 81E80EB
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

LittlerootTown_EventScript_1E8091:: @ 81E8091
	lockall
	applymovement 1, LittlerootTown_Movement_1E80D1
	waitmovement 0
	call LittlerootTown_EventScript_1E80AD
	applymovement 1, LittlerootTown_Movement_1E80E1
	waitmovement 0
	releaseall
	end
LittlerootTown_Movement_1E80D1: @ 81E80D1
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_left
	face_down
	step_end
LittlerootTown_Movement_1E80E1: @ 81E80E1
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_fastest_down
	step_end


LittlerootTown_EventScript_1E80EF:: @ 81E80EF
	lockall
	applymovement 1, LittlerootTown_Movement_1E810B
	waitmovement 0
	call LittlerootTown_EventScript_1E80AD
	applymovement 1, LittlerootTown_Movement_1E8118
	waitmovement 0
	releaseall
	end
LittlerootTown_Movement_1E810B: @ 81E810B
	face_right
	delay_8
	disable_jump_landing_ground_effect
	jump_in_place_right
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	face_down
	step_end
LittlerootTown_Movement_1E8118: @ 81E8118
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end


@ -----------------------------------------------------
@ Parental Figure

LittlerootTown_TriggerScript_FinalIntro_LeavingTown::
	goto LittlerootTown_EventScript_FinalIntro_LeavingTown
	end
LittlerootTown_TriggerScript_FinalIntro_EnteringBrendans::
	@ Check if player is male
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_EventScript_FinalIntro_House
	release
	end
LittlerootTown_TriggerScript_FinalIntro_EnteringMays::
	@ Check if player is female
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_EventScript_FinalIntro_House
	release
	end

LittlerootTown_EventScript_FinalIntro_SetupMaleHouse:
	setvar VAR_0x8004, 5
	setvar VAR_0x8005, 8
	setobjectxyperm LID_DAD, 5, 8
	return
LittlerootTown_EventScript_FinalIntro_SetupFemaleHouse:
	setvar VAR_0x8004, 14
	setvar VAR_0x8005, 8
	setobjectxyperm LID_DAD, 14, 8
	return

LittlerootTown_EventScript_FinalIntro_House:
	lockall
	flagasdialog
	call_on_gender LittlerootTown_EventScript_FinalIntro_SetupMaleHouse, LittlerootTown_EventScript_FinalIntro_SetupFemaleHouse
	opendoor VAR_0x8004, VAR_0x8005
	waitdooranim
	addobject LID_DAD
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	msgbox LittlerootTown_Text_FinalIntro1b, MSGBOX_DEFAULT
	applymovement LID_DAD, LittlerootTown_Movement_FinalIntroA_Dad1
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_FinalIntroA_Player1
	waitmovement 0
	closedoor VAR_0x8004, VAR_0x8005
	waitdooranim
	delay 10
	call LittlerootTown_EventScript_FinalIntro_Main
	applymovement_gendered LID_DAD, LittlerootTown_Movement_FinalIntroA_Dad2_Boy, LittlerootTown_Movement_FinalIntroA_Dad2_Girl
	delay 30
	fadeinbgm 2
	waitmovement 0
	removeobject LID_DAD
	releaseall
	end
LittlerootTown_Movement_FinalIntroA_Dad1:
	delay_8
	walk_down
	face_left
	step_end
LittlerootTown_Movement_FinalIntroA_Player1:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end
LittlerootTown_Movement_FinalIntroA_Dad2_Boy:
	walk_right
	walk_right
	walk_right
	delay_16
	delay_16
	walk_in_place_left
	delay_16
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
LittlerootTown_Movement_FinalIntroA_Dad2_Girl:
	walk_down
	walk_left
	walk_left
	walk_left
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	

LittlerootTown_EventScript_FinalIntro_LeavingTown:
	lockall
	flagasdialog
	getplayerxy VAR_0x8004, VAR_0x8005
	addvar VAR_0x8005, 6
	setobjectxyperm LID_DAD, VAR_0x8004, VAR_0x8005
	addobject LID_DAD
	message LittlerootTown_Text_FinalIntro1a
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_FinalIntroB_Player1
	waitmovement 0
	waitbuttonpress
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_FinalIntroB_Player2
	applymovement LID_DAD, LittlerootTown_Movement_FinalIntroB_Dad1
	waitmovement 0
	call LittlerootTown_EventScript_FinalIntro_Main
	applymovement LID_DAD, LittlerootTown_Movement_FinalIntroB_Dad2
	delay 30
	fadeinbgm 2
	waitmovement 0
	removeobject LID_DAD
	releaseall
	end
LittlerootTown_Movement_FinalIntroB_Player1:
	face_down
	emote_exclamation_mark
	step_end
LittlerootTown_Movement_FinalIntroB_Dad1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end
LittlerootTown_Movement_FinalIntroB_Player2:
	delay_16
	delay_16
	delay_8
	walk_left
	face_right
	step_end
LittlerootTown_Movement_FinalIntroB_Dad2:
	walk_up
	walk_up
	delay_16
	delay_16
	walk_in_place_down
	delay_16
	delay_16
	delay_16
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_EventScript_FinalIntro_Main:
	message LittlerootTown_Text_FinalIntro2
	waitmessage
	fadeoutbgm 0
	message LittlerootTown_Text_FinalIntro3
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	setyesnotext gYN_YeahStutter, gYN_Elipsis1
	yesnobox 20, 8
	selectyesnoanswer LittlerootTown_Text_FinalIntro4_Yes, LittlerootTown_Text_FinalIntro4_No
	message 0x0
	waitmessage
	message LittlerootTown_Text_FinalIntro4
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_Movement_FinalIntroC_Player
	message LittlerootTown_Text_FinalIntro5
	waitmessage
	waitbuttonpress
	closemessage
	setflag FLAG_DAD_IS_AT_WORK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_DAD
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_DAD
	setvar VAR_0x4050, 4
	return
LittlerootTown_Movement_FinalIntroC_Player:
	delay_16
	delay_16
	delay_16
	delay_8
	face_right
	step_end
	

LittlerootTown_Text_FinalIntro1a:
	.string "Dad: There you are, {PLAYER}!$"
LittlerootTown_Text_FinalIntro1b:
	.string "Dad: Oh, {PLAYER}!$"
LittlerootTown_Text_FinalIntro2:
	.string "Dad: I wasn't sure I'd see you again\n"
	.string "before I had to leave!\p"
	.string "I'm heading to work now.\n"
	.string "I'm sure I'll be back late.\p"
	.string "I made some of my Dash of Figy Soup!\n"
	.string "I know it's your favorite.\l"
	.string "It's in the fridge if you get hungry.\p"
	.string "You look like you're going out.\n"
	.string "Where are you off to?\p"
	.string "$"
LittlerootTown_Text_FinalIntro3:
	.string "Oh…{PAUSE 60}\l"
	.string "You…{PAUSE 60} have Pokémon…{PAUSE 30}\n"
	.string "again… … …{PAUSE 30}\p"
	@ TODO: Different background music now, piano plunking?
	.string "… … … … … … … … … … … … … … …\p"
	.string "Um…{PAUSE 10}\p"
	.string "I…{PAUSE 10}\p"
	.string "I… hope you… {PAUSE 15}learned from the Alolan\n"
	.string "Challenge incident…{PAUSE 30} …{P_PLAYER}?{PAUSE 10}$"
LittlerootTown_Text_FinalIntro4_Yes:
	.string "Did you…? I hope so…\p"
	.string "$"
LittlerootTown_Text_FinalIntro4_No:
	.string "$"
LittlerootTown_Text_FinalIntro4:
	.string "Listen… {PLAYER_buddy}…\n"
	.string "I don't want to see you fail…\l"
	.string "despite what you might think…\p"
	.string "Please, be careful out there.\n"
	.string "Treat your Pokémon with respect.\p"
	.string "And, uh… {PAUSE 15}Feel free to come home\n"
	.string "if you need to rest.\p"
	.string "I'll keep your bed made and\n"
	.string "the fridge stocked for you.\p$"
LittlerootTown_Text_FinalIntro5:
	.string "{PLAYER}…{PAUSE 60} Don't…{PAUSE 30}\n"
	.string "get into trouble…{PAUSE 30} please…?{PAUSE 10}\p"
	.string "Good…{PAUSE 30} Good luck out there.$"
			


LittlerootTown_EventScript_1E81BB:: @ 81E81BB
	lockall
	setvar VAR_0x8008, 0
	setobjectxy LID_DAD, 10, 9
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81CE:: @ 81E81CE
	lockall
	setvar VAR_0x8008, 1
	setobjectxy LID_DAD, 11, 9
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81E1:: @ 81E81E1
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81ED:: @ 81E81ED
	lockall
	setvar VAR_0x8008, 3
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E81F9:: @ 81E81F9
	lockall
	setvar VAR_0x8008, 4
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E8205:: @ 81E8205
	lockall
	setvar VAR_0x8008, 5
	goto LittlerootTown_EventScript_1E8211
	end

LittlerootTown_EventScript_1E8211:: @ 81E8211
	call_on_gender LittlerootTown_EventScript_1E8297, LittlerootTown_EventScript_1E82A2
	call_on_gender LittlerootTown_EventScript_1E8281, LittlerootTown_EventScript_1E828C
	msgbox LittlerootTown_Text_1E87E1, MSGBOX_DEFAULT
	closemessage
	call_on_gender LittlerootTown_EventScript_1E82AD, LittlerootTown_EventScript_1E82F0
	call LittlerootTown_EventScript_1E8693
	call_on_gender LittlerootTown_EventScript_1E8405, LittlerootTown_EventScript_1E8448
	goto LittlerootTown_EventScript_1E8686
	end
LittlerootTown_Text_1E87E1: @ 81E87E1
	.string "MOM: Wait, {PLAYER}!$"

LittlerootTown_EventScript_1E8281:: @ 81E8281
	setvar VAR_0x8009, 5
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_1E828C:: @ 81E828C
	setvar VAR_0x8009, 14
	setvar VAR_0x800A, 8
	return

LittlerootTown_EventScript_1E8297:: @ 81E8297
	applymovement LID_DAD, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_EventScript_1E82A2:: @ 81E82A2
	applymovement LID_DAD, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_EventScript_1E82AD:: @ 81E82AD
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E8333
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8348
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E835D
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E8372
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E8387
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E839C
	return

LittlerootTown_EventScript_1E82F0:: @ 81E82F0
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E8333
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8348
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E83B1
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E83C6
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E83DB
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E83F0
	return

LittlerootTown_EventScript_1E8333:: @ 81E8333
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85D1
	waitmovement 0
	return

LittlerootTown_EventScript_1E8348:: @ 81E8348
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85D8
	waitmovement 0
	return

LittlerootTown_EventScript_1E835D:: @ 81E835D
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85DF
	waitmovement 0
	return

LittlerootTown_EventScript_1E8372:: @ 81E8372
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85E4
	waitmovement 0
	return

LittlerootTown_EventScript_1E8387:: @ 81E8387
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85EA
	waitmovement 0
	return

LittlerootTown_EventScript_1E839C:: @ 81E839C
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85ED
	waitmovement 0
	return

LittlerootTown_EventScript_1E83B1:: @ 81E83B1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85F1
	waitmovement 0
	return

LittlerootTown_EventScript_1E83C6:: @ 81E83C6
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85F5
	waitmovement 0
	return

LittlerootTown_EventScript_1E83DB:: @ 81E83DB
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85F8
	waitmovement 0
	return

LittlerootTown_EventScript_1E83F0:: @ 81E83F0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_DAD, LittlerootTown_Movement_1E85FE
	waitmovement 0
	return

LittlerootTown_EventScript_1E8405:: @ 81E8405
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E848B
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8496
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E84A1
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E84C7
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E84ED
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E8513
	return

LittlerootTown_EventScript_1E8448:: @ 81E8448
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_EventScript_1E848B
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_EventScript_1E8496
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_EventScript_1E8539
	compare VAR_0x8008, 3
	call_if_eq LittlerootTown_EventScript_1E855F
	compare VAR_0x8008, 4
	call_if_eq LittlerootTown_EventScript_1E8585
	compare VAR_0x8008, 5
	call_if_eq LittlerootTown_EventScript_1E85AB
	return

LittlerootTown_EventScript_1E848B:: @ 81E848B
	applymovement LID_DAD, LittlerootTown_Movement_1E8603
	waitmovement 0
	return

LittlerootTown_EventScript_1E8496:: @ 81E8496
	applymovement LID_DAD, LittlerootTown_Movement_1E8609
	waitmovement 0
	return

LittlerootTown_EventScript_1E84A1:: @ 81E84A1
	applymovement LID_DAD, LittlerootTown_Movement_1E860F
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E84C7:: @ 81E84C7
	applymovement LID_DAD, LittlerootTown_Movement_1E8615
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E84ED:: @ 81E84ED
	applymovement LID_DAD, LittlerootTown_Movement_1E861C
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E8513:: @ 81E8513
	applymovement LID_DAD, LittlerootTown_Movement_1E8620
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E8539:: @ 81E8539
	applymovement LID_DAD, LittlerootTown_Movement_1E8625
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E855F:: @ 81E855F
	applymovement LID_DAD, LittlerootTown_Movement_1E862A
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E8585:: @ 81E8585
	applymovement LID_DAD, LittlerootTown_Movement_1E862E
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_EventScript_1E85AB:: @ 81E85AB
	applymovement LID_DAD, LittlerootTown_Movement_1E8635
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	return

LittlerootTown_Movement_1E85D1: @ 81E85D1
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_1E85D8: @ 81E85D8
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_Movement_1E85DF: @ 81E85DF
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85E4: @ 81E85E4
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85EA: @ 81E85EA
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85ED: @ 81E85ED
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_Movement_1E85F1: @ 81E85F1
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E85F5: @ 81E85F5
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E85F8: @ 81E85F8
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E85FE: @ 81E85FE
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_Movement_1E8603: @ 81E8603
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_1E8609: @ 81E8609
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LittlerootTown_Movement_1E860F: @ 81E860F
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8615: @ 81E8615
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E861C: @ 81E861C
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8620: @ 81E8620
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8625: @ 81E8625
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E862A: @ 81E862A
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E862E: @ 81E862E
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E8635: @ 81E8635
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

LittlerootTown_Movement_1E863B: @ 81E863B
	walk_up
	step_end

LittlerootTown_EventScript_1E863D:: @ 81E863D
	lock
	faceplayer
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_EventScript_1E8281
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_EventScript_1E828C
	call LittlerootTown_EventScript_1E8693
	applymovement LID_DAD, Common_Movement_WalkInPlaceUp
	waitmovement 0
	opendoor VAR_0x8009, VAR_0x800A
	waitdooranim
	applymovement LID_DAD, LittlerootTown_Movement_1E863B
	waitmovement 0
	hideobjectat LID_DAD, MAP_LITTLEROOT_TOWN
	closedoor VAR_0x8009, VAR_0x800A
	waitdooranim
	goto LittlerootTown_EventScript_1E8686
	end

LittlerootTown_EventScript_1E8686:: @ 81E8686
	removeobject LID_DAD
	setflag FLAG_SYS_B_DASH
	setvar VAR_0x4050, 4
	release
	end

LittlerootTown_EventScript_1E8693:: @ 81E8693
	msgbox LittlerootTown_Text_1E87F0, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message LittlerootTown_Text_1E8925
	waitfanfare
	setflag FLAG_DAD_IS_AT_WORK
	msgbox LittlerootTown_Text_1E894F, MSGBOX_DEFAULT
	msgbox LittlerootTown_Text_1E8A03, MSGBOX_DEFAULT
	closemessage
	delay 30
	return





LittlerootTown_Text_1E87F0: @ 81E87F0
	.string "MOM: {PLAYER}! {PLAYER}! Did you\n"
	.string "introduce yourself to Prof. Birch?\p"
	.string "Oh! What an adorable Pokémon!\n"
	.string "You got it from Prof. Birch. How nice!\p"
	.string "You're your father's child, all right.\n"
	.string "You look good together with Pokémon!\p"
	.string "Here, honey! If you're going out on an\n"
	.string "adventure, wear these RUNNING SHOES.\p"
	.string "They'll put a zip in your step!$"

LittlerootTown_Text_1E8925: @ 81E8925
	.string "{PLAYER} switched shoes with the\n"
	.string "RUNNING SHOES.$"

LittlerootTown_Text_1E894F: @ 81E894F
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

LittlerootTown_Text_1E8A03: @ 81E8A03
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "To think that you have your very own\n"
	.string "Pokémon now…\l"
	.string "Your father will be overjoyed.\p"
	.string "…But please be careful.\n"
	.string "If anything happens, you can come home.\p"
	.string "Go on, go get them, honey!$"


#undef LID_DAD
