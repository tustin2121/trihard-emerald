@ This script is called from every Pokemon Center
PokemonCenter_1F_NurseHealScript:: @ 827191E
	lock
	faceplayer
	setvar VAR_0x8004, 0
	specialvar VAR_RESULT, CountPlayerTrainerStars
	compare VAR_RESULT, 4
	goto_if_eq PokemonCenter_1F_NurseHealScript_MentionGoldCard
	msgbox gText_NurseHealPrompt, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PokemonCenter_1F_NurseHealScript_HealPokemon
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_NurseHealScript_NormalGoodbye
	end

PokemonCenter_1F_NurseHealScript_NormalGoodbye:: @ 8271954
	message gText_NurseHealGoodbye
	return

PokemonCenter_1F_NurseHealScript_HealPokemon:: @ 827195A
	incrementgamestat GAME_STAT_USED_POKECENTER
	compare VAR_0x8004, 0
	call_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemon
	compare VAR_0x8004, 1
	call_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard
	waitmessage
	call PokemonCenter_1F_NurseHealScript_DoHealMachineAnimation
	goto_if_unset FLAG_POKERUS_EXPLAINED, PokemonCenter_1F_NurseHealScript_CheckForPokerus
	goto PokemonCenter_1F_NurseHealScript_FinishUp
	end

PokemonCenter_1F_NurseHealScript_SayTakingPokemon:: @ 8271987
	message gText_NurseHealTakePokemon
	return

PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard:: @ 827198D
	message gText_NurseHealGoldCardTakePokemon
	return

PokemonCenter_1F_NurseHealScript_DoHealMachineAnimation:: @ 8271993
	applymovement VAR_0x800B, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	@ applymovement VAR_0x800B, Common_Movement_WalkInPlaceDown
	applymovement VAR_0x800B, Common_Movement_FacePlayer
	waitmovement 0
	special HealPlayerParty
	@ TriHard Emerald: Force Save
	special ForceSaveGame
	waitstate
	return

PokemonCenter_1F_NurseHealScript_FinishUp:: @ 82719B1
	specialvar VAR_RESULT, sub_8139ED0
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_NurseHealScript_ThankYouBow
	specialvar VAR_RESULT, sp182_move_string
	copyvar VAR_0x8008, VAR_RESULT
	compare VAR_0x8008, 0
	goto_if_eq PokemonCenter_1F_NurseHealScript_ThankYouBow
	compare VAR_0x8008, 1
	goto_if_eq PokemonCenter_1F_NurseHealScript_CheckUnionRoom
	end

PokemonCenter_1F_NurseHealScript_ThankYouBow:: @ 82719E2
	compare VAR_0x8004, 1
	goto_if_eq PokemonCenter_1F_NurseHealScript_ThankYouBowGoldCard
	message gText_NurseHealThankYou
	waitmessage
	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
	waitmovement 0
	message gText_NurseHealGoodbye
	return

PokemonCenter_1F_NurseHealScript_ThankYouBowGoldCard:: @ 8271A03
	message gText_NurseHealGoldCardThankYou
	waitmessage
	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
	waitmovement 0
	message gText_NurseHealGoldCardGoodbye
	return

PokemonCenter_1F_NurseHealScript_CheckUnionRoom:: @ 8271A19
	goto_if_set FLAG_NURSE_UNION_ROOM_REMINDER, PokemonCenter_1F_NurseHealScript_ThankYouBow
	msgbox gText_NurseHealThankYou, MSGBOX_DEFAULT
	setflag FLAG_NURSE_UNION_ROOM_REMINDER
	message OldaleTown_PokemonCenter_1F_Text_278A48
	waitmessage
	applymovement VAR_0x800B, PokemonCenter_1F_Movement_NurseBow
	waitmovement 0
	message gText_NurseHealGoodbye
	return

PokemonCenter_1F_NurseHealScript_CheckForPokerus:: @ 8271A43
	specialvar VAR_RESULT, IsPokerusInParty
	compare VAR_RESULT, 1
	goto_if_eq PokemonCenter_1F_NurseHealScript_ExplainPokerus
	compare VAR_RESULT, 0
	goto_if_eq PokemonCenter_1F_NurseHealScript_FinishUp
	end

PokemonCenter_1F_NurseHealScript_ExplainPokerus:: @ 8271A5F
	message gText_NurseExplainPokerus
	setflag FLAG_POKERUS_EXPLAINED
	return

PokemonCenter_1F_NurseHealScript_MentionGoldCard:: @ 8271A68
	goto_if_set FLAG_OLDALE_NURSE_MENTIONS_GOLD_CARD, PokemonCenter_1F_NurseHealScript_WelcomeGoldCard
	setflag FLAG_OLDALE_NURSE_MENTIONS_GOLD_CARD
	msgbox gText_NurseHealGoldCardCutoff, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x800B, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x800B, Common_Movement_Delay48
	waitmovement 0
	msgbox gText_NurseHealGoldCardMention, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard2
	message gText_NurseHealGoldCardGoodbye
	return

PokemonCenter_1F_NurseHealScript_WelcomeGoldCard:: @ 8271AAC
	msgbox gText_NurseHealGoldCardWelcome, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard2
	message gText_NurseHealGoldCardGoodbye
	return

PokemonCenter_1F_NurseHealScript_SayTakingPokemonGoldCard2:: @ 8271AC5
	setvar VAR_0x8004, 1
	goto PokemonCenter_1F_NurseHealScript_HealPokemon
	end

PokemonCenter_1F_Movement_NurseBow: @ 8271AD0
	nurse_joy_bow
	delay_4
	step_end

gText_NurseHealPrompt:: @ 82726EB
	.string "Hello, and welcome to\n"
	.string "the Pokémon CENTER.\p"
	.string "We restore your tired Pokémon\n"
	.string "to full health.\p"
	.string "Would you like to rest your Pokémon?$"

gText_NurseHealTakePokemon:: @ 8272768
	.string "Okay, I'll take your Pokémon\n"
	.string "for a few seconds.$"

gText_NurseHealThankYou:: @ 8272798
	.string "Thank you for waiting.\p"
	.string "We've restored your Pokémon\n"
	.string "to full health.$"

gText_NurseHealGoodbye:: @ 82727DB
	.string "We hope to see you again!$"

gText_NurseHealGoldCardCutoff:: @ 82727F5
	.string "Hello, and welcome to\n"
	.string "the Pokémon CENTER.\p"
	.string "We restore your tired Pokémon\n"
	.string "to full health.\p"
	.string "Would you like to…$"

gText_NurseHealGoldCardMention:: @ 8272860
	.string "Th-that card…\n"
	.string "Could it be… The GOLD CARD?!\p"
	.string "Oh, the gold color is brilliant!\n"
	.string "The four stars seem to sparkle!\p"
	.string "I've seen several TRAINERS with\n"
	.string "a SILVER CARD before, but, {PLAYER},\l"
	.string "you're the first TRAINER I've ever\l"
	.string "seen with a GOLD CARD!\p"
	.string "Okay, {PLAYER}, please allow me\n"
	.string "the honor of resting your Pokémon!$"

gText_NurseHealGoldCardWelcome:: @ 8272982
	.string "I'm delighted to see you, {PLAYER}!\n"
	.string "You want the usual, am I right?$"

gText_NurseHealGoldCardTakePokemon:: @ 82729C0
	.string "Okay, I'll take your Pokémon\n"
	.string "for a few seconds.$"

gText_NurseHealGoldCardThankYou:: @ 82729F0
	.string "Thank you for waiting.$"

gText_NurseHealGoldCardGoodbye:: @ 8272A07
	.string "We hope to see you again!$"

gText_NurseExplainPokerus:: @ 8272F07
	.string "Your Pokémon may be infected with\n"
	.string "POKéRUS.\p"
	.string "Little is known about the POKéRUS\n"
	.string "except that they are microscopic life-\l"
	.string "forms that attach to Pokémon.\p"
	.string "While infected, Pokémon are said to\n"
	.string "grow exceptionally well.$"
