EverGrandeCity_PokemonCenter_2F_MapScripts:: @ 8229CE0
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PokemonCenter_2F_MapTable
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PokemonCenter_2F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, PokemonCenter_2F_OnTransition
	.byte 0

EverGrandeCity_PokemonCenter_2F_OnLoad:: @ 8229CF5
	call_if_set FLAG_DAILY_STEALFAIL_EVERGRANDE_SOUTH1, EverGrandeCity_PokemonCenter_2F_EventScript_AfterKickout
	end

EverGrandeCity_PokemonCenter_2F_MapTable:
	map_script_2 VAR_LAST_WARP_ID, 2, Common_EventScript_SetPowerOffWeather
	.2byte 0

EverGrandeCity_PokemonCenter_2F_EventScript_AfterKickout:
	setobjectxyperm 6, 18, 6
	setobjectxy 6, 18, 6
	setmetatile 18, 5, 0x32B, FALSE @Set tile to non-warp tile
	end

@ -----------------------------------------------------

#define LID_BOY 3

EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoy::
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SleepingBoy
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoy:
	.string "Not quite sure if he's sleeping…$"

EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoysBag::
	lock
	trysteal_setcheck EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoy_StealCheck
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag, MSGBOX_DEFAULT
	trysteal ITEM_HYPER_POTION, 3, FLAG_ITEM_STOLEN_EVERGRANDE_SOUTH1
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag:
	.string "He's got more than enough of those…$"
EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoy_StealCheck:
	closemessage
	playse SE_PIN
	random 100 @ 50% chance
	@
	@ buffernumberstring 0, VAR_RESULT
	@ message EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_DEBUG
	@ waitmessage
	@ waitbuttonpress
	@
	compare VAR_RESULT, 50
	goto_if_lt EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoy_StealCheckFail
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Shock
	applymovement LID_BOY, EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Success
	waitmovement LID_BOY
	markasdialog 15
	message EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_Success
	waitmessage
	waitbuttonpress
	closemessage
	delay 16
	call Common_EventScript_RestorePlayerFacing
	setvar VAR_RESULT, 1
	return
EverGrandeCity_PokemonCenter_2F_EventScript_SleepingBoy_StealCheckFail:
	applymovement EVENT_OBJ_ID_PLAYER, EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Shock
	applymovement LID_BOY, EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Fail
	waitmovement LID_BOY
	markasdialog 15
	selectpointer_ongender EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_FailMale, EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_FailFemale
	message 0
	waitmessage
	waitbuttonpress
	closemessage
	delay 16
	setflag FLAG_DAILY_STEALFAIL_EVERGRANDE_SOUTH1
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement EVENT_OBJ_ID_PLAYER
	warptodynamic
	waitstate
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_DEBUG:
	.string "VAR RESULT = {STR_VAR_1}$"
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_Success:
	.string "Ugh… … …\n"
	.string "zzzzzzz…$"
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_FailMale:
	.string "Ugh… … …\n"
	.string "Mom? Is that you?$"
EverGrandeCity_PokemonCenter_2F_Text_SleepingBoysBag_FailFemale:
	.string "Ugh… … …\n"
	.string "Dad? Is that you?$"
	
EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Shock:
	walk_in_place_fastest_right
	emote_exclamation_mark
	delay_16
	step_end
EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Success:
	walk_in_place_slow_right
	walk_in_place_right
	delay_8
	delay_4
	walk_in_place_up
	walk_in_place_slow_up
	step_end
EverGrandeCity_PokemonCenter_2F_Movement_SleepingBoy_Fail:
	walk_in_place_slow_right
	walk_in_place_right
	delay_8
	delay_4
	walk_in_place_down
	delay_8
	delay_4
	walk_in_place_fast_left
	delay_8
	emote_question_mark
	step_end

#undef LID_BOY


EverGrandeCity_PokemonCenter_2F_EventScript_SnorlaxDoll::
	lock
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll, MSGBOX_CDESCRIBE
	givedecoration_std DECOR_SNORLAX_DOLL
	msgbox EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll2, MSGBOX_CDESCRIBE
	removeobject THIS_EVENT
	release
	end
EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll:
	.string "Wow, that's a big plush!\p"
	.string "…\p"
	.string "Yoink!\p"
	.string "Ack!! It's heavy!!$"
EverGrandeCity_PokemonCenter_2F_Text_SnorlaxDoll2:
	.string "Which is good, because you weren't\n"
	.string "sure how to fit it into your bag!$"
