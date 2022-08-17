FortreeCity_PokemonCenter_2F_MapScripts:: @ 821763E
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0



FortreeCity_PokemonCenter_2F_EventScript_GBKid::
	msgbox FortreeCity_PokemonCenter_2F_Text_GBKid, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceDown
	waitmovement THIS_EVENT
	end
FortreeCity_PokemonCenter_2F_Text_GBKid:
	.string "Gah! You distracted me! Now I gotta\n"
	.string "start this level over!\p"
	.string "Kazio Mario is really hard!$"


FortreeCity_PokemonCenter_2F_EventScript_LittleFan::
	msgbox FortreeCity_PokemonCenter_2F_Text_LittleFan, MSGBOX_DIALOG
	end
FortreeCity_PokemonCenter_2F_Text_LittleFan:
	.string "Winona! You're my favorite gym leader!\n"
	.string "I wanna grow up to be just like you!$"

FortreeCity_PokemonCenter_2F_EventScript_Winona::
	msgbox FortreeCity_PokemonCenter_2F_Text_Winona, MSGBOX_DIALOG
	end
FortreeCity_PokemonCenter_2F_Text_Winona:
	.string "Aww, you're so sweet! Now, where are\n"
	.string "your parents at?$"


RustboroCity_PokemonCenter_2F_EventScript_AbandonedBag::
	lock
	msgbox RustboroCity_PokemonCenter_2F_Text_AbandonedBag, MSGBOX_DEFAULT
	trysteal ITEM_PP_UP, 2, FLAG_ITEM_STOLEN_FORETREE_CENTER
	release
	end
RustboroCity_PokemonCenter_2F_Text_AbandonedBag:
	.string "Looks like someone left their bag\n"
	.string "behind…$"


FortreeCity_PokemonCenter_2F_EventScript_SickBoy::
	msgbox FortreeCity_PokemonCenter_2F_Text_SickBoy, MSGBOX_DIALOG
	end
FortreeCity_PokemonCenter_2F_Text_SickBoy:
	.string "Urgh… I feel terrible…$"

FortreeCity_PokemonCenter_2F_EventScript_Nurse::
	msgbox FortreeCity_PokemonCenter_2F_Text_Nurse, MSGBOX_NPC
	end
FortreeCity_PokemonCenter_2F_Text_Nurse:
	.string "We thought it might have been a case\n"
	.string "of Mankypox, but fortunately not.\p"
	.string "Which is good. I'd hate to have to\n"
	.string "shut down like Mauville had to.\p"
	@ .string "It's looking like a case of Mankypox…\n"
	@ .string "I don't know how it got to Hoenn.\p"
	.string "He shouldn't be contagious anymore,\n"
	.string "but you should leave, just in case.$"


