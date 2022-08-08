OldaleTown_MapScripts:: @ 81E8EA2
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

OldaleTown_OnTransition: @ 81E8EA8
	call Common_EventScript_SetupRivalGender
	setflag FLAG_VISITED_OLDALE_TOWN
	call_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_PreAdventRoadblockSetup
	call_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_1E8ECC
	end

OldaleTown_EventScript_PreAdventRoadblockSetup:: @ 81E8ED2
	setobjectxyperm 1, 4, 12
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 3, 3, 10
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_LEFT
	setflag FLAG_HIDE_OLDALE_ROADBLOCK_AFTERMATCH
	return

OldaleTown_EventScript_1E8ECC:: @ 81E8ECC
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	clearflag FLAG_HIDE_OLDALE_ROADBLOCK_AFTERMATCH
	return

@ -----------------------------------------------------
@ Signs

OldaleTown_EventScript_TownSign:: @ 81E8EEA
	msgbox OldaleTown_Text_1E94DA, MSGBOX_SIGN
	end
OldaleTown_Text_1E94DA: @ 81E94DA
	.string "{PLACE}Oldale Town{END}\n"
	.string "“Where things start off scarce.”$"

@ -----------------------------------------------------
@ People

OldaleTown_EventScript_RestingGirl:: @ 81E8EF3
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_RestingGirl_BlockEvent
	msgbox OldaleTown_Text_1E918F, MSGBOX_DIALOG
	end
OldaleTown_Text_1E918F: @ 81E918E
	.string "He's gonna be fine, mom…\n"
	.string "D-Don't worry…$"
OldaleTown_EventScript_RestingGirl_BlockEvent:
	msgbox OldaleTown_Text_1E918E, MSGBOX_NPC
	release
	end
OldaleTown_Text_1E918E: @ 81E918E
	.string "I can't stand the atmosphere inside.\p"
	.string "They say my brother is in stable\n"
	.string "condition…$"


OldaleTown_EventScript_BlockadeBoy1::
	msgbox OldaleTown_Text_BlockadeBoy1, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceLeft
	waitmovement 0
	release
	end
OldaleTown_Text_BlockadeBoy1:
	.string "It looks like someone got attacked by\n"
	.string "some wild Pokemon! They're really hurt!$"


OldaleTown_EventScript_BlockadeBoy2::
	lock
	applymovement THIS_EVENT, Common_Movement_FaceDown
	msgbox OldaleTown_Text_BlockadeBoy2, MSGBOX_CDIALOG
	applymovement THIS_EVENT, Common_Movement_FaceLeft
	waitmovement 0
	release
	end
OldaleTown_Text_BlockadeBoy2:
	.string "Connor! What's happening?\n"
	.string "I can't see anything!$"


OldaleTown_TriggerScript_Policeman::
	lock
	msgbox OldaleTown_Text_1E91G4, MSGBOX_CDIALOG
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	release
	end
OldaleTown_Text_1E91G4:
	.string "Oh, {PLAYER_sir}, I'm sorry.\n"
	.string "You can't come this way right now.\p"
	.string "The situation should be cleared soon,\n"
	.string "if you'd like to wait in the Center.$"


OldaleTown_EventScript_BlockadeMother::
	msgbox OldaleTown_Text_BlockadeMother, MSGBOX_DESCRIBE
	release
	end
OldaleTown_Text_BlockadeMother: @ 81E918E
	.string "This woman seems to be crying\n"
	.string "uncontrollably.$"



OldaleTown_EventScript_MartEmployee:: @ 81E8EFC
	lock
	faceplayer
	flagasdialog
	goto_if_set FLAG_RECEIVED_POTION_OLDALE, OldaleTown_EventScript_1E8FB9
	msgbox OldaleTown_Text_1E91C0, MSGBOX_DEFAULT
	giveitem_std ITEM_POTION
	compare VAR_RESULT, 0
	goto_if_eq OldaleTown_EventScript_1E8FC3
	msgbox OldaleTown_Text_1E92AF, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_POTION_OLDALE
	release
	end
OldaleTown_EventScript_1E8FB9:: @ 81E8FB9
	msgbox OldaleTown_Text_1E92AF, MSGBOX_DEFAULT
	release
	end
OldaleTown_Text_1E91C0:
	.string "Hi! I work at the Mart Counter in\n"
	.string "the Pokémon Center.\p"
	.string "Just head inside and find us in the\n"
	.string "back corner of any Center.\p"
	.string "We sell a variety of goods, including\n"
	.string "Potions and Antidotes! And of course\l"
	.string "we give away Poké Balls at the\l"
	.string "adjoining counter!\p"
	.string "Here, I'd like you to have this as\n"
	.string "a promotional item.$"
OldaleTown_Text_1E92AF: @ 81E92AF
	.string "A Potion can be used anytime, so it's\n"
	.string "even more useful than a Pokémon Center\l"
	.string "in certain situations.$"
OldaleTown_EventScript_1E8FC3:: @ 81E8FC3
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end


OldaleTown_EventScript_BlockadeBoy3:: @ 81E901F
	lock
	faceplayer
	flagasdialog
	goto_if_set FLAG_ADVENTURE_STARTED, OldaleTown_EventScript_1E9066
	msgbox OldaleTown_Text_1E939A, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
OldaleTown_Text_1E939A: @ 81E939A
	.string "I saw it myself! A boy's Pokémon\n"
	.string "was struck down by a wild Pokémon!\p"
	.string "And then the boy was attacked by\n"
	.string "the wild Pokémon himself!\p"
	.string "My Poochyena and I managed to fend\n"
	.string "off the wild Pokémon, but the boy\l"
	.string "was badly injured!\p"
	.string "I-I hope he's gonna be okay…$"

OldaleTown_EventScript_1E9066:: @ 81E9066
	msgbox OldaleTown_Text_1E93F8, MSGBOX_DEFAULT
	release
	end
OldaleTown_Text_1E93F8: @ 81E93F8
	.string "Make sure your Pokémon are prepared to\n"
	.string "go out into the wilds.\p"
	.string "If they're not, you could end up like\n"
	.string "that boy earlier… or worse…$"


@ -----------------------------------------------------
@ Rival

OldaleTown_EventScript_RivalSpeak:: @ 81E90E6
	@ Select movement
	selectpointer OldaleTown_EventScript_Rival_MovementTable, VAR_0x8009
	applymovement 4, 0 @ Apply selected movement
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	markasdialog
	selectpointer_ongender OldaleTown_Text_1E9462, OldaleTown_Text_1E948A
	msgbox_selected
	closemessage
	compare VAR_0x8009, 0
	call_if_eq OldaleTown_EventScript_1E9148
	applymovement 4, Common_Movement_WalkDownOutOfFrame
	waitmovement 0
	removeobject 4
	setvar VAR_OLDALE_STATE, 2
	setflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	releaseall
	end
OldaleTown_EventScript_1E9148:: @ 81E9148
	applymovement EVENT_OBJ_ID_PLAYER, OldaleTown_Movement_1E917E
	return
OldaleTown_Movement_1E917E: @ 81E917E
	delay_8
	delay_4
	walk_in_place_fastest_down
	step_end
OldaleTown_Text_1E9462: @ 81E9462
	.string "May: Hey, {PLAYER}.\p"
	.string "I was just considering whether I\n"
	.string "should rest at the Pokémon Center\l"
	.string "before heading back home.\p"
	.string "You know it's one of the only places\n"
	.string "to record your accomplishments too.\p"
	.string "Anyway, meet you back at home.$"
OldaleTown_Text_1E948A: @ 81E948A
	.string "Brendan: I'm heading back to my dad's\n"
	.string "lab now.\p"
	.string "I was maybe gonna rest at the Pokémon\n"
	.string "Center first, since it's one of the\l"
	.string "few places to record what you've done.\p"
	.string "But I figure I could sleep at home too.\n"
	.string "Meet you there.$"

.align 2
OldaleTown_EventScript_Rival_MovementTable:
	.4byte Common_Movement_FacePlayer
	.4byte Common_Movement_FaceLeft
	.4byte Common_Movement_WalkLeft1
	.4byte OldaleTown_Movement_1E9170
	.4byte 0
OldaleTown_Movement_1E9170: @ 81E9170
	walk_left
	walk_left
	step_end

OldaleTown_EventScript_Rival:: @ 81E9070
	lockall
	setvar VAR_0x8009, 0
	goto OldaleTown_EventScript_RivalSpeak
	end

OldaleTown_TriggerScript_Rival1:: @ 81E90C6
	lockall
	setvar VAR_0x8009, 1
	goto OldaleTown_EventScript_RivalSpeak
	end

OldaleTown_TriggerScript_Rival2:: @ 81E90A6
	lockall
	setvar VAR_0x8009, 2
	goto OldaleTown_EventScript_RivalSpeak
	end

OldaleTown_TriggerScript_Rival3:: @ 81E9086
	lockall
	setvar VAR_0x8009, 3
	goto OldaleTown_EventScript_RivalSpeak
	end

















OldaleTown_Movement_1E9182: @ 81E9182
	delay_8
	walk_right
	step_end

OldaleTown_Movement_1E9185: @ 81E9185
	walk_fast_up
	walk_in_place_fastest_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

OldaleTown_Movement_1E918B: @ 81E918B
	walk_down
	walk_left
	step_end





















