LavaridgeTown_MapScripts:: @ 81EA4D3
	map_script MAP_SCRIPT_ON_LOAD, LavaridgeTown_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_MapScript2
	.byte 0

LavaridgeTown_MapScript2: @ 81EA547
	map_script_2 VAR_LAVARIDGE_RIVAL_STATE, 1, LavaridgeTown_EventScript_1EA551
	.2byte 0

LavaridgeTown_OnTransition: @ 81EA4DE
	setflag FLAG_VISITED_LAVARIDGE_TOWN
	call_if_set FLAG_FLANNERY_GIVES_BADGE_INFO, LavaridgeTown_EventScript_1EA514
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_1EA53F
	call Common_EventScript_SetupRivalGender
	call Common_EventScript_SetupRivalOnBikeGender
	compare VAR_LAVARIDGE_RIVAL_STATE, 1
	call_if_eq LavaridgeTown_EventScript_1EA518
	compare VAR_LAVARIDGE_RIVAL_STATE, 1
	call_if_eq LavaridgeTown_EventScript_1EA543
	end

LavaridgeTown_EventScript_1EA514:: @ 81EA514
	clearflag FLAG_FLANNERY_GIVES_BADGE_INFO
	return

LavaridgeTown_EventScript_1EA53F:: @ 81EA53F
	clearflag FLAG_HIDE_MT_CHIMNEY_TRAINERS
	return

LavaridgeTown_EventScript_1EA518:: @ 81EA518
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 9
	goto_if_eq LavaridgeTown_EventScript_1EA529
	return

LavaridgeTown_EventScript_1EA529:: @ 81EA529
	setobjectxyperm 8, 11, 9
	setobjectxyperm 7, 9, 8
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_HIDE_LAVARIDGE_TOWN_RIVAL_1
	return

LavaridgeTown_EventScript_1EA543:: @ 81EA543
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

@ -----------------------------------------------------

LavaridgeTown_OnLoad:
	call_if_unset FLAG_HIDE_AQUA_HIDEOUT_GRUNTS, LavaridgeTown_OnLoad_HideAquaGrunts
	end
LavaridgeTown_OnLoad_HideAquaGrunts:
	setflag FLAG_TEMP_10
	return

@ -----------------------------------------------------

LavaridgeTown_TriggerScript_EnterHotSpring:: @ 81EA6FA
	specialvar VAR_RESULT, GetPlayerFacingDirection
	compare VAR_RESULT, DIR_SOUTH
	goto_if_eq LavaridgeTown_EventScript_1EA70B
	end
LavaridgeTown_EventScript_1EA70B:: @ 81EA70B
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

@ -----------------------------------------------------
@ Signs

LavaridgeTown_SignScript_Town:: @ 81EA7A5
	msgbox LavaridgeTown_Text_1EB12B, MSGBOX_SIGN
	end
LavaridgeTown_Text_1EB12B: @ 81EB12B
	.string "{PLACE}Lavaridge Town{END}\p"
	.string "“Pokémon CENTER HOT SPRINGS\n"
	.string "An excellent place for relaxing!”$"


LavaridgeTown_SignScript_Gym:: @ 81EA7AE
	msgbox LavaridgeTown_Text_1EB178, MSGBOX_SIGN
	end
LavaridgeTown_Text_1EB178: @ 81EB178
	.string "{GYM}Lavaridge Town Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Flannery\l"
	.string "“One with a fiery passion that burns!”$"


LavaridgeTown_SignScript_HerbShop:: @ 81EA7B7
	msgbox LavaridgeTown_Text_1EB1CB, MSGBOX_SIGN
	end
LavaridgeTown_Text_1EB1CB: @ 81EB1CB
	.string "{PLACE}Pokémon Herb Shop{END}\n"
	.string "“Bitter taste--better cure!”$"


@ -----------------------------------------------------
@ People


LavaridgeTown_EventScript_SpringMan:: @ 81EA70E
	msgbox LavaridgeTown_Text_1EAE03, MSGBOX_NPC
	end
LavaridgeTown_Text_1EAE03: @ 81EAE03
	.string "We draw as much hot water as we need,\n"
	.string "and yet the hot springs never run dry.\p"
	.string "Isn't it magical?\p"
	.string "These hot springs appear near active\n"
	.string "volcanoes. Veins of water under the\l"
	.string "ground are heated by magma to well up\l"
	.string "as hot springs.$"


LavaridgeTown_EventScript_SandMan:: @ 81EA717
	msgbox LavaridgeTown_Text_1EAEE1, MSGBOX_NPC
	end
LavaridgeTown_Text_1EAEE1: @ 81EAEE1
	.string "Being buried in this hot sand is…\n"
	.string "Sigh…\p"
	.string "So warm and heavenly…\p"
	.string "Eh? Gyaah! Ouch!\p"
	.string "A Pokémon nipped my backside!$"


LavaridgeTown_EventScript_WanderingGirl:: @ 81EA720
	msgbox LavaridgeTown_Text_1EAF9B, MSGBOX_NPC
	end
LavaridgeTown_Text_1EAF9B: @ 81EAF9B
	.string "I bathe in the hot springs every day.\p"
	.string "I want to become a beautiful and strong\n"
	.string "Gym Leader like Flannery.$"


LavaridgeTown_EventScript_HotSpringWoman1:: @ 81EA729
	msgbox LavaridgeTown_Text_1EB003, MSGBOX_NPC
	end
LavaridgeTown_Text_1EB003: @ 81EB003
	.string "If people put Pokémon in hot springs,\n"
	.string "it might be seriously strange.\p"
	.string "Why, it might be an electric bath, or\n"
	.string "a bubble bath, or even a lava bath…$"


LavaridgeTown_EventScript_HotSpringWoman2:: @ 81EA732
	msgbox LavaridgeTown_Text_1EB092, MSGBOX_NPC
	end
LavaridgeTown_Text_1EB092: @ 81EB092
	.string "They're claiming that these hot springs\n"
	.string "are good for calming nervous tension,\l"
	.string "relieving aching muscles, solving\l"
	.string "romantic problems, and attracting\l"
	.string "money…$"


LavaridgeTown_EventScript_CenterWoman:: @ 81EA73B
	msgbox LavaridgeTown_Text_1EAF4E, MSGBOX_NPC
	end
LavaridgeTown_Text_1EAF4E: @ 81EAF4E
	.string "Oh, you like hot springs, do you?\p"
	.string "That's surprising for one as young\n"
	.string "as you.$"


LavaridgeTown_EventScript_HotSpringGrunt1::
	msgbox LavaridgeTown_Text_HotSpringGrunt1, MSGBOX_NPC
	end
LavaridgeTown_Text_HotSpringGrunt1:
	.string "Oh, hey. I think I remember seeing you\n"
	.string "during the Slateport heist.\p"
	.string "After the Team disbanded, we've been\n"
	.string "around here, doing our own thing.\p"
	.string "I've got a guy on one arm, and a\n"
	.string "girl on the other.\l"
	.string "I could stay here forever…$"

LavaridgeTown_EventScript_HotSpringGrunt2::
	msgbox LavaridgeTown_Text_HotSpringGrunt2, MSGBOX_NPC
	end
LavaridgeTown_Text_HotSpringGrunt2:
	.string "I'm trying to de-stress.\n"
	.string "I was part of the submarine team.\p"
	.string "The cave collapsed on us as Kyogre\n"
	.string "dug and clawed its way out!\l"
	.string "We thought we were gonna die!\p"
	.string "I don't think I'm ever gonna forget\n"
	.string "that visceral panic and fear…$"

LavaridgeTown_EventScript_HotSpringGrunt3::
	goto_if_set FLAG_TEMP_7, LavaridgeTown_EventScript_HotSpringGrunt3Post
	selectpointer_ongender LavaridgeTown_Text_HotSpringGrunt3m, LavaridgeTown_Text_HotSpringGrunt3f
	bufferstring 0, 0
	msgbox LavaridgeTown_Text_HotSpringGrunt3, MSGBOX_NPC
	setflag FLAG_TEMP_7
	end
LavaridgeTown_EventScript_HotSpringGrunt3Post:
	msgbox LavaridgeTown_Text_HotSpringGrunt3post, MSGBOX_NPC
	end
LavaridgeTown_Text_HotSpringGrunt3:
	.string "{FORCE_SPEED_MID}"
	.string "Hey {STR_VAR_1}, how you doing?\n"
	.string "Come to… join us?\p"
	.string "{RESET_SPEED}"
	.string "You're what?!{PAUSE 30} Oh!{PAUSE 30} …{PAUSE 30} …{PAUSE 30} Y-You look\n"
	.string "very mature for…{PAUSE 20} your age…\p" @fallthrough
LavaridgeTown_Text_HotSpringGrunt3post:
	.string "Well, I've got a kid sister your age.\n"
	.string "Maybe she'd be interested, if you are.$"
LavaridgeTown_Text_HotSpringGrunt3m:
	.string "handsome$"
LavaridgeTown_Text_HotSpringGrunt3f:
	.string "darling$"

@ -----------------------------------------------------
@ Egg Woman

LavaridgeTown_EventScript_EggWoman:: @ 81EA744
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_1EA787
	msgbox LavaridgeTown_Text_1EAB80, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq LavaridgeTown_EventScript_1EA79B
	getpartysize
	compare VAR_RESULT, 6
	goto_if_eq LavaridgeTown_EventScript_1EA791
	msgbox LavaridgeTown_Text_1EACC0, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_FANFA4
	message LavaridgeTown_Text_1EACF4
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end
LavaridgeTown_Text_1EAB80: @ 81EAB80
	.string "I have here an egg.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with Pokémon and\l"
	.string "carried about.\p"
	.string "You are a trainer, yes?\n"
	.string "And your Pokémon radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this egg to hatch?$"
LavaridgeTown_Text_1EACC0: @ 81EACC0
	.string "Good! I hope you'll walk plenty with\n"
	.string "this here egg!$"
LavaridgeTown_Text_1EACF4: @ 81EACF4
	.string "{PLAYER} received the egg.$"

LavaridgeTown_EventScript_1EA787:: @ 81EA787
	msgbox LavaridgeTown_Text_1EAD9E, MSGBOX_DEFAULT
	release
	end
LavaridgeTown_Text_1EAD9E: @ 81EAD9E
	.string "Every so often, an egg will be found at\n"
	.string "the Pokémon DAY CARE.\p"
	.string "Or at least that's how the rumor goes.$"

LavaridgeTown_EventScript_1EA791:: @ 81EA791
	msgbox LavaridgeTown_Text_1EAD09, MSGBOX_DEFAULT
	release
	end
LavaridgeTown_Text_1EAD09: @ 81EAD09
	.string "Oh? You've too many Pokémon.\n"
	.string "There's no room for this egg…$"

LavaridgeTown_EventScript_1EA79B:: @ 81EA79B
	msgbox LavaridgeTown_Text_1EAD44, MSGBOX_DEFAULT
	release
	end
LavaridgeTown_Text_1EAD44: @ 81EAD44
	.string "As you wish, then…\p"
	.string "If you have a change of heart about\n"
	.string "hatching this egg, I will be here.$"


@ -----------------------------------------------------
@ Rival Event

LavaridgeTown_EventScript_1EA551:: @ 81EA551
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA63A
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA65C
	delay 20
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LavaridgeTown_EventScript_1EA630
	compare VAR_RESULT, FEMALE
	call_if_eq LavaridgeTown_EventScript_1EA635
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA6A1
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA6AC
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_1EA5B5
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_1EA5DA
	end

LavaridgeTown_EventScript_1EA63A:: @ 81EA63A
	applymovement 8, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_1EA65C:: @ 81EA65C
	opendoor 12, 15
	waitdooranim
	addobject 8
	applymovement 8, LavaridgeTown_Movement_1EA6F8
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement 8, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return
LavaridgeTown_Movement_1EA6F8: @ 81EA6F8
	walk_down
	step_end

LavaridgeTown_EventScript_1EA630:: @ 81EA630
	playbgm MUS_GIRL_SUP, 1
	return

LavaridgeTown_EventScript_1EA635:: @ 81EA635
	playbgm MUS_BOY_SUP, 1
	return

LavaridgeTown_EventScript_1EA6A1:: @ 81EA6A1
	applymovement 8, LavaridgeTown_Movement_1EA6F4
	waitmovement 0
	return
LavaridgeTown_Movement_1EA6F4: @ 81EA6F4
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_EventScript_1EA6AC:: @ 81EA6AC
	applymovement 8, LavaridgeTown_Movement_1EA6ED
	waitmovement 0
	return
LavaridgeTown_Movement_1EA6ED: @ 81EA6ED
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_EventScript_1EA5B5:: @ 81EA5B5
	markasdialog
	msgbox LavaridgeTown_Text_1EA7C0, MSGBOX_DEFAULT
	giveitem_std ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	message LavaridgeTown_Text_1EA897
	waitmessage
	message LavaridgeTown_BetterThanYou_Text
	waitmessage
	msgbox LavaridgeTown_GottaGo_Text, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_1EA5FF
	end
LavaridgeTown_Text_1EA7C0: @ 81EA7C0
	.string "May: {PLAYER}! Long time no see…\p"
	.string "While I visited the hot springs,\n"
	.string "you convinced the Lavaridge Gym leader\l"
	.string "to give you a badge.\p"
	.string "You must have been very… persuasive.\p"
	.string "I guess here's a gift for that win.$"
LavaridgeTown_Text_1EA897: @ 81EA897
	.string "May: With those Go-Goggles, you'll\n"
	.string "have no trouble if you get lost in\l"
	.string "the desert near Route 111.\p"
	.string "But, wow, {PLAYER}…\n"
	.string "Challenging Gyms…\p"
	.string "You're trying hard I see…\n"
	.string "For what, I don't know…\p"
	.string "I heard that Petalburg City's Gym\n"
	.string "should be open again soon.\l"
	.string "That's where I'm heading now.\p"
	.string "I hope the new Gym Leader will be\n"
	.string "nicer… Malaqui could have given you\l"
	.string "a run for your money.\p$"

LavaridgeTown_EventScript_1EA5DA:: @ 81EA5DA
	markasdialog
	msgbox LavaridgeTown_Text_1EA9A2, MSGBOX_DEFAULT
	giveitem_std ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	message LavaridgeTown_Text_1EAA2E
	waitmessage
	message LavaridgeTown_BetterThanYou_Text
	waitmessage
	msgbox LavaridgeTown_GottaGo_Text, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_1EA5FF
	end
LavaridgeTown_Text_1EA9A2: @ 81EA9A2
	.string "Brendan: {PLAYER}, ah, it's been a bit.\n"
	.string "That's a decent collection of Badges.\p"
	.string "Who did you steal them from?\p"
	.string "Ah… I-I mean, here, a gift for your…\n"
	.string "tenacity.$"
LavaridgeTown_Text_1EAA2E: @ 81EAA2E
	.string "Brendan: Keep those with you if you're\n"
	.string "feel like getting lost in that desert\l"
	.string "near Route 111.\p"
	.string "But yeah… you're trying hard I see…\n"
	.string "For what, I don't know…\p"
	.string "I heard that Petalburg City's Gym\n"
	.string "should be open again soon.\l"
	.string "That's where I'm heading now.\p"
	.string "I hope the new Gym Leader will be\n"
	.string "nicer… Malaqui could have given you\l"
	.string "a run for your money.\p$"
LavaridgeTown_BetterThanYou_Text::
	.string "{COLOR LIGHT_GREY}{SHADOW WHITE}"
	.string "(in the kindness department…)\p$"
LavaridgeTown_GottaGo_Text::
	.string "OK, gotta go!$"

LavaridgeTown_EventScript_1EA5FF:: @ 81EA5FF
	closemessage
	removeobject 8
	addobject 7
	delay 30
	compare VAR_0x8008, 9
	call_if_eq LavaridgeTown_EventScript_1EA6B7
	compare VAR_0x8008, 9
	call_if_ne LavaridgeTown_EventScript_1EA6C9
	removeobject 7
	setvar VAR_LAVARIDGE_RIVAL_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_1EA6B7:: @ 81EA6B7
	applymovement EVENT_OBJ_ID_PLAYER, LavaridgeTown_Movement_1EA6DF
	applymovement 7, LavaridgeTown_Movement_1EA6E3
	waitmovement 0
	return
LavaridgeTown_Movement_1EA6DF: @ 81EA6DF
	delay_16
	delay_8
	walk_in_place_fastest_right
	step_end
LavaridgeTown_Movement_1EA6E3: @ 81EA6E3
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_EventScript_1EA6C9:: @ 81EA6C9
	applymovement 7, LavaridgeTown_Movement_1EA6D4
	waitmovement 0
	return
LavaridgeTown_Movement_1EA6D4: @ 81EA6D4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
