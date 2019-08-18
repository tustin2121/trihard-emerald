MtPyre_Summit_MapScripts:: @ 8231FF7
	map_script MAP_SCRIPT_ON_TRANSITION, MtPyre_Summit_OnTransition
	.byte 0

@ -----------------------------------------------------

#define LID_ARCHIE 2
#define LID_MAXIE 8
#define LID_AQUAGIRL 9
#define LID_AQUAGUY 10
#define LID_OLDWOMAN 3
#define LID_OLDMAN 1

MtPyre_Summit_OnTransition: @ 8231FFD
	compare VAR_MT_PYRE_STATE, 0
	call_if_eq MtPyre_Summit_OnTransition_SetSceneForTheft
	compare VAR_MT_PYRE_STATE, 2
	call_if_eq MtPyre_Summit_OnTransition_SetSceneForReturn
	compare VAR_MT_PYRE_STATE, 3
	call_if_eq MtPyre_Summit_OnTransition_SetSceneForAfterReturn
	end

MtPyre_Summit_OnTransition_SetSceneForTheft:
	setobjectxyperm LID_OLDMAN, 21, 3
	setobjectxyperm LID_OLDWOMAN, 25, 3
	setobjectxyperm LID_MAXIE, 24, 5
	setobjectxyperm LID_ARCHIE, 22, 5
	clearflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	end

MtPyre_Summit_OnTransition_SetSceneForReturn: @ 8232009
	setobjectxyperm LID_MAXIE, 23, 6
	setobjectxyperm LID_ARCHIE, 22, 6
	setobjectmovementtype LID_MAXIE, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LID_ARCHIE, MOVEMENT_TYPE_FACE_UP
	end

MtPyre_Summit_OnTransition_SetSceneForAfterReturn:
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_MAXIE
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	end

@ -----------------------------------------------------
@ People


MtPyre_Summit_EventScript_OldMan:: @ 823213C
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_SOOTOPOLIS_ARCHIE_MAXIE_LEAVE, MtPyre_Summit_EventScript_232167
	msgbox MtPyre_Summit_Text_232E0C, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq MtPyre_Summit_EventScript_232187
	compare VAR_RESULT, 0
	call_if_eq MtPyre_Summit_EventScript_232190
	release
	end
MtPyre_Summit_Text_232E0C: @ 8232E0C
	.string "Mt. Pyre is where we calm the spirits\n"
	.string "of Pokémon that have passed on…\p"
	.string "This is a high place where one can\n"
	.string "see all of Hoenn…\p"
	.string "The disembodied spirits of Pokémon\n"
	.string "must find solace here…\p"
	.string "Is it coincidence that you are here…\p"
	.string "Will you hear out my tale? A tale long\n"
	.string "told in the Hoenn region?$"
MtPyre_Summit_EventScript_232167:: @ 8232167
	msgbox MtPyre_Summit_Text_2331A6, MSGBOX_YESNO
	compare VAR_RESULT, 1
	call_if_eq MtPyre_Summit_EventScript_232199
	compare VAR_RESULT, 0
	call_if_eq MtPyre_Summit_EventScript_232190
	release
	end
MtPyre_Summit_Text_2331A6: @ 82331A6
	.string "It is my role to pass on the legends\n"
	.string "of Hoenn to future generations.\p"
	.string "And the crisis that just ended in\n"
	.string "Sootopolis rewrote a legend…\p"
	.string "Have you the time to hear the new\n"
	.string "legend of Hoenn?$"
MtPyre_Summit_EventScript_232187:: @ 8232187
	msgbox MtPyre_Summit_Text_232F27, MSGBOX_DEFAULT
	return
MtPyre_Summit_Text_232F27: @ 8232F27
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "infernos and vicious storms.\p"
	.string "The Blue Orb and the Red Orb brought\n"
	.string "an end to the calamity.\p"
	.string "Light poured from the two Orbs and\n"
	.string "becalmed the enraged adversaries.\p"
	.string "The pair, made docile, dove deep into\n"
	.string "the sea where eventually they\l"
	.string "disappeared…$"
MtPyre_Summit_EventScript_232199:: @ 8232199
	msgbox MtPyre_Summit_Text_23325D, MSGBOX_DEFAULT
	return
MtPyre_Summit_Text_23325D: @ 823325D
	.string "It happened long, long ago…\p"
	.string "The world was wracked by a ferocious\n"
	.string "clash between the Pokémon of the land\l"
	.string "and the Pokémon of the sea…\p"
	.string "The Pokémon of the land raised\n"
	.string "mountains and created continents…\p"
	.string "The Pokémon of the sea raised huge\n"
	.string "waves and carved out oceans…\p"
	.string "Their fierce duel raged without end.\p"
	.string "The world was engulfed in massive\n"
	.string "fires and vicious storms.\p"
	.string "It was then that the Pokémon of\n"
	.string "the sky descended from a storm.\p"
	.string "The Pokémon, shining a vivid green,\n"
	.string "becalmed the two enraged Pokémon.\p"
	.string "Then, its duty done, the green Pokémon\n"
	.string "flew off into the wild blue yonder…$"
MtPyre_Summit_EventScript_232190:: @ 8232190
	msgbox MtPyre_Summit_Text_233162, MSGBOX_DEFAULT
	return
MtPyre_Summit_Text_233162: @ 8233162
	.string "I see…\n"
	.string "Well, that, too, is fine…$"



MtPyre_Summit_EventScript_OldWoman:: @ 82321A2
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RETURNED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_2321E2
	compare VAR_MT_PYRE_STATE, 3
	call_if_ge MtPyre_Summit_EventScript_2321CB
	goto_if_set FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, MtPyre_Summit_EventScript_2321D8
	msgbox MtPyre_Summit_Text_232AD8, MSGBOX_DEFAULT
	release
	end
MtPyre_Summit_Text_232AD8: @ 8232AD8
	.string "The Blue Orb and Red Orb taken by\n"
	.string "those sinister men…\p"
	.string "They must never be apart…\n"
	.string "I fear something terrible will happen…$"
MtPyre_Summit_EventScript_2321CB:: @ 82321CB
	msgbox MtPyre_Summit_Text_232CA6, MSGBOX_DEFAULT
	setflag FLAG_RETURNED_RED_OR_BLUE_ORB
	release
	end
MtPyre_Summit_Text_232CA6: @ 8232CA6
	.string "The two men who took the Orbs came\n"
	.string "back to return them on their own.\p"
	.string "Those men…\n"
	.string "Perhaps they are not so evil after all…$"
MtPyre_Summit_EventScript_2321D8:: @ 82321D8
	msgbox MtPyre_Summit_Text_232B4F, MSGBOX_DEFAULT
	release
	end
MtPyre_Summit_Text_232B4F: @ 8232B4F
	.string "Oh, my goodness…\p"
	.string "You say that both Groudon and Kyogre\n"
	.string "have been awakened?\p"
	.string "It is said that the Blue Orb and\n"
	.string "the Red Orb quelled the rage of\l"
	.string "the two Pokémon…\p"
	.string "It is also said that the true owner\n"
	.string "of the Orbs still exists.\p"
	.string "However, no one knows who, or what\n"
	.string "exactly, the Orbs belong to.\p"
	.string "It could be a human, or perhaps\n"
	.string "a Pokémon, but no one knows.$"
MtPyre_Summit_EventScript_2321E2:: @ 82321E2
	msgbox MtPyre_Summit_Text_232D1E, MSGBOX_DEFAULT
	release
	end
MtPyre_Summit_Text_232D1E: @ 8232D1E
	.string "The embodiments of the land, sea,\n"
	.string "and the sky…\p"
	.string "That is said to be the identities of\n"
	.string "the super-ancient Pokémon…\p"
	.string "In the same way that we humans and\n"
	.string "Pokémon have life, our world, too,\l"
	.string "is alive…\p"
	.string "The super-ancient Pokémon have\n"
	.string "taught us that…$"

@ -----------------------------------------------------
@ Team Members

MtPyre_Summit_EventScript_AquaGirl1:: @ 82323FD
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, MtPyre_Summit_EventScript_AquaGirl3
	goto_if_set FLAG_SCENE_1, MtPyre_Summit_EventScript_AquaGirl2
	msgbox MtPyre_Summit_Text_23245G
	setflag FLAG_SCENE_1
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	release
	end
MtPyre_Summit_Text_23245G: @ 8232459
	.string "{AQUA_GIRL}: The boss is up ahead\n"
	.string "already! We gotta back him up!\p"
	.string "{PLAYER}, can you push ahead?$"
MtPyre_Summit_EventScript_AquaGirl2:
	msgbox MtPyre_Summit_Text_23245H
	release
	end
MtPyre_Summit_Text_23245H:
	.string "{AQUA_GIRL}: {PLAYER}! Try and get\n"
	.string "through the Magma guard!\p"
	.string "We'll keep any stragglers off\n"
	.string "your tail!$"
MtPyre_Summit_EventScript_AquaGirl3:
	msgbox MtPyre_Summit_Text_23245K
	release
	end
MtPyre_Summit_Text_23245K:
	.string "{AQUA_GIRL}: I'm gonna head back to\n"
	.string "the base to research that emblem.\p"
	.string "I'll be there if you need help.$"


MtPyre_Summit_EventScript_AquaGuy1:: @ 82323FD
	msgbox MtPyre_Summit_Text_23245Z, MSGBOX_NPC
	end
MtPyre_Summit_Text_23245Z: @ 8232459
	.string "No! Those Team Magma goons got\n"
	.string "here ahead of us!\p"
	.string "We can't fall behind!$"


MtPyre_Summit_EventScript_Magma1:: @ 8232414
	trainerbattle_single TRAINER_GRUNT_18, MtPyre_Summit_Text_232513, MtPyre_Summit_Text_2325B0
	msgbox MtPyre_Summit_Text_2325E4, MSGBOX_AUTOCLOSE
	end
MtPyre_Summit_Text_232513: @ 8232513
	.string "Hah!\n"
	.string "Too bad for you!\p"
	.string "If you had come earlier, you wouldn't\n"
	.string "have to take on us toughies!$"
MtPyre_Summit_Text_2325B0: @ 82325B0
	.string "Urgh… I should've just let you go\n"
	.string "on through…$"
MtPyre_Summit_Text_2325E4: @ 82325E4
	.string "What tipped you off to our plans?!\n"
	.string "How are you here at the same time?!$"


MtPyre_Summit_EventScript_Magma2:: @ 82323FD
	trainerbattle_single TRAINER_GRUNT_17, MtPyre_Summit_Text_232459, MtPyre_Summit_Text_2324A0
	msgbox MtPyre_Summit_Text_2324E0, MSGBOX_AUTOCLOSE
	end
MtPyre_Summit_Text_232459: @ 8232459
	.string "Too late, Aqua chumps!\n"
	.string "We got here first!$"
MtPyre_Summit_Text_2324A0: @ 82324A0
	.string "Maybe I'm the chump…$"
MtPyre_Summit_Text_2324E0: @ 82324E0
	.string "Yeah, so you are strong…\n"
	.string "But there're a lot of us!$"


MtPyre_Summit_EventScript_Magma3A:: @ 823242B
	trainerbattle_single TRAINER_GRUNT_19, MtPyre_Summit_Text_23261D, MtPyre_Summit_Text_232678
	msgbox MtPyre_Summit_Text_2326B3, MSGBOX_AUTOCLOSE
	end
MtPyre_Summit_Text_23261D: @ 823261D
	.string "Augh! Team Aqua's at the final line!$"
MtPyre_Summit_Text_232678: @ 8232678
	.string "Shoot, we couldn't hold them!$"
MtPyre_Summit_Text_2326B3: @ 82326B3
	.string "Heh, it doesn't matter!\n"
	.string "We bought ourselves some time!\p"
	.string "The boss should have snatched what\n"
	.string "he was after!$"


MtPyre_Summit_EventScript_Magma3B:: @ 8232442
	trainerbattle_single TRAINER_GRUNT_29, MtPyre_Summit_Text_23271B, MtPyre_Summit_Text_23279A
	msgbox MtPyre_Summit_Text_2327D8, MSGBOX_AUTOCLOSE
	end
MtPyre_Summit_Text_23271B: @ 823271B
	.string "Hold them back! Hold them back!$"
MtPyre_Summit_Text_23279A: @ 823279A
	.string "We tried our best…$"
MtPyre_Summit_Text_2327D8: @ 82327D8
	.string "We have a great combination going\n"
	.string "with us members and our leader.$"


@ -----------------------------------------------------
@ Cutscene: Stealing the Orbs


MtPyre_Summit_EventScript_OrbTheft::
	lockall
	playbgm MUS_MGM0, 0
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_X, 22
	@ Player runs up
	special SpawnCameraObject
	selectpointer MtPyre_Summit_MovementTable_OrbTheft1_Player, VAR_INTERACT_X
	applymovement EVENT_OBJ_ID_PLAYER, 0
	selectpointer MtPyre_Summit_MovementTable_OrbTheft1_Camera, VAR_INTERACT_X
	applymovement EVENT_OBJ_ID_CAMERA, 0
	waitmovement EVENT_OBJ_ID_CAMERA
	@ Others run up
	setobjectxyperm LID_AQUAGIRL, 22, 11
	addobject LID_AQUAGIRL
	applymovement LID_AQUAGIRL, Common_Movement_WalkUp3
	delay 16
	setobjectxyperm LID_AQUAGUY, 24, 11
	addobject LID_AQUAGUY
	applymovement LID_AQUAGUY, Common_Movement_WalkUp3
	waitmovement LID_AQUAGUY
	waitmovement LID_AQUAGIRL
	@ "so the calvary arrived"
	applymovement LID_MAXIE, Common_Movement_WalkInPlaceDown
	waitmovement 0
	markasdialog -10
	msgbox MtPyre_Summit_Text_OrbTheft3
	closemessage
	@ Magma Vanishes
	fadescreen 1
	removeobject LID_MAXIE
	removeobject 4
	removeobject 5
	removeobject 6
	removeobject 7
	setflag FLAG_HIDE_MT_PYRE_SUMMIT_ARCHIE
	@ setflag FLAG_HIDE_MT_PYRE_SUMMIT_TEAM_AQUA
	fadedefaultbgm
	delay 2
	fadescreen 0
	@ "He's gone!"
	applymovement EVENT_OBJ_ID_CAMERA, Common_Movement_WalkDown2
	applymovement LID_AQUAGUY, MtPyre_Summit_Movement_OrbTheft4_Guy
	applymovement LID_AQUAGIRL, MtPyre_Summit_Movement_OrbTheft4_Girl
	waitmovement 0
	markasdialog 8
	msgbox MtPyre_Summit_Text_OrbTheft4
	@
	markasdialog -6
	msgbox MtPyre_Summit_Text_OrbTheft5
	@
	markasdialog 6
	applymovement LID_ARCHIE, MtPyre_Summit_Movement_OrbTheft5
	message MtPyre_Summit_Text_OrbTheft6
	waitmovement 0
	applymovement LID_AQUAGIRL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	waitmessage
	waitbuttonpress
	@
	markasdialog -12
	applymovement LID_OLDWOMAN, MtPyre_Summit_Movement_OrbTheft6
	message MtPyre_Summit_Text_OrbTheft7
	waitmovement 0
	applymovement LID_ARCHIE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	waitmessage
	waitbuttonpress
	@
	markasdialog 6
	msgbox MtPyre_Summit_Text_OrbTheft8
	closemessage
	@
	applymovement LID_ARCHIE, MtPyre_Summit_Movement_OrbTheft8_Archie
	applymovement LID_AQUAGIRL, MtPyre_Summit_Movement_OrbTheft8_AquaGirl
	applymovement LID_AQUAGUY, MtPyre_Summit_Movement_OrbTheft8_AquaGuy
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_OrbTheft8_Player
	applymovement EVENT_OBJ_ID_CAMERA, MtPyre_Summit_Movement_OrbTheft8_Camera
	waitmovement LID_ARCHIE
	@
	markasdialog -8
	msgbox MtPyre_Summit_Text_OrbTheft9
	waitmovement LID_AQUAGIRL
	waitmovement EVENT_OBJ_ID_PLAYER
	waitmovement EVENT_OBJ_ID_CAMERA
	removeobject LID_AQUAGUY
	@
	giveitem_std ITEM_MAGMA_EMBLEM
	@
	setyesnotext gYN_YesSir, gYN_Uhhh
	msgbox MtPyre_Summit_Text_OrbTheft10, MSGBOX_YESNO
	@
	selectpointer MtPyre_Summit_StringTable_OrbTheft10, VAR_RESULT
	markasdialog 6
	message 0
	waitmessage
	@
	markasdialog -8
	msgbox MtPyre_Summit_Text_OrbTheft11
	closemessage
	applymovement LID_ARCHIE, MtPyre_Summit_Movement_OrbTheft8_AquaGuy
	delay 16
	applymovement LID_AQUAGIRL, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement EVENT_OBJ_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement LID_ARCHIE
	removeobject LID_ARCHIE
	waitmovement EVENT_OBJ_ID_CAMERA
	special RemoveCameraObject
	@ Clean up
	setvar VAR_MT_PYRE_STATE, 1
	setflag FLAG_RECEIVED_RED_OR_BLUE_ORB
	setflag FLAG_HIDE_JAGGED_PASS_MAGMA_GUARD
	call Common_EventScript_ClearSceneFlags
	setobjectxyperm LID_OLDMAN, 22, 5
	setobjectxyperm LID_OLDWOMAN, 23, 5
	releaseall
	end

MtPyre_Summit_Text_OrbTheft3:
	.string "Maxie: Ah, so the calvary arrived.\p"
	.string "I suppose that means it's time to make\n"
	.string "my departure.\p"
	.string "No matter, I got what I came for.\p"
	.string "See you around, Archie!$"
MtPyre_Summit_Text_OrbTheft4:
	.string "{AQUA_GIRL}: He's gone!\p"
	.string "How did he do that?!$"
MtPyre_Summit_Text_OrbTheft5:
	.string "The rest of Team Magma are gone too!$"
MtPyre_Summit_Text_OrbTheft6:
	.string "Archie: It doesn't matter.\p"
	.string "Good work, everyone. We got what we\n"
	.string "came for as well.\p"
	.string "Time to pull out!$"
MtPyre_Summit_Text_OrbTheft7:
	.string "No! Please!\p"
	.string "The Blue Orb and Red Orb must never\n"
	.string "be separated! They belong together!$"
MtPyre_Summit_Text_OrbTheft8:
	.string "Archie: I'm sure this Red Orb will\n"
	.string "see its blue brother soon enough.\p"
	.string "Fwahahahahaha…$"
MtPyre_Summit_Text_OrbTheft9:
	.string "Archie: You two. I have a task for you.\p"
	.string "Maxie dropped this during our battle\n"
	.string "in a moment of panic.\p"
	.string "No, not the Orb. This.$"
MtPyre_Summit_Text_OrbTheft10:
	.string "Archie: I believe this is the key\n"
	.string "to finding their secret base.\p"
	.string "Perhaps if we find it, we can\n"
	.string "bring down their whole operation.\p"
	.string "We need you two to do this while we\n"
	.string "focus on our next move.\p"
	.string "Can you two handle this?$"
MtPyre_Summit_Text_OrbTheft10a:
	.string "{AQUA_GIRL}: I'll have {PLAYER_their} back, sir!\p$"
MtPyre_Summit_Text_OrbTheft10b:
	.string "{AQUA_GIRL}: Y-Yes sir!\p$"
MtPyre_Summit_Text_OrbTheft11:
	.string "Archie: Excellent!\p"
	.string "I'll be expecting a full report!$"

.align 2
MtPyre_Summit_MovementTable_OrbTheft1_Player:
	.4byte MtPyre_Summit_Movement_OrbTheft1_Player0
	.4byte MtPyre_Summit_Movement_OrbTheft1_Player1
	.4byte MtPyre_Summit_Movement_OrbTheft1_Player2
	.4byte 0
MtPyre_Summit_MovementTable_OrbTheft1_Camera:
	.4byte MtPyre_Summit_Movement_OrbTheft1_Camera0
	.4byte MtPyre_Summit_Movement_OrbTheft1_Camera1
	.4byte MtPyre_Summit_Movement_OrbTheft1_Camera2
	.4byte 0
MtPyre_Summit_StringTable_OrbTheft10:
	.4byte MtPyre_Summit_Text_OrbTheft10b
	.4byte MtPyre_Summit_Text_OrbTheft10a
	.4byte 0

MtPyre_Summit_Movement_OrbTheft1_Player0:
	walk_up
	walk_right
	walk_up
	walk_up
	step_end
MtPyre_Summit_Movement_OrbTheft1_Player1:
	walk_up
	walk_up
	walk_up
	step_end
MtPyre_Summit_Movement_OrbTheft1_Player2:
	walk_up
	walk_left
	walk_up
	walk_up
	step_end

MtPyre_Summit_Movement_OrbTheft1_Camera0:
	walk_up
	walk_diag_northeast
	walk_up
	walk_up
	walk_up
	step_end
MtPyre_Summit_Movement_OrbTheft1_Camera1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
MtPyre_Summit_Movement_OrbTheft1_Camera2:
	walk_up
	walk_diag_northwest
	walk_up
	walk_up
	walk_up
	step_end

MtPyre_Summit_Movement_OrbTheft4_Girl:
	emote_exclamation_mark
	delay_16
	delay_16
	walk_fast_up
	walk_fast_up
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end
MtPyre_Summit_Movement_OrbTheft4_Guy:
	emote_exclamation_mark
	delay_16
	delay_16
	walk_in_place_fastest_down
	delay_16
	delay_8
	delay_2
	walk_in_place_fastest_up
	step_end

MtPyre_Summit_Movement_OrbTheft5:
	walk_right
	walk_down
	step_end

MtPyre_Summit_Movement_OrbTheft6:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_OrbTheft8_Archie:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_left
	step_end
MtPyre_Summit_Movement_OrbTheft8_Player:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_right
	step_end
MtPyre_Summit_Movement_OrbTheft8_AquaGirl:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_right
	step_end
MtPyre_Summit_Movement_OrbTheft8_AquaGuy:
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
MtPyre_Summit_Movement_OrbTheft8_Camera:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

@ -----------------------------------------------------

MtPyre_Summit_EventScript_2321EC:: @ 82321EC
	lockall
	setvar VAR_0x8008, 0
	goto MtPyre_Summit_EventScript_232210
	end

MtPyre_Summit_EventScript_2321F8:: @ 82321F8
	lockall
	setvar VAR_0x8008, 1
	goto MtPyre_Summit_EventScript_232210
	end

MtPyre_Summit_EventScript_232204:: @ 8232204
	lockall
	setvar VAR_0x8008, 2
	goto MtPyre_Summit_EventScript_232210
	end

MtPyre_Summit_EventScript_232210:: @ 8232210
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 60
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_2322C4
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_2322DD
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_2322F6
	playse SE_PIN
	applymovement 8, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement 8, Common_Movement_Delay48
	waitmovement 0
	delay 30
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_23230F
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_232328
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_232341
	msgbox MtPyre_Summit_Text_233183, MSGBOX_DEFAULT
	closemessage
	compare VAR_0x8008, 0
	call_if_eq MtPyre_Summit_EventScript_23235A
	compare VAR_0x8008, 1
	call_if_eq MtPyre_Summit_EventScript_232376
	compare VAR_0x8008, 2
	call_if_eq MtPyre_Summit_EventScript_232392
	delay 30
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	removeobject 2
	removeobject 8
	setvar VAR_MT_PYRE_STATE, 3
	releaseall
	end

MtPyre_Summit_EventScript_2322C4:: @ 82322C4
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323C4
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	return

MtPyre_Summit_EventScript_2322DD:: @ 82322DD
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323CB
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	return

MtPyre_Summit_EventScript_2322F6:: @ 82322F6
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323D2
	applymovement 2, MtPyre_Summit_Movement_2323B6
	applymovement 8, MtPyre_Summit_Movement_2323BD
	waitmovement 0
	return

MtPyre_Summit_EventScript_23230F:: @ 823230F
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323AE
	applymovement 2, MtPyre_Summit_Movement_2323E7
	applymovement 8, MtPyre_Summit_Movement_2323D8
	waitmovement 0
	return

MtPyre_Summit_EventScript_232328:: @ 8232328
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323B2
	applymovement 2, MtPyre_Summit_Movement_2323E7
	applymovement 8, MtPyre_Summit_Movement_2323DD
	waitmovement 0
	return

MtPyre_Summit_EventScript_232341:: @ 8232341
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323B2
	applymovement 2, MtPyre_Summit_Movement_2323E7
	applymovement 8, MtPyre_Summit_Movement_2323E2
	waitmovement 0
	return

MtPyre_Summit_EventScript_23235A:: @ 823235A
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323EA
	applymovement 8, MtPyre_Summit_Movement_2323ED
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_232376:: @ 8232376
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323EA
	applymovement 8, MtPyre_Summit_Movement_2323F3
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_EventScript_232392:: @ 8232392
	applymovement EVENT_OBJ_ID_PLAYER, MtPyre_Summit_Movement_2323EA
	applymovement 8, MtPyre_Summit_Movement_2323F8
	waitmovement 0
	applymovement 2, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

MtPyre_Summit_Movement_2323AE: @ 82323AE
	delay_16
	delay_16
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_2323B2: @ 82323B2
	delay_16
	delay_16
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_2323B6: @ 82323B6
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_2323BD: @ 82323BD
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtPyre_Summit_Movement_2323C4: @ 82323C4
	delay_16
	delay_8
	walk_left
	walk_in_place_fastest_right
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323CB: @ 82323CB
	delay_16
	delay_8
	walk_right
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323D2: @ 82323D2
	delay_16
	delay_8
	walk_in_place_fastest_left
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323D8: @ 82323D8
	walk_up
	walk_up
	walk_up
	walk_left
	step_end

MtPyre_Summit_Movement_2323DD: @ 82323DD
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_2323E2: @ 82323E2
	walk_up
	walk_up
	walk_up
	walk_in_place_fastest_right
	step_end

MtPyre_Summit_Movement_2323E7: @ 82323E7
	delay_16
	walk_in_place_fastest_up
	step_end

MtPyre_Summit_Movement_2323EA: @ 82323EA
	delay_16
	walk_in_place_fastest_down
	step_end

MtPyre_Summit_Movement_2323ED: @ 82323ED
	walk_down
	walk_right
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_2323F3: @ 82323F3
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Movement_2323F8: @ 82323F8
	walk_down
	walk_down
	walk_down
	walk_in_place_fastest_left
	step_end

MtPyre_Summit_Text_233183: @ 8233183
	.string "MAXIE: {PLAYER}…\p"
	.string "… … … … … …\n"
	.string "… … … … … …$"


#undef LID_ARCHIE
#undef LID_MAXIE
#undef LID_AQUAGIRL
#undef LID_AQUAGUY
#undef LID_OLDWOMAN
