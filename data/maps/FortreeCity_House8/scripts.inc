FortreeCity_House8_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_House8_WarpIntoMapTable
	@ map_script MAP_SCRIPT_ON_FRAME_TABLE, FortreeCity_House8_FrameTable
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_House8_OnResume
	@ map_script MAP_SCRIPT_STEAL_CHECK, FortreeCity_House8_FrameTable
	.byte 0

@------------------------------------------------------

FortreeCity_House8_FrameTable:
	map_script_2 VAR_TEMP_0, 0, FortreeCity_House8_StartTurn
	.2byte 0
FortreeCity_House8_StartTurn:
	setobjectmovementtype 1, MOVEMENT_TYPE_LOOK_AROUND
	setvar VAR_TEMP_0, 1
	end

@------------------------------------------------------

FortreeCity_House8_WarpIntoMapTable:
	map_script_2 VAR_TEMP_9, 0, FortreeCity_House8_WarpIn
	.2byte 0
FortreeCity_House8_WarpIn:
	call FortreeCity_House8_CreateVirtualObjects
	setvar VAR_TEMP_9, 1
	end

@------------------------------------------------------
	
FortreeCity_House8_OnResume:
	compare VAR_TEMP_9, 1
	call_if_eq FortreeCity_House8_CreateVirtualObjects
	end
FortreeCity_House8_CreateVirtualObjects:
	createvobject EVENT_OBJ_GFX_WYNAUT_DOLL             0, 6, 4
	createvobject EVENT_OBJ_GFX_TOGEPI_DOLL,            1, 2, 3
	createvobject EVENT_OBJ_GFX_UNUSED_NATU_DOLL,       2, 5, 3
	createvobject EVENT_OBJ_GFX_CLEFAIRY_DOLL,          3, 1, 3
	createvobject EVENT_OBJ_GFX_BALTOY_DOLL,            4, 6, 3
	createvobject EVENT_OBJ_GFX_CHIKORITA_DOLL,         5, 0, 3
	createvobject EVENT_OBJ_GFX_CYNDAQUIL_DOLL,         6, 7, 3
	createvobject EVENT_OBJ_GFX_UNUSED_WOOPER_DOLL,     7, 7, 4
	createvobject EVENT_OBJ_GFX_BIG_REGISTEEL_DOLL,     8, 6, 2
	createvobject EVENT_OBJ_GFX_MARILL_DOLL,            9, 1, 4
	createvobject EVENT_OBJ_GFX_SMOOCHUM_DOLL,         10, 0, 4
	createvobject EVENT_OBJ_GFX_DITTO_DOLL,            11, 4, 2
	createvobject EVENT_OBJ_GFX_JIGGLYPUFF_DOLL,       12, 3, 1
@	object        EVENT_OBJ_GFX_UNUSED_PIKACHU_DOLL    13, 6, 5
@	object        EVENT_OBJ_GFX_UNUSED_SQUIRTLE_DOLL   14, 1, 5
@	object        EVENT_OBJ_GFX_SWABLU_DOLL            15, 5, 5 - Stealable
@	object        EVENT_OBJ_GFX_AZURILL_DOLL           16, 4, 4
@	object        EVENT_OBJ_GFX_UNUSED_PORYGON2_DOLL   17, 5, 4
@	object        EVENT_OBJ_GFX_TREECKO_DOLL           18, 2, 5
@	object        EVENT_OBJ_GFX_TOTODILE_DOLL          19, 0, 5
@	object        EVENT_OBJ_GFX_TORCHIC_DOLL           20, 7, 5
@	object        EVENT_OBJ_GFX_SKITTY_DOLL            21, 2, 4
@	object        EVENT_OBJ_GFX_BIG_SNORLAX_DOLL       22, 1, 2
	return


FortreeCity_House8_EventScript_Collector::
	msgbox FortreeCity_House8_Text_Collector, MSGBOX_NPC
	end
FortreeCity_House8_Text_Collector:
	.string "I DON'T HAVE A PROBLEM!!\p"
	.string "I CAN QUIT ANY TIME I WANT TO!!$"

