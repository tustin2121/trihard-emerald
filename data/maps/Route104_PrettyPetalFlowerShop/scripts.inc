Route104_PrettyPetalFlowerShop_MapScripts:: @ 822A34C
	map_script MAP_SCRIPT_ON_TRANSITION, Route104_PrettyPetalFlowerShop_OnTransition
	.byte 0

@ -----------------------------------------------------

Route104_PrettyPetalFlowerShop_OnTransition: @ 822A352
	setflag FLAG_LANDMARK_FLOWER_SHOP
	goto_if_unset FLAG_MET_PRETTY_PETAL_SHOP_OWNER, Route104_PrettyPetalFlowerShop_EventScript_22A36B
	goto_if_unset FLAG_BADGE03_GET, Route104_PrettyPetalFlowerShop_EventScript_22A36B
	setflag FLAG_TEMP_1
	end

Route104_PrettyPetalFlowerShop_EventScript_22A36B:: @ 822A36B
	setobjectxyperm 1, 4, 6
	end

@ -----------------------------------------------------

Route104_PrettyPetalFlowerShop_EventScript_Owner:: @ 822A373
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, Route104_PrettyPetalFlowerShop_EventScript_22A3E4
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7686, MSGBOX_DEFAULT
	setflag FLAG_MET_PRETTY_PETAL_SHOP_OWNER
	setyesnotext gYN_Uhhh, gYN_UgNo
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7706, MSGBOX_YESNO
	compare VAR_RESULT, YES
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_22A3D2
	compare VAR_RESULT, NO
	call_if_eq Route104_PrettyPetalFlowerShop_EventScript_22A3DB
	release
	end
Route104_PrettyPetalFlowerShop_Text_2A7686: @ 82A7686
	.string "Hello!\p"
	.string "This is the {PLACE}Pretty Petal Flower Shop{END}.\n"
	.string "Spreading flowers all over the world!$"
Route104_PrettyPetalFlowerShop_Text_2A7706: @ 82A7706
	.string "Would you like to learn about\n"
	.string "berries?$"
Route104_PrettyPetalFlowerShop_EventScript_22A3D2:: @ 822A3D2
	msgbox Route104_PrettyPetalFlowerShop_Text_2A775B, MSGBOX_DEFAULT
	return
Route104_PrettyPetalFlowerShop_Text_2A775B: @ 82A775B
	.string "Berries grow on trees that thrive\n"
	.string "only in soft, loamy soil.\p"
	.string "If you take some berries, be sure to\n"
	.string "plant one in the loamy soil again.\p"
	.string "A planted berry will soon sprout,\n"
	.string "grow into a plant, flower beautifully,\l"
	.string "then grow berries again.\p"
	.string "I want to see the whole wide world\n"
	.string "filled with beautiful flowers.\l"
	.string "That's my dream.\p"
	.string "Please help me. Plant berries\n"
	.string "and bring more flowers into the world.$"
Route104_PrettyPetalFlowerShop_EventScript_22A3DB:: @ 822A3DB
	msgbox Route104_PrettyPetalFlowerShop_Text_2A78DF, MSGBOX_DEFAULT
	return
Route104_PrettyPetalFlowerShop_Text_2A78DF: @ 82A78DF
	.string "Well, excuse me…\p"
	.string "Flowers bring so much happiness to\n"
	.string "people. You should reconsider…$"

Route104_PrettyPetalFlowerShop_EventScript_22A3E4:: @ 822A3E4
	message Route104_PrettyPetalFlowerShop_Text_22A3E4
	waitmessage
	pokemartdecoration2 Route104_PrettyPetalFlowerShop_Pokemart_Plants
	msgbox gText_Mart_Goodbye, MSGBOX_DEFAULT
	release
	end
Route104_PrettyPetalFlowerShop_Text_22A3E4:: @ 8272A52
	.string "Welcome!\p"
	.string "What can I do for you?$"

	.align 2
Route104_PrettyPetalFlowerShop_Pokemart_Plants: @ 822A3FC
	.2byte DECOR_RED_PLANT
	.2byte DECOR_TROPICAL_PLANT
	.2byte DECOR_PRETTY_FLOWERS
	.2byte DECOR_COLORFUL_PLANT
	.2byte DECOR_BIG_PLANT
	.2byte DECOR_GORGEOUS_PLANT
	.2byte DECOR_NONE
	release
	end


Route104_PrettyPetalFlowerShop_EventScript_PailGirl:: @ 822A40C
	lock
	faceplayer
	markasdialog
	goto_if_unset FLAG_RECEIVED_WAILMER_PAIL, Route104_PrettyPetalFlowerShop_EventScript_22A421
	msgbox Route104_PrettyPetalFlowerShop_Text_2A79A6, MSGBOX_DEFAULT
	release
	end
Route104_PrettyPetalFlowerShop_Text_2A79A6: @ 82A79A6
	.string "While berry plants are growing,\n"
	.string "water them with the Wailmer Pail.\p"
	.string "Oh, another thing.\p"
	.string "If you don't pick berries for a while,\n"
	.string "they'll drop off onto the ground.\l"
	.string "But they'll sprout again.\p"
	.string "Isn't that awesome?\n"
	.string "It's like they have the will to live.$"
Route104_PrettyPetalFlowerShop_EventScript_22A421:: @ 822A421
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7916, MSGBOX_DEFAULT
	giveitem_std ITEM_WAILMER_PAIL
	msgbox Route104_PrettyPetalFlowerShop_Text_2A79A6, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_WAILMER_PAIL
	release
	end
Route104_PrettyPetalFlowerShop_Text_2A7916: @ 82A7916
	.string "Hello!\p"
	.string "The more attention you give to flowers,\n"
	.string "the more beautifully they bloom.\p"
	.string "You'll like tending flowers. I'm sure\n"
	.string "of it. You can have this.$"


Route104_PrettyPetalFlowerShop_EventScript_22A442:: @ 822A442
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY, Route104_PrettyPetalFlowerShop_EventScript_22A482
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7A98, MSGBOX_DEFAULT
	random 8
	addvar VAR_RESULT, 133
	giveitem_std VAR_RESULT
	compare VAR_RESULT, 0
	goto_if_eq Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_FLOWER_SHOP_RECEIVED_BERRY
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7AF3, MSGBOX_DEFAULT
	release
	end
Route104_PrettyPetalFlowerShop_Text_2A7A98: @ 82A7A98
	.string "I'm trying to be like my big sisters.\n"
	.string "I'm growing flowers, too!\p"
	.string "Here you go!\n"
	.string "It's for you!$"
Route104_PrettyPetalFlowerShop_Text_2A7AF3: @ 82A7AF3
	.string "You can plant a berry and grow it big,\n"
	.string "or you can make a Pokémon hold it.\p"
	.string "But now they have a machine that mixes\n"
	.string "up different berries and makes candies\l"
	.string "for Pokémon.\p"
	.string "I want some candy, too.$"
Route104_PrettyPetalFlowerShop_EventScript_22A482:: @ 822A482
	msgbox Route104_PrettyPetalFlowerShop_Text_2A7AF3, MSGBOX_DEFAULT
	release
	end


