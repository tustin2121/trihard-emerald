EverGrandeCity_WaitingRoom1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_WaitingRoom1_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_WaitingRoom1_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_WaitingRoom1_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom1_OnLoad:
	setflag FLAG_DISABLE_FADE_INIT
	overridemapname EverGrandeCity_WaitingRoom1_MapName
	end
EverGrandeCity_WaitingRoom1_MapName:
	.string "Day 1$"

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom1_FrameTable:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_WaitingRoom1_SlowFade
	.2byte 0

EverGrandeCity_WaitingRoom1_SlowFade:
	setvar VAR_TEMP_0, 1
	incrementgamestat GAME_STAT_NUM_E4_ATTEMPTS
	callnative AdvanceTimeToNextMondayMorning
	call Common_EventScript_ClearSceneFlags
	advancetime 4, 10, 35
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	delay 50
	callnative ShowMapNamePopup
	delay 80
	call EverGrandeCity_WaitingRoom1_CreateVirtualObjects
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 6
	end

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom1_OnResume:
	compare VAR_TEMP_0, 1
	call_if_eq EverGrandeCity_WaitingRoom1_CreateVirtualObjects
	end
EverGrandeCity_WaitingRoom1_CreateVirtualObjects:
	createvobject EVENT_OBJ_GFX_YOUNGSTER,     50, 10, 3,  3, DIR_WEST
	setmetatile                                    10, 3, -1, TRUE
	createvobject EVENT_OBJ_GFX_BLACK_BELT,    51, 10, 5,  3, DIR_WEST
	setmetatile                                    10, 5, -1, TRUE
	createvobject EVENT_OBJ_GFX_GENTLEMAN,     52, 10, 8,  3, DIR_WEST
	setmetatile                                    10, 8, -1, TRUE
	createvobject EVENT_OBJ_GFX_BUG_CATCHER,   53,  0, 7,  3, DIR_EAST
	setmetatile                                     0, 7, -1, TRUE
	createvobject EVENT_OBJ_GFX_HIKER,         54,  0, 4,  3, DIR_EAST
	setmetatile                                     0, 4, -1, TRUE
	createvobject EVENT_OBJ_GFX_BEAUTY,        55,  0, 3,  3, DIR_EAST
	setmetatile                                     0, 3, -1, TRUE
	return

@ -----------------------------------------------------
@ TV Screens

EverGrandeCity_WaitingRoom1_SignScript_TVs::
	goto_if_set FLAG_TEMP_2, EverGrandeCity_WaitingRoom1_SignScript_TVs2
	msgbox EverGrandeCity_WaitingRoom1_Text_TVs, MSGBOX_DIALOG
	setflag FLAG_TEMP_2
	end
EverGrandeCity_WaitingRoom1_Text_TVs:
	.string "Reporter: It's been an exciting first\n"
	.string "day of this year's Elite Four Conference!\p"
	.string "We just saw a stunning defeat for a poor\n"
	.string "Lass from Lilycove. She almost had it!\p"
	.string "Right after the break, we'll have our\n"
	.string "12th combatant for the day, a {PLAYER_boy}\l"
	.string "by the name of {PLAYER}, coming to us\l"
	.string "from the town of Littleroot!\p"
	.string "But first, a word from our sponsors.$"
EverGrandeCity_WaitingRoom1_SignScript_TVs2:
	msgbox EverGrandeCity_WaitingRoom1_Text_TVs2, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_TVs2:
	.string "Currently showing ads for Pokémon food.$"

@ -----------------------------------------------------
@ People

EverGrandeCity_WaitingRoom1_EventScript_Logan::
	goto_if_set FLAG_TEMP_1, EverGrandeCity_WaitingRoom1_EventScript_Logan2
	msgbox EverGrandeCity_WaitingRoom1_Text_Logan, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end
EverGrandeCity_WaitingRoom1_Text_Logan:
	.string "{PLAYER}! You made it to the Conference!\p"
	.string "After what you did to my team, I'm\n"
	.string "surprised they didn't, like, disqualify\l"
	.string "you or something, haha…\p"
	.string "Woah, {PLAYER_dude}, what's with the look?!\n"
	.string "Sorry, I must have touched a nerve!\p"
	.string "I didn't mean anything by it…$"
EverGrandeCity_WaitingRoom1_EventScript_Logan2:
	msgbox EverGrandeCity_WaitingRoom1_Text_Logan2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom1_Text_Logan2:
	.string "Um… G-Good luck, {P_PLAYER}…$"


EverGrandeCity_WaitingRoom1_EventScript_Person1::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person1, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom1_Text_Person1::
	.string "When will it be my turn?$"


EverGrandeCity_WaitingRoom1_EventScript_Person2::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom1_Text_Person2::
	.string "Did you hear your name get called?\n"
	.string "Good luck.$"


EverGrandeCity_WaitingRoom1_EventScript_Person3::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person3, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_Person3::
	.string "This boy is tapping his foot rapidly,\n"
	.string "nervously.$"


EverGrandeCity_WaitingRoom1_EventScript_Person4::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person4, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_Person4::
	.string "She seems too intent on pacing\nto notice you.$"


EverGrandeCity_WaitingRoom1_EventScript_Person5::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person5, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_Person5::
	.string "His gaze is fixed at the floor, and\n"
	.string "he seems to be muttering about\l"
	.string "strategies to himself.$"


EverGrandeCity_WaitingRoom1_EventScript_Person6::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person6, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_Person6::
	.string "She seems to be doing breathing\nexercises.$"


EverGrandeCity_WaitingRoom1_EventScript_Person7::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person7, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_Person7::
	.string "He's curled up, reading a book.\p"
	.string "It would look like he was calm, except\n"
	.string "his hand is rapidly tapping his knee.$"


EverGrandeCity_WaitingRoom1_EventScript_Person8::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person8, MSGBOX_DIALOG
	end
EverGrandeCity_WaitingRoom1_Text_Person8::
	.string "If she hits with Blizzard, I can\n"
	.string "counter with… shoot, that won't work…$"


EverGrandeCity_WaitingRoom1_EventScript_Person9::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person9, MSGBOX_DIALOG
	end
EverGrandeCity_WaitingRoom1_Text_Person9::
	.string "It looks like the next person is going\n"
	.string "to battle Sidney.\p"
	.string "He has a lot of Dark-type Pokémon…\p"
	.string "What do I have to counter that if I\n"
	.string "have to face off against him when I go?$"


EverGrandeCity_WaitingRoom1_EventScript_Person10::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person10, MSGBOX_DIALOG
	end
EverGrandeCity_WaitingRoom1_Text_Person10::
	.string "…\n…$"


EverGrandeCity_WaitingRoom1_EventScript_Person11::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person11, MSGBOX_DIALOG
	end
EverGrandeCity_WaitingRoom1_Text_Person11::
	.string "You're gonna win big for us,\n"
	.string "aren't you, my darling Pikaq?$"


EverGrandeCity_WaitingRoom1_EventScript_Person12::
	msgbox EverGrandeCity_WaitingRoom1_Text_Person12, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom1_Text_Person12::
	.string "She's staring off into space.\n"
	.string "Perhaps she needs rebooting?$"


EverGrandeCity_WaitingRoom1_EventScript_Pikachu:: @ 82030DA
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, 0
	msgbox EverGrandeCity_WaitingRoom1_Text_20334A, MSGBOX_CDIALOG
	waitmoncry
	release
	end
EverGrandeCity_WaitingRoom1_Text_20334A: @ 820334A
	.string "Pikaq: Pika pika!$"



