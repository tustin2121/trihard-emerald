SlateportCity_MapScripts:: @ 81DCC61
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_MapScript2_FrameTable
	.byte 0

#define LID_SCOTT 35
#define LID_CAPT_STERN 11
#define LID_REPORTER 10
#define LID_CAMERAMAN 9

SlateportCity_OnTransition: @ 81DCC6C
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_1DCC8D
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCC99
	compare VAR_CROSS_MAP_TRIGGER, 1
	call_if_eq SlateportCity_EventScript_SailOffPrep
	end
SlateportCity_EventScript_1DCC8D:: @ 81DCC8D
	setflag FLAG_VISITED_SLATEPORT_CITY
	setvar VAR_LINK_CONTEST_ROOM_STATE, 0
	setflag FLAG_HIDE_SLATEPORT_CITY_CONTEST_REPORTER
	return
SlateportCity_EventScript_1DCC99:: @ 81DCC99
	setobjectxyperm LID_CAPT_STERN, 36, 13
	setobjectxyperm 7, 25+8, 13
	setobjectxyperm 3, 25+8, 14
	setobjectxyperm 6, 27+8, 16
	setobjectxyperm 8, 28+8, 16
	setobjectxyperm 1, 29+8, 16
	setobjectxyperm 2, 30+8, 17
	setobjectmovementtype LID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype 7, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 2, MOVEMENT_TYPE_FACE_UP
	return

SlateportCity_EventScript_SailOffPrep:
	setobjectxyperm 38, 44, 12
	return


SlateportCity_EventScript_PositionScottAfterMuseum:: @ 81DCCE7
	setflag FLAG_HIDE_MAP_NAME_POPUP
	@ Check if the player is on the left of the door
	getplayerxy VAR_0x8004, VAR_0x8005
	compare VAR_0x8004, 38
	goto_if_eq SlateportCity_EventScript_1DCD06
	setobjectxyperm LID_SCOTT, 23, 27
	setobjectmovementtype LID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return
SlateportCity_EventScript_1DCD06:: @ 81DCD06
	setobjectxyperm LID_SCOTT, 22, 27
	setobjectmovementtype LID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_MapScript2_FrameTable: @ 81DCD12
	map_script_2 VAR_SLATEPORT_MUSEUM_HEIST_STATE, 3, SlateportCity_EventScript_LoganAfterMuseum
	map_script_2 VAR_CROSS_MAP_TRIGGER, 1, SlateportCity_EventScript_SailOff
	.2byte 0

SlateportCity_EventScript_SailOff:
	applymovement 38, SlateportCity_Movement_SailOff
	setobjectxyperm 38, 47, 0
	setvar VAR_CROSS_MAP_TRIGGER, 0
	end
SlateportCity_Movement_SailOff:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end


@ -----------------------------------------------------
@ Signs

SlateportCity_SignScript_BattleTent:: @ 81DCF36
	msgbox SlateportCity_Text_1DE8BC, MSGBOX_SIGN
	end
SlateportCity_Text_1DE8BC: @ 81DE8BC
	.string "{PLACE}Pokémon Contest{END}\n"
	.string "“Find it! The most fabulous Pokémon!”$"


SlateportCity_SignScript_SternsShipyard:: @ 81DCF3F
	lockall
	msgbox SlateportCity_Text_SternsShipyard, MSGBOX_SIGN
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_1DCF66
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_1DCF5C
	msgbox SlateportCity_Text_1DE8F8, MSGBOX_DEFAULT
	releaseall
	end
SlateportCity_Text_SternsShipyard:
	.string "{PLACE}Stern's Shipyard$"
SlateportCity_Text_1DE8F8: @ 81DE8F8
	.string "“Wanted: A sailor capable of sailing\n"
	.string "in all currents.”$"
SlateportCity_EventScript_1DCF5C:: @ 81DCF5C
	msgbox SlateportCity_Text_1DE940, MSGBOX_DEFAULT
	releaseall
	end
SlateportCity_Text_1DE940: @ 81DE940
	.string "“The ferry {REF}S.S. Tidal{END} nears\n"
	.string "completion for serving the ports of\l"
	.string "Slateport and Lilycove.”$"
SlateportCity_EventScript_1DCF66:: @ 81DCF66
	msgbox SlateportCity_Text_1DE9AA, MSGBOX_DEFAULT
	releaseall
	end
SlateportCity_Text_1DE9AA: @ 81DE9AA
	.string "“Boarding of the Slateport-Lilycove\n"
	.string "ferry {REF}S.S. Tidal{END} is handled at the\l"
	.string "Harbor.”$"


SlateportCity_SignScript_FanClub:: @ 81DCF70
	msgbox SlateportCity_Text_1DEA0B, MSGBOX_SIGN
	end
SlateportCity_Text_1DEA0B: @ 81DEA0B
	.string "{PLACE}Pokémon Fan Club{END}\n"
	.string "“Calling all fans of Pokémon!”$"


SlateportCity_SignScript_Museum:: @ 81DCF79
	msgbox SlateportCity_Text_1DEA3B, MSGBOX_SIGN
	end
SlateportCity_Text_1DEA3B: @ 81DEA3B
	.string "“The endless sea sustains\n"
	.string "all life.”\p"
	.string "{PLACE}Oceanic Museum{END}$"


SlateportCity_SignScript_CitySign:: @ 81DCF82
	msgbox SlateportCity_Text_1DEA6F, MSGBOX_SIGN
	end
SlateportCity_Text_1DEA6F: @ 81DEA6F
	.string "{PLACE}Slateport City{END}\p"
	.string "“The port where people and Pokémon\n"
	.string "cross paths.”$"


SlateportCity_SignScript_Market:: @ 81DCF8B
	msgbox SlateportCity_Text_1DEAAF, MSGBOX_SIGN
	end
SlateportCity_Text_1DEAAF: @ 81DEAAF
	.string "{PLACE}Slateport Market{END}\n"
	.string "“Unique items found nowhere else!”$"


SlateportCity_SignScript_Habor:: @ 81DCF94
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_1DCFA8
	msgbox SlateportCity_Text_1DEAE3, MSGBOX_SIGN
	releaseall
	end
SlateportCity_Text_1DEAE3: @ 81DEAE3
	.string "{PLACE}Slateport Harbor{END}\p"
	.string "“The ferry S.S. Tidal is under\n"
	.string "construction in the SHIPYARD.\p"
	.string "“Service is scheduled to begin\n"
	.string "shortly.”$"
SlateportCity_EventScript_1DCFA8:: @ 81DCFA8
	msgbox SlateportCity_Text_1DEB5A, MSGBOX_SIGN
	releaseall
	end
SlateportCity_Text_1DEB5A: @ 81DEB5A
	.string "{PLACE}Slateport Harbor{END}\p"
	.string "“Enjoy a delightful cruise on\n"
	.string "the ferry S.S. Tidal.”$"


SlateportCity_SignScript_NameRater:: @ 81DCFB2
	msgbox SlateportCity_Text_NameRater1, MSGBOX_SIGN
	msgbox SlateportCity_Text_NameRater2, MSGBOX_DESCRIBE
	end
SlateportCity_Text_NameRater1: @ 81DEBA0
	.string "{PLACE}Name Rater's House{END}\n"
	.string "“Pokémon nicknames rated.”$"
SlateportCity_Text_NameRater2: @ 81DEBA0
	.string "Someone used a blue marker to add the\n"
	.string "word {COLOR BLUE}“condescendingly”{END} to the end.$"


@ -----------------------------------------------------
@ People

SlateportCity_EventScript_EnergyGuru:: @ 81DCDBD
	lock
	faceplayer
	markasdialog
	message SlateportCity_Text_1DD64A
	waitmessage
	pokemart SlateportCity_Pokemart_1DCDD4
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end
SlateportCity_Text_1DD64A: @ 81DD64A
	.string "I'm the Energy Guru! I'll go for it and\n"
	.string "sell you what you need!$"
SlateportCity_Pokemart_1DCDD4: @ 81DCDD4
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end


SlateportCity_EventScript_EffortRibbonWoman:: @ 81DCDE4
	lock
	faceplayer
	markasdialog
	bufferleadmonspeciesname 0
	msgbox SlateportCity_Text_1DD68A, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	compare VAR_RESULT, 1
	call_if_eq SlateportCity_EventScript_1DCE38
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	compare VAR_RESULT, 0
	call_if_eq SlateportCity_EventScript_1DCE2E
	msgbox SlateportCity_Text_1DD697, MSGBOX_DEFAULT
	playfanfare MUS_FANFA4
	message SlateportCity_Text_1DD6E3
	waitfanfare
	msgbox SlateportCity_Text_1DD702, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end
SlateportCity_Text_1DD68A: @ 81DD68A
	.string "Oh?\n"
	.string "Your {STR_VAR_1}…$"
SlateportCity_Text_1DD697: @ 81DD697
	.string "Went for it stupendously!\p"
	.string "As its reward, please give it this\n"
	.string "{REF}Effort Ribbon{END}.$"
SlateportCity_Text_1DD6E3: @ 81DD6E3
	.string "{PLAYER} received the Effort Ribbon.$"
SlateportCity_Text_1DD702: @ 81DD702
	.string "{PLAYER} put the Effort Ribbon\n"
	.string "on {STR_VAR_1}.$"
SlateportCity_EventScript_1DCE38:: @ 81DCE38
	msgbox SlateportCity_Text_1DD77B, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DD77B: @ 81DD77B
	.string "Oh! Your {STR_VAR_1}, that EFFORT\n"
	.string "RIBBON looks good on it!$"
SlateportCity_EventScript_1DCE2E:: @ 81DCE2E
	msgbox SlateportCity_Text_1DD722, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DD722: @ 81DD722
	.string "You have to go for it a little harder.\p"
	.string "If you do, I'll give your Pokémon\n"
	.string "something nice.$"


SlateportCity_EventScript_Chef:: @ 81DCE42
	lock
	faceplayer
	markasdialog
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCE59
	msgbox SlateportCity_Text_1DD81A, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DD81A: @ 81DD81A
	.string "Ooh, look at this!\p"
	.string "The seaweed you can get around these\n"
	.string "parts is fresh and full of life.\p"
	.string "Why, it looks like it can even rear up\n"
	.string "and attack!$"
SlateportCity_EventScript_1DCE59:: @ 81DCE59
	msgbox SlateportCity_Text_1DE3E2, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DE3E2: @ 81DE3E2
	.string "What's going on here?\p"
	.string "Did the good Captain come back with\n"
	.string "a big fish from the ocean floor?$"


SlateportCity_EventScript_OldWoman:: @ 81DCE63
	lock
	faceplayer
	markasdialog
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCE7A
	msgbox SlateportCity_Text_1DD8A6, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DD8A6: @ 81DD8A6
	.string "Where the water is clean, the fruits\n"
	.string "of bountiful harvest gather.\p"
	.string "And where people gather, a market\n"
	.string "soon starts.\p"
	.string "That is how a town is born and grows.$"
SlateportCity_EventScript_1DCE7A:: @ 81DCE7A
	msgbox SlateportCity_Text_1DE28E, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DE28E: @ 81DE28E
	.string "I was hoping that it was a famous star\n"
	.string "so I could get an autograph.\p"
	.string "But who's that being interviewed?\n"
	.string "Isn't that Capt. Stern?$"


SlateportCity_EventScript_MarketGirl:: @ 81DCE84
	lock
	faceplayer
	markasdialog
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCEA4
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_1DCEAE
	msgbox SlateportCity_Text_1DD93D, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DD93D: @ 81DD93D
	.string "Shopping where you can breathe the\n"
	.string "scent of the ocean…\p"
	.string "Slateport is such a wonderful place!$"
SlateportCity_EventScript_1DCEA4:: @ 81DCEA4
	msgbox SlateportCity_Text_1DE30C, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DE30C: @ 81DE30C
	.string "That lady interviewer is so cool\n"
	.string "and pretty.\p"
	.string "When I grow up, I'm going to be\n"
	.string "an international journalist!$"
SlateportCity_EventScript_1DCEAE:: @ 81DCEAE
	msgbox SlateportCity_Text_1DD999, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DD999: @ 81DD999
	.string "If you put dolls or cushions on\n"
	.string "the floor, they'll get dirty.\p"
	.string "I'm going to buy some BRICKS so my\n"
	.string "dolls and cushions won't get dirty\l"
	.string "when I leave them out.$"


SlateportCity_EventScript_TentGuy:: @ 81DCEB8
	lock
	faceplayer
	markasdialog
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCECF
	msgbox SlateportCity_Text_1DDA34, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DDA34: @ 81DDA34
	.string "Wroooar! I'm going to compete in\n"
	.string "the {POKEMON} Contests, too!\p"
	.string "But before that, I need to catch\n"
	.string "some Pokémon!$"
SlateportCity_EventScript_1DCECF:: @ 81DCECF
	msgbox SlateportCity_Text_1DE376, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DE376: @ 81DE376
	.string "Capt. Stern says they discovered\n"
	.string "something at the bottom of the sea.\p"
	.string "I wonder what it is?\n"
	.string "What could it be?$"


SlateportCity_EventScript_FatMan:: @ 81DCED9
	compare VAR_SLATEPORT_STATE, 1
	goto_if_eq SlateportCity_EventScript_1DCEED
	msgbox SlateportCity_Text_1DDA9A, MSGBOX_NPC
	end
SlateportCity_Text_1DDA9A: @ 81DDA9A
	.string "Whew… I'm just bushed…\p"
	.string "I hiked over from Mauville City.\n"
	.string "But, boy, this city's huge.\p"
	.string "If I'd known this, I would've ridden\n"
	.string "my bike here.$"
SlateportCity_EventScript_1DCEED:: @ 81DCEED
	msgbox SlateportCity_Text_1DE43D, MSGBOX_DIALOG
	end
SlateportCity_Text_1DE43D: @ 81DE43D
	.string "Hey! Are you watching?\n"
	.string "Am I on TV?$"


SlateportCity_EventScript_MuseumMan:: @ 81DCEF6
	lock
	faceplayer
	markasdialog
	compare VAR_SLATEPORT_STATE, 1
	call_if_eq SlateportCity_EventScript_1DCF0D
	msgbox SlateportCity_Text_1DDB21, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DDB21: @ 81DDB21
	.string "Stern, the fellow who built the\n"
	.string "Museum, also happens to be the leader\l"
	.string "of an undersea exploration team.\p"
	.string "So, everyone calls him Capt. Stern.$"
SlateportCity_EventScript_1DCF0D:: @ 81DCF0D
	msgbox SlateportCity_Text_1DE460, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DE460: @ 81DE460
	.string "A TV interview! Here!\n"
	.string "The Captain's a celebrity!$"


SlateportCity_EventScript_MuseumWoman:: @ 81DCF17
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA, SlateportCity_EventScript_1DCF2C
	msgbox SlateportCity_Text_1DDBAC, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DDBAC: @ 81DDBAC
	.string "What is with the long line?\n"
	.string "It's never this busy…$"
SlateportCity_EventScript_1DCF2C:: @ 81DCF2C
	msgbox SlateportCity_Text_1DDBD5, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_1DDBD5: @ 81DDBD5
	.string "When I was a child, I visited\n"
	.string "the Museum often.\p"
	.string "I used to dream about the mysteries of\n"
	.string "the sea after seeing the exhibits.$"



SlateportCity_EventScript_NameRaterGuy:: @ 81DCFBB
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_TEMP_5, SlateportCity_EventScript_NameRaterGuy2
	msgbox SlateportCity_Text_NameRaterGuy, MSGBOX_DEFAULT
	setflag FLAG_TEMP_5
	incrementgamestat GAME_STAT_NUM_NPCS_HARASSED
	release
	end
SlateportCity_EventScript_NameRaterGuy2:
	msgbox SlateportCity_Text_NameRaterGuy2, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_NameRaterGuy: @ 81DE10E
	.string "If you want to change your Pokémon's\n"
	.string "nickname, you'll have to get the Name\l"
	.string "Rater to help you.\p"
	.string "… … … What do you mean “Why”?\n"
	.string "Why wouldn't you want his help?$"
	.string "… … … … … … No, I didn't say you\n"
	.string "were incapable of naming your own…\p"
	.string "Look, I'm sorry I brought it up.\n" @fallthrough
SlateportCity_Text_NameRaterGuy2:
	.string "Go away. Leave me alone.$"


SlateportCity_EventScript_1DCFDC:: @ 81DCFDC
	msgbox SlateportCity_Text_1DE16C, MSGBOX_NPC
	end
SlateportCity_Text_1DE16C: @ 81DE16C
	.string "Any Pokémon you get in a trade,\n"
	.string "you can't change its nickname.\p"
	.string "The original trainer's love for that\n"
	.string "Pokémon is in the nickname.$"


SlateportCity_EventScript_1DCFE5:: @ 81DCFE5
	msgbox SlateportCity_Text_1DDFF7, MSGBOX_NPC
	end
SlateportCity_Text_1DDFF7: @ 81DDFF7
	.string "The sea is just so vast…\p"
	.string "Could the sea have been made by\n"
	.string "the tears shed by Pokémon?$"


SlateportCity_EventScript_1DCFEE:: @ 81DCFEE
	msgbox SlateportCity_Text_1DE04B, MSGBOX_NPC
	end
SlateportCity_Text_1DE04B: @ 81DE04B
	.string "Do you know what they do with old\n"
	.string "ships that become too creaky to sail?\p"
	.string "They sink them in the sea so they\n"
	.string "become habitats for Pokémon.$"


SlateportCity_EventScript_ShoppingWoman:: @ 81DCFF7
	msgbox SlateportCity_Text_1DE0D2, MSGBOX_NPC
	end
SlateportCity_Text_1DE0D2: @ 81DE0D2
	.string "Whenever I visit here, I get carried\n"
	.string "away and buy too much.$"


SlateportCity_EventScript_1DD000:: @ 81DD000
	msgbox SlateportCity_Text_1DE1EC, MSGBOX_NPC
	end
SlateportCity_Text_1DE1EC: @ 81DE1EC
	.string "Recently, a Battle Tent was built\n"
	.string "in Slateport.\p"
	.string "Gyms are fun, but the Battle Tent's\n"
	.string "awesome in its own way.\p"
	.string "You should go find tough Pokémon\n"
	.string "for the Battle Tent!$"


SlateportCity_EventScript_LighthouseMan:: @ 81DD365
	msgbox SlateportCity_Text_1DD7AD, MSGBOX_NPC
	end
SlateportCity_Text_1DD7AD: @ 81DD7AD
	.string "The light of the lighthouse reaches\n"
	.string "dozens of miles away.\p"
	.string "I wonder if it doesn't startle Pokémon\n"
	.string "in the sea.$"


SlateportCity_EventScript_DollShop:: @ 81DD16A
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end
	.align 2
SlateportCity_PokemartDecor_Dolls: @ 81DD184
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end


SlateportCity_EventScript_DecorShop1:: @ 81DD198
	lock
	faceplayer
	markasdialog
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_1DD18E
	message gText_Mart_Welcome
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_1DD1B8
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end
SlateportCity_EventScript_1DD18E:: @ 81DD18E
	msgbox SlateportCity_Text_SecretPower, MSGBOX_DEFAULT
	release
	end
SlateportCity_Text_SecretPower:
	.string "Do you know the TM Secret Power?\p"
	.string "Our group, we love the TM Secret\n"
	.string "Power.\p"
	.string "One of our members will give it to you.\n"
	.string "Come back and show me if you get it.\p"
	.string "We'll accept you as a member and sell\n"
	.string "you good stuff in secrecy.$"
.align 2
SlateportCity_PokemartDecor_1DD1B8: @ 81DD1B8
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_TMShop:: @ 81DD1D8
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	pokemart SlateportCity_Pokemart_1DD1F0
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end
	.align 2
SlateportCity_Pokemart_1DD1F0: @ 81DD1F0
	.2byte ITEM_TM10
	.2byte ITEM_TM43
	.2byte ITEM_NONE
	release
	end


SlateportCity_EventScript_DenyEntryResidential::
	msgbox SlateportCity_Text_DenyEntryResidential, MSGBOX_NPC
	end
SlateportCity_Text_DenyEntryResidential:
	.string "I'm sorry for blocking the way. There's\n"
	.string "so much stuff to move…\p"
	.string "You're not missing anything anyway.\n"
	.string "Down this street there's just a\l"
	.string "residential section of the city.$"



@ -----------------------------------------------------
@ Team Aqua Members

SlateportCity_EventScript_AquaMember1:: @ 81DD009
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDC4F, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDC4F: @ 81DDC4F
	.string "Hey, there! Quit pushing!\n"
	.string "This is the line, can't you see?$"


SlateportCity_EventScript_AquaMember2:: @ 81DD020
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDC8A, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDC8A: @ 81DDC8A
	.string "Team Aqua has a policy of\n"
	.string "assembling and dispersing at\l"
	.string "the operation site.$"


SlateportCity_EventScript_AquaMember3:: @ 81DD037
	lock
	msgbox SlateportCity_Text_1DDCD5, MSGBOX_DIALOG
	release
	end
SlateportCity_Text_1DDCD5: @ 81DDCD5
	.string "Grumble…\p"
	.string "I should've brought my Game Boy\n"
	.string "Advance so I wouldn't get bored in line…\p"
	.string "Grumble…$"
	@ .string "Our boss is brilliant.\p"
	@ .string "What would he want to do with\n"
	@ .string "a museum now?$"


SlateportCity_EventScript_AquaMember9:: @ 81DD04E
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDD18, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDD18: @ 81DDD18
	.string "What's the new scheme, I wonder?\p"
	.string "Our boss is scary when he's mad, so\n"
	.string "I'd better not screw things up…$"


SlateportCity_EventScript_AquaMember7:: @ 81DD07C
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDDC0, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDDC0: @ 81DDDC0
	.string "Hey, you there!\n"
	.string "Wanna help us again?$"


SlateportCity_EventScript_AquaMember10:: @ 81DD093
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDDDF, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDDDF: @ 81DDDDF
	.string "A long line, huh?\p"
	.string "It reminds me of the times I lined up to\n"
	.string "buy smash-hit games…$"


SlateportCity_EventScript_AquaMember11:: @ 81DD0AA
	lock
	faceplayer
	msgbox SlateportCity_Text_1DDE2F, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDE2F: @ 81DDE2F
	.string "Why are we even lining up and paying?\n"
	.string "We should just march in!$"


SlateportCity_EventScript_AquaMember5:: @ 81DD0C1
	lock
	faceplayer
	markasdialog
	playse SE_PIN
	applymovement THIS_EVENT, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox SlateportCity_Text_1DDE6E, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	delay 32
	applymovement THIS_EVENT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_1DDE86, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	delay 32
	msgbox SlateportCity_Text_1DDEB8, MSGBOX_DEFAULT
	closemessage
	applymovement THIS_EVENT, Common_Movement_FacePlayer
	waitmovement 0
	delay 32
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDE6E: @ 81DDE6E
	.string "What?\n"
	.string "Whaddya want?$"
SlateportCity_Text_1DDE86: @ 81DDE86
	.string "You wanna to read this sign, do ya?\n"
	.string "I'll read it for ya!$"
SlateportCity_Text_1DDEB8: @ 81DDEB8
	.string "Les'see…\p"
	.string "Err… I think it says som'ing like\n"
	.string "“the life in the sea is endless.”\p"
	.string "Yup, pretty sure tha's what\n"
	.string "it says.$"


SlateportCity_EventScript_AquaMember6:: @ 81DD153
	lock
	goto_if_set FLAG_TEMP_6, SlateportCity_EventScript_AquaMember6_Post
	faceplayer
	markasdialog
	message SlateportCity_Text_1DDF8D
	waitmessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_Angry
	applymovement THIS_EVENT, Common_Movement_AngryReaction
	selectpointer_ongender SlateportCity_Text_1DDF8D_Male, SlateportCity_Text_1DDF8D_Female
	msgbox_selected
	closemessage
	setflag FLAG_TEMP_6
	incrementgamestat GAME_STAT_NUM_NPCS_HARASSED
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDF8D: @ 81DDF8D
	.string "When this operation's over, I'll take\n"
	.string "you to a hot spring spa!\p"
	.string "What? N-No! I didn't mean you!\n"
	.string "That's what the boss said to us!\p"
	.string "Though…{PAUSE 20} Ya know…{PAUSE 20}\n"
	.string "If you wanted to…\p"
	.string "$"
SlateportCity_Text_1DDF8D_Male:
	.string "Hahaa! What?! No!! I'm not gay either!\n"
	.string "Hahahaha…! Hahaha…! Ha! Haha! … … …$"
SlateportCity_Text_1DDF8D_Female:
	.string "Ack! I'm sorry! I'm sorry!\n"
	.string "Don't hit me! I'm sorry!$"
SlateportCity_EventScript_AquaMember6_Post:
	msgbox SlateportCity_Text_1DDF8E, MSGBOX_DESCRIBE
	release
	end
SlateportCity_Text_1DDF8E:
	.string "He's red in the face, desperately\n"
	.string "trying not to look at you.$"

@ -----------------------------------------------------
@ Aqua Friends

SlateportCity_EventScript_AquaMember8:: @ 81DD065
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_SCENE_1, SlateportCity_EventScript_AquaMember8a
	selectpointer_clamp SlateportCity_TextArray_AquaGirl, VAR_AQUA_GIRL_FRIENDSHIP
	msgbox_selected
	closemessage
	setflag FLAG_SCENE_1
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	faceoriginaldir
	release
	end
.align 2
SlateportCity_TextArray_AquaGirl:
	.4byte SlateportCity_Text_AquaGirl1
	.4byte SlateportCity_Text_AquaGirl2
	.4byte 0
SlateportCity_Text_AquaGirl1:
	.string "Hey, aren't you that {PLAYER_girl} who helped\n"
	.string "us get the Devon Goods?\p"
	.string "I thought I recognized you. Didn't get\n"
	.string "the chance to say hi last time.\p"
	.string "My name's {AQUA_GIRL}. What's yours?\p"
	.string "{PLAYER}? Nice name.\p"
	.string "Any chance you wanna help us again?\n"
	.string "Not like we'll need it with all these\l"
	.string "people here. Like seriously.\p"
	.string "Hop in line when you're ready.$"
SlateportCity_Text_AquaGirl2:
	.string "{AQUA_GIRL}: Hey! It's {PLAYER}!\n"
	.string "How's it hanging, {PLAYER_gurl}?\l"
	.string "Do anything fun since Rustboro?\p"
	.string "Hey, you wanna help us again, actually?\n"
	.string "Not like we'll need it with all these\l"
	.string "people here. Like seriously.\p"
	.string "The boss wants something inside the\n"
	.string "museum. No one knows what, but if the\l"
	.string "boss wants our help, we help!\p"
	.string "Hop in line when you're ready.$"
SlateportCity_EventScript_AquaMember8a:
	msgbox SlateportCity_Text_1DDD7D, MSGBOX_NPC
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDD7D: @ 81DDD7D
	.string "Hop in line, if you want.\n"
	.string "We should be going in shortly.$"



SlateportCity_EventScript_AquaMember4:: @ 81DD14A
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_SCENE_0, SlateportCity_EventScript_AquaMember4a
	selectpointer_clamp SlateportCity_TextArray_AquaBoy, VAR_AQUA_BOY_FRIENDSHIP
	msgbox_selected
	closemessage
	setflag FLAG_SCENE_0
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	faceoriginaldir
	release
	end
.align 2
SlateportCity_TextArray_AquaBoy:
	.4byte SlateportCity_Text_AquaBoy1
	.4byte SlateportCity_Text_AquaBoy2
	.4byte 0
SlateportCity_Text_AquaBoy1:
	.string "Oh, you're that {PLAYER_boy} who helped us\n"
	.string "back in Rustboro. Didn't get a chance\l"
	.string "to introduce myself before.\p"
	.string "My name's {AQUA_BOY}.\p"
	.string "You're {PLAYER}, right?\n"
	.string "Sweet. See, I remembered!\p"
	.string "Hey, wanna help again? There's something\n"
	.string "the boss wants in the museum. No idea\l"
	.string "what it is, of course.\p"
	.string "If you wanna help, you can cut in\n"
	.string "behind me. When you're ready.$"
SlateportCity_Text_AquaBoy2: @ 81DDF32
	.string "{AQUA_BOY}: Hey! {PLAYER}!\n"
	.string "How's it going, {PLAYER_dude}?\p"
	.string "You managed to find us at just the\n"
	.string "right time again, didn't you?\p"
	.string "Wanna hop in with us? We're waiting to\n"
	.string "get into the museum. Something the\l"
	.string "boss wants is inside.\p"
	.string "Feel free to slide in behind me when,\n"
	.string "you're ready.$"
SlateportCity_EventScript_AquaMember4a:
	msgbox SlateportCity_Text_1DDF32, MSGBOX_NPC
	faceoriginaldir
	release
	end
SlateportCity_Text_1DDF32:
	.string "{AQUA_BOY}: Feel free to cut in line\n"
	.string "behind me. We should be going in soon.$"

@ -----------------------------------------------------
@ Cutscene: Entering the Museum

#define LID_BEHIND 31
#define LID_BOY 32

SlateportCity_TriggerScript_AquaLineFront::
	lockall
	@ !
	applymovement LID_BEHIND, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LID_BEHIND, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	markasdialog
	msgbox SlateportCity_Text_AquaLineFront1
	@ Check friendship and kick out if not friend
	compare VAR_AQUA_BOY_FRIENDSHIP, 0
	goto_if_eq SlateportCity_TriggerScript_AquaLineFront_Ejected
	@ Bailey butts in
	applymovement LID_BOY, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	markasdialog -6
	msgbox SlateportCity_Text_AquaLineFront2
	applymovement LID_BEHIND, Common_Movement_FaceUp
	waitmovement 0
	applymovement LID_BEHIND, Common_Movement_Angry
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox SlateportCity_Text_AquaLineFront3
	closemessage
	applymovement LID_BOY, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	goto SlateportCity_EventScript_AquaLineMove
	end
SlateportCity_Text_AquaLineFront1:
	.string "Oy! Donchya know howta\n"
	.string "queue properly?!\p"
	.string "Get to tha back with ya!$"
SlateportCity_Text_AquaLineFront2:
	.string "{AQUA_BOY}: Chill, dude, it's alright.\n"
	.string "{PLAYER_They}'s with us. {PLAYER_They} just hasn't gotten\l"
	.string "the uniform yet.$"
SlateportCity_Text_AquaLineFront3:
	.string "{AQUA_BOY}: Don't mind him. We're all\n"
	.string "going to the same place anyway.$"
SlateportCity_TriggerScript_AquaLineFront_Ejected:
	closemessage
	applymovement LID_BEHIND, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	releaseall
	end

#undef LID_BOY
#undef LID_BEHIND

SlateportCity_TriggerScript_AquaLineBack::
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SlateportCity_Movement_AquaLineBack_Camera
	waitmovement 0
	goto SlateportCity_EventScript_AquaLineMove
	@ special RemoveCameraObject
	end
SlateportCity_Movement_AquaLineBack_Camera:
	walk_diag_southeast
	walk_diag_southeast
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

#define LID_FRONT1 5
#define LID_FRONT2 18
#define LID_FRONT3 19

SlateportCity_EventScript_AquaLineMove:
	applymovement LID_FRONT1, SlateportCity_Movement_AquaLineMove_GoIn
	waitmovement 0
	playse SE_KAIDAN
	applymovement LID_FRONT2, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LID_FRONT3, Common_Movement_WalkRight1
	applymovement LID_FRONT2, SlateportCity_Movement_AquaLineMove_GoIn
	waitmovement 0
	setvar VAR_SLATEPORT_MUSEUM_HEIST_STATE, 1
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	setflag FLAG_HIDE_SLATEPORT_MUSEUM_POPULATION
	setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	warp MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_1F, 255, 10, 4
	waitstate
	releaseall
	end
SlateportCity_Movement_AquaLineMove_GoIn:
	walk_up
	set_invisible
	step_end


#undef LID_FRONT1
#undef LID_FRONT2
#undef LID_FRONT3

@ -----------------------------------------------------
@ Cutscene: Logan Post Museum

#define LID_LOGAN 35

SlateportCity_EventScript_LoganAfterMuseum:
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	special SpawnCameraObject
	@
	playse SE_KAIDAN
	setobjectxyperm LID_LOGAN, VAR_INTERACT_X, 26
	addobject LID_LOGAN
	delay 32
	playse SE_W233B
	applymovement LID_LOGAN, SlateportCity_Movement_LoganAfterMuseum_LoganShove
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_LoganAfterMuseum_PlayerShoved
	applymovement EVENT_OBJ_ID_CAMERA, Common_Movement_WalkDown1
	markasdialog
	@
	setvar VAR_0x800B, 0
	addvar_if_set FLAG_TATTLED_ON_LOGAN, VAR_0x800B, 1
	selectpointer_from VAR_0x800B, SlateportCity_Text_LoganAfterMuseum1, SlateportCity_Text_LoganAfterMuseum2
	msgbox_selected
	waitmovement EVENT_OBJ_ID_PLAYER
	waitmovement EVENT_OBJ_ID_CAMERA
	special RemoveCameraObject
	closemessage
	@
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_LoganAfterMuseum_PlayerWatch
	applymovement LID_LOGAN, SlateportCity_Movement_LoganAfterMuseum_LoganRunOff
	waitmovement 0
	removeobject LID_LOGAN
	setvar VAR_SLATEPORT_MUSEUM_HEIST_STATE, 4
	setvar VAR_LOGAN_STATE, 5
	releaseall
	end
.align 2
SlateportCity_TextTable_LoganAfterMuseum:
	.4byte SlateportCity_Text_LoganAfterMuseum1
	.4byte SlateportCity_Text_LoganAfterMuseum2
	.4byte 0
SlateportCity_Text_LoganAfterMuseum1:
	.string "{RIVAL_HERO}: What is your problem,\n"
	.string "you big stupid jerk?!\p"
	.string "You nearly got my {RIVAL_MON} killed!\p"
	.string "Go jump off a pier, jerk!$"
SlateportCity_Text_LoganAfterMuseum2:
	.string "{RIVAL_HERO}: What is your problem,\n"
	.string "you big stupid jerk?!\p"
	.string "First, you sic my mother on me after\n"
	.string "I specifically asked you not to!\p"
	.string "Then you nearly get my {RIVAL_MON} killed!\p"
	.string "Do you just hate me or something?!\n"
	.string "Go jump off a pier, jerk!$"

SlateportCity_Movement_LoganAfterMuseum_PlayerShoved:
	slide_down
	slide_down
	emote_exclamation_mark
	delay_16
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_down
	delay_8
	player_run_up
	step_end
SlateportCity_Movement_LoganAfterMuseum_LoganShove:
	delay_8
	walk_slow_down
	step_end

SlateportCity_Movement_LoganAfterMuseum_LoganRunOff:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
SlateportCity_Movement_LoganAfterMuseum_PlayerWatch:
	delay_8
	walk_in_place_fastest_left
	step_end

#undef LID_LOGAN

@ -----------------------------------------------------
@ Captain Stern Scene


SlateportCity_EventScript_Cameraman:: @ 81DD353
	msgbox SlateportCity_Text_1DE491, MSGBOX_DESCRIBE
	end
SlateportCity_Text_1DE491: @ 81DE491
	.string "Ty: Okay, Capt. Stern, a big smile\n"
	.string "for the camera!$"


SlateportCity_EventScript_Reporter:: @ 81DD35C
	msgbox SlateportCity_Text_1DE4C4, MSGBOX_DESCRIBE
	end
SlateportCity_Text_1DE4C4: @ 81DE4C4
	.string "Gabby: I see, I see. You've had a most\n"
	.string "invaluable experience…$"

SlateportCity_EventScript_CaptainStern:: @ 81DD1F8
	lockall
	@ Stern talking
	markasdialog 16
	msgbox SlateportCity_Text_1DE502
	@ Gabby
	markasdialog -6
	msgbox SlateportCity_Text_1DE54A
	closemessage
	@ Reporter walks away
	applymovement LID_REPORTER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	applymovement LID_CAMERAMAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 25
	applymovement LID_CAPT_STERN, SlateportCity_Movement_1DD33C
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD34A
	applymovement LID_REPORTER, SlateportCity_Movement_1DD319
	applymovement LID_CAMERAMAN, SlateportCity_Movement_1DD326
	waitmovement 0
	removeobject LID_REPORTER
	removeobject LID_CAMERAMAN
	@
	markasdialog 12
	msgbox SlateportCity_Text_1DE64F, MSGBOX_DEFAULT
	@ Archie on megaphone
	playbgm MUS_AQA_0, 0
	markasdialog -10
	msgbox SlateportCity_Text_1DE724, MSGBOX_DEFAULT
	@ Panic
	applymovement 6, Common_Movement_WalkInPlaceLeft
	applymovement 1, Common_Movement_WalkInPlaceLeft
	applymovement 7, SlateportCity_Movement_1DD309
	applymovement 3, Common_Movement_QuestionMark
	applymovement 2, SlateportCity_Movement_1DD311
	delay 20
	playse SE_PIN
	applymovement LID_CAPT_STERN, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement LID_CAPT_STERN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@
	markasdialog 12
	msgbox SlateportCity_Text_1DE860, MSGBOX_DEFAULT
	closemessage
	@ Go inside
	applymovement LID_CAPT_STERN, SlateportCity_Movement_1DD337
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_Movement_1DD344
	waitmovement 0
	removeobject LID_CAPT_STERN
	@ Prepare next screen in harbor
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_SUBMARINE_SHADOW
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_AQUA_GRUNT
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_ARCHIE
	setvar VAR_SLATEPORT_STATE, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 255, 11, 14
	waitstate
	releaseall
	end
SlateportCity_Text_1DE502: @ 81DE502
	.string "Capt. Stern: Yes, indeed. We intend to\n"
	.string "move ahead with our exploration.$"
SlateportCity_Text_1DE54A: @ 81DE54A
	.string "Gabby: That's wonderful, Capt. Stern!\n"
	.string "Thank you for taking the time from\l"
	.string "your busy schedule to talk to us.\p"
	.string "We hope we can interview you again\n"
	.string "with news of more discoveries!$"
SlateportCity_Text_1DE64F: @ 81DE64F
	.string "Capt. Stern: Augh! {P_PLAYER}!\n"
	.string "If you're here! That means the rest\l"
	.string "Team Aqua isn't too far behind!!$"
SlateportCity_Text_1DE724: @ 81DE724
	.string "Archie: Fufufu…\n"
	.string "That's right, Capt. Stern.\p"
	.string "We of Team Aqua will assume\n"
	.string "control of your submarine!\p"
	.string "Your objections are meaningless!\n"
	.string "We expect your total cooperation!\p"
	.string "Fufufu…\n"
	.string "Just watch and learn what Team\l"
	.string "Aqua has planned!$"
SlateportCity_Text_1DE860: @ 81DE860
	.string "Capt. Stern: It's from the harbor!\p"
	.string "The submarine!\n"
	.string "They're trying to take it!$"


SlateportCity_Movement_1DD33C: @ 81DD33C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	walk_in_place_fastest_down
	emote_exclamation_mark
	step_end
SlateportCity_Movement_1DD34A: @ 81DD34A
	delay_16
	delay_16
	walk_right
	walk_in_place_fastest_up
	step_end
SlateportCity_Movement_1DD319: @ 81DD319
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
SlateportCity_Movement_1DD326: @ 81DD326
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
SlateportCity_Movement_1DD309: @ 81DD309
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_fastest_right
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end
SlateportCity_Movement_1DD311: @ 81DD311
	emote_question_mark
	walk_in_place_fastest_up
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

SlateportCity_Movement_1DD334: @ 81DD334
	walk_down
	walk_in_place_fastest_up
	step_end

SlateportCity_Movement_1DD337: @ 81DD337
	walk_fast_right
	walk_fast_up
	walk_fast_up
	set_invisible
	step_end
SlateportCity_Movement_1DD344: @ 81DD344
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	walk_up
	step_end




@ -----------------------------------------------------
@ Powder Jar Lady

SlateportCity_EventScript_PowderJarLady:: @ 81DD36E
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_1DD39A
	msgbox SlateportCity_Text_1DEBCE
	giveitem_std ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_1DED27
	release
	end
SlateportCity_Text_1DEBCE: @ 81DEBCE
	.string "If a wild Pokémon gets hurt, it heals\n"
	.string "itself by chewing on berries.\p"
	.string "Did you know that?\p"
	.string "Somebody saw that and got the idea\n"
	.string "of making medicine from berries.\p"
	.string "Did you know that?\p"
	.string "To turn berries into medicine,\n"
	.string "they must be crushed into powder.\p"
	.string "Did you know that?\p"
	.string "You seem to have an interest\n"
	.string "in berries!\p"
	.string "I've got something good for someone\n"
	.string "like you.$"

SlateportCity_EventScript_1DD39A:: @ 81DD39A
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD3C0
	msgbox SlateportCity_Text_1DEE40
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_1DD3CA
	end
SlateportCity_Text_1DEE40: @ 81DEE40
	.string "Have you brought me some\n"
	.string "Berry Powder?$"

SlateportCity_EventScript_1DD3C0:: @ 81DD3C0
	msgbox SlateportCity_Text_1DED27
	release
	end
SlateportCity_Text_1DED27: @ 81DED27
	.string "I recently applied to have machines\n"
	.string "installed at Centers for crushing berries.\p"
	.string "The berry crush machines would be in\n"
	.string "the {PLACE}Trainer's Lounge{END} upstairs.\p"
	.string "Did you know?\p"
	.string "Could you make Berry Powder for\n"
	.string "me using those machines?\p"
	.string "Any day now, the Hoenn General Council\n"
	.string "will approve my petition.$"
	@ .string "I can make you all sorts of medicine\n"
	@ .string "if you bring me lots of Berry Powder.$"

SlateportCity_EventScript_1DD3CA:: @ 81DD3CA
	message SlateportCity_Text_1DEE67
	waitmessage
	setvar VAR_0x8004, 7
	special DisplaySpecialScriptChoiceList
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_1DD46E
	case 1, SlateportCity_EventScript_1DD482
	case 2, SlateportCity_EventScript_1DD496
	@ case 3, SlateportCity_EventScript_1DD4AA
	case 3, SlateportCity_EventScript_1DD4BE
	case 4, SlateportCity_EventScript_1DD4D2
	case 5, SlateportCity_EventScript_1DD4E6
	case 6, SlateportCity_EventScript_1DD4FA
	case 7, SlateportCity_EventScript_1DD50E
	case 8, SlateportCity_EventScript_1DD522
	case 9, SlateportCity_EventScript_1DD536
	case 10, SlateportCity_EventScript_1DD54A
	case 127, SlateportCity_EventScript_1DD54A
	end
SlateportCity_Text_1DEE67: @ 81DEE67
	.string "What would you like to exchange\n"
	.string "it with?$"

SlateportCity_EventScript_1DD46E:: @ 81DD46E
	bufferitemname 0, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, 30
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD482:: @ 81DD482
	bufferitemname 0, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, 31
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD496:: @ 81DD496
	bufferitemname 0, ITEM_HEAL_POWDER
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_1DD557
	end

@ SlateportCity_EventScript_1DD4AA:: @ 81DD4AA
@ 	bufferitemname 0, ITEM_REVIVAL_HERB
@ 	setvar VAR_0x8008, 33
@ 	setvar VAR_0x8009, 300
@ 	goto SlateportCity_EventScript_1DD557
@ 	end

SlateportCity_EventScript_1DD4BE:: @ 81DD4BE
	bufferitemname 0, ITEM_PROTEIN
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4D2:: @ 81DD4D2
	bufferitemname 0, ITEM_IRON
	setvar VAR_0x8008, 65
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4E6:: @ 81DD4E6
	bufferitemname 0, ITEM_CARBOS
	setvar VAR_0x8008, 66
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD4FA:: @ 81DD4FA
	bufferitemname 0, ITEM_CALCIUM
	setvar VAR_0x8008, 67
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD50E:: @ 81DD50E
	bufferitemname 0, ITEM_ZINC
	setvar VAR_0x8008, 70
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD522:: @ 81DD522
	bufferitemname 0, ITEM_HP_UP
	setvar VAR_0x8008, 63
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD536:: @ 81DD536
	bufferitemname 0, ITEM_PP_UP
	setvar VAR_0x8008, 69
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_1DD557
	end

SlateportCity_EventScript_1DD54A:: @ 81DD54A
	msgbox SlateportCity_Text_1DEFBC, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end
SlateportCity_Text_1DEFBC: @ 81DEFBC
	.string "Come back if you'd like to trade your\n"
	.string "Berry Powder for some medicine.\p"
	.string "I'm always running a bazaar here.\p"
	.string "Did you know?$"

SlateportCity_EventScript_1DD557:: @ 81DD557
	msgbox SlateportCity_Text_1DEE90, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD3CA
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD5CE
	giveitem_std VAR_0x8008
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_EventScript_1DD5C1
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_1DEEF7, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_EventScript_1DD3CA
	msgbox SlateportCity_Text_1DEF79, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end
SlateportCity_Text_1DEE90: @ 81DEE90
	.string "Okay, you want to exchange your\n"
	.string "Berry Powder for one {STR_VAR_1}?$"
SlateportCity_Text_1DEEF7: @ 81DEEF7
	.string "This is fine Berry Powder.\n"
	.string "It will make excellent medicine.\p"
	.string "Would you like to trade more of your\n"
	.string "Berry Powder for something else?$"
SlateportCity_Text_1DEF79: @ 81DEF79
	.string "Okay! When you get some more\n"
	.string "Berry Powder, bring it to me, please!$"

SlateportCity_EventScript_1DD5C1:: @ 81DD5C1
	msgbox gText_BagIsFull3, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_1DD5CE:: @ 81DD5CE
	msgbox SlateportCity_Text_1DEEC9, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_1DD3CA
	end
SlateportCity_Text_1DEEC9: @ 81DEEC9
	.string "Oh, dear. You don't have enough\n"
	.string "Berry Powder.$"






SlateportCity_EventScript_1DD643:: @ 81DD643
	lockall
	special sub_80224D0
	waitstate
	releaseall
	end







#undef LID_CAPT_STERN
#undef LID_REPORTER
#undef LID_CAMERAMAN
