AquaHideout_B2F_MapScripts:: @ 8233DCF
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, AquaHideout_B2F_OnLoad
	.byte 0

@ -----------------------------------------------------

AquaHideout_B2F_OnTransition: @ 8233DD5
	setflag FLAG_DEATH_PREVENT
	setflag FLAG_DEATH_PREVENT_1HP
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_233DDF
	end

AquaHideout_B2F_EventScript_233DDF:: @ 8233DDF
	setvar VAR_TEMP_1, 1
	return

@ -----------------------------------------------------

AquaHideout_B2F_OnLoad:
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_OnLoad_CompleteSubmarineDeparture
	goto_if_unset FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_B2F_OnLoad_DisableSubmarineArrival
	clearflag FLAG_TEMP_5 @FLAG_HIDE_AQUA_HIDEOUT_B2F_SUBMARINE_SHADOW
	end

AquaHideout_B2F_OnLoad_DisableSubmarineArrival:
	setobjectxyperm 1, 45, 19
	setvar VAR_TEMP_1, 1
	setflag FLAG_TEMP_5
	end

AquaHideout_B2F_OnLoad_CompleteSubmarineDeparture:
	setobjectxyperm 1, 45, 19
	setvar VAR_TEMP_1, 1
	setflag FLAG_TEMP_5
	end

@ -----------------------------------------------------
@ Items

AquaHideout_B2F_EventScript_ItemNestBall:: @ 829137F
	giveitem_std ITEM_NEST_BALL, 1, 1
	end

AquaHideout_B2F_EventScript_ItemMasterBall:: @ 829138C
	giveitem_std ITEM_MASTER_BALL, 1, 1      // Unused
	end

@ -----------------------------------------------------
@ Trainers

AquaHideout_B2F_EventScript_Scrappy22:: @ 8233EAF
	trainerbattle_single TRAINER_GRUNT_22, AquaHideout_B2F_Text_23412D, AquaHideout_B2F_Text_2341CE
	msgbox AquaHideout_B2F_Text_2341FE, MSGBOX_AUTOCLOSE
	end
AquaHideout_B2F_Text_23412D: @ 823412D
	.string "Don't you think these new warp panels\n"
	.string "are awesome?\p"
	.string "Fluster and tire out the enemy, then\n"
	.string "lower the boom!\p"
	.string "Let's scrap and see how good it works!$"
AquaHideout_B2F_Text_2341CE: @ 82341CE
	.string "I think I'm the one confused by\n"
	.string "the warp panels after all!$"
AquaHideout_B2F_Text_2341FE: @ 82341FE
	.string "That reminds me… I can't remember\n"
	.string "where I put the Master Ball.\p"
	.string "If I fail to guard it, boss will\n"
	.string "chew me out…$"


AquaHideout_B2F_EventScript_Scrappy26:: @ 8233EC6
	trainerbattle_single TRAINER_GRUNT_26, AquaHideout_B2F_Text_23426F, AquaHideout_B2F_Text_2342CC
	msgbox AquaHideout_B2F_Text_2342FF, MSGBOX_AUTOCLOSE
	end
AquaHideout_B2F_Text_23426F: @ 823426F
	.string "Hey, uh, do you have a cheat sheet \n"
	.string "that lays out these warp panels?\l"
	.string "I'm so confused by them…\p"
	.string "I'll battle you for that sheet.$"
AquaHideout_B2F_Text_2342CC: @ 82342CC
	.string "I was too occupied thinking about\n"
	.string "the warp panels…$"
AquaHideout_B2F_Text_2342FF: @ 82342FF
	.string "I'm new here, so I have no idea what's\n"
	.string "going on with these panels.\p"
	.string "How do you cope with them?$"


AquaHideout_B2F_EventScript_Scrappy4:: @ 8233E8A
	trainerbattle_single TRAINER_GRUNT_4, AquaHideout_B2F_Text_2340B4, AquaHideout_B2F_Text_2340F0, AquaHideout_B2F_EventScript_233EA5
	msgbox AquaHideout_B2F_Text_234112, MSGBOX_AUTOCLOSE
	end
AquaHideout_B2F_EventScript_233EA5:: @ 8233EA5
	msgbox AquaHideout_B2F_Text_234112, MSGBOX_DEFAULT
	release
	end
AquaHideout_B2F_Text_2340B4: @ 82340B4
	.string "Wahahah, I grow weary of waiting!\n"
	.string "You owe me a scrap!$"
AquaHideout_B2F_Text_2340F0: @ 82340F0
	.string "Tired of waiting…\n"
	.string "Lost and dazed…$"
AquaHideout_B2F_Text_234112: @ 8234112
	.string "Boss…\n"
	.string "Is this good enough?\p"
	.string "I think I'm going crazy down here!$"


@ -----------------------------------------------------

AquaHideout_B2F_AquaWhy::
	msgbox AquaHideout_B2F_AquaWhyText, MSGBOX_NPC
	release
	end
AquaHideout_B2F_AquaWhyText:
	.string "Why?! Why did they do this?!\p"
	.string "This was an open passageway to the\n"
	.string "lounge corner before the remodel!\p"
	.string "But they walled it off and installed\n"
	.string "that teleporter… which just takes\l"
	.string "you to the room they walled off!\p"
	.string "Just… why?!\n"
	.string "Did they WANT this to be confusing?!$"

@ -----------------------------------------------------
@ Trigger: Napping on couch

AquaHideout_B2F_RestCouch::
	lockall
	goto_if_set FLAG_TEMP_1F, AquaHideout_B2F_RestCouch_Nope
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	message AquaHideout_B2F_RestCouch_Text, MSGTYPE_DESCRIBE
	waitmessage
	yesnobox 20, 8
	compare VAR_RESULT, NO
	goto_if_eq Common_EventScript_ReleaseAllEnd
	@ now napping
	setflag FLAG_TEMP_1F
	call Common_EventScript_PartyHealSave_Setup
	@ TODO: Walk player off couch?
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	@ Do the mourning cutscene, if needed
	domourning
	call Common_EventScript_PartyHealSave_Save
	@ Check for dream cutscenes
	dodreams
	call Common_EventScript_PartyHealSave_Complete
	release
	end
AquaHideout_B2F_RestCouch_Text:
	.string "This couch is very comfey…\n"
	.string "Take a quick nap?$"
AquaHideout_B2F_RestCouch_Nope:
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	message AquaHideout_B2F_RestCouch_NopeText, MSGTYPE_DESCRIBE
	waitmessage
	waitbuttonpress
	release
	end
AquaHideout_B2F_RestCouch_NopeText:
	.string "{PLAYER} takes a rest for a moment,\n"
	.string "not feeling tired.$"

@ -----------------------------------------------------

#define LID_MATT 1

AquaHideout_B2F_TriggerScript_Arrival:: @ 8233DE5
	lockall
	playse SE_PIN
	applymovement LID_MATT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LID_MATT, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	@ Clean up Slateport Heist, which didn't get seen
	setvar VAR_SLATEPORT_STATE, 2
	setvar VAR_SLATEPORT_HARBOR_STATE, 2
	setflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	setflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setflag FLAG_MET_TEAM_AQUA_HARBOR @ Blatant Lies
	setflag FLAG_TEAM_AQUA_STOLE_SUBMARINE
	setflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_PATRONS
	clearflag FLAG_HIDE_SLATEPORT_CITY_HARBOR_CAPTAIN_STERN
	releaseall
	end

AquaHideout_B2F_EventScript_233E09:: @ 8233E09
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_233EDD, AquaHideout_B2F_Text_233F8D, AquaHideout_B2F_EventScript_233E25
	msgbox AquaHideout_B2F_Text_233FF2a, MSGBOX_DEFAULT
	release
	end
AquaHideout_B2F_Text_233EDD: @ 8233EDD
	.string "Oh, hey. You're that new kid, huh?\p"
	.string "We just got back from the submarine\n"
	.string "hijacking.\p"
	.string "They're in there installing the Devon\n"
	.string "Goods so we can dive deeper than ever\l"
	.string "before.\p"
	.string "How are you liking the hideout?\p"
	.string "Oh, you wanna scrap? You sure?\p"
	.string "I'm a mite tougher than the others.\p"
	.string "Oh, you beat the others already, huh?\n"
	.string "Don't get a swollen head now.\l"
	.string "Let's go!$"
AquaHideout_B2F_Text_233F8D: @ 8233F8D
	.string "So, I lost, too…$"
AquaHideout_B2F_EventScript_233E25:: @ 8233E25
	markasdialog
	msgbox AquaHideout_B2F_Text_233FA6
	applymovement LID_MATT, Common_Movement_WalkInPlaceUp
	waitmovement 0
	playse SE_PIN
	applymovement LID_MATT, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	delay 20
	applymovement LID_MATT, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_233FF2
	setvar VAR_AQUA_HIDEOUT_STATE, 1
	release
	end
AquaHideout_B2F_Text_233FA6: @ 8233FA6
	.string "Wow, you are pretty strong.\p"
	.string "Maybe the boss'll promote you to my\n"
	.string "rank if you keep up that performance.$"
AquaHideout_B2F_Text_233FF2:
	.string "Uh, and maybe you'll get to prove\n"
	.string "yourself sooner than you think!\p"
AquaHideout_B2F_Text_233FF2a:
	.string "There's an intruder in the base.\n"
	.string "Some kid wearing a visor all wrong.\p"
	.string "Hold him off long enough for us to\n"
	.string "get out of here, will ya?$"

#undef LID_MATT
