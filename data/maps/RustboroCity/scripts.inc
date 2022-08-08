RustboroCity_MapScripts:: @ 81E06BD
	map_script MAP_SCRIPT_ON_RESUME, RustboroCity_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_MapScript2_FrameTable
	.byte 0

@ -----------------------------------------------------

RustboroCity_OnTransition: @ 81E06C8
	setflag FLAG_VISITED_RUSTBORO_CITY
	call Common_EventScript_SetupRivalGender
	compare VAR_RUSTBORO_STATE, 2
	call_if_eq RustboroCity_EventScript_SetupAqua2
	compare VAR_RUSTBORO_STATE, 3
	call_if_eq RustboroCity_EventScript_SetupAqua3
	compare VAR_RUSTBORO_STATE, 4
	call_if_eq RustboroCity_EventScript_SetupAqua4
	@ compare VAR_RUSTBORO_STATE, 6
	@ call_if_eq Common_EventScript_HideMapNamePopup
	@ getplayerxy VAR_TEMP_0, VAR_TEMP_1
	@ compare VAR_RUSTBORO_STATE, 6
	@ goto_if_eq RustboroCity_EventScript_1E06EC
	end

@ -----------------------------------------------------

RustboroCity_OnResume:
	call_if_unset FLAG_HIDE_RUSTBORO_CITY_DEVON_SCENE, RustboroCity_EventScript_SetupDevonScene
	end

RustboroCity_EventScript_SetupDevonScene:
	createvobject EVENT_OBJ_GFX_SCIENTIST_1,    50, 11, 21, 3, DIR_NORTH
	createvobject EVENT_OBJ_GFX_DEVON_EMPLOYEE, 51, 10, 21, 3, DIR_NORTH
	createvobject EVENT_OBJ_GFX_WOMAN_3,        52, 15, 16, 3, DIR_WEST
	createvobject EVENT_OBJ_GFX_SCIENTIST_2,    53,  9, 22, 3, DIR_NORTH
	createvobject EVENT_OBJ_GFX_POLICEMAN,      54, 14, 16, 3, DIR_EAST
	createvobject EVENT_OBJ_GFX_POLICEMAN,      55,  9, 17, 3, DIR_EAST
	createvobject EVENT_OBJ_GFX_SCIENTIST_1,    56, 10, 19, 3, DIR_EAST
	createvobject EVENT_OBJ_GFX_SCIENTIST_1,    57,  8, 16, 3, DIR_EAST
	return

@ RustboroCity_EventScript_1E06EC:: @ 81E06EC
@ 	compare VAR_TEMP_0, 11
@ 	goto_if_eq RustboroCity_EventScript_1E06FF
@ 	setobjectxyperm 15, 12, 15
@ 	end

@ RustboroCity_EventScript_1E06FF:: @ 81E06FF
@ 	setobjectxyperm 15, 11, 15
@ 	end

@ -----------------------------------------------------

RustboroCity_MapScript2_FrameTable: @ 81E070B
	@ map_script_2 VAR_RUSTBORO_STATE, 6, RustboroCity_EventScript_1E0715
	.2byte 0

@ -----------------------------------------------------
@ Sign

RustboroCity_EventScript_1E08E3:: @ 81E08E3
	lock
	message RustboroCity_Text_1E20A6, MSGTYPE_SIGN
	waitmessage
	waitbuttonpress
	message RustboroCity_Text_1E20A7, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	release
	end
RustboroCity_Text_1E20A6: @ 81E20A6
	.string "“Timesaving tunnel nearing\n"
	.string "completion!”$"
RustboroCity_Text_1E20A7:
	.string "…Is what it says on the sign, but\n"
	.string "there's also a big “X” splashed\l"
	.string "across it in red paint…$"


RustboroCity_EventScript_1E08EC:: @ 81E08EC
	msgbox RustboroCity_Text_1E2128, MSGBOX_SIGN
	end
RustboroCity_Text_1E2128: @ 81E2128
	.string "{PLACE}DEVON CORPORATION{END}\p"
	.string "“For all your living needs, we make\n"
	.string "it all.”$"


RustboroCity_EventScript_1E08F5:: @ 81E08F5
	msgbox RustboroCity_Text_1E2167, MSGBOX_SIGN
	end
RustboroCity_Text_1E2167: @ 81E2167
	.string "{GYM}Rustboro City Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Roxanne\p"
	.string "“The Rock-loving honors student!”$"


RustboroCity_EventScript_1E08FE:: @ 81E08FE
	msgbox RustboroCity_Text_1E21B3, MSGBOX_SIGN
	end
RustboroCity_Text_1E21B3: @ 81E21B3
	.string "{PLACE}Devon Corp. Branch Office{END}\p"
	.string "“Access limited to Devon employees\n"
	.string "and authorized personnel.”$"


RustboroCity_EventScript_1E0907:: @ 81E0907
	msgbox RustboroCity_Text_1E220B, MSGBOX_SIGN
	end
RustboroCity_Text_1E220B: @ 81E220B
	.string "{PLACE}Rustboro City{END}\p"
	.string "“The city probing the integration of\n"
	.string "nature and science.”$"


RustboroCity_EventScript_1E0910:: @ 81E0910
	msgbox RustboroCity_Text_1E2253, MSGBOX_SIGN
	end
RustboroCity_Text_1E2253: @ 81E2253
	.string "{PLACE}Pokémon Trainer's School{END}\p"
	.string "“We'll teach you anything about\n"
	.string "Pokémon!”$"


RustboroCity_EventScript_1E0919:: @ 81E0919
	msgbox RustboroCity_Text_1E2296, MSGBOX_SIGN
	end
RustboroCity_Text_1E2296: @ 81E2296
	.string "{PLACE}Lumberjack's House{END}$"


@ -----------------------------------------------------
@ People

RustboroCity_EventScript_1E085F:: @ 81E085F
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_EventScript_1E0874
	msgbox RustboroCity_Text_1E123F, MSGBOX_DEFAULT
	release
	end
RustboroCity_Text_1E123F: @ 81E123F
	.string "The Devon Corporation…\n"
	.string "We all just shorten it to Devon.\p"
	.string "That company makes all sorts of\n"
	.string "convenient products.\p"
	.string "… … … No, it's not evil,\n"
	.string "what are you on about?$"
RustboroCity_EventScript_1E0874:: @ 81E0874
	msgbox RustboroCity_Text_1E12AC, MSGBOX_DEFAULT
	release
	end
RustboroCity_Text_1E12AC: @ 81E12AC
	.string "Hm? A sneaky-looking man?\p"
	.string "Come to think of it, yes, a shady-\n"
	.string "looking guy went around the corner.$"



RustboroCity_EventScript_DevonEmployee:: @ 81E087E
	lock
	faceplayer
	markasdialog
	checkplayeroutfit
	selectpointer RustboroCity_TextArray_DevonEmployee, VAR_RESULT
	msgbox_selected MSGBOX_DEFAULT
	release
	end
.align 2
RustboroCity_TextArray_DevonEmployee:
	.4byte RustboroCity_Text_1E1407
	.4byte RustboroCity_Text_1E1408
	.4byte RustboroCity_Text_1E1408
	.4byte RustboroCity_Text_1E1409
	.4byte 0
RustboroCity_Text_1E1407: @ 81E1407
	.string "Oh, no. Who are you now?\p"
	.string "We already have two gangs in town,\n"
	.string "we don't need another.$"
RustboroCity_Text_1E1408:
	.string "Augh! Team Aqua! Don't hurt me!\n"
	.string "I don't know anything!\l"
	.string "Please go away!$"
RustboroCity_Text_1E1409:
	.string "Oh? Who might you be?\p"
	.string "Are you a new student at the\n"
	.string "Pokémon… Trainer's School?$"



RustboroCity_EventScript_FireGirl:: @ 81E088A
	msgbox RustboroCity_Text_1E1480, MSGBOX_NPC
	end
RustboroCity_Text_1E1480: @ 81E1480
	.string "I challenged the Gym Leader, but…\p"
	.string "It's not going to be easy winning with\n"
	.string "my Fire-type Pokémon…\p"
	.string "Fire-type Pokémon don't match up\n"
	.string "well against Rock-type Pokémon…$"



RustboroCity_EventScript_GymBadgeGuy:: @ 81E0893
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_BADGE01_GET, RustboroCity_EventScript_1E08A8
	msgbox RustboroCity_Text_1E130D, MSGBOX_DEFAULT
	release
	end
RustboroCity_Text_1E130D: @ 81E130D
	.string "Have you taken the Pokémon Gym\n"
	.string "challenge?\p"
	.string "When you get that shiny Gym Badge\n"
	.string "in hand, I guess trainers begin to\l"
	.string "realize what is required of them.$"
RustboroCity_EventScript_1E08A8:: @ 81E08A8
	msgbox RustboroCity_Text_1E139E, MSGBOX_DEFAULT
	release
	end
RustboroCity_Text_1E139E: @ 81E139E
	.string "Hey, that's Rustboro's Gym Badge!\p"
	.string "Out of all the Pokémon Gym Badges,\n"
	.string "Rustboro's is the coolest, I'd say.$"



RustboroCity_EventScript_BrineyBoy:: @ 81E08B2
	msgbox RustboroCity_Text_1E1520, MSGBOX_NPC
	end
RustboroCity_Text_1E1520: @ 81E1520
	.string "The old sailor Mr. Briney lives in\n"
	.string "a cottage by the sea.\p"
	.string "He likes to sail around with his pet,\n"
	.string "Peeko, and go fishing all around Hoenn.$"



RustboroCity_EventScript_AspiringTrainerGirl:: @ 81E08D1
	msgbox RustboroCity_Text_1E1633, MSGBOX_NPC
	end
RustboroCity_Text_1E1633: @ 81E1633
	.string "Wow, you have Pokémon with you, too.\p"
	.string "When I get bigger, I'm going to go\n"
	.string "places with Pokémon, too.$"



RustboroCity_EventScript_AspiringSchoolBoy:: @ 81E08DA
	msgbox RustboroCity_Text_1E1695, MSGBOX_DIALOG
	end
RustboroCity_Text_1E1695: @ 81E1695
	.string "Pokémon TRAINER'S SCHOOL!\p"
	.string "If I go to this school, will I be able\n"
	.string "to catch rare Pokémon easily?$"



RustboroCity_EventScript_LittleBoy:: @ 81E0922
	lock
	faceplayer
	msgbox RustboroCity_Text_1E16F4, MSGBOX_DIALOG
	faceoriginaldir
	release
	end
RustboroCity_Text_1E16F4: @ 81E16F4
	.string "If a Pokémon gains experience in\n"
	.string "battles, it can sometimes change in\l"
	.string "the way it looks.$"



RustboroCity_EventScript_LittleGirl:: @ 81E0938
	lock
	faceplayer
	msgbox RustboroCity_Text_1E174B, MSGBOX_DIALOG
	faceoriginaldir
	release
	end
RustboroCity_Text_1E174B: @ 81E174B
	.string "A Pokémon changes shape?\n"
	.string "If one did that, I would be shocked!$"



RustboroCity_EventScript_TradeGuy:: @ 81E094E
	msgbox RustboroCity_Text_1E1789, MSGBOX_NPC
	end
RustboroCity_Text_1E1789: @ 81E1789
	.string "A Pokémon you get in a trade from\n"
	.string "someone grows fast.\p"
	.string "But if you don't have certain Gym\n"
	.string "Badges, it may not obey you…$"



RustboroCity_EventScript_TriviaBoy:: @ 81E1236
	msgbox RustboroCity_Text_1E249D, MSGBOX_NPC
	end
RustboroCity_Text_1E249D: @ 81E249D
	.string "Did you know this?\p"
	.string "You can have a 2-on-2 battle even\n"
	.string "if you're not with another Trainer.\p"
	.string "If you catch the eyes of two Trainers\n"
	.string "when you have two or more Pokémon,\l"
	.string "they'll both challenge you.\p"
	.string "Don't you think it'd be cool if you\n"
	.string "could beat two Trainers by yourself?$"



RustboroCity_EventScript_AquaBoy::
	goto_if_set FLAG_SCENE_0, RustboroCity_EventScript_AquaBoyB
	msgbox RustboroCity_Text_AquaBoy, MSGBOX_NPC
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	setflag FLAG_SCENE_0
	end
RustboroCity_Text_AquaBoy:
	.string "Those are another gang's colors\n"
	.string "you're wearing, isn't it?\p"
	.string "If you're already part of a gang,\n"
	.string "why are you itching to join us?\p"
	.string "Did you get lost? Kicked out?\p"
	.string "Pulled away without a choice?\n"
	.string "Oh, I hit a nerve. My bad.$"
RustboroCity_EventScript_AquaBoyB:
	msgbox RustboroCity_Text_AquaBoyB, MSGBOX_NPC
	end
RustboroCity_Text_AquaBoyB:
	.string "Can't let you into the family unless\n"
	.string "you prove yourself first.\p"
	.string "I know you know how this goes.$"


RustboroCity_EventScript_AquaGirl::
	goto_if_set FLAG_SCENE_1, RustboroCity_EventScript_AquaGirlB
	selectpointer_ongender RustboroCity_Text_AquaGirl_Boy, RustboroCity_Text_AquaGirl_Girl
	msgbox_selected MSGBOX_NPC
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	setflag FLAG_SCENE_1
	end
RustboroCity_Text_AquaGirl_Boy:
	.string "Gotta say, boy. Usually when some guy,\n"
	.string "sneaks up behind me, it ain't to ask\l"
	.string "to join my gang.\p"
	.string "You caught me off guard there.\n"
	.string "Do it again, and I deck ya one.$"
RustboroCity_Text_AquaGirl_Girl:
	.string "Gotta say, girl. I was ready to turn\n"
	.string "around and deck a guy wanting to get\l"
	.string "handsey with me.\p"
	.string "Yeah, you know what I mean. That\n"
	.string "face you're making is mood.$"
RustboroCity_EventScript_AquaGirlB:
	msgbox RustboroCity_Text_AquaGirlB, MSGBOX_NPC
	end
RustboroCity_Text_AquaGirlB:
	.string "If ya stand around gabbing, you're\n"
	.string "never gonna get the {ITEM}Goods{END}, are ya?$"


RustboroCity_EventScript_AquaThree::
	msgbox RustboroCity_Text_AquaThree, MSGBOX_NPC
	end
RustboroCity_Text_AquaThree:
	.string "Did you get the {ITEM}Devon Goods{END}\n"
	.string "back from that Magma Bloke yet?\p"
	.string "He ran off into the Rusturf Tunnel.$"


@ -----------------------------------------------------
@ Cutscene: The Heist

#define LID_MAGMA 10
#define LID_AQUA_GIRL 15
#define LID_AQUA_BOY 17
#define LID_AQUA_3 18

RustboroCity_TriggerScript_HeistCutscene1::
	lockall
	setobjectmovementtype LID_MAGMA, MOVEMENT_TYPE_FACE_RIGHT
	setobjectxyperm LID_MAGMA, 14, 21
	setobjectxyperm LID_AQUA_BOY, 13, 21
	setobjectxyperm LID_AQUA_GIRL, 12, 21
	setobjectxyperm LID_AQUA_3, 13, 22
	addobject LID_MAGMA
	addobject LID_AQUA_BOY
	addobject LID_AQUA_GIRL
	addobject LID_AQUA_3
	@ Yelling ensues
	markasdialog -26
	msgbox RustboroCity_Text_Heist1, MSGBOX_CDIALOG
	playbgm MUS_MGM0, 0
	markasdialog -26
	msgbox RustboroCity_Text_Heist2, MSGBOX_CDIALOG
	closemessage
	@ They rush past
	applymovement LID_MAGMA, RustboroCity_Movement_Heist3_Magma
	waitmovement 0
	applymovement LID_AQUA_BOY, RustboroCity_Movement_Heist3_AquaA
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_Heist3_AquaB
	applymovement LID_AQUA_3, RustboroCity_Movement_Heist3_AquaC
	delay 40
	setfieldeffectargument 0, 22
	setfieldeffectargument 1, 22
	setfieldeffectargument 2, 4
	setfieldeffectargument 3, 2
	dofieldeffect FLDEFF_DUST
	waitfieldeffect 0
	waitmovement 0
	@ Scene end, clean up:
	fadedefaultbgm
	removeobject LID_MAGMA
	removeobject LID_AQUA_BOY
	removeobject LID_AQUA_GIRL
	removeobject LID_AQUA_3
	call RustboroCity_EventScript_SetupAqua2
	@ Reset magma grunt actor to separate person
	setobjectmovementtype LID_MAGMA, MOVEMENT_TYPE_LYING_DOWN
	setobjectxyperm LID_MAGMA, 13, 18
	@ clearflag FLAG_UNUSED_0x2DB
	clearflag FLAG_HIDE_RUSTBORO_CITY_AQUA_MEMBERS
	clearflag FLAG_HIDE_RUSTBORO_CITY_DEVON_SCENE
	call RustboroCity_EventScript_SetupDevonScene
	setflag FLAG_DEVON_GOODS_STOLEN
	setvar VAR_RUSTBORO_STATE, 2
	setvar VAR_RUSTURF_TUNNEL_STATE, 2
	setvar VAR_ROUTE116_STATE, 1
	clearflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_PEEKO
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_AQUA_GRUNT
	setflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	setflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	releaseall
	end


RustboroCity_Text_Heist1: @ 81E17FE
	.string "Out of the way! Move it!!$"
RustboroCity_Text_Heist2:
	.string "After him!! He's getting away!$"
RustboroCity_Movement_Heist3_Magma: @ 81E0A8E
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
RustboroCity_Movement_Heist3_AquaA:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
RustboroCity_Movement_Heist3_AquaB:
	delay_8
	walk_fastest_right
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
RustboroCity_Movement_Heist3_AquaC:
	delay_16
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_up
	lock_facing_direction
	walk_right
	walk_slow_right
	unlock_facing_direction
	face_left
	delay_8
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ -----------------------------------------------------
@ Cutscene: Aqua's Task

RustboroCity_EventScript_SetupAqua2:
	setobjectxyperm LID_AQUA_BOY, 30, 11
	setobjectxyperm LID_AQUA_GIRL, 29, 10
	setobjectxyperm LID_AQUA_3, 34, 8
	return

RustboroCity_TriggerScript_AquasTask1::
	lockall
	getplayerxy VAR_TEMP_E, VAR_TEMP_F
	subvar VAR_TEMP_F, 8
	delay 8
	special SpawnCameraObject
	addobject LID_AQUA_3
	delay 2
	selectpointer RustboroCity_MovementTable_AquasTask1_CamMovement1, VAR_TEMP_F
	applymovement EVENT_OBJ_ID_CAMERA, 0
	applymovement LID_AQUA_3, RustboroCity_Movement_AquasTask1_AquaGuy
	waitmovement LID_AQUA_3
	delay 2
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceUp
	applymovement LID_AQUA_3, Common_Movement_WalkInPlaceDown
	waitmovement 0
	waitmovement EVENT_OBJ_ID_CAMERA
	@ "He went into the tunnel."
	markasdialog -6
	msgbox RustboroCity_Text_AquasTask2
	playse SE_SELECT
	@ "Ugh, really?"
	markasdialog -12
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquasTask_BoyGlanceRight
	msgbox RustboroCity_Text_AquasTask3
	playse SE_SELECT
	waitmovement 0
	@ "my team's beat"
	selectpointer RustboroCity_MovementTable_AquasTask4_PlayerCreep1, VAR_TEMP_F
	applymovement EVENT_OBJ_ID_PLAYER, 0
	markasdialog 8
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquasTask_GirlGlanceDown
	msgbox RustboroCity_Text_AquasTask4
	playse SE_SELECT
	waitmovement 0
	@ "mine too"
	markasdialog -6
	applymovement LID_AQUA_3, RustboroCity_Movement_AquasTask_3GlanceRight
	msgbox RustboroCity_Text_AquasTask5
	playse SE_SELECT
	waitmovement 0
	waitmovement EVENT_OBJ_ID_PLAYER
	@ "Any suggestions"
	selectpointer RustboroCity_MovementTable_AquasTask4_PlayerCreep2, VAR_TEMP_F
	applymovement EVENT_OBJ_ID_PLAYER, 0
	markasdialog -12
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquasTask_BoyGlanceRight
	msgbox RustboroCity_Text_AquasTask6
	playse SE_SELECT
	waitmovement 0
	closemessage
	@ Player sneaks up
	waitmovement EVENT_OBJ_ID_PLAYER
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_AquasTask_PlayerCreepForward
	waitmovement 0
	delay 40
	@
	applymovement LID_AQUA_GIRL, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LID_AQUA_GIRL, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	playbgm MUS_AQA_0, 0
	@ "Oh, hello"
	markasdialog -6
	applymovement LID_AQUA_3, RustboroCity_Movement_AquasTask7_Aqua3
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquasTask7_AquaGuy
	applymovement EVENT_OBJ_ID_CAMERA, RustboroCity_Movement_AquasTask7_Camera
	msgbox RustboroCity_Text_AquasTask7
	playse SE_SELECT
	waitmovement LID_AQUA_BOY
	closemessage
	waitmovement EVENT_OBJ_ID_CAMERA
	@
	special RemoveCameraObject
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_AquasTask8_PlayerTalk
	waitmovement 0
	@ "You wanna join?"
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquasTask8_AquaGirlBackup
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceRight
	applymovement LID_AQUA_3, Common_Movement_WalkInPlaceRight
	msgbox RustboroCity_Text_AquasTask9
	playse SE_SELECT
	waitmovement 0
	closemessage
	delay 40
	@ Conference
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquasTask9_AquaGirl
	applymovement LID_AQUA_3, RustboroCity_Movement_AquasTask9_Aqua3
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquasTask9_AquaBoy
	waitmovement LID_AQUA_BOY
	delay 8
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquasTask10_AquaGirl
	applymovement LID_AQUA_3, RustboroCity_Movement_AquasTask10_Aqua3
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquasTask10_AquaBoy
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_AquasTask10_Player
	waitmovement LID_AQUA_BOY
	delay 16
	@ "Alright"
	markasdialog 14
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_AquasTask11_Player
	msgbox RustboroCity_Text_AquasTask11
	closemessage
	waitmovement 0
	@ Brush past
	fadedefaultbgm
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_AquasTask12_Player
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquasTask12_AquaGirl
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquasTask12_AquaBoy
	applymovement LID_AQUA_3, RustboroCity_Movement_AquasTask12_Aqua3
	waitmovement 0
	waitmovement EVENT_OBJ_ID_PLAYER
	@ Clean up
	setvar VAR_RUSTBORO_STATE, 3
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_SCENE
	setobjectmovementtype LID_AQUA_BOY, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LID_AQUA_GIRL, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LID_AQUA_3, MOVEMENT_TYPE_LOOK_AROUND
	releaseall
	end

RustboroCity_Text_AquasTask2:
	.string "He went into the tunnel.$"
RustboroCity_Text_AquasTask3:
	.string "Ugh, really? Anyone want to follow him?$"
RustboroCity_Text_AquasTask4:
	.string "I dunno about you, but my Pokémon\n"
	.string "are beat.$"
RustboroCity_Text_AquasTask5:
	.string "Yeah, that heist was rough on\n"
	.string "my Pokémon too.$"
RustboroCity_Text_AquasTask6:
	.string "Welp… Any suggestions?$"
RustboroCity_Text_AquasTask7:
	.string "Oh, hello, little {PLAYER_boy}…\n"
	.string "Can we help you?$"
RustboroCity_Text_AquasTask9:
	.string "You…{PAUSE 10} You want to…{PAUSE 20} join us…?$"
RustboroCity_Text_AquasTask11:
	.string "{PAUSE 16}Alright.{PAUSE 16}{PLAY_SE SE_DANSA}{PAUSE 10} On one condition.\p"
	.string "We need you to retrieve those\n"
	.string "{ITEM}Devon Goods{END} from that Team Magma\l"
	.string "bloke who just ran off.\p"
	.string "If you can do that, then…{PAUSE 10}\n"
	.string "We'll consider it.$"

RustboroCity_Movement_AquasTask_BoyGlanceRight:
	face_right
	delay_8
	delay_4
	walk_in_place_fastest_up
	step_end
RustboroCity_Movement_AquasTask_GirlGlanceDown:
	face_down
	delay_8
	delay_4
	walk_in_place_fastest_right
	step_end
RustboroCity_Movement_AquasTask_3GlanceRight:
	face_right
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end

.align 2
RustboroCity_MovementTable_AquasTask4_PlayerCreep1:
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepDiagDown
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepDiagDown
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepForward
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepDiagUp
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepDiagUp
	.4byte 0
.align 2
RustboroCity_MovementTable_AquasTask4_PlayerCreep2:
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepDiagDown
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepForward
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepForward
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepForward
	.4byte RustboroCity_Movement_AquasTask_PlayerCreepDiagUp
	.4byte 0
RustboroCity_Movement_AquasTask_PlayerCreepDiagUp:
	walk_up
	walk_slow_right
	step_end
RustboroCity_Movement_AquasTask_PlayerCreepDiagDown:
	walk_down
	walk_slow_right
	step_end
RustboroCity_Movement_AquasTask_PlayerCreepForward:
	walk_slow_right
	step_end
RustboroCity_Movement_AquasTask8_PlayerTalk:
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	step_end

.align 2
RustboroCity_MovementTable_AquasTask1_CamMovement1:
	.4byte RustboroCity_Movement_AquasTask1_CamMovement1
	.4byte RustboroCity_Movement_AquasTask1_CamMovement2
	.4byte RustboroCity_Movement_AquasTask1_CamMovement3
	.4byte RustboroCity_Movement_AquasTask1_CamMovement4
	.4byte RustboroCity_Movement_AquasTask1_CamMovement5
	.4byte 0

RustboroCity_Movement_AquasTask1_CamMovement1:
	walk_diag_southeast
	walk_diag_southeast
	walk_right
	walk_right
	walk_right
	step_end
RustboroCity_Movement_AquasTask1_CamMovement2:
	walk_diag_southeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
RustboroCity_Movement_AquasTask1_CamMovement3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
RustboroCity_Movement_AquasTask1_CamMovement4:
	walk_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
RustboroCity_Movement_AquasTask1_CamMovement5:
	walk_diag_northeast
	walk_diag_northeast
	walk_right
	walk_right
	walk_right
	step_end
RustboroCity_Movement_AquasTask1_AquaGuy:
	walk_fastest_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_Movement_AquasTask7_AquaGuy:
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end
RustboroCity_Movement_AquasTask7_Aqua3:
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end
RustboroCity_Movement_AquasTask7_Camera:
	walk_slow_left
	walk_slow_left
	step_end
RustboroCity_Movement_AquasTask8_AquaGirlBackup:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end
RustboroCity_Movement_AquasTask9_AquaGirl:
	walk_right
	walk_right
	walk_in_place_fastest_right
	step_end
RustboroCity_Movement_AquasTask9_Aqua3:
	delay_4
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end
RustboroCity_Movement_AquasTask9_AquaBoy:
	delay_8
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_in_place_fastest_left
	step_end
RustboroCity_Movement_AquasTask10_AquaGirl:
	walk_in_place_fast_up
	delay_16
	delay_8
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_fast_up
	delay_16
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_down
	walk_in_place_fast_left
	step_end
RustboroCity_Movement_AquasTask10_Aqua3:
	walk_in_place_fast_right
	delay_16
	delay_16
	walk_in_place_fast_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fast_right
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_left
	step_end
RustboroCity_Movement_AquasTask10_AquaBoy:
	delay_4
	delay_8
	walk_in_place_fast_up
	delay_16
	walk_in_place_fast_left
	delay_16
	delay_16
	walk_in_place_fast_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	step_end
RustboroCity_Movement_AquasTask10_Player:
	delay_16
	delay_16
	delay_16
	walk_slow_right
	step_end
RustboroCity_Movement_AquasTask11_Player:
	delay_16
	delay_16
	delay_16
	delay_16
	jump_in_place_right
	step_end

RustboroCity_Movement_AquasTask12_AquaGirl:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_up
	step_end
RustboroCity_Movement_AquasTask12_AquaBoy:
	walk_left
	delay_16
	delay_8
	walk_down
	walk_left
	walk_down
	walk_in_place_fastest_up
	step_end
RustboroCity_Movement_AquasTask12_Aqua3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_up
	step_end
RustboroCity_Movement_AquasTask12_Player:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fast_down
	delay_16
	delay_16
	delay_8
	walk_in_place_fast_right
	step_end

@ -----------------------------------------------------

RustboroCity_EventScript_SetupAqua3:
	setobjectxyperm LID_AQUA_BOY, 29, 12
	setobjectxyperm LID_AQUA_GIRL, 27, 12
	setobjectxyperm LID_AQUA_3, 28, 12
	setobjectmovementtype LID_AQUA_BOY, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LID_AQUA_GIRL, MOVEMENT_TYPE_LOOK_AROUND
	setobjectmovementtype LID_AQUA_3, MOVEMENT_TYPE_LOOK_AROUND
	return

@ -----------------------------------------------------

RustboroCity_EventScript_SetupAqua4:
	setobjectxyperm LID_AQUA_BOY, 29, 12
	setobjectxyperm LID_AQUA_GIRL, 27, 12
	setobjectxyperm LID_AQUA_3, 28, 12
	return

RustboroCity_TriggerScript_AquaTaskReturn::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_Y, 8
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_AQUA_BOY, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	@
	markasdialog -26
	msgbox RustboroCity_Text_AquaTaskReturn1
	closemessage
	@
	selectpointer RustboroCity_MovementTable_AquaTaskReturn2_Player, VAR_INTERACT_Y
	applymovement EVENT_OBJ_ID_PLAYER, 0
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquaTaskReturn2_AquaBoy
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquaTaskReturn2_AquaGirl
	applymovement LID_AQUA_3, RustboroCity_Movement_AquaTaskReturn2_AquaThree
	waitmovement 0
	waitmovement EVENT_OBJ_ID_PLAYER
	@
	markasdialog 6
	msgbox RustboroCity_Text_AquaTaskReturn3
	playse SE_SELECT
	@
	msgbox RustboroCity_Text_AquaTaskReturn4, MSGBOX_CDESCRIBE
	playse SE_SELECT
	takeitem ITEM_DEVON_GOODS, 1
	@
	applymovement LID_AQUA_3, RustboroCity_Movement_AquaTaskReturn5_AquaThree
	msgbox RustboroCity_Text_AquaTaskReturn5
	closemessage
	@
	special SpawnCameraObject
	playse SE_PIN
	applymovement EVENT_OBJ_ID_PLAYER, RustboroCity_Movement_AquaTaskReturn6_Player
	applymovement LID_AQUA_3, RustboroCity_Movement_AquaTaskReturn6_AquaThree
	@ Determine friendship level, split cutscene
	setvar VAR_TEMP_F, 0
	addvar VAR_TEMP_F, VAR_AQUA_BOY_FRIENDSHIP
	addvar VAR_TEMP_F, VAR_AQUA_GIRL_FRIENDSHIP
	compare VAR_TEMP_F, 2 @ Broken??
	goto_if_eq RustboroCity_TriggerScript_AquaTaskReturn_FriendBoth
	compare VAR_AQUA_BOY_FRIENDSHIP, 1
	goto_if_eq RustboroCity_TriggerScript_AquaTaskReturn_FriendBoy
	compare VAR_AQUA_GIRL_FRIENDSHIP, 1
	goto_if_eq RustboroCity_TriggerScript_AquaTaskReturn_FriendGirl
	goto RustboroCity_TriggerScript_AquaTaskReturn_FriendNone
	end

RustboroCity_TriggerScript_AquaTaskReturn_FriendBoth:
	@ three runs off, protag is sad
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquaTaskReturn6_AquaGirl
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquaTaskReturn6_AquaBoy
	waitmovement LID_AQUA_BOY
	@
	markasdialog 6
	msgbox RustboroCity_Text_AquaTaskReturn7
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	playse SE_SELECT
	message RustboroCity_Text_AquaTaskReturn8_boy
	waitmessage
	@
	applymovement LID_AQUA_GIRL, Common_Movement_WalkRight2
	markasdialog -14
	message RustboroCity_Text_AquaTaskReturn8_bgirl
	waitmessage
	waitmovement 0
	@
	markasdialog 6
	message RustboroCity_Text_AquaTaskReturn8a
	waitmessage
	@
	goto RustboroCity_TriggerScript_AquaTaskReturn_Finish
	end

RustboroCity_TriggerScript_AquaTaskReturn_FriendBoy:
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquaTaskReturn6_AquaGirl
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquaTaskReturn6_AquaBoy
	waitmovement LID_AQUA_BOY
	@
	markasdialog 12
	msgbox RustboroCity_Text_AquaTaskReturn7
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	playse SE_SELECT
	message RustboroCity_Text_AquaTaskReturn8_boy
	waitmessage
	message RustboroCity_Text_AquaTaskReturn8a
	waitmessage
	@
	goto RustboroCity_TriggerScript_AquaTaskReturn_Finish
	end

RustboroCity_TriggerScript_AquaTaskReturn_FriendGirl:
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquaTaskReturn6a_AquaGirl
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquaTaskReturn6a_AquaBoy
	waitmovement LID_AQUA_GIRL
	@
	markasdialog 12
	msgbox RustboroCity_Text_AquaTaskReturn7
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	playse SE_SELECT
	message RustboroCity_Text_AquaTaskReturn8_girl
	waitmessage
	message RustboroCity_Text_AquaTaskReturn8a
	waitmessage
	@
	goto RustboroCity_TriggerScript_AquaTaskReturn_Finish
	end

RustboroCity_TriggerScript_AquaTaskReturn_FriendNone:
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquaTaskReturn6_AquaGirl
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquaTaskReturn6_AquaBoy
	waitmovement LID_AQUA_BOY
	@
	markasdialog 6
	msgbox RustboroCity_Text_AquaTaskReturn7
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	playse SE_SELECT
	message RustboroCity_Text_AquaTaskReturn8_none
	waitmessage
	@
	goto RustboroCity_TriggerScript_AquaTaskReturn_Finish
	end

RustboroCity_TriggerScript_AquaTaskReturn_Finish:
	msgbox RustboroCity_Text_AquaTaskReturn9
	closemessage
	applymovement LID_AQUA_GIRL, RustboroCity_Movement_AquaTaskReturn9
	applymovement LID_AQUA_BOY, RustboroCity_Movement_AquaTaskReturn9
	applymovement EVENT_OBJ_ID_CAMERA, Common_Movement_WalkRight2
	waitmovement LID_AQUA_BOY
	waitmovement EVENT_OBJ_ID_CAMERA
	@ Clean up
	special RemoveCameraObject
	removeobject LID_AQUA_GIRL
	removeobject LID_AQUA_BOY
	removeobject LID_AQUA_3
	setvar VAR_RUSTBORO_STATE, 7
	setvar VAR_LOGAN_STATE, 2
	setflag FLAG_AQUA_FETCH_QUEST_COMPLETED
	setflag FLAG_HIDE_ROUTE_116_TUNNELER
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_LOVER_MAN
	clearflag FLAG_HIDE_RUSTURF_TUNNEL_LOVER_WOMAN
	clearflag FLAG_HIDE_BRINEYS_HOUSE_MR_BRINEY
	clearflag FLAG_HIDE_BRINEYS_HOUSE_PEEKO
	setvar VAR_BRINEY_LOCATION, 1
	call Common_EventScript_ClearSceneFlags
	releaseall
	end

RustboroCity_Text_AquaTaskReturn1:
	.string "Oh! {PLAYER_They}'s back!$"
RustboroCity_Text_AquaTaskReturn3:
	.string "So, did you get it?$"
RustboroCity_Text_AquaTaskReturn4:
	.string "{PLAYER} handed over the\n"
	.string "{ITEM}Devon Goods{END}.$"
RustboroCity_Text_AquaTaskReturn5:
	.string "Oh, wow, {PLAYER_they} actually got it!\n"
	.string "The boss'll be so pleased!\p"
	.string "Thanks, sucker!!$"
RustboroCity_Text_AquaTaskReturn7:
	.string "Hey, uh…\p"
	.string "Sorry about him.\p"
	.string "You did great, getting that for us.\n"
	.string "What's your name, kid?$"
RustboroCity_Text_AquaTaskReturn8_boy:
	.string "{PLAYER}?\n"
	.string "My name's {AQUA_BOY}.\p$"
RustboroCity_Text_AquaTaskReturn8_girl:
	.string "{PLAYER}?\n"
	.string "My name's {AQUA_GIRL}.\p$"
RustboroCity_Text_AquaTaskReturn8_bgirl:
	.string "And my name's {AQUA_GIRL}.\p$"
RustboroCity_Text_AquaTaskReturn8a:
	.string "We'll put in a good word for you.\p"
	.string "Maybe the boss'll give ya some colors\n"
	.string "if we meet again, alright?\p$"
RustboroCity_Text_AquaTaskReturn8_none:
	.string "{PLAYER}?\n"
	.string "We'll put in a good word for you.\p"
	.string "Maybe the boss'll give ya some colors\n"
	.string "if we meet again, alright?\p$"
RustboroCity_Text_AquaTaskReturn9:
	.string "See yah around, {PLAYER}.$"

.align 2
RustboroCity_MovementTable_AquaTaskReturn2_Player:
	.4byte RustboroCity_Movement_AquaTaskReturn2_Player1
	.4byte RustboroCity_Movement_AquaTaskReturn2_Player2
	.4byte RustboroCity_Movement_AquaTaskReturn2_Player3
	.4byte RustboroCity_Movement_AquaTaskReturn2_Player4
	.4byte RustboroCity_Movement_AquaTaskReturn2_Player5
	.4byte 0
RustboroCity_Movement_AquaTaskReturn2_Player1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
RustboroCity_Movement_AquaTaskReturn2_Player2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
RustboroCity_Movement_AquaTaskReturn2_Player3:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
RustboroCity_Movement_AquaTaskReturn2_Player4:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
RustboroCity_Movement_AquaTaskReturn2_Player5:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_Movement_AquaTaskReturn2_AquaBoy:
	walk_up
	walk_right
	walk_right
	delay_16
	delay_16
	walk_in_place_fast_up
	step_end
RustboroCity_Movement_AquaTaskReturn2_AquaGirl:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_down
	step_end
RustboroCity_Movement_AquaTaskReturn2_AquaThree:
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

RustboroCity_Movement_AquaTaskReturn5_AquaThree:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	delay_1
	step_end

RustboroCity_Movement_AquaTaskReturn6_Player:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_down
	delay_16
	delay_16
	walk_slow_right
	delay_16
	walk_slow_right
	step_end
RustboroCity_Movement_AquaTaskReturn6_AquaThree:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
RustboroCity_Movement_AquaTaskReturn6_AquaGirl:
	delay_2
	delay_4
	walk_left
	walk_fast_left
	walk_left
	delay_16
	delay_16
	delay_4
	delay_1
	walk_in_place_fast_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end
RustboroCity_Movement_AquaTaskReturn6_AquaBoy:
	delay_8
	delay_1
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	step_end

RustboroCity_Movement_AquaTaskReturn6a_AquaBoy:
	walk_left
	walk_fast_left
	walk_left
	delay_16
	delay_16
	walk_in_place_fast_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	step_end
RustboroCity_Movement_AquaTaskReturn6a_AquaGirl:
	walk_slow_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_right
	step_end

RustboroCity_Movement_AquaTaskReturn9:
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

#undef LID_MAGMA
#undef LID_AQUA_GIRL
#undef LID_AQUA_BOY
#undef LID_AQUA_3

@ -----------------------------------------------------


RustboroCity_Text_1E183E: @ 81E183E
	.string "Oh, it's you!\p"
	.string "You're that fantastic TRAINER who\n"
	.string "helped me in Petalburg Woods!\p"
	.string "Help me! I was robbed by Team Aqua!\n"
	.string "I have to get the DEVON GOODS back!\p"
	.string "If I don't…\n"
	.string "I'm going to be in serious trouble.$"



RustboroCity_Text_1E194D: @ 81E194D
	.string "Oh! How did it go?\n"
	.string "The DEVON GOODS?\p"
	.string "You did!\n"
	.string "You got them back!\p"
	.string "You really are a great TRAINER!\p"
	.string "I know! As my thanks, I'll give you\n"
	.string "another GREAT BALL!$"

RustboroCity_EventScript_1E0A3B:: @ 81E0A3B
	msgbox RustboroCity_Text_1E1904, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_1E0A44:: @ 81E0A44
	msgbox RustboroCity_Text_1E194D, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_1E0A4D:: @ 81E0A4D
	applymovement 9, RustboroCity_Movement_1E0AC1
	waitmovement 0
	return

RustboroCity_EventScript_1E0A58:: @ 81E0A58
	applymovement 9, RustboroCity_Movement_1E0AC5
	waitmovement 0
	return

RustboroCity_EventScript_1E0A63:: @ 81E0A63
	applymovement 9, RustboroCity_Movement_1E0ACA
	waitmovement 0
	return

RustboroCity_EventScript_1E0A6E:: @ 81E0A6E
	applymovement 9, RustboroCity_Movement_1E0ACF
	waitmovement 0
	return

RustboroCity_EventScript_1E0A79:: @ 81E0A79
	applymovement 9, RustboroCity_Movement_1E0AD5
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return



RustboroCity_Movement_1E0AA0: @ 81E0AA0
	walk_fastest_right
	walk_fastest_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

RustboroCity_Movement_1E0AB1: @ 81E0AB1
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_up
	step_end

RustboroCity_Movement_1E0AB9: @ 81E0AB9
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RustboroCity_Movement_1E0AC1: @ 81E0AC1
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0AC5: @ 81E0AC5
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0ACA: @ 81E0ACA
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0ACF: @ 81E0ACF
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

RustboroCity_Movement_1E0AD5: @ 81E0AD5
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

RustboroCity_EventScript_1E0ADD:: @ 81E0ADD
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_EventScript_1E0AF2
	msgbox RustboroCity_Text_1E1904, MSGBOX_DEFAULT
	release
	end
RustboroCity_Text_1E1904: @ 81E1904
	.string "That shady character, I think he took\n"
	.string "off towards the tunnel over there.$"

RustboroCity_EventScript_1E0AF2:: @ 81E0AF2
	waitse
	setvar VAR_TEMP_1, 4
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0AFE:: @ 81E0AFE
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B0A:: @ 81E0B0A
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B16:: @ 81E0B16
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B22:: @ 81E0B22
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_1E0B2E
	end

RustboroCity_EventScript_1E0B2E:: @ 81E0B2E
	compare VAR_TEMP_1, 0
	call_if_eq RustboroCity_EventScript_1E0B6F
	compare VAR_TEMP_1, 1
	call_if_eq RustboroCity_EventScript_1E0B9B
	compare VAR_TEMP_1, 2
	call_if_eq RustboroCity_EventScript_1E0BC7
	compare VAR_TEMP_1, 3
	call_if_eq RustboroCity_EventScript_1E0BF3
	@ setflag FLAG_INTERACTED_WITH_DEVON_EMPLOYEE_GOODS_STOLEN
	setvar VAR_RUSTBORO_STATE, 3
	moveobjectoffscreen 9
	msgbox RustboroCity_Text_1E183E, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_1E0B6F:: @ 81E0B6F
	applymovement 9, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RustboroCity_EventScript_1E0B9B:: @ 81E0B9B
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

RustboroCity_EventScript_1E0BC7:: @ 81E0BC7
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_EventScript_1E0BF3:: @ 81E0BF3
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, RustboroCity_Movement_1E0C29
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_Movement_1E0C29: @ 81E0C29
	walk_down
	step_end

RustboroCity_EventScript_1E0C2B:: @ 81E0C2B
	lockall
	setvar VAR_TEMP_1, 0
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C37:: @ 81E0C37
	lockall
	setvar VAR_TEMP_1, 1
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C43:: @ 81E0C43
	lockall
	setvar VAR_TEMP_1, 2
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C4F:: @ 81E0C4F
	lockall
	setvar VAR_TEMP_1, 3
	goto RustboroCity_EventScript_1E0C5B
	end

RustboroCity_EventScript_1E0C5B:: @ 81E0C5B
	compare VAR_TEMP_1, 0
	call_if_eq RustboroCity_EventScript_1E0CDC
	compare VAR_TEMP_1, 1
	call_if_eq RustboroCity_EventScript_1E0D08
	compare VAR_TEMP_1, 2
	call_if_eq RustboroCity_EventScript_1E0D34
	compare VAR_TEMP_1, 3
	call_if_eq RustboroCity_EventScript_1E0D60
	compare VAR_TEMP_1, 4
	call_if_eq RustboroCity_EventScript_1E0D96
	msgbox RustboroCity_Text_1E194D, MSGBOX_DEFAULT
	giveitem_std ITEM_GREAT_BALL
	compare VAR_RESULT, 0
	call_if_eq RustboroCity_EventScript_1E0CD3
	msgbox RustboroCity_Text_1E1A21, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RETURNED_DEVON_GOODS
	@ setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_EMPLOYEE_1
	setvar VAR_RUSTBORO_STATE, 5
	delay 30
	warp MAP_RUSTBORO_CITY_DEVON_CORP_3F, 255, 2, 2
	waitstate
	releaseall
	end

RustboroCity_EventScript_1E0CD3:: @ 81E0CD3
	msgbox RustboroCity_Text_1E19E5, MSGBOX_DEFAULT
	return

RustboroCity_EventScript_1E0CDC:: @ 81E0CDC
	applymovement 9, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

RustboroCity_EventScript_1E0D08:: @ 81E0D08
	applymovement 9, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

RustboroCity_EventScript_1E0D34:: @ 81E0D34
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_EventScript_1E0D60:: @ 81E0D60
	applymovement 9, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	applymovement 9, RustboroCity_Movement_1E0C29
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

RustboroCity_EventScript_1E0D96:: @ 81E0D96
	applymovement 9, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 9, Common_Movement_Delay48
	waitmovement 0
	return

RustboroCity_EventScript_1E0DB8:: @ 81E0DB8
	lockall
	call_if_unset FLAG_MET_RIVAL_RUSTBORO, Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0DF3:: @ 81E0DF3
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E120E
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0E33:: @ 81E0E33
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1215
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0E73:: @ 81E0E73
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E121B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0EB3:: @ 81E0EB3
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1220
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0EF3:: @ 81E0EF3
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1224
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0F33:: @ 81E0F33
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1227
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0F73:: @ 81E0F73
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E122B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0FB3:: @ 81E0FB3
	lockall
	call Common_EventScript_PlayRivalMusic
	applymovement 14, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 14, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 14, Common_Movement_Delay48
	waitmovement 0
	applymovement 14, RustboroCity_Movement_1E1230
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	goto RustboroCity_EventScript_1E0FF3

RustboroCity_EventScript_1E0FF3:: @ 81E0FF3
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq RustboroCity_EventScript_1E100B
	compare VAR_RESULT, FEMALE
	goto_if_eq RustboroCity_EventScript_1E1114
	end

RustboroCity_EventScript_1E100B:: @ 81E100B
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_1E10C1
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_1E1070
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_1E1A49, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Text_1E1ADB, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_STATE, 8
	setvar VAR_0x8008, 0
	msgbox RustboroCity_Text_1E1AFA, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1092
	msgbox RustboroCity_Text_1E1BD3, MSGBOX_DEFAULT
	call RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E1070:: @ 81E1070
	setvar VAR_0x8008, 1
	msgbox RustboroCity_Text_1E1C48, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1092
	msgbox RustboroCity_Text_1E1BD3, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_1E1092:: @ 81E1092
	msgbox RustboroCity_Text_1E1C84, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_1E10DB
	case 1, RustboroCity_EventScript_1E10EE
	case 2, RustboroCity_EventScript_1E1101
	end

RustboroCity_EventScript_1E10C1:: @ 81E10C1
	msgbox RustboroCity_Text_1E1CE7, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E10D6:: @ 81E10D6
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

RustboroCity_EventScript_1E10DB:: @ 81E10DB
	trainerbattle_no_intro TRAINER_MAY_14, RustboroCity_Text_1E1CC1
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E10C1
	end

RustboroCity_EventScript_1E10EE:: @ 81E10EE
	trainerbattle_no_intro TRAINER_MAY_15, RustboroCity_Text_1E1CC1
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E10C1
	end

RustboroCity_EventScript_1E1101:: @ 81E1101
	trainerbattle_no_intro TRAINER_MAY_10, RustboroCity_Text_1E1CC1
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E10C1
	end

RustboroCity_EventScript_1E1114:: @ 81E1114
	goto_if_set FLAG_DEFEATED_RIVAL_RUSTBORO, RustboroCity_EventScript_1E11C0
	goto_if_set FLAG_MET_RIVAL_RUSTBORO, RustboroCity_EventScript_1E1174
	setflag FLAG_MET_RIVAL_RUSTBORO
	msgbox RustboroCity_Text_1E1D7D, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Text_1E1E11, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_RIVAL_MATCH_CALL
	setvar VAR_RUSTBORO_STATE, 8
	msgbox RustboroCity_Text_1E1E34, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1191
	msgbox RustboroCity_Text_1E1F2F, MSGBOX_DEFAULT
	call RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E1174:: @ 81E1174
	msgbox RustboroCity_Text_1E1F76, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_EventScript_1E1191
	msgbox RustboroCity_Text_1E1F2F, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_EventScript_1E1191:: @ 81E1191
	msgbox RustboroCity_Text_1E1FA9, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, RustboroCity_EventScript_1E11D5
	case 1, RustboroCity_EventScript_1E11E8
	case 2, RustboroCity_EventScript_1E11FB
	end

RustboroCity_EventScript_1E11C0:: @ 81E11C0
	msgbox RustboroCity_Text_1E2002, MSGBOX_DEFAULT
	compare VAR_0x8008, 0
	call_if_eq RustboroCity_EventScript_1E10D6
	releaseall
	end

RustboroCity_EventScript_1E11D5:: @ 81E11D5
	trainerbattle_no_intro TRAINER_BRENDAN_10, RustboroCity_Text_1E1FE9
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E11C0
	end

RustboroCity_EventScript_1E11E8:: @ 81E11E8
	trainerbattle_no_intro TRAINER_BRENDAN_12, RustboroCity_Text_1E1FE9
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E11C0
	end

RustboroCity_EventScript_1E11FB:: @ 81E11FB
	trainerbattle_no_intro TRAINER_BRENDAN_11, RustboroCity_Text_1E1FE9
	setflag FLAG_DEFEATED_RIVAL_RUSTBORO
	goto RustboroCity_EventScript_1E11C0
	end

RustboroCity_Movement_1E120E: @ 81E120E
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E1215: @ 81E1215
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E121B: @ 81E121B
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E1220: @ 81E1220
	walk_down
	walk_left
	walk_down
	step_end

RustboroCity_Movement_1E1224: @ 81E1224
	walk_down
	walk_down
	step_end

RustboroCity_Movement_1E1227: @ 81E1227
	walk_down
	walk_right
	walk_down
	step_end

RustboroCity_Movement_1E122B: @ 81E122B
	walk_down
	walk_right
	walk_right
	walk_down
	step_end

RustboroCity_Movement_1E1230: @ 81E1230
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	step_end









RustboroCity_Text_1E19E5: @ 81E19E5
	.string "You're loaded with items.\n"
	.string "I can't give you this GREAT BALL.$"

RustboroCity_Text_1E1A21: @ 81E1A21
	.string "Excuse me, please!\n"
	.string "Please come with me!$"

RustboroCity_Text_1E1A49: @ 81E1A49
	.string "May: Oh, hi, {PLAYER}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your PokéNav!\p"
	.string "Let's register each other so we can\n"
	.string "contact one another anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_1E1ADB: @ 81E1ADB
	.string "Registered MAY\n"
	.string "in the PokéNav.$"

RustboroCity_Text_1E1AFA: @ 81E1AFA
	.string "May: Oh, by the way, I passed\n"
	.string "MR. BRINEY in Petalburg Woods.\p"
	.string "I guess he's on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "How's your Pokédex coming along,\n"
	.string "{PLAYER}? Mine's looking pretty decent!\p"
	.string "So…\n"
	.string "How about a little battle?$"

RustboroCity_Text_1E1BD3: @ 81E1BD3
	.string "May: Oh, what's the matter?\p"
	.string "Haven't you caught or raised your\n"
	.string "Pokémon very much?\p"
	.string "That's not very good for a TRAINER!$"

RustboroCity_Text_1E1C48: @ 81E1C48
	.string "May: So, what do you think?\n"
	.string "How about a little battle here?$"

RustboroCity_Text_1E1C84: @ 81E1C84
	.string "May: You just became a TRAINER,\n"
	.string "{PLAYER}. I'm not going to lose!$"

RustboroCity_Text_1E1CC1: @ 81E1CC1
	.string "Yikes!\n"
	.string "You're better than I expected!$"

RustboroCity_Text_1E1CE7: @ 81E1CE7
	.string "May: Oh, by the way, MR. BRINEY, who\n"
	.string "I just passed…\p"
	.string "{PLAYER}, you just moved here so you\n"
	.string "might not know this, but MR. BRINEY\l"
	.string "was once a revered seafarer.$"

RustboroCity_Text_1E1D7D: @ 81E1D7D
	.string "Brendan: Oh, hey, {PLAYER}!\p"
	.string "You had a MATCH CALL feature put\n"
	.string "on your PokéNav! Cool!\p"
	.string "Let's register each other so we can\n"
	.string "get in touch anytime!\p"
	.string "… … … … … …$"

RustboroCity_Text_1E1E11: @ 81E1E11
	.string "Registered BRENDAN\n"
	.string "in the PokéNav.$"

RustboroCity_Text_1E1E34: @ 81E1E34
	.string "Brendan: By the way, {PLAYER}, I walked\n"
	.string "by MR. BRINEY in Petalburg Woods.\p"
	.string "I bet he was on his way home to his\n"
	.string "cottage by the sea.\p"
	.string "{PLAYER}, how's your Pokédex?\n"
	.string "Have you filled in any pages yet?\p"
	.string "Mine rules.\p"
	.string "Want to have a battle to test how\n"
	.string "far you've progressed?$"

RustboroCity_Text_1E1F2F: @ 81E1F2F
	.string "Brendan: What's the matter? Don't have\n"
	.string "any confidence in your Pokémon?$"

RustboroCity_Text_1E1F76: @ 81E1F76
	.string "Brendan: What's up?\n"
	.string "Want to have a battle with me?$"

RustboroCity_Text_1E1FA9: @ 81E1FA9
	.string "Brendan: I know you just became\n"
	.string "a TRAINER, but I won't go easy!$"

RustboroCity_Text_1E1FE9: @ 81E1FE9
	.string "Hmm…\n"
	.string "You're pretty good.$"

RustboroCity_Text_1E2002: @ 81E2002
	.string "Brendan: By the way, you know\n"
	.string "MR. BRINEY? The guy I just passed?\p"
	.string "I bet you didn't know this, since you\n"
	.string "just moved here, {PLAYER}, but\l"
	.string "MR. BRINEY was once a great sailor.$"
