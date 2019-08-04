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


ScriptTestMap_TriggerScript_AdvanceTime::
	advancetime 0, 5
	release
	end




ScriptTestMap_EventScript_CryTest0::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 0
	msgbox ScriptTestMap_Text_CryTest0, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest0:
	.string "playmoncry 0$"

ScriptTestMap_EventScript_CryTest1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 1
	msgbox ScriptTestMap_Text_CryTest1, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest1:
	.string "playmoncry 1$"

ScriptTestMap_EventScript_CryTest2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 2
	msgbox ScriptTestMap_Text_CryTest2, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest2:
	.string "playmoncry 2$"

ScriptTestMap_EventScript_CryTest3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 3
	msgbox ScriptTestMap_Text_CryTest3, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest3:
	.string "playmoncry 3$"

ScriptTestMap_EventScript_CryTest4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 4
	msgbox ScriptTestMap_Text_CryTest4, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest4:
	.string "playmoncry 4$"

ScriptTestMap_EventScript_CryTest5::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 5
	msgbox ScriptTestMap_Text_CryTest5, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest5:
	.string "playmoncry 5$"

ScriptTestMap_EventScript_CryTest6::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 6
	msgbox ScriptTestMap_Text_CryTest6, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest6:
	.string "playmoncry 6$"

ScriptTestMap_EventScript_CryTest7::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 7
	msgbox ScriptTestMap_Text_CryTest7, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest7:
	.string "playmoncry 7$"

ScriptTestMap_EventScript_CryTest8::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 8
	msgbox ScriptTestMap_Text_CryTest8, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest8:
	.string "playmoncry 8$"

ScriptTestMap_EventScript_CryTest9::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 9
	msgbox ScriptTestMap_Text_CryTest9, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest9:
	.string "playmoncry 9$"

ScriptTestMap_EventScript_CryTest10::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 10
	msgbox ScriptTestMap_Text_CryTest10, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest10:
	.string "playmoncry 10$"

ScriptTestMap_EventScript_CryTest11::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, 11
	msgbox ScriptTestMap_Text_CryTest11, MSGBOX_DIALOG
	waitmoncry
	release
	end
ScriptTestMap_Text_CryTest11:
	.string "playmoncry 11$"





#undef VID_JAMES
#undef VID_JOEY