MauvilleCity_Mart_MapScripts:: @ 82110E5
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Menu_OnLoad
	.byte 0

@ -----------------------------------------------------

MauvilleCity_Menu_OnLoad:
	dotimebasedevents
	compare VAR_EGGMAN_BROTHER_COUNTER, 1
	goto_if_eq Common_EventScript_NopEnd
	setflag FLAG_TEMP_5
	end

@ -----------------------------------------------------

MauvilleCity_Mart_EventScript_Chester::
	lock
	faceplayer
	markasdialog
	msgbox MauvilleCity_Mart_Text_Chester1
	callnative CheckPartyBadMons
	switch VAR_RESULT
	case 0, MauvilleCity_Mart_EventScript_Chester_NoBad
	case 1, MauvilleCity_Mart_EventScript_Chester_1Bad
	case 2, MauvilleCity_Mart_EventScript_Chester_2Bad
	case 3, MauvilleCity_Mart_EventScript_Chester_Shedinja
	release
	end
MauvilleCity_Mart_Text_Chester1:
	.string "Hello there! I'm Chester!\n"
	.string "This is my Home for\l"
	.string "Problematic Pokémon!\p"
	.string "If you need me to take a problematic\n"
	.string "Pokémon off your hands, that's what\l"
	.string "I'm here for.\p"
	.string "Oh, no, I don't mean from a training\n"
	.string "standpoint, I mean like ones which just\l"
	.string "fill space in your party.\p"
	.string "Like eggs which just won't hatch.\p"
	.string "Here, let me take a look.$"
MauvilleCity_Mart_EventScript_Chester_NoBad:
	msgbox MauvilleCity_Mart_Text_Chester_Nothing
	release
	end
MauvilleCity_Mart_Text_Chester_Nothing:
	.string "Hm… No, your party looks perfectly\n"
	.string "healthy to me.\p"
	.string "But if you do come across any Pokémon\n"
	.string "you just can't seem to get rid of,\l"
	.string "feel free to come by and we'll find\l"
	.string "them a nice loving home.\p"
	.string "Toodles!$"

MauvilleCity_Mart_EventScript_Chester_1Bad:
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_Mart_EventScript_Chester_1BadRemove
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg1No
	release
	end
MauvilleCity_Mart_Text_Chester_BadEgg1:
	.string "Oh, you've got a naughty egg there!\p"
	.string "These eggs just refuse to hatch no\n"
	.string "matter how much you care for it.\p"
	.string "Don't worry, we can find it a nice\n"
	.string "home, I'm sure. If you don't mind me\l"
	.string "taking it, that is.\p"
	.string "Would you like me to take it\n"
	.string "off your hands?$"
MauvilleCity_Mart_Text_Chester_BadEgg1No:
	.string "No? You wanna hang on to that egg\n"
	.string "a little longer then?\p"
	.string "I assure you it won't hatch.\p"
	.string "If you change your mind, I'll be here.\p"
	.string "Toodles!$"
MauvilleCity_Mart_EventScript_Chester_1BadRemove:
	callnative RemovePartyBadEggs
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg1Yes
	release
	end
MauvilleCity_Mart_Text_Chester_BadEgg1Yes:
	.string "Excellent! I'll just grab that bad\n"
	.string "boy off you then.\p"
	.string "If you come across any other Pokémon\n"
	.string "you just can't seem to get rid of,\l"
	.string "feel free to come by and we'll find\l"
	.string "them a nice loving home.\p"
	.string "Toodles!$"

MauvilleCity_Mart_EventScript_Chester_2Bad:
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_Mart_EventScript_Chester_2BadRemove
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg2No
	release
	end
MauvilleCity_Mart_Text_Chester_BadEgg2:
	.string "Oh, you've got a bunch of bad eggs\n"
	.string "there in your party! My my, what have\l"
	.string "YOU been up to, {PLAYER_boy}?\p"
	.string "If you'd like, we can find a nice home\n"
	.string "for all of those.\p"
	.string "Would you like me to take those\n"
	.string "off your hands?$"
MauvilleCity_Mart_Text_Chester_BadEgg2No:
	.string "No? You wanna hang on to those eggs\n"
	.string "a little longer then?\p"
	.string "I assure you none of them will hatch.\p"
	.string "If you change your mind, I'll be here.\p"
	.string "Toodles!$"
MauvilleCity_Mart_EventScript_Chester_2BadRemove:
	callnative RemovePartyBadEggs
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg2Yes
	release
	end
MauvilleCity_Mart_Text_Chester_BadEgg2Yes:
	.string "Excellent! I'll just grab those bad\n"
	.string "boys off you then.\p"
	.string "If you come across any other Pokémon\n"
	.string "you just can't seem to get rid of,\l"
	.string "feel free to come by and we'll find\l"
	.string "them a nice loving home.\p"
	.string "Toodles!$"

MauvilleCity_Mart_EventScript_Chester_Shedinja:
	compare VAR_EGGMAN_BROTHER_COUNTER, 2
	goto_if_eq MauvilleCity_Mart_EventScript_Chester_Shedinja2
	compare VAR_EGGMAN_BROTHER_COUNTER, 1
	goto_if_eq MauvilleCity_Mart_EventScript_Chester_Shedinja1
	msgbox MauvilleCity_Mart_Text_Chester_Shedinja, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq MauvilleCity_Mart_EventScript_Chester_ShedinjaYes
	msgbox MauvilleCity_Mart_Text_Chester_ShedinjaNo
	release
	end
MauvilleCity_Mart_Text_Chester_Shedinja:
	.string "Ohhh, a Shedinja. Now those can be a\n"
	.string "handful.\p"
	.string "An excellent Pokémon, but sometimes\n"
	.string "you just can't get rid of it. If only\l"
	.string "there was someplace to store them.\p"
	.string "I'm no collector of Shedinja, but my\n"
	.string "little brother loves them.\p"
	.string "I can call him up and he'll be here\n"
	.string "tomorrow, and you can give it to him,\l"
	.string "if you wish.$"
MauvilleCity_Mart_Text_Chester_ShedinjaNo:
	.string "Perfectly fine, perfectly fine.\p"
	.string "If you change your mind, or if you\n"
	.string "come across my specialty, bad eggs,\l"
	.string "feel free to swing by again!\p"
	.string "Toodles!$"
MauvilleCity_Mart_EventScript_Chester_ShedinjaYes:
	setvar VAR_EGGMAN_BROTHER_COUNTER, 2
	msgbox MauvilleCity_Mart_Text_Chester_BadEgg2Yes
	release
	end
MauvilleCity_Mart_Text_Chester_ShedinjaYes:
	.string "Alrighty, I'll give him a call. You\n"
	.string "should pop by tomorrow to see him.\p"
	.string "Toodles!$"
MauvilleCity_Mart_EventScript_Chester_Shedinja2:
	msgbox MauvilleCity_Mart_Text_Chester_Shedinja2
	release
	end
MauvilleCity_Mart_Text_Chester_Shedinja2:
	.string "Oh, yes, your Shedinja.\p"
	.string "Like I said, I'll call my brother and\n"
	.string "he should be here tomorrow.\p"
	.string "If you change your mind about giving\n"
	.string "it up before then, don't worry.\l"
	.string "We won't be offended if you no show.$"
MauvilleCity_Mart_EventScript_Chester_Shedinja1:
	msgbox MauvilleCity_Mart_Text_Chester_Shedinja1
	release
	end
MauvilleCity_Mart_Text_Chester_Shedinja1:
	.string "Oh, yes, your Shedinja.\p"
	.string "My brother is right over there if you\n"
	.string "want to talk to him.\p"
	.string "He'll take that Shedinja off your\n"
	.string "hands.\p"
	.string "But if you changed your mind,\n"
	.string "don't hesitate to simply walk away.$"




MauvilleCity_Mart_EventScript_Brother::
	lock
	faceplayer
	markasdialog
	callnative CheckPartyBadMons
	compare VAR_RESULT, 3
	goto_if_lt MauvilleCity_Mart_EventScript_BrotherNoShed
	compare VAR_EGGMAN_BROTHER_COUNTER, 1
	goto_if_ne MauvilleCity_Mart_EventScript_BrotherAfter
	@
	setyesnotext gYN_Yeah, gYN_Uhhh
	msgbox MauvilleCity_Mart_Text_Brother1, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_Mart_EventScript_BrotherNo
	@
	setyesnotext gYN_YeahBang, gYN_Elipsis2
	msgbox MauvilleCity_Mart_Text_Brother2, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_Mart_EventScript_BrotherNo
	@
	setyesnotext gYN_No, gYN_YeahStutter
	msgbox MauvilleCity_Mart_Text_Brother3, MSGBOX_YESNO
	compare VAR_RESULT, YES @reversed
	goto_if_eq MauvilleCity_Mart_EventScript_BrotherNo
	@
	setyesnotext gYN_YesCaps, gYN_No
	msgbox MauvilleCity_Mart_Text_Brother4, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq MauvilleCity_Mart_EventScript_BrotherNo
	@
	callnative RemovePartyShedinja
	setvar VAR_EGGMAN_BROTHER_COUNTER, 0
	msgbox MauvilleCity_Mart_Text_Brother5
	release
	end
MauvilleCity_Mart_Text_Brother1:
	.string "Hi! My big bro said you had a Shedinja\n"
	.string "that you didn't want anymore.\p"
	.string "He said I could have it if you were\n"
	.string "absolutely sure.\p"
	.string "So… Are you sure?$"
MauvilleCity_Mart_Text_Brother2:
	.string "Are you absolutely sure?$"
MauvilleCity_Mart_Text_Brother3:
	.string "You won't ever see it again, you know.\p"
	.string "Are you really really sure?$"
MauvilleCity_Mart_Text_Brother4:
	.string "Super ultra extra sure?$"
MauvilleCity_Mart_Text_Brother5:
	.string "Alrighty! Thank ya, kind {PLAYER_sir}!\p"
	.string "Hello, {STR_VAR_1}. I'm your new friend!\n"
	.string "We're gonna have so much fun!$"
MauvilleCity_Mart_EventScript_BrotherNo:
	msgbox MauvilleCity_Mart_Text_BrotherNo
	release
	end
MauvilleCity_Mart_Text_BrotherNo:
	.string "Alright…\p"
	.string "It's okay, I'll keep looking for my\n"
	.string "own Shedinja.\p"
	.string "But… I'll be here all day if you,"
	.string "change your mind last minute.$"
MauvilleCity_Mart_EventScript_BrotherAfter:
	msgbox MauvilleCity_Mart_Text_BrotherAfter
	release
	end
MauvilleCity_Mart_Text_BrotherAfter:
	.string "Thanks again, {PLAYER_miss}!\n"
	.string "I'll take good care of it!$"
MauvilleCity_Mart_EventScript_BrotherNoShed:
	msgbox MauvilleCity_Mart_Text_BrotherNoShed
	release
	end
MauvilleCity_Mart_Text_BrotherNoShed:
	.string "Hi! Were you the one with the Shedinja?\p"
	.string "Where is it?$"
