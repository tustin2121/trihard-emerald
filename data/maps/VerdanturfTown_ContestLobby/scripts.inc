VerdanturfTown_ContestLobby_MapScripts:: @ 821A211
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_ContestLobby_OnTransition
	.byte 0

@ -----------------------------------------------------

VerdanturfTown_ContestLobby_OnTransition: @ 821A21C
	call LilycoveCity_ContestLobby_EventScript_28CB2B
	call LilycoveCity_ContestLobby_EventScript_21A227
	end

@ -----------------------------------------------------

VerdanturfTown_ContestLobby_EventScript_JoinContestNPC::
	special sub_80F9154
	specialvar VAR_RESULT, sub_80F8D24
	compare VAR_RESULT, 1
	goto_if_eq VerdanturfTown_ContestLobby_EventScript_21A5CF
	call LilycoveCity_ContestLobby_EventScript_279CC5
	call VerdanturfTown_ContestLobby_EventScript_21A670
	special SetContestTrainerGfxIds
	call LilycoveCity_ContestLobby_EventScript_23BEB6
	call LilycoveCity_ContestLobby_EventScript_21A585
	call LilycoveCity_ContestLobby_EventScript_21A5EF
	waitstate
	end

VerdanturfTown_ContestLobby_EventScript_21A5CF::
	setflag FLAG_HIDE_LILYCOVE_MUSEUM_CURATOR
	copyvar VAR_LILYCOVE_MUSEUM_2F_STATE, 0x1
	giveitem ITEM_CONTEST_PASS, 1
	setvar VAR_0x800B, 8
	setvar VAR_CONTEST_RANK, 3
	setvar VAR_LILYCOVE_CONTEST_LOBBY_STATE, 1
	setflag FLAG_SYS_RIBBON_GET
	end

VerdanturfTown_ContestLobby_EventScript_21A670::
	lockall
	applymovement 1, VerdanturfTown_ContestLobby_Movement_21A6F5
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
	applymovement 1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox LilycoveCity_ContestLobby_Text_27B653, MSGBOX_DEFAULT
	closemessage
	applymovement 1, VerdanturfTown_ContestLobby_Movement_21A6FD
	applymovement EVENT_OBJ_ID_PLAYER, LilycoveCity_ContestLobby_Movement_21A6E8
	waitmovement 0
	setdynamicwarp MAP_VERDANTURF_TOWN_CONTEST_LOBBY, 0xFF, 5, 4
	@ setvar VAR_CONTEST_LOCATION, 1
	releaseall
	return

VerdanturfTown_ContestLobby_Movement_21A6F5::
	walk_left
	walk_in_place_fastest_down
	step_end

VerdanturfTown_ContestLobby_Movement_21A6FD::
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	delay_8
	set_invisible
	step_end

@ -----------------------------------------------------

VerdanturfTown_ContestLobby_JustAPlant::
	goto_if_unset FLAG_ITEM_CONTEST_HALL_LEAF_STONE, VerdanturfTown_ContestLobby_JustAPlant_ItemFind
	msgbox VerdanturfTown_ContestLobby_JustAPlant_Text, MSGBOX_DESCRIBE
	release
	end
VerdanturfTown_ContestLobby_JustAPlant_Text::
	.string "It's just a plant.\p"
	.string "What did you expect,\n"
	.string "a hidden PC behind it?$"
VerdanturfTown_ContestLobby_JustAPlant_ItemFind::
	msgbox VerdanturfTown_ContestLobby_JustAPlant_ItemFind_Text, MSGBOX_DESCRIBE
	giveitem_std ITEM_LEAF_STONE
	setflag FLAG_ITEM_CONTEST_HALL_LEAF_STONE
	release
	end
VerdanturfTown_ContestLobby_JustAPlant_ItemFind_Text::
	.string "It's just a plant.\p"
	.string "What did you expect,\n"
	.string "a hidden PC behind it?\p"
	.string "There's something in the pot, though…$"


VerdanturfTown_ContestLobby_ContestFan::
	faceplayer
	msgbox VerdanturfTown_ContestLobby_Text_ContestFan, MSGBOX_CDIALOG
	release
	end
VerdanturfTown_ContestLobby_Text_ContestFan::
	.string "I'm a huge fan of Sydney\n"
	.string "and her Whiris.\p"
	.string "They are totally the best together!$"

