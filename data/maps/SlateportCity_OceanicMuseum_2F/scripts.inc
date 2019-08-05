SlateportCity_OceanicMuseum_2F_MapScripts:: @ 820BAFF
	.byte 0

@ -----------------------------------------------------
@ Exhibits

SlateportCity_OceanicMuseum_2F_EventScript_20BD0A:: @ 820BD0A
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C4F9, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C4F9: @ 820C4F9
	.string "{CENTER}{TIPS}WATER QUALITY SAMPLE 1{END}\n"
	.string "{CENTER}The sea is all connected, but the\n"
	.string "{CENTER}water seems to differ by region.$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD13:: @ 820BD13
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C566, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C566: @ 820C566
	.string "{CENTER}{TIPS}WATER QUALITY SAMPLE 2{END}\n"
	.string "{CENTER}Does the saltiness of seawater\n"
	.string "{CENTER}differ by region, too?$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD1C:: @ 820BD1C
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C5C6, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C5C6: @ 820C5C6
	.string "{CENTER}In the sea, the weight of water itself\n"
	.string "{CENTER}exerts pressure. In shallow water, the\n"
	.string "{CENTER}pressure is not very heavy. However,\n"
	.string "{CENTER}in extremely deep water, the pressure\n"
	.string "{CENTER}can reach even tens of thousands of\l"
	.string "{CENTER}tons on a small area.”$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD25:: @ 820BD25
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C6C7, MSGBOX_DESCRIBE
	end
SlateportCity_OceanicMuseum_2F_Text_20C6C7: @ 820C6C7
	.string "“Model of Hoenn Region”\p"
	.string "It's a miniature diorama of the\n"
	.string "Hoenn region, like the sign says.\p"
	.string "If only they had a model of Alola\n"
	.string "here too…$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD2E:: @ 820BD2E
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C72F, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C72F: @ 820C72F
	.string "{CENTER}Near the bottom of the sea, water\n"
	.string "{CENTER}flows due to differences in such\l"
	.string "{CENTER}factors as temperature and salinity.$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD37:: @ 820BD37
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C7C1, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C7C1: @ 820C7C1
	.string "{CENTER}Toward the surface, seawater flows\n"
	.string "{CENTER}as currents driven by the winds.$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD40:: @ 820BD40
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C82F, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C82F: @ 820C82F
	.string "{CENTER}{TIPS}The Ferry S.S. Tidal{END}\p"
	.string "{CENTER}A scale replica of the ship under\n"
	.string "{CENTER}construction at Stern's Shipyard.$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD49:: @ 820BD49
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C88B, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C88B: @ 820C88B
	.string "{CENTER}{TIPS}SUBMARINE EXPLORER 1{END}\p"
	.string "{CENTER}A replica of the high-performance\n"
	.string "{CENTER}ocean floor exploration submarine.$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD52:: @ 820BD52
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C8E8, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C8E8: @ 820C8E8
	.string "{CENTER}{TIPS}Submersible Pod{END}\p"
	.string "{CENTER}A replica of a compact, unmanned\n"
	.string "{CENTER}pod for seafloor exploration.$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD5B:: @ 820BD5B
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C93A, MSGBOX_SIGN
	end
SlateportCity_OceanicMuseum_2F_Text_20C93A: @ 820C93A
	.string "{CENTER}{TIPS}S.S. Anne{END}\p"
	.string "{CENTER}A replica of the luxury liner that\n"
	.string "{CENTER}circles the globe.$"

@ -----------------------------------------------------
@ People

SlateportCity_OceanicMuseum_2F_EventScript_20BD64:: @ 820BD64
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C43F, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_2F_Text_20C43F: @ 820C43F
	.string "I saw a model of a ship here.\p"
	.string "It reminded me of the Abandoned Ship\n"
	.string "near Dewford Town…$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD6D:: @ 820BD6D
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C495, MSGBOX_NPC
	end
SlateportCity_OceanicMuseum_2F_Text_20C495: @ 820C495
	.string "Don't you dare run around inside\n"
	.string "the museum!$"


SlateportCity_OceanicMuseum_2F_EventScript_20BD76:: @ 820BD76
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_20C4C2, MSGBOX_DIALOG
	closemessage
	faceoriginaldir
	release
	end
SlateportCity_OceanicMuseum_2F_Text_20C4C2: @ 820C4C2
	.string "Wow, the submarine's awesome!\n"
	.string "I want to go for a ride!$"

@ -----------------------------------------------------
@ Cutscene: Stern Mugging

#define LID_STERN 1
#define LID_LOGAN 8
#define LID_AQUA_BOY 3
#define LID_AQUA_2 4
#define LID_DOCS 9
#define LID_ARCHIE 2

SlateportCity_OceanicMuseum_2F_TriggerScript_SternMugging::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_Y, 4
	@ "Technobable!"
	markasdialog -2
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging1
	playse SE_SELECT
	@ "Sweet!"
	markasdialog 18
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging2
	closemessage
	@ Player steps forward, others notice
	selectpointer SlateportCity_OceanicMuseum_2F_MovementTable_SternMugging3_Player, VAR_INTERACT_Y
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	applymovement LID_STERN, Common_Movement_WalkInPlaceLeft
	applymovement LID_LOGAN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	@ "Oh, hello?"
	markasdialog -4
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging4
	playse SE_SELECT
	@ "Hi Player!"
	markasdialog 16
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging5
	playse SE_SELECT
	@ "This is Stern!"
	applymovement LID_LOGAN, SlateportCity_OceanicMuseum_2F_Movement_SternMugging6_Logan
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging6
	waitmovement 0
	@ Player steps forward
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	@ "Nice to, uh...?!"
	markasdialog -6
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging7
	closemessage
	@ The backup arrives
	playbgm MUS_AQA_0, 1
	setobjectxyperm LID_AQUA_BOY, 6, 1
	addobject LID_AQUA_BOY
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging7_Aqua1
	waitmovement 0
	setobjectxyperm LID_AQUA_2, 6, 1
	addobject LID_AQUA_2
	applymovement LID_AQUA_2, Common_Movement_WalkDown1
	waitmovement 0
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging7_Aqua2
	applymovement LID_AQUA_2, SlateportCity_OceanicMuseum_2F_Movement_SternMugging7_Aqua3
	waitmovement 0
	@ "Who are these guys?!"
	applymovement LID_LOGAN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LID_LOGAN, Common_Movement_ExclamationMark
	playse SE_PIN
	markasdialog 14
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging8
	waitmovement 0
	playse SE_SELECT
	@ "Hand it over"
	markasdialog 6
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging9
	playse SE_SELECT
	@ "You're not with these guys, right?"
	applymovement LID_LOGAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	markasdialog 14
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging10
	closemessage
	@ Player moves forward threateningly
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement LID_STERN, Common_Movement_BackOffRight1
	waitmovement 0
	applymovement LID_LOGAN, SlateportCity_OceanicMuseum_2F_Movement_SternMugging11_LoganSlide
	waitmovement 0
	@
	markasdialog 14
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging11
	@ FIGHT
	setflag FLAG_SCENE_FORCE_AQUA_THEME
	trainerbattle_no_intro TRAINER_LOGAN_STERNCUTSCENE, SlateportCity_OceanicMuseum_2F_Text_SternMugging_LoganLose
	@
	applymovement LID_LOGAN, Common_Movement_WalkInPlaceUp
	waitmovement 0
	markasdialog 14
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging12
	@ Logan runs off
	closemessage
	applymovement LID_LOGAN, SlateportCity_OceanicMuseum_2F_Movement_SternMugging13_Logan
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging13_Aqua
	waitmovement LID_LOGAN
	setobjectxy LID_LOGAN, 30, 0
	moveobjectoffscreen LID_LOGAN
	@ Aqua closes in
	markasdialog -8
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging14_AquaBoy
	applymovement LID_AQUA_2, SlateportCity_OceanicMuseum_2F_Movement_SternMugging14_Aqua2
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging13
	waitmovement 0
	@ Bailey finds papers
	closemessage
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LID_AQUA_BOY, Common_Movement_ExclamationMarkAndWait
	playse SE_PIN
	waitmovement 0
	@ 
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging15_AquaBoy
	applymovement LID_DOCS, SlateportCity_OceanicMuseum_2F_Movement_SternMugging15_Docs
	markasdialog -6
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging15
	waitmovement LID_AQUA_BOY
	@ Back off, enter Archie
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	setobjectxyperm LID_ARCHIE, 6, 2
	addobject LID_ARCHIE
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging16_AquaBoy
	applymovement LID_AQUA_2, SlateportCity_OceanicMuseum_2F_Movement_SternMugging16_Aqua2
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_SternMugging16_Player
	waitmovement 0
	@ "Excellent"
	markasdialog 6
	message SlateportCity_OceanicMuseum_2F_Text_SternMugging17
	waitmessage
	@ Archie steps forward to look at player
	applymovement LID_AQUA_BOY, SlateportCity_OceanicMuseum_2F_Movement_SternMugging18_AquaBoy
	applymovement LID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_SternMugging18_Archie
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging18
	playse SE_SELECT
	@ "He wants to join"
	markasdialog -6
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging19
	playse SE_SELECT
	@ Archie speech
	markasdialog 6
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging20
	playse SE_SELECT
	@ Bandanna get!
	message SlateportCity_OceanicMuseum_2F_Text_SternMugging21, MSGTYPE_DESCRIBE
	waitmessage
	playfanfare MUS_ME_BACHI
	message SlateportCity_OceanicMuseum_2F_Text_SternMugging22, MSGTYPE_DESCRIBE
	waitfanfare
	@
	applymovement LID_ARCHIE, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging23
	@
	fadescreen 5 @ FADE_TO_BLACK_NO_WINDOW
	playse SE_KAIDAN
	@ removeobject LID_ARCHIE
	@ removeobject LID_AQUA_BOY
	@ removeobject LID_AQUA_2
	@ removeobject LID_LOGAN
	@ removeobject LID_STERN
	@ removeobject LID_DOCS
	setvar VAR_0x8000, 1
	callnative SetPlayerOutfit
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternMugging24, MSGBOX_CDESCRIBE
	closemessage
	@ clean up
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	setflag FLAG_HIDE_ROUTE_110_TEAM_AQUA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_AQUA_GRUNTS
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_AQUA
	setflag FLAG_HIDE_SLATEPORT_CITY_OCEANIC_MUSEUM_2F_CAPTAIN_STERN
	setflag FLAG_DELIVERED_DEVON_GOODS
	setvar VAR_SLATEPORT_MUSEUM_HEIST_STATE, 3
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	call Common_EventScript_ClearSceneFlags
	@ reload map
	warpcustom MAP_SLATEPORT_CITY_OCEANIC_MUSEUM_2F, 255, VAR_INTERACT_X, VAR_INTERACT_Y
	waitstate
	releaseall
	end

SlateportCity_OceanicMuseum_2F_Text_SternMugging1:
	.string "Capt. Stern: Yes, we're really close to\n"
	.string "a major breakthrough with this deep\l"
	.string "sea technology.\p"
	.string "We're mainly just waiting on a\n"
	.string "delivery of some important parts.$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging2:
	.string "{RIVAL_HERO}: That's really neat!\p"
	.string "It'd be really nifty to be on that\n"
	.string "submarine when it goes that deep!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging4:
	.string "Capt. Stern: Oh, hello, young {PLAYER_man}.\n"
	.string "Can I… help you?$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging5:
	.string "{RIVAL_HERO}: Hey, {PLAYER}!\n"
	.string "Fancy meeting you here!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging6:
	.string "Mr. Stern, this is {PLAYER}!\n"
	.string "{PLAYER_They} helped me out once back in\l"
	.string "Petalburg!\p"
	.string "{PLAYER}, this is Captain Stern!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging7:
	.string "Capt. Stern: Ah, nice to, uh…\p"
	.string "Wh-What's with the look?$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging8:
	.string "{RIVAL_HERO}: {P_PLAYER}?!\n"
	.string "W-Who are these guys?!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging9:
	.string "{AQUA_BOY}: Alright, Stern.\n"
	.string "This is a stick up.\p"
	.string "Just hand over those documents\n"
	.string "and no one will get hurt.$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging10:
	.string "{RIVAL_HERO}: You're not WITH these\n"
	.string "guys, are you, {PLAYER}?!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging11:
	.string "{RIVAL_HERO}: What's wrong with you,\n"
	.string "{PLAYER}?! I thought you were one of\l"
	.string "the good guys!\p"
	.string "I can't let you do this!\n"
	.string "You'll have to get through me first!$"
@ FIGHT
SlateportCity_OceanicMuseum_2F_Text_SternMugging_LoganLose:
	.string "Oh, crud, you're really tough…$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging12:
	.string "{RIVAL_HERO}: Seedot? Are you alright?!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging13:
	.string "Capt. Stern: Ah, fellas…\p"
	.string "Perhaps we can, um…\n"
	.string "negotiate something?$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging15:
	.string "{AQUA_BOY}: Back off, guys.\n"
	.string "I got the docs right here.\p"
	.string "We can head out.$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging17:
	.string "Excellent! Excellent work!\n"
	.string "Just what I wanted.\p$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging18:
	.string "Ah, excuse me, who are you?$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging19:
	.string "{AQUA_BOY}: This is {PLAYER}, sir.\n"
	.string "{PLAYER_They} just helped us get these papers.\p"
	.string "{PLAYER_They}… wants to join the Team, sir.$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging20:
	.string "Do you, now?\n"
	.string "Do you love the sea as much as we?\p"
	.string "For we are {REF}Team Aqua{END},\n"
	.string "and we love the sea!\p"
	.string "And I am Team Aqua's leader,\n"
	.string "{REF}Archie{END}!\p"
	.string "Pokémon, people…\n"
	.string "All life depends on the sea.\p"
	.string "So, Team Aqua is dedicated to\n"
	.string "the expansion of the sea.\p"
	.string "What we are doing is a magnificent\n"
	.string "undertaking, don't you agree?\p"
	.string "… … … … … …\n"
	.string "Ah, it's fine… Perhaps you are still\l"
	.string "too young to understand our noble\l"
	.string "objective to its fullest.\p"
	.string "But that does not mean you have not\n"
	.string "proven yourself today.\p"
	.string "I apologize. This will have to do for\n"
	.string "the interim.$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging21:
	.string "Archie takes the armband from his arm\n"
	.string "and hands it to you.\p$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging22:
	.string "Recieved the Team Aqua Bandana!$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging23:
	.string "Archie: Time to leave, boys.$"
SlateportCity_OceanicMuseum_2F_Text_SternMugging24:
	.string "{PLAYER} donned the headband.$"


.align 2
SlateportCity_OceanicMuseum_2F_MovementTable_SternMugging3_Player:
	.4byte SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player1
	.4byte SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player2
	.4byte SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player3
	.4byte SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player4
	.4byte SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player5
	.4byte 0

SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player1:
	walk_down
	walk_down
	walk_right
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player2:
	walk_down
	walk_right
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player3:
	walk_right
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player4:
	walk_up
	walk_right
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging3_Player5:
	walk_up
	walk_up
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging6_Logan:
	walk_left
	walk_left
	walk_in_place_fast_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging7_Aqua1: @ 820BCE4
	walk_down
	walk_right
	walk_in_place_fastest_down
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging7_Aqua2:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging7_Aqua3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging11_LoganSlide:
	walk_fast_right
	face_down
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	face_left
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	walk_in_place_fastest_left
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging13_Logan:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	set_invisible
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging13_Aqua:
	delay_8
	delay_8
	delay_8
	delay_8
	face_up
	lock_facing_direction
	slide_down
	unlock_facing_direction
	walk_in_place_fast_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging14_AquaBoy:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_fast_down
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging14_Aqua2:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging15_AquaBoy:
	walk_right
	walk_in_place_up
	delay_16
	walk_in_place_down
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging15_Docs:
	delay_16
	delay_16
	delay_8
	set_invisible
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging16_AquaBoy:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	emote_exclamation_mark
	delay_16
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging16_Aqua2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	emote_exclamation_mark
	delay_16
	delay_8
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging16_Player:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	delay_16
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SternMugging18_AquaBoy:
	face_left
	lock_facing_direction
	walk_right
	unlock_facing_direction
	step_end
SlateportCity_OceanicMuseum_2F_Movement_SternMugging18_Archie:
	delay_16
	walk_down
	step_end

#undef LID_STERN
#undef LID_LOGAN
#undef LID_AQUA_BOY
#undef LID_AQUA_2
#undef LID_DOCS
#undef LID_ARCHIE

