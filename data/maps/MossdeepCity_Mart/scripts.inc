MossdeepCity_Mart_MapScripts:: @ 82223C7
	map_script MAP_SCRIPT_STEAL_CHECK, MossdeepCity_Mart_StealCheck
	.byte 0

MossdeepCity_Store_MartScript::
	lock
	faceplayer
	markasdialog
	message MossdeepCity_Store_Welcome
	waitmessage
	pokemart MossdeepCity_Store_Pokemart
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end
MossdeepCity_Store_Welcome:
	.string "Hey, welcome to the Mossdeep Emporium!\p"
	.string "How can I help you?$"

.align 2
MossdeepCity_Store_Pokemart:
	.2byte ITEM_LEMONADE
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_ETHER
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_ELIXIR
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_SODA_POP
	.2byte ITEM_CARBOS
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_HP_UP
	.2byte ITEM_CALCIUM
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Stealable::
	lock
	msgbox RustboroCity_Store_Text_Stealable, MSGBOX_DEFAULT
	trysteal ITEM_LAVA_COOKIE, 5, FLAG_DAILY_ITEM_STOLEN_MOSSDEEP_MART
	release
	end

MossdeepCity_Mart_StealCheck:
	setflag FLAG_DAILY_ITEM_STOLEN_MOSSDEEP_MART @ flag is always set regardless
	@ Check mart employee
	setvar VAR_0x8000, 1
	callnative GetObjectFacingAndPosition
	compare VAR_RESULT, DIR_EAST
	goto_if_eq MossdeepCity_Mart_StealCheck_Fail1
	@ Check fisherman
	setvar VAR_0x8000, 2
	callnative GetObjectFacingAndPosition
	compare VAR_0x8001, 7 @ x position = must be >= 7
	goto_if_lt MossdeepCity_Mart_StealCheck_Success
	compare VAR_RESULT, DIR_SOUTH @ facing south
	goto_if_eq MossdeepCity_Mart_StealCheck_Fail2
	@fallthrough
MossdeepCity_Mart_StealCheck_Success:
	@ Neither noticed, success
	setvar VAR_RESULT, 1
	return
MossdeepCity_Mart_StealCheck_Fail1:
	closemessage
	applymovement 1, Common_Movement_ExclamationMarkAndWait
	playse SE_PIN
	waitmovement 1
	applymovement 3, Common_Movement_WalkInPlaceRight
	waitmovement 3
	@
	markasdialog -20
	message MossdeepCity_Mart_StealCheck_Fail1Text
	waitmessage
	waitbuttonpress
	@
	release
	end
MossdeepCity_Mart_StealCheck_Fail2:
	applymovement 2, Common_Movement_ExclamationMarkAndWait
	playse SE_PIN
	waitmovement 2
	@
	markasdialog
	message MossdeepCity_Mart_StealCheck_Fail2Text
	delay 15
	applymovement LID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmessage
	waitmovement LID_PLAYER
	waitbuttonpress
	@
	setflag FLAG_TEMP_2
	release
	end
MossdeepCity_Mart_StealCheck_Fail1Text:
	.string "Uh, {PLAYER_sir}, you are going to\n"
	.string "pay for those, right?$"
MossdeepCity_Mart_StealCheck_Fail2Text:
	.string "Ehm… you are going to pay for those,{PAUSE 20}\n"
	.string "…{PAUSE 20} …{PAUSE 20} …right?$"


MossdeepCity_Mart_Fisherman::
	select_if_set FLAG_TEMP_2, MossdeepCity_Mart_FishermanText_StealAttempt, MossdeepCity_Mart_FishermanText
	msgbox_selected MSGBOX_NPC
	end
MossdeepCity_Mart_FishermanText:
	.string "This place usually sells bait,\n"
	.string "doesn't it? Are they out?$"
MossdeepCity_Mart_FishermanText_StealAttempt:
	.string "I wouldn't say anything if this was\n"
	.string "some big chain store, but stealing\l"
	.string "from a locally-owned business? Shame!$"

MossdeepCity_Mart_Camper::
	msgbox MossdeepCity_Mart_CamperText, MSGBOX_DESCRIBE
	end
MossdeepCity_Mart_CamperText:
	.string "He seems to be in a flirty conversation\n"
	.string "with the cashier girl.$"


