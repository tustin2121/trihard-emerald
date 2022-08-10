PetalburgCity_WallysHouse_MapScripts:: @ 8204229
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_MapScript2_FrameTable
	@ map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_MapScript2_MapTable
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_WallysHouse_OnLoad
	.byte 0

@ -----------------------------------------------------

@ PetalburgCity_WallysHouse_MapScript2_MapTable: @ 8204234
@ 	map_script_2 VAR_LOGAN_STATE, 0, PetalburgCity_WallysHouse_EventScript_HideActors1
@ 	map_script_2 VAR_LOGAN_STATE, 1, PetalburgCity_WallysHouse_EventScript_HideActors2
@ 	map_script_2 VAR_LOGAN_STATE, 2, PetalburgCity_WallysHouse_EventScript_HideActors2
@ 	map_script_2 VAR_LOGAN_STATE, 3, PetalburgCity_WallysHouse_EventScript_HideActors3
@ 	.2byte 0

PetalburgCity_WallysHouse_OnLoad:
	selectpointer_clamp PetalburgCity_WallysHouse_OnLoad_ScriptTable, VAR_LOGAN_STATE
	goto 0
	end
	
.align 2
PetalburgCity_WallysHouse_OnLoad_ScriptTable:
	.4byte PetalburgCity_WallysHouse_EventScript_HideActors1
	.4byte PetalburgCity_WallysHouse_EventScript_HideActors2
	.4byte PetalburgCity_WallysHouse_EventScript_HideActors2
	.4byte PetalburgCity_WallysHouse_EventScript_HideActors3
	.4byte 0

PetalburgCity_WallysHouse_EventScript_HideActors1: @ 820423E
	setflag FLAG_TEMP_10 @ Used to hide Logan's Dad
	setflag FLAG_TEMP_11 @ Used to hide Logan's Mom
	end
PetalburgCity_WallysHouse_EventScript_HideActors2:
	setflag FLAG_TEMP_10 @ Used to hide Logan's Dad
	setflag FLAG_TEMP_11 @ Used to hide Logan's Mom
	setflag FLAG_TEMP_12 @ Used to hide Logan's cousin
	end

PetalburgCity_WallysHouse_EventScript_HideActors3:
	setflag FLAG_TEMP_12 @ Used to hide Logan's cousin
	goto_if_set FLAG_TATTLED_ON_LOGAN, PetalburgCity_WallysHouse_EventScript_HideMom
	end
PetalburgCity_WallysHouse_EventScript_HideMom:
	setflag FLAG_TEMP_11 @ Used to hide Logan's Mom
	end
	
@ 	turnobject EVENT_OBJ_ID_PLAYER, 4
@ 	turnobject 1, 3

@ -----------------------------------------------------

PetalburgCity_WallysHouse_MapScript2_FrameTable: @ 8204247
	@ map_script_2 VAR_PETALBURG_STATE, 4, PetalburgCity_WallysHouse_EventScript_204251
	.2byte 0

@ -----------------------------------------------------
@ Mom

PetalburgCity_WallysHouse_EventScript_Mother::
	lock
	faceplayer
	markasdialog
	switch VAR_LOGAN_STATE
	case 3, PetalburgCity_WallysHouse_EventScript_MotherState3
	
	msgbox PetalburgCity_WallysHouse_Text_Mother
	release
	end
PetalburgCity_WallysHouse_Text_Mother:
	.string "Oh, I'm so worried about our little boy…$"


PetalburgCity_WallysHouse_EventScript_MotherState3:
	goto_if_set FLAG_TEMP_1, PetalburgCity_WallysHouse_EventScript_MotherState3no2
	setyesnotext gYN_Yeah, gYN_No
	msgbox PetalburgCity_WallysHouse_Text_MotherState3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq PetalburgCity_WallysHouse_EventScript_MotherState3yes
	goto PetalburgCity_WallysHouse_EventScript_MotherState3no
	release
	end
PetalburgCity_WallysHouse_Text_MotherState3:
	.string "We came home this afternoon to find\n"
	.string "our little boy {RIVAL_HERO} GONE!\p"
	.string "We've looked everywhere!\n"
	.string "He's not anywhere in the city!\p"
	.string "Have you seen him, {PLAYER}?\n"
	.string "Please tell me you have!$"

PetalburgCity_WallysHouse_EventScript_MotherState3yes:
	setflag FLAG_TATTLED_ON_LOGAN
	msgbox PetalburgCity_WallysHouse_Text_MotherState3yes
	closemessage
	fadescreen 1
	playse SE_KAIDAN
	removeobject THIS_EVENT
	fadescreen 0
	release
	end
PetalburgCity_WallysHouse_Text_MotherState3yes:
	.string "Oh Lord Arceus above, you have?!\p"
	.string "He's run off to Rustboro?!\p"
	.string "I have to go get him right now!!$"

PetalburgCity_WallysHouse_EventScript_MotherState3no:
	setflag FLAG_TEMP_1
	message PetalburgCity_WallysHouse_Text_MotherState3no
	waitmessage
	@ waitbuttonpress
	playse SE_SELECT
	@fallthrough
PetalburgCity_WallysHouse_EventScript_MotherState3no2:
	msgbox PetalburgCity_WallysHouse_Text_MotherState3no2
	release
	end
PetalburgCity_WallysHouse_Text_MotherState3no:
	.string "{FORCE_AUTOSCROLL_ON}{FORCE_SPEED_YES}"
	.string "Oh, I'm so worried about him!\n"
	.string "He could be hurt out there!\l"
	.string "Mauled by a wild Pokémon!\l"
	.string "Harassed by one of those evil teams!\l"
	.string "Tortured by more Gym Leaders!\l"
	.string "Murdered by a poacher!\l"
	.string "Have his feelings hurt by bullies!\l"
	.string "Robbed by another trainer!\l"
	.string "Fail to reach his dreams!\l"
	.string "Trip and fall off a cliff into the sea!\l"
	.string "Or worst of all, never shower another\l"
	.string "day in his life!{PAUSE 20}$"
PetalburgCity_WallysHouse_Text_MotherState3no2:
	.string "Oh Lord Acerus, help me find him!$"
			

@ -----------------------------------------------------
@ Dad

PetalburgCity_WallysHouse_EventScript_Father::
	msgbox PetalburgCity_WallysHouse_Text_Father, MSGBOX_DESCRIBE
	end
PetalburgCity_WallysHouse_Text_Father:
	.string "{RIVAL_HERO}'s father seems to be\n"
	.string "trying to manage a migrane.$"
	@TODO more in-depth about what's going on

@ -----------------------------------------------------
@ Dad

PetalburgCity_WallysHouse_EventScript_Cousin::
	msgbox PetalburgCity_WallysHouse_Text_Cousin, MSGBOX_NPC
	end
PetalburgCity_WallysHouse_Text_Cousin:
	.string "'Sup. They still looking for {RIVAL_HERO}\n"
	.string "out there?\p"
	.string "{RIVAL_HERO} said he didn't want to go to\n"
	.string "Vanderturf Town with us this morning.\p"
	.string "I don't care, but his mom does and\n"
	.string "is forcing him to go.\p"
	.string "Frankly, I don't blame the kid.\n"
	.string "I'm so glad Aunt Gretchen isn't my mom.$"

