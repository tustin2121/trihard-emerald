PetalburgCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_MapScript2_FrameTable
	.byte 0

@ -----------------------------------------------------

PetalburgCity_OnTransition: @ 81DC2D7
	setflag FLAG_VISITED_PETALBURG_CITY
	compare VAR_PETALBURG_STATE, 0
	call_if_eq PetalburgCity_EventScript_1DC307
	@ compare VAR_PETALBURG_STATE, 2
	@ call_if_eq PetalburgCity_EventScript_1DC30F
	compare VAR_PETALBURG_STATE, 12
	call_if_eq PetalburgCity_EventScript_1DC316
	end

PetalburgCity_EventScript_1DC307:: @ 81DC307
	@ setobjectxyperm 8, 5, 11
	return

@ PetalburgCity_EventScript_1DC30F:: @ 81DC30F
@ 	setflag FLAG_HIDE_MAP_NAME_POPUP
@ 	savebgm MUS_TSURETEK
@ 	return

PetalburgCity_EventScript_1DC316:: @ 81DC316
	setvar VAR_PETALBURG_STATE, 11
	return

@ -----------------------------------------------------

PetalburgCity_OnLoad:
	call_if_unset FLAG_HIDE_PETALBURG_CITY_GYM_LOCK, PetalburgCity_OnLoad_BlockGym
	selectpointer_clamp PetalburgCity_OnLoad_ScriptTable_LoganFlagFix, VAR_LOGAN_STATE
	call 0
	end

PetalburgCity_OnLoad_BlockGym:
	setmetatile 15, 8, 0x200, TRUE
	return

.align 2
PetalburgCity_OnLoad_ScriptTable_LoganFlagFix:
	.4byte PetalburgCity_OnLoad_LoganFlagFix1
	.4byte PetalburgCity_OnLoad_LoganFlagFix2
	.4byte PetalburgCity_OnLoad_LoganFlagFix3
	.4byte 0

PetalburgCity_OnLoad_LoganFlagFix1:
	setflag FLAG_HIDE_PETALBURG_CENTER_LOGAN
	end
PetalburgCity_OnLoad_LoganFlagFix2:
	clearflag FLAG_HIDE_PETALBURG_CENTER_LOGAN
	end
PetalburgCity_OnLoad_LoganFlagFix3:
	setflag FLAG_HIDE_PETALBURG_CENTER_LOGAN
	end


@ -----------------------------------------------------

PetalburgCity_MapScript2_FrameTable: @ 81DC31C
	@ map_script_2 VAR_PETALBURG_STATE, 2, PetalburgCity_EventScript_1DC32E
	@ map_script_2 VAR_PETALBURG_STATE, 4, PetalburgCity_EventScript_1DC390
	.2byte 0

@ -----------------------------------------------------
@ Signs

PetalburgCity_EventScript_1DC47F:: @ 81DC47F
	msgbox PetalburgCity_Text_1DCAF1, MSGBOX_SIGN
	end
PetalburgCity_Text_1DCAF1: @ 81DCAF1
	.string "{PLACE}Petalburg City{END}\n"
	.string "“Where people mingle with nature.”$"


PetalburgCity_EventScript_1DC491:: @ 81DC491
	msgbox PetalburgCity_Text_1DCB23, MSGBOX_SIGN
	end
PetalburgCity_Text_1DCB23: @ 81DCB23
	.string "{PLACE}{RIVAL_HERO}'s House{END}$"


PetalburgCity_EventScript_GymSign:: @ 81DC476
	compare VAR_NUM_BADGES, 2
	goto_if_lt PetalburgCity_EventScript_GymSign2
	msgbox PetalburgCity_Text_GymSign, MSGBOX_SIGN
	end
PetalburgCity_Text_GymSign: @ 81DCAAA
	.string "{GYM}Petalburg City Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Norman\l"
	.string "“A man in pursuit of power!”$"
PetalburgCity_EventScript_GymSign2:: @ 81DC491
	msgbox PetalburgCity_Text_GymSign2, MSGBOX_SIGN
	end
PetalburgCity_Text_GymSign2:
	.string "{GYM}Petalburg City Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Malaqui\l"
	.string "“The dark cloak of mystery!”$"


PetalburgCity_EventScript_GymNotice:: @ 81DC491
	msgbox PetalburgCity_Text_Notice, MSGBOX_SIGN
	end
PetalburgCity_Text_Notice:
	.string "{CENTER}{GYM}Notice{END}\n"
	.string "{CENTER}This facility is closed until\n"
	.string "{CENTER}further notice due to police\n"
	.string "{CENTER}investigation. Please contact HPD\n"
	.string "{CENTER}with any information about potential\n"
	.string "{CENTER}misconduct or endangerment charges.$"


@ -----------------------------------------------------
@ People

PetalburgCity_EventScript_1DC3E6:: @ 81DC3E6
	lock
	faceplayer
	msgbox PetalburgCity_Text_1DC985, MSGBOX_DIALOG
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
PetalburgCity_Text_1DC985: @ 81DC985
	.string "My face is reflected in the water.\p"
	.string "It's a shining grin full of hope…\p"
	.string "Or it could be a look of somber silence\n"
	.string "struggling with fear…\p"
	.string "What do you see reflected in your face?$"


PetalburgCity_EventScript_Gentleman:: @ 81DC488
	msgbox PetalburgCity_Text_1DCA30, MSGBOX_NPC
	end
PetalburgCity_Text_1DCA30: @ 81DCA30
	.string "You should be careful which Pokémon\n"
	.string "you choose to catch.\p"
	.string "You can only carry six Pokémon.\p"
	.string "If only there was a way to store\n"
	.string "excess Pokémon, but there's not.$"


PetalburgCity_EventScript_LoganMom:: @ 81DC3FD
	msgbox PetalburgCity_Text_1DC837, MSGBOX_NPC
	end
PetalburgCity_Text_1DC837: @ 81DC837
	.string "Where has our precious {RIVAL_HERO} gone?\p"
	.string "We have to leave for Verdanturf Town\n"
	.string "very soon, and he's gonna be all by\l"
	.string "himself if we don't find him!$"


PetalburgCity_TriggerScript_LoganMom::
	lock
	markasdialog
	applymovement 1, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 1, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	selectpointer_from VAR_PETALBURG_STATE, PetalburgCity_Text_1DC838A, PetalburgCity_Text_1DC838B
	msgbox_selected
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkRight1
	applymovement 1, Common_Movement_FaceRight
	waitmovement 0
	release
	end
PetalburgCity_Text_1DC838A:
	.string "Have you seen our son?!\n"
	.string "We need to leave soon!\p"
	.string "Please help us find him!$"
PetalburgCity_Text_1DC838B:
	.string "Have you seen our son?!\p"
	.string "You have?! Where is he?!\p"
	.string "You don't know?! Well, he has to be\n"
	.string "around here somewhere!\p"
	.string "Please help us find him!$"


PetalburgCity_EventScript_LoganDad:: @ 81DC3FD
	msgbox PetalburgCity_Text_1DC839, MSGBOX_NPC
	end
PetalburgCity_Text_1DC839: @ 81DC837
	.string "{RIVAL_HERO}? {RIVAL_HERO}!{PAUSE 20}\n"
	.string "Oh, hello.\p"
	.string "We're searching for our son, {RIVAL_HERO}.\n"
	.string "If you see him come find us, please?$"

@ -----------------------------------------------------
@ Cutscene: Logan in the dirt

PetalburgCity_TriggerScript_FindLogan::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	fadenewbgm MUS_DUMMY
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement EVENT_OBJ_ID_CAMERA, PetalburgCity_Movement_FindLogan1
	waitmovement 0
	markasdialog 16
	msgbox PetalburgCity_Text_FindLogan2
	closemessage
	delay 40
	subvar VAR_INTERACT_Y, 16
	selectpointer_clamp PetalburgCity_MovementTable_FindLogan3, VAR_INTERACT_Y
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	delay 30
	setobjectxy EVENT_OBJ_ID_PLAYER, 20, 17
	setobjectxyperm 1, 20, 18
	setobjectxyperm 5, 20, 18
	addobject 1
	addobject 5
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Movement_FindLogan4a
	applymovement 1, PetalburgCity_Movement_FindLogan4b
	applymovement 5, PetalburgCity_Movement_FindLogan4c
	fadescreenspeed 1, 10
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_PETALBURG_STATE, 2
	setvar VAR_LOGAN_STATE, 1
	setflag FLAG_HIDE_PETALBURG_CITY_LOGAN_PARENTS
	setflag FLAG_HIDE_PETALBURG_CITY_LOGAN
	clearflag FLAG_HIDE_PETALBURG_CITY_GYM_LOCK
	clearflag FLAG_HIDE_PETALBURG_CENTER_LOGAN
	@ fadeinbgm 0
	warpcustom MAP_PETALBURG_CITY_POKEMON_CENTER_2F, 255, 14, 17
	waitstate
	releaseall
	end
PetalburgCity_Movement_FindLogan1:
	walk_right
	walk_right
	step_end
PetalburgCity_Text_FindLogan2:
	.string "I… … did it… … …\p"
	.string "I… caught a S-Seedot… … …\n"
	.string "all… by my… … myself… … …$"
.align 2
PetalburgCity_MovementTable_FindLogan3:
	.4byte PetalburgCity_Movement_FindLogan3b
	.4byte PetalburgCity_Movement_FindLogan3a
	.4byte 0
PetalburgCity_Movement_FindLogan3a:
	lock_facing_direction
	walk_left
	walk_left
	delay_16
	delay_16
	unlock_facing_direction
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
PetalburgCity_Movement_FindLogan3b:
	lock_facing_direction
	walk_left
	walk_left
	delay_16
	delay_16
	unlock_facing_direction
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
PetalburgCity_Movement_FindLogan4a:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	step_end
PetalburgCity_Movement_FindLogan4b:
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
PetalburgCity_Movement_FindLogan4c:
	delay_16
	delay_8
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

@ -----------------------------------------------------

@ PetalburgCity_EventScript_1DC49A:: @ 81DC49A
@ 	lockall
@ 	setvar VAR_0x8008, 0
@ 	goto PetalburgCity_EventScript_1DC4CA
@ 	end

@ PetalburgCity_EventScript_1DC4A6:: @ 81DC4A6
@ 	lockall
@ 	setvar VAR_0x8008, 1
@ 	goto PetalburgCity_EventScript_1DC4CA
@ 	end

@ PetalburgCity_EventScript_1DC4B2:: @ 81DC4B2
@ 	lockall
@ 	setvar VAR_0x8008, 2
@ 	goto PetalburgCity_EventScript_1DC4CA
@ 	end

@ PetalburgCity_EventScript_1DC4BE:: @ 81DC4BE
@ 	lockall
@ 	setvar VAR_0x8008, 3
@ 	goto PetalburgCity_EventScript_1DC4CA
@ 	end

@ PetalburgCity_EventScript_1DC4CA:: @ 81DC4CA
@ 	applymovement 8, Common_Movement_FacePlayer
@ 	waitmovement 0
@ 	playbgm MUS_TSURETEK, 0
@ 	playse SE_PIN
@ 	applymovement 8, Common_Movement_ExclamationMark
@ 	waitmovement 0
@ 	applymovement 8, Common_Movement_Delay48
@ 	waitmovement 0
@ 	@ Movement
@ 	selectpointer PetalburgCity_MovementTable_1DC57F_Boy, VAR_0x8008
@ 	applymovement 8, 0
@ 	waitmovement 0
@ 	selectpointer PetalburgCity_MovementTable_1DC57F_Player, VAR_0x8008
@ 	applymovement EVENT_OBJ_ID_PLAYER, 0
@ 	waitmovement 0
	
@ 	msgbox PetalburgCity_Text_1DC881, MSGBOX_DEFAULT
@ 	closemessage
	
@ 	selectpointer PetalburgCity_MovementTable_1DC5C9_Boy, VAR_0x8008
@ 	applymovement 8, 0
@ 	selectpointer PetalburgCity_MovementTable_1DC5C9_Player, VAR_0x8008
@ 	applymovement EVENT_OBJ_ID_PLAYER, 0
@ 	waitmovement 0
	
@ 	msgbox PetalburgCity_Text_1DC91B, MSGBOX_DEFAULT
@ 	applymovement 8, Common_Movement_WalkInPlaceRight
@ 	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
@ 	waitmovement 0
@ 	msgbox PetalburgCity_Text_1DC93E, MSGBOX_DEFAULT
@ 	closemessage
@ 	applymovement 8, PetalburgCity_Movement_1DC658
@ 	waitmovement 0
@ 	fadedefaultbgm
@ 	releaseall
@ 	end
PetalburgCity_EventScript_1DC82E:: @ 81DC82E
	msgbox PetalburgCity_Text_1DC881, MSGBOX_NPC
	end
PetalburgCity_Text_1DC881: @ 81DC881
	.string "Hiya! Are you maybe…\n"
	.string "A rookie trainer?\p"
	.string "Do you know what Pokémon Trainers\n"
	.string "do when they reach a new town?\p"
	.string "They first check what kind of Gym\n"
	.string "is in the town.$"
@ PetalburgCity_Text_1DC91B: @ 81DC91B
@ 	.string "See? This is Petalburg City's Gym.$"
@ PetalburgCity_Text_1DC93E: @ 81DC93E
@ 	.string "This is the Gym's sign. Look for it\n"
@ 	.string "whenever you're looking for a Gym.$"

@ .align 2
@ PetalburgCity_MovementTable_1DC57F_Boy:
@ 	.4byte PetalburgCity_Movement_1DC615
@ 	.4byte PetalburgCity_Movement_1DC61A
@ 	.4byte PetalburgCity_Movement_1DC61D
@ 	.4byte PetalburgCity_Movement_1DC622
@ 	.4byte 0
@ PetalburgCity_MovementTable_1DC57F_Player:
@ 	.4byte Common_Movement_WalkInPlaceDown
@ 	.4byte Common_Movement_NoOp
@ 	.4byte Common_Movement_WalkInPlaceUp
@ 	.4byte Common_Movement_WalkInPlaceUp
@ 	.4byte 0
@ .align 2
@ PetalburgCity_MovementTable_1DC5C9_Boy:
@ 	.4byte PetalburgCity_Movement_1DC628
@ 	.4byte PetalburgCity_Movement_1DC633
@ 	.4byte PetalburgCity_Movement_1DC641
@ 	.4byte PetalburgCity_Movement_1DC64C
@ 	.4byte 0
@ PetalburgCity_MovementTable_1DC5C9_Player:
@ 	.4byte PetalburgCity_Movement_1DC665
@ 	.4byte PetalburgCity_Movement_1DC66F
@ 	.4byte PetalburgCity_Movement_1DC67C
@ 	.4byte PetalburgCity_Movement_1DC686
@ 	.4byte 0

@ PetalburgCity_Movement_1DC611:: @ 81DC611
@ 	delay_16
@ 	delay_16
@ 	delay_16
@ 	step_end

@ PetalburgCity_Movement_1DC615: @ 81DC615
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ PetalburgCity_Movement_1DC61A: @ 81DC61A
@ 	walk_right
@ 	walk_right
@ 	step_end

@ PetalburgCity_Movement_1DC61D: @ 81DC61D
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_in_place_fastest_down
@ 	step_end

@ PetalburgCity_Movement_1DC622: @ 81DC622
@ 	walk_down
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_in_place_fastest_down
@ 	step_end

@ PetalburgCity_Movement_1DC628: @ 81DC628
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ PetalburgCity_Movement_1DC633: @ 81DC633
@ 	walk_down
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_up
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ PetalburgCity_Movement_1DC641: @ 81DC641
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ PetalburgCity_Movement_1DC64C: @ 81DC64C
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_up
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ PetalburgCity_Movement_1DC658: @ 81DC658
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
@ 	walk_left
@ 	walk_left
@ 	step_end

@ PetalburgCity_Movement_1DC665: @ 81DC665
@ 	walk_down
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	step_end

@ PetalburgCity_Movement_1DC66F: @ 81DC66F
@ 	delay_16
@ 	delay_16
@ 	walk_down
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_up
@ 	step_end

@ PetalburgCity_Movement_1DC67C: @ 81DC67C
@ 	walk_up
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	step_end

@ PetalburgCity_Movement_1DC686: @ 81DC686
@ 	walk_up
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_up
@ 	step_end



PetalburgCity_EventScript_1DC691:: @ 81DC691
	lockall
	addobject 9
	setvar VAR_0x8008, 0
	setobjectxy 9, 13, 10
	goto PetalburgCity_EventScript_1DC6E9
	end
PetalburgCity_EventScript_1DC6A7:: @ 81DC6A7
	lockall
	addobject 9
	setvar VAR_0x8008, 1
	setobjectxy 9, 13, 11
	goto PetalburgCity_EventScript_1DC6E9
	end
PetalburgCity_EventScript_1DC6BD:: @ 81DC6BD
	lockall
	addobject 9
	setvar VAR_0x8008, 2
	setobjectxy 9, 13, 12
	goto PetalburgCity_EventScript_1DC6E9
	end
PetalburgCity_EventScript_1DC6D3:: @ 81DC6D3
	lockall
	addobject 9
	setvar VAR_0x8008, 3
	setobjectxy 9, 13, 13
	goto PetalburgCity_EventScript_1DC6E9
	end
PetalburgCity_EventScript_1DC6E9:: @ 81DC6E9
	applymovement 9, PetalburgCity_Movement_1DC7D6
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, PetalburgCity_Movement_1DC7DB
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	setvar VAR_SCOTT_STATE, 1
	msgbox PetalburgCity_Text_1DCB31, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_1DCB82, MSGBOX_DEFAULT
	closemessage
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 30
	msgbox PetalburgCity_Text_1DCC09, MSGBOX_DEFAULT
	closemessage
	selectpointer PetalburgCity_MovementTable_1DC7EE_Player, VAR_0x8008
	applymovement EVENT_OBJ_ID_PLAYER, 0
	selectpointer PetalburgCity_MovementTable_1DC7EE_Scott, VAR_0x8008
	applymovement 9, 0
	waitmovement 0
	setvar VAR_SCOTT_PETALBURG_ENCOUNTER, 1
	removeobject 9
	releaseall
	end
PetalburgCity_Text_1DCB31: @ 81DCB31
	.string "Excuse me!\p"
	.string "Let me guess, from the way you're\n"
	.string "dressed, are you a Pokémon trainer?$"
PetalburgCity_Text_1DCB82: @ 81DCB82
	.string "… … … … … …\p"
	.string "Well, maybe not.\n"
	.string "Your clothes aren't all that dirty.\p"
	.string "You're either a rookie trainer,\n"
	.string "or maybe you're just an ordinary kid.$"
PetalburgCity_Text_1DCC09: @ 81DCC09
	.string "I'm roaming the land in search of\n"
	.string "talented trainerS.\p"
	.string "I'm sorry to have taken your time.$"

.align 2
PetalburgCity_MovementTable_1DC7EE_Player:
	.4byte PetalburgCity_Movement_1DC7EE
	.4byte PetalburgCity_Movement_1DC802
	.4byte PetalburgCity_Movement_1DC815
	.4byte PetalburgCity_Movement_1DC828
	.4byte 0
PetalburgCity_MovementTable_1DC7EE_Scott:
	.4byte PetalburgCity_Movement_1DC7E0
	.4byte PetalburgCity_Movement_1DC7F5
	.4byte PetalburgCity_Movement_1DC808
	.4byte PetalburgCity_Movement_1DC81B
	.4byte 0

PetalburgCity_Movement_1DC7D6: @ 81DC7D6
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_1DC7DB: @ 81DC7DB
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_1DC7E0: @ 81DC7E0
	walk_down
	walk_down
	walk_left
	walk_left
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

PetalburgCity_Movement_1DC7EE: @ 81DC7EE
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_1DC7F5: @ 81DC7F5
	walk_down
	walk_left
	walk_left
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

PetalburgCity_Movement_1DC802: @ 81DC802
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_1DC808: @ 81DC808
	walk_down
	walk_left
	walk_left
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

PetalburgCity_Movement_1DC815: @ 81DC815
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

PetalburgCity_Movement_1DC81B: @ 81DC81B
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
	walk_left
	walk_left
	step_end

PetalburgCity_Movement_1DC828: @ 81DC828
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end






















