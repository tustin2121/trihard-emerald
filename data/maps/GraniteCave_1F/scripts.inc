GraniteCave_1F_MapScripts:: @ 822DA5D
	.byte 0

@ -----------------------------------------------------
@ Items

GraniteCave_1F_EventScript_ItemEscapeRope:: @ 8291150
	giveitem_std ITEM_ESCAPE_ROPE, 1, 1
	end

@ -----------------------------------------------------

GraniteCave_1F_EventScript_22DA5E:: @ 822DA5E
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM55, GraniteCave_1F_EventScript_22DA8A
	msgbox GraniteCave_1F_Text_22DA94, MSGBOX_DEFAULT
	giveitem_std ITEM_TM55
	setflag FLAG_RECEIVED_TM55
	msgbox GraniteCave_1F_Text_22DBB7, MSGBOX_DEFAULT
	release
	end
GraniteCave_1F_EventScript_22DA8A:: @ 822DA8A
	msgbox GraniteCave_1F_Text_22DBB8, MSGBOX_DEFAULT
	release
	end
GraniteCave_1F_Text_22DA94: @ 822DA94
	.string "Hey, you.\n"
	.string "It gets awfully dark ahead.\l"
	.string "It'll be tough trying to explore.\p"
	.string "For us hikers, helping out those\n"
	.string "that we meet is our motto.\p"
	.string "Let me give you some advice:\p"
	.string "Some of your Pokémon should be able to\n"
	.string "do something called “Flash”.\p"
	.string "Flash lights up even the inky\n"
	.string "darkness of caves.\p"
	.string "But, to use it, you need the Gym Badge\n"
	.string "from Dewford's Pokémon Gym.\p"
	.string "Here, I'll pass this on to you as well.$"
GraniteCave_1F_Text_22DBB7: @ 822DBB7
	.string "That TM teaches the move Flash to a\n"
	.string "Pokémon, so they can use it in battle.\p"
	.string "Remember, you don't need to teach the\n"
	.string "move for a Pokémon to be able to use\l"
	.string "the capability outside of battle.$"
GraniteCave_1F_Text_22DBB8:
	.string "Flash lights up even the inky\n"
	.string "darkness of caves.\p"
	.string "But, to use it, you need the Gym Badge\n"
	.string "from Dewford's Pokémon Gym.$"
