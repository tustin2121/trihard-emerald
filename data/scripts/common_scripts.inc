Common_EventScript_NopReturn:: @ 827374E
	return

Common_EventScript_NopEnd::
	end
	
Common_EventScript_ReleaseEnd::
	release
	end
	
Common_EventScript_ReleaseAllEnd::
	releaseall
	end
	
Common_EventScript_CloseReleaseAllEnd::
	closemessage
	releaseall
	end

@ Emotes

Common_Movement_QuestionMark:: @ 8272596
	emote_question_mark
	step_end

Common_Movement_ExclamationMark:: @ 8272598
	emote_exclamation_mark
	step_end
	
Common_Movement_ExclamationMarkAndWait:: @ 8272598
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	step_end

Common_Movement_Angry: @ 8272598
	emote_angry
	step_end

Common_Movement_AngryAndWait:: @ 8272598
	emote_angry
	delay_16
	delay_16
	delay_16
	step_end

Common_Movement_AngryReaction: @ 8272598
	delay_16
	emote_exclamation_mark
	step_end

Common_Movement_Delay48: @ 827259A
	delay_16
	delay_16
	delay_16
	step_end

@ Movement

Common_Movement_NoOp:
	step_end

Common_Movement_FacePlayer: @ 827259E
	face_player
	step_end

Common_Movement_FaceAwayPlayer: @ 82725A0
	face_away_player
	step_end

Common_Movement_FaceOriginalDirection: @ 82725A2
	face_original_direction
	step_end

Common_Movement_WalkInPlaceLeft: @ 82725A4
	walk_in_place_fastest_left
	step_end

Common_Movement_WalkInPlaceUp: @ 82725A6
	walk_in_place_fastest_up
	step_end

Common_Movement_WalkInPlaceRight: @ 82725A8
	walk_in_place_fastest_right
	step_end

Common_Movement_WalkInPlaceDown: @ 82725AA
	walk_in_place_fastest_down
	step_end

Common_Movement_FaceRight: @ 82725AC
	face_right
	step_end

Common_Movement_FaceLeft: @ 82725AE
	face_left
	step_end

Common_Movement_FaceDown: @ 82725B0
	face_down
	step_end

Common_Movement_FaceUp: @ 82725B2
	face_up
	step_end

Common_Movement_BackOffUp1: @ 82725C9
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

Common_Movement_BackOffDown1:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

Common_Movement_BackOffLeft1:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

Common_Movement_BackOffRight1:
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end

Common_Movement_WalkUp1: @ 82725C9
	walk_up
	step_end

Common_Movement_WalkDown1:
	walk_down
	step_end

Common_Movement_WalkLeft1:
	walk_left
	step_end

Common_Movement_WalkRight1:
	walk_right
	step_end

Common_Movement_WalkUp2: @ 82725C9
	walk_up
	walk_up
	step_end

Common_Movement_WalkDown2:
	walk_down
	walk_down
	step_end

Common_Movement_WalkLeft2:
	walk_left
	walk_left
	step_end

Common_Movement_WalkRight2:
	walk_right
	walk_right
	step_end

Common_Movement_WalkUpOutOfFrame:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
Common_Movement_WalkDownOutOfFrame:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Common_Movement_KecleonShowAnim: @ 82723C7
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_4
	set_invisible
	delay_4
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_8
	set_invisible
	delay_8
	set_visible
	delay_16
	set_invisible
	delay_16
	set_visible
	step_end

@ Message Scripts

Common_EventScript_ShowBagIsFull:: @ 8272054
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end
Common_EventScript_BagIsFull:: @ 827205E
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	return
gText_TooBadBagIsFull:: @ 8272AD0
	.string "Too bad!\n"
	.string "The bag is full…$"

Common_EventScript_ShowPokemartSign:: @ 8271E6A
	msgbox gText_PokemartSign, MSGBOX_SIGN
	end
gText_PokemartSign:: @ 8272B6A
	.string "“Selected items for your convenience!”\n"
	.string "{PLACE}Pokémon Mart$"

Common_EventScript_ShowPokemonCenterSign:: @ 8271E73
	msgbox gText_PokemonCenterSign, MSGBOX_SIGN
	end
gText_PokemonCenterSign:: @ 8272B9E
	.string "“Rejuvenate your tired partners!”\n"
	.string "{PLACE}Pokémon Center$"

Common_EventScript_BattleTentClosed::
	msgbox gText_BattleTentClosed, MSGBOX_SIGN
	end
gText_BattleTentClosed:
	.string "{CENTER}Closed for Renovations$"


@ Music/Sound Scripts

Common_EventScript_StartBrineyBoatSequence:: @ 82720A0
	setflag FLAG_SPECIAL_FLAG_ON_BRINEYS_BOAT
	playbgm MUS_M_BOAT, 0
	return

Common_EventScript_EndBrineyBoatSequence:: @ 82720A8
	clearflag FLAG_SPECIAL_FLAG_ON_BRINEYS_BOAT
	fadedefaultbgm
	return

Common_EventScript_PlayGymBadgeFanfare:: @ 827207E
	playfanfare MUS_ME_BACHI
	waitfanfare
	return

Common_EventScript_PlayRivalMusic:: @ 81ECD11
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq Common_EventScript_PlayRivalMusic_Girl
	compare VAR_RESULT, FEMALE
	goto_if_eq Common_EventScript_PlayRivalMusic_Boy
	return
Common_EventScript_PlayRivalMusic_Girl: @ 81ECD29
	playbgm MUS_GIRL_SUP, 1
	return
Common_EventScript_PlayRivalMusic_Boy: @ 81ECD2E
	playbgm MUS_BOY_SUP, 1
	return

Common_EventScript_FadeMusicToMapMusic::
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

@ Scripts

Common_EventScript_HideMapNamePopup:: @ 8273D13
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

Common_EventScript_NameReceivedPokemon:: @ 82723DD
	fadescreen 1
	special ChangePokemonNickname
	waitstate
	return

Common_EventScript_SetWeatherAlternating:: @ 827207A
	setweather WEATHER_ALTERNATING
	return

Common_ShowEasyChatScreen:: @ 8271E7C
	fadescreen 1
	special ShowEasyChatScreen
	fadescreen 0
	return

Common_EventScript_ViewWallClock:: @ 829283F
	incrementgamestat GAME_STAT_CHECKED_CLOCK
	fadescreen 1
	special Special_ViewWallClock
	waitstate
	releaseall
	end

Common_EventScript_SetPowerOffWeather:
	setweather_nodelay WEATHER_POWEROUT
	end

Common_EventScript_SetupRivalGender:: @ 8271ED7
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq RustboroCity_EventScript_271EEF
	compare VAR_RESULT, FEMALE
	goto_if_eq RustboroCity_EventScript_271EF5
	end
RustboroCity_EventScript_271EEF:: @ 8271EEF
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_MAY_NORMAL
	return
RustboroCity_EventScript_271EF5:: @ 8271EF5
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_RIVAL_BRENDAN_NORMAL
	return

Common_EventScript_SetupRivalOnBikeGender:: @ 8271EFB
	checkplayergender
	compare VAR_RESULT, MALE
	goto_if_eq LavaridgeTown_EventScript_271F13
	compare VAR_RESULT, FEMALE
	goto_if_eq LavaridgeTown_EventScript_271F19
	end
LavaridgeTown_EventScript_271F13:: @ 8271F13
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_RIVAL_MAY_MACH_BIKE
	return
LavaridgeTown_EventScript_271F19:: @ 8271F19
	setvar VAR_OBJ_GFX_ID_3, EVENT_OBJ_GFX_RIVAL_BRENDAN_MACH_BIKE
	return

Common_EventScript_IncrementBadgeCount::
	addvar VAR_NUM_BADGES, 1
	compare VAR_NUM_BADGES, 4
	call_if_eq PetalburgCity_Gym_EventScript_OpenGym
	return

Common_EventScript_ClearSceneFlags::
	clearflag FLAG_SCENE_0
	clearflag FLAG_SCENE_1
	clearflag FLAG_SCENE_2
	clearflag FLAG_SCENE_3
	clearflag FLAG_SCENE_4
	clearflag FLAG_SCENE_5
	clearflag FLAG_SCENE_6
	clearflag FLAG_SCENE_7
	clearflag FLAG_SCENE_8
	clearflag FLAG_SCENE_9
	clearflag FLAG_SCENE_A
	clearflag FLAG_SCENE_B
	clearflag FLAG_SCENE_C
	clearflag FLAG_SCENE_D
	clearflag FLAG_SCENE_E
	clearflag FLAG_SCENE_F
	return

Common_EventScript_FailTheftNoRoom::
	msgbox Common_Text_FailTheftNoRoom, MSGBOX_DEFAULT
	release
	end
Common_Text_FailTheftNoRoom:
	.string "But then, you don't have the space\n"
	.string "available anyway…$"
