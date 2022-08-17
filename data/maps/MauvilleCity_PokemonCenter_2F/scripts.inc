MauvilleCity_PokemonCenter_2F_MapScripts:: @ 8211008
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_PokemonCenter_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_2F_OnTransition
	.byte 0

MauvilleCity_PokemonCenter_2F_OnLoad:
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, PokemonCenter_2F_SetupNormal
	call_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, PokemonCenter_2F_SetupQuarantine
	end

MauvilleCity_PokemonCenter_2F_OnTransition:
	@ call PokemonCenter_2F_OnTransition  @ This is causing problems. No Mystery Gift here!
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, Common_EventScript_NopEnd
	setmaplayoutindex LAYOUT_POKEMON_CENTER_2F
	end

@ -----------------------------------------------------

MauvilleCity_PokemonCenter_2F_EventScript_ClosedSign::
	msgbox MauvilleCity_PokemonCenter_2F_Text_ClosedSign, MSGBOX_SIGN
	end
MauvilleCity_PokemonCenter_2F_Text_ClosedSign:
	.string "Closed for deep cleaning.$"

@ -----------------------------------------------------
@ Quarantine

PokemonCenter_2F_SetupQuarantine:
	@ hide normal events
	clearflag FLAG_TEMP_10
	setflag FLAG_TEMP_11
	return


MauvilleCity_PokemonCenter_2F_EventScript_YoungsterQ::
	msgbox MauvilleCity_PokemonCenter_2F_Text_YoungsterQ, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_2F_Text_YoungsterQ:
	.string "There's a lot of medical people\n"
	.string "running around back there.\p"
	.string "What on earth is going on??$"

MauvilleCity_PokemonCenter_2F_EventScript_CamperQ::
	msgbox MauvilleCity_PokemonCenter_2F_Text_CamperQ, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_2F_Text_CamperQ:
	.string "The normal rooms are all closed off.\p"
	.string "So the nurses only have these cots\n"
	.string "for people to stay on.\p"
	.string "They're better than nothing, but leave\n"
	.string "something to be desired, privacy-wise.$"

MauvilleCity_PokemonCenter_2F_EventScript_LassQ::
	msgbox MauvilleCity_PokemonCenter_2F_Text_LassQ, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceRight
	waitmovement THIS_EVENT
	end
MauvilleCity_PokemonCenter_2F_Text_LassQ:
	.string "This whole thing has my poor\n"
	.string "Kirlia so spooked!$"
	
MauvilleCity_PokemonCenter_2F_EventScript_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, 4 @ question-like
	msgbox MauvilleCity_PokemonCenter_2F_Text_Kirlia, MSGBOX_DEFAULT
	waitmoncry
	applymovement THIS_EVENT, Common_Movement_FaceLeft
	waitmovement THIS_EVENT
	release
	end
MauvilleCity_PokemonCenter_2F_Text_Kirlia:
	.string "Kirlia: Prrri?$"


MauvilleCity_PokemonCenter_2F_EventScript_OfficerQ::
	msgbox MauvilleCity_PokemonCenter_2F_Text_OfficerQ, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_2F_Text_OfficerQ:
	.string "I'm sorry, {PLAYER_sir}, this area is\n"
	.string "currently under quarantine.\p"
	.string "I can't allow you through.$"

MauvilleCity_PokemonCenter_2F_EventScript_NurseQ::
	msgbox MauvilleCity_PokemonCenter_2F_Text_NurseQ, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceRight
	waitmovement THIS_EVENT
	end
MauvilleCity_PokemonCenter_2F_Text_NurseQ:
	.string "Uh, {PLAYER_sir}, I insist you stay back.\n"
	.string "This area is under quarantine.\p"
	.string "If you get any closer, you'll need to\n"
	.string "be locked down too.$"
	
@ -----------------------------------------------------
@ Normal Mode

PokemonCenter_2F_SetupNormal:
	@ hide quarantine events
	setflag FLAG_TEMP_10
	clearflag FLAG_TEMP_11
	return


MauvilleCity_PokemonCenter_2F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Youngster, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_2F_Text_Youngster:
	.string "I heard some of the medical people\n"
	.string "talking while they were packing up.\p"
	.string "Something called “Mankeypox”?\n"
	.string "I hope it's not serious.$"
	

MauvilleCity_PokemonCenter_2F_EventScript_Officer::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Officer, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_2F_Text_Officer:
	.string "Sigh…\p"
	.string "I need a vacation after that whole\n"
	.string "quarantine ordeal.\p"
	.string "Maybe the hazard pay will cover the\n"
	.string "cost of a trip down to Johto.\p"
	.string "Me and my partner have been meaning\n"
	.string "to visit his family down there.$"
	

MauvilleCity_PokemonCenter_2F_EventScript_Doctor::
	msgbox MauvilleCity_PokemonCenter_2F_Text_Doctor, MSGBOX_NPC
	end
MauvilleCity_PokemonCenter_2F_Text_Doctor:
	.string "I just don't understand how Mankypox\n"
	.string "could have gotten into Hoenn.\l"
	.string "Manky aren't native to Hoenn!$"


