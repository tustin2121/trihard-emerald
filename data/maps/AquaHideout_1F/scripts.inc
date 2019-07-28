AquaHideout_1F_MapScripts:: @ 8233493
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, AquaHideout_1F_OnLoad
	.byte 0

@ -----------------------------------------------------

AquaHideout_1F_OnLoad:
	call_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_OnLoad_MoveDoorGuard
	end

AquaHideout_1F_OnLoad_MoveDoorGuard:
	setobjectxyperm 2, 24, 3
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_LEFT
	return

@ -----------------------------------------------------

AquaHideout_1F_OnTransition:
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	end

@ -----------------------------------------------------
@ Bailey

AquaHideout_1F_EventScript_Bailey:: @ 8233494
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334BC
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334B2
	msgbox AquaHideout_1F_Text_23351D, MSGBOX_DEFAULT
	release
	end
AquaHideout_1F_Text_23351D: @ 823351D
	.string "What? What? What do you want with \n"
	.string "Team Aqua?\p"
	.string "Our BOSS isn't here! He's gone off to\n"
	.string "snatch something important!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"

AquaHideout_1F_EventScript_2334B2:: @ 82334B2
	msgbox AquaHideout_1F_Text_2335E3, MSGBOX_DEFAULT
	release
	end
AquaHideout_1F_Text_2335E3: @ 82335E3
	.string "What? What?\n"
	.string "Are you a Team Magma grunt?\p"
	.string "I hear that Team Magma is trying to\n"
	.string "awaken an awesome Pokémon at their\l"
	.string "HIDEOUT.\p"
	.string "But where might their HIDEOUT be?$"

AquaHideout_1F_EventScript_2334BC:: @ 82334BC
	msgbox AquaHideout_1F_Text_23367D, MSGBOX_DEFAULT
	release
	end
AquaHideout_1F_Text_23367D: @ 823367D
	.string "What? What? What do you want with \n"
	.string "Team Aqua?\p"
	.string "Our BOSS isn't here!\n"
	.string "He's gone off to jack a submarine!\p"
	.string "… …\n"
	.string "Where did he go?\p"
	.string "Wahaha! Do you really think I'd tell\n"
	.string "you something that crucial?$"


AquaHideout_1F_Text_23367D:
	.string "I just saw that visor kid run out of\n"
	.string "here really fast. Did you do that?\p"
	.string "Good job. You held him off long enough\n"
	.string "for the boss to get the preperations\l"
	.string "done and head out to sea.$"


@ -----------------------------------------------------
@ Grunts

AquaHideout_1F_EventScript_DoorGuard:: @ 82334C6
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_2334EE
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_2334E4
	msgbox AquaHideout_1F_Text_233739
	release
	end
AquaHideout_1F_Text_233739: @ 8233739
	.string "Sup, {PLAYER_dude}. Everyone kinda went\n"
	.string "down to help the boss at Mt. Pyre.\p"
	.string "Since no one's here, they're remodelling\n"
	.string "some things downstairs.\p"
	.string "Something about installing teleporters\n"
	.string "so it's easier to get around?\p"
	.string "It is kinda a maze down there,\n"
	.string "so this should help, maybe.$"
AquaHideout_1F_EventScript_2334E4:: @ 82334E4
	msgbox AquaHideout_1F_Text_2337FA
	release
	end
AquaHideout_1F_Text_2337FA: @ 82337FA
	.string "I hear that Team Magma is after\n"
	.string "some powerful Pokémon at Mt. Chimney.\p"
	.string "I wonder what kind of Pokémon it is.$"
AquaHideout_1F_EventScript_2334EE:: @ 82334EE
	msgbox AquaHideout_1F_Text_233884
	release
	end
AquaHideout_1F_Text_233884: @ 8233884
	.string "There's a bunch of other guys downstairs\n"
	.string "who will want to scrap fight with you.\p"
	.string "Why don't you head down and say hi?$"



AquaHideout_1F_EventScript_Scrappy1:: @ 82334F8
	lock
	faceplayer
	markasdialog
	checktrainerflag TRAINER_GRUNT_1
	goto_if_eq AquaHideout_1F_EventScript_Scrappy1_Lost
	setyesnotext gYN_Sure, gYN_Later
	msgbox AquaHideout_1F_Text_23393D, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq AquaHideout_1F_EventScript_Scrappy1_Fight
	msgbox AquaHideout_1F_Text_23393G
	release
	end
AquaHideout_1F_Text_23393D:
	.string "Ayi! Dude! I'm itching for a fight!\p"
	.string "You wanna scrap? I'll go easy on\n"
	.string "yer 'mon, promise!$"
AquaHideout_1F_Text_23393G:
	.string "Awwww, com'on!\n"
	.string "I gotta scratch this itch!$"
AquaHideout_1F_EventScript_Scrappy1_Fight:
	msgbox AquaHideout_1F_Text_23393E
	setflag FLAG_DEATH_PREVENT
	setflag FLAG_DEATH_PREVENT_1HP
	trainerbattle_no_intro TRAINER_GRUNT_1, AquaHideout_1F_Text_233964
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	release
	end
AquaHideout_1F_Text_23393E:
	.string "Yiah! Let's gooooooo!$"
AquaHideout_1F_Text_233964: @ 8233964
	.string "Yoooo…\n"
	.string "I lost it!$"
AquaHideout_1F_EventScript_Scrappy1_Lost:
	msgbox AquaHideout_1F_Text_233977
	release
	end
AquaHideout_1F_Text_233977:
	.string "Well, I'm all out of fight now.\n"
	.string "Thanks.$"

