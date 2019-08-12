
#define LID_NORMAN 1
#define LID_LOGAN 10
#define LID_OLDLEADER 11

PetalburgCity_Gym_MapScripts:: @ 8204889
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_Gym_MapScript2_WarpTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_Gym_MapScript2_FrameTable
	.byte 0

PetalburgCity_Gym_EventScript_OpenGym::
	clearflag FLAG_HIDE_PETALBURG_GYM_GREETER
	setvar VAR_PETALBURG_STATE, 10
	setflag FLAG_PETALBURG_MART_EXPANDED_ITEMS
	setflag FLAG_HIDE_PETALBURG_CITY_GYM_LOCK
	setflag FLAG_HIDE_PETALBURG_GYM_OLD_LEADER
	return

@ -----------------------------------------------------

PetalburgCity_Gym_OnLoad: @ 820489E
	compare VAR_NUM_BADGES, 4
	goto_if_eq PetalburgCity_Gym_EventScript_2048B5
	compare VAR_NUM_BADGES, 5
	call_if_ge PetalburgCity_Gym_RunAllGymSpecials
	end

PetalburgCity_Gym_EventScript_2048B5:: @ 82048B5
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_20555E
	checktrainerflag TRAINER_RANDALL
	call_if_eq PetalburgCity_Gym_EventScript_20557F
	checktrainerflag TRAINER_MARY
	call_if_eq PetalburgCity_Gym_EventScript_2055A0
	checktrainerflag TRAINER_PARKER
	call_if_eq PetalburgCity_Gym_EventScript_2055C1
	checktrainerflag TRAINER_ALEXIA
	call_if_eq PetalburgCity_Gym_EventScript_2055E2
	checktrainerflag TRAINER_GEORGE
	call_if_eq PetalburgCity_Gym_EventScript_205603
	checktrainerflag TRAINER_JODY
	call_if_eq PetalburgCity_Gym_EventScript_205624
	checktrainerflag TRAINER_BERKE
	call_if_eq PetalburgCity_Gym_EventScript_205645
	end

PetalburgCity_Gym_RunAllGymSpecials:: @ 82048FF
	setvar VAR_0x8005, 1
	call PetalburgCity_Gym_EventScript_20555E
	call PetalburgCity_Gym_EventScript_20557F
	call PetalburgCity_Gym_EventScript_2055A0
	call PetalburgCity_Gym_EventScript_2055C1
	call PetalburgCity_Gym_EventScript_2055E2
	call PetalburgCity_Gym_EventScript_205603
	call PetalburgCity_Gym_EventScript_205624
	call PetalburgCity_Gym_EventScript_205645
	return

@ -----------------------------------------------------

PetalburgCity_Gym_OnTransition: @ 820492D
	@ compare VAR_NUM_BADGES, 1
	@ call_if_eq PetalburgCity_Gym_EventScript_20494D
	@ compare VAR_NUM_BADGES, 6
	@ call_if_lt PetalburgCity_Gym_EventScript_204955
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgCity_Gym_EventScript_20495D
	end

@ PetalburgCity_Gym_EventScript_20494D:: @ 820494D
@ 	setobjectxyperm LID_LOGAN, 5, 108
@ 	return

@ PetalburgCity_Gym_EventScript_204955:: @ 8204955
@ 	setobjectxyperm LID_NORMAN, 4, 107
@ 	return

PetalburgCity_Gym_EventScript_20495D:: @ 820495D
	setorcopyvar VAR_TRAINER_BATTLE_OPPONENT_A, 269
	specialvar VAR_RESULT, IsTrainerReadyForRematch
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_204985
	compare VAR_NUM_BADGES, 8
	goto_if_eq PetalburgCity_Gym_EventScript_204985
	setobjectxyperm LID_NORMAN, 4, 107
	return

PetalburgCity_Gym_EventScript_204985:: @ 8204985
	setvar VAR_NUM_BADGES, 8
	end

@ -----------------------------------------------------

PetalburgCity_Gym_MapScript2_FrameTable: @ 820499A
	map_script_2 VAR_PETALBURG_STATE, 0, PetalburgCity_Gym_EventScript_LoganScene
	.2byte 0

PetalburgCity_Gym_EventScript_LoganScene::
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	applymovement LID_LOGAN, Common_Movement_Angry
	markasdialog -6
	msgbox PetalburgCity_Gym_Text_LoganScene1
	waitmovement 0
	closemessage
	markasdialog 6
	applymovement LID_OLDLEADER, PetalburgCity_Gym_Movement_LoganScene2b
	applymovement LID_LOGAN, PetalburgCity_Gym_Movement_LoganScene2a
	applymovement EVENT_OBJ_ID_PLAYER, PetalburgCity_Gym_Movement_LoganScene2c
	waitmovement 0
	playse SE_KAIDAN
	removeobject LID_LOGAN
	msgbox PetalburgCity_Gym_Text_LoganScene3
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox PetalburgCity_Gym_Text_LoganScene4
	setvar VAR_PETALBURG_STATE, 1
	setflag FLAG_HIDE_PETALBURG_GYM_WALLY
	clearflag FLAG_HIDE_PETALBURG_CITY_LOGAN
	releaseall
	end
PetalburgCity_Gym_Text_LoganScene1:
	.string "If you won't help me, then I'll\n"
	.string "just go do it myself!$"
PetalburgCity_Gym_Movement_LoganScene2a:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	set_invisible
	step_end
PetalburgCity_Gym_Movement_LoganScene2b:
	delay_8
	walk_in_place_fastest_down
	step_end
PetalburgCity_Gym_Movement_LoganScene2c:
	delay_16
	face_right
	delay_8
	face_down
	step_end
PetalburgCity_Gym_Text_LoganScene3:
	.string "Good! It's not my job to just give\n"
	.string "away Pokémon like they're candy!\p"
	.string "Go find a man in a lab coat if you\n"
	.string "want a handout!$"
PetalburgCity_Gym_Text_LoganScene4:
	.string "And what do you want?\p"
	.string "If you're here to challenge me,\n"
	.string "bug off. I don't accept challenges\l"
	.string "from anyone under four badges.$"


@ -----------------------------------------------------

PetalburgCity_Gym_MapScript2_WarpTable: @ 820498B
	map_script_2 VAR_PETALBURG_STATE, 0, PetalburgCity_Gym_EventScript_204995
	.2byte 0

PetalburgCity_Gym_EventScript_204995:: @ 8204995
	@ turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	turnobject LID_OLDLEADER, DIR_EAST
	end

@ -----------------------------------------------------
@ Gym Entrance

PetalburgCity_Gym_EventScript_GymGreeter:: @ 820574F
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205764
	msgbox PetalburgCity_Gym_Text_206542, MSGBOX_DEFAULT
	release
	end
PetalburgCity_Gym_Text_206542: @ 8206542
	.string "Ah, hello, {PLAYER_sir}.\n"
	.string "Here to challenge the Gym Leader?\p"
	.string "The doors in this gym open when you\n"
	.string "beat the awaiting trainers.\p"
	.string "Whoops! The doors in this room are\n"
	.string "already open, so don't attack me!\p"
	.string "The trainers of Petalburg Gym\n"
	.string "use all kinds of items.\p"
	.string "The door at the left leads to\n"
	.string "the Speed Room.\p"
	.string "The door at the right leads to\n"
	.string "the Accuracy Room.\p"
	.string "The room's name will be on\n"
	.string "the door, so choose carefully.\p"
	.string "Once you've chosen the door…\n"
	.string "Well, hey, go for it!$"
PetalburgCity_Gym_EventScript_205764:: @ 8205764
	msgbox PetalburgCity_Gym_Text_2066F3, MSGBOX_DEFAULT
	release
	end
PetalburgCity_Gym_Text_2066F3: @ 82066F3
	.string "Congratulations on your victory!\n"
	.string "What a stunning battle!$"



PetalburgCity_Gym_GymSignage::
	lockall
	goto_if_unset FLAG_BADGE01_GET, PetalburgCity_Gym_GymSignage_OldLeader
	msgbox PetalburgCity_Gym_Text_GymSignageTitle, MSGBOX_SIGN
	goto_if_set FLAG_BADGE05_GET, PetalburgCity_Gym_GymSignage_AfterBadge5
	goto_if_set FLAG_BADGE06_GET, PetalburgCity_Gym_GymSignage_AfterBadge6
	msgbox PetalburgCity_Gym_Text_GymSignageNameList1, MSGBOX_CDESCRIBE
	releaseall
	end
PetalburgCity_Gym_Text_GymSignageTitle: @ 820744C
	.string "{GYM}Petalburg City Pokémon Gym{END}\n"
	.string "Norman's Certified Trainers:$"
PetalburgCity_Gym_Text_GymSignageNameList1:
	.string "There are no names under that.$"
PetalburgCity_Gym_GymSignage_AfterBadge5:
	msgbox PetalburgCity_Gym_Text_GymSignageNameList2, MSGBOX_SIGN
	releaseall
	end
PetalburgCity_Gym_Text_GymSignageNameList2:
	.string "{PLAYER}$"
PetalburgCity_Gym_GymSignage_AfterBadge6:
	msgbox PetalburgCity_Gym_Text_GymSignageNameList3, MSGBOX_SIGN
	releaseall
	end
PetalburgCity_Gym_Text_GymSignageNameList3:
	.string "{PLAYER}, Logan$"

PetalburgCity_Gym_GymSignage_OldLeader:
	msgbox PetalburgCity_Gym_Text_GymSignageTitle_Old, MSGBOX_SIGN
	msgbox PetalburgCity_Gym_Text_GymSignageNameList_Old, MSGBOX_SIGN
	releaseall
	end
PetalburgCity_Gym_Text_GymSignageTitle_Old: @ 820744C
	.string "{GYM}Petalburg City Pokémon Gym{END}\n"
	.string "Malaqui's Certified Trainers:$"
PetalburgCity_Gym_Text_GymSignageNameList_Old:
	.string "Virginia, Johnny, Margaret, Gregg,\n"
	.string "Curtis, Drake, Eileen, Charlie,\n"
	.string "Glacia, Daniel, Sidney, Darlene,\n"
	.string "Kelly, Wallace, Clifton, Leslie,\n"
	.string "Steven, Roxanne, Katie, Phoebe,\n"
	.string "Connor, Holly, Alexis, Flannery,\n"
	.string "Ethan, {RIVAL_BIRCH}$"



PetalburgCity_Gym_EventScript_OldLeader::
	msgbox PetalburgCity_Gym_Text_OldLeader, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_OldLeader:
	.string "I don't accept challenges from\n"
	.string "anyone with less than four badges.\p"
	.string "So kindly go away.$"


@ -----------------------------------------------------
@ Gym Puzzle

PetalburgCity_Gym_EventScript_LockedDoor:: @ 820517D
	msgbox PetalburgCity_Gym_Text_2071F4, MSGBOX_DEFAULT
	releaseall
	end
PetalburgCity_Gym_Text_2071F4: @ 82071F4
	.string "This door appears to be locked\n"
	.string "right now…$"

PetalburgCity_Gym_EventScript_EnterDoor:: @ 820516C
	closemessage
	delay 30
	warpdoor MAP_PETALBURG_CITY_GYM, 255, VAR_0x8008, VAR_0x8009
	waitstate
	releaseall
	end


PetalburgCity_Gym_EventScript_205187:: @ 8205187
	lockall
	compare VAR_NUM_BADGES, 4
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 98
	msgbox PetalburgCity_Gym_Text_207280, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_207280: @ 8207280
	.string "“{PLACE}Accuracy Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_205137:: @ 8205137
	lockall
	compare VAR_NUM_BADGES, 4
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 85
	msgbox PetalburgCity_Gym_Text_20721E, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_20721E: @ 820721E
	.string "“{PLACE}Speed Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_2051BC:: @ 82051BC
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 46
	msgbox PetalburgCity_Gym_Text_2072BB, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_2072BB: @ 82072BB
	.string "“{PLACE}Confusion Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_2051EF:: @ 82051EF
	lockall
	checktrainerflag TRAINER_RANDALL
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_2072F7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_EventScript_205222:: @ 8205222
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 59
	msgbox PetalburgCity_Gym_Text_2072F7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_2072F7: @ 82072F7
	.string "“{PLACE}Defense Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_205255:: @ 8205255
	lockall
	checktrainerflag TRAINER_MARY
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 72
	msgbox PetalburgCity_Gym_Text_207331, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_207331: @ 8207331
	.string "“{PLACE}Recovery Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_205288:: @ 8205288
	lockall
	checktrainerflag TRAINER_PARKER
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_20736C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_EventScript_2052BB:: @ 82052BB
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 20
	msgbox PetalburgCity_Gym_Text_20736C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_20736C: @ 820736C
	.string "“{PLACE}Strength Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_2052EE:: @ 82052EE
	lockall
	checktrainerflag TRAINER_ALEXIA
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_2073A7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_EventScript_205321:: @ 8205321
	lockall
	checktrainerflag TRAINER_GEORGE
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 33
	msgbox PetalburgCity_Gym_Text_2073A7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_2073A7: @ 82073A7
	.string "“{PLACE}One-Hit KO Room{END}”, the sign says.\p"
	.string "Do you want to go through?$"


PetalburgCity_Gym_EventScript_205354:: @ 8205354
	lockall
	checktrainerflag TRAINER_JODY
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_2073E4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_EventScript_205387:: @ 8205387
	lockall
	checktrainerflag TRAINER_BERKE
	goto_if_lt PetalburgCity_Gym_EventScript_LockedDoor
	setvar VAR_0x8008, 7
	setvar VAR_0x8009, 7
	msgbox PetalburgCity_Gym_Text_2073E4, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_Gym_EventScript_EnterDoor
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ReleaseAllEnd
	end
PetalburgCity_Gym_Text_2073E4: @ 82073E4
	.string "“{PLACE}Gym Leader's Room{END}\p"
	.string "“See for yourself what Pokémon await\n"
	.string "you!”, the sign says.\p"
	.string "Do you want to go through?$"

@ -----------------------------------------------------
@ Trainers

PetalburgCity_Gym_EventScript_2053BA:: @ 82053BA
	trainerbattle_single TRAINER_RANDALL, PetalburgCity_Gym_Text_20674F, PetalburgCity_Gym_Text_2067B9, PetalburgCity_Gym_EventScript_2053DE
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_2053ED
	msgbox PetalburgCity_Gym_Text_2067D8, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_20674F: @ 820674F
	.string "The ability to attack before the\n"
	.string "opponent…\p"
	.string "Just that alone puts me at a great\n"
	.string "advantage, don't you agree?$"
PetalburgCity_Gym_Text_2067B9: @ 82067B9
	.string "That was a magnificent battle!$"
PetalburgCity_Gym_Text_2067D8: @ 82067D8
	.string "Go on to the next room where a new\n"
	.string "challenge awaits you.\p"
	.string "At the left is the {PLACE}Confusion Room{END}.\p"
	.string "The right door leads to the\n"
	.string "{PLACE}Defense Room{END}.$"
PetalburgCity_Gym_EventScript_2053DE:: @ 82053DE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_20557F
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_2053ED:: @ 82053ED
	msgbox PetalburgCity_Gym_Text_20685E, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_20685E: @ 820685E
	.string "Whomever you beat, and whomever you\n"
	.string "may lose to, you never shirk from\l"
	.string "training yourself and your Pokémon.\p"
	.string "That's what I think being a\n"
	.string "Gym Leader is all about.$"



PetalburgCity_Gym_EventScript_2053F6:: @ 82053F6
	trainerbattle_single TRAINER_PARKER, PetalburgCity_Gym_Text_2068FD, PetalburgCity_Gym_Text_20694F, PetalburgCity_Gym_EventScript_20541A
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205429
	msgbox PetalburgCity_Gym_Text_206996, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_2068FD: @ 82068FD
	.string "This is the {PLACE}Confusion Room{END}.\p"
	.string "Let me see how well bonded you are\n"
	.string "with your Pokémon!$"
PetalburgCity_Gym_Text_20694F: @ 820694F
	.string "I couldn't confuse your team enough…\n"
	.string "You share a strong bond together.$"
PetalburgCity_Gym_Text_206996: @ 8206996
	.string "The next room is the {PLACE}Strength Room{END}.\n"
	.string "Can you withstand brute force?$"
PetalburgCity_Gym_EventScript_20541A:: @ 820541A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_2055C1
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_205429:: @ 8205429
	msgbox PetalburgCity_Gym_Text_2069D9, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_2069D9: @ 82069D9
	.string "After you beat our Leader, the\n"
	.string "training has become a lot tougher.$"



PetalburgCity_Gym_EventScript_205432:: @ 8205432
	trainerbattle_single TRAINER_GEORGE, PetalburgCity_Gym_Text_206A1B, PetalburgCity_Gym_Text_206AB8, PetalburgCity_Gym_EventScript_205456
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205465
	msgbox PetalburgCity_Gym_Text_206AE9, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_206A1B: @ 8206A1B
	.string "Just when you think you're going to\n"
	.string "win, your opponent restores HP…\p"
	.string "Can you just imagine how awful that\n"
	.string "must feel?\p"
	.string "I'll show you exactly how awful it\n"
	.string "feels!$"
PetalburgCity_Gym_Text_206AB8: @ 8206AB8
	.string "I couldn't restore HP enough…\n"
	.string "What attack power…$"
PetalburgCity_Gym_Text_206AE9: @ 8206AE9
	.string "A trainer's abilities are\n"
	.string "earned only through effort.\p"
	.string "I lost because my own efforts\n"
	.string "weren't enough.\p"
	.string "Go on! The {PLACE}One-Hit KO Room{END} is next.$"
PetalburgCity_Gym_EventScript_205456:: @ 8205456
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_205603
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_205465:: @ 8205465
	msgbox PetalburgCity_Gym_Text_206BB1, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_206BB1: @ 8206BB1
	.string "I'm going to keep training at gyms.\n"
	.string "One day, I'll become a Gym Leader.$"



PetalburgCity_Gym_EventScript_20546E:: @ 820546E
	trainerbattle_single TRAINER_BERKE, PetalburgCity_Gym_Text_206BF4, PetalburgCity_Gym_Text_206C7D, PetalburgCity_Gym_EventScript_205492
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_2054A1
	msgbox PetalburgCity_Gym_Text_206C9F, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_206BF4: @ 8206BF4
	.string "I'll show you how horrid it is for\n"
	.string "a Pokémon to take a critical hit!$"
PetalburgCity_Gym_Text_206C7D: @ 8206C7D
	.string "Your power…\n"
	.string "You're the real deal.$"
PetalburgCity_Gym_Text_206C9F: @ 8206C9F
	.string "Our Gym Leader really is strong.\n"
	.string "He's a trainer worth my respect.\l"
	.string "That's why I train at his gym.\p"
	.string "And, I sense a similar glow coming\n"
	.string "from you.\p"
	.string "I hope that you'll stage a terrific\n"
	.string "battle with our leader!$"
PetalburgCity_Gym_EventScript_205492:: @ 8205492
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_205645
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_2054A1:: @ 82054A1
	msgbox PetalburgCity_Gym_Text_206D56, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_206D56: @ 8206D56
	.string "Since Norman became the Leader,\n"
	.string "the trainers of Petalburg City have\l"
	.string "become a lot tougher.$"



PetalburgCity_Gym_EventScript_2054AA:: @ 82054AA
	trainerbattle_single TRAINER_MARY, PetalburgCity_Gym_Text_206DB2, PetalburgCity_Gym_Text_206E0D, PetalburgCity_Gym_EventScript_2054CE
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_2054DD
	msgbox PetalburgCity_Gym_Text_206E26, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_206DB2: @ 8206DB2
	.string "Giggle…\n"
	.string "This is the {PLACE}Accuracy Room{END}.\p"
	.string "It's pretty nasty when every attack\n"
	.string "lands without fail.$"
PetalburgCity_Gym_Text_206E0D: @ 8206E0D
	.string "You were a cut above me…$"
PetalburgCity_Gym_Text_206E26: @ 8206E26
	.string "There are some even stronger\n"
	.string "trainers waiting for you.\p"
	.string "The left is the {PLACE}Defense Room{END}, and\n"
	.string "the right is the {PLACE}Recovery Room{END}.\p"
	.string "Your Pokémon's attack power will be\n"
	.string "on trial either way.$"
PetalburgCity_Gym_EventScript_2054CE:: @ 82054CE
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_2055A0
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_2054DD:: @ 82054DD
	msgbox PetalburgCity_Gym_Text_206ED8, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_206ED8: @ 8206ED8
	.string "Do you know what we're trying to\n"
	.string "achieve as trainers?\p"
	.string "We're striving to become soul mates\n"
	.string "with our Pokémon.$"



PetalburgCity_Gym_EventScript_2054E6:: @ 82054E6
	trainerbattle_single TRAINER_ALEXIA, PetalburgCity_Gym_Text_206F44, PetalburgCity_Gym_Text_206F82, PetalburgCity_Gym_EventScript_20550A
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205519
	msgbox PetalburgCity_Gym_Text_206F9F, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_206F44: @ 8206F44
	.string "The higher the defense, the more\n"
	.string "reckless I can be in attack.$"
PetalburgCity_Gym_Text_206F82: @ 8206F82
	.string "Our defenses weren't enough…$"
PetalburgCity_Gym_Text_206F9F: @ 8206F9F
	.string "I think you've taught me a valuable\n"
	.string "lesson here.\p"
	.string "Now, go on! The left door goes to\n"
	.string "the {PLACE}Strength Room{END}.\p"
	.string "The right door opens to\n"
	.string "the {PLACE}One-Hit KO Room{END}.\p"
	.string "Both of them have trainers who are\n"
	.string "skilled at offense.$"
PetalburgCity_Gym_EventScript_20550A:: @ 820550A
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_2055E2
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_205519:: @ 8205519
	msgbox PetalburgCity_Gym_Text_207069, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_207069: @ 8207069
	.string "Hi! Have you tried surfing?$"



PetalburgCity_Gym_EventScript_205522:: @ 8205522
	trainerbattle_single TRAINER_JODY, PetalburgCity_Gym_Text_207088, PetalburgCity_Gym_Text_2070E6, PetalburgCity_Gym_EventScript_205546
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, PetalburgCity_Gym_EventScript_205555
	msgbox PetalburgCity_Gym_Text_2070FB, MSGBOX_AUTOCLOSE
	end
PetalburgCity_Gym_Text_207088: @ 8207088
	.string "Our Gym Leader told us to go all out\n"
	.string "and beat every challenger.\p"
	.string "And you're no different!$"
PetalburgCity_Gym_Text_2070E6: @ 82070E6
	.string "But… I went all out!$"
PetalburgCity_Gym_Text_2070FB: @ 82070FB
	.string "The way you use your Pokémon…\n"
	.string "It's an insane style.\p"
	.string "Go on through! The Gym Leader,\n"
	.string "Norman, is waiting!$"
PetalburgCity_Gym_EventScript_205546:: @ 8205546
	setvar VAR_0x8005, 0
	call PetalburgCity_Gym_EventScript_205624
	special DrawWholeMapView
	release
	end
PetalburgCity_Gym_EventScript_205555:: @ 8205555
	msgbox PetalburgCity_Gym_Text_207170, MSGBOX_NPC
	end
PetalburgCity_Gym_Text_207170: @ 8207170
	.string "Sure, it's fine to make your Pokémon\n"
	.string "stronger.\p"
	.string "But what decides the winner?\p"
	.string "Why, it's the feelings trainers have\n"
	.string "for their Pokémon.$"


PetalburgCity_Gym_ClearGymTrainers:: @ 8271FE7
	settrainerflag TRAINER_RANDALL
	settrainerflag TRAINER_PARKER
	settrainerflag TRAINER_GEORGE
	settrainerflag TRAINER_BERKE
	settrainerflag TRAINER_MARY
	settrainerflag TRAINER_ALEXIA
	settrainerflag TRAINER_JODY
	return

@ -----------------------------------------------------


PetalburgCity_Gym_DoSpecial1:: @ 8205746
	special PetalburgGymSpecial1
	waitstate
	return

PetalburgCity_Gym_DoSpecial2:: @ 820574B
	special PetalburgGymSpecial2
	return

PetalburgCity_Gym_EventScript_20555E:: @ 820555E
	setvar VAR_0x8004, 1
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_205666
	return
PetalburgCity_Gym_EventScript_205666:: @ 8205666
	setmetatile 6, 85, 528, 0
	setmetatile 7, 85, 529, 0
	setmetatile 1, 98, 528, 0
	setmetatile 2, 98, 529, 0
	return

PetalburgCity_Gym_EventScript_20557F:: @ 820557F
	setvar VAR_0x8004, 2
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_20568B
	return
PetalburgCity_Gym_EventScript_20568B:: @ 820568B
	setmetatile 6, 46, 528, 0
	setmetatile 7, 46, 529, 0
	setmetatile 1, 59, 528, 0
	setmetatile 2, 59, 529, 0
	return

PetalburgCity_Gym_EventScript_2055A0:: @ 82055A0
	setvar VAR_0x8004, 3
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_2056B0
	return
PetalburgCity_Gym_EventScript_2056B0:: @ 82056B0
	setmetatile 6, 59, 528, 0
	setmetatile 7, 59, 529, 0
	setmetatile 1, 72, 528, 0
	setmetatile 2, 72, 529, 0
	return

PetalburgCity_Gym_EventScript_2055C1:: @ 82055C1
	setvar VAR_0x8004, 4
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_2056D5
	return
PetalburgCity_Gym_EventScript_2056D5:: @ 82056D5
	setmetatile 1, 20, 528, 0
	setmetatile 2, 20, 529, 0
	return

PetalburgCity_Gym_EventScript_2055E2:: @ 82055E2
	setvar VAR_0x8004, 5
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_2056E8
	return
PetalburgCity_Gym_EventScript_2056E8:: @ 82056E8
	setmetatile 6, 20, 528, 0
	setmetatile 7, 20, 529, 0
	setmetatile 1, 33, 528, 0
	setmetatile 2, 33, 529, 0
	return

PetalburgCity_Gym_EventScript_205603:: @ 8205603
	setvar VAR_0x8004, 6
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_20570D
	return
PetalburgCity_Gym_EventScript_20570D:: @ 820570D
	setmetatile 6, 33, 528, 0
	setmetatile 7, 33, 529, 0
	return

PetalburgCity_Gym_EventScript_205624:: @ 8205624
	setvar VAR_0x8004, 7
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_205720
	return
PetalburgCity_Gym_EventScript_205720:: @ 8205720
	setmetatile 1, 7, 528, 0
	setmetatile 2, 7, 529, 0
	return

PetalburgCity_Gym_EventScript_205645:: @ 8205645
	setvar VAR_0x8004, 8
	compare VAR_0x8005, 0
	call_if_eq PetalburgCity_Gym_DoSpecial1
	compare VAR_0x8005, 1
	call_if_eq PetalburgCity_Gym_DoSpecial2
	call PetalburgCity_Gym_EventScript_205733
	return
PetalburgCity_Gym_EventScript_205733:: @ 8205733
	setmetatile 6, 7, 528, 0
	setmetatile 7, 7, 529, 0
	return

@ -----------------------------------------------------
@ Norman:

PetalburgCity_Gym_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN_1, PetalburgCity_Gym_Text_205FE5, PetalburgCity_Gym_Text_206107, PetalburgCity_Gym_EventScript_1FE7C1, NO_MUSIC
	@ specialvar VAR_RESULT, ShouldTryRematchBattle
	@ compare VAR_RESULT, 1
	@ goto_if_eq LavaridgeTown_Gym_1F_EventScript_1FE864
	goto_if_unset FLAG_RECEIVED_TM42, PetalburgCity_Gym_EventScript_GiveTM
	msgbox PetalburgCity_Gym_Text_2062FB, MSGBOX_DEFAULT
	release
	end
PetalburgCity_Gym_Text_205FE5: @ 8205FE5
	.string "Norman: Hm…\n"
	.string "Welcome to the Petalburg City Gym.\l"
	.string "I am Norman.\p"
	.string "I apologize. You are one of the first\n"
	.string "challengers to this gym since it has\l"
	.string "reopened, under my management.\p"
	.string "And for some reason, I was reminded\n"
	.string "inexplicably of my own {PLAYER_son}.\p"
	.string "{PLAYER_They} is still back in Johto, so I'm\n"
	.string "sure you don't know {PLAYER_them}, but {PLAYER_they} has\l"
	.string "the same determination as you.\p"
	.string "Challenger! Are you prepared to take\n"
	.string "me on?!$"
PetalburgCity_Gym_Text_206107: @ 8206107
	.string "…\p"
	.string "I… I can't…\p"
	.string "I can't believe it…\p"
	.string "My very first challenger?\p"
	.string "But, rules are rules!\n"
	.string "Here, take this.$"
PetalburgCity_Gym_Text_2062FB: @ 82062FB
	.string "Norman: My wife and my {PLAYER_son} will be\n"
	.string "moving here in a month or two.\p"
	.string "Clearly, I will need to train harder\n"
	.string "if I want to face them with dignity.$"
PetalburgCity_Gym_EventScript_1FE7C1:
	message PetalburgCity_Gym_Text_206162, MSGTYPE_DESCRIBE
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PetalburgCity_Gym_Text_20618A, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_PETALBURG_GYM
	setflag FLAG_BADGE05_GET
	special PreventDewfordHealSoftlock
	@ call PetalburgCity_Gym_DisableMrBriney
	setflag FLAG_HIDE_MAUVILLE_GYM_WATTSON
	clearflag FLAG_HIDE_MAUVILLE_CITY_WATTSON
	@ setvar VAR_0x8008, 5
	@ call PetalburgCity_Gym_EventScript_271F43 @PetalburgCity_Gym_ClearGymTrainers
	call PetalburgCity_Gym_ClearGymTrainers
	clearflag FLAG_HIDE_DEWFORD_HALL_SLUDGE_BOMB_MAN
	call PetalburgCity_Gym_RunAllGymSpecials
	special DrawWholeMapView
	call PetalburgCity_Gym_EventScript_GiveTM
	closemessage
	delay 30
	msgbox PetalburgCity_Gym_Text_1FF517
	release
	end
PetalburgCity_Gym_Text_206162: @ 8206162
	.string "{PLAYER} received the {ITEM}Balance Badge{END}\n"
	.string "from Norman.$"
PetalburgCity_Gym_Text_20618A: @ 820618A
	.string "Norman: With that badge, the defense\n"
	.string "of all your Pokémon will increase.\p"
	.string "Pokémon that are able to be ridden over\n"
	.string "water will do so at your command.\p"
	.string "This is my gift to you. {PLAYER}, I'm\n"
	.string "sure you can use it correctly.$"
PetalburgCity_Gym_Text_1FF517: @ 81FF517
	.string "Oh, um, I don't have a phone number yet,\n"
	.string "sorry.$"

PetalburgCity_Gym_EventScript_GiveTM:: @ 8204ED2
	giveitem_std ITEM_TM42
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_BagIsFull
	setflag FLAG_RECEIVED_TM42
	msgbox PetalburgCity_Gym_Text_206254, MSGBOX_DEFAULT
	return
PetalburgCity_Gym_Text_206254: @ 8206254
	.string "Norman: TM42 contains Facade.\p"
	.string "It doubles the power of moves if\n"
	.string "the Pokémon is poisoned, paralyzed\l"
	.string "or burned.\p"
	.string "It might be able to turn a bad\n"
	.string "situation into an advantage.$"

@ -----------------------------------------------------

#undef LID_NORMAN
#undef LID_LOGAN
#undef LID_OLDLEADER
