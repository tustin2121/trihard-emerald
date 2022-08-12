MtPyre_1F_MapScripts:: @ 8230F3E
	map_script MAP_SCRIPT_ON_LOAD, MtPyre_1F_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_Common_OnResume
	.byte 0

@ -----------------------------------------------------
MtPyre_1F_OnLoad:
	addvar_if_unset FLAG_VISITED_MT_PYRE, VAR_TEMP_0, 1
	end

MtPyre_Common_OnResume:
	@ Memoize the number of dead pokemon for use here
	callnative MemoizeBoxedMon
	@ Now VAR_TEMP_B has the number of mon in the graveyard
	end
	

@ -----------------------------------------------------

MtPyre_1F_EventScript_230F3F:: @ 8230F3F
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_230F6E
	msgbox MtPyre_1F_Text_230F8A, MSGBOX_DEFAULT
	giveitem_std ITEM_CLEANSE_TAG
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end
MtPyre_1F_Text_230F8A: @ 8230F8A
	.string "All sorts of beings wander the slopes\n"
	.string "of Mt. Pyre…\p"
	.string "There is no telling what may happen.\n"
	.string "Take this. It's for your own good.$"
MtPyre_1F_EventScript_230F6E:: @ 8230F6E
	msgbox MtPyre_1F_Text_231005, MSGBOX_DEFAULT
	release
	end
MtPyre_1F_Text_231005: @ 8231005
	.string "Have a Pokémon hold that\n"
	.string "Cleanse Tag.\p"
	.string "It will help ward off wild Pokémon.$"


MtPyre_1F_EventScript_230F78:: @ 8230F78
	goto_if_set FLAG_TEMP_1, MtPyre_1F_EventScript_230F78b
	msgbox MtPyre_1F_Text_23104F, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end
MtPyre_1F_EventScript_230F78b:: @ 8230F78
	msgbox MtPyre_1F_Text_23104Fb, MSGBOX_NPC
	end
MtPyre_1F_Text_23104F: @ 823104F
	.string "Did you come to pay your respect\n"
	.string "to the spirits of departed Pokémon?\p"
	.string "No? Not your Pokémon?{PAUSE 10}\n"
	.string "What's a “Tūtū”? Your grandmother? Oh…\l" @ fallthrough
MtPyre_1F_Text_23104Fb:
	.string "My condolences, child.$"
	@ .string "You must care for your Pokémon a lot.$"


MtPyre_1F_EventScript_230F81:: @ 8230F81
	compare VAR_TEMP_B, 0
	goto_if_eq MtPyre_1F_EventScript_230F81_normal
	msgbox MtPyre_1F_Text_2310BA, MSGBOX_NPC
	end
MtPyre_1F_Text_2310BA: @ 82310BA
	.string "You okay? You seem vexed.\p"
	.string "Every time you look at a grave\n"
	.string "marker, you go pale.\p"
.if TPP_MODE
	.string "{FORCE_SPEED_MID}"
.endif
	.string "Like those who you've discarded on your\n"
	.string "journey haunt your guilty conscience…"
.if TPP_MODE
	.string "{PAUSE 60}"
.endif
	.string "$"
MtPyre_1F_EventScript_230F81_normal:
	msgbox MtPyre_1F_Text_2310BB, MSGBOX_NPC
	end
MtPyre_1F_Text_2310BB:
	.string "This is the final resting place of my\n"
	.string "Zigzagoon. I cherished it…$"


MtPyre_1F_EventScript_TriggerMemory::
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMark
	playse SE_PIN
	waitmovement EVENT_OBJ_ID_PLAYER
	delay 15
	msgbox MtPyre_1F_Text_TriggerMemory1, MSGBOX_DESCRIBE
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkLeft2
	waitmovement EVENT_OBJ_ID_PLAYER
	delay 15
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement EVENT_OBJ_ID_PLAYER
	msgbox MtPyre_1F_Text_TriggerMemory2, MSGBOX_DESCRIBE
	setflag FLAG_VISITED_MT_PYRE
	setvar VAR_TEMP_0, 0
	closemessage
	releaseall
	end
MtPyre_1F_Text_TriggerMemory1:
	.string "A chill runs down {PLAYER}'s spine.$"
MtPyre_1F_Text_TriggerMemory2:
	.string "Tūtū's grave looked like these…{PAUSE 20}\p"
	.string "No!{PAUSE 30}\n"
	.string "Now's not the time to cry…$"
