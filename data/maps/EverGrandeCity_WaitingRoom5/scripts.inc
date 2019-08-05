EverGrandeCity_WaitingRoom5_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_WaitingRoom5_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_WaitingRoom5_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom5_OnLoad:
	setflag FLAG_DISABLE_FADE_INIT
	overridemapname EverGrandeCity_WaitingRoom5_MapName
	end
EverGrandeCity_WaitingRoom5_MapName:
	.string "Day 5$"

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom5_FrameTable:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_WaitingRoom5_SlowFade
	.2byte 0

EverGrandeCity_WaitingRoom5_SlowFade:
	setvar VAR_TEMP_0, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	callnative AdvanceTimeToNextMorning
	advancetime 0, 5, 5
	callnative ShowMapNamePopup
	delay 80
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 6
	end

@ -----------------------------------------------------
@ TV Screens

EverGrandeCity_WaitingRoom5_SignScript_TVs::
	goto_if_set FLAG_TEMP_2, EverGrandeCity_WaitingRoom5_SignScript_TVs2
	msgbox EverGrandeCity_WaitingRoom5_Text_TVs, MSGBOX_DIALOG
	setflag FLAG_TEMP_2
	end
EverGrandeCity_WaitingRoom5_Text_TVs:
	.string "Reporter: (Placeholder).$"
EverGrandeCity_WaitingRoom5_SignScript_TVs2:
	bufferpartymonnick 0, 0
	msgbox EverGrandeCity_WaitingRoom5_Text_TVs2, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom5_Text_TVs2:
	.string "with a red marker to help illustrate.$"

@ -----------------------------------------------------
@ People: None

