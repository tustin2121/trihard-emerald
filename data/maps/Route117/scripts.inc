Route117_MapScripts:: @ 81F397D
	map_script MAP_SCRIPT_ON_RESUME, Route117_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_OnTransition
	.byte 0

Route117_OnTransition: @ 81F3983
	call Route117_EventScript_1F3989
	end

Route117_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route117_EventScript_Kecleon_MonCaughtCheck
	end

Route117_EventScript_1F3989:: @ 81F3989
@	goto_if_unset FLAG_PENDING_DAYCARE_EGG, Route117_EventScript_1F3999
@	setobjectxyperm 3, 47, 6

Route117_EventScript_1F3999:: @ 81F3999
	return

@ -----------------------------------------------------
@ People

Route117_EventScript_FlowerGirl:: @ 81F399A
	msgbox Route117_Text_1F3CFD, MSGBOX_NPC
	end
Route117_Text_1F3CFD: @ 81F3CFD
	.string "What do you think?\n"
	.string "Aren't these flowers pretty?\p"
	.string "I planted them all!$"


Route117_EventScript_TastyAirBoy:: @ 81F39A3
	msgbox Route117_Text_1F3D41, MSGBOX_NPC
	end
Route117_Text_1F3D41: @ 81F3D41
	.string "The air is tasty here!$"


Route117_EventScript_GirlNearDaycare:: @ 81F39AC
	msgbox Route117_Text_1F3C7C, MSGBOX_NPC
	end
Route117_Text_1F3C7C: @ 81F3C7C
	.string "I used to leave my Pokémon at the\n"
	.string "Day Care. But recently the owners were\l"
	.string "arrested on allegations of malpractice.\p"
	.string "I was really, really surprised.\n"
	.string "They didn't seem like bad people…$"


Route117_EventScript_Policeman::
	lock
	faceplayer
	message Route117_Text_Policeman
	waitmessage
	waitbuttonpress
	closemessage
	compare VAR_FACING, DIR_WEST @player is talking to him from east
	goto_if_ne Route117_EventScript_Policeman_WalkAway
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	applymovement THIS_EVENT, Route117_Movement_Policeman_WalkDown
	waitmovement 0
	@fallthrough
Route117_EventScript_Policeman_WalkAway:
	applymovement EVENT_OBJ_ID_PLAYER, Route117_Movement_Policeman_WatchWalkAway
	applymovement THIS_EVENT, Route117_Movement_Policeman_WalkAway
	waitmovement 0
	removeobject THIS_EVENT
	release
	end
Route117_Text_Policeman:
	.string "Nothing to see here.\nMove along.\p"
	.string "Oh… Are you in some kind of gang?\n"
	.string "Those look like gang colors.\p"
	.string "Please stay out of trouble.$"
Route117_Movement_Policeman_WalkDown:
	walk_down
	step_end
Route117_Movement_Policeman_WalkAway:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
Route117_Movement_Policeman_WatchWalkAway:
	delay_16
	delay_16
	face_right
	step_end
	

Route117_EventScript_Kecleon:: @ 81E2614
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE, 1
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_Kecleon_ScopeAsk
	msgbox Route117_Text_Kecleon1, MSGBOX_DEFAULT
	release
	end
Route117_Text_Kecleon1: @ 81E29E5
	.string "Something unseeable is in the way.$"
Route117_EventScript_Kecleon_ScopeAsk:: @ 81E2630
	msgbox Route117_Text_Kecleon2, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_Kecleon_ScopeUsed
	release
	end
Route117_Text_Kecleon2: @ 81E2A08
	.string "Something unseeable is in the way.\p"
	.string "Want to use the DEVON SCOPE?$"
Route117_EventScript_Kecleon_ScopeUsed:: @ 81E2645
	msgbox Route117_Text_1E2A48, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_KecleonShowAnim
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, 2
	delay 40
	waitmoncry
	setwildbattle SPECIES_KECLEON, 30, ITEM_NONE
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	@ Check outcome, remove kecleon if won
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_eq Route117_EventScript_Kecleon_MonVanishes
	compare VAR_RESULT, B_OUTCOME_RAN
	goto_if_eq Route117_EventScript_Kecleon_MonVanishes
	compare VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED
	goto_if_eq Route117_EventScript_Kecleon_MonVanishes
	release
	end
Route117_Text_1E2A48: @ 81E2A48
	.string "{PLAYER} used the DEVON SCOPE.\p"
	.string "An invisible Pokémon became completely\n"
	.string "visible!\p"
	.string "The startled Pokémon attacked!$"
Route117_EventScript_Kecleon_MonVanishes:
	fadescreenswapbuffers 1
	removeobject VAR_LAST_TALKED
	fadescreenswapbuffers 0
	release
	end
Route117_EventScript_Kecleon_MonCaughtCheck:
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return



@ -----------------------------------------------------
@ Signs

Route117_EventScript_RoadSignWest:: @ 81F39B5
	msgbox Route117_Text_1F3D58, MSGBOX_SIGN
	end
Route117_Text_1F3D58: @ 81F3D58
	.string "Route 117\n"
	.string "{LEFT_ARROW} Verdanturf Town$"


Route117_EventScript_RoadSignEast:: @ 81F39BE
	msgbox Route117_Text_1F3D74, MSGBOX_SIGN
	end
Route117_Text_1F3D74: @ 81F3D74
	.string "Route 117\n"
	.string "{RIGHT_ARROW} Mauville City$"


Route117_EventScript_DaycareSign:: @ 81F39C7
	lockall
	message3 Route117_Text_DaycareSign1
	waitmessage
	waitbuttonpress
	message Route117_Text_DaycareSign2
	waitmessage
	waitbuttonpress
	releaseall
	end
Route117_Text_DaycareSign1: @ 81F3D8E
	.string "{PLACE}Pokémon Day Care{END}\n"
	.string "“Let us raise your Pokémon.”$"
Route117_Text_DaycareSign2:
	.string "There's a noticed pinned on the sign\n"
	.string "just below those words:\l"
	.string "“Closed pending police investigation.”$"


Route117_EventScript_DaycareDoor:: @ 81F39C7
	msgbox Route117_Text_DaycareDoor, MSGBOX_DESCRIBE
	end
Route117_Text_DaycareDoor:
	.string "The door's locked.\p"
	.string "There's a sign in the window:\n"
	.string "“Closed pending police investigation.”$"


@ -----------------------------------------------------
@ Trainers

Route117_TrainerScript_Issac:: @ 81F39D0
	trainerbattle_single TRAINER_ISAAC_1, Route117_Text_29C43F, Route117_Text_29C47A, Route117_EventScript_1F39FC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3A1B
	msgbox Route117_Text_29C498, MSGBOX_DEFAULT
	release
	end
Route117_Text_29C43F: @ 829C43F
	.string "Listen, could I get you to battle\n"
	.string "the Pokémon I'm raising?$"
Route117_Text_29C47A: @ 829C47A
	.string "You've raised yours superbly…$"
Route117_Text_29C498: @ 829C498
	.string "Pokémon isn't all about power.\p"
	.string "Polishing a unique aspect of one's\n"
	.string "character is another way of enjoying\l"
	.string "Pokémon.$"
Route117_EventScript_1F39FC:: @ 81F39FC
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29C508, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISAAC_1
	release
	end
Route117_Text_29C508: @ 829C508
	.string "I'm going to redouble my training.\n"
	.string "Would you come look in on us?$"
Route117_EventScript_1F3A1B:: @ 81F3A1B
	trainerbattle_rematch TRAINER_ISAAC_1, Route117_Text_29C549, Route117_Text_29C58B
	msgbox Route117_Text_29C5D0, MSGBOX_AUTOCLOSE
	end
Route117_Text_29C549: @ 829C549
	.string "The Pokémon I've been raising are\n"
	.string "looking good, just like before.$"
Route117_Text_29C58B: @ 829C58B
	.string "You know how to raise them properly.\n"
	.string "You might have DAY CARE skills…$"
Route117_Text_29C5D0: @ 829C5D0
	.string "Your Pokémon are growing good!\n"
	.string "You should enter them in CONTESTS.$"


Route117_TrainerScript_Lydia:: @ 81F3A32
	trainerbattle_single TRAINER_LYDIA_1, Route117_Text_29C612, Route117_Text_29C659, Route117_EventScript_1F3A5E
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3A7D
	msgbox Route117_Text_29C679, MSGBOX_DEFAULT
	release
	end
Route117_Text_29C612: @ 829C612
	.string "Please, allow me to evaluate if you\n"
	.string "have raised your Pokémon properly.$"
Route117_Text_29C659: @ 829C659
	.string "Yes, they are growing properly.$"
Route117_Text_29C679: @ 829C679
	.string "Try raising Pokémon with more\n"
	.string "attention to their character traits.$"
Route117_EventScript_1F3A5E:: @ 81F3A5E
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29C6BC, MSGBOX_DEFAULT
	register_matchcall TRAINER_LYDIA_1
	release
	end
Route117_Text_29C6BC: @ 829C6BC
	.string "I'm glad I met a superb TRAINER in you.\n"
	.string "I hope to see you again.$"
Route117_EventScript_1F3A7D:: @ 81F3A7D
	trainerbattle_rematch TRAINER_LYDIA_1, Route117_Text_29C6FD, Route117_Text_29C73E
	msgbox Route117_Text_29C75A, MSGBOX_AUTOCLOSE
	end
Route117_Text_29C6FD: @ 829C6FD
	.string "Allow me to reevaluate if you have\n"
	.string "raised your Pokémon properly.$"
Route117_Text_29C73E: @ 829C73E
	.string "They are growing admirably.$"
Route117_Text_29C75A: @ 829C75A
	.string "Pokémon seem to like different kinds\n"
	.string "of {POKEBLOCK}S, depending on their nature.$"


Route117_TrainerScript_Dylan:: @ 81F3A94
	trainerbattle_single TRAINER_DYLAN_1, Route117_Text_29C7A5, Route117_Text_29C7EB, Route117_EventScript_1F3AC0
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3ADF
	msgbox Route117_Text_29C800, MSGBOX_DEFAULT
	release
	end
Route117_Text_29C7A5: @ 829C7A5
	.string "I'm in the middle of a triathlon, but,\n"
	.string "whatever, let's have a battle!$"
Route117_Text_29C7EB: @ 829C7EB
	.string "I ran out of energy!$"
Route117_Text_29C800: @ 829C800
	.string "I may have blown it…\p"
	.string "I might have dropped to last during\n"
	.string "that battle…$"
Route117_EventScript_1F3AC0:: @ 81F3AC0
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29C846, MSGBOX_DEFAULT
	register_matchcall TRAINER_DYLAN_1
	release
	end
Route117_Text_29C846: @ 829C846
	.string "Pokémon have to be strong, too?\n"
	.string "I'd like you to train me!$"
Route117_EventScript_1F3ADF:: @ 81F3ADF
	trainerbattle_rematch TRAINER_DYLAN_1, Route117_Text_29C880, Route117_Text_29C8E3
	msgbox Route117_Text_29C8FE, MSGBOX_AUTOCLOSE
	end
Route117_Text_29C880: @ 829C880
	.string "I'm smack in the middle of a triathlon,\n"
	.string "but I'm comfortably ahead.\l"
	.string "Let's make this a quick battle!$"
Route117_Text_29C8E3: @ 829C8E3
	.string "I ran out of energy again!$"
Route117_Text_29C8FE: @ 829C8FE
	.string "I was tops in swimming and cycling,\n"
	.string "but I'm not quite that confident with\l"
	.string "Pokémon yet.$"


Route117_TrainerScript_Maria:: @ 81F3AF6
	trainerbattle_single TRAINER_MARIA_1, Route117_Text_29C955, Route117_Text_29C9A6, Route117_EventScript_1F3B22
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3B41
	msgbox Route117_Text_29C9D0, MSGBOX_DEFAULT
	release
	end
Route117_Text_29C955: @ 829C955
	.string "I do my triathlon training with Pokémon,\n"
	.string "so I'm pretty confident about my speed.$"
Route117_Text_29C9A6: @ 829C9A6
	.string "I need to get more practices in,\n"
	.string "I guess.$"
Route117_Text_29C9D0: @ 829C9D0
	.string "Training is meaningful only if you\n"
	.string "keep it up regularly.\p"
	.string "Okay! I'll resume my training!\n"
	.string "Tomorrow!$"
Route117_EventScript_1F3B22:: @ 81F3B22
	special sub_80B4808
	waitmovement 0
	msgbox Route117_Text_29CA32, MSGBOX_DEFAULT
	register_matchcall TRAINER_MARIA_1
	release
	end
Route117_Text_29CA32: @ 829CA32
	.string "You appear to be training properly…\n"
	.string "If you'd like, I'll battle you later!$"
Route117_EventScript_1F3B41:: @ 81F3B41
	trainerbattle_rematch TRAINER_MARIA_1, Route117_Text_29CA7C, Route117_Text_29CACC
	msgbox Route117_Text_29CAF6, MSGBOX_AUTOCLOSE
	end
Route117_Text_29CA7C: @ 829CA7C
	.string "Are you keeping up with your training?\n"
	.string "I sure am!\l"
	.string "Let me show you the evidence!$"
Route117_Text_29CACC: @ 829CACC
	.string "I need to get more practices in,\n"
	.string "I guess.$"
Route117_Text_29CAF6: @ 829CAF6
	.string "I'll resume training tomorrow.\n"
	.string "Let's battle again sometime!$"


Route117_TrainerScript_Derek:: @ 81F3B58
	trainerbattle_single TRAINER_DEREK, Route117_Text_29CB32, Route117_Text_29CB87
	msgbox Route117_Text_29CBAD, MSGBOX_AUTOCLOSE
	end
Route117_Text_29CB32: @ 829CB32
	.string "Once a Bug Catcher!\n"
	.string "And now a Bug Maniac!\p"
	.string "But my love for Pokémon remains\n"
	.string "unchanged!$"
Route117_Text_29CB87: @ 829CB87
	.string "My ineptitude also remains\n"
	.string "unchanged…$"
Route117_Text_29CBAD: @ 829CBAD
	.string "All I did was follow my heart, and now\n"
	.string "they call me a Bug Maniac…\p"
	.string "Still, I am an expert on Bug Pokémon,\n"
	.string "so it's only natural that they call me\l"
	.string "a Bug Maniac.$"


Route117_TrainerScript_Anna:: @ 81F3B6F
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CC4A, Route117_Text_29CC8E, Route117_Text_29CD61, Route117_EventScript_1F3B9F
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3BB8
	msgbox Route117_Text_29CCCB, MSGBOX_DEFAULT
	release
	end
Route117_Text_29CC4A: @ 829CC4A
	.string "Anna: I'm with my pretty junior student\n"
	.string "partner. I have to do good!$"
Route117_Text_29CC8E: @ 829CC8E
	.string "Anna: I'm with my pretty junior student\n"
	.string "partner! Let me win!$"
Route117_Text_29CCCB: @ 829CCCB
	.string "Anna: Your Pokémon have some good\n"
	.string "combinations.\p"
	.string "I'd say you're second only to us!$"
Route117_Text_29CD61: @ 829CD61
	.string "Anna: If you want to battle us,\n"
	.string "bring two Pokémon with you.$"
Route117_EventScript_1F3B9F:: @ 81F3B9F
	msgbox Route117_Text_29CD1D, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end
Route117_Text_29CD1D: @ 829CD1D
	.string "Anna: We can't take this lying down!\n"
	.string "You will come back, won't you?$"
Route117_EventScript_1F3BB8:: @ 81F3BB8
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CEB6, Route117_Text_29CEF6, Route117_Text_29CD61
	msgbox Route117_Text_29CF1C, MSGBOX_AUTOCLOSE
	end
Route117_Text_29CEB6: @ 829CEB6
	.string "Anna: I can't keep losing in front of\n"
	.string "my junior partner, right?$"
Route117_Text_29CEF6: @ 829CEF6
	.string "Anna: I couldn't get into the groove.$"
Route117_Text_29CF1C: @ 829CF1C
	.string "Anna: Your Pokémon have some good\n"
	.string "combinations.\p"
	.string "I'd say you're second only to us!$"

Route117_TrainerScript_Meg:: @ 81F3BD3
	trainerbattle_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CD9D, Route117_Text_29CDE9, Route117_Text_29CE52, Route117_EventScript_1F3C03
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route117_EventScript_1F3C1C
	msgbox Route117_Text_29CE17, MSGBOX_DEFAULT
	release
	end
Route117_Text_29CD9D: @ 829CD9D
	.string "Meg: I'm going to tag up with my super\n"
	.string "senior student partner and beat you!$"
Route117_Text_29CDE9: @ 829CDE9
	.string "Meg: Oh, no!\n"
	.string "I'm sorry, Anna! I let you down…$"
Route117_Text_29CE17: @ 829CE17
	.string "Meg: I dragged Anna down…\n"
	.string "If I didn't, she would have won!$"
Route117_Text_29CE52: @ 829CE52
	.string "Meg: Do you only have one Pokémon?\n"
	.string "We can't battle with you, then.\p"
	.string "We want to have a 2-on-2 battle.$"
Route117_EventScript_1F3C03:: @ 81F3C03
	msgbox Route117_Text_29CD1D, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANNA_AND_MEG_1
	release
	end
Route117_EventScript_1F3C1C:: @ 81F3C1C
	trainerbattle_rematch_double TRAINER_ANNA_AND_MEG_1, Route117_Text_29CFAA, Route117_Text_29CFED, Route117_Text_29CE52
	msgbox Route117_Text_29CFFE, MSGBOX_AUTOCLOSE
	end
Route117_Text_29CFAA: @ 829CFAA
	.string "Meg: I'm going to tag up with my\n"
	.string "senior partner and win this time!$"
Route117_Text_29CFED: @ 829CFED
	.string "Meg: Too strong!$"
Route117_Text_29CFFE: @ 829CFFE
	.string "Meg: I battled together with my\n"
	.string "senior partner, but we lost…\p"
	.string "That's so discouraging…$"


Route117_TrainerScript_Melina:: @ 81F3C37
	trainerbattle_single TRAINER_MELINA, Route117_Text_29D0B7, Route117_Text_29D0F1
	msgbox Route117_Text_29D10E, MSGBOX_AUTOCLOSE
	end
Route117_Text_29D0B7: @ 829D0B7
	.string "Isn't it nice? To battle while looking\n"
	.string "at pretty flowers?$"
Route117_Text_29D0F1: @ 829D0F1
	.string "Oh, that's quite impressive!$"
Route117_Text_29D10E: @ 829D10E
	.string "It feels wonderful to go for a jog\n"
	.string "while looking at flowers.$"


Route117_TrainerScript_Brandi:: @ 81F3C4E
	trainerbattle_single TRAINER_BRANDI, Route117_Text_29D14B, Route117_Text_29D189
	msgbox Route117_Text_29D196, MSGBOX_AUTOCLOSE
	end
Route117_Text_29D14B: @ 829D14B
	.string "Let me demonstrate the power\n"
	.string "hidden within a Psychic Pokémon!$"
Route117_Text_29D189: @ 829D189
	.string "Astonishing!$"
Route117_Text_29D196: @ 829D196
	.string "Psychic Pokémon are complex.\n"
	.string "You should try catching some.$"


Route117_TrainerScript_Aisha:: @ 81F3C65
	trainerbattle_single TRAINER_AISHA, Route117_Text_29D1D1, Route117_Text_29D206
	msgbox Route117_Text_29D24C, MSGBOX_AUTOCLOSE
	end
Route117_Text_29D1D1: @ 829D1D1
	.string "Concentrate on getting the win.\n"
	.string "That's how I battle!$"
Route117_Text_29D206: @ 829D206
	.string "I don't waste any time being angry\n"
	.string "over a loss--I would rather train.$"
Route117_Text_29D24C: @ 829D24C
	.string "I think that if you worry about losing,\n"
	.string "you're more likely to lose.$"

