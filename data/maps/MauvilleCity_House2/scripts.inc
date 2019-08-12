MauvilleCity_House2_MapScripts:: @ 8210C5C
	.byte 0

MauvilleCity_House2_EventScript_210C5D:: @ 8210C5D
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_COIN_CASE, MauvilleCity_House2_EventScript_210CDA
	msgbox MauvilleCity_House2_Text_210CEE, MSGBOX_CDIALOG
	@ checkitem ITEM_HARBOR_MAIL, 1
	@ compare VAR_RESULT, 1
	goto_if_set FLAG_SYS_RIBBON_GET, MauvilleCity_House2_EventScript_210C82
	goto MauvilleCity_House2_EventScript_210CE4
	release
	end

MauvilleCity_House2_EventScript_210C82:: @ 8210C82
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	@ msgbox MauvilleCity_House2_Text_210D76, MSGBOX_YESNO
	@ compare VAR_RESULT, 1
	@ goto_if_eq MauvilleCity_House2_EventScript_210CB8
	msgbox MauvilleCity_House2_Text_210DB3, MSGBOX_CDIALOG
	@ takeitem ITEM_HARBOR_MAIL, 1
	giveitem_std ITEM_COIN_CASE
	setflag FLAG_RECEIVED_COIN_CASE
	goto MauvilleCity_House2_EventScript_210CDA
	end

MauvilleCity_House2_EventScript_210CDA:: @ 8210CDA
	msgbox MauvilleCity_House2_Text_210DE7, MSGBOX_CDIALOG
	release
	end

MauvilleCity_House2_EventScript_210CE4:: @ 8210CE4
	msgbox MauvilleCity_House2_Text_210E16, MSGBOX_CDIALOG
	release
	end

MauvilleCity_House2_EventScript_Rosa::
	lock
	faceplayer
	playmoncry SPECIES_SKITTY, 0
	msgbox MauvilleCity_House2_EventScript_Rosa_Text, MSGBOX_CDIALOG
	release
	end

MauvilleCity_House2_Text_210CEE: @ 8210CEE
	.string "I love my Rosa, but it's a bit plain.\p"
	.string "I'd love to get a ribbon for it\n"
	.string "to wear, but I don't know how.\l"
	.string "I hear they're so pretty!$"

MauvilleCity_House2_Text_210D76: @ 8210D76
	.string "Oh! You have HARBOR MAIL?\n"
	.string "Will you trade it for a COIN CASE?$"

MauvilleCity_House2_Text_210DB3: @ 8210DB3
	.string "You say your Pokémon has a ribbon?\p"
	.string "May I have it for my Rosa?\n"
	.string "I'll give you this Coin Case\l"
	.string "in exchange for that.\p"
	.string "Oh, I was only kidding. That ribbon\n"
	.string "goes so perfectly with your Pokémon\l"
	.string "that I could never take it away!\p"
	.string "Here, have the Coin Case anyway as\n"
	.string "thanks for showing me your\l"
	.string "wonderful ribbon!$"

MauvilleCity_House2_Text_210DE7: @ 8210DE7
	.string "That Coin Case can be used\n"
	.string "at the Game Corner.$"

MauvilleCity_House2_Text_210E16: @ 8210E16
	.string "You don't have any either?\n"
	.string "Oh, that's so disappointing.\p"
	.string "It would have been awesome if\n"
	.string "they were available as prizes at\l"
	.string "the Casino, but they aren't, so\l"
	.string "this Coin Case is useless to me…$"

MauvilleCity_House2_EventScript_Rosa_Text::
	.string "Rosa: Miao!$"
