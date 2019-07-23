Route102_MapScripts:: @ 81EC0E0
	.byte 0

@ -----------------------------------------------------
@ Signs

Route102_SignScript_Signpost1:: @ 81EC0EA
	msgbox Route102_Text_1EC35B, MSGBOX_SIGN
	end
Route102_Text_1EC35B: @ 81EC35B
	.string "Route 102\n"
	.string "{RIGHT_ARROW} Oldale Town$"


Route102_SignScript_Signpost2:: @ 81EC0F3
	msgbox Route102_Text_1EC373, MSGBOX_SIGN
	end
Route102_Text_1EC373: @ 81EC373
	.string "Route 102\n"
	.string "{LEFT_ARROW} Petalburg City$"

@ -----------------------------------------------------
@ Items

Route102_EventScript_ItemPotion:: @ 8290CD8
	giveitem_std ITEM_POTION, 1, 1
	end

@ -----------------------------------------------------
@ People

Route102_EventScript_GrassKid:: @ 81EC0E1
	msgbox Route102_Text_1EC2C0, MSGBOX_NPC
	end
Route102_Text_1EC2C0: @ 81EC2C0
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"


Route102_EventScript_CatchBoy:: @ 81EC0FC
	msgbox Route102_Text_1EC32E, MSGBOX_NPC
	end
Route102_Text_1EC32E: @ 81EC32E
	.string "I'm going to catch a whole bunch of\n"
	.string "Pokémon!$"

@ -----------------------------------------------------
@ Trainers

Route102_TrainerScript_Calvin:: @ 81EC105
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_294513, Route102_Text_29457C, Route102_EventScript_1EC146
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route102_EventScript_1EC19C
	setvar VAR_0x8004, 318
	specialvar VAR_RESULT, IsRematchTrainerRegistered
	compare VAR_RESULT, 0
	goto_if_eq Route102_EventScript_1EC170
	msgbox Route102_Text_2945AC, MSGBOX_DEFAULT
	release
	end
Route102_Text_294513: @ 8294513
	.string "If you have Pokémon with you, then\n"
	.string "you're an official Pokémon Trainer!\l"
	.string "You can't say no to my challenge!$"
Route102_Text_29457C: @ 829457C
	.string "Arrgh, I lost…\n"
	.string "I should have trained mine more…$"
Route102_Text_2945AC: @ 82945AC
	.string "Listen, you. If you're strong,\n"
	.string "you should have told me before!$"
Route102_EventScript_1EC146:: @ 81EC146
	special DoSpinningTrainerApproach
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_1EC157
	release
	end
Route102_EventScript_1EC157:: @ 81EC157
	msgbox Route102_Text_294668, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end
Route102_Text_294668: @ 8294668
	.string "I'd like to battle you again, so can\n"
	.string "you register me in your PokéNav?$"
Route102_EventScript_1EC170:: @ 81EC170
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_1EC183
	msgbox Route102_Text_2945AC, MSGBOX_DEFAULT
	release
	end
Route102_EventScript_1EC183:: @ 81EC183
	msgbox Route102_Text_2945EB, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end
Route102_Text_2945EB: @ 82945EB
	.string "I've been working hard at this since\n"
	.string "I saw you before.\p"
	.string "I'd like to battle you again, so can\n"
	.string "you register me in your PokéNav?$"
Route102_EventScript_1EC19C:: @ 81EC19C
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_2946AE, Route102_Text_29470C
	msgbox Route102_Text_29473C, MSGBOX_AUTOCLOSE
	end
Route102_Text_2946AE: @ 82946AE
	.string "Ever since I lost to you, I desperately\n"
	.string "trained my Pokémon.\l"
	.string "You can't say no to my challenge!$"
Route102_Text_29470C: @ 829470C
	.string "Arrgh, I lost…\n"
	.string "Is my training method not right?$"
Route102_Text_29473C: @ 829473C
	.string "If you're going to get stronger,\n"
	.string "I'll get stronger, too.$"



Route102_TrainerScript_Rick:: @ 81EC1B3
	trainerbattle_single TRAINER_RICK, Route102_Text_29480C, Route102_Text_294847
	msgbox Route102_Text_294859, MSGBOX_AUTOCLOSE
	end
Route102_Text_29480C: @ 829480C
	.string "Hahah! Our eyes met!\n"
	.string "I'll take you on with my Bug Pokémon!$"
Route102_Text_294847: @ 8294847
	.string "Ow! Down and out!$"
Route102_Text_294859: @ 8294859
	.string "If you lock eyes with a trainer,\n"
	.string "you have to challenge! It's a rule!$"



Route102_TrainerScript_Tiana:: @ 81EC1CA
	trainerbattle_single TRAINER_TIANA, Route102_Text_29489E, Route102_Text_2948F3
	msgbox Route102_Text_294916, MSGBOX_AUTOCLOSE
	end
Route102_Text_29489E: @ 829489E
	.string "I'm going to keep winning and aim\n"
	.string "to be the best trainer.\p"
	.string "Help me further my career!$"
Route102_Text_2948F3: @ 82948F3
	.string "I ended up furthering your career…$"
Route102_Text_294916: @ 8294916
	.string "To keep winning my way up, I see that\n"
	.string "I have to catch more Pokémon.$"



Route102_TrainerScript_Allen:: @ 81EC1E1
	trainerbattle_single TRAINER_ALLEN, Route102_Text_294775, Route102_Text_2947AA
	msgbox Route102_Text_2947DB, MSGBOX_AUTOCLOSE
	end
Route102_Text_294775: @ 8294775
	.string "Did you just become a trainer?\n"
	.string "We're both beginners!$"
Route102_Text_2947AA: @ 82947AA
	.string "I called you because I thought\n"
	.string "I could beat you…$"
Route102_Text_2947DB: @ 82947DB
	.string "I haven't won once yet…\n"
	.string "I wish I would win soon…$"
