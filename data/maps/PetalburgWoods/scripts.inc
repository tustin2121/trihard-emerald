PetalburgWoods_MapScripts:: @ 822DFD6
	.byte 0

@ -----------------------------------------------------
@ Signs

PetalburgWoods_SignScript_TrainerTips1:: @ 822E25B
	msgbox PetalburgWoods_Text_22EC10, MSGBOX_DESCRIBE
	end
PetalburgWoods_Text_22EC10: @ 822EC10
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "Any Pokémon that appears even once\n"
	.string "in a battle is awarded EXP Points.\p"
	.string "To raise a weak Pokémon, put it at the\n"
	.string "left of the team list.\p"
	.string "As soon as a battle starts, switch it\n"
	.string "out. It will earn EXP Points without\l"
	.string "being exposed to any harm.$"

PetalburgWoods_SignScript_TrainerTips2:: @ 822E264
	msgbox PetalburgWoods_Text_22ED07, MSGBOX_DESCRIBE
	end
PetalburgWoods_Text_22ED07: @ 822ED07
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "In addition to Hit Points (HP), Pokémon\n"
	.string "have Power Points (PP) that are used to\l"
	.string "make moves during battle.\p"
	.string "If a Pokémon runs out of PP, it must be\n"
	.string "taken to a Pokémon Center.$"

@ -----------------------------------------------------
@ People

PetalburgWoods_EventScript_TallGrassBoy:: @ 822E210
	msgbox PetalburgWoods_Text_22EA0C, MSGBOX_NPC
	end
PetalburgWoods_Text_22EA0C: @ 822EA0C
	.string "Yo, there!\n"
	.string "Your Pokémon doing okay?\p"
	.string "If your Pokémon are weak and you want\n"
	.string "to avoid battles, you should stay out\l"
	.string "of tall grass.$"


PetalburgWoods_EventScript_HiddenItemBoy:: @ 822E219
	msgbox PetalburgWoods_Text_22EA8B, MSGBOX_NPC
	end
PetalburgWoods_Text_22EA8B: @ 822EA8B
	.string "Sometimes, there are things on the\n"
	.string "ground even if you can't see them.\p"
	.string "That's why I always check where I'm\n"
	.string "walking.$"


PetalburgWoods_EventScript_SeedGirl:: @ 822E222
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_22E251
	msgbox PetalburgWoods_Text_22EAFE, MSGBOX_DEFAULT
	giveitem_std ITEM_MIRACLE_SEED
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end
PetalburgWoods_Text_22EAFE: @ 822EAFE
	.string "Oh, neat!\n"
	.string "That's the badge from Rustboro Gym!\p"
	.string "You must be a trainer.\n"
	.string "You should try using this item.$"
PetalburgWoods_EventScript_22E251:: @ 822E251
	msgbox PetalburgWoods_Text_22EB63, MSGBOX_DEFAULT
	release
	end
PetalburgWoods_Text_22EB63: @ 822EB63
	.string "It's a Miracle Seed.\n"
	.string "If a Pokémon holds that item, its\l"
	.string "GRASS-type moves become stronger.\p"
	.string "Besides Miracle Seed, I think there are\n"
	.string "other convenient items for Pokémon\l"
	.string "to hold.$"

@ -----------------------------------------------------
@ Trainer

PetalburgWoods_TrainerScript_Lyle:: @ 822E26D
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_22E77D, PetalburgWoods_Text_22E7C1
	msgbox PetalburgWoods_Text_22E7EF, MSGBOX_AUTOCLOSE
	end
PetalburgWoods_Text_22E77D: @ 822E77D
	.string "I caught a whole bunch of Pokémon!\p"
	.string "Go, go, go!\n"
	.string "My Bug Pokémon team!$"
PetalburgWoods_Text_22E7C1: @ 822E7C1
	.string "I have all these Pokémon,\n"
	.string "but I couldn't win…$"
PetalburgWoods_Text_22E7EF: @ 822E7EF
	.string "I caught a bunch of Pokémon.\n"
	.string "Now I'm out of Poké Balls.$"



PetalburgWoods_TrainerScript_James:: @ 822E284
	trainerbattle_single TRAINER_JAMES_1, PetalburgWoods_Text_22E827, PetalburgWoods_Text_22E86B, PetalburgWoods_EventScript_22E2C5
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq PetalburgWoods_EventScript_22E31B
	msgbox PetalburgWoods_Text_22E889, MSGBOX_DEFAULT
	release
	end
PetalburgWoods_Text_22E827: @ 822E827
	.string "If you take Bug Pokémon to school,\n"
	.string "you get to be instantly popular!$"
PetalburgWoods_Text_22E86B: @ 822E86B
	.string "I can't be popular if I lose.$"
PetalburgWoods_Text_22E889: @ 822E889
	.string "If you have a big Bug Pokémon,\n"
	.string "people respect you for it.$"
PetalburgWoods_EventScript_22E2C5:: @ 822E2C5
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox PetalburgWoods_Text_22E8C3, MSGBOX_DEFAULT
	register_matchcall TRAINER_JAMES_1
	release
	end
PetalburgWoods_Text_22E8C3: @ 822E8C3
	.string "I want a rematch when my Bug\n"
	.string "Pokémon grow up!\p"
	.string "I'm registering you in my PokéNav!$"
PetalburgWoods_EventScript_22E31B:: @ 822E31B
	trainerbattle_rematch TRAINER_JAMES_1, PetalburgWoods_Text_22E966, PetalburgWoods_Text_22E998
	msgbox PetalburgWoods_Text_22E9B6, MSGBOX_AUTOCLOSE
	end
PetalburgWoods_Text_22E966: @ 822E966
	.string "My Bug Pokémon have grown.\n"
	.string "I'll be popular again.$"
PetalburgWoods_Text_22E998: @ 822E998
	.string "I can't be popular if I lose.$"
PetalburgWoods_Text_22E9B6: @ 822E9B6
	.string "You get to be popular if you have\n"
	.string "strong Pokémon, right?\l"
	.string "So, I've been training hard.$"


@ -----------------------------------------------------
@ Devon Cutscene

PetalburgWoods_TriggerScript_DevonAttack_Left::
	lockall
	setvar VAR_0x800B, 0
	goto PetalburgWoods_EventScript_DevonAttack
	end
PetalburgWoods_TriggerScript_DevonAttack_Right::
	lockall
	setvar VAR_0x800B, 1
	goto PetalburgWoods_EventScript_DevonAttack
	end

#define LID_DEVON 4
#define LID_BAD 3
#define LID_PLAYER EVENT_OBJ_ID_PLAYER

PetalburgWoods_EventScript_DevonAttack:: @ 822E079
	lockall
	markasdialog
	applymovement LID_DEVON, PetalburgWoods_Movement_LookAround
	waitmovement 0
	@ "Not one to be found..."
	msgbox PetalburgWoods_Text_22E332, MSGBOX_DEFAULT
	closemessage
	selectpointer_from VAR_0x800B, PetalburgWoods_Movement_22E1CB, PetalburgWoods_Movement_22E1CC
	applymovement LID_PLAYER, 0
	applymovement LID_DEVON, PetalburgWoods_Movement_22E1D0
	waitmovement 0
	@ "Seen any Shroomish?"
	setyesnotext gYN_Uhhh, gYN_NoQuestion
	msgbox PetalburgWoods_Text_22E34F, MSGBOX_YESNO
	closemessage
	@ Play Evil Team music
	playbgm MUS_MGM0, 0
	applymovement LID_BAD, PetalburgWoods_Movement_22E209
	waitmovement 0
	@ "I got sick of waiting"
	msgbox PetalburgWoods_Text_22E3AA, MSGBOX_DEFAULT
	closemessage
	applymovement LID_BAD, PetalburgWoods_Movement_22E205
	waitmovement 0
	applymovement LID_DEVON, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@ "Hand over those papers!"
	msgbox PetalburgWoods_Text_22E428, MSGBOX_DEFAULT
	closemessage
	applymovement LID_DEVON, PetalburgWoods_Movement_22E1EA
	applymovement LID_PLAYER, PetalburgWoods_Movement_22E1EB
	waitmovement 0
	@ "Aiee! Help!"
	msgbox PetalburgWoods_Text_22E457, MSGBOX_DEFAULT
	closemessage
	@ player tries to dodge out of the way
	special SpawnCameraObject
	applymovement LID_PLAYER, PetalburgWoods_Movement_PlayerDance
	applymovement LID_DEVON, PetalburgWoods_Movement_DevonDance
	waitmovement 0
	applymovement LID_BAD, PetalburgWoods_Movement_22EE4AD
	waitmovement 0
	applymovement LID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	special RemoveCameraObject
	@ "You going to protect him?"
	msgbox PetalburgWoods_Text_22E4A5, MSGBOX_DEFAULT
	@ Trainer Battle!
	trainerbattle_no_intro TRAINER_GRUNT_8, PetalburgWoods_Text_22E542
	applymovement LID_BAD, PetalburgWoods_Movement_22E1F9
	waitmovement 0
	@ "You've got some nerve!"
	msgbox PetalburgWoods_Text_22E563, MSGBOX_DEFAULT
	closemessage
	applymovement LID_BAD, PetalburgWoods_Movement_22E1FD
	waitmovement 0
	removeobject LID_BAD
	applymovement LID_DEVON, PetalburgWoods_Movement_22E1FE
	applymovement LID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	@ "Thanks! Here's a great ball!"
	msgbox PetalburgWoods_Text_22E63D, MSGBOX_DEFAULT
	giveitem_std ITEM_GREAT_BALL
	compare VAR_RESULT, 0
	@ "Too many things"
	call_if_eq PetalburgWoods_EventScript_22E17D
	@ "Wait, were they in Rustoboro?"
	msgbox PetalburgWoods_Text_22E6C7, MSGBOX_DEFAULT
	applymovement LID_DEVON, PetalburgWoods_Movement_22E1EE
	waitmovement 0
	@ "Augh, crisis!"
	msgbox PetalburgWoods_Text_22E712, MSGBOX_DEFAULT
	closemessage
	applymovement LID_PLAYER, PetalburgWoods_Movement_22E1E0
	applymovement LID_DEVON, PetalburgWoods_Movement_22E1C2
	waitmovement 0
	removeobject LID_DEVON
	setvar VAR_PETALBURG_WOODS_STATE, 1
	releaseall
	end
PetalburgWoods_EventScript_22E17D:: @ 822E17D
	msgbox PetalburgWoods_Text_22E741, MSGBOX_DEFAULT
	end

#undef LID_DEVON
#undef LID_BAD
#undef LID_PLAYER

PetalburgWoods_Movement_LookAround: @ 822E1B1
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end
PetalburgWoods_Text_22E332: @ 822E332
	.string "Hmmm…\n"
	.string "Not a one to be found…$"
PetalburgWoods_Movement_22E1CB:
	delay_16
	delay_16
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end
PetalburgWoods_Movement_22E1CC:
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end
@ PetalburgWoods_Movement_22E1CB: @ 822E1CB
@ 	delay_16
@ 	face_player
@ 	walk_down
@ 	walk_down
@ 	step_end
PetalburgWoods_Movement_22E1D0: @ 822E1D0
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_right
	step_end
PetalburgWoods_Text_22E34F: @ 822E34F
	.string "Hello, have you seen any Pokémon\n"
	.string "called Shroomish around here?\l"
	.string "I really love that Pokémon.$"
PetalburgWoods_Movement_22E209: @ 822E209
	walk_down
	walk_down
	delay_16
	delay_16
	step_end
PetalburgWoods_Text_22E3AA: @ 822E3AA
	.string "I was going to ambush you, but you\n"
	.string "had to dawdle in Petalburg Woods\l"
	.string "forever, didn't you?\p"
	.string "I got sick of waiting, so here I am!$"
@ PetalburgWoods_Movement_22E1F6: @ 822E1F6
@ 	walk_fast_down
@ 	walk_fast_down
@ 	step_end
PetalburgWoods_Movement_22E205: @ 822E205
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
PetalburgWoods_Text_22E428: @ 822E428
	.string "You! Devon Researcher!\p"
	.string "Hand over those papers!$"
@ PetalburgWoods_Movement_22E1E4: @ 822E1E4
@ 	walk_fast_right
@ 	walk_fast_down
@ 	walk_fast_down
@ 	walk_fast_left
@ 	walk_in_place_fastest_up
@ 	step_end
PetalburgWoods_Movement_22E1EA: @ 822E1EA
	walk_fast_down
	walk_fast_right
	walk_in_place_fastest_up
	step_end
PetalburgWoods_Movement_22E1EB: @ 822E1EA
	delay_16
	emote_exclamation_mark
	walk_in_place_fastest_down
	step_end
PetalburgWoods_Text_22E457: @ 822E457
	.string "Aiyeeeh!\p"
	.string "You're a Pokémon Trainer, aren't you?\n"
	.string "You've got to help me, please!$"
PetalburgWoods_Movement_PlayerDance:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_fastest_down
	delay_16
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	delay_8
	walk_in_place_fastest_down
	delay_8
	lock_facing_direction
	walk_left
	delay_8
	walk_fast_right
	delay_8
	walk_fast_left
	delay_8
	walk_fast_right
	delay_8
	unlock_facing_direction
	face_left
	step_end
PetalburgWoods_Movement_DevonDance:
	delay_16
	emote_exclamation_mark
	face_left
	delay_16
	delay_16
	delay_16
	walk_fast_left
	walk_in_place_fastest_up
	delay_16
	delay_16
	walk_fast_right
	walk_in_place_fastest_up
	delay_16
	delay_8
	lock_facing_direction
	walk_fast_left
	delay_16
	walk_fast_right
	delay_8
	walk_fast_left
	unlock_facing_direction
	delay_4
	step_end
PetalburgWoods_Movement_22EE4AD:
	walk_fast_right
	walk_in_place_fastest_down
	step_end
PetalburgWoods_Text_22E4A5: @ 822E4A5
	@ .string "Hunh? What do you think you're doing?\n"
	.string "What, you gonna to protect him?\p"
	.string "No one who crosses Team Magma\n"
	.string "gets any mercy!\p"
	.string "Come on and battle me!$"
PetalburgWoods_Text_22E542: @ 822E542
	.string "You're kidding me! You're tough!$"
PetalburgWoods_Movement_22E1F9: @ 822E1F9
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end
PetalburgWoods_Text_22E563: @ 822E563
	.string "Grrr… You've got some nerve\n"
	.string "meddling with Team Magma!\l"
	.string "Come on and battle me again!\p"
	.string "Stop laughing!\n"
	.string "I know I'm outta Pokémon!\p"
	.string "Whatever, I gotta get back to my\n"
	.string "posse anyway. Gotta get that thing\l"
	.string "in Rustboro. I'll let you go today!$"
PetalburgWoods_Movement_22E1FD: @ 822E1FD
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end
PetalburgWoods_Movement_22E1FE:
	walk_up
	walk_in_place_fastest_right
	step_end
PetalburgWoods_Text_22E63D: @ 822E63D
	.string "Whew…\n"
	.string "That was awfully close!\p"
	.string "Thanks to you, he didn't rob me of\n"
	.string "these important papers.\p"
	.string "I know, I'll give you a Great Ball as\n"
	.string "my thanks!$"
PetalburgWoods_Text_22E741: @ 822E741
	.string "You're loaded with items.\n"
	.string "I can't give you this Great Ball.$"
PetalburgWoods_Text_22E6C7: @ 822E6C7
	.string "Didn't that Team Magma thug say\n"
	.string "they were after something in\l"
	.string "Rustboro, too?$"
PetalburgWoods_Movement_22E1EE: @ 822E1EE
	walk_in_place_fastest_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_right
	step_end
PetalburgWoods_Text_22E712: @ 822E712
	.string "Uh-oh! It's a crisis!\n"
	.string "I can't be wasting time!$"
PetalburgWoods_Movement_22E1C2: @ 822E1C2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
PetalburgWoods_Movement_22E1E0: @ 822E1E0
	delay_16
	delay_16
	walk_in_place_fastest_up
	step_end
