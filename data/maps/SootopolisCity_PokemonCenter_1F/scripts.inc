
	.macro SootopolisCity_GotoIfNoWeather pointer:req
	compare VAR_SKY_PILLAR_STATE, 2
	goto_if_ge \pointer
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, \pointer
	.endm

@ -----------------------------------------------------

SootopolisCity_PokemonCenter_1F_MapScripts:: @ 82264F1
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_PokemonCenter_1F_MapScript1_277C30
	@ map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_PokemonCenter_1F_FrameTable
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition: @ 82264FC
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	goto_if_set FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS, Common_EventScript_NopEnd
	setweather_nodelay WEATHER_POWEROUT
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_POKEMON_CENTER_ALT
	@ Move people around
	setobjectxyperm 4, 6, 9
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 5, 4, 11
	setobjectmovementtype 5, MOVEMENT_TYPE_LOOK_AROUND
	setobjectxyperm 6, 7, 6
	setobjectmovementtype 6, MOVEMENT_TYPE_FACE_DOWN
	setobjectxyperm 8, 4, 6
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_DOWN
	SootopolisCity_GotoIfNoWeather Common_EventScript_NopEnd
	@ Move staff around
	setobjectmovementtype 1, MOVEMENT_TYPE_FACE_LEFT
	setobjectxyperm 2, 17, 10
	setobjectmovementtype 2, MOVEMENT_TYPE_WALK_DOWN_AND_UP
	setobjectxyperm 3, 9, 2
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_RIGHT
	end

SootopolisCity_PokemonCenter_1F_OnLoad:
	call_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_OnLoad_NoEscape
	@ Set up cot replacements for the 2nd floor
	setmetatile 3, 5, 0x324, 0
	setmetatile 3, 6, 0x325, 0
	setmetatile 3, 7, 0x327, 0
	setmetatile 4, 5, 0x324, 0
	setmetatile 4, 6, 0x325, 0
	setmetatile 4, 7, 0x327, 0
	setmetatile 5, 5, 0x324, 0
	setmetatile 5, 6, 0x326, 0
	setmetatile 5, 7, 0x327, 0
	setmetatile 7, 5, 0x234, 0
	setmetatile 7, 6, 0x226, 0
	goto_if_unset FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS, Common_EventScript_NopEnd
	setobjectxyperm 6, 8, 7
	end
SootopolisCity_PokemonCenter_1F_OnLoad_NoEscape:
	setflag FLAG_TEMP_1E
	end

@ -----------------------------------------------------

@ SootopolisCity_PokemonCenter_1F_FrameTable:
@ 	map_script_2 VAR_TEMP_1F, 0, SootopolisCity_PokemonCenter_1F_StartRain
@ 	.2byte 0

@ SootopolisCity_PokemonCenter_1F_StartRain:

@ 	setvar VAR_TEMP_1F, 1
@ 	end

@ -----------------------------------------------------

SootopolisCity_PokemonCenter_1F_NurseScript:: @ 8226500
	lock
	setvar VAR_0x800B, 1
	faceplayer
	setvar VAR_TEXTBOX_TYPE, MSGTYPE_DIALOG
	goto_if_set FLAG_TEMP_5, SootopolisCity_PokemonCenter_1F_NurseHealScript_Talk
	setyesnotext gYN_Sure, gYN_No
	msgbox SootopolisCity_PokemonCenter_1F_NurseScript_Text, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq SootopolisCity_PokemonCenter_1F_NurseHealScript_Heal
	goto SootopolisCity_PokemonCenter_1F_NurseHealScript_Talk
	end
SootopolisCity_PokemonCenter_1F_NurseScript_Text:
	.string "Oh, hello.\n"
	.string "The second floor is damaged.\p"
	.string "We can only offer cots.\n"
	.string "Would you like one?$"
SootopolisCity_PokemonCenter_1F_NurseHealScript_Heal:
	incrementgamestat GAME_STAT_USED_POKECENTER
	setflag FLAG_TEMP_5
	message PokemonCenter_1F_NurseText_NurseNowHealing
	waitmessage
	waitbuttonpress
	closemessage
	@ Walk towards escalator, fade screen
	fadescreen 5 @ FADE_TO_BLACK_NO_WINDOW
	setflag FLAG_DISABLE_FADE_INIT
	@ Heal while setting positions
	playfanfare MUS_ME_ASA
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown2
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
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	warpcustom MAP_SOOTOPOLIS_CITY_POKEMON_CENTER_1F, 255, VAR_INTERACT_X, VAR_INTERACT_Y @ FADE_FROM_BLACK_NO_WINDOW
	waitstate
	release
	end
SootopolisCity_PokemonCenter_1F_NurseHealScript_Talk:
	message SootopolisCity_PokemonCenter_1F_NurseText_Goodluck
	waitmessage
	waitbuttonpress
	release
	end
SootopolisCity_PokemonCenter_1F_NurseText_Goodluck:
	.string "Stay safe out there.$"



SootopolisCity_PokemonCenter_1F_FreePokeballCounter:: @ 8226500
	SootopolisCity_GotoIfNoWeather PokemonCenter_1F_EventScript_FreePokeballCounter
	msgbox SootopolisCity_PokemonCenter_1F_FreePokeballCounter_Text, MSGBOX_NPC
	end
SootopolisCity_PokemonCenter_1F_FreePokeballCounter_Text:
	.string "Are you alright, kid?\n"
	.string "It's a right mess out there.\p"
	.string "Stay inside where it's safer. Or,\n"
	.string "if you can, get out of the city!$"


SootopolisCity_PokemonCenter_1F_FreePokeballBox::
	lock
	SootopolisCity_GotoIfNoWeather Common_EventScript_ReleaseEnd
	goto_if_set FLAG_TEMP_1D, SootopolisCity_PokemonCenter_1F_FreePokeballBoxFlagged
	setyesnotext gYN_Sure, gYN_Nah
	msgbox SootopolisCity_PokemonCenter_1F_FreePokeballBox_Text, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_ReleaseEnd
	giveitem_std ITEM_POKE_BALL, 10
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_TEMP_1D
	release
	end
SootopolisCity_PokemonCenter_1F_FreePokeballBox_Text:
	.string "This box of free Poké Ball handouts\n"
	.string "should probably be behind the counter.\p"
	.string "Take a couple sets?$"
SootopolisCity_PokemonCenter_1F_FreePokeballBoxFlagged:
	msgbox SootopolisCity_PokemonCenter_1F_FreePokeballBox_Text2
	release
	end
SootopolisCity_PokemonCenter_1F_FreePokeballBox_Text2:
	.string "This box of free Poké Ball handouts\n"
	.string "should probably be behind the counter.$"


SootopolisCity_Mart_MartScript:: @ 8226795
	lock
	faceplayer
	markasdialog
	SootopolisCity_GotoIfNoWeather SootopolisCity_Mart_MartScript_Do
	message SootopolisCity_Mart_Text_PowerOut
	waitmessage
	waitbuttonpress
	release
	end
SootopolisCity_Mart_Text_PowerOut:
	.string "Oh, lord Arceus, we're all going to die!$"
SootopolisCity_Mart_MartScript_Do:
	message gText_Mart_Welcome
	waitmessage
	pokemart SootopolisCity_Mart_Pokemart_2267AC
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

.align 2
SootopolisCity_Mart_Pokemart_2267AC: @ 82267AC
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_MAX_ELIXIR
	@ .2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end


@ -----------------------------------------------------

SootopolisCity_PokemonCenter_1F_EventScript_Teala::
	msgbox SootopolisCity_PokemonCenter_1F_Text_Teala, MSGBOX_NPC
	release
	end
SootopolisCity_PokemonCenter_1F_Text_Teala:
	.string "The second floor is off limits, {PLAYER_sir}.\p"
	.string "The whole roof was caved in by the\n"
	.string "horrible weather. It's not safe.$"


SootopolisCity_PokemonCenter_1F_EventScript_PC::
	lock
	@ SootopolisCity_GotoIfNoWeather SootopolisCity_PokemonCenter_1F_EventScript_PCNoStorm
	goto_if_set FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS, SootopolisCity_PokemonCenter_1F_EventScript_PCNoStorm
	msgbox SootopolisCity_PokemonCenter_1F_Text_PC, MSGBOX_DESCRIBE
	release
	end
SootopolisCity_PokemonCenter_1F_Text_PC:
	.string "The center's power is out from the\n"
	.string "raging Pokémon outside.\p"
	.string "There's no way the PC is going to turn\n"
	.string "on in these conditions.$"
SootopolisCity_PokemonCenter_1F_EventScript_PCNoStorm:
	msgbox SootopolisCity_PokemonCenter_1F_Text_PCNoStorm, MSGBOX_DESCRIBE
	release
	end
SootopolisCity_PokemonCenter_1F_Text_PCNoStorm:
	.string "The PC keeps booting, and then flashing\n"
	.string "a blue screen before rebooting again.$"



SootopolisCity_PokemonCenter_1F_EventScript_WallaceGentleman:: @ 822650E
	lock
	faceplayer
	SootopolisCity_GotoIfNoWeather SootopolisCity_PokemonCenter_1F_EventScript_22652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_22664B, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_22664B: @ 822664B
	.string "Everyone in town has taken refuge\n"
	.string "and won't come out of their homes.\p"
	.string "Even I would rather not venture\n"
	.string "outside.$"
SootopolisCity_PokemonCenter_1F_EventScript_22652E:: @ 822652E
	msgbox SootopolisCity_PokemonCenter_1F_Text_226562, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_226562: @ 8226562
	.string "Wallace is rumored to be the toughest\n"
	.string "trainer in the whole Hoenn region.\p"
	.string "This town's Gym is led by the trainer\n"
	.string "who taught Wallace.\p"
	.string "But the Elite Four… They're said to be\n"
	.string "even stronger than Wallace's mentor.\p"
	.string "How strong could they be?$"



SootopolisCity_PokemonCenter_1F_EventScript_FriendsWoman:: @ 8226538
	lock
	faceplayer
	SootopolisCity_GotoIfNoWeather SootopolisCity_PokemonCenter_1F_EventScript_226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_22672F, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_22672F: @ 822672F
	.string "Aren't Pokémon our friends?\p"
	.string "Why are they going wild this way?$"
SootopolisCity_PokemonCenter_1F_EventScript_226558:: @ 8226558
	msgbox SootopolisCity_PokemonCenter_1F_Text_2266B9, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_2266B9: @ 82266B9
	.string "Whenever, wherever, and whatever\n"
	.string "happens, I will always be friends with\l"
	.string "Pokémon.\p"
	.string "Because it's fun to be with Pokémon!$"



SootopolisCity_Mart_EventScript_PPUpMan:: @ 82267C2
	lock
	faceplayer
	SootopolisCity_GotoIfNoWeather SootopolisCity_Mart_EventScript_2267E2
	msgbox SootopolisCity_Mart_Text_22685D, MSGBOX_DIALOG
	release
	end
SootopolisCity_Mart_Text_22685D: @ 822685D
	.string "What…\n"
	.string "What is happening?\p"
	.string "I really want to know, but it's too\n"
	.string "scary to go outside.$"
SootopolisCity_Mart_EventScript_2267E2:: @ 82267E2
	msgbox SootopolisCity_Mart_Text_226816, MSGBOX_DIALOG
	release
	end
SootopolisCity_Mart_Text_226816: @ 8226816
	.string "PP Up is great!\p"
	.string "It raises the Power Points, the PP,\n"
	.string "of a Pokémon move.\p"
	.string "… … … I see you smirking.\n"
	.string "Get your mind out of the gutter!$"



SootopolisCity_Mart_EventScript_FullRestoreMan:: @ 82267EC
	lock
	faceplayer
	SootopolisCity_GotoIfNoWeather SootopolisCity_Mart_EventScript_22680C
	msgbox SootopolisCity_Mart_Text_226928, MSGBOX_DIALOG
	release
	end
SootopolisCity_Mart_Text_226928: @ 8226928
	.string "This weather…\n"
	.string "Did something awaken?$"
SootopolisCity_Mart_EventScript_22680C:: @ 822680C
	msgbox SootopolisCity_Mart_Text_2268AF, MSGBOX_DIALOG
	release
	end
SootopolisCity_Mart_Text_2268AF: @ 82268AF
	.string "Do you know Full Restore?\p"
	.string "Full restoration of HP!\n"
	.string "Eradication of all status problems!\p"
	.string "It's truly an item of your dreams!$"



SootopolisCity_PokemonCenter_1F_EventScript_Youngster::
	SootopolisCity_GotoIfNoWeather SootopolisCity_PokemonCenter_1F_EventScript_YoungsterAfter
	msgbox SootopolisCity_PokemonCenter_1F_Text_Youngster, MSGTYPE_DIALOG
	end
SootopolisCity_PokemonCenter_1F_Text_Youngster:
	.string "It's okay… It's gonna be alright…\n"
	.string "Sniff… We're gonna be okay…$"
SootopolisCity_PokemonCenter_1F_EventScript_YoungsterAfter:
	msgbox SootopolisCity_PokemonCenter_1F_Text_YoungsterAfter, MSGTYPE_DIALOG
	end
SootopolisCity_PokemonCenter_1F_Text_YoungsterAfter:
	.string "It's okay now… It's alright…\n"
	.string "Don't cry… Sniff…$"



SootopolisCity_PokemonCenter_1F_EventScript_LittleGirl::
	SootopolisCity_GotoIfNoWeather SootopolisCity_PokemonCenter_1F_EventScript_LittleGirlAfter
	msgbox SootopolisCity_PokemonCenter_1F_Text_LittleGirl, MSGTYPE_DIALOG
	end
SootopolisCity_PokemonCenter_1F_Text_LittleGirl:
	.string "Johnny… I'm scared… Make it stop…$"
SootopolisCity_PokemonCenter_1F_EventScript_LittleGirlAfter:
	msgbox SootopolisCity_PokemonCenter_1F_Text_LittleGirlAfter, MSGTYPE_DIALOG
	end
SootopolisCity_PokemonCenter_1F_Text_LittleGirlAfter:
	.string "Johnny…? Is… Is it over…?$"



@ -----------------------------------------------------
@ Move Tutor

SootopolisCity_PokemonCenter_1F_EventScript_MoveTutor:: @ 82C8256
	lock
	faceplayer
	SootopolisCity_GotoIfNoWeather SootopolisCity_PokemonCenter_1F_EventScript_MoveTutor2
	msgbox SootopolisCity_PokemonCenter_1F_Text_MoveTutorScared, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_MoveTutorScared:
	.string "AAAHHH!!\p"
	.string "I hope Wallace is alright in this\n"
	.string "terrible weather!$"

SootopolisCity_PokemonCenter_1F_EventScript_MoveTutor2:
	goto_if_set FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE, SootopolisCity_PokemonCenter_1F_EventScript_2C82B4
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7B8E, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	call SootopolisCity_PokemonCenter_1F_EventScript_2C832D
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7C98, MSGBOX_CDIALOG
	setvar VAR_0x8005, 4
	call EventScript_ShowPartyMenu
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_PokemonCenter_1F_EventScript_2C82AA
	setflag FLAG_MOVE_TUTOR_TAUGHT_DOUBLE_EDGE
	goto SootopolisCity_PokemonCenter_1F_EventScript_2C82B4
	end
SootopolisCity_PokemonCenter_1F_Text_2C7B8E: @ 82C7B8E
	.string "Sigh…\p"
	.string "Sootopolis's Gym Leader is really\n"
	.string "lovably admirable.\p"
	.string "But that also means I have many\n"
	.string "rivals for his attention.\p"
	.string "He's got appeal with a Double-Edge.\n"
	.string "I couldn't even catch his eye.\p"
	.string "Please, let me teach your Pokémon\n"
	.string "the move Double-Edge!$"
SootopolisCity_PokemonCenter_1F_Text_2C7C98: @ 82C7C98
	.string "Okay, which Pokémon should I teach\n"
	.string "Double-Edge?$"

SootopolisCity_PokemonCenter_1F_EventScript_2C82AA:: @ 82C82AA
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7C7E, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_2C7C7E: @ 82C7C7E
	.string "Oh…\n"
	.string "Even you rejected me…$"

SootopolisCity_PokemonCenter_1F_EventScript_2C82B4:: @ 82C82B4
	msgbox SootopolisCity_PokemonCenter_1F_Text_2C7CC8, MSGBOX_DIALOG
	release
	end
SootopolisCity_PokemonCenter_1F_Text_2C7CC8: @ 82C7CC8
	.string "I won't live for love anymore!\n"
	.string "I'll become tough!$"
