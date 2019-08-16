MossdeepCity_PokemonCenter_2F_MapScripts:: @ 8222334
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_PokemonCenter_2F_MapScript2_276C3B
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_PokemonCenter_2F_MapScript2_276B6C
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_PokemonCenter_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

MossdeepCity_PokemonCenter_2F_EventScript_222349:: @ 8222349
	call OldaleTown_PokemonCenter_2F_EventScript_276EB7
	end

MossdeepCity_PokemonCenter_2F_EventScript_22234F:: @ 822234F
	call OldaleTown_PokemonCenter_2F_EventScript_2770B2
	end

MossdeepCity_PokemonCenter_2F_EventScript_222355:: @ 8222355
	call OldaleTown_PokemonCenter_2F_EventScript_2771DB
	end

MossdeepCity_PokemonCenter_2F_OnLoad:
	call_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MossdeepCity_PokemonCenter_2F_OnLoad_FixFlags
	call_if_set FLAG_BADGE08_GET, MossdeepCity_PokemonCenter_2F_OnLoad_FixFlags
	end
MossdeepCity_PokemonCenter_2F_OnLoad_FixFlags:
	setflag FLAG_HIDE_MOSSDEEP_CENTER_FORMER_TEAM_MEMBERS
	return
	

@ -----------------------------------------------------

MossdeepCity_PokemonCenter_2F_EventScript_22235B:: @ 822235B
	msgbox MossdeepCity_PokemonCenter_2F_Text_222364, MSGBOX_NPC
	end
MossdeepCity_PokemonCenter_2F_Text_222364: @ 8222364
	.string "If I win a whole lot of link battles\n"
	.string "and show everyone how good I am,\l"
	.string "I might get a fan following!$"


MossdeepCity_PokemonCenter_2F_EventScript_Cushion::
	msgbox PokemonCenter_2F_Text_OccupiedSign, MSGBOX_SIGN
	lock
	msgbox MossdeepCity_PokemonCenter_2F_Text_Cushion, MSGBOX_CDESCRIBE
	givedecoration_std DECOR_BALL_CUSHION
	removeobject THIS_EVENT
	release
	end
MossdeepCity_PokemonCenter_2F_Text_Cushion:
	.string "…is what a tag on the pillow says.\p"
	.string "Ah, well, yoink!$"



@ -----------------------------------------------------

MossdeepCity_PokemonCenter_2F_EventScript_AquaBoy::
	msgbox MossdeepCity_PokemonCenter_2F_Text_AquaBoy, MSGBOX_NPC
	end
MossdeepCity_PokemonCenter_2F_Text_AquaBoy:
	.string "{AQUA_BOY}: Hey, {PLAYER}!\n"
	.string "How's it hanging?\p"
	.string "We're still here, right?\n"
	.string "So things must be good!$"

MossdeepCity_PokemonCenter_2F_EventScript_AquaGirl::
	msgbox MossdeepCity_PokemonCenter_2F_Text_AquaGirl, MSGBOX_NPC
	end
MossdeepCity_PokemonCenter_2F_Text_AquaGirl:
	.string "{AQUA_GIRL}: The Center didn't have\n"
	.string "anything good to drink, so we're\l"
	.string "making do with what we can get.\p"
	.string "Turns out {AQUA_BOY} is a lightweight.\p"
	.string "Robby here hasn't touched his.\p"
	.string "You're free to join us if you like.$"

MossdeepCity_PokemonCenter_2F_EventScript_MagmaGuy::
	msgbox MossdeepCity_PokemonCenter_2F_Text_MagmaGuy, MSGBOX_NPC
	end
MossdeepCity_PokemonCenter_2F_Text_MagmaGuy:
	.string "Joining Team Magma was a mistake I'll\n"
	.string "never live down. But I'm gonna try to\l"
	.string "make things better.\p"
	.string "I just don't know how. Or if I'll\n"
	.string "even get the chance.$"


