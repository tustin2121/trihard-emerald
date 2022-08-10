EverGrandeCity_MapScripts:: @ 81E7D1B
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_OnTransition: @ 81E7D21
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeatherAlternating
	end
@ -----------------------------------------------------

EverGrandeCity_OnLoad:
	call_if_unset FLAG_BADGE08_GET, EverGrandeCity_OnLoad_MakeRoadblock
	end

EverGrandeCity_OnLoad_MakeRoadblock:
	setmetatile 32, 62, 0x27E, TRUE
	setmetatile 33, 62, 0x27F, TRUE
	setmetatile 32, 63, 0x286, TRUE
	setmetatile 33, 63, 0x287, TRUE
	setobjectxyperm 4, 33, 64
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_UP
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
	setflag FLAG_ENABLE_ALEX_LEAGUE_CALL
	clearflag FLAG_ALEX_CALL_LEGENDARIES @ If somehow alex is still pending a call about legendaries
	setvar VAR_ALEX_CALL_STEP_COUNTER, 0
	end


EverGrandeCity_TriggerScript_VRRoadBlock::
	lock
	applymovement 2, Common_Movement_FacePlayer
	waitmovement 0
	msgbox EverGrandeCity_Text_VRRoadBlock, MSGBOX_CDIALOG
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	release
	end
EverGrandeCity_Text_VRRoadBlock:
	.string "I'm sorry, {PLAYER_sir}. This road is still\n"
	.string "being cleared of landslide rubble.\p"
	.string "You'll have to take the detour\n"
	.string "through Victory Road for now.$"


EverGrandeCity_EventScript_WaterfallRoadBlock::
	goto_if_set FLAG_BADGE08_GET, EverGrandeCity_EventScript_WaterfallRoadBlock2
	msgbox EverGrandeCity_Text_WaterfallRoadBlock1, MSGBOX_NPC
	end
EverGrandeCity_Text_WaterfallRoadBlock1:
	.string "A giant red Pokémon came rampaging\n"
	.string "through here the other day!\p"
	.string "It caused several landslides which\n"
	.string "we can hopefully clear out before the\l"
	.string "start of the Elite Four Conference.$"
EverGrandeCity_EventScript_WaterfallRoadBlock2:
	msgbox EverGrandeCity_Text_WaterfallRoadBlock2, MSGBOX_NPC
	end
EverGrandeCity_Text_WaterfallRoadBlock2:
	.string "That massive red Pokémon that was\n"
	.string "fighting in Sootopolis! It caused a\l"
	.string "landslide here that we had to clear out.\p"
	.string "Thankfully, we managed to do it before\n"
	.string "the Elite Four Conference started.$"


EverGrandeCity_EventScript_Sailor::
	msgbox EverGrandeCity_Text_Sailor, MSGBOX_DESCRIBE
	end
EverGrandeCity_Text_Sailor:
	.string "He's just staring off into space,\n"
	.string "completely oblivious to you.$"


EverGrandeCity_EventScript_TransportMossdeep::
	lock
	faceplayer
	markasdialog
	askforboat EverGrandeCity_Text_TransportMossdeep_Ask, EverGrandeCity_Text_TransportMossdeep_Decline, EverGrandeCity_Text_TransportMossdeep_NoMoney, EverGrandeCity_Text_TransportMossdeep_Embark
	warpcustom MAP_MOSSDEEP_CITY, 255, 65, 36
	waitstate
	end
EverGrandeCity_Text_TransportMossdeep_Ask:
	.string "Hello, old {PLAYER_boy}, I will be\n"
	.string "heading back to {PLACE}Mossdeep{END} shortly.\p"
	.string "For ¥100, I'll give you a ride there.$"
EverGrandeCity_Text_TransportMossdeep_Decline:
	.string "Your loss.$"
EverGrandeCity_Text_TransportMossdeep_NoMoney:
	.string "You don't have the money.$"
EverGrandeCity_Text_TransportMossdeep_Embark:
	.string "Thanks! Let us embark!$"


EverGrandeCity_EventScript_JoeyFight::
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_DAILY_E4_JOEY_BATTLE, EverGrandeCity_EventScript_JoeyFight_After
	goto_if_set FLAG_MET_E4_JOEY, EverGrandeCity_EventScript_JoeyFightRematch
	msgbox EverGrandeCity_Text_JoeyFight1
	setflag FLAG_MET_E4_JOEY
	setflag FLAG_DEATH_PREVENT
	setflag FLAG_DEATH_PREVENT_1HP
	trainerbattle_no_intro TRAINER_JOEY_E4_1, EverGrandeCity_Text_JoeyFight2
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	setflag FLAG_DAILY_E4_JOEY_BATTLE
	msgbox EverGrandeCity_Text_JoeyFight3
	release
	end
EverGrandeCity_Text_JoeyFight1:
	.string "I'm really nervous about the\n"
	.string "Hoenn Elite Four Conference.\p"
	.string "I came all the way from Johto for this,\n"
	.string "but I don't think I'm ready yet…\p"
	.string "Hey, wanna battle real quick?\n"
	.string "We can see if we're ready together!$"
EverGrandeCity_Text_JoeyFight2:
	.string "Man, I can't catch a break…$"
EverGrandeCity_Text_JoeyFight3:
	.string "So, are you really tough?\n"
	.string "Or am I just bad this?\p"
	.string "I taught my Pokémon some TMs like\n"
	.string "people said, but I think that just\l"
	.string "made my Pokémon worse…$"
EverGrandeCity_EventScript_JoeyFight_After:
	msgbox EverGrandeCity_Text_JoeyFight_After
	release
	end
EverGrandeCity_Text_JoeyFight_After:
	.string "Joey: Maybe I'll be better tomorrow…\n"
	.string "I gotta think on what to do…$"
EverGrandeCity_EventScript_JoeyFightRematch:
	msgbox EverGrandeCity_Text_JoeyFightRematch1
	setflag FLAG_DEATH_PREVENT
	setflag FLAG_DEATH_PREVENT_1HP
	trainerbattle_no_intro TRAINER_JOEY_E4_1, EverGrandeCity_Text_JoeyFight2
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	setflag FLAG_DAILY_E4_JOEY_BATTLE
	msgbox EverGrandeCity_Text_JoeyFightRematch3
	release
	end
EverGrandeCity_Text_JoeyFightRematch1:
	.string "Joey: Hey, let's battle again and see\n"
	.string "if we got any better!$"
EverGrandeCity_Text_JoeyFightRematch3:
	.string "Man, I must be bad at this. You seem\n"
	.string "to be getting better, but I'm not…$"
