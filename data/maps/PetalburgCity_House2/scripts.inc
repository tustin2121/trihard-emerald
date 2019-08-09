PetalburgCity_House2_MapScripts:: @ 82078F2
	.byte 0

PetalburgCity_House2_EventScript_2078F3:: @ 82078F3
	compare VAR_PETALBURG_STATE, 10
	goto_if_lt PetalburgCity_House2_EventScript_2078F4
	msgbox PetalburgCity_House2_Text_207905, MSGBOX_NPC
	end
PetalburgCity_House2_Text_207905: @ 8207905
	.string "Norman became our town's new\n"
	.string "Gym Leader.\p"
	.string "I think he called his family over from\n"
	.string "somewhere far away.$"
PetalburgCity_House2_EventScript_2078F4:
	msgbox PetalburgCity_House2_Text_207906, MSGBOX_NPC
	end
PetalburgCity_House2_Text_207906:
	.string "Malaqui has been our town's\n"
	.string "Gym Leader for many years.\p"
	.string "He uses Dark-type Pokémon. He's\n"
	.string "really tough. And he's kinda mean.$"


PetalburgCity_House2_EventScript_2078FC:: @ 82078FC
	compare VAR_PETALBURG_STATE, 10
	goto_if_lt PetalburgCity_House2_EventScript_2078FD
	msgbox PetalburgCity_House2_Text_207969, MSGBOX_NPC
	end
PetalburgCity_House2_Text_207969: @ 8207969
	.string "Did you hear about the new Gym Leader,\n"
	.string "Norman?\p"
	.string "I can't wait to try my hand at a\n"
	.string "battle with him!$"
PetalburgCity_House2_EventScript_2078FD:
	msgbox PetalburgCity_House2_Text_20796A, MSGBOX_NPC
	end
PetalburgCity_House2_Text_20796A:
	.string "I battled Malaqui once, but, whew,\n"
	.string "he was way too strong.\p"
	.string "How would I put it?\p"
	.string "I just get the feeling that he\n"
	.string "loves pummeling his opponents.$"
