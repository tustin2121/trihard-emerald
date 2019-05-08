
EventScript_DoLinkRoomExit:: @ 8277513
	special CleanupLinkRoomState
	special sub_80AF9F8
	waitstate
	end

gEventScript_TradeRoom_ReadTrainerCard_NoColor:: @ 827747E
	msgbox Text_278452, MSGBOX_DEFAULT
	fadescreen 1
	special sp02A_crash_sound
	waitstate
	end
Text_278452: @ 8278452
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!$"

gEventScript_TradeRoom_ReadTrainerCard_Normal:: @ 827748D
	msgbox Text_27847B, MSGBOX_DEFAULT
	fadescreen 1
	special sp02A_crash_sound
	waitstate
	end
Text_27847B: @ 827847B
	.string "Score! Got to look at {STR_VAR_1}'s\n"
	.string "TRAINER CARD!\p"
	.string "It's a {STR_VAR_2} card!$"

gEventScript_TradeRoom_TooBusyToNotice:: @ 827749C
	msgbox Text_27842E, MSGBOX_DEFAULT
	closemessage
	end
Text_27842E: @ 827842E
	.string "This TRAINER is too busy to\n"
	.string "notice…$"


PokemonCenter_2F_EventScript_OpenGate1:: @ 8277BBE
	setmetatile 5, 2, 732, 0
	setmetatile 5, 3, 740, 0
	return

PokemonCenter_2F_EventScript_CloseGate1:: @ 8277BD1
	setmetatile 5, 2, 542, 1
	setmetatile 5, 3, 605, 1
	return

PokemonCenter_2F_EventScript_OpenGate2:: @ 8277BE4
	setmetatile 9, 2, 732, 0
	setmetatile 9, 3, 740, 0
	return

PokemonCenter_2F_EventScript_CloseGate2:: @ 8277BF7
	setmetatile 9, 2, 542, 1
	setmetatile 9, 3, 605, 1
	return

MossdeepCity_GameCorner_1F_EventScript_277C0A:: @ 8277C0A
PokemonCenter_2F_EventScript_OpenGate3:: @ 8277C0A
	@ Interestingly, the pokecenter tileset can't logically support this
	setmetatile 5, 2, 556, 0
	setmetatile 5, 3, 564, 0
	return

PokemonCenter_2F_EventScript_CloseGate3:: @ 8277C1D
	@ Interestingly, the pokecenter tileset can't logically support this
	setmetatile 5, 2, 554, 1
	setmetatile 5, 3, 562, 1
	return

PokemonCenter_1F_MapScript1_InitUnionRoom: @ 8277C30
	special sub_8016934
	end

gText_PleaseWaitForLink:: @ 8278091
	.string "Please wait.\n"
	.string "… … B Button: Cancel$"

gText_ConfirmLinkWhenPlayersReady:: @ 82780B3
	.string "When all players are ready…\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

gText_ConfirmStartLinkWithXPlayers:: @ 82780F2
	.string "Start link with {STR_VAR_1} players.\n"
	.string "A Button: Confirm\l"
	.string "B Button: Cancel$"

gText_AwaitingLinkup:: @ 8278131
	.string "Awaiting linkup…\n"
	.string "… … B Button: Cancel$"

LilycoveCity_ContestLobby_Text_2781C7: @ 82781C7
OldaleTown_PokemonCenter_2F_Text_2781C7: @ 82781C7
	.string "Someone is not ready to link.\p"
	.string "Please come back after everyone\n"
	.string "has made preparations.$"

LilycoveCity_ContestLobby_Text_27821C: @ 827821C
OldaleTown_PokemonCenter_2F_Text_27821C: @ 827821C
	.string "Sorry, we have a link error…\n"
	.string "Please reset and try again.$"

BattleFrontier_BattleTowerLobby_Text_278255: @ 8278255
LilycoveCity_ContestLobby_Text_278255: @ 8278255
OldaleTown_PokemonCenter_2F_Text_278255: @ 8278255
	.string "The link partners appear to have\n"
	.string "made different selections.$"