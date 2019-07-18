MossdeepCity_MapScripts:: @ 81E4A96
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_MapTable
	.byte 0

MossdeepCity_OnTransition: @ 81E4A9C
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeatherAlternating
	compare VAR_MOSSDEEP_STATE, 0
	call_if_eq MossdeepCity_EventScript_UpdateInvasionFlags
	end

MossdeepCity_EventScript_MarkCityVisited:: @ 81E4B38
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_UpdateInvasionFlags:
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	return

MossdeepCity_MapTable:
	@ map_script_2 VAR_LAST_WARP_ID, 8, MossdeepCity_MapTable_StepMusicOn
	.2byte 0

@ MossdeepCity_MapTable_StepMusicOn:
@ 	compare VAR_MOSSDEEP_STATE, 2
@ 	goto_if_eq MossdeepCity_EventScript_MusicOn
@ 	end

@ -----------------------------------------------------
@ Sign

MossdeepCity_EventScript_1E4B1D:: @ 81E4B1D
	msgbox MossdeepCity_Text_1E53A9, MSGBOX_SIGN
	end
MossdeepCity_Text_1E53A9: @ 81E53A9
	.string "{GYM}Mossdeep City Pokémon Gym{END}\n"
	.string "{GYM}Leaders:{END} Liza & Tate\p"
	.string "“The mystic combination!”$"


MossdeepCity_EventScript_1E4B26:: @ 81E4B26
	msgbox MossdeepCity_Text_1E53F2, MSGBOX_SIGN
	end
MossdeepCity_Text_1E53F2: @ 81E53F2
	.string "{PLACE}Mossdeep City{END}\n"
	.string "“Our slogan: Cherish Pokémon!”$"


MossdeepCity_EventScript_1E4B2F:: @ 81E4B2F
	msgbox MossdeepCity_Text_1E541F, MSGBOX_SIGN
	end
MossdeepCity_Text_1E541F: @ 81E541F
	.string "{PLACE}Mossdeep Space Center{END}\n"
	.string "“The closest place to space.”$"

@ -----------------------------------------------------
@ People

MossdeepCity_EventScript_1E4AB2:: @ 81E4AB2
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM58, MossdeepCity_EventScript_1E4AC7
	msgbox MossdeepCity_Text_1E4E90, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4E90: @ 81E4E90
	.string "The island's {PLACE}Space Center{END} has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"
MossdeepCity_EventScript_1E4AC7:: @ 81E4AC7
	msgbox MossdeepCity_Text_1E4F15, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4F15: @ 81E4F15
	.string "The island's {PLACE}Space Center{END} has been\n"
	.string "launching huge rockets.$"


MossdeepCity_EventScript_1E4AD1:: @ 81E4AD1
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM58, MossdeepCity_EventScript_1E4AE6
	msgbox MossdeepCity_Text_1E4F50, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4F50: @ 81E4F50
	.string "I heard from a sailor buddy that\n"
	.string "Team Aqua set up shop in Lilycove.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But Mossdeep here's been targeted\n"
	.string "by that Team Magma.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the {PLACE}Space Center{END}.$"
MossdeepCity_EventScript_1E4AE6:: @ 81E4AE6
	msgbox MossdeepCity_Text_1E5051, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E5051: @ 81E5051
	.string "I'm a sailor, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"


MossdeepCity_EventScript_1E4AF0:: @ 81E4AF0
	msgbox MossdeepCity_Text_1E4E22, MSGBOX_NPC
	end
MossdeepCity_Text_1E4E22: @ 81E4E22
	.string "Around Mossdeep, you can see wild\n"
	.string "Wailmer.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "Wai, Wai, Wai…\p"
	.string "Wailmer watching!$"


MossdeepCity_EventScript_1E4AF9:: @ 81E4AF9
	msgbox MossdeepCity_Text_1E5135, MSGBOX_NPC
	end
MossdeepCity_Text_1E5135: @ 81E5135
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"


MossdeepCity_EventScript_1E4B02:: @ 81E4B02
	msgbox MossdeepCity_Text_1E50D9, MSGBOX_NPC
	end
MossdeepCity_Text_1E50D9: @ 81E50D9
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"


MossdeepCity_EventScript_1E4B0B:: @ 81E4B0B
	msgbox MossdeepCity_Text_1E529D, MSGBOX_NPC
	end
MossdeepCity_Text_1E529D: @ 81E529D
	.string "This rock has a special meaning to\n"
	.string "the people at the {PLACE}Space Center{END}.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"


MossdeepCity_EventScript_1E4B14:: @ 81E4B14
	msgbox MossdeepCity_Text_1E5396, MSGBOX_DESCRIBE
	end
MossdeepCity_Text_1E5396: @ 81E5396
	.string "It's a white rock.$"


MossdeepCity_EventScript_1E4C10:: @ 81E4C10
	lock
	faceplayer
	msgbox MossdeepCity_Text_1E5213, MSGBOX_DIALOG
	faceoriginaldir
	release
	end
MossdeepCity_Text_1E5213: @ 81E5213
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with Pokémon\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"


MossdeepCity_EventScript_1E4C26:: @ 81E4C26
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_1E4C68
	msgbox MossdeepCity_Text_1E4CED, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_EventScript_1E4C72
	msgbox MossdeepCity_Text_1E4D5B, MSGBOX_DEFAULT
	giveitem_std ITEM_KINGS_ROCK
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end
MossdeepCity_Text_1E4CED: @ 81E4CED
	.string "I got this from Steven, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called King's Rock.\n"
	.string "Do you want it?$"
MossdeepCity_Text_1E4D5B: @ 81E4D5B
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from Steven.$"
MossdeepCity_EventScript_1E4C68:: @ 81E4C68
	msgbox MossdeepCity_Text_1E4DB3, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4DB3: @ 81E4DB3
	.string "Steven's house is right over there!$"
MossdeepCity_EventScript_1E4C72:: @ 81E4C72
	msgbox MossdeepCity_Text_1E4DD7, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4DD7: @ 81E4DD7
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"


MossdeepCity_EventScript_1E4C7C:: @ 81E4C7C
	msgbox MossdeepCity_Text_1E5581, MSGBOX_NPC
	end
MossdeepCity_Text_1E5581: @ 81E5581
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city Sootopolis?\p"
	.string "I think the Gym there had a new\n"
	.string "Leader come in.\p"
	.string "People tell me the new Leader once\n"
	.string "mentored Wallace.$"

@ -----------------------------------------------------
@ State: Magma Invasion

MossdeepCity_EventScript_BlockingAqua::
	msgbox MossdeepCity_Text_BlockingAqua, MSGBOX_NPC
	end
MossdeepCity_Text_BlockingAqua:
	.string "Oh, hey! {AQUA_BOY} was looking for you!\p"
	.string "Magma decided to take over the Space\n"
	.string "Center for some reason.\l"
	.string "You should go find him to help!\p"
	.string "Me? I'm the undersea radio relay.\p"
	.string "The boss and them are in the sub\n"
	.string "looking for a cave or something?\p"
	.string "This is the only place on the island\n"
	.string "where I could get reception.$"


MossdeepCity_EventScript_FightingAqua1::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FightingAqua1, MSGBOX_DIALOG
	faceoriginaldir
	end
MossdeepCity_Text_FightingAqua1:
	.string "{AQUA_BOY} is inside! I'm holding off\n"
	.string "this one! Get in and help!$"


MossdeepCity_EventScript_FightingAqua2::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FightingAqua2, MSGBOX_DIALOG
	faceoriginaldir
	end
MossdeepCity_Text_FightingAqua2:
	.string "Magma struck at the perfect time,\n"
	.string "didn't they?\p"
	.string "Right when half our men are underwater\n"
	.string "searching for a cave!$"


MossdeepCity_EventScript_FightingMagma2::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FightingMagma2, MSGBOX_DIALOG
	faceoriginaldir
	end
MossdeepCity_Text_FightingMagma2:
	.string "Why must you people meddle in our\n"
	.string "affairs constantly?!$"


MossdeepCity_EventScript_MusicOn::
	playbgm MUS_MGM0, 0
	end

MossdeepCity_EventScript_MusicOff::
	fadedefaultbgm
	end


