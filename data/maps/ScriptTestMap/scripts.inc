ScriptTestMap_MapScripts::
	.byte 0

#define VID_JAMES 1
#define VID_JOEY 2

ScriptTestMap_SignScript::
	lock
	goto_if_set FLAG_TEMP_1, ScriptTestMap_SignScript2
	createvobject EVENT_OBJ_GFX_YOUNGSTER, VID_JOEY, 7, 6, 3, DIR_EAST
	msgbox ScriptTestMap_SignScript_Text
	setflag FLAG_TEMP_1
	release
	end
ScriptTestMap_SignScript_Text:
	.string "Poof! Robot Joey appears!$"
ScriptTestMap_SignScript2:
	removeobject VID_JOEY
	msgbox ScriptTestMap_SignScript_Text
	clearflag FLAG_TEMP_1
	release
	end
ScriptTestMap_SignScript_Text2:
	.string "Poof! Robot Joey vanishes!$"


ScriptTestMap_TriggerScript_Fight::
	lock
	setweather WEATHER_RAIN_HEAVY
	doweather
	special WaitWeather
	waitstate
	callnative BattleSetup_StartLegendaryRageBattle
	waitstate
	@ specialvar VAR_RESULT, GetBattleOutcome
	
	release
	end

ScriptTestMap_TriggerScript_FieldEffectTest::
	lock
	dofieldeffect FLDEFF_DUST
	waitfieldeffect FLDEFF_DUST
	release
	end


ScriptTestMap_SignScript_RunAround::
	createvobject EVENT_OBJ_GFX_YOUNGSTER, VID_JAMES, 6, 10, 3, DIR_EAST
	applymovement VID_JAMES, ScriptTestMap_Movement_RunAround
	waitmovement 0
	removeobject VID_JAMES
	end
ScriptTestMap_Movement_RunAround:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end


#undef VID_JAMES
#undef VID_JOEY