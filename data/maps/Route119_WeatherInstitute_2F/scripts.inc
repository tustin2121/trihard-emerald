Route119_WeatherInstitute_2F_MapScripts:: @ 826FF1E
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

@ -----------------------------------------------------

Route119_WeatherInstitute_2F_OnTransition: @ 826FF24
	compare VAR_WEATHER_INSTITUTE_STATE, 1
	call_if_eq Route119_WeatherInstitute_2F_EventScript_26FF44
	compare VAR_WEATHER_INSTITUTE_STATE, 2
	call_if_eq Route119_WeatherInstitute_2F_EventScript_26FF50
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_26FF5C
	end

Route119_WeatherInstitute_2F_EventScript_26FF44:: @ 826FF44
	setobjectxyperm 5, 1, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_26FF50:: @ 826FF50
	setobjectxyperm 5, 4, 6
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_26FF5C:: @ 826FF5C
	setobjectxyperm 5, 2, 2
	setobjectmovementtype 5, MOVEMENT_TYPE_FACE_UP
	return

@ -----------------------------------------------------
@ Trainers

Route119_WeatherInstitute_2F_EventScript_Scientist1:: @ 826FF68
	trainerbattle_single TRAINER_BECKETT, Route119_WeatherInstitute_2F_Text_270335, Route119_WeatherInstitute_2F_Text_27039F
	msgbox Route119_WeatherInstitute_2F_Text_2703C0, MSGBOX_AUTOCLOSE
	end
Route119_WeatherInstitute_2F_Text_270335: @ 8270335
	.string "Wha-! Who are you people?!\n"
	.string "What do you want from our Pokémon?!$"
Route119_WeatherInstitute_2F_Text_27039F: @ 827039F
	.string "Oh, will you look at my Pokémon?$"
Route119_WeatherInstitute_2F_Text_2703C0: @ 82703C0
	.string "We're just meteorologists!\n"
	.string "Please don't hurt us!$"


Route119_WeatherInstitute_2F_EventScript_Ranger:: @ 826FF7F
	trainerbattle_single TRAINER_SEAN, Route119_WeatherInstitute_2F_Text_27019C, Route119_WeatherInstitute_2F_Text_270208
	msgbox Route119_WeatherInstitute_2F_Text_27022B, MSGBOX_AUTOCLOSE
	end
Route119_WeatherInstitute_2F_Text_27019C: @ 827019C
	.string "What's all this then?!$"
Route119_WeatherInstitute_2F_Text_270208: @ 8270208
	.string "Drat! I wasn't strong enough!$"
Route119_WeatherInstitute_2F_Text_27022B: @ 827022B
	.string "As a Pokémon Ranger, it's my duty to\n"
	.string "help those in need against evildoers!\p"
	.string "And despite what you might think,\n"
	.string "raiding a place of science like this\l"
	.string "is an act of evil in my book!$"


Route119_WeatherInstitute_2F_EventScript_26FF96:: @ 826FF96
	trainerbattle_single TRAINER_WALKER, Route119_WeatherInstitute_2F_Text_270292, Route119_WeatherInstitute_2F_Text_2702CE
	msgbox Route119_WeatherInstitute_2F_Text_2702DA, MSGBOX_AUTOCLOSE
	end
Route119_WeatherInstitute_2F_Text_270292: @ 8270292
	.string "You're Team Aqua! What would you\n"
	.string "want with our Castform?!\p"
	.string "Whatever it is, you can't have them!$"
Route119_WeatherInstitute_2F_Text_2702CE: @ 82702CE
	.string "You got me!$"
Route119_WeatherInstitute_2F_Text_2702DA: @ 82702DA
	.string "You don't have any idea what Team\n"
	.string "Aqua are working towards, do you?!\l"
	.string "Get out while you can!$"

@ -----------------------------------------------------
@ People

Route119_WeatherInstitute_2F_EventScript_Aqua1::
	msgbox Route119_WeatherInstitute_2F_Text_Aqua1, MSGBOX_NPC
	end
Route119_WeatherInstitute_2F_Text_Aqua1: @ 827019C
	.string "The Institute created a type of\n"
	.string "Pokémon that has something to do with\l"
	.string "the weather.\p"
	.string "This could be a valuable asset for us,\n"
	.string "so we're here to take them!$"


Route119_WeatherInstitute_2F_EventScript_Dude::
	msgbox Route119_WeatherInstitute_2F_Text_Dude, MSGBOX_NPC
	end
Route119_WeatherInstitute_2F_Text_Dude: @ 827019C
	.string "Don't hurt me or my Castform, please!$"


Route119_WeatherInstitute_2F_EventScript_AquaGirl::
	msgbox Route119_WeatherInstitute_2F_Text_AquaGirl, MSGBOX_NPC
	goto_if_set FLAG_SCENE_1, Common_EventScript_ReleaseEnd
	addvar VAR_AQUA_GIRL_FRIENDSHIP, 1
	setflag FLAG_SCENE_1
	end
Route119_WeatherInstitute_2F_Text_AquaGirl:
	.string "{AQUA_GIRL}: Hey, {PLAYER}.\p"
	.string "Some of these guys are tough.\n"
	.string "I gotta take a rest and regroup.\p"
	.string "See if you can get to Shelly. She\n"
	.string "pushed to the far end of the room.$"


@ -----------------------------------------------------
@ Finale

#define LID_SHELLY 3
#define LID_LOGAN 7

Route119_WeatherInstitute_2F_EventScript_InstituteFinale::
	lockall
	@
	applymovement LID_SHELLY, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	markasdialog -14
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale1
	@
	applymovement 6, Common_Movement_AngryAndWait
	markasdialog 6
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale2
	waitmovement 0
	@
	applymovement LID_SHELLY, Common_Movement_WalkInPlaceDown
	waitmovement 0
	markasdialog -14
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale3
	@
	markasdialog 9
	applymovement LID_SHELLY, Common_Movement_WalkInPlaceRight
	waitmovement 0
	@ Check if the player has room for a new pokemon, branch on it
	getpartysize
	copyvar VAR_TEMP_6, VAR_RESULT
	compare VAR_RESULT, 6
	goto_if_lt Route119_WeatherInstitute_2F_EventScript_InstituteFinale_GiveBranch
	goto Route119_WeatherInstitute_2F_EventScript_InstituteFinale_FightBranch
	end

Route119_WeatherInstitute_2F_EventScript_InstituteFinale_GiveBranch:
	@ Shelly just gives you a Castform
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale4a
	call Route119_WeatherInstitute_2F_EventScript_GiveAndNameCastform
	closemessage
	@
	call Route119_WeatherInstitute_2F_EventScript_InstituteFinale_LoganBranch
	@
	markasdialog 9
	callnative Castform_CheckAfterBattle
	selectpointer Route119_WeatherInstitute_2F_TextArrau_InstituteFinale_Castform, VAR_RESULT
	msgbox_selected
	@
	goto Route119_WeatherInstitute_2F_EventScript_InstituteFinale_Ending
	end


Route119_WeatherInstitute_2F_EventScript_InstituteFinale_FightBranch:
	@ Shelly makes you fight a Castform
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale4b
	@ Battle!
	trainerbattle_no_intro TRAINER_SHELLY_1, Route119_WeatherInstitute_2F_Text_InstituteFinale4b_lose
	markasdialog 12
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformLoss
	closemessage
	@
	call Route119_WeatherInstitute_2F_EventScript_InstituteFinale_LoganBranch
	@
	goto Route119_WeatherInstitute_2F_EventScript_InstituteFinale_Ending
	end

Route119_WeatherInstitute_2F_EventScript_InstituteFinale_LoganBranch:
	@ Logan rushes in
	playbgm MUS_AQA_0, 1
	addobject LID_LOGAN
	applymovement LID_LOGAN, Route119_WeatherInstitute_2F_Movement_270170
	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_27017C
	waitmovement 0
	@
	markasdialog -10
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale5
	@
	markasdialog 9
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale6
	@ Battle!
	applymovement LID_LOGAN, Common_Movement_WalkInPlaceUp
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	trainerbattle_no_intro TRAINER_LOGAN_INSTITUTE, Route119_WeatherInstitute_2F_Text_InstituteFinale7
	@
	markasdialog -10
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale8
	closemessage
	@
	fadedefaultbgm
	applymovement LID_LOGAN, Route119_WeatherInstitute_2F_Movement_27017A
	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_27017Q
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	applymovement EVENT_OBJ_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

Route119_WeatherInstitute_2F_EventScript_InstituteFinale_Ending:
	@
	applymovement LID_SHELLY, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	markasdialog 10
	msgbox Route119_WeatherInstitute_2F_Text_InstituteFinale10
	@ Clean up
	setvar VAR_WEATHER_INSTITUTE_STATE, 2
	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
	call Common_EventScript_ClearSceneFlags
	@
	warp MAP_ROUTE119, 0, 0xFF, 0xFF
	waitstate
	release
	end

Route119_WeatherInstitute_2F_Text_InstituteFinale1:
	.string "Shelly: This thing is the Pokémon\n"
	.string "we heard about?! That's it?$"
Route119_WeatherInstitute_2F_Text_InstituteFinale2:
	.string "You're the one who invaded us for it!$"
Route119_WeatherInstitute_2F_Text_InstituteFinale3:
	.string "Shelly: Yeah, yeah, whatever.\p"
	.string "The boss is not gonna be pleased that\n"
	.string "we wasted resources for this thing.$"
Route119_WeatherInstitute_2F_Text_InstituteFinale4a:
	.string "Shelly: You! New recruit!\p"
	.string "You have room on your team for this\n"
	.string "thing. Report back with how it fares.$"
Route119_WeatherInstitute_2F_Text_InstituteFinale4b:
	.string "Shelly: You! New recurit!\p"
	.string "Battle me. We're gonna see how this\n"
	.string "thing fares in battle.$"
Route119_WeatherInstitute_2F_Text_InstituteFinale4b_lose:
	.string "This is the thing the boss wants?$"
Route119_WeatherInstitute_2F_Text_InstituteFinale5:
	.string "{RIVAL_HERO}: What are you guys\n"
	.string "doing here?! You have no right to\l"
	.string "raid these people!$"
Route119_WeatherInstitute_2F_Text_InstituteFinale6:
	.string "Shelly: Hahahaha!\p"
	.string "You're going to meddle in Team Aqua's\n"
	.string "affairs?\p"
	.string "You're either absolutely fearless,\n"
	.string "simply ignorant, or both!\p"
	.string "You're so cute, you're disgusting!\n"
	.string "I don't have time for you, kid.\l"
	.string "You there, deal with him!$"
Route119_WeatherInstitute_2F_Text_InstituteFinale7:
	.string "Ugh, I should have known you'd get in\n"
	.string "my way again!$"
Route119_WeatherInstitute_2F_Text_InstituteFinale8:
	.string "Someday, I'm gonna defeat you and\n"
	.string "your posse.\p"
	.string "Someday, you're all gonna pay for\n"
	.string "your crimes.$"
Route119_WeatherInstitute_2F_Text_InstituteFinale10:
	.string "We got what we came for!\p"
	.string "Time to pull out!$"

.align 2
Route119_WeatherInstitute_2F_TextArrau_InstituteFinale_Castform:
	.4byte Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformLoss
	.4byte Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformUnused
	.4byte Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformWon
	.4byte Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformWeather
	.4byte 0
Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformLoss:
	.string "Shelly: This Pokémon is pathetic.\n"
	.string "It couldn't even survive a battle.\p"
	.string "This heist was a waste of time…$"
Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformUnused:
	.string "Shelly: That was the prefect chance to\n"
	.string "try out this Pokémon I gave you and\l"
	.string "you didn't even call it out!\p"
	.string "This heist was a waste of time…$"
Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformWon:
	.string "Shelly: Huh, these Pokémon aren't bad\n"
	.string "in a fight.\p"
	.string "Still don't see what use it has…$"
Route119_WeatherInstitute_2F_Text_InstituteFinale_CastformWeather:
	.string "Shelly: This Pokémon can control the\n"
	.string "local weather?\p"
	.string "It might actually be of use to us!\p"
	.string "This whole endeavor might be worthwhile…$"


Route119_WeatherInstitute_2F_Movement_270170: @ 8270170
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_27017A: @ 8270170
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

Route119_WeatherInstitute_2F_Movement_27017C: @ 827017C
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_fastest_down
	step_end

Route119_WeatherInstitute_2F_Movement_27017Q: @ 827017C
	delay_16
	walk_in_place_right
	step_end

#undef LID_SHELLY
#undef LID_LOGAN


Route119_WeatherInstitute_2F_EventScript_GiveAndNameCastform:: @ 82700DB
	@ Give mon
	setvar VAR_TEMP_1, SPECIES_CASTFORM
	bufferspeciesname 0, VAR_TEMP_1
	givemon VAR_TEMP_1, 25, ITEM_MYSTIC_WATER
	@ Play fanfare
	playfanfare MUS_FANFA4
	bufferspeciesname 0, VAR_TEMP_1
	message Route119_WeatherInstitute_2F_Text_2706E8, MSGTYPE_DESCRIBE
	waitmessage
	waitfanfare
	@ Nickname?
	.if !TPP_MODE
		msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
		compare VAR_RESULT, 0
		goto_if_eq _Route119_WeatherInstitute_GiveAndNameCastform_End
	.endif
	copyvar VAR_0x8004, VAR_TEMP_6 @ 0x8004 = party mon to name
	call Common_EventScript_NameReceivedPokemon
_Route119_WeatherInstitute_GiveAndNameCastform_End:
	setflag FLAG_RECEIVED_CASTFORM
	return
Route119_WeatherInstitute_2F_Text_2706E8: @ 82706E8
	.string "{PLAYER} scored a free {STR_VAR_1}!$"






@ Route119_WeatherInstitute_2F_EventScript_26FFAD:: @ 826FFAD
@ 	trainerbattle_single TRAINER_SHELLY_1, Route119_WeatherInstitute_2F_Text_270409, Route119_WeatherInstitute_2F_Text_2704BD, Route119_WeatherInstitute_2F_EventScript_26FFC8
@ 	msgbox Route119_WeatherInstitute_2F_Text_2704E4, MSGBOX_AUTOCLOSE
@ 	end
@ Route119_WeatherInstitute_2F_Text_270409: @ 8270409
@ 	.string "Ahahahaha!\p"
@ 	.string "You're going to meddle in Team Aqua's\n"
@ 	.string "affairs?\p"
@ 	.string "You're either absolutely fearless,\n"
@ 	.string "simply ignorant, or both!\p"
@ 	.string "You're so cute, you're disgusting!\n"
@ 	.string "I'll put you down, kiddy!$"
@ Route119_WeatherInstitute_2F_Text_2704BD: @ 82704BD
@ 	.string "Ahahahaha!\n"
@ 	.string "You're disgustingly strong!$"
@ Route119_WeatherInstitute_2F_Text_2704E4: @ 82704E4
@ 	.string "It's bad enough to have Team Magma\n"
@ 	.string "blunder about, but now there's you!\p"
@ 	.string "What makes you want to sniff around\n"
@ 	.string "in our business, anyway?$"
@ Route119_WeatherInstitute_2F_EventScript_26FFC8:: @ 826FFC8
@ 	msgbox Route119_WeatherInstitute_2F_Text_2704E4, MSGBOX_DEFAULT
@ 	closemessage
@ 	addobject 7
@ 	applymovement 7, Route119_WeatherInstitute_2F_Movement_270170
@ 	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_27017C
@ 	waitmovement 0
@ 	msgbox Route119_WeatherInstitute_2F_Text_270568, MSGBOX_DEFAULT
@ 	closemessage
@ 	playse SE_PIN
@ 	applymovement 3, Common_Movement_ExclamationMark
@ 	waitmovement 0
@ 	applymovement 3, Common_Movement_Delay48
@ 	waitmovement 0
@ 	msgbox Route119_WeatherInstitute_2F_Text_2705DD, MSGBOX_DEFAULT
@ 	closemessage
@ 	setvar VAR_WEATHER_INSTITUTE_STATE, 2
@ 	clearflag FLAG_HIDE_WEATHER_INSTITUTE_2F_WORKERS
@ 	fadedefaultbgm
@ 	fadescreen 1
@ 	setflag FLAG_HIDE_ROUTE_119_TEAM_AQUA
@ 	setflag FLAG_HIDE_WEATHER_INSTITUTE_2F_AQUA_GRUNT_M
@ 	removeobject 1
@ 	removeobject 2
@ 	removeobject 3
@ 	removeobject 8
@ 	removeobject 7
@ 	applymovement EVENT_OBJ_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_270184
@ 	waitmovement 0
@ 	fadescreen 0
@ 	applymovement 5, Route119_WeatherInstitute_2F_Movement_270187
@ 	waitmovement 0
@ 	moveobjectoffscreen 5
@ 	call Common_EventScript_ClearSceneFlags
@ 	goto Route119_WeatherInstitute_2F_EventScript_27004D
@ 	end
@ Route119_WeatherInstitute_2F_Text_270568: @ 8270568
@ 	.string "We have a situation here!\p"
@ 	.string "A Team Magma mob just passed\n"
@ 	.string "the Weather Institute.\p"
@ 	.string "They appear to be headed for\n"
@ 	.string "Mt. Pyre!$"
@ Route119_WeatherInstitute_2F_Text_2705DD: @ 82705DD
@ 	.string "What?!\p"
@ 	.string "We can't waste any more time here!\n"
@ 	.string "We have to hurry to Mt. Pyre, too!\p"
@ 	.string "Ahahahaha!\n"
@ 	.string "Team Magma, just you wait!$"
@ Route119_WeatherInstitute_2F_EventScript_27004D:: @ 827004D
@ 	setvar VAR_TEMP_1, SPECIES_CASTFORM
@ 	bufferspeciesname 0, VAR_TEMP_1
@ 	msgbox Route119_WeatherInstitute_2F_Text_270650, MSGBOX_DEFAULT
@ 	givemon VAR_TEMP_1, 25, ITEM_MYSTIC_WATER
@ 	compare VAR_RESULT, 0 @MON_GIVEN_TO_PARTY
@ 	goto_if_eq Route119_WeatherInstitute_2F_EventScript_270085
@ 	@ compare VAR_RESULT, 1 @MON_GIVEN_TO_PC
@ 	@ goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700AD
@ 	goto Common_EventScript_NoRoomForGiftPokemon
@ 	end
@ Route119_WeatherInstitute_2F_Text_270650: @ 8270650
@ 	.string "Thanks!\n"
@ 	.string "Thanks to you, we're safe!\p"
@ 	.string "It might be an odd way of thanking you,\n"
@ 	.string "but take this {STR_VAR_1}.$"
@ Route119_WeatherInstitute_2F_Text_2706B2: @ 82706B2
@ 	.string "Hm? You don't seem to have any room\n"
@ 	.string "for this Pokémon.$"

@ Route119_WeatherInstitute_2F_EventScript_270085:: @ 8270085
@ 	call Route119_WeatherInstitute_2F_EventScript_2700DB
@ 	.if !TPP_MODE
@ 		msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
@ 		compare VAR_RESULT, 0
@ 		goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700EA
@ 	.endif
@ 	call Route119_WeatherInstitute_2F_EventScript_27378B
@ 	call Common_EventScript_NameReceivedPokemon
@ 	goto Route119_WeatherInstitute_2F_EventScript_2700EA
@ 	end

@ @ Route119_WeatherInstitute_2F_EventScript_2700AD:: @ 82700AD
@ @ 	call Route119_WeatherInstitute_2F_EventScript_2700DB
@ @ 	.if !TPP_MODE
@ @ 		msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
@ @ 		compare VAR_RESULT, 0
@ @ 		goto_if_eq Route119_WeatherInstitute_2F_EventScript_2700D0
@ @ 	.endif
@ @ 	call Route119_WeatherInstitute_2F_EventScript_273797
@ @ 	goto Route119_WeatherInstitute_2F_EventScript_2700D0
@ @ 	end

@ @ Route119_WeatherInstitute_2F_EventScript_2700D0:: @ 82700D0
@ @ 	call Route119_WeatherInstitute_2F_EventScript_2737A0
@ @ 	goto Route119_WeatherInstitute_2F_EventScript_2700EA
@ @ 	end

@ Route119_WeatherInstitute_2F_EventScript_2700DB:: @ 82700DB
@ 	playfanfare MUS_FANFA4
@ 	bufferspeciesname 0, VAR_TEMP_1
@ 	message Route119_WeatherInstitute_2F_Text_2706E8
@ 	waitmessage
@ 	waitfanfare
@ 	return
@ Route119_WeatherInstitute_2F_Text_2706E8: @ 82706E8
@ 	.string "{PLAYER} scored a free {STR_VAR_1}!$"
@ Route119_WeatherInstitute_2F_EventScript_2700EA:: @ 82700EA
@ 	msgbox Route119_WeatherInstitute_2F_Text_2706FE, MSGBOX_DEFAULT
@ 	setflag FLAG_RECEIVED_CASTFORM
@ 	release
@ 	end
@ Route119_WeatherInstitute_2F_Text_2706FE: @ 82706FE
@ 	.string "That Pokémon changes shape according\n"
@ 	.string "to the weather conditions.\p"
@ 	.string "There're plenty of them in the\n"
@ 	.string "Institute--go ahead and take it.$"

Route119_WeatherInstitute_2F_EventScript_2700F7:: @ 82700F7
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartUnusualWeather
	msgbox Route119_WeatherInstitute_2F_Text_27077E, MSGBOX_DEFAULT
	release
	end
Route119_WeatherInstitute_2F_Text_27077E: @ 827077E
	.string "I've been researching rain for many\n"
	.string "years, but it's ridiculous to think that\l"
	.string "humans can freely change the weather.$"
Route119_WeatherInstitute_2F_EventScript_TryStartUnusualWeather:: @ 827010A
    @ This code uses VAR_0x8004 to count the number of legendaries the player has defeated
    @ already.
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount
	call_if_set FLAG_DEFEATED_GROUDON, WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount
	compare VAR_0x8004, 2
	goto_if_eq WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeated
	call_if_unset FLAG_TEMP_2, WeatherInstitute_UnusualWeather_EventScript_DoCreateUnusualWeather
	specialvar VAR_RESULT, GetUnusualWeatherMapNameAndType
	compare VAR_RESULT, 1
	goto_if_eq WeatherInstitute_UnusualWeather_EventScript_ShowKyogreWeatherMessage
	msgbox WeatherInstitute_UnusualWeather_GroudonWeatherText, MSGBOX_DEFAULT
	release
	end
WeatherInstitute_UnusualWeather_GroudonWeatherText: @ 82707F1
	.string "I track weather patterns over\n"
	.string "the Hoenn region.\p"
	.string "Presently, a drought has been recorded\n"
	.string "in {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"
WeatherInstitute_UnusualWeather_EventScript_ShowKyogreWeatherMessage:: @ 827014F
	msgbox WeatherInstitute_UnusualWeather_KyogreWeatherText, MSGBOX_DEFAULT
	release
	end
WeatherInstitute_UnusualWeather_KyogreWeatherText: @ 8270873
	.string "I track weather patterns over\n"
	.string "the Hoenn region.\p"
	.string "Presently, heavy rainfall has been\n"
	.string "recorded over {STR_VAR_1}.\p"
	.string "Could that mean, somewhere near\n"
	.string "{STR_VAR_1}…$"
WeatherInstitute_UnusualWeather_EventScript_DoCreateUnusualWeather:: @ 8270159
	special CreateUnusualWeatherEvent
	setflag FLAG_TEMP_2
	return
WeatherInstitute_UnusualWeather_EventScript_IncrementLegendCount:: @ 8270160
	addvar VAR_0x8004, 1
	return
WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeated:: @ 8270166
	msgbox WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeatedText, MSGBOX_DEFAULT
	release
	end
WeatherInstitute_UnusualWeather_EventScript_ShowLegendariesAlreadyDefeatedText: @ 82708FC
	.string "Abnormal weather conditions are\n"
	.string "no longer being reported.\p"
	.string "The occasional rainfall is a blessing,\n"
	.string "really.$"


Route119_WeatherInstitute_2F_Movement_270184: @ 8270184
	slide_down
	walk_in_place_fastest_left
	step_end

Route119_WeatherInstitute_2F_Movement_270187: @ 8270187
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_27018B:: @ 827018B
	@ lock
	@ faceplayer
	@ goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_2700F7
	@ goto Route119_WeatherInstitute_2F_EventScript_27004D
	end
