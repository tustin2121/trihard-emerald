@ This script is called from every Pokemon Center

@@@@ Pokecenter Nurse Script @@@@

PokemonCenter_1F_NurseHealScript:: @ 827191E
	lock
	faceplayer
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG
	goto_if_set FLAG_TEMP_5, PokemonCenter_1F_NurseHealScript_Talk
	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
	setyesnotext gYN_Sure, gYN_No
	msgbox PokemonCenter_1F_NurseText_NurseHealPrompt, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PokemonCenter_1F_NurseHealScript_Heal
	
	message PokemonCenter_1F_NurseText_NurseGoodbye
	waitmessage
	waitbuttonpress
	release
	end
PokemonCenter_1F_Movement_NurseBow: @ 8271AD0
	delay_16
	nurse_joy_bow
	delay_4
	step_end
PokemonCenter_1F_NurseText_NurseHealPrompt:: @ 82726EB
	.string "Welcome to the Pokémon Center!\p"
	.string "Would you like a room\n"
	.string "for the {TIME_OF_DAY}?$"
PokemonCenter_1F_NurseText_NurseGoodbye:
	.string "Very well. Feel free to use any of our\n"
	.string "other amenities, of course.\p"
	.string "The shop is to your right, the escalator\n"
	.string "to the lounge is to the left.$"

PokemonCenter_1F_NurseHealScript_Heal:
	incrementgamestat GAME_STAT_USED_POKECENTER
	setflag FLAG_TEMP_5
	message PokemonCenter_1F_NurseText_NurseNowHealing
	waitmessage
	waitbuttonpress
	closemessage
	@ Walk towards escalator, fade screen
	applymovement VAR_0x800B, PokemonCenter_1F_NurseHealScript_NurseWalk
	applymovement EVENT_OBJ_ID_PLAYER, PokemonCenter_1F_NurseHealScript_PlayerWalk
	fadescreenspeed 5, 2 @ FADE_TO_BLACK_NO_WINDOW
	waitmovement 0
	setflag FLAG_DISABLE_FADE_INIT
	@ Heal while setting positions
	playfanfare MUS_ME_ASA
	applymovement VAR_0x800B, PokemonCenter_1F_NurseHealScript_NurseResetPosition
	applymovement EVENT_OBJ_ID_PLAYER, PokemonCenter_1F_NurseHealScript_PlayerResetPosition
	waitfanfare
	waitmovement 0
	special HealPlayerParty
	advancetime 6, 45, 30
	@ Do the mourning cutscene, if needed
	domourning
	@ TriHard Emerald: Force Save
	special ForceSaveGame
	waitstate
	closemessage
	delay 1
	@ Check for dream cutscenes
	dodreams
	clearflag FLAG_DISABLE_FADE_INIT
	fadescreenspeed 4, 2 @ FADE_FROM_BLACK_NO_WINDOW
	release
	end
PokemonCenter_1F_NurseText_NurseNowHealing:
	.string "Right this way then, {PLAYER_sir}.$"
PokemonCenter_1F_NurseHealScript_PlayerWalk:
	face_left
	delay_8
	walk_left
	walk_left
	step_end
PokemonCenter_1F_NurseHealScript_NurseWalk:
	walk_left
	walk_left
	face_down
	step_end
PokemonCenter_1F_NurseHealScript_PlayerResetPosition:
	walk_fastest_right
	walk_fastest_right
	walk_fastest_down
	walk_fastest_down
	step_end
PokemonCenter_1F_NurseHealScript_NurseResetPosition:
	walk_fastest_right
	walk_fastest_right
	face_down
	step_end

PokemonCenter_1F_NurseHealScript_Talk:
	message PokemonCenter_1F_NurseText_Goodluck
	waitmessage
	waitbuttonpress
	release
	end
PokemonCenter_1F_NurseText_Goodluck:
	.string "I hope you had a good rest.\n"
	.string "Feel free to use any of our amenities\l"
	.string "before you head out. Good luck.$"
	

@ PokemonCenter_1F_NurseHealScript:: @ 827191E
@ 	lock
@ 	faceplayer
@ 	@TODO special ScrSpecial_CanAnyPartyMonsBeHealed
@ 	setvar VAR_0x8004, 0
@ 	specialvar VAR_RESULT, CountPlayerTrainerStars
@ 	compare VAR_RESULT, 4
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_MentionGoldCard
@ 	msgbox PokemonCenter_1F_NurseText_NurseHealPrompt, MSGBOX_YESNO
@ 	compare VAR_RESULT, 1
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_HealPokemon
@ 	compare VAR_RESULT, 0
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_NormalGoodbye
@ 	end

@ PokemonCenter_1F_NurseHealScript_NormalGoodbye:: @ 8271954
@ 	message gText_NurseHealGoodbye
@ 	return

@ PokemonCenter_1F_NurseHealScript_HealPokemon:: @ 827195A
@ 	incrementgamestat GAME_STAT_USED_POKECENTER
@ 	compare VAR_0x8004, 0
@ 	call_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemon
@ 	compare VAR_0x8004, 1
@ 	call_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard
@ 	waitmessage
@ 	call PokemonCenter_1F_NurseHealScript_DoHealMachineAnimation
@ 	goto_if_unset FLAG_POKERUS_EXPLAINED, PokemonCenter_1F_NurseHealScript_CheckForPokerus
@ 	goto PokemonCenter_1F_NurseHealScript_FinishUp
@ 	end

@ PokemonCenter_1F_NurseHealScript_SayTakingPokemon:: @ 8271987
@ 	message gText_NurseHealTakePokemon
@ 	return

@ PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard:: @ 827198D
@ 	message gText_NurseHealGoldCardTakePokemon
@ 	return

@ PokemonCenter_1F_NurseHealScript_DoHealMachineAnimation:: @ 8271993
@ 	applymovement VAR_0x800B, Common_Movement_WalkInPlaceLeft
@ 	waitmovement 0
@ 	dofieldeffect FLDEFF_POKECENTER_HEAL
@ 	waitfieldeffect FLDEFF_POKECENTER_HEAL
@ 	@ applymovement VAR_0x800B, Common_Movement_WalkInPlaceDown
@ 	applymovement VAR_0x800B, Common_Movement_FacePlayer
@ 	waitmovement 0
@ 	special HealPlayerParty
@ 	@ TriHard Emerald: Force Save
@ 	special ForceSaveGame
@ 	waitstate
@ 	return

@ PokemonCenter_1F_NurseHealScript_FinishUp:: @ 82719B1
@ 	specialvar VAR_RESULT, sub_8139ED0
@ 	compare VAR_RESULT, 0
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_ThankYouBow
@ 	specialvar VAR_RESULT, sp182_move_string
@ 	copyvar VAR_0x8008, VAR_RESULT
@ 	compare VAR_0x8008, 0
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_ThankYouBow
@ 	compare VAR_0x8008, 1
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_CheckUnionRoom
@ 	end

@ PokemonCenter_1F_NurseHealScript_ThankYouBow:: @ 82719E2
@ 	compare VAR_0x8004, 1
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_ThankYouBowGoldCard
@ 	message gText_NurseHealThankYou
@ 	waitmessage
@ 	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
@ 	waitmovement 0
@ 	message gText_NurseHealGoodbye
@ 	return

@ PokemonCenter_1F_NurseHealScript_ThankYouBowGoldCard:: @ 8271A03
@ 	message gText_NurseHealGoldCardThankYou
@ 	waitmessage
@ 	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
@ 	waitmovement 0
@ 	message gText_NurseHealGoldCardGoodbye
@ 	return

@ PokemonCenter_1F_NurseHealScript_CheckUnionRoom:: @ 8271A19
@ 	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, PokemonCenter_1F_NurseHealScript_ThankYouBow
@ 	msgbox gText_NurseHealThankYou, MSGBOX_DEFAULT
@ 	setflag FLAG_NURSE_UNION_ROOM_REMINDER
@ 	message OldaleTown_PokemonCenter_1F_Text_278A48
@ 	waitmessage
@ 	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
@ 	waitmovement 0
@ 	message gText_NurseHealGoodbye
@ 	return

@ PokemonCenter_1F_NurseHealScript_CheckForPokerus:: @ 8271A43
@ 	specialvar VAR_RESULT, IsPokerusInParty
@ 	compare VAR_RESULT, 1
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_ExplainPokerus
@ 	compare VAR_RESULT, 0
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_FinishUp
@ 	end

@ PokemonCenter_1F_NurseHealScript_ExplainPokerus:: @ 8271A5F
@ 	message gText_NurseExplainPokerus
@ 	setflag FLAG_POKERUS_EXPLAINED
@ 	return

@ PokemonCenter_1F_NurseHealScript_MentionGoldCard:: @ 8271A68
@ 	goto_if_set FLAG_OLDALE_NURSE_MENTIONS_GOLD_CARD, PokemonCenter_1F_NurseHealScript_WelcomeGoldCard
@ 	setflag FLAG_OLDALE_NURSE_MENTIONS_GOLD_CARD
@ 	msgbox gText_NurseHealGoldCardCutoff, MSGBOX_DEFAULT
@ 	playse SE_PIN
@ 	applymovement VAR_0x800B, Common_Movement_ExclamationMark
@ 	waitmovement 0
@ 	applymovement VAR_0x800B, Common_Movement_Delay48
@ 	waitmovement 0
@ 	msgbox gText_NurseHealGoldCardMention, MSGBOX_YESNO
@ 	compare VAR_RESULT, 1
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard2
@ 	message gText_NurseHealGoldCardGoodbye
@ 	return

@ PokemonCenter_1F_NurseHealScript_WelcomeGoldCard:: @ 8271AAC
@ 	msgbox gText_NurseHealGoldCardWelcome, MSGBOX_YESNO
@ 	compare VAR_RESULT, 1
@ 	goto_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard2
@ 	message gText_NurseHealGoldCardGoodbye
@ 	return

@ PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard2:: @ 8271AC5
@ 	setvar VAR_0x8004, 1
@ 	goto PokemonCenter_1F_NurseHealScript_HealPokemon
@ 	end

@ PokemonCenter_1F_Movement_NurseBow: @ 8271AD0
@ 	nurse_joy_bow
@ 	delay_4
@ 	step_end

@ PokemonCenter_1F_NurseText_NurseHealPrompt:: @ 82726EB
@ 	.string "Hello, and welcome to\n"
@ 	.string "the Pokémon CENTER.\p"
@ 	.string "We restore your tired Pokémon\n"
@ 	.string "to full health.\p"
@ 	.string "Would you like to rest your Pokémon?$"

@ gText_NurseHealTakePokemon:: @ 8272768
@ 	.string "Okay, I'll take your Pokémon\n"
@ 	.string "for a few seconds.$"

@ gText_NurseHealThankYou:: @ 8272798
@ 	.string "Thank you for waiting.\p"
@ 	.string "We've restored your Pokémon\n"
@ 	.string "to full health.$"

@ gText_NurseHealGoodbye:: @ 82727DB
@ 	.string "We hope to see you again!$"

@ gText_NurseHealGoldCardCutoff:: @ 82727F5
@ 	.string "Hello, and welcome to\n"
@ 	.string "the Pokémon CENTER.\p"
@ 	.string "We restore your tired Pokémon\n"
@ 	.string "to full health.\p"
@ 	.string "Would you like to…$"

@ gText_NurseHealGoldCardMention:: @ 8272860
@ 	.string "Th-that card…\n"
@ 	.string "Could it be… The GOLD CARD?!\p"
@ 	.string "Oh, the gold color is brilliant!\n"
@ 	.string "The four stars seem to sparkle!\p"
@ 	.string "I've seen several TRAINERS with\n"
@ 	.string "a SILVER CARD before, but, {PLAYER},\l"
@ 	.string "you're the first TRAINER I've ever\l"
@ 	.string "seen with a GOLD CARD!\p"
@ 	.string "Okay, {PLAYER}, please allow me\n"
@ 	.string "the honor of resting your Pokémon!$"

@ gText_NurseHealGoldCardWelcome:: @ 8272982
@ 	.string "I'm delighted to see you, {PLAYER}!\n"
@ 	.string "You want the usual, am I right?$"

@ gText_NurseHealGoldCardTakePokemon:: @ 82729C0
@ 	.string "Okay, I'll take your Pokémon\n"
@ 	.string "for a few seconds.$"

@ gText_NurseHealGoldCardThankYou:: @ 82729F0
@ 	.string "Thank you for waiting.$"

@ gText_NurseHealGoldCardGoodbye:: @ 8272A07
@ 	.string "We hope to see you again!$"

@ gText_NurseExplainPokerus:: @ 8272F07
@ 	.string "Your Pokémon may be infected with\n"
@ 	.string "Pokérus.\p"
@ 	.string "Little is known about the Pokérus\n"
@ 	.string "except that they are microscopic life-\l"
@ 	.string "forms that attach to Pokémon.\p"
@ 	.string "While infected, Pokémon are said to\n"
@ 	.string "grow exceptionally well.$"


@@@@ Pokecenter Free Pokeball Counter @@@@

PokemonCenter_1F_EventScript_FreePokeballCounter::
	lock
	faceplayer
	markasdialog 14
	@ Deny if the player hasn't yet completed the tutorial
	compare VAR_FREE_POKEBALL_STATE, 0
	goto_if_eq PokemonCenter_1F_EventScript_FreePokeballCounter_DenyTutorial
	@ Check for free ball cutoff
	compare VAR_TEMP_A, 8
	goto_if_ge PokemonCenter_1F_EventScript_FreePokeballCounter_DenyCutoff
	@ Welcome message
	selectpointer PokemonCenter_1F_TextArray_FreePokeballCounter_Intro, VAR_TEMP_A
	message 0
	waitmessage
	@ Check for first time tutorial
	compare VAR_FREE_POKEBALL_STATE, 1
	call_if_eq PokemonCenter_1F_EventScript_FreePokeballCounter_Explain
	yesnobox 20, 8
	compare VAR_RESULT, 1
	goto_if_eq PokemonCenter_1F_EventScript_FreePokeballCounter_GiveBalls
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_EventScript_FreePokeballCounter_Goodbye
	release
	end
.align 2
PokemonCenter_1F_TextArray_FreePokeballCounter_Intro:
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro0
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro1
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro1
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro2
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro2
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro2
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro3
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_Intro3
	.4byte 0
PokemonCenter_1F_Text_FreePokeballCounter_Intro0:
	.string "Hello {PLAYER_sir}, how are you today?\n"
	.string "Would you like some free {REF}Poké Balls{END}?$"
PokemonCenter_1F_Text_FreePokeballCounter_Intro1:
	.string "Hello again, {PLAYER_sir}.\n"
	.string "Would you like some more {REF}Poké Balls{END}?$"
PokemonCenter_1F_Text_FreePokeballCounter_Intro2:
	.string "Back again, {PLAYER_sir}?\n"
	.string "Want some more {REF}Poké Balls{END}?$"
PokemonCenter_1F_Text_FreePokeballCounter_Intro3:
	.string "Ah, {PLAYER_sir}.\n"
	.string "You still want more {REF}Poké Balls{END}?$"

PokemonCenter_1F_EventScript_FreePokeballCounter_GiveBalls:
	selectpointer PokemonCenter_1F_TextArray_FreePokeballCounter_GiveComments, VAR_TEMP_A
	message 0
	waitmessage
	waitbuttonpress
	giveitem_std ITEM_POKE_BALL, 5
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_EventScript_FreePokeballCounter_NoRoom
	addvar VAR_TEMP_A, 1
	goto PokemonCenter_1F_EventScript_FreePokeballCounter_Goodbye
	end
.align 2
PokemonCenter_1F_TextArray_FreePokeballCounter_GiveComments:
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls1
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls1
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls2
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls3
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls3
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls3
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls4
	.4byte PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls5
	.4byte 0
PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls1:
	.string "Okay, here's a pack of Poké Balls!$"
PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls2:
	.string "Planning to catch a lot of Pokémon,\n"
	.string "are you? Here you go!$"
PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls3:
	.string "Alright. Here's a few more.$"
PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls4:
	.string "Ok, last set. I know they're free, but\n"
	.string "we can't just have one person hogging\l"
	.string "them all now, can we?$"
PokemonCenter_1F_Text_FreePokeballCounter_GiveBalls5:
	.string "I'm serious this time, {PLAYER_sir}.\n"
	.string "No more than this.$"


PokemonCenter_1F_EventScript_FreePokeballCounter_NoRoom:
	message PokemonCenter_1F_Text_FreePokeballCounter_NoRoom
	waitmessage
	waitbuttonpress
	release
	end
PokemonCenter_1F_Text_FreePokeballCounter_NoRoom:
	.string "Oh, you don't have enough room.\n"
	.string "Feel free to return when you do.$"

PokemonCenter_1F_EventScript_FreePokeballCounter_Goodbye:
	message PokemonCenter_1F_Text_FreePokeballCounter_Goodbye
	waitmessage
	waitbuttonpress
	release
	end
PokemonCenter_1F_Text_FreePokeballCounter_Goodbye:
	.string "Have a good day!$"

PokemonCenter_1F_EventScript_FreePokeballCounter_DenyCutoff:
	message PokemonCenter_1F_Text_FreePokeballCounter_DenyCutoff
	waitmessage
	waitbuttonpress
	goto_if_set FLAG_TEMP_6, PokemonCenter_1F_EventScript_FreePokeballCounter_DenyCutoff_jump
	incrementgamestat GAME_STAT_NUM_NPCS_HARASSED
	setflag FLAG_TEMP_6 @fallthrough
PokemonCenter_1F_EventScript_FreePokeballCounter_DenyCutoff_jump:
	release
	end
PokemonCenter_1F_Text_FreePokeballCounter_DenyCutoff:
	.string "No, I'm sorry, {PLAYER_sir}.\n"
	.string "I'm cutting you off.\p"
	.string "Please leave.$"

PokemonCenter_1F_EventScript_FreePokeballCounter_DenyTutorial:
	msgbox PokemonCenter_1F_Text_FreePokeballCounter_DenyTutorial, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
PokemonCenter_1F_Text_FreePokeballCounter_DenyTutorial:
	.string "Oh, I'm sorry, {PLAYER_sir}.\n"
	.string "We're currently out of stock.\p"
	.string "Sorry for the inconvenience.$"

PokemonCenter_1F_EventScript_FreePokeballCounter_Explain:
	waitbuttonpress
	playse SE_SELECT
	message PokemonCenter_1F_Text_FreePokeballCounter_Explain
	waitmessage
	waitbuttonpress
	applymovement THIS_EVENT, PokemonCenter_1F_Text_FreePokeballCounter_Glance
	waitmovement 0
	message PokemonCenter_1F_Text_FreePokeballCounter_Explain2
	waitmessage
	waitbuttonpress
	setvar VAR_FREE_POKEBALL_STATE, 2
	message PokemonCenter_1F_Text_FreePokeballCounter_Explain3
	waitmessage
	return
PokemonCenter_1F_Text_FreePokeballCounter_Explain:
	.string "Oh, have you not heard of our program\n"
	.string "before? You must be new to the region.\p"
	.string "I'm sure you've noticed how Pokémon can\n"
	.string "be very dangerous in the wild.\p"
	.string "The Hoenn General Council decided\n"
	.string "the best way to address this problem\l"
	.string "was to ensure everyone has some\l"
	.string "Pokémon to protect themselves.\p"
	.string "So they started the\n"
	.string "{REF}Free Poké Ball Initiative{END},\l"
	.string "to help keep you safe and reduce the\l"
	.string "number of wild Pokémon incidences.$"
PokemonCenter_1F_Text_FreePokeballCounter_Explain2:
	.string "{COLOR DARK_GREY}{SHADOW WHITE}"
	.string "(Just between you and me, I think it's\n"
	.string "actually increased the number of wild\l"
	.string "Pokémon attacks… many people don't\l"
	.string "know how to handle a Pokémon…)$"
PokemonCenter_1F_Text_FreePokeballCounter_Explain3:
	.string "Anyway, would like some {REF}Poké Balls{END}?$"
PokemonCenter_1F_Text_FreePokeballCounter_Glance:
	face_down
	delay_16
	delay_16
	face_player
	step_end


@ TODO; stick this text on a random patron in a pokecenter instead
	.string "Your parents' taxes go towards paying\n"
	.string "for free Poké Balls for you, as well as\l"
	.string "all the services offered here at the\n"
	.string "Pokémon Center!$"


@@@@ Pokecenter Mr Briney Location @@@@

PokemonCenter_1F_SetMrBrineyLocation:: @ 82718DE
	goto_if_unset FLAG_RECEIVED_POKENAV, Common_EventScript_NopReturn
	goto_if_set FLAG_DEFEATED_PETALBURG_GYM, Common_EventScript_NopReturn
	goto_if_unset FLAG_HIDE_ROUTE_104_MR_BRINEY_BOAT, PokemonCenter_1F_SetMrBrineyLocation_A
	goto_if_unset FLAG_HIDE_MR_BRINEY_DEWFORD_TOWN, PokemonCenter_1F_SetMrBrineyLocation_B
	goto_if_unset FLAG_HIDE_ROUTE_108_MR_BRINEY, PokemonCenter_1F_SetMrBrineyLocation_C
	return

PokemonCenter_1F_SetMrBrineyLocation_A: @ 827190C
	setvar VAR_BRINEY_LOCATION, 1
	return

PokemonCenter_1F_SetMrBrineyLocation_B: @ 8271912
	setvar VAR_BRINEY_LOCATION, 2
	return

PokemonCenter_1F_SetMrBrineyLocation_C: @ 8271918
	setvar VAR_BRINEY_LOCATION, 3
	return
