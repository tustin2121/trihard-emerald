SootopolisCity_MapScripts:: @ 81E565C
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_MapScript1_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_MapScript1_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_MapScript2_FrameTable
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SootopolisCity_MapScript2_WarpTable
	.byte 0

@ -----------------------------------------------------

SootopolisCity_MapScript1_OnResume: @ 81E590B
	setdivewarp MAP_UNDERWATER_SOOTOPOLIS_CITY, 255, 9, 6
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, SootopolisCity_EventScript_RemoveLegendaries
	end

SootopolisCity_EventScript_RemoveLegendaries:: @ 8267D5E
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_ne Common_EventScript_NopReturn
	call SootopolisCity_EventScript_RemoveLegendaryPedistals
	removeobject 9
	removeobject 10
	return

@ -----------------------------------------------------

SootopolisCity_MapScript1_OnLoad: @ 81E5676
	call_if_set FLAG_LEGENDARIES_IN_SOOTOPOLIS, SootopolisCity_EventScript_SetupLegendariesBattleTrigger
	call_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_EventScript_DestroyCenterRoof
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_BlockGymDoor
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, Common_EventScript_NopEnd
	call_if_unset FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_BlockDoors
	end

SootopolisCity_EventScript_SetupLegendariesBattleTrigger::
	setvar VAR_TEMP_F, 1
	return
SootopolisCity_EventScript_DestroyCenterRoof:: @ 81E5692
	setmetatile 42, 28, 0x300, 1
	setmetatile 43, 28, 0x301, 1
	setmetatile 44, 28, 0x302, 1
	setmetatile 42, 29, 0x308, 1
	setmetatile 43, 29, 0x309, 1
	setmetatile 44, 29, 0x30A, 1
	return
SootopolisCity_EventScript_BlockGymDoor:: @ 81E56E5
	setmetatile 31, 32, 592, 1
	return
SootopolisCity_EventScript_BlockDoors:: @ 81E5693
	setmetatile 9, 6, 584, 1
	setmetatile 9, 17, 584, 1
	setmetatile 9, 26, 584, 1
	setmetatile 44, 17, 584, 1
	setmetatile 8, 35, 584, 1
	setmetatile 53, 28, 584, 1
	setmetatile 45, 6, 584, 1
	setmetatile 48, 25, 584, 1
	setmetatile 51, 36, 584, 1
	return

@ -----------------------------------------------------

SootopolisCity_OnTransition: @ 81E56EF
	setflag FLAG_VISITED_SOOTOPOLIS_CITY
	compare VAR_RAYQUAZA_STATE, 1
	call_if_eq Common_EventScript_HideMapNamePopup
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq Common_EventScript_HideMapNamePopup
	call SootopolisCity_MapScript_SetWeatherType
	call SootopolisCity_MapScript_SetLayout
	compare VAR_RAYQUAZA_STATE, 1
	call_if_eq SootopolisCity_MapScript_SetResidentLocations
	compare VAR_RAYQUAZA_STATE, 2
	call_if_eq SootopolisCity_MapScript_SetResidentLocations
	compare VAR_RAYQUAZA_STATE, 3
	call_if_eq SootopolisCity_MapScript_SetResidentLocations
	compare VAR_RAYQUAZA_STATE, 4
	call_if_eq SootopolisCity_MapScript_SetResidentLocations
	compare VAR_RAYQUAZA_STATE, 5
	call_if_eq SootopolisCity_MapScript_SetResidentLocations
	compare VAR_RAYQUAZA_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5842
	compare VAR_RAYQUAZA_STATE, 3
	call_if_eq SootopolisCity_EventScript_1E5842
	compare VAR_RAYQUAZA_STATE, 4
	call_if_eq SootopolisCity_EventScript_1E585B
	compare VAR_RAYQUAZA_STATE, 5
	call_if_eq SootopolisCity_EventScript_1E5871
	compare VAR_RAYQUAZA_STATE, 6
	call_if_eq SootopolisCity_EventScript_1E58D3
	end
SootopolisCity_MapScript_SetResidentLocations:: @ 81E5785
	setobjectxyperm 3, 13, 48
	setobjectxyperm 5, 46, 32
	setobjectxyperm 4, 48, 41
	setobjectxyperm 8, 45, 43
	setobjectmovementtype 3, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	setobjectmovementtype 8, MOVEMENT_TYPE_FACE_LEFT
	return

SootopolisCity_MapScript_SetLayout:: @ 81E57B2
	compare VAR_RAYQUAZA_STATE, 0
	goto_if_eq Common_EventScript_NopReturn
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge Common_EventScript_NopReturn
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_RAYQUAZA_STATE, 3
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_RAYQUAZA_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E5801
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E5801
	return
SootopolisCity_EventScript_1E5801:: @ 81E5801
	setmaplayoutindex LAYOUT_SOOTOPOLIS_CITY_LEGENDS_BATTLE
	return

SootopolisCity_MapScript_SetWeatherType:: @ 81E5805
	compare VAR_RAYQUAZA_STATE, 0
	goto_if_eq Common_EventScript_NopReturn
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge Common_EventScript_NopReturn
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E583E
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_eq SootopolisCity_EventScript_1E583E
	compare VAR_SKY_PILLAR_STATE, 1
	goto_if_le Common_EventScript_SetWeatherAlternating
	return
SootopolisCity_EventScript_1E583E:: @ 81E583E
	setweather WEATHER_RAIN_HEAVY
	return

SootopolisCity_EventScript_1E5842:: @ 81E5842
	goto_if_set FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_1E584C
	return
SootopolisCity_EventScript_1E584C:: @ 81E584C
	setobjectxyperm 1, 30, 18
	setobjectxyperm 7, 32, 18
	return

SootopolisCity_EventScript_1E585B:: @ 81E585B
	setobjectxyperm 1, 30, 18
	setobjectxyperm 18, 31, 18
	setobjectxyperm 7, 32, 18
	end

SootopolisCity_EventScript_1E5871:: @ 81E5871
	setobjectxyperm 1, 31, 18
	setobjectxyperm 7, 29, 33
	setobjectxyperm 16, 33, 35
	setobjectxyperm 17, 34, 35
	compare VAR_SOOTOPOLIS_STATE, 0
	call_if_eq SootopolisCity_EventScript_1E58AF
	compare VAR_SOOTOPOLIS_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E58BB
	compare VAR_SOOTOPOLIS_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E58C7
	return
SootopolisCity_EventScript_1E58AF:: @ 81E58AF
	setobjectxyperm 18, 31, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return
SootopolisCity_EventScript_1E58BB:: @ 81E58BB
	setobjectxyperm 18, 32, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return
SootopolisCity_EventScript_1E58C7:: @ 81E58C7
	setobjectxyperm 18, 30, 33
	setobjectmovementtype 18, MOVEMENT_TYPE_FACE_DOWN
	return

SootopolisCity_EventScript_1E58D3:: @ 81E58D3
	setobjectxyperm 1, 31, 18
	return

@ -----------------------------------------------------

SootopolisCity_MapScript2_WarpTable: @ 81E58DB
	map_script_2 VAR_CROSS_MAP_TRIGGER, 2, SootopolisCity_EventScript_FlyFromPillar
	map_script_2 VAR_RAYQUAZA_STATE, 5, SootopolisCity_EventScript_1E58E5
	.2byte 0

SootopolisCity_EventScript_FlyFromPillar:
	callnative HidePlayerOnLoad
	turnobject EVENT_OBJ_ID_PLAYER, 1
	@ setvar VAR_CROSS_MAP_TRIGGER, 0
	end

SootopolisCity_EventScript_1E58E5:: @ 81E58E5
	compare VAR_SKY_PILLAR_STATE, 1
	call_if_eq SootopolisCity_EventScript_1E58FC
	compare VAR_SKY_PILLAR_STATE, 2
	call_if_eq SootopolisCity_EventScript_1E5901
	end
SootopolisCity_EventScript_1E58FC:: @ 81E58FC
	turnobject EVENT_OBJ_ID_PLAYER, 2
	return
SootopolisCity_EventScript_1E5901:: @ 81E5901
	turnobject EVENT_OBJ_ID_PLAYER, 2
	setvar VAR_SKY_PILLAR_STATE, 3
	return

@ -----------------------------------------------------

#define LID_GROUDON 9
#define LID_KYOGRE 10

SootopolisCity_MapScript2_FrameTable: @ 81E5914
	map_script_2 VAR_CROSS_MAP_TRIGGER, 2, SootopolisCity_EventScript_FlyIn
	map_script_2 VAR_RAYQUAZA_STATE, 1, SootopolisCity_EventScript_1E5926
	map_script_2 VAR_SKY_PILLAR_STATE, 1, SootopolisCity_EventScript_1E5BFE
	.2byte 0

SootopolisCity_EventScript_FlyIn:
	lockall
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	createvobject EVENT_OBJ_GFX_WALLY, 50, 44, 32
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_SetVisible
	waitmovement 0
	setvar VAR_CROSS_MAP_TRIGGER, 0
	releaseall
	end


SootopolisCity_EventScript_1E5926:: @ 81E5926
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_1E5A82
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_1E5A82
	goto SootopolisCity_EventScript_1E5946
	end

SootopolisCity_EventScript_1E5946:: @ 81E5946
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	setweather WEATHER_ALTERNATING
	doweather
	setvar VAR_0x8004, 0
	special sub_813B7D8
	waitstate
	applymovement LID_KYOGRE, Common_Movement_WalkInPlaceLeft
	applymovement LID_GROUDON, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_SlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_WaitSlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_RetreatRight
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_RetreatLeft
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_WaitSlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_SlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_RetreatRight
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_RetreatLeft
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_SlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_WaitSlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_RetreatRight
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_RetreatLeft
	waitmovement 0
	special SpawnCameraObject
	applymovement LID_KYOGRE, SootopolisCity_Movement_1E5BD6
	applymovement LID_GROUDON, SootopolisCity_Movement_1E5BF7
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A75
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_RAYQUAZA_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end
SootopolisCity_Movement_1E5A68: @ 81E5A68
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end
SootopolisCity_Movement_1E5A75: @ 81E5A75
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	step_end


SootopolisCity_EventScript_1E5A82:: @ 81E5A82
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	setweather WEATHER_ALTERNATING
	doweather
	setvar VAR_0x8004, 0
	special sub_813B7D8
	waitstate
	applymovement LID_KYOGRE, Common_Movement_WalkInPlaceLeft
	applymovement LID_GROUDON, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 60
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_SlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_WaitSlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_RetreatRight
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_RetreatLeft
	waitmovement 0
	waitse
	playmoncry SPECIES_GROUDON, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_WaitSlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_SlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_RetreatRight
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_RetreatLeft
	waitmovement 0
	waitse
	playmoncry SPECIES_KYOGRE, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_SlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_WaitSlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_RetreatRight
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_RetreatLeft
	waitmovement 0
	special SpawnCameraObject
	applymovement LID_KYOGRE, SootopolisCity_Movement_1E5BD6
	applymovement LID_GROUDON, SootopolisCity_Movement_1E5BF7
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BAE
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_RAYQUAZA_STATE, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	releaseall
	end
SootopolisCity_Movement_1E5BA4: @ 81E5BA4
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
SootopolisCity_Movement_1E5BAE: @ 81E5BAE
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end
SootopolisCity_Movement_Kyogre_SlamLeft: @ 81E5BB8
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end
SootopolisCity_Movement_Kyogre_WaitSlamLeft: @ 81E5BC2
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	init_affine_anim
	walk_left_affine
	clear_affine_anim
	step_end
SootopolisCity_Movement_Kyogre_RetreatRight: @ 81E5BCF
	lock_facing_direction
	walk_right
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end
SootopolisCity_Movement_1E5BD6: @ 81E5BD6
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	walk_in_place_slow_left
	step_end
SootopolisCity_Movement_Groudon_SlamRight: @ 81E5BDD
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end
SootopolisCity_Movement_Groudon_WaitSlamRight: @ 81E5BE5
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_fast_right
	step_end
SootopolisCity_Movement_Groudon_RetreatLeft: @ 81E5BF0
	lock_facing_direction
	walk_left
	delay_16
	delay_16
	delay_16
	unlock_facing_direction
	step_end
SootopolisCity_Movement_1E5BF7: @ 81E5BF7
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	walk_in_place_slow_right
	step_end


SootopolisCity_TriggerScript_FightLegendaries::
	lock
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	
	waitse
	playmoncry SPECIES_KYOGRE, 2
	delay 30
	playmoncry SPECIES_GROUDON, 2
	applymovement LID_KYOGRE, SootopolisCity_Movement_Kyogre_SlamLeft
	applymovement LID_GROUDON, SootopolisCity_Movement_Groudon_SlamRight
	waitmovement 0
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	delay 10
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	callnative BattleSetup_StartLegendaryRageBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	@ If we get here, the player likely won, but if not...
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, B_OUTCOME_WON
	goto_if_ne Common_EventScript_ReleaseEnd
	@ The player won somehow!
	@ See the OnResume FLAG_SYS_CTRL_OBJ_DELETE for deleting the legendaries
	@ Fade out the weather
	setweather WEATHER_NONE
	doweather
	special WaitWeather
	waitstate
	@ Clean up, warp to normal city
	clearflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY
	setvar VAR_SKY_PILLAR_STATE, 10
	setvar VAR_RAYQUAZA_STATE, 5
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	setflag FLAG_LEGENDARIES_CLEARED
	fadenewbgm MUS_RUNECITY
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, VAR_INTERACT_X, VAR_INTERACT_Y
	waitstate
	end

#undef LID_GROUDON
#undef LID_KYOGRE

@ -----------------------------------------------------

SootopolisCity_EventScript_1E5BFE:: @ 81E5BFE
	lockall
	special StorePlayerCoordsInVars
	compare VAR_0x8004, 43
	goto_if_ne SootopolisCity_EventScript_1E5CCE
	compare VAR_0x8005, 32
	goto_if_ne SootopolisCity_EventScript_1E5CCE
	goto SootopolisCity_EventScript_1E5C1E
	end

SootopolisCity_EventScript_1E5C1E:: @ 81E5C1E
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5A68
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_RemoveLegendaryPedistals
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special sub_813B7D8
	waitstate
	playse SE_T_KAMI
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5E63
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special DoCameraShakeEffect
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 3
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	setflag FLAG_LEGENDARIES_CLEARED
	fadenewbgm MUS_RUNECITY
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, 43, 32
	waitstate
	end

SootopolisCity_EventScript_1E5CCE:: @ 81E5CCE
	delay 60
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5BA4
	waitmovement 0
	special RemoveCameraObject
	delay 60
	fadescreenspeed 1, 8
	call SootopolisCity_EventScript_RemoveLegendaryPedistals
	removeobject 9
	removeobject 10
	addobject 11
	setvar VAR_0x8004, 1
	special sub_813B7D8
	waitstate
	special SpawnCameraObject
	applymovement EVENT_OBJ_ID_CAMERA, SootopolisCity_Movement_1E5E63
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E5E68
	waitmovement 0
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 3
	special DoCameraShakeEffect
	waitstate
	waitse
	playmoncry SPECIES_RAYQUAZA, 2
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	waitmoncry
	setweather WEATHER_NONE
	doweather
	applymovement 11, SootopolisCity_Movement_1E5E5B
	waitmovement 0
	removeobject 11
	special WaitWeather
	waitstate
	clearflag FLAG_SYS_WEATHER_CTRL
	setvar VAR_SKY_PILLAR_STATE, 2
	clearflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	setflag FLAG_LEGENDARIES_CLEARED
	fadenewbgm MUS_NAMINORI
	delay 120
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	warp8 MAP_SOOTOPOLIS_CITY, 255, 29, 53
	waitstate
	end

SootopolisCity_EventScript_RemoveLegendaryPedistals:: @ 81E5D82
	setmetatile 27, 43, 656, 0
	setmetatile 28, 43, 656, 0
	setmetatile 29, 43, 656, 0
	setmetatile 30, 43, 656, 0
	setmetatile 27, 44, 656, 0
	setmetatile 28, 44, 656, 0
	setmetatile 29, 44, 656, 0
	setmetatile 30, 44, 656, 0
	setmetatile 27, 45, 656, 0
	setmetatile 28, 45, 656, 0
	setmetatile 29, 45, 656, 0
	setmetatile 30, 45, 656, 0
	setmetatile 32, 43, 656, 0
	setmetatile 33, 43, 656, 0
	setmetatile 34, 43, 656, 0
	setmetatile 35, 43, 656, 0
	setmetatile 32, 44, 656, 0
	setmetatile 33, 44, 656, 0
	setmetatile 34, 44, 656, 0
	setmetatile 35, 44, 656, 0
	setmetatile 32, 45, 656, 0
	setmetatile 33, 45, 656, 0
	setmetatile 34, 45, 656, 0
	setmetatile 35, 45, 656, 0
	return

SootopolisCity_Movement_1E5E5B: @ 81E5E5B
	walk_fast_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	walk_fastest_up
	step_end

SootopolisCity_Movement_1E5E63: @ 81E5E63
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5E68: @ 81E5E68
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E5E6D: @ 81E5E6D
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SootopolisCity_Movement_1E5E72: @ 81E5E72
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_1E5E7F: @ 81E5E7F
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_slow_diag_southwest
	walk_slow_diag_southwest
	step_end

@ -----------------------------------------------------
@ Signs

SootopolisCity_EventScript_1E614B:: @ 81E614B
	msgbox SootopolisCity_Text_1E656F, MSGBOX_SIGN
	end
SootopolisCity_Text_1E656F: @ 81E656F
	.string "{GYM}Sootopolis City Pokémon Gym{END}\n"
	.string "{GYM}Leader:{END} Juan\p"
	.string "“The Gym Leader with the beauty\n"
	.string "of pure water!”$"


SootopolisCity_EventScript_1E6154:: @ 81E6154
	msgbox SootopolisCity_Text_1E65C8, MSGBOX_SIGN
	end
SootopolisCity_Text_1E65C8: @ 81E65C8
	.string "{PLACE}Sootopolis City{END}\p"
	.string "“The mystical city where history\n"
	.string "slumbers.”$"


EventScript_ClosedSootopolisDoor:: @ 81E615D
	callnative HashInteractLocation
	selectpointer_wrap SootopolisCity_TextArray_ClosedDoor, VAR_0x8000
	msgbox_selected MSGBOX_DESCRIBE
	end

.align 2
SootopolisCity_TextArray_ClosedDoor:
	.4byte SootopolisCity_Text_ClosedDoor1
	.4byte SootopolisCity_Text_ClosedDoor2
	.4byte SootopolisCity_Text_ClosedDoor3
	.4byte SootopolisCity_Text_ClosedDoor4
	.4byte SootopolisCity_Text_ClosedDoor5
	.4byte SootopolisCity_Text_ClosedDoor6
	.4byte SootopolisCity_Text_ClosedDoor7
	.4byte 0
SootopolisCity_Text_ClosedDoor1: @ 81E6604
	.string "The door is shut tight.$"
SootopolisCity_Text_ClosedDoor2:
	.string "The door seems to be barricaded.$"
SootopolisCity_Text_ClosedDoor3:
	.string "There's wooden planks over the windows.$"
SootopolisCity_Text_ClosedDoor4:
	.string "You hear hammering at the door.\n"
	.string "Sounds like they're boarding up.$"
SootopolisCity_Text_ClosedDoor5:
	.string "You try the door handle.\n"
	.string "It doesn't budge.$"
SootopolisCity_Text_ClosedDoor6:
	.string "You can barely tell that the door is\n"
	.string "boarded up from the inside.$"
SootopolisCity_Text_ClosedDoor7:
	.string "It looks like the back of a dresser\n"
	.string "is shoved against the door.$"


@ -----------------------------------------------------
@ People

SootopolisCity_EventScript_CaveOfOriginMan:: @ 81E5E8D
	lock
	faceplayer
	markasdialog
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5EC4
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E5ECE
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_ge SootopolisCity_EventScript_1E5EBA
	msgbox SootopolisCity_Text_1E6D77, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6D77: @ 81E6D77
	.string "Who might you be?\p"
	.string "This is the Cave of Origin.\p"
	.string "The spirits of Pokémon, becalmed at\n"
	.string "Mt. Pyre, are said to be revived here.\p"
	.string "Please leave.$"
SootopolisCity_EventScript_1E5EBA:: @ 81E5EBA
	msgbox SootopolisCity_Text_1E6DFE, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6DFE: @ 81E6DFE
	.string "A person with a strong will and\n"
	.string "superior talent…\p"
	.string "A trainer who has knowledge and\n"
	.string "experience of many kinds of Pokémon…\p"
	.string "If such a person were to appear, I was\n"
	.string "instructed by Wallace to lead that\l"
	.string "trainer to this cave.$"
SootopolisCity_EventScript_1E5EC4:: @ 81E5EC4
	msgbox SootopolisCity_Text_1E6F38, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6F38: @ 81E6F38
	.string "This is the Cave of Origin…\p"
	.string "With the passing of the crisis,\n"
	.string "the cave, too, shall sleep…$"
SootopolisCity_EventScript_1E5ECE:: @ 81E5ECE
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E5ECG
	msgbox SootopolisCity_Text_1E6ED4, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6ED4: @ 81E6ED4
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "Pokémon was quelled by the awakening\l"
	.string "of a third Pokémon…$"
SootopolisCity_EventScript_1E5ECG:
	msgbox SootopolisCity_Text_1E6ED5, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6ED5: @ 81E6ED4
	.string "Oh, my…\p"
	.string "The clash between the two awakened\n"
	.string "Pokémon… you managed to quell it all\l"
	.string "by yourself! I'm in awe.$"
	



SootopolisCity_EventScript_Kiri:: @ 81E5ED8
	lock
	faceplayer
	markasdialog
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E5F1B
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E5F1B
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E5F10
	msgbox SootopolisCity_Text_1E6BFF, MSGBOX_DEFAULT
	closemessage
	applymovement 3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SootopolisCity_Text_1E6BFF: @ 81E6BFF
	.string "A big Pokémon is fighting with\n"
	.string "another big Pokémon!\p"
	.string "Please, someone make them stop!$"
SootopolisCity_EventScript_1E5F10:: @ 81E5F10
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E5F11
	msgbox SootopolisCity_Text_1E6C53, MSGBOX_DEFAULT
	closemessage
	release
	end
SootopolisCity_Text_1E6C53: @ 81E6C53
	.string "A pretty Pokémon came down from\n"
	.string "the sky…$"
SootopolisCity_EventScript_1E5F11:: @ 81E5F10
	msgbox SootopolisCity_Text_1E6C54, MSGBOX_DEFAULT
	closemessage
	release
	end
SootopolisCity_Text_1E6C54: @ 81E6C53
	.string "Wow, {PLAYER_sir}!\n"
	.string "You beat up those big Pokémon…$"
SootopolisCity_EventScript_1E5F1B:: @ 81E5F1B
	dotimebasedevents
	goto_if_set FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY, SootopolisCity_EventScript_1E5FBB
	msgbox SootopolisCity_Text_2A7BB0, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, 20
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_SOOTOPOLIS_RECEIVED_BERRY
	msgbox SootopolisCity_Text_2A7C7C, MSGBOX_DEFAULT
	random 2
	compare VAR_RESULT, 0
	goto_if_eq SootopolisCity_EventScript_1E5F79
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_1E5F9A
	end
SootopolisCity_Text_2A7BB0: @ 82A7BB0
	.string "Hi, what's your name?\p"
	.string "… … …  … … …  … … …\n"
	.string "Okay. That's nice!\p"
	.string "My name is Kiri.\p"
	.string "My mommy and daddy named me that so\n"
	.string "I would grow healthy and warmhearted.\l"
	.string "That's what they wished.\p"
	.string "You can have one of these.$"
SootopolisCity_Text_2A7C7C: @ 82A7C7C
	.string "Kiri will give you this berry, too!\n"
	.string "I really like it lots!$"
SootopolisCity_EventScript_1E5F79:: @ 81E5F79
	giveitem_std ITEM_FIGY_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_2A7CB7, MSGBOX_DEFAULT
	release
	end
SootopolisCity_EventScript_1E5F9A:: @ 81E5F9A
	giveitem_std ITEM_IAPAPA_BERRY
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Text_2A7CB7, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_2A7CB7: @ 82A7CB7
	.string "I wonder what kind of wish is included\n"
	.string "in your name.$"
SootopolisCity_EventScript_1E5FBB:: @ 81E5FBB
	msgbox SootopolisCity_Text_2A7CEC, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SootopolisCity_EventScript_1E5FD8
	msgbox SootopolisCity_Text_2A7DD2, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_2A7CEC: @ 82A7CEC
	.string "Spring, summer, autumn, and winter.\p"
	.string "If you're born in springtime, do you like\n"
	.string "the spring, and if you're born in the\l"
	.string "summer, do you like the summer?$"
SootopolisCity_Text_2A7DD2: @ 82A7DD2
	.string "Oh…\n"
	.string "It doesn't matter…\p"
	.string "There's so much that I want to know…$"
SootopolisCity_EventScript_1E5FD8:: @ 81E5FD8
	msgbox SootopolisCity_Text_2A7D80, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_2A7D80: @ 82A7D80
	.string "Then Kiri was born in the autumn,\n"
	.string "so I love the autumn!\p"
	.string "Which season do you like?$"



SootopolisCity_EventScript_1E5FE2:: @ 81E5FE2
	lockall
	markasdialog
	applymovement THIS_EVENT, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E600D
	msgbox SootopolisCity_Text_1E71A1, MSGBOX_DEFAULT
	closemessage
	applymovement THIS_EVENT, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
SootopolisCity_Text_1E71A1: @ 81E71A1
	.string "The weather was clear this morning,\n"
	.string "but…\p"
	.string "All of a sudden, dark clouds brewed up,\n"
	.string "rain started falling in sheets, and\l"
	.string "there was thunder and lightning, too.\p"
	.string "The weather just went completely\n"
	.string "wild!\p"
	.string "Is all of this because of those\n"
	.string "Pokémon?$"
SootopolisCity_EventScript_1E600D:: @ 81E600D
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E600G
	msgbox SootopolisCity_Text_1E728C, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E728C: @ 81E728C
	.string "Oh?\p"
	.string "It was you who brought that flying\n"
	.string "Pokémon here?\p"
	.string "Well, aren't you amazing!$"
SootopolisCity_EventScript_1E600G:: @ 81E600D
	msgbox SootopolisCity_Text_1E728H, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E728H: @ 81E728C
	.string "Oh?\p"
	.string "It was you who slew the giant\n"
	.string "Pokémon singlehandedly?\p"
	.string "Well, aren't you amazing!$"



SootopolisCity_EventScript_1E6017:: @ 81E6017
	lock
	faceplayer
	markasdialog
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E602E
	msgbox SootopolisCity_Text_1E6CCA, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6CCA: @ 81E6CCA
	.string "Hm!\n"
	.string "You've come all the way to Sootopolis?\l"
	.string "You're no ordinary tourist.\p"
	.string "But I suppose that doesn't make you\n"
	.string "an extraordinary tourist, either.$"
SootopolisCity_EventScript_1E602E:: @ 81E602E
	msgbox SootopolisCity_Text_1E6D57, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6D57: @ 81E6D57
	.string "The city has regained its calm…$"



SootopolisCity_EventScript_1E6038:: @ 81E6038
	lock
	faceplayer
	markasdialog
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E607A
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6084
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_ge SootopolisCity_EventScript_1E6065
	msgbox SootopolisCity_Text_1E6F90, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6F90: @ 81E6F90
	.string "Sootopolis sprang up as a town in\n"
	.string "the crater of a volcano.\p"
	.string "If you look up at the sky, the lip of\n"
	.string "the crater is also visible.\l"
	.string "So, all you see is the sky in a circle.\p"
	.string "But that's what makes the sky above\n"
	.string "Sootopolis the most beautiful.$"
SootopolisCity_EventScript_1E607A:: @ 81E607A
	msgbox SootopolisCity_Text_1E710B, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E710B: @ 81E710B
	.string "A circle of a night sky framed by\n"
	.string "the crater of a volcano…\p"
	.string "And in that ring, stars flicker and\n"
	.string "blink as if they were alive…\l"
	.string "It's my favorite scenery.$"
SootopolisCity_EventScript_1E6084:: @ 81E6084
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E6084H
	msgbox SootopolisCity_Text_1E70D4, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E70D4: @ 81E70D4
	.string "When that third Pokémon flew down,\n"
	.string "I feared the worst.$"
SootopolisCity_EventScript_1E6084H:: @ 81E6084
	msgbox SootopolisCity_Text_1E70D5, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E70D5: @ 81E70D4
	.string "When I saw you heading out into the\n"
	.string "middle of the crater by yourself,\l"
	.string "I feared the worst.$"
SootopolisCity_EventScript_1E6065:: @ 81E6065
	msgbox SootopolisCity_Text_1E7078, MSGBOX_DEFAULT
	closemessage
	applymovement 8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SootopolisCity_Text_1E7078: @ 81E7078
	.string "When two Pokémon that gigantic\n"
	.string "are fighting that savagely, there's\l"
	.string "not much that we can do.$"



SootopolisCity_EventScript_1E608E:: @ 81E608E
	lockall
	markasdialog
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E60D9
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E60CF
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E60CF
	msgbox SootopolisCity_Text_1E690B, MSGBOX_DEFAULT
	closemessage
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SootopolisCity_Text_1E690B: @ 81E690B
	.string "Wow!\n"
	.string "This is wicked!$"
SootopolisCity_EventScript_1E60D9:: @ 81E60D9
	msgbox SootopolisCity_Text_1E6920, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6920: @ 81E6920
	.string "Wow!\n"
	.string "That was wicked!$"
SootopolisCity_EventScript_1E60CF:: @ 81E60CF
	msgbox SootopolisCity_Text_1E68A1, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E68A1: @ 81E68A1
	.string "I… I've never been out of this city.\p"
	.string "I wonder what the world is like on\n"
	.string "the other side of this round sky?$"



SootopolisCity_EventScript_1E60E3:: @ 81E60E3
	lockall
	markasdialog
	applymovement 5, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E612D
	goto_if_set FLAG_SYS_GAME_CLEAR, SootopolisCity_EventScript_1E6137
	compare VAR_RAYQUAZA_STATE, 6
	goto_if_ge SootopolisCity_EventScript_1E6141
	compare VAR_RAYQUAZA_STATE, 1
	goto_if_le SootopolisCity_EventScript_1E6141
	msgbox SootopolisCity_Text_1E6692, MSGBOX_DEFAULT
	closemessage
	applymovement 5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SootopolisCity_Text_1E6692: @ 81E6692
	.string "These giant Pokémon suddenly appeared\n"
	.string "in the middle of the city!\p"
	.string "And, I've never seen them before!\p"
	.string "Why are they smashing into each\n"
	.string "other like that?\p"
	.string "Why can't they be friends, those\n"
	.string "Pokémon?$"
SootopolisCity_EventScript_1E612D:: @ 81E612D
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E612G
	msgbox SootopolisCity_Text_1E6750, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6750: @ 81E6750
	.string "What? What? What?\n"
	.string "What is that green Pokémon?!$"
SootopolisCity_EventScript_1E612G:: @ 81E612D
	msgbox SootopolisCity_Text_1E6755, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6755: @ 81E6750
	.string "What? What? What?\n"
	.string "All by yourself?! What?!$"
SootopolisCity_EventScript_1E6137:: @ 81E6137
	msgbox SootopolisCity_Text_1E677F, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E677F: @ 81E677F
	.string "Groudon and Kyogre…\n"
	.string "Where did they go?\p"
	.string "Will they cause droughts or downpours\n"
	.string "somewhere else?$"
SootopolisCity_EventScript_1E6141:: @ 81E6141
	msgbox SootopolisCity_Text_1E6618, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E6618: @ 81E6618
	.string "Diving in the sea. Climbing up and\n"
	.string "down stairs all the time…\p"
	.string "If you live in this town, you end up\n"
	.string "getting physically fit.$"



SootopolisCity_EventScript_1E635D:: @ 81E635D
	lockall
	markasdialog
	applymovement 15, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6388
	msgbox SootopolisCity_Text_1E67DC, MSGBOX_DEFAULT
	closemessage
	applymovement 15, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
SootopolisCity_Text_1E67DC: @ 81E67DC
	.string "I just get this sense somehow that\n"
	.string "the two Pokémon aren't angry.\p"
	.string "I think… They probably can't control\n"
	.string "their own power…$"
SootopolisCity_EventScript_1E6388:: @ 81E6388
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E6389
	msgbox SootopolisCity_Text_1E6853, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
SootopolisCity_Text_1E6853: @ 81E6853
	.string "That flying Pokémon came down from\n"
	.string "the sky and stopped the rampaging\l"
	.string "Pokémon…$"
SootopolisCity_EventScript_1E6389:: @ 81E6388
	msgbox SootopolisCity_Text_1E6854, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
SootopolisCity_Text_1E6854: @ 81E6853
	.string "How you managed to stop the rampaging\n"
	.string "Pokémon… I'll never know…$"



SootopolisCity_EventScript_1E6393:: @ 81E6393
	lockall
	markasdialog
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E63C7
	msgbox SootopolisCity_Text_1E6936, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SootopolisCity_Text_1E696C, MSGBOX_DEFAULT
	closemessage
	applymovement 14, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
SootopolisCity_Text_1E6936: @ 81E6936
	.string "Go for it, red Pokémon!\n"
	.string "Don't back off, blue Pokémon!$"
SootopolisCity_Text_1E696C: @ 81E696C
	.string "… … … … … …\p"
	.string "Hi, do you know the names of those\n"
	.string "Pokémon fighting over there?$"
SootopolisCity_EventScript_1E63C7:: @ 81E63C7
	applymovement 14, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, SootopolisCity_EventScript_1E63C8
	msgbox SootopolisCity_Text_1E69B8, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E69B8: @ 81E69B8
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "it's the green one that settles things!\p"
	.string "Talk about a huge turn of events!$"
SootopolisCity_EventScript_1E63C8:: @ 81E63C7
	msgbox SootopolisCity_Text_1E69B9, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E69B9: @ 81E69B8
	.string "I was wondering which one would win,\n"
	.string "the red one or the blue one, but, oh no,\l"
	.string "you had to go and ruin it by beating\l"
	.string "them up all by yourself!\p"
	.string "Thanks, party pooper!$"



SootopolisCity_EventScript_1E63DB:: @ 81E63DB
	lockall
	markasdialog
	applymovement 13, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6406
	msgbox SootopolisCity_Text_1E6C7C, MSGBOX_DEFAULT
	closemessage
	applymovement 13, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
SootopolisCity_Text_1E6C7C: @ 81E6C7C
	.string "Oh, no!\n"
	.string "Sootopolis City will get wrecked!$"
SootopolisCity_EventScript_1E6406:: @ 81E6406
	msgbox SootopolisCity_Text_1E6CA6, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
SootopolisCity_Text_1E6CA6: @ 81E6CA6
	.string "Sootopolis City didn't get wrecked!\p"
	.string "Well, except for the Pokémon Center…\n"
	.string "Its roof is in shambles…$"



SootopolisCity_EventScript_1E6411:: @ 81E6411
	lockall
	markasdialog
	applymovement 12, Common_Movement_FacePlayer
	waitmovement 0
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E643C
	msgbox SootopolisCity_Text_1E6A50, MSGBOX_DEFAULT
	closemessage
	applymovement 12, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end
SootopolisCity_Text_1E6A50: @ 81E6A50
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between Pokémon.\p"
	.string "Well, I'm seeing that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"
SootopolisCity_EventScript_1E643C:: @ 81E643C
	msgbox SootopolisCity_Text_1E6B2A, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E6B2A: @ 81E6B2A
	.string "There's an ancient legend that claims\n"
	.string "the land and sea were shaped by\l"
	.string "a colossal battle between Pokémon.\p"
	.string "Well, I saw that happen with\n"
	.string "my very own eyes!\p"
	.string "Whoa! I never expected to be\n"
	.string "witness to something this huge!$"





@ -----------------------------------------------------


SootopolisCity_EventScript_1E6166:: @ 81E6166
	lockall
	markasdialog
	applymovement 7, Common_Movement_FacePlayer
	waitmovement 0
	call_if_unset FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN, SootopolisCity_EventScript_1E61CC
	compare VAR_RAYQUAZA_STATE, 2
	goto_if_eq SootopolisCity_EventScript_1E61AE
	compare VAR_RAYQUAZA_STATE, 3
	goto_if_eq SootopolisCity_EventScript_1E61C2
	compare VAR_RAYQUAZA_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E61C2
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E61B8
	msgbox SootopolisCity_Text_1E78E5, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E78E5: @ 81E78E5
	.string "Steven: So that's Rayquaza…\p"
	.string "It's incredible how the two rampaging\n"
	.string "Pokémon would flee from it in fear…$"

SootopolisCity_EventScript_1E61AE:: @ 81E61AE
	msgbox SootopolisCity_Text_1E7866, MSGBOX_DEFAULT
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setflag FLAG_HIDE_CAVE_OF_ORIGIN_B1F_WALLACE
	setvar VAR_RAYQUAZA_STATE, 3
	releaseall
	end
SootopolisCity_Text_1E7866: @ 81E7866
	.string "Steven: Excuse me, who are you…?\n"
	.string "Are you {RIVAL_HERO}'s friend?\p"
	.string "He went searching for the {PLACE}Sky Pillar{END}.\p"
	.string "He hopes to find an ancient Pokémon\n"
	.string "at the top who can help quell the\l"
	.string "fighting of these legendary beasts.$"

SootopolisCity_EventScript_1E61B8:: @ 81E61B8
	msgbox SootopolisCity_Text_1E794B, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E794B: @ 81E794B
	.string "Steven: It looks like both Maxie and\n"
	.string "Archie have gone away somewhere.\p"
	.string "Perhaps they've gone to Mt. Pyre to\n"
	.string "return those orbs…$"

SootopolisCity_EventScript_1E61C2:: @ 81E61C2
	msgbox SootopolisCity_Text_1E789A, MSGBOX_DEFAULT
	releaseall
	end
SootopolisCity_Text_1E789A: @ 81E789A
	.string "Steven: The Sky Pillar…\p"
	.string "I've never been there.\n"
	.string "I wonder where it could be?$"

SootopolisCity_EventScript_1E61CC:: @ 81E61CC
	@ msgbox SootopolisCity_Text_1E75CB, MSGBOX_DEFAULT
	@ closemessage
	@ compare VAR_FACING, 3
	@ call_if_eq SootopolisCity_EventScript_1E6243
	@ compare VAR_FACING, 2
	@ call_if_eq SootopolisCity_EventScript_1E6255
	@ msgbox SootopolisCity_Text_1E7737, MSGBOX_DEFAULT
	@ closemessage
	@ applymovement 7, SootopolisCity_Movement_1E62D4
	@ applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E630E
	@ waitmovement 0
	@ delay 120
	@ applymovement 1, SootopolisCity_Movement_1E6341
	@ waitmovement 0
	@ applymovement 7, SootopolisCity_Movement_1E6344
	@ applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E634F
	@ waitmovement 0
	@ msgbox SootopolisCity_Text_1E77F0, MSGBOX_DEFAULT
	@ closemessage
	@ setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	@ applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E635A
	@ waitmovement 0
	@ warp MAP_CAVE_OF_ORIGIN_ENTRANCE, 255, 9, 20
	@ waitstate
	end
@ SootopolisCity_Text_1E75CB: @ 81E75CB
@ 	.string "STEVEN: Those Pokémon fighting…\n"
@ 	.string "GROUDON… And KYOGRE…\p"
@ 	.string "The two super-ancient Pokémon\n"
@ 	.string "were awakened from a long sleep…\p"
@ 	.string "And now they are smashing each other\n"
@ 	.string "with their uncontrollable energy…\p"
@ 	.string "…{PLAYER}.\p"
@ 	.string "You being here now I'll take to mean\n"
@ 	.string "that you're prepared to become\l"
@ 	.string "involved in this crisis.\p"
@ 	.string "Well, then, there's someone that\n"
@ 	.string "I'd like you to meet.\p"
@ 	.string "Come with me, please.$"
@ SootopolisCity_Text_1E7737: @ 81E7737
@ 	.string "STEVEN: Listen, {PLAYER}.\p"
@ 	.string "Does seeing GROUDON and KYOGRE make\n"
@ 	.string "you think Pokémon are to be feared?\p"
@ 	.string "But that's not true.\n"
@ 	.string "Pokémon are really more…\p"
@ 	.string "…Why am I asking you this?\n"
@ 	.string "You already know.$"
@ SootopolisCity_Text_1E77F0: @ 81E77F0
@ 	.string "STEVEN: Okay, here we are!\p"
@ 	.string "Inside here you'll find someone named\n"
@ 	.string "WALLACE.\p"
@ 	.string "I think you have what's needed to\n"
@ 	.string "help him…$"


SootopolisCity_EventScript_1E6243:: @ 81E6243
	applymovement 7, SootopolisCity_Movement_1E6267
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E628C
	waitmovement 0
	return

SootopolisCity_EventScript_1E6255:: @ 81E6255
	applymovement 7, SootopolisCity_Movement_1E6267
	applymovement EVENT_OBJ_ID_PLAYER, SootopolisCity_Movement_1E62B0
	waitmovement 0
	return

SootopolisCity_Movement_1E6267: @ 81E6267
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_1E628C: @ 81E628C
	walk_left
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E62B0: @ 81E62B0
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E62D4: @ 81E62D4
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	delay_4
	walk_in_place_fastest_left
	delay_16
	delay_16
	walk_right
	walk_up
	walk_up
	step_end

SootopolisCity_Movement_1E630E: @ 81E630E
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SootopolisCity_Movement_1E6341: @ 81E6341
	walk_slow_left
	walk_in_place_fastest_right
	step_end

SootopolisCity_Movement_1E6344: @ 81E6344
	walk_down
	walk_down
	walk_left
	delay_8
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_fastest_left
	step_end

SootopolisCity_Movement_1E634F: @ 81E634F
	delay_16
	delay_16
	delay_16
	delay_8
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

SootopolisCity_Movement_1E635A: @ 81E635A
	walk_up
	walk_up
	step_end




SootopolisCity_EventScript_1E6446:: @ 81E6446
	lock
	faceplayer
	markasdialog
	compare VAR_RAYQUAZA_STATE, 4
	goto_if_eq SootopolisCity_EventScript_1E64D8
	goto_if_set FLAG_RECEIVED_TM57, SootopolisCity_EventScript_1E64E2
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, SootopolisCity_EventScript_1E646F
	msgbox SootopolisCity_Text_1E7A3E, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E7A3E: @ 81E7A3E
	.string "Wallace: The leaders of Team Magma and\n"
	.string "Aqua, I don't think they meant harm.\p"
	.string "It wouldn't hurt to hear what they\n"
	.string "have to say for themselves.$"

SootopolisCity_EventScript_1E646F:: @ 81E646F
	msgbox SootopolisCity_Text_1E7ACF, MSGBOX_DEFAULT
	giveitem_std ITEM_TM57
	setflag FLAG_RECEIVED_TM57
	msgbox SootopolisCity_Text_1E7B86, MSGBOX_DEFAULT
	closemessage
	compare VAR_FACING, 2
	call_if_eq SootopolisCity_EventScript_1E64B2
	compare VAR_FACING, 4
	call_if_eq SootopolisCity_EventScript_1E64B2
	compare VAR_FACING, 3
	call_if_eq SootopolisCity_EventScript_1E64C5
	release
	end
SootopolisCity_Text_1E7ACF: @ 81E7ACF
	.string "Wallace: {RIVAL_HERO}…\n"
	.string "My eyes didn't deceive me…\l"
	.string "Even without my contacts…\p"
	.string "Thanks to your help, Sootopolis…\n"
	.string "No, all of Hoenn was saved.\p"
	.string "On behalf of the people, I thank you.\p"
	.string "This is a gift from me.\n"
	.string "Please accept it.$"
SootopolisCity_Text_1E7B86: @ 81E7B86
	.string "That Technical Machine contains\n"
	.string "Waterfall.\p"
	.string "It allows a Pokémon to use their natural\n"
	.string "waterfall-climbing ability in-battle.\p"
	.string "But of course, they can only harness that\n"
	.string "ability if you have the Rain Badge.\p"
	.string "And where does one get the Rain Badge?\n"
	.string "You know, don't you?\p"
	.string "That's right! You have to beat\n"
	.string "the Sootopolis Gym Leader.\p"
	.string "When you're all set to go, step through\n"
	.string "that door.$"

SootopolisCity_EventScript_1E64B2:: @ 81E64B2
	applymovement 18, SootopolisCity_Movement_1E64EC
	waitmovement 0
	moveobjectoffscreen 18
	setvar VAR_SOOTOPOLIS_STATE, 1
	return

SootopolisCity_EventScript_1E64C5:: @ 81E64C5
	applymovement 18, SootopolisCity_Movement_1E64EF
	waitmovement 0
	moveobjectoffscreen 18
	setvar VAR_SOOTOPOLIS_STATE, 2
	return

SootopolisCity_EventScript_1E64D8:: @ 81E64D8
	msgbox SootopolisCity_Text_1E79C8, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E79C8: @ 81E79C8
	.string "WALLACE: Oh?\n"
	.string "{RIVAL_HERO}?\p"
	.string "Haven't you scaled the Sky Pillar\n"
	.string "yet?\p"
	.string "I can't see anything… I lost\n"
	.string "my contacts in the Cave of Origin.$"

SootopolisCity_EventScript_1E64E2:: @ 81E64E2
	msgbox SootopolisCity_Text_1E7CBC, MSGBOX_DEFAULT
	release
	end
SootopolisCity_Text_1E7CBC: @ 81E7CBC
	.string "Wallace: Hang on, you're not {RIVAL_HERO}.\n"
	.string "Who are you?\p"
	.string "Did I just give an inspiring speech\n"
	.string "to the wrong person?$"

SootopolisCity_Movement_1E64EC: @ 81E64EC
	walk_right
	walk_in_place_fastest_down
	step_end

SootopolisCity_Movement_1E64EF: @ 81E64EF
	walk_left
	walk_in_place_fastest_down
	step_end

SootopolisCity_EventScript_1E64F2:: @ 81E64F2
	lockall
	markasdialog
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6509
	msgbox SootopolisCity_Text_1E72DB, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
SootopolisCity_Text_1E72DB: @ 81E72DB
	.string "Maxie: G… Groudon…\n"
	.string "Please! Stop what you're doing!\p"
	.string "I know the extent of your power now!\p"
	.string "If you keep going, all Hoenn, not just\n"
	.string "Sootopolis, will be utterly ruined!$"

SootopolisCity_EventScript_1E6509:: @ 81E6509
	msgbox SootopolisCity_Text_1E737E, MSGBOX_DEFAULT
	setflag FLAG_MET_MAXIE_SOOTOPOLIS
	goto_if_set FLAG_MET_ARCHIE_SOOTOPOLIS, SootopolisCity_EventScript_1E654C
	releaseall
	end
SootopolisCity_Text_1E737E: @ 81E737E
	.string "Maxie: So the super-ancient Pokémon\n"
	.string "weren't only Groudon and Kyogre…\p"
	.string "After all our fruitless scheming and\n"
	.string "frantic efforts, that one Pokémon's\l"
	.string "simple action puts everything right\l"
	.string "again as if nothing had happened…\p"
	.string "Fu…\n"
	.string "Fuhahaha…$"

SootopolisCity_EventScript_1E651F:: @ 81E651F
	lockall
	markasdialog
	compare VAR_RAYQUAZA_STATE, 5
	goto_if_eq SootopolisCity_EventScript_1E6536
	msgbox SootopolisCity_Text_1E7460, MSGBOX_DEFAULT
	closemessage
	releaseall
	end
SootopolisCity_Text_1E7460: @ 81E7460
	.string "Archie: Kyogre! What's wrong?!\n"
	.string "Look over here! It's the Red Orb!\l"
	.string "Calm down! Kyogre!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "It's no good!\n"
	.string "It's not responding at all!$"

SootopolisCity_EventScript_1E6536:: @ 81E6536
	msgbox SootopolisCity_Text_1E74F6, MSGBOX_DEFAULT
	setflag FLAG_MET_ARCHIE_SOOTOPOLIS
	goto_if_set FLAG_MET_MAXIE_SOOTOPOLIS, SootopolisCity_EventScript_1E654C
	releaseall
	end
SootopolisCity_Text_1E74F6: @ 81E74F6
	.string "Archie: Oh, {PLAYER}.\p"
	.string "Kyogre and Groudon both flew off\n"
	.string "to who knows where.\p"
	.string "The weather in Hoenn has returned\n"
	.string "to its normal state…\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Haha…\n"
	.string "Hahaha…\p"
	.string "Maybe what we were trying to do was\n"
	.string "something small, even meaningless,\l"
	.string "to Pokémon…\p"
	.string "… … … … … …\n"
	.string "I'm dissolving the team.\p"
	.string "Please, get rid of that uniform…\p"
	.string "It doesn't suit you anymore.$"

SootopolisCity_EventScript_1E654C:: @ 81E654C
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	setflag FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	setvar VAR_MT_PYRE_STATE, 2
	warpsilent MAP_SOOTOPOLIS_CITY, 255, 31, 34
	waitstate
	releaseall
	end

SootopolisCity_Movement_1E656B:: @ 81E656B
	levitate
	step_end

SootopolisCity_Movement_1E656D:: @ 81E656D
	destroy_extra_task
	step_end








