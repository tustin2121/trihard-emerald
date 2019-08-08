SlateportCity_ContestLobby_MapScripts:: @ 821A211
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_ContestLobby_OnTransition
	.byte 0

SlateportCity_ContestLobby_OnTransition: @ 821A21C
	call LilycoveCity_ContestLobby_EventScript_28CB2B
	call LilycoveCity_ContestLobby_EventScript_21A227
	end

SlateportCity_ContestLobby_EventScript_JoinContestNPC::
	special sub_80F9154
	specialvar VAR_RESULT, sub_80F8D24
	compare VAR_RESULT, 1
	goto_if_eq SlateportCity_ContestLobby_EventScript_21A5CF
	call LilycoveCity_ContestLobby_EventScript_279CC5
	call SlateportCity_ContestLobby_EventScript_21A670
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_23BEB6
	call LilycoveCity_ContestLobby_EventScript_21A585
	call LilycoveCity_ContestLobby_EventScript_21A5EF
	waitstate
	end

SlateportCity_ContestLobby_EventScript_21A5CF::
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 0x1
	giveitem ITEM_CONTEST_PASS, 1
	setvar VAR_0x800B, 8
	setvar VAR_CONTEST_RANK, 3
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	setflag FLAG_SYS_RIBBON_GET
	end

SlateportCity_ContestLobby_EventScript_21A670::
	lockall
	applymovement 1, SlateportCity_ContestLobby_Movement_21A6F5
	waitmovement 0
	playse SE_HASHI
	setmetatile 4, 2, 545, 1
	setmetatile 4, 3, 609, 1
	special DrawWholeMapView
	applymovement 1, LilycoveCity_ContestLobby_Movement_21A6F9
	waitmovement 0
	playse SE_HASHI
	setmetatile 4, 2, 721, 1
	setmetatile 4, 3, 729, 1
	special DrawWholeMapView
	delay 20
	applymovement 1, LilycoveCity_ContestLobby_Movement_21A706
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, SlateportCity_ContestLobby_Movement_21A6F2_Player
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_27B653, MSGBOX_DEFAULT
	closemessage
	applymovement 1, SlateportCity_ContestLobby_Movement_21A6FD
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_ContestLobby_Movement_21A6E8
	waitmovement 0
	setdynamicwarp MAP_SLATEPORT_CITY_CONTEST_LOBBY, 0xFF, 5, 4
	releaseall
	return

SlateportCity_ContestLobby_Movement_21A6F5::
	walk_left
	walk_in_place_fastest_down
	step_end

SlateportCity_ContestLobby_Movement_21A6FD::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

SlateportCity_ContestLobby_Movement_21A6F2_Player::
	walk_in_place_fastest_left
	step_end

SlateportCity_ContestLobby_IdolGirlPC::
	lockall
	msgbox SlateportCity_ContestLobby_IdolGirlPC_Text, MSGBOX_CDIALOG
	msgbox SlateportCity_ContestLobby_IdolGirlPC_Text_DESC, MSGBOX_DEFAULT
	compare VAR_LETTER_INTERNETMUSIC_LOVERS, 0
	call_if_eq SlateportCity_ContestLobby_IdolGirlPC_FirstTime
	releaseall
	compare VAR_LETTER_INTERNETMUSIC_LOVERS, 2
	call_if_eq SlateportCity_ContestLobby_IdolGirlPC_AfterDelivery
	releaseall
	end

SlateportCity_ContestLobby_IdolGirlPC_FirstTime:
	playse SE_PIN
	applymovement 4, SlateportCity_ContestLobby_IdolGirlPC_Faceplayer
	waitmovement 4
	msgbox SlateportCity_ContestLobby_IdolGirlPC_Text_Letter1, MSGBOX_CDIALOG
	playfanfare MUS_FANFA4
	giveitem_std ITEM_LETTER
	msgbox SlateportCity_ContestLobby_IdolGirlPC_Text_Letter2, MSGBOX_CDIALOG
	setvar VAR_LETTER_INTERNETMUSIC_LOVERS, 1
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 4
	return

SlateportCity_ContestLobby_IdolGirlPC_AfterDelivery:
	faceplayer
	msgbox SlateportCity_ContestLobby_IdolGirlPC_Text_AfterDelivery1, MSGBOX_CDIALOG
	giveitem_std ITEM_BRIGHT_POWDER
	msgbox SlateportCity_ContestLobby_IdolGirlPC_Text_AfterDelivery2, MSGBOX_CDIALOG
	setvar VAR_LETTER_INTERNETMUSIC_LOVERS, 3
	applymovement 4, Common_Movement_FaceOriginalDirection
	waitmovement 4
	return

SlateportCity_ContestLobby_IdolGirlPC_Text:
	.string "Booy mo giirl mo nai sekai,\n"
	.string "Lovelove to ka kankei ne!\p"
	.string "Saitan kiroku de, omae wa kuzureochi\n"
	.string "Watashi ni sugaritsuku!$"

SlateportCity_ContestLobby_IdolGirlPC_Text_DESC:
	.string "She's singing along a Japanese video\n"
	.string "with an idol dressed as a battle woman.$"

SlateportCity_ContestLobby_IdolGirlPC_Text_Letter1::
	.string "Your smell!\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "You smell like the sand of Dewford…\p"
	.string "Listen, I have a favor to ask.\p"
	.string "There's a guy in Dewford who really\n"
	.string "likes music videos.\p"
	.string "Can you please bring this to him?\p"
	.string "I will give you something good\n"
	.string "in exchange, I promise!$"

SlateportCity_ContestLobby_IdolGirlPC_Text_Letter2::
	.string "I would LOVE to do it myself,\n"
	.string "but I'm very busy at the moment.\p"
	.string "… … … … … …\p"
	.string "What's with that look?!\n"
	.string "It's not that I'm embarassed…$"

SlateportCity_ContestLobby_IdolGirlPC_Faceplayer:
	emote_exclamation_mark
	face_player
	step_end

SlateportCity_ContestLobby_IdolGirlPC_Text_AfterDelivery1::
	.string "What is it?\p"
	.string "I cannot believe it,\n"
	.string "you actually did it!\p"
	.string "I don't know how to thank you.\p"
	.string "I hope this will be enough!$"

SlateportCity_ContestLobby_IdolGirlPC_Text_AfterDelivery2::
	.string "I really hope he appreciated\n"
	.string "my letter…$"

SlateportCity_ContestLobby_ContestFan::
	faceplayer
	lock
	msgbox SlateportCity_ContestLobby_Text_ContestFan, MSGBOX_CDIALOG
	release
	end

SlateportCity_ContestLobby_Text_ContestFan:
	.string "What's my favourite type of contests?\n"
	.string "Well, coolness contests, of course.\p"
	.string "They fit me perfectly!$"
