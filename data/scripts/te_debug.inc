DebugScript_EmergencySave::
	lockall
	playse SE_SELECT
	special DoSaveGame
	waitstate
	special DebugSetCallbackSuccess
	releaseall
	end

DebugScript_ShowPCBox::
	lockall
	playse SE_SELECT
	special ShowPokemonStorageSystemPC
	waitstate @ should pause here
	closemessage
	setvar VAR_0x8004, 0 @ Not sure what this does, but the PC sets it to 0 on close
	special DebugSetCallbackSuccess
	releaseall
	end

DebugScript_GiveDebugPartyAndSetFlags::
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
	
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_TRUCK
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F_POKE_BALL
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_TRUCK
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_2F_POKE_BALL
	
	setflag FLAG_HIDE_LITTLEROOT_TOWN_BRENDANS_HOUSE_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_MOM
	setflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_SIBLING
	setflag FLAG_RESCUED_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_SYS_B_DASH @ Give Fast Movement
	
	setvar VAR_LITTLEROOT_INTRO_STATE, 7 @ After last intro
	setvar VAR_LITTLEROOT_HOUSES_STATE, 2 @ After rival introduction
	setvar VAR_LITTLEROOT_HOUSES_STATE_2, 2 @ After rival introduction
	setvar VAR_0x4050, 4 @ Set mom to after prologue
	setvar VAR_BIRCH_LAB_STATE, 5
	setvar VAR_ROUTE102_ACCESSIBLE, 1
	setvar VAR_LITTLEROOT_RIVAL_STATE, 4
	
	setdynamicwarp MAP_LITTLEROOT_TOWN, 255, 9, 10
	releaseall
	return

ScriptText_DebugBoxText: @ 823BF75
	.string "Oh! There's some Pokemon and badges in\n"
	.string "this box! Yoink!$"