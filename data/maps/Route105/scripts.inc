Route105_MapScripts:: @ 81EE1DB
	map_script MAP_SCRIPT_ON_LOAD, Route105_MapScript1_1EE1EB
	map_script MAP_SCRIPT_ON_TRANSITION, Route105_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route105_MapScript2_1EE240
	.byte 0

@ -----------------------------------------------------

Route105_MapScript1_1EE1EB: @ 81EE1EB
	call_if_unset FLAG_REGI_DOORS_OPENED, Route105_EventScript_1EE20B
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_NORTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute105North
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq UnusualWeather_EventScript_PlaceTilesRoute105South
	end
Route105_EventScript_1EE20B:: @ 81EE20B
	setmetatile 9, 19, 124, 1
	setmetatile 9, 20, 145, 1
	return

Route105_OnTransition: @ 81EE21E
	compare VAR_SHOULD_END_UNUSUAL_WEATHER, 1
	call_if_eq Common_EventScript_HideMapNamePopup
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_NORTH
	call_if_eq UnusualWeather_StartKyogreWeather
	compare VAR_UNUSUAL_WEATHER_LOCATION, UNUSUAL_WEATHER_ROUTE_105_SOUTH
	call_if_eq UnusualWeather_StartKyogreWeather
	end

Route105_MapScript2_1EE240: @ 81EE240
	map_script_2 VAR_SHOULD_END_UNUSUAL_WEATHER, 1, UnusualWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

@ -----------------------------------------------------
@ Trainers

Route105_TrainerScript_Foster:: @ 81EE24A
	trainerbattle_single TRAINER_FOSTER, Route105_Text_295D0F, Route105_Text_295D62
	msgbox Route105_Text_295DAB, MSGBOX_AUTOCLOSE
	end
Route105_Text_295D0F: @ 8295D0F
	.string "There's supposed to be a mystical\n"
	.string "rock around here.\l"
	.string "Do you know anything about it?$"
Route105_Text_295D62: @ 8295D62
	.string "I was thinking too much about that\n"
	.string "rock, while my Pokémon remained weak…$"
Route105_Text_295DAB: @ 8295DAB
	.string "I can spend hours and hours staring\n"
	.string "at a nice rock without growing bored.$"



Route105_TrainerScript_Luis:: @ 81EE261
	trainerbattle_single TRAINER_LUIS, Route105_Text_295DF5, Route105_Text_295E66
	msgbox Route105_Text_295E72, MSGBOX_AUTOCLOSE
	end
Route105_Text_295DF5: @ 8295DF5
	.string "Whew! I was worried that a kid was\n"
	.string "drowning when I saw you.\p"
	.string "You seem to be okay, so what do you\n"
	.string "say to a battle?$"
Route105_Text_295E66: @ 8295E66
	.string "Glub… Glub…$"
Route105_Text_295E72: @ 8295E72
	.string "If you are drowning, the signal is to\n"
	.string "wave one arm toward the beach.$"



Route105_TrainerScript_Dominik:: @ 81EE278
	trainerbattle_single TRAINER_DOMINIK, Route105_Text_295EB7, Route105_Text_295EEA
	msgbox Route105_Text_295F08, MSGBOX_AUTOCLOSE
	end
Route105_Text_295EB7: @ 8295EB7
	.string "Swimming the deep blue sea…\n"
	.string "It feels the greatest!$"
Route105_Text_295EEA: @ 8295EEA
	.string "I lost…\n"
	.string "Now I'm feeling blue…$"
Route105_Text_295F08: @ 8295F08
	.string "Why is the sea blue?\p"
	.string "I learned about that at the Museum in\n"
	.string "Slateport, but I forgot.$"



Route105_TrainerScript_Beverly:: @ 81EE28F
	trainerbattle_single TRAINER_BEVERLY, Route105_Text_295F5C, Route105_Text_295FA0
	msgbox Route105_Text_295FAE, MSGBOX_AUTOCLOSE
	end
Route105_Text_295F5C: @ 8295F5C
	.string "My body feels lighter in the water.\n"
	.string "It's as if I've gotten slimmer!$"
Route105_Text_295FA0: @ 8295FA0
	.string "I'm floating…$"
Route105_Text_295FAE: @ 8295FAE
	.string "Your body weight is reduced to just\n"
	.string "one tenth in the water.\p"
	.string "That would make me…\n"
	.string "Whoops! I'm not telling you my weight!$"



Route105_TrainerScript_Imani:: @ 81EE2A6
	trainerbattle_single TRAINER_IMANI, Route105_Text_296025, Route105_Text_296059
	msgbox Route105_Text_296076, MSGBOX_AUTOCLOSE
	end
Route105_Text_296025: @ 8296025
	.string "The blue, blue sky…\n"
	.string "The vast sea…\l"
	.string "It's so peaceful…$"
Route105_Text_296059: @ 8296059
	.string "I lost while I was lounging!$"
Route105_Text_296076: @ 8296076
	.string "I want to be told I'm relaxing to be\n"
	.string "with. Giggle.$"



Route105_TrainerScript_Josue:: @ 81EE2BD
	trainerbattle_single TRAINER_JOSUE, Route105_Text_29626F, Route105_Text_2962CB
	msgbox Route105_Text_2962EC, MSGBOX_AUTOCLOSE
	end
Route105_Text_29626F: @ 829626F
	.string "I'm exhausted from swimming.\n"
	.string "I'm just not used to it.\p"
	.string "I need a battle for a change of pace!$"
Route105_Text_2962CB: @ 82962CB
	.string "I lost because I battled at sea.$"
Route105_Text_2962EC: @ 82962EC
	.string "Yeah, for me, the sky is a much better\n"
	.string "match than the sea.$"



Route105_TrainerScript_Andres:: @ 81EE2D4
	trainerbattle_single TRAINER_ANDRES_1, Route105_Text_2960A9, Route105_Text_2960DB, Route105_EventScript_1EE300
	specialvar VAR_RESULT, ShouldTryRematchBattle
	compare VAR_RESULT, 1
	goto_if_eq Route105_EventScript_1EE31F
	msgbox Route105_Text_2960FA, MSGBOX_DEFAULT
	release
	end
Route105_Text_2960A9: @ 82960A9
	.string "I'm convinced that the sea keeps\n"
	.string "secrets from us.$"
Route105_Text_2960DB: @ 82960DB
	.string "Yes…\n"
	.string "I am no good at battling…$"
Route105_Text_2960FA: @ 82960FA
	.string "I'm sure there are many secrets to be\n"
	.string "discovered in the world's seas.\p"
	.string "I mean to find them all!$"
Route105_EventScript_1EE300:: @ 81EE300
	special DoSpinningTrainerApproach
	waitmovement 0
	msgbox Route105_Text_296159, MSGBOX_DEFAULT
	register_matchcall TRAINER_ANDRES_1
	release
	end
Route105_Text_296159: @ 8296159
	.string "Huh? I'm so weak, but you're willing\n"
	.string "to register me in your PokéNav?$"
Route105_EventScript_1EE31F:: @ 81EE31F
	trainerbattle_rematch TRAINER_ANDRES_1, Route105_Text_29619E, Route105_Text_2961DD
	msgbox Route105_Text_2961FE, MSGBOX_AUTOCLOSE
	end
Route105_Text_29619E: @ 829619E
	.string "I've told you that I'm weak…\n"
	.string "Are you sure you want to do this?$"
Route105_Text_2961DD: @ 82961DD
	.string "Yes…\n"
	.string "I didn't think I could win.$"
Route105_Text_2961FE: @ 82961FE
	.string "I may be weak at battling, but my\n"
	.string "drive to explore can't be bested.\p"
	.string "I will travel the seas all around\n"
	.string "the world!$"

