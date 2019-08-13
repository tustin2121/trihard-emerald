Route119_MapScripts:: @ 81F4424
	map_script MAP_SCRIPT_ON_RESUME, Route119_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_OnTransition
	.byte 0

@ -----------------------------------------------------

Route119_OnResume: @ 81F442F
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, Route119_EventScript_1F4439
	end
Route119_EventScript_1F4439:: @ 81F4439
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

@ -----------------------------------------------------

Route119_OnTransition: @ 81F444D
	call Common_EventScript_SetupRivalGender
	call Common_EventScript_SetupRivalOnBikeGender
	compare VAR_WEATHER_INSTITUTE_STATE, 2
	call_if_eq Route119_EventScript_1F4466
	special SetRoute119Weather
	clearflag FLAG_SCENE_FORCE_AQUA_THEME
	end

Route119_EventScript_1F4466:: @ 81F4466
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_1F_WORKERS
	setvar VAR_WEATHER_INSTITUTE_STATE, 3
	return

@ -----------------------------------------------------
@ Signs

Route119_EventScript_1F4774:: @ 81F4774
	msgbox Route119_Text_1F530E, MSGBOX_SIGN
	end
Route119_Text_1F530E: @ 81F530E
	.string "Route 119\n"
	.string "{RIGHT_ARROW} Fortree City$"


Route119_EventScript_1F477D:: @ 81F477D
	msgbox Route119_Text_1F5327, MSGBOX_SIGN
	end
Route119_Text_1F5327: @ 81F5327
	.string "{PLACE}WEATHER INSTITUTE{END}$"


Route119_EventScript_1F49E3:: @ 81F49E3
	msgbox Route119_Text_1F5339, MSGBOX_DESCRIBE
	end
Route119_Text_1F5339: @ 81F5339
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "Up to sixteen decorations and\n"
	.string "furniture items can be placed in\l"
	.string "a Secret Base.\p"
	.string "Pick your favorite items and create\n"
	.string "your very own Secret Base exactly the\l"
	.string "way you want.$"


@ -----------------------------------------------------
@ People

Route119_EventScript_1F49A3:: @ 81F49A3
	lock
	faceplayer
	msgbox Route119_Text_1F50EB, MSGBOX_CDIALOG
	closemessage
	faceoriginaldir
	release
	end
Route119_Text_1F50EB: @ 81F50EB
	.string "There's a heist happening soon in\n"
	.string "the Weather Institute.\p"
	.string "We're standing lookout here.\p"
	.string "You might wanna go see if you can help.$"

Route119_EventScript_1F49BA:: @ 81F49BA
	lock
	faceplayer
	msgbox Route119_Text_1F5147, MSGBOX_CDIALOG
	closemessage
	faceoriginaldir
	release
	end
Route119_Text_1F5147: @ 81F5147
	.string "Lookout duty is surprisingly boring.\p"
	.string "If I wasn't standing, I'd curl up and\n"
	.string "go to sleep right here.$"


Route119_EventScript_1F476B:: @ 81F476B
	msgbox Route119_Text_1F5261, MSGBOX_NPC
	end
Route119_Text_1F5261: @ 81F5261
	.string "Tch…\n"
	.string "It's a no-go…\p"
	.string "The tall grass snares bike tires.\n"
	.string "There's no way you can cycle here.$"

Route119_EventScript_1F49D1:: @ 81F49D1
	msgbox Route119_Text_1F51A2, MSGBOX_NPC
	end
Route119_Text_1F51A2: @ 81F51A2
	.string "I thought you fly by catching a whole\n"
	.string "flock of bird Pokémon, and then\l"
	.string "hanging on to them somehow.\p"
	.string "But it turns out there's a Gym Badge\n"
	.string "that lets you fly them!\p"
	.string "I wish I'd known about that a long\n"
	.string "time ago…$"

Route119_EventScript_1F49DA:: @ 81F49DA
	msgbox Route119_Text_1F52B9, MSGBOX_NPC
	end
Route119_Text_1F52B9: @ 81F52B9
	.string "Can your Pokémon use its Secret Power\n"
	.string "on a big pile of grass and make a\l"
	.string "Secret Base?$"


@ -----------------------------------------------------
@ Trainers

Route119_EventScript_1F4786:: @ 81F4786
	trainerbattle_single TRAINER_BRENT, Route119_Text_29D8C2, Route119_Text_29D8F0
	msgbox Route119_Text_29D902, MSGBOX_AUTOCLOSE
	end
Route119_Text_29D8C2: @ 829D8C2
	.string "We're the Mimic Circle!\n"
	.string "We Mimic what you do!$"
Route119_Text_29D8F0: @ 829D8F0
	.string "Whoopsie!\n"
	.string "I lost!$"
Route119_Text_29D902: @ 829D902
	.string "What's so good about mimicry?\p"
	.string "Fufufu…\n"
	.string "You'll never understand…$"


Route119_EventScript_1F479D:: @ 81F479D
	trainerbattle_single TRAINER_DONALD, Route119_Text_29D941, Route119_Text_29D97C
	msgbox Route119_Text_29D993, MSGBOX_AUTOCLOSE
	end
Route119_Text_29D941: @ 829D941
	.string "So, we finally meet!\n"
	.string "My Bug Pokémon will keep you company!$"
Route119_Text_29D97C: @ 829D97C
	.string "I wish we'd never met…$"
Route119_Text_29D993: @ 829D993
	.string "I want to Mimic you some more.\n"
	.string "Can you hurry up and move?$"


Route119_EventScript_1F47B4:: @ 81F47B4
	trainerbattle_single TRAINER_TAYLOR, Route119_Text_29D9CD, Route119_Text_29DA14
	msgbox Route119_Text_29DA2C, MSGBOX_AUTOCLOSE
	end
Route119_Text_29D9CD: @ 829D9CD
	.string "If you step forward, we step forward.\p"
	.string "If you turn right, we turn, too…$"
Route119_Text_29DA14: @ 829DA14
	.string "But if you win, I lose…$"
Route119_Text_29DA2C: @ 829DA2C
	.string "I can't Mimic you winning the match.\n"
	.string "That's just impossible…\l"
	.string "It's burning me up…$"


Route119_EventScript_1F47CB:: @ 81F47CB
	trainerbattle_single TRAINER_DOUG, Route119_Text_29DA7D, Route119_Text_29DABC
	msgbox Route119_Text_29DADB, MSGBOX_AUTOCLOSE
	end
Route119_Text_29DA7D: @ 829DA7D
	.string "Yep, you've finally caught me!\n"
	.string "Or were you trying to avoid me?$"
Route119_Text_29DABC: @ 829DABC
	.string "Whoop, that was a great match!$"
Route119_Text_29DADB: @ 829DADB
	.string "We're the Mimic Circle!\n"
	.string "I hope you enjoyed our performance.$"


Route119_EventScript_1F47E2:: @ 81F47E2
	trainerbattle_single TRAINER_GREG, Route119_Text_29DB17, Route119_Text_29DB66
	msgbox Route119_Text_29DB7C, MSGBOX_AUTOCLOSE
	end
Route119_Text_29DB17: @ 829DB17
	.string "You don't know who I am, do you?\p"
	.string "But, I also don't know you.\n"
	.string "So, we'll battle!$"
Route119_Text_29DB66: @ 829DB66
	.string "You're pretty strong!$"
Route119_Text_29DB7C: @ 829DB7C
	.string "Until you go away somewhere, we'll\n"
	.string "keep on mimicking your every move.$"


Route119_EventScript_1F47F9:: @ 81F47F9
	trainerbattle_single TRAINER_KENT, Route119_Text_29DBC2, Route119_Text_29DC20
	msgbox Route119_Text_29DC2B, MSGBOX_AUTOCLOSE
	end
Route119_Text_29DBC2: @ 829DBC2
	.string "The Mimic Circle was formed by people\n"
	.string "who like to Mimic.\p"
	.string "A battle starts the instant we meet!$"
Route119_Text_29DC20: @ 829DC20
	.string "I give up!$"
Route119_Text_29DC2B: @ 829DC2B
	.string "Won't you join our Mimic Circle?$"


Route119_EventScript_1F4810:: @ 81F4810
	trainerbattle_single TRAINER_JACKSON_1, Route119_Text_29DC4C, Route119_Text_29DC9F, Route119_EventScript_1F483C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_1F485B
	msgbox Route119_Text_29DCC6, MSGBOX_DEFAULT
	release
	end
Route119_Text_29DC4C: @ 829DC4C
	.string "Who has the knowledge and\n"
	.string "the technique for survival?\p"
	.string "Pokémon Rangers, that's who!$"
Route119_Text_29DC9F: @ 829DC9F
	.string "I didn't have enough Pokémon\n"
	.string "know-how…$"
Route119_Text_29DCC6: @ 829DCC6
	.string "To break away from civilization and\n"
	.string "awaken the wild spirit within!\p"
	.string "That's our vision.$"
Route119_EventScript_1F483C:: @ 81F483C
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route119_Text_29DD1C, MSGBOX_DEFAULT
	register_matchcall TRAINER_JACKSON_1
	release
	end
Route119_Text_29DD1C: @ 829DD1C
	.string "I hope you'll give me a rematch without\n"
	.string "mocking my lack of knowledge.$"
Route119_EventScript_1F485B:: @ 81F485B
	trainerbattle_rematch TRAINER_JACKSON_1, Route119_Text_29DD62, Route119_Text_29DDA5
	msgbox Route119_Text_29DDBD, MSGBOX_AUTOCLOSE
	end
Route119_Text_29DD62: @ 829DD62
	.string "I'm going to regain my wild spirit by\n"
	.string "being together with Pokémon.$"
Route119_Text_29DDA5: @ 829DDA5
	.string "You've remained strong!$"
Route119_Text_29DDBD: @ 829DDBD
	.string "Believe in your Pokémon.\n"
	.string "Believe in yourself.\p"
	.string "The road will reveal itself to you.$"



Route119_EventScript_1F4872:: @ 81F4872
	trainerbattle_single TRAINER_CATHERINE_1, Route119_Text_29DE0F, Route119_Text_29DE5D, Route119_EventScript_1F489E
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route119_EventScript_1F48BD
	msgbox Route119_Text_29DE88, MSGBOX_DEFAULT
	release
	end
Route119_Text_29DE0F: @ 829DE0F
	.string "Oh? Look at you.\p"
	.string "For someone on an adventure,\n"
	.string "you're traveling awfully light.$"
Route119_Text_29DE5D: @ 829DE5D
	.string "Accidents happen when you're not\n"
	.string "prepared!$"
Route119_Text_29DE88: @ 829DE88
	.string "You're traveling light but you have\n"
	.string "everything you need.\p"
	.string "You're on top of things mentally and\n"
	.string "physically, too.$"
Route119_EventScript_1F489E:: @ 81F489E
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route119_Text_29DEF7, MSGBOX_DEFAULT
	register_matchcall TRAINER_CATHERINE_1
	release
	end
Route119_Text_29DEF7: @ 829DEF7
	.string "Do you have a PokéNav?\n"
	.string "It's a must-have tool for any trainer.\p"
	.string "Oh, you do have one!\n"
	.string "Let's register each other, then!$"
Route119_EventScript_1F48BD:: @ 81F48BD
	trainerbattle_rematch TRAINER_CATHERINE_1, Route119_Text_29DF6B, Route119_Text_29DF92
	msgbox Route119_Text_29DFAF, MSGBOX_AUTOCLOSE
	end
Route119_Text_29DF6B: @ 829DF6B
	.string "How's your journey with Pokémon\n"
	.string "going?$"
Route119_Text_29DF92: @ 829DF92
	.string "I'm still missing something…$"
Route119_Text_29DFAF: @ 829DFAF
	.string "In the same way that you, as a trainer,\n"
	.string "rely on your Pokémon, your Pokémon\l"
	.string "rely on you.$"


Route119_EventScript_1F48D4:: @ 81F48D4
	trainerbattle_single TRAINER_HUGH, Route119_Text_29E007, Route119_Text_29E063
	msgbox Route119_Text_29E071, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E007: @ 829E007
	.string "The vast sky holds untold promise!\p"
	.string "Nothing can compare to the sheer\n"
	.string "exhilaration of flight!$"
Route119_Text_29E063: @ 829E063
	.string "Down and out!$"
Route119_Text_29E071: @ 829E071
	.string "My Bird Pokémon made my dreams of\n"
	.string "flying come true!$"


Route119_EventScript_1F48EB:: @ 81F48EB
	trainerbattle_single TRAINER_PHIL, Route119_Text_29E0A5, Route119_Text_29E0E1
	msgbox Route119_Text_29E0F6, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E0A5: @ 829E0A5
	.string "I'll show you the true potential of me\n"
	.string "and my Bird Pokémon!$"
Route119_Text_29E0E1: @ 829E0E1
	.string "We lacked potential…$"
Route119_Text_29E0F6: @ 829E0F6
	.string "Ever since I was a little kid, I always\n"
	.string "admired Bird Pokémon…$"


Route119_EventScript_1F4902:: @ 81F4902
	trainerbattle_single TRAINER_YASU, Route119_Text_29E134, Route119_Text_29E18D
	msgbox Route119_Text_29E19D, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E134: @ 829E134
	.string "To lurk in shadows, and live in\n"
	.string "darkness… That is my destiny.\p"
	.string "I emerge to challenge you!$"
Route119_Text_29E18D: @ 829E18D
	.string "I admit defeat!$"
Route119_Text_29E19D: @ 829E19D
	.string "Those defeated in battle withdraw\n"
	.string "quietly back into the shadows.\l"
	.string "That, too, is destiny…$"


Route119_EventScript_1F4919:: @ 81F4919
	trainerbattle_single TRAINER_TAKASHI, Route119_Text_29E1F5, Route119_Text_29E22B
	msgbox Route119_Text_29E245, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E1F5: @ 829E1F5
	.string "If you're not on your guard,\n"
	.string "you're in for some pain!$"
Route119_Text_29E22B: @ 829E22B
	.string "You're surprisingly good!$"
Route119_Text_29E245: @ 829E245
	.string "My surprise attack ended in\n"
	.string "failure…$"


Route119_EventScript_1F4930:: @ 81F4930
	trainerbattle_single TRAINER_HIDEO, Route119_Text_29E26A, Route119_Text_29E288
	msgbox Route119_Text_29E2A3, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E26A: @ 829E26A
	.string "To hide a tree, use a forest!$"
Route119_Text_29E288: @ 829E288
	.string "I bow to your superiority.$"
Route119_Text_29E2A3: @ 829E2A3
	.string "To hide a tree, use a forest!\n"
	.string "To hide a Pokémon, use a Pokémon!\p"
	.string "There is no deep, hidden meaning\n"
	.string "to that.$"


Route119_EventScript_1F4947:: @ 81F4947
	trainerbattle_single TRAINER_CHRIS, Route119_Text_29E30D, Route119_Text_29E372
	msgbox Route119_Text_29E3A2, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E30D: @ 829E30D
	.string "You spoke to me…\n"
	.string "So you want to challenge me!\p"
	.string "Sure! I'll try out the Pokémon I caught\n"
	.string "while surfing!$"
Route119_Text_29E372: @ 829E372
	.string "I don't have a clue about what it\n"
	.string "takes to win.$"
Route119_Text_29E3A2: @ 829E3A2
	.string "Go for a surf on my Pokémon…\p"
	.string "Then fish off its back…\p"
	.string "It's an indescribably luxuriant moment!$"


Route119_EventScript_1F495E:: @ 81F495E
	trainerbattle_single TRAINER_FABIAN, Route119_Text_29E3FF, Route119_Text_29E44F
	msgbox Route119_Text_29E492, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E3FF: @ 829E3FF
	.string "Hit me with a power chord!\n"
	.string "Victory is mine!\l"
	.string "It's our time to shine, whoa, yeah!$"
Route119_Text_29E44F: @ 829E44F
	.string "You showed me who's the boss!\n"
	.string "We'll have to take the loss, oh, no!$"
Route119_Text_29E492: @ 829E492
	.string "Hit me with another power chord!\n"
	.string "Leave me alone!\l"
	.string "Your win you have to atone!$"


Route119_EventScript_1F4975:: @ 81F4975
	trainerbattle_single TRAINER_DAYTON, Route119_Text_29E4DF, Route119_Text_29E513
	msgbox Route119_Text_29E532, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E4DF: @ 829E4DF
	.string "Hohoho!\n"
	.string "I like kid trainers!\l"
	.string "Let's have a good one!\p"
	.string "What? No, I meant a battle!$"
Route119_Text_29E513: @ 829E513
	.string "You're pretty amazing!\n"
	.string "Hohoho!$"
Route119_Text_29E532: @ 829E532
	.string "Hohoho!\n"
	.string "I'll try emulating the pep of kid\l"
	.string "trainers like you!\p"
	.string "Well, not you specifically, since\n"
	.string "you're a rude one. Maybe the kid to\l"
	.string "my left with the disguise.$"


Route119_EventScript_1F498C:: @ 81F498C
	trainerbattle_single TRAINER_RACHEL, Route119_Text_29E56F, Route119_Text_29E5B1
	msgbox Route119_Text_29E5CB, MSGBOX_AUTOCLOSE
	end
Route119_Text_29E56F: @ 829E56F
	.string "Wherever and whenever I may be,\n"
	.string "I always have my parasol in hand.$"
Route119_Text_29E5B1: @ 829E5B1
	.string "Oh, but…\n"
	.string "That's not fair.$"
Route119_Text_29E5CB: @ 829E5CB
	.string "What? No, I cannot fly via my parasol.\n"
	.string "Whatever kind of question is that?$"

@ -----------------------------------------------------
@ Rival

#define LID_RIVAL_BIKE 25
#define LID_RIVAL_WALK 16

Route119_EventScript_1F4472:: @ 81F4472
	setvar VAR_TEMP_1, 1
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F447D:: @ 81F447D
	setvar VAR_TEMP_1, 2
	goto Route119_EventScript_1F4488
	end

Route119_EventScript_1F4488:: @ 81F4488
	lockall
	addobject LID_RIVAL_BIKE
	call Common_EventScript_PlayRivalMusic
	delay 65
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46C6
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46D1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F4700
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F470F
	removeobject LID_RIVAL_BIKE
	addobject LID_RIVAL_WALK
	delay 30
	markasdialog
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route119_EventScript_1F450B
	compare VAR_RESULT, FEMALE
	goto_if_eq Route119_EventScript_1F4585
	releaseall
	end
Route119_EventScript_1F46C6:: @ 81F46C6
	applymovement LID_RIVAL_BIKE, Route119_Movement_1F4728
	waitmovement 0
	return
Route119_EventScript_1F46D1:: @ 81F46D1
	applymovement LID_RIVAL_BIKE, Route119_Movement_1F4732
	waitmovement 0
	return
Route119_EventScript_1F4700:: @ 81F4700
	setobjectxyperm LID_RIVAL_WALK, 25, 32
	setobjectxyperm LID_RIVAL_BIKE, 25, 32
	return
Route119_EventScript_1F470F:: @ 81F470F
	setobjectxyperm LID_RIVAL_WALK, 26, 32
	setobjectxyperm LID_RIVAL_BIKE, 26, 32
	return

Route119_EventScript_1F450B:: @ 81F450B
	msgbox Route119_Text_1F49FD, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_1F453A
	case 1, Route119_EventScript_1F454A
	case 2, Route119_EventScript_1F455A
	end
Route119_Text_1F49FD: @ 81F49FD
	.string "May: {PLAYER}!\n"
	.string "Oh! I didn't expect to see you still\l"
	.string "out and about.\p"
	.string "Uh, hey! Wanna quick battle?\n"
	.string "Ready? Of course you are! Go!$"
Route119_EventScript_1F453A:: @ 81F453A
	trainerbattle_no_intro TRAINER_MAY_6, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end
Route119_EventScript_1F454A:: @ 81F454A
	trainerbattle_no_intro TRAINER_MAY_9, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end
Route119_EventScript_1F455A:: @ 81F455A
	trainerbattle_no_intro TRAINER_MAY_3, Route119_Text_1F4A98
	goto Route119_EventScript_1F456A
	end
Route119_Text_1F4A98: @ 81F4A98
	.string "Achah!\n"
	.string "{PLAYER}, you're strong!\p"
	.string "No wonder they can't catch you…\n"
	.string "uh, I mean, heh…$"
Route119_EventScript_1F456A:: @ 81F456A
	markasdialog
	msgbox Route119_Text_1F4AF3, MSGBOX_DEFAULT
	@ call Route119_EventScript_RivalGiveFlyTM
	@ msgbox Route119_Text_1F4B56, MSGBOX_DEFAULT
	goto Route119_EventScript_1F460F
	end
Route119_Text_1F4AF3: @ 81F4AF3
	.string "May: I had absolutely nothing to\n"
	.string "worry about! Heh… Keep it up!$"
@ Route119_Text_1F4B56: @ 81F4B56
@ 	.string "May: Use FLY, and your Pokémon will\n"
@ 	.string "instantly carry you to any town you've\l"
@ 	.string "already visited.\p"
@ 	.string "But, to use FLY, you have to get\n"
@ 	.string "the Gym Badge from Fortree City.\l"
@ 	.string "That's important, so don't forget.\p"
@ 	.string "You should FLY home and visit\n"
@ 	.string "LITTLEROOT for a change.\p"
@ 	.string "I bet your mom's worried about you,\n"
@ 	.string "{PLAYER}.\p"
@ 	.string "Well, let's meet again somewhere!$"

Route119_EventScript_1F4585:: @ 81F4585
	msgbox Route119_Text_1F4C9A, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route119_EventScript_1F45B4
	case 1, Route119_EventScript_1F45C4
	case 2, Route119_EventScript_1F45D4
	end
Route119_Text_1F4C9A: @ 81F4C9A
	.string "Brendan: {PLAYER}!\p"
	.string "So this is where you've been hiding\n"
	.string "from the la{PAUSE 10}a{PAUSE 12}a{PAUSE 16}a{PAUSE 6}oud Pokémon!\l"
	.string "Those Loudred are booming today!\p"
	.string "Say! Our eyes met, right?!\n"
	.string "It's a battle, so battle!$"

Route119_EventScript_1F45B4:: @ 81F45B4
	trainerbattle_no_intro TRAINER_BRENDAN_6, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end
Route119_EventScript_1F45C4:: @ 81F45C4
	trainerbattle_no_intro TRAINER_BRENDAN_9, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end
Route119_EventScript_1F45D4:: @ 81F45D4
	trainerbattle_no_intro TRAINER_BRENDAN_3, Route119_Text_1F4D24
	goto Route119_EventScript_1F45E4
	end
Route119_Text_1F4D24: @ 81F4D24
	.string "Darn…\n"
	.string "You've gotten pretty tough.$"

Route119_EventScript_1F45E4:: @ 81F45E4
	markasdialog
	msgbox Route119_Text_1F4D4B, MSGBOX_DEFAULT
	@ call Route119_EventScript_RivalGiveFlyTM
	@ msgbox Route119_Text_1F4DB5, MSGBOX_DEFAULT
	goto Route119_EventScript_1F460F
	end
Route119_Text_1F4D4B: @ 81F4D4B
	.string "Brendan: I'd say you're good enough\n"
	.string "to run from… Pokémon… anywhere!\p"
	.string "Like me, right now. Bye!$"
@ Route119_Text_1F4DB5: @ 81F4DB5
@ 	.string "Brendan: Use FLY, and your Pokémon\n"
@ 	.string "instantly carries you to any town\l"
@ 	.string "you've already visited.\p"
@ 	.string "But you need the FORTREE Gym Badge \n"
@ 	.string "to do that.\p"
@ 	.string "Anyway, I have to move along.$"

Route119_EventScript_RivalGiveFlyTM:: @ 81F45FF
	giveitem_std ITEM_TM52
	setflag FLAG_RECEIVED_TM52
	return

Route119_EventScript_1F460F:: @ 81F460F
	closemessage
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F4700
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F470F
	removeobject LID_RIVAL_WALK
	addobject LID_RIVAL_BIKE
	delay 30
	compare VAR_TEMP_1, 1
	call_if_eq Route119_EventScript_1F46DC
	compare VAR_TEMP_1, 2
	call_if_eq Route119_EventScript_1F46EE
	removeobject LID_RIVAL_BIKE
	msgbox Route119_Text_1F4DB5, MSGBOX_CDESCRIBE
	call Route119_EventScript_RivalGiveFlyTM
	@ clean up
	setvar VAR_ROUTE119_STATE, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end
Route119_Text_1F4DB5:
	.string "Looks like {RIVAL_they} dropped something…$"

Route119_EventScript_1F46DC:: @ 81F46DC
	applymovement EVENT_OBJ_ID_PLAYER, Route119_Movement_1F471E
	applymovement 25, Route119_Movement_1F473D
	waitmovement 0
	return

Route119_EventScript_1F46EE:: @ 81F46EE
	applymovement EVENT_OBJ_ID_PLAYER, Route119_Movement_1F4723
	applymovement 25, Route119_Movement_1F4747
	waitmovement 0
	return



Route119_Movement_1F471E: @ 81F471E
	delay_16
	walk_in_place_fastest_right
	delay_8
	walk_in_place_fastest_up
	step_end

Route119_Movement_1F4723: @ 81F4723
	delay_16
	walk_in_place_fastest_left
	delay_8
	walk_in_place_fastest_up
	step_end

Route119_Movement_1F4728: @ 81F4728
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_1F4732: @ 81F4732
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	step_end

Route119_Movement_1F473D: @ 81F473D
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route119_Movement_1F4747: @ 81F4747
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end


#undef LID_RIVAL_BIKE
#undef LID_RIVAL_WALK
