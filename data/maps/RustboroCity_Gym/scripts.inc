RustboroCity_Gym_MapScripts:: @ 8212F30
	.byte 0

@ -----------------------------------------------------
@ Gym Entrance

RustboroCity_Gym_EventScript_213028:: @ 8213028
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_RUSTBORO_GYM, RustboroCity_Gym_EventScript_21303D
	msgbox RustboroCity_Gym_Text_21309D, MSGBOX_DEFAULT
	release
	end
RustboroCity_Gym_Text_21309D: @ 821309D
	.string "Ah, hello, {PLAYER_sir}.\n"
	.string "I presume you're here to challenge\l"
	.string "the Gym Leader.\p"
	.string "I'm here to provide expert advice!\p"
	.string "Roxanne, the Gym Leader, is a user\n"
	.string "of Rock-type Pokémon.\p"
	.string "The Rock type is very durable, but\n"
	.string "it can't stand Water-type and\l"
	.string "Grass-type moves.\p"
	.string "Come see me afterwards, if you beat\n"
	.string "the Gym Leader.\p"
	.string "Well, go for it!$"
RustboroCity_Gym_EventScript_21303D:: @ 821303D
	msgbox RustboroCity_Gym_Text_2132E2, MSGBOX_DEFAULT
	release
	end
RustboroCity_Gym_Text_2132E2: @ 82132E2
	.string "Congratulations on your victory!\n"
	.string "Check your Trainer Card.\p"
	.string "The Stone Badge you got should be\n"
	.string "properly recorded on it.\p"
	.string "You've climbed the first step on\n"
	.string "the stairs to the Championship!\p"
	.string "That's got to feel awesome!$"


RustboroCity_Gym_GymSignage:: @ 8213047
	lockall
	msgbox RustboroCity_Gym_Text_GymSignageTitle, MSGBOX_SIGN
	setvar VAR_0x8000, 0
	addvar_if_set FLAG_BADGE01_GET, VAR_0x8000, 1
	addvar_if_set FLAG_BADGE04_GET, VAR_0x8000, 1
	selectpointer_clamp RustboroCity_Gym_TextArray_GymSignageNames, VAR_0x8000
	msgbox_selected MSGBOX_SIGN
	releaseall
	end
RustboroCity_Gym_Text_GymSignageTitle: @ 820744C
	.string "{GYM}Rustboro City Pokémon Gym{END}\n"
	.string "Roxanne's Certified Trainers:$"
.align 2
RustboroCity_Gym_TextArray_GymSignageNames:
	.4byte RustboroCity_Gym_Text_GymSignageNameList1
	.4byte RustboroCity_Gym_Text_GymSignageNameList2
	.4byte RustboroCity_Gym_Text_GymSignageNameList3
	.4byte 0
RustboroCity_Gym_Text_GymSignageNameList1:
	.string "Clifton, Phoebe, Connor, Holly, Flannery,\n"
	.string "Alexis, {RIVAL_BIRCH}, Ethan$"
RustboroCity_Gym_Text_GymSignageNameList2:
	.string "Clifton, Phoebe, Connor, Holly, Flannery,\n"
	.string "Alexis, {RIVAL_BIRCH}, Ethan, {PLAYER}$"
RustboroCity_Gym_Text_GymSignageNameList3:
	.string "Clifton, Phoebe, Connor, Holly, Flannery,\n"
	.string "Alexis, {RIVAL_BIRCH}, Ethan, {PLAYER},\n"
	.string "{RIVAL_HERO}$"

@ -----------------------------------------------------
@ Trainers

RustboroCity_Gym_EventScript_212FE3:: @ 8212FE3
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_2133E9, RustboroCity_Gym_Text_21342D
	msgbox RustboroCity_Gym_Text_213447, MSGBOX_AUTOCLOSE
	end
RustboroCity_Gym_Text_2133E9: @ 82133E9
	.string "Don't take us gym trainers lightly!\n"
	.string "I'll show you why we're better!$"
RustboroCity_Gym_Text_21342D: @ 821342D
	.string "You were too good for me…$"
RustboroCity_Gym_Text_213447: @ 8213447
	.string "You haven't seen anything of the Rock\n"
	.string "type's terrifying power!$"


RustboroCity_Gym_EventScript_212FFA:: @ 8212FFA
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_213486, RustboroCity_Gym_Text_2134C6
	msgbox RustboroCity_Gym_Text_2134E6, MSGBOX_AUTOCLOSE
	end
RustboroCity_Gym_Text_213486: @ 8213486
	.string "If you can't beat me, you won't stand\n"
	.string "a chance against Roxanne!$"
RustboroCity_Gym_Text_2134C6: @ 82134C6
	.string "Wow! You've got some potential!$"
RustboroCity_Gym_Text_2134E6: @ 82134E6
	.string "Roxanne is stronger than me by\n"
	.string "several times.\p"
	.string "You'd better be on your guard!$"


RustboroCity_Gym_EventScript_213011:: @ 8213011
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_213533, RustboroCity_Gym_Text_213589
	msgbox RustboroCity_Gym_Text_2135C0, MSGBOX_AUTOCLOSE
	end
RustboroCity_Gym_Text_213533: @ 8213533
	.string "We might be in the middle of town,\n"
	.string "but so what?\p"
	.string "My Rock Pokémon need room to\n"
	.string "rampage!$"
RustboroCity_Gym_Text_213589: @ 8213589
	.string "Oh, man oh man!\n"
	.string "Our challenger is one feisty customer!$"
RustboroCity_Gym_Text_2135C0: @ 82135C0
	.string "I have to hand it to our leader.\p"
	.string "It took smarts and sense for her to\n"
	.string "pick the Rock type at her young age.$"


RustboroCity_Gym_ClearGymTrainers:: @ 8271FA1
	settrainerflag TRAINER_JOSH
	settrainerflag TRAINER_TOMMY
	settrainerflag TRAINER_MARC
	return

@ -----------------------------------------------------
@ Roxanne

RustboroCity_Gym_EventScript_Roxanne:: @ 8212F31
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_21362A, RustboroCity_Gym_Text_21370B, RustboroCity_Gym_EventScript_212F66, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq RustboroCity_Gym_EventScript_212FC8
	goto_if_unset FLAG_RECEIVED_TM39, RustboroCity_Gym_EventScript_GiveTMEnd
	msgbox RustboroCity_Gym_Text_2139A7, MSGBOX_DEFAULT
	release
	end
RustboroCity_Gym_Text_21362A: @ 821362A
	.string "Hello, I am Roxanne, the Rustboro\n"
	.string "Pokémon Gym Leader.\p"
	.string "I became a Gym Leader so that I might\n"
	.string "apply what I learned at the Pokémon\l"
	.string "Trainer's School in battle.\p"
	.string "Would you kindly demonstrate how you\n"
	.string "battle, and with which Pokémon?$"
RustboroCity_Gym_Text_21370B: @ 821370B
	.string "So…\n"
	.string "I lost…\p"
	.string "It seems that I still have much more\n"
	.string "to learn…\p"
	.string "I understand.\p"
	.string "The Pokémon League's rules state\n"
	.string "that trainers are to be given this\l"
	.string "if they defeat a Gym Leader.\p"
	.string "Please accept the official Pokémon\n"
	.string "League {ITEM}Stone Badge{END}.$"
RustboroCity_Gym_Text_2139A7: @ 82139A7
	.string "Since you are so strong, you should\n"
	.string "challenge other Gym Leaders.\p"
	.string "By battling many trainers, you should\n"
	.string "learn many things.$"
RustboroCity_Gym_EventScript_212F66:: @ 8212F66
	message RustboroCity_Gym_Text_2137EC, MSGTYPE_DESCRIBE
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_213816, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RUSTBORO_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_RUSTBORO_STATE, 1
	call RustboroCity_Gym_ClearGymTrainers
	call Common_EventScript_IncrementBadgeCount
	call RustboroCity_Gym_EventScript_GiveTM
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox RustboroCity_Gym_Text_213C01, MSGBOX_CDESCRIBE
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	release
	end
RustboroCity_Gym_Text_2137EC: @ 82137EC
	.string "{PLAYER} received the {ITEM}Stone Badge{END}\n"
	.string "from Roxanne.$"
RustboroCity_Gym_Text_213816: @ 8213816
	.string "The Stone Badge heightens the Attack\n"
	.string "power of your Pokémon.\p"
	.string "It also allows them to cut things\n"
	.string "outside of battle.\p"
	.string "Hm?{PAUSE 20} N-No, I don't know why a Pokémon's\n"
	.string "natural capabilities are unlocked by\l"
	.string "the posession of a badge.\l"
	.string "It's just how it's always been.\p"
	.string "Oh, please take this with you, too.$"
RustboroCity_Gym_Text_213C01: @ 8213C01
	.string "Registered Gym Leader Roxanne\n"
	.string "in the PokéNav.$"
RustboroCity_Gym_EventScript_GiveTM: @ 8212FA4
	giveitem_std ITEM_TM39
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox RustboroCity_Gym_Text_2138B1, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM39
	return
RustboroCity_Gym_Text_2138B1: @ 82138B1
	.string "That Technical Machine, TM39,\n"
	.string "contains Rock Tomb.\p"
	.string "It not only inflicts damage by dropping\n"
	.string "rocks, it also lowers Speed.\p"
	.string "If you use a TM, it instantly teaches\n"
	.string "the move to a Pokémon.\p"
	.string "Remember, a TM can be used as many\n"
	.string "times as you like, so don't hesitate.$"
RustboroCity_Gym_EventScript_GiveTMEnd:
	call RustboroCity_Gym_EventScript_GiveTM
	release
	end
RustboroCity_Gym_EventScript_212FC8:: @ 8212FC8
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_213C2F, RustboroCity_Gym_Text_213CF9, RustboroCity_Gym_Text_213D93
	msgbox RustboroCity_Gym_Text_213D12, MSGBOX_AUTOCLOSE
	end
RustboroCity_Gym_Text_213C2F: @ 8213C2F
	.string "Roxanne: I'm so glad to see you again.\n"
	.string "I'm Roxanne, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become. Let us battle!$"
RustboroCity_Gym_Text_213D93: @ 8213D93
	.string "Roxanne: I'm so glad to see you again.\n"
	.string "I'm Roxanne, the Gym Leader here.\p"
	.string "I'm sure we've both experienced many\n"
	.string "battles since we last met.\p"
	.string "I would like to see how much better\n"
	.string "we've become…\p"
	.string "Oh, no…\n"
	.string "You only have one Pokémon with you?\p"
	.string "Please return with at least one more\n"
	.string "Pokémon.$"
RustboroCity_Gym_Text_213CF9: @ 8213CF9
	.string "Grr…\n"
	.string "Again, I have lost…$"
RustboroCity_Gym_Text_213D12: @ 8213D12
	.string "Roxanne: I still have much to learn\n"
	.string "when it comes to battling Pokémon.\p"
	.string "That awareness makes me love battling\n"
	.string "all that much more!$"



@ RustboroCity_Gym_EventScript_21307B:: @ 821307B
@ 	lockall
@ 	pokenavcall RustboroCity_Gym_Text_213A76
@ 	waitmessage
@ 	delay 30
@ 	playfanfare MUS_ME_TORE_EYE
@ 	msgbox RustboroCity_Gym_Text_213C01, MSGBOX_DEFAULT
@ 	waitfanfare
@ 	closemessage
@ 	delay 30
@ 	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
@ 	clearflag FLAG_ENABLE_ALEX_FIRST_CALL
@ 	releaseall
@ 	end
@ RustboroCity_Gym_Text_213A76: @ 8213A76
@ 	.string "… … … … … …\n"
@ 	.string "… … … … … Beep!\p"
@ 	.string "Roxanne: Oh, hello, {PLAYER}?\n"
@ 	.string "This is Roxanne of Rustboro City.\p"
@ 	.string "I heard from BRAWLY that you're\n"
@ 	.string "moving up through the ranks of\l"
@ 	.string "TRAINERS at an incredible clip.\p"
@ 	.string "Well, I'd rather not think that\n"
@ 	.string "I can't beat you.\p"
@ 	.string "I promise, I will shape up my GYM\n"
@ 	.string "so that you may challenge us again.\p"
@ 	.string "I hope you'll be looking forward to\n"
@ 	.string "that occasion as much as me!\p"
@ 	.string "… … … … … …\n"
@ 	.string "… … … … … Click!$"


