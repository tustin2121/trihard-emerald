FallarborTown_Mart_MapScripts:: @ 81FFCBE
	.byte 0


FallarborTown_Mart_EventScript_Stealable::
	lock
	msgbox FallarborTown_Mart_Text_Stealable, MSGBOX_DEFAULT
	trysteal ITEM_LEMONADE, 3, FLAG_ITEM_STOLEN_FALLARBOR_MART
	release
	end
FallarborTown_Mart_Text_Stealable:
	.string "The shelves brim with all sorts of\n"
	.string "food items…\l"
	.string "Probably too many to notice…$"

