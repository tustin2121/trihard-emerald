RustboroCity_Mart_MapScripts:: @ 8214F05
	.byte 0

@ -----------------------------------------------------

RustboroCity_Store_MartScript:: @ 820DC49
	lock
	faceplayer
	markasdialog
	message RustboroCity_Store_Welcome
	waitmessage
	pokemart RustboroCity_Store_Pokemart
	msgbox gText_Mart_Goodbye, MSGBOX_DIALOG
	release
	end
RustboroCity_Store_Welcome:: @ 8272A21
	.string "Welcome to M&S!\p"
	.string "How may I serve you?$"

.align 2
RustboroCity_Store_Pokemart: @ 8214F58
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_TINY_MUSHROOM
	.2byte ITEM_LEMONADE
	.2byte ITEM_NANAB_BERRY
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_SODA_POP
	.2byte ITEM_CORNN_BERRY
	.2byte ITEM_MOOMOO_MILK
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_FLUFFY_TAIL
	.2byte ITEM_NONE
	release
	end


RustboroCity_Store_EventScript_Fridge::
	msgbox RustboroCity_Store_Text_Fridge, MSGBOX_DESCRIBE
	end
RustboroCity_Store_Text_Fridge:
	.string "Full of sandwiches and cold items.$"


RustboroCity_Store_EventScript_Shelves::
	msgbox RustboroCity_Store_Text_Shelves, MSGBOX_DESCRIBE
	end
RustboroCity_Store_Text_Shelves:
	.string "The shelves brim with all sorts of\n"
	.string "food items.$"


RustboroCity_Store_EventScript_Stealable::
	lock
	msgbox RustboroCity_Store_Text_Stealable, MSGBOX_DEFAULT
	trysteal ITEM_FRESH_WATER, 2, FLAG_ITEM_STOLEN_RUSTBORO_MART
	release
	end
RustboroCity_Store_Text_Stealable:
	.string "The shelves brim with all sorts of\n"
	.string "food items…\l"
	.string "Probably too many to notice…$"

