MeteorFalls_1F_1R_MapScripts:: @ 822BD2A
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

@ -----------------------------------------------------

MeteorFalls_1F_1R_OnLoad: @ 822BD30
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_22BD3A
	end

MeteorFalls_1F_1R_EventScript_22BD3A:: @ 822BD3A
	setmetatile 4, 1, 582, 1
	setmetatile 3, 2, 589, 1
	setmetatile 4, 2, 590, 0
	setmetatile 5, 2, 591, 1
	return

@ -----------------------------------------------------

MeteorFalls_1F_1R_EventScript_Cosmo:: @ 822BF25
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_MET_PROF_COSMO, MeteorFalls_1F_1R_EventScript_22BF3D
	setflag FLAG_MET_PROF_COSMO
	msgbox MeteorFalls_1F_1R_Text_22C342, MSGBOX_DEFAULT
	release
	end
MeteorFalls_1F_1R_Text_22C342: @ 822C342
	.string "Augh! Don't hurt me!!\p"
	.string "Oh, everyone else is gone…\p"
	.string "M-My name is Prof. Cozmo…\p"
	.string "Team Magma asked me to guide them\n"
	.string "to Meteor Falls…\p"
	.string "But they tricked me.\n"
	.string "They even took my meteorite sample…\p"
	.string "Then you showed up, and they showed up…\n"
	.string "I don't understand any of it.\p"
	.string "Please… if it isn't destroyed…\n"
	.string "Can you return it to me?\p"
	.string "I know it's a lot to ask from…\n"
	.string "your kind… but… please?$"
MeteorFalls_1F_1R_EventScript_22BF3D:: @ 822BF3D
	msgbox MeteorFalls_1F_1R_Text_22C47D, MSGBOX_DEFAULT
	release
	end
MeteorFalls_1F_1R_Text_22C47D: @ 822C47D
	.string "Prof. Cozmo: Please… If Team Magma\n"
	.string "doesn't destroy the meteorite…\p"
	.string "Can you return it to me? Please?$"

@ -----------------------------------------------------
@ Cutscene: Finding the Meteorite

#define LID_COSMO 10
#define LID_MAGMA1 5
#define LID_MAGMA2 6
#define LID_ARCHIE 7
#define LID_AQUAGIRL 8
#define LID_AQUA2 9

MeteorFalls_1F_1R_TriggerScript_FindingRocks_LoadName:
	bufferstring 0, MeteorFalls_1F_1R_Text_FindingRocks_LoadName1
	return
MeteorFalls_1F_1R_Text_FindingRocks_LoadName1:
	.string "{AQUA_GIRL}: $"
MeteorFalls_1F_1R_Text_FindingRocks_LoadName2:
	.string "$"

MeteorFalls_1F_1R_TriggerScript_FindingRocks::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_Y, 18
	@
	markasdialog -26
	msgbox MeteorFalls_1F_1R_Text_FindingRocks1
	closemessage
	@ Player walks over to see what's going on
	selectpointer MeteorFalls_1F_1R_MovementTable_FindingRocks2, VAR_INTERACT_Y
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, MeteorFalls_1F_1R_Movement_FindingRocks2_Camera
	waitmovement 0
	@
	markasdialog 10
	msgbox MeteorFalls_1F_1R_Text_FindingRocks3
	closemessage
	@ Magma notices player
	playbgm MUS_MGM0, 0
	applymovement LID_MAGMA1, Common_Movement_WalkInPlaceUp
	applymovement LID_MAGMA2, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LID_MAGMA1, Common_Movement_ExclamationMarkAndWait
	applymovement LID_MAGMA2, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	@
	markasdialog 10
	msgbox MeteorFalls_1F_1R_Text_FindingRocks4
	closemessage
	@
	applymovement LID_MAGMA1, MeteorFalls_1F_1R_Movement_FindingRocks5
	waitmovement 0
	markasdialog 14
	msgbox MeteorFalls_1F_1R_Text_FindingRocks5
	closemessage
	@
	applymovement LID_MAGMA2, MeteorFalls_1F_1R_Movement_FindingRocks6_Magma2
	applymovement LID_COSMO, MeteorFalls_1F_1R_Movement_FindingRocks6_Cosmo
	applymovement LID_MAGMA1, MeteorFalls_1F_1R_Movement_FindingRocks6_Magma1
	waitmovement LID_MAGMA1
	applymovement EVENT_OBJ_ID_PLAYER, MeteorFalls_1F_1R_Movement_FindingRocks6_Player
	waitmovement 0
	applymovement LID_MAGMA1, Common_Movement_WalkUp1
	waitmovement 0
	waitmovement LID_MAGMA2
	waitmovement LID_COSMO
	special RemoveCameraObject
	@ removeobject LID_MAGMA2
	delay 10
	@ BATTLE
	trainerbattle_no_intro TRAINER_GRUNT_15, MeteorFalls_1F_1R_Text_FindingRocks6
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	@ Load Jessica's name if friendship is high enough
	bufferstring 0, MeteorFalls_1F_1R_Text_FindingRocks_LoadName2
	compare VAR_AQUA_GIRL_FRIENDSHIP, 1
	call_if_ge MeteorFalls_1F_1R_TriggerScript_FindingRocks_LoadName
	@
	markasdialog -29
	msgbox MeteorFalls_1F_1R_Text_FindingRocks8
	@
	applymovement LID_MAGMA1, Common_Movement_WalkInPlaceDown
	applymovement LID_COSMO, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LID_MAGMA1, Common_Movement_ExclamationMarkAndWait
	applymovement LID_COSMO, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	playbgm MUS_AQA_0, 0
	markasdialog -9
	msgbox MeteorFalls_1F_1R_Text_FindingRocks9
	closemessage
	@ Aqua members runs in
	applymovement LID_MAGMA1, MeteorFalls_1F_1R_Movement_FindingRocks10_Magma1
	applymovement LID_COSMO, MeteorFalls_1F_1R_Movement_FindingRocks10_Cosmo
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	addobject LID_AQUAGIRL
	addobject LID_AQUA2
	applymovement LID_AQUAGIRL, MeteorFalls_1F_1R_Movement_FindingRocks10_AquaGirl
	applymovement LID_AQUA2, MeteorFalls_1F_1R_Movement_FindingRocks10_Aqua2
	waitmovement LID_AQUAGIRL
	waitmovement LID_MAGMA1
	removeobject LID_MAGMA1
	removeobject LID_MAGMA2
	special SpawnCameraObject
	@
	markasdialog -12
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	addobject LID_ARCHIE
	applymovement LID_ARCHIE, MeteorFalls_1F_1R_Movement_FindingRocks10_Archie
	msgbox MeteorFalls_1F_1R_Text_FindingRocks10
	closemessage
	waitmovement LID_ARCHIE
	@
	markasdialog 6
	applymovement LID_AQUA2, Common_Movement_WalkInPlaceLeft
	applymovement EVENT_OBJ_ID_PLAYER, MeteorFalls_1F_1R_Movement_FindingRocks11_Player
	msgbox MeteorFalls_1F_1R_Text_FindingRocks11
	waitmovement 0
	@
	applymovement LID_ARCHIE, Common_Movement_WalkInPlaceUp
	applymovement LID_AQUAGIRL, Common_Movement_WalkInPlaceDown
	msgbox MeteorFalls_1F_1R_Text_FindingRocks12
	@
	applymovement LID_AQUA2, MeteorFalls_1F_1R_Movement_FindingRocks12_Aqua2
	applymovement LID_ARCHIE, MeteorFalls_1F_1R_Movement_FindingRocks12_Archie
	applymovement LID_AQUAGIRL, Common_Movement_WalkInPlaceRight
	msgbox MeteorFalls_1F_1R_Text_FindingRocks13
	applymovement LID_AQUAGIRL, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LID_AQUAGIRL, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	@
	msgbox MeteorFalls_1F_1R_Text_FindingRocks14
	waitmovement 0
	closemessage
	fadedefaultbgm
	applymovement LID_AQUAGIRL, MeteorFalls_1F_1R_Movement_FindingRocks12_AquaGirl
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement LID_AQUAGIRL
	removeobject LID_AQUAGIRL
	removeobject LID_AQUA2
	removeobject LID_ARCHIE
	@ Clean up
	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT
	setvar VAR_METEOR_FALLS_STATE, 1
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	special RemoveCameraObject
	releaseall
	end

MeteorFalls_1F_1R_Text_FindingRocks1:
	.string "This is it, is it?\p"
	.string "Why y-yes, of course it is!$"
MeteorFalls_1F_1R_Text_FindingRocks3:
	.string "Hehehe! Well, if that's the case…\p"
	.string "With this meteorite, that thing in\n"
	.string "Mt. Chimney will…$"
MeteorFalls_1F_1R_Text_FindingRocks4:
	.string "Oh ho! What is this?\p"
	.string "That's quite a prominent Team Aqua\n"
	.string "sign you got there!$"
MeteorFalls_1F_1R_Text_FindingRocks5:
	.string "Take the rock and get out of here,\n"
	.string "Jared!\p"
	.string "I'll make sure this kid doesn't blab!$"
MeteorFalls_1F_1R_Text_FindingRocks6:
	.string "Shoot, you're tougher than I thought!$"
MeteorFalls_1F_1R_Text_FindingRocks8:
	.string "{STR_VAR_1}{PLAYER}!\n"
	.string "We've got your back!$"
MeteorFalls_1F_1R_Text_FindingRocks9:
	.string "Oh no! There's more coming!\p"
	.string "I gotta peace out!$"
MeteorFalls_1F_1R_Text_FindingRocks10:
	.string "{STR_VAR_1}{PLAYER}, you alright?\p"
	.string "We saw a Magma goon run out and\n"
	.string "we came to investigate.$"
MeteorFalls_1F_1R_Text_FindingRocks11:
	.string "Archie: Ah yes, I remember you.\p"
	.string "You were that eager {PLAYER_boy} who helped\n"
	.string "us back in Slateport.\p"
	.string "{AQUA_GIRL}, you said {PLAYER_their} name\n"
	.string "was {PLAYER}, yes?\p"
	.string "Team Magma is a dangerous group of\n"
	.string "total fanatics.\p"
	.string "They engage in destruction, claiming\n"
	.string "to expand the land mass.\p"
	.string "What did you overhear them saying?\p"
	.string "… … … … … … … …\n"
	.string "… … … … … … … …\p"
	.string "I see…\n"
	.string "So, they're heading to Mt. Chimney.$"
MeteorFalls_1F_1R_Text_FindingRocks12:
	.string "{AQUA_GIRL}, we've got to hurry.\p"
	.string "There's no telling what Team Magma\n"
	.string "will do at Mt. Chimney!$"
MeteorFalls_1F_1R_Text_FindingRocks13:
	.string "{AQUA_GIRL}: Uh, y-yes, sir!$"
MeteorFalls_1F_1R_Text_FindingRocks14:
	.string "{PLAYER}, if you really want the boss's\n"
	.string "respect, I suggest you join us there.$"


.align 2
MeteorFalls_1F_1R_MovementTable_FindingRocks2:
	.4byte MeteorFalls_1F_1R_Movement_FindingRocks2_0
	.4byte MeteorFalls_1F_1R_Movement_FindingRocks2_1
	.4byte 0
MeteorFalls_1F_1R_Movement_FindingRocks2_0:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks2_1:
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_in_place_fastest_down
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks2_Camera:
	walk_diag_southwest
	walk_down
	walk_down
	step_end

MeteorFalls_1F_1R_Movement_FindingRocks5: @ 822BEC0
	walk_right
	walk_right
	walk_in_place_fastest_down
	step_end

MeteorFalls_1F_1R_Movement_FindingRocks6_Cosmo:
	delay_16
	emote_exclamation_mark
	walk_fast_left
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks6_Magma2:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks6_Magma1:
	walk_fast_up
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks6_Player:
	lock_facing_direction
	slide_up
	unlock_facing_direction
	step_end

MeteorFalls_1F_1R_Movement_FindingRocks10_Magma1: @ 822BEC4
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks10_Cosmo:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_in_place_fastest_up
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks10_AquaGirl:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_right
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks10_Aqua2:
	walk_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_right
	walk_right
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks10_Archie:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_FindingRocks11_Player:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

MeteorFalls_1F_1R_Movement_FindingRocks12_Archie:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks12_Aqua2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
MeteorFalls_1F_1R_Movement_FindingRocks12_AquaGirl:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

#undef LID_COSMO
#undef LID_MAGMA1
#undef LID_MAGMA2
#undef LID_ARCHIE
#undef LID_AQUAGIRL
#undef LID_AQUA2


@ MeteorFalls_1F_1R_TriggerScript_FindingRocks:: @ 822BD5F
@ 	lockall
@ 	playbgm MUS_MGM0, 0
@ 	@ Player comes across this scene
@ 	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
@ 	waitmovement 0
@ 	delay 30
@ 	@ "With this meteorite..."
@ 	applymovement LID_MAGMA1, Common_Movement_WalkInPlaceDown
@ 	waitmovement 0
@ 	markasdialog
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks1
@ 	closemessage
@ 	@ Magma notices player
@ 	applymovement LID_MAGMA1, Common_Movement_WalkInPlaceUp
@ 	applymovement LID_MAGMA2, Common_Movement_WalkInPlaceUp
@ 	waitmovement 0
@ 	playse SE_PIN
@ 	applymovement LID_MAGMA1, Common_Movement_ExclamationMarkAndWait
@ 	waitmovement 0
@ 	@ "Don't get in our way!"
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks3
@ 	closemessage
@ 	@ Magma walks up to player
@ 	applymovement LID_MAGMA1, MeteorFalls_1F_1R_Movement_FindingRocks4
@ 	waitmovement 0
@ 	@ Aqua shouts
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks5
@ 	closemessage
@ 	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
@ 	applymovement LID_MAGMA1, Common_Movement_WalkInPlaceLeft
@ 	applymovement LID_MAGMA2, Common_Movement_WalkInPlaceLeft
@ 	waitmovement 0
@ 	@ Aqua appears
@ 	addobject LID_ARCHIE
@ 	addobject LID_AQUA1
@ 	addobject LID_AQUA2
@ 	playbgm MUS_AQA_0, 0
@ 	applymovement LID_ARCHIE, MeteorFalls_1F_1R_Movement_FindingRocks6_Archie
@ 	applymovement LID_AQUA1, MeteorFalls_1F_1R_Movement_FindingRocks6_Aqua1
@ 	applymovement LID_AQUA2, MeteorFalls_1F_1R_Movement_FindingRocks6_Aqua2
@ 	waitmovement 0
@ 	@
@ 	applymovement LID_MAGMA1, Common_Movement_WalkInPlaceLeft
@ 	applymovement LID_MAGMA2, Common_Movement_WalkInPlaceLeft
@ 	waitmovement 0
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks7
@ 	closemessage
@ 	@ Magma runs off
@ 	applymovement EVENT_OBJ_ID_PLAYER, MeteorFalls_1F_1R_Movement_FindingRocks8_Player
@ 	applymovement LID_MAGMA1, MeteorFalls_1F_1R_Movement_FindingRocks8_Magma1
@ 	applymovement LID_MAGMA2, MeteorFalls_1F_1R_Movement_FindingRocks8_Magma2
@ 	waitmovement 0
@ 	removeobject LID_MAGMA1
@ 	removeobject LID_MAGMA2
@ 	@
@ 	applymovement LID_ARCHIE, MeteorFalls_1F_1R_Movement_FindingRocks9
@ 	waitmovement 0
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks9
@ 	closemessage
@ 	@
@ 	applymovement LID_AQUA1, MeteorFalls_1F_1R_Movement_FindingRocks10_Aqua1
@ 	applymovement LID_AQUA2, MeteorFalls_1F_1R_Movement_FindingRocks10_Aqua2
@ 	waitmovement 0
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks10
@ 	@
@ 	applymovement LID_ARCHIE, Common_Movement_WalkInPlaceDown
@ 	waitmovement 0
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks11
@ 	@
@ 	applymovement LID_ARCHIE, Common_Movement_WalkInPlaceLeft
@ 	waitmovement 0
@ 	msgbox MeteorFalls_1F_1R_Text_FindingRocks12
@ 	closemessage
@ 	@ Exunt
@ 	applymovement LID_ARCHIE, MeteorFalls_1F_1R_Movement_FindingRocks13_Archie
@ 	applymovement LID_AQUA1, MeteorFalls_1F_1R_Movement_FindingRocks13_Aqua1
@ 	applymovement LID_AQUA2, MeteorFalls_1F_1R_Movement_FindingRocks13_Aqua2
@ 	waitmovement 0
@ 	fadedefaultbgm
@ 	removeobject LID_ARCHIE
@ 	removeobject LID_AQUA1
@ 	removeobject LID_AQUA2
@ 	@ Clean up
@ 	setflag FLAG_HIDE_ROUTE_112_TEAM_MAGMA
@ 	setflag FLAG_MET_ARCHIE_METEOR_FALLS
@ 	setflag FLAG_HIDE_FALLORBOR_TOWN_BATTLE_TENT_SCOTT
@ 	setvar VAR_METEOR_FALLS_STATE, 1
@ 	releaseall
@ 	end

@ MeteorFalls_1F_1R_Text_FindingRocks1: @ 822BF47
@ 	.string "Hehehe!\p"
@ 	.string "With this meteorite, that thing in\n"
@ 	.string "Mt. Chimney will…$"
@ MeteorFalls_1F_1R_Text_FindingRocks3: @ 822BF84
@ 	.string "Heh?\p"
@ 	.string "I don't know who you are, but if you get\n"
@ 	.string "in the way of Team Magma, don't\l"
@ 	.string "expect any mercy!$"
@ MeteorFalls_1F_1R_Text_FindingRocks5: @ 822BFE4
@ 	.string "Hold it right there, Team Magma!\p"
@ 	.string "You're badly mistaken if you think you\n"
@ 	.string "can have your way with the world!$"
@ MeteorFalls_1F_1R_Text_FindingRocks7: @ 822C04E
@ 	.string "Hehehe!\n"
@ 	.string "Even Team Aqua joins us!\p"
@ 	.string "But it's too much trouble to deal with\n"
@ 	.string "you all…\p"
@ 	.string "Heh, it doesn't matter!\p"
@ 	.string "We've got the METEORITE, so off to\n"
@ 	.string "Mt. Chimney we go!\p"
@ 	.string "Hehehe! Be seeing you, you TEAM\n"
@ 	.string "AQUA dingbats!$"
@ MeteorFalls_1F_1R_Text_FindingRocks9: @ 822C11C
@ 	.string "ARCHIE: Didn't I see you before?\n"
@ 	.string "At SLATEPORT's MUSEUM?\p"
@ 	.string "Ah, so your name is {PLAYER}.\p"
@ 	.string "At the time, I thought you were one\n"
@ 	.string "of Team Magma's goons.\p"
@ 	.string "Humph…\n"
@ 	.string "You're one odd kid.\p"
@ 	.string "Team Magma is a dangerous group of\n"
@ 	.string "total fanatics.\p"
@ 	.string "They engage in destruction, claiming\n"
@ 	.string "to expand the land mass.\p"
@ 	.string "They are the rivals to us,\n"
@ 	.string "the sea-loving Team Aqua!$"
@ MeteorFalls_1F_1R_Text_FindingRocks10: @ 822C268
@ 	.string "BOSS, we should give chase to\n"
@ 	.string "Team Magma…$"
@ MeteorFalls_1F_1R_Text_FindingRocks11: @ 822C292
@ 	.string "ARCHIE: Yes, yes, we must!\n"
@ 	.string "We've got to hurry.\p"
@ 	.string "There's no telling what Team Magma\n"
@ 	.string "will do at Mt. Chimney!$"
@ MeteorFalls_1F_1R_Text_FindingRocks12: @ 822C2FC
@ 	.string "ARCHIE: {PLAYER}, you should keep\n"
@ 	.string "an eye out for Team Magma, too.\p"
@ 	.string "Farewell!$"



@ MeteorFalls_1F_1R_Movement_FindingRocks4: @ 822BEC0
@ 	walk_right
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ MeteorFalls_1F_1R_Movement_FindingRocks6_Archie: @ 822BED9
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks6_Aqua1: @ 822BEE0
@ 	delay_16
@ 	delay_16
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks6_Aqua2: @ 822BEE8
@ 	delay_16
@ 	delay_16
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	step_end

@ MeteorFalls_1F_1R_Movement_FindingRocks8_Player: @ 822BF1D
@ 	walk_in_place_fastest_down
@ 	delay_4
@ 	walk_in_place_fastest_right
@ 	lock_facing_direction
@ 	walk_left
@ 	unlock_facing_direction
@ 	face_right
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks8_Magma1: @ 822BEC4
@ 	walk_fast_up
@ 	walk_fast_up
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks8_Magma2: @ 822BECE
@ 	walk_fast_up
@ 	walk_fast_up
@ 	walk_fast_up
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	walk_fast_right
@ 	step_end

@ MeteorFalls_1F_1R_Movement_FindingRocks9: @ 822BEF8
@ 	walk_right
@ 	walk_right
@ 	walk_up
@ 	walk_up
@ 	walk_in_place_fastest_left
@ 	step_end

@ MeteorFalls_1F_1R_Movement_FindingRocks10_Aqua1: @ 822BF08
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks10_Aqua2: @ 822BF18
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_in_place_fastest_up
@ 	step_end

@ MeteorFalls_1F_1R_Movement_FindingRocks13_Archie: @ 822BEF0
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks13_Aqua1: @ 822BEFE
@ 	walk_up
@ 	walk_up
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	step_end
@ MeteorFalls_1F_1R_Movement_FindingRocks13_Aqua2: @ 822BF0D
@ 	walk_up
@ 	walk_up
@ 	walk_up
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	walk_right
@ 	step_end
