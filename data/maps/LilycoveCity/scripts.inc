LilycoveCity_MapScripts:: @ 81E2B3C
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	.byte 0

@ -----------------------------------------------------

LilycoveCity_OnTransition: @ 81E2B47
	setflag FLAG_VISITED_LILYCOVE_CITY
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	setflag FLAG_HIDE_LILYCOVE_CONTEST_HALL_REPORTER
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeatherAlternating
	call Common_EventScript_SetupRivalGender
	end

@ -----------------------------------------------------

LilycoveCity_OnLoad: @ 81E2B61
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_AddWalimers
	end

LilycoveCity_EventScript_AddWalimers:: @ 81E2B6B
	setmetatile 76, 12, 656, 1
	setmetatile 77, 12, 657, 1
	setmetatile 76, 13, 672, 1
	setmetatile 77, 13, 673, 1
	setmetatile 76, 14, 664, 1
	setmetatile 77, 14, 665, 1
	setmetatile 76, 15, 672, 1
	setmetatile 77, 15, 673, 1
	setmetatile 77, 16, 664, 1
	setmetatile 78, 16, 665, 1
	setmetatile 77, 17, 672, 1
	setmetatile 78, 17, 673, 1
	return

@ -----------------------------------------------------
@ Signs

LilycoveCity_EventScript_1E2CFF:: @ 81E2CFF
	msgbox LilycoveCity_Text_1E448B, MSGBOX_SIGN
	end
LilycoveCity_Text_1E448B: @ 81E448B
	.string "{PLACE}Lilycove City{END}\p"
	.string "“Where the land ends and the\n"
	.string "sea begins.”$"


LilycoveCity_EventScript_1E2D08:: @ 81E2D08
	msgbox LilycoveCity_Text_1E44C3, MSGBOX_SIGN
	end
LilycoveCity_Text_1E44C3: @ 81E44C3
	.string "{PLACE}Pokémon Contest Hall{END}\n"
	.string "“The gathering place for trainers!”$"


LilycoveCity_EventScript_1E2D11:: @ 81E2D11
	msgbox LilycoveCity_Text_1E44FC, MSGBOX_SIGN
	end
LilycoveCity_Text_1E44FC: @ 81E44FC
	.string "{PLACE}Cove Lily Motel{END}\p"
	.string "“Remember us as Cove Lily of\n"
	.string "Lilycove.”$"


LilycoveCity_EventScript_1E2D1A:: @ 81E2D1A
	lockall
	specialvar VAR_0x8004, CountPlayerContestPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_1E2D3A
	msgbox LilycoveCity_Text_1E4571, MSGBOX_SIGN
	releaseall
	end
LilycoveCity_Text_1E4571: @ 81E4571
	.string "{PLACE}Lilycove Museum{END}\p"
	.string "“{PLAYER}'s Pokémon Collection\n"
	.string "on exhibit!”$"
LilycoveCity_EventScript_1E2D3A:: @ 81E2D3A
	msgbox LilycoveCity_Text_1E4534, MSGBOX_SIGN
	releaseall
	end
LilycoveCity_Text_1E4534: @ 81E4534
	.string "{PLACE}Lilycove Museum{END}\p"
	.string "“Pokémon Masterpiece Collection\n"
	.string "on exhibit!”$"


LilycoveCity_EventScript_1E2D44:: @ 81E2D44
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_1E2D58
	msgbox LilycoveCity_Text_1E45A7, MSGBOX_SIGN
	releaseall
	end
LilycoveCity_Text_1E45A7: @ 81E45A7
	.string "{PLACE}Lilycove City Harbor{END}\p"
	.string "“The ferry S.S. TIDAL is under\n"
	.string "construction in Slateport City.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"


LilycoveCity_EventScript_1E2D58:: @ 81E2D58
	msgbox LilycoveCity_Text_1E4624, MSGBOX_SIGN
	releaseall
	end
LilycoveCity_Text_1E4624: @ 81E4624
	.string "{PLACE}Lilycove City Harbor{END}\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. TIDAL.”$"

LilycoveCity_EventScript_1E2D62:: @ 81E2D62
	msgbox LilycoveCity_Text_1E466E, MSGBOX_SIGN
	end
LilycoveCity_Text_1E466E: @ 81E466E
	.string "{PLACE}Pokémon Trainer Fan Club{END}\p"
	.string "The names of trainers are scribbled\n"
	.string "all over the sign…$"


LilycoveCity_EventScript_1E2D6B:: @ 81E2D6B
	msgbox LilycoveCity_Text_1E46BE, MSGBOX_SIGN
	end
LilycoveCity_Text_1E46BE: @ 81E46BE
	.string "{PLACE}Lilycove Department Store{END}\p"
	.string "“Overflowing with great merchandise\n"
	.string "and excitement!\p"
	.string "“A great place to find that something\n"
	.string "you need!”$"


LilycoveCity_EventScript_1E2D74:: @ 81E2D74
	msgbox LilycoveCity_Text_1E473D, MSGBOX_SIGN
	end
LilycoveCity_Text_1E473D: @ 81E473D
	.string "{PLACE}Move Deleter's House{END}\p"
	.string "“Unwanted Pokémon moves deleted.”$"


@ -----------------------------------------------------

LilycoveCity_EventScript_1E2BD8:: @ 81E2BD8
	lock
	faceplayer
	markasdialog
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_1E2C18
	msgbox LilycoveCity_Text_2A7244, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_2A72E3, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_2A7244: @ 82A7244
	.string "When it gets right down to it…\p"
	.string "The same way suits suit me perfectly,\n"
	.string "a crisp breeze suits the sea.\p"
	.string "And you, a berry suits you to a “T”…\p"
	.string "Why should that be so?$"
LilycoveCity_Text_2A72E3: @ 82A72E3
	.string "When it gets right down to it…\p"
	.string "It's because you're a trainer!$"
LilycoveCity_EventScript_1E2C18:: @ 81E2C18
	msgbox LilycoveCity_Text_2A7321, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_2A7321: @ 82A7321
	.string "When it gets right down to it…\p"
	.string "The way dignified simplicity suits me,\n"
	.string "{POKEBLOCK}s perfectly suit Pokémon.$"



LilycoveCity_EventScript_1E2C22:: @ 81E2C22
	msgbox LilycoveCity_Text_1E3D9E, MSGBOX_NPC
	end
LilycoveCity_Text_1E3D9E: @ 81E3D9E
	.string "There's a Pokémon Contest Hall\n"
	.string "right in this here town. \p"
	.string "That means well-raised Pokémon will\n"
	.string "come from all over the country.\p"
	.string "My heart swells with excitement!$"


LilycoveCity_EventScript_1E2C2B:: @ 81E2C2B
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_1E2C40
	msgbox LilycoveCity_Text_1E3E3C, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E3E3C: @ 81E3E3C
	.string "Have you seen that strange cave in\n"
	.string "the cove at the edge of town?$"
LilycoveCity_EventScript_1E2C40:: @ 81E2C40
	msgbox LilycoveCity_Text_1E3E7D, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E3E7D: @ 81E3E7D
	.string "I'm going to teach my Pokémon some new\n"
	.string "moves for entering a contest.\p"
	.string "So, I'm going to see the Move Deleter\n"
	.string "and make it forget some moves.$"


LilycoveCity_EventScript_1E2C4A:: @ 81E2C4A
	msgbox LilycoveCity_Text_1E3F05, MSGBOX_NPC
	end
LilycoveCity_Text_1E3F05: @ 81E3F05
	.string "I came from Unova.\p"
	.string "The Hoenn region is beautiful with\n"
	.string "all its water and verdant nature.\p"
	.string "And all the Pokémon! They're all\n"
	.string "different from the ones we have!$"


LilycoveCity_EventScript_1E2C53:: @ 81E2C53
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2C68
	msgbox LilycoveCity_Text_1E3FAB, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E3FAB: @ 81E3FAB
	.string "Team Aqua's been training their\n"
	.string "Wailmer in the cove.\p"
	.string "We sailors can't get our boats out\n"
	.string "to sea with them in the way!$"
LilycoveCity_EventScript_1E2C68:: @ 81E2C68
	msgbox LilycoveCity_Text_1E4020, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E4020: @ 81E4020
	.string "Ahoy, did you know?\p"
	.string "Someone punted Team Aqua out of\n"
	.string "the way for us!\p"
	.string "That got the WAILMER out of the cove,\n"
	.string "so we can get our boats out again.$"


LilycoveCity_EventScript_1E2C72:: @ 81E2C72
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_1E2C87
	msgbox LilycoveCity_Text_1E40AD, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E40AD: @ 81E40AD
	.string "I was taking a relaxing snooze at the\n"
	.string "seaside inn to the sound of waves…\p"
	.string "When someone stole my Pokémon!\p"
	.string "Who's the abductor?\n"
	.string "Team Aqua? Is it Team Aqua?$"
LilycoveCity_EventScript_1E2C87:: @ 81E2C87
	msgbox LilycoveCity_Text_1E4145, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E4145: @ 81E4145
	.string "My missing Pokémon…\n"
	.string "It came back without me noticing!$"


LilycoveCity_EventScript_1E2C91:: @ 81E2C91
	msgbox LilycoveCity_Text_1E417B, MSGBOX_NPC
	end
LilycoveCity_Text_1E417B: @ 81E417B
	.string "I'm an art dealer.\p"
	.string "I am a buyer and seller of fine art,\n"
	.string "especially paintings.\p"
	.string "I've heard that the museum here has\n"
	.string "magnificent works on exhibit…$"


LilycoveCity_EventScript_1E2C9A:: @ 81E2C9A
	msgbox LilycoveCity_Text_1E420B, MSGBOX_DIALOG
	end
LilycoveCity_Text_1E420B: @ 81E420B
	.string "Even as we grow old and wrinkled,\n"
	.string "the sea remains forever young with\l"
	.string "the vivid brilliance of life…\p"
	.string "Fwohoho fwohohohoho…$"


LilycoveCity_EventScript_1E2CA3:: @ 81E2CA3
	msgbox LilycoveCity_Text_1E4283, MSGBOX_DIALOG
	end
LilycoveCity_Text_1E4283: @ 81E4283
	.string "It was sixty years ago that my husband\n"
	.string "proposed to me here.\l"
	.string "The sea remains as beautiful as ever.\p"
	.string "Mufufufu mufufufufufu…$"


LilycoveCity_EventScript_1E2CAC:: @ 81E2CAC
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_1E2CC1
	msgbox LilycoveCity_Text_1E42FC, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E42FC: @ 81E42FC
	.string "Hm, you know of the peculiar cavern\n"
	.string "in this cove?\p"
	.string "That had been a natural formation,\n"
	.string "but then that Team Aqua lot came\l"
	.string "along and made their renovations.\p"
	.string "They call themselves\n"
	.string "the “nature-loving Team Aqua”!\p"
	.string "But what they do and what they say\n"
	.string "don't match at all!$"
LilycoveCity_EventScript_1E2CC1:: @ 81E2CC1
	msgbox LilycoveCity_Text_1E43FF, MSGBOX_DEFAULT
	release
	end
LilycoveCity_Text_1E43FF: @ 81E43FF
	.string "That cave in the cove…\p"
	.string "I didn't notice it right away,\n"
	.string "but it's completely empty now.\p"
	.string "That Team Aqua lot, they must\n"
	.string "have gone away for good.$"


LilycoveCity_EventScript_1E2CCB:: @ 81E2CCB
	msgbox LilycoveCity_Text_1E48A5, MSGBOX_NPC
	end
LilycoveCity_Text_1E48A5: @ 81E48A5
	.string "I heard there's a tower somewhere out\n"
	.string "on the sea routes.\p"
	.string "It's called the Sky Pillar, I hear.$"


LilycoveCity_EventScript_1E2CD4:: @ 81E2CD4
	msgbox LilycoveCity_Text_1E4902, MSGBOX_NPC
	end
LilycoveCity_Text_1E4902: @ 81E4902
	.string "I saw this tall tower somewhere\n"
	.string "around Route 131.\p"
	.string "Could that possibly be…?$"


LilycoveCity_EventScript_1E2CDD:: @ 81E2CDD
	lockall
	msgbox LilycoveCity_Text_1E494D, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceOriginalDirection
	end
LilycoveCity_Text_1E494D: @ 81E494D
	.string "We just arrived here on our\n"
	.string "honeymoon vacation.\p"
	.string "We happened to see a Dragon-type\n"
	.string "Pokémon flying way up in the sky.\p"
	.string "Do cool Pokémon like that live in\n"
	.string "the Hoenn region?$"


LilycoveCity_EventScript_1E2CEE:: @ 81E2CEE
	lockall
	msgbox LilycoveCity_Text_1E49F4, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceOriginalDirection
	end
LilycoveCity_Text_1E49F4: @ 81E49F4
	.string "On our honeymoon, we vowed to see as\n"
	.string "many rare Pokémon as we can.\p"
	.string "So we were delighted to see a rare\n"
	.string "Pokémon as soon as we arrived.\p"
	.string "I mean, we are totally happy!$"


LilycoveCity_EventScript_1E302D:: @ 81E302D
	lock
	faceplayer
	markasdialog
	msgbox LilycoveCity_Text_1E4774, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq LilycoveCity_EventScript_1E304F
	compare VAR_RESULT, 0
	call_if_eq LilycoveCity_EventScript_1E3058
	release
	end
LilycoveCity_Text_1E4774: @ 81E4774
	.string "Do you know about the machine\n"
	.string "{REF}Berry Blender{END}?$"
LilycoveCity_EventScript_1E304F:: @ 81E304F
	msgbox LilycoveCity_Text_1E47A1, MSGBOX_DEFAULT
	return
LilycoveCity_Text_1E47A1: @ 81E47A1
	.string "People have to work together to get it\n"
	.string "to spin faster.\p"
	.string "The faster you can make it spin, the\n"
	.string "better {POKEBLOCK}s you can get, I've heard.$"
LilycoveCity_EventScript_1E3058:: @ 81E3058
	msgbox LilycoveCity_Text_1E4824, MSGBOX_DEFAULT
	return
LilycoveCity_Text_1E4824: @ 81E4824
	.string "It's used for making a kind of candy\n"
	.string "called a {POKEBLOCK}.\p"
	.string "If you give a good {POKEBLOCK} to a Pokémon,\n"
	.string "its condition will improve by a lot.$"

@ -----------------------------------------------------
@ Team Aqua

LilycoveCity_EventScript_1E2D7D:: @ 81E2D7D
	lockall
	markasdialog
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_1E2DB0
	msgbox LilycoveCity_Text_1E3D1F, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_1E3D4A, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end
LilycoveCity_Text_1E3D4A: @ 81E3D4A
	.string "Hunh? What do you want?\p"
	.string "You're messing up our training,\n"
	.string "so can you, like, get lost?$"
LilycoveCity_EventScript_1E2DB0:: @ 81E2DB0
	msgbox LilycoveCity_Text_1E3D1F, MSGBOX_DEFAULT
	releaseall
	end
LilycoveCity_Text_1E3D1F: @ 81E3D1F
	.string "There! Wailmer!\n"
	.string "Leap out of the water now!$"


LilycoveCity_EventScript_1E2DBA:: @ 81E2DBA
	msgbox LilycoveCity_Text_1E3B2C, MSGBOX_NPC
	end
LilycoveCity_Text_1E3B2C: @ 81E3B2C
	.string "Fufufu…\p"
	.string "We moved more loot into our secret\n"
	.string "Hideout today…\p"
	.string "Have you visited?\n"
	.string "It's out in the harbor.$"


LilycoveCity_EventScript_1E2DC3:: @ 81E2DC3
	msgbox LilycoveCity_Text_1E3B95, MSGBOX_NPC
	end
LilycoveCity_Text_1E3B95: @ 81E3B95
	.string "I'm just a grunt, so I don't know what\n"
	.string "the boss is thinking…\p"
	.string "But being on Team Aqua, I know I'll get\n"
	.string "the chance to do big things!\p"
	.string "What big things do you want to do?$"


LilycoveCity_EventScript_1E2DCC:: @ 81E2DCC
	msgbox LilycoveCity_Text_1E3C46, MSGBOX_NPC
	end
LilycoveCity_Text_1E3C46: @ 81E3C46
	.string "Hey, you!\p"
	.string "Have you been to the hideout?\p"
	.string "It's the cave in the cove!\p"
	.string "Just don't invite anyone else.\n"
	.string "It's for full-time members only.$"


LilycoveCity_EventScript_1E2DD5:: @ 81E2DD5
	msgbox LilycoveCity_Text_1E3CBE, MSGBOX_NPC
	end
LilycoveCity_Text_1E3CBE: @ 81E3CBE
	.string "If this whole wide world becomes ours,\n"
	.string "Team Aqua's, it will be a happier\l"
	.string "place for Pokémon, too.$"


@ -----------------------------------------------------
@ Rival

LilycoveCity_EventScript_Rival:: @ 81E2DDE
	lock
	faceplayer
	markasdialog
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LilycoveCity_EventScript_1E2DF8
	compare VAR_RESULT, FEMALE
	goto_if_eq LilycoveCity_EventScript_1E2E6B
	end

LilycoveCity_EventScript_1E2DF8:: @ 81E2DF8
	playbgm MUS_GIRL_SUP, 1
	setyesnotext gYN_Fine2, gYN_UgNo
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2E48
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2E51
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_EventScript_1E2E5A
	msgbox LilycoveCity_Text_1E3234, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_1E2EDE
	case 1, LilycoveCity_EventScript_1E2EEE
	case 2, LilycoveCity_EventScript_1E2EFE
	end
LilycoveCity_Text_1E3234: @ 81E3234
	.string "May: The Pokémon I raised won't be\n"
	.string "beaten by you, {PLAYER}!$"

LilycoveCity_EventScript_1E2E48:: @ 81E2E48
	msgbox LilycoveCity_Text_1E31F5, MSGBOX_YESNO
	return
LilycoveCity_Text_1E31F5: @ 81E31F5
	.string "May: Come on, battle with me, or\n"
	.string "are you too scared?!$"

LilycoveCity_EventScript_1E2E51:: @ 81E2E51
	msgbox LilycoveCity_Text_1E3061, MSGBOX_YESNO
	return
LilycoveCity_Text_1E3061: @ 81E3061
	.string "May: Oh, hey?\n"
	.string "{PLAYER}, are you shopping, too?\p"
	.string "I bought a whole bunch of dolls and\n"
	.string "posters.\p"
	.string "Of course, I've also caught a lot of\n"
	.string "Pokémon, and I'm raising them\l"
	.string "{BOLD}properly{END} too, ya know.\p"
	.string "I'm betting you're worried if you're\n"
	.string "raising Pokémon properly, {PLAYER}.\p"
	.string "I'll battle with you, so you can show\n"
	.string "me your Pokémon, {PLAYER}.$"

LilycoveCity_EventScript_1E2E5A:: @ 81E2E5A
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_1E318D, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end
LilycoveCity_Text_1E318D: @ 81E318D
	.string "May: Oh, why? {PLAYER}, haven't you\n"
	.string "been raising your Pokémon right?\p"
	.string "Do you not know how…?$"


LilycoveCity_EventScript_1E2E6B:: @ 81E2E6B
	playbgm MUS_BOY_SUP, 1
	setyesnotext gYN_FOff, gYN_UgNo
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2EBB
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_1E2EC4
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_EventScript_1E2ECD
	msgbox LilycoveCity_Text_1E373C, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_1E2F0E
	case 1, LilycoveCity_EventScript_1E2F1E
	case 2, LilycoveCity_EventScript_1E2F2E
	end
LilycoveCity_Text_1E373C: @ 81E373C
	.string "Brendan: Bring it!!$"

LilycoveCity_EventScript_1E2EBB:: @ 81E2EBB
	msgbox LilycoveCity_Text_1E36FA, MSGBOX_YESNO
	return
LilycoveCity_Text_1E36FA: @ 81E36FA
	.string "Brendan: I know I touched a nerve.\n"
	.string "I know you wanna fight me!$"

LilycoveCity_EventScript_1E2EC4:: @ 81E2EC4
	msgbox LilycoveCity_Text_1E3608, MSGBOX_YESNO
	return
LilycoveCity_Text_1E3608: @ 81E3608
	.string "Brendan: Oh, hey, it's {PLAYER}.\n"
	.string "I'm running an errand for my dad.\p"
	.string "Does your dad ever send you on\n"
	.string "errands for him? Or is he never\l"
	.string "around enough?\p"
	.string "That's right, you wanna fight?!$"

LilycoveCity_EventScript_1E2ECD:: @ 81E2ECD
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_1E36BF, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end
LilycoveCity_Text_1E36BF: @ 81E36BF
	.string "Brendan: Oh, what's the matter?\n"
	.string "Don't have the confidence?!$"


LilycoveCity_EventScript_1E2EDE:: @ 81E2EDE
	trainerbattle_no_intro TRAINER_MAY_12, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end
LilycoveCity_EventScript_1E2EEE:: @ 81E2EEE
	trainerbattle_no_intro TRAINER_MAY_13, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end
LilycoveCity_EventScript_1E2EFE:: @ 81E2EFE
	trainerbattle_no_intro TRAINER_MAY_11, LilycoveCity_Text_1E3275
	goto LilycoveCity_EventScript_1E2F3E
	end
LilycoveCity_Text_1E3275: @ 81E3275
	.string "… … … … … … … …\p"
	.string "I remember the battle I had with you,\n"
	.string "{PLAYER}, on Route 103.\p"
	.string "That battle helped you become…\n"
	.string "{BOLD}this{END}, {PLAYER}, didn't it?$"


LilycoveCity_EventScript_1E2F0E:: @ 81E2F0E
	trainerbattle_no_intro TRAINER_BRENDAN_14, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end
LilycoveCity_EventScript_1E2F1E:: @ 81E2F1E
	trainerbattle_no_intro TRAINER_BRENDAN_15, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end
LilycoveCity_EventScript_1E2F2E:: @ 81E2F2E
	trainerbattle_no_intro TRAINER_BRENDAN_13, LilycoveCity_Text_1E3777
	goto LilycoveCity_EventScript_1E2FAA
	end
LilycoveCity_Text_1E3777: @ 81E3777
	.string "Humph…\n"
	.string "You're no match for me.\p"
	.string "That stings a bit for me to say…$"


LilycoveCity_EventScript_1E2F3E:: @ 81E2F3E
	msgbox LilycoveCity_Text_1E32FB, MSGBOX_CDIALOG
	@ setvar VAR_RESULT, 0
	@ call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_1E2F76
	@ compare VAR_RESULT, 0
	@ call_if_eq LilycoveCity_EventScript_1E2F86
	@ compare VAR_RESULT, 1
	@ call_if_eq LilycoveCity_EventScript_1E2F8F
	setflag FLAG_CAN_CONCEDE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_PICHU_DOLL
	goto LilycoveCity_EventScript_1E3006
	end
LilycoveCity_Text_1E32FB: @ 81E32FB
	.string "May: {PLAYER}, I don't know if you're\n"
	.string "aware, but you CAN forfiet a battle.\p"
	.string "You don't have to fight every battle\l"
	.string "tooth-and-nail. It's okay to lose.\p"
	.string "… … … … …\p"
	.string "I'm going back to Littleroot soon.\p"
	.string "It's too dangerous out here with your\n"
	.string "lot running about.\p"
	.string "{PLAYER}, what are you going to do?\p"
	.string "Because the life you've got isn't a\n"
	.string "good one.$"

LilycoveCity_EventScript_1E2FAA:: @ 81E2FAA
	msgbox LilycoveCity_Text_1E37D7, MSGBOX_DEFAULT
	@ setvar VAR_RESULT, 0
	@ call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_1E2F76
	@ compare VAR_RESULT, 0
	@ call_if_eq LilycoveCity_EventScript_1E2FE2
	@ compare VAR_RESULT, 1
	@ call_if_eq LilycoveCity_EventScript_1E2FEB
	setflag FLAG_CAN_CONCEDE
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_SWABLU_DOLL
	goto LilycoveCity_EventScript_1E3006
	end
LilycoveCity_Text_1E37D7: @ 81E37D7
	.string "Brendan: {PLAYER}, no matter what I do\n"
	.string "I can't get through to you, it seems.\p"
	.string "You know you ARE allowed to concede\n"
	.string "from a battle! You can stop before\l"
	.string "things go too far…\p"
	.string "… … … … …\p"
	.string "I plan on going home to Littleroot.\p"
	.string "It's too dangerous out here with you\n"
	.string "and your gang running around.\p"
	.string "{PLAYER}, what are you going to do?\p"
	.string "Because the life you've got isn't a\n"
	.string "good one.$"

LilycoveCity_EventScript_1E3006:: @ 81E3006
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end
