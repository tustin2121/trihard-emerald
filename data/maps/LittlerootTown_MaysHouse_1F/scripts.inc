LittlerootTown_MaysHouse_1F_MapScripts:: @ 81F88A5
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_MaysHouse_1F_MapScript1_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_MapScript1_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_MapScript2_FrameTable
	.byte 0

LittlerootTown_MaysHouse_1F_MapScript1_OnLoad: @ 81F88B5
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_lt LittlerootTown_MaysHouse_1F_EventScript_1F88CA
	call_if_set FLAG_DAD_IS_AT_WORK, LittlerootTown_MaysHouse_1F_EventScript_SetupLetter
	call_if_unset FLAG_DAD_IS_AT_WORK, LittlerootTown_PlayerHouse_1F_OnLoad_LetterHide
	end
LittlerootTown_MaysHouse_1F_EventScript_1F88CA:: @ 81F88CA
	setmetatile 5, 4, 0x270, 1
	setmetatile 5, 2, 0x268, 1
	setmetatile 4, 1, 0x26B, 1
	setmetatile 4, 2, 0x273, 0
	setmetatile 0, 2, 0x26C, 1
	setmetatile 0, 3, 0x274, 0
	return
LittlerootTown_MaysHouse_1F_EventScript_SetupLetter:: @ 81F88DD
	checkplayergender
	compare VAR_RESULT, FEMALE
	goto_if_eq LittlerootTown_PlayerHouse_1F_OnLoad_Letter
	goto LittlerootTown_PlayerHouse_1F_OnLoad_LetterHide
	return

LittlerootTown_MaysHouse_1F_MapScript1_OnTransition: @ 81F88F4
	compare VAR_LITTLEROOT_INTRO_STATE, 3
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F892E
	compare VAR_LITTLEROOT_INTRO_STATE, 5
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8916
	compare VAR_LITTLEROOT_INTRO_STATE, 6
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8922
	end
LittlerootTown_MaysHouse_1F_EventScript_1F892E:: @ 81F892E
	setobjectxyperm 1, 1, 8
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return
LittlerootTown_MaysHouse_1F_EventScript_1F8916:: @ 81F8916
	setobjectxyperm 1, 2, 4
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	return
LittlerootTown_MaysHouse_1F_EventScript_1F8922:: @ 81F8922
	setobjectxyperm 1, 7, 5
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_RIGHT
	return

@ -----------------------------------------------------

LittlerootTown_MaysHouse_1F_MapScript2_FrameTable: @ 81F893A
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_1F898C
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_MaysHouse_1F_EventScript_1F8964
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_MaysHouse_1F_EventScript_1F899D
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE_2, 1, LittlerootTown_MaysHouse_1F_EventScript_MeetingTheNeighbors
	map_script_2 VAR_LITTLEROOT_HOUSES_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_292AF2
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_1F898C:: @ 81F898C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_292704
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8964:: @ 81F8964
	lockall
	msgbox LittlerootTown_PlayersHouse_1F_Text_DadStayInRoom, MSGBOX_CDIALOG
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkUp1
	applymovement 1, Common_Movement_WalkUp1
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_MAYS_HOUSE_2F, 255, 1, 1
	waitstate
	releaseall
	end


LittlerootTown_MaysHouse_1F_EventScript_1F899D:: @ 81F899D
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	goto LittlerootTown_PlayersHouse_1F_EventScript_AfterClockCutscene
	end

LittlerootTown_MaysHouse_1F_EventScript_MeetingTheNeighbors:: @ 81F89AE
	lockall
	playse SE_PIN
	flagasdialog
	applymovement 4, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 4, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement 4, LittlerootTown_MaysHouse_1F_Movement_1F89EC
	waitmovement 0
@	special GetRivalSonDaughterString
	msgbox LittlerootTown_RivalsHouse_1F_Text_1F8BC5, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 2
	releaseall
	end
LittlerootTown_MaysHouse_1F_Movement_1F89EC: @ 81F89EC
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_1F89F3:: @ 81F89F3
LittlerootTown_MaysHouse_1F_EventScript_1F89F3:: @ 81F89F3
	lock
	faceplayer
	flagasdialog
	goto_if_set FLAG_DEFEATED_RIVAL_ROUTE103, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomHeal
	goto_if_set FLAG_SYS_POKEMON_GET, LittlerootTown_BrendansHouse_1F_EventScript_1F8A29
	compare VAR_LITTLEROOT_RIVAL_STATE, 3
	goto_if_eq LittlerootTown_BrendansHouse_1F_EventScript_1F8A1F
@	special GetRivalSonDaughterString
	msgbox LittlerootTown_RivalsHouse_1F_Text_1F8CA5, MSGBOX_DEFAULT
	release
	end
LittlerootTown_RivalsHouse_1F_Text_1F8CA5: @ 81F8CA5
	.string "Like father, like {RIVAL_son}.\p"
	.string "My husband is as wild about Pokémon\n"
	.string "as our little {RIVAL_boy}.\p"
	.string "If he's not at the lab, he's likely\n"
	.string "scrabbling about in grassy places.$"


LittlerootTown_BrendansHouse_1F_EventScript_1F8A1F:: @ 81F8A1F
	msgbox LittlerootTown_RivalsHouse_1F_Text_1F8D37, MSGBOX_DEFAULT
	release
	end
LittlerootTown_RivalsHouse_1F_Text_1F8D37: @ 81F8D37
	.string "That's our {RIVAL_son}!\p"
	.string "I guess {RIVAL_they}'s too busy with\n"
	.string "Pokémon to notice that you came\l"
	.string "to visit, {PLAYER}.$"


LittlerootTown_BrendansHouse_1F_EventScript_1F8A29:: @ 81F8A29
	msgbox LittlerootTown_RivalsHouse_1F_Text_1F8D93, MSGBOX_DEFAULT
	release
	end
LittlerootTown_RivalsHouse_1F_Text_1F8D93: @ 81F8D93
	.string "Oh, {RIVAL} went out to Route 103\n"
	.string "just a little while ago.\p"
	.string "I would be going along with {RIVAL_them}, but\n"
	.string "little Charlie is a little ill today.\p"
	.string "Why don't you go meet {RIVAL_them}?\p"
	.string "You don't seem like the kind of {PLAYER_boy}\n"
	.string "who likes to stay cooped up at home.$"


LittlerootTown_BrendansHouse_1F_EventScript_RivalMomHeal:: @ 81F8A33
	goto_if_set FLAG_TEMP_1F, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomHealGoodbye
	msgbox LittlerootTown_RivalsHouse_1F_Text_1F8E01, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_TEMP_1F
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	call Common_EventScript_OutOfCenterPartyHeal
	goto LittlerootTown_BrendansHouse_1F_EventScript_RivalMomHealGoodbye
	end
LittlerootTown_RivalsHouse_1F_Text_1F8E01: @ 81F8E01
	.string "Oh, {PLAYER}!\n"
	.string "How are you this {TIME_OF_DAY}?\p"
	.string "Have you visited your father recently?\n"
	.string "You know, I don't think I've met him\l"
	.string "yet. Just haven't seen him around.\p"
	.string "You're always free to visit anytime!\n"
	.string "In fact, how about something to eat?$"
LittlerootTown_PlayersHouse_1F_Text_1F7D5C:
	.string "Feel free to drop by again any time!$"
LittlerootTown_BrendansHouse_1F_EventScript_RivalMomHealGoodbye::
	msgbox LittlerootTown_PlayersHouse_1F_Text_1F7D5C, MSGBOX_DEFAULT
	release
	end


LittlerootTown_RivalHouse_1F_EventScript_Charlie:: @ 81F8A3D
	lock
	faceplayer
	flagasdialog
	message LittlerootTown_RivalsHouse_1F_Text_Charlie1
	waitmessage
	checkplayeroutfit
	selectpointer LittlerootTown_RivalsHouse_1F_TextArray_CharlieResponse, VAR_RESULT
	msgbox_selected MSGBOX_DEFAULT
	release
	end
LittlerootTown_RivalsHouse_1F_Text_Charlie1: @ 81F9262
	.string "Charlie: Hi, neighbor!\p"
	.string "Are you part of a gang?\n"
	.string "You look like you're part of a gang!\p"
	.string "$"
LittlerootTown_RivalsHouse_1F_Text_Charlie2a:
	.string "Team Skull? That sounds AWESOME!$"
LittlerootTown_RivalsHouse_1F_Text_Charlie2b:
	.string "What's that bandanna from?\n"
	.string "I think I've seen that on the news!$"
LittlerootTown_RivalsHouse_1F_Text_Charlie2c:
	.string "Team Aqua? Are those the bad guys\n"
	.string "that I see on the news? Wicked!$"
LittlerootTown_RivalsHouse_1F_Text_Charlie2d:
	.string "You're not anymore? Why not?\n"
	.string "Did they do something bad?$"

.align 2
LittlerootTown_RivalsHouse_1F_TextArray_CharlieResponse:
	.4byte LittlerootTown_RivalsHouse_1F_Text_Charlie2a
	.4byte LittlerootTown_RivalsHouse_1F_Text_Charlie2b
	.4byte LittlerootTown_RivalsHouse_1F_Text_Charlie2c
	.4byte LittlerootTown_RivalsHouse_1F_Text_Charlie2d
	.4byte 0

	

LittlerootTown_MaysHouse_1F_EventScript_1F8A4C:: @ 81F8A4C
	lockall
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto LittlerootTown_MaysHouse_1F_EventScript_292765
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A67:: @ 81F8A67
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A73:: @ 81F8A73
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A7F:: @ 81F8A7F
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_MaysHouse_1F_EventScript_1F8A8B
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8A8B:: @ 81F8A8B
	flagasdialog
	playse SE_KAIDAN
	delay 10
	addobject 7
	delay 30
	playse SE_PIN
	applymovement 7, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 7, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_ne LittlerootTown_MaysHouse_1F_EventScript_1F8B2A
	playbgm MUS_GIRL_SUP, 1
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B35
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B40
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B4B
	msgbox LittlerootTown_RivalHouse_1F_Text_1F8EC6, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B6A
	compare VAR_0x8008, 1
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B7C
	compare VAR_0x8008, 2
	call_if_eq LittlerootTown_MaysHouse_1F_EventScript_1F8B8E
	playse SE_KAIDAN
	removeobject 7
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_BRENDAN
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	delay 30
	setvar VAR_LITTLEROOT_RIVAL_STATE, 3
	setvar VAR_0x4050, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_MaysHouse_1F_EventScript_1F8B2A:: @ 81F8B2A
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B35:: @ 81F8B35
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B56
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B40:: @ 81F8B40
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B5E
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B4B:: @ 81F8B4B
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8B62
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_1F8B56: @ 81F8B56
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8B5E: @ 81F8B5E
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8B62: @ 81F8B62
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_EventScript_1F8B6A:: @ 81F8B6A
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F8BA0
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BAF
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B7C:: @ 81F8B7C
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F8BA4
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BB5
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_EventScript_1F8B8E:: @ 81F8B8E
	applymovement EVENT_OBJ_ID_PLAYER, LittlerootTown_MaysHouse_1F_Movement_1F8BAB
	applymovement 7, LittlerootTown_MaysHouse_1F_Movement_1F8BBF
	waitmovement 0
	return

LittlerootTown_MaysHouse_1F_Movement_1F8BA0: @ 81F8BA0
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BA4: @ 81F8BA4
	delay_16
	delay_8
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BAB: @ 81F8BAB
	delay_16
	delay_8
	walk_in_place_fastest_left
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BAF: @ 81F8BAF
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BB5: @ 81F8BB5
	walk_in_place_fastest_right
	walk_right
	walk_in_place_fastest_up
	walk_up
	walk_up
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	step_end

LittlerootTown_MaysHouse_1F_Movement_1F8BBF: @ 81F8BBF
	walk_in_place_fastest_left
	walk_left
	walk_in_place_fastest_up
	walk_up
	walk_up
	step_end

@ -----------------------------------------------------

LittlerootTown_MaysHouse_1F_SignScript_Fridge::
	checkplayergender
	compare VAR_RESULT, FEMALE
	call_if_eq LittlerootTown_PlayerHouse_1F_SignScript_Fridge
	release
	end




LittlerootTown_MaysHouse_1F_Text_1F8EC6: @ 81F8EC6
	.string "Huh?\n"
	.string "Who… Who are you?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "Oh, you're {PLAYER}.\n"
	.string "So your move was today.\p"
	.string "Um… I'm May.\n"
	.string "Glad to meet you!\p"
	.string "I…\n"
	.string "I have this dream of becoming friends\l"
	.string "with Pokémon all over the world.\p"
	.string "I… I heard about you, {PLAYER}, from\n"
	.string "my dad, Prof. Birch.\p"
	.string "I was hoping that you would be nice,\n"
	.string "{PLAYER}, and that we could be friends.\p"
	.string "Oh, this is silly, isn't it?\n"
	.string "I… I've just met you, {PLAYER}.\p"
	.string "Eheheh…\p"
	.string "Oh, no! I forgot!\p"
	.string "I was supposed to go help Dad catch\n"
	.string "some wild Pokémon!\p"
	.string "{PLAYER}, I'll catch you later!$"

LittlerootTown_BrendansHouse_1F_Text_1F90B4: @ 81F90B4
	.string "Hey!\n"
	.string "You…\p"
	.string "Who are you?\p"
	.string "Oh, you're {PLAYER}, aren't you?\n"
	.string "Moved in next door, right?\p"
	.string "I didn't know that you're a girl.\p"
	.string "Dad, Prof. Birch, said that our new\n"
	.string "next-door neighbor is a Gym Leader's\l"
	.string "kid, so I assumed you'd be a guy.\p"
	.string "My name's Brendan.\n"
	.string "So, hi, neighbor!\p"
	.string "Huh? Hey, {PLAYER}, don't you have\n"
	.string "a Pokémon?\p"
	.string "Do you want me to go catch you one?\p"
	.string "Aw, darn, I forgot…\p"
	.string "I'm supposed to go help my dad catch\n"
	.string "some wild Pokémon.\p"
	.string "Some other time, okay?$"


