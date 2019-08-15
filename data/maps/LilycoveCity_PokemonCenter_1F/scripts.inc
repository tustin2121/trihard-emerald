LilycoveCity_PokemonCenter_1F_MapScripts:: @ 821C5B2
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, LilycoveCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

@ FortreeCity_PokemonCenter_1F_OnLoad:
@ 	@ Set the PC to "On"
@ 	setmetatile 16, 5, 0x5, 1
@ 	return

LilycoveCity_PokemonCenter_1F_OnTransition: @ 821C5BD
	setrespawn HEAL_LOCATION_LILYCOVE_CITY
	goto LilycoveCity_PokemonCenter_1F_EventScript_21C5C6
	end

LilycoveCity_PokemonCenter_1F_FavorLady::
	markasdialog
	goto LilycoveCity_PokemonCenter_1F_EventScript_2A836B
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5C6:: @ 821C5C6
	special sub_818D9C0
	compare VAR_RESULT, 0
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_21C5E0
	compare VAR_RESULT, 1
	goto_if_eq LilycoveCity_PokemonCenter_1F_EventScript_21C5E4
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E0:: @ 821C5E0
	setflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY
	end

LilycoveCity_PokemonCenter_1F_EventScript_21C5E4:: @ 821C5E4
	clearflag FLAG_HIDE_LILYCOVE_POKEMON_CENTER_LADY
	end

@ -----------------------------------------------------

LilycoveCity_PokemonCenter_1F_NurseScript:: @ 821C5E8
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end

LilycoveCity_PokemonCenter_1F_LittleKidMartScript::
	lock
	faceplayer
	markasdialog
	checkplayergender
	compare VAR_RESULT, MALE
	call_if_eq LilycoveCity_PokemonCenter_1F_LittleKidMartScript_WelcomeM
	compare VAR_RESULT, FEMALE
	call_if_eq LilycoveCity_PokemonCenter_1F_LittleKidMartScript_WelcomeF
	waitmessage
	pokemart LilycoveCity_Mart_Pokemart
	msgbox LilycoveCity_PokemonCenter_1F_LittleKidMartText2, MSGBOX_DEFAULT
	release
	end
LilycoveCity_PokemonCenter_1F_LittleKidMartScript_WelcomeM:
	message LilycoveCity_PokemonCenter_1F_LittleKidMartText1M
	return
LilycoveCity_PokemonCenter_1F_LittleKidMartScript_WelcomeF:
	message LilycoveCity_PokemonCenter_1F_LittleKidMartText1F
	return
LilycoveCity_Mart_Pokemart: @ 8217680
	.2byte ITEM_LEMONADE
	.2byte ITEM_SODA_POP
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NONE
	release
	end

LilycoveCity_PokemonCenter_1F_LittleKidMartText1M:
	.string "Hiya! I'm selling Lemonade!\n"
	.string "Want some, mister?$"
LilycoveCity_PokemonCenter_1F_LittleKidMartText1F:
	.string "Hi, lady! I'm selling Lemonade!\n"
	.string "Wanna buy some?$"
LilycoveCity_PokemonCenter_1F_LittleKidMartText2:
	.string "{COLOR RED}Thank you{EMOJI_TILDE EMOJI_HEART}!{RESETCOLOR} Tell your friends!$"

@ -----------------------------------------------------

LilycoveCity_PokemonCenter_1F_PCMan::
	lock
	faceplayer
	markasdialog
	msgbox LilycoveCity_PokemonCenter_1F_PCMan_Text1, MSGBOX_DEFAULT
	closemessage
	applymovement THIS_EVENT, Common_Movement_FaceUp
	waitmovement 0
	delay 10
	special DoPCBangShakingEffect
	playse SE_W070
	waitstate
	delay 30
	msgbox LilycoveCity_PokemonCenter_1F_PCMan_Text3, MSGBOX_DEFAULT
	release
	end
LilycoveCity_PokemonCenter_1F_PCMan_Text1:
	.string "What do you kids do to these PCs?!\p"
	.string "I haven't seen one working PC in the\n"
	.string "entire region!$"
LilycoveCity_PokemonCenter_1F_PCMan_Text3:
	.string "Work, you stupid thing!$"


LilycoveCity_PokemonCenter_1F_EventScript_21C5F6:: @ 821C5F6
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C61E, MSGBOX_NPC
	end
LilycoveCity_PokemonCenter_1F_Text_21C61E: @ 821C61E
	.string "I wonder how many kinds of Pokémon\n"
	.string "there are in the world.\p"
	.string "It'd be great to cross seas and\n"
	.string "trade Pokémon with people far away.$"


LilycoveCity_PokemonCenter_1F_EventScript_MeteoriteManiac:: @ 821C5FF
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_PokemonCenter_1F_EventScript_21C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C69D, MSGBOX_DEFAULT
	release
	end
LilycoveCity_PokemonCenter_1F_EventScript_21C614:: @ 821C614
	msgbox LilycoveCity_PokemonCenter_1F_Text_21C6F6, MSGBOX_DEFAULT
	release
	end
LilycoveCity_PokemonCenter_1F_Text_21C69D: @ 821C69D
	.string "I've been hearing about some rotten\n"
	.string "scoundrels who steal Pokémon and rip\l"
	.string "off Meteorites.$"
LilycoveCity_PokemonCenter_1F_Text_21C6F6: @ 821C6F6
	.string "Those rotten scoundrels who steal\n"
	.string "Pokémon and rip off Meteorites…\p"
	.string "I haven't seen them around recently.$"


@ -----------------------------------------------------
@ Lilycove Lady: see data/scripts/lilycove_lady.inc
