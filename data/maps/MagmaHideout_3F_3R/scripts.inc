MagmaHideout_3F_3R_MapScripts:: @ 823ACFF
	.byte 0

@ -----------------------------------------------------

MagmaHideout_3F_3R_EventScript_AquaGirl::
	goto_if_set FLAG_SCENE_3, MagmaHideout_3F_3R_EventScript_AquaGirl2
	msgbox MagmaHideout_3F_3R_Text_AquaGirl, MSGBOX_NPC
	setflag FLAG_SCENE_3
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	end
MagmaHideout_3F_3R_Text_AquaGirl:
	.string "{AQUA_GIRL}: Oh, {P_PLAYER}. What have\n"
	.string "they released onto the world?!\p"
	.string "Did you see how big and powerful\n"
	.string "that Pokémon looked?!\p"
	.string "We have to tell the boss\n"
	.string "when we see him next!\p"
	.string "If we both try and do it, one of us\n"
	.string "will eventually, right?$"
MagmaHideout_3F_3R_EventScript_AquaGirl2::
	msgbox MagmaHideout_3F_3R_Text_AquaGirl2, MSGBOX_NPC
	end
MagmaHideout_3F_3R_Text_AquaGirl2:
	.string "{AQUA_GIRL}: We have to tell Archie,\n"
	.string "{PLAYER}. If you see him next, please\l"
	.string "tell him about that Groudon thing!$"


