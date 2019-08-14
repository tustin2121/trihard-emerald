MagmaHideout_4F_MapScripts:: @ 823A55F
	.byte 0

@ -----------------------------------------------------
@ Trainers


MagmaHideout_4F_EventScript_23A68C:: @ 823A68C
	trainerbattle_single TRAINER_GRUNT_48, MagmaHideout_4F_Text_23A6E8, MagmaHideout_4F_Text_23A775
	msgbox MagmaHideout_4F_Text_23A7B5, MSGBOX_AUTOCLOSE
	end
MagmaHideout_4F_Text_23A6E8: @ 823A6E8
	.string "I want to see Groudon, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about Groudon!$"
MagmaHideout_4F_Text_23A775: @ 823A775
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"
MagmaHideout_4F_Text_23A7B5: @ 823A7B5
	.string "I wonder if Groudon even has a tail?$"


MagmaHideout_4F_EventScript_23A6A3:: @ 823A6A3
	trainerbattle_single TRAINER_GRUNT_49, MagmaHideout_4F_Text_23A7DA, MagmaHideout_4F_Text_23A81B
	msgbox MagmaHideout_4F_Text_23A841, MSGBOX_AUTOCLOSE
	end
MagmaHideout_4F_Text_23A7DA: @ 823A7DA
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"
MagmaHideout_4F_Text_23A81B: @ 823A81B
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"
MagmaHideout_4F_Text_23A841: @ 823A841
	.string "Maxie, sir!\n"
	.string "An intruder is headed your way!$"


MagmaHideout_4F_EventScript_23A6BA:: @ 823A6BA
	trainerbattle_single TRAINER_GRUNT_50, MagmaHideout_4F_Text_23A86D, MagmaHideout_4F_Text_23A8A7
	msgbox MagmaHideout_4F_Text_23A8C6, MSGBOX_AUTOCLOSE
	end
MagmaHideout_4F_Text_23A86D: @ 823A86D
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"
MagmaHideout_4F_Text_23A8A7: @ 823A8A7
	.string "Was I that easy to knock down?$"
MagmaHideout_4F_Text_23A8C6: @ 823A8C6
	.string "C-come on, one more match…$"


MagmaHideout_4F_EventScript_23A6D1:: @ 823A6D1
	trainerbattle_single TRAINER_TABITHA_3, MagmaHideout_4F_Text_23A8E1, MagmaHideout_4F_Text_23A994
	msgbox MagmaHideout_4F_Text_23A9AC, MSGBOX_AUTOCLOSE
	end
MagmaHideout_4F_Text_23A8E1: @ 823A8E1
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, Groudon is sleeping!\p"
	.string "Maxie went to Groudon just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"
MagmaHideout_4F_Text_23A994: @ 823A994
	.string "Taken down again…\n"
	.string "Hehe…$"
MagmaHideout_4F_Text_23A9AC: @ 823A9AC
	.string "…And while you wasted time with me,\n"
	.string "Maxie should have awakened Groudon…$"


MagmaHideout_4F_EventScript_Logan::
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, MagmaHideout_4F_EventScript_Logan3
	goto_if_set FLAG_SCENE_6, MagmaHideout_4F_EventScript_Logan2
	msgbox MagmaHideout_4F_Text_Logan, MSGBOX_NPC
	setflag FLAG_SCENE_6
	end
MagmaHideout_4F_Text_Logan:
	.string "{RIVAL_HERO}: {PLAYER}!?\p"
	.string "Oh, to think I'd actually be {BOLD}happy{END}\n"
	.string "to see you for once.\p"
	.string "Listen, Maxie's ahead. He was too much\n"
	.string "for my team to handle.\p"
	.string "He's trying to wake up some ancient\n"
	.string "Pokémon. And once he does, who knows\l"
	.string "what kind of power he'll have at his\l"
	.string "disposal!? You gotta stop him!$"
MagmaHideout_4F_EventScript_Logan2:
	msgbox MagmaHideout_4F_Text_Logan2, MSGBOX_NPC
	end
MagmaHideout_4F_Text_Logan2:
	.string "{RIVAL_HERO}: You've beaten me a number\n"
	.string "of times! I know you can beat him!$"
MagmaHideout_4F_EventScript_Logan3:
	msgbox MagmaHideout_4F_Text_Logan3, MSGBOX_NPC
	end
MagmaHideout_4F_Text_Logan3:
	.string "{RIVAL_HERO}: S-So that's it?!\n"
	.string "You just let him get away?!\p"
	.string "How can you be so BAD at this?!$"
	

@ -----------------------------------------------------
@ Maxie

MagmaHideout_4F_EventScript_23A560:: @ 823A560
	lockall
	markasdialog
	playbgm MUS_MGM0, 0
	@ 
	msgbox MagmaHideout_4F_Text_23A9F4, MSGBOX_DEFAULT
	closemessage
	delay 20
	@ Sparkle
	setvar VAR_RESULT, 1
	playse SE_W197
	setfieldeffectargument 0, 16 @18
	setfieldeffectargument 1, 21 @42
	setfieldeffectargument 2, 0
	dofieldeffect FLDEFF_SPARKLE
	waitfieldeffect FLDEFF_SPARKLE
	@ SHINE!!!
	setvar VAR_RESULT, 1
	playfanfare MUS_ME_TAMA
	playse SE_TAMA
	special sub_80B0534 @Trigger shine
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 150
	removeobject 7
	addobject 1
	waitstate
	delay 60
	applymovement 1, MagmaHideout_4F_Movement_23A672
	waitmovement 0
	special sub_80B058C @ Trigger fade out
	waitstate
	@ Camera shake, Groudon walk forward
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	@ Camera shake, Groudon jump out
	applymovement 1, MagmaHideout_4F_Movement_23A67D
	waitmovement 0
	removeobject 1
	delay 4
	setvar VAR_0x8004, 2
	setvar VAR_0x8005, 2
	setvar VAR_0x8006, 8
	setvar VAR_0x8007, 5
	special DoCameraShakeEffect
	waitstate
	delay 30
	@ "What?! where?!"
	applymovement 6, MagmaHideout_4F_Movement_23A680
	waitmovement 0
	msgbox MagmaHideout_4F_Text_23AADA, MSGBOX_DEFAULT
	closemessage
	@
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	applymovement 6, Common_Movement_FacePlayer
	waitmovement 0
	@
	msgbox MagmaHideout_4F_Text_23AB33, MSGBOX_DEFAULT
	closemessage
	@ Battle
	trainerbattle_no_intro TRAINER_MAXIE_1, MagmaHideout_4F_Text_23ABB5
	@ 
	markasdialog
	msgbox MagmaHideout_4F_Text_23ABE2, MSGBOX_DEFAULT
	closemessage
	@ Clean up
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	call Common_EventScript_ClearSceneFlags
	fadescreen 1
	removeobject 6
	removeobject 2
	removeobject 3
	removeobject 4
	removeobject 5
	@ setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen 0
	releaseall
	end

MagmaHideout_4F_Text_23A9F4: @ 823A9F4
	.string "Maxie: Groudon…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This Blue Orb is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the Blue Orb.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"
MagmaHideout_4F_Text_23AADA: @ 823AADA
	.string "Maxie: Groudon!\n"
	.string "What's wrong?\p"
	.string "Wasn't the Blue Orb the key?\p"
	.string "Groudon!\n"
	.string "Where have you gone…$"
MagmaHideout_4F_Text_23AB33: @ 823AB33
	.string "Maxie: Oh, was it you?!\p"
	.string "I get it now! Team Aqua sent\n"
	.string "you to pull some cheap stunt!$"
MagmaHideout_4F_Text_23ABB5: @ 823ABB5
	.string "What stunt did you pull?\n"
	.string "Answer me!$"
MagmaHideout_4F_Text_23ABE2: @ 823ABE2
	.string "Maxie: There has to be some reason\n"
	.string "why Groudon fled…\p"
	.string "And you can no more tell me than\n"
	.string "that meddling kid over there…\p"
	.string "With Groudon gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after Groudon, so this\n"
	.string "is where we part!$"

MagmaHideout_4F_Movement_23A672: @ 823A672
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_23A67D: @ 823A67D
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_23A680: @ 823A680
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end





