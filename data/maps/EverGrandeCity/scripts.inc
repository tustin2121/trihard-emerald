EverGrandeCity_MapScripts:: @ 81E7D1B
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_OnTransition: @ 81E7D21
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeatherAlternating
	end

@ -----------------------------------------------------
@ Signs

EverGrandeCity_SignScript_VictoryRoad:: @ 81E7D2B
	msgbox EverGrandeCity_Text_1E7D4F, MSGBOX_SIGN
	end
EverGrandeCity_Text_1E7D4F: @ 81E7D4F
	.string "{PLACE}Entering Victory Road{END}$"


EverGrandeCity_SignScript_TownSign:: @ 81E7D34
	msgbox EverGrandeCity_Text_1E7D89, MSGBOX_SIGN
	end
EverGrandeCity_Text_1E7D89: @ 81E7D89
	.string "{PLACE}Ever Grande City{END}\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and Pokémon.”$"


EverGrandeCity_SignScript_League:: @ 81E7D3D
	msgbox EverGrandeCity_Text_1E7D65, MSGBOX_SIGN
	end
EverGrandeCity_Text_1E7D65: @ 81E7D65
	.string "{PLACE}Entering Pokémon League\n"
	.string "Center Gate{END}$"

@ -----------------------------------------------------
@ Signs

EverGrandeCity_TriggerScript_SetVisited:: @ 81E7D46
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end

EverGrandeCity_TriggerScript_RemoveVRRoadBlock::
	setflag FLAG_HIDE_VICTORY_ROAD_BLOCKER
	setvar VAR_EVERGRANDE_STATE, 1
	end

EverGrandeCity_TriggerScript_VRRoadBlock::
	
	end


