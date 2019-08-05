EverGrandeCity_WaitingRoom3_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_WaitingRoom3_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_WaitingRoom3_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_WaitingRoom3_FrameTable
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom3_OnLoad:
	setflag FLAG_DISABLE_FADE_INIT
	overridemapname EverGrandeCity_WaitingRoom3_MapName
	end
EverGrandeCity_WaitingRoom3_MapName:
	.string "Day 3$"

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom3_FrameTable:
	map_script_2 VAR_TEMP_0, 0, EverGrandeCity_WaitingRoom3_SlowFade
	.2byte 0

EverGrandeCity_WaitingRoom3_SlowFade:
	setvar VAR_TEMP_0, 1
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	advancetime 23, 0, 35
	callnative ShowMapNamePopup
	delay 80
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 6
	end

@ -----------------------------------------------------

EverGrandeCity_WaitingRoom3_OnResume:
	call EverGrandeCity_WaitingRoom3_CreateVirtualObjects
	end
EverGrandeCity_WaitingRoom3_CreateVirtualObjects:
	createvobject EVENT_OBJ_GFX_BEAUTY,        50,  0, 3,  3, DIR_EAST
	setmetatile                                     0, 3, -1, TRUE
	return

@ -----------------------------------------------------
@ TV Screens

EverGrandeCity_WaitingRoom3_SignScript_TVs::
	goto_if_set FLAG_TEMP_2, EverGrandeCity_WaitingRoom3_SignScript_TVs2
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, 
	msgbox EverGrandeCity_WaitingRoom3_Text_TVs, MSGBOX_DIALOG
	setflag FLAG_TEMP_2
	end
EverGrandeCity_WaitingRoom3_Text_TVs:
	.string "Reporter: Welcome back to day three, folks!\n"
	.string "We have quite the Conference this year!\p"
	.string "We have a real treat coming up. It's our\n"
	.string "{PLAYER_boy} from Littleroot who's recently\l"
	.string "captured hearts and minds across Hoenn!\p"
	.string "It came out this morning that {PLAYER} was\n"
	.string "once part of Team Aqua, but that {PLAYER_they}\l"
	.string "was a rogue agent that helped stop\l"
	.string "the beasts and save the region!\p"
	.string "If these roumors are true, it's possible\n"
	.string "we may be seeing a new raising star!\l"
	.string "Possibly even the next champion!$"
EverGrandeCity_WaitingRoom3_SignScript_TVsA:
	msgbox EverGrandeCity_WaitingRoom3_Text_TVsA, MSGBOX_DIALOG
	setflag FLAG_TEMP_2
	end
EverGrandeCity_WaitingRoom3_Text_TVsA:
	.string "Reporter: Welcome back to day three, folks!\n"
	.string "We have quite the Conference this year!\p"
	.string "We have a real treat coming up. It's our\n"
	.string "{PLAYER_boy} from Littleroot who's recently\l"
	.string "captured hearts and minds across Hoenn!\p"
	.string "It came out this morning that {PLAYER} was\n"
	.string "the one who challenged the divine beasts\l"
	.string "that were wreaking havoc in the region.\p"
	.string "{PLAYER_They} did it SINGLEHANDEDLY, as told\n"
	.string "by multiple eyewitness accounts!\p"
	.string "If these roumors are true, we're sure to\n"
	.string "see {PLAYER} shoot to the top of this\l"
	.string "Conference, to the Championship!$"
EverGrandeCity_WaitingRoom3_SignScript_TVs2:
	bufferpartymonnick 0, 0
	msgbox EverGrandeCity_WaitingRoom3_Text_TVs2, MSGBOX_DESCRIBE
	end
EverGrandeCity_WaitingRoom3_Text_TVs2:
	.string "It's are report about rumors from\nthis morning.$"
	
@ -----------------------------------------------------
@ People

EverGrandeCity_WaitingRoom3_EventScript_Logan::
	goto_if_set FLAG_TEMP_1, EverGrandeCity_WaitingRoom3_EventScript_Logan2
	msgbox EverGrandeCity_WaitingRoom3_Text_Logan, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end
EverGrandeCity_WaitingRoom3_Text_Logan:
	.string "{P_PLAYER}! I'm… I'm surprised you\n"
	.string "made it this far…\p"
	.string "That was a tough battle yesterday…\n"
	.string "I… I barely made it through myself…$"
EverGrandeCity_WaitingRoom3_EventScript_Logan2:
	msgbox EverGrandeCity_WaitingRoom3_Text_Logan2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom3_Text_Logan2:
	.string "Heh… heheheh…$"


EverGrandeCity_WaitingRoom3_EventScript_Person1::
	goto_if_set FLAG_TEMP_3, EverGrandeCity_WaitingRoom3_EventScript_Person1A
	msgbox EverGrandeCity_WaitingRoom3_Text_Person1, MSGBOX_NPC
	setflag FLAG_TEMP_3
	end
EverGrandeCity_WaitingRoom3_Text_Person1::
	.string "I don't think I'm gonna make it to the\n"
	.string "next round. My Pokémon are beat.\p"
	.string "But it's alright. This boy asked me\n"
	.string "out just before my battle yesterday.\p"
	.string "He was apparently so distracted by my\n"
	.string "saying yes that he completely zoned\l"
	.string "out and lost the battle.\p"
	.string "But now he's cheering me on from the\n"
	.string "stands today, and we have dinner tonight.\p"
	.string "So, on the whole, a net positive.$"
EverGrandeCity_WaitingRoom3_EventScript_Person1A:
	msgbox EverGrandeCity_WaitingRoom3_Text_Person1A, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom3_Text_Person1A:
	.string "Sorry, I don't even know why I told you\n"
	.string "all that! You're a complete stranger!\p"
	.string "I guess that's just my nerves for you!$"


EverGrandeCity_WaitingRoom2_EventScript_Person2::
	msgbox EverGrandeCity_WaitingRoom2_Text_Person2, MSGBOX_NPC
	end
EverGrandeCity_WaitingRoom2_Text_Person2::
	.string "My Bug-type Pokémon held their own against\n"
	.string "Drake's dragons, but there's no way I'm\l"
	.string "gonna survive Glacia's ice today…$"
		


