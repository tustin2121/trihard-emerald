SlateportCity_OceanicMuseum_1F_MapScripts:: @ 820AD95
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_OceanicMuseum_1F_MapTable
	.byte 0

SlateportCity_OceanicMuseum_1F_MapTable:
	map_script_2 VAR_SLATEPORT_MUSEUM_HEIST_STATE, 1, SlateportCity_OceanicMuseum_1F_PositionForHeist
	.2byte 0

SlateportCity_OceanicMuseum_1F_PositionForHeist:
	turnobject EVENT_OBJ_ID_PLAYER, DIR_NORTH
	end


@ -----------------------------------------------------
@ Entrance Fee

SlateportCity_OceanicMuseum_1F_TriggerScript_EntranceLeft:: @ 820AD9F
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_EntrancePay
	end
SlateportCity_OceanicMuseum_1F_TriggerScript_EntranceRight:: @ 820ADB0
	lockall
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_EntrancePay
	end
SlateportCity_OceanicMuseum_1F_EventScript_EntrancePay:: @ 820ADC1
	markasdialog
	goto_if_unset FLAG_DELIVERED_DEVON_GOODS, SlateportCity_OceanicMuseum_1F_EventScript_20AE39
	showmoneybox 0, 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20AFD5, MSGBOX_YESNO
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20ADE8
	closemessage
	hidemoneybox
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	releaseall
	end
SlateportCity_OceanicMuseum_1F_Text_20AFD5: @ 820AFD5
	.string "Welcome to the {PLACE}Oceanic Museum{END}.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?$"
SlateportCity_OceanicMuseum_1F_EventScript_20ADE8:: @ 820ADE8
	checkmoney 50, 0
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AE18
	playse SE_REGI
	takemoney 50, 0
	updatemoneybox 0, 0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B026, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	hidemoneybox
	releaseall
	end
SlateportCity_OceanicMuseum_1F_EventScript_EntranceLady:: @ 820AD96
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B026, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B026: @ 820B026
	.string "Please enjoy yourself.$"
SlateportCity_OceanicMuseum_1F_EventScript_20AE18:: @ 820AE18
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B03D, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	releaseall
	end
SlateportCity_OceanicMuseum_1F_Text_20B03D: @ 820B03D
	.string "Oh? I'm sorry, but you don't seem to\n"
	.string "have enough money.$"
SlateportCity_OceanicMuseum_1F_EventScript_20AE39:: @ 820AE39
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B075, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 1
	releaseall
	end
SlateportCity_OceanicMuseum_1F_Text_20B075: @ 820B075
	.string "Welcome to the {PLACE}Oceanic Museum{END}.\p"
	.string "The entrance fee is ¥50.\n"
	.string "Would you like to enter?\p"
	.string "Oh? You're with that group that\n"
	.string "went in earlier?\p"
	.string "You'd better go catch up to them!$"


@ -----------------------------------------------------
@ Exhibits

SlateportCity_OceanicMuseum_1F_EventScript_20AE83:: @ 820AE83
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B4CF, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B4CF: @ 820B4CF
	.string "{CENTER}The spiraling blue fluid in this glass\n"
	.string "{CENTER}vessel is an experiment to create an\n"
	.string "{CENTER}artificial whirlpool using wind.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE8C:: @ 820AE8C
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B547, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B547: @ 820B547
	.string "{CENTER}This is an experiment simulating a\n"
	.string "{CENTER}waterfall using the red ball's buoyancy.\n"
	.string "{CENTER}Note how it bobs up and down in the\n"
	.string "{CENTER}middle of the two fluids.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE95:: @ 820AE95
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B5CA, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B5CA: @ 820B5CA
	.string "{CENTER}{ITEM}Soil Sample from the Ocean Floor{END}\n"
	.string "{CENTER}Over many years, the remains of life-\n"
	.string "{CENTER}forms settle at the bottom of the sea,\n"
	.string "{CENTER}making sedimentary layers. By analyzing\n"
	.string "{CENTER}them, our ancient past is revealed.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE9E:: @ 820AE9E
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B699, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B699: @ 820B699
	.string "{CENTER}{ITEM}Sample of Beach Sand{END}\n"
	.string "{CENTER}Stones from mountains are washed down\n"
	.string "{CENTER}by rivers where they are chipped and\l"
	.string "{CENTER}ground down. They are reduced to grains\n"
	.string "{CENTER}and end up as sand on beaches.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEA7:: @ 820AEA7
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B74B, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B74B: @ 820B74B
	.string "{CENTER}{TIPS}OCEANIC MINIFACT 1{END}\n"
	.string "{CENTER}Why is seawater blue? Light is composed\p"
	.string "{CENTER}of many colors. When light passes\p"
	.string "{CENTER}through the water, it loses color.\n"
	.string "{CENTER}However, blue light retains its\n"
	.string "{CENTER}color, making the sea appear blue.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEB0:: @ 820AEB0
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B81F, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B81F: @ 820B81F
	.string "{CENTER}{TIPS}OCEANIC MINIFACT 2{END}\n"
	.string "{CENTER}Why is the sea salty? Seawater contains\p"
	.string "{CENTER}dissolved salt in the form of sodium\n"
	.string "{CENTER}and chlorine ions. These ions leech out\p"
	.string "{CENTER}of rocks and are carried out to sea by\n"
	.string "{CENTER}rain. The concentration of dissolved\p"
	.string "{CENTER}salt makes the sea salty.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEB9:: @ 820AEB9
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B912, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B912: @ 820B912
	.string "{CENTER}{TIPS}OCEANIC MINIFACT 3{END}\n"
	.string "{CENTER}Which is bigger? Sea or land? The sea\p"
	.string "{CENTER}covers about 70% of the planet, while\n"
	.string "{CENTER}the rest is land. The sea is therefore\p"
	.string "{CENTER}more than twice the size of land.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEC2:: @ 820AEC2
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B9C0, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_1F_Text_20B9C0: @ 820B9C0
	.string "{CENTER}It's a fossil with wavy ridges on it.\p"
	.string "{CENTER}Soil on the ocean floor gets scoured\n"
	.string "{CENTER}by the tide. The flowing seawater marks\n"
	.string "{CENTER}the soil with small ridges and valleys.\p"
	.string "{CENTER}If this soil becomes fossilized, it is\n"
	.string "{CENTER}called a ripple mark.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AECB:: @ 820AECB
	msgbox SlateportCity_OceanicMuseum_1F_Text_20BA9C, MSGBOX_DESCRIBE
	end
SlateportCity_OceanicMuseum_1F_Text_20BA9C: @ 820BA9C
	.string "A strange machine is rotating under\n"
	.string "a glass dome.\p"
	.string "Maybe it's for measuring the depth\n"
	.string "of something…$"


@ -----------------------------------------------------
@ People

SlateportCity_OceanicMuseum_1F_EventScript_20AED4:: @ 820AED4
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B25F, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B25F: @ 820B25F
	.string "I want to learn about the sea and\n"
	.string "use that knowledge for battling.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEDD:: @ 820AEDD
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B2A2, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B2A2: @ 820B2A2
	.string "I get all giddy and gooey when\n"
	.string "I see the sea!\p"
	.string "For me, Capt. Stern is the number\n"
	.string "one role model!$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEE6:: @ 820AEE6
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B302, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B302: @ 820B302
	.string "The sea is vast without end, and\n"
	.string "infinitely deep…\p"
	.string "There must be many Pokémon that\n"
	.string "we don't know about.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AEEF:: @ 820AEEF
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B369, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B369: @ 820B369
	.string "I want a sea Pokémon.\p"
	.string "I think it would feel cool and nice\n"
	.string "to hug.$"



@ -----------------------------------------------------
@ Team Aqua

SlateportCity_OceanicMuseum_1F_EventScript_20AE56:: @ 820AE56
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B112, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B112: @ 820B112
	.string "We were told to assemble here,\n"
	.string "so we did, but…\p"
	.string "Our boss, the linchpin, isn't here yet.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE5F:: @ 820AE5F
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B165, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B165: @ 820B165
	.string "If I stole the stuff here,\n"
	.string "would it make me rich?\p"
	.string "Uh, don't tell {AQUA_GIRL} I said that.$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE68:: @ 820AE68
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B19C, MSGBOX_DIALOG
	end
SlateportCity_OceanicMuseum_1F_Text_20B19C: @ 820B19C
	.string "What I learn here, I can put to use on\n"
	.string "later missions for the boss…$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE71:: @ 820AE71
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM46, SlateportCity_OceanicMuseum_1F_EventScript_20AE72
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B1D4
	giveitem_std ITEM_TM46
	compare VAR_RESULT, 0
	goto_if_eq SlateportCity_OceanicMuseum_1F_EventScript_20AFB5
	setflag FLAG_RECEIVED_TM46
	@ fallthrough
SlateportCity_OceanicMuseum_1F_EventScript_20AE72:
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B449, MSGBOX_DEFAULT
	release
	end
SlateportCity_OceanicMuseum_1F_Text_20B1D4: @ 820B1D4
	.string "Hey! It's the Skull kid! The one that\n"
	.string "helped the guys back in Rustboro!\p"
	.string "I got something for ya. It suits you\n"
	.string "more than it suits {AQUA_BOY} and 'em!$"
SlateportCity_OceanicMuseum_1F_Text_20B449:
	.string "That TM teaches Thief!\p"
	.string "Thief! Get it! Gwahahahaha!$"
SlateportCity_OceanicMuseum_1F_EventScript_20AFB5:: @ 820AFB5
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B49B
	release
	end
SlateportCity_OceanicMuseum_1F_Text_20B49B:
	.string "Ah, but ya got no room! What is this?!$"


SlateportCity_OceanicMuseum_1F_EventScript_20AE7A:: @ 820AE7A
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B218, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_1F_Text_20B218: @ 820B218
	.string "I didn't have ¥50, so it took a long\n"
	.string "time getting by the receptionist.$"


SlateportCity_OceanicMuseum_1F_EventScript_AquaGirl:: @ 820AE4D
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_SCENE_1, SlateportCity_OceanicMuseum_1F_EventScript_AquaGirlA
	selectpointer_clamp SlateportCity_OceanicMuseum_1F_TextArray_AquaGirl, VAR_AQUA_GIRL_FRIENDSHIP
	msgbox_selected 
	setflag FLAG_SCENE_1
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	release
	end
SlateportCity_OceanicMuseum_1F_EventScript_AquaGirlA:
	msgbox SlateportCity_OceanicMuseum_1F_Text_20B0E8
	release
	end
SlateportCity_OceanicMuseum_1F_Text_20B0E8: @ 820B0E8
	.string "{AQUA_GIRL}: I just love visiting this\n"
	.string "museum.\p"
	.string "I joined Team Aqua because of a shared\n"
	.string "love of the sea and everything in it.\p"
	.string "I wanna become a marine biologist\n"
	.string "when I grow up.$"
.align 2
SlateportCity_OceanicMuseum_1F_TextArray_AquaGirl:
	.4byte SlateportCity_OceanicMuseum_Text_AquaGirl1
	.4byte SlateportCity_OceanicMuseum_Text_AquaGirl2
	.4byte 0
SlateportCity_OceanicMuseum_Text_AquaGirl1:
	.string "I just love visiting this museum.\p"
	.string "You're the one who helped us get the\n"
	.string "Devon Goods!\p"
	.string "My name's {AQUA_GIRL}. What's yours?\p"
	.string "{PLAYER}? Nice name.\p"
	.string "What do you think of the museum?\n"
	.string "Isn't it wonderful?\p"
	.string "I joined Team Aqua because of a shared\n"
	.string "love of the sea and everything in it.\p"
	.string "I wanna become a marine biologist\n"
	.string "when I grow up.$"
SlateportCity_OceanicMuseum_Text_AquaGirl2:
	.string "{AQUA_GIRL}: I just love visiting this\n"
	.string "museum. Oh, hey, {PLAYER}!\p"
	.string "What do you think of the museum?\n"
	.string "Isn't it wonderful?\p"
	.string "I joined Team Aqua because of a shared\n"
	.string "love of the sea and everything in it.\p"
	.string "I wanna become a marine biologist\n"
	.string "when I grow up.$"



SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy:: @ 820AEF8
	lock
	goto SlateportCity_OceanicMuseum_1F_EventScript_AquaBoyCommon
	end
SlateportCity_OceanicMuseum_1F_TriggerScript_AquaBoy::
	lock
	setvar THIS_EVENT, 13
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto SlateportCity_OceanicMuseum_1F_EventScript_AquaBoyCommon
	end

SlateportCity_OceanicMuseum_1F_EventScript_AquaBoyCommon: 
	applymovement THIS_EVENT, Common_Movement_FacePlayer
	waitmovement 0
	markasdialog
	goto_if_set   FLAG_SCENE_3, SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy_Repeat
	call_if_set   FLAG_SCENE_0, SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy_Update
	call_if_unset FLAG_SCENE_0, SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy_Meeting
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaBoy_Mission
	setvar VAR_SLATEPORT_MUSEUM_HEIST_STATE, 2
	setflag FLAG_SCENE_0
	setflag FLAG_SCENE_3
	release
	end

SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy_Meeting:
	selectpointer_clamp SlateportCity_OceanicMuseum_1F_TextArray_AquaBoy, VAR_AQUA_BOY_FRIENDSHIP
	message 0
	waitmessage 
	addvar VAR_AQUA_BOY_FRIENDSHIP, 1
	return
SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy_Update:
	message SlateportCity_OceanicMuseum_1F_Text_AquaBoy2
	waitmessage 
	return
SlateportCity_OceanicMuseum_1F_EventScript_AquaBoy_Repeat:
	msgbox SlateportCity_OceanicMuseum_1F_Text_AquaBoy_Repeat
	release
	end
.align 2
SlateportCity_OceanicMuseum_1F_TextArray_AquaBoy:
	.4byte SlateportCity_OceanicMuseum_1F_Text_AquaBoy0
	.4byte SlateportCity_OceanicMuseum_1F_Text_AquaBoy1
	.4byte 0
SlateportCity_OceanicMuseum_1F_Text_AquaBoy0:
	.string "Oh, you're that {PLAYER_boy} who helped us\n"
	.string "back in Rustboro. Didn't get a chance\l"
	.string "to introduce myself before.\p"
	.string "My name's {AQUA_BOY}.\p"
	.string "You're {PLAYER}, right?\n"
	.string "Sweet. See, I remembered!\p"
	.string "Hey, wanna help again? Listen up.\p$"
SlateportCity_OceanicMuseum_1F_Text_AquaBoy1:
	.string "{AQUA_BOY}: Hey! {PLAYER}!\n"
	.string "How's it going, {PLAYER_dude}?\p"
	.string "You managed to find us at just the\n"
	.string "right time again, didn't you?\p"
	.string "Hey, wanna help again? Listen up.\p$"
SlateportCity_OceanicMuseum_1F_Text_AquaBoy2:
	.string "{AQUA_BOY}: {PLAYER}, just in time.\n"
	.string "Listen up.\p$"
SlateportCity_OceanicMuseum_1F_Text_AquaBoy_Mission:
	.string "I just got a message from the boss.\n"
	.string "He's on his way, but he wants the job\l"
	.string "finished before he gets here.\p"
	.string "Turns out the Devon Goods are missing\n"
	.string "some documentation, which Capt. Stern\l"
	.string "should have on his person.\p"
	.string "The guy tailing Stern reported he came\n"
	.string "in here, so he should be here somewhere.\p"
	.string "{PLAYER}, check to see if he's upstairs.\p"
	.string "I'll be right behind you, after I pass\n"
	.string "the message to the rest of these guys.$"
SlateportCity_OceanicMuseum_1F_Text_AquaBoy_Repeat:
	.string "{AQUA_BOY}: I'll be up right behind you.\p"
	.string "I have to descretely pass the message\n"
	.string "to everyone else first.\p"
	.string "I can't just shout our intention to\n"
	.string "mug Stern. That's asking for trouble.$"
	

