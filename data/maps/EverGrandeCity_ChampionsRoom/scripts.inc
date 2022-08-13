EverGrandeCity_ChampionsRoom_MapScripts:: @ 82289EF
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_ChampionsRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_ChampionsRoom_MapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_ChampionsRoom_FrameTable
	map_script MAP_SCRIPT_ON_RESUME, EverGrandeCity_ChampionsRoom_OnResume
	.byte 0

@ -----------------------------------------------------

EverGrandeCity_ChampionsRoom_OnTransition: @ 82289FF
	call Common_EventScript_SetupRivalGender
	end

@ -----------------------------------------------------

EverGrandeCity_ChampionsRoom_MapTable: @ 8228A05
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_228A0F
	.2byte 0

EverGrandeCity_ChampionsRoom_EventScript_228A0F:: @ 8228A0F
	turnobject EVENT_OBJ_ID_PLAYER, 2
	end

@ -----------------------------------------------------

EverGrandeCity_ChampionsRoom_FrameTable: @ 8228A14
	@ map_script_2 VAR_TEMP_1, 0, EverGrandeCity_ChampionsRoom_EventScript_228A1E
	.2byte 0

@ -----------------------------------------------------

EverGrandeCity_ChampionsRoom_OnResume:
	callnative SetupChampionBackgroundPanning
	compare VAR_TEMP_0, 1
	goto_if_eq EverGrandeCity_ChampionsRoom_OnResume_Wave
	end
EverGrandeCity_ChampionsRoom_OnResume_Wave:
	callnative DoChampWaveFlags
	end

@ -----------------------------------------------------
@ Triggers

EverGrandeCity_ChampionsRoom_TriggerScript_GoWave::
	callnative DoChampWaveFlags
	playse SE_DENDOU
	setvar VAR_TEMP_0, 1
	end


EverGrandeCity_ChampionsRoom_TriggerScript_GoChampion::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_X, 8
	special SpawnCameraObject
	@ Walk to plinth
	selectpointer EverGrandeCity_ChampionsRoom_MovementTable_Player, VAR_INTERACT_X
	applymovement EVENT_OBJ_ID_PLAYER, 0
	selectpointer EverGrandeCity_ChampionsRoom_MovementTable_Camera, VAR_INTERACT_X
	applymovement EVENT_OBJ_ID_CAMERA, 0
	waitmovement 0
	@ Play music, jump to speech
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_0, 2
	playbgm MUS_DAIGO, 0
	call_if_unset FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, EverGrandeCity_ChampionsRoom_EventScript_ChampTalk1
	call_if_set FLAG_DEFEATED_LEGENDARIES_SINGLEHANDEDLY, EverGrandeCity_ChampionsRoom_EventScript_ChampTalk2
	@ to battle!
	goto EverGrandeCity_ChampionsRoom_EventScript_Battle
	end

.align 2
EverGrandeCity_ChampionsRoom_MovementTable_Player:
	.4byte EverGrandeCity_ChampionsRoom_Movement_Player1
	.4byte EverGrandeCity_ChampionsRoom_Movement_Player2
	.4byte EverGrandeCity_ChampionsRoom_Movement_Player3
	.4byte 0
EverGrandeCity_ChampionsRoom_MovementTable_Camera:
	.4byte EverGrandeCity_ChampionsRoom_Movement_Camera1
	.4byte EverGrandeCity_ChampionsRoom_Movement_Camera2
	.4byte EverGrandeCity_ChampionsRoom_Movement_Camera3
	.4byte 0

EverGrandeCity_ChampionsRoom_Movement_Player1: @ 82725C1
	walk_right
	walk_up
	walk_up
	walk_up
	step_end
EverGrandeCity_ChampionsRoom_Movement_Camera1:
	walk_slow_diag_northeast
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
EverGrandeCity_ChampionsRoom_Movement_Player2: @ 82725C1
	delay_16
	walk_up
	walk_up
	walk_up
	step_end
EverGrandeCity_ChampionsRoom_Movement_Camera2:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
EverGrandeCity_ChampionsRoom_Movement_Player3: @ 82725C1
	walk_left
	walk_up
	walk_up
	walk_up
	step_end
EverGrandeCity_ChampionsRoom_Movement_Camera3:
	walk_slow_diag_northwest
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end

EverGrandeCity_ChampionsRoom_EventScript_ChampTalk1:
	msgbox EverGrandeCity_ChampionsRoom_Text_ChampTalk1, MSGBOX_DIALOG
	return
EverGrandeCity_ChampionsRoom_Text_ChampTalk1:
	.string "Wallace: Welcome, {PLAYER}.\p"
	.string "I've heard many things about you over\n"
	.string "the course of the last week.\p"
	.string "The news media says you used to be with\n"
	.string "Team Aqua, and that you're attempting\l"
	.string "to atone for that sin.\p"
	.string "There was another contestant who even\n"
	.string "said you helped stop the Sootopolis\l"
	.string "City incident.\p"
	.string "I don't know how true these rumors are,\n"
	.string "but they make for fascinating TV.\p"
	.string "You did manage to make it this far\n"
	.string "in the Elite Four Conference.\p"
	.string "Tell me. What drives you so?\p"
	.string "Why do you push your Pokémon to the\n"
	.string "edge for this title?\p"
	.string "Is it power you seek?\n"
	.string "Validation, perhaps?\l"
	.string "A sense of self-worth?\p"
	.string "Hm. Perhaps I've hit a nerve.\n"
	.string "I see the impatience in your face.\p"
	.string "Very well, I suppose I've talked\n"
	.string "long enough.\p"
	.string "The people in this stadium are not here\n"
	.string "to hear me talk.\l"
	.string "{PLAY_SE SE_DENDOU}They are here to see a battle!\p"
	.string "Let's see which of us can most elegantly\n"
	.string "dance atop the Champion's Plinth!\p"
	.string "EN GARDE!$"
	

EverGrandeCity_ChampionsRoom_EventScript_ChampTalk2:
	msgbox EverGrandeCity_ChampionsRoom_Text_ChampTalk2, MSGBOX_DIALOG
	return
EverGrandeCity_ChampionsRoom_Text_ChampTalk2: @ 8228C4C
	.string "Wallace: Welcome, {PLAYER}.\p"
	.string "That incident in Sootopolis City…\n"
	.string "That was superb work, putting an end\l"
	.string "to that crisis all by yourself.\p"
	.string "You overcame that difficult situation\n"
	.string "by working as one with your Pokémon.\p"
	.string "After that showing, frankly it's no\n"
	.string "surprise that you made it this far in\l"
	.string "the Elite Four Conference.\p"
	.string "Tell me. What drives you so?\p"
	.string "Why do you push your Pokémon to the\n"
	.string "edge for this title?\p"
	.string "Is it power you seek?\n"
	.string "Validation, perhaps?\l"
	.string "A sense of self-worth?\p"
	.string "Perhaps you're just looking for the next\n"
	.string "thrill after taking out those beasts!\p"
	.string "I see the impatience in your face.\p"
	.string "Very well, I suppose I've talked\n"
	.string "long enough.\p"
	.string "The people in this stadium are not here\n"
	.string "to hear me talk.\l"
	.string "{PLAY_SE SE_DENDOU}They are here to see a battle!\p"
	.string "Let's see which of us can most elegantly\n"
	.string "dance atop the Champion's Plinth!\p"
	.string "EN GARDE!$"

EverGrandeCity_ChampionsRoom_EventScript_Battle:: @ 8228A45
	setflag FLAG_DEATH_PREVENT
	savebgm MUS_KACHI5 @ save victory music for after battle
	special RemoveCameraObject
	trainerbattle_no_intro TRAINER_WALLACE, EverGrandeCity_ChampionsRoom_Text_228EAC
	goto EverGrandeCity_ChampionsRoom_EventScript_AfterMath
	end
EverGrandeCity_ChampionsRoom_Text_228EAC: @ 8228EAC
	.string "I, the champion, fall in defeat…\p"
	.string "That was wonderful work.\n"
	.string "You were elegant, infuriatingly so.\l"
	.string "And yet it was utterly glorious!\p"
	.string "Kudos to you, {PLAYER}!\p"
	.string "You are a truly noble Pokémon\n"
	.string "Trainer!$"

#define LID_CHAMP 1
#define LID_DAD 3
#define LID_AQUA_GIRL 4
#define LID_AQUA_BOY 5

EverGrandeCity_ChampionsRoom_DetermineFriendCount:
	setvar VAR_TEMP_A, 0
	@ If the player has reached the friendship threshold with the boy, add 1
	compare VAR_AQUA_BOY_FRIENDSHIP, 4
	addvar_if 4, VAR_TEMP_A, 1 @ "addvar_if_ge"
	@ If the player has reached the friendship threshold with the girl, add 2
	compare VAR_AQUA_GIRL_FRIENDSHIP, 4
	addvar_if 4, VAR_TEMP_A, 2 @ "addvar_if_ge"
	@ if VAR_TEMP_A == 0 => No friends
	@ if VAR_TEMP_A == 1 => Only boy
	@ if VAR_TEMP_A == 2 => Only girl
	@ if VAR_TEMP_A == 3 => Both
	selectpointer EverGrandeCity_ChampionsRoom_PointerTable_SetupFriendCount, VAR_TEMP_A
	call 0
	return

.align 2
EverGrandeCity_ChampionsRoom_PointerTable_SetupFriendCount:
	.4byte EverGrandeCity_ChampionsRoom_SetupFriendCount0
	.4byte EverGrandeCity_ChampionsRoom_SetupFriendCount1
	.4byte EverGrandeCity_ChampionsRoom_SetupFriendCount2
	.4byte EverGrandeCity_ChampionsRoom_SetupFriendCount3
	.4byte 0
EverGrandeCity_ChampionsRoom_SetupFriendCount0:
	return
EverGrandeCity_ChampionsRoom_SetupFriendCount1:
	setobjectxyperm LID_AQUA_BOY, 8, 32
	return 
EverGrandeCity_ChampionsRoom_SetupFriendCount2:
	setobjectxyperm LID_AQUA_GIRL, 8, 32
	return 
EverGrandeCity_ChampionsRoom_SetupFriendCount3:
	setobjectxyperm LID_AQUA_BOY, 8, 32
	setobjectxyperm LID_AQUA_GIRL, 10, 32
	return


EverGrandeCity_ChampionsRoom_EventScript_AfterMath:: @ 8228A61
	special SpawnCameraObject
	setflag FLAG_TEMP_1E @ Trigger crowd cheering tileset animation
	playse SE_DENDOU
	@ Walk towards each other
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkUp1
	applymovement EVENT_OBJ_ID_CAMERA, Common_Movement_WalkDown1
	applymovement LID_CHAMP, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath1, MSGBOX_CDIALOG
	closemessage
	@ 
	applymovement LID_CHAMP, EverGrandeCity_ChampionsRoom_Movement_AfterMath2_Champ
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_AfterMath2_Player
	playse SE_DENDOU
	waitmovement 0
	@ Initiate "confetti"
	setweather WEATHER_CONFETTI
	doweather
	delay 100
	@ Walking down
	applymovement LID_CHAMP, EverGrandeCity_ChampionsRoom_Movement_AfterMath3
	delay 8
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_AfterMath3
	waitmovement LID_CHAMP
	@
	markasdialog -29
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath4
	closemessage
	@ 
	addobject LID_DAD
	applymovement LID_DAD, EverGrandeCity_ChampionsRoom_Movement_AfterMath5
	waitmovement 0
	applymovement LID_CHAMP, Common_Movement_WalkInPlaceRight
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath5, MSGBOX_CDESCRIBE
	waitmovement 0
	@
	markasdialog 12
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath6
	closemessage
	@
	call EverGrandeCity_ChampionsRoom_DetermineFriendCount
	
	@ Dad steps aside to let the champ walk continue
	applymovement LID_DAD, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LID_DAD, Common_Movement_BackOffRight1
	waitmovement 0
	delay 20
	@ Player leads the way back across the walkway
	resetweather
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_ChampionsRoom_Movement_AfterMath8
	delay 20
	applymovement LID_CHAMP, EverGrandeCity_ChampionsRoom_Movement_AfterMath8
	delay 8
	applymovement LID_DAD, EverGrandeCity_ChampionsRoom_Movement_AfterMath8a
	delay 30
	doweather
	waitmovement EVENT_OBJ_ID_PLAYER
	selectpointer EverGrandeCity_ChampionsRoom_PointerTable_DoFriendScene, VAR_TEMP_A
	call 0
	
	@ TODO either walk up to the cheering crowds, or walk down right away
	@ Walk down to cheering, meet up with Dad at the bottom of the walk
	@ Dad congratulates you.
	@ Your Team Aqua friends are also there possibly, with high enough friendship.
	warp MAP_EVER_GRANDE_CITY_HALL_OF_FAME, 255, 7, 16
	waitstate
	releaseall
	end

EverGrandeCity_ChampionsRoom_Text_AfterMath1: @ 8228F66
	.string "Wallace: The Pokémon you sent into\n"
	.string "battle…\p"
	.string "At times they danced like a spring\n"
	.string "breeze, and at times they struck\l"
	.string "like lightning.\p"
	.string "It was with light, yet surefooted,\n"
	.string "elegance that you led your Pokémon.\p"
	.string "Even I felt bedazzled by your\n"
	.string "masterful performance!\p"
	.string "You now stand at the glorious peak\n"
	.string "of the Pokémon League.\p"
	.string "I now proclaim you to be the new\n"
	.string "Hoenn region Champion!$"
EverGrandeCity_ChampionsRoom_Text_AfterMath4:
	.string "Dad: {PLAYER}!$"
EverGrandeCity_ChampionsRoom_Text_AfterMath5:
	.string "Dad hugged {PLAYER} tightly.$"
EverGrandeCity_ChampionsRoom_Text_AfterMath6:
	.string "Dad: {PLAYER}! You did it!\n"
	.string "My little {PLAYER_boy} is all grown up now!\p"
	.string "Your mother and your friend {RIVAL_ALOLA}!\n"
	.string "They're back in Alola, watching you too!\p"
	.string "I… {PAUSE 40}I'm so proud of you…$"
EverGrandeCity_ChampionsRoom_Text_AfterMath7a:
	.string "Wallace: If you'll all excuse us.\p"
	.string "We need to enter {PLAYER} into the\n"
	.string "records of history.$"
EverGrandeCity_ChampionsRoom_Text_AfterMath7b:
	.string "Wallace: If you'll excuse us, sir.\p"
	.string "We need to enter {PLAYER} into the\n"
	.string "records of history.$"


.align 2
EverGrandeCity_ChampionsRoom_PointerTable_DoFriendScene:
	.4byte EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene0
	.4byte EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene1
	.4byte EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene2
	.4byte EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene3
	.4byte 0

EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene0:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown2
	waitmovement EVENT_OBJ_ID_PLAYER
	waitmovement LID_CHAMP
	applymovement LID_CHAMP, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_DAD, Common_Movement_WalkInPlaceLeft
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@
	markasdialog 6
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath7b
	@
	markasdialog -6
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend0A
	closemessage
	@
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	applymovement LID_CHAMP, Common_Movement_WalkDown1
	waitmovement 0
	return
EverGrandeCity_ChampionsRoom_Text_Friend0A:
	.string "Dad: Of course! I'll see you after,\n"
	.string "{PLAYER}. We'll get dinner somewhere.$"

EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene1:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown2
	waitmovement EVENT_OBJ_ID_PLAYER
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceRight
	waitmovement 0
	@
	markasdialog 8
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend1A
	@
	applymovement LID_DAD, Common_Movement_WalkInPlaceLeft
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@
	markasdialog 4
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath7a
	@
	markasdialog -6
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend1B
	closemessage
	@
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	applymovement LID_CHAMP, Common_Movement_WalkDown1
	waitmovement 0
	return 
EverGrandeCity_ChampionsRoom_Text_Friend1A:
	.string "{AQUA_BOY}: Congratulations, {PLAYER}!\n"
	.string "I knew you could do it!\p"
	.string "Even with all that rumor stuff,\n"
	.string "you still came out on top!\p"
	.string "You beat them! You beat them all!$"
EverGrandeCity_ChampionsRoom_Text_Friend1B:
	.string "Dad: Of course! We'll see you after,\n"
	.string "{PLAYER}. We'll get dinner somewhere.$"

EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene2:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown2
	waitmovement EVENT_OBJ_ID_PLAYER
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	@
	markasdialog 8
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend2A
	@
	applymovement LID_DAD, Common_Movement_WalkInPlaceLeft
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@
	markasdialog 4
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath7a
	@
	markasdialog -6
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend1B
	closemessage
	@
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	applymovement LID_CHAMP, Common_Movement_WalkDown1
	waitmovement 0
	return 
EverGrandeCity_ChampionsRoom_Text_Friend2A:
	.string "{AQUA_GIRL}: Congrats, {PLAYER_gurl}!\n"
	.string "You made it! You won!\p"
	.string "I'll admit I was a little worried at\n"
	.string "after the first couple battles, but\l"
	.string "you pulled through!\p"
	.string "No one can defeat you!$"

EverGrandeCity_ChampionsRoom_EventScript_DoFriendScene3:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown2
	waitmovement EVENT_OBJ_ID_PLAYER
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceRight
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	@
	markasdialog 8
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend3A
	@
	markasdialog -8
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend3B
	@
	markasdialog 8
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend3C
	@
	applymovement LID_DAD, Common_Movement_WalkInPlaceLeft
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceUp
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	@
	markasdialog 6
	msgbox EverGrandeCity_ChampionsRoom_Text_AfterMath7a
	@
	markasdialog -6
	msgbox EverGrandeCity_ChampionsRoom_Text_Friend1B
	closemessage
	@
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	applymovement LID_CHAMP, Common_Movement_WalkRight1
	waitmovement 0
	return
EverGrandeCity_ChampionsRoom_Text_Friend3A:
	.string "{AQUA_BOY}: Congratulations, {PLAYER}!\n"
	.string "I knew you could do it!$"
EverGrandeCity_ChampionsRoom_Text_Friend3B:
	.string "{AQUA_GIRL}: Yes, we were cheering for\n"
	.string "you the whole time!$"
EverGrandeCity_ChampionsRoom_Text_Friend3C:
	.string "{AQUA_BOY}: I think {AQUA_GIRL} may\n"
	.string "have blown out my eardrum with\l"
	.string "all her cheering and screaming!$"


EverGrandeCity_ChampionsRoom_Movement_AfterMath2_Player:
	walk_down
	walk_down
	step_end
EverGrandeCity_ChampionsRoom_Movement_AfterMath2_Champ:
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

EverGrandeCity_ChampionsRoom_Movement_AfterMath3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
EverGrandeCity_ChampionsRoom_Movement_AfterMath5:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

EverGrandeCity_ChampionsRoom_Movement_AfterMath8:
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
	walk_down
	step_end
EverGrandeCity_ChampionsRoom_Movement_AfterMath8a:
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
	step_end

#undef LID_CHAMP
#undef LID_DAD
#undef LID_AQUA_GIRL
#undef LID_AQUA_BOY
