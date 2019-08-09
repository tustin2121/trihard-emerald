RusturfTunnel_MapScripts:: @ 822CE27
	map_script MAP_SCRIPT_ON_TRANSITION, RusturfTunnel_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RusturfTunnel_MapScript2_FrameTable
	.byte 0

@ -----------------------------------------------------

RusturfTunnel_OnTransition: @ 822CE44
	compare VAR_RUSTURF_TUNNEL_STATE, 2
	call_if_eq RusturfTunnel_EventScript_22CE50
	end
RusturfTunnel_EventScript_22CE50:: @ 822CE50
	setobjectxyperm 7, 13, 4
	setobjectxyperm 6, 13, 5
	return

@ -----------------------------------------------------
@ Scene: Braking the Rock Between Them

#define LID_RUST_MAN 1
#define LID_TURF_MAN 10

RusturfTunnel_MapScript2_FrameTable: @ 822CE32
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 4, RusturfTunnel_EventScript_RockSmashReact
	map_script_2 VAR_RUSTURF_TUNNEL_STATE, 5, RusturfTunnel_EventScript_RockSmashReact
	.2byte 0

RusturfTunnel_EventScript_RockSmashReact:: @ 822CEAE
	lockall
	markasdialog
	selectpointer RusturfTunnel_ScriptTable_RockSmashReact_Step1, VAR_TEMP_1
	call 0
	call RusturfTunnel_EventScript_RockSmashReact_Step2
	msgbox RusturfTunnel_Text_RockSmashReact_Step3, MSGBOX_DIALOG
	selectpointer RusturfTunnel_ScriptTable_RockSmashReact_Step4, VAR_TEMP_1
	call 0
	giveitem_std ITEM_TM54
	setflag FLAG_RECEIVED_TM54
	msgbox RusturfTunnel_Text_RockSmashReact_Step5, MSGBOX_DEFAULT
	closemessage
	selectpointer RusturfTunnel_ScriptTable_RockSmashReact_Step6, VAR_TEMP_1
	call 0
	msgbox RusturfTunnel_Text_RockSmashReact_Step7, MSGBOX_DEFAULT
	closemessage
	selectpointer RusturfTunnel_ScriptTable_RockSmashReact_Step8, VAR_TEMP_1
	call 0
	call RusturfTunnel_EventScript_RockSmashReact_Step9
	releaseall
	end

.align 2
RusturfTunnel_ScriptTable_RockSmashReact_Step1:
	.4byte Common_EventScript_NopReturn
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step1a
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step1b
	.4byte Common_EventScript_NopReturn
	.4byte 0
RusturfTunnel_ScriptTable_RockSmashReact_Step4:
	.4byte Common_EventScript_NopReturn
	.4byte Common_EventScript_NopReturn
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step4
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step4
	.4byte 0
RusturfTunnel_ScriptTable_RockSmashReact_Step6:
	.4byte Common_EventScript_NopReturn
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step6a
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step6b
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step6c
	.4byte 0
RusturfTunnel_ScriptTable_RockSmashReact_Step8:
	.4byte Common_EventScript_NopReturn
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step8a
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step8b
	.4byte RusturfTunnel_EventScript_RockSmashReact_Step8b
	.4byte 0

RusturfTunnel_EventScript_RockSmashReact_Step1a:: @ 822CFA7
	applymovement LID_RUST_MAN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return
RusturfTunnel_EventScript_RockSmashReact_Step1b:: @ 822CFBC
	applymovement LID_RUST_MAN, RusturfTunnel_Movement_22D048
	waitmovement 0
	return
RusturfTunnel_Movement_22D048: @ 822D048
	walk_up
	walk_in_place_fastest_right
	step_end

RusturfTunnel_EventScript_RockSmashReact_Step2:: @ 822CFFF
	playse SE_PIN
	applymovement LID_RUST_MAN, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	return
RusturfTunnel_Text_RockSmashReact_Step3: @ 822D65C
	.string "Wow! You shattered that boulder\n"
	.string "blocking the way.\p"
	.string "To show you how much I appreciate it,\n"
	.string "I'd like you to have this TM.$"
RusturfTunnel_EventScript_RockSmashReact_Step4:: @ 822CFC8
	closemessage
	applymovement LID_RUST_MAN, Common_Movement_WalkRight1
	waitmovement 0
	return
RusturfTunnel_Text_RockSmashReact_Step5: @ 822D6D2
	.string "That TM contains Strength.\p"
	.string "If a muscular Pokémon were to learn\n"
	.string "that, it would be able to move even\l"
	.string "large boulders.$"
RusturfTunnel_EventScript_RockSmashReact_Step6a:: @ 822CF5D
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D042
	applymovement LID_RUST_MAN, RusturfTunnel_Movement_22D067
	waitmovement 0
	return
RusturfTunnel_Movement_22D042: @ 822D042
	walk_left
	walk_in_place_fastest_right
	step_end
RusturfTunnel_Movement_22D067: @ 822D067
	walk_in_place_fast_up
	walk_in_place_fast_up
	walk_fast_up
	walk_fast_right
	step_end
RusturfTunnel_EventScript_RockSmashReact_Step6b:: @ 822CF6F
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D045
	applymovement LID_RUST_MAN, RusturfTunnel_Movement_22D06C
	waitmovement 0
	applymovement LID_TURF_MAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return
RusturfTunnel_EventScript_RockSmashReact_Step6c:: @ 822CF8B
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D045
	applymovement LID_RUST_MAN, RusturfTunnel_Movement_22D06C
	waitmovement 0
	applymovement LID_TURF_MAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return
RusturfTunnel_Movement_22D045: @ 822D045
	walk_right
	walk_in_place_fastest_left
	step_end
RusturfTunnel_Movement_22D06C: @ 822D06C
	walk_in_place_fast_right
	walk_in_place_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	step_end

RusturfTunnel_Text_RockSmashReact_Step7: @ 822D745
	.string "Carver!\n"
	.string "Now I can see you anytime!\p"
	.string "Carver: Yes! Finally!\p"
	.string "Let's go back to my place, big boy.$"
RusturfTunnel_EventScript_RockSmashReact_Step8a:: @ 822CFD4
	applymovement LID_TURF_MAN, RusturfTunnel_Movement_22D017
	applymovement LID_RUST_MAN, RusturfTunnel_Movement_22D04B
	waitmovement 0
	return
RusturfTunnel_EventScript_RockSmashReact_Step8b:: @ 822CFE6
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D02F
	applymovement LID_TURF_MAN, RusturfTunnel_Movement_22D017
	applymovement LID_RUST_MAN, RusturfTunnel_Movement_22D058
	waitmovement 0
	return
RusturfTunnel_Movement_22D02F: @ 822D02F
	delay_8
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end
RusturfTunnel_Movement_22D017: @ 822D017
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
RusturfTunnel_Movement_22D04B: @ 822D04B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
RusturfTunnel_Movement_22D058: @ 822D058
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
RusturfTunnel_EventScript_RockSmashReact_Step9:: @ 8272216
	removeobject LID_RUST_MAN
	removeobject LID_TURF_MAN
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_MAN
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_LOVER_WOMAN
	setvar VAR_RUSTURF_TUNNEL_STATE, 6
	setflag FLAG_RUSTURF_TUNNEL_OPENED
	return


RusturfTunnel_EventScript_22D071:: @ 822D071
	setvar VAR_TEMP_1, 1
	end
RusturfTunnel_EventScript_22D077:: @ 822D077
	setvar VAR_TEMP_1, 2
	end
RusturfTunnel_EventScript_22D07D:: @ 822D07D
	setvar VAR_TEMP_1, 3
	end

#undef LID_RUST_MAN
#undef LID_TURF_MAN

@ -----------------------------------------------------
@ People

RusturfTunnel_EventScript_TurfMan:: @ 822CE5F
	lock
	faceplayer
	markasdialog
	msgbox RusturfTunnel_Text_22D7A3, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	release
	end
RusturfTunnel_Text_22D7A3: @ 822D7A3
	.string "On the other side of this rock…\n"
	.string "My boyfriend is there.\p"
	.string "He… He's not just digging the tunnel\n"
	.string "to come see me.\p"
	.string "He works his hands raw and rough\n"
	.string "for the benefit of everyone.$"


RusturfTunnel_EventScript_RustMan:: @ 822CE76
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_TEMP_1, RusturfTunnel_EventScript_22CE99
	setflag FLAG_TEMP_1
	msgbox RusturfTunnel_Text_22D510, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	release
	end
RusturfTunnel_Text_22D510: @ 822D510
	.string "… …\p"
	.string "Why can't they keep digging?\n"
	.string "Is the bedrock too hard?\p"
	.string "My beloved awaits me in Verdanturf\n"
	.string "Town just beyond here…\p"
	.string "If Rustboro and Verdanturf were\n"
	.string "joined by this tunnel, I could visit\l"
	.string "him every day…\p"
	.string "But this…\n"
	.string "What am I to do?$"
RusturfTunnel_EventScript_22CE99:: @ 822CE99
	msgbox RusturfTunnel_Text_22D5F3, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	release
	end
RusturfTunnel_Text_22D5F3: @ 822D5F3
	.string "To get from Rustboro to Verdanturf,\n"
	.string "you need to go to Dewford, then pass\l"
	.string "through Slateport and Mauville…$"

@ -----------------------------------------------------
@ Scene: Kidnapping!

#define LID_BRINEY 5
#define LID_GRUNT 6
#define LID_PEEKO 7

RusturfTunnel_TriggerScript_ApproachGrunt:: @ 822D083
	lockall
	msgbox RusturfTunnel_Text_22D1C8, MSGBOX_DIALOG
	closemessage
	applymovement LID_GRUNT, RusturfTunnel_Movement_22D0AB
	applymovement LID_PEEKO, RusturfTunnel_Movement_22D0AB
	waitmovement 0
	moveobjectoffscreen LID_GRUNT
	moveobjectoffscreen LID_PEEKO
	setvar VAR_RUSTURF_TUNNEL_STATE, 3
	releaseall
	end
RusturfTunnel_Text_22D1C8: @ 822D1C8
	.string "What, are you coming?\n"
	.string "Come and get some, then!$"
RusturfTunnel_Movement_22D0AB: @ 822D0AB
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end


RusturfTunnel_EventScript_Peeko:: @ 822D0AF
	lock
	faceplayer
	waitse
	playmoncry SPECIES_WINGULL, 0
	msgbox RusturfTunnel_Text_22D1F7, MSGBOX_DIALOG
	waitmoncry
	release
	end
RusturfTunnel_Text_22D1F7: @ 822D1F7
	.string "Peeko: Pii pihyoh!$"


RusturfTunnel_EventScript_Grunt:: @ 822D0C2
	lock
	faceplayer
	markasdialog
	playbgm MUS_AQA_0, 0
	msgbox RusturfTunnel_Text_22D20A
	@ Battle!
	trainerbattle_no_intro TRAINER_GRUNT_10, RusturfTunnel_Text_22D2B0
	msgbox RusturfTunnel_Text_22D2E1
	giveitem_std ITEM_DEVON_GOODS
	closemessage
	@ Grunt runs off
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D178
	applymovement LID_GRUNT, RusturfTunnel_Movement_22D181
	waitmovement 0
	removeobject LID_GRUNT
	delay 50
	@ Briney approaches
	addobject LID_BRINEY
	applymovement LID_BRINEY, RusturfTunnel_Movement_22D18B
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D17E
	applymovement LID_BRINEY, RusturfTunnel_Movement_22D1A4
	waitmovement 0
	msgbox RusturfTunnel_Text_22D395
	applymovement LID_BRINEY, Common_Movement_FacePlayer
	waitmovement 0
	message RusturfTunnel_Text_22D3BA
	waitmessage
	waitse
	playmoncry SPECIES_WINGULL, 0
	waitbuttonpress
	waitmoncry
	closemessage
	@ Leaves
	applymovement EVENT_OBJ_ID_PLAYER, RusturfTunnel_Movement_22D19F
	applymovement LID_BRINEY, RusturfTunnel_Movement_22D193
	applymovement LID_PEEKO, RusturfTunnel_Movement_22D1A7
	waitmovement 0
	@ Clean up
	removeobject LID_BRINEY
	removeobject LID_PEEKO
	clearflag FLAG_DEVON_GOODS_STOLEN
	setflag FLAG_RECOVERED_DEVON_GOODS
	setvar VAR_RUSTBORO_STATE, 4
	setvar VAR_BRINEY_HOUSE_STATE, 1
	setflag FLAG_HIDE_ROUTE_116_MR_BRINEY
	release
	end
RusturfTunnel_Text_22D20A: @ 822D20A
	.string "Grah, torch it all!\p"
	.string "That hostage Pokémon turned out to\n"
	.string "be worthless!\p"
	.string "And to think I made a getaway…\n"
	.string "In this tunnel to nowhere!\p"
	.string "Hey! You! In the gang colors!\n"
	.string "So you want to battle me?$"
RusturfTunnel_Text_22D2B0: @ 822D2B0
	.string "Urrrggh! My career in crime comes to\n"
	.string "a dead end!$"
RusturfTunnel_Text_22D2E1: @ 822D2E1
	.string "This is plain not right…\p"
	.string "The boss told me this would be a\n"
	.string "slick-and-easy job to pull.\p"
	.string "All I had to do was steal some package\n"
	.string "from Devon.\p"
	.string "Then those jerks from Aqua show up\n"
	.string "and ruin our plans!\p"
	.string "Tch!\n"
	.string "You want it back that badly, take it!$"

RusturfTunnel_Movement_22D178: @ 822D178
	face_down
	lock_facing_direction
	walk_up
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end
RusturfTunnel_Movement_22D181: @ 822D181
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

RusturfTunnel_Movement_22D18B: @ 822D18B
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
RusturfTunnel_Movement_22D17E: @ 822D17E
	walk_down
	walk_in_place_fastest_up
	step_end
RusturfTunnel_Movement_22D1A4: @ 822D1A4
	delay_16
	walk_right
	step_end

RusturfTunnel_Text_22D395: @ 822D395
	.string "Peeko!\n"
	.string "Am I glad to see you're safe!$"
RusturfTunnel_Text_22D3BA: @ 822D3BA
	.string "Peeko owes her life to you!\p"
	.string "They call me Mr. Briney.\n"
	.string "And, you are?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Ah, so you are {PLAYER}!\n"
	.string "I sincerely thank you!\p"
	.string "Now, if there's anything that troubles\n"
	.string "you, don't hesitate to tell me!\p"
	.string "You can usually find me in my cottage\n"
	.string "by the sea near Petalburg Woods.\p"
	.string "Come, Peeko, we should make our way\n"
	.string "home.\p"
	.string "Peeko: Pihyoh!$"

RusturfTunnel_Movement_22D19F: @ 822D19F
	delay_16
	delay_8
	delay_4
	walk_in_place_fastest_left
	step_end
RusturfTunnel_Movement_22D193: @ 822D193
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
RusturfTunnel_Movement_22D1A7: @ 822D1A7
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

#undef LID_BRINEY
#undef LID_GRUNT
#undef LID_PEEKO

@ -----------------------------------------------------


RusturfTunnel_EventScript_22D1B1:: @ 822D1B1
	trainerbattle_single TRAINER_MIKE_2, RusturfTunnel_Text_22D84D, RusturfTunnel_Text_22D8DB
	msgbox RusturfTunnel_Text_22D8F9, MSGBOX_AUTOCLOSE
	end
RusturfTunnel_Text_22D84D: @ 822D84D
	.string "What do you call a wild man up in the\n"
	.string "mountains? A mountain man, right?\p"
	.string "So why don't they call a Pokémon in\n"
	.string "the mountains a mountain Pokémon?$"
RusturfTunnel_Text_22D8DB: @ 822D8DB
	.string "My Pokémon…\n"
	.string "Ran out of power…$"
RusturfTunnel_Text_22D8F9: @ 822D8F9
	.string "They halted development here to\n"
	.string "protect Pokémon, right?\l"
	.string "There's a feel-good story!$"

