EverGrandeCity_WaitingRoom2_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_WaitingRoom2_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_WaitingRoom2_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_WaitingRoom2_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom2_OnLoad:
	setflag FLAG_DISABLE_FADE_INIT
	overridemapname EverGrandeCity_WaitingRoom2_MapName
	end
EverGrandeCity_WaitingRoom2_MapName:
	.string "Day 2$"

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom2_FrameTable:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_WaitingRoom2_SlowFade
	.2byte 0

EverGrandeCity_WaitingRoom2_SlowFade:
	setvar VAR_TEMP_0, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	advancetime 22, 0, 35
	callnative ShowMapNamePopup
	delay 80
	call EverGrandeCity_WaitingRoom2_CreateVirtualObjects
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 6
	end

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom2_OnResume:
	compare VAR_TEMP_0, 1
	call_if_eq EverGrandeCity_WaitingRoom2_CreateVirtualObjects
	end
EverGrandeCity_WaitingRoom2_CreateVirtualObjects:
	createvobject EVENT_OBJ_GFX_YOUNGSTER,     50, 10, 7,  3, DIR_WEST
	setmetatile                                    10, 7, -1, TRUE
	createvobject EVENT_OBJ_GFX_GENTLEMAN,     51, 10, 4,  3, DIR_WEST
	setmetatile                                    10, 4, -1, TRUE
	createvobject EVENT_OBJ_GFX_BUG_CATCHER,   52,  0, 7,  3, DIR_EAST
	setmetatile                                     0, 7, -1, TRUE
	createvobject EVENT_OBJ_GFX_BEAUTY,        53,  0, 3,  3, DIR_EAST
	setmetatile                                     0, 3, -1, TRUE
	return

@ -----------------------------------------------------
@ TV Screens

EverGrandeCity_WaitingRoom2_SignScript_TVs::
	goto_if_set FLAG_TEMP_2, EverGrandeCity_WaitingRoom2_SignScript_TVs2
	msgbox EverGrandeCity_WaitingRoom2_Text_TVs, MSGBOX_DIALOG
	setflag FLAG_TEMP_2
	end
EverGrandeCity_WaitingRoom2_Text_TVs:
	.string "Reporter: It's day two of the Elite\n"
	.string "Four Conference, ladies and gents!\p"
	.string "We're looking forward to the eighth\n"
	.string "combatant of the day, ready to face\l"
	.string "off against Phoebe!\p"
	.string "{PLAYER} from Littleroot will be battling\n"
	.string "her Ghost Pokémon in a short moment.\p"
	.string "{PLAYER_They} proved {PLAYER_them}self yesterday against\n"
	.string "Sidney, but who knows if that luck will\l"
	.string "continue today.$"
EverGrandeCity_WaitingRoom2_SignScript_TVs2:
	bufferpartymonnick 0, 0
	msgbox EverGrandeCity_WaitingRoom2_Text_TVs2, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom2_Text_TVs2:
	.string "They're replaying moments from the\n"
	.string "battle against Sidney yesterday.\p"
	.string "There's lots of talk about mistakes\n"
	.string "{STR_VAR_1} made.\p"
	.string "And someone's drawing on a whiteboard\n"
	.string "with a red marker to help illustrate.$"

@ -----------------------------------------------------
@ People

EverGrandeCity_WaitingRoom2_EventScript_Logan::
	goto_if_set FLAG_TEMP_1, EverGrandeCity_WaitingRoom2_EventScript_Logan2
	msgbox EverGrandeCity_WaitingRoom2_Text_Logan, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end
EverGrandeCity_WaitingRoom2_Text_Logan:
	.string "{PLAYER}! Still in it, I see.\p"
	.string "These battles are turning out to be a\n"
	.string "lot tougher than I thought.\p"
	.string "Ha… ha ha…$"
EverGrandeCity_WaitingRoom2_EventScript_Logan2:
	msgbox EverGrandeCity_WaitingRoom2_Text_Logan2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom2_Text_Logan2:
	.string "Good luck, dude…$" @ use of literal "dude" is deliberate


EverGrandeCity_WaitingRoom2_EventScript_Person1::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person1, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom2_Text_Person1::
	.string "The Elite Four is a tough lot.\p"
	.string "They only get tougher as you go…$"


EverGrandeCity_WaitingRoom2_EventScript_Person2::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom2_Text_Person2::
	.string "The Elite Four is a tough lot.\p"
	.string "They only get tougher as you go…$"


EverGrandeCity_WaitingRoom2_EventScript_Person3::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person3, MSGBOX_DIALOG
	end
EverGrandeCity_WaitingRoom2_Text_Person3::
	.string "That's right, my little Pikaq!\p"
	.string "Eat these protein cookies so you can\n"
	.string "be ready to battle anything!$"


EverGrandeCity_WaitingRoom2_EventScript_Person4::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person4, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom2_Text_Person4::
	.string "She seems to be praying to herself…$"


EverGrandeCity_WaitingRoom2_EventScript_Person5::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person5, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom2_Text_Person5::
	.string "I'm too tired to stand, but\n"
	.string "I'm too wired to sit…$"


EverGrandeCity_WaitingRoom2_EventScript_Person6::
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_TEMP_5, EverGrandeCity_WaitingRoom2_EventScript_Person6B
	goto_if_set FLAG_SCENE_0, EverGrandeCity_WaitingRoom2_EventScript_Person6A
	setyesnotext gYN_YeahBang, gYN_Uhhh
	msgbox EverGrandeCity_WaitingRoom2_Text_Person6, MSGBOX_YESNO
	switch VAR_RESULT
	case YES, EverGrandeCity_WaitingRoom2_EventScript_Person6A
	case NO, EverGrandeCity_WaitingRoom2_EventScript_Person6B
	release
	end
EverGrandeCity_WaitingRoom2_Text_Person6:
	.string "I don't know which is making me more\n"
	.string "nervous: the Conference, or that pretty\l"
	.string "girl standing over there…\p"
	.string "Should… I ask her out…?$"
EverGrandeCity_WaitingRoom2_EventScript_Person6A:
	msgbox EverGrandeCity_WaitingRoom2_Text_Person6A
	setflag FLAG_SCENE_0
	release
	end
EverGrandeCity_WaitingRoom2_Text_Person6A:
	.string "Yeah, you're right, I should go ask\n"
	.string "her out!\p"
	.string "J-Just not yet…$"
EverGrandeCity_WaitingRoom2_EventScript_Person6B:
	msgbox EverGrandeCity_WaitingRoom2_Text_Person6B
	setflag FLAG_TEMP_5
	release
	end
EverGrandeCity_WaitingRoom2_Text_Person6B:
	.string "No, y-you're right. I-I'll just make a\n"
	.string "fool of myself…$"
	

EverGrandeCity_WaitingRoom2_EventScript_Person7::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person7, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom2_Text_Person7:
	.string "His gaze is fixed on the lady's Pikachu.\p"
	.string "He seems to be muttering about items\n"
	.string "to himself.$"


EverGrandeCity_WaitingRoom2_EventScript_Person8::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person8, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom2_Text_Person8:
	.string "Each one of us is fighting a different\n"
	.string "Elite Member, so that the Elite Four\l"
	.string "can rest between fights.\p"
	.string "Who did you fight yesterday?\n"
	.string "Sidney? I fought Glacia.$"

