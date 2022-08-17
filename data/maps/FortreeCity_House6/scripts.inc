FortreeCity_House6_MapScripts::
	.byte 0

FortreeCity_House6_EventScript_Mom::
	lock
	@
	markasdialog 10
	message FortreeCity_House6_Text_Mom1a
	waitmessage
	markasdialog -10
	message FortreeCity_House6_Text_Mom1b
	applymovement 2, FortreeCity_House6_Movement_Mom
	waitmessage
	waitmovement 2
	@
	markasdialog 10
	message FortreeCity_House6_Text_Mom2a
	waitmessage
	markasdialog -10
	message FortreeCity_House6_Text_Mom2b
	applymovement 2, FortreeCity_House6_Movement_Mom
	waitmessage
	waitmovement 2
	@
	markasdialog 10
	message FortreeCity_House6_Text_Mom3a
	waitmessage
	markasdialog -10
	message FortreeCity_House6_Text_Mom3b
	applymovement 2, FortreeCity_House6_Movement_Mom
	waitmessage
	waitmovement 2
	@
	message FortreeCity_House6_Text_Mom4, MSGTYPE_CDESCRIBE
	waitmessage
	waitbuttonpress
	release
	end
FortreeCity_House6_Text_Mom1a:
	.string "Wrench.{PAUSE 20}$"
FortreeCity_House6_Text_Mom1b:
	.string "{CLEAR_TO 20}Wrench!{PAUSE 20}$"
FortreeCity_House6_Text_Mom2a:
	.string "Pliers.{PAUSE 20}$"
FortreeCity_House6_Text_Mom2b:
	.string "{CLEAR_TO 20}Pliers!{PAUSE 20}$"
FortreeCity_House6_Text_Mom3a:
	.string "Wires.{PAUSE 20}$"
FortreeCity_House6_Text_Mom3b:
	.string "{CLEAR_TO 20}Wires!{PAUSE 20}$"
FortreeCity_House6_Text_Mom4:
	.string "She's down in a trapdoor in the floor\n"
	.string "fiddling with a breaker box.$"
FortreeCity_House6_Movement_Mom:
	walk_in_place_fast_left
	delay_2
	walk_in_place_fast_down
	step_end


FortreeCity_House6_EventScript_Dad::
	msgbox FortreeCity_House6_Text_Dad, MSGBOX_NPC
	end
FortreeCity_House6_Text_Dad:
	.string "Look, all I wanted to do was start up\n"
	.string "my crypto-mining setup!\p"
	.string "Is that such a crime?!$"

FortreeCity_House6_EventScript_Boy1::
	msgbox FortreeCity_House6_Text_Boy1, MSGBOX_NPC
	end
FortreeCity_House6_Text_Boy1:
	.string "Dad blew the circuit on the house again.$"

FortreeCity_House6_EventScript_Boy2::
	msgbox FortreeCity_House6_Text_Boy2, MSGBOX_NPC
	applymovement THIS_EVENT, Common_Movement_FaceDown
	waitmovement THIS_EVENT
	end
FortreeCity_House6_Text_Boy2:
	.string "My DS has a backlight on it, so when\n"
	.string "the power goes out again, I can just\l"
	.string "curl up in the corner and play.$"

