Route103_MapScripts:: @ 81EC38E
	map_script MAP_SCRIPT_ON_TRANSITION, Route103_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route103_MapScript1_1EC3A4
	.byte 0

@ -----------------------------------------------------

Route103_OnTransition: @ 81EC399
	call Common_EventScript_SetupRivalGender
	call Route103_EventScript_2720AD
	end

@ -----------------------------------------------------

Route103_MapScript1_1EC3A4: @ 81EC3A4
	call_if_set FLAG_SYS_GAME_CLEAR, Route103_EventScript_1EC3AE
	end

Route103_EventScript_1EC3AE:: @ 81EC3AE
	setmetatile 45, 5, 159, 1
	setmetatile 45, 6, 167, 0
	return

@ -----------------------------------------------------
@ Rival

Route103_EventScript_Rival:: @ 81EC3C1
	lockall
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Route103_EventScript_1EC3DA
	compare VAR_RESULT, FEMALE
	goto_if_eq Route103_EventScript_1EC434
	end

Route103_EventScript_1EC3DA:: @ 81EC3DA
	msgbox Route103_Text_1EC7A6, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_GIRL_SUP, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_1EC7DE, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_1EC48E
	case 1, Route103_EventScript_1EC49E
	case 2, Route103_EventScript_1EC4AE
	end
Route103_Text_1EC7A6: @ 81EC7A6
	.string "May: Hi! Aren't you a cutie?\n"
	.string "Wait! Where are you going?$"
Route103_Text_1EC7DE: @ 81EC7DE
	.string "Ah! {PLAYER}! You startled me!\p"
	.string "I thought a Pokémon snuck up on me\n"
	.string "for a moment!\p"
	.string "Oh! Dad…{PAUSE 16} gave you a Pokémon.\n"
	.string "That's nice of him! You helped him out?\p"
	.string "Oh, yeah, sure. Let's battle and\n"
	.string "see how good you are!$"

Route103_EventScript_1EC434:: @ 81EC434
	msgbox Route103_Text_1EC989, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_BOY_SUP, 1
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	applymovement 2, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 2, Common_Movement_Delay48
	waitmovement 0
	msgbox Route103_Text_1EC9CE, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route103_EventScript_1EC4BE
	case 1, Route103_EventScript_1EC4CE
	case 2, Route103_EventScript_1EC4DE
	end
Route103_Text_1EC989: @ 81EC989
	.string "Brendan: Hey, little guy! How are you?\n"
	.string "Ok, so they live here too…$"
Route103_Text_1EC9CE: @ 81EC9CE
	.string "Oh! {PLAYER}! Don't scare me like that!\n"
	.string "I thought a Pokémon snuck up on me!\p"
	.string "…Dad gave {BOLD}you{END} a Pokémon?{PAUSE 16}\p"
	.string "S-Sorry, I didn't mean it like that!\p"
	.string "Sure, alright, let's battle.\n"
	.string "I'll teach you a thing or two\l"
	.string "about being a trainer.$"

Route103_EventScript_1EC48E:: @ 81EC48E
	trainerbattle_no_intro TRAINER_MAY_4, Route103_Text_1EC881
	goto Route103_EventScript_1EC4EE
	end
Route103_EventScript_1EC49E:: @ 81EC49E
	trainerbattle_no_intro TRAINER_MAY_7, Route103_Text_1EC881
	goto Route103_EventScript_1EC4EE
	end
Route103_EventScript_1EC4AE:: @ 81EC4AE
	trainerbattle_no_intro TRAINER_MAY_1, Route103_Text_1EC881
	goto Route103_EventScript_1EC4EE
	end
Route103_Text_1EC881: @ 81EC881
	.string "…Wow… you're really tough…$"

Route103_EventScript_1EC4BE:: @ 81EC4BE
	trainerbattle_no_intro TRAINER_BRENDAN_4, Route103_Text_1ECA59
	goto Route103_EventScript_1EC4FC
	end
Route103_EventScript_1EC4CE:: @ 81EC4CE
	trainerbattle_no_intro TRAINER_BRENDAN_7, Route103_Text_1ECA59
	goto Route103_EventScript_1EC4FC
	end
Route103_EventScript_1EC4DE:: @ 81EC4DE
	trainerbattle_no_intro TRAINER_BRENDAN_1, Route103_Text_1ECA59
	goto Route103_EventScript_1EC4FC
	end
Route103_Text_1ECA59: @ 81ECA59
	.string "…Wow, you're… pretty good.$"

Route103_EventScript_1EC4EE:: @ 81EC4EE
	msgbox Route103_Text_1EC8AE, MSGBOX_DEFAULT
	goto Route103_EventScript_1EC50A
	end
Route103_Text_1EC8AE: @ 81EC8AE
	.string "May: Okay… do you really have\n"
	.string "to be so rough in battle?\p"
	.string "No, no, I didn't mean…\p"
	.string "Let's head back to the lab! I think\n"
	.string "Dad might want to give you something.$"

Route103_EventScript_1EC4FC:: @ 81EC4FC
	msgbox Route103_Text_1ECA79, MSGBOX_DEFAULT
	goto Route103_EventScript_1EC50A
	end
Route103_Text_1ECA79: @ 81ECA79
	.string "Brendan: Wow, you're pretty rough\n"
	.string "in battle, aren't you?\p"
	.string "Let's um…\n"
	.string "Let's head back to the lab, alright?\p"
	.string "I hear dad's got something for you.$"

Route103_EventScript_1EC50A:: @ 81EC50A
	closemessage
	switch VAR_FACING
	case 1, Route103_EventScript_1EC585
	case 2, Route103_EventScript_1EC53D
	case 3, Route103_EventScript_1EC561
	case 4, Route103_EventScript_1EC561
	end

Route103_EventScript_1EC53D:: @ 81EC53D
	applymovement EVENT_OBJ_ID_PLAYER, Route103_Movement_1EC5C8
	applymovement 2, Route103_Movement_1EC5BE
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route103_Movement_1EC5C1
	waitmovement 0
	goto Route103_EventScript_1EC5A2
	end
Route103_Movement_1EC5C8: @ 81EC5C8
	delay_16
	delay_4
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end
Route103_Movement_1EC5BE: @ 81EC5BE
	walk_left
	walk_down
	step_end
Route103_Movement_1EC5C1: @ 81EC5C1
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route103_EventScript_1EC561:: @ 81EC561
	applymovement EVENT_OBJ_ID_PLAYER, Route103_Movement_1EC5D6
	applymovement 2, Common_Movement_WalkDown1
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route103_Movement_1EC5D0
	waitmovement 0
	goto Route103_EventScript_1EC5A2
	end
Route103_Movement_1EC5D6: @ 81EC5D6
	delay_16
	walk_in_place_fastest_down
	step_end

Route103_EventScript_1EC585:: @ 81EC585
	applymovement 2, Common_Movement_WalkDown1
	waitmovement 0
	playse SE_DANSA
	applymovement 2, Route103_Movement_1EC5D0
	waitmovement 0
	goto Route103_EventScript_1EC5A2
	end
Route103_Movement_1EC5D0: @ 81EC5D0
	jump_2_down
	delay_16
	walk_down
	walk_down
	walk_down
	step_end

Route103_EventScript_1EC5A2:: @ 81EC5A2
	removeobject 2
	setvar VAR_BIRCH_LAB_STATE, 4
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_RIVAL
	setflag FLAG_DEFEATED_RIVAL_ROUTE103
	setvar VAR_OLDALE_STATE, 1
	clearflag FLAG_HIDE_OLDALE_TOWN_RIVAL
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

@ -----------------------------------------------------
@ Signs and People

Route103_EventScript_1EC5EB:: @ 81EC5EB
	msgbox Route103_Text_1ECC1A, MSGBOX_SIGN
	end
Route103_Text_1ECC1A: @ 81ECC1A
	.string "Route 103\n"
	.string "{DOWN_ARROW} Oldale Town$"


Route103_EventScript_1EC5D9:: @ 81EC5D9
	msgbox Route103_Text_1ECB73, MSGBOX_NPC
	end
Route103_Text_1ECB73: @ 81ECB73
	.string "My Pokémon is staggeringly tired…\n"
	.string "I should have brought a Potion…$"



Route103_EventScript_1EC5E2:: @ 81EC5E2
	msgbox Route103_Text_1ECBB5, MSGBOX_NPC
	end
Route103_Text_1ECBB5: @ 81ECBB5
	.string "If you cross the sea from here,\n"
	.string "it'll be a shortcut to Oldale Town.\p"
	.string "Fufufu, that's useful, isn't it?$"

@ -----------------------------------------------------
@ Trainers

Route103_EventScript_1EC5F4:: @ 81EC5F4
	trainerbattle_single TRAINER_DAISY, Route103_Text_29495A, Route103_Text_29498F
	msgbox Route103_Text_2949B4, MSGBOX_AUTOCLOSE
	end
Route103_Text_29495A: @ 829495A
	.string "Did you feel the tug of our\n"
	.string "soul-soothing fragrance?$"
Route103_Text_29498F: @ 829498F
	.string "You weren't led astray by our aroma…$"
Route103_Text_2949B4: @ 82949B4
	.string "Aromatherapy is a form of mental\n"
	.string "healing that works with fragrances.$"



Route103_EventScript_1EC60B:: @ 81EC60B
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_2949F9, Route103_Text_294A3D, Route103_Text_294AAE, Route103_EventScript_1EC63A
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route103_EventScript_1EC653
	msgbox Route103_Text_294A52, MSGBOX_AUTOCLOSE
	end
Route103_Text_2949F9: @ 82949F9
	.string "Amy: I'm Amy.\n"
	.string "And this is my little sister Liv.\l"
	.string "We battle together!$"
Route103_Text_294A3D: @ 8294A3D
	.string "Amy: Uh-oh, we lost.$"
Route103_Text_294AAE: @ 8294AAE
	.string "Amy: Uh-oh, you have only one\n"
	.string "Pokémon with you.\l"
	.string "You can't battle us like that.$"
Route103_Text_294A52: @ 8294A52
	.string "Amy: You have to think about all\n"
	.string "kinds of things when you're battling\l"
	.string "against two trainers.$"
Route103_EventScript_1EC653:: @ 81EC653
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_294C29, Route103_Text_294C6D, Route103_Text_294CEF
	msgbox Route103_Text_294C93, MSGBOX_AUTOCLOSE
	end
Route103_Text_294C29: @ 8294C29
	.string "Amy: I'm Amy.\n"
	.string "And this is my little sister Liv.\l"
	.string "We battle together!$"
Route103_Text_294C6D: @ 8294C6D
	.string "Amy: Aww, boo!\n"
	.string "We couldn't win again…$"
Route103_Text_294CEF: @ 8294CEF
	.string "Amy: Uh-oh, you have only one\n"
	.string "Pokémon with you.\l"
	.string "You can't battle us like that.$"
Route103_Text_294C93: @ 8294C93
	.string "Amy: You have to think about all\n"
	.string "kinds of things when you're battling\l"
	.string "against two trainers.$"

Route103_EventScript_1EC63A:: @ 81EC63A
	msgbox Route103_Text_294B8A, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end
Route103_EventScript_1EC69D:: @ 81EC69D
	msgbox Route103_Text_294B8A, MSGBOX_DEFAULT
	register_matchcall TRAINER_AMY_AND_LIV_1
	release
	end
Route103_Text_294B8A: @ 8294B8A
	.string "Liv: Really, we're a lot better…\n"
	.string "It's true! We'll show you next time!$"

Route103_EventScript_1EC66E:: @ 81EC66E
	trainerbattle_double TRAINER_AMY_AND_LIV_1, Route103_Text_294AFD, Route103_Text_294B22, Route103_Text_294BD0, Route103_EventScript_1EC69D
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route103_EventScript_1EC6B6
	msgbox Route103_Text_294B40, MSGBOX_AUTOCLOSE
	end
Route103_Text_294AFD: @ 8294AFD
	.string "Liv: We battle together as one\n"
	.string "team.$"
Route103_Text_294B22: @ 8294B22
	.string "Liv: Oh, we lost, big sister…$"
Route103_Text_294BD0: @ 8294BD0
	.string "Liv: If you want to battle us,\n"
	.string "you have to have two Pokémon!\l"
	.string "It's not fair if you don't!$"
Route103_Text_294B40: @ 8294B40
	.string "Liv: We work perfectly together,\n"
	.string "me and my big sister…\p"
	.string "But we still lost…$"
Route103_EventScript_1EC6B6:: @ 81EC6B6
	trainerbattle_rematch_double TRAINER_AMY_AND_LIV_1, Route103_Text_294D3E, Route103_Text_294D63, Route103_Text_294DDB
	msgbox Route103_Text_294D89, MSGBOX_AUTOCLOSE
	end
Route103_Text_294D3E: @ 8294D3E
	.string "Liv: We battle together as one\n"
	.string "team.$"
Route103_Text_294D63: @ 8294D63
	.string "Liv: Awww, we lost again…\n"
	.string "Big sister…$"
Route103_Text_294DDB: @ 8294DDB
	.string "Liv: If you want to battle us, you\n"
	.string "have to have two Pokémon!\l"
	.string "It's not fair if you don't!$"
Route103_Text_294D89: @ 8294D89
	.string "Liv: We work perfectly together,\n"
	.string "me and my big sister…\p"
	.string "But why did we lose again?$"



Route103_EventScript_1EC6D1:: @ 81EC6D1
	trainerbattle_single TRAINER_ANDREW, Route103_Text_294E34, Route103_Text_294E92
	msgbox Route103_Text_294EBB, MSGBOX_AUTOCLOSE
	end
Route103_Text_294E34: @ 8294E34
	.string "Gah! My fishing line's all snarled up!\n"
	.string "I'm getting frustrated and mean!\l"
	.string "That's it! Battle me!$"
Route103_Text_294E92: @ 8294E92
	.string "Gah! Lost it!\n"
	.string "I'm even more annoyed now!$"
Route103_Text_294EBB: @ 8294EBB
	.string "Gah, I'm still boiling mad…\n"
	.string "Grrrrr…$"



Route103_EventScript_1EC6E8:: @ 81EC6E8
	trainerbattle_single TRAINER_MIGUEL_1, Route103_Text_294EDF, Route103_Text_294F21, Route103_EventScript_1EC714
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route103_EventScript_1EC733
	msgbox Route103_Text_294F42, MSGBOX_DEFAULT
	release
	end
Route103_Text_294EDF: @ 8294EDF
	.string "My Pokémon is delightfully adorable!\n"
	.string "Don't be shy--I'll show you!$"
Route103_Text_294F21: @ 8294F21
	.string "Oh, my gosh!\n"
	.string "My darling Pokémon!$"
Route103_Text_294F42: @ 8294F42
	.string "My delightful Pokémon looks darling\n"
	.string "even when it's fainted!$"
Route103_EventScript_1EC714:: @ 81EC714
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route103_Text_294F7E, MSGBOX_DEFAULT
	register_matchcall TRAINER_MIGUEL_1
	release
	end
Route103_Text_294F7E: @ 8294F7E
	.string "I'll get you to come out and look in\n"
	.string "on my delightful Pokémon again!$"
Route103_EventScript_1EC733:: @ 81EC733
	trainerbattle_rematch TRAINER_MIGUEL_1, Route103_Text_294FC3, Route103_Text_295006
	msgbox Route103_Text_29501E, MSGBOX_AUTOCLOSE
	end
Route103_Text_294FC3: @ 8294FC3
	.string "Hi, you! My delightfully adorable\n"
	.string "Pokémon has become more darling!$"
Route103_Text_295006: @ 8295006
	.string "Oh!\n"
	.string "My darling Pokémon!$"
Route103_Text_29501E: @ 829501E
	.string "The more I spend time with it,\n"
	.string "the more adorable my Pokémon becomes.$"



Route103_EventScript_1EC74A:: @ 81EC74A
	trainerbattle_single TRAINER_MARCOS, Route103_Text_295206, Route103_Text_29522B
	msgbox Route103_Text_295246, MSGBOX_AUTOCLOSE
	end
Route103_Text_295206: @ 8295206
	.string "Did my guitar's wailing draw you in?$"
Route103_Text_29522B: @ 829522B
	.string "My one-man show is ruined…$"
Route103_Text_295246: @ 8295246
	.string "I was playing my guitar where few\n"
	.string "people were around, but a lot of fans\l"
	.string "have gathered.\p"
	.string "Heh, maybe I should turn pro.$"



Route103_EventScript_1EC761:: @ 81EC761
	trainerbattle_single TRAINER_RHETT, Route103_Text_295199, Route103_Text_2951C6
	msgbox Route103_Text_2951DE, MSGBOX_AUTOCLOSE
	end
Route103_Text_295199: @ 8295199
	.string "Whoa!\n"
	.string "How'd you get into a space this small?$"
Route103_Text_2951C6: @ 82951C6
	.string "Whoa!\n"
	.string "The kid can rock!$"
Route103_Text_2951DE: @ 82951DE
	.string "Do you like cramped quarters\n"
	.string "like this?$"



Route103_EventScript_1EC778:: @ 81EC778
	trainerbattle_single TRAINER_PETE, Route103_Text_295063, Route103_Text_295093
	msgbox Route103_Text_2950AA, MSGBOX_AUTOCLOSE
	end
Route103_Text_295063: @ 8295063
	.string "This sort of distance…\n"
	.string "You should just swim it!$"
Route103_Text_295093: @ 8295093
	.string "Oh, that's good going!$"
Route103_Text_2950AA: @ 82950AA
	.string "Oh, I understand where you're coming\n"
	.string "from now.\p"
	.string "If I had a Pokémon that trusty,\n"
	.string "I'd want to SURF on it, too!$"



Route103_EventScript_1EC78F:: @ 81EC78F
	trainerbattle_single TRAINER_ISABELLE, Route103_Text_295116, Route103_Text_295146
	msgbox Route103_Text_29514D, MSGBOX_AUTOCLOSE
	end
Route103_Text_295116: @ 8295116
	.string "Watch where you're going!\n"
	.string "We're going to crash!$"
Route103_Text_295146: @ 8295146
	.string "Groan…$"
Route103_Text_29514D: @ 829514D
	.string "I'm a poor swimmer so I was practicing…\n"
	.string "Sorry for almost crashing into you.$"

