Route107_MapScripts:: @ 81EE594
	.byte 0

@ -----------------------------------------------------
@ Trainers

Route107_TrainerScript_Darrin:: @ 81EE595
	trainerbattle_single TRAINER_DARRIN, Route107_Text_2966E5, Route107_Text_29672F
	msgbox Route107_Text_29675B, MSGBOX_AUTOCLOSE
	end
Route107_Text_2966E5: @ 82966E5
	.string "Yawn…\p"
	.string "I must have drifted off to sleep while\n"
	.string "I was drifting in the waves.$"
Route107_Text_29672F: @ 829672F
	.string "Ahaha, I lost…\n"
	.string "I'll take a snooze, I think…$"
Route107_Text_29675B: @ 829675B
	.string "Floating and being rocked by\n"
	.string "the waves--it's like sleeping in\l"
	.string "a plush, comfy bed.$"



Route107_TrainerScript_Tony:: @ 81EE5AC
	trainerbattle_single TRAINER_TONY_1, Route107_Text_2967AD, Route107_Text_2967D8, Route107_EventScript_1EE5D8
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route107_EventScript_1EE5F7
	msgbox Route107_Text_2967FF, MSGBOX_DEFAULT
	release
	end
Route107_Text_2967AD: @ 82967AD
	.string "The sea is like my backyard.\n"
	.string "Let's battle!$"
Route107_Text_2967D8: @ 82967D8
	.string "I lost on my home field…\n"
	.string "I'm in shock!$"
Route107_Text_2967FF: @ 82967FF
	.string "I swim the seas with a heart full of\n"
	.string "dreams…\p"
	.string "It's a song!\n"
	.string "Anyways, I'm swimming some more.$"
Route107_EventScript_1EE5D8:: @ 81EE5D8
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route107_Text_29685A, MSGBOX_DEFAULT
	register_matchcall TRAINER_TONY_1
	release
	end
Route107_Text_29685A: @ 829685A
	.string "You've shocked me to the bone!\n"
	.string "Well, so you won't forget me…$"
Route107_EventScript_1EE5F7:: @ 81EE5F7
	trainerbattle_rematch TRAINER_TONY_1, Route107_Text_296897, Route107_Text_2968D5
	msgbox Route107_Text_296923, MSGBOX_AUTOCLOSE
	end
Route107_Text_296897: @ 8296897
	.string "Swimming in the big, wide sea,\n"
	.string "my Pokémon has grown stronger!$"
Route107_Text_2968D5: @ 82968D5
	.string "What a shock!\p"
	.string "My Pokémon has gotten stronger, but\n"
	.string "I stayed weak as a trainer!$"
Route107_Text_296923: @ 8296923
	.string "What you learn in battle makes you\n"
	.string "a stronger trainer.\l"
	.string "The waves taught me that.$"



Route107_TrainerScript_Denise:: @ 81EE60E
	trainerbattle_single TRAINER_DENISE, Route107_Text_296974, Route107_Text_29699E
	msgbox Route107_Text_2969AB, MSGBOX_AUTOCLOSE
	end
Route107_Text_296974: @ 8296974
	.string "Do you know a little town called\n"
	.string "DEWFORD?$"
Route107_Text_29699E: @ 829699E
	.string "I hate this!$"
Route107_Text_2969AB: @ 82969AB
	.string "A weird saying is getting really\n"
	.string "trendy at DEWFORD HALL.$"



Route107_TrainerScript_Beth:: @ 81EE625
	trainerbattle_single TRAINER_BETH, Route107_Text_2969E4, Route107_Text_296A17
	msgbox Route107_Text_296A35, MSGBOX_AUTOCLOSE
	end
Route107_Text_2969E4: @ 82969E4
	.string "Did you want to battle me?\n"
	.string "Sure, I'll go with you!$"
Route107_Text_296A17: @ 8296A17
	.string "I wasn't good enough for you.$"
Route107_Text_296A35: @ 8296A35
	.string "I think you're going to keep getting\n"
	.string "better. I'll go for it, too!$"



Route107_TrainerScript_Lisa:: @ 81EE63C
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_296A77, Route107_Text_296AA7, Route107_Text_296B1E
	msgbox Route107_Text_296ADC, MSGBOX_AUTOCLOSE
	end
Route107_Text_296A77: @ 8296A77
	.string "Lisa: We challenge you as a sister\n"
	.string "and brother!$"
Route107_Text_296AA7: @ 8296AA7
	.string "Lisa: Awesome.\n"
	.string "You're in a different class of tough.$"
Route107_Text_296ADC: @ 8296ADC
	.string "Lisa: Do you have any friends who\n"
	.string "would go to the beach with you?$"
Route107_Text_296B1E: @ 8296B1E
	.string "Lisa: If you want to battle with us,\n"
	.string "bring more Pokémon.$"



Route107_TrainerScript_Ray:: @ 81EE657
	trainerbattle_double TRAINER_LISA_AND_RAY, Route107_Text_296B57, Route107_Text_296BB3, Route107_Text_296C34
	msgbox Route107_Text_296BE1, MSGBOX_AUTOCLOSE
	end
Route107_Text_296B57: @ 8296B57
	.string "Ray: We always battle Pokémon,\n"
	.string "me and my sister.\p"
	.string "I always lose, but we can beat you\n"
	.string "2-on-2!$"
Route107_Text_296BB3: @ 8296BB3
	.string "Ray: Wowee, you're at a higher level\n"
	.string "than us!$"
Route107_Text_296BE1: @ 8296BE1
	.string "Ray: My sister gave me my Pokémon.\n"
	.string "I raised it, and now it's my important\l"
	.string "partner!$"
Route107_Text_296C34: @ 8296C34
	.string "Ray: If you want to battle us,\n"
	.string "go bring some more Pokémon!$"



Route107_TrainerScript_Camron:: @ 81EE672
	trainerbattle_single TRAINER_CAMRON, Route107_Text_296C6F, Route107_Text_296CAD
	msgbox Route107_Text_296CC0, MSGBOX_AUTOCLOSE
	end
Route107_Text_296C6F: @ 8296C6F
	.string "I'm in the middle of a triathlon,\n"
	.string "but I'm nowhere near tired!$"
Route107_Text_296CAD: @ 8296CAD
	.string "That exhausted me…$"
Route107_Text_296CC0: @ 8296CC0
	.string "I still have swimming and running left\n"
	.string "to do after this.\p"
	.string "Am I going to be okay?$"

