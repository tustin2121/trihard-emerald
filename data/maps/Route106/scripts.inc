Route106_MapScripts:: @ 81EE489
	.byte 0

@ Tyler -----------------------------------

Route106_TrainerTrio_Tyler::
	lock
	faceplayer
	markasdialog
	dotimebasedevents
	compare VAR_DAILY_TRAINERTRIO, 0
	goto_if_eq Route106_TrainerTrio_Tyler_NewDay
	msgbox Route106_TrainerTrio_Tyler_TextAlreadyDone
	release
	end
Route106_TrainerTrio_Tyler_TextAlreadyDone:
	.string "Tyler: You are very talented!\p"
	.string "I would like to battle you\n"
	.string "tomorrow too!$"

Route106_TrainerTrio_Tyler_NewDay:
	msgbox Route106_TrainerTrio_Tyler_Text1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route106_TrainerTrio_Tyler_Battle
	msgbox Route106_TrainerTrio_Tyler_TextRefusal, MSGBOX_NPC
	release
	end
Route106_TrainerTrio_Tyler_Text1:
	.string "Tyler: Heya, we are the Training Trio!\p"
	.string "We came here on vacation from\n"
	.string "another region. We are really\l"
	.string "enjoying ourselves in Hoenn.\p"
	.string "We like to train our Pokémon everyday.\p"
	.string "Would you like to join us in our\n"
	.string "training session?$"
Route106_TrainerTrio_Tyler_TextRefusal:
	.string "Aw, that's too bad.$"

Route106_TrainerTrio_Tyler_Battle:
	msgbox Route106_TrainerTrio_Tyler_Battle_Text, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_TYLER_BADGE8, Route106_TrainerTrio_Tyler_Battle_DefeatText
	setvar VAR_DAILY_TRAINERTRIO, 1
	msgbox Route106_TrainerTrio_Tyler_Text2
	release
	end
Route106_TrainerTrio_Tyler_Battle_Text:
	.string "Tyler: Good, we will do our best!\n"
	.string "I will be your first opponent.$"
Route106_TrainerTrio_Tyler_Battle_DefeatText:
	.string "Well, good job!$"
Route106_TrainerTrio_Tyler_Text2:
	.string "Tyler: You really are powerful.\p"
	.string "If you want to train more,\n"
	.string "I think Tessa will be happy\l"
	.string "to take on your challenge.$"


@ Tessa ------------------------------------

Route106_TrainerTrio_Tessa::
	lock
	faceplayer
	markasdialog
	compare VAR_DAILY_TRAINERTRIO, 1
	goto_if_eq Route106_TrainerTrio_Tessa_NewDay
	msgbox Route106_TrainerTrio_Tessa_Text, MSGBOX_NPC
	release
	end
Route106_TrainerTrio_Tessa_Text:
	.string "Tessa: The weather in Hoenn is\n"
	.string "wonderful!\p"
	.string "I wish I could bring it to the island\n"
	.string "we live in…$"

Route106_TrainerTrio_Tessa_NewDay:
	msgbox Route106_TrainerTrio_Tessa_Text1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route106_TrainerTrio_Tessa_Battle
	msgbox Route106_TrainerTrio_Tessa_TextRefusal, MSGBOX_NPC
	release
	end
Route106_TrainerTrio_Tessa_Text1:
	.string "Tessa: So, you defeated Tyler…\p"
	.string "Please, let me see how strong\n"
	.string "you are.$"
Route106_TrainerTrio_Tessa_TextRefusal:
	.string "Now I'm just upset.$"

Route106_TrainerTrio_Tessa_Battle:
	msgbox Route106_TrainerTrio_Tessa_Battle_Text, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_TESSA_BADGE8, Route106_TrainerTrio_Tessa_Battle_DefeatText
	setvar VAR_DAILY_TRAINERTRIO, 2
	msgbox Route106_TrainerTrio_Tessa_Text2
	release
	end
Route106_TrainerTrio_Tessa_Battle_Text:
	.string "I will do my best!$"
Route106_TrainerTrio_Tessa_Battle_DefeatText:
	.string "Whoa! You are too strong!$"
Route106_TrainerTrio_Tessa_Text2:
	.string "Tessa: At this point, Theo is\n"
	.string "the only one who could have\l"
	.string "a chance to beat you…$"


@ Theo -------------------------------------

Route106_TrainerTrio_Theo::
	lock
	faceplayer
	markasdialog
	compare VAR_DAILY_TRAINERTRIO, 2
	goto_if_eq Route106_TrainerTrio_Theo_NewDay
	msgbox Route106_TrainerTrio_Theo_Text, MSGBOX_NPC
	release
	end
Route106_TrainerTrio_Theo_Text:
	.string "Theo: We usually do a training\n"
	.string "session per day.\p"
	.string "If you want to train with us,\n"
	.string "come here regularly.$"

Route106_TrainerTrio_Theo_NewDay:
	msgbox Route106_TrainerTrio_Theo_Text1, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq Route106_TrainerTrio_Theo_Battle
	msgbox Route106_TrainerTrio_Theo_TextRefusal, MSGBOX_NPC
	release
	end
Route106_TrainerTrio_Theo_Text1:
	.string "Theo: So you defeated both Tyler\n"
	.string "and Tessa?\p"
	.string "Well, then I am curious.\p"
	.string "Please, accept my challenge.$"
Route106_TrainerTrio_Theo_TextRefusal:
	.string "Oh, come on…$"

Route106_TrainerTrio_Theo_Battle:
	msgbox Route106_TrainerTrio_Theo_Battle_Text, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_THEO_BADGE8, Route106_TrainerTrio_Theo_Battle_DefeatText
	setvar VAR_DAILY_TRAINERTRIO, 3
	msgbox Route106_TrainerTrio_Theo_Text2, MSGBOX_NPC
	release
	end
Route106_TrainerTrio_Theo_Battle_Text:
	.string "Thank you. En garde!$"
Route106_TrainerTrio_Theo_Battle_DefeatText:
	.string "What happened?$"
Route106_TrainerTrio_Theo_Text2::
	.string "Theo: I can't believe it.\p"
	.string "You literally swept us.\p"
	.string "Please, come back tomorrow,\n"
	.string "it has been an honor battling\l"
	.string "with such a great trainer.$"


@ -----------------------------------------------------
@ Signs

Route106_EventScript_TrainerTips:: @ 81EE48A
	msgbox Route106_Text_1EE53A, MSGBOX_DESCRIBE
	end
Route106_Text_1EE53A: @ 81EE53A
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "Advice on catching Pokémon with a ROD:\n"
	.string "Press the A Button if you get a bite.$"

@ -----------------------------------------------------
@ Items

Route106_EventScript_ItemProtein:: @ 8290D40
	giveitem_std ITEM_PROTEIN, 1, 1
	end

@ -----------------------------------------------------
@ Trainers

Route106_TrainerScript_Douglas:: @ 81EE493
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_2965BB, Route106_Text_2965FD
	msgbox Route106_Text_296608, MSGBOX_AUTOCLOSE
	end
Route106_Text_2965BB: @ 82965BB
	.string "Hahahah! I'm a lousy runner, but in\n"
	.string "the water you can't catch me!$"
Route106_Text_2965FD: @ 82965FD
	.string "I give up!$"
Route106_Text_296608: @ 8296608
	.string "I wouldn't lose in a swim race…$"



Route106_TrainerScript_Kyla:: @ 81EE4AA
	trainerbattle_single TRAINER_KYLA, Route106_Text_296628, Route106_Text_296674
	msgbox Route106_Text_29669E, MSGBOX_AUTOCLOSE
	end
Route106_Text_296628: @ 8296628
	.string "The sea is my backyard. I'm not going\n"
	.string "to take it easy because you're a kid!$"
Route106_Text_296674: @ 8296674
	.string "Did you take it easy on me by any\n"
	.string "chance?$"
Route106_Text_29669E: @ 829669E
	.string "Drifting along with the waves…\n"
	.string "I love it! Why don't you give it a try?$"



Route106_TrainerScript_Elliot:: @ 81EE4C1
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_296327, Route106_Text_29635C, Route106_EventScript_1EE4ED
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route106_EventScript_1EE50C
	msgbox Route106_Text_29638C, MSGBOX_DEFAULT
	release
	end
Route106_Text_296327: @ 8296327
	.string "Which do you prefer, fishing in the\n"
	.string "sea or a stream?$"
Route106_Text_29635C: @ 829635C
	.string "Like in deep-sea fishing, I lost\n"
	.string "spectacularly!$"
Route106_Text_29638C: @ 829638C
	.string "Fishing is the greatest whether it's\n"
	.string "in the sea or a stream.\l"
	.string "You agree with me, right?$"
Route106_EventScript_1EE4ED:: @ 81EE4ED
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route106_Text_2963E3, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end
Route106_Text_2963E3: @ 82963E3
	.string "Fishing's great, but so is battling.\n"
	.string "If you don't mind, can we meet again?$"
Route106_EventScript_1EE50C:: @ 81EE50C
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_29642E, Route106_Text_296477
	msgbox Route106_Text_296493, MSGBOX_AUTOCLOSE
	end
Route106_Text_29642E: @ 829642E
	.string "I caught a bunch of Pokémon fishing.\n"
	.string "I'll show you an impressive battle!$"
Route106_Text_296477: @ 8296477
	.string "I lost again spectacularly!$"
Route106_Text_296493: @ 8296493
	.string "Win or lose, Pokémon are the greatest!\n"
	.string "You agree with me, right?$"



Route106_TrainerScript_Ned:: @ 81EE523
	trainerbattle_single TRAINER_NED, Route106_Text_2964D4, Route106_Text_296553
	msgbox Route106_Text_296588, MSGBOX_AUTOCLOSE
	end
Route106_Text_2964D4: @ 82964D4
	.string "What do people do if they need to go\n"
	.string "to the toilet?\p"
	.string "What if my rod hooks a big one while\n"
	.string "I'm in the toilet? I just can't go…$"
Route106_Text_296553: @ 8296553
	.string "I lost because I'm trying to not go\n"
	.string "to the toilet…$"
Route106_Text_296588: @ 8296588
	.string "Oh, no! I've got this feeling I'll hook\n"
	.string "a big one!$"
