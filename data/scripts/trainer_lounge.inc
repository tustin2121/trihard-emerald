
@ PokemonCenter_2F_EventScript_Teala::
@ 	lock
@ 	faceplayer
@ 	msgbox PokemonCenter_2F_Text_TealaGreeting, MSGBOX_DEFAULT @TODO
@ 	release
@ 	end
PokemonCenter_2F_Text_TealaGreeting:
	.string "Welcome to the Trainer's Lounge.\n"
	.string "My name is Teala; how may I help you?$"
PokemonCenter_2F_Text_TealaFarewell:
	.string "Have a good day.$"
@ PokemonCenter_2F_Text_TealaGreeting:
	@ .string "Welcome to the Trainer's Lounge.\p"
	@ .string "If you're looking to take a rest\n"
	@ .string "in one of our rooms, please talk\l"
	@ .string "to the receptionist downstairs.\p"
	@ .string "Otherwise feel free to rest and\n"
	@ .string "socialize with other trainers.$"
	@ "We offer refreshments at this counter"
	
PokemonCenter_2F_EventScript_Teala::
	lock
	faceplayer
	markasdialog
	message PokemonCenter_2F_Text_TealaGreeting
	waitmessage
	pokemart PokemonCenter_2F_TealaMart
	msgbox PokemonCenter_2F_Text_TealaFarewell, MSGBOX_DIALOG
	release
	end

	.align 2
PokemonCenter_2F_TealaMart: @ 8207D8C
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_NONE
	release
	end
	


PokemonCenter_2F_EventScript_OccupiedSign::
	msgbox PokemonCenter_2F_Text_OccupiedSign, MSGBOX_SIGN
	end
PokemonCenter_2F_Text_OccupiedSign:
	.string "Locked: Occupied.$"



PokemonCenter_2F_Text_TealaExplanation: @ "What is this place?"
	.string "This is the Trainer's Lounge.\p"
	.string "Trainers are free to come here and rest\n"
	.string "for a while. You can chat with other\l"
	.string "trainers hanging around or reserve a\n"
	.string "room to sleep and rest your team.\p"
	.string "If you want to reserve a room, please\n"
	.string "speak with the nurse downstairs.\p"
	.string "(We ask that you respect your fellow\n" 
	.string "trainers' personal space.\l"
	.string "Please refrain from battling while\n"
	.string "in the lounge or resting rooms.\l"
	.string "We are not liable for lost or stolen\n"
	.string "possessions while sleeping with us.)$"

