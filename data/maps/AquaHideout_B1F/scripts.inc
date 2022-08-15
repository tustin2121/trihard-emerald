AquaHideout_B1F_MapScripts:: @ 82339A7
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, AquaHideout_B1F_OnLoad
	.byte 0

@ -----------------------------------------------------

AquaHideout_B1F_OnLoad:
	call AquaHideout_B1F_EventScript_Scrappy21_SitDownOnLoad
	setflag FLAG_VISITED_AQUA_BASE
	setflag FLAG_TEMP_5
	@ If Mt. Pyre is finished, but Jagged pass is not yet open, show Aqua girl
	setflag VAR_TEMP_A
	@ If before Mt. Pyre, stay hidden
	goto_if_unset FLAG_RECEIVED_RED_OR_BLUE_ORB, Common_EventScript_NopEnd
	@ If after Jagged Pass, stay hidden
	compare VAR_JAGGED_PASS_STATE, 0
	goto_if_gt Common_EventScript_NopEnd
	@ Show
	clearflag VAR_TEMP_A
	end

@ -----------------------------------------------------

AquaHideout_B1F_OnResume: @ 82339B2
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_2339BC
	end

AquaHideout_B1F_EventScript_2339BC:: @ 82339BC
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 7
	goto_if_ne Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

@ -----------------------------------------------------

AquaHideout_B1F_OnTransition: @ 82339D0
	setflag FLAG_DEATH_PREVENT
	setflag FLAG_DEATH_PREVENT_1HP
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_2339E3
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_2339E7
	end

AquaHideout_B1F_EventScript_2339E3:: @ 82339E3
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_1
	return

AquaHideout_B1F_EventScript_2339E7:: @ 82339E7
	clearflag FLAG_HIDE_AQUA_HIDEOUT_B1F_ELECTRODE_2
	return

@ -----------------------------------------------------
@ Item Balls

AquaHideout_B1F_EventScript_ItemMasterBall:: @ 8291358
	giveitem_std ITEM_MASTER_BALL, 1, 1
	end

AquaHideout_B1F_EventScript_ItemNugget:: @ 8291365
	giveitem_std ITEM_NUGGET, 1, 1
	end

AquaHideout_B1F_EventScript_ItemMaxElixir:: @ 8291372
	giveitem_std ITEM_MAX_ELIXIR, 1, 1
	end

@ -----------------------------------------------------
@ Electrode

AquaHideout_B1F_EventScript_WildElectrode1:: @ 82339EB
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq AquaHideout_B1F_EventScript_233A2F
	compare VAR_RESULT, 4
	goto_if_eq AquaHideout_B1F_EventScript_233A2F
	compare VAR_RESULT, 5
	goto_if_eq AquaHideout_B1F_EventScript_233A2F
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end
AquaHideout_B1F_EventScript_233A2F:: @ 8233A2F
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto AquaHideout_B1F_EventScript_27376D
	end

AquaHideout_B1F_EventScript_WildElectrode2:: @ 8233A38
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30, ITEM_NONE
	waitse
	playmoncry SPECIES_ELECTRODE, 2
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	compare VAR_RESULT, 1
	goto_if_eq AquaHideout_B1F_EventScript_233A7C
	compare VAR_RESULT, 4
	goto_if_eq AquaHideout_B1F_EventScript_233A7C
	compare VAR_RESULT, 5
	goto_if_eq AquaHideout_B1F_EventScript_233A7C
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end
AquaHideout_B1F_EventScript_233A7C:: @ 8233A7C
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto AquaHideout_B1F_EventScript_27376D
	end

@ -----------------------------------------------------
@ Trainers

AquaHideout_B1F_EventScript_Scrappy2:: @ 8233A85
	trainerbattle_single TRAINER_GRUNT_2, AquaHideout_B1F_Text_233B03, AquaHideout_B1F_Text_233B4A @, AquaHideout_B1F_EventScript_233AA0
	msgbox AquaHideout_B1F_Text_233B5E, MSGBOX_AUTOCLOSE
	end
@ AquaHideout_B1F_EventScript_233AA0:: @ 8233AA0
@ 	special DoSpinningTrainerApproach
@ 	waitmovement 0
@ 	msgbox AquaHideout_B1F_Text_233B5E, MSGBOX_DEFAULT
@ 	release
@ 	end
AquaHideout_B1F_Text_233B03: @ 8233B03
	.string "Ey yo! Let's scrap!$"
AquaHideout_B1F_Text_233B4A: @ 8233B4A
	.string "Ya can't win at all…$"
AquaHideout_B1F_Text_233B5E: @ 8233B5E
	.string "Ey, which do ya think is cooler?\n"
	.string "Team Aqua's uniform, or Team Magma's?\p"
	.string "Magma's hoodie is kinda sick, like\n"
	.string "yo, I ain't seen anything like that.\p"
	.string "But then Aqua's do-rag is like,\n"
	.string "yooooooooooo, man!$"


AquaHideout_B1F_EventScript_Scrappy25:: @ 8233AEC
	trainerbattle_single TRAINER_GRUNT_25, AquaHideout_B1F_Text_233D1B, AquaHideout_B1F_Text_233D6E
	goto_if_set FLAG_TEAM_AQUA_STOLE_SUBMARINE, AquaHideout_B1F_EventScript_233AAB
	msgbox AquaHideout_B1F_Text_233D84, MSGBOX_AUTOCLOSE
	end
AquaHideout_B1F_Text_233D1B: @ 8233D1B
	.string "I'm amiable to a quick training battle.$"
AquaHideout_B1F_Text_233D6E: @ 8233D6E
	.string "Clearly I must better prepare myself\n"
	.string "for future encounters…$"
AquaHideout_B1F_Text_233D84: @ 8233D84
	.string "I heard that the boss is enroute to\n"
	.string "steal a submarine so that we can move\l"
	.string "on to phase three of the plan.\p"
	.string "I think I heard the sub was in\n"
	.string "Slateport?$"
AquaHideout_B1F_EventScript_233AAB:
	msgbox AquaHideout_B1F_Text_233D85, MSGBOX_AUTOCLOSE
	end
AquaHideout_B1F_Text_233D85:
	.string "They made it back from the sub heist.\p"
	.string "We'll be departing on the sub shortly.$"


AquaHideout_B1F_EventScript_Scrappy3:: @ 8233AB0
	trainerbattle_single TRAINER_GRUNT_3, AquaHideout_B1F_Text_233BC5, AquaHideout_B1F_Text_233C27, AquaHideout_B1F_EventScript_233ACB
	msgbox AquaHideout_B1F_Text_233C41, MSGBOX_AUTOCLOSE
	end
AquaHideout_B1F_EventScript_233ACB:: @ 8233ACB
	msgbox AquaHideout_B1F_Text_233C41, MSGBOX_DEFAULT
	release
	end
AquaHideout_B1F_Text_233BC5: @ 8233BC5
	.string "Fuel supply loaded A-OK!\n"
	.string "In-cruise snacks loaded A-OK!\p"
	.string "Nothing left to do, so…\n"
	.string "Wanna scrap fight to pass the time?$"
AquaHideout_B1F_Text_233C27: @ 8233C27
	.string "I took a serious licking!$"
AquaHideout_B1F_Text_233C41: @ 8233C41
	.string "So are you assigned to be on the sub?\p"
	.string "No?\n"
	.string "Are you assigned to guard the hideout?\p"
	.string "Are you assigned to anything?!$"


AquaHideout_B1F_EventScript_Scrappy21:: @ 8233AD5
	trainerbattle_single TRAINER_GRUNT_21, AquaHideout_B1F_Text_233C89, AquaHideout_B1F_Text_233CCA
	msgbox AquaHideout_B1F_Text_233CDC, MSGBOX_AUTOCLOSE
	end
AquaHideout_B1F_Text_233C89: @ 8233C89
	.string "Yawn… I'm bored.\n"
	.string "Hey, you wanna scrap?$"
AquaHideout_B1F_Text_233CCA: @ 8233CCA
	.string "Phew! That woke me up alright.$"
AquaHideout_B1F_Text_233CDC: @ 8233CDC
	.string "Everyone else is always scurrying\n"
	.string "around everywhere.\p"
	.string "I'm content to just chill for a while.$"
AquaHideout_B1F_EventScript_Scrappy21_SitDownOnLoad:
	checktrainerflag TRAINER_GRUNT_21
	goto_if_lt Common_EventScript_NopReturn
	setobjectxy 4, 21, 16
	setobjectxyperm 4, 21, 16
	setobjectmovementtype 4, MOVEMENT_TYPE_FACE_LEFT
	return


AquaHideout_B1F_EventScript_Jessica::
	goto_if_set FLAG_SCENE_1, AquaHideout_B1F_EventScript_Jessica2
	msgbox AquaHideout_B1F_Text_Jessica, MSGBOX_NPC
	setflag FLAG_SCENE_1
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	end
AquaHideout_B1F_Text_Jessica:
	.string "{AQUA_GIRL}: Oh, {PLAYER}. I'm working\n"
	.string "on finding the Magma base…\p"
	.string "All I know right now is that\n"
	.string "it's near Mt. Chimney…$"
AquaHideout_B1F_EventScript_Jessica2:
	msgbox AquaHideout_B1F_Text_Jessica2, MSGBOX_DIALOG
	end
AquaHideout_B1F_Text_Jessica2:
	.string "{AQUA_GIRL}: Where could it be…?$"

@ -----------------------------------------------------

AquaHideout_B1F_EventScript_Blueprint1::
	lockall
	selectpointer_clamp AquaHideout_B1F_TextTable_Blueprint1, VAR_AQUA_BLUEPRINT1
	message 0x0, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	addvar VAR_AQUA_BLUEPRINT1, 1
	releaseall 
	end
.align 2
AquaHideout_B1F_TextTable_Blueprint1:
	.4byte AquaHideout_B1F_Text_Blueprint1A
	.4byte AquaHideout_B1F_Text_Blueprint1B
	.4byte AquaHideout_B1F_Text_Blueprint1C
	.4byte AquaHideout_B1F_Text_Blueprint1D
	.4byte AquaHideout_B1F_Text_Blueprint1E
	.4byte 0
AquaHideout_B1F_Text_Blueprint1A:
	.string "It's a blueprint for some kind of\n"
	.string "ocean-faring vessel.\p"
	.string "{PLAYER} looks through the various\n"
	.string "measurements and details, picturing\l"
	.string "what it might look like when built.\p"
	.string "It looks like they got this calculation\n"
	.string "wrong? {PLAYER} corrects it quickly.$"
AquaHideout_B1F_Text_Blueprint1B:
	.string "Wait, they got this wrong too!\p"
	.string "{PLAYER} grabs a pen and starts\n"
	.string "scribbling notes and calculations.\p"
	.string "This this could never sail!\n"
	.string "What were they thinking?!$"
AquaHideout_B1F_Text_Blueprint1C:
	.string "By Arceus's spike ring, who did this\n"
	.string "blueprint?! It's a mess!\p"
	.string "{PLAYER} goes at about five more things\n"
	.string "that are so blatantly wrong here!\p"
	.string "Really, how can ANYONE with this terrible\n"
	.string "level of understanding about buoyancy\l"
	.string "call themselves Team AQUA?! Disgraceful!$"
AquaHideout_B1F_Text_Blueprint1D:
	.string "{PLAYER} scribbles out the whole set of\n"
	.string "calculations and grabs a sheet of paper.\p"
	.string "{PLAYER_They} starts doing all the math again\n"
	.string "from scratch. Nothing was salvageable.\p"
	.string "After several minutes, {PLAYER_their} mathematical\n"
	.string "proof is finished and flawless.\p"
	.string "{PLAYER} tapes the new calculations over\n"
	.string "the old ones. Idiots. All of them.$"
AquaHideout_B1F_Text_Blueprint1E:
	.string "{PLAYER} looks back over the corrected\n"
	.string "calculations for errors.\p"
	.string "Seems good now. THIS boat will float,\n"
	.string "unlike the last one.$"

AquaHideout_B1F_EventScript_Blueprint2::
	lockall
	selectpointer_clamp AquaHideout_B1F_TextTable_Blueprint2, VAR_AQUA_BLUEPRINT1
	message 0x0, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	releaseall 
	end
.align 2
AquaHideout_B1F_TextTable_Blueprint2:
	.4byte AquaHideout_B1F_Text_Blueprint2A
	.4byte AquaHideout_B1F_Text_Blueprint2A
	.4byte AquaHideout_B1F_Text_Blueprint2B
	.4byte AquaHideout_B1F_Text_Blueprint2B
	.4byte AquaHideout_B1F_Text_Blueprint2B
	.4byte 0
AquaHideout_B1F_Text_Blueprint2A:
	.string "It's a blueprint for some kind of\n"
	.string "new propeller design.\p"
	.string "{PLAYER} scans over it and pictures\n"
	.string "how the fluid dynamics would function.$"
AquaHideout_B1F_Text_Blueprint2B:
	.string "It's a blueprint for some kind of\n"
	.string "new propeller design.\p"
	.string "THIS blueprint looks like it was made\n"
	.string "by someone competent!$"


@ -----------------------------------------------------

#define LID_LOGAN 10

AquaHideout_B1F_TriggerScript_LoganFight::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_X, 27
	@
	setobjectxyperm LID_LOGAN, 29, 1
	addobject LID_LOGAN
	applymovement LID_LOGAN, Common_Movement_WalkDown1
	waitmovement 0
	selectpointer AquaHideout_B1F_MovementTable_LoganFight, VAR_INTERACT_X
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	@
	markasdialog
	msgbox AquaHideout_B1F_Text_LoganFight1
	closemessage
	@ juking each other out
	special SpawnCameraObject
	applymovement LID_LOGAN, AquaHideout_B1F_Movement_LoganFight2_JukeLogan1
	applymovement EVENT_OBJ_ID_PLAYER, AquaHideout_B1F_Movement_LoganFight2_JukePlayer1
	waitmovement LID_LOGAN
	waitmovement EVENT_OBJ_ID_PLAYER
	delay 20
	applymovement LID_LOGAN, AquaHideout_B1F_Movement_LoganFight2_JukeLogan2
	applymovement EVENT_OBJ_ID_PLAYER, AquaHideout_B1F_Movement_LoganFight2_JukePlayer2
	waitmovement LID_LOGAN
	waitmovement EVENT_OBJ_ID_PLAYER
	delay 20
	applymovement LID_LOGAN, AquaHideout_B1F_Movement_LoganFight2_JukeLogan3
	applymovement EVENT_OBJ_ID_PLAYER, AquaHideout_B1F_Movement_LoganFight2_JukePlayer3
	waitmovement LID_LOGAN
	waitmovement EVENT_OBJ_ID_PLAYER
	delay 20
	special RemoveCameraObject
	@
	msgbox AquaHideout_B1F_Text_LoganFight3
	@ make note of how many party members we have now
	getpartysize
	copyvar VAR_TEMP_A, VAR_RESULT
	@ Start a deadly fight!
	clearflag FLAG_DEATH_PREVENT
	clearflag FLAG_DEATH_PREVENT_1HP
	trainerbattle_no_intro TRAINER_LOGAN_HIDEOUT, AquaHideout_B1F_Text_LoganFight4
	@ make note of how many pokemon we have now
	@ mon count = prev - curr
	copyvar VAR_LOGAN_AQUA_FIGHT_LOST_MON_COUNT, VAR_TEMP_A
	getpartysize
	subvar VAR_LOGAN_AQUA_FIGHT_LOST_MON_COUNT, VAR_RESULT
	@
	markasdialog
	msgbox AquaHideout_B1F_Text_LoganFight5
	applymovement LID_LOGAN, Common_Movement_WalkUp1
	waitmovement 0
	removeobject LID_LOGAN
	@ Clean up
	setvar VAR_AQUA_HIDEOUT_STATE, 2
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_HIDE_LILYCOVE_CITY_AQUA_GRUNTS
	call Common_EventScript_ClearSceneFlags
	releaseall
	end
AquaHideout_B1F_Text_LoganFight1:
	.string "Oh, it's you again.\p"
	.string "Figures I'd see you here.$"
AquaHideout_B1F_Text_LoganFight3:
	.string "So it's gonna be like this, is it?\p"
	.string "That's fine.\n"
	.string "I'll just beat you out of the way!$"
AquaHideout_B1F_Text_LoganFight4:
	.string "Arceus wept…$"
AquaHideout_B1F_Text_LoganFight5:
	.string "I keep forgetting how ruthless you\n"
	.string "are with your Pokémon…\p"
	.string "You lot haven't seen the last of me…$"

.align 2
AquaHideout_B1F_MovementTable_LoganFight:
	.4byte AquaHideout_B1F_Movement_LoganFight0
	.4byte AquaHideout_B1F_Movement_LoganFight1
	.4byte AquaHideout_B1F_Movement_LoganFight2
	.4byte AquaHideout_B1F_Movement_LoganFight3
	.4byte AquaHideout_B1F_Movement_LoganFight4
	.4byte 0
AquaHideout_B1F_Movement_LoganFight0:
	walk_right
	walk_right
	walk_in_place_up
	step_end
AquaHideout_B1F_Movement_LoganFight1:
	walk_right
	walk_in_place_up
	step_end
AquaHideout_B1F_Movement_LoganFight2:
	walk_in_place_up
	step_end
AquaHideout_B1F_Movement_LoganFight3:
	walk_left
	walk_in_place_up
	step_end
AquaHideout_B1F_Movement_LoganFight4:
	walk_left
	walk_left
	walk_in_place_up
	step_end

AquaHideout_B1F_Movement_LoganFight2_JukeLogan1:
	walk_right
	walk_in_place_down
	step_end
AquaHideout_B1F_Movement_LoganFight2_JukePlayer1:
	face_up
	lock_facing_direction
	delay_8
	walk_fast_right
	unlock_facing_direction
	step_end

AquaHideout_B1F_Movement_LoganFight2_JukeLogan2:
	walk_left
	walk_in_place_down
	walk_fast_left
	walk_in_place_down
	step_end
AquaHideout_B1F_Movement_LoganFight2_JukePlayer2:
	walk_left
	walk_in_place_up
	walk_fast_left
	walk_in_place_up
	step_end

AquaHideout_B1F_Movement_LoganFight2_JukeLogan3:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	walk_in_place_down
	step_end
AquaHideout_B1F_Movement_LoganFight2_JukePlayer3:
	walk_left
	player_run_right
	player_run_right
	walk_in_place_up
	step_end


#undef LID_LOGAN

