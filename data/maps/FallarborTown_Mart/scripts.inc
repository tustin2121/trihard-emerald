FallarborTown_Mart_MapScripts:: @ 81FFCBE
	map_script MAP_SCRIPT_STEAL_CHECK, FallarborTown_Mart_StealCheck
	.byte 0


FallarborTown_Mart_EventScript_Stealable::
	lock
	msgbox RustboroCity_Store_Text_Stealable, MSGBOX_DEFAULT
	trysteal ITEM_LEMONADE, 3, FLAG_DAILY_ITEM_STOLEN_FALLARBOR_MART
	release
	end

FallarborTown_Mart_StealCheck:
	setflag FLAG_DAILY_ITEM_STOLEN_FALLARBOR_MART @ flag is always set regardless
	random 100 @ 20% chance to fail
	compare VAR_RESULT, 20
	goto_if_lt RustboroCity_Mart_StealCheck_Fail
	setvar VAR_RESULT, 1
	return
