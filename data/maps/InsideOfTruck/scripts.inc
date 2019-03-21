InsideOfTruck_MapScripts:: @ 823BEDA
	map_script 1, InsideOfTruck_MapScript1_23BEE5
	map_script 5, InsideOfTruck_MapScript1_23BF01
	.byte 0

InsideOfTruck_MapScript1_23BEE5: @ 823BEE5
	setmetatile 4, 1, 520, 0
	setmetatile 4, 2, 528, 0
	setmetatile 4, 3, 536, 0
	end

InsideOfTruck_MapScript1_23BF01: @ 823BF01
	setstepcallback 5
	end

InsideOfTruck_SetPrologueVarsScript:: @ 823BF04
	lockall
	setflag FLAG_SPECIAL_FLAG_0x4000
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq InsideOfTruck_SetPrologueVarsScript_Boy
	compare VAR_RESULT, FEMALE
	goto_if_eq InsideOfTruck_SetPrologueVarsScript_Girl
	end

InsideOfTruck_SetPrologueVarsScript_Boy: @ 823BF20
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	setvar VAR_0x4092, 1
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	setvar VAR_0x408C, 1
	setflag FLAG_SYS_B_DASH @ Give Fast Movement
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 3, 10
	releaseall
	end

InsideOfTruck_SetPrologueVarsScript_Girl: @ 823BF46
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_0x4092, 2
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	setvar VAR_0x4082, 1
	setflag FLAG_SYS_B_DASH @ Give Fast Movement
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	end

InsideOfTruck_EventScript_MovingBoxText:: @ 823BF6C
	msgbox InsideOfTruck_Text_MovingBoxText, MSGBOX_SIGN
	end

InsideOfTruck_EventScript_DebugMovingBox:: @ 823BF6C
#if !DEBUG
	msgbox InsideOfTruck_Text_MovingBoxText, MSGBOX_SIGN
#else
	msgbox InsideOfTruck_Text_DebugBoxText, MSGBOX_SIGN
	call EventScript_GiveDebugPartyAndSetFlags
#endif
	end

InsideOfTruck_Text_MovingBoxText: @ 823BF75
	.string "The box is printed with a POKéMON logo.\p"
	.string "It's a POKéMON brand moving and\n"
	.string "delivery service.$"

InsideOfTruck_Text_DebugBoxText: @ 823BF75
	.string "Oh! There's some Pokemon and badges in\n"
	.string "this box! Yoink!$"

EventScript_GiveDebugPartyAndSetFlags::
	lockall
	@ Give debug party
	givemon SPECIES_RATTATA, 2, ITEM_NONE, 0, 0, 0
	givemon SPECIES_WAILMER, 30, ITEM_NONE, 0, 0, 0
	givemon SPECIES_BRELOOM, 27, ITEM_NONE, 0, 0, 0
	givemon SPECIES_SWELLOW, 30, ITEM_NONE, 0, 0, 0
	givemon SPECIES_QUILAVA, 50, ITEM_EVERSTONE, 0, 0, 0
	setmonmove 1, 3, MOVE_FLY
	@ Set starting scripts past the end of the prologue
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_MAYS_HOUSE_2F
	setvar VAR_0x4092, 3
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_RESCUED_BIRCH
	setvar VAR_0x4082, 1
	setvar VAR_0x4050, 4 @ Set mom to after prologue
	setflag FLAG_SYS_B_DASH @ Give Fast Movement
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 12, 10
	releaseall
	return