MetatileScript_PictureBookShelf:: @ 82725CE
	msgbox MetatileText_PictureBookShelf, MSGBOX_DESCRIBE
	end
MetatileText_PictureBookShelf: @ 82A81E5
	.string "There's a set of Pokémon picture books.$"


MetatileScript_BookShelf:: @ 82725D7
	msgbox MetatileText_BookShelf, MSGBOX_DESCRIBE
	end
MetatileText_BookShelf: @ 82A820D
	.string "It's filled with all sorts of books.$"


MetatileScript_PokemonCenterBookShelf:: @ 82725E0
	msgbox MetatileText_PokemonCenterBookShelf, MSGBOX_DESCRIBE
	end
MetatileText_PokemonCenterBookShelf: @ 82A8232
	.string "Pokémon magazines!\n"
	.string "Pokémon Pal…\p"
	.string "Pokémon Handbook…\n"
	.string "Adorable Pokémon…$"


MetatileScript_PokemonCenterSleepSign:: @ 82725E0
	msgbox MetatileText_PokemonCenterSleepSign, MSGBOX_DESCRIBE
	end
MetatileText_PokemonCenterSleepSign: @ 82A8232
	.string "{PLACE}Courtesy Resting Rooms{END}\n"
	.string "“A rested trainer is a safe trainer!”\p"
	.string "“The Pokémon Center is not liable for\n"
	.string "lost or stolen property while using\l"
	.string "our facilities.\p"
	.string "“Please remember to lock your door\n"
	.string "before going to sleep. We ask that\l"
	.string "you respect others' personal space.”$"


MetatileScript_PokemonCenterClock::
	lockall
	setvar VAR_0x8004, 2
	goto Common_EventScript_ViewWallClock
	end


MetatileScript_Vase:: @ 82725E9
	msgbox MetatileText_Vase, MSGBOX_DESCRIBE
	end
MetatileText_Vase: @ 82A8276
	.string "This vase looks expensive…\n"
	.string "Peered inside…\p"
	.string "But, it was empty.$"


MetatileScript_EmptyTrashCan:: @ 82725F2
	callnative HashInteractLocation
	selectpointer_wrap TextArray_EmptyTrashCan, VAR_0x8000
	msgbox_selected MSGBOX_DESCRIBE
	end
.align 2
TextArray_EmptyTrashCan:
	.4byte MetatileText_EmptyTrashCan1
	.4byte MetatileText_EmptyTrashCan2
	.4byte MetatileText_EmptyTrashCan3
	.4byte MetatileText_EmptyTrashCan4
	.4byte MetatileText_EmptyTrashCan5
	.4byte MetatileText_EmptyTrashCan6
	.4byte MetatileText_EmptyTrashCan7
	.4byte 0
MetatileText_EmptyTrashCan1: @ 82A82B3
	.string "It's empty.$"
MetatileText_EmptyTrashCan2:
	.string "It's full of used napkins and tissues.$"
MetatileText_EmptyTrashCan3:
	.string "There's a half-eaten burger in there.$"
MetatileText_EmptyTrashCan4:
.if TPP_MODE
	.string "There's a figure of a man in there,\n"
	.string "covered in trash. How very disgusting.$"
.else
	.string "There's some discarded fliers in here\n"
	.string "that have old memes printed on them…$"
.endif
MetatileText_EmptyTrashCan5:
	.string "Looks like there's a broken TM in here.$"
MetatileText_EmptyTrashCan6:
	.string "Is that a used…? Oh, gross!$"
MetatileText_EmptyTrashCan7:
	.string "Hopefully those papers weren't\nimportant.$"


MetatileScript_ShopShelf:: @ 82725FB
	msgbox MetatileText_ShopShelf, MSGBOX_DESCRIBE
	end
MetatileText_ShopShelf: @ 82A82BF
	.string "The shelves brim with all sorts of\n"
	.string "Pokémon merchandise.$"


MetatileScript_Blueprint:: @ 8272604
	msgbox MetatileText_Blueprint, MSGBOX_DESCRIBE
	end
MetatileText_Blueprint: @ 82A82F7
	.string "It's a blueprint. You scrutinize it,\n"
	.string "examining the details and measurements\l"
	.string "for a while, imagining what it would\l"
	.string "look like when built…$"


MetatileScript_RegionMap:: @ 827208F
	lockall
	msgbox MetatileText_LookCloserAtMap, MSGBOX_DEFAULT
	fadescreen 1
	special FieldShowRegionMap
	waitstate
	releaseall
	end
MetatileText_LookCloserAtMap: @ 81F8820
	.string "{PLAYER} took a closer look at the\n"
	.string "Hoenn region map.$"


MetatileScript_RunningShoesManual:: @ 8292DE5
	@ msgbox LittlerootTown_PlayersHouse_1F_Text_1F7F66, MSGBOX_SIGN
	release
	end
@ LittlerootTown_PlayersHouse_1F_Text_1F7F66: @ 81F7F66
@ 	.string "It's the instruction booklet for the\n"
@ 	.string "RUNNING SHOES.\p"
@ 	.string "“Press the B Button to run while\n"
@ 	.string "wearing your RUNNING SHOES.\p"
@ 	.string "“Lace up your RUNNING SHOES and hit\n"
@ 	.string "the road running!”$"
