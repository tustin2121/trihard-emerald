
PokemonCenter_2F_EventScript_Teala::
	lock
	faceplayer
	msgbox PokemonCenter_2F_Text_TealaGreeting, MSGBOX_DEFAULT @TODO
	release
	end
PokemonCenter_2F_Text_TealaGreeting:
	.string "Welcome to the Trainer's Lounge.\n"
	.string "My name is Teala; how may I help you?$"


PokemonCenter_2F_EventScript_OccupiedSign::
	msgbox PokemonCenter_2F_Text_OccupiedSign, MSGBOX_SIGN
	end
PokemonCenter_2F_Text_OccupiedSign:
	.string "Locked: Occupied.$"



PokemonCenter_2F_Text_TealaExplaination: @ "What is this place?"
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
	.string "posessions while sleeping with us.)$"

