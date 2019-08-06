EverGrandeCity_DrakesRoom_MapScripts:: @ 822869C
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_DrakesRoom_MapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_DrakesRoom_OnLoad: @ 82286D2
	call_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_E4Room_SetRoomPostBattle
	compare VAR_ELITE_4_STATE, 4
	call_if_eq EverGrandeCity_E4Room_SetRoomClosedDoorBehind
	end

@ -----------------------------------------------------

EverGrandeCity_DrakesRoom_MapTable: @ 82286AC
	map_script_2 VAR_TEMP_1, 0, Common_EventScript_FacePlayerUp
	.2byte 0

@ -----------------------------------------------------

EverGrandeCity_DrakesRoom_FrameTable: @ 82286BB
	map_script_2 VAR_ELITE_4_STATE, 3, EverGrandeCity_DrakesRoom_EventScript_2286C5
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_2286C5:: @ 82286C5
	lockall
	call EverGrandeCity_E4Room_WalkUpAndCloseDoorBehind
	setvar VAR_ELITE_4_STATE, 4
	releaseall
	end

@ -----------------------------------------------------

EverGrandeCity_DrakesRoom_EventScript_2286F3:: @ 82286F3
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_DrakesRoom_EventScript_22871A
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_DrakesRoom_Text_22873E, MSGBOX_CDIALOG
	setflag FLAG_DEATH_PREVENT
	trainerbattle_no_intro TRAINER_DRAKE, EverGrandeCity_DrakesRoom_Text_228895
	goto EverGrandeCity_DrakesRoom_EventScript_228724
	end
EverGrandeCity_DrakesRoom_Text_22873E: @ 822873E
	.string "I am the last of the Pokémon League\n"
	.string "Elite Four, Drake the Dragon master!\p"
	.string "In their natural state, Pokémon are\n"
	.string "wild living things. They are free.\p"
	.string "At times, they hinder us.\n"
	.string "At times, they help us.\p"
	.string "For us to battle with Pokémon as\n"
	.string "partners, do you know what it takes?\p"
	.string "Do you know what is needed?\p"
	.string "If you don't, then you will never\n"
	.string "prevail over me!$"
EverGrandeCity_DrakesRoom_Text_228895: @ 8228895
	.string "Superb, it should be said.$"
EverGrandeCity_DrakesRoom_EventScript_22871A:: @ 822871A
	msgbox EverGrandeCity_DrakesRoom_Text_2288B0, MSGBOX_CDIALOG
	release
	end
EverGrandeCity_DrakesRoom_EventScript_228724:: @ 8228724
	setvar VAR_0x8004, 0
	special sub_813BF7C
	setflag FLAG_DEFEATED_ELITE_4_DRAKE
	call EverGrandeCity_DrakesRoom_EventScript_2723F8
	msgbox EverGrandeCity_DrakesRoom_Text_2288B0, MSGBOX_CDIALOG
	release
	end
EverGrandeCity_DrakesRoom_Text_2288B0: @ 82288B0
	.string "You deserve every credit for coming\n"
	.string "this far as a trainer of Pokémon.\p"
	.string "You do seem to know what is needed.\p"
	.string "Yes, what a trainer needs is a\n"
	.string "virtuous heart.\p"
	.string "Pokémon touch the good hearts of\n"
	.string "trainers and learn good from wrong.\p"
	.string "They touch the good hearts of\n"
	.string "trainers and grow strong.\p"
	.string "Go! Go onwards!\n"
	.string "The Champion will be waiting!$"

