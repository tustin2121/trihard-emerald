RustboroCity_Flat1_1F_MapScripts:: @ 82150CD
	map_script MAP_SCRIPT_ON_LOAD, RustboroCity_Flat1_1F_OnLoad
	.byte 0

RustboroCity_Flat1_1F_OnLoad:
	setflag FLAG_HIDE_RUSTBORO_CITY_DEVON_SCENE @quick fix for misplaced events
	end

RustboroCity_Flat1_1F_EventScript_2150CE:: @ 82150CE
	msgbox RustboroCity_Flat1_1F_Text_2150E0, MSGBOX_NPC
	end
RustboroCity_Flat1_1F_Text_2150E0: @ 82150E0
	.string "Every Pokémon has a special ability\n"
	.string "that it can use.$"

RustboroCity_Flat1_1F_EventScript_2150D7:: @ 82150D7
	msgbox RustboroCity_Flat1_1F_Text_215115, MSGBOX_NPC
	end
RustboroCity_Flat1_1F_Text_215115: @ 8215115
	.string "Pokémon are such strange creatures.$"

