SlateportCity_SternsShipyard_1F_MapScripts:: @ 8207F3F
	.byte 0

@ -----------------------------------------------------

SlateportCity_SternsShipyard_1F_EventScript_207F40:: @ 8207F40
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_207F92
	@ goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_207FA6
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_207FD9
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_207FBA
	msgbox SlateportCity_SternsShipyard_1F_Text_208008, MSGBOX_DEFAULT
	faceplayer
	msgbox SlateportCity_SternsShipyard_1F_Text_2080A5, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	@ setflag FLAG_HIDE_SLATEPORT_CITY_TEAM_AQUA
	releaseall
	end
SlateportCity_SternsShipyard_1F_Text_208008: @ 8208008
	.string "Umm… If this goes here, and that\n"
	.string "goes over there…\p"
	.string "Then where does this thing go?\n"
	.string "And what about that doohickey?\p"
	.string "Aaargh! I can't make heads or tails\n"
	.string "of this!$"
SlateportCity_SternsShipyard_1F_Text_2080A5: @ 82080A5
	.string "Hm?\n"
	.string "Who are you?\p"
	.string "(Oh, those look like gang colors… Um…)\p"
	.string "I'm sorry, we don't allow… your kind\n"
	.string "on these premises. Please leave.$"
SlateportCity_SternsShipyard_1F_EventScript_207F92:: @ 8207F92
	faceplayer
	msgbox SlateportCity_SternsShipyard_1F_Text_208323, MSGBOX_DEFAULT
	releaseall
	end
SlateportCity_SternsShipyard_1F_Text_208323: @ 8208323
	.string "Dock: The ferry is finally ready!\p"
	.string "The new S.S. Tidal is truly a marvel\n"
	.string "of technology!\p"
	.string "But, I get the feeling that we can\n"
	.string "make something even better.\p"
	.string "You know, there's never an end to\n"
	.string "technology's march.$"
SlateportCity_SternsShipyard_1F_EventScript_207FBA:: @ 8207FBA
	faceplayer
	msgbox SlateportCity_SternsShipyard_1F_Text_2081A5, MSGBOX_DEFAULT
	closemessage
	faceoriginaldir
	releaseall
	end
SlateportCity_SternsShipyard_1F_Text_2081A5: @ 82081A5
	.string "Please leave, before I have to call\n"
	.string "the police.\p"
	.string "(Oh, I hate confrontation…)$"
SlateportCity_SternsShipyard_1F_EventScript_207FD9:: @ 8207FD9
	faceplayer
	msgbox SlateportCity_SternsShipyard_1F_Text_208213, MSGBOX_DEFAULT
	releaseall
	end
SlateportCity_SternsShipyard_1F_Text_208213: @ 8208213
	.string "Why are you here again?\p"
	.string "Oh no, now you're sporting Team Aqua's\n"
	.string "colors! I'm definitely calling the\l"
	.string "police now!\p"
	.string "(Once I work up the courage…)$"


SlateportCity_SternsShipyard_1F_EventScript_207FED:: @ 8207FED
	msgbox SlateportCity_SternsShipyard_1F_Text_208558, MSGBOX_NPC
	end
SlateportCity_SternsShipyard_1F_Text_208558: @ 8208558
	.string "The seasons, the weather, where\n"
	.string "the moon sits in the sky…\p"
	.string "These and other conditions make\n"
	.string "the sea change its expression.\p"
	.string "That's right!\n"
	.string "The sea is like a living thing!$"


SlateportCity_SternsShipyard_1F_EventScript_207FF6:: @ 8207FF6
	msgbox SlateportCity_SternsShipyard_1F_Text_2085FF, MSGBOX_NPC
	end
SlateportCity_SternsShipyard_1F_Text_2085FF: @ 82085FF
	.string "I get seasick real easily.\n"
	.string "So I get to help out here instead.$"


SlateportCity_SternsShipyard_1F_EventScript_207FFF:: @ 8207FFF
	msgbox SlateportCity_SternsShipyard_1F_Text_2083EE, MSGBOX_NPC
	end
SlateportCity_SternsShipyard_1F_Text_2083EE: @ 82083EE
	.string "Mr. Briney: Ah, {PLAYER}!\n"
	.string "It's been too long!\p"
	.string "Aye, since I met you, this old sea dog's\n"
	.string "been feeling frisky!\p"
	.string "So I've decided to help Dock make\n"
	.string "a ferry.\p"
	.string "Aye, after all, a ferry would be able\n"
	.string "to carry a lot of people.\p"
	.string "But, you know, that Dock is really\n"
	.string "something special.\p"
	.string "With his knack for technology and\n"
	.string "my experience, I'm sure that we can\l"
	.string "build one great ship, aye!$"

