EverGrandeCity_SidneysRoom_MapScripts:: @ 8227F01
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_SidneysRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_MapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_SidneysRoom_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_SidneysRoom_OnLoad: @ 8227F1D
	call_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_E4Room_SetRoomPostBattle
	compare VAR_ELITE_4_STATE, 1
	call_if_eq EverGrandeCity_E4Room_SetRoomClosedDoorBehind
	end

@ -----------------------------------------------------

EverGrandeCity_SidneysRoom_MapTable: @ 8227F3E
	map_script_2 VAR_TEMP_1, 0, Common_EventScript_FacePlayerUp
	.2byte 0

@ -----------------------------------------------------

EverGrandeCity_SidneysRoom_FrameTable: @ 8227F4D
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_SidneysRoom_EventScript_227F57
	.2byte 0

EverGrandeCity_SidneysRoom_EventScript_227F57:: @ 8227F57
	lockall
	call EverGrandeCity_E4Room_WalkUpAndCloseDoorBehind
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

@ -----------------------------------------------------

EverGrandeCity_SidneysRoom_EventScript_227F64:: @ 8227F64
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_SidneysRoom_EventScript_227F8B
	playbgm MUS_SITENNOU, 0
	msgbox EverGrandeCity_SidneysRoom_Text_227FA7, MSGBOX_CDIALOG
	setflag FLAG_DEATH_PREVENT
	trainerbattle_no_intro TRAINER_SIDNEY, EverGrandeCity_SidneysRoom_Text_2280A2
	goto EverGrandeCity_SidneysRoom_EventScript_227F95
	end
EverGrandeCity_SidneysRoom_Text_227FA7: @ 8227FA7
	.string "Welcome, challenger!\n"
	.string "I'm Sidney of the Elite Four.\p"
	.string "I like that look you're giving me.\n"
	.string "I guess you'll give me a good match.\l"
	.string "That's good! Looking real good!\p"
	.string "All right! You and me, let's enjoy\n"
	.string "a battle that can only be staged\l"
	.string "here in the Pokémon League!$"
EverGrandeCity_SidneysRoom_Text_2280A2: @ 82280A2
	.string "Well, how do you like that? I lost!\n"
	.string "Eh, it was fun, so it doesn't matter.$"
EverGrandeCity_SidneysRoom_EventScript_227F8B:: @ 8227F8B
	msgbox EverGrandeCity_SidneysRoom_Text_2280EC, MSGBOX_CDIALOG
	release
	end
EverGrandeCity_SidneysRoom_EventScript_227F95:: @ 8227F95
	setflag FLAG_DEFEATED_ELITE_4_SIDNEY
	call EverGrandeCity_E4Room_UnlockNextDoorTurnOffLights
	msgbox EverGrandeCity_SidneysRoom_Text_2280EC, MSGBOX_CDIALOG
	release
	end
EverGrandeCity_SidneysRoom_Text_2280EC: @ 82280EC
	.string "Well, listen to what this loser has\n"
	.string "to say.\p"
	.string "You've got what it takes to go far.\n"
	.string "Now, head on through the door behind me\l"
	.string "and prepare for your next battle!$"

