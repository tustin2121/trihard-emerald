VictoryRoad_1F_MapScripts:: @ 8235D7A
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	.byte 0

@ -----------------------------------------------------

#define LID_LOGAN 4

VictoryRoad_1F_OnTransition: @ 8235D80
	compare VAR_VICTORY_ROAD_1F_STATE, 1
	call_if_eq VictoryRoad_1F_EventScript_235D97
	compare VAR_VICTORY_ROAD_1F_STATE, 2
	call_if_eq VictoryRoad_1F_EventScript_235DA3
	end

VictoryRoad_1F_EventScript_235D97:: @ 8235D97
	setobjectxyperm LID_LOGAN, 2, 24
	setobjectmovementtype LID_LOGAN, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_235DA3:: @ 8235DA3
	setobjectxyperm LID_LOGAN, 3, 24
	setobjectmovementtype LID_LOGAN, MOVEMENT_TYPE_FACE_DOWN
	return

@ -----------------------------------------------------

VictoryRoad_1F_TriggerScript_Logan1:: @ 8235DAF
	lockall
	setvar VAR_0x8008, 1
	addobject LID_LOGAN
	applymovement LID_LOGAN, VictoryRoad_1F_Movement_235E15
	waitmovement 0
	goto VictoryRoad_1F_EventScript_LoganFight
	end

VictoryRoad_1F_TriggerScript_Logan2:: @ 8235DC8
	lockall
	setvar VAR_0x8008, 2
	addobject LID_LOGAN
	applymovement LID_LOGAN, VictoryRoad_1F_Movement_235E21
	waitmovement 0
	goto VictoryRoad_1F_EventScript_LoganFight
	end

VictoryRoad_1F_EventScript_LoganFight:: @ 8235DE1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	@
	markasdialog
	message VictoryRoad_1F_Text_LoganFight1
	waitmessage
	select_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, VictoryRoad_1F_Text_LoganFight2b, VictoryRoad_1F_Text_LoganFight2a
	message 0
	waitmessage
	message VictoryRoad_1F_Text_LoganFight3
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	message VictoryRoad_1F_Text_LoganFight4, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	message VictoryRoad_1F_Text_LoganFight5
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	message VictoryRoad_1F_Text_LoganFight6, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	message VictoryRoad_1F_Text_LoganFight7
	waitmessage
	waitbuttonpress
	@ Battle!
	trainerbattle_no_intro TRAINER_WALLY_1, VictoryRoad_1F_Text_LoganLose
	msgbox VictoryRoad_1F_Text_LoganFightPost, MSGBOX_DEFAULT
	@ clearflag FLAG_HIDE_VICTORY_ROAD_ENTRANCE_WALLY
	moveobjectoffscreen LID_LOGAN
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end
VictoryRoad_1F_Text_LoganFight1:
	.string "{RIVAL_HERO}: Oh, {PLAYER}, how are you?\p"
	.string "Listen, uh… I didn't… really get to talk\n"
	.string "to you after all that stuff in…\l"
	.string "in Sootopolis City…\p"
	.string "I…{PAUSE 20} I forgive you…{PAUSE 30} and I'm sorry…\p"
	.string "After I saw you on Mossdeep without\n"
	.string "the bandanna, I realized that maybe…\l"
	.string "maybe you had a change of heart.\p$"
VictoryRoad_1F_Text_LoganFight2a:
	.string "And… you were the one to help me\n"
	.string "find Rayquaza and all.\p$"
VictoryRoad_1F_Text_LoganFight2b:
	.string "And then you just went and fought the\n"
	.string "giant beasts singlehandedly…!\p"
	.string "Which is either really brave or\n"
	.string "REALLY stupid, by the way…\p$"
VictoryRoad_1F_Text_LoganFight3:
	.string "So… maybe we can be friends after all…\p"
	.string "Or at least not enemies…\p"
	.string "Here, as a gesture of… apology…\n"
	.string "I got you this…$"
VictoryRoad_1F_Text_LoganFight4:
	.string "{RIVAL_HERO} hands {PLAYER} a hat.{PAUSE 30}\n"
	.string "{PLAYER} raises an eyebrow at him.$"
VictoryRoad_1F_Text_LoganFight5:
	.string "{RIVAL_HERO}: I figured you needed something new\n"
	.string "to wear, since you ditched the bandanna.$"
VictoryRoad_1F_Text_LoganFight6:
	.string "{RIVAL_HERO} claiming to know anything about\n"
	.string "fashion is laughable…\p"
	.string "But {PLAYER} puts the hat away anyway,\n"
	.string "if only to keep {RIVAL_HERO} happy.$"
VictoryRoad_1F_Text_LoganFight7:
	.string "So…{PAUSE 10} …{PAUSE 10} …{PAUSE 10} Not-Enemy…{PAUSE 20} You wanna battle\n"
	.string "one more time before the League?\p"
	.string "Our eyes met, it's the rules!\n"
	.string "Let's go!$"
VictoryRoad_1F_Text_LoganLose:
	.string "Enough! I forfeit! You win.$"
VictoryRoad_1F_Text_LoganFightPost:
	.string "Arceus wept, {PLAYER}…\p"
	.string "You're still way too rough with your\n"
	.string "Pokémon…\p"
	.string "I know we just had a heart-to-heart and\n"
	.string "all that, but… as a friend…\p"
	.string "You need to cool it.\n" @fallthrough
VictoryRoad_1F_Text_LoganPostBattle:
	.string "You're driving your Pokémon too hard.\p"
	.string "Just… think about it, alright?$"
VictoryRoad_1F_EventScript_235E2C:: @ 8235E2C
	msgbox VictoryRoad_1F_Text_LoganPostBattle, MSGBOX_NPC
	end

VictoryRoad_1F_Movement_235E15: @ 8235E15
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_235E21: @ 8235E21
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end


#undef LID_LOGAN

@ -----------------------------------------------------
@ Trainers

VictoryRoad_1F_EventScript_235E73:: @ 8235E73
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_236184, VictoryRoad_1F_Text_2361CB
	msgbox VictoryRoad_1F_Text_2361E5, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_Text_236184: @ 8236184
	.string "I've made it this far a couple times,\n"
	.string "but the last stretch is so long…$"
VictoryRoad_1F_Text_2361CB: @ 82361CB
	.string "My dream ends here again…$"
VictoryRoad_1F_Text_2361E5: @ 82361E5
	.string "You've made it this far. Keep the\n"
	.string "momentum going and become the\l"
	.string "champion! If anyone can, it's you!$"


VictoryRoad_1F_EventScript_235E8A:: @ 8235E8A
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_236248, VictoryRoad_1F_Text_236290
	msgbox VictoryRoad_1F_Text_2362A4, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_Text_236248: @ 8236248
	.string "I didn't come all this way to lose now.\n"
	.string "That possibility doesn't exist!$"
VictoryRoad_1F_Text_236290: @ 8236290
	.string "Impossible…\n"
	.string "I lost?$"
VictoryRoad_1F_Text_2362A4: @ 82362A4
	.string "I lost here…\p"
	.string "That means I lack the qualifications\n"
	.string "to become the champion…$"


VictoryRoad_1F_EventScript_235EA1:: @ 8235EA1
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_2362EE, VictoryRoad_1F_Text_236336
	msgbox VictoryRoad_1F_Text_236356, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_Text_2362EE: @ 82362EE
	.string "This seemingly infinite and harsh road\n"
	.string "lives up to its name of Victory.$"
VictoryRoad_1F_Text_236336: @ 8236336
	.string "Your battle style is fantastic…$"
VictoryRoad_1F_Text_236356: @ 8236356
	.string "You seem to have the potential for\n"
	.string "becoming the champion.$"


VictoryRoad_1F_EventScript_235EB8:: @ 8235EB8
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_236390, VictoryRoad_1F_Text_2363C4
	msgbox VictoryRoad_1F_Text_2363D5, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_Text_236390: @ 8236390
	.string "What is the Victory Road?\n"
	.string "I'll tell you if you win!$"
VictoryRoad_1F_Text_2363C4: @ 82363C4
	.string "Okay!\n"
	.string "Well done!$"
VictoryRoad_1F_Text_2363D5: @ 82363D5
	.string "Getting through here safely--that's\n"
	.string "the final test for any trainer aiming\l"
	.string "to become the Pokémon Champion.\p"
	.string "That's why it's called the Victory\n"
	.string "Road.$"


VictoryRoad_1F_EventScript_235ECF:: @ 8235ECF
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_236468, VictoryRoad_1F_Text_2364A7
	msgbox VictoryRoad_1F_Text_2364BB, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_Text_236468: @ 8236468
	.string "I have nothing to say to anyone\n"
	.string "that's come this far. Come on!$"
VictoryRoad_1F_Text_2364A7: @ 82364A7
	.string "This is a disgrace…$"
VictoryRoad_1F_Text_2364BB: @ 82364BB
	.string "Humph, go right on ahead.\n"
	.string "See if I care.$"


VictoryRoad_1F_EventScript_ExitLogan:: @ 8235E35
	trainerbattle_single TRAINER_WALLY_3, VictoryRoad_1F_Text_236073, VictoryRoad_1F_Text_2360DA
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq VictoryRoad_1F_EventScript_235E5C
	msgbox VictoryRoad_1F_Text_2360FE, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_EventScript_235E5C:: @ 8235E5C
	trainerbattle_rematch TRAINER_WALLY_3, VictoryRoad_1F_Text_236073, VictoryRoad_1F_Text_2360DA
	msgbox VictoryRoad_1F_Text_2360FE, MSGBOX_AUTOCLOSE
	end
VictoryRoad_1F_Text_236073: @ 8236073
	.string "WALLY: Hi! {PLAYER}!\p"
	.string "I've gotten stronger since that last\n"
	.string "time! I wanted to show you, {PLAYER}!\p"
	.string "Okay… Here I come!$"
VictoryRoad_1F_Text_2360DA: @ 82360DA
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"
VictoryRoad_1F_Text_2360FE: @ 82360FE
	.string "WALLY: I couldn't beat you this time,\n"
	.string "too… But one of these days, {PLAYER},\l"
	.string "I'm going to catch up to you…\p"
	.string "And challenge the Pokémon League!$"

