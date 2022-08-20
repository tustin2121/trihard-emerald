SlateportCity_Mart_MapScripts:: @ 820DC48
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_Mart_FrameTable
	.byte 0


SlateportCity_Mart_FrameTable:
	map_script_2 VAR_BANNED_SLATEPORT_MART, 1, SlateportCity_Mart_EventScript_KickedOut

SlateportCity_Mart_EventScript_KickedOut:
	applymovement 1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	markasdialog 6
	msgbox SlateportCity_Mart_Text_KickedOut
	warp MAP_SLATEPORT_CITY, 1, 255, 255
	waitstate
	end
SlateportCity_Mart_Text_KickedOut:
	.string "No! You're banned from my store!$"

SlateportCity_Mart_EventScript_Stealable::
	lock
	@ trysteal - always fails
	msgbox SlateportCity_Mart_Text_Stealable1, MSGBOX_DEFAULT
	markasdialog -24
	playse SE_PIN
	applymovement 1, Common_Movement_ExclamationMarkAndWait
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox SlateportCity_Mart_Text_Stealable2
	setvar VAR_BANNED_SLATEPORT_MART, 1
	warp MAP_SLATEPORT_CITY, 1, 255, 255
	waitstate
	release
	end
SlateportCity_Mart_Text_Stealable1:
	.string "The shelves brim with all sorts of\n"
	.string "food items…\l"
	.string "Probably too many to notice…$"
SlateportCity_Mart_Text_Stealable2:
	.string "Hey! What are you doing?!$"

