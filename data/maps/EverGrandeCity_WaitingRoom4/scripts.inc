EverGrandeCity_WaitingRoom4_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_WaitingRoom4_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_WaitingRoom4_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom4_OnLoad:
	setflag FLAG_DISABLE_FADE_INIT
	overridemapname EverGrandeCity_WaitingRoom4_MapName
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
	.string "Reporter: (Placeholder).$"
EverGrandeCity_WaitingRoom4_SignScript_TVs2:
	bufferpartymonnick 0, 0
	msgbox EverGrandeCity_WaitingRoom4_Text_TVs2, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom4_Text_TVs2:
	.string "with a red marker to help illustrate.$"

@ -----------------------------------------------------
@ People

EverGrandeCity_WaitingRoom4_EventScript_Logan::
	goto_if_set FLAG_TEMP_1, EverGrandeCity_WaitingRoom4_EventScript_Logan2
	msgbox EverGrandeCity_WaitingRoom4_Text_Logan, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceDown
	waitmovement 0
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
	.string "Shoo!"

