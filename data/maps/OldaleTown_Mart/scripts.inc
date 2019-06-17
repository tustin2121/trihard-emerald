OldaleTown_Mart_MapScripts:: @ 81FC23F
	.byte 0

@ -----------------------------------------------------

OldaleTown_House3_EventScript_Youngster::
	msgbox OldaleTown_House3_Text_Youngster, MSGBOX_NPC
	end
OldaleTown_House3_Text_Youngster:
	.string "I hope that kid is alright…\n"
	.string "He looked really bad…$"


OldaleTown_House3_EventScript_LittleBoy::
	msgbox OldaleTown_House3_Text_LittleBoy, MSGBOX_NPC
	end
OldaleTown_House3_Text_LittleBoy:
	.string "Pokémon can be really dangerous.\p"
	.string "Mommy says never to go into the tall\n"
	.string "grass without a Pokémon of your own.$"


OldaleTown_House3_EventScript_Mother::
	goto_if_unset FLAG_ADVENTURE_STARTED, OldaleTown_House3_EventScript_Mother2
	msgbox OldaleTown_House3_Text_Mother, MSGBOX_NPC
	end
OldaleTown_House3_Text_Mother:
	.string "My boys aren't allowed outside anymore.\n"
	.string "It's too dangerous.$"
OldaleTown_House3_EventScript_Mother2:
	msgbox OldaleTown_House3_Text_Mother2, MSGBOX_NPC
	end
OldaleTown_House3_Text_Mother2:
	.string "My boys should be outside playing\n"
	.string "somewhere.\p"
	.string "I should call them in for dinner soon.$"

