MossdeepCity_MapScripts:: @ 81E4A96
	map_script MAP_SCRIPT_ON_LOAD, MossdeepCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_MapTable
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_FrameTable
	.byte 0

MossdeepCity_OnTransition: @ 81E4A9C
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetWeatherAlternating
	compare VAR_MOSSDEEP_STATE, 0
	call_if_eq MossdeepCity_EventScript_UpdateInvasionFlags
	end

MossdeepCity_EventScript_MarkCityVisited:: @ 81E4B38
	setflag FLAG_VISITED_MOSSDEEP_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_UpdateInvasionFlags:
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_1F_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_CITY_SPACE_CENTER_2F_STEVEN
	clearflag FLAG_HIDE_MOSSDEEP_CITY_TEAM_MAGMA
	clearflag FLAG_HIDE_MOSSDEEP_SPACE_CENTER_TEAM_MEMBERS
	return

MossdeepCity_OnLoad:
	compare VAR_MOSSDEEP_STATE, 11
	call_if_ge MossdeepCity_OnLoad_AddTeamPile
	end

MossdeepCity_OnLoad_AddTeamPile:
	setmetatile 31, 26, 0x380, FALSE
	return


MossdeepCity_MapTable:
	@ map_script_2 VAR_LAST_WARP_ID, 8, MossdeepCity_MapTable_StepMusicOn
	.2byte 0

MossdeepCity_FrameTable:
	map_script_2 VAR_MOSSDEEP_STATE, 11, MossdeepCity_FrameTable_ClearFlags
	.2byte 0

MossdeepCity_FrameTable_ClearFlags:
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_MOSSDEEP_STATE, 12
	end

@ -----------------------------------------------------
@ Sign

MossdeepCity_EventScript_1E4B1D:: @ 81E4B1D
	msgbox MossdeepCity_Text_1E53A9, MSGBOX_SIGN
	end
MossdeepCity_Text_1E53A9: @ 81E53A9
	.string "{GYM}Mossdeep City Pokémon Gym{END}\n"
	.string "{GYM}Leaders:{END} Liza & Tate\p"
	.string "“The mystic combination!”$"


MossdeepCity_EventScript_1E4B26:: @ 81E4B26
	msgbox MossdeepCity_Text_1E53F2, MSGBOX_SIGN
	end
MossdeepCity_Text_1E53F2: @ 81E53F2
	.string "{PLACE}Mossdeep City{END}\n"
	.string "“Our slogan: Cherish Pokémon!”$"


MossdeepCity_EventScript_1E4B2F:: @ 81E4B2F
	msgbox MossdeepCity_Text_1E541F, MSGBOX_SIGN
	end
MossdeepCity_Text_1E541F: @ 81E541F
	.string "{PLACE}Mossdeep Space Center{END}\n"
	.string "“The closest place to space.”$"


MossdeepCity_EventScript_TeamPile:: @ 81E4B2F
	compare VAR_MOSSDEEP_STATE, 12
	goto_if_lt Common_EventScript_ReleaseEnd
	@ This script will not auto-play the select sound
	playse SE_SELECT
	msgbox MossdeepCity_Text_TeamPile, MSGBOX_DESCRIBE
	end
MossdeepCity_Text_TeamPile: @ 81E541F
	.string "The discarded colors of Team Aqua\n"
	.string "and Team Magma.$"

@ -----------------------------------------------------
@ People

MossdeepCity_DynamicPunchGuy::
	markasdialog
	goto MossdeepCity_EventScript_2C81EE
	end

MossdeepCity_EventScript_1E4AB2:: @ 81E4AB2
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM58, MossdeepCity_EventScript_1E4AC7
	msgbox MossdeepCity_Text_1E4E90, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4E90: @ 81E4E90
	.string "The island's {PLACE}Space Center{END} has been\n"
	.string "launching huge rockets.\p"
	.string "There's been some kind of an uproar\n"
	.string "over a letter they received recently.$"
MossdeepCity_EventScript_1E4AC7:: @ 81E4AC7
	msgbox MossdeepCity_Text_1E4F15, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4F15: @ 81E4F15
	.string "The island's {PLACE}Space Center{END} has been\n"
	.string "launching huge rockets.$"


MossdeepCity_EventScript_1E4AD1:: @ 81E4AD1
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM58, MossdeepCity_EventScript_1E4AE6
	msgbox MossdeepCity_Text_1E4F50, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4F50: @ 81E4F50
	.string "I heard from a sailor buddy that\n"
	.string "Team Aqua set up shop in Lilycove.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But Mossdeep here's been targeted\n"
	.string "by that Team Magma.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the {PLACE}Space Center{END}.$"
MossdeepCity_EventScript_1E4AE6:: @ 81E4AE6
	msgbox MossdeepCity_Text_1E5051, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E5051: @ 81E5051
	.string "I'm a sailor, so the sea's obviously\n"
	.string "more important to me.\p"
	.string "But you know? When I get back on land\n"
	.string "after a long voyage, I do feel relief!$"


MossdeepCity_EventScript_1E4AF0:: @ 81E4AF0
	msgbox MossdeepCity_Text_1E4E22, MSGBOX_NPC
	end
MossdeepCity_Text_1E4E22: @ 81E4E22
	.string "Around Mossdeep, you can see wild\n"
	.string "Wailmer.\p"
	.string "It's called, uh…\n"
	.string "What was it now…\p"
	.string "Wai, Wai, Wai…\p"
	.string "Wailmer watching!$"


MossdeepCity_EventScript_1E4AF9:: @ 81E4AF9
	msgbox MossdeepCity_Text_1E5135, MSGBOX_NPC
	end
MossdeepCity_Text_1E5135: @ 81E5135
	.string "All life needs the sea to live, even\n"
	.string "though it makes its home on the land.\p"
	.string "Life, having run its course, becomes\n"
	.string "soil and returns to the land.\p"
	.string "And the sea is always connected to\n"
	.string "the land.\p"
	.string "Yes, like the very shoreline here.$"


MossdeepCity_EventScript_1E4B02:: @ 81E4B02
	msgbox MossdeepCity_Text_1E50D9, MSGBOX_NPC
	end
MossdeepCity_Text_1E50D9: @ 81E50D9
	.string "Wouldn't it be nice?\p"
	.string "If the whole world was covered in\n"
	.string "plants and flowers like this island?$"


MossdeepCity_EventScript_1E4B0B:: @ 81E4B0B
	msgbox MossdeepCity_Text_1E529D, MSGBOX_NPC
	end
MossdeepCity_Text_1E529D: @ 81E529D
	.string "This rock has a special meaning to\n"
	.string "the people at the {PLACE}Space Center{END}.\p"
	.string "They put it here as their wish for\n"
	.string "their rockets to fly safely.\p"
	.string "When you make a wish, what do you use?\n"
	.string "Do you wish upon a star?\p"
	.string "I use a wish tag to make it happen.\n"
	.string "That's what I do.$"


MossdeepCity_EventScript_1E4B14:: @ 81E4B14
	msgbox MossdeepCity_Text_1E5396, MSGBOX_DESCRIBE
	end
MossdeepCity_Text_1E5396: @ 81E5396
	.string "It's a white rock.$"


MossdeepCity_EventScript_1E4C10:: @ 81E4C10
	lock
	faceplayer
	msgbox MossdeepCity_Text_1E5213, MSGBOX_DIALOG
	faceoriginaldir
	release
	end
MossdeepCity_Text_1E5213: @ 81E5213
	.string "A voyage on a ship is fine.\p"
	.string "But crossing the sea with Pokémon\n"
	.string "using SURF…\p"
	.string "Now that's an exhilarating trip!\n"
	.string "Wouldn't you agree, youngster?$"


MossdeepCity_EventScript_1E4C26:: @ 81E4C26
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_1E4C68
	msgbox MossdeepCity_Text_1E4CED, MSGBOX_YESNO
	compare VAR_RESULT, 0
	goto_if_eq MossdeepCity_EventScript_1E4C72
	msgbox MossdeepCity_Text_1E4D5B, MSGBOX_DEFAULT
	giveitem_std ITEM_KINGS_ROCK
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end
MossdeepCity_Text_1E4CED: @ 81E4CED
	.string "I got this from Steven, but I don't\n"
	.string "know what it's good for.\p"
	.string "I think it's called King's Rock.\n"
	.string "Do you want it?$"
MossdeepCity_Text_1E4D5B: @ 81E4D5B
	.string "Why would you want it?\n"
	.string "You're weird.\p"
	.string "You can keep it, but keep it a secret\n"
	.string "from Steven.$"
MossdeepCity_EventScript_1E4C68:: @ 81E4C68
	msgbox MossdeepCity_Text_1E4DB3, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4DB3: @ 81E4DB3
	.string "Steven's house is right over there!$"
MossdeepCity_EventScript_1E4C72:: @ 81E4C72
	msgbox MossdeepCity_Text_1E4DD7, MSGBOX_DEFAULT
	release
	end
MossdeepCity_Text_1E4DD7: @ 81E4DD7
	.string "Yeah, you think so, too! What are you\n"
	.string "supposed to do with some weird rock?$"


MossdeepCity_EventScript_1E4C7C:: @ 81E4C7C
	msgbox MossdeepCity_Text_1E5581, MSGBOX_NPC
	end
MossdeepCity_Text_1E5581: @ 81E5581
	.string "Ahh… It feels great letting the waves\n"
	.string "wash over my feet…\p"
	.string "Speaking of the waves, you know that\n"
	.string "island city Sootopolis?\p"
	.string "I think the Gym there had a new\n"
	.string "Leader come in.\p"
	.string "People tell me the new Leader once\n"
	.string "mentored Wallace.$"


MossdeepCity_EventScript_TransportEverGrande::
	lock
	faceplayer
	markasdialog
	askforboat MossdeepCity_Text_TransportEverGrande_Ask, MossdeepCity_Text_TransportEverGrande_Decline, MossdeepCity_Text_TransportEverGrande_NoMoney, MossdeepCity_Text_TransportEverGrande_Embark
	warpcustom MAP_EVER_GRANDE_CITY, 255, 45, 76
	waitstate
	end
MossdeepCity_Text_TransportEverGrande_Ask:
	.string "Hello, old {PLAYER_boy}, I will be\n"
	.string "travelling to {PLACE}Ever Grande{END} shortly.\p"
	.string "For ¥100, I'll give you a ride there.$"
MossdeepCity_Text_TransportEverGrande_Decline:
	.string "Your loss.$"
MossdeepCity_Text_TransportEverGrande_NoMoney:
	.string "You don't have the money.$"
MossdeepCity_Text_TransportEverGrande_Embark:
	.string "Thanks! Let us embark!$"


MossdeepCity_EventScript_TransportSootopolis::
	lock
	faceplayer
	markasdialog
	askforboat MossdeepCity_Text_TransportSootopolis_Ask, MossdeepCity_Text_TransportSootopolis_Decline, MossdeepCity_Text_TransportSootopolis_NoMoney, MossdeepCity_Text_TransportSootopolis_Embark
	warpcustom MAP_ROUTE126, 255, 25, 50
	waitstate
	end
MossdeepCity_Text_TransportSootopolis_Ask:
	.string "Ahoy! I'm heading off near {PLACE}Sootopolis{END}\n"
	.string "to do some fishing. I can drop ya off\l"
	.string "for ¥100. Need me some bait, after all.$"
MossdeepCity_Text_TransportSootopolis_Decline:
	.string "Ah, well.$"
MossdeepCity_Text_TransportSootopolis_NoMoney:
	.string "Um, I need the fee first.\n"
	.string "No fishing without it.$"
MossdeepCity_Text_TransportSootopolis_Embark:
	.string "Mighty thank ya! Onward!$"


MossdeepCity_EventScript_TransportPacifidlog::
	lock
	faceplayer
	markasdialog
	askforboat MossdeepCity_Text_TransportPacifidlog_Ask, MossdeepCity_Text_TransportPacifidlog_Decline, MossdeepCity_Text_TransportPacifidlog_NoMoney, MossdeepCity_Text_TransportPacifidlog_Embark
	warpcustom MAP_PACIFIDLOG_TOWN, 255, 17, 14
	waitstate
	end
MossdeepCity_Text_TransportPacifidlog_Ask:
	.string "Oh, hello! I'm going to {PLACE}Pacifidlog{END}\n"
	.string "soon to visit some family.\p"
	.string "If you're heading the same way,\n"
	.string "I think ¥100 will cover the fuel.$"
MossdeepCity_Text_TransportPacifidlog_Decline:
	.string "Oh, alright.$"
MossdeepCity_Text_TransportPacifidlog_NoMoney:
	.string "Ah ah, no stiffing me, young {PLAYER_man}.$"
MossdeepCity_Text_TransportPacifidlog_Embark:
	.string "Yay! Let's head out now!$"



@ -----------------------------------------------------
@ State: Magma Invasion

MossdeepCity_EventScript_BlockingAqua::
	msgbox MossdeepCity_Text_BlockingAqua, MSGBOX_NPC
	end
MossdeepCity_Text_BlockingAqua:
	.string "Oh, hey! {AQUA_BOY} was looking for you!\p"
	.string "Magma decided to take over the Space\n"
	.string "Center for some reason.\l"
	.string "You should go find him to help!\p"
	.string "Me? I'm the undersea radio relay.\p"
	.string "The boss and them are in the sub\n"
	.string "looking for a cave or something?\p"
	.string "This is the only place on the island\n"
	.string "where I could get reception.$"


MossdeepCity_EventScript_FightingAqua1::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FightingAqua1, MSGBOX_DIALOG
	faceoriginaldir
	end
MossdeepCity_Text_FightingAqua1:
	.string "{AQUA_BOY} is inside! I'm holding off\n"
	.string "this one! Get in and help!$"


MossdeepCity_EventScript_FightingAqua2::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FightingAqua2, MSGBOX_DIALOG
	faceoriginaldir
	end
MossdeepCity_Text_FightingAqua2:
	.string "Magma struck at the perfect time,\n"
	.string "didn't they?\p"
	.string "Right when half our men are underwater\n"
	.string "searching for a cave!$"


MossdeepCity_EventScript_FightingMagma2::
	lock
	faceplayer
	msgbox MossdeepCity_Text_FightingMagma2, MSGBOX_DIALOG
	faceoriginaldir
	end
MossdeepCity_Text_FightingMagma2:
	.string "Why must you people meddle in our\n"
	.string "affairs constantly?!$"


@ -----------------------------------------------------
@ Cutscene: The Rains Begin

#define LID_RANDO_LADY 3
#define LID_RANDO_DUDE 1
#define LID_AQUA_BOY 18
#define LID_AQUA_GIRL 19
#define LID_MAGMA_GUY 20
#define LID_LOGAN 17

MossdeepCity_EventScript_RainsBegin_OnLoad1::
	return

MossdeepCity_EventScript_RainsBegin::
	lockall
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	subvar VAR_INTERACT_Y, 10
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_AQUA_FRIEND_M
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_AQUA_FRIEND_F
	setvar VAR_OBJ_GFX_ID_2, EVENT_OBJ_GFX_MAGMA_MEMBER_M
	@ "PLAYER!"
	markasdialog 29 @off the edge of the screen
	msgbox MossdeepCity_Text_RainsBegin1
	closemessage
	@ Player looks for voice
	applymovement LID_RANDO_LADY, MossdeepCity_Movement_RainsBegin2_LadyMeander
	applymovement LID_RANDO_DUDE, MossdeepCity_Movement_RainsBegin2_DudeMeander
	selectpointer MossdeepCity_MovementTable_RainsBegin2_PlayerSearch, VAR_INTERACT_Y
	applymovement EVENT_OBJ_ID_PLAYER, 0
	waitmovement 0
	@ Bailey runs up
	setobjectxyperm LID_AQUA_BOY, 34, 19
	addobject LID_AQUA_BOY
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin3
	waitmovement 0
	@
	markasdialog 8
	msgbox MossdeepCity_Text_RainsBegin4
	closemessage
	@ The rain begins
	setweather WEATHER_ALTERNATING
	doweather
	delay 20
	setflag FLAG_SYS_WEATHER_CTRL
	@ people react
	playse SE_PIN
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin5_AquaReact
	applymovement LID_RANDO_LADY, MossdeepCity_Movement_RainsBegin5_LadyReact
	applymovement LID_RANDO_DUDE, MossdeepCity_Movement_RainsBegin5_DudeReact
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin5_PlayerReact
	waitmovement LID_AQUA_BOY
	msgbox MossdeepCity_Text_RainsBegin5
	waitmovement EVENT_OBJ_ID_PLAYER
	closemessage
	@ runs off, player follows
	fadenewbgm MUS_OOAME
	special SpawnCameraObject
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin6_AquaRun
	waitmovement 0
	setobjectxy LID_AQUA_BOY, 31, 25
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin6_PlayerRun
	applymovement EVENT_OBJ_ID_CAMERA, MossdeepCity_Movement_RainsBegin6_CameraRun
	waitmovement EVENT_OBJ_ID_PLAYER
	waitmovement EVENT_OBJ_ID_CAMERA
	@
	markasdialog 10
	msgbox MossdeepCity_Text_RainsBegin7
	closemessage
	delay 16
	@
	markasdialog 26
	msgbox MossdeepCity_Text_RainsBegin8
	closemessage
	@ Magma dude runs up
	setobjectxyperm LID_MAGMA_GUY, 37, 25
	addobject LID_MAGMA_GUY
	applymovement LID_MAGMA_GUY, MossdeepCity_Movement_RainsBegin8
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceRight
	waitmovement 0
	@
	markasdialog -3
	msgbox MossdeepCity_Text_RainsBegin9
	closemessage
	@ roar
	waitse
	playmoncry SPECIES_GROUDON, CRY_MODE_SLOW
	delay 16
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LID_MAGMA_GUY, Common_Movement_WalkInPlaceDown
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceDown
	waitmovement 0
	waitmoncry
	delay 30
	@ Jessica arrives
	setobjectxyperm LID_AQUA_GIRL, 28, 33
	addobject LID_AQUA_GIRL
	playse SE_DANSA
	applymovement LID_AQUA_GIRL, MossdeepCity_Movement_RainsBegin10
	waitmovement 0
	@
	markasdialog -5
	msgbox MossdeepCity_Text_RainsBegin11
	playse SE_SELECT
	@
	markasdialog 10
	message MossdeepCity_Text_RainsBegin12
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin12
	waitmovement 0
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	waitmessage
	waitbuttonpress
	playse SE_SELECT
	@
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin13
	markasdialog -5
	msgbox MossdeepCity_Text_RainsBegin13
	playse SE_SELECT
	waitmovement 0
	@
	markasdialog 10
	msgbox MossdeepCity_Text_RainsBegin14
	playse SE_SELECT
	@
	markasdialog -5
	msgbox MossdeepCity_Text_RainsBegin15
	closemessage
	@ roar
	waitse
	playmoncry SPECIES_KYOGRE, CRY_MODE_SLOW
	delay 14
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceDown
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	waitmoncry
	delay 30
	@ Logan arrives
	setobjectxyperm LID_LOGAN, 25, 33
	addobject LID_LOGAN
	playse SE_DANSA
	applymovement LID_LOGAN, MossdeepCity_Movement_RainsBegin16
	waitmovement 0
	@ Logan chews them out
	markasdialog 10
	message MossdeepCity_Text_RainsBegin17
	delay 8
	applymovement LID_AQUA_GIRL, Common_Movement_FaceLeft
	delay 6
	applymovement LID_AQUA_BOY, Common_Movement_FaceLeft
	delay 10
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_FaceLeft
	delay 4
	applymovement LID_MAGMA_GUY, Common_Movement_FaceLeft
	waitmessage
	waitbuttonpress
	closemessage
	@ Logan runs off
	applymovement LID_AQUA_GIRL, MossdeepCity_Movement_RainsBegin18_AquaGirl
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin18_AquaBoy
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin18_Player
	applymovement LID_MAGMA_GUY, MossdeepCity_Movement_RainsBegin18_MagmaGuy
	applymovement LID_LOGAN, MossdeepCity_Movement_RainsBegin18_Logan
	waitmovement LID_LOGAN
	removeobject LID_LOGAN
	setobjectxyperm LID_LOGAN, 80, 0
	waitmovement LID_AQUA_BOY
	@ Bailey is contemplative, takes off his aqua garb
	applymovement LID_AQUA_GIRL, MossdeepCity_Movement_RainsBegin19_AquaGirl
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin19_Player
	applymovement LID_MAGMA_GUY, MossdeepCity_Movement_RainsBegin19_MagmaGuy
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin19_AquaBoy
	waitmovement LID_AQUA_BOY
	@
	setvar VAR_0x8000, 31
	setvar VAR_0x8001, 26
	applymovement LID_AQUA_BOY, Common_Movement_WalkInPlaceLeft
	waitmovement LID_AQUA_BOY
	delay 16
	setobjectxyperm LID_AQUA_BOY, 31, 25
	setvar VAR_OBJ_GFX_ID_0, EVENT_OBJ_GFX_FORMER_AQUA_FRIEND_M
	removeobject LID_AQUA_BOY
	setmetatile VAR_0x8000, VAR_0x8001, 0x370, FALSE
	special DrawWholeMapView
	addobject LID_AQUA_BOY
	delay 8
	waitmovement LID_MAGMA_GUY
	@ Bailey leaves
	markasdialog 10
	msgbox MossdeepCity_Text_RainsBegin21
	closemessage
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin21_Player
	applymovement LID_AQUA_BOY, MossdeepCity_Movement_RainsBegin21_AquaBoy
	waitmovement LID_AQUA_BOY
	applymovement LID_AQUA_GIRL, MossdeepCity_Movement_RainsBegin21_AquaGirl
	waitmovement LID_AQUA_GIRL
	@
	markasdialog -5
	msgbox MossdeepCity_Text_RainsBegin22
	closemessage
	@ takes off aqua garb
	applymovement LID_AQUA_GIRL, Common_Movement_WalkInPlaceRight
	waitmovement LID_AQUA_GIRL
	delay 24
	setobjectxyperm LID_AQUA_GIRL, 31, 25
	setvar VAR_OBJ_GFX_ID_1, EVENT_OBJ_GFX_FORMER_AQUA_FRIEND_F
	removeobject LID_AQUA_GIRL
	setmetatile VAR_0x8000, VAR_0x8001, 0x378, FALSE
	special DrawWholeMapView
	addobject LID_AQUA_GIRL
	delay 8
	@
	applymovement LID_AQUA_BOY, Common_Movement_WalkUp1
	applymovement LID_AQUA_GIRL, MossdeepCity_Movement_RainsBegin22_AquaGirl
	applymovement LID_MAGMA_GUY, MossdeepCity_Movement_RainsBegin23
	delay 16
	markasdialog -6
	message MossdeepCity_Text_RainsBegin23
	waitmovement LID_MAGMA_GUY
	waitmessage
	@ takes off magma garb
	applymovement LID_MAGMA_GUY, Common_Movement_WalkInPlaceLeft
	waitmovement LID_MAGMA_GUY
	delay 12
	setobjectxyperm LID_MAGMA_GUY, 31, 25
	setvar VAR_OBJ_GFX_ID_2, EVENT_OBJ_GFX_FORMER_MAGMA_M
	removeobject LID_MAGMA_GUY
	setmetatile VAR_0x8000, VAR_0x8001, 0x380, FALSE
	special DrawWholeMapView
	addobject LID_MAGMA_GUY
	delay 8
	waitbuttonpress
	playse SE_SELECT
	applymovement LID_MAGMA_GUY, MossdeepCity_Movement_RainsBegin24
	markasdialog -6
	msgbox MossdeepCity_Text_RainsBegin24
	closemessage
	waitmovement 0
	@
	removeobject LID_MAGMA_GUY
	removeobject LID_AQUA_GIRL
	removeobject LID_AQUA_BOY
	setobjectxyperm LID_MAGMA_GUY, 80, 0
	setobjectxyperm LID_AQUA_GIRL, 80, 0
	setobjectxyperm LID_AQUA_BOY, 80, 0
	@
	delay 20
	applymovement EVENT_OBJ_ID_CAMERA, MossdeepCity_Movement_RainsBegin26
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, MossdeepCity_Movement_RainsBegin25
	waitmovement 0
	delay 30
	special RemoveCameraObject
	@ Fade out, change clothes
	fadescreen 5 @ FADE_TO_BLACK_NO_WINDOW
	setvar VAR_0x8000, 3
	callnative SetPlayerOutfit
	@ Clean up
	setvar VAR_MOSSDEEP_STATE, 11
	setvar VAR_ROUTE128_STATE, 2
	setvar VAR_RAYQUAZA_STATE, 1
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_STEVEN
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_ARCHIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_MAXIE
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_RESIDENTS
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_HIDE_SOOTOPOLIS_CITY_MAN_1
	setflag FLAG_LEGENDARIES_IN_SOOTOPOLIS
	clearflag FLAG_HIDE_ROUTE_128_ARCHIE
	clearflag FLAG_HIDE_ROUTE_128_MAXIE
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_HIDE_MOSSDEEP_CITY_STEVENS_HOUSE_STEVEN
	setflag FLAG_HIDE_MOSSDEEP_SPACE_CENTER_TEAM_MEMBERS
	clearflag FLAG_HIDE_MOSSDEEP_CENTER_FORMER_TEAM_MEMBERS
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_ARCHIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAXIE
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_MAGMA_GRUNTS
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_ROOM_9_KYOGRE_1
	setflag FLAG_HIDE_SEAFLOOR_CAVERN_AQUA_GRUNTS
	setflag FLAG_STEVEN_GUIDES_TO_CAVE_OF_ORIGIN
	getplayerxy VAR_INTERACT_X, VAR_INTERACT_Y
	call Common_EventScript_ClearSceneFlags
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warpcustom MAP_MOSSDEEP_CITY, 255, VAR_INTERACT_X, VAR_INTERACT_Y
	waitstate
	releaseall
	end

MossdeepCity_Text_RainsBegin1:
	.string "{AQUA_BOY}: {PLAYER}!!$"
MossdeepCity_Text_RainsBegin4:
	.string "{AQUA_BOY}: {PLAYER}! We have a problem!\p"
	.string "Archie radioed in that they found\n"
	.string "what they were looking for:\l"
	.string "an ancient Pokémon, just like Groudon!\p"
	.string "I think this confirms my worst fears.\n"
	.string "Team Aqua IS just as insane as\l"
	.string "Team Magma was…$"
MossdeepCity_Text_RainsBegin5:
	.string "{AQUA_BOY}: Oh no…\p"
	.string "Oh no no no no no…$"
MossdeepCity_Text_RainsBegin7:
	.string "{AQUA_BOY}: {PLAYER}…\p"
	.string "Y-You see it, right…?\p"
	.string "A massive sudden storm has formed over\n"
	.string "the entire East Hoenn Sea…\p"
	.string "The storm clouds seem to be centered\n"
	.string "over Sootopolis…\p"
	.string "This…{PAUSE 10} This is bad…$"
MossdeepCity_Text_RainsBegin8:
	.string "Augh! What is happening?!$"
MossdeepCity_Text_RainsBegin9:
	.string "Magma Grunt: The weather! It can't\n"
	.string "decide what it wants to do!\p"
	.string "And Sootopolis! Did you see those\n"
	.string "beasts start fighting on top of it?!\p"
	.string "One of them looked like Groudon!$"
MossdeepCity_Text_RainsBegin11:
	.string "{AQUA_GIRL}: We… We couldn't…\n"
	.string "We couldn't… couldn't control it…$"
MossdeepCity_Text_RainsBegin12:
	.string "{AQUA_BOY}: {AQUA_GIRL}, are you alright?\n"
	.string "You're shaking.$"
MossdeepCity_Text_RainsBegin13:
	.string "{AQUA_GIRL}: N-No… No I'm not alright…\n"
	.string "{AQUA_BOY}, that thing nearly crushed us\l"
	.string "as it escaped the cavern!$"
MossdeepCity_Text_RainsBegin14:
	.string "{AQUA_BOY}: W-What thing?\n"
	.string "The ancient Pokémon?!$"
MossdeepCity_Text_RainsBegin15:
	.string "{AQUA_GIRL}: Yes…{PAUSE 20} Kyogre…$"
MossdeepCity_Text_RainsBegin17:
	.string "{RIVAL_HERO}: I hope you lot are\n"
	.string "happy with yourselves!\p"
	.string "Thanks to your brilliant Teams,\n"
	.string "there's now two ancient super-powerful\l"
	.string "ticked off Pokémon rampaging about,\l"
	.string "causing mass destruction!\p"
	.string "The world is gonna be torn to shreds\n"
	.string "thanks to you numbskulls!\p"
	.string "I've already lost half my team trying\n"
	.string "to clean up your mess!\l"
	.string "Steven's lost most of his team!\p"
	.string "Who knows if anyone can stop these\n"
	.string "things before it's too late!\p"
	.string "I really hope you're freaking happy!!$"
MossdeepCity_Text_RainsBegin21:
	.string "{AQUA_BOY}: Well… I don't know about\n"
	.string "you guys…\p"
	.string "But if the world's gonna end…\n"
	.string "I don't want to be sober when it does…\p"
	.string "I hope the center has a good selection…$"
MossdeepCity_Text_RainsBegin22:
	.string "{AQUA_GIRL}: {AQUA_BOY}, wait for me.$"
MossdeepCity_Text_RainsBegin23:
	.string "Magma Grunt: Can I come too?$"
MossdeepCity_Text_RainsBegin24:
	.string "{AQUA_BOY}: By all means!\p"
	.string "Consider us brothers in screwing over\n"
	.string "the world…$"

.align 2
MossdeepCity_MovementTable_RainsBegin2_PlayerSearch:
	.4byte MossdeepCity_Movement_RainsBegin2_PlayerSearch0
	.4byte MossdeepCity_Movement_RainsBegin2_PlayerSearch1
	.4byte MossdeepCity_Movement_RainsBegin2_PlayerSearch2
	.4byte MossdeepCity_Movement_RainsBegin2_PlayerSearch3
	.4byte MossdeepCity_Movement_RainsBegin2_PlayerSearch4
	.4byte MossdeepCity_Movement_RainsBegin2_PlayerSearch5
	.4byte 0

MossdeepCity_Movement_RainsBegin2_LadyMeander:
	delay_8
	delay_4
	delay_1
	walk_left
	delay_16
	delay_2
	walk_up
	step_end
MossdeepCity_Movement_RainsBegin2_DudeMeander:
	delay_16
	delay_2
	delay_1
	delay_8
	delay_8
	walk_right
	step_end
MossdeepCity_Movement_RainsBegin2_PlayerSearch0:
	emote_question_mark
	delay_8
	face_left
	delay_16
	face_right
	delay_16
	delay_16
	walk_down
	walk_down
	emote_exclamation_mark
	walk_down
	step_end
MossdeepCity_Movement_RainsBegin2_PlayerSearch1:
	emote_question_mark
	delay_8
	face_right
	delay_16
	face_left
	delay_16
	delay_16
	walk_down
	emote_exclamation_mark
	walk_down
	step_end
MossdeepCity_Movement_RainsBegin2_PlayerSearch2:
	emote_question_mark
	delay_8
	face_right
	delay_16
	walk_left
	delay_16
	delay_16
	face_down
	emote_exclamation_mark
	delay_16
	walk_down
	step_end
MossdeepCity_Movement_RainsBegin2_PlayerSearch3:
	emote_question_mark
	delay_8
	face_right
	delay_16
	walk_left
	delay_16
	delay_16
	face_down
	emote_exclamation_mark
	delay_16
	step_end
MossdeepCity_Movement_RainsBegin2_PlayerSearch4:
	emote_question_mark
	delay_8
	face_left
	delay_16
	delay_16
	walk_up
	delay_16
	walk_left
	delay_16
	delay_16
	face_down
	emote_exclamation_mark
	delay_16
	step_end
MossdeepCity_Movement_RainsBegin2_PlayerSearch5:
	emote_question_mark
	delay_8
	face_left
	delay_16
	delay_16
	walk_up
	walk_up
	delay_16
	walk_left
	delay_16
	delay_16
	face_down
	emote_exclamation_mark
	delay_16
	step_end

MossdeepCity_Movement_RainsBegin3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

MossdeepCity_Movement_RainsBegin5_AquaReact:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	face_down
	step_end
MossdeepCity_Movement_RainsBegin5_PlayerReact:
	delay_16
	delay_16
	delay_8
	emote_question_mark
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	step_end
MossdeepCity_Movement_RainsBegin5_LadyReact:
	delay_16
	delay_16
	emote_question_mark
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	face_up
	step_end
MossdeepCity_Movement_RainsBegin5_DudeReact:
	delay_16
	delay_16
	delay_16
	emote_question_mark
	delay_16
	delay_8
	face_up
	delay_16
	face_left
	delay_16
	face_right
	step_end

MossdeepCity_Movement_RainsBegin6_AquaRun:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end
MossdeepCity_Movement_RainsBegin6_PlayerRun:
	emote_question_mark
	delay_16
	delay_16
	delay_16
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_down
	player_run_left
	player_run_left
	player_run_down
	walk_fast_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_in_place_down
	step_end
MossdeepCity_Movement_RainsBegin6_CameraRun:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_diag_southwest
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MossdeepCity_Movement_RainsBegin8:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

MossdeepCity_Movement_RainsBegin10:
	jump_2_up
	delay_16
	walk_in_place_down
	delay_16
	walk_right
	delay_8
	walk_right
	walk_right
	walk_right
	delay_8
	walk_up
	walk_up
	walk_slow_up
	walk_slow_up
	walk_up
	step_end

MossdeepCity_Movement_RainsBegin12:
	walk_down
	walk_in_place_right
	step_end

MossdeepCity_Movement_RainsBegin13:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_left
	step_end

MossdeepCity_Movement_RainsBegin16:
	ride_water_current_up
	jump_2_up
	delay_16
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	walk_in_place_fast_right
	delay_16
	delay_16
	emote_angry
	delay_16
	delay_16
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MossdeepCity_Movement_RainsBegin18_Logan:
	emote_angry
	delay_8
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end
MossdeepCity_Movement_RainsBegin18_AquaBoy:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_up
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	step_end
MossdeepCity_Movement_RainsBegin18_AquaGirl:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_2
	face_up
	step_end
MossdeepCity_Movement_RainsBegin18_MagmaGuy:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	face_up
	step_end
MossdeepCity_Movement_RainsBegin18_Player:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	delay_4
	face_up
	step_end

MossdeepCity_Movement_RainsBegin19_AquaBoy:
	delay_16
	walk_in_place_down
	delay_16
	step_end
MossdeepCity_Movement_RainsBegin19_AquaGirl:
	delay_8
	delay_4
	face_left
MossdeepCity_Movement_RainsBegin19_MagmaGuy:
	delay_16
	delay_16
	delay_4
	face_left
MossdeepCity_Movement_RainsBegin19_Player:
	delay_16
	delay_2
	face_left
	step_end

MossdeepCity_Movement_RainsBegin21_AquaBoy:
	walk_slow_up
	delay_16
	delay_16
	delay_16
	delay_16
	walk_slow_up
	walk_slow_up
	step_end
MossdeepCity_Movement_RainsBegin21_Player:
	delay_16
	walk_up
	walk_up
	face_left
	step_end
MossdeepCity_Movement_RainsBegin21_AquaGirl:
	walk_left
	walk_up
	step_end

MossdeepCity_Movement_RainsBegin22_AquaGirl:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_Movement_RainsBegin23:
	delay_16
	delay_16
	delay_16
	walk_left
	face_down
	step_end
MossdeepCity_Movement_RainsBegin24:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

MossdeepCity_Movement_RainsBegin25:
	walk_left
	walk_left
	walk_down
	step_end
MossdeepCity_Movement_RainsBegin26:
	walk_diag_northeast
	walk_diag_northeast
	step_end

#undef LID_AQUA_BOY
#undef LID_AQUA_GIRL
#undef LID_MAGMA_GUY
#undef LID_LOGAN
#undef LID_RANDO_LADY
#undef LID_RANDO_DUDE

@ -----------------------------------------------------
@ Scene: Logan in a Huff

#define LID_LOGAN 17

MossdeepCity_EventScript_LoganCenter::
	lock
	opendoor 28, 16
	waitdooranim
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_BackOffDown1
	waitmovement 0
	setobjectxyperm LID_LOGAN, 28, 16
	addobject LID_LOGAN
	applymovement LID_LOGAN, Common_Movement_WalkDown1
	waitmovement 0
	closedoor 28, 16
	waitdooranim
	markasdialog
	msgbox MossdeepCity_Text_LoganCenter1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_AngryAndWait
	waitmovement 0
	msgbox MossdeepCity_Text_LoganCenter2
	closemessage
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	setobjectxyperm LID_LOGAN, 80, 0
	removeobject LID_LOGAN
	moveobjectoffscreen LID_LOGAN
	waitfieldeffect FLDEFF_NPCFLY_OUT
	msgbox MossdeepCity_Text_LoganCenter3, MSGBOX_CDESCRIBE
	giveitem_std ITEM_TM58
	setflag FLAG_RECEIVED_TM58
	setvar VAR_MOSSDEEP_STATE, 13
	release
	end
MossdeepCity_Text_LoganCenter1:
	.string "{RIVAL_HERO}: Oh, excuse you.\p"
	.string "Did you drop your bandanna? Wouldn't\n"
	.string "want you to get kicked out of your\l"
	.string "gang for a dress code violation.$"
MossdeepCity_Text_LoganCenter2:
	.string "Don't you swear at me!\p"
	.string "It's YOUR fault we're in this mess\n"
	.string "to begin with! You and your gang!\p"
	.string "Why don't you go home? At least you\n"
	.string "can't cause any more damage there.\p"
	.string "Now excuse me. I need to fly into\n"
	.string "Sootopolis to try and figure out how\l"
	.string "to stop the rampaging god-beasts.$"
MossdeepCity_Text_LoganCenter3:
	.string "{RIVAL_HERO} left something behind\n"
	.string "on the ground.$"

#undef LID_LOGAN
