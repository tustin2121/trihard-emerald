MtPyre_2F_MapScripts:: @ 82310FB
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Common_EventScript_FrameTable_IceStep_FallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, Common_EventScript_OnTransition_IceStep
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_OnResume
	.byte 0

@ -----------------------------------------------------

MtPyre_2F_OnResume: @ 823110B
	setstepcallback 7
	setholewarp MAP_MT_PYRE_1F, 255, 0, 0
	callnative MemoizeBoxedMon
	end

@ -----------------------------------------------------

MtPyre_2F_EventScript_231116:: @ 8231116
	compare VAR_TEMP_B, 0
	goto_if_gt MtPyre_2F_EventScript_231116_Alt
	msgbox MtPyre_2F_Text_2311A3, MSGBOX_NPC
	end
MtPyre_2F_Text_2311A3: @ 82311A3
	.string "Memories of my darling Skitty…\n"
	.string "My eyes overflow thinking about it.$"
MtPyre_2F_EventScript_231116_Alt:
	buffernumberstring2 0, VAR_TEMP_B
	msgbox MtPyre_2F_Text_2311A3_Alt, MSGBOX_NPC
	end
MtPyre_2F_Text_2311A3_Alt:
	.string "Memories of my darling Skitty…\n"
	.string "My eyes overflow thinking about it.\p"
	.string "Why aren't your eyes overflowing?\n"
.if TPP_MODE
	.string "{PAUSE 30}{FORCE_SPEED_MID}"
.endif
	.string "For the {STR_VAR_1} you lost?"
.if TPP_MODE
	.string "{PAUSE 60}"
.endif
	.string "$"


MtPyre_2F_EventScript_23111F:: @ 823111F
	msgbox MtPyre_2F_Text_2311E6, MSGBOX_NPC
	end
MtPyre_2F_Text_2311E6: @ 82311E6
	.string "Ooch, ouch… There are holes in the\n"
	.string "ground here and there.\p"
	.string "I didn't notice and took a tumble from\n"
	.string "the floor above.$"


MtPyre_2F_EventScript_231128:: @ 8231128
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_231258, MtPyre_2F_Text_2312A2
	msgbox MtPyre_2F_Text_2312CB, MSGBOX_AUTOCLOSE
	end
MtPyre_2F_Text_231258: @ 8231258
	.string "Hey! Are you searching for Pokémon?\n"
	.string "You came along after me! You're rude!$"
MtPyre_2F_Text_2312A2: @ 82312A2
	.string "Ayieeeeh!\n"
	.string "I'm sorry, forgive me, please!$"
MtPyre_2F_Text_2312CB: @ 82312CB
	.string "People don't come here often, so\n"
	.string "I thought there'd be rare Pokémon.$"


MtPyre_2F_EventScript_23113F:: @ 823113F
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_23130F, MtPyre_2F_Text_2313A1, MtPyre_2F_Text_231414
	msgbox MtPyre_2F_Text_2313B1, MSGBOX_AUTOCLOSE
	end
MtPyre_2F_Text_23130F: @ 823130F
	.string "Luke: We're here on a dare.\p"
	.string "Heheh, if I show her how cool I am,\n"
	.string "she'll fall for me. I know it!\p"
	.string "I know! I'll cream you and show her\n"
	.string "how cool I am!$"
MtPyre_2F_Text_2313A1: @ 82313A1
	.string "Luke: Whoopsie!$"
MtPyre_2F_Text_2313B1: @ 82313B1
	.string "Luke: Well, we lost but that's okay!\n"
	.string "I'm right here by your side.\l"
	.string "We'll make it through this dare!$"
MtPyre_2F_Text_231414: @ 8231414
	.string "Luke: If you want to take me on,\n"
	.string "bring some more Pokémon.\p"
	.string "If you don't, I won't be able to show\n"
	.string "off to my girl how cool I am!$"

MtPyre_2F_EventScript_23115A:: @ 823115A
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_231492, MtPyre_2F_Text_231534, MtPyre_2F_Text_231582
	msgbox MtPyre_2F_Text_23154D, MSGBOX_AUTOCLOSE
	end
MtPyre_2F_Text_231492: @ 8231492
	.string "Dez: I came here on a dare with my\n"
	.string "boyfriend.\p"
	.string "It's really scary, but I'm with my\n"
	.string "boyfriend. It's okay.\p"
	.string "I know! I'll get my boyfriend to look\n"
	.string "cool by beating you!$"
MtPyre_2F_Text_231534: @ 8231534
	.string "Dez: Waaaah! I'm scared!$"
MtPyre_2F_Text_23154D: @ 823154D
	.string "Dez: We're lovey-dovey, so we don't\n"
	.string "care if we lose!$"
MtPyre_2F_Text_231582: @ 8231582
	.string "Dez: If you want to challenge us, you\n"
	.string "should bring at least two Pokémon.\p"
	.string "My boyfriend's strong.\n"
	.string "Just one Pokémon won't do at all.$"



MtPyre_2F_EventScript_231175:: @ 8231175
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_231604, MtPyre_2F_Text_231645
	msgbox MtPyre_2F_Text_23165A, MSGBOX_AUTOCLOSE
	end
MtPyre_2F_Text_231604: @ 8231604
	.string "You are an unfamiliar sight…\n"
	.string "Depart before anything befalls you!$"
MtPyre_2F_Text_231645: @ 8231645
	.string "Hmm…\n"
	.string "You're durable.$"
MtPyre_2F_Text_23165A: @ 823165A
	.string "Our family have been trainers here\n"
	.string "since my great-grandmother's time…\p"
	.string "It is my duty to protect this\n"
	.string "mountain…$"


MtPyre_2F_EventScript_23118C:: @ 823118C
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_2316C7, MtPyre_2F_Text_2316E1
	msgbox MtPyre_2F_Text_2316FB, MSGBOX_AUTOCLOSE
	end
MtPyre_2F_Text_2316C7: @ 82316C7
	.string "Kiyaaaaah!\n"
	.string "I'm terrified!$"
MtPyre_2F_Text_2316E1: @ 82316E1
	.string "Nooooooo!\n"
	.string "I lost my wits!$"
MtPyre_2F_Text_2316FB: @ 82316FB
	.string "I get freaked out every time I see\n"
	.string "anything move…\p"
	.string "I shouldn't have come here to train…$"

