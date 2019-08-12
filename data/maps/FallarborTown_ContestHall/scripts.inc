FallarborTown_ContestHall_MapScripts::
	.byte 0

@ -----------------------------------------------------

FallarborTown_ContestHall_Stealspot::
	lock
	msgbox FallarborTown_ContestHall_Stealspot_Text, MSGBOX_DEFAULT
	trysteal ITEM_SITRUS_BERRY, 5, FLAG_ITEM_STOLEN_FALLARBOR_CONTESTHALL
	release
	end
FallarborTown_ContestHall_Stealspot_Text::
	.string "Looks like someone left this behind…$"
