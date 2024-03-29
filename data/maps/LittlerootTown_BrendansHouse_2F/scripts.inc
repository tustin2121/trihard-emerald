LittlerootTown_BrendansHouse_2F_MapScripts:: @ 81F83E3
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_MapScript1_1F83EE
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_2F_MapScript2_1F846A
	.byte 0

@ -----------------------------------------------------

LittlerootTown_BrendansHouse_2F_MapScript1_1F83EE: @ 81F83EE
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	call_if_lt LittlerootTown_BrendansHouse_2F_EventScript_1F8457
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	call_if_ge LittlerootTown_BrendansHouse_2F_EventScript_1F841A
	compare VAR_LITTLEROOT_INTRO_STATE, 4
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_2926FE
	call LittlerootTown_BrendansHouse_2F_EventScript_275CE1
	@ setvar VAR_SECRET_BASE_INITIALIZED, 0
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F841A:: @ 81F841A
	goto_if_set FLAG_MET_RIVAL_LILYCOVE, LittlerootTown_BrendansHouse_2F_EventScript_1F8433
	compare VAR_BIRCH_LAB_STATE, 2
	goto_if_ge LittlerootTown_BrendansHouse_2F_EventScript_1F8456
	goto LittlerootTown_BrendansHouse_2F_EventScript_1F8433

LittlerootTown_BrendansHouse_2F_EventScript_1F8433:: @ 81F8433
	checkplayergender
	compare VAR_RESULT, 0
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8456
	compare VAR_0x40D3, 2
	goto_if_ge LittlerootTown_BrendansHouse_2F_EventScript_1F9309
	setobjectxyperm 1, 0, 2
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8456:: @ 81F8456
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8457:: @ 81F8457
	checkplayergender
	compare VAR_RESULT, 1
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8464
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8464:: @ 81F8464
	setvar VAR_LITTLEROOT_RIVAL_STATE, 2
	return

@ -----------------------------------------------------

LittlerootTown_BrendansHouse_2F_MapScript2_1F846A: @ 81F846A
	@ map_script_2 VAR_SECRET_BASE_INITIALIZED, 0, LittlerootTown_BrendansHouse_2F_EventScript_1F8474
	.2byte 0

@ LittlerootTown_BrendansHouse_2F_EventScript_1F8474:: @ 81F8474
@ 	checkplayergender
@ 	compare VAR_RESULT, 0
@ 	goto_if_eq EventScript_275D0C
@ 	end

@ -----------------------------------------------------

LittlerootTown_BrendansHouse_2F_EventScript_1F8481:: @ 81F8481
	lockall
	compare VAR_LITTLEROOT_RIVAL_STATE, 2
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8497
	msgbox LittlerootTown_RivalsHouse_2F_Text_1F9962, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F8497:: @ 81F8497
	flagasdialog
	delay 10
	addobject 1
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85BC
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 1, Common_Movement_Delay48
	waitmovement 0
	delay 10
	playbgm MUS_BOY_SUP, 1
	compare VAR_FACING, 2
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8507
	compare VAR_FACING, 1
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8536
	compare VAR_FACING, 3
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8565
	compare VAR_FACING, 4
	call_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8594
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	setvar VAR_0x4050, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F8507:: @ 81F8507
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85C0
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_RivalHouse_1F_Text_1F8EC6, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_1F85CF
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85C6
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8536:: @ 81F8536
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85D7
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_RivalHouse_1F_Text_1F8EC6, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_1F85E2
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85DB
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8565:: @ 81F8565
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85E8
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LittlerootTown_RivalHouse_1F_Text_1F8EC6, MSGBOX_DEFAULT
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_BrendansHouse_2F_Movement_1F85F6
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85ED
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_EventScript_1F8594:: @ 81F8594
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F85FD
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LittlerootTown_RivalHouse_1F_Text_1F8EC6, MSGBOX_DEFAULT
	closemessage
	applymovement 1, LittlerootTown_BrendansHouse_2F_Movement_1F8604
	waitmovement 0
	return

LittlerootTown_BrendansHouse_2F_Movement_1F85BC: @ 81F85BC
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85C0: @ 81F85C0
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85C6: @ 81F85C6
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85CF: @ 81F85CF
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85D7: @ 81F85D7
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85DB: @ 81F85DB
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85E2: @ 81F85E2
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85E8: @ 81F85E8
	walk_left
	walk_left
	walk_down
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85ED: @ 81F85ED
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85F6: @ 81F85F6
	delay_8
	delay_16
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F85FD: @ 81F85FD
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F8604: @ 81F8604
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_up
	step_end

LittlerootTown_BrendansHouse_2F_Movement_1F8609: @ 81F8609
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

EventScript_PlayerPCMale:: @ 81F860D
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F8626
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_BrendansHouse_2F_EventScript_1F864C
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F8626:: @ 81F8626
	msgbox Text_PCLivestreamEvent, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F863F:: @ 81F863F
	setvar VAR_0x8004, 1
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_1F864C:: @ 81F864C
	msgbox gUnknown_08272CD5, MSGBOX_DEFAULT
	releaseall
	end

@ -----------------------------------------------------
@ Trigger: Sleeping in bed

LittlerootTown_BrendansHouse_2F_TriggerScript_SleepInBed::
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LittlerootTown_PlayersHouse_2F_TriggerScript_SleepInBed
	release
	end

@ -----------------------------------------------------

LittlerootTown_BrendansHouse_2F_EventScript_1F8656:: @ 81F8656
LittlerootTown_MaysHouse_2F_EventScript_1F8656:: @ 81F8656
	msgbox LittlerootTown_PlayersHouse_2F_Text_1F877F, MSGBOX_DESCRIBE
	end
LittlerootTown_PlayersHouse_2F_Text_1F877F: @ 81F877F
	.string "{PLAYER} flipped open the notebook.\p"
	.string "{TIPS}TRIHARD ADVENTURE RULES{END}\p"
	.string "{NO} 1: Rest at a Pokémon Center,\n"
	.string "at home, or a heal house to SAVE!\p"
	.string "{NO} 2: If you white out or forfeit,\n"
	.string "the game will RESET without saving!\p"
	.string "{NO} 3: Fainting means DEATH!\n"
	.string "Don't let your Pokémon faint!\p"
	.string "The remaining pages are blank…$"

LittlerootTown_BrendansHouse_2F_EventScript_1F865F:: @ 81F865F
LittlerootTown_MaysHouse_2F_EventScript_1F865F:: @ 81F865F
	msgbox LittlerootTown_PlayersHouse_2F_Text_1F884F, MSGBOX_DESCRIBE
	end
LittlerootTown_PlayersHouse_2F_Text_1F884F: @ 81F884F
	.string "It's a Nintendo GameCube.\p"
	.string "A Game Boy Advance is connected to\n"
	.string "serve as the Controller.$"


