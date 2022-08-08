
Text_MonUsedHM: @ 8290771
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

@ -----------------------------------------------------
@ Cut

EventScript_CutTree:: @ 82906BB
	lockall
	goto_if_unset FLAG_BADGE01_GET, EventScript_CheckTreeCantCut
	checkpartycapability CAPABILITY_CUT
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CheckTreeCantCut
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	@ buffermovename 1, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	msgbox Text_MonUsedCut, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end
Text_WantToCut: @ 829072E
	.string "This tree looks like it can be\n"
	.string "chopped down. \p"
	.string "Would you like to cut it down?$"
Text_MonUsedCut:
	.string "{STR_VAR_1} sliced at the tree!$"
EventScript_FldEffCut:: @ 8290705
	lockall
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
	goto EventScript_CutTreeDown
	end
EventScript_CutTreeDown:: @ 8290710
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end
Movement_CutTreeDown: @ 829071F
	cut_tree
	step_end
EventScript_CheckTreeCantCut:: @ 8290721
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end
Text_CantCut: @ 829077D
	.string "This tree looks like it can be\n"
	.string "chopped down!$"

@ -----------------------------------------------------
@ Rock Smash

EventScript_RockSmash:: @ 82907A6
	lockall
	goto_if_unset FLAG_BADGE03_GET, EventScript_CantSmashRock
	checkpartycapability CAPABILITY_ROCK_SMASH
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantSmashRock
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	msgbox Text_MonUsedSmash, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end
Text_WantToSmash: @ 829083A
	.string "This rock appears to be breakable.\n"
	.string "Would you like to smash it?$"
Text_MonUsedSmash:
	.string "{STR_VAR_1} struck the rock!$"
EventScript_FldEffRockSmash:: @ 82907F0
	lockall
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
	goto EventScript_SmashRock
	end
EventScript_SmashRock:: @ 82907FB
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	compare VAR_RESULT, 1
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	special RockSmashWildEncounter
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	waitstate
	releaseall
	end
Movement_SmashRock: @ 829082B
	rock_smash_break
	step_end
EventScript_CantSmashRock:: @ 829082D
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end
Text_CantSmash: @ 829087F
	.string "It's a rugged rock, but a Pokémon\n"
	.string "may be able to smash it.$"

@ -----------------------------------------------------
@ Strength

EventScript_StrengthBoulder:: @ 82908BA
	lockall
	goto_if_unset FLAG_BADGE04_GET, EventScript_CantStrength
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkpartycapability CAPABILITY_STRENGTH
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantStrength
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end
Text_WantToStrength: @ 829092C
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to push it?$"
EventScript_FldEffStrength:: @ 82908FD
	lockall
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	goto EventScript_ActivateStrength
	end
EventScript_ActivateStrength:: @ 8290908
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end
Text_MonUsedStrength: @ 829098C
	.string "{STR_VAR_1} steeled itself!\p"
	.string "{STR_VAR_1}'s is now ready\n"
	.string "to move boulders around!$"
EventScript_CantStrength:: @ 8290915
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end
Text_CantStrength: @ 82909D6
	.string "It's a big boulder, but a Pokémon\n"
	.string "may be able to push it aside.$"
EventScript_CheckActivatedBoulder:: @ 829091F
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end
Text_StrengthActivated: @ 8290A16
	.string "Your Pokémon is prepped to move\n"
	.string "boulders around.$"

@ -----------------------------------------------------
@ Waterfalls

EventScript_UseWaterfall:: @ 8290A49
	lockall
	checkpartycapability CAPABILITY_WATERFALL
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantWaterfall
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	msgbox Text_MonUsedWaterfall, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_WATERFALL
	goto Common_EventScript_CloseReleaseAllEnd
	end
Text_WantToWaterfall: @ 8290AC3
	.string "It's a large waterfall.\n"
	.string "Would you like to climb it?$"
Text_MonUsedWaterfall: @ 8290AFC
	.string "{STR_VAR_1} rushes up the falls.$"
EventScript_CannotUseWaterfall:: @ 8290A83
	lockall
EventScript_CantWaterfall:: @ 8290A84
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
	releaseall
	end
Text_CantWaterfall: @ 8290A8E
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

@ -----------------------------------------------------

EventScript_UseDive:: @ 8290B0F
	lockall
	checkpartycapability CAPABILITY_DIVE
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantDive
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	msgbox Text_MonDove, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto Common_EventScript_CloseReleaseAllEnd
	end
Text_WantToDive: @ 8290BE8
	.string "The sea is deep here.\n"
	.string "Would you like to dive down?$"
Text_MonDove: @ 8290C1A
	.string "{STR_VAR_1} dove underwater.$"
EventScript_CantDive:: @ 8290B4E
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end
Text_CantDive: @ 8290BAA
	.string "The sea is deep here. A Pokémon\n"
	.string "should be able to go underwater.$"

EventScript_UseDiveUnderwater:: @ 8290B5A
	lockall
	checkpartycapability CAPABILITY_DIVE
	compare VAR_RESULT, 6
	goto_if_eq EventScript_CantSurface
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	msgbox Text_MonSurfaced, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_DIVE
	goto Common_EventScript_CloseReleaseAllEnd
	end
Text_WantToSurface: @ 8290C6E
	.string "Light is filtering down from above.\n"
	.string "Would you like to surface?$"
Text_MonSurfaced: @ 8290C1A
	.string "{STR_VAR_1} rose to the surface.$"

EventScript_CantSurface:: @ 8290B99
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto Common_EventScript_CloseReleaseAllEnd
	end
Text_CantSurface: @ 8290C28
	.string "Light is filtering down from above.\n"
	.string "A Pokémon may be able to surface.$"

@ -----------------------------------------------------
@ Surf

EventScript_UseSurf:: @ 8271EA0
	checkpartycapability CAPABILITY_SURF
	compare VAR_RESULT, 6
	goto_if_eq Common_EventScript_NopEnd
	bufferpartymonnick 0, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_CloseReleaseAllEnd
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	setflag FLAG_PLAYER_HAS_SURFED
	dofieldeffect FLDEFF_USE_SURF
	goto Common_EventScript_CloseReleaseAllEnd
gText_WantToUseSurf:: @ 8272FD6
	.string "The water is dyed a deep blue…\n"
	.string "Would you like to surf?$"

gText_PlayerUsedSurf:: @ 827300D
	.string "{STR_VAR_1} jumped into the waves!$"


@ -----------------------------------------------------
@ Sweet Scent

EventScript_FailSweetScent:: @ 8290CAE
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end
Text_FailSweetScent: @ 8290CB7
	.string "Looks like there's nothing here…$"
