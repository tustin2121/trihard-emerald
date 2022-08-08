Route110_MapScripts:: @ 81EF269
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_FrameTable
	.byte 0

@ -----------------------------------------------------

Route110_OnResume: @ 81EF279
	special UpdateCyclingRoadState
	end

@ -----------------------------------------------------

Route110_OnTransition: @ 81EF27D
	call Common_EventScript_SetupRivalGender
	call Common_EventScript_SetupRivalOnBikeGender
	call_if_set FLAG_SYS_CYCLING_ROAD, Route110_EventScript_1EF293
	@ compare VAR_CYCLING_CHALLENGE_STATE, 1
	@ call_if_eq Route110_EventScript_1EF293
	end

Route110_EventScript_1EF293:: @ 81EF293
	savebgm MUS_CYCLING
	return

@ -----------------------------------------------------

Route110_FrameTable: @ 81EF297
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_1EF2A1
	.2byte 0

Route110_EventScript_1EF2A1:: @ 81EF2A1
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

@ -----------------------------------------------------
@ Signs

Route110_EventScript_1EF341:: @ 81EF341
	msgbox Route110_Text_1F0812, MSGBOX_SIGN
	end
Route110_Text_1F0812: @ 81F0812
	.string "Route 110\n"
	.string "{DOWN_ARROW} Slateport City$"


Route110_EventScript_1EF34A:: @ 81EF34A
	msgbox Route110_Text_1F082D, MSGBOX_SIGN
	end
Route110_Text_1F082D: @ 81F082D
	.string "{PLACE}Seaside Cycling Road{END}$"


Route110_EventScript_1EF353:: @ 81EF353
	msgbox Route110_Text_1F0842, MSGBOX_DESCRIBE
	end
Route110_Text_1F0842: @ 81F0842
	.string "“Team Aqua was here!”\p"
	.string "Someone painted that onto this sign,\n"
	.string "but then someone else painted over it.\p"
	.string "“Team Magma rules!” is what it\n"
	.string "says now.$"


Route110_EventScript_1EF35C:: @ 81EF35C
	msgbox Route110_Text_1F08CD, MSGBOX_SIGN
	end
Route110_Text_1F08CD: @ 81F08CD
	.string "Route 110\n"
	.string "{LEFT_ARROW} Route 103$"


Route110_EventScript_1EF365:: @ 81EF365
	msgbox Route110_Text_1F08E3, MSGBOX_SIGN
	end
Route110_Text_1F08E3: @ 81F08E3
	.string "{PLACE}Seaside Parking{END}$"


Route110_EventScript_1EF36E:: @ 81EF36E
	msgbox Route110_Text_1F08F3, MSGBOX_SIGN
	end
Route110_Text_1F08F3: @ 81F08F3
	.string "Route 110\n"
	.string "{UP_ARROW} Mauville City$"


Route110_EventScript_1EF377:: @ 81EF377
	msgbox Route110_Text_1F090D, MSGBOX_DESCRIBE
	end
Route110_Text_1F090D: @ 81F090D
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "The foe can be made helpless by\n"
	.string "paralyzing it or causing it to sleep.\p"
	.string "It is an important technique for\n"
	.string "Pokémon battles.$"


Route110_EventScript_1EF380:: @ 81EF380
	msgbox Route110_Text_1F0992, MSGBOX_DESCRIBE
	end
Route110_Text_1F0992: @ 81F0992
	.string "{TIPS} TRAINER TIPS {END}\p"
	.string "The items in the BAG can be reorganized\n"
	.string "by pressing SELECT.$"


Route110_EventScript_1EF389:: @ 81EF389
	msgbox Route110_Text_1F09DB, MSGBOX_SIGN
	end
Route110_Text_1F09DB: @ 81F09DB
	.string "Three steps {RIGHT_ARROW} and two steps {UP_ARROW}\n"
	.string "to reach the wondrous TRICK HOUSE.$"


Route110_EventScript_1EF392:: @ 81EF392
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	compare VAR_RESULT, 0
	goto_if_eq Route110_EventScript_1EF3AD
	msgbox Route110_Text_1F0A1E, MSGBOX_SIGN
	releaseall
	end
Route110_Text_1F0A1E: @ 81F0A1E
	.string "THE BEST RECORD TO DATE…\p"
	.string "No. of collisions: {STR_VAR_1}\p"
	.string "Elapsed time: {STR_VAR_2}$"
Route110_EventScript_1EF3AD:: @ 81EF3AD
	msgbox Route110_Text_1F0A5E, MSGBOX_SIGN
	releaseall
	end
Route110_Text_1F0A5E: @ 81F0A5E
	.string "THE BEST RECORD TO DATE…\p"
	.string "No one seems to have taken the\n"
	.string "challenge. There is no record…$"

@ -----------------------------------------------------
@ People

Route110_EventScript_1EF2AA:: @ 81EF2AA
	lock
	faceplayer
	markasdialog
	msgbox Route110_Text_1EFB5D, MSGBOX_DEFAULT
	faceoriginaldir
	release
	end
Route110_Text_1EFB5D: @ 81EFB5D
	.string "Team Aqua's activities…\n"
	.string "We can't talk about them yet.$"


Route110_EventScript_1EF2C0:: @ 81EF2C0
	lock
	faceplayer
	markasdialog
	msgbox Route110_Text_1EFB93, MSGBOX_DEFAULT
	faceoriginaldir
	release
	end
Route110_Text_1EFB93: @ 81EFB93
	.string "I want to get going to Slateport and\n"
	.string "kick up a ruckus!$"


Route110_EventScript_1EF2D6:: @ 81EF2D6
	lock
	faceplayer
	markasdialog
	msgbox Route110_Text_1EFBCA, MSGBOX_DEFAULT
	faceoriginaldir
	release
	end
Route110_Text_1EFBCA: @ 81EFBCA
	.string "This is my first job after joining\n"
	.string "Team Aqua. It's a little scary.$"


Route110_EventScript_1EF2EC:: @ 81EF2EC
	lock
	faceplayer
	markasdialog
	msgbox Route110_Text_1EFC0D, MSGBOX_DEFAULT
	faceoriginaldir
	release
	end
Route110_Text_1EFC0D: @ 81EFC0D
	.string "Team Aqua's actions should bring\n"
	.string "smiles to people's faces!$"


Route110_EventScript_1EF302:: @ 81EF302
	msgbox Route110_Text_1EFFC3, MSGBOX_NPC
	end
Route110_Text_1EFFC3: @ 81EFFC3
	.string "Wouldn't it be great to ride a bike\n"
	.string "at full speed on Cycling Road?$"


Route110_EventScript_1EF30B:: @ 81EF30B
	msgbox Route110_Text_1F0006, MSGBOX_NPC
	end
Route110_Text_1F0006: @ 81F0006
	.string "How do you like the way my raven-\n"
	.string "colored hair streams behind me?\p"
	.string "I grew my hair out just for that.$"


Route110_EventScript_1EF314:: @ 81EF314
	msgbox Route110_Text_1F006A, MSGBOX_NPC
	end
Route110_Text_1F006A: @ 81F006A
	.string "Oh, hey, you got that bike from RYDEL!\p"
	.string "Oh, it's glaringly obvious.\n"
	.string "It says right on your bike…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "That name's everywhere.\p"
	.string "You should ride it around all over\n"
	.string "the place--it's good advertising!$"


Route110_EventScript_1EF31D:: @ 81EF31D
	msgbox Route110_Text_1F0261, MSGBOX_NPC
	end
Route110_Text_1F0261: @ 81F0261
	.string "The two roads, one above, one below…\p"
	.string "A road each for people and Pokémon.\n"
	.string "Perhaps that is right and fair.$"


Route110_EventScript_1EF326:: @ 81EF326
	msgbox Route110_Text_1F02CA, MSGBOX_NPC
	end
Route110_Text_1F02CA: @ 81F02CA
	.string "I don't have a bike, so I'll take\n"
	.string "a leisurely walk on the low road.$"


Route110_EventScript_1EF32F:: @ 81EF32F
	msgbox Route110_Text_1F030E, MSGBOX_NPC
	end
Route110_Text_1F030E: @ 81F030E
	.string "Learning techniques will make bike\n"
	.string "riding even more fun.\p"
	.string "There are some places that you can\n"
	.string "reach only by using a bike technique.$"


Route110_EventScript_1EF338:: @ 81EF338
	msgbox Route110_Text_1F0390, MSGBOX_NPC
	end
Route110_Text_1F0390: @ 81F0390
	.string "Which should I choose?\p"
	.string "Make a beeline for Mauville on\n"
	.string "Cycling Road, or take the low road\l"
	.string "and look for Pokémon?$"


Route110_EventScript_1EF3B7:: @ 81EF3B7
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF3E8
	compare VAR_CYCLING_CHALLENGE_STATE, 0
	goto_if_eq Route110_EventScript_1EF3DE
	msgbox Route110_Text_1F06FB, MSGBOX_DEFAULT
	release
	end
Route110_Text_1F06FB: @ 81F06FB
	.string "Regardless of the results, I count on\n"
	.string "seeing more challenges from you.\l"
	.string "Always aim higher!$"
Route110_EventScript_1EF3DE:: @ 81EF3DE
	msgbox Route110_Text_1F0661, MSGBOX_DEFAULT
	release
	end
Route110_Text_1F0661: @ 81F0661
	.string "This is Cycling Road.\p"
	.string "If you were to ride from Mauville to\n"
	.string "Slateport on a Mach Bike, you would\l"
	.string "be rated for the number of collisions\l"
	.string "and your total time.$"
Route110_EventScript_1EF3E8:: @ 81EF3E8
	msgbox Route110_Text_1F0755, MSGBOX_DEFAULT
	release
	end
Route110_Text_1F0755: @ 81F0755
	.string "On this Cycling Road, those riding\n"
	.string "Mach Bikes are rated for their number\l"
	.string "of collisions and their total times.\p"
	.string "Acro Bikes do not qualify for rating.\n"
	.string "They are easy to turn, so it's not fair.$"

@ -----------------------------------------------------
@ Trainers

Route110_EventScript_1EF3F2:: @ 81EF3F2
	trainerbattle_single TRAINER_EDWARD, Route110_Text_29802B, Route110_Text_298064
	msgbox Route110_Text_29808A, MSGBOX_AUTOCLOSE
	end
Route110_Text_29802B: @ 829802B
	.string "I have foreseen your intentions!\n"
	.string "I cannot possibly lose!$"
Route110_Text_298064: @ 8298064
	.string "I failed to prophesize my own demise!$"
Route110_Text_29808A: @ 829808A
	.string "I see your future…\p"
	.string "Hmm…\n"
	.string "I see a shining light…$"


Route110_EventScript_1EF409:: @ 81EF409
	trainerbattle_single TRAINER_JACLYN, Route110_Text_2980B9, Route110_Text_2980E5
	msgbox Route110_Text_2980F8, MSGBOX_AUTOCLOSE
	end
Route110_Text_2980B9: @ 82980B9
	.string "Ahahahaha!\n"
	.string "I'll dazzle you with my wonders!$"
Route110_Text_2980E5: @ 82980E5
	.string "I wondrously lost!$"
Route110_Text_2980F8: @ 82980F8
	.string "You managed to win only because it was\n"
	.string "a wonder! Yes, a wonder!\l"
	.string "Don't think you can win all the time!$"


Route110_EventScript_1EF420:: @ 81EF420
	trainerbattle_single TRAINER_EDWIN_1, Route110_Text_29815E, Route110_Text_29818F, Route110_EventScript_1EF44C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF46B
	msgbox Route110_Text_2981B3, MSGBOX_DEFAULT
	release
	end
Route110_Text_29815E: @ 829815E
	.string "Could I see your Pokémon?\n"
	.string "Just one look, please?$"
Route110_Text_29818F: @ 829818F
	.string "I wanted to complete\n"
	.string "my collection…$"
Route110_Text_2981B3: @ 82981B3
	.string "When I see a Pokémon that I don't know,\n"
	.string "my passion as a collector is ignited!$"
Route110_EventScript_1EF44C:: @ 81EF44C
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route110_Text_298201, MSGBOX_DEFAULT
	register_matchcall TRAINER_EDWIN_1
	release
	end
Route110_Text_298201: @ 8298201
	.string "I like collecting match call\n"
	.string "registrations, too…$"
Route110_EventScript_1EF46B:: @ 81EF46B
	trainerbattle_rematch TRAINER_EDWIN_1, Route110_Text_298232, Route110_Text_298288
	msgbox Route110_Text_2982A2, MSGBOX_AUTOCLOSE
	end
Route110_Text_298232: @ 8298232
	.string "Hi, have you caught any new Pokémon?\p"
	.string "Could I see your Pokémon?\n"
	.string "Just one look, please?$"
Route110_Text_298288: @ 8298288
	.string "Your Pokémon…\n"
	.string "I envy you.$"
Route110_Text_2982A2: @ 82982A2
	.string "Oh, I long to make all rare Pokémon\n"
	.string "mine!$"


Route110_EventScript_1EF482:: @ 81EF482
	trainerbattle_single TRAINER_DALE, Route110_Text_2982CC, Route110_Text_2982F5
	msgbox Route110_Text_298303, MSGBOX_AUTOCLOSE
	end
Route110_Text_2982CC: @ 82982CC
	.string "Hey!\n"
	.string "Don't sneak up behind me like that!$"
Route110_Text_2982F5: @ 82982F5
	.string "I lost!\n"
	.string "Drat!$"
Route110_Text_298303: @ 8298303
	.string "Fishing is all about concentration.\n"
	.string "You have to focus on the floater.$"


Route110_EventScript_1EF499:: @ 81EF499
	trainerbattle_single TRAINER_JACOB, Route110_Text_297B3F, Route110_Text_297B77
	msgbox Route110_Text_297B8F, MSGBOX_AUTOCLOSE
	end
Route110_Text_297B3F: @ 8297B3F
	.string "Whoa! Watch it!\n"
	.string "I guess you're not used to bike racing.$"
Route110_Text_297B77: @ 8297B77
	.string "Whoa!\n"
	.string "My brakes failed!$"
Route110_Text_297B8F: @ 8297B8F
	.string "Flat tires and brake problems can\n"
	.string "cause serious injury!\l"
	.string "Inspect your bike for problems!$"


Route110_EventScript_1EF4B0:: @ 81EF4B0
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_297BE7, Route110_Text_297C0F
	msgbox Route110_Text_297C1F, MSGBOX_AUTOCLOSE
	end
Route110_Text_297BE7: @ 8297BE7
	.string "Yo, you!\n"
	.string "Can you keep up with my speed?$"
Route110_Text_297C0F: @ 8297C0F
	.string "Crash and burn!$"
Route110_Text_297C1F: @ 8297C1F
	.string "Speed alone won't let me win at Pokémon.\n"
	.string "I need to reconsider this…$"


Route110_EventScript_1EF4C7:: @ 81EF4C7
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_297C63, Route110_Text_297C8A, Route110_EventScript_1EF4F3
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF512
	msgbox Route110_Text_297CB4, MSGBOX_DEFAULT
	release
	end
Route110_Text_297C63: @ 8297C63
	.string "Don't panic if your BIKE's going fast!$"
Route110_Text_297C8A: @ 8297C8A
	.string "I shouldn't panic during Pokémon\n"
	.string "battles…$"
Route110_Text_297CB4: @ 8297CB4
	.string "There's no need to panic or stress.\n"
	.string "Take it easy. There's plenty of time.$"
Route110_EventScript_1EF4F3:: @ 81EF4F3
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route110_Text_297CFE, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end
Route110_Text_297CFE: @ 8297CFE
	.string "I'll keep chugging on without stressing.\n"
	.string "Give me a shout if you're up to it.$"
Route110_EventScript_1EF512:: @ 81EF512
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_297D4B, Route110_Text_297D8E
	msgbox Route110_Text_297DB0, MSGBOX_AUTOCLOSE
	end
Route110_Text_297D4B: @ 8297D4B
	.string "Aren't you going a little too fast?\n"
	.string "Take it easy and let's battle.$"
Route110_Text_297D8E: @ 8297D8E
	.string "I didn't panic, but I still lost…$"
Route110_Text_297DB0: @ 8297DB0
	.string "There's no need to panic or stress.\n"
	.string "Take it easy. There's plenty of time.$"


Route110_EventScript_1EF529:: @ 81EF529
	trainerbattle_single TRAINER_JASMINE, Route110_Text_297F93, Route110_Text_297FD0
	msgbox Route110_Text_297FF1, MSGBOX_AUTOCLOSE
	end
Route110_Text_297F93: @ 8297F93
	.string "I've been riding without stopping.\n"
	.string "My thighs are like rocks!$"
Route110_Text_297FD0: @ 8297FD0
	.string "I'm worried about muscle cramps…$"
Route110_Text_297FF1: @ 8297FF1
	.string "Oh, you have some Gym Badges?\n"
	.string "No wonder you're so strong!$"


Route110_EventScript_1EF540:: @ 81EF540
	trainerbattle_single TRAINER_ABIGAIL_1, Route110_Text_297DFA, Route110_Text_297E69, Route110_EventScript_1EF56C
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF58B
	msgbox Route110_Text_297E88, MSGBOX_DEFAULT
	release
	end
Route110_Text_297DFA: @ 8297DFA
	.string "The triathlon is hard in the extreme.\p"
	.string "You have to complete the three events\n"
	.string "of swimming, cycling, and running.$"
Route110_Text_297E69: @ 8297E69
	.string "Pokémon battles are hard, too!$"
Route110_Text_297E88: @ 8297E88
	.string "I'm exhausted, so I need a break.\n"
	.string "It's important to get proper rest.$"
Route110_EventScript_1EF56C:: @ 81EF56C
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route110_Text_297ECD, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABIGAIL_1
	release
	end
Route110_Text_297ECD: @ 8297ECD
	.string "You know, I like you!\n"
	.string "Let's have a rematch on Cycling Road.$"
Route110_EventScript_1EF58B:: @ 81EF58B
	trainerbattle_rematch TRAINER_ABIGAIL_1, Route110_Text_297F09, Route110_Text_297F37
	msgbox Route110_Text_297F58, MSGBOX_AUTOCLOSE
	end
Route110_Text_297F09: @ 8297F09
	.string "Isn't it neat to hold a battle while\n"
	.string "cycling?$"
Route110_Text_297F37: @ 8297F37
	.string "Wow…\n"
	.string "How could you be so strong?$"
Route110_Text_297F58: @ 8297F58
	.string "Were you going after a record?\p"
	.string "I'm sorry if I held you up!$"


Route110_EventScript_1EF5A2:: @ 81EF5A2
	trainerbattle_single TRAINER_ISABEL_1, Route110_Text_298349, Route110_Text_298389, Route110_EventScript_1EF5CE
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route110_EventScript_1EF5ED
	msgbox Route110_Text_2983A2, MSGBOX_DEFAULT
	release
	end
Route110_Text_298349: @ 8298349
	.string "Ahahaha! I would go anywhere to show\n"
	.string "off my delightful Pokémon.$"
Route110_Text_298389: @ 8298389
	.string "Oh, dear, this won't do.$"
Route110_Text_2983A2: @ 82983A2
	.string "Rather than battling, perhaps I should\n"
	.string "show off my Pokémon at the fan club.$"
Route110_EventScript_1EF5CE:: @ 81EF5CE
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route110_Text_2983EE, MSGBOX_DEFAULT
	register_matchcall TRAINER_ISABEL_1
	release
	end
Route110_Text_2983EE: @ 82983EE
	.string "That wasn't close to what I could\n"
	.string "do to show off my Pokémon.\p"
	.string "I'll have you as my captive audience\n"
	.string "as often as possible!$"
Route110_EventScript_1EF5ED:: @ 81EF5ED
	trainerbattle_rematch TRAINER_ISABEL_1, Route110_Text_298466, Route110_Text_2984AF
	msgbox Route110_Text_2984C8, MSGBOX_AUTOCLOSE
	end
Route110_Text_298466: @ 8298466
	.string "Ahahahaha! I would be happy to show\n"
	.string "off my Pokémon as often as you like!$"
Route110_Text_2984AF: @ 82984AF
	.string "Oh, dear, this won't do.$"
Route110_Text_2984C8: @ 82984C8
	.string "I don't think that I could ever stop\n"
	.string "from showing off my Pokémon.\p"
	.string "But I like to battle, too!$"


Route110_EventScript_1EF604:: @ 81EF604
	trainerbattle_single TRAINER_TIMMY, Route110_Text_298525, Route110_Text_298559
	msgbox Route110_Text_298579, MSGBOX_AUTOCLOSE
	end
Route110_Text_298525: @ 8298525
	.string "I found some cool Pokémon in the grass\n"
	.string "around here!$"
Route110_Text_298559: @ 8298559
	.string "Being cool isn't enough to win…$"
Route110_Text_298579: @ 8298579
	.string "It's hard to battle with Pokémon you\n"
	.string "just caught.$"


Route110_EventScript_1EF61C:: @ 81EF61C
	trainerbattle_single TRAINER_KALEB, Route110_Text_2986ED, Route110_Text_298735
	msgbox Route110_Text_298755, MSGBOX_AUTOCLOSE
	end
Route110_Text_2986ED: @ 82986ED
	.string "When cute Pokémon help each other…\n"
	.string "You won't see a more adorable sight!$"
Route110_Text_298735: @ 8298735
	.string "Have you no compassion or pity?$"
Route110_Text_298755: @ 8298755
	.string "Okay, okay, you've done the best you\n"
	.string "could, my pretties.$"


Route110_EventScript_1EF633:: @ 81EF633
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_298642, Route110_Text_298686
	msgbox Route110_Text_2986A9, MSGBOX_AUTOCLOSE
	end
Route110_Text_298642: @ 8298642
	.string "Okay! Full-throttle time! If you can't\n"
	.string "groove, you get left behind!$"
Route110_Text_298686: @ 8298686
	.string "You got into the groove all right…$"
Route110_Text_2986A9: @ 82986A9
	.string "This isn't going to bring me down!\n"
	.string "Losing has made me a better man!$"


Route110_EventScript_1EF64A:: @ 81EF64A
	trainerbattle_single TRAINER_ALYSSA, Route110_Text_2985AB, Route110_Text_2985F9
	msgbox Route110_Text_298612, MSGBOX_AUTOCLOSE
	end
Route110_Text_2985AB: @ 82985AB
	.string "I fell off Cycling Road…\p"
	.string "I'll get over my embarrassment by\n"
	.string "battling with you!$"
Route110_Text_2985F9: @ 82985F9
	.string "Oops!\n"
	.string "I ended up losing!$"
Route110_Text_298612: @ 8298612
	.string "Falling… Losing…\n"
	.string "This is so humiliating for me!$"

@ -----------------------------------------------------
@ Cycling Road Challenge

Route110_TriggerScript_FinishCyclingRoadChallenge:: @ 81EF661
	lockall
	markasdialog
	applymovement 21, Common_Movement_WalkInPlaceRight
	waitmovement 0
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_1F03FF, MSGBOX_DEFAULT
	selectpointer_clamp Route110_StringTable_FinishCyclingRoadChallenge, VAR_RESULT
	msgbox_selected
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	@ savebgm MUS_DUMMY
	@ fadedefaultbgm
	releaseall
	end

.align 2
Route110_StringTable_FinishCyclingRoadChallenge:
	.4byte Route110_Text_FinishCyclingRoadChallenge_Terrible @0
	.4byte Route110_Text_FinishCyclingRoadChallenge_Poor @1
	.4byte Route110_Text_FinishCyclingRoadChallenge_Poor
	.4byte Route110_Text_FinishCyclingRoadChallenge_Poor
	.4byte Route110_Text_FinishCyclingRoadChallenge_Acceptable
	.4byte Route110_Text_FinishCyclingRoadChallenge_Acceptable @5
	.4byte Route110_Text_FinishCyclingRoadChallenge_Acceptable
	.4byte Route110_Text_FinishCyclingRoadChallenge_Good
	.4byte Route110_Text_FinishCyclingRoadChallenge_Good
	.4byte Route110_Text_FinishCyclingRoadChallenge_Good
	.4byte Route110_Text_FinishCyclingRoadChallenge_Best @10
	.4byte 0

Route110_Text_1F03FF: @ 81F03FF
	.string "Number of collisions:\n"
	.string "… … {STR_VAR_1}!\p"
	.string "Total time:\n"
	.string "… … {STR_VAR_2}!$"
Route110_Text_FinishCyclingRoadChallenge_Best: @ 81F0431
	.string "Bravo! Splendid showing!\p"
	.string "Your love of cycling comes from deep\n"
	.string "within your heart.\l"
	.string "You've shaken me to my very soul!$"
Route110_Text_FinishCyclingRoadChallenge_Good: @ 81F04A4
	.string "Your technique is remarkable.\p"
	.string "I suggest you speed up a bit while\n"
	.string "still avoiding collisions.$"
Route110_Text_FinishCyclingRoadChallenge_Acceptable: @ 81F0500
	.string "I would consider you a work in\n"
	.string "progress.\p"
	.string "Still, I hope you don't forget the\n"
	.string "sheer pleasure of cycling.$"
Route110_Text_FinishCyclingRoadChallenge_Poor: @ 81F0567
	.string "My word… Your cycling skills border\n"
	.string "on terrifying.\p"
	.string "Most certainly, you need much more\n"
	.string "practice riding.$"
Route110_Text_FinishCyclingRoadChallenge_Terrible: @ 81F05CE
	.string "…I am aghast…\p"
	.string "You're perhaps not cut out for this\n"
	.string "unfortunate cycling business.\p"
	.string "You ought to give serious thought to\n"
	.string "returning that bike to Rydel.$"

@ -----------------------------------------------------
@ Rival

Route110_EventScript_1EF74D:: @ 81EF74D
	setvar VAR_0x8008, 1
	goto Route110_EventScript_1EF76E
	end

Route110_EventScript_1EF758:: @ 81EF758
	setvar VAR_0x8008, 2
	goto Route110_EventScript_1EF76E
	end

Route110_EventScript_1EF763:: @ 81EF763
	setvar VAR_0x8008, 3
	goto Route110_EventScript_1EF76E
	end

Route110_EventScript_1EF76E:: @ 81EF76E
	lockall
	markasdialog
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq Route110_EventScript_1EF7E1
	compare VAR_RESULT, FEMALE
	call_if_eq Route110_EventScript_1EF7E6
	applymovement 28, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement 28, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 28, Common_Movement_Delay48
	waitmovement 0
	delay 30
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EF94E
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EF959
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EF964
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route110_EventScript_1EF7EB
	compare VAR_RESULT, FEMALE
	goto_if_eq Route110_EventScript_1EF865
	releaseall
	end

Route110_EventScript_1EF7E1:: @ 81EF7E1
	playbgm MUS_GIRL_SUP, 1
	return

Route110_EventScript_1EF7E6:: @ 81EF7E6
	playbgm MUS_BOY_SUP, 1
	return

Route110_EventScript_1EF7EB:: @ 81EF7EB
	msgbox Route110_Text_1EFC48, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_1EF81A
	case 1, Route110_EventScript_1EF82A
	case 2, Route110_EventScript_1EF83A
	end
Route110_Text_1EFC48: @ 81EFC48
	.string "May: Oh! {PLAYER}! Ha, long time no see!\p"
	.string "Wow! What's… what's that on your head?\n"
	.string "That's a new look.\p"
	.string "You running with some new friends or\n"
	.string "something? That's… … … great!\p"
	.string "H-How about a little battle?$"

Route110_EventScript_1EF81A:: @ 81EF81A
	trainerbattle_no_intro TRAINER_MAY_5, Route110_Text_1EFCCB
	goto Route110_EventScript_1EF84A
	end
Route110_EventScript_1EF82A:: @ 81EF82A
	trainerbattle_no_intro TRAINER_MAY_8, Route110_Text_1EFCCB
	goto Route110_EventScript_1EF84A
	end
Route110_EventScript_1EF83A:: @ 81EF83A
	trainerbattle_no_intro TRAINER_MAY_2, Route110_Text_1EFCCB
	goto Route110_EventScript_1EF84A
	end
Route110_Text_1EFCCB: @ 81EFCCB
	.string "Yikes!\n"
	.string "You're worse than I expected!$"

Route110_EventScript_1EF84A:: @ 81EF84A
	markasdialog
	msgbox Route110_Text_1EFCF1, MSGBOX_DEFAULT
	call Route110_EventScript_1EF8DF
	msgbox Route110_Text_1EFD58, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF8EC
	end
Route110_Text_1EFCF1: @ 81EFCF1
	.string "May: {PLAYER}, you've uh… been training\n"
	.string "new Pokémon, huh…\p"
	.string "Hey, uh… I have this thing! That I'd\n"
	.string "like you to have! Maybe make it your\l"
	.string "new hobby or something!$"
Route110_Text_1EFD58: @ 81EFD58
	.string "May: It's an Itemfinder!\p"
	.string "Try it out. If there is an item that's\n"
	.string "not visible, it emits a sound.\p"
	.string "You could maybe spend some time doing\n"
	.string "that instead of abus--TRAINING new\l"
	.string "Pokémon, or hanging with hood--FRIENDS!\p"
	.string "… … …$"

Route110_EventScript_1EF865:: @ 81EF865
	msgbox Route110_Text_1EFE3F, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_1EF894
	case 1, Route110_EventScript_1EF8A4
	case 2, Route110_EventScript_1EF8B4
	end
Route110_Text_1EFE3F: @ 81EFE3F
	.string "Brendan: Hey! Uh… {PLAYER}!\n"
	.string "Don't sneak up on me like that!\l"
	.string "How's it going?\p"
	.string "That's uh… a cool bandanna you've got\n"
	.string "there. New crowd, huh?\p"
	.string "How've you been raising your Pokémon?\n"
	.string "I'll, uh… check for you.$"

Route110_EventScript_1EF894:: @ 81EF894
	trainerbattle_no_intro TRAINER_BRENDAN_5, Route110_Text_1EFEB4
	goto Route110_EventScript_1EF8C4
	end
Route110_EventScript_1EF8A4:: @ 81EF8A4
	trainerbattle_no_intro TRAINER_BRENDAN_8, Route110_Text_1EFEB4
	goto Route110_EventScript_1EF8C4
	end
Route110_EventScript_1EF8B4:: @ 81EF8B4
	trainerbattle_no_intro TRAINER_BRENDAN_2, Route110_Text_1EFEB4
	goto Route110_EventScript_1EF8C4
	end
Route110_Text_1EFEB4: @ 81EFEB4
	.string "Hmm…\n"
	.string "That's… that's not good…$"

Route110_EventScript_1EF8C4:: @ 81EF8C4
	markasdialog
	msgbox Route110_Text_1EFECD, MSGBOX_DEFAULT
	call Route110_EventScript_1EF8DF
	msgbox Route110_Text_1EFF1C, MSGBOX_DEFAULT
	goto Route110_EventScript_1EF8EC
	end
Route110_Text_1EFECD: @ 81EFECD
	.string "Brendan: {PLAYER}, you've trained some\n"
	.string "new Pokémon, eh, without my knowing…?\p"
	.string "Uh… Here! Take this!$"
Route110_Text_1EFF1C: @ 81EFF1C
	.string "Brendan: This! This is… amazing!\p"
	.string "It's an Itemfinder! Use it to root\n"
	.string "around for items that aren't visible!\p"
	.string "If it senses something, it emits\n"
	.string "a sound.\p"
	.string "Maybe you'll like it enough to take up\n"
	.string "as a hobby. One that doesn't involve…\l"
	.string "stealing things and… abusing Pokémon…\p"
	.string "… … …$"

Route110_EventScript_1EF8DF:: @ 81EF8DF
	giveitem_std ITEM_ITEMFINDER
	return

Route110_EventScript_1EF8EC:: @ 81EF8EC
	closemessage
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EF990
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EF998
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EF9A0
	setobjectmovementtype 28, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype 29, MOVEMENT_TYPE_FACE_RIGHT
	removeobject 28
	addobject 29
	delay 45
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EF96F
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EF97A
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EF985
	removeobject 29
	setvar VAR_ROUTE110_STATE, 1
	setflag FLAG_DEFEATED_RIVAL_R110
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_1EF94E:: @ 81EF94E
	applymovement 28, Route110_Movement_1EF9A8
	waitmovement 0
	return

Route110_EventScript_1EF959:: @ 81EF959
	applymovement 28, Route110_Movement_1EF9AC
	waitmovement 0
	return

Route110_EventScript_1EF964:: @ 81EF964
	applymovement 28, Route110_Movement_1EF9AE
	waitmovement 0
	return

Route110_EventScript_1EF96F:: @ 81EF96F
	applymovement 29, Route110_Movement_1EF9B2
	waitmovement 0
	return

Route110_EventScript_1EF97A:: @ 81EF97A
	applymovement 29, Route110_Movement_1EF9BA
	waitmovement 0
	return

Route110_EventScript_1EF985:: @ 81EF985
	applymovement 29, Route110_Movement_1EF9C3
	waitmovement 0
	return

Route110_EventScript_1EF990:: @ 81EF990
	setobjectxyperm 29, 33, 55
	return

Route110_EventScript_1EF998:: @ 81EF998
	setobjectxyperm 29, 34, 55
	return

Route110_EventScript_1EF9A0:: @ 81EF9A0
	setobjectxyperm 29, 35, 55
	return

Route110_Movement_1EF9A8: @ 81EF9A8
	walk_down
	walk_left
	walk_in_place_fastest_down
	step_end

Route110_Movement_1EF9AC: @ 81EF9AC
	walk_down
	step_end

Route110_Movement_1EF9AE: @ 81EF9AE
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end

Route110_Movement_1EF9B2: @ 81EF9B2
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_1EF9BA: @ 81EF9BA
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_1EF9C3: @ 81EF9C3
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

@ -----------------------------------------------------
@ Birch

Route110_EventScript_1EF9CB:: @ 81EF9CB
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9D6:: @ 81EF9D6
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9E1:: @ 81EF9E1
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9EC:: @ 81EF9EC
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_1EF9F7

Route110_EventScript_1EF9F7:: @ 81EF9F7
	markasdialog
	addobject 36
	applymovement 36, Route110_Movement_1EFB30
	waitmovement 0
	playse SE_PIN
	applymovement 36, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 36, Common_Movement_Delay48
	waitmovement 0
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EFAD8
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EFAE3
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EFAEE
	compare VAR_0x8008, 4
	call_if_eq Route110_EventScript_1EFAF9
	msgbox Route110_Text_1F0AB5, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement 36, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	applymovement 36, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 20
	applymovement 36, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_1F0AFF, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_ME_TORE_EYE
	msgbox Route110_Text_1F0C0C, MSGBOX_CDESCRIBE
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_1F0C33, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 1
	call_if_eq Route110_EventScript_1EFB04
	compare VAR_0x8008, 2
	call_if_eq Route110_EventScript_1EFB0F
	compare VAR_0x8008, 3
	call_if_eq Route110_EventScript_1EFB1A
	compare VAR_0x8008, 4
	call_if_eq Route110_EventScript_1EFB25
	removeobject 36
	setvar VAR_0x40DA, 2
	releaseall
	end
Route110_Text_1F0AB5: @ 81F0AB5
	.string "Prof. Birch: Oh, {PLAYER}!\n"
	.string "Imagine seeing you here!\p"
	.string "And where might my {RIVAL} be?$"
Route110_Text_1F0AFF: @ 81F0AFF
	.string "Oh, I see!\n"
	.string "You two are running separately.\l"
	.string "Well, that's fine.\p"
	.string "Oh, yes, I heard that your PokéNav\n"
	.string "had the match call system installed.\p"
	.string "Well, then, I should register you in\n"
	.string "my PokéNav as well.\p"
	.string "That way, even when we're apart,\n"
	.string "I can rate your Pokédex anytime.\p"
	.string "… … … … … …$"
Route110_Text_1F0C0C: @ 81F0C0C
	.string "Registered Prof. Birch\n"
	.string "in the PokéNav.$"
Route110_Text_1F0C33: @ 81F0C33
	.string "Prof. Birch: {PLAYER}…\p"
	.string "Please keep an eye out for my {RIVAL}.\n"
	.string "… … … … … …\p"
	.string "Well, I had better get going.\n"
	.string "See you again, {PLAYER}!$"

Route110_EventScript_1EFAD8:: @ 81EFAD8
	applymovement 36, Route110_Movement_1EFB34
	waitmovement 0
	return

Route110_EventScript_1EFAE3:: @ 81EFAE3
	applymovement 36, Route110_Movement_1EFB39
	waitmovement 0
	return

Route110_EventScript_1EFAEE:: @ 81EFAEE
	applymovement 36, Route110_Movement_1EFB3D
	waitmovement 0
	return

Route110_EventScript_1EFAF9:: @ 81EFAF9
	applymovement 36, Route110_Movement_1EFB40
	waitmovement 0
	return

Route110_EventScript_1EFB04:: @ 81EFB04
	applymovement 36, Route110_Movement_1EFB44
	waitmovement 0
	return

Route110_EventScript_1EFB0F:: @ 81EFB0F
	applymovement 36, Route110_Movement_1EFB4B
	waitmovement 0
	return

Route110_EventScript_1EFB1A:: @ 81EFB1A
	applymovement 36, Route110_Movement_1EFB51
	waitmovement 0
	return

Route110_EventScript_1EFB25:: @ 81EFB25
	applymovement 36, Route110_Movement_1EFB57
	waitmovement 0
	return

Route110_Movement_1EFB30: @ 81EFB30
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_1EFB34: @ 81EFB34
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_1EFB39: @ 81EFB39
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_1EFB3D: @ 81EFB3D
	walk_down
	walk_down
	step_end

Route110_Movement_1EFB40: @ 81EFB40
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_1EFB44: @ 81EFB44
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_1EFB4B: @ 81EFB4B
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_1EFB51: @ 81EFB51
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_1EFB57: @ 81EFB57
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

