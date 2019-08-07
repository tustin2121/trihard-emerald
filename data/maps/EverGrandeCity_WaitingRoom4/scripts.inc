EverGrandeCity_WaitingRoom4_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_WaitingRoom4_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_WaitingRoom4_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom4_OnLoad:
	setflag FLAG_DISABLE_FADE_INIT
	overridemapname EverGrandeCity_WaitingRoom4_MapName
	setmetatileex 1, 1, 0x222, 3, TRUE
	setmetatileex 1, 2, 0x05E, 3, FALSE
	setmetatileex 2, 2, 0x355, 3, FALSE
	setmetatileex 2, 3, 0x35D, 3, TRUE
	end
EverGrandeCity_WaitingRoom4_MapName:
	.string "Day 4$"

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom4_FrameTable:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_WaitingRoom4_SlowFade
	.2byte 0

EverGrandeCity_WaitingRoom4_SlowFade:
	setvar VAR_TEMP_0, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	advancetime 23, 30, 35
	callnative ShowMapNamePopup
	delay 80
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 6
	end

@ -----------------------------------------------------
@ TV Screens

EverGrandeCity_WaitingRoom4_SignScript_TVs::
	goto_if_set FLAG_TEMP_2, EverGrandeCity_WaitingRoom4_SignScript_TVs2
	msgbox EverGrandeCity_WaitingRoom4_Text_TVs, MSGBOX_DIALOG
	setflag FLAG_TEMP_2
	end
EverGrandeCity_WaitingRoom4_Text_TVs:
	.string "Reporter: Welcome to day four, folks!\p"
	.string "There's only FIVE competitors left!\p"
	.string "Today, we'll see if any of our\n"
	.string "challengers make it to the Champion!\p"
	.string "Remember two years ago, when all of our\n"
	.string "challengers failed to reach the Champ?\p"
	.string "Well, it's looking promising this year,\n"
	.string "folks! And leading the pack, we have\l"
	.string "the “Lightning from Littleroot”, {PLAYER}!\p"
	.string "{PLAYER_They}'ll be facing off against\n"
	.string "Drake this morning!$"
EverGrandeCity_WaitingRoom4_SignScript_TVs2:
	msgbox EverGrandeCity_WaitingRoom4_Text_TVs2, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom4_Text_TVs2:
	.string "They're talking potential strategies\n"
	.string "for winning against Drake.$"

@ -----------------------------------------------------
@ People

EverGrandeCity_WaitingRoom4_EventScript_Logan::
	goto_if_set FLAG_TEMP_1, EverGrandeCity_WaitingRoom4_EventScript_Logan2
	msgbox EverGrandeCity_WaitingRoom4_Text_Logan, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceDown
	waitmovement 0
	incrementgamestat GAME_STAT_NUM_NPCS_HARRASSED
	setflag FLAG_TEMP_1
	end
EverGrandeCity_WaitingRoom4_Text_Logan:
	.string "Go away, {PLAYER}!\p"
	.string "I'm too nervous to talk right now! And\n"
	.string "I don't need you making me more nervous!$"
EverGrandeCity_WaitingRoom4_EventScript_Logan2:
	msgbox EverGrandeCity_WaitingRoom4_Text_Logan2, MSGBOX_DIALOG
	end
EverGrandeCity_WaitingRoom4_Text_Logan2:
	.string "Shoo!$"


EverGrandeCity_WaitingRoom4_EventScript_Person1::
	lock
	faceplayer
	msgbox EverGrandeCity_WaitingRoom4_Text_Person1, MSGBOX_CDESCRIBE
	release
	end
EverGrandeCity_WaitingRoom4_Text_Person1::
	.string "The boy gives you a slight, silent nod.$"


EverGrandeCity_WaitingRoom4_EventScript_Person2::
	msgbox EverGrandeCity_WaitingRoom4_Text_Person2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom4_Text_Person2::
	.string "Her incessent pacing… Ugh!\p"
	.string "It made it impossible for me to continue\n"
	.string "to sit in my lucky corner.$"

