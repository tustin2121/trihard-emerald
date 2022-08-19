DewfordTown_MapScripts:: @ 81E9507
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, DewfordTown_FrameTable
	map_script MAP_SCRIPT_ON_LOAD, DewfordTown_OnLoad
	.byte 0

DewfordTown_OnTransition: @ 81E950D
	setflag FLAG_VISITED_DEWFORD_TOWN
	end

@ -----------------------------------------------------

DewfordTown_FrameTable:
	map_script_2 VAR_CROSS_MAP_TRIGGER, 1, DewfordTown_EventScript_LockHouse_Kickout
	.2byte 0
	
DewfordTown_OnLoad:
	call_if_set FLAG_DAILY_STEALFAIL_DEWFORD1, DewfordTown_EventScript_LockHouse
	end

DewfordTown_EventScript_LockHouse_Kickout:
	setvar VAR_CROSS_MAP_TRIGGER, 0
	setflag FLAG_DAILY_STEALFAIL_DEWFORD1
	markasdialog 0
	message DewfordTown_EventScript_LockHouse_KickoutText
	waitmessage
	delay 40
	closemessage
	@ fallthrough
DewfordTown_EventScript_LockHouse:
	setmetatile 8, 8, 0x2FE, TRUE @Set tile to non-warp tile
	return
DewfordTown_EventScript_LockHouse_KickoutText:
	.string "And stay out!!$"

@ -----------------------------------------------------
@ Briney Sailing

DewfordTown_EventScript_BrineyArriveFromSlateport:: @ 81ED139
	@ continued sequence from briney_boat.inc
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	applymovement EVENT_OBJ_ID_PLAYER, Route109_Movement_1EE900
	waitmovement 0
	addobject 4
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	setobjectxyperm 2, 12, 8
	addobject 2
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	applymovement 2, Route109_Movement_1EE90D
	waitmovement 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	setflag FLAG_HIDE_ROUTE_109_MR_BRINEY_BOAT
	hideobjectat 1, MAP_ROUTE109
	msgbox Route109_Text_1E9C1D, MSGBOX_NPC
	closemessage
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_ROUTE109
	resetobjectpriority 2, MAP_DEWFORD_TOWN
	moveobjectoffscreen 2
	release
	end
Route109_Movement_1EE900: @ 81EE900
	walk_down
	walk_down
	walk_left
	walk_in_place_fastest_right
	step_end
Route109_Movement_1EE90D: @ 81EE90D
	walk_down
	walk_in_place_fastest_left
	step_end


DewfordTown_EventScript_BrineyArriveFromRoute104:: @ 81ED139
	@ continued sequence from briney_boat.inc
	delay 50
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ED353
	waitmovement 0
	showobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	applymovement EVENT_OBJ_ID_PLAYER, Route104_Movement_1ED355
	waitmovement 0
	setobjectxyperm 2, 12, 8
	addobject 2
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	clearflag FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN
	applymovement 2, Route104_Movement_1ED35C
	waitmovement 0
	addobject 4
	clearflag FLAG_HIDE_MR_BRINEY_BOAT_DEWFORD_TOWN
	call Common_EventScript_EndBrineyBoatSequence
	setflag FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT
	hideobjectat 7, MAP_ROUTE104
	copyvar VAR_BRINEY_LOCATION, VAR_0x8008
	resetobjectpriority EVENT_OBJ_ID_PLAYER, MAP_ROUTE104
	resetobjectpriority 2, MAP_DEWFORD_TOWN
	moveobjectoffscreen 2
	setvar VAR_BOARD_BRINEY_BOAT_ROUTE104_STATE, 0
	goto Route104_EventScript_1ED1BE
	end
Route104_Movement_1ED353: @ 81ED353
	walk_down
	step_end
Route104_Movement_1ED355: @ 81ED355
	walk_down
	walk_left
	walk_in_place_fastest_right
	step_end
Route104_Movement_1ED35C: @ 81ED35C
	walk_down
	walk_in_place_fastest_left
	step_end

Route104_EventScript_1ED1BE:: @ 81ED1BE
	msgbox Route104_Text_1E9C1D, MSGBOX_DIALOG
	releaseall
	end
Route104_Text_1E9C1D: @ 81E9C1D
Route109_Text_1E9C1D: @ 81E9C1D
	.string "Mr. Briney: Ahoy!\n"
	.string "We've hit land in Dewford!\p"
	.string "You just go on and tell me whenever\n"
	.string "you want to set sail again!$"


DewfordTown_EventScript_BrineyTalk:: @ 81E9511
	lock
	faceplayer
	markasdialog
	message DewfordTown_Text_1E9C8A
	waitmessage
	multichoicedefault 21, 6, 0, 2, 0
	switch VAR_RESULT
	case 0, DewfordTown_EventScript_1E955A
	case 1, DewfordTown_EventScript_1E956A
	case 2, DewfordTown_EventScript_1E957A
	case 127, DewfordTown_EventScript_1E957A
	end
DewfordTown_Text_1E9C8A: @ 81E9C8A
	.string "Mr. Briney: Ahoy!\n"
	.string "For you, I'll go out to sea anytime!\p"
	.string "Now, my friend, where are we bound?$"

DewfordTown_EventScript_1E955A:: @ 81E955A
	msgbox DewfordTown_Text_1E9CE5, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_BrineyDepartForRoute104
	release
	end
DewfordTown_Text_1E9CE5: @ 81E9CE5
	.string "Mr. Briney: Petalburg, is it?\p"
	.string "Anchors aweigh!\n"
	.string "Peeko, we're setting sail, my darling!$"

DewfordTown_EventScript_1E956A:: @ 81E956A
	msgbox DewfordTown_Text_1E9D3A, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_BrineyDepartForSlateport
	release
	end
DewfordTown_Text_1E9D3A: @ 81E9D3A
	.string "Mr. Briney: Slateport, is it?\p"
	.string "Anchors aweigh!\n"
	.string "Peeko, we're setting sail, my darling!$"

DewfordTown_EventScript_1E957A:: @ 81E957A
	msgbox DewfordTown_Text_1E9D8F, MSGBOX_DEFAULT
	closemessage
	release
	end
DewfordTown_Text_1E9D8F: @ 81E9D8F
	.string "Mr. Briney: You just tell me whenever\n"
	.string "you need to set sail again!$"

DewfordTown_EventScript_1E95A2:: @ 81E95A2
	msgbox DewfordTown_Text_1E9B7F, MSGBOX_DEFAULT
	closemessage
	goto DewfordTown_EventScript_BrineyDepartForRoute104
	end
DewfordTown_Text_1E9B7F: @ 81E9B7F
	.string "Mr. Briney: Petalburg it is, then!\p"
	.string "Anchors aweigh!\n"
	.string "Peeko, we're setting sail, my darling!$"

DewfordTown_EventScript_BrineyDepartForRoute104:: @ 81E9660
	call DewfordTown_EventScript_271E95
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN, 0
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	goto Briney_EventScript_Dewford_Route104
	end

DewfordTown_EventScript_BrineyDepartForSlateport:: @ 81E96E7
	call DewfordTown_EventScript_271E95
	setobjectpriority 2, MAP_DEWFORD_TOWN, 0
	setobjectpriority EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN, 1
	applymovement 2, DewfordTown_Movement_1E991D
	waitmovement 0
	removeobject 2
	applymovement EVENT_OBJ_ID_PLAYER, DewfordTown_Movement_1E9911
	waitmovement 0
	hideobjectat EVENT_OBJ_ID_PLAYER, MAP_DEWFORD_TOWN
	goto Briney_EventScript_Dewford_Slateport
	end

DewfordTown_Movement_1E9911: @ 81E9911
	walk_right
	walk_up
	step_end

DewfordTown_Movement_1E9914: @ 81E9914
	walk_up
	walk_up
	walk_up
	step_end

DewfordTown_Movement_1E9918: @ 81E9918
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

DewfordTown_Movement_1E991D: @ 81E991D
	walk_up
	step_end

DewfordTown_Movement_1E991F: @ 81E991F
	walk_up
	walk_up
	step_end


@ -----------------------------------------------------
@ Signs

DewfordTown_EventScript_1E95BA:: @ 81E95BA
	msgbox DewfordTown_Text_1E9A0F, MSGBOX_SIGN
	end
DewfordTown_Text_1E9A0F: @ 81E9A0F
	.string "{PLACE}Dewford Town{END}\n"
	.string "“A tiny island in the blue sea.”$"


DewfordTown_EventScript_1E95C3:: @ 81E95C3
	msgbox DewfordTown_Text_1E9A3D, MSGBOX_SIGN
	end
DewfordTown_Text_1E9A3D: @ 81E9A3D
	.string "{GYM}Dewford Town Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Brawly\l"
	.string "“A big wave in fighting!”$"


DewfordTown_EventScript_1E95CC:: @ 81E95CC
	msgbox DewfordTown_Text_1E9A7F, MSGBOX_SIGN
	end
DewfordTown_Text_1E9A7F: @ 81E9A7F
	.string "{PLACE}Dewford Hall{END}\n"
	.string "“Everyone's information exchange!”$"


@ -----------------------------------------------------
@ People

DewfordTown_EventScript_1E95B1:: @ 81E95B1
	msgbox DewfordTown_Text_1E99A8, MSGBOX_NPC
	end
DewfordTown_Text_1E99A8: @ 81E99A8
	.string "Dewford is a tiny island community.\n"
	.string "If something gets trendy here,\l"
	.string "everyone picks up on it right away.$"



DewfordTown_EventScript_1E95D5:: @ 81E95D5
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_OLD_ROD, DewfordTown_EventScript_1E962A
	setyesnotext gYN_Uhhh, gYN_PftNo
	msgbox DewfordTown_Text_1E9DD1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq DewfordTown_EventScript_1E95FF
	compare VAR_RESULT, NO
	goto_if_eq DewfordTown_EventScript_1E9620
	end
DewfordTown_Text_1E9DD1: @ 81E9DD1
	.string "This is a renowned fishing spot.\n"
	.string "Are you getting the itch to fish?$"
DewfordTown_EventScript_1E95FF:: @ 81E95FF
	msgbox DewfordTown_Text_1E9E14, MSGBOX_DEFAULT
	giveitem_std ITEM_OLD_ROD
	setflag FLAG_RECEIVED_OLD_ROD
	msgbox DewfordTown_Text_1E9E65, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1E9E14: @ 81E9E14
	.string "I hear you, and I like what\n"
	.string "you're saying!\p"
	.string "I'll give you one of my fishing rods.$"
DewfordTown_Text_1E9E65: @ 81E9E65
	.string "And, as an added bonus, I'll even throw\n"
	.string "in a little fishing advice!\p"
	.string "First, you want to face the water,\n"
	.string "then use the rod.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull on the rod.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your rod\l"
	.string "to haul them in.$"
DewfordTown_EventScript_1E9620:: @ 81E9620
	msgbox DewfordTown_Text_1E9F92, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1E9F92: @ 81E9F92
	.string "Oh, is that so?\n"
	.string "That's too bad, then.$"
DewfordTown_EventScript_1E962A:: @ 81E962A
	message DewfordTown_Text_1E9FB8
	waitmessage
	multichoice 20, 8, 50, 1
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E964C
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E9656
	end
DewfordTown_Text_1E9FB8: @ 81E9FB8
	.string "Yo!\n"
	.string "How's your fishing?$"
DewfordTown_EventScript_1E964C:: @ 81E964C
	msgbox DewfordTown_Text_1E9FD0, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1E9FD0: @ 81E9FD0
	.string "Is that right! That's great!\n"
	.string "Haul in some big ones!$"
DewfordTown_EventScript_1E9656:: @ 81E9656
	msgbox DewfordTown_Text_1EA004, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1EA004: @ 81EA004
	.string "Oh, hey, don't get down on yourself!\n"
	.string "I'll give you a little fishing advice.\p"
	.string "First, you want to face the water,\n"
	.string "then use the rod.\p"
	.string "Focus your mind…\n"
	.string "If you get a bite, pull the rod.\p"
	.string "Sometimes you can snag something\n"
	.string "immediately, but with bigger catches,\l"
	.string "you need to time the pulls on your rod\l"
	.string "to haul them in.$"




DewfordTown_EventScript_1E9922:: @ 81E9922
	lock
	faceplayer
	markasdialog
	call DewfordTown_EventScript_271E8B
	msgbox DewfordTown_Text_1EA136, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E9948
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9952
	end
DewfordTown_Text_1EA136: @ 81EA136
	.string "I like what's hip, happening, and trendy.\n"
	.string "I'm always checking it out.\p"
	.string "Listen, have you heard about this new\n"
	.string "“{STR_VAR_1}”?\p"
	.string "That's right!\n"
	.string "Of course you know!\p"
	.string "I mean, sheesh,\n"
	.string "“{STR_VAR_1}”…\l"
	.string "It's the hottest thing in cool!\p"
	.string "Wherever you're from,\n"
	.string "“{STR_VAR_1}”\l"
	.string "is the biggest happening thing, right?$"
DewfordTown_EventScript_1E9948:: @ 81E9948
	msgbox DewfordTown_Text_1EA491, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1EA491: @ 81EA491
	.string "Yeah, absolutely right!\p"
	.string "“{STR_VAR_1}” is the\n"
	.string "definition of “in” right now.$"
DewfordTown_EventScript_1E9952:: @ 81E9952
	msgbox DewfordTown_Text_1EA242, MSGBOX_DEFAULT
	setvar VAR_0x8004, EASY_CHAT_TYPE_TRENDY_PHRASE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	compare VAR_RESULT, 1
	goto_if_eq DewfordTown_EventScript_1E997D
	compare VAR_RESULT, 0
	goto_if_eq DewfordTown_EventScript_1E9994
	end
DewfordTown_Text_1EA242: @ 81EA242
	.string "Hunh?\n"
	.string "It's not the hip and happening thing?\p"
	.string "Well, hey, you have to tell me,\n"
	.string "what's new and what's “in”?$"
DewfordTown_EventScript_1E997D:: @ 81E997D
	incrementgamestat GAME_STAT_STARTED_TRENDS
	compare VAR_0x8004, 0
	goto_if_eq DewfordTown_EventScript_1E999E
	msgbox DewfordTown_Text_1EA2AA, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1EA2AA: @ 81EA2AA
	.string "Hunh?\n"
	.string "“{STR_VAR_2}”?\p"
	.string "… …\p"
	.string "…Uh… Yeah! That's right!\n"
	.string "Yeah, I knew that! Knew it all along!\p"
	.string "Of course I know about that!\n"
	.string "“{STR_VAR_2},” right?\p"
	.string "Yeah, that's it, it's there!\n"
	.string "Isn't “{STR_VAR_2}”\l"
	.string "the coolest, or what?\p"
	.string "It's the hippest thing in hip.\n"
	.string "You think I'd not know about it?\p"
	.string "“{STR_VAR_1}”…\n"
	.string "It's, like, so five minutes ago.\p"
	.string "Now, “{STR_VAR_2}” is\n"
	.string "what's vital and in tune with the times!$"
DewfordTown_EventScript_1E9994:: @ 81E9994
	msgbox DewfordTown_Text_1EA443, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1EA443: @ 81EA443
	.string "Well, if you hear of any happening new\n"
	.string "trends, come share them with me, okay?$"
DewfordTown_EventScript_1E999E:: @ 81E999E
	msgbox DewfordTown_Text_1EA3FE, MSGBOX_DEFAULT
	release
	end
DewfordTown_Text_1EA3FE: @ 81EA3FE
	.string "Hmm…\n"
	.string "“{STR_VAR_2},” huh?\p"
	.string "But personally, I think\n"
	.string "“{STR_VAR_1}”\l"
	.string "is what's real in cool.$"
