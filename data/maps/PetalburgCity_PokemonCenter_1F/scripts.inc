PetalburgCity_PokemonCenter_1F_MapScripts:: @ 82079E8
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_PokemonCenter_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PetalburgCity_PokemonCenter_1F_MapScript1_277C30
	.byte 0

PetalburgCity_PokemonCenter_1F_OnLoad:
	@ Set the PC to "On"
	setmetatile 3, 3, 0x5, 1
	return

PetalburgCity_PokemonCenter_1F_OnTransition: @ 82079F3
	setrespawn HEAL_LOCATION_PETALBURG_CITY
	call PokemonCenter_1F_SetMrBrineyLocation
	end

@ -----------------------------------------------------

PetalburgCity_PokemonCenter_1F_NurseScript:: @ 82079FC
	setvar VAR_0x800B, 1
	goto PokemonCenter_1F_NurseHealScript
	end


PetalburgCity_Mart_MartScript:: @ 8207D69
	lock
	faceplayer
	markasdialog
	message gText_Mart_Welcome
	waitmessage
	goto_if_set FLAG_PETALBURG_MART_EXPANDED_ITEMS, PetalburgCity_Mart_EventScript_207DA6
	pokemart PetalburgCity_Mart_Pokemart_207D8C
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_207D8C: @ 8207D8C
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

PetalburgCity_Mart_EventScript_207DA6:: @ 8207DA6
	pokemart PetalburgCity_Mart_Pokemart_207DB8
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end

	.align 2
PetalburgCity_Mart_Pokemart_207DB8: @ 8207DB8
	@ .2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_ORANGE_MAIL
	.2byte ITEM_NONE
	release
	end

@ -----------------------------------------------------

PetalburgCity_PokemonCenter_1F_PCGirl::
	lock
	markasdialog
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCGirl_Part1, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement THIS_EVENT, Common_Movement_ExclamationMark
	waitmovement 0
	faceplayer
	delay 30
	msgbox PetalburgCity_PokemonCenter_1F_Text_PCGirl_Part2, MSGBOX_DEFAULT
	applymovement THIS_EVENT, Common_Movement_FaceUp
	waitmovement 0
	release
	end
PetalburgCity_PokemonCenter_1F_Text_PCGirl_Part1:
	.string "Yes, Mom…\n"
	.string "No, Mom…\l"
	.string "Yes, Mom…$"
PetalburgCity_PokemonCenter_1F_Text_PCGirl_Part2:
	.string "Excuse me. Some privacy, please?$"



PetalburgCity_PokemonCenter_1F_EventScript_207A0A:: @ 8207A0A
	compare VAR_PETALBURG_STATE, 10
	goto_if_lt PetalburgCity_PokemonCenter_1F_EventScript_207A0B
	msgbox PetalburgCity_PokemonCenter_1F_Text_207A76, MSGBOX_NPC
	end
PetalburgCity_PokemonCenter_1F_Text_207A76: @ 8207A76
	.string "Roumor has it Malaqui was forcefully\n"
	.string "retired to a prison cell for his conduct\l"
	.string "in that tall grass incident.\p"
	.string "Good riddance, if you ask me.$"
PetalburgCity_PokemonCenter_1F_EventScript_207A0B:
	msgbox PetalburgCity_PokemonCenter_1F_Text_207A77, MSGBOX_NPC
	end
PetalburgCity_PokemonCenter_1F_Text_207A77:
	.string "That Malaqui is off his rocker!\n"
	.string "He should be disciplined for some of\l"
	.string "the stuff he puts trainers through!$"



PetalburgCity_PokemonCenter_1F_EventScript_OranBoy:: @ 8207A13
	msgbox PetalburgCity_PokemonCenter_1F_Text_207AD6, MSGBOX_NPC
	end
PetalburgCity_PokemonCenter_1F_Text_207AD6: @ 8207AD6
	.string "When my Pokémon ate an\n"
	.string "Oran Berry, it regained HP!$"



PetalburgCity_Mart_EventScript_207DD6:: @ 8207DD6
	msgbox PetalburgCity_Mart_Text_207DF1, MSGBOX_NPC
	end
PetalburgCity_Mart_Text_207DF1: @ 8207DF1
	.string "Even if a Pokémon is weak now,\n"
	.string "it will grow stronger.\p"
	.string "The most important thing is love!\n"
	.string "Love for your Pokémon!$"



PetalburgCity_Mart_EventScript_RepelBoy:: @ 8207DDF
	msgbox PetalburgCity_Mart_Text_207E60, MSGBOX_NPC
	end
PetalburgCity_Mart_Text_207E60: @ 8207E60
	.string "Do you use Repel?\n"
	.string "It keeps Pokémon away, so it's\l"
	.string "useful when you're in a hurry.$"



PetalburgCity_Mart_EventScript_AntidoteMan:: @ 8207DE8
	msgbox PetalburgCity_Mart_Text_207EB0, MSGBOX_NPC
	end
PetalburgCity_Mart_Text_207EB0: @ 8207EB0
	.string "Do you have any Antidotes with\n"
	.string "you?\p"
	.string "If your Pokémon gets poisoned, it will\n"
	.string "lose HP in battle until it dies!\l"
	.string "Take some Antidotes with you.$"



PetalburgCity_Mart_EventScript_LoganCousin:: @ 8207DE8
	msgbox PetalburgCity_Mart_Text_LoganCousin, MSGBOX_NPC
	end
PetalburgCity_Mart_Text_LoganCousin: @ 8207EB0
	.string "I'm pretty sure they've forgotten about\n"
	.string "me upstairs at this point.\p"
	.string "Which is fine by me. I can meet my\n"
	.string "boyfriend on the way back, without\l"
	.string "having to lie to Aunt Gretchen about\l"
	.string "who he is again.$"



@ -----------------------------------------------------

PetalburgCity_PokemonCenter_1F_EventScript_StarterLady:: @ 8207A1C
	lock
	faceplayer
	markasdialog
	msgbox PetalburgCity_PokemonCenter_1F_Text_207B09, MSGBOX_DEFAULT
	specialvar VAR_RESULT, IsStarterInParty
	compare VAR_RESULT, 1
	goto_if_eq PetalburgCity_PokemonCenter_1F_EventScript_207A38
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_207A38:: @ 8207A38
	compare VAR_STARTER_MON, 0
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_207A5B
	compare VAR_STARTER_MON, 1
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_207A64
	compare VAR_STARTER_MON, 2
	call_if_eq PetalburgCity_PokemonCenter_1F_EventScript_207A6D
	release
	end

PetalburgCity_PokemonCenter_1F_EventScript_207A5B:: @ 8207A5B
	msgbox PetalburgCity_PokemonCenter_1F_Text_207BB0, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_207A64:: @ 8207A64
	msgbox PetalburgCity_PokemonCenter_1F_Text_207C35, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_EventScript_207A6D:: @ 8207A6D
	msgbox PetalburgCity_PokemonCenter_1F_Text_207CB7, MSGBOX_DEFAULT
	return

PetalburgCity_PokemonCenter_1F_Text_207B09: @ 8207B09
	.string "There are many types of Pokémon.\p"
	.string "All types have their strengths and\n"
	.string "weaknesses against other types.\p"
	.string "Depending on the types of Pokémon,\n"
	.string "a battle could be easy or hard.$"

PetalburgCity_PokemonCenter_1F_Text_207BB0: @ 8207BB0
	.string "For example, your Treecko\n"
	.string "is a Grass type.\p"
	.string "It's strong against the Water and\n"
	.string "Ground types.\p"
	.string "But, it's weak against Fire-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_207C35: @ 8207C35
	.string "For example, your Torchic\n"
	.string "is a Fire type.\p"
	.string "It's strong against the Grass and\n"
	.string "Bug types.\p"
	.string "But, it's weak against Water-type\n"
	.string "Pokémon.$"

PetalburgCity_PokemonCenter_1F_Text_207CB7: @ 8207CB7
	.string "For example, your Mudkip\n"
	.string "is a Water type.\p"
	.string "It's strong against the Fire type.\p"
	.string "But, it's weak against Grass-type\n"
	.string "and Electric-type Pokémon.$"



@ Mystery Event boy is in mystery_event_club.inc
