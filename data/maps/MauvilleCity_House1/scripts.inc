MauvilleCity_House1_MapScripts:: @ 820F975
	map_script MAP_SCRIPT_STEAL_CHECK, Common_EventScript_StealCheck_CheckSingleNPC_NoRightUp
	.byte 0

MauvilleCity_House1_EventScript_20F976:: @ 820F976
	lock
	faceplayer
	markasdialog
	goto_if_set FLAG_RECEIVED_TM56, MauvilleCity_House1_EventScript_20F9A5
	msgbox MauvilleCity_House1_Text_20F9AF, MSGBOX_DEFAULT
	giveitem_std ITEM_TM56
	setflag FLAG_RECEIVED_TM56
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_20FAA9, MSGBOX_DEFAULT
	release
	end
MauvilleCity_House1_Text_20F9AF: @ 820F9AF
	.string "Woohoo!\p"
	.string "I hear people call me the ROCK SMASH\n"
	.string "GUY, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the ROCK SMASH DUDE.\p"
	.string "Woohoo!\p"
	.string "Anyways, your Pokémon look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this TECHNICAL MACHINE!$"
MauvilleCity_House1_Text_20FAA9: @ 820FAA9
	.string "That TM contains ROCK SMASH.\p"
	.string "Smash rocks aside, I say!\n"
	.string "Woohoo!$"
MauvilleCity_House1_EventScript_20F9A5:: @ 820F9A5
	msgbox MauvilleCity_House1_Text_20FB67, MSGBOX_DEFAULT
	release
	end
MauvilleCity_House1_Text_20FB67: @ 820FB67
	.string "Oh, yes, if you smash a rock, a Pokémon\n"
	.string "could come flying out of hiding.\p"
	.string "Woohoo!$"


MauvilleCity_House1_EventScript_StealSpot::
	lock
	setdynamicwarp MAP_MAUVILLE_CITY, 4, 255, 255  @ Spot to get thrown out to
	msgbox MauvilleCity_House1_StealSpot_Text, MSGBOX_DEFAULT
	trysteal ITEM_LUCKY_EGG, 1, FLAG_ITEM_STOLEN_MAUVILLE_HOUSE1
	release
	end
MauvilleCity_House1_StealSpot_Text:
	.string "I wonder how lucky he thinks this is…$"
